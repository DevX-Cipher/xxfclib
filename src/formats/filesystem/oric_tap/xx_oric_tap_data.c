/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Oric Tap data structures, moved out of the systemextra schema family. */
#include "../../xx_format_schema_systemextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxse_oric_tap_header_fields[] = {
    SX_FIELD("sync_marker","uint8",0,1,SX_SIGNATURE),
    SX_FIELD("reserved1","byte[2]",1,2,SX_RESERVED),
    SX_FIELD("file_type","uint8",3,1,SX_ID),
    SX_FIELD("autostart","uint8",4,1,SX_ID),
    SX_FIELD("end_address","uint16",5,2,SX_ADDRESS),
    SX_FIELD("start_address","uint16",7,2,SX_ADDRESS),
    SX_FIELD("reserved2","uint8",9,1,SX_RESERVED),
};
const sx_layout sxse_oric_tap_header = {0x602f0044U,"oric_tap_header",sxse_oric_tap_header_fields,SX_COUNT(sxse_oric_tap_header_fields),SX_BE};
#define SXSE_ADD(c,l,p,z) sxse_put(c,&sxse_##l,p,z,1)
static bool sxse_oric(sx_context*c){uint8_t b[10];uint64_t p=0;for(unsigned k=0;p<(uint64_t)c->size&&k<4096;k++){unsigned sync=0;while(sync<4096&&sxse_read(c,p,b,1)&&b[0]==0x16){sync++;p++;}if(sync<3||!sxse_read(c,p,b,10)||b[0]!=0x24||!SXSE_ADD(c,oric_tap_header,p,10))return false;unsigned end=sxse_u16(b,5,true),start=sxse_u16(b,7,true);if(start>end)return false;p+=10;unsigned name=0;for(;name<=255;name++){if(!sxse_read(c,p++,b,1))return false;if(!b[0])break;}if(name>255||!sxse_span(c,p,1+(uint64_t)end-start))return false;p+=1+(uint64_t)end-start;}return p==(uint64_t)c->size;}
bool sx_oric_tap_build(sx_context*c)
{
 return sxse_oric(c);
}
#undef SXSE_ADD
