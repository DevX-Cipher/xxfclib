/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * PYC data structures, moved out of the executablemore schema family. */
#include "../../xx_format_schema_executablemore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxexm_pyc_header8_fields[] = {
 SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("newline","uint16",2,2,SX_SIGNATURE),
 SX_FIELD("timestamp","uint32",4,4,SX_TIME),
};
const sx_layout sxexm_pyc_header8 = {UINT32_C(0x602b0003),"pyc_header8",sxexm_pyc_header8_fields,SX_COUNT(sxexm_pyc_header8_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_pyc_header12_fields[] = {
 SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("newline","uint16",2,2,SX_SIGNATURE),
 SX_FIELD("timestamp","uint32",4,4,SX_TIME),
 SX_FIELD("source_size","uint32",8,4,SX_SIZE),
};
const sx_layout sxexm_pyc_header12 = {UINT32_C(0x602b0004),"pyc_header12",sxexm_pyc_header12_fields,SX_COUNT(sxexm_pyc_header12_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_pyc_header16_timestamp_fields[] = {
 SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("newline","uint16",2,2,SX_SIGNATURE),
 SX_FIELD("flags","uint32",4,4,SX_FLAGS),
 SX_FIELD("timestamp","uint32",8,4,SX_TIME),
 SX_FIELD("source_size","uint32",12,4,SX_SIZE),
};
const sx_layout sxexm_pyc_header16_timestamp = {UINT32_C(0x602b0005),"pyc_header16_timestamp",sxexm_pyc_header16_timestamp_fields,SX_COUNT(sxexm_pyc_header16_timestamp_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_pyc_header16_hash_fields[] = {
 SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("newline","uint16",2,2,SX_SIGNATURE),
 SX_FIELD("flags","uint32",4,4,SX_FLAGS),
 SX_FIELD("source_hash","uint8[8]",8,8,SX_CHECKSUM),
};
const sx_layout sxexm_pyc_header16_hash = {UINT32_C(0x602b0006),"pyc_header16_hash",sxexm_pyc_header16_hash_fields,SX_COUNT(sxexm_pyc_header16_hash_fields),SX_LE};
static bool sxexm_pyc(sx_context*c){uint8_t h[8];if(!sxexm_read(c,0,h,8))return false;uint64_t magic=sxexm16(h,false);/* Historical Python 1/2 magics are above 5000; modern Python3 magics are 3000..4999. */unsigned size=magic>=3000&&magic<5000?(magic>=3392?16:magic>=3210?12:8):8;const sx_layout*l=size==8?&sxexm_pyc_header8:size==12?&sxexm_pyc_header12:(sxexm32(h+4,false)&1)?&sxexm_pyc_header16_hash:&sxexm_pyc_header16_timestamp;return sxexm_add(c,l,0);}
bool sx_pyc_build(sx_context*c)
{
bool ok=false;
ok=sxexm_pyc(c);
return ok&&sxexm_finish(c);
}
