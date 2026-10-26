/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SONY_VAG data structures, moved out of the storage schema family. */
#include "../../xx_format_schema_storage.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_st_vag_header_fields[] = {
    SX_FIELD("signature", "byte[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("version", "uint32", 4, 4, SX_NONE),
    SX_FIELD("reserved", "uint32", 8, 4, SX_RESERVED),
    SX_FIELD("data_size", "uint32", 12, 4, SX_SIZE),
    SX_FIELD("sample_rate", "uint32", 16, 4, SX_NONE),
    SX_FIELD("reserved2", "byte[12]", 20, 12, SX_RESERVED),
    SX_FIELD("name", "char[16]", 32, 16, SX_STRING),
};
const sx_layout sx_st_vag_header = {0x60080010U, "vag_header", sx_st_vag_header_fields, SX_COUNT(sx_st_vag_header_fields), SX_BE};
static const xx_data_struct_field_desc sx_st_vag_adpcm_frame_fields[] = {
    SX_FIELD("predictor_and_shift", "uint8", 0, 1, SX_NONE),
    SX_FIELD("flags", "uint8", 1, 1, SX_FLAGS),
    SX_FIELD("encoded_samples", "byte[14]", 2, 14, SX_NONE),
};
const sx_layout sx_st_vag_adpcm_frame = {0x60080011U, "vag_adpcm_frame", sx_st_vag_adpcm_frame_fields, SX_COUNT(sx_st_vag_adpcm_frame_fields), SX_LE};
bool sx_sony_vag_build(sx_context*c)
{
    bool ok=false;
    uint32_t n;ok=sx_add(c,&sx_st_vag_header,0,48)&&sx_u32(c,12,true,&n)&&sx_table(c,&sx_st_vag_adpcm_frame,48,16,n/16);
    return ok&&sx_st_finish(c);
}
