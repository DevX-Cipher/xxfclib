/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * wintermutedcp data structures, moved out of the gamearchives schema family. */
#include "../../xx_format_schema_gamearchives.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxga_name_length8_fields[]={
 SX_FIELD("name_bytes","uint8",0,1,SX_SIZE),
};
const sx_layout sxga_name_length8={UINT32_C(0x603B0003),"name_length8",sxga_name_length8_fields,SX_COUNT(sxga_name_length8_fields),SX_LE};
static const xx_data_struct_field_desc sxga_dcp_directory_fields[]={
 SX_FIELD("cd","uint8",0,1,SX_ID),
 SX_FIELD("files","uint32",1,4,SX_COUNT_PROP),
};
const sx_layout sxga_dcp_directory={UINT32_C(0x603B0031),"dcp_directory",sxga_dcp_directory_fields,SX_COUNT(sxga_dcp_directory_fields),SX_LE};
#define GA_ROW(l,at,end) sxga_row(v,&sxga_##l,(at),(end))
static bool sxga_dcp(sxga_view*v)
{uint64_t end=v->c->size,at=128,version,dirs,n,z;if(!GA_ROW(dcp_header,0,end)||!sxga_word(v,8,4,false,&version,end)||!sxga_word(v,124,4,false,&dirs,end)||dirs>1000000)return false;if(version==0x200){if(!GA_ROW(dcp_directory_offset,128,end)||!sxga_word(v,128,4,false,&at,end))return false;}for(uint64_t i=0;i<dirs;i++){if(!GA_ROW(name_length8,at,end)||!sxga_word(v,at,1,false,&z,end))return false;at++;if(!sxga_named(v,at,z,end,false))return false;at+=z;if(!GA_ROW(dcp_directory,at,end)||!sxga_word(v,at+1,4,false,&n,end)||n>1000000)return false;at+=5;for(uint64_t j=0;j<n;j++){if(!GA_ROW(name_length8,at,end)||!sxga_word(v,at,1,false,&z,end))return false;at++;if(!sxga_named(v,at,z,end,version==0x200))return false;at+=z;if(!sxga_row(v,version==0x200?&sxga_dcp_entry2:&sxga_dcp_entry1,at,end))return false;at+=version==0x200?24:16;}}return true;}
bool sx_wintermutedcp_build(sxga_view*v)
{
 return sxga_dcp(v);
}
#undef GA_ROW
