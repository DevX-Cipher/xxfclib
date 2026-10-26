/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ZPAQ data structures, moved out of the archivenext schema family. */
#include "../../xx_format_schema_archivenext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxan_zpaq_block_fields[] = {
 SX_FIELD("signature","char[3]",0,3,SX_SIGNATURE),
 SX_FIELD("level","uint8",3,1,SX_NONE),
 SX_FIELD("type","uint8",4,1,SX_NONE),
 SX_FIELD("header_size","uint16",5,2,SX_SIZE),
};
const sx_layout sxan_zpaq_block = {UINT32_C(0x607700a8),"zpaq_block",sxan_zpaq_block_fields,SX_COUNT(sxan_zpaq_block_fields),SX_LE};
static const xx_data_struct_field_desc sxan_zpaq_model_fields[] = {
 SX_FIELD("hcomp_hash_bits","uint8",0,1,SX_NONE),
 SX_FIELD("hcomp_memory_bits","uint8",1,1,SX_NONE),
 SX_FIELD("pcomp_hash_bits","uint8",2,1,SX_NONE),
 SX_FIELD("pcomp_memory_bits","uint8",3,1,SX_NONE),
 SX_FIELD("component_count","uint8",4,1,SX_COUNT_PROP),
};
const sx_layout sxan_zpaq_model = {UINT32_C(0x607700a9),"zpaq_model",sxan_zpaq_model_fields,SX_COUNT(sxan_zpaq_model_fields),SX_LE};
static const xx_data_struct_field_desc sxan_zpaq_locator_fields[] = {
 SX_FIELD("locator","uint8[13]",0,13,SX_SIGNATURE),
};
const sx_layout sxan_zpaq_locator = {UINT32_C(0x607700aa),"zpaq_locator",sxan_zpaq_locator_fields,SX_COUNT(sxan_zpaq_locator_fields),SX_LE};
static const xx_data_struct_field_desc sxan_zpaq_marker_fields[] = {
 SX_FIELD("marker","uint8",0,1,SX_NONE),
};
const sx_layout sxan_zpaq_marker = {UINT32_C(0x607700ab),"zpaq_marker",sxan_zpaq_marker_fields,SX_COUNT(sxan_zpaq_marker_fields),SX_LE};
static const xx_data_struct_field_desc sxan_zpaq_stored_run_fields[] = {
 SX_FIELD("run_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxan_zpaq_stored_run = {UINT32_C(0x607700ac),"zpaq_stored_run",sxan_zpaq_stored_run_fields,SX_COUNT(sxan_zpaq_stored_run_fields),SX_BE};
static const xx_data_struct_field_desc sxan_zpaq_sha1_fields[] = {
 SX_FIELD("sha1","uint8[20]",0,20,SX_CHECKSUM),
};
const sx_layout sxan_zpaq_sha1 = {UINT32_C(0x607700ad),"zpaq_sha1",sxan_zpaq_sha1_fields,SX_COUNT(sxan_zpaq_sha1_fields),SX_LE};
static const xx_data_struct_field_desc sxan_zpaq_comment_fields[] = {
 SX_FIELD("comment","char",0,0,SX_NONE),
};
const sx_layout sxan_zpaq_comment = {UINT32_C(0x607700ae),"zpaq_comment",sxan_zpaq_comment_fields,SX_COUNT(sxan_zpaq_comment_fields),SX_LE};
static const xx_data_struct_field_desc sxan_zpaq_cons_fields[] = {
 SX_FIELD("component_type","uint8",0,1,SX_NONE),
 SX_FIELD("constant","uint8",1,1,SX_NONE),
};
const sx_layout sxan_zpaq_cons = {UINT32_C(0x607700af),"zpaq_cons",sxan_zpaq_cons_fields,SX_COUNT(sxan_zpaq_cons_fields),SX_LE};
static const xx_data_struct_field_desc sxan_zpaq_cm_fields[] = {
 SX_FIELD("component_type","uint8",0,1,SX_NONE),
 SX_FIELD("sizebits","uint8",1,1,SX_NONE),
 SX_FIELD("limit","uint8",2,1,SX_NONE),
};
const sx_layout sxan_zpaq_cm = {UINT32_C(0x607700b0),"zpaq_cm",sxan_zpaq_cm_fields,SX_COUNT(sxan_zpaq_cm_fields),SX_LE};
static const xx_data_struct_field_desc sxan_zpaq_icm_fields[] = {
 SX_FIELD("component_type","uint8",0,1,SX_NONE),
 SX_FIELD("sizebits","uint8",1,1,SX_NONE),
};
const sx_layout sxan_zpaq_icm = {UINT32_C(0x607700b1),"zpaq_icm",sxan_zpaq_icm_fields,SX_COUNT(sxan_zpaq_icm_fields),SX_LE};
static const xx_data_struct_field_desc sxan_zpaq_match_fields[] = {
 SX_FIELD("component_type","uint8",0,1,SX_NONE),
 SX_FIELD("sizebits","uint8",1,1,SX_NONE),
 SX_FIELD("bufferbits","uint8",2,1,SX_NONE),
};
const sx_layout sxan_zpaq_match = {UINT32_C(0x607700b2),"zpaq_match",sxan_zpaq_match_fields,SX_COUNT(sxan_zpaq_match_fields),SX_LE};
static const xx_data_struct_field_desc sxan_zpaq_avg_fields[] = {
 SX_FIELD("component_type","uint8",0,1,SX_NONE),
 SX_FIELD("component_j","uint8",1,1,SX_NONE),
 SX_FIELD("component_k","uint8",2,1,SX_NONE),
 SX_FIELD("weight","uint8",3,1,SX_NONE),
};
const sx_layout sxan_zpaq_avg = {UINT32_C(0x607700b3),"zpaq_avg",sxan_zpaq_avg_fields,SX_COUNT(sxan_zpaq_avg_fields),SX_LE};
static const xx_data_struct_field_desc sxan_zpaq_mix2_fields[] = {
 SX_FIELD("component_type","uint8",0,1,SX_NONE),
 SX_FIELD("sizebits","uint8",1,1,SX_NONE),
 SX_FIELD("component_j","uint8",2,1,SX_NONE),
 SX_FIELD("component_k","uint8",3,1,SX_NONE),
 SX_FIELD("rate","uint8",4,1,SX_NONE),
 SX_FIELD("mask","uint8",5,1,SX_NONE),
};
const sx_layout sxan_zpaq_mix2 = {UINT32_C(0x607700b4),"zpaq_mix2",sxan_zpaq_mix2_fields,SX_COUNT(sxan_zpaq_mix2_fields),SX_LE};
static const xx_data_struct_field_desc sxan_zpaq_mix_fields[] = {
 SX_FIELD("component_type","uint8",0,1,SX_NONE),
 SX_FIELD("sizebits","uint8",1,1,SX_NONE),
 SX_FIELD("first_component","uint8",2,1,SX_NONE),
 SX_FIELD("component_count","uint8",3,1,SX_COUNT_PROP),
 SX_FIELD("rate","uint8",4,1,SX_NONE),
 SX_FIELD("mask","uint8",5,1,SX_NONE),
};
const sx_layout sxan_zpaq_mix = {UINT32_C(0x607700b5),"zpaq_mix",sxan_zpaq_mix_fields,SX_COUNT(sxan_zpaq_mix_fields),SX_LE};
static const xx_data_struct_field_desc sxan_zpaq_isse_fields[] = {
 SX_FIELD("component_type","uint8",0,1,SX_NONE),
 SX_FIELD("sizebits","uint8",1,1,SX_NONE),
 SX_FIELD("component_j","uint8",2,1,SX_NONE),
};
const sx_layout sxan_zpaq_isse = {UINT32_C(0x607700b6),"zpaq_isse",sxan_zpaq_isse_fields,SX_COUNT(sxan_zpaq_isse_fields),SX_LE};
static const xx_data_struct_field_desc sxan_zpaq_sse_fields[] = {
 SX_FIELD("component_type","uint8",0,1,SX_NONE),
 SX_FIELD("sizebits","uint8",1,1,SX_NONE),
 SX_FIELD("component_j","uint8",2,1,SX_NONE),
 SX_FIELD("start","uint8",3,1,SX_NONE),
 SX_FIELD("limit","uint8",4,1,SX_NONE),
};
const sx_layout sxan_zpaq_sse = {UINT32_C(0x607700b7),"zpaq_sse",sxan_zpaq_sse_fields,SX_COUNT(sxan_zpaq_sse_fields),SX_LE};
#define SXAN_LIMIT 20000U
static bool sxan_zpaq(sx_context*c){static const uint8_t locator[13]={0x37,0x6b,0x53,0x74,0xa0,0x31,0x83,0xd3,0x8c,0xb2,0x28,0xb0,0xd3};static const uint8_t width[10]={0,2,3,2,3,4,6,6,3,5};static const sx_layout*const layouts[10]={NULL,&sxan_zpaq_cons,&sxan_zpaq_cm,&sxan_zpaq_icm,&sxan_zpaq_match,&sxan_zpaq_avg,&sxan_zpaq_mix2,&sxan_zpaq_mix,&sxan_zpaq_isse,&sxan_zpaq_sse};uint64_t p=0;for(unsigned blocks=0;blocks<SXAN_LIMIT&&p<(uint64_t)c->size;blocks++){uint8_t h[13];if(sxan_read(c,p,h,13)&&!xx_rt_memcmp(h,locator,13)){if(!sxan_add(c,&sxan_zpaq_locator,p))return false;p+=13;}if(!sxan_read(c,p,h,7)||xx_rt_memcmp(h,"zPQ",3))return true;uint64_t z=sxan_uint(h+5,2,false);if(z<7||!sxan_span(c,p+7,z)||!sxan_add(c,&sxan_zpaq_block,p))return false;p+=7;uint64_t header_end=p+z;if(!sxan_read(c,p,h,5)||!sxan_add(c,&sxan_zpaq_model,p))return false;unsigned count=h[4];p+=5;for(unsigned i=0;i<count;i++){uint64_t kind;if(!sxan_word(c,p,1,false,&kind)||kind<1||kind>9||p>header_end||width[kind]>header_end-p||!sxan_add(c,layouts[kind],p))return false;p+=width[kind];}if(p>=header_end||!sxan_add(c,&sxan_zpaq_marker,p))return false;if(header_end-1>p&&!sxan_add(c,&sxan_zpaq_marker,header_end-1))return false;p=header_end;for(unsigned segments=0;segments<SXAN_LIMIT;segments++){uint64_t marker,len;if(!sxan_word(c,p,1,false,&marker)||!sxan_add(c,&sxan_zpaq_marker,p))return false;p++;if(marker==255)break;if(marker!=1)return true;if(!sxan_zlen(c,p,(uint64_t)c->size,&len)||!sxan_named(c,p,len))return false;p+=len;if(!sxan_zlen(c,p,(uint64_t)c->size,&len)||!sxan_text(c,&sxan_zpaq_comment,p,len,false))return false;p+=len;if(!sxan_add(c,&sxan_zpaq_marker,p))return false;p++;
 /* Arithmetic-coded segment ends require execution of the probability model.
  * Preserve that opaque suffix instead of searching for marker-like bytes. */
 if(count)return true;for(unsigned runs=0;runs<SXAN_LIMIT;runs++){if(!sxan_word(c,p,4,true,&z)||!sxan_add(c,&sxan_zpaq_stored_run,p))return false;p+=4;if(!z)break;if(!sxan_span(c,p,z))return true;p+=z;}if(!sxan_word(c,p,1,false,&marker)||!sxan_add(c,&sxan_zpaq_marker,p))return false;p++;if(marker==253){if(!sxan_add(c,&sxan_zpaq_sha1,p))return false;p+=20;}else if(marker!=254)return true;}}return true;}
bool sx_zpaq_build(sx_context*c)
{
bool ok=false;
ok=sxan_zpaq(c);
(void)ok;return c->count&&sxan_finish(c);
}
