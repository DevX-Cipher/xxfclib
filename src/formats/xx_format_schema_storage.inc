/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical storage and audiovisual schemas. Scope and wire references are
 * documented in docs/data_struct_storage_scope.txt. Encoded payloads remain raw.
 */

static const xx_data_struct_field_desc sx_st_midi_header_fields[] = {
    SX_FIELD("signature", "byte[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("header_length", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("format", "uint16", 8, 2, SX_ID),
    SX_FIELD("track_count", "uint16", 10, 2, SX_COUNT_PROP),
    SX_FIELD("division", "uint16", 12, 2, SX_NONE),
};
static const sx_layout sx_st_midi_header = {0x60080001U, "midi_header", sx_st_midi_header_fields, SX_COUNT(sx_st_midi_header_fields), SX_BE};

static const xx_data_struct_field_desc sx_st_midi_track_fields[] = {
    SX_FIELD("signature", "byte[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("length", "uint32", 4, 4, SX_SIZE),
};
static const sx_layout sx_st_midi_track = {0x60080002U, "midi_track", sx_st_midi_track_fields, SX_COUNT(sx_st_midi_track_fields), SX_BE};

static const xx_data_struct_field_desc sx_st_caf_header_fields[] = {
    SX_FIELD("signature", "byte[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("version", "uint16", 4, 2, SX_NONE),
    SX_FIELD("flags", "uint16", 6, 2, SX_FLAGS),
};
static const sx_layout sx_st_caf_header = {0x60080003U, "caf_header", sx_st_caf_header_fields, SX_COUNT(sx_st_caf_header_fields), SX_BE};

static const xx_data_struct_field_desc sx_st_caf_chunk_fields[] = {
    SX_FIELD("type", "char[4]", 0, 4, SX_STRING),
    SX_FIELD("size", "int64", 4, 8, SX_NONE),
};
static const sx_layout sx_st_caf_chunk = {0x60080004U, "caf_chunk", sx_st_caf_chunk_fields, SX_COUNT(sx_st_caf_chunk_fields), SX_BE};

static const xx_data_struct_field_desc sx_st_caf_description_fields[] = {
    SX_FIELD("sample_rate", "float64", 0, 8, SX_NONE),
    SX_FIELD("format_id", "char[4]", 8, 4, SX_STRING),
    SX_FIELD("format_flags", "uint32", 12, 4, SX_FLAGS),
    SX_FIELD("bytes_per_packet", "uint32", 16, 4, SX_SIZE),
    SX_FIELD("frames_per_packet", "uint32", 20, 4, SX_COUNT_PROP),
    SX_FIELD("channels_per_frame", "uint32", 24, 4, SX_COUNT_PROP),
    SX_FIELD("bits_per_channel", "uint32", 28, 4, SX_COUNT_PROP),
};
static const sx_layout sx_st_caf_description = {0x60080005U, "caf_description", sx_st_caf_description_fields, SX_COUNT(sx_st_caf_description_fields), SX_BE};

static const xx_data_struct_field_desc sx_st_caf_data_fields[] = {
    SX_FIELD("edit_count", "uint32", 0, 4, SX_COUNT_PROP),
};
static const sx_layout sx_st_caf_data = {0x60080006U, "caf_data", sx_st_caf_data_fields, SX_COUNT(sx_st_caf_data_fields), SX_BE};

static const xx_data_struct_field_desc sx_st_caf_packet_table_fields[] = {
    SX_FIELD("packet_count", "int64", 0, 8, SX_COUNT_PROP),
    SX_FIELD("valid_frame_count", "int64", 8, 8, SX_COUNT_PROP),
    SX_FIELD("priming_frame_count", "int32", 16, 4, SX_COUNT_PROP),
    SX_FIELD("remainder_frame_count", "int32", 20, 4, SX_COUNT_PROP),
};
static const sx_layout sx_st_caf_packet_table = {0x60080007U, "caf_packet_table", sx_st_caf_packet_table_fields, SX_COUNT(sx_st_caf_packet_table_fields), SX_BE};

static const xx_data_struct_field_desc sx_st_voc_header_fields[] = {
    SX_FIELD("signature", "byte[20]", 0, 20, SX_SIGNATURE),
    SX_FIELD("data_offset", "uint16", 20, 2, SX_OFFSET),
    SX_FIELD("version", "uint16", 22, 2, SX_NONE),
    SX_FIELD("version_checksum", "uint16", 24, 2, SX_CHECKSUM),
};
static const sx_layout sx_st_voc_header = {0x60080008U, "voc_header", sx_st_voc_header_fields, SX_COUNT(sx_st_voc_header_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_voc_block_fields[] = {
    SX_FIELD("type", "uint8", 0, 1, SX_ID),
    SX_FIELD("payload_size", "uint24", 1, 3, SX_SIZE),
};
static const sx_layout sx_st_voc_block = {0x60080009U, "voc_block", sx_st_voc_block_fields, SX_COUNT(sx_st_voc_block_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_voc_terminator_fields[] = {
    SX_FIELD("type", "uint8", 0, 1, SX_ID),
};
static const sx_layout sx_st_voc_terminator = {0x6008000AU, "voc_terminator", sx_st_voc_terminator_fields, SX_COUNT(sx_st_voc_terminator_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_voc_sound_fields[] = {
    SX_FIELD("time_constant", "uint8", 0, 1, SX_NONE),
    SX_FIELD("codec", "uint8", 1, 1, SX_ID),
};
static const sx_layout sx_st_voc_sound = {0x6008000BU, "voc_sound", sx_st_voc_sound_fields, SX_COUNT(sx_st_voc_sound_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_voc_silence_fields[] = {
    SX_FIELD("sample_count_minus_one", "uint16", 0, 2, SX_NONE),
    SX_FIELD("time_constant", "uint8", 2, 1, SX_NONE),
};
static const sx_layout sx_st_voc_silence = {0x6008000CU, "voc_silence", sx_st_voc_silence_fields, SX_COUNT(sx_st_voc_silence_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_voc_marker_fields[] = {
    SX_FIELD("marker", "uint16", 0, 2, SX_ID),
};
static const sx_layout sx_st_voc_marker = {0x6008000DU, "voc_marker", sx_st_voc_marker_fields, SX_COUNT(sx_st_voc_marker_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_voc_repeat_fields[] = {
    SX_FIELD("repeat_count", "uint16", 0, 2, SX_COUNT_PROP),
};
static const sx_layout sx_st_voc_repeat = {0x6008000EU, "voc_repeat", sx_st_voc_repeat_fields, SX_COUNT(sx_st_voc_repeat_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_voc_sound_v2_fields[] = {
    SX_FIELD("sample_rate", "uint32", 0, 4, SX_NONE),
    SX_FIELD("bits_per_sample", "uint8", 4, 1, SX_NONE),
    SX_FIELD("channels", "uint8", 5, 1, SX_COUNT_PROP),
    SX_FIELD("codec", "uint16", 6, 2, SX_ID),
    SX_FIELD("reserved", "byte[4]", 8, 4, SX_RESERVED),
};
static const sx_layout sx_st_voc_sound_v2 = {0x6008000FU, "voc_sound_v2", sx_st_voc_sound_v2_fields, SX_COUNT(sx_st_voc_sound_v2_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_vag_header_fields[] = {
    SX_FIELD("signature", "byte[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("version", "uint32", 4, 4, SX_NONE),
    SX_FIELD("reserved", "uint32", 8, 4, SX_RESERVED),
    SX_FIELD("data_size", "uint32", 12, 4, SX_SIZE),
    SX_FIELD("sample_rate", "uint32", 16, 4, SX_NONE),
    SX_FIELD("reserved2", "byte[12]", 20, 12, SX_RESERVED),
    SX_FIELD("name", "char[16]", 32, 16, SX_STRING),
};
static const sx_layout sx_st_vag_header = {0x60080010U, "vag_header", sx_st_vag_header_fields, SX_COUNT(sx_st_vag_header_fields), SX_BE};

static const xx_data_struct_field_desc sx_st_vag_adpcm_frame_fields[] = {
    SX_FIELD("predictor_and_shift", "uint8", 0, 1, SX_NONE),
    SX_FIELD("flags", "uint8", 1, 1, SX_FLAGS),
    SX_FIELD("encoded_samples", "byte[14]", 2, 14, SX_NONE),
};
static const sx_layout sx_st_vag_adpcm_frame = {0x60080011U, "vag_adpcm_frame", sx_st_vag_adpcm_frame_fields, SX_COUNT(sx_st_vag_adpcm_frame_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_psf_header_fields[] = {
    SX_FIELD("signature", "byte[3]", 0, 3, SX_SIGNATURE),
    SX_FIELD("version", "uint8", 3, 1, SX_NONE),
    SX_FIELD("reserved_size", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("compressed_program_size", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("compressed_program_crc32", "uint32", 12, 4, SX_CHECKSUM),
};
static const sx_layout sx_st_psf_header = {0x60080012U, "psf_header", sx_st_psf_header_fields, SX_COUNT(sx_st_psf_header_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_dsf_header_fields[] = {
    SX_FIELD("chunk_id", "char[4]", 0, 4, SX_STRING),
    SX_FIELD("chunk_size", "uint64", 4, 8, SX_SIZE),
    SX_FIELD("file_size", "uint64", 12, 8, SX_SIZE),
    SX_FIELD("metadata_offset", "uint64", 20, 8, SX_OFFSET),
};
static const sx_layout sx_st_dsf_header = {0x60080013U, "dsf_header", sx_st_dsf_header_fields, SX_COUNT(sx_st_dsf_header_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_dsf_format_fields[] = {
    SX_FIELD("chunk_id", "char[4]", 0, 4, SX_STRING),
    SX_FIELD("chunk_size", "uint64", 4, 8, SX_SIZE),
    SX_FIELD("format_version", "uint32", 12, 4, SX_NONE),
    SX_FIELD("format_id", "uint32", 16, 4, SX_ID),
    SX_FIELD("channel_type", "uint32", 20, 4, SX_ID),
    SX_FIELD("channel_count", "uint32", 24, 4, SX_COUNT_PROP),
    SX_FIELD("sample_rate", "uint32", 28, 4, SX_NONE),
    SX_FIELD("bits_per_sample", "uint32", 32, 4, SX_NONE),
    SX_FIELD("sample_count", "uint64", 36, 8, SX_COUNT_PROP),
    SX_FIELD("block_size_per_channel", "uint32", 44, 4, SX_SIZE),
    SX_FIELD("reserved", "uint32", 48, 4, SX_RESERVED),
};
static const sx_layout sx_st_dsf_format = {0x60080014U, "dsf_format", sx_st_dsf_format_fields, SX_COUNT(sx_st_dsf_format_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_dsf_data_fields[] = {
    SX_FIELD("chunk_id", "char[4]", 0, 4, SX_STRING),
    SX_FIELD("chunk_size", "uint64", 4, 8, SX_SIZE),
};
static const sx_layout sx_st_dsf_data = {0x60080015U, "dsf_data", sx_st_dsf_data_fields, SX_COUNT(sx_st_dsf_data_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_dff_form_fields[] = {
    SX_FIELD("chunk_id", "char[4]", 0, 4, SX_STRING),
    SX_FIELD("chunk_size", "uint64", 4, 8, SX_SIZE),
    SX_FIELD("form_type", "char[4]", 12, 4, SX_STRING),
};
static const sx_layout sx_st_dff_form = {0x60080016U, "dff_form", sx_st_dff_form_fields, SX_COUNT(sx_st_dff_form_fields), SX_BE};

static const xx_data_struct_field_desc sx_st_dff_chunk_fields[] = {
    SX_FIELD("chunk_id", "char[4]", 0, 4, SX_STRING),
    SX_FIELD("chunk_size", "uint64", 4, 8, SX_SIZE),
};
static const sx_layout sx_st_dff_chunk = {0x60080017U, "dff_chunk", sx_st_dff_chunk_fields, SX_COUNT(sx_st_dff_chunk_fields), SX_BE};

static const xx_data_struct_field_desc sx_st_dff_version_fields[] = {
    SX_FIELD("version", "uint32", 0, 4, SX_NONE),
};
static const sx_layout sx_st_dff_version = {0x60080018U, "dff_version", sx_st_dff_version_fields, SX_COUNT(sx_st_dff_version_fields), SX_BE};

static const xx_data_struct_field_desc sx_st_dff_property_fields[] = {
    SX_FIELD("property_type", "char[4]", 0, 4, SX_STRING),
};
static const sx_layout sx_st_dff_property = {0x60080019U, "dff_property", sx_st_dff_property_fields, SX_COUNT(sx_st_dff_property_fields), SX_BE};

static const xx_data_struct_field_desc sx_st_dff_frequency_fields[] = {
    SX_FIELD("sample_rate", "uint32", 0, 4, SX_NONE),
};
static const sx_layout sx_st_dff_frequency = {0x6008001AU, "dff_frequency", sx_st_dff_frequency_fields, SX_COUNT(sx_st_dff_frequency_fields), SX_BE};

static const xx_data_struct_field_desc sx_st_dff_channels_fields[] = {
    SX_FIELD("channel_count", "uint16", 0, 2, SX_COUNT_PROP),
};
static const sx_layout sx_st_dff_channels = {0x6008001BU, "dff_channels", sx_st_dff_channels_fields, SX_COUNT(sx_st_dff_channels_fields), SX_BE};

static const xx_data_struct_field_desc sx_st_dff_channel_fields[] = {
    SX_FIELD("channel_id", "char[4]", 0, 4, SX_STRING),
};
static const sx_layout sx_st_dff_channel = {0x6008001CU, "dff_channel", sx_st_dff_channel_fields, SX_COUNT(sx_st_dff_channel_fields), SX_BE};

static const xx_data_struct_field_desc sx_st_dff_compression_fields[] = {
    SX_FIELD("compression_id", "char[4]", 0, 4, SX_STRING),
    SX_FIELD("name_length", "uint8", 4, 1, SX_SIZE),
};
static const sx_layout sx_st_dff_compression = {0x6008001DU, "dff_compression", sx_st_dff_compression_fields, SX_COUNT(sx_st_dff_compression_fields), SX_BE};

static const xx_data_struct_field_desc sx_st_wave64_header_fields[] = {
    SX_FIELD("riff_guid", "byte[16]", 0, 16, SX_ID),
    SX_FIELD("file_size", "uint64", 16, 8, SX_SIZE),
    SX_FIELD("wave_guid", "byte[16]", 24, 16, SX_ID),
};
static const sx_layout sx_st_wave64_header = {0x6008001EU, "wave64_header", sx_st_wave64_header_fields, SX_COUNT(sx_st_wave64_header_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_wave64_chunk_fields[] = {
    SX_FIELD("chunk_guid", "byte[16]", 0, 16, SX_ID),
    SX_FIELD("chunk_size", "uint64", 16, 8, SX_SIZE),
};
static const sx_layout sx_st_wave64_chunk = {0x6008001FU, "wave64_chunk", sx_st_wave64_chunk_fields, SX_COUNT(sx_st_wave64_chunk_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_wave64_format_fields[] = {
    SX_FIELD("format_tag", "uint16", 0, 2, SX_ID),
    SX_FIELD("channels", "uint16", 2, 2, SX_COUNT_PROP),
    SX_FIELD("sample_rate", "uint32", 4, 4, SX_NONE),
    SX_FIELD("average_bytes_per_second", "uint32", 8, 4, SX_NONE),
    SX_FIELD("block_alignment", "uint16", 12, 2, SX_SIZE),
    SX_FIELD("bits_per_sample", "uint16", 14, 2, SX_NONE),
};
static const sx_layout sx_st_wave64_format = {0x60080020U, "wave64_format", sx_st_wave64_format_fields, SX_COUNT(sx_st_wave64_format_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_wave64_format_extra_fields[] = {
    SX_FIELD("extra_size", "uint16", 0, 2, SX_SIZE),
};
static const sx_layout sx_st_wave64_format_extra = {0x60080021U, "wave64_format_extra", sx_st_wave64_format_extra_fields, SX_COUNT(sx_st_wave64_format_extra_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_adx_header_fields[] = {
    SX_FIELD("signature", "uint16", 0, 2, SX_SIGNATURE),
    SX_FIELD("data_offset_minus_four", "uint16", 2, 2, SX_OFFSET),
    SX_FIELD("encoding", "uint8", 4, 1, SX_ID),
    SX_FIELD("block_size", "uint8", 5, 1, SX_SIZE),
    SX_FIELD("sample_bits", "uint8", 6, 1, SX_NONE),
    SX_FIELD("channels", "uint8", 7, 1, SX_COUNT_PROP),
    SX_FIELD("sample_rate", "uint32", 8, 4, SX_NONE),
    SX_FIELD("sample_count", "uint32", 12, 4, SX_COUNT_PROP),
    SX_FIELD("highpass_frequency", "uint16", 16, 2, SX_NONE),
    SX_FIELD("version", "uint8", 18, 1, SX_NONE),
    SX_FIELD("flags", "uint8", 19, 1, SX_FLAGS),
};
static const sx_layout sx_st_adx_header = {0x60080022U, "adx_header", sx_st_adx_header_fields, SX_COUNT(sx_st_adx_header_fields), SX_BE};

static const xx_data_struct_field_desc sx_st_adx_terminator_fields[] = {
    SX_FIELD("signature", "uint16", 0, 2, SX_SIGNATURE),
    SX_FIELD("payload_size", "uint16", 2, 2, SX_SIZE),
    SX_FIELD("padding", "byte[14]", 4, 14, SX_RESERVED),
};
static const sx_layout sx_st_adx_terminator = {0x60080023U, "adx_terminator", sx_st_adx_terminator_fields, SX_COUNT(sx_st_adx_terminator_fields), SX_BE};

static const xx_data_struct_field_desc sx_st_wavpack_block_fields[] = {
    SX_FIELD("signature", "byte[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("size_minus_eight", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("version", "uint16", 8, 2, SX_NONE),
    SX_FIELD("track_number", "uint8", 10, 1, SX_NONE),
    SX_FIELD("index_number", "uint8", 11, 1, SX_NONE),
    SX_FIELD("total_samples", "uint32", 12, 4, SX_COUNT_PROP),
    SX_FIELD("block_index", "uint32", 16, 4, SX_NONE),
    SX_FIELD("block_samples", "uint32", 20, 4, SX_COUNT_PROP),
    SX_FIELD("flags", "uint32", 24, 4, SX_FLAGS),
    SX_FIELD("crc32", "uint32", 28, 4, SX_CHECKSUM),
};
static const sx_layout sx_st_wavpack_block = {0x60080024U, "wavpack_block", sx_st_wavpack_block_fields, SX_COUNT(sx_st_wavpack_block_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_wavpack_metadata_fields[] = {
    SX_FIELD("id_and_flags", "uint8", 0, 1, SX_FLAGS),
    SX_FIELD("word_count", "uint8", 1, 1, SX_COUNT_PROP),
};
static const sx_layout sx_st_wavpack_metadata = {0x60080025U, "wavpack_metadata", sx_st_wavpack_metadata_fields, SX_COUNT(sx_st_wavpack_metadata_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_wavpack_metadata_large_fields[] = {
    SX_FIELD("id_and_flags", "uint8", 0, 1, SX_FLAGS),
    SX_FIELD("word_count", "uint24", 1, 3, SX_COUNT_PROP),
};
static const sx_layout sx_st_wavpack_metadata_large = {0x60080026U, "wavpack_metadata_large", sx_st_wavpack_metadata_large_fields, SX_COUNT(sx_st_wavpack_metadata_large_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_apev2_tag_fields[] = {
    SX_FIELD("signature", "byte[8]", 0, 8, SX_SIGNATURE),
    SX_FIELD("version", "uint32", 8, 4, SX_NONE),
    SX_FIELD("tag_size", "uint32", 12, 4, SX_SIZE),
    SX_FIELD("item_count", "uint32", 16, 4, SX_COUNT_PROP),
    SX_FIELD("flags", "uint32", 20, 4, SX_FLAGS),
    SX_FIELD("reserved", "byte[8]", 24, 8, SX_RESERVED),
};
static const sx_layout sx_st_apev2_tag = {0x60080027U, "apev2_tag", sx_st_apev2_tag_fields, SX_COUNT(sx_st_apev2_tag_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_apev2_item_fields[] = {
    SX_FIELD("value_size", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("flags", "uint32", 4, 4, SX_FLAGS),
};
static const sx_layout sx_st_apev2_item = {0x60080028U, "apev2_item", sx_st_apev2_item_fields, SX_COUNT(sx_st_apev2_item_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_ivf_header_fields[] = {
    SX_FIELD("signature", "byte[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("version", "uint16", 4, 2, SX_NONE),
    SX_FIELD("header_size", "uint16", 6, 2, SX_SIZE),
    SX_FIELD("codec", "char[4]", 8, 4, SX_STRING),
    SX_FIELD("width", "uint16", 12, 2, SX_NONE),
    SX_FIELD("height", "uint16", 14, 2, SX_NONE),
    SX_FIELD("frame_rate_numerator", "uint32", 16, 4, SX_NONE),
    SX_FIELD("frame_rate_denominator", "uint32", 20, 4, SX_NONE),
    SX_FIELD("declared_frame_count", "uint32", 24, 4, SX_COUNT_PROP),
    SX_FIELD("unused", "uint32", 28, 4, SX_RESERVED),
};
static const sx_layout sx_st_ivf_header = {0x60080029U, "ivf_header", sx_st_ivf_header_fields, SX_COUNT(sx_st_ivf_header_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_ivf_frame_fields[] = {
    SX_FIELD("size", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("timestamp", "uint64", 4, 8, SX_NONE),
};
static const sx_layout sx_st_ivf_frame = {0x6008002AU, "ivf_frame", sx_st_ivf_frame_fields, SX_COUNT(sx_st_ivf_frame_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_roq_header_fields[] = {
    SX_FIELD("signature", "uint16", 0, 2, SX_SIGNATURE),
    SX_FIELD("size_marker", "uint32", 2, 4, SX_SIGNATURE),
    SX_FIELD("frames_per_second", "uint16", 6, 2, SX_NONE),
};
static const sx_layout sx_st_roq_header = {0x6008002BU, "roq_header", sx_st_roq_header_fields, SX_COUNT(sx_st_roq_header_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_roq_chunk_fields[] = {
    SX_FIELD("type", "uint16", 0, 2, SX_ID),
    SX_FIELD("payload_size", "uint32", 2, 4, SX_SIZE),
    SX_FIELD("argument", "uint16", 6, 2, SX_NONE),
};
static const sx_layout sx_st_roq_chunk = {0x6008002CU, "roq_chunk", sx_st_roq_chunk_fields, SX_COUNT(sx_st_roq_chunk_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_roq_info_fields[] = {
    SX_FIELD("width", "uint16", 0, 2, SX_NONE),
    SX_FIELD("height", "uint16", 2, 2, SX_NONE),
    SX_FIELD("maximum_block_size", "uint16", 4, 2, SX_NONE),
    SX_FIELD("minimum_block_size", "uint16", 6, 2, SX_NONE),
};
static const sx_layout sx_st_roq_info = {0x6008002DU, "roq_info", sx_st_roq_info_fields, SX_COUNT(sx_st_roq_info_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_roq_codebook_cell_fields[] = {
    SX_FIELD("y0", "uint8", 0, 1, SX_NONE),
    SX_FIELD("y1", "uint8", 1, 1, SX_NONE),
    SX_FIELD("y2", "uint8", 2, 1, SX_NONE),
    SX_FIELD("y3", "uint8", 3, 1, SX_NONE),
    SX_FIELD("u", "uint8", 4, 1, SX_NONE),
    SX_FIELD("v", "uint8", 5, 1, SX_NONE),
};
static const sx_layout sx_st_roq_codebook_cell = {0x6008002EU, "roq_codebook_cell", sx_st_roq_codebook_cell_fields, SX_COUNT(sx_st_roq_codebook_cell_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_roq_codebook_quad_fields[] = {
    SX_FIELD("cell0", "uint8", 0, 1, SX_ID),
    SX_FIELD("cell1", "uint8", 1, 1, SX_ID),
    SX_FIELD("cell2", "uint8", 2, 1, SX_ID),
    SX_FIELD("cell3", "uint8", 3, 1, SX_ID),
};
static const sx_layout sx_st_roq_codebook_quad = {0x6008002FU, "roq_codebook_quad", sx_st_roq_codebook_quad_fields, SX_COUNT(sx_st_roq_codebook_quad_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_flv_header_fields[] = {
    SX_FIELD("signature", "byte[3]", 0, 3, SX_SIGNATURE),
    SX_FIELD("version", "uint8", 3, 1, SX_NONE),
    SX_FIELD("flags", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("data_offset", "uint32", 5, 4, SX_OFFSET),
};
static const sx_layout sx_st_flv_header = {0x60080030U, "flv_header", sx_st_flv_header_fields, SX_COUNT(sx_st_flv_header_fields), SX_BE};

static const xx_data_struct_field_desc sx_st_flv_previous_tag_fields[] = {
    SX_FIELD("previous_tag_size", "uint32", 0, 4, SX_SIZE),
};
static const sx_layout sx_st_flv_previous_tag = {0x60080031U, "flv_previous_tag", sx_st_flv_previous_tag_fields, SX_COUNT(sx_st_flv_previous_tag_fields), SX_BE};

static const xx_data_struct_field_desc sx_st_flv_tag_fields[] = {
    SX_FIELD("type", "uint8", 0, 1, SX_ID),
    SX_FIELD("data_size", "uint24", 1, 3, SX_SIZE),
    SX_FIELD("timestamp_low24", "uint24", 4, 3, SX_NONE),
    SX_FIELD("timestamp_high8", "uint8", 7, 1, SX_NONE),
    SX_FIELD("stream_id", "uint24", 8, 3, SX_ID),
};
static const sx_layout sx_st_flv_tag = {0x60080032U, "flv_tag", sx_st_flv_tag_fields, SX_COUNT(sx_st_flv_tag_fields), SX_BE};

static const xx_data_struct_field_desc sx_st_flv_audio_fields[] = {
    SX_FIELD("sound_format_rate_size_type", "uint8", 0, 1, SX_FLAGS),
};
static const sx_layout sx_st_flv_audio = {0x60080033U, "flv_audio", sx_st_flv_audio_fields, SX_COUNT(sx_st_flv_audio_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_flv_aac_audio_fields[] = {
    SX_FIELD("sound_format_rate_size_type", "uint8", 0, 1, SX_FLAGS),
    SX_FIELD("aac_packet_type", "uint8", 1, 1, SX_ID),
};
static const sx_layout sx_st_flv_aac_audio = {0x60080034U, "flv_aac_audio", sx_st_flv_aac_audio_fields, SX_COUNT(sx_st_flv_aac_audio_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_flv_video_fields[] = {
    SX_FIELD("frame_type_and_codec_id", "uint8", 0, 1, SX_FLAGS),
};
static const sx_layout sx_st_flv_video = {0x60080035U, "flv_video", sx_st_flv_video_fields, SX_COUNT(sx_st_flv_video_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_flv_avc_video_fields[] = {
    SX_FIELD("frame_type_and_codec_id", "uint8", 0, 1, SX_FLAGS),
    SX_FIELD("avc_packet_type", "uint8", 1, 1, SX_ID),
    SX_FIELD("composition_time", "int24", 2, 3, SX_NONE),
};
static const sx_layout sx_st_flv_avc_video = {0x60080036U, "flv_avc_video", sx_st_flv_avc_video_fields, SX_COUNT(sx_st_flv_avc_video_fields), SX_BE};

static const xx_data_struct_field_desc sx_st_bink_header_fields[] = {
    SX_FIELD("signature", "byte[3]", 0, 3, SX_SIGNATURE),
    SX_FIELD("version", "uint8", 3, 1, SX_NONE),
    SX_FIELD("file_size_minus_eight", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("frame_count", "uint32", 8, 4, SX_COUNT_PROP),
    SX_FIELD("largest_frame_size", "uint32", 12, 4, SX_SIZE),
    SX_FIELD("duplicate_frame_count", "uint32", 16, 4, SX_COUNT_PROP),
    SX_FIELD("width", "uint32", 20, 4, SX_NONE),
    SX_FIELD("height", "uint32", 24, 4, SX_NONE),
    SX_FIELD("frame_rate_numerator", "uint32", 28, 4, SX_NONE),
    SX_FIELD("frame_rate_denominator", "uint32", 32, 4, SX_NONE),
    SX_FIELD("flags", "uint32", 36, 4, SX_FLAGS),
    SX_FIELD("audio_track_count", "uint32", 40, 4, SX_COUNT_PROP),
};
static const sx_layout sx_st_bink_header = {0x60080037U, "bink_header", sx_st_bink_header_fields, SX_COUNT(sx_st_bink_header_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_bink_audio_maximum_fields[] = {
    SX_FIELD("maximum_decoded_size", "uint32", 0, 4, SX_SIZE),
};
static const sx_layout sx_st_bink_audio_maximum = {0x60080038U, "bink_audio_maximum", sx_st_bink_audio_maximum_fields, SX_COUNT(sx_st_bink_audio_maximum_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_bink_audio_format_fields[] = {
    SX_FIELD("sample_rate", "uint16", 0, 2, SX_NONE),
    SX_FIELD("flags", "uint16", 2, 2, SX_FLAGS),
};
static const sx_layout sx_st_bink_audio_format = {0x60080039U, "bink_audio_format", sx_st_bink_audio_format_fields, SX_COUNT(sx_st_bink_audio_format_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_bink_audio_id_fields[] = {
    SX_FIELD("track_id", "uint32", 0, 4, SX_ID),
};
static const sx_layout sx_st_bink_audio_id = {0x6008003AU, "bink_audio_id", sx_st_bink_audio_id_fields, SX_COUNT(sx_st_bink_audio_id_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_bink_frame_index_fields[] = {
    SX_FIELD("offset_and_keyframe_flag", "uint32", 0, 4, SX_OFFSET),
};
static const sx_layout sx_st_bink_frame_index = {0x6008003BU, "bink_frame_index", sx_st_bink_frame_index_fields, SX_COUNT(sx_st_bink_frame_index_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_bink_end_offset_fields[] = {
    SX_FIELD("end_offset", "uint32", 0, 4, SX_OFFSET),
};
static const sx_layout sx_st_bink_end_offset = {0x6008003CU, "bink_end_offset", sx_st_bink_end_offset_fields, SX_COUNT(sx_st_bink_end_offset_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_bink_audio_packet_fields[] = {
    SX_FIELD("packet_size", "uint32", 0, 4, SX_SIZE),
};
static const sx_layout sx_st_bink_audio_packet = {0x6008003DU, "bink_audio_packet", sx_st_bink_audio_packet_fields, SX_COUNT(sx_st_bink_audio_packet_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_bink_audio_decoded_fields[] = {
    SX_FIELD("decoded_size", "uint32", 0, 4, SX_SIZE),
};
static const sx_layout sx_st_bink_audio_decoded = {0x6008003EU, "bink_audio_decoded", sx_st_bink_audio_decoded_fields, SX_COUNT(sx_st_bink_audio_decoded_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_smacker_header_fields[] = {
    SX_FIELD("signature", "byte[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("width", "uint32", 4, 4, SX_NONE),
    SX_FIELD("height", "uint32", 8, 4, SX_NONE),
    SX_FIELD("frame_count", "uint32", 12, 4, SX_COUNT_PROP),
    SX_FIELD("frame_duration", "int32", 16, 4, SX_NONE),
    SX_FIELD("flags", "uint32", 20, 4, SX_FLAGS),
    SX_FIELD("audio_buffer_size_0", "uint32", 24, 4, SX_SIZE),
    SX_FIELD("audio_buffer_size_1", "uint32", 28, 4, SX_SIZE),
    SX_FIELD("audio_buffer_size_2", "uint32", 32, 4, SX_SIZE),
    SX_FIELD("audio_buffer_size_3", "uint32", 36, 4, SX_SIZE),
    SX_FIELD("audio_buffer_size_4", "uint32", 40, 4, SX_SIZE),
    SX_FIELD("audio_buffer_size_5", "uint32", 44, 4, SX_SIZE),
    SX_FIELD("audio_buffer_size_6", "uint32", 48, 4, SX_SIZE),
    SX_FIELD("trees_size", "uint32", 52, 4, SX_SIZE),
    SX_FIELD("mmap_size", "uint32", 56, 4, SX_SIZE),
    SX_FIELD("mclr_size", "uint32", 60, 4, SX_SIZE),
    SX_FIELD("full_size", "uint32", 64, 4, SX_SIZE),
    SX_FIELD("type_size", "uint32", 68, 4, SX_SIZE),
    SX_FIELD("audio_rate_flags_0", "uint32", 72, 4, SX_FLAGS),
    SX_FIELD("audio_rate_flags_1", "uint32", 76, 4, SX_FLAGS),
    SX_FIELD("audio_rate_flags_2", "uint32", 80, 4, SX_FLAGS),
    SX_FIELD("audio_rate_flags_3", "uint32", 84, 4, SX_FLAGS),
    SX_FIELD("audio_rate_flags_4", "uint32", 88, 4, SX_FLAGS),
    SX_FIELD("audio_rate_flags_5", "uint32", 92, 4, SX_FLAGS),
    SX_FIELD("audio_rate_flags_6", "uint32", 96, 4, SX_FLAGS),
    SX_FIELD("dummy", "uint32", 100, 4, SX_RESERVED),
};
static const sx_layout sx_st_smacker_header = {0x6008003FU, "smacker_header", sx_st_smacker_header_fields, SX_COUNT(sx_st_smacker_header_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_smacker_frame_size_fields[] = {
    SX_FIELD("size_and_flags", "uint32", 0, 4, SX_FLAGS),
};
static const sx_layout sx_st_smacker_frame_size = {0x60080040U, "smacker_frame_size", sx_st_smacker_frame_size_fields, SX_COUNT(sx_st_smacker_frame_size_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_smacker_frame_type_fields[] = {
    SX_FIELD("flags", "uint8", 0, 1, SX_FLAGS),
};
static const sx_layout sx_st_smacker_frame_type = {0x60080041U, "smacker_frame_type", sx_st_smacker_frame_type_fields, SX_COUNT(sx_st_smacker_frame_type_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_smacker_audio_packet_fields[] = {
    SX_FIELD("packet_size", "uint32", 0, 4, SX_SIZE),
};
static const sx_layout sx_st_smacker_audio_packet = {0x60080042U, "smacker_audio_packet", sx_st_smacker_audio_packet_fields, SX_COUNT(sx_st_smacker_audio_packet_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_smacker_audio_decoded_fields[] = {
    SX_FIELD("decoded_size", "uint32", 0, 4, SX_SIZE),
};
static const sx_layout sx_st_smacker_audio_decoded = {0x60080043U, "smacker_audio_decoded", sx_st_smacker_audio_decoded_fields, SX_COUNT(sx_st_smacker_audio_decoded_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_smacker_palette_fields[] = {
    SX_FIELD("four_byte_units", "uint8", 0, 1, SX_COUNT_PROP),
};
static const sx_layout sx_st_smacker_palette = {0x60080044U, "smacker_palette", sx_st_smacker_palette_fields, SX_COUNT(sx_st_smacker_palette_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_fli_header_fields[] = {
    SX_FIELD("file_size", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("magic", "uint16", 4, 2, SX_SIGNATURE),
    SX_FIELD("frame_count", "uint16", 6, 2, SX_COUNT_PROP),
    SX_FIELD("width", "uint16", 8, 2, SX_NONE),
    SX_FIELD("height", "uint16", 10, 2, SX_NONE),
    SX_FIELD("depth", "uint16", 12, 2, SX_NONE),
    SX_FIELD("flags", "uint16", 14, 2, SX_FLAGS),
    SX_FIELD("speed_jiffies", "uint16", 16, 2, SX_NONE),
    SX_FIELD("reserved", "byte[110]", 18, 110, SX_RESERVED),
};
static const sx_layout sx_st_fli_header = {0x60080045U, "fli_header", sx_st_fli_header_fields, SX_COUNT(sx_st_fli_header_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_flc_header_fields[] = {
    SX_FIELD("file_size", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("magic", "uint16", 4, 2, SX_SIGNATURE),
    SX_FIELD("frame_count", "uint16", 6, 2, SX_COUNT_PROP),
    SX_FIELD("width", "uint16", 8, 2, SX_NONE),
    SX_FIELD("height", "uint16", 10, 2, SX_NONE),
    SX_FIELD("depth", "uint16", 12, 2, SX_NONE),
    SX_FIELD("flags", "uint16", 14, 2, SX_FLAGS),
    SX_FIELD("speed_milliseconds", "uint32", 16, 4, SX_NONE),
    SX_FIELD("reserved", "uint16", 20, 2, SX_RESERVED),
    SX_FIELD("created_dos_datetime", "uint32", 22, 4, SX_NONE),
    SX_FIELD("creator", "uint32", 26, 4, SX_ID),
    SX_FIELD("updated_dos_datetime", "uint32", 30, 4, SX_NONE),
    SX_FIELD("updater", "uint32", 34, 4, SX_ID),
    SX_FIELD("aspect_x", "uint16", 38, 2, SX_NONE),
    SX_FIELD("aspect_y", "uint16", 40, 2, SX_NONE),
    SX_FIELD("reserved2", "byte[38]", 42, 38, SX_RESERVED),
    SX_FIELD("first_frame_offset", "uint32", 80, 4, SX_OFFSET),
    SX_FIELD("second_frame_offset", "uint32", 84, 4, SX_OFFSET),
    SX_FIELD("reserved3", "byte[40]", 88, 40, SX_RESERVED),
};
static const sx_layout sx_st_flc_header = {0x60080046U, "flc_header", sx_st_flc_header_fields, SX_COUNT(sx_st_flc_header_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_flic_chunk_fields[] = {
    SX_FIELD("size", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("type", "uint16", 4, 2, SX_ID),
};
static const sx_layout sx_st_flic_chunk = {0x60080047U, "flic_chunk", sx_st_flic_chunk_fields, SX_COUNT(sx_st_flic_chunk_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_flic_frame_fields[] = {
    SX_FIELD("size", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("type", "uint16", 4, 2, SX_ID),
    SX_FIELD("chunk_count", "uint16", 6, 2, SX_COUNT_PROP),
    SX_FIELD("delay", "uint16", 8, 2, SX_NONE),
    SX_FIELD("reserved", "uint16", 10, 2, SX_RESERVED),
    SX_FIELD("width_override", "uint16", 12, 2, SX_NONE),
    SX_FIELD("height_override", "uint16", 14, 2, SX_NONE),
};
static const sx_layout sx_st_flic_frame = {0x60080048U, "flic_frame", sx_st_flic_frame_fields, SX_COUNT(sx_st_flic_frame_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_qcow1_header_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("version", "uint32", 4, 4, SX_NONE),
    SX_FIELD("backing_file_offset", "uint64", 8, 8, SX_OFFSET),
    SX_FIELD("backing_file_size", "uint32", 16, 4, SX_SIZE),
    SX_FIELD("mtime", "uint32", 20, 4, SX_TIME),
    SX_FIELD("virtual_size", "uint64", 24, 8, SX_SIZE),
    SX_FIELD("cluster_bits", "uint8", 32, 1, SX_NONE),
    SX_FIELD("l2_bits", "uint8", 33, 1, SX_NONE),
    SX_FIELD("padding", "uint16", 34, 2, SX_RESERVED),
    SX_FIELD("crypt_method", "uint32", 36, 4, SX_ID),
    SX_FIELD("l1_table_offset", "uint64", 40, 8, SX_OFFSET),
};
static const sx_layout sx_st_qcow1_header = {0x60080049U, "qcow1_header", sx_st_qcow1_header_fields, SX_COUNT(sx_st_qcow1_header_fields), SX_BE};

static const xx_data_struct_field_desc sx_st_qcow2_header_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("version", "uint32", 4, 4, SX_NONE),
    SX_FIELD("backing_file_offset", "uint64", 8, 8, SX_OFFSET),
    SX_FIELD("backing_file_size", "uint32", 16, 4, SX_SIZE),
    SX_FIELD("cluster_bits", "uint32", 20, 4, SX_NONE),
    SX_FIELD("virtual_size", "uint64", 24, 8, SX_SIZE),
    SX_FIELD("crypt_method", "uint32", 32, 4, SX_ID),
    SX_FIELD("l1_size", "uint32", 36, 4, SX_COUNT_PROP),
    SX_FIELD("l1_table_offset", "uint64", 40, 8, SX_OFFSET),
    SX_FIELD("refcount_table_offset", "uint64", 48, 8, SX_OFFSET),
    SX_FIELD("refcount_table_clusters", "uint32", 56, 4, SX_COUNT_PROP),
    SX_FIELD("snapshot_count", "uint32", 60, 4, SX_COUNT_PROP),
    SX_FIELD("snapshots_offset", "uint64", 64, 8, SX_OFFSET),
};
static const sx_layout sx_st_qcow2_header = {0x6008004AU, "qcow2_header", sx_st_qcow2_header_fields, SX_COUNT(sx_st_qcow2_header_fields), SX_BE};

static const xx_data_struct_field_desc sx_st_qcow3_header_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("version", "uint32", 4, 4, SX_NONE),
    SX_FIELD("backing_file_offset", "uint64", 8, 8, SX_OFFSET),
    SX_FIELD("backing_file_size", "uint32", 16, 4, SX_SIZE),
    SX_FIELD("cluster_bits", "uint32", 20, 4, SX_NONE),
    SX_FIELD("virtual_size", "uint64", 24, 8, SX_SIZE),
    SX_FIELD("crypt_method", "uint32", 32, 4, SX_ID),
    SX_FIELD("l1_size", "uint32", 36, 4, SX_COUNT_PROP),
    SX_FIELD("l1_table_offset", "uint64", 40, 8, SX_OFFSET),
    SX_FIELD("refcount_table_offset", "uint64", 48, 8, SX_OFFSET),
    SX_FIELD("refcount_table_clusters", "uint32", 56, 4, SX_COUNT_PROP),
    SX_FIELD("snapshot_count", "uint32", 60, 4, SX_COUNT_PROP),
    SX_FIELD("snapshots_offset", "uint64", 64, 8, SX_OFFSET),
    SX_FIELD("incompatible_features", "uint64", 72, 8, SX_FLAGS),
    SX_FIELD("compatible_features", "uint64", 80, 8, SX_FLAGS),
    SX_FIELD("autoclear_features", "uint64", 88, 8, SX_FLAGS),
    SX_FIELD("refcount_order", "uint32", 96, 4, SX_NONE),
    SX_FIELD("header_length", "uint32", 100, 4, SX_SIZE),
};
static const sx_layout sx_st_qcow3_header = {0x6008004BU, "qcow3_header", sx_st_qcow3_header_fields, SX_COUNT(sx_st_qcow3_header_fields), SX_BE};

static const xx_data_struct_field_desc sx_st_qcow_compression_fields[] = {
    SX_FIELD("compression_type", "uint8", 0, 1, SX_ID),
};
static const sx_layout sx_st_qcow_compression = {0x6008004CU, "qcow_compression", sx_st_qcow_compression_fields, SX_COUNT(sx_st_qcow_compression_fields), SX_BE};

static const xx_data_struct_field_desc sx_st_qcow_extension_fields[] = {
    SX_FIELD("type", "uint32", 0, 4, SX_ID),
    SX_FIELD("length", "uint32", 4, 4, SX_SIZE),
};
static const sx_layout sx_st_qcow_extension = {0x6008004DU, "qcow_extension", sx_st_qcow_extension_fields, SX_COUNT(sx_st_qcow_extension_fields), SX_BE};

static const xx_data_struct_field_desc sx_st_qcow_crypto_extension_fields[] = {
    SX_FIELD("header_offset", "uint64", 0, 8, SX_OFFSET),
    SX_FIELD("header_size", "uint64", 8, 8, SX_SIZE),
};
static const sx_layout sx_st_qcow_crypto_extension = {0x6008004EU, "qcow_crypto_extension", sx_st_qcow_crypto_extension_fields, SX_COUNT(sx_st_qcow_crypto_extension_fields), SX_BE};

static const xx_data_struct_field_desc sx_st_qcow_l1_entry_fields[] = {
    SX_FIELD("offset_and_flags", "uint64", 0, 8, SX_OFFSET),
};
static const sx_layout sx_st_qcow_l1_entry = {0x6008004FU, "qcow_l1_entry", sx_st_qcow_l1_entry_fields, SX_COUNT(sx_st_qcow_l1_entry_fields), SX_BE};

static const xx_data_struct_field_desc sx_st_qcow_l2_entry_fields[] = {
    SX_FIELD("offset_and_flags", "uint64", 0, 8, SX_OFFSET),
};
static const sx_layout sx_st_qcow_l2_entry = {0x60080050U, "qcow_l2_entry", sx_st_qcow_l2_entry_fields, SX_COUNT(sx_st_qcow_l2_entry_fields), SX_BE};

static const xx_data_struct_field_desc sx_st_qcow_l2_extended_fields[] = {
    SX_FIELD("offset_and_flags", "uint64", 0, 8, SX_OFFSET),
    SX_FIELD("subcluster_zero_bitmap", "uint32", 8, 4, SX_FLAGS),
    SX_FIELD("subcluster_allocation_bitmap", "uint32", 12, 4, SX_FLAGS),
};
static const sx_layout sx_st_qcow_l2_extended = {0x60080051U, "qcow_l2_extended", sx_st_qcow_l2_extended_fields, SX_COUNT(sx_st_qcow_l2_extended_fields), SX_BE};

static const xx_data_struct_field_desc sx_st_qcow1_l1_entry_fields[] = {
    SX_FIELD("l2_table_offset", "uint64", 0, 8, SX_OFFSET),
};
static const sx_layout sx_st_qcow1_l1_entry = {0x60080052U, "qcow1_l1_entry", sx_st_qcow1_l1_entry_fields, SX_COUNT(sx_st_qcow1_l1_entry_fields), SX_BE};

static const xx_data_struct_field_desc sx_st_qcow1_l2_entry_fields[] = {
    SX_FIELD("offset_and_compressed_flag", "uint64", 0, 8, SX_OFFSET),
};
static const sx_layout sx_st_qcow1_l2_entry = {0x60080053U, "qcow1_l2_entry", sx_st_qcow1_l2_entry_fields, SX_COUNT(sx_st_qcow1_l2_entry_fields), SX_BE};

static const xx_data_struct_field_desc sx_st_qcow_refcount_pointer_fields[] = {
    SX_FIELD("block_offset", "uint64", 0, 8, SX_OFFSET),
};
static const sx_layout sx_st_qcow_refcount_pointer = {0x60080054U, "qcow_refcount_pointer", sx_st_qcow_refcount_pointer_fields, SX_COUNT(sx_st_qcow_refcount_pointer_fields), SX_BE};

static const xx_data_struct_field_desc sx_st_qcow_snapshot_fields[] = {
    SX_FIELD("l1_table_offset", "uint64", 0, 8, SX_OFFSET),
    SX_FIELD("l1_size", "uint32", 8, 4, SX_COUNT_PROP),
    SX_FIELD("id_string_size", "uint16", 12, 2, SX_SIZE),
    SX_FIELD("name_size", "uint16", 14, 2, SX_SIZE),
    SX_FIELD("date_seconds", "uint32", 16, 4, SX_TIME),
    SX_FIELD("date_nanoseconds", "uint32", 20, 4, SX_NONE),
    SX_FIELD("vm_clock_nanoseconds", "uint64", 24, 8, SX_NONE),
    SX_FIELD("vm_state_size", "uint32", 32, 4, SX_SIZE),
    SX_FIELD("extra_data_size", "uint32", 36, 4, SX_SIZE),
};
static const sx_layout sx_st_qcow_snapshot = {0x60080055U, "qcow_snapshot", sx_st_qcow_snapshot_fields, SX_COUNT(sx_st_qcow_snapshot_fields), SX_BE};

static const xx_data_struct_field_desc sx_st_luks1_header_fields[] = {
    SX_FIELD("magic", "byte[6]", 0, 6, SX_SIGNATURE),
    SX_FIELD("version", "uint16", 6, 2, SX_NONE),
    SX_FIELD("cipher_name", "char[32]", 8, 32, SX_STRING),
    SX_FIELD("cipher_mode", "char[32]", 40, 32, SX_STRING),
    SX_FIELD("hash_spec", "char[32]", 72, 32, SX_STRING),
    SX_FIELD("payload_sector", "uint32", 104, 4, SX_OFFSET),
    SX_FIELD("key_bytes", "uint32", 108, 4, SX_SIZE),
    SX_FIELD("master_key_digest", "byte[20]", 112, 20, SX_CHECKSUM),
    SX_FIELD("master_key_salt", "byte[32]", 132, 32, SX_NONE),
    SX_FIELD("master_key_iterations", "uint32", 164, 4, SX_COUNT_PROP),
    SX_FIELD("uuid", "char[40]", 168, 40, SX_STRING),
};
static const sx_layout sx_st_luks1_header = {0x60080056U, "luks1_header", sx_st_luks1_header_fields, SX_COUNT(sx_st_luks1_header_fields), SX_BE};

static const xx_data_struct_field_desc sx_st_luks1_keyslot_fields[] = {
    SX_FIELD("active", "uint32", 0, 4, SX_ID),
    SX_FIELD("iterations", "uint32", 4, 4, SX_COUNT_PROP),
    SX_FIELD("salt", "byte[32]", 8, 32, SX_NONE),
    SX_FIELD("key_material_sector", "uint32", 40, 4, SX_OFFSET),
    SX_FIELD("stripes", "uint32", 44, 4, SX_COUNT_PROP),
};
static const sx_layout sx_st_luks1_keyslot = {0x60080057U, "luks1_keyslot", sx_st_luks1_keyslot_fields, SX_COUNT(sx_st_luks1_keyslot_fields), SX_BE};

static const xx_data_struct_field_desc sx_st_luks2_header_fields[] = {
    SX_FIELD("magic", "byte[6]", 0, 6, SX_SIGNATURE),
    SX_FIELD("version", "uint16", 6, 2, SX_NONE),
    SX_FIELD("header_size", "uint64", 8, 8, SX_SIZE),
    SX_FIELD("sequence_id", "uint64", 16, 8, SX_NONE),
    SX_FIELD("label", "char[48]", 24, 48, SX_STRING),
    SX_FIELD("checksum_algorithm", "char[32]", 72, 32, SX_STRING),
    SX_FIELD("salt", "byte[64]", 104, 64, SX_NONE),
    SX_FIELD("uuid", "char[40]", 168, 40, SX_STRING),
    SX_FIELD("subsystem", "char[48]", 208, 48, SX_STRING),
    SX_FIELD("header_offset", "uint64", 256, 8, SX_OFFSET),
    SX_FIELD("padding", "byte[184]", 264, 184, SX_RESERVED),
    SX_FIELD("checksum", "byte[64]", 448, 64, SX_CHECKSUM),
    SX_FIELD("padding4096", "byte[3584]", 512, 3584, SX_RESERVED),
};
static const sx_layout sx_st_luks2_header = {0x60080058U, "luks2_header", sx_st_luks2_header_fields, SX_COUNT(sx_st_luks2_header_fields), SX_BE};

static const xx_data_struct_field_desc sx_st_romfs_superblock_fields[] = {
    SX_FIELD("signature", "byte[8]", 0, 8, SX_SIGNATURE),
    SX_FIELD("full_size", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("checksum", "uint32", 12, 4, SX_CHECKSUM),
};
static const sx_layout sx_st_romfs_superblock = {0x60080059U, "romfs_superblock", sx_st_romfs_superblock_fields, SX_COUNT(sx_st_romfs_superblock_fields), SX_BE};

static const xx_data_struct_field_desc sx_st_romfs_inode_fields[] = {
    SX_FIELD("next_offset_and_type", "uint32", 0, 4, SX_OFFSET),
    SX_FIELD("spec_info", "uint32", 4, 4, SX_NONE),
    SX_FIELD("size", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("checksum", "uint32", 12, 4, SX_CHECKSUM),
};
static const sx_layout sx_st_romfs_inode = {0x6008005AU, "romfs_inode", sx_st_romfs_inode_fields, SX_COUNT(sx_st_romfs_inode_fields), SX_BE};

static const xx_data_struct_field_desc sx_st_cramfs_superblock_le_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("size", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("flags", "uint32", 8, 4, SX_FLAGS),
    SX_FIELD("future", "uint32", 12, 4, SX_RESERVED),
    SX_FIELD("signature", "byte[16]", 16, 16, SX_SIGNATURE),
    SX_FIELD("crc32", "uint32", 32, 4, SX_CHECKSUM),
    SX_FIELD("edition", "uint32", 36, 4, SX_NONE),
    SX_FIELD("block_count", "uint32", 40, 4, SX_COUNT_PROP),
    SX_FIELD("file_count", "uint32", 44, 4, SX_COUNT_PROP),
    SX_FIELD("name", "char[16]", 48, 16, SX_STRING),
};
static const sx_layout sx_st_cramfs_superblock_le = {0x6008005BU, "cramfs_superblock_le", sx_st_cramfs_superblock_le_fields, SX_COUNT(sx_st_cramfs_superblock_le_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_cramfs_inode_le_fields[] = {
    SX_FIELD("mode_uid", "uint32", 0, 4, SX_FLAGS),
    SX_FIELD("size_gid", "uint32", 4, 4, SX_NONE),
    SX_FIELD("name_length_and_offset", "uint32", 8, 4, SX_OFFSET),
};
static const sx_layout sx_st_cramfs_inode_le = {0x6008005CU, "cramfs_inode_le", sx_st_cramfs_inode_le_fields, SX_COUNT(sx_st_cramfs_inode_le_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_cramfs_block_pointer_le_fields[] = {
    SX_FIELD("end_offset_and_flags", "uint32", 0, 4, SX_OFFSET),
};
static const sx_layout sx_st_cramfs_block_pointer_le = {0x6008005DU, "cramfs_block_pointer_le", sx_st_cramfs_block_pointer_le_fields, SX_COUNT(sx_st_cramfs_block_pointer_le_fields), SX_LE};

static const xx_data_struct_field_desc sx_st_cramfs_superblock_be_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("size", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("flags", "uint32", 8, 4, SX_FLAGS),
    SX_FIELD("future", "uint32", 12, 4, SX_RESERVED),
    SX_FIELD("signature", "byte[16]", 16, 16, SX_SIGNATURE),
    SX_FIELD("crc32", "uint32", 32, 4, SX_CHECKSUM),
    SX_FIELD("edition", "uint32", 36, 4, SX_NONE),
    SX_FIELD("block_count", "uint32", 40, 4, SX_COUNT_PROP),
    SX_FIELD("file_count", "uint32", 44, 4, SX_COUNT_PROP),
    SX_FIELD("name", "char[16]", 48, 16, SX_STRING),
};
static const sx_layout sx_st_cramfs_superblock_be = {0x6008005EU, "cramfs_superblock_be", sx_st_cramfs_superblock_be_fields, SX_COUNT(sx_st_cramfs_superblock_be_fields), SX_BE};

static const xx_data_struct_field_desc sx_st_cramfs_inode_be_fields[] = {
    SX_FIELD("mode_uid", "uint32", 0, 4, SX_FLAGS),
    SX_FIELD("size_gid", "uint32", 4, 4, SX_NONE),
    SX_FIELD("name_length_and_offset", "uint32", 8, 4, SX_OFFSET),
};
static const sx_layout sx_st_cramfs_inode_be = {0x6008005FU, "cramfs_inode_be", sx_st_cramfs_inode_be_fields, SX_COUNT(sx_st_cramfs_inode_be_fields), SX_BE};

static const xx_data_struct_field_desc sx_st_cramfs_block_pointer_be_fields[] = {
    SX_FIELD("end_offset_and_flags", "uint32", 0, 4, SX_OFFSET),
};
static const sx_layout sx_st_cramfs_block_pointer_be = {0x60080060U, "cramfs_block_pointer_be", sx_st_cramfs_block_pointer_be_fields, SX_COUNT(sx_st_cramfs_block_pointer_be_fields), SX_BE};

static const sx_layout *const sx_storage_layouts[] = {
    &sx_st_midi_header,
    &sx_st_midi_track,
    &sx_st_caf_header,
    &sx_st_caf_chunk,
    &sx_st_caf_description,
    &sx_st_caf_data,
    &sx_st_caf_packet_table,
    &sx_st_voc_header,
    &sx_st_voc_block,
    &sx_st_voc_terminator,
    &sx_st_voc_sound,
    &sx_st_voc_silence,
    &sx_st_voc_marker,
    &sx_st_voc_repeat,
    &sx_st_voc_sound_v2,
    &sx_st_vag_header,
    &sx_st_vag_adpcm_frame,
    &sx_st_psf_header,
    &sx_st_dsf_header,
    &sx_st_dsf_format,
    &sx_st_dsf_data,
    &sx_st_dff_form,
    &sx_st_dff_chunk,
    &sx_st_dff_version,
    &sx_st_dff_property,
    &sx_st_dff_frequency,
    &sx_st_dff_channels,
    &sx_st_dff_channel,
    &sx_st_dff_compression,
    &sx_st_wave64_header,
    &sx_st_wave64_chunk,
    &sx_st_wave64_format,
    &sx_st_wave64_format_extra,
    &sx_st_adx_header,
    &sx_st_adx_terminator,
    &sx_st_wavpack_block,
    &sx_st_wavpack_metadata,
    &sx_st_wavpack_metadata_large,
    &sx_st_apev2_tag,
    &sx_st_apev2_item,
    &sx_st_ivf_header,
    &sx_st_ivf_frame,
    &sx_st_roq_header,
    &sx_st_roq_chunk,
    &sx_st_roq_info,
    &sx_st_roq_codebook_cell,
    &sx_st_roq_codebook_quad,
    &sx_st_flv_header,
    &sx_st_flv_previous_tag,
    &sx_st_flv_tag,
    &sx_st_flv_audio,
    &sx_st_flv_aac_audio,
    &sx_st_flv_video,
    &sx_st_flv_avc_video,
    &sx_st_bink_header,
    &sx_st_bink_audio_maximum,
    &sx_st_bink_audio_format,
    &sx_st_bink_audio_id,
    &sx_st_bink_frame_index,
    &sx_st_bink_end_offset,
    &sx_st_bink_audio_packet,
    &sx_st_bink_audio_decoded,
    &sx_st_smacker_header,
    &sx_st_smacker_frame_size,
    &sx_st_smacker_frame_type,
    &sx_st_smacker_audio_packet,
    &sx_st_smacker_audio_decoded,
    &sx_st_smacker_palette,
    &sx_st_fli_header,
    &sx_st_flc_header,
    &sx_st_flic_chunk,
    &sx_st_flic_frame,
    &sx_st_qcow1_header,
    &sx_st_qcow2_header,
    &sx_st_qcow3_header,
    &sx_st_qcow_compression,
    &sx_st_qcow_extension,
    &sx_st_qcow_crypto_extension,
    &sx_st_qcow_l1_entry,
    &sx_st_qcow_l2_entry,
    &sx_st_qcow_l2_extended,
    &sx_st_qcow1_l1_entry,
    &sx_st_qcow1_l2_entry,
    &sx_st_qcow_refcount_pointer,
    &sx_st_qcow_snapshot,
    &sx_st_luks1_header,
    &sx_st_luks1_keyslot,
    &sx_st_luks2_header,
    &sx_st_romfs_superblock,
    &sx_st_romfs_inode,
    &sx_st_cramfs_superblock_le,
    &sx_st_cramfs_inode_le,
    &sx_st_cramfs_block_pointer_le,
    &sx_st_cramfs_superblock_be,
    &sx_st_cramfs_inode_be,
    &sx_st_cramfs_block_pointer_be,
};
/* Physical records only; native readers establish validity, while this walker
 * independently bounds every field and pointed-to table. Codec streams, names,
 * JSON and unsupported/over-budget metadata stay explicitly RAW_DATA. */
static bool sx_storage_supports(xx_file_type_t t)
{
    switch(t) {
    case XX_FILE_TYPE_MIDI: case XX_FILE_TYPE_CAF: case XX_FILE_TYPE_CREATIVE_VOC:
    case XX_FILE_TYPE_SONY_VAG: case XX_FILE_TYPE_SONY_PSF: case XX_FILE_TYPE_AUDIO_DSF:
    case XX_FILE_TYPE_AUDIO_DFF: case XX_FILE_TYPE_AUDIO_WAVE64: case XX_FILE_TYPE_AUDIO_ADX:
    case XX_FILE_TYPE_AUDIO_WAVPACK: case XX_FILE_TYPE_IVF: case XX_FILE_TYPE_IDTECH_ROQ:
    case XX_FILE_TYPE_FLASH_VIDEO_FLV: case XX_FILE_TYPE_RAD_BINK: case XX_FILE_TYPE_RAD_SMACKER:
    case XX_FILE_TYPE_AUTODESK_FLIC: case XX_FILE_TYPE_QCOW: case XX_FILE_TYPE_QCOW1:
    case XX_FILE_TYPE_LUKS: case XX_FILE_TYPE_ROMFS: case XX_FILE_TYPE_CRAMFS:return true;
    default:return false;
    }
}
static bool sx_st_fits(const sx_context *c,uint64_t o,uint64_t n)
{return c&&c->size>=0&&o<=(uint64_t)c->size&&n<=(uint64_t)c->size-o;}
static void sx_st_sort(sx_context *c)
{
    for(size_t gap=c->count/2;gap;gap/=2)for(size_t i=gap;i<c->count;i++) {
        xx_data_struct item=c->items[i];size_t j=i;
        while(j>=gap&&c->items[j-gap].offset>item.offset){c->items[j]=c->items[j-gap];j-=gap;}
        c->items[j]=item;
    }
}
static bool sx_st_finish(sx_context *c)
{
    int64_t end=0;size_t n=c->count;sx_st_sort(c);
    for(size_t i=0;i<n;i++) {
        int64_t off=c->items[i].offset-c->f->base_address;
        if(off<end)return false;
        if(off>end&&!sx_raw(c,end,off-end))return false;
        end=off+c->items[i].total_size;
    }
    if(end<c->size&&!sx_raw(c,end,c->size-end))return false;
    sx_st_sort(c);return !c->failed;
}
/* Pointer graphs may alias, cycle or intersect other metadata. Only nonoverlapping
 * physical regions become structures; a rejected candidate is retained as raw. */
static bool sx_st_free(sx_context *c,uint64_t o,uint64_t n)
{
    if(!sx_st_fits(c,o,n)||c->count>=20000)return false;
    for(size_t i=0;i<c->count;i++) {
        uint64_t x=(uint64_t)(c->items[i].offset-c->f->base_address),z=(uint64_t)c->items[i].total_size;
        if(o<x+z&&x<o+n)return false;
    }
    return true;
}
static bool sx_st_midi(sx_context *c)
{
    uint32_t n;uint16_t tracks;uint64_t at;
    if(!sx_add(c,&sx_st_midi_header,0,14)||!sx_u32(c,4,true,&n)||!sx_u16(c,10,true,&tracks))return false;
    at=8+(uint64_t)n;
    for(uint32_t j=0;j<tracks&&c->count<20000;j++) {
        if(!sx_add(c,&sx_st_midi_track,(int64_t)at,8)||!sx_u32(c,(int64_t)at+4,true,&n)||!sx_st_fits(c,at+8,n))return false;
        at+=8+(uint64_t)n;
    }
    return true;
}
static bool sx_st_caf(sx_context *c)
{
    uint64_t at=8;
    if(!sx_add(c,&sx_st_caf_header,0,8))return false;
    while(at<(uint64_t)c->size) {
        uint8_t h[12];uint64_t n;
        if(!sx_read(c,(int64_t)at,h,12)||!sx_add(c,&sx_st_caf_chunk,(int64_t)at,12))return false;
        n=xx_data_get_u64(h,12,4,true);at+=12;
        if(n==UINT64_MAX)n=(uint64_t)c->size-at;
        if(!sx_st_fits(c,at,n))return false;
        if(!xx_rt_memcmp(h,"desc",4)){if(n!=32||!sx_add(c,&sx_st_caf_description,(int64_t)at,32))return false;}
        else if(!xx_rt_memcmp(h,"data",4)){if(n<4||!sx_add(c,&sx_st_caf_data,(int64_t)at,4))return false;}
        else if(!xx_rt_memcmp(h,"pakt",4)){if(n<24||!sx_add(c,&sx_st_caf_packet_table,(int64_t)at,24))return false;}
        at+=n;if(c->count>=20000)break;
    }
    return true;
}
static bool sx_st_voc(sx_context *c)
{
    uint16_t offset;uint64_t at;
    if(!sx_add(c,&sx_st_voc_header,0,26)||!sx_u16(c,20,false,&offset))return false;at=offset;
    while(at<(uint64_t)c->size) {
        uint8_t h[4];uint32_t n;const sx_layout *l=NULL;unsigned z=0;
        if(!sx_read(c,(int64_t)at,h,1))return false;
        if(!h[0])return sx_add(c,&sx_st_voc_terminator,(int64_t)at,1);
        if(!sx_read(c,(int64_t)at,h,4)||!sx_add(c,&sx_st_voc_block,(int64_t)at,4))return false;
        n=xx_data_get_u24(h,4,1,false);at+=4;if(!sx_st_fits(c,at,n))return false;
        switch(h[0]){case 1:l=&sx_st_voc_sound;z=2;break;case 3:l=&sx_st_voc_silence;z=3;break;case 4:l=&sx_st_voc_marker;z=2;break;case 6:l=&sx_st_voc_repeat;z=2;break;case 9:l=&sx_st_voc_sound_v2;z=12;break;default:break;}
        if(l&&(n<z||!sx_add(c,l,(int64_t)at,z)))return false;at+=n;
    }
    return false;
}
static bool sx_st_dff_chunks(sx_context *c,uint64_t at,uint64_t end,bool properties)
{
    while(at<end) {
        uint8_t h[12];uint64_t n;
        if(end-at<12||!sx_read(c,(int64_t)at,h,12)||!sx_add(c,&sx_st_dff_chunk,(int64_t)at,12))return false;
        n=xx_data_get_u64(h,12,4,true);at+=12;if(n>end-at)return false;
        if(!properties&&!xx_rt_memcmp(h,"PROP",4)) {
            if(n<4||!sx_add(c,&sx_st_dff_property,(int64_t)at,4)||!sx_st_dff_chunks(c,at+4,at+n,true))return false;
        } else if(!properties&&!xx_rt_memcmp(h,"FVER",4)) {
            if(n!=4||!sx_add(c,&sx_st_dff_version,(int64_t)at,4))return false;
        } else if(properties&&!xx_rt_memcmp(h,"FS  ",4)) {
            if(n!=4||!sx_add(c,&sx_st_dff_frequency,(int64_t)at,4))return false;
        } else if(properties&&!xx_rt_memcmp(h,"CHNL",4)) {
            uint16_t count;if(n<2||!sx_u16(c,(int64_t)at,true,&count)||n!=2+(uint64_t)count*4||!sx_add(c,&sx_st_dff_channels,(int64_t)at,2)||!sx_table(c,&sx_st_dff_channel,(int64_t)at+2,4,count))return false;
        } else if(properties&&!xx_rt_memcmp(h,"CMPR",4)) {
            if(n<5||!sx_add(c,&sx_st_dff_compression,(int64_t)at,5))return false;
        }
        at+=n;if(n&1){if(at>=end)return false;at++;}
    }
    return at==end;
}
static bool sx_st_wave64(sx_context *c)
{
    uint64_t at=40;
    if(!sx_add(c,&sx_st_wave64_header,0,40))return false;
    while(at<(uint64_t)c->size) {
        uint8_t h[24];uint64_t n;
        if(!sx_read(c,(int64_t)at,h,24)||!sx_add(c,&sx_st_wave64_chunk,(int64_t)at,24))return false;
        n=xx_data_get_u64(h,24,16,false);if(n<24||!sx_st_fits(c,at,n))return false;
        if(!xx_rt_memcmp(h,"fmt ",4)) {
            if(n<40||!sx_add(c,&sx_st_wave64_format,(int64_t)at+24,16))return false;
            if(n>=42&&!sx_add(c,&sx_st_wave64_format_extra,(int64_t)at+40,2))return false;
        }
        at+=n;if(at>UINT64_MAX-7)return false;at=(at+7)&~UINT64_C(7);
    }
    return at==(uint64_t)c->size;
}
static bool sx_st_ape(sx_context *c,uint64_t at)
{
    uint8_t h[32];uint64_t end=(uint64_t)c->size;uint32_t count,flags;
    if(end-at<32||!sx_read(c,(int64_t)end-32,h,32)||!sx_add(c,&sx_st_apev2_tag,(int64_t)end-32,32))return false;
    count=xx_data_get_u32(h,32,16,false);flags=xx_data_get_u32(h,32,20,false);end-=32;
    if(flags&0x80000000U){if(end-at<32||!sx_add(c,&sx_st_apev2_tag,(int64_t)at,32))return false;at+=32;}
    for(uint32_t j=0;j<count;j++) {
        uint32_t n;uint8_t ch=1;unsigned len=0;
        if(end-at<8||!sx_u32(c,(int64_t)at,false,&n)||!sx_add(c,&sx_st_apev2_item,(int64_t)at,8))return false;at+=8;
        while(ch&&at<end&&len++<256){if(!sx_read(c,(int64_t)at++,&ch,1))return false;}
        if(ch||n>end-at)return false;at+=n;
    }
    return at==end;
}
static bool sx_st_wavpack(sx_context *c)
{
    uint64_t at=0;
    while(at<(uint64_t)c->size) {
        uint8_t h[32];uint32_t n;
        if(!sx_read(c,(int64_t)at,h,8))return false;
        if(!xx_rt_memcmp(h,"APETAGEX",8))return sx_st_ape(c,at);
        if(!sx_read(c,(int64_t)at,h,32)||!sx_add(c,&sx_st_wavpack_block,(int64_t)at,32))return false;
        n=xx_data_get_u32(h,32,4,false);if(n<24||!sx_st_fits(c,at,8+(uint64_t)n))return false;
        uint64_t end=at+8+n;at+=32;
        while(at<end) {
            uint8_t m[4];uint32_t words;unsigned size;
            if(end-at<2||!sx_read(c,(int64_t)at,m,2))return false;size=(m[0]&128)?4:2;
            if(end-at<size||!sx_read(c,(int64_t)at,m,size)||!sx_add(c,size==4?&sx_st_wavpack_metadata_large:&sx_st_wavpack_metadata,(int64_t)at,size))return false;
            words=size==4?xx_data_get_u24(m,4,1,false):m[1];at+=size;
            if((uint64_t)words*2>end-at)return false;at+=(uint64_t)words*2;
            if(c->count>=20000)return true;
        }
        if(c->count>=20000)break;
    }
    return true;
}
static bool sx_st_ivf(sx_context *c)
{
    uint64_t at=32;if(!sx_add(c,&sx_st_ivf_header,0,32))return false;
    while(at<(uint64_t)c->size) {
        uint32_t n;if(!sx_add(c,&sx_st_ivf_frame,(int64_t)at,12)||!sx_u32(c,(int64_t)at,false,&n)||!sx_st_fits(c,at+12,n))return false;
        at+=12+(uint64_t)n;if(c->count>=20000)break;
    }
    return true;
}
static bool sx_st_roq(sx_context *c)
{
    uint64_t at=8;if(!sx_add(c,&sx_st_roq_header,0,8))return false;
    while(at<(uint64_t)c->size) {
        uint8_t h[8];uint16_t type,arg;uint32_t n;
        if(!sx_read(c,(int64_t)at,h,8)||!sx_add(c,&sx_st_roq_chunk,(int64_t)at,8))return false;
        type=xx_data_get_u16(h,8,0,false);n=xx_data_get_u32(h,8,2,false);arg=xx_data_get_u16(h,8,6,false);at+=8;
        if(!sx_st_fits(c,at,n))return false;
        if(type==0x1001){if(n!=8||!sx_add(c,&sx_st_roq_info,(int64_t)at,8))return false;}
        else if(type==0x1002) {
            unsigned cells=arg>>8,quads=arg&255;if(!cells)cells=256;if(!quads&&n>cells*6)quads=256;
            if(n!=cells*6+quads*4||!sx_table(c,&sx_st_roq_codebook_cell,(int64_t)at,6,cells)||!sx_table(c,&sx_st_roq_codebook_quad,(int64_t)at+cells*6,4,quads))return false;
        }
        at+=n;
    }
    return true;
}
static bool sx_st_flv(sx_context *c)
{
    uint32_t start;uint64_t at;
    if(!sx_add(c,&sx_st_flv_header,0,9)||!sx_u32(c,5,true,&start)||!sx_add(c,&sx_st_flv_previous_tag,start,4))return false;at=(uint64_t)start+4;
    while(at<(uint64_t)c->size) {
        uint8_t h[11],first;uint32_t n;
        if(!sx_read(c,(int64_t)at,h,11)||!sx_add(c,&sx_st_flv_tag,(int64_t)at,11))return false;
        n=xx_data_get_u24(h,11,1,true);at+=11;if(!n||!sx_st_fits(c,at,(uint64_t)n+4)||!sx_read(c,(int64_t)at,&first,1))return false;
        if(h[0]==8){bool aac=(first>>4)==10;if(n<(aac?2U:1U)||!sx_add(c,aac?&sx_st_flv_aac_audio:&sx_st_flv_audio,(int64_t)at,aac?2:1))return false;}
        else if(h[0]==9){bool avc=(first&15)==7;if(n<(avc?5U:1U)||!sx_add(c,avc?&sx_st_flv_avc_video:&sx_st_flv_video,(int64_t)at,avc?5:1))return false;}
        at+=n;if(!sx_add(c,&sx_st_flv_previous_tag,(int64_t)at,4))return false;at+=4;
    }
    return true;
}
static bool sx_st_bink(sx_context *c)
{
    uint32_t frames,tracks,first;uint64_t table;
    if(!sx_add(c,&sx_st_bink_header,0,44)||!sx_u32(c,8,false,&frames)||!sx_u32(c,40,false,&tracks)||!frames||frames>4094||tracks>16)return false;
    table=44+(uint64_t)tracks*12;
    if(!sx_table(c,&sx_st_bink_audio_maximum,44,4,tracks)||!sx_table(c,&sx_st_bink_audio_format,44+tracks*4,4,tracks)||!sx_table(c,&sx_st_bink_audio_id,44+tracks*8,4,tracks)||!sx_table(c,&sx_st_bink_frame_index,(int64_t)table,4,frames)||!sx_u32(c,(int64_t)table,false,&first))return false;
    if((first&~1U)==table+(uint64_t)frames*4+4&&!sx_add(c,&sx_st_bink_end_offset,(int64_t)(table+(uint64_t)frames*4),4))return false;
    for(uint32_t i=0;i<frames;i++) {
        uint32_t begin,next;uint64_t at,end=(uint64_t)c->size;
        if(!sx_u32(c,(int64_t)(table+(uint64_t)i*4),false,&begin))return false;at=begin&~1U;
        if(i+1<frames){if(!sx_u32(c,(int64_t)(table+(uint64_t)(i+1)*4),false,&next))return false;end=next&~1U;}
        if(at>end||!sx_st_fits(c,at,end-at))return false;
        for(uint32_t j=0;j<tracks;j++) {
            uint32_t n;if(end-at<4||!sx_u32(c,(int64_t)at,false,&n)||!sx_add(c,&sx_st_bink_audio_packet,(int64_t)at,4))return false;at+=4;
            if(n>end-at)return false;if(n&&(n<4||!sx_add(c,&sx_st_bink_audio_decoded,(int64_t)at,4)))return false;at+=n;
        }
        if(c->count>=20000)break;
    }
    return true;
}
static bool sx_st_smacker(sx_context *c)
{
    uint8_t h[104];uint32_t frames,flags,trees;uint64_t at,types;
    if(!sx_read(c,0,h,104)||!sx_add(c,&sx_st_smacker_header,0,104))return false;
    frames=xx_data_get_u32(h,104,12,false);flags=xx_data_get_u32(h,104,20,false);trees=xx_data_get_u32(h,104,52,false);
    if(frames>4092)return false;frames+=flags&1;types=104+(uint64_t)frames*4;at=types+frames+trees;
    if(!sx_table(c,&sx_st_smacker_frame_size,104,4,frames)||!sx_table(c,&sx_st_smacker_frame_type,(int64_t)types,1,frames)||!sx_st_fits(c,types+frames,trees))return false;
    for(uint32_t i=0;i<frames;i++) {
        uint32_t size;uint8_t type;uint64_t q=at,end;
        if(!sx_u32(c,104+(int64_t)i*4,false,&size)||!sx_read(c,(int64_t)types+i,&type,1))return false;size&=~3U;
        if(!sx_st_fits(c,at,size))return false;end=at+size;
        if(type&1){uint8_t units;if(!sx_read(c,(int64_t)q,&units,1)||!units||(uint64_t)units*4>end-q||!sx_add(c,&sx_st_smacker_palette,(int64_t)q,1))return false;q+=(uint64_t)units*4;}
        for(unsigned j=0;j<7;j++)if(type&(2U<<j)) {
            uint32_t n,af=xx_data_get_u32(h,104,72+j*4,false)>>24;bool prefix=(af&0x8c)||!(af&0x20);
            if(end-q<4||!sx_u32(c,(int64_t)q,false,&n)||n<(prefix?8U:4U)||n>end-q||!sx_add(c,&sx_st_smacker_audio_packet,(int64_t)q,4))return false;
            if(prefix&&!sx_add(c,&sx_st_smacker_audio_decoded,(int64_t)q+4,4))return false;q+=n;
        }
        at=end;if(c->count>=20000)break;
    }
    return true;
}
static bool sx_st_flic(sx_context *c)
{
    uint16_t magic;uint64_t at=128;
    if(!sx_u16(c,4,false,&magic)||!sx_add(c,magic==0xaf11?&sx_st_fli_header:&sx_st_flc_header,0,128))return false;
    while(at<(uint64_t)c->size) {
        uint32_t n;uint16_t type;
        if(!sx_u32(c,(int64_t)at,false,&n)||!sx_u16(c,(int64_t)at+4,false,&type)||n<6||!sx_st_fits(c,at,n))return false;
        if(type==0xf1fa) {
            uint16_t count;uint64_t q=at+16,end=at+n;
            if(n<16||!sx_add(c,&sx_st_flic_frame,(int64_t)at,16)||!sx_u16(c,(int64_t)at+6,false,&count))return false;
            for(uint32_t i=0;i<count&&c->count<20000;i++) {
                uint32_t z;if(end-q<6||!sx_u32(c,(int64_t)q,false,&z)||z<6||z>end-q||!sx_add(c,&sx_st_flic_chunk,(int64_t)q,6))return false;q+=z;
            }
        } else if(!sx_add(c,&sx_st_flic_chunk,(int64_t)at,6))return false;
        at+=n;if(c->count>=20000)break;
    }
    return true;
}
static bool sx_st_luks(sx_context *c)
{
    uint16_t version;if(!sx_u16(c,6,true,&version))return false;
    if(version==1)return sx_add(c,&sx_st_luks1_header,0,208)&&sx_table(c,&sx_st_luks1_keyslot,208,48,8);
    if(version==2) {
        uint64_t span;uint8_t magic[8];
        if(!sx_add(c,&sx_st_luks2_header,0,4096)||!sx_u64(c,8,true,&span))return false;
        if(span>=4096&&sx_st_fits(c,span,4096)) {
            uint64_t size,off;
            if(!sx_read(c,(int64_t)span,magic,8))return false;
            if(!xx_rt_memcmp(magic,"SKUL\xba\xbe\0\2",8)) {
                if(!sx_u64(c,(int64_t)span+8,true,&size)||!sx_u64(c,(int64_t)span+256,true,&off))return false;
                if(off==span&&size>=4096&&sx_st_fits(c,span,size)&&!sx_add(c,&sx_st_luks2_header,(int64_t)span,4096))return false;
            }
        }
        return true;
    }
    return false;
}
static bool sx_st_qcow_l1(sx_context *c,uint64_t at,uint64_t count,uint32_t bits,uint32_t l2bits,bool v1,bool extended)
{
    uint64_t l2bytes=UINT64_C(8)<<l2bits;
    if(count>1048576||(!v1&&(at&((UINT64_C(1)<<bits)-1)))||!sx_st_free(c,at,count*8))return true;
    if(!sx_table(c,v1?&sx_st_qcow1_l1_entry:&sx_st_qcow_l1_entry,(int64_t)at,8,count))return false;
    /* Large tables retain all L1 physical entries. Follow at most 8192 L2
     * pointers so an adversarial sparse image cannot monopolize traversal. */
    for(uint64_t j=0;j<count&&j<8192;j++) {
        uint64_t entry;if(!sx_u64(c,(int64_t)(at+j*8),true,&entry))return false;
        uint64_t p=v1?entry:(entry&UINT64_C(0x00fffffffffffe00));
        uint64_t bytes=v1?l2bytes:(UINT64_C(1)<<bits);
        if(!p||!sx_st_free(c,p,bytes))continue;
        if(!sx_table(c,v1?&sx_st_qcow1_l2_entry:extended?&sx_st_qcow_l2_extended:&sx_st_qcow_l2_entry,(int64_t)p,extended?16:8,bytes/(extended?16:8)))return false;
    }
    return true;
}
static bool sx_st_qcow(sx_context *c,bool v1)
{
    uint8_t h[104];uint32_t version,bits,l2bits,l1count=0;uint64_t l1,size,cluster;bool extended=false;
    if(!sx_read(c,0,h,v1?48:72))return false;version=xx_data_get_u32(h,104,4,true);size=xx_data_get_u64(h,104,24,true);
    if(v1) {
        bits=h[32];l2bits=h[33];l1=xx_data_get_u64(h,104,40,true);
        if(bits<9||bits>16||l2bits<6||l2bits>13||!sx_add(c,&sx_st_qcow1_header,0,48))return false;
        uint64_t per=UINT64_C(1)<<(bits+l2bits),count=size/per+(size%per!=0);
        return sx_st_qcow_l1(c,l1,count,bits,l2bits,true,false);
    }
    bits=xx_data_get_u32(h,104,20,true);if(bits<9||bits>21)return false;cluster=UINT64_C(1)<<bits;
    l1count=xx_data_get_u32(h,104,36,true);l1=xx_data_get_u64(h,104,40,true);
    uint64_t header=72,backing=xx_data_get_u64(h,104,8,true),ext_end=backing?backing:cluster;
    if(version==3) {
        if(!sx_read(c,0,h,104)||!sx_add(c,&sx_st_qcow3_header,0,104))return false;
        header=xx_data_get_u32(h,104,100,true);extended=(xx_data_get_u64(h,104,72,true)&16)!=0;
        if(header<104||header>cluster)return false;
        if(header>104&&sx_st_fits(c,104,1)&&!sx_add(c,&sx_st_qcow_compression,104,1))return false;
    } else if(version!=2||!sx_add(c,&sx_st_qcow2_header,0,72))return false;
    /* Extensions are framed only within the first cluster before any backing
     * name. Unknown extension payloads and future header bytes remain raw. */
    if(ext_end<=cluster&&ext_end<=(uint64_t)c->size&&header<=ext_end)for(unsigned i=0;i<4096&&ext_end-header>=8;i++) {
        uint32_t type,n;if(!sx_u32(c,(int64_t)header,true,&type)||!sx_u32(c,(int64_t)header+4,true,&n))return false;
        if((uint64_t)n>ext_end-header-8)break;
        if(!sx_add(c,&sx_st_qcow_extension,(int64_t)header,8))return false;header+=8;
        if(!type)break;
        if(type==0x0537be77U&&n==16) {
            uint64_t off,len;uint8_t magic[8];
            if(!sx_add(c,&sx_st_qcow_crypto_extension,(int64_t)header,16)||!sx_u64(c,(int64_t)header,true,&off)||!sx_u64(c,(int64_t)header+8,true,&len))return false;
            if(len>=592&&sx_st_fits(c,off,len)&&sx_st_free(c,off,592)) {
                if(!sx_read(c,(int64_t)off,magic,8))return false;
                if(!xx_rt_memcmp(magic,"LUKS\xba\xbe\0\1",8)&&(!sx_add(c,&sx_st_luks1_header,(int64_t)off,208)||!sx_table(c,&sx_st_luks1_keyslot,(int64_t)off+208,48,8)))return false;
            }
        }
        header+=n;if(header>UINT64_MAX-7)return false;header=(header+7)&~UINT64_C(7);
    }
    l2bits=bits-(extended?4:3);
    /* Reserve the refcount pointer array before L2 traversal to avoid aliasing
     * declared allocation metadata into another structure family. */
    uint64_t rc=xx_data_get_u64(h,104,48,true),rcc=xx_data_get_u32(h,104,56,true);
    if(rcc<=UINT64_MAX/cluster&&rcc*cluster<=UINT64_C(64)*1024*1024&&sx_st_free(c,rc,rcc*cluster)&&!sx_table(c,&sx_st_qcow_refcount_pointer,(int64_t)rc,8,rcc*cluster/8))return false;
    if(!sx_st_qcow_l1(c,l1,l1count,bits,l2bits,false,extended))return false;
    uint32_t count=xx_data_get_u32(h,104,60,true);uint64_t at=xx_data_get_u64(h,104,64,true);
    for(uint32_t j=0;j<count&&j<4096;j++) {
        uint8_t sh[40];uint64_t n;
        if(!sx_st_free(c,at,40))break;if(!sx_read(c,(int64_t)at,sh,40))return false;
        n=40+(uint64_t)xx_data_get_u32(sh,40,36,true)+xx_data_get_u16(sh,40,12,true)+xx_data_get_u16(sh,40,14,true);
        if(!sx_st_free(c,at,n))break;if(!sx_add(c,&sx_st_qcow_snapshot,(int64_t)at,40))return false;
        /* Snapshot variable extra-data and names are raw. Their own L1 tables
         * are followed with the same physical bounds as the active image. */
        if(!sx_st_qcow_l1(c,xx_data_get_u64(sh,40,0,true),xx_data_get_u32(sh,40,8,true),bits,l2bits,false,extended))return false;
        at+=n;if(at>UINT64_MAX-7)return false;at=(at+7)&~UINT64_C(7);
    }
    return true;
}
static bool sx_st_romfs_chain(sx_context *c,uint64_t at,unsigned depth)
{
    if(depth>=64)return true;
    while(at&&sx_st_free(c,at,16)) {
        uint8_t h[16];uint32_t next,spec;
        if(!sx_read(c,(int64_t)at,h,16)||!sx_add(c,&sx_st_romfs_inode,(int64_t)at,16))return false;
        next=xx_data_get_u32(h,16,0,true);spec=xx_data_get_u32(h,16,4,true);
        if((next&7)==1&&spec&&!sx_st_romfs_chain(c,spec,depth+1))return false;
        /* Hardlink destinations contain the same inode header; follow them too
         * because a valid hardlink may target a header outside directory chains. */
        if(!(next&7)&&spec&&!sx_st_romfs_chain(c,spec,depth+1))return false;
        at=next&~UINT32_C(15);
    }
    return true;
}
static bool sx_st_romfs(sx_context *c)
{
    uint64_t at=16;uint8_t ch=1;unsigned count=0;
    if(!sx_add(c,&sx_st_romfs_superblock,0,16))return false;
    while(ch&&at<(uint64_t)c->size&&count++<4096)if(!sx_read(c,(int64_t)at++,&ch,1))return false;
    if(ch)return false;at=(at+15)&~UINT64_C(15);
    return sx_st_romfs_chain(c,at,0);
}
static bool sx_st_cramfs_inode_walk(sx_context *c,uint64_t at,bool be,unsigned depth,bool root)
{
    uint8_t h[12];uint32_t w0,w1,w2,mode,size,off;
    if(depth>=64||!sx_st_free(c,at,12))return true;
    if(!sx_read(c,(int64_t)at,h,12)||!sx_add(c,be?&sx_st_cramfs_inode_be:&sx_st_cramfs_inode_le,(int64_t)at,12))return false;
    w0=xx_data_get_u32(h,12,0,be);w1=xx_data_get_u32(h,12,4,be);w2=xx_data_get_u32(h,12,8,be);
    mode=be?w0>>16:w0&65535;size=be?w1>>8:w1&0xffffff;off=(be?w2&0x3ffffff:w2>>6)*4;
    if((mode&0xf000)==0x4000&&off&&sx_st_fits(c,off,size)) {
        uint64_t p=off,end=p+size;
        while(end-p>=12&&c->count<20000) {
            uint32_t word;unsigned name;
            if(!sx_u32(c,(int64_t)p+8,be,&word))return false;name=(be?word>>26:word&63)*4;
            if((uint64_t)name+12>end-p)break;
            if(!sx_st_cramfs_inode_walk(c,p,be,depth+1,false))return false;p+=12+name;
        }
    } else if((mode&0xf000)==0x8000&&off&&size) {
        uint64_t count=((uint64_t)size+4095)/4096;
        if(sx_st_free(c,off,count*4)&&!sx_table(c,be?&sx_st_cramfs_block_pointer_be:&sx_st_cramfs_block_pointer_le,off,4,count))return false;
    }
    (void)root;return true;
}
static bool sx_storage_build(sx_context *c)
{
    bool ok=false;
    if(!c||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;
    switch(c->f->file_type) {
    case XX_FILE_TYPE_MIDI:ok=sx_st_midi(c);break;
    case XX_FILE_TYPE_CAF:ok=sx_st_caf(c);break;
    case XX_FILE_TYPE_CREATIVE_VOC:ok=sx_st_voc(c);break;
    case XX_FILE_TYPE_SONY_VAG:{uint32_t n;ok=sx_add(c,&sx_st_vag_header,0,48)&&sx_u32(c,12,true,&n)&&sx_table(c,&sx_st_vag_adpcm_frame,48,16,n/16);break;}
    case XX_FILE_TYPE_SONY_PSF:ok=sx_add(c,&sx_st_psf_header,0,16);break;
    case XX_FILE_TYPE_AUDIO_DSF:ok=sx_add(c,&sx_st_dsf_header,0,28)&&sx_add(c,&sx_st_dsf_format,28,52)&&sx_add(c,&sx_st_dsf_data,80,12);break;
    case XX_FILE_TYPE_AUDIO_DFF:ok=sx_add(c,&sx_st_dff_form,0,16)&&sx_st_dff_chunks(c,16,(uint64_t)c->size,false);break;
    case XX_FILE_TYPE_AUDIO_WAVE64:ok=sx_st_wave64(c);break;
    case XX_FILE_TYPE_AUDIO_ADX:{uint8_t h[20];uint64_t header,frames,end;ok=sx_read(c,0,h,20)&&sx_add(c,&sx_st_adx_header,0,20);if(!ok)break;header=4+(uint64_t)xx_data_get_u16(h,20,2,true);frames=((uint64_t)xx_data_get_u32(h,20,12,true)+31)/32*h[7];end=header+frames*18;if(sx_st_fits(c,end,18)){uint16_t magic;ok=sx_u16(c,(int64_t)end,true,&magic);if(ok&&magic==0x8001)ok=sx_add(c,&sx_st_adx_terminator,(int64_t)end,18);}break;}
    case XX_FILE_TYPE_AUDIO_WAVPACK:ok=sx_st_wavpack(c);break;
    case XX_FILE_TYPE_IVF:ok=sx_st_ivf(c);break;
    case XX_FILE_TYPE_IDTECH_ROQ:ok=sx_st_roq(c);break;
    case XX_FILE_TYPE_FLASH_VIDEO_FLV:ok=sx_st_flv(c);break;
    case XX_FILE_TYPE_RAD_BINK:ok=sx_st_bink(c);break;
    case XX_FILE_TYPE_RAD_SMACKER:ok=sx_st_smacker(c);break;
    case XX_FILE_TYPE_AUTODESK_FLIC:ok=sx_st_flic(c);break;
    case XX_FILE_TYPE_QCOW:ok=sx_st_qcow(c,false);break;
    case XX_FILE_TYPE_QCOW1:ok=sx_st_qcow(c,true);break;
    case XX_FILE_TYPE_LUKS:ok=sx_st_luks(c);break;
    case XX_FILE_TYPE_ROMFS:ok=sx_st_romfs(c);break;
    case XX_FILE_TYPE_CRAMFS:{uint32_t magic;ok=sx_u32(c,0,false,&magic);if(ok){bool be=magic!=0x28cd3d45U;ok=sx_add(c,be?&sx_st_cramfs_superblock_be:&sx_st_cramfs_superblock_le,0,64)&&sx_st_cramfs_inode_walk(c,64,be,0,true);}break;}
    default:break;
    }
    return ok&&sx_st_finish(c);
}
static bool sx_storage_comment(xx_data_struct_record *r,uint32_t id)
{
    if(id<0x60080000U||id>=0x60090000U||!r->name)return true;
    const wchar_t *n=r->name,*text=NULL;
    if(!xx_rt_wcscmp(n,L"sample_rate"))text=L"Samples per second (Hz)";
    else if(!xx_rt_wcscmp(n,L"bits_per_sample")||!xx_rt_wcscmp(n,L"sample_bits")||!xx_rt_wcscmp(n,L"bits_per_channel")||!xx_rt_wcscmp(n,L"depth"))text=L"Bits per sample or pixel; not a byte count";
    else if(!xx_rt_wcscmp(n,L"average_bytes_per_second"))text=L"Byte rate in bytes per second";
    else if(!xx_rt_wcscmp(n,L"cluster_bits"))text=L"Encoded exponent: cluster bytes = 1 << cluster_bits";
    else if(!xx_rt_wcscmp(n,L"l2_bits"))text=L"Encoded exponent: L2 entry count = 1 << l2_bits";
    else if(!xx_rt_wcscmp(n,L"refcount_order"))text=L"Encoded exponent: bits per reference count = 1 << refcount_order";
    else if(!xx_rt_wcscmp(n,L"payload_sector")||!xx_rt_wcscmp(n,L"key_material_sector"))text=L"Offset in 512-byte sectors relative to the volume";
    else if(!xx_rt_wcscmp(n,L"word_count"))text=L"Encoded payload length in two-byte words, including odd-byte padding";
    else if(!xx_rt_wcscmp(n,L"four_byte_units"))text=L"Palette packet length in four-byte units, including this byte";
    else if(!xx_rt_wcscmp(n,L"time_constant"))text=L"Encoded rate: samples per second = 1000000 / (256 - value)";
    else if(!xx_rt_wcscmp(n,L"division"))text=L"Bit 15 clear: ticks per quarter note; set: signed SMPTE frame rate and ticks per frame";
    else if(!xx_rt_wcscmp(n,L"predictor_and_shift"))text=L"High nibble: ADPCM predictor; low nibble: sample shift";
    else if(!xx_rt_wcscmp(n,L"timestamp_low24"))text=L"Low 24 bits of millisecond timestamp; combine with timestamp_high8";
    else if(!xx_rt_wcscmp(n,L"timestamp_high8"))text=L"High 8 bits of millisecond timestamp";
    else if(!xx_rt_wcscmp(n,L"composition_time"))text=L"Signed composition-time offset in milliseconds";
    else if(!xx_rt_wcscmp(n,L"offset_and_keyframe_flag"))text=L"Physical byte offset in bits 1..31; bit 0 is the keyframe flag";
    else if(!xx_rt_wcscmp(n,L"size_and_flags"))text=L"Frame byte length in bits 2..31; low two bits are flags";
    else if(!xx_rt_wcscmp(n,L"next_offset_and_type"))text=L"Next inode byte offset in bits 4..31; bit 3 executable, bits 0..2 inode type";
    else if(!xx_rt_wcscmp(n,L"spec_info"))text=L"Type-dependent: directory child, hardlink target, device number, or zero";
    else if(!xx_rt_wcscmp(n,L"mode_uid"))text=id==sx_st_cramfs_inode_be.id?L"High 16 bits: mode; low 16 bits: UID":L"Low 16 bits: mode; high 16 bits: UID";
    else if(!xx_rt_wcscmp(n,L"size_gid"))text=id==sx_st_cramfs_inode_be.id?L"High 24 bits: byte size; low 8 bits: GID":L"Low 24 bits: byte size; high 8 bits: GID";
    else if(!xx_rt_wcscmp(n,L"name_length_and_offset"))text=id==sx_st_cramfs_inode_be.id?L"High 6 bits: name length in four-byte units; low 26 bits: offset in four-byte units":L"Low 6 bits: name length in four-byte units; high 26 bits: offset in four-byte units";
    else if(!xx_rt_wcscmp(n,L"end_offset_and_flags"))text=L"Block end offset; high two flag bits apply only with extended block pointers";
    else if(!xx_rt_wcscmp(n,L"speed_jiffies"))text=L"Delay in units of 1/70 second";
    else if(!xx_rt_wcscmp(n,L"speed_milliseconds")||!xx_rt_wcscmp(n,L"delay"))text=L"Delay in milliseconds";
    else if(!xx_rt_wcscmp(n,L"frame_duration"))text=L"Positive: milliseconds; negative: absolute value in 1/100000 second units";
    else if(!xx_rt_wcscmp(n,L"data_offset_minus_four"))text=L"Audio starts at this encoded offset plus four bytes";
    else if(!xx_rt_wcscmp(n,L"size_marker"))text=L"RoQ sentinel 0xFFFFFFFF; not a byte count";
    else if(!xx_rt_wcscmp(n,L"timestamp")&&id==sx_st_ivf_frame.id)text=L"Timestamp in IVF time-base ticks (denominator / numerator seconds)";
    else if(!xx_rt_wcscmp(n,L"size")&&id==sx_st_caf_chunk.id)text=L"Signed payload byte length; -1 means data extends to end of file";
    return !text||xx_data_struct_record_set_comment(r,text);
}
