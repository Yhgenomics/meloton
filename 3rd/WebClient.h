/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-11-22
* Description:
* * * * * * * * * * * * * * * */

#ifndef WEB_CLIENT_H_
#define WEB_CLIENT_H_

#include <string>
#include <map>

#include "uv.h"
#include "HTTP.h"

NS_MARATON_BEGIN 

typedef std::function<void( uptr<HTTPResponse> )>  callback_response_t;
 
class WebClient
{
public:

    WebClient ( );

    void get        ( std::string url , 
                      callback_response_t callback );

    void post       ( std::string url , 
                      std::string data , 
                      callback_response_t callback );

    void post_file  ( std::string url , 
                      std::string file_token , 
                      FILE* pfile , 
                      callback_response_t callback );

    void dl_file    ( std::string url ,
                      FILE* pfile ,
                      callback_response_t callback);

    void header( std::string key, std::string value );

private:

    class WebClientRequestToken
    {
    public:

        uptr<HTTPRequest>   req              = nullptr;
        uptr<HTTPResponse>  rep              = nullptr;
        callback_response_t callback         = nullptr; 

        std::string       ip                 = "";
        std::string       address            = "";
        int               port               = 0;
        uv_loop_t*        uv_loop            = nullptr;
        uv_getaddrinfo_t  uv_getaddrinfo     = { 0 };
        addrinfo          addrinfo           = { 0 };
        sockaddr_in       addr_in            = { 0 };
                                            
        uv_connect_t      uv_connect         = { 0 };
        uv_tcp_t          uv_tcp             = { 0 };

        void invoke_callback( uptr<HTTPResponse> rep )
        {
            if ( this->callback != nullptr )
            {
                this->callback( move_ptr( rep ) );
            }
        }
    };

    struct write_token_t
    {
        uv_write_t *                writer  = nullptr;
        uv_buf_t *                  buffer  = nullptr;
        WebClientRequestToken *     session = nullptr;
    };

    void query_dns                      ( uptr<WebClientRequestToken> token );
    void fill_header                    ( HTTPRequest* req );
    static void uv_send_request         ( WebClientRequestToken* token );
    static void uv_process_resolved     ( uv_getaddrinfo_t * req , 
                                          int status , 
                                          addrinfo * res );
    static void uv_connected_callback   ( uv_connect_t* req , 
                                          int status );
    static void uv_alloc_callback       ( uv_handle_t * handle , 
                                          size_t suggested_size , 
                                          uv_buf_t * buf );
    static void uv_read_callback        ( uv_stream_t * stream , 
                                          ssize_t nread , 
                                          const uv_buf_t * buf );
    static void uv_write_callback       ( uv_write_t * req , 
                                          int status );
    static void uv_close_callback       ( uv_handle_t* handle );

    std::map<std::string , std::string> header_;
};

NS_MARATON_END

#endif // !WEB_CLIENT_H_
