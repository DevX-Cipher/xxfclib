/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * TRS-80 JV3 data structures, moved out of the disklegacy schema family. */
#include "../../xx_format_schema_disklegacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdleg_jv3_sector_descriptor_fields[] = {
    SX_FIELD("cylinder","uint8",0,1,SX_NONE),
    SX_FIELD("sector_id","uint8",1,1,SX_ID),
    SX_FIELD("flags","uint8",2,1,SX_FLAGS),
};
const sx_layout sxdleg_jv3_sector_descriptor = {0x60750002U,"jv3_sector_descriptor",sxdleg_jv3_sector_descriptor_fields,SX_COUNT(sxdleg_jv3_sector_descriptor_fields),SX_LE};
static const xx_data_struct_field_desc sxdleg_jv3_write_protection_fields[] = {
    SX_FIELD("write_protection","uint8",0,1,SX_FLAGS),
};
const sx_layout sxdleg_jv3_write_protection = {0x60750003U,"jv3_write_protection",sxdleg_jv3_write_protection_fields,SX_COUNT(sxdleg_jv3_write_protection_fields),SX_LE};
#define SXDLEG_LIMIT 24000U
#define SXDLEG_ADD(c,l,p) sxdleg_put(c,&sxdleg_##l,p,1)
#define SXDLEG_TABLE(c,l,p,n) sxdleg_put(c,&sxdleg_##l,p,n)
static bool sxdleg_jv3(sx_context*c){uint8_t h[8704];uint64_t p=0;for(unsigned block=0;block<4&&c->count<SXDLEG_LIMIT;block++){
 if(!sxdleg_read(c,p,h,sizeof(h)))break;if(!SXDLEG_TABLE(c,jv3_sector_descriptor,p,2901)||!SXDLEG_ADD(c,jv3_write_protection,p+8703))return false;uint64_t next=p+8704;
 for(unsigned i=0;i<2901;i++){const uint8_t*e=h+3*i;bool free=e[0]==255&&e[1]==255;unsigned code=e[2]&3;static const unsigned used[4]={256,128,1024,512},unused[4]={512,1024,128,256};unsigned n=free?unused[code]:used[code];if(!sxdleg_span(c,next,n))return true;next+=n;}
 if(next<=p)return false;p=next;if(p==(uint64_t)c->size)break;}return c->count!=0;}
#undef SXDLEG_LIMIT
#undef SXDLEG_ADD
#undef SXDLEG_TABLE
bool sx_trs_80_jv3_build(sx_context*c)
{
 return sxdleg_jv3(c);
}
