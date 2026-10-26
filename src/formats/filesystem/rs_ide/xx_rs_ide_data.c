/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * RS_IDE data structures, moved out of the systemtail schema family. */
#include "../../xx_format_schema_systemtail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxst_rside_header_fields[] = {
    SX_FIELD("signature","char[7]",0,7,SX_SIGNATURE),
    SX_FIELD("revision","uint8",7,1,SX_ID),
    SX_FIELD("flags","uint8",8,1,SX_FLAGS),
    SX_FIELD("data_offset","uint16",9,2,SX_OFFSET),
    SX_FIELD("reserved","byte[11]",11,11,SX_RESERVED),
};
const sx_layout sxst_rside_header = {0x60370031U,"rside_header",sxst_rside_header_fields,SX_COUNT(sxst_rside_header_fields),SX_LE};
static const xx_data_struct_field_desc sxst_rside_identify_fields[] = {
    SX_FIELD("general_configuration","uint16",0,2,SX_FLAGS),
    SX_FIELD("cylinders","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("specific_configuration","uint16",4,2,SX_FLAGS),
    SX_FIELD("heads","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("obsolete_bytes_per_track","uint16",8,2,SX_SIZE),
    SX_FIELD("obsolete_bytes_per_sector","uint16",10,2,SX_SIZE),
    SX_FIELD("sectors_per_track","uint16",12,2,SX_COUNT_PROP),
    SX_FIELD("obsolete_vendor","byte[6]",14,6,SX_NONE),
    SX_FIELD("serial_number_words","byte[20]",20,20,SX_NONE),
    SX_FIELD("obsolete_buffer_type","uint16",40,2,SX_ID),
    SX_FIELD("obsolete_buffer_size","uint16",42,2,SX_NONE),
    SX_FIELD("obsolete_ecc_bytes","uint16",44,2,SX_SIZE),
    SX_FIELD("firmware_revision_words","byte[8]",46,8,SX_NONE),
    SX_FIELD("model_number_words","byte[40]",54,40,SX_NONE),
    SX_FIELD("multiple_sector_setting","uint16",94,2,SX_FLAGS),
    SX_FIELD("trusted_computing","uint16",96,2,SX_FLAGS),
    SX_FIELD("capabilities1","uint16",98,2,SX_FLAGS),
    SX_FIELD("capabilities2","uint16",100,2,SX_FLAGS),
    SX_FIELD("pio_timing_word","uint16",102,2,SX_FLAGS),
    SX_FIELD("dma_timing_word","uint16",104,2,SX_FLAGS),
};
const sx_layout sxst_rside_identify = {0x60370032U,"rside_identify",sxst_rside_identify_fields,SX_COUNT(sxst_rside_identify_fields),SX_LE};
#define SXST_ADD(c,l,p) sxst_put(c,&sxst_##l,p,1)
bool sx_rs_ide_build(sx_context*c)
{
 return SXST_ADD(c,rside_header,0)&&SXST_ADD(c,rside_identify,22);
}
#undef SXST_ADD
