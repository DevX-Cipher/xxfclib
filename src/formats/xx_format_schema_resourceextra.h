/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The resourceextra schema family: what its family unit (xx_format_schema_resourceextra.c)
 * and its formats' data files share. Formats: Second Nature; SKF. */
#ifndef XX_FORMAT_SCHEMA_RESOURCEEXTRA_H
#define XX_FORMAT_SCHEMA_RESOURCEEXTRA_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxre_secondnature_banner;
extern const sx_layout sxre_secondnature_bmx_count;
extern const sx_layout sxre_secondnature_ref_counts;
extern const sx_layout sxre_secondnature_snx_text;
extern const sx_layout sxre_secondnature_snx_info;
extern const sx_layout sxre_secondnature_entry;
extern const sx_layout sxre_secondnature_ref_entry;
extern const sx_layout sxre_secondnature_banner_complemented;
extern const sx_layout sxre_secondnature_bmx_count_complemented;
extern const sx_layout sxre_secondnature_ref_counts_complemented;
extern const sx_layout sxre_secondnature_snx_text_complemented;
extern const sx_layout sxre_secondnature_snx_info_complemented;
extern const sx_layout sxre_secondnature_entry_complemented;
extern const sx_layout sxre_secondnature_ref_entry_complemented;
extern const sx_layout sxre_skf_short_string_length;
extern const sx_layout sxre_skf_long_string_length;
extern const sx_layout sxre_skf_object_count;
extern const sx_layout sxre_skf_property_count;
extern const sx_layout sxre_skf_property_id;
extern const sx_layout sxre_skf_resource_count;
extern const sx_layout sxre_skf_resource_prefix;
extern const sx_layout sxre_skf_record6_count;
extern const sx_layout sxre_skf_optional_flag;
extern const sx_layout sxre_skf_record14_count;
extern const sx_layout sxre_skf_variable_record_count;
extern const sx_layout sxre_skf_payload_size;
bool sxre_span(sx_context*c,uint64_t p,uint64_t n);
bool sxre_read(sx_context*c,uint64_t p,void*b,size_t n);
bool sxre_word(sx_context*c,uint64_t p,unsigned n,bool mask,uint64_t*v);
bool sxre_add(sx_context*c,const sx_layout*l,uint64_t p);

/* Per-format walkers, called by the family's build. */
bool sx_secondnature_build(sx_context *c);  /* image/secondnature/xx_secondnature_data.c */
bool sx_skf_build(sx_context *c);  /* image/skf/xx_skf_data.c */

#endif
