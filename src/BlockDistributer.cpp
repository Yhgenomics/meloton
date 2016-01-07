#include "BlockDistributer.h"
#include <tuple>
#include "NodeManager.h"
#include <meloton.h>
#include <RequestTokenTable.h>
#include <MessageRequestGetToken.pb.h>
#include <MessageRequestPutToken.pb.h>
#include <math.h>

BlockDistributer::BlockDistributer( )
{
}

BlockDistributer::~BlockDistributer( )
{
}

void BlockDistributer::get_file( sptr<FileMeta> file , 
                                 sptr<ClientSession> client , 
                                 uptr<MessageRequestGet> msg )
{
    if ( file == nullptr || client == nullptr || msg == nullptr )
        return;

    auto blocks = file->blocks( );

    //sptr<RequestTokenCollection> token = 
    //    RequestTokenTable::instance( )->create( sptr<ClusterSession>( client ) , 
    //                                            msg->request_id( ) ,
    //                                            blocks.size( ) );
     
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
        req->set_client_id( client->id( ) );
        node_session->send_message( move_ptr( req ) );
    } 

    client->token_num( blocks.size( ) );
}

void BlockDistributer::put_file( size_t file_size , 
                                 sptr<ClientSession> client ,
                                 uptr<MessageRequestPut> msg )
{
    LOG_DEBUG( "file size num %lld " , file_size );
    
    auto size_left = file_size;
      
    size_t block_num        = (size_t)ceil( (double)file_size / (double)(BLOCK_SIZE) );
    size_t max_block_num    = 0;
    size_t offset           = 0;

    NodeManager::instance( )->sort( [ ] ( sptr<NodeSession> n1 , sptr<NodeSession> n2)
    { 
        return n1->block_num( ) > n2->block_num( );
    } );

    if ( NodeManager::instance( )->count( ) == 0 )
    {
        LOG_DEBUG( "node count is 0 exit" , block_num );
        client->close( );
        return;
    }

    LOG_DEBUG( "block num %lld " , block_num );
    //NodeManager::instance( )->all_node( [ &max_block_num ] ( sptr<NodeSession> node )
    //{ 
    //    if ( node->block_num( ) > max_block_num )
    //    {
    //        max_block_num = node->block_num( );
    //    }
    //} );

    //sptr<RequestTokenCollection> token = 
    //    RequestTokenTable::instance( )->create( sptr<ClusterSession>( client ) , 
    //                                            msg->request_id( ) ,
    //                                            block_num );

    for ( size_t i = 0; i < block_num; i++ )
    {
        if ( size_left == 0 ) break;

        auto c_size = size_left > BLOCK_SIZE ? BLOCK_SIZE : size_left;

        LOG_DEBUG( "Block[%lld] size: %lld" , i , c_size );

        uptr<MessageRequestPutToken> req = make_uptr( MessageRequestPutToken );
        req->set_request_id( msg->request_id( ) );
        req->set_block_id( i );
        req->set_size( c_size );
        req->set_client_id( client->id( ) );
        req->set_file_name( msg->path( ) );
        req->set_offset( offset );

        auto n = NodeManager::instance( )->get_node( i % NodeManager::instance( )->count( ) );
        
        if ( n == nullptr )
        {
            break;
        }

        LOG_DEBUG( "distribute block to %lld " , n->id( ) );

        n->send_message( move_ptr( req ) );

        size_left -= c_size;
        offset += c_size;
    }

    client->token_num( block_num );
}
