/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * mp4 data structures, moved out of the videotail schema family. */
#include "../../xx_format_schema_videotail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxvt_mp4_box_fields[] = {
 SX_FIELD("box_size","uint32",0,4,SX_SIZE),
 SX_FIELD("type","char[4]",4,4,SX_ID),
};
const sx_layout sxvt_mp4_box = {UINT32_C(0x6039002a),"mp4_box",sxvt_mp4_box_fields,SX_COUNT(sxvt_mp4_box_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_box64_fields[] = {
 SX_FIELD("box_size","uint32",0,4,SX_NONE),
 SX_FIELD("type","char[4]",4,4,SX_ID),
 SX_FIELD("extended_size","uint64",8,8,SX_SIZE),
};
const sx_layout sxvt_mp4_box64 = {UINT32_C(0x6039002b),"mp4_box64",sxvt_mp4_box64_fields,SX_COUNT(sxvt_mp4_box64_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_uuid_fields[] = {
 SX_FIELD("user_type","uint8[16]",0,16,SX_ID),
};
const sx_layout sxvt_mp4_uuid = {UINT32_C(0x6039002c),"mp4_uuid",sxvt_mp4_uuid_fields,SX_COUNT(sxvt_mp4_uuid_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_ftyp_fields[] = {
 SX_FIELD("major_brand","char[4]",0,4,SX_ID),
 SX_FIELD("minor_version","uint32",4,4,SX_ID),
};
const sx_layout sxvt_mp4_ftyp = {UINT32_C(0x6039002d),"mp4_ftyp",sxvt_mp4_ftyp_fields,SX_COUNT(sxvt_mp4_ftyp_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_brand_fields[] = {
 SX_FIELD("compatible_brand","char[4]",0,4,SX_ID),
};
const sx_layout sxvt_mp4_brand = {UINT32_C(0x6039002e),"mp4_brand",sxvt_mp4_brand_fields,SX_COUNT(sxvt_mp4_brand_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_mvhd_v0_fields[] = {
 SX_FIELD("version","uint8",0,1,SX_ID),
 SX_FIELD("flags","uint24",1,3,SX_FLAGS),
 SX_FIELD("creation_time","uint32",4,4,SX_NONE),
 SX_FIELD("modification_time","uint32",8,4,SX_NONE),
 SX_FIELD("timescale","uint32",12,4,SX_NONE),
 SX_FIELD("duration","uint32",16,4,SX_NONE),
 SX_FIELD("rate_fixed16","int32",20,4,SX_NONE),
 SX_FIELD("volume_fixed8","int16",24,2,SX_NONE),
 SX_FIELD("reserved0","uint16",26,2,SX_RESERVED),
 SX_FIELD("reserved1","uint32[2]",28,8,SX_RESERVED),
 SX_FIELD("matrix","int32[9]",36,36,SX_NONE),
 SX_FIELD("pre_defined","uint32[6]",72,24,SX_RESERVED),
 SX_FIELD("next_track_id","uint32",96,4,SX_ID),
};
const sx_layout sxvt_mp4_mvhd_v0 = {UINT32_C(0x6039002f),"mp4_mvhd_v0",sxvt_mp4_mvhd_v0_fields,SX_COUNT(sxvt_mp4_mvhd_v0_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_tkhd_v0_fields[] = {
 SX_FIELD("version","uint8",0,1,SX_ID),
 SX_FIELD("flags","uint24",1,3,SX_FLAGS),
 SX_FIELD("creation_time","uint32",4,4,SX_NONE),
 SX_FIELD("modification_time","uint32",8,4,SX_NONE),
 SX_FIELD("track_id","uint32",12,4,SX_ID),
 SX_FIELD("reserved0","uint32",16,4,SX_RESERVED),
 SX_FIELD("duration","uint32",20,4,SX_NONE),
 SX_FIELD("reserved1","uint32[2]",24,8,SX_RESERVED),
 SX_FIELD("layer","int16",32,2,SX_NONE),
 SX_FIELD("alternate_group","int16",34,2,SX_ID),
 SX_FIELD("volume_fixed8","int16",36,2,SX_NONE),
 SX_FIELD("reserved2","uint16",38,2,SX_RESERVED),
 SX_FIELD("matrix","int32[9]",40,36,SX_NONE),
 SX_FIELD("width_fixed16","uint32",76,4,SX_NONE),
 SX_FIELD("height_fixed16","uint32",80,4,SX_NONE),
};
const sx_layout sxvt_mp4_tkhd_v0 = {UINT32_C(0x60390030),"mp4_tkhd_v0",sxvt_mp4_tkhd_v0_fields,SX_COUNT(sxvt_mp4_tkhd_v0_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_mdhd_v0_fields[] = {
 SX_FIELD("version","uint8",0,1,SX_ID),
 SX_FIELD("flags","uint24",1,3,SX_FLAGS),
 SX_FIELD("creation_time","uint32",4,4,SX_NONE),
 SX_FIELD("modification_time","uint32",8,4,SX_NONE),
 SX_FIELD("timescale","uint32",12,4,SX_NONE),
 SX_FIELD("duration","uint32",16,4,SX_NONE),
 SX_FIELD("language","uint16",20,2,SX_FLAGS),
 SX_FIELD("pre_defined","uint16",22,2,SX_RESERVED),
};
const sx_layout sxvt_mp4_mdhd_v0 = {UINT32_C(0x60390031),"mp4_mdhd_v0",sxvt_mp4_mdhd_v0_fields,SX_COUNT(sxvt_mp4_mdhd_v0_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_elst_entry_v0_fields[] = {
 SX_FIELD("segment_duration","uint32",0,4,SX_NONE),
 SX_FIELD("media_time","int32",4,4,SX_NONE),
 SX_FIELD("media_rate_integer","int16",8,2,SX_NONE),
 SX_FIELD("media_rate_fraction","int16",10,2,SX_NONE),
};
const sx_layout sxvt_mp4_elst_entry_v0 = {UINT32_C(0x60390032),"mp4_elst_entry_v0",sxvt_mp4_elst_entry_v0_fields,SX_COUNT(sxvt_mp4_elst_entry_v0_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_mvhd_v1_fields[] = {
 SX_FIELD("version","uint8",0,1,SX_ID),
 SX_FIELD("flags","uint24",1,3,SX_FLAGS),
 SX_FIELD("creation_time","uint64",4,8,SX_NONE),
 SX_FIELD("modification_time","uint64",12,8,SX_NONE),
 SX_FIELD("timescale","uint32",20,4,SX_NONE),
 SX_FIELD("duration","uint64",24,8,SX_NONE),
 SX_FIELD("rate_fixed16","int32",32,4,SX_NONE),
 SX_FIELD("volume_fixed8","int16",36,2,SX_NONE),
 SX_FIELD("reserved0","uint16",38,2,SX_RESERVED),
 SX_FIELD("reserved1","uint32[2]",40,8,SX_RESERVED),
 SX_FIELD("matrix","int32[9]",48,36,SX_NONE),
 SX_FIELD("pre_defined","uint32[6]",84,24,SX_RESERVED),
 SX_FIELD("next_track_id","uint32",108,4,SX_ID),
};
const sx_layout sxvt_mp4_mvhd_v1 = {UINT32_C(0x60390033),"mp4_mvhd_v1",sxvt_mp4_mvhd_v1_fields,SX_COUNT(sxvt_mp4_mvhd_v1_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_tkhd_v1_fields[] = {
 SX_FIELD("version","uint8",0,1,SX_ID),
 SX_FIELD("flags","uint24",1,3,SX_FLAGS),
 SX_FIELD("creation_time","uint64",4,8,SX_NONE),
 SX_FIELD("modification_time","uint64",12,8,SX_NONE),
 SX_FIELD("track_id","uint32",20,4,SX_ID),
 SX_FIELD("reserved0","uint32",24,4,SX_RESERVED),
 SX_FIELD("duration","uint64",28,8,SX_NONE),
 SX_FIELD("reserved1","uint32[2]",36,8,SX_RESERVED),
 SX_FIELD("layer","int16",44,2,SX_NONE),
 SX_FIELD("alternate_group","int16",46,2,SX_ID),
 SX_FIELD("volume_fixed8","int16",48,2,SX_NONE),
 SX_FIELD("reserved2","uint16",50,2,SX_RESERVED),
 SX_FIELD("matrix","int32[9]",52,36,SX_NONE),
 SX_FIELD("width_fixed16","uint32",88,4,SX_NONE),
 SX_FIELD("height_fixed16","uint32",92,4,SX_NONE),
};
const sx_layout sxvt_mp4_tkhd_v1 = {UINT32_C(0x60390034),"mp4_tkhd_v1",sxvt_mp4_tkhd_v1_fields,SX_COUNT(sxvt_mp4_tkhd_v1_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_mdhd_v1_fields[] = {
 SX_FIELD("version","uint8",0,1,SX_ID),
 SX_FIELD("flags","uint24",1,3,SX_FLAGS),
 SX_FIELD("creation_time","uint64",4,8,SX_NONE),
 SX_FIELD("modification_time","uint64",12,8,SX_NONE),
 SX_FIELD("timescale","uint32",20,4,SX_NONE),
 SX_FIELD("duration","uint64",24,8,SX_NONE),
 SX_FIELD("language","uint16",32,2,SX_FLAGS),
 SX_FIELD("pre_defined","uint16",34,2,SX_RESERVED),
};
const sx_layout sxvt_mp4_mdhd_v1 = {UINT32_C(0x60390035),"mp4_mdhd_v1",sxvt_mp4_mdhd_v1_fields,SX_COUNT(sxvt_mp4_mdhd_v1_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_elst_entry_v1_fields[] = {
 SX_FIELD("segment_duration","uint64",0,8,SX_NONE),
 SX_FIELD("media_time","int64",8,8,SX_NONE),
 SX_FIELD("media_rate_integer","int16",16,2,SX_NONE),
 SX_FIELD("media_rate_fraction","int16",18,2,SX_NONE),
};
const sx_layout sxvt_mp4_elst_entry_v1 = {UINT32_C(0x60390036),"mp4_elst_entry_v1",sxvt_mp4_elst_entry_v1_fields,SX_COUNT(sxvt_mp4_elst_entry_v1_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_hdlr_fields[] = {
 SX_FIELD("version","uint8",0,1,SX_ID),
 SX_FIELD("flags","uint24",1,3,SX_FLAGS),
 SX_FIELD("pre_defined","uint32",4,4,SX_NONE),
 SX_FIELD("handler_type","char[4]",8,4,SX_ID),
 SX_FIELD("reserved","uint32[3]",12,12,SX_RESERVED),
};
const sx_layout sxvt_mp4_hdlr = {UINT32_C(0x60390037),"mp4_hdlr",sxvt_mp4_hdlr_fields,SX_COUNT(sxvt_mp4_hdlr_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_table_fields[] = {
 SX_FIELD("version","uint8",0,1,SX_ID),
 SX_FIELD("flags","uint24",1,3,SX_FLAGS),
 SX_FIELD("entry_count","uint32",4,4,SX_COUNT_PROP),
};
const sx_layout sxvt_mp4_table = {UINT32_C(0x60390038),"mp4_table",sxvt_mp4_table_fields,SX_COUNT(sxvt_mp4_table_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_stsz_fields[] = {
 SX_FIELD("version","uint8",0,1,SX_ID),
 SX_FIELD("flags","uint24",1,3,SX_FLAGS),
 SX_FIELD("sample_size","uint32",4,4,SX_SIZE),
 SX_FIELD("sample_count","uint32",8,4,SX_COUNT_PROP),
};
const sx_layout sxvt_mp4_stsz = {UINT32_C(0x60390039),"mp4_stsz",sxvt_mp4_stsz_fields,SX_COUNT(sxvt_mp4_stsz_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_stco_fields[] = {
 SX_FIELD("chunk_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxvt_mp4_stco = {UINT32_C(0x6039003a),"mp4_stco",sxvt_mp4_stco_fields,SX_COUNT(sxvt_mp4_stco_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_co64_fields[] = {
 SX_FIELD("chunk_offset","uint64",0,8,SX_OFFSET),
};
const sx_layout sxvt_mp4_co64 = {UINT32_C(0x6039003b),"mp4_co64",sxvt_mp4_co64_fields,SX_COUNT(sxvt_mp4_co64_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_stts_fields[] = {
 SX_FIELD("sample_count","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("sample_delta","uint32",4,4,SX_NONE),
};
const sx_layout sxvt_mp4_stts = {UINT32_C(0x6039003c),"mp4_stts",sxvt_mp4_stts_fields,SX_COUNT(sxvt_mp4_stts_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_ctts_v0_fields[] = {
 SX_FIELD("sample_count","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("sample_offset","uint32",4,4,SX_NONE),
};
const sx_layout sxvt_mp4_ctts_v0 = {UINT32_C(0x6039003d),"mp4_ctts_v0",sxvt_mp4_ctts_v0_fields,SX_COUNT(sxvt_mp4_ctts_v0_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_ctts_v1_fields[] = {
 SX_FIELD("sample_count","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("sample_offset","int32",4,4,SX_NONE),
};
const sx_layout sxvt_mp4_ctts_v1 = {UINT32_C(0x6039003e),"mp4_ctts_v1",sxvt_mp4_ctts_v1_fields,SX_COUNT(sxvt_mp4_ctts_v1_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_stsc_fields[] = {
 SX_FIELD("first_chunk","uint32",0,4,SX_ID),
 SX_FIELD("samples_per_chunk","uint32",4,4,SX_COUNT_PROP),
 SX_FIELD("sample_description_index","uint32",8,4,SX_ID),
};
const sx_layout sxvt_mp4_stsc = {UINT32_C(0x6039003f),"mp4_stsc",sxvt_mp4_stsc_fields,SX_COUNT(sxvt_mp4_stsc_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_stss_fields[] = {
 SX_FIELD("sample_number","uint32",0,4,SX_ID),
};
const sx_layout sxvt_mp4_stss = {UINT32_C(0x60390040),"mp4_stss",sxvt_mp4_stss_fields,SX_COUNT(sxvt_mp4_stss_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_sample_size_fields[] = {
 SX_FIELD("sample_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxvt_mp4_sample_size = {UINT32_C(0x60390041),"mp4_sample_size",sxvt_mp4_sample_size_fields,SX_COUNT(sxvt_mp4_sample_size_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_sample_entry_fields[] = {
 SX_FIELD("reserved","uint8[6]",0,6,SX_RESERVED),
 SX_FIELD("data_reference_index","uint16",6,2,SX_ID),
};
const sx_layout sxvt_mp4_sample_entry = {UINT32_C(0x60390042),"mp4_sample_entry",sxvt_mp4_sample_entry_fields,SX_COUNT(sxvt_mp4_sample_entry_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_vmhd_fields[] = {
 SX_FIELD("version","uint8",0,1,SX_ID),
 SX_FIELD("flags","uint24",1,3,SX_FLAGS),
 SX_FIELD("graphics_mode","uint16",4,2,SX_ID),
 SX_FIELD("opcolour","uint16[3]",6,6,SX_NONE),
};
const sx_layout sxvt_mp4_vmhd = {UINT32_C(0x60390043),"mp4_vmhd",sxvt_mp4_vmhd_fields,SX_COUNT(sxvt_mp4_vmhd_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_smhd_fields[] = {
 SX_FIELD("version","uint8",0,1,SX_ID),
 SX_FIELD("flags","uint24",1,3,SX_FLAGS),
 SX_FIELD("balance_fixed8","int16",4,2,SX_NONE),
 SX_FIELD("reserved","uint16",6,2,SX_RESERVED),
};
const sx_layout sxvt_mp4_smhd = {UINT32_C(0x60390044),"mp4_smhd",sxvt_mp4_smhd_fields,SX_COUNT(sxvt_mp4_smhd_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_fullbox_fields[] = {
 SX_FIELD("version","uint8",0,1,SX_ID),
 SX_FIELD("flags","uint24",1,3,SX_FLAGS),
};
const sx_layout sxvt_mp4_fullbox = {UINT32_C(0x60390045),"mp4_fullbox",sxvt_mp4_fullbox_fields,SX_COUNT(sxvt_mp4_fullbox_fields),SX_BE};
#define SXVT_LIMIT 20000U
static bool sxvt_four(const uint8_t*a,const char*b){return !xx_rt_memcmp(a,b,4);}
static bool sxvt_mp4_container(const uint8_t*t){const char*const names[]={"moov","trak","mdia","minf","stbl","edts","dinf","mvex","moof","traf","mfra","udta"};for(size_t i=0;i<SX_COUNT(names);i++)if(sxvt_four(t,names[i]))return true;return false;}
static bool sxvt_mp4(sx_context*c,uint64_t p,uint64_t end,unsigned depth){if(depth>24)return false;while(p<end&&c->count<SXVT_LIMIT){uint8_t b[16];uint64_t n,z=8;if(end-p<8||!sxvt_read(c,p,b,8))return false;n=sxvt_uint(b,4,true);if(n==1){if(end-p<16||!sxvt_read(c,p+8,b+8,8))return false;n=sxvt_uint(b+8,8,true);z=16;}else if(!n)n=end-p;if(n<z||n>end-p)return false;if(!sxvt_add(c,z==8?&sxvt_mp4_box:&sxvt_mp4_box64,p))return false;uint64_t q=p+z,stop=p+n;if(sxvt_four(b+4,"uuid")){if(stop-q<16||!sxvt_add(c,&sxvt_mp4_uuid,q))return false;q+=16;}
 if(sxvt_mp4_container(b+4)){(void)sxvt_mp4(c,q,stop,depth+1);p=stop;continue;}const sx_layout*l=NULL,*entry=NULL;uint64_t es=0,count=0;uint8_t v=0;if(q<stop&&!sxvt_byte(c,q,&v))return false;
 if(sxvt_four(b+4,"ftyp")&&stop-q>=8){l=&sxvt_mp4_ftyp;entry=&sxvt_mp4_brand;es=4;count=(stop-q-8)/4;}
 else if(sxvt_four(b+4,"mvhd")&&v<2)l=v?&sxvt_mp4_mvhd_v1:&sxvt_mp4_mvhd_v0;
 else if(sxvt_four(b+4,"tkhd")&&v<2)l=v?&sxvt_mp4_tkhd_v1:&sxvt_mp4_tkhd_v0;
 else if(sxvt_four(b+4,"mdhd")&&v<2)l=v?&sxvt_mp4_mdhd_v1:&sxvt_mp4_mdhd_v0;
 else if(sxvt_four(b+4,"hdlr"))l=&sxvt_mp4_hdlr;
 else if(sxvt_four(b+4,"vmhd"))l=&sxvt_mp4_vmhd;
 else if(sxvt_four(b+4,"smhd"))l=&sxvt_mp4_smhd;
 else if(sxvt_four(b+4,"nmhd"))l=&sxvt_mp4_fullbox;
 else if(sxvt_four(b+4,"stsz")&&stop-q>=12){uint64_t sz;if(!sxvt_word(c,q+4,4,true,&sz)||!sxvt_word(c,q+8,4,true,&count))return false;l=&sxvt_mp4_stsz;if(!sz){es=4;entry=&sxvt_mp4_sample_size;}}
 else if(sxvt_four(b+4,"stco")){entry=&sxvt_mp4_stco;es=4;}
 else if(sxvt_four(b+4,"co64")){entry=&sxvt_mp4_co64;es=8;}
 else if(sxvt_four(b+4,"stts")){entry=&sxvt_mp4_stts;es=8;}
 else if(sxvt_four(b+4,"ctts")&&v<2){entry=v?&sxvt_mp4_ctts_v1:&sxvt_mp4_ctts_v0;es=8;}
 else if(sxvt_four(b+4,"stsc")){entry=&sxvt_mp4_stsc;es=12;}
 else if(sxvt_four(b+4,"stss")){entry=&sxvt_mp4_stss;es=4;}
 else if(sxvt_four(b+4,"elst")&&v<2){entry=v?&sxvt_mp4_elst_entry_v1:&sxvt_mp4_elst_entry_v0;es=v?20:12;}
 else if((sxvt_four(b+4,"stsd")||sxvt_four(b+4,"dref"))&&stop-q>=8){if(!sxvt_word(c,q+4,4,true,&count)||!sxvt_add(c,&sxvt_mp4_table,q))return false;uint64_t cur=q+8;for(uint64_t i=0;i<count&&c->count<SXVT_LIMIT;i++){uint8_t eb[8];if(cur>stop||stop-cur<8||!sxvt_read(c,cur,eb,8))break;uint64_t en=sxvt_uint(eb,4,true);if(en<8||en>stop-cur)break;if(!sxvt_add(c,&sxvt_mp4_box,cur))return false;if(sxvt_four(b+4,"stsd")&&en>=16&&!sxvt_add(c,&sxvt_mp4_sample_entry,cur+8))return false;if(sxvt_four(b+4,"dref")&&en>=12&&!sxvt_add(c,&sxvt_mp4_fullbox,cur+8))return false;cur+=en;}p=stop;continue;}
 if(entry&&!l){l=&sxvt_mp4_table;if(stop-q<8||!sxvt_word(c,q+4,4,true,&count)){p=stop;continue;}}
 if(l){const xx_data_struct_field_desc*f=&l->fields[l->field_count-1];uint64_t hs=(uint64_t)(f->rel_offset+f->size);if(hs<=stop-q){if(!sxvt_add(c,l,q))return false;if(entry&&es&&count<=(stop-q-hs)/es)for(uint64_t i=0;i<count;i++)if(!sxvt_add(c,entry,q+hs+i*es))return false;}}
 p=stop;}return p==end;}
bool sx_mp4_build(sx_context*c)
{
 return sxvt_mp4(c,0,(uint64_t)c->size,0);
}
