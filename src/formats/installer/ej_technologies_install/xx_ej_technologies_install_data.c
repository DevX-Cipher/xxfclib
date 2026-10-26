/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ej-technologies install4j / exe4j data structures, moved out of the installerlast schema family. */
#include "../../xx_format_schema_installerlast.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxil_ej_technologies_header_fields[] = {
    SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("variable_count","int32",4,4,SX_COUNT_PROP),
};
const sx_layout sxil_ej_technologies_header = {0x60850010U,"ej_technologies_header",sxil_ej_technologies_header_fields,SX_COUNT(sxil_ej_technologies_header_fields),SX_LE};
static const xx_data_struct_field_desc sxil_ej_technologies_variable_fields[] = {
    SX_FIELD("key","int32",0,4,SX_ID),
    SX_FIELD("value_size","int32",4,4,SX_SIZE),
};
const sx_layout sxil_ej_technologies_variable = {0x60850011U,"ej_technologies_variable",sxil_ej_technologies_variable_fields,SX_COUNT(sxil_ej_technologies_variable_fields),SX_LE};
static const xx_data_struct_field_desc sxil_ej_technologies_extra_count_fields[] = {
    SX_FIELD("extra_count","int32",0,4,SX_COUNT_PROP),
};
const sx_layout sxil_ej_technologies_extra_count = {0x60850012U,"ej_technologies_extra_count",sxil_ej_technologies_extra_count_fields,SX_COUNT(sxil_ej_technologies_extra_count_fields),SX_LE};
static const xx_data_struct_field_desc sxil_ej_technologies_member_fields[] = {
    SX_FIELD("file_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxil_ej_technologies_member = {0x60850013U,"ej_technologies_member",sxil_ej_technologies_member_fields,SX_COUNT(sxil_ej_technologies_member_fields),SX_LE};
static const xx_data_struct_field_desc sxil_ej_technologies_member_later_fields[] = {
    SX_FIELD("file_size","uint32",0,4,SX_SIZE),
    SX_FIELD("reserved","uint32",4,4,SX_RESERVED),
};
const sx_layout sxil_ej_technologies_member_later = {0x60850014U,"ej_technologies_member_later",sxil_ej_technologies_member_later_fields,SX_COUNT(sxil_ej_technologies_member_later_fields),SX_LE};
static const xx_data_struct_field_desc sxil_ej_technologies_trailer_fields[] = {
    SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("member_count","uint32",4,4,SX_COUNT_PROP),
};
const sx_layout sxil_ej_technologies_trailer = {0x60850015U,"ej_technologies_trailer",sxil_ej_technologies_trailer_fields,SX_COUNT(sxil_ej_technologies_trailer_fields),SX_BE};
static const xx_data_struct_field_desc sxil_ej_technologies_trailer_name_fields[] = {
    SX_FIELD("name_length","uint16",0,2,SX_SIZE),
};
const sx_layout sxil_ej_technologies_trailer_name = {0x60850016U,"ej_technologies_trailer_name",sxil_ej_technologies_trailer_name_fields,SX_COUNT(sxil_ej_technologies_trailer_name_fields),SX_BE};
static const xx_data_struct_field_desc sxil_ej_technologies_trailer_size_fields[] = {
    SX_FIELD("file_size","uint64",0,8,SX_SIZE),
};
const sx_layout sxil_ej_technologies_trailer_size = {0x60850017U,"ej_technologies_trailer_size",sxil_ej_technologies_trailer_size_fields,SX_COUNT(sxil_ej_technologies_trailer_size_fields),SX_BE};
#define SXIL_ADD(c,n,p) sxil_put(c,&sxil_##n,p,1)
static bool sxil_ej(sx_context*c,sxil_records*r){
 uint64_t p;if(!sxil_pe(c,&p)||!sxil_eq(c,p,"\xd5\x13\xe4\xe8",4))return true;uint32_t n;if(!sxil_u32(c,p+4,&n)||!n||n>=1024)return true;
 if(!SXIL_ADD(c,ej_technologies_header,p))return false;p+=8;
 for(unsigned pass=0;pass<2;pass++){
  if(pass){if(!sxil_u32(c,p,&n)||n>=1024)return true;if(!SXIL_ADD(c,ej_technologies_extra_count,p))return false;p+=4;}
  for(uint32_t i=0;i<n;i++){uint32_t z;if(!sxil_u32(c,p+4,&z)||z>INT32_MAX||!sxil_span(c,p+8,z))return true;if(!SXIL_ADD(c,ej_technologies_variable,p)||!sxil_name(c,p+8,z))return false;p+=8+(uint64_t)z;}
 }
 for(size_t i=0;i<r->count;i++){
  sxil_member*m=r->items+i;if(m->header_size==4){if(!SXIL_ADD(c,ej_technologies_member,m->header))return false;}
  else if(m->header_size==8){if(!SXIL_ADD(c,ej_technologies_member_later,m->header))return false;}
  else if(m->header_size>=10){uint8_t b[2];if(!sxil_read(c,m->header,b,2))continue;uint64_t z=sxil16(b,true);if(z+10==m->header_size&&(!SXIL_ADD(c,ej_technologies_trailer_name,m->header)||!sxil_name(c,m->header+2,z)||!SXIL_ADD(c,ej_technologies_trailer_size,m->header+2+z)))return false;}
  uint64_t e=m->data+m->packed;if(sxil_eq(c,e,"\xe8\xe4\x13\xd5",4)&&!SXIL_ADD(c,ej_technologies_trailer,e))return false;
 }
 if(sxil_eq(c,p,"\xe8\xe4\x13\xd5",4)&&!SXIL_ADD(c,ej_technologies_trailer,p))return false;return true;
}
bool sx_ej_technologies_install_build(sx_context*c,sxil_records records)
{
 return sxil_ej(c,&records);
}
#undef SXIL_ADD
