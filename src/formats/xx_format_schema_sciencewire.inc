/* SPDX-License-Identifier: MIT
 * Scientific file metadata. Scope: docs/data_struct_sciencewire_scope.txt. */
static const xx_data_struct_field_desc sxsw_fits_card_fields[] = {
    SX_FIELD("keyword","char[8]",0,8,SX_ID),
    SX_FIELD("value_and_comment","char[72]",8,72,SX_STRING),
};
static const sx_layout sxsw_fits_card = {UINT32_C(0x602d0001),"fits_card",sxsw_fits_card_fields,SX_COUNT(sxsw_fits_card_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_fits_integer_card_fields[] = {
    SX_FIELD("keyword","char[8]",0,8,SX_ID),
    SX_FIELD("indicator","char[2]",8,2,SX_NONE),
    SX_FIELD("integer_text","char[20]",10,20,SX_STRING),
    SX_FIELD("comment","char[50]",30,50,SX_STRING),
};
static const sx_layout sxsw_fits_integer_card = {UINT32_C(0x602d0002),"fits_integer_card",sxsw_fits_integer_card_fields,SX_COUNT(sxsw_fits_integer_card_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_xport_header_record_fields[] = {
    SX_FIELD("prefix","char[20]",0,20,SX_SIGNATURE),
    SX_FIELD("record_name","char[8]",20,8,SX_ID),
    SX_FIELD("suffix","char[20]",28,20,SX_SIGNATURE),
    SX_FIELD("field1","ascii_decimal[5]",48,5,SX_NONE),
    SX_FIELD("field2","ascii_decimal[5]",53,5,SX_NONE),
    SX_FIELD("field3","ascii_decimal[5]",58,5,SX_NONE),
    SX_FIELD("field4","ascii_decimal[5]",63,5,SX_NONE),
    SX_FIELD("field5","ascii_decimal[5]",68,5,SX_NONE),
    SX_FIELD("field6","ascii_decimal[5]",73,5,SX_NONE),
    SX_FIELD("padding","char[2]",78,2,SX_RESERVED),
};
static const sx_layout sxsw_xport_header_record = {UINT32_C(0x602d0003),"xport_header_record",sxsw_xport_header_record_fields,SX_COUNT(sxsw_xport_header_record_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_xport_namestr_fields[] = {
    SX_FIELD("type","uint16",0,2,SX_ID),
    SX_FIELD("hash_function","uint16",2,2,SX_RESERVED),
    SX_FIELD("length","uint16",4,2,SX_SIZE),
    SX_FIELD("variable_number","uint16",6,2,SX_ID),
    SX_FIELD("name","char[8]",8,8,SX_STRING),
    SX_FIELD("label","char[40]",16,40,SX_STRING),
    SX_FIELD("format","char[8]",56,8,SX_STRING),
    SX_FIELD("format_width","uint16",64,2,SX_NONE),
    SX_FIELD("format_decimals","uint16",66,2,SX_NONE),
    SX_FIELD("justification","uint16",68,2,SX_ID),
    SX_FIELD("reserved1","char[2]",70,2,SX_RESERVED),
    SX_FIELD("informat","char[8]",72,8,SX_STRING),
    SX_FIELD("informat_width","uint16",80,2,SX_NONE),
    SX_FIELD("informat_decimals","uint16",82,2,SX_NONE),
    SX_FIELD("observation_offset","uint32",84,4,SX_OFFSET),
    SX_FIELD("reserved2","uint8[52]",88,52,SX_RESERVED),
};
static const sx_layout sxsw_xport_namestr = {UINT32_C(0x602d0004),"xport_namestr",sxsw_xport_namestr_fields,SX_COUNT(sxsw_xport_namestr_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_sav_header_le_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("product","char[60]",4,60,SX_STRING),
    SX_FIELD("layout_code","int32",64,4,SX_ID),
    SX_FIELD("case_size","int32",68,4,SX_COUNT_PROP),
    SX_FIELD("compression","int32",72,4,SX_ID),
    SX_FIELD("weight_index","int32",76,4,SX_ID),
    SX_FIELD("case_count","int32",80,4,SX_COUNT_PROP),
    SX_FIELD("bias","float64",84,8,SX_NONE),
    SX_FIELD("creation_date","char[9]",92,9,SX_STRING),
    SX_FIELD("creation_time","char[8]",101,8,SX_STRING),
    SX_FIELD("file_label","char[64]",109,64,SX_STRING),
    SX_FIELD("padding","uint8[3]",173,3,SX_RESERVED),
};
static const sx_layout sxsw_sav_header_le = {UINT32_C(0x602d0005),"sav_header_le",sxsw_sav_header_le_fields,SX_COUNT(sxsw_sav_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_sav_variable_le_fields[] = {
    SX_FIELD("record_type","int32",0,4,SX_ID),
    SX_FIELD("variable_type","int32",4,4,SX_ID),
    SX_FIELD("has_label","int32",8,4,SX_FLAGS),
    SX_FIELD("missing_value_count","int32",12,4,SX_NONE),
    SX_FIELD("print_format","int32",16,4,SX_FLAGS),
    SX_FIELD("write_format","int32",20,4,SX_FLAGS),
    SX_FIELD("name","char[8]",24,8,SX_STRING),
};
static const sx_layout sxsw_sav_variable_le = {UINT32_C(0x602d0006),"sav_variable_le",sxsw_sav_variable_le_fields,SX_COUNT(sxsw_sav_variable_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_sav_extension_le_fields[] = {
    SX_FIELD("record_type","int32",0,4,SX_ID),
    SX_FIELD("subtype","int32",4,4,SX_ID),
    SX_FIELD("entry_size","int32",8,4,SX_SIZE),
    SX_FIELD("entry_count","int32",12,4,SX_COUNT_PROP),
};
static const sx_layout sxsw_sav_extension_le = {UINT32_C(0x602d0007),"sav_extension_le",sxsw_sav_extension_le_fields,SX_COUNT(sxsw_sav_extension_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_sav_count_record_le_fields[] = {
    SX_FIELD("record_type","int32",0,4,SX_ID),
    SX_FIELD("count","int32",4,4,SX_COUNT_PROP),
};
static const sx_layout sxsw_sav_count_record_le = {UINT32_C(0x602d0008),"sav_count_record_le",sxsw_sav_count_record_le_fields,SX_COUNT(sxsw_sav_count_record_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_sav_dictionary_end_le_fields[] = {
    SX_FIELD("record_type","int32",0,4,SX_ID),
    SX_FIELD("filler","int32",4,4,SX_RESERVED),
};
static const sx_layout sxsw_sav_dictionary_end_le = {UINT32_C(0x602d0009),"sav_dictionary_end_le",sxsw_sav_dictionary_end_le_fields,SX_COUNT(sxsw_sav_dictionary_end_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_sav_label_size_le_fields[] = {
    SX_FIELD("label_size","int32",0,4,SX_SIZE),
};
static const sx_layout sxsw_sav_label_size_le = {UINT32_C(0x602d000a),"sav_label_size_le",sxsw_sav_label_size_le_fields,SX_COUNT(sxsw_sav_label_size_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_sav_variable_index_le_fields[] = {
    SX_FIELD("variable_index","int32",0,4,SX_ID),
};
static const sx_layout sxsw_sav_variable_index_le = {UINT32_C(0x602d000b),"sav_variable_index_le",sxsw_sav_variable_index_le_fields,SX_COUNT(sxsw_sav_variable_index_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_sav_value_label_le_fields[] = {
    SX_FIELD("value_bytes","uint8[8]",0,8,SX_NONE),
    SX_FIELD("label_size","uint8",8,1,SX_SIZE),
};
static const sx_layout sxsw_sav_value_label_le = {UINT32_C(0x602d000c),"sav_value_label_le",sxsw_sav_value_label_le_fields,SX_COUNT(sxsw_sav_value_label_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_sav_machine_integer_le_fields[] = {
    SX_FIELD("version_major","int32",0,4,SX_ID),
    SX_FIELD("version_minor","int32",4,4,SX_ID),
    SX_FIELD("version_revision","int32",8,4,SX_ID),
    SX_FIELD("machine_code","int32",12,4,SX_ID),
    SX_FIELD("floating_point_representation","int32",16,4,SX_ID),
    SX_FIELD("compression_code","int32",20,4,SX_ID),
    SX_FIELD("endianness","int32",24,4,SX_ID),
    SX_FIELD("character_code","int32",28,4,SX_ID),
};
static const sx_layout sxsw_sav_machine_integer_le = {UINT32_C(0x602d000d),"sav_machine_integer_le",sxsw_sav_machine_integer_le_fields,SX_COUNT(sxsw_sav_machine_integer_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_sav_header_be_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("product","char[60]",4,60,SX_STRING),
    SX_FIELD("layout_code","int32",64,4,SX_ID),
    SX_FIELD("case_size","int32",68,4,SX_COUNT_PROP),
    SX_FIELD("compression","int32",72,4,SX_ID),
    SX_FIELD("weight_index","int32",76,4,SX_ID),
    SX_FIELD("case_count","int32",80,4,SX_COUNT_PROP),
    SX_FIELD("bias","float64",84,8,SX_NONE),
    SX_FIELD("creation_date","char[9]",92,9,SX_STRING),
    SX_FIELD("creation_time","char[8]",101,8,SX_STRING),
    SX_FIELD("file_label","char[64]",109,64,SX_STRING),
    SX_FIELD("padding","uint8[3]",173,3,SX_RESERVED),
};
static const sx_layout sxsw_sav_header_be = {UINT32_C(0x602d000e),"sav_header_be",sxsw_sav_header_be_fields,SX_COUNT(sxsw_sav_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_sav_variable_be_fields[] = {
    SX_FIELD("record_type","int32",0,4,SX_ID),
    SX_FIELD("variable_type","int32",4,4,SX_ID),
    SX_FIELD("has_label","int32",8,4,SX_FLAGS),
    SX_FIELD("missing_value_count","int32",12,4,SX_NONE),
    SX_FIELD("print_format","int32",16,4,SX_FLAGS),
    SX_FIELD("write_format","int32",20,4,SX_FLAGS),
    SX_FIELD("name","char[8]",24,8,SX_STRING),
};
static const sx_layout sxsw_sav_variable_be = {UINT32_C(0x602d000f),"sav_variable_be",sxsw_sav_variable_be_fields,SX_COUNT(sxsw_sav_variable_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_sav_extension_be_fields[] = {
    SX_FIELD("record_type","int32",0,4,SX_ID),
    SX_FIELD("subtype","int32",4,4,SX_ID),
    SX_FIELD("entry_size","int32",8,4,SX_SIZE),
    SX_FIELD("entry_count","int32",12,4,SX_COUNT_PROP),
};
static const sx_layout sxsw_sav_extension_be = {UINT32_C(0x602d0010),"sav_extension_be",sxsw_sav_extension_be_fields,SX_COUNT(sxsw_sav_extension_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_sav_count_record_be_fields[] = {
    SX_FIELD("record_type","int32",0,4,SX_ID),
    SX_FIELD("count","int32",4,4,SX_COUNT_PROP),
};
static const sx_layout sxsw_sav_count_record_be = {UINT32_C(0x602d0011),"sav_count_record_be",sxsw_sav_count_record_be_fields,SX_COUNT(sxsw_sav_count_record_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_sav_dictionary_end_be_fields[] = {
    SX_FIELD("record_type","int32",0,4,SX_ID),
    SX_FIELD("filler","int32",4,4,SX_RESERVED),
};
static const sx_layout sxsw_sav_dictionary_end_be = {UINT32_C(0x602d0012),"sav_dictionary_end_be",sxsw_sav_dictionary_end_be_fields,SX_COUNT(sxsw_sav_dictionary_end_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_sav_label_size_be_fields[] = {
    SX_FIELD("label_size","int32",0,4,SX_SIZE),
};
static const sx_layout sxsw_sav_label_size_be = {UINT32_C(0x602d0013),"sav_label_size_be",sxsw_sav_label_size_be_fields,SX_COUNT(sxsw_sav_label_size_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_sav_variable_index_be_fields[] = {
    SX_FIELD("variable_index","int32",0,4,SX_ID),
};
static const sx_layout sxsw_sav_variable_index_be = {UINT32_C(0x602d0014),"sav_variable_index_be",sxsw_sav_variable_index_be_fields,SX_COUNT(sxsw_sav_variable_index_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_sav_value_label_be_fields[] = {
    SX_FIELD("value_bytes","uint8[8]",0,8,SX_NONE),
    SX_FIELD("label_size","uint8",8,1,SX_SIZE),
};
static const sx_layout sxsw_sav_value_label_be = {UINT32_C(0x602d0015),"sav_value_label_be",sxsw_sav_value_label_be_fields,SX_COUNT(sxsw_sav_value_label_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_sav_machine_integer_be_fields[] = {
    SX_FIELD("version_major","int32",0,4,SX_ID),
    SX_FIELD("version_minor","int32",4,4,SX_ID),
    SX_FIELD("version_revision","int32",8,4,SX_ID),
    SX_FIELD("machine_code","int32",12,4,SX_ID),
    SX_FIELD("floating_point_representation","int32",16,4,SX_ID),
    SX_FIELD("compression_code","int32",20,4,SX_ID),
    SX_FIELD("endianness","int32",24,4,SX_ID),
    SX_FIELD("character_code","int32",28,4,SX_ID),
};
static const sx_layout sxsw_sav_machine_integer_be = {UINT32_C(0x602d0016),"sav_machine_integer_be",sxsw_sav_machine_integer_be_fields,SX_COUNT(sxsw_sav_machine_integer_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_sav_document_line_fields[] = {
    SX_FIELD("text","char[80]",0,80,SX_STRING),
};
static const sx_layout sxsw_sav_document_line = {UINT32_C(0x602d0017),"sav_document_line",sxsw_sav_document_line_fields,SX_COUNT(sxsw_sav_document_line_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_bgen_header_fields[] = {
    SX_FIELD("first_variant_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("header_size","uint32",4,4,SX_SIZE),
    SX_FIELD("variant_count","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("sample_count","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("signature","char[4]",16,4,SX_SIGNATURE),
};
static const sx_layout sxsw_bgen_header = {UINT32_C(0x602d0018),"bgen_header",sxsw_bgen_header_fields,SX_COUNT(sxsw_bgen_header_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_bgen_flags_fields[] = {
    SX_FIELD("flags","uint32",0,4,SX_FLAGS),
};
static const sx_layout sxsw_bgen_flags = {UINT32_C(0x602d0019),"bgen_flags",sxsw_bgen_flags_fields,SX_COUNT(sxsw_bgen_flags_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_bgen_sample_header_fields[] = {
    SX_FIELD("block_size","uint32",0,4,SX_SIZE),
    SX_FIELD("sample_count","uint32",4,4,SX_COUNT_PROP),
};
static const sx_layout sxsw_bgen_sample_header = {UINT32_C(0x602d001a),"bgen_sample_header",sxsw_bgen_sample_header_fields,SX_COUNT(sxsw_bgen_sample_header_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_bgen_string16_fields[] = {
    SX_FIELD("string_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxsw_bgen_string16 = {UINT32_C(0x602d001b),"bgen_string16",sxsw_bgen_string16_fields,SX_COUNT(sxsw_bgen_string16_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_bgen_string32_fields[] = {
    SX_FIELD("string_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxsw_bgen_string32 = {UINT32_C(0x602d001c),"bgen_string32",sxsw_bgen_string32_fields,SX_COUNT(sxsw_bgen_string32_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_bgen_variant_sample_count_fields[] = {
    SX_FIELD("sample_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxsw_bgen_variant_sample_count = {UINT32_C(0x602d001d),"bgen_variant_sample_count",sxsw_bgen_variant_sample_count_fields,SX_COUNT(sxsw_bgen_variant_sample_count_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_bgen_variant_position_fields[] = {
    SX_FIELD("position","uint32",0,4,SX_NONE),
};
static const sx_layout sxsw_bgen_variant_position = {UINT32_C(0x602d001e),"bgen_variant_position",sxsw_bgen_variant_position_fields,SX_COUNT(sxsw_bgen_variant_position_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_igor_binary5_le_fields[] = {
    SX_FIELD("version","int16",0,2,SX_ID),
    SX_FIELD("checksum","int16",2,2,SX_CHECKSUM),
    SX_FIELD("wfmSize","int32",4,4,SX_SIZE),
    SX_FIELD("formulaSize","int32",8,4,SX_SIZE),
    SX_FIELD("noteSize","int32",12,4,SX_SIZE),
    SX_FIELD("dataEUnitsSize","int32",16,4,SX_SIZE),
    SX_FIELD("dimEUnitsSize0","int32",20,4,SX_SIZE),
    SX_FIELD("dimEUnitsSize1","int32",24,4,SX_SIZE),
    SX_FIELD("dimEUnitsSize2","int32",28,4,SX_SIZE),
    SX_FIELD("dimEUnitsSize3","int32",32,4,SX_SIZE),
    SX_FIELD("dimLabelsSize0","int32",36,4,SX_SIZE),
    SX_FIELD("dimLabelsSize1","int32",40,4,SX_SIZE),
    SX_FIELD("dimLabelsSize2","int32",44,4,SX_SIZE),
    SX_FIELD("dimLabelsSize3","int32",48,4,SX_SIZE),
    SX_FIELD("sIndicesSize","int32",52,4,SX_SIZE),
    SX_FIELD("optionsSize1","int32",56,4,SX_RESERVED),
    SX_FIELD("optionsSize2","int32",60,4,SX_RESERVED),
};
static const sx_layout sxsw_igor_binary5_le = {UINT32_C(0x602d001f),"igor_binary5_le",sxsw_igor_binary5_le_fields,SX_COUNT(sxsw_igor_binary5_le_fields),SX_LE};
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
static const sx_layout sxsw_igor_wave5_le = {UINT32_C(0x602d0020),"igor_wave5_le",sxsw_igor_wave5_le_fields,SX_COUNT(sxsw_igor_wave5_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_igor_binary5_be_fields[] = {
    SX_FIELD("version","int16",0,2,SX_ID),
    SX_FIELD("checksum","int16",2,2,SX_CHECKSUM),
    SX_FIELD("wfmSize","int32",4,4,SX_SIZE),
    SX_FIELD("formulaSize","int32",8,4,SX_SIZE),
    SX_FIELD("noteSize","int32",12,4,SX_SIZE),
    SX_FIELD("dataEUnitsSize","int32",16,4,SX_SIZE),
    SX_FIELD("dimEUnitsSize0","int32",20,4,SX_SIZE),
    SX_FIELD("dimEUnitsSize1","int32",24,4,SX_SIZE),
    SX_FIELD("dimEUnitsSize2","int32",28,4,SX_SIZE),
    SX_FIELD("dimEUnitsSize3","int32",32,4,SX_SIZE),
    SX_FIELD("dimLabelsSize0","int32",36,4,SX_SIZE),
    SX_FIELD("dimLabelsSize1","int32",40,4,SX_SIZE),
    SX_FIELD("dimLabelsSize2","int32",44,4,SX_SIZE),
    SX_FIELD("dimLabelsSize3","int32",48,4,SX_SIZE),
    SX_FIELD("sIndicesSize","int32",52,4,SX_SIZE),
    SX_FIELD("optionsSize1","int32",56,4,SX_RESERVED),
    SX_FIELD("optionsSize2","int32",60,4,SX_RESERVED),
};
static const sx_layout sxsw_igor_binary5_be = {UINT32_C(0x602d0021),"igor_binary5_be",sxsw_igor_binary5_be_fields,SX_COUNT(sxsw_igor_binary5_be_fields),SX_BE};
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
static const sx_layout sxsw_igor_wave5_be = {UINT32_C(0x602d0022),"igor_wave5_be",sxsw_igor_wave5_be_fields,SX_COUNT(sxsw_igor_wave5_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_spider_header_le_fields[] = {
    SX_FIELD("slices","float32",0,4,SX_COUNT_PROP),
    SX_FIELD("rows","float32",4,4,SX_COUNT_PROP),
    SX_FIELD("records","float32",8,4,SX_COUNT_PROP),
    SX_FIELD("unused3","float32",12,4,SX_RESERVED),
    SX_FIELD("iform","float32",16,4,SX_ID),
    SX_FIELD("statistics_valid","float32",20,4,SX_NONE),
    SX_FIELD("maximum","float32",24,4,SX_NONE),
    SX_FIELD("minimum","float32",28,4,SX_NONE),
    SX_FIELD("average","float32",32,4,SX_NONE),
    SX_FIELD("standard_deviation","float32",36,4,SX_NONE),
    SX_FIELD("unused10","float32",40,4,SX_RESERVED),
    SX_FIELD("columns","float32",44,4,SX_COUNT_PROP),
    SX_FIELD("header_records","float32",48,4,SX_COUNT_PROP),
    SX_FIELD("angle_valid","float32",52,4,SX_NONE),
    SX_FIELD("phi","float32",56,4,SX_NONE),
    SX_FIELD("theta","float32",60,4,SX_NONE),
    SX_FIELD("gamma","float32",64,4,SX_NONE),
    SX_FIELD("x_offset","float32",68,4,SX_NONE),
    SX_FIELD("y_offset","float32",72,4,SX_NONE),
    SX_FIELD("z_offset","float32",76,4,SX_NONE),
    SX_FIELD("scale","float32",80,4,SX_NONE),
    SX_FIELD("header_size","float32",84,4,SX_SIZE),
    SX_FIELD("record_size","float32",88,4,SX_SIZE),
    SX_FIELD("stack","float32",92,4,SX_NONE),
    SX_FIELD("unused24","float32",96,4,SX_RESERVED),
    SX_FIELD("highest_image_number","float32",100,4,SX_NONE),
    SX_FIELD("image_number","float32",104,4,SX_NONE),
    SX_FIELD("last_index","float32",108,4,SX_NONE),
    SX_FIELD("opaque_70","uint8[8]",112,8,SX_NONE),
    SX_FIELD("additional_angle_sets","float32",120,4,SX_NONE),
    SX_FIELD("phi1","float32",124,4,SX_NONE),
    SX_FIELD("theta1","float32",128,4,SX_NONE),
    SX_FIELD("psi1","float32",132,4,SX_NONE),
    SX_FIELD("phi2","float32",136,4,SX_NONE),
    SX_FIELD("theta2","float32",140,4,SX_NONE),
    SX_FIELD("psi2","float32",144,4,SX_NONE),
    SX_FIELD("pixel_size","float32",148,4,SX_NONE),
    SX_FIELD("electron_voltage","float32",152,4,SX_NONE),
    SX_FIELD("project_number","float32",156,4,SX_NONE),
    SX_FIELD("micrograph_number","float32",160,4,SX_NONE),
    SX_FIELD("window_number","float32",164,4,SX_NONE),
    SX_FIELD("global_image_number","float32",168,4,SX_NONE),
    SX_FIELD("opaque_ac","uint8[228]",172,228,SX_NONE),
    SX_FIELD("psi3","float32",400,4,SX_NONE),
    SX_FIELD("theta3","float32",404,4,SX_NONE),
    SX_FIELD("phi3","float32",408,4,SX_NONE),
    SX_FIELD("projection_angles_present","float32",412,4,SX_NONE),
    SX_FIELD("opaque_1a0","uint8[428]",416,428,SX_NONE),
    SX_FIELD("creation_date","char[11]",844,11,SX_STRING),
    SX_FIELD("date_padding","uint8",855,1,SX_NONE),
    SX_FIELD("creation_time","char[8]",856,8,SX_STRING),
    SX_FIELD("title","char[160]",864,160,SX_STRING),
};
static const sx_layout sxsw_spider_header_le = {UINT32_C(0x602d0023),"spider_header_le",sxsw_spider_header_le_fields,SX_COUNT(sxsw_spider_header_le_fields),SX_LE};
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
static const sx_layout sxsw_lecroy_descriptor_le = {UINT32_C(0x602d0024),"lecroy_descriptor_le",sxsw_lecroy_descriptor_le_fields,SX_COUNT(sxsw_lecroy_descriptor_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_lecroy_trigger_time_le_fields[] = {
    SX_FIELD("trigger_time","float64",0,8,SX_NONE),
    SX_FIELD("time_offset","float64",8,8,SX_NONE),
};
static const sx_layout sxsw_lecroy_trigger_time_le = {UINT32_C(0x602d0025),"lecroy_trigger_time_le",sxsw_lecroy_trigger_time_le_fields,SX_COUNT(sxsw_lecroy_trigger_time_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_lecroy_ris_time_le_fields[] = {
    SX_FIELD("ris_time","float64",0,8,SX_NONE),
};
static const sx_layout sxsw_lecroy_ris_time_le = {UINT32_C(0x602d0026),"lecroy_ris_time_le",sxsw_lecroy_ris_time_le_fields,SX_COUNT(sxsw_lecroy_ris_time_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_spider_header_be_fields[] = {
    SX_FIELD("slices","float32",0,4,SX_COUNT_PROP),
    SX_FIELD("rows","float32",4,4,SX_COUNT_PROP),
    SX_FIELD("records","float32",8,4,SX_COUNT_PROP),
    SX_FIELD("unused3","float32",12,4,SX_RESERVED),
    SX_FIELD("iform","float32",16,4,SX_ID),
    SX_FIELD("statistics_valid","float32",20,4,SX_NONE),
    SX_FIELD("maximum","float32",24,4,SX_NONE),
    SX_FIELD("minimum","float32",28,4,SX_NONE),
    SX_FIELD("average","float32",32,4,SX_NONE),
    SX_FIELD("standard_deviation","float32",36,4,SX_NONE),
    SX_FIELD("unused10","float32",40,4,SX_RESERVED),
    SX_FIELD("columns","float32",44,4,SX_COUNT_PROP),
    SX_FIELD("header_records","float32",48,4,SX_COUNT_PROP),
    SX_FIELD("angle_valid","float32",52,4,SX_NONE),
    SX_FIELD("phi","float32",56,4,SX_NONE),
    SX_FIELD("theta","float32",60,4,SX_NONE),
    SX_FIELD("gamma","float32",64,4,SX_NONE),
    SX_FIELD("x_offset","float32",68,4,SX_NONE),
    SX_FIELD("y_offset","float32",72,4,SX_NONE),
    SX_FIELD("z_offset","float32",76,4,SX_NONE),
    SX_FIELD("scale","float32",80,4,SX_NONE),
    SX_FIELD("header_size","float32",84,4,SX_SIZE),
    SX_FIELD("record_size","float32",88,4,SX_SIZE),
    SX_FIELD("stack","float32",92,4,SX_NONE),
    SX_FIELD("unused24","float32",96,4,SX_RESERVED),
    SX_FIELD("highest_image_number","float32",100,4,SX_NONE),
    SX_FIELD("image_number","float32",104,4,SX_NONE),
    SX_FIELD("last_index","float32",108,4,SX_NONE),
    SX_FIELD("opaque_70","uint8[8]",112,8,SX_NONE),
    SX_FIELD("additional_angle_sets","float32",120,4,SX_NONE),
    SX_FIELD("phi1","float32",124,4,SX_NONE),
    SX_FIELD("theta1","float32",128,4,SX_NONE),
    SX_FIELD("psi1","float32",132,4,SX_NONE),
    SX_FIELD("phi2","float32",136,4,SX_NONE),
    SX_FIELD("theta2","float32",140,4,SX_NONE),
    SX_FIELD("psi2","float32",144,4,SX_NONE),
    SX_FIELD("pixel_size","float32",148,4,SX_NONE),
    SX_FIELD("electron_voltage","float32",152,4,SX_NONE),
    SX_FIELD("project_number","float32",156,4,SX_NONE),
    SX_FIELD("micrograph_number","float32",160,4,SX_NONE),
    SX_FIELD("window_number","float32",164,4,SX_NONE),
    SX_FIELD("global_image_number","float32",168,4,SX_NONE),
    SX_FIELD("opaque_ac","uint8[228]",172,228,SX_NONE),
    SX_FIELD("psi3","float32",400,4,SX_NONE),
    SX_FIELD("theta3","float32",404,4,SX_NONE),
    SX_FIELD("phi3","float32",408,4,SX_NONE),
    SX_FIELD("projection_angles_present","float32",412,4,SX_NONE),
    SX_FIELD("opaque_1a0","uint8[428]",416,428,SX_NONE),
    SX_FIELD("creation_date","char[11]",844,11,SX_STRING),
    SX_FIELD("date_padding","uint8",855,1,SX_NONE),
    SX_FIELD("creation_time","char[8]",856,8,SX_STRING),
    SX_FIELD("title","char[160]",864,160,SX_STRING),
};
static const sx_layout sxsw_spider_header_be = {UINT32_C(0x602d0027),"spider_header_be",sxsw_spider_header_be_fields,SX_COUNT(sxsw_spider_header_be_fields),SX_BE};
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
static const sx_layout sxsw_lecroy_descriptor_be = {UINT32_C(0x602d0028),"lecroy_descriptor_be",sxsw_lecroy_descriptor_be_fields,SX_COUNT(sxsw_lecroy_descriptor_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_lecroy_trigger_time_be_fields[] = {
    SX_FIELD("trigger_time","float64",0,8,SX_NONE),
    SX_FIELD("time_offset","float64",8,8,SX_NONE),
};
static const sx_layout sxsw_lecroy_trigger_time_be = {UINT32_C(0x602d0029),"lecroy_trigger_time_be",sxsw_lecroy_trigger_time_be_fields,SX_COUNT(sxsw_lecroy_trigger_time_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_lecroy_ris_time_be_fields[] = {
    SX_FIELD("ris_time","float64",0,8,SX_NONE),
};
static const sx_layout sxsw_lecroy_ris_time_be = {UINT32_C(0x602d002a),"lecroy_ris_time_be",sxsw_lecroy_ris_time_be_fields,SX_COUNT(sxsw_lecroy_ris_time_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_grib2_indicator_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("reserved","uint8[2]",4,2,SX_RESERVED),
    SX_FIELD("discipline","uint8",6,1,SX_ID),
    SX_FIELD("edition","uint8",7,1,SX_ID),
    SX_FIELD("total_size","uint64",8,8,SX_SIZE),
};
static const sx_layout sxsw_grib2_indicator = {UINT32_C(0x602d002b),"grib2_indicator",sxsw_grib2_indicator_fields,SX_COUNT(sxsw_grib2_indicator_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_grib2_section_fields[] = {
    SX_FIELD("section_size","uint32",0,4,SX_SIZE),
    SX_FIELD("section_number","uint8",4,1,SX_ID),
};
static const sx_layout sxsw_grib2_section = {UINT32_C(0x602d002c),"grib2_section",sxsw_grib2_section_fields,SX_COUNT(sxsw_grib2_section_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_grib2_identification_fields[] = {
    SX_FIELD("section_size","uint32",0,4,SX_SIZE),
    SX_FIELD("section_number","uint8",4,1,SX_ID),
    SX_FIELD("centre","uint16",5,2,SX_ID),
    SX_FIELD("subcentre","uint16",7,2,SX_ID),
    SX_FIELD("master_table","uint8",9,1,SX_ID),
    SX_FIELD("local_table","uint8",10,1,SX_ID),
    SX_FIELD("reference_time_significance","uint8",11,1,SX_ID),
    SX_FIELD("year","uint16",12,2,SX_NONE),
    SX_FIELD("month","uint8",14,1,SX_NONE),
    SX_FIELD("day","uint8",15,1,SX_NONE),
    SX_FIELD("hour","uint8",16,1,SX_NONE),
    SX_FIELD("minute","uint8",17,1,SX_NONE),
    SX_FIELD("second","uint8",18,1,SX_NONE),
    SX_FIELD("production_status","uint8",19,1,SX_ID),
    SX_FIELD("data_type","uint8",20,1,SX_ID),
};
static const sx_layout sxsw_grib2_identification = {UINT32_C(0x602d002d),"grib2_identification",sxsw_grib2_identification_fields,SX_COUNT(sxsw_grib2_identification_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_grib2_grid_fields[] = {
    SX_FIELD("section_size","uint32",0,4,SX_SIZE),
    SX_FIELD("section_number","uint8",4,1,SX_ID),
    SX_FIELD("source","uint8",5,1,SX_ID),
    SX_FIELD("point_count","uint32",6,4,SX_COUNT_PROP),
    SX_FIELD("list_entry_size","uint8",10,1,SX_SIZE),
    SX_FIELD("list_interpretation","uint8",11,1,SX_ID),
    SX_FIELD("template_number","uint16",12,2,SX_ID),
};
static const sx_layout sxsw_grib2_grid = {UINT32_C(0x602d002e),"grib2_grid",sxsw_grib2_grid_fields,SX_COUNT(sxsw_grib2_grid_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_grib2_product_fields[] = {
    SX_FIELD("section_size","uint32",0,4,SX_SIZE),
    SX_FIELD("section_number","uint8",4,1,SX_ID),
    SX_FIELD("coordinate_count","uint16",5,2,SX_COUNT_PROP),
    SX_FIELD("template_number","uint16",7,2,SX_ID),
};
static const sx_layout sxsw_grib2_product = {UINT32_C(0x602d002f),"grib2_product",sxsw_grib2_product_fields,SX_COUNT(sxsw_grib2_product_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_grib2_representation_fields[] = {
    SX_FIELD("section_size","uint32",0,4,SX_SIZE),
    SX_FIELD("section_number","uint8",4,1,SX_ID),
    SX_FIELD("value_count","uint32",5,4,SX_COUNT_PROP),
    SX_FIELD("template_number","uint16",9,2,SX_ID),
};
static const sx_layout sxsw_grib2_representation = {UINT32_C(0x602d0030),"grib2_representation",sxsw_grib2_representation_fields,SX_COUNT(sxsw_grib2_representation_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_grib2_bitmap_fields[] = {
    SX_FIELD("section_size","uint32",0,4,SX_SIZE),
    SX_FIELD("section_number","uint8",4,1,SX_ID),
    SX_FIELD("bitmap_indicator","uint8",5,1,SX_ID),
};
static const sx_layout sxsw_grib2_bitmap = {UINT32_C(0x602d0031),"grib2_bitmap",sxsw_grib2_bitmap_fields,SX_COUNT(sxsw_grib2_bitmap_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_wmo_end_fields[] = {
    SX_FIELD("marker","char[4]",0,4,SX_SIGNATURE),
};
static const sx_layout sxsw_wmo_end = {UINT32_C(0x602d0032),"wmo_end",sxsw_wmo_end_fields,SX_COUNT(sxsw_wmo_end_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_bufr4_indicator_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("total_size","uint24",4,3,SX_SIZE),
    SX_FIELD("edition","uint8",7,1,SX_ID),
};
static const sx_layout sxsw_bufr4_indicator = {UINT32_C(0x602d0033),"bufr4_indicator",sxsw_bufr4_indicator_fields,SX_COUNT(sxsw_bufr4_indicator_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_bufr4_identification_fields[] = {
    SX_FIELD("section_size","uint24",0,3,SX_SIZE),
    SX_FIELD("master_table","uint8",3,1,SX_ID),
    SX_FIELD("centre","uint16",4,2,SX_ID),
    SX_FIELD("subcentre","uint16",6,2,SX_ID),
    SX_FIELD("update_sequence","uint8",8,1,SX_ID),
    SX_FIELD("optional_section","uint8",9,1,SX_FLAGS),
    SX_FIELD("data_category","uint8",10,1,SX_ID),
    SX_FIELD("international_subcategory","uint8",11,1,SX_ID),
    SX_FIELD("local_subcategory","uint8",12,1,SX_ID),
    SX_FIELD("master_table_version","uint8",13,1,SX_ID),
    SX_FIELD("local_table_version","uint8",14,1,SX_ID),
    SX_FIELD("year","uint16",15,2,SX_NONE),
    SX_FIELD("month","uint8",17,1,SX_NONE),
    SX_FIELD("day","uint8",18,1,SX_NONE),
    SX_FIELD("hour","uint8",19,1,SX_NONE),
    SX_FIELD("minute","uint8",20,1,SX_NONE),
    SX_FIELD("second","uint8",21,1,SX_NONE),
};
static const sx_layout sxsw_bufr4_identification = {UINT32_C(0x602d0034),"bufr4_identification",sxsw_bufr4_identification_fields,SX_COUNT(sxsw_bufr4_identification_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_bufr4_section_fields[] = {
    SX_FIELD("section_size","uint24",0,3,SX_SIZE),
    SX_FIELD("reserved","uint8",3,1,SX_RESERVED),
};
static const sx_layout sxsw_bufr4_section = {UINT32_C(0x602d0035),"bufr4_section",sxsw_bufr4_section_fields,SX_COUNT(sxsw_bufr4_section_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_bufr4_data_description_fields[] = {
    SX_FIELD("section_size","uint24",0,3,SX_SIZE),
    SX_FIELD("reserved","uint8",3,1,SX_RESERVED),
    SX_FIELD("subset_count","uint16",4,2,SX_COUNT_PROP),
    SX_FIELD("flags","uint8",6,1,SX_FLAGS),
};
static const sx_layout sxsw_bufr4_data_description = {UINT32_C(0x602d0036),"bufr4_data_description",sxsw_bufr4_data_description_fields,SX_COUNT(sxsw_bufr4_data_description_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_bufr_descriptor_fields[] = {
    SX_FIELD("descriptor","uint16",0,2,SX_ID),
};
static const sx_layout sxsw_bufr_descriptor = {UINT32_C(0x602d0037),"bufr_descriptor",sxsw_bufr_descriptor_fields,SX_COUNT(sxsw_bufr_descriptor_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_openephys_record_fields[] = {
    SX_FIELD("timestamp","int64",0,8,SX_NONE),
    SX_FIELD("sample_count","uint16",8,2,SX_COUNT_PROP),
    SX_FIELD("recording_number","uint16be",10,2,SX_ID),
};
static const sx_layout sxsw_openephys_record = {UINT32_C(0x602d0038),"openephys_record",sxsw_openephys_record_fields,SX_COUNT(sxsw_openephys_record_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_openephys_marker_fields[] = {
    SX_FIELD("marker","uint8[10]",0,10,SX_SIGNATURE),
};
static const sx_layout sxsw_openephys_marker = {UINT32_C(0x602d0039),"openephys_marker",sxsw_openephys_marker_fields,SX_COUNT(sxsw_openephys_marker_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_cnt_setup_fields[] = {
    SX_FIELD("revision","char[12]",0,12,SX_STRING),
    SX_FIELD("next_file","int32",12,4,SX_POINTER),
    SX_FIELD("opaque_10","uint8[5]",16,5,SX_NONE),
    SX_FIELD("patient_id","char[20]",21,20,SX_STRING),
    SX_FIELD("opaque_29","uint8[80]",41,80,SX_NONE),
    SX_FIELD("patient_name","char[20]",121,20,SX_STRING),
    SX_FIELD("opaque_8d","uint8[2]",141,2,SX_NONE),
    SX_FIELD("sex","char[1]",143,1,SX_ID),
    SX_FIELD("handedness","char[1]",144,1,SX_ID),
    SX_FIELD("opaque_91","uint8[60]",145,60,SX_NONE),
    SX_FIELD("session_label","char[20]",205,20,SX_STRING),
    SX_FIELD("date","char[10]",225,10,SX_STRING),
    SX_FIELD("time","char[12]",235,12,SX_STRING),
    SX_FIELD("opaque_f7","uint8[123]",247,123,SX_NONE),
    SX_FIELD("channel_count","uint16",370,2,SX_COUNT_PROP),
    SX_FIELD("opaque_174","uint8[4]",372,4,SX_NONE),
    SX_FIELD("sample_rate","uint16",376,2,SX_NONE),
    SX_FIELD("opaque_17a","uint8[24]",378,24,SX_NONE),
    SX_FIELD("eog_channel1","int16",402,2,SX_ID),
    SX_FIELD("eog_channel2","int16",404,2,SX_ID),
    SX_FIELD("opaque_196","uint8[32]",406,32,SX_NONE),
    SX_FIELD("lowpass_enabled","uint8",438,1,SX_FLAGS),
    SX_FIELD("highpass_enabled","uint8",439,1,SX_FLAGS),
    SX_FIELD("opaque_1b8","uint8[424]",440,424,SX_NONE),
    SX_FIELD("sample_count","uint32",864,4,SX_COUNT_PROP),
    SX_FIELD("opaque_364","uint8[1]",868,1,SX_NONE),
    SX_FIELD("low_cutoff","float32",869,4,SX_NONE),
    SX_FIELD("opaque_369","uint8[2]",873,2,SX_NONE),
    SX_FIELD("high_cutoff","float32",875,4,SX_NONE),
    SX_FIELD("opaque_36f","uint8[7]",879,7,SX_NONE),
    SX_FIELD("event_table_offset","uint32",886,4,SX_OFFSET),
    SX_FIELD("continuous_seconds","float32",890,4,SX_NONE),
    SX_FIELD("channel_block_size","int32",894,4,SX_SIZE),
    SX_FIELD("opaque_382","uint8[2]",898,2,SX_NONE),
};
static const sx_layout sxsw_cnt_setup = {UINT32_C(0x602d003a),"cnt_setup",sxsw_cnt_setup_fields,SX_COUNT(sxsw_cnt_setup_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_cnt_channel_fields[] = {
    SX_FIELD("label","char[10]",0,10,SX_STRING),
    SX_FIELD("opaque_a","uint8[4]",10,4,SX_NONE),
    SX_FIELD("bad_channel","uint8",14,1,SX_FLAGS),
    SX_FIELD("opaque_f","uint8[4]",15,4,SX_NONE),
    SX_FIELD("x_coordinate","float32",19,4,SX_NONE),
    SX_FIELD("y_coordinate","float32",23,4,SX_NONE),
    SX_FIELD("opaque_1b","uint8[20]",27,20,SX_NONE),
    SX_FIELD("baseline","int16",47,2,SX_NONE),
    SX_FIELD("opaque_31","uint8[10]",49,10,SX_NONE),
    SX_FIELD("sensitivity","float32",59,4,SX_NONE),
    SX_FIELD("opaque_3f","uint8[8]",63,8,SX_NONE),
    SX_FIELD("calibration","float32",71,4,SX_NONE),
};
static const sx_layout sxsw_cnt_channel = {UINT32_C(0x602d003b),"cnt_channel",sxsw_cnt_channel_fields,SX_COUNT(sxsw_cnt_channel_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_cnt_event_table_fields[] = {
    SX_FIELD("event_type","uint8",0,1,SX_ID),
    SX_FIELD("event_bytes","int32",1,4,SX_SIZE),
    SX_FIELD("offset","int32",5,4,SX_NONE),
};
static const sx_layout sxsw_cnt_event_table = {UINT32_C(0x602d003c),"cnt_event_table",sxsw_cnt_event_table_fields,SX_COUNT(sxsw_cnt_event_table_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_cnt_event1_fields[] = {
    SX_FIELD("stimulus_type","uint16",0,2,SX_ID),
    SX_FIELD("keyboard","uint8",2,1,SX_ID),
    SX_FIELD("keypad_accept","uint8",3,1,SX_FLAGS),
    SX_FIELD("offset","int32",4,4,SX_OFFSET),
};
static const sx_layout sxsw_cnt_event1 = {UINT32_C(0x602d003d),"cnt_event1",sxsw_cnt_event1_fields,SX_COUNT(sxsw_cnt_event1_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_cnt_event2_fields[] = {
    SX_FIELD("stimulus_type","uint16",0,2,SX_ID),
    SX_FIELD("keyboard","uint8",2,1,SX_ID),
    SX_FIELD("keypad_accept","uint8",3,1,SX_FLAGS),
    SX_FIELD("offset","int32",4,4,SX_OFFSET),
    SX_FIELD("type","int16",8,2,SX_ID),
    SX_FIELD("code","int16",10,2,SX_ID),
    SX_FIELD("latency","float32",12,4,SX_NONE),
    SX_FIELD("epoch","uint8",16,1,SX_ID),
    SX_FIELD("accept2","uint8",17,1,SX_FLAGS),
    SX_FIELD("accuracy","uint8",18,1,SX_NONE),
};
static const sx_layout sxsw_cnt_event2 = {UINT32_C(0x602d003e),"cnt_event2",sxsw_cnt_event2_fields,SX_COUNT(sxsw_cnt_event2_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_cnt_event3_fields[] = {
    SX_FIELD("stimulus_type","uint16",0,2,SX_ID),
    SX_FIELD("keyboard","uint8",2,1,SX_ID),
    SX_FIELD("keypad_accept","uint8",3,1,SX_FLAGS),
    SX_FIELD("global_sample_frame","uint32",4,4,SX_NONE),
    SX_FIELD("type","int16",8,2,SX_ID),
    SX_FIELD("code","int16",10,2,SX_ID),
    SX_FIELD("latency","float32",12,4,SX_NONE),
    SX_FIELD("epoch","uint8",16,1,SX_ID),
    SX_FIELD("accept2","uint8",17,1,SX_FLAGS),
    SX_FIELD("accuracy","uint8",18,1,SX_NONE),
};
static const sx_layout sxsw_cnt_event3 = {UINT32_C(0x602d003f),"cnt_event3",sxsw_cnt_event3_fields,SX_COUNT(sxsw_cnt_event3_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_stata117_prefix_le_fields[] = {
    SX_FIELD("prefix","char[28]",0,28,SX_SIGNATURE),
    SX_FIELD("release","char[3]",28,3,SX_ID),
    SX_FIELD("release_end","char[21]",31,21,SX_NONE),
    SX_FIELD("byte_order","char[3]",52,3,SX_ID),
    SX_FIELD("byte_order_end","char[15]",55,15,SX_NONE),
    SX_FIELD("variable_count","uint16",70,2,SX_COUNT_PROP),
    SX_FIELD("variable_count_end","char[7]",72,7,SX_NONE),
    SX_FIELD("observation_count","uint32",79,4,SX_COUNT_PROP),
};
static const sx_layout sxsw_stata117_prefix_le = {UINT32_C(0x602d0040),"stata117_prefix_le",sxsw_stata117_prefix_le_fields,SX_COUNT(sxsw_stata117_prefix_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_stata117_label_size_le_fields[] = {
    SX_FIELD("label_size","uint8",0,1,SX_SIZE),
};
static const sx_layout sxsw_stata117_label_size_le = {UINT32_C(0x602d0041),"stata117_label_size_le",sxsw_stata117_label_size_le_fields,SX_COUNT(sxsw_stata117_label_size_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_stata117_variable_name_fields[] = {
    SX_FIELD("variable_name","char[33]",0,33,SX_STRING),
};
static const sx_layout sxsw_stata117_variable_name = {UINT32_C(0x602d0042),"stata117_variable_name",sxsw_stata117_variable_name_fields,SX_COUNT(sxsw_stata117_variable_name_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_stata117_display_format_fields[] = {
    SX_FIELD("display_format","char[49]",0,49,SX_STRING),
};
static const sx_layout sxsw_stata117_display_format = {UINT32_C(0x602d0043),"stata117_display_format",sxsw_stata117_display_format_fields,SX_COUNT(sxsw_stata117_display_format_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_stata117_value_label_name_fields[] = {
    SX_FIELD("value_label_name","char[33]",0,33,SX_STRING),
};
static const sx_layout sxsw_stata117_value_label_name = {UINT32_C(0x602d0044),"stata117_value_label_name",sxsw_stata117_value_label_name_fields,SX_COUNT(sxsw_stata117_value_label_name_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_stata117_variable_label_fields[] = {
    SX_FIELD("variable_label","char[81]",0,81,SX_STRING),
};
static const sx_layout sxsw_stata117_variable_label = {UINT32_C(0x602d0045),"stata117_variable_label",sxsw_stata117_variable_label_fields,SX_COUNT(sxsw_stata117_variable_label_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_stata118_prefix_le_fields[] = {
    SX_FIELD("prefix","char[28]",0,28,SX_SIGNATURE),
    SX_FIELD("release","char[3]",28,3,SX_ID),
    SX_FIELD("release_end","char[21]",31,21,SX_NONE),
    SX_FIELD("byte_order","char[3]",52,3,SX_ID),
    SX_FIELD("byte_order_end","char[15]",55,15,SX_NONE),
    SX_FIELD("variable_count","uint16",70,2,SX_COUNT_PROP),
    SX_FIELD("variable_count_end","char[7]",72,7,SX_NONE),
    SX_FIELD("observation_count","uint64",79,8,SX_COUNT_PROP),
};
static const sx_layout sxsw_stata118_prefix_le = {UINT32_C(0x602d0046),"stata118_prefix_le",sxsw_stata118_prefix_le_fields,SX_COUNT(sxsw_stata118_prefix_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_stata118_label_size_le_fields[] = {
    SX_FIELD("label_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxsw_stata118_label_size_le = {UINT32_C(0x602d0047),"stata118_label_size_le",sxsw_stata118_label_size_le_fields,SX_COUNT(sxsw_stata118_label_size_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_stata118_variable_name_fields[] = {
    SX_FIELD("variable_name","char[129]",0,129,SX_STRING),
};
static const sx_layout sxsw_stata118_variable_name = {UINT32_C(0x602d0048),"stata118_variable_name",sxsw_stata118_variable_name_fields,SX_COUNT(sxsw_stata118_variable_name_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_stata118_display_format_fields[] = {
    SX_FIELD("display_format","char[57]",0,57,SX_STRING),
};
static const sx_layout sxsw_stata118_display_format = {UINT32_C(0x602d0049),"stata118_display_format",sxsw_stata118_display_format_fields,SX_COUNT(sxsw_stata118_display_format_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_stata118_value_label_name_fields[] = {
    SX_FIELD("value_label_name","char[129]",0,129,SX_STRING),
};
static const sx_layout sxsw_stata118_value_label_name = {UINT32_C(0x602d004a),"stata118_value_label_name",sxsw_stata118_value_label_name_fields,SX_COUNT(sxsw_stata118_value_label_name_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_stata118_variable_label_fields[] = {
    SX_FIELD("variable_label","char[321]",0,321,SX_STRING),
};
static const sx_layout sxsw_stata118_variable_label = {UINT32_C(0x602d004b),"stata118_variable_label",sxsw_stata118_variable_label_fields,SX_COUNT(sxsw_stata118_variable_label_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_stata_map_le_fields[] = {
    SX_FIELD("start","char[5]",0,5,SX_NONE),
    SX_FIELD("file_start","uint64",5,8,SX_OFFSET),
    SX_FIELD("map_offset","uint64",13,8,SX_OFFSET),
    SX_FIELD("variable_types_offset","uint64",21,8,SX_OFFSET),
    SX_FIELD("variable_names_offset","uint64",29,8,SX_OFFSET),
    SX_FIELD("sortlist_offset","uint64",37,8,SX_OFFSET),
    SX_FIELD("formats_offset","uint64",45,8,SX_OFFSET),
    SX_FIELD("value_label_names_offset","uint64",53,8,SX_OFFSET),
    SX_FIELD("variable_labels_offset","uint64",61,8,SX_OFFSET),
    SX_FIELD("characteristics_offset","uint64",69,8,SX_OFFSET),
    SX_FIELD("data_offset","uint64",77,8,SX_OFFSET),
    SX_FIELD("strls_offset","uint64",85,8,SX_OFFSET),
    SX_FIELD("value_labels_offset","uint64",93,8,SX_OFFSET),
    SX_FIELD("file_end_tag_offset","uint64",101,8,SX_OFFSET),
    SX_FIELD("file_end","uint64",109,8,SX_OFFSET),
    SX_FIELD("end","char[6]",117,6,SX_NONE),
};
static const sx_layout sxsw_stata_map_le = {UINT32_C(0x602d004c),"stata_map_le",sxsw_stata_map_le_fields,SX_COUNT(sxsw_stata_map_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_stata_type_le_fields[] = {
    SX_FIELD("type","uint16",0,2,SX_ID),
};
static const sx_layout sxsw_stata_type_le = {UINT32_C(0x602d004d),"stata_type_le",sxsw_stata_type_le_fields,SX_COUNT(sxsw_stata_type_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_stata_sort_index_le_fields[] = {
    SX_FIELD("variable_index","uint16",0,2,SX_ID),
};
static const sx_layout sxsw_stata_sort_index_le = {UINT32_C(0x602d004e),"stata_sort_index_le",sxsw_stata_sort_index_le_fields,SX_COUNT(sxsw_stata_sort_index_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_stata117_prefix_be_fields[] = {
    SX_FIELD("prefix","char[28]",0,28,SX_SIGNATURE),
    SX_FIELD("release","char[3]",28,3,SX_ID),
    SX_FIELD("release_end","char[21]",31,21,SX_NONE),
    SX_FIELD("byte_order","char[3]",52,3,SX_ID),
    SX_FIELD("byte_order_end","char[15]",55,15,SX_NONE),
    SX_FIELD("variable_count","uint16",70,2,SX_COUNT_PROP),
    SX_FIELD("variable_count_end","char[7]",72,7,SX_NONE),
    SX_FIELD("observation_count","uint32",79,4,SX_COUNT_PROP),
};
static const sx_layout sxsw_stata117_prefix_be = {UINT32_C(0x602d004f),"stata117_prefix_be",sxsw_stata117_prefix_be_fields,SX_COUNT(sxsw_stata117_prefix_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_stata117_label_size_be_fields[] = {
    SX_FIELD("label_size","uint8",0,1,SX_SIZE),
};
static const sx_layout sxsw_stata117_label_size_be = {UINT32_C(0x602d0050),"stata117_label_size_be",sxsw_stata117_label_size_be_fields,SX_COUNT(sxsw_stata117_label_size_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_stata118_prefix_be_fields[] = {
    SX_FIELD("prefix","char[28]",0,28,SX_SIGNATURE),
    SX_FIELD("release","char[3]",28,3,SX_ID),
    SX_FIELD("release_end","char[21]",31,21,SX_NONE),
    SX_FIELD("byte_order","char[3]",52,3,SX_ID),
    SX_FIELD("byte_order_end","char[15]",55,15,SX_NONE),
    SX_FIELD("variable_count","uint16",70,2,SX_COUNT_PROP),
    SX_FIELD("variable_count_end","char[7]",72,7,SX_NONE),
    SX_FIELD("observation_count","uint64",79,8,SX_COUNT_PROP),
};
static const sx_layout sxsw_stata118_prefix_be = {UINT32_C(0x602d0051),"stata118_prefix_be",sxsw_stata118_prefix_be_fields,SX_COUNT(sxsw_stata118_prefix_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_stata118_label_size_be_fields[] = {
    SX_FIELD("label_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxsw_stata118_label_size_be = {UINT32_C(0x602d0052),"stata118_label_size_be",sxsw_stata118_label_size_be_fields,SX_COUNT(sxsw_stata118_label_size_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_stata_map_be_fields[] = {
    SX_FIELD("start","char[5]",0,5,SX_NONE),
    SX_FIELD("file_start","uint64",5,8,SX_OFFSET),
    SX_FIELD("map_offset","uint64",13,8,SX_OFFSET),
    SX_FIELD("variable_types_offset","uint64",21,8,SX_OFFSET),
    SX_FIELD("variable_names_offset","uint64",29,8,SX_OFFSET),
    SX_FIELD("sortlist_offset","uint64",37,8,SX_OFFSET),
    SX_FIELD("formats_offset","uint64",45,8,SX_OFFSET),
    SX_FIELD("value_label_names_offset","uint64",53,8,SX_OFFSET),
    SX_FIELD("variable_labels_offset","uint64",61,8,SX_OFFSET),
    SX_FIELD("characteristics_offset","uint64",69,8,SX_OFFSET),
    SX_FIELD("data_offset","uint64",77,8,SX_OFFSET),
    SX_FIELD("strls_offset","uint64",85,8,SX_OFFSET),
    SX_FIELD("value_labels_offset","uint64",93,8,SX_OFFSET),
    SX_FIELD("file_end_tag_offset","uint64",101,8,SX_OFFSET),
    SX_FIELD("file_end","uint64",109,8,SX_OFFSET),
    SX_FIELD("end","char[6]",117,6,SX_NONE),
};
static const sx_layout sxsw_stata_map_be = {UINT32_C(0x602d0053),"stata_map_be",sxsw_stata_map_be_fields,SX_COUNT(sxsw_stata_map_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_stata_type_be_fields[] = {
    SX_FIELD("type","uint16",0,2,SX_ID),
};
static const sx_layout sxsw_stata_type_be = {UINT32_C(0x602d0054),"stata_type_be",sxsw_stata_type_be_fields,SX_COUNT(sxsw_stata_type_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_stata_sort_index_be_fields[] = {
    SX_FIELD("variable_index","uint16",0,2,SX_ID),
};
static const sx_layout sxsw_stata_sort_index_be = {UINT32_C(0x602d0055),"stata_sort_index_be",sxsw_stata_sort_index_be_fields,SX_COUNT(sxsw_stata_sort_index_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_stata_timestamp_size_fields[] = {
    SX_FIELD("timestamp_size","uint8",0,1,SX_SIZE),
};
static const sx_layout sxsw_stata_timestamp_size = {UINT32_C(0x602d0056),"stata_timestamp_size",sxsw_stata_timestamp_size_fields,SX_COUNT(sxsw_stata_timestamp_size_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_rosbag_signature_fields[] = {
    SX_FIELD("signature","char[13]",0,13,SX_SIGNATURE),
};
static const sx_layout sxsw_rosbag_signature = {UINT32_C(0x602d0057),"rosbag_signature",sxsw_rosbag_signature_fields,SX_COUNT(sxsw_rosbag_signature_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_rosbag_header_size_fields[] = {
    SX_FIELD("header_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxsw_rosbag_header_size = {UINT32_C(0x602d0058),"rosbag_header_size",sxsw_rosbag_header_size_fields,SX_COUNT(sxsw_rosbag_header_size_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_rosbag_field_size_fields[] = {
    SX_FIELD("field_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxsw_rosbag_field_size = {UINT32_C(0x602d0059),"rosbag_field_size",sxsw_rosbag_field_size_fields,SX_COUNT(sxsw_rosbag_field_size_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_rosbag_data_size_fields[] = {
    SX_FIELD("data_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxsw_rosbag_data_size = {UINT32_C(0x602d005a),"rosbag_data_size",sxsw_rosbag_data_size_fields,SX_COUNT(sxsw_rosbag_data_size_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_rosbag_op_fields[] = {
    SX_FIELD("operation","uint8",0,1,SX_ID),
};
static const sx_layout sxsw_rosbag_op = {UINT32_C(0x602d005b),"rosbag_op",sxsw_rosbag_op_fields,SX_COUNT(sxsw_rosbag_op_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_rosbag_conn_fields[] = {
    SX_FIELD("connection_id","uint32",0,4,SX_ID),
};
static const sx_layout sxsw_rosbag_conn = {UINT32_C(0x602d005c),"rosbag_conn",sxsw_rosbag_conn_fields,SX_COUNT(sxsw_rosbag_conn_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_rosbag_size_fields[] = {
    SX_FIELD("uncompressed_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxsw_rosbag_size = {UINT32_C(0x602d005d),"rosbag_size",sxsw_rosbag_size_fields,SX_COUNT(sxsw_rosbag_size_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_rosbag_count_fields[] = {
    SX_FIELD("count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxsw_rosbag_count = {UINT32_C(0x602d005e),"rosbag_count",sxsw_rosbag_count_fields,SX_COUNT(sxsw_rosbag_count_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_rosbag_ver_fields[] = {
    SX_FIELD("version","uint32",0,4,SX_ID),
};
static const sx_layout sxsw_rosbag_ver = {UINT32_C(0x602d005f),"rosbag_ver",sxsw_rosbag_ver_fields,SX_COUNT(sxsw_rosbag_ver_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_rosbag_index_pos_fields[] = {
    SX_FIELD("index_offset","uint64",0,8,SX_OFFSET),
};
static const sx_layout sxsw_rosbag_index_pos = {UINT32_C(0x602d0060),"rosbag_index_pos",sxsw_rosbag_index_pos_fields,SX_COUNT(sxsw_rosbag_index_pos_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_rosbag_chunk_pos_fields[] = {
    SX_FIELD("chunk_offset","uint64",0,8,SX_OFFSET),
};
static const sx_layout sxsw_rosbag_chunk_pos = {UINT32_C(0x602d0061),"rosbag_chunk_pos",sxsw_rosbag_chunk_pos_fields,SX_COUNT(sxsw_rosbag_chunk_pos_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_rosbag_conn_count_fields[] = {
    SX_FIELD("connection_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxsw_rosbag_conn_count = {UINT32_C(0x602d0062),"rosbag_conn_count",sxsw_rosbag_conn_count_fields,SX_COUNT(sxsw_rosbag_conn_count_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_rosbag_chunk_count_fields[] = {
    SX_FIELD("chunk_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxsw_rosbag_chunk_count = {UINT32_C(0x602d0063),"rosbag_chunk_count",sxsw_rosbag_chunk_count_fields,SX_COUNT(sxsw_rosbag_chunk_count_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_rosbag_time_fields[] = {
    SX_FIELD("seconds","uint32",0,4,SX_TIME),
    SX_FIELD("nanoseconds","uint32",4,4,SX_NONE),
};
static const sx_layout sxsw_rosbag_time = {UINT32_C(0x602d0064),"rosbag_time",sxsw_rosbag_time_fields,SX_COUNT(sxsw_rosbag_time_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_rosbag_index_fields[] = {
    SX_FIELD("seconds","uint32",0,4,SX_TIME),
    SX_FIELD("nanoseconds","uint32",4,4,SX_NONE),
    SX_FIELD("record_offset","uint32",8,4,SX_OFFSET),
};
static const sx_layout sxsw_rosbag_index = {UINT32_C(0x602d0065),"rosbag_index",sxsw_rosbag_index_fields,SX_COUNT(sxsw_rosbag_index_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_rosbag_connection_count_fields[] = {
    SX_FIELD("connection_id","uint32",0,4,SX_ID),
    SX_FIELD("message_count","uint32",4,4,SX_COUNT_PROP),
};
static const sx_layout sxsw_rosbag_connection_count = {UINT32_C(0x602d0066),"rosbag_connection_count",sxsw_rosbag_connection_count_fields,SX_COUNT(sxsw_rosbag_connection_count_fields),SX_LE};
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
static const xx_data_struct_field_desc sxsw_tecplot_prefix_le_fields[] = {
    SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("byte_order","int32",8,4,SX_ID),
    SX_FIELD("file_type","int32",12,4,SX_ID),
};
static const sx_layout sxsw_tecplot_prefix_le = {UINT32_C(0x602d0070),"tecplot_prefix_le",sxsw_tecplot_prefix_le_fields,SX_COUNT(sxsw_tecplot_prefix_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_tecplot_codepoint_le_fields[] = {
    SX_FIELD("character","int32",0,4,SX_NONE),
};
static const sx_layout sxsw_tecplot_codepoint_le = {UINT32_C(0x602d0071),"tecplot_codepoint_le",sxsw_tecplot_codepoint_le_fields,SX_COUNT(sxsw_tecplot_codepoint_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_tecplot_variable_count_le_fields[] = {
    SX_FIELD("variable_count","int32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxsw_tecplot_variable_count_le = {UINT32_C(0x602d0072),"tecplot_variable_count_le",sxsw_tecplot_variable_count_le_fields,SX_COUNT(sxsw_tecplot_variable_count_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_tecplot_marker_le_fields[] = {
    SX_FIELD("marker","float32",0,4,SX_NONE),
};
static const sx_layout sxsw_tecplot_marker_le = {UINT32_C(0x602d0073),"tecplot_marker_le",sxsw_tecplot_marker_le_fields,SX_COUNT(sxsw_tecplot_marker_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_tecplot_ordered_zone_le_fields[] = {
    SX_FIELD("parent_zone","int32",0,4,SX_ID),
    SX_FIELD("strand_id","int32",4,4,SX_ID),
    SX_FIELD("solution_time","float64",8,8,SX_NONE),
    SX_FIELD("zone_color","int32",16,4,SX_ID),
    SX_FIELD("zone_type","int32",20,4,SX_ID),
    SX_FIELD("specify_variable_location","int32",24,4,SX_FLAGS),
    SX_FIELD("raw_local_face_neighbors","int32",28,4,SX_FLAGS),
    SX_FIELD("miscellaneous_face_neighbor_count","int32",32,4,SX_COUNT_PROP),
    SX_FIELD("dimension_i","int32",36,4,SX_COUNT_PROP),
    SX_FIELD("dimension_j","int32",40,4,SX_COUNT_PROP),
    SX_FIELD("dimension_k","int32",44,4,SX_COUNT_PROP),
};
static const sx_layout sxsw_tecplot_ordered_zone_le = {UINT32_C(0x602d0074),"tecplot_ordered_zone_le",sxsw_tecplot_ordered_zone_le_fields,SX_COUNT(sxsw_tecplot_ordered_zone_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_tecplot_auxiliary_flag_le_fields[] = {
    SX_FIELD("auxiliary_data","int32",0,4,SX_FLAGS),
};
static const sx_layout sxsw_tecplot_auxiliary_flag_le = {UINT32_C(0x602d0075),"tecplot_auxiliary_flag_le",sxsw_tecplot_auxiliary_flag_le_fields,SX_COUNT(sxsw_tecplot_auxiliary_flag_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_tecplot_variable_type_le_fields[] = {
    SX_FIELD("type","int32",0,4,SX_ID),
};
static const sx_layout sxsw_tecplot_variable_type_le = {UINT32_C(0x602d0076),"tecplot_variable_type_le",sxsw_tecplot_variable_type_le_fields,SX_COUNT(sxsw_tecplot_variable_type_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_tecplot_data_flags_le_fields[] = {
    SX_FIELD("passive_variables","int32",0,4,SX_FLAGS),
    SX_FIELD("variable_sharing","int32",4,4,SX_FLAGS),
    SX_FIELD("connectivity_sharing","int32",8,4,SX_ID),
};
static const sx_layout sxsw_tecplot_data_flags_le = {UINT32_C(0x602d0077),"tecplot_data_flags_le",sxsw_tecplot_data_flags_le_fields,SX_COUNT(sxsw_tecplot_data_flags_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_tecplot_range_le_fields[] = {
    SX_FIELD("minimum","float64",0,8,SX_NONE),
    SX_FIELD("maximum","float64",8,8,SX_NONE),
};
static const sx_layout sxsw_tecplot_range_le = {UINT32_C(0x602d0078),"tecplot_range_le",sxsw_tecplot_range_le_fields,SX_COUNT(sxsw_tecplot_range_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_tecplot_prefix_be_fields[] = {
    SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("byte_order","int32",8,4,SX_ID),
    SX_FIELD("file_type","int32",12,4,SX_ID),
};
static const sx_layout sxsw_tecplot_prefix_be = {UINT32_C(0x602d0079),"tecplot_prefix_be",sxsw_tecplot_prefix_be_fields,SX_COUNT(sxsw_tecplot_prefix_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_tecplot_codepoint_be_fields[] = {
    SX_FIELD("character","int32",0,4,SX_NONE),
};
static const sx_layout sxsw_tecplot_codepoint_be = {UINT32_C(0x602d007a),"tecplot_codepoint_be",sxsw_tecplot_codepoint_be_fields,SX_COUNT(sxsw_tecplot_codepoint_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_tecplot_variable_count_be_fields[] = {
    SX_FIELD("variable_count","int32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxsw_tecplot_variable_count_be = {UINT32_C(0x602d007b),"tecplot_variable_count_be",sxsw_tecplot_variable_count_be_fields,SX_COUNT(sxsw_tecplot_variable_count_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_tecplot_marker_be_fields[] = {
    SX_FIELD("marker","float32",0,4,SX_NONE),
};
static const sx_layout sxsw_tecplot_marker_be = {UINT32_C(0x602d007c),"tecplot_marker_be",sxsw_tecplot_marker_be_fields,SX_COUNT(sxsw_tecplot_marker_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_tecplot_ordered_zone_be_fields[] = {
    SX_FIELD("parent_zone","int32",0,4,SX_ID),
    SX_FIELD("strand_id","int32",4,4,SX_ID),
    SX_FIELD("solution_time","float64",8,8,SX_NONE),
    SX_FIELD("zone_color","int32",16,4,SX_ID),
    SX_FIELD("zone_type","int32",20,4,SX_ID),
    SX_FIELD("specify_variable_location","int32",24,4,SX_FLAGS),
    SX_FIELD("raw_local_face_neighbors","int32",28,4,SX_FLAGS),
    SX_FIELD("miscellaneous_face_neighbor_count","int32",32,4,SX_COUNT_PROP),
    SX_FIELD("dimension_i","int32",36,4,SX_COUNT_PROP),
    SX_FIELD("dimension_j","int32",40,4,SX_COUNT_PROP),
    SX_FIELD("dimension_k","int32",44,4,SX_COUNT_PROP),
};
static const sx_layout sxsw_tecplot_ordered_zone_be = {UINT32_C(0x602d007d),"tecplot_ordered_zone_be",sxsw_tecplot_ordered_zone_be_fields,SX_COUNT(sxsw_tecplot_ordered_zone_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_tecplot_auxiliary_flag_be_fields[] = {
    SX_FIELD("auxiliary_data","int32",0,4,SX_FLAGS),
};
static const sx_layout sxsw_tecplot_auxiliary_flag_be = {UINT32_C(0x602d007e),"tecplot_auxiliary_flag_be",sxsw_tecplot_auxiliary_flag_be_fields,SX_COUNT(sxsw_tecplot_auxiliary_flag_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_tecplot_variable_type_be_fields[] = {
    SX_FIELD("type","int32",0,4,SX_ID),
};
static const sx_layout sxsw_tecplot_variable_type_be = {UINT32_C(0x602d007f),"tecplot_variable_type_be",sxsw_tecplot_variable_type_be_fields,SX_COUNT(sxsw_tecplot_variable_type_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_tecplot_data_flags_be_fields[] = {
    SX_FIELD("passive_variables","int32",0,4,SX_FLAGS),
    SX_FIELD("variable_sharing","int32",4,4,SX_FLAGS),
    SX_FIELD("connectivity_sharing","int32",8,4,SX_ID),
};
static const sx_layout sxsw_tecplot_data_flags_be = {UINT32_C(0x602d0080),"tecplot_data_flags_be",sxsw_tecplot_data_flags_be_fields,SX_COUNT(sxsw_tecplot_data_flags_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_tecplot_range_be_fields[] = {
    SX_FIELD("minimum","float64",0,8,SX_NONE),
    SX_FIELD("maximum","float64",8,8,SX_NONE),
};
static const sx_layout sxsw_tecplot_range_be = {UINT32_C(0x602d0081),"tecplot_range_be",sxsw_tecplot_range_be_fields,SX_COUNT(sxsw_tecplot_range_be_fields),SX_BE};
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

static uint16_t sxsw16(const uint8_t *p,bool be){return xx_data_get_u16(p,2,0,be);}
static uint32_t sxsw32(const uint8_t *p,bool be){return xx_data_get_u32(p,4,0,be);}
static bool sxsw_span(sx_context *c,int64_t at,uint64_t n){return c&&!xx_pd_is_stopped(c->pd)&&at>=0&&at<=c->size&&n<=(uint64_t)(c->size-at);}
static bool sxsw_add(sx_context *c,const sx_layout *l,int64_t at,int64_t bytes){return sxsw_span(c,at,(uint64_t)bytes)&&(c->count>=32000||sx_add(c,l,at,bytes));}
static bool sxsw_table(sx_context *c,const sx_layout *l,int64_t at,int64_t bytes,uint64_t count){return bytes>0&&count<=INT64_MAX/(uint64_t)bytes&&sxsw_span(c,at,(uint64_t)bytes*count)&&(c->count>=32000||sx_table(c,l,at,bytes,count));}
static int sxsw_order(const void *a,const void *b){const xx_data_struct *x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:x->total_size<y->total_size?-1:x->total_size>y->total_size?1:0;}
static bool sxsw_finish(sx_context *c)
{
 size_t n=c->count;if(!n)return false;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxsw_order);
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,bytes=c->items[i].total_size;if(at<end)return false;if(at>end&&!sx_raw(c,end,at-end))return false;end=at+bytes;}
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxsw_order);return !c->failed&&!xx_pd_is_stopped(c->pd);
}
static uint64_t sxsw64(const uint8_t *p,bool be){return xx_data_get_u64(p,8,0,be);}
static bool sxsw_text_integer(const uint8_t *p,size_t n,int64_t *out)
{
 bool negative=false,digit=false,space=false;uint64_t v=0;size_t i=0;
 while(i<n&&p[i]==' ')i++;if(i<n&&(p[i]=='-'||p[i]=='+'))negative=p[i++]=='-';
 for(;i<n;i++){if(p[i]==' '){space=true;continue;}if(space||p[i]<'0'||p[i]>'9'||v>(INT64_MAX-(p[i]-'0'))/10)return false;digit=true;v=v*10+p[i]-'0';}
 *out=negative?-(int64_t)v:(int64_t)v;return digit;
}
static bool sxsw_fits(sx_context *c)
{
 int64_t at=0;
 for(unsigned hdu=0;at<c->size&&hdu<1024;hdu++){
  uint8_t b[80];int64_t begin=at,bitpix=0,rank=-1;uint64_t pixels=1;bool end=false;
  if(!sx_read(c,at,b,80))return false;if(hdu&&xx_rt_memcmp(b,"XTENSION",8))return true;
  for(unsigned card=0;card<4096;card++){
   if(!sx_read(c,at,b,80))return false;bool integer=!xx_rt_memcmp(b,"BITPIX  ",8)||!xx_rt_memcmp(b,"NAXIS",5)||!xx_rt_memcmp(b,"PCOUNT  ",8)||!xx_rt_memcmp(b,"GCOUNT  ",8);
   if(!sxsw_add(c,integer?&sxsw_fits_integer_card:&sxsw_fits_card,at,80))return false;at+=80;
   if(!xx_rt_memcmp(b,"END     ",8)){end=true;break;}
   if(integer){int64_t n;if(!sxsw_text_integer(b+10,20,&n))return false;
    if(!xx_rt_memcmp(b,"BITPIX  ",8))bitpix=n;else if(!xx_rt_memcmp(b,"NAXIS   ",8))rank=n;
    else if(!xx_rt_memcmp(b,"NAXIS",5)){if(n<0||(n&&pixels>UINT64_MAX/(uint64_t)n))return false;pixels*=(uint64_t)n;}
   }
  }
  if(!end||rank<0||rank>16||!bitpix||bitpix==INT64_MIN)return false;
  uint64_t width=(uint64_t)(bitpix<0?-bitpix:bitpix)/8;if(!width||pixels>INT64_MAX/width)return false;
  uint64_t header=((uint64_t)(at-begin)+2879)/2880*2880,bytes=rank?pixels*width:0;
  bytes=(bytes+2879)/2880*2880;if(!sxsw_span(c,begin,header+bytes))return false;at=begin+(int64_t)(header+bytes);
 }return at==c->size;
}
static bool sxsw_xport(sx_context *c)
{
 uint8_t b[80];int64_t count,at;
 if(!sx_read(c,560,b,80)||!sxsw_text_integer(b+54,4,&count)||count<1||count>4096)return false;
 const int64_t headers[]={0,240,320,560};for(unsigned i=0;i<SX_COUNT(headers);i++)if(!sxsw_add(c,&sxsw_xport_header_record,headers[i],80))return false;
 at=((640+count*140+79)/80)*80;
 return sxsw_table(c,&sxsw_xport_namestr,640,140,(uint64_t)count)&&sxsw_add(c,&sxsw_xport_header_record,at,80);
}
static bool sxsw_sav(sx_context *c)
{
 uint8_t b[176];if(!sx_read(c,0,b,176))return false;bool be=sxsw32(b+64,true)==2;int64_t at=176;
 if(!sxsw_add(c,be?&sxsw_sav_header_be:&sxsw_sav_header_le,0,176))return false;
 while(at<c->size){
  uint32_t tag,n;if(!sx_u32(c,at,be,&tag))return false;
  if(tag==2){if(!sx_read(c,at,b,32)||!sxsw_add(c,be?&sxsw_sav_variable_be:&sxsw_sav_variable_le,at,32))return false;uint32_t label=sxsw32(b+8,be);int32_t missing=(int32_t)sxsw32(b+12,be);at+=32;
   if(label){if(!sx_u32(c,at,be,&n)||n>16777216||!sxsw_add(c,be?&sxsw_sav_label_size_be:&sxsw_sav_label_size_le,at,4)||!sxsw_span(c,at+4,((uint64_t)n+3)&~UINT64_C(3)))return false;at+=4+((n+3U)&~3U);}
   if(missing<-3||missing>3||!sxsw_span(c,at,(unsigned)(missing<0?-missing:missing)*8))return false;at+=(missing<0?-missing:missing)*8;
  }else if(tag==3||tag==4||tag==6){
   if(!sx_u32(c,at+4,be,&n)||n>4096||!sxsw_add(c,be?&sxsw_sav_count_record_be:&sxsw_sav_count_record_le,at,8))return false;at+=8;
   if(tag==3){for(uint32_t j=0;j<n;j++){if(!sx_read(c,at,b,9)||!sxsw_add(c,be?&sxsw_sav_value_label_be:&sxsw_sav_value_label_le,at,9))return false;uint32_t bytes=8+((1U+b[8]+7)&~7U);if(!sxsw_span(c,at,bytes))return false;at+=bytes;}}
   else {uint32_t width=tag==4?4:80;const sx_layout *l=tag==4?(be?&sxsw_sav_variable_index_be:&sxsw_sav_variable_index_le):&sxsw_sav_document_line;if(!sxsw_table(c,l,at,width,n))return false;at+=(int64_t)n*width;}
  }else if(tag==7){
   if(!sx_read(c,at,b,16)||!sxsw_add(c,be?&sxsw_sav_extension_be:&sxsw_sav_extension_le,at,16))return false;uint32_t subtype=sxsw32(b+4,be),width=sxsw32(b+8,be);n=sxsw32(b+12,be);uint64_t bytes=(uint64_t)width*n;at+=16;if(!sxsw_span(c,at,bytes))return false;
   if(subtype==3&&width==4&&n==8&&!sxsw_add(c,be?&sxsw_sav_machine_integer_be:&sxsw_sav_machine_integer_le,at,32))return false;at+=(int64_t)bytes;
  }else if(tag==999)return sxsw_add(c,be?&sxsw_sav_dictionary_end_be:&sxsw_sav_dictionary_end_le,at,8);
  else return false;
 }return false;
}
static bool sxsw_bgen_string(sx_context *c,int64_t *at,bool wide)
{
 uint32_t n;if(wide){if(!sx_u32(c,*at,false,&n))return false;}else{uint16_t x;if(!sx_u16(c,*at,false,&x))return false;n=x;}
 unsigned width=wide?4:2;if(!sxsw_add(c,wide?&sxsw_bgen_string32:&sxsw_bgen_string16,*at,width)||!sxsw_span(c,*at+width,n))return false;*at+=width+n;return true;
}
static bool sxsw_bgen(sx_context *c)
{
 uint8_t b[20];if(!sx_read(c,0,b,20))return false;uint32_t offset=sxsw32(b,false),header=sxsw32(b+4,false),variants=sxsw32(b+8,false),samples=sxsw32(b+12,false),flags;int64_t at=(int64_t)header+4;
 if(!sxsw_add(c,&sxsw_bgen_header,0,20)||!sx_u32(c,header,false,&flags)||!sxsw_add(c,&sxsw_bgen_flags,header,4))return false;
 if(flags&0x80000000U){uint32_t count;if(!sx_u32(c,at+4,false,&count)||count!=samples||!sxsw_add(c,&sxsw_bgen_sample_header,at,8))return false;at+=8;for(uint32_t i=0;i<count;i++)if(!sxsw_bgen_string(c,&at,false))return false;}
 at=(int64_t)offset+4;if(variants>1024||samples>1000000)return false;
 for(uint32_t i=0;i<variants;i++){if(!sxsw_add(c,&sxsw_bgen_variant_sample_count,at,4))return false;at+=4;for(unsigned j=0;j<3;j++)if(!sxsw_bgen_string(c,&at,false))return false;
  if(!sxsw_add(c,&sxsw_bgen_variant_position,at,4))return false;at+=4;
  for(unsigned j=0;j<2;j++)if(!sxsw_bgen_string(c,&at,true))return false;
  if(!sxsw_span(c,at,(uint64_t)samples*6))return false;at+=(int64_t)samples*6;
 }return at==c->size;
}
static bool sxsw_igor(sx_context *c)
{
 uint16_t version;if(!sx_u16(c,0,false,&version))return false;bool be=version!=5;
 return sxsw_add(c,be?&sxsw_igor_binary5_be:&sxsw_igor_binary5_le,0,64)&&sxsw_add(c,be?&sxsw_igor_wave5_be:&sxsw_igor_wave5_le,64,320);
}
static bool sxsw_spider(sx_context *c)
{
 uint32_t form;if(!sx_u32(c,16,false,&form))return false;bool be=form!=0x3f800000U&&form!=0x40400000U;
 return sxsw_add(c,be?&sxsw_spider_header_be:&sxsw_spider_header_le,0,1024);
}
static bool sxsw_lecroy(sx_context *c)
{
 uint8_t b[346];if(!sx_read(c,0,b,346))return false;bool be=sxsw16(b+34,false)==0;uint32_t desc=sxsw32(b+36,be),user=sxsw32(b+40,be),trigger=sxsw32(b+48,be),ris=sxsw32(b+52,be);int64_t at=(int64_t)desc+user;
 return sxsw_add(c,be?&sxsw_lecroy_descriptor_be:&sxsw_lecroy_descriptor_le,0,346)&&sxsw_table(c,be?&sxsw_lecroy_trigger_time_be:&sxsw_lecroy_trigger_time_le,at,16,trigger/16)&&sxsw_table(c,be?&sxsw_lecroy_ris_time_be:&sxsw_lecroy_ris_time_le,at+trigger,8,ris/8);
}
static bool sxsw_grib(sx_context *c)
{
 int64_t at=0;for(unsigned msg=0;at<c->size&&msg<400;msg++){
  uint64_t size;if(!sx_u64(c,at+8,true,&size)||size<20||!sxsw_span(c,at,size)||!sxsw_add(c,&sxsw_grib2_indicator,at,16))return false;int64_t end=at+(int64_t)size-4;at+=16;
  while(at<end){uint8_t b[5];if(!sx_read(c,at,b,5))return false;uint32_t n=sxsw32(b,true);unsigned id=b[4];const sx_layout *l=&sxsw_grib2_section;unsigned width=5;
   if(id==1){l=&sxsw_grib2_identification;width=21;}else if(id==3){l=&sxsw_grib2_grid;width=14;}else if(id==4){l=&sxsw_grib2_product;width=9;}else if(id==5){l=&sxsw_grib2_representation;width=11;}else if(id==6){l=&sxsw_grib2_bitmap;width=6;}
   if(n<width||n>(uint64_t)(end-at)||!sxsw_add(c,l,at,width))return false;at+=n;
  }if(at!=end||!sxsw_add(c,&sxsw_wmo_end,at,4))return false;at+=4;
 }return at==c->size;
}
static uint32_t sxsw24(const uint8_t *b){return ((uint32_t)b[0]<<16)|((uint32_t)b[1]<<8)|b[2];}
static bool sxsw_bufr(sx_context *c)
{
 int64_t at=0;for(unsigned msg=0;at<c->size&&msg<600;msg++){
  uint8_t b[22];if(!sx_read(c,at,b,8))return false;uint32_t size=sxsw24(b+4);if(size<12||!sxsw_span(c,at,size)||!sxsw_add(c,&sxsw_bufr4_indicator,at,8))return false;int64_t end=at+size-4;at+=8;
  if(!sx_read(c,at,b,22))return false;uint32_t n=sxsw24(b);bool optional=(b[9]&128)!=0;if(n<22||n>(uint64_t)(end-at)||!sxsw_add(c,&sxsw_bufr4_identification,at,22))return false;at+=n;
  if(optional){if(!sx_read(c,at,b,4))return false;n=sxsw24(b);if(n<4||n>(uint64_t)(end-at)||!sxsw_add(c,&sxsw_bufr4_section,at,4))return false;at+=n;}
  if(!sx_read(c,at,b,7))return false;n=sxsw24(b);if(n<7||(n-7)%2||n>(uint64_t)(end-at)||!sxsw_add(c,&sxsw_bufr4_data_description,at,7)||!sxsw_table(c,&sxsw_bufr_descriptor,at+7,2,(n-7)/2))return false;at+=n;
  if(!sx_read(c,at,b,4))return false;n=sxsw24(b);if(n<4||n>(uint64_t)(end-at)||!sxsw_add(c,&sxsw_bufr4_section,at,4))return false;at+=n;
  if(at!=end||!sxsw_add(c,&sxsw_wmo_end,at,4))return false;at+=4;
 }return at==c->size;
}
static bool sxsw_openephys(sx_context *c)
{
 int64_t at=1024;for(unsigned i=0;at<c->size&&i<4095;i++,at+=2070)if(!sxsw_span(c,at,2070)||!sxsw_add(c,&sxsw_openephys_record,at,12)||!sxsw_add(c,&sxsw_openephys_marker,at+2060,10))return false;return at==c->size;
}
static bool sxsw_cnt(sx_context *c)
{
 uint8_t b[900];if(!sx_read(c,0,b,900))return false;uint32_t channels=sxsw16(b+370,false),events=sxsw32(b+886,false);
 if(!sxsw_add(c,&sxsw_cnt_setup,0,900)||!sxsw_table(c,&sxsw_cnt_channel,900,75,channels)||!sx_read(c,events,b,9)||!sxsw_add(c,&sxsw_cnt_event_table,events,9))return false;
 unsigned event_type=b[0];uint32_t bytes=sxsw32(b+1,false),width=event_type==1?8:19;
 return bytes%width==0&&sxsw_table(c,event_type==1?&sxsw_cnt_event1:event_type==3?&sxsw_cnt_event3:&sxsw_cnt_event2,(int64_t)events+9,width,bytes/width);
}
static bool sxsw_literal(sx_context *c,int64_t *at,const char *s)
{
 size_t n=xx_rt_strlen(s);uint8_t b[128];if(n>sizeof(b)||!sx_read(c,*at,b,n)||xx_rt_memcmp(b,s,n))return false;*at+=(int64_t)n;return true;
}
static bool sxsw_stata(sx_context *c)
{
 uint8_t b[128];if(!sx_read(c,0,b,79))return false;bool v118=b[30]=='8',be=!xx_rt_memcmp(b+50,"MSF",3);unsigned width=v118?8:4;
 /* Prefix locations are fixed by the mandatory release/byte-order tags. */
 int64_t at=0;if(!sxsw_literal(c,&at,"<stata_dta><header><release>"))return false;at+=3;if(!sxsw_literal(c,&at,"</release><byteorder>"))return false;
 if(!sx_read(c,at,b,3))return false;be=!xx_rt_memcmp(b,"MSF",3);at+=3;
 if(!sxsw_literal(c,&at,"</byteorder><K>"))return false;uint16_t vars;if(!sx_u16(c,at,be,&vars)||!vars||vars>4096)return false;at+=2;
 if(!sxsw_literal(c,&at,"</K><N>"))return false;at+=width;
 const sx_layout *prefix=v118?(be?&sxsw_stata118_prefix_be:&sxsw_stata118_prefix_le):(be?&sxsw_stata117_prefix_be:&sxsw_stata117_prefix_le);
 if(!sxsw_add(c,prefix,0,at)||!sxsw_literal(c,&at,"</N><label>"))return false;
 unsigned n;if(v118){uint16_t x;if(!sx_u16(c,at,be,&x))return false;n=x;}else{if(!sx_read(c,at,b,1))return false;n=b[0];}
 if(!sxsw_add(c,v118?(be?&sxsw_stata118_label_size_be:&sxsw_stata118_label_size_le):(be?&sxsw_stata117_label_size_be:&sxsw_stata117_label_size_le),at,v118?2:1)||!sxsw_span(c,at+(v118?2:1),n))return false;at+=(v118?2:1)+n;
 if(!sxsw_literal(c,&at,"</label><timestamp>")||!sx_read(c,at,b,1)||!sxsw_add(c,&sxsw_stata_timestamp_size,at,1)||!sxsw_span(c,at+1,b[0]))return false;at+=1+b[0];
 if(!sxsw_literal(c,&at,"</timestamp></header>")||!sx_read(c,at,b,123)||!sxsw_add(c,be?&sxsw_stata_map_be:&sxsw_stata_map_le,at,123))return false;
 uint64_t offsets[14];for(unsigned i=0;i<14;i++){offsets[i]=sxsw64(b+5+i*8,be);if(offsets[i]>(uint64_t)c->size)return false;}
 const char *tags[]={"<variable_types>","<varnames>","<sortlist>","<formats>","<value_label_names>","<variable_labels>"};
 const sx_layout *layouts[]={be?&sxsw_stata_type_be:&sxsw_stata_type_le,v118?&sxsw_stata118_variable_name:&sxsw_stata117_variable_name,be?&sxsw_stata_sort_index_be:&sxsw_stata_sort_index_le,v118?&sxsw_stata118_display_format:&sxsw_stata117_display_format,v118?&sxsw_stata118_value_label_name:&sxsw_stata117_value_label_name,v118?&sxsw_stata118_variable_label:&sxsw_stata117_variable_label};
 const unsigned widths[]={2,v118?129:33,2,v118?57:49,v118?129:33,v118?321:81};
 for(unsigned i=0;i<6;i++){at=(int64_t)offsets[i+2];if(!sxsw_literal(c,&at,tags[i])||!sxsw_table(c,layouts[i],at,widths[i],vars+(i==2)))return false;}return true;
}
static bool sxsw_rb_fields(sx_context *c,int64_t at,int64_t end,unsigned *op,uint32_t *count)
{
 for(unsigned i=0;at<end;i++){
  uint32_t n;uint8_t b[64];if(i>=16||at>end-4||!sx_u32(c,at,false,&n)||n>(uint64_t)(end-at-4)||!sxsw_add(c,&sxsw_rosbag_field_size,at,4))return false;at+=4;
  unsigned key=0;for(;key<n&&key<64;key++){if(!sx_read(c,at+key,b+key,1))return false;if(b[key]=='=')break;}
  if(!key||key>=n||key>63)return false;b[key]=0;int64_t value=at+key+1;uint32_t size=n-key-1;const sx_layout *l=NULL;unsigned expected=4;
  if(!xx_rt_strcmp((const char*)b,"op")){l=&sxsw_rosbag_op;expected=1;uint8_t v;if(size==1&&sx_read(c,value,&v,1))*op=v;}
  else if(!xx_rt_strcmp((const char*)b,"conn"))l=&sxsw_rosbag_conn;
  else if(!xx_rt_strcmp((const char*)b,"size"))l=&sxsw_rosbag_size;
  else if(!xx_rt_strcmp((const char*)b,"count")){l=&sxsw_rosbag_count;if(size==4&&!sx_u32(c,value,false,count))return false;}
  else if(!xx_rt_strcmp((const char*)b,"ver"))l=&sxsw_rosbag_ver;
  else if(!xx_rt_strcmp((const char*)b,"conn_count"))l=&sxsw_rosbag_conn_count;
  else if(!xx_rt_strcmp((const char*)b,"chunk_count"))l=&sxsw_rosbag_chunk_count;
  else if(!xx_rt_strcmp((const char*)b,"index_pos")){l=&sxsw_rosbag_index_pos;expected=8;}
  else if(!xx_rt_strcmp((const char*)b,"chunk_pos")){l=&sxsw_rosbag_chunk_pos;expected=8;}
  else if(!xx_rt_strcmp((const char*)b,"time")||!xx_rt_strcmp((const char*)b,"start_time")||!xx_rt_strcmp((const char*)b,"end_time")){l=&sxsw_rosbag_time;expected=8;}
  if(l&&size==expected&&!sxsw_add(c,l,value,expected))return false;at+=n;
 }return at==end;
}
static bool sxsw_rb_records(sx_context *c,int64_t at,int64_t end,unsigned depth)
{
 if(depth>2)return false;
 for(unsigned i=0;at<end;i++){
  uint32_t n,bytes,count=0;unsigned op=0;
  if(i>=8192||at>end-4||!sxsw_span(c,at,4)||!sx_u32(c,at,false,&n)||n>65536||n>(uint64_t)(end-at-4)||!sxsw_add(c,&sxsw_rosbag_header_size,at,4))return false;at+=4;
  if(!sxsw_rb_fields(c,at,at+n,&op,&count))return false;at+=n;
  if(at>end-4||!sx_u32(c,at,false,&bytes)||bytes>(uint64_t)(end-at-4)||!sxsw_add(c,&sxsw_rosbag_data_size,at,4))return false;at+=4;
  if(op==5){if(!sxsw_rb_records(c,at,at+bytes,depth+1))return false;}
  else if(op==7){unsigned unused_op=0;uint32_t unused_count=0;if(!sxsw_rb_fields(c,at,at+bytes,&unused_op,&unused_count))return false;}
  else if(op==4){if(count>4090||(uint64_t)count*12!=bytes||!sxsw_table(c,&sxsw_rosbag_index,at,12,count))return false;}
  else if(op==6){if(count>128||(uint64_t)count*8!=bytes||!sxsw_table(c,&sxsw_rosbag_connection_count,at,8,count))return false;}
  at+=bytes;
 }return at==end;
}
static bool sxsw_rosbag(sx_context *c){return sxsw_add(c,&sxsw_rosbag_signature,0,13)&&sxsw_rb_records(c,13,c->size,0);}
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
static bool sxsw_tec_string(sx_context *c,int64_t *at,bool be)
{
 uint32_t n;int64_t begin=*at;for(unsigned i=0;i<4096;i++){if(!sx_u32(c,*at,be,&n)||n>127)return false;*at+=4;if(!n)return sxsw_table(c,be?&sxsw_tecplot_codepoint_be:&sxsw_tecplot_codepoint_le,begin,4,i+1);}return false;
}
static bool sxsw_tecplot(sx_context *c)
{
 uint32_t x,vars;uint64_t points[32];unsigned zones=0;int64_t at=16;
 if(!sx_u32(c,8,false,&x))return false;bool be=x!=1;
 if(!sxsw_add(c,be?&sxsw_tecplot_prefix_be:&sxsw_tecplot_prefix_le,0,16)||!sxsw_tec_string(c,&at,be)||!sx_u32(c,at,be,&vars)||!vars||vars>64||!sxsw_add(c,be?&sxsw_tecplot_variable_count_be:&sxsw_tecplot_variable_count_le,at,4))return false;at+=4;
 for(uint32_t i=0;i<vars;i++)if(!sxsw_tec_string(c,&at,be))return false;
 while(true){if(!sx_u32(c,at,be,&x)||!sxsw_add(c,be?&sxsw_tecplot_marker_be:&sxsw_tecplot_marker_le,at,4))return false;at+=4;if(x==0x43b28000U)break;
  uint8_t b[48];if(x!=0x43958000U||zones>=32||!sxsw_tec_string(c,&at,be)||!sx_read(c,at,b,48)||!sxsw_add(c,be?&sxsw_tecplot_ordered_zone_be:&sxsw_tecplot_ordered_zone_le,at,48))return false;
  uint64_t count=1;for(unsigned i=0;i<3;i++){uint32_t dim=sxsw32(b+36+i*4,be);if(!dim||count>1048576/dim)return false;count*=dim;}points[zones++]=count;at+=48;
  if(!sxsw_add(c,be?&sxsw_tecplot_auxiliary_flag_be:&sxsw_tecplot_auxiliary_flag_le,at,4))return false;at+=4;
 }
 for(unsigned z=0;z<zones;z++){
  uint32_t types[64];if(!sxsw_add(c,be?&sxsw_tecplot_marker_be:&sxsw_tecplot_marker_le,at,4)||!sxsw_table(c,be?&sxsw_tecplot_variable_type_be:&sxsw_tecplot_variable_type_le,at+4,4,vars))return false;at+=4;
  for(uint32_t i=0;i<vars;i++){if(!sx_u32(c,at,be,&types[i])||types[i]<1||types[i]>5)return false;at+=4;}
  if(!sxsw_add(c,be?&sxsw_tecplot_data_flags_be:&sxsw_tecplot_data_flags_le,at,12)||!sxsw_table(c,be?&sxsw_tecplot_range_be:&sxsw_tecplot_range_le,at+12,16,vars))return false;at+=12+vars*16;
  for(uint32_t i=0;i<vars;i++){unsigned width=types[i]==2?8:types[i]<=3?4:types[i]==4?2:1;uint64_t bytes=points[z]*width;if(!sxsw_span(c,at,bytes))return false;at+=(int64_t)bytes;}
 }return at==c->size;
}

static bool sx_sciencewire_supports(xx_file_type_t t){switch(t){case XX_FILE_TYPE_FITS:case XX_FILE_TYPE_DICOM:case XX_FILE_TYPE_SAS_XPORT:case XX_FILE_TYPE_SPSS_SAV:case XX_FILE_TYPE_STATA_DTA:case XX_FILE_TYPE_ROSBAG1:case XX_FILE_TYPE_GENOMICS_BGEN:case XX_FILE_TYPE_IGOR_IBW:case XX_FILE_TYPE_MICROSCOPY_SPIDER:case XX_FILE_TYPE_WMO_GRIB:case XX_FILE_TYPE_WMO_BUFR:case XX_FILE_TYPE_LECROY_TRC:case XX_FILE_TYPE_NEUROSCAN_CNT:case XX_FILE_TYPE_TECPLOT_PLT:case XX_FILE_TYPE_OPENEPHYS_CONTINUOUS:return true;default:return false;}}
static bool sx_sciencewire_build(sx_context *c)
{
 if(!c||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;
 switch(c->f->file_type){case XX_FILE_TYPE_FITS:ok=sxsw_fits(c);break;case XX_FILE_TYPE_DICOM:ok=sxsw_dicom(c);break;case XX_FILE_TYPE_SAS_XPORT:ok=sxsw_xport(c);break;case XX_FILE_TYPE_SPSS_SAV:ok=sxsw_sav(c);break;case XX_FILE_TYPE_STATA_DTA:ok=sxsw_stata(c);break;case XX_FILE_TYPE_ROSBAG1:ok=sxsw_rosbag(c);break;case XX_FILE_TYPE_GENOMICS_BGEN:ok=sxsw_bgen(c);break;case XX_FILE_TYPE_IGOR_IBW:ok=sxsw_igor(c);break;case XX_FILE_TYPE_MICROSCOPY_SPIDER:ok=sxsw_spider(c);break;case XX_FILE_TYPE_WMO_GRIB:ok=sxsw_grib(c);break;case XX_FILE_TYPE_WMO_BUFR:ok=sxsw_bufr(c);break;case XX_FILE_TYPE_LECROY_TRC:ok=sxsw_lecroy(c);break;case XX_FILE_TYPE_NEUROSCAN_CNT:ok=sxsw_cnt(c);break;case XX_FILE_TYPE_TECPLOT_PLT:ok=sxsw_tecplot(c);break;case XX_FILE_TYPE_OPENEPHYS_CONTINUOUS:ok=sxsw_openephys(c);break;default:return false;}return ok&&sxsw_finish(c);
}
