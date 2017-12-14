// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: nqueens.proto

#include "nqueens.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)
namespace nqueens {
class MasterCallDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<MasterCall>
      _instance;
} _MasterCall_default_instance_;
class SlaveAskForWorkDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<SlaveAskForWork>
      _instance;
} _SlaveAskForWork_default_instance_;
class MasterAssignWorkDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<MasterAssignWork>
      _instance;
} _MasterAssignWork_default_instance_;
}  // namespace nqueens
namespace protobuf_nqueens_2eproto {
void InitDefaultsMasterCallImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  ::google::protobuf::internal::InitProtobufDefaultsForceUnique();
#else
  ::google::protobuf::internal::InitProtobufDefaults();
#endif  // GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  {
    void* ptr = &::nqueens::_MasterCall_default_instance_;
    new (ptr) ::nqueens::MasterCall();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::nqueens::MasterCall::InitAsDefaultInstance();
}

void InitDefaultsMasterCall() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsMasterCallImpl);
}

void InitDefaultsSlaveAskForWorkImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  ::google::protobuf::internal::InitProtobufDefaultsForceUnique();
#else
  ::google::protobuf::internal::InitProtobufDefaults();
#endif  // GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  {
    void* ptr = &::nqueens::_SlaveAskForWork_default_instance_;
    new (ptr) ::nqueens::SlaveAskForWork();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::nqueens::SlaveAskForWork::InitAsDefaultInstance();
}

void InitDefaultsSlaveAskForWork() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsSlaveAskForWorkImpl);
}

void InitDefaultsMasterAssignWorkImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  ::google::protobuf::internal::InitProtobufDefaultsForceUnique();
#else
  ::google::protobuf::internal::InitProtobufDefaults();
#endif  // GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  {
    void* ptr = &::nqueens::_MasterAssignWork_default_instance_;
    new (ptr) ::nqueens::MasterAssignWork();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::nqueens::MasterAssignWork::InitAsDefaultInstance();
}

void InitDefaultsMasterAssignWork() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsMasterAssignWorkImpl);
}

::google::protobuf::Metadata file_level_metadata[3];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::nqueens::MasterCall, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::nqueens::MasterCall, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::nqueens::MasterCall, password_),
  0,
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::nqueens::SlaveAskForWork, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::nqueens::SlaveAskForWork, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::nqueens::SlaveAskForWork, password_),
  0,
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::nqueens::MasterAssignWork, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::nqueens::MasterAssignWork, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::nqueens::MasterAssignWork, constraint_),
  ~0u,
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 6, sizeof(::nqueens::MasterCall)},
  { 7, 13, sizeof(::nqueens::SlaveAskForWork)},
  { 14, 20, sizeof(::nqueens::MasterAssignWork)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::nqueens::_MasterCall_default_instance_),
  reinterpret_cast<const ::google::protobuf::Message*>(&::nqueens::_SlaveAskForWork_default_instance_),
  reinterpret_cast<const ::google::protobuf::Message*>(&::nqueens::_MasterAssignWork_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "nqueens.proto", schemas, file_default_instances, TableStruct::offsets, factory,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 3);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\rnqueens.proto\022\007nqueens\"\036\n\nMasterCall\022\020"
      "\n\010password\030\001 \002(\t\"#\n\017SlaveAskForWork\022\020\n\010p"
      "assword\030\001 \002(\t\"&\n\020MasterAssignWork\022\022\n\ncon"
      "straint\030\001 \003(\005"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 133);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "nqueens.proto", &protobuf_RegisterTypes);
}

void AddDescriptors() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_nqueens_2eproto
namespace nqueens {

// ===================================================================

void MasterCall::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int MasterCall::kPasswordFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

MasterCall::MasterCall()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_nqueens_2eproto::InitDefaultsMasterCall();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:nqueens.MasterCall)
}
MasterCall::MasterCall(const MasterCall& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  password_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_password()) {
    password_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.password_);
  }
  // @@protoc_insertion_point(copy_constructor:nqueens.MasterCall)
}

void MasterCall::SharedCtor() {
  _cached_size_ = 0;
  password_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

MasterCall::~MasterCall() {
  // @@protoc_insertion_point(destructor:nqueens.MasterCall)
  SharedDtor();
}

void MasterCall::SharedDtor() {
  password_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void MasterCall::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* MasterCall::descriptor() {
  ::protobuf_nqueens_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_nqueens_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const MasterCall& MasterCall::default_instance() {
  ::protobuf_nqueens_2eproto::InitDefaultsMasterCall();
  return *internal_default_instance();
}

MasterCall* MasterCall::New(::google::protobuf::Arena* arena) const {
  MasterCall* n = new MasterCall;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void MasterCall::Clear() {
// @@protoc_insertion_point(message_clear_start:nqueens.MasterCall)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    GOOGLE_DCHECK(!password_.IsDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited()));
    (*password_.UnsafeRawStringPointer())->clear();
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool MasterCall::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:nqueens.MasterCall)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string password = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_password()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->password().data(), static_cast<int>(this->password().length()),
            ::google::protobuf::internal::WireFormat::PARSE,
            "nqueens.MasterCall.password");
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:nqueens.MasterCall)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:nqueens.MasterCall)
  return false;
#undef DO_
}

