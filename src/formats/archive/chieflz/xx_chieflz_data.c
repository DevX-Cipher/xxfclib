/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * CHIEFLZ data structures, moved out of the archivestreams schema family. */
#include "../../xx_format_schema_archivestreams.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxas_chieflz_prefix_fields[] = {
 SX_FIELD("signature_size","uint8",0,1,SX_SIZE),
 SX_FIELD("signature","char[8]",1,8,SX_SIGNATURE),
 SX_FIELD("opaque0","uint8[2]",9,2,SX_NONE),
 SX_FIELD("uncompressed_size","int32",11,4,SX_SIZE),
 SX_FIELD("opaque1","uint8[4]",15,4,SX_NONE),
 SX_FIELD("dos_date","uint16",19,2,SX_NONE),
 SX_FIELD("dos_time","uint16",21,2,SX_NONE),
 SX_FIELD("opaque2","uint8[4]",23,4,SX_NONE),
 SX_FIELD("crc32","uint32",27,4,SX_CHECKSUM),
};
const sx_layout sxas_chieflz_prefix = {UINT32_C(0x6043001d),"chieflz_prefix",sxas_chieflz_prefix_fields,SX_COUNT(sxas_chieflz_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxas_chieflz_name_size_fields[] = {
 SX_FIELD("name_size","uint8",0,1,SX_SIZE),
};
const sx_layout sxas_chieflz_name_size = {UINT32_C(0x6043001e),"chieflz_name_size",sxas_chieflz_name_size_fields,SX_COUNT(sxas_chieflz_name_size_fields),SX_LE};
static const xx_data_struct_field_desc sxas_chieflz_method_fields[] = {
 SX_FIELD("method","uint8",0,1,SX_NONE),
};
const sx_layout sxas_chieflz_method = {UINT32_C(0x6043001f),"chieflz_method",sxas_chieflz_method_fields,SX_COUNT(sxas_chieflz_method_fields),SX_LE};
static bool sxas_chief(sx_context*c){return sxas_span(c,0,257)&&sxas_add(c,&sxas_chieflz_prefix,0)&&sxas_add(c,&sxas_chieflz_name_size,40)&&sxas_add(c,&sxas_chieflz_method,173);}
bool sx_chieflz_build(sx_context*c)
{
 return sxas_chief(c);
}
