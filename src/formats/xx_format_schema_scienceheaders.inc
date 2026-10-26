/* SPDX-License-Identifier: MIT
 * Scientific file metadata. Scope: docs/data_struct_scienceheaders_scope.txt. */
static const xx_data_struct_field_desc sxsh_nsx_header_fields[] = {
    SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("major_version","uint8",8,1,SX_ID),
    SX_FIELD("minor_version","uint8",9,1,SX_ID),
    SX_FIELD("header_size","uint32",10,4,SX_SIZE),
    SX_FIELD("label","char[16]",14,16,SX_STRING),
    SX_FIELD("comment","char[256]",30,256,SX_STRING),
    SX_FIELD("period","uint32",286,4,SX_NONE),
    SX_FIELD("time_resolution","uint32",290,4,SX_NONE),
    SX_FIELD("year","uint16",294,2,SX_NONE),
    SX_FIELD("month","uint16",296,2,SX_NONE),
    SX_FIELD("day_of_week","uint16",298,2,SX_NONE),
    SX_FIELD("day","uint16",300,2,SX_NONE),
    SX_FIELD("hour","uint16",302,2,SX_NONE),
    SX_FIELD("minute","uint16",304,2,SX_NONE),
    SX_FIELD("second","uint16",306,2,SX_NONE),
    SX_FIELD("millisecond","uint16",308,2,SX_NONE),
    SX_FIELD("channel_count","uint32",310,4,SX_COUNT_PROP),
};
static const sx_layout sxsh_nsx_header = {UINT32_C(0x602a0001),"nsx_header",sxsh_nsx_header_fields,SX_COUNT(sxsh_nsx_header_fields),SX_LE};
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
static const sx_layout sxsh_nsx_channel = {UINT32_C(0x602a0002),"nsx_channel",sxsh_nsx_channel_fields,SX_COUNT(sxsh_nsx_channel_fields),SX_LE};
static const xx_data_struct_field_desc sxsh_nsx_packet_fields[] = {
    SX_FIELD("marker","uint8",0,1,SX_SIGNATURE),
    SX_FIELD("timestamp","uint32",1,4,SX_NONE),
    SX_FIELD("sample_count","uint32",5,4,SX_COUNT_PROP),
};
static const sx_layout sxsh_nsx_packet = {UINT32_C(0x602a0003),"nsx_packet",sxsh_nsx_packet_fields,SX_COUNT(sxsh_nsx_packet_fields),SX_LE};
static const xx_data_struct_field_desc sxsh_nev_header_fields[] = {
    SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("major_version","uint8",8,1,SX_ID),
    SX_FIELD("minor_version","uint8",9,1,SX_ID),
    SX_FIELD("flags","uint16",10,2,SX_FLAGS),
    SX_FIELD("header_size","uint32",12,4,SX_SIZE),
    SX_FIELD("packet_size","uint32",16,4,SX_SIZE),
    SX_FIELD("timestamp_resolution","uint32",20,4,SX_NONE),
    SX_FIELD("sample_resolution","uint32",24,4,SX_NONE),
    SX_FIELD("year","uint16",28,2,SX_NONE),
    SX_FIELD("month","uint16",30,2,SX_NONE),
    SX_FIELD("day_of_week","uint16",32,2,SX_NONE),
    SX_FIELD("day","uint16",34,2,SX_NONE),
    SX_FIELD("hour","uint16",36,2,SX_NONE),
    SX_FIELD("minute","uint16",38,2,SX_NONE),
    SX_FIELD("second","uint16",40,2,SX_NONE),
    SX_FIELD("millisecond","uint16",42,2,SX_NONE),
    SX_FIELD("application","char[32]",44,32,SX_STRING),
    SX_FIELD("comment","char[256]",76,256,SX_STRING),
    SX_FIELD("extended_header_count","uint32",332,4,SX_COUNT_PROP),
};
static const sx_layout sxsh_nev_header = {UINT32_C(0x602a0004),"nev_header",sxsh_nev_header_fields,SX_COUNT(sxsh_nev_header_fields),SX_LE};
static const xx_data_struct_field_desc sxsh_nev_extension_fields[] = {
    SX_FIELD("type","char[8]",0,8,SX_ID),
    SX_FIELD("payload","uint8[24]",8,24,SX_NONE),
};
static const sx_layout sxsh_nev_extension = {UINT32_C(0x602a0005),"nev_extension",sxsh_nev_extension_fields,SX_COUNT(sxsh_nev_extension_fields),SX_LE};
static const xx_data_struct_field_desc sxsh_nev_text_extension_fields[] = {
    SX_FIELD("type","char[8]",0,8,SX_ID),
    SX_FIELD("text","char[24]",8,24,SX_STRING),
};
static const sx_layout sxsh_nev_text_extension = {UINT32_C(0x602a0006),"nev_text_extension",sxsh_nev_text_extension_fields,SX_COUNT(sxsh_nev_text_extension_fields),SX_LE};
static const xx_data_struct_field_desc sxsh_nev_waveform_extension_fields[] = {
    SX_FIELD("type","char[8]",0,8,SX_ID),
    SX_FIELD("electrode_id","uint16",8,2,SX_ID),
    SX_FIELD("connector_bank","uint8",10,1,SX_ID),
    SX_FIELD("connector_pin","uint8",11,1,SX_ID),
    SX_FIELD("digital_factor","int16",12,2,SX_NONE),
    SX_FIELD("energy_threshold","uint16",14,2,SX_NONE),
    SX_FIELD("high_threshold","int16",16,2,SX_NONE),
    SX_FIELD("low_threshold","int16",18,2,SX_NONE),
    SX_FIELD("sorted_unit_count","uint8",20,1,SX_COUNT_PROP),
    SX_FIELD("bytes_per_sample","uint8",21,1,SX_SIZE),
    SX_FIELD("reserved","uint8[10]",22,10,SX_RESERVED),
};
static const sx_layout sxsh_nev_waveform_extension = {UINT32_C(0x602a0007),"nev_waveform_extension",sxsh_nev_waveform_extension_fields,SX_COUNT(sxsh_nev_waveform_extension_fields),SX_LE};
static const xx_data_struct_field_desc sxsh_nev_label_extension_fields[] = {
    SX_FIELD("type","char[8]",0,8,SX_ID),
    SX_FIELD("electrode_id","uint16",8,2,SX_ID),
    SX_FIELD("label","char[16]",10,16,SX_STRING),
    SX_FIELD("reserved","uint8[6]",26,6,SX_RESERVED),
};
static const sx_layout sxsh_nev_label_extension = {UINT32_C(0x602a0008),"nev_label_extension",sxsh_nev_label_extension_fields,SX_COUNT(sxsh_nev_label_extension_fields),SX_LE};
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
static const sx_layout sxsh_nev_filter_extension = {UINT32_C(0x602a0009),"nev_filter_extension",sxsh_nev_filter_extension_fields,SX_COUNT(sxsh_nev_filter_extension_fields),SX_LE};
static const xx_data_struct_field_desc sxsh_nev_spike_fields[] = {
    SX_FIELD("timestamp","uint32",0,4,SX_NONE),
    SX_FIELD("packet_id","uint16",4,2,SX_ID),
    SX_FIELD("unit_id","uint8",6,1,SX_ID),
    SX_FIELD("reserved","uint8",7,1,SX_RESERVED),
};
static const sx_layout sxsh_nev_spike = {UINT32_C(0x602a000a),"nev_spike",sxsh_nev_spike_fields,SX_COUNT(sxsh_nev_spike_fields),SX_LE};
static const xx_data_struct_field_desc sxsh_nev_digital_fields[] = {
    SX_FIELD("timestamp","uint32",0,4,SX_NONE),
    SX_FIELD("packet_id","uint16",4,2,SX_ID),
    SX_FIELD("reason","uint8",6,1,SX_FLAGS),
    SX_FIELD("reserved","uint8",7,1,SX_RESERVED),
    SX_FIELD("digital_value","uint16",8,2,SX_FLAGS),
};
static const sx_layout sxsh_nev_digital = {UINT32_C(0x602a000b),"nev_digital",sxsh_nev_digital_fields,SX_COUNT(sxsh_nev_digital_fields),SX_LE};
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
static const sx_layout sxsh_spe_header = {UINT32_C(0x602a000c),"spe_header",sxsh_spe_header_fields,SX_COUNT(sxsh_spe_header_fields),SX_LE};
static const xx_data_struct_field_desc sxsh_dcd_header_le_fields[] = {
    SX_FIELD("record_size","int32",0,4,SX_SIZE),
    SX_FIELD("signature","char[4]",4,4,SX_SIGNATURE),
    SX_FIELD("frame_count","int32",8,4,SX_COUNT_PROP),
    SX_FIELD("first_step","int32",12,4,SX_NONE),
    SX_FIELD("step_interval","int32",16,4,SX_NONE),
    SX_FIELD("control_words","int32[5]",20,20,SX_NONE),
    SX_FIELD("fixed_atom_count","int32",40,4,SX_COUNT_PROP),
    SX_FIELD("delta","float32",44,4,SX_NONE),
    SX_FIELD("unit_cell_flag","int32",48,4,SX_FLAGS),
    SX_FIELD("four_dimensions_flag","int32",52,4,SX_FLAGS),
    SX_FIELD("reserved","int32[7]",56,28,SX_RESERVED),
    SX_FIELD("charmm_version","int32",84,4,SX_ID),
    SX_FIELD("trailing_record_size","int32",88,4,SX_SIZE),
};
static const sx_layout sxsh_dcd_header_le = {UINT32_C(0x602a000d),"dcd_header_le",sxsh_dcd_header_le_fields,SX_COUNT(sxsh_dcd_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsh_dcd_record_size_le_fields[] = {
    SX_FIELD("record_size","int32",0,4,SX_SIZE),
};
static const sx_layout sxsh_dcd_record_size_le = {UINT32_C(0x602a000e),"dcd_record_size_le",sxsh_dcd_record_size_le_fields,SX_COUNT(sxsh_dcd_record_size_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsh_dcd_title_count_le_fields[] = {
    SX_FIELD("title_count","int32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxsh_dcd_title_count_le = {UINT32_C(0x602a000f),"dcd_title_count_le",sxsh_dcd_title_count_le_fields,SX_COUNT(sxsh_dcd_title_count_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsh_dcd_atom_count_le_fields[] = {
    SX_FIELD("atom_count","int32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxsh_dcd_atom_count_le = {UINT32_C(0x602a0010),"dcd_atom_count_le",sxsh_dcd_atom_count_le_fields,SX_COUNT(sxsh_dcd_atom_count_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsh_dcd_cell_le_fields[] = {
    SX_FIELD("a","float64",0,8,SX_NONE),
    SX_FIELD("gamma","float64",8,8,SX_NONE),
    SX_FIELD("b","float64",16,8,SX_NONE),
    SX_FIELD("beta","float64",24,8,SX_NONE),
    SX_FIELD("alpha","float64",32,8,SX_NONE),
    SX_FIELD("c","float64",40,8,SX_NONE),
};
static const sx_layout sxsh_dcd_cell_le = {UINT32_C(0x602a0011),"dcd_cell_le",sxsh_dcd_cell_le_fields,SX_COUNT(sxsh_dcd_cell_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsh_dcd_header_be_fields[] = {
    SX_FIELD("record_size","int32",0,4,SX_SIZE),
    SX_FIELD("signature","char[4]",4,4,SX_SIGNATURE),
    SX_FIELD("frame_count","int32",8,4,SX_COUNT_PROP),
    SX_FIELD("first_step","int32",12,4,SX_NONE),
    SX_FIELD("step_interval","int32",16,4,SX_NONE),
    SX_FIELD("control_words","int32[5]",20,20,SX_NONE),
    SX_FIELD("fixed_atom_count","int32",40,4,SX_COUNT_PROP),
    SX_FIELD("delta","float32",44,4,SX_NONE),
    SX_FIELD("unit_cell_flag","int32",48,4,SX_FLAGS),
    SX_FIELD("four_dimensions_flag","int32",52,4,SX_FLAGS),
    SX_FIELD("reserved","int32[7]",56,28,SX_RESERVED),
    SX_FIELD("charmm_version","int32",84,4,SX_ID),
    SX_FIELD("trailing_record_size","int32",88,4,SX_SIZE),
};
static const sx_layout sxsh_dcd_header_be = {UINT32_C(0x602a0012),"dcd_header_be",sxsh_dcd_header_be_fields,SX_COUNT(sxsh_dcd_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsh_dcd_record_size_be_fields[] = {
    SX_FIELD("record_size","int32",0,4,SX_SIZE),
};
static const sx_layout sxsh_dcd_record_size_be = {UINT32_C(0x602a0013),"dcd_record_size_be",sxsh_dcd_record_size_be_fields,SX_COUNT(sxsh_dcd_record_size_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsh_dcd_title_count_be_fields[] = {
    SX_FIELD("title_count","int32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxsh_dcd_title_count_be = {UINT32_C(0x602a0014),"dcd_title_count_be",sxsh_dcd_title_count_be_fields,SX_COUNT(sxsh_dcd_title_count_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsh_dcd_atom_count_be_fields[] = {
    SX_FIELD("atom_count","int32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxsh_dcd_atom_count_be = {UINT32_C(0x602a0015),"dcd_atom_count_be",sxsh_dcd_atom_count_be_fields,SX_COUNT(sxsh_dcd_atom_count_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsh_dcd_cell_be_fields[] = {
    SX_FIELD("a","float64",0,8,SX_NONE),
    SX_FIELD("gamma","float64",8,8,SX_NONE),
    SX_FIELD("b","float64",16,8,SX_NONE),
    SX_FIELD("beta","float64",24,8,SX_NONE),
    SX_FIELD("alpha","float64",32,8,SX_NONE),
    SX_FIELD("c","float64",40,8,SX_NONE),
};
static const sx_layout sxsh_dcd_cell_be = {UINT32_C(0x602a0016),"dcd_cell_be",sxsh_dcd_cell_be_fields,SX_COUNT(sxsh_dcd_cell_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsh_dcd_title_fields[] = {
    SX_FIELD("title","char[80]",0,80,SX_STRING),
};
static const sx_layout sxsh_dcd_title = {UINT32_C(0x602a0017),"dcd_title",sxsh_dcd_title_fields,SX_COUNT(sxsh_dcd_title_fields),SX_LE};
static const xx_data_struct_field_desc sxsh_trr_header_fields[] = {
    SX_FIELD("magic","int32",0,4,SX_SIGNATURE),
    SX_FIELD("version_buffer_size","int32",4,4,SX_SIZE),
    SX_FIELD("version_string_size","int32",8,4,SX_SIZE),
    SX_FIELD("version","char[12]",12,12,SX_STRING),
    SX_FIELD("ir_size","int32",24,4,SX_SIZE),
    SX_FIELD("energy_size","int32",28,4,SX_SIZE),
    SX_FIELD("box_size","int32",32,4,SX_SIZE),
    SX_FIELD("virial_size","int32",36,4,SX_SIZE),
    SX_FIELD("pressure_size","int32",40,4,SX_SIZE),
    SX_FIELD("topology_size","int32",44,4,SX_SIZE),
    SX_FIELD("symbols_size","int32",48,4,SX_SIZE),
    SX_FIELD("coordinates_size","int32",52,4,SX_SIZE),
    SX_FIELD("velocities_size","int32",56,4,SX_SIZE),
    SX_FIELD("forces_size","int32",60,4,SX_SIZE),
    SX_FIELD("atom_count","int32",64,4,SX_COUNT_PROP),
    SX_FIELD("step","int32",68,4,SX_NONE),
    SX_FIELD("nre","int32",72,4,SX_NONE),
};
static const sx_layout sxsh_trr_header = {UINT32_C(0x602a0018),"trr_header",sxsh_trr_header_fields,SX_COUNT(sxsh_trr_header_fields),SX_BE};
static const xx_data_struct_field_desc sxsh_trr_time32_fields[] = {
    SX_FIELD("time","float32",0,4,SX_NONE),
    SX_FIELD("lambda","float32",4,4,SX_NONE),
};
static const sx_layout sxsh_trr_time32 = {UINT32_C(0x602a0019),"trr_time32",sxsh_trr_time32_fields,SX_COUNT(sxsh_trr_time32_fields),SX_BE};
static const xx_data_struct_field_desc sxsh_trr_time64_fields[] = {
    SX_FIELD("time","float64",0,8,SX_NONE),
    SX_FIELD("lambda","float64",8,8,SX_NONE),
};
static const sx_layout sxsh_trr_time64 = {UINT32_C(0x602a001a),"trr_time64",sxsh_trr_time64_fields,SX_COUNT(sxsh_trr_time64_fields),SX_BE};
static const xx_data_struct_field_desc sxsh_netcdf_header_fields[] = {
    SX_FIELD("signature","char[3]",0,3,SX_SIGNATURE),
    SX_FIELD("version","uint8",3,1,SX_ID),
    SX_FIELD("record_count","uint32",4,4,SX_COUNT_PROP),
};
static const sx_layout sxsh_netcdf_header = {UINT32_C(0x602a001b),"netcdf_header",sxsh_netcdf_header_fields,SX_COUNT(sxsh_netcdf_header_fields),SX_BE};
static const xx_data_struct_field_desc sxsh_netcdf_list_fields[] = {
    SX_FIELD("tag","uint32",0,4,SX_ID),
    SX_FIELD("count","uint32",4,4,SX_COUNT_PROP),
};
static const sx_layout sxsh_netcdf_list = {UINT32_C(0x602a001c),"netcdf_list",sxsh_netcdf_list_fields,SX_COUNT(sxsh_netcdf_list_fields),SX_BE};
static const xx_data_struct_field_desc sxsh_netcdf_name_size_fields[] = {
    SX_FIELD("name_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxsh_netcdf_name_size = {UINT32_C(0x602a001d),"netcdf_name_size",sxsh_netcdf_name_size_fields,SX_COUNT(sxsh_netcdf_name_size_fields),SX_BE};
static const xx_data_struct_field_desc sxsh_netcdf_dimension_fields[] = {
    SX_FIELD("dimension_length","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxsh_netcdf_dimension = {UINT32_C(0x602a001e),"netcdf_dimension",sxsh_netcdf_dimension_fields,SX_COUNT(sxsh_netcdf_dimension_fields),SX_BE};
static const xx_data_struct_field_desc sxsh_netcdf_rank_fields[] = {
    SX_FIELD("dimension_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxsh_netcdf_rank = {UINT32_C(0x602a001f),"netcdf_rank",sxsh_netcdf_rank_fields,SX_COUNT(sxsh_netcdf_rank_fields),SX_BE};
static const xx_data_struct_field_desc sxsh_netcdf_dimension_id_fields[] = {
    SX_FIELD("dimension_id","uint32",0,4,SX_ID),
};
static const sx_layout sxsh_netcdf_dimension_id = {UINT32_C(0x602a0020),"netcdf_dimension_id",sxsh_netcdf_dimension_id_fields,SX_COUNT(sxsh_netcdf_dimension_id_fields),SX_BE};
static const xx_data_struct_field_desc sxsh_netcdf_attribute_fields[] = {
    SX_FIELD("data_type","uint32",0,4,SX_ID),
    SX_FIELD("value_count","uint32",4,4,SX_COUNT_PROP),
};
static const sx_layout sxsh_netcdf_attribute = {UINT32_C(0x602a0021),"netcdf_attribute",sxsh_netcdf_attribute_fields,SX_COUNT(sxsh_netcdf_attribute_fields),SX_BE};
static const xx_data_struct_field_desc sxsh_netcdf_variable32_fields[] = {
    SX_FIELD("data_type","uint32",0,4,SX_ID),
    SX_FIELD("padded_size","uint32",4,4,SX_SIZE),
    SX_FIELD("data_offset","uint32",8,4,SX_OFFSET),
};
static const sx_layout sxsh_netcdf_variable32 = {UINT32_C(0x602a0022),"netcdf_variable32",sxsh_netcdf_variable32_fields,SX_COUNT(sxsh_netcdf_variable32_fields),SX_BE};
static const xx_data_struct_field_desc sxsh_netcdf_variable64_fields[] = {
    SX_FIELD("data_type","uint32",0,4,SX_ID),
    SX_FIELD("padded_size","uint32",4,4,SX_SIZE),
    SX_FIELD("data_offset","uint64",8,8,SX_OFFSET),
};
static const sx_layout sxsh_netcdf_variable64 = {UINT32_C(0x602a0023),"netcdf_variable64",sxsh_netcdf_variable64_fields,SX_COUNT(sxsh_netcdf_variable64_fields),SX_BE};
static const xx_data_struct_field_desc sxsh_fcs_header_fields[] = {
    SX_FIELD("version","char[6]",0,6,SX_ID),
    SX_FIELD("reserved","char[4]",6,4,SX_RESERVED),
    SX_FIELD("text_start","ascii_decimal[8]",10,8,SX_OFFSET),
    SX_FIELD("text_end","ascii_decimal[8]",18,8,SX_OFFSET),
    SX_FIELD("data_start","ascii_decimal[8]",26,8,SX_OFFSET),
    SX_FIELD("data_end","ascii_decimal[8]",34,8,SX_OFFSET),
    SX_FIELD("analysis_start","ascii_decimal[8]",42,8,SX_OFFSET),
    SX_FIELD("analysis_end","ascii_decimal[8]",50,8,SX_OFFSET),
};
static const sx_layout sxsh_fcs_header = {UINT32_C(0x602a0024),"fcs_header",sxsh_fcs_header_fields,SX_COUNT(sxsh_fcs_header_fields),SX_LE};
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
static const sx_layout sxsh_segy_binary_header = {UINT32_C(0x602a0030),"segy_binary_header",sxsh_segy_binary_header_fields,SX_COUNT(sxsh_segy_binary_header_fields),SX_BE};
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
static const sx_layout sxsh_segy_trace_header = {UINT32_C(0x602a0031),"segy_trace_header",sxsh_segy_trace_header_fields,SX_COUNT(sxsh_segy_trace_header_fields),SX_BE};
static const xx_data_struct_field_desc sxsh_segy_text_card_fields[] = {
    SX_FIELD("text_bytes","uint8[80]",0,80,SX_STRING),
};
static const sx_layout sxsh_segy_text_card = {UINT32_C(0x602a0032),"segy_text_card",sxsh_segy_text_card_fields,SX_COUNT(sxsh_segy_text_card_fields),SX_LE};
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
static uint16_t sxsh16(const uint8_t *p,bool be){return xx_data_get_u16(p,2,0,be);}
static uint32_t sxsh32(const uint8_t *p,bool be){return xx_data_get_u32(p,4,0,be);}
static bool sxsh_span(sx_context *c,int64_t at,uint64_t n){return c&&!xx_pd_is_stopped(c->pd)&&at>=0&&at<=c->size&&n<=(uint64_t)(c->size-at);}
static bool sxsh_add(sx_context *c,const sx_layout *l,int64_t at,int64_t bytes){return sxsh_span(c,at,(uint64_t)bytes)&&(c->count>=32000||sx_add(c,l,at,bytes));}
static bool sxsh_table(sx_context *c,const sx_layout *l,int64_t at,int64_t bytes,uint64_t count){return bytes>0&&count<=INT64_MAX/(uint64_t)bytes&&sxsh_span(c,at,(uint64_t)bytes*count)&&(c->count>=32000||sx_table(c,l,at,bytes,count));}
static int sxsh_order(const void *a,const void *b){const xx_data_struct *x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:x->total_size<y->total_size?-1:x->total_size>y->total_size?1:0;}
static bool sxsh_finish(sx_context *c)
{
 size_t n=c->count;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxsh_order);
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,bytes=c->items[i].total_size;if(at<end)return false;if(at>end&&!sx_raw(c,end,at-end))return false;end=at+bytes;}
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxsh_order);return !c->failed&&!xx_pd_is_stopped(c->pd);
}
static bool sxsh_nsx(sx_context *c)
{
 uint8_t b[314];if(!sx_read(c,0,b,314)||xx_rt_memcmp(b,"NEURALCD",8))return false;
 uint32_t count=sxsh32(b+310,false),header=sxsh32(b+10,false);int64_t at=header;
 if(!count||count>1024||header!=314U+66U*count||!sxsh_add(c,&sxsh_nsx_header,0,314)||!sxsh_table(c,&sxsh_nsx_channel,314,66,count))return false;
 for(unsigned i=0;at<c->size;i++){if(i>=4095||!sx_read(c,at,b,9)||b[0]!=1)return false;uint64_t n=(uint64_t)sxsh32(b+5,false)*count*2;if(!n||!sxsh_span(c,at+9,n)||!sxsh_add(c,&sxsh_nsx_packet,at,9))return false;at+=9+(int64_t)n;}
 return at==c->size;
}
static bool sxsh_nev(sx_context *c)
{
 uint8_t b[336];if(!sx_read(c,0,b,336)||xx_rt_memcmp(b,"NEURALEV",8))return false;
 uint32_t header=sxsh32(b+12,false),packet=sxsh32(b+16,false),count=sxsh32(b+332,false);
 if(count>1024||header!=336U+count*32U||packet<8||packet>65536||!sxsh_add(c,&sxsh_nev_header,0,336))return false;
 for(uint32_t i=0;i<count;i++){
  int64_t at=336+(int64_t)i*32;if(!sx_read(c,at,b,32))return false;const sx_layout *l=&sxsh_nev_extension;
  if(!xx_rt_memcmp(b,"NEUEVWAV",8))l=&sxsh_nev_waveform_extension;else if(!xx_rt_memcmp(b,"NEUEVLBL",8))l=&sxsh_nev_label_extension;else if(!xx_rt_memcmp(b,"NEUEVFLT",8))l=&sxsh_nev_filter_extension;
  else if(!xx_rt_memcmp(b,"ARRAYNME",8)||!xx_rt_memcmp(b,"ECOMMENT",8)||!xx_rt_memcmp(b,"CCOMMENT",8))l=&sxsh_nev_text_extension;
  if(!sxsh_add(c,l,at,32))return false;
 }
 int64_t at=header;
 for(unsigned i=0;at<c->size;i++){
  if(i>=4095||!sxsh_span(c,at,packet)||!sx_read(c,at,b,8))return false;bool digital=sxsh16(b+4,false)==0;
  if((digital&&packet<10)||!sxsh_add(c,digital?&sxsh_nev_digital:&sxsh_nev_spike,at,digital?10:8))return false;at+=packet;
 }return at==c->size;
}
static bool sxsh_dcd_record(sx_context *c,int64_t *at,bool be,uint32_t wanted,const sx_layout *payload)
{
 uint32_t n,tail;int64_t p=*at;
 if(!sx_u32(c,p,be,&n)||n!=wanted||!sxsh_span(c,p,(uint64_t)n+8)||!sx_u32(c,p+4+n,be,&tail)||tail!=n||!sxsh_add(c,be?&sxsh_dcd_record_size_be:&sxsh_dcd_record_size_le,p,4)||!sxsh_add(c,be?&sxsh_dcd_record_size_be:&sxsh_dcd_record_size_le,p+4+n,4))return false;
 if(payload&&!sxsh_add(c,payload,p+4,n))return false;*at=p+8+n;return true;
}
static bool sxsh_dcd(sx_context *c)
{
 uint8_t b[92];if(!sx_read(c,0,b,92)||xx_rt_memcmp(b+4,"CORD",4))return false;bool be=sxsh32(b,true)==84;
 uint32_t frames=sxsh32(b+8,be),cell=sxsh32(b+48,be),title,count,atoms;int64_t at=92;
 if(sxsh32(b,be)!=84||!frames||frames>1024||cell>1||!sxsh_add(c,be?&sxsh_dcd_header_be:&sxsh_dcd_header_le,0,92)||!sx_u32(c,at,be,&title)||title<84||title>2564||!sx_u32(c,at+4,be,&count)||count!=(title-4)/80||title!=4+count*80)return false;
 if(!sxsh_add(c,be?&sxsh_dcd_title_count_be:&sxsh_dcd_title_count_le,at+4,4)||!sxsh_table(c,&sxsh_dcd_title,at+8,80,count)||!sxsh_dcd_record(c,&at,be,title,NULL)||!sx_u32(c,at+4,be,&atoms)||!atoms||atoms>1048576||!sxsh_dcd_record(c,&at,be,4,be?&sxsh_dcd_atom_count_be:&sxsh_dcd_atom_count_le))return false;
 for(uint32_t i=0;i<frames;i++){
  if(cell&&!sxsh_dcd_record(c,&at,be,48,be?&sxsh_dcd_cell_be:&sxsh_dcd_cell_le))return false;
  for(unsigned j=0;j<3;j++)if(!sxsh_dcd_record(c,&at,be,atoms*4,NULL))return false;
 }return at==c->size;
}
static bool sxsh_trr(sx_context *c)
{
 int64_t at=0;
 for(unsigned frame=0;at<c->size;frame++){
  uint8_t b[76];if(frame>=512||!sx_read(c,at,b,76)||sxsh32(b,true)!=1993||sxsh32(b+4,true)!=13||sxsh32(b+8,true)!=12||xx_rt_memcmp(b+12,"GMX_trn_file\0",12))return false;
  uint32_t sizes[10],atoms=sxsh32(b+64,true),width=0;uint64_t bytes=0;
  if(!atoms||atoms>1048576)return false;for(unsigned i=0;i<10;i++){sizes[i]=sxsh32(b+24+i*4,true);bytes+=sizes[i];}
  if(sizes[2])width=sizes[2]/9;else for(unsigned i=7;i<10&&!width;i++)if(sizes[i])width=sizes[i]/(atoms*3);
  if((width!=4&&width!=8)||sizes[0]||sizes[1]||sizes[5]||sizes[6]||!sxsh_span(c,at,76+width*2+bytes)||!sxsh_add(c,&sxsh_trr_header,at,76)||!sxsh_add(c,width==4?&sxsh_trr_time32:&sxsh_trr_time64,at+76,width*2))return false;
  for(unsigned i=2;i<=4;i++)if(sizes[i]&&sizes[i]!=width*9)return false;
  for(unsigned i=7;i<10;i++)if(sizes[i]&&sizes[i]!=width*3*atoms)return false;
  at+=76+width*2+(int64_t)bytes;
 }return at>0&&at==c->size;
}
static bool sxsh_nc_name(sx_context *c,int64_t *at)
{
 uint32_t n;if(!sx_u32(c,*at,true,&n)||!n||n>255||!sxsh_span(c,*at,4+((n+3U)&~3U))||!sxsh_add(c,&sxsh_netcdf_name_size,*at,4))return false;*at+=4+((n+3U)&~3U);return true;
}
static bool sxsh_nc_list(sx_context *c,int64_t *at,uint32_t wanted,uint32_t limit,uint32_t *n)
{
 uint32_t tag;if(!sx_u32(c,*at,true,&tag)||!sx_u32(c,*at+4,true,n)||*n>limit||!((tag==0&&!*n)||tag==wanted)||!sxsh_add(c,&sxsh_netcdf_list,*at,8))return false;*at+=8;return true;
}
static bool sxsh_nc_attrs(sx_context *c,int64_t *at)
{
 uint32_t count;if(!sxsh_nc_list(c,at,12,1024,&count))return false;
 for(uint32_t i=0;i<count;i++){
  uint32_t type,n;if(!sxsh_nc_name(c,at)||!sx_u32(c,*at,true,&type)||!sx_u32(c,*at+4,true,&n)||!type||type>6||!sxsh_add(c,&sxsh_netcdf_attribute,*at,8))return false;
  uint32_t width=type<=2?1:type==3?2:type==6?8:4;uint64_t bytes=((uint64_t)n*width+3)&~UINT64_C(3);
  if(!sxsh_span(c,*at+8,bytes))return false;*at+=8+(int64_t)bytes;
 }return true;
}
static bool sxsh_nc(sx_context *c)
{
 uint8_t b[8];int64_t at=8;uint32_t dims,vars;
 if(!sx_read(c,0,b,8)||xx_rt_memcmp(b,"CDF",3)||(b[3]!=1&&b[3]!=2)||!sxsh_add(c,&sxsh_netcdf_header,0,8)||!sxsh_nc_list(c,&at,10,128,&dims))return false;
 for(uint32_t i=0;i<dims;i++){if(!sxsh_nc_name(c,&at)||!sxsh_add(c,&sxsh_netcdf_dimension,at,4))return false;at+=4;}
 if(!sxsh_nc_attrs(c,&at)||!sxsh_nc_list(c,&at,11,256,&vars)||!vars)return false;
 for(uint32_t i=0;i<vars;i++){
  uint32_t n;if(!sxsh_nc_name(c,&at)||!sx_u32(c,at,true,&n)||n>128||!sxsh_add(c,&sxsh_netcdf_rank,at,4)||!sxsh_table(c,&sxsh_netcdf_dimension_id,at+4,4,n))return false;
  for(uint32_t j=0;j<n;j++){uint32_t id;if(!sx_u32(c,at+4+j*4,true,&id)||id>=dims)return false;}
  at+=4+(int64_t)n*4;if(!sxsh_nc_attrs(c,&at)||!sxsh_add(c,b[3]==1?&sxsh_netcdf_variable32:&sxsh_netcdf_variable64,at,b[3]==1?12:16))return false;at+=b[3]==1?12:16;
 }return true;
}
static bool sxsh_decimal(sx_context *c,int64_t at,unsigned width,uint64_t *v)
{
 uint8_t b[16];if(width>sizeof(b)||!sx_read(c,at,b,width))return false;bool digit=false,space=false;*v=0;
 for(unsigned i=0;i<width;i++){if(b[i]==' '){if(digit)space=true;continue;}if(b[i]<'0'||b[i]>'9'||space)return false;digit=true;*v=*v*10+(unsigned)(b[i]-'0');}return digit;
}
static bool sxsh_edf(sx_context *c)
{
 uint64_t header,count;if(!sxsh_decimal(c,184,8,&header)||!sxsh_decimal(c,252,4,&count)||!count||count>512||header!=256*(count+1)||!sxsh_span(c,0,header)||!sxsh_add(c,&sxsh_edf_header,0,256))return false;
 const sx_layout *l[]={&sxsh_edf_signal_label,&sxsh_edf_signal_transducer,&sxsh_edf_signal_physical_dimension,&sxsh_edf_signal_physical_min,&sxsh_edf_signal_physical_max,&sxsh_edf_signal_digital_min,&sxsh_edf_signal_digital_max,&sxsh_edf_signal_prefilter,&sxsh_edf_signal_samples,&sxsh_edf_signal_reserved};
 const unsigned widths[]={16,80,8,8,8,8,8,80,8,32};int64_t at=256;
 for(unsigned i=0;i<SX_COUNT(l);i++){if(!sxsh_table(c,l[i],at,widths[i],count))return false;at+=(int64_t)widths[i]*(int64_t)count;}return (uint64_t)at==header;
}
static bool sxsh_segy(sx_context *c)
{
 uint8_t b[400];if(!sx_read(c,3200,b,400)||!sxsh_table(c,&sxsh_segy_text_card,0,80,40)||!sxsh_add(c,&sxsh_segy_binary_header,3200,400))return false;
 unsigned ext=sxsh16(b+304,true),fmt=sxsh16(b+24,true),width=fmt==1||fmt==2||fmt==5?4:fmt==3?2:fmt==8?1:0;
 if(!width||ext>16||!sxsh_table(c,&sxsh_segy_text_card,3600,80,ext*40))return false;int64_t at=3600+ext*3200;
 for(unsigned i=0;at<c->size;i++){uint16_t n;if(i>=1024||!sxsh_span(c,at,240)||!sx_u16(c,at+114,true,&n)||!n||!sxsh_span(c,at,240+(uint64_t)n*width)||!sxsh_add(c,&sxsh_segy_trace_header,at,240))return false;at+=240+(int64_t)n*width;}
 return at==c->size;
}
static bool sx_scienceheaders_build(sx_context *c)
{
 if(!c||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;
 switch(c->f->file_type){case XX_FILE_TYPE_BLACKROCK_NSX:ok=sxsh_nsx(c);break;case XX_FILE_TYPE_BLACKROCK_NEV:ok=sxsh_nev(c);break;case XX_FILE_TYPE_PRINCETON_SPE:ok=sxsh_add(c,&sxsh_spe_header,0,4100);break;case XX_FILE_TYPE_CHARMM_DCD:ok=sxsh_dcd(c);break;case XX_FILE_TYPE_GROMACS_TRR:ok=sxsh_trr(c);break;case XX_FILE_TYPE_NETCDF_CLASSIC:ok=sxsh_nc(c);break;case XX_FILE_TYPE_FCS:ok=sxsh_add(c,&sxsh_fcs_header,0,58);break;case XX_FILE_TYPE_EDF:case XX_FILE_TYPE_BIOMEDICAL_BDF:ok=sxsh_edf(c);break;case XX_FILE_TYPE_SEISMIC_SEGY:ok=sxsh_segy(c);break;default:return false;}
 return ok&&sxsh_finish(c);
}
