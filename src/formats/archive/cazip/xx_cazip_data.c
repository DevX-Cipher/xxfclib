/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * CAZIP data structures, moved out of the archivestreams schema family. */
#include "../../xx_format_schema_archivestreams.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxas_cazip_header_fields[] = {
 SX_FIELD("lead_in","uint8[3]",0,3,SX_SIGNATURE),
 SX_FIELD("signature","char[5]",3,5,SX_SIGNATURE),
 SX_FIELD("version","char[2]",8,2,SX_NONE),
 SX_FIELD("fixed_word","uint16",10,2,SX_NONE),
 SX_FIELD("volume_flag","uint16",12,2,SX_NONE),
 SX_FIELD("crc32","uint32",14,4,SX_CHECKSUM),
 SX_FIELD("reserved","uint8[2]",18,2,SX_NONE),
};
const sx_layout sxas_cazip_header = {UINT32_C(0x60430022),"cazip_header",sxas_cazip_header_fields,SX_COUNT(sxas_cazip_header_fields),SX_LE};
static const xx_data_struct_field_desc sxas_cazip_dcl_prefix_fields[] = {
 SX_FIELD("literal_mode","uint8",0,1,SX_NONE),
 SX_FIELD("dictionary_bits","uint8",1,1,SX_NONE),
};
const sx_layout sxas_cazip_dcl_prefix = {UINT32_C(0x60430023),"cazip_dcl_prefix",sxas_cazip_dcl_prefix_fields,SX_COUNT(sxas_cazip_dcl_prefix_fields),SX_LE};
bool sx_cazip_build(sx_context*c)
{
 bool ok=false;uint8_t b[8];if(sxas_read(c,0,b,8)&&!xx_rt_memcmp(b,"\r\n\032CAZIP",8))ok=sxas_add(c,&sxas_cazip_header,0)&&sxas_add(c,&sxas_cazip_dcl_prefix,20);return ok;
}
