/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-24
* Description: handler for MessageRequestPutToken
* * * * * * * * * * * * * * * */

#ifndef MESSAGEREQUESTPUTTOKEN_HANDLER_
#define MESSAGEREQUESTPUTTOKEN_HANDLER_

#include <string>
#include <memory>

#include <MRT.h>
#include <ClusterSession.h>
#include <google/protobuf/message.h>
#include <MessageRequestPutToken.pb.h>

static int MessageRequestPutTokenHandler( ClusterSession * session , uptr<MessageRequestPutToken> msg )
{
    return 0;
}

#endif

// !MESSAGEREQUESTPUTTOKEN_HANDLER_