void MasterCall::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:nqueens.MasterCall)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required string password = 1;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->password().data(), static_cast<int>(this->password().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "nqueens.MasterCall.password");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->password(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:nqueens.MasterCall)
}

::google::protobuf::uint8* MasterCall::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:nqueens.MasterCall)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required string password = 1;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->password().data(), static_cast<int>(this->password().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "nqueens.MasterCall.password");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->password(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:nqueens.MasterCall)
  return target;
}

size_t MasterCall::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:nqueens.MasterCall)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  // required string password = 1;
  if (has_password()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->password());
  }
  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void MasterCall::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:nqueens.MasterCall)
  GOOGLE_DCHECK_NE(&from, this);
  const MasterCall* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const MasterCall>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:nqueens.MasterCall)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:nqueens.MasterCall)
    MergeFrom(*source);
  }
}

void MasterCall::MergeFrom(const MasterCall& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:nqueens.MasterCall)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.has_password()) {
    set_has_password();
    password_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.password_);
  }
}

void MasterCall::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:nqueens.MasterCall)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MasterCall::CopyFrom(const MasterCall& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:nqueens.MasterCall)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MasterCall::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;
  return true;
}

void MasterCall::Swap(MasterCall* other) {
  if (other == this) return;
  InternalSwap(other);
}
void MasterCall::InternalSwap(MasterCall* other) {
  using std::swap;
  password_.Swap(&other->password_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata MasterCall::GetMetadata() const {
  protobuf_nqueens_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_nqueens_2eproto::file_level_metadata[kIndexInFileMessages];
}


// ===================================================================

void SlaveAskForWork::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int SlaveAskForWork::kPasswordFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

SlaveAskForWork::SlaveAskForWork()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_nqueens_2eproto::InitDefaultsSlaveAskForWork();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:nqueens.SlaveAskForWork)
}
SlaveAskForWork::SlaveAskForWork(const SlaveAskForWork& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  password_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_password()) {
    password_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.password_);
  }
  // @@protoc_insertion_point(copy_constructor:nqueens.SlaveAskForWork)
}

void SlaveAskForWork::SharedCtor() {
  _cached_size_ = 0;
  password_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

SlaveAskForWork::~SlaveAskForWork() {
  // @@protoc_insertion_point(destructor:nqueens.SlaveAskForWork)
  SharedDtor();
}

void SlaveAskForWork::SharedDtor() {
  password_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void SlaveAskForWork::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SlaveAskForWork::descriptor() {
  ::protobuf_nqueens_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_nqueens_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const SlaveAskForWork& SlaveAskForWork::default_instance() {
  ::protobuf_nqueens_2eproto::InitDefaultsSlaveAskForWork();
  return *internal_default_instance();
}

SlaveAskForWork* SlaveAskForWork::New(::google::protobuf::Arena* arena) const {
  SlaveAskForWork* n = new SlaveAskForWork;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void SlaveAskForWork::Clear() {
// @@protoc_insertion_point(message_clear_start:nqueens.SlaveAskForWork)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    GOOGLE_DCHECK(!password_.IsDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited()));
    (*password_.UnsafeRawStringPointer())->clear();
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool SlaveAskForWork::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:nqueens.SlaveAskForWork)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string password = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_password()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->password().data(), static_cast<int>(this->password().length()),
            ::google::protobuf::internal::WireFormat::PARSE,
            "nqueens.SlaveAskForWork.password");
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:nqueens.SlaveAskForWork)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:nqueens.SlaveAskForWork)
  return false;
#undef DO_
}

void SlaveAskForWork::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:nqueens.SlaveAskForWork)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required string password = 1;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->password().data(), static_cast<int>(this->password().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "nqueens.SlaveAskForWork.password");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->password(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:nqueens.SlaveAskForWork)
}

::google::protobuf::uint8* SlaveAskForWork::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:nqueens.SlaveAskForWork)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required string password = 1;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->password().data(), static_cast<int>(this->password().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "nqueens.SlaveAskForWork.password");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->password(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:nqueens.SlaveAskForWork)
  return target;
}

size_t SlaveAskForWork::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:nqueens.SlaveAskForWork)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  // required string password = 1;
  if (has_password()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->password());
  }
  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void SlaveAskForWork::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:nqueens.SlaveAskForWork)
  GOOGLE_DCHECK_NE(&from, this);
  const SlaveAskForWork* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const SlaveAskForWork>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:nqueens.SlaveAskForWork)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:nqueens.SlaveAskForWork)
    MergeFrom(*source);
  }
}

