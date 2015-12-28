/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-24
* Description: handler for MessageAlive
* * * * * * * * * * * * * * * */

#ifndef MESSAGEALIVE_HANDLER_
#define MESSAGEALIVE_HANDLER_

#include <string>
#include <memory>

#include <MRT.h>
#include <ClusterSession.h>
#include <google/protobuf/message.h>
#include <MessageAlive.pb.h>

#include "NodeSession.h"

static int MessageAliveHandler( ClusterSession * session , uptr<MessageAlive> msg )
{
    auto instance = scast<NodeSession*>( session );
    
    instance->block_num( msg->block_num( ) );
    instance->disk_space( msg->disk_space( ) );
    instance->token_num( msg->token_num( ) );

    instance->update_alive( );

    return 0;
}

#endif

// !MESSAGEALIVE_HANDLER_
