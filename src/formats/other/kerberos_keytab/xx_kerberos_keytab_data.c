/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * kerberos keytab data structures, moved out of the binaryextra schema family. */
#include "../../xx_format_schema_binaryextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxbx_keytab_header_fields[] = {
 SX_FIELD("major","uint8",0,1,SX_NONE),
 SX_FIELD("minor","uint8",1,1,SX_NONE),
};
const sx_layout sxbx_keytab_header = {UINT32_C(0x60300074),"keytab_header",sxbx_keytab_header_fields,SX_COUNT(sxbx_keytab_header_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_keytab_entry_length_fields[] = {
 SX_FIELD("signed_entry_size","int32",0,4,SX_NONE),
};
const sx_layout sxbx_keytab_entry_length = {UINT32_C(0x60300075),"keytab_entry_length",sxbx_keytab_entry_length_fields,SX_COUNT(sxbx_keytab_entry_length_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_keytab_component_count_fields[] = {
 SX_FIELD("component_count","uint16",0,2,SX_COUNT_PROP),
};
const sx_layout sxbx_keytab_component_count = {UINT32_C(0x60300076),"keytab_component_count",sxbx_keytab_component_count_fields,SX_COUNT(sxbx_keytab_component_count_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_keytab_string_length_fields[] = {
 SX_FIELD("byte_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxbx_keytab_string_length = {UINT32_C(0x60300077),"keytab_string_length",sxbx_keytab_string_length_fields,SX_COUNT(sxbx_keytab_string_length_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_kerberos_name_type_fields[] = {
 SX_FIELD("name_type","uint32",0,4,SX_ID),
};
const sx_layout sxbx_kerberos_name_type = {UINT32_C(0x60300078),"kerberos_name_type",sxbx_kerberos_name_type_fields,SX_COUNT(sxbx_kerberos_name_type_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_keytab_key_fields[] = {
 SX_FIELD("timestamp","uint32",0,4,SX_NONE),
 SX_FIELD("kvno","uint8",4,1,SX_NONE),
 SX_FIELD("enctype","uint16",5,2,SX_ID),
 SX_FIELD("key_size","uint16",7,2,SX_SIZE),
};
const sx_layout sxbx_keytab_key = {UINT32_C(0x60300079),"keytab_key",sxbx_keytab_key_fields,SX_COUNT(sxbx_keytab_key_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_keytab_extended_kvno_fields[] = {
 SX_FIELD("kvno","uint32",0,4,SX_NONE),
};
const sx_layout sxbx_keytab_extended_kvno = {UINT32_C(0x6030007a),"keytab_extended_kvno",sxbx_keytab_extended_kvno_fields,SX_COUNT(sxbx_keytab_extended_kvno_fields),SX_BE};
#define SXBX_LIMIT 20000U
static bool sxbx_keytab(sx_context*c){uint64_t p=2,end=(uint64_t)c->size;if(!sxbx_add(c,&sxbx_keytab_header,0))return false;for(unsigned entries=0;p<end&&entries<2048&&c->count<SXBX_LIMIT;entries++){uint64_t raw;if(!sxbx_word(c,p,4,true,&raw))break;int64_t z=(int32_t)(uint32_t)raw;uint64_t n=z<0?(uint64_t)-z:(uint64_t)z;if(n>end-p-4||!sxbx_add(c,&sxbx_keytab_entry_length,p))break;p+=4;if(!z)break;if(z<0){p+=n;continue;}uint64_t q=p,stop=p+n,count;if(!sxbx_word(c,q,2,true,&count)||count>32||!count||!sxbx_add(c,&sxbx_keytab_component_count,q))break;q+=2;bool ok=true;for(uint64_t i=0;i<=count;i++)if(!sxbx_counted(c,&q,stop,&sxbx_keytab_string_length,2,true,1)){ok=false;break;}if(ok&&stop-q>=13&&sxbx_add(c,&sxbx_kerberos_name_type,q)&&sxbx_add(c,&sxbx_keytab_key,q+4)&&sxbx_word(c,q+11,2,true,&count)&&count<=stop-q-13){q+=13+count;if(stop-q>=4&&!sxbx_add(c,&sxbx_keytab_extended_kvno,q))return false;}p=stop;}return true;}
bool sx_kerberos_keytab_build(sx_context*c)
{
 return sxbx_keytab(c);
}
