/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * IGF1 data structures, moved out of the archivesystems schema family. */
#include "../../xx_format_schema_archivesystems.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxasy_igf1_header_fields[] = {
 SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("version","uint16",2,2,SX_NONE),
 SX_FIELD("opaque1","uint8[2]",4,2,SX_NONE),
 SX_FIELD("group_id","uint16",6,2,SX_NONE),
 SX_FIELD("opaque2","uint8[4]",8,4,SX_NONE),
 SX_FIELD("file_id","uint32",12,4,SX_NONE),
 SX_FIELD("pack_time","uint32",16,4,SX_NONE),
 SX_FIELD("file_time","uint32",20,4,SX_NONE),
 SX_FIELD("opaque3","uint8[4]",24,4,SX_NONE),
 SX_FIELD("uncompressed_size","int32",28,4,SX_SIZE),
 SX_FIELD("unpacked_checksum","uint32",32,4,SX_CHECKSUM),
 SX_FIELD("compressed_size","int32",36,4,SX_SIZE),
 SX_FIELD("packed_checksum","uint32",40,4,SX_CHECKSUM),
 SX_FIELD("data_offset","uint32",44,4,SX_OFFSET),
 SX_FIELD("complemented_data_offset","uint32_ones_le",48,4,SX_OFFSET),
 SX_FIELD("compressed_size_copy","int32",52,4,SX_SIZE),
};
const sx_layout sxasy_igf1_header = {UINT32_C(0x60440011),"igf1_header",sxasy_igf1_header_fields,SX_COUNT(sxasy_igf1_header_fields),SX_LE};
static bool sxasy_igf1(sx_context*c){return sxasy_add(c,&sxasy_igf1_header,0);}
bool sx_igf1_build(sx_context*c)
{
 return sxasy_igf1(c);
}
