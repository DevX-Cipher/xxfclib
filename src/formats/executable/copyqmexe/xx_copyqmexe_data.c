/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * CopyQMOverlay data structures, moved out of the archiveend schema family. */
#include "../../xx_format_schema_archiveend.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#if SX_ALIAS_READER_FACTORY
#include "xxfclib/formats/archive/sfx_tgcf/xx_sfx_tgcf.h"
#endif

static const xx_data_struct_field_desc sxaend_copyqm_tx_header_fields[]={
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("node_count","uint16",2,2,SX_COUNT_PROP),
 SX_FIELD("screen_count","uint16",4,2,SX_COUNT_PROP),
 SX_FIELD("body_size","uint32",6,4,SX_SIZE),
 SX_FIELD("node_count_copy","uint16",10,2,SX_COUNT_PROP),
};
const sx_layout sxaend_copyqm_tx_header={UINT32_C(0x60840014),"copyqm_tx_header",sxaend_copyqm_tx_header_fields,SX_COUNT(sxaend_copyqm_tx_header_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_copyqm_tx_leaf_fields[]={
 SX_FIELD("leaf_marker","uint8",0,1,SX_ID),
 SX_FIELD("symbol","uint8",1,1,SX_NONE),
};
const sx_layout sxaend_copyqm_tx_leaf={UINT32_C(0x60840015),"copyqm_tx_leaf",sxaend_copyqm_tx_leaf_fields,SX_COUNT(sxaend_copyqm_tx_leaf_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_copyqm_tx_branch_fields[]={
 SX_FIELD("zero_child","uint8",0,1,SX_NONE),
 SX_FIELD("one_child","uint8",1,1,SX_NONE),
};
const sx_layout sxaend_copyqm_tx_branch={UINT32_C(0x60840016),"copyqm_tx_branch",sxaend_copyqm_tx_branch_fields,SX_COUNT(sxaend_copyqm_tx_branch_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_copyqm_tx_screen6_fields[]={
 SX_FIELD("line_count","uint16",0,2,SX_COUNT_PROP),
 SX_FIELD("data_offset","uint32",2,4,SX_OFFSET),
};
const sx_layout sxaend_copyqm_tx_screen6={UINT32_C(0x60840017),"copyqm_tx_screen6",sxaend_copyqm_tx_screen6_fields,SX_COUNT(sxaend_copyqm_tx_screen6_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_copyqm_tx_screen8_fields[]={
 SX_FIELD("unknown","uint16",0,2,SX_NONE),
 SX_FIELD("line_count","uint16",2,2,SX_COUNT_PROP),
 SX_FIELD("data_offset","uint32",4,4,SX_OFFSET),
};
const sx_layout sxaend_copyqm_tx_screen8={UINT32_C(0x60840018),"copyqm_tx_screen8",sxaend_copyqm_tx_screen8_fields,SX_COUNT(sxaend_copyqm_tx_screen8_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_copyqm_tx_geometry_fields[]={
 SX_FIELD("geometry_0","uint16",0,2,SX_NONE),
 SX_FIELD("geometry_1","uint16",2,2,SX_NONE),
 SX_FIELD("geometry_2","uint16",4,2,SX_NONE),
};
const sx_layout sxaend_copyqm_tx_geometry={UINT32_C(0x60840019),"copyqm_tx_geometry",sxaend_copyqm_tx_geometry_fields,SX_COUNT(sxaend_copyqm_tx_geometry_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_copyqm_tx_line_fields[]={
 SX_FIELD("record_size","uint8",0,1,SX_SIZE),
};
const sx_layout sxaend_copyqm_tx_line={UINT32_C(0x6084001a),"copyqm_tx_line",sxaend_copyqm_tx_line_fields,SX_COUNT(sxaend_copyqm_tx_line_fields),SX_LE};
#define SXAEND_LIMIT 20000U
static bool sxaend_copyqm(sx_context*c){uint8_t h[64];if(!sxaend_read(c,0,h,64)||h[0]!='M'||h[1]!='Z')return false;uint64_t pages=sxaend_uint(h+4,2,false),last=sxaend_uint(h+2,2,false);if(!pages||last>511)return false;uint64_t start=(pages-1)*512+(last?last:512);if(!sxaend_read(c,start,h,12)||h[0]!='T'||h[1]!='X')return false;uint64_t nc=sxaend_uint(h+2,2,false),sc=sxaend_uint(h+4,2,false),body=sxaend_uint(h+6,4,false);if(nc<3||nc>255||!(nc&1)||!sc||sc>1000||!sxaend_span(c,start,10+body)||!sxaend_add(c,&sxaend_copyqm_tx_header,start))return false;uint64_t end=start+10+body,dir=start+12+2*nc,data=0,stride=0;for(unsigned z=6;z<=8;z+=2){uint64_t begin=dir+sc*z,prev=0;bool valid=begin<end;for(uint64_t i=0;valid&&i<sc;i++){uint64_t lines=0,off=0;if(!sxaend_word(c,dir+i*z+(z==8?2:0),2,false,&lines)||!sxaend_word(c,dir+i*z+(z==8?4:2),4,false,&off)||!lines||off>=end-begin||(i&&off<=prev))valid=false;prev=off;}if(valid){if(stride)return false;stride=z;data=begin;}}if(!stride)return false;for(uint64_t i=0;i<nc;i++){uint64_t v;if(!sxaend_word(c,start+12+i*2,1,false,&v)||!sxaend_add(c,v?&sxaend_copyqm_tx_branch:&sxaend_copyqm_tx_leaf,start+12+i*2))return false;}for(uint64_t i=0;i<sc;i++){uint64_t row=dir+i*stride,n,off,limit=end;if(!sxaend_add(c,stride==6?&sxaend_copyqm_tx_screen6:&sxaend_copyqm_tx_screen8,row)||!sxaend_word(c,row+(stride==8?2:0),2,false,&n)||!sxaend_word(c,row+(stride==8?4:2),4,false,&off))return false;if(i==0&&off==6&&!sxaend_add(c,&sxaend_copyqm_tx_geometry,data))return false;if(i+1<sc){uint64_t q;if(!sxaend_word(c,row+stride+(stride==8?4:2),4,false,&q))return false;limit=data+q;}uint64_t p=data+off;for(uint64_t j=0;j<n&&j<SXAEND_LIMIT;j++){uint64_t z;if(p>=limit||!sxaend_word(c,p,1,false,&z)||z<2||z>limit-p||!sxaend_add(c,&sxaend_copyqm_tx_line,p))return false;p+=z;}}return true;}
bool sx_copyqmexe_build(sx_context*c)
{
 return sxaend_copyqm(c);
}
