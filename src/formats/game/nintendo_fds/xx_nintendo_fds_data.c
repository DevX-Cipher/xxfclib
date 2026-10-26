/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * nintendo_fds data structures, moved out of the gameplatforms schema family. */
#include "../../xx_format_schema_gameplatforms.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgp_fds_header_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("side_count","uint8",4,1,SX_COUNT_PROP),
 SX_FIELD("reserved","bytes",5,11,SX_RESERVED),
};
const sx_layout sxgp_fds_header={UINT32_C(0x60360013),"fds_header",sxgp_fds_header_fields,SX_COUNT(sxgp_fds_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_fds_file_count_fields[]={
 SX_FIELD("block_type","uint8",0,1,SX_ID),
 SX_FIELD("file_count","uint8",1,1,SX_COUNT_PROP),
};
const sx_layout sxgp_fds_file_count={UINT32_C(0x60360014),"fds_file_count",sxgp_fds_file_count_fields,SX_COUNT(sxgp_fds_file_count_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_fds_file_fields[]={
 SX_FIELD("block_type","uint8",0,1,SX_ID),
 SX_FIELD("file_number","uint8",1,1,SX_ID),
 SX_FIELD("file_id","uint8",2,1,SX_ID),
 SX_FIELD("name","char[8]",3,8,SX_STRING),
 SX_FIELD("load_address","uint16",11,2,SX_ADDRESS),
 SX_FIELD("file_size","uint16",13,2,SX_SIZE),
 SX_FIELD("file_type","uint8",15,1,SX_ID),
 SX_FIELD("data_block_type","uint8",16,1,SX_ID),
};
const sx_layout sxgp_fds_file={UINT32_C(0x60360015),"fds_file",sxgp_fds_file_fields,SX_COUNT(sxgp_fds_file_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_fds_side_fields[]={
 SX_FIELD("block_type","uint8",0,1,SX_ID),
 SX_FIELD("disk_verification","bytes",1,14,SX_SIGNATURE),
 SX_FIELD("licensee","uint8",15,1,SX_ID),
 SX_FIELD("game_code","char[3]",16,3,SX_ID),
 SX_FIELD("game_type","uint8",19,1,SX_ID),
 SX_FIELD("game_version","uint8",20,1,SX_ID),
 SX_FIELD("side_number","uint8",21,1,SX_ID),
 SX_FIELD("disk_number","uint8",22,1,SX_ID),
 SX_FIELD("fmc_disk_type","uint8",23,1,SX_ID),
 SX_FIELD("unknown18","uint8",24,1,SX_NONE),
 SX_FIELD("boot_file_id","uint8",25,1,SX_ID),
 SX_FIELD("unknown1a","bytes",26,5,SX_NONE),
 SX_FIELD("manufacture_date_bcd","bytes",31,3,SX_NONE),
 SX_FIELD("country","uint8",34,1,SX_ID),
 SX_FIELD("unknown23","uint8",35,1,SX_NONE),
 SX_FIELD("unknown24","uint8",36,1,SX_NONE),
 SX_FIELD("unknown25","bytes",37,2,SX_NONE),
 SX_FIELD("unknown27","bytes",39,5,SX_NONE),
 SX_FIELD("rewrite_date_bcd","bytes",44,3,SX_NONE),
 SX_FIELD("unknown2f","uint8",47,1,SX_NONE),
 SX_FIELD("unknown30","uint8",48,1,SX_NONE),
 SX_FIELD("disk_writer_serial","uint16",49,2,SX_ID),
 SX_FIELD("unknown33","uint8",51,1,SX_NONE),
 SX_FIELD("rewrite_count_bcd","uint8",52,1,SX_NONE),
 SX_FIELD("actual_side","uint8",53,1,SX_ID),
 SX_FIELD("disk_type","uint8",54,1,SX_ID),
 SX_FIELD("disk_version","uint8",55,1,SX_ID),
};
const sx_layout sxgp_fds_side={UINT32_C(0x60360089),"fds_side",sxgp_fds_side_fields,SX_COUNT(sxgp_fds_side_fields),SX_LE};
#define SG_ROW(l,at,end) sxgp_row(v,&sxgp_##l,(at),(end))
static bool sxgp_fds(sxgp_view*v)
{uint64_t end=(uint64_t)v->c->size,sides;if(!SG_ROW(fds_header,0,end)||!sxgp_word(v,4,1,false,&sides,end)||sides>8)return false;for(uint64_t i=0;i<sides;i++){uint64_t p=16+i*65500,n,z,stop=p+65500;if(!sxgp_span(v,p,65500,end)||!SG_ROW(fds_side,p,stop)||!SG_ROW(fds_file_count,p+56,stop)||!sxgp_word(v,p+57,1,false,&n,stop)||n>128)return false;p+=58;for(uint64_t j=0;j<n;j++){if(!SG_ROW(fds_file,p,stop)||!sxgp_word(v,p+13,2,false,&z,stop)||!sxgp_span(v,p+17,z,stop))return false;p+=17+z;}}return true;}
bool sx_nintendo_fds_build(sxgp_view*v)
{
 return sxgp_fds(v);
}
#undef SG_ROW
