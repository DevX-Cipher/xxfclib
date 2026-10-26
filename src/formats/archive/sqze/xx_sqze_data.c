/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SQZE compressed archive data structures, moved out of the archivestreams schema family. */
#include "../../xx_format_schema_archivestreams.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxas_sqze_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_NONE),
 SX_FIELD("header_size","uint32",8,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",12,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",16,4,SX_SIZE),
 SX_FIELD("compressed_crc32","uint32",20,4,SX_CHECKSUM),
};
const sx_layout sxas_sqze_header = {UINT32_C(0x60430001),"sqze_header",sxas_sqze_header_fields,SX_COUNT(sxas_sqze_header_fields),SX_LE};
bool sx_sqze_build(sx_context*c)
{
 return sxas_add(c,&sxas_sqze_header,0);
}
