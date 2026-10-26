/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * BeOSPackage data structures, moved out of the archivepackages schema family. */
#include "../../xx_format_schema_archivepackages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxap_beospkg_header_fields[] = {
 SX_FIELD("signature","uint8[8]",0,8,SX_SIGNATURE),
};
const sx_layout sxap_beospkg_header = {UINT32_C(0x6072001d),"beospkg_header",sxap_beospkg_header_fields,SX_COUNT(sxap_beospkg_header_fields),SX_LE};
static const xx_data_struct_field_desc sxap_beospkg_tag_fields[] = {
 SX_FIELD("tag","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("reserved","uint8",4,1,SX_NONE),
 SX_FIELD("payload_type","uint16",5,2,SX_NONE),
};
const sx_layout sxap_beospkg_tag = {UINT32_C(0x6072001e),"beospkg_tag",sxap_beospkg_tag_fields,SX_COUNT(sxap_beospkg_tag_fields),SX_LE};
static const xx_data_struct_field_desc sxap_beospkg_value32_fields[] = {
 SX_FIELD("value","uint32",0,4,SX_NONE),
};
const sx_layout sxap_beospkg_value32 = {UINT32_C(0x6072001f),"beospkg_value32",sxap_beospkg_value32_fields,SX_COUNT(sxap_beospkg_value32_fields),SX_BE};
static const xx_data_struct_field_desc sxap_beospkg_value64_fields[] = {
 SX_FIELD("value","uint64",0,8,SX_NONE),
};
const sx_layout sxap_beospkg_value64 = {UINT32_C(0x60720020),"beospkg_value64",sxap_beospkg_value64_fields,SX_COUNT(sxap_beospkg_value64_fields),SX_BE};
static const xx_data_struct_field_desc sxap_beospkg_offset64_fields[] = {
 SX_FIELD("file_offset","uint64",0,8,SX_OFFSET),
};
const sx_layout sxap_beospkg_offset64 = {UINT32_C(0x60720021),"beospkg_offset64",sxap_beospkg_offset64_fields,SX_COUNT(sxap_beospkg_offset64_fields),SX_BE};
static const xx_data_struct_field_desc sxap_beospkg_size64_fields[] = {
 SX_FIELD("uncompressed_size","uint64",0,8,SX_SIZE),
};
const sx_layout sxap_beospkg_size64 = {UINT32_C(0x60720022),"beospkg_size64",sxap_beospkg_size64_fields,SX_COUNT(sxap_beospkg_size64_fields),SX_BE};
static const xx_data_struct_field_desc sxap_beospkg_length_fields[] = {
 SX_FIELD("payload_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxap_beospkg_length = {UINT32_C(0x60720023),"beospkg_length",sxap_beospkg_length_fields,SX_COUNT(sxap_beospkg_length_fields),SX_BE};
static const xx_data_struct_field_desc sxap_beospkg_chunk_fields[] = {
 SX_FIELD("compressed_size","uint64",0,8,SX_SIZE),
 SX_FIELD("uncompressed_size","uint64",8,8,SX_SIZE),
 SX_FIELD("method","uint32",16,4,SX_NONE),
};
const sx_layout sxap_beospkg_chunk = {UINT32_C(0x60720024),"beospkg_chunk",sxap_beospkg_chunk_fields,SX_COUNT(sxap_beospkg_chunk_fields),SX_BE};
#define SXAP_LIMIT 20000U
static bool sxap_beos_payload(sx_context*c,uint64_t p){uint8_t h[14];uint64_t z;if(!sxap_read(c,p,h,14)||xx_rt_memcmp(h,"FiDa",4)||xx_rt_memcmp(h+7,"FiMF",4)||sxap_uint(h+12,2,false)!=0x300||!sxap_word(c,p+14,8,true,&z)||!sxap_span(c,p+34,z))return false;return sxap_add(c,&sxap_beospkg_tag,p)&&sxap_add(c,&sxap_beospkg_tag,p+7)&&sxap_add(c,&sxap_beospkg_chunk,p+14);}
static bool sxap_beos_element(sx_context*c,uint64_t*p,unsigned depth,uint64_t*tree){uint8_t h[7];if(depth>64||!sxap_read(c,*p,h,7)||h[4]||!sxap_add(c,&sxap_beospkg_tag,*p))return false;*p+=7;unsigned type=(unsigned)sxap_uint(h+5,2,false);uint64_t n;if(!type&&!sxap_uint(h,4,false))return true;if(type==0x101){if(!sxap_add(c,&sxap_beospkg_value32,*p))return false;*p+=4;}else if(type==0x102){const sx_layout*l=(!xx_rt_memcmp(h,"COff",4)||!xx_rt_memcmp(h,"OffT",4))?&sxap_beospkg_offset64:!xx_rt_memcmp(h,"OrgS",4)?&sxap_beospkg_size64:&sxap_beospkg_value64;if(!sxap_word(c,*p,8,true,&n)||!sxap_add(c,l,*p))return false;if(tree&&!xx_rt_memcmp(h,"COff",4))*tree=n;if(!xx_rt_memcmp(h,"OffT",4)&&!sxap_beos_payload(c,n))return false;*p+=8;}else if(type==0x200||type==0x500){if(!sxap_word(c,*p,4,true,&n)||!sxap_add(c,&sxap_beospkg_length,*p)||!sxap_span(c,*p+4,n))return false;*p+=4;if(type==0x200&&!sxap_text(c,&sxap_archivepackages_name,*p,n,false))return false;*p+=n;}else if(type==0x300){if(!sxap_word(c,*p,8,true,&n)||!sxap_add(c,&sxap_beospkg_chunk,*p)||!sxap_span(c,*p+20,n))return false;*p+=20+n;}else if(type==0x400){for(size_t work=0;work<SXAP_LIMIT;work++){if(!sxap_read(c,*p,h,7))return false;bool end=!sxap_uint(h,4,false)&&!sxap_uint(h+5,2,false);if(!sxap_beos_element(c,p,depth+1,tree))return false;if(end||(tree&&*tree))break;}}else return false;return true;}
static bool sxap_beos(sx_context*c){uint64_t p=8,tree=0;if(!sxap_add(c,&sxap_beospkg_header,0)||!sxap_beos_element(c,&p,0,&tree)||!tree)return false;p=tree;return sxap_beos_element(c,&p,0,NULL);}
bool sx_beospkg_build(sx_context*c)
{
 return sxap_beos(c);
}
