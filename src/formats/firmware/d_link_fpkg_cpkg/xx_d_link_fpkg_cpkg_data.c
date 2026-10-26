/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * d_link_fpkg_cpkg data structures, moved out of the firmwaremore schema family. */
#include "../../xx_format_schema_firmwaremore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_fm_dlink_fpkg_extra_fields[] = {
    SX_FIELD("unknown","uint32",0,4,SX_NONE),
    SX_FIELD("model_name_length","uint32",4,4,SX_SIZE),
};
const sx_layout sx_fm_dlink_fpkg_extra = {0x6022000fU,"dlink_fpkg_extra",sx_fm_dlink_fpkg_extra_fields,SX_COUNT(sx_fm_dlink_fpkg_extra_fields),SX_BE};
static bool sx_fm_dlink(sx_context *c)
{
    uint8_t magic[4];uint32_t off;if(!sx_fm_read(c,0,magic,4)||!sx_fm_u32(c,8,true,&off)||!sx_fm_add(c,&sx_fm_dlink_package_header,0,12))return false;
    if(!xx_rt_memcmp(magic,"FPKG",4)&&off>=20){uint32_t name;if(sx_fm_u32(c,16,true,&name)&&name&&name<=256&&name<=off-20&&!sx_fm_add(c,&sx_fm_dlink_fpkg_extra,12,8))return false;}
    uint64_t at=off;unsigned count=0;
    while(at+28<=(uint64_t)c->size&&count<65530){
        uint8_t h[28];if(!sx_fm_read(c,(int64_t)at,h,28))return false;
        uint32_t n=xx_data_get_u32(h,28,8,true);uint16_t t=xx_data_get_u16(h,28,4,true);
        if(xx_data_get_u32(h,28,0,true)!=28||t<0x100||t>0x103||!sx_fm_span(c,(int64_t)at+28,n))break;
        bool printable=true;for(unsigned i=12;i<28&&h[i];i++)if(h[i]<32||h[i]>126)printable=false;
        if(!printable)break;if(!sx_fm_add(c,&sx_fm_dlink_package_entry,(int64_t)at,28))return false;at+=28+(uint64_t)n;count++;
    }
    return !c->failed;
}
bool sx_d_link_fpkg_cpkg_build(sx_context*c)
{
    return sx_fm_dlink(c);
}
