/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * TRDOS data structures, moved out of the systemtail schema family. */
#include "../../xx_format_schema_systemtail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxst_trdos_entry_fields[] = {
    SX_FIELD("name","char[8]",0,8,SX_NONE),
    SX_FIELD("extension","char[1]",8,1,SX_ID),
    SX_FIELD("start_address","uint16",9,2,SX_ADDRESS),
    SX_FIELD("byte_length","uint16",11,2,SX_SIZE),
    SX_FIELD("sector_count","uint8",13,1,SX_COUNT_PROP),
    SX_FIELD("first_sector","uint8",14,1,SX_NONE),
    SX_FIELD("first_track","uint8",15,1,SX_NONE),
};
const sx_layout sxst_trdos_entry = {0x60370008U,"trdos_entry",sxst_trdos_entry_fields,SX_COUNT(sxst_trdos_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxst_trdos_disk_descriptor_fields[] = {
    SX_FIELD("reserved","uint8",0,1,SX_RESERVED),
    SX_FIELD("first_free_sector","uint8",1,1,SX_NONE),
    SX_FIELD("first_free_track","uint8",2,1,SX_NONE),
    SX_FIELD("disk_type","uint8",3,1,SX_ID),
    SX_FIELD("file_count","uint8",4,1,SX_COUNT_PROP),
    SX_FIELD("free_sector_count","uint16",5,2,SX_COUNT_PROP),
    SX_FIELD("identifier","uint8",7,1,SX_SIGNATURE),
};
const sx_layout sxst_trdos_disk_descriptor = {0x60370009U,"trdos_disk_descriptor",sxst_trdos_disk_descriptor_fields,SX_COUNT(sxst_trdos_disk_descriptor_fields),SX_LE};
#define SXST_ADD(c,l,p) sxst_put(c,&sxst_##l,p,1)
#define SXST_TABLE(c,l,p,n) sxst_put(c,&sxst_##l,p,n)
static bool sxst_trdos(sx_context*c){if(!SXST_ADD(c,trdos_disk_descriptor,0x8e0))return false;uint8_t b;uint64_t n=0;for(;n<128;n++){if(!sxst_read(c,16*n,&b,1))break;if(!b){n++;break;}}return n&&SXST_TABLE(c,trdos_entry,0,n);}
bool sx_trdos_build(sx_context*c)
{
 return sxst_trdos(c);
}
#undef SXST_ADD
#undef SXST_TABLE
