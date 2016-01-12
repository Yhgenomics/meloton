/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2016-01-07
* Description: handler for MessageRequestGetToken
* * * * * * * * * * * * * * * */

#ifndef MESSAGEREQUESTGETTOKEN_HANDLER_
#define MESSAGEREQUESTGETTOKEN_HANDLER_

#include <string>
#include <memory>

#include <MRT.h>
#include <ClusterSession.h>
#include <google/protobuf/message.h>
#include <MessageRequestGetToken.pb.h>

static int MessageRequestGetTokenHandler( ClusterSession * session , uptr<MessageRequestGetToken> msg )
{
    return 0;
}

#endif

// !MESSAGEREQUESTGETTOKEN_HANDLER_
