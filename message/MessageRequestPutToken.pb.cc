// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MessageRequestPutToken.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "MessageRequestPutToken.pb.h"

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

const ::google::protobuf::Descriptor* MessageRequestPutToken_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  MessageRequestPutToken_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_MessageRequestPutToken_2eproto() {
  protobuf_AddDesc_MessageRequestPutToken_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "MessageRequestPutToken.proto");
  GOOGLE_CHECK(file != NULL);
  MessageRequestPutToken_descriptor_ = file->message_type(0);
  static const int MessageRequestPutToken_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MessageRequestPutToken, status_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MessageRequestPutToken, block_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MessageRequestPutToken, path_),
  };
  MessageRequestPutToken_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      MessageRequestPutToken_descriptor_,
      MessageRequestPutToken::default_instance_,
      MessageRequestPutToken_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MessageRequestPutToken, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MessageRequestPutToken, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(MessageRequestPutToken));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_MessageRequestPutToken_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    MessageRequestPutToken_descriptor_, &MessageRequestPutToken::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_MessageRequestPutToken_2eproto() {
  delete MessageRequestPutToken::default_instance_;
  delete MessageRequestPutToken_reflection_;
}

void protobuf_AddDesc_MessageRequestPutToken_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\034MessageRequestPutToken.proto\"H\n\026Messag"
    "eRequestPutToken\022\016\n\006status\030\001 \002(\003\022\020\n\010bloc"
    "k_id\030\002 \002(\003\022\014\n\004path\030\003 \002(\t", 104);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "MessageRequestPutToken.proto", &protobuf_RegisterTypes);
  MessageRequestPutToken::default_instance_ = new MessageRequestPutToken();
  MessageRequestPutToken::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_MessageRequestPutToken_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_MessageRequestPutToken_2eproto {
  StaticDescriptorInitializer_MessageRequestPutToken_2eproto() {
    protobuf_AddDesc_MessageRequestPutToken_2eproto();
  }
} static_descriptor_initializer_MessageRequestPutToken_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int MessageRequestPutToken::kStatusFieldNumber;
const int MessageRequestPutToken::kBlockIdFieldNumber;
const int MessageRequestPutToken::kPathFieldNumber;
#endif  // !_MSC_VER

MessageRequestPutToken::MessageRequestPutToken()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:MessageRequestPutToken)
}

void MessageRequestPutToken::InitAsDefaultInstance() {
}

MessageRequestPutToken::MessageRequestPutToken(const MessageRequestPutToken& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:MessageRequestPutToken)
}

void MessageRequestPutToken::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  status_ = GOOGLE_LONGLONG(0);
  block_id_ = GOOGLE_LONGLONG(0);
  path_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

MessageRequestPutToken::~MessageRequestPutToken() {
  // @@protoc_insertion_point(destructor:MessageRequestPutToken)
  SharedDtor();
}

void MessageRequestPutToken::SharedDtor() {
  if (path_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete path_;
  }
  if (this != default_instance_) {
  }
}

void MessageRequestPutToken::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* MessageRequestPutToken::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return MessageRequestPutToken_descriptor_;
}

const MessageRequestPutToken& MessageRequestPutToken::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_MessageRequestPutToken_2eproto();
  return *default_instance_;
}

MessageRequestPutToken* MessageRequestPutToken::default_instance_ = NULL;

MessageRequestPutToken* MessageRequestPutToken::New() const {
  return new MessageRequestPutToken;
}

void MessageRequestPutToken::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<MessageRequestPutToken*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 7) {
    ZR_(status_, block_id_);
    if (has_path()) {
      if (path_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        path_->clear();
      }
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool MessageRequestPutToken::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:MessageRequestPutToken)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int64 status = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &status_)));
          set_has_status();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_block_id;
        break;
      }

      // required int64 block_id = 2;
      case 2: {
        if (tag == 16) {
         parse_block_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &block_id_)));
          set_has_block_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_path;
        break;
      }

      // required string path = 3;
      case 3: {
        if (tag == 26) {
         parse_path:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_path()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->path().data(), this->path().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "path");
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
  // @@protoc_insertion_point(parse_success:MessageRequestPutToken)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:MessageRequestPutToken)
  return false;
#undef DO_
}

void MessageRequestPutToken::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:MessageRequestPutToken)
  // required int64 status = 1;
  if (has_status()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(1, this->status(), output);
  }

  // required int64 block_id = 2;
  if (has_block_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(2, this->block_id(), output);
  }

  // required string path = 3;
  if (has_path()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->path().data(), this->path().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "path");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->path(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:MessageRequestPutToken)
}

::google::protobuf::uint8* MessageRequestPutToken::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:MessageRequestPutToken)
  // required int64 status = 1;
  if (has_status()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(1, this->status(), target);
  }

  // required int64 block_id = 2;
  if (has_block_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(2, this->block_id(), target);
  }

  // required string path = 3;
  if (has_path()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->path().data(), this->path().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "path");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->path(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:MessageRequestPutToken)
  return target;
}

int MessageRequestPutToken::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required int64 status = 1;
    if (has_status()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->status());
    }

    // required int64 block_id = 2;
    if (has_block_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->block_id());
    }

    // required string path = 3;
    if (has_path()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->path());
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

void MessageRequestPutToken::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const MessageRequestPutToken* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const MessageRequestPutToken*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void MessageRequestPutToken::MergeFrom(const MessageRequestPutToken& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_status()) {
      set_status(from.status());
    }
    if (from.has_block_id()) {
      set_block_id(from.block_id());
    }
    if (from.has_path()) {
      set_path(from.path());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void MessageRequestPutToken::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MessageRequestPutToken::CopyFrom(const MessageRequestPutToken& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MessageRequestPutToken::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000007) != 0x00000007) return false;

  return true;
}

void MessageRequestPutToken::Swap(MessageRequestPutToken* other) {
  if (other != this) {
    std::swap(status_, other->status_);
    std::swap(block_id_, other->block_id_);
    std::swap(path_, other->path_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata MessageRequestPutToken::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = MessageRequestPutToken_descriptor_;
  metadata.reflection = MessageRequestPutToken_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)