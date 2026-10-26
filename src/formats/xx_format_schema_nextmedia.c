/* Copyright (c)2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical image and audiovisual metadata; compressed and unknown bodies stay raw. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_nextmedia.h"
static const xx_data_struct_field_desc sxnx_rgb_palette_entry_fields[]={
 SX_FIELD("red","uint8",0,1,SX_NONE),
 SX_FIELD("green","uint8",1,1,SX_NONE),
 SX_FIELD("blue","uint8",2,1,SX_NONE),
};
const sx_layout sxnx_rgb_palette_entry={UINT32_C(0x60320033),"rgb_palette_entry",sxnx_rgb_palette_entry_fields,SX_COUNT(sxnx_rgb_palette_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_mpeg_packet_fields[]={
 SX_FIELD("prefix","bytes",0,3,SX_SIGNATURE),
 SX_FIELD("stream_id","uint8",3,1,SX_ID),
 SX_FIELD("packet_bytes","uint16",4,2,SX_SIZE),
};
const sx_layout sxnx_mpeg_packet={UINT32_C(0x603200F1),"mpeg_packet",sxnx_mpeg_packet_fields,SX_COUNT(sxnx_mpeg_packet_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_mpeg_pes2_fields[]={
 SX_FIELD("control","uint8",0,1,SX_FLAGS),
 SX_FIELD("timestamp_flags","uint8",1,1,SX_FLAGS),
 SX_FIELD("header_bytes","uint8",2,1,SX_SIZE),
};
static const sx_layout sxnx_mpeg_pes2={UINT32_C(0x603200F2),"mpeg_pes2",sxnx_mpeg_pes2_fields,SX_COUNT(sxnx_mpeg_pes2_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_mpeg_timestamp_fields[]={
 SX_FIELD("tag_high_and_marker","uint8",0,1,SX_FLAGS),
 SX_FIELD("middle_and_marker","uint16",1,2,SX_FLAGS),
 SX_FIELD("low_and_marker","uint16",3,2,SX_FLAGS),
};
static const sx_layout sxnx_mpeg_timestamp={UINT32_C(0x603200F3),"mpeg_timestamp",sxnx_mpeg_timestamp_fields,SX_COUNT(sxnx_mpeg_timestamp_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_mpeg_pes1_buffer_fields[]={
 SX_FIELD("std_buffer_scale_size","uint16",0,2,SX_FLAGS),
};
static const sx_layout sxnx_mpeg_pes1_buffer={UINT32_C(0x603200F4),"mpeg_pes1_buffer",sxnx_mpeg_pes1_buffer_fields,SX_COUNT(sxnx_mpeg_pes1_buffer_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_mpeg_pes1_no_timestamp_fields[]={
 SX_FIELD("marker","uint8",0,1,SX_SIGNATURE),
};
static const sx_layout sxnx_mpeg_pes1_no_timestamp={UINT32_C(0x603200F5),"mpeg_pes1_no_timestamp",sxnx_mpeg_pes1_no_timestamp_fields,SX_COUNT(sxnx_mpeg_pes1_no_timestamp_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_mpeg_crc_fields[]={
 SX_FIELD("crc32","uint32",0,4,SX_CHECKSUM),
};
const sx_layout sxnx_mpeg_crc={UINT32_C(0x603200FB),"mpeg_crc",sxnx_mpeg_crc_fields,SX_COUNT(sxnx_mpeg_crc_fields),SX_BE};
static const sx_layout *const sx_nextmedia_layouts[]={
 &sxnx_emf_header,
 &sxnx_emf_record,
 &sxnx_emf_rectangle,
 &sxnx_emf_point,
 &sxnx_emf_poly_count,
 &sxnx_emf_mode,
 &sxnx_emf_flags,
 &sxnx_emf_color,
 &sxnx_emf_restore,
 &sxnx_emf_handle,
 &sxnx_emf_pen,
 &sxnx_emf_brush,
 &sxnx_emf_eof,
 &sxnx_wmf_placeable,
 &sxnx_wmf_header,
 &sxnx_wmf_record,
 &sxnx_wmf_point,
 &sxnx_wmf_coordinate_pair,
 &sxnx_wmf_rectangle,
 &sxnx_wmf_poly_count,
 &sxnx_wmf_mode,
 &sxnx_wmf_restore,
 &sxnx_wmf_handle,
 &sxnx_wmf_color,
 &sxnx_wmf_pen,
 &sxnx_wmf_brush,
 &sxnx_wbmp_header,
 &sxnx_wbmp_width_1,
 &sxnx_wbmp_height_1,
 &sxnx_wbmp_width_2,
 &sxnx_wbmp_height_2,
 &sxnx_palm_bitmap_header,
 &sxnx_palm_palette_header,
 &sxnx_palm_palette_entry,
 &sxnx_palm_compressed_header,
 &sxnx_viff_header_le,
 &sxnx_viff_header_be,
 &sxnx_viff_header_dec,
 &sxnx_abr_header,
 &sxnx_abr_record,
 &sxnx_abr_sample_prefix,
 &sxnx_abr_name_header,
 &sxnx_abr_sample_geometry,
 &sxnx_abr_row_size,
 &sxnx_wpg_header,
 &sxnx_wpg_record_short,
 &sxnx_wpg_record_medium,
 &sxnx_wpg_record_long,
 &sxnx_wpg_start,
 &sxnx_wpg_palette,
 &sxnx_rgb_palette_entry,
 &sxnx_wpg_bitmap,
 &sxnx_psp_header,
 &sxnx_psp_block,
 &sxnx_psp_image,
 &sxnx_psp_layer,
 &sxnx_psp_channel,
 &sxnx_pat_header,
 &sxnx_pat_pattern,
 &sxnx_pat_id_length,
 &sxnx_pat_vma,
 &sxnx_pat_slot,
 &sxnx_pat_channel,
 &sxnx_pat_row_size,
 &sxnx_pat_hierarchy,
 &sxnx_pat_empty_descriptor,
 &sxnx_qpic_header,
 &sxnx_qpic_record,
 &sxnx_qpic_record_long,
 &sxnx_qpic_point,
 &sxnx_qpic_rectangle,
 &sxnx_qpic_line,
 &sxnx_qpic_rounding,
 &sxnx_qpic_angles,
 &sxnx_qpic_point_count,
 &sxnx_qpic_fill_rule,
 &sxnx_qpic_mode,
 &sxnx_qpic_flags,
 &sxnx_qpic_raster_operation,
 &sxnx_qpic_boolean,
 &sxnx_qpic_opacity,
 &sxnx_icon_diskobject,
 &sxnx_icon_drawer,
 &sxnx_icon_image,
 &sxnx_icon_string,
 &sxnx_icon_tooltypes,
 &sxnx_icon_new_drawer,
 &sxnx_pict_header,
 &sxnx_pict_clip,
 &sxnx_pict_directbits,
 &sxnx_pict_row_short,
 &sxnx_pict_row_long,
 &sxnx_pict_end,
 &sxnx_sprite_area,
 &sxnx_sprite_header,
 &sxnx_sprite_palette,
 &sxnx_thumb_header_old,
 &sxnx_thumb_header_28,
 &sxnx_thumb_header_new,
 &sxnx_thumb_entry_20,
 &sxnx_thumb_entry_21,
 &sxnx_thumb_entry_new,
 &sxnx_xcf_header,
 &sxnx_xcf_property,
 &sxnx_xcf_string,
 &sxnx_xcf_offset,
 &sxnx_xcf_layer,
 &sxnx_xcf_channel,
 &sxnx_xcf_hierarchy,
 &sxnx_xcf_level,
 &sxnx_xcf_color_count,
 &sxnx_xcf_opacity,
 &sxnx_xcf_mode,
 &sxnx_xcf_boolean,
 &sxnx_xcf_geometry_offset,
 &sxnx_xcf_compression,
 &sxnx_xcf_guide,
 &sxnx_xcf_resolution,
 &sxnx_xcf_tattoo,
 &sxnx_xcf_unit,
 &sxnx_xcf_parasite,
 &sxnx_xcf_sample_point,
 &sxnx_bpg_header,
 &sxnx_bpg_width_1,
 &sxnx_bpg_width_2,
 &sxnx_bpg_width_3,
 &sxnx_bpg_height_1,
 &sxnx_bpg_height_2,
 &sxnx_bpg_height_3,
 &sxnx_bpg_picture_bytes_1,
 &sxnx_bpg_picture_bytes_2,
 &sxnx_bpg_picture_bytes_3,
 &sxnx_bpg_picture_bytes_4,
 &sxnx_bpg_extension_bytes_1,
 &sxnx_bpg_extension_bytes_2,
 &sxnx_bpg_extension_bytes_3,
 &sxnx_bpg_extension_tag_1,
 &sxnx_bpg_extension_tag_2,
 &sxnx_bpg_extension_tag_3,
 &sxnx_bpg_extension_tag_4,
 &sxnx_bpg_extension_tag_5,
 &sxnx_bpg_extension_data_bytes_1,
 &sxnx_bpg_extension_data_bytes_2,
 &sxnx_bpg_extension_data_bytes_3,
 &sxnx_bpg_hevc_header_bytes_1,
 &sxnx_bpg_nal,
 &sxnx_ani_riff,
 &sxnx_ani_chunk,
 &sxnx_ani_list,
 &sxnx_ani_header,
 &sxnx_ani_rate,
 &sxnx_ani_sequence,
 &sxnx_ani_icon_header,
 &sxnx_ani_icon_entry,
 &sxnx_ani_cursor_entry,
 &sxnx_pamf_header,
 &sxnx_pamf_sequence,
 &sxnx_pamf_period,
 &sxnx_pamf_group,
 &sxnx_pamf_stream,
 &sxnx_pamf_avc,
 &sxnx_pamf_m2v,
 &sxnx_pamf_audio,
 &sxnx_pamf_userdata,
 &sxnx_pamf_entry_point,
 &sxnx_usm_chunk,
 &sxnx_usm_utf_header,
 &sxnx_usm_utf_column,
 &sxnx_usm_utf_value_u8,
 &sxnx_usm_utf_value_i8,
 &sxnx_usm_utf_value_u16,
 &sxnx_usm_utf_value_i16,
 &sxnx_usm_utf_value_u32,
 &sxnx_usm_utf_value_i32,
 &sxnx_usm_utf_value_u64,
 &sxnx_usm_utf_value_i64,
 &sxnx_usm_utf_value_f32,
 &sxnx_usm_utf_value_f64,
 &sxnx_usm_utf_string,
 &sxnx_usm_utf_data,
 &sxnx_usm_utf_guid,
 &sxnx_mve_header,
 &sxnx_mve_chunk,
 &sxnx_mve_opcode,
 &sxnx_mve_timer,
 &sxnx_mve_audio_init,
 &sxnx_mve_video_init_0,
 &sxnx_mve_video_init_1,
 &sxnx_mve_video_init_2,
 &sxnx_mve_send_buffer,
 &sxnx_mve_audio_frame,
 &sxnx_mve_video_mode,
 &sxnx_mve_palette,
 &sxnx_vqa_form,
 &sxnx_vqa_chunk,
 &sxnx_vqa_header,
 &sxnx_vqa_frame_index,
 &sxnx_vqa_sound,
 &sxnx_mng_signature,
 &sxnx_mng_chunk,
 &sxnx_mng_crc,
 &sxnx_mng_header,
 &sxnx_mng_png_header,
 &sxnx_mng_gray,
 &sxnx_mng_rgb,
 &sxnx_mng_palette_index,
 &sxnx_mng_alpha,
 &sxnx_mng_gamma,
 &sxnx_mng_chromaticity,
 &sxnx_mng_srgb,
 &sxnx_mng_physical,
 &sxnx_mng_term,
 &sxnx_mng_fram,
 &sxnx_mng_defi,
 &sxnx_mng_back_flag,
 &sxnx_dxa_header,
 &sxnx_dxa_wave_size,
 &sxnx_dxa_riff,
 &sxnx_dxa_tag,
 &sxnx_dxa_frame,
 &sxnx_rmf_header,
 &sxnx_rm_object,
 &sxnx_rm_prop,
 &sxnx_rm_title_length,
 &sxnx_rm_author_length,
 &sxnx_rm_copyright_length,
 &sxnx_rm_comment_length,
 &sxnx_rm_mdpr,
 &sxnx_rm_name_length,
 &sxnx_rm_mime_length,
 &sxnx_rm_specific_length,
 &sxnx_rm_video,
 &sxnx_rm_audio_prefix,
 &sxnx_rm_data,
 &sxnx_rm_packet,
 &sxnx_rm_index,
 &sxnx_rm_index_entry,
 &sxnx_mpeg_start_code,
 &sxnx_mpeg_pack1,
 &sxnx_mpeg_pack2,
 &sxnx_mpeg_packet,
 &sxnx_mpeg_pes2,
 &sxnx_mpeg_timestamp,
 &sxnx_mpeg_pes1_buffer,
 &sxnx_mpeg_pes1_no_timestamp,
 &sxnx_mpeg_system,
 &sxnx_mpeg_system_stream,
 &sxnx_mpeg_map,
 &sxnx_mpeg_map_length,
 &sxnx_mpeg_map_stream,
 &sxnx_mpeg_crc,
 &sxnx_ts_header,
 &sxnx_ts_adaptation_size,
 &sxnx_ts_adaptation_flags,
 &sxnx_ts_clock,
 &sxnx_ts_splice,
 &sxnx_ts_private_size,
 &sxnx_ts_pointer,
 &sxnx_ts_section,
 &sxnx_ts_pat_program,
 &sxnx_ts_pmt,
 &sxnx_ts_pmt_stream,
 &sxnx_ts_sdt,
 &sxnx_ts_sdt_service,
 &sxnx_ts_descriptor,
};
bool sxnx_need(sxnx_view *v,size_t at,uint64_t n,size_t end){return !xx_pd_is_stopped(v->c->pd)&&end<=v->n&&at<=end&&n<=end-at;}
uint16_t sxnx_u16(const uint8_t*p,bool be){return xx_data_get_u16(p,2,0,be);}
uint32_t sxnx_u32(const uint8_t*p,bool be){return xx_data_get_u32(p,4,0,be);}
bool sxnx_row(sxnx_view *v,const sx_layout*l,size_t at,size_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;size_t n=(size_t)(f->rel_offset+f->size);if(++v->work>4000000||!sxnx_need(v,at,n,end))return false;return v->c->count>=24000||sx_add(v->c,l,(int64_t)at,(int64_t)n);}
#define SN_ROW(l,at,end) sxnx_row(v,&sxnx_##l,(at),(end))
bool sxnx_table(sxnx_view*v,const sx_layout*l,size_t at,uint64_t count,size_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;size_t z=(size_t)(f->rel_offset+f->size);if(count>4000000||!sxnx_need(v,at,count*z,end))return false;for(uint64_t i=0;i<count;i++,at+=z)if(!sxnx_row(v,l,at,end))return false;return true;}
static int sxnx_order(const void*aa,const void*bb){const xx_data_struct*a=aa,*b=bb;if(a->offset!=b->offset)return a->offset<b->offset?-1:1;return a->total_size<b->total_size?-1:a->total_size>b->total_size?1:0;}
static bool sxnx_finish(sx_context*c)
{size_t n=c->count,keep=0;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxnx_order);
 /* Native readers can permit shared descriptor ranges. Keep one physical interpretation;
  * never repeat identical source bytes as overlapping structures. */
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(at<end)continue;c->items[keep++]=c->items[i];end=at+z;}c->count=keep;n=keep;end=0;
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(at>end&&!sx_raw(c,end,at-end))return false;end=at+z;}
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxnx_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
bool sxnx_varuint(sxnx_view*v,size_t*at,size_t end,uint32_t*out,unsigned*width)
{size_t start=*at;uint32_t u=0;for(unsigned i=0;i<5;i++){if(!sxnx_need(v,*at,1,end))return false;unsigned b=v->p[(*at)++];if((!i&&b==128)||u>UINT32_MAX>>7)return false;u=(u<<7)|(b&127);if(!(b&128)){*out=u;*width=(unsigned)(*at-start);return true;}}return false;}
bool sxnx_pes(sxnx_view*v,size_t p,size_t end)
{if(!sxnx_need(v,p,1,end))return false;if((v->p[p]&0xc0)==0x80){if(!SN_ROW(mpeg_pes2,p,end))return false;unsigned flags=v->p[p+1]>>6,z=v->p[p+2];p+=3;if(!sxnx_need(v,p,z,end))return false;if(flags>=2){if(!SN_ROW(mpeg_timestamp,p,p+z))return false;if(flags==3&&!SN_ROW(mpeg_timestamp,p+5,p+z))return false;}return true;}
 unsigned work=0;while(p<end&&v->p[p]==255){if(++work>16)return false;p++;}if(!sxnx_need(v,p,1,end))return false;if((v->p[p]&0xc0)==0x40){if(!SN_ROW(mpeg_pes1_buffer,p,end))return false;p+=2;}if(!sxnx_need(v,p,1,end))return false;if(v->p[p]==15)return SN_ROW(mpeg_pes1_no_timestamp,p,end);unsigned tag=v->p[p]>>4;if(tag==2||tag==3){if(!SN_ROW(mpeg_timestamp,p,end))return false;return tag!=3||SN_ROW(mpeg_timestamp,p+5,end);}return false;}
