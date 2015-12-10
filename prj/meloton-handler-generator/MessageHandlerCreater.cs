using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace meloton_handler_generator
{
    class MessageHandlerCreater
    {
        string output_root;
        public MessageHandlerCreater(string output)
        {
            output_root = output;
        }

        public void create(List<string> protos)
        {
            foreach (var item in protos)
            {
                createHandler(item);
            }
        }

        private void createHandler(string proto)
        {
            StringBuilder sb = new StringBuilder();
            sb.Append(@"/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : " + DateTime.Now.ToString("yyyy-MM-dd") + @"
* Description: handler for "+proto+ @"
* * * * * * * * * * * * * * * */

#ifndef " + proto.ToUpper() + @"_HANDLER_
#define " + proto.ToUpper() + @"_HANDLER_

#include <string>
#include <memory>

#include <MRT.h>
#include <ClusterSession.h>
#include <google/protobuf/message.h>");
            sb.AppendLine();
            sb.AppendLine(@"#include <"+proto+".pb.h>");
            sb.AppendLine();
            sb.AppendLine(@"static int "+proto+ "Handler( ClusterSession * session , uptr<" + proto +"> msg )");
            sb.AppendLine("{");


            sb.AppendLine(Symbol.space4 + "return 0;");
            sb.AppendLine("}"); // method xxxHandler

            sb.AppendLine("");
            sb.AppendLine("#endif");
            sb.AppendLine("");
            sb.AppendLine("// !"+ proto.ToUpper() + @"_HANDLER_");

            System.IO.File.WriteAllText(this.output_root + "handler/" + proto + "Handler.h", sb.ToString());
        }
    }
}
