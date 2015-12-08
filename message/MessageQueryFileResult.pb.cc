// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MessageQueryFileResult.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "MessageQueryFileResult.pb.h"

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

const ::google::protobuf::Descriptor* MessageQueryFileResult_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  MessageQueryFileResult_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_MessageQueryFileResult_2eproto() {
  protobuf_AddDesc_MessageQueryFileResult_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "MessageQueryFileResult.proto");
  GOOGLE_CHECK(file != NULL);
  MessageQueryFileResult_descriptor_ = file->message_type(0);
  static const int MessageQueryFileResult_offsets_[5] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MessageQueryFileResult, session_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MessageQueryFileResult, error_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MessageQueryFileResult, file_name_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MessageQueryFileResult, file_part_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MessageQueryFileResult, file_part_size_),
  };
  MessageQueryFileResult_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      MessageQueryFileResult_descriptor_,
      MessageQueryFileResult::default_instance_,
      MessageQueryFileResult_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MessageQueryFileResult, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MessageQueryFileResult, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(MessageQueryFileResult));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_MessageQueryFileResult_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    MessageQueryFileResult_descriptor_, &MessageQueryFileResult::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_MessageQueryFileResult_2eproto() {
  delete MessageQueryFileResult::default_instance_;
  delete MessageQueryFileResult_reflection_;
}

void protobuf_AddDesc_MessageQueryFileResult_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\034MessageQueryFileResult.proto\"|\n\026Messag"
    "eQueryFileResult\022\022\n\nsession_id\030\001 \002(\003\022\r\n\005"
    "error\030\002 \002(\003\022\021\n\tfile_name\030\003 \002(\t\022\024\n\014file_p"
    "art_id\030\004 \003(\003\022\026\n\016file_part_size\030\005 \003(\003", 156);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "MessageQueryFileResult.proto", &protobuf_RegisterTypes);
  MessageQueryFileResult::default_instance_ = new MessageQueryFileResult();
  MessageQueryFileResult::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_MessageQueryFileResult_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_MessageQueryFileResult_2eproto {
  StaticDescriptorInitializer_MessageQueryFileResult_2eproto() {
    protobuf_AddDesc_MessageQueryFileResult_2eproto();
  }
} static_descriptor_initializer_MessageQueryFileResult_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int MessageQueryFileResult::kSessionIdFieldNumber;
const int MessageQueryFileResult::kErrorFieldNumber;
const int MessageQueryFileResult::kFileNameFieldNumber;
const int MessageQueryFileResult::kFilePartIdFieldNumber;
const int MessageQueryFileResult::kFilePartSizeFieldNumber;
#endif  // !_MSC_VER

MessageQueryFileResult::MessageQueryFileResult()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:MessageQueryFileResult)
}

void MessageQueryFileResult::InitAsDefaultInstance() {
}

MessageQueryFileResult::MessageQueryFileResult(const MessageQueryFileResult& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:MessageQueryFileResult)
}

void MessageQueryFileResult::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  session_id_ = GOOGLE_LONGLONG(0);
  error_ = GOOGLE_LONGLONG(0);
  file_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

MessageQueryFileResult::~MessageQueryFileResult() {
  // @@protoc_insertion_point(destructor:MessageQueryFileResult)
  SharedDtor();
}

void MessageQueryFileResult::SharedDtor() {
  if (file_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete file_name_;
  }
  if (this != default_instance_) {
  }
}

void MessageQueryFileResult::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* MessageQueryFileResult::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return MessageQueryFileResult_descriptor_;
}

const MessageQueryFileResult& MessageQueryFileResult::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_MessageQueryFileResult_2eproto();
  return *default_instance_;
}

MessageQueryFileResult* MessageQueryFileResult::default_instance_ = NULL;

MessageQueryFileResult* MessageQueryFileResult::New() const {
  return new MessageQueryFileResult;
}

