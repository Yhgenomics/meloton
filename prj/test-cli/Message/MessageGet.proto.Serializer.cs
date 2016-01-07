﻿// This is the backend code for reading and writing

// Generated by ProtocolBuffer
// - a pure c# code generation implementation of protocol buffers
// Report bugs to: https://silentorbit.com/protobuf/

// DO NOT EDIT
// This file will be overwritten when CodeGenerator is run.
using System;
using System.IO;
using System.Text;
using System.Collections.Generic;

namespace Message
{
    public partial class MessageGet
    {
        /// <summary>Helper: create a new instance to deserializing into</summary>
        public static MessageGet Deserialize(Stream stream)
        {
            var instance = new MessageGet();
            Deserialize(stream, instance);
            return instance;
        }

        /// <summary>Helper: create a new instance to deserializing into</summary>
        public static MessageGet DeserializeLengthDelimited(Stream stream)
        {
            var instance = new MessageGet();
            DeserializeLengthDelimited(stream, instance);
            return instance;
        }

        /// <summary>Helper: create a new instance to deserializing into</summary>
        public static MessageGet DeserializeLength(Stream stream, int length)
        {
            var instance = new MessageGet();
            DeserializeLength(stream, length, instance);
            return instance;
        }

        /// <summary>Helper: put the buffer into a MemoryStream and create a new instance to deserializing into</summary>
        public static MessageGet Deserialize(byte[] buffer)
        {
            var instance = new MessageGet();
            using (var ms = new MemoryStream(buffer))
                Deserialize(ms, instance);
            return instance;
        }

        /// <summary>Helper: put the buffer into a MemoryStream before deserializing</summary>
        public static Message.MessageGet Deserialize(byte[] buffer, Message.MessageGet instance)
        {
            using (var ms = new MemoryStream(buffer))
                Deserialize(ms, instance);
            return instance;
        }

        /// <summary>Takes the remaining content of the stream and deserialze it into the instance.</summary>
        public static Message.MessageGet Deserialize(Stream stream, Message.MessageGet instance)
        {
            while (true)
            {
                int keyByte = stream.ReadByte();
                if (keyByte == -1)
                    break;
                // Optimized reading of known fields with field ID < 16
                switch (keyByte)
                {
                    // Field 1 Varint
                    case 8:
                        instance.Index = (long)global::SilentOrbit.ProtocolBuffers.ProtocolParser.ReadUInt64(stream);
                        continue;
                    // Field 2 LengthDelimited
                    case 18:
                        instance.Token = global::SilentOrbit.ProtocolBuffers.ProtocolParser.ReadString(stream);
                        continue;
                    // Field 3 Varint
                    case 24:
                        instance.Size = (long)global::SilentOrbit.ProtocolBuffers.ProtocolParser.ReadUInt64(stream);
                        continue;
                    // Field 4 Varint
                    case 32:
                        instance.Offset = (long)global::SilentOrbit.ProtocolBuffers.ProtocolParser.ReadUInt64(stream);
                        continue;
                }

                var key = global::SilentOrbit.ProtocolBuffers.ProtocolParser.ReadKey((byte)keyByte, stream);

                // Reading field ID > 16 and unknown field ID/wire type combinations
                switch (key.Field)
                {
                    case 0:
                        throw new global::SilentOrbit.ProtocolBuffers.ProtocolBufferException("Invalid field id: 0, something went wrong in the stream");
                    default:
                        global::SilentOrbit.ProtocolBuffers.ProtocolParser.SkipKey(stream, key);
                        break;
                }
            }

            return instance;
        }

        /// <summary>Read the VarInt length prefix and the given number of bytes from the stream and deserialze it into the instance.</summary>
        public static Message.MessageGet DeserializeLengthDelimited(Stream stream, Message.MessageGet instance)
        {
            long limit = global::SilentOrbit.ProtocolBuffers.ProtocolParser.ReadUInt32(stream);
            limit += stream.Position;
            while (true)
            {
                if (stream.Position >= limit)
                {
                    if (stream.Position == limit)
                        break;
                    else
                        throw new global::SilentOrbit.ProtocolBuffers.ProtocolBufferException("Read past max limit");
                }
                int keyByte = stream.ReadByte();
                if (keyByte == -1)
                    throw new System.IO.EndOfStreamException();
                // Optimized reading of known fields with field ID < 16
                switch (keyByte)
                {
                    // Field 1 Varint
                    case 8:
                        instance.Index = (long)global::SilentOrbit.ProtocolBuffers.ProtocolParser.ReadUInt64(stream);
                        continue;
                    // Field 2 LengthDelimited
                    case 18:
                        instance.Token = global::SilentOrbit.ProtocolBuffers.ProtocolParser.ReadString(stream);
                        continue;
                    // Field 3 Varint
                    case 24:
                        instance.Size = (long)global::SilentOrbit.ProtocolBuffers.ProtocolParser.ReadUInt64(stream);
                        continue;
                    // Field 4 Varint
                    case 32:
                        instance.Offset = (long)global::SilentOrbit.ProtocolBuffers.ProtocolParser.ReadUInt64(stream);
                        continue;
                }

                var key = global::SilentOrbit.ProtocolBuffers.ProtocolParser.ReadKey((byte)keyByte, stream);

                // Reading field ID > 16 and unknown field ID/wire type combinations
                switch (key.Field)
                {
                    case 0:
                        throw new global::SilentOrbit.ProtocolBuffers.ProtocolBufferException("Invalid field id: 0, something went wrong in the stream");
                    default:
                        global::SilentOrbit.ProtocolBuffers.ProtocolParser.SkipKey(stream, key);
                        break;
                }
            }

            return instance;
        }

