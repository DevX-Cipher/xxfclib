/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The androidmeta schema family: what its family unit (xx_format_schema_androidmeta.c)
 * and its formats' data files share. Formats: Android binary XML; Android resources (ARSC). */
#ifndef XX_FORMAT_SCHEMA_ANDROIDMETA_H
#define XX_FORMAT_SCHEMA_ANDROIDMETA_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

typedef struct sx_am_chunk_info{uint64_t at,end;uint16_t type,header;}sx_am_chunk_info;

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sx_am_android_chunk_header;
extern const sx_layout sx_am_android_xml_node;
extern const sx_layout sx_am_android_xml_namespace;
extern const sx_layout sx_am_android_xml_start_element;
extern const sx_layout sx_am_android_xml_end_element;
extern const sx_layout sx_am_android_xml_attribute;
extern const sx_layout sx_am_android_xml_cdata;
extern const sx_layout sx_am_android_resource_id;
extern const sx_layout sx_am_android_table_header;
extern const sx_layout sx_am_android_package_header;
extern const sx_layout sx_am_android_package_header_extended;
extern const sx_layout sx_am_android_type_spec;
extern const sx_layout sx_am_android_type_spec_flags;
extern const sx_layout sx_am_android_type_header;
extern const sx_layout sx_am_android_config_size;
extern const sx_layout sx_am_android_config_base;
extern const sx_layout sx_am_android_config_screen;
extern const sx_layout sx_am_android_config_size_dp;
extern const sx_layout sx_am_android_config_locale;
extern const sx_layout sx_am_android_config_color;
extern const sx_layout sx_am_android_entry_offset;
extern const sx_layout sx_am_android_table_entry;
extern const sx_layout sx_am_android_table_map_entry;
extern const sx_layout sx_am_android_value;
extern const sx_layout sx_am_android_table_map;
bool sx_am_chunk(sx_context *c,uint64_t at,uint64_t end,sx_am_chunk_info *q);
bool sx_am_pool(sx_context *c,const sx_am_chunk_info *q);

/* Per-format walkers, called by the family's build. */
bool sx_android_binary_xml_build(sx_context*c,sx_am_chunk_info root);  /* executable/android_binary_xml/xx_android_binary_xml_data.c */
bool sx_android_resources_arsc_build(sx_context*c,sx_am_chunk_info root);  /* executable/android_resources_arsc/xx_android_resources_arsc_data.c */

#endif
