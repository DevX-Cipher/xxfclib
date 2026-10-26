/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * sfx_analogx_emucore_ffs data structures, moved out of the installerextras schema family. */
#include "../../xx_format_schema_installerextras.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxiex_ffs_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("file_count","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("complemented_file_count","uint32",8,4,SX_NONE),
    SX_FIELD("flags","uint32",12,4,SX_FLAGS),
};
const sx_layout sxiex_ffs_header = {0x60820006U,"ffs_header",sxiex_ffs_header_fields,SX_COUNT(sxiex_ffs_header_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_ffs_index_fields[] = {
    SX_FIELD("filename_crc32","uint32",0,4,SX_CHECKSUM),
    SX_FIELD("record_offset","uint32",4,4,SX_OFFSET),
};
const sx_layout sxiex_ffs_index = {0x60820007U,"ffs_index",sxiex_ffs_index_fields,SX_COUNT(sxiex_ffs_index_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_ffs_member_fields[] = {
    SX_FIELD("filename_crc32","uint32",0,4,SX_CHECKSUM),
    SX_FIELD("payload_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxiex_ffs_member = {0x60820008U,"ffs_member",sxiex_ffs_member_fields,SX_COUNT(sxiex_ffs_member_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_ffs_cmp1_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("encoded_unpacked_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxiex_ffs_cmp1 = {0x60820009U,"ffs_cmp1",sxiex_ffs_cmp1_fields,SX_COUNT(sxiex_ffs_cmp1_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_ffs_cmp2_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("encoded_unpacked_size","uint32",4,4,SX_NONE),
};
const sx_layout sxiex_ffs_cmp2 = {0x6082000aU,"ffs_cmp2",sxiex_ffs_cmp2_fields,SX_COUNT(sxiex_ffs_cmp2_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_ffs_footer_fields[] = {
    SX_FIELD("archive_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxiex_ffs_footer = {0x6082000bU,"ffs_footer",sxiex_ffs_footer_fields,SX_COUNT(sxiex_ffs_footer_fields),SX_LE};
#define SXIEX_ADD(c,n,p) sxiex_put(c,&sxiex_##n,p,1)
static bool sxiex_ffs(sx_context*c,const sxiex_records*r){
 uint64_t p=0;uint8_t h[16];uint32_t tail;
 if(!sxiex_eq(c,0,"FFS!",4)){if(c->size<4||!sxiex_u32(c,(uint64_t)c->size-4,&tail))return true;p=tail;if(!sxiex_eq(c,p,"FFS!",4))return true;if(!SXIEX_ADD(c,ffs_footer,(uint64_t)c->size-4))return false;}
 if(!sxiex_read(c,p,h,16))return true;uint32_t n=sxiex32(h+4,false);if(n!=~sxiex32(h+8,false)||!sxiex_span(c,p+16,(uint64_t)n*8))return true;
 if(!SXIEX_ADD(c,ffs_header,p)||!sxiex_put(c,&sxiex_ffs_index,p+16,n))return false;
 for(size_t i=0;i<r->count;i++){const sxiex_member*m=r->items+i;if(m->header_size==8&&!SXIEX_ADD(c,ffs_member,m->header))return false;if(m->packed>=8){if(sxiex_eq(c,m->data,"FFC!",4)){if(!SXIEX_ADD(c,ffs_cmp1,m->data))return false;}else if(sxiex_eq(c,m->data,"FFC@",4)&&!SXIEX_ADD(c,ffs_cmp2,m->data))return false;}}
 return true;
}
bool sx_sfx_analogx_emucore_ffs_build(sx_context*c,const sxiex_records*records)
{
 return sxiex_ffs(c,records);
}
#undef SXIEX_ADD
