/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * sfx_compaq_softpaq data structures, moved out of the installerextras schema family. */
#include "../../xx_format_schema_installerextras.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxiex_softpaq_fit1_fields[] = {
    SX_FIELD("name","char[12]",0,12,SX_NONE),
    SX_FIELD("reserved","uint8",12,1,SX_RESERVED),
    SX_FIELD("file_size","int32",13,4,SX_SIZE),
    SX_FIELD("file_offset","int32",17,4,SX_OFFSET),
};
const sx_layout sxiex_softpaq_fit1 = {0x6082002eU,"softpaq_fit1",sxiex_softpaq_fit1_fields,SX_COUNT(sxiex_softpaq_fit1_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_softpaq_fit2_fields[] = {
    SX_FIELD("name","char[12]",0,12,SX_NONE),
    SX_FIELD("reserved","uint8",12,1,SX_RESERVED),
    SX_FIELD("file_size","int32",13,4,SX_SIZE),
    SX_FIELD("file_offset","int32",17,4,SX_OFFSET),
    SX_FIELD("dos_date","uint16",21,2,SX_NONE),
    SX_FIELD("dos_time","uint16",23,2,SX_NONE),
};
const sx_layout sxiex_softpaq_fit2 = {0x6082002fU,"softpaq_fit2",sxiex_softpaq_fit2_fields,SX_COUNT(sxiex_softpaq_fit2_fields),SX_LE};
static bool sxiex_softpaq(sx_context*c,const sxiex_records*r){
 uint64_t first=UINT64_MAX,last=0,stride=0;
 for(size_t i=0;i<r->count;i++){const sxiex_member*m=r->items+i;if(m->header_size!=21&&m->header_size!=25)continue;if(!sxiex_put(c,m->header_size==21?&sxiex_softpaq_fit1:&sxiex_softpaq_fit2,m->header,1))return false;if(m->header<first)first=m->header;if(m->header+m->header_size>last)last=m->header+m->header_size;stride=m->header_size;}
 if(stride&&first>=stride&&sxiex_eq(c,first-stride,"US_PCU.DOS",10)&&!sxiex_put(c,stride==21?&sxiex_softpaq_fit1:&sxiex_softpaq_fit2,first-stride,1))return false;
 if(stride&&sxiex_span(c,last,stride)&&sxiex_eq(c,last,stride==21?"FIT001":"FIT002",6)&&!sxiex_put(c,stride==21?&sxiex_softpaq_fit1:&sxiex_softpaq_fit2,last,1))return false;
 return true;
}
bool sx_sfx_compaq_softpaq_build(sx_context*c,const sxiex_records*records)
{
 return sxiex_softpaq(c,records);
}
