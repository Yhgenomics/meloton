/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-31
* Description: handler for MessageBlockData
* * * * * * * * * * * * * * * */

#ifndef MESSAGEBLOCKDATA_HANDLER_
#define MESSAGEBLOCKDATA_HANDLER_

#include <string>
#include <memory>

#include <MRT.h>
#include <ClusterSession.h>
#include <google/protobuf/message.h>
#include <MessageBlockData.pb.h>

static int MessageBlockDataHandler( ClusterSession * session , uptr<MessageBlockData> msg )
{
    return 0;
}

#endif

// !MESSAGEBLOCKDATA_HANDLER_
