/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-24
* Description: handler for MessageRegister
* * * * * * * * * * * * * * * */

#ifndef MESSAGEREGISTER_HANDLER_
#define MESSAGEREGISTER_HANDLER_

#include <string>
#include <memory>

#include <MRT.h>
#include <ClusterSession.h>
#include <google/protobuf/message.h>
#include <MessageRegister.pb.h>

#include "NodeSession.h"

static int MessageRegisterHandler( ClusterSession * session , uptr<MessageRegister> msg )
{
    auto instance = scast<NodeSession*>( session );

    if ( instance == nullptr )
    {
        session->close( );
    }

    instance->block_num( msg->block_num( ) );
    instance->disk_space( msg->disk_space( ) );

    auto reply = make_uptr( MessageAccept );
    reply->set_session_id( instance->id( ) );
    
    instance->send_message( move_ptr( reply ) );

    return 0;
}

#endif

// !MESSAGEREGISTER_HANDLER_
