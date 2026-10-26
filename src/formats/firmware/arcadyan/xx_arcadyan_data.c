/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ARCADYAN data structures, moved out of the installerwire schema family. */
#include "../../xx_format_schema_installerwire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#if SX_ALIAS_READER_FACTORY
#include "xxfclib/formats/executable/binsh_starkit/xx_binsh_starkit.h"
#endif

static const xx_data_struct_field_desc sxiw_arcadyan_lzma_fragments_fields[]={
 SX_FIELD("encoded_dictionary_byte_0","uint8",0,1,SX_NONE),
 SX_FIELD("encoded_properties","uint8",1,1,SX_NONE),
 SX_FIELD("encoded_dictionary_byte_2","uint8",2,1,SX_NONE),
 SX_FIELD("encoded_dictionary_byte_1","uint8",3,1,SX_NONE),
 SX_FIELD("encoded_size_byte_0","uint8",4,1,SX_NONE),
 SX_FIELD("encoded_dictionary_byte_3","uint8",5,1,SX_NONE),
 SX_FIELD("encoded_size_byte_2","uint8",6,1,SX_NONE),
 SX_FIELD("encoded_size_byte_1","uint8",7,1,SX_NONE),
 SX_FIELD("encoded_size_byte_4","uint8",8,1,SX_NONE),
 SX_FIELD("encoded_size_byte_3","uint8",9,1,SX_NONE),
 SX_FIELD("encoded_size_byte_6","uint8",10,1,SX_NONE),
 SX_FIELD("encoded_size_byte_5","uint8",11,1,SX_NONE),
 SX_FIELD("encoded_range_coder_zero","uint8",12,1,SX_NONE),
 SX_FIELD("encoded_size_byte_7","uint8",13,1,SX_NONE),
};
const sx_layout sxiw_arcadyan_lzma_fragments={UINT32_C(0x60790054),"arcadyan_lzma_fragments",sxiw_arcadyan_lzma_fragments_fields,SX_COUNT(sxiw_arcadyan_lzma_fragments_fields),SX_LE};
bool sx_arcadyan_build(sx_context*c)
{
 return sxiw_add(c,&sxiw_arcadyan_lzma_fragments,0x68);
}
