/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SPK data structures, moved out of the archivepackages schema family. */
#include "../../xx_format_schema_archivepackages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxap_spark_prefix_fields[] = {
 SX_FIELD("signature","uint8",0,1,SX_SIGNATURE),
 SX_FIELD("method","uint8",1,1,SX_NONE),
 SX_FIELD("name","char[13]",2,13,SX_NONE),
 SX_FIELD("compressed_size","uint32",15,4,SX_SIZE),
 SX_FIELD("dos_date","uint16",19,2,SX_NONE),
 SX_FIELD("dos_time","uint16",21,2,SX_NONE),
 SX_FIELD("crc16","uint16",23,2,SX_CHECKSUM),
};
const sx_layout sxap_spark_prefix = {UINT32_C(0x6072000f),"spark_prefix",sxap_spark_prefix_fields,SX_COUNT(sxap_spark_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxap_spark_original_size_fields[] = {
 SX_FIELD("uncompressed_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxap_spark_original_size = {UINT32_C(0x60720010),"spark_original_size",sxap_spark_original_size_fields,SX_COUNT(sxap_spark_original_size_fields),SX_LE};
static const xx_data_struct_field_desc sxap_spark_riscos_fields[] = {
 SX_FIELD("load_address","uint32",0,4,SX_ADDRESS),
 SX_FIELD("exec_address","uint32",4,4,SX_ADDRESS),
 SX_FIELD("attributes","uint32",8,4,SX_FLAGS),
};
const sx_layout sxap_spark_riscos = {UINT32_C(0x60720011),"spark_riscos",sxap_spark_riscos_fields,SX_COUNT(sxap_spark_riscos_fields),SX_LE};
static const xx_data_struct_field_desc sxap_spark_end_fields[] = {
 SX_FIELD("signature","uint8",0,1,SX_SIGNATURE),
 SX_FIELD("method","uint8",1,1,SX_NONE),
};
const sx_layout sxap_spark_end = {UINT32_C(0x60720012),"spark_end",sxap_spark_end_fields,SX_COUNT(sxap_spark_end_fields),SX_LE};
static bool sxap_spark(sx_context*c,uint64_t p,uint64_t end,unsigned depth){if(depth>32||end>(uint64_t)c->size)return false;while(p<end){uint8_t h[41];if(end-p<2||!sxap_read(c,p,h,2)||h[0]!=0x1a)return false;unsigned method=h[1]&127;if(!method)return sxap_add(c,&sxap_spark_end,p);if(end-p<25||!sxap_read(c,p,h,25)||!sxap_add(c,&sxap_spark_prefix,p))return false;uint64_t packed=sxap_uint(h+15,4,false),q=p+25,load=0;{if(end-q<4||!sxap_add(c,&sxap_spark_original_size,q))return false;q+=4;}if(h[1]&128){if(end-q<12||!sxap_word(c,q,4,false,&load)||!sxap_add(c,&sxap_spark_riscos,q))return false;q+=12;}if(packed>end-q)return true;if(method==2&&(load&0xffffff00U)==0xfffddc00U&&!sxap_spark(c,q,q+packed,depth+1))return false;p=q+packed;}return true;}
bool sx_spk_build(sx_context*c)
{
 return sxap_spark(c,0,(uint64_t)c->size,0);
}
