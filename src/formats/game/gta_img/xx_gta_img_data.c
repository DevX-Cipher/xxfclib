/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * GTA IMG v2 archive data structures, moved out of the binaryextra schema family. */
#include "../../xx_format_schema_binaryextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxbx_gta_img_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("entry_count","uint32",4,4,SX_COUNT_PROP),
};
const sx_layout sxbx_gta_img_header = {UINT32_C(0x603000eb),"gta_img_header",sxbx_gta_img_header_fields,SX_COUNT(sxbx_gta_img_header_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_gta_img_entry_fields[] = {
 SX_FIELD("sector_offset","uint32",0,4,SX_NONE),
 SX_FIELD("sector_count","uint16",4,2,SX_COUNT_PROP),
 SX_FIELD("reserved","uint16",6,2,SX_NONE),
 SX_FIELD("filename","char[24]",8,24,SX_NONE),
};
const sx_layout sxbx_gta_img_entry = {UINT32_C(0x603000ec),"gta_img_entry",sxbx_gta_img_entry_fields,SX_COUNT(sxbx_gta_img_entry_fields),SX_LE};
bool sx_gta_img_build(sx_context*c)
{
 uint64_t n;return sxbx_word(c,4,4,false,&n)&&sxbx_add(c,&sxbx_gta_img_header,0)&&sxbx_table(c,&sxbx_gta_img_entry,8,n);
}
