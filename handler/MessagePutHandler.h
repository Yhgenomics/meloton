/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-24
* Description: handler for MessagePut
* * * * * * * * * * * * * * * */

#ifndef MESSAGEPUT_HANDLER_
#define MESSAGEPUT_HANDLER_

#include <string>
#include <memory>

#include <MRT.h>
#include <ClusterSession.h>
#include <google/protobuf/message.h>
#include <MessagePut.pb.h>

#include <BlockTable.h>
#include <MRT.h>
#include <MessageUpdateBlock.pb.h>

static int MessagePutHandler( ClusterSession * session , uptr<MessagePut> msg )
{
    auto & token    = msg->token( );
    auto size       = msg->size( ) > SIZE_PER_MESSAGE ? SIZE_PER_MESSAGE : msg->size( );
    auto block      = BlockTable::instance( )->find_block( msg->index( ) );
    auto offset     = msg->offset( );
    auto msg_size   = msg->size( );
    auto pos        = offset + msg_size;

    if ( !TokenPool::instance( )->check_token( msg->token( ) ) )
    {
        LOG_DEBUG( "Token check failed" );
        return -1;
    }

    if ( block->size < ( pos ) )
    {
        LOG_DEBUG( "Block Size : %lld" , block->size );
        LOG_DEBUG( "MessagePutHandler Leave" );
        return -1;
    }

    if ( block == nullptr )
    {
        LOG_DEBUG( "Block is nullptr" );
        LOG_DEBUG( "MessagePutHandler Leave" );
        return -1;
    }

    BlockTable::instance( )->write_block( block , 
                                          msg->data( ).c_str( ) , 
                                          msg->size( ) , 
                                          msg->offset( ) );

    if ( block->size == ( msg->offset( ) + msg->size( ) ) )
    {
        TokenPool::instance( )->remove( msg->token( ) );

        uptr<MessageUpdateBlock> update_msg = make_uptr( MessageUpdateBlock );
        update_msg->set_id( block->block_id );
        update_msg->set_index( block->index );
        update_msg->set_path( block->path );
        update_msg->set_size( block->size );
        update_msg->set_status( 1 );

        MasterSession::instance( )->send_message( move_ptr( update_msg ) );

        LOG_DEBUG( "Block transfer finished" );
    }

    return 0;
}

#endif

// !MESSAGEPUT_HANDLER_
