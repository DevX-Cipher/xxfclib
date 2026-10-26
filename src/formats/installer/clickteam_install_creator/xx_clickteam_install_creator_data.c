/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Clickteam Install Creator data structures, moved out of the installerlast schema family. */
#include "../../xx_format_schema_installerlast.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxil_clickteam_creator_tag_fields[] = {
    SX_FIELD("signature","char[6]",0,6,SX_SIGNATURE),
};
const sx_layout sxil_clickteam_creator_tag = {0x6085003dU,"clickteam_creator_tag",sxil_clickteam_creator_tag_fields,SX_COUNT(sxil_clickteam_creator_tag_fields),SX_LE};
static const xx_data_struct_field_desc sxil_clickteam_creator_chunk_fields[] = {
    SX_FIELD("chunk_id","uint16",0,2,SX_ID),
    SX_FIELD("flags","uint16",2,2,SX_FLAGS),
    SX_FIELD("payload_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxil_clickteam_creator_chunk = {0x6085003eU,"clickteam_creator_chunk",sxil_clickteam_creator_chunk_fields,SX_COUNT(sxil_clickteam_creator_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxil_clickteam_creator_data_chunk_fields[] = {
    SX_FIELD("chunk_id","uint16",0,2,SX_ID),
    SX_FIELD("flags","uint16",2,2,SX_FLAGS),
    SX_FIELD("data_size","uint32",4,4,SX_SIZE),
    SX_FIELD("repeated_data_size","uint32",8,4,SX_SIZE),
};
const sx_layout sxil_clickteam_creator_data_chunk = {0x6085003fU,"clickteam_creator_data_chunk",sxil_clickteam_creator_data_chunk_fields,SX_COUNT(sxil_clickteam_creator_data_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxil_clickteam_creator_compression1_fields[] = {
    SX_FIELD("unpacked_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxil_clickteam_creator_compression1 = {0x60850040U,"clickteam_creator_compression1",sxil_clickteam_creator_compression1_fields,SX_COUNT(sxil_clickteam_creator_compression1_fields),SX_LE};
static const xx_data_struct_field_desc sxil_clickteam_creator_compression2_fields[] = {
    SX_FIELD("unpacked_size","uint32",0,4,SX_SIZE),
    SX_FIELD("method","uint8",4,1,SX_ID),
};
const sx_layout sxil_clickteam_creator_compression2 = {0x60850041U,"clickteam_creator_compression2",sxil_clickteam_creator_compression2_fields,SX_COUNT(sxil_clickteam_creator_compression2_fields),SX_LE};
static const xx_data_struct_field_desc sxil_clickteam_creator_method_fields[] = {
    SX_FIELD("method","uint8",0,1,SX_ID),
};
const sx_layout sxil_clickteam_creator_method = {0x60850042U,"clickteam_creator_method",sxil_clickteam_creator_method_fields,SX_COUNT(sxil_clickteam_creator_method_fields),SX_LE};
#define SXIL_ADD(c,n,p) sxil_put(c,&sxil_##n,p,1)
static bool sxil_clickteam(sx_context*c,sxil_records*r){uint64_t p;if(!sxil_pe(c,&p))return true;bool v2=sxil_eq(c,p,"wwgT)H",6);if(v2){if(!SXIL_ADD(c,clickteam_creator_tag,p))return false;p+=6;}
 for(size_t k=0;k<4096&&sxil_span(c,p,8);k++){uint8_t b[8];if(!sxil_read(c,p,b,8))return true;uint16_t id=sxil16(b,false),flags=sxil16(b+2,false);uint64_t n=sxil32(b+4,false);
  if(id==0x7f7f){if(sxil_span(c,p,12)&&!SXIL_ADD(c,clickteam_creator_data_chunk,p))return false;break;}
  if(!sxil_span(c,p+8,n))return true;if(!SXIL_ADD(c,clickteam_creator_chunk,p))return false;
  if(flags&&n>=(v2?5:4)){if(!sxil_put(c,v2?&sxil_clickteam_creator_compression2:&sxil_clickteam_creator_compression1,p+8,1))return false;}p+=8+n;
 }
 if(v2)for(size_t i=0;i<r->count;i++){sxil_member*m=r->items+i;/* A native v2 record includes the method byte in its physical payload. */if(m->packed&&sxil_span(c,m->data,1)&&!SXIL_ADD(c,clickteam_creator_method,m->data))return false;}
 return true;
}
bool sx_clickteam_install_creator_build(sx_context*c,sxil_records records)
{
 return sxil_clickteam(c,&records);
}
#undef SXIL_ADD
