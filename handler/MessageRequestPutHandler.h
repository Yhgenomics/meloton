/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-28
* Description: handler for MessageRequestPut
* * * * * * * * * * * * * * * */

#ifndef MESSAGEREQUESTPUT_HANDLER_
#define MESSAGEREQUESTPUT_HANDLER_

#include <string>
#include <memory>

#include <MRT.h>
#include <ClusterSession.h>
#include <google/protobuf/message.h>
#include <MessageRequestPut.pb.h>

static int MessageRequestPutHandler( ClusterSession * session , uptr<MessageRequestPut> msg )
{
    return 0;
}

#endif

// !MESSAGEREQUESTPUT_HANDLER_
