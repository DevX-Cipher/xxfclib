/* SPDX-License-Identifier: MIT. Independently implemented physical music metadata. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_musicportable.h"

static const xx_data_struct_field_desc sxportable_proto_section_fields[]={
 SX_FIELD("tag","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("section_bytes","uint32",4,4,SX_SIZE),
};
const sx_layout sxportable_proto_section={0x60910001U,"proto_section",sxportable_proto_section_fields,SX_COUNT(sxportable_proto_section_fields),SX_LE};
static const xx_data_struct_field_desc sxportable_proto_dimensions_fields[]={
 SX_FIELD("pattern_rows_minus_one","uint8",0,1,SX_NONE),
 SX_FIELD("sequence_rows_minus_one","uint8",1,1,SX_NONE),
};
const sx_layout sxportable_proto_dimensions={0x60910006U,"proto_dimensions",sxportable_proto_dimensions_fields,SX_COUNT(sxportable_proto_dimensions_fields),SX_LE};
static const xx_data_struct_field_desc sxportable_proto_pattern_rows_fields[]={
 SX_FIELD("stored_row_count","uint8",0,1,SX_NONE),
};
const sx_layout sxportable_proto_pattern_rows={0x6091000aU,"proto_pattern_rows",sxportable_proto_pattern_rows_fields,SX_COUNT(sxportable_proto_pattern_rows_fields),SX_LE};
static const xx_data_struct_field_desc sxportable_tf4_instrument_fields[]={
 SX_FIELD("global_gain","uint8",0,1,SX_NONE),
 SX_FIELD("gen_bandwidth","uint8",1,1,SX_NONE),
 SX_FIELD("gen_numharmonics","uint8",2,1,SX_NONE),
 SX_FIELD("gen_damp","uint8",3,1,SX_NONE),
 SX_FIELD("gen_modulation","uint8",4,1,SX_NONE),
 SX_FIELD("gen_volume","uint8",5,1,SX_NONE),
 SX_FIELD("gen_panning","uint8",6,1,SX_NONE),
 SX_FIELD("gen_slop","uint8",7,1,SX_NONE),
 SX_FIELD("gen_octave","uint8",8,1,SX_NONE),
 SX_FIELD("gen_glide","uint8",9,1,SX_NONE),
 SX_FIELD("gen_detune","uint8",10,1,SX_NONE),
 SX_FIELD("gen_freq","uint8",11,1,SX_NONE),
 SX_FIELD("gen_polyphony","uint8",12,1,SX_NONE),
 SX_FIELD("gen_drive","uint8",13,1,SX_NONE),
 SX_FIELD("gen_unisono","uint8",14,1,SX_NONE),
 SX_FIELD("gen_spread","uint8",15,1,SX_NONE),
 SX_FIELD("gen_scale","uint8",16,1,SX_NONE),
 SX_FIELD("noise_amount","uint8",17,1,SX_NONE),
 SX_FIELD("noise_freq","uint8",18,1,SX_NONE),
 SX_FIELD("noise_bw","uint8",19,1,SX_NONE),
 SX_FIELD("lp_filter_on","uint8",20,1,SX_NONE),
 SX_FIELD("lp_filter_cutoff","uint8",21,1,SX_NONE),
 SX_FIELD("lp_filter_resonance","uint8",22,1,SX_NONE),
 SX_FIELD("hp_filter_on","uint8",23,1,SX_NONE),
 SX_FIELD("hp_filter_cutoff","uint8",24,1,SX_NONE),
 SX_FIELD("hp_filter_resonance","uint8",25,1,SX_NONE),
 SX_FIELD("adsr1_attack","uint8",26,1,SX_NONE),
 SX_FIELD("adsr1_decay","uint8",27,1,SX_NONE),
 SX_FIELD("adsr1_sustain","uint8",28,1,SX_NONE),
 SX_FIELD("adsr1_release","uint8",29,1,SX_NONE),
 SX_FIELD("adsr1_slope","uint8",30,1,SX_NONE),
 SX_FIELD("adsr2_attack","uint8",31,1,SX_NONE),
 SX_FIELD("adsr2_decay","uint8",32,1,SX_NONE),
 SX_FIELD("adsr2_sustain","uint8",33,1,SX_NONE),
 SX_FIELD("adsr2_release","uint8",34,1,SX_NONE),
 SX_FIELD("adsr2_slope","uint8",35,1,SX_NONE),
 SX_FIELD("lfo1_rate","uint8",36,1,SX_NONE),
 SX_FIELD("lfo1_depth","uint8",37,1,SX_NONE),
 SX_FIELD("lfo1_shape","uint8",38,1,SX_NONE),
 SX_FIELD("lfo1_sync","uint8",39,1,SX_NONE),
 SX_FIELD("lfo2_rate","uint8",40,1,SX_NONE),
 SX_FIELD("lfo2_depth","uint8",41,1,SX_NONE),
 SX_FIELD("lfo2_shape","uint8",42,1,SX_NONE),
 SX_FIELD("lfo2_sync","uint8",43,1,SX_NONE),
 SX_FIELD("mm1_source","uint8",44,1,SX_NONE),
 SX_FIELD("mm1_mod","uint8",45,1,SX_NONE),
 SX_FIELD("mm1_target","uint8",46,1,SX_NONE),
 SX_FIELD("mm2_source","uint8",47,1,SX_NONE),
 SX_FIELD("mm2_mod","uint8",48,1,SX_NONE),
 SX_FIELD("mm2_target","uint8",49,1,SX_NONE),
 SX_FIELD("mm3_source","uint8",50,1,SX_NONE),
 SX_FIELD("mm3_mod","uint8",51,1,SX_NONE),
 SX_FIELD("mm3_target","uint8",52,1,SX_NONE),
 SX_FIELD("mm4_source","uint8",53,1,SX_NONE),
 SX_FIELD("mm4_mod","uint8",54,1,SX_NONE),
 SX_FIELD("mm4_target","uint8",55,1,SX_NONE),
 SX_FIELD("mm5_source","uint8",56,1,SX_NONE),
 SX_FIELD("mm5_mod","uint8",57,1,SX_NONE),
 SX_FIELD("mm5_target","uint8",58,1,SX_NONE),
 SX_FIELD("mm6_source","uint8",59,1,SX_NONE),
 SX_FIELD("mm6_mod","uint8",60,1,SX_NONE),
 SX_FIELD("mm6_target","uint8",61,1,SX_NONE),
 SX_FIELD("mm7_source","uint8",62,1,SX_NONE),
 SX_FIELD("mm7_mod","uint8",63,1,SX_NONE),
 SX_FIELD("mm7_target","uint8",64,1,SX_NONE),
 SX_FIELD("mm8_source","uint8",65,1,SX_NONE),
 SX_FIELD("mm8_mod","uint8",66,1,SX_NONE),
 SX_FIELD("mm8_target","uint8",67,1,SX_NONE),
 SX_FIELD("mm9_source","uint8",68,1,SX_NONE),
 SX_FIELD("mm9_mod","uint8",69,1,SX_NONE),
 SX_FIELD("mm9_target","uint8",70,1,SX_NONE),
 SX_FIELD("mm10_source","uint8",71,1,SX_NONE),
 SX_FIELD("mm10_mod","uint8",72,1,SX_NONE),
 SX_FIELD("mm10_target","uint8",73,1,SX_NONE),
 SX_FIELD("effect_1","uint8",74,1,SX_NONE),
 SX_FIELD("effect_2","uint8",75,1,SX_NONE),
 SX_FIELD("effect_3","uint8",76,1,SX_NONE),
 SX_FIELD("effect_4","uint8",77,1,SX_NONE),
 SX_FIELD("effect_5","uint8",78,1,SX_NONE),
 SX_FIELD("effect_6","uint8",79,1,SX_NONE),
 SX_FIELD("effect_7","uint8",80,1,SX_NONE),
 SX_FIELD("effect_8","uint8",81,1,SX_NONE),
 SX_FIELD("effect_9","uint8",82,1,SX_NONE),
 SX_FIELD("effect_10","uint8",83,1,SX_NONE),
 SX_FIELD("distort_amount","uint8",84,1,SX_NONE),
 SX_FIELD("chorus_rate","uint8",85,1,SX_NONE),
 SX_FIELD("chorus_depth","uint8",86,1,SX_NONE),
 SX_FIELD("delay_left","uint8",87,1,SX_NONE),
 SX_FIELD("delay_right","uint8",88,1,SX_NONE),
 SX_FIELD("delay_decay","uint8",89,1,SX_NONE),
 SX_FIELD("reverb_roomsize","uint8",90,1,SX_NONE),
 SX_FIELD("reverb_damp","uint8",91,1,SX_NONE),
 SX_FIELD("reverb_wet","uint8",92,1,SX_NONE),
 SX_FIELD("reverb_width","uint8",93,1,SX_NONE),
 SX_FIELD("flanger_lfo","uint8",94,1,SX_NONE),
 SX_FIELD("flanger_frequency","uint8",95,1,SX_NONE),
 SX_FIELD("flanger_amplitude","uint8",96,1,SX_NONE),
 SX_FIELD("flanger_wet","uint8",97,1,SX_NONE),
 SX_FIELD("chorus_gain","uint8",98,1,SX_NONE),
 SX_FIELD("formant_mode","uint8",99,1,SX_NONE),
 SX_FIELD("formant_wet","uint8",100,1,SX_NONE),
 SX_FIELD("eq_low","uint8",101,1,SX_NONE),
 SX_FIELD("eq_mid","uint8",102,1,SX_NONE),
 SX_FIELD("eq_high","uint8",103,1,SX_NONE),
 SX_FIELD("pitchwheel_up","uint8",104,1,SX_NONE),
 SX_FIELD("pitchwheel_down","uint8",105,1,SX_NONE),
 SX_FIELD("bp_filter_on","uint8",106,1,SX_NONE),
 SX_FIELD("bp_filter_cutoff","uint8",107,1,SX_NONE),
 SX_FIELD("bp_filter_q","uint8",108,1,SX_NONE),
 SX_FIELD("nt_filter_on","uint8",109,1,SX_NONE),
 SX_FIELD("nt_filter_cutoff","uint8",110,1,SX_NONE),
 SX_FIELD("nt_filter_q","uint8",111,1,SX_NONE),
};
const sx_layout sxportable_tf4_instrument={0x60910013U,"tf4_instrument",sxportable_tf4_instrument_fields,SX_COUNT(sxportable_tf4_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxportable_tf4_row_delta_fields[]={
 SX_FIELD("row_delta","uint16",0,2,SX_NONE),
};
const sx_layout sxportable_tf4_row_delta={0x60910014U,"tf4_row_delta",sxportable_tf4_row_delta_fields,SX_COUNT(sxportable_tf4_row_delta_fields),SX_LE};
static const xx_data_struct_field_desc sxportable_ice_music_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("packed_bytes","uint32",4,4,SX_SIZE),
 SX_FIELD("unpacked_bytes","uint32",8,4,SX_SIZE),
};
const sx_layout sxportable_ice_music_header={0x60910017U,"ice_music_header",sxportable_ice_music_header_fields,SX_COUNT(sxportable_ice_music_header_fields),SX_BE};
static const xx_data_struct_field_desc sxportable_mgs_description_fields[]={
 SX_FIELD("encoded_description","uint8",0,0,SX_NONE),
};
const sx_layout sxportable_mgs_description={0x6091001aU,"mgs_description",sxportable_mgs_description_fields,SX_COUNT(sxportable_mgs_description_fields),SX_LE};
static const xx_data_struct_field_desc sxportable_bgm_channel_header_fields[]={
 SX_FIELD("loop_flag","uint8",0,1,SX_FLAGS),
 SX_FIELD("channel_0_address","uint16",1,2,SX_ADDRESS),
 SX_FIELD("channel_1_address","uint16",3,2,SX_ADDRESS),
 SX_FIELD("channel_2_address","uint16",5,2,SX_ADDRESS),
 SX_FIELD("channel_3_address","uint16",7,2,SX_ADDRESS),
 SX_FIELD("channel_4_address","uint16",9,2,SX_ADDRESS),
 SX_FIELD("channel_5_address","uint16",11,2,SX_ADDRESS),
 SX_FIELD("channel_6_address","uint16",13,2,SX_ADDRESS),
 SX_FIELD("channel_7_address","uint16",15,2,SX_ADDRESS),
 SX_FIELD("channel_8_address","uint16",17,2,SX_ADDRESS),
 SX_FIELD("channel_9_address","uint16",19,2,SX_ADDRESS),
 SX_FIELD("channel_10_address","uint16",21,2,SX_ADDRESS),
 SX_FIELD("channel_11_address","uint16",23,2,SX_ADDRESS),
 SX_FIELD("channel_12_address","uint16",25,2,SX_ADDRESS),
 SX_FIELD("channel_13_address","uint16",27,2,SX_ADDRESS),
 SX_FIELD("channel_14_address","uint16",29,2,SX_ADDRESS),
 SX_FIELD("channel_15_address","uint16",31,2,SX_ADDRESS),
 SX_FIELD("channel_16_address","uint16",33,2,SX_ADDRESS),
};
const sx_layout sxportable_bgm_channel_header={0x6091001dU,"bgm_channel_header",sxportable_bgm_channel_header_fields,SX_COUNT(sxportable_bgm_channel_header_fields),SX_LE};
static const xx_data_struct_field_desc sxportable_bgm_bto_header_fields[]={
 SX_FIELD("magic","char[3]",0,3,SX_SIGNATURE),
 SX_FIELD("unknown_bytes","uint8[6]",3,6,SX_NONE),
 SX_FIELD("metadata_load_address","uint16",9,2,SX_ADDRESS),
 SX_FIELD("title_address","uint16",11,2,SX_ADDRESS),
 SX_FIELD("extra_address","uint16",13,2,SX_ADDRESS),
};
const sx_layout sxportable_bgm_bto_header={0x6091001eU,"bgm_bto_header",sxportable_bgm_bto_header_fields,SX_COUNT(sxportable_bgm_bto_header_fields),SX_LE};
static const xx_data_struct_field_desc sxportable_bgm_encoded_text_fields[]={
 SX_FIELD("encoded_text","uint8",0,0,SX_NONE),
};
const sx_layout sxportable_bgm_encoded_text={0x6091001fU,"bgm_encoded_text",sxportable_bgm_encoded_text_fields,SX_COUNT(sxportable_bgm_encoded_text_fields),SX_LE};
static const xx_data_struct_field_desc sxportable_ntk_identity_fields[]={
 SX_FIELD("magic","char[7]",0,7,SX_SIGNATURE),
 SX_FIELD("version","char[1]",7,1,SX_NONE),
 SX_FIELD("nul","uint8",8,1,SX_NONE),
};
static const sx_layout sxportable_ntk_identity={0x60910020U,"ntk_identity",sxportable_ntk_identity_fields,SX_COUNT(sxportable_ntk_identity_fields),SX_LE};
static const xx_data_struct_field_desc sxportable_ntk_song_info_fields[]={
 SX_FIELD("title","char[20]",0,20,SX_NONE),
 SX_FIELD("pattern_count","uint8",20,1,SX_COUNT_PROP),
 SX_FIELD("sequence_length","uint8",21,1,SX_COUNT_PROP),
};
static const sx_layout sxportable_ntk_song_info={0x60910021U,"ntk_song_info",sxportable_ntk_song_info_fields,SX_COUNT(sxportable_ntk_song_info_fields),SX_LE};
static const xx_data_struct_field_desc sxportable_ntk_sequence_fields[]={
 SX_FIELD("pattern_index","uint8[256]",0,256,SX_NONE),
};
static const sx_layout sxportable_ntk_sequence={0x60910022U,"ntk_sequence",sxportable_ntk_sequence_fields,SX_COUNT(sxportable_ntk_sequence_fields),SX_LE};
static const xx_data_struct_field_desc sxportable_ntk_pattern_lines_fields[]={
 SX_FIELD("line_count","int16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxportable_ntk_pattern_lines={0x60910023U,"ntk_pattern_lines",sxportable_ntk_pattern_lines_fields,SX_COUNT(sxportable_ntk_pattern_lines_fields),SX_LE};
static const xx_data_struct_field_desc sxportable_ptk_packed_header_fields[]={
 SX_FIELD("magic","char[7]",0,7,SX_SIGNATURE),
 SX_FIELD("version","char[1]",7,1,SX_NONE),
 SX_FIELD("nul","uint8",8,1,SX_NONE),
 SX_FIELD("unpacked_bytes","int32",9,4,SX_SIZE),
};
static const sx_layout sxportable_ptk_packed_header={0x60910024U,"ptk_packed_header",sxportable_ptk_packed_header_fields,SX_COUNT(sxportable_ptk_packed_header_fields),SX_LE};
static const xx_data_struct_field_desc sxportable_psy2_event_fields[]={
 SX_FIELD("note","uint8",0,1,SX_NONE),
 SX_FIELD("instrument","uint8",1,1,SX_NONE),
 SX_FIELD("machine","uint8",2,1,SX_NONE),
 SX_FIELD("command","uint8",3,1,SX_NONE),
 SX_FIELD("parameter","uint8",4,1,SX_NONE),
};
const sx_layout sxportable_psy2_event={0x60910027U,"psy2_event",sxportable_psy2_event_fields,SX_COUNT(sxportable_psy2_event_fields),SX_LE};
static const xx_data_struct_field_desc sxportable_psy3_chunk_fields[]={
 SX_FIELD("tag","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_NONE),
 SX_FIELD("body_bytes","uint32",8,4,SX_SIZE),
};
const sx_layout sxportable_psy3_chunk={0x60910029U,"psy3_chunk",sxportable_psy3_chunk_fields,SX_COUNT(sxportable_psy3_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxportable_psy3_song_info_fields[]={
 SX_FIELD("track_count","int32",0,4,SX_COUNT_PROP),
 SX_FIELD("tempo_coarse","int16",4,2,SX_NONE),
 SX_FIELD("tempo_hundredths","int16",6,2,SX_NONE),
 SX_FIELD("lines_per_beat","int32",8,4,SX_NONE),
 SX_FIELD("octave","int32",12,4,SX_NONE),
 SX_FIELD("solo_machine","int32",16,4,SX_NONE),
 SX_FIELD("solo_track","int32",20,4,SX_NONE),
 SX_FIELD("sequence_bus","int32",24,4,SX_NONE),
 SX_FIELD("midi_selected","int32",28,4,SX_NONE),
 SX_FIELD("aux_column_selected","int32",32,4,SX_NONE),
 SX_FIELD("instrument_selected","int32",36,4,SX_NONE),
 SX_FIELD("sequence_width","int32",40,4,SX_NONE),
};
const sx_layout sxportable_psy3_song_info={0x6091002fU,"psy3_song_info",sxportable_psy3_song_info_fields,SX_COUNT(sxportable_psy3_song_info_fields),SX_LE};
static const xx_data_struct_field_desc sxportable_psy3_compressed_bytes_fields[]={
 SX_FIELD("compressed_bytes","uint32",0,4,SX_SIZE),
};
const sx_layout sxportable_psy3_compressed_bytes={0x60910034U,"psy3_compressed_bytes",sxportable_psy3_compressed_bytes_fields,SX_COUNT(sxportable_psy3_compressed_bytes_fields),SX_LE};
static const sx_layout*const sx_musicportable_layouts[]={&sxportable_proto_section,&sxportable_proto_version0,&sxportable_proto_version1,&sxportable_proto_version17,&sxportable_proto_text,&sxportable_proto_dimensions,&sxportable_proto_sequence_row_count,&sxportable_proto_pattern_count,&sxportable_proto_macro_count,&sxportable_proto_pattern_rows,&sxportable_proto_sequence_pattern_index_plane,&sxportable_proto_note_effect_plane,&sxportable_proto_note_parameter_plane,&sxportable_proto_effect_plane,&sxportable_proto_effect_parameter_plane,&sxportable_tf4_song_header,&sxportable_tf4_event_count,&sxportable_tf4_tag,&sxportable_tf4_instrument,&sxportable_tf4_row_delta,&sxportable_tf4_note_plane,&sxportable_tf4_velocity_plane,&sxportable_ice_music_header,&sxportable_mgs_identity,&sxportable_mgs_identity_single_newline,&sxportable_mgs_description,&sxportable_mgs_text_end,&sxportable_bgm_bsave_header,&sxportable_bgm_channel_header,&sxportable_bgm_bto_header,&sxportable_bgm_encoded_text,&sxportable_ntk_identity,&sxportable_ntk_song_info,&sxportable_ntk_sequence,&sxportable_ntk_pattern_lines,&sxportable_ptk_packed_header,&sxportable_psy2_header,&sxportable_psy2_pattern_header,&sxportable_psy2_event,&sxportable_psy3_header,&sxportable_psy3_chunk,&sxportable_psy3_title,&sxportable_psy3_author,&sxportable_psy3_comment,&sxportable_psy3_sequence_name,&sxportable_psy3_pattern_name,&sxportable_psy3_song_info,&sxportable_psy3_track_state,&sxportable_psy3_sequence,&sxportable_psy3_pattern_index,&sxportable_psy3_pattern,&sxportable_psy3_compressed_bytes};
static bool sx_musicportable_supports(xx_file_type_t t)
{
    switch(t){
    case XX_FILE_TYPE_DIE_MUSIC_KOMETBOMB_PROTOTRACKER_SONG:
    case XX_FILE_TYPE_DIE_MUSIC_BRAINCONTROL_TUNEFISH_TF4:
    case XX_FILE_TYPE_DIE_MUSIC_ATARIST_SNDH:
    case XX_FILE_TYPE_DIE_MUSIC_GIGAMIX_MGSDRV:
    case XX_FILE_TYPE_DIE_MUSIC_ASCII_MUSICA_BGM:
    case XX_FILE_TYPE_DIE_MUSIC_ARGURU_NOISETREKKER:
    case XX_FILE_TYPE_DIE_MUSIC_ARGURU_PROTREKKR_SNG6_PROTREK:
    case XX_FILE_TYPE_DIE_MUSIC_SEGURA_PSYCLEMMCS:return true;
    default:return false;
    }
}
bool sxportable_span(sx_context*c,uint64_t p,uint64_t n,uint64_t end)
{return c&&c->size>=0&&end<=(uint64_t)c->size&&p<=end&&n<=end-p&&!xx_pd_is_stopped(c->pd);}
bool sxportable_read(sx_context*c,uint64_t p,void*b,size_t n,uint64_t end)
{return sxportable_span(c,p,n,end)&&sx_read(c,(int64_t)p,b,n);}
bool sxportable_byte(sx_context*c,uint64_t p,uint8_t*b,uint64_t end)
{return sxportable_read(c,p,b,1,end);}
bool sxportable_row(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n,uint64_t end)
{return sxportable_span(c,p,n,end)&&sx_add(c,l,(int64_t)p,(int64_t)n);}
bool sxportable_plane(sx_context*c,const sx_layout*l,uint64_t*p,uint64_t n,uint64_t end)
{
    if(!sxportable_span(c,*p,n,end))return false;
    uint64_t shown=n>4096?4096:n;
    if(shown&&!sx_add(c,l,(int64_t)*p,(int64_t)shown))return false;
    *p+=n;return true;
}
bool sxportable_string(sx_context*c,const sx_layout*l,uint64_t*p,uint64_t end)
{
    uint64_t start=*p;uint8_t b;
    while(*p<end&&*p-start<4096){
        if(!sxportable_byte(c,(*p)++,&b,end))return false;
        if(!b)return sxportable_row(c,l,start,*p-start,end);
    }
    return false;
}
static int sxportable_order(const void*a,const void*b)
{const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxportable_finish(sx_context*c)
{
    size_t n=c->count;uint64_t end=0;
    xx_rt_qsort(c->items,n,sizeof(*c->items),sxportable_order);
    for(size_t i=0;i<n;i++){
        uint64_t at=(uint64_t)(c->items[i].offset-c->f->base_address),z=(uint64_t)c->items[i].total_size;
        if(at<end)return false;
        if(at>end&&!sx_raw(c,(int64_t)end,(int64_t)(at-end)))return false;
        end=at+z;
    }
    if(end<(uint64_t)c->size&&!sx_raw(c,(int64_t)end,c->size-(int64_t)end))return false;
    xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxportable_order);
    return !c->failed&&!xx_pd_is_stopped(c->pd);
}
static bool sxportable_ntk(sx_context*c)
{
    uint8_t h[13];uint64_t end=(uint64_t)c->size;
    if(!sxportable_read(c,0,h,9,end)||h[8]||
       (xx_rt_memcmp(h,"TWNNSNG",7)&&xx_rt_memcmp(h,"PROTREK",7)))return false;
    uint8_t v=h[7];
    if(c->f->file_type==XX_FILE_TYPE_DIE_MUSIC_ARGURU_NOISETREKKER){
        if(xx_rt_memcmp(h,"TWNNSNG",7)||(v!='1'&&v!='2'))return false;
    }else if(v>='B'&&v<='X'){
        if(!sxportable_read(c,0,h,13,end)||!xx_data_get_u32(h,13,9,false))return false;
        return sxportable_row(c,&sxportable_ptk_packed_header,0,13,end);
    }else if(v<'3'||v>'8')return false;
    if(!sxportable_row(c,&sxportable_ntk_identity,0,9,end)||
       !sxportable_row(c,&sxportable_ntk_song_info,9,22,end)||
       !sxportable_row(c,&sxportable_ntk_sequence,31,256,end))return false;
    return v=='1'||(sxportable_span(c,287,256,end)&&sx_table(c,&sxportable_ntk_pattern_lines,287,2,128));
}
static bool sx_musicportable_build(sx_context*c)
{
    if(!c||!c->f||!sx_musicportable_supports(c->f->file_type)||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid||c->size<0)return false;
    bool ok=false;
    switch(c->f->file_type){
    case XX_FILE_TYPE_DIE_MUSIC_KOMETBOMB_PROTOTRACKER_SONG:ok=sx_kometbomb_prototracker_song_build(c);break;
    case XX_FILE_TYPE_DIE_MUSIC_BRAINCONTROL_TUNEFISH_TF4:ok=sx_braincontrol_tunefish_tf4_build(c);break;
    case XX_FILE_TYPE_DIE_MUSIC_ATARIST_SNDH:ok=sx_atarist_sndh_build(c);break;
    case XX_FILE_TYPE_DIE_MUSIC_GIGAMIX_MGSDRV:ok=sx_gigamix_mgsdrv_build(c);break;
    case XX_FILE_TYPE_DIE_MUSIC_ASCII_MUSICA_BGM:ok=sx_ascii_musica_bgm_build(c);break;
    case XX_FILE_TYPE_DIE_MUSIC_ARGURU_NOISETREKKER:
    case XX_FILE_TYPE_DIE_MUSIC_ARGURU_PROTREKKR_SNG6_PROTREK:ok=sxportable_ntk(c);break;
    case XX_FILE_TYPE_DIE_MUSIC_SEGURA_PSYCLEMMCS:ok=sx_segura_psyclemmcs_build(c);break;
    default:break;
    }
    return ok&&sxportable_finish(c);
}
static bool sx_musicportable_comment(xx_data_struct_record*r,uint32_t id)
{
    if(!r||!r->name||id<0x60910001U||id>sxportable_psy3_compressed_bytes.id)return true;
    const wchar_t*text=L"Physical stored value; unparsed music commands and transformed payloads remain raw.";
    if(id==sxportable_proto_section.id)text=L"Little-endian section size includes its eight-byte header. The original writer is authoritative; its FORMAT.TXT incorrectly says big-endian.";
    else if(id==sxportable_proto_dimensions.id)text=L"Stored row count minus one; the decoded dimension is this byte plus one.";
    else if(id==sxportable_proto_pattern_rows.id)text=L"Stored rows in this pattern; 255 represents 256 rows. It is independent of the display dimension.";
    else if(id==sxportable_tf4_instrument.id)text=L"Original TuneFish4 parameter byte. The player divides this byte by 100; the displayed member preserves the encoded integer.";
    else if(id==sxportable_tf4_row_delta.id)text=L"Little-endian row delta. Playback accumulates it; the cumulative time is not stored here.";
    else if(id==sxportable_ice_music_header.id)text=L"Physical ICE packing header, big-endian sizes. The packed size includes the header. No decompressed SNDH tags or payload authenticity are claimed.";
    else if(id==sxportable_bgm_channel_header.id)text=L"Loop flag and seventeen stored Z80 addresses. Address zero denotes an absent channel; other addresses use the BSAVE load base.";
    else if(id==sxportable_bgm_bto_header.id)text=L"Optional Kinrou5 BTO metadata. Stored addresses map to file position 7 + address - metadata_load_address. Unknown bytes are preserved.";
    else if(id==sxportable_mgs_description.id||id==sxportable_bgm_encoded_text.id)text=L"Original encoded description bytes, commonly Shift-JIS; no lossy text conversion is applied.";
    else if(id==sxportable_ptk_packed_header.id)text=L"ProTrekkr versions B through X store this unpacked byte count before the compressed body. Only physical header fields are decoded.";
    else if(id==sxportable_psy2_event.id)text=L"Physical five-byte PSY2 event cell. Each stored row contains 32 cells, including inactive channel slots; no playback conversion is applied.";
    else if(id==sxportable_psy3_chunk.id)text=L"Stored chunk size excludes its twelve-byte header. Original version-zero INFO, SNGI and PATD writers have documented size bugs; traversal follows the original reader's corrections.";
    else if(id==sxportable_psy3_song_info.id)text=L"Physical PSY3 version-zero song settings. Tempo is stored as a coarse value and separate hundredths; both are displayed as stored.";
    return xx_data_struct_record_set_comment(r,text);
}
const sx_family sx_musicportable_family={sx_musicportable_supports,sx_musicportable_build,sx_musicportable_layouts,SX_COUNT(sx_musicportable_layouts),sx_musicportable_comment};
