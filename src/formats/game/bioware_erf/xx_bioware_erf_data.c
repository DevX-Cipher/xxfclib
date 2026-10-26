/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * bioware_erf data structures, moved out of the gamemeta schema family. */
#include "../../xx_format_schema_gamemeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgm_erf_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","char[4]",4,4,SX_ID),
 SX_FIELD("language_count","uint32",8,4,SX_COUNT_PROP),
 SX_FIELD("localized_size","uint32",12,4,SX_SIZE),
 SX_FIELD("entry_count","uint32",16,4,SX_COUNT_PROP),
 SX_FIELD("localized_offset","uint32",20,4,SX_OFFSET),
 SX_FIELD("keys_offset","uint32",24,4,SX_OFFSET),
 SX_FIELD("resources_offset","uint32",28,4,SX_OFFSET),
 SX_FIELD("build_year","uint32",32,4,SX_NONE),
 SX_FIELD("build_day","uint32",36,4,SX_NONE),
 SX_FIELD("description_strref","uint32",40,4,SX_ID),
 SX_FIELD("reserved","uint8[116]",44,116,SX_RESERVED),
};
const sx_layout sxgm_erf_header = {UINT32_C(0x60270034),"erf_header",sxgm_erf_header_fields,SX_COUNT(sxgm_erf_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_erf_key16_fields[] = {
 SX_FIELD("resref","char[16]",0,16,SX_STRING),
 SX_FIELD("resource_id","uint32",16,4,SX_ID),
 SX_FIELD("resource_type","uint16",20,2,SX_ID),
 SX_FIELD("reserved","uint16",22,2,SX_RESERVED),
};
const sx_layout sxgm_erf_key16 = {UINT32_C(0x60270035),"erf_key16",sxgm_erf_key16_fields,SX_COUNT(sxgm_erf_key16_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_erf_key32_fields[] = {
 SX_FIELD("resref","char[32]",0,32,SX_STRING),
 SX_FIELD("resource_id","uint32",32,4,SX_ID),
 SX_FIELD("resource_type","uint16",36,2,SX_ID),
 SX_FIELD("reserved","uint16",38,2,SX_RESERVED),
};
const sx_layout sxgm_erf_key32 = {UINT32_C(0x60270036),"erf_key32",sxgm_erf_key32_fields,SX_COUNT(sxgm_erf_key32_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_erf_resource_fields[] = {
 SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("data_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxgm_erf_resource = {UINT32_C(0x60270037),"erf_resource",sxgm_erf_resource_fields,SX_COUNT(sxgm_erf_resource_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_erf_localized_fields[] = {
 SX_FIELD("language_id","uint32",0,4,SX_ID),
 SX_FIELD("text_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxgm_erf_localized = {UINT32_C(0x60270038),"erf_localized",sxgm_erf_localized_fields,SX_COUNT(sxgm_erf_localized_fields),SX_LE};
#define SXGM_LIMIT 20000U
static bool sxgm_erf(sx_context *c){uint8_t b[160];if(!sxgm_read(c,0,b,160)||!sxgm_add(c,&sxgm_erf_header,0))return false;uint64_t n=sxgm32(b+16,false),p=sxgm32(b+20,false),z=sxgm32(b+12,false),langs=sxgm32(b+8,false);if(!sxgm_table(c,b[7]=='1'?&sxgm_erf_key32:&sxgm_erf_key16,sxgm32(b+24,false),n)||!sxgm_table(c,&sxgm_erf_resource,sxgm32(b+28,false),n))return false;if(!sxgm_span(c,p,z))return true;uint64_t end=p+z;for(uint64_t i=0;i<langs&&i<SXGM_LIMIT&&end-p>=8;i++){uint64_t text;if(!sxgm_word(c,p+4,4,false,&text)||text>end-p-8)break;if(!sxgm_add(c,&sxgm_erf_localized,p))return false;p+=8+text;}return true;}
bool sx_bioware_erf_build(sx_context*c)
{
 return sxgm_erf(c);
}
