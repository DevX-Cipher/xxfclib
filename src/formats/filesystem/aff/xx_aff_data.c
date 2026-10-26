/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Aff data structures, moved out of the volumeimages schema family. */
#include "../../xx_format_schema_volumeimages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxvi_aff_segment_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("name_length","uint32",4,4,SX_SIZE),
    SX_FIELD("data_length","uint32",8,4,SX_SIZE),
    SX_FIELD("argument","uint32",12,4,SX_FLAGS),
};
const sx_layout sxvi_aff_segment_header = {0x60530036U,"aff_segment_header",sxvi_aff_segment_header_fields,SX_COUNT(sxvi_aff_segment_header_fields),SX_BE};
static const xx_data_struct_field_desc sxvi_aff_segment_footer_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("segment_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxvi_aff_segment_footer = {0x60530037U,"aff_segment_footer",sxvi_aff_segment_footer_fields,SX_COUNT(sxvi_aff_segment_footer_fields),SX_BE};
static const xx_data_struct_field_desc sxvi_aff_quadword_fields[] = {
    SX_FIELD("low","uint32",0,4,SX_NONE),
    SX_FIELD("high","uint32",4,4,SX_NONE),
};
const sx_layout sxvi_aff_quadword = {0x60530038U,"aff_quadword",sxvi_aff_quadword_fields,SX_COUNT(sxvi_aff_quadword_fields),SX_BE};
#define SXVI_LIMIT 24000U
#define SXVI_ADD(c,l,p) sxvi_put(c,&sxvi_##l,p,1)
static bool sxvi_aff(sx_context*c){
 if(!sxvi_magic(c,0,"AFF10\r\n\0",8))return false;
 uint64_t p=8;uint8_t h[16],name[128];
 for(unsigned count=0;count<262144&&p<(uint64_t)c->size&&c->count<SXVI_LIMIT;count++){
  if(!sxvi_read(c,p,h,16)||xx_rt_memcmp(h,"AFF\0",4))break;uint64_t n=sxvi32(h+4,1),z=sxvi32(h+8,1);
  if(n>=128||!sxvi_span(c,p+16,n)||z>(uint64_t)c->size-p-16-n||!sxvi_span(c,p+16+n+z,8))break;
  uint64_t tail=p+16+n+z;uint8_t f[8];if(!sxvi_read(c,tail,f,8)||xx_rt_memcmp(f,"ATT\0",4)||sxvi32(f+4,1)!=24+n+z)break;
  if(!SXVI_ADD(c,aff_segment_header,p)||!SXVI_ADD(c,aff_segment_footer,tail))return false;
  if(n&&sxvi_read(c,p+16,name,(size_t)n)&&n==9&&!xx_rt_memcmp(name,"imagesize",9)&&z==8&&sxvi32(h+12,1)==2&&!SXVI_ADD(c,aff_quadword,p+16+n))return false;
  p=tail+8;
 }return c->count!=0;
}
bool sx_aff_build(sx_context*c)
{
 return sxvi_aff(c);
}
#undef SXVI_LIMIT
#undef SXVI_ADD
