/* SPDX-License-Identifier: MIT
 * Physical Hippel, Kefrens and TFMX metadata. Playback bytecode and sample bodies remain raw.
 * See docs/data_struct_classicmusic_scope.txt for format-specific limits. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_classicmusic.h"
static const xx_data_struct_field_desc sxcmus_hippel_header_fields[]={
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("frequency_last_index","uint16",4,2,SX_NONE),
 SX_FIELD("envelope_last_index","uint16",6,2,SX_NONE),
 SX_FIELD("track_last_index","uint16",8,2,SX_NONE),
 SX_FIELD("position_last_index","uint16",10,2,SX_NONE),
 SX_FIELD("bytes_per_track","uint16",12,2,SX_SIZE),
 SX_FIELD("opaque_word","bytes",14,2,SX_NONE),
 SX_FIELD("subsong_count","uint16",16,2,SX_COUNT_PROP),
 SX_FIELD("sample_count","uint16",18,2,SX_COUNT_PROP),
 SX_FIELD("opaque_tail","bytes",20,12,SX_NONE),
};
static const sx_layout sxcmus_hippel_header={UINT32_C(0x609E0001),"hippel_header",sxcmus_hippel_header_fields,SX_COUNT(sxcmus_hippel_header_fields),SX_BE};
static const xx_data_struct_field_desc sxcmus_hippel_st_header_fields[]={
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("frequency_last_index","uint16",4,2,SX_NONE),
 SX_FIELD("envelope_last_index","uint16",6,2,SX_NONE),
 SX_FIELD("track_last_index","uint16",8,2,SX_NONE),
 SX_FIELD("position_last_index","uint16",10,2,SX_NONE),
 SX_FIELD("bytes_per_track","uint16",12,2,SX_SIZE),
 SX_FIELD("opaque_word","bytes",14,2,SX_NONE),
 SX_FIELD("subsong_count","uint16",16,2,SX_COUNT_PROP),
 SX_FIELD("waveform_last_index","uint16",18,2,SX_NONE),
 SX_FIELD("opaque_tail","bytes",20,12,SX_NONE),
};
static const sx_layout sxcmus_hippel_st_header={UINT32_C(0x609E0002),"hippel_st_header",sxcmus_hippel_st_header_fields,SX_COUNT(sxcmus_hippel_st_header_fields),SX_BE};
static const xx_data_struct_field_desc sxcmus_hippel_coso_fields[]={
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("frequency_table_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("envelope_table_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("track_table_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("position_table_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("subsong_table_offset","uint32",20,4,SX_OFFSET),
 SX_FIELD("sample_info_offset","uint32",24,4,SX_OFFSET),
 SX_FIELD("sample_data_offset","int32",28,4,SX_OFFSET),
};
static const sx_layout sxcmus_hippel_coso={UINT32_C(0x609E0003),"hippel_coso",sxcmus_hippel_coso_fields,SX_COUNT(sxcmus_hippel_coso_fields),SX_BE};
static const xx_data_struct_field_desc sxcmus_hippel_st_coso_fields[]={
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("frequency_table_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("envelope_table_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("track_table_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("position_table_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("subsong_table_offset","uint32",20,4,SX_OFFSET),
 SX_FIELD("waveform_table_offset","uint32",24,4,SX_OFFSET),
 SX_FIELD("digital_data_offset_or_marker","bytes",28,4,SX_NONE),
};
static const sx_layout sxcmus_hippel_st_coso={UINT32_C(0x609E0004),"hippel_st_coso",sxcmus_hippel_st_coso_fields,SX_COUNT(sxcmus_hippel_st_coso_fields),SX_BE};
static const xx_data_struct_field_desc sxcmus_hippel_pointer16_fields[]={
 SX_FIELD("data_offset","uint16",0,2,SX_OFFSET),
};
static const sx_layout sxcmus_hippel_pointer16={UINT32_C(0x609E0005),"hippel_pointer16",sxcmus_hippel_pointer16_fields,SX_COUNT(sxcmus_hippel_pointer16_fields),SX_BE};
static const xx_data_struct_field_desc sxcmus_hippel_pointer32_fields[]={
 SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxcmus_hippel_pointer32={UINT32_C(0x609E0006),"hippel_pointer32",sxcmus_hippel_pointer32_fields,SX_COUNT(sxcmus_hippel_pointer32_fields),SX_BE};
static const xx_data_struct_field_desc sxcmus_hippel_st_pointer16_fields[]={
 SX_FIELD("data_offset","int16",0,2,SX_OFFSET),
};
static const sx_layout sxcmus_hippel_st_pointer16={UINT32_C(0x609E0007),"hippel_st_pointer16",sxcmus_hippel_st_pointer16_fields,SX_COUNT(sxcmus_hippel_st_pointer16_fields),SX_BE};
static const xx_data_struct_field_desc sxcmus_hippel_envelope_fields[]={
 SX_FIELD("speed","uint8",0,1,SX_NONE),
 SX_FIELD("frequency_index","uint8",1,1,SX_NONE),
 SX_FIELD("vibrato_speed","uint8",2,1,SX_NONE),
 SX_FIELD("vibrato_depth","uint8",3,1,SX_NONE),
 SX_FIELD("vibrato_delay","uint8",4,1,SX_NONE),
};
static const sx_layout sxcmus_hippel_envelope={UINT32_C(0x609E0008),"hippel_envelope",sxcmus_hippel_envelope_fields,SX_COUNT(sxcmus_hippel_envelope_fields),SX_LE};
static const xx_data_struct_field_desc sxcmus_hippel_position_fields[]={
 SX_FIELD("track_index","uint8",0,1,SX_NONE),
 SX_FIELD("note_transpose","int8",1,1,SX_NONE),
 SX_FIELD("envelope_transpose","int8",2,1,SX_NONE),
};
static const sx_layout sxcmus_hippel_position={UINT32_C(0x609E0009),"hippel_position",sxcmus_hippel_position_fields,SX_COUNT(sxcmus_hippel_position_fields),SX_LE};
static const xx_data_struct_field_desc sxcmus_hippel_position_control_fields[]={
 SX_FIELD("track_index","uint8",0,1,SX_NONE),
 SX_FIELD("note_transpose","int8",1,1,SX_NONE),
 SX_FIELD("envelope_transpose","int8",2,1,SX_NONE),
 SX_FIELD("command","uint8",3,1,SX_NONE),
};
static const sx_layout sxcmus_hippel_position_control={UINT32_C(0x609E000A),"hippel_position_control",sxcmus_hippel_position_control_fields,SX_COUNT(sxcmus_hippel_position_control_fields),SX_LE};
static const xx_data_struct_field_desc sxcmus_hippel_subsong_fields[]={
 SX_FIELD("first_position","uint16",0,2,SX_NONE),
 SX_FIELD("last_position","uint16",2,2,SX_NONE),
 SX_FIELD("start_speed","uint16",4,2,SX_NONE),
};
static const sx_layout sxcmus_hippel_subsong={UINT32_C(0x609E000B),"hippel_subsong",sxcmus_hippel_subsong_fields,SX_COUNT(sxcmus_hippel_subsong_fields),SX_BE};
static const xx_data_struct_field_desc sxcmus_hippel_subsong7_fields[]={
 SX_FIELD("first_position","uint16",0,2,SX_NONE),
 SX_FIELD("last_position","uint16",2,2,SX_NONE),
 SX_FIELD("opaque_word","bytes",4,2,SX_NONE),
 SX_FIELD("start_speed","uint16",6,2,SX_NONE),
};
static const sx_layout sxcmus_hippel_subsong7={UINT32_C(0x609E000C),"hippel_subsong7",sxcmus_hippel_subsong7_fields,SX_COUNT(sxcmus_hippel_subsong7_fields),SX_BE};
static const xx_data_struct_field_desc sxcmus_hippel_sample7_fields[]={
 SX_FIELD("name","char[18]",0,18,SX_NONE),
 SX_FIELD("sample_data_offset","uint32",18,4,SX_OFFSET),
 SX_FIELD("length_words","uint16",22,2,SX_NONE),
 SX_FIELD("volume_word","uint16",24,2,SX_NONE),
 SX_FIELD("loop_start","uint16",26,2,SX_OFFSET),
 SX_FIELD("loop_length_words","uint16",28,2,SX_NONE),
};
static const sx_layout sxcmus_hippel_sample7={UINT32_C(0x609E000D),"hippel_sample7",sxcmus_hippel_sample7_fields,SX_COUNT(sxcmus_hippel_sample7_fields),SX_BE};
static const xx_data_struct_field_desc sxcmus_hippel_sample_coso_fields[]={
 SX_FIELD("sample_data_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("length_words","uint16",4,2,SX_NONE),
 SX_FIELD("loop_start","uint16",6,2,SX_OFFSET),
 SX_FIELD("loop_length_words","uint16",8,2,SX_NONE),
};
static const sx_layout sxcmus_hippel_sample_coso={UINT32_C(0x609E000E),"hippel_sample_coso",sxcmus_hippel_sample_coso_fields,SX_COUNT(sxcmus_hippel_sample_coso_fields),SX_BE};
static const xx_data_struct_field_desc sxcmus_kefrens_sample_fields[]={
 SX_FIELD("opaque_prefix","bytes",0,16,SX_NONE),
 SX_FIELD("sample_data_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("byte_length","uint16",20,2,SX_SIZE),
 SX_FIELD("volume","uint8",22,1,SX_NONE),
 SX_FIELD("opaque_byte","bytes",23,1,SX_NONE),
 SX_FIELD("loop_start","uint16",24,2,SX_OFFSET),
 SX_FIELD("opaque_tail","bytes",26,6,SX_NONE),
};
const sx_layout sxcmus_kefrens_sample={UINT32_C(0x609E0010),"kefrens_sample",sxcmus_kefrens_sample_fields,SX_COUNT(sxcmus_kefrens_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxcmus_kefrens_end_fields[]={
 SX_FIELD("marker","uint8",0,1,SX_NONE),
};
const sx_layout sxcmus_kefrens_end={UINT32_C(0x609E0012),"kefrens_end",sxcmus_kefrens_end_fields,SX_COUNT(sxcmus_kefrens_end_fields),SX_LE};
static const xx_data_struct_field_desc sxcmus_kefrens_cell_fields[]={
 SX_FIELD("note_index","uint8",0,1,SX_NONE),
 SX_FIELD("sample_and_effect","uint8",1,1,SX_NONE),
 SX_FIELD("parameter","uint8",2,1,SX_NONE),
};
const sx_layout sxcmus_kefrens_cell={UINT32_C(0x609E0013),"kefrens_cell",sxcmus_kefrens_cell_fields,SX_COUNT(sxcmus_kefrens_cell_fields),SX_LE};
static const xx_data_struct_field_desc sxcmus_tfmx_tfhd_fields[]={
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("header_byte_length","uint32",4,4,SX_SIZE),
 SX_FIELD("player_type","uint8",8,1,SX_ID),
 SX_FIELD("wrapper_version","uint8",9,1,SX_ID),
 SX_FIELD("music_byte_length","uint32",10,4,SX_SIZE),
 SX_FIELD("sample_byte_length","uint32",14,4,SX_SIZE),
};
const sx_layout sxcmus_tfmx_tfhd={UINT32_C(0x609E0014),"tfmx_tfhd",sxcmus_tfmx_tfhd_fields,SX_COUNT(sxcmus_tfmx_tfhd_fields),SX_BE};
static const xx_data_struct_field_desc sxcmus_tfmx_song_end_fields[]={
 SX_FIELD("last_track_step","uint16",0,2,SX_NONE),
};
const sx_layout sxcmus_tfmx_song_end={UINT32_C(0x609E0019),"tfmx_song_end",sxcmus_tfmx_song_end_fields,SX_COUNT(sxcmus_tfmx_song_end_fields),SX_BE};
static const xx_data_struct_field_desc sxcmus_tfmx_song_tempo_fields[]={
 SX_FIELD("tempo_word","uint16",0,2,SX_NONE),
};
const sx_layout sxcmus_tfmx_song_tempo={UINT32_C(0x609E001A),"tfmx_song_tempo",sxcmus_tfmx_song_tempo_fields,SX_COUNT(sxcmus_tfmx_song_tempo_fields),SX_BE};
static const xx_data_struct_field_desc sxcmus_tfmx_track_mute_fields[]={
 SX_FIELD("mute_word","uint16",0,2,SX_NONE),
};
const sx_layout sxcmus_tfmx_track_mute={UINT32_C(0x609E001B),"tfmx_track_mute",sxcmus_tfmx_track_mute_fields,SX_COUNT(sxcmus_tfmx_track_mute_fields),SX_BE};
static const xx_data_struct_field_desc sxcmus_tfmx_tables_be_fields[]={
 SX_FIELD("track_table_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("pattern_table_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("macro_table_offset","uint32",8,4,SX_OFFSET),
};
const sx_layout sxcmus_tfmx_tables_be={UINT32_C(0x609E001C),"tfmx_tables_be",sxcmus_tfmx_tables_be_fields,SX_COUNT(sxcmus_tfmx_tables_be_fields),SX_BE};
static const xx_data_struct_field_desc sxcmus_tfmx_tables_le_fields[]={
 SX_FIELD("track_table_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("pattern_table_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("macro_table_offset","uint32",8,4,SX_OFFSET),
};
const sx_layout sxcmus_tfmx_tables_le={UINT32_C(0x609E001D),"tfmx_tables_le",sxcmus_tfmx_tables_le_fields,SX_COUNT(sxcmus_tfmx_tables_le_fields),SX_LE};
static const xx_data_struct_field_desc sxcmus_tfmx_pointer_fields[]={
 SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxcmus_tfmx_pointer={UINT32_C(0x609E001E),"tfmx_pointer",sxcmus_tfmx_pointer_fields,SX_COUNT(sxcmus_tfmx_pointer_fields),SX_BE};
static const xx_data_struct_field_desc sxcmus_tfmx_track_channel_fields[]={
 SX_FIELD("pattern_or_control","uint8",0,1,SX_NONE),
 SX_FIELD("transpose","int8",1,1,SX_NONE),
};
const sx_layout sxcmus_tfmx_track_channel={UINT32_C(0x609E001F),"tfmx_track_channel",sxcmus_tfmx_track_channel_fields,SX_COUNT(sxcmus_tfmx_track_channel_fields),SX_LE};
static const xx_data_struct_field_desc sxcmus_tfmx_track_command_fields[]={
 SX_FIELD("marker","uint16",0,2,SX_ID),
 SX_FIELD("command","uint16",2,2,SX_ID),
 SX_FIELD("parameters","bytes",4,12,SX_NONE),
};
const sx_layout sxcmus_tfmx_track_command={UINT32_C(0x609E0020),"tfmx_track_command",sxcmus_tfmx_track_command_fields,SX_COUNT(sxcmus_tfmx_track_command_fields),SX_BE};
static const xx_data_struct_field_desc sxcmus_tfmx_mod_tag_fields[]={
 SX_FIELD("tag_id","uint8",0,1,SX_ID),
 SX_FIELD("declared_length","uint16",1,2,SX_NONE),
};
const sx_layout sxcmus_tfmx_mod_tag={UINT32_C(0x609E0021),"tfmx_mod_tag",sxcmus_tfmx_mod_tag_fields,SX_COUNT(sxcmus_tfmx_mod_tag_fields),SX_LE};
static const sx_layout *const sx_classicmusic_layouts[]={
 &sxcmus_hippel_header,
 &sxcmus_hippel_st_header,
 &sxcmus_hippel_coso,
 &sxcmus_hippel_st_coso,
 &sxcmus_hippel_pointer16,
 &sxcmus_hippel_pointer32,
 &sxcmus_hippel_st_pointer16,
 &sxcmus_hippel_envelope,
 &sxcmus_hippel_position,
 &sxcmus_hippel_position_control,
 &sxcmus_hippel_subsong,
 &sxcmus_hippel_subsong7,
 &sxcmus_hippel_sample7,
 &sxcmus_hippel_sample_coso,
 &sxcmus_kefrens_header,
 &sxcmus_kefrens_sample,
 &sxcmus_kefrens_order,
 &sxcmus_kefrens_end,
 &sxcmus_kefrens_cell,
 &sxcmus_tfmx_tfhd,
 &sxcmus_tfmx_mod_wrapper,
 &sxcmus_tfmx_prefix,
 &sxcmus_tfmx_comment,
 &sxcmus_tfmx_song_start,
 &sxcmus_tfmx_song_end,
 &sxcmus_tfmx_song_tempo,
 &sxcmus_tfmx_track_mute,
 &sxcmus_tfmx_tables_be,
 &sxcmus_tfmx_tables_le,
 &sxcmus_tfmx_pointer,
 &sxcmus_tfmx_track_channel,
 &sxcmus_tfmx_track_command,
 &sxcmus_tfmx_mod_tag,
};
#define SXCMUS_LIMIT 24000U
bool sxcmus_span(sx_context*c,uint64_t p,uint64_t n){return c&&c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p&&!xx_pd_is_stopped(c->pd);}
bool sxcmus_read(sx_context*c,uint64_t p,void*b,size_t n){return sxcmus_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
bool sxcmus_eq(sx_context*c,uint64_t p,const char*s,size_t n){uint8_t b[64];return n<=sizeof(b)&&sxcmus_read(c,p,b,n)&&!xx_rt_memcmp(b,s,n);}
static uint64_t sxcmus_width(const sx_layout*l){const xx_data_struct_field_desc*f=l->fields+l->field_count-1;return (uint64_t)f->rel_offset+(uint64_t)f->size;}
/* Insert only disjoint physical records. Shared pointers are decoded once;
 * conflicting interpretations remain covered by the first authenticated row.
 * Display-budget exhaustion retains earlier metadata and raw remainder. */
