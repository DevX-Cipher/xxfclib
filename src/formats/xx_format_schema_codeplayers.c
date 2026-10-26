/* Copyright (c)2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical music header and table metadata; compressed and unknown bodies stay raw. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_codeplayers.h"
static const xx_data_struct_field_desc sxcodeplayers_bd_subsong_fields[]={
 SX_FIELD("channel0_position_offset","uint16",0,2,SX_OFFSET),
 SX_FIELD("channel1_position_offset","uint16",2,2,SX_OFFSET),
 SX_FIELD("channel2_position_offset","uint16",4,2,SX_OFFSET),
 SX_FIELD("channel3_position_offset","uint16",6,2,SX_OFFSET),
};
const sx_layout sxcodeplayers_bd_subsong={UINT32_C(0x60A10001),"bd_subsong",sxcodeplayers_bd_subsong_fields,SX_COUNT(sxcodeplayers_bd_subsong_fields),SX_BE};
static const xx_data_struct_field_desc sxcodeplayers_bd_track_offset_fields[]={
 SX_FIELD("track_offset","uint16",0,2,SX_OFFSET),
};
const sx_layout sxcodeplayers_bd_track_offset={UINT32_C(0x60A10002),"bd_track_offset",sxcodeplayers_bd_track_offset_fields,SX_COUNT(sxcodeplayers_bd_track_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxcodeplayers_bd_sample_offset_fields[]={
 SX_FIELD("sample_info_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxcodeplayers_bd_sample_offset={UINT32_C(0x60A10003),"bd_sample_offset",sxcodeplayers_bd_sample_offset_fields,SX_COUNT(sxcodeplayers_bd_sample_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxcodeplayers_bd_sample_fields[]={
 SX_FIELD("sample_data_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("loop_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("length_words","uint16",8,2,SX_NONE),
 SX_FIELD("loop_length_words","uint16",10,2,SX_NONE),
 SX_FIELD("volume","uint16",12,2,SX_NONE),
 SX_FIELD("volume_fade_speed","int16",14,2,SX_NONE),
 SX_FIELD("portamento_duration","int16",16,2,SX_NONE),
 SX_FIELD("portamento_add_value","int16",18,2,SX_NONE),
 SX_FIELD("vibrato_depth","uint16",20,2,SX_NONE),
 SX_FIELD("vibrato_add_value","uint16",22,2,SX_NONE),
 SX_FIELD("note_transpose","int16",24,2,SX_NONE),
 SX_FIELD("finetune_period","uint16",26,2,SX_NONE),
};
const sx_layout sxcodeplayers_bd_sample={UINT32_C(0x60A10004),"bd_sample",sxcodeplayers_bd_sample_fields,SX_COUNT(sxcodeplayers_bd_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxcodeplayers_dw_position_offset_fields[]={
 SX_FIELD("position_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxcodeplayers_dw_position_offset={UINT32_C(0x60A10007),"dw_position_offset",sxcodeplayers_dw_position_offset_fields,SX_COUNT(sxcodeplayers_dw_position_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxcodeplayers_dw_sample32_fields[]={
 SX_FIELD("sample_pointer","uint32",0,4,SX_POINTER),
 SX_FIELD("loop_start","int32",4,4,SX_OFFSET),
 SX_FIELD("length_words","uint16",8,2,SX_NONE),
 SX_FIELD("padding","bytes",10,2,SX_NONE),
 SX_FIELD("finetune_period","uint16",12,2,SX_NONE),
 SX_FIELD("volume","uint16",14,2,SX_NONE),
};
const sx_layout sxcodeplayers_dw_sample32={UINT32_C(0x60A10008),"dw_sample32",sxcodeplayers_dw_sample32_fields,SX_COUNT(sxcodeplayers_dw_sample32_fields),SX_BE};
static const xx_data_struct_field_desc sxcodeplayers_dw_sample_data_fields[]={
 SX_FIELD("sample_bytes","uint32",0,4,SX_SIZE),
 SX_FIELD("frequency_hz","uint16",4,2,SX_NONE),
};
const sx_layout sxcodeplayers_dw_sample_data={UINT32_C(0x60A10009),"dw_sample_data",sxcodeplayers_dw_sample_data_fields,SX_COUNT(sxcodeplayers_dw_sample_data_fields),SX_BE};
static const xx_data_struct_field_desc sxcodeplayers_avp_subsong_fields[]={
 SX_FIELD("channel0_position_offset","uint16",0,2,SX_OFFSET),
 SX_FIELD("channel1_position_offset","uint16",2,2,SX_OFFSET),
 SX_FIELD("channel2_position_offset","uint16",4,2,SX_OFFSET),
 SX_FIELD("channel3_position_offset","uint16",6,2,SX_OFFSET),
 SX_FIELD("speed_variation0","int8",8,1,SX_NONE),
 SX_FIELD("speed_variation1","int8",9,1,SX_NONE),
 SX_FIELD("speed_variation2","int8",10,1,SX_NONE),
 SX_FIELD("speed_variation3","int8",11,1,SX_NONE),
 SX_FIELD("speed_variation4","int8",12,1,SX_NONE),
 SX_FIELD("speed_variation5","int8",13,1,SX_NONE),
 SX_FIELD("speed_variation6","int8",14,1,SX_NONE),
 SX_FIELD("speed_variation7","int8",15,1,SX_NONE),
};
const sx_layout sxcodeplayers_avp_subsong={UINT32_C(0x60A1000A),"avp_subsong",sxcodeplayers_avp_subsong_fields,SX_COUNT(sxcodeplayers_avp_subsong_fields),SX_BE};
static const xx_data_struct_field_desc sxcodeplayers_avp_track_offset_fields[]={
 SX_FIELD("track_offset","int16",0,2,SX_OFFSET),
};
const sx_layout sxcodeplayers_avp_track_offset={UINT32_C(0x60A1000B),"avp_track_offset",sxcodeplayers_avp_track_offset_fields,SX_COUNT(sxcodeplayers_avp_track_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxcodeplayers_avp_envelope_fields[]={
 SX_FIELD("point0_wait","uint8",0,1,SX_NONE),
 SX_FIELD("point0_increment","int8",1,1,SX_NONE),
 SX_FIELD("point0_repeat","uint8",2,1,SX_NONE),
 SX_FIELD("point1_wait","uint8",3,1,SX_NONE),
 SX_FIELD("point1_increment","int8",4,1,SX_NONE),
 SX_FIELD("point1_repeat","uint8",5,1,SX_NONE),
 SX_FIELD("point2_wait","uint8",6,1,SX_NONE),
 SX_FIELD("point2_increment","int8",7,1,SX_NONE),
 SX_FIELD("point2_repeat","uint8",8,1,SX_NONE),
 SX_FIELD("point3_wait","uint8",9,1,SX_NONE),
 SX_FIELD("point3_increment","int8",10,1,SX_NONE),
 SX_FIELD("point3_repeat","uint8",11,1,SX_NONE),
 SX_FIELD("point4_wait","uint8",12,1,SX_NONE),
 SX_FIELD("point4_increment","int8",13,1,SX_NONE),
 SX_FIELD("point4_repeat","uint8",14,1,SX_NONE),
 SX_FIELD("trailing_wait","uint8",15,1,SX_NONE),
};
const sx_layout sxcodeplayers_avp_envelope={UINT32_C(0x60A1000C),"avp_envelope",sxcodeplayers_avp_envelope_fields,SX_COUNT(sxcodeplayers_avp_envelope_fields),SX_BE};
static const xx_data_struct_field_desc sxcodeplayers_avp_sample_offset_fields[]={
 SX_FIELD("sample_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxcodeplayers_avp_sample_offset={UINT32_C(0x60A10010),"avp_sample_offset",sxcodeplayers_avp_sample_offset_fields,SX_COUNT(sxcodeplayers_avp_sample_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxcodeplayers_avp_sample_fields[]={
 SX_FIELD("length_words","uint16",0,2,SX_NONE),
 SX_FIELD("loop_start","uint16",2,2,SX_OFFSET),
 SX_FIELD("loop_length_words","uint16",4,2,SX_NONE),
};
const sx_layout sxcodeplayers_avp_sample={UINT32_C(0x60A10011),"avp_sample",sxcodeplayers_avp_sample_fields,SX_COUNT(sxcodeplayers_avp_sample_fields),SX_BE};
static const sx_layout *const sx_codeplayers_layouts[]={
 &sxcodeplayers_bd_subsong,
 &sxcodeplayers_bd_track_offset,
 &sxcodeplayers_bd_sample_offset,
 &sxcodeplayers_bd_sample,
 &sxcodeplayers_dw_speed,
 &sxcodeplayers_dw_delay_speed,
 &sxcodeplayers_dw_position_offset,
 &sxcodeplayers_dw_sample32,
 &sxcodeplayers_dw_sample_data,
 &sxcodeplayers_avp_subsong,
 &sxcodeplayers_avp_track_offset,
 &sxcodeplayers_avp_envelope,
 &sxcodeplayers_avp_instrument1,
 &sxcodeplayers_avp_instrument2,
 &sxcodeplayers_avp_instrument3,
 &sxcodeplayers_avp_sample_offset,
 &sxcodeplayers_avp_sample,
};
bool sxcodeplayers_span(sxcodeplayers_view*v,uint64_t p,uint64_t n){return p<=v->end&&n<=v->end-p&&!xx_pd_is_stopped(v->c->pd);}
bool sxcodeplayers_read(sxcodeplayers_view*v,uint64_t p,void*b,size_t n){return ++v->work<=1000000&&sxcodeplayers_span(v,p,n)&&sx_read(v->c,(int64_t)p,b,n);}
uint16_t sxcodeplayers_be16(const uint8_t*b){return (uint16_t)((uint16_t)b[0]<<8)|b[1];}
bool sxcodeplayers_u(sxcodeplayers_view*v,uint64_t p,unsigned n,uint64_t*out){uint8_t b[4];if(!n||n>4||!sxcodeplayers_read(v,p,b,n))return false;*out=0;for(unsigned i=0;i<n;i++)*out=(*out<<8)|b[i];return true;}
bool sxcodeplayers_eq(sxcodeplayers_view*v,size_t p,const char*b,size_t n){return p<=v->code_size&&n<=v->code_size-p&&!xx_rt_memcmp(v->code+p,b,n);}
size_t sxcodeplayers_find(sxcodeplayers_view*v,size_t p,size_t end,const char*b,size_t n){if(end>v->code_size)end=v->code_size;for(;p<=end&&n<=end-p;p+=2){if(++v->work>1000000||xx_pd_is_stopped(v->c->pd))break;if(sxcodeplayers_eq(v,p,b,n))return p;}return SIZE_MAX;}
bool sxcodeplayers_ref(sxcodeplayers_view*v,size_t p,uint64_t*out){if(p>v->code_size||v->code_size-p<2)return false;int32_t d=sxcodeplayers_be16(v->code+p);if(d>=32768)d-=65536;int64_t q=(int64_t)p+d;if(q<0||(uint64_t)q>=v->end)return false;*out=(uint64_t)q;return true;}
bool sxcodeplayers_put(sxcodeplayers_view*v,const sx_layout*l,uint64_t p,uint64_t count){const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(!count)return true;if(!z||count>UINT64_MAX/z||!sxcodeplayers_span(v,p,count*z)||++v->work>1000000)return false;if(v->c->count>=24000)return true;uint64_t end=p+count*z;for(size_t i=0;i<v->c->count;i++){uint64_t q=(uint64_t)(v->c->items[i].offset-v->c->f->base_address),n=(uint64_t)v->c->items[i].total_size;if(p<q+n&&q<end)return true;}return count==1?sx_add(v->c,l,(int64_t)p,(int64_t)z):sx_table(v->c,l,(int64_t)p,(int64_t)z,(int64_t)count);}
static int sxcodeplayers_order(const void*aa,const void*bb){const xx_data_struct*a=aa,*b=bb;return a->offset<b->offset?-1:a->offset>b->offset?1:0;}
static bool sxcodeplayers_finish(sx_context*c){size_t n=c->count;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxcodeplayers_order);for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(p<end||z<=0||p>c->size||z>c->size-p)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+z;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxcodeplayers_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
static bool sx_codeplayers_supports(xx_file_type_t t){switch(t){case XX_FILE_TYPE_DIE_MUSIC_BENDAGLISH_BD:case XX_FILE_TYPE_DIE_MUSIC_DAVIDWHITTAKER_DW:case XX_FILE_TYPE_DIE_MUSIC_WALKER_ACTIVISIONPRO:return true;default:return false;}}
static bool sx_codeplayers_build(sx_context*c){if(!c||!c->f||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid||c->size<=0)return false;sxcodeplayers_view v;v.c=c;v.end=(uint64_t)c->size;v.work=0;v.code_size=v.end<sizeof(v.code)?(size_t)v.end:sizeof(v.code);if(!sx_read(c,0,v.code,v.code_size))return false;switch(c->f->file_type){case XX_FILE_TYPE_DIE_MUSIC_BENDAGLISH_BD:(void)sx_bendaglish_bd_build(&v);break;case XX_FILE_TYPE_DIE_MUSIC_DAVIDWHITTAKER_DW:(void)sx_davidwhittaker_dw_build(&v);break;case XX_FILE_TYPE_DIE_MUSIC_WALKER_ACTIVISIONPRO:(void)sx_walker_activisionpro_build(&v);break;default:return false;}if(c->failed||xx_pd_is_stopped(c->pd))return false;return c->count?sxcodeplayers_finish(c):sx_raw(c,0,c->size);}
static bool sx_codeplayers_comment(xx_data_struct_record*r,uint32_t id){
 if(!r||!r->name||id<UINT32_C(0x60a10001)||id>UINT32_C(0x60a1ffff)||r->value.type==XX_VAR_TYPE_FLOAT||r->value.type==XX_VAR_TYPE_DOUBLE)return true;
 const wchar_t*n=r->name;
 if(id==sxcodeplayers_bd_subsong.id)return xx_data_struct_record_set_comment(r,L"Byte offset relative to the authenticated Ben Daglish subsong-table origin; position command bytes remain raw.");
 if(id==sxcodeplayers_bd_track_offset.id)return xx_data_struct_record_set_comment(r,L"Byte offset relative to the separately authenticated track-data origin.");
 if(id==sxcodeplayers_bd_sample_offset.id||(id==sxcodeplayers_bd_sample.id&&(!xx_rt_wcscmp(n,L"sample_data_offset")||!xx_rt_wcscmp(n,L"loop_offset"))))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the authenticated sample-info offset-table origin. Zero loop offset disables looping.");
 if(!xx_rt_wcscmp(n,L"length_words")||!xx_rt_wcscmp(n,L"loop_length_words"))return xx_data_struct_record_set_comment(r,L"Stored length in two-byte words, preserved without conversion to bytes. Loop-length sentinel semantics depend on the player variant.");
 if(id==sxcodeplayers_dw_sample32.id&&!xx_rt_wcscmp(n,L"sample_pointer"))return xx_data_struct_record_set_comment(r,L"Stored sample-address slot. The loader replaces runtime pointers using the separate sample-data blocks; this is not followed as a physical file offset.");
 if(id==sxcodeplayers_dw_sample32.id&&!xx_rt_wcscmp(n,L"loop_start"))return xx_data_struct_record_set_comment(r,L"Signed sample-relative byte offset; -1 disables looping. Original stored value is retained.");
 if(id==sxcodeplayers_dw_position_offset.id)return xx_data_struct_record_set_comment(r,L"Byte offset relative to the authenticated player-global origin, not the start of this pointer table.");
 if(id==sxcodeplayers_dw_sample_data.id&&!xx_rt_wcscmp(n,L"frequency_hz"))return xx_data_struct_record_set_comment(r,L"Stored sample playback frequency in Hz; the player derives a period from 3579545 / frequency.");
 if(id==sxcodeplayers_avp_subsong.id){if(!xx_rt_wcsncmp(n,L"channel",7))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the separately authenticated position-list origin.");return xx_data_struct_record_set_comment(r,L"Signed stored speed-variation byte; playback sequence interpretation depends on the authenticated player variant.");}
 if(id==sxcodeplayers_avp_track_offset.id)return xx_data_struct_record_set_comment(r,L"Signed byte offset relative to the track-data origin. Negative entries are unused sentinels and are not followed.");
 if(id==sxcodeplayers_avp_sample_offset.id)return xx_data_struct_record_set_comment(r,L"Byte offset relative to the separately authenticated sample-data origin; the 28th entry marks the end after 27 sample slots.");
 if(id==sxcodeplayers_avp_sample.id&&!xx_rt_wcscmp(n,L"loop_start"))return xx_data_struct_record_set_comment(r,L"Sample-relative byte offset, unlike the length and repeat-length words in this record.");
 if(!xx_rt_wcscmp(n,L"sample_start_offset"))return xx_data_struct_record_set_comment(r,L"Sample-relative byte offset used by the version3 instrument player; retained separately from hardware word lengths.");
 if(id==sxcodeplayers_avp_envelope.id){if(!xx_rt_wcscmp(n,L"trailing_wait"))return xx_data_struct_record_set_comment(r,L"Physical trailing envelope byte. The maintained player may use it as a sixth wait counter; its synthetic increment/repeat values have no serialized fields.");if((xx_rt_wcschr(n,L'_')&&!xx_rt_wcscmp(xx_rt_wcschr(n,L'_')+1,L"increment")))return xx_data_struct_record_set_comment(r,L"Signed volume increment at this stored envelope point.");return xx_data_struct_record_set_comment(r,L"Stored envelope wait/repetition control byte; playback applies its original sentinel behavior.");}
 if(!xx_rt_wcscmp(n,L"volume"))return xx_data_struct_record_set_comment(r,L"Stored player volume control; usual Amiga hardware volume range is 0..64.");
 if(!xx_rt_wcsncmp(n,L"arpeggio",8)||!xx_rt_wcscmp(n,L"transpose")||!xx_rt_wcscmp(n,L"note_transpose"))return xx_data_struct_record_set_comment(r,L"Signed stored note adjustment; no derived note or frequency is substituted.");
 if(!xx_rt_wcscmp(n,L"finetune_period"))return xx_data_struct_record_set_comment(r,L"Stored sample period control, retained before any runtime frequency or note conversion.");
 return true;
}
const sx_family sx_codeplayers_family={sx_codeplayers_supports,sx_codeplayers_build,sx_codeplayers_layouts,SX_COUNT(sx_codeplayers_layouts),sx_codeplayers_comment};
