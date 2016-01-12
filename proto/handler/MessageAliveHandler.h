/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2016-01-07
* Description: handler for MessageAlive
* * * * * * * * * * * * * * * */

#ifndef MESSAGEALIVE_HANDLER_
#define MESSAGEALIVE_HANDLER_

#include <string>
#include <memory>

#include <MRT.h>
#include <ClusterSession.h>
#include <google/protobuf/message.h>
#include <MessageAlive.pb.h>

static int MessageAliveHandler( ClusterSession * session , uptr<MessageAlive> msg )
{
    return 0;
}

#endif

// !MESSAGEALIVE_HANDLER_
