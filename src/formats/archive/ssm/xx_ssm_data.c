/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SSM data structures, moved out of the archivepackages schema family. */
#include "../../xx_format_schema_archivepackages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxap_ssm_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("name","char[12]",4,12,SX_NONE),
 SX_FIELD("dos_date","uint16",16,2,SX_NONE),
 SX_FIELD("dos_time","uint16",18,2,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",20,4,SX_SIZE),
 SX_FIELD("window_size","uint32",24,4,SX_SIZE),
 SX_FIELD("unused","uint32",28,4,SX_NONE),
 SX_FIELD("method","uint32",32,4,SX_NONE),
};
const sx_layout sxap_ssm_header = {UINT32_C(0x6072000e),"ssm_header",sxap_ssm_header_fields,SX_COUNT(sxap_ssm_header_fields),SX_LE};
bool sx_ssm_build(sx_context*c)
{
 return sxap_add(c,&sxap_ssm_header,0);
}
