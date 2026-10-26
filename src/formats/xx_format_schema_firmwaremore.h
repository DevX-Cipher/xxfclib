/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The firmwaremore schema family: what its family unit (xx_format_schema_firmwaremore.c)
 * and its formats' data files share. Formats: ROMPAQ; DMS swapped firmware; DKBS; D-Link SHRS; D-Link MH01; AUTEL; DLKE; D-Link encrpted_img; d_link_alpha_encimg_v2; d_link_fpkg_cpkg; htc_nbh_rom_image; xiaomi_hdr1; xiaomi_hdr2; BIOS firmware; Apple C4000 GNS1 baseband firmware. */
#ifndef XX_FORMAT_SCHEMA_FIRMWAREMORE_H
#define XX_FORMAT_SCHEMA_FIRMWAREMORE_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sx_fm_rompaq_header;
extern const sx_layout sx_fm_dms_swapped_header;
extern const sx_layout sx_fm_dkbs_header;
extern const sx_layout sx_fm_shrs_header_prefix;
extern const sx_layout sx_fm_mh01_signature_header;
extern const sx_layout sx_fm_mh01_payload_header;
extern const sx_layout sx_fm_autel_header;
extern const sx_layout sx_fm_dlke_arm_header;
extern const sx_layout sx_fm_encrpted_img_header;
extern const sx_layout sx_fm_alpha_encimg_header_prefix;
extern const sx_layout sx_fm_alpha_encimg_payload_le;
extern const sx_layout sx_fm_alpha_encimg_payload_be;
extern const sx_layout sx_fm_alpha_encimg_header_suffix;
extern const sx_layout sx_fm_dlink_package_header;
extern const sx_layout sx_fm_dlink_fpkg_extra;
extern const sx_layout sx_fm_dlink_package_entry;
extern const sx_layout sx_fm_htc_nbh_header;
extern const sx_layout sx_fm_htc_nbh_block_header;
extern const sx_layout sx_fm_htc_dbh_prefix;
extern const sx_layout sx_fm_htc_dbh_section_type;
extern const sx_layout sx_fm_htc_dbh_section_offset;
extern const sx_layout sx_fm_htc_dbh_section_size;
extern const sx_layout sx_fm_htc_dbh_identity;
extern const sx_layout sx_fm_bios_far_reset_jump;
extern const sx_layout sx_fm_bios_near_reset_jump;
extern const sx_layout sx_fm_gns1_ftab_header;
extern const sx_layout sx_fm_gns1_ftab_entry;
extern const sx_layout sx_fm_gns1_segment;
extern const sx_layout sx_fm_gns1_terminator;
bool sx_fm_span(sx_context*c,int64_t p,uint64_t n);
bool sx_fm_read(sx_context*c,int64_t p,void*b,size_t n);
bool sx_fm_u32(sx_context*c,int64_t p,bool be,uint32_t*v);
bool sx_fm_table(sx_context*c,const sx_layout*l,int64_t p,int64_t z,uint64_t n);
bool sx_fm_add(sx_context*c,const sx_layout*l,int64_t p,int64_t z);
bool sx_fm_xiaomi(sx_context *c,bool hdr2);

/* Per-format walkers, called by the family's build. */
bool sx_rompaq_build(sx_context *c);  /* firmware/rompaq/xx_rompaq_data.c */
bool sx_dmsfw_build(sx_context *c);  /* firmware/dmsfw/xx_dmsfw_data.c */
bool sx_dkbs_build(sx_context *c);  /* firmware/dkbs/xx_dkbs_data.c */
bool sx_shrs_build(sx_context *c);  /* firmware/shrs/xx_shrs_data.c */
bool sx_mh01_build(sx_context *c);  /* firmware/mh01/xx_mh01_data.c */
bool sx_autel_build(sx_context *c);  /* firmware/autel/xx_autel_data.c */
bool sx_dlke_build(sx_context *c);  /* firmware/dlke/xx_dlke_data.c */
bool sx_encrpted_img_build(sx_context *c);  /* firmware/encrpted_img/xx_encrpted_img_data.c */
bool sx_d_link_alpha_encimg_v2_build(sx_context *c);  /* firmware/d_link_alpha_encimg_v2/xx_d_link_alpha_encimg_v2_data.c */
bool sx_d_link_fpkg_cpkg_build(sx_context *c);  /* firmware/d_link_fpkg_cpkg/xx_d_link_fpkg_cpkg_data.c */
bool sx_htc_nbh_rom_image_build(sx_context *c);  /* firmware/htc_nbh_rom_image/xx_htc_nbh_rom_image_data.c */
bool sx_xiaomi_hdr1_build(sx_context *c);  /* firmware/xiaomi_hdr1/xx_xiaomi_hdr1_data.c */
bool sx_xiaomi_hdr2_build(sx_context *c);  /* firmware/xiaomi_hdr2/xx_xiaomi_hdr2_data.c */
bool sx_bios_firmware_build(sx_context *c);  /* firmware/bios_firmware/xx_bios_firmware_data.c */
bool sx_gns1_build(sx_context *c);  /* firmware/gns1/xx_gns1_data.c */

#endif
