/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * OMF data structures, moved out of the executablemore schema family. */
#include "../../xx_format_schema_executablemore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxexm_omf_record_header_fields[] = {
 SX_FIELD("record_type","uint8",0,1,SX_ID),
 SX_FIELD("record_size","uint16",1,2,SX_SIZE),
};
const sx_layout sxexm_omf_record_header = {UINT32_C(0x602b0040),"omf_record_header",sxexm_omf_record_header_fields,SX_COUNT(sxexm_omf_record_header_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_omf_checksum_fields[] = {
 SX_FIELD("checksum","uint8",0,1,SX_CHECKSUM),
};
const sx_layout sxexm_omf_checksum = {UINT32_C(0x602b0041),"omf_checksum",sxexm_omf_checksum_fields,SX_COUNT(sxexm_omf_checksum_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_omf_name_length_fields[] = {
 SX_FIELD("name_size","uint8",0,1,SX_SIZE),
};
const sx_layout sxexm_omf_name_length = {UINT32_C(0x602b0042),"omf_name_length",sxexm_omf_name_length_fields,SX_COUNT(sxexm_omf_name_length_fields),SX_LE};
#define SXEXM_LIMIT 20000U
static bool sxexm_omf(sx_context*c){uint8_t h[3];uint64_t p=0;for(unsigned i=0;i<SXEXM_LIMIT&&c->count<SXEXM_LIMIT;i++){if(!sxexm_read(c,p,h,3))break;uint64_t z=sxexm16(h+1,false);if(!z||!sxexm_span(c,p+3,z))break;if(!sxexm_add(c,&sxexm_omf_record_header,p)||!sxexm_add(c,&sxexm_omf_checksum,p+2+z))return false;if(h[0]==0x80||h[0]==0x82||h[0]==0x96){uint64_t q=p+3,end=p+2+z;while(q<end&&c->count<SXEXM_LIMIT){uint64_t n;if(!sxexm_word(c,q,1,false,&n)||n>=end-q)break;if(!sxexm_add(c,&sxexm_omf_name_length,q))return false;q+=1+n;if(h[0]!=0x96)break;}}p+=3+z;}return c->count!=0;}
bool sx_omf_build(sx_context*c)
{
bool ok=false;
ok=sxexm_omf(c);
return ok&&sxexm_finish(c);
}
