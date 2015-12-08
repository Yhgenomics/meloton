/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-03
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

#include "MessageAccept.pb.h"
#include "NodeManager.h"
#include "MasterConfig.h"

static int MessageRegisterHandler( ClusterSession * session , uptr<MessageRegister> msg )
{
    auto ptr = sptr<NodeSession>( ( NodeSession* ) session );
    NodeManager::instance( )->push_node( ptr );

    auto reply = make_uptr( MessageAccept );
    reply->set_session_id( session->id( ) );
    reply->set_alive_duration( MasterConfig::alive_time );

    session->send_message( move_ptr( reply ) );

    return 0;
}

#endif

// !MESSAGEREGISTER_HANDLER_
