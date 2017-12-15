// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: nqueens.proto

#ifndef PROTOBUF_nqueens_2eproto__INCLUDED
#define PROTOBUF_nqueens_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace protobuf_nqueens_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[3];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
void InitDefaultsMasterCallImpl();
void InitDefaultsMasterCall();
void InitDefaultsSlaveAskForWorkImpl();
void InitDefaultsSlaveAskForWork();
void InitDefaultsMasterAssignWorkImpl();
void InitDefaultsMasterAssignWork();
inline void InitDefaults() {
  InitDefaultsMasterCall();
  InitDefaultsSlaveAskForWork();
  InitDefaultsMasterAssignWork();
}
}  // namespace protobuf_nqueens_2eproto
namespace nqueens {
class MasterAssignWork;
class MasterAssignWorkDefaultTypeInternal;
extern MasterAssignWorkDefaultTypeInternal _MasterAssignWork_default_instance_;
class MasterCall;
class MasterCallDefaultTypeInternal;
extern MasterCallDefaultTypeInternal _MasterCall_default_instance_;
class SlaveAskForWork;
class SlaveAskForWorkDefaultTypeInternal;
extern SlaveAskForWorkDefaultTypeInternal _SlaveAskForWork_default_instance_;
}  // namespace nqueens
namespace nqueens {

enum MasterMsgID {
  MASTER_MSG_CALL = 1,
  MASTER_MSG_ASSIGN_WORK = 2
};
bool MasterMsgID_IsValid(int value);
const MasterMsgID MasterMsgID_MIN = MASTER_MSG_CALL;
const MasterMsgID MasterMsgID_MAX = MASTER_MSG_ASSIGN_WORK;
const int MasterMsgID_ARRAYSIZE = MasterMsgID_MAX + 1;

const ::google::protobuf::EnumDescriptor* MasterMsgID_descriptor();
inline const ::std::string& MasterMsgID_Name(MasterMsgID value) {
  return ::google::protobuf::internal::NameOfEnum(
    MasterMsgID_descriptor(), value);
}
inline bool MasterMsgID_Parse(
    const ::std::string& name, MasterMsgID* value) {
  return ::google::protobuf::internal::ParseNamedEnum<MasterMsgID>(
    MasterMsgID_descriptor(), name, value);
}
enum SlaveMsgID {
  SLAVE_MSG_ASK_FOR_WORK = 1
};
bool SlaveMsgID_IsValid(int value);
const SlaveMsgID SlaveMsgID_MIN = SLAVE_MSG_ASK_FOR_WORK;
const SlaveMsgID SlaveMsgID_MAX = SLAVE_MSG_ASK_FOR_WORK;
const int SlaveMsgID_ARRAYSIZE = SlaveMsgID_MAX + 1;

const ::google::protobuf::EnumDescriptor* SlaveMsgID_descriptor();
inline const ::std::string& SlaveMsgID_Name(SlaveMsgID value) {
  return ::google::protobuf::internal::NameOfEnum(
    SlaveMsgID_descriptor(), value);
}
inline bool SlaveMsgID_Parse(
    const ::std::string& name, SlaveMsgID* value) {
  return ::google::protobuf::internal::ParseNamedEnum<SlaveMsgID>(
    SlaveMsgID_descriptor(), name, value);
}
enum ErrorCode {
  ERROR_NO_ERROR = 0,
  ERROR_MASTER_NO_MORE_WORK = 1
};
bool ErrorCode_IsValid(int value);
const ErrorCode ErrorCode_MIN = ERROR_NO_ERROR;
const ErrorCode ErrorCode_MAX = ERROR_MASTER_NO_MORE_WORK;
const int ErrorCode_ARRAYSIZE = ErrorCode_MAX + 1;

const ::google::protobuf::EnumDescriptor* ErrorCode_descriptor();
inline const ::std::string& ErrorCode_Name(ErrorCode value) {
  return ::google::protobuf::internal::NameOfEnum(
    ErrorCode_descriptor(), value);
}
inline bool ErrorCode_Parse(
    const ::std::string& name, ErrorCode* value) {
  return ::google::protobuf::internal::ParseNamedEnum<ErrorCode>(
    ErrorCode_descriptor(), name, value);
}
// ===================================================================

class MasterCall : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:nqueens.MasterCall) */ {
 public:
  MasterCall();
  virtual ~MasterCall();

