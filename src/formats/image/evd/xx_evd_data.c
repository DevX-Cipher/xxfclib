/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * EVD map images data structures, moved out of the binaryresources schema family. */
#include "../../xx_format_schema_binaryresources.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"

static const xx_data_struct_field_desc sxbrs_evd_header_fields[] = {
    SX_FIELD("reserved0","uint32",0,4,SX_RESERVED),
    SX_FIELD("reserved1","uint32",4,4,SX_RESERVED),
    SX_FIELD("marker","uint32",8,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",12,4,SX_NONE),
    SX_FIELD("field_10","uint32",16,4,SX_NONE),
    SX_FIELD("field_14","uint32",20,4,SX_NONE),
};
const sx_layout sxbrs_evd_header = {UINT32_C(0x603e002e),"evd_header",sxbrs_evd_header_fields,SX_COUNT(sxbrs_evd_header_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_evd_record_fields[] = {
    SX_FIELD("image_type","uint16",0,2,SX_ID),
    SX_FIELD("repeated_image_type","uint16",2,2,SX_ID),
    SX_FIELD("image_id","uint32",4,4,SX_ID),
    SX_FIELD("payload_size","uint32",8,4,SX_SIZE),
};
const sx_layout sxbrs_evd_record = {UINT32_C(0x603e002f),"evd_record",sxbrs_evd_record_fields,SX_COUNT(sxbrs_evd_record_fields),SX_LE};
#define AL(n,k) do{if(!sxbrs_take(c,&sxbrs_##n,&at,end,(k)))return false;}while(0)
#define SK(n) do{if(!sxbrs_skip(&at,end,(n)))return false;}while(0)
#define N(p,w) sxbrs_num(c,(p),(w),false)
static bool sxbrs_evd(sx_context*c){int64_t at=0,end=c->size;if(N(0,4)||N(4,4)||N(8,4)!=12||(N(12,4)!=1&&N(12,4)!=2)||!N(16,4)||!N(20,4))return false;AL(evd_header,1);unsigned count=0;while(at<end){uint64_t type=N(at,2),z=N(at+8,4);if(++count>100000||(type!=1&&type!=2)||N(at+2,2)!=type||!N(at+4,4)||z<8)return false;AL(evd_record,1);if(type==1?!sxbrs_eq(c,at,"\xff\xd8\xff",3):!sxbrs_eq(c,at,"\x89PNG\r\n\x1a\n",8))return false;SK(z);}return count>0;}
bool sx_evd_build(sx_context*c)
{
 return sxbrs_evd(c);
}
#undef AL
#undef SK
#undef N
