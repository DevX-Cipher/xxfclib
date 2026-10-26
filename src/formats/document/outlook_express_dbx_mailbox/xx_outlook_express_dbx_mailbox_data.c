/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Outlook Express 5/6 DBX message store data structures, moved out of the docmeta schema family. */
#include "../../xx_format_schema_docmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdm_dbx_header_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("class_guid","bytes",4,16,SX_ID),
 SX_FIELD("unknown1","bytes",20,176,SX_NONE),
 SX_FIELD("message_count","uint32",196,4,SX_COUNT_PROP),
 SX_FIELD("unknown2","bytes",200,28,SX_NONE),
 SX_FIELD("root_offset","uint32",228,4,SX_OFFSET),
 SX_FIELD("unknown3","bytes",232,9172,SX_NONE),
};
const sx_layout sxdm_dbx_header={UINT32_C(0x60230041),"dbx_header",sxdm_dbx_header_fields,SX_COUNT(sxdm_dbx_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_dbx_node_header_fields[]={
 SX_FIELD("self_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("unknown1","uint32",4,4,SX_NONE),
 SX_FIELD("left_child_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("parent_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("unknown2","uint8",16,1,SX_NONE),
 SX_FIELD("entry_count","uint8",17,1,SX_COUNT_PROP),
 SX_FIELD("unknown3","bytes",18,2,SX_NONE),
 SX_FIELD("left_subtree_count","uint32",20,4,SX_COUNT_PROP),
};
const sx_layout sxdm_dbx_node_header={UINT32_C(0x60230042),"dbx_node_header",sxdm_dbx_node_header_fields,SX_COUNT(sxdm_dbx_node_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_dbx_node_entry_fields[]={
 SX_FIELD("info_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("right_child_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("right_subtree_count","uint32",8,4,SX_COUNT_PROP),
};
const sx_layout sxdm_dbx_node_entry={UINT32_C(0x60230043),"dbx_node_entry",sxdm_dbx_node_entry_fields,SX_COUNT(sxdm_dbx_node_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_dbx_info_header_fields[]={
 SX_FIELD("self_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("body_size","uint32",4,4,SX_SIZE),
 SX_FIELD("unknown1","uint16",8,2,SX_NONE),
 SX_FIELD("attribute_count","uint8",10,1,SX_COUNT_PROP),
 SX_FIELD("unknown2","uint8",11,1,SX_NONE),
};
const sx_layout sxdm_dbx_info_header={UINT32_C(0x60230044),"dbx_info_header",sxdm_dbx_info_header_fields,SX_COUNT(sxdm_dbx_info_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_dbx_attribute_fields[]={
 SX_FIELD("id_and_direct_flag","uint8",0,1,SX_FLAGS),
 SX_FIELD("direct_value","uint24",1,3,SX_NONE),
};
const sx_layout sxdm_dbx_attribute={UINT32_C(0x60230045),"dbx_attribute",sxdm_dbx_attribute_fields,SX_COUNT(sxdm_dbx_attribute_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_dbx_attribute_indirect_fields[]={
 SX_FIELD("id_and_direct_flag","uint8",0,1,SX_FLAGS),
 SX_FIELD("data_offset","uint24",1,3,SX_OFFSET),
};
const sx_layout sxdm_dbx_attribute_indirect={UINT32_C(0x60230046),"dbx_attribute_indirect",sxdm_dbx_attribute_indirect_fields,SX_COUNT(sxdm_dbx_attribute_indirect_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_dbx_attribute_message_fields[]={
 SX_FIELD("id_and_direct_flag","uint8",0,1,SX_FLAGS),
 SX_FIELD("first_block_offset","uint24",1,3,SX_OFFSET),
};
const sx_layout sxdm_dbx_attribute_message={UINT32_C(0x60230047),"dbx_attribute_message",sxdm_dbx_attribute_message_fields,SX_COUNT(sxdm_dbx_attribute_message_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_dbx_message_pointer_fields[]={
 SX_FIELD("first_block_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxdm_dbx_message_pointer={UINT32_C(0x60230048),"dbx_message_pointer",sxdm_dbx_message_pointer_fields,SX_COUNT(sxdm_dbx_message_pointer_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_dbx_block_header_fields[]={
 SX_FIELD("self_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("allocated_body_size","uint32",4,4,SX_SIZE),
 SX_FIELD("used_body_size","uint32",8,4,SX_SIZE),
 SX_FIELD("next_block_offset","uint32",12,4,SX_OFFSET),
};
const sx_layout sxdm_dbx_block_header={UINT32_C(0x60230049),"dbx_block_header",sxdm_dbx_block_header_fields,SX_COUNT(sxdm_dbx_block_header_fields),SX_LE};
/* DBX intentionally accepts damaged subtrees. Only complete, self-identifying
 * nodes/objects/blocks are classified; damaged links remain raw. A single
 * finite queue tracks ownership and stops cycles/shared targets. */
typedef struct sxdm_dbx_job{uint32_t at,parent;unsigned kind,depth;}sxdm_dbx_job;
static bool sxdm_dbx_push(sxdm_dbx_job *q,uint32_t *seen,size_t *n,uint32_t at,uint32_t parent,unsigned kind,unsigned depth)
{
 if(!at||depth>64)return true;size_t slot=((uint32_t)(at*UINT32_C(2654435761)))&131071;while(seen[slot]){if(seen[slot]==at)return true;slot=(slot+1)&131071;}if(*n>=65536)return false;seen[slot]=at;q[(*n)++]=(sxdm_dbx_job){at,parent,kind,depth};return true;
}
static bool sxdm_dbx(sx_context *c)
{
 uint8_t b[636];uint32_t root;size_t count=0;bool ok=false;sxdm_dbx_job *queue=NULL;uint32_t *seen=NULL;
 if(!sxdm_add(c,&sxdm_dbx_header,0,9404)||!sx_u32(c,228,false,&root))return false;queue=xx_mem_alloc(65536*sizeof(*queue));seen=xx_mem_calloc(131072,sizeof(*seen));if(!queue||!seen)goto done;if(!sxdm_dbx_push(queue,seen,&count,root,0,0,0))goto done;
 for(size_t i=0;i<count;i++){
  sxdm_dbx_job j=queue[i];uint32_t at=j.at;if(xx_pd_is_stopped(c->pd))goto done;if(at<9404)continue;
  if(j.kind==0){
   if(!sxdm_span(c,at,24)||!sx_read(c,at,b,24)||sxdm_u32(b)!=at||(j.parent&&sxdm_u32(b+12)!=j.parent)||b[17]>51||!sxdm_span(c,(int64_t)at+24,(uint64_t)b[17]*12))continue;
   unsigned n=b[17];uint32_t left=sxdm_u32(b+8);if(!sxdm_add(c,&sxdm_dbx_node_header,at,24)||!sxdm_dbx_push(queue,seen,&count,left,at,0,j.depth+1))goto done;
   for(unsigned k=0;k<n;k++){int64_t pos=(int64_t)at+24+k*12;if(!sx_read(c,pos,b,12)||!sxdm_add(c,&sxdm_dbx_node_entry,pos,12)||!sxdm_dbx_push(queue,seen,&count,sxdm_u32(b),0,1,0)||!sxdm_dbx_push(queue,seen,&count,sxdm_u32(b+4),at,0,j.depth+1))goto done;}
  }else if(j.kind==1){
   if(!sxdm_span(c,at,12)||!sx_read(c,at,b,12)||sxdm_u32(b)!=at)continue;uint32_t body=sxdm_u32(b+4);unsigned n=b[10];if(n*4>body||!sxdm_span(c,(int64_t)at+12,body))continue;
   if(!sxdm_add(c,&sxdm_dbx_info_header,at,12))goto done;bool found=false;
   for(unsigned k=0;k<n;k++){int64_t pos=(int64_t)at+12+k*4;if(!sx_read(c,pos,b,4))goto done;const sx_layout *al=!(b[0]&128)?&sxdm_dbx_attribute_indirect:(b[0]&127)==4?&sxdm_dbx_attribute_message:&sxdm_dbx_attribute;if(!sxdm_add(c,al,pos,4))goto done;uint32_t v=sxdm_u32(b)>>8;if((b[0]&127)!=4||found)continue;found=true;
    if(!(b[0]&128)){uint64_t rel=(uint64_t)n*4+v;if(rel+4>body)continue;pos=(int64_t)at+12+(int64_t)rel;if(!sx_u32(c,pos,false,&v)||!sxdm_add(c,&sxdm_dbx_message_pointer,pos,4))goto done;}
    if(!sxdm_dbx_push(queue,seen,&count,v,0,2,0))goto done;
   }
  }else{
   if(!sxdm_span(c,at,16)||!sx_read(c,at,b,16)||sxdm_u32(b)!=at)continue;uint32_t allocated=sxdm_u32(b+4),used=sxdm_u32(b+8);if(!allocated||allocated>1048576||used>allocated||!sxdm_span(c,(int64_t)at+16,used))continue;
   if(!sxdm_add(c,&sxdm_dbx_block_header,at,16)||!sxdm_dbx_push(queue,seen,&count,sxdm_u32(b+12),0,2,0))goto done;
  }
 }ok=true;
done:xx_mem_free(queue);xx_mem_free(seen);return ok;
}
bool sx_outlook_express_dbx_mailbox_build(sx_context*c)
{
 return sxdm_dbx(c);
}
