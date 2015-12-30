// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MessageRequestPut.proto

#ifndef PROTOBUF_MessageRequestPut_2eproto__INCLUDED
#define PROTOBUF_MessageRequestPut_2eproto__INCLUDED

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
void  protobuf_AddDesc_MessageRequestPut_2eproto();
void protobuf_AssignDesc_MessageRequestPut_2eproto();
void protobuf_ShutdownFile_MessageRequestPut_2eproto();

class MessageRequestPut;

// ===================================================================

class MessageRequestPut : public ::google::protobuf::Message {
 public:
  MessageRequestPut();
  virtual ~MessageRequestPut();

  MessageRequestPut(const MessageRequestPut& from);

  inline MessageRequestPut& operator=(const MessageRequestPut& from) {
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
  static const MessageRequestPut& default_instance();

  void Swap(MessageRequestPut* other);

  // implements Message ----------------------------------------------

  MessageRequestPut* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const MessageRequestPut& from);
  void MergeFrom(const MessageRequestPut& from);
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

  // required string path = 1;
  inline bool has_path() const;
  inline void clear_path();
  static const int kPathFieldNumber = 1;
  inline const ::std::string& path() const;
  inline void set_path(const ::std::string& value);
  inline void set_path(const char* value);
  inline void set_path(const char* value, size_t size);
  inline ::std::string* mutable_path();
  inline ::std::string* release_path();
  inline void set_allocated_path(::std::string* path);

  // required int64 size = 2;
  inline bool has_size() const;
  inline void clear_size();
  static const int kSizeFieldNumber = 2;
  inline ::google::protobuf::int64 size() const;
  inline void set_size(::google::protobuf::int64 value);

  // required string request_id = 3;
  inline bool has_request_id() const;
  inline void clear_request_id();
  static const int kRequestIdFieldNumber = 3;
  inline const ::std::string& request_id() const;
  inline void set_request_id(const ::std::string& value);
  inline void set_request_id(const char* value);
  inline void set_request_id(const char* value, size_t size);
  inline ::std::string* mutable_request_id();
  inline ::std::string* release_request_id();
  inline void set_allocated_request_id(::std::string* request_id);

  // @@protoc_insertion_point(class_scope:MessageRequestPut)
 private:
  inline void set_has_path();
  inline void clear_has_path();
  inline void set_has_size();
  inline void clear_has_size();
  inline void set_has_request_id();
  inline void clear_has_request_id();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::std::string* path_;
  ::google::protobuf::int64 size_;
  ::std::string* request_id_;
  friend void  protobuf_AddDesc_MessageRequestPut_2eproto();
  friend void protobuf_AssignDesc_MessageRequestPut_2eproto();
  friend void protobuf_ShutdownFile_MessageRequestPut_2eproto();

  void InitAsDefaultInstance();
  static MessageRequestPut* default_instance_;
};
// ===================================================================


// ===================================================================

// MessageRequestPut

// required string path = 1;
inline bool MessageRequestPut::has_path() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void MessageRequestPut::set_has_path() {
  _has_bits_[0] |= 0x00000001u;
}
inline void MessageRequestPut::clear_has_path() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void MessageRequestPut::clear_path() {
  if (path_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    path_->clear();
  }
  clear_has_path();
}
inline const ::std::string& MessageRequestPut::path() const {
  // @@protoc_insertion_point(field_get:MessageRequestPut.path)
  return *path_;
}
inline void MessageRequestPut::set_path(const ::std::string& value) {
  set_has_path();
  if (path_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    path_ = new ::std::string;
  }
  path_->assign(value);
  // @@protoc_insertion_point(field_set:MessageRequestPut.path)
}
inline void MessageRequestPut::set_path(const char* value) {
  set_has_path();
  if (path_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    path_ = new ::std::string;
  }
  path_->assign(value);
  // @@protoc_insertion_point(field_set_char:MessageRequestPut.path)
}
inline void MessageRequestPut::set_path(const char* value, size_t size) {
  set_has_path();
  if (path_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    path_ = new ::std::string;
  }
  path_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:MessageRequestPut.path)
}
inline ::std::string* MessageRequestPut::mutable_path() {
  set_has_path();
  if (path_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    path_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:MessageRequestPut.path)
  return path_;
}
inline ::std::string* MessageRequestPut::release_path() {
  clear_has_path();
  if (path_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = path_;
    path_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void MessageRequestPut::set_allocated_path(::std::string* path) {
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
  // @@protoc_insertion_point(field_set_allocated:MessageRequestPut.path)
}

// required int64 size = 2;
inline bool MessageRequestPut::has_size() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void MessageRequestPut::set_has_size() {
  _has_bits_[0] |= 0x00000002u;
}
inline void MessageRequestPut::clear_has_size() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void MessageRequestPut::clear_size() {
  size_ = GOOGLE_LONGLONG(0);
  clear_has_size();
}
inline ::google::protobuf::int64 MessageRequestPut::size() const {
  // @@protoc_insertion_point(field_get:MessageRequestPut.size)
  return size_;
}
inline void MessageRequestPut::set_size(::google::protobuf::int64 value) {
  set_has_size();
  size_ = value;
  // @@protoc_insertion_point(field_set:MessageRequestPut.size)
}

// required string request_id = 3;
inline bool MessageRequestPut::has_request_id() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void MessageRequestPut::set_has_request_id() {
  _has_bits_[0] |= 0x00000004u;
}
inline void MessageRequestPut::clear_has_request_id() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void MessageRequestPut::clear_request_id() {
  if (request_id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    request_id_->clear();
  }
  clear_has_request_id();
}
inline const ::std::string& MessageRequestPut::request_id() const {
  // @@protoc_insertion_point(field_get:MessageRequestPut.request_id)
  return *request_id_;
}
inline void MessageRequestPut::set_request_id(const ::std::string& value) {
  set_has_request_id();
  if (request_id_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    request_id_ = new ::std::string;
  }
  request_id_->assign(value);
  // @@protoc_insertion_point(field_set:MessageRequestPut.request_id)
}
inline void MessageRequestPut::set_request_id(const char* value) {
  set_has_request_id();
  if (request_id_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    request_id_ = new ::std::string;
  }
  request_id_->assign(value);
  // @@protoc_insertion_point(field_set_char:MessageRequestPut.request_id)
}
inline void MessageRequestPut::set_request_id(const char* value, size_t size) {
  set_has_request_id();
  if (request_id_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    request_id_ = new ::std::string;
  }
  request_id_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:MessageRequestPut.request_id)
}
inline ::std::string* MessageRequestPut::mutable_request_id() {
  set_has_request_id();
  if (request_id_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    request_id_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:MessageRequestPut.request_id)
  return request_id_;
}
inline ::std::string* MessageRequestPut::release_request_id() {
  clear_has_request_id();
  if (request_id_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = request_id_;
    request_id_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void MessageRequestPut::set_allocated_request_id(::std::string* request_id) {
  if (request_id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete request_id_;
  }
  if (request_id) {
    set_has_request_id();
    request_id_ = request_id;
  } else {
    clear_has_request_id();
    request_id_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:MessageRequestPut.request_id)
}


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_MessageRequestPut_2eproto__INCLUDED
