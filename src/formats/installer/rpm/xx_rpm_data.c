/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * RPM package data structures, moved out of the package schema family. */
#include "../../xx_format_schema_package.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_p_rpm_lead_fields[] = {
    SX_FIELD("magic", "bytes", 0, 4, SX_SIGNATURE),
    SX_FIELD("major", "uint8", 4, 1, SX_NONE),
    SX_FIELD("minor", "uint8", 5, 1, SX_NONE),
    SX_FIELD("package_type", "uint16", 6, 2, SX_ID),
    SX_FIELD("architecture", "uint16", 8, 2, SX_ID),
    SX_FIELD("name", "char[66]", 10, 66, SX_STRING),
    SX_FIELD("operating_system", "uint16", 76, 2, SX_ID),
    SX_FIELD("signature_type", "uint16", 78, 2, SX_ID),
    SX_FIELD("reserved", "bytes", 80, 16, SX_RESERVED),
};
const sx_layout sx_p_rpm_lead = { UINT32_C(0x60070029), "rpm_lead", sx_p_rpm_lead_fields, SX_COUNT(sx_p_rpm_lead_fields), SX_BE };
static const xx_data_struct_field_desc sx_p_rpm_header_fields[] = {
    SX_FIELD("magic", "bytes", 0, 3, SX_SIGNATURE),
    SX_FIELD("version", "uint8", 3, 1, SX_NONE),
    SX_FIELD("reserved", "uint32", 4, 4, SX_RESERVED),
    SX_FIELD("index_count", "uint32", 8, 4, SX_COUNT_PROP),
    SX_FIELD("data_size", "uint32", 12, 4, SX_SIZE),
};
const sx_layout sx_p_rpm_header = { UINT32_C(0x6007002A), "rpm_header", sx_p_rpm_header_fields, SX_COUNT(sx_p_rpm_header_fields), SX_BE };
static bool sx_p_rpm_header_at(sx_context *c,int64_t *off)
{
    uint32_t count,size;if(!sx_p_sig(c,*off,"\x8e\xad\xe8\1",4)||!sx_u32(c,*off+8,true,&count)||!count||count>65535||!sx_u32(c,*off+12,true,&size)||!sx_add(c,&sx_p_rpm_header,*off,16))return false;*off+=16;
    if(!sx_table(c,&sx_p_rpm_index,*off,16,count))return false;int64_t store=*off+(int64_t)count*16;if(!sx_p_span(c,store,size))return false;
    for(uint32_t i=0;i<count;i++){uint32_t type,at,n;if(!sx_u32(c,*off+16*i+4,true,&type)||type>9||!sx_u32(c,*off+16*i+8,true,&at)||!sx_u32(c,*off+16*i+12,true,&n)||at>size)return false;unsigned unit=type==3?2:type==4?4:type==5?8:1;if(type!=0&&type!=6&&type!=8&&type!=9&&(uint64_t)n*unit>size-at)return false;}
    *off=store+size;return true;
}
static bool sx_p_rpm(sx_context *c)
{
    uint16_t sig;if(!sx_p_sig(c,0,"\xed\xab\xee\xdb",4)||!sx_u16(c,78,true,&sig)||!sx_add(c,&sx_p_rpm_lead,0,96))return false;int64_t off=96;
    if(sig==5){if(!sx_p_rpm_header_at(c,&off))return false;off=(off+7)&~INT64_C(7);}else if(sig==1)off+=256;else if(sig)return false;
    return sx_p_rpm_header_at(c,&off);
}
bool sx_rpm_build(sx_context*c)
{
    return sx_p_rpm(c);
}
