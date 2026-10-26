/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ARDI OS/2 installer data structures, moved out of the installerlast schema family. */
#include "../../xx_format_schema_installerlast.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxil_ardi_trailer_fields[] = {
    SX_FIELD("copyright","char[25]",0,25,SX_NONE),
    SX_FIELD("builder_check","uint32",25,4,SX_NONE),
    SX_FIELD("builder_counter","uint16",29,2,SX_NONE),
    SX_FIELD("copyright_suffix","char[14]",31,14,SX_NONE),
    SX_FIELD("year","char[4]",45,4,SX_NONE),
    SX_FIELD("terminator","char[1]",49,1,SX_NONE),
};
const sx_layout sxil_ardi_trailer = {0x60850009U,"ardi_trailer",sxil_ardi_trailer_fields,SX_COUNT(sxil_ardi_trailer_fields),SX_LE};
static const xx_data_struct_field_desc sxil_ardi_block_tag_fields[] = {
    SX_FIELD("tag","uint32",0,4,SX_ID),
};
const sx_layout sxil_ardi_block_tag = {0x6085000aU,"ardi_block_tag",sxil_ardi_block_tag_fields,SX_COUNT(sxil_ardi_block_tag_fields),SX_LE};
static const xx_data_struct_field_desc sxil_ardi_block_length_fields[] = {
    SX_FIELD("block_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxil_ardi_block_length = {0x6085000bU,"ardi_block_length",sxil_ardi_block_length_fields,SX_COUNT(sxil_ardi_block_length_fields),SX_LE};
static const xx_data_struct_field_desc sxil_ardi_member_time_fields[] = {
    SX_FIELD("modification_time","uint32",0,4,SX_TIME),
};
const sx_layout sxil_ardi_member_time = {0x6085000cU,"ardi_member_time",sxil_ardi_member_time_fields,SX_COUNT(sxil_ardi_member_time_fields),SX_LE};
static const xx_data_struct_field_desc sxil_ardi_chain_start_fields[] = {
    SX_FIELD("sentinel","uint32",0,4,SX_SIGNATURE),
};
const sx_layout sxil_ardi_chain_start = {0x6085000dU,"ardi_chain_start",sxil_ardi_chain_start_fields,SX_COUNT(sxil_ardi_chain_start_fields),SX_LE};
#define SXIL_ADD(c,n,p) sxil_put(c,&sxil_##n,p,1)
static bool sxil_ardi(sx_context*c){
 if(c->size<54)return true;uint64_t end=(uint64_t)c->size-50;if(!SXIL_ADD(c,ardi_trailer,end))return false;
 for(size_t k=0;k<100000&&end>=4;k++){
  uint32_t n;if(!sxil_u32(c,end-4,&n))return true;if(n==0x98765432U)return SXIL_ADD(c,ardi_chain_start,end-4);
  if(n<8||n>end)return true;uint64_t p=end-n;uint32_t tag;if(!sxil_u32(c,p,&tag))return true;
  if(!SXIL_ADD(c,ardi_block_tag,p)||!SXIL_ADD(c,ardi_block_length,end-4))return false;
  if(tag==0x12345677U&&n>=14){if(!SXIL_ADD(c,ardi_member_time,p+4)||!sxil_name(c,p+8,n-12))return false;}
  else if(tag==0x11221122U||tag==0x97979797U||tag==0x12121212U||tag==0x13131313U){if(!sxil_name(c,p+4,n-8))return false;}
  end=p;
 }return true;
}
bool sx_ardi_installer_build(sx_context*c)
{
 return sxil_ardi(c);
}
#undef SXIL_ADD
