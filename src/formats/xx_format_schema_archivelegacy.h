/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The archivelegacy schema family: what its family unit (xx_format_schema_archivelegacy.c)
 * and its formats' data files share. Formats: Amiga Plus archives; Now Compress archives; AppleLink Package (ACU); CBM ARC v1/v2 254-byte records; VMARC archives (John Fisher, Rice University); TI-99/4A ARC (.ARK) archives; ZFSF archives; TRCPAK archives; ChiefLZ "Multiple" archives; IBM ZPAK archives; Ascend compressed files; CFL (version 3) archives; DPK4 archives; SWAG packets; MARC archives; HLB libraries; JAM resource archives; TWS archives; Maximus FIZ archives; EALIB archives. */
#ifndef XX_FORMAT_SCHEMA_ARCHIVELEGACY_H
#define XX_FORMAT_SCHEMA_ARCHIVELEGACY_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxag_amplus_header;
extern const sx_layout sxag_amplus_chunk;
extern const sx_layout sxag_amplus_data;
extern const sx_layout sxag_amplus_file;
extern const sx_layout sxag_nowcompress_header;
extern const sx_layout sxag_nowcompress_entry;
extern const sx_layout sxag_nowcompress_stream;
extern const sx_layout sxag_nowcompress_block;
extern const sx_layout sxag_nowcompress_stream_end;
extern const sx_layout sxag_applelink_header;
extern const sx_layout sxag_applelink_member;
extern const sx_layout sxag_arc_cbm_member;
extern const sx_layout sxag_arc_cbm_v2;
extern const sx_layout sxag_vmarc_member;
extern const sx_layout sxag_vmarc_record;
extern const sx_layout sxag_ti99_tifiles;
extern const sx_layout sxag_ti99_fiad;
extern const sx_layout sxag_ti99_record_count;
extern const sx_layout sxag_ti99_fiad_times;
extern const sx_layout sxag_ti99_entry;
extern const sx_layout sxag_ti99_catalog_end;
extern const sx_layout sxag_zfsf_header;
extern const sx_layout sxag_zfsf_group;
extern const sx_layout sxag_zfsf_entry;
extern const sx_layout sxag_trcpak_header;
extern const sx_layout sxag_trcpak_entry;
extern const sx_layout sxag_chieflz_header;
extern const sx_layout sxag_chieflz_entry;
extern const sx_layout sxag_ibmzpak_header;
extern const sx_layout sxag_ibmzpak_entry;
extern const sx_layout sxag_ibmzpak_count;
extern const sx_layout sxag_archivelegacy_dcl;
extern const sx_layout sxag_ascend_header;
extern const sx_layout sxag_cfl_header;
extern const sx_layout sxag_cfl_directory_block;
extern const sx_layout sxag_cfl_directory_size;
extern const sx_layout sxag_cfl_entry;
extern const sx_layout sxag_cfl_member_block;
extern const sx_layout sxag_dpk_header;
extern const sx_layout sxag_dpk_entry;
extern const sx_layout sxag_swagpacket_header;
extern const sx_layout sxag_swagpacket_entry;
extern const sx_layout sxag_marc_header;
extern const sx_layout sxag_marc_entry;
extern const sx_layout sxag_hlb_header;
extern const sx_layout sxag_hlb_entry;
extern const sx_layout sxag_hlb_footer;
extern const sx_layout sxag_jam_header;
extern const sx_layout sxag_jam_file_count;
extern const sx_layout sxag_jam_directory_count;
extern const sx_layout sxag_jam_file;
extern const sx_layout sxag_jam_directory;
extern const sx_layout sxag_tws_header;
extern const sx_layout sxag_tws_entry;
extern const sx_layout sxag_fiz_member;
extern const sx_layout sxag_ealib_header;
extern const sx_layout sxag_ealib_entry;
extern const sx_layout sxag_ealib_packed_size;
bool sxag_span(sx_context *c,uint64_t p,uint64_t n);
bool sxag_read(sx_context *c,uint64_t p,void *b,size_t n);
uint16_t sxag16(const uint8_t *b,bool be);
uint32_t sxag32(const uint8_t *b,bool be);
bool sxag_free(sx_context *c,uint64_t p,uint64_t n);
bool sxag_add(sx_context *c,const sx_layout *l,uint64_t p);
bool sxag_table(sx_context *c,const sx_layout *l,uint64_t p,uint64_t n);
bool sxag_fixed(sx_context *c,const sx_layout *header,const sx_layout *entry,unsigned h,unsigned field,unsigned width,bool be,uint64_t p,int extra);

/* Per-format walkers, called by the family's build. */
bool sx_amplus_build(sx_context *c);  /* archive/amplus/xx_amplus_data.c */
bool sx_nowcompress_build(sx_context *c);  /* archive/nowcompress/xx_nowcompress_data.c */
bool sx_applelink_pe_build(sx_context *c);  /* archive/applelink_pe/xx_applelink_pe_data.c */
bool sx_arc_cbm_build(sx_context *c);  /* archive/arc_cbm/xx_arc_cbm_data.c */
bool sx_vmarc_build(sx_context *c);  /* archive/vmarc/xx_vmarc_data.c */
bool sx_ti99arc_build(sx_context *c);  /* archive/ti99arc/xx_ti99arc_data.c */
bool sx_zfsf_build(sx_context *c);  /* archive/zfsf/xx_zfsf_data.c */
bool sx_trcpak_build(sx_context *c);  /* archive/trcpak/xx_trcpak_data.c */
bool sx_chieflzmulti_build(sx_context *c);  /* archive/chieflzmulti/xx_chieflzmulti_data.c */
bool sx_ibmzpak_build(sx_context *c);  /* archive/ibmzpak/xx_ibmzpak_data.c */
bool sx_ascend_build(sx_context *c);  /* archive/ascend/xx_ascend_data.c */
bool sx_cfl_build(sx_context *c);  /* archive/cfl/xx_cfl_data.c */
bool sx_dpk_build(sx_context *c);  /* archive/dpk/xx_dpk_data.c */
bool sx_swagpacket_build(sx_context *c);  /* archive/swagpacket/xx_swagpacket_data.c */
bool sx_marc_build(sx_context *c);  /* archive/marc/xx_marc_data.c */
bool sx_hlb_build(sx_context *c);  /* archive/hlb/xx_hlb_data.c */
bool sx_jam_build(sx_context *c);  /* archive/jam/xx_jam_data.c */
bool sx_tws_build(sx_context *c);  /* archive/tws/xx_tws_data.c */
bool sx_fiz_build(sx_context *c);  /* archive/fiz/xx_fiz_data.c */
bool sx_ealib_build(sx_context *c);  /* archive/ealib/xx_ealib_data.c */

#endif
