/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-11-19
* Description:
* * * * * * * * * * * * * * * */

#ifndef MRT_LISTENER_H_
#define MRT_LISTENER_H_

#include <string>

#include "Macro.h"
#include "Operator.h"

NS_MARATON_BEGIN

class Listener :
    public Operator
{
public:

    Listener    ( std::string addr , 
                  int port );
    ~Listener   ( );

protected:

    //virtual Session * create_session    ( ) = 0;
    //virtual void      on_session_open   ( Session * session ) = 0;
    //virtual void      on_session_close  ( Session * session ) = 0;
                                        
    void              do_work           ( ) override;
    void              close_session     ( Session * session ) override;

private:

    uv_tcp_t uv_tcp_ = { 0 }; 

    Session* session_list_[MAX_CONNECTION_SIZE] = { 0 };
    size_t   session_list_index_                = 0;

    static void uv_new_connection_callback ( uv_stream_t * server ,
                                             int status );
    static void uv_alloc_callback          ( uv_handle_t * handle , 
                                             size_t suggested_size , 
                                             uv_buf_t * buf );
    static void uv_read_callback           ( uv_stream_t * stream , 
                                             ssize_t nread , 
                                             const uv_buf_t * buf );
    static void uv_close_callback          ( uv_handle_t * handle );
};

NS_MARATON_END

#endif // !MRT_LISTENER_H_
