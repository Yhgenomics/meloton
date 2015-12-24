// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MessageAlive.proto

#ifndef PROTOBUF_MessageAlive_2eproto__INCLUDED
#define PROTOBUF_MessageAlive_2eproto__INCLUDED

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
void  protobuf_AddDesc_MessageAlive_2eproto();
void protobuf_AssignDesc_MessageAlive_2eproto();
void protobuf_ShutdownFile_MessageAlive_2eproto();

class MessageAlive;

// ===================================================================

class MessageAlive : public ::google::protobuf::Message {
 public:
  MessageAlive();
  virtual ~MessageAlive();

  MessageAlive(const MessageAlive& from);

  inline MessageAlive& operator=(const MessageAlive& from) {
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
  static const MessageAlive& default_instance();

  void Swap(MessageAlive* other);

  // implements Message ----------------------------------------------

  MessageAlive* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const MessageAlive& from);
  void MergeFrom(const MessageAlive& from);
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

  // required int64 session_id = 1;
  inline bool has_session_id() const;
  inline void clear_session_id();
  static const int kSessionIdFieldNumber = 1;
  inline ::google::protobuf::int64 session_id() const;
  inline void set_session_id(::google::protobuf::int64 value);

  // required int64 local_time = 2;
  inline bool has_local_time() const;
  inline void clear_local_time();
  static const int kLocalTimeFieldNumber = 2;
  inline ::google::protobuf::int64 local_time() const;
  inline void set_local_time(::google::protobuf::int64 value);

  // required int64 disk_space = 3;
  inline bool has_disk_space() const;
  inline void clear_disk_space();
  static const int kDiskSpaceFieldNumber = 3;
  inline ::google::protobuf::int64 disk_space() const;
  inline void set_disk_space(::google::protobuf::int64 value);

  // required int64 block_num = 4;
  inline bool has_block_num() const;
  inline void clear_block_num();
  static const int kBlockNumFieldNumber = 4;
  inline ::google::protobuf::int64 block_num() const;
  inline void set_block_num(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:MessageAlive)
 private:
  inline void set_has_session_id();
  inline void clear_has_session_id();
  inline void set_has_local_time();
  inline void clear_has_local_time();
  inline void set_has_disk_space();
  inline void clear_has_disk_space();
  inline void set_has_block_num();
  inline void clear_has_block_num();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::int64 session_id_;
  ::google::protobuf::int64 local_time_;
  ::google::protobuf::int64 disk_space_;
  ::google::protobuf::int64 block_num_;
  friend void  protobuf_AddDesc_MessageAlive_2eproto();
  friend void protobuf_AssignDesc_MessageAlive_2eproto();
  friend void protobuf_ShutdownFile_MessageAlive_2eproto();

  void InitAsDefaultInstance();
  static MessageAlive* default_instance_;
};
// ===================================================================


// ===================================================================

// MessageAlive

// required int64 session_id = 1;
inline bool MessageAlive::has_session_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void MessageAlive::set_has_session_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void MessageAlive::clear_has_session_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void MessageAlive::clear_session_id() {
  session_id_ = GOOGLE_LONGLONG(0);
  clear_has_session_id();
}
inline ::google::protobuf::int64 MessageAlive::session_id() const {
  // @@protoc_insertion_point(field_get:MessageAlive.session_id)
  return session_id_;
}
inline void MessageAlive::set_session_id(::google::protobuf::int64 value) {
  set_has_session_id();
  session_id_ = value;
  // @@protoc_insertion_point(field_set:MessageAlive.session_id)
}

// required int64 local_time = 2;
inline bool MessageAlive::has_local_time() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void MessageAlive::set_has_local_time() {
  _has_bits_[0] |= 0x00000002u;
}
inline void MessageAlive::clear_has_local_time() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void MessageAlive::clear_local_time() {
  local_time_ = GOOGLE_LONGLONG(0);
  clear_has_local_time();
}
inline ::google::protobuf::int64 MessageAlive::local_time() const {
  // @@protoc_insertion_point(field_get:MessageAlive.local_time)
  return local_time_;
}
inline void MessageAlive::set_local_time(::google::protobuf::int64 value) {
  set_has_local_time();
  local_time_ = value;
  // @@protoc_insertion_point(field_set:MessageAlive.local_time)
}

// required int64 disk_space = 3;
inline bool MessageAlive::has_disk_space() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void MessageAlive::set_has_disk_space() {
  _has_bits_[0] |= 0x00000004u;
}
inline void MessageAlive::clear_has_disk_space() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void MessageAlive::clear_disk_space() {
  disk_space_ = GOOGLE_LONGLONG(0);
  clear_has_disk_space();
}
inline ::google::protobuf::int64 MessageAlive::disk_space() const {
  // @@protoc_insertion_point(field_get:MessageAlive.disk_space)
  return disk_space_;
}
inline void MessageAlive::set_disk_space(::google::protobuf::int64 value) {
  set_has_disk_space();
  disk_space_ = value;
  // @@protoc_insertion_point(field_set:MessageAlive.disk_space)
}

// required int64 block_num = 4;
inline bool MessageAlive::has_block_num() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void MessageAlive::set_has_block_num() {
  _has_bits_[0] |= 0x00000008u;
}
inline void MessageAlive::clear_has_block_num() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void MessageAlive::clear_block_num() {
  block_num_ = GOOGLE_LONGLONG(0);
  clear_has_block_num();
}
inline ::google::protobuf::int64 MessageAlive::block_num() const {
  // @@protoc_insertion_point(field_get:MessageAlive.block_num)
  return block_num_;
}
inline void MessageAlive::set_block_num(::google::protobuf::int64 value) {
  set_has_block_num();
  block_num_ = value;
  // @@protoc_insertion_point(field_set:MessageAlive.block_num)
}


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_MessageAlive_2eproto__INCLUDED
