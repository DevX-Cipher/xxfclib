/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Delrina PerFORM / FormFlow documents data structures, moved out of the docmeta schema family. */
#include "../../xx_format_schema_docmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdm_perform_header_fields[]={
 SX_FIELD("signature","char[34]",0,34,SX_SIGNATURE),
 SX_FIELD("plaintext_crc16","uint16",34,2,SX_CHECKSUM),
};
const sx_layout sxdm_perform_header={UINT32_C(0x6023000D),"perform_header",sxdm_perform_header_fields,SX_COUNT(sxdm_perform_header_fields),SX_LE};
bool sx_perform_build(sx_context*c)
{
 return sxdm_add(c,&sxdm_perform_header,0,36);
}
