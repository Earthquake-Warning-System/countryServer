/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: interface.proto */

/* Do not generate deprecated warnings for self */
#ifndef PROTOBUF_C__NO_DEPRECATED
#define PROTOBUF_C__NO_DEPRECATED
#endif

#include "interface.pb-c.h"
void   kp_alive__init
                     (KpAlive         *message)
{
  static const KpAlive init_value = KP_ALIVE__INIT;
  *message = init_value;
}
size_t kp_alive__get_packed_size
                     (const KpAlive *message)
{
  assert(message->base.descriptor == &kp_alive__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t kp_alive__pack
                     (const KpAlive *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &kp_alive__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t kp_alive__pack_to_buffer
                     (const KpAlive *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &kp_alive__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
KpAlive *
       kp_alive__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (KpAlive *)
     protobuf_c_message_unpack (&kp_alive__descriptor,
                                allocator, len, data);
}
void   kp_alive__free_unpacked
                     (KpAlive *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &kp_alive__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   eq_event__init
                     (EQEvent         *message)
{
  static const EQEvent init_value = EQ_EVENT__INIT;
  *message = init_value;
}
size_t eq_event__get_packed_size
                     (const EQEvent *message)
{
  assert(message->base.descriptor == &eq_event__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t eq_event__pack
                     (const EQEvent *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &eq_event__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t eq_event__pack_to_buffer
                     (const EQEvent *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &eq_event__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
EQEvent *
       eq_event__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (EQEvent *)
     protobuf_c_message_unpack (&eq_event__descriptor,
                                allocator, len, data);
}
void   eq_event__free_unpacked
                     (EQEvent *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &eq_event__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   eq_occur__init
                     (EQOccur         *message)
{
  static const EQOccur init_value = EQ_OCCUR__INIT;
  *message = init_value;
}
size_t eq_occur__get_packed_size
                     (const EQOccur *message)
{
  assert(message->base.descriptor == &eq_occur__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t eq_occur__pack
                     (const EQOccur *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &eq_occur__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t eq_occur__pack_to_buffer
                     (const EQOccur *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &eq_occur__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
EQOccur *
       eq_occur__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (EQOccur *)
     protobuf_c_message_unpack (&eq_occur__descriptor,
                                allocator, len, data);
}
void   eq_occur__free_unpacked
                     (EQOccur *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &eq_occur__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   boot_ask__init
                     (BootAsk         *message)
{
  static const BootAsk init_value = BOOT_ASK__INIT;
  *message = init_value;
}
size_t boot_ask__get_packed_size
                     (const BootAsk *message)
{
  assert(message->base.descriptor == &boot_ask__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t boot_ask__pack
                     (const BootAsk *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &boot_ask__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t boot_ask__pack_to_buffer
                     (const BootAsk *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &boot_ask__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
BootAsk *
       boot_ask__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (BootAsk *)
     protobuf_c_message_unpack (&boot_ask__descriptor,
                                allocator, len, data);
}
void   boot_ask__free_unpacked
                     (BootAsk *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &boot_ask__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   boot_kp__init
                     (BootKp         *message)
{
  static const BootKp init_value = BOOT_KP__INIT;
  *message = init_value;
}
size_t boot_kp__get_packed_size
                     (const BootKp *message)
{
  assert(message->base.descriptor == &boot_kp__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t boot_kp__pack
                     (const BootKp *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &boot_kp__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t boot_kp__pack_to_buffer
                     (const BootKp *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &boot_kp__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
BootKp *
       boot_kp__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (BootKp *)
     protobuf_c_message_unpack (&boot_kp__descriptor,
                                allocator, len, data);
}
void   boot_kp__free_unpacked
                     (BootKp *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &boot_kp__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   kp_alive_ack__init
                     (KpAliveAck         *message)
{
  static const KpAliveAck init_value = KP_ALIVE_ACK__INIT;
  *message = init_value;
}
size_t kp_alive_ack__get_packed_size
                     (const KpAliveAck *message)
{
  assert(message->base.descriptor == &kp_alive_ack__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t kp_alive_ack__pack
                     (const KpAliveAck *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &kp_alive_ack__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t kp_alive_ack__pack_to_buffer
                     (const KpAliveAck *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &kp_alive_ack__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
KpAliveAck *
       kp_alive_ack__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (KpAliveAck *)
     protobuf_c_message_unpack (&kp_alive_ack__descriptor,
                                allocator, len, data);
}
void   kp_alive_ack__free_unpacked
                     (KpAliveAck *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &kp_alive_ack__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   packet_type__init
                     (PacketType         *message)
{
  static const PacketType init_value = PACKET_TYPE__INIT;
  *message = init_value;
}
size_t packet_type__get_packed_size
                     (const PacketType *message)
{
  assert(message->base.descriptor == &packet_type__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t packet_type__pack
                     (const PacketType *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &packet_type__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t packet_type__pack_to_buffer
                     (const PacketType *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &packet_type__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
PacketType *
       packet_type__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (PacketType *)
     protobuf_c_message_unpack (&packet_type__descriptor,
                                allocator, len, data);
}
void   packet_type__free_unpacked
                     (PacketType *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &packet_type__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
static const ProtobufCFieldDescriptor kp_alive__field_descriptors[6] =
{
  {
    "packet_type",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(KpAlive, packet_type),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "sensor_id",
    2,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(KpAlive, sensor_id),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "alive_flag",
    3,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    offsetof(KpAlive, alive_flag),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "country_code",
    4,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(KpAlive, country_code),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "city_code",
    5,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(KpAlive, city_code),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "version",
    6,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(KpAlive, version),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned kp_alive__field_indices_by_name[] = {
  2,   /* field[2] = alive_flag */
  4,   /* field[4] = city_code */
  3,   /* field[3] = country_code */
  0,   /* field[0] = packet_type */
  1,   /* field[1] = sensor_id */
  5,   /* field[5] = version */
};
static const ProtobufCIntRange kp_alive__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 6 }
};
const ProtobufCMessageDescriptor kp_alive__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "kp_alive",
  "KpAlive",
  "KpAlive",
  "",
  sizeof(KpAlive),
  6,
  kp_alive__field_descriptors,
  kp_alive__field_indices_by_name,
  1,  kp_alive__number_ranges,
  (ProtobufCMessageInit) kp_alive__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor eq_event__field_descriptors[6] =
{
  {
    "packet_type",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(EQEvent, packet_type),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "sensor_id",
    2,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(EQEvent, sensor_id),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "event_output",
    3,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    offsetof(EQEvent, event_output),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "event_sec",
    4,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_INT64,
    0,   /* quantifier_offset */
    offsetof(EQEvent, event_sec),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "event_usec",
    5,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_INT64,
    0,   /* quantifier_offset */
    offsetof(EQEvent, event_usec),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "version",
    6,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(EQEvent, version),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned eq_event__field_indices_by_name[] = {
  2,   /* field[2] = event_output */
  3,   /* field[3] = event_sec */
  4,   /* field[4] = event_usec */
  0,   /* field[0] = packet_type */
  1,   /* field[1] = sensor_id */
  5,   /* field[5] = version */
};
static const ProtobufCIntRange eq_event__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 6 }
};
const ProtobufCMessageDescriptor eq_event__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "EQ_event",
  "EQEvent",
  "EQEvent",
  "",
  sizeof(EQEvent),
  6,
  eq_event__field_descriptors,
  eq_event__field_indices_by_name,
  1,  eq_event__number_ranges,
  (ProtobufCMessageInit) eq_event__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor eq_occur__field_descriptors[3] =
{
  {
    "packet_type",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(EQOccur, packet_type),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "information",
    2,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(EQOccur, information),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "version",
    3,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(EQOccur, version),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned eq_occur__field_indices_by_name[] = {
  1,   /* field[1] = information */
  0,   /* field[0] = packet_type */
  2,   /* field[2] = version */
};
static const ProtobufCIntRange eq_occur__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 3 }
};
const ProtobufCMessageDescriptor eq_occur__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "EQ_occur",
  "EQOccur",
  "EQOccur",
  "",
  sizeof(EQOccur),
  3,
  eq_occur__field_descriptors,
  eq_occur__field_indices_by_name,
  1,  eq_occur__number_ranges,
  (ProtobufCMessageInit) eq_occur__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor boot_ask__field_descriptors[4] =
{
  {
    "packet_type",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(BootAsk, packet_type),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "server_ip",
    2,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(BootAsk, server_ip),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "server_port",
    3,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_INT32,
    0,   /* quantifier_offset */
    offsetof(BootAsk, server_port),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "version",
    4,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(BootAsk, version),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned boot_ask__field_indices_by_name[] = {
  0,   /* field[0] = packet_type */
  1,   /* field[1] = server_ip */
  2,   /* field[2] = server_port */
  3,   /* field[3] = version */
};
static const ProtobufCIntRange boot_ask__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 4 }
};
const ProtobufCMessageDescriptor boot_ask__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "Boot_ask",
  "BootAsk",
  "BootAsk",
  "",
  sizeof(BootAsk),
  4,
  boot_ask__field_descriptors,
  boot_ask__field_indices_by_name,
  1,  boot_ask__number_ranges,
  (ProtobufCMessageInit) boot_ask__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor boot_kp__field_descriptors[4] =
{
  {
    "packet_type",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(BootKp, packet_type),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "server_ID",
    2,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(BootKp, server_id),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "token",
    3,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(BootKp, token),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "version",
    4,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(BootKp, version),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned boot_kp__field_indices_by_name[] = {
  0,   /* field[0] = packet_type */
  1,   /* field[1] = server_ID */
  2,   /* field[2] = token */
  3,   /* field[3] = version */
};
static const ProtobufCIntRange boot_kp__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 4 }
};
const ProtobufCMessageDescriptor boot_kp__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "Boot_kp",
  "BootKp",
  "BootKp",
  "",
  sizeof(BootKp),
  4,
  boot_kp__field_descriptors,
  boot_kp__field_indices_by_name,
  1,  boot_kp__number_ranges,
  (ProtobufCMessageInit) boot_kp__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor kp_alive_ack__field_descriptors[4] =
{
  {
    "packet_type",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(KpAliveAck, packet_type),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "role",
    2,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    offsetof(KpAliveAck, role),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "server_id",
    3,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(KpAliveAck, server_id),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "version",
    4,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(KpAliveAck, version),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned kp_alive_ack__field_indices_by_name[] = {
  0,   /* field[0] = packet_type */
  1,   /* field[1] = role */
  2,   /* field[2] = server_id */
  3,   /* field[3] = version */
};
static const ProtobufCIntRange kp_alive_ack__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 4 }
};
const ProtobufCMessageDescriptor kp_alive_ack__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "kp_alive_ack",
  "KpAliveAck",
  "KpAliveAck",
  "",
  sizeof(KpAliveAck),
  4,
  kp_alive_ack__field_descriptors,
  kp_alive_ack__field_indices_by_name,
  1,  kp_alive_ack__number_ranges,
  (ProtobufCMessageInit) kp_alive_ack__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor packet_type__field_descriptors[1] =
{
  {
    "packet_type",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(PacketType, packet_type),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned packet_type__field_indices_by_name[] = {
  0,   /* field[0] = packet_type */
};
static const ProtobufCIntRange packet_type__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 1 }
};
const ProtobufCMessageDescriptor packet_type__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "packet_type",
  "PacketType",
  "PacketType",
  "",
  sizeof(PacketType),
  1,
  packet_type__field_descriptors,
  packet_type__field_indices_by_name,
  1,  packet_type__number_ranges,
  (ProtobufCMessageInit) packet_type__init,
  NULL,NULL,NULL    /* reserved[123] */
};
