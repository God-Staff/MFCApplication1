// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: config.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "config.pb.h"

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
// @@protoc_insertion_point(includes)

namespace qiuwanli {
class ConfigDefaultTypeInternal : public ::google::protobuf::internal::ExplicitlyConstructed<Config> {
} _Config_default_instance_;
class ConfigFileDefaultTypeInternal : public ::google::protobuf::internal::ExplicitlyConstructed<ConfigFile> {
} _ConfigFile_default_instance_;

namespace protobuf_config_2eproto {


namespace {

::google::protobuf::Metadata file_level_metadata[2];
const ::google::protobuf::EnumDescriptor* file_level_enum_descriptors[1];

}  // namespace

const ::google::protobuf::uint32 TableStruct::offsets[] = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Config, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Config, value_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Config, type_),
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ConfigFile, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ConfigFile, config_),
};

static const ::google::protobuf::internal::MigrationSchema schemas[] = {
  { 0, -1, sizeof(Config)},
  { 6, -1, sizeof(ConfigFile)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&_Config_default_instance_),
  reinterpret_cast<const ::google::protobuf::Message*>(&_ConfigFile_default_instance_),
};

namespace {

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "config.proto", schemas, file_default_instances, TableStruct::offsets, factory,
      file_level_metadata, file_level_enum_descriptors, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 2);
}

}  // namespace

void TableStruct::Shutdown() {
  _Config_default_instance_.Shutdown();
  delete file_level_metadata[0].reflection;
  _ConfigFile_default_instance_.Shutdown();
  delete file_level_metadata[1].reflection;
}

void TableStruct::InitDefaultsImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::internal::InitProtobufDefaults();
  _Config_default_instance_.DefaultConstruct();
  _ConfigFile_default_instance_.DefaultConstruct();
}

void InitDefaults() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &TableStruct::InitDefaultsImpl);
}
void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] = {
      "\n\014config.proto\022\010qiuwanli\"5\n\006Config\022\r\n\005va"
      "lue\030\001 \001(\t\022\034\n\004type\030\002 \001(\0162\016.qiuwanli.Type\""
      ".\n\nConfigFile\022 \n\006config\030\001 \003(\0132\020.qiuwanli"
      ".Config*n\n\004Type\022\020\n\014DownFilePath\020\000\022\017\n\013Thr"
      "eadNumUp\020\001\022\021\n\rThreadNumDown\020\002\022\017\n\013FileUpS"
      "peed\020\003\022\021\n\rFileDownSpeed\020\004\022\014\n\010FilePath\020\005b"
      "\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 247);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "config.proto", &protobuf_RegisterTypes);
  ::google::protobuf::internal::OnShutdown(&TableStruct::Shutdown);
}

void AddDescriptors() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;

}  // namespace protobuf_config_2eproto

const ::google::protobuf::EnumDescriptor* Type_descriptor() {
  protobuf_config_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_config_2eproto::file_level_enum_descriptors[0];
}
bool Type_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      return true;
    default:
      return false;
  }
}


// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Config::kValueFieldNumber;
const int Config::kTypeFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Config::Config()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    protobuf_config_2eproto::InitDefaults();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:qiuwanli.Config)
}
Config::Config(const Config& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  value_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.value().size() > 0) {
    value_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.value_);
  }
  type_ = from.type_;
  // @@protoc_insertion_point(copy_constructor:qiuwanli.Config)
}

void Config::SharedCtor() {
  value_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  type_ = 0;
  _cached_size_ = 0;
}

Config::~Config() {
  // @@protoc_insertion_point(destructor:qiuwanli.Config)
  SharedDtor();
}

void Config::SharedDtor() {
  value_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void Config::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Config::descriptor() {
  protobuf_config_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_config_2eproto::file_level_metadata[0].descriptor;
}

const Config& Config::default_instance() {
  protobuf_config_2eproto::InitDefaults();
  return *internal_default_instance();
}

Config* Config::New(::google::protobuf::Arena* arena) const {
  Config* n = new Config;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void Config::Clear() {
// @@protoc_insertion_point(message_clear_start:qiuwanli.Config)
  value_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  type_ = 0;
}

bool Config::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:qiuwanli.Config)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // string value = 1;
      case 1: {
        if (tag == 10u) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_value()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->value().data(), this->value().length(),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "qiuwanli.Config.value"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // .qiuwanli.Type type = 2;
      case 2: {
        if (tag == 16u) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          set_type(static_cast< ::qiuwanli::Type >(value));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:qiuwanli.Config)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:qiuwanli.Config)
  return false;
#undef DO_
}

