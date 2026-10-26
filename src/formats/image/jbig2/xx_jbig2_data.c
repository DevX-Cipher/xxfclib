/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * jbig2 data structures, moved out of the rastermore schema family. */
#include "../../xx_format_schema_rastermore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxrm_jbig2_file_header_fields[] = {
    SX_FIELD("signature","uint8[8]",0,8,SX_SIGNATURE),
    SX_FIELD("flags","uint8",8,1,SX_FLAGS),
};
const sx_layout sxrm_jbig2_file_header = {UINT32_C(0x601d0059),"jbig2_file_header",sxrm_jbig2_file_header_fields,SX_COUNT(sxrm_jbig2_file_header_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_jbig2_page_count_fields[] = {
    SX_FIELD("pages","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxrm_jbig2_page_count = {UINT32_C(0x601d005a),"jbig2_page_count",sxrm_jbig2_page_count_fields,SX_COUNT(sxrm_jbig2_page_count_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_jbig2_segment_prefix_fields[] = {
    SX_FIELD("segment_number","uint32",0,4,SX_ID),
    SX_FIELD("flags","uint8",4,1,SX_FLAGS),
    SX_FIELD("reference_count_and_retention","uint8",5,1,SX_FLAGS),
};
const sx_layout sxrm_jbig2_segment_prefix = {UINT32_C(0x601d005b),"jbig2_segment_prefix",sxrm_jbig2_segment_prefix_fields,SX_COUNT(sxrm_jbig2_segment_prefix_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_jbig2_reference1_fields[] = {
    SX_FIELD("segment_number","uint8",0,1,SX_ID),
};
const sx_layout sxrm_jbig2_reference1 = {UINT32_C(0x601d005c),"jbig2_reference1",sxrm_jbig2_reference1_fields,SX_COUNT(sxrm_jbig2_reference1_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_jbig2_reference2_fields[] = {
    SX_FIELD("segment_number","uint16",0,2,SX_ID),
};
const sx_layout sxrm_jbig2_reference2 = {UINT32_C(0x601d005d),"jbig2_reference2",sxrm_jbig2_reference2_fields,SX_COUNT(sxrm_jbig2_reference2_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_jbig2_reference4_fields[] = {
    SX_FIELD("segment_number","uint32",0,4,SX_ID),
};
const sx_layout sxrm_jbig2_reference4 = {UINT32_C(0x601d005e),"jbig2_reference4",sxrm_jbig2_reference4_fields,SX_COUNT(sxrm_jbig2_reference4_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_jbig2_segment_tail1_fields[] = {
    SX_FIELD("page_association","uint8",0,1,SX_ID),
    SX_FIELD("data_size","uint32",1,4,SX_SIZE),
};
const sx_layout sxrm_jbig2_segment_tail1 = {UINT32_C(0x601d005f),"jbig2_segment_tail1",sxrm_jbig2_segment_tail1_fields,SX_COUNT(sxrm_jbig2_segment_tail1_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_jbig2_segment_tail4_fields[] = {
    SX_FIELD("page_association","uint32",0,4,SX_ID),
    SX_FIELD("data_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxrm_jbig2_segment_tail4 = {UINT32_C(0x601d0060),"jbig2_segment_tail4",sxrm_jbig2_segment_tail4_fields,SX_COUNT(sxrm_jbig2_segment_tail4_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_jbig2_page_info_fields[] = {
    SX_FIELD("width","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("height","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("x_resolution","uint32",8,4,SX_NONE),
    SX_FIELD("y_resolution","uint32",12,4,SX_NONE),
    SX_FIELD("flags","uint8",16,1,SX_FLAGS),
    SX_FIELD("striping_information","uint16",17,2,SX_FLAGS),
};
const sx_layout sxrm_jbig2_page_info = {UINT32_C(0x601d0061),"jbig2_page_info",sxrm_jbig2_page_info_fields,SX_COUNT(sxrm_jbig2_page_info_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_jbig2_region_fields[] = {
    SX_FIELD("width","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("height","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("x","uint32",8,4,SX_NONE),
    SX_FIELD("y","uint32",12,4,SX_NONE),
    SX_FIELD("flags","uint8",16,1,SX_FLAGS),
};
const sx_layout sxrm_jbig2_region = {UINT32_C(0x601d0062),"jbig2_region",sxrm_jbig2_region_fields,SX_COUNT(sxrm_jbig2_region_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_jbig2_extension_fields[] = {
    SX_FIELD("extension_type","uint32",0,4,SX_FLAGS),
};
const sx_layout sxrm_jbig2_extension = {UINT32_C(0x601d0063),"jbig2_extension",sxrm_jbig2_extension_fields,SX_COUNT(sxrm_jbig2_extension_fields),SX_BE};
static bool sxrm_jbig2(sx_context *c)
{
 uint8_t h[20];if(!sxrm_read(c,0,h,9)||xx_rt_memcmp(h,"\x97JB2\r\n\x1a\n",8)||!sxrm_add(c,&sxrm_jbig2_file_header,0))return false;uint64_t p=9;
 if(!(h[8]&2)){if(!sxrm_span(c,p,4))return true;if(!sxrm_add(c,&sxrm_jbig2_page_count,p))return false;p+=4;}
 for(unsigned step=0;step<4096;step++){
  if(!sxrm_read(c,p,h,6))break;uint32_t id=sxrm32(h,true);unsigned flags=h[4],type=flags&63,n=h[5]>>5,refsize=id<=256?1:id<=65536?2:4,pagesize=(flags&64)?4:1;if(n>4)break;
  uint64_t tail=p+6+(uint64_t)n*refsize;if(!sxrm_read(c,tail,h,pagesize+4))break;uint32_t z=sxrm32(h+pagesize,true);uint64_t body=tail+pagesize+4;if(!sxrm_span(c,body,z))break;
  if(!sxrm_add(c,&sxrm_jbig2_segment_prefix,p)||!sxrm_table(c,refsize==1?&sxrm_jbig2_reference1:refsize==2?&sxrm_jbig2_reference2:&sxrm_jbig2_reference4,p+6,n)||!sxrm_add(c,pagesize==1?&sxrm_jbig2_segment_tail1:&sxrm_jbig2_segment_tail4,tail))return false;
  if(type==48&&z>=19){if(!sxrm_add(c,&sxrm_jbig2_page_info,body))return false;}
  else if((type==4||type==6||type==7||type==20||type==22||type==23||type==36||type==38||type==39||type==40||type==42||type==43)&&z>=17){if(!sxrm_add(c,&sxrm_jbig2_region,body))return false;}
  else if(type==62&&z>=4&&!sxrm_add(c,&sxrm_jbig2_extension,body))return false;p=body+z;if(type==51)break;
 }return !c->failed;
}
bool sx_jbig2_build(sx_context*c)
{
 return sxrm_jbig2(c);
}
