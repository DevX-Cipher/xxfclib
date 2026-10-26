/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * crystallography_mtz data structures, moved out of the scientificextra schema family. */
#include "../../xx_format_schema_scientificextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxscx_mtz_prefix_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("header_word_index","uint32",4,4,SX_NONE),
    SX_FIELD("machine_stamp","uint8[4]",8,4,SX_ID),
    SX_FIELD("reserved","uint8[68]",12,68,SX_RESERVED),
};
const sx_layout sxscx_mtz_prefix = {UINT32_C(0x6031000b),"mtz_prefix",sxscx_mtz_prefix_fields,SX_COUNT(sxscx_mtz_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_mtz_header_record_fields[] = {
    SX_FIELD("record_text","char[80]",0,80,SX_STRING),
};
const sx_layout sxscx_mtz_header_record = {UINT32_C(0x6031000c),"mtz_header_record",sxscx_mtz_header_record_fields,SX_COUNT(sxscx_mtz_header_record_fields),SX_LE};
static bool sxscx_mtz(sx_context *c,const uint8_t *b,size_t n){if(n<80)return false;uint64_t word=sxscx32(b+4,false);if(word<21)return false;uint64_t at=(word-1)*4;return at<=n&&(n-at)%80==0&&sxscx_add(c,&sxscx_mtz_prefix,0)&&sxscx_table(c,&sxscx_mtz_header_record,at,(n-at)/80);}
bool sx_crystallography_mtz_build(sx_context *c,uint8_t *b)
{
 return sxscx_mtz(c,b,(size_t)c->size);
}
