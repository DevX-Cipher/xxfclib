/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Windows Help (HLP) data structures, moved out of the docmeta schema family. */
#include "../../xx_format_schema_docmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdm_winhelp_header_fields[]={
 SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("directory_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("free_chain_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("file_size","uint32",12,4,SX_SIZE),
};
const sx_layout sxdm_winhelp_header={UINT32_C(0x60230015),"winhelp_header",sxdm_winhelp_header_fields,SX_COUNT(sxdm_winhelp_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_winhelp_internal_file_header_fields[]={
 SX_FIELD("allocated_size","uint32",0,4,SX_SIZE),
 SX_FIELD("used_size","uint32",4,4,SX_SIZE),
 SX_FIELD("flags","uint8",8,1,SX_FLAGS),
};
const sx_layout sxdm_winhelp_internal_file_header={UINT32_C(0x60230016),"winhelp_internal_file_header",sxdm_winhelp_internal_file_header_fields,SX_COUNT(sxdm_winhelp_internal_file_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_winhelp_btree_header_fields[]={
 SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("flags","uint16",2,2,SX_FLAGS),
 SX_FIELD("page_size","uint16",4,2,SX_SIZE),
 SX_FIELD("data_format","char[16]",6,16,SX_NONE),
 SX_FIELD("unknown1","uint16",22,2,SX_NONE),
 SX_FIELD("page_split","uint16",24,2,SX_NONE),
 SX_FIELD("root_page","uint16",26,2,SX_ID),
 SX_FIELD("unknown2","uint16",28,2,SX_NONE),
 SX_FIELD("page_count","uint16",30,2,SX_COUNT_PROP),
 SX_FIELD("level_count","uint16",32,2,SX_COUNT_PROP),
 SX_FIELD("entry_count","uint32",34,4,SX_COUNT_PROP),
};
const sx_layout sxdm_winhelp_btree_header={UINT32_C(0x60230017),"winhelp_btree_header",sxdm_winhelp_btree_header_fields,SX_COUNT(sxdm_winhelp_btree_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_winhelp_index_header_fields[]={
 SX_FIELD("unused_size","uint16",0,2,SX_SIZE),
 SX_FIELD("entry_count","uint16",2,2,SX_COUNT_PROP),
 SX_FIELD("first_child","uint16",4,2,SX_ID),
};
const sx_layout sxdm_winhelp_index_header={UINT32_C(0x60230018),"winhelp_index_header",sxdm_winhelp_index_header_fields,SX_COUNT(sxdm_winhelp_index_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_winhelp_leaf_header_fields[]={
 SX_FIELD("unused_size","uint16",0,2,SX_SIZE),
 SX_FIELD("entry_count","uint16",2,2,SX_COUNT_PROP),
 SX_FIELD("previous_page","uint16",4,2,SX_ID),
 SX_FIELD("next_page","uint16",6,2,SX_ID),
};
const sx_layout sxdm_winhelp_leaf_header={UINT32_C(0x60230019),"winhelp_leaf_header",sxdm_winhelp_leaf_header_fields,SX_COUNT(sxdm_winhelp_leaf_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_winhelp_file_pointer_fields[]={
 SX_FIELD("file_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxdm_winhelp_file_pointer={UINT32_C(0x6023001A),"winhelp_file_pointer",sxdm_winhelp_file_pointer_fields,SX_COUNT(sxdm_winhelp_file_pointer_fields),SX_LE};
/* Walk native WinHelp root-to-first-leaf path and leaf chain. Other index
 * branches are not traversed by the native reader and remain raw. */
static bool sxdm_hlp(sx_context *c)
{
 uint8_t b[38];uint32_t dir;if(!sx_u32(c,4,false,&dir)||!sxdm_add(c,&sxdm_winhelp_header,0,16)||!sxdm_add(c,&sxdm_winhelp_internal_file_header,dir,9)||!sx_read(c,dir+9,b,38)||!sxdm_add(c,&sxdm_winhelp_btree_header,dir+9,38))return false;
 uint16_t page=sxdm_u16(b+4),count=sxdm_u16(b+30),levels=sxdm_u16(b+32),cur=sxdm_u16(b+26);int64_t pages=(int64_t)dir+47;uint8_t *seen=NULL;bool ok=false;
 if(page<64||!count||levels<1||levels>64||!sxdm_span(c,pages,(uint64_t)page*count))return false;seen=xx_mem_calloc(count,1);if(!seen)return false;
 for(unsigned i=1;i<levels;i++){if(cur>=count||seen[cur])goto done;seen[cur]=1;int64_t at=pages+(int64_t)cur*page;if(!sx_read(c,at,b,6)||!sxdm_add(c,&sxdm_winhelp_index_header,at,6))goto done;cur=sxdm_u16(b+4);}
 for(unsigned i=0;cur!=65535;i++){
  if(i>=count||cur>=count||seen[cur])goto done;seen[cur]=1;int64_t start=pages+(int64_t)cur*page,at=start+8;
  if(!sx_read(c,start,b,8)||!sxdm_add(c,&sxdm_winhelp_leaf_header,start,8))goto done;uint16_t unused=sxdm_u16(b),entries=sxdm_u16(b+2),next=sxdm_u16(b+6);if(unused>page-8)goto done;int64_t end=start+page-unused;
  for(unsigned j=0;j<entries;j++){
   uint32_t off,alloc,used;if(!sxdm_zero(c,&at,end,256)||end-at<4||!sx_u32(c,at,false,&off)||!sxdm_add(c,&sxdm_winhelp_file_pointer,at,4))goto done;at+=4;
   if(!sx_u32(c,off,false,&alloc)||!sx_u32(c,(int64_t)off+4,false,&used)||alloc<9||used>alloc-9||!sxdm_span(c,off,alloc)||!sxdm_add(c,&sxdm_winhelp_internal_file_header,off,9))goto done;
  }if(at!=end)goto done;cur=next;
 }ok=true;
done:xx_mem_free(seen);return ok;
}
bool sx_ue2_documents_build(sx_context*c)
{
 return sxdm_hlp(c);
}
