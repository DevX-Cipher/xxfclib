/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * htc_nbh_rom_image data structures, moved out of the firmwaremore schema family. */
#include "../../xx_format_schema_firmwaremore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_fm_htc_nbh_header_fields[] = {
    SX_FIELD("magic","byte[7]",0,7,SX_SIGNATURE),
    SX_FIELD("initial_signature","byte[16]",7,16,SX_NONE),
};
const sx_layout sx_fm_htc_nbh_header = {0x60220011U,"htc_nbh_header",sx_fm_htc_nbh_header_fields,SX_COUNT(sx_fm_htc_nbh_header_fields),SX_LE};
static const xx_data_struct_field_desc sx_fm_htc_dbh_prefix_fields[] = {
    SX_FIELD("magic","uint32[8]",0,32,SX_SIGNATURE),
    SX_FIELD("device_name","char[32]",32,32,SX_NONE),
};
const sx_layout sx_fm_htc_dbh_prefix = {0x60220013U,"htc_dbh_prefix",sx_fm_htc_dbh_prefix_fields,SX_COUNT(sx_fm_htc_dbh_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sx_fm_htc_dbh_section_size_fields[] = {
    SX_FIELD("section_size","uint32",0,4,SX_SIZE),
};
const sx_layout sx_fm_htc_dbh_section_size = {0x60220016U,"htc_dbh_section_size",sx_fm_htc_dbh_section_size_fields,SX_COUNT(sx_fm_htc_dbh_section_size_fields),SX_LE};
static const xx_data_struct_field_desc sx_fm_htc_dbh_identity_fields[] = {
    SX_FIELD("cid","char[32]",0,32,SX_NONE),
    SX_FIELD("version","char[16]",32,16,SX_NONE),
    SX_FIELD("language","char[16]",48,16,SX_NONE),
};
const sx_layout sx_fm_htc_dbh_identity = {0x60220017U,"htc_dbh_identity",sx_fm_htc_dbh_identity_fields,SX_COUNT(sx_fm_htc_dbh_identity_fields),SX_LE};
static bool sx_fm_dbh(sx_context *c,int64_t at)
{
    return sx_fm_add(c,&sx_fm_htc_dbh_prefix,at,64)&&sx_fm_table(c,&sx_fm_htc_dbh_section_type,at+64,4,32)&&sx_fm_table(c,&sx_fm_htc_dbh_section_offset,at+192,4,32)&&sx_fm_table(c,&sx_fm_htc_dbh_section_size,at+320,4,32)&&sx_fm_add(c,&sx_fm_htc_dbh_identity,at+448,64);
}
static bool sx_fm_nbh(sx_context *c)
{
    if(!sx_fm_add(c,&sx_fm_htc_nbh_header,0,23))return false;uint64_t at=23,logical=0;unsigned count=0;
    while(at+9<=(uint64_t)c->size&&count<65500){
        uint8_t h[9];if(!sx_fm_read(c,(int64_t)at,h,9))return false;
        uint32_t data=xx_data_get_u32(h,9,0,false),sig=xx_data_get_u32(h,9,4,false);
        if(h[8]>2||sig>65536)break;if(!sx_fm_add(c,&sx_fm_htc_nbh_block_header,(int64_t)at,9))return false;
        if(logical==0&&data>=512&&sx_fm_span(c,(int64_t)at+9,512)){uint8_t m[32];bool valid=sx_fm_read(c,(int64_t)at+9,m,32);for(unsigned i=0;i<8&&valid;i++)if(xx_data_get_u32(m,32,i*4,false)!=(uint8_t)"HTCIMAGE"[i])valid=false;if(valid&&!sx_fm_dbh(c,(int64_t)at+9))return false;}
        uint64_t next=at+9+(uint64_t)data+sig;count++;if(next>(uint64_t)c->size||h[8]==2)break;
        logical+=data;at=next;
    }
    return !c->failed;
}
bool sx_htc_nbh_rom_image_build(sx_context*c)
{
    return sx_fm_nbh(c);
}
