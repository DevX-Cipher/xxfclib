/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * sfx_jgsoft_deploymaster_package data structures, moved out of the installerextras schema family. */
#include "../../xx_format_schema_installerextras.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxiex_deploymaster_record_fields[] = {
    SX_FIELD("compressed_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxiex_deploymaster_record = {0x60820022U,"deploymaster_record",sxiex_deploymaster_record_fields,SX_COUNT(sxiex_deploymaster_record_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_deploymaster_separator_fields[] = {
    SX_FIELD("marker","uint32",0,4,SX_SIGNATURE),
};
const sx_layout sxiex_deploymaster_separator = {0x60820023U,"deploymaster_separator",sxiex_deploymaster_separator_fields,SX_COUNT(sxiex_deploymaster_separator_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_deploymaster_bzip2_fields[] = {
    SX_FIELD("signature","char[3]",0,3,SX_SIGNATURE),
    SX_FIELD("block_size_digit","uint8",3,1,SX_ID),
};
const sx_layout sxiex_deploymaster_bzip2 = {0x60820024U,"deploymaster_bzip2",sxiex_deploymaster_bzip2_fields,SX_COUNT(sxiex_deploymaster_bzip2_fields),SX_LE};
#define SXIEX_ADD(c,n,p) sxiex_put(c,&sxiex_##n,p,1)
static bool sxiex_deploy(sx_context*c,const sxiex_records*r){
 for(size_t i=0;i<r->count;i++){const sxiex_member*m=r->items+i;
 if(m->header_size==4){uint32_t z;if(sxiex_u32(c,m->header,&z)&&z==m->packed&&!SXIEX_ADD(c,deploymaster_record,m->header))return false;}
 if(m->header_size==0&&m->packed>=4&&sxiex_eq(c,m->data,"BZh",3)){if(!SXIEX_ADD(c,deploymaster_bzip2,m->data))return false;uint64_t end=m->data+m->packed;if(sxiex_eq(c,end,"\xff\xff\xff\xff",4)){if(!SXIEX_ADD(c,deploymaster_separator,end))return false;uint64_t q=end+4;for(unsigned j=0;j<2;j++){uint32_t z;if(!sxiex_u32(c,q,&z)||!sxiex_span(c,q+4,z))break;if(!SXIEX_ADD(c,deploymaster_record,q))return false;q+=4+z;}}}}
 return true;
}
bool sx_sfx_jgsoft_deploymaster_package_build(sx_context*c,const sxiex_records*records)
{
 return sxiex_deploy(c,records);
}
#undef SXIEX_ADD
