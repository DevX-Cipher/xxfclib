/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Stylus dictionary containers data structures, moved out of the docmeta schema family. */
#include "../../xx_format_schema_docmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdm_stylus_header_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_ID),
 SX_FIELD("stream_kind","uint8",6,1,SX_ID),
 SX_FIELD("payload_tag","char[3]",7,3,SX_ID),
 SX_FIELD("unknown","bytes",10,2,SX_NONE),
 SX_FIELD("plaintext_crc32","uint32",12,4,SX_CHECKSUM),
};
const sx_layout sxdm_stylus_header={UINT32_C(0x6023000C),"stylus_header",sxdm_stylus_header_fields,SX_COUNT(sxdm_stylus_header_fields),SX_LE};
bool sx_stylus_build(sx_context*c)
{
 return sxdm_add(c,&sxdm_stylus_header,0,16);
}
