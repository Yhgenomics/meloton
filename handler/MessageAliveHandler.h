/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-08
* Description: handler for MessageAlive
* * * * * * * * * * * * * * * */

#ifndef MESSAGEALIVE_HANDLER_
#define MESSAGEALIVE_HANDLER_

#include <string>
#include <memory>
#include <time.h>

#include <MRT.h>
#include <ClusterSession.h>
#include <google/protobuf/message.h>
#include <MessageAlive.pb.h>

#include "MessageAliveACK.pb.h"
#include "NodeManager.h"

static int MessageAliveHandler( ClusterSession * session , uptr<MessageAlive> msg )
{
    auto id = msg->session_id( );
    auto node = NodeManager::instance( )->find_node( [ id ] ( sptr<NodeSession> session )
    {
        return session->id( ) == id;
    } );

    if ( node == nullptr )
    {
        session->close( );
    }
    
    node->update_alive( );

    auto reply = make_uptr( MessageAliveACK );
    reply->set_local_time( msg->local_time( ) );
    reply->set_server_time( time( NULL ) );
    reply->set_session_id( msg->session_id( ) );
    session->send_message( move_ptr( reply ) );

    return 0;
}

#endif

// !MESSAGEALIVE_HANDLER_
