/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-11-13
* Description:
* * * * * * * * * * * * * * * */

#ifndef BUFFER_H_
#define BUFFER_H_

#include <string>
#include "Macro.h"

NS_MARATON_BEGIN

class Buffer
{
public:

     Buffer( );
    ~Buffer( );

    Buffer( size_t size );
    Buffer( std::string string );
    Buffer( const char* data , size_t size );
    Buffer( Buffer& buffer );
    Buffer( Buffer&& buffer );
    Buffer& operator =( Buffer& buffer );
    Buffer& operator =( Buffer&& buffer );
    Buffer& operator +=( const Buffer& buffer );
    char    operator[]( const size_t index );

    char*   data( );
    void    data( const char * value , size_t size );
    size_t  size( ) { return this->size_; }
    void    push( const char* data , size_t len );
    void    zero( );

private:

    char*   data_  = nullptr;
    size_t  size_  = 0;
    char*   pdata_ = nullptr;

    void    clearup( );
};

NS_MARATON_END

#endif // !BUFFER_H_
