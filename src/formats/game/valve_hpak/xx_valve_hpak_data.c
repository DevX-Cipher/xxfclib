/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * valve hpak data structures, moved out of the mediaextra schema family. */
#include "../../xx_format_schema_mediaextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmx_hpak_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","int32",4,4,SX_ID),
 SX_FIELD("directory_offset","int32",8,4,SX_OFFSET),
};
const sx_layout sxmx_hpak_header={UINT32_C(0x602E001C),"hpak_header",sxmx_hpak_header_fields,SX_COUNT(sxmx_hpak_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_hpak_directory_fields[]={
 SX_FIELD("entry_count","int32",0,4,SX_COUNT_PROP),
};
const sx_layout sxmx_hpak_directory={UINT32_C(0x602E001D),"hpak_directory",sxmx_hpak_directory_fields,SX_COUNT(sxmx_hpak_directory_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_hpak_entry_fields[]={
 SX_FIELD("name","char[64]",0,64,SX_STRING),
 SX_FIELD("resource_type","int32",64,4,SX_ID),
 SX_FIELD("resource_index","int32",68,4,SX_ID),
 SX_FIELD("download_size","int32",72,4,SX_SIZE),
 SX_FIELD("flags","uint8",76,1,SX_FLAGS),
 SX_FIELD("md5","bytes",77,16,SX_CHECKSUM),
 SX_FIELD("player_index","uint8",93,1,SX_ID),
 SX_FIELD("reserved","bytes",94,32,SX_RESERVED),
 SX_FIELD("alignment","bytes",126,2,SX_NONE),
 SX_FIELD("next_pointer","uint32",128,4,SX_POINTER),
 SX_FIELD("previous_pointer","uint32",132,4,SX_POINTER),
 SX_FIELD("file_offset","int32",136,4,SX_OFFSET),
 SX_FIELD("file_size","int32",140,4,SX_SIZE),
};
const sx_layout sxmx_hpak_entry={UINT32_C(0x602E001E),"hpak_entry",sxmx_hpak_entry_fields,SX_COUNT(sxmx_hpak_entry_fields),SX_LE};
#define SM_ROW(l,at,end) sxmx_row(v,&sxmx_##l,(at),(end))
static bool sxmx_hpak(sxmx_view*v)
{if(!SM_ROW(hpak_header,0,v->n))return false;size_t at=sxmx_u32(v->p+8,false);if(!SM_ROW(hpak_directory,at,v->n))return false;return sxmx_table(v,&sxmx_hpak_entry,at+4,sxmx_u32(v->p+at,false),v->n);}
bool sx_valve_hpak_build(sxmx_view*v)
{
 return sxmx_hpak(v);
}
#undef SM_ROW
