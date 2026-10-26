/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Alexander 'NightRadio' Zolotov's SunVox module (.SUNVOX) data structures, moved out of the musicwire schema family. */
#include "../../../xx_format_schema_musicwire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmw_sunvox_header_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("payload_bytes","uint32",4,4,SX_SIZE),
};
const sx_layout sxmw_sunvox_header={UINT32_C(0x60870043),"sunvox_header",sxmw_sunvox_header_fields,SX_COUNT(sxmw_sunvox_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_sv_version_fields[]={
 SX_FIELD("version","uint32",0,4,SX_ID),
};
const sx_layout sxmw_sv_version={UINT32_C(0x60870044),"sv_version",sxmw_sv_version_fields,SX_COUNT(sxmw_sv_version_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_sv_base_version_fields[]={
 SX_FIELD("base_version","uint32",0,4,SX_ID),
};
const sx_layout sxmw_sv_base_version={UINT32_C(0x60870045),"sv_base_version",sxmw_sv_base_version_fields,SX_COUNT(sxmw_sv_base_version_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_sv_ticks_per_line_fields[]={
 SX_FIELD("ticks_per_line","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxmw_sv_ticks_per_line={UINT32_C(0x60870047),"sv_ticks_per_line",sxmw_sv_ticks_per_line_fields,SX_COUNT(sxmw_sv_ticks_per_line_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_sv_global_volume_fields[]={
 SX_FIELD("global_volume","uint32",0,4,SX_NONE),
};
const sx_layout sxmw_sv_global_volume={UINT32_C(0x6087004A),"sv_global_volume",sxmw_sv_global_volume_fields,SX_COUNT(sxmw_sv_global_volume_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_sv_module_scale_fields[]={
 SX_FIELD("module_scale","uint32",0,4,SX_NONE),
};
const sx_layout sxmw_sv_module_scale={UINT32_C(0x6087004B),"sv_module_scale",sxmw_sv_module_scale_fields,SX_COUNT(sxmw_sv_module_scale_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_sv_module_zoom_fields[]={
 SX_FIELD("module_zoom","uint32",0,4,SX_NONE),
};
const sx_layout sxmw_sv_module_zoom={UINT32_C(0x6087004C),"sv_module_zoom",sxmw_sv_module_zoom_fields,SX_COUNT(sxmw_sv_module_zoom_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_sv_module_x_fields[]={
 SX_FIELD("module_x","int32",0,4,SX_NONE),
};
const sx_layout sxmw_sv_module_x={UINT32_C(0x6087004D),"sv_module_x",sxmw_sv_module_x_fields,SX_COUNT(sxmw_sv_module_x_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_sv_module_y_fields[]={
 SX_FIELD("module_y","int32",0,4,SX_NONE),
};
const sx_layout sxmw_sv_module_y={UINT32_C(0x6087004E),"sv_module_y",sxmw_sv_module_y_fields,SX_COUNT(sxmw_sv_module_y_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_sv_layer_mask_fields[]={
 SX_FIELD("layer_mask","uint32",0,4,SX_FLAGS),
};
const sx_layout sxmw_sv_layer_mask={UINT32_C(0x6087004F),"sv_layer_mask",sxmw_sv_layer_mask_fields,SX_COUNT(sxmw_sv_layer_mask_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_sv_current_layer_fields[]={
 SX_FIELD("current_layer","uint32",0,4,SX_ID),
};
const sx_layout sxmw_sv_current_layer={UINT32_C(0x60870050),"sv_current_layer",sxmw_sv_current_layer_fields,SX_COUNT(sxmw_sv_current_layer_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_sv_selected_module_fields[]={
 SX_FIELD("selected_module","uint32",0,4,SX_ID),
};
const sx_layout sxmw_sv_selected_module={UINT32_C(0x60870053),"sv_selected_module",sxmw_sv_selected_module_fields,SX_COUNT(sxmw_sv_selected_module_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_sv_last_generator_fields[]={
 SX_FIELD("last_generator","uint32",0,4,SX_ID),
};
const sx_layout sxmw_sv_last_generator={UINT32_C(0x60870054),"sv_last_generator",sxmw_sv_last_generator_fields,SX_COUNT(sxmw_sv_last_generator_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_sv_tracks_fields[]={
 SX_FIELD("tracks","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxmw_sv_tracks={UINT32_C(0x60870055),"sv_tracks",sxmw_sv_tracks_fields,SX_COUNT(sxmw_sv_tracks_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_sv_lines_fields[]={
 SX_FIELD("lines","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxmw_sv_lines={UINT32_C(0x60870056),"sv_lines",sxmw_sv_lines_fields,SX_COUNT(sxmw_sv_lines_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_sv_source_pattern_fields[]={
 SX_FIELD("source_pattern","uint32",0,4,SX_ID),
};
const sx_layout sxmw_sv_source_pattern={UINT32_C(0x60870057),"sv_source_pattern",sxmw_sv_source_pattern_fields,SX_COUNT(sxmw_sv_source_pattern_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_sv_flags_fields[]={
 SX_FIELD("flags","uint32",0,4,SX_FLAGS),
};
const sx_layout sxmw_sv_flags={UINT32_C(0x60870058),"sv_flags",sxmw_sv_flags_fields,SX_COUNT(sxmw_sv_flags_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_sv_x_fields[]={
 SX_FIELD("x","int32",0,4,SX_NONE),
};
const sx_layout sxmw_sv_x={UINT32_C(0x60870059),"sv_x",sxmw_sv_x_fields,SX_COUNT(sxmw_sv_x_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_sv_y_fields[]={
 SX_FIELD("y","int32",0,4,SX_NONE),
};
const sx_layout sxmw_sv_y={UINT32_C(0x6087005A),"sv_y",sxmw_sv_y_fields,SX_COUNT(sxmw_sv_y_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_sv_finetune_fields[]={
 SX_FIELD("finetune","int32",0,4,SX_NONE),
};
const sx_layout sxmw_sv_finetune={UINT32_C(0x6087005B),"sv_finetune",sxmw_sv_finetune_fields,SX_COUNT(sxmw_sv_finetune_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_sv_relative_note_fields[]={
 SX_FIELD("relative_note","int32",0,4,SX_NONE),
};
const sx_layout sxmw_sv_relative_note={UINT32_C(0x6087005C),"sv_relative_note",sxmw_sv_relative_note_fields,SX_COUNT(sxmw_sv_relative_note_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_sv_layer_fields[]={
 SX_FIELD("layer","int32",0,4,SX_NONE),
};
const sx_layout sxmw_sv_layer={UINT32_C(0x6087005D),"sv_layer",sxmw_sv_layer_fields,SX_COUNT(sxmw_sv_layer_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_sv_scale_fields[]={
 SX_FIELD("scale","uint32",0,4,SX_NONE),
};
const sx_layout sxmw_sv_scale={UINT32_C(0x6087005E),"sv_scale",sxmw_sv_scale_fields,SX_COUNT(sxmw_sv_scale_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_sv_midi_in_fields[]={
 SX_FIELD("midi_in","uint32",0,4,SX_FLAGS),
};
const sx_layout sxmw_sv_midi_in={UINT32_C(0x6087005F),"sv_midi_in",sxmw_sv_midi_in_fields,SX_COUNT(sxmw_sv_midi_in_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_sv_midi_channel_fields[]={
 SX_FIELD("midi_channel","uint32",0,4,SX_ID),
};
const sx_layout sxmw_sv_midi_channel={UINT32_C(0x60870060),"sv_midi_channel",sxmw_sv_midi_channel_fields,SX_COUNT(sxmw_sv_midi_channel_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_sv_midi_bank_fields[]={
 SX_FIELD("midi_bank","int32",0,4,SX_ID),
};
const sx_layout sxmw_sv_midi_bank={UINT32_C(0x60870061),"sv_midi_bank",sxmw_sv_midi_bank_fields,SX_COUNT(sxmw_sv_midi_bank_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_sv_midi_program_fields[]={
 SX_FIELD("midi_program","int32",0,4,SX_ID),
};
const sx_layout sxmw_sv_midi_program={UINT32_C(0x60870062),"sv_midi_program",sxmw_sv_midi_program_fields,SX_COUNT(sxmw_sv_midi_program_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_sv_controller_value_fields[]={
 SX_FIELD("controller_value","uint32",0,4,SX_NONE),
};
const sx_layout sxmw_sv_controller_value={UINT32_C(0x60870064),"sv_controller_value",sxmw_sv_controller_value_fields,SX_COUNT(sxmw_sv_controller_value_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_sv_chunk_number_fields[]={
 SX_FIELD("chunk_number","uint32",0,4,SX_ID),
};
const sx_layout sxmw_sv_chunk_number={UINT32_C(0x60870065),"sv_chunk_number",sxmw_sv_chunk_number_fields,SX_COUNT(sxmw_sv_chunk_number_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_sv_chunk_format_fields[]={
 SX_FIELD("chunk_format","uint32",0,4,SX_FLAGS),
};
const sx_layout sxmw_sv_chunk_format={UINT32_C(0x60870067),"sv_chunk_format",sxmw_sv_chunk_format_fields,SX_COUNT(sxmw_sv_chunk_format_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_sv_color_fields[]={
 SX_FIELD("red","uint8",0,1,SX_NONE),
 SX_FIELD("green","uint8",1,1,SX_NONE),
 SX_FIELD("blue","uint8",2,1,SX_NONE),
};
const sx_layout sxmw_sv_color={UINT32_C(0x60870069),"sv_color",sxmw_sv_color_fields,SX_COUNT(sxmw_sv_color_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_sv_note_fields[]={
 SX_FIELD("note","uint8",0,1,SX_NONE),
 SX_FIELD("velocity","uint8",1,1,SX_NONE),
 SX_FIELD("module","uint8",2,1,SX_ID),
 SX_FIELD("reserved","uint8",3,1,SX_RESERVED),
 SX_FIELD("controller","uint8",4,1,SX_ID),
 SX_FIELD("effect","uint8",5,1,SX_ID),
 SX_FIELD("value","uint16",6,2,SX_NONE),
};
const sx_layout sxmw_sv_note={UINT32_C(0x6087006A),"sv_note",sxmw_sv_note_fields,SX_COUNT(sxmw_sv_note_fields),SX_LE};
#define MW_ROW(l,at,end) sxmw_row(v,&sxmw_##l,(at),(end))
#define MW_TAKE(l,p,n,end) sxmw_take(v,&sxmw_##l,(p),(n),(end))
typedef struct sxmw_sv_tag {const char *tag;const sx_layout *layout;}sxmw_sv_tag;
static const sxmw_sv_tag sxmw_sv_tags[]={
 {"VERS",&sxmw_sv_version},{"BVER",&sxmw_sv_base_version},{"BPM ",&sxmw_sv_tempo},{"SPED",&sxmw_sv_ticks_per_line},{"TGRD",&sxmw_sv_time_grid},{"TGD2",&sxmw_sv_time_grid2},{"GVOL",&sxmw_sv_global_volume},
 {"MSCL",&sxmw_sv_module_scale},{"MZOO",&sxmw_sv_module_zoom},{"MXOF",&sxmw_sv_module_x},{"MYOF",&sxmw_sv_module_y},{"LMSK",&sxmw_sv_layer_mask},{"CURL",&sxmw_sv_current_layer},{"TIME",&sxmw_sv_timeline_position},{"REPS",&sxmw_sv_restart_position},{"SELS",&sxmw_sv_selected_module},{"LGEN",&sxmw_sv_last_generator},
 {"PCHN",&sxmw_sv_tracks},{"PLIN",&sxmw_sv_lines},{"PPAR",&sxmw_sv_source_pattern},{"PFLG",&sxmw_sv_flags},{"PFFF",&sxmw_sv_flags},{"PXXX",&sxmw_sv_x},{"PYYY",&sxmw_sv_y},
 {"SFFF",&sxmw_sv_flags},{"SFIN",&sxmw_sv_finetune},{"SREL",&sxmw_sv_relative_note},{"SXXX",&sxmw_sv_x},{"SYYY",&sxmw_sv_y},{"SZZZ",&sxmw_sv_layer},{"SSCL",&sxmw_sv_scale},{"SMII",&sxmw_sv_midi_in},{"SMIC",&sxmw_sv_midi_channel},{"SMIB",&sxmw_sv_midi_bank},{"SMIP",&sxmw_sv_midi_program},{"CVAL",&sxmw_sv_controller_value},{"CHNK",&sxmw_sv_chunk_capacity},{"CHNM",&sxmw_sv_chunk_number},{"CHFF",&sxmw_sv_chunk_format},{"CHFR",&sxmw_sv_sample_rate}};
static bool sxmw_sv(sxmw_view*v)
{uint64_t end=v->c->size,p=8,n,ce;uint8_t tag[4];
 if(!sxmw_eq(v,0,"SVOX\0\0\0\0",8,end)||!MW_ROW(sunvox_header,0,end))return false;
 while(p<end){if(!sxmw_read(v,p,tag,4,end)||!sxmw_u(v,p+4,4,&n,end)||!sxmw_span(v,p+8,n,end)||!MW_TAKE(chunk_le,&p,1,end))return false;ce=p+n;
  if(n==4){for(size_t i=0;i<SX_COUNT(sxmw_sv_tags);i++)if(!xx_rt_memcmp(tag,sxmw_sv_tags[i].tag,4)){if(!sxmw_row(v,sxmw_sv_tags[i].layout,p,ce))return false;break;}}
  if((!xx_rt_memcmp(tag,"PFGC",4)||!xx_rt_memcmp(tag,"PBGC",4)||!xx_rt_memcmp(tag,"SCOL",4))&&n==3){if(!MW_ROW(sv_color,p,ce))return false;}
  else if(!xx_rt_memcmp(tag,"PDTA",4)&&n%8==0){if(!MW_TAKE(sv_note,&p,n/8,ce))return false;}
  else if(!xx_rt_memcmp(tag,"SLNK",4)&&n%4==0){if(!MW_TAKE(sv_link_module,&p,n/4,ce))return false;}
  else if(!xx_rt_memcmp(tag,"NAME",4)||!xx_rt_memcmp(tag,"PNME",4)||!xx_rt_memcmp(tag,"STYP",4)||!xx_rt_memcmp(tag,"SMIN",4)){if(n&&!sxmw_cstring(v,&p,ce,n))return false;}
  p=ce;
 }return true;}
bool sx_nightradio_sunvox_build(sxmw_view*v)
{
 return sxmw_sv(v);
}
#undef MW_ROW
#undef MW_TAKE
