/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-02
* Description: map messages to id
* * * * * * * * * * * * * * * */

#ifndef MESSAGE_UTILS_H_
#define MESSAGE_UTILS_H_

#include "Message1.h"
#include "Messagea2.h"
#include "Message3.h"

class MessageIDFactory
{
public:
    inline static size_t get_id(Message1 message){ return (size_t)0x316567617373654D; };
    inline static void set_id(Message1 & message){ item.MessageId(0x316567617373654D); };
    inline static size_t get_id(Messagea2 message){ return (size_t)0x616567617373657F; };
    inline static void set_id(Messagea2 & message){ item.MessageId(0x616567617373657F); };
    inline static size_t get_id(Message3 message){ return (size_t)0x336567617373654D; };
    inline static void set_id(Message3 & message){ item.MessageId(0x336567617373654D); };
}

// !MESSAGE_UTILS_H_