﻿// Classes and structures being serialized

// Generated by ProtocolBuffer
// - a pure c# code generation implementation of protocol buffers
// Report bugs to: https://silentorbit.com/protobuf/

// DO NOT EDIT
// This file will be overwritten when CodeGenerator is run.
// To make custom modifications, edit the .proto file and add //:external before the message line
// then write the code and the changes in a separate file.
using System;
using System.Collections.Generic;

namespace Message
{
    public partial class MessageSyncBlock
    {
        public int Status { get; set; }

        public string Path { get; set; }

        public long Size { get; set; }

        public long Id { get; set; }

        public long Index { get; set; }

    }

}