        /// <summary>Read the given number of bytes from the stream and deserialze it into the instance.</summary>
        public static Message.MessageGet DeserializeLength(Stream stream, int length, Message.MessageGet instance)
        {
            long limit = stream.Position + length;
            while (true)
            {
                if (stream.Position >= limit)
                {
                    if (stream.Position == limit)
                        break;
                    else
                        throw new global::SilentOrbit.ProtocolBuffers.ProtocolBufferException("Read past max limit");
                }
                int keyByte = stream.ReadByte();
                if (keyByte == -1)
                    throw new System.IO.EndOfStreamException();
                // Optimized reading of known fields with field ID < 16
                switch (keyByte)
                {
                    // Field 1 Varint
                    case 8:
                        instance.Index = (long)global::SilentOrbit.ProtocolBuffers.ProtocolParser.ReadUInt64(stream);
                        continue;
                    // Field 2 LengthDelimited
                    case 18:
                        instance.Token = global::SilentOrbit.ProtocolBuffers.ProtocolParser.ReadString(stream);
                        continue;
                    // Field 3 Varint
                    case 24:
                        instance.Size = (long)global::SilentOrbit.ProtocolBuffers.ProtocolParser.ReadUInt64(stream);
                        continue;
                    // Field 4 Varint
                    case 32:
                        instance.Offset = (long)global::SilentOrbit.ProtocolBuffers.ProtocolParser.ReadUInt64(stream);
                        continue;
                }

                var key = global::SilentOrbit.ProtocolBuffers.ProtocolParser.ReadKey((byte)keyByte, stream);

                // Reading field ID > 16 and unknown field ID/wire type combinations
                switch (key.Field)
                {
                    case 0:
                        throw new global::SilentOrbit.ProtocolBuffers.ProtocolBufferException("Invalid field id: 0, something went wrong in the stream");
                    default:
                        global::SilentOrbit.ProtocolBuffers.ProtocolParser.SkipKey(stream, key);
                        break;
                }
            }

            return instance;
        }

        /// <summary>Serialize the instance into the stream</summary>
        public static void Serialize(Stream stream, MessageGet instance)
        {
            var msField = global::SilentOrbit.ProtocolBuffers.ProtocolParser.Stack.Pop();
            // Key for field: 1, Varint
            stream.WriteByte(8);
            global::SilentOrbit.ProtocolBuffers.ProtocolParser.WriteUInt64(stream,(ulong)instance.Index);
            if (instance.Token == null)
                throw new global::SilentOrbit.ProtocolBuffers.ProtocolBufferException("Token is required by the proto specification.");
            // Key for field: 2, LengthDelimited
            stream.WriteByte(18);
            global::SilentOrbit.ProtocolBuffers.ProtocolParser.WriteBytes(stream, Encoding.UTF8.GetBytes(instance.Token));
            // Key for field: 3, Varint
            stream.WriteByte(24);
            global::SilentOrbit.ProtocolBuffers.ProtocolParser.WriteUInt64(stream,(ulong)instance.Size);
            // Key for field: 4, Varint
            stream.WriteByte(32);
            global::SilentOrbit.ProtocolBuffers.ProtocolParser.WriteUInt64(stream,(ulong)instance.Offset);
            global::SilentOrbit.ProtocolBuffers.ProtocolParser.Stack.Push(msField);
        }

        /// <summary>Helper: Serialize into a MemoryStream and return its byte array</summary>
        public static byte[] SerializeToBytes(MessageGet instance)
        {
            using (var ms = new MemoryStream())
            {
                Serialize(ms, instance);
                return ms.ToArray();
            }
        }
        /// <summary>Helper: Serialize with a varint length prefix</summary>
        public static void SerializeLengthDelimited(Stream stream, MessageGet instance)
        {
            var data = SerializeToBytes(instance);
            global::SilentOrbit.ProtocolBuffers.ProtocolParser.WriteUInt32(stream, (uint)data.Length);
            stream.Write(data, 0, data.Length);
        }
    }

}
