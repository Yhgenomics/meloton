/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-11-11
* Description:
* * * * * * * * * * * * * * * */

#ifndef SYNC_WORKER_H_
#define SYNC_WORKER_H_

#include <functional>

#include "uv.h"
#include "Macro.h"

NS_MARATON_BEGIN

class SyncWorker
{
public:

    typedef std::function<bool( SyncWorker* )> syncworker_callback_t;

    static SyncWorker* create       ( const syncworker_callback_t  work_callback , 
                                      const syncworker_callback_t  after_callback , 
                                      void* data );

    static SyncWorker* create       ( const size_t time_span,
                                      const syncworker_callback_t  work_callback , 
                                      const syncworker_callback_t  after_callback , 
                                      void* data );
    static void        stop         ( SyncWorker * worker );

    void*              data         ( ) { return this->data_; };
    void               data         ( void* value ) { this->data_ = value; };
    size_t             loop_count   ( ) { return loop_count_; };
    size_t             loop_time    ( ) { return loop_time_ * loop_count_; };

private:

    static void uv_process_timer_tick_callback( uv_timer_t* handle );

    SyncWorker  ( );
    ~SyncWorker ( );

    void stop   ( );
    void start  ( );

    bool                            finished_       = false;
    void*                           data_           = nullptr;
    uv_timer_t                      timer_          = { 0 };
    size_t                          loop_time_      = 1;

    syncworker_callback_t           cb_work_        = nullptr;
    syncworker_callback_t           cb_after_work_  = nullptr;
    size_t                          loop_count_     = 1;
};

NS_MARATON_END

#endif // !SYNC_WORKER_H_