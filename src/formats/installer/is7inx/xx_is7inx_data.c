/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * IS7INX data structures, moved out of the installerwire schema family. */
#include "../../xx_format_schema_installerwire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#if SX_ALIAS_READER_FACTORY
#include "xxfclib/formats/executable/binsh_starkit/xx_binsh_starkit.h"
#endif

static const xx_data_struct_field_desc sxiw_is7inx_header_fields[]={
 SX_FIELD("signature","uint32le",0,4,SX_SIGNATURE),
 SX_FIELD("encoded_reserved","uint8[2]",4,2,SX_NONE),
 SX_FIELD("encoded_copyright","uint8[73]",6,73,SX_NONE),
 SX_FIELD("encoded_padding","uint8[25]",79,25,SX_NONE),
 SX_FIELD("encoded_header_size","uint8[4]",104,4,SX_NONE),
 SX_FIELD("encoded_section_offset_0","uint8[4]",108,4,SX_NONE),
 SX_FIELD("encoded_section_offset_1","uint8[4]",112,4,SX_NONE),
 SX_FIELD("encoded_section_offset_2","uint8[4]",116,4,SX_NONE),
 SX_FIELD("encoded_section_offset_3","uint8[4]",120,4,SX_NONE),
};
const sx_layout sxiw_is7inx_header={UINT32_C(0x60790001),"is7inx_header",sxiw_is7inx_header_fields,SX_COUNT(sxiw_is7inx_header_fields),SX_LE};
bool sx_is7inx_build(sx_context*c)
{
 return sxiw_add(c,&sxiw_is7inx_header,0);
}
