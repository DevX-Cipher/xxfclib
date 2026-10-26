/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The binaryresources schema family: what its family unit (xx_format_schema_binaryresources.c)
 * and its formats' data files share. Formats: Genus pcxLib picture libraries; Torque DTS shapes; Nokia OTA bitmap; SSBOB slideshow; Photodex named-resource package; EVD map images; QNX Neutrino boot images; VxWorks images; IBM Mwave DSP distribution files; U-Boot environment; Android logical partitions (super); Sony TCJN images. */
#ifndef XX_FORMAT_SCHEMA_BINARYRESOURCES_H
#define XX_FORMAT_SCHEMA_BINARYRESOURCES_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxbrs_ota_bitmap_short;
extern const sx_layout sxbrs_ota_bitmap_extended;
extern const sx_layout sxbrs_lp_geometry;
extern const sx_layout sxbrs_lp_header;
extern const sx_layout sxbrs_lp_header_extended;
extern const sx_layout sxbrs_lp_partition;
extern const sx_layout sxbrs_lp_extent;
extern const sx_layout sxbrs_lp_group;
extern const sx_layout sxbrs_lp_block_device;
extern const sx_layout sxbrs_dts_header;
extern const sx_layout sxbrs_dts_counts;
extern const sx_layout sxbrs_dts_bounds;
extern const sx_layout sxbrs_dts_node;
extern const sx_layout sxbrs_dts_subshape_first;
extern const sx_layout sxbrs_dts_subshape_count;
extern const sx_layout sxbrs_dts_rotation;
extern const sx_layout sxbrs_dts_translation;
extern const sx_layout sxbrs_dts_guard32;
extern const sx_layout sxbrs_dts_guard16;
extern const sx_layout sxbrs_dts_guard8;
extern const sx_layout sxbrs_dts_name_byte;
extern const sx_layout sxbrs_dts_footer;
extern const sx_layout sxbrs_vxworks_symbol_le;
extern const sx_layout sxbrs_vxworks_symbol_be;
extern const sx_layout sxbrs_mwave_header;
extern const sx_layout sxbrs_pcxlib_header;
extern const sx_layout sxbrs_pcxlib_member;
extern const sx_layout sxbrs_qnx_startup_prefix;
extern const sx_layout sxbrs_qnx_startup_header;
extern const sx_layout sxbrs_qnx_block;
extern const sx_layout sxbrs_uboot_env_le;
extern const sx_layout sxbrs_uboot_redundant_env_le;
extern const sx_layout sxbrs_uboot_env_be;
extern const sx_layout sxbrs_uboot_redundant_env_be;
extern const sx_layout sxbrs_uboot_key_byte;
extern const sx_layout sxbrs_uboot_value_byte;
extern const sx_layout sxbrs_uboot_separator;
extern const sx_layout sxbrs_uboot_terminator;
extern const sx_layout sxbrs_fss_header;
extern const sx_layout sxbrs_fss_record;
extern const sx_layout sxbrs_fss_end;
extern const sx_layout sxbrs_px_header;
extern const sx_layout sxbrs_px_block;
extern const sx_layout sxbrs_px_count;
extern const sx_layout sxbrs_px_record;
extern const sx_layout sxbrs_evd_header;
extern const sx_layout sxbrs_evd_record;
extern const sx_layout sxbrs_sony_image_header;
extern const sx_layout sxbrs_sony_image_zlib_marker;
extern const sx_layout sxbrs_resource_zlib_header;
extern const sx_layout sxbrs_resource_zlib_trailer;
uint64_t sxbrs_num(sx_context*c,int64_t at,unsigned width,bool be);
uint64_t sxbrs_width(const sx_layout*l);
bool sxbrs_take(sx_context*c,const sx_layout*l,int64_t*at,int64_t end,uint64_t count);
bool sxbrs_add(sx_context*c,const sx_layout*l,int64_t at);
bool sxbrs_skip(int64_t*at,int64_t end,uint64_t n);
bool sxbrs_eq(sx_context*c,int64_t at,const char*text,size_t n);

/* Per-format walkers, called by the family's build. */
bool sx_pcxlib_build(sx_context *c);  /* image/pcxlib/xx_pcxlib_data.c */
bool sx_torque_dts_build(sx_context *c);  /* image/torque_dts/xx_torque_dts_data.c */
bool sx_nokia_ota_bitmap_build(sx_context *c);  /* image/nokia_ota_bitmap/xx_nokia_ota_bitmap_data.c */
bool sx_fss_build(sx_context *c);  /* image/fss/xx_fss_data.c */
bool sx_px_build(sx_context *c);  /* image/px/xx_px_data.c */
bool sx_evd_build(sx_context *c);  /* image/evd/xx_evd_data.c */
bool sx_qnxbase_build(sx_context *c);  /* firmware/qnxbase/xx_qnxbase_data.c */
bool sx_vxworks_build(sx_context *c);  /* firmware/vxworks/xx_vxworks_data.c */
bool sx_mwave_build(sx_context *c);  /* firmware/mwave/xx_mwave_data.c */
bool sx_uboot_build(sx_context *c);  /* firmware/uboot/xx_uboot_data.c */
bool sx_android_lp_build(sx_context *c);  /* firmware/android_lp/xx_android_lp_data.c */
bool sx_sony_image_build(sx_context *c);  /* firmware/sony_image/xx_sony_image_data.c */

#endif
