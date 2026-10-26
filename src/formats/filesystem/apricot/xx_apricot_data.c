/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Apricot data structures, moved out of the systemtail schema family. */
#include "../../xx_format_schema_systemtail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxst_apricot_image_header_fields[] = {
    SX_FIELD("signature","char[22]",0,22,SX_SIGNATURE),
    SX_FIELD("opaque_preamble","byte[106]",22,106,SX_NONE),
};
const sx_layout sxst_apricot_image_header = {0x6037000eU,"apricot_image_header",sxst_apricot_image_header_fields,SX_COUNT(sxst_apricot_image_header_fields),SX_LE};
static const xx_data_struct_field_desc sxst_apricot_chunk_fields[] = {
    SX_FIELD("kind","uint16",0,2,SX_ID),
    SX_FIELD("tag","uint16",2,2,SX_SIGNATURE),
    SX_FIELD("subtype","uint16",4,2,SX_ID),
    SX_FIELD("header_size","uint16",6,2,SX_SIZE),
    SX_FIELD("data_size","int32",8,4,SX_SIZE),
    SX_FIELD("unknown_0c","byte[4]",12,4,SX_NONE),
};
const sx_layout sxst_apricot_chunk = {0x6037000fU,"apricot_chunk",sxst_apricot_chunk_fields,SX_COUNT(sxst_apricot_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxst_apricot_run_fields[] = {
    SX_FIELD("repeat_count","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("value","uint8",2,1,SX_ID),
};
const sx_layout sxst_apricot_run = {0x60370010U,"apricot_run",sxst_apricot_run_fields,SX_COUNT(sxst_apricot_run_fields),SX_LE};
#define SXST_LIMIT 24000U
#define SXST_ADD(c,l,p) sxst_put(c,&sxst_##l,p,1)
static bool sxst_apricot(sx_context*c){if(!SXST_ADD(c,apricot_image_header,0))return false;uint64_t p=128;uint8_t b[16];for(unsigned i=0;i<SXST_LIMIT&&c->count<SXST_LIMIT;i++){if(!sxst_read(c,p,b,16))break;uint64_t z=sxst32(b+8),h=sxst16(b+6);if(h<16||z>INT32_MAX||!sxst_span(c,p,h+z)||!SXST_ADD(c,apricot_chunk,p))break;if(sxst16(b)==1&&sxst16(b+4)==0x3e5a&&z==3&&!SXST_ADD(c,apricot_run,p+h))return false;p+=h+z;}return true;}
bool sx_apricot_build(sx_context*c)
{
 return sxst_apricot(c);
}
#undef SXST_LIMIT
#undef SXST_ADD
