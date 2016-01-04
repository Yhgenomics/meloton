/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-31
* Description: handler for MessageTokenACK
* * * * * * * * * * * * * * * */

#ifndef MESSAGETOKENACK_HANDLER_
#define MESSAGETOKENACK_HANDLER_

#include <string>
#include <memory>

#include <MRT.h>
#include <ClusterSession.h>
#include <google/protobuf/message.h>
#include <MessageTokenACK.pb.h>

#include <NodeSession.h>
#include <MessageToken.pb.h>
#include <ClientManager.h>
#include <TokenPool.h>
#include <TokenMeta.h>

static int MessageTokenACKHandler( ClusterSession * session , uptr<MessageTokenACK> msg )
{
    auto node = scast<NodeSession*>( session );
    auto client = ClientManager::instance( )->find_session( msg->client_id( ) );
    
    if ( client == nullptr )
    {
        return 0;
    }

    sptr<TokenMeta> meta = make_sptr( TokenMeta );
    meta->address        = node->data_ip( );
    meta->port           = node->data_port( );
    meta->block_id       = msg->block_id( );
    meta->client_id      = msg->client_id( );
    meta->expire         = msg->expire( );
    meta->index          = msg->index( );
    meta->request_id     = msg->request_id( );
    meta->token          = msg->token( );

    if ( client->add_token( meta ) )
    {
        uptr<MessageToken> reply    = make_uptr( MessageToken );
        auto token_num              = client->token_num( );

        for ( size_t i = 0; i < token_num; i++ )
        {
            auto token = client->get_token( i );
            
            if ( token == nullptr ) return -1;

            reply->set_address( i , token->address );
            reply->set_block_id( i , token->block_id );
            reply->set_expire( i , token->expire );
            reply->set_index( i , token->index );
            reply->set_port( i , token->port );
            reply->set_token ( i , token->token );
        }
        
        client->send_message( move_ptr( reply ) );
        client->close( );
    }

    return 0;
}

#endif

// !MESSAGETOKENACK_HANDLER_
