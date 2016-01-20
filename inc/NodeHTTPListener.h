/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2016-01-18
* Description:
* * * * * * * * * * * * * * * */

#ifndef HTTP_NODE_LISTENER_H_
#define HTTP_NODE_LISTENER_H_

#include <string>
#include <MRT.h>

class NodeHTTPListener :
    public MRT::Listener
{
public:

    NodeHTTPListener( std::string ip , int port );
    ~NodeHTTPListener( );

    virtual MRT::Session * create_session( ) override;

    virtual void on_session_open( MRT::Session * session ) override;

    virtual void on_session_close( MRT::Session * session ) override;

};

#endif // !HTTP_NODE_LISTENER_H_
