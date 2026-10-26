/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * DTPACKED data structures, moved out of the archiveclassic schema family. */
#include "../../xx_format_schema_archiveclassic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxacl_dtpacked_header_fields[] = {
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("version","uint16",2,2,SX_NONE),
 SX_FIELD("flags","uint16",4,2,SX_NONE),
 SX_FIELD("uninitialized1","uint8[23]",6,23,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",29,4,SX_SIZE),
 SX_FIELD("uninitialized2","uint8[4]",33,4,SX_NONE),
 SX_FIELD("dos_date","uint16",37,2,SX_NONE),
 SX_FIELD("dos_time","uint16",39,2,SX_NONE),
};
const sx_layout sxacl_dtpacked_header = {UINT32_C(0x60500001),"dtpacked_header",sxacl_dtpacked_header_fields,SX_COUNT(sxacl_dtpacked_header_fields),SX_LE};
bool sx_dtpacked_build(sx_context*c)
{
 return sxacl_add(c,&sxacl_dtpacked_header,0)&&sxacl_dcl(c,41,(uint64_t)c->size-41);
}
