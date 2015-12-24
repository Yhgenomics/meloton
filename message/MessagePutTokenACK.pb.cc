// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MessagePutTokenACK.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "MessagePutTokenACK.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {

const ::google::protobuf::Descriptor* MessagePutTokenACK_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  MessagePutTokenACK_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_MessagePutTokenACK_2eproto() {
  protobuf_AddDesc_MessagePutTokenACK_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "MessagePutTokenACK.proto");
  GOOGLE_CHECK(file != NULL);
  MessagePutTokenACK_descriptor_ = file->message_type(0);
  static const int MessagePutTokenACK_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MessagePutTokenACK, token_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MessagePutTokenACK, expire_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MessagePutTokenACK, block_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MessagePutTokenACK, client_id_),
  };
  MessagePutTokenACK_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      MessagePutTokenACK_descriptor_,
      MessagePutTokenACK::default_instance_,
      MessagePutTokenACK_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MessagePutTokenACK, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MessagePutTokenACK, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(MessagePutTokenACK));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_MessagePutTokenACK_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    MessagePutTokenACK_descriptor_, &MessagePutTokenACK::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_MessagePutTokenACK_2eproto() {
  delete MessagePutTokenACK::default_instance_;
  delete MessagePutTokenACK_reflection_;
}

void protobuf_AddDesc_MessagePutTokenACK_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\030MessagePutTokenACK.proto\"X\n\022MessagePut"
    "TokenACK\022\r\n\005token\030\001 \002(\t\022\016\n\006expire\030\002 \002(\003\022"
    "\020\n\010block_id\030\003 \002(\003\022\021\n\tclient_id\030\004 \002(\003", 116);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "MessagePutTokenACK.proto", &protobuf_RegisterTypes);
  MessagePutTokenACK::default_instance_ = new MessagePutTokenACK();
  MessagePutTokenACK::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_MessagePutTokenACK_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_MessagePutTokenACK_2eproto {
  StaticDescriptorInitializer_MessagePutTokenACK_2eproto() {
    protobuf_AddDesc_MessagePutTokenACK_2eproto();
  }
} static_descriptor_initializer_MessagePutTokenACK_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int MessagePutTokenACK::kTokenFieldNumber;
const int MessagePutTokenACK::kExpireFieldNumber;
const int MessagePutTokenACK::kBlockIdFieldNumber;
const int MessagePutTokenACK::kClientIdFieldNumber;
#endif  // !_MSC_VER

MessagePutTokenACK::MessagePutTokenACK()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:MessagePutTokenACK)
}

void MessagePutTokenACK::InitAsDefaultInstance() {
}

MessagePutTokenACK::MessagePutTokenACK(const MessagePutTokenACK& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:MessagePutTokenACK)
}

void MessagePutTokenACK::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  token_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  expire_ = GOOGLE_LONGLONG(0);
  block_id_ = GOOGLE_LONGLONG(0);
  client_id_ = GOOGLE_LONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

MessagePutTokenACK::~MessagePutTokenACK() {
  // @@protoc_insertion_point(destructor:MessagePutTokenACK)
  SharedDtor();
}

void MessagePutTokenACK::SharedDtor() {
  if (token_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete token_;
  }
  if (this != default_instance_) {
  }
}

void MessagePutTokenACK::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* MessagePutTokenACK::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return MessagePutTokenACK_descriptor_;
}

const MessagePutTokenACK& MessagePutTokenACK::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_MessagePutTokenACK_2eproto();
  return *default_instance_;
}

MessagePutTokenACK* MessagePutTokenACK::default_instance_ = NULL;

MessagePutTokenACK* MessagePutTokenACK::New() const {
  return new MessagePutTokenACK;
}

void MessagePutTokenACK::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<MessagePutTokenACK*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 15) {
    ZR_(expire_, client_id_);
    if (has_token()) {
      if (token_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        token_->clear();
      }
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool MessagePutTokenACK::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:MessagePutTokenACK)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string token = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_token()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->token().data(), this->token().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "token");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_expire;
        break;
      }

      // required int64 expire = 2;
      case 2: {
        if (tag == 16) {
         parse_expire:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &expire_)));
          set_has_expire();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_block_id;
        break;
      }

      // required int64 block_id = 3;
      case 3: {
        if (tag == 24) {
         parse_block_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &block_id_)));
          set_has_block_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32)) goto parse_client_id;
        break;
      }

      // required int64 client_id = 4;
      case 4: {
        if (tag == 32) {
         parse_client_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &client_id_)));
          set_has_client_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:MessagePutTokenACK)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:MessagePutTokenACK)
  return false;
#undef DO_
}

void MessagePutTokenACK::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:MessagePutTokenACK)
  // required string token = 1;
  if (has_token()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->token().data(), this->token().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "token");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->token(), output);
  }

  // required int64 expire = 2;
  if (has_expire()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(2, this->expire(), output);
  }

  // required int64 block_id = 3;
  if (has_block_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(3, this->block_id(), output);
  }

  // required int64 client_id = 4;
  if (has_client_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(4, this->client_id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:MessagePutTokenACK)
}

::google::protobuf::uint8* MessagePutTokenACK::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:MessagePutTokenACK)
  // required string token = 1;
  if (has_token()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->token().data(), this->token().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "token");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->token(), target);
  }

  // required int64 expire = 2;
  if (has_expire()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(2, this->expire(), target);
  }

  // required int64 block_id = 3;
  if (has_block_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(3, this->block_id(), target);
  }

  // required int64 client_id = 4;
  if (has_client_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(4, this->client_id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:MessagePutTokenACK)
  return target;
}

int MessagePutTokenACK::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string token = 1;
    if (has_token()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->token());
    }

    // required int64 expire = 2;
    if (has_expire()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->expire());
    }

    // required int64 block_id = 3;
    if (has_block_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->block_id());
    }

    // required int64 client_id = 4;
    if (has_client_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->client_id());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void MessagePutTokenACK::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const MessagePutTokenACK* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const MessagePutTokenACK*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void MessagePutTokenACK::MergeFrom(const MessagePutTokenACK& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_token()) {
      set_token(from.token());
    }
    if (from.has_expire()) {
      set_expire(from.expire());
    }
    if (from.has_block_id()) {
      set_block_id(from.block_id());
    }
    if (from.has_client_id()) {
      set_client_id(from.client_id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void MessagePutTokenACK::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MessagePutTokenACK::CopyFrom(const MessagePutTokenACK& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MessagePutTokenACK::IsInitialized() const {
  if ((_has_bits_[0] & 0x0000000f) != 0x0000000f) return false;

  return true;
}

void MessagePutTokenACK::Swap(MessagePutTokenACK* other) {
  if (other != this) {
    std::swap(token_, other->token_);
    std::swap(expire_, other->expire_);
    std::swap(block_id_, other->block_id_);
    std::swap(client_id_, other->client_id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata MessagePutTokenACK::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = MessagePutTokenACK_descriptor_;
  metadata.reflection = MessagePutTokenACK_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
