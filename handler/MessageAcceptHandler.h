/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-03
* Description: handler for MessageAccept
* * * * * * * * * * * * * * * */

#ifndef MESSAGEACCEPT_HANDLER_
#define MESSAGEACCEPT_HANDLER_

#include <string>
#include <memory>

#include <MRT.h>
#include <ClusterSession.h>
#include <google/protobuf/message.h>
#include <MessageAccept.pb.h>

static int MessageAcceptHandler( ClusterSession * session , uptr<MessageAccept> msg )
{
    
    return 0;
}

#endif

// !MESSAGEACCEPT_HANDLER_
