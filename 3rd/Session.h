/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-11-19
* Description:
* * * * * * * * * * * * * * * */

#ifndef MRT_SESSION_H_
#define MRT_SESSION_H_

#include "Macro.h"
#include "Buffer.h"
#include "uv.h"

NS_MARATON_BEGIN

class Operator;

class Session
{
public:

    Session( );
    virtual ~Session();

    void close  ( );

    PP_DEF( std::string , ip_address )
    PP_DEF( int , port )

protected:
    
    Operator* opt_ =  nullptr;

            void send       ( uptr<Buffer> data );
    virtual void on_connect ( )                   { };
    virtual void on_read    ( uptr<Buffer> data ) { };
    virtual void on_write   ( uptr<Buffer> data ) { };
    virtual void on_close   ( )                   { };

private:
    
    enum SessionMode
    {
        Unknown = 0 ,
        Server ,
        Client 
    };

    struct write_token_t
    {
        uv_write_t *        writer;
        uv_buf_t *          buffer;
        Session *           session;
    };

    uv_tcp_t    uv_tcp_         = { 0 };
    std::string ip_address_     = "";
    int         port_           = 0;
    bool        is_connected_   = false;
    
    static void uv_write_callback ( uv_write_t * req, int status );

    friend class Operator;
    friend class Listener;
    friend class Connector;
};

NS_MARATON_END

#endif // !MRT_SESSION_H_