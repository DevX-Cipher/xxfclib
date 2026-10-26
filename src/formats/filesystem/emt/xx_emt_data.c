/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Emt data structures, moved out of the disknext schema family. */
#include "../../xx_format_schema_disknext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"
#if SX_ALIAS_READER_FACTORY
#include "xxfclib/formats/filesystem/psa_disk/xx_psa_disk.h"
#endif

static const xx_data_struct_field_desc sxdn_emt_header_fields[] = {
    SX_FIELD("marker","byte[3]",0,3,SX_SIGNATURE),
    SX_FIELD("producer_ebcdic","byte[4]",3,4,SX_NONE),
    SX_FIELD("version_digits_ebcdic","byte[6]",7,6,SX_NONE),
    SX_FIELD("text_ebcdic","byte[51]",13,51,SX_NONE),
    SX_FIELD("product_banner_ebcdic","byte[16]",64,16,SX_NONE),
    SX_FIELD("unknown","byte[8]",80,8,SX_NONE),
    SX_FIELD("marker_1","uint8",88,1,SX_SIGNATURE),
    SX_FIELD("unknown2","byte[3]",89,3,SX_NONE),
    SX_FIELD("marker_2","uint32",92,4,SX_SIGNATURE),
};
const sx_layout sxdn_emt_header = {0x60780001U,"emt_header",sxdn_emt_header_fields,SX_COUNT(sxdn_emt_header_fields),SX_LE};
#define SXDN_ADD(c,l,p) sxdn_put(c,&sxdn_##l,p,1)
bool sx_emt_build(sx_context*c)
{
 return SXDN_ADD(c,emt_header,0);
}
#undef SXDN_ADD
