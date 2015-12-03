using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace meloton_handler_generator
{
    class MessageUtilsCreater
    {
        string output_root;
        public MessageUtilsCreater(string output)
        {

            output_root = output;
        }

        string hash_message(string name)
        {
            UInt64 ret = 0;
            for (int i = 0; i < name.Length; i++)
            {
                byte b = (byte)name[i];
                UInt64 v = (((UInt64)b << ((i % (byte)8) * (byte)8)) | (byte)i);
                ret |= (UInt64)(v);
            }

            return ret.ToString("X16");
        }
        public void create(List<string> messageNames)
        {
            StringBuilder sb = new StringBuilder();
            sb.Append(@"/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : " + DateTime.Now.ToString("yyyy-MM-dd") + @"
* Description: map messages to id
* * * * * * * * * * * * * * * */

#ifndef MESSAGE_UTILS_H_
#define MESSAGE_UTILS_H_

#include <string>
#include <memory>

#include <MRT.h>
#include <ClusterSession.h>
#include <google/protobuf/message.h>
");
            sb.AppendLine("");
            foreach (var item in messageNames)
            {
                sb.AppendLine("#include \"" + item + ".pb.h\"");
            }

            sb.AppendLine("");

            foreach (var item in messageNames)
            {
                sb.AppendLine("#include \"" + item + "Handler.h\"");
            }

            sb.Append(@"
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
");
            sb.AppendLine("");
            sb.AppendLine(Symbol.space4 + @"static uptr<MRT::Buffer> build(::google::protobuf::Message * message)");
            sb.AppendLine(Symbol.space4 + "{");
            sb.AppendLine(Symbol.space8 + @"size_t message_id = hash_name( message->GetTypeName( ) );");
            sb.AppendLine(Symbol.space8 + @"std::string body = message->SerializeAsString( );");
            sb.AppendLine(Symbol.space8 + @"MRT::Buffer buffer(body.size( ) + sizeof( size_t ));");
            sb.AppendLine(Symbol.space8 + @"char* pbuf = buffer.data( );");
            sb.AppendLine(Symbol.space8 + @"*((size_t*)pbuf) = message_id;");
            sb.AppendLine(Symbol.space8 + @"pbuf += sizeof( size_t );");
            sb.AppendLine(Symbol.space8 + @"memcpy(pbuf , body.c_str( ) , body.size( ) );");
            sb.AppendLine(Symbol.space8 + @"return make_uptr( MRT::Buffer , buffer );");
            //method
            sb.AppendLine(Symbol.space4 + @"}");

            sb.AppendLine("");

            sb.AppendLine(Symbol.space4 + @"static int handle( ClusterSession * session , const void* pdata , size_t len )");
            sb.AppendLine(Symbol.space4 + "{");
            sb.AppendLine(Symbol.space8 + @"size_t message_id = 0;");
            sb.AppendLine(Symbol.space8 + @"char* data = ( char* )pdata;");
            sb.AppendLine(Symbol.space8 + @"message_id = *( (size_t*) data );");
            sb.AppendLine(Symbol.space8 + @"data += sizeof( size_t );");
            sb.AppendLine(Symbol.space8 + @"int msg_len = scast<int>( len - sizeof( size_t ) );");
            sb.AppendLine(Symbol.space8 + @"switch( message_id )");
            sb.AppendLine(Symbol.space8 + @"{");

            foreach (var item in messageNames)
            {
                sb.AppendLine(Symbol.space12 + @"case 0x" + hash_message(item) + " : ");
                sb.AppendLine(Symbol.space12 + @"{");
                sb.AppendLine(Symbol.space16 + @"auto msg = new " + item + "( );");
                sb.AppendLine(Symbol.space16 + @"msg->ParseFromArray( data, msg_len );");
                sb.AppendLine(Symbol.space16 + "return " + item + @"Handler( session , move_ptr( std::unique_ptr<" + item + ">( msg ) ) );");
                //sb.AppendLine(Symbol.space16 + @"return std::unique_ptr<" + item + ">( msg );");
                sb.AppendLine(Symbol.space12 + "}break;");
            }

            sb.AppendLine(Symbol.space12 + @"default: return -1;");

            sb.AppendLine(Symbol.space8 + @"}");

            //method
            sb.AppendLine(Symbol.space4 + @"}");

            //class
            sb.Append(@"};

#endif

// !MESSAGE_UTILS_H_");

            System.IO.File.WriteAllText(output_root + "handler/MessageUtils.h", sb.ToString());
        }
    }
}
