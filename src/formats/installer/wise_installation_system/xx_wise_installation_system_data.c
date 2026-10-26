/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Wise Installation System data structures, moved out of the installerlast schema family. */
#include "../../xx_format_schema_installerlast.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxil_wise_member_crc32_fields[] = {
    SX_FIELD("crc32","uint32",0,4,SX_CHECKSUM),
};
const sx_layout sxil_wise_member_crc32 = {0x6085004eU,"wise_member_crc32",sxil_wise_member_crc32_fields,SX_COUNT(sxil_wise_member_crc32_fields),SX_LE};
static const xx_data_struct_field_desc sxil_wise_zip_local_fields[] = {
    SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("version_needed","uint16",4,2,SX_ID),
    SX_FIELD("flags","uint16",6,2,SX_FLAGS),
    SX_FIELD("method","uint16",8,2,SX_ID),
    SX_FIELD("dos_time","uint16",10,2,SX_NONE),
    SX_FIELD("dos_date","uint16",12,2,SX_NONE),
    SX_FIELD("crc32","uint32",14,4,SX_CHECKSUM),
    SX_FIELD("packed_size","uint32",18,4,SX_SIZE),
    SX_FIELD("unpacked_size","uint32",22,4,SX_SIZE),
    SX_FIELD("name_size","uint16",26,2,SX_SIZE),
    SX_FIELD("extra_size","uint16",28,2,SX_SIZE),
};
const sx_layout sxil_wise_zip_local = {0x6085004fU,"wise_zip_local",sxil_wise_zip_local_fields,SX_COUNT(sxil_wise_zip_local_fields),SX_LE};
static const xx_data_struct_field_desc sxil_wise_zip_central_fields[] = {
    SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("version_made_by","uint16",4,2,SX_ID),
    SX_FIELD("version_needed","uint16",6,2,SX_ID),
    SX_FIELD("flags","uint16",8,2,SX_FLAGS),
    SX_FIELD("method","uint16",10,2,SX_ID),
    SX_FIELD("dos_time","uint16",12,2,SX_NONE),
    SX_FIELD("dos_date","uint16",14,2,SX_NONE),
    SX_FIELD("crc32","uint32",16,4,SX_CHECKSUM),
    SX_FIELD("packed_size","uint32",20,4,SX_SIZE),
    SX_FIELD("unpacked_size","uint32",24,4,SX_SIZE),
    SX_FIELD("name_size","uint16",28,2,SX_SIZE),
    SX_FIELD("extra_size","uint16",30,2,SX_SIZE),
    SX_FIELD("comment_size","uint16",32,2,SX_SIZE),
    SX_FIELD("disk_start","uint16",34,2,SX_NONE),
    SX_FIELD("internal_attributes","uint16",36,2,SX_FLAGS),
    SX_FIELD("external_attributes","uint32",38,4,SX_FLAGS),
    SX_FIELD("local_header_offset","uint32",42,4,SX_OFFSET),
};
const sx_layout sxil_wise_zip_central = {0x60850050U,"wise_zip_central",sxil_wise_zip_central_fields,SX_COUNT(sxil_wise_zip_central_fields),SX_LE};
static const xx_data_struct_field_desc sxil_wise_zip_end_fields[] = {
    SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("disk_number","uint16",4,2,SX_NONE),
    SX_FIELD("directory_disk","uint16",6,2,SX_NONE),
    SX_FIELD("entries_on_disk","uint16",8,2,SX_COUNT_PROP),
    SX_FIELD("total_entries","uint16",10,2,SX_COUNT_PROP),
    SX_FIELD("directory_size","uint32",12,4,SX_SIZE),
    SX_FIELD("directory_offset","uint32",16,4,SX_OFFSET),
    SX_FIELD("comment_size","uint16",20,2,SX_SIZE),
};
const sx_layout sxil_wise_zip_end = {0x60850051U,"wise_zip_end",sxil_wise_zip_end_fields,SX_COUNT(sxil_wise_zip_end_fields),SX_LE};
#define SXIL_ADD(c,n,p) sxil_put(c,&sxil_##n,p,1)
static bool sxil_wise(sx_context*c,sxil_records*r){uint64_t end=0;bool zip=false;for(size_t i=0;i<r->count;i++){sxil_member*m=r->items+i;
 if(m->header_size>=30&&sxil_eq(c,m->header,"PK\3\4",4)){uint8_t b[30];if(!sxil_read(c,m->header,b,30))continue;uint64_t ns=sxil16(b+26,false),es=sxil16(b+28,false);if(30+ns+es!=m->header_size)continue;zip=true;if(!SXIL_ADD(c,wise_zip_local,m->header)||!sxil_name(c,m->header+30,ns))return false;end=m->data+m->packed;}
 else if(!m->header_size&&m->crc<=UINT32_MAX){uint64_t p=m->data+m->packed;for(unsigned pad=0;pad<=3;pad++){uint32_t v;if(sxil_u32(c,p+pad,&v)&&v==(uint32_t)m->crc){if(!SXIL_ADD(c,wise_member_crc32,p+pad))return false;break;}uint8_t z;if(!sxil_read(c,p+pad,&z,1)||z)break;}}
 }
 if(zip){uint64_t p=end;for(size_t k=0;k<100000;k++){if(sxil_eq(c,p,"PK\1\2",4)){uint8_t b[46];if(!sxil_read(c,p,b,46))return true;uint64_t n=sxil16(b+28,false),e=sxil16(b+30,false),z=sxil16(b+32,false);if(!sxil_span(c,p,46+n+e+z))return true;if(!SXIL_ADD(c,wise_zip_central,p)||!sxil_name(c,p+46,n)||!sxil_name(c,p+46+n+e,z))return false;p+=46+n+e+z;}
 else{if(sxil_eq(c,p,"PK\5\6",4)&&sxil_span(c,p,22)&&!SXIL_ADD(c,wise_zip_end,p))return false;break;}}}return true;}
bool sx_wise_installation_system_build(sx_context*c,sxil_records records)
{
 return sxil_wise(c,&records);
}
#undef SXIL_ADD
