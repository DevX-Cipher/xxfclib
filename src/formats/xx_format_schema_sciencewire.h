/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The sciencewire schema family: what its family unit (xx_format_schema_sciencewire.c)
 * and its formats' data files share. Formats: FITS; SAS XPORT; SPSS SAV; Stata DTA; ROS bag v1; BGEN; Igor binary wave; SPIDER; WMO GRIB; WMO BUFR; LeCroy TRC; Neuroscan CNT; Tecplot PLT; Open Ephys continuous. */
#ifndef XX_FORMAT_SCHEMA_SCIENCEWIRE_H
#define XX_FORMAT_SCHEMA_SCIENCEWIRE_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxsw_fits_card;
extern const sx_layout sxsw_fits_integer_card;
extern const sx_layout sxsw_xport_header_record;
extern const sx_layout sxsw_xport_namestr;
extern const sx_layout sxsw_sav_header_le;
extern const sx_layout sxsw_sav_variable_le;
extern const sx_layout sxsw_sav_extension_le;
extern const sx_layout sxsw_sav_count_record_le;
extern const sx_layout sxsw_sav_dictionary_end_le;
extern const sx_layout sxsw_sav_label_size_le;
extern const sx_layout sxsw_sav_variable_index_le;
extern const sx_layout sxsw_sav_value_label_le;
extern const sx_layout sxsw_sav_machine_integer_le;
extern const sx_layout sxsw_sav_header_be;
extern const sx_layout sxsw_sav_variable_be;
extern const sx_layout sxsw_sav_extension_be;
extern const sx_layout sxsw_sav_count_record_be;
extern const sx_layout sxsw_sav_dictionary_end_be;
extern const sx_layout sxsw_sav_label_size_be;
extern const sx_layout sxsw_sav_variable_index_be;
extern const sx_layout sxsw_sav_value_label_be;
extern const sx_layout sxsw_sav_machine_integer_be;
extern const sx_layout sxsw_sav_document_line;
extern const sx_layout sxsw_bgen_header;
extern const sx_layout sxsw_bgen_flags;
extern const sx_layout sxsw_bgen_sample_header;
extern const sx_layout sxsw_bgen_string16;
extern const sx_layout sxsw_bgen_string32;
extern const sx_layout sxsw_bgen_variant_sample_count;
extern const sx_layout sxsw_bgen_variant_position;
extern const sx_layout sxsw_igor_binary5_le;
extern const sx_layout sxsw_igor_wave5_le;
extern const sx_layout sxsw_igor_binary5_be;
extern const sx_layout sxsw_igor_wave5_be;
extern const sx_layout sxsw_spider_header_le;
extern const sx_layout sxsw_lecroy_descriptor_le;
extern const sx_layout sxsw_lecroy_trigger_time_le;
extern const sx_layout sxsw_lecroy_ris_time_le;
extern const sx_layout sxsw_spider_header_be;
extern const sx_layout sxsw_lecroy_descriptor_be;
extern const sx_layout sxsw_lecroy_trigger_time_be;
extern const sx_layout sxsw_lecroy_ris_time_be;
extern const sx_layout sxsw_grib2_indicator;
extern const sx_layout sxsw_grib2_section;
extern const sx_layout sxsw_grib2_identification;
extern const sx_layout sxsw_grib2_grid;
extern const sx_layout sxsw_grib2_product;
extern const sx_layout sxsw_grib2_representation;
extern const sx_layout sxsw_grib2_bitmap;
extern const sx_layout sxsw_wmo_end;
extern const sx_layout sxsw_bufr4_indicator;
extern const sx_layout sxsw_bufr4_identification;
extern const sx_layout sxsw_bufr4_section;
extern const sx_layout sxsw_bufr4_data_description;
extern const sx_layout sxsw_bufr_descriptor;
extern const sx_layout sxsw_openephys_record;
extern const sx_layout sxsw_openephys_marker;
extern const sx_layout sxsw_cnt_setup;
extern const sx_layout sxsw_cnt_channel;
extern const sx_layout sxsw_cnt_event_table;
extern const sx_layout sxsw_cnt_event1;
extern const sx_layout sxsw_cnt_event2;
extern const sx_layout sxsw_cnt_event3;
extern const sx_layout sxsw_stata117_prefix_le;
extern const sx_layout sxsw_stata117_label_size_le;
extern const sx_layout sxsw_stata117_variable_name;
extern const sx_layout sxsw_stata117_display_format;
extern const sx_layout sxsw_stata117_value_label_name;
extern const sx_layout sxsw_stata117_variable_label;
extern const sx_layout sxsw_stata118_prefix_le;
extern const sx_layout sxsw_stata118_label_size_le;
extern const sx_layout sxsw_stata118_variable_name;
extern const sx_layout sxsw_stata118_display_format;
extern const sx_layout sxsw_stata118_value_label_name;
extern const sx_layout sxsw_stata118_variable_label;
extern const sx_layout sxsw_stata_map_le;
extern const sx_layout sxsw_stata_type_le;
extern const sx_layout sxsw_stata_sort_index_le;
extern const sx_layout sxsw_stata117_prefix_be;
extern const sx_layout sxsw_stata117_label_size_be;
extern const sx_layout sxsw_stata118_prefix_be;
extern const sx_layout sxsw_stata118_label_size_be;
extern const sx_layout sxsw_stata_map_be;
extern const sx_layout sxsw_stata_type_be;
extern const sx_layout sxsw_stata_sort_index_be;
extern const sx_layout sxsw_stata_timestamp_size;
extern const sx_layout sxsw_rosbag_signature;
extern const sx_layout sxsw_rosbag_header_size;
extern const sx_layout sxsw_rosbag_field_size;
extern const sx_layout sxsw_rosbag_data_size;
extern const sx_layout sxsw_rosbag_op;
extern const sx_layout sxsw_rosbag_conn;
extern const sx_layout sxsw_rosbag_size;
extern const sx_layout sxsw_rosbag_count;
extern const sx_layout sxsw_rosbag_ver;
extern const sx_layout sxsw_rosbag_index_pos;
extern const sx_layout sxsw_rosbag_chunk_pos;
extern const sx_layout sxsw_rosbag_conn_count;
extern const sx_layout sxsw_rosbag_chunk_count;
extern const sx_layout sxsw_rosbag_time;
extern const sx_layout sxsw_rosbag_index;
extern const sx_layout sxsw_rosbag_connection_count;
extern const sx_layout sxsw_tecplot_prefix_le;
extern const sx_layout sxsw_tecplot_codepoint_le;
extern const sx_layout sxsw_tecplot_variable_count_le;
extern const sx_layout sxsw_tecplot_marker_le;
extern const sx_layout sxsw_tecplot_ordered_zone_le;
extern const sx_layout sxsw_tecplot_auxiliary_flag_le;
extern const sx_layout sxsw_tecplot_variable_type_le;
extern const sx_layout sxsw_tecplot_data_flags_le;
extern const sx_layout sxsw_tecplot_range_le;
extern const sx_layout sxsw_tecplot_prefix_be;
extern const sx_layout sxsw_tecplot_codepoint_be;
extern const sx_layout sxsw_tecplot_variable_count_be;
extern const sx_layout sxsw_tecplot_marker_be;
extern const sx_layout sxsw_tecplot_ordered_zone_be;
extern const sx_layout sxsw_tecplot_auxiliary_flag_be;
extern const sx_layout sxsw_tecplot_variable_type_be;
extern const sx_layout sxsw_tecplot_data_flags_be;
extern const sx_layout sxsw_tecplot_range_be;
uint16_t sxsw16(const uint8_t *p,bool be);
uint32_t sxsw32(const uint8_t *p,bool be);
bool sxsw_span(sx_context *c,int64_t at,uint64_t n);
bool sxsw_add(sx_context *c,const sx_layout *l,int64_t at,int64_t bytes);
bool sxsw_table(sx_context *c,const sx_layout *l,int64_t at,int64_t bytes,uint64_t count);
bool sxsw_text_integer(const uint8_t *p,size_t n,int64_t *out);

