using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace meloton_csharp_test
{
    class Program
    {
        static void Main(string[] args)
        {

            melotoncsharp.Meloton m = new melotoncsharp.Meloton("10.0.0.20", 101);

            m.GetFile("/test/test2", System.IO.File.Open("E:\\testeee", System.IO.FileMode.OpenOrCreate));
        }
    }
}
