/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-28
* Description: handler for MessageRequestGet
* * * * * * * * * * * * * * * */

#ifndef MESSAGEREQUESTGET_HANDLER_
#define MESSAGEREQUESTGET_HANDLER_

#include <string>
#include <memory>

#include <MRT.h>
#include <ClusterSession.h>
#include <google/protobuf/message.h>
#include <MessageRequestGet.pb.h>

#include "FS.h"
#include "ErrDef.h"
#include <MessageActionError.pb.h>

#include <ClientManager.h>
#include "BlockDistributer.h"

static int MessageRequestGetHandler( ClusterSession * session , uptr<MessageRequestGet> msg )
{
    auto client = ClientManager::instance( )->find_session( session->id( ) );

    if ( client == nullptr )
    {
        return -1;
    }

    auto path = msg->path( );
    auto uuid = msg->request_id( );
    auto file = FS::instance( )->get_file( path );

    if ( file == nullptr )
    {
        uptr<MessageActionError> result = make_uptr( MessageActionError );
        result->set_action_id( uuid );
        result->set_code( ERR_FILE_NOT_EXIST );
        result->set_message( ERR_FILE_NOT_EXIST_STR );
        session->send_message( move_ptr( result ) );
        session->close( );
        return 0;
    }

    BlockDistributer distributer;
    auto result = distributer.get_file( file , client , move_ptr( msg ) );

    if ( !result )
    {
        uptr<MessageActionError> result = make_uptr( MessageActionError );
        result->set_action_id( uuid );
        result->set_code( ERR_NO_NODE );
        result->set_message( ERR_NO_NODE_STR );
        session->send_message( move_ptr( result ) );
        session->close( );
    }

    return 0;
}

#endif

// !MESSAGEREQUESTGET_HANDLER_
