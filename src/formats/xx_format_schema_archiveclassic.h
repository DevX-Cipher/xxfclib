/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The archiveclassic schema family: what its family unit (xx_format_schema_archiveclassic.c)
 * and its formats' data files share. Formats: DTPACKED; ZLWB; ZZ; ZZZ; JGPAK; BORLANDPACK; JETBBS; QUALITAS; BWF; ZAP; STORK; ASCENDBACKUP; FMC1; SPIS; BWCF; CMP; FLS; GENIUS; HZL; KBOOM. */
#ifndef XX_FORMAT_SCHEMA_ARCHIVECLASSIC_H
#define XX_FORMAT_SCHEMA_ARCHIVECLASSIC_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxacl_dtpacked_header;
extern const sx_layout sxacl_zlwb_header;
extern const sx_layout sxacl_zlwb_blob;
extern const sx_layout sxacl_zz_header;
extern const sx_layout sxacl_zzz_member;
extern const sx_layout sxacl_jgpak_header;
extern const sx_layout sxacl_jgpak_version_size;
extern const sx_layout sxacl_jgpak_count;
extern const sx_layout sxacl_jgpak_name_size;
extern const sx_layout sxacl_jgpak_member;
extern const sx_layout sxacl_borlandpack_header;
extern const sx_layout sxacl_borlandpack_attributes;
extern const sx_layout sxacl_borlandpack_size;
extern const sx_layout sxacl_borlandpack_lzw_flags;
extern const sx_layout sxacl_jetbbs_member;
extern const sx_layout sxacl_jetbbs_crc16;
extern const sx_layout sxacl_jetbbs_os;
extern const sx_layout sxacl_jetbbs_extension_size;
extern const sx_layout sxacl_jetbbs_extension_type;
extern const sx_layout sxacl_jetbbs_sizes64;
extern const sx_layout sxacl_qualitas_header;
extern const sx_layout sxacl_qualitas_member;
extern const sx_layout sxacl_qualitas_crc32;
extern const sx_layout sxacl_bwf_member;
extern const sx_layout sxacl_zap_member;
extern const sx_layout sxacl_stork_member;
extern const sx_layout sxacl_ascendbackup_name_size;
extern const sx_layout sxacl_ascendbackup_size;
extern const sx_layout sxacl_fmc1_header;
extern const sx_layout sxacl_fmc1_member;
extern const sx_layout sxacl_spis_header;
extern const sx_layout sxacl_spis_member;
extern const sx_layout sxacl_bwcf_header;
extern const sx_layout sxacl_bwcf_name_v1;
extern const sx_layout sxacl_bwcf_name_v2;
extern const sx_layout sxacl_bwcf_directory_size;
extern const sx_layout sxacl_bwcf_member;
extern const sx_layout sxacl_bwcf_block_size;
extern const sx_layout sxacl_cmp_header;
extern const sx_layout sxacl_fls_count;
extern const sx_layout sxacl_fls_header_record;
extern const sx_layout sxacl_fls_member;
extern const sx_layout sxacl_fls_name_header;
extern const sx_layout sxacl_fls_component_offset;
extern const sx_layout sxacl_fls_component_size;
extern const sx_layout sxacl_genius_header;
extern const sx_layout sxacl_genius_member;
extern const sx_layout sxacl_genius_block_size;
extern const sx_layout sxacl_genius_footer;
extern const sx_layout sxacl_hzl_header;
extern const sx_layout sxacl_kboom_header;
bool sxacl_span(sx_context*c,uint64_t p,uint64_t n);
bool sxacl_read(sx_context*c,uint64_t p,void*b,size_t n);
uint64_t sxacl_uint(const uint8_t*b,unsigned n,bool be);
bool sxacl_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v);
bool sxacl_add(sx_context*c,const sx_layout*l,uint64_t p);
bool sxacl_dcl(sx_context*c,uint64_t p,uint64_t n);
bool sxacl_chain(sx_context*c,const sx_layout*l,uint64_t p,unsigned hs,unsigned sizeoff,bool sign,bool dcl);

/* Per-format walkers, called by the family's build. */
bool sx_dtpacked_build(sx_context *c);  /* archive/dtpacked/xx_dtpacked_data.c */
bool sx_zlwb_build(sx_context *c);  /* archive/zlwb/xx_zlwb_data.c */
bool sx_zz_build(sx_context *c);  /* archive/zz/xx_zz_data.c */
bool sx_zzz_build(sx_context *c);  /* archive/zzz/xx_zzz_data.c */
bool sx_jgpak_build(sx_context *c);  /* archive/jgpak/xx_jgpak_data.c */
bool sx_borlandpack_build(sx_context *c);  /* archive/borlandpack/xx_borlandpack_data.c */
bool sx_jetbbs_build(sx_context *c);  /* archive/jetbbs/xx_jetbbs_data.c */
bool sx_qualitas_build(sx_context *c);  /* installer/qualitas/xx_qualitas_data.c */
bool sx_bwf_build(sx_context *c);  /* archive/bwf/xx_bwf_data.c */
bool sx_zap_build(sx_context *c);  /* archive/zap/xx_zap_data.c */
bool sx_stork_build(sx_context *c);  /* installer/stork/xx_stork_data.c */
bool sx_ascendbackup_build(sx_context *c);  /* archive/ascendbackup/xx_ascendbackup_data.c */
bool sx_fmc1_build(sx_context *c);  /* archive/fmc1/xx_fmc1_data.c */
bool sx_spis_build(sx_context *c);  /* archive/spis/xx_spis_data.c */
bool sx_bwcf_build(sx_context *c);  /* archive/bwcf/xx_bwcf_data.c */
bool sx_cmp_build(sx_context *c);  /* archive/cmp/xx_cmp_data.c */
bool sx_fls_build(sx_context *c);  /* archive/fls/xx_fls_data.c */
bool sx_genius_build(sx_context *c);  /* archive/genius/xx_genius_data.c */
bool sx_hzl_build(sx_context *c);  /* archive/hzl/xx_hzl_data.c */
bool sx_kboom_build(sx_context *c);  /* archive/kboom/xx_kboom_data.c */

#endif
