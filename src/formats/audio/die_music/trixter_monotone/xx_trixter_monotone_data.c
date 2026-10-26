/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Trixter's MONOTONE module (.MON) data structures, moved out of the musicnext schema family. */
#include "../../../xx_format_schema_musicnext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmn_monotone_header_fields[]={
 SX_FIELD("signature_length","uint8",0,1,SX_SIZE),
 SX_FIELD("magic","char[8]",1,8,SX_SIGNATURE),
 SX_FIELD("title_length","uint8",9,1,SX_SIZE),
 SX_FIELD("title","char[40]",10,40,SX_STRING),
 SX_FIELD("comment_length","uint8",50,1,SX_SIZE),
 SX_FIELD("comment","char[40]",51,40,SX_STRING),
 SX_FIELD("version","uint8",91,1,SX_ID),
 SX_FIELD("patterns","uint8",92,1,SX_COUNT_PROP),
 SX_FIELD("tracks","uint8",93,1,SX_COUNT_PROP),
 SX_FIELD("cell_bytes","uint8",94,1,SX_SIZE),
};
const sx_layout sxmn_monotone_header={UINT32_C(0x6076002A),"monotone_header",sxmn_monotone_header_fields,SX_COUNT(sxmn_monotone_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_monotone_order_fields[]={
 SX_FIELD("pattern","uint8",0,1,SX_ID),
};
const sx_layout sxmn_monotone_order={UINT32_C(0x6076002B),"monotone_order",sxmn_monotone_order_fields,SX_COUNT(sxmn_monotone_order_fields),SX_LE};
#define MN_ROW(l,at,end) sxmn_row(v,&sxmn_##l,(at),(end))
static bool sxmn_monotone(sxmn_view*v)
{uint64_t end=v->c->size,p,t,z;if(!MN_ROW(monotone_header,0,end)||!sxmn_table(v,&sxmn_monotone_order,95,256,end)||!sxmn_word(v,92,1,false,&p,end)||!sxmn_word(v,93,1,false,&t,end)||!sxmn_word(v,94,1,false,&z,end)||!p||!t||t>16||!z)return false;uint64_t count=p*t*64;if(!sxmn_span(v,351,count*z,end))return false;return z!=2||sxmn_table(v,&sxmn_monotone_cell,351,count,end);}
bool sx_trixter_monotone_build(sxmn_view*v)
{
 return sxmn_monotone(v);
}
#undef MN_ROW
