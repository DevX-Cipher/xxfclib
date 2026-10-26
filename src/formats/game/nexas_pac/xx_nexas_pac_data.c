/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * nexas_pac data structures, moved out of the gamearchives schema family. */
#include "../../xx_format_schema_gamearchives.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxga_nexas_footer_fields[]={
 SX_FIELD("packed_index_bytes","uint32",0,4,SX_SIZE),
};
const sx_layout sxga_nexas_footer={UINT32_C(0x603B0044),"nexas_footer",sxga_nexas_footer_fields,SX_COUNT(sxga_nexas_footer_fields),SX_LE};
#define GA_ROW(l,at,end) sxga_row(v,&sxga_##l,(at),(end))
static bool sxga_nexas_candidate(sxga_view*v,unsigned width,uint64_t n,uint64_t end,uint64_t mode)
{uint64_t z=width+12,table=n*z;if(table>16777216||!sxga_span(v,12,table,end))return false;for(uint64_t i=0;i<n;i++){uint8_t b[76];if(!sxga_read(v,12+i*z,b,(size_t)z,end))return false;bool nonspace=false;unsigned length=0;while(length<width&&b[length]){if(b[length]>32)nonspace=true;length++;}uint64_t at=xx_data_get_u32(b+width,4,0,false),raw=xx_data_get_u32(b+width+4,4,0,false),packed=xx_data_get_u32(b+width+8,4,0,false);if(!length||!nonspace||at<12+table||!sxga_span(v,at,packed,end)||(!mode&&packed!=raw))return false;}return true;}
static bool sxga_nexas(sxga_view*v)
{uint64_t end=v->c->size,n,mode;if(!GA_ROW(nexas_header,0,end)||!sxga_word(v,4,4,false,&n,end)||!n||n>0xfffff||!sxga_word(v,8,4,false,&mode,end))return false;
 if(sxga_nexas_candidate(v,32,n,end,mode))return sxga_table(v,&sxga_nexas_entry32,12,n,end);
 if(sxga_nexas_candidate(v,64,n,end,mode))return sxga_table(v,&sxga_nexas_entry64,12,n,end);
 return end>=4&&GA_ROW(nexas_footer,end-4,end);}
bool sx_nexas_pac_build(sxga_view*v)
{
 return sxga_nexas(v);
}
#undef GA_ROW
