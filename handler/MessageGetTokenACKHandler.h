/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-24
* Description: handler for MessageGetTokenACK
* * * * * * * * * * * * * * * */

#ifndef MESSAGEGETTOKENACK_HANDLER_
#define MESSAGEGETTOKENACK_HANDLER_

#include <string>
#include <memory>

#include <MRT.h>
#include <ClusterSession.h>
#include <google/protobuf/message.h>
#include <MessageGetTokenACK.pb.h>

#include <RequestTokenTable.h>

static int MessageGetTokenACKHandler( ClusterSession * session , uptr<MessageGetTokenACK> msg )
{
    auto token_collection = RequestTokenTable::instance( )->find( msg->request_id( ) );

    if ( token_collection == nullptr )
    {
        return 0;
    }
    
    token_collection->add_token( sptr<NodeSession>( scast<NodeSession*>( session ) ) ,
                                 msg->token( ) ,
                                 msg->index( ) ,
                                 msg->block_id( ) );

    if ( token_collection->is_full( ) )
    {
        token_collection->reply_token( );
        RequestTokenTable::instance( )->remove( token_collection->request_id( ) );
    }
    
    return 0;
}

#endif

// !MESSAGEGETTOKENACK_HANDLER_
