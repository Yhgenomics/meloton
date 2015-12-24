/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-24
* Description: handler for MessagePutTokenACK
* * * * * * * * * * * * * * * */

#ifndef MESSAGEPUTTOKENACK_HANDLER_
#define MESSAGEPUTTOKENACK_HANDLER_

#include <string>
#include <memory>

#include <MRT.h>
#include <ClusterSession.h>
#include <google/protobuf/message.h>
#include <MessagePutTokenACK.pb.h>

static int MessagePutTokenACKHandler( ClusterSession * session , uptr<MessagePutTokenACK> msg )
{
    return 0;
}

#endif

// !MESSAGEPUTTOKENACK_HANDLER_
