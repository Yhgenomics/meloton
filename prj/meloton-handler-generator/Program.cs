using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;

namespace meloton_handler_generator
{
    static class Program
    {
        static string proto_root = "";
        static string output_root = "";
        static List<string> proto_files = new List<string>();
        static void Main(string[] args)
        {

            //MessageIDCreater c = new MessageIDCreater(@"D:\Git\meloton\handler");
            //c.create(new List<string>() { "Message1", "Messagea2", "Message3" });

            if (args.Length < 2)
            {
                Console.WriteLine("handler-generator proto_folder output_folder");
                return;
            }

            proto_root = args[0];
            output_root = args[1];

            System.IO.Directory.CreateDirectory(output_root + "/message");
            System.IO.Directory.CreateDirectory(output_root + "/handler");

            var files = System.IO.Directory.GetFiles(proto_root, "*.proto");
            foreach (var f in files)
            {
                proto_files.Add(System.IO.Path.GetFileNameWithoutExtension(f));
            }

            MessageUtilsCreater c = new MessageUtilsCreater(output_root);
            c.create(proto_files);

            MessageHandlerCreater hc = new MessageHandlerCreater(output_root);
            hc.create(proto_files);
        }
    }
}
