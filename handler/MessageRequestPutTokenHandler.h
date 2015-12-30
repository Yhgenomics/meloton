/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-29
* Description: handler for MessageRequestPutToken
* * * * * * * * * * * * * * * */

#ifndef MESSAGEREQUESTPUTTOKEN_HANDLER_
#define MESSAGEREQUESTPUTTOKEN_HANDLER_

#include <string>
#include <memory>

#include <MRT.h>
#include <ClusterSession.h>
#include <google/protobuf/message.h>
#include <MessageRequestPutToken.pb.h>

#include <MessagePutTokenACK.pb.h>
#include <BlockTable.h>

static int MessageRequestPutTokenHandler( ClusterSession * session , uptr<MessageRequestPutToken> msg )
{
    auto block = BlockTable::instance( )->create_block( msg->file_name( ) , 
                                                        msg->size( ) , 
                                                        msg->block_id( ) );

    if ( block == nullptr ) return -1;

    uptr<MessagePutTokenACK> reply = make_uptr( MessagePutTokenACK );

    reply->set_block_id( block->block_id );
    reply->set_expire ( MAX_SIZE_T );
    reply->set_index( block->index );
    reply->set_request_id( msg->request_id( ) );
    reply->set_token( MRT::UUID::create( ) );

    session->send_message( move_ptr( reply ) );

    return 0;
}

#endif

// !MESSAGEREQUESTPUTTOKEN_HANDLER_
