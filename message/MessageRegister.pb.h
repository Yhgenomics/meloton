// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MessageRegister.proto

#ifndef PROTOBUF_MessageRegister_2eproto__INCLUDED
#define PROTOBUF_MessageRegister_2eproto__INCLUDED

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
void  protobuf_AddDesc_MessageRegister_2eproto();
void protobuf_AssignDesc_MessageRegister_2eproto();
void protobuf_ShutdownFile_MessageRegister_2eproto();

class MessageRegister;

// ===================================================================

class MessageRegister : public ::google::protobuf::Message {
 public:
  MessageRegister();
  virtual ~MessageRegister();

  MessageRegister(const MessageRegister& from);

  inline MessageRegister& operator=(const MessageRegister& from) {
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
  static const MessageRegister& default_instance();

  void Swap(MessageRegister* other);

  // implements Message ----------------------------------------------

  MessageRegister* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const MessageRegister& from);
  void MergeFrom(const MessageRegister& from);
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

  // required string id = 1;
  inline bool has_id() const;
  inline void clear_id();
  static const int kIdFieldNumber = 1;
  inline const ::std::string& id() const;
  inline void set_id(const ::std::string& value);
  inline void set_id(const char* value);
  inline void set_id(const char* value, size_t size);
  inline ::std::string* mutable_id();
  inline ::std::string* release_id();
  inline void set_allocated_id(::std::string* id);

  // required int64 disk_space = 2;
  inline bool has_disk_space() const;
  inline void clear_disk_space();
  static const int kDiskSpaceFieldNumber = 2;
  inline ::google::protobuf::int64 disk_space() const;
  inline void set_disk_space(::google::protobuf::int64 value);

  // required int64 block_num = 3;
  inline bool has_block_num() const;
  inline void clear_block_num();
  static const int kBlockNumFieldNumber = 3;
  inline ::google::protobuf::int64 block_num() const;
  inline void set_block_num(::google::protobuf::int64 value);

  // required string data_addr = 4;
  inline bool has_data_addr() const;
  inline void clear_data_addr();
  static const int kDataAddrFieldNumber = 4;
  inline const ::std::string& data_addr() const;
  inline void set_data_addr(const ::std::string& value);
  inline void set_data_addr(const char* value);
  inline void set_data_addr(const char* value, size_t size);
  inline ::std::string* mutable_data_addr();
  inline ::std::string* release_data_addr();
  inline void set_allocated_data_addr(::std::string* data_addr);

  // required int32 data_port = 5;
  inline bool has_data_port() const;
  inline void clear_data_port();
  static const int kDataPortFieldNumber = 5;
  inline ::google::protobuf::int32 data_port() const;
  inline void set_data_port(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:MessageRegister)
 private:
  inline void set_has_id();
  inline void clear_has_id();
  inline void set_has_disk_space();
  inline void clear_has_disk_space();
  inline void set_has_block_num();
  inline void clear_has_block_num();
  inline void set_has_data_addr();
  inline void clear_has_data_addr();
  inline void set_has_data_port();
  inline void clear_has_data_port();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::std::string* id_;
  ::google::protobuf::int64 disk_space_;
  ::google::protobuf::int64 block_num_;
  ::std::string* data_addr_;
  ::google::protobuf::int32 data_port_;
  friend void  protobuf_AddDesc_MessageRegister_2eproto();
  friend void protobuf_AssignDesc_MessageRegister_2eproto();
  friend void protobuf_ShutdownFile_MessageRegister_2eproto();

  void InitAsDefaultInstance();
  static MessageRegister* default_instance_;
};
// ===================================================================


// ===================================================================

// MessageRegister

