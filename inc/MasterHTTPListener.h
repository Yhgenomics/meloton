/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-10
* Description:
* * * * * * * * * * * * * * * */

#ifndef MASTER_HTTP_LISTENER
#define MASTER_HTTP_LISTENER

#include <string>

#include "MRT.h"

class MasterHTTPListener :
    public MRT::Listener
{
public:
    MasterHTTPListener( std::string ip );
    ~MasterHTTPListener( );

    virtual MRT::Session * create_session( ) override;
    virtual void on_session_open( MRT::Session * session ) override;
    virtual void on_session_close( MRT::Session * session ) override;
};

#endif // !MASTER_HTTP_LISTENER
