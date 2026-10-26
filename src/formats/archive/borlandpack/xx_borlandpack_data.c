/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * BORLANDPACK data structures, moved out of the archiveclassic schema family. */
#include "../../xx_format_schema_archiveclassic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxacl_borlandpack_header_fields[] = {
 SX_FIELD("signature","uint8[23]",0,23,SX_SIGNATURE),
 SX_FIELD("method_tag","char[4]",23,4,SX_SIGNATURE),
 SX_FIELD("method","ascii_decimal[2]",27,2,SX_NONE),
 SX_FIELD("separator","char[1]",29,1,SX_NONE),
 SX_FIELD("version","ascii_decimal[3]",30,3,SX_NONE),
 SX_FIELD("suffix","char[3]",33,3,SX_NONE),
};
const sx_layout sxacl_borlandpack_header = {UINT32_C(0x6050000b),"borlandpack_header",sxacl_borlandpack_header_fields,SX_COUNT(sxacl_borlandpack_header_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_borlandpack_attributes_fields[] = {
 SX_FIELD("uncompressed_size","ascii_decimal[11]",0,11,SX_SIZE),
 SX_FIELD("separator1","char[1]",11,1,SX_NONE),
 SX_FIELD("checksum","ascii_hex[4]",12,4,SX_CHECKSUM),
 SX_FIELD("separator2","char[1]",16,1,SX_NONE),
 SX_FIELD("dos_date","ascii_hex[4]",17,4,SX_NONE),
 SX_FIELD("separator3","char[1]",21,1,SX_NONE),
 SX_FIELD("dos_time","ascii_hex[4]",22,4,SX_NONE),
};
const sx_layout sxacl_borlandpack_attributes = {UINT32_C(0x6050000c),"borlandpack_attributes",sxacl_borlandpack_attributes_fields,SX_COUNT(sxacl_borlandpack_attributes_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_borlandpack_size_fields[] = {
 SX_FIELD("compressed_size","ascii_decimal[10]",0,10,SX_SIZE),
 SX_FIELD("line_end","char[2]",10,2,SX_NONE),
};
const sx_layout sxacl_borlandpack_size = {UINT32_C(0x6050000d),"borlandpack_size",sxacl_borlandpack_size_fields,SX_COUNT(sxacl_borlandpack_size_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_borlandpack_lzw_flags_fields[] = {
 SX_FIELD("flags","uint8",0,1,SX_NONE),
};
const sx_layout sxacl_borlandpack_lzw_flags = {UINT32_C(0x6050000e),"borlandpack_lzw_flags",sxacl_borlandpack_lzw_flags_fields,SX_COUNT(sxacl_borlandpack_lzw_flags_fields),SX_LE};
#define SXACL_LIMIT 20000U
static bool sxacl_decimal(sx_context*c,uint64_t p,unsigned n,uint64_t*v){uint8_t b[24];if(n>24||!sxacl_read(c,p,b,n))return false;unsigned i=0;while(i<n&&b[i]==' ')i++;if(i==n)return false;uint64_t a=0;for(;i<n;i++){if(b[i]<'0'||b[i]>'9'||a>(UINT64_MAX-(b[i]-'0'))/10)return false;a=a*10+b[i]-'0';}*v=a;return true;}
static bool sxacl_hex4(sx_context*c,uint64_t p){uint8_t b[4];if(!sxacl_read(c,p,b,4))return false;for(unsigned i=0;i<4;i++)if(!((b[i]>='0'&&b[i]<='9')||(b[i]>='A'&&b[i]<='F')))return false;return true;}
static bool sxacl_borland(sx_context*c){uint64_t p=36;if(!sxacl_add(c,&sxacl_borlandpack_header,0))return false;for(unsigned i=0;i<SXACL_LIMIT&&p<(uint64_t)c->size;i++){uint64_t q=p+1,z;bool found=false;for(unsigned j=0;j<4096;j++,q++){uint8_t b[2];if(!sxacl_read(c,q,b,2))return false;if(b[0]=='\r'&&b[1]=='\n'){found=true;break;}}if(!found||q-p<28||!sxacl_hex4(c,q-14)||!sxacl_hex4(c,q-9)||!sxacl_hex4(c,q-4)||!sxacl_add(c,&sxacl_borlandpack_attributes,q-26)||!sxacl_add(c,&sxacl_borlandpack_size,q+2)||!sxacl_decimal(c,q+2,10,&z)||!sxacl_span(c,q+14,z))return false;if(z&&!sxacl_add(c,&sxacl_borlandpack_lzw_flags,q+14))return false;p=q+14+z;}return true;}
bool sx_borlandpack_build(sx_context*c)
{
 return sxacl_borland(c);
}
