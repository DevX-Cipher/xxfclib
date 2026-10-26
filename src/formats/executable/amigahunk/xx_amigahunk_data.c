/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * AMIGAHUNK data structures, moved out of the executablemore schema family. */
#include "../../xx_format_schema_executablemore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxexm_amiga_hunk_tag_fields[] = {
 SX_FIELD("type_and_memory_flags","uint32",0,4,SX_FLAGS),
};
const sx_layout sxexm_amiga_hunk_tag = {UINT32_C(0x602b0046),"amiga_hunk_tag",sxexm_amiga_hunk_tag_fields,SX_COUNT(sxexm_amiga_hunk_tag_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_amiga_hunk_length_fields[] = {
 SX_FIELD("longword_count","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxexm_amiga_hunk_length = {UINT32_C(0x602b0047),"amiga_hunk_length",sxexm_amiga_hunk_length_fields,SX_COUNT(sxexm_amiga_hunk_length_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_amiga_hunk_table_fields[] = {
 SX_FIELD("table_size","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("first_hunk","uint32",4,4,SX_ID),
 SX_FIELD("last_hunk","uint32",8,4,SX_ID),
};
const sx_layout sxexm_amiga_hunk_table = {UINT32_C(0x602b0048),"amiga_hunk_table",sxexm_amiga_hunk_table_fields,SX_COUNT(sxexm_amiga_hunk_table_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_amiga_hunk_allocation_fields[] = {
 SX_FIELD("size_and_memory_flags","uint32",0,4,SX_FLAGS),
};
const sx_layout sxexm_amiga_hunk_allocation = {UINT32_C(0x602b0049),"amiga_hunk_allocation",sxexm_amiga_hunk_allocation_fields,SX_COUNT(sxexm_amiga_hunk_allocation_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_amiga_memory_flags_fields[] = {
 SX_FIELD("memory_flags","uint32",0,4,SX_FLAGS),
};
const sx_layout sxexm_amiga_memory_flags = {UINT32_C(0x602b004a),"amiga_memory_flags",sxexm_amiga_memory_flags_fields,SX_COUNT(sxexm_amiga_memory_flags_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_amiga_relocation_count16_fields[] = {
 SX_FIELD("count","uint16",0,2,SX_COUNT_PROP),
};
const sx_layout sxexm_amiga_relocation_count16 = {UINT32_C(0x602b004b),"amiga_relocation_count16",sxexm_amiga_relocation_count16_fields,SX_COUNT(sxexm_amiga_relocation_count16_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_amiga_relocation_target16_fields[] = {
 SX_FIELD("hunk_index","uint16",0,2,SX_ID),
};
const sx_layout sxexm_amiga_relocation_target16 = {UINT32_C(0x602b004c),"amiga_relocation_target16",sxexm_amiga_relocation_target16_fields,SX_COUNT(sxexm_amiga_relocation_target16_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_amiga_relocation_offset16_fields[] = {
 SX_FIELD("offset","uint16",0,2,SX_OFFSET),
};
const sx_layout sxexm_amiga_relocation_offset16 = {UINT32_C(0x602b004d),"amiga_relocation_offset16",sxexm_amiga_relocation_offset16_fields,SX_COUNT(sxexm_amiga_relocation_offset16_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_amiga_relocation_count32_fields[] = {
 SX_FIELD("count","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxexm_amiga_relocation_count32 = {UINT32_C(0x602b004e),"amiga_relocation_count32",sxexm_amiga_relocation_count32_fields,SX_COUNT(sxexm_amiga_relocation_count32_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_amiga_relocation_target32_fields[] = {
 SX_FIELD("hunk_index","uint32",0,4,SX_ID),
};
const sx_layout sxexm_amiga_relocation_target32 = {UINT32_C(0x602b004f),"amiga_relocation_target32",sxexm_amiga_relocation_target32_fields,SX_COUNT(sxexm_amiga_relocation_target32_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_amiga_relocation_offset32_fields[] = {
 SX_FIELD("offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxexm_amiga_relocation_offset32 = {UINT32_C(0x602b0050),"amiga_relocation_offset32",sxexm_amiga_relocation_offset32_fields,SX_COUNT(sxexm_amiga_relocation_offset32_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_amiga_symbol_value_fields[] = {
 SX_FIELD("value","uint32",0,4,SX_NONE),
};
const sx_layout sxexm_amiga_symbol_value = {UINT32_C(0x602b0051),"amiga_symbol_value",sxexm_amiga_symbol_value_fields,SX_COUNT(sxexm_amiga_symbol_value_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_amiga_ext_name_fields[] = {
 SX_FIELD("type","uint8",0,1,SX_ID),
 SX_FIELD("name_longwords","uint24",1,3,SX_COUNT_PROP),
};
const sx_layout sxexm_amiga_ext_name = {UINT32_C(0x602b0052),"amiga_ext_name",sxexm_amiga_ext_name_fields,SX_COUNT(sxexm_amiga_ext_name_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_amiga_common_size_fields[] = {
 SX_FIELD("common_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxexm_amiga_common_size = {UINT32_C(0x602b0053),"amiga_common_size",sxexm_amiga_common_size_fields,SX_COUNT(sxexm_amiga_common_size_fields),SX_BE};
#define SXEXM_LIMIT 20000U
static bool sxexm_hunk_counted(sx_context*c,uint64_t*p,const sx_layout*l,bool skip){uint64_t n;if(!sxexm_word(c,*p,4,true,&n)||!sxexm_add(c,l,*p))return false;*p+=4;if(skip){if(n>UINT32_MAX/4||!sxexm_span(c,*p,n*4))return false;*p+=n*4;}return true;}
static bool sxexm_hunk(sx_context*c){uint64_t p=0;unsigned budget=0;while(sxexm_span(c,p,4)&&budget++<SXEXM_LIMIT&&c->count<SXEXM_LIMIT){uint64_t start=p,v;if(!sxexm_word(c,p,4,true,&v))break;unsigned id=(unsigned)v&0x3fffffff;size_t old=c->count;if(!sxexm_add(c,&sxexm_amiga_hunk_tag,p))return false;p+=4;bool ok=true;
 if(id==0x3f3){for(;;){uint64_t n;if(++budget>SXEXM_LIMIT||!sxexm_word(c,p,4,true,&n)){ok=false;break;}if(!sxexm_hunk_counted(c,&p,&sxexm_amiga_hunk_length,true)){ok=false;break;}if(!n)break;}uint8_t b[12];if(!ok||!sxexm_read(c,p,b,12)){ok=false;}else{uint64_t first=sxexm32(b+4,true),last=sxexm32(b+8,true);if(last<first||last-first>=SXEXM_LIMIT)ok=false;else{ok=sxexm_add(c,&sxexm_amiga_hunk_table,p);p+=12;for(uint64_t i=first;ok&&i<=last;i++){if(++budget>=SXEXM_LIMIT){ok=false;break;}uint64_t n;if(!sxexm_word(c,p,4,true,&n)||!sxexm_add(c,&sxexm_amiga_hunk_allocation,p)){ok=false;break;}p+=4;if((n>>30)==3){ok=sxexm_add(c,&sxexm_amiga_memory_flags,p);p+=4;}}}}}
 else if(id==0x3e7||id==0x3e8||id==0x3e9||id==0x3ea||id==0x3f1||id==0x4e9)ok=sxexm_hunk_counted(c,&p,&sxexm_amiga_hunk_length,true);
 else if(id==0x3eb)ok=sxexm_hunk_counted(c,&p,&sxexm_amiga_hunk_length,false);
 else if(id==0x3ec||id==0x3ed||id==0x3ee||id==0x3f7||id==0x3f8||id==0x3f9||id==0x3fc||id==0x3ff){unsigned width=(id==0x3fc||id==0x3ff)?2:4;const sx_layout*count=width==2?&sxexm_amiga_relocation_count16:&sxexm_amiga_relocation_count32,*target=width==2?&sxexm_amiga_relocation_target16:&sxexm_amiga_relocation_target32,*offset=width==2?&sxexm_amiga_relocation_offset16:&sxexm_amiga_relocation_offset32;for(;;){uint64_t n;if(++budget>SXEXM_LIMIT||!sxexm_word(c,p,width,true,&n)||!sxexm_add(c,count,p)){ok=false;break;}p+=width;if(!n){if(width==2)p=start+((p-start+3)&~UINT64_C(3));break;}if(n>SXEXM_LIMIT||!sxexm_span(c,p,(n+1)*width)||!sxexm_add(c,target,p)||!sxexm_table(c,offset,p+width,n)){ok=false;break;}p+=(n+1)*width;}}
 else if(id==0x3f0||id==0x3ef){for(;;){uint64_t n;if(++budget>SXEXM_LIMIT||!sxexm_word(c,p,4,true,&n)){ok=false;break;}if(!sxexm_add(c,id==0x3ef?&sxexm_amiga_ext_name:&sxexm_amiga_hunk_length,p)){ok=false;break;}p+=4;if(!n)break;unsigned type=id==0x3ef?(unsigned)(n>>24):0;n=id==0x3ef?n&0xffffff:n;if(n>UINT32_MAX/4||!sxexm_span(c,p,n*4)){ok=false;break;}p+=n*4;if(type<=3){ok=sxexm_add(c,&sxexm_amiga_symbol_value,p);p+=4;}else if(type>=128){if(type==130){ok=sxexm_add(c,&sxexm_amiga_common_size,p);p+=4;}uint64_t refs;if(!ok||!sxexm_word(c,p,4,true,&refs)||refs>SXEXM_LIMIT||!sxexm_span(c,p+4,refs*4)){ok=false;break;}ok=sxexm_add(c,&sxexm_amiga_relocation_count32,p)&&sxexm_table(c,&sxexm_amiga_relocation_offset32,p+4,refs);p+=4+refs*4;}else ok=false;if(!ok)break;}}
 else if(id!=0x3f2)ok=false;if(!ok||p>(uint64_t)c->size){c->count=old;break;}if(p<=start)break;}return c->count!=0;}
bool sx_amigahunk_build(sx_context*c)
{
bool ok=false;
ok=sxexm_hunk(c);
return ok&&sxexm_finish(c);
}
