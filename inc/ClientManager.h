/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-31
* Description:
* * * * * * * * * * * * * * * */

#ifndef CLIENT_MANAGER_H_
#define CLIENT_MANAGER_H_

#include <meloton.h>
#include <PoolManager.h>
#include <ClientSession.h>

class ClientManager :
    public ::PoolManager<ClientSession>
{
public:

    SINGLETON( ClientManager );
    
    ~ClientManager( )
    {

    }

    sptr<ClientSession> find_session( size_t id )
    {
        return this->find_node( [&id] ( sptr<ClientSession> session )
        {
            if ( session->id( ) == id ) return true;

            return false;
        } );
    }

protected:

    ClientManager( )
        : PoolManager( 10240 )
    {

    }

private:

};

#endif // !CLIENT_MANAGER_H_
