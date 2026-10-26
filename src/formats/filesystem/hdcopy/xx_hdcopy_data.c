/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * HDCOPY data structures, moved out of the systemlater schema family. */
#include "../../xx_format_schema_systemlater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsl_hdcopy_header_fields[] = {
    SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("label_size","uint8",2,1,SX_SIZE),
    SX_FIELD("label","char[11]",3,11,SX_NONE),
    SX_FIELD("last_cylinder","uint8",14,1,SX_NONE),
    SX_FIELD("sectors_per_track","uint8",15,1,SX_COUNT_PROP),
    SX_FIELD("track_usage_map","uint8[168]",16,168,SX_FLAGS),
};
const sx_layout sxsl_hdcopy_header = {0x6033000dU,"hdcopy_header",sxsl_hdcopy_header_fields,SX_COUNT(sxsl_hdcopy_header_fields),SX_LE};
static const xx_data_struct_field_desc sxsl_hdcopy_block_fields[] = {
    SX_FIELD("block_size","uint16",0,2,SX_SIZE),
    SX_FIELD("escape","uint8",2,1,SX_ID),
};
const sx_layout sxsl_hdcopy_block = {0x6033000eU,"hdcopy_block",sxsl_hdcopy_block_fields,SX_COUNT(sxsl_hdcopy_block_fields),SX_LE};
#define SXSL_LIMIT 24000U
#define SXSL_ADD(c,l,p) sxsl_put(c,&sxsl_##l,p,1)
static bool sxsl_hdcopy(sx_context*c){uint8_t b[184];if(!sxsl_read(c,0,b,184)||!SXSL_ADD(c,hdcopy_header,0))return false;uint64_t p=184;unsigned n=((unsigned)b[14]+1)*2;if(n>168)return true;for(unsigned i=0;i<n&&c->count<SXSL_LIMIT;i++)if(b[16+i]){uint64_t z;if(!sxsl_word(c,p,2,false,&z)||z<1||!sxsl_span(c,p+2,z)||!SXSL_ADD(c,hdcopy_block,p))break;p+=2+z;}return true;}
bool sx_hdcopy_build(sx_context*c)
{
bool ok=false;
ok=sxsl_hdcopy(c);
return ok&&sxsl_finish(c);
}
