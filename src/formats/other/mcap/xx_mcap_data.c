/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * mcap data structures, moved out of the binaryextra schema family. */
#include "../../xx_format_schema_binaryextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxbx_mcap_magic_fields[] = {
 SX_FIELD("magic","uint8[8]",0,8,SX_SIGNATURE),
};
const sx_layout sxbx_mcap_magic = {UINT32_C(0x6030000d),"mcap_magic",sxbx_mcap_magic_fields,SX_COUNT(sxbx_mcap_magic_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_mcap_record_header_fields[] = {
 SX_FIELD("opcode","uint8",0,1,SX_ID),
 SX_FIELD("payload_size","uint64",1,8,SX_SIZE),
};
const sx_layout sxbx_mcap_record_header = {UINT32_C(0x6030000e),"mcap_record_header",sxbx_mcap_record_header_fields,SX_COUNT(sxbx_mcap_record_header_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_mcap_schema_id_fields[] = {
 SX_FIELD("schema_id","uint16",0,2,SX_ID),
};
const sx_layout sxbx_mcap_schema_id = {UINT32_C(0x6030000f),"mcap_schema_id",sxbx_mcap_schema_id_fields,SX_COUNT(sxbx_mcap_schema_id_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_mcap_channel_ids_fields[] = {
 SX_FIELD("channel_id","uint16",0,2,SX_ID),
 SX_FIELD("schema_id","uint16",2,2,SX_ID),
};
const sx_layout sxbx_mcap_channel_ids = {UINT32_C(0x60300010),"mcap_channel_ids",sxbx_mcap_channel_ids_fields,SX_COUNT(sxbx_mcap_channel_ids_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_mcap_message_fields[] = {
 SX_FIELD("channel_id","uint16",0,2,SX_ID),
 SX_FIELD("sequence","uint32",2,4,SX_NONE),
 SX_FIELD("log_time","uint64",6,8,SX_NONE),
 SX_FIELD("publish_time","uint64",14,8,SX_NONE),
};
const sx_layout sxbx_mcap_message = {UINT32_C(0x60300011),"mcap_message",sxbx_mcap_message_fields,SX_COUNT(sxbx_mcap_message_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_mcap_attachment_times_fields[] = {
 SX_FIELD("log_time","uint64",0,8,SX_NONE),
 SX_FIELD("create_time","uint64",8,8,SX_NONE),
};
const sx_layout sxbx_mcap_attachment_times = {UINT32_C(0x60300012),"mcap_attachment_times",sxbx_mcap_attachment_times_fields,SX_COUNT(sxbx_mcap_attachment_times_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_mcap_footer_fields[] = {
 SX_FIELD("summary_start","uint64",0,8,SX_OFFSET),
 SX_FIELD("summary_offset_start","uint64",8,8,SX_OFFSET),
 SX_FIELD("summary_crc","uint32",16,4,SX_CHECKSUM),
};
const sx_layout sxbx_mcap_footer = {UINT32_C(0x60300013),"mcap_footer",sxbx_mcap_footer_fields,SX_COUNT(sxbx_mcap_footer_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_mcap_crc_fields[] = {
 SX_FIELD("crc32","uint32",0,4,SX_CHECKSUM),
};
const sx_layout sxbx_mcap_crc = {UINT32_C(0x60300014),"mcap_crc",sxbx_mcap_crc_fields,SX_COUNT(sxbx_mcap_crc_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_mcap_map_size_fields[] = {
 SX_FIELD("map_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxbx_mcap_map_size = {UINT32_C(0x60300015),"mcap_map_size",sxbx_mcap_map_size_fields,SX_COUNT(sxbx_mcap_map_size_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_mcap_string_size_fields[] = {
 SX_FIELD("byte_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxbx_mcap_string_size = {UINT32_C(0x60300016),"mcap_string_size",sxbx_mcap_string_size_fields,SX_COUNT(sxbx_mcap_string_size_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_mcap_data_size_fields[] = {
 SX_FIELD("byte_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxbx_mcap_data_size = {UINT32_C(0x60300017),"mcap_data_size",sxbx_mcap_data_size_fields,SX_COUNT(sxbx_mcap_data_size_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_mcap_attachment_size_fields[] = {
 SX_FIELD("byte_size","uint64",0,8,SX_SIZE),
};
const sx_layout sxbx_mcap_attachment_size = {UINT32_C(0x60300018),"mcap_attachment_size",sxbx_mcap_attachment_size_fields,SX_COUNT(sxbx_mcap_attachment_size_fields),SX_LE};
#define SXBX_LIMIT 20000U
static bool sxbx_mcap_map(sx_context*c,uint64_t*p,uint64_t end){uint64_t z;if(*p>end||end-*p<4||!sxbx_word(c,*p,4,false,&z)||z>end-*p-4||!sxbx_add(c,&sxbx_mcap_map_size,*p))return false;*p+=4;uint64_t stop=*p+z;for(unsigned i=0;*p<stop&&i<128;i++)if(!sxbx_counted(c,p,stop,&sxbx_mcap_string_size,4,false,1)||!sxbx_counted(c,p,stop,&sxbx_mcap_string_size,4,false,1))return false;return *p==stop;}
static bool sxbx_mcap(sx_context*c){uint8_t b[9];uint64_t p=8;if(!sxbx_add(c,&sxbx_mcap_magic,0))return false;while(c->count<SXBX_LIMIT&&p<(uint64_t)c->size){if(sxbx_read(c,p,b,8)&&!xx_rt_memcmp(b,"\x89MCAP0\r\n",8)){return sxbx_add(c,&sxbx_mcap_magic,p);}if(!sxbx_read(c,p,b,9))break;uint64_t z=sxbx_uint(b+1,8,false);if(!sxbx_span(c,p+9,z))break;if(!sxbx_add(c,&sxbx_mcap_record_header,p))return false;uint64_t q=p+9,end=q+z;size_t keep=c->count;bool ok=true;
 switch(b[0]){case 1:ok=sxbx_counted(c,&q,end,&sxbx_mcap_string_size,4,false,1)&&sxbx_counted(c,&q,end,&sxbx_mcap_string_size,4,false,1);break;
 case 2:ok=z==20&&sxbx_add(c,&sxbx_mcap_footer,q);break;
 case 3:ok=z>=2&&sxbx_add(c,&sxbx_mcap_schema_id,q);q+=2;ok=ok&&sxbx_counted(c,&q,end,&sxbx_mcap_string_size,4,false,1)&&sxbx_counted(c,&q,end,&sxbx_mcap_string_size,4,false,1)&&sxbx_counted(c,&q,end,&sxbx_mcap_data_size,4,false,1);break;
 case 4:ok=z>=4&&sxbx_add(c,&sxbx_mcap_channel_ids,q);q+=4;ok=ok&&sxbx_counted(c,&q,end,&sxbx_mcap_string_size,4,false,1)&&sxbx_counted(c,&q,end,&sxbx_mcap_string_size,4,false,1)&&sxbx_mcap_map(c,&q,end);break;
 case 5:ok=z>=22&&sxbx_add(c,&sxbx_mcap_message,q);break;
 case 9:ok=z>=16&&sxbx_add(c,&sxbx_mcap_attachment_times,q);q+=16;ok=ok&&sxbx_counted(c,&q,end,&sxbx_mcap_string_size,4,false,1)&&sxbx_counted(c,&q,end,&sxbx_mcap_string_size,4,false,1)&&sxbx_counted(c,&q,end,&sxbx_mcap_attachment_size,8,false,1)&&end-q==4&&sxbx_add(c,&sxbx_mcap_crc,q);break;
 case 12:ok=sxbx_counted(c,&q,end,&sxbx_mcap_string_size,4,false,1)&&sxbx_mcap_map(c,&q,end);break;
 case 15:ok=z==4&&sxbx_add(c,&sxbx_mcap_crc,q);break;default:break;}if(!ok)c->count=keep;p=end;}return true;}
bool sx_mcap_build(sx_context*c)
{
 return sxbx_mcap(c);
}
