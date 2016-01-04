/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-31
* Description: handler for MessageUpdateBlock
* * * * * * * * * * * * * * * */

#ifndef MESSAGEUPDATEBLOCK_HANDLER_
#define MESSAGEUPDATEBLOCK_HANDLER_

#include <string>
#include <memory>

#include <MRT.h>
#include <ClusterSession.h>
#include <google/protobuf/message.h>
#include <MessageUpdateBlock.pb.h>

static int MessageUpdateBlockHandler( ClusterSession * session , uptr<MessageUpdateBlock> msg )
{
    return 0;
}

#endif

// !MESSAGEUPDATEBLOCK_HANDLER_
