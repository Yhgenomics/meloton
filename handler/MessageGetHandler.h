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

#include <ErrDef.h>

static int MessageGetHandler( ClusterSession * session , uptr<MessageGet> msg )
{
    
    auto size    = msg->size( ) > SIZE_PER_MESSAGE ? SIZE_PER_MESSAGE : msg->size( );
    auto token   = TokenPool::instance( )->get_token( msg->token( ) );

    if ( token == nullptr )
    {
        Logger::error( "Token is nullptr" );

        uptr<MessageActionError> err = make_uptr( MessageActionError );
        err->set_code( ERR_TOKEN_NOT_EXIST );
        err->set_message( ERR_TOKEN_NOT_EXIST_STR );
        session->send_message( move_ptr( err ) );
        return -1;
    }

    auto block = BlockTable::instance( )->find_block( token->index( ) );

    if ( block == nullptr )
    {
        Logger::error( "Block is not found" );

        uptr<MessageActionError> err = make_uptr( MessageActionError );
        err->set_code( ERR_BLOCK_NOT_EXIST );
        err->set_message( ERR_BLOCK_NOT_EXIST_STR );
        session->send_message( move_ptr( err ) );

        return -1;
    }

    if ( !TokenPool::instance( )->check_token( msg->token( ) ) )
    {
        Logger::error( "Token is not found" );
        return -1;
    }

    auto data    = BlockTable::instance( )->read_block( block ,
                                                        msg->offset( ) ,
                                                        size );

    if ( data == nullptr )
    {
        Logger::error( "Data is nullptr" );
        return -1;
    }

    uptr<MessageBlockData> reply = make_uptr( MessageBlockData );
    reply->set_token( token->token( ) );
    reply->set_size( size );
    reply->set_offset( msg->offset( ) );
    reply->set_data( data->data( ) , size );
    session->send_message( move_ptr( reply ) );

    if ( ( size_t ) ( msg->offset( ) + size ) >= block->size )
    {
        LOG_DEBUG( "Reading Block %lld finished" , block->block_id );
        // TODO 
        // remove token, finish the transfer
        TokenPool::instance( )->remove( msg->token( ) );
        session->close( );
    }

    return 0;
}

#endif

// !MESSAGEGET_HANDLER_
