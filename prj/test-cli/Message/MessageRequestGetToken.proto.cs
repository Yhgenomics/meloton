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
    public partial class MessageRequestGetToken
    {
        public long Index { get; set; }

        public string RequestId { get; set; }

        public long BlockId { get; set; }

        public long ClientId { get; set; }

    }

}
