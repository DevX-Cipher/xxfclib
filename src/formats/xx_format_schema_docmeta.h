/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The docmeta schema family: what its family unit (xx_format_schema_docmeta.c)
 * and its formats' data files share. Formats: DjVu documents; ZXML documents; Delrina WinFax LSZ libraries; PAIN documents; The Bat! MSB mailbox; Stylus dictionary containers; Delrina PerFORM / FormFlow documents; FidoNet mail packets; PaperPort desktop files; Windows Help (HLP); MediaView titles (*.ivt); openZIM archives; Outlook Express 5/6 DBX message store. */
#ifndef XX_FORMAT_SCHEMA_DOCMETA_H
#define XX_FORMAT_SCHEMA_DOCMETA_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxdm_djvu_form_header;
extern const sx_layout sxdm_djvu_chunk_header;
extern const sx_layout sxdm_djvu_info;
extern const sx_layout sxdm_zxml_header;
extern const sx_layout sxdm_lsz_header;
extern const sx_layout sxdm_lsz_member_header;
extern const sx_layout sxdm_pain_header;
extern const sx_layout sxdm_pain_directory_entry;
extern const sx_layout sxdm_pain_lzss_block_header;
extern const sx_layout sxdm_thebat_msb_header;
extern const sx_layout sxdm_thebat_msb_record;
extern const sx_layout sxdm_stylus_header;
extern const sx_layout sxdm_perform_header;
extern const sx_layout sxdm_pkt_type2_header;
extern const sx_layout sxdm_pkt_message_header;
extern const sx_layout sxdm_paperport_header;
extern const sx_layout sxdm_paperport_chunk_header;
extern const sx_layout sxdm_paperport_root_prefix;
extern const sx_layout sxdm_paperport_root_entry;
extern const sx_layout sxdm_paperport_page_item;
extern const sx_layout sxdm_winhelp_header;
extern const sx_layout sxdm_winhelp_internal_file_header;
extern const sx_layout sxdm_winhelp_btree_header;
extern const sx_layout sxdm_winhelp_index_header;
extern const sx_layout sxdm_winhelp_leaf_header;
extern const sx_layout sxdm_winhelp_file_pointer;
extern const sx_layout sxdm_ivt_header;
extern const sx_layout sxdm_ivt_btree_header;
extern const sx_layout sxdm_ivt_leaf_header;
extern const sx_layout sxdm_ivt_index_header;
extern const sx_layout sxdm_ivt_key_length;
extern const sx_layout sxdm_ivt_child_pointer;
extern const sx_layout sxdm_ivt_entry_terminator;
extern const sx_layout sxdm_ivt_mszip_header;
extern const sx_layout sxdm_ivt_mszip_block_header;
extern const sx_layout sxdm_ivt_leb_offset_1;
extern const sx_layout sxdm_ivt_leb_offset_2;
extern const sx_layout sxdm_ivt_leb_offset_3;
extern const sx_layout sxdm_ivt_leb_offset_4;
extern const sx_layout sxdm_ivt_leb_offset_5;
extern const sx_layout sxdm_ivt_leb_size_1;
extern const sx_layout sxdm_ivt_leb_size_2;
extern const sx_layout sxdm_ivt_leb_size_3;
extern const sx_layout sxdm_ivt_leb_size_4;
extern const sx_layout sxdm_ivt_leb_size_5;
extern const sx_layout sxdm_zim_header;
extern const sx_layout sxdm_zim_url_pointer;
extern const sx_layout sxdm_zim_title_pointer;
extern const sx_layout sxdm_zim_cluster_pointer;
extern const sx_layout sxdm_zim_article_entry;
extern const sx_layout sxdm_zim_redirect_entry;
extern const sx_layout sxdm_zim_cluster_header;
extern const sx_layout sxdm_zim_blob_offset32;
extern const sx_layout sxdm_zim_blob_offset64;
extern const sx_layout sxdm_zim_checksum;
extern const sx_layout sxdm_dbx_header;
extern const sx_layout sxdm_dbx_node_header;
extern const sx_layout sxdm_dbx_node_entry;
extern const sx_layout sxdm_dbx_info_header;
extern const sx_layout sxdm_dbx_attribute;
extern const sx_layout sxdm_dbx_attribute_indirect;
extern const sx_layout sxdm_dbx_attribute_message;
extern const sx_layout sxdm_dbx_message_pointer;
extern const sx_layout sxdm_dbx_block_header;
uint16_t sxdm_u16(const uint8_t *p);
uint32_t sxdm_u32(const uint8_t *p);
uint64_t sxdm_u64(const uint8_t *p);
bool sxdm_span(sx_context *c,int64_t at,uint64_t n);
bool sxdm_add(sx_context *c,const sx_layout *l,int64_t at,int64_t n);
bool sxdm_zero(sx_context *c,int64_t *at,int64_t end,unsigned limit);

/* Per-format walkers, called by the family's build. */
bool sx_djvu_build(sx_context *c);  /* document/djvu/xx_djvu_data.c */
bool sx_zxml_build(sx_context *c);  /* document/zxml/xx_zxml_data.c */
bool sx_lsz_build(sx_context *c);  /* document/lsz/xx_lsz_data.c */
bool sx_pain_build(sx_context *c);  /* document/pain/xx_pain_data.c */
bool sx_thebat_msb_build(sx_context *c);  /* document/thebat_msb/xx_thebat_msb_data.c */
bool sx_stylus_build(sx_context *c);  /* document/stylus/xx_stylus_data.c */
bool sx_perform_build(sx_context *c);  /* document/perform/xx_perform_data.c */
bool sx_pkt_build(sx_context *c);  /* document/pkt/xx_pkt_data.c */
bool sx_paperport_build(sx_context *c);  /* document/paperport/xx_paperport_data.c */
bool sx_ue2_documents_build(sx_context *c);  /* document/ue2_documents/xx_ue2_documents_data.c */
bool sx_ivt_build(sx_context *c);  /* document/ivt/xx_ivt_data.c */
bool sx_openzim_build(sx_context *c);  /* document/openzim/xx_openzim_data.c */
bool sx_outlook_express_dbx_mailbox_build(sx_context *c);  /* document/outlook_express_dbx_mailbox/xx_outlook_express_dbx_mailbox_data.c */

#endif
