/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-02
* Description:
* * * * * * * * * * * * * * * */

#ifndef ASYNC_TOKEN_H_
#define ASYNC_TOKEN_H_

#include <functional>

#include "Macro.h"
#include "uv.h"

NS_MARATON_BEGIN

class AsyncToken
{
public:

    typedef std::function<void( AsyncToken*,void* )> callback_t;

    AsyncToken( callback_t callback );
    ~AsyncToken( );

    void send( void* data );

private:

    static void uv_async_callback( uv_async_t* handle );

    void*      data_        = nullptr;
    uv_async_t async_       = { 0 };
    callback_t callback_    = nullptr;
};

NS_MARATON_END

#endif // !ASYNC_TOKEN_H_
