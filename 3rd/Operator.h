/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-11-19
* Description:
* * * * * * * * * * * * * * * */

#ifndef MRT_OPERATOR_H_
#define MRT_OPERATOR_H_

#include <string>

#include "Macro.h"
#include "uv.h"
#include "Session.h"

NS_MARATON_BEGIN

class Operator
{
public:

    Operator( std::string address , int port ); 

    virtual     ~Operator   ( );
    std::string ip          ( );
    std::string address     ( );
    int         port        ( ); 

protected:

    virtual Session * create_session    ( ) = 0;
    virtual void      on_session_open   ( Session * session ) = 0;
    virtual void      on_session_close  ( Session * session ) = 0;

    virtual void      close_session     ( Session* session ) = 0;
    virtual void      do_work           ( ) = 0;

private:
    
    std::string       ip_              = "";
    std::string       address_         = "";
    int               port_            = 0; 
    uv_loop_t*        uv_loop_         = nullptr;
    uv_getaddrinfo_t  uv_getaddrinfo_  = { 0 };
    addrinfo          addrinfo_        = { 0 };
    sockaddr_in       addr_in_         = { 0 };
    size_t            index_           = 0 ;
     
    friend class Maraton;
    friend class Listener;
    friend class Connector;
    friend class Session;
};

NS_MARATON_END

#endif // !MRT_OPERATOR_H_
