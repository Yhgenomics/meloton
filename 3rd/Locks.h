/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-02
* Description:
* * * * * * * * * * * * * * * */

#ifndef LOCKS_H_
#define LOCKS_H_

#include "Macro.h"
#include "uv.h"

NS_MARATON_BEGIN

class Mutex
{
public:

    Mutex( );
    ~Mutex( );

    void wait( );
    void release( );

private:

    uv_mutex_t mutex_ = { 0 };
};

class Semaphore
{
public:

    Semaphore( );
    Semaphore( int initNum );
    ~Semaphore( );

    void wait( );
    void release( );

private:

    uv_sem_t sem_ = { 0 };
};

NS_MARATON_END

#endif // !LOCKS_H_
