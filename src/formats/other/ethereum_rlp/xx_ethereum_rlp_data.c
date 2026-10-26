/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ethereum rlp data structures, moved out of the binarylater schema family. */
#include "../../xx_format_schema_binarylater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxbl_rlp_tag_fields[] = {
 SX_FIELD("type_and_flags","uint8",0,1,SX_FLAGS),
};
const sx_layout sxbl_rlp_tag = {UINT32_C(0x60350041),"rlp_tag",sxbl_rlp_tag_fields,SX_COUNT(sxbl_rlp_tag_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_rlp_payload_size1_fields[] = {
 SX_FIELD("payload_size","uint8",0,1,SX_SIZE),
};
const sx_layout sxbl_rlp_payload_size1 = {UINT32_C(0x603500fd),"rlp_payload_size1",sxbl_rlp_payload_size1_fields,SX_COUNT(sxbl_rlp_payload_size1_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_rlp_payload_size2_fields[] = {
 SX_FIELD("payload_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxbl_rlp_payload_size2 = {UINT32_C(0x603500ff),"rlp_payload_size2",sxbl_rlp_payload_size2_fields,SX_COUNT(sxbl_rlp_payload_size2_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_rlp_payload_size3_fields[] = {
 SX_FIELD("payload_size","uint24",0,3,SX_SIZE),
};
const sx_layout sxbl_rlp_payload_size3 = {UINT32_C(0x60350101),"rlp_payload_size3",sxbl_rlp_payload_size3_fields,SX_COUNT(sxbl_rlp_payload_size3_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_rlp_payload_size4_fields[] = {
 SX_FIELD("payload_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxbl_rlp_payload_size4 = {UINT32_C(0x60350103),"rlp_payload_size4",sxbl_rlp_payload_size4_fields,SX_COUNT(sxbl_rlp_payload_size4_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_rlp_payload_size5_fields[] = {
 SX_FIELD("payload_size","uint40",0,5,SX_SIZE),
};
const sx_layout sxbl_rlp_payload_size5 = {UINT32_C(0x60350105),"rlp_payload_size5",sxbl_rlp_payload_size5_fields,SX_COUNT(sxbl_rlp_payload_size5_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_rlp_payload_size6_fields[] = {
 SX_FIELD("payload_size","uint48",0,6,SX_SIZE),
};
const sx_layout sxbl_rlp_payload_size6 = {UINT32_C(0x60350107),"rlp_payload_size6",sxbl_rlp_payload_size6_fields,SX_COUNT(sxbl_rlp_payload_size6_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_rlp_payload_size7_fields[] = {
 SX_FIELD("payload_size","uint56",0,7,SX_SIZE),
};
const sx_layout sxbl_rlp_payload_size7 = {UINT32_C(0x60350109),"rlp_payload_size7",sxbl_rlp_payload_size7_fields,SX_COUNT(sxbl_rlp_payload_size7_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_rlp_payload_size8_fields[] = {
 SX_FIELD("payload_size","uint64",0,8,SX_SIZE),
};
const sx_layout sxbl_rlp_payload_size8 = {UINT32_C(0x6035010b),"rlp_payload_size8",sxbl_rlp_payload_size8_fields,SX_COUNT(sxbl_rlp_payload_size8_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_rlp_literal_fields[] = {
 SX_FIELD("literal_byte","uint8",0,1,SX_NONE),
};
const sx_layout sxbl_rlp_literal = {UINT32_C(0x60350119),"rlp_literal",sxbl_rlp_literal_fields,SX_COUNT(sxbl_rlp_literal_fields),SX_LE};
static bool sxbl_rlp(sx_context*c,uint64_t*p,uint64_t end,unsigned depth){uint8_t t;if(depth>32||!sxbl_byte(c,*p,&t))return false;if(t<128)return sxbl_emit(c,p,end,&sxbl_rlp_literal);if(!sxbl_emit(c,p,end,&sxbl_rlp_tag))return false;bool list=t>=192;unsigned lb=list?247:183,sb=list?192:128;uint64_t n=t-sb;if(t>lb){unsigned z=t-lb;const sx_layout*const a[]={&sxbl_rlp_payload_size1,&sxbl_rlp_payload_size2,&sxbl_rlp_payload_size3,&sxbl_rlp_payload_size4,&sxbl_rlp_payload_size5,&sxbl_rlp_payload_size6,&sxbl_rlp_payload_size7,&sxbl_rlp_payload_size8};if(!z||z>8||!sxbl_word(c,*p,z,true,&n)||!sxbl_emit(c,p,end,a[z-1]))return false;}if(*p>end||n>end-*p)return false;uint64_t stop=*p+n;if(list){while(*p<stop)if(!sxbl_rlp(c,p,stop,depth+1))return false;return true;}return sxbl_skip(c,p,end,n);}
bool sx_ethereum_rlp_build(sx_context*c)
{
 uint64_t p=0,end=(uint64_t)c->size;return sxbl_rlp(c,&p,end,0);
}
