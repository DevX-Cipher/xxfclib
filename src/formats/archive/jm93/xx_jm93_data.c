/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * JM93 data structures, moved out of the archivesystems schema family. */
#include "../../xx_format_schema_archivesystems.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxasy_jm93_header_fields[] = {
 SX_FIELD("signature","char[5]",0,5,SX_SIGNATURE),
 SX_FIELD("name","char[60]",5,60,SX_NONE),
 SX_FIELD("compressed_size","uint32",65,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",69,4,SX_SIZE),
};
const sx_layout sxasy_jm93_header = {UINT32_C(0x60440019),"jm93_header",sxasy_jm93_header_fields,SX_COUNT(sxasy_jm93_header_fields),SX_LE};
static bool sxasy_jm(sx_context*c){uint64_t n;return sxasy_word(c,65,4,false,&n)&&sxasy_add(c,&sxasy_jm93_header,0)&&sxasy_dcl(c,73,n);}
bool sx_jm93_build(sx_context*c)
{
 return sxasy_jm(c);
}