void SlaveAskForWork::MergeFrom(const SlaveAskForWork& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:nqueens.SlaveAskForWork)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.has_password()) {
    set_has_password();
    password_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.password_);
  }
}

void SlaveAskForWork::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:nqueens.SlaveAskForWork)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SlaveAskForWork::CopyFrom(const SlaveAskForWork& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:nqueens.SlaveAskForWork)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SlaveAskForWork::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;
  return true;
}

void SlaveAskForWork::Swap(SlaveAskForWork* other) {
  if (other == this) return;
  InternalSwap(other);
}
void SlaveAskForWork::InternalSwap(SlaveAskForWork* other) {
  using std::swap;
  password_.Swap(&other->password_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata SlaveAskForWork::GetMetadata() const {
  protobuf_nqueens_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_nqueens_2eproto::file_level_metadata[kIndexInFileMessages];
}


// ===================================================================

void MasterAssignWork::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int MasterAssignWork::kConstraintFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

MasterAssignWork::MasterAssignWork()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_nqueens_2eproto::InitDefaultsMasterAssignWork();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:nqueens.MasterAssignWork)
}
MasterAssignWork::MasterAssignWork(const MasterAssignWork& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_),
      _cached_size_(0),
      constraint_(from.constraint_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:nqueens.MasterAssignWork)
}

void MasterAssignWork::SharedCtor() {
  _cached_size_ = 0;
}

MasterAssignWork::~MasterAssignWork() {
  // @@protoc_insertion_point(destructor:nqueens.MasterAssignWork)
  SharedDtor();
}

void MasterAssignWork::SharedDtor() {
}

void MasterAssignWork::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* MasterAssignWork::descriptor() {
  ::protobuf_nqueens_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_nqueens_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const MasterAssignWork& MasterAssignWork::default_instance() {
  ::protobuf_nqueens_2eproto::InitDefaultsMasterAssignWork();
  return *internal_default_instance();
}

MasterAssignWork* MasterAssignWork::New(::google::protobuf::Arena* arena) const {
  MasterAssignWork* n = new MasterAssignWork;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void MasterAssignWork::Clear() {
// @@protoc_insertion_point(message_clear_start:nqueens.MasterAssignWork)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  constraint_.Clear();
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool MasterAssignWork::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:nqueens.MasterAssignWork)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated int32 constraint = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 1, 8u, input, this->mutable_constraint())));
        } else if (
            static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitiveNoInline<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, this->mutable_constraint())));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:nqueens.MasterAssignWork)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:nqueens.MasterAssignWork)
  return false;
#undef DO_
}

void MasterAssignWork::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:nqueens.MasterAssignWork)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated int32 constraint = 1;
  for (int i = 0, n = this->constraint_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(
      1, this->constraint(i), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:nqueens.MasterAssignWork)
}

::google::protobuf::uint8* MasterAssignWork::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:nqueens.MasterAssignWork)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated int32 constraint = 1;
  target = ::google::protobuf::internal::WireFormatLite::
    WriteInt32ToArray(1, this->constraint_, target);

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:nqueens.MasterAssignWork)
  return target;
}

size_t MasterAssignWork::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:nqueens.MasterAssignWork)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  // repeated int32 constraint = 1;
  {
    size_t data_size = ::google::protobuf::internal::WireFormatLite::
      Int32Size(this->constraint_);
    total_size += 1 *
                  ::google::protobuf::internal::FromIntSize(this->constraint_size());
    total_size += data_size;
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void MasterAssignWork::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:nqueens.MasterAssignWork)
  GOOGLE_DCHECK_NE(&from, this);
  const MasterAssignWork* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const MasterAssignWork>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:nqueens.MasterAssignWork)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:nqueens.MasterAssignWork)
    MergeFrom(*source);
  }
}

void MasterAssignWork::MergeFrom(const MasterAssignWork& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:nqueens.MasterAssignWork)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  constraint_.MergeFrom(from.constraint_);
}

void MasterAssignWork::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:nqueens.MasterAssignWork)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MasterAssignWork::CopyFrom(const MasterAssignWork& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:nqueens.MasterAssignWork)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MasterAssignWork::IsInitialized() const {
  return true;
}

void MasterAssignWork::Swap(MasterAssignWork* other) {
  if (other == this) return;
  InternalSwap(other);
}
void MasterAssignWork::InternalSwap(MasterAssignWork* other) {
  using std::swap;
  constraint_.InternalSwap(&other->constraint_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata MasterAssignWork::GetMetadata() const {
  protobuf_nqueens_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_nqueens_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace nqueens

// @@protoc_insertion_point(global_scope)
