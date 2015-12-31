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

#include <MessageTokenACK.pb.h>
#include <BlockTable.h>
#include <TokenPool.h>

static int MessageRequestPutTokenHandler( ClusterSession * session , uptr<MessageRequestPutToken> msg )
{
    auto block = BlockTable::instance( )->create_block( msg->file_name( ) , 
                                                        msg->size( ) , 
                                                        msg->block_id( ) );

    if ( block == nullptr ) return -1;

    uptr<MessageTokenACK> reply = make_uptr( MessageTokenACK );

    reply->set_block_id( block->block_id );
    reply->set_expire ( MAX_SIZE_T );
    reply->set_index( block->index );
    reply->set_request_id( msg->request_id( ) );
    reply->set_token( TokenPool::instance( )->create( ) );
    reply->set_client_id( msg->client_id( ) );

    session->send_message( move_ptr( reply ) );

    return 0;
}

#endif

// !MESSAGEREQUESTPUTTOKEN_HANDLER_
