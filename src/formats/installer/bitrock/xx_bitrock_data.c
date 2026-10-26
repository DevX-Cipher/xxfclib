/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * BitRock (CookFS) data structures, moved out of the installerremaining schema family. */
#include "../../xx_format_schema_installerremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxir_installer_utf8_fields[]={
 SX_FIELD("text","utf8",0,0,SX_NONE),
};
const sx_layout sxir_installer_utf8={0x60800009U,"installer_utf8",sxir_installer_utf8_fields,SX_COUNT(sxir_installer_utf8_fields),SX_LE};
static const xx_data_struct_field_desc sxir_cookfs_page_digest_fields[]={
 SX_FIELD("digest","uint8[16]",0,16,SX_CHECKSUM),
};
const sx_layout sxir_cookfs_page_digest={0x6080000dU,"cookfs_page_digest",sxir_cookfs_page_digest_fields,SX_COUNT(sxir_cookfs_page_digest_fields),SX_BE};
static const xx_data_struct_field_desc sxir_cookfs_page_size_fields[]={
 SX_FIELD("stored_size","uint32be",0,4,SX_SIZE),
};
const sx_layout sxir_cookfs_page_size={0x6080000eU,"cookfs_page_size",sxir_cookfs_page_size_fields,SX_COUNT(sxir_cookfs_page_size_fields),SX_BE};
static const xx_data_struct_field_desc sxir_cookfs_index_fields[]={
 SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
};
const sx_layout sxir_cookfs_index={0x60800010U,"cookfs_index",sxir_cookfs_index_fields,SX_COUNT(sxir_cookfs_index_fields),SX_BE};
static const xx_data_struct_field_desc sxir_cookfs_directory_fields[]={
 SX_FIELD("entry_count","uint32be",0,4,SX_COUNT_PROP),
};
const sx_layout sxir_cookfs_directory={0x60800011U,"cookfs_directory",sxir_cookfs_directory_fields,SX_COUNT(sxir_cookfs_directory_fields),SX_BE};
static const xx_data_struct_field_desc sxir_cookfs_name_length_fields[]={
 SX_FIELD("name_size","uint8",0,1,SX_SIZE),
};
const sx_layout sxir_cookfs_name_length={0x60800012U,"cookfs_name_length",sxir_cookfs_name_length_fields,SX_COUNT(sxir_cookfs_name_length_fields),SX_BE};
static const xx_data_struct_field_desc sxir_cookfs_block_fields[]={
 SX_FIELD("page_index","uint32be",0,4,SX_ID),
 SX_FIELD("page_relative_offset","uint32be",4,4,SX_OFFSET),
 SX_FIELD("size","uint32be",8,4,SX_SIZE),
};
const sx_layout sxir_cookfs_block={0x60800014U,"cookfs_block",sxir_cookfs_block_fields,SX_COUNT(sxir_cookfs_block_fields),SX_BE};
#define IR_ROW(name,at,end) sxir_row(v,&sxir_##name,(at),(end))
#define IR_U(at,z,out,end) sxir_u(v,(at),(z),false,&(out),(end))
static bool sxir_cook_dir(sxir_view*v,uint64_t*at,uint64_t end,unsigned depth)
{uint64_t count;if(depth>64||!sxir_u(v,*at,4,true,&count,end)||count>65535||!IR_ROW(cookfs_directory,*at,end))return false;*at+=4;
 for(uint64_t i=0;i<count;i++){uint64_t n,blocks;uint8_t zero;if(!IR_U(*at,1,n,end)||!n||!IR_ROW(cookfs_name_length,*at,end))return false;(*at)++;if(!sxir_span(v,*at,n+1,end)||!sxir_emit(v,&sxir_installer_utf8,*at,n,end)||!sxir_read(v,*at+n,&zero,1,end)||zero||!IR_ROW(installer_terminator,*at+n,end))return false;*at+=n+1;if(!sxir_u(v,*at+8,4,true,&blocks,end)||!IR_ROW(cookfs_entry,*at,end))return false;*at+=12;
  if(blocks==UINT32_MAX){if(!sxir_cook_dir(v,at,end,depth+1))return false;}else{if(blocks>1000000||!sxir_table(v,&sxir_cookfs_block,*at,blocks,end))return false;*at+=blocks*12;}}
 return true;}
static bool sxir_cookfs(sxir_view*v)
{uint64_t end=v->c->size,sig,index_size,count;if(v->c->f->format_size>0&&(uint64_t)v->c->f->format_size<end)end=(uint64_t)v->c->f->format_size;if(end<16||!sxir_find(v,end>16777216?end-16777216:0,end,"CFS0002",7,true,&sig)||sig<9)return false;uint64_t footer=sig-9,finish=sig+7;
 if(!sxir_u(v,footer,4,true,&index_size,finish)||!index_size||index_size>67108864||!sxir_u(v,footer+4,4,true,&count,finish)||count>65535||index_size>footer||count*20>footer-index_size||!IR_ROW(cookfs_footer,footer,finish))return false;
 uint64_t table=footer-index_size-count*20,total=0;for(uint64_t i=0;i<count;i++){uint64_t z;if(!sxir_u(v,table+count*16+4*i,4,true,&z,footer)||z>67108864||z>table-total)return false;total+=z;}
 if(!sxir_table(v,&sxir_cookfs_page_digest,table,count,footer)||!sxir_table(v,&sxir_cookfs_page_size,table+16*count,count,footer))return false;
 uint64_t p=table-total;for(uint64_t i=0;i<count;i++){uint64_t z;if(!sxir_u(v,table+count*16+4*i,4,true,&z,footer))return false;if(z&&!IR_ROW(cookfs_blob,p,p+z))return false;p+=z;}
 p=footer-index_size;uint64_t method;if(!IR_U(p,1,method,footer)||!IR_ROW(cookfs_blob,p,footer))return false;if(method)return true;p++;if(!sxir_eq(v,p,"CFS2.200",8,footer)||!IR_ROW(cookfs_index,p,footer))return false;p+=8;return sxir_cook_dir(v,&p,footer,0);}
bool sx_bitrock_build(sx_context*c)
{
 sxir_view view={c,0},*v=&view;return sxir_cookfs(v);
}
#undef IR_ROW
#undef IR_U
