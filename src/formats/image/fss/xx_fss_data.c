/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SSBOB slideshow data structures, moved out of the binaryresources schema family. */
#include "../../xx_format_schema_binaryresources.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"

static const xx_data_struct_field_desc sxbrs_fss_header_fields[] = {
    SX_FIELD("signature","char[5]",0,5,SX_SIGNATURE),
    SX_FIELD("marker_05","uint8",5,1,SX_NONE),
    SX_FIELD("opaque_6","uint8[1]",6,1,SX_NONE),
    SX_FIELD("marker_07","uint8",7,1,SX_NONE),
    SX_FIELD("descriptor_count","uint16",8,2,SX_COUNT_PROP),
    SX_FIELD("record_count","uint16",10,2,SX_COUNT_PROP),
    SX_FIELD("opaque_c","uint8[2]",12,2,SX_NONE),
    SX_FIELD("marker_0e","uint16",14,2,SX_SIGNATURE),
};
const sx_layout sxbrs_fss_header = {UINT32_C(0x603e0027),"fss_header",sxbrs_fss_header_fields,SX_COUNT(sxbrs_fss_header_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_fss_record_fields[] = {
    SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("data_size","uint32",4,4,SX_SIZE),
    SX_FIELD("kind","uint8",8,1,SX_ID),
    SX_FIELD("name","char[64]",9,64,SX_STRING),
    SX_FIELD("opaque_49","uint8[1]",73,1,SX_NONE),
};
const sx_layout sxbrs_fss_record = {UINT32_C(0x603e0028),"fss_record",sxbrs_fss_record_fields,SX_COUNT(sxbrs_fss_record_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_fss_end_fields[] = {
    SX_FIELD("file_size","uint32",0,4,SX_SIZE),
    SX_FIELD("reserved","uint32",4,4,SX_RESERVED),
};
const sx_layout sxbrs_fss_end = {UINT32_C(0x603e0029),"fss_end",sxbrs_fss_end_fields,SX_COUNT(sxbrs_fss_end_fields),SX_LE};
#define AL(n,k) do{if(!sxbrs_take(c,&sxbrs_##n,&at,end,(k)))return false;}while(0)
#define SK(n) do{if(!sxbrs_skip(&at,end,(n)))return false;}while(0)
#define N(p,w) sxbrs_num(c,(p),(w),false)
static bool sxbrs_fss(sx_context*c){int64_t at=0,end=c->size;uint64_t d=N(8,2),n=N(10,2);if(!sxbrs_eq(c,0,"SSBOB\1\0\1",8)||d<2||d>128||n<2||n>128||N(12,2)||N(14,2)!=65535)return false;AL(fss_header,1);SK((d-1)*12);AL(fss_record,n);if(N(at,4)!=(uint64_t)end||N(at+4,4))return false;AL(fss_end,1);return true;}
bool sx_fss_build(sx_context*c)
{
 return sxbrs_fss(c);
}
#undef AL
#undef SK
#undef N
