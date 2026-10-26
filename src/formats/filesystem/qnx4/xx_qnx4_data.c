/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * QNX4 data structures, moved out of the classicfs schema family. */
#include "../../xx_format_schema_classicfs.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxcf_qnx4_extent_block_header_fields[] = {
    SX_FIELD("next_block","uint32",0,4,SX_NONE),
    SX_FIELD("previous_block","uint32",4,4,SX_NONE),
    SX_FIELD("extent_count","uint8",8,1,SX_COUNT_PROP),
    SX_FIELD("reserved","byte[3]",9,3,SX_RESERVED),
    SX_FIELD("block_count","uint32",12,4,SX_COUNT_PROP),
};
const sx_layout sxcf_qnx4_extent_block_header = {0x603d002fU,"qnx4_extent_block_header",sxcf_qnx4_extent_block_header_fields,SX_COUNT(sxcf_qnx4_extent_block_header_fields),SX_LE};
static const xx_data_struct_field_desc sxcf_qnx4_extent_fields[] = {
    SX_FIELD("first_block","uint32",0,4,SX_NONE),
    SX_FIELD("block_count","uint32",4,4,SX_COUNT_PROP),
};
const sx_layout sxcf_qnx4_extent = {0x603d0030U,"qnx4_extent",sxcf_qnx4_extent_fields,SX_COUNT(sxcf_qnx4_extent_fields),SX_LE};
static const xx_data_struct_field_desc sxcf_qnx4_extent_block_tail_fields[] = {
    SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("first_block","uint32",8,4,SX_NONE),
    SX_FIELD("block_count","uint32",12,4,SX_COUNT_PROP),
};
const sx_layout sxcf_qnx4_extent_block_tail = {0x603d0031U,"qnx4_extent_block_tail",sxcf_qnx4_extent_block_tail_fields,SX_COUNT(sxcf_qnx4_extent_block_tail_fields),SX_LE};
#define SXCF_LIMIT 24000U
#define SXCF_ADD(c,l,p) sxcf_put(c,&sxcf_##l,p,1)
#define SXCF_TABLE(c,l,p,n) sxcf_put(c,&sxcf_##l,p,n)
static bool sxcf_qnx_inode(sx_context*c,uint64_t at,uint64_t blocks,unsigned depth,unsigned*visits);
static bool sxcf_qnx_extent(sx_context*c,uint32_t block,uint32_t count,uint64_t*left,bool dir,uint64_t blocks,unsigned depth,unsigned*visits){
 if(!*left)return true;if(!block||block-1>=blocks||count>blocks-(block-1))return false;uint64_t p=(uint64_t)(block-1)*512,n=(uint64_t)count*512;if(n>*left)n=*left;
 if(dir){for(uint64_t q=0;q+64<=n&&*visits<4096&&c->count<SXCF_LIMIT;q+=64){uint8_t b[64];if(!sxcf_read(c,p+q,b,64))return false;if(!(b[63]&9))continue;
  if((b[0]=='.'&&!b[1])||(b[0]=='.'&&b[1]=='.'&&!b[2]))continue;
  if(b[63]&8){if(!SXCF_ADD(c,qnx4_link,p+q))return false;uint32_t nr=sxcf32(b+48,0);if(nr&&nr<=blocks&&b[52]<8&&!sxcf_qnx_inode(c,(uint64_t)(nr-1)*512+(uint64_t)b[52]*64,blocks,depth+1,visits))return false;}
  else if(!sxcf_qnx_inode(c,p+q,blocks,depth+1,visits))return false;
 }}*left-=n;return true;
}
static bool sxcf_qnx_inode(sx_context*c,uint64_t at,uint64_t blocks,unsigned depth,unsigned*visits){
 uint8_t b[512];if(depth>24||++*visits>4096||c->count>=SXCF_LIMIT)return true;if(!sxcf_read(c,at,b,64))return false;if(!(b[63]&1))return true;
 if(!SXCF_ADD(c,qnx4_inode,at))return false;uint64_t left=sxcf32(b+16,0);bool dir=(sxcf16(b+50,0)&0xf000)==0x4000;uint32_t next=sxcf32(b+28,0);
 if(!sxcf_qnx_extent(c,sxcf32(b+20,0),sxcf32(b+24,0),&left,dir,blocks,depth,visits))return true;
 for(unsigned k=0;left&&next&&k<4096&&c->count<SXCF_LIMIT;k++){
  if(next>blocks||!sxcf_read(c,(uint64_t)(next-1)*512,b,512)||b[8]>60)break;uint64_t p=(uint64_t)(next-1)*512;uint32_t following=sxcf32(b,0);
  if(!SXCF_ADD(c,qnx4_extent_block_header,p)||!SXCF_TABLE(c,qnx4_extent,p+16,60)||!SXCF_ADD(c,qnx4_extent_block_tail,p+496))return false;
  for(unsigned i=0;i<b[8]&&left;i++)if(!sxcf_qnx_extent(c,sxcf32(b+16+8*i,0),sxcf32(b+20+8*i,0),&left,dir,blocks,depth,visits))return true;
  if(following==next)break;next=following;
 }return true;
}
static bool sxcf_qnx(sx_context*c){uint8_t b[256];if(!sxcf_read(c,512,b,256)||b[0]!='/'||b[1]||(sxcf16(b+50,0)&0xf000)!=0x4000)return false;if(!SXCF_TABLE(c,qnx4_inode,512,4))return false;unsigned visits=0;return sxcf_qnx_inode(c,512,(uint64_t)c->size/512,0,&visits);}
bool sx_qnx4_build(sx_context*c)
{
 return sxcf_qnx(c);
}
