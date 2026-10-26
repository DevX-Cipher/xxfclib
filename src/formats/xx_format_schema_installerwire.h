/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The installerwire schema family: what its family unit (xx_format_schema_installerwire.c)
 * and its formats' data files share. Formats: IS7INX; IzPack (com.izforge.izpack) installer pack file; SVR4 / Solaris package datastream; OPC; Symbian / EPOC installation packages; DAHUA ZIP; ARCADYAN. */
#ifndef XX_FORMAT_SCHEMA_INSTALLERWIRE_H
#define XX_FORMAT_SCHEMA_INSTALLERWIRE_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxiw_is7inx_header;
extern const sx_layout sxiw_izpack_stream_header;
extern const sx_layout sxiw_java_object_tag;
extern const sx_layout sxiw_java_class_tag;
extern const sx_layout sxiw_java_utf_length;
extern const sx_layout sxiw_java_class_metadata;
extern const sx_layout sxiw_java_field_type;
extern const sx_layout sxiw_java_reference;
extern const sx_layout sxiw_java_string;
extern const sx_layout sxiw_java_long_string;
extern const sx_layout sxiw_java_block;
extern const sx_layout sxiw_java_long_block;
extern const sx_layout sxiw_java_boolean;
extern const sx_layout sxiw_java_byte;
extern const sx_layout sxiw_java_char;
extern const sx_layout sxiw_java_short;
extern const sx_layout sxiw_java_int;
extern const sx_layout sxiw_java_long;
extern const sx_layout sxiw_java_float;
extern const sx_layout sxiw_java_double;
extern const sx_layout sxiw_solaris_package_name;
extern const sx_layout sxiw_solaris_part_count;
extern const sx_layout sxiw_solaris_block_count;
extern const sx_layout sxiw_solaris_banner;
extern const sx_layout sxiw_solaris_end_header;
extern const sx_layout sxiw_opc_banner;
extern const sx_layout sxiw_sis_uids;
extern const sx_layout sxiw_sis_epoc_header;
extern const sx_layout sxiw_sis_epoc6_extension;
extern const sx_layout sxiw_sis_installed_space;
extern const sx_layout sxiw_sis_maximum_installed_space;
extern const sx_layout sxiw_sis_epoc6_reserved;
extern const sx_layout sxiw_sis_requisite;
extern const sx_layout sxiw_sis_certificate_header;
extern const sx_layout sxiw_sis_language;
extern const sx_layout sxiw_sis_file_record;
extern const sx_layout sxiw_sis_payload_length;
extern const sx_layout sxiw_sis_payload_offset;
extern const sx_layout sxiw_sis_uncompressed_length;
extern const sx_layout sxiw_sis_mime_length;
extern const sx_layout sxiw_sis_mime_offset;
extern const sx_layout sxiw_sis_conditional;
extern const sx_layout sxiw_sis_control_type;
extern const sx_layout sxiw_sisx_field;
extern const sx_layout sxiw_sisx_long_field;
extern const sx_layout sxiw_sisx_array_element;
extern const sx_layout sxiw_sisx_array_length;
extern const sx_layout sxiw_sisx_array_long_length;
extern const sx_layout sxiw_sisx_compressed;
extern const sx_layout sxiw_java_modified_utf8;
extern const sx_layout sxiw_sis_latin1;
extern const sx_layout sxiw_sis_utf16;
extern const sx_layout sxiw_sis_capability;
extern const sx_layout sxiw_sisx_checksum;
extern const sx_layout sxiw_sisx_data_index;
extern const sx_layout sxiw_arcadyan_lzma_fragments;
extern const sx_layout sxiw_installer_zip_local;
extern const sx_layout sxiw_installer_zip_central;
extern const sx_layout sxiw_installer_zip_eocd;
extern const sx_layout sxiw_installer_zip_extra;
extern const sx_layout sxiw_installer_zip_name;
extern const sx_layout sxiw_installer_zip_comment;
extern const sx_layout sxiw_solaris_cpio_newc;
extern const sx_layout sxiw_solaris_cpio_odc;
extern const sx_layout sxiw_solaris_cpio_binary_le;
extern const sx_layout sxiw_solaris_cpio_binary_be;
extern const sx_layout sxiw_solaris_cpio_name;
extern const sx_layout sxiw_izpack_record_v1;
extern const sx_layout sxiw_izpack_record_v2;
extern const sx_layout sxiw_izpack_record_v3;
extern const sx_layout sxiw_izpack_record_v4;
extern const sx_layout sxiw_izpack_record_v5;
extern const sx_layout sxiw_izpack_record_v6;
extern const sx_layout sxiw_izpack_record_v7;
extern const sx_layout sxiw_sis_localized_name_length;
extern const sx_layout sxiw_sis_localized_name_offset;
extern const sx_layout sxiw_izpack_list_count;
bool sxiw_span(sx_context*c,uint64_t p,uint64_t n);
bool sxiw_read(sx_context*c,uint64_t p,void*b,size_t n);
uint64_t sxiw_uint(const uint8_t*b,unsigned n,bool be);
bool sxiw_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v);
bool sxiw_add(sx_context*c,const sx_layout*l,uint64_t p);
bool sxiw_text(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n,bool aliases);
bool sxiw_table(sx_context*c,const sx_layout*l,uint64_t p,uint64_t width,uint64_t n);
bool sxiw_emit(sx_context*c,uint64_t*p,uint64_t end,const sx_layout*l);

/* Per-format walkers, called by the family's build. */
bool sx_is7inx_build(sx_context *c);  /* installer/is7inx/xx_is7inx_data.c */
bool sx_izpack_build(sx_context *c);  /* installer/izpack/xx_izpack_data.c */
bool sx_solarispkg_build(sx_context *c);  /* installer/solarispkg/xx_solarispkg_data.c */
bool sx_opc_build(sx_context *c);  /* installer/opc/xx_opc_data.c */
bool sx_sis_build(sx_context *c);  /* installer/sis/xx_sis_data.c */
bool sx_dahuazip_build(sx_context *c);  /* firmware/dahuazip/xx_dahuazip_data.c */
bool sx_arcadyan_build(sx_context *c);  /* firmware/arcadyan/xx_arcadyan_data.c */

#endif
