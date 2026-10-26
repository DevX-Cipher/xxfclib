/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Photodex named-resource package data structures, moved out of the binaryresources schema family. */
#include "../../xx_format_schema_binaryresources.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"

static const xx_data_struct_field_desc sxbrs_px_header_fields[] = {
    SX_FIELD("signature","char[30]",0,30,SX_SIGNATURE),
    SX_FIELD("opaque_1e","uint8[4]",30,4,SX_NONE),
    SX_FIELD("version","uint16",34,2,SX_NONE),
    SX_FIELD("opaque_24","uint8[22]",36,22,SX_NONE),
    SX_FIELD("descriptor_count","uint32",58,4,SX_COUNT_PROP),
};
const sx_layout sxbrs_px_header = {UINT32_C(0x603e002a),"px_header",sxbrs_px_header_fields,SX_COUNT(sxbrs_px_header_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_px_block_fields[] = {
    SX_FIELD("reserved","uint16",0,2,SX_RESERVED),
    SX_FIELD("kind","uint16",2,2,SX_ID),
    SX_FIELD("payload_size","uint32",4,4,SX_SIZE),
    SX_FIELD("opaque_8","uint8[4]",8,4,SX_NONE),
};
const sx_layout sxbrs_px_block = {UINT32_C(0x603e002b),"px_block",sxbrs_px_block_fields,SX_COUNT(sxbrs_px_block_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_px_count_fields[] = {
    SX_FIELD("record_count","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxbrs_px_count = {UINT32_C(0x603e002c),"px_count",sxbrs_px_count_fields,SX_COUNT(sxbrs_px_count_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_px_record_fields[] = {
    SX_FIELD("category","char[32]",0,32,SX_STRING),
    SX_FIELD("payload_size","uint32",32,4,SX_SIZE),
    SX_FIELD("marker","uint8",36,1,SX_NONE),
};
const sx_layout sxbrs_px_record = {UINT32_C(0x603e002d),"px_record",sxbrs_px_record_fields,SX_COUNT(sxbrs_px_record_fields),SX_LE};
#define AL(n,k) do{if(!sxbrs_take(c,&sxbrs_##n,&at,end,(k)))return false;}while(0)
#define SK(n) do{if(!sxbrs_skip(&at,end,(n)))return false;}while(0)
#define N(p,w) sxbrs_num(c,(p),(w),false)
static bool sxbrs_px(sx_context*c){int64_t at=0,end=c->size;if(!sxbrs_eq(c,0,"Photodex Presenter Stream\x1a\n\r\n\x1a",30)||N(34,2)<1||N(34,2)>5)return false;uint64_t d=N(58,4),blocks=0;AL(px_header,1);SK(d*44);while(at<end){if(++blocks>100000||N(at,2)||N(at+2,2)!=1)return false;uint64_t z=N(at+4,4);AL(px_block,1);if(z<4||z>(uint64_t)(end-at))return false;int64_t blockend=at+(int64_t)z;uint64_t count=N(at,4);if(!count||count>100000)return false;AL(px_count,1);for(uint64_t j=0;j<count;j++){if(blockend-at<37||N(at+36,1)!=1)return false;z=N(at+32,4);AL(px_record,1);if(z>(uint64_t)(blockend-at))return false;SK(z);}if(at!=blockend)return false;}return blocks>0;}
bool sx_px_build(sx_context*c)
{
 return sxbrs_px(c);
}
#undef AL
#undef SK
#undef N
