using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace melotoncsharp
{
    public class Meloton
    {
        Action<int, string> GetProgressCB;

        string serverAddress = "";
        int port = 0;


        public Meloton(string ip, int port)
        {
            this.serverAddress = ip;
            this.port = port;
        }

        public void GetProgressCallback(Action<int, string> callback)
        {
            GetProgressCB = callback;
        }


        public int GetFile(string remotePath, Stream stream)
        {
            try
            {
                Protocol p = new Protocol();
                p.Connect(this.serverAddress, this.port);
                Message.MessageRequestGet req = new Message.MessageRequestGet();
                req.Path = remotePath;
                req.RequestId = Guid.NewGuid().ToString().Replace("-", "");

                p.Send<Message.MessageRequestGet>(Message.MessageRequestGet.SerializeToBytes(req));
                var msg = p.Receive();

                long offset = 0;

                float progress = 0;

                if (msg is Message.MessageToken)
                {
                    var tokens = msg as Message.MessageToken;

                    int count = tokens.Address.Count;

                    for (int i = 0; i < tokens.Address.Count; i++)
                    {
                        stream.Position = tokens.Offset[i];

                        Protocol srv = new Protocol();
                        srv.Connect(tokens.Address[i], port);

                        long size_left = tokens.Size[i];
                        long pos = 0;
                        long package_size = 1024 * 1024;

                        while (size_left > 0)
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
                                stream.Write(reply.Data, 0, (int)reply.Size);
                            }

                            pos += reply.Size;
                            offset += reply.Size;
                            size_left -= reply.Size;
                        }

                        srv.Close();

                        progress = (float)(1+i) / (float)tokens.Address.Count;

                        if( this.GetProgressCB!=null)
                        {
                            this.GetProgressCB((int)(progress * 100.0f), null);
                        }

                    }
                }
                else if (msg is Message.MessageActionError)
                {
                    Message.MessageActionError err = msg as Message.MessageActionError;
                    if (this.GetProgressCB != null)
                    {
                        this.GetProgressCB(100, err.Message);
                    }
                    return 1;
                }
            }
            catch(Exception  eee)
            {
                if (this.GetProgressCB != null)
                {
                    this.GetProgressCB(100, eee.Message);
                }
            }

            return 0;
        }
    }
}