void Config::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:qiuwanli.Config)
  // string value = 1;
  if (this->value().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->value().data(), this->value().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "qiuwanli.Config.value");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->value(), output);
  }

  // .qiuwanli.Type type = 2;
  if (this->type() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      2, this->type(), output);
  }

  // @@protoc_insertion_point(serialize_end:qiuwanli.Config)
}

::google::protobuf::uint8* Config::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic;  // Unused
  // @@protoc_insertion_point(serialize_to_array_start:qiuwanli.Config)
  // string value = 1;
  if (this->value().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->value().data(), this->value().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "qiuwanli.Config.value");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->value(), target);
  }

  // .qiuwanli.Type type = 2;
  if (this->type() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      2, this->type(), target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:qiuwanli.Config)
  return target;
}

size_t Config::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:qiuwanli.Config)
  size_t total_size = 0;

  // string value = 1;
  if (this->value().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->value());
  }

  // .qiuwanli.Type type = 2;
  if (this->type() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::EnumSize(this->type());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Config::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:qiuwanli.Config)
  GOOGLE_DCHECK_NE(&from, this);
  const Config* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const Config>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:qiuwanli.Config)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:qiuwanli.Config)
    MergeFrom(*source);
  }
}

void Config::MergeFrom(const Config& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:qiuwanli.Config)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  if (from.value().size() > 0) {

    value_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.value_);
  }
  if (from.type() != 0) {
    set_type(from.type());
  }
}

void Config::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:qiuwanli.Config)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Config::CopyFrom(const Config& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:qiuwanli.Config)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Config::IsInitialized() const {
  return true;
}

void Config::Swap(Config* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Config::InternalSwap(Config* other) {
  value_.Swap(&other->value_);
  std::swap(type_, other->type_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata Config::GetMetadata() const {
  protobuf_config_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_config_2eproto::file_level_metadata[0];
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// Config

// string value = 1;
void Config::clear_value() {
  value_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
const ::std::string& Config::value() const {
  // @@protoc_insertion_point(field_get:qiuwanli.Config.value)
  return value_.GetNoArena();
}
void Config::set_value(const ::std::string& value) {
  
  value_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:qiuwanli.Config.value)
}
#if LANG_CXX11
void Config::set_value(::std::string&& value) {
  
  value_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:qiuwanli.Config.value)
}
#endif
void Config::set_value(const char* value) {
  
  value_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:qiuwanli.Config.value)
}
void Config::set_value(const char* value, size_t size) {
  
  value_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:qiuwanli.Config.value)
}
::std::string* Config::mutable_value() {
  
  // @@protoc_insertion_point(field_mutable:qiuwanli.Config.value)
  return value_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
::std::string* Config::release_value() {
  // @@protoc_insertion_point(field_release:qiuwanli.Config.value)
  
  return value_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
void Config::set_allocated_value(::std::string* value) {
  if (value != NULL) {
    
  } else {
    
  }
  value_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set_allocated:qiuwanli.Config.value)
}

// .qiuwanli.Type type = 2;
void Config::clear_type() {
  type_ = 0;
}
::qiuwanli::Type Config::type() const {
  // @@protoc_insertion_point(field_get:qiuwanli.Config.type)
  return static_cast< ::qiuwanli::Type >(type_);
}
void Config::set_type(::qiuwanli::Type value) {
  
  type_ = value;
  // @@protoc_insertion_point(field_set:qiuwanli.Config.type)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int ConfigFile::kConfigFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

ConfigFile::ConfigFile()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    protobuf_config_2eproto::InitDefaults();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:qiuwanli.ConfigFile)
}
ConfigFile::ConfigFile(const ConfigFile& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      config_(from.config_),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:qiuwanli.ConfigFile)
}

void ConfigFile::SharedCtor() {
  _cached_size_ = 0;
}

ConfigFile::~ConfigFile() {
  // @@protoc_insertion_point(destructor:qiuwanli.ConfigFile)
  SharedDtor();
}

void ConfigFile::SharedDtor() {
}

