/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The nextmedia schema family: what its family unit (xx_format_schema_nextmedia.c)
 * and its formats' data files share. Formats: EMF; WMF; GIMP XCF; PHOTOSHOP ABR; QT QPICTURE; BPG IMAGE; PAINTSHOP PSP; PHOTOSHOP PAT; AMIGA DISKOBJECT; WBMP IMAGE; PALM BITMAP; APPLE PICT; WORDPERFECT WPG; KHOROS VIFF; RISC OS sprite file (filetype &FF9); WINDOWS ANI; Format facts; SONY PAMF; CRI USM; MPEG TRANSPORT STREAM; MPEG PROGRAM STREAM; REALMEDIA RM; INTERPLAY MVE; WESTWOOD VQA; MNG ANIMATION; SCUMMVM DXA. */
#ifndef XX_FORMAT_SCHEMA_NEXTMEDIA_H
#define XX_FORMAT_SCHEMA_NEXTMEDIA_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

typedef struct sxnx_view {sx_context *c;uint8_t *p;size_t n;unsigned work;}sxnx_view;

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxnx_emf_header;
extern const sx_layout sxnx_emf_record;
extern const sx_layout sxnx_emf_rectangle;
extern const sx_layout sxnx_emf_point;
extern const sx_layout sxnx_emf_poly_count;
extern const sx_layout sxnx_emf_mode;
extern const sx_layout sxnx_emf_flags;
extern const sx_layout sxnx_emf_color;
extern const sx_layout sxnx_emf_restore;
extern const sx_layout sxnx_emf_handle;
extern const sx_layout sxnx_emf_pen;
extern const sx_layout sxnx_emf_brush;
extern const sx_layout sxnx_emf_eof;
extern const sx_layout sxnx_wmf_placeable;
extern const sx_layout sxnx_wmf_header;
extern const sx_layout sxnx_wmf_record;
extern const sx_layout sxnx_wmf_point;
extern const sx_layout sxnx_wmf_coordinate_pair;
extern const sx_layout sxnx_wmf_rectangle;
extern const sx_layout sxnx_wmf_poly_count;
extern const sx_layout sxnx_wmf_mode;
extern const sx_layout sxnx_wmf_restore;
extern const sx_layout sxnx_wmf_handle;
extern const sx_layout sxnx_wmf_color;
extern const sx_layout sxnx_wmf_pen;
extern const sx_layout sxnx_wmf_brush;
extern const sx_layout sxnx_wbmp_header;
extern const sx_layout sxnx_wbmp_width_1;
extern const sx_layout sxnx_wbmp_height_1;
extern const sx_layout sxnx_wbmp_width_2;
extern const sx_layout sxnx_wbmp_height_2;
extern const sx_layout sxnx_palm_bitmap_header;
extern const sx_layout sxnx_palm_palette_header;
extern const sx_layout sxnx_palm_palette_entry;
extern const sx_layout sxnx_palm_compressed_header;
extern const sx_layout sxnx_viff_header_le;
extern const sx_layout sxnx_viff_header_be;
extern const sx_layout sxnx_viff_header_dec;
extern const sx_layout sxnx_abr_header;
extern const sx_layout sxnx_abr_record;
extern const sx_layout sxnx_abr_sample_prefix;
extern const sx_layout sxnx_abr_name_header;
extern const sx_layout sxnx_abr_sample_geometry;
extern const sx_layout sxnx_abr_row_size;
extern const sx_layout sxnx_wpg_header;
extern const sx_layout sxnx_wpg_record_short;
extern const sx_layout sxnx_wpg_record_medium;
extern const sx_layout sxnx_wpg_record_long;
extern const sx_layout sxnx_wpg_start;
extern const sx_layout sxnx_wpg_palette;
extern const sx_layout sxnx_rgb_palette_entry;
extern const sx_layout sxnx_wpg_bitmap;
extern const sx_layout sxnx_psp_header;
extern const sx_layout sxnx_psp_block;
extern const sx_layout sxnx_psp_image;
extern const sx_layout sxnx_psp_layer;
extern const sx_layout sxnx_psp_channel;
extern const sx_layout sxnx_pat_header;
extern const sx_layout sxnx_pat_pattern;
extern const sx_layout sxnx_pat_id_length;
extern const sx_layout sxnx_pat_vma;
extern const sx_layout sxnx_pat_slot;
extern const sx_layout sxnx_pat_channel;
extern const sx_layout sxnx_pat_row_size;
extern const sx_layout sxnx_pat_hierarchy;
extern const sx_layout sxnx_pat_empty_descriptor;
extern const sx_layout sxnx_qpic_header;
extern const sx_layout sxnx_qpic_record;
extern const sx_layout sxnx_qpic_record_long;
extern const sx_layout sxnx_qpic_point;
extern const sx_layout sxnx_qpic_rectangle;
extern const sx_layout sxnx_qpic_line;
extern const sx_layout sxnx_qpic_rounding;
extern const sx_layout sxnx_qpic_angles;
extern const sx_layout sxnx_qpic_point_count;
extern const sx_layout sxnx_qpic_fill_rule;
extern const sx_layout sxnx_qpic_mode;
extern const sx_layout sxnx_qpic_flags;
extern const sx_layout sxnx_qpic_raster_operation;
extern const sx_layout sxnx_qpic_boolean;
extern const sx_layout sxnx_qpic_opacity;
extern const sx_layout sxnx_icon_diskobject;
extern const sx_layout sxnx_icon_drawer;
extern const sx_layout sxnx_icon_image;
extern const sx_layout sxnx_icon_string;
extern const sx_layout sxnx_icon_tooltypes;
extern const sx_layout sxnx_icon_new_drawer;
extern const sx_layout sxnx_pict_header;
extern const sx_layout sxnx_pict_clip;
extern const sx_layout sxnx_pict_directbits;
extern const sx_layout sxnx_pict_row_short;
extern const sx_layout sxnx_pict_row_long;
extern const sx_layout sxnx_pict_end;
extern const sx_layout sxnx_sprite_area;
extern const sx_layout sxnx_sprite_header;
extern const sx_layout sxnx_sprite_palette;
extern const sx_layout sxnx_thumb_header_old;
extern const sx_layout sxnx_thumb_header_28;
extern const sx_layout sxnx_thumb_header_new;
extern const sx_layout sxnx_thumb_entry_20;
extern const sx_layout sxnx_thumb_entry_21;
extern const sx_layout sxnx_thumb_entry_new;
extern const sx_layout sxnx_xcf_header;
extern const sx_layout sxnx_xcf_property;
extern const sx_layout sxnx_xcf_string;
extern const sx_layout sxnx_xcf_offset;
extern const sx_layout sxnx_xcf_layer;
extern const sx_layout sxnx_xcf_channel;
extern const sx_layout sxnx_xcf_hierarchy;
extern const sx_layout sxnx_xcf_level;
extern const sx_layout sxnx_xcf_color_count;
extern const sx_layout sxnx_xcf_opacity;
extern const sx_layout sxnx_xcf_mode;
extern const sx_layout sxnx_xcf_boolean;
extern const sx_layout sxnx_xcf_geometry_offset;
extern const sx_layout sxnx_xcf_compression;
extern const sx_layout sxnx_xcf_guide;
extern const sx_layout sxnx_xcf_resolution;
extern const sx_layout sxnx_xcf_tattoo;
extern const sx_layout sxnx_xcf_unit;
extern const sx_layout sxnx_xcf_parasite;
extern const sx_layout sxnx_xcf_sample_point;
extern const sx_layout sxnx_bpg_header;
extern const sx_layout sxnx_bpg_width_1;
extern const sx_layout sxnx_bpg_width_2;
extern const sx_layout sxnx_bpg_width_3;
extern const sx_layout sxnx_bpg_height_1;
extern const sx_layout sxnx_bpg_height_2;
extern const sx_layout sxnx_bpg_height_3;
extern const sx_layout sxnx_bpg_picture_bytes_1;
extern const sx_layout sxnx_bpg_picture_bytes_2;
extern const sx_layout sxnx_bpg_picture_bytes_3;
extern const sx_layout sxnx_bpg_picture_bytes_4;
extern const sx_layout sxnx_bpg_extension_bytes_1;
extern const sx_layout sxnx_bpg_extension_bytes_2;
extern const sx_layout sxnx_bpg_extension_bytes_3;
extern const sx_layout sxnx_bpg_extension_tag_1;
extern const sx_layout sxnx_bpg_extension_tag_2;
extern const sx_layout sxnx_bpg_extension_tag_3;
extern const sx_layout sxnx_bpg_extension_tag_4;
extern const sx_layout sxnx_bpg_extension_tag_5;
extern const sx_layout sxnx_bpg_extension_data_bytes_1;
extern const sx_layout sxnx_bpg_extension_data_bytes_2;
extern const sx_layout sxnx_bpg_extension_data_bytes_3;
extern const sx_layout sxnx_bpg_hevc_header_bytes_1;
extern const sx_layout sxnx_bpg_nal;
extern const sx_layout sxnx_ani_riff;
extern const sx_layout sxnx_ani_chunk;
extern const sx_layout sxnx_ani_list;
extern const sx_layout sxnx_ani_header;
extern const sx_layout sxnx_ani_rate;
extern const sx_layout sxnx_ani_sequence;
extern const sx_layout sxnx_ani_icon_header;
extern const sx_layout sxnx_ani_icon_entry;
extern const sx_layout sxnx_ani_cursor_entry;
extern const sx_layout sxnx_pamf_header;
extern const sx_layout sxnx_pamf_sequence;
extern const sx_layout sxnx_pamf_period;
extern const sx_layout sxnx_pamf_group;
extern const sx_layout sxnx_pamf_stream;
extern const sx_layout sxnx_pamf_avc;
extern const sx_layout sxnx_pamf_m2v;
extern const sx_layout sxnx_pamf_audio;
extern const sx_layout sxnx_pamf_userdata;
extern const sx_layout sxnx_pamf_entry_point;
extern const sx_layout sxnx_usm_chunk;
extern const sx_layout sxnx_usm_utf_header;
extern const sx_layout sxnx_usm_utf_column;
extern const sx_layout sxnx_usm_utf_value_u8;
extern const sx_layout sxnx_usm_utf_value_i8;
extern const sx_layout sxnx_usm_utf_value_u16;
extern const sx_layout sxnx_usm_utf_value_i16;
extern const sx_layout sxnx_usm_utf_value_u32;
extern const sx_layout sxnx_usm_utf_value_i32;
extern const sx_layout sxnx_usm_utf_value_u64;
extern const sx_layout sxnx_usm_utf_value_i64;
extern const sx_layout sxnx_usm_utf_value_f32;
extern const sx_layout sxnx_usm_utf_value_f64;
extern const sx_layout sxnx_usm_utf_string;
extern const sx_layout sxnx_usm_utf_data;
extern const sx_layout sxnx_usm_utf_guid;
extern const sx_layout sxnx_mve_header;
extern const sx_layout sxnx_mve_chunk;
extern const sx_layout sxnx_mve_opcode;
extern const sx_layout sxnx_mve_timer;
extern const sx_layout sxnx_mve_audio_init;
extern const sx_layout sxnx_mve_video_init_0;
extern const sx_layout sxnx_mve_video_init_1;
extern const sx_layout sxnx_mve_video_init_2;
extern const sx_layout sxnx_mve_send_buffer;
extern const sx_layout sxnx_mve_audio_frame;
extern const sx_layout sxnx_mve_video_mode;
extern const sx_layout sxnx_mve_palette;
extern const sx_layout sxnx_vqa_form;
extern const sx_layout sxnx_vqa_chunk;
extern const sx_layout sxnx_vqa_header;
extern const sx_layout sxnx_vqa_frame_index;
extern const sx_layout sxnx_vqa_sound;
extern const sx_layout sxnx_mng_signature;
extern const sx_layout sxnx_mng_chunk;
extern const sx_layout sxnx_mng_crc;
extern const sx_layout sxnx_mng_header;
extern const sx_layout sxnx_mng_png_header;
extern const sx_layout sxnx_mng_gray;
extern const sx_layout sxnx_mng_rgb;
extern const sx_layout sxnx_mng_palette_index;
extern const sx_layout sxnx_mng_alpha;
extern const sx_layout sxnx_mng_gamma;
extern const sx_layout sxnx_mng_chromaticity;
extern const sx_layout sxnx_mng_srgb;
extern const sx_layout sxnx_mng_physical;
extern const sx_layout sxnx_mng_term;
extern const sx_layout sxnx_mng_fram;
extern const sx_layout sxnx_mng_defi;
extern const sx_layout sxnx_mng_back_flag;
extern const sx_layout sxnx_dxa_header;
extern const sx_layout sxnx_dxa_wave_size;
extern const sx_layout sxnx_dxa_riff;
extern const sx_layout sxnx_dxa_tag;
extern const sx_layout sxnx_dxa_frame;
extern const sx_layout sxnx_rmf_header;
extern const sx_layout sxnx_rm_object;
extern const sx_layout sxnx_rm_prop;
extern const sx_layout sxnx_rm_title_length;
extern const sx_layout sxnx_rm_author_length;
extern const sx_layout sxnx_rm_copyright_length;
extern const sx_layout sxnx_rm_comment_length;
extern const sx_layout sxnx_rm_mdpr;
extern const sx_layout sxnx_rm_name_length;
extern const sx_layout sxnx_rm_mime_length;
extern const sx_layout sxnx_rm_specific_length;
extern const sx_layout sxnx_rm_video;
extern const sx_layout sxnx_rm_audio_prefix;
extern const sx_layout sxnx_rm_data;
extern const sx_layout sxnx_rm_packet;
extern const sx_layout sxnx_rm_index;
extern const sx_layout sxnx_rm_index_entry;
extern const sx_layout sxnx_mpeg_start_code;
extern const sx_layout sxnx_mpeg_pack1;
extern const sx_layout sxnx_mpeg_pack2;
extern const sx_layout sxnx_mpeg_packet;
extern const sx_layout sxnx_mpeg_system;
extern const sx_layout sxnx_mpeg_system_stream;
extern const sx_layout sxnx_mpeg_map;
extern const sx_layout sxnx_mpeg_map_length;
extern const sx_layout sxnx_mpeg_map_stream;
extern const sx_layout sxnx_mpeg_crc;
extern const sx_layout sxnx_ts_header;
extern const sx_layout sxnx_ts_adaptation_size;
extern const sx_layout sxnx_ts_adaptation_flags;
extern const sx_layout sxnx_ts_clock;
extern const sx_layout sxnx_ts_splice;
extern const sx_layout sxnx_ts_private_size;
extern const sx_layout sxnx_ts_pointer;
extern const sx_layout sxnx_ts_section;
extern const sx_layout sxnx_ts_pat_program;
extern const sx_layout sxnx_ts_pmt;
extern const sx_layout sxnx_ts_pmt_stream;
extern const sx_layout sxnx_ts_sdt;
extern const sx_layout sxnx_ts_sdt_service;
extern const sx_layout sxnx_ts_descriptor;
bool sxnx_need(sxnx_view *v,size_t at,uint64_t n,size_t end);
uint16_t sxnx_u16(const uint8_t*p,bool be);
uint32_t sxnx_u32(const uint8_t*p,bool be);
bool sxnx_row(sxnx_view *v,const sx_layout*l,size_t at,size_t end);
bool sxnx_table(sxnx_view*v,const sx_layout*l,size_t at,uint64_t count,size_t end);
bool sxnx_varuint(sxnx_view*v,size_t*at,size_t end,uint32_t*out,unsigned*width);
bool sxnx_pes(sxnx_view*v,size_t p,size_t end);

