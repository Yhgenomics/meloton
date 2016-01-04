/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-31
* Description: handler for MessagePut
* * * * * * * * * * * * * * * */

#ifndef MESSAGEPUT_HANDLER_
#define MESSAGEPUT_HANDLER_

#include <string>
#include <memory>

#include <MRT.h>
#include <ClusterSession.h>
#include <google/protobuf/message.h>
#include <MessagePut.pb.h>

static int MessagePutHandler( ClusterSession * session , uptr<MessagePut> msg )
{
    return 0;
}

#endif

// !MESSAGEPUT_HANDLER_