  MasterCall(const MasterCall& from);

  inline MasterCall& operator=(const MasterCall& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  MasterCall(MasterCall&& from) noexcept
    : MasterCall() {
    *this = ::std::move(from);
  }

  inline MasterCall& operator=(MasterCall&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const MasterCall& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const MasterCall* internal_default_instance() {
    return reinterpret_cast<const MasterCall*>(
               &_MasterCall_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(MasterCall* other);
  friend void swap(MasterCall& a, MasterCall& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline MasterCall* New() const PROTOBUF_FINAL { return New(NULL); }

  MasterCall* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const MasterCall& from);
  void MergeFrom(const MasterCall& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(MasterCall* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required string password = 1;
  bool has_password() const;
  void clear_password();
  static const int kPasswordFieldNumber = 1;
  const ::std::string& password() const;
  void set_password(const ::std::string& value);
  #if LANG_CXX11
  void set_password(::std::string&& value);
  #endif
  void set_password(const char* value);
  void set_password(const char* value, size_t size);
  ::std::string* mutable_password();
  ::std::string* release_password();
  void set_allocated_password(::std::string* password);

  // @@protoc_insertion_point(class_scope:nqueens.MasterCall)
 private:
  void set_has_password();
  void clear_has_password();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::internal::ArenaStringPtr password_;
  friend struct ::protobuf_nqueens_2eproto::TableStruct;
  friend void ::protobuf_nqueens_2eproto::InitDefaultsMasterCallImpl();
};
// -------------------------------------------------------------------

class SlaveAskForWork : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:nqueens.SlaveAskForWork) */ {
 public:
  SlaveAskForWork();
  virtual ~SlaveAskForWork();

  SlaveAskForWork(const SlaveAskForWork& from);

  inline SlaveAskForWork& operator=(const SlaveAskForWork& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  SlaveAskForWork(SlaveAskForWork&& from) noexcept
    : SlaveAskForWork() {
    *this = ::std::move(from);
  }

  inline SlaveAskForWork& operator=(SlaveAskForWork&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const SlaveAskForWork& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const SlaveAskForWork* internal_default_instance() {
    return reinterpret_cast<const SlaveAskForWork*>(
               &_SlaveAskForWork_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(SlaveAskForWork* other);
  friend void swap(SlaveAskForWork& a, SlaveAskForWork& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline SlaveAskForWork* New() const PROTOBUF_FINAL { return New(NULL); }

  SlaveAskForWork* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const SlaveAskForWork& from);
  void MergeFrom(const SlaveAskForWork& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(SlaveAskForWork* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required string password = 1;
  bool has_password() const;
  void clear_password();
  static const int kPasswordFieldNumber = 1;
  const ::std::string& password() const;
  void set_password(const ::std::string& value);
  #if LANG_CXX11
  void set_password(::std::string&& value);
  #endif
  void set_password(const char* value);
  void set_password(const char* value, size_t size);
  ::std::string* mutable_password();
  ::std::string* release_password();
  void set_allocated_password(::std::string* password);

  // @@protoc_insertion_point(class_scope:nqueens.SlaveAskForWork)
 private:
  void set_has_password();
  void clear_has_password();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::internal::ArenaStringPtr password_;
  friend struct ::protobuf_nqueens_2eproto::TableStruct;
  friend void ::protobuf_nqueens_2eproto::InitDefaultsSlaveAskForWorkImpl();
};
// -------------------------------------------------------------------

class MasterAssignWork : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:nqueens.MasterAssignWork) */ {
 public:
  MasterAssignWork();
  virtual ~MasterAssignWork();

  MasterAssignWork(const MasterAssignWork& from);

  inline MasterAssignWork& operator=(const MasterAssignWork& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  MasterAssignWork(MasterAssignWork&& from) noexcept
    : MasterAssignWork() {
    *this = ::std::move(from);
  }

  inline MasterAssignWork& operator=(MasterAssignWork&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const MasterAssignWork& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const MasterAssignWork* internal_default_instance() {
    return reinterpret_cast<const MasterAssignWork*>(
               &_MasterAssignWork_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    2;

  void Swap(MasterAssignWork* other);
  friend void swap(MasterAssignWork& a, MasterAssignWork& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline MasterAssignWork* New() const PROTOBUF_FINAL { return New(NULL); }

  MasterAssignWork* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const MasterAssignWork& from);
  void MergeFrom(const MasterAssignWork& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(MasterAssignWork* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated int32 constraint = 2;
  int constraint_size() const;
  void clear_constraint();
  static const int kConstraintFieldNumber = 2;
  ::google::protobuf::int32 constraint(int index) const;
  void set_constraint(int index, ::google::protobuf::int32 value);
  void add_constraint(::google::protobuf::int32 value);
  const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
      constraint() const;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
      mutable_constraint();

  // required int32 error_code = 1;
  bool has_error_code() const;
  void clear_error_code();
  static const int kErrorCodeFieldNumber = 1;
  ::google::protobuf::int32 error_code() const;
  void set_error_code(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:nqueens.MasterAssignWork)
 private:
  void set_has_error_code();
  void clear_has_error_code();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 > constraint_;
  ::google::protobuf::int32 error_code_;
  friend struct ::protobuf_nqueens_2eproto::TableStruct;
  friend void ::protobuf_nqueens_2eproto::InitDefaultsMasterAssignWorkImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// MasterCall

// required string password = 1;
inline bool MasterCall::has_password() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void MasterCall::set_has_password() {
  _has_bits_[0] |= 0x00000001u;
}
inline void MasterCall::clear_has_password() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void MasterCall::clear_password() {
  password_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_password();
}
inline const ::std::string& MasterCall::password() const {
  // @@protoc_insertion_point(field_get:nqueens.MasterCall.password)
  return password_.GetNoArena();
}
inline void MasterCall::set_password(const ::std::string& value) {
  set_has_password();
  password_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:nqueens.MasterCall.password)
}
#if LANG_CXX11
inline void MasterCall::set_password(::std::string&& value) {
  set_has_password();
  password_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:nqueens.MasterCall.password)
}
#endif
inline void MasterCall::set_password(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_password();
  password_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:nqueens.MasterCall.password)
}
inline void MasterCall::set_password(const char* value, size_t size) {
  set_has_password();
  password_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:nqueens.MasterCall.password)
}
inline ::std::string* MasterCall::mutable_password() {
  set_has_password();
  // @@protoc_insertion_point(field_mutable:nqueens.MasterCall.password)
  return password_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* MasterCall::release_password() {
  // @@protoc_insertion_point(field_release:nqueens.MasterCall.password)
  clear_has_password();
  return password_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void MasterCall::set_allocated_password(::std::string* password) {
  if (password != NULL) {
    set_has_password();
  } else {
    clear_has_password();
  }
  password_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), password);
  // @@protoc_insertion_point(field_set_allocated:nqueens.MasterCall.password)
}

// -------------------------------------------------------------------

// SlaveAskForWork

// required string password = 1;
inline bool SlaveAskForWork::has_password() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void SlaveAskForWork::set_has_password() {
  _has_bits_[0] |= 0x00000001u;
}
inline void SlaveAskForWork::clear_has_password() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void SlaveAskForWork::clear_password() {
  password_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_password();
}
inline const ::std::string& SlaveAskForWork::password() const {
  // @@protoc_insertion_point(field_get:nqueens.SlaveAskForWork.password)
  return password_.GetNoArena();
}
inline void SlaveAskForWork::set_password(const ::std::string& value) {
  set_has_password();
  password_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:nqueens.SlaveAskForWork.password)
}
#if LANG_CXX11
inline void SlaveAskForWork::set_password(::std::string&& value) {
  set_has_password();
  password_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:nqueens.SlaveAskForWork.password)
}
#endif
inline void SlaveAskForWork::set_password(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_password();
  password_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:nqueens.SlaveAskForWork.password)
}
inline void SlaveAskForWork::set_password(const char* value, size_t size) {
  set_has_password();
  password_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:nqueens.SlaveAskForWork.password)
}
inline ::std::string* SlaveAskForWork::mutable_password() {
  set_has_password();
  // @@protoc_insertion_point(field_mutable:nqueens.SlaveAskForWork.password)
  return password_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* SlaveAskForWork::release_password() {
  // @@protoc_insertion_point(field_release:nqueens.SlaveAskForWork.password)
  clear_has_password();
  return password_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SlaveAskForWork::set_allocated_password(::std::string* password) {
  if (password != NULL) {
    set_has_password();
  } else {
    clear_has_password();
  }
  password_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), password);
  // @@protoc_insertion_point(field_set_allocated:nqueens.SlaveAskForWork.password)
}

// -------------------------------------------------------------------

// MasterAssignWork

// required int32 error_code = 1;
inline bool MasterAssignWork::has_error_code() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void MasterAssignWork::set_has_error_code() {
  _has_bits_[0] |= 0x00000001u;
}
inline void MasterAssignWork::clear_has_error_code() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void MasterAssignWork::clear_error_code() {
  error_code_ = 0;
  clear_has_error_code();
}
inline ::google::protobuf::int32 MasterAssignWork::error_code() const {
  // @@protoc_insertion_point(field_get:nqueens.MasterAssignWork.error_code)
  return error_code_;
}
inline void MasterAssignWork::set_error_code(::google::protobuf::int32 value) {
  set_has_error_code();
  error_code_ = value;
  // @@protoc_insertion_point(field_set:nqueens.MasterAssignWork.error_code)
}

// repeated int32 constraint = 2;
inline int MasterAssignWork::constraint_size() const {
  return constraint_.size();
}
inline void MasterAssignWork::clear_constraint() {
  constraint_.Clear();
}
inline ::google::protobuf::int32 MasterAssignWork::constraint(int index) const {
  // @@protoc_insertion_point(field_get:nqueens.MasterAssignWork.constraint)
  return constraint_.Get(index);
}
inline void MasterAssignWork::set_constraint(int index, ::google::protobuf::int32 value) {
  constraint_.Set(index, value);
  // @@protoc_insertion_point(field_set:nqueens.MasterAssignWork.constraint)
}
inline void MasterAssignWork::add_constraint(::google::protobuf::int32 value) {
  constraint_.Add(value);
  // @@protoc_insertion_point(field_add:nqueens.MasterAssignWork.constraint)
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
MasterAssignWork::constraint() const {
  // @@protoc_insertion_point(field_list:nqueens.MasterAssignWork.constraint)
  return constraint_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
MasterAssignWork::mutable_constraint() {
  // @@protoc_insertion_point(field_mutable_list:nqueens.MasterAssignWork.constraint)
  return &constraint_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace nqueens

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::nqueens::MasterMsgID> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::nqueens::MasterMsgID>() {
  return ::nqueens::MasterMsgID_descriptor();
}
template <> struct is_proto_enum< ::nqueens::SlaveMsgID> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::nqueens::SlaveMsgID>() {
  return ::nqueens::SlaveMsgID_descriptor();
}
template <> struct is_proto_enum< ::nqueens::ErrorCode> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::nqueens::ErrorCode>() {
  return ::nqueens::ErrorCode_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_nqueens_2eproto__INCLUDED
