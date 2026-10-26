/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * PEA data structures, moved out of the archivelater schema family. */
#include "../../xx_format_schema_archivelater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxal_pea_header_fields[] = {
 SX_FIELD("signature","uint8",0,1,SX_SIGNATURE),
 SX_FIELD("version","uint8",1,1,SX_ID),
 SX_FIELD("revision","uint8",2,1,SX_ID),
 SX_FIELD("volume_control","uint8",3,1,SX_ID),
 SX_FIELD("writer_data","uint8[4]",4,4,SX_NONE),
 SX_FIELD("byte_order_flags","uint8",8,1,SX_FLAGS),
 SX_FIELD("writer_data9","uint8",9,1,SX_NONE),
};
const sx_layout sxal_pea_header = {UINT32_C(0x6020000e),"pea_header",sxal_pea_header_fields,SX_COUNT(sxal_pea_header_fields),SX_LE};
static const xx_data_struct_field_desc sxal_pea_trigger_le_fields[] = {
 SX_FIELD("zero_name_size","uint16",0,2,SX_SIZE),
 SX_FIELD("signature","char[4]",2,4,SX_SIGNATURE),
};
const sx_layout sxal_pea_trigger_le = {UINT32_C(0x6020000f),"pea_trigger_le",sxal_pea_trigger_le_fields,SX_COUNT(sxal_pea_trigger_le_fields),SX_LE};
static const xx_data_struct_field_desc sxal_pea_stream_le_fields[] = {
 SX_FIELD("compression","uint8",0,1,SX_ID),
 SX_FIELD("reserved","uint8",1,1,SX_RESERVED),
 SX_FIELD("stream_control","uint8",2,1,SX_ID),
 SX_FIELD("object_control","uint8",3,1,SX_ID),
};
const sx_layout sxal_pea_stream_le = {UINT32_C(0x60200010),"pea_stream_le",sxal_pea_stream_le_fields,SX_COUNT(sxal_pea_stream_le_fields),SX_LE};
static const xx_data_struct_field_desc sxal_pea_block_size_le_fields[] = {
 SX_FIELD("block_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxal_pea_block_size_le = {UINT32_C(0x60200011),"pea_block_size_le",sxal_pea_block_size_le_fields,SX_COUNT(sxal_pea_block_size_le_fields),SX_LE};
static const xx_data_struct_field_desc sxal_pea_name_size_le_fields[] = {
 SX_FIELD("name_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxal_pea_name_size_le = {UINT32_C(0x60200012),"pea_name_size_le",sxal_pea_name_size_le_fields,SX_COUNT(sxal_pea_name_size_le_fields),SX_LE};
static const xx_data_struct_field_desc sxal_pea_object_le_fields[] = {
 SX_FIELD("modified","uint32",0,4,SX_NONE),
 SX_FIELD("attributes","uint32",4,4,SX_FLAGS),
};
const sx_layout sxal_pea_object_le = {UINT32_C(0x60200013),"pea_object_le",sxal_pea_object_le_fields,SX_COUNT(sxal_pea_object_le_fields),SX_LE};
static const xx_data_struct_field_desc sxal_pea_file_size_le_fields[] = {
 SX_FIELD("unpacked_size","uint64",0,8,SX_SIZE),
};
const sx_layout sxal_pea_file_size_le = {UINT32_C(0x60200014),"pea_file_size_le",sxal_pea_file_size_le_fields,SX_COUNT(sxal_pea_file_size_le_fields),SX_LE};
static const xx_data_struct_field_desc sxal_pea_packed_size_le_fields[] = {
 SX_FIELD("packed_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxal_pea_packed_size_le = {UINT32_C(0x60200015),"pea_packed_size_le",sxal_pea_packed_size_le_fields,SX_COUNT(sxal_pea_packed_size_le_fields),SX_LE};
static const xx_data_struct_field_desc sxal_pea_last_size_le_fields[] = {
 SX_FIELD("repeated_last_block_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxal_pea_last_size_le = {UINT32_C(0x60200016),"pea_last_size_le",sxal_pea_last_size_le_fields,SX_COUNT(sxal_pea_last_size_le_fields),SX_LE};
static const xx_data_struct_field_desc sxal_pea_trigger_be_fields[] = {
 SX_FIELD("zero_name_size","uint16",0,2,SX_SIZE),
 SX_FIELD("signature","char[4]",2,4,SX_SIGNATURE),
};
const sx_layout sxal_pea_trigger_be = {UINT32_C(0x60200017),"pea_trigger_be",sxal_pea_trigger_be_fields,SX_COUNT(sxal_pea_trigger_be_fields),SX_BE};
static const xx_data_struct_field_desc sxal_pea_stream_be_fields[] = {
 SX_FIELD("compression","uint8",0,1,SX_ID),
 SX_FIELD("reserved","uint8",1,1,SX_RESERVED),
 SX_FIELD("stream_control","uint8",2,1,SX_ID),
 SX_FIELD("object_control","uint8",3,1,SX_ID),
};
const sx_layout sxal_pea_stream_be = {UINT32_C(0x60200018),"pea_stream_be",sxal_pea_stream_be_fields,SX_COUNT(sxal_pea_stream_be_fields),SX_BE};
static const xx_data_struct_field_desc sxal_pea_block_size_be_fields[] = {
 SX_FIELD("block_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxal_pea_block_size_be = {UINT32_C(0x60200019),"pea_block_size_be",sxal_pea_block_size_be_fields,SX_COUNT(sxal_pea_block_size_be_fields),SX_BE};
static const xx_data_struct_field_desc sxal_pea_name_size_be_fields[] = {
 SX_FIELD("name_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxal_pea_name_size_be = {UINT32_C(0x6020001a),"pea_name_size_be",sxal_pea_name_size_be_fields,SX_COUNT(sxal_pea_name_size_be_fields),SX_BE};
static const xx_data_struct_field_desc sxal_pea_object_be_fields[] = {
 SX_FIELD("modified","uint32",0,4,SX_NONE),
 SX_FIELD("attributes","uint32",4,4,SX_FLAGS),
};
const sx_layout sxal_pea_object_be = {UINT32_C(0x6020001b),"pea_object_be",sxal_pea_object_be_fields,SX_COUNT(sxal_pea_object_be_fields),SX_BE};
static const xx_data_struct_field_desc sxal_pea_file_size_be_fields[] = {
 SX_FIELD("unpacked_size","uint64",0,8,SX_SIZE),
};
const sx_layout sxal_pea_file_size_be = {UINT32_C(0x6020001c),"pea_file_size_be",sxal_pea_file_size_be_fields,SX_COUNT(sxal_pea_file_size_be_fields),SX_BE};
static const xx_data_struct_field_desc sxal_pea_packed_size_be_fields[] = {
 SX_FIELD("packed_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxal_pea_packed_size_be = {UINT32_C(0x6020001d),"pea_packed_size_be",sxal_pea_packed_size_be_fields,SX_COUNT(sxal_pea_packed_size_be_fields),SX_BE};
static const xx_data_struct_field_desc sxal_pea_last_size_be_fields[] = {
 SX_FIELD("repeated_last_block_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxal_pea_last_size_be = {UINT32_C(0x6020001e),"pea_last_size_be",sxal_pea_last_size_be_fields,SX_COUNT(sxal_pea_last_size_be_fields),SX_BE};
static int sxal_pea_tag(unsigned v){if(v==0)return 0;if(v==1||v==2)return 4;if(v==3)return 8;if(v==0x10)return 16;if(v==0x11||v==0x12)return 20;if(v==0x13||v==0x16||v==0x18)return 32;if(v==0x14||v==0x15||v==0x17||v==0x19)return 64;return -1;}
static bool sxal_pea(sx_context *c){uint8_t b[24];if(!sxal_read(c,0,b,20)||!sxal_add(c,&sxal_pea_header,0))return false;bool be=(b[8]&128)!=0;unsigned compression=b[16];int volume=sxal_pea_tag(b[3]),stream=sxal_pea_tag(b[18]),object=sxal_pea_tag(b[19]);uint64_t p=20,block=0;
 if(!sxal_add(c,be?&sxal_pea_trigger_be:&sxal_pea_trigger_le,10)||!sxal_add(c,be?&sxal_pea_stream_be:&sxal_pea_stream_le,16))return false;if(stream<0||object<0||volume<0)return true;
 if(compression){if(!sxal_read(c,p,b,4))return true;block=sxal32(b,be);if(!sxal_add(c,be?&sxal_pea_block_size_be:&sxal_pea_block_size_le,p))return false;p+=4;if(block<1024||block>33554432)return true;}
 for(unsigned i=0;i<SXAL_LIMIT&&p<(uint64_t)c->size;i++){if(!sxal_read(c,p,b,2))break;unsigned name=sxal16(b,be);if(!name){if(sxal_read(c,p,b,6)&&!xx_rt_memcmp(b+2,"EOA\0",4)&&!sxal_add(c,be?&sxal_pea_trigger_be:&sxal_pea_trigger_le,p))return false;break;}
  if(!sxal_span(c,p+2,name+8U))break;if(!sxal_add(c,be?&sxal_pea_name_size_be:&sxal_pea_name_size_le,p))return false;p+=2+name;if(!sxal_read(c,p,b,8)||!sxal_add(c,be?&sxal_pea_object_be:&sxal_pea_object_le,p))return false;bool folder=(sxal32(b+4,be)&16)!=0;p+=8;uint64_t n=0;
  if(!folder){if(!sxal_read(c,p,b,8))break;n=sxal_uint(b,8,be);if(!sxal_add(c,be?&sxal_pea_file_size_be:&sxal_pea_file_size_le,p))return false;p+=8;}
  if(!compression){if(!sxal_span(c,p,n))break;p+=n;}else{uint64_t left=n;unsigned steps=0;while(left&&steps++<SXAL_LIMIT){if(!sxal_read(c,p,b,4))return true;uint64_t z=sxal32(b,be),plain=left>block?block:left;if(!z||z>plain||!sxal_span(c,p+4,z))return true;if(!sxal_add(c,be?&sxal_pea_packed_size_be:&sxal_pea_packed_size_le,p))return false;p+=4+z;left-=plain;}if(left)return true;if(n){if(!sxal_span(c,p,4))break;if(!sxal_add(c,be?&sxal_pea_last_size_be:&sxal_pea_last_size_le,p))return false;p+=4;}}
  if(!sxal_span(c,p,(uint64_t)object))break;p+=(uint64_t)object;
 }return true;}
bool sx_pea_build(sx_context*c)
{
 return sxal_pea(c);
}
