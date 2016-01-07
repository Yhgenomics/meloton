using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace test_cli
{
    class Program
    {
        static string Method;
        static string LocalPath;
        static string ServerAddress;
        static string RemotePath;

        static int tick = 0;

        static int Main(string[] args)
        {
            tick = Environment.TickCount;

            if (!ReadArgs(args))
            {
                return 1;
            }

            if (Method == "p")
            {
                return PutFile(System.IO.File.Open(LocalPath,FileMode.Open));
            }
            else if (Method == "g")
            {
                return GetFile(System.IO.File.Open(LocalPath, FileMode.Create));
            }

            Console.WriteLine(Environment.TickCount - tick);

            return 0;
            //ProtoBuf.Serializer.DeserializeWithLengthPrefix(null, ProtoBuf.PrefixStyle.None);
        }
        static bool ReadArgs(string[] args)
        {
            if (args.Length < 4)
            {
                Console.WriteLine("usage");
                Console.WriteLine("<g,p> <server ip> <path> <local path>");
                Console.WriteLine("g: get a file from yhfs");
                Console.WriteLine("p: put a file to yhfs");
                Console.WriteLine("server ip: yhfs ip address");
                Console.WriteLine("path: yhfs path");
                Console.WriteLine("local path: the local file path");
                return false;
            }

            Method = args[0];
            ServerAddress = args[1];
            RemotePath = args[2];
            LocalPath = args[3];
             
            if( Method != "g" && Method != "p" )
            {
                Console.WriteLine("g or p can not be found");
                return false;
            }

            return true;
        }

        static int PutFile(FileStream stream )
        {
            if (!System.IO.File.Exists(LocalPath))
            {
                Console.WriteLine("Local File not exists");
                return 1;
            }

            Protocol p = new Protocol();
            p.Connect(ServerAddress, 101);
            Message.MessageRequestPut req = new Message.MessageRequestPut();
            req.Path = RemotePath;
            req.RequestId = Guid.NewGuid().ToString().Replace("-", "");
            req.Size = stream.Length;
            p.Send<Message.MessageRequestPut>(Message.MessageRequestPut.SerializeToBytes(req));
            var msg = p.Receive();

            if (msg is Message.MessageToken)
            {
                var tokens = msg as Message.MessageToken;

                for (int i = 0; i < tokens.Address.Count; i++)
                {
                    Console.WriteLine("Writing Block :" + tokens.BlockId[i]);

                    stream.Position = tokens.Offset[i];

                    Protocol srv = new Protocol();
                    srv.Connect(tokens.Address[i], 101);

                    long total_len = tokens.Size[i];
                    long offset = 0;

                    while (total_len > 0)
                    {
                        const int length = 10240;

                        long send_size = total_len > length ? length : total_len;
                        byte[] readBuffer = new byte[length];
                        var readSize = stream.Read(readBuffer, 0, (int)send_size);

                        total_len -= readSize;

                        Message.MessagePut putmsg = new Message.MessagePut();
                        putmsg.Data = readBuffer;
                        putmsg.Index = tokens.Index[i];
                        putmsg.Offset = offset;
                        putmsg.Size = send_size;
                        putmsg.Token = tokens.Token[i];
                        srv.Send<Message.MessagePut>(Message.MessagePut.SerializeToBytes(putmsg));

                        offset += readSize;
                    }

                    srv.Close();
                }
            }
            else if ( msg is Message.MessageActionError )
            {
                Message.MessageActionError err = msg as Message.MessageActionError;
                Console.WriteLine(string.Format("Error[{0}]:{1}",err.Code , err.Message));
                return 1;
            }

            return 0;
        }

        static int GetFile(FileStream stream)
        {
            Protocol p = new Protocol();
            p.Connect(ServerAddress, 101);
            Message.MessageRequestGet req = new Message.MessageRequestGet();
            req.Path = RemotePath;
            req.RequestId = Guid.NewGuid().ToString().Replace("-", "");

            p.Send<Message.MessageRequestGet>(Message.MessageRequestGet.SerializeToBytes(req));
            var msg = p.Receive();

            long offset = 0;

            if (msg is Message.MessageToken)
            {
                var tokens = msg as Message.MessageToken;

                for (int i = 0; i < tokens.Address.Count; i++)
                { 
                    Console.WriteLine("Reading Block :"+ tokens.BlockId[i]);
                    stream.Position = tokens.Offset[i];

                    Protocol srv = new Protocol();
                    srv.Connect(tokens.Address[i], 101);

                    long size_left = tokens.Size[i];
                    long pos = 0;
                    long package_size = 1024 * 5 * 100;

                    while ( size_left > 0 )
                    {
                        package_size = size_left > package_size ? package_size : size_left;

                        Message.MessageGet msgGet = new Message.MessageGet();
                        msgGet.Index = tokens.Index[i];
                        msgGet.Token = tokens.Token[i];
                        msgGet.Offset = pos;
                        msgGet.Size = package_size;
                        srv.Send<Message.MessageGet>(Message.MessageGet.SerializeToBytes(msgGet));

                        var reply = srv.Receive() as Message.MessageBlockData;
                         
                        if (reply != null)
                        {
                            stream.Position = offset;
                            stream.Write(reply.Data, 0, (int)reply.Size);
                        }

                        offset += reply.Size;
                        size_left -= reply.Size;
                    }

                    srv.Close();
                }
            }
            else if (msg is Message.MessageActionError)
            {
                Message.MessageActionError err = msg as Message.MessageActionError;
                Console.WriteLine(string.Format("Error[{0}]:{1}", err.Code, err.Message));
                return 1;
            }

            return 0;
        }


        static List<long> SplitSize(long fileLength , int blockNum)
        {
            long fileSize = fileLength;
            long perBlockSize = (long)Math.Ceiling( (double)fileSize / (double)(64*1024*1024));
            List<long> ret = new List<long>();

            long index = 0;
            for (int i = 0; i < blockNum - 1; i++)
            {
                var size = fileSize > perBlockSize ? perBlockSize : fileSize;
                ret.Add(size);
                index += size;
                fileSize -= size;
            }

            ret.Add(fileSize);

            return ret;
        }

    }
}
