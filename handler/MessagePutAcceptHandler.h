/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2016-01-21
* Description: handler for MessagePutAccept
* * * * * * * * * * * * * * * */

#ifndef MESSAGEPUTACCEPT_HANDLER_
#define MESSAGEPUTACCEPT_HANDLER_

#include <string>
#include <memory>

#include <MRT.h>
#include <ClusterSession.h>
#include <google/protobuf/message.h>
#include <MessagePutAccept.pb.h>

static int MessagePutAcceptHandler( ClusterSession * session , uptr<MessagePutAccept> msg )
{
    return 0;
}

#endif

// !MESSAGEPUTACCEPT_HANDLER_
