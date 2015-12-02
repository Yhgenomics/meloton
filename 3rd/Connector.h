/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-11-19
* Description:
* * * * * * * * * * * * * * * */

#ifndef MRT_CONNECTOR_H_
#define MRT_CONNECTOR_H_

#include <string>

#include "Macro.h"
#include "Operator.h"

NS_MARATON_BEGIN

class Connector :
    public Operator
{
public:

    Connector    ( std::string addr,
                   int port );
    ~Connector   ( );
                 
protected:       
     
    //virtual Session * create_session    ( ) = 0;
    //virtual void      on_session_open   ( Session * session ) = 0;
    //virtual void      on_session_close  ( Session * session ) = 0;
                                        
    void              do_work           ( ) override;
    void              close_session     ( Session * session ) override;

private:

    uv_connect_t      uv_connect_          = { 0 };
    uv_tcp_t          uv_tcp_              = { 0 };

    static void uv_connected_callback   ( uv_connect_t* req , 
                                          int status );
    static void uv_alloc_callback       ( uv_handle_t * handle , 
                                          size_t suggested_size , 
                                          uv_buf_t * buf );
    static void uv_read_callback        ( uv_stream_t * stream , 
                                          ssize_t nread , 
                                          const uv_buf_t * buf );
    static void uv_close_callback       ( uv_handle_t* handle );

    Session*    session_ = nullptr;

    friend class Session;
};

NS_MARATON_END

#endif // !MRT_CONNECTOR_H_
