using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace meloton_handler_generator
{
    class MessageIDCreater
    {
        string space4 = "    ";
        string output_root;
        public MessageIDCreater(string output)
        {
            output_root = output;
        }

        string hash_message(string name)
        {
            UInt64 ret = 0;
            for (int i = 0; i < name.Length; i++)
            {
                byte b = (byte)name[i];
                UInt64 v = ((UInt64)b << ((i % (byte)8) * (byte)8));
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

");

            foreach (var item in messageNames)
            {
                sb.AppendLine("#include \""+item+ ".h\"");
            }

            sb.Append(@"
class MessageIDFactory
{
public:
");

            foreach (var item in messageNames)
            {
                sb.AppendLine(space4+ "inline static size_t get_id(" + item + " message){ return (size_t)0x"+ hash_message (item) + "; };");
                sb.AppendLine(space4 + "inline static void set_id(" + item + " & message){ item.MessageId(0x" + hash_message(item) + "); };");
            }

            sb.Append(@"}

// !MESSAGE_UTILS_H_");


            System.IO.File.WriteAllText(output_root+"/MessageUtils.h", sb.ToString());
        }
    }
}
