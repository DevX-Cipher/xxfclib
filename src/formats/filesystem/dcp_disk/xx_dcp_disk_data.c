/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Dcp Disk data structures, moved out of the disknext schema family. */
#include "../../xx_format_schema_disknext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"
#if SX_ALIAS_READER_FACTORY
#include "xxfclib/formats/filesystem/psa_disk/xx_psa_disk.h"
#endif

static const xx_data_struct_field_desc sxdn_dcp_disk_header_fields[] = {
    SX_FIELD("sectors_per_track","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("heads","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("cylinders","uint16",4,2,SX_COUNT_PROP),
    SX_FIELD("unknown","byte[82]",6,82,SX_NONE),
    SX_FIELD("format_value","uint8",88,1,SX_NONE),
    SX_FIELD("unknown2","uint8",89,1,SX_NONE),
    SX_FIELD("compression","uint16",90,2,SX_ID),
    SX_FIELD("signature","char[4]",92,4,SX_SIGNATURE),
};
const sx_layout sxdn_dcp_disk_header = {0x60780016U,"dcp_disk_header",sxdn_dcp_disk_header_fields,SX_COUNT(sxdn_dcp_disk_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_dcp_rdc_block_fields[] = {
    SX_FIELD("size_or_stored_length","int16",0,2,SX_NONE),
};
const sx_layout sxdn_dcp_rdc_block = {0x60780017U,"dcp_rdc_block",sxdn_dcp_rdc_block_fields,SX_COUNT(sxdn_dcp_rdc_block_fields),SX_LE};
#define SXDN_LIMIT 24000U
#define SXDN_ADD(c,l,p) sxdn_put(c,&sxdn_##l,p,1)
static bool sxdn_dcp(sx_context*c){uint8_t h[96];if(!sxdn_read(c,0,h,96)||!SXDN_ADD(c,dcp_disk_header,0))return false;if(!sxdn16(h+90,0))return true;for(uint64_t p=512;p<(uint64_t)c->size&&c->count<SXDN_LIMIT;){if(!sxdn_read(c,p,h,2)||!SXDN_ADD(c,dcp_rdc_block,p))break;uint64_t v=sxdn16(h,0),n=(v&0x8000)?65536-v:v;p+=2;if(!v||!sxdn_span(c,p,n))break;p+=n;}return true;}
bool sx_dcp_disk_build(sx_context*c)
{
 return sxdn_dcp(c);
}
#undef SXDN_LIMIT
#undef SXDN_ADD
