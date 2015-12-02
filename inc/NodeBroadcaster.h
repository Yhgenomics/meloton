/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-01
* Description:
* * * * * * * * * * * * * * * */

#ifndef NODE_BROADCASTER_H_
#define NODE_BROADCASTER_H_

#include "MRT.h"
#include "uv.h"

class NodeBroadcaster
{
public:

    static NodeBroadcaster* instance( )
    {
        static NodeBroadcaster inst_;
        return &inst_;
    }

    ~NodeBroadcaster( );

    void start( );
    void stop( );

protected:

    NodeBroadcaster( );

private:

    static void uv_udp_sent_callback( uv_udp_send_t* req , int status );

    uv_loop_t * uv_loop_;
    uv_udp_t    uv_udp_     = { 0 };
    bool        started_    = false;
    char broadcast_data_[5]  = { 'Y','H' };

    uv_buf_t make_discover_msg( );

};

#endif // !NODE_BROADCASTER_H_
