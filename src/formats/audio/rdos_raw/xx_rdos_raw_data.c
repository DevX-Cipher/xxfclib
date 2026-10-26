/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * RDOS RAW data structures, moved out of the adlib schema family. */
#include "../../xx_format_schema_adlib.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxad_adlib_raw_header_fields[] = {
    SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("timer_divisor","uint16_t",8,2,SX_NONE),
};
const sx_layout sxad_adlib_raw_header = {UINT32_C(0x600f004a),"adlib_raw_header",sxad_adlib_raw_header_fields,SX_COUNT(sxad_adlib_raw_header_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_raw_command_fields[] = {
    SX_FIELD("value","uint8_t",0,1,SX_NONE),
    SX_FIELD("register_or_command","uint8_t",1,1,SX_ID),
};
const sx_layout sxad_adlib_raw_command = {UINT32_C(0x600f004b),"adlib_raw_command",sxad_adlib_raw_command_fields,SX_COUNT(sxad_adlib_raw_command_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_raw_timer_fields[] = {
    SX_FIELD("value","uint8_t",0,1,SX_NONE),
    SX_FIELD("command","uint8_t",1,1,SX_ID),
    SX_FIELD("timer_divisor","uint16_t",2,2,SX_NONE),
};
const sx_layout sxad_adlib_raw_timer = {UINT32_C(0x600f004c),"adlib_raw_timer",sxad_adlib_raw_timer_fields,SX_COUNT(sxad_adlib_raw_timer_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_raw_metadata_tag_fields[] = {
    SX_FIELD("tag","uint8_t",0,1,SX_ID),
};
const sx_layout sxad_adlib_raw_metadata_tag = {UINT32_C(0x600f004d),"adlib_raw_metadata_tag",sxad_adlib_raw_metadata_tag_fields,SX_COUNT(sxad_adlib_raw_metadata_tag_fields),SX_LE};
static bool sxad_raw(sx_context *c)
{
    uint16_t clock;int64_t at=10;bool end=false;
    if(!sxad_tag(c,0,"RAWADATA",8)||!sx_u16(c,8,false,&clock)||!clock||!sx_add(c,&sxad_adlib_raw_header,0,10))return false;
    while(at<c->size&&!end){uint8_t b[2];if(!sx_read(c,at,b,2))return false;int64_t width=2;const sx_layout *l=&sxad_adlib_raw_command;
        if(b[0]==255&&b[1]==255)end=true;
        else if(b[1]==2){if(!b[0]){if(!sx_u16(c,at+2,false,&clock)||!clock)return false;width=4;l=&sxad_adlib_raw_timer;}else if(b[0]>2)return false;}
        if(!sxad_header(c,l,&at,width))return false;
    }if(!end)return false;
    for(unsigned tag=26;at<c->size&&tag<=28;tag++){
        uint8_t v;if(!sxad_byte(c,at,&v))return false;if(v!=tag){if(tag==26)return false;continue;}
        if(!sxad_header(c,&sxad_adlib_raw_metadata_tag,&at,1)||!sxad_zraw(c,&at,tag==28?1023:40))return false;
    }return at==c->size;
}
bool sx_rdos_raw_build(sx_context*c)
{
    return sxad_raw(c);
}
