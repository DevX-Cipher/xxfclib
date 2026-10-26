/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * nitroplus_npa data structures, moved out of the gamecontainers schema family. */
#include "../../xx_format_schema_gamecontainers.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgco_npa_header_fields[]={
 SX_FIELD("magic","char[7]",0,7,SX_SIGNATURE),
 SX_FIELD("key1","uint32",7,4,SX_NONE),
 SX_FIELD("key2","uint32",11,4,SX_NONE),
 SX_FIELD("compressed","uint8",15,1,SX_FLAGS),
 SX_FIELD("encrypted","uint8",16,1,SX_FLAGS),
 SX_FIELD("entries","int32",17,4,SX_COUNT_PROP),
 SX_FIELD("directories","int32",21,4,SX_COUNT_PROP),
 SX_FIELD("files","int32",25,4,SX_COUNT_PROP),
 SX_FIELD("unknown1d","bytes",29,8,SX_NONE),
 SX_FIELD("index_bytes","uint32",37,4,SX_SIZE),
};
const sx_layout sxgco_npa_header={UINT32_C(0x60400044),"npa_header",sxgco_npa_header_fields,SX_COUNT(sxgco_npa_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_npa_name_size_fields[]={
 SX_FIELD("name_bytes","int32",0,4,SX_SIZE),
};
const sx_layout sxgco_npa_name_size={UINT32_C(0x60400045),"npa_name_size",sxgco_npa_name_size_fields,SX_COUNT(sxgco_npa_name_size_fields),SX_LE};
#define GC_ROW(l,at,end) sxgco_row(v,&sxgco_##l,(at),(end))
static bool sxgco_npa(sxgco_view*v)
{uint64_t e=v->c->size,n,z,end,p=41;if(!GC_ROW(npa_header,0,e)||!sxgco_word(v,17,4,false,&n,e)||!sxgco_word(v,37,4,false,&end,e)||!sxgco_span(v,41,end,e)||n>UINT32_C(0xfffff))return false;end+=41;
 for(uint64_t i=0;i<n;i++){if(!GC_ROW(npa_name_size,p,end)||!sxgco_word(v,p,4,false,&z,end)||!z||z>4096||!sxgco_table(v,&sxgco_encoded_byte,p+4,z,end)||!GC_ROW(npa_fields,p+4+z,end))return false;p+=21+z;}return p==end;}
bool sx_nitroplus_npa_build(sxgco_view*v)
{
 return sxgco_npa(v);
}
#undef GC_ROW
