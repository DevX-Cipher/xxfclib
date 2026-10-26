/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * WESTWOOD_PAK data structures, moved out of the archivenext schema family. */
#include "../../xx_format_schema_archivenext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxan_westwood_offset_fields[] = {
 SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxan_westwood_offset = {UINT32_C(0x60770029),"westwood_offset",sxan_westwood_offset_fields,SX_COUNT(sxan_westwood_offset_fields),SX_LE};
static bool sxan_westwood(sx_context*c){uint64_t end,p=0,z,len;if(!sxan_word(c,0,4,false,&end)||!sxan_span(c,0,end))return false;while(p<end){if(end-p<4||!sxan_word(c,p,4,false,&z)||!sxan_add(c,&sxan_westwood_offset,p))return false;p+=4;if(!z)break;if(p==end)break;if(!sxan_zlen(c,p,end,&len)||!sxan_named(c,p,len))return false;p+=len;}return true;}
bool sx_westwood_pak_build(sx_context*c)
{
bool ok=false;
ok=sxan_westwood(c);
(void)ok;return c->count&&sxan_finish(c);
}
