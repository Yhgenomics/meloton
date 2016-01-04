/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-29
* Description: handler for MessageActionError
* * * * * * * * * * * * * * * */

#ifndef MESSAGEACTIONERROR_HANDLER_
#define MESSAGEACTIONERROR_HANDLER_

#include <string>
#include <memory>

#include <MRT.h>
#include <ClusterSession.h>
#include <google/protobuf/message.h>
#include <MessageActionError.pb.h>

static int MessageActionErrorHandler( ClusterSession * session , uptr<MessageActionError> msg )
{
    return 0;
}

#endif

// !MESSAGEACTIONERROR_HANDLER_
