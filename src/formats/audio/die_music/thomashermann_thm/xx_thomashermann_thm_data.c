/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * thomashermann_thm data structures, moved out of the amigamore schema family. */
#include "../../../xx_format_schema_amigamore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxamore_thm_order_fields[]={
 SX_FIELD("pattern","uint8",0,1,SX_ID),
};
const sx_layout sxamore_thm_order={UINT32_C(0x60950011),"thm_order",sxamore_thm_order_fields,SX_COUNT(sxamore_thm_order_fields),SX_LE};
#define AM_ROW(l,at,end) sxamore_row(v,&sxamore_##l,(at),(end))
static bool sxamore_thm(sxamore_view*v)
{
 uint64_t e=(uint64_t)v->c->size,origin,n,rows;
 if(!sxamore_be(v,46,4,&origin,e)||!origin||(origin&1)||origin>=UINT64_C(0x80000000)||!sxamore_be(v,35,1,&n,e)||n>31||!sxamore_be(v,41,1,&rows,e))return false;
 for(unsigned i=0;i<8;i++){uint64_t x,want=i<4?64+i*1024:4160+(i-4)*256;if(!sxamore_be(v,i*4,4,&x,e)||x<origin||x-origin!=want)return false;}
 if(!AM_ROW(thm_header,0,e)||!sxamore_table(v,&sxamore_original_address,64,1024,e)||!sxamore_table(v,&sxamore_thm_order,4160,1024,e)||!sxamore_table(v,&sxamore_original_address,5184,32,e)||!sxamore_table(v,&sxamore_thm_sample,5358,n,e))return false;
 return true;
}
bool sx_thomashermann_thm_build(sxamore_view*v)
{
 return sxamore_thm(v);
}
#undef AM_ROW
