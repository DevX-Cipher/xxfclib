/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * pc magazine flp data structures, moved out of the systemtail schema family. */
#include "../../xx_format_schema_systemtail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxst_pcmag_flp_header_fields[] = {
    SX_FIELD("signature","char[3]",0,3,SX_SIGNATURE),
    SX_FIELD("reserved","uint16",3,2,SX_RESERVED),
    SX_FIELD("heads","uint16",5,2,SX_COUNT_PROP),
    SX_FIELD("tracks_per_side","uint16",7,2,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint16",9,2,SX_COUNT_PROP),
    SX_FIELD("bytes_per_sector","uint16",11,2,SX_SIZE),
};
const sx_layout sxst_pcmag_flp_header = {0x60370016U,"pcmag_flp_header",sxst_pcmag_flp_header_fields,SX_COUNT(sxst_pcmag_flp_header_fields),SX_LE};
#define SXST_ADD(c,l,p) sxst_put(c,&sxst_##l,p,1)
bool sx_pc_magazine_flp_build(sx_context*c)
{
 return SXST_ADD(c,pcmag_flp_header,0);
}
#undef SXST_ADD
