/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * noa data structures, moved out of the gamecontainers schema family. */
#include "../../xx_format_schema_gamecontainers.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgco_noa_header_fields[]={
 SX_FIELD("magic","bytes",0,8,SX_SIGNATURE),
 SX_FIELD("file_id","uint32",8,4,SX_ID),
 SX_FIELD("reserved","uint32",12,4,SX_RESERVED),
 SX_FIELD("description","char[48]",16,48,SX_STRING),
};
const sx_layout sxgco_noa_header={UINT32_C(0x60400028),"noa_header",sxgco_noa_header_fields,SX_COUNT(sxgco_noa_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_noa_record_fields[]={
 SX_FIELD("tag","char[8]",0,8,SX_ID),
 SX_FIELD("body_bytes","uint64",8,8,SX_SIZE),
};
const sx_layout sxgco_noa_record={UINT32_C(0x60400029),"noa_record",sxgco_noa_record_fields,SX_COUNT(sxgco_noa_record_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_noa_count_fields[]={
 SX_FIELD("entries","int32",0,4,SX_COUNT_PROP),
};
const sx_layout sxgco_noa_count={UINT32_C(0x6040005E),"noa_count",sxgco_noa_count_fields,SX_COUNT(sxgco_noa_count_fields),SX_LE};
#define GC_ROW(l,at,end) sxgco_row(v,&sxgco_##l,(at),(end))
static bool sxgco_noa_dir(sxgco_view*v,uint64_t p,uint64_t end,unsigned depth)
{uint64_t length,n,at,attr,relative,extra,z;uint8_t tag[8];if(depth>32||!sxgco_read(v,p,tag,8,end)||xx_rt_memcmp(tag,"DirEntry",8)||!GC_ROW(noa_directory_record,p,end)||!sxgco_word(v,p+8,8,false,&length,end)||length>INT32_MAX)return false;
 uint64_t limit=end-p-16;if(length<limit)limit=length;limit+=p+16;if(!GC_ROW(noa_count,p+16,limit)||!sxgco_word(v,p+16,4,false,&n,limit))return false;if(n>INT32_MAX)return true;at=p+20;
 for(uint64_t i=0;i<n;i++){if(!GC_ROW(noa_entry,at,limit)||!sxgco_word(v,at+8,4,false,&attr,limit)||!sxgco_word(v,at+16,8,false,&relative,limit)||!sxgco_word(v,at+32,4,false,&extra,limit))return false;at+=36;if(!sxgco_span(v,at,extra,limit))return false;at+=extra;if(!GC_ROW(name_size32,at,limit)||!sxgco_word(v,at,4,false,&z,limit)||z>0x10000||!sxgco_table(v,&sxgco_filename_byte,at+4,z,limit))return false;at+=4+z;
 if(attr==0x20||attr==0x40)break;uint64_t target;bool valid;if(relative>>63){uint64_t back=(~relative)+1;valid=back<=p;target=valid?p-back:0;}else{valid=relative<=end-p;target=valid?p+relative:0;}
 if(valid&&sxgco_span(v,target,16,end)){if(!GC_ROW(noa_record,target,end))return false;if(attr==0x10&&!sxgco_noa_dir(v,target+16,end,depth+1))return false;}}
 return true;}
static bool sxgco_noa(sxgco_view*v){return GC_ROW(noa_header,0,v->c->size)&&sxgco_noa_dir(v,64,v->c->size,0);}
bool sx_noa_build(sxgco_view*v)
{
 return sxgco_noa(v);
}
#undef GC_ROW
