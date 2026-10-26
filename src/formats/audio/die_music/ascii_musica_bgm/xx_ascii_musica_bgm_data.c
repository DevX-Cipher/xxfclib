/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ASCII MuSICA chiptune (.BGM,.BGR) data structures, moved out of the musicportable schema family. */
#include "../../../xx_format_schema_musicportable.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxportable_bgm_bsave_header_fields[]={
 SX_FIELD("marker","uint8",0,1,SX_SIGNATURE),
 SX_FIELD("load_address","uint16",1,2,SX_ADDRESS),
 SX_FIELD("last_address","uint16",3,2,SX_ADDRESS),
 SX_FIELD("entry_address","uint16",5,2,SX_ADDRESS),
};
const sx_layout sxportable_bgm_bsave_header={0x6091001cU,"bgm_bsave_header",sxportable_bgm_bsave_header_fields,SX_COUNT(sxportable_bgm_bsave_header_fields),SX_LE};
static bool sxportable_clear(sx_context*c,uint64_t p,uint64_t n)
{
    for(size_t i=0;i<c->count;i++){
        uint64_t at=(uint64_t)(c->items[i].offset-c->f->base_address),z=(uint64_t)c->items[i].total_size;
        if(p<at+z&&at<p+n)return false;
    }
    return true;
}
static bool sxportable_bgm(sx_context*c)
{
    uint8_t h[15];uint64_t end=(uint64_t)c->size;
    if(!sxportable_read(c,0,h,7,end)||h[0]!=0xfe)return false;
    uint16_t base=xx_data_get_u16(h,7,1,false),last=xx_data_get_u16(h,7,3,false),entry=xx_data_get_u16(h,7,5,false);
    if(last<base||entry<base)return false;
    uint64_t declared=8U+(uint64_t)last-base,p=7U+(uint64_t)entry-base;
    if(declared>end||p<7||!sxportable_span(c,p,35,declared)||!sxportable_row(c,&sxportable_bgm_bsave_header,0,7,end)||!sxportable_row(c,&sxportable_bgm_channel_header,p,35,end))return false;
    if(sxportable_span(c,80,15,declared)&&sxportable_clear(c,80,15)&&sxportable_read(c,80,h,15,declared)&&!xx_rt_memcmp(h,"BTO",3)){
        if(!sxportable_row(c,&sxportable_bgm_bto_header,80,15,end))return false;
        uint16_t load=xx_data_get_u16(h,15,9,false);
        for(unsigned i=11;i<=13;i+=2){
            uint16_t address=xx_data_get_u16(h,15,i,false);if(address<load)continue;
            uint64_t at=7U+(uint64_t)address-load,q=at;uint8_t ch;
            while(q<declared&&q-at<256){if(!sxportable_byte(c,q++,&ch,declared))return false;if(ch<0x20)break;}
            if(q>at&&sxportable_clear(c,at,q-at)&&!sxportable_row(c,&sxportable_bgm_encoded_text,at,q-at,end))return false;
        }
    }
    return true;
}
bool sx_ascii_musica_bgm_build(sx_context*c)
{
    return sxportable_bgm(c);
}
