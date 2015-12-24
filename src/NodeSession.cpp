#include "NodeSession.h"
#include "MasterConfig.h"

NodeSession::NodeSession( )
{
    this->update_alive( );
}

NodeSession::~NodeSession( )
{

}

void NodeSession::update_alive( )
{
    this->alive_time_ = Timer::tick( );
}

size_t NodeSession::alive_time( )
{
    return  (Timer::tick( ) - this->alive_time_);
}

size_t NodeSession::delay( )
{
    return ( Timer::tick( ) - this->alive_time_ ) / 2 - MasterConfig::alive_time;
}