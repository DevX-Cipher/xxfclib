/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * OPC data structures, moved out of the installerwire schema family. */
#include "../../xx_format_schema_installerwire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#if SX_ALIAS_READER_FACTORY
#include "xxfclib/formats/executable/binsh_starkit/xx_binsh_starkit.h"
#endif

static const xx_data_struct_field_desc sxiw_opc_banner_fields[]={
 SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("version_and_part_description","char[71]",8,71,SX_STRING),
 SX_FIELD("terminator","uint8",79,1,SX_SIGNATURE),
};
const sx_layout sxiw_opc_banner={UINT32_C(0x60790021),"opc_banner",sxiw_opc_banner_fields,SX_COUNT(sxiw_opc_banner_fields),SX_LE};
bool sx_opc_build(sx_context*c)
{
 return sxiw_add(c,&sxiw_opc_banner,0);
}
