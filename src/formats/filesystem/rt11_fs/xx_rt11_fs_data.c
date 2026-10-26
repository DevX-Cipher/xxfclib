/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * RT11_FS data structures, moved out of the classicfs schema family. */
#include "../../xx_format_schema_classicfs.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxcf_rt11_home_block_fields[] = {
    SX_FIELD("bad_block_table","byte[130]",0,130,SX_NONE),
    SX_FIELD("reserved0","byte[2]",130,2,SX_RESERVED),
    SX_FIELD("initialization_area","byte[38]",132,38,SX_NONE),
    SX_FIELD("backup_information","byte[18]",170,18,SX_NONE),
    SX_FIELD("reserved1","byte[260]",188,260,SX_RESERVED),
    SX_FIELD("reserved_words","byte[4]",448,4,SX_RESERVED),
    SX_FIELD("reserved2","byte[14]",452,14,SX_RESERVED),
    SX_FIELD("cluster_blocks","uint16",466,2,SX_COUNT_PROP),
    SX_FIELD("first_directory_segment","uint16",468,2,SX_NONE),
    SX_FIELD("system_version_rad50","uint16",470,2,SX_NONE),
    SX_FIELD("volume_name","char[12]",472,12,SX_NONE),
    SX_FIELD("owner_name","char[12]",484,12,SX_NONE),
    SX_FIELD("format_identifier","char[12]",496,12,SX_SIGNATURE),
    SX_FIELD("reserved3","uint16",508,2,SX_RESERVED),
    SX_FIELD("checksum","uint16",510,2,SX_CHECKSUM),
};
const sx_layout sxcf_rt11_home_block = {0x603d0037U,"rt11_home_block",sxcf_rt11_home_block_fields,SX_COUNT(sxcf_rt11_home_block_fields),SX_LE};
static const xx_data_struct_field_desc sxcf_rt11_directory_segment_fields[] = {
    SX_FIELD("total_segments","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("next_segment","uint16",2,2,SX_NONE),
    SX_FIELD("highest_segment","uint16",4,2,SX_NONE),
    SX_FIELD("extra_bytes_per_entry","uint16",6,2,SX_SIZE),
    SX_FIELD("first_data_block","uint16",8,2,SX_NONE),
};
const sx_layout sxcf_rt11_directory_segment = {0x603d0038U,"rt11_directory_segment",sxcf_rt11_directory_segment_fields,SX_COUNT(sxcf_rt11_directory_segment_fields),SX_LE};
static const xx_data_struct_field_desc sxcf_rt11_directory_entry_fields[] = {
    SX_FIELD("status","uint16",0,2,SX_FLAGS),
    SX_FIELD("filename_rad50_1","uint16",2,2,SX_NONE),
    SX_FIELD("filename_rad50_2","uint16",4,2,SX_NONE),
    SX_FIELD("extension_rad50","uint16",6,2,SX_NONE),
    SX_FIELD("length_blocks","uint16",8,2,SX_COUNT_PROP),
    SX_FIELD("job_channel","uint16",10,2,SX_FLAGS),
    SX_FIELD("creation_date_encoded","uint16",12,2,SX_NONE),
};
const sx_layout sxcf_rt11_directory_entry = {0x603d0039U,"rt11_directory_entry",sxcf_rt11_directory_entry_fields,SX_COUNT(sxcf_rt11_directory_entry_fields),SX_LE};
#define SXCF_ADD(c,l,p) sxcf_put(c,&sxcf_##l,p,1)
static bool sxcf_rt11(sx_context*c){
 uint8_t h[512],b[1024];if(!sxcf_read(c,512,h,512)||xx_rt_memcmp(h+496,"DECRT11A    ",12)||!SXCF_ADD(c,rt11_home_block,512))return false;
 uint32_t first=sxcf16(h+468,0),nr=1,seen=0;for(unsigned step=0;nr&&step<31;step++){
  if(nr>31||(seen&(UINT32_C(1)<<(nr-1))))break;seen|=UINT32_C(1)<<(nr-1);uint64_t p=((uint64_t)first+(nr-1)*2)*512;
  if(!sxcf_read(c,p,b,1024))break;unsigned max=sxcf16(b,0),next=sxcf16(b+2,0),extra=sxcf16(b+6,0);if(!max||max>31||nr>max||extra>1000||(extra&1)||sxcf16(b+4,0)>max)break;
  if(!SXCF_ADD(c,rt11_directory_segment,p))return false;
  for(unsigned q=10;q+14+extra<=1024;q+=14+extra){if(!SXCF_ADD(c,rt11_directory_entry,p+q))return false;if(sxcf16(b+q,0)&0x0800)break;}nr=next;
 }return true;
}
bool sx_rt11_fs_build(sx_context*c)
{
 return sxcf_rt11(c);
}
