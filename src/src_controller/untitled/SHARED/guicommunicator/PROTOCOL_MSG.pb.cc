// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: PROTOCOL_MSG.proto

#include "PROTOCOL_MSG.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
namespace protocolmsg {
class gui2backend_msgDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<gui2backend_msg> _instance;
} _gui2backend_msg_default_instance_;
}  // namespace protocolmsg
static void InitDefaultsscc_info_gui2backend_msg_PROTOCOL_5fMSG_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::protocolmsg::_gui2backend_msg_default_instance_;
    new (ptr) ::protocolmsg::gui2backend_msg();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::protocolmsg::gui2backend_msg::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_gui2backend_msg_PROTOCOL_5fMSG_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_gui2backend_msg_PROTOCOL_5fMSG_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_PROTOCOL_5fMSG_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_PROTOCOL_5fMSG_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_PROTOCOL_5fMSG_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_PROTOCOL_5fMSG_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::protocolmsg::gui2backend_msg, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::protocolmsg::gui2backend_msg, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::protocolmsg::gui2backend_msg, event_),
  PROTOBUF_FIELD_OFFSET(::protocolmsg::gui2backend_msg, type_),
  PROTOBUF_FIELD_OFFSET(::protocolmsg::gui2backend_msg, value_),
  PROTOBUF_FIELD_OFFSET(::protocolmsg::gui2backend_msg, ack_),
  PROTOBUF_FIELD_OFFSET(::protocolmsg::gui2backend_msg, ispageswitchevent_),
  1,
  2,
  0,
  3,
  4,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 10, sizeof(::protocolmsg::gui2backend_msg)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::protocolmsg::_gui2backend_msg_default_instance_),
};

const char descriptor_table_protodef_PROTOCOL_5fMSG_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\022PROTOCOL_MSG.proto\022\013protocolmsg\"w\n\017gui"
  "2backend_msg\022\021\n\005event\030\001 \001(\005:\002-1\022\020\n\004type\030"
  "\002 \001(\005:\002-1\022\017\n\005value\030\003 \001(\t:\000\022\017\n\003ack\030\004 \001(\005:"
  "\002-1\022\035\n\021ispageswitchevent\030\005 \001(\005:\002-1"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_PROTOCOL_5fMSG_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_PROTOCOL_5fMSG_2eproto_sccs[1] = {
  &scc_info_gui2backend_msg_PROTOCOL_5fMSG_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_PROTOCOL_5fMSG_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_PROTOCOL_5fMSG_2eproto = {
  false, false, descriptor_table_protodef_PROTOCOL_5fMSG_2eproto, "PROTOCOL_MSG.proto", 154,
  &descriptor_table_PROTOCOL_5fMSG_2eproto_once, descriptor_table_PROTOCOL_5fMSG_2eproto_sccs, descriptor_table_PROTOCOL_5fMSG_2eproto_deps, 1, 0,
  schemas, file_default_instances, TableStruct_PROTOCOL_5fMSG_2eproto::offsets,
  file_level_metadata_PROTOCOL_5fMSG_2eproto, 1, file_level_enum_descriptors_PROTOCOL_5fMSG_2eproto, file_level_service_descriptors_PROTOCOL_5fMSG_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_PROTOCOL_5fMSG_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_PROTOCOL_5fMSG_2eproto)), true);
namespace protocolmsg {

// ===================================================================

void gui2backend_msg::InitAsDefaultInstance() {
}
class gui2backend_msg::_Internal {
 public:
  using HasBits = decltype(std::declval<gui2backend_msg>()._has_bits_);
  static void set_has_event(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_type(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
  static void set_has_value(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_ack(HasBits* has_bits) {
    (*has_bits)[0] |= 8u;
  }
  static void set_has_ispageswitchevent(HasBits* has_bits) {
    (*has_bits)[0] |= 16u;
  }
};

gui2backend_msg::gui2backend_msg(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:protocolmsg.gui2backend_msg)
}
gui2backend_msg::gui2backend_msg(const gui2backend_msg& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  value_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_value()) {
    value_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_value(),
      GetArena());
  }
  ::memcpy(&event_, &from.event_,
    static_cast<size_t>(reinterpret_cast<char*>(&ispageswitchevent_) -
    reinterpret_cast<char*>(&event_)) + sizeof(ispageswitchevent_));
  // @@protoc_insertion_point(copy_constructor:protocolmsg.gui2backend_msg)
}

void gui2backend_msg::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_gui2backend_msg_PROTOCOL_5fMSG_2eproto.base);
  value_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  event_ = -1;
  type_ = -1;
  ack_ = -1;
  ispageswitchevent_ = -1;
}

gui2backend_msg::~gui2backend_msg() {
  // @@protoc_insertion_point(destructor:protocolmsg.gui2backend_msg)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void gui2backend_msg::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  value_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void gui2backend_msg::ArenaDtor(void* object) {
  gui2backend_msg* _this = reinterpret_cast< gui2backend_msg* >(object);
  (void)_this;
}
void gui2backend_msg::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void gui2backend_msg::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const gui2backend_msg& gui2backend_msg::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_gui2backend_msg_PROTOCOL_5fMSG_2eproto.base);
  return *internal_default_instance();
}


