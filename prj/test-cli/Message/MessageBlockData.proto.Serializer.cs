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
    public partial class MessageBlockData
    {
        /// <summary>Helper: create a new instance to deserializing into</summary>
        public static MessageBlockData Deserialize(Stream stream)
        {
            var instance = new MessageBlockData();
            Deserialize(stream, instance);
            return instance;
        }

        /// <summary>Helper: create a new instance to deserializing into</summary>
        public static MessageBlockData DeserializeLengthDelimited(Stream stream)
        {
            var instance = new MessageBlockData();
            DeserializeLengthDelimited(stream, instance);
            return instance;
        }

        /// <summary>Helper: create a new instance to deserializing into</summary>
        public static MessageBlockData DeserializeLength(Stream stream, int length)
        {
            var instance = new MessageBlockData();
            DeserializeLength(stream, length, instance);
            return instance;
        }

        /// <summary>Helper: put the buffer into a MemoryStream and create a new instance to deserializing into</summary>
        public static MessageBlockData Deserialize(byte[] buffer)
        {
            var instance = new MessageBlockData();
            using (var ms = new MemoryStream(buffer))
                Deserialize(ms, instance);
            return instance;
        }

        /// <summary>Helper: put the buffer into a MemoryStream before deserializing</summary>
        public static Message.MessageBlockData Deserialize(byte[] buffer, Message.MessageBlockData instance)
        {
            using (var ms = new MemoryStream(buffer))
                Deserialize(ms, instance);
            return instance;
        }

        /// <summary>Takes the remaining content of the stream and deserialze it into the instance.</summary>
        public static Message.MessageBlockData Deserialize(Stream stream, Message.MessageBlockData instance)
        {
            while (true)
            {
                int keyByte = stream.ReadByte();
                if (keyByte == -1)
                    break;
                // Optimized reading of known fields with field ID < 16
                switch (keyByte)
                {
                    // Field 1 LengthDelimited
                    case 10:
                        instance.Token = global::SilentOrbit.ProtocolBuffers.ProtocolParser.ReadString(stream);
                        continue;
                    // Field 2 Varint
                    case 16:
                        instance.Size = (long)global::SilentOrbit.ProtocolBuffers.ProtocolParser.ReadUInt64(stream);
                        continue;
                    // Field 3 LengthDelimited
                    case 26:
                        instance.Data = global::SilentOrbit.ProtocolBuffers.ProtocolParser.ReadBytes(stream);
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
        public static Message.MessageBlockData DeserializeLengthDelimited(Stream stream, Message.MessageBlockData instance)
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
                    // Field 1 LengthDelimited
                    case 10:
                        instance.Token = global::SilentOrbit.ProtocolBuffers.ProtocolParser.ReadString(stream);
                        continue;
                    // Field 2 Varint
                    case 16:
                        instance.Size = (long)global::SilentOrbit.ProtocolBuffers.ProtocolParser.ReadUInt64(stream);
                        continue;
                    // Field 3 LengthDelimited
                    case 26:
                        instance.Data = global::SilentOrbit.ProtocolBuffers.ProtocolParser.ReadBytes(stream);
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
        public static Message.MessageBlockData DeserializeLength(Stream stream, int length, Message.MessageBlockData instance)
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
                    // Field 1 LengthDelimited
                    case 10:
                        instance.Token = global::SilentOrbit.ProtocolBuffers.ProtocolParser.ReadString(stream);
                        continue;
                    // Field 2 Varint
                    case 16:
                        instance.Size = (long)global::SilentOrbit.ProtocolBuffers.ProtocolParser.ReadUInt64(stream);
                        continue;
                    // Field 3 LengthDelimited
                    case 26:
                        instance.Data = global::SilentOrbit.ProtocolBuffers.ProtocolParser.ReadBytes(stream);
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
        public static void Serialize(Stream stream, MessageBlockData instance)
        {
            var msField = global::SilentOrbit.ProtocolBuffers.ProtocolParser.Stack.Pop();
            if (instance.Token == null)
                throw new global::SilentOrbit.ProtocolBuffers.ProtocolBufferException("Token is required by the proto specification.");
            // Key for field: 1, LengthDelimited
            stream.WriteByte(10);
            global::SilentOrbit.ProtocolBuffers.ProtocolParser.WriteBytes(stream, Encoding.UTF8.GetBytes(instance.Token));
            // Key for field: 2, Varint
            stream.WriteByte(16);
            global::SilentOrbit.ProtocolBuffers.ProtocolParser.WriteUInt64(stream,(ulong)instance.Size);
            if (instance.Data == null)
                throw new global::SilentOrbit.ProtocolBuffers.ProtocolBufferException("Data is required by the proto specification.");
            // Key for field: 3, LengthDelimited
            stream.WriteByte(26);
            global::SilentOrbit.ProtocolBuffers.ProtocolParser.WriteBytes(stream, instance.Data);
            // Key for field: 4, Varint
            stream.WriteByte(32);
            global::SilentOrbit.ProtocolBuffers.ProtocolParser.WriteUInt64(stream,(ulong)instance.Offset);
            global::SilentOrbit.ProtocolBuffers.ProtocolParser.Stack.Push(msField);
        }

        /// <summary>Helper: Serialize into a MemoryStream and return its byte array</summary>
        public static byte[] SerializeToBytes(MessageBlockData instance)
        {
            using (var ms = new MemoryStream())
            {
                Serialize(ms, instance);
                return ms.ToArray();
            }
        }
        /// <summary>Helper: Serialize with a varint length prefix</summary>
        public static void SerializeLengthDelimited(Stream stream, MessageBlockData instance)
        {
            var data = SerializeToBytes(instance);
            global::SilentOrbit.ProtocolBuffers.ProtocolParser.WriteUInt32(stream, (uint)data.Length);
            stream.Write(data, 0, data.Length);
        }
    }

}