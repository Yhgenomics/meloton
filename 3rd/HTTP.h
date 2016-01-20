/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-11-20
* Description:
* * * * * * * * * * * * * * * */

#ifndef HTTP_H_
#define HTTP_H_

#include <string>
#include <map>
#include <functional>

#include "Macro.h"
#include "Buffer.h"
#include "Connector.h"
#include "CircleBuffer.h"
#include "Maraton.h"

NS_MARATON_BEGIN

class HTTPRequest;
class HTTPResponse;

typedef std::function<uptr<Buffer>( HTTPRequest* req )> write_callback_t;
typedef std::function<uptr<Buffer>( HTTPResponse* rep )> read_callback_t;
typedef std::function<void( HTTPResponse* rep , uptr<Buffer> buffer )> rep_read_callback_t;

class Url
{
public:

    Url                  ( std::string url );
    ~Url                 ( );
                    
    std::string domain   ( );
    std::string path     ( );
    std::string protocol ( );
    int port             ( );

protected:

    virtual void parse( std::string url );

private:

    std::string url_      = "";
    std::string domain_   = "";
    std::string path_     = "";
    std::string protocol_ = "";
    int port_             = 80;
    std::string tmp_      = "";
};
// ===========================================
// HTTPRequest
// ===========================================
class HTTPRequest
{
public:
     
    HTTPRequest ( std::string url ,
                  std::string method );
    HTTPRequest ( );
    ~HTTPRequest( );

    void write_callback         ( write_callback_t callback );

    void content                ( uptr<Buffer> content );
    uptr<Buffer> content        ( );
    void content_length         ( size_t size );
    size_t content_length       ( );
    
    void header                 ( std::string key ,
                                  std::string value );
    std::string header          ( std::string key );
    std::string domain          ( ){ return this->domain_; };
    std::string host            ( ){ return this->ip_;};

    void parse                  ( uptr<Buffer> data );

    uptr<Buffer> build_header   ( );
    uptr<Buffer> build_body     ( );

    void* data                  ( );
    void data                   ( void* value );

    bool finish                 ( );
     
private:

    std::string                         ip_             = "";
    int                                 port_           = 0;
    std::string                         url_            = "";
    std::string                         method_         = "";
    std::string                         domain_         = "";
    std::map<std::string , std::string> header_;
    size_t                              content_length_ = 0;
    uptr<Buffer>                        content_        = nullptr;
    write_callback_t                    write_callback_ = nullptr;
    void*                               data_           = nullptr;

    // Parsing used
    // ==================================================================
    enum ParseState
    {
        kMethod = 1,
        kUrl,
        kProtocol,
        kHeadKey,
        kHeadValue,
        kContent
    };

    ParseState  parse_state_ = ParseState::kMethod;
    std::string tmp_key_     = "";
    std::string tmp_value_   = "";
    std::string protocol_    = "";

    friend class WebClient;
};

// ===========================================
// HTTPResponse
// ===========================================
class HTTPResponse
{
public:
     
    //HTTPResponse                 ( size_t status );
    HTTPResponse                 ( );
    ~HTTPResponse                ( );

    void         read_callback   ( rep_read_callback_t callback );
                                 
    void*        data            ( );
    void         data            ( void* value );
                                        
    void         header          ( std::string key , 
                                   std::string value );
    std::string  header          ( std::string key );
                 
    void         content         ( uptr<Buffer> content );
    uptr<Buffer> content         ( );
    void         content_length  ( size_t size );
    size_t       content_length  ( );

    void         status          ( size_t code );
    size_t       status          ( );

    uptr<Buffer> build_header    ( );
    uptr<Buffer> build_body      ( );

    void         parse           ( uptr<Buffer> data );

    bool         finish          ( );

private: 

    size_t              status_         = 0;
    std::string         status_str_     = "";
    size_t              content_length_ = 0;
    std::string         protocol_       = "";
    rep_read_callback_t read_callback_  = nullptr;
    void*               data_           = nullptr;
    uptr<Buffer>        content_        = nullptr;
    std::map<
       std::string , 
       std::string> header_;

    // Parsing used
    // ==================================================================
    enum ParseState
    {
        kProtocol = 1,
        kStatusCode,
        kStatus,
        kHeadKey,
        kHeadValue,
        kContent
    };
   
    ParseState   parse_state_ = ParseState::kProtocol;
    std::string  tmp_key_     = "";
    std::string  tmp_value_   = "";
}; 

class WebRequestSession :
    public Session
{
public:

    WebRequestSession           ( uptr<HTTPRequest> req );
    ~WebRequestSession          ( );

    uptr<HTTPResponse> response ( );

protected:

    virtual void on_connect ( )                  ;
    virtual void on_read    ( uptr<Buffer> data );
    virtual void on_write   ( uptr<Buffer> data );
    virtual void on_close   ( )                  ;

private:

    uptr<HTTPRequest>       req_;
    uptr<HTTPResponse>      rep_;
};

//// ===========================================
//// WebRequestConnector
//// ===========================================
//class WebRequestConnector :
//    public Connector
//{
//public:
//
//    WebRequestConnector ( uptr<HTTPRequest> req , 
//                          callback_response_t callback);
//    ~WebRequestConnector( );
//protected:
//
//    virtual Session * create_session( ) override;
//
//    virtual void on_session_open    ( Session * session ) override;
//
//    virtual void on_session_close   ( Session * session ) override;
//
//private:
//
//    uptr<HTTPRequest> req_;
//    callback_response_t callback_response_;
//};
//
//// ===========================================
//// WebClient
//// ===========================================
//class WebClient
//{
//public:
//
//    void get( std::string url , 
//              callback_response_t callback);
//};

NS_MARATON_END

#endif // !HTTP_H_