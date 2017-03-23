// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: fffff.proto

#ifndef PROTOBUF_fffff_2eproto__INCLUDED
#define PROTOBUF_fffff_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3002000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3002000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
namespace qiuwanli {
class ConfigFile;
class ConfigFileDefaultTypeInternal;
extern ConfigFileDefaultTypeInternal _ConfigFile_default_instance_;
}  // namespace qiuwanli

namespace qiuwanli {

namespace protobuf_fffff_2eproto {
// Internal implementation detail -- do not call these.
struct TableStruct {
  static const ::google::protobuf::uint32 offsets[];
  static void InitDefaultsImpl();
  static void Shutdown();
};
void AddDescriptors();
void InitDefaults();
}  // namespace protobuf_fffff_2eproto

// ===================================================================

class ConfigFile : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:qiuwanli.ConfigFile) */ {
 public:
  ConfigFile();
  virtual ~ConfigFile();

  ConfigFile(const ConfigFile& from);

  inline ConfigFile& operator=(const ConfigFile& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const ConfigFile& default_instance();

  static inline const ConfigFile* internal_default_instance() {
    return reinterpret_cast<const ConfigFile*>(
               &_ConfigFile_default_instance_);
  }

  void Swap(ConfigFile* other);

  // implements Message ----------------------------------------------

  inline ConfigFile* New() const PROTOBUF_FINAL { return New(NULL); }

  ConfigFile* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const ConfigFile& from);
  void MergeFrom(const ConfigFile& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output)
      const PROTOBUF_FINAL {
    return InternalSerializeWithCachedSizesToArray(
        ::google::protobuf::io::CodedOutputStream::IsDefaultSerializationDeterministic(), output);
  }
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(ConfigFile* other);
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

  // repeated string config = 1;
  int config_size() const;
  void clear_config();
  static const int kConfigFieldNumber = 1;
  const ::std::string& config(int index) const;
  ::std::string* mutable_config(int index);
  void set_config(int index, const ::std::string& value);
  void set_config(int index, const char* value);
  void set_config(int index, const char* value, size_t size);
  ::std::string* add_config();
  void add_config(const ::std::string& value);
  void add_config(const char* value);
  void add_config(const char* value, size_t size);
  const ::google::protobuf::RepeatedPtrField< ::std::string>& config() const;
  ::google::protobuf::RepeatedPtrField< ::std::string>* mutable_config();

  // @@protoc_insertion_point(class_scope:qiuwanli.ConfigFile)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::std::string> config_;
  mutable int _cached_size_;
  friend struct  protobuf_fffff_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// ConfigFile

// repeated string config = 1;
inline int ConfigFile::config_size() const {
  return config_.size();
}
inline void ConfigFile::clear_config() {
  config_.Clear();
}
inline const ::std::string& ConfigFile::config(int index) const {
  // @@protoc_insertion_point(field_get:qiuwanli.ConfigFile.config)
  return config_.Get(index);
}
inline ::std::string* ConfigFile::mutable_config(int index) {
  // @@protoc_insertion_point(field_mutable:qiuwanli.ConfigFile.config)
  return config_.Mutable(index);
}
inline void ConfigFile::set_config(int index, const ::std::string& value) {
  // @@protoc_insertion_point(field_set:qiuwanli.ConfigFile.config)
  config_.Mutable(index)->assign(value);
}
inline void ConfigFile::set_config(int index, const char* value) {
  config_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:qiuwanli.ConfigFile.config)
}
inline void ConfigFile::set_config(int index, const char* value, size_t size) {
  config_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:qiuwanli.ConfigFile.config)
}
inline ::std::string* ConfigFile::add_config() {
  // @@protoc_insertion_point(field_add_mutable:qiuwanli.ConfigFile.config)
  return config_.Add();
}
inline void ConfigFile::add_config(const ::std::string& value) {
  config_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:qiuwanli.ConfigFile.config)
}
inline void ConfigFile::add_config(const char* value) {
  config_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:qiuwanli.ConfigFile.config)
}
inline void ConfigFile::add_config(const char* value, size_t size) {
  config_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:qiuwanli.ConfigFile.config)
}
inline const ::google::protobuf::RepeatedPtrField< ::std::string>&
ConfigFile::config() const {
  // @@protoc_insertion_point(field_list:qiuwanli.ConfigFile.config)
  return config_;
}
inline ::google::protobuf::RepeatedPtrField< ::std::string>*
ConfigFile::mutable_config() {
  // @@protoc_insertion_point(field_mutable_list:qiuwanli.ConfigFile.config)
  return &config_;
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)


}  // namespace qiuwanli

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_fffff_2eproto__INCLUDED
