/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The sciencemeta schema family: what its family unit (xx_format_schema_sciencemeta.c)
 * and its formats' data files share. Formats: MRC electron-density maps; Esri shapefile; LiDAR LAS point clouds; SEG-2 seismic data; Garmin FIT; MountainSort MDA arrays; FreeSurfer surface; SAC seismic data. */
#ifndef XX_FORMAT_SCHEMA_SCIENCEMETA_H
#define XX_FORMAT_SCHEMA_SCIENCEMETA_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxsc_mrc_header_le;
extern const sx_layout sxsc_mrc_header_be;
extern const sx_layout sxsc_mrc_label;
extern const sx_layout sxsc_shp_file_header;
extern const sx_layout sxsc_shp_record_header;
extern const sx_layout sxsc_shp_shape_type;
extern const sx_layout sxsc_shp_point;
extern const sx_layout sxsc_shp_multipoint;
extern const sx_layout sxsc_shp_polyline_polygon;
extern const sx_layout sxsc_shp_part;
extern const sx_layout sxsc_shp_xy;
extern const sx_layout sxsc_las12_header;
extern const sx_layout sxsc_las_vlr;
extern const sx_layout sxsc_las_point0;
extern const sx_layout sxsc_las_point1;
extern const sx_layout sxsc_las_point2;
extern const sx_layout sxsc_las_point3;
extern const sx_layout sxsc_seg2_file_header_le;
extern const sx_layout sxsc_seg2_trace_pointer_le;
extern const sx_layout sxsc_seg2_trace_header_le;
extern const sx_layout sxsc_seg2_string_length_le;
extern const sx_layout sxsc_seg2_file_header_be;
extern const sx_layout sxsc_seg2_trace_pointer_be;
extern const sx_layout sxsc_seg2_trace_header_be;
extern const sx_layout sxsc_seg2_string_length_be;
extern const sx_layout sxsc_fit_file_header;
extern const sx_layout sxsc_fit_crc16;
extern const sx_layout sxsc_fit_record_header;
extern const sx_layout sxsc_fit_definition_le;
extern const sx_layout sxsc_fit_definition_be;
extern const sx_layout sxsc_fit_field_definition;
extern const sx_layout sxsc_fit_developer_count;
extern const sx_layout sxsc_fit_developer_field;
extern const sx_layout sxsc_mda_header;
extern const sx_layout sxsc_mda_dimension32;
extern const sx_layout sxsc_mda_dimension64;
extern const sx_layout sxsc_freesurfer_signature;
extern const sx_layout sxsc_freesurfer_counts;
extern const sx_layout sxsc_freesurfer_vertex;
extern const sx_layout sxsc_freesurfer_face;
extern const sx_layout sxsc_freesurfer_volume_marker;
extern const sx_layout sxsc_freesurfer_volume_marker_long;
extern const sx_layout sxsc_sac_header_le;
extern const sx_layout sxsc_sac_header_be;
uint16_t sxsc16(const uint8_t *p,bool be);
uint32_t sxsc32(const uint8_t *p,bool be);
bool sxsc_span(sx_context *c,int64_t at,uint64_t n);
bool sxsc_add(sx_context *c,const sx_layout *l,int64_t at,int64_t bytes);
bool sxsc_table(sx_context *c,const sx_layout *l,int64_t at,int64_t bytes,uint64_t count);

/* Per-format walkers, called by the family's build. */
bool sx_mrc_build(sx_context *c);  /* science/mrc/xx_mrc_data.c */
bool sx_esri_shp_build(sx_context *c);  /* science/esri_shp/xx_esri_shp_data.c */
bool sx_lidar_las_build(sx_context *c);  /* science/lidar_las/xx_lidar_las_data.c */
bool sx_seismic_seg2_build(sx_context *c);  /* science/seismic_seg2/xx_seismic_seg2_data.c */
bool sx_garmin_fit_build(sx_context *c);  /* science/garmin_fit/xx_garmin_fit_data.c */
bool sx_mountainsort_mda_build(sx_context *c);  /* science/mountainsort_mda/xx_mountainsort_mda_data.c */
bool sx_freesurfer_surface_build(sx_context *c);  /* science/freesurfer_surface/xx_freesurfer_surface_data.c */
bool sx_seismic_sac_build(sx_context *c);  /* science/seismic_sac/xx_seismic_sac_data.c */

#endif