static bool sx_nextmedia_supports(xx_file_type_t t)
{switch(t){
case XX_FILE_TYPE_EMF:
case XX_FILE_TYPE_WMF:
case XX_FILE_TYPE_GIMP_XCF:
case XX_FILE_TYPE_PHOTOSHOP_ABR:
case XX_FILE_TYPE_QT_QPICTURE:
case XX_FILE_TYPE_BPG_IMAGE:
case XX_FILE_TYPE_PAINTSHOP_PSP:
case XX_FILE_TYPE_PHOTOSHOP_PAT:
case XX_FILE_TYPE_AMIGA_DISKOBJECT:
case XX_FILE_TYPE_WBMP_IMAGE:
case XX_FILE_TYPE_PALM_BITMAP:
case XX_FILE_TYPE_APPLE_PICT:
case XX_FILE_TYPE_WORDPERFECT_WPG:
case XX_FILE_TYPE_KHOROS_VIFF:
case XX_FILE_TYPE_RISC_OS_SPRITE:
case XX_FILE_TYPE_WINDOWS_ANI:
case XX_FILE_TYPE_WINDOWS_THUMBNAIL_CACHE:
case XX_FILE_TYPE_SONY_PAMF:
case XX_FILE_TYPE_CRI_USM:
case XX_FILE_TYPE_MPEG_TRANSPORT_STREAM:
case XX_FILE_TYPE_MPEG_PROGRAM_STREAM:
case XX_FILE_TYPE_REALMEDIA_RM:
case XX_FILE_TYPE_INTERPLAY_MVE:
case XX_FILE_TYPE_WESTWOOD_VQA:
case XX_FILE_TYPE_MNG_ANIMATION:
case XX_FILE_TYPE_SCUMMVM_DXA:
return true;default:return false;}}
static bool sx_nextmedia_build(sx_context*c)
{if(!c||!c->f||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid||c->size<=0||c->size>134217728)return false;sxnx_view view={c,NULL,(size_t)c->size,0},*v=&view;v->p=(uint8_t*)xx_mem_alloc(v->n);if(!v->p||!sx_read(c,0,v->p,v->n)){xx_mem_free(v->p);return false;}bool ok=false;
 switch(c->f->file_type){
case XX_FILE_TYPE_EMF:ok=sx_emf_build(v);break;
case XX_FILE_TYPE_WMF:ok=sx_wmf_build(v);break;
case XX_FILE_TYPE_GIMP_XCF:ok=sx_gimp_xcf_build(v);break;
case XX_FILE_TYPE_PHOTOSHOP_ABR:ok=sx_photoshop_abr_build(v);break;
case XX_FILE_TYPE_QT_QPICTURE:ok=sx_qt_qpicture_build(v);break;
case XX_FILE_TYPE_BPG_IMAGE:ok=sx_bpg_image_build(v);break;
case XX_FILE_TYPE_PAINTSHOP_PSP:ok=sx_paintshop_psp_build(v);break;
case XX_FILE_TYPE_PHOTOSHOP_PAT:ok=sx_photoshop_pat_build(v);break;
case XX_FILE_TYPE_AMIGA_DISKOBJECT:ok=sx_amiga_diskobject_build(v);break;
case XX_FILE_TYPE_WBMP_IMAGE:ok=sx_wbmp_image_build(v);break;
case XX_FILE_TYPE_PALM_BITMAP:ok=sx_palm_bitmap_build(v);break;
case XX_FILE_TYPE_APPLE_PICT:ok=sx_apple_pict_build(v);break;
case XX_FILE_TYPE_WORDPERFECT_WPG:ok=sx_wordperfect_wpg_build(v);break;
case XX_FILE_TYPE_KHOROS_VIFF:ok=sx_khoros_viff_build(v);break;
case XX_FILE_TYPE_RISC_OS_SPRITE:ok=sx_risc_os_sprite_build(v);break;
case XX_FILE_TYPE_WINDOWS_ANI:ok=sx_windows_ani_build(v);break;
case XX_FILE_TYPE_WINDOWS_THUMBNAIL_CACHE:ok=sx_windows_thumbnail_cache_build(v);break;
case XX_FILE_TYPE_SONY_PAMF:ok=sx_sony_pamf_build(v);break;
case XX_FILE_TYPE_CRI_USM:ok=sx_cri_usm_build(v);break;
case XX_FILE_TYPE_MPEG_TRANSPORT_STREAM:ok=sx_mpeg_transport_stream_build(v);break;
case XX_FILE_TYPE_MPEG_PROGRAM_STREAM:ok=sx_mpeg_program_stream_build(v);break;
case XX_FILE_TYPE_REALMEDIA_RM:ok=sx_realmedia_rm_build(v);break;
case XX_FILE_TYPE_INTERPLAY_MVE:ok=sx_interplay_mve_build(v);break;
case XX_FILE_TYPE_WESTWOOD_VQA:ok=sx_westwood_vqa_build(v);break;
case XX_FILE_TYPE_MNG_ANIMATION:ok=sx_mng_animation_build(v);break;
case XX_FILE_TYPE_SCUMMVM_DXA:ok=sx_scummvm_dxa_build(v);break;
default:break;}
 xx_mem_free(v->p);return ok&&sxnx_finish(c);}
