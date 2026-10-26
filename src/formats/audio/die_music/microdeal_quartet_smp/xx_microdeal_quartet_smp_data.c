/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Microdeal Quartet Smp data structures, moved out of the musiclate schema family. */
#include "../../../xx_format_schema_musiclate.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static bool sxlate_quartet(sx_context*c)
{
    uint64_t end=(uint64_t)c->size,p=16;unsigned channels=0;uint16_t cmd;
    if(!sxlate_row(c,&sxlate_quartet_header,0,16,end))return false;
    while(end-p>=12&&channels<4&&c->count<30000){
        if(!sx_u16(c,(int64_t)p,true,&cmd))return false;
        if(cmd!='F'&&cmd!='P'&&cmd!='S'&&cmd!='R'&&cmd!='L'&&cmd!='V'&&cmd!='l')return true;
        if(!sxlate_row(c,&sxlate_quartet_sequence,p,12,end))return false;p+=12;
        if(cmd=='F')++channels;
    }
    return true;
}
bool sx_microdeal_quartet_smp_build(sx_context*c)
{
    return sxlate_quartet(c);
}
