#include "NodeSession.h"
#include "MasterConfig.h"
#include <FS.h>

NodeSession::NodeSession( )
{
    this->update_alive( );
}

NodeSession::~NodeSession( )
{ 

}

void NodeSession::on_close( )
{
    for ( auto & b : this->own_block_ )
    {
        if( b != nullptr &&
            b.get() != nullptr )
        {
            b->remove_node( this->id( ) );
        }
    }
}

void NodeSession::update_alive( )
{
    this->alive_time_ = Timer::tick( );
}

size_t NodeSession::alive_time( )
{
    auto time =  ( Timer::tick( ) - this->alive_time_ ) / 1000;
    return  time;
}

size_t NodeSession::delay( )
{
    return ( Timer::tick( ) - this->alive_time_ ) / 2 - MasterConfig::alive_time;
}

void NodeSession::add_block( sptr<BlockMeta> block )
{
    this->own_block_.push_back( move_ptr( block ) );
}