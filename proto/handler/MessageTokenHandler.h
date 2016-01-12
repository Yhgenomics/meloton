/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2016-01-07
* Description: handler for MessageToken
* * * * * * * * * * * * * * * */

#ifndef MESSAGETOKEN_HANDLER_
#define MESSAGETOKEN_HANDLER_

#include <string>
#include <memory>

#include <MRT.h>
#include <ClusterSession.h>
#include <google/protobuf/message.h>
#include <MessageToken.pb.h>

static int MessageTokenHandler( ClusterSession * session , uptr<MessageToken> msg )
{
    return 0;
}

#endif

// !MESSAGETOKEN_HANDLER_
