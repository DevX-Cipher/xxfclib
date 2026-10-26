/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * volition vpp data structures, moved out of the mediaextra schema family. */
#include "../../xx_format_schema_mediaextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmx_vpp3_header_le_fields[]={
 SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("name","char[65]",8,65,SX_STRING),
 SX_FIELD("path","char[256]",73,256,SX_STRING),
 SX_FIELD("alignment","bytes",329,3,SX_NONE),
 SX_FIELD("flags","uint32",332,4,SX_FLAGS),
 SX_FIELD("unknown_150","uint32",336,4,SX_NONE),
 SX_FIELD("entry_count","uint32",340,4,SX_COUNT_PROP),
 SX_FIELD("package_size","uint32",344,4,SX_SIZE),
 SX_FIELD("directory_size","uint32",348,4,SX_SIZE),
 SX_FIELD("names_size","uint32",352,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",356,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",360,4,SX_SIZE),
 SX_FIELD("directory_pointer","uint32",364,4,SX_POINTER),
 SX_FIELD("names_pointer","uint32",368,4,SX_POINTER),
 SX_FIELD("data_pointer","uint32",372,4,SX_POINTER),
};
const sx_layout sxmx_vpp3_header_le={UINT32_C(0x602E0011),"vpp3_header_le",sxmx_vpp3_header_le_fields,SX_COUNT(sxmx_vpp3_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_vpp3_entry_le_fields[]={
 SX_FIELD("name_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("runtime_offset","uint32",4,4,SX_ADDRESS),
 SX_FIELD("data_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("name_hash","uint32",12,4,SX_CHECKSUM),
 SX_FIELD("uncompressed_size","uint32",16,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",20,4,SX_SIZE),
 SX_FIELD("package_pointer","uint32",24,4,SX_POINTER),
};
const sx_layout sxmx_vpp3_entry_le={UINT32_C(0x602E0012),"vpp3_entry_le",sxmx_vpp3_entry_le_fields,SX_COUNT(sxmx_vpp3_entry_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_vpp3_header_be_fields[]={
 SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("name","char[65]",8,65,SX_STRING),
 SX_FIELD("path","char[256]",73,256,SX_STRING),
 SX_FIELD("alignment","bytes",329,3,SX_NONE),
 SX_FIELD("flags","uint32",332,4,SX_FLAGS),
 SX_FIELD("unknown_150","uint32",336,4,SX_NONE),
 SX_FIELD("entry_count","uint32",340,4,SX_COUNT_PROP),
 SX_FIELD("package_size","uint32",344,4,SX_SIZE),
 SX_FIELD("directory_size","uint32",348,4,SX_SIZE),
 SX_FIELD("names_size","uint32",352,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",356,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",360,4,SX_SIZE),
 SX_FIELD("directory_pointer","uint32",364,4,SX_POINTER),
 SX_FIELD("names_pointer","uint32",368,4,SX_POINTER),
 SX_FIELD("data_pointer","uint32",372,4,SX_POINTER),
};
const sx_layout sxmx_vpp3_header_be={UINT32_C(0x602E0013),"vpp3_header_be",sxmx_vpp3_header_be_fields,SX_COUNT(sxmx_vpp3_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_vpp3_entry_be_fields[]={
 SX_FIELD("name_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("runtime_offset","uint32",4,4,SX_ADDRESS),
 SX_FIELD("data_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("name_hash","uint32",12,4,SX_CHECKSUM),
 SX_FIELD("uncompressed_size","uint32",16,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",20,4,SX_SIZE),
 SX_FIELD("package_pointer","uint32",24,4,SX_POINTER),
};
const sx_layout sxmx_vpp3_entry_be={UINT32_C(0x602E0014),"vpp3_entry_be",sxmx_vpp3_entry_be_fields,SX_COUNT(sxmx_vpp3_entry_be_fields),SX_BE};
static bool sxmx_vpp(sxmx_view*v)
{if(!sxmx_need(v,0,376,v->n))return false;bool be=sxmx_u32(v->p,true)==0x51890ace;return sxmx_row(v,be?&sxmx_vpp3_header_be:&sxmx_vpp3_header_le,0,v->n)&&sxmx_table(v,be?&sxmx_vpp3_entry_be:&sxmx_vpp3_entry_le,2048,sxmx_u32(v->p+340,be),v->n);}
bool sx_volition_vpp_build(sxmx_view*v)
{
 return sxmx_vpp(v);
}
