/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * IBM Mwave DSP distribution files data structures, moved out of the binaryresources schema family. */
#include "../../xx_format_schema_binaryresources.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"

static const xx_data_struct_field_desc sxbrs_mwave_header_fields[] = {
    SX_FIELD("magic","uint8[2]",0,2,SX_SIGNATURE),
    SX_FIELD("dos_time","uint16",2,2,SX_TIME),
    SX_FIELD("dos_date","uint16",4,2,SX_TIME),
    SX_FIELD("constant","uint16",6,2,SX_SIGNATURE),
    SX_FIELD("filename","char[12]",8,12,SX_STRING),
    SX_FIELD("reserved","uint8[3]",20,3,SX_RESERVED),
    SX_FIELD("compress_flags","uint8",23,1,SX_FLAGS),
};
const sx_layout sxbrs_mwave_header = {UINT32_C(0x603e0019),"mwave_header",sxbrs_mwave_header_fields,SX_COUNT(sxbrs_mwave_header_fields),SX_LE};
#define N(p,w) sxbrs_num(c,(p),(w),false)
static bool sxbrs_mwave(sx_context*c){if(c->size<=24||!sxbrs_eq(c,0,"\x1f\x9d",2)||N(6,2)!=32||N(20,3))return false;uint64_t flags=N(23,1);if((flags&0x60)||(flags&31)<9||(flags&31)>16)return false;return sxbrs_add(c,&sxbrs_mwave_header,0);}
bool sx_mwave_build(sx_context*c)
{
 return sxbrs_mwave(c);
}
#undef N
