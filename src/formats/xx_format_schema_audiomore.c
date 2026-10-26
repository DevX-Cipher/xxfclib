/* Copyright (c)2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical audio-container and stream metadata; coded payload stays raw. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_audiomore.h"
static const xx_data_struct_field_desc sxau_xact_name_fields[]={
 SX_FIELD("name","char[64]",0,64,SX_STRING),
};
const sx_layout sxau_xact_name={UINT32_C(0x602C000A),"xact_name",sxau_xact_name_fields,SX_COUNT(sxau_xact_name_fields),SX_LE};
static const xx_data_struct_field_desc sxau_adts_header_fields[]={
 SX_FIELD("sync_id_layer_protection","uint16",0,2,SX_FLAGS),
 SX_FIELD("profile_sampling_private_channel_high","uint8",2,1,SX_FLAGS),
 SX_FIELD("channel_low_original_home_copyright_length_high","uint8",3,1,SX_FLAGS),
 SX_FIELD("frame_length_middle","uint8",4,1,SX_FLAGS),
 SX_FIELD("length_low_buffer_fullness_high","uint8",5,1,SX_FLAGS),
 SX_FIELD("fullness_low_raw_block_count","uint8",6,1,SX_FLAGS),
};
static const sx_layout sxau_adts_header={UINT32_C(0x602C0033),"adts_header",sxau_adts_header_fields,SX_COUNT(sxau_adts_header_fields),SX_BE};
static const xx_data_struct_field_desc sxau_adts_crc_fields[]={
 SX_FIELD("crc","uint16",0,2,SX_CHECKSUM),
};
static const sx_layout sxau_adts_crc={UINT32_C(0x602C0034),"adts_crc",sxau_adts_crc_fields,SX_COUNT(sxau_adts_crc_fields),SX_BE};
static const sx_layout *const sx_audiomore_layouts[]={
 &sxau_awb_header,
 &sxau_awb_id16,
 &sxau_awb_offset16,
 &sxau_awb_id32,
 &sxau_awb_offset32,
 &sxau_xwb_header,
 &sxau_xwb_segment,
 &sxau_xwb_bank_data,
 &sxau_xwb_entry,
 &sxau_xact_name,
 &sxau_xsb_header,
 &sxau_xsb_cue,
 &sxau_xsb_simple_sound,
 &sxau_ast_header,
 &sxau_ast_block,
 &sxau_hca_header,
 &sxau_hca_format,
 &sxau_hca_compression,
 &sxau_hca_ath,
 &sxau_hca_loop,
 &sxau_hca_cipher,
 &sxau_hca_relative_volume,
 &sxau_hca_comment,
 &sxau_hca_pad,
 &sxau_hca_checksum,
 &sxau_hca_frame_sync,
 &sxau_iff8svx_form,
 &sxau_iff8svx_chunk,
 &sxau_iff8svx_voice,
 &sxau_iff8svx_channel,
 &sxau_vgm_header,
 &sxau_vgm_gd3,
 &sxau_vgm_command,
 &sxau_vgm_register8,
 &sxau_vgm_register16,
 &sxau_vgm_wait,
 &sxau_vgm_data_block,
 &sxau_vgm_pcm_seek,
 &sxau_vgm_dac_setup,
 &sxau_vgm_dac_data,
 &sxau_vgm_dac_frequency,
 &sxau_vgm_dac_start,
 &sxau_vgm_dac_stop,
 &sxau_vgm_dac_fast_start,
 &sxau_ac3_sync_info,
 &sxau_ac3_checksum2,
 &sxau_mp3_frame_header,
 &sxau_id3_header,
 &sxau_id3v23_frame,
 &sxau_id3v24_frame,
 &sxau_adts_header,
 &sxau_adts_crc,
 &sxau_ape_descriptor,
 &sxau_ape_header,
 &sxau_ape_seek,
 &sxau_ape_tag,
 &sxau_ape_tag_item,
 &sxau_sdif_header,
 &sxau_sdif_frame,
 &sxau_sdif_matrix,
 &sxau_sap_binary_marker,
 &sxau_sap_load_segment,
 &sxau_sc68_header,
 &sxau_sc68_chunk,
 &sxau_sc68_default,
 &sxau_sc68_load_address,
 &sxau_sc68_integer,
 &sxau_amiga_ahx_header,
 &sxau_amiga_ahx_subsong,
 &sxau_amiga_ahx_channel_order,
 &sxau_amiga_ahx_instrument,
 &sxau_amiga_ahx_playlist,
 &sxau_vab_header,
 &sxau_vab_program,
 &sxau_vab_tone,
 &sxau_vab_sample_size,
 &sxau_ay_header,
 &sxau_ay_track_index,
 &sxau_ay_track,
 &sxau_ay_cpu_state,
 &sxau_ay_block,
 &sxau_ay_blocks_end,
 &sxau_fsb1_header,
 &sxau_fsb1_sample,
 &sxau_fsb2_header,
 &sxau_fsb34_version,
 &sxau_fsb4_hash,
 &sxau_fsb_sample,
 &sxau_fsb_sample_basic,
 &sxau_fsb5_header,
 &sxau_fsb5_sample,
 &sxau_fsb5_chunk,
 &sxau_fsb5_channels,
 &sxau_fsb5_frequency,
 &sxau_fsb5_name_offset,
 &sxau_acm_header,
 &sxau_cri_ahx_header,
 &sxau_cri_ahx_copyright,
 &sxau_cri_ahx_footer,
 &sxau_dss_header,
 &sxau_ea_block_le,
 &sxau_nitro_header_le,
 &sxau_nitro_chunk_le,
 &sxau_nitro_stream_le,
 &sxau_paf_header_le,
 &sxau_ea_block_be,
 &sxau_nitro_header_be,
 &sxau_nitro_chunk_be,
 &sxau_nitro_stream_be,
 &sxau_paf_header_be,
 &sxau_abylight_header,
 &sxau_alp_header,
 &sxau_alp_sample_rate,
 &sxau_pmm_header,
 &sxau_pmm_sample,
 &sxau_pmm_instrument,
};
static bool sx_audiomore_supports(xx_file_type_t t)
{switch(t){
case XX_FILE_TYPE_CRI_AWB:case XX_FILE_TYPE_MICROSOFT_XWB:case XX_FILE_TYPE_MICROSOFT_XSB:case XX_FILE_TYPE_AUDIO_AST:case XX_FILE_TYPE_AUDIO_HCA:case XX_FILE_TYPE_IFF_8SVX:case XX_FILE_TYPE_VGM_LOG:case XX_FILE_TYPE_AUDIO_DOLBY_AC3:case XX_FILE_TYPE_AUDIO_MPEG_MP3:case XX_FILE_TYPE_AUDIO_AAC_ADTS:case XX_FILE_TYPE_AUDIO_MONKEYS_APE:case XX_FILE_TYPE_IRCAM_SDIF:case XX_FILE_TYPE_ATARI_SAP:case XX_FILE_TYPE_SC68_MUSIC:case XX_FILE_TYPE_AMIGA_AHX:case XX_FILE_TYPE_SONY_VAB:case XX_FILE_TYPE_ZX_AYEMUL:case XX_FILE_TYPE_FMOD_SAMPLE_BANK:case XX_FILE_TYPE_INTERPLAY_ACM:case XX_FILE_TYPE_CRI_AHX:case XX_FILE_TYPE_OLYMPUS_DSS:case XX_FILE_TYPE_EA_EXA:case XX_FILE_TYPE_AUDIO_NITRO_STRM:case XX_FILE_TYPE_ENSONIQ_PAF:case XX_FILE_TYPE_ABYLIGHT_STRM:case XX_FILE_TYPE_LEGO_ALP:case XX_FILE_TYPE_PARSEC_PMM:return true;default:return false;}}
bool sxau_need(sxau_view *v,size_t at,uint64_t n,size_t end){return !xx_pd_is_stopped(v->c->pd)&&end<=v->n&&at<=end&&n<=end-at;}
uint16_t sxau_u16(const uint8_t*p,bool be){return xx_data_get_u16(p,2,0,be);}
uint32_t sxau_u32(const uint8_t*p,bool be){return xx_data_get_u32(p,4,0,be);}
bool sxau_row(sxau_view *v,const sx_layout*l,size_t at,size_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;size_t n=(size_t)(f->rel_offset+f->size);if(++v->work>4000000||!sxau_need(v,at,n,end))return false;return v->c->count>=24000||sx_add(v->c,l,(int64_t)at,(int64_t)n);}
#define SA_ROW(l,at,end) sxau_row(v,&sxau_##l,(at),(end))
bool sxau_table(sxau_view*v,const sx_layout*l,size_t at,uint64_t count,size_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;size_t z=(size_t)(f->rel_offset+f->size);if(count>4000000||!sxau_need(v,at,count*z,end))return false;for(uint64_t i=0;i<count;i++,at+=z)if(!sxau_row(v,l,at,end))return false;return true;}
static int sxau_order(const void*aa,const void*bb){const xx_data_struct*a=aa,*b=bb;if(a->offset!=b->offset)return a->offset<b->offset?-1:1;return a->total_size<b->total_size?-1:a->total_size>b->total_size?1:0;}
static bool sxau_finish(sx_context*c)
{size_t n=c->count,keep=0;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxau_order);
 /* AY permits shared descriptor ranges. Keep one physical interpretation;
  * never repeat identical source bytes as overlapping structures. */
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(at<end)continue;c->items[keep++]=c->items[i];end=at+z;}c->count=keep;n=keep;end=0;
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(at>end&&!sx_raw(c,end,at-end))return false;end=at+z;}
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxau_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
bool sxau_adts(sxau_view*v,size_t at,size_t end)
{while(at<end){if(!SA_ROW(adts_header,at,end))return false;size_t z=((v->p[at+3]&3)<<11)|(v->p[at+4]<<3)|(v->p[at+5]>>5),h=(v->p[at+1]&1)?7:9;if(z<h||!sxau_need(v,at,z,end))return false;if(h==9&&!SA_ROW(adts_crc,at+7,at+z))return false;at+=z;}return at==end;}
static bool sx_audiomore_build(sx_context*c)
{if(!c||!c->f||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid||c->size<=0||c->size>134217728)return false;sxau_view view={c,NULL,(size_t)c->size,0},*v=&view;v->p=(uint8_t*)xx_mem_alloc(v->n);if(!v->p||!sx_read(c,0,v->p,v->n)){if(v->p)xx_mem_free(v->p);return false;}bool ok=false;
 switch(c->f->file_type){case XX_FILE_TYPE_CRI_AWB:ok=sx_cri_awb_build(v);break;case XX_FILE_TYPE_MICROSOFT_XWB:ok=sx_microsoft_xwb_build(v);break;case XX_FILE_TYPE_MICROSOFT_XSB:ok=sx_microsoft_xsb_build(v);break;case XX_FILE_TYPE_AUDIO_AST:ok=sx_audio_ast_build(v);break;case XX_FILE_TYPE_AUDIO_HCA:ok=sx_audio_hca_build(v);break;case XX_FILE_TYPE_IFF_8SVX:ok=sx_iff_8svx_build(v);break;case XX_FILE_TYPE_VGM_LOG:ok=sx_vgm_log_build(v);break;case XX_FILE_TYPE_AUDIO_DOLBY_AC3:ok=sx_audio_dolby_ac3_build(v);break;case XX_FILE_TYPE_AUDIO_MPEG_MP3:ok=sx_audio_mpeg_mp3_build(v);break;case XX_FILE_TYPE_AUDIO_AAC_ADTS:ok=sx_audio_aac_adts_build(v);break;case XX_FILE_TYPE_AUDIO_MONKEYS_APE:ok=sx_audio_monkeys_ape_build(v);break;case XX_FILE_TYPE_IRCAM_SDIF:ok=sx_ircam_sdif_build(v);break;case XX_FILE_TYPE_ATARI_SAP:ok=sx_atari_sap_build(v);break;case XX_FILE_TYPE_SC68_MUSIC:ok=sx_sc68_music_build(v);break;case XX_FILE_TYPE_AMIGA_AHX:ok=sx_amiga_ahx_build(v);break;case XX_FILE_TYPE_SONY_VAB:ok=sx_sony_vab_build(v);break;case XX_FILE_TYPE_ZX_AYEMUL:ok=sx_zx_ayemul_build(v);break;case XX_FILE_TYPE_FMOD_SAMPLE_BANK:ok=sx_fmod_sample_bank_build(v);break;case XX_FILE_TYPE_INTERPLAY_ACM:ok=sx_interplay_acm_build(v);break;case XX_FILE_TYPE_CRI_AHX:ok=sx_cri_ahx_build(v);break;case XX_FILE_TYPE_OLYMPUS_DSS:ok=sx_olympus_dss_build(v);break;case XX_FILE_TYPE_EA_EXA:ok=sx_ea_exa_build(v);break;case XX_FILE_TYPE_AUDIO_NITRO_STRM:ok=sx_audio_nitro_strm_build(v);break;case XX_FILE_TYPE_ENSONIQ_PAF:ok=sx_ensoniq_paf_build(v);break;case XX_FILE_TYPE_ABYLIGHT_STRM:ok=sx_abylight_strm_build(v);break;case XX_FILE_TYPE_LEGO_ALP:ok=sx_lego_alp_build(v);break;case XX_FILE_TYPE_PARSEC_PMM:ok=sx_parsec_pmm_build(v);break;default:break;}
 xx_mem_free(v->p);return ok&&sxau_finish(c);}