/* Per-format walkers, called by the family's build. */
bool sx_emf_build(sxnx_view*v);  /* image/emf/xx_emf_data.c */
bool sx_wmf_build(sxnx_view*v);  /* image/wmf/xx_wmf_data.c */
bool sx_gimp_xcf_build(sxnx_view*v);  /* image/gimp_xcf/xx_gimp_xcf_data.c */
bool sx_photoshop_abr_build(sxnx_view*v);  /* image/photoshop_abr/xx_photoshop_abr_data.c */
bool sx_qt_qpicture_build(sxnx_view*v);  /* image/qt_qpicture/xx_qt_qpicture_data.c */
bool sx_bpg_image_build(sxnx_view*v);  /* image/bpg_image/xx_bpg_image_data.c */
bool sx_paintshop_psp_build(sxnx_view*v);  /* image/paintshop_psp/xx_paintshop_psp_data.c */
bool sx_photoshop_pat_build(sxnx_view*v);  /* image/photoshop_pat/xx_photoshop_pat_data.c */
bool sx_amiga_diskobject_build(sxnx_view*v);  /* image/amiga_diskobject/xx_amiga_diskobject_data.c */
bool sx_wbmp_image_build(sxnx_view*v);  /* image/wbmp_image/xx_wbmp_image_data.c */
bool sx_palm_bitmap_build(sxnx_view*v);  /* image/palm_bitmap/xx_palm_bitmap_data.c */
bool sx_apple_pict_build(sxnx_view*v);  /* image/apple_pict/xx_apple_pict_data.c */
bool sx_wordperfect_wpg_build(sxnx_view*v);  /* image/wordperfect_wpg/xx_wordperfect_wpg_data.c */
bool sx_khoros_viff_build(sxnx_view*v);  /* image/khoros_viff/xx_khoros_viff_data.c */
bool sx_risc_os_sprite_build(sxnx_view*v);  /* image/risc_os_sprite/xx_risc_os_sprite_data.c */
bool sx_windows_ani_build(sxnx_view*v);  /* image/windows_ani/xx_windows_ani_data.c */
bool sx_windows_thumbnail_cache_build(sxnx_view*v);  /* image/windows_thumbnail_cache/xx_windows_thumbnail_cache_data.c */
bool sx_sony_pamf_build(sxnx_view*v);  /* video/sony_pamf/xx_sony_pamf_data.c */
bool sx_cri_usm_build(sxnx_view*v);  /* video/cri_usm/xx_cri_usm_data.c */
bool sx_mpeg_transport_stream_build(sxnx_view*v);  /* video/mpeg_transport_stream/xx_mpeg_transport_stream_data.c */
bool sx_mpeg_program_stream_build(sxnx_view*v);  /* video/mpeg_program_stream/xx_mpeg_program_stream_data.c */
bool sx_realmedia_rm_build(sxnx_view*v);  /* video/realmedia_rm/xx_realmedia_rm_data.c */
bool sx_interplay_mve_build(sxnx_view*v);  /* video/interplay_mve/xx_interplay_mve_data.c */
bool sx_westwood_vqa_build(sxnx_view*v);  /* video/westwood_vqa/xx_westwood_vqa_data.c */
bool sx_mng_animation_build(sxnx_view*v);  /* video/mng_animation/xx_mng_animation_data.c */
bool sx_scummvm_dxa_build(sxnx_view*v);  /* video/scummvm_dxa/xx_scummvm_dxa_data.c */

#endif
