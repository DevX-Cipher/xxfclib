/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Hxc Mfm data structures, moved out of the systemextra schema family. */
#include "../../xx_format_schema_systemextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxse_hxc_mfm_header_fields[] = {
    SX_FIELD("signature","char[7]",0,7,SX_SIGNATURE),
    SX_FIELD("cylinder_count","uint16",7,2,SX_COUNT_PROP),
    SX_FIELD("side_count","uint8",9,1,SX_COUNT_PROP),
    SX_FIELD("rpm","uint16",10,2,SX_NONE),
    SX_FIELD("bitrate_kbps","uint16",12,2,SX_NONE),
    SX_FIELD("interface_type","uint8",14,1,SX_ID),
    SX_FIELD("track_table_offset","uint32",15,4,SX_OFFSET),
};
const sx_layout sxse_hxc_mfm_header = {0x602f0054U,"hxc_mfm_header",sxse_hxc_mfm_header_fields,SX_COUNT(sxse_hxc_mfm_header_fields),SX_LE};
static const xx_data_struct_field_desc sxse_hxc_mfm_track_fields[] = {
    SX_FIELD("cylinder","uint16",0,2,SX_ID),
    SX_FIELD("side","uint8",2,1,SX_ID),
    SX_FIELD("data_size","uint32",3,4,SX_SIZE),
    SX_FIELD("data_offset","uint32",7,4,SX_OFFSET),
};
const sx_layout sxse_hxc_mfm_track = {0x602f0055U,"hxc_mfm_track",sxse_hxc_mfm_track_fields,SX_COUNT(sxse_hxc_mfm_track_fields),SX_LE};
#define SXSE_ADD(c,l,p,z) sxse_put(c,&sxse_##l,p,z,1)
#define SXSE_TABLE(c,l,p,z,n) sxse_put(c,&sxse_##l,p,z,n)
static bool sxse_mfm(sx_context*c){uint8_t b[19];if(!sxse_read(c,0,b,19)||xx_rt_memcmp(b,"HXCMFM\0",7)||!SXSE_ADD(c,hxc_mfm_header,0,19))return false;uint64_t n=(uint64_t)sxse_u16(b,7,false)*b[9],p=sxse_u32(b,15,false);return n<=340&&p>=19&&SXSE_TABLE(c,hxc_mfm_track,p,11,n);}
bool sx_hxc_mfm_build(sx_context*c)
{
 return sxse_mfm(c);
}
#undef SXSE_ADD
#undef SXSE_TABLE
