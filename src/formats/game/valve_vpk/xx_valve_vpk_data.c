/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * valve_vpk data structures, moved out of the gamemeta schema family. */
#include "../../xx_format_schema_gamemeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgm_vpk_header_fields[] = {
 SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("tree_size","uint32",8,4,SX_SIZE),
};
const sx_layout sxgm_vpk_header = {UINT32_C(0x60270010),"vpk_header",sxgm_vpk_header_fields,SX_COUNT(sxgm_vpk_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_vpk_v2_sections_fields[] = {
 SX_FIELD("data_size","uint32",0,4,SX_SIZE),
 SX_FIELD("archive_md5_size","uint32",4,4,SX_SIZE),
 SX_FIELD("other_md5_size","uint32",8,4,SX_SIZE),
 SX_FIELD("signature_size","uint32",12,4,SX_SIZE),
};
const sx_layout sxgm_vpk_v2_sections = {UINT32_C(0x60270011),"vpk_v2_sections",sxgm_vpk_v2_sections_fields,SX_COUNT(sxgm_vpk_v2_sections_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_vpk_entry_fields[] = {
 SX_FIELD("crc32","uint32",0,4,SX_CHECKSUM),
 SX_FIELD("preload_size","uint16",4,2,SX_SIZE),
 SX_FIELD("archive_index","uint16",6,2,SX_ID),
 SX_FIELD("data_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("data_size","uint32",12,4,SX_SIZE),
 SX_FIELD("terminator","uint16",16,2,SX_SIGNATURE),
};
const sx_layout sxgm_vpk_entry = {UINT32_C(0x60270012),"vpk_entry",sxgm_vpk_entry_fields,SX_COUNT(sxgm_vpk_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_vpk_archive_md5_fields[] = {
 SX_FIELD("archive_index","uint32",0,4,SX_ID),
 SX_FIELD("data_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("data_size","uint32",8,4,SX_SIZE),
 SX_FIELD("md5","uint8[16]",12,16,SX_CHECKSUM),
};
const sx_layout sxgm_vpk_archive_md5 = {UINT32_C(0x60270013),"vpk_archive_md5",sxgm_vpk_archive_md5_fields,SX_COUNT(sxgm_vpk_archive_md5_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_vpk_other_md5_fields[] = {
 SX_FIELD("tree_md5","uint8[16]",0,16,SX_CHECKSUM),
 SX_FIELD("archive_md5_section_md5","uint8[16]",16,16,SX_CHECKSUM),
 SX_FIELD("file_md5","uint8[16]",32,16,SX_CHECKSUM),
};
const sx_layout sxgm_vpk_other_md5 = {UINT32_C(0x60270014),"vpk_other_md5",sxgm_vpk_other_md5_fields,SX_COUNT(sxgm_vpk_other_md5_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_vpk_public_key_length_fields[] = {
 SX_FIELD("public_key_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxgm_vpk_public_key_length = {UINT32_C(0x60270015),"vpk_public_key_length",sxgm_vpk_public_key_length_fields,SX_COUNT(sxgm_vpk_public_key_length_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_vpk_signature_length_fields[] = {
 SX_FIELD("signature_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxgm_vpk_signature_length = {UINT32_C(0x60270016),"vpk_signature_length",sxgm_vpk_signature_length_fields,SX_COUNT(sxgm_vpk_signature_length_fields),SX_LE};
#define SXGM_LIMIT 20000U
static bool sxgm_cstr(sx_context *c,uint64_t *p,uint64_t end,bool *empty){uint8_t b;uint64_t start=*p;for(unsigned i=0;i<4096&&*p<end;i++,(*p)++){if(!sxgm_read(c,*p,&b,1))return false;if(!b){*empty=*p==start;(*p)++;return true;}}return false;}
static bool sxgm_vpk(sx_context *c){uint8_t b[28];if(!sxgm_read(c,0,b,12)||!sxgm_add(c,&sxgm_vpk_header,0))return false;unsigned v=sxgm32(b+4,false),h=v==1?12:28;uint64_t tree=sxgm32(b+8,false);if(v!=1&&v!=2)return true;if(!sxgm_read(c,0,b,h)||!sxgm_span(c,h,tree))return true;if(v==2&&!sxgm_add(c,&sxgm_vpk_v2_sections,12))return false;uint64_t p=h,end=h+tree;bool empty=false;unsigned steps=0;
 while(p<end&&steps++<SXGM_LIMIT){if(!sxgm_cstr(c,&p,end,&empty)||empty)break;for(;;){if(++steps>SXGM_LIMIT||!sxgm_cstr(c,&p,end,&empty))goto sections;if(empty)break;for(;;){if(++steps>SXGM_LIMIT||!sxgm_cstr(c,&p,end,&empty))goto sections;if(empty)break;uint8_t e[18];if(end-p<18||!sxgm_read(c,p,e,18)||sxgm16(e+16,false)!=0xffff)goto sections;uint64_t z=sxgm16(e+4,false);if(z>end-p-18)goto sections;if(!sxgm_add(c,&sxgm_vpk_entry,p))return false;p+=18+z;}}}
sections:if(v==2){p=end+sxgm32(b+12,false);uint64_t a=sxgm32(b+16,false),o=sxgm32(b+20,false),sig=sxgm32(b+24,false);if(!sxgm_span(c,p,a)||a%28)return true;if(!sxgm_table(c,&sxgm_vpk_archive_md5,p,a/28))return false;p+=a;if(!sxgm_span(c,p,o))return true;if(o==48&&!sxgm_add(c,&sxgm_vpk_other_md5,p))return false;p+=o;if(sig>=8&&sxgm_span(c,p,sig)){uint64_t z;if(sxgm_word(c,p,4,false,&z)&&z<=sig-8){uint64_t sn;if(sxgm_word(c,p+4+z,4,false,&sn)&&sn==sig-8-z){if(!sxgm_add(c,&sxgm_vpk_public_key_length,p)||!sxgm_add(c,&sxgm_vpk_signature_length,p+4+z))return false;}}}}return true;}
bool sx_valve_vpk_build(sx_context*c)
{
 return sxgm_vpk(c);
}
