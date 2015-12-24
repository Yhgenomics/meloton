/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-24
* Description: handler for MessageGetTokenACK
* * * * * * * * * * * * * * * */

#ifndef MESSAGEGETTOKENACK_HANDLER_
#define MESSAGEGETTOKENACK_HANDLER_

#include <string>
#include <memory>

#include <MRT.h>
#include <ClusterSession.h>
#include <google/protobuf/message.h>
#include <MessageGetTokenACK.pb.h>

static int MessageGetTokenACKHandler( ClusterSession * session , uptr<MessageGetTokenACK> msg )
{
    return 0;
}

#endif

// !MESSAGEGETTOKENACK_HANDLER_
