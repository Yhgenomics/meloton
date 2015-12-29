#include "BlockDistributer.h"
#include <tuple>
#include "NodeManager.h"
#include <MessageRequestGetToken.pb.h>
#include <meloton.h>
#include <RequestTokenTable.h>

BlockDistributer::BlockDistributer( )
{
}

BlockDistributer::~BlockDistributer( )
{
}

void BlockDistributer::get_file( sptr<FileMeta> file , ClusterSession * session , uptr<MessageRequestGet> msg )
{
    if ( file == nullptr || session == nullptr || msg == nullptr )
        return;

    auto blocks = file->blocks( );

    sptr<RequestTokenCollection> token = 
        RequestTokenTable::instance( )->create( sptr<ClusterSession>( session ) , 
                                                msg->request_id( ) ,
                                                blocks.size( ) );

    for ( auto & block : blocks )
    {
        auto nodes = block->nodes( );

        size_t min_block_node_id = MAX_SIZE_T;
        sptr<NodeSession> node_session = nullptr;
        sptr<NodeMeta> node_meta = nullptr;

        for ( auto & node : nodes )
        {
            auto n = NodeManager::instance( )->find_node( [ node ] ( sptr<NodeSession> ns )
            { 
                return ns->id( ) == node->node_id( );
            } );

            if ( n != nullptr )
            {
                if ( n->block_num( ) <= min_block_node_id )
                {
                    min_block_node_id = n->id( );
                    node_session = n;
                    node_meta = node;
                }
            }
        }
        
        uptr<MessageRequestGetToken> req = make_uptr( MessageRequestGetToken );
        req->set_index( node_meta->index( ) );
        req->set_request_id( msg->request_id( ) );
        req->set_block_id( block->id( ) );
        node_session->send_message( move_ptr( msg ) );
    } 
}

void BlockDistributer::put_file( size_t file_size , 
                                 ClusterSession * session ,
                                 uptr<MessageRequestPut> msg )
{
    //size_t block_num = file_size / BLOCK_SIZE + 1;

    //NodeManager::instance( )->sort( [ ] ( sptr<NodeSession> n1 , sptr<NodeSession> n2)
    //{ 
    //    return n1->block_num( ) > n2->block_num( );
    //} );

    //for ( size_t i = 0; i < block_num; i++ )
    //{

    //}
}
