/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * OGG data structures, moved out of the container schema family. */
#include "../../xx_format_schema_container.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_c_ogg_lacing_value_fields[] = {
    SX_FIELD("segment_size", "uint8", 0, 1, SX_SIZE),
};
const sx_layout sx_c_ogg_lacing_value = { UINT32_C(0x6002001D), "ogg_lacing_value", sx_c_ogg_lacing_value_fields, SX_COUNT(sx_c_ogg_lacing_value_fields), SX_LE };
static bool sx_c_ogg(sx_context *c)
{
    int64_t at=0;
    while (at<c->size) {
        uint8_t h[27], lacing[255]; uint32_t n=0;
        if (!sx_read(c,at,h,27) || xx_rt_memcmp(h,"OggS",4) || h[4] || (h[5]&~7U) || !sx_read(c,at+27,lacing,h[26])) return false;
        for (unsigned i=0;i<h[26];++i) n+=lacing[i];
        if (!sx_c_bounds(c,at+27+h[26],n) || !sx_add(c,&sx_c_ogg_page_header,at,27) ||
            !sx_table(c,&sx_c_ogg_lacing_value,at+27,1,h[26]) || !sx_raw(c,at+27+h[26],n)) return false;
        at+=27+h[26]+n;
    }
    return at>0;
}
bool sx_ogg_build(sx_context*c)
{
    return sx_c_ogg(c);
}
