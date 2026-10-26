/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ECMPACKED data structures, moved out of the archivestreams schema family. */
#include "../../xx_format_schema_archivestreams.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxas_ecmpacked_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_NONE),
 SX_FIELD("opaque_word0","uint32",6,4,SX_NONE),
 SX_FIELD("opaque_word1","uint16",10,2,SX_NONE),
 SX_FIELD("opaque_word2","uint32",12,4,SX_NONE),
 SX_FIELD("reserved","uint8[20]",16,20,SX_NONE),
 SX_FIELD("opaque_word3","uint16",36,2,SX_NONE),
};
const sx_layout sxas_ecmpacked_header = {UINT32_C(0x6043001c),"ecmpacked_header",sxas_ecmpacked_header_fields,SX_COUNT(sxas_ecmpacked_header_fields),SX_LE};
bool sx_ecmpacked_build(sx_context*c)
{
 return sxas_add(c,&sxas_ecmpacked_header,0);
}
