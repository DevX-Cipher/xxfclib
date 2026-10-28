/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical tracker metadata selected from validated native component records.
 * Field layouts follow the corresponding native parsers and cited primary
 * tracker specifications; encoded payloads remain explicitly RAW_DATA. */
static const xx_data_struct_field_desc sxt_tracker_order_u8_fields[] = {
    SX_FIELD("pattern", "uint8", 0, 1, SX_NONE),
};
static const sx_layout sxt_tracker_order_u8 = {UINT32_C(0x600E0001),"tracker_order_u8",sxt_tracker_order_u8_fields,SX_COUNT(sxt_tracker_order_u8_fields),SX_LE};

static const xx_data_struct_field_desc sxt_tracker_order_u16be_fields[] = {
    SX_FIELD("pattern", "uint16", 0, 2, SX_NONE),
};
static const sx_layout sxt_tracker_order_u16be = {UINT32_C(0x600E0002),"tracker_order_u16be",sxt_tracker_order_u16be_fields,SX_COUNT(sxt_tracker_order_u16be_fields),SX_BE};

static const xx_data_struct_field_desc sxt_tracker_track_index_fields[] = {
    SX_FIELD("track", "uint16", 0, 2, SX_NONE),
};
static const sx_layout sxt_tracker_track_index = {UINT32_C(0x600E0003),"tracker_track_index",sxt_tracker_track_index_fields,SX_COUNT(sxt_tracker_track_index_fields),SX_LE};

static const xx_data_struct_field_desc sxt_tracker_offset_u32le_fields[] = {
    SX_FIELD("offset", "uint32", 0, 4, SX_OFFSET),
};
static const sx_layout sxt_tracker_offset_u32le = {UINT32_C(0x600E0004),"tracker_offset_u32le",sxt_tracker_offset_u32le_fields,SX_COUNT(sxt_tracker_offset_u32le_fields),SX_LE};

static const xx_data_struct_field_desc sxt_tracker_offset_u32be_fields[] = {
    SX_FIELD("offset", "uint32", 0, 4, SX_OFFSET),
};
static const sx_layout sxt_tracker_offset_u32be = {UINT32_C(0x600E0005),"tracker_offset_u32be",sxt_tracker_offset_u32be_fields,SX_COUNT(sxt_tracker_offset_u32be_fields),SX_BE};

static const xx_data_struct_field_desc sxt_tracker_paragraph_fields[] = {
    SX_FIELD("paragraph", "uint16", 0, 2, SX_NONE),
};
static const sx_layout sxt_tracker_paragraph = {UINT32_C(0x600E0006),"tracker_paragraph",sxt_tracker_paragraph_fields,SX_COUNT(sxt_tracker_paragraph_fields),SX_LE};

static const xx_data_struct_field_desc sxt_tracker_length_u32be_fields[] = {
    SX_FIELD("length", "uint32", 0, 4, SX_SIZE),
};
static const sx_layout sxt_tracker_length_u32be = {UINT32_C(0x600E0007),"tracker_length_u32be",sxt_tracker_length_u32be_fields,SX_COUNT(sxt_tracker_length_u32be_fields),SX_BE};

static const xx_data_struct_field_desc sxt_tracker_loop_start_u32be_fields[] = {
    SX_FIELD("loop_start", "uint32", 0, 4, SX_OFFSET),
};
static const sx_layout sxt_tracker_loop_start_u32be = {UINT32_C(0x600E0008),"tracker_loop_start_u32be",sxt_tracker_loop_start_u32be_fields,SX_COUNT(sxt_tracker_loop_start_u32be_fields),SX_BE};

static const xx_data_struct_field_desc sxt_tracker_loop_length_u32be_fields[] = {
    SX_FIELD("loop_length", "uint32", 0, 4, SX_SIZE),
};
static const sx_layout sxt_tracker_loop_length_u32be = {UINT32_C(0x600E0009),"tracker_loop_length_u32be",sxt_tracker_loop_length_u32be_fields,SX_COUNT(sxt_tracker_loop_length_u32be_fields),SX_BE};

static const xx_data_struct_field_desc sxt_tracker_volume_fields[] = {
    SX_FIELD("volume", "uint8", 0, 1, SX_NONE),
};
static const sx_layout sxt_tracker_volume = {UINT32_C(0x600E000A),"tracker_volume",sxt_tracker_volume_fields,SX_COUNT(sxt_tracker_volume_fields),SX_LE};

static const xx_data_struct_field_desc sxt_tracker_finetune_fields[] = {
    SX_FIELD("finetune", "int8", 0, 1, SX_NONE),
};
static const sx_layout sxt_tracker_finetune = {UINT32_C(0x600E000B),"tracker_finetune",sxt_tracker_finetune_fields,SX_COUNT(sxt_tracker_finetune_fields),SX_LE};

static const xx_data_struct_field_desc sxt_tracker_pan4_fields[] = {
    SX_FIELD("panning", "uint8", 0, 1, SX_NONE),
};
static const sx_layout sxt_tracker_pan4 = {UINT32_C(0x600E000C),"tracker_pan4",sxt_tracker_pan4_fields,SX_COUNT(sxt_tracker_pan4_fields),SX_LE};

static const xx_data_struct_field_desc sxt_tracker_count_u8_fields[] = {
    SX_FIELD("count", "uint8", 0, 1, SX_COUNT_PROP),
};
static const sx_layout sxt_tracker_count_u8 = {UINT32_C(0x600E000D),"tracker_count_u8",sxt_tracker_count_u8_fields,SX_COUNT(sxt_tracker_count_u8_fields),SX_LE};

static const xx_data_struct_field_desc sxt_tracker_count_u16le_fields[] = {
    SX_FIELD("count", "uint16", 0, 2, SX_COUNT_PROP),
};
static const sx_layout sxt_tracker_count_u16le = {UINT32_C(0x600E000E),"tracker_count_u16le",sxt_tracker_count_u16le_fields,SX_COUNT(sxt_tracker_count_u16le_fields),SX_LE};

static const xx_data_struct_field_desc sxt_tracker_count_u16be_fields[] = {
    SX_FIELD("count", "uint16", 0, 2, SX_COUNT_PROP),
};
static const sx_layout sxt_tracker_count_u16be = {UINT32_C(0x600E000F),"tracker_count_u16be",sxt_tracker_count_u16be_fields,SX_COUNT(sxt_tracker_count_u16be_fields),SX_BE};

static const xx_data_struct_field_desc sxt_tracker_length_u16le_fields[] = {
    SX_FIELD("length", "uint16", 0, 2, SX_SIZE),
};
static const sx_layout sxt_tracker_length_u16le = {UINT32_C(0x600E0010),"tracker_length_u16le",sxt_tracker_length_u16le_fields,SX_COUNT(sxt_tracker_length_u16le_fields),SX_LE};