bool sxcmus_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t count){
 uint64_t z=sxcmus_width(l);if(!count)return true;if(!z||count>UINT64_MAX/z||!sxcmus_span(c,p,count*z))return false;
 if(c->count>=SXCMUS_LIMIT)return true;
 uint64_t end=p+count*z;
 for(size_t i=0;i<c->count;i++){int64_t rel=c->items[i].offset-c->f->base_address;uint64_t n=(uint64_t)c->items[i].total_size;
  if(rel>=0&&p<(uint64_t)rel+n&&(uint64_t)rel<end)return true;}
 return count==1?sx_add(c,l,(int64_t)p,(int64_t)z):sx_table(c,l,(int64_t)p,(int64_t)z,(int64_t)count);
}
#define SXCMUS_ADD(c,n,p) sxcmus_put(c,&sxcmus_##n,p,1)
static bool sxcmus_opt(sx_context*c,const sx_layout*l,uint64_t p,uint64_t count){uint64_t z=sxcmus_width(l);return !count||!z||count>UINT64_MAX/z||!sxcmus_span(c,p,count*z)?true:sxcmus_put(c,l,p,count);}
static int sxcmus_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset;}
static bool sxcmus_finish(sx_context*c){size_t n=c->count;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxcmus_order);for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(p<end||z<=0||p>c->size||z>c->size-p)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+z;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxcmus_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
static uint16_t sxcmus_be16(const uint8_t*b){return (uint16_t)((uint16_t)b[0]<<8)|b[1];}
uint32_t sxcmus_be32(const uint8_t*b){return (uint32_t)b[0]<<24|(uint32_t)b[1]<<16|(uint32_t)b[2]<<8|b[3];}
bool sxcmus_word(sx_context*c,uint64_t p,uint16_t*v){uint8_t b[2];if(!sxcmus_read(c,p,b,2))return false;*v=sxcmus_be16(b);return true;}
/* All coordinates below are physical source bytes. No replayer is executed and
 * no pointer is resolved against decompressed or external sample storage. */
