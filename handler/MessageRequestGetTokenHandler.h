/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-29
* Description: handler for MessageRequestGetToken
* * * * * * * * * * * * * * * */

#ifndef MESSAGEREQUESTGETTOKEN_HANDLER_
#define MESSAGEREQUESTGETTOKEN_HANDLER_

#include <string>
#include <memory>

#include <MRT.h>
#include <ClusterSession.h>
#include <google/protobuf/message.h>
#include <MessageRequestGetToken.pb.h>

#include <BlockTable.h>
#include <MessageTokenACK.pb.h>
#include <TokenPool.h>

static int MessageRequestGetTokenHandler( ClusterSession * session , uptr<MessageRequestGetToken> msg )
{
    auto block = BlockTable::instance( )->find_block( msg->index( ) );
    
    if ( block == nullptr || block->is_used == false )
    {

        return 0;
    }

    uptr<MessageTokenACK> reply = make_uptr( MessageTokenACK );

    reply->set_block_id( msg->block_id( ) );
    reply->set_expire( MAX_SIZE_T );
    reply->set_index( block->index );
    reply->set_request_id( msg->request_id( ) );
    reply->set_token( TokenPool::instance( )->create( ) );
    reply->set_client_id( msg->client_id( ) );

    session->send_message( move_ptr( reply ) );
    
    return 0;
}

#endif

// !MESSAGEREQUESTGETTOKEN_HANDLER_
