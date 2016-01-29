/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2016-01-07
* Description: handler for MessageSyncBlock
* * * * * * * * * * * * * * * */

#ifndef MESSAGESYNCBLOCK_HANDLER_
#define MESSAGESYNCBLOCK_HANDLER_

#include <string>
#include <memory>

#include <MRT.h>
#include <ClusterSession.h>
#include <google/protobuf/message.h>
#include <MessageSyncBlock.pb.h>

#include <FS.h>
#include <NodeSession.h>

static int MessageSyncBlockHandler( ClusterSession * session , uptr<MessageSyncBlock> msg )
{
    NodeSession* node_session = ( NodeSession* ) session;

    auto file = FS::instance( )->get_file( msg->path( ) );

    if ( file == nullptr )
    {
        file =  FS::instance( )->create_file( msg->path( ) );
    }

    sptr<BlockMeta> block = file->get_block( msg->id( ) );

    if ( block == nullptr )
    {
        block = make_sptr( BlockMeta , msg->id( ) );
        block->size( msg->size( ) );
        file->add_block( block );
    }
    else
    {
        block->size( msg->size( ) );
    }

    node_session->add_block( block );

    sptr<NodeMeta> node = block->get_nodes( session->id( ) );

    if ( node == nullptr )
    {
        node = make_sptr( NodeMeta , session->id( ) );
        node->index( msg->index( ) );
        block->add_nodes( node );
    }
    else
    {
        node->index( msg->index( ) );
    }

    LOG_DEBUG( "[%s] Block[%lld] size: %lld %s" , session->ip_address( ).c_str( ) ,  msg->id( ) , msg->size( ), msg->path( ).c_str( ) );

    return 0;
}

#endif

// !MESSAGESYNCBLOCK_HANDLER_
