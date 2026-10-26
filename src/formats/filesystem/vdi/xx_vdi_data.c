/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * vdi data structures, moved out of the diskmeta schema family. */
#include "../../xx_format_schema_diskmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"

static const xx_data_struct_field_desc sx_dm_vdi_preheader_fields[] = {
    SX_FIELD("text","char[64]",0,64,SX_NONE),
    SX_FIELD("signature","uint32",64,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",68,4,SX_NONE),
};
const sx_layout sx_dm_vdi_preheader = {0x60290018U,"vdi_preheader",sx_dm_vdi_preheader_fields,SX_COUNT(sx_dm_vdi_preheader_fields),SX_LE};
static bool sx_dm_vdi(sx_context*c){uint8_t h[456];if(!sx_dm_read(c,0,h,sizeof(h))||sx_dm_u32(h,64,false)!=0xbeda107f)return false;if(!sx_dm_add(c,&sx_dm_vdi_preheader,0,72)||!sx_dm_add(c,&sx_dm_vdi_header_v1,72,384))return false;uint64_t p=sx_dm_u32(h,340,false),n=sx_dm_u32(h,384,false);return !sx_dm_span(c,p,n*4)||sx_dm_table(c,&sx_dm_vdi_block_map_entry,p,4,n);}
bool sx_vdi_build(sx_context*c)
{
 return sx_dm_vdi(c);
}
