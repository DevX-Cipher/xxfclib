/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Genus pcxLib picture libraries data structures, moved out of the binaryresources schema family. */
#include "../../xx_format_schema_binaryresources.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"

static const xx_data_struct_field_desc sxbrs_pcxlib_header_fields[] = {
    SX_FIELD("magic","char[7]",0,7,SX_SIGNATURE),
    SX_FIELD("opaque_7","uint8[115]",7,115,SX_NONE),
};
const sx_layout sxbrs_pcxlib_header = {UINT32_C(0x603e001a),"pcxlib_header",sxbrs_pcxlib_header_fields,SX_COUNT(sxbrs_pcxlib_header_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_pcxlib_member_fields[] = {
    SX_FIELD("tag","uint8",0,1,SX_SIGNATURE),
    SX_FIELD("filename","char[13]",1,13,SX_STRING),
    SX_FIELD("stored_size","uint32",14,4,SX_SIZE),
    SX_FIELD("opaque_12","uint8[4]",18,4,SX_NONE),
    SX_FIELD("method","uint16",22,2,SX_ID),
    SX_FIELD("opaque_18","uint8[60]",24,60,SX_NONE),
};
const sx_layout sxbrs_pcxlib_member = {UINT32_C(0x603e001b),"pcxlib_member",sxbrs_pcxlib_member_fields,SX_COUNT(sxbrs_pcxlib_member_fields),SX_LE};
#define AL(n,k) do{if(!sxbrs_take(c,&sxbrs_##n,&at,end,(k)))return false;}while(0)
#define SK(n) do{if(!sxbrs_skip(&at,end,(n)))return false;}while(0)
#define N(p,w) sxbrs_num(c,(p),(w),false)
static bool sxbrs_pcxlib(sx_context*c){int64_t at=0,end=c->size;if(end<206||!sxbrs_eq(c,0,"pcxLib\0",7))return false;AL(pcxlib_header,1);uint64_t count=0;while(at<end){if(++count>1000000||N(at,1)!=1||N(at+22,2)!=0)return false;uint64_t n=N(at+14,4);AL(pcxlib_member,1);SK(n);}return count>0;}
bool sx_pcxlib_build(sx_context*c)
{
 return sxbrs_pcxlib(c);
}
#undef AL
#undef SK
#undef N
