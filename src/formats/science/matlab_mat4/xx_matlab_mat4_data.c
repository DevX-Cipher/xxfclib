/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * matlab_mat4 data structures, moved out of the media schema family. */
#include "../../xx_format_schema_media.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static bool sxm_mat4(sx_context *c)
{
    uint64_t at=0;static const unsigned widths[]={8,4,4,2,2,1};
    while(at<(uint64_t)c->size){uint8_t h[20];uint32_t type,rows,cols,imag,names;bool be;uint64_t n;
        if(!sx_read(c,(int64_t)at,h,20))return false;type=xx_data_get_u32(h,20,0,false);be=type>1999;if(be)type=xx_data_get_u32(h,20,0,true);
        rows=xx_data_get_u32(h,20,4,be);cols=xx_data_get_u32(h,20,8,be);imag=xx_data_get_u32(h,20,12,be);names=xx_data_get_u32(h,20,16,be);
        if(type>1999||type/1000!=(be?1U:0U)||(type/100)%10||type%10>1||(type/10)%10>=6||imag>1||!rows||!cols||rows>1000000||cols>1000000||names<2||names>256)return false;
        n=(uint64_t)rows*cols;if(n>1000000)return false;n=n*widths[(type/10)%10]*(1+imag);
        if(!sx_add(c,be?&sxm_mat4_header_be:&sxm_mat4_header_le,(int64_t)at,20)||!sxm_raw(c,at+20,names)||!sxm_raw(c,at+20+names,n))return false;at+=20+names+n;
    }
    return at!=0;
}
bool sx_matlab_mat4_build(sx_context*c)
{
 return sxm_mat4(c);
}
