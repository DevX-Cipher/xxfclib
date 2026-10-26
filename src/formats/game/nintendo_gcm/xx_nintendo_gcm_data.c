/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * nintendo_gcm data structures, moved out of the gameplatforms schema family. */
#include "../../xx_format_schema_gameplatforms.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgp_gcm_title_fields[]={
 SX_FIELD("title","char[992]",0,992,SX_STRING),
};
const sx_layout sxgp_gcm_title={UINT32_C(0x60360091),"gcm_title",sxgp_gcm_title_fields,SX_COUNT(sxgp_gcm_title_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_gcm_debug_fields[]={
 SX_FIELD("debug_monitor_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("debug_monitor_load_address","uint32",4,4,SX_ADDRESS),
 SX_FIELD("reserved","bytes",8,24,SX_RESERVED),
};
const sx_layout sxgp_gcm_debug={UINT32_C(0x60360092),"gcm_debug",sxgp_gcm_debug_fields,SX_COUNT(sxgp_gcm_debug_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_gcm_boot_fields[]={
 SX_FIELD("dol_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("fst_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("fst_size","uint32",8,4,SX_SIZE),
 SX_FIELD("fst_maximum_size","uint32",12,4,SX_SIZE),
 SX_FIELD("fst_load_address","uint32",16,4,SX_ADDRESS),
 SX_FIELD("user_data_offset","uint32",20,4,SX_OFFSET),
 SX_FIELD("user_data_size","uint32",24,4,SX_SIZE),
 SX_FIELD("reserved","uint32",28,4,SX_RESERVED),
};
const sx_layout sxgp_gcm_boot={UINT32_C(0x60360093),"gcm_boot",sxgp_gcm_boot_fields,SX_COUNT(sxgp_gcm_boot_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_gcm_apploader_fields[]={
 SX_FIELD("date","char[16]",0,16,SX_STRING),
 SX_FIELD("entry_address","uint32",16,4,SX_ADDRESS),
 SX_FIELD("code_size","uint32",20,4,SX_SIZE),
 SX_FIELD("trailer_size","uint32",24,4,SX_SIZE),
 SX_FIELD("reserved","uint32",28,4,SX_RESERVED),
};
const sx_layout sxgp_gcm_apploader={UINT32_C(0x60360094),"gcm_apploader",sxgp_gcm_apploader_fields,SX_COUNT(sxgp_gcm_apploader_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_gcm_fst_file_fields[]={
 SX_FIELD("is_directory","uint8",0,1,SX_FLAGS),
 SX_FIELD("name_offset","uint24",1,3,SX_OFFSET),
 SX_FIELD("data_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("data_size","uint32",8,4,SX_SIZE),
};
const sx_layout sxgp_gcm_fst_file={UINT32_C(0x60360095),"gcm_fst_file",sxgp_gcm_fst_file_fields,SX_COUNT(sxgp_gcm_fst_file_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_gcm_fst_directory_fields[]={
 SX_FIELD("is_directory","uint8",0,1,SX_FLAGS),
 SX_FIELD("name_offset","uint24",1,3,SX_OFFSET),
 SX_FIELD("parent_index","uint32",4,4,SX_ID),
 SX_FIELD("next_entry_index","uint32",8,4,SX_ID),
};
const sx_layout sxgp_gcm_fst_directory={UINT32_C(0x60360096),"gcm_fst_directory",sxgp_gcm_fst_directory_fields,SX_COUNT(sxgp_gcm_fst_directory_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_gcm_fst_root_fields[]={
 SX_FIELD("is_directory","uint8",0,1,SX_FLAGS),
 SX_FIELD("name_offset","uint24",1,3,SX_OFFSET),
 SX_FIELD("parent_index","uint32",4,4,SX_ID),
 SX_FIELD("entry_count","uint32",8,4,SX_COUNT_PROP),
};
const sx_layout sxgp_gcm_fst_root={UINT32_C(0x60360097),"gcm_fst_root",sxgp_gcm_fst_root_fields,SX_COUNT(sxgp_gcm_fst_root_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_gcm_dol_offset_fields[]={
 SX_FIELD("section_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxgp_gcm_dol_offset={UINT32_C(0x60360098),"gcm_dol_offset",sxgp_gcm_dol_offset_fields,SX_COUNT(sxgp_gcm_dol_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_gcm_dol_address_fields[]={
 SX_FIELD("load_address","uint32",0,4,SX_ADDRESS),
};
const sx_layout sxgp_gcm_dol_address={UINT32_C(0x60360099),"gcm_dol_address",sxgp_gcm_dol_address_fields,SX_COUNT(sxgp_gcm_dol_address_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_gcm_dol_size_fields[]={
 SX_FIELD("section_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxgp_gcm_dol_size={UINT32_C(0x6036009A),"gcm_dol_size",sxgp_gcm_dol_size_fields,SX_COUNT(sxgp_gcm_dol_size_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_gcm_dol_tail_fields[]={
 SX_FIELD("bss_address","uint32",0,4,SX_ADDRESS),
 SX_FIELD("bss_size","uint32",4,4,SX_SIZE),
 SX_FIELD("entry_address","uint32",8,4,SX_ADDRESS),
 SX_FIELD("reserved","bytes",12,28,SX_RESERVED),
};
const sx_layout sxgp_gcm_dol_tail={UINT32_C(0x6036009B),"gcm_dol_tail",sxgp_gcm_dol_tail_fields,SX_COUNT(sxgp_gcm_dol_tail_fields),SX_BE};
#define SG_ROW(l,at,end) sxgp_row(v,&sxgp_##l,(at),(end))
static bool sxgp_gcm(sxgp_view*v)
{uint64_t end=(uint64_t)v->c->size,dol,fst,fs,n;if(!SG_ROW(gcm_id,0,end)||!SG_ROW(gcm_title,32,end)||!SG_ROW(gcm_debug,0x400,end)||!SG_ROW(gcm_boot,0x420,end)||!SG_ROW(gcm_apploader,0x2440,end)||!sxgp_word(v,0x420,4,true,&dol,end)||!sxgp_word(v,0x424,4,true,&fst,end)||!sxgp_word(v,0x428,4,true,&fs,end)||!sxgp_span(v,fst,fs,end))return false;
 if(!sxgp_table(v,&sxgp_gcm_dol_offset,dol,18,end)||!sxgp_table(v,&sxgp_gcm_dol_address,dol+72,18,end)||!sxgp_table(v,&sxgp_gcm_dol_size,dol+144,18,end)||!SG_ROW(gcm_dol_tail,dol+216,end))return false;
 uint64_t stop=fst+fs;if(!SG_ROW(gcm_fst_root,fst,stop)||!sxgp_word(v,fst+8,4,true,&n,stop)||!n||n>4094||!sxgp_span(v,fst,n*12,stop))return false;
 for(uint64_t i=1;i<n;i++){uint64_t at=fst+i*12,kind;if(!sxgp_word(v,at,1,false,&kind,stop)||!sxgp_row(v,kind?&sxgp_gcm_fst_directory:&sxgp_gcm_fst_file,at,stop))return false;}return true;}
bool sx_nintendo_gcm_build(sxgp_view*v)
{
 return sxgp_gcm(v);
}
#undef SG_ROW
