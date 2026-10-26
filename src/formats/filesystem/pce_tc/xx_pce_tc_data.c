/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * PCE TransCopy TC bitstream disk image data structures, moved out of the diskimages schema family. */
#include "../../xx_format_schema_diskimages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdi_transcopy_header_fields[] = {
    SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("comment1","char[32]",2,32,SX_STRING),
    SX_FIELD("comment2","char[32]",34,32,SX_STRING),
};
const sx_layout sxdi_transcopy_header = {UINT32_C(0x60150002),"transcopy_header",sxdi_transcopy_header_fields,SX_COUNT(sxdi_transcopy_header_fields),SX_BE};
static const xx_data_struct_field_desc sxdi_transcopy_geometry_fields[] = {
    SX_FIELD("last_cylinder","uint8",0,1,SX_ID),
    SX_FIELD("head_count","uint8",1,1,SX_COUNT_PROP),
};
const sx_layout sxdi_transcopy_geometry = {UINT32_C(0x60150003),"transcopy_geometry",sxdi_transcopy_geometry_fields,SX_COUNT(sxdi_transcopy_geometry_fields),SX_LE};
static const xx_data_struct_field_desc sxdi_transcopy_track_offset_fields[] = {
    SX_FIELD("offset_in_256_byte_units","uint16",0,2,SX_NONE),
};
const sx_layout sxdi_transcopy_track_offset = {UINT32_C(0x60150004),"transcopy_track_offset",sxdi_transcopy_track_offset_fields,SX_COUNT(sxdi_transcopy_track_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxdi_transcopy_track_length_fields[] = {
    SX_FIELD("byte_length","uint16",0,2,SX_SIZE),
};
const sx_layout sxdi_transcopy_track_length = {UINT32_C(0x60150005),"transcopy_track_length",sxdi_transcopy_track_length_fields,SX_COUNT(sxdi_transcopy_track_length_fields),SX_LE};
static bool sxdi_tc(sx_context *c)
{
    uint8_t h[4];if(c->size<16384||!sxdi_read(c,0,h,2)||h[0]!=0x5a||h[1]!=0xa5||!sxdi_read(c,258,h,2)||h[0]>=99||!h[1]||h[1]>2)return false;
    return sx_add(c,&sxdi_transcopy_header,0,66)&&sx_add(c,&sxdi_transcopy_geometry,258,2)&&sx_table(c,&sxdi_transcopy_track_offset,0x305,2,256)&&sx_table(c,&sxdi_transcopy_track_length,0x505,2,256);
}
bool sx_pce_tc_build(sx_context*c)
{
    return sxdi_tc(c);
}
