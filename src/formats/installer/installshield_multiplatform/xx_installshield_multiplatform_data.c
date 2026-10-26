/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * InstallShield MultiPlatform data structures, moved out of the installerlast schema family. */
#include "../../xx_format_schema_installerlast.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxil_installshield_multiplatform_footer_fields[] = {
    SX_FIELD("index_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("signature","uint32",4,4,SX_SIGNATURE),
};
const sx_layout sxil_installshield_multiplatform_footer = {0x6085002bU,"installshield_multiplatform_footer",sxil_installshield_multiplatform_footer_fields,SX_COUNT(sxil_installshield_multiplatform_footer_fields),SX_BE};
static const xx_data_struct_field_desc sxil_installshield_multiplatform_count_fields[] = {
    SX_FIELD("resource_count","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxil_installshield_multiplatform_count = {0x6085002cU,"installshield_multiplatform_count",sxil_installshield_multiplatform_count_fields,SX_COUNT(sxil_installshield_multiplatform_count_fields),SX_BE};
static const xx_data_struct_field_desc sxil_installshield_multiplatform_record_fields[] = {
    SX_FIELD("resource_type","uint8",0,1,SX_ID),
    SX_FIELD("resource_id","uint32",1,4,SX_ID),
    SX_FIELD("file_size","uint32",5,4,SX_SIZE),
    SX_FIELD("file_offset","uint32",9,4,SX_OFFSET),
    SX_FIELD("name_size","uint16",13,2,SX_SIZE),
};
const sx_layout sxil_installshield_multiplatform_record = {0x6085002dU,"installshield_multiplatform_record",sxil_installshield_multiplatform_record_fields,SX_COUNT(sxil_installshield_multiplatform_record_fields),SX_BE};
static const xx_data_struct_field_desc sxil_installshield_multiplatform_optional_fields[] = {
    SX_FIELD("has_u64","uint8",0,1,SX_FLAGS),
};
const sx_layout sxil_installshield_multiplatform_optional = {0x6085002eU,"installshield_multiplatform_optional",sxil_installshield_multiplatform_optional_fields,SX_COUNT(sxil_installshield_multiplatform_optional_fields),SX_LE};
static const xx_data_struct_field_desc sxil_installshield_multiplatform_u64_fields[] = {
    SX_FIELD("bundled_jvm_value","uint64",0,8,SX_NONE),
};
const sx_layout sxil_installshield_multiplatform_u64 = {0x6085002fU,"installshield_multiplatform_u64",sxil_installshield_multiplatform_u64_fields,SX_COUNT(sxil_installshield_multiplatform_u64_fields),SX_BE};
#define SXIL_ADD(c,n,p) sxil_put(c,&sxil_##n,p,1)
static bool sxil_u32be(sx_context*c,uint64_t p,uint32_t*v){uint8_t b[4];if(!sxil_read(c,p,b,4))return false;*v=sxil32(b,true);return true;}
static bool sxil_ismp(sx_context*c){if(c->size<12)return true;uint64_t tr=(uint64_t)c->size-8;uint32_t p,n;if(!sxil_eq(c,tr+4,"\xca\x82\xca\x82",4)||!sxil_u32be(c,tr,&p)||p>tr||tr-p<4)return true;
 if(!SXIL_ADD(c,installshield_multiplatform_footer,tr)||!sxil_u32be(c,p,&n)||!SXIL_ADD(c,installshield_multiplatform_count,p))return false;
 uint64_t q=(uint64_t)p+4;for(uint32_t i=0;i<n&&i<100000&&q<=tr&&15<=tr-q;i++){uint8_t b[15],flag;if(!sxil_read(c,q,b,15))return true;uint64_t z=sxil16(b+13,true);if(z>tr-q-15)return true;if(!SXIL_ADD(c,installshield_multiplatform_record,q)||!sxil_name(c,q+15,z))return false;q+=15+z;if(!sxil_read(c,q,&flag,1)||flag>1)return true;if(!SXIL_ADD(c,installshield_multiplatform_optional,q))return false;q++;if(flag){if(q>tr||8>tr-q)return true;if(!SXIL_ADD(c,installshield_multiplatform_u64,q))return false;q+=8;}}return true;}
bool sx_installshield_multiplatform_build(sx_context*c)
{
 return sxil_ismp(c);
}
#undef SXIL_ADD
