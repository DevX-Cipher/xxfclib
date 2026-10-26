/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * inivation_aedat data structures, moved out of the scientificextra schema family. */
#include "../../xx_format_schema_scientificextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxscx_aedat2_event_fields[] = {
    SX_FIELD("event_address","int32",0,4,SX_FLAGS),
    SX_FIELD("timestamp","int32",4,4,SX_NONE),
};
const sx_layout sxscx_aedat2_event = {UINT32_C(0x60310001),"aedat2_event",sxscx_aedat2_event_fields,SX_COUNT(sxscx_aedat2_event_fields),SX_BE};
static bool sxscx_aedat(sx_context *c,const uint8_t *b,size_t n)
{
 uint64_t at=0;while(at<n&&b[at]=='#'){while(at<n&&b[at]!='\n')at++;if(at==n)return false;at++;}
 return at>=13&&at<n&&(n-at)%8==0&&sxscx_table(c,&sxscx_aedat2_event,at,(n-at)/8);
}
bool sx_inivation_aedat_build(sx_context *c,uint8_t *b)
{
 return sxscx_aedat(c,b,(size_t)c->size);
}
