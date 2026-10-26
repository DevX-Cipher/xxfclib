/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * XPAK data structures, moved out of the package schema family. */
#include "../../xx_format_schema_package.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_p_xpak_header_fields[] = {
    SX_FIELD("signature", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("archive_size", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("name", "char[13]", 8, 13, SX_STRING),
    SX_FIELD("original_size", "uint32", 21, 4, SX_SIZE),
};
const sx_layout sx_p_xpak_header = { UINT32_C(0x60070048), "xpak_header", sx_p_xpak_header_fields, SX_COUNT(sx_p_xpak_header_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_xpak_codec_fields[] = {
    SX_FIELD("hash_size_parameter", "uint8", 0, 1, SX_NONE),
    SX_FIELD("magic", "uint16", 1, 2, SX_SIGNATURE),
    SX_FIELD("window_size", "uint16", 3, 2, SX_SIZE),
    SX_FIELD("max_match", "uint16", 5, 2, SX_SIZE),
    SX_FIELD("model_rescale_limit", "uint16", 7, 2, SX_NONE),
};
const sx_layout sx_p_xpak_codec = { UINT32_C(0x60070049), "xpak_codec", sx_p_xpak_codec_fields, SX_COUNT(sx_p_xpak_codec_fields), SX_LE };
bool sx_xpak_build(sx_context*c)
{
    uint32_t n;return sx_p_sig(c,0,"XPAK",4)&&sx_u32(c,4,false,&n)&&n>=35&&n<=(uint64_t)c->size&&sx_p_sig(c,26,"\xff\xfe",2)&&sx_add(c,&sx_p_xpak_header,0,25)&&sx_add(c,&sx_p_xpak_codec,25,9);
}
