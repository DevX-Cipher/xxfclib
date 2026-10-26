/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * AD01 SFX data structures, moved out of the installerremaining schema family. */
#include "../../xx_format_schema_installerremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxir_active_delivery_header_fields[]={
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("unknown_04","uint8[4]",4,4,SX_NONE),
 SX_FIELD("zip_size","uint32le",8,4,SX_SIZE),
};
const sx_layout sxir_active_delivery_header={0x6080003cU,"active_delivery_header",sxir_active_delivery_header_fields,SX_COUNT(sxir_active_delivery_header_fields),SX_LE};
#define IR_ROW(name,at,end) sxir_row(v,&sxir_##name,(at),(end))
#define IR_U(at,z,out,end) sxir_u(v,(at),(z),false,&(out),(end))
static bool sxir_ad01(sxir_view*v)
{uint64_t end=v->c->size,extent,cert,pe,sections,opt;if(!sxir_eq(v,0,"MZ",2,end)||!sxir_pe(v,0,end,&extent,&cert)||!IR_U(60,4,pe,end)||!IR_U(pe+6,2,sections,end)||!IR_U(pe+20,2,opt,end))return false;
 for(uint64_t i=0;i<sections;i++){uint64_t s=pe+24+opt+40*i;if(!sxir_eq(v,s,"actdlvry",8,end))continue;uint64_t size,at,z;if(!IR_U(s+16,4,size,end)||!IR_U(s+20,4,at,end)||!sxir_span(v,at,size,end)||size<34||!sxir_eq(v,at,"AD01",4,at+size)||!IR_U(at+8,4,z,at+size)||z>size-12||!IR_ROW(active_delivery_header,at,at+size))return false;return true;}return false;}
bool sx_sfx_ad01_build(sx_context*c)
{
 sxir_view view={c,0},*v=&view;return sxir_ad01(v);
}
#undef IR_ROW
#undef IR_U
