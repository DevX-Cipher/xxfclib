/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * xbox xdvdfs data structures, moved out of the disklegacy schema family. */
#include "../../xx_format_schema_disklegacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdleg_xdvdfs_volume_descriptor_fields[] = {
    SX_FIELD("signature","char[20]",0,20,SX_SIGNATURE),
    SX_FIELD("root_directory_sector","uint32",20,4,SX_NONE),
    SX_FIELD("root_directory_size","uint32",24,4,SX_SIZE),
    SX_FIELD("creation_filetime","uint64",28,8,SX_NONE),
    SX_FIELD("reserved","byte[1992]",36,1992,SX_RESERVED),
    SX_FIELD("ending_signature","char[20]",2028,20,SX_SIGNATURE),
};
const sx_layout sxdleg_xdvdfs_volume_descriptor = {0x60750040U,"xdvdfs_volume_descriptor",sxdleg_xdvdfs_volume_descriptor_fields,SX_COUNT(sxdleg_xdvdfs_volume_descriptor_fields),SX_LE};
static const xx_data_struct_field_desc sxdleg_xdvdfs_directory_entry_fields[] = {
    SX_FIELD("left_child_words","uint16",0,2,SX_NONE),
    SX_FIELD("right_child_words","uint16",2,2,SX_NONE),
    SX_FIELD("first_sector","uint32",4,4,SX_NONE),
    SX_FIELD("file_size","uint32",8,4,SX_SIZE),
    SX_FIELD("attributes","uint8",12,1,SX_FLAGS),
    SX_FIELD("name_length","uint8",13,1,SX_COUNT_PROP),
};
const sx_layout sxdleg_xdvdfs_directory_entry = {0x60750041U,"xdvdfs_directory_entry",sxdleg_xdvdfs_directory_entry_fields,SX_COUNT(sxdleg_xdvdfs_directory_entry_fields),SX_LE};
#define SXDLEG_ADD(c,l,p) sxdleg_put(c,&sxdleg_##l,p,1)
static bool sxdleg_xdvdfs(sx_context*c){uint8_t h[32],e[14];if(!sxdleg_read(c,65536,h,32)||xx_rt_memcmp(h,"MICROSOFT*XBOX*MEDIA",20)||!SXDLEG_ADD(c,xdvdfs_volume_descriptor,65536))return false;uint64_t base=(uint64_t)sxdleg32(h+20,0)*2048,size=sxdleg32(h+24,0);if(size<14||!sxdleg_span(c,base,size))return true;uint32_t todo[1024]={0};unsigned count=1;for(unsigned i=0;i<count;i++){uint64_t p=todo[i];if(p>size||size-p<14||!sxdleg_read(c,base+p,e,14)||e[13]>size-p-14)continue;if(!SXDLEG_ADD(c,xdvdfs_directory_entry,base+p))return false;for(unsigned j=0;j<2;j++){uint32_t child=sxdleg16(e+j*2,0);if(!child||child==65535)continue;child*=4;bool seen=false;for(unsigned k=0;k<count;k++)if(todo[k]==child)seen=true;if(!seen&&count<1024)todo[count++]=child;}}return true;}
#undef SXDLEG_ADD
bool sx_xbox_xdvdfs_build(sx_context*c)
{
 return sxdleg_xdvdfs(c);
}
