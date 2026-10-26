/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * AIN data structures, moved out of the archiveextras schema family. */
#include "../../xx_format_schema_archiveextras.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxae_ain_header_fields[] = {
    SX_FIELD("magic","char[1]",0,1,SX_SIGNATURE),
    SX_FIELD("version_method","uint8",1,1,SX_FLAGS),
    SX_FIELD("flags","uint16",2,2,SX_FLAGS),
    SX_FIELD("unknown4","uint8[4]",4,4,SX_NONE),
    SX_FIELD("member_count","uint16",8,2,SX_COUNT_PROP),
    SX_FIELD("unknown10","uint8[4]",10,4,SX_NONE),
    SX_FIELD("directory_offset","uint32",14,4,SX_OFFSET),
    SX_FIELD("unknown18","uint8[4]",18,4,SX_NONE),
    SX_FIELD("header_checksum","uint16",22,2,SX_CHECKSUM),
};
const sx_layout sxae_ain_header = {UINT32_C(0x60170033),"ain_header",sxae_ain_header_fields,SX_COUNT(sxae_ain_header_fields),SX_LE};
static bool sxae_ain(sx_context *c){uint8_t b[24];uint32_t p;if(!sx_read(c,0,b,24)||b[0]!='!'||(p=sxae32(b+14))<24||p>=c->size)return false;return sxae_add(c,&sxae_ain_header,0);}
bool sx_ain_build(sx_context*c)
{
 return sxae_ain(c);
}
