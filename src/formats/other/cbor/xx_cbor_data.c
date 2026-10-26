/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * cbor data structures, moved out of the binarylater schema family. */
#include "../../xx_format_schema_binarylater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxbl_cbor_tag_fields[] = {
 SX_FIELD("type_and_flags","uint8",0,1,SX_FLAGS),
};
const sx_layout sxbl_cbor_tag = {UINT32_C(0x60350036),"cbor_tag",sxbl_cbor_tag_fields,SX_COUNT(sxbl_cbor_tag_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_cbor_self_describe_fields[] = {
 SX_FIELD("tag","uint8[3]",0,3,SX_SIGNATURE),
};
const sx_layout sxbl_cbor_self_describe = {UINT32_C(0x60350092),"cbor_self_describe",sxbl_cbor_self_describe_fields,SX_COUNT(sxbl_cbor_self_describe_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_cbor_half_float_fields[] = {
 SX_FIELD("ieee754_binary16_bits","uint16",0,2,SX_NONE),
};
const sx_layout sxbl_cbor_half_float = {UINT32_C(0x60350093),"cbor_half_float",sxbl_cbor_half_float_fields,SX_COUNT(sxbl_cbor_half_float_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_cbor_negative_argument1_fields[] = {
 SX_FIELD("encoded_argument","uint8",0,1,SX_NONE),
};
const sx_layout sxbl_cbor_negative_argument1 = {UINT32_C(0x6035010c),"cbor_negative_argument1",sxbl_cbor_negative_argument1_fields,SX_COUNT(sxbl_cbor_negative_argument1_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_cbor_negative_argument2_fields[] = {
 SX_FIELD("encoded_argument","uint16",0,2,SX_NONE),
};
const sx_layout sxbl_cbor_negative_argument2 = {UINT32_C(0x6035010f),"cbor_negative_argument2",sxbl_cbor_negative_argument2_fields,SX_COUNT(sxbl_cbor_negative_argument2_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_cbor_negative_argument4_fields[] = {
 SX_FIELD("encoded_argument","uint32",0,4,SX_NONE),
};
const sx_layout sxbl_cbor_negative_argument4 = {UINT32_C(0x60350112),"cbor_negative_argument4",sxbl_cbor_negative_argument4_fields,SX_COUNT(sxbl_cbor_negative_argument4_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_cbor_negative_argument8_fields[] = {
 SX_FIELD("encoded_argument","uint64",0,8,SX_NONE),
};
const sx_layout sxbl_cbor_negative_argument8 = {UINT32_C(0x60350115),"cbor_negative_argument8",sxbl_cbor_negative_argument8_fields,SX_COUNT(sxbl_cbor_negative_argument8_fields),SX_BE};
#define SXBL_LIMIT 20000U
static bool sxbl_cbor(sx_context*c,uint64_t*p,uint64_t end,unsigned depth){uint8_t t;if(depth>32||!sxbl_byte(c,*p,&t)||!sxbl_emit(c,p,end,&sxbl_cbor_tag))return false;unsigned major=t>>5,ai=t&31,z=ai<24?0:ai<=27?1U<<(ai-24):0;uint64_t n=ai;if(ai>=24){if(!z||!sxbl_word(c,*p,z,true,&n))return false;if(major==7){if(ai==25)return sxbl_emit(c,p,end,&sxbl_cbor_half_float);if(ai==26||ai==27)return sxbl_float(c,p,end,z,true);}if(major==2||major==3||major==4||major==5){uint64_t x;if(!sxbl_length(c,p,end,z,true,major>=4,&x))return false;}else if(major==1){const sx_layout*const a[]={&sxbl_cbor_negative_argument1,&sxbl_cbor_negative_argument2,&sxbl_cbor_negative_argument4,&sxbl_cbor_negative_argument8};if(!sxbl_emit(c,p,end,a[ai-24]))return false;}else if(!sxbl_numeric(c,p,end,z,false,true))return false;}
 if(major<=1||major==7)return true;if(major==2||major==3)return sxbl_skip(c,p,end,n);if(major==6)return sxbl_cbor(c,p,end,depth+1);if(n>SXBL_LIMIT)return false;uint64_t count=n*(major==5?2U:1U);for(uint64_t i=0;i<count;i++)if(!sxbl_cbor(c,p,end,depth+1))return false;return true;}
bool sx_cbor_build(sx_context*c)
{
 uint64_t p=0,end=(uint64_t)c->size;bool ok=false;p=3;ok=sxbl_add(c,&sxbl_cbor_self_describe,0)&&sxbl_cbor(c,&p,end,0);return ok;
}
