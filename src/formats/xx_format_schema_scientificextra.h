/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The scientificextra schema family: what its family unit (xx_format_schema_scientificextra.c)
 * and its formats' data files share. Formats: flatgeobuf; axona_tetrode; inivation_aedat; ensight_gold_geometry; dted_elevation; scanalytics_iplab; dsn6_density; crystallography_mtz. */
#ifndef XX_FORMAT_SCHEMA_SCIENTIFICEXTRA_H
#define XX_FORMAT_SCHEMA_SCIENTIFICEXTRA_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxscx_aedat2_event;
extern const sx_layout sxscx_axona_timestamp;
extern const sx_layout sxscx_axona_end;
extern const sx_layout sxscx_iplab_header_le;
extern const sx_layout sxscx_iplab_terminator_le;
extern const sx_layout sxscx_dsn6_header_le;
extern const sx_layout sxscx_iplab_header_be;
extern const sx_layout sxscx_iplab_terminator_be;
extern const sx_layout sxscx_dsn6_header_be;
extern const sx_layout sxscx_brix_header;
extern const sx_layout sxscx_mtz_prefix;
extern const sx_layout sxscx_mtz_header_record;
extern const sx_layout sxscx_ensight_header;
extern const sx_layout sxscx_ensight_part;
extern const sx_layout sxscx_ensight_elements;
extern const sx_layout sxscx_ensight_given_id;
extern const sx_layout sxscx_ensight_coordinate;
extern const sx_layout sxscx_ensight_connectivity;
extern const sx_layout sxscx_dted_uhl;
extern const sx_layout sxscx_dted_dsi;
extern const sx_layout sxscx_dted_acc;
extern const sx_layout sxscx_dted_column_header;
extern const sx_layout sxscx_dted_column_checksum;
extern const sx_layout sxscx_fgb_prefix;
extern const sx_layout sxscx_fgb_root;
extern const sx_layout sxscx_fgb_feature_size;
extern const sx_layout sxscx_fgb_table_header;
extern const sx_layout sxscx_fgb_vtable_header;
extern const sx_layout sxscx_fgb_vtable_entry;
extern const sx_layout sxscx_fgb_vector_header;
extern const sx_layout sxscx_fgb_string_header;
extern const sx_layout sxscx_fgb_vector_reference;
extern const sx_layout sxscx_fgb_geometry_end;
extern const sx_layout sxscx_fgb_coordinate;
extern const sx_layout sxscx_fgb_geometry_time;
extern const sx_layout sxscx_fgb_index_internal;
extern const sx_layout sxscx_fgb_index_leaf;
extern const sx_layout sxscx_fgb_header_name;
extern const sx_layout sxscx_fgb_header_envelope;
extern const sx_layout sxscx_fgb_header_geometry_type;
extern const sx_layout sxscx_fgb_header_has_z;
extern const sx_layout sxscx_fgb_header_has_m;
extern const sx_layout sxscx_fgb_header_has_t;
extern const sx_layout sxscx_fgb_header_has_tm;
extern const sx_layout sxscx_fgb_header_columns;
extern const sx_layout sxscx_fgb_header_features_count;
extern const sx_layout sxscx_fgb_header_index_node_size;
extern const sx_layout sxscx_fgb_header_crs;
extern const sx_layout sxscx_fgb_header_title;
extern const sx_layout sxscx_fgb_header_description;
extern const sx_layout sxscx_fgb_header_metadata;
extern const sx_layout sxscx_fgb_column_name;
extern const sx_layout sxscx_fgb_column_type;
extern const sx_layout sxscx_fgb_column_title;
extern const sx_layout sxscx_fgb_column_description;
extern const sx_layout sxscx_fgb_column_width;
extern const sx_layout sxscx_fgb_column_precision;
extern const sx_layout sxscx_fgb_column_scale;
extern const sx_layout sxscx_fgb_column_nullable;
extern const sx_layout sxscx_fgb_column_unique;
extern const sx_layout sxscx_fgb_column_primary_key;
extern const sx_layout sxscx_fgb_column_metadata;
extern const sx_layout sxscx_fgb_crs_org;
extern const sx_layout sxscx_fgb_crs_code;
extern const sx_layout sxscx_fgb_crs_name;
extern const sx_layout sxscx_fgb_crs_description;
extern const sx_layout sxscx_fgb_crs_wkt;
extern const sx_layout sxscx_fgb_crs_code_string;
extern const sx_layout sxscx_fgb_geometry_ends;
extern const sx_layout sxscx_fgb_geometry_xy;
extern const sx_layout sxscx_fgb_geometry_z;
extern const sx_layout sxscx_fgb_geometry_m;
extern const sx_layout sxscx_fgb_geometry_t;
extern const sx_layout sxscx_fgb_geometry_tm;
extern const sx_layout sxscx_fgb_geometry_type;
extern const sx_layout sxscx_fgb_geometry_parts;
extern const sx_layout sxscx_fgb_feature_geometry;
extern const sx_layout sxscx_fgb_feature_properties;
extern const sx_layout sxscx_fgb_property_0;
extern const sx_layout sxscx_fgb_property_1;
extern const sx_layout sxscx_fgb_property_2;
extern const sx_layout sxscx_fgb_property_3;
extern const sx_layout sxscx_fgb_property_4;
extern const sx_layout sxscx_fgb_property_5;
extern const sx_layout sxscx_fgb_property_6;
extern const sx_layout sxscx_fgb_property_7;
extern const sx_layout sxscx_fgb_property_8;
extern const sx_layout sxscx_fgb_property_9;
extern const sx_layout sxscx_fgb_property_10;
extern const sx_layout sxscx_fgb_property_11;
extern const sx_layout sxscx_fgb_property_12;
extern const sx_layout sxscx_fgb_property_13;
extern const sx_layout sxscx_fgb_property_14;
bool sxscx_span(sx_context *c,uint64_t at,uint64_t n);
uint16_t sxscx16(const uint8_t *p,bool be);
uint32_t sxscx32(const uint8_t *p,bool be);
uint64_t sxscx_extent(const sx_layout *l);
bool sxscx_add(sx_context *c,const sx_layout *l,uint64_t at);
bool sxscx_table(sx_context *c,const sx_layout *l,uint64_t at,uint64_t count);
bool sxscx_decimal(const uint8_t *p,size_t n,uint64_t *value);

/* Per-format walkers, called by the family's build. */
bool sx_flatgeobuf_build(sx_context *c,uint8_t *b);  /* science/flatgeobuf/xx_flatgeobuf_data.c */
bool sx_axona_tetrode_build(sx_context *c,uint8_t *b);  /* science/axona_tetrode/xx_axona_tetrode_data.c */
bool sx_inivation_aedat_build(sx_context *c,uint8_t *b);  /* science/inivation_aedat/xx_inivation_aedat_data.c */
bool sx_ensight_gold_geometry_build(sx_context *c,uint8_t *b);  /* science/ensight_gold_geometry/xx_ensight_gold_geometry_data.c */
bool sx_dted_elevation_build(sx_context *c,uint8_t *b);  /* science/dted_elevation/xx_dted_elevation_data.c */
bool sx_scanalytics_iplab_build(sx_context *c,uint8_t *b);  /* science/scanalytics_iplab/xx_scanalytics_iplab_data.c */
bool sx_dsn6_density_build(sx_context *c,uint8_t *b);  /* science/dsn6_density/xx_dsn6_density_data.c */
bool sx_crystallography_mtz_build(sx_context *c,uint8_t *b);  /* science/crystallography_mtz/xx_crystallography_mtz_data.c */

#endif
