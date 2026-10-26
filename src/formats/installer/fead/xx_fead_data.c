/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * NetopSystems FEAD data structures, moved out of the installerremaining schema family. */
#include "../../xx_format_schema_installerremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxir_fead_outer_prefix_fields[]={
 SX_FIELD("signature","char[6]",0,6,SX_SIGNATURE),
 SX_FIELD("version","uint8",6,1,SX_NONE),
};
const sx_layout sxir_fead_outer_prefix={0x60800019U,"fead_outer_prefix",sxir_fead_outer_prefix_fields,SX_COUNT(sxir_fead_outer_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxir_fead_encoded_header_fields[]={
 SX_FIELD("encoded_signature","uint8[6]",0,6,SX_SIGNATURE),
 SX_FIELD("encoded_unknown_06","uint8[4]",6,4,SX_NONE),
 SX_FIELD("encoded_payload_size","uint8[4]",10,4,SX_NONE),
 SX_FIELD("encoded_unknown_0e","uint8[4]",14,4,SX_NONE),
};
const sx_layout sxir_fead_encoded_header={0x6080001aU,"fead_encoded_header",sxir_fead_encoded_header_fields,SX_COUNT(sxir_fead_encoded_header_fields),SX_LE};
#define IR_ROW(name,at,end) sxir_row(v,&sxir_##name,(at),(end))
static bool sxir_fead(sxir_view*v)
{uint64_t end=v->c->size,at,cert;if(!sxir_pe(v,0,end,&at,&cert))return false;if(sxir_eq(v,at,"NOS_PO",6,end)){if(!IR_ROW(fead_outer_prefix,at,end))return false;at+=7;}return IR_ROW(fead_encoded_header,at,end);}
bool sx_fead_build(sx_context*c)
{
 sxir_view view={c,0},*v=&view;return sxir_fead(v);
}
#undef IR_ROW
