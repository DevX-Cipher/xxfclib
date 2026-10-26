/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ravensoft_rff data structures, moved out of the gameplatforms schema family. */
#include "../../xx_format_schema_gameplatforms.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgp_rff_header_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_ID),
 SX_FIELD("reserved","uint16",6,2,SX_RESERVED),
 SX_FIELD("directory_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("entry_count","uint32",12,4,SX_COUNT_PROP),
 SX_FIELD("reserved_tail","bytes",16,16,SX_RESERVED),
};
const sx_layout sxgp_rff_header={UINT32_C(0x60360043),"rff_header",sxgp_rff_header_fields,SX_COUNT(sxgp_rff_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_rff_entry_fields[]={
 SX_FIELD("runtime_state","bytes",0,16,SX_NONE),
 SX_FIELD("data_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("data_size","uint32",20,4,SX_SIZE),
 SX_FIELD("unknown_word","uint32",24,4,SX_NONE),
 SX_FIELD("unknown_time_word","uint32",28,4,SX_NONE),
 SX_FIELD("flags","uint8",32,1,SX_FLAGS),
 SX_FIELD("extension","char[3]",33,3,SX_STRING),
 SX_FIELD("name","char[8]",36,8,SX_STRING),
 SX_FIELD("resource_id","uint32",44,4,SX_ID),
};
const sx_layout sxgp_rff_entry={UINT32_C(0x60360044),"rff_entry",sxgp_rff_entry_fields,SX_COUNT(sxgp_rff_entry_fields),SX_LE};
#define SG_ROW(l,at,end) sxgp_row(v,&sxgp_##l,(at),(end))
static bool sxgp_rff(sxgp_view*v)
{uint64_t end=(uint64_t)v->c->size,ver,at,n;if(!SG_ROW(rff_header,0,end)||!sxgp_word(v,4,2,false,&ver,end)||!sxgp_word(v,8,4,false,&at,end)||!sxgp_word(v,12,4,false,&n,end))return false;return ver!=0x200||sxgp_table(v,&sxgp_rff_entry,at,n,end);}
bool sx_ravensoft_rff_build(sxgp_view*v)
{
 return sxgp_rff(v);
}
#undef SG_ROW
