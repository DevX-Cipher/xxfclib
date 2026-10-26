/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * BLACKROCK_NEV data structures, moved out of the scienceheaders schema family. */
#include "../../xx_format_schema_scienceheaders.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsh_nev_header_fields[] = {
    SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("major_version","uint8",8,1,SX_ID),
    SX_FIELD("minor_version","uint8",9,1,SX_ID),
    SX_FIELD("flags","uint16",10,2,SX_FLAGS),
    SX_FIELD("header_size","uint32",12,4,SX_SIZE),
    SX_FIELD("packet_size","uint32",16,4,SX_SIZE),
    SX_FIELD("timestamp_resolution","uint32",20,4,SX_NONE),
    SX_FIELD("sample_resolution","uint32",24,4,SX_NONE),
    SX_FIELD("year","uint16",28,2,SX_NONE),
    SX_FIELD("month","uint16",30,2,SX_NONE),
    SX_FIELD("day_of_week","uint16",32,2,SX_NONE),
    SX_FIELD("day","uint16",34,2,SX_NONE),
    SX_FIELD("hour","uint16",36,2,SX_NONE),
    SX_FIELD("minute","uint16",38,2,SX_NONE),
    SX_FIELD("second","uint16",40,2,SX_NONE),
    SX_FIELD("millisecond","uint16",42,2,SX_NONE),
    SX_FIELD("application","char[32]",44,32,SX_STRING),
    SX_FIELD("comment","char[256]",76,256,SX_STRING),
    SX_FIELD("extended_header_count","uint32",332,4,SX_COUNT_PROP),
};
const sx_layout sxsh_nev_header = {UINT32_C(0x602a0004),"nev_header",sxsh_nev_header_fields,SX_COUNT(sxsh_nev_header_fields),SX_LE};
static const xx_data_struct_field_desc sxsh_nev_extension_fields[] = {
    SX_FIELD("type","char[8]",0,8,SX_ID),
    SX_FIELD("payload","uint8[24]",8,24,SX_NONE),
};
const sx_layout sxsh_nev_extension = {UINT32_C(0x602a0005),"nev_extension",sxsh_nev_extension_fields,SX_COUNT(sxsh_nev_extension_fields),SX_LE};
static const xx_data_struct_field_desc sxsh_nev_text_extension_fields[] = {
    SX_FIELD("type","char[8]",0,8,SX_ID),
    SX_FIELD("text","char[24]",8,24,SX_STRING),
};
const sx_layout sxsh_nev_text_extension = {UINT32_C(0x602a0006),"nev_text_extension",sxsh_nev_text_extension_fields,SX_COUNT(sxsh_nev_text_extension_fields),SX_LE};
static const xx_data_struct_field_desc sxsh_nev_waveform_extension_fields[] = {
    SX_FIELD("type","char[8]",0,8,SX_ID),
    SX_FIELD("electrode_id","uint16",8,2,SX_ID),
    SX_FIELD("connector_bank","uint8",10,1,SX_ID),
    SX_FIELD("connector_pin","uint8",11,1,SX_ID),
    SX_FIELD("digital_factor","int16",12,2,SX_NONE),
    SX_FIELD("energy_threshold","uint16",14,2,SX_NONE),
    SX_FIELD("high_threshold","int16",16,2,SX_NONE),
    SX_FIELD("low_threshold","int16",18,2,SX_NONE),
    SX_FIELD("sorted_unit_count","uint8",20,1,SX_COUNT_PROP),
    SX_FIELD("bytes_per_sample","uint8",21,1,SX_SIZE),
    SX_FIELD("reserved","uint8[10]",22,10,SX_RESERVED),
};
const sx_layout sxsh_nev_waveform_extension = {UINT32_C(0x602a0007),"nev_waveform_extension",sxsh_nev_waveform_extension_fields,SX_COUNT(sxsh_nev_waveform_extension_fields),SX_LE};
static const xx_data_struct_field_desc sxsh_nev_label_extension_fields[] = {
    SX_FIELD("type","char[8]",0,8,SX_ID),
    SX_FIELD("electrode_id","uint16",8,2,SX_ID),
    SX_FIELD("label","char[16]",10,16,SX_STRING),
    SX_FIELD("reserved","uint8[6]",26,6,SX_RESERVED),
};
const sx_layout sxsh_nev_label_extension = {UINT32_C(0x602a0008),"nev_label_extension",sxsh_nev_label_extension_fields,SX_COUNT(sxsh_nev_label_extension_fields),SX_LE};
static const xx_data_struct_field_desc sxsh_nev_spike_fields[] = {
    SX_FIELD("timestamp","uint32",0,4,SX_NONE),
    SX_FIELD("packet_id","uint16",4,2,SX_ID),
    SX_FIELD("unit_id","uint8",6,1,SX_ID),
    SX_FIELD("reserved","uint8",7,1,SX_RESERVED),
};
const sx_layout sxsh_nev_spike = {UINT32_C(0x602a000a),"nev_spike",sxsh_nev_spike_fields,SX_COUNT(sxsh_nev_spike_fields),SX_LE};
static const xx_data_struct_field_desc sxsh_nev_digital_fields[] = {
    SX_FIELD("timestamp","uint32",0,4,SX_NONE),
    SX_FIELD("packet_id","uint16",4,2,SX_ID),
    SX_FIELD("reason","uint8",6,1,SX_FLAGS),
    SX_FIELD("reserved","uint8",7,1,SX_RESERVED),
    SX_FIELD("digital_value","uint16",8,2,SX_FLAGS),
};
const sx_layout sxsh_nev_digital = {UINT32_C(0x602a000b),"nev_digital",sxsh_nev_digital_fields,SX_COUNT(sxsh_nev_digital_fields),SX_LE};
static bool sxsh_nev(sx_context *c)
{
 uint8_t b[336];if(!sx_read(c,0,b,336)||xx_rt_memcmp(b,"NEURALEV",8))return false;
 uint32_t header=sxsh32(b+12,false),packet=sxsh32(b+16,false),count=sxsh32(b+332,false);
 if(count>1024||header!=336U+count*32U||packet<8||packet>65536||!sxsh_add(c,&sxsh_nev_header,0,336))return false;
 for(uint32_t i=0;i<count;i++){
  int64_t at=336+(int64_t)i*32;if(!sx_read(c,at,b,32))return false;const sx_layout *l=&sxsh_nev_extension;
  if(!xx_rt_memcmp(b,"NEUEVWAV",8))l=&sxsh_nev_waveform_extension;else if(!xx_rt_memcmp(b,"NEUEVLBL",8))l=&sxsh_nev_label_extension;else if(!xx_rt_memcmp(b,"NEUEVFLT",8))l=&sxsh_nev_filter_extension;
  else if(!xx_rt_memcmp(b,"ARRAYNME",8)||!xx_rt_memcmp(b,"ECOMMENT",8)||!xx_rt_memcmp(b,"CCOMMENT",8))l=&sxsh_nev_text_extension;
  if(!sxsh_add(c,l,at,32))return false;
 }
 int64_t at=header;
 for(unsigned i=0;at<c->size;i++){
  if(i>=4095||!sxsh_span(c,at,packet)||!sx_read(c,at,b,8))return false;bool digital=sxsh16(b+4,false)==0;
  if((digital&&packet<10)||!sxsh_add(c,digital?&sxsh_nev_digital:&sxsh_nev_spike,at,digital?10:8))return false;at+=packet;
 }return at==c->size;
}
bool sx_blackrock_nev_build(sx_context*c)
{
 bool ok=false;
 ok=sxsh_nev(c);
 return ok&&sxsh_finish(c);
}
