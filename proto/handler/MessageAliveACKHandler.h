/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-08
* Description: handler for MessageAliveACK
* * * * * * * * * * * * * * * */

#ifndef MESSAGEALIVEACK_HANDLER_
#define MESSAGEALIVEACK_HANDLER_

#include <string>
#include <memory>

#include <MRT.h>
#include <ClusterSession.h>
#include <google/protobuf/message.h>
#include <MessageAliveACK.pb.h>

static int MessageAliveACKHandler( ClusterSession * session , uptr<MessageAliveACK> msg )
{
    return 0;
}

#endif

// !MESSAGEALIVEACK_HANDLER_
