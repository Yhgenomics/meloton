/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-24
* Description: handler for MessageUpdateBlock
* * * * * * * * * * * * * * * */

#ifndef MESSAGEUPDATEBLOCK_HANDLER_
#define MESSAGEUPDATEBLOCK_HANDLER_

#include <string>
#include <memory>

#include <MRT.h>
#include <ClusterSession.h>
#include <google/protobuf/message.h>
#include <MessageUpdateBlock.pb.h>

#include "FS.h"

static int MessageUpdateBlockHandler( ClusterSession * session , uptr<MessageUpdateBlock> msg )
{
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

    return 0;
}

#endif

// !MESSAGEUPDATEBLOCK_HANDLER_
