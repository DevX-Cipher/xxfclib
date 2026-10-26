/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * unreal package data structures, moved out of the mediaextra schema family. */
#include "../../xx_format_schema_mediaextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmx_ue1_header_fields[]={
 SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_ID),
 SX_FIELD("licensee_version","uint16",6,2,SX_ID),
 SX_FIELD("package_flags","uint32",8,4,SX_FLAGS),
 SX_FIELD("name_count","int32",12,4,SX_COUNT_PROP),
 SX_FIELD("name_offset","int32",16,4,SX_OFFSET),
 SX_FIELD("export_count","int32",20,4,SX_COUNT_PROP),
 SX_FIELD("export_offset","int32",24,4,SX_OFFSET),
 SX_FIELD("import_count","int32",28,4,SX_COUNT_PROP),
 SX_FIELD("import_offset","int32",32,4,SX_OFFSET),
 SX_FIELD("heritage_count","int32",36,4,SX_COUNT_PROP),
 SX_FIELD("heritage_offset","int32",40,4,SX_OFFSET),
};
const sx_layout sxmx_ue1_header={UINT32_C(0x602E0056),"ue1_header",sxmx_ue1_header_fields,SX_COUNT(sxmx_ue1_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_ue1_name_flags_fields[]={
 SX_FIELD("object_flags","uint32",0,4,SX_FLAGS),
};
const sx_layout sxmx_ue1_name_flags={UINT32_C(0x602E0057),"ue1_name_flags",sxmx_ue1_name_flags_fields,SX_COUNT(sxmx_ue1_name_flags_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_ue1_heritage_fields[]={
 SX_FIELD("guid","bytes",0,16,SX_ID),
};
const sx_layout sxmx_ue1_heritage={UINT32_C(0x602E0058),"ue1_heritage",sxmx_ue1_heritage_fields,SX_COUNT(sxmx_ue1_heritage_fields),SX_LE};
#define SM_ROW(l,at,end) sxmx_row(v,&sxmx_##l,(at),(end))
static bool sxmx_ue1(sxmx_view*v)
{if(!SM_ROW(ue1_header,0,v->n))return false;size_t at=sxmx_u32(v->p+16,false);uint32_t n=sxmx_u32(v->p+12,false);if(n>4096)return false;for(uint32_t i=0;i<n;i++){if(!sxmx_cstr(v,&at,v->n)||!SM_ROW(ue1_name_flags,at,v->n))return false;at+=4;}return sxmx_table(v,&sxmx_ue1_heritage,sxmx_u32(v->p+40,false),sxmx_u32(v->p+36,false),v->n);}
bool sx_unreal_package_build(sxmx_view*v)
{
 return sxmx_ue1(v);
}
#undef SM_ROW
