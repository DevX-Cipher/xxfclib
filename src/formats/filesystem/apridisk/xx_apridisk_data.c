/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * APRIDISK data structures, moved out of the systemlater schema family. */
#include "../../xx_format_schema_systemlater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsl_apridisk_header_fields[] = {
    SX_FIELD("signature","char[24]",0,24,SX_SIGNATURE),
    SX_FIELD("reserved","byte[104]",24,104,SX_RESERVED),
};
const sx_layout sxsl_apridisk_header = {0x6033000fU,"apridisk_header",sxsl_apridisk_header_fields,SX_COUNT(sxsl_apridisk_header_fields),SX_LE};
static const xx_data_struct_field_desc sxsl_apridisk_record_fields[] = {
    SX_FIELD("type","uint32",0,4,SX_ID),
    SX_FIELD("compression","uint16",4,2,SX_ID),
    SX_FIELD("header_size","uint16",6,2,SX_SIZE),
    SX_FIELD("data_size","uint32",8,4,SX_SIZE),
    SX_FIELD("head","uint8",12,1,SX_NONE),
    SX_FIELD("sector","uint8",13,1,SX_NONE),
    SX_FIELD("cylinder","uint16",14,2,SX_NONE),
};
const sx_layout sxsl_apridisk_record = {0x60330010U,"apridisk_record",sxsl_apridisk_record_fields,SX_COUNT(sxsl_apridisk_record_fields),SX_LE};
#define SXSL_LIMIT 24000U
#define SXSL_ADD(c,l,p) sxsl_put(c,&sxsl_##l,p,1)
static bool sxsl_apridisk(sx_context*c){if(!SXSL_ADD(c,apridisk_header,0))return false;uint64_t p=128;uint8_t b[16];for(unsigned i=0;i<SXSL_LIMIT&&c->count<SXSL_LIMIT;i++){if(!sxsl_read(c,p,b,16))break;uint64_t h=sxsl16(b+6),z=sxsl32(b+8);if(h<16||!sxsl_span(c,p,h+z)||!SXSL_ADD(c,apridisk_record,p))break;p+=h+z;}return true;}
bool sx_apridisk_build(sx_context*c)
{
bool ok=false;
ok=sxsl_apridisk(c);
return ok&&sxsl_finish(c);
}
