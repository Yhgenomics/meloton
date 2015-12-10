/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-03
* Description:
* * * * * * * * * * * * * * * */

#ifndef MASETER_SESSION_H_
#define MASETER_SESSION_H_

#include "ClusterSession.h"

class MasterSession :
    public ClusterSession
{
public:

    static MasterSession* instance( );

    MasterSession( );
    ~MasterSession( );

    virtual void on_connect ( ) override;

protected:

private:

    static MasterSession* instance_;

    friend class MasterConnector;
};

#endif // !MASETER_SESSION_H_
