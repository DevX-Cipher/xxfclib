/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * PC_86F data structures, moved out of the systemtail schema family. */
#include "../../xx_format_schema_systemtail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxst_pc86f_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("minor_version","uint8",4,1,SX_ID),
    SX_FIELD("major_version","uint8",5,1,SX_ID),
    SX_FIELD("disk_flags","uint16",6,2,SX_FLAGS),
};
const sx_layout sxst_pc86f_header = {0x60370034U,"pc86f_header",sxst_pc86f_header_fields,SX_COUNT(sxst_pc86f_header_fields),SX_LE};
static const xx_data_struct_field_desc sxst_pc86f_track_offset_fields[] = {
    SX_FIELD("track_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxst_pc86f_track_offset = {0x60370035U,"pc86f_track_offset",sxst_pc86f_track_offset_fields,SX_COUNT(sxst_pc86f_track_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxst_pc86f_track_fields[] = {
    SX_FIELD("track_flags","uint16",0,2,SX_FLAGS),
    SX_FIELD("index_bit_position","uint32",2,4,SX_NONE),
};
const sx_layout sxst_pc86f_track = {0x60370036U,"pc86f_track",sxst_pc86f_track_fields,SX_COUNT(sxst_pc86f_track_fields),SX_LE};
static const xx_data_struct_field_desc sxst_pc86f_track_extra_fields[] = {
    SX_FIELD("track_flags","uint16",0,2,SX_FLAGS),
    SX_FIELD("extra_bit_cells","int32",2,4,SX_NONE),
    SX_FIELD("index_bit_position","uint32",6,4,SX_NONE),
};
const sx_layout sxst_pc86f_track_extra = {0x60370037U,"pc86f_track_extra",sxst_pc86f_track_extra_fields,SX_COUNT(sxst_pc86f_track_extra_fields),SX_LE};
#define SXST_ADD(c,l,p) sxst_put(c,&sxst_##l,p,1)
#define SXST_TABLE(c,l,p,n) sxst_put(c,&sxst_##l,p,n)
static bool sxst_pc86f(sx_context*c){uint8_t h[8];if(!sxst_read(c,0,h,8)||!SXST_ADD(c,pc86f_header,0))return false;uint16_t flags=sxst16(h+6);uint64_t n=(flags&8)?512:256;if(!sxst_span(c,8,n*4)||!SXST_TABLE(c,pc86f_track_offset,8,n))return true;for(uint64_t i=0;i<n;i++){uint64_t p;if(!sxst_word(c,8+i*4,4,false,&p))return false;if(!p||p<8+n*4)continue;unsigned hs=(flags&128)?10:6;if(sxst_span(c,p,hs)&&!sxst_put(c,hs==10?&sxst_pc86f_track_extra:&sxst_pc86f_track,p,1))return false;}return true;}
bool sx_pc_86f_build(sx_context*c)
{
 return sxst_pc86f(c);
}
#undef SXST_ADD
#undef SXST_TABLE
