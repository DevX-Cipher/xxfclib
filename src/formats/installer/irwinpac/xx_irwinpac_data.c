/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * IrwinPac installation files (*.DL_, *.EX_ and friends) data structures, moved out of the archiveframes schema family. */
#include "../../xx_format_schema_archiveframes.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxafr_irwinpac_header_fields[] = {
 SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("header_size","uint16",8,2,SX_SIZE),
 SX_FIELD("opaque","uint8[10]",10,10,SX_NONE),
};
const sx_layout sxafr_irwinpac_header = {UINT32_C(0x60540017),"irwinpac_header",sxafr_irwinpac_header_fields,SX_COUNT(sxafr_irwinpac_header_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_irwinpac_block_fields[] = {
 SX_FIELD("compressed","uint16",0,2,SX_NONE),
 SX_FIELD("total_size","uint16",2,2,SX_SIZE),
 SX_FIELD("uncompressed_size","uint16",4,2,SX_SIZE),
 SX_FIELD("uninitialized","uint8[4]",6,4,SX_NONE),
};
const sx_layout sxafr_irwinpac_block = {UINT32_C(0x60540018),"irwinpac_block",sxafr_irwinpac_block_fields,SX_COUNT(sxafr_irwinpac_block_fields),SX_LE};
static bool sxafr_irwin(sx_context*c){uint64_t p=20;if(!sxafr_add(c,&sxafr_irwinpac_header,0))return false;while(p<(uint64_t)c->size){uint64_t z;if(!sxafr_word(c,p+2,2,false,&z)||z<10||!sxafr_span(c,p,z)||!sxafr_add(c,&sxafr_irwinpac_block,p))return false;p+=z;}return true;}
bool sx_irwinpac_build(sx_context*c)
{
 return sxafr_irwin(c);
}