void ConfigFile::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ConfigFile::descriptor() {
  protobuf_config_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_config_2eproto::file_level_metadata[1].descriptor;
}

const ConfigFile& ConfigFile::default_instance() {
  protobuf_config_2eproto::InitDefaults();
  return *internal_default_instance();
}

ConfigFile* ConfigFile::New(::google::protobuf::Arena* arena) const {
  ConfigFile* n = new ConfigFile;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void ConfigFile::Clear() {
// @@protoc_insertion_point(message_clear_start:qiuwanli.ConfigFile)
  config_.Clear();
}

bool ConfigFile::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:qiuwanli.ConfigFile)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .qiuwanli.Config config = 1;
      case 1: {
        if (tag == 10u) {
          DO_(input->IncrementRecursionDepth());
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtualNoRecursionDepth(
                input, add_config()));
        } else {
          goto handle_unusual;
        }
        input->UnsafeDecrementRecursionDepth();
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:qiuwanli.ConfigFile)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:qiuwanli.ConfigFile)
  return false;
#undef DO_
}

void ConfigFile::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:qiuwanli.ConfigFile)
  // repeated .qiuwanli.Config config = 1;
  for (unsigned int i = 0, n = this->config_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->config(i), output);
  }

  // @@protoc_insertion_point(serialize_end:qiuwanli.ConfigFile)
}

::google::protobuf::uint8* ConfigFile::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic;  // Unused
  // @@protoc_insertion_point(serialize_to_array_start:qiuwanli.ConfigFile)
  // repeated .qiuwanli.Config config = 1;
  for (unsigned int i = 0, n = this->config_size(); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageNoVirtualToArray(
        1, this->config(i), false, target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:qiuwanli.ConfigFile)
  return target;
}

size_t ConfigFile::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:qiuwanli.ConfigFile)
  size_t total_size = 0;

  // repeated .qiuwanli.Config config = 1;
  {
    unsigned int count = this->config_size();
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->config(i));
    }
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void ConfigFile::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:qiuwanli.ConfigFile)
  GOOGLE_DCHECK_NE(&from, this);
  const ConfigFile* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const ConfigFile>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:qiuwanli.ConfigFile)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:qiuwanli.ConfigFile)
    MergeFrom(*source);
  }
}

void ConfigFile::MergeFrom(const ConfigFile& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:qiuwanli.ConfigFile)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  config_.MergeFrom(from.config_);
}

void ConfigFile::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:qiuwanli.ConfigFile)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ConfigFile::CopyFrom(const ConfigFile& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:qiuwanli.ConfigFile)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ConfigFile::IsInitialized() const {
  return true;
}

void ConfigFile::Swap(ConfigFile* other) {
  if (other == this) return;
  InternalSwap(other);
}
void ConfigFile::InternalSwap(ConfigFile* other) {
  config_.UnsafeArenaSwap(&other->config_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata ConfigFile::GetMetadata() const {
  protobuf_config_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_config_2eproto::file_level_metadata[1];
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// ConfigFile

// repeated .qiuwanli.Config config = 1;
int ConfigFile::config_size() const {
  return config_.size();
}
void ConfigFile::clear_config() {
  config_.Clear();
}
const ::qiuwanli::Config& ConfigFile::config(int index) const {
  // @@protoc_insertion_point(field_get:qiuwanli.ConfigFile.config)
  return config_.Get(index);
}
::qiuwanli::Config* ConfigFile::mutable_config(int index) {
  // @@protoc_insertion_point(field_mutable:qiuwanli.ConfigFile.config)
  return config_.Mutable(index);
}
::qiuwanli::Config* ConfigFile::add_config() {
  // @@protoc_insertion_point(field_add:qiuwanli.ConfigFile.config)
  return config_.Add();
}
::google::protobuf::RepeatedPtrField< ::qiuwanli::Config >*
ConfigFile::mutable_config() {
  // @@protoc_insertion_point(field_mutable_list:qiuwanli.ConfigFile.config)
  return &config_;
}
const ::google::protobuf::RepeatedPtrField< ::qiuwanli::Config >&
ConfigFile::config() const {
  // @@protoc_insertion_point(field_list:qiuwanli.ConfigFile.config)
  return config_;
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace qiuwanli

// @@protoc_insertion_point(global_scope)
