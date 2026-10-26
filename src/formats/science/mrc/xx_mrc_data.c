/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * MRC electron-density maps data structures, moved out of the sciencemeta schema family. */
#include "../../xx_format_schema_sciencemeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsc_mrc_label_fields[] = {
    SX_FIELD("label","char[80]",0,80,SX_STRING),
};
const sx_layout sxsc_mrc_label = {UINT32_C(0x60280003),"mrc_label",sxsc_mrc_label_fields,SX_COUNT(sxsc_mrc_label_fields),SX_LE};
static bool sxsc_mrc(sx_context *c)
{
 uint8_t b[224];if(!sx_read(c,0,b,sizeof(b))||xx_rt_memcmp(b+208,"MAP ",4))return false;
 bool be=b[212]==0x11&&b[213]==0x11;if(!be&&!(b[212]==0x44&&(b[213]==0x44||b[213]==0x41)))return false;
 return sxsc_add(c,be?&sxsc_mrc_header_be:&sxsc_mrc_header_le,0,224)&&sxsc_table(c,&sxsc_mrc_label,224,80,10);
}
bool sx_mrc_build(sx_context*c)
{
 return sxsc_mrc(c);
}
