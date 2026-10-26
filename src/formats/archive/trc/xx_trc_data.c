/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * TRC data structures, moved out of the archivesystems schema family. */
#include "../../xx_format_schema_archivesystems.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxasy_trc_header_fields[] = {
 SX_FIELD("signature","uint8[12]",0,12,SX_SIGNATURE),
 SX_FIELD("version","uint16",12,2,SX_NONE),
 SX_FIELD("crc32","uint32",14,4,SX_CHECKSUM),
 SX_FIELD("separator","char[1]",18,1,SX_SIGNATURE),
 SX_FIELD("opaque1","uint8[31]",19,31,SX_NONE),
 SX_FIELD("name","char[13]",50,13,SX_NONE),
 SX_FIELD("opaque2","uint8[4]",63,4,SX_NONE),
 SX_FIELD("uncompressed_size","int32",67,4,SX_SIZE),
 SX_FIELD("compressed_size","int32",71,4,SX_SIZE),
 SX_FIELD("signature2","char[8]",75,8,SX_SIGNATURE),
 SX_FIELD("opaque3","uint8[4]",83,4,SX_NONE),
 SX_FIELD("crc32_copy","uint32",87,4,SX_CHECKSUM),
 SX_FIELD("opaque4","uint8[68]",91,68,SX_NONE),
 SX_FIELD("uncompressed_size_copy","int32",159,4,SX_SIZE),
 SX_FIELD("opaque5","uint8[143]",163,143,SX_NONE),
};
const sx_layout sxasy_trc_header = {UINT32_C(0x60440033),"trc_header",sxasy_trc_header_fields,SX_COUNT(sxasy_trc_header_fields),SX_LE};
static bool sxasy_trc(sx_context*c){uint64_t n;return sxasy_word(c,71,4,false,&n)&&sxasy_add(c,&sxasy_trc_header,0)&&sxasy_dcl(c,306,n);}
bool sx_trc_build(sx_context*c)
{
 return sxasy_trc(c);
}
