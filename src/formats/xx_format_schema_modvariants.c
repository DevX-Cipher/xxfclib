/* Copyright (c)2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical music header and table metadata; compressed and unknown bodies stay raw. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_modvariants.h"
static const xx_data_struct_field_desc sxmodv_mod_compact_sample_fields[]={
 SX_FIELD("length_words","uint16",0,2,SX_NONE),
 SX_FIELD("finetune","uint8",2,1,SX_NONE),
 SX_FIELD("volume","uint8",3,1,SX_NONE),
 SX_FIELD("loop_start_words","uint16",4,2,SX_NONE),
 SX_FIELD("loop_length_words","uint16",6,2,SX_NONE),
};
const sx_layout sxmodv_mod_compact_sample={UINT32_C(0x609B0002),"mod_compact_sample",sxmodv_mod_compact_sample_fields,SX_COUNT(sxmodv_mod_compact_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxmodv_mod_order_fields[]={
 SX_FIELD("pattern_index","uint8",0,1,SX_ID),
};
const sx_layout sxmodv_mod_order={UINT32_C(0x609B0004),"mod_order",sxmodv_mod_order_fields,SX_COUNT(sxmodv_mod_order_fields),SX_BE};
static const xx_data_struct_field_desc sxmodv_di_orders_end_fields[]={
 SX_FIELD("end_marker","uint8",0,1,SX_ID),
};
const sx_layout sxmodv_di_orders_end={UINT32_C(0x609B0005),"di_orders_end",sxmodv_di_orders_end_fields,SX_COUNT(sxmodv_di_orders_end_fields),SX_BE};
static const xx_data_struct_field_desc sxmodv_di_blank_fields[]={
 SX_FIELD("blank_marker","uint8",0,1,SX_ID),
};
const sx_layout sxmodv_di_blank={UINT32_C(0x609B0006),"di_blank",sxmodv_di_blank_fields,SX_COUNT(sxmodv_di_blank_fields),SX_BE};
static const xx_data_struct_field_desc sxmodv_di_event_fields[]={
 SX_FIELD("sample_note_control","uint8",0,1,SX_FLAGS),
 SX_FIELD("note_effect","uint8",1,1,SX_FLAGS),
};
const sx_layout sxmodv_di_event={UINT32_C(0x609B0007),"di_event",sxmodv_di_event_fields,SX_COUNT(sxmodv_di_event_fields),SX_BE};
static const xx_data_struct_field_desc sxmodv_di_event_value_fields[]={
 SX_FIELD("sample_note_control","uint8",0,1,SX_FLAGS),
 SX_FIELD("note_effect","uint8",1,1,SX_FLAGS),
 SX_FIELD("effect_parameter","uint8",2,1,SX_NONE),
};
const sx_layout sxmodv_di_event_value={UINT32_C(0x609B0008),"di_event_value",sxmodv_di_event_value_fields,SX_COUNT(sxmodv_di_event_value_fields),SX_BE};
static const xx_data_struct_field_desc sxmodv_soundtracker_sample_fields[]={
 SX_FIELD("name","char[22]",0,22,SX_NONE),
 SX_FIELD("length_words","uint16",22,2,SX_NONE),
 SX_FIELD("finetune_control","uint8",24,1,SX_NONE),
 SX_FIELD("volume","uint8",25,1,SX_NONE),
 SX_FIELD("loop_start_encoded","uint16",26,2,SX_NONE),
 SX_FIELD("loop_length_words","uint16",28,2,SX_NONE),
};
const sx_layout sxmodv_soundtracker_sample={UINT32_C(0x609B000D),"soundtracker_sample",sxmodv_soundtracker_sample_fields,SX_COUNT(sxmodv_soundtracker_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxmodv_soundtracker_controls_fields[]={
 SX_FIELD("song_length","uint8",0,1,SX_COUNT_PROP),
 SX_FIELD("tempo_control","uint8",1,1,SX_NONE),
};
const sx_layout sxmodv_soundtracker_controls={UINT32_C(0x609B000E),"soundtracker_controls",sxmodv_soundtracker_controls_fields,SX_COUNT(sxmodv_soundtracker_controls_fields),SX_BE};
static const xx_data_struct_field_desc sxmodv_soundtracker_cell_fields[]={
 SX_FIELD("reserved_period_high","uint8",0,1,SX_FLAGS),
 SX_FIELD("period_low","uint8",1,1,SX_NONE),
 SX_FIELD("sample_low_effect","uint8",2,1,SX_FLAGS),
 SX_FIELD("effect_parameter","uint8",3,1,SX_NONE),
};
const sx_layout sxmodv_soundtracker_cell={UINT32_C(0x609B000F),"soundtracker_cell",sxmodv_soundtracker_cell_fields,SX_COUNT(sxmodv_soundtracker_cell_fields),SX_BE};
static const xx_data_struct_field_desc sxmodv_mfp_controls_fields[]={
 SX_FIELD("song_length","uint8",0,1,SX_COUNT_PROP),
 SX_FIELD("restart","uint8",1,1,SX_ID),
};
const sx_layout sxmodv_mfp_controls={UINT32_C(0x609B0010),"mfp_controls",sxmodv_mfp_controls_fields,SX_COUNT(sxmodv_mfp_controls_fields),SX_BE};
static const xx_data_struct_field_desc sxmodv_mfp_counts_fields[]={
 SX_FIELD("position_count","uint16",0,2,SX_COUNT_PROP),
 SX_FIELD("position_count_copy","uint16",2,2,SX_COUNT_PROP),
};
const sx_layout sxmodv_mfp_counts={UINT32_C(0x609B0011),"mfp_counts",sxmodv_mfp_counts_fields,SX_COUNT(sxmodv_mfp_counts_fields),SX_BE};
static const xx_data_struct_field_desc sxmodv_mfp_channels_fields[]={
 SX_FIELD("channel_a_offset","int16",0,2,SX_OFFSET),
 SX_FIELD("channel_b_offset","int16",2,2,SX_OFFSET),
 SX_FIELD("channel_c_offset","int16",4,2,SX_OFFSET),
 SX_FIELD("channel_d_offset","int16",6,2,SX_OFFSET),
};
const sx_layout sxmodv_mfp_channels={UINT32_C(0x609B0012),"mfp_channels",sxmodv_mfp_channels_fields,SX_COUNT(sxmodv_mfp_channels_fields),SX_BE};
static const sx_layout *const sx_modvariants_layouts[]={
 &sxmodv_di_header,
 &sxmodv_mod_compact_sample,
 &sxmodv_di_pattern_offset,
 &sxmodv_mod_order,
 &sxmodv_di_orders_end,
 &sxmodv_di_blank,
 &sxmodv_di_event,
 &sxmodv_di_event_value,
 &sxmodv_pha_sample,
 &sxmodv_pha_control,
 &sxmodv_pha_pattern_offset,
 &sxmodv_soundtracker_title,
 &sxmodv_soundtracker_sample,
 &sxmodv_soundtracker_controls,
 &sxmodv_soundtracker_cell,
 &sxmodv_mfp_controls,
 &sxmodv_mfp_counts,
 &sxmodv_mfp_channels,
};
bool sxmodv_span(sxmodv_view*v,uint64_t p,uint64_t n){return !xx_pd_is_stopped(v->c->pd)&&p<=v->end&&n<=v->end-p;}
bool sxmodv_word(sxmodv_view*v,uint64_t p,unsigned n,uint64_t*x){uint8_t b[4];if(++v->work>1000000||!n||n>4||!sxmodv_span(v,p,n)||!sx_read(v->c,(int64_t)p,b,n))return false;*x=0;for(unsigned i=0;i<n;i++)*x=(*x<<8)|b[i];return true;}
bool sxmodv_row(sxmodv_view*v,const sx_layout*l,uint64_t p){const xx_data_struct_field_desc*f=&l->fields[l->field_count-1];uint64_t n=(uint64_t)(f->rel_offset+f->size);return ++v->work<=1000000&&sxmodv_span(v,p,n)&&(v->c->count>=24000||sx_add(v->c,l,(int64_t)p,(int64_t)n));}
static int sxmodv_order(const void*aa,const void*bb){const xx_data_struct*a=aa,*b=bb;if(a->offset!=b->offset)return a->offset<b->offset?-1:1;return a->total_size<b->total_size?-1:a->total_size>b->total_size?1:0;}
static bool sxmodv_finish(sx_context*c){size_t n=c->count,keep=0;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxmodv_order);for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(at<end)continue;c->items[keep++]=c->items[i];end=at+z;}c->count=keep;n=keep;end=0;for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(at>end&&!sx_raw(c,end,at-end))return false;end=at+z;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxmodv_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
static bool sx_modvariants_supports(xx_file_type_t t){switch(t){case XX_FILE_TYPE_DIE_MUSIC_AZATOTH_PHAPACKER:case XX_FILE_TYPE_DIE_MUSIC_DIGITALILLUSIONSCREATIVEENT_DI:case XX_FILE_TYPE_DIE_MUSIC_OBI_SOUNDTRACKER_STK:case XX_FILE_TYPE_DIE_MUSIC_SOUTHERN_MAGNETICFIELDSPACKER:return true;default:return false;}}
static bool sx_modvariants_build(sx_context*c){if(!c||!c->f||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid||c->size<=0)return false;sxmodv_view v={c,(uint64_t)c->size,0};switch(c->f->file_type){case XX_FILE_TYPE_DIE_MUSIC_AZATOTH_PHAPACKER:(void)sx_azatoth_phapacker_build(&v);break;case XX_FILE_TYPE_DIE_MUSIC_DIGITALILLUSIONSCREATIVEENT_DI:(void)sx_digitalillusionscreativeent_di_build(&v);break;case XX_FILE_TYPE_DIE_MUSIC_OBI_SOUNDTRACKER_STK:(void)sx_obi_soundtracker_stk_build(&v);break;case XX_FILE_TYPE_DIE_MUSIC_SOUTHERN_MAGNETICFIELDSPACKER:(void)sx_southern_magneticfieldspacker_build(&v);break;default:return false;}return c->count&&sxmodv_finish(c);}
static bool sx_modvariants_comment(xx_data_struct_record*r,uint32_t id){if(!r||!r->name||id<UINT32_C(0x609B0001)||id>=UINT32_C(0x609C0000))return true;const wchar_t*s=NULL;
#define SMV_N(n) (!xx_rt_wcscmp(r->name,L##n))
 if(id==sxmodv_mfp_channels.id)s=L"Signed channel-data byte displacement from module offset 382 + 8 * position_count; original player uses ADDA.W; packed bodies remain raw";
 else if(r->property&SX_OFFSET)s=L"Byte offset from the beginning of this module's physical file view";
 else if(SMV_N("length_words")||SMV_N("loop_length_words")||SMV_N("loop_start_words"))s=L"Stored in two-byte words; multiply by two for a byte length or loop position";
 else if(SMV_N("volume"))s=L"Amiga sample volume, 0..64";
 else if(SMV_N("finetune"))s=L"Stored MOD finetune nibble, 0..15; values 8..15 encode negative adjustments";
 else if(SMV_N("finetune_times_72"))s=L"Stored MOD finetune nibble multiplied by 72; preserved encoded value";
 else if(SMV_N("position_table_bytes"))s=L"Active bytes of the four-byte pattern-offset table; divide by four for active positions; 128 slots are physically stored";
 else if(id==sxmodv_mod_order.id)s=L"Zero-based pattern index; unused fixed-table slots are preserved";
 else if(id==sxmodv_di_orders_end.id)s=L"0xFF terminates the physical Digital Illusions order list";
 else if(id==sxmodv_di_blank.id)s=L"0xFF encodes one blank channel cell";
 else if(id==sxmodv_di_event.id||id==sxmodv_di_event_value.id){if(SMV_N("sample_note_control"))s=L"Bits 2..6 sample number; bits 0..1 high note bits; bit 7 adds a third effect-parameter byte";else if(SMV_N("note_effect"))s=L"High nibble low note bits; low nibble effect code; B/D stop after the current four-channel row";else s=L"Stored effect parameter; absent in the two-byte encoding";}
 else if(id==sxmodv_soundtracker_sample.id){if(SMV_N("finetune_control"))s=L"Physical control byte retained; early 15-sample SoundTracker variants do not share all later MOD finetune semantics";else if(SMV_N("loop_start_encoded"))s=L"Original encoded loop position; the retained SoundTracker IV player uses bytes, while later variants differ, so no unit conversion is assumed";}
 else if(id==sxmodv_soundtracker_controls.id&&SMV_N("tempo_control"))s=L"Stored SoundTracker timing/control byte; variant-dependent playback interpretation, not a timestamp";
 else if(id==sxmodv_mfp_controls.id&&SMV_N("restart"))s=L"Stored restart/control value; the native-supported Magnetic Fields Packer variant uses 127";
 else if(id==sxmodv_mfp_counts.id)s=L"Stored count of eight-byte channel-pointer rows; both physical copies are retained";
 else if(id==sxmodv_soundtracker_cell.id){if(SMV_N("reserved_period_high"))s=L"Upper nibble unused/reserved in the retained 15-sample player; lower nibble Amiga period high bits; sample number comes only from the third byte";else if(SMV_N("period_low"))s=L"Low eight bits of the Amiga playback period";else if(SMV_N("sample_low_effect"))s=L"High nibble sample number; low nibble effect code";else s=L"Effect-dependent unsigned parameter byte";}
 else if(SMV_N("song_length"))s=L"Count of active entries in the fixed 128-byte order table";
 if(!s&&(SMV_N("unknown")||SMV_N("unknown0")||SMV_N("unknown4")))s=L"Physically stored bytes skipped by the retained reference loader; no stronger semantics assumed";
#undef SMV_N
 return !s||xx_data_struct_record_set_comment(r,s);
}
const sx_family sx_modvariants_family={sx_modvariants_supports,sx_modvariants_build,sx_modvariants_layouts,SX_COUNT(sx_modvariants_layouts),sx_modvariants_comment};
