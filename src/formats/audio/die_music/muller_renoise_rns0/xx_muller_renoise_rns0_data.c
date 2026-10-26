/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * muller_renoise_rns0 data structures, moved out of the musicprojects schema family. */
#include "../../../xx_format_schema_musicprojects.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmp_renoise_legacy_text_fields[]={
 SX_FIELD("text","char",0,0,SX_STRING),
};
const sx_layout sxmp_renoise_legacy_text={0x607b001bU,"renoise_legacy_text",sxmp_renoise_legacy_text_fields,SX_COUNT(sxmp_renoise_legacy_text_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_renoise_legacy_header_fields[]={
 SX_FIELD("signature","char[3]",0,3,SX_SIGNATURE),
 SX_FIELD("version_text","char[4]",3,4,SX_STRING),
};
const sx_layout sxmp_renoise_legacy_header={0x607b003eU,"renoise_legacy_header",sxmp_renoise_legacy_header_fields,SX_COUNT(sxmp_renoise_legacy_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_renoise_legacy_chunk_header_fields[]={
 SX_FIELD("start_marker","char[20]",0,20,SX_SIGNATURE),
 SX_FIELD("chunk_type","char[20]",20,20,SX_ID),
};
const sx_layout sxmp_renoise_legacy_chunk_header={0x607b003fU,"renoise_legacy_chunk_header",sxmp_renoise_legacy_chunk_header_fields,SX_COUNT(sxmp_renoise_legacy_chunk_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_renoise_legacy_info_v0_fields[]={
 SX_FIELD("song_name","char[20]",0,20,SX_STRING),
 SX_FIELD("author","char[20]",20,20,SX_STRING),
 SX_FIELD("style","char[20]",40,20,SX_STRING),
};
const sx_layout sxmp_renoise_legacy_info_v0={0x607b0040U,"renoise_legacy_info_v0",sxmp_renoise_legacy_info_v0_fields,SX_COUNT(sxmp_renoise_legacy_info_v0_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_renoise_legacy_string_length_fields[]={
 SX_FIELD("text_length","uint32",0,4,SX_SIZE),
};
const sx_layout sxmp_renoise_legacy_string_length={0x607b0041U,"renoise_legacy_string_length",sxmp_renoise_legacy_string_length_fields,SX_COUNT(sxmp_renoise_legacy_string_length_fields),SX_LE};
#define MP_ROW(name,at,end) sxmp_row(v,&sxmp_##name,(at),(end))
static bool sxmp_renoise_legacy(sxmp_view*v)
{uint64_t e=v->c->size,p=49;if(!MP_ROW(renoise_legacy_header,0,e)||!MP_ROW(renoise_legacy_chunk_header,9,e))return false;
 if(sxmp_eq(v,29,"Header V00         \0",20,e))return MP_ROW(renoise_legacy_info_v0,p,e);
 if(sxmp_eq(v,29,"Header V01         \0",20,e)||sxmp_eq(v,29,"Header V02         \0",20,e)){for(unsigned i=0;i<3;i++){uint64_t z;if(!MP_ROW(renoise_legacy_string_length,p,e)||!sxmp_u(v,p,4,&z,e)||!sxmp_emit(v,&sxmp_renoise_legacy_text,p+4,z,e))return false;p+=4+z;}}
 return true;}
bool sx_muller_renoise_rns0_build(sxmp_view*v)
{
 return sxmp_renoise_legacy(v);
}
#undef MP_ROW