#undef SN_ROW
static bool sx_nextmedia_comment(xx_data_struct_record*r,uint32_t id)
{
 if(!r||!r->name||id<UINT32_C(0x60320001)||id>=UINT32_C(0x60330000))return true;
 if(id==1613889537u&&!xx_rt_wcscmp(r->name,L"record_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 1u:return xx_data_struct_record_set_comment(r,L"EMR_HEADER");
 case 2u:return xx_data_struct_record_set_comment(r,L"EMR_POLYBEZIER");
 case 3u:return xx_data_struct_record_set_comment(r,L"EMR_POLYGON");
 case 4u:return xx_data_struct_record_set_comment(r,L"EMR_POLYLINE");
 case 5u:return xx_data_struct_record_set_comment(r,L"EMR_POLYBEZIERTO");
 case 6u:return xx_data_struct_record_set_comment(r,L"EMR_POLYLINETO");
 case 9u:return xx_data_struct_record_set_comment(r,L"EMR_SETWINDOWEXTEX");
 case 10u:return xx_data_struct_record_set_comment(r,L"EMR_SETWINDOWORGEX");
 case 11u:return xx_data_struct_record_set_comment(r,L"EMR_SETVIEWPORTEXTEX");
 case 12u:return xx_data_struct_record_set_comment(r,L"EMR_SETVIEWPORTORGEX");
 case 14u:return xx_data_struct_record_set_comment(r,L"EMR_EOF");
 case 15u:return xx_data_struct_record_set_comment(r,L"EMR_SETPIXELV");
 case 16u:return xx_data_struct_record_set_comment(r,L"EMR_SETMAPPERFLAGS");
 case 17u:return xx_data_struct_record_set_comment(r,L"EMR_SETMAPMODE");
 case 18u:return xx_data_struct_record_set_comment(r,L"EMR_SETBKMODE");
 case 19u:return xx_data_struct_record_set_comment(r,L"EMR_SETPOLYFILLMODE");
 case 20u:return xx_data_struct_record_set_comment(r,L"EMR_SETROP2");
 case 21u:return xx_data_struct_record_set_comment(r,L"EMR_SETSTRETCHBLTMODE");
 case 22u:return xx_data_struct_record_set_comment(r,L"EMR_SETTEXTALIGN");
 case 24u:return xx_data_struct_record_set_comment(r,L"EMR_SETTEXTCOLOR");
 case 25u:return xx_data_struct_record_set_comment(r,L"EMR_SETBKCOLOR");
 case 27u:return xx_data_struct_record_set_comment(r,L"EMR_MOVETOEX");
 case 33u:return xx_data_struct_record_set_comment(r,L"EMR_SAVEDC");
 case 34u:return xx_data_struct_record_set_comment(r,L"EMR_RESTOREDC");
 case 37u:return xx_data_struct_record_set_comment(r,L"EMR_SELECTOBJECT");
 case 38u:return xx_data_struct_record_set_comment(r,L"EMR_CREATEPEN");
 case 39u:return xx_data_struct_record_set_comment(r,L"EMR_CREATEBRUSHINDIRECT");
 case 40u:return xx_data_struct_record_set_comment(r,L"EMR_DELETEOBJECT");
 case 42u:return xx_data_struct_record_set_comment(r,L"EMR_ELLIPSE");
 case 43u:return xx_data_struct_record_set_comment(r,L"EMR_RECTANGLE");
 case 54u:return xx_data_struct_record_set_comment(r,L"EMR_LINETO");
 default:break;}}
 if(id==1613889538u&&!xx_rt_wcscmp(r->name,L"record_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 1u:return xx_data_struct_record_set_comment(r,L"EMR_HEADER");
 case 2u:return xx_data_struct_record_set_comment(r,L"EMR_POLYBEZIER");
 case 3u:return xx_data_struct_record_set_comment(r,L"EMR_POLYGON");
 case 4u:return xx_data_struct_record_set_comment(r,L"EMR_POLYLINE");
 case 5u:return xx_data_struct_record_set_comment(r,L"EMR_POLYBEZIERTO");
 case 6u:return xx_data_struct_record_set_comment(r,L"EMR_POLYLINETO");
 case 9u:return xx_data_struct_record_set_comment(r,L"EMR_SETWINDOWEXTEX");
 case 10u:return xx_data_struct_record_set_comment(r,L"EMR_SETWINDOWORGEX");
 case 11u:return xx_data_struct_record_set_comment(r,L"EMR_SETVIEWPORTEXTEX");
 case 12u:return xx_data_struct_record_set_comment(r,L"EMR_SETVIEWPORTORGEX");
 case 14u:return xx_data_struct_record_set_comment(r,L"EMR_EOF");
 case 15u:return xx_data_struct_record_set_comment(r,L"EMR_SETPIXELV");
 case 16u:return xx_data_struct_record_set_comment(r,L"EMR_SETMAPPERFLAGS");
 case 17u:return xx_data_struct_record_set_comment(r,L"EMR_SETMAPMODE");
 case 18u:return xx_data_struct_record_set_comment(r,L"EMR_SETBKMODE");
 case 19u:return xx_data_struct_record_set_comment(r,L"EMR_SETPOLYFILLMODE");
 case 20u:return xx_data_struct_record_set_comment(r,L"EMR_SETROP2");
 case 21u:return xx_data_struct_record_set_comment(r,L"EMR_SETSTRETCHBLTMODE");
 case 22u:return xx_data_struct_record_set_comment(r,L"EMR_SETTEXTALIGN");
 case 24u:return xx_data_struct_record_set_comment(r,L"EMR_SETTEXTCOLOR");
 case 25u:return xx_data_struct_record_set_comment(r,L"EMR_SETBKCOLOR");
 case 27u:return xx_data_struct_record_set_comment(r,L"EMR_MOVETOEX");
 case 33u:return xx_data_struct_record_set_comment(r,L"EMR_SAVEDC");
 case 34u:return xx_data_struct_record_set_comment(r,L"EMR_RESTOREDC");
 case 37u:return xx_data_struct_record_set_comment(r,L"EMR_SELECTOBJECT");
 case 38u:return xx_data_struct_record_set_comment(r,L"EMR_CREATEPEN");
 case 39u:return xx_data_struct_record_set_comment(r,L"EMR_CREATEBRUSHINDIRECT");
 case 40u:return xx_data_struct_record_set_comment(r,L"EMR_DELETEOBJECT");
 case 42u:return xx_data_struct_record_set_comment(r,L"EMR_ELLIPSE");
 case 43u:return xx_data_struct_record_set_comment(r,L"EMR_RECTANGLE");
 case 54u:return xx_data_struct_record_set_comment(r,L"EMR_LINETO");
 default:break;}}
 if(id==1613889552u&&!xx_rt_wcscmp(r->name,L"function")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"META_EOF");
 case 30u:return xx_data_struct_record_set_comment(r,L"META_SAVEDC");
 case 295u:return xx_data_struct_record_set_comment(r,L"META_RESTOREDC");
 case 301u:return xx_data_struct_record_set_comment(r,L"META_SELECTOBJECT");
 case 496u:return xx_data_struct_record_set_comment(r,L"META_DELETEOBJECT");
 case 513u:return xx_data_struct_record_set_comment(r,L"META_SETBKCOLOR");
 case 521u:return xx_data_struct_record_set_comment(r,L"META_SETTEXTCOLOR");
 case 531u:return xx_data_struct_record_set_comment(r,L"META_LINETO");
 case 532u:return xx_data_struct_record_set_comment(r,L"META_MOVETO");
 case 762u:return xx_data_struct_record_set_comment(r,L"META_CREATEPENINDIRECT");
 case 764u:return xx_data_struct_record_set_comment(r,L"META_CREATEBRUSHINDIRECT");
 case 804u:return xx_data_struct_record_set_comment(r,L"META_POLYGON");
 case 805u:return xx_data_struct_record_set_comment(r,L"META_POLYLINE");
 case 1048u:return xx_data_struct_record_set_comment(r,L"META_ELLIPSE");
 case 1051u:return xx_data_struct_record_set_comment(r,L"META_RECTANGLE");
 default:break;}}
 if(id==1613889551u&&!xx_rt_wcscmp(r->name,L"file_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 1u:return xx_data_struct_record_set_comment(r,L"MEMORY_METAFILE");
 case 2u:return xx_data_struct_record_set_comment(r,L"DISK_METAFILE");
 default:break;}}
 if(id==1613889548u&&!xx_rt_wcscmp(r->name,L"style")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"BS_SOLID");
 case 1u:return xx_data_struct_record_set_comment(r,L"BS_NULL");
 case 2u:return xx_data_struct_record_set_comment(r,L"BS_HATCHED");
 case 3u:return xx_data_struct_record_set_comment(r,L"BS_PATTERN");
 case 5u:return xx_data_struct_record_set_comment(r,L"BS_DIBPATTERN");
 default:break;}}
 if(id==1613889562u&&!xx_rt_wcscmp(r->name,L"style")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"BS_SOLID");
 case 1u:return xx_data_struct_record_set_comment(r,L"BS_NULL");
 case 2u:return xx_data_struct_record_set_comment(r,L"BS_HATCHED");
 case 3u:return xx_data_struct_record_set_comment(r,L"BS_PATTERN");
 case 5u:return xx_data_struct_record_set_comment(r,L"BS_DIBPATTERN");
 default:break;}}
 if(id==1613889548u&&!xx_rt_wcscmp(r->name,L"hatch")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"HS_HORIZONTAL");
 case 1u:return xx_data_struct_record_set_comment(r,L"HS_VERTICAL");
 case 2u:return xx_data_struct_record_set_comment(r,L"HS_FDIAGONAL");
 case 3u:return xx_data_struct_record_set_comment(r,L"HS_BDIAGONAL");
 case 4u:return xx_data_struct_record_set_comment(r,L"HS_CROSS");
 case 5u:return xx_data_struct_record_set_comment(r,L"HS_DIAGCROSS");
 default:break;}}
 if(id==1613889562u&&!xx_rt_wcscmp(r->name,L"hatch")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"HS_HORIZONTAL");
 case 1u:return xx_data_struct_record_set_comment(r,L"HS_VERTICAL");
 case 2u:return xx_data_struct_record_set_comment(r,L"HS_FDIAGONAL");
 case 3u:return xx_data_struct_record_set_comment(r,L"HS_BDIAGONAL");
 case 4u:return xx_data_struct_record_set_comment(r,L"HS_CROSS");
 case 5u:return xx_data_struct_record_set_comment(r,L"HS_DIAGCROSS");
 default:break;}}
 if(id==1613889563u&&!xx_rt_wcscmp(r->name,L"type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"WBMP_TYPE_0_MONOCHROME");
 default:break;}}
 if(id==1613889568u&&!xx_rt_wcscmp(r->name,L"compression")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"SCANLINE");
 case 1u:return xx_data_struct_record_set_comment(r,L"RLE");
 case 2u:return xx_data_struct_record_set_comment(r,L"PACKBITS");
 case 255u:return xx_data_struct_record_set_comment(r,L"UNCOMPRESSED");
 default:break;}}
 if(id==1613889572u&&!xx_rt_wcscmp(r->name,L"machine_dependency")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 2u:return xx_data_struct_record_set_comment(r,L"IEEE_BIG_ENDIAN");
 case 4u:return xx_data_struct_record_set_comment(r,L"DEC_VAX");
 case 8u:return xx_data_struct_record_set_comment(r,L"IEEE_LITTLE_ENDIAN");
 default:break;}}
 if(id==1613889573u&&!xx_rt_wcscmp(r->name,L"machine_dependency")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 2u:return xx_data_struct_record_set_comment(r,L"IEEE_BIG_ENDIAN");
 case 4u:return xx_data_struct_record_set_comment(r,L"DEC_VAX");
 case 8u:return xx_data_struct_record_set_comment(r,L"IEEE_LITTLE_ENDIAN");
 default:break;}}
 if(id==1613889574u&&!xx_rt_wcscmp(r->name,L"machine_dependency")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 2u:return xx_data_struct_record_set_comment(r,L"IEEE_BIG_ENDIAN");
 case 4u:return xx_data_struct_record_set_comment(r,L"DEC_VAX");
 case 8u:return xx_data_struct_record_set_comment(r,L"IEEE_LITTLE_ENDIAN");
 default:break;}}
 if(id==1613889572u&&!xx_rt_wcscmp(r->name,L"storage_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 1u:return xx_data_struct_record_set_comment(r,L"VFF_TYP_1_BYTE");
 case 2u:return xx_data_struct_record_set_comment(r,L"VFF_TYP_2_BYTE");
 case 4u:return xx_data_struct_record_set_comment(r,L"VFF_TYP_4_BYTE");
 case 5u:return xx_data_struct_record_set_comment(r,L"VFF_TYP_FLOAT");
 case 9u:return xx_data_struct_record_set_comment(r,L"VFF_TYP_DOUBLE");
 default:break;}}
 if(id==1613889573u&&!xx_rt_wcscmp(r->name,L"storage_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 1u:return xx_data_struct_record_set_comment(r,L"VFF_TYP_1_BYTE");
 case 2u:return xx_data_struct_record_set_comment(r,L"VFF_TYP_2_BYTE");
 case 4u:return xx_data_struct_record_set_comment(r,L"VFF_TYP_4_BYTE");
 case 5u:return xx_data_struct_record_set_comment(r,L"VFF_TYP_FLOAT");
 case 9u:return xx_data_struct_record_set_comment(r,L"VFF_TYP_DOUBLE");
 default:break;}}
 if(id==1613889574u&&!xx_rt_wcscmp(r->name,L"storage_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 1u:return xx_data_struct_record_set_comment(r,L"VFF_TYP_1_BYTE");
 case 2u:return xx_data_struct_record_set_comment(r,L"VFF_TYP_2_BYTE");
 case 4u:return xx_data_struct_record_set_comment(r,L"VFF_TYP_4_BYTE");
 case 5u:return xx_data_struct_record_set_comment(r,L"VFF_TYP_FLOAT");
 case 9u:return xx_data_struct_record_set_comment(r,L"VFF_TYP_DOUBLE");
 default:break;}}
 if(id==1613889576u&&!xx_rt_wcscmp(r->name,L"brush_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 1u:return xx_data_struct_record_set_comment(r,L"COMPUTED_BRUSH");
 case 2u:return xx_data_struct_record_set_comment(r,L"SAMPLED_BRUSH");
 default:break;}}
 if(id==1613889579u&&!xx_rt_wcscmp(r->name,L"compression")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"STORED");
 case 1u:return xx_data_struct_record_set_comment(r,L"PACKBITS");
 default:break;}}
 if(id==1613889599u&&!xx_rt_wcscmp(r->name,L"compression")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"STORED");
 case 1u:return xx_data_struct_record_set_comment(r,L"PACKBITS");
 default:break;}}
 if(id==1613889582u&&!xx_rt_wcscmp(r->name,L"record_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 11u:return xx_data_struct_record_set_comment(r,L"BITMAP_TYPE_1");
 case 14u:return xx_data_struct_record_set_comment(r,L"COLORMAP");
 case 15u:return xx_data_struct_record_set_comment(r,L"START_WPG");
 case 16u:return xx_data_struct_record_set_comment(r,L"END_WPG");
 default:break;}}
 if(id==1613889583u&&!xx_rt_wcscmp(r->name,L"record_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 11u:return xx_data_struct_record_set_comment(r,L"BITMAP_TYPE_1");
 case 14u:return xx_data_struct_record_set_comment(r,L"COLORMAP");
 case 15u:return xx_data_struct_record_set_comment(r,L"START_WPG");
 case 16u:return xx_data_struct_record_set_comment(r,L"END_WPG");
 default:break;}}
 if(id==1613889584u&&!xx_rt_wcscmp(r->name,L"record_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 11u:return xx_data_struct_record_set_comment(r,L"BITMAP_TYPE_1");
 case 14u:return xx_data_struct_record_set_comment(r,L"COLORMAP");
 case 15u:return xx_data_struct_record_set_comment(r,L"START_WPG");
 case 16u:return xx_data_struct_record_set_comment(r,L"END_WPG");
 default:break;}}
 if(id==1613889590u&&!xx_rt_wcscmp(r->name,L"block_id")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"PSP_IMAGE_BLOCK");
 case 1u:return xx_data_struct_record_set_comment(r,L"PSP_CREATOR_BLOCK");
 case 2u:return xx_data_struct_record_set_comment(r,L"PSP_COLOR_BLOCK");
 case 3u:return xx_data_struct_record_set_comment(r,L"PSP_LAYER_START_BLOCK");
 case 4u:return xx_data_struct_record_set_comment(r,L"PSP_LAYER_BLOCK");
 case 5u:return xx_data_struct_record_set_comment(r,L"PSP_CHANNEL_BLOCK");
 case 6u:return xx_data_struct_record_set_comment(r,L"PSP_SELECTION_BLOCK");
 case 7u:return xx_data_struct_record_set_comment(r,L"PSP_ALPHA_BANK_BLOCK");
 case 8u:return xx_data_struct_record_set_comment(r,L"PSP_ALPHA_CHANNEL_BLOCK");
 case 9u:return xx_data_struct_record_set_comment(r,L"PSP_COMPOSITE_IMAGE_BLOCK");
 case 10u:return xx_data_struct_record_set_comment(r,L"PSP_EXTENDED_DATA_BLOCK");
 default:break;}}
 if(id==1613889591u&&!xx_rt_wcscmp(r->name,L"compression")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"PSP_COMP_NONE");
 case 1u:return xx_data_struct_record_set_comment(r,L"PSP_COMP_RLE");
 case 2u:return xx_data_struct_record_set_comment(r,L"PSP_COMP_LZ77");
 case 3u:return xx_data_struct_record_set_comment(r,L"PSP_COMP_JPEG");
 default:break;}}
 if(id==1613889591u&&!xx_rt_wcscmp(r->name,L"resolution_unit")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"UNDEFINED");
 case 1u:return xx_data_struct_record_set_comment(r,L"INCHES");
 case 2u:return xx_data_struct_record_set_comment(r,L"CENTIMETERS");
 default:break;}}
 if(id==1613889592u&&!xx_rt_wcscmp(r->name,L"layer_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"NORMAL_RASTER");
 case 1u:return xx_data_struct_record_set_comment(r,L"FLOATING_SELECTION");
 case 2u:return xx_data_struct_record_set_comment(r,L"VECTOR");
 default:break;}}
 if(id==1613889595u&&!xx_rt_wcscmp(r->name,L"image_mode")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 1u:return xx_data_struct_record_set_comment(r,L"GRAYSCALE");
 case 2u:return xx_data_struct_record_set_comment(r,L"INDEXED");
 case 3u:return xx_data_struct_record_set_comment(r,L"RGB");
 default:break;}}
 if(id==1613889603u&&!xx_rt_wcscmp(r->name,L"begin_opcode")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 30u:return xx_data_struct_record_set_comment(r,L"PdcBegin");
 default:break;}}
 if(id==1613889604u&&!xx_rt_wcscmp(r->name,L"opcode")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"PdcNOP");
 case 1u:return xx_data_struct_record_set_comment(r,L"PdcDrawPoint");
 case 4u:return xx_data_struct_record_set_comment(r,L"PdcDrawLine");
 case 5u:return xx_data_struct_record_set_comment(r,L"PdcDrawRect");
 case 6u:return xx_data_struct_record_set_comment(r,L"PdcDrawRoundRect");
 case 7u:return xx_data_struct_record_set_comment(r,L"PdcDrawEllipse");
 case 8u:return xx_data_struct_record_set_comment(r,L"PdcDrawArc");
 case 9u:return xx_data_struct_record_set_comment(r,L"PdcDrawPie");
 case 10u:return xx_data_struct_record_set_comment(r,L"PdcDrawChord");
 case 12u:return xx_data_struct_record_set_comment(r,L"PdcDrawPolyline");
 case 13u:return xx_data_struct_record_set_comment(r,L"PdcDrawPolygon");
 case 31u:return xx_data_struct_record_set_comment(r,L"PdcEnd");
 case 32u:return xx_data_struct_record_set_comment(r,L"PdcSave");
 case 33u:return xx_data_struct_record_set_comment(r,L"PdcRestore");
 case 41u:return xx_data_struct_record_set_comment(r,L"PdcSetBkMode");
 case 42u:return xx_data_struct_record_set_comment(r,L"PdcSetROP");
 case 63u:return xx_data_struct_record_set_comment(r,L"PdcSetRenderHint");
 case 64u:return xx_data_struct_record_set_comment(r,L"PdcSetCompositionMode");
 case 65u:return xx_data_struct_record_set_comment(r,L"PdcSetClipEnabled");
 case 66u:return xx_data_struct_record_set_comment(r,L"PdcSetOpacity");
 default:break;}}
 if(id==1613889605u&&!xx_rt_wcscmp(r->name,L"opcode")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"PdcNOP");
 case 1u:return xx_data_struct_record_set_comment(r,L"PdcDrawPoint");
 case 4u:return xx_data_struct_record_set_comment(r,L"PdcDrawLine");
 case 5u:return xx_data_struct_record_set_comment(r,L"PdcDrawRect");
 case 6u:return xx_data_struct_record_set_comment(r,L"PdcDrawRoundRect");
 case 7u:return xx_data_struct_record_set_comment(r,L"PdcDrawEllipse");
 case 8u:return xx_data_struct_record_set_comment(r,L"PdcDrawArc");
 case 9u:return xx_data_struct_record_set_comment(r,L"PdcDrawPie");
 case 10u:return xx_data_struct_record_set_comment(r,L"PdcDrawChord");
 case 12u:return xx_data_struct_record_set_comment(r,L"PdcDrawPolyline");
 case 13u:return xx_data_struct_record_set_comment(r,L"PdcDrawPolygon");
 case 31u:return xx_data_struct_record_set_comment(r,L"PdcEnd");
 case 32u:return xx_data_struct_record_set_comment(r,L"PdcSave");
 case 33u:return xx_data_struct_record_set_comment(r,L"PdcRestore");
 case 41u:return xx_data_struct_record_set_comment(r,L"PdcSetBkMode");
 case 42u:return xx_data_struct_record_set_comment(r,L"PdcSetROP");
 case 63u:return xx_data_struct_record_set_comment(r,L"PdcSetRenderHint");
 case 64u:return xx_data_struct_record_set_comment(r,L"PdcSetCompositionMode");
 case 65u:return xx_data_struct_record_set_comment(r,L"PdcSetClipEnabled");
 case 66u:return xx_data_struct_record_set_comment(r,L"PdcSetOpacity");
 default:break;}}
 if(id==1613889612u&&!xx_rt_wcscmp(r->name,L"fill_rule")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"OddEvenFill");
 case 1u:return xx_data_struct_record_set_comment(r,L"WindingFill");
 default:break;}}
 if(id==1613889616u&&!xx_rt_wcscmp(r->name,L"enabled")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"FALSE");
 case 1u:return xx_data_struct_record_set_comment(r,L"TRUE");
 default:break;}}
 if(id==1613889618u&&!xx_rt_wcscmp(r->name,L"object_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 1u:return xx_data_struct_record_set_comment(r,L"WBDISK");
 case 2u:return xx_data_struct_record_set_comment(r,L"WBDRAWER");
 case 3u:return xx_data_struct_record_set_comment(r,L"WBTOOL");
 case 4u:return xx_data_struct_record_set_comment(r,L"WBPROJECT");
 case 5u:return xx_data_struct_record_set_comment(r,L"WBGARBAGE");
 case 6u:return xx_data_struct_record_set_comment(r,L"WBDEVICE");
 case 7u:return xx_data_struct_record_set_comment(r,L"WBKICK");
 case 8u:return xx_data_struct_record_set_comment(r,L"WBAPPICON");
 default:break;}}
 if(id==1613889625u&&!xx_rt_wcscmp(r->name,L"opcode")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 1u:return xx_data_struct_record_set_comment(r,L"Clip");
 case 154u:return xx_data_struct_record_set_comment(r,L"DirectBitsRect");
 case 255u:return xx_data_struct_record_set_comment(r,L"EndPic");
 default:break;}}
 if(id==1613889626u&&!xx_rt_wcscmp(r->name,L"opcode")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 1u:return xx_data_struct_record_set_comment(r,L"Clip");
 case 154u:return xx_data_struct_record_set_comment(r,L"DirectBitsRect");
 case 255u:return xx_data_struct_record_set_comment(r,L"EndPic");
 default:break;}}
 if(id==1613889629u&&!xx_rt_wcscmp(r->name,L"opcode")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 1u:return xx_data_struct_record_set_comment(r,L"Clip");
 case 154u:return xx_data_struct_record_set_comment(r,L"DirectBitsRect");
 case 255u:return xx_data_struct_record_set_comment(r,L"EndPic");
 default:break;}}
 if(id==1613889626u&&!xx_rt_wcscmp(r->name,L"pack_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 4u:return xx_data_struct_record_set_comment(r,L"COMPONENT_PACKBITS");
 default:break;}}
 if(id==1613889626u&&!xx_rt_wcscmp(r->name,L"transfer_mode")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 64u:return xx_data_struct_record_set_comment(r,L"ditherCopy");
 default:break;}}
 if(id==1613889639u&&!xx_rt_wcscmp(r->name,L"image_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"RGB");
 case 1u:return xx_data_struct_record_set_comment(r,L"GRAY");
 case 2u:return xx_data_struct_record_set_comment(r,L"INDEXED");
 default:break;}}
 if(id==1613889652u&&!xx_rt_wcscmp(r->name,L"compression")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"STORED");
 case 1u:return xx_data_struct_record_set_comment(r,L"RLE");
 case 2u:return xx_data_struct_record_set_comment(r,L"ZLIB");
 case 3u:return xx_data_struct_record_set_comment(r,L"FRACTAL");
 default:break;}}
 if(id==1613889640u&&!xx_rt_wcscmp(r->name,L"property_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"PROP_END");
 case 1u:return xx_data_struct_record_set_comment(r,L"PROP_COLORMAP");
 case 6u:return xx_data_struct_record_set_comment(r,L"PROP_OPACITY");
 case 7u:return xx_data_struct_record_set_comment(r,L"PROP_MODE");
 case 8u:return xx_data_struct_record_set_comment(r,L"PROP_VISIBLE");
 case 9u:return xx_data_struct_record_set_comment(r,L"PROP_LINKED");
 case 10u:return xx_data_struct_record_set_comment(r,L"PROP_LOCK_ALPHA");
 case 11u:return xx_data_struct_record_set_comment(r,L"PROP_APPLY_MASK");
 case 12u:return xx_data_struct_record_set_comment(r,L"PROP_EDIT_MASK");
 case 13u:return xx_data_struct_record_set_comment(r,L"PROP_SHOW_MASK");
 case 14u:return xx_data_struct_record_set_comment(r,L"PROP_SHOW_MASKED");
 case 15u:return xx_data_struct_record_set_comment(r,L"PROP_OFFSETS");
 case 16u:return xx_data_struct_record_set_comment(r,L"PROP_COLOR");
 case 17u:return xx_data_struct_record_set_comment(r,L"PROP_COMPRESSION");
 case 18u:return xx_data_struct_record_set_comment(r,L"PROP_GUIDES");
 case 19u:return xx_data_struct_record_set_comment(r,L"PROP_RESOLUTION");
 case 20u:return xx_data_struct_record_set_comment(r,L"PROP_TATTOO");
 case 21u:return xx_data_struct_record_set_comment(r,L"PROP_PARASITES");
 case 22u:return xx_data_struct_record_set_comment(r,L"PROP_UNIT");
 case 27u:return xx_data_struct_record_set_comment(r,L"PROP_SAMPLE_POINTS");
 default:break;}}
 if(id==1613889689u&&!xx_rt_wcscmp(r->name,L"image_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 1u:return xx_data_struct_record_set_comment(r,L"ICON");
 case 2u:return xx_data_struct_record_set_comment(r,L"CURSOR");
 default:break;}}
 if(id==1613889696u&&!xx_rt_wcscmp(r->name,L"coding_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 27u:return xx_data_struct_record_set_comment(r,L"AVC");
 case 2u:return xx_data_struct_record_set_comment(r,L"MPEG2_VIDEO");
 case 220u:return xx_data_struct_record_set_comment(r,L"ATRAC3PLUS");
 case 128u:return xx_data_struct_record_set_comment(r,L"LPCM");
 case 129u:return xx_data_struct_record_set_comment(r,L"AC3");
 case 221u:return xx_data_struct_record_set_comment(r,L"USER_DATA");
 default:break;}}
 if(id==1613889702u&&!xx_rt_wcscmp(r->name,L"payload_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"STREAM");
 case 1u:return xx_data_struct_record_set_comment(r,L"HEADER");
 case 2u:return xx_data_struct_record_set_comment(r,L"SECTION_END");
 case 3u:return xx_data_struct_record_set_comment(r,L"METADATA");
 default:break;}}
 if(id==1613889719u&&!xx_rt_wcscmp(r->name,L"chunk_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"INIT_AUDIO");
 case 1u:return xx_data_struct_record_set_comment(r,L"AUDIO_ONLY");
 case 2u:return xx_data_struct_record_set_comment(r,L"INIT_VIDEO");
 case 3u:return xx_data_struct_record_set_comment(r,L"VIDEO");
 case 4u:return xx_data_struct_record_set_comment(r,L"SHUTDOWN");
 case 5u:return xx_data_struct_record_set_comment(r,L"END");
 default:break;}}
 if(id==1613889720u&&!xx_rt_wcscmp(r->name,L"opcode")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"END_OF_STREAM");
 case 1u:return xx_data_struct_record_set_comment(r,L"END_OF_CHUNK");
 case 2u:return xx_data_struct_record_set_comment(r,L"CREATE_TIMER");
 case 3u:return xx_data_struct_record_set_comment(r,L"INIT_AUDIO");
 case 4u:return xx_data_struct_record_set_comment(r,L"START_STOP_AUDIO");
 case 5u:return xx_data_struct_record_set_comment(r,L"INIT_VIDEO");
 case 6u:return xx_data_struct_record_set_comment(r,L"VIDEO_DATA_06");
 case 7u:return xx_data_struct_record_set_comment(r,L"SEND_BUFFER");
 case 8u:return xx_data_struct_record_set_comment(r,L"AUDIO_FRAME");
 case 9u:return xx_data_struct_record_set_comment(r,L"AUDIO_SILENCE");
 case 10u:return xx_data_struct_record_set_comment(r,L"SET_VIDEO_MODE");
 case 12u:return xx_data_struct_record_set_comment(r,L"SET_PALETTE");
 case 15u:return xx_data_struct_record_set_comment(r,L"SET_DECODING_MAP");
 case 16u:return xx_data_struct_record_set_comment(r,L"VIDEO_DATA_10");
 case 17u:return xx_data_struct_record_set_comment(r,L"VIDEO_DATA_11");
 default:break;}}
 if(id==1613889739u&&!xx_rt_wcscmp(r->name,L"color_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"GRAYSCALE");
 case 2u:return xx_data_struct_record_set_comment(r,L"TRUECOLOR");
 case 3u:return xx_data_struct_record_set_comment(r,L"INDEXED_COLOR");
 case 4u:return xx_data_struct_record_set_comment(r,L"GRAYSCALE_ALPHA");
 case 6u:return xx_data_struct_record_set_comment(r,L"TRUECOLOR_ALPHA");
 default:break;}}
 if(id==1613889739u&&!xx_rt_wcscmp(r->name,L"compression")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"DEFLATE");
 default:break;}}
 if(id==1613889739u&&!xx_rt_wcscmp(r->name,L"interlace")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"NONE");
 case 1u:return xx_data_struct_record_set_comment(r,L"ADAM7");
 default:break;}}
 if(id==1613889746u&&!xx_rt_wcscmp(r->name,L"rendering_intent")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"PERCEPTUAL");
 case 1u:return xx_data_struct_record_set_comment(r,L"RELATIVE_COLORIMETRIC");
 case 2u:return xx_data_struct_record_set_comment(r,L"SATURATION");
 case 3u:return xx_data_struct_record_set_comment(r,L"ABSOLUTE_COLORIMETRIC");
 default:break;}}
 if(id==1613889747u&&!xx_rt_wcscmp(r->name,L"unit")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"UNSPECIFIED");
 case 1u:return xx_data_struct_record_set_comment(r,L"METERS");
 default:break;}}
 if(id==1613889756u&&!xx_rt_wcscmp(r->name,L"compression")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 2u:return xx_data_struct_record_set_comment(r,L"ZLIB");
 case 3u:return xx_data_struct_record_set_comment(r,L"ZLIB_XOR_PREVIOUS");
 default:break;}}
 if(id==1613889795u&&!xx_rt_wcscmp(r->name,L"table_id")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"PAT");
 case 2u:return xx_data_struct_record_set_comment(r,L"PMT");
 case 66u:return xx_data_struct_record_set_comment(r,L"SDT_ACTUAL");
 case 70u:return xx_data_struct_record_set_comment(r,L"SDT_OTHER");
 default:break;}}
 if(id==1613889798u&&!xx_rt_wcscmp(r->name,L"stream_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 1u:return xx_data_struct_record_set_comment(r,L"MPEG1_VIDEO");
 case 2u:return xx_data_struct_record_set_comment(r,L"MPEG2_VIDEO");
 case 3u:return xx_data_struct_record_set_comment(r,L"MPEG1_AUDIO");
 case 4u:return xx_data_struct_record_set_comment(r,L"MPEG2_AUDIO");
 case 6u:return xx_data_struct_record_set_comment(r,L"PRIVATE_DATA");
 case 15u:return xx_data_struct_record_set_comment(r,L"AAC_ADTS");
 case 16u:return xx_data_struct_record_set_comment(r,L"MPEG4_VIDEO");
 case 17u:return xx_data_struct_record_set_comment(r,L"AAC_LATM");
 case 27u:return xx_data_struct_record_set_comment(r,L"H264_AVC");
 case 36u:return xx_data_struct_record_set_comment(r,L"H265_HEVC");
 case 129u:return xx_data_struct_record_set_comment(r,L"AC3");
 default:break;}}
 if(id==1613889786u&&!xx_rt_wcscmp(r->name,L"stream_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 1u:return xx_data_struct_record_set_comment(r,L"MPEG1_VIDEO");
 case 2u:return xx_data_struct_record_set_comment(r,L"MPEG2_VIDEO");
 case 3u:return xx_data_struct_record_set_comment(r,L"MPEG1_AUDIO");
 case 4u:return xx_data_struct_record_set_comment(r,L"MPEG2_AUDIO");
 case 6u:return xx_data_struct_record_set_comment(r,L"PRIVATE_DATA");
 case 15u:return xx_data_struct_record_set_comment(r,L"AAC_ADTS");
 case 16u:return xx_data_struct_record_set_comment(r,L"MPEG4_VIDEO");
 case 17u:return xx_data_struct_record_set_comment(r,L"AAC_LATM");
 case 27u:return xx_data_struct_record_set_comment(r,L"H264_AVC");
 case 36u:return xx_data_struct_record_set_comment(r,L"H265_HEVC");
 case 129u:return xx_data_struct_record_set_comment(r,L"AC3");
 default:break;}}
 if(id==1613889537u&&!xx_rt_wcscmp(r->name,L"frame_left"))return xx_data_struct_record_set_comment(r,L"Frame coordinate in 0.01 millimeter units");
 if(id==1613889537u&&!xx_rt_wcscmp(r->name,L"frame_top"))return xx_data_struct_record_set_comment(r,L"Frame coordinate in 0.01 millimeter units");
 if(id==1613889537u&&!xx_rt_wcscmp(r->name,L"frame_right"))return xx_data_struct_record_set_comment(r,L"Frame coordinate in 0.01 millimeter units");
 if(id==1613889537u&&!xx_rt_wcscmp(r->name,L"frame_bottom"))return xx_data_struct_record_set_comment(r,L"Frame coordinate in 0.01 millimeter units");
 if(id==1613889537u&&!xx_rt_wcscmp(r->name,L"device_width"))return xx_data_struct_record_set_comment(r,L"Reference device size in pixels");
 if(id==1613889537u&&!xx_rt_wcscmp(r->name,L"device_height"))return xx_data_struct_record_set_comment(r,L"Reference device size in pixels");
 if(id==1613889544u&&!xx_rt_wcscmp(r->name,L"color_ref"))return xx_data_struct_record_set_comment(r,L"COLORREF packed as 0x00BBGGRR");
 if(id==1613889547u&&!xx_rt_wcscmp(r->name,L"color_ref"))return xx_data_struct_record_set_comment(r,L"COLORREF packed as 0x00BBGGRR");
 if(id==1613889548u&&!xx_rt_wcscmp(r->name,L"color_ref"))return xx_data_struct_record_set_comment(r,L"COLORREF packed as 0x00BBGGRR");
 if(id==1613889551u&&!xx_rt_wcscmp(r->name,L"header_words"))return xx_data_struct_record_set_comment(r,L"Count of 16-bit words; multiply by 2 for bytes");
 if(id==1613889551u&&!xx_rt_wcscmp(r->name,L"file_words"))return xx_data_struct_record_set_comment(r,L"Count of 16-bit words; multiply by 2 for bytes");
 if(id==1613889551u&&!xx_rt_wcscmp(r->name,L"maximum_record_words"))return xx_data_struct_record_set_comment(r,L"Count of 16-bit words; multiply by 2 for bytes");
 if(id==1613889552u&&!xx_rt_wcscmp(r->name,L"record_words"))return xx_data_struct_record_set_comment(r,L"Count of 16-bit words; multiply by 2 for bytes");
 if(id==1613889560u&&!xx_rt_wcscmp(r->name,L"color_ref"))return xx_data_struct_record_set_comment(r,L"COLORREF packed as 0x00BBGGRR");
 if(id==1613889561u&&!xx_rt_wcscmp(r->name,L"color_ref"))return xx_data_struct_record_set_comment(r,L"COLORREF packed as 0x00BBGGRR");
 if(id==1613889562u&&!xx_rt_wcscmp(r->name,L"color_ref"))return xx_data_struct_record_set_comment(r,L"COLORREF packed as 0x00BBGGRR");
 if(id==1613889568u&&!xx_rt_wcscmp(r->name,L"next_bitmap_words"))return xx_data_struct_record_set_comment(r,L"Bitmap-relative offset in 32-bit words; multiply by 4 for bytes");
 if(id==1613889574u&&!xx_rt_wcscmp(r->name,L"x_bits_per_pixel_vax"))return xx_data_struct_record_set_comment(r,L"Original DEC VAX floating-point bytes; not IEEE decoded");
 if(id==1613889574u&&!xx_rt_wcscmp(r->name,L"y_bits_per_pixel_vax"))return xx_data_struct_record_set_comment(r,L"Original DEC VAX floating-point bytes; not IEEE decoded");
 if(id==1613889618u&&!xx_rt_wcscmp(r->name,L"next_gadget"))return xx_data_struct_record_set_comment(r,L"Serialized pointer or presence marker; not a file offset");
 if(id==1613889618u&&!xx_rt_wcscmp(r->name,L"gadget_render"))return xx_data_struct_record_set_comment(r,L"Serialized pointer or presence marker; not a file offset");
 if(id==1613889618u&&!xx_rt_wcscmp(r->name,L"select_render"))return xx_data_struct_record_set_comment(r,L"Serialized pointer or presence marker; not a file offset");
 if(id==1613889618u&&!xx_rt_wcscmp(r->name,L"gadget_text"))return xx_data_struct_record_set_comment(r,L"Serialized pointer or presence marker; not a file offset");
 if(id==1613889618u&&!xx_rt_wcscmp(r->name,L"special_info"))return xx_data_struct_record_set_comment(r,L"Serialized pointer or presence marker; not a file offset");
 if(id==1613889618u&&!xx_rt_wcscmp(r->name,L"user_data"))return xx_data_struct_record_set_comment(r,L"Serialized pointer or presence marker; not a file offset");
 if(id==1613889618u&&!xx_rt_wcscmp(r->name,L"default_tool"))return xx_data_struct_record_set_comment(r,L"Serialized pointer or presence marker; not a file offset");
 if(id==1613889618u&&!xx_rt_wcscmp(r->name,L"tool_types"))return xx_data_struct_record_set_comment(r,L"Serialized pointer or presence marker; not a file offset");
 if(id==1613889618u&&!xx_rt_wcscmp(r->name,L"drawer_data"))return xx_data_struct_record_set_comment(r,L"Serialized pointer or presence marker; not a file offset");
 if(id==1613889618u&&!xx_rt_wcscmp(r->name,L"tool_window"))return xx_data_struct_record_set_comment(r,L"Serialized pointer or presence marker; not a file offset");
 if(id==1613889619u&&!xx_rt_wcscmp(r->name,L"first_gadget"))return xx_data_struct_record_set_comment(r,L"Serialized pointer or presence marker; not a file offset");
 if(id==1613889619u&&!xx_rt_wcscmp(r->name,L"check_mark"))return xx_data_struct_record_set_comment(r,L"Serialized pointer or presence marker; not a file offset");
 if(id==1613889619u&&!xx_rt_wcscmp(r->name,L"title"))return xx_data_struct_record_set_comment(r,L"Serialized pointer or presence marker; not a file offset");
 if(id==1613889619u&&!xx_rt_wcscmp(r->name,L"screen"))return xx_data_struct_record_set_comment(r,L"Serialized pointer or presence marker; not a file offset");
 if(id==1613889619u&&!xx_rt_wcscmp(r->name,L"bitmap"))return xx_data_struct_record_set_comment(r,L"Serialized pointer or presence marker; not a file offset");
 if(id==1613889620u&&!xx_rt_wcscmp(r->name,L"image_data"))return xx_data_struct_record_set_comment(r,L"Serialized pointer or presence marker; not a file offset");
 if(id==1613889620u&&!xx_rt_wcscmp(r->name,L"next_image"))return xx_data_struct_record_set_comment(r,L"Serialized pointer or presence marker; not a file offset");
 if(id==1613889624u&&!xx_rt_wcscmp(r->name,L"horizontal_resolution_fixed"))return xx_data_struct_record_set_comment(r,L"Unsigned 16.16 fixed-point value");
 if(id==1613889624u&&!xx_rt_wcscmp(r->name,L"vertical_resolution_fixed"))return xx_data_struct_record_set_comment(r,L"Unsigned 16.16 fixed-point value");
 if(id==1613889626u&&!xx_rt_wcscmp(r->name,L"horizontal_resolution_fixed"))return xx_data_struct_record_set_comment(r,L"Unsigned 16.16 fixed-point value");
 if(id==1613889626u&&!xx_rt_wcscmp(r->name,L"vertical_resolution_fixed"))return xx_data_struct_record_set_comment(r,L"Unsigned 16.16 fixed-point value");
 if(id==1613889630u&&!xx_rt_wcscmp(r->name,L"first_sprite_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the omitted area-size word, 4 bytes before the file");
 if(id==1613889630u&&!xx_rt_wcscmp(r->name,L"free_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the omitted area-size word, 4 bytes before the file");
 if(id==1613889631u&&!xx_rt_wcscmp(r->name,L"next_sprite_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the current sprite header");
 if(id==1613889631u&&!xx_rt_wcscmp(r->name,L"image_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the current sprite header");
 if(id==1613889631u&&!xx_rt_wcscmp(r->name,L"mask_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the current sprite header");
 if(id==1613889686u&&!xx_rt_wcscmp(r->name,L"display_rate_jiffies"))return xx_data_struct_record_set_comment(r,L"Duration in 1/60-second jiffies");
 if(id==1613889687u&&!xx_rt_wcscmp(r->name,L"duration_jiffies"))return xx_data_struct_record_set_comment(r,L"Duration in 1/60-second jiffies");
 if(id==1613889693u&&!xx_rt_wcscmp(r->name,L"start_pts_high"))return xx_data_struct_record_set_comment(r,L"Split 90 kHz presentation timestamp; combine high and low words");
 if(id==1613889693u&&!xx_rt_wcscmp(r->name,L"start_pts_low"))return xx_data_struct_record_set_comment(r,L"Split 90 kHz presentation timestamp; combine high and low words");
 if(id==1613889693u&&!xx_rt_wcscmp(r->name,L"end_pts_high"))return xx_data_struct_record_set_comment(r,L"Split 90 kHz presentation timestamp; combine high and low words");
 if(id==1613889693u&&!xx_rt_wcscmp(r->name,L"end_pts_low"))return xx_data_struct_record_set_comment(r,L"Split 90 kHz presentation timestamp; combine high and low words");
 if(id==1613889694u&&!xx_rt_wcscmp(r->name,L"start_pts_high"))return xx_data_struct_record_set_comment(r,L"Split 90 kHz presentation timestamp; combine high and low words");
 if(id==1613889694u&&!xx_rt_wcscmp(r->name,L"start_pts_low"))return xx_data_struct_record_set_comment(r,L"Split 90 kHz presentation timestamp; combine high and low words");
 if(id==1613889694u&&!xx_rt_wcscmp(r->name,L"end_pts_high"))return xx_data_struct_record_set_comment(r,L"Split 90 kHz presentation timestamp; combine high and low words");
 if(id==1613889694u&&!xx_rt_wcscmp(r->name,L"end_pts_low"))return xx_data_struct_record_set_comment(r,L"Split 90 kHz presentation timestamp; combine high and low words");
 if(id==1613889697u&&!xx_rt_wcscmp(r->name,L"width_16pixels"))return xx_data_struct_record_set_comment(r,L"Encoded dimension in 16-pixel units");
 if(id==1613889697u&&!xx_rt_wcscmp(r->name,L"height_16pixels"))return xx_data_struct_record_set_comment(r,L"Encoded dimension in 16-pixel units");
 if(id==1613889698u&&!xx_rt_wcscmp(r->name,L"width_16pixels"))return xx_data_struct_record_set_comment(r,L"Encoded dimension in 16-pixel units");
 if(id==1613889698u&&!xx_rt_wcscmp(r->name,L"height_16pixels"))return xx_data_struct_record_set_comment(r,L"Encoded dimension in 16-pixel units");
 if(id==1613889701u&&!xx_rt_wcscmp(r->name,L"pts_high"))return xx_data_struct_record_set_comment(r,L"Split 90 kHz presentation timestamp; combine high and low words");
 if(id==1613889701u&&!xx_rt_wcscmp(r->name,L"pts_low"))return xx_data_struct_record_set_comment(r,L"Split 90 kHz presentation timestamp; combine high and low words");
 if(id==1613889703u&&!xx_rt_wcscmp(r->name,L"rows_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset from the UTF table base plus 8");
 if(id==1613889703u&&!xx_rt_wcscmp(r->name,L"strings_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset from the UTF table base plus 8");
 if(id==1613889703u&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset from the UTF table base plus 8");
 if(id==1613889703u&&!xx_rt_wcscmp(r->name,L"table_name_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the UTF string pool");
 if(id==1613889704u&&!xx_rt_wcscmp(r->name,L"name_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the UTF string pool");
 if(id==1613889715u&&!xx_rt_wcscmp(r->name,L"string_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the UTF string pool");
 if(id==1613889716u&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the UTF data pool");
 if(id==1613889723u&&!xx_rt_wcscmp(r->name,L"width_8pixels"))return xx_data_struct_record_set_comment(r,L"Encoded dimension in 8-pixel units");
 if(id==1613889723u&&!xx_rt_wcscmp(r->name,L"height_8pixels"))return xx_data_struct_record_set_comment(r,L"Encoded dimension in 8-pixel units");
 if(id==1613889724u&&!xx_rt_wcscmp(r->name,L"width_8pixels"))return xx_data_struct_record_set_comment(r,L"Encoded dimension in 8-pixel units");
 if(id==1613889724u&&!xx_rt_wcscmp(r->name,L"height_8pixels"))return xx_data_struct_record_set_comment(r,L"Encoded dimension in 8-pixel units");
 if(id==1613889725u&&!xx_rt_wcscmp(r->name,L"width_8pixels"))return xx_data_struct_record_set_comment(r,L"Encoded dimension in 8-pixel units");
 if(id==1613889725u&&!xx_rt_wcscmp(r->name,L"height_8pixels"))return xx_data_struct_record_set_comment(r,L"Encoded dimension in 8-pixel units");
 if(id==1613889744u&&!xx_rt_wcscmp(r->name,L"gamma_100000"))return xx_data_struct_record_set_comment(r,L"Fixed-point value scaled by 100000");
 if(id==1613889745u&&!xx_rt_wcscmp(r->name,L"white_x_100000"))return xx_data_struct_record_set_comment(r,L"Fixed-point value scaled by 100000");
 if(id==1613889745u&&!xx_rt_wcscmp(r->name,L"white_y_100000"))return xx_data_struct_record_set_comment(r,L"Fixed-point value scaled by 100000");
 if(id==1613889745u&&!xx_rt_wcscmp(r->name,L"red_x_100000"))return xx_data_struct_record_set_comment(r,L"Fixed-point value scaled by 100000");
 if(id==1613889745u&&!xx_rt_wcscmp(r->name,L"red_y_100000"))return xx_data_struct_record_set_comment(r,L"Fixed-point value scaled by 100000");
 if(id==1613889745u&&!xx_rt_wcscmp(r->name,L"green_x_100000"))return xx_data_struct_record_set_comment(r,L"Fixed-point value scaled by 100000");
 if(id==1613889745u&&!xx_rt_wcscmp(r->name,L"green_y_100000"))return xx_data_struct_record_set_comment(r,L"Fixed-point value scaled by 100000");
 if(id==1613889745u&&!xx_rt_wcscmp(r->name,L"blue_x_100000"))return xx_data_struct_record_set_comment(r,L"Fixed-point value scaled by 100000");
 if(id==1613889745u&&!xx_rt_wcscmp(r->name,L"blue_y_100000"))return xx_data_struct_record_set_comment(r,L"Fixed-point value scaled by 100000");
 if(id==1613889759u&&!xx_rt_wcscmp(r->name,L"duration_ms"))return xx_data_struct_record_set_comment(r,L"Stream-relative time in milliseconds");
 if(id==1613889759u&&!xx_rt_wcscmp(r->name,L"preroll_ms"))return xx_data_struct_record_set_comment(r,L"Stream-relative time in milliseconds");
 if(id==1613889764u&&!xx_rt_wcscmp(r->name,L"start_time_ms"))return xx_data_struct_record_set_comment(r,L"Stream-relative time in milliseconds");
 if(id==1613889764u&&!xx_rt_wcscmp(r->name,L"preroll_ms"))return xx_data_struct_record_set_comment(r,L"Stream-relative time in milliseconds");
 if(id==1613889764u&&!xx_rt_wcscmp(r->name,L"duration_ms"))return xx_data_struct_record_set_comment(r,L"Stream-relative time in milliseconds");
 if(id==1613889768u&&!xx_rt_wcscmp(r->name,L"frame_rate_fixed"))return xx_data_struct_record_set_comment(r,L"Unsigned 16.16 fixed-point value");
 if(id==1613889771u&&!xx_rt_wcscmp(r->name,L"timestamp_ms"))return xx_data_struct_record_set_comment(r,L"Stream-relative time in milliseconds");
 if(id==1613889773u&&!xx_rt_wcscmp(r->name,L"timestamp_ms"))return xx_data_struct_record_set_comment(r,L"Stream-relative time in milliseconds");
 if(id==1613889775u&&!xx_rt_wcscmp(r->name,L"scr_marker_bits"))return xx_data_struct_record_set_comment(r,L"Packed MPEG field; marker, reserved and data bits preserved");
 if(id==1613889775u&&!xx_rt_wcscmp(r->name,L"mux_rate_marker_bits"))return xx_data_struct_record_set_comment(r,L"Packed MPEG field; marker, reserved and data bits preserved");
 if(id==1613889776u&&!xx_rt_wcscmp(r->name,L"scr_base_extension_marker_bits"))return xx_data_struct_record_set_comment(r,L"Packed MPEG field; marker, reserved and data bits preserved");
 if(id==1613889776u&&!xx_rt_wcscmp(r->name,L"mux_rate_marker_bits"))return xx_data_struct_record_set_comment(r,L"Packed MPEG field; marker, reserved and data bits preserved");
 if(id==1613889778u&&!xx_rt_wcscmp(r->name,L"timestamp_flags"))return xx_data_struct_record_set_comment(r,L"Packed MPEG field; marker, reserved and data bits preserved");
 if(id==1613889779u&&!xx_rt_wcscmp(r->name,L"tag_high_and_marker"))return xx_data_struct_record_set_comment(r,L"Packed MPEG field; marker, reserved and data bits preserved");
 if(id==1613889779u&&!xx_rt_wcscmp(r->name,L"middle_and_marker"))return xx_data_struct_record_set_comment(r,L"Packed MPEG field; marker, reserved and data bits preserved");
 if(id==1613889779u&&!xx_rt_wcscmp(r->name,L"low_and_marker"))return xx_data_struct_record_set_comment(r,L"Packed MPEG field; marker, reserved and data bits preserved");
 if(id==1613889781u&&!xx_rt_wcscmp(r->name,L"marker"))return xx_data_struct_record_set_comment(r,L"Packed MPEG field; marker, reserved and data bits preserved");
 if(id==1613889782u&&!xx_rt_wcscmp(r->name,L"rate_bound_marker_bits"))return xx_data_struct_record_set_comment(r,L"Packed MPEG field; marker, reserved and data bits preserved");
 if(id==1613889782u&&!xx_rt_wcscmp(r->name,L"audio_bound_flags"))return xx_data_struct_record_set_comment(r,L"Packed MPEG field; marker, reserved and data bits preserved");
 if(id==1613889782u&&!xx_rt_wcscmp(r->name,L"video_bound_flags"))return xx_data_struct_record_set_comment(r,L"Packed MPEG field; marker, reserved and data bits preserved");
 if(id==1613889784u&&!xx_rt_wcscmp(r->name,L"reserved_marker"))return xx_data_struct_record_set_comment(r,L"Packed MPEG field; marker, reserved and data bits preserved");
 if(id==1613889788u&&!xx_rt_wcscmp(r->name,L"flags_pid"))return xx_data_struct_record_set_comment(r,L"Packed transport field; flags, reserved bits and encoded values preserved");
 if(id==1613889788u&&!xx_rt_wcscmp(r->name,L"scrambling_adaptation_counter"))return xx_data_struct_record_set_comment(r,L"Packed transport field; flags, reserved bits and encoded values preserved");
 if(id==1613889790u&&!xx_rt_wcscmp(r->name,L"flags"))return xx_data_struct_record_set_comment(r,L"Packed transport field; flags, reserved bits and encoded values preserved");
 if(id==1613889791u&&!xx_rt_wcscmp(r->name,L"base_low_reserved_extension_high"))return xx_data_struct_record_set_comment(r,L"Packed transport field; flags, reserved bits and encoded values preserved");
 if(id==1613889795u&&!xx_rt_wcscmp(r->name,L"flags_section_length"))return xx_data_struct_record_set_comment(r,L"Packed transport field; flags, reserved bits and encoded values preserved");
 if(id==1613889795u&&!xx_rt_wcscmp(r->name,L"version_current_next"))return xx_data_struct_record_set_comment(r,L"Packed transport field; flags, reserved bits and encoded values preserved");
 if(id==1613889796u&&!xx_rt_wcscmp(r->name,L"reserved_pid"))return xx_data_struct_record_set_comment(r,L"Packed transport field; flags, reserved bits and encoded values preserved");
 if(id==1613889797u&&!xx_rt_wcscmp(r->name,L"reserved_pcr_pid"))return xx_data_struct_record_set_comment(r,L"Packed transport field; flags, reserved bits and encoded values preserved");
 if(id==1613889797u&&!xx_rt_wcscmp(r->name,L"reserved_program_info_length"))return xx_data_struct_record_set_comment(r,L"Packed transport field; flags, reserved bits and encoded values preserved");
 if(id==1613889798u&&!xx_rt_wcscmp(r->name,L"reserved_elementary_pid"))return xx_data_struct_record_set_comment(r,L"Packed transport field; flags, reserved bits and encoded values preserved");
 if(id==1613889798u&&!xx_rt_wcscmp(r->name,L"reserved_info_length"))return xx_data_struct_record_set_comment(r,L"Packed transport field; flags, reserved bits and encoded values preserved");
 if(id==1613889800u&&!xx_rt_wcscmp(r->name,L"eit_flags"))return xx_data_struct_record_set_comment(r,L"Packed transport field; flags, reserved bits and encoded values preserved");
 if(id==1613889800u&&!xx_rt_wcscmp(r->name,L"running_free_ca_descriptor_length"))return xx_data_struct_record_set_comment(r,L"Packed transport field; flags, reserved bits and encoded values preserved");
 if(id==1613889549u&&!xx_rt_wcscmp(r->name,L"palette_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this EMR_EOF record");
 if(id==1613889537u&&!xx_rt_wcscmp(r->name,L"description_chars"))return xx_data_struct_record_set_comment(r,L"UTF-16 code units, including terminators");
 if(id==1613889550u&&!xx_rt_wcscmp(r->name,L"units_per_inch"))return xx_data_struct_record_set_comment(r,L"Metafile coordinate units per inch");
 if(id==1613889610u&&!xx_rt_wcscmp(r->name,L"start_angle"))return xx_data_struct_record_set_comment(r,L"Angle in 1/16 degree units");
 if(id==1613889610u&&!xx_rt_wcscmp(r->name,L"span_angle"))return xx_data_struct_record_set_comment(r,L"Angle in 1/16 degree units");
 if(id==1613889609u&&!xx_rt_wcscmp(r->name,L"x_rounding"))return xx_data_struct_record_set_comment(r,L"Horizontal rounding percentage");
 if(id==1613889609u&&!xx_rt_wcscmp(r->name,L"y_rounding"))return xx_data_struct_record_set_comment(r,L"Vertical rounding percentage");
 if(id==1613889622u&&!xx_rt_wcscmp(r->name,L"pointer_array_bytes"))return xx_data_struct_record_set_comment(r,L"Serialized pointer-array byte size, including its terminating null pointer");
 if(id==1613889624u&&!xx_rt_wcscmp(r->name,L"picture_size"))return xx_data_struct_record_set_comment(r,L"Legacy informational size; may be zero for PICT v2");
 if(id==1613889626u&&!xx_rt_wcscmp(r->name,L"row_bytes_and_flag"))return xx_data_struct_record_set_comment(r,L"Bit 15 marks PixMap; bits 0..14 are bytes per decoded row");
 if(id==1613889631u&&!xx_rt_wcscmp(r->name,L"width_words_minus_one"))return xx_data_struct_record_set_comment(r,L"Words per image row minus one; each word is 32 bits");
 if(id==1613889631u&&!xx_rt_wcscmp(r->name,L"height_minus_one"))return xx_data_struct_record_set_comment(r,L"Image rows minus one");
 if(id==1613889632u&&!xx_rt_wcscmp(r->name,L"color1"))return xx_data_struct_record_set_comment(r,L"First flashing palette color, packed as 0xBBGGRR00");
 if(id==1613889632u&&!xx_rt_wcscmp(r->name,L"color2"))return xx_data_struct_record_set_comment(r,L"Second flashing palette color, packed as 0xBBGGRR00");
 if(id==1613889692u&&!xx_rt_wcscmp(r->name,L"header_blocks"))return xx_data_struct_record_set_comment(r,L"Count of 2048-byte blocks");
 if(id==1613889692u&&!xx_rt_wcscmp(r->name,L"data_blocks"))return xx_data_struct_record_set_comment(r,L"Count of 2048-byte blocks");
 if(id==1613889693u&&!xx_rt_wcscmp(r->name,L"mux_rate_bound"))return xx_data_struct_record_set_comment(r,L"Rate in units of 50 bytes per second");
 if(id==1613889693u&&!xx_rt_wcscmp(r->name,L"std_delay_bound"))return xx_data_struct_record_set_comment(r,L"Delay in 1/90000-second units");
 if(id==1613889701u&&!xx_rt_wcscmp(r->name,L"relative_packet_blocks"))return xx_data_struct_record_set_comment(r,L"Data-relative packet position in 2048-byte blocks");
 if(id==1613889701u&&!xx_rt_wcscmp(r->name,L"index_reference_picture_blocks"))return xx_data_struct_record_set_comment(r,L"Packed entry index and reference-picture size in 2048-byte blocks");
 if(id==1613889702u&&!xx_rt_wcscmp(r->name,L"payload_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset from this chunk base plus 8");
 if(id==1613889702u&&!xx_rt_wcscmp(r->name,L"data_size"))return xx_data_struct_record_set_comment(r,L"Chunk bytes excluding its first 8 bytes");
 if(id==1613889702u&&!xx_rt_wcscmp(r->name,L"frame_time"))return xx_data_struct_record_set_comment(r,L"Frame time in the accompanying stream frame-rate units");
 if(id==1613889702u&&!xx_rt_wcscmp(r->name,L"frame_rate"))return xx_data_struct_record_set_comment(r,L"Stream frame-rate value");
 if(id==1613889721u&&!xx_rt_wcscmp(r->name,L"microsecond_rate"))return xx_data_struct_record_set_comment(r,L"Frame duration is this microsecond rate multiplied by rate_divisor");
 if(id==1613889721u&&!xx_rt_wcscmp(r->name,L"rate_divisor"))return xx_data_struct_record_set_comment(r,L"Multiplicative factor used with microsecond_rate");
 if(id==1613889733u&&!xx_rt_wcscmp(r->name,L"word_offset_and_flags"))return xx_data_struct_record_set_comment(r,L"Low 30 bits hold the offset in 16-bit words; top two bits are flags");
 if(id==1613889738u&&!xx_rt_wcscmp(r->name,L"nominal_play_time_ticks"))return xx_data_struct_record_set_comment(r,L"Duration in ticks at ticks_per_second");
 if(id==1613889752u&&!xx_rt_wcscmp(r->name,L"frame_duration"))return xx_data_struct_record_set_comment(r,L"Positive: milliseconds; negative: magnitude in 1/100000 second units; zero: 10 fps");
 if(id==1613889791u&&!xx_rt_wcscmp(r->name,L"base_high"))return xx_data_struct_record_set_comment(r,L"Upper 32 bits of the 33-bit 90 kHz clock base");
 if(id==1613889791u&&!xx_rt_wcscmp(r->name,L"extension_low"))return xx_data_struct_record_set_comment(r,L"Low 8 bits of the 9-bit 27 MHz clock extension");
 if(id==1613889794u&&!xx_rt_wcscmp(r->name,L"pointer_bytes"))return xx_data_struct_record_set_comment(r,L"Bytes to skip before the next PSI section");
 if(id==1613889586u&&!xx_rt_wcscmp(r->name,L"end_index"))return xx_data_struct_record_set_comment(r,L"Exclusive ending palette index");
 return true;
}
const sx_family sx_nextmedia_family={sx_nextmedia_supports,sx_nextmedia_build,sx_nextmedia_layouts,SX_COUNT(sx_nextmedia_layouts),sx_nextmedia_comment};
