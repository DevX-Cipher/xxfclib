/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Zx Hobeta data structures, moved out of the disknext schema family. */
#include "../../xx_format_schema_disknext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"
#if SX_ALIAS_READER_FACTORY
#include "xxfclib/formats/filesystem/psa_disk/xx_psa_disk.h"
#endif

static const xx_data_struct_field_desc sxdn_hobeta_header_fields[] = {
    SX_FIELD("filename","char[8]",0,8,SX_NONE),
    SX_FIELD("file_type","char[1]",8,1,SX_ID),
    SX_FIELD("start_or_parameter","uint16",9,2,SX_NONE),
    SX_FIELD("logical_size","uint16",11,2,SX_SIZE),
    SX_FIELD("reserved","uint8",13,1,SX_NONE),
    SX_FIELD("stored_sector_count","uint8",14,1,SX_COUNT_PROP),
    SX_FIELD("header_checksum","uint16",15,2,SX_CHECKSUM),
};
const sx_layout sxdn_hobeta_header = {0x60780006U,"hobeta_header",sxdn_hobeta_header_fields,SX_COUNT(sxdn_hobeta_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_hobeta_code_header_fields[] = {
    SX_FIELD("filename","char[8]",0,8,SX_NONE),
    SX_FIELD("file_type","char[1]",8,1,SX_ID),
    SX_FIELD("load_address","uint16",9,2,SX_ADDRESS),
    SX_FIELD("logical_size","uint16",11,2,SX_SIZE),
    SX_FIELD("reserved","uint8",13,1,SX_NONE),
    SX_FIELD("stored_sector_count","uint8",14,1,SX_COUNT_PROP),
    SX_FIELD("header_checksum","uint16",15,2,SX_CHECKSUM),
};
const sx_layout sxdn_hobeta_code_header = {0x60780007U,"hobeta_code_header",sxdn_hobeta_code_header_fields,SX_COUNT(sxdn_hobeta_code_header_fields),SX_LE};
static bool sxdn_hobeta(sx_context*c){uint8_t h[17];return sxdn_read(c,0,h,17)&&sxdn_put(c,h[8]=='C'?&sxdn_hobeta_code_header:&sxdn_hobeta_header,0,1);}
bool sx_zx_hobeta_build(sx_context*c)
{
 return sxdn_hobeta(c);
}
