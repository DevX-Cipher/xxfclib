/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * CMP data structures, moved out of the archiveclassic schema family. */
#include "../../xx_format_schema_archiveclassic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxacl_cmp_header_fields[] = {
 SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("header_size","uint16",2,2,SX_SIZE),
 SX_FIELD("method","uint16",4,2,SX_NONE),
 SX_FIELD("opaque1","uint8[8]",6,8,SX_NONE),
 SX_FIELD("variant","uint16",14,2,SX_NONE),
 SX_FIELD("opaque2","uint8[24]",16,24,SX_NONE),
 SX_FIELD("name","char[15]",40,15,SX_NONE),
 SX_FIELD("block_size","uint16",55,2,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",57,4,SX_SIZE),
};
const sx_layout sxacl_cmp_header = {UINT32_C(0x60500027),"cmp_header",sxacl_cmp_header_fields,SX_COUNT(sxacl_cmp_header_fields),SX_LE};
static bool sxacl_cmp(sx_context*c){uint64_t method;if(!sxacl_word(c,4,2,false,&method)||!sxacl_add(c,&sxacl_cmp_header,0))return false;return method!=2||sxacl_dcl(c,61,(uint64_t)c->size-61);}
bool sx_cmp_build(sx_context*c)
{
 return sxacl_cmp(c);
}