static bool sxcmus_hippel_origin(sx_context*c,unsigned kind,uint64_t*out){
 if(kind==1){if(!sxcmus_eq(c,0,"COSO",4))return false;*out=0;return true;}
 if(sxcmus_eq(c,0,"TFMX",4)||(kind==2&&sxcmus_eq(c,0,"COSO",4))){*out=0;return true;}
 if(kind==0&&sxcmus_eq(c,0,"\x60\0",2)){
  uint16_t d;if(!sxcmus_word(c,2,&d)||!d||d>=0x8000||(d&1))return false;
  uint64_t p=2U+d;for(unsigned i=0;i<20;i++){
   if(sxcmus_eq(c,p+i,"\x30\x81\x41\xfa",4)&&sxcmus_word(c,p+i+4,&d)&&d&&d<0x8000&&!(d&1)&&sxcmus_eq(c,p+i+4+d,"TFMX",4)){*out=p+i+4+d;return true;}
  }
 }else if(kind==2){
  for(unsigned i=0;i<127;i++){
   uint64_t p=2U*i;uint16_t d;if(sxcmus_eq(c,p,"\x41\xfa",2)&&sxcmus_word(c,p+2,&d)&&d<0x8000&&!(d&1)){
    uint64_t q=p+2+d;if(sxcmus_eq(c,q,"TFMX",4)||sxcmus_eq(c,q,"COSO",4)){*out=q;return true;}
   }
  }
 }
 return false;
}
bool sxcmus_hippel(sx_context*c,unsigned kind){
 uint64_t base;if(!sxcmus_hippel_origin(c,kind,&base))return false;
 bool packed=sxcmus_eq(c,base,"COSO",4),st=kind==2,seven=kind==0;uint64_t head=base+(packed?32:0);
 uint8_t h[32],co[32];if(!sxcmus_read(c,head,h,32)||xx_rt_memcmp(h,"TFMX",4))return false;
 if(packed){if(!sxcmus_read(c,base,co,32)||!sxcmus_put(c,st?&sxcmus_hippel_st_coso:&sxcmus_hippel_coso,base,1))return false;}
 if(!sxcmus_put(c,st?&sxcmus_hippel_st_header:&sxcmus_hippel_header,head,1))return false;
 uint64_t nf=(uint64_t)sxcmus_be16(h+4)+1,ne=(uint64_t)sxcmus_be16(h+6)+1,nt=(uint64_t)sxcmus_be16(h+8)+1,np=(uint64_t)sxcmus_be16(h+10)+1;
 uint64_t trackbytes=sxcmus_be16(h+12),songs=sxcmus_be16(h+16),samples=sxcmus_be16(h+18);
 uint64_t pos,sub,smp;
 if(!packed){
  uint64_t env=head+32+nf*64,tr=env+ne*64;pos=tr+nt*trackbytes;sub=pos+np*(seven?28:12);smp=sub+(songs+1)*(seven?8:6);
  if(!sxcmus_span(c,head+32,nf*64+ne*64))return true;
  for(uint64_t i=0;i<ne;i++)if(!SXCMUS_ADD(c,hippel_envelope,env+i*64))return false;
 }else{
  uint64_t fs=sxcmus_be32(co+4),es=sxcmus_be32(co+8),ts=sxcmus_be32(co+12),ps=sxcmus_be32(co+16),ss=sxcmus_be32(co+20),ms=sxcmus_be32(co+24);
  pos=base+ps;sub=base+ss;smp=base+ms;
  uint16_t first;if(!sxcmus_word(c,base+64,&first))return true;unsigned width=st&&!first?4:2;
  uint64_t offsets[3]={fs,es,ts},counts[3]={nf,ne,nt},ends[3]={es,ts,ps};
  for(unsigned j=0;j<3;j++){
   uint64_t p=base+offsets[j],bytes=counts[j]*width;
   if(offsets[j]<64||ends[j]<offsets[j]||bytes>ends[j]-offsets[j]||!sxcmus_span(c,p,bytes))continue;
   if(!sxcmus_put(c,width==2?(st?&sxcmus_hippel_st_pointer16:&sxcmus_hippel_pointer16):&sxcmus_hippel_pointer32,p,counts[j]))return false;
   if(j==1)for(uint64_t i=0;i<counts[j];i++){
    uint8_t b[4];if(!sxcmus_read(c,p+i*width,b,width))return false;uint64_t ep=width==2?sxcmus_be16(b):sxcmus_be32(b);
    if(width==2&&(b[0]&128))continue; /* ST is signed; Amiga short-pointer sources disagree. Keep ambiguous targets raw. */
    if(ep>=offsets[j]+bytes&&ep<=ends[j]&&ends[j]-ep>=5&&sxcmus_span(c,base+ep,5)&&!SXCMUS_ADD(c,hippel_envelope,base+ep))return false;
   }
  }
  if(ps<64||ss<ps||np*(seven?28:12)>ss-ps)pos=(uint64_t)c->size;
  if(ss<64||ms<ss||songs*(seven?8:6)>ms-ss)sub=(uint64_t)c->size;
  if(ms<64)smp=(uint64_t)c->size;
 }
 const sx_layout*position=seven||st?&sxcmus_hippel_position_control:&sxcmus_hippel_position;
 if(!sxcmus_opt(c,position,pos,np*(seven?7:st?3:4)))return false;
 if(!sxcmus_opt(c,seven?&sxcmus_hippel_subsong7:&sxcmus_hippel_subsong,sub,songs))return false;
 /* ST's six-byte waveform definitions are a different grammar, not Amiga
  * sample headers. Their exact per-field semantics remain unexposed. */
 if(!st&&!sxcmus_opt(c,seven?&sxcmus_hippel_sample7:&sxcmus_hippel_sample_coso,smp,samples))return false;
 return true;
}
static bool sx_classicmusic_supports(xx_file_type_t t){switch(t){
case XX_FILE_TYPE_DIE_MUSIC_HIPPEL_7:
case XX_FILE_TYPE_DIE_MUSIC_HIPPEL_CO:
case XX_FILE_TYPE_DIE_MUSIC_HIPPEL_ST:
case XX_FILE_TYPE_DIE_MUSIC_RAZMO_KEFRENSSOUNDMACHINE:
case XX_FILE_TYPE_DIE_MUSIC_HULSBECK_THEFINALMUSICSYSTEMEXTENDED:
return true;default:return false;}}
static bool sx_classicmusic_build(sx_context*c){bool ok=false;switch(c->f->file_type){
case XX_FILE_TYPE_DIE_MUSIC_HIPPEL_7:ok=sx_hippel_7_build(c);break;
case XX_FILE_TYPE_DIE_MUSIC_HIPPEL_CO:ok=sx_hippel_co_build(c);break;
case XX_FILE_TYPE_DIE_MUSIC_HIPPEL_ST:ok=sx_hippel_st_build(c);break;
case XX_FILE_TYPE_DIE_MUSIC_RAZMO_KEFRENSSOUNDMACHINE:ok=sx_razmo_kefrenssoundmachine_build(c);break;
case XX_FILE_TYPE_DIE_MUSIC_HULSBECK_THEFINALMUSICSYSTEMEXTENDED:ok=sx_hulsbeck_thefinalmusicsystemextended_build(c);break;
default:return false;}(void)ok;
 /* Native-valid ST MMME and other unauthenticated ST metadata grammars
  * expose only their physical bytes. Never hide an actual I/O/cancel error. */
 if(!c->count&&c->f->file_type==XX_FILE_TYPE_DIE_MUSIC_HIPPEL_ST&&
    c->f->base_info_handled&&c->f->is_valid&&c->size>0&&
    !c->failed&&!xx_pd_is_stopped(c->pd))return sx_raw(c,0,c->size);
 return c->count&&sxcmus_finish(c);}
