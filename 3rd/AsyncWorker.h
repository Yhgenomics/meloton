/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       :
* Description:
* * * * * * * * * * * * * * * */

#ifndef ASYNC_WORKER_H_
#define ASYNC_WORKER_H_ 

#include <functional>

#include "Macro.h"
#include "uv.h"

NS_MARATON_BEGIN

class AsyncWorker;

class IAsyncWorkerNotifier
{
public:
    virtual void on_async_work( AsyncWorker* worker ) { };
    virtual void on_async_work_finish( AsyncWorker* worker ) { };
};

class AsyncWorker
{
public:

    typedef std::function<void( AsyncWorker* )> callback_t;
    
    static AsyncWorker* create ( callback_t acting , 
                                 callback_t finish, 
                                 void* data );

    static AsyncWorker* create ( callback_t acting , 
                                 void* data );

    static void         stop   ( AsyncWorker* worker );


    void data           ( void* value ) { this->data_ = value; };
    void* data          ( ) { return this->data_; };


private:

    void stop( );
    AsyncWorker( callback_t acting, callback_t finish );

    void start();

    void*       data_;
    uv_work_t   worker;
    callback_t  acting_callback_;
    callback_t  finish_callback_;

    static void uv_process_work_callback( uv_work_t* req );
    static void uv_process_after_work_callback( uv_work_t* req , int status );
};

NS_MARATON_END

#endif // !ASYNC_WORKER_H_ 
 