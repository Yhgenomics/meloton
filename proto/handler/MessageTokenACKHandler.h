/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2016-01-07
* Description: handler for MessageTokenACK
* * * * * * * * * * * * * * * */

#ifndef MESSAGETOKENACK_HANDLER_
#define MESSAGETOKENACK_HANDLER_

#include <string>
#include <memory>

#include <MRT.h>
#include <ClusterSession.h>
#include <google/protobuf/message.h>
#include <MessageTokenACK.pb.h>

static int MessageTokenACKHandler( ClusterSession * session , uptr<MessageTokenACK> msg )
{
    return 0;
}

#endif

// !MESSAGETOKENACK_HANDLER_
