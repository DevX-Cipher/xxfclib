/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * minecraft_nbt data structures, moved out of the gameplatforms schema family. */
#include "../../xx_format_schema_gameplatforms.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgp_nbt_tag_fields[]={
 SX_FIELD("tag_id","uint8",0,1,SX_ID),
};
const sx_layout sxgp_nbt_tag={UINT32_C(0x6036006E),"nbt_tag",sxgp_nbt_tag_fields,SX_COUNT(sxgp_nbt_tag_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_nbt_string_fields[]={
 SX_FIELD("byte_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxgp_nbt_string={UINT32_C(0x6036006F),"nbt_string",sxgp_nbt_string_fields,SX_COUNT(sxgp_nbt_string_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_nbt_array_fields[]={
 SX_FIELD("element_count","int32",0,4,SX_COUNT_PROP),
};
const sx_layout sxgp_nbt_array={UINT32_C(0x60360070),"nbt_array",sxgp_nbt_array_fields,SX_COUNT(sxgp_nbt_array_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_nbt_list_fields[]={
 SX_FIELD("element_type","uint8",0,1,SX_ID),
 SX_FIELD("element_count","int32",1,4,SX_COUNT_PROP),
};
const sx_layout sxgp_nbt_list={UINT32_C(0x60360071),"nbt_list",sxgp_nbt_list_fields,SX_COUNT(sxgp_nbt_list_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_nbt_byte_fields[]={
 SX_FIELD("value","int8",0,1,SX_NONE),
};
const sx_layout sxgp_nbt_byte={UINT32_C(0x60360072),"nbt_byte",sxgp_nbt_byte_fields,SX_COUNT(sxgp_nbt_byte_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_nbt_short_fields[]={
 SX_FIELD("value","int16",0,2,SX_NONE),
};
const sx_layout sxgp_nbt_short={UINT32_C(0x60360073),"nbt_short",sxgp_nbt_short_fields,SX_COUNT(sxgp_nbt_short_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_nbt_int_fields[]={
 SX_FIELD("value","int32",0,4,SX_NONE),
};
const sx_layout sxgp_nbt_int={UINT32_C(0x60360074),"nbt_int",sxgp_nbt_int_fields,SX_COUNT(sxgp_nbt_int_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_nbt_long_fields[]={
 SX_FIELD("value","int64",0,8,SX_NONE),
};
const sx_layout sxgp_nbt_long={UINT32_C(0x60360075),"nbt_long",sxgp_nbt_long_fields,SX_COUNT(sxgp_nbt_long_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_nbt_float_fields[]={
 SX_FIELD("value","float",0,4,SX_NONE),
};
const sx_layout sxgp_nbt_float={UINT32_C(0x60360076),"nbt_float",sxgp_nbt_float_fields,SX_COUNT(sxgp_nbt_float_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_nbt_double_fields[]={
 SX_FIELD("value","double",0,8,SX_NONE),
};
const sx_layout sxgp_nbt_double={UINT32_C(0x60360077),"nbt_double",sxgp_nbt_double_fields,SX_COUNT(sxgp_nbt_double_fields),SX_BE};
#define SG_ROW(l,at,end) sxgp_row(v,&sxgp_##l,(at),(end))
static bool sxgp_nbt_text(sxgp_view*v,uint64_t*p,uint64_t end)
{uint64_t z;if(!SG_ROW(nbt_string,*p,end)||!sxgp_word(v,*p,2,true,&z,end)||!sxgp_span(v,*p+2,z,end))return false;*p+=2+z;return true;}
static bool sxgp_nbt_value(sxgp_view*v,uint64_t*p,uint64_t end,unsigned type,unsigned depth)
{if(depth>32||++v->work>4000000)return false;uint64_t n,kind;const sx_layout*scalars[]={&sxgp_nbt_byte,&sxgp_nbt_short,&sxgp_nbt_int,&sxgp_nbt_long,&sxgp_nbt_float,&sxgp_nbt_double};
 if(type>=1&&type<=6){const sx_layout*l=scalars[type-1];if(!sxgp_row(v,l,*p,end))return false;*p+=(uint64_t)l->fields[0].size;return true;}
 if(type==8)return sxgp_nbt_text(v,p,end);
 if(type==7||type==11||type==12){if(!SG_ROW(nbt_array,*p,end)||!sxgp_word(v,*p,4,true,&n,end)||n>1048576)return false;*p+=4;const sx_layout*l=type==7?&sxgp_nbt_byte:type==11?&sxgp_nbt_int:&sxgp_nbt_long;uint64_t z=(uint64_t)l->fields[0].size;if(!sxgp_table(v,l,*p,n,end))return false;*p+=n*z;return true;}
 if(type==9){if(!SG_ROW(nbt_list,*p,end)||!sxgp_word(v,*p,1,false,&kind,end)||!sxgp_word(v,*p+1,4,true,&n,end)||n>65536||kind>12||(!kind&&n))return false;*p+=5;for(uint64_t i=0;i<n;i++)if(!sxgp_nbt_value(v,p,end,(unsigned)kind,depth+1))return false;return true;}
 if(type==10){for(unsigned i=0;i<=4096;i++){if(!SG_ROW(nbt_tag,*p,end)||!sxgp_word(v,*p,1,false,&kind,end))return false;(*p)++;if(!kind)return true;if(i==4096||!sxgp_nbt_text(v,p,end)||!sxgp_nbt_value(v,p,end,(unsigned)kind,depth+1))return false;}}
 return false;}
static bool sxgp_nbt(sxgp_view*v){uint64_t end=(uint64_t)v->c->size,p=1;return SG_ROW(nbt_tag,0,end)&&sxgp_nbt_text(v,&p,end)&&sxgp_nbt_value(v,&p,end,10,0)&&p==end;}
bool sx_minecraft_nbt_build(sxgp_view*v)
{
 return sxgp_nbt(v);
}
#undef SG_ROW
