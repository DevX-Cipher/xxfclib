/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * NetWare packed data structures, moved out of the archivesystems schema family. */
#include "../../xx_format_schema_archivesystems.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxasy_netwarepacked_header_fields[] = {
 SX_FIELD("signature","char[12]",0,12,SX_SIGNATURE),
 SX_FIELD("name","char[12]",12,12,SX_NONE),
 SX_FIELD("marker","uint8",24,1,SX_SIGNATURE),
 SX_FIELD("version","uint8",25,1,SX_NONE),
 SX_FIELD("method","uint8",26,1,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",27,4,SX_SIZE),
};
const sx_layout sxasy_netwarepacked_header = {UINT32_C(0x60440034),"netwarepacked_header",sxasy_netwarepacked_header_fields,SX_COUNT(sxasy_netwarepacked_header_fields),SX_LE};
bool sx_netwarepacked_build(sx_context*c)
{
 return sxasy_add(c,&sxasy_netwarepacked_header,0);
}
