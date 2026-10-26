/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * axona_tetrode data structures, moved out of the scientificextra schema family. */
#include "../../xx_format_schema_scientificextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxscx_axona_timestamp_fields[] = {
    SX_FIELD("timestamp","int32",0,4,SX_NONE),
};
const sx_layout sxscx_axona_timestamp = {UINT32_C(0x60310002),"axona_timestamp",sxscx_axona_timestamp_fields,SX_COUNT(sxscx_axona_timestamp_fields),SX_BE};
static const xx_data_struct_field_desc sxscx_axona_end_fields[] = {
    SX_FIELD("marker","char[12]",0,12,SX_SIGNATURE),
};
const sx_layout sxscx_axona_end = {UINT32_C(0x60310003),"axona_end",sxscx_axona_end_fields,SX_COUNT(sxscx_axona_end_fields),SX_LE};
static bool sxscx_axona(sx_context *c,const uint8_t *b,size_t n)
{
 uint64_t at=0,head=0,samples=0,count=0,channels=0;
 while(at<n&&at<65536){if(n-at>=10&&!xx_rt_memcmp(b+at,"data_start",10)){head=at+10;break;}
  uint64_t end=at;while(end<n&&b[end]!='\n')end++;if(end==n)return false;
  const char *keys[]={"num_spikes ","num_chans ","samples_per_spike "};uint64_t *out[]={&count,&channels,&samples};
  for(unsigned i=0;i<3;i++){size_t z=xx_rt_strlen(keys[i]);if(end-at>=z&&!xx_rt_memcmp(b+at,keys[i],z)&&!sxscx_decimal(b+at+z,(size_t)(end-at-z),out[i]))return false;}at=end+1;
 }
 if(!head||!count||count>261760||channels!=4||!samples||samples>1024)return false;
 uint64_t width=4+samples,bytes=count*4*width;if(!sxscx_span(c,head,bytes+12)||head+bytes+12!=n)return false;
 for(uint64_t i=0;i<count*4&&c->count<32000;i++)if(!sxscx_add(c,&sxscx_axona_timestamp,head+i*width))return false;
 return sxscx_add(c,&sxscx_axona_end,head+bytes);
}
bool sx_axona_tetrode_build(sx_context *c,uint8_t *b)
{
 return sxscx_axona(c,b,(size_t)c->size);
}
