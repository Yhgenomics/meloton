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

template<class T>
class AsyncToken
{
public:

    typedef std::function<void( AsyncToken*, uptr<T> )> callback_t;

    static void create( callback_t callback , uptr<T> data )
    {
        AsyncToken* token = new AsyncToken( callback );
        token->send( move_ptr( data ) );
    }

    AsyncToken( callback_t callback )
    {
        this->callback_     = callback;
        this->async_.data   = this;
        uv_async_init( uv_default_loop( ) ,
                       &this->async_ ,
                       AsyncToken::uv_async_callback );
    }

    ~AsyncToken( )
    {
        //uv_close( ( uv_handle_t* ) &this->async_ , NULL );
    }

    void send( uptr<T> data )
    {
         this->data_ = move_ptr( data );
         uv_async_send( &this->async_ );
    }

private:

    static void uv_async_callback( uv_async_t* handle )
    {
        AsyncToken* token = scast<AsyncToken*>( handle->data );

        if ( token->callback_ != nullptr )
        {
            token->callback_( token , move_ptr( token->data_ ) );
        }
       
        SAFE_DELETE( token );
    }

    uptr<T>  data_        = nullptr;
    uv_async_t  async_       = { 0 };
    callback_t  callback_    = nullptr;
};
 

NS_MARATON_END

#endif // !ASYNC_TOKEN_H_
