/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-03
* Description: map messages to id
* * * * * * * * * * * * * * * */

#ifndef MESSAGE_UTILS_H_
#define MESSAGE_UTILS_H_

#include <string>
#include <memory>

#include <MRT.h>
#include <ClusterSession.h>
#include <google/protobuf/message.h>

#include "MessageAccept.pb.h"
#include "MessageQueryFile.pb.h"
#include "MessageQueryFileResult.pb.h"
#include "MessageRegister.pb.h"

#include "MessageAcceptHandler.h"
#include "MessageQueryFileHandler.h"
#include "MessageQueryFileResultHandler.h"
#include "MessageRegisterHandler.h"

class MessageUtils
{
private:

    static size_t hash_name( std::string & name)
    {
        size_t ret = 0;
        for (int i = 0; i < name.length(); i++)
        {
            char b = (char)name[i];
            size_t v = (((size_t)b << ((i % (char)8) * (char)8)) | i);
            ret |= (size_t)(v);
        }
        return ret;
    }
public:

    static uptr<MRT::Buffer> build(::google::protobuf::Message * message)
    {
        size_t message_id = hash_name( message->GetTypeName( ) );
        std::string body = message->SerializeAsString( );
        MRT::Buffer buffer(body.size( ) + sizeof( size_t ));
        char* pbuf = buffer.data( );
        *((size_t*)pbuf) = message_id;
        pbuf += sizeof( size_t );
        memcpy(pbuf , body.c_str( ) , body.size( ) );
        return make_uptr( MRT::Buffer , buffer );
    }

    static int handle( ClusterSession * session , const void* pdata , size_t len )
    {
        size_t message_id = 0;
        char* data = ( char* )pdata;
        message_id = *( (size_t*) data );
        data += sizeof( size_t );
        int msg_len = scast<int>( len - sizeof( size_t ) );
        switch( message_id )
        {
            case 0x416567757377676F : 
            {
                auto msg = new MessageAccept( );
                msg->ParseFromArray( data, msg_len );
                return MessageAcceptHandler( session , move_ptr( std::unique_ptr<MessageAccept>( msg ) ) );
            }break;
            case 0x756D6F677B73657F : 
            {
                auto msg = new MessageQueryFile( );
                msg->ParseFromArray( data, msg_len );
                return MessageQueryFileHandler( session , move_ptr( std::unique_ptr<MessageQueryFile>( msg ) ) );
            }break;
            case 0x756D7F6F7F73657F : 
            {
                auto msg = new MessageQueryFileResult( );
                msg->ParseFromArray( data, msg_len );
                return MessageQueryFileResultHandler( session , move_ptr( std::unique_ptr<MessageQueryFileResult>( msg ) ) );
            }break;
            case 0x52776775737B676F : 
            {
                auto msg = new MessageRegister( );
                msg->ParseFromArray( data, msg_len );
                return MessageRegisterHandler( session , move_ptr( std::unique_ptr<MessageRegister>( msg ) ) );
            }break;
            default: return -1;
        }
    }
};

#endif

// !MESSAGE_UTILS_H_