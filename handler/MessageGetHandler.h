/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-24
* Description: handler for MessageGet
* * * * * * * * * * * * * * * */

#ifndef MESSAGEGET_HANDLER_
#define MESSAGEGET_HANDLER_

#include <string>
#include <memory>

#include <MRT.h>
#include <ClusterSession.h>
#include <google/protobuf/message.h>
#include <MessageGet.pb.h>

static int MessageGetHandler( ClusterSession * session , uptr<MessageGet> msg )
{
   
    return 0;
}

#endif

// !MESSAGEGET_HANDLER_
