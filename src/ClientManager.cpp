#include <ClientManager.h>

ClientManager::ClientManager( )
    : Manager( 10240 )
{

}

ClientManager::~ClientManager( )
{

}

sptr<ClientSession> ClientManager::find_session( size_t id )
{
    return this->find_node( [&id] ( sptr<ClientSession> session )
    { 
        if ( session->id( ) == id ) return true;

        return false;
    } );
}

