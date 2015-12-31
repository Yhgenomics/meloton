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

static int MessagePutHandler( ClusterSession * session , uptr<MessagePut> msg )
{
    auto & token = msg->token( );
    auto size    = msg->size( ) > SIZE_PER_MESSAGE ? SIZE_PER_MESSAGE : msg->size( );
    auto block   = BlockTable::instance( )->find_block( msg->index( ) );
    
    if ( !TokenPool::instance( )->check_token( msg->token( ) ) )
    {
        return -1;
    }

    if ( block->size < ( msg->offset( ) + msg->size( ) ) )
    {
        return -1;
    }

    if ( block == nullptr )
    {
        return -1;
    }

    BlockTable::instance( )->write_block( block , 
                                          msg->data( ).c_str( ) , 
                                          msg->size( ) , 
                                          msg->offset( ) );

    if ( block->size == ( msg->offset( ) + msg->size( ) ) )
    {
        TokenPool::instance( )->remove( msg->token( ) );
        session->close( );
    }

    return 0;
}

#endif

// !MESSAGEPUT_HANDLER_
