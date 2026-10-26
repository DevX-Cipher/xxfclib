/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * totalannihilation_hpi data structures, moved out of the gameplatforms schema family. */
#include "../../xx_format_schema_gameplatforms.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgp_hpi_header_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("directory_end_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("encryption_key","uint32",12,4,SX_FLAGS),
 SX_FIELD("root_directory_offset","uint32",16,4,SX_OFFSET),
};
const sx_layout sxgp_hpi_header={UINT32_C(0x6036003F),"hpi_header",sxgp_hpi_header_fields,SX_COUNT(sxgp_hpi_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_hpi_directory_fields[]={
 SX_FIELD("entry_count","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("entries_offset","uint32",4,4,SX_OFFSET),
};
const sx_layout sxgp_hpi_directory={UINT32_C(0x60360040),"hpi_directory",sxgp_hpi_directory_fields,SX_COUNT(sxgp_hpi_directory_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_hpi_entry_fields[]={
 SX_FIELD("name_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("record_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("is_directory","uint8",8,1,SX_FLAGS),
};
const sx_layout sxgp_hpi_entry={UINT32_C(0x60360041),"hpi_entry",sxgp_hpi_entry_fields,SX_COUNT(sxgp_hpi_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_hpi_file_fields[]={
 SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("data_size","uint32",4,4,SX_SIZE),
 SX_FIELD("compression","uint8",8,1,SX_ID),
};
const sx_layout sxgp_hpi_file={UINT32_C(0x60360042),"hpi_file",sxgp_hpi_file_fields,SX_COUNT(sxgp_hpi_file_fields),SX_LE};
#define SG_ROW(l,at,end) sxgp_row(v,&sxgp_##l,(at),(end))
static bool sxgp_hpi(sxgp_view*v)
{uint64_t end=(uint64_t)v->c->size,de,root,queue[1024];unsigned used=0,count=1;if(!SG_ROW(hpi_header,0,end)||!sxgp_word(v,8,4,false,&de,end)||de>end||!sxgp_word(v,16,4,false,&root,end))return false;queue[0]=root;
 while(used<count){uint64_t at=queue[used++],n,table;if(!SG_ROW(hpi_directory,at,de)||!sxgp_word(v,at,4,false,&n,de)||n>65536||!sxgp_word(v,at+4,4,false,&table,de)||!sxgp_table(v,&sxgp_hpi_entry,table,n,de))return false;
  for(uint64_t i=0;i<n;i++){uint64_t p=table+i*9,rec,kind;if(!sxgp_word(v,p+4,4,false,&rec,de)||!sxgp_word(v,p+8,1,false,&kind,de))return false;if(kind){if(count==1024)return false;for(unsigned j=0;j<count;j++)if(queue[j]==rec)return false;queue[count++]=rec;}else if(!SG_ROW(hpi_file,rec,de))return false;}}
 return true;}
bool sx_totalannihilation_hpi_build(sxgp_view*v)
{
 return sxgp_hpi(v);
}
#undef SG_ROW
