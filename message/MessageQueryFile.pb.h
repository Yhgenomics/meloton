// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MessageQueryFile.proto

#ifndef PROTOBUF_MessageQueryFile_2eproto__INCLUDED
#define PROTOBUF_MessageQueryFile_2eproto__INCLUDED

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
void  protobuf_AddDesc_MessageQueryFile_2eproto();
void protobuf_AssignDesc_MessageQueryFile_2eproto();
void protobuf_ShutdownFile_MessageQueryFile_2eproto();

class MessageQueryFile;

// ===================================================================

class MessageQueryFile : public ::google::protobuf::Message {
 public:
  MessageQueryFile();
  virtual ~MessageQueryFile();

  MessageQueryFile(const MessageQueryFile& from);

  inline MessageQueryFile& operator=(const MessageQueryFile& from) {
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
  static const MessageQueryFile& default_instance();

  void Swap(MessageQueryFile* other);

  // implements Message ----------------------------------------------

  MessageQueryFile* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const MessageQueryFile& from);
  void MergeFrom(const MessageQueryFile& from);
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

  // required string file_name = 1;
  inline bool has_file_name() const;
  inline void clear_file_name();
  static const int kFileNameFieldNumber = 1;
  inline const ::std::string& file_name() const;
  inline void set_file_name(const ::std::string& value);
  inline void set_file_name(const char* value);
  inline void set_file_name(const char* value, size_t size);
  inline ::std::string* mutable_file_name();
  inline ::std::string* release_file_name();
  inline void set_allocated_file_name(::std::string* file_name);

  // required int64 job_id = 2;
  inline bool has_job_id() const;
  inline void clear_job_id();
  static const int kJobIdFieldNumber = 2;
  inline ::google::protobuf::int64 job_id() const;
  inline void set_job_id(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:MessageQueryFile)
 private:
  inline void set_has_file_name();
  inline void clear_has_file_name();
  inline void set_has_job_id();
  inline void clear_has_job_id();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::std::string* file_name_;
  ::google::protobuf::int64 job_id_;
  friend void  protobuf_AddDesc_MessageQueryFile_2eproto();
  friend void protobuf_AssignDesc_MessageQueryFile_2eproto();
  friend void protobuf_ShutdownFile_MessageQueryFile_2eproto();

  void InitAsDefaultInstance();
  static MessageQueryFile* default_instance_;
};
// ===================================================================


// ===================================================================

// MessageQueryFile

// required string file_name = 1;
inline bool MessageQueryFile::has_file_name() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void MessageQueryFile::set_has_file_name() {
  _has_bits_[0] |= 0x00000001u;
}
inline void MessageQueryFile::clear_has_file_name() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void MessageQueryFile::clear_file_name() {
  if (file_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    file_name_->clear();
  }
  clear_has_file_name();
}
inline const ::std::string& MessageQueryFile::file_name() const {
  // @@protoc_insertion_point(field_get:MessageQueryFile.file_name)
  return *file_name_;
}
inline void MessageQueryFile::set_file_name(const ::std::string& value) {
  set_has_file_name();
  if (file_name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    file_name_ = new ::std::string;
  }
  file_name_->assign(value);
  // @@protoc_insertion_point(field_set:MessageQueryFile.file_name)
}
inline void MessageQueryFile::set_file_name(const char* value) {
  set_has_file_name();
  if (file_name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    file_name_ = new ::std::string;
  }
  file_name_->assign(value);
  // @@protoc_insertion_point(field_set_char:MessageQueryFile.file_name)
}
inline void MessageQueryFile::set_file_name(const char* value, size_t size) {
  set_has_file_name();
  if (file_name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    file_name_ = new ::std::string;
  }
  file_name_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:MessageQueryFile.file_name)
}
inline ::std::string* MessageQueryFile::mutable_file_name() {
  set_has_file_name();
  if (file_name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    file_name_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:MessageQueryFile.file_name)
  return file_name_;
}
inline ::std::string* MessageQueryFile::release_file_name() {
  clear_has_file_name();
  if (file_name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = file_name_;
    file_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void MessageQueryFile::set_allocated_file_name(::std::string* file_name) {
  if (file_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete file_name_;
  }
  if (file_name) {
    set_has_file_name();
    file_name_ = file_name;
  } else {
    clear_has_file_name();
    file_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:MessageQueryFile.file_name)
}

// required int64 job_id = 2;
inline bool MessageQueryFile::has_job_id() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void MessageQueryFile::set_has_job_id() {
  _has_bits_[0] |= 0x00000002u;
}
inline void MessageQueryFile::clear_has_job_id() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void MessageQueryFile::clear_job_id() {
  job_id_ = GOOGLE_LONGLONG(0);
  clear_has_job_id();
}
inline ::google::protobuf::int64 MessageQueryFile::job_id() const {
  // @@protoc_insertion_point(field_get:MessageQueryFile.job_id)
  return job_id_;
}
inline void MessageQueryFile::set_job_id(::google::protobuf::int64 value) {
  set_has_job_id();
  job_id_ = value;
  // @@protoc_insertion_point(field_set:MessageQueryFile.job_id)
}


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_MessageQueryFile_2eproto__INCLUDED