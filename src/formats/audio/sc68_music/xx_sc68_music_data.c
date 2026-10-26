/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * sc68_music data structures, moved out of the audiomore schema family. */
#include "../../xx_format_schema_audiomore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxau_sc68_header_fields[]={
 SX_FIELD("signature","char[56]",0,56,SX_SIGNATURE),
 SX_FIELD("magic","char[4]",56,4,SX_SIGNATURE),
 SX_FIELD("file_size_from_magic","uint32",60,4,SX_SIZE),
};
const sx_layout sxau_sc68_header={UINT32_C(0x602C003F),"sc68_header",sxau_sc68_header_fields,SX_COUNT(sxau_sc68_header_fields),SX_LE};
static const xx_data_struct_field_desc sxau_sc68_chunk_fields[]={
 SX_FIELD("chunk_id","char[4]",0,4,SX_ID),
 SX_FIELD("payload_bytes","uint32",4,4,SX_SIZE),
};
const sx_layout sxau_sc68_chunk={UINT32_C(0x602C0040),"sc68_chunk",sxau_sc68_chunk_fields,SX_COUNT(sxau_sc68_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxau_sc68_default_fields[]={
 SX_FIELD("default_track","uint32",0,4,SX_ID),
};
const sx_layout sxau_sc68_default={UINT32_C(0x602C0041),"sc68_default",sxau_sc68_default_fields,SX_COUNT(sxau_sc68_default_fields),SX_LE};
static const xx_data_struct_field_desc sxau_sc68_load_address_fields[]={
 SX_FIELD("load_address","uint32",0,4,SX_ADDRESS),
};
const sx_layout sxau_sc68_load_address={UINT32_C(0x602C0042),"sc68_load_address",sxau_sc68_load_address_fields,SX_COUNT(sxau_sc68_load_address_fields),SX_LE};
static const xx_data_struct_field_desc sxau_sc68_integer_fields[]={
 SX_FIELD("value","uint32",0,4,SX_NONE),
};
const sx_layout sxau_sc68_integer={UINT32_C(0x602C0043),"sc68_integer",sxau_sc68_integer_fields,SX_COUNT(sxau_sc68_integer_fields),SX_LE};
#define SA_ROW(l,at,end) sxau_row(v,&sxau_##l,(at),(end))
static bool sxau_sc68(sxau_view*v)
{if(!SA_ROW(sc68_header,0,v->n))return false;size_t at=64;while(at<v->n){if(!SA_ROW(sc68_chunk,at,v->n))return false;uint32_t n=sxau_u32(v->p+at+4,false);if(!sxau_need(v,at+8,n,v->n))return false;const uint8_t*p=v->p+at;if(n==4){const sx_layout*l=!xx_rt_memcmp(p,"SCDF",4)?&sxau_sc68_default:!xx_rt_memcmp(p,"SCAT",4)?&sxau_sc68_load_address:(!xx_rt_memcmp(p,"SCD0",4)||!xx_rt_memcmp(p,"SCTI",4)||!xx_rt_memcmp(p,"SCFR",4)||!xx_rt_memcmp(p,"SCFQ",4)||!xx_rt_memcmp(p,"SCLP",4)||!xx_rt_memcmp(p,"SCTY",4))?&sxau_sc68_integer:NULL;if(l&&!sxau_row(v,l,at+8,at+8+n))return false;}at+=8+n;}return true;}
bool sx_sc68_music_build(sxau_view*v)
{
 return sxau_sc68(v);
}
#undef SA_ROW
