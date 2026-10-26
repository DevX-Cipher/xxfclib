/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * MetaProducts data structures, moved out of the installerremaining schema family. */
#include "../../xx_format_schema_installerremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxir_metaproducts_header_fields[]={
 SX_FIELD("signature","uint32le",0,4,SX_SIGNATURE),
};
const sx_layout sxir_metaproducts_header={0x6080002bU,"metaproducts_header",sxir_metaproducts_header_fields,SX_COUNT(sxir_metaproducts_header_fields),SX_LE};
static const xx_data_struct_field_desc sxir_metaproducts_member_fields[]={
 SX_FIELD("name_size","uint8",0,1,SX_SIZE),
 SX_FIELD("name","char[103]",1,103,SX_NONE),
 SX_FIELD("packed_size","uint32le",104,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32le",108,4,SX_SIZE),
};
const sx_layout sxir_metaproducts_member={0x6080002cU,"metaproducts_member",sxir_metaproducts_member_fields,SX_COUNT(sxir_metaproducts_member_fields),SX_LE};
static const xx_data_struct_field_desc sxir_metaproducts_footer_fields[]={
 SX_FIELD("footer_value","uint32le",0,4,SX_NONE),
 SX_FIELD("signature","uint32le",4,4,SX_SIGNATURE),
};
const sx_layout sxir_metaproducts_footer={0x6080002dU,"metaproducts_footer",sxir_metaproducts_footer_fields,SX_COUNT(sxir_metaproducts_footer_fields),SX_LE};
#define IR_ROW(name,at,end) sxir_row(v,&sxir_##name,(at),(end))
#define IR_U(at,z,out,end) sxir_u(v,(at),(z),false,&(out),(end))
static bool sxir_metaproducts(sxir_view*v)
{uint64_t end=v->c->size,at,cert;if(!sxir_pe(v,0,end,&at,&cert)||!sxir_eq(v,at,"\x73\x19\xba\xab",4,end)||!IR_ROW(metaproducts_header,at,end))return false;at+=4;end=cert;
 while(at<end){if(sxir_eq(v,at+4,"\x73\x19\xc0\xab",4,end))return at+8==end&&IR_ROW(metaproducts_footer,at,end);uint64_t n;if(!IR_U(at+104,4,n,end)||!n||!IR_ROW(metaproducts_member,at,end)||!sxir_span(v,at+112,n,end))return false;at+=112+n;}return false;}
bool sx_metaproducts_build(sx_context*c)
{
 sxir_view view={c,0},*v=&view;return sxir_metaproducts(v);
}
#undef IR_ROW
#undef IR_U
