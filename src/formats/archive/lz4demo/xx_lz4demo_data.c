/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * LZ4Demo data structures, moved out of the archivepackages schema family. */
#include "../../xx_format_schema_archivepackages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxap_legacy_lz4_magic_fields[] = {
 SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
};
const sx_layout sxap_legacy_lz4_magic = {UINT32_C(0x6072000b),"legacy_lz4_magic",sxap_legacy_lz4_magic_fields,SX_COUNT(sxap_legacy_lz4_magic_fields),SX_LE};
static const xx_data_struct_field_desc sxap_legacy_lz4_block_fields[] = {
 SX_FIELD("compressed_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxap_legacy_lz4_block = {UINT32_C(0x6072000c),"legacy_lz4_block",sxap_legacy_lz4_block_fields,SX_COUNT(sxap_legacy_lz4_block_fields),SX_LE};
static const xx_data_struct_field_desc sxap_legacy_lz4_skip_fields[] = {
 SX_FIELD("skip_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxap_legacy_lz4_skip = {UINT32_C(0x6072000d),"legacy_lz4_skip",sxap_legacy_lz4_skip_fields,SX_COUNT(sxap_legacy_lz4_skip_fields),SX_LE};
static bool sxap_lz4(sx_context*c){uint64_t p=0;while(sxap_span(c,p,4)){uint64_t n;if(!sxap_word(c,p,4,false,&n))return false;if(n==0x184c2102U||(n&0xfffffff0U)==0x184d2a50U){if(!sxap_add(c,&sxap_legacy_lz4_magic,p))return false;p+=4;if(n==0x184c2102U)continue;if(!sxap_word(c,p,4,false,&n)||!sxap_add(c,&sxap_legacy_lz4_skip,p))return false;}else if(!sxap_add(c,&sxap_legacy_lz4_block,p))return false;p+=4;if(!sxap_span(c,p,n))return true;p+=n;}return true;}
bool sx_lz4demo_build(sx_context*c)
{
 return sxap_lz4(c);
}
