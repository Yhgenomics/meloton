/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-10-22
* Description:
* * * * * * * * * * * * * * * */

#ifndef NETWORK_DATA_BUILDER_H_
#define NETWORK_DATA_BUILDER_H_

#include <memory.h>
#include <Macro.h>
#include "Buffer.h"

NS_MARATON_BEGIN

class CircleBuffer
{
public:

    CircleBuffer ( );

    ~CircleBuffer( );

    virtual bool push           ( Buffer & buf );
    virtual bool push           ( const char* data , size_t len );
    virtual bool push           ( uptr<Buffer> buf );
    void         clear          ( );

    virtual uptr<Buffer> pop    ( size_t len );

    size_t length               ( ) { return this->buffer_length_; };
    size_t used_length          ( ) { return this->used_len_; };
    size_t available_length     ( ) { return this->available_len_; };

    size_t tail_ = 0;
    size_t head_ = 0;

private:

    CircleBuffer                ( CircleBuffer & ) = delete;
    CircleBuffer                ( CircleBuffer && ) = delete;
    CircleBuffer operator=      ( CircleBuffer ) = delete;

    size_t used_len_            = 0;
    size_t available_len_       = 0;

    const int buffer_length_    = MAX_CIRCLE_BUFFER_SIZE;

    char* circle_buffer_        = nullptr;
};

NS_MARATON_END

#endif // !NETWORK_DATA_BUILDER_H_