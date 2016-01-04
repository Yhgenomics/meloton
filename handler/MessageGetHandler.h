/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-24
* Description: handler for MessageGet
* * * * * * * * * * * * * * * */

#ifndef MESSAGEGET_HANDLER_
#define MESSAGEGET_HANDLER_

#include <string>
#include <memory>

#include <MRT.h>
#include <ClusterSession.h>
#include <google/protobuf/message.h>
#include <MessageGet.pb.h>

#include <BlockTable.h>
#include <MessageBlockData.pb.h>
#include "meloton.h"
#include <TokenPool.h>

static int MessageGetHandler( ClusterSession * session , uptr<MessageGet> msg )
{
    auto & token = msg->token( );
    auto size    = msg->size( ) > SIZE_PER_MESSAGE ? SIZE_PER_MESSAGE : msg->size( );
    auto block   = BlockTable::instance( )->find_block( msg->index( ) );

    if ( !TokenPool::instance( )->check_token( msg->token( ) ) )
    {
        return -1;
    }

    if ( block == nullptr )
    {
        return 0;
    }

    auto data    = BlockTable::instance( )->read_block( block , 
                                                        msg->offset() ,
                                                        size );

    if ( data == nullptr )
    {
        return 0;
    }

    uptr<MessageBlockData> reply = make_uptr( MessageBlockData );
    reply->set_token( token );
    reply->set_size( size );
    reply->set_offset( msg->offset( ) );
    reply->set_data( data->data( ) , size );

    if ( (size_t)( msg->offset( ) + size ) >= block->size )
    {
        // TODO 
        // remove token, finish the transfer
        TokenPool::instance( )->remove( msg->token( ) );
    }

    return 0;
}

#endif

// !MESSAGEGET_HANDLER_
