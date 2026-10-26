/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Ain/GIGAMIX MGSDRV chiptune (.MGS) data structures, moved out of the musicportable schema family. */
#include "../../../xx_format_schema_musicportable.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxportable_mgs_identity_fields[]={
 SX_FIELD("magic","char[3]",0,3,SX_SIGNATURE),
 SX_FIELD("version","char[3]",3,3,SX_NONE),
 SX_FIELD("line_ending","uint8[2]",6,2,SX_NONE),
};
const sx_layout sxportable_mgs_identity={0x60910018U,"mgs_identity",sxportable_mgs_identity_fields,SX_COUNT(sxportable_mgs_identity_fields),SX_LE};
static const xx_data_struct_field_desc sxportable_mgs_identity_single_newline_fields[]={
 SX_FIELD("magic","char[3]",0,3,SX_SIGNATURE),
 SX_FIELD("version","char[3]",3,3,SX_NONE),
 SX_FIELD("line_ending","uint8",6,1,SX_NONE),
};
const sx_layout sxportable_mgs_identity_single_newline={0x60910019U,"mgs_identity_single_newline",sxportable_mgs_identity_single_newline_fields,SX_COUNT(sxportable_mgs_identity_single_newline_fields),SX_LE};
static const xx_data_struct_field_desc sxportable_mgs_text_end_fields[]={
 SX_FIELD("cr","uint8",0,1,SX_NONE),
 SX_FIELD("lf","uint8",1,1,SX_NONE),
 SX_FIELD("dos_text_eof","uint8",2,1,SX_NONE),
 SX_FIELD("nul","uint8",3,1,SX_NONE),
};
const sx_layout sxportable_mgs_text_end={0x6091001bU,"mgs_text_end",sxportable_mgs_text_end_fields,SX_COUNT(sxportable_mgs_text_end_fields),SX_LE};
static bool sxportable_mgs(sx_context*c)
{
    uint8_t h[8],tail[4];uint64_t end=(uint64_t)c->size;
    if(!sxportable_read(c,0,h,8,end)||xx_rt_memcmp(h,"MGS",3)||(h[6]!=13&&h[6]!=10))return false;
    uint64_t start=h[6]==13&&h[7]==10?8:7,limit=end<start+256?end:start+256;
    const sx_layout*identity=start==8?&sxportable_mgs_identity:&sxportable_mgs_identity_single_newline;
    for(uint64_t p=start;p+4<=limit;p++){
        if(!sxportable_read(c,p,tail,4,end))return false;
        if(!xx_rt_memcmp(tail,"\r\n\032\0",4)){
            return sxportable_row(c,identity,0,start,end)&&(p==start||sxportable_row(c,&sxportable_mgs_description,start,p-start,end))&&sxportable_row(c,&sxportable_mgs_text_end,p,4,end);
        }
    }
    return false;
}
bool sx_gigamix_mgsdrv_build(sx_context*c)
{
    return sxportable_mgs(c);
}
