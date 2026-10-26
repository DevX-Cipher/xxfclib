/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * tps data structures, moved out of the databases schema family. */
#include "../../xx_format_schema_databases.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxd_tps_header_fields[] = {
    SX_FIELD("magic", "char[4]", 0, 4, SX_SIGNATURE),
};
const sx_layout sxd_tps_header = {UINT32_C(0x601A0038),"tps_header",sxd_tps_header_fields,SX_COUNT(sxd_tps_header_fields),SX_LE};
static const xx_data_struct_field_desc sxd_tps_terminator_fields[] = {
    SX_FIELD("end_tag", "uint8", 0, 1, SX_ID),
};
const sx_layout sxd_tps_terminator = {UINT32_C(0x601A003A),"tps_terminator",sxd_tps_terminator_fields,SX_COUNT(sxd_tps_terminator_fields),SX_LE};
static bool sxd_tps(sx_context *c,const uint8_t *b)
{
    uint64_t at=4;if(!sxd_add(c,&sxd_tps_header,0,4))return false;
    while(at<(uint64_t)c->size){if((uint64_t)c->size-at==1){if(b[at]==4&&!sxd_add(c,&sxd_tps_terminator,at,1))return false;break;}if(!sxd_can(c,at,22)||b[at]!=2)break;
        int64_t coded=(int32_t)sxd_u32(b+at+14);if(coded<0)coded=-coded;coded-=4;if(coded<0||coded>0x10000000)return false;uint64_t stored=(uint64_t)coded+((uint64_t)coded+4+16383)/16384+1;
        if(!sxd_can(c,at+22,stored)||!sxd_add(c,&sxd_tps_entry,at,22))return false;at+=22+stored;
    }return true;
}
bool sx_tps_build(sx_context *c,uint8_t *b)
{
 return sxd_tps(c,b);
}
