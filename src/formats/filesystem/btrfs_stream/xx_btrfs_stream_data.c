/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Btrfs Stream data structures, moved out of the volumeimages schema family. */
#include "../../xx_format_schema_volumeimages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxvi_btrfs_send_header_fields[] = {
    SX_FIELD("magic","char[13]",0,13,SX_SIGNATURE),
    SX_FIELD("version","uint32",13,4,SX_ID),
};
const sx_layout sxvi_btrfs_send_header = {0x60530024U,"btrfs_send_header",sxvi_btrfs_send_header_fields,SX_COUNT(sxvi_btrfs_send_header_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_btrfs_send_command_fields[] = {
    SX_FIELD("payload_size","uint32",0,4,SX_SIZE),
    SX_FIELD("command","uint16",4,2,SX_ID),
    SX_FIELD("crc32c","uint32",6,4,SX_CHECKSUM),
};
const sx_layout sxvi_btrfs_send_command = {0x60530025U,"btrfs_send_command",sxvi_btrfs_send_command_fields,SX_COUNT(sxvi_btrfs_send_command_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_btrfs_send_attribute_fields[] = {
    SX_FIELD("type","uint16",0,2,SX_ID),
    SX_FIELD("value_size","uint16",2,2,SX_SIZE),
};
const sx_layout sxvi_btrfs_send_attribute = {0x60530026U,"btrfs_send_attribute",sxvi_btrfs_send_attribute_fields,SX_COUNT(sxvi_btrfs_send_attribute_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_btrfs_send_data_attribute_v2_fields[] = {
    SX_FIELD("type","uint16",0,2,SX_ID),
};
const sx_layout sxvi_btrfs_send_data_attribute_v2 = {0x60530027U,"btrfs_send_data_attribute_v2",sxvi_btrfs_send_data_attribute_v2_fields,SX_COUNT(sxvi_btrfs_send_data_attribute_v2_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_btrfs_send_uuid_fields[] = {
    SX_FIELD("uuid","byte[16]",0,16,SX_ID),
};
const sx_layout sxvi_btrfs_send_uuid = {0x60530028U,"btrfs_send_uuid",sxvi_btrfs_send_uuid_fields,SX_COUNT(sxvi_btrfs_send_uuid_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_btrfs_send_id64_fields[] = {
    SX_FIELD("value","uint64",0,8,SX_ID),
};
const sx_layout sxvi_btrfs_send_id64 = {0x60530029U,"btrfs_send_id64",sxvi_btrfs_send_id64_fields,SX_COUNT(sxvi_btrfs_send_id64_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_btrfs_send_size64_fields[] = {
    SX_FIELD("size","uint64",0,8,SX_SIZE),
};
const sx_layout sxvi_btrfs_send_size64 = {0x6053002aU,"btrfs_send_size64",sxvi_btrfs_send_size64_fields,SX_COUNT(sxvi_btrfs_send_size64_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_btrfs_send_offset64_fields[] = {
    SX_FIELD("offset","uint64",0,8,SX_OFFSET),
};
const sx_layout sxvi_btrfs_send_offset64 = {0x6053002bU,"btrfs_send_offset64",sxvi_btrfs_send_offset64_fields,SX_COUNT(sxvi_btrfs_send_offset64_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_btrfs_send_flags64_fields[] = {
    SX_FIELD("flags","uint64",0,8,SX_FLAGS),
};
const sx_layout sxvi_btrfs_send_flags64 = {0x6053002cU,"btrfs_send_flags64",sxvi_btrfs_send_flags64_fields,SX_COUNT(sxvi_btrfs_send_flags64_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_btrfs_send_flags32_fields[] = {
    SX_FIELD("flags","uint32",0,4,SX_FLAGS),
};
const sx_layout sxvi_btrfs_send_flags32 = {0x6053002dU,"btrfs_send_flags32",sxvi_btrfs_send_flags32_fields,SX_COUNT(sxvi_btrfs_send_flags32_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_btrfs_send_codec32_fields[] = {
    SX_FIELD("codec","uint32",0,4,SX_ID),
};
const sx_layout sxvi_btrfs_send_codec32 = {0x6053002eU,"btrfs_send_codec32",sxvi_btrfs_send_codec32_fields,SX_COUNT(sxvi_btrfs_send_codec32_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_btrfs_send_timespec_fields[] = {
    SX_FIELD("seconds","int64",0,8,SX_TIME),
    SX_FIELD("nanoseconds","uint32",8,4,SX_NONE),
};
const sx_layout sxvi_btrfs_send_timespec = {0x6053002fU,"btrfs_send_timespec",sxvi_btrfs_send_timespec_fields,SX_COUNT(sxvi_btrfs_send_timespec_fields),SX_LE};
#define SXVI_LIMIT 24000U
#define SXVI_ADD(c,l,p) sxvi_put(c,&sxvi_##l,p,1)
static bool sxvi_btrfs(sx_context*c){uint8_t h[17],b[10];if(!sxvi_read(c,0,h,17)||xx_rt_memcmp(h,"btrfs-stream\0",13)||sxvi32(h+13,0)<1||sxvi32(h+13,0)>3||!SXVI_ADD(c,btrfs_send_header,0))return false;unsigned version=sxvi32(h+13,0);
 for(uint64_t p=17;p+10<=(uint64_t)c->size&&c->count<SXVI_LIMIT;){if(!sxvi_read(c,p,b,10))return false;uint64_t n=sxvi32(b,0);if(n>1048576||!sxvi_span(c,p+10,n))break;if(!SXVI_ADD(c,btrfs_send_command,p))return false;uint64_t end=p+10+n,q=p+10;
  while(q+2<=end&&c->count<SXVI_LIMIT){uint8_t a[4];if(!sxvi_read(c,q,a,2))return false;unsigned type=sxvi16(a,0);if(version>=2&&type==19){if(!SXVI_ADD(c,btrfs_send_data_attribute_v2,q))return false;break;}if(end-q<4||!sxvi_read(c,q,a,4))break;uint64_t z=sxvi16(a+2,0);if(z>end-q-4)break;if(!SXVI_ADD(c,btrfs_send_attribute,q))return false;q+=4;const sx_layout*l=NULL;
   if((type==1||type==20)&&z==16)l=&sxvi_btrfs_send_uuid;
   else if(type>=9&&type<=12&&z==12)l=&sxvi_btrfs_send_timespec;
   else if(z==8){if(type==4||type==24||type==27||type==28)l=&sxvi_btrfs_send_size64;else if(type==18||type==23||type==29)l=&sxvi_btrfs_send_offset64;else if(type==5||type==26)l=&sxvi_btrfs_send_flags64;else if(type==2||type==3||type==6||type==7||type==8||type==21)l=&sxvi_btrfs_send_id64;}
   else if(z==4){if(type==25)l=&sxvi_btrfs_send_flags32;else if(type==30||type==31)l=&sxvi_btrfs_send_codec32;}
   if(l&&!sxvi_put(c,l,q,1))return false;q+=z;
  }p=end;
 }return true;
}
bool sx_btrfs_stream_build(sx_context*c)
{
 return sxvi_btrfs(c);
}
#undef SXVI_LIMIT
#undef SXVI_ADD
