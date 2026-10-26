/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * MUB data structures, moved out of the executablemore schema family. */
#include "../../xx_format_schema_executablemore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxexm_mub_header_le_fields[] = {
 SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("slice_count","uint32",4,4,SX_COUNT_PROP),
};
const sx_layout sxexm_mub_header_le = {UINT32_C(0x602b000c),"mub_header_le",sxexm_mub_header_le_fields,SX_COUNT(sxexm_mub_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_mub_arch32_le_fields[] = {
 SX_FIELD("cpu_type","int32",0,4,SX_ID),
 SX_FIELD("cpu_subtype","int32",4,4,SX_ID),
 SX_FIELD("slice_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("slice_size","uint32",12,4,SX_SIZE),
 SX_FIELD("alignment_shift","uint32",16,4,SX_NONE),
};
const sx_layout sxexm_mub_arch32_le = {UINT32_C(0x602b000d),"mub_arch32_le",sxexm_mub_arch32_le_fields,SX_COUNT(sxexm_mub_arch32_le_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_mub_header_be_fields[] = {
 SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("slice_count","uint32",4,4,SX_COUNT_PROP),
};
const sx_layout sxexm_mub_header_be = {UINT32_C(0x602b000e),"mub_header_be",sxexm_mub_header_be_fields,SX_COUNT(sxexm_mub_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_mub_arch32_be_fields[] = {
 SX_FIELD("cpu_type","int32",0,4,SX_ID),
 SX_FIELD("cpu_subtype","int32",4,4,SX_ID),
 SX_FIELD("slice_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("slice_size","uint32",12,4,SX_SIZE),
 SX_FIELD("alignment_shift","uint32",16,4,SX_NONE),
};
const sx_layout sxexm_mub_arch32_be = {UINT32_C(0x602b000f),"mub_arch32_be",sxexm_mub_arch32_be_fields,SX_COUNT(sxexm_mub_arch32_be_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_mub_arch64_be_fields[] = {
 SX_FIELD("cpu_type","int32",0,4,SX_ID),
 SX_FIELD("cpu_subtype","int32",4,4,SX_ID),
 SX_FIELD("slice_offset","uint64",8,8,SX_OFFSET),
 SX_FIELD("slice_size","uint64",16,8,SX_SIZE),
 SX_FIELD("alignment_shift","uint32",24,4,SX_NONE),
 SX_FIELD("reserved","uint32",28,4,SX_RESERVED),
};
const sx_layout sxexm_mub_arch64_be = {UINT32_C(0x602b0010),"mub_arch64_be",sxexm_mub_arch64_be_fields,SX_COUNT(sxexm_mub_arch64_be_fields),SX_BE};
static bool sxexm_mub(sx_context*c){uint8_t h[8];if(!sxexm_read(c,0,h,8))return false;uint32_t magic=sxexm32(h,true);bool be=magic!=0xb9faf10eU,fat64=magic==0xcafebabfU;if(magic!=0xcafebabeU&&magic!=0xcafebabfU&&magic!=0xb9faf10eU)return false;uint64_t n=sxexm32(h+4,be);return sxexm_add(c,be?&sxexm_mub_header_be:&sxexm_mub_header_le,0)&&sxexm_table(c,fat64?&sxexm_mub_arch64_be:be?&sxexm_mub_arch32_be:&sxexm_mub_arch32_le,8,n);}
bool sx_mub_build(sx_context*c)
{
bool ok=false;
ok=sxexm_mub(c);
return ok&&sxexm_finish(c);
}
