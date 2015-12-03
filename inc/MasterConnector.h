/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-3
* Description:
* * * * * * * * * * * * * * * */

#ifndef MASTER_CONNECTOR_H_
#define MASTER_CONNECTOR_H_

#include "MRT.h"

class MasterConnector :
    public MRT::Connector
{
public:

    MasterConnector( std::string ip , int port );
    ~MasterConnector( );

protected:

private:
    
    virtual MRT::Session * create_session( ) override;

    virtual void on_session_open( MRT::Session * session ) override;

    virtual void on_session_close( MRT::Session * session ) override;
};

#endif // !MASTER_CONNECTOR_H_