void gui2backend_msg::Clear() {
// @@protoc_insertion_point(message_clear_start:protocolmsg.gui2backend_msg)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x0000001fu) {
    if (cached_has_bits & 0x00000001u) {
      value_.ClearNonDefaultToEmpty();
    }
    event_ = -1;
    type_ = -1;
    ack_ = -1;
    ispageswitchevent_ = -1;
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* gui2backend_msg::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // optional int32 event = 1 [default = -1];
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          _Internal::set_has_event(&has_bits);
          event_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional int32 type = 2 [default = -1];
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          _Internal::set_has_type(&has_bits);
          type_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional string value = 3 [default = ""];
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          auto str = _internal_mutable_value();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "protocolmsg.gui2backend_msg.value");
          #endif  // !NDEBUG
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional int32 ack = 4 [default = -1];
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 32)) {
          _Internal::set_has_ack(&has_bits);
          ack_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional int32 ispageswitchevent = 5 [default = -1];
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 40)) {
          _Internal::set_has_ispageswitchevent(&has_bits);
          ispageswitchevent_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* gui2backend_msg::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:protocolmsg.gui2backend_msg)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional int32 event = 1 [default = -1];
  if (cached_has_bits & 0x00000002u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(1, this->_internal_event(), target);
  }

  // optional int32 type = 2 [default = -1];
  if (cached_has_bits & 0x00000004u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(2, this->_internal_type(), target);
  }

  // optional string value = 3 [default = ""];
  if (cached_has_bits & 0x00000001u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_value().data(), static_cast<int>(this->_internal_value().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "protocolmsg.gui2backend_msg.value");
    target = stream->WriteStringMaybeAliased(
        3, this->_internal_value(), target);
  }

  // optional int32 ack = 4 [default = -1];
  if (cached_has_bits & 0x00000008u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(4, this->_internal_ack(), target);
  }

  // optional int32 ispageswitchevent = 5 [default = -1];
  if (cached_has_bits & 0x00000010u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(5, this->_internal_ispageswitchevent(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:protocolmsg.gui2backend_msg)
  return target;
}

size_t gui2backend_msg::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:protocolmsg.gui2backend_msg)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x0000001fu) {
    // optional string value = 3 [default = ""];
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->_internal_value());
    }

    // optional int32 event = 1 [default = -1];
    if (cached_has_bits & 0x00000002u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
          this->_internal_event());
    }

    // optional int32 type = 2 [default = -1];
    if (cached_has_bits & 0x00000004u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
          this->_internal_type());
    }

    // optional int32 ack = 4 [default = -1];
    if (cached_has_bits & 0x00000008u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
          this->_internal_ack());
    }

    // optional int32 ispageswitchevent = 5 [default = -1];
    if (cached_has_bits & 0x00000010u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
          this->_internal_ispageswitchevent());
    }

  }
  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void gui2backend_msg::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:protocolmsg.gui2backend_msg)
  GOOGLE_DCHECK_NE(&from, this);
  const gui2backend_msg* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<gui2backend_msg>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:protocolmsg.gui2backend_msg)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:protocolmsg.gui2backend_msg)
    MergeFrom(*source);
  }
}

void gui2backend_msg::MergeFrom(const gui2backend_msg& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:protocolmsg.gui2backend_msg)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x0000001fu) {
    if (cached_has_bits & 0x00000001u) {
      _internal_set_value(from._internal_value());
    }
    if (cached_has_bits & 0x00000002u) {
      event_ = from.event_;
    }
    if (cached_has_bits & 0x00000004u) {
      type_ = from.type_;
    }
    if (cached_has_bits & 0x00000008u) {
      ack_ = from.ack_;
    }
    if (cached_has_bits & 0x00000010u) {
      ispageswitchevent_ = from.ispageswitchevent_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void gui2backend_msg::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:protocolmsg.gui2backend_msg)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void gui2backend_msg::CopyFrom(const gui2backend_msg& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:protocolmsg.gui2backend_msg)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool gui2backend_msg::IsInitialized() const {
  return true;
}

void gui2backend_msg::InternalSwap(gui2backend_msg* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  value_.Swap(&other->value_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  swap(event_, other->event_);
  swap(type_, other->type_);
  swap(ack_, other->ack_);
  swap(ispageswitchevent_, other->ispageswitchevent_);
}

::PROTOBUF_NAMESPACE_ID::Metadata gui2backend_msg::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace protocolmsg
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::protocolmsg::gui2backend_msg* Arena::CreateMaybeMessage< ::protocolmsg::gui2backend_msg >(Arena* arena) {
  return Arena::CreateMessageInternal< ::protocolmsg::gui2backend_msg >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