static bool sx_classicmusic_comment(xx_data_struct_record*r,uint32_t id){
 if(!r||!r->name||id<0x609e0000U||id>=0x609f0000U)return true;
 if(id==sxcmus_hippel_header.id&&!xx_rt_wcscmp(r->name,L"frequency_last_index"))return xx_data_struct_record_set_comment(r,L"Stored final zero-based index; number of saved records is this word plus one.");
 if(id==sxcmus_hippel_header.id&&!xx_rt_wcscmp(r->name,L"envelope_last_index"))return xx_data_struct_record_set_comment(r,L"Stored final zero-based index; number of saved records is this word plus one.");
 if(id==sxcmus_hippel_header.id&&!xx_rt_wcscmp(r->name,L"track_last_index"))return xx_data_struct_record_set_comment(r,L"Stored final zero-based index; number of saved records is this word plus one.");
 if(id==sxcmus_hippel_header.id&&!xx_rt_wcscmp(r->name,L"position_last_index"))return xx_data_struct_record_set_comment(r,L"Stored final zero-based index; number of saved records is this word plus one.");
 if(id==sxcmus_hippel_header.id&&!xx_rt_wcscmp(r->name,L"bytes_per_track"))return xx_data_struct_record_set_comment(r,L"Uncompressed track byte stride; packed COSO tracks instead use the physical offset table.");
 if(id==sxcmus_hippel_st_header.id&&!xx_rt_wcscmp(r->name,L"frequency_last_index"))return xx_data_struct_record_set_comment(r,L"Stored final zero-based index; number of saved records is this word plus one.");
 if(id==sxcmus_hippel_st_header.id&&!xx_rt_wcscmp(r->name,L"envelope_last_index"))return xx_data_struct_record_set_comment(r,L"Stored final zero-based index; number of saved records is this word plus one.");
 if(id==sxcmus_hippel_st_header.id&&!xx_rt_wcscmp(r->name,L"track_last_index"))return xx_data_struct_record_set_comment(r,L"Stored final zero-based index; number of saved records is this word plus one.");
 if(id==sxcmus_hippel_st_header.id&&!xx_rt_wcscmp(r->name,L"position_last_index"))return xx_data_struct_record_set_comment(r,L"Stored final zero-based index; number of saved records is this word plus one.");
 if(id==sxcmus_hippel_st_header.id&&!xx_rt_wcscmp(r->name,L"bytes_per_track"))return xx_data_struct_record_set_comment(r,L"Uncompressed track byte stride; packed COSO tracks instead use the physical offset table.");
 if(id==sxcmus_hippel_st_header.id&&!xx_rt_wcscmp(r->name,L"waveform_last_index"))return xx_data_struct_record_set_comment(r,L"Stored final waveform-definition index in the Atari ST variant; definitions have six physical bytes and are kept raw pending stronger per-field semantics.");
 if(id==sxcmus_hippel_coso.id&&!xx_rt_wcscmp(r->name,L"sample_data_offset"))return xx_data_struct_record_set_comment(r,L"Signed displacement from the COSO module start; -1 denotes external sample data. It is never followed as an unsigned physical offset.");
 if(id==sxcmus_hippel_st_coso.id&&!xx_rt_wcscmp(r->name,L"digital_data_offset_or_marker"))return xx_data_struct_record_set_comment(r,L"Module-relative digital-data displacement, or the literal LSMP marker for an external sample set; external files and transformed audio remain raw.");
 if(id==sxcmus_hippel_pointer16.id&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Stored module-relative16-bit offset interpreted unsigned by the maintained Amiga COSO loader. Original assembler short-pointer paths sign-extend it; values with bit15 set have variant-dependent target semantics and are not followed here.");
 if(id==sxcmus_hippel_pointer32.id&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Stored byte displacement relative to the beginning of the COSO module, including its32-byte outer header. Shared target bytes are emitted once.");
 if(id==sxcmus_hippel_st_pointer16.id&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Signed16-bit module-relative displacement: the original Atari ST player uses MOVEA.W to sign-extend this word before adding the COSO module base.");
 if(id==sxcmus_hippel_position_control.id&&!xx_rt_wcscmp(r->name,L"command"))return xx_data_struct_record_set_comment(r,L"Stored per-channel control byte. The7-voice Amiga position has seven such records; Atari ST has three. Command values are not converted to playback state.");
 if(id==sxcmus_hippel_subsong.id&&!xx_rt_wcscmp(r->name,L"last_position"))return xx_data_struct_record_set_comment(r,L"Inclusive final position index; the stored value is not a record count.");
 if(id==sxcmus_hippel_subsong7.id&&!xx_rt_wcscmp(r->name,L"last_position"))return xx_data_struct_record_set_comment(r,L"Inclusive final position index; the stored value is not a record count.");
 if(id==sxcmus_hippel_sample7.id&&!xx_rt_wcscmp(r->name,L"sample_data_offset"))return xx_data_struct_record_set_comment(r,L"Byte displacement relative to the sample-data region, which may be external; not relative to the physical module header.");
 if(id==sxcmus_hippel_sample7.id&&!xx_rt_wcscmp(r->name,L"length_words"))return xx_data_struct_record_set_comment(r,L"Stored sample length in two-byte words; preserved without multiplying the serialized value.");
 if(id==sxcmus_hippel_sample7.id&&!xx_rt_wcscmp(r->name,L"loop_start"))return xx_data_struct_record_set_comment(r,L"Byte displacement within the sample; the original loader clears its low bit before playback.");
 if(id==sxcmus_hippel_sample7.id&&!xx_rt_wcscmp(r->name,L"loop_length_words"))return xx_data_struct_record_set_comment(r,L"Stored sample loop length in two-byte words; no decoded sample bytes are synthesized.");
 if(id==sxcmus_hippel_sample_coso.id&&!xx_rt_wcscmp(r->name,L"sample_data_offset"))return xx_data_struct_record_set_comment(r,L"Byte displacement relative to the sample-data region, which may be external; not relative to the physical module header.");
 if(id==sxcmus_hippel_sample_coso.id&&!xx_rt_wcscmp(r->name,L"length_words"))return xx_data_struct_record_set_comment(r,L"Stored sample length in two-byte words; preserved without multiplying the serialized value.");
 if(id==sxcmus_hippel_sample_coso.id&&!xx_rt_wcscmp(r->name,L"loop_start"))return xx_data_struct_record_set_comment(r,L"Byte displacement within the sample; the original loader clears its low bit before playback.");
 if(id==sxcmus_hippel_sample_coso.id&&!xx_rt_wcscmp(r->name,L"loop_length_words"))return xx_data_struct_record_set_comment(r,L"Stored sample loop length in two-byte words; no decoded sample bytes are synthesized.");
 if(id==sxcmus_hippel_sample7.id&&!xx_rt_wcscmp(r->name,L"volume_word"))return xx_data_struct_record_set_comment(r,L"Physical volume word; the maintained7-voice loader ignores it and uses playback volume64.");
 if(id==sxcmus_kefrens_sample.id&&!xx_rt_wcscmp(r->name,L"sample_data_offset"))return xx_data_struct_record_set_comment(r,L"Stored physical byte offset relative to the beginning of the module.");
 if(id==sxcmus_kefrens_sample.id&&!xx_rt_wcscmp(r->name,L"byte_length"))return xx_data_struct_record_set_comment(r,L"Sample length in bytes, not hardware words; the converter divides this word by two for derived MOD metadata.");
 if(id==sxcmus_kefrens_sample.id&&!xx_rt_wcscmp(r->name,L"loop_start"))return xx_data_struct_record_set_comment(r,L"Sample-relative byte position; zero disables looping. The repeat length is derived and is not serialized.");
 if(id==sxcmus_kefrens_end.id&&!xx_rt_wcscmp(r->name,L"marker"))return xx_data_struct_record_set_comment(r,L"Physical0xFF in the first byte of an order entry ends active positions; remaining bytes are not inferred as another order.");
 if(id==sxcmus_kefrens_cell.id&&!xx_rt_wcscmp(r->name,L"note_index"))return xx_data_struct_record_set_comment(r,L"One-based note index; zero means no note. No frequency/period conversion is applied.");
 if(id==sxcmus_kefrens_cell.id&&!xx_rt_wcscmp(r->name,L"sample_and_effect"))return xx_data_struct_record_set_comment(r,L"High nibble sample number; low nibble stored effect. Stored effect D remains D even though the converter maps it to derived MOD effect A.");
 if(id==sxcmus_tfmx_tfhd.id&&!xx_rt_wcscmp(r->name,L"player_type"))return xx_data_struct_record_set_comment(r,L"Low7 bits:0 unspecified,1 TFMX1.5,2 Pro,3 seven voices; bit7 requests forced interpretation.");
 if(id==sxcmus_tfmx_song_end.id&&!xx_rt_wcscmp(r->name,L"last_track_step"))return xx_data_struct_record_set_comment(r,L"Inclusive final track-step index;0x01FF is commonly used in inactive song slots. No active-song count is invented.");
 if(id==sxcmus_tfmx_song_tempo.id&&!xx_rt_wcscmp(r->name,L"tempo_word"))return xx_data_struct_record_set_comment(r,L"Stored timing word. The player selects tick-count/BPM interpretation by value and module variant; retained without normalization.");
 if(id==sxcmus_tfmx_track_mute.id&&!xx_rt_wcscmp(r->name,L"mute_word"))return xx_data_struct_record_set_comment(r,L"Editor track-mute word; zero is the normal unmuted setting. Some playback variants ignore these words.");
 if(id==sxcmus_tfmx_tables_be.id&&!xx_rt_wcscmp(r->name,L"track_table_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the512-byte music-header origin, after any wrapper. All three zero words select default track/pattern/macro offsets0x800/0x400/0x600.");
 if(id==sxcmus_tfmx_tables_be.id&&!xx_rt_wcscmp(r->name,L"pattern_table_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the512-byte music-header origin, after any wrapper. All three zero words select default track/pattern/macro offsets0x800/0x400/0x600.");
 if(id==sxcmus_tfmx_tables_be.id&&!xx_rt_wcscmp(r->name,L"macro_table_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the512-byte music-header origin, after any wrapper. All three zero words select default track/pattern/macro offsets0x800/0x400/0x600.");
 if(id==sxcmus_tfmx_tables_le.id&&!xx_rt_wcscmp(r->name,L"track_table_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the512-byte music-header origin, after any wrapper. All three zero words select default track/pattern/macro offsets0x800/0x400/0x600.");
 if(id==sxcmus_tfmx_tables_le.id&&!xx_rt_wcscmp(r->name,L"pattern_table_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the512-byte music-header origin, after any wrapper. All three zero words select default track/pattern/macro offsets0x800/0x400/0x600.");
 if(id==sxcmus_tfmx_tables_le.id&&!xx_rt_wcscmp(r->name,L"macro_table_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the512-byte music-header origin, after any wrapper. All three zero words select default track/pattern/macro offsets0x800/0x400/0x600.");
 if(id==sxcmus_tfmx_pointer.id&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Big-endian byte offset relative to the music-header origin, including when the three header table offsets use the legacy little-endian variant.");
 if(id==sxcmus_tfmx_track_channel.id&&!xx_rt_wcscmp(r->name,L"pattern_or_control"))return xx_data_struct_record_set_comment(r,L"Pattern index below0x80; higher values are stored sequencer control states. Eight channel words occupy a16-byte ordinary track step.");
 if(id==sxcmus_tfmx_track_command.id&&!xx_rt_wcscmp(r->name,L"marker"))return xx_data_struct_record_set_comment(r,L"0xEFFE identifies a track-command step; parameters remain opaque command-specific bytes.");
 if(id==sxcmus_tfmx_mod_tag.id&&!xx_rt_wcscmp(r->name,L"declared_length"))return xx_data_struct_record_set_comment(r,L"Stored tag length; ordinary text/data tags count bytes, tag0 uses a distinct four-byte-unit grammar and is not traversed further here.");
 if(r->property&SX_OFFSET)return xx_data_struct_record_set_comment(r,L"Stored byte offset relative to the module start, unless the enclosing structure specifies another origin.");
 if(r->property&SX_ADDRESS)return xx_data_struct_record_set_comment(r,L"Encoded target-machine memory address; the field source-file offset is shown separately.");
 return true;
}
const sx_family sx_classicmusic_family={sx_classicmusic_supports,sx_classicmusic_build,sx_classicmusic_layouts,SX_COUNT(sx_classicmusic_layouts),sx_classicmusic_comment};
