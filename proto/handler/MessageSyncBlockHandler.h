/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2016-01-07
* Description: handler for MessageSyncBlock
* * * * * * * * * * * * * * * */

#ifndef MESSAGESYNCBLOCK_HANDLER_
#define MESSAGESYNCBLOCK_HANDLER_

#include <string>
#include <memory>

#include <MRT.h>
#include <ClusterSession.h>
#include <google/protobuf/message.h>
#include <MessageSyncBlock.pb.h>

static int MessageSyncBlockHandler( ClusterSession * session , uptr<MessageSyncBlock> msg )
{
    return 0;
}

#endif

// !MESSAGESYNCBLOCK_HANDLER_