// required string id = 1;
inline bool MessageRegister::has_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void MessageRegister::set_has_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void MessageRegister::clear_has_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void MessageRegister::clear_id() {
  if (id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    id_->clear();
  }
  clear_has_id();
}
inline const ::std::string& MessageRegister::id() const {
  // @@protoc_insertion_point(field_get:MessageRegister.id)
  return *id_;
}
inline void MessageRegister::set_id(const ::std::string& value) {
  set_has_id();
  if (id_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    id_ = new ::std::string;
  }
  id_->assign(value);
  // @@protoc_insertion_point(field_set:MessageRegister.id)
}
inline void MessageRegister::set_id(const char* value) {
  set_has_id();
  if (id_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    id_ = new ::std::string;
  }
  id_->assign(value);
  // @@protoc_insertion_point(field_set_char:MessageRegister.id)
}
inline void MessageRegister::set_id(const char* value, size_t size) {
  set_has_id();
  if (id_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    id_ = new ::std::string;
  }
  id_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:MessageRegister.id)
}
inline ::std::string* MessageRegister::mutable_id() {
  set_has_id();
  if (id_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    id_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:MessageRegister.id)
  return id_;
}
inline ::std::string* MessageRegister::release_id() {
  clear_has_id();
  if (id_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = id_;
    id_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void MessageRegister::set_allocated_id(::std::string* id) {
  if (id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete id_;
  }
  if (id) {
    set_has_id();
    id_ = id;
  } else {
    clear_has_id();
    id_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:MessageRegister.id)
}

// required int64 disk_space = 2;
inline bool MessageRegister::has_disk_space() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void MessageRegister::set_has_disk_space() {
  _has_bits_[0] |= 0x00000002u;
}
inline void MessageRegister::clear_has_disk_space() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void MessageRegister::clear_disk_space() {
  disk_space_ = GOOGLE_LONGLONG(0);
  clear_has_disk_space();
}
inline ::google::protobuf::int64 MessageRegister::disk_space() const {
  // @@protoc_insertion_point(field_get:MessageRegister.disk_space)
  return disk_space_;
}
inline void MessageRegister::set_disk_space(::google::protobuf::int64 value) {
  set_has_disk_space();
  disk_space_ = value;
  // @@protoc_insertion_point(field_set:MessageRegister.disk_space)
}

// required int64 block_num = 3;
inline bool MessageRegister::has_block_num() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void MessageRegister::set_has_block_num() {
  _has_bits_[0] |= 0x00000004u;
}
inline void MessageRegister::clear_has_block_num() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void MessageRegister::clear_block_num() {
  block_num_ = GOOGLE_LONGLONG(0);
  clear_has_block_num();
}
inline ::google::protobuf::int64 MessageRegister::block_num() const {
  // @@protoc_insertion_point(field_get:MessageRegister.block_num)
  return block_num_;
}
inline void MessageRegister::set_block_num(::google::protobuf::int64 value) {
  set_has_block_num();
  block_num_ = value;
  // @@protoc_insertion_point(field_set:MessageRegister.block_num)
}

// required string data_addr = 4;
inline bool MessageRegister::has_data_addr() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void MessageRegister::set_has_data_addr() {
  _has_bits_[0] |= 0x00000008u;
}
inline void MessageRegister::clear_has_data_addr() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void MessageRegister::clear_data_addr() {
  if (data_addr_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    data_addr_->clear();
  }
  clear_has_data_addr();
}
inline const ::std::string& MessageRegister::data_addr() const {
  // @@protoc_insertion_point(field_get:MessageRegister.data_addr)
  return *data_addr_;
}
inline void MessageRegister::set_data_addr(const ::std::string& value) {
  set_has_data_addr();
  if (data_addr_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    data_addr_ = new ::std::string;
  }
  data_addr_->assign(value);
  // @@protoc_insertion_point(field_set:MessageRegister.data_addr)
}
inline void MessageRegister::set_data_addr(const char* value) {
  set_has_data_addr();
  if (data_addr_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    data_addr_ = new ::std::string;
  }
  data_addr_->assign(value);
  // @@protoc_insertion_point(field_set_char:MessageRegister.data_addr)
}
inline void MessageRegister::set_data_addr(const char* value, size_t size) {
  set_has_data_addr();
  if (data_addr_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    data_addr_ = new ::std::string;
  }
  data_addr_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:MessageRegister.data_addr)
}
inline ::std::string* MessageRegister::mutable_data_addr() {
  set_has_data_addr();
  if (data_addr_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    data_addr_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:MessageRegister.data_addr)
  return data_addr_;
}
inline ::std::string* MessageRegister::release_data_addr() {
  clear_has_data_addr();
  if (data_addr_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = data_addr_;
    data_addr_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void MessageRegister::set_allocated_data_addr(::std::string* data_addr) {
  if (data_addr_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete data_addr_;
  }
  if (data_addr) {
    set_has_data_addr();
    data_addr_ = data_addr;
  } else {
    clear_has_data_addr();
    data_addr_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:MessageRegister.data_addr)
}

// required int32 data_port = 5;
inline bool MessageRegister::has_data_port() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void MessageRegister::set_has_data_port() {
  _has_bits_[0] |= 0x00000010u;
}
inline void MessageRegister::clear_has_data_port() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void MessageRegister::clear_data_port() {
  data_port_ = 0;
  clear_has_data_port();
}
inline ::google::protobuf::int32 MessageRegister::data_port() const {
  // @@protoc_insertion_point(field_get:MessageRegister.data_port)
  return data_port_;
}
inline void MessageRegister::set_data_port(::google::protobuf::int32 value) {
  set_has_data_port();
  data_port_ = value;
  // @@protoc_insertion_point(field_set:MessageRegister.data_port)
}


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_MessageRegister_2eproto__INCLUDED
