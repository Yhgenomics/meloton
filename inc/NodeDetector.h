/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-01
* Description:
* * * * * * * * * * * * * * * */

#ifndef NODE_DETECTOR_H_
#define NODE_DETECTOR_H_

#include "MRT.h"
#include <functional>

#include "uv.h"

class NodeDetector
{
public:

    typedef std::function<void( sockaddr_in* )> cb_on_detected_t;

    static NodeDetector* instance( )
    {
        static NodeDetector inst_;
        return &inst_ ;
    };

    void callback( cb_on_detected_t callback );
    void start( );
    void stop( );

    bool detected = false;

private:

    NodeDetector( );

    bool                started_    = false;
    cb_on_detected_t    callback_   = nullptr;
    uv_loop_t*          uv_loop_;
    uv_udp_t            uv_udp_     = { 0 };

    static void uv_alloc_callback( uv_handle_t* handle,
                                   size_t suggested_size,
                                   uv_buf_t* buf );

    static void uv_read_callback ( uv_udp_t* handle,
                                   ssize_t nread,
                                   const uv_buf_t* buf,
                                   const struct sockaddr* addr,
                                   unsigned flags );
};

#endif // !NODE_DETECTOR_H_
