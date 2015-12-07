#include "NodeManager.h"

NodeManager::NodeManager( )
{
    this->node_array_ = make_uptr( Array<NodeSession> , 1024 );

    MRT::SyncWorker::create( 1000 , [ this ] ( MRT::SyncWorker* worker )
    {
        this->all_node( [ ] ( sptr<NodeSession> session )
        {
            if ( session->alive_time( ) > 5000 )
            {
                session->close( );
            }
        } );

        return false;
    } , nullptr , nullptr );
}

NodeManager::~NodeManager( )
{

}

void NodeManager::push_node( sptr<NodeSession> session )
{
    this->node_array_->push( session );
}

void NodeManager::remove_node( sptr<NodeSession> session )
{ 
    this->node_array_->remove( session );
}

sptr<NodeSession> NodeManager::find_node( find_callback_t callback )
{
    return  this->node_array_->find( callback );
}

void NodeManager::all_node( all_callback_t callback )
{
    for ( size_t i = 0; i < this->node_array_->size( ); i++ )
    {
        auto t = this->node_array_->get( i );
        if ( t != nullptr )
        {
            callback( t );
        }
    }
}
