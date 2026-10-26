/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * BAGF data structures, moved out of the archivefinal schema family. */
#include "../../xx_format_schema_archivefinal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxaf_bagf_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_NONE),
 SX_FIELD("positive_word","int32",8,4,SX_NONE),
 SX_FIELD("opaque_words","uint8[20]",12,20,SX_NONE),
 SX_FIELD("class_word0","uint32",32,4,SX_NONE),
 SX_FIELD("class_word1","uint32",36,4,SX_NONE),
 SX_FIELD("payload_size","uint32",40,4,SX_SIZE),
 SX_FIELD("name_size","uint8",44,1,SX_SIZE),
 SX_FIELD("name","char[15]",45,15,SX_NONE),
 SX_FIELD("description_size","uint8",60,1,SX_SIZE),
 SX_FIELD("description","char[51]",61,51,SX_NONE),
};
const sx_layout sxaf_bagf_header = {UINT32_C(0x603c0016),"bagf_header",sxaf_bagf_header_fields,SX_COUNT(sxaf_bagf_header_fields),SX_LE};
bool sx_bagf_build(sx_context*c)
{
 return sxaf_add(c,&sxaf_bagf_header,0);
}
