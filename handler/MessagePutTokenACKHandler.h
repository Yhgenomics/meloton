/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-24
* Description: handler for MessagePutTokenACK
* * * * * * * * * * * * * * * */

#ifndef MESSAGEPUTTOKENACK_HANDLER_
#define MESSAGEPUTTOKENACK_HANDLER_

#include <string>
#include <memory>

#include <MRT.h>
#include <ClusterSession.h>
#include <google/protobuf/message.h>
#include <MessagePutTokenACK.pb.h>

static int MessagePutTokenACKHandler( ClusterSession * session , uptr<MessagePutTokenACK> msg )
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

// !MESSAGEPUTTOKENACK_HANDLER_
