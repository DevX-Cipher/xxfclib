/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * DISKCOPY42 data structures, moved out of the systemlater schema family. */
#include "../../xx_format_schema_systemlater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsl_diskcopy42_header_fields[] = {
    SX_FIELD("name_size","uint8",0,1,SX_SIZE),
    SX_FIELD("disk_name","char[63]",1,63,SX_NONE),
    SX_FIELD("data_size","uint32",64,4,SX_SIZE),
    SX_FIELD("tag_size","uint32",68,4,SX_SIZE),
    SX_FIELD("data_checksum","uint32",72,4,SX_CHECKSUM),
    SX_FIELD("tag_checksum","uint32",76,4,SX_CHECKSUM),
    SX_FIELD("disk_format","uint8",80,1,SX_ID),
    SX_FIELD("format_byte","uint8",81,1,SX_ID),
    SX_FIELD("private_word","uint16",82,2,SX_ID),
};
const sx_layout sxsl_diskcopy42_header = {0x60330011U,"diskcopy42_header",sxsl_diskcopy42_header_fields,SX_COUNT(sxsl_diskcopy42_header_fields),SX_BE};
#define SXSL_ADD(c,l,p) sxsl_put(c,&sxsl_##l,p,1)
bool sx_diskcopy42_build(sx_context*c)
{
bool ok=false;
ok=SXSL_ADD(c,diskcopy42_header,0);
return ok&&sxsl_finish(c);
}
