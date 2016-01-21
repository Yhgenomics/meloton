#include "NodeManager.h"
#include <meloton.h>

NodeManager::NodeManager( )
{
    this->node_array_ = make_uptr( Array<NodeSession> , 1024 * 10 );

    MRT::SyncWorker::create( 1000 , [ this ] ( MRT::SyncWorker* worker )
    {
        this->all_node( [ ] ( sptr<NodeSession> session )
        {
            //if ( session->alive_time( ) > NODE_TIMEOUT )
            //{
            //    session->close( );
            //}
        } );

        return false;
    } , nullptr , nullptr );
} 

NodeManager::~NodeManager( )
{

}

NodeSession * NodeManager::create_node( )
{
    return new NodeSession( );
}

sptr<NodeSession> NodeManager::get_node( size_t index )
{
    return this->node_array_->get( index );
}

size_t NodeManager::count( )
{
    return this->node_array_->size( );
}

void NodeManager::push_node( sptr<NodeSession> session )
{
    this->node_array_->push( session );
}

void NodeManager::remove_node( sptr<NodeSession> session )
{ 
    this->node_array_->remove( session );
}

void NodeManager::remove_node( NodeSession* session )
{ 
    this->node_array_->remove( (NodeSession*)session );
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

void NodeManager::sort( compare_callback_t callback )
{
    if ( this->node_array_->size( ) < 2 )
        return;

    quick_sort( 0 , this->node_array_->size( ) - 1, callback );
}

void NodeManager::quick_sort( size_t l , size_t r , compare_callback_t compare )
{ 
    if (l < r)  
    {        
        size_t i = l , j = r;
        auto x = this->node_array_->get(l);  
        while (i < j)  
        {  
            auto nj = this->node_array_->get(j);  
            while ( i < j && compare(nj,x) ) // s[j]>= x
            {
                j--;   
            } 

            if ( i < j )
            { 
                //s[i++] = s[j];  
                this->node_array_->swap( i , j );
                i++;
            }

            auto ni = this->node_array_->get(i);  
            while ( i < j && compare(x , ni) ) //s[i] < x
            {
                i++;
            }

            if ( i < j )
            {
                //s[j--] = s[i];
                this->node_array_->swap( j , i );
                j--;
            }
        } 
        
        this->node_array_->set( i , x );
        //s[i] = x;  
        
        if( i>0 )
            quick_sort(l, i - 1 , compare);  

        if( i<r )
            quick_sort(i + 1, r , compare);  
    }  
}