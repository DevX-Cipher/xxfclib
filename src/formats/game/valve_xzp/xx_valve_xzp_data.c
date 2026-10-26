/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * valve_xzp data structures, moved out of the gamearchives schema family. */
#include "../../xx_format_schema_gamearchives.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxga_xzp_mapping_fields[]={
 SX_FIELD("preload_entry","uint16",0,2,SX_ID),
};
const sx_layout sxga_xzp_mapping={UINT32_C(0x603B0039),"xzp_mapping",sxga_xzp_mapping_fields,SX_COUNT(sxga_xzp_mapping_fields),SX_LE};
static const xx_data_struct_field_desc sxga_xzp_footer_fields[]={
 SX_FIELD("file_bytes","uint32",0,4,SX_SIZE),
 SX_FIELD("magic","char[4]",4,4,SX_SIGNATURE),
};
const sx_layout sxga_xzp_footer={UINT32_C(0x603B003B),"xzp_footer",sxga_xzp_footer_fields,SX_COUNT(sxga_xzp_footer_fields),SX_LE};
#define GA_ROW(l,at,end) sxga_row(v,&sxga_##l,(at),(end))
static bool sxga_xzp(sxga_view*v)
{uint64_t end=v->c->size,n,p,z,m,at,names,table_end;if(!GA_ROW(xzp_header,0,end)||!sxga_word(v,8,4,false,&p,end)||!sxga_word(v,12,4,false,&n,end)||!sxga_word(v,16,4,false,&z,end)||!sxga_word(v,24,4,false,&m,end)||!sxga_word(v,28,4,false,&at,end)||!sxga_word(v,32,4,false,&names,end)||m>1000000)return false;if(!sxga_table(v,&sxga_xzp_entry,36,n,end))return false;if(z&&(!sxga_table(v,&sxga_xzp_entry,36+12*n,p,end)||!sxga_table(v,&sxga_xzp_mapping,36+12*(n+p),n,end)))return false;if(!sxga_span(v,at,names,end)||!sxga_table(v,&sxga_xzp_name,at,m,at+names))return false;table_end=at+names;for(uint64_t i=0;i<m;i++){uint64_t pos,start;if(!sxga_word(v,at+12*i+4,4,false,&pos,table_end))return false;start=pos;if(pos>=at+12*m&&pos<table_end&&sxga_cstring(v,&pos,table_end,256)&&!sxga_named(v,start,pos-start,table_end,false))return false;}return end>=8&&GA_ROW(xzp_footer,end-8,end);}
bool sx_valve_xzp_build(sxga_view*v)
{
 return sxga_xzp(v);
}
#undef GA_ROW
