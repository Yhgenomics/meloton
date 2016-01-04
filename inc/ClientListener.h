/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-31
* Description:
* * * * * * * * * * * * * * * */

#ifndef CLIENT_LISTENER_H_
#define CLIENT_LISTENER_H_

#include <MRT.h>
#include <string>

class ClientListener : 
    public MRT::Listener
{
public:

    ClientListener( std::string ip , int port );
    ~ClientListener( );

private:

    virtual MRT::Session * create_session( ) override;

    virtual void on_session_open( MRT::Session * session ) override;

    virtual void on_session_close( MRT::Session * session ) override;

};

#endif // !CLIENT_LISTENER_H_
