/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Msxperformer Opx data structures, moved out of the musiclate schema family. */
#include "../../../xx_format_schema_musiclate.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static bool sxlate_opx_at(sx_context*c,uint64_t p)
{
    uint64_t end=(uint64_t)c->size;uint8_t h[159];
    if(!sxlate_read(c,p,h,sizeof(h),end))return false;
    bool marked=!xx_rt_memcmp(h+122," \r\n\032",4)&&!xx_rt_memcmp(h+53,"\r\n",2)&&!xx_rt_memcmp(h+108,"\r\n",2);
    if(!marked&&xx_rt_memcmp(h+122,"    ",4))return false;
    if(h[134]>1)return false;
    for(unsigned i=0;i<12;i++)if(xx_data_get_u16(h,sizeof(h),135+i*2,false)>=0x4000)return false;
    return sxlate_row(c,&sxlate_opx_text_header,p,128,end)&&sxlate_row(c,&sxlate_opx_info,p+128,31,end);
}
bool sx_msxperformer_opx_build(sx_context*c)
{
    return sxlate_opx_at(c,0)||sxlate_opx_at(c,0xC00);
}
