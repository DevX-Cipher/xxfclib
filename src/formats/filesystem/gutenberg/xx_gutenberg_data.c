/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Gutenberg filesystem data structures, moved out of the diskremaining schema family. */
#include "../../xx_format_schema_diskremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdr_gutenberg_link_fields[] = {
    SX_FIELD("previous_track_flags","uint8",0,1,SX_FLAGS),
    SX_FIELD("previous_sector_flags","uint8",1,1,SX_FLAGS),
    SX_FIELD("current_track_flags","uint8",2,1,SX_FLAGS),
    SX_FIELD("current_sector_flags","uint8",3,1,SX_FLAGS),
    SX_FIELD("next_track_flags","uint8",4,1,SX_FLAGS),
    SX_FIELD("next_sector_flags","uint8",5,1,SX_FLAGS),
};
const sx_layout sxdr_gutenberg_link = {0x607f0017U,"gutenberg_link",sxdr_gutenberg_link_fields,SX_COUNT(sxdr_gutenberg_link_fields),SX_LE};
static const xx_data_struct_field_desc sxdr_gutenberg_volume_fields[] = {
    SX_FIELD("volume_name_high_ascii","byte[9]",0,9,SX_NONE),
    SX_FIELD("carriage_return","uint8",9,1,SX_ID),
};
const sx_layout sxdr_gutenberg_volume = {0x607f0018U,"gutenberg_volume",sxdr_gutenberg_volume_fields,SX_COUNT(sxdr_gutenberg_volume_fields),SX_LE};
static const xx_data_struct_field_desc sxdr_gutenberg_entry_fields[] = {
    SX_FIELD("name_high_ascii","byte[12]",0,12,SX_NONE),
    SX_FIELD("first_track_flags","uint8",12,1,SX_FLAGS),
    SX_FIELD("first_sector_flags","uint8",13,1,SX_FLAGS),
    SX_FIELD("type_high_ascii","uint8",14,1,SX_ID),
    SX_FIELD("carriage_return","uint8",15,1,SX_ID),
};
const sx_layout sxdr_gutenberg_entry = {0x607f0019U,"gutenberg_entry",sxdr_gutenberg_entry_fields,SX_COUNT(sxdr_gutenberg_entry_fields),SX_LE};
#define SXDR_ADD(c,n,p) sxdr_put(c,&sxdr_##n,p,1)
static uint32_t sxdr_gb_index(uint8_t t,uint8_t s){t&=127;s&=127;if(t==64)t=0;if(s==64)s=0;return t<35&&s<16?(uint32_t)t*16+s:560;}
static uint64_t sxdr_gb_offset(uint32_t i,bool po){static const uint8_t skew[16]={0,14,13,12,11,10,9,8,7,6,5,4,3,2,1,15};return (uint64_t)(i/16)*4096+(po?skew[i%16]:i%16)*256;}
static bool sxdr_gb_chain(sx_context*c,uint32_t first,bool po,uint16_t*list,uint32_t*count){uint8_t seen[560]={0},h[6];uint32_t curr=first,prev=560;*count=0;for(unsigned k=0;k<560;k++){if(curr>=560||seen[curr]||!sxdr_read(c,sxdr_gb_offset(curr,po),h,6)||sxdr_gb_index(h[2],h[3])!=curr||((h[3]&128)!=0)!=(k==0)||(k&&sxdr_gb_index(h[0],h[1])!=prev))return false;seen[curr]=1;list[(*count)++]=(uint16_t)curr;uint32_t next=sxdr_gb_index(h[4],h[5]);if(h[4]&128)return next==first;prev=curr;curr=next;}return false;}
static bool sxdr_gutenberg(sx_context*c){if(c->size!=35*4096)return false;uint16_t dirs[560],files[560];uint8_t root[256],d[256];bool any=false;
 for(unsigned order=0;order<2;order++){bool po=order!=0;uint32_t nd=0;if(!sxdr_read(c,sxdr_gb_offset(279,po),root,256)||root[15]!=0x8d||xx_rt_memcmp(root+16,"\xc4\xc9\xd2",3)||!sxdr_gb_chain(c,279,po,dirs,&nd))continue;any=true;
 for(uint32_t i=0;i<nd;i++){uint64_t p=sxdr_gb_offset(dirs[i],po);if(!sxdr_read(c,p,d,256))return false;if(xx_rt_memcmp(d+6,root+6,9)||d[15]!=0x8d)continue;if(!SXDR_ADD(c,gutenberg_link,p)||!SXDR_ADD(c,gutenberg_volume,p+6))return false;
 for(unsigned j=0;j<15;j++){const uint8_t*e=d+16+j*16;if(!e[0]||e[0]==0xa0)continue;uint8_t type=e[14]&127;uint32_t first=sxdr_gb_index(e[12],e[13]),nf=0;if(e[15]!=0x8d||(type!=' '&&type!='L'&&type!='M'&&type!='P')||!sxdr_gb_chain(c,first,po,files,&nf))continue;if(!SXDR_ADD(c,gutenberg_entry,p+16+j*16))return false;for(uint32_t k=0;k<nf;k++)if(!SXDR_ADD(c,gutenberg_link,sxdr_gb_offset(files[k],po)))return false;}}
 }return any;}
#undef SXDR_ADD
bool sx_gutenberg_build(sx_context*c)
{
 return sxdr_gutenberg(c);
}
