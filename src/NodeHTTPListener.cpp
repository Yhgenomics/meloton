#include <NodeHTTPListener.h>
#include <NodeHTTPSession.h>

NodeHTTPListener::NodeHTTPListener( std::string ip , int port )
    : Listener( ip , port )
{

}

NodeHTTPListener::~NodeHTTPListener( )
{
}

MRT::Session * NodeHTTPListener::create_session( )
{
    return new NodeHTTPSession( );
}

void NodeHTTPListener::on_session_open( MRT::Session * session )
{

}

void NodeHTTPListener::on_session_close( MRT::Session * session )
{

}