static const xx_data_struct_field_desc sxt_tracker_chunk_be_fields[] = {
    SX_FIELD("tag", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("size", "uint32", 4, 4, SX_SIZE),
};
static const sx_layout sxt_tracker_chunk_be = {UINT32_C(0x600E0011),"tracker_chunk_be",sxt_tracker_chunk_be_fields,SX_COUNT(sxt_tracker_chunk_be_fields),SX_BE};

static const xx_data_struct_field_desc sxt_tracker_title20_fields[] = {
    SX_FIELD("title", "char[20]", 0, 20, SX_STRING),
};
static const sx_layout sxt_tracker_title20 = {UINT32_C(0x600E0012),"tracker_title20",sxt_tracker_title20_fields,SX_COUNT(sxt_tracker_title20_fields),SX_LE};

static const xx_data_struct_field_desc sxt_tracker_title30_fields[] = {
    SX_FIELD("title", "char[30]", 0, 30, SX_STRING),
};
static const sx_layout sxt_tracker_title30 = {UINT32_C(0x600E0013),"tracker_title30",sxt_tracker_title30_fields,SX_COUNT(sxt_tracker_title30_fields),SX_LE};

static const xx_data_struct_field_desc sxt_tracker_title32_fields[] = {
    SX_FIELD("title", "char[32]", 0, 32, SX_STRING),
};
static const sx_layout sxt_tracker_title32 = {UINT32_C(0x600E0014),"tracker_title32",sxt_tracker_title32_fields,SX_COUNT(sxt_tracker_title32_fields),SX_LE};

static const xx_data_struct_field_desc sxt_tracker_title44_fields[] = {
    SX_FIELD("title", "char[44]", 0, 44, SX_STRING),
};
static const sx_layout sxt_tracker_title44 = {UINT32_C(0x600E0015),"tracker_title44",sxt_tracker_title44_fields,SX_COUNT(sxt_tracker_title44_fields),SX_LE};

static const xx_data_struct_field_desc sxt_mod_sample_fields[] = {
    SX_FIELD("name", "char[22]", 0, 22, SX_STRING),
    SX_FIELD("length_words", "uint16", 22, 2, SX_NONE),
    SX_FIELD("finetune_nibble", "uint8", 24, 1, SX_NONE),
    SX_FIELD("volume", "uint8", 25, 1, SX_NONE),
    SX_FIELD("loop_start_words", "uint16", 26, 2, SX_NONE),
    SX_FIELD("loop_length_words", "uint16", 28, 2, SX_NONE),
};
static const sx_layout sxt_mod_sample = {UINT32_C(0x600E0016),"mod_sample",sxt_mod_sample_fields,SX_COUNT(sxt_mod_sample_fields),SX_BE};

static const xx_data_struct_field_desc sxt_mod_orders_fields[] = {
    SX_FIELD("order_count", "uint8", 0, 1, SX_COUNT_PROP),
    SX_FIELD("restart", "uint8", 1, 1, SX_NONE),
    SX_FIELD("orders", "uint8[128]", 2, 128, SX_NONE),
};
static const sx_layout sxt_mod_orders = {UINT32_C(0x600E0017),"mod_orders",sxt_mod_orders_fields,SX_COUNT(sxt_mod_orders_fields),SX_LE};

static const xx_data_struct_field_desc sxt_mod_signature_fields[] = {
    SX_FIELD("signature", "char[4]", 0, 4, SX_SIGNATURE),
};
static const sx_layout sxt_mod_signature = {UINT32_C(0x600E0018),"mod_signature",sxt_mod_signature_fields,SX_COUNT(sxt_mod_signature_fields),SX_LE};

static const xx_data_struct_field_desc sxt_mod_event_fields[] = {
    SX_FIELD("sample_high_period_high", "uint8", 0, 1, SX_FLAGS),
    SX_FIELD("period_low", "uint8", 1, 1, SX_NONE),
    SX_FIELD("sample_low_effect", "uint8", 2, 1, SX_FLAGS),
    SX_FIELD("effect_parameter", "uint8", 3, 1, SX_NONE),
};
static const sx_layout sxt_mod_event = {UINT32_C(0x600E0019),"mod_event",sxt_mod_event_fields,SX_COUNT(sxt_mod_event_fields),SX_BE};

static const xx_data_struct_field_desc sxt_xm_header_fields[] = {
    SX_FIELD("signature", "char[17]", 0, 17, SX_SIGNATURE),
    SX_FIELD("title", "char[20]", 17, 20, SX_STRING),
    SX_FIELD("marker", "uint8", 37, 1, SX_SIGNATURE),
    SX_FIELD("tracker", "char[20]", 38, 20, SX_STRING),
    SX_FIELD("version", "uint16", 58, 2, SX_ID),
    SX_FIELD("header_size", "uint32", 60, 4, SX_SIZE),
    SX_FIELD("order_count", "uint16", 64, 2, SX_COUNT_PROP),
    SX_FIELD("restart", "uint16", 66, 2, SX_NONE),
    SX_FIELD("channel_count", "uint16", 68, 2, SX_COUNT_PROP),
    SX_FIELD("pattern_count", "uint16", 70, 2, SX_COUNT_PROP),
    SX_FIELD("instrument_count", "uint16", 72, 2, SX_COUNT_PROP),
    SX_FIELD("frequency_flags", "uint16", 74, 2, SX_FLAGS),
    SX_FIELD("speed", "uint16", 76, 2, SX_NONE),
    SX_FIELD("bpm", "uint16", 78, 2, SX_NONE),
};
static const sx_layout sxt_xm_header = {UINT32_C(0x600E001A),"xm_header",sxt_xm_header_fields,SX_COUNT(sxt_xm_header_fields),SX_LE};

static const xx_data_struct_field_desc sxt_xm_pattern_header_fields[] = {
    SX_FIELD("header_size", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("packing_type", "uint8", 4, 1, SX_ID),
    SX_FIELD("row_count", "uint16", 5, 2, SX_COUNT_PROP),
    SX_FIELD("packed_size", "uint16", 7, 2, SX_SIZE),
};
static const sx_layout sxt_xm_pattern_header = {UINT32_C(0x600E001B),"xm_pattern_header",sxt_xm_pattern_header_fields,SX_COUNT(sxt_xm_pattern_header_fields),SX_LE};

static const xx_data_struct_field_desc sxt_xm_instrument_header_fields[] = {
    SX_FIELD("header_size", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("name", "char[22]", 4, 22, SX_STRING),
    SX_FIELD("instrument_type", "uint8", 26, 1, SX_ID),
    SX_FIELD("sample_count", "uint16", 27, 2, SX_COUNT_PROP),
};
static const sx_layout sxt_xm_instrument_header = {UINT32_C(0x600E001C),"xm_instrument_header",sxt_xm_instrument_header_fields,SX_COUNT(sxt_xm_instrument_header_fields),SX_LE};

static const xx_data_struct_field_desc sxt_xm_instrument_sampled_header_fields[] = {
    SX_FIELD("header_size", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("name", "char[22]", 4, 22, SX_STRING),
    SX_FIELD("instrument_type", "uint8", 26, 1, SX_ID),
    SX_FIELD("sample_count", "uint16", 27, 2, SX_COUNT_PROP),
    SX_FIELD("sample_header_size", "uint32", 29, 4, SX_SIZE),
};
static const sx_layout sxt_xm_instrument_sampled_header = {UINT32_C(0x600E001D),"xm_instrument_sampled_header",sxt_xm_instrument_sampled_header_fields,SX_COUNT(sxt_xm_instrument_sampled_header_fields),SX_LE};

static const xx_data_struct_field_desc sxt_xm_keymap_fields[] = {
    SX_FIELD("sample_for_note", "uint8[96]", 0, 96, SX_NONE),
};
static const sx_layout sxt_xm_keymap = {UINT32_C(0x600E001E),"xm_keymap",sxt_xm_keymap_fields,SX_COUNT(sxt_xm_keymap_fields),SX_LE};

static const xx_data_struct_field_desc sxt_tracker_envelope_point_fields[] = {
    SX_FIELD("position", "uint16", 0, 2, SX_NONE),
    SX_FIELD("value", "uint16", 2, 2, SX_NONE),
};
static const sx_layout sxt_tracker_envelope_point = {UINT32_C(0x600E001F),"tracker_envelope_point",sxt_tracker_envelope_point_fields,SX_COUNT(sxt_tracker_envelope_point_fields),SX_LE};

static const xx_data_struct_field_desc sxt_xm_envelope_control_fields[] = {
    SX_FIELD("volume_point_count", "uint8", 0, 1, SX_COUNT_PROP),
    SX_FIELD("panning_point_count", "uint8", 1, 1, SX_COUNT_PROP),
    SX_FIELD("volume_sustain", "uint8", 2, 1, SX_NONE),
    SX_FIELD("volume_loop_start", "uint8", 3, 1, SX_NONE),
    SX_FIELD("volume_loop_end", "uint8", 4, 1, SX_NONE),
    SX_FIELD("panning_sustain", "uint8", 5, 1, SX_NONE),
    SX_FIELD("panning_loop_start", "uint8", 6, 1, SX_NONE),
    SX_FIELD("panning_loop_end", "uint8", 7, 1, SX_NONE),
    SX_FIELD("volume_flags", "uint8", 8, 1, SX_FLAGS),
    SX_FIELD("panning_flags", "uint8", 9, 1, SX_FLAGS),
    SX_FIELD("vibrato_type", "uint8", 10, 1, SX_ID),
    SX_FIELD("vibrato_sweep", "uint8", 11, 1, SX_NONE),
    SX_FIELD("vibrato_depth", "uint8", 12, 1, SX_NONE),
    SX_FIELD("vibrato_rate", "uint8", 13, 1, SX_NONE),
    SX_FIELD("volume_fadeout", "uint16", 14, 2, SX_NONE),
    SX_FIELD("reserved", "bytes", 16, 22, SX_RESERVED),
};
static const sx_layout sxt_xm_envelope_control = {UINT32_C(0x600E0020),"xm_envelope_control",sxt_xm_envelope_control_fields,SX_COUNT(sxt_xm_envelope_control_fields),SX_LE};

static const xx_data_struct_field_desc sxt_xm_sample_fields[] = {
    SX_FIELD("length", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("loop_start", "uint32", 4, 4, SX_OFFSET),
    SX_FIELD("loop_length", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("volume", "uint8", 12, 1, SX_NONE),
    SX_FIELD("finetune", "int8", 13, 1, SX_NONE),
    SX_FIELD("flags", "uint8", 14, 1, SX_FLAGS),
    SX_FIELD("panning", "uint8", 15, 1, SX_NONE),
    SX_FIELD("relative_note", "int8", 16, 1, SX_NONE),
    SX_FIELD("reserved", "uint8", 17, 1, SX_RESERVED),
    SX_FIELD("name", "char[22]", 18, 22, SX_STRING),
};
static const sx_layout sxt_xm_sample = {UINT32_C(0x600E0021),"xm_sample",sxt_xm_sample_fields,SX_COUNT(sxt_xm_sample_fields),SX_LE};

static const xx_data_struct_field_desc sxt_s3m_header_fields[] = {
    SX_FIELD("title", "char[28]", 0, 28, SX_STRING),
    SX_FIELD("marker", "uint8", 28, 1, SX_SIGNATURE),
    SX_FIELD("file_type", "uint8", 29, 1, SX_ID),
    SX_FIELD("reserved0", "uint16", 30, 2, SX_RESERVED),
    SX_FIELD("order_count", "uint16", 32, 2, SX_COUNT_PROP),
    SX_FIELD("sample_count", "uint16", 34, 2, SX_COUNT_PROP),
    SX_FIELD("pattern_count", "uint16", 36, 2, SX_COUNT_PROP),
    SX_FIELD("flags", "uint16", 38, 2, SX_FLAGS),
    SX_FIELD("tracker_version", "uint16", 40, 2, SX_ID),
    SX_FIELD("sample_format", "uint16", 42, 2, SX_ID),
    SX_FIELD("signature", "char[4]", 44, 4, SX_SIGNATURE),
    SX_FIELD("global_volume", "uint8", 48, 1, SX_NONE),
    SX_FIELD("speed", "uint8", 49, 1, SX_NONE),
    SX_FIELD("bpm", "uint8", 50, 1, SX_NONE),
    SX_FIELD("master_volume", "uint8", 51, 1, SX_FLAGS),
    SX_FIELD("ultraclick", "uint8", 52, 1, SX_NONE),
    SX_FIELD("default_panning", "uint8", 53, 1, SX_ID),
    SX_FIELD("reserved1", "bytes", 54, 8, SX_RESERVED),
    SX_FIELD("special", "uint16", 62, 2, SX_NONE),
};
static const sx_layout sxt_s3m_header = {UINT32_C(0x600E0022),"s3m_header",sxt_s3m_header_fields,SX_COUNT(sxt_s3m_header_fields),SX_LE};

static const xx_data_struct_field_desc sxt_s3m_channel_fields[] = {
    SX_FIELD("channel", "uint8", 0, 1, SX_FLAGS),
};
static const sx_layout sxt_s3m_channel = {UINT32_C(0x600E0023),"s3m_channel",sxt_s3m_channel_fields,SX_COUNT(sxt_s3m_channel_fields),SX_LE};

static const xx_data_struct_field_desc sxt_s3m_panning_fields[] = {
    SX_FIELD("panning", "uint8", 0, 1, SX_FLAGS),
};
static const sx_layout sxt_s3m_panning = {UINT32_C(0x600E0024),"s3m_panning",sxt_s3m_panning_fields,SX_COUNT(sxt_s3m_panning_fields),SX_LE};

static const xx_data_struct_field_desc sxt_s3m_sample_fields[] = {
    SX_FIELD("sample_type", "uint8", 0, 1, SX_ID),
    SX_FIELD("filename", "char[12]", 1, 12, SX_STRING),
    SX_FIELD("data_paragraph_high", "uint8", 13, 1, SX_NONE),
    SX_FIELD("data_paragraph_low", "uint16", 14, 2, SX_NONE),
    SX_FIELD("length_frames", "uint32", 16, 4, SX_COUNT_PROP),
    SX_FIELD("loop_start_frames", "uint32", 20, 4, SX_NONE),
    SX_FIELD("loop_end_frames", "uint32", 24, 4, SX_NONE),
    SX_FIELD("volume", "uint8", 28, 1, SX_NONE),
    SX_FIELD("reserved0", "uint8", 29, 1, SX_RESERVED),
    SX_FIELD("packing", "uint8", 30, 1, SX_ID),
    SX_FIELD("flags", "uint8", 31, 1, SX_FLAGS),
    SX_FIELD("c2_frequency", "uint32", 32, 4, SX_NONE),
    SX_FIELD("reserved1", "bytes", 36, 12, SX_RESERVED),
    SX_FIELD("name", "char[28]", 48, 28, SX_STRING),
    SX_FIELD("signature", "char[4]", 76, 4, SX_SIGNATURE),
};
static const sx_layout sxt_s3m_sample = {UINT32_C(0x600E0025),"s3m_sample",sxt_s3m_sample_fields,SX_COUNT(sxt_s3m_sample_fields),SX_LE};

static const xx_data_struct_field_desc sxt_it_header_fields[] = {
    SX_FIELD("signature", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("title", "char[26]", 4, 26, SX_STRING),
    SX_FIELD("highlight_minor", "uint8", 30, 1, SX_NONE),
    SX_FIELD("highlight_major", "uint8", 31, 1, SX_NONE),
    SX_FIELD("order_count", "uint16", 32, 2, SX_COUNT_PROP),
    SX_FIELD("instrument_count", "uint16", 34, 2, SX_COUNT_PROP),
    SX_FIELD("sample_count", "uint16", 36, 2, SX_COUNT_PROP),
    SX_FIELD("pattern_count", "uint16", 38, 2, SX_COUNT_PROP),
    SX_FIELD("created_version", "uint16", 40, 2, SX_ID),
    SX_FIELD("compatible_version", "uint16", 42, 2, SX_ID),
    SX_FIELD("flags", "uint16", 44, 2, SX_FLAGS),
    SX_FIELD("special", "uint16", 46, 2, SX_FLAGS),
    SX_FIELD("global_volume", "uint8", 48, 1, SX_NONE),
    SX_FIELD("mix_volume", "uint8", 49, 1, SX_NONE),
    SX_FIELD("speed", "uint8", 50, 1, SX_NONE),
    SX_FIELD("bpm", "uint8", 51, 1, SX_NONE),
    SX_FIELD("pan_separation", "uint8", 52, 1, SX_NONE),
    SX_FIELD("pitch_wheel_depth", "uint8", 53, 1, SX_NONE),
    SX_FIELD("message_length", "uint16", 54, 2, SX_SIZE),
    SX_FIELD("message_offset", "uint32", 56, 4, SX_OFFSET),
    SX_FIELD("reserved", "uint32", 60, 4, SX_RESERVED),
};
static const sx_layout sxt_it_header = {UINT32_C(0x600E0026),"it_header",sxt_it_header_fields,SX_COUNT(sxt_it_header_fields),SX_LE};

static const xx_data_struct_field_desc sxt_it_channel_pan_fields[] = {
    SX_FIELD("panning", "uint8", 0, 1, SX_FLAGS),
};
static const sx_layout sxt_it_channel_pan = {UINT32_C(0x600E0027),"it_channel_pan",sxt_it_channel_pan_fields,SX_COUNT(sxt_it_channel_pan_fields),SX_LE};

static const xx_data_struct_field_desc sxt_it_sample_fields[] = {
    SX_FIELD("signature", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("filename", "char[12]", 4, 12, SX_STRING),
    SX_FIELD("reserved", "uint8", 16, 1, SX_RESERVED),
    SX_FIELD("global_volume", "uint8", 17, 1, SX_NONE),
    SX_FIELD("flags", "uint8", 18, 1, SX_FLAGS),
    SX_FIELD("default_volume", "uint8", 19, 1, SX_NONE),
    SX_FIELD("name", "char[26]", 20, 26, SX_STRING),
    SX_FIELD("conversion", "uint8", 46, 1, SX_FLAGS),
    SX_FIELD("default_pan", "uint8", 47, 1, SX_FLAGS),
    SX_FIELD("length_frames", "uint32", 48, 4, SX_COUNT_PROP),
    SX_FIELD("loop_start_frames", "uint32", 52, 4, SX_NONE),
    SX_FIELD("loop_end_frames", "uint32", 56, 4, SX_NONE),
    SX_FIELD("c5_frequency", "uint32", 60, 4, SX_NONE),
    SX_FIELD("sustain_start_frames", "uint32", 64, 4, SX_NONE),
    SX_FIELD("sustain_end_frames", "uint32", 68, 4, SX_NONE),
    SX_FIELD("sample_offset", "uint32", 72, 4, SX_OFFSET),
    SX_FIELD("vibrato_speed", "uint8", 76, 1, SX_NONE),
    SX_FIELD("vibrato_depth", "uint8", 77, 1, SX_NONE),
    SX_FIELD("vibrato_rate", "uint8", 78, 1, SX_NONE),
    SX_FIELD("vibrato_waveform", "uint8", 79, 1, SX_ID),
};
static const sx_layout sxt_it_sample = {UINT32_C(0x600E0028),"it_sample",sxt_it_sample_fields,SX_COUNT(sxt_it_sample_fields),SX_LE};

static const xx_data_struct_field_desc sxt_it_pattern_header_fields[] = {
    SX_FIELD("packed_size", "uint16", 0, 2, SX_SIZE),
    SX_FIELD("row_count", "uint16", 2, 2, SX_COUNT_PROP),
    SX_FIELD("reserved", "uint32", 4, 4, SX_RESERVED),
};
static const sx_layout sxt_it_pattern_header = {UINT32_C(0x600E0029),"it_pattern_header",sxt_it_pattern_header_fields,SX_COUNT(sxt_it_pattern_header_fields),SX_LE};

static const xx_data_struct_field_desc sxt_mtm_header_fields[] = {
    SX_FIELD("signature", "char[3]", 0, 3, SX_SIGNATURE),
    SX_FIELD("version", "uint8", 3, 1, SX_ID),
    SX_FIELD("title", "char[20]", 4, 20, SX_STRING),
    SX_FIELD("track_count", "uint16", 24, 2, SX_COUNT_PROP),
    SX_FIELD("last_pattern", "uint8", 26, 1, SX_NONE),
    SX_FIELD("last_order", "uint8", 27, 1, SX_NONE),
    SX_FIELD("comment_size", "uint16", 28, 2, SX_SIZE),
    SX_FIELD("sample_count", "uint8", 30, 1, SX_COUNT_PROP),
    SX_FIELD("attributes", "uint8", 31, 1, SX_FLAGS),
    SX_FIELD("rows_per_track", "uint8", 32, 1, SX_COUNT_PROP),
    SX_FIELD("channel_count", "uint8", 33, 1, SX_COUNT_PROP),
};
static const sx_layout sxt_mtm_header = {UINT32_C(0x600E002A),"mtm_header",sxt_mtm_header_fields,SX_COUNT(sxt_mtm_header_fields),SX_LE};

static const xx_data_struct_field_desc sxt_mtm_sample_fields[] = {
    SX_FIELD("name", "char[22]", 0, 22, SX_STRING),
    SX_FIELD("length", "uint32", 22, 4, SX_SIZE),
    SX_FIELD("loop_start", "uint32", 26, 4, SX_OFFSET),
    SX_FIELD("loop_end", "uint32", 30, 4, SX_OFFSET),
    SX_FIELD("finetune_nibble", "uint8", 34, 1, SX_NONE),
    SX_FIELD("volume", "uint8", 35, 1, SX_NONE),
    SX_FIELD("attributes", "uint8", 36, 1, SX_FLAGS),
};
static const sx_layout sxt_mtm_sample = {UINT32_C(0x600E002B),"mtm_sample",sxt_mtm_sample_fields,SX_COUNT(sxt_mtm_sample_fields),SX_LE};

static const xx_data_struct_field_desc sxt_mtm_event_fields[] = {
    SX_FIELD("note_instrument_high", "uint8", 0, 1, SX_FLAGS),
    SX_FIELD("instrument_low_effect", "uint8", 1, 1, SX_FLAGS),
    SX_FIELD("effect_parameter", "uint8", 2, 1, SX_NONE),
};
static const sx_layout sxt_mtm_event = {UINT32_C(0x600E002C),"mtm_event",sxt_mtm_event_fields,SX_COUNT(sxt_mtm_event_fields),SX_LE};

static const xx_data_struct_field_desc sxt_ult_header_fields[] = {
    SX_FIELD("signature", "char[15]", 0, 15, SX_SIGNATURE),
    SX_FIELD("title", "char[32]", 15, 32, SX_STRING),
    SX_FIELD("comment_line_count", "uint8", 47, 1, SX_COUNT_PROP),
};
static const sx_layout sxt_ult_header = {UINT32_C(0x600E002D),"ult_header",sxt_ult_header_fields,SX_COUNT(sxt_ult_header_fields),SX_LE};

static const xx_data_struct_field_desc sxt_ult_sample_fields[] = {
    SX_FIELD("name", "char[32]", 0, 32, SX_STRING),
    SX_FIELD("filename", "char[12]", 32, 12, SX_STRING),
    SX_FIELD("loop_start_frames", "uint32", 44, 4, SX_NONE),
    SX_FIELD("loop_end_frames", "uint32", 48, 4, SX_NONE),
    SX_FIELD("sample_start_frames", "uint32", 52, 4, SX_NONE),
    SX_FIELD("sample_end_frames", "uint32", 56, 4, SX_NONE),
    SX_FIELD("volume", "uint8", 60, 1, SX_NONE),
    SX_FIELD("flags", "uint8", 61, 1, SX_FLAGS),
    SX_FIELD("c2_frequency", "uint16", 62, 2, SX_NONE),
    SX_FIELD("finetune", "int16", 64, 2, SX_NONE),
};
static const sx_layout sxt_ult_sample = {UINT32_C(0x600E002E),"ult_sample",sxt_ult_sample_fields,SX_COUNT(sxt_ult_sample_fields),SX_LE};

static const xx_data_struct_field_desc sxt_ult_counts_fields[] = {
    SX_FIELD("channels_minus_one", "uint8", 0, 1, SX_NONE),
    SX_FIELD("patterns_minus_one", "uint8", 1, 1, SX_NONE),
};
static const sx_layout sxt_ult_counts = {UINT32_C(0x600E002F),"ult_counts",sxt_ult_counts_fields,SX_COUNT(sxt_ult_counts_fields),SX_LE};

static const xx_data_struct_field_desc sxt_okt_signature_fields[] = {
    SX_FIELD("signature", "char[8]", 0, 8, SX_SIGNATURE),
};
static const sx_layout sxt_okt_signature = {UINT32_C(0x600E0030),"okt_signature",sxt_okt_signature_fields,SX_COUNT(sxt_okt_signature_fields),SX_LE};

static const xx_data_struct_field_desc sxt_okt_channel_fields[] = {
    SX_FIELD("channel_mode", "uint16", 0, 2, SX_ID),
};
static const sx_layout sxt_okt_channel = {UINT32_C(0x600E0031),"okt_channel",sxt_okt_channel_fields,SX_COUNT(sxt_okt_channel_fields),SX_BE};

static const xx_data_struct_field_desc sxt_okt_sample_fields[] = {
    SX_FIELD("name", "char[20]", 0, 20, SX_STRING),
    SX_FIELD("length", "uint32", 20, 4, SX_SIZE),
    SX_FIELD("loop_start_words", "uint16", 24, 2, SX_NONE),
    SX_FIELD("loop_length_words", "uint16", 26, 2, SX_NONE),
    SX_FIELD("volume", "uint16", 28, 2, SX_NONE),
    SX_FIELD("sample_mode", "uint16", 30, 2, SX_ID),
};
static const sx_layout sxt_okt_sample = {UINT32_C(0x600E0032),"okt_sample",sxt_okt_sample_fields,SX_COUNT(sxt_okt_sample_fields),SX_BE};

static const xx_data_struct_field_desc sxt_okt_speed_fields[] = {
    SX_FIELD("speed", "uint16", 0, 2, SX_NONE),
};
static const sx_layout sxt_okt_speed = {UINT32_C(0x600E0033),"okt_speed",sxt_okt_speed_fields,SX_COUNT(sxt_okt_speed_fields),SX_BE};

static const xx_data_struct_field_desc sxt_okt_event_fields[] = {
    SX_FIELD("note", "uint8", 0, 1, SX_NONE),
    SX_FIELD("instrument", "uint8", 1, 1, SX_NONE),
    SX_FIELD("effect", "uint8", 2, 1, SX_ID),
    SX_FIELD("effect_parameter", "uint8", 3, 1, SX_NONE),
};
static const sx_layout sxt_okt_event = {UINT32_C(0x600E0034),"okt_event",sxt_okt_event_fields,SX_COUNT(sxt_okt_event_fields),SX_LE};

static const xx_data_struct_field_desc sxt_digi_header_fields[] = {
    SX_FIELD("signature", "char[20]", 0, 20, SX_SIGNATURE),
    SX_FIELD("version_string", "char[4]", 20, 4, SX_STRING),
    SX_FIELD("version", "uint8", 24, 1, SX_ID),
    SX_FIELD("channel_count", "uint8", 25, 1, SX_COUNT_PROP),
    SX_FIELD("packed_patterns", "uint8", 26, 1, SX_FLAGS),
    SX_FIELD("unknown", "bytes", 27, 19, SX_NONE),
    SX_FIELD("last_pattern", "uint8", 46, 1, SX_NONE),
    SX_FIELD("last_order", "uint8", 47, 1, SX_NONE),
};
static const sx_layout sxt_digi_header = {UINT32_C(0x600E0035),"digi_header",sxt_digi_header_fields,SX_COUNT(sxt_digi_header_fields),SX_LE};

static const xx_data_struct_field_desc sxt_digi_pattern_header_fields[] = {
    SX_FIELD("packed_size", "uint16", 0, 2, SX_SIZE),
    SX_FIELD("channel_masks", "uint8[64]", 2, 64, SX_FLAGS),
};
static const sx_layout sxt_digi_pattern_header = {UINT32_C(0x600E0036),"digi_pattern_header",sxt_digi_pattern_header_fields,SX_COUNT(sxt_digi_pattern_header_fields),SX_BE};

static const xx_data_struct_field_desc sxt_far_header_fields[] = {
    SX_FIELD("signature", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("title", "char[40]", 4, 40, SX_STRING),
    SX_FIELD("marker", "uint8[3]", 44, 3, SX_SIGNATURE),
    SX_FIELD("header_size", "uint16", 47, 2, SX_SIZE),
    SX_FIELD("version", "uint8", 49, 1, SX_ID),
    SX_FIELD("channel_enabled", "uint8[16]", 50, 16, SX_FLAGS),
    SX_FIELD("editor_state", "bytes", 66, 9, SX_NONE),
    SX_FIELD("tempo", "uint8", 75, 1, SX_NONE),
    SX_FIELD("channel_panning", "uint8[16]", 76, 16, SX_NONE),
    SX_FIELD("editor_grid_mode", "bytes", 92, 4, SX_NONE),
    SX_FIELD("comment_size", "uint16", 96, 2, SX_SIZE),
};
static const sx_layout sxt_far_header = {UINT32_C(0x600E0037),"far_header",sxt_far_header_fields,SX_COUNT(sxt_far_header_fields),SX_LE};

static const xx_data_struct_field_desc sxt_far_order_counts_fields[] = {
    SX_FIELD("stored_patterns", "uint8", 0, 1, SX_COUNT_PROP),
    SX_FIELD("order_count", "uint8", 1, 1, SX_COUNT_PROP),
    SX_FIELD("restart", "uint8", 2, 1, SX_NONE),
};
static const sx_layout sxt_far_order_counts = {UINT32_C(0x600E0038),"far_order_counts",sxt_far_order_counts_fields,SX_COUNT(sxt_far_order_counts_fields),SX_LE};

static const xx_data_struct_field_desc sxt_far_pattern_header_fields[] = {
    SX_FIELD("break_row", "uint8", 0, 1, SX_NONE),
    SX_FIELD("tempo", "uint8", 1, 1, SX_NONE),
};
static const sx_layout sxt_far_pattern_header = {UINT32_C(0x600E0039),"far_pattern_header",sxt_far_pattern_header_fields,SX_COUNT(sxt_far_pattern_header_fields),SX_LE};

static const xx_data_struct_field_desc sxt_far_sample_bitmap_fields[] = {
    SX_FIELD("sample_bitmap", "uint8[8]", 0, 8, SX_FLAGS),
};
static const sx_layout sxt_far_sample_bitmap = {UINT32_C(0x600E003A),"far_sample_bitmap",sxt_far_sample_bitmap_fields,SX_COUNT(sxt_far_sample_bitmap_fields),SX_LE};

static const xx_data_struct_field_desc sxt_far_sample_fields[] = {
    SX_FIELD("name", "char[32]", 0, 32, SX_STRING),
    SX_FIELD("length", "uint32", 32, 4, SX_SIZE),
    SX_FIELD("finetune", "uint8", 36, 1, SX_NONE),
    SX_FIELD("volume", "uint8", 37, 1, SX_NONE),
    SX_FIELD("loop_start", "uint32", 38, 4, SX_OFFSET),
    SX_FIELD("loop_end", "uint32", 42, 4, SX_OFFSET),
    SX_FIELD("sample_type", "uint8", 46, 1, SX_ID),
    SX_FIELD("loop_flags", "uint8", 47, 1, SX_FLAGS),
};
static const sx_layout sxt_far_sample = {UINT32_C(0x600E003B),"far_sample",sxt_far_sample_fields,SX_COUNT(sxt_far_sample_fields),SX_LE};

static const xx_data_struct_field_desc sxt_far_event_fields[] = {
    SX_FIELD("note", "uint8", 0, 1, SX_NONE),
    SX_FIELD("instrument", "uint8", 1, 1, SX_NONE),
    SX_FIELD("volume", "uint8", 2, 1, SX_NONE),
    SX_FIELD("effect", "uint8", 3, 1, SX_FLAGS),
};
static const sx_layout sxt_far_event = {UINT32_C(0x600E003C),"far_event",sxt_far_event_fields,SX_COUNT(sxt_far_event_fields),SX_LE};

static const xx_data_struct_field_desc sxt_gdm_header_fields[] = {
    SX_FIELD("signature", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("title", "char[32]", 4, 32, SX_STRING),
    SX_FIELD("author", "char[32]", 36, 32, SX_STRING),
    SX_FIELD("marker", "uint8[3]", 68, 3, SX_SIGNATURE),
    SX_FIELD("signature2", "char[4]", 71, 4, SX_SIGNATURE),
    SX_FIELD("major", "uint8", 75, 1, SX_ID),
    SX_FIELD("minor", "uint8", 76, 1, SX_ID),
    SX_FIELD("tracker_id", "uint16", 77, 2, SX_ID),
    SX_FIELD("tracker_major", "uint8", 79, 1, SX_ID),
    SX_FIELD("tracker_minor", "uint8", 80, 1, SX_ID),
    SX_FIELD("channel_panning", "uint8[32]", 81, 32, SX_NONE),
    SX_FIELD("global_volume", "uint8", 113, 1, SX_NONE),
    SX_FIELD("speed", "uint8", 114, 1, SX_NONE),
    SX_FIELD("bpm", "uint8", 115, 1, SX_NONE),
    SX_FIELD("original_format", "uint16", 116, 2, SX_ID),
    SX_FIELD("orders_offset", "uint32", 118, 4, SX_OFFSET),
    SX_FIELD("orders_minus_one", "uint8", 122, 1, SX_NONE),
    SX_FIELD("patterns_offset", "uint32", 123, 4, SX_OFFSET),
    SX_FIELD("patterns_minus_one", "uint8", 127, 1, SX_NONE),
    SX_FIELD("instruments_offset", "uint32", 128, 4, SX_OFFSET),
    SX_FIELD("samples_offset", "uint32", 132, 4, SX_OFFSET),
    SX_FIELD("samples_minus_one", "uint8", 136, 1, SX_NONE),
    SX_FIELD("unsupported_extension", "bytes", 137, 20, SX_NONE),
};
static const sx_layout sxt_gdm_header = {UINT32_C(0x600E003D),"gdm_header",sxt_gdm_header_fields,SX_COUNT(sxt_gdm_header_fields),SX_LE};

static const xx_data_struct_field_desc sxt_gdm_sample_fields[] = {
    SX_FIELD("name", "char[32]", 0, 32, SX_STRING),
    SX_FIELD("filename", "char[12]", 32, 12, SX_STRING),
    SX_FIELD("ems_handle", "uint8", 44, 1, SX_NONE),
    SX_FIELD("length", "uint32", 45, 4, SX_SIZE),
    SX_FIELD("loop_start_frames", "uint32", 49, 4, SX_NONE),
    SX_FIELD("loop_end_plus_one_frames", "uint32", 53, 4, SX_NONE),
    SX_FIELD("flags", "uint8", 57, 1, SX_FLAGS),
    SX_FIELD("c4_frequency", "uint16", 58, 2, SX_NONE),
    SX_FIELD("volume", "uint8", 60, 1, SX_NONE),
    SX_FIELD("panning", "uint8", 61, 1, SX_NONE),
};
static const sx_layout sxt_gdm_sample = {UINT32_C(0x600E003E),"gdm_sample",sxt_gdm_sample_fields,SX_COUNT(sxt_gdm_sample_fields),SX_LE};

static const xx_data_struct_field_desc sxt_dbm_header_fields[] = {
    SX_FIELD("signature", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("major", "uint8", 4, 1, SX_ID),
    SX_FIELD("minor", "uint8", 5, 1, SX_ID),
    SX_FIELD("reserved", "uint16", 6, 2, SX_RESERVED),
};
static const sx_layout sxt_dbm_header = {UINT32_C(0x600E003F),"dbm_header",sxt_dbm_header_fields,SX_COUNT(sxt_dbm_header_fields),SX_BE};

static const xx_data_struct_field_desc sxt_dbm_info_fields[] = {
    SX_FIELD("instrument_count", "uint16", 0, 2, SX_COUNT_PROP),
    SX_FIELD("sample_count", "uint16", 2, 2, SX_COUNT_PROP),
    SX_FIELD("song_count", "uint16", 4, 2, SX_COUNT_PROP),
    SX_FIELD("pattern_count", "uint16", 6, 2, SX_COUNT_PROP),
    SX_FIELD("channel_count", "uint16", 8, 2, SX_COUNT_PROP),
};
static const sx_layout sxt_dbm_info = {UINT32_C(0x600E0040),"dbm_info",sxt_dbm_info_fields,SX_COUNT(sxt_dbm_info_fields),SX_BE};

static const xx_data_struct_field_desc sxt_dbm_song_fields[] = {
    SX_FIELD("name", "char[44]", 0, 44, SX_STRING),
    SX_FIELD("order_count", "uint16", 44, 2, SX_COUNT_PROP),
};
static const sx_layout sxt_dbm_song = {UINT32_C(0x600E0041),"dbm_song",sxt_dbm_song_fields,SX_COUNT(sxt_dbm_song_fields),SX_BE};

static const xx_data_struct_field_desc sxt_dbm_instrument_fields[] = {
    SX_FIELD("name", "char[30]", 0, 30, SX_STRING),
    SX_FIELD("sample_number", "uint16", 30, 2, SX_NONE),
    SX_FIELD("volume", "uint16", 32, 2, SX_NONE),
    SX_FIELD("c3_frequency", "uint32", 34, 4, SX_NONE),
    SX_FIELD("loop_start_frames", "uint32", 38, 4, SX_NONE),
    SX_FIELD("loop_length_frames", "uint32", 42, 4, SX_NONE),
    SX_FIELD("panning", "int16", 46, 2, SX_NONE),
    SX_FIELD("flags", "uint16", 48, 2, SX_FLAGS),
};
static const sx_layout sxt_dbm_instrument = {UINT32_C(0x600E0042),"dbm_instrument",sxt_dbm_instrument_fields,SX_COUNT(sxt_dbm_instrument_fields),SX_BE};

static const xx_data_struct_field_desc sxt_dbm_pattern_header_fields[] = {
    SX_FIELD("row_count", "uint16", 0, 2, SX_COUNT_PROP),
    SX_FIELD("packed_size", "uint32", 2, 4, SX_SIZE),
};
static const sx_layout sxt_dbm_pattern_header = {UINT32_C(0x600E0043),"dbm_pattern_header",sxt_dbm_pattern_header_fields,SX_COUNT(sxt_dbm_pattern_header_fields),SX_BE};

static const xx_data_struct_field_desc sxt_dbm_sample_header_fields[] = {
    SX_FIELD("sample_format", "uint32", 0, 4, SX_FLAGS),
    SX_FIELD("frame_count", "uint32", 4, 4, SX_COUNT_PROP),
};
static const sx_layout sxt_dbm_sample_header = {UINT32_C(0x600E0044),"dbm_sample_header",sxt_dbm_sample_header_fields,SX_COUNT(sxt_dbm_sample_header_fields),SX_BE};

static const xx_data_struct_field_desc sxt_mdl_header_fields[] = {
    SX_FIELD("signature", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("version", "uint8", 4, 1, SX_ID),
};
static const sx_layout sxt_mdl_header = {UINT32_C(0x600E0045),"mdl_header",sxt_mdl_header_fields,SX_COUNT(sxt_mdl_header_fields),SX_LE};

static const xx_data_struct_field_desc sxt_mdl_chunk_fields[] = {
    SX_FIELD("tag", "char[2]", 0, 2, SX_SIGNATURE),
    SX_FIELD("size", "uint32", 2, 4, SX_SIZE),
};
static const sx_layout sxt_mdl_chunk = {UINT32_C(0x600E0046),"mdl_chunk",sxt_mdl_chunk_fields,SX_COUNT(sxt_mdl_chunk_fields),SX_LE};

static const xx_data_struct_field_desc sxt_mdl_info_fields[] = {
    SX_FIELD("title", "char[32]", 0, 32, SX_STRING),
    SX_FIELD("composer", "char[20]", 32, 20, SX_STRING),
    SX_FIELD("order_count", "uint16", 52, 2, SX_COUNT_PROP),
    SX_FIELD("restart", "uint16", 54, 2, SX_NONE),
    SX_FIELD("global_volume", "uint8", 56, 1, SX_NONE),
    SX_FIELD("speed", "uint8", 57, 1, SX_NONE),
    SX_FIELD("bpm", "uint8", 58, 1, SX_NONE),
    SX_FIELD("channel_panning", "uint8[32]", 59, 32, SX_FLAGS),
};
static const sx_layout sxt_mdl_info = {UINT32_C(0x600E0047),"mdl_info",sxt_mdl_info_fields,SX_COUNT(sxt_mdl_info_fields),SX_LE};

static const xx_data_struct_field_desc sxt_mdl_pattern_header_fields[] = {
    SX_FIELD("channel_count", "uint8", 0, 1, SX_COUNT_PROP),
    SX_FIELD("rows_minus_one", "uint8", 1, 1, SX_NONE),
    SX_FIELD("name", "char[16]", 2, 16, SX_STRING),
};
static const sx_layout sxt_mdl_pattern_header = {UINT32_C(0x600E0048),"mdl_pattern_header",sxt_mdl_pattern_header_fields,SX_COUNT(sxt_mdl_pattern_header_fields),SX_LE};

static const xx_data_struct_field_desc sxt_mdl_instrument_fields[] = {
    SX_FIELD("instrument_number", "uint8", 0, 1, SX_NONE),
    SX_FIELD("sample_count", "uint8", 1, 1, SX_COUNT_PROP),
    SX_FIELD("name", "char[32]", 2, 32, SX_STRING),
};
static const sx_layout sxt_mdl_instrument = {UINT32_C(0x600E0049),"mdl_instrument",sxt_mdl_instrument_fields,SX_COUNT(sxt_mdl_instrument_fields),SX_LE};

static const xx_data_struct_field_desc sxt_mdl_subinstrument_fields[] = {
    SX_FIELD("sample_number", "uint8", 0, 1, SX_NONE),
    SX_FIELD("last_note", "uint8", 1, 1, SX_NONE),
    SX_FIELD("volume", "uint8", 2, 1, SX_NONE),
    SX_FIELD("volume_envelope", "uint8", 3, 1, SX_FLAGS),
    SX_FIELD("panning", "uint8", 4, 1, SX_NONE),
    SX_FIELD("panning_envelope", "uint8", 5, 1, SX_FLAGS),
    SX_FIELD("fadeout", "uint16", 6, 2, SX_NONE),
    SX_FIELD("vibrato_speed", "uint8", 8, 1, SX_NONE),
    SX_FIELD("vibrato_depth", "uint8", 9, 1, SX_NONE),
    SX_FIELD("vibrato_sweep", "uint8", 10, 1, SX_NONE),
    SX_FIELD("vibrato_waveform", "uint8", 11, 1, SX_ID),
    SX_FIELD("reserved", "uint8", 12, 1, SX_RESERVED),
    SX_FIELD("pitch_envelope", "uint8", 13, 1, SX_FLAGS),
};
static const sx_layout sxt_mdl_subinstrument = {UINT32_C(0x600E004A),"mdl_subinstrument",sxt_mdl_subinstrument_fields,SX_COUNT(sxt_mdl_subinstrument_fields),SX_LE};

static const xx_data_struct_field_desc sxt_mdl_sample_fields[] = {
    SX_FIELD("sample_number", "uint8", 0, 1, SX_NONE),
    SX_FIELD("name", "char[32]", 1, 32, SX_STRING),
    SX_FIELD("filename", "char[8]", 33, 8, SX_STRING),
    SX_FIELD("c4_frequency", "uint32", 41, 4, SX_NONE),
    SX_FIELD("length", "uint32", 45, 4, SX_SIZE),
    SX_FIELD("loop_start", "uint32", 49, 4, SX_OFFSET),
    SX_FIELD("loop_length", "uint32", 53, 4, SX_SIZE),
    SX_FIELD("volume", "uint8", 57, 1, SX_NONE),
    SX_FIELD("flags", "uint8", 58, 1, SX_FLAGS),
};
static const sx_layout sxt_mdl_sample = {UINT32_C(0x600E004B),"mdl_sample",sxt_mdl_sample_fields,SX_COUNT(sxt_mdl_sample_fields),SX_LE};

static const xx_data_struct_field_desc sxt_mdl_envelope_fields[] = {
    SX_FIELD("envelope_number", "uint8", 0, 1, SX_NONE),
    SX_FIELD("points", "uint8[30]", 1, 30, SX_NONE),
    SX_FIELD("sustain_flags", "uint8", 31, 1, SX_FLAGS),
    SX_FIELD("loop_points", "uint8", 32, 1, SX_FLAGS),
};
static const sx_layout sxt_mdl_envelope = {UINT32_C(0x600E004C),"mdl_envelope",sxt_mdl_envelope_fields,SX_COUNT(sxt_mdl_envelope_fields),SX_LE};

static const xx_data_struct_field_desc sxt_med_header_fields[] = {
    SX_FIELD("signature", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("module_size", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("song_offset", "uint32", 8, 4, SX_OFFSET),
    SX_FIELD("player_section", "uint16", 12, 2, SX_NONE),
    SX_FIELD("player_sequence", "uint16", 14, 2, SX_NONE),
    SX_FIELD("pattern_table_offset", "uint32", 16, 4, SX_OFFSET),
    SX_FIELD("mmd_flags", "uint8", 20, 1, SX_FLAGS),
    SX_FIELD("reserved0", "uint8[3]", 21, 3, SX_RESERVED),
    SX_FIELD("sample_table_offset", "uint32", 24, 4, SX_OFFSET),
    SX_FIELD("reserved1", "uint32", 28, 4, SX_RESERVED),
    SX_FIELD("expansion_offset", "uint32", 32, 4, SX_OFFSET),
    SX_FIELD("reserved2", "uint32", 36, 4, SX_RESERVED),
    SX_FIELD("player_state", "uint16", 40, 2, SX_NONE),
    SX_FIELD("player_block", "uint16", 42, 2, SX_NONE),
    SX_FIELD("player_line", "uint16", 44, 2, SX_NONE),
    SX_FIELD("player_sequence_number", "uint16", 46, 2, SX_NONE),
    SX_FIELD("active_line", "int16", 48, 2, SX_NONE),
    SX_FIELD("counter", "uint8", 50, 1, SX_NONE),
    SX_FIELD("extra_songs_minus_one", "uint8", 51, 1, SX_NONE),
};
static const sx_layout sxt_med_header = {UINT32_C(0x600E004D),"med_header",sxt_med_header_fields,SX_COUNT(sxt_med_header_fields),SX_BE};

static const xx_data_struct_field_desc sxt_med_sample_settings_fields[] = {
    SX_FIELD("repeat_start_words", "uint16", 0, 2, SX_NONE),
    SX_FIELD("repeat_length_words", "uint16", 2, 2, SX_NONE),
    SX_FIELD("midi_channel", "uint8", 4, 1, SX_NONE),
    SX_FIELD("midi_preset", "uint8", 5, 1, SX_NONE),
    SX_FIELD("volume", "uint8", 6, 1, SX_NONE),
    SX_FIELD("transpose", "int8", 7, 1, SX_NONE),
};
static const sx_layout sxt_med_sample_settings = {UINT32_C(0x600E004E),"med_sample_settings",sxt_med_sample_settings_fields,SX_COUNT(sxt_med_sample_settings_fields),SX_BE};

static const xx_data_struct_field_desc sxt_med_song_fields[] = {
    SX_FIELD("pattern_count", "uint16", 0, 2, SX_COUNT_PROP),
    SX_FIELD("order_count", "uint16", 2, 2, SX_COUNT_PROP),
    SX_FIELD("orders", "uint8[256]", 4, 256, SX_NONE),
    SX_FIELD("default_tempo", "uint16", 260, 2, SX_NONE),
    SX_FIELD("transpose", "int8", 262, 1, SX_NONE),
    SX_FIELD("flags", "uint8", 263, 1, SX_FLAGS),
    SX_FIELD("flags2", "uint8", 264, 1, SX_FLAGS),
    SX_FIELD("speed", "uint8", 265, 1, SX_NONE),
    SX_FIELD("track_volumes", "uint8[16]", 266, 16, SX_NONE),
    SX_FIELD("master_volume", "uint8", 282, 1, SX_NONE),
    SX_FIELD("sample_count", "uint8", 283, 1, SX_COUNT_PROP),
};
static const sx_layout sxt_med_song = {UINT32_C(0x600E004F),"med_song",sxt_med_song_fields,SX_COUNT(sxt_med_song_fields),SX_BE};

static const xx_data_struct_field_desc sxt_med_pattern0_header_fields[] = {
    SX_FIELD("channel_count", "uint8", 0, 1, SX_COUNT_PROP),
    SX_FIELD("rows_minus_one", "uint8", 1, 1, SX_NONE),
};
static const sx_layout sxt_med_pattern0_header = {UINT32_C(0x600E0050),"med_pattern0_header",sxt_med_pattern0_header_fields,SX_COUNT(sxt_med_pattern0_header_fields),SX_BE};

static const xx_data_struct_field_desc sxt_med_pattern1_header_fields[] = {
    SX_FIELD("channel_count", "uint16", 0, 2, SX_COUNT_PROP),
    SX_FIELD("rows_minus_one", "uint16", 2, 2, SX_NONE),
    SX_FIELD("block_info_offset", "uint32", 4, 4, SX_OFFSET),
};
static const sx_layout sxt_med_pattern1_header = {UINT32_C(0x600E0051),"med_pattern1_header",sxt_med_pattern1_header_fields,SX_COUNT(sxt_med_pattern1_header_fields),SX_BE};

static const xx_data_struct_field_desc sxt_med_sample_header_fields[] = {
    SX_FIELD("length", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("sample_type", "int16", 4, 2, SX_ID),
};
static const sx_layout sxt_med_sample_header = {UINT32_C(0x600E0052),"med_sample_header",sxt_med_sample_header_fields,SX_COUNT(sxt_med_sample_header_fields),SX_BE};

static const xx_data_struct_field_desc sxt_med_expansion_fields[] = {
    SX_FIELD("next_module_offset", "uint32", 0, 4, SX_OFFSET),
    SX_FIELD("instrument_extensions_offset", "uint32", 4, 4, SX_OFFSET),
    SX_FIELD("instrument_extension_count", "uint16", 8, 2, SX_COUNT_PROP),
    SX_FIELD("instrument_extension_size", "uint16", 10, 2, SX_SIZE),
    SX_FIELD("annotation_offset", "uint32", 12, 4, SX_OFFSET),
    SX_FIELD("annotation_size", "uint32", 16, 4, SX_SIZE),
    SX_FIELD("instrument_names_offset", "uint32", 20, 4, SX_OFFSET),
    SX_FIELD("instrument_name_count", "uint16", 24, 2, SX_COUNT_PROP),
    SX_FIELD("instrument_name_size", "uint16", 26, 2, SX_SIZE),
    SX_FIELD("jump_mask", "uint32", 28, 4, SX_FLAGS),
    SX_FIELD("rgb_table_offset", "uint32", 32, 4, SX_OFFSET),
    SX_FIELD("channel_split", "uint8[4]", 36, 4, SX_NONE),
    SX_FIELD("notation_offset", "uint32", 40, 4, SX_OFFSET),
    SX_FIELD("song_name_offset", "uint32", 44, 4, SX_OFFSET),
    SX_FIELD("song_name_size", "uint32", 48, 4, SX_SIZE),
    SX_FIELD("dumps_offset", "uint32", 52, 4, SX_OFFSET),
    SX_FIELD("info_offset", "uint32", 56, 4, SX_OFFSET),
    SX_FIELD("rexx_offset", "uint32", 60, 4, SX_OFFSET),
    SX_FIELD("command3x_offset", "uint32", 64, 4, SX_OFFSET),
    SX_FIELD("reserved", "bytes", 68, 12, SX_RESERVED),
};
static const sx_layout sxt_med_expansion = {UINT32_C(0x600E0053),"med_expansion",sxt_med_expansion_fields,SX_COUNT(sxt_med_expansion_fields),SX_BE};

static const xx_data_struct_field_desc sxt_imf_header_fields[] = {
    SX_FIELD("title", "char[32]", 0, 32, SX_STRING),
    SX_FIELD("order_count", "uint16", 32, 2, SX_COUNT_PROP),
    SX_FIELD("pattern_count", "uint16", 34, 2, SX_COUNT_PROP),
    SX_FIELD("instrument_count", "uint16", 36, 2, SX_COUNT_PROP),
    SX_FIELD("flags", "uint16", 38, 2, SX_FLAGS),
    SX_FIELD("reserved0", "bytes", 40, 8, SX_RESERVED),
    SX_FIELD("speed", "uint8", 48, 1, SX_NONE),
    SX_FIELD("bpm", "uint8", 49, 1, SX_NONE),
    SX_FIELD("master_volume", "uint8", 50, 1, SX_NONE),
    SX_FIELD("amplification", "uint8", 51, 1, SX_NONE),
    SX_FIELD("reserved1", "bytes", 52, 8, SX_RESERVED),
    SX_FIELD("signature", "char[4]", 60, 4, SX_SIGNATURE),
};
static const sx_layout sxt_imf_header = {UINT32_C(0x600E0054),"imf_header",sxt_imf_header_fields,SX_COUNT(sxt_imf_header_fields),SX_LE};

static const xx_data_struct_field_desc sxt_imf_channel_fields[] = {
    SX_FIELD("name", "char[12]", 0, 12, SX_STRING),
    SX_FIELD("chorus", "uint8", 12, 1, SX_NONE),
    SX_FIELD("reverb", "uint8", 13, 1, SX_NONE),
    SX_FIELD("panning", "uint8", 14, 1, SX_NONE),
    SX_FIELD("status", "uint8", 15, 1, SX_ID),
};
static const sx_layout sxt_imf_channel = {UINT32_C(0x600E0055),"imf_channel",sxt_imf_channel_fields,SX_COUNT(sxt_imf_channel_fields),SX_LE};

static const xx_data_struct_field_desc sxt_imf_instrument_fields[] = {
    SX_FIELD("name", "char[32]", 0, 32, SX_STRING),
    SX_FIELD("sample_map", "uint8[120]", 32, 120, SX_NONE),
    SX_FIELD("reserved", "bytes", 152, 8, SX_RESERVED),
};
static const sx_layout sxt_imf_instrument = {UINT32_C(0x600E0056),"imf_instrument",sxt_imf_instrument_fields,SX_COUNT(sxt_imf_instrument_fields),SX_LE};

static const xx_data_struct_field_desc sxt_imf_envelope_control_fields[] = {
    SX_FIELD("point_count", "uint8", 0, 1, SX_COUNT_PROP),
    SX_FIELD("sustain", "uint8", 1, 1, SX_NONE),
    SX_FIELD("loop_start", "uint8", 2, 1, SX_NONE),
    SX_FIELD("loop_end", "uint8", 3, 1, SX_NONE),
    SX_FIELD("flags", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("reserved", "uint8[3]", 5, 3, SX_RESERVED),
};
static const sx_layout sxt_imf_envelope_control = {UINT32_C(0x600E0057),"imf_envelope_control",sxt_imf_envelope_control_fields,SX_COUNT(sxt_imf_envelope_control_fields),SX_LE};

static const xx_data_struct_field_desc sxt_imf_instrument_tail_fields[] = {
    SX_FIELD("fadeout", "uint16", 0, 2, SX_NONE),
    SX_FIELD("sample_count", "uint16", 2, 2, SX_COUNT_PROP),
    SX_FIELD("signature", "char[4]", 4, 4, SX_SIGNATURE),
};
static const sx_layout sxt_imf_instrument_tail = {UINT32_C(0x600E0058),"imf_instrument_tail",sxt_imf_instrument_tail_fields,SX_COUNT(sxt_imf_instrument_tail_fields),SX_LE};

static const xx_data_struct_field_desc sxt_imf_sample_fields[] = {
    SX_FIELD("filename", "char[13]", 0, 13, SX_STRING),
    SX_FIELD("reserved0", "uint8[3]", 13, 3, SX_RESERVED),
    SX_FIELD("length", "uint32", 16, 4, SX_SIZE),
    SX_FIELD("loop_start", "uint32", 20, 4, SX_OFFSET),
    SX_FIELD("loop_end", "uint32", 24, 4, SX_OFFSET),
    SX_FIELD("sample_rate", "uint32", 28, 4, SX_NONE),
    SX_FIELD("volume", "uint8", 32, 1, SX_NONE),
    SX_FIELD("panning", "uint8", 33, 1, SX_NONE),
    SX_FIELD("reserved1", "bytes", 34, 14, SX_RESERVED),
    SX_FIELD("flags", "uint8", 48, 1, SX_FLAGS),
    SX_FIELD("reserved2", "bytes", 49, 5, SX_RESERVED),
    SX_FIELD("ems_handle", "uint16", 54, 2, SX_RESERVED),
    SX_FIELD("dram_address", "uint32", 56, 4, SX_RESERVED),
    SX_FIELD("signature", "char[4]", 60, 4, SX_SIGNATURE),
};
static const sx_layout sxt_imf_sample = {UINT32_C(0x600E0059),"imf_sample",sxt_imf_sample_fields,SX_COUNT(sxt_imf_sample_fields),SX_LE};

static const xx_data_struct_field_desc sxt_imf_pattern_header_fields[] = {
    SX_FIELD("packed_size", "uint16", 0, 2, SX_SIZE),
    SX_FIELD("row_count", "uint16", 2, 2, SX_COUNT_PROP),
};
static const sx_layout sxt_imf_pattern_header = {UINT32_C(0x600E005A),"imf_pattern_header",sxt_imf_pattern_header_fields,SX_COUNT(sxt_imf_pattern_header_fields),SX_LE};

static const xx_data_struct_field_desc sxt_amf_header_fields[] = {
    SX_FIELD("signature", "char[3]", 0, 3, SX_SIGNATURE),
    SX_FIELD("version", "uint8", 3, 1, SX_ID),
    SX_FIELD("title", "char[32]", 4, 32, SX_STRING),
    SX_FIELD("instrument_count", "uint8", 36, 1, SX_COUNT_PROP),
    SX_FIELD("order_count", "uint8", 37, 1, SX_COUNT_PROP),
    SX_FIELD("track_count", "uint16", 38, 2, SX_COUNT_PROP),
    SX_FIELD("channel_count", "uint8", 40, 1, SX_COUNT_PROP),
    SX_FIELD("panning", "uint8[32]", 41, 32, SX_NONE),
    SX_FIELD("bpm", "uint8", 73, 1, SX_NONE),
    SX_FIELD("speed", "uint8", 74, 1, SX_NONE),
};
static const sx_layout sxt_amf_header = {UINT32_C(0x600E005B),"amf_header",sxt_amf_header_fields,SX_COUNT(sxt_amf_header_fields),SX_LE};

static const xx_data_struct_field_desc sxt_amf_instrument_fields[] = {
    SX_FIELD("sample_type", "uint8", 0, 1, SX_ID),
    SX_FIELD("name", "char[32]", 1, 32, SX_STRING),
    SX_FIELD("filename", "char[13]", 33, 13, SX_STRING),
    SX_FIELD("sample_index", "uint32", 46, 4, SX_NONE),
    SX_FIELD("length", "uint32", 50, 4, SX_SIZE),
    SX_FIELD("c2_frequency", "uint16", 54, 2, SX_NONE),
    SX_FIELD("volume", "uint8", 56, 1, SX_NONE),
    SX_FIELD("loop_start", "uint32", 57, 4, SX_OFFSET),
    SX_FIELD("loop_end", "uint32", 61, 4, SX_OFFSET),
};
static const sx_layout sxt_amf_instrument = {UINT32_C(0x600E005C),"amf_instrument",sxt_amf_instrument_fields,SX_COUNT(sxt_amf_instrument_fields),SX_LE};

static const xx_data_struct_field_desc sxt_amf_track_header_fields[] = {
    SX_FIELD("event_count", "uint16", 0, 2, SX_COUNT_PROP),
    SX_FIELD("unknown", "uint8", 2, 1, SX_NONE),
};
static const sx_layout sxt_amf_track_header = {UINT32_C(0x600E005D),"amf_track_header",sxt_amf_track_header_fields,SX_COUNT(sxt_amf_track_header_fields),SX_LE};

static const xx_data_struct_field_desc sxt_amf_event_fields[] = {
    SX_FIELD("row", "uint8", 0, 1, SX_NONE),
    SX_FIELD("event_type", "uint8", 1, 1, SX_ID),
    SX_FIELD("parameter", "uint8", 2, 1, SX_NONE),
};
static const sx_layout sxt_amf_event = {UINT32_C(0x600E005E),"amf_event",sxt_amf_event_fields,SX_COUNT(sxt_amf_event_fields),SX_LE};

static const xx_data_struct_field_desc sxt_asylum_header_fields[] = {
    SX_FIELD("signature", "char[32]", 0, 32, SX_SIGNATURE),
    SX_FIELD("speed", "uint8", 32, 1, SX_NONE),
    SX_FIELD("bpm", "uint8", 33, 1, SX_NONE),
    SX_FIELD("instrument_count", "uint8", 34, 1, SX_COUNT_PROP),
    SX_FIELD("pattern_count", "uint8", 35, 1, SX_COUNT_PROP),
    SX_FIELD("order_count", "uint8", 36, 1, SX_COUNT_PROP),
    SX_FIELD("restart", "uint8", 37, 1, SX_NONE),
};
static const sx_layout sxt_asylum_header = {UINT32_C(0x600E005F),"asylum_header",sxt_asylum_header_fields,SX_COUNT(sxt_asylum_header_fields),SX_LE};

static const xx_data_struct_field_desc sxt_asylum_instrument_fields[] = {
    SX_FIELD("name", "char[22]", 0, 22, SX_STRING),
    SX_FIELD("finetune_nibble", "uint8", 22, 1, SX_NONE),
    SX_FIELD("volume", "uint8", 23, 1, SX_NONE),
    SX_FIELD("transpose", "int8", 24, 1, SX_NONE),
    SX_FIELD("length", "uint32", 25, 4, SX_SIZE),
    SX_FIELD("loop_start", "uint32", 29, 4, SX_OFFSET),
    SX_FIELD("loop_length", "uint32", 33, 4, SX_SIZE),
};
static const sx_layout sxt_asylum_instrument = {UINT32_C(0x600E0060),"asylum_instrument",sxt_asylum_instrument_fields,SX_COUNT(sxt_asylum_instrument_fields),SX_LE};

static const xx_data_struct_field_desc sxt_asylum_event_fields[] = {
    SX_FIELD("note", "uint8", 0, 1, SX_NONE),
    SX_FIELD("instrument", "uint8", 1, 1, SX_NONE),
    SX_FIELD("effect", "uint8", 2, 1, SX_ID),
    SX_FIELD("parameter", "uint8", 3, 1, SX_NONE),
};
static const sx_layout sxt_asylum_event = {UINT32_C(0x600E0061),"asylum_event",sxt_asylum_event_fields,SX_COUNT(sxt_asylum_event_fields),SX_LE};

static const xx_data_struct_field_desc sxt_soundfx_header_fields[] = {
    SX_FIELD("signature", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("delay", "uint16", 4, 2, SX_NONE),
    SX_FIELD("reserved", "bytes", 6, 14, SX_RESERVED),
};
static const sx_layout sxt_soundfx_header = {UINT32_C(0x600E0062),"soundfx_header",sxt_soundfx_header_fields,SX_COUNT(sxt_soundfx_header_fields),SX_BE};

static const xx_data_struct_field_desc sxt_soundfx_instrument_fields[] = {
    SX_FIELD("name", "char[22]", 0, 22, SX_STRING),
    SX_FIELD("length_words", "uint16", 22, 2, SX_NONE),
    SX_FIELD("finetune_nibble", "uint8", 24, 1, SX_NONE),
    SX_FIELD("volume", "uint8", 25, 1, SX_NONE),
    SX_FIELD("loop_start", "uint16", 26, 2, SX_OFFSET),
    SX_FIELD("loop_length_words", "uint16", 28, 2, SX_NONE),
};
static const sx_layout sxt_soundfx_instrument = {UINT32_C(0x600E0063),"soundfx_instrument",sxt_soundfx_instrument_fields,SX_COUNT(sxt_soundfx_instrument_fields),SX_BE};

static const sx_layout *const sx_tracker_layouts[] = {
    &sxt_tracker_order_u8,
    &sxt_tracker_order_u16be,
    &sxt_tracker_track_index,
    &sxt_tracker_offset_u32le,
    &sxt_tracker_offset_u32be,
    &sxt_tracker_paragraph,
    &sxt_tracker_length_u32be,
    &sxt_tracker_loop_start_u32be,
    &sxt_tracker_loop_length_u32be,
    &sxt_tracker_volume,
    &sxt_tracker_finetune,
    &sxt_tracker_pan4,
    &sxt_tracker_count_u8,
    &sxt_tracker_count_u16le,
    &sxt_tracker_count_u16be,
    &sxt_tracker_length_u16le,
    &sxt_tracker_chunk_be,
    &sxt_tracker_title20,
    &sxt_tracker_title30,
    &sxt_tracker_title32,
    &sxt_tracker_title44,
    &sxt_mod_sample,
    &sxt_mod_orders,
    &sxt_mod_signature,
    &sxt_mod_event,
    &sxt_xm_header,
    &sxt_xm_pattern_header,
    &sxt_xm_instrument_header,
    &sxt_xm_instrument_sampled_header,
    &sxt_xm_keymap,
    &sxt_tracker_envelope_point,
    &sxt_xm_envelope_control,
    &sxt_xm_sample,
    &sxt_s3m_header,
    &sxt_s3m_channel,
    &sxt_s3m_panning,
    &sxt_s3m_sample,
    &sxt_it_header,
    &sxt_it_channel_pan,
    &sxt_it_sample,
    &sxt_it_pattern_header,
    &sxt_mtm_header,
    &sxt_mtm_sample,
    &sxt_mtm_event,
    &sxt_ult_header,
    &sxt_ult_sample,
    &sxt_ult_counts,
    &sxt_okt_signature,
    &sxt_okt_channel,
    &sxt_okt_sample,
    &sxt_okt_speed,
    &sxt_okt_event,
    &sxt_digi_header,
    &sxt_digi_pattern_header,
    &sxt_far_header,
    &sxt_far_order_counts,
    &sxt_far_pattern_header,
    &sxt_far_sample_bitmap,
    &sxt_far_sample,
    &sxt_far_event,
    &sxt_gdm_header,
    &sxt_gdm_sample,
    &sxt_dbm_header,
    &sxt_dbm_info,
    &sxt_dbm_song,
    &sxt_dbm_instrument,
    &sxt_dbm_pattern_header,
    &sxt_dbm_sample_header,
    &sxt_mdl_header,
    &sxt_mdl_chunk,
    &sxt_mdl_info,
    &sxt_mdl_pattern_header,
    &sxt_mdl_instrument,
    &sxt_mdl_subinstrument,
    &sxt_mdl_sample,
    &sxt_mdl_envelope,
    &sxt_med_header,
    &sxt_med_sample_settings,
    &sxt_med_song,
    &sxt_med_pattern0_header,
    &sxt_med_pattern1_header,
    &sxt_med_sample_header,
    &sxt_med_expansion,
    &sxt_imf_header,
    &sxt_imf_channel,
    &sxt_imf_instrument,
    &sxt_imf_envelope_control,
    &sxt_imf_instrument_tail,
    &sxt_imf_sample,
    &sxt_imf_pattern_header,
    &sxt_amf_header,
    &sxt_amf_instrument,
    &sxt_amf_track_header,
    &sxt_amf_event,
    &sxt_asylum_header,
    &sxt_asylum_instrument,
    &sxt_asylum_event,
    &sxt_soundfx_header,
    &sxt_soundfx_instrument,
};

static bool sx_tracker_supports(xx_file_type_t type)
{
    switch(type){
    case XX_FILE_TYPE_TRACKER_XM:case XX_FILE_TYPE_TRACKER_S3M:case XX_FILE_TYPE_TRACKER_IT:
    case XX_FILE_TYPE_TRACKER_MTM:case XX_FILE_TYPE_TRACKER_ULT:case XX_FILE_TYPE_TRACKER_OKT:
    case XX_FILE_TYPE_TRACKER_DIGI:case XX_FILE_TYPE_TRACKER_MOD:case XX_FILE_TYPE_TRACKER_FAR:
    case XX_FILE_TYPE_TRACKER_MDL:case XX_FILE_TYPE_TRACKER_GDM:case XX_FILE_TYPE_TRACKER_DBM:
    case XX_FILE_TYPE_TRACKER_MED:case XX_FILE_TYPE_TRACKER_IMF:case XX_FILE_TYPE_TRACKER_AMF:
    case XX_FILE_TYPE_ASYLUM_AMF:case XX_FILE_TYPE_TRACKER_SOUNDFX:return true;
    default:return false;
    }
}
static uint32_t sxt_num(sx_context *c,int64_t at,unsigned width,bool be)
{
    uint8_t b[4];if(!width||width>4||!sx_read(c,at,b,width)){c->failed=true;return 0;}
    uint32_t v=0;for(unsigned i=0;i<width;i++)v|=(uint32_t)b[i]<<(8*(be?width-1-i:i));return v;
}
static bool sxt_take(sx_context *c,const sx_layout *l,int64_t *at,int64_t end,uint64_t count)
{
    const xx_data_struct_field_desc *f=&l->fields[l->field_count-1];int64_t width=f->rel_offset+f->size;
    if(*at<0||end<*at||count>(uint64_t)(end-*at)/(uint64_t)width)return false;
    if(!sx_table(c,l,*at,width,count))return false;*at+=(int64_t)count*width;return true;
}
static bool sxt_prefix(const char *s,const char *p){return !xx_rt_strncmp(s,p,xx_rt_strlen(p));}
static bool sxt_suffix(const char *s,const char *p){size_t a=xx_rt_strlen(s),b=xx_rt_strlen(p);return a>=b&&!xx_rt_strcmp(s+a-b,p);}
static bool sxt_wcontains(const wchar_t *s,const wchar_t *p){size_t n=xx_rt_wcslen(p);for(;*s;s++)if(!xx_rt_wcsncmp(s,p,n))return true;return false;}
#define SXT_T(n,k) do{if(!sxt_take(c,&sxt_##n,&at,end,(k)))return false;}while(0)
#define SXT_EQ(n) (!xx_rt_strcmp(name,(n)))
static bool sxt_component(sx_context *c,const char *name,int64_t off,int64_t size)
{
    int64_t at=off,end=off+size;uint32_t n,m;xx_file_type_t type=c->f->file_type;
    switch(type){
    case XX_FILE_TYPE_TRACKER_XM:
        if(SXT_EQ("xm-descriptor.bin")){SXT_T(xm_header,1);SXT_T(tracker_order_u8,end-at);}
        else if(sxt_prefix(name,"pattern-")){SXT_T(xm_pattern_header,1);}
        else if(sxt_suffix(name,"descriptor.bin")){SXT_T(xm_sample,1);}
        else if(sxt_prefix(name,"instrument-")&&sxt_suffix(name,".bin")&&!sxt_suffix(name,"delta.bin")){
            if(size==29){SXT_T(xm_instrument_header,1);}else if(size==263){SXT_T(xm_instrument_sampled_header,1);SXT_T(xm_keymap,1);SXT_T(tracker_envelope_point,24);SXT_T(xm_envelope_control,1);}else return false;
        }break;
    case XX_FILE_TYPE_TRACKER_S3M:
        if(SXT_EQ("s3m-descriptor.bin")){n=sxt_num(c,32,2,false);m=sxt_num(c,34,2,false)+sxt_num(c,36,2,false);SXT_T(s3m_header,1);SXT_T(s3m_channel,32);SXT_T(tracker_order_u8,n);SXT_T(tracker_paragraph,m);if(sxt_num(c,53,1,false)==252){SXT_T(s3m_panning,32);}if(at!=end)return false;}
        else if(sxt_suffix(name,"descriptor.bin")){SXT_T(s3m_sample,1);}
        else if(sxt_prefix(name,"pattern-")){SXT_T(tracker_length_u16le,1);}break;
    case XX_FILE_TYPE_TRACKER_IT:
        if(SXT_EQ("it-descriptor.bin")){n=sxt_num(c,32,2,false);m=sxt_num(c,36,2,false)+sxt_num(c,38,2,false);SXT_T(it_header,1);SXT_T(it_channel_pan,64);SXT_T(tracker_volume,64);SXT_T(tracker_order_u8,n);SXT_T(tracker_offset_u32le,m);if(at!=end)return false;}
        else if(sxt_suffix(name,"descriptor.bin")){SXT_T(it_sample,1);}
        else if(sxt_prefix(name,"pattern-")){SXT_T(it_pattern_header,1);}break;
    case XX_FILE_TYPE_TRACKER_MTM:
        if(SXT_EQ("mtm-descriptor.bin")){SXT_T(mtm_header,1);SXT_T(tracker_pan4,32);SXT_T(mtm_sample,sxt_num(c,30,1,false));SXT_T(tracker_order_u8,128);if(at!=end)return false;}
        else if(SXT_EQ("pattern-tracks.bin")){if(size%2)return false;SXT_T(tracker_track_index,size/2);}
        else if(sxt_prefix(name,"track-")){if(size%3)return false;SXT_T(mtm_event,size/3);}break;
    case XX_FILE_TYPE_TRACKER_ULT:
        if(SXT_EQ("ult-descriptor.bin")){SXT_T(ult_header,1);at+=32*(int64_t)sxt_num(c,47,1,false);SXT_T(tracker_count_u8,1);if(at!=end)return false;}
        else if(sxt_suffix(name,"descriptor.bin")){SXT_T(ult_sample,1);}
        else if(SXT_EQ("orders-panning.bin")){SXT_T(tracker_order_u8,256);n=sxt_num(c,at,1,false)+1;SXT_T(ult_counts,1);SXT_T(tracker_pan4,n);if(at!=end)return false;}break;
    case XX_FILE_TYPE_TRACKER_OKT:
        if(SXT_EQ("okt-magic.bin")){SXT_T(okt_signature,1);break;}
        SXT_T(tracker_chunk_be,1);
        if(SXT_EQ("cmod.bin")){SXT_T(okt_channel,4);}
        else if(SXT_EQ("samp.bin")){SXT_T(okt_sample,36);}
        else if(SXT_EQ("spee.bin")){SXT_T(okt_speed,1);}
        else if(SXT_EQ("slen.bin")||SXT_EQ("plen.bin")){SXT_T(tracker_count_u16be,1);}
        else if(SXT_EQ("patt.bin")){SXT_T(tracker_order_u8,end-at);}
        else if(sxt_prefix(name,"pattern-")){SXT_T(tracker_count_u16be,1);if((end-at)%4)return false;SXT_T(okt_event,(end-at)/4);}break;
    case XX_FILE_TYPE_TRACKER_DIGI:
        if(SXT_EQ("headers.bin")){SXT_T(digi_header,1);SXT_T(tracker_order_u8,128);SXT_T(tracker_length_u32be,31);SXT_T(tracker_loop_start_u32be,31);SXT_T(tracker_loop_length_u32be,31);SXT_T(tracker_volume,31);SXT_T(tracker_finetune,31);SXT_T(tracker_title32,1);SXT_T(tracker_title30,31);if(at!=end)return false;}
        else if(SXT_EQ("pattern.bin")){if(sxt_num(c,26,1,false)){SXT_T(digi_pattern_header,1);}if((end-at)%4)return false;SXT_T(mod_event,(end-at)/4);}break;
    case XX_FILE_TYPE_TRACKER_MOD:
        if(SXT_EQ("descriptor.bin")){SXT_T(tracker_title20,1);SXT_T(mod_sample,31);SXT_T(mod_orders,1);SXT_T(mod_signature,1);if(at!=end)return false;}
        else if(sxt_prefix(name,"pattern-")){if(size%4)return false;SXT_T(mod_event,size/4);}break;
    case XX_FILE_TYPE_TRACKER_FAR:
        if(SXT_EQ("descriptor.bin")){SXT_T(far_header,1);at+=sxt_num(c,96,2,false);SXT_T(tracker_order_u8,256);SXT_T(far_order_counts,1);SXT_T(tracker_length_u16le,256);}
        else if(sxt_prefix(name,"pattern-")){SXT_T(far_pattern_header,1);if((end-at)%4)return false;SXT_T(far_event,(end-at)/4);}
        else if(SXT_EQ("sample-bitmap.bin")){SXT_T(far_sample_bitmap,1);}
        else if(sxt_prefix(name,"instrument-")){SXT_T(far_sample,1);}break;
    case XX_FILE_TYPE_TRACKER_GDM:
        if(SXT_EQ("descriptor.bin")){SXT_T(gdm_header,1);}
        else if(SXT_EQ("orders.bin")){SXT_T(tracker_order_u8,size);}
        else if(SXT_EQ("instruments.bin")){if(size%62)return false;SXT_T(gdm_sample,size/62);}
        else if(sxt_prefix(name,"pattern-")){SXT_T(tracker_length_u16le,1);}break;
    case XX_FILE_TYPE_TRACKER_DBM:
        if(SXT_EQ("descriptor.bin")){SXT_T(dbm_header,1);break;}
        SXT_T(tracker_chunk_be,1);
        if(SXT_EQ("chunk-NAME.bin")){SXT_T(tracker_title44,1);}
        else if(SXT_EQ("chunk-INFO.bin")){SXT_T(dbm_info,1);}
        else if(SXT_EQ("chunk-SONG.bin")){n=sxt_num(c,at+44,2,true);SXT_T(dbm_song,1);SXT_T(tracker_order_u16be,n);}
        else if(SXT_EQ("chunk-INST.bin")){if((end-at)%50)return false;SXT_T(dbm_instrument,(end-at)/50);}
        else if(SXT_EQ("chunk-PATT.bin")){while(at<end){n=sxt_num(c,at+2,4,true);SXT_T(dbm_pattern_header,1);if(n>(uint64_t)(end-at))return false;at+=n;}}
        else if(SXT_EQ("chunk-SMPL.bin")){while(at<end){n=sxt_num(c,at,4,true);m=sxt_num(c,at+4,4,true);SXT_T(dbm_sample_header,1);if(!n||m>(uint64_t)(end-at)/n)return false;at+=(int64_t)n*m;}}break;
    case XX_FILE_TYPE_TRACKER_MDL:
        SXT_T(mdl_chunk,1);
        if(SXT_EQ("chunk-IN.bin")){n=sxt_num(c,at+52,2,false);SXT_T(mdl_info,1);SXT_T(tracker_order_u8,n);}
        else if(SXT_EQ("chunk-PA.bin")){n=sxt_num(c,at,1,false);SXT_T(tracker_count_u8,1);for(uint32_t i=0;i<n;i++){m=sxt_num(c,at,1,false);SXT_T(mdl_pattern_header,1);SXT_T(tracker_track_index,m);}}
        else if(SXT_EQ("chunk-TR.bin")){n=sxt_num(c,at,2,false);SXT_T(tracker_count_u16le,1);for(uint32_t i=0;i<n;i++){m=sxt_num(c,at,2,false);SXT_T(tracker_length_u16le,1);if(m>(uint64_t)(end-at))return false;at+=m;}}
        else if(SXT_EQ("chunk-II.bin")){n=sxt_num(c,at,1,false);SXT_T(tracker_count_u8,1);for(uint32_t i=0;i<n;i++){m=sxt_num(c,at+1,1,false);SXT_T(mdl_instrument,1);SXT_T(mdl_subinstrument,m);}}
        else if(SXT_EQ("chunk-IS.bin")){n=sxt_num(c,at,1,false);SXT_T(tracker_count_u8,1);SXT_T(mdl_sample,n);}
        else if(SXT_EQ("chunk-VE.bin")||SXT_EQ("chunk-PE.bin")||SXT_EQ("chunk-FE.bin")){n=sxt_num(c,at,1,false);SXT_T(tracker_count_u8,1);SXT_T(mdl_envelope,n);}break;
    case XX_FILE_TYPE_TRACKER_MED:
        if(SXT_EQ("descriptor.bin")){SXT_T(med_header,1);}
        else if(SXT_EQ("song.bin")){SXT_T(med_sample_settings,63);SXT_T(med_song,1);}
        else if(SXT_EQ("pattern-pointers.bin")||SXT_EQ("sample-pointers.bin")){if(size%4)return false;SXT_T(tracker_offset_u32be,size/4);}
        else if(sxt_prefix(name,"pattern-")){if(sxt_num(c,3,1,false)=='1'){SXT_T(med_pattern1_header,1);}else{SXT_T(med_pattern0_header,1);}}
        else if(sxt_prefix(name,"sample-")){SXT_T(med_sample_header,1);}
        else if(SXT_EQ("expansion.bin")){SXT_T(med_expansion,1);}break;
    case XX_FILE_TYPE_TRACKER_IMF:
        if(SXT_EQ("descriptor.bin")){SXT_T(imf_header,1);SXT_T(imf_channel,32);SXT_T(tracker_order_u8,256);}
        else if(sxt_prefix(name,"pattern-")){SXT_T(imf_pattern_header,1);}
        else if(sxt_prefix(name,"instrument-")){SXT_T(imf_instrument,1);SXT_T(tracker_envelope_point,48);SXT_T(imf_envelope_control,3);SXT_T(imf_instrument_tail,1);}
        else if(sxt_suffix(name,"header.bin")){SXT_T(imf_sample,1);}break;
    case XX_FILE_TYPE_TRACKER_AMF:
        if(SXT_EQ("descriptor.bin")){SXT_T(amf_header,1);}
        else if(SXT_EQ("orders.bin")){n=sxt_num(c,37,1,false);m=sxt_num(c,40,1,false);for(uint32_t i=0;i<n;i++){SXT_T(tracker_count_u16le,1);SXT_T(tracker_track_index,m);}}
        else if(SXT_EQ("instruments.bin")){if(size%65)return false;SXT_T(amf_instrument,size/65);}
        else if(SXT_EQ("track-map.bin")){if(size%2)return false;SXT_T(tracker_track_index,size/2);}
        else if(sxt_prefix(name,"track-")){n=sxt_num(c,at,2,false);SXT_T(amf_track_header,1);SXT_T(amf_event,n);if(at!=end)return false;}break;
    case XX_FILE_TYPE_ASYLUM_AMF:
        if(SXT_EQ("descriptor.amf")){SXT_T(asylum_header,1);}
        else if(SXT_EQ("orders.amf")){SXT_T(tracker_order_u8,256);}
        else if(SXT_EQ("instruments.amf")){SXT_T(asylum_instrument,64);}
        else if(SXT_EQ("pattern.amf")){if(size%4)return false;SXT_T(asylum_event,size/4);}break;
    case XX_FILE_TYPE_TRACKER_SOUNDFX:
        if(SXT_EQ("sample-lengths.sfx")){if(size%4)return false;SXT_T(tracker_length_u32be,size/4);}
        else if(SXT_EQ("descriptor.sfx")){SXT_T(soundfx_header,1);}
        else if(SXT_EQ("instruments.sfx")){if(size%30)return false;SXT_T(soundfx_instrument,size/30);}
        else if(SXT_EQ("orders.sfx")){SXT_T(mod_orders,1);}
        else if(SXT_EQ("pattern.sfx")){if(size%4)return false;SXT_T(mod_event,size/4);}break;
    default:return false;
    }
    return !c->failed;
}
#undef SXT_T
#undef SXT_EQ
static bool sxt_finish(sx_context *c)
{
    size_t count=c->count;int64_t end=0;
    for(size_t i=1;i<count;i++){xx_data_struct d=c->items[i];size_t j=i;while(j&&c->items[j-1].offset>d.offset){c->items[j]=c->items[j-1];j--;}c->items[j]=d;}
    for(size_t i=0;i<count;i++){
        int64_t at=c->items[i].offset-c->f->base_address,n=c->items[i].total_size;
        if(at<end)return false;if(at>end&&!sx_raw(c,end,at-end))return false;end=at+n;
    }
    if(end<c->size&&!sx_raw(c,end,c->size-end))return false;
    for(size_t i=1;i<c->count;i++){xx_data_struct d=c->items[i];size_t j=i;while(j&&c->items[j-1].offset>d.offset){c->items[j]=c->items[j-1];j--;}c->items[j]=d;}
    return !c->failed;
}
static bool sx_tracker_build(sx_context *c)
{
    xx_archive_record_state *s;bool ok=true;uint64_t walked=0;
    if(c->size<1||c->size>268435456||!c->f->create_archive_records_reading)return false;
    s=xx_format_create_archive_records_reading(c->f,NULL,c->pd);if(!s)return false;
    if(c->f->file_type==XX_FILE_TYPE_TRACKER_MDL&&!sx_add(c,&sxt_mdl_header,0,5))ok=false;
    while(ok&&s->has_record){
        const xx_archive_record *r=xx_format_get_current_archive_record(c->f,s);
        const char *name=r?xx_archive_record_get_original_name(r):NULL;
        if(++walked>4096||xx_pd_is_stopped(c->pd)||!r||!name||xx_rt_strlen(name)<5||name[4]!='-'||r->data_offset<c->f->base_address||r->compressed_size<0){ok=false;break;}
        int64_t at=r->data_offset-c->f->base_address,n=r->compressed_size;
        if(!sx_range(c,at,(uint64_t)n)||!sxt_component(c,name+5,at,n)){ok=false;break;}
        if(!xx_format_archive_record_move_to_next(c->f,s,c->pd))break;
    }
    if(walked!=(uint64_t)s->total_records||xx_pd_is_stopped(c->pd))ok=false;
    xx_format_free_archive_records_reading(c->f,s);
    return ok&&c->count>0&&sxt_finish(c);
}
static bool sx_tracker_comment(xx_data_struct_record *r,uint32_t id)
{
    if(!r||!r->name||id<UINT32_C(0x600e0000)||id>=UINT32_C(0x600f0000))return true;
    const wchar_t *n=r->name,*text=NULL;uint64_t v=xx_var_get_u64(&r->value);
    if(sxt_wcontains(n,L"_words"))text=L"16-bit word units; byte count or offset = value * 2";
    else if(sxt_wcontains(n,L"_frames"))text=L"Sample frames; byte extent also depends on channel count and sample width";
    else if(sxt_wcontains(n,L"minus_one")||!xx_rt_wcscmp(n,L"last_pattern")||!xx_rt_wcscmp(n,L"last_order"))text=L"Stored as count minus one";
    else if(id==sxt_tracker_paragraph.id)text=L"16-byte paragraph index; file byte offset = value * 16";
    if((id==sxt_s3m_sample.id)&&(!xx_rt_wcscmp(n,L"data_paragraph_high")||!xx_rt_wcscmp(n,L"data_paragraph_low")))text=L"File offset = ((high << 16) | low) * 16";
    else if(!xx_rt_wcscmp(n,L"finetune_nibble"))text=L"Low four bits encode signed finetune -8..7";
    else if(id==sxt_xm_header.id&&!xx_rt_wcscmp(n,L"frequency_flags"))text=v?L"LINEAR_FREQUENCIES":L"AMIGA_FREQUENCIES";
    else if(id==sxt_xm_sample.id&&!xx_rt_wcscmp(n,L"flags"))text=L"Bits 0..1: no/forward/ping-pong loop; bit 4: 16-bit sample";
    else if(id==sxt_s3m_sample.id&&!xx_rt_wcscmp(n,L"flags"))text=L"Bit 0: loop; bit 1: stereo; bit 2: 16-bit sample";
    else if(id==sxt_s3m_header.id&&!xx_rt_wcscmp(n,L"sample_format"))text=v==1?L"SIGNED_PCM":v==2?L"UNSIGNED_PCM":NULL;
    else if(id==sxt_s3m_channel.id)text=L"0..7: left PCM; 8..15: right PCM; 255: disabled";
    else if(id==sxt_s3m_panning.id)text=L"Low nibble: panning; bit 5: use this panning value";
    else if(id==sxt_it_sample.id&&!xx_rt_wcscmp(n,L"flags"))text=L"Bits: 0 present, 1 16-bit, 2 stereo, 3 compressed, 4 loop, 5 sustain, 6/7 ping-pong";
    else if(id==sxt_dbm_sample_header.id&&!xx_rt_wcscmp(n,L"sample_format"))text=v==1?L"PCM8":v==2?L"PCM16_BIG_ENDIAN":v==4?L"PCM32_BIG_ENDIAN":NULL;
    else if(id==sxt_imf_channel.id&&!xx_rt_wcscmp(n,L"status"))text=v==0?L"ENABLED":v==1?L"MUTED":v==2?L"DISABLED":NULL;
    else if(id==sxt_imf_header.id&&!xx_rt_wcscmp(n,L"flags"))text=(v&1)?L"LINEAR_FREQUENCIES":L"AMIGA_FREQUENCIES";
    else if(id==sxt_imf_sample.id&&!xx_rt_wcscmp(n,L"flags"))text=L"Bit 0: loop; bit 1: bidirectional; bit 2: 16-bit; bit 3: default pan";
    else if(id==sxt_amf_track_header.id&&!xx_rt_wcscmp(n,L"unknown"))text=L"Unknown third header byte, ignored by native DSMI reader; not part of event count";
    else if(id==sxt_gdm_sample.id&&!xx_rt_wcscmp(n,L"loop_end_plus_one_frames"))text=L"Stored loop end is one beyond the effective frame end";
    else if(id==sxt_mod_event.id){if(!xx_rt_wcscmp(n,L"sample_high_period_high"))text=L"High nibble: sample high bits; low nibble: period high bits";else if(!xx_rt_wcscmp(n,L"sample_low_effect"))text=L"High nibble: sample low bits; low nibble: effect command";}
    else if(id==sxt_xm_envelope_control.id&&sxt_wcontains(n,L"_flags"))text=L"Bit 0: enabled; bit 1: sustain; bit 2: loop";
    return !text||xx_data_struct_record_set_comment(r,text);
}
