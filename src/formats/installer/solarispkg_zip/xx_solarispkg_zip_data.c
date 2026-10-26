/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Solaris package (ZIP) data structures, moved out of the installerremaining schema family. */
#include "../../xx_format_schema_installerremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxir_solaris_zip_signature_fields[]={
 SX_FIELD("signature","char[25]",0,25,SX_SIGNATURE),
};
const sx_layout sxir_solaris_zip_signature={0x60800025U,"solaris_zip_signature",sxir_solaris_zip_signature_fields,SX_COUNT(sxir_solaris_zip_signature_fields),SX_LE};
static const xx_data_struct_field_desc sxir_solaris_zip_object_fields[]={
 SX_FIELD("signature","uint8[4]",0,4,SX_SIGNATURE),
 SX_FIELD("stored_object_size","uint32le",4,4,SX_SIZE),
 SX_FIELD("unknown_08","uint8[4]",8,4,SX_NONE),
};
const sx_layout sxir_solaris_zip_object={0x60800026U,"solaris_zip_object",sxir_solaris_zip_object_fields,SX_COUNT(sxir_solaris_zip_object_fields),SX_LE};
static const xx_data_struct_field_desc sxir_solaris_zip_group_fields[]={
 SX_FIELD("signature","uint8[4]",0,4,SX_SIGNATURE),
 SX_FIELD("block_count","uint32le",4,4,SX_COUNT_PROP),
 SX_FIELD("maximum_block_size","uint32le",8,4,SX_SIZE),
};
const sx_layout sxir_solaris_zip_group={0x60800027U,"solaris_zip_group",sxir_solaris_zip_group_fields,SX_COUNT(sxir_solaris_zip_group_fields),SX_LE};
static const xx_data_struct_field_desc sxir_solaris_zip_block_fields[]={
 SX_FIELD("uncompressed_size","uint32le",0,4,SX_SIZE),
 SX_FIELD("stored_size","uint32le",4,4,SX_SIZE),
 SX_FIELD("group_relative_offset","uint32le",8,4,SX_OFFSET),
};
const sx_layout sxir_solaris_zip_block={0x60800028U,"solaris_zip_block",sxir_solaris_zip_block_fields,SX_COUNT(sxir_solaris_zip_block_fields),SX_LE};
#define IR_ROW(name,at,end) sxir_row(v,&sxir_##name,(at),(end))
#define IR_U(at,z,out,end) sxir_u(v,(at),(z),false,&(out),(end))
static bool sxir_solaris_zip(sxir_view*v)
{uint64_t end=v->c->size;if(!sxir_eq(v,0,"# PaCkAgE DaTaStReAm:zip\n",25,end)||!IR_ROW(solaris_zip_signature,0,end))return false;
 for(uint64_t at=512;at<=end&&end-at>=512;){if(!sxir_eq(v,at,"\x19\x9eTL",4,end)){at+=512;continue;}uint64_t n,count,body=at+512;if(!IR_U(at+4,4,n,end)||n<12||!sxir_span(v,body,n,end)||!IR_ROW(solaris_zip_object,at,end)||!sxir_eq(v,body,"\x19\x9eTG",4,body+n)||!IR_U(body+4,4,count,body+n)||!count||count>262144||!IR_ROW(solaris_zip_group,body,body+n)||!sxir_table(v,&sxir_solaris_zip_block,body+12,count,body+n))return false;uint64_t pad=(512-(n&511))&511;if(!sxir_span(v,body+n,pad,end))return false;at=body+n+pad;}return true;}
bool sx_solarispkg_zip_build(sx_context*c)
{
 sxir_view view={c,0},*v=&view;return sxir_solaris_zip(v);
}
#undef IR_ROW
#undef IR_U
