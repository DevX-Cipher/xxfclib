/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Apple II Binary II data structures, moved out of the archivemore schema family. */
#include "../../xx_format_schema_archivemore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxar_binaryii_header_fields[] = {
    SX_FIELD("signature","char[3]",0,3,SX_SIGNATURE),
    SX_FIELD("access_low","uint8",3,1,SX_FLAGS),
    SX_FIELD("file_type_low","uint8",4,1,SX_NONE),
    SX_FIELD("auxiliary_type_low","uint16",5,2,SX_NONE),
    SX_FIELD("storage_type_low","uint8",7,1,SX_NONE),
    SX_FIELD("block_count_low","uint16",8,2,SX_NONE),
    SX_FIELD("modified_date","uint16",10,2,SX_NONE),
    SX_FIELD("modified_time","uint16",12,2,SX_NONE),
    SX_FIELD("created_date","uint16",14,2,SX_NONE),
    SX_FIELD("created_time","uint16",16,2,SX_NONE),
    SX_FIELD("identity","uint8",18,1,SX_SIGNATURE),
    SX_FIELD("reserved19","uint8",19,1,SX_RESERVED),
    SX_FIELD("eof_low","uint24",20,3,SX_NONE),
    SX_FIELD("name_size","uint8",23,1,SX_SIZE),
    SX_FIELD("name","char[64]",24,64,SX_STRING),
    SX_FIELD("unused88","uint8[21]",88,21,SX_NONE),
    SX_FIELD("auxiliary_type_high","uint16",109,2,SX_NONE),
    SX_FIELD("access_high","uint8",111,1,SX_FLAGS),
    SX_FIELD("file_type_high","uint8",112,1,SX_NONE),
    SX_FIELD("storage_type_high","uint8",113,1,SX_NONE),
    SX_FIELD("block_count_high","uint16",114,2,SX_NONE),
    SX_FIELD("eof_high","uint8",116,1,SX_NONE),
    SX_FIELD("unused117","uint8[4]",117,4,SX_NONE),
    SX_FIELD("operating_system","uint8",121,1,SX_ID),
    SX_FIELD("native_file_type","uint16",122,2,SX_ID),
    SX_FIELD("reserved124","uint8",124,1,SX_RESERVED),
    SX_FIELD("data_flags","uint8",125,1,SX_FLAGS),
    SX_FIELD("version","uint8",126,1,SX_ID),
    SX_FIELD("files_to_follow","uint8",127,1,SX_COUNT_PROP),
};
const sx_layout sxar_binaryii_header = {UINT32_C(0x601c0011),"binaryii_header",sxar_binaryii_header_fields,SX_COUNT(sxar_binaryii_header_fields),SX_LE};
#define SXAR_LIMIT 20000U
static bool sxar_binaryii(sx_context *c){uint64_t p=0;for(unsigned i=0;i<SXAR_LIMIT;i++){uint8_t b[128];if(!sxar_read(c,p,b,128)||xx_rt_memcmp(b,"\x0aGL",3))break;if(!sxar_add(c,&sxar_binaryii_header,p))return false;uint64_t n=b[7]==13?0:(uint64_t)sxar16(b+20,false)|((uint64_t)b[22]<<16)|((uint64_t)b[116]<<24);if(!b[127]||!sxar_span(c,p+128,n))break;p=(p+128+n+127)&~UINT64_C(127);}return c->count!=0;}
bool sx_binaryii_build(sx_context*c)
{
 return sxar_binaryii(c);
}
