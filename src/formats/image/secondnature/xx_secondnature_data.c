/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Second Nature data structures, moved out of the resourceextra schema family. */
#include "../../xx_format_schema_resourceextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxre_secondnature_banner_fields[] = {
 SX_FIELD("banner","char[28]",0,28,SX_SIGNATURE),
 SX_FIELD("kind","char[3]",28,3,SX_NONE),
 SX_FIELD("terminator","uint8",31,1,SX_NONE),
};
const sx_layout sxre_secondnature_banner = {UINT32_C(0x603f0001),"secondnature_banner",sxre_secondnature_banner_fields,SX_COUNT(sxre_secondnature_banner_fields),SX_LE};
static const xx_data_struct_field_desc sxre_secondnature_bmx_count_fields[] = {
 SX_FIELD("member_count","uint16",0,2,SX_COUNT_PROP),
};
const sx_layout sxre_secondnature_bmx_count = {UINT32_C(0x603f0002),"secondnature_bmx_count",sxre_secondnature_bmx_count_fields,SX_COUNT(sxre_secondnature_bmx_count_fields),SX_LE};
static const xx_data_struct_field_desc sxre_secondnature_ref_counts_fields[] = {
 SX_FIELD("text_member_count","uint16",0,2,SX_COUNT_PROP),
 SX_FIELD("image_member_count","uint16",2,2,SX_COUNT_PROP),
};
const sx_layout sxre_secondnature_ref_counts = {UINT32_C(0x603f0003),"secondnature_ref_counts",sxre_secondnature_ref_counts_fields,SX_COUNT(sxre_secondnature_ref_counts_fields),SX_LE};
static const xx_data_struct_field_desc sxre_secondnature_snx_text_fields[] = {
 SX_FIELD("title","char[64]",0,64,SX_NONE),
 SX_FIELD("caption","char[128]",64,128,SX_NONE),
 SX_FIELD("description","char[128]",192,128,SX_NONE),
};
const sx_layout sxre_secondnature_snx_text = {UINT32_C(0x603f0004),"secondnature_snx_text",sxre_secondnature_snx_text_fields,SX_COUNT(sxre_secondnature_snx_text_fields),SX_LE};
static const xx_data_struct_field_desc sxre_secondnature_snx_info_fields[] = {
 SX_FIELD("sequence_id","uint16",0,2,SX_NONE),
 SX_FIELD("width","uint16",2,2,SX_NONE),
 SX_FIELD("height","uint16",4,2,SX_NONE),
};
const sx_layout sxre_secondnature_snx_info = {UINT32_C(0x603f0005),"secondnature_snx_info",sxre_secondnature_snx_info_fields,SX_COUNT(sxre_secondnature_snx_info_fields),SX_LE};
static const xx_data_struct_field_desc sxre_secondnature_ref_entry_fields[] = {
 SX_FIELD("name","char[13]",0,13,SX_NONE),
 SX_FIELD("kind","uint16",13,2,SX_NONE),
 SX_FIELD("payload_offset","uint32",15,4,SX_OFFSET),
 SX_FIELD("payload_size","uint32",19,4,SX_SIZE),
 SX_FIELD("rectangle_0","uint16",23,2,SX_NONE),
 SX_FIELD("rectangle_1","uint16",25,2,SX_NONE),
 SX_FIELD("rectangle_2","uint16",27,2,SX_NONE),
 SX_FIELD("rectangle_3","uint16",29,2,SX_NONE),
};
const sx_layout sxre_secondnature_ref_entry = {UINT32_C(0x603f0007),"secondnature_ref_entry",sxre_secondnature_ref_entry_fields,SX_COUNT(sxre_secondnature_ref_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxre_secondnature_banner_complemented_fields[] = {
 SX_FIELD("banner","ones_char[28]",0,28,SX_SIGNATURE),
 SX_FIELD("kind","ones_char[3]",28,3,SX_NONE),
 SX_FIELD("terminator","uint8_ones",31,1,SX_NONE),
};
const sx_layout sxre_secondnature_banner_complemented = {UINT32_C(0x603f0008),"secondnature_banner_complemented",sxre_secondnature_banner_complemented_fields,SX_COUNT(sxre_secondnature_banner_complemented_fields),SX_LE};
static const xx_data_struct_field_desc sxre_secondnature_bmx_count_complemented_fields[] = {
 SX_FIELD("member_count","uint16_ones_le",0,2,SX_COUNT_PROP),
};
const sx_layout sxre_secondnature_bmx_count_complemented = {UINT32_C(0x603f0009),"secondnature_bmx_count_complemented",sxre_secondnature_bmx_count_complemented_fields,SX_COUNT(sxre_secondnature_bmx_count_complemented_fields),SX_LE};
static const xx_data_struct_field_desc sxre_secondnature_ref_counts_complemented_fields[] = {
 SX_FIELD("text_member_count","uint16_ones_le",0,2,SX_COUNT_PROP),
 SX_FIELD("image_member_count","uint16_ones_le",2,2,SX_COUNT_PROP),
};
const sx_layout sxre_secondnature_ref_counts_complemented = {UINT32_C(0x603f000a),"secondnature_ref_counts_complemented",sxre_secondnature_ref_counts_complemented_fields,SX_COUNT(sxre_secondnature_ref_counts_complemented_fields),SX_LE};
static const xx_data_struct_field_desc sxre_secondnature_snx_text_complemented_fields[] = {
 SX_FIELD("title","ones_char[64]",0,64,SX_NONE),
 SX_FIELD("caption","ones_char[128]",64,128,SX_NONE),
 SX_FIELD("description","ones_char[128]",192,128,SX_NONE),
};
const sx_layout sxre_secondnature_snx_text_complemented = {UINT32_C(0x603f000b),"secondnature_snx_text_complemented",sxre_secondnature_snx_text_complemented_fields,SX_COUNT(sxre_secondnature_snx_text_complemented_fields),SX_LE};
static const xx_data_struct_field_desc sxre_secondnature_snx_info_complemented_fields[] = {
 SX_FIELD("sequence_id","uint16_ones_le",0,2,SX_NONE),
 SX_FIELD("width","uint16_ones_le",2,2,SX_NONE),
 SX_FIELD("height","uint16_ones_le",4,2,SX_NONE),
};
const sx_layout sxre_secondnature_snx_info_complemented = {UINT32_C(0x603f000c),"secondnature_snx_info_complemented",sxre_secondnature_snx_info_complemented_fields,SX_COUNT(sxre_secondnature_snx_info_complemented_fields),SX_LE};
static const xx_data_struct_field_desc sxre_secondnature_ref_entry_complemented_fields[] = {
 SX_FIELD("name","ones_char[13]",0,13,SX_NONE),
 SX_FIELD("kind","uint16_ones_le",13,2,SX_NONE),
 SX_FIELD("payload_offset","uint32_ones_le",15,4,SX_OFFSET),
 SX_FIELD("payload_size","uint32_ones_le",19,4,SX_SIZE),
 SX_FIELD("rectangle_0","uint16_ones_le",23,2,SX_NONE),
 SX_FIELD("rectangle_1","uint16_ones_le",25,2,SX_NONE),
 SX_FIELD("rectangle_2","uint16_ones_le",27,2,SX_NONE),
 SX_FIELD("rectangle_3","uint16_ones_le",29,2,SX_NONE),
};
const sx_layout sxre_secondnature_ref_entry_complemented = {UINT32_C(0x603f000e),"secondnature_ref_entry_complemented",sxre_secondnature_ref_entry_complemented_fields,SX_COUNT(sxre_secondnature_ref_entry_complemented_fields),SX_LE};
static bool sxre_secondnature(sx_context*c){uint8_t b[32];if(!sxre_read(c,0,b,32))return false;bool mask=b[0]!=(uint8_t)'S';if(mask)for(unsigned i=0;i<32;i++)b[i]=(uint8_t)~b[i];if(xx_rt_memcmp(b,"Second Nature Software Inc. ",28)||b[31])return false;uint64_t count,p,z;const sx_layout *entry;
#define SXRE_SN(n) (mask?&sxre_secondnature_##n##_complemented:&sxre_secondnature_##n)
 if(!sxre_add(c,SXRE_SN(banner),0))return false;
 if(!xx_rt_memcmp(b+28,"BMX",3)){if(!sxre_word(c,32,2,mask,&count)||count<1||count>4096||!sxre_add(c,SXRE_SN(bmx_count),32))return false;p=34;z=21;entry=SXRE_SN(entry);}
 else if(!xx_rt_memcmp(b+28,"REF",3)){uint64_t a,v;if(!sxre_word(c,32,2,mask,&a)||!sxre_word(c,34,2,mask,&v)||a>64||v>64||!(count=a+v)||count>64||!sxre_add(c,SXRE_SN(ref_counts),32))return false;p=36;z=31;entry=SXRE_SN(ref_entry);}
 else if(!xx_rt_memcmp(b+28,"SNX",3)){if(!sxre_add(c,SXRE_SN(snx_text),32)||!sxre_add(c,SXRE_SN(snx_info),352))return false;p=358;z=21;count=3;entry=SXRE_SN(entry);}
 else return false;
 if(!sxre_span(c,p,count*z))return false;for(uint64_t i=0;i<count;i++)if(!sxre_add(c,entry,p+i*z))return false;
#undef SXRE_SN
 return true;}
bool sx_secondnature_build(sx_context*c)
{
return sxre_secondnature(c);
}
