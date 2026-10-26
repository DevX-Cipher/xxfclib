/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * IXA data structures, moved out of the archivefinal schema family. */
#include "../../xx_format_schema_archivefinal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxaf_ixa_header_fields[] = {
 SX_FIELD("signature","char[9]",0,9,SX_SIGNATURE),
 SX_FIELD("title","char[31]",9,31,SX_NONE),
 SX_FIELD("fixed_word","uint32",40,4,SX_NONE),
 SX_FIELD("version","uint32",44,4,SX_NONE),
 SX_FIELD("slot_count_plus_one","uint32",48,4,SX_NONE),
 SX_FIELD("table_end_offset","uint32",52,4,SX_OFFSET),
 SX_FIELD("auxiliary_block_size","uint32",56,4,SX_SIZE),
 SX_FIELD("unknown_word","uint32",60,4,SX_NONE),
};
const sx_layout sxaf_ixa_header = {UINT32_C(0x603c0017),"ixa_header",sxaf_ixa_header_fields,SX_COUNT(sxaf_ixa_header_fields),SX_LE};
static const xx_data_struct_field_desc sxaf_ixa_entry_fields[] = {
 SX_FIELD("payload_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("compressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
};
const sx_layout sxaf_ixa_entry = {UINT32_C(0x603c0018),"ixa_entry",sxaf_ixa_entry_fields,SX_COUNT(sxaf_ixa_entry_fields),SX_LE};
static bool sxaf_ixa(sx_context*c){uint64_t count,end;if(!sxaf_word(c,48,4,false,&count)||!count||!sxaf_word(c,52,4,false,&end)||end<64||count-1>(end-64)/12||!sxaf_span(c,0,end)||!sxaf_add(c,&sxaf_ixa_header,0))return false;for(uint64_t i=0;i<count-1;i++)if(!sxaf_add(c,&sxaf_ixa_entry,64+i*12))return false;return true;}
bool sx_ixa_build(sx_context*c)
{
 return sxaf_ixa(c);
}
