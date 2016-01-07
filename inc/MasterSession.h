/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-03
* Description:
* * * * * * * * * * * * * * * */

#ifndef MASETER_SESSION_H_
#define MASETER_SESSION_H_

#include "ClusterSession.h"
#include "MRT.h"

class MasterSession :
    public ClusterSession
{
public:

    static MasterSession* instance( );

    MasterSession( );
    ~MasterSession( );

    PP_DEF( size_t , session_id )

    void sync_all_block( );
    void alive( );

    virtual void on_connect ( ) override;
    virtual void on_close   ( ) override;

protected:

private:
    
    size_t              session_id_ = 0;
    MRT::SyncWorker*    worker_     = nullptr;


    static MasterSession* instance_;
    friend class MasterConnector;
};

#endif // !MASETER_SESSION_H_
