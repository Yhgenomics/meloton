/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-28
* Description: handler for MessageRequestPut
* * * * * * * * * * * * * * * */

#ifndef MESSAGEREQUESTPUT_HANDLER_
#define MESSAGEREQUESTPUT_HANDLER_

#include <string>
#include <memory>

#include <MRT.h>
#include <ClusterSession.h>
#include <google/protobuf/message.h>
#include <MessageRequestPut.pb.h>

#include <ClientManager.h>

static int MessageRequestPutHandler( ClusterSession * session , uptr<MessageRequestPut> msg )
{
    auto client = ClientManager::instance( )->find_session( session->id( ) );
    auto size =  msg->size( );
    if ( client == nullptr ) return -1;

    auto path = msg->path( );
    auto uuid = msg->request_id( );
    auto file = FS::instance( )->get_file( path );
    
    if ( file != nullptr )
    {
        uptr<MessageActionError> result = make_uptr( MessageActionError );
        result->set_action_id( uuid );
        result->set_code( ERR_FILE_EXIST );
        result->set_message( ERR_FILE_EXIST_STR );
        session->send_message( move_ptr( result ) );
        session->close( );
        return 0;
    }

    LOG_DEBUG( "Split Block..." );

    BlockDistributer distributer;
    distributer.put_file( size , client , move_ptr( msg ) );
    //distributer.get_file( file , session , move_ptr( msg ) );

    LOG_DEBUG( "Split Finish..." );

    return 0;
}

#endif

// !MESSAGEREQUESTPUT_HANDLER_
