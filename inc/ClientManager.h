/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-31
* Description:
* * * * * * * * * * * * * * * */

#ifndef CLIENT_MANAGER_H_
#define CLIENT_MANAGER_H_

#include <meloton.h>
#include <Manager.h>
#include <ClientSession.h>

class ClientManager :
    public ::Manager<ClientSession>
{
public:

    ~ClientManager( );
    SINGLETON( ClientManager );

    sptr<ClientSession> find_session( size_t id );

protected:

    ClientManager( );

private:

};

#endif // !CLIENT_MANAGER_H_
