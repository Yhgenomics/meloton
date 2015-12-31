#include <ClientListener.h>
#include <ClientSession.h>
#include <ClientManager.h>

ClientListener::ClientListener( std::string ip , int port  )
    : Listener( ip , port )
{

}

ClientListener::~ClientListener( )
{
}

MRT::Session * ClientListener::create_session( )
{ 
    return new ClientSession( );
}

void ClientListener::on_session_open( MRT::Session * session )
{
    auto ins = sptr<ClientSession>( ( ClientSession* ) session );
    ClientManager::instance( )->push_node( ins );
}

void ClientListener::on_session_close( MRT::Session * session )
{
    auto ins = sptr<ClientSession>( ( ClientSession* ) session );
    ClientManager::instance( )->remove_node( ins );
}
