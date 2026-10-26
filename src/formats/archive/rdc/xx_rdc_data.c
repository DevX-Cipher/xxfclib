/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * RDC compressed stream data structures, moved out of the archivepackages schema family. */
#include "../../xx_format_schema_archivepackages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxap_rdc_block_fields[] = {
 SX_FIELD("size_or_stored_length","int16",0,2,SX_NONE),
};
const sx_layout sxap_rdc_block = {UINT32_C(0x6072002e),"rdc_block",sxap_rdc_block_fields,SX_COUNT(sxap_rdc_block_fields),SX_LE};
static bool sxap_rdc(sx_context*c){uint64_t p=0;while(sxap_span(c,p,2)){uint64_t word;if(!sxap_word(c,p,2,false,&word)||!sxap_add(c,&sxap_rdc_block,p))return false;p+=2;if(!word)break;uint64_t n=(word&0x8000)?0x10000-word:word;if(!sxap_span(c,p,n))return true;p+=n;}return true;}
bool sx_rdc_build(sx_context*c)
{
 return sxap_rdc(c);
}
