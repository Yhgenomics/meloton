/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-31
* Description: handler for MessageRequestGet
* * * * * * * * * * * * * * * */

#ifndef MESSAGEREQUESTGET_HANDLER_
#define MESSAGEREQUESTGET_HANDLER_

#include <string>
#include <memory>

#include <MRT.h>
#include <ClusterSession.h>
#include <google/protobuf/message.h>
#include <MessageRequestGet.pb.h>

static int MessageRequestGetHandler( ClusterSession * session , uptr<MessageRequestGet> msg )
{
    return 0;
}

#endif

// !MESSAGEREQUESTGET_HANDLER_
