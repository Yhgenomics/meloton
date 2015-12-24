#include "NodeListener.h"
#include "NodeSession.h"
#include "NodeManager.h"

NodeListener::NodeListener( std::string ip , int port )
    : MRT::Listener( ip , port )
{
}

NodeListener::~NodeListener( )
{
}

Session * NodeListener::create_session( )
{
    return NodeManager::instance( )->create_node( );
}

void NodeListener::on_session_open( Session * session )
{
    auto ptr = sptr<NodeSession>( (NodeSession*)session );
    NodeManager::instance( )->push_node( ptr );
}

void NodeListener::on_session_close( Session * session )
{
    auto ptr = sptr<NodeSession>( (NodeSession*)session );
    NodeManager::instance( )->remove_node( ptr );
}
