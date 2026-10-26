/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * nintendo_nds data structures, moved out of the gameplatforms schema family. */
#include "../../xx_format_schema_gameplatforms.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgp_nds_header_fields[]={
 SX_FIELD("title","char[12]",0,12,SX_STRING),
 SX_FIELD("game_code","char[4]",12,4,SX_ID),
 SX_FIELD("maker_code","char[2]",16,2,SX_ID),
 SX_FIELD("unit_code","uint8",18,1,SX_ID),
 SX_FIELD("device_type","uint8",19,1,SX_ID),
 SX_FIELD("capacity_exponent","uint8",20,1,SX_NONE),
 SX_FIELD("reserved","bytes",21,7,SX_RESERVED),
 SX_FIELD("dsi_flags","uint8",28,1,SX_FLAGS),
 SX_FIELD("region","uint8",29,1,SX_ID),
 SX_FIELD("version","uint8",30,1,SX_ID),
 SX_FIELD("autostart","uint8",31,1,SX_FLAGS),
 SX_FIELD("arm9_rom_offset","uint32",32,4,SX_OFFSET),
 SX_FIELD("arm9_entry_address","uint32",36,4,SX_ADDRESS),
 SX_FIELD("arm9_load_address","uint32",40,4,SX_ADDRESS),
 SX_FIELD("arm9_size","uint32",44,4,SX_SIZE),
 SX_FIELD("arm7_rom_offset","uint32",48,4,SX_OFFSET),
 SX_FIELD("arm7_entry_address","uint32",52,4,SX_ADDRESS),
 SX_FIELD("arm7_load_address","uint32",56,4,SX_ADDRESS),
 SX_FIELD("arm7_size","uint32",60,4,SX_SIZE),
 SX_FIELD("fnt_offset","uint32",64,4,SX_OFFSET),
 SX_FIELD("fnt_size","uint32",68,4,SX_SIZE),
 SX_FIELD("fat_offset","uint32",72,4,SX_OFFSET),
 SX_FIELD("fat_size","uint32",76,4,SX_SIZE),
 SX_FIELD("arm9_overlay_offset","uint32",80,4,SX_OFFSET),
 SX_FIELD("arm9_overlay_size","uint32",84,4,SX_SIZE),
 SX_FIELD("arm7_overlay_offset","uint32",88,4,SX_OFFSET),
 SX_FIELD("arm7_overlay_size","uint32",92,4,SX_SIZE),
 SX_FIELD("rom_control_normal","uint32",96,4,SX_FLAGS),
 SX_FIELD("rom_control_secure","uint32",100,4,SX_FLAGS),
 SX_FIELD("banner_offset","uint32",104,4,SX_OFFSET),
 SX_FIELD("secure_area_crc","uint16",108,2,SX_CHECKSUM),
 SX_FIELD("secure_transfer_timeout","uint16",110,2,SX_NONE),
 SX_FIELD("arm9_autoload_list_address","uint32",112,4,SX_ADDRESS),
 SX_FIELD("arm7_autoload_list_address","uint32",116,4,SX_ADDRESS),
 SX_FIELD("secure_area_disable","bytes",120,8,SX_FLAGS),
 SX_FIELD("rom_size","uint32",128,4,SX_SIZE),
 SX_FIELD("header_size","uint32",132,4,SX_SIZE),
 SX_FIELD("unknown_88","uint32",136,4,SX_NONE),
 SX_FIELD("reserved2","bytes",140,8,SX_RESERVED),
 SX_FIELD("nand_rom_end_units","uint16",148,2,SX_NONE),
 SX_FIELD("nand_rw_start_units","uint16",150,2,SX_NONE),
 SX_FIELD("reserved3a","bytes",152,24,SX_RESERVED),
 SX_FIELD("reserved_or_fastboot","bytes",176,16,SX_NONE),
 SX_FIELD("logo","bytes",192,156,SX_SIGNATURE),
 SX_FIELD("logo_crc","uint16",348,2,SX_CHECKSUM),
 SX_FIELD("header_crc","uint16",350,2,SX_CHECKSUM),
 SX_FIELD("debug_rom_offset","uint32",352,4,SX_OFFSET),
 SX_FIELD("debug_size","uint32",356,4,SX_SIZE),
 SX_FIELD("debug_load_address","uint32",360,4,SX_ADDRESS),
 SX_FIELD("reserved3","bytes",364,20,SX_RESERVED),
};
const sx_layout sxgp_nds_header={UINT32_C(0x60360031),"nds_header",sxgp_nds_header_fields,SX_COUNT(sxgp_nds_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_nds_fat_fields[]={
 SX_FIELD("start_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("end_offset","uint32",4,4,SX_OFFSET),
};
const sx_layout sxgp_nds_fat={UINT32_C(0x60360032),"nds_fat",sxgp_nds_fat_fields,SX_COUNT(sxgp_nds_fat_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_nds_overlay_fields[]={
 SX_FIELD("overlay_id","uint32",0,4,SX_ID),
 SX_FIELD("load_address","uint32",4,4,SX_ADDRESS),
 SX_FIELD("ram_size","uint32",8,4,SX_SIZE),
 SX_FIELD("bss_size","uint32",12,4,SX_SIZE),
 SX_FIELD("static_init_start","uint32",16,4,SX_ADDRESS),
 SX_FIELD("static_init_end","uint32",20,4,SX_ADDRESS),
 SX_FIELD("file_id","uint32",24,4,SX_ID),
 SX_FIELD("compressed_size_flags","uint32",28,4,SX_FLAGS),
};
const sx_layout sxgp_nds_overlay={UINT32_C(0x60360033),"nds_overlay",sxgp_nds_overlay_fields,SX_COUNT(sxgp_nds_overlay_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_nds_directory_fields[]={
 SX_FIELD("subtable_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("first_file_id","uint16",4,2,SX_ID),
 SX_FIELD("parent_id_or_directory_count","uint16",6,2,SX_NONE),
};
const sx_layout sxgp_nds_directory={UINT32_C(0x60360034),"nds_directory",sxgp_nds_directory_fields,SX_COUNT(sxgp_nds_directory_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_nds_name_fields[]={
 SX_FIELD("directory_flag_name_length","uint8",0,1,SX_FLAGS),
};
const sx_layout sxgp_nds_name={UINT32_C(0x60360035),"nds_name",sxgp_nds_name_fields,SX_COUNT(sxgp_nds_name_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_nds_subdirectory_fields[]={
 SX_FIELD("directory_id","uint16",0,2,SX_ID),
};
const sx_layout sxgp_nds_subdirectory={UINT32_C(0x60360036),"nds_subdirectory",sxgp_nds_subdirectory_fields,SX_COUNT(sxgp_nds_subdirectory_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_nds_root_directory_fields[]={
 SX_FIELD("subtable_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("first_file_id","uint16",4,2,SX_ID),
 SX_FIELD("directory_count","uint16",6,2,SX_COUNT_PROP),
};
const sx_layout sxgp_nds_root_directory={UINT32_C(0x60360038),"nds_root_directory",sxgp_nds_root_directory_fields,SX_COUNT(sxgp_nds_root_directory_fields),SX_LE};
#define SG_ROW(l,at,end) sxgp_row(v,&sxgp_##l,(at),(end))
static bool sxgp_nds(sxgp_view*v)
{uint64_t end=(uint64_t)v->c->size,fnt,fns,fat,fas,dirs;uint8_t h[384];if(!SG_ROW(nds_header,0,end)||!sxgp_read(v,0,h,sizeof(h),end))return false;
 fnt=xx_data_get_u32(h+64,4,0,false);fns=xx_data_get_u32(h+68,4,0,false);fat=xx_data_get_u32(h+72,4,0,false);fas=xx_data_get_u32(h+76,4,0,false);
 if(fas%8||!sxgp_span(v,fnt,fns,end)||!sxgp_table(v,&sxgp_nds_fat,fat,fas/8,end))return false;
 if(fns){uint64_t stop=fnt+fns;if(!sxgp_word(v,fnt+6,2,false,&dirs,stop)||!dirs||dirs>4096||!SG_ROW(nds_root_directory,fnt,stop)||!sxgp_table(v,&sxgp_nds_directory,fnt+8,dirs-1,stop))return false;
  for(uint64_t i=0;i<dirs;i++){uint64_t p,q;if(!sxgp_word(v,fnt+i*8,4,false,&p,stop)||p>=fns)return false;p+=fnt;
   for(q=0;q<4096;q++){uint64_t ch;if(!SG_ROW(nds_name,p,stop)||!sxgp_word(v,p++,1,false,&ch,stop))return false;if(!ch)break;if(!(ch&127)||!sxgp_span(v,p,(ch&127)+(ch&128?2:0),stop))return false;p+=ch&127;if(ch&128){if(!SG_ROW(nds_subdirectory,p,stop))return false;p+=2;}}
   if(q==4096)return false;
  }
 }
 for(unsigned i=0;i<2;i++){uint64_t at=xx_data_get_u32(h+80+i*8,4,0,false),z=xx_data_get_u32(h+84+i*8,4,0,false);if(z%32||!sxgp_table(v,&sxgp_nds_overlay,at,z/32,end))return false;}
 return true;}
bool sx_nintendo_nds_build(sxgp_view*v)
{
 return sxgp_nds(v);
}
#undef SG_ROW
