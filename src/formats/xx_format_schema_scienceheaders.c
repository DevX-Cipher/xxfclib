/* SPDX-License-Identifier: MIT
 * Scientific file metadata. Scope: docs/data_struct_scienceheaders_scope.txt. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_scienceheaders.h"

static const xx_data_struct_field_desc sxsh_nsx_channel_fields[] = {
    SX_FIELD("type","char[2]",0,2,SX_ID),
    SX_FIELD("channel_id","uint16",2,2,SX_ID),
    SX_FIELD("label","char[16]",4,16,SX_STRING),
    SX_FIELD("connector_bank","uint8",20,1,SX_ID),
    SX_FIELD("connector_pin","uint8",21,1,SX_ID),
    SX_FIELD("digital_min","int16",22,2,SX_NONE),
    SX_FIELD("digital_max","int16",24,2,SX_NONE),
    SX_FIELD("analog_min","int16",26,2,SX_NONE),
    SX_FIELD("analog_max","int16",28,2,SX_NONE),
    SX_FIELD("units","char[16]",30,16,SX_STRING),
    SX_FIELD("high_frequency_corner","uint32",46,4,SX_NONE),
    SX_FIELD("high_frequency_order","uint32",50,4,SX_NONE),
    SX_FIELD("high_filter_type","uint16",54,2,SX_ID),
    SX_FIELD("low_frequency_corner","uint32",56,4,SX_NONE),
    SX_FIELD("low_frequency_order","uint32",60,4,SX_NONE),
    SX_FIELD("low_filter_type","uint16",64,2,SX_ID),
};
const sx_layout sxsh_nsx_channel = {UINT32_C(0x602a0002),"nsx_channel",sxsh_nsx_channel_fields,SX_COUNT(sxsh_nsx_channel_fields),SX_LE};
static const xx_data_struct_field_desc sxsh_nev_filter_extension_fields[] = {
    SX_FIELD("type","char[8]",0,8,SX_ID),
    SX_FIELD("electrode_id","uint16",8,2,SX_ID),
    SX_FIELD("high_frequency_corner","uint32",10,4,SX_NONE),
    SX_FIELD("high_frequency_order","uint32",14,4,SX_NONE),
    SX_FIELD("high_filter_type","uint16",18,2,SX_ID),
    SX_FIELD("low_frequency_corner","uint32",20,4,SX_NONE),
    SX_FIELD("low_frequency_order","uint32",24,4,SX_NONE),
    SX_FIELD("low_filter_type","uint16",28,2,SX_ID),
    SX_FIELD("reserved","uint8[2]",30,2,SX_RESERVED),
};
const sx_layout sxsh_nev_filter_extension = {UINT32_C(0x602a0009),"nev_filter_extension",sxsh_nev_filter_extension_fields,SX_COUNT(sxsh_nev_filter_extension_fields),SX_LE};
static const xx_data_struct_field_desc sxsh_spe_header_fields[] = {
    SX_FIELD("controller_version","int16",0,2,SX_ID),
    SX_FIELD("logic_output","int16",2,2,SX_ID),
    SX_FIELD("amplifier_mode","uint16",4,2,SX_ID),
    SX_FIELD("detector_width","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("timing_mode","int16",8,2,SX_ID),
    SX_FIELD("exposure_seconds","float32",10,4,SX_NONE),
    SX_FIELD("virtual_chip_width","int16",14,2,SX_COUNT_PROP),
    SX_FIELD("virtual_chip_height","int16",16,2,SX_COUNT_PROP),
    SX_FIELD("detector_height","uint16",18,2,SX_COUNT_PROP),
    SX_FIELD("date","char[10]",20,10,SX_STRING),
    SX_FIELD("opaque_1e","uint8[6]",30,6,SX_NONE),
    SX_FIELD("detector_temperature","float32",36,4,SX_NONE),
    SX_FIELD("detector_type","int16",40,2,SX_ID),
    SX_FIELD("width","uint16",42,2,SX_COUNT_PROP),
    SX_FIELD("diode_start","int16",44,2,SX_NONE),
    SX_FIELD("delay_time","float32",46,4,SX_NONE),
    SX_FIELD("shutter_control","uint16",50,2,SX_ID),
    SX_FIELD("absorbance_live","int16",52,2,SX_FLAGS),
    SX_FIELD("absorbance_mode","uint16",54,2,SX_ID),
    SX_FIELD("virtual_chip_enabled","int16",56,2,SX_FLAGS),
    SX_FIELD("threshold_min_enabled","int16",58,2,SX_FLAGS),
    SX_FIELD("threshold_min","float32",60,4,SX_NONE),
    SX_FIELD("threshold_max_enabled","int16",64,2,SX_FLAGS),
    SX_FIELD("threshold_max","float32",66,4,SX_NONE),
    SX_FIELD("opaque_46","uint8[28]",70,28,SX_NONE),
    SX_FIELD("x_pre_pixels","int16",98,2,SX_COUNT_PROP),
    SX_FIELD("x_post_pixels","int16",100,2,SX_COUNT_PROP),
    SX_FIELD("y_pre_pixels","int16",102,2,SX_COUNT_PROP),
    SX_FIELD("y_post_pixels","int16",104,2,SX_COUNT_PROP),
    SX_FIELD("opaque_6a","uint8[2]",106,2,SX_NONE),
    SX_FIELD("data_type","int16",108,2,SX_ID),
    SX_FIELD("opaque_6e","uint8[62]",110,62,SX_NONE),
    SX_FIELD("local_time","char[7]",172,7,SX_STRING),
    SX_FIELD("utc_time","char[7]",179,7,SX_STRING),
    SX_FIELD("opaque_ba","uint8[2]",186,2,SX_NONE),
    SX_FIELD("adc_offset","uint16",188,2,SX_NONE),
    SX_FIELD("adc_rate","uint16",190,2,SX_NONE),
    SX_FIELD("adc_type","uint16",192,2,SX_ID),
    SX_FIELD("adc_resolution","uint16",194,2,SX_NONE),
    SX_FIELD("adc_bit_adjust","uint16",196,2,SX_NONE),
    SX_FIELD("gain","uint16",198,2,SX_NONE),
    SX_FIELD("comment1","char[80]",200,80,SX_STRING),
    SX_FIELD("comment2","char[80]",280,80,SX_STRING),
    SX_FIELD("comment3","char[80]",360,80,SX_STRING),
    SX_FIELD("comment4","char[80]",440,80,SX_STRING),
    SX_FIELD("comment5","char[80]",520,80,SX_STRING),
    SX_FIELD("geometry","uint16",600,2,SX_FLAGS),
    SX_FIELD("opaque_25a","uint8[54]",602,54,SX_NONE),
    SX_FIELD("height","uint16",656,2,SX_COUNT_PROP),
    SX_FIELD("opaque_292","uint8[14]",658,14,SX_NONE),
    SX_FIELD("readout_time","float32",672,4,SX_NONE),
    SX_FIELD("opaque_2a4","uint8[12]",676,12,SX_NONE),
    SX_FIELD("software_version","char[16]",688,16,SX_STRING),
    SX_FIELD("controller_type","int16",704,2,SX_ID),
    SX_FIELD("opaque_2c2","uint8[722]",706,722,SX_NONE),
    SX_FIELD("clock_speed_microseconds","float32",1428,4,SX_NONE),
    SX_FIELD("opaque_598","uint8[14]",1432,14,SX_NONE),
    SX_FIELD("frame_count","int32",1446,4,SX_COUNT_PROP),
    SX_FIELD("opaque_5aa","uint8[30]",1450,30,SX_NONE),
    SX_FIELD("readout_mode","uint16",1480,2,SX_ID),
    SX_FIELD("window_size","uint16",1482,2,SX_NONE),
    SX_FIELD("opaque_5cc","uint8[26]",1484,26,SX_NONE),
    SX_FIELD("roi_count","int16",1510,2,SX_COUNT_PROP),
    SX_FIELD("roi1_start_x","uint16",1512,2,SX_NONE),
    SX_FIELD("roi1_end_x","uint16",1514,2,SX_NONE),
    SX_FIELD("roi1_group_x","uint16",1516,2,SX_NONE),
    SX_FIELD("roi1_start_y","uint16",1518,2,SX_NONE),
    SX_FIELD("roi1_end_y","uint16",1520,2,SX_NONE),
    SX_FIELD("roi1_group_y","uint16",1522,2,SX_NONE),
    SX_FIELD("roi2_start_x","uint16",1524,2,SX_NONE),
    SX_FIELD("roi2_end_x","uint16",1526,2,SX_NONE),
    SX_FIELD("roi2_group_x","uint16",1528,2,SX_NONE),
    SX_FIELD("roi2_start_y","uint16",1530,2,SX_NONE),
    SX_FIELD("roi2_end_y","uint16",1532,2,SX_NONE),
    SX_FIELD("roi2_group_y","uint16",1534,2,SX_NONE),
    SX_FIELD("roi3_start_x","uint16",1536,2,SX_NONE),
    SX_FIELD("roi3_end_x","uint16",1538,2,SX_NONE),
    SX_FIELD("roi3_group_x","uint16",1540,2,SX_NONE),
    SX_FIELD("roi3_start_y","uint16",1542,2,SX_NONE),
    SX_FIELD("roi3_end_y","uint16",1544,2,SX_NONE),
    SX_FIELD("roi3_group_y","uint16",1546,2,SX_NONE),
    SX_FIELD("roi4_start_x","uint16",1548,2,SX_NONE),
    SX_FIELD("roi4_end_x","uint16",1550,2,SX_NONE),
    SX_FIELD("roi4_group_x","uint16",1552,2,SX_NONE),
    SX_FIELD("roi4_start_y","uint16",1554,2,SX_NONE),
    SX_FIELD("roi4_end_y","uint16",1556,2,SX_NONE),
    SX_FIELD("roi4_group_y","uint16",1558,2,SX_NONE),
    SX_FIELD("roi5_start_x","uint16",1560,2,SX_NONE),
    SX_FIELD("roi5_end_x","uint16",1562,2,SX_NONE),
    SX_FIELD("roi5_group_x","uint16",1564,2,SX_NONE),
    SX_FIELD("roi5_start_y","uint16",1566,2,SX_NONE),
    SX_FIELD("roi5_end_y","uint16",1568,2,SX_NONE),
    SX_FIELD("roi5_group_y","uint16",1570,2,SX_NONE),
    SX_FIELD("roi6_start_x","uint16",1572,2,SX_NONE),
    SX_FIELD("roi6_end_x","uint16",1574,2,SX_NONE),
    SX_FIELD("roi6_group_x","uint16",1576,2,SX_NONE),
    SX_FIELD("roi6_start_y","uint16",1578,2,SX_NONE),
    SX_FIELD("roi6_end_y","uint16",1580,2,SX_NONE),
    SX_FIELD("roi6_group_y","uint16",1582,2,SX_NONE),
    SX_FIELD("roi7_start_x","uint16",1584,2,SX_NONE),
    SX_FIELD("roi7_end_x","uint16",1586,2,SX_NONE),
    SX_FIELD("roi7_group_x","uint16",1588,2,SX_NONE),
    SX_FIELD("roi7_start_y","uint16",1590,2,SX_NONE),
    SX_FIELD("roi7_end_y","uint16",1592,2,SX_NONE),
    SX_FIELD("roi7_group_y","uint16",1594,2,SX_NONE),
    SX_FIELD("roi8_start_x","uint16",1596,2,SX_NONE),
    SX_FIELD("roi8_end_x","uint16",1598,2,SX_NONE),
    SX_FIELD("roi8_group_x","uint16",1600,2,SX_NONE),
    SX_FIELD("roi8_start_y","uint16",1602,2,SX_NONE),
    SX_FIELD("roi8_end_y","uint16",1604,2,SX_NONE),
    SX_FIELD("roi8_group_y","uint16",1606,2,SX_NONE),
    SX_FIELD("roi9_start_x","uint16",1608,2,SX_NONE),
    SX_FIELD("roi9_end_x","uint16",1610,2,SX_NONE),
    SX_FIELD("roi9_group_x","uint16",1612,2,SX_NONE),
    SX_FIELD("roi9_start_y","uint16",1614,2,SX_NONE),
    SX_FIELD("roi9_end_y","uint16",1616,2,SX_NONE),
    SX_FIELD("roi9_group_y","uint16",1618,2,SX_NONE),
    SX_FIELD("roi10_start_x","uint16",1620,2,SX_NONE),
    SX_FIELD("roi10_end_x","uint16",1622,2,SX_NONE),
    SX_FIELD("roi10_group_x","uint16",1624,2,SX_NONE),
    SX_FIELD("roi10_start_y","uint16",1626,2,SX_NONE),
    SX_FIELD("roi10_end_y","uint16",1628,2,SX_NONE),
    SX_FIELD("roi10_group_y","uint16",1630,2,SX_NONE),
    SX_FIELD("opaque_660","uint8[360]",1632,360,SX_NONE),
    SX_FIELD("file_header_version","float32",1992,4,SX_ID),
    SX_FIELD("opaque_7cc","uint8[2102]",1996,2102,SX_NONE),
    SX_FIELD("signature","uint16",4098,2,SX_SIGNATURE),
};
const sx_layout sxsh_spe_header = {UINT32_C(0x602a000c),"spe_header",sxsh_spe_header_fields,SX_COUNT(sxsh_spe_header_fields),SX_LE};
static const xx_data_struct_field_desc sxsh_netcdf_attribute_fields[] = {
    SX_FIELD("data_type","uint32",0,4,SX_ID),
    SX_FIELD("value_count","uint32",4,4,SX_COUNT_PROP),
};
const sx_layout sxsh_netcdf_attribute = {UINT32_C(0x602a0021),"netcdf_attribute",sxsh_netcdf_attribute_fields,SX_COUNT(sxsh_netcdf_attribute_fields),SX_BE};
static const xx_data_struct_field_desc sxsh_netcdf_variable32_fields[] = {
    SX_FIELD("data_type","uint32",0,4,SX_ID),
    SX_FIELD("padded_size","uint32",4,4,SX_SIZE),
    SX_FIELD("data_offset","uint32",8,4,SX_OFFSET),
};
const sx_layout sxsh_netcdf_variable32 = {UINT32_C(0x602a0022),"netcdf_variable32",sxsh_netcdf_variable32_fields,SX_COUNT(sxsh_netcdf_variable32_fields),SX_BE};
static const xx_data_struct_field_desc sxsh_netcdf_variable64_fields[] = {
    SX_FIELD("data_type","uint32",0,4,SX_ID),
    SX_FIELD("padded_size","uint32",4,4,SX_SIZE),
    SX_FIELD("data_offset","uint64",8,8,SX_OFFSET),
};
const sx_layout sxsh_netcdf_variable64 = {UINT32_C(0x602a0023),"netcdf_variable64",sxsh_netcdf_variable64_fields,SX_COUNT(sxsh_netcdf_variable64_fields),SX_BE};
static const xx_data_struct_field_desc sxsh_edf_header_fields[] = {
    SX_FIELD("version","char[8]",0,8,SX_ID),
    SX_FIELD("patient","char[80]",8,80,SX_STRING),
    SX_FIELD("recording","char[80]",88,80,SX_STRING),
    SX_FIELD("start_date","char[8]",168,8,SX_STRING),
    SX_FIELD("start_time","char[8]",176,8,SX_STRING),
    SX_FIELD("header_size","ascii_decimal[8]",184,8,SX_SIZE),
    SX_FIELD("reserved","char[44]",192,44,SX_RESERVED),
    SX_FIELD("record_count","ascii_decimal[8]",236,8,SX_COUNT_PROP),
    SX_FIELD("record_duration","char[8]",244,8,SX_STRING),
    SX_FIELD("signal_count","ascii_decimal[4]",252,4,SX_COUNT_PROP),
};
static const sx_layout sxsh_edf_header = {UINT32_C(0x602a0025),"edf_header",sxsh_edf_header_fields,SX_COUNT(sxsh_edf_header_fields),SX_LE};
static const xx_data_struct_field_desc sxsh_edf_signal_label_fields[] = {
    SX_FIELD("label","char[16]",0,16,SX_STRING),
};
static const sx_layout sxsh_edf_signal_label = {UINT32_C(0x602a0026),"edf_signal_label",sxsh_edf_signal_label_fields,SX_COUNT(sxsh_edf_signal_label_fields),SX_LE};
static const xx_data_struct_field_desc sxsh_edf_signal_transducer_fields[] = {
    SX_FIELD("transducer","char[80]",0,80,SX_STRING),
};
static const sx_layout sxsh_edf_signal_transducer = {UINT32_C(0x602a0027),"edf_signal_transducer",sxsh_edf_signal_transducer_fields,SX_COUNT(sxsh_edf_signal_transducer_fields),SX_LE};
static const xx_data_struct_field_desc sxsh_edf_signal_physical_dimension_fields[] = {
    SX_FIELD("physical_dimension","char[8]",0,8,SX_STRING),
};
static const sx_layout sxsh_edf_signal_physical_dimension = {UINT32_C(0x602a0028),"edf_signal_physical_dimension",sxsh_edf_signal_physical_dimension_fields,SX_COUNT(sxsh_edf_signal_physical_dimension_fields),SX_LE};
static const xx_data_struct_field_desc sxsh_edf_signal_physical_min_fields[] = {
    SX_FIELD("physical_min","char[8]",0,8,SX_STRING),
};
static const sx_layout sxsh_edf_signal_physical_min = {UINT32_C(0x602a0029),"edf_signal_physical_min",sxsh_edf_signal_physical_min_fields,SX_COUNT(sxsh_edf_signal_physical_min_fields),SX_LE};
static const xx_data_struct_field_desc sxsh_edf_signal_physical_max_fields[] = {
    SX_FIELD("physical_max","char[8]",0,8,SX_STRING),
};
static const sx_layout sxsh_edf_signal_physical_max = {UINT32_C(0x602a002a),"edf_signal_physical_max",sxsh_edf_signal_physical_max_fields,SX_COUNT(sxsh_edf_signal_physical_max_fields),SX_LE};
static const xx_data_struct_field_desc sxsh_edf_signal_digital_min_fields[] = {
    SX_FIELD("digital_min","char[8]",0,8,SX_STRING),
};
static const sx_layout sxsh_edf_signal_digital_min = {UINT32_C(0x602a002b),"edf_signal_digital_min",sxsh_edf_signal_digital_min_fields,SX_COUNT(sxsh_edf_signal_digital_min_fields),SX_LE};
static const xx_data_struct_field_desc sxsh_edf_signal_digital_max_fields[] = {
    SX_FIELD("digital_max","char[8]",0,8,SX_STRING),
};
static const sx_layout sxsh_edf_signal_digital_max = {UINT32_C(0x602a002c),"edf_signal_digital_max",sxsh_edf_signal_digital_max_fields,SX_COUNT(sxsh_edf_signal_digital_max_fields),SX_LE};
static const xx_data_struct_field_desc sxsh_edf_signal_prefilter_fields[] = {
    SX_FIELD("prefilter","char[80]",0,80,SX_STRING),
};
static const sx_layout sxsh_edf_signal_prefilter = {UINT32_C(0x602a002d),"edf_signal_prefilter",sxsh_edf_signal_prefilter_fields,SX_COUNT(sxsh_edf_signal_prefilter_fields),SX_LE};
static const xx_data_struct_field_desc sxsh_edf_signal_reserved_fields[] = {
    SX_FIELD("reserved","char[32]",0,32,SX_RESERVED),
};
static const sx_layout sxsh_edf_signal_reserved = {UINT32_C(0x602a002e),"edf_signal_reserved",sxsh_edf_signal_reserved_fields,SX_COUNT(sxsh_edf_signal_reserved_fields),SX_LE};
static const xx_data_struct_field_desc sxsh_edf_signal_samples_fields[] = {
    SX_FIELD("samples_per_record","ascii_decimal[8]",0,8,SX_COUNT_PROP),
};
static const sx_layout sxsh_edf_signal_samples = {UINT32_C(0x602a002f),"edf_signal_samples",sxsh_edf_signal_samples_fields,SX_COUNT(sxsh_edf_signal_samples_fields),SX_LE};
static const xx_data_struct_field_desc sxsh_segy_binary_header_fields[] = {
    SX_FIELD("job_identification_number","int32",0,4,SX_NONE),
    SX_FIELD("line_number","int32",4,4,SX_NONE),
    SX_FIELD("reel_number","int32",8,4,SX_NONE),
    SX_FIELD("number_of_data_traces_per_ensemble","int16",12,2,SX_COUNT_PROP),
    SX_FIELD("number_of_auxiliary_traces_per_ensemble","int16",14,2,SX_COUNT_PROP),
    SX_FIELD("sample_interval_in_microseconds","uint16",16,2,SX_NONE),
    SX_FIELD("sample_interval_in_microseconds_of_original_field_recording","uint16",18,2,SX_NONE),
    SX_FIELD("number_of_samples_per_data_trace","uint16",20,2,SX_COUNT_PROP),
    SX_FIELD("number_of_samples_per_data_trace_for_original_field_recording","uint16",22,2,SX_COUNT_PROP),
    SX_FIELD("data_sample_format_code","int16",24,2,SX_ID),
    SX_FIELD("ensemble_fold","int16",26,2,SX_NONE),
    SX_FIELD("trace_sorting_code","int16",28,2,SX_ID),
    SX_FIELD("vertical_sum_code","int16",30,2,SX_ID),
    SX_FIELD("sweep_frequency_at_start","int16",32,2,SX_NONE),
    SX_FIELD("sweep_frequency_at_end","int16",34,2,SX_NONE),
    SX_FIELD("sweep_length","int16",36,2,SX_NONE),
    SX_FIELD("sweep_type_code","int16",38,2,SX_ID),
    SX_FIELD("trace_number_of_sweep_channel","int16",40,2,SX_NONE),
    SX_FIELD("sweep_trace_taper_length_in_ms_at_start","int16",42,2,SX_NONE),
    SX_FIELD("sweep_trace_taper_length_in_ms_at_end","int16",44,2,SX_NONE),
    SX_FIELD("taper_type","int16",46,2,SX_NONE),
    SX_FIELD("correlated_data_traces","int16",48,2,SX_NONE),
    SX_FIELD("binary_gain_recovered","int16",50,2,SX_NONE),
    SX_FIELD("amplitude_recovery_method","int16",52,2,SX_NONE),
    SX_FIELD("measurement_system","int16",54,2,SX_NONE),
    SX_FIELD("impulse_signal_polarity","int16",56,2,SX_NONE),
    SX_FIELD("vibratory_polarity_code","int16",58,2,SX_ID),
    SX_FIELD("unassigned_1","uint8[240]",60,240,SX_RESERVED),
    SX_FIELD("seg_y_format_revision_number","uint16",300,2,SX_ID),
    SX_FIELD("fixed_length_trace_flag","int16",302,2,SX_FLAGS),
    SX_FIELD("number_of_3200_byte_ext_file_header_records_following","int16",304,2,SX_COUNT_PROP),
    SX_FIELD("unassigned_2","uint8[94]",306,94,SX_RESERVED),
};
const sx_layout sxsh_segy_binary_header = {UINT32_C(0x602a0030),"segy_binary_header",sxsh_segy_binary_header_fields,SX_COUNT(sxsh_segy_binary_header_fields),SX_BE};
static const sx_layout *const sx_scienceheaders_layouts[] = {
    &sxsh_nsx_header,
    &sxsh_nsx_channel,
    &sxsh_nsx_packet,
    &sxsh_nev_header,
    &sxsh_nev_extension,
    &sxsh_nev_text_extension,
    &sxsh_nev_waveform_extension,
    &sxsh_nev_label_extension,
    &sxsh_nev_filter_extension,
    &sxsh_nev_spike,
    &sxsh_nev_digital,
    &sxsh_spe_header,
    &sxsh_dcd_header_le,
    &sxsh_dcd_record_size_le,
    &sxsh_dcd_title_count_le,
    &sxsh_dcd_atom_count_le,
    &sxsh_dcd_cell_le,
    &sxsh_dcd_header_be,
    &sxsh_dcd_record_size_be,
    &sxsh_dcd_title_count_be,
    &sxsh_dcd_atom_count_be,
    &sxsh_dcd_cell_be,
    &sxsh_dcd_title,
    &sxsh_trr_header,
    &sxsh_trr_time32,
    &sxsh_trr_time64,
    &sxsh_netcdf_header,
    &sxsh_netcdf_list,
    &sxsh_netcdf_name_size,
    &sxsh_netcdf_dimension,
    &sxsh_netcdf_rank,
    &sxsh_netcdf_dimension_id,
    &sxsh_netcdf_attribute,
    &sxsh_netcdf_variable32,
    &sxsh_netcdf_variable64,
    &sxsh_fcs_header,
    &sxsh_edf_header,
    &sxsh_edf_signal_label,
    &sxsh_edf_signal_transducer,
    &sxsh_edf_signal_physical_dimension,
    &sxsh_edf_signal_physical_min,
    &sxsh_edf_signal_physical_max,
    &sxsh_edf_signal_digital_min,
    &sxsh_edf_signal_digital_max,
    &sxsh_edf_signal_prefilter,
    &sxsh_edf_signal_reserved,
    &sxsh_edf_signal_samples,
    &sxsh_segy_binary_header,
    &sxsh_segy_trace_header,
    &sxsh_segy_text_card,
};
static bool sx_scienceheaders_static_comment(xx_data_struct_record *r,uint32_t id)
{
    if(!r||!r->name||id<0x602a0000U||id>=0x602b0000U)return true;
    const wchar_t *text=NULL;switch(id){
    case 0x602a0002U:
        if(!xx_rt_wcscmp(r->name,L"high_frequency_corner"))text=L"Frequency in millihertz.";
        if(!xx_rt_wcscmp(r->name,L"low_frequency_corner"))text=L"Frequency in millihertz.";
        break;
    case 0x602a0003U:
        if(!xx_rt_wcscmp(r->name,L"timestamp"))text=L"Device clock ticks, not Unix seconds.";
        break;
    case 0x602a0004U:
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Bit 0: all waveforms use sixteen-bit samples.";
        break;
    case 0x602a0005U:
        if(!xx_rt_wcscmp(r->name,L"payload"))text=L"Extension payload is not decoded for this tag.";
        break;
    case 0x602a000aU:
        if(!xx_rt_wcscmp(r->name,L"timestamp"))text=L"Device clock ticks, not Unix seconds.";
        break;
    case 0x602a000bU:
        if(!xx_rt_wcscmp(r->name,L"timestamp"))text=L"Device clock ticks, not Unix seconds.";
        if(!xx_rt_wcscmp(r->name,L"reason"))text=L"Bit 0 digital input; bit 7 periodic sampling.";
        break;
    case 0x602a000eU:
        if(!xx_rt_wcscmp(r->name,L"record_size"))text=L"Fortran record byte length; appears before and after the payload.";
        break;
    case 0x602a0013U:
        if(!xx_rt_wcscmp(r->name,L"record_size"))text=L"Fortran record byte length; appears before and after the payload.";
        break;
    case 0x602a001bU:
        if(!xx_rt_wcscmp(r->name,L"version"))text=L"1=CDF1, 2=CDF2 (64-bit offsets).";
        break;
    case 0x602a001cU:
        if(!xx_rt_wcscmp(r->name,L"tag"))text=L"0=absent, 10=NC_DIMENSION, 11=NC_VARIABLE, 12=NC_ATTRIBUTE.";
        break;
    case 0x602a001dU:
        if(!xx_rt_wcscmp(r->name,L"name_size"))text=L"Bytes of the following UTF-8 name; padded to a multiple of four.";
        break;
    case 0x602a001eU:
        if(!xx_rt_wcscmp(r->name,L"dimension_length"))text=L"Zero denotes the unlimited dimension.";
        break;
    case 0x602a0022U:
        if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Byte offset from the file base.";
        break;
    case 0x602a0023U:
        if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Byte offset from the file base.";
        break;
    case 0x602a0024U:
        if(!xx_rt_wcscmp(r->name,L"text_start"))text=L"File-relative byte offset; end offsets are inclusive. Zero may delegate to TEXT keywords.";
        if(!xx_rt_wcscmp(r->name,L"text_end"))text=L"File-relative byte offset; end offsets are inclusive. Zero may delegate to TEXT keywords.";
        if(!xx_rt_wcscmp(r->name,L"data_start"))text=L"File-relative byte offset; end offsets are inclusive. Zero may delegate to TEXT keywords.";
        if(!xx_rt_wcscmp(r->name,L"data_end"))text=L"File-relative byte offset; end offsets are inclusive. Zero may delegate to TEXT keywords.";
        if(!xx_rt_wcscmp(r->name,L"analysis_start"))text=L"File-relative byte offset; end offsets are inclusive. Zero may delegate to TEXT keywords.";
        if(!xx_rt_wcscmp(r->name,L"analysis_end"))text=L"File-relative byte offset; end offsets are inclusive. Zero may delegate to TEXT keywords.";
        break;
    case 0x602a0025U:
        if(!xx_rt_wcscmp(r->name,L"record_duration"))text=L"ASCII decimal seconds, including a possible fractional part.";
        break;
    case 0x602a0029U:
        if(!xx_rt_wcscmp(r->name,L"physical_min"))text=L"Stored ASCII numeric text, with sign/fraction preserved.";
        break;
    case 0x602a002aU:
        if(!xx_rt_wcscmp(r->name,L"physical_max"))text=L"Stored ASCII numeric text, with sign/fraction preserved.";
        break;
    case 0x602a002bU:
        if(!xx_rt_wcscmp(r->name,L"digital_min"))text=L"Stored ASCII numeric text, with sign/fraction preserved.";
        break;
    case 0x602a002cU:
        if(!xx_rt_wcscmp(r->name,L"digital_max"))text=L"Stored ASCII numeric text, with sign/fraction preserved.";
        break;
    case 0x602a0031U:
        if(!xx_rt_wcscmp(r->name,L"sample_interval_in_microseconds"))text=L"Microseconds per sample.";
        if(!xx_rt_wcscmp(r->name,L"source_energy_direction"))text=L"Stored six-byte direction representation; interpretation is not assumed.";
        break;
    case 0x602a0032U:
        if(!xx_rt_wcscmp(r->name,L"text_bytes"))text=L"Original ASCII or EBCDIC bytes are preserved without assuming character encoding.";
        break;
    default:break;}return !text||xx_data_struct_record_set_comment(r,text);
}
static bool sx_scienceheaders_comment(xx_data_struct_record *r,uint32_t id)
{
 if(!sx_scienceheaders_static_comment(r,id))return false;
 if(!r||!r->name||id<0x602a0000U||id>=0x602b0000U||r->value.type==XX_VAR_TYPE_FLOAT||r->value.type==XX_VAR_TYPE_DOUBLE||r->value.type==XX_VAR_TYPE_STRING||r->value.type==XX_VAR_TYPE_BYTES)return true;
 uint64_t v=xx_var_get_u64(&r->value);const wchar_t *text=NULL;
 if(id==sxsh_spe_header.id&&!xx_rt_wcscmp(r->name,L"data_type")){static const wchar_t *const names[]={L"SPE_FLOAT32",L"SPE_INT32",L"SPE_INT16",L"SPE_UINT16"};if(v<SX_COUNT(names))text=names[v];}
 if((id==sxsh_netcdf_attribute.id||id==sxsh_netcdf_variable32.id||id==sxsh_netcdf_variable64.id)&&!xx_rt_wcscmp(r->name,L"data_type")){static const wchar_t *const names[]={L"NC_NAT",L"NC_BYTE",L"NC_CHAR",L"NC_SHORT",L"NC_INT",L"NC_FLOAT",L"NC_DOUBLE"};if(v<SX_COUNT(names))text=names[v];}
 if(id==sxsh_segy_binary_header.id&&!xx_rt_wcscmp(r->name,L"data_sample_format_code"))switch(v){case 1:text=L"IBM_FLOAT32";break;case 2:text=L"INT32";break;case 3:text=L"INT16";break;case 5:text=L"IEEE_FLOAT32";break;case 8:text=L"INT8";break;default:break;}
 if((id==sxsh_nsx_channel.id||id==sxsh_nev_filter_extension.id)&&(!xx_rt_wcscmp(r->name,L"high_filter_type")||!xx_rt_wcscmp(r->name,L"low_filter_type"))){if(v==0)text=L"NONE";else if(v==1)text=L"BUTTERWORTH";}
 return !text||xx_data_struct_record_set_comment(r,text);
}
static bool sx_scienceheaders_supports(xx_file_type_t t)
{switch(t){case XX_FILE_TYPE_BLACKROCK_NSX:case XX_FILE_TYPE_BLACKROCK_NEV:case XX_FILE_TYPE_PRINCETON_SPE:case XX_FILE_TYPE_CHARMM_DCD:case XX_FILE_TYPE_GROMACS_TRR:case XX_FILE_TYPE_NETCDF_CLASSIC:case XX_FILE_TYPE_SEISMIC_SEGY:case XX_FILE_TYPE_FCS:case XX_FILE_TYPE_EDF:case XX_FILE_TYPE_BIOMEDICAL_BDF:return true;default:return false;}}
uint16_t sxsh16(const uint8_t *p,bool be){return xx_data_get_u16(p,2,0,be);}
uint32_t sxsh32(const uint8_t *p,bool be){return xx_data_get_u32(p,4,0,be);}
bool sxsh_span(sx_context *c,int64_t at,uint64_t n){return c&&!xx_pd_is_stopped(c->pd)&&at>=0&&at<=c->size&&n<=(uint64_t)(c->size-at);}
bool sxsh_add(sx_context *c,const sx_layout *l,int64_t at,int64_t bytes){return sxsh_span(c,at,(uint64_t)bytes)&&(c->count>=32000||sx_add(c,l,at,bytes));}
bool sxsh_table(sx_context *c,const sx_layout *l,int64_t at,int64_t bytes,uint64_t count){return bytes>0&&count<=INT64_MAX/(uint64_t)bytes&&sxsh_span(c,at,(uint64_t)bytes*count)&&(c->count>=32000||sx_table(c,l,at,bytes,count));}
static int sxsh_order(const void *a,const void *b){const xx_data_struct *x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:x->total_size<y->total_size?-1:x->total_size>y->total_size?1:0;}
bool sxsh_finish(sx_context *c)
{
 size_t n=c->count;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxsh_order);
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,bytes=c->items[i].total_size;if(at<end)return false;if(at>end&&!sx_raw(c,end,at-end))return false;end=at+bytes;}
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxsh_order);return !c->failed&&!xx_pd_is_stopped(c->pd);
}
static bool sxsh_decimal(sx_context *c,int64_t at,unsigned width,uint64_t *v)
{
 uint8_t b[16];if(width>sizeof(b)||!sx_read(c,at,b,width))return false;bool digit=false,space=false;*v=0;
 for(unsigned i=0;i<width;i++){if(b[i]==' '){if(digit)space=true;continue;}if(b[i]<'0'||b[i]>'9'||space)return false;digit=true;*v=*v*10+(unsigned)(b[i]-'0');}return digit;
}
bool sxsh_edf(sx_context *c)
{
 uint64_t header,count;if(!sxsh_decimal(c,184,8,&header)||!sxsh_decimal(c,252,4,&count)||!count||count>512||header!=256*(count+1)||!sxsh_span(c,0,header)||!sxsh_add(c,&sxsh_edf_header,0,256))return false;
 const sx_layout *l[]={&sxsh_edf_signal_label,&sxsh_edf_signal_transducer,&sxsh_edf_signal_physical_dimension,&sxsh_edf_signal_physical_min,&sxsh_edf_signal_physical_max,&sxsh_edf_signal_digital_min,&sxsh_edf_signal_digital_max,&sxsh_edf_signal_prefilter,&sxsh_edf_signal_samples,&sxsh_edf_signal_reserved};
 const unsigned widths[]={16,80,8,8,8,8,8,80,8,32};int64_t at=256;
 for(unsigned i=0;i<SX_COUNT(l);i++){if(!sxsh_table(c,l[i],at,widths[i],count))return false;at+=(int64_t)widths[i]*(int64_t)count;}return (uint64_t)at==header;
}
static bool sx_scienceheaders_build(sx_context *c)
{
 if(!c||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;
 if(c->f->file_type==XX_FILE_TYPE_BLACKROCK_NSX)return sx_blackrock_nsx_build(c);
 if(c->f->file_type==XX_FILE_TYPE_BLACKROCK_NEV)return sx_blackrock_nev_build(c);
 if(c->f->file_type==XX_FILE_TYPE_PRINCETON_SPE)return sx_princeton_spe_build(c);
 if(c->f->file_type==XX_FILE_TYPE_CHARMM_DCD)return sx_charmm_dcd_build(c);
 if(c->f->file_type==XX_FILE_TYPE_GROMACS_TRR)return sx_gromacs_trr_build(c);
 if(c->f->file_type==XX_FILE_TYPE_NETCDF_CLASSIC)return sx_netcdf_classic_build(c);
 if(c->f->file_type==XX_FILE_TYPE_FCS)return sx_fcs_build(c);
 if(c->f->file_type==XX_FILE_TYPE_EDF)return sx_edf_build(c);
 if(c->f->file_type==XX_FILE_TYPE_BIOMEDICAL_BDF)return sx_biomedical_bdf_build(c);
 if(c->f->file_type==XX_FILE_TYPE_SEISMIC_SEGY)return sx_seismic_segy_build(c);
 return false;
}
const sx_family sx_scienceheaders_family={sx_scienceheaders_supports,sx_scienceheaders_build,sx_scienceheaders_layouts,SX_COUNT(sx_scienceheaders_layouts),sx_scienceheaders_comment};
