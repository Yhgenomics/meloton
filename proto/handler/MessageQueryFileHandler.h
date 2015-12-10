/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-08
* Description: handler for MessageQueryFile
* * * * * * * * * * * * * * * */

#ifndef MESSAGEQUERYFILE_HANDLER_
#define MESSAGEQUERYFILE_HANDLER_

#include <string>
#include <memory>

#include <MRT.h>
#include <ClusterSession.h>
#include <google/protobuf/message.h>
#include <MessageQueryFile.pb.h>

static int MessageQueryFileHandler( ClusterSession * session , uptr<MessageQueryFile> msg )
{
    return 0;
}

#endif

// !MESSAGEQUERYFILE_HANDLER_
