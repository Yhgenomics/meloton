/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2016-01-21
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
#include "MessageActionError.pb.h"
#include "MessageAlive.pb.h"
#include "MessageBlockData.pb.h"
#include "MessageGet.pb.h"
#include "MessagePut.pb.h"
#include "MessagePutAccept.pb.h"
#include "MessageRegister.pb.h"
#include "MessageRequestGet.pb.h"
#include "MessageRequestGetToken.pb.h"
#include "MessageRequestPut.pb.h"
#include "MessageRequestPutToken.pb.h"
#include "MessageSyncBlock.pb.h"
#include "MessageToken.pb.h"
#include "MessageTokenACK.pb.h"
#include "MessageUpdateBlock.pb.h"

#include "MessageAcceptHandler.h"
#include "MessageActionErrorHandler.h"
#include "MessageAliveHandler.h"
#include "MessageBlockDataHandler.h"
#include "MessageGetHandler.h"
#include "MessagePutHandler.h"
#include "MessagePutAcceptHandler.h"
#include "MessageRegisterHandler.h"
#include "MessageRequestGetHandler.h"
#include "MessageRequestGetTokenHandler.h"
#include "MessageRequestPutHandler.h"
#include "MessageRequestPutTokenHandler.h"
#include "MessageSyncBlockHandler.h"
#include "MessageTokenHandler.h"
#include "MessageTokenACKHandler.h"
#include "MessageUpdateBlockHandler.h"

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
            case 0x7377676F7F7B777F : 
            {
                auto msg = new MessageActionError( );
                msg->ParseFromArray( data, msg_len );
                return MessageActionErrorHandler( session , move_ptr( std::unique_ptr<MessageActionError>( msg ) ) );
            }break;
            case 0x4165676177776D6F : 
            {
                auto msg = new MessageAlive( );
                msg->ParseFromArray( data, msg_len );
                return MessageAliveHandler( session , move_ptr( std::unique_ptr<MessageAlive>( msg ) ) );
            }break;
            case 0x637567657B736F6F : 
            {
                auto msg = new MessageBlockData( );
                msg->ParseFromArray( data, msg_len );
                return MessageBlockDataHandler( session , move_ptr( std::unique_ptr<MessageBlockData>( msg ) ) );
            }break;
            case 0x476567617373756F : 
            {
                auto msg = new MessageGet( );
                msg->ParseFromArray( data, msg_len );
                return MessageGetHandler( session , move_ptr( std::unique_ptr<MessageGet>( msg ) ) );
            }break;
            case 0x506567617373757F : 
            {
                auto msg = new MessagePut( );
                msg->ParseFromArray( data, msg_len );
                return MessagePutHandler( session , move_ptr( std::unique_ptr<MessagePut>( msg ) ) );
            }break;
            case 0x747567637373757F : 
            {
                auto msg = new MessagePutAccept( );
                msg->ParseFromArray( data, msg_len );
                return MessagePutAcceptHandler( session , move_ptr( std::unique_ptr<MessagePutAccept>( msg ) ) );
            }break;
            case 0x52776775737B676F : 
            {
                auto msg = new MessageRegister( );
                msg->ParseFromArray( data, msg_len );
                return MessageRegisterHandler( session , move_ptr( std::unique_ptr<MessageRegister>( msg ) ) );
            }break;
            case 0x776777737777757F : 
            {
                auto msg = new MessageRequestGet( );
                msg->ParseFromArray( data, msg_len );
                return MessageRequestGetHandler( session , move_ptr( std::unique_ptr<MessageRequestGet>( msg ) ) );
            }break;
            case 0x77677F777F7F757F : 
            {
                auto msg = new MessageRequestGetToken( );
                msg->ParseFromArray( data, msg_len );
                return MessageRequestGetTokenHandler( session , move_ptr( std::unique_ptr<MessageRequestGetToken>( msg ) ) );
            }break;
            case 0x777577737777757F : 
            {
                auto msg = new MessageRequestPut( );
                msg->ParseFromArray( data, msg_len );
                return MessageRequestPutHandler( session , move_ptr( std::unique_ptr<MessageRequestPut>( msg ) ) );
            }break;
            case 0x77757F777F7F757F : 
            {
                auto msg = new MessageRequestPutToken( );
                msg->ParseFromArray( data, msg_len );
                return MessageRequestPutTokenHandler( session , move_ptr( std::unique_ptr<MessageRequestPutToken>( msg ) ) );
            }break;
            case 0x7B676F6D73736F7F : 
            {
                auto msg = new MessageSyncBlock( );
                msg->ParseFromArray( data, msg_len );
                return MessageSyncBlockHandler( session , move_ptr( std::unique_ptr<MessageSyncBlock>( msg ) ) );
            }break;
            case 0x546567617F776F6F : 
            {
                auto msg = new MessageToken( );
                msg->ParseFromArray( data, msg_len );
                return MessageTokenHandler( session , move_ptr( std::unique_ptr<MessageToken>( msg ) ) );
            }break;
            case 0x546F67617F776F6F : 
            {
                auto msg = new MessageTokenACK( );
                msg->ParseFromArray( data, msg_len );
                return MessageTokenACKHandler( session , move_ptr( std::unique_ptr<MessageTokenACK>( msg ) ) );
            }break;
            case 0x7F6D676577736F7F : 
            {
                auto msg = new MessageUpdateBlock( );
                msg->ParseFromArray( data, msg_len );
                return MessageUpdateBlockHandler( session , move_ptr( std::unique_ptr<MessageUpdateBlock>( msg ) ) );
            }break;
            default: return -1;
        }
    }
};

#endif

// !MESSAGE_UTILS_H_