/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * earefpack data structures, moved out of the gamearchives schema family. */
#include "../../xx_format_schema_gamearchives.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxga_refpack_header24_fields[]={
 SX_FIELD("flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("marker","uint8",1,1,SX_SIGNATURE),
 SX_FIELD("decoded_bytes","uint24",2,3,SX_SIZE),
};
const sx_layout sxga_refpack_header24={UINT32_C(0x603B0019),"refpack_header24",sxga_refpack_header24_fields,SX_COUNT(sxga_refpack_header24_fields),SX_BE};
static const xx_data_struct_field_desc sxga_refpack_header24_packed_fields[]={
 SX_FIELD("flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("marker","uint8",1,1,SX_SIGNATURE),
 SX_FIELD("packed_bytes","uint24",2,3,SX_SIZE),
 SX_FIELD("decoded_bytes","uint24",5,3,SX_SIZE),
};
const sx_layout sxga_refpack_header24_packed={UINT32_C(0x603B001A),"refpack_header24_packed",sxga_refpack_header24_packed_fields,SX_COUNT(sxga_refpack_header24_packed_fields),SX_BE};
static const xx_data_struct_field_desc sxga_refpack_header32_fields[]={
 SX_FIELD("flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("marker","uint8",1,1,SX_SIGNATURE),
 SX_FIELD("decoded_bytes","uint32",2,4,SX_SIZE),
};
const sx_layout sxga_refpack_header32={UINT32_C(0x603B001B),"refpack_header32",sxga_refpack_header32_fields,SX_COUNT(sxga_refpack_header32_fields),SX_BE};
static const xx_data_struct_field_desc sxga_refpack_header32_packed_fields[]={
 SX_FIELD("flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("marker","uint8",1,1,SX_SIGNATURE),
 SX_FIELD("packed_bytes","uint32",2,4,SX_SIZE),
 SX_FIELD("decoded_bytes","uint32",6,4,SX_SIZE),
};
const sx_layout sxga_refpack_header32_packed={UINT32_C(0x603B001C),"refpack_header32_packed",sxga_refpack_header32_packed_fields,SX_COUNT(sxga_refpack_header32_packed_fields),SX_BE};
static bool sxga_refpack(sxga_view*v)
{uint64_t end=v->c->size,b;if(!sxga_word(v,0,1,false,&b,end))return false;const sx_layout*l=(b&1)?((b&128)?&sxga_refpack_header32_packed:&sxga_refpack_header32):((b&128)?&sxga_refpack_header24_packed:&sxga_refpack_header24);return sxga_row(v,l,0,end);}
bool sx_earefpack_build(sxga_view*v)
{
 return sxga_refpack(v);
}
