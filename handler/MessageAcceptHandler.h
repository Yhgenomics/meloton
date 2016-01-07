/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-24
* Description: handler for MessageAccept
* * * * * * * * * * * * * * * */

#ifndef MESSAGEACCEPT_HANDLER_
#define MESSAGEACCEPT_HANDLER_

#include <string>
#include <memory>

#include <MRT.h>
#include <ClusterSession.h>
#include <google/protobuf/message.h>
#include <MessageAccept.pb.h>

#include <MessageAlive.pb.h>
#include <MasterSession.h>
#include "NodeSession.h"
#include <MRT.h>

static int MessageAcceptHandler( ClusterSession * session , uptr<MessageAccept> msg )
{

    if ( MasterSession::instance( ) == nullptr )
    {
        return -1;
    }

    MasterSession::instance( )->session_id( msg->session_id() ); 
    MasterSession::instance( )->alive( );
    MasterSession::instance( )->sync_all_block( );

    return 0;
}

#endif

// !MESSAGEACCEPT_HANDLER_
