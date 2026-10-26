/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * godot ctex data structures, moved out of the rastermore schema family. */
#include "../../xx_format_schema_rastermore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxrm_godot_ctex_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",4,4,SX_ID),
    SX_FIELD("original_width","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("original_height","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("flags","uint32",16,4,SX_FLAGS),
    SX_FIELD("mipmap_limit","int32",20,4,SX_NONE),
    SX_FIELD("reserved","uint32[3]",24,12,SX_RESERVED),
    SX_FIELD("data_format","uint32",36,4,SX_ID),
    SX_FIELD("width","uint16",40,2,SX_COUNT_PROP),
    SX_FIELD("height","uint16",42,2,SX_COUNT_PROP),
    SX_FIELD("mipmap_count","uint32",44,4,SX_COUNT_PROP),
    SX_FIELD("image_format","uint32",48,4,SX_ID),
};
const sx_layout sxrm_godot_ctex_header = {UINT32_C(0x601d0058),"godot_ctex_header",sxrm_godot_ctex_header_fields,SX_COUNT(sxrm_godot_ctex_header_fields),SX_LE};
bool sx_godot_ctex_build(sx_context*c)
{
 return sxrm_add(c,&sxrm_godot_ctex_header,0);
}
