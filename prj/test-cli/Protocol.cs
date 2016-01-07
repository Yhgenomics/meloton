using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace test_cli
{
    class ProtocolBody
    {
        public Int64 Command;
        public byte[] Body;
    }
    class Protocol
    {
        PackageReader reader = new PackageReader();

        int state = 0;
        MemoryStream receiveBuffer = new MemoryStream();
        Socket socket;
        bool isConnected = false;

        Int64 cmd = 0;
        int bodyLength = 0;


        public Protocol()
        {

        }

        public void Close()
        {
            try
            {
                socket.Disconnect(false);
                socket.Close();
                socket = null;
            }
            catch (Exception eee)
            {

            }
        }

        public void Connect(string ip, int port)
        {
            while (true)
            {
                try
                {
                    socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
                    socket.Connect(new IPEndPoint(IPAddress.Parse(ip), port));
                    isConnected = true;
                    return;
                }
                catch (Exception eee)
                {

                }
            }

        }

        public void Send<T>(byte[] buffer)
        {
            try
            {
                string name = typeof(T).Name;
                MemoryStream ms = new MemoryStream();
                BinaryWriter bw = new BinaryWriter(ms);
                bw.Write('Y');
                bw.Write('H');
                bw.Write(buffer.Length + 8);
                bw.Write((long)hash_name(name));
                bw.Write(buffer);
                bw.Flush();
                socket.Send(ms.ToArray());
                bw.Close();
                bw.Dispose();
                ms.Dispose();
            }
            catch
            {

            }
        }

        public object Receive()
        {
            var body = read_package();
            switch (body.Command)
            {
                //MessageError
                case 0x7377676F7F7B777F:
                    {
                        var ins = Message.MessageActionError.Deserialize(body.Data);
                        return ((object)ins);
                    }
                    break;
                //MessageToken
                case 0x546567617F776F6F:
                    {
                        var ins = Message.MessageToken.Deserialize(body.Data);
                        return ((object)ins);
                    }
                    break;
                //MessageBlockData
                case 0x637567657B736F6F:
                    {
                        var ins = Message.MessageBlockData.Deserialize(body.Data);
                        return ((object)ins);
                    }
                    break;
                default:
                    {
                        return null;
                    }
                    break;
            }

            return null;
        }

        static long hash_name(string name)
        {
            long ret = 0;
            for (int i = 0; i < name.Length; i++)
            {
                char b = (char)name[i];
                long v = (((long)b << ((i % (char)8) * (char)8)) | i);
                ret |= (long)(v);
            }
            return ret;
        }

        Package read_package()
        {
            socket.ReceiveTimeout = 100;
            while (true)
            {
                try
                {
                    byte[] buffer = new byte[10240];
                    var reads = socket.Receive(buffer);
                    reader.AddContent(buffer, reads);
                    var p = reader.ReadPackage();
                    if (p != null)
                    {
                        return p;
                    }
                }
                catch
                {

                }
            }
        }

    }
}
