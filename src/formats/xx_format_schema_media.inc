/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical image, font and scientific structures. Wire references and reader
 * scope are listed in private_tests/data_structs/media_coverage.json.
 * Encoded pixels, glyph programs, arrays and uninterpreted metadata stay RAW_DATA.
 */
static const xx_data_struct_field_desc sxm_tga_header_fields[] = {
    SX_FIELD("id_length", "uint8", 0, 1, SX_SIZE),
    SX_FIELD("color_map_type", "uint8", 1, 1, SX_ID),
    SX_FIELD("image_type", "uint8", 2, 1, SX_ID),
    SX_FIELD("color_map_first_index", "uint16", 3, 2, SX_NONE),
    SX_FIELD("color_map_length", "uint16", 5, 2, SX_COUNT_PROP),
    SX_FIELD("color_map_entry_bits", "uint8", 7, 1, SX_NONE),
    SX_FIELD("x_origin", "uint16", 8, 2, SX_NONE),
    SX_FIELD("y_origin", "uint16", 10, 2, SX_NONE),
    SX_FIELD("width", "uint16", 12, 2, SX_NONE),
    SX_FIELD("height", "uint16", 14, 2, SX_NONE),
    SX_FIELD("pixel_depth_bits", "uint8", 16, 1, SX_NONE),
    SX_FIELD("image_descriptor", "uint8", 17, 1, SX_FLAGS),
};
static const sx_layout sxm_tga_header = {UINT32_C(0x60060001), "tga_header", sxm_tga_header_fields, SX_COUNT(sxm_tga_header_fields), SX_LE};

static const xx_data_struct_field_desc sxm_tga_footer_fields[] = {
    SX_FIELD("extension_area_offset", "uint32", 0, 4, SX_OFFSET),
    SX_FIELD("developer_directory_offset", "uint32", 4, 4, SX_OFFSET),
    SX_FIELD("signature", "char[18]", 8, 18, SX_SIGNATURE),
};
static const sx_layout sxm_tga_footer = {UINT32_C(0x60060002), "tga_footer", sxm_tga_footer_fields, SX_COUNT(sxm_tga_footer_fields), SX_LE};

static const xx_data_struct_field_desc sxm_pcx_header_fields[] = {
    SX_FIELD("manufacturer", "uint8", 0, 1, SX_SIGNATURE),
    SX_FIELD("version", "uint8", 1, 1, SX_NONE),
    SX_FIELD("encoding", "uint8", 2, 1, SX_ID),
    SX_FIELD("bits_per_pixel", "uint8", 3, 1, SX_NONE),
    SX_FIELD("xmin", "uint16", 4, 2, SX_NONE),
    SX_FIELD("ymin", "uint16", 6, 2, SX_NONE),
    SX_FIELD("xmax", "uint16", 8, 2, SX_NONE),
    SX_FIELD("ymax", "uint16", 10, 2, SX_NONE),
    SX_FIELD("horizontal_dpi", "uint16", 12, 2, SX_NONE),
    SX_FIELD("vertical_dpi", "uint16", 14, 2, SX_NONE),
    SX_FIELD("palette16", "uint8[48]", 16, 48, SX_NONE),
    SX_FIELD("reserved", "uint8", 64, 1, SX_RESERVED),
    SX_FIELD("color_planes", "uint8", 65, 1, SX_COUNT_PROP),
    SX_FIELD("bytes_per_line", "uint16", 66, 2, SX_SIZE),
    SX_FIELD("palette_info", "uint16", 68, 2, SX_ID),
    SX_FIELD("horizontal_screen_size", "uint16", 70, 2, SX_NONE),
    SX_FIELD("vertical_screen_size", "uint16", 72, 2, SX_NONE),
    SX_FIELD("filler", "uint8[54]", 74, 54, SX_RESERVED),
};
static const sx_layout sxm_pcx_header = {UINT32_C(0x60060003), "pcx_header", sxm_pcx_header_fields, SX_COUNT(sxm_pcx_header_fields), SX_LE};

