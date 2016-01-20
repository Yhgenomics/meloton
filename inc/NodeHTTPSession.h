/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2016-01-18
* Description:
* * * * * * * * * * * * * * * */

#ifndef HTTP_NODE_SESSION_H_
#define HTTP_NODE_SESSION_H_

#include <MRT.h>

class NodeHTTPSession :
    public MRT::Session
{
public:

    virtual void on_connect ( )                        override;
    virtual void on_read    ( uptr<MRT::Buffer> data ) override;
    virtual void on_write   ( uptr<MRT::Buffer> data ) override;
    virtual void on_close   ( )                        override;

private:

    MRT::HTTPRequest req_;
};

#endif // !HTTP_NODE_SESSION_H_
