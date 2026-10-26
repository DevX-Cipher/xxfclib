/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * emax disk data structures, moved out of the samplebanks schema family. */
#include "../../xx_format_schema_samplebanks.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsb_emaxutil_marker_fields[] = {
    SX_FIELD("producer_marker","char[39]",0,39,SX_SIGNATURE),
};
const sx_layout sxsb_emaxutil_marker = {0x603a0001U,"emaxutil_marker",sxsb_emaxutil_marker_fields,SX_COUNT(sxsb_emaxutil_marker_fields),SX_LE};
static const xx_data_struct_field_desc sxsb_emax_bank_header_fields[] = {
    SX_FIELD("preset_addresses","uint16[100]",0,200,SX_ADDRESS),
    SX_FIELD("allocation_address","uint16",200,2,SX_ADDRESS),
    SX_FIELD("unknown_0ca","uint16",202,2,SX_NONE),
    SX_FIELD("unknown_0cc","uint32",204,4,SX_NONE),
    SX_FIELD("selected_preset","uint32",208,4,SX_NONE),
    SX_FIELD("sequence_addresses","uint32[51]",212,204,SX_ADDRESS),
    SX_FIELD("lowest_sample_entry_address","uint32",416,4,SX_ADDRESS),
    SX_FIELD("highest_sample_entry_address","uint32",420,4,SX_ADDRESS),
    SX_FIELD("sample_memory_bytes_used","uint32",424,4,SX_SIZE),
};
const sx_layout sxsb_emax_bank_header = {0x603a0002U,"emax_bank_header",sxsb_emax_bank_header_fields,SX_COUNT(sxsb_emax_bank_header_fields),SX_LE};
static const xx_data_struct_field_desc sxsb_emax_preset_header_fields[] = {
    SX_FIELD("name","char[12]",0,12,SX_NONE),
    SX_FIELD("opaque_preset_parameters","byte[23]",12,23,SX_NONE),
    SX_FIELD("key_area_count","uint8",35,1,SX_COUNT_PROP),
    SX_FIELD("key_area_map","uint8[88]",36,88,SX_NONE),
};
const sx_layout sxsb_emax_preset_header = {0x603a0003U,"emax_preset_header",sxsb_emax_preset_header_fields,SX_COUNT(sxsb_emax_preset_header_fields),SX_LE};
static const xx_data_struct_field_desc sxsb_emax_key_area_fields[] = {
    SX_FIELD("flags","uint8",0,1,SX_FLAGS),
    SX_FIELD("velocity_crossfade_encoded","uint8",1,1,SX_NONE),
    SX_FIELD("primary_voice","uint8",2,1,SX_NONE),
    SX_FIELD("secondary_voice","uint8",3,1,SX_NONE),
};
const sx_layout sxsb_emax_key_area = {0x603a0004U,"emax_key_area",sxsb_emax_key_area_fields,SX_COUNT(sxsb_emax_key_area_fields),SX_LE};
static const xx_data_struct_field_desc sxsb_emax_voice_fields[] = {
    SX_FIELD("amplitude_envelope_and_lfo_rate","uint32",0,4,SX_FLAGS),
    SX_FIELD("lfo_tuning_and_velocity","uint32",4,4,SX_FLAGS),
    SX_FIELD("level_velocity_and_chorus","uint32",8,4,SX_FLAGS),
    SX_FIELD("original_key","uint8",12,1,SX_NONE),
    SX_FIELD("sample_index","uint8",13,1,SX_NONE),
    SX_FIELD("opaque_0e","byte[2]",14,2,SX_NONE),
    SX_FIELD("filter_cutoff_encoded","uint8",16,1,SX_FLAGS),
    SX_FIELD("filter_q_encoded","uint8",17,1,SX_FLAGS),
    SX_FIELD("filter_envelope_amount_encoded","uint8",18,1,SX_FLAGS),
    SX_FIELD("opaque_13","uint8",19,1,SX_NONE),
    SX_FIELD("filter_envelope_and_flags","uint32",20,4,SX_FLAGS),
    SX_FIELD("keyboard_tracking_and_pan","uint8",24,1,SX_FLAGS),
    SX_FIELD("lfo_filter_encoded","uint8",25,1,SX_FLAGS),
    SX_FIELD("delay_attenuation_chorus","uint16",26,2,SX_FLAGS),
    SX_FIELD("opaque_1c","byte[4]",28,4,SX_NONE),
};
const sx_layout sxsb_emax_voice = {0x603a0005U,"emax_voice",sxsb_emax_voice_fields,SX_COUNT(sxsb_emax_voice_fields),SX_LE};
static const xx_data_struct_field_desc sxsb_emax_sample_entry_fields[] = {
    SX_FIELD("unused_00","uint32",0,4,SX_NONE),
    SX_FIELD("sample_start","uint32",4,4,SX_ADDRESS),
    SX_FIELD("sample_end","uint32",8,4,SX_ADDRESS),
    SX_FIELD("sustain_loop_start","uint32",12,4,SX_ADDRESS),
    SX_FIELD("sustain_loop_end","uint32",16,4,SX_ADDRESS),
    SX_FIELD("release_loop_start","uint32",20,4,SX_ADDRESS),
    SX_FIELD("release_loop_end","uint32",24,4,SX_ADDRESS),
    SX_FIELD("flags","uint8",28,1,SX_FLAGS),
    SX_FIELD("sample_rate_index","uint8",29,1,SX_ID),
    SX_FIELD("unused_1e","uint16",30,2,SX_NONE),
};
const sx_layout sxsb_emax_sample_entry = {0x603a0006U,"emax_sample_entry",sxsb_emax_sample_entry_fields,SX_COUNT(sxsb_emax_sample_entry_fields),SX_LE};
#define SXSB_ADD(c,l,p) sxsb_put(c,&sxsb_##l,p,1)
#define SXSB_TABLE(c,l,p,n) sxsb_put(c,&sxsb_##l,p,n)
static bool sxsb_emax(sx_context*c){
 uint8_t h[428],p[124],a[4],v[32];const uint64_t origin=39;
 if(c->size!=552999||!sxsb_read(c,origin,h,sizeof(h))||!SXSB_ADD(c,emaxutil_marker,0)||!SXSB_ADD(c,emax_bank_header,origin))return false;
 uint32_t low=sxsb32(h+416),high=sxsb32(h+420);
 if(low<0x81ac||low>0xf000||high!=0xefe0||(0xf000-low)%32)return true;
 uint64_t directory=low-0x8000,samples=(0xf000-low)/32;
 if(samples&&!SXSB_TABLE(c,emax_sample_entry,origin+directory,samples))return false;
 for(unsigned slot=0;slot<100;slot++){
  uint32_t at=sxsb16(h+slot*2);if(at<0x81ac||at>=low)continue;
  uint64_t off=at-0x8000;if(directory-off<124||!sxsb_read(c,origin+off,p,124))continue;
  bool valid=true,nonblank=false;for(unsigned i=0;i<12;i++){if(p[i]<32||p[i]>126)valid=false;if(p[i]!=32)nonblank=true;}
  unsigned areas=p[35],voices=0;if(!valid||!nonblank||!areas||areas>88||directory-off<124+(uint64_t)areas*4)continue;
  for(unsigned i=0;i<88;i++)if(p[36+i]!=255&&p[36+i]>=areas)valid=false;
  if(!valid)continue;
  for(unsigned i=0;i<areas;i++){
   if(!sxsb_read(c,origin+off+124+4*i,a,4))return false;
   if(a[2]==255){valid=false;break;}if((unsigned)a[2]+1>voices)voices=(unsigned)a[2]+1;
   if(a[0]&16){if(a[3]==255){valid=false;break;}if((unsigned)a[3]+1>voices)voices=(unsigned)a[3]+1;}
  }
  uint64_t vo=off+124+4*areas,end=vo+(uint64_t)voices*32;
  if(!valid||end>directory)continue;
  for(unsigned i=0;i<voices;i++){if(!sxsb_read(c,origin+vo+i*32,v,32))return false;if(v[12]>=88||v[13]>=samples){valid=false;break;}}
  if(!valid)continue;
  /* Repeated and overlapping stale pointer slots do not create overlapping rows. */
  bool overlap=false;for(size_t i=0;i<c->count;i++){uint64_t x=(uint64_t)(c->items[i].offset-c->f->base_address),z=(uint64_t)c->items[i].total_size;if(x<origin+end&&origin+off<x+z){overlap=true;break;}}
  if(overlap)continue;
  if(!SXSB_ADD(c,emax_preset_header,origin+off)||!SXSB_TABLE(c,emax_key_area,origin+off+124,areas)||!SXSB_TABLE(c,emax_voice,origin+vo,voices))return false;
 }
 return true;
}
#undef SXSB_ADD
#undef SXSB_TABLE
bool sx_emax_disk_build(sx_context*c)
{
 return sxsb_emax(c);
}
