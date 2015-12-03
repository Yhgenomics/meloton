#include "NodeListener.h"
#include "NodeSession.h"

NodeListener::NodeListener( std::string ip , int port )
    : MRT::Listener( ip , port )
{
}

NodeListener::~NodeListener( )
{
}

Session * NodeListener::create_session( )
{
    return new NodeSession( );
}

void NodeListener::on_session_open( Session * session )
{

}

void NodeListener::on_session_close( Session * session )
{

}
