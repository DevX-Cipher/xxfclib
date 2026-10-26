/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * InstallShield skin data structures, moved out of the installerlast schema family. */
#include "../../xx_format_schema_installerlast.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxil_installshield_skin_encoded_name_fields[] = {
    SX_FIELD("encoded_name","uint8",0,0,SX_NONE),
};
const sx_layout sxil_installshield_skin_encoded_name = {0x60850030U,"installshield_skin_encoded_name",sxil_installshield_skin_encoded_name_fields,SX_COUNT(sxil_installshield_skin_encoded_name_fields),SX_LE};
static const xx_data_struct_field_desc sxil_installshield_skin_encoded_size_fields[] = {
    SX_FIELD("encoded_size","uint8",0,0,SX_NONE),
};
const sx_layout sxil_installshield_skin_encoded_size = {0x60850031U,"installshield_skin_encoded_size",sxil_installshield_skin_encoded_size_fields,SX_COUNT(sxil_installshield_skin_encoded_size_fields),SX_LE};
static bool sxil_skin(sx_context*c,sxil_records*r){static const uint8_t key[8]={0xa2,0x85,0x59,0xbc,0xa3,0x9f,0x3b,0xac};for(size_t i=0;i<r->count;i++){sxil_member*m=r->items+i;if(m->header_size>281)continue;uint8_t b[281];if(!sxil_read(c,m->header,b,(size_t)m->header_size))continue;for(uint64_t k=0;k<m->header_size;k++)b[k]=(uint8_t)((b[k]>>4)|(b[k]<<4))^key[(m->header+k)&7];uint64_t n=0;while(n<m->header_size&&b[n])n++;if(n>=m->header_size)continue;n++;if(!sxil_text(c,&sxil_installshield_skin_encoded_name,m->header,n)||!sxil_text(c,&sxil_installshield_skin_encoded_size,m->header+n,m->header_size-n))return false;}return true;}
bool sx_installshield_skin_build(sx_context*c,sxil_records records)
{
 return sxil_skin(c,&records);
}
