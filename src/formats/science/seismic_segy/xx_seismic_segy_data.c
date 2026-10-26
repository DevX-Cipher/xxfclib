/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SEISMIC_SEGY data structures, moved out of the scienceheaders schema family. */
#include "../../xx_format_schema_scienceheaders.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsh_segy_trace_header_fields[] = {
    SX_FIELD("trace_sequence_number_within_line","int32",0,4,SX_NONE),
    SX_FIELD("trace_sequence_number_within_segy_file","int32",4,4,SX_NONE),
    SX_FIELD("original_field_record_number","int32",8,4,SX_NONE),
    SX_FIELD("trace_number_within_the_original_field_record","int32",12,4,SX_NONE),
    SX_FIELD("energy_source_point_number","int32",16,4,SX_NONE),
    SX_FIELD("ensemble_number","int32",20,4,SX_NONE),
    SX_FIELD("trace_number_within_the_ensemble","int32",24,4,SX_NONE),
    SX_FIELD("trace_identification_code","int16",28,2,SX_ID),
    SX_FIELD("number_of_vertically_summed_traces_yielding_this_trace","int16",30,2,SX_NONE),
    SX_FIELD("number_of_horizontally_stacked_traces_yielding_this_trace","int16",32,2,SX_NONE),
    SX_FIELD("data_use","int16",34,2,SX_NONE),
    SX_FIELD("distance_from_center_of_the_source_point_to_the_center_of_the_receiver_group","int32",36,4,SX_NONE),
    SX_FIELD("receiver_group_elevation","int32",40,4,SX_NONE),
    SX_FIELD("surface_elevation_at_source","int32",44,4,SX_NONE),
    SX_FIELD("source_depth_below_surface","int32",48,4,SX_NONE),
    SX_FIELD("datum_elevation_at_receiver_group","int32",52,4,SX_NONE),
    SX_FIELD("datum_elevation_at_source","int32",56,4,SX_NONE),
    SX_FIELD("water_depth_at_source","int32",60,4,SX_NONE),
    SX_FIELD("water_depth_at_group","int32",64,4,SX_NONE),
    SX_FIELD("scalar_to_be_applied_to_all_elevations_and_depths","int16",68,2,SX_NONE),
    SX_FIELD("scalar_to_be_applied_to_all_coordinates","int16",70,2,SX_NONE),
    SX_FIELD("source_coordinate_x","int32",72,4,SX_NONE),
    SX_FIELD("source_coordinate_y","int32",76,4,SX_NONE),
    SX_FIELD("group_coordinate_x","int32",80,4,SX_NONE),
    SX_FIELD("group_coordinate_y","int32",84,4,SX_NONE),
    SX_FIELD("coordinate_units","int16",88,2,SX_ID),
    SX_FIELD("weathering_velocity","int16",90,2,SX_NONE),
    SX_FIELD("subweathering_velocity","int16",92,2,SX_NONE),
    SX_FIELD("uphole_time_at_source_in_ms","int16",94,2,SX_NONE),
    SX_FIELD("uphole_time_at_group_in_ms","int16",96,2,SX_NONE),
    SX_FIELD("source_static_correction_in_ms","int16",98,2,SX_NONE),
    SX_FIELD("group_static_correction_in_ms","int16",100,2,SX_NONE),
    SX_FIELD("total_static_applied_in_ms","int16",102,2,SX_NONE),
    SX_FIELD("lag_time_A","int16",104,2,SX_NONE),
    SX_FIELD("lag_time_B","int16",106,2,SX_NONE),
    SX_FIELD("delay_recording_time","int16",108,2,SX_NONE),
    SX_FIELD("mute_time_start_time_in_ms","int16",110,2,SX_NONE),
    SX_FIELD("mute_time_end_time_in_ms","int16",112,2,SX_NONE),
    SX_FIELD("number_of_samples_in_this_trace","uint16",114,2,SX_COUNT_PROP),
    SX_FIELD("sample_interval_in_microseconds","uint16",116,2,SX_NONE),
    SX_FIELD("gain_type_of_field_instruments","int16",118,2,SX_NONE),
    SX_FIELD("instrument_gain_constant","int16",120,2,SX_NONE),
    SX_FIELD("instrument_early_or_initial_gain","int16",122,2,SX_NONE),
    SX_FIELD("correlated","int16",124,2,SX_NONE),
    SX_FIELD("sweep_frequency_at_start","int16",126,2,SX_NONE),
    SX_FIELD("sweep_frequency_at_end","int16",128,2,SX_NONE),
    SX_FIELD("sweep_length_in_ms","int16",130,2,SX_NONE),
    SX_FIELD("sweep_type","int16",132,2,SX_NONE),
    SX_FIELD("sweep_trace_taper_length_at_start_in_ms","int16",134,2,SX_NONE),
    SX_FIELD("sweep_trace_taper_length_at_end_in_ms","int16",136,2,SX_NONE),
    SX_FIELD("taper_type","int16",138,2,SX_NONE),
    SX_FIELD("alias_filter_frequency","int16",140,2,SX_NONE),
    SX_FIELD("alias_filter_slope","int16",142,2,SX_NONE),
    SX_FIELD("notch_filter_frequency","int16",144,2,SX_NONE),
    SX_FIELD("notch_filter_slope","int16",146,2,SX_NONE),
    SX_FIELD("low_cut_frequency","int16",148,2,SX_NONE),
    SX_FIELD("high_cut_frequency","int16",150,2,SX_NONE),
    SX_FIELD("low_cut_slope","int16",152,2,SX_NONE),
    SX_FIELD("high_cut_slope","int16",154,2,SX_NONE),
    SX_FIELD("year_data_recorded","int16",156,2,SX_NONE),
    SX_FIELD("day_of_year","int16",158,2,SX_NONE),
    SX_FIELD("hour_of_day","int16",160,2,SX_NONE),
    SX_FIELD("minute_of_hour","int16",162,2,SX_NONE),
    SX_FIELD("second_of_minute","int16",164,2,SX_NONE),
    SX_FIELD("time_basis_code","int16",166,2,SX_ID),
    SX_FIELD("trace_weighting_factor","int16",168,2,SX_NONE),
    SX_FIELD("geophone_group_number_of_roll_switch_position_one","int16",170,2,SX_NONE),
    SX_FIELD("geophone_group_number_of_trace_number_one","int16",172,2,SX_NONE),
    SX_FIELD("geophone_group_number_of_last_trace","int16",174,2,SX_NONE),
    SX_FIELD("gap_size","int16",176,2,SX_NONE),
    SX_FIELD("over_travel_associated_with_taper","int16",178,2,SX_NONE),
    SX_FIELD("x_coordinate_of_ensemble_position_of_this_trace","int32",180,4,SX_NONE),
    SX_FIELD("y_coordinate_of_ensemble_position_of_this_trace","int32",184,4,SX_NONE),
    SX_FIELD("for_3d_poststack_data_this_field_is_for_in_line_number","int32",188,4,SX_NONE),
    SX_FIELD("for_3d_poststack_data_this_field_is_for_cross_line_number","int32",192,4,SX_NONE),
    SX_FIELD("shotpoint_number","int32",196,4,SX_NONE),
    SX_FIELD("scalar_to_be_applied_to_the_shotpoint_number","int16",200,2,SX_NONE),
    SX_FIELD("trace_value_measurement_unit","int16",202,2,SX_ID),
    SX_FIELD("transduction_constant_mantissa","int32",204,4,SX_NONE),
    SX_FIELD("transduction_constant_exponent","int16",208,2,SX_NONE),
    SX_FIELD("transduction_units","int16",210,2,SX_ID),
    SX_FIELD("device_trace_identifier","int16",212,2,SX_ID),
    SX_FIELD("scalar_to_be_applied_to_times","int16",214,2,SX_NONE),
    SX_FIELD("source_type_orientation","int16",216,2,SX_NONE),
    SX_FIELD("source_energy_direction","uint8[6]",218,6,SX_NONE),
    SX_FIELD("source_measurement_mantissa","int32",224,4,SX_NONE),
    SX_FIELD("source_measurement_exponent","int16",228,2,SX_NONE),
    SX_FIELD("source_measurement_unit","int16",230,2,SX_ID),
    SX_FIELD("unassigned","uint8[8]",232,8,SX_RESERVED),
};
const sx_layout sxsh_segy_trace_header = {UINT32_C(0x602a0031),"segy_trace_header",sxsh_segy_trace_header_fields,SX_COUNT(sxsh_segy_trace_header_fields),SX_BE};
static const xx_data_struct_field_desc sxsh_segy_text_card_fields[] = {
    SX_FIELD("text_bytes","uint8[80]",0,80,SX_STRING),
};
const sx_layout sxsh_segy_text_card = {UINT32_C(0x602a0032),"segy_text_card",sxsh_segy_text_card_fields,SX_COUNT(sxsh_segy_text_card_fields),SX_LE};
static bool sxsh_segy(sx_context *c)
{
 uint8_t b[400];if(!sx_read(c,3200,b,400)||!sxsh_table(c,&sxsh_segy_text_card,0,80,40)||!sxsh_add(c,&sxsh_segy_binary_header,3200,400))return false;
 unsigned ext=sxsh16(b+304,true),fmt=sxsh16(b+24,true),width=fmt==1||fmt==2||fmt==5?4:fmt==3?2:fmt==8?1:0;
 if(!width||ext>16||!sxsh_table(c,&sxsh_segy_text_card,3600,80,ext*40))return false;int64_t at=3600+ext*3200;
 for(unsigned i=0;at<c->size;i++){uint16_t n;if(i>=1024||!sxsh_span(c,at,240)||!sx_u16(c,at+114,true,&n)||!n||!sxsh_span(c,at,240+(uint64_t)n*width)||!sxsh_add(c,&sxsh_segy_trace_header,at,240))return false;at+=240+(int64_t)n*width;}
 return at==c->size;
}
bool sx_seismic_segy_build(sx_context*c)
{
 bool ok=false;
 ok=sxsh_segy(c);
 return ok&&sxsh_finish(c);
}
