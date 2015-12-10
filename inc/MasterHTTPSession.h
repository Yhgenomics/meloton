/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-10
* Description:
* * * * * * * * * * * * * * * */

#ifndef MASTER_HTTP_SESSION_H_
#define MASTER_HTTP_SESSION_H_

#include "MRT.h"

class MasterHTTPSession : 
    public MRT::Session
{
public:
    MasterHTTPSession   ( );
    ~MasterHTTPSession  ( );

    void send_message   ( uptr<MRT::HTTPResponse> response );

protected:

    virtual void on_connect ( )                        override;
    virtual void on_read    ( uptr<MRT::Buffer> data ) override;
    virtual void on_write   ( uptr<MRT::Buffer> data ) override;
    virtual void on_close   ( )                        override;

private:

    MRT::HTTPRequest request_;
};

#endif // !MASTER_HTTP_SESSION_H_