#undef SA_ROW
static bool sx_audiomore_comment(xx_data_struct_record*r,uint32_t id)
{
 if(!r||!r->name||id<(int32_t)UINT32_C(0x602c0000)||id>=(int32_t)UINT32_C(0x602d0000))return true;
 if(id==1613496334&&!xx_rt_wcscmp(r->name,L"encoding")){switch(xx_var_get_u64(&r->value)){
 case 1:return xx_data_struct_record_set_comment(r,L"PCM");
 default:break;}}
 if(id==1613496336&&!xx_rt_wcscmp(r->name,L"version")){switch(xx_var_get_u64(&r->value)){
 case 512:return xx_data_struct_record_set_comment(r,L"HCA2.0");
 default:break;}}
 if(id==1613496341&&!xx_rt_wcscmp(r->name,L"cipher_type")){switch(xx_var_get_u64(&r->value)){
 case 0:return xx_data_struct_record_set_comment(r,L"HCA_CIPHER_NONE");
 case 1:return xx_data_struct_record_set_comment(r,L"HCA_CIPHER1");
 case 56:return xx_data_struct_record_set_comment(r,L"HCA_CIPHER56");
 default:break;}}
 if(id==1613496339&&!xx_rt_wcscmp(r->name,L"ath_type")){switch(xx_var_get_u64(&r->value)){
 case 0:return xx_data_struct_record_set_comment(r,L"ATH_DISABLED");
 case 1:return xx_data_struct_record_set_comment(r,L"ATH_ENABLED");
 default:break;}}
 if(id==1613496349&&!xx_rt_wcscmp(r->name,L"compression")){switch(xx_var_get_u64(&r->value)){
 case 0:return xx_data_struct_record_set_comment(r,L"CMP_NONE");
 case 1:return xx_data_struct_record_set_comment(r,L"CMP_FIBDELTA");
 default:break;}}
 if(id==1613496350&&!xx_rt_wcscmp(r->name,L"channel_assignment")){switch(xx_var_get_u64(&r->value)){
 case 2:return xx_data_struct_record_set_comment(r,L"LEFT");
 case 4:return xx_data_struct_record_set_comment(r,L"RIGHT");
 case 6:return xx_data_struct_record_set_comment(r,L"STEREO");
 default:break;}}
 if(id==1613496374&&!xx_rt_wcscmp(r->name,L"compression_level")){switch(xx_var_get_u64(&r->value)){
 case 1000:return xx_data_struct_record_set_comment(r,L"FAST");
 case 2000:return xx_data_struct_record_set_comment(r,L"NORMAL");
 case 3000:return xx_data_struct_record_set_comment(r,L"HIGH");
 case 4000:return xx_data_struct_record_set_comment(r,L"EXTRA_HIGH");
 case 5000:return xx_data_struct_record_set_comment(r,L"INSANE");
 default:break;}}
 if(id==1613496417&&!xx_rt_wcscmp(r->name,L"encoding")){switch(xx_var_get_u64(&r->value)){
 case 16:return xx_data_struct_record_set_comment(r,L"AHX_LOW_RATE");
 case 17:return xx_data_struct_record_set_comment(r,L"AHX_STANDARD");
 default:break;}}
 if(id==1613496417&&!xx_rt_wcscmp(r->name,L"encryption_type")){switch(xx_var_get_u64(&r->value)){
 case 0:return xx_data_struct_record_set_comment(r,L"UNENCRYPTED");
 case 8:return xx_data_struct_record_set_comment(r,L"KEY8");
 case 9:return xx_data_struct_record_set_comment(r,L"KEY9");
 default:break;}}
 if(id==1613496424&&!xx_rt_wcscmp(r->name,L"encoding")){switch(xx_var_get_u64(&r->value)){
 case 0:return xx_data_struct_record_set_comment(r,L"PCM8");
 case 1:return xx_data_struct_record_set_comment(r,L"PCM16");
 case 2:return xx_data_struct_record_set_comment(r,L"IMA_ADPCM");
 default:break;}}
 if(id==1613496425&&!xx_rt_wcscmp(r->name,L"sample_byte_order")){switch(xx_var_get_u64(&r->value)){
 case 0:return xx_data_struct_record_set_comment(r,L"BIG_ENDIAN");
 case 1:return xx_data_struct_record_set_comment(r,L"LITTLE_ENDIAN");
 default:break;}}
 if(id==1613496425&&!xx_rt_wcscmp(r->name,L"encoding")){switch(xx_var_get_u64(&r->value)){
 case 0:return xx_data_struct_record_set_comment(r,L"PCM16");
 case 1:return xx_data_struct_record_set_comment(r,L"PACKED_PCM24");
 case 2:return xx_data_struct_record_set_comment(r,L"PCM8");
 default:break;}}
 if(id==1613496425&&!xx_rt_wcscmp(r->name,L"source")){switch(xx_var_get_u64(&r->value)){
 case 1:return xx_data_struct_record_set_comment(r,L"ANALOG_RECORDING");
 case 2:return xx_data_struct_record_set_comment(r,L"DIGITAL_TRANSFER");
 case 3:return xx_data_struct_record_set_comment(r,L"MULTITRACK_MIXDOWN");
 case 5:return xx_data_struct_record_set_comment(r,L"DSP_PROCESSING");
 default:break;}}
 if(id==1613496429&&!xx_rt_wcscmp(r->name,L"encoding")){switch(xx_var_get_u64(&r->value)){
 case 0:return xx_data_struct_record_set_comment(r,L"PCM8");
 case 1:return xx_data_struct_record_set_comment(r,L"PCM16");
 case 2:return xx_data_struct_record_set_comment(r,L"IMA_ADPCM");
 default:break;}}
 if(id==1613496430&&!xx_rt_wcscmp(r->name,L"sample_byte_order")){switch(xx_var_get_u64(&r->value)){
 case 0:return xx_data_struct_record_set_comment(r,L"BIG_ENDIAN");
 case 1:return xx_data_struct_record_set_comment(r,L"LITTLE_ENDIAN");
 default:break;}}
 if(id==1613496430&&!xx_rt_wcscmp(r->name,L"encoding")){switch(xx_var_get_u64(&r->value)){
 case 0:return xx_data_struct_record_set_comment(r,L"PCM16");
 case 1:return xx_data_struct_record_set_comment(r,L"PACKED_PCM24");
 case 2:return xx_data_struct_record_set_comment(r,L"PCM8");
 default:break;}}
 if(id==1613496430&&!xx_rt_wcscmp(r->name,L"source")){switch(xx_var_get_u64(&r->value)){
 case 1:return xx_data_struct_record_set_comment(r,L"ANALOG_RECORDING");
 case 2:return xx_data_struct_record_set_comment(r,L"DIGITAL_TRANSFER");
 case 3:return xx_data_struct_record_set_comment(r,L"MULTITRACK_MIXDOWN");
 case 5:return xx_data_struct_record_set_comment(r,L"DSP_PROCESSING");
 default:break;}}
 if(id==1613496321&&!xx_rt_wcscmp(r->name,L"alignment"))return xx_data_struct_record_set_comment(r,L"Byte alignment applied to stored member offsets.");
 if(id==1613496321&&!xx_rt_wcscmp(r->name,L"subkey"))return xx_data_struct_record_set_comment(r,L"CRI AWB subkey; does not imply payload decryption.");
 if(id==1613496328&&!xx_rt_wcscmp(r->name,L"build_time"))return xx_data_struct_record_set_comment(r,L"Windows FILETIME:100 ns intervals since1601-01-01 UTC.");
 if(id==1613496331&&!xx_rt_wcscmp(r->name,L"last_modified"))return xx_data_struct_record_set_comment(r,L"Windows FILETIME:100 ns intervals since1601-01-01 UTC.");
 if(id==1613496329&&!xx_rt_wcscmp(r->name,L"play_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset from the wave-data segment, not from the file start.");
 if(id==1613496329&&!xx_rt_wcscmp(r->name,L"flags_and_duration"))return xx_data_struct_record_set_comment(r,L"Bits0..3:entry flags; bits4..31:decoded duration in samples.");
 if(id==1613496329&&!xx_rt_wcscmp(r->name,L"mini_wave_format"))return xx_data_struct_record_set_comment(r,L"Bits0..1:codec;2..4:channels;5..22:sample rate;23..30:block alignment;31:16-bit PCM flag.");
 if(id==1613496328&&!xx_rt_wcscmp(r->name,L"compact_format"))return xx_data_struct_record_set_comment(r,L"Packed mini-wave format used by compact banks; native supported banks are noncompact.");
 if(id==1613496340&&!xx_rt_wcscmp(r->name,L"start_frame"))return xx_data_struct_record_set_comment(r,L"Zero-based encoded frame index.");
 if(id==1613496340&&!xx_rt_wcscmp(r->name,L"end_frame"))return xx_data_struct_record_set_comment(r,L"Inclusive encoded frame index.");
 if(id==1613496342&&!xx_rt_wcscmp(r->name,L"volume"))return xx_data_struct_record_set_comment(r,L"IEEE754 relative linear volume multiplier.");
 if(id==1613496349&&!xx_rt_wcscmp(r->name,L"volume_fixed16_16"))return xx_data_struct_record_set_comment(r,L"Unsigned16.16 fixed-point volume;65536 means1.0.");
 if(id==1613496347&&!xx_rt_wcscmp(r->name,L"form_bytes"))return xx_data_struct_record_set_comment(r,L"Byte length after the first8 bytes.");
 if(id==1613496348&&!xx_rt_wcscmp(r->name,L"payload_size"))return xx_data_struct_record_set_comment(r,L"Payload bytes; excludes8-byte header and optional odd-byte pad.");
 if(id==1613496351&&!xx_rt_wcscmp(r->name,L"eof_offset"))return xx_data_struct_record_set_comment(r,L"Byte displacement from file byte4; zero has the version-specific absent/default meaning.");
 if(id==1613496351&&!xx_rt_wcscmp(r->name,L"gd3_offset"))return xx_data_struct_record_set_comment(r,L"Byte displacement from file byte20; zero has the version-specific absent/default meaning.");
 if(id==1613496351&&!xx_rt_wcscmp(r->name,L"loop_offset"))return xx_data_struct_record_set_comment(r,L"Byte displacement from file byte28; zero has the version-specific absent/default meaning.");
 if(id==1613496351&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte displacement from file byte52; zero has the version-specific absent/default meaning.");
 if(id==1613496351&&!xx_rt_wcscmp(r->name,L"sn76489_clock"))return xx_data_struct_record_set_comment(r,L"Clock frequency in Hz; high bits may carry chip configuration flags.");
 if(id==1613496351&&!xx_rt_wcscmp(r->name,L"ym2413_clock"))return xx_data_struct_record_set_comment(r,L"Clock frequency in Hz; high bits may carry chip configuration flags.");
 if(id==1613496351&&!xx_rt_wcscmp(r->name,L"ym2612_clock"))return xx_data_struct_record_set_comment(r,L"Clock frequency in Hz; high bits may carry chip configuration flags.");
 if(id==1613496351&&!xx_rt_wcscmp(r->name,L"ym2151_clock"))return xx_data_struct_record_set_comment(r,L"Clock frequency in Hz; high bits may carry chip configuration flags.");
 if(id==1613496351&&!xx_rt_wcscmp(r->name,L"sega_pcm_clock"))return xx_data_struct_record_set_comment(r,L"Clock frequency in Hz; high bits may carry chip configuration flags.");
 if(id==1613496351&&!xx_rt_wcscmp(r->name,L"version"))return xx_data_struct_record_set_comment(r,L"Packed hexadecimal VGM version (for example0x160 means1.60).");
 if(id==1613496351&&!xx_rt_wcscmp(r->name,L"total_samples"))return xx_data_struct_record_set_comment(r,L"Total duration in44100-Hz sample ticks.");
 if(id==1613496351&&!xx_rt_wcscmp(r->name,L"loop_samples"))return xx_data_struct_record_set_comment(r,L"Loop duration in44100-Hz sample ticks.");
 if(id==1613496356&&!xx_rt_wcscmp(r->name,L"wait_samples"))return xx_data_struct_record_set_comment(r,L"Delay in44100-Hz sample ticks.");
 if(id==1613496358&&!xx_rt_wcscmp(r->name,L"pcm_bank_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset into the concatenated PCM data bank, not a file position.");
 if(id==1613496362&&!xx_rt_wcscmp(r->name,L"data_start_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset into PCM data bank;0xFFFFFFFF continues current position.");
 if(id==1613496362&&!xx_rt_wcscmp(r->name,L"data_length"))return xx_data_struct_record_set_comment(r,L"Length interpretation depends on length_mode (commands, milliseconds, or data remainder).");
 if(id==1613496360&&!xx_rt_wcscmp(r->name,L"step_base"))return xx_data_struct_record_set_comment(r,L"Byte displacement within each PCM step.");
 if(id==1613496360&&!xx_rt_wcscmp(r->name,L"step_size"))return xx_data_struct_record_set_comment(r,L"PCM step size in bytes.");
 if(id==1613496362&&!xx_rt_wcscmp(r->name,L"length_mode"))return xx_data_struct_record_set_comment(r,L"Low2 bits:length mode; bit4:reverse; bit7:loop.");
 if(id==1613496365&&!xx_rt_wcscmp(r->name,L"sample_rate_and_frame_size_code"))return xx_data_struct_record_set_comment(r,L"Bits6..7:sample-rate code; bits0..5:frame-size code, not a byte count.");
 if(id==1613496365&&!xx_rt_wcscmp(r->name,L"bitstream_id_and_mode"))return xx_data_struct_record_set_comment(r,L"Bits3..7:bitstream ID; bits0..2:bitstream mode. Native supports classic AC-3 bsid8.");
 if(id==1613496367&&!xx_rt_wcscmp(r->name,L"sync_version_layer_protection"))return xx_data_struct_record_set_comment(r,L"11-bit sync, MPEG version, layer and protection-absent bit. Native supports MPEG1 LayerIII unprotected frames.");
 if(id==1613496367&&!xx_rt_wcscmp(r->name,L"bitrate_rate_padding_private"))return xx_data_struct_record_set_comment(r,L"Bits4..7:bitrate index;2..3:sample-rate index;1:padding;0:private.");
 if(id==1613496367&&!xx_rt_wcscmp(r->name,L"channel_mode_extension_flags"))return xx_data_struct_record_set_comment(r,L"Bits6..7:channel mode;4..5:mode extension;3:copyright;2:original;0..1:emphasis.");
 if(id==1613496368&&!xx_rt_wcscmp(r->name,L"synchsafe_size"))return xx_data_struct_record_set_comment(r,L"Four7-bit groups, most significant first; decoded tag length excludes10-byte prefix.");
 if(id==1613496370&&!xx_rt_wcscmp(r->name,L"synchsafe_size"))return xx_data_struct_record_set_comment(r,L"Four7-bit groups, most significant first; decoded frame payload byte length.");
 if(id==1613496371&&!xx_rt_wcscmp(r->name,L"sync_id_layer_protection"))return xx_data_struct_record_set_comment(r,L"Bits4..15:sync0xFFF;3:MPEG ID;1..2:layer;0:protection absent.");
 if(id==1613496371&&!xx_rt_wcscmp(r->name,L"profile_sampling_private_channel_high"))return xx_data_struct_record_set_comment(r,L"Bits6..7:profile;2..5:sampling frequency index;1:private;0:channel configuration high bit.");
 if(id==1613496371&&!xx_rt_wcscmp(r->name,L"channel_low_original_home_copyright_length_high"))return xx_data_struct_record_set_comment(r,L"Bits6..7:channel configuration low bits;5:original;4:home;3..2:copyright bits;1..0:frame length high bits.");
 if(id==1613496371&&!xx_rt_wcscmp(r->name,L"frame_length_middle"))return xx_data_struct_record_set_comment(r,L"Middle8 bits of the13-bit total ADTS frame byte length.");
 if(id==1613496371&&!xx_rt_wcscmp(r->name,L"length_low_buffer_fullness_high"))return xx_data_struct_record_set_comment(r,L"Bits5..7:frame length low bits;0..4:buffer fullness high bits.");
 if(id==1613496371&&!xx_rt_wcscmp(r->name,L"fullness_low_raw_block_count"))return xx_data_struct_record_set_comment(r,L"Bits2..7:buffer fullness low bits;0..1:raw data block count minus one.");
 if(id==1613496373&&!xx_rt_wcscmp(r->name,L"audio_data_bytes_low"))return xx_data_struct_record_set_comment(r,L"Low32 bits of encoded audio byte count; native scope requires high word zero.");
 if(id==1613496373&&!xx_rt_wcscmp(r->name,L"audio_data_bytes_high"))return xx_data_struct_record_set_comment(r,L"High32 bits of encoded audio byte count.");
 if(id==1613496373&&!xx_rt_wcscmp(r->name,L"md5"))return xx_data_struct_record_set_comment(r,L"Stored MD5; schema does not recompute or validate decoded audio.");
 if(id==1613496376&&!xx_rt_wcscmp(r->name,L"tag_bytes"))return xx_data_struct_record_set_comment(r,L"Tag byte length including footer, excluding optional32-byte header.");
 if(id==1613496377&&!xx_rt_wcscmp(r->name,L"flags"))return xx_data_struct_record_set_comment(r,L"Bit0:read-only; bits1..2:value type (UTF8,binary,external,reserved).");
 if(id==1613496379&&!xx_rt_wcscmp(r->name,L"frame_data_size"))return xx_data_struct_record_set_comment(r,L"Frame byte length after its first8 bytes.");
 if(id==1613496379&&!xx_rt_wcscmp(r->name,L"time_seconds"))return xx_data_struct_record_set_comment(r,L"IEEE754 seconds from start of stream, not a Unix timestamp.");
 if(id==1613496380&&!xx_rt_wcscmp(r->name,L"data_type"))return xx_data_struct_record_set_comment(r,L"High byte:numeric class (0 floating,1 signed,2 unsigned); low byte:element width in bytes.");
 if(id==1613496383&&!xx_rt_wcscmp(r->name,L"file_size_from_magic"))return xx_data_struct_record_set_comment(r,L"Byte length from the SC68 signature at file byte56.");
 if(id==1613496387&&!xx_rt_wcscmp(r->name,L"value"))return xx_data_struct_record_set_comment(r,L"32-bit value interpreted by the preceding SC68 chunk ID; timing/count/register units vary by tag.");
 if(id==1613496386&&!xx_rt_wcscmp(r->name,L"load_address"))return xx_data_struct_record_set_comment(r,L"68000 memory load address, not a file offset.");
 if(id==1613496388&&!xx_rt_wcscmp(r->name,L"names_offset_low16"))return xx_data_struct_record_set_comment(r,L"Low16 bits of the actual name-table byte offset; large modules wrap modulo65536.");
 if(id==1613496388&&!xx_rt_wcscmp(r->name,L"flags_and_position_count"))return xx_data_struct_record_set_comment(r,L"Low12 bits:position count; high bit:track0 omitted; other high bits encode replay-speed flags.");
 if(id==1613496391&&!xx_rt_wcscmp(r->name,L"filter_speed_and_wave_length"))return xx_data_struct_record_set_comment(r,L"Low3 bits:wave length code; high bits:filter speed.");
 if(id==1613496392&&!xx_rt_wcscmp(r->name,L"effects_and_waveform"))return xx_data_struct_record_set_comment(r,L"Packed playlist effects and waveform selector; source bit pattern preserved.");
 if(id==1613496392&&!xx_rt_wcscmp(r->name,L"note_and_fixed"))return xx_data_struct_record_set_comment(r,L"Low6 bits:note; high bits:fixed-note/effect flags.");
 if(id==1613496396&&!xx_rt_wcscmp(r->name,L"size_in_8byte_units"))return xx_data_struct_record_set_comment(r,L"Encoded sample length in8-byte units; multiply by8 for bytes.");
 if(id==1613496397&&!xx_rt_wcscmp(r->name,L"track_count_minus_one"))return xx_data_struct_record_set_comment(r,L"Number of tracks minus one.");
 if(id==1613496399&&!xx_rt_wcscmp(r->name,L"duration_frames"))return xx_data_struct_record_set_comment(r,L"Duration in50-Hz replay frames.");
 if(id==1613496399&&!xx_rt_wcscmp(r->name,L"fade_frames"))return xx_data_struct_record_set_comment(r,L"Fade duration in50-Hz replay frames.");
 if(id==1613496411&&!xx_rt_wcscmp(r->name,L"packed_sample_metadata"))return xx_data_struct_record_set_comment(r,L"Bit0:more chunks;1..4:rate code;5..6:channel code;7..33:data offset in32-byte units;34..63:sample count.");
 if(id==1613496412&&!xx_rt_wcscmp(r->name,L"more_size_type"))return xx_data_struct_record_set_comment(r,L"Bit0:more chunks;1..24:chunk payload bytes;25..31:chunk type.");
 if(id==1613496415&&!xx_rt_wcscmp(r->name,L"name_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the name-table beginning.");
 if(id==1613496416&&!xx_rt_wcscmp(r->name,L"levels_and_subblocks"))return xx_data_struct_record_set_comment(r,L"Low4 bits:transform levels; high12 bits:subblocks.");
 if(id==1613496417&&!xx_rt_wcscmp(r->name,L"data_offset_minus_four"))return xx_data_struct_record_set_comment(r,L"Stored relative offset; add4 to obtain encoded-data byte offset.");
 if(id==1613496420&&!xx_rt_wcscmp(r->name,L"header_512byte_blocks"))return xx_data_struct_record_set_comment(r,L"Header length in512-byte blocks, not bytes.");
 if(id==1613496420&&!xx_rt_wcscmp(r->name,L"recording_start"))return xx_data_struct_record_set_comment(r,L"Twelve ASCII digits:YYMMDDhhmmss; no time zone encoded.");
 if(id==1613496420&&!xx_rt_wcscmp(r->name,L"recording_end"))return xx_data_struct_record_set_comment(r,L"Twelve ASCII digits:YYMMDDhhmmss; no time zone encoded.");
 if(id==1613496420&&!xx_rt_wcscmp(r->name,L"duration_hhmmss"))return xx_data_struct_record_set_comment(r,L"Six ASCII digits:HHMMSS duration.");
 if(id==1613496421&&!xx_rt_wcscmp(r->name,L"block_size"))return xx_data_struct_record_set_comment(r,L"Total block byte length including8-byte prefix.");
 if(id==1613496423&&!xx_rt_wcscmp(r->name,L"chunk_size"))return xx_data_struct_record_set_comment(r,L"Total chunk bytes including8-byte prefix.");
 if(id==1613496424&&!xx_rt_wcscmp(r->name,L"block_bytes"))return xx_data_struct_record_set_comment(r,L"Encoded bytes per channel in each full block.");
 if(id==1613496424&&!xx_rt_wcscmp(r->name,L"last_block_bytes"))return xx_data_struct_record_set_comment(r,L"Encoded bytes per channel in the final block.");
 if(id==1613496424&&!xx_rt_wcscmp(r->name,L"timer"))return xx_data_struct_record_set_comment(r,L"Nintendo hardware playback timer value; not a timestamp.");
 if(id==1613496426&&!xx_rt_wcscmp(r->name,L"block_size"))return xx_data_struct_record_set_comment(r,L"Total block byte length including8-byte prefix.");
 if(id==1613496428&&!xx_rt_wcscmp(r->name,L"chunk_size"))return xx_data_struct_record_set_comment(r,L"Total chunk bytes including8-byte prefix.");
 if(id==1613496429&&!xx_rt_wcscmp(r->name,L"block_bytes"))return xx_data_struct_record_set_comment(r,L"Encoded bytes per channel in each full block.");
 if(id==1613496429&&!xx_rt_wcscmp(r->name,L"last_block_bytes"))return xx_data_struct_record_set_comment(r,L"Encoded bytes per channel in the final block.");
 if(id==1613496429&&!xx_rt_wcscmp(r->name,L"timer"))return xx_data_struct_record_set_comment(r,L"Nintendo hardware playback timer value; not a timestamp.");
 if(id==1613496432&&!xx_rt_wcscmp(r->name,L"header_bytes_after_prefix"))return xx_data_struct_record_set_comment(r,L"Header bytes following the first8 bytes;8 means implicit22050Hz,12 includes sample-rate word.");
 if(id==1613496434&&!xx_rt_wcscmp(r->name,L"track_relative_offset"))return xx_data_struct_record_set_comment(r,L"Byte displacement relative to MDH signature at file byte0x38.");
 if(id==1613496323&&!xx_rt_wcscmp(r->name,L"entry_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this file or bank beginning.");
 if(id==1613496325&&!xx_rt_wcscmp(r->name,L"entry_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this file or bank beginning.");
 if(id==1613496327&&!xx_rt_wcscmp(r->name,L"segment_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this file or bank beginning.");
 if(id==1613496329&&!xx_rt_wcscmp(r->name,L"loop_start_samples"))return xx_data_struct_record_set_comment(r,L"Decoded sample index, not a byte offset.");
 if(id==1613496331&&!xx_rt_wcscmp(r->name,L"unknown_17"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical header bytes; no guessed member semantics.");
 if(id==1613496331&&!xx_rt_wcscmp(r->name,L"unknown_20"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical header bytes; no guessed member semantics.");
 if(id==1613496331&&!xx_rt_wcscmp(r->name,L"simple_cues_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this file or bank beginning.");
 if(id==1613496331&&!xx_rt_wcscmp(r->name,L"complex_cues_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this file or bank beginning.");
 if(id==1613496331&&!xx_rt_wcscmp(r->name,L"cue_names_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this file or bank beginning.");
 if(id==1613496331&&!xx_rt_wcscmp(r->name,L"unknown_offset"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical header bytes; no guessed member semantics.");
 if(id==1613496331&&!xx_rt_wcscmp(r->name,L"variation_tables_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this file or bank beginning.");
 if(id==1613496331&&!xx_rt_wcscmp(r->name,L"transition_tables_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this file or bank beginning.");
 if(id==1613496331&&!xx_rt_wcscmp(r->name,L"wave_bank_names_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this file or bank beginning.");
 if(id==1613496331&&!xx_rt_wcscmp(r->name,L"cue_name_hash_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this file or bank beginning.");
 if(id==1613496331&&!xx_rt_wcscmp(r->name,L"cue_name_index_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this file or bank beginning.");
 if(id==1613496331&&!xx_rt_wcscmp(r->name,L"sounds_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this file or bank beginning.");
 if(id==1613496332&&!xx_rt_wcscmp(r->name,L"sound_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this file or bank beginning.");
 if(id==1613496334&&!xx_rt_wcscmp(r->name,L"bits_per_sample"))return xx_data_struct_record_set_comment(r,L"Bits per decoded sample per channel.");
 if(id==1613496334&&!xx_rt_wcscmp(r->name,L"sample_rate"))return xx_data_struct_record_set_comment(r,L"Frequency in Hz.");
 if(id==1613496334&&!xx_rt_wcscmp(r->name,L"loop_start_sample"))return xx_data_struct_record_set_comment(r,L"Decoded sample index, not a byte offset.");
 if(id==1613496334&&!xx_rt_wcscmp(r->name,L"loop_end_sample"))return xx_data_struct_record_set_comment(r,L"Decoded sample index, not a byte offset.");
 if(id==1613496334&&!xx_rt_wcscmp(r->name,L"unknown_tail"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical header bytes; no guessed member semantics.");
 if(id==1613496337&&!xx_rt_wcscmp(r->name,L"sample_rate"))return xx_data_struct_record_set_comment(r,L"Frequency in Hz.");
 if(id==1613496349&&!xx_rt_wcscmp(r->name,L"samples_per_second"))return xx_data_struct_record_set_comment(r,L"Frequency in Hz.");
 if(id==1613496361&&!xx_rt_wcscmp(r->name,L"frequency"))return xx_data_struct_record_set_comment(r,L"Frequency in Hz.");
 if(id==1613496374&&!xx_rt_wcscmp(r->name,L"bits_per_sample"))return xx_data_struct_record_set_comment(r,L"Bits per decoded sample per channel.");
 if(id==1613496374&&!xx_rt_wcscmp(r->name,L"sample_rate"))return xx_data_struct_record_set_comment(r,L"Frequency in Hz.");
 if(id==1613496375&&!xx_rt_wcscmp(r->name,L"frame_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this file or bank beginning.");
 if(id==1613496382&&!xx_rt_wcscmp(r->name,L"start_address"))return xx_data_struct_record_set_comment(r,L"Target machine memory address, not a file offset.");
 if(id==1613496382&&!xx_rt_wcscmp(r->name,L"end_address_inclusive"))return xx_data_struct_record_set_comment(r,L"Target machine memory address, not a file offset.");
 if(id==1613496391&&!xx_rt_wcscmp(r->name,L"unknown_a"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical header bytes; no guessed member semantics.");
 if(id==1613496397&&!xx_rt_wcscmp(r->name,L"custom_player_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement from the beginning of this pointer word.");
 if(id==1613496397&&!xx_rt_wcscmp(r->name,L"author_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement from the beginning of this pointer word.");
 if(id==1613496397&&!xx_rt_wcscmp(r->name,L"comment_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement from the beginning of this pointer word.");
 if(id==1613496397&&!xx_rt_wcscmp(r->name,L"track_table_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement from the beginning of this pointer word.");
 if(id==1613496398&&!xx_rt_wcscmp(r->name,L"name_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement from the beginning of this pointer word.");
 if(id==1613496398&&!xx_rt_wcscmp(r->name,L"descriptor_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement from the beginning of this pointer word.");
 if(id==1613496399&&!xx_rt_wcscmp(r->name,L"cpu_state_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement from the beginning of this pointer word.");
 if(id==1613496399&&!xx_rt_wcscmp(r->name,L"block_index_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement from the beginning of this pointer word.");
 if(id==1613496400&&!xx_rt_wcscmp(r->name,L"stack_pointer"))return xx_data_struct_record_set_comment(r,L"Target machine memory address, not a file offset.");
 if(id==1613496400&&!xx_rt_wcscmp(r->name,L"init_address"))return xx_data_struct_record_set_comment(r,L"Target machine memory address, not a file offset.");
 if(id==1613496400&&!xx_rt_wcscmp(r->name,L"interrupt_address"))return xx_data_struct_record_set_comment(r,L"Target machine memory address, not a file offset.");
 if(id==1613496401&&!xx_rt_wcscmp(r->name,L"load_address"))return xx_data_struct_record_set_comment(r,L"Target machine memory address, not a file offset.");
 if(id==1613496401&&!xx_rt_wcscmp(r->name,L"payload_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement from the beginning of this pointer word.");
 if(id==1613496404&&!xx_rt_wcscmp(r->name,L"sample_rate"))return xx_data_struct_record_set_comment(r,L"Frequency in Hz.");
 if(id==1613496404&&!xx_rt_wcscmp(r->name,L"opaque_2c"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical header bytes; no guessed member semantics.");
 if(id==1613496404&&!xx_rt_wcscmp(r->name,L"loop_start_sample"))return xx_data_struct_record_set_comment(r,L"Decoded sample index, not a byte offset.");
 if(id==1613496404&&!xx_rt_wcscmp(r->name,L"loop_end_sample"))return xx_data_struct_record_set_comment(r,L"Decoded sample index, not a byte offset.");
 if(id==1613496408&&!xx_rt_wcscmp(r->name,L"loop_start_sample"))return xx_data_struct_record_set_comment(r,L"Decoded sample index, not a byte offset.");
 if(id==1613496408&&!xx_rt_wcscmp(r->name,L"loop_end_sample"))return xx_data_struct_record_set_comment(r,L"Decoded sample index, not a byte offset.");
 if(id==1613496408&&!xx_rt_wcscmp(r->name,L"sample_rate"))return xx_data_struct_record_set_comment(r,L"Frequency in Hz.");
 if(id==1613496414&&!xx_rt_wcscmp(r->name,L"sample_rate"))return xx_data_struct_record_set_comment(r,L"Frequency in Hz.");
 if(id==1613496416&&!xx_rt_wcscmp(r->name,L"sample_rate"))return xx_data_struct_record_set_comment(r,L"Frequency in Hz.");
 if(id==1613496417&&!xx_rt_wcscmp(r->name,L"sample_rate"))return xx_data_struct_record_set_comment(r,L"Frequency in Hz.");
 if(id==1613496417&&!xx_rt_wcscmp(r->name,L"unknown"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical header bytes; no guessed member semantics.");
 if(id==1613496420&&!xx_rt_wcscmp(r->name,L"opaque_metadata"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical header bytes; no guessed member semantics.");
 if(id==1613496424&&!xx_rt_wcscmp(r->name,L"sample_rate"))return xx_data_struct_record_set_comment(r,L"Frequency in Hz.");
 if(id==1613496424&&!xx_rt_wcscmp(r->name,L"loop_start_sample"))return xx_data_struct_record_set_comment(r,L"Decoded sample index, not a byte offset.");
 if(id==1613496424&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this file or bank beginning.");
 if(id==1613496425&&!xx_rt_wcscmp(r->name,L"sample_rate"))return xx_data_struct_record_set_comment(r,L"Frequency in Hz.");
 if(id==1613496429&&!xx_rt_wcscmp(r->name,L"sample_rate"))return xx_data_struct_record_set_comment(r,L"Frequency in Hz.");
 if(id==1613496429&&!xx_rt_wcscmp(r->name,L"loop_start_sample"))return xx_data_struct_record_set_comment(r,L"Decoded sample index, not a byte offset.");
 if(id==1613496429&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this file or bank beginning.");
 if(id==1613496430&&!xx_rt_wcscmp(r->name,L"sample_rate"))return xx_data_struct_record_set_comment(r,L"Frequency in Hz.");
 if(id==1613496431&&!xx_rt_wcscmp(r->name,L"sample_rate"))return xx_data_struct_record_set_comment(r,L"Frequency in Hz.");
 if(id==1613496431&&!xx_rt_wcscmp(r->name,L"unknown_c"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical header bytes; no guessed member semantics.");
 if(id==1613496431&&!xx_rt_wcscmp(r->name,L"unknown_14"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical header bytes; no guessed member semantics.");
 if(id==1613496431&&!xx_rt_wcscmp(r->name,L"unknown_1c"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical header bytes; no guessed member semantics.");
 if(id==1613496432&&!xx_rt_wcscmp(r->name,L"unknown"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical header bytes; no guessed member semantics.");
 if(id==1613496433&&!xx_rt_wcscmp(r->name,L"sample_rate"))return xx_data_struct_record_set_comment(r,L"Frequency in Hz.");
 if(id==1613496434&&!xx_rt_wcscmp(r->name,L"instrument_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this file or bank beginning.");
 if(id==1613496434&&!xx_rt_wcscmp(r->name,L"sample_offset0"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this file or bank beginning.");
 if(id==1613496434&&!xx_rt_wcscmp(r->name,L"sample_offset1"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this file or bank beginning.");
 if(id==1613496434&&!xx_rt_wcscmp(r->name,L"sample_offset2"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this file or bank beginning.");
 if(id==1613496434&&!xx_rt_wcscmp(r->name,L"sample_offset3"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this file or bank beginning.");
 if(id==1613496434&&!xx_rt_wcscmp(r->name,L"sample_offset4"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this file or bank beginning.");
 if(id==1613496434&&!xx_rt_wcscmp(r->name,L"sample_offset5"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this file or bank beginning.");
 if(id==1613496434&&!xx_rt_wcscmp(r->name,L"sample_offset6"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this file or bank beginning.");
 if(id==1613496434&&!xx_rt_wcscmp(r->name,L"sample_offset7"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this file or bank beginning.");
 if(id==1613496434&&!xx_rt_wcscmp(r->name,L"unknown_3c"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical header bytes; no guessed member semantics.");
 if(id==1613496435&&!xx_rt_wcscmp(r->name,L"unknown"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical header bytes; no guessed member semantics.");
 return true;
}
const sx_family sx_audiomore_family={sx_audiomore_supports,sx_audiomore_build,sx_audiomore_layouts,SX_COUNT(sx_audiomore_layouts),sx_audiomore_comment};
