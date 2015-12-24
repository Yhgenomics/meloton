// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MessageRequestPutToken.proto

#ifndef PROTOBUF_MessageRequestPutToken_2eproto__INCLUDED
#define PROTOBUF_MessageRequestPutToken_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_MessageRequestPutToken_2eproto();
void protobuf_AssignDesc_MessageRequestPutToken_2eproto();
void protobuf_ShutdownFile_MessageRequestPutToken_2eproto();

class MessageRequestPutToken;

// ===================================================================

class MessageRequestPutToken : public ::google::protobuf::Message {
 public:
  MessageRequestPutToken();
  virtual ~MessageRequestPutToken();

  MessageRequestPutToken(const MessageRequestPutToken& from);

  inline MessageRequestPutToken& operator=(const MessageRequestPutToken& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const MessageRequestPutToken& default_instance();

  void Swap(MessageRequestPutToken* other);

  // implements Message ----------------------------------------------

  MessageRequestPutToken* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const MessageRequestPutToken& from);
  void MergeFrom(const MessageRequestPutToken& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required int64 status = 1;
  inline bool has_status() const;
  inline void clear_status();
  static const int kStatusFieldNumber = 1;
  inline ::google::protobuf::int64 status() const;
  inline void set_status(::google::protobuf::int64 value);

  // required int64 block_id = 2;
  inline bool has_block_id() const;
  inline void clear_block_id();
  static const int kBlockIdFieldNumber = 2;
  inline ::google::protobuf::int64 block_id() const;
  inline void set_block_id(::google::protobuf::int64 value);

  // required string path = 3;
  inline bool has_path() const;
  inline void clear_path();
  static const int kPathFieldNumber = 3;
  inline const ::std::string& path() const;
  inline void set_path(const ::std::string& value);
  inline void set_path(const char* value);
  inline void set_path(const char* value, size_t size);
  inline ::std::string* mutable_path();
  inline ::std::string* release_path();
  inline void set_allocated_path(::std::string* path);

  // @@protoc_insertion_point(class_scope:MessageRequestPutToken)
 private:
  inline void set_has_status();
  inline void clear_has_status();
  inline void set_has_block_id();
  inline void clear_has_block_id();
  inline void set_has_path();
  inline void clear_has_path();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::int64 status_;
  ::google::protobuf::int64 block_id_;
  ::std::string* path_;
  friend void  protobuf_AddDesc_MessageRequestPutToken_2eproto();
  friend void protobuf_AssignDesc_MessageRequestPutToken_2eproto();
  friend void protobuf_ShutdownFile_MessageRequestPutToken_2eproto();

  void InitAsDefaultInstance();
  static MessageRequestPutToken* default_instance_;
};
// ===================================================================


// ===================================================================

// MessageRequestPutToken

// required int64 status = 1;
inline bool MessageRequestPutToken::has_status() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void MessageRequestPutToken::set_has_status() {
  _has_bits_[0] |= 0x00000001u;
}
inline void MessageRequestPutToken::clear_has_status() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void MessageRequestPutToken::clear_status() {
  status_ = GOOGLE_LONGLONG(0);
  clear_has_status();
}
inline ::google::protobuf::int64 MessageRequestPutToken::status() const {
  // @@protoc_insertion_point(field_get:MessageRequestPutToken.status)
  return status_;
}
inline void MessageRequestPutToken::set_status(::google::protobuf::int64 value) {
  set_has_status();
  status_ = value;
  // @@protoc_insertion_point(field_set:MessageRequestPutToken.status)
}

// required int64 block_id = 2;
inline bool MessageRequestPutToken::has_block_id() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void MessageRequestPutToken::set_has_block_id() {
  _has_bits_[0] |= 0x00000002u;
}
inline void MessageRequestPutToken::clear_has_block_id() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void MessageRequestPutToken::clear_block_id() {
  block_id_ = GOOGLE_LONGLONG(0);
  clear_has_block_id();
}
inline ::google::protobuf::int64 MessageRequestPutToken::block_id() const {
  // @@protoc_insertion_point(field_get:MessageRequestPutToken.block_id)
  return block_id_;
}
inline void MessageRequestPutToken::set_block_id(::google::protobuf::int64 value) {
  set_has_block_id();
  block_id_ = value;
  // @@protoc_insertion_point(field_set:MessageRequestPutToken.block_id)
}

// required string path = 3;
inline bool MessageRequestPutToken::has_path() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void MessageRequestPutToken::set_has_path() {
  _has_bits_[0] |= 0x00000004u;
}
inline void MessageRequestPutToken::clear_has_path() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void MessageRequestPutToken::clear_path() {
  if (path_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    path_->clear();
  }
  clear_has_path();
}
inline const ::std::string& MessageRequestPutToken::path() const {
  // @@protoc_insertion_point(field_get:MessageRequestPutToken.path)
  return *path_;
}
inline void MessageRequestPutToken::set_path(const ::std::string& value) {
  set_has_path();
  if (path_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    path_ = new ::std::string;
  }
  path_->assign(value);
  // @@protoc_insertion_point(field_set:MessageRequestPutToken.path)
}
inline void MessageRequestPutToken::set_path(const char* value) {
  set_has_path();
  if (path_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    path_ = new ::std::string;
  }
  path_->assign(value);
  // @@protoc_insertion_point(field_set_char:MessageRequestPutToken.path)
}
inline void MessageRequestPutToken::set_path(const char* value, size_t size) {
  set_has_path();
  if (path_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    path_ = new ::std::string;
  }
  path_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:MessageRequestPutToken.path)
}
inline ::std::string* MessageRequestPutToken::mutable_path() {
  set_has_path();
  if (path_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    path_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:MessageRequestPutToken.path)
  return path_;
}
inline ::std::string* MessageRequestPutToken::release_path() {
  clear_has_path();
  if (path_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = path_;
    path_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void MessageRequestPutToken::set_allocated_path(::std::string* path) {
  if (path_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete path_;
  }
  if (path) {
    set_has_path();
    path_ = path;
  } else {
    clear_has_path();
    path_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:MessageRequestPutToken.path)
}


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_MessageRequestPutToken_2eproto__INCLUDED
