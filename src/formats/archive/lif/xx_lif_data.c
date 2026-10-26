/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * LIF data structures, moved out of the archivefinal schema family. */
#include "../../xx_format_schema_archivefinal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxaf_lif_header_fields[] = {
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("version","uint16",2,2,SX_NONE),
 SX_FIELD("positive_word","uint16",4,2,SX_NONE),
 SX_FIELD("name","char[15]",6,15,SX_NONE),
 SX_FIELD("file_size","uint32",21,4,SX_SIZE),
 SX_FIELD("method","uint32",25,4,SX_NONE),
 SX_FIELD("compressed_size","uint32",29,4,SX_SIZE),
 SX_FIELD("reserved","uint32",33,4,SX_NONE),
 SX_FIELD("dos_date","uint16",37,2,SX_NONE),
 SX_FIELD("dos_time","uint16",39,2,SX_NONE),
};
const sx_layout sxaf_lif_header = {UINT32_C(0x603c0029),"lif_header",sxaf_lif_header_fields,SX_COUNT(sxaf_lif_header_fields),SX_LE};
bool sx_lif_build(sx_context*c)
{
 return sxaf_add(c,&sxaf_lif_header,0);
}
