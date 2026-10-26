/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Simh Disk data structures, moved out of the disknext schema family. */
#include "../../xx_format_schema_disknext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"
#if SX_ALIAS_READER_FACTORY
#include "xxfclib/formats/filesystem/psa_disk/xx_psa_disk.h"
#endif

static const xx_data_struct_field_desc sxdn_simh_cpm_directory_fields[] = {
    SX_FIELD("user_or_status","uint8",0,1,SX_NONE),
    SX_FIELD("filename_and_flags","byte[8]",1,8,SX_NONE),
    SX_FIELD("extension_and_flags","byte[3]",9,3,SX_FLAGS),
    SX_FIELD("extent_low","uint8",12,1,SX_NONE),
    SX_FIELD("reserved","uint8",13,1,SX_NONE),
    SX_FIELD("extent_high","uint8",14,1,SX_NONE),
    SX_FIELD("record_count","uint8",15,1,SX_COUNT_PROP),
    SX_FIELD("allocation_blocks","uint16[8]",16,16,SX_NONE),
};
const sx_layout sxdn_simh_cpm_directory = {0x6078002cU,"simh_cpm_directory",sxdn_simh_cpm_directory_fields,SX_COUNT(sxdn_simh_cpm_directory_fields),SX_LE};
#define SXDN_TABLE(c,l,p,n) sxdn_put(c,&sxdn_##l,p,n)
static bool sxdn_simh(sx_context*c){for(unsigned sector=192;sector<256;sector++)if(!SXDN_TABLE(c,simh_cpm_directory,(uint64_t)sector*137+3,4))return false;return true;}
bool sx_simh_disk_build(sx_context*c)
{
 return sxdn_simh(c);
}
#undef SXDN_TABLE