/* Per-format walkers, called by the family's build. */
bool sx_fits_build(sx_context *c);  /* science/fits/xx_fits_data.c */
bool sx_sas_xport_build(sx_context *c);  /* science/sas_xport/xx_sas_xport_data.c */
bool sx_spss_sav_build(sx_context *c);  /* science/spss_sav/xx_spss_sav_data.c */
bool sx_stata_dta_build(sx_context *c);  /* science/stata_dta/xx_stata_dta_data.c */
bool sx_rosbag1_build(sx_context *c);  /* science/rosbag1/xx_rosbag1_data.c */
bool sx_genomics_bgen_build(sx_context *c);  /* science/genomics_bgen/xx_genomics_bgen_data.c */
bool sx_igor_ibw_build(sx_context *c);  /* science/igor_ibw/xx_igor_ibw_data.c */
bool sx_microscopy_spider_build(sx_context *c);  /* science/microscopy_spider/xx_microscopy_spider_data.c */
bool sx_wmo_grib_build(sx_context *c);  /* science/wmo_grib/xx_wmo_grib_data.c */
bool sx_wmo_bufr_build(sx_context *c);  /* science/wmo_bufr/xx_wmo_bufr_data.c */
bool sx_lecroy_trc_build(sx_context *c);  /* science/lecroy_trc/xx_lecroy_trc_data.c */
bool sx_neuroscan_cnt_build(sx_context *c);  /* science/neuroscan_cnt/xx_neuroscan_cnt_data.c */
bool sx_tecplot_plt_build(sx_context *c);  /* science/tecplot_plt/xx_tecplot_plt_data.c */
bool sx_openephys_continuous_build(sx_context *c);  /* science/openephys_continuous/xx_openephys_continuous_data.c */

#endif
