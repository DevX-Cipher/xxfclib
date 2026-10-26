/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * valve_gcf_cache data structures, moved out of the gamecontainers schema family. */
#include "../../xx_format_schema_gamecontainers.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgco_gcf_header_fields[]={
 SX_FIELD("marker","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("major_version","uint32",4,4,SX_ID),
 SX_FIELD("minor_version","uint32",8,4,SX_ID),
 SX_FIELD("cache_id","uint32",12,4,SX_ID),
 SX_FIELD("last_version_played","uint32",16,4,SX_ID),
 SX_FIELD("unknown14","uint32",20,4,SX_NONE),
 SX_FIELD("unknown18","uint32",24,4,SX_NONE),
 SX_FIELD("file_bytes","uint32",28,4,SX_SIZE),
 SX_FIELD("block_bytes","uint32",32,4,SX_SIZE),
 SX_FIELD("blocks","uint32",36,4,SX_COUNT_PROP),
 SX_FIELD("unknown28","uint32",40,4,SX_NONE),
};
const sx_layout sxgco_gcf_header={UINT32_C(0x6040004E),"gcf_header",sxgco_gcf_header_fields,SX_COUNT(sxgco_gcf_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_gcf_block_header_fields[]={
 SX_FIELD("entries","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("used_entries","uint32",4,4,SX_COUNT_PROP),
 SX_FIELD("unknown08","bytes",8,20,SX_NONE),
 SX_FIELD("checksum","uint32",28,4,SX_CHECKSUM),
};
const sx_layout sxgco_gcf_block_header={UINT32_C(0x6040004F),"gcf_block_header",sxgco_gcf_block_header_fields,SX_COUNT(sxgco_gcf_block_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_gcf_block_link_fields[]={
 SX_FIELD("next_block","uint32",0,4,SX_ID),
};
const sx_layout sxgco_gcf_block_link={UINT32_C(0x60400052),"gcf_block_link",sxgco_gcf_block_link_fields,SX_COUNT(sxgco_gcf_block_link_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_gcf_map_header_fields[]={
 SX_FIELD("entries","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("first_entry","uint32",4,4,SX_ID),
 SX_FIELD("last_entry","uint32",8,4,SX_ID),
 SX_FIELD("unknown0c","uint32",12,4,SX_NONE),
 SX_FIELD("checksum","uint32",16,4,SX_CHECKSUM),
};
const sx_layout sxgco_gcf_map_header={UINT32_C(0x60400053),"gcf_map_header",sxgco_gcf_map_header_fields,SX_COUNT(sxgco_gcf_map_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_gcf_map_entry_fields[]={
 SX_FIELD("previous_entry","uint32",0,4,SX_ID),
 SX_FIELD("next_entry","uint32",4,4,SX_ID),
};
const sx_layout sxgco_gcf_map_entry={UINT32_C(0x60400054),"gcf_map_entry",sxgco_gcf_map_entry_fields,SX_COUNT(sxgco_gcf_map_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_gcf_directory_map_fields[]={
 SX_FIELD("unknown00","uint32",0,4,SX_NONE),
 SX_FIELD("unknown04","uint32",4,4,SX_NONE),
};
const sx_layout sxgco_gcf_directory_map={UINT32_C(0x60400058),"gcf_directory_map",sxgco_gcf_directory_map_fields,SX_COUNT(sxgco_gcf_directory_map_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_gcf_directory_link_fields[]={
 SX_FIELD("first_block_entry","uint32",0,4,SX_ID),
};
const sx_layout sxgco_gcf_directory_link={UINT32_C(0x60400059),"gcf_directory_link",sxgco_gcf_directory_link_fields,SX_COUNT(sxgco_gcf_directory_link_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_gcf_checksum_header_fields[]={
 SX_FIELD("version","uint32",0,4,SX_ID),
 SX_FIELD("checksum_bytes","uint32",4,4,SX_SIZE),
};
const sx_layout sxgco_gcf_checksum_header={UINT32_C(0x6040005A),"gcf_checksum_header",sxgco_gcf_checksum_header_fields,SX_COUNT(sxgco_gcf_checksum_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_gcf_info_word_fields[]={
 SX_FIELD("unknown","uint32",0,4,SX_NONE),
};
const sx_layout sxgco_gcf_info_word={UINT32_C(0x60400060),"gcf_info_word",sxgco_gcf_info_word_fields,SX_COUNT(sxgco_gcf_info_word_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_gcf_directory_index_fields[]={
 SX_FIELD("directory_item","uint32",0,4,SX_ID),
};
const sx_layout sxgco_gcf_directory_index={UINT32_C(0x60400061),"gcf_directory_index",sxgco_gcf_directory_index_fields,SX_COUNT(sxgco_gcf_directory_index_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_gcf_checksum_map_header_fields[]={
 SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("items","uint32",8,4,SX_COUNT_PROP),
 SX_FIELD("checksums","uint32",12,4,SX_COUNT_PROP),
};
const sx_layout sxgco_gcf_checksum_map_header={UINT32_C(0x60400062),"gcf_checksum_map_header",sxgco_gcf_checksum_map_header_fields,SX_COUNT(sxgco_gcf_checksum_map_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_gcf_checksum_map_entry_fields[]={
 SX_FIELD("checksums","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("first_checksum","uint32",4,4,SX_ID),
};
const sx_layout sxgco_gcf_checksum_map_entry={UINT32_C(0x60400063),"gcf_checksum_map_entry",sxgco_gcf_checksum_map_entry_fields,SX_COUNT(sxgco_gcf_checksum_map_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_gcf_checksum_fields[]={
 SX_FIELD("checksum","uint32",0,4,SX_CHECKSUM),
};
const sx_layout sxgco_gcf_checksum={UINT32_C(0x60400064),"gcf_checksum",sxgco_gcf_checksum_fields,SX_COUNT(sxgco_gcf_checksum_fields),SX_LE};
#define GC_ROW(l,at,end) sxgco_row(v,&sxgco_##l,(at),(end))
static bool sxgco_gcf(sxgco_view*v)
{uint64_t e=v->c->size,minor,blocks,blocksize,p=44,n,names,info,copies,locals,dirsize,dir,needed,map=0,check=0,datahead=0,dhsize;
 if(!GC_ROW(gcf_header,0,e)||!sxgco_word(v,8,4,false,&minor,e)||!sxgco_word(v,32,4,false,&blocksize,e)||!sxgco_word(v,36,4,false,&blocks,e)||blocks>UINT32_C(0x1000000)||!GC_ROW(gcf_block_header,p,e))return false;p+=32;
 if(!sxgco_table(v,&sxgco_gcf_block_entry,p,blocks,e))return false;p+=28*blocks;if(!GC_ROW(gcf_fragment_header,p,e))return false;p+=16;if(!sxgco_table(v,&sxgco_gcf_block_link,p,blocks,e))return false;p+=4*blocks;
 if(minor<6){if(!GC_ROW(gcf_map_header,p,e))return false;p+=20;if(!sxgco_table(v,&sxgco_gcf_map_entry,p,blocks,e))return false;p+=8*blocks;}
 dir=p;if(!GC_ROW(gcf_directory_header,p,e)||!sxgco_word(v,p+12,4,false,&n,e)||!sxgco_word(v,p+24,4,false,&dirsize,e)||!sxgco_word(v,p+28,4,false,&names,e)||!sxgco_word(v,p+32,4,false,&info,e)||!sxgco_word(v,p+36,4,false,&copies,e)||!sxgco_word(v,p+40,4,false,&locals,e)||!n||n>UINT32_C(0x100000))return false;
 needed=56+n*28+names+4*(info+n+copies+locals);if(!sxgco_span(v,dir,needed,e)||!sxgco_table(v,&sxgco_filename_byte,dir+56+n*28,names,e))return false;
 for(uint64_t i=0;i<n;i++){uint64_t flags;if(!sxgco_word(v,dir+56+i*28+12,4,false,&flags,e)||!sxgco_row(v,(flags&0x4000)?&sxgco_gcf_directory_file:&sxgco_gcf_directory_folder,dir+56+i*28,e))return false;}
 p=dir+56+n*28+names;if(!sxgco_table(v,&sxgco_gcf_info_word,p,info+n,e)||!sxgco_table(v,&sxgco_gcf_directory_index,p+4*(info+n),copies+locals,e))return false;
 uint64_t ends[3]={dir+needed,dir+dirsize,dir+56+dirsize};bool found=false,with=false;dhsize=minor>=5?24:20;
 for(unsigned i=0;i<3&&!found;i++)for(unsigned j=0;j<2&&!found;j++){uint64_t m,c,d,z,b,s,first,used;bool header=(minor>=5)==(j==0);if(ends[i]<dir+needed||ends[i]>e||!sxgco_span(v,ends[i],(header?8:0)+n*4+8,e))continue;m=ends[i]+(header?8:0);c=m+n*4;if(!sxgco_word(v,c+4,4,false,&z,e)||z>e-c-8)continue;d=c+8+z;if(!sxgco_span(v,d,dhsize,e))continue;uint64_t q=d+(minor>=5?4:0);if(!sxgco_word(v,q,4,false,&b,e)||!sxgco_word(v,q+4,4,false,&s,e)||!sxgco_word(v,q+8,4,false,&first,e)||!sxgco_word(v,q+12,4,false,&used,e)||b!=blocks||s!=blocksize||used>blocks||first<d+dhsize||first>e)continue;map=m;check=c;datahead=d;with=header;found=true;}
 if(!found)return false;if(with&&!GC_ROW(gcf_directory_map,map-8,e))return false;
 uint64_t sumsize,magic,itemcount,sumcount;if(!sxgco_word(v,check+4,4,false,&sumsize,e))return false;p=check+8;
 if(sumsize>=16&&sxgco_word(v,p,4,false,&magic,e)&&magic==UINT32_C(0x14893721)&&sxgco_word(v,p+8,4,false,&itemcount,e)&&sxgco_word(v,p+12,4,false,&sumcount,e)&&itemcount<=(sumsize-16)/8&&sumcount<=(sumsize-16-itemcount*8)/4){if(!GC_ROW(gcf_checksum_map_header,p,e)||!sxgco_table(v,&sxgco_gcf_checksum_map_entry,p+16,itemcount,e)||!sxgco_table(v,&sxgco_gcf_checksum,p+16+itemcount*8,sumcount,e))return false;}
 return sxgco_table(v,&sxgco_gcf_directory_link,map,n,e)&&GC_ROW(gcf_checksum_header,check,e)&&sxgco_row(v,minor>=5?&sxgco_gcf_data_header5:&sxgco_gcf_data_header3,datahead,e);}
bool sx_valve_gcf_cache_build(sxgco_view*v)
{
 return sxgco_gcf(v);
}
#undef GC_ROW
