/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ARNI installer container data structures, moved out of the installerlast schema family. */
#include "../../xx_format_schema_installerlast.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxil_arni_member_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("unpacked_size","int32",4,4,SX_SIZE),
};
const sx_layout sxil_arni_member = {0x6085000eU,"arni_member",sxil_arni_member_fields,SX_COUNT(sxil_arni_member_fields),SX_LE};
static const xx_data_struct_field_desc sxil_arni_end_fields[] = {
    SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("terminator","byte[2]",8,2,SX_NONE),
};
const sx_layout sxil_arni_end = {0x6085000fU,"arni_end",sxil_arni_end_fields,SX_COUNT(sxil_arni_end_fields),SX_LE};
#define SXIL_ADD(c,n,p) sxil_put(c,&sxil_##n,p,1)
static bool sxil_arni(sx_context*c,sxil_records*r){
 for(size_t i=0;i<r->count;i++){sxil_member*m=r->items+i;if(m->header_size!=8||!sxil_eq(c,m->header,"ARNI",4))continue;if(!SXIL_ADD(c,arni_member,m->header))return false;uint64_t e=m->data+m->packed;if(sxil_eq(c,e,"ARNIARNI\r\n",10)&&!SXIL_ADD(c,arni_end,e))return false;}return true;
}
bool sx_arni_installer_container_build(sx_context*c,sxil_records records)
{
 return sxil_arni(c,&records);
}
#undef SXIL_ADD
