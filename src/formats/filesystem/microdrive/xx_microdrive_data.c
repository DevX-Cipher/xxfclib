/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Apple MicroDrive partition map data structures, moved out of the disklegacy schema family. */
#include "../../xx_format_schema_disklegacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdleg_microdrive_header_fields[] = {
    SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("cylinder_count","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("reserved0","uint16",4,2,SX_RESERVED),
    SX_FIELD("heads_per_cylinder","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint16",8,2,SX_COUNT_PROP),
    SX_FIELD("reserved1","uint16",10,2,SX_RESERVED),
    SX_FIELD("first_partition_count","uint8",12,1,SX_COUNT_PROP),
    SX_FIELD("second_partition_count","uint8",13,1,SX_COUNT_PROP),
    SX_FIELD("reserved2","byte[10]",14,10,SX_RESERVED),
    SX_FIELD("iigs_rom_version","uint16",24,2,SX_ID),
    SX_FIELD("reserved3","byte[6]",26,6,SX_RESERVED),
};
const sx_layout sxdleg_microdrive_header = {0x60750046U,"microdrive_header",sxdleg_microdrive_header_fields,SX_COUNT(sxdleg_microdrive_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdleg_microdrive_start_fields[] = {
    SX_FIELD("start_lba","uint32",0,4,SX_NONE),
};
const sx_layout sxdleg_microdrive_start = {0x60750047U,"microdrive_start",sxdleg_microdrive_start_fields,SX_COUNT(sxdleg_microdrive_start_fields),SX_LE};
static const xx_data_struct_field_desc sxdleg_microdrive_size_fields[] = {
    SX_FIELD("block_count","uint24",0,3,SX_COUNT_PROP),
    SX_FIELD("drive_switch","uint8",3,1,SX_FLAGS),
};
const sx_layout sxdleg_microdrive_size = {0x60750048U,"microdrive_size",sxdleg_microdrive_size_fields,SX_COUNT(sxdleg_microdrive_size_fields),SX_LE};
#define SXDLEG_ADD(c,l,p) sxdleg_put(c,&sxdleg_##l,p,1)
#define SXDLEG_TABLE(c,l,p,n) sxdleg_put(c,&sxdleg_##l,p,n)
static bool sxdleg_micro(sx_context*c){uint8_t h[32];if(!sxdleg_read(c,0,h,32)||sxdleg16(h,0)!=0xccca||h[12]>8||h[13]>8||(!h[12]&&!h[13])||!SXDLEG_ADD(c,microdrive_header,0))return false;return SXDLEG_TABLE(c,microdrive_start,32,h[12])&&SXDLEG_TABLE(c,microdrive_size,64,h[12])&&SXDLEG_TABLE(c,microdrive_start,128,h[13])&&SXDLEG_TABLE(c,microdrive_size,160,h[13]);}
#undef SXDLEG_ADD
#undef SXDLEG_TABLE
bool sx_microdrive_build(sx_context*c)
{
 return sxdleg_micro(c);
}