void MessageQueryFileResult::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<MessageQueryFileResult*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 7) {
    ZR_(session_id_, error_);
    if (has_file_name()) {
      if (file_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        file_name_->clear();
      }
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  file_part_id_.Clear();
  file_part_size_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool MessageQueryFileResult::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:MessageQueryFileResult)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int64 session_id = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &session_id_)));
          set_has_session_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_error;
        break;
      }

      // required int64 error = 2;
      case 2: {
        if (tag == 16) {
         parse_error:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &error_)));
          set_has_error();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_file_name;
        break;
      }

      // required string file_name = 3;
      case 3: {
        if (tag == 26) {
         parse_file_name:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_file_name()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->file_name().data(), this->file_name().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "file_name");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32)) goto parse_file_part_id;
        break;
      }

      // repeated int64 file_part_id = 4;
      case 4: {
        if (tag == 32) {
         parse_file_part_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 1, 32, input, this->mutable_file_part_id())));
        } else if (tag == 34) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitiveNoInline<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, this->mutable_file_part_id())));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32)) goto parse_file_part_id;
        if (input->ExpectTag(40)) goto parse_file_part_size;
        break;
      }

      // repeated int64 file_part_size = 5;
      case 5: {
        if (tag == 40) {
         parse_file_part_size:
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 1, 40, input, this->mutable_file_part_size())));
        } else if (tag == 42) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitiveNoInline<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, this->mutable_file_part_size())));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(40)) goto parse_file_part_size;
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
  // @@protoc_insertion_point(parse_success:MessageQueryFileResult)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:MessageQueryFileResult)
  return false;
#undef DO_
}

void MessageQueryFileResult::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:MessageQueryFileResult)
  // required int64 session_id = 1;
  if (has_session_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(1, this->session_id(), output);
  }

  // required int64 error = 2;
  if (has_error()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(2, this->error(), output);
  }

  // required string file_name = 3;
  if (has_file_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->file_name().data(), this->file_name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "file_name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->file_name(), output);
  }

  // repeated int64 file_part_id = 4;
  for (int i = 0; i < this->file_part_id_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(
      4, this->file_part_id(i), output);
  }

  // repeated int64 file_part_size = 5;
  for (int i = 0; i < this->file_part_size_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(
      5, this->file_part_size(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:MessageQueryFileResult)
}

::google::protobuf::uint8* MessageQueryFileResult::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:MessageQueryFileResult)
  // required int64 session_id = 1;
  if (has_session_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(1, this->session_id(), target);
  }

  // required int64 error = 2;
  if (has_error()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(2, this->error(), target);
  }

  // required string file_name = 3;
  if (has_file_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->file_name().data(), this->file_name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "file_name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->file_name(), target);
  }

  // repeated int64 file_part_id = 4;
  for (int i = 0; i < this->file_part_id_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteInt64ToArray(4, this->file_part_id(i), target);
  }

  // repeated int64 file_part_size = 5;
  for (int i = 0; i < this->file_part_size_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteInt64ToArray(5, this->file_part_size(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:MessageQueryFileResult)
  return target;
}

int MessageQueryFileResult::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required int64 session_id = 1;
    if (has_session_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->session_id());
    }

    // required int64 error = 2;
    if (has_error()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->error());
    }

    // required string file_name = 3;
    if (has_file_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->file_name());
    }

  }
  // repeated int64 file_part_id = 4;
  {
    int data_size = 0;
    for (int i = 0; i < this->file_part_id_size(); i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::
        Int64Size(this->file_part_id(i));
    }
    total_size += 1 * this->file_part_id_size() + data_size;
  }

  // repeated int64 file_part_size = 5;
  {
    int data_size = 0;
    for (int i = 0; i < this->file_part_size_size(); i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::
        Int64Size(this->file_part_size(i));
    }
    total_size += 1 * this->file_part_size_size() + data_size;
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

void MessageQueryFileResult::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const MessageQueryFileResult* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const MessageQueryFileResult*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void MessageQueryFileResult::MergeFrom(const MessageQueryFileResult& from) {
  GOOGLE_CHECK_NE(&from, this);
  file_part_id_.MergeFrom(from.file_part_id_);
  file_part_size_.MergeFrom(from.file_part_size_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_session_id()) {
      set_session_id(from.session_id());
    }
    if (from.has_error()) {
      set_error(from.error());
    }
    if (from.has_file_name()) {
      set_file_name(from.file_name());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void MessageQueryFileResult::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MessageQueryFileResult::CopyFrom(const MessageQueryFileResult& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MessageQueryFileResult::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000007) != 0x00000007) return false;

  return true;
}

void MessageQueryFileResult::Swap(MessageQueryFileResult* other) {
  if (other != this) {
    std::swap(session_id_, other->session_id_);
    std::swap(error_, other->error_);
    std::swap(file_name_, other->file_name_);
    file_part_id_.Swap(&other->file_part_id_);
    file_part_size_.Swap(&other->file_part_size_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata MessageQueryFileResult::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = MessageQueryFileResult_descriptor_;
  metadata.reflection = MessageQueryFileResult_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)