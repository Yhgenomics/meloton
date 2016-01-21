// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MessagePutAccept.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "MessagePutAccept.pb.h"

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

const ::google::protobuf::Descriptor* MessagePutAccept_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  MessagePutAccept_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_MessagePutAccept_2eproto() {
  protobuf_AddDesc_MessagePutAccept_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "MessagePutAccept.proto");
  GOOGLE_CHECK(file != NULL);
  MessagePutAccept_descriptor_ = file->message_type(0);
  static const int MessagePutAccept_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MessagePutAccept, offset_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MessagePutAccept, size_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MessagePutAccept, token_),
  };
  MessagePutAccept_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      MessagePutAccept_descriptor_,
      MessagePutAccept::default_instance_,
      MessagePutAccept_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MessagePutAccept, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MessagePutAccept, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(MessagePutAccept));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_MessagePutAccept_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    MessagePutAccept_descriptor_, &MessagePutAccept::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_MessagePutAccept_2eproto() {
  delete MessagePutAccept::default_instance_;
  delete MessagePutAccept_reflection_;
}

void protobuf_AddDesc_MessagePutAccept_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\026MessagePutAccept.proto\"\?\n\020MessagePutAc"
    "cept\022\016\n\006offset\030\001 \002(\003\022\014\n\004size\030\002 \002(\003\022\r\n\005to"
    "ken\030\003 \002(\t", 89);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "MessagePutAccept.proto", &protobuf_RegisterTypes);
  MessagePutAccept::default_instance_ = new MessagePutAccept();
  MessagePutAccept::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_MessagePutAccept_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_MessagePutAccept_2eproto {
  StaticDescriptorInitializer_MessagePutAccept_2eproto() {
    protobuf_AddDesc_MessagePutAccept_2eproto();
  }
} static_descriptor_initializer_MessagePutAccept_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int MessagePutAccept::kOffsetFieldNumber;
const int MessagePutAccept::kSizeFieldNumber;
const int MessagePutAccept::kTokenFieldNumber;
#endif  // !_MSC_VER

MessagePutAccept::MessagePutAccept()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:MessagePutAccept)
}

void MessagePutAccept::InitAsDefaultInstance() {
}

MessagePutAccept::MessagePutAccept(const MessagePutAccept& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:MessagePutAccept)
}

void MessagePutAccept::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  offset_ = GOOGLE_LONGLONG(0);
  size_ = GOOGLE_LONGLONG(0);
  token_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

MessagePutAccept::~MessagePutAccept() {
  // @@protoc_insertion_point(destructor:MessagePutAccept)
  SharedDtor();
}

void MessagePutAccept::SharedDtor() {
  if (token_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete token_;
  }
  if (this != default_instance_) {
  }
}

void MessagePutAccept::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* MessagePutAccept::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return MessagePutAccept_descriptor_;
}

const MessagePutAccept& MessagePutAccept::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_MessagePutAccept_2eproto();
  return *default_instance_;
}

MessagePutAccept* MessagePutAccept::default_instance_ = NULL;

MessagePutAccept* MessagePutAccept::New() const {
  return new MessagePutAccept;
}

void MessagePutAccept::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<MessagePutAccept*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 7) {
    ZR_(offset_, size_);
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

bool MessagePutAccept::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:MessagePutAccept)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int64 offset = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &offset_)));
          set_has_offset();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_size;
        break;
      }

      // required int64 size = 2;
      case 2: {
        if (tag == 16) {
         parse_size:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &size_)));
          set_has_size();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_token;
        break;
      }

      // required string token = 3;
      case 3: {
        if (tag == 26) {
         parse_token:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_token()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->token().data(), this->token().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "token");
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
  // @@protoc_insertion_point(parse_success:MessagePutAccept)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:MessagePutAccept)
  return false;
#undef DO_
}

void MessagePutAccept::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:MessagePutAccept)
  // required int64 offset = 1;
  if (has_offset()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(1, this->offset(), output);
  }

  // required int64 size = 2;
  if (has_size()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(2, this->size(), output);
  }

  // required string token = 3;
  if (has_token()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->token().data(), this->token().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "token");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->token(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:MessagePutAccept)
}

::google::protobuf::uint8* MessagePutAccept::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:MessagePutAccept)
  // required int64 offset = 1;
  if (has_offset()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(1, this->offset(), target);
  }

  // required int64 size = 2;
  if (has_size()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(2, this->size(), target);
  }

  // required string token = 3;
  if (has_token()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->token().data(), this->token().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "token");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->token(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:MessagePutAccept)
  return target;
}

int MessagePutAccept::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required int64 offset = 1;
    if (has_offset()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->offset());
    }

    // required int64 size = 2;
    if (has_size()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->size());
    }

    // required string token = 3;
    if (has_token()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->token());
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

void MessagePutAccept::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const MessagePutAccept* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const MessagePutAccept*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void MessagePutAccept::MergeFrom(const MessagePutAccept& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_offset()) {
      set_offset(from.offset());
    }
    if (from.has_size()) {
      set_size(from.size());
    }
    if (from.has_token()) {
      set_token(from.token());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void MessagePutAccept::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MessagePutAccept::CopyFrom(const MessagePutAccept& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MessagePutAccept::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000007) != 0x00000007) return false;

  return true;
}

void MessagePutAccept::Swap(MessagePutAccept* other) {
  if (other != this) {
    std::swap(offset_, other->offset_);
    std::swap(size_, other->size_);
    std::swap(token_, other->token_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata MessagePutAccept::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = MessagePutAccept_descriptor_;
  metadata.reflection = MessagePutAccept_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