static const xx_data_struct_field_desc sxm_dds_header_fields[] = {
    SX_FIELD("magic", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("size", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("flags", "uint32", 8, 4, SX_FLAGS),
    SX_FIELD("height", "uint32", 12, 4, SX_NONE),
    SX_FIELD("width", "uint32", 16, 4, SX_NONE),
    SX_FIELD("pitch_or_linear_size", "uint32", 20, 4, SX_SIZE),
    SX_FIELD("depth", "uint32", 24, 4, SX_NONE),
    SX_FIELD("mipmap_count", "uint32", 28, 4, SX_COUNT_PROP),
    SX_FIELD("reserved1", "uint32[11]", 32, 44, SX_RESERVED),
    SX_FIELD("pixel_format_size", "uint32", 76, 4, SX_SIZE),
    SX_FIELD("pixel_format_flags", "uint32", 80, 4, SX_FLAGS),
    SX_FIELD("fourcc", "uint32", 84, 4, SX_ID),
    SX_FIELD("rgb_bit_count", "uint32", 88, 4, SX_NONE),
    SX_FIELD("red_mask", "uint32", 92, 4, SX_FLAGS),
    SX_FIELD("green_mask", "uint32", 96, 4, SX_FLAGS),
    SX_FIELD("blue_mask", "uint32", 100, 4, SX_FLAGS),
    SX_FIELD("alpha_mask", "uint32", 104, 4, SX_FLAGS),
    SX_FIELD("caps", "uint32", 108, 4, SX_FLAGS),
    SX_FIELD("caps2", "uint32", 112, 4, SX_FLAGS),
    SX_FIELD("caps3", "uint32", 116, 4, SX_FLAGS),
    SX_FIELD("caps4", "uint32", 120, 4, SX_FLAGS),
    SX_FIELD("reserved2", "uint32", 124, 4, SX_RESERVED),
};
static const sx_layout sxm_dds_header = {UINT32_C(0x60060004), "dds_header", sxm_dds_header_fields, SX_COUNT(sxm_dds_header_fields), SX_LE};

static const xx_data_struct_field_desc sxm_dds_dx10_fields[] = {
    SX_FIELD("dxgi_format", "uint32", 0, 4, SX_ID),
    SX_FIELD("resource_dimension", "uint32", 4, 4, SX_ID),
    SX_FIELD("misc_flag", "uint32", 8, 4, SX_FLAGS),
    SX_FIELD("array_size", "uint32", 12, 4, SX_COUNT_PROP),
    SX_FIELD("misc_flags2", "uint32", 16, 4, SX_FLAGS),
};
static const sx_layout sxm_dds_dx10 = {UINT32_C(0x60060005), "dds_dx10", sxm_dds_dx10_fields, SX_COUNT(sxm_dds_dx10_fields), SX_LE};

static const xx_data_struct_field_desc sxm_psd_header_fields[] = {
    SX_FIELD("signature", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("version", "uint16", 4, 2, SX_ID),
    SX_FIELD("reserved", "bytes", 6, 6, SX_RESERVED),
    SX_FIELD("channels", "uint16", 12, 2, SX_COUNT_PROP),
    SX_FIELD("height", "uint32", 14, 4, SX_NONE),
    SX_FIELD("width", "uint32", 18, 4, SX_NONE),
    SX_FIELD("depth_bits", "uint16", 22, 2, SX_NONE),
    SX_FIELD("color_mode", "uint16", 24, 2, SX_ID),
};
static const sx_layout sxm_psd_header = {UINT32_C(0x60060006), "psd_header", sxm_psd_header_fields, SX_COUNT(sxm_psd_header_fields), SX_BE};

static const xx_data_struct_field_desc sxm_be_length32_fields[] = {
    SX_FIELD("length", "uint32", 0, 4, SX_SIZE),
};
static const sx_layout sxm_be_length32 = {UINT32_C(0x60060007), "be_length32", sxm_be_length32_fields, SX_COUNT(sxm_be_length32_fields), SX_BE};

static const xx_data_struct_field_desc sxm_be_length64_fields[] = {
    SX_FIELD("length", "uint64", 0, 8, SX_SIZE),
};
static const sx_layout sxm_be_length64 = {UINT32_C(0x60060008), "be_length64", sxm_be_length64_fields, SX_COUNT(sxm_be_length64_fields), SX_BE};

static const xx_data_struct_field_desc sxm_psd_compression_fields[] = {
    SX_FIELD("compression", "uint16", 0, 2, SX_ID),
};
static const sx_layout sxm_psd_compression = {UINT32_C(0x60060009), "psd_compression", sxm_psd_compression_fields, SX_COUNT(sxm_psd_compression_fields), SX_BE};

static const xx_data_struct_field_desc sxm_farbfeld_header_fields[] = {
    SX_FIELD("magic", "char[8]", 0, 8, SX_SIGNATURE),
    SX_FIELD("width", "uint32", 8, 4, SX_NONE),
    SX_FIELD("height", "uint32", 12, 4, SX_NONE),
};
static const sx_layout sxm_farbfeld_header = {UINT32_C(0x6006000A), "farbfeld_header", sxm_farbfeld_header_fields, SX_COUNT(sxm_farbfeld_header_fields), SX_BE};

static const xx_data_struct_field_desc sxm_sgi_header_fields[] = {
    SX_FIELD("magic", "uint16", 0, 2, SX_SIGNATURE),
    SX_FIELD("storage", "uint8", 2, 1, SX_ID),
    SX_FIELD("bytes_per_channel", "uint8", 3, 1, SX_SIZE),
    SX_FIELD("dimension", "uint16", 4, 2, SX_NONE),
    SX_FIELD("width", "uint16", 6, 2, SX_NONE),
    SX_FIELD("height", "uint16", 8, 2, SX_NONE),
    SX_FIELD("channels", "uint16", 10, 2, SX_COUNT_PROP),
    SX_FIELD("minimum_pixel_value", "uint32", 12, 4, SX_NONE),
    SX_FIELD("maximum_pixel_value", "uint32", 16, 4, SX_NONE),
    SX_FIELD("reserved1", "uint32", 20, 4, SX_RESERVED),
    SX_FIELD("image_name", "char[80]", 24, 80, SX_STRING),
    SX_FIELD("colormap", "uint32", 104, 4, SX_ID),
    SX_FIELD("reserved2", "bytes", 108, 404, SX_RESERVED),
};
static const sx_layout sxm_sgi_header = {UINT32_C(0x6006000B), "sgi_header", sxm_sgi_header_fields, SX_COUNT(sxm_sgi_header_fields), SX_BE};

static const xx_data_struct_field_desc sxm_be_offset32_fields[] = {
    SX_FIELD("offset", "uint32", 0, 4, SX_OFFSET),
};
static const sx_layout sxm_be_offset32 = {UINT32_C(0x6006000C), "be_offset32", sxm_be_offset32_fields, SX_COUNT(sxm_be_offset32_fields), SX_BE};

static const xx_data_struct_field_desc sxm_le_length32_fields[] = {
    SX_FIELD("length", "uint32", 0, 4, SX_SIZE),
};
static const sx_layout sxm_le_length32 = {UINT32_C(0x6006000D), "le_length32", sxm_le_length32_fields, SX_COUNT(sxm_le_length32_fields), SX_LE};

static const xx_data_struct_field_desc sxm_le_offset32_fields[] = {
    SX_FIELD("offset", "uint32", 0, 4, SX_OFFSET),
};
static const sx_layout sxm_le_offset32 = {UINT32_C(0x6006000E), "le_offset32", sxm_le_offset32_fields, SX_COUNT(sxm_le_offset32_fields), SX_LE};

static const xx_data_struct_field_desc sxm_sun_raster_header_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("width", "uint32", 4, 4, SX_NONE),
    SX_FIELD("height", "uint32", 8, 4, SX_NONE),
    SX_FIELD("depth_bits", "uint32", 12, 4, SX_NONE),
    SX_FIELD("data_length", "uint32", 16, 4, SX_SIZE),
    SX_FIELD("raster_type", "uint32", 20, 4, SX_ID),
    SX_FIELD("map_type", "uint32", 24, 4, SX_ID),
    SX_FIELD("map_length", "uint32", 28, 4, SX_SIZE),
};
static const sx_layout sxm_sun_raster_header = {UINT32_C(0x6006000F), "sun_raster_header", sxm_sun_raster_header_fields, SX_COUNT(sxm_sun_raster_header_fields), SX_BE};

static const xx_data_struct_field_desc sxm_avs_header_fields[] = {
    SX_FIELD("width", "uint32", 0, 4, SX_NONE),
    SX_FIELD("height", "uint32", 4, 4, SX_NONE),
};
static const sx_layout sxm_avs_header = {UINT32_C(0x60060010), "avs_header", sxm_avs_header_fields, SX_COUNT(sxm_avs_header_fields), SX_BE};

static const xx_data_struct_field_desc sxm_alias_pix_header_fields[] = {
    SX_FIELD("width", "uint16", 0, 2, SX_NONE),
    SX_FIELD("height", "uint16", 2, 2, SX_NONE),
    SX_FIELD("x_offset", "uint16", 4, 2, SX_NONE),
    SX_FIELD("y_offset", "uint16", 6, 2, SX_NONE),
    SX_FIELD("bits_per_pixel", "uint16", 8, 2, SX_NONE),
};
static const sx_layout sxm_alias_pix_header = {UINT32_C(0x60060011), "alias_pix_header", sxm_alias_pix_header_fields, SX_COUNT(sxm_alias_pix_header_fields), SX_BE};

static const xx_data_struct_field_desc sxm_astc_header_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("block_width", "uint8", 4, 1, SX_NONE),
    SX_FIELD("block_height", "uint8", 5, 1, SX_NONE),
    SX_FIELD("block_depth", "uint8", 6, 1, SX_NONE),
    SX_FIELD("width", "uint24", 7, 3, SX_NONE),
    SX_FIELD("height", "uint24", 10, 3, SX_NONE),
    SX_FIELD("depth", "uint24", 13, 3, SX_NONE),
};
static const sx_layout sxm_astc_header = {UINT32_C(0x60060012), "astc_header", sxm_astc_header_fields, SX_COUNT(sxm_astc_header_fields), SX_LE};

static const xx_data_struct_field_desc sxm_pkm_header_fields[] = {
    SX_FIELD("magic", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("version", "char[2]", 4, 2, SX_ID),
    SX_FIELD("texture_format", "uint16", 6, 2, SX_ID),
    SX_FIELD("encoded_width", "uint16", 8, 2, SX_NONE),
    SX_FIELD("encoded_height", "uint16", 10, 2, SX_NONE),
    SX_FIELD("width", "uint16", 12, 2, SX_NONE),
    SX_FIELD("height", "uint16", 14, 2, SX_NONE),
};
static const sx_layout sxm_pkm_header = {UINT32_C(0x60060013), "pkm_header", sxm_pkm_header_fields, SX_COUNT(sxm_pkm_header_fields), SX_BE};

static const xx_data_struct_field_desc sxm_ktx_header_le_fields[] = {
    SX_FIELD("identifier", "bytes", 0, 12, SX_SIGNATURE),
    SX_FIELD("endianness", "uint32", 12, 4, SX_ID),
    SX_FIELD("gl_type", "uint32", 16, 4, SX_ID),
    SX_FIELD("gl_type_size", "uint32", 20, 4, SX_SIZE),
    SX_FIELD("gl_format", "uint32", 24, 4, SX_ID),
    SX_FIELD("gl_internal_format", "uint32", 28, 4, SX_ID),
    SX_FIELD("gl_base_internal_format", "uint32", 32, 4, SX_ID),
    SX_FIELD("pixel_width", "uint32", 36, 4, SX_NONE),
    SX_FIELD("pixel_height", "uint32", 40, 4, SX_NONE),
    SX_FIELD("pixel_depth", "uint32", 44, 4, SX_NONE),
    SX_FIELD("array_elements", "uint32", 48, 4, SX_COUNT_PROP),
    SX_FIELD("faces", "uint32", 52, 4, SX_COUNT_PROP),
    SX_FIELD("mipmap_levels", "uint32", 56, 4, SX_COUNT_PROP),
    SX_FIELD("key_value_bytes", "uint32", 60, 4, SX_SIZE),
};
static const sx_layout sxm_ktx_header_le = {UINT32_C(0x60060014), "ktx_header_le", sxm_ktx_header_le_fields, SX_COUNT(sxm_ktx_header_le_fields), SX_LE};

static const xx_data_struct_field_desc sxm_ktx_header_be_fields[] = {
    SX_FIELD("identifier", "bytes", 0, 12, SX_SIGNATURE),
    SX_FIELD("endianness", "uint32", 12, 4, SX_ID),
    SX_FIELD("gl_type", "uint32", 16, 4, SX_ID),
    SX_FIELD("gl_type_size", "uint32", 20, 4, SX_SIZE),
    SX_FIELD("gl_format", "uint32", 24, 4, SX_ID),
    SX_FIELD("gl_internal_format", "uint32", 28, 4, SX_ID),
    SX_FIELD("gl_base_internal_format", "uint32", 32, 4, SX_ID),
    SX_FIELD("pixel_width", "uint32", 36, 4, SX_NONE),
    SX_FIELD("pixel_height", "uint32", 40, 4, SX_NONE),
    SX_FIELD("pixel_depth", "uint32", 44, 4, SX_NONE),
    SX_FIELD("array_elements", "uint32", 48, 4, SX_COUNT_PROP),
    SX_FIELD("faces", "uint32", 52, 4, SX_COUNT_PROP),
    SX_FIELD("mipmap_levels", "uint32", 56, 4, SX_COUNT_PROP),
    SX_FIELD("key_value_bytes", "uint32", 60, 4, SX_SIZE),
};
static const sx_layout sxm_ktx_header_be = {UINT32_C(0x60060015), "ktx_header_be", sxm_ktx_header_be_fields, SX_COUNT(sxm_ktx_header_be_fields), SX_BE};

static const xx_data_struct_field_desc sxm_ktx2_header_fields[] = {
    SX_FIELD("identifier", "bytes", 0, 12, SX_SIGNATURE),
    SX_FIELD("vk_format", "uint32", 12, 4, SX_ID),
    SX_FIELD("type_size", "uint32", 16, 4, SX_SIZE),
    SX_FIELD("pixel_width", "uint32", 20, 4, SX_NONE),
    SX_FIELD("pixel_height", "uint32", 24, 4, SX_NONE),
    SX_FIELD("pixel_depth", "uint32", 28, 4, SX_NONE),
    SX_FIELD("layer_count", "uint32", 32, 4, SX_COUNT_PROP),
    SX_FIELD("face_count", "uint32", 36, 4, SX_COUNT_PROP),
    SX_FIELD("level_count", "uint32", 40, 4, SX_COUNT_PROP),
    SX_FIELD("supercompression_scheme", "uint32", 44, 4, SX_ID),
    SX_FIELD("dfd_offset", "uint32", 48, 4, SX_OFFSET),
    SX_FIELD("dfd_length", "uint32", 52, 4, SX_SIZE),
    SX_FIELD("kvd_offset", "uint32", 56, 4, SX_OFFSET),
    SX_FIELD("kvd_length", "uint32", 60, 4, SX_SIZE),
    SX_FIELD("sgd_offset", "uint64", 64, 8, SX_OFFSET),
    SX_FIELD("sgd_length", "uint64", 72, 8, SX_SIZE),
};
static const sx_layout sxm_ktx2_header = {UINT32_C(0x60060016), "ktx2_header", sxm_ktx2_header_fields, SX_COUNT(sxm_ktx2_header_fields), SX_LE};

static const xx_data_struct_field_desc sxm_ktx2_level_fields[] = {
    SX_FIELD("byte_offset", "uint64", 0, 8, SX_OFFSET),
    SX_FIELD("byte_length", "uint64", 8, 8, SX_SIZE),
    SX_FIELD("uncompressed_byte_length", "uint64", 16, 8, SX_SIZE),
};
static const sx_layout sxm_ktx2_level = {UINT32_C(0x60060017), "ktx2_level", sxm_ktx2_level_fields, SX_COUNT(sxm_ktx2_level_fields), SX_LE};

static const xx_data_struct_field_desc sxm_pvr_header_le_fields[] = {
    SX_FIELD("version", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("flags", "uint32", 4, 4, SX_FLAGS),
    SX_FIELD("pixel_format", "uint64", 8, 8, SX_ID),
    SX_FIELD("color_space", "uint32", 16, 4, SX_ID),
    SX_FIELD("channel_type", "uint32", 20, 4, SX_ID),
    SX_FIELD("height", "uint32", 24, 4, SX_NONE),
    SX_FIELD("width", "uint32", 28, 4, SX_NONE),
    SX_FIELD("depth", "uint32", 32, 4, SX_NONE),
    SX_FIELD("surface_count", "uint32", 36, 4, SX_COUNT_PROP),
    SX_FIELD("face_count", "uint32", 40, 4, SX_COUNT_PROP),
    SX_FIELD("mipmap_count", "uint32", 44, 4, SX_COUNT_PROP),
    SX_FIELD("metadata_size", "uint32", 48, 4, SX_SIZE),
};
static const sx_layout sxm_pvr_header_le = {UINT32_C(0x60060018), "pvr_header_le", sxm_pvr_header_le_fields, SX_COUNT(sxm_pvr_header_le_fields), SX_LE};

static const xx_data_struct_field_desc sxm_pvr_metadata_le_fields[] = {
    SX_FIELD("fourcc", "uint32", 0, 4, SX_ID),
    SX_FIELD("key", "uint32", 4, 4, SX_ID),
    SX_FIELD("data_size", "uint32", 8, 4, SX_SIZE),
};
static const sx_layout sxm_pvr_metadata_le = {UINT32_C(0x60060019), "pvr_metadata_le", sxm_pvr_metadata_le_fields, SX_COUNT(sxm_pvr_metadata_le_fields), SX_LE};

static const xx_data_struct_field_desc sxm_pvr_header_be_fields[] = {
    SX_FIELD("version", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("flags", "uint32", 4, 4, SX_FLAGS),
    SX_FIELD("pixel_format", "uint64", 8, 8, SX_ID),
    SX_FIELD("color_space", "uint32", 16, 4, SX_ID),
    SX_FIELD("channel_type", "uint32", 20, 4, SX_ID),
    SX_FIELD("height", "uint32", 24, 4, SX_NONE),
    SX_FIELD("width", "uint32", 28, 4, SX_NONE),
    SX_FIELD("depth", "uint32", 32, 4, SX_NONE),
    SX_FIELD("surface_count", "uint32", 36, 4, SX_COUNT_PROP),
    SX_FIELD("face_count", "uint32", 40, 4, SX_COUNT_PROP),
    SX_FIELD("mipmap_count", "uint32", 44, 4, SX_COUNT_PROP),
    SX_FIELD("metadata_size", "uint32", 48, 4, SX_SIZE),
};
static const sx_layout sxm_pvr_header_be = {UINT32_C(0x6006001A), "pvr_header_be", sxm_pvr_header_be_fields, SX_COUNT(sxm_pvr_header_be_fields), SX_BE};

static const xx_data_struct_field_desc sxm_pvr_metadata_be_fields[] = {
    SX_FIELD("fourcc", "uint32", 0, 4, SX_ID),
    SX_FIELD("key", "uint32", 4, 4, SX_ID),
    SX_FIELD("data_size", "uint32", 8, 4, SX_SIZE),
};
static const sx_layout sxm_pvr_metadata_be = {UINT32_C(0x6006001B), "pvr_metadata_be", sxm_pvr_metadata_be_fields, SX_COUNT(sxm_pvr_metadata_be_fields), SX_BE};

static const xx_data_struct_field_desc sxm_gimp_gbr_header_fields[] = {
    SX_FIELD("header_size", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("version", "uint32", 4, 4, SX_ID),
    SX_FIELD("width", "uint32", 8, 4, SX_NONE),
    SX_FIELD("height", "uint32", 12, 4, SX_NONE),
    SX_FIELD("bytes_per_pixel", "uint32", 16, 4, SX_SIZE),
    SX_FIELD("magic", "char[4]", 20, 4, SX_SIGNATURE),
    SX_FIELD("spacing_percent", "uint32", 24, 4, SX_NONE),
};
static const sx_layout sxm_gimp_gbr_header = {UINT32_C(0x6006001C), "gimp_gbr_header", sxm_gimp_gbr_header_fields, SX_COUNT(sxm_gimp_gbr_header_fields), SX_BE};

static const xx_data_struct_field_desc sxm_gimp_pat_header_fields[] = {
    SX_FIELD("header_size", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("version", "uint32", 4, 4, SX_ID),
    SX_FIELD("width", "uint32", 8, 4, SX_NONE),
    SX_FIELD("height", "uint32", 12, 4, SX_NONE),
    SX_FIELD("bytes_per_pixel", "uint32", 16, 4, SX_SIZE),
    SX_FIELD("magic", "char[4]", 20, 4, SX_SIGNATURE),
};
static const sx_layout sxm_gimp_pat_header = {UINT32_C(0x6006001D), "gimp_pat_header", sxm_gimp_pat_header_fields, SX_COUNT(sxm_gimp_pat_header_fields), SX_BE};

static const xx_data_struct_field_desc sxm_icns_header_fields[] = {
    SX_FIELD("magic", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("file_size", "uint32", 4, 4, SX_SIZE),
};
static const sx_layout sxm_icns_header = {UINT32_C(0x6006001E), "icns_header", sxm_icns_header_fields, SX_COUNT(sxm_icns_header_fields), SX_BE};

static const xx_data_struct_field_desc sxm_icns_element_fields[] = {
    SX_FIELD("type", "char[4]", 0, 4, SX_ID),
    SX_FIELD("element_size", "uint32", 4, 4, SX_SIZE),
};
static const sx_layout sxm_icns_element = {UINT32_C(0x6006001F), "icns_element", sxm_icns_element_fields, SX_COUNT(sxm_icns_element_fields), SX_BE};

static const xx_data_struct_field_desc sxm_xwd_header_fields[] = {
    SX_FIELD("header_size", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("version", "uint32", 4, 4, SX_ID),
    SX_FIELD("pixmap_format", "uint32", 8, 4, SX_ID),
    SX_FIELD("pixmap_depth", "uint32", 12, 4, SX_NONE),
    SX_FIELD("pixmap_width", "uint32", 16, 4, SX_NONE),
    SX_FIELD("pixmap_height", "uint32", 20, 4, SX_NONE),
    SX_FIELD("x_offset", "uint32", 24, 4, SX_NONE),
    SX_FIELD("byte_order", "uint32", 28, 4, SX_ID),
    SX_FIELD("bitmap_unit", "uint32", 32, 4, SX_NONE),
    SX_FIELD("bitmap_bit_order", "uint32", 36, 4, SX_ID),
    SX_FIELD("bitmap_pad", "uint32", 40, 4, SX_NONE),
    SX_FIELD("bits_per_pixel", "uint32", 44, 4, SX_NONE),
    SX_FIELD("bytes_per_line", "uint32", 48, 4, SX_SIZE),
    SX_FIELD("visual_class", "uint32", 52, 4, SX_ID),
    SX_FIELD("red_mask", "uint32", 56, 4, SX_FLAGS),
    SX_FIELD("green_mask", "uint32", 60, 4, SX_FLAGS),
    SX_FIELD("blue_mask", "uint32", 64, 4, SX_FLAGS),
    SX_FIELD("bits_per_rgb", "uint32", 68, 4, SX_NONE),
    SX_FIELD("colormap_entries", "uint32", 72, 4, SX_COUNT_PROP),
    SX_FIELD("color_count", "uint32", 76, 4, SX_COUNT_PROP),
    SX_FIELD("window_width", "uint32", 80, 4, SX_NONE),
    SX_FIELD("window_height", "uint32", 84, 4, SX_NONE),
    SX_FIELD("window_x", "uint32", 88, 4, SX_NONE),
    SX_FIELD("window_y", "uint32", 92, 4, SX_NONE),
    SX_FIELD("window_border_width", "uint32", 96, 4, SX_NONE),
};
static const sx_layout sxm_xwd_header = {UINT32_C(0x60060020), "xwd_header", sxm_xwd_header_fields, SX_COUNT(sxm_xwd_header_fields), SX_BE};

static const xx_data_struct_field_desc sxm_xwd_color_fields[] = {
    SX_FIELD("pixel", "uint32", 0, 4, SX_NONE),
    SX_FIELD("red", "uint16", 4, 2, SX_NONE),
    SX_FIELD("green", "uint16", 6, 2, SX_NONE),
    SX_FIELD("blue", "uint16", 8, 2, SX_NONE),
    SX_FIELD("flags", "uint8", 10, 1, SX_FLAGS),
    SX_FIELD("pad", "uint8", 11, 1, SX_RESERVED),
};
static const sx_layout sxm_xwd_color = {UINT32_C(0x60060021), "xwd_color", sxm_xwd_color_fields, SX_COUNT(sxm_xwd_color_fields), SX_BE};

static const xx_data_struct_field_desc sxm_psf1_header_fields[] = {
    SX_FIELD("magic", "uint16", 0, 2, SX_SIGNATURE),
    SX_FIELD("mode", "uint8", 2, 1, SX_FLAGS),
    SX_FIELD("glyph_size", "uint8", 3, 1, SX_SIZE),
};
static const sx_layout sxm_psf1_header = {UINT32_C(0x60060022), "psf1_header", sxm_psf1_header_fields, SX_COUNT(sxm_psf1_header_fields), SX_LE};

static const xx_data_struct_field_desc sxm_psf2_header_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("version", "uint32", 4, 4, SX_ID),
    SX_FIELD("header_size", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("flags", "uint32", 12, 4, SX_FLAGS),
    SX_FIELD("glyph_count", "uint32", 16, 4, SX_COUNT_PROP),
    SX_FIELD("glyph_size", "uint32", 20, 4, SX_SIZE),
    SX_FIELD("height", "uint32", 24, 4, SX_NONE),
    SX_FIELD("width", "uint32", 28, 4, SX_NONE),
};
static const sx_layout sxm_psf2_header = {UINT32_C(0x60060023), "psf2_header", sxm_psf2_header_fields, SX_COUNT(sxm_psf2_header_fields), SX_LE};

static const xx_data_struct_field_desc sxm_pcf_header_fields[] = {
    SX_FIELD("magic", "bytes", 0, 4, SX_SIGNATURE),
    SX_FIELD("table_count", "uint32", 4, 4, SX_COUNT_PROP),
};
static const sx_layout sxm_pcf_header = {UINT32_C(0x60060024), "pcf_header", sxm_pcf_header_fields, SX_COUNT(sxm_pcf_header_fields), SX_LE};

static const xx_data_struct_field_desc sxm_pcf_directory_fields[] = {
    SX_FIELD("type", "uint32", 0, 4, SX_ID),
    SX_FIELD("format", "uint32", 4, 4, SX_FLAGS),
    SX_FIELD("size", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("offset", "uint32", 12, 4, SX_OFFSET),
};
static const sx_layout sxm_pcf_directory = {UINT32_C(0x60060025), "pcf_directory", sxm_pcf_directory_fields, SX_COUNT(sxm_pcf_directory_fields), SX_LE};

static const xx_data_struct_field_desc sxm_pfb_segment_fields[] = {
    SX_FIELD("marker", "uint8", 0, 1, SX_SIGNATURE),
    SX_FIELD("type", "uint8", 1, 1, SX_ID),
    SX_FIELD("length", "uint32", 2, 4, SX_SIZE),
};
static const sx_layout sxm_pfb_segment = {UINT32_C(0x60060026), "pfb_segment", sxm_pfb_segment_fields, SX_COUNT(sxm_pfb_segment_fields), SX_LE};

static const xx_data_struct_field_desc sxm_pfb_end_fields[] = {
    SX_FIELD("marker", "uint8", 0, 1, SX_SIGNATURE),
    SX_FIELD("type", "uint8", 1, 1, SX_ID),
};
static const sx_layout sxm_pfb_end = {UINT32_C(0x60060027), "pfb_end", sxm_pfb_end_fields, SX_COUNT(sxm_pfb_end_fields), SX_LE};

static const xx_data_struct_field_desc sxm_bmfont_header_fields[] = {
    SX_FIELD("magic", "char[3]", 0, 3, SX_SIGNATURE),
    SX_FIELD("version", "uint8", 3, 1, SX_ID),
};
static const sx_layout sxm_bmfont_header = {UINT32_C(0x60060028), "bmfont_header", sxm_bmfont_header_fields, SX_COUNT(sxm_bmfont_header_fields), SX_LE};

static const xx_data_struct_field_desc sxm_bmfont_block_fields[] = {
    SX_FIELD("type", "uint8", 0, 1, SX_ID),
    SX_FIELD("size", "uint32", 1, 4, SX_SIZE),
};
static const sx_layout sxm_bmfont_block = {UINT32_C(0x60060029), "bmfont_block", sxm_bmfont_block_fields, SX_COUNT(sxm_bmfont_block_fields), SX_LE};

static const xx_data_struct_field_desc sxm_bmfont_info_fields[] = {
    SX_FIELD("font_size", "int16", 0, 2, SX_NONE),
    SX_FIELD("bit_field", "uint8", 2, 1, SX_FLAGS),
    SX_FIELD("charset", "uint8", 3, 1, SX_ID),
    SX_FIELD("stretch_height_percent", "uint16", 4, 2, SX_NONE),
    SX_FIELD("antialiasing", "uint8", 6, 1, SX_NONE),
    SX_FIELD("padding_up", "uint8", 7, 1, SX_NONE),
    SX_FIELD("padding_right", "uint8", 8, 1, SX_NONE),
    SX_FIELD("padding_down", "uint8", 9, 1, SX_NONE),
    SX_FIELD("padding_left", "uint8", 10, 1, SX_NONE),
    SX_FIELD("spacing_horizontal", "uint8", 11, 1, SX_NONE),
    SX_FIELD("spacing_vertical", "uint8", 12, 1, SX_NONE),
    SX_FIELD("outline", "uint8", 13, 1, SX_NONE),
};
static const sx_layout sxm_bmfont_info = {UINT32_C(0x6006002A), "bmfont_info", sxm_bmfont_info_fields, SX_COUNT(sxm_bmfont_info_fields), SX_LE};

static const xx_data_struct_field_desc sxm_bmfont_common_fields[] = {
    SX_FIELD("line_height", "uint16", 0, 2, SX_NONE),
    SX_FIELD("base", "uint16", 2, 2, SX_NONE),
    SX_FIELD("scale_width", "uint16", 4, 2, SX_NONE),
    SX_FIELD("scale_height", "uint16", 6, 2, SX_NONE),
    SX_FIELD("pages", "uint16", 8, 2, SX_COUNT_PROP),
    SX_FIELD("bit_field", "uint8", 10, 1, SX_FLAGS),
    SX_FIELD("alpha_channel", "uint8", 11, 1, SX_NONE),
    SX_FIELD("red_channel", "uint8", 12, 1, SX_NONE),
    SX_FIELD("green_channel", "uint8", 13, 1, SX_NONE),
    SX_FIELD("blue_channel", "uint8", 14, 1, SX_NONE),
};
static const sx_layout sxm_bmfont_common = {UINT32_C(0x6006002B), "bmfont_common", sxm_bmfont_common_fields, SX_COUNT(sxm_bmfont_common_fields), SX_LE};

static const xx_data_struct_field_desc sxm_bmfont_char_fields[] = {
    SX_FIELD("id", "uint32", 0, 4, SX_ID),
    SX_FIELD("x", "uint16", 4, 2, SX_NONE),
    SX_FIELD("y", "uint16", 6, 2, SX_NONE),
    SX_FIELD("width", "uint16", 8, 2, SX_NONE),
    SX_FIELD("height", "uint16", 10, 2, SX_NONE),
    SX_FIELD("x_offset", "int16", 12, 2, SX_NONE),
    SX_FIELD("y_offset", "int16", 14, 2, SX_NONE),
    SX_FIELD("x_advance", "int16", 16, 2, SX_NONE),
    SX_FIELD("page", "uint8", 18, 1, SX_NONE),
    SX_FIELD("channel", "uint8", 19, 1, SX_FLAGS),
};
static const sx_layout sxm_bmfont_char = {UINT32_C(0x6006002C), "bmfont_char", sxm_bmfont_char_fields, SX_COUNT(sxm_bmfont_char_fields), SX_LE};

static const xx_data_struct_field_desc sxm_bmfont_kerning_fields[] = {
    SX_FIELD("first", "uint32", 0, 4, SX_ID),
    SX_FIELD("second", "uint32", 4, 4, SX_ID),
    SX_FIELD("amount", "int16", 8, 2, SX_NONE),
};
static const sx_layout sxm_bmfont_kerning = {UINT32_C(0x6006002D), "bmfont_kerning", sxm_bmfont_kerning_fields, SX_COUNT(sxm_bmfont_kerning_fields), SX_LE};

static const xx_data_struct_field_desc sxm_vlw_header_fields[] = {
    SX_FIELD("glyph_count", "uint32", 0, 4, SX_COUNT_PROP),
    SX_FIELD("version", "uint32", 4, 4, SX_ID),
    SX_FIELD("font_size", "uint32", 8, 4, SX_NONE),
    SX_FIELD("reserved", "uint32", 12, 4, SX_RESERVED),
    SX_FIELD("ascent", "uint32", 16, 4, SX_NONE),
    SX_FIELD("descent", "uint32", 20, 4, SX_NONE),
};
static const sx_layout sxm_vlw_header = {UINT32_C(0x6006002E), "vlw_header", sxm_vlw_header_fields, SX_COUNT(sxm_vlw_header_fields), SX_BE};

static const xx_data_struct_field_desc sxm_vlw_glyph_fields[] = {
    SX_FIELD("value", "uint32", 0, 4, SX_ID),
    SX_FIELD("height", "uint32", 4, 4, SX_NONE),
    SX_FIELD("width", "uint32", 8, 4, SX_NONE),
    SX_FIELD("set_width", "int32", 12, 4, SX_NONE),
    SX_FIELD("top_extent", "int32", 16, 4, SX_NONE),
    SX_FIELD("left_extent", "int32", 20, 4, SX_NONE),
    SX_FIELD("reserved", "uint32", 24, 4, SX_RESERVED),
};
static const sx_layout sxm_vlw_glyph = {UINT32_C(0x6006002F), "vlw_glyph", sxm_vlw_glyph_fields, SX_COUNT(sxm_vlw_glyph_fields), SX_BE};

static const xx_data_struct_field_desc sxm_npy_v1_fields[] = {
    SX_FIELD("magic", "bytes", 0, 6, SX_SIGNATURE),
    SX_FIELD("major", "uint8", 6, 1, SX_ID),
    SX_FIELD("minor", "uint8", 7, 1, SX_ID),
    SX_FIELD("header_length", "uint16", 8, 2, SX_SIZE),
};
static const sx_layout sxm_npy_v1 = {UINT32_C(0x60060030), "npy_v1", sxm_npy_v1_fields, SX_COUNT(sxm_npy_v1_fields), SX_LE};

static const xx_data_struct_field_desc sxm_npy_v2_fields[] = {
    SX_FIELD("magic", "bytes", 0, 6, SX_SIGNATURE),
    SX_FIELD("major", "uint8", 6, 1, SX_ID),
    SX_FIELD("minor", "uint8", 7, 1, SX_ID),
    SX_FIELD("header_length", "uint32", 8, 4, SX_SIZE),
};
static const sx_layout sxm_npy_v2 = {UINT32_C(0x60060031), "npy_v2", sxm_npy_v2_fields, SX_COUNT(sxm_npy_v2_fields), SX_LE};

static const xx_data_struct_field_desc sxm_nib_header_le_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("sequence_length", "uint32", 4, 4, SX_COUNT_PROP),
};
static const sx_layout sxm_nib_header_le = {UINT32_C(0x60060032), "nib_header_le", sxm_nib_header_le_fields, SX_COUNT(sxm_nib_header_le_fields), SX_LE};

static const xx_data_struct_field_desc sxm_nib_header_be_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("sequence_length", "uint32", 4, 4, SX_COUNT_PROP),
};
static const sx_layout sxm_nib_header_be = {UINT32_C(0x60060033), "nib_header_be", sxm_nib_header_be_fields, SX_COUNT(sxm_nib_header_be_fields), SX_BE};

static const xx_data_struct_field_desc sxm_scf_header_fields[] = {
    SX_FIELD("magic", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("samples", "uint32", 4, 4, SX_COUNT_PROP),
    SX_FIELD("samples_offset", "uint32", 8, 4, SX_OFFSET),
    SX_FIELD("bases", "uint32", 12, 4, SX_COUNT_PROP),
    SX_FIELD("left_clip", "uint32", 16, 4, SX_NONE),
    SX_FIELD("right_clip", "uint32", 20, 4, SX_NONE),
    SX_FIELD("bases_offset", "uint32", 24, 4, SX_OFFSET),
    SX_FIELD("comments_size", "uint32", 28, 4, SX_SIZE),
    SX_FIELD("comments_offset", "uint32", 32, 4, SX_OFFSET),
    SX_FIELD("version", "char[4]", 36, 4, SX_ID),
    SX_FIELD("sample_size", "uint32", 40, 4, SX_SIZE),
    SX_FIELD("code_set", "uint32", 44, 4, SX_ID),
    SX_FIELD("private_size", "uint32", 48, 4, SX_SIZE),
    SX_FIELD("private_offset", "uint32", 52, 4, SX_OFFSET),
    SX_FIELD("spare", "uint32[18]", 56, 72, SX_RESERVED),
};
static const sx_layout sxm_scf_header = {UINT32_C(0x60060034), "scf_header", sxm_scf_header_fields, SX_COUNT(sxm_scf_header_fields), SX_BE};

static const xx_data_struct_field_desc sxm_abif_header_fields[] = {
    SX_FIELD("magic", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("version", "uint16", 4, 2, SX_ID),
};
static const sx_layout sxm_abif_header = {UINT32_C(0x60060035), "abif_header", sxm_abif_header_fields, SX_COUNT(sxm_abif_header_fields), SX_BE};

static const xx_data_struct_field_desc sxm_abif_directory_fields[] = {
    SX_FIELD("tag_name", "char[4]", 0, 4, SX_ID),
    SX_FIELD("tag_number", "uint32", 4, 4, SX_ID),
    SX_FIELD("element_type", "uint16", 8, 2, SX_ID),
    SX_FIELD("element_size", "uint16", 10, 2, SX_SIZE),
    SX_FIELD("element_count", "uint32", 12, 4, SX_COUNT_PROP),
    SX_FIELD("data_size", "uint32", 16, 4, SX_SIZE),
    SX_FIELD("data_offset", "uint32", 20, 4, SX_OFFSET),
    SX_FIELD("data_handle", "uint32", 24, 4, SX_RESERVED),
};
static const sx_layout sxm_abif_directory = {UINT32_C(0x60060036), "abif_directory", sxm_abif_directory_fields, SX_COUNT(sxm_abif_directory_fields), SX_BE};

static const xx_data_struct_field_desc sxm_abif_inline_directory_fields[] = {
    SX_FIELD("tag_name", "char[4]", 0, 4, SX_ID),
    SX_FIELD("tag_number", "uint32", 4, 4, SX_ID),
    SX_FIELD("element_type", "uint16", 8, 2, SX_ID),
    SX_FIELD("element_size", "uint16", 10, 2, SX_SIZE),
    SX_FIELD("element_count", "uint32", 12, 4, SX_COUNT_PROP),
    SX_FIELD("data_size", "uint32", 16, 4, SX_SIZE),
    SX_FIELD("inline_data", "uint8[4]", 20, 4, SX_NONE),
    SX_FIELD("data_handle", "uint32", 24, 4, SX_RESERVED),
};
static const sx_layout sxm_abif_inline_directory = {UINT32_C(0x60060037), "abif_inline_directory", sxm_abif_inline_directory_fields, SX_COUNT(sxm_abif_inline_directory_fields), SX_BE};

static const xx_data_struct_field_desc sxm_sff_header_fields[] = {
    SX_FIELD("magic", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("version", "uint32", 4, 4, SX_ID),
    SX_FIELD("index_offset", "uint64", 8, 8, SX_OFFSET),
    SX_FIELD("index_length", "uint32", 16, 4, SX_SIZE),
    SX_FIELD("read_count", "uint32", 20, 4, SX_COUNT_PROP),
    SX_FIELD("header_length", "uint16", 24, 2, SX_SIZE),
    SX_FIELD("key_length", "uint16", 26, 2, SX_COUNT_PROP),
    SX_FIELD("flows_per_read", "uint16", 28, 2, SX_COUNT_PROP),
    SX_FIELD("flowgram_format_code", "uint8", 30, 1, SX_ID),
};
static const sx_layout sxm_sff_header = {UINT32_C(0x60060038), "sff_header", sxm_sff_header_fields, SX_COUNT(sxm_sff_header_fields), SX_BE};

static const xx_data_struct_field_desc sxm_sff_read_header_fields[] = {
    SX_FIELD("header_length", "uint16", 0, 2, SX_SIZE),
    SX_FIELD("name_length", "uint16", 2, 2, SX_SIZE),
    SX_FIELD("base_count", "uint32", 4, 4, SX_COUNT_PROP),
    SX_FIELD("clip_quality_left", "uint16", 8, 2, SX_NONE),
    SX_FIELD("clip_quality_right", "uint16", 10, 2, SX_NONE),
    SX_FIELD("clip_adapter_left", "uint16", 12, 2, SX_NONE),
    SX_FIELD("clip_adapter_right", "uint16", 14, 2, SX_NONE),
};
static const sx_layout sxm_sff_read_header = {UINT32_C(0x60060039), "sff_read_header", sxm_sff_read_header_fields, SX_COUNT(sxm_sff_read_header_fields), SX_BE};

static const xx_data_struct_field_desc sxm_mat4_header_le_fields[] = {
    SX_FIELD("mopt", "int32", 0, 4, SX_ID),
    SX_FIELD("rows", "int32", 4, 4, SX_COUNT_PROP),
    SX_FIELD("columns", "int32", 8, 4, SX_COUNT_PROP),
    SX_FIELD("imaginary", "int32", 12, 4, SX_FLAGS),
    SX_FIELD("name_length", "int32", 16, 4, SX_SIZE),
};
static const sx_layout sxm_mat4_header_le = {UINT32_C(0x6006003A), "mat4_header_le", sxm_mat4_header_le_fields, SX_COUNT(sxm_mat4_header_le_fields), SX_LE};

static const xx_data_struct_field_desc sxm_mat5_header_le_fields[] = {
    SX_FIELD("description", "char[116]", 0, 116, SX_STRING),
    SX_FIELD("subsystem_data_offset", "uint64", 116, 8, SX_OFFSET),
    SX_FIELD("version", "uint16", 124, 2, SX_ID),
    SX_FIELD("endian_indicator", "char[2]", 126, 2, SX_ID),
};
static const sx_layout sxm_mat5_header_le = {UINT32_C(0x6006003B), "mat5_header_le", sxm_mat5_header_le_fields, SX_COUNT(sxm_mat5_header_le_fields), SX_LE};

static const xx_data_struct_field_desc sxm_mat5_tag_le_fields[] = {
    SX_FIELD("data_type", "uint32", 0, 4, SX_ID),
    SX_FIELD("data_size", "uint32", 4, 4, SX_SIZE),
};
static const sx_layout sxm_mat5_tag_le = {UINT32_C(0x6006003C), "mat5_tag_le", sxm_mat5_tag_le_fields, SX_COUNT(sxm_mat5_tag_le_fields), SX_LE};

static const xx_data_struct_field_desc sxm_mat5_small_tag_le_fields[] = {
    SX_FIELD("type_and_length", "uint32", 0, 4, SX_FLAGS),
    SX_FIELD("inline_data", "uint8[4]", 4, 4, SX_NONE),
};
static const sx_layout sxm_mat5_small_tag_le = {UINT32_C(0x6006003D), "mat5_small_tag_le", sxm_mat5_small_tag_le_fields, SX_COUNT(sxm_mat5_small_tag_le_fields), SX_LE};

static const xx_data_struct_field_desc sxm_mat4_header_be_fields[] = {
    SX_FIELD("mopt", "int32", 0, 4, SX_ID),
    SX_FIELD("rows", "int32", 4, 4, SX_COUNT_PROP),
    SX_FIELD("columns", "int32", 8, 4, SX_COUNT_PROP),
    SX_FIELD("imaginary", "int32", 12, 4, SX_FLAGS),
    SX_FIELD("name_length", "int32", 16, 4, SX_SIZE),
};
static const sx_layout sxm_mat4_header_be = {UINT32_C(0x6006003E), "mat4_header_be", sxm_mat4_header_be_fields, SX_COUNT(sxm_mat4_header_be_fields), SX_BE};

static const xx_data_struct_field_desc sxm_mat5_header_be_fields[] = {
    SX_FIELD("description", "char[116]", 0, 116, SX_STRING),
    SX_FIELD("subsystem_data_offset", "uint64", 116, 8, SX_OFFSET),
    SX_FIELD("version", "uint16", 124, 2, SX_ID),
    SX_FIELD("endian_indicator", "char[2]", 126, 2, SX_ID),
};
static const sx_layout sxm_mat5_header_be = {UINT32_C(0x6006003F), "mat5_header_be", sxm_mat5_header_be_fields, SX_COUNT(sxm_mat5_header_be_fields), SX_BE};

static const xx_data_struct_field_desc sxm_mat5_tag_be_fields[] = {
    SX_FIELD("data_type", "uint32", 0, 4, SX_ID),
    SX_FIELD("data_size", "uint32", 4, 4, SX_SIZE),
};
static const sx_layout sxm_mat5_tag_be = {UINT32_C(0x60060040), "mat5_tag_be", sxm_mat5_tag_be_fields, SX_COUNT(sxm_mat5_tag_be_fields), SX_BE};

static const xx_data_struct_field_desc sxm_mat5_small_tag_be_fields[] = {
    SX_FIELD("type_and_length", "uint32", 0, 4, SX_FLAGS),
    SX_FIELD("inline_data", "uint8[4]", 4, 4, SX_NONE),
};
static const sx_layout sxm_mat5_small_tag_be = {UINT32_C(0x60060041), "mat5_small_tag_be", sxm_mat5_small_tag_be_fields, SX_COUNT(sxm_mat5_small_tag_be_fields), SX_BE};

static const xx_data_struct_field_desc sxm_hdf4_dd_block_fields[] = {
    SX_FIELD("descriptor_count", "uint16", 0, 2, SX_COUNT_PROP),
    SX_FIELD("next_block_offset", "uint32", 2, 4, SX_OFFSET),
};
static const sx_layout sxm_hdf4_dd_block = {UINT32_C(0x60060042), "hdf4_dd_block", sxm_hdf4_dd_block_fields, SX_COUNT(sxm_hdf4_dd_block_fields), SX_BE};

static const xx_data_struct_field_desc sxm_hdf4_descriptor_fields[] = {
    SX_FIELD("tag", "uint16", 0, 2, SX_ID),
    SX_FIELD("reference", "uint16", 2, 2, SX_ID),
    SX_FIELD("data_offset", "uint32", 4, 4, SX_OFFSET),
    SX_FIELD("data_length", "uint32", 8, 4, SX_SIZE),
};
static const sx_layout sxm_hdf4_descriptor = {UINT32_C(0x60060043), "hdf4_descriptor", sxm_hdf4_descriptor_fields, SX_COUNT(sxm_hdf4_descriptor_fields), SX_BE};

static const xx_data_struct_field_desc sxm_hdf4_first_block_fields[] = {
    SX_FIELD("signature", "bytes", 0, 4, SX_SIGNATURE),
    SX_FIELD("descriptor_count", "uint16", 4, 2, SX_COUNT_PROP),
    SX_FIELD("next_block_offset", "uint32", 6, 4, SX_OFFSET),
};
static const sx_layout sxm_hdf4_first_block = {UINT32_C(0x60060044), "hdf4_first_block", sxm_hdf4_first_block_fields, SX_COUNT(sxm_hdf4_first_block_fields), SX_BE};

static const sx_layout *const sx_media_layouts[] = {
    &sxm_tga_header,
    &sxm_tga_footer,
    &sxm_pcx_header,
    &sxm_dds_header,
    &sxm_dds_dx10,
    &sxm_psd_header,
    &sxm_be_length32,
    &sxm_be_length64,
    &sxm_psd_compression,
    &sxm_farbfeld_header,
    &sxm_sgi_header,
    &sxm_be_offset32,
    &sxm_le_length32,
    &sxm_le_offset32,
    &sxm_sun_raster_header,
    &sxm_avs_header,
    &sxm_alias_pix_header,
    &sxm_astc_header,
    &sxm_pkm_header,
    &sxm_ktx_header_le,
    &sxm_ktx_header_be,
    &sxm_ktx2_header,
    &sxm_ktx2_level,
    &sxm_pvr_header_le,
    &sxm_pvr_metadata_le,
    &sxm_pvr_header_be,
    &sxm_pvr_metadata_be,
    &sxm_gimp_gbr_header,
    &sxm_gimp_pat_header,
    &sxm_icns_header,
    &sxm_icns_element,
    &sxm_xwd_header,
    &sxm_xwd_color,
    &sxm_psf1_header,
    &sxm_psf2_header,
    &sxm_pcf_header,
    &sxm_pcf_directory,
    &sxm_pfb_segment,
    &sxm_pfb_end,
    &sxm_bmfont_header,
    &sxm_bmfont_block,
    &sxm_bmfont_info,
    &sxm_bmfont_common,
    &sxm_bmfont_char,
    &sxm_bmfont_kerning,
    &sxm_vlw_header,
    &sxm_vlw_glyph,
    &sxm_npy_v1,
    &sxm_npy_v2,
    &sxm_nib_header_le,
    &sxm_nib_header_be,
    &sxm_scf_header,
    &sxm_abif_header,
    &sxm_abif_directory,
    &sxm_abif_inline_directory,
    &sxm_sff_header,
    &sxm_sff_read_header,
    &sxm_mat4_header_le,
    &sxm_mat5_header_le,
    &sxm_mat5_tag_le,
    &sxm_mat5_small_tag_le,
    &sxm_mat4_header_be,
    &sxm_mat5_header_be,
    &sxm_mat5_tag_be,
    &sxm_mat5_small_tag_be,
    &sxm_hdf4_dd_block,
    &sxm_hdf4_descriptor,
    &sxm_hdf4_first_block,
};

static bool sxm_span(sx_context *c,uint64_t at,uint64_t n)
{
    if(at>INT64_MAX)return false;
    return sx_range(c,(int64_t)at,n);
}
static bool sxm_raw(sx_context *c,uint64_t at,uint64_t n)
{
    return n<=INT64_MAX&&sxm_span(c,at,n)&&sx_raw(c,(int64_t)at,(int64_t)n);
}
static bool sxm_tail(sx_context *c,uint64_t at)
{
    return at<=(uint64_t)c->size&&sxm_raw(c,at,(uint64_t)c->size-at);
}
static bool sxm_fixed(sx_context *c,const sx_layout *l,int64_t bytes)
{
    return sx_add(c,l,0,bytes)&&sxm_tail(c,(uint64_t)bytes);
}
static bool sxm_psd(sx_context *c,const uint8_t *h)
{
    uint64_t at=26,n;uint16_t version=xx_data_get_u16(h,26,4,true);
    if(xx_rt_memcmp(h,"8BPS",4)||(version!=1&&version!=2)||!sx_add(c,&sxm_psd_header,0,26))return false;
    for(unsigned i=0;i<3;i++){
        bool wide=i==2&&version==2;uint32_t small=0;
        if(wide){if(!sx_u64(c,(int64_t)at,true,&n))return false;}
        else{if(!sx_u32(c,(int64_t)at,true,&small))return false;n=small;}
        if(!sx_add(c,wide?&sxm_be_length64:&sxm_be_length32,(int64_t)at,wide?8:4))return false;
        at+=wide?8:4;if(!sxm_raw(c,at,n))return false;at+=n;
    }
    return sx_add(c,&sxm_psd_compression,(int64_t)at,2)&&sxm_tail(c,at+2);
}
static bool sxm_ktx(sx_context *c,const uint8_t *h)
{
    bool be=xx_data_get_u32(h,64,12,true)==UINT32_C(0x04030201);
    uint32_t meta,levels,faces,layers;uint64_t at=64,end;
    if(xx_rt_memcmp(h,"\xabKTX 11\xbb\r\n\x1a\n",12)||(!be&&xx_data_get_u32(h,64,12,false)!=UINT32_C(0x04030201)))return false;
    meta=xx_data_get_u32(h,64,60,be);levels=xx_data_get_u32(h,64,56,be);faces=xx_data_get_u32(h,64,52,be);layers=xx_data_get_u32(h,64,48,be);
    if(levels>32||(faces!=1&&faces!=6)||!sxm_span(c,at,meta)||!sx_add(c,be?&sxm_ktx_header_be:&sxm_ktx_header_le,0,64))return false;
    end=at+meta;
    while(at<end){uint32_t n;uint64_t padded;
        if(end-at<4||!sx_u32(c,(int64_t)at,be,&n)||!n)return false;padded=((uint64_t)n+3)&~UINT64_C(3);
        if(padded>end-at-4||!sx_add(c,be?&sxm_be_length32:&sxm_le_length32,(int64_t)at,4)||!sxm_raw(c,at+4,padded))return false;at+=4+padded;
    }
    if(!levels)levels=1;
    for(uint32_t i=0;i<levels;i++){uint32_t n,parts=faces==6&&!layers?6:1;uint64_t padded;
        if(!sx_u32(c,(int64_t)at,be,&n)||!n||!sx_add(c,be?&sxm_be_length32:&sxm_le_length32,(int64_t)at,4))return false;
        at+=4;padded=((uint64_t)n+3)&~UINT64_C(3);
        if(!sxm_raw(c,at,padded*parts))return false;at+=padded*parts;
    }
    return sxm_tail(c,at);
}
static bool sxm_ktx2(sx_context *c,const uint8_t *h)
{
    uint32_t levels=xx_data_get_u32(h,80,40,false);uint64_t at;
    if(xx_rt_memcmp(h,"\xabKTX 20\xbb\r\n\x1a\n",12)||levels>32)return false;
    if(!levels)levels=1;
    if(!sx_add(c,&sxm_ktx2_header,0,80)||!sx_table(c,&sxm_ktx2_level,80,24,levels))return false;
    at=80+(uint64_t)levels*24;
    for(uint32_t i=0;i<levels;i++){uint64_t off,n;if(!sx_u64(c,80+(int64_t)i*24,false,&off)||!sx_u64(c,88+(int64_t)i*24,false,&n)||!sxm_span(c,off,n))return false;}
    for(unsigned i=48;i<=56;i+=8){uint32_t off=xx_data_get_u32(h,80,i,false),n=xx_data_get_u32(h,80,i+4,false);if(n&&!sxm_span(c,off,n))return false;}
    if(!sxm_span(c,xx_data_get_u64(h,80,64,false),xx_data_get_u64(h,80,72,false)))return false;
    return sxm_tail(c,at);
}
static bool sxm_pvr(sx_context *c,const uint8_t *h)
{
    bool be=xx_data_get_u32(h,52,0,true)==UINT32_C(0x03525650);uint64_t at=52,end;uint32_t meta;
    if(!be&&xx_data_get_u32(h,52,0,false)!=UINT32_C(0x03525650))return false;
    meta=xx_data_get_u32(h,52,48,be);if(!sxm_span(c,52,meta)||!sx_add(c,be?&sxm_pvr_header_be:&sxm_pvr_header_le,0,52))return false;end=52+(uint64_t)meta;
    while(at<end){uint32_t n;if(end-at<12||!sx_u32(c,(int64_t)at+8,be,&n)||n>end-at-12||!sx_add(c,be?&sxm_pvr_metadata_be:&sxm_pvr_metadata_le,(int64_t)at,12)||!sxm_raw(c,at+12,n))return false;at+=12+(uint64_t)n;}
    return sxm_tail(c,at);
}
static bool sxm_icns(sx_context *c,const uint8_t *h)
{
    uint64_t at=8,end=xx_data_get_u32(h,8,4,true);
    if(xx_rt_memcmp(h,"icns",4)||end<8||!sxm_span(c,0,end)||!sx_add(c,&sxm_icns_header,0,8))return false;
    while(at<end){uint32_t n;if(end-at<8||!sx_u32(c,(int64_t)at+4,true,&n)||n<8||n>end-at||!sx_add(c,&sxm_icns_element,(int64_t)at,8)||!sxm_raw(c,at+8,n-8))return false;at+=n;}
    return sxm_tail(c,end);
}
static bool sxm_pcf(sx_context *c,const uint8_t *h)
{
    uint32_t count=xx_data_get_u32(h,8,4,false);uint64_t first=8+(uint64_t)count*16;
    if(xx_rt_memcmp(h,"\1fcp",4)||!count||count>9||!sx_add(c,&sxm_pcf_header,0,8)||!sx_table(c,&sxm_pcf_directory,8,16,count))return false;
    for(uint32_t i=0;i<count;i++){
        uint8_t e[16];uint64_t at,n;uint32_t type,fmt;
        if(!sx_read(c,8+(int64_t)i*16,e,16))return false;
        type=xx_data_get_u32(e,16,0,false);fmt=xx_data_get_u32(e,16,4,false);n=xx_data_get_u32(e,16,8,false);at=xx_data_get_u32(e,16,12,false);
        /* Historic bdftopcf declares 100 bytes but writes a 72-byte EOF accelerator. */
        if(at<=(uint64_t)c->size&&n>(uint64_t)c->size-at&&i+1==count&&(type==2||type==256)&&(fmt&256)&&n==100&&(uint64_t)c->size-at==72)n=72;
        if(at<first||!sxm_span(c,at,n))return false;
    }
    return sxm_tail(c,first);
}
static bool sxm_pfb(sx_context *c)
{
    uint64_t at=0;
    while(at<(uint64_t)c->size){uint8_t h[6];uint32_t n;
        if(!sx_read(c,(int64_t)at,h,2)||h[0]!=128)return false;
        if(h[1]==3)return sx_add(c,&sxm_pfb_end,(int64_t)at,2)&&sxm_tail(c,at+2);
        if((h[1]!=1&&h[1]!=2)||!sx_read(c,(int64_t)at,h,6))return false;n=xx_data_get_u32(h,6,2,false);
        if(!n||!sx_add(c,&sxm_pfb_segment,(int64_t)at,6)||!sxm_raw(c,at+6,n))return false;at+=6+(uint64_t)n;
    }
    return false;
}
static bool sxm_bmfont(sx_context *c,const uint8_t *h)
{
    uint64_t at=4;
    if(xx_rt_memcmp(h,"BMF\3",4)||!sx_add(c,&sxm_bmfont_header,0,4))return false;
    while(at<(uint64_t)c->size){uint8_t b[5];uint32_t n;uint64_t data;
        if(!sx_read(c,(int64_t)at,b,5))return false;n=xx_data_get_u32(b,5,1,false);data=at+5;
        if(!sxm_span(c,data,n)||!sx_add(c,&sxm_bmfont_block,(int64_t)at,5))return false;
        if(b[0]==1){if(n<14||!sx_add(c,&sxm_bmfont_info,(int64_t)data,14)||!sxm_raw(c,data+14,n-14))return false;}
        else if(b[0]==2){if(n!=15||!sx_add(c,&sxm_bmfont_common,(int64_t)data,15))return false;}
        else if(b[0]==4){if(n%20||!sx_table(c,&sxm_bmfont_char,(int64_t)data,20,n/20))return false;}
        else if(b[0]==5){if(n%10||!sx_table(c,&sxm_bmfont_kerning,(int64_t)data,10,n/10))return false;}
        else if(!sxm_raw(c,data,n))return false;
        at=data+n;
    }
    return true;
}
static bool sxm_abif(sx_context *c,const uint8_t *h)
{
    uint32_t count=xx_data_get_u32(h,34,18,true),bytes=xx_data_get_u32(h,34,22,true),off=xx_data_get_u32(h,34,26,true);uint64_t end;
    if(xx_rt_memcmp(h,"ABIF",4)||xx_rt_memcmp(h+6,"tdir",4)||!count||count>4096||bytes<(uint64_t)count*28||off<34||!sxm_span(c,off,bytes)||!sx_add(c,&sxm_abif_header,0,6)||!sx_add(c,&sxm_abif_directory,6,28)||!sxm_raw(c,34,off-34))return false;
    for(uint32_t i=0;i<count;i++){uint64_t at=off+(uint64_t)i*28;uint32_t n,pos;
        if(!sx_u32(c,(int64_t)at+16,true,&n)||!sx_u32(c,(int64_t)at+20,true,&pos)||!sx_add(c,n<=4?&sxm_abif_inline_directory:&sxm_abif_directory,(int64_t)at,28))return false;
        if(n>4&&!sxm_span(c,pos,n))return false;
    }
    end=off+(uint64_t)count*28;
    return sxm_tail(c,end);
}
static bool sxm_sff(sx_context *c,const uint8_t *h)
{
    uint64_t index=xx_data_get_u64(h,31,8,true),index_size=xx_data_get_u32(h,31,16,true),at=xx_data_get_u16(h,31,24,true);uint32_t count=xx_data_get_u32(h,31,20,true),flows=xx_data_get_u16(h,31,28,true);
    if(xx_rt_memcmp(h,".sff",4)||!count||count>512||at<31||!sxm_span(c,index,index_size)||!sx_add(c,&sxm_sff_header,0,31)||!sxm_raw(c,31,at-31))return false;
    for(uint32_t i=0;i<count;i++){
        uint8_t b[16];uint32_t header,n;uint64_t data;
        if(index&&at==index){uint64_t padded=(index_size+7)&~UINT64_C(7);if(!sxm_raw(c,at,padded))return false;at+=padded;}
        if(!sx_read(c,(int64_t)at,b,16))return false;header=xx_data_get_u16(b,16,0,true);n=xx_data_get_u32(b,16,4,true);
        if(header<16||!sx_add(c,&sxm_sff_read_header,(int64_t)at,16)||!sxm_raw(c,at+16,header-16))return false;at+=header;
        data=((uint64_t)flows*2+(uint64_t)n*3+7)&~UINT64_C(7);
        if(!sxm_raw(c,at,data))return false;at+=data;
    }
    return sxm_tail(c,at);
}
static bool sxm_mat4(sx_context *c)
{
    uint64_t at=0;static const unsigned widths[]={8,4,4,2,2,1};
    while(at<(uint64_t)c->size){uint8_t h[20];uint32_t type,rows,cols,imag,names;bool be;uint64_t n;
        if(!sx_read(c,(int64_t)at,h,20))return false;type=xx_data_get_u32(h,20,0,false);be=type>1999;if(be)type=xx_data_get_u32(h,20,0,true);
        rows=xx_data_get_u32(h,20,4,be);cols=xx_data_get_u32(h,20,8,be);imag=xx_data_get_u32(h,20,12,be);names=xx_data_get_u32(h,20,16,be);
        if(type>1999||type/1000!=(be?1U:0U)||(type/100)%10||type%10>1||(type/10)%10>=6||imag>1||!rows||!cols||rows>1000000||cols>1000000||names<2||names>256)return false;
        n=(uint64_t)rows*cols;if(n>1000000)return false;n=n*widths[(type/10)%10]*(1+imag);
        if(!sx_add(c,be?&sxm_mat4_header_be:&sxm_mat4_header_le,(int64_t)at,20)||!sxm_raw(c,at+20,names)||!sxm_raw(c,at+20+names,n))return false;at+=20+names+n;
    }
    return at!=0;
}
static bool sxm_mat5_tags(sx_context *c,uint64_t at,uint64_t end,bool be,unsigned depth)
{
    if(depth>8)return false;
    while(at<end){uint32_t type,n;uint64_t data,next;
        if(end-at<8||!sx_u32(c,(int64_t)at,be,&type))return false;
        /* miCOMPRESSED has no 8-byte padding and is outside native reader scope. */
        if((type&UINT32_C(0xffff))==15)return false;
        if(type>>16){n=type>>16;if(n>4||!sx_add(c,be?&sxm_mat5_small_tag_be:&sxm_mat5_small_tag_le,(int64_t)at,8))return false;next=at+8;}
        else{if(!sx_u32(c,(int64_t)at+4,be,&n))return false;data=at+8;next=data+(((uint64_t)n+7)&~UINT64_C(7));if(next>end||!sx_add(c,be?&sxm_mat5_tag_be:&sxm_mat5_tag_le,(int64_t)at,8))return false;
            if(type==14){if(!sxm_mat5_tags(c,data,data+n,be,depth+1)||!sxm_raw(c,data+n,next-data-n))return false;}
            else if(!sxm_raw(c,data,next-data))return false;
        }
        at=next;
    }
    return at==end;
}
static bool sxm_hdf4(sx_context *c,const uint8_t *h)
{
    uint32_t at=4,seen[1024];unsigned blocks=0;
    if(xx_rt_memcmp(h,"\x0e\x03\x13\x01",4))return false;
    while(at){uint16_t count;uint32_t next;
        if(blocks==1024)return false;
        for(unsigned i=0;i<blocks;i++)if(seen[i]==at)return false;seen[blocks++]=at;
        if(!sx_u16(c,at,true,&count)||!sx_u32(c,(int64_t)at+2,true,&next)||!count||count>4096)return false;
        if(at==4){if(!sx_add(c,&sxm_hdf4_first_block,0,10))return false;}else if(!sx_add(c,&sxm_hdf4_dd_block,at,6))return false;
        if(!sx_table(c,&sxm_hdf4_descriptor,(int64_t)at+6,12,count))return false;
        for(unsigned i=0;i<count;i++){uint8_t e[12];uint32_t off,n;if(!sx_read(c,(int64_t)at+6+(int64_t)i*12,e,12))return false;
            if(xx_data_get_u16(e,12,0,true)==1)continue;off=xx_data_get_u32(e,12,4,true);n=xx_data_get_u32(e,12,8,true);if(!sxm_raw(c,off,n))return false;}
        at=next;
    }
    return true;
}
static bool sx_media_supports(xx_file_type_t t)
{
    switch(t){
    case XX_FILE_TYPE_TGA:case XX_FILE_TYPE_PCX:case XX_FILE_TYPE_DDS:case XX_FILE_TYPE_PHOTOSHOP_PSD:case XX_FILE_TYPE_FARBFELD:case XX_FILE_TYPE_SGI_RGB:case XX_FILE_TYPE_SUN_RASTER:case XX_FILE_TYPE_AVS_IMAGE:case XX_FILE_TYPE_ALIAS_PIX:case XX_FILE_TYPE_ASTC_TEXTURE:case XX_FILE_TYPE_PKM_TEXTURE:case XX_FILE_TYPE_KTX:case XX_FILE_TYPE_KTX2:case XX_FILE_TYPE_PVR:case XX_FILE_TYPE_GIMP_GBR:case XX_FILE_TYPE_GIMP_PAT:case XX_FILE_TYPE_ICNS:case XX_FILE_TYPE_XWD:
    case XX_FILE_TYPE_FONT_PSF:case XX_FILE_TYPE_FONT_PCF:case XX_FILE_TYPE_FONT_TYPE1_PFB:case XX_FILE_TYPE_FONT_BMFONT:case XX_FILE_TYPE_PROCESSING_VLW:
    case XX_FILE_TYPE_NUMPY_NPY:case XX_FILE_TYPE_UCSC_NIB:case XX_FILE_TYPE_SEQUENCING_SCF:case XX_FILE_TYPE_SEQUENCING_ABIF:case XX_FILE_TYPE_GENOMICS_SFF:case XX_FILE_TYPE_MATLAB_MAT4:case XX_FILE_TYPE_MATLAB_MAT5:case XX_FILE_TYPE_HDF4:return true;
    default:return false;
    }
}
static bool sx_media_build(sx_context *c)
{
    uint8_t h[128]={0};size_t n;
    if(!c||!c->f||c->size<=0)return false;n=(uint64_t)c->size<sizeof(h)?(size_t)c->size:sizeof(h);if(!sx_read(c,0,h,n))return false;
    switch(c->f->file_type){
    case XX_FILE_TYPE_TGA:{uint8_t footer[26];if(c->size<44||!sx_read(c,c->size-26,footer,26)||xx_rt_memcmp(footer+8,"TRUEVISION-XFILE.\0",18))return false;return sx_add(c,&sxm_tga_header,0,18)&&sxm_raw(c,18,(uint64_t)c->size-44)&&sx_add(c,&sxm_tga_footer,c->size-26,26);}
    case XX_FILE_TYPE_PCX:return h[0]==10&&sxm_fixed(c,&sxm_pcx_header,128);
    case XX_FILE_TYPE_DDS:if(n<128||xx_rt_memcmp(h,"DDS ",4)||xx_data_get_u32(h,128,4,false)!=124||xx_data_get_u32(h,128,76,false)!=32||!sx_add(c,&sxm_dds_header,0,128))return false;if(!xx_rt_memcmp(h+84,"DX10",4))return sx_add(c,&sxm_dds_dx10,128,20)&&sxm_tail(c,148);return sxm_tail(c,128);
    case XX_FILE_TYPE_PHOTOSHOP_PSD:return n>=26&&sxm_psd(c,h);
    case XX_FILE_TYPE_FARBFELD:return n>=16&&!xx_rt_memcmp(h,"farbfeld",8)&&sxm_fixed(c,&sxm_farbfeld_header,16);
    case XX_FILE_TYPE_SGI_RGB:{uint64_t at=512,rows;if(n<108||xx_data_get_u16(h,n,0,true)!=474||!sx_add(c,&sxm_sgi_header,0,512))return false;if(h[2]==1){rows=(uint64_t)xx_data_get_u16(h,n,8,true)*xx_data_get_u16(h,n,10,true);if(!rows||!sx_table(c,&sxm_be_offset32,512,4,rows)||!sx_table(c,&sxm_be_length32,512+(int64_t)rows*4,4,rows))return false;for(uint64_t i=0;i<rows;i++){uint32_t off,z;if(!sx_u32(c,512+(int64_t)i*4,true,&off)||!sx_u32(c,512+(int64_t)(rows+i)*4,true,&z)||!sxm_span(c,off,z))return false;}at+=rows*8;}return sxm_tail(c,at);}
    case XX_FILE_TYPE_SUN_RASTER:return n>=32&&xx_data_get_u32(h,n,0,true)==UINT32_C(0x59a66a95)&&sxm_fixed(c,&sxm_sun_raster_header,32);
    case XX_FILE_TYPE_AVS_IMAGE:return n>=8&&xx_data_get_u32(h,n,0,true)&&xx_data_get_u32(h,n,4,true)&&sxm_fixed(c,&sxm_avs_header,8);
    case XX_FILE_TYPE_ALIAS_PIX:return n>=10&&sxm_fixed(c,&sxm_alias_pix_header,10);
    case XX_FILE_TYPE_ASTC_TEXTURE:return n>=16&&!xx_rt_memcmp(h,"\x13\xab\xa1\x5c",4)&&sxm_fixed(c,&sxm_astc_header,16);
    case XX_FILE_TYPE_PKM_TEXTURE:return n>=16&&(!xx_rt_memcmp(h,"PKM 10",6)||!xx_rt_memcmp(h,"PKM 20",6))&&sxm_fixed(c,&sxm_pkm_header,16);
    case XX_FILE_TYPE_KTX:return n>=64&&sxm_ktx(c,h);
    case XX_FILE_TYPE_KTX2:return n>=80&&sxm_ktx2(c,h);
    case XX_FILE_TYPE_PVR:return n>=52&&sxm_pvr(c,h);
    case XX_FILE_TYPE_GIMP_GBR:case XX_FILE_TYPE_GIMP_PAT:{bool pat=c->f->file_type==XX_FILE_TYPE_GIMP_PAT;uint32_t fixed=pat?24:28,header;if(n<fixed||xx_rt_memcmp(h+20,pat?"GPAT":"GIMP",4))return false;header=xx_data_get_u32(h,n,0,true);return header>=fixed&&sxm_span(c,0,header)&&sxm_fixed(c,pat?&sxm_gimp_pat_header:&sxm_gimp_gbr_header,fixed);}
    case XX_FILE_TYPE_ICNS:return n>=8&&sxm_icns(c,h);
    case XX_FILE_TYPE_XWD:{uint32_t header,count;if(n<100||xx_data_get_u32(h,n,4,true)!=7)return false;header=xx_data_get_u32(h,n,0,true);count=xx_data_get_u32(h,n,76,true);return header>=100&&sx_add(c,&sxm_xwd_header,0,100)&&sxm_raw(c,100,header-100)&&sx_table(c,&sxm_xwd_color,header,12,count)&&sxm_tail(c,header+(uint64_t)count*12);}
    case XX_FILE_TYPE_FONT_PSF:if(n>=4&&h[0]==0x36&&h[1]==4)return sxm_fixed(c,&sxm_psf1_header,4);return n>=32&&xx_data_get_u32(h,n,0,false)==UINT32_C(0x864ab572)&&sxm_fixed(c,&sxm_psf2_header,32);
    case XX_FILE_TYPE_FONT_PCF:return n>=8&&sxm_pcf(c,h);
    case XX_FILE_TYPE_FONT_TYPE1_PFB:return sxm_pfb(c);
    case XX_FILE_TYPE_FONT_BMFONT:return n>=4&&sxm_bmfont(c,h);
    case XX_FILE_TYPE_PROCESSING_VLW:{uint32_t count;if(n<24||xx_data_get_u32(h,n,4,true)!=11)return false;count=xx_data_get_u32(h,n,0,true);return count&&count<=4092&&sx_add(c,&sxm_vlw_header,0,24)&&sx_table(c,&sxm_vlw_glyph,24,28,count)&&sxm_tail(c,24+(uint64_t)count*28);}
    case XX_FILE_TYPE_NUMPY_NPY:{uint32_t prefix,len;if(n<10||xx_rt_memcmp(h,"\x93NUMPY",6)||h[6]<1||h[6]>3||h[7])return false;prefix=h[6]==1?10:12;if(n<prefix)return false;len=prefix==10?xx_data_get_u16(h,n,8,false):xx_data_get_u32(h,n,8,false);return sxm_span(c,prefix,len)&&sxm_fixed(c,prefix==10?&sxm_npy_v1:&sxm_npy_v2,prefix);}
    case XX_FILE_TYPE_UCSC_NIB:{bool be;if(n<8)return false;be=xx_data_get_u32(h,n,0,true)==UINT32_C(0x6be93d3a);if(!be&&xx_data_get_u32(h,n,0,false)!=UINT32_C(0x6be93d3a))return false;return sxm_span(c,8,((uint64_t)xx_data_get_u32(h,n,4,be)+1)/2)&&sxm_fixed(c,be?&sxm_nib_header_be:&sxm_nib_header_le,8);}
    case XX_FILE_TYPE_SEQUENCING_SCF:{uint32_t samples,bases,width;if(n<128||xx_rt_memcmp(h,".scf",4))return false;samples=xx_data_get_u32(h,n,4,true);bases=xx_data_get_u32(h,n,12,true);width=xx_data_get_u32(h,n,40,true);
        if((width!=1&&width!=2)||!sxm_span(c,xx_data_get_u32(h,n,8,true),(uint64_t)samples*4*width)||!sxm_span(c,xx_data_get_u32(h,n,24,true),(uint64_t)bases*12)||!sxm_span(c,xx_data_get_u32(h,n,32,true),xx_data_get_u32(h,n,28,true))||!sxm_span(c,xx_data_get_u32(h,n,52,true),xx_data_get_u32(h,n,48,true)))return false;
        return sxm_fixed(c,&sxm_scf_header,128); }
    case XX_FILE_TYPE_SEQUENCING_ABIF:return n>=34&&sxm_abif(c,h);
    case XX_FILE_TYPE_GENOMICS_SFF:return n>=31&&sxm_sff(c,h);
    case XX_FILE_TYPE_MATLAB_MAT4:return sxm_mat4(c);
    case XX_FILE_TYPE_MATLAB_MAT5:{bool be;if(n<128||xx_rt_memcmp(h,"MATLAB 5.0 MAT-file",19))return false;be=!xx_rt_memcmp(h+126,"MI",2);if(!be&&xx_rt_memcmp(h+126,"IM",2))return false;return sx_add(c,be?&sxm_mat5_header_be:&sxm_mat5_header_le,0,128)&&sxm_mat5_tags(c,128,(uint64_t)c->size,be,0);}
    case XX_FILE_TYPE_HDF4:return n>=10&&sxm_hdf4(c,h);
    default:return false;
    }
}
static bool sx_media_comment(xx_data_struct_record *r,uint32_t id)
{
    const wchar_t *s=NULL;uint64_t v;
    if(!r||!r->name||id<UINT32_C(0x60060000)||id>UINT32_C(0x6006ffff))return true;v=xx_var_get_u64(&r->value);
    if(id==sxm_tga_header.id&&!xx_rt_wcscmp(r->name,L"image_type"))s=v==1?L"Color mapped":v==2?L"True color":v==3?L"Grayscale":v==9?L"RLE color mapped":v==10?L"RLE true color":v==11?L"RLE grayscale":NULL;
    else if(id==sxm_psd_compression.id)s=v==0?L"Raw":v==1?L"PackBits RLE":v==2?L"ZIP":v==3?L"ZIP with prediction":NULL;
    else if(id==sxm_sgi_header.id&&!xx_rt_wcscmp(r->name,L"storage"))s=v==0?L"Verbatim":v==1?L"Run length encoding":NULL;
    else if((id==sxm_mat5_small_tag_le.id||id==sxm_mat5_small_tag_be.id)&&!xx_rt_wcscmp(r->name,L"type_and_length"))s=L"Low 16 bits: data type; high 16 bits: inline byte count";
    else if((id==sxm_mat4_header_le.id||id==sxm_mat4_header_be.id)&&!xx_rt_wcscmp(r->name,L"mopt"))s=L"Decimal digits: machine, reserved, precision, matrix type";
    return !s||xx_data_struct_record_set_comment(r,s);
}
