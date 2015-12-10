/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-08
* Description: handler for MessageQueryFileResult
* * * * * * * * * * * * * * * */

#ifndef MESSAGEQUERYFILERESULT_HANDLER_
#define MESSAGEQUERYFILERESULT_HANDLER_

#include <string>
#include <memory>

#include <MRT.h>
#include <ClusterSession.h>
#include <google/protobuf/message.h>
#include <MessageQueryFileResult.pb.h>

static int MessageQueryFileResultHandler( ClusterSession * session , uptr<MessageQueryFileResult> msg )
{
    return 0;
}

#endif

// !MESSAGEQUERYFILERESULT_HANDLER_
