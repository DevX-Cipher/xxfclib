/* SPDX-License-Identifier: MIT
 * Scientific file metadata. Scope: docs/data_struct_sciencewire_scope.txt. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_sciencewire.h"

static const xx_data_struct_field_desc sxsw_igor_wave5_le_fields[] = {
    SX_FIELD("next","uint32",0,4,SX_POINTER),
    SX_FIELD("creationDate","uint32",4,4,SX_NONE),
    SX_FIELD("modDate","uint32",8,4,SX_NONE),
    SX_FIELD("npnts","int32",12,4,SX_COUNT_PROP),
    SX_FIELD("type","int16",16,2,SX_ID),
    SX_FIELD("dLock","int16",18,2,SX_RESERVED),
    SX_FIELD("whpad1","char[6]",20,6,SX_RESERVED),
    SX_FIELD("whVersion","int16",26,2,SX_ID),
    SX_FIELD("bname","char[32]",28,32,SX_STRING),
    SX_FIELD("whpad2","int32",60,4,SX_RESERVED),
    SX_FIELD("dFolder","uint32",64,4,SX_POINTER),
    SX_FIELD("nDim0","int32",68,4,SX_COUNT_PROP),
    SX_FIELD("nDim1","int32",72,4,SX_COUNT_PROP),
    SX_FIELD("nDim2","int32",76,4,SX_COUNT_PROP),
    SX_FIELD("nDim3","int32",80,4,SX_COUNT_PROP),
    SX_FIELD("sfA0","float64",84,8,SX_NONE),
    SX_FIELD("sfA1","float64",92,8,SX_NONE),
    SX_FIELD("sfA2","float64",100,8,SX_NONE),
    SX_FIELD("sfA3","float64",108,8,SX_NONE),
    SX_FIELD("sfB0","float64",116,8,SX_NONE),
    SX_FIELD("sfB1","float64",124,8,SX_NONE),
    SX_FIELD("sfB2","float64",132,8,SX_NONE),
    SX_FIELD("sfB3","float64",140,8,SX_NONE),
    SX_FIELD("dataUnits","char[4]",148,4,SX_STRING),
    SX_FIELD("dimUnits","char[16]",152,16,SX_STRING),
    SX_FIELD("fsValid","int16",168,2,SX_NONE),
    SX_FIELD("whpad3","int16",170,2,SX_RESERVED),
    SX_FIELD("topFullScale","float64",172,8,SX_NONE),
    SX_FIELD("botFullScale","float64",180,8,SX_NONE),
    SX_FIELD("dataEUnits","uint32",188,4,SX_POINTER),
    SX_FIELD("dimEUnits0","uint32",192,4,SX_POINTER),
    SX_FIELD("dimEUnits1","uint32",196,4,SX_POINTER),
    SX_FIELD("dimEUnits2","uint32",200,4,SX_POINTER),
    SX_FIELD("dimEUnits3","uint32",204,4,SX_POINTER),
    SX_FIELD("dimLabels0","uint32",208,4,SX_POINTER),
    SX_FIELD("dimLabels1","uint32",212,4,SX_POINTER),
    SX_FIELD("dimLabels2","uint32",216,4,SX_POINTER),
    SX_FIELD("dimLabels3","uint32",220,4,SX_POINTER),
    SX_FIELD("waveNoteH","uint32",224,4,SX_POINTER),
    SX_FIELD("whUnused0","int32",228,4,SX_RESERVED),
    SX_FIELD("whUnused1","int32",232,4,SX_RESERVED),
    SX_FIELD("whUnused2","int32",236,4,SX_RESERVED),
    SX_FIELD("whUnused3","int32",240,4,SX_RESERVED),
    SX_FIELD("whUnused4","int32",244,4,SX_RESERVED),
    SX_FIELD("whUnused5","int32",248,4,SX_RESERVED),
    SX_FIELD("whUnused6","int32",252,4,SX_RESERVED),
    SX_FIELD("whUnused7","int32",256,4,SX_RESERVED),
    SX_FIELD("whUnused8","int32",260,4,SX_RESERVED),
    SX_FIELD("whUnused9","int32",264,4,SX_RESERVED),
    SX_FIELD("whUnused10","int32",268,4,SX_RESERVED),
    SX_FIELD("whUnused11","int32",272,4,SX_RESERVED),
    SX_FIELD("whUnused12","int32",276,4,SX_RESERVED),
    SX_FIELD("whUnused13","int32",280,4,SX_RESERVED),
    SX_FIELD("whUnused14","int32",284,4,SX_RESERVED),
    SX_FIELD("whUnused15","int32",288,4,SX_RESERVED),
    SX_FIELD("aModified","int16",292,2,SX_NONE),
    SX_FIELD("wModified","int16",294,2,SX_NONE),
    SX_FIELD("swModified","int16",296,2,SX_NONE),
    SX_FIELD("useBits","char[1]",298,1,SX_NONE),
    SX_FIELD("kindBits","char[1]",299,1,SX_RESERVED),
    SX_FIELD("formula","uint32",300,4,SX_POINTER),
    SX_FIELD("depID","int32",304,4,SX_NONE),
    SX_FIELD("whpad4","int16",308,2,SX_RESERVED),
    SX_FIELD("srcFldr","int16",310,2,SX_NONE),
    SX_FIELD("fileName","uint32",312,4,SX_POINTER),
    SX_FIELD("sIndices","uint32",316,4,SX_POINTER),
};
const sx_layout sxsw_igor_wave5_le = {UINT32_C(0x602d0020),"igor_wave5_le",sxsw_igor_wave5_le_fields,SX_COUNT(sxsw_igor_wave5_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_igor_wave5_be_fields[] = {
    SX_FIELD("next","uint32",0,4,SX_POINTER),
    SX_FIELD("creationDate","uint32",4,4,SX_NONE),
    SX_FIELD("modDate","uint32",8,4,SX_NONE),
    SX_FIELD("npnts","int32",12,4,SX_COUNT_PROP),
    SX_FIELD("type","int16",16,2,SX_ID),
    SX_FIELD("dLock","int16",18,2,SX_RESERVED),
    SX_FIELD("whpad1","char[6]",20,6,SX_RESERVED),
    SX_FIELD("whVersion","int16",26,2,SX_ID),
    SX_FIELD("bname","char[32]",28,32,SX_STRING),
    SX_FIELD("whpad2","int32",60,4,SX_RESERVED),
    SX_FIELD("dFolder","uint32",64,4,SX_POINTER),
    SX_FIELD("nDim0","int32",68,4,SX_COUNT_PROP),
    SX_FIELD("nDim1","int32",72,4,SX_COUNT_PROP),
    SX_FIELD("nDim2","int32",76,4,SX_COUNT_PROP),
    SX_FIELD("nDim3","int32",80,4,SX_COUNT_PROP),
    SX_FIELD("sfA0","float64",84,8,SX_NONE),
    SX_FIELD("sfA1","float64",92,8,SX_NONE),
    SX_FIELD("sfA2","float64",100,8,SX_NONE),
    SX_FIELD("sfA3","float64",108,8,SX_NONE),
    SX_FIELD("sfB0","float64",116,8,SX_NONE),
    SX_FIELD("sfB1","float64",124,8,SX_NONE),
    SX_FIELD("sfB2","float64",132,8,SX_NONE),
    SX_FIELD("sfB3","float64",140,8,SX_NONE),
    SX_FIELD("dataUnits","char[4]",148,4,SX_STRING),
    SX_FIELD("dimUnits","char[16]",152,16,SX_STRING),
    SX_FIELD("fsValid","int16",168,2,SX_NONE),
    SX_FIELD("whpad3","int16",170,2,SX_RESERVED),
    SX_FIELD("topFullScale","float64",172,8,SX_NONE),
    SX_FIELD("botFullScale","float64",180,8,SX_NONE),
    SX_FIELD("dataEUnits","uint32",188,4,SX_POINTER),
    SX_FIELD("dimEUnits0","uint32",192,4,SX_POINTER),
    SX_FIELD("dimEUnits1","uint32",196,4,SX_POINTER),
    SX_FIELD("dimEUnits2","uint32",200,4,SX_POINTER),
    SX_FIELD("dimEUnits3","uint32",204,4,SX_POINTER),
    SX_FIELD("dimLabels0","uint32",208,4,SX_POINTER),
    SX_FIELD("dimLabels1","uint32",212,4,SX_POINTER),
    SX_FIELD("dimLabels2","uint32",216,4,SX_POINTER),
    SX_FIELD("dimLabels3","uint32",220,4,SX_POINTER),
    SX_FIELD("waveNoteH","uint32",224,4,SX_POINTER),
    SX_FIELD("whUnused0","int32",228,4,SX_RESERVED),
    SX_FIELD("whUnused1","int32",232,4,SX_RESERVED),
    SX_FIELD("whUnused2","int32",236,4,SX_RESERVED),
    SX_FIELD("whUnused3","int32",240,4,SX_RESERVED),
    SX_FIELD("whUnused4","int32",244,4,SX_RESERVED),
    SX_FIELD("whUnused5","int32",248,4,SX_RESERVED),
    SX_FIELD("whUnused6","int32",252,4,SX_RESERVED),
    SX_FIELD("whUnused7","int32",256,4,SX_RESERVED),
    SX_FIELD("whUnused8","int32",260,4,SX_RESERVED),
    SX_FIELD("whUnused9","int32",264,4,SX_RESERVED),
    SX_FIELD("whUnused10","int32",268,4,SX_RESERVED),
    SX_FIELD("whUnused11","int32",272,4,SX_RESERVED),
    SX_FIELD("whUnused12","int32",276,4,SX_RESERVED),
    SX_FIELD("whUnused13","int32",280,4,SX_RESERVED),
    SX_FIELD("whUnused14","int32",284,4,SX_RESERVED),
    SX_FIELD("whUnused15","int32",288,4,SX_RESERVED),
    SX_FIELD("aModified","int16",292,2,SX_NONE),
    SX_FIELD("wModified","int16",294,2,SX_NONE),
    SX_FIELD("swModified","int16",296,2,SX_NONE),
    SX_FIELD("useBits","char[1]",298,1,SX_NONE),
    SX_FIELD("kindBits","char[1]",299,1,SX_RESERVED),
    SX_FIELD("formula","uint32",300,4,SX_POINTER),
    SX_FIELD("depID","int32",304,4,SX_NONE),
    SX_FIELD("whpad4","int16",308,2,SX_RESERVED),
    SX_FIELD("srcFldr","int16",310,2,SX_NONE),
    SX_FIELD("fileName","uint32",312,4,SX_POINTER),
    SX_FIELD("sIndices","uint32",316,4,SX_POINTER),
};
const sx_layout sxsw_igor_wave5_be = {UINT32_C(0x602d0022),"igor_wave5_be",sxsw_igor_wave5_be_fields,SX_COUNT(sxsw_igor_wave5_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_lecroy_descriptor_le_fields[] = {
    SX_FIELD("descriptor_name","char[16]",0,16,SX_SIGNATURE),
    SX_FIELD("template_name","char[16]",16,16,SX_ID),
    SX_FIELD("communication_type","int16",32,2,SX_ID),
    SX_FIELD("communication_order","int16",34,2,SX_ID),
    SX_FIELD("descriptor_size","int32",36,4,SX_SIZE),
    SX_FIELD("user_text_size","int32",40,4,SX_SIZE),
    SX_FIELD("reserved_descriptor_size","int32",44,4,SX_RESERVED),
    SX_FIELD("trigger_time_size","int32",48,4,SX_SIZE),
    SX_FIELD("ris_time_size","int32",52,4,SX_SIZE),
    SX_FIELD("reserved_array1_size","int32",56,4,SX_RESERVED),
    SX_FIELD("wave_array1_size","int32",60,4,SX_SIZE),
    SX_FIELD("wave_array2_size","int32",64,4,SX_SIZE),
    SX_FIELD("reserved_array2_size","int32",68,4,SX_RESERVED),
    SX_FIELD("reserved_array3_size","int32",72,4,SX_RESERVED),
    SX_FIELD("instrument_name","char[16]",76,16,SX_STRING),
    SX_FIELD("instrument_number","int32",92,4,SX_ID),
    SX_FIELD("trace_label","char[16]",96,16,SX_STRING),
    SX_FIELD("reserved2","int16",112,2,SX_RESERVED),
    SX_FIELD("reserved3","int16",114,2,SX_RESERVED),
    SX_FIELD("wave_array_count","int32",116,4,SX_COUNT_PROP),
    SX_FIELD("points_per_screen","int32",120,4,SX_COUNT_PROP),
    SX_FIELD("first_valid_point","int32",124,4,SX_NONE),
    SX_FIELD("last_valid_point","int32",128,4,SX_NONE),
    SX_FIELD("first_point","int32",132,4,SX_NONE),
    SX_FIELD("sparsing_factor","int32",136,4,SX_NONE),
    SX_FIELD("segment_index","int32",140,4,SX_ID),
    SX_FIELD("subarray_count","int32",144,4,SX_COUNT_PROP),
    SX_FIELD("sweeps_per_acquisition","int32",148,4,SX_COUNT_PROP),
    SX_FIELD("points_per_pair","int16",152,2,SX_COUNT_PROP),
    SX_FIELD("pair_offset","int16",154,2,SX_NONE),
    SX_FIELD("vertical_gain","float32",156,4,SX_NONE),
    SX_FIELD("vertical_offset","float32",160,4,SX_NONE),
    SX_FIELD("maximum_value","float32",164,4,SX_NONE),
    SX_FIELD("minimum_value","float32",168,4,SX_NONE),
    SX_FIELD("nominal_bits","int16",172,2,SX_NONE),
    SX_FIELD("nominal_subarray_count","int16",174,2,SX_COUNT_PROP),
    SX_FIELD("horizontal_interval","float32",176,4,SX_NONE),
    SX_FIELD("horizontal_offset","float64",180,8,SX_NONE),
    SX_FIELD("pixel_offset","float64",188,8,SX_NONE),
    SX_FIELD("vertical_unit","char[48]",196,48,SX_STRING),
    SX_FIELD("horizontal_unit","char[48]",244,48,SX_STRING),
    SX_FIELD("horizontal_uncertainty","float32",292,4,SX_NONE),
    SX_FIELD("trigger_seconds","float64",296,8,SX_NONE),
    SX_FIELD("trigger_minute","int8",304,1,SX_NONE),
    SX_FIELD("trigger_hour","int8",305,1,SX_NONE),
    SX_FIELD("trigger_day","int8",306,1,SX_NONE),
    SX_FIELD("trigger_month","int8",307,1,SX_NONE),
    SX_FIELD("trigger_year","int16",308,2,SX_NONE),
    SX_FIELD("trigger_unused","int16",310,2,SX_RESERVED),
    SX_FIELD("acquisition_duration","float32",312,4,SX_NONE),
    SX_FIELD("record_type","int16",316,2,SX_ID),
    SX_FIELD("processing_done","int16",318,2,SX_ID),
    SX_FIELD("reserved5","int16",320,2,SX_RESERVED),
    SX_FIELD("ris_sweeps","int16",322,2,SX_COUNT_PROP),
    SX_FIELD("timebase","int16",324,2,SX_ID),
    SX_FIELD("vertical_coupling","int16",326,2,SX_ID),
    SX_FIELD("probe_attenuation","float32",328,4,SX_NONE),
    SX_FIELD("fixed_vertical_gain","int16",332,2,SX_ID),
    SX_FIELD("bandwidth_limit","uint16",334,2,SX_ID),
    SX_FIELD("vertical_vernier","float32",336,4,SX_NONE),
    SX_FIELD("acquisition_vertical_offset","float32",340,4,SX_NONE),
    SX_FIELD("wave_source","int16",344,2,SX_ID),
};
const sx_layout sxsw_lecroy_descriptor_le = {UINT32_C(0x602d0024),"lecroy_descriptor_le",sxsw_lecroy_descriptor_le_fields,SX_COUNT(sxsw_lecroy_descriptor_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_lecroy_descriptor_be_fields[] = {
    SX_FIELD("descriptor_name","char[16]",0,16,SX_SIGNATURE),
    SX_FIELD("template_name","char[16]",16,16,SX_ID),
    SX_FIELD("communication_type","int16",32,2,SX_ID),
    SX_FIELD("communication_order","int16",34,2,SX_ID),
    SX_FIELD("descriptor_size","int32",36,4,SX_SIZE),
    SX_FIELD("user_text_size","int32",40,4,SX_SIZE),
    SX_FIELD("reserved_descriptor_size","int32",44,4,SX_RESERVED),
    SX_FIELD("trigger_time_size","int32",48,4,SX_SIZE),
    SX_FIELD("ris_time_size","int32",52,4,SX_SIZE),
    SX_FIELD("reserved_array1_size","int32",56,4,SX_RESERVED),
    SX_FIELD("wave_array1_size","int32",60,4,SX_SIZE),
    SX_FIELD("wave_array2_size","int32",64,4,SX_SIZE),
    SX_FIELD("reserved_array2_size","int32",68,4,SX_RESERVED),
    SX_FIELD("reserved_array3_size","int32",72,4,SX_RESERVED),
    SX_FIELD("instrument_name","char[16]",76,16,SX_STRING),
    SX_FIELD("instrument_number","int32",92,4,SX_ID),
    SX_FIELD("trace_label","char[16]",96,16,SX_STRING),
    SX_FIELD("reserved2","int16",112,2,SX_RESERVED),
    SX_FIELD("reserved3","int16",114,2,SX_RESERVED),
    SX_FIELD("wave_array_count","int32",116,4,SX_COUNT_PROP),
    SX_FIELD("points_per_screen","int32",120,4,SX_COUNT_PROP),
    SX_FIELD("first_valid_point","int32",124,4,SX_NONE),
    SX_FIELD("last_valid_point","int32",128,4,SX_NONE),
    SX_FIELD("first_point","int32",132,4,SX_NONE),
    SX_FIELD("sparsing_factor","int32",136,4,SX_NONE),
    SX_FIELD("segment_index","int32",140,4,SX_ID),
    SX_FIELD("subarray_count","int32",144,4,SX_COUNT_PROP),
    SX_FIELD("sweeps_per_acquisition","int32",148,4,SX_COUNT_PROP),
    SX_FIELD("points_per_pair","int16",152,2,SX_COUNT_PROP),
    SX_FIELD("pair_offset","int16",154,2,SX_NONE),
    SX_FIELD("vertical_gain","float32",156,4,SX_NONE),
    SX_FIELD("vertical_offset","float32",160,4,SX_NONE),
    SX_FIELD("maximum_value","float32",164,4,SX_NONE),
    SX_FIELD("minimum_value","float32",168,4,SX_NONE),
    SX_FIELD("nominal_bits","int16",172,2,SX_NONE),
    SX_FIELD("nominal_subarray_count","int16",174,2,SX_COUNT_PROP),
    SX_FIELD("horizontal_interval","float32",176,4,SX_NONE),
    SX_FIELD("horizontal_offset","float64",180,8,SX_NONE),
    SX_FIELD("pixel_offset","float64",188,8,SX_NONE),
    SX_FIELD("vertical_unit","char[48]",196,48,SX_STRING),
    SX_FIELD("horizontal_unit","char[48]",244,48,SX_STRING),
    SX_FIELD("horizontal_uncertainty","float32",292,4,SX_NONE),
    SX_FIELD("trigger_seconds","float64",296,8,SX_NONE),
    SX_FIELD("trigger_minute","int8",304,1,SX_NONE),
    SX_FIELD("trigger_hour","int8",305,1,SX_NONE),
    SX_FIELD("trigger_day","int8",306,1,SX_NONE),
    SX_FIELD("trigger_month","int8",307,1,SX_NONE),
    SX_FIELD("trigger_year","int16",308,2,SX_NONE),
    SX_FIELD("trigger_unused","int16",310,2,SX_RESERVED),
    SX_FIELD("acquisition_duration","float32",312,4,SX_NONE),
    SX_FIELD("record_type","int16",316,2,SX_ID),
    SX_FIELD("processing_done","int16",318,2,SX_ID),
    SX_FIELD("reserved5","int16",320,2,SX_RESERVED),
    SX_FIELD("ris_sweeps","int16",322,2,SX_COUNT_PROP),
    SX_FIELD("timebase","int16",324,2,SX_ID),
    SX_FIELD("vertical_coupling","int16",326,2,SX_ID),
    SX_FIELD("probe_attenuation","float32",328,4,SX_NONE),
    SX_FIELD("fixed_vertical_gain","int16",332,2,SX_ID),
    SX_FIELD("bandwidth_limit","uint16",334,2,SX_ID),
    SX_FIELD("vertical_vernier","float32",336,4,SX_NONE),
    SX_FIELD("acquisition_vertical_offset","float32",340,4,SX_NONE),
    SX_FIELD("wave_source","int16",344,2,SX_ID),
};
const sx_layout sxsw_lecroy_descriptor_be = {UINT32_C(0x602d0028),"lecroy_descriptor_be",sxsw_lecroy_descriptor_be_fields,SX_COUNT(sxsw_lecroy_descriptor_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_grib2_section_fields[] = {
    SX_FIELD("section_size","uint32",0,4,SX_SIZE),
    SX_FIELD("section_number","uint8",4,1,SX_ID),
};
const sx_layout sxsw_grib2_section = {UINT32_C(0x602d002c),"grib2_section",sxsw_grib2_section_fields,SX_COUNT(sxsw_grib2_section_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_grib2_bitmap_fields[] = {
    SX_FIELD("section_size","uint32",0,4,SX_SIZE),
    SX_FIELD("section_number","uint8",4,1,SX_ID),
    SX_FIELD("bitmap_indicator","uint8",5,1,SX_ID),
};
const sx_layout sxsw_grib2_bitmap = {UINT32_C(0x602d0031),"grib2_bitmap",sxsw_grib2_bitmap_fields,SX_COUNT(sxsw_grib2_bitmap_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_wmo_end_fields[] = {
    SX_FIELD("marker","char[4]",0,4,SX_SIGNATURE),
};
const sx_layout sxsw_wmo_end = {UINT32_C(0x602d0032),"wmo_end",sxsw_wmo_end_fields,SX_COUNT(sxsw_wmo_end_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_stata_type_le_fields[] = {
    SX_FIELD("type","uint16",0,2,SX_ID),
};
const sx_layout sxsw_stata_type_le = {UINT32_C(0x602d004d),"stata_type_le",sxsw_stata_type_le_fields,SX_COUNT(sxsw_stata_type_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_stata_type_be_fields[] = {
    SX_FIELD("type","uint16",0,2,SX_ID),
};
const sx_layout sxsw_stata_type_be = {UINT32_C(0x602d0054),"stata_type_be",sxsw_stata_type_be_fields,SX_COUNT(sxsw_stata_type_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_rosbag_op_fields[] = {
    SX_FIELD("operation","uint8",0,1,SX_ID),
};
const sx_layout sxsw_rosbag_op = {UINT32_C(0x602d005b),"rosbag_op",sxsw_rosbag_op_fields,SX_COUNT(sxsw_rosbag_op_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_dicom_preamble_fields[] = {
    SX_FIELD("preamble","uint8[128]",0,128,SX_NONE),
    SX_FIELD("signature","char[4]",128,4,SX_SIGNATURE),
};
static const sx_layout sxsw_dicom_preamble = {UINT32_C(0x602d0067),"dicom_preamble",sxsw_dicom_preamble_fields,SX_COUNT(sxsw_dicom_preamble_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_dicom_implicit_le_fields[] = {
    SX_FIELD("group","uint16",0,2,SX_ID),
    SX_FIELD("element","uint16",2,2,SX_ID),
    SX_FIELD("value_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxsw_dicom_implicit_le = {UINT32_C(0x602d0068),"dicom_implicit_le",sxsw_dicom_implicit_le_fields,SX_COUNT(sxsw_dicom_implicit_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_dicom_short_le_fields[] = {
    SX_FIELD("group","uint16",0,2,SX_ID),
    SX_FIELD("element","uint16",2,2,SX_ID),
    SX_FIELD("value_representation","char[2]",4,2,SX_ID),
    SX_FIELD("value_size","uint16",6,2,SX_SIZE),
};
static const sx_layout sxsw_dicom_short_le = {UINT32_C(0x602d0069),"dicom_short_le",sxsw_dicom_short_le_fields,SX_COUNT(sxsw_dicom_short_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_dicom_wide_le_fields[] = {
    SX_FIELD("group","uint16",0,2,SX_ID),
    SX_FIELD("element","uint16",2,2,SX_ID),
    SX_FIELD("value_representation","char[2]",4,2,SX_ID),
    SX_FIELD("reserved","uint16",6,2,SX_RESERVED),
    SX_FIELD("value_size","uint32",8,4,SX_SIZE),
};
static const sx_layout sxsw_dicom_wide_le = {UINT32_C(0x602d006a),"dicom_wide_le",sxsw_dicom_wide_le_fields,SX_COUNT(sxsw_dicom_wide_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_dicom_implicit_be_fields[] = {
    SX_FIELD("group","uint16",0,2,SX_ID),
    SX_FIELD("element","uint16",2,2,SX_ID),
    SX_FIELD("value_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxsw_dicom_implicit_be = {UINT32_C(0x602d006b),"dicom_implicit_be",sxsw_dicom_implicit_be_fields,SX_COUNT(sxsw_dicom_implicit_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_dicom_short_be_fields[] = {
    SX_FIELD("group","uint16",0,2,SX_ID),
    SX_FIELD("element","uint16",2,2,SX_ID),
    SX_FIELD("value_representation","char[2]",4,2,SX_ID),
    SX_FIELD("value_size","uint16",6,2,SX_SIZE),
};
static const sx_layout sxsw_dicom_short_be = {UINT32_C(0x602d006c),"dicom_short_be",sxsw_dicom_short_be_fields,SX_COUNT(sxsw_dicom_short_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_dicom_wide_be_fields[] = {
    SX_FIELD("group","uint16",0,2,SX_ID),
    SX_FIELD("element","uint16",2,2,SX_ID),
    SX_FIELD("value_representation","char[2]",4,2,SX_ID),
    SX_FIELD("reserved","uint16",6,2,SX_RESERVED),
    SX_FIELD("value_size","uint32",8,4,SX_SIZE),
};
static const sx_layout sxsw_dicom_wide_be = {UINT32_C(0x602d006d),"dicom_wide_be",sxsw_dicom_wide_be_fields,SX_COUNT(sxsw_dicom_wide_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_dicom_meta_size_fields[] = {
    SX_FIELD("group_length","uint32",0,4,SX_SIZE),
};
static const sx_layout sxsw_dicom_meta_size = {UINT32_C(0x602d006e),"dicom_meta_size",sxsw_dicom_meta_size_fields,SX_COUNT(sxsw_dicom_meta_size_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_dicom_frame_offset_fields[] = {
    SX_FIELD("offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxsw_dicom_frame_offset = {UINT32_C(0x602d006f),"dicom_frame_offset",sxsw_dicom_frame_offset_fields,SX_COUNT(sxsw_dicom_frame_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_tecplot_variable_type_le_fields[] = {
    SX_FIELD("type","int32",0,4,SX_ID),
};
const sx_layout sxsw_tecplot_variable_type_le = {UINT32_C(0x602d0076),"tecplot_variable_type_le",sxsw_tecplot_variable_type_le_fields,SX_COUNT(sxsw_tecplot_variable_type_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_tecplot_variable_type_be_fields[] = {
    SX_FIELD("type","int32",0,4,SX_ID),
};
const sx_layout sxsw_tecplot_variable_type_be = {UINT32_C(0x602d007f),"tecplot_variable_type_be",sxsw_tecplot_variable_type_be_fields,SX_COUNT(sxsw_tecplot_variable_type_be_fields),SX_BE};
static const sx_layout *const sx_sciencewire_layouts[] = {
    &sxsw_fits_card,
    &sxsw_fits_integer_card,
    &sxsw_xport_header_record,
    &sxsw_xport_namestr,
    &sxsw_sav_header_le,
    &sxsw_sav_variable_le,
    &sxsw_sav_extension_le,
    &sxsw_sav_count_record_le,
    &sxsw_sav_dictionary_end_le,
    &sxsw_sav_label_size_le,
    &sxsw_sav_variable_index_le,
    &sxsw_sav_value_label_le,
    &sxsw_sav_machine_integer_le,
    &sxsw_sav_header_be,
    &sxsw_sav_variable_be,
    &sxsw_sav_extension_be,
    &sxsw_sav_count_record_be,
    &sxsw_sav_dictionary_end_be,
    &sxsw_sav_label_size_be,
    &sxsw_sav_variable_index_be,
    &sxsw_sav_value_label_be,
    &sxsw_sav_machine_integer_be,
    &sxsw_sav_document_line,
    &sxsw_bgen_header,
    &sxsw_bgen_flags,
    &sxsw_bgen_sample_header,
    &sxsw_bgen_string16,
    &sxsw_bgen_string32,
    &sxsw_bgen_variant_sample_count,
    &sxsw_bgen_variant_position,
    &sxsw_igor_binary5_le,
    &sxsw_igor_wave5_le,
    &sxsw_igor_binary5_be,
    &sxsw_igor_wave5_be,
    &sxsw_spider_header_le,
    &sxsw_lecroy_descriptor_le,
    &sxsw_lecroy_trigger_time_le,
    &sxsw_lecroy_ris_time_le,
    &sxsw_spider_header_be,
    &sxsw_lecroy_descriptor_be,
    &sxsw_lecroy_trigger_time_be,
    &sxsw_lecroy_ris_time_be,
    &sxsw_grib2_indicator,
    &sxsw_grib2_section,
    &sxsw_grib2_identification,
    &sxsw_grib2_grid,
    &sxsw_grib2_product,
    &sxsw_grib2_representation,
    &sxsw_grib2_bitmap,
    &sxsw_wmo_end,
    &sxsw_bufr4_indicator,
    &sxsw_bufr4_identification,
    &sxsw_bufr4_section,
    &sxsw_bufr4_data_description,
    &sxsw_bufr_descriptor,
    &sxsw_openephys_record,
    &sxsw_openephys_marker,
    &sxsw_cnt_setup,
    &sxsw_cnt_channel,
    &sxsw_cnt_event_table,
    &sxsw_cnt_event1,
    &sxsw_cnt_event2,
    &sxsw_cnt_event3,
    &sxsw_stata117_prefix_le,
    &sxsw_stata117_label_size_le,
    &sxsw_stata117_variable_name,
    &sxsw_stata117_display_format,
    &sxsw_stata117_value_label_name,
    &sxsw_stata117_variable_label,
    &sxsw_stata118_prefix_le,
    &sxsw_stata118_label_size_le,
    &sxsw_stata118_variable_name,
    &sxsw_stata118_display_format,
    &sxsw_stata118_value_label_name,
    &sxsw_stata118_variable_label,
    &sxsw_stata_map_le,
    &sxsw_stata_type_le,
    &sxsw_stata_sort_index_le,
    &sxsw_stata117_prefix_be,
    &sxsw_stata117_label_size_be,
    &sxsw_stata118_prefix_be,
    &sxsw_stata118_label_size_be,
    &sxsw_stata_map_be,
    &sxsw_stata_type_be,
    &sxsw_stata_sort_index_be,
    &sxsw_stata_timestamp_size,
    &sxsw_rosbag_signature,
    &sxsw_rosbag_header_size,
    &sxsw_rosbag_field_size,
    &sxsw_rosbag_data_size,
    &sxsw_rosbag_op,
    &sxsw_rosbag_conn,
    &sxsw_rosbag_size,
    &sxsw_rosbag_count,
    &sxsw_rosbag_ver,
    &sxsw_rosbag_index_pos,
    &sxsw_rosbag_chunk_pos,
    &sxsw_rosbag_conn_count,
    &sxsw_rosbag_chunk_count,
    &sxsw_rosbag_time,
    &sxsw_rosbag_index,
    &sxsw_rosbag_connection_count,
    &sxsw_dicom_preamble,
    &sxsw_dicom_implicit_le,
    &sxsw_dicom_short_le,
    &sxsw_dicom_wide_le,
    &sxsw_dicom_implicit_be,
    &sxsw_dicom_short_be,
    &sxsw_dicom_wide_be,
    &sxsw_dicom_meta_size,
    &sxsw_dicom_frame_offset,
    &sxsw_tecplot_prefix_le,
    &sxsw_tecplot_codepoint_le,
    &sxsw_tecplot_variable_count_le,
    &sxsw_tecplot_marker_le,
    &sxsw_tecplot_ordered_zone_le,
    &sxsw_tecplot_auxiliary_flag_le,
    &sxsw_tecplot_variable_type_le,
    &sxsw_tecplot_data_flags_le,
    &sxsw_tecplot_range_le,
    &sxsw_tecplot_prefix_be,
    &sxsw_tecplot_codepoint_be,
    &sxsw_tecplot_variable_count_be,
    &sxsw_tecplot_marker_be,
    &sxsw_tecplot_ordered_zone_be,
    &sxsw_tecplot_auxiliary_flag_be,
    &sxsw_tecplot_variable_type_be,
    &sxsw_tecplot_data_flags_be,
    &sxsw_tecplot_range_be,
};
static bool sx_sciencewire_static_comment(xx_data_struct_record *r,uint32_t id)
{
    if(!r||!r->name||id<0x602d0000U||id>=0x602e0000U)return true;
    const wchar_t *text=NULL;switch(id){
    case 0x602d0001U:
        if(!xx_rt_wcscmp(r->name,L"value_and_comment"))text=L"FITS card text; quoted slashes are not assumed to start a comment.";
        break;
    case 0x602d0002U:
        if(!xx_rt_wcscmp(r->name,L"integer_text"))text=L"Signed decimal FITS integer stored in a twenty-character text field.";
        break;
    case 0x602d0004U:
        if(!xx_rt_wcscmp(r->name,L"type"))text=L"1=numeric, 2=character.";
        if(!xx_rt_wcscmp(r->name,L"observation_offset"))text=L"Byte displacement within one observation, not an absolute file position.";
        break;
    case 0x602d0005U:
        if(!xx_rt_wcscmp(r->name,L"case_size"))text=L"Number of eight-byte slots per case.";
        break;
    case 0x602d0006U:
        if(!xx_rt_wcscmp(r->name,L"variable_type"))text=L"0=numeric, positive=string byte length, -1=continuation slot.";
        if(!xx_rt_wcscmp(r->name,L"missing_value_count"))text=L"Negative values encode a missing-value range.";
        break;
    case 0x602d000cU:
        if(!xx_rt_wcscmp(r->name,L"value_bytes"))text=L"Stored numeric or string value, interpreted through the linked variable.";
        break;
    case 0x602d000eU:
        if(!xx_rt_wcscmp(r->name,L"case_size"))text=L"Number of eight-byte slots per case.";
        break;
    case 0x602d000fU:
        if(!xx_rt_wcscmp(r->name,L"variable_type"))text=L"0=numeric, positive=string byte length, -1=continuation slot.";
        if(!xx_rt_wcscmp(r->name,L"missing_value_count"))text=L"Negative values encode a missing-value range.";
        break;
    case 0x602d0015U:
        if(!xx_rt_wcscmp(r->name,L"value_bytes"))text=L"Stored numeric or string value, interpreted through the linked variable.";
        break;
    case 0x602d0018U:
        if(!xx_rt_wcscmp(r->name,L"first_variant_offset"))text=L"Relative to byte four; add four to locate the first variant.";
        break;
    case 0x602d0019U:
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Bits0..1 compression, bits2..5 layout, bit31 sample identifiers. Native scope is uncompressed layout1.";
        break;
    case 0x602d001eU:
        if(!xx_rt_wcscmp(r->name,L"position"))text=L"One-based chromosome coordinate, not a byte offset.";
        break;
    case 0x602d0020U:
        if(!xx_rt_wcscmp(r->name,L"next"))text=L"In-memory pointer slot preserved verbatim; not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"creationDate"))text=L"Seconds since1904-01-01.";
        if(!xx_rt_wcscmp(r->name,L"modDate"))text=L"Seconds since1904-01-01.";
        if(!xx_rt_wcscmp(r->name,L"dFolder"))text=L"In-memory pointer slot preserved verbatim; not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"dataEUnits"))text=L"In-memory pointer slot preserved verbatim; not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"dimEUnits0"))text=L"In-memory pointer slot preserved verbatim; not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"dimEUnits1"))text=L"In-memory pointer slot preserved verbatim; not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"dimEUnits2"))text=L"In-memory pointer slot preserved verbatim; not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"dimEUnits3"))text=L"In-memory pointer slot preserved verbatim; not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"dimLabels0"))text=L"In-memory pointer slot preserved verbatim; not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"dimLabels1"))text=L"In-memory pointer slot preserved verbatim; not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"dimLabels2"))text=L"In-memory pointer slot preserved verbatim; not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"dimLabels3"))text=L"In-memory pointer slot preserved verbatim; not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"waveNoteH"))text=L"In-memory pointer slot preserved verbatim; not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"formula"))text=L"In-memory pointer slot preserved verbatim; not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"fileName"))text=L"In-memory pointer slot preserved verbatim; not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"sIndices"))text=L"In-memory pointer slot preserved verbatim; not a file offset.";
        break;
    case 0x602d0022U:
        if(!xx_rt_wcscmp(r->name,L"next"))text=L"In-memory pointer slot preserved verbatim; not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"creationDate"))text=L"Seconds since1904-01-01.";
        if(!xx_rt_wcscmp(r->name,L"modDate"))text=L"Seconds since1904-01-01.";
        if(!xx_rt_wcscmp(r->name,L"dFolder"))text=L"In-memory pointer slot preserved verbatim; not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"dataEUnits"))text=L"In-memory pointer slot preserved verbatim; not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"dimEUnits0"))text=L"In-memory pointer slot preserved verbatim; not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"dimEUnits1"))text=L"In-memory pointer slot preserved verbatim; not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"dimEUnits2"))text=L"In-memory pointer slot preserved verbatim; not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"dimEUnits3"))text=L"In-memory pointer slot preserved verbatim; not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"dimLabels0"))text=L"In-memory pointer slot preserved verbatim; not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"dimLabels1"))text=L"In-memory pointer slot preserved verbatim; not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"dimLabels2"))text=L"In-memory pointer slot preserved verbatim; not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"dimLabels3"))text=L"In-memory pointer slot preserved verbatim; not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"waveNoteH"))text=L"In-memory pointer slot preserved verbatim; not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"formula"))text=L"In-memory pointer slot preserved verbatim; not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"fileName"))text=L"In-memory pointer slot preserved verbatim; not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"sIndices"))text=L"In-memory pointer slot preserved verbatim; not a file offset.";
        break;
    case 0x602d0023U:
        if(!xx_rt_wcscmp(r->name,L"x_offset"))text=L"Spatial translation, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"y_offset"))text=L"Spatial translation, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"z_offset"))text=L"Spatial translation, not a file offset.";
        break;
    case 0x602d0024U:
        if(!xx_rt_wcscmp(r->name,L"pair_offset"))text=L"Sample position, not a file byte offset.";
        if(!xx_rt_wcscmp(r->name,L"vertical_offset"))text=L"Signal translation, not a byte offset.";
        if(!xx_rt_wcscmp(r->name,L"horizontal_offset"))text=L"Time origin, not a byte offset.";
        if(!xx_rt_wcscmp(r->name,L"pixel_offset"))text=L"Time quantity, not a byte offset.";
        if(!xx_rt_wcscmp(r->name,L"acquisition_vertical_offset"))text=L"Signal translation, not a byte offset.";
        break;
    case 0x602d0027U:
        if(!xx_rt_wcscmp(r->name,L"x_offset"))text=L"Spatial translation, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"y_offset"))text=L"Spatial translation, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"z_offset"))text=L"Spatial translation, not a file offset.";
        break;
    case 0x602d0028U:
        if(!xx_rt_wcscmp(r->name,L"pair_offset"))text=L"Sample position, not a file byte offset.";
        if(!xx_rt_wcscmp(r->name,L"vertical_offset"))text=L"Signal translation, not a byte offset.";
        if(!xx_rt_wcscmp(r->name,L"horizontal_offset"))text=L"Time origin, not a byte offset.";
        if(!xx_rt_wcscmp(r->name,L"pixel_offset"))text=L"Time quantity, not a byte offset.";
        if(!xx_rt_wcscmp(r->name,L"acquisition_vertical_offset"))text=L"Signal translation, not a byte offset.";
        break;
    case 0x602d0036U:
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Bit7 observed data; bit6 compressed data.";
        break;
    case 0x602d0037U:
        if(!xx_rt_wcscmp(r->name,L"descriptor"))text=L"Packed F-X-Y descriptor:2bits F,6bits X,8bits Y.";
        break;
    case 0x602d0038U:
        if(!xx_rt_wcscmp(r->name,L"timestamp"))text=L"Sample-clock ticks, not Unix time.";
        break;
    case 0x602d003aU:
        if(!xx_rt_wcscmp(r->name,L"next_file"))text=L"Legacy next-file pointer slot, not an on-disk byte position.";
        if(!xx_rt_wcscmp(r->name,L"sample_rate"))text=L"Samples per second.";
        if(!xx_rt_wcscmp(r->name,L"channel_block_size"))text=L"Channel-block byte stride; zero or one selects interleaved samples.";
        break;
    case 0x602d003cU:
        if(!xx_rt_wcscmp(r->name,L"offset"))text=L"Reserved zero in the supported event-table variant.";
        break;
    case 0x602d003dU:
        if(!xx_rt_wcscmp(r->name,L"offset"))text=L"Absolute byte position in the sample data.";
        break;
    case 0x602d003eU:
        if(!xx_rt_wcscmp(r->name,L"offset"))text=L"Absolute byte position in the sample data.";
        break;
    case 0x602d003fU:
        if(!xx_rt_wcscmp(r->name,L"global_sample_frame"))text=L"Frame units measured from the file origin; multiply by channels and sample width to obtain a byte position.";
        break;
    case 0x602d0064U:
        if(!xx_rt_wcscmp(r->name,L"nanoseconds"))text=L"Fractional nanoseconds within the second.";
        break;
    case 0x602d0065U:
        if(!xx_rt_wcscmp(r->name,L"record_offset"))text=L"Relative to the beginning of the uncompressed chunk data.";
        break;
    case 0x602d0068U:
        if(!xx_rt_wcscmp(r->name,L"value_size"))text=L"0xffffffff means undefined length.";
        break;
    case 0x602d006aU:
        if(!xx_rt_wcscmp(r->name,L"value_size"))text=L"0xffffffff means undefined length.";
        break;
    case 0x602d006bU:
        if(!xx_rt_wcscmp(r->name,L"value_size"))text=L"0xffffffff means undefined length.";
        break;
    case 0x602d006dU:
        if(!xx_rt_wcscmp(r->name,L"value_size"))text=L"0xffffffff means undefined length.";
        break;
    case 0x602d006fU:
        if(!xx_rt_wcscmp(r->name,L"offset"))text=L"Relative to the first fragment item after the basic offset table.";
        break;
    case 0x602d0071U:
        if(!xx_rt_wcscmp(r->name,L"character"))text=L"ASCII character stored as a signed 32-bit integer, including the terminating zero.";
        break;
    case 0x602d0073U:
        if(!xx_rt_wcscmp(r->name,L"marker"))text=L"299.0 identifies a zone;357.0 ends the header.";
        break;
    case 0x602d007aU:
        if(!xx_rt_wcscmp(r->name,L"character"))text=L"ASCII character stored as a signed 32-bit integer, including the terminating zero.";
        break;
    case 0x602d007cU:
        if(!xx_rt_wcscmp(r->name,L"marker"))text=L"299.0 identifies a zone;357.0 ends the header.";
        break;
    default:break;}return !text||xx_data_struct_record_set_comment(r,text);
}
static bool sx_sciencewire_comment(xx_data_struct_record *r,uint32_t id)
{
 if(!sx_sciencewire_static_comment(r,id))return false;
 if(!r||!r->name||id<0x602d0000U||id>=0x602e0000U||r->value.type==XX_VAR_TYPE_FLOAT||r->value.type==XX_VAR_TYPE_DOUBLE||r->value.type==XX_VAR_TYPE_STRING||r->value.type==XX_VAR_TYPE_BYTES)return true;
 uint64_t v=xx_var_get_u64(&r->value);const wchar_t *text=NULL;
 if(id==sxsw_rosbag_op.id)switch(v){case 2:text=L"MSG_DATA";break;case 3:text=L"BAG_HEADER";break;case 4:text=L"INDEX_DATA";break;case 5:text=L"CHUNK";break;case 6:text=L"CHUNK_INFO";break;case 7:text=L"CONNECTION";break;default:break;}
 if((id==sxsw_tecplot_variable_type_le.id||id==sxsw_tecplot_variable_type_be.id)&&!xx_rt_wcscmp(r->name,L"type"))switch(v){case 1:text=L"FLOAT";break;case 2:text=L"DOUBLE";break;case 3:text=L"LONGINT";break;case 4:text=L"SHORTINT";break;case 5:text=L"BYTE";break;default:break;}
 if((id==sxsw_stata_type_le.id||id==sxsw_stata_type_be.id)&&!xx_rt_wcscmp(r->name,L"type"))switch(v){case 65526:text=L"DOUBLE";break;case 65527:text=L"FLOAT";break;case 65528:text=L"LONG";break;case 65529:text=L"INT";break;case 65530:text=L"BYTE";break;default:if(v&&v<=2045)text=L"Fixed-width string";break;}
 if((id==sxsw_igor_wave5_le.id||id==sxsw_igor_wave5_be.id)&&!xx_rt_wcscmp(r->name,L"type"))switch(v){case 2:text=L"NT_FP32";break;case 4:text=L"NT_FP64";break;case 8:text=L"NT_I8";break;case 16:text=L"NT_I16";break;case 32:text=L"NT_I32";break;case 72:text=L"NT_I8|NT_UNSIGNED";break;case 80:text=L"NT_I16|NT_UNSIGNED";break;case 96:text=L"NT_I32|NT_UNSIGNED";break;default:break;}

 if(id==sxsw_lecroy_descriptor_le.id||id==sxsw_lecroy_descriptor_be.id){
  if(!xx_rt_wcscmp(r->name,L"communication_type")){if(v==0)text=L"BYTE";else if(v==1)text=L"WORD";}
  if(!xx_rt_wcscmp(r->name,L"communication_order")){if(v==0)text=L"HIFIRST";else if(v==1)text=L"LOFIRST";}
  if(!xx_rt_wcscmp(r->name,L"bandwidth_limit")){if(v==0)text=L"OFF";else if(v==1)text=L"ON";}
  if(!xx_rt_wcscmp(r->name,L"wave_source")){static const wchar_t*const names[]={L"CHANNEL_1",L"CHANNEL_2",L"CHANNEL_3",L"CHANNEL_4"};if(v<4)text=names[v];else if(v==9)text=L"UNKNOWN";}
  if(!xx_rt_wcscmp(r->name,L"record_type")){static const wchar_t*const names[]={L"SINGLE_SWEEP",L"INTERLEAVED",L"HISTOGRAM",L"GRAPH",L"FILTER_COEFFICIENT",L"COMPLEX",L"EXTREMA",L"SEQUENCE_OBSOLETE",L"CENTERED_RIS",L"PEAK_DETECT"};if(v<SX_COUNT(names))text=names[v];}
  if(!xx_rt_wcscmp(r->name,L"processing_done")){static const wchar_t*const names[]={L"NO_PROCESSING",L"FIR_FILTER",L"INTERPOLATED",L"SPARSED",L"AUTOSCALED",L"NO_RESULT",L"ROLLING",L"CUMULATIVE"};if(v<SX_COUNT(names))text=names[v];}
 }
 if(!xx_rt_wcscmp(r->name,L"section_number")&&id>=sxsw_grib2_section.id&&id<=sxsw_grib2_bitmap.id){static const wchar_t*const names[]={L"INDICATOR",L"IDENTIFICATION",L"LOCAL_USE",L"GRID_DEFINITION",L"PRODUCT_DEFINITION",L"DATA_REPRESENTATION",L"BITMAP",L"DATA"};if(v<SX_COUNT(names))text=names[v];}
 return !text||xx_data_struct_record_set_comment(r,text);
}
uint16_t sxsw16(const uint8_t *p,bool be){return xx_data_get_u16(p,2,0,be);}
uint32_t sxsw32(const uint8_t *p,bool be){return xx_data_get_u32(p,4,0,be);}
bool sxsw_span(sx_context *c,int64_t at,uint64_t n){return c&&!xx_pd_is_stopped(c->pd)&&at>=0&&at<=c->size&&n<=(uint64_t)(c->size-at);}
bool sxsw_add(sx_context *c,const sx_layout *l,int64_t at,int64_t bytes){return sxsw_span(c,at,(uint64_t)bytes)&&(c->count>=32000||sx_add(c,l,at,bytes));}
bool sxsw_table(sx_context *c,const sx_layout *l,int64_t at,int64_t bytes,uint64_t count){return bytes>0&&count<=INT64_MAX/(uint64_t)bytes&&sxsw_span(c,at,(uint64_t)bytes*count)&&(c->count>=32000||sx_table(c,l,at,bytes,count));}
static int sxsw_order(const void *a,const void *b){const xx_data_struct *x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:x->total_size<y->total_size?-1:x->total_size>y->total_size?1:0;}
static bool sxsw_finish(sx_context *c)
{
 size_t n=c->count;if(!n)return false;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxsw_order);
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,bytes=c->items[i].total_size;if(at<end)return false;if(at>end&&!sx_raw(c,end,at-end))return false;end=at+bytes;}
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxsw_order);return !c->failed&&!xx_pd_is_stopped(c->pd);
}
bool sxsw_text_integer(const uint8_t *p,size_t n,int64_t *out)
{
 bool negative=false,digit=false,space=false;uint64_t v=0;size_t i=0;
 while(i<n&&p[i]==' ')i++;if(i<n&&(p[i]=='-'||p[i]=='+'))negative=p[i++]=='-';
 for(;i<n;i++){if(p[i]==' '){space=true;continue;}if(space||p[i]<'0'||p[i]>'9'||v>(INT64_MAX-(p[i]-'0'))/10)return false;digit=true;v=v*10+p[i]-'0';}
 *out=negative?-(int64_t)v:(int64_t)v;return digit;
}
typedef struct {uint16_t group,element;char vr[3];uint32_t bytes;unsigned header;} sxsw_dc_element;
static bool sxsw_dc_header(sx_context *c,int64_t at,int64_t end,bool be,bool explicit_vr,sxsw_dc_element *v)
{
 uint8_t b[12];if(at>end-8||!sx_read(c,at,b,8))return false;v->group=sxsw16(b,be);v->element=sxsw16(b+2,be);v->vr[0]=v->vr[1]=v->vr[2]=0;v->header=8;
 const sx_layout *l=be?&sxsw_dicom_implicit_be:&sxsw_dicom_implicit_le;
 if(explicit_vr&&v->group!=0xfffe){v->vr[0]=(char)b[4];v->vr[1]=(char)b[5];
  bool wide=b[4]=='O'||(b[4]=='S'&&(b[5]=='Q'||b[5]=='V'))||(b[4]=='U'&&(b[5]=='C'||b[5]=='N'||b[5]=='R'||b[5]=='T'||b[5]=='V'));
  if(wide){if(at>end-12||!sx_read(c,at+8,b+8,4))return false;v->bytes=sxsw32(b+8,be);v->header=12;l=be?&sxsw_dicom_wide_be:&sxsw_dicom_wide_le;}
  else{v->bytes=sxsw16(b+6,be);l=be?&sxsw_dicom_short_be:&sxsw_dicom_short_le;}
 }else v->bytes=sxsw32(b+4,be);
 return sxsw_add(c,l,at,v->header);
}
static bool sxsw_dc_dataset(sx_context *c,int64_t *cursor,int64_t end,bool be,bool explicit_vr,unsigned depth,bool undefined);
static bool sxsw_dc_sequence(sx_context *c,int64_t *cursor,int64_t end,bool be,bool explicit_vr,unsigned depth,bool undefined,bool pixels)
{
 if(depth>32)return false;int64_t at=*cursor;unsigned index=0;
 while(at<end){sxsw_dc_element v;if((pixels&&index>=4097)||!sxsw_dc_header(c,at,end,be,false,&v)||v.group!=0xfffe)return false;at+=v.header;
  if(v.element==0xe0dd){if(!undefined||v.bytes)return false;*cursor=at;return true;}
  if(v.element!=0xe000)return false;
  if(pixels){if(v.bytes==UINT32_MAX||v.bytes>(uint64_t)(end-at))return false;if(!index&&(v.bytes%4||!sxsw_table(c,&sxsw_dicom_frame_offset,at,4,v.bytes/4)))return false;at+=v.bytes;}
  else{bool undef=v.bytes==UINT32_MAX;if(!undef&&v.bytes>(uint64_t)(end-at))return false;int64_t limit=undef?end:at+v.bytes;if(!sxsw_dc_dataset(c,&at,limit,be,explicit_vr,depth+1,undef))return false;}
  index++;
 }*cursor=at;return !undefined&&at==end;
}
static bool sxsw_dc_dataset(sx_context *c,int64_t *cursor,int64_t end,bool be,bool explicit_vr,unsigned depth,bool undefined)
{
 if(depth>32)return false;int64_t at=*cursor;
 while(at<end){
  sxsw_dc_element v;if(!sxsw_dc_header(c,at,end,be,explicit_vr,&v))return false;at+=v.header;
  if(v.group==0xfffe&&v.element==0xe00d){if(!undefined||v.bytes)return false;*cursor=at;return true;}
  bool undef=v.bytes==UINT32_MAX,pixels=v.group==0x7fe0&&v.element==0x0010,sequence=(v.vr[0]=='S'&&v.vr[1]=='Q');
  if(undef||sequence){if(!undef&&v.bytes>(uint64_t)(end-at))return false;int64_t limit=undef?end:at+v.bytes;if(!sxsw_dc_sequence(c,&at,limit,be,explicit_vr,depth,undef,pixels))return false;}
  else{if(v.bytes>(uint64_t)(end-at))return false;at+=v.bytes;}
 }*cursor=at;return !undefined&&at==end;
}
static bool sxsw_dicom(sx_context *c)
{
 uint32_t n;if(!sx_u32(c,140,false,&n)||!sxsw_span(c,144,n)||!sxsw_add(c,&sxsw_dicom_preamble,0,132))return false;
 int64_t at=132,end=144+(int64_t)n;bool be=false,explicit_vr=true;
 while(at<end){sxsw_dc_element v;if(!sxsw_dc_header(c,at,end,false,true,&v))return false;at+=v.header;if(v.bytes>(uint64_t)(end-at))return false;
  if(v.group==2&&v.element==0&&!sxsw_add(c,&sxsw_dicom_meta_size,at,4))return false;
  if(v.group==2&&v.element==0x10){uint8_t b[80];if(v.bytes>=sizeof(b)||!sx_read(c,at,b,v.bytes))return false;unsigned len=v.bytes;while(len&&(b[len-1]==0||b[len-1]==' '))len--;b[len]=0;
   explicit_vr=xx_rt_strcmp((char*)b,"1.2.840.10008.1.2")!=0;be=!xx_rt_strcmp((char*)b,"1.2.840.10008.1.2.2");
  }at+=v.bytes;
 }return at==end&&sxsw_dc_dataset(c,&at,c->size,be,explicit_vr,0,false);
}
static bool sx_sciencewire_supports(xx_file_type_t t){switch(t){case XX_FILE_TYPE_FITS:case XX_FILE_TYPE_DICOM:case XX_FILE_TYPE_SAS_XPORT:case XX_FILE_TYPE_SPSS_SAV:case XX_FILE_TYPE_STATA_DTA:case XX_FILE_TYPE_ROSBAG1:case XX_FILE_TYPE_GENOMICS_BGEN:case XX_FILE_TYPE_IGOR_IBW:case XX_FILE_TYPE_MICROSCOPY_SPIDER:case XX_FILE_TYPE_WMO_GRIB:case XX_FILE_TYPE_WMO_BUFR:case XX_FILE_TYPE_LECROY_TRC:case XX_FILE_TYPE_NEUROSCAN_CNT:case XX_FILE_TYPE_TECPLOT_PLT:case XX_FILE_TYPE_OPENEPHYS_CONTINUOUS:return true;default:return false;}}
static bool sx_sciencewire_build(sx_context *c)
{
 if(!c||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;
 switch(c->f->file_type){case XX_FILE_TYPE_FITS:ok=sx_fits_build(c);break;case XX_FILE_TYPE_DICOM:ok=sxsw_dicom(c);break;case XX_FILE_TYPE_SAS_XPORT:ok=sx_sas_xport_build(c);break;case XX_FILE_TYPE_SPSS_SAV:ok=sx_spss_sav_build(c);break;case XX_FILE_TYPE_STATA_DTA:ok=sx_stata_dta_build(c);break;case XX_FILE_TYPE_ROSBAG1:ok=sx_rosbag1_build(c);break;case XX_FILE_TYPE_GENOMICS_BGEN:ok=sx_genomics_bgen_build(c);break;case XX_FILE_TYPE_IGOR_IBW:ok=sx_igor_ibw_build(c);break;case XX_FILE_TYPE_MICROSCOPY_SPIDER:ok=sx_microscopy_spider_build(c);break;case XX_FILE_TYPE_WMO_GRIB:ok=sx_wmo_grib_build(c);break;case XX_FILE_TYPE_WMO_BUFR:ok=sx_wmo_bufr_build(c);break;case XX_FILE_TYPE_LECROY_TRC:ok=sx_lecroy_trc_build(c);break;case XX_FILE_TYPE_NEUROSCAN_CNT:ok=sx_neuroscan_cnt_build(c);break;case XX_FILE_TYPE_TECPLOT_PLT:ok=sx_tecplot_plt_build(c);break;case XX_FILE_TYPE_OPENEPHYS_CONTINUOUS:ok=sx_openephys_continuous_build(c);break;default:return false;}return ok&&sxsw_finish(c);
}
const sx_family sx_sciencewire_family={sx_sciencewire_supports,sx_sciencewire_build,sx_sciencewire_layouts,SX_COUNT(sx_sciencewire_layouts),sx_sciencewire_comment};
