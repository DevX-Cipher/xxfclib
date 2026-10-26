/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * PEF data structures, moved out of the legacy schema family. */
#include "../../xx_format_schema_legacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static bool sxl_pef(sx_context *c)
{
    uint16_t count,inst;uint32_t arch,version;unsigned loaders=0;
    if(!sxl_sig(c,0,"Joy!peff",8)||!sx_u32(c,8,true,&arch)||(arch!=0x70777063&&arch!=0x6d36386b)||!sx_u32(c,12,true,&version)||version>1||!sx_u16(c,32,true,&count)||!count||count>4096||!sx_u16(c,34,true,&inst)||inst>count||!sx_add(c,&sxl_pef_header,0,40)||!sx_table(c,&sxl_pef_section,40,28,count))return false;
    for(uint16_t i=0;i<count;i++){int64_t at=40+(int64_t)i*28;uint32_t packed,off;uint8_t kind,align,reserved;if(!sx_u32(c,at+16,true,&packed)||!sx_u32(c,at+20,true,&off)||!sxl_byte(c,at+24,&kind)||kind>8||!sxl_byte(c,at+26,&align)||align>31||!sxl_byte(c,at+27,&reserved)||reserved||(packed&&(off<40+(uint64_t)count*28||!sxl_span(c,off,packed))))return false;
        if(kind==4){if(++loaders>1||packed<56||!sx_add(c,&sxl_pef_loader,off,56))return false;}
    }return loaders==1;
}
bool sx_pef_build(sx_context*c)
{
    return sxl_pef(c);
}
