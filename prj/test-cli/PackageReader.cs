using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace melotoncsharp
{
    class Package
    {
        public long Command;
        public byte[] Data;
    }
    class PackageReader : BinaryReader
    {

        int state = 0;
        int bodyLength = 0;
        int pos = 0;
        long cmd = 0;

        public PackageReader()
            : base( new MemoryStream() )
        {

        }

        public PackageReader(Stream input, Encoding encoding)
            : base( input , encoding )
        {

        }

        public void AddContent(byte[] buffer, int len)
        {
            var p = this.BaseStream.Position;
            this.BaseStream.Position = this.BaseStream.Length;
            this.BaseStream.Write(buffer, 0, len);
            this.BaseStream.Position = p;
        }

        public Package ReadPackage()
        {
            while (true)
            {
                long len = this.BaseStream.Length - this.BaseStream.Position;
                switch (state)
                {
                    case 0:
                        {
                            if( len >= 2 &&
                                this.ReadByte() == 'Y' &&
                                this.ReadByte() == 'H')
                            {
                                this.state = 1;
                                continue;
                            }

                            return null;
                        }
                        break;
                    case 1:
                        {
                            if( len > 4 )
                            {
                                this.bodyLength = this.ReadInt32();
                                this.state = 2;
                                continue;
                            }

                            return null;
                        }
                        break;
                    case 2:
                        {
                            if( len >= this.bodyLength)
                            {
                                Package ret = new Package();
                                ret.Command = this.ReadInt64();
                                ret.Data = this.ReadBytes(this.bodyLength - 8);
                                state = 0;
                                return ret;
                            }

                            return null;
                        }
                        break; 
                    default:
                        return null;
                }
            }

            return null;
        }
    }
}
