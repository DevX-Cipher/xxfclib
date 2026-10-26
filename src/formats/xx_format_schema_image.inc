/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical image headers and encoded-component boundaries.
 * Layout references: W3C PNG third edition and GIF89a specifications;
 * Microsoft BITMAPFILEHEADER/BITMAPV4HEADER/BITMAPV5HEADER definitions;
 * qoiformat.org/qoi-specification.pdf; ITU-T T.81 JPEG syntax;
 * Adobe TIFF 6.0 and libtiff BigTIFF design.
 * The format reader performs semantic validation; this independent walk
 * checks every emitted physical range and variable-length count.
 */

static const xx_data_struct_field_desc sxi_png_signature_fields[] = {
    SX_FIELD("signature", "uint8[8]", 0, 8, SX_SIGNATURE),
};
static const sx_layout sxi_png_signature = { UINT32_C(0x60010001), "PNG_SIGNATURE", sxi_png_signature_fields, SX_COUNT(sxi_png_signature_fields), SX_BE };

static const xx_data_struct_field_desc sxi_png_chunk_fields[] = {
    SX_FIELD("length", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("type", "char[4]", 4, 4, SX_ID),
};
static const sx_layout sxi_png_chunk = { UINT32_C(0x60010002), "PNG_CHUNK_HEADER", sxi_png_chunk_fields, SX_COUNT(sxi_png_chunk_fields), SX_BE };

static const xx_data_struct_field_desc sxi_png_crc_fields[] = {
    SX_FIELD("crc", "uint32", 0, 4, SX_CHECKSUM),
};
static const sx_layout sxi_png_crc = { UINT32_C(0x60010003), "PNG_CHUNK_CRC", sxi_png_crc_fields, SX_COUNT(sxi_png_crc_fields), SX_BE };

static const xx_data_struct_field_desc sxi_png_ihdr_fields[] = {
    SX_FIELD("width", "uint32", 0, 4, SX_NONE),
    SX_FIELD("height", "uint32", 4, 4, SX_NONE),
    SX_FIELD("bit_depth", "uint8", 8, 1, SX_NONE),
    SX_FIELD("color_type", "uint8", 9, 1, SX_ID),
    SX_FIELD("compression_method", "uint8", 10, 1, SX_ID),
    SX_FIELD("filter_method", "uint8", 11, 1, SX_ID),
    SX_FIELD("interlace_method", "uint8", 12, 1, SX_ID),
};
static const sx_layout sxi_png_ihdr = { UINT32_C(0x60010004), "PNG_IHDR", sxi_png_ihdr_fields, SX_COUNT(sxi_png_ihdr_fields), SX_BE };

static const xx_data_struct_field_desc sxi_png_actl_fields[] = {
    SX_FIELD("num_frames", "uint32", 0, 4, SX_COUNT_PROP),
    SX_FIELD("num_plays", "uint32", 4, 4, SX_COUNT_PROP),
};
static const sx_layout sxi_png_actl = { UINT32_C(0x60010005), "PNG_acTL", sxi_png_actl_fields, SX_COUNT(sxi_png_actl_fields), SX_BE };

static const xx_data_struct_field_desc sxi_png_fctl_fields[] = {
    SX_FIELD("sequence_number", "uint32", 0, 4, SX_NONE),
    SX_FIELD("width", "uint32", 4, 4, SX_NONE),
    SX_FIELD("height", "uint32", 8, 4, SX_NONE),
    SX_FIELD("x_offset", "uint32", 12, 4, SX_NONE),
    SX_FIELD("y_offset", "uint32", 16, 4, SX_NONE),
    SX_FIELD("delay_num", "uint16", 20, 2, SX_NONE),
    SX_FIELD("delay_den", "uint16", 22, 2, SX_NONE),
    SX_FIELD("dispose_op", "uint8", 24, 1, SX_ID),
    SX_FIELD("blend_op", "uint8", 25, 1, SX_ID),
};
static const sx_layout sxi_png_fctl = { UINT32_C(0x60010006), "PNG_fcTL", sxi_png_fctl_fields, SX_COUNT(sxi_png_fctl_fields), SX_BE };

static const xx_data_struct_field_desc sxi_png_fdat_fields[] = {
    SX_FIELD("sequence_number", "uint32", 0, 4, SX_NONE),
};
static const sx_layout sxi_png_fdat = { UINT32_C(0x60010007), "PNG_fdAT_HEADER", sxi_png_fdat_fields, SX_COUNT(sxi_png_fdat_fields), SX_BE };

static const xx_data_struct_field_desc sxi_rgb_fields[] = {
    SX_FIELD("red", "uint8", 0, 1, SX_NONE),
    SX_FIELD("green", "uint8", 1, 1, SX_NONE),
    SX_FIELD("blue", "uint8", 2, 1, SX_NONE),
};
static const sx_layout sxi_rgb = { UINT32_C(0x60010008), "RGB_COLOR", sxi_rgb_fields, SX_COUNT(sxi_rgb_fields), SX_LE };

static const xx_data_struct_field_desc sxi_png_phys_fields[] = {
    SX_FIELD("pixels_per_unit_x", "uint32", 0, 4, SX_NONE),
    SX_FIELD("pixels_per_unit_y", "uint32", 4, 4, SX_NONE),
    SX_FIELD("unit_specifier", "uint8", 8, 1, SX_ID),
};
static const sx_layout sxi_png_phys = { UINT32_C(0x60010009), "PNG_pHYs", sxi_png_phys_fields, SX_COUNT(sxi_png_phys_fields), SX_BE };

static const xx_data_struct_field_desc sxi_png_gama_fields[] = {
    SX_FIELD("image_gamma", "uint32", 0, 4, SX_NONE),
};
static const sx_layout sxi_png_gama = { UINT32_C(0x6001000A), "PNG_gAMA", sxi_png_gama_fields, SX_COUNT(sxi_png_gama_fields), SX_BE };

static const xx_data_struct_field_desc sxi_png_chrm_fields[] = {
    SX_FIELD("white_point_x", "uint32", 0, 4, SX_NONE),
    SX_FIELD("white_point_y", "uint32", 4, 4, SX_NONE),
    SX_FIELD("red_x", "uint32", 8, 4, SX_NONE),
    SX_FIELD("red_y", "uint32", 12, 4, SX_NONE),
    SX_FIELD("green_x", "uint32", 16, 4, SX_NONE),
    SX_FIELD("green_y", "uint32", 20, 4, SX_NONE),
    SX_FIELD("blue_x", "uint32", 24, 4, SX_NONE),
    SX_FIELD("blue_y", "uint32", 28, 4, SX_NONE),
};
static const sx_layout sxi_png_chrm = { UINT32_C(0x6001000B), "PNG_cHRM", sxi_png_chrm_fields, SX_COUNT(sxi_png_chrm_fields), SX_BE };

static const xx_data_struct_field_desc sxi_png_srgb_fields[] = {
    SX_FIELD("rendering_intent", "uint8", 0, 1, SX_ID),
};
static const sx_layout sxi_png_srgb = { UINT32_C(0x6001000C), "PNG_sRGB", sxi_png_srgb_fields, SX_COUNT(sxi_png_srgb_fields), SX_BE };

static const xx_data_struct_field_desc sxi_png_time_fields[] = {
    SX_FIELD("year", "uint16", 0, 2, SX_NONE),
    SX_FIELD("month", "uint8", 2, 1, SX_NONE),
    SX_FIELD("day", "uint8", 3, 1, SX_NONE),
    SX_FIELD("hour", "uint8", 4, 1, SX_NONE),
    SX_FIELD("minute", "uint8", 5, 1, SX_NONE),
    SX_FIELD("second", "uint8", 6, 1, SX_NONE),
};
static const sx_layout sxi_png_time = { UINT32_C(0x6001000D), "PNG_tIME", sxi_png_time_fields, SX_COUNT(sxi_png_time_fields), SX_BE };

static const xx_data_struct_field_desc sxi_bmp_file_fields[] = {
    SX_FIELD("bfType", "uint16", 0, 2, SX_SIGNATURE),
    SX_FIELD("bfSize", "uint32", 2, 4, SX_SIZE),
    SX_FIELD("bfReserved1", "uint16", 6, 2, SX_RESERVED),
    SX_FIELD("bfReserved2", "uint16", 8, 2, SX_RESERVED),
    SX_FIELD("bfOffBits", "uint32", 10, 4, SX_OFFSET),
};
static const sx_layout sxi_bmp_file = { UINT32_C(0x6001000E), "BITMAPFILEHEADER", sxi_bmp_file_fields, SX_COUNT(sxi_bmp_file_fields), SX_LE };

static const xx_data_struct_field_desc sxi_bmp_core_fields[] = {
    SX_FIELD("bcSize", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("bcWidth", "uint16", 4, 2, SX_NONE),
    SX_FIELD("bcHeight", "uint16", 6, 2, SX_NONE),
    SX_FIELD("bcPlanes", "uint16", 8, 2, SX_COUNT_PROP),
    SX_FIELD("bcBitCount", "uint16", 10, 2, SX_NONE),
};
static const sx_layout sxi_bmp_core = { UINT32_C(0x6001000F), "BITMAPCOREHEADER", sxi_bmp_core_fields, SX_COUNT(sxi_bmp_core_fields), SX_LE };

static const xx_data_struct_field_desc sxi_bmp_info_fields[] = {
    SX_FIELD("biSize", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("biWidth", "int32", 4, 4, SX_NONE),
    SX_FIELD("biHeight", "int32", 8, 4, SX_NONE),
    SX_FIELD("biPlanes", "uint16", 12, 2, SX_COUNT_PROP),
    SX_FIELD("biBitCount", "uint16", 14, 2, SX_NONE),
    SX_FIELD("biCompression", "uint32", 16, 4, SX_ID),
    SX_FIELD("biSizeImage", "uint32", 20, 4, SX_SIZE),
    SX_FIELD("biXPelsPerMeter", "int32", 24, 4, SX_NONE),
    SX_FIELD("biYPelsPerMeter", "int32", 28, 4, SX_NONE),
    SX_FIELD("biClrUsed", "uint32", 32, 4, SX_COUNT_PROP),
    SX_FIELD("biClrImportant", "uint32", 36, 4, SX_COUNT_PROP),
};
static const sx_layout sxi_bmp_info = { UINT32_C(0x60010010), "BITMAPINFOHEADER", sxi_bmp_info_fields, SX_COUNT(sxi_bmp_info_fields), SX_LE };

static const xx_data_struct_field_desc sxi_bmp_v4_fields[] = {
    SX_FIELD("bV4Size", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("bV4Width", "int32", 4, 4, SX_NONE),
    SX_FIELD("bV4Height", "int32", 8, 4, SX_NONE),
    SX_FIELD("bV4Planes", "uint16", 12, 2, SX_COUNT_PROP),
    SX_FIELD("bV4BitCount", "uint16", 14, 2, SX_NONE),
    SX_FIELD("bV4V4Compression", "uint32", 16, 4, SX_ID),
    SX_FIELD("bV4SizeImage", "uint32", 20, 4, SX_SIZE),
    SX_FIELD("bV4XPelsPerMeter", "int32", 24, 4, SX_NONE),
    SX_FIELD("bV4YPelsPerMeter", "int32", 28, 4, SX_NONE),
    SX_FIELD("bV4ClrUsed", "uint32", 32, 4, SX_COUNT_PROP),
    SX_FIELD("bV4ClrImportant", "uint32", 36, 4, SX_COUNT_PROP),
    SX_FIELD("bV4RedMask", "uint32", 40, 4, SX_FLAGS),
    SX_FIELD("bV4GreenMask", "uint32", 44, 4, SX_FLAGS),
    SX_FIELD("bV4BlueMask", "uint32", 48, 4, SX_FLAGS),
    SX_FIELD("bV4AlphaMask", "uint32", 52, 4, SX_FLAGS),
    SX_FIELD("bV4CSType", "uint32", 56, 4, SX_ID),
    SX_FIELD("bV4Endpoints.ciexyzRed.ciexyzX", "int32", 60, 4, SX_NONE),
    SX_FIELD("bV4Endpoints.ciexyzRed.ciexyzY", "int32", 64, 4, SX_NONE),
    SX_FIELD("bV4Endpoints.ciexyzRed.ciexyzZ", "int32", 68, 4, SX_NONE),
    SX_FIELD("bV4Endpoints.ciexyzGreen.ciexyzX", "int32", 72, 4, SX_NONE),
    SX_FIELD("bV4Endpoints.ciexyzGreen.ciexyzY", "int32", 76, 4, SX_NONE),
    SX_FIELD("bV4Endpoints.ciexyzGreen.ciexyzZ", "int32", 80, 4, SX_NONE),
    SX_FIELD("bV4Endpoints.ciexyzBlue.ciexyzX", "int32", 84, 4, SX_NONE),
    SX_FIELD("bV4Endpoints.ciexyzBlue.ciexyzY", "int32", 88, 4, SX_NONE),
    SX_FIELD("bV4Endpoints.ciexyzBlue.ciexyzZ", "int32", 92, 4, SX_NONE),
    SX_FIELD("bV4GammaRed", "uint32", 96, 4, SX_NONE),
    SX_FIELD("bV4GammaGreen", "uint32", 100, 4, SX_NONE),
    SX_FIELD("bV4GammaBlue", "uint32", 104, 4, SX_NONE),
};
static const sx_layout sxi_bmp_v4 = { UINT32_C(0x60010011), "BITMAPV4HEADER", sxi_bmp_v4_fields, SX_COUNT(sxi_bmp_v4_fields), SX_LE };

static const xx_data_struct_field_desc sxi_bmp_v5_fields[] = {
    SX_FIELD("bV5Size", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("bV5Width", "int32", 4, 4, SX_NONE),
    SX_FIELD("bV5Height", "int32", 8, 4, SX_NONE),
    SX_FIELD("bV5Planes", "uint16", 12, 2, SX_COUNT_PROP),
    SX_FIELD("bV5BitCount", "uint16", 14, 2, SX_NONE),
    SX_FIELD("bV5Compression", "uint32", 16, 4, SX_ID),
    SX_FIELD("bV5SizeImage", "uint32", 20, 4, SX_SIZE),
    SX_FIELD("bV5XPelsPerMeter", "int32", 24, 4, SX_NONE),
    SX_FIELD("bV5YPelsPerMeter", "int32", 28, 4, SX_NONE),
    SX_FIELD("bV5ClrUsed", "uint32", 32, 4, SX_COUNT_PROP),
    SX_FIELD("bV5ClrImportant", "uint32", 36, 4, SX_COUNT_PROP),
    SX_FIELD("bV5RedMask", "uint32", 40, 4, SX_FLAGS),
    SX_FIELD("bV5GreenMask", "uint32", 44, 4, SX_FLAGS),
    SX_FIELD("bV5BlueMask", "uint32", 48, 4, SX_FLAGS),
    SX_FIELD("bV5AlphaMask", "uint32", 52, 4, SX_FLAGS),
    SX_FIELD("bV5CSType", "uint32", 56, 4, SX_ID),
    SX_FIELD("bV5Endpoints.ciexyzRed.ciexyzX", "int32", 60, 4, SX_NONE),
    SX_FIELD("bV5Endpoints.ciexyzRed.ciexyzY", "int32", 64, 4, SX_NONE),
    SX_FIELD("bV5Endpoints.ciexyzRed.ciexyzZ", "int32", 68, 4, SX_NONE),
    SX_FIELD("bV5Endpoints.ciexyzGreen.ciexyzX", "int32", 72, 4, SX_NONE),
    SX_FIELD("bV5Endpoints.ciexyzGreen.ciexyzY", "int32", 76, 4, SX_NONE),
    SX_FIELD("bV5Endpoints.ciexyzGreen.ciexyzZ", "int32", 80, 4, SX_NONE),
    SX_FIELD("bV5Endpoints.ciexyzBlue.ciexyzX", "int32", 84, 4, SX_NONE),
    SX_FIELD("bV5Endpoints.ciexyzBlue.ciexyzY", "int32", 88, 4, SX_NONE),
    SX_FIELD("bV5Endpoints.ciexyzBlue.ciexyzZ", "int32", 92, 4, SX_NONE),
    SX_FIELD("bV5GammaRed", "uint32", 96, 4, SX_NONE),
    SX_FIELD("bV5GammaGreen", "uint32", 100, 4, SX_NONE),
    SX_FIELD("bV5GammaBlue", "uint32", 104, 4, SX_NONE),
    SX_FIELD("bV5Intent", "uint32", 108, 4, SX_ID),
    SX_FIELD("bV5ProfileData", "uint32", 112, 4, SX_OFFSET),
    SX_FIELD("bV5ProfileSize", "uint32", 116, 4, SX_SIZE),
    SX_FIELD("bV5Reserved", "uint32", 120, 4, SX_RESERVED),
};
static const sx_layout sxi_bmp_v5 = { UINT32_C(0x60010012), "BITMAPV5HEADER", sxi_bmp_v5_fields, SX_COUNT(sxi_bmp_v5_fields), SX_LE };

static const xx_data_struct_field_desc sxi_bmp_rgbtriple_fields[] = {
    SX_FIELD("rgbtBlue", "uint8", 0, 1, SX_NONE),
    SX_FIELD("rgbtGreen", "uint8", 1, 1, SX_NONE),
    SX_FIELD("rgbtRed", "uint8", 2, 1, SX_NONE),
};
static const sx_layout sxi_bmp_rgbtriple = { UINT32_C(0x60010013), "RGBTRIPLE", sxi_bmp_rgbtriple_fields, SX_COUNT(sxi_bmp_rgbtriple_fields), SX_LE };

static const xx_data_struct_field_desc sxi_bmp_rgbquad_fields[] = {
    SX_FIELD("rgbBlue", "uint8", 0, 1, SX_NONE),
    SX_FIELD("rgbGreen", "uint8", 1, 1, SX_NONE),
    SX_FIELD("rgbRed", "uint8", 2, 1, SX_NONE),
    SX_FIELD("rgbReserved", "uint8", 3, 1, SX_RESERVED),
};
static const sx_layout sxi_bmp_rgbquad = { UINT32_C(0x60010014), "RGBQUAD", sxi_bmp_rgbquad_fields, SX_COUNT(sxi_bmp_rgbquad_fields), SX_LE };

static const xx_data_struct_field_desc sxi_bmp_masks_fields[] = {
    SX_FIELD("red_mask", "uint32", 0, 4, SX_FLAGS),
    SX_FIELD("green_mask", "uint32", 4, 4, SX_FLAGS),
    SX_FIELD("blue_mask", "uint32", 8, 4, SX_FLAGS),
};
static const sx_layout sxi_bmp_masks = { UINT32_C(0x60010015), "BITMAP_BITFIELDS", sxi_bmp_masks_fields, SX_COUNT(sxi_bmp_masks_fields), SX_LE };

static const xx_data_struct_field_desc sxi_bmp_alpha_masks_fields[] = {
    SX_FIELD("red_mask", "uint32", 0, 4, SX_FLAGS),
    SX_FIELD("green_mask", "uint32", 4, 4, SX_FLAGS),
    SX_FIELD("blue_mask", "uint32", 8, 4, SX_FLAGS),
    SX_FIELD("alpha_mask", "uint32", 12, 4, SX_FLAGS),
};
static const sx_layout sxi_bmp_alpha_masks = { UINT32_C(0x60010016), "BITMAP_ALPHA_BITFIELDS", sxi_bmp_alpha_masks_fields, SX_COUNT(sxi_bmp_alpha_masks_fields), SX_LE };

static const xx_data_struct_field_desc sxi_gif_header_fields[] = {
    SX_FIELD("signature", "char[3]", 0, 3, SX_SIGNATURE),
    SX_FIELD("version", "char[3]", 3, 3, SX_ID),
};
static const sx_layout sxi_gif_header = { UINT32_C(0x60010017), "GIF_HEADER", sxi_gif_header_fields, SX_COUNT(sxi_gif_header_fields), SX_LE };

static const xx_data_struct_field_desc sxi_gif_screen_fields[] = {
    SX_FIELD("logical_screen_width", "uint16", 0, 2, SX_NONE),
    SX_FIELD("logical_screen_height", "uint16", 2, 2, SX_NONE),
    SX_FIELD("packed_fields", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("background_color_index", "uint8", 5, 1, SX_NONE),
    SX_FIELD("pixel_aspect_ratio", "uint8", 6, 1, SX_NONE),
};
static const sx_layout sxi_gif_screen = { UINT32_C(0x60010018), "GIF_LOGICAL_SCREEN_DESCRIPTOR", sxi_gif_screen_fields, SX_COUNT(sxi_gif_screen_fields), SX_LE };

static const xx_data_struct_field_desc sxi_gif_image_fields[] = {
    SX_FIELD("image_separator", "uint8", 0, 1, SX_SIGNATURE),
    SX_FIELD("image_left_position", "uint16", 1, 2, SX_NONE),
    SX_FIELD("image_top_position", "uint16", 3, 2, SX_NONE),
    SX_FIELD("image_width", "uint16", 5, 2, SX_NONE),
    SX_FIELD("image_height", "uint16", 7, 2, SX_NONE),
    SX_FIELD("packed_fields", "uint8", 9, 1, SX_FLAGS),
};
static const sx_layout sxi_gif_image = { UINT32_C(0x60010019), "GIF_IMAGE_DESCRIPTOR", sxi_gif_image_fields, SX_COUNT(sxi_gif_image_fields), SX_LE };

static const xx_data_struct_field_desc sxi_gif_extension_fields[] = {
    SX_FIELD("extension_introducer", "uint8", 0, 1, SX_SIGNATURE),
    SX_FIELD("extension_label", "uint8", 1, 1, SX_ID),
};
static const sx_layout sxi_gif_extension = { UINT32_C(0x6001001A), "GIF_EXTENSION_HEADER", sxi_gif_extension_fields, SX_COUNT(sxi_gif_extension_fields), SX_LE };

static const xx_data_struct_field_desc sxi_gif_graphic_fields[] = {
    SX_FIELD("extension_introducer", "uint8", 0, 1, SX_SIGNATURE),
    SX_FIELD("graphic_control_label", "uint8", 1, 1, SX_ID),
    SX_FIELD("block_size", "uint8", 2, 1, SX_SIZE),
    SX_FIELD("packed_fields", "uint8", 3, 1, SX_FLAGS),
    SX_FIELD("delay_time", "uint16", 4, 2, SX_NONE),
    SX_FIELD("transparent_color_index", "uint8", 6, 1, SX_NONE),
    SX_FIELD("block_terminator", "uint8", 7, 1, SX_SIGNATURE),
};
static const sx_layout sxi_gif_graphic = { UINT32_C(0x6001001B), "GIF_GRAPHIC_CONTROL_EXTENSION", sxi_gif_graphic_fields, SX_COUNT(sxi_gif_graphic_fields), SX_LE };

static const xx_data_struct_field_desc sxi_gif_application_fields[] = {
    SX_FIELD("extension_introducer", "uint8", 0, 1, SX_SIGNATURE),
    SX_FIELD("application_label", "uint8", 1, 1, SX_ID),
    SX_FIELD("block_size", "uint8", 2, 1, SX_SIZE),
    SX_FIELD("application_identifier", "char[8]", 3, 8, SX_ID),
    SX_FIELD("application_authentication_code", "uint8[3]", 11, 3, SX_ID),
};
static const sx_layout sxi_gif_application = { UINT32_C(0x6001001C), "GIF_APPLICATION_EXTENSION", sxi_gif_application_fields, SX_COUNT(sxi_gif_application_fields), SX_LE };

static const xx_data_struct_field_desc sxi_gif_text_fields[] = {
    SX_FIELD("extension_introducer", "uint8", 0, 1, SX_SIGNATURE),
    SX_FIELD("plain_text_label", "uint8", 1, 1, SX_ID),
    SX_FIELD("block_size", "uint8", 2, 1, SX_SIZE),
    SX_FIELD("text_grid_left_position", "uint16", 3, 2, SX_NONE),
    SX_FIELD("text_grid_top_position", "uint16", 5, 2, SX_NONE),
    SX_FIELD("text_grid_width", "uint16", 7, 2, SX_NONE),
    SX_FIELD("text_grid_height", "uint16", 9, 2, SX_NONE),
    SX_FIELD("character_cell_width", "uint8", 11, 1, SX_NONE),
    SX_FIELD("character_cell_height", "uint8", 12, 1, SX_NONE),
    SX_FIELD("text_foreground_color_index", "uint8", 13, 1, SX_NONE),
    SX_FIELD("text_background_color_index", "uint8", 14, 1, SX_NONE),
};
static const sx_layout sxi_gif_text = { UINT32_C(0x6001001D), "GIF_PLAIN_TEXT_EXTENSION", sxi_gif_text_fields, SX_COUNT(sxi_gif_text_fields), SX_LE };

static const xx_data_struct_field_desc sxi_gif_subblock_fields[] = {
    SX_FIELD("block_size", "uint8", 0, 1, SX_SIZE),
};
static const sx_layout sxi_gif_subblock = { UINT32_C(0x6001001E), "GIF_DATA_SUB_BLOCK_HEADER", sxi_gif_subblock_fields, SX_COUNT(sxi_gif_subblock_fields), SX_LE };

static const xx_data_struct_field_desc sxi_gif_lzw_fields[] = {
    SX_FIELD("lzw_minimum_code_size", "uint8", 0, 1, SX_NONE),
};
static const sx_layout sxi_gif_lzw = { UINT32_C(0x6001001F), "GIF_LZW_MINIMUM_CODE_SIZE", sxi_gif_lzw_fields, SX_COUNT(sxi_gif_lzw_fields), SX_LE };

static const xx_data_struct_field_desc sxi_gif_trailer_fields[] = {
    SX_FIELD("trailer", "uint8", 0, 1, SX_SIGNATURE),
};
static const sx_layout sxi_gif_trailer = { UINT32_C(0x60010020), "GIF_TRAILER", sxi_gif_trailer_fields, SX_COUNT(sxi_gif_trailer_fields), SX_LE };

static const xx_data_struct_field_desc sxi_ico_header_fields[] = {
    SX_FIELD("idReserved", "uint16", 0, 2, SX_RESERVED),
    SX_FIELD("idType", "uint16", 2, 2, SX_ID),
    SX_FIELD("idCount", "uint16", 4, 2, SX_COUNT_PROP),
};
static const sx_layout sxi_ico_header = { UINT32_C(0x60010021), "ICONDIR", sxi_ico_header_fields, SX_COUNT(sxi_ico_header_fields), SX_LE };

static const xx_data_struct_field_desc sxi_ico_entry_fields[] = {
    SX_FIELD("bWidth", "uint8", 0, 1, SX_NONE),
    SX_FIELD("bHeight", "uint8", 1, 1, SX_NONE),
    SX_FIELD("bColorCount", "uint8", 2, 1, SX_COUNT_PROP),
    SX_FIELD("bReserved", "uint8", 3, 1, SX_RESERVED),
    SX_FIELD("wPlanes", "uint16", 4, 2, SX_COUNT_PROP),
    SX_FIELD("wBitCount", "uint16", 6, 2, SX_NONE),
    SX_FIELD("dwBytesInRes", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("dwImageOffset", "uint32", 12, 4, SX_OFFSET),
};
static const sx_layout sxi_ico_entry = { UINT32_C(0x60010022), "ICONDIRENTRY", sxi_ico_entry_fields, SX_COUNT(sxi_ico_entry_fields), SX_LE };

static const xx_data_struct_field_desc sxi_cur_entry_fields[] = {
    SX_FIELD("bWidth", "uint8", 0, 1, SX_NONE),
    SX_FIELD("bHeight", "uint8", 1, 1, SX_NONE),
    SX_FIELD("bColorCount", "uint8", 2, 1, SX_COUNT_PROP),
    SX_FIELD("bReserved", "uint8", 3, 1, SX_RESERVED),
    SX_FIELD("wXHotspot", "uint16", 4, 2, SX_NONE),
    SX_FIELD("wYHotspot", "uint16", 6, 2, SX_NONE),
    SX_FIELD("dwBytesInRes", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("dwImageOffset", "uint32", 12, 4, SX_OFFSET),
};
static const sx_layout sxi_cur_entry = { UINT32_C(0x60010023), "CURSORDIRENTRY", sxi_cur_entry_fields, SX_COUNT(sxi_cur_entry_fields), SX_LE };

static const xx_data_struct_field_desc sxi_qoi_header_fields[] = {
    SX_FIELD("magic", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("width", "uint32", 4, 4, SX_NONE),
    SX_FIELD("height", "uint32", 8, 4, SX_NONE),
    SX_FIELD("channels", "uint8", 12, 1, SX_COUNT_PROP),
    SX_FIELD("colorspace", "uint8", 13, 1, SX_ID),
};
static const sx_layout sxi_qoi_header = { UINT32_C(0x60010024), "QOI_HEADER", sxi_qoi_header_fields, SX_COUNT(sxi_qoi_header_fields), SX_BE };

static const xx_data_struct_field_desc sxi_qoi_end_fields[] = {
    SX_FIELD("end_marker", "uint8[8]", 0, 8, SX_SIGNATURE),
};
static const sx_layout sxi_qoi_end = { UINT32_C(0x60010025), "QOI_END_MARKER", sxi_qoi_end_fields, SX_COUNT(sxi_qoi_end_fields), SX_BE };

static const xx_data_struct_field_desc sxi_jpeg_marker_fields[] = {
    SX_FIELD("marker", "uint16", 0, 2, SX_ID),
};
static const sx_layout sxi_jpeg_marker = { UINT32_C(0x60010026), "JPEG_MARKER", sxi_jpeg_marker_fields, SX_COUNT(sxi_jpeg_marker_fields), SX_BE };

static const xx_data_struct_field_desc sxi_jpeg_segment_fields[] = {
    SX_FIELD("marker", "uint16", 0, 2, SX_ID),
    SX_FIELD("segment_length", "uint16", 2, 2, SX_SIZE),
};
static const sx_layout sxi_jpeg_segment = { UINT32_C(0x60010027), "JPEG_SEGMENT_HEADER", sxi_jpeg_segment_fields, SX_COUNT(sxi_jpeg_segment_fields), SX_BE };

static const xx_data_struct_field_desc sxi_jpeg_frame_fields[] = {
    SX_FIELD("marker", "uint16", 0, 2, SX_ID),
    SX_FIELD("frame_header_length", "uint16", 2, 2, SX_SIZE),
    SX_FIELD("sample_precision", "uint8", 4, 1, SX_NONE),
    SX_FIELD("number_of_lines", "uint16", 5, 2, SX_NONE),
    SX_FIELD("samples_per_line", "uint16", 7, 2, SX_NONE),
    SX_FIELD("number_of_components", "uint8", 9, 1, SX_COUNT_PROP),
};
static const sx_layout sxi_jpeg_frame = { UINT32_C(0x60010028), "JPEG_FRAME_HEADER", sxi_jpeg_frame_fields, SX_COUNT(sxi_jpeg_frame_fields), SX_BE };

static const xx_data_struct_field_desc sxi_jpeg_component_fields[] = {
    SX_FIELD("component_identifier", "uint8", 0, 1, SX_ID),
    SX_FIELD("sampling_factors", "uint8", 1, 1, SX_FLAGS),
    SX_FIELD("quantization_table_selector", "uint8", 2, 1, SX_ID),
};
static const sx_layout sxi_jpeg_component = { UINT32_C(0x60010029), "JPEG_FRAME_COMPONENT", sxi_jpeg_component_fields, SX_COUNT(sxi_jpeg_component_fields), SX_BE };

static const xx_data_struct_field_desc sxi_jpeg_scan_fields[] = {
    SX_FIELD("marker", "uint16", 0, 2, SX_ID),
    SX_FIELD("scan_header_length", "uint16", 2, 2, SX_SIZE),
    SX_FIELD("number_of_components", "uint8", 4, 1, SX_COUNT_PROP),
};
static const sx_layout sxi_jpeg_scan = { UINT32_C(0x6001002A), "JPEG_SCAN_HEADER", sxi_jpeg_scan_fields, SX_COUNT(sxi_jpeg_scan_fields), SX_BE };

static const xx_data_struct_field_desc sxi_jpeg_scan_component_fields[] = {
    SX_FIELD("component_selector", "uint8", 0, 1, SX_ID),
    SX_FIELD("entropy_coding_table_selectors", "uint8", 1, 1, SX_FLAGS),
};
static const sx_layout sxi_jpeg_scan_component = { UINT32_C(0x6001002B), "JPEG_SCAN_COMPONENT", sxi_jpeg_scan_component_fields, SX_COUNT(sxi_jpeg_scan_component_fields), SX_BE };

static const xx_data_struct_field_desc sxi_jpeg_scan_tail_fields[] = {
    SX_FIELD("spectral_selection_start", "uint8", 0, 1, SX_NONE),
    SX_FIELD("spectral_selection_end", "uint8", 1, 1, SX_NONE),
    SX_FIELD("successive_approximation", "uint8", 2, 1, SX_FLAGS),
};
static const sx_layout sxi_jpeg_scan_tail = { UINT32_C(0x6001002C), "JPEG_SCAN_PARAMETERS", sxi_jpeg_scan_tail_fields, SX_COUNT(sxi_jpeg_scan_tail_fields), SX_BE };

static const xx_data_struct_field_desc sxi_jpeg_dri_fields[] = {
    SX_FIELD("marker", "uint16", 0, 2, SX_ID),
    SX_FIELD("segment_length", "uint16", 2, 2, SX_SIZE),
    SX_FIELD("restart_interval", "uint16", 4, 2, SX_COUNT_PROP),
};
static const sx_layout sxi_jpeg_dri = { UINT32_C(0x6001002D), "JPEG_RESTART_INTERVAL", sxi_jpeg_dri_fields, SX_COUNT(sxi_jpeg_dri_fields), SX_BE };

static const xx_data_struct_field_desc sxi_jpeg_jfif_fields[] = {
    SX_FIELD("marker", "uint16", 0, 2, SX_ID),
    SX_FIELD("segment_length", "uint16", 2, 2, SX_SIZE),
    SX_FIELD("identifier", "char[5]", 4, 5, SX_SIGNATURE),
    SX_FIELD("version_major", "uint8", 9, 1, SX_NONE),
    SX_FIELD("version_minor", "uint8", 10, 1, SX_NONE),
    SX_FIELD("density_units", "uint8", 11, 1, SX_ID),
    SX_FIELD("x_density", "uint16", 12, 2, SX_NONE),
    SX_FIELD("y_density", "uint16", 14, 2, SX_NONE),
    SX_FIELD("x_thumbnail", "uint8", 16, 1, SX_NONE),
    SX_FIELD("y_thumbnail", "uint8", 17, 1, SX_NONE),
};
static const sx_layout sxi_jpeg_jfif = { UINT32_C(0x6001002E), "JPEG_JFIF_APP0", sxi_jpeg_jfif_fields, SX_COUNT(sxi_jpeg_jfif_fields), SX_BE };

static const xx_data_struct_field_desc sxi_jpeg_dqt8_fields[] = {
    SX_FIELD("precision_and_identifier", "uint8", 0, 1, SX_FLAGS),
    SX_FIELD("quantization_values", "uint8[64]", 1, 64, SX_NONE),
};
static const sx_layout sxi_jpeg_dqt8 = { UINT32_C(0x6001002F), "JPEG_QUANTIZATION_TABLE8", sxi_jpeg_dqt8_fields, SX_COUNT(sxi_jpeg_dqt8_fields), SX_BE };

static const xx_data_struct_field_desc sxi_jpeg_dqt16_fields[] = {
    SX_FIELD("precision_and_identifier", "uint8", 0, 1, SX_FLAGS),
    SX_FIELD("quantization_values", "uint16[64]", 1, 128, SX_NONE),
};
static const sx_layout sxi_jpeg_dqt16 = { UINT32_C(0x60010030), "JPEG_QUANTIZATION_TABLE16", sxi_jpeg_dqt16_fields, SX_COUNT(sxi_jpeg_dqt16_fields), SX_BE };

static const xx_data_struct_field_desc sxi_jpeg_dht_fields[] = {
    SX_FIELD("table_class_and_identifier", "uint8", 0, 1, SX_FLAGS),
    SX_FIELD("codes_of_length_1", "uint8", 1, 1, SX_COUNT_PROP),
    SX_FIELD("codes_of_length_2", "uint8", 2, 1, SX_COUNT_PROP),
    SX_FIELD("codes_of_length_3", "uint8", 3, 1, SX_COUNT_PROP),
    SX_FIELD("codes_of_length_4", "uint8", 4, 1, SX_COUNT_PROP),
    SX_FIELD("codes_of_length_5", "uint8", 5, 1, SX_COUNT_PROP),
    SX_FIELD("codes_of_length_6", "uint8", 6, 1, SX_COUNT_PROP),
    SX_FIELD("codes_of_length_7", "uint8", 7, 1, SX_COUNT_PROP),
    SX_FIELD("codes_of_length_8", "uint8", 8, 1, SX_COUNT_PROP),
    SX_FIELD("codes_of_length_9", "uint8", 9, 1, SX_COUNT_PROP),
    SX_FIELD("codes_of_length_10", "uint8", 10, 1, SX_COUNT_PROP),
    SX_FIELD("codes_of_length_11", "uint8", 11, 1, SX_COUNT_PROP),
    SX_FIELD("codes_of_length_12", "uint8", 12, 1, SX_COUNT_PROP),
    SX_FIELD("codes_of_length_13", "uint8", 13, 1, SX_COUNT_PROP),
    SX_FIELD("codes_of_length_14", "uint8", 14, 1, SX_COUNT_PROP),
    SX_FIELD("codes_of_length_15", "uint8", 15, 1, SX_COUNT_PROP),
    SX_FIELD("codes_of_length_16", "uint8", 16, 1, SX_COUNT_PROP),
};
static const sx_layout sxi_jpeg_dht = { UINT32_C(0x60010031), "JPEG_HUFFMAN_TABLE_HEADER", sxi_jpeg_dht_fields, SX_COUNT(sxi_jpeg_dht_fields), SX_BE };

static const xx_data_struct_field_desc sxi_tiff_header_le_fields[] = {
    SX_FIELD("byte_order", "char[2]", 0, 2, SX_ID),
    SX_FIELD("version", "uint16", 2, 2, SX_ID),
    SX_FIELD("first_ifd_offset", "uint32", 4, 4, SX_OFFSET),
};
static const sx_layout sxi_tiff_header_le = { UINT32_C(0x60010032), "TIFF_HEADER_LE", sxi_tiff_header_le_fields, SX_COUNT(sxi_tiff_header_le_fields), SX_LE };

static const sx_layout sxi_tiff_header_be = { UINT32_C(0x60010033), "TIFF_HEADER_BE", sxi_tiff_header_le_fields, SX_COUNT(sxi_tiff_header_le_fields), SX_BE };

static const xx_data_struct_field_desc sxi_bigtiff_header_le_fields[] = {
    SX_FIELD("byte_order", "char[2]", 0, 2, SX_ID),
    SX_FIELD("version", "uint16", 2, 2, SX_ID),
    SX_FIELD("offset_size", "uint16", 4, 2, SX_SIZE),
    SX_FIELD("reserved", "uint16", 6, 2, SX_RESERVED),
    SX_FIELD("first_ifd_offset", "uint64", 8, 8, SX_OFFSET),
};
static const sx_layout sxi_bigtiff_header_le = { UINT32_C(0x60010034), "BIGTIFF_HEADER_LE", sxi_bigtiff_header_le_fields, SX_COUNT(sxi_bigtiff_header_le_fields), SX_LE };

static const sx_layout sxi_bigtiff_header_be = { UINT32_C(0x60010035), "BIGTIFF_HEADER_BE", sxi_bigtiff_header_le_fields, SX_COUNT(sxi_bigtiff_header_le_fields), SX_BE };

static const xx_data_struct_field_desc sxi_tiff_count_le_fields[] = {
    SX_FIELD("entry_count", "uint16", 0, 2, SX_COUNT_PROP),
};
static const sx_layout sxi_tiff_count_le = { UINT32_C(0x60010036), "TIFF_IFD_COUNT_LE", sxi_tiff_count_le_fields, SX_COUNT(sxi_tiff_count_le_fields), SX_LE };

static const sx_layout sxi_tiff_count_be = { UINT32_C(0x60010037), "TIFF_IFD_COUNT_BE", sxi_tiff_count_le_fields, SX_COUNT(sxi_tiff_count_le_fields), SX_BE };

static const xx_data_struct_field_desc sxi_bigtiff_count_le_fields[] = {
    SX_FIELD("entry_count", "uint64", 0, 8, SX_COUNT_PROP),
};
static const sx_layout sxi_bigtiff_count_le = { UINT32_C(0x60010038), "BIGTIFF_IFD_COUNT_LE", sxi_bigtiff_count_le_fields, SX_COUNT(sxi_bigtiff_count_le_fields), SX_LE };

static const sx_layout sxi_bigtiff_count_be = { UINT32_C(0x60010039), "BIGTIFF_IFD_COUNT_BE", sxi_bigtiff_count_le_fields, SX_COUNT(sxi_bigtiff_count_le_fields), SX_BE };

static const xx_data_struct_field_desc sxi_tiff_next_le_fields[] = {
    SX_FIELD("next_ifd_offset", "uint32", 0, 4, SX_OFFSET),
};
static const sx_layout sxi_tiff_next_le = { UINT32_C(0x6001003A), "TIFF_NEXT_IFD_LE", sxi_tiff_next_le_fields, SX_COUNT(sxi_tiff_next_le_fields), SX_LE };

static const sx_layout sxi_tiff_next_be = { UINT32_C(0x6001003B), "TIFF_NEXT_IFD_BE", sxi_tiff_next_le_fields, SX_COUNT(sxi_tiff_next_le_fields), SX_BE };

static const xx_data_struct_field_desc sxi_bigtiff_next_le_fields[] = {
    SX_FIELD("next_ifd_offset", "uint64", 0, 8, SX_OFFSET),
};
static const sx_layout sxi_bigtiff_next_le = { UINT32_C(0x6001003C), "BIGTIFF_NEXT_IFD_LE", sxi_bigtiff_next_le_fields, SX_COUNT(sxi_bigtiff_next_le_fields), SX_LE };

static const sx_layout sxi_bigtiff_next_be = { UINT32_C(0x6001003D), "BIGTIFF_NEXT_IFD_BE", sxi_bigtiff_next_le_fields, SX_COUNT(sxi_bigtiff_next_le_fields), SX_BE };

static const xx_data_struct_field_desc sxi_tiff_entry_inline_le_fields[] = {
    SX_FIELD("tag", "uint16", 0, 2, SX_ID),
    SX_FIELD("field_type", "uint16", 2, 2, SX_ID),
    SX_FIELD("count", "uint32", 4, 4, SX_COUNT_PROP),
    SX_FIELD("inline_value", "uint8[4]", 8, 4, SX_NONE),
};
static const sx_layout sxi_tiff_entry_inline_le = { UINT32_C(0x6001003E), "TIFF_IFD_ENTRY_INLINE_LE", sxi_tiff_entry_inline_le_fields, SX_COUNT(sxi_tiff_entry_inline_le_fields), SX_LE };

static const sx_layout sxi_tiff_entry_inline_be = { UINT32_C(0x6001003F), "TIFF_IFD_ENTRY_INLINE_BE", sxi_tiff_entry_inline_le_fields, SX_COUNT(sxi_tiff_entry_inline_le_fields), SX_BE };

static const xx_data_struct_field_desc sxi_tiff_entry_offset_le_fields[] = {
    SX_FIELD("tag", "uint16", 0, 2, SX_ID),
    SX_FIELD("field_type", "uint16", 2, 2, SX_ID),
    SX_FIELD("count", "uint32", 4, 4, SX_COUNT_PROP),
    SX_FIELD("value_offset", "uint32", 8, 4, SX_OFFSET),
};
static const sx_layout sxi_tiff_entry_offset_le = { UINT32_C(0x60010040), "TIFF_IFD_ENTRY_OFFSET_LE", sxi_tiff_entry_offset_le_fields, SX_COUNT(sxi_tiff_entry_offset_le_fields), SX_LE };

static const sx_layout sxi_tiff_entry_offset_be = { UINT32_C(0x60010041), "TIFF_IFD_ENTRY_OFFSET_BE", sxi_tiff_entry_offset_le_fields, SX_COUNT(sxi_tiff_entry_offset_le_fields), SX_BE };

static const xx_data_struct_field_desc sxi_bigtiff_entry_inline_le_fields[] = {
    SX_FIELD("tag", "uint16", 0, 2, SX_ID),
    SX_FIELD("field_type", "uint16", 2, 2, SX_ID),
    SX_FIELD("count", "uint64", 4, 8, SX_COUNT_PROP),
    SX_FIELD("inline_value", "uint8[8]", 12, 8, SX_NONE),
};
static const sx_layout sxi_bigtiff_entry_inline_le = { UINT32_C(0x60010042), "BIGTIFF_IFD_ENTRY_INLINE_LE", sxi_bigtiff_entry_inline_le_fields, SX_COUNT(sxi_bigtiff_entry_inline_le_fields), SX_LE };

static const sx_layout sxi_bigtiff_entry_inline_be = { UINT32_C(0x60010043), "BIGTIFF_IFD_ENTRY_INLINE_BE", sxi_bigtiff_entry_inline_le_fields, SX_COUNT(sxi_bigtiff_entry_inline_le_fields), SX_BE };

static const xx_data_struct_field_desc sxi_bigtiff_entry_offset_le_fields[] = {
    SX_FIELD("tag", "uint16", 0, 2, SX_ID),
    SX_FIELD("field_type", "uint16", 2, 2, SX_ID),
    SX_FIELD("count", "uint64", 4, 8, SX_COUNT_PROP),
    SX_FIELD("value_offset", "uint64", 12, 8, SX_OFFSET),
};
static const sx_layout sxi_bigtiff_entry_offset_le = { UINT32_C(0x60010044), "BIGTIFF_IFD_ENTRY_OFFSET_LE", sxi_bigtiff_entry_offset_le_fields, SX_COUNT(sxi_bigtiff_entry_offset_le_fields), SX_LE };

static const sx_layout sxi_bigtiff_entry_offset_be = { UINT32_C(0x60010045), "BIGTIFF_IFD_ENTRY_OFFSET_BE", sxi_bigtiff_entry_offset_le_fields, SX_COUNT(sxi_bigtiff_entry_offset_le_fields), SX_BE };

static const sx_layout *const sx_image_layouts[] = {
    &sxi_png_signature,
    &sxi_png_chunk,
    &sxi_png_crc,
    &sxi_png_ihdr,
    &sxi_png_actl,
    &sxi_png_fctl,
    &sxi_png_fdat,
    &sxi_rgb,
    &sxi_png_phys,
    &sxi_png_gama,
    &sxi_png_chrm,
    &sxi_png_srgb,
    &sxi_png_time,
    &sxi_bmp_file,
    &sxi_bmp_core,
    &sxi_bmp_info,
    &sxi_bmp_v4,
    &sxi_bmp_v5,
    &sxi_bmp_rgbtriple,
    &sxi_bmp_rgbquad,
    &sxi_bmp_masks,
    &sxi_bmp_alpha_masks,
    &sxi_gif_header,
    &sxi_gif_screen,
    &sxi_gif_image,
    &sxi_gif_extension,
    &sxi_gif_graphic,
    &sxi_gif_application,
    &sxi_gif_text,
    &sxi_gif_subblock,
    &sxi_gif_lzw,
    &sxi_gif_trailer,
    &sxi_ico_header,
    &sxi_ico_entry,
    &sxi_cur_entry,
    &sxi_qoi_header,
    &sxi_qoi_end,
    &sxi_jpeg_marker,
    &sxi_jpeg_segment,
    &sxi_jpeg_frame,
    &sxi_jpeg_component,
    &sxi_jpeg_scan,
    &sxi_jpeg_scan_component,
    &sxi_jpeg_scan_tail,
    &sxi_jpeg_dri,
    &sxi_jpeg_jfif,
    &sxi_jpeg_dqt8,
    &sxi_jpeg_dqt16,
    &sxi_jpeg_dht,
    &sxi_tiff_header_le,
    &sxi_tiff_header_be,
    &sxi_bigtiff_header_le,
    &sxi_bigtiff_header_be,
    &sxi_tiff_count_le,
    &sxi_tiff_count_be,
    &sxi_bigtiff_count_le,
    &sxi_bigtiff_count_be,
    &sxi_tiff_next_le,
    &sxi_tiff_next_be,
    &sxi_bigtiff_next_le,
    &sxi_bigtiff_next_be,
    &sxi_tiff_entry_inline_le,
    &sxi_tiff_entry_inline_be,
    &sxi_tiff_entry_offset_le,
    &sxi_tiff_entry_offset_be,
    &sxi_bigtiff_entry_inline_le,
    &sxi_bigtiff_entry_inline_be,
    &sxi_bigtiff_entry_offset_le,
    &sxi_bigtiff_entry_offset_be,
};


static bool sx_image_range(const sx_context *c, int64_t at, uint64_t n)
{
    return c && at >= 0 && at <= c->size && n <= (uint64_t)(c->size - at);
}

typedef struct sxi_cursor {
    sx_context *context;
    int64_t start;
    size_t valid;
    uint8_t bytes[4096];
} sxi_cursor;

static bool sxi_byte(sxi_cursor *cursor, int64_t at, uint8_t *value)
{
    sx_context *c = cursor->context;
    if (!sx_image_range(c, at, 1) || xx_pd_is_stopped(c->pd)) return false;
    if (at < cursor->start || (uint64_t)(at - cursor->start) >= cursor->valid) {
        uint64_t remaining = (uint64_t)(c->size - at);
        cursor->start = at;
        cursor->valid = remaining < sizeof(cursor->bytes) ? (size_t)remaining : sizeof(cursor->bytes);
        if (!sx_read(c, at, cursor->bytes, cursor->valid)) return false;
    }
    *value = cursor->bytes[(size_t)(at - cursor->start)];
    return true;
}

static bool sx_image_png(sx_context *c)
{
    uint8_t h[8];
    int64_t at = 8;
    unsigned chunks = 0;
    bool have_ihdr = false, have_idat = false;
    if (!sx_read(c, 0, h, 8) || xx_rt_memcmp(h, "\x89PNG\r\n\x1a\n", 8) || !sx_add(c, &sxi_png_signature, 0, 8)) return false;
    while (sx_image_range(c, at, 12) && ++chunks <= 100000U) {
        uint32_t n;
        int64_t data = at + 8;
        const sx_layout *layout = NULL;
        int64_t fixed = 0;
        if (!sx_read(c, at, h, 8) || !sx_u32(c, at, true, &n) || n > INT32_MAX || !sx_image_range(c, at, (uint64_t)n + 12)) return false;
        if (!sx_add(c, &sxi_png_chunk, at, 8)) return false;
        if (!xx_rt_memcmp(h + 4, "IHDR", 4)) {
            if (have_ihdr || chunks != 1 || n != 13) return false;
            have_ihdr = true;
            layout = &sxi_png_ihdr;
            fixed = 13;
        } else if (!have_ihdr) return false;
        else if (!xx_rt_memcmp(h + 4, "acTL", 4)) { layout = &sxi_png_actl; fixed = 8; }
        else if (!xx_rt_memcmp(h + 4, "fcTL", 4)) { layout = &sxi_png_fctl; fixed = 26; }
        else if (!xx_rt_memcmp(h + 4, "fdAT", 4)) {
            if (n < 4 || !sx_add(c, &sxi_png_fdat, data, 4) || !sx_raw(c, data + 4, (int64_t)n - 4)) return false;
        } else if (!xx_rt_memcmp(h + 4, "pHYs", 4)) { layout = &sxi_png_phys; fixed = 9; }
        else if (!xx_rt_memcmp(h + 4, "gAMA", 4)) { layout = &sxi_png_gama; fixed = 4; }
        else if (!xx_rt_memcmp(h + 4, "cHRM", 4)) { layout = &sxi_png_chrm; fixed = 32; }
        else if (!xx_rt_memcmp(h + 4, "sRGB", 4)) { layout = &sxi_png_srgb; fixed = 1; }
        else if (!xx_rt_memcmp(h + 4, "tIME", 4)) { layout = &sxi_png_time; fixed = 7; }
        else if (!xx_rt_memcmp(h + 4, "PLTE", 4)) {
            if (!n || n > 768 || n % 3 || !sx_table(c, &sxi_rgb, data, 3, n / 3)) return false;
        } else if (!xx_rt_memcmp(h + 4, "IDAT", 4)) {
            have_idat = true;
            if (!sx_raw(c, data, n)) return false;
        } else if (!xx_rt_memcmp(h + 4, "IEND", 4)) {
            return n == 0 && have_idat && sx_add(c, &sxi_png_crc, data, 4);
        } else if (!sx_raw(c, data, n)) return false;
        if (layout && (n != (uint32_t)fixed || !sx_add(c, layout, data, fixed))) return false;
        if (!sx_add(c, &sxi_png_crc, data + n, 4)) return false;
        at += (int64_t)n + 12;
    }
    return false;
}

static bool sx_image_bmp(sx_context *c)
{
    uint8_t magic[2];
    uint16_t bits;
    uint32_t length, pixels, dib, compression = 0, colors = 0;
    int64_t at, palette_size;
    const sx_layout *header, *color;
    if (!sx_read(c, 0, magic, 2) || xx_rt_memcmp(magic, "BM", 2) || !sx_u32(c, 2, false, &length) ||
        !sx_u32(c, 10, false, &pixels) || !sx_u32(c, 14, false, &dib) || length > (uint64_t)c->size || pixels > length) return false;
    if (dib == 12) { header = &sxi_bmp_core; color = &sxi_bmp_rgbtriple; palette_size = 3; }
    else if (dib == 40 || dib == 108 || dib == 124) {
        header = dib == 40 ? &sxi_bmp_info : dib == 108 ? &sxi_bmp_v4 : &sxi_bmp_v5;
        color = &sxi_bmp_rgbquad;
        palette_size = 4;
        if (!sx_u32(c, 30, false, &compression) || !sx_u32(c, 46, false, &colors)) return false;
    } else return false;
    if ((uint64_t)14 + dib > pixels || !sx_add(c, &sxi_bmp_file, 0, 14) || !sx_add(c, header, 14, dib) ||
        !sx_u16(c, dib == 12 ? 24 : 28, false, &bits)) return false;
    at = 14 + (int64_t)dib;
    if (dib == 40 && (compression == 3 || compression == 6)) {
        int64_t masks = compression == 6 ? 16 : 12;
        if ((uint64_t)at + (uint64_t)masks > pixels || !sx_add(c, compression == 6 ? &sxi_bmp_alpha_masks : &sxi_bmp_masks, at, masks)) return false;
        at += masks;
    }
    if (bits <= 8 && bits && !colors) colors = 1U << bits;
    if ((uint64_t)colors * (uint64_t)palette_size > (uint64_t)((int64_t)pixels - at) ||
        !sx_table(c, color, at, palette_size, colors)) return false;
    at += (int64_t)colors * palette_size;
    return sx_raw(c, at, (int64_t)pixels - at) && sx_raw(c, pixels, (int64_t)length - pixels);
}

static bool sx_image_gif_subblocks(sx_context *c, int64_t *at)
{
    unsigned count = 0;
    while (++count <= 100000U) {
        uint8_t n;
        if (!sx_read(c, *at, &n, 1) || !sx_add(c, &sxi_gif_subblock, *at, 1)) return false;
        ++*at;
        if (!n) return true;
        if (!sx_raw(c, *at, n)) return false;
        *at += n;
    }
    return false;
}

static bool sx_image_gif(sx_context *c)
{
    uint8_t h[13];
    int64_t at = 13;
    unsigned blocks = 0;
    if (!sx_read(c, 0, h, 13) || (xx_rt_memcmp(h, "GIF87a", 6) && xx_rt_memcmp(h, "GIF89a", 6)) ||
        !sx_add(c, &sxi_gif_header, 0, 6) || !sx_add(c, &sxi_gif_screen, 6, 7)) return false;
    if (h[10] & 0x80) {
        unsigned n = 2U << (h[10] & 7);
        if (!sx_table(c, &sxi_rgb, at, 3, n)) return false;
        at += (int64_t)n * 3;
    }
    while (++blocks <= 100000U) {
        uint8_t kind;
        if (!sx_read(c, at, &kind, 1)) return false;
        if (kind == 0x3b) return sx_add(c, &sxi_gif_trailer, at, 1);
        if (kind == 0x2c) {
            if (!sx_read(c, at, h, 10) || !sx_add(c, &sxi_gif_image, at, 10)) return false;
            at += 10;
            if (h[9] & 0x80) {
                unsigned n = 2U << (h[9] & 7);
                if (!sx_table(c, &sxi_rgb, at, 3, n)) return false;
                at += (int64_t)n * 3;
            }
            if (!sx_read(c, at, &kind, 1) || kind < 2 || kind > 8 || !sx_add(c, &sxi_gif_lzw, at, 1)) return false;
            ++at;
        } else if (kind == 0x21) {
            if (!sx_read(c, at, h, 3)) return false;
            if (h[1] == 0xf9) {
                if (h[2] != 4 || !sx_read(c, at + 7, &kind, 1) || kind || !sx_add(c, &sxi_gif_graphic, at, 8)) return false;
                at += 8;
                continue;
            }
            if (h[1] == 0xff) {
                if (h[2] != 11 || !sx_add(c, &sxi_gif_application, at, 14)) return false;
                at += 14;
            } else if (h[1] == 0x01) {
                if (h[2] != 12 || !sx_add(c, &sxi_gif_text, at, 15)) return false;
                at += 15;
            } else {
                if (!sx_add(c, &sxi_gif_extension, at, 2)) return false;
                at += 2;
            }
        } else return false;
        if (!sx_image_gif_subblocks(c, &at)) return false;
    }
    return false;
}

static bool sx_image_ico(sx_context *c)
{
    uint16_t reserved, type, count;
    uint32_t i;
    if (!sx_u16(c, 0, false, &reserved) || reserved || !sx_u16(c, 2, false, &type) || (type != 1 && type != 2) ||
        !sx_u16(c, 4, false, &count) || !count || count > 4096 || !sx_image_range(c, 6, (uint64_t)count * 16) ||
        !sx_add(c, &sxi_ico_header, 0, 6)) return false;
    for (i = 0; i < count; ++i) {
        int64_t at = 6 + (int64_t)i * 16;
        uint32_t size, off;
        if (!sx_u32(c, at + 8, false, &size) || !sx_u32(c, at + 12, false, &off) || off < 6U + (uint32_t)count * 16U || !size ||
            !sx_add(c, type == 2 ? &sxi_cur_entry : &sxi_ico_entry, at, 16) || !sx_raw(c, off, size)) return false;
    }
    return true;
}

static bool sx_image_qoi(sx_context *c)
{
    uint8_t h[14], marker[8];
    uint32_t width, height;
    uint64_t remaining;
    int64_t at = 14;
    sxi_cursor cursor = {c, -1, 0, {0}};
    if (!sx_read(c, 0, h, 14) || xx_rt_memcmp(h, "qoif", 4) || (h[12] != 3 && h[12] != 4) || h[13] > 1 ||
        !sx_u32(c, 4, true, &width) || !sx_u32(c, 8, true, &height) || !width || !height ||
        !sx_add(c, &sxi_qoi_header, 0, 14)) return false;
    remaining = (uint64_t)width * height;
    /* Follow opcode widths/runs to locate the end marker. A trailer following
     * the image must not be mistaken for image data or its terminator. */
    while (remaining) {
        uint8_t op;
        unsigned bytes = 1, pixels = 1;
        if (!sxi_byte(&cursor, at, &op)) return false;
        if (op == 0xfe) bytes = 4;
        else if (op == 0xff) bytes = 5;
        else if ((op & 0xc0) == 0x80) bytes = 2;
        else if ((op & 0xc0) == 0xc0) pixels = (op & 0x3f) + 1U;
        if (pixels > remaining || !sx_image_range(c, at, bytes)) return false;
        at += bytes;
        remaining -= pixels;
    }
    if (!sx_read(c, at, marker, 8) || xx_rt_memcmp(marker, "\0\0\0\0\0\0\0\1", 8)) return false;
    return sx_raw(c, 14, at - 14) && sx_add(c, &sxi_qoi_end, at, 8);
}

static bool sx_image_jpeg(sx_context *c)
{
    uint8_t h[18];
    int64_t at = 0;
    unsigned markers = 0;
    sxi_cursor cursor = {c, -1, 0, {0}};
    if (!sx_read(c, 0, h, 2) || h[0] != 0xff || h[1] != 0xd8) return false;
    while (++markers <= 100000U) {
        uint8_t marker;
        uint16_t length;
        int64_t end;
        if (!sx_read(c, at, h, 2) || h[0] != 0xff || !h[1]) return false;
        if (h[1] == 0xff) {
            /* Fill bytes are physical bytes, not an extra marker. */
            if (!sx_raw(c, at, 1)) return false;
            ++at;
            continue;
        }
        marker = h[1];
        if (marker == 0x01 || (marker >= 0xd0 && marker <= 0xd9)) {
            if (!sx_add(c, &sxi_jpeg_marker, at, 2)) return false;
            if (marker == 0xd9) return true;
            at += 2;
            continue;
        }
        if (!sx_u16(c, at + 2, true, &length) || length < 2 || !sx_image_range(c, at, (uint64_t)length + 2)) return false;
        end = at + length + 2;
        if (marker >= 0xc0 && marker <= 0xcf && marker != 0xc4 && marker != 0xc8 && marker != 0xcc) {
            unsigned n;
            if (length < 8 || !sx_read(c, at + 9, h, 1)) return false;
            n = h[0];
            if (!n || length != 8U + 3U * n || !sx_add(c, &sxi_jpeg_frame, at, 10) || !sx_table(c, &sxi_jpeg_component, at + 10, 3, n)) return false;
        } else if (marker == 0xda) {
            unsigned n;
            if (length < 6 || !sx_read(c, at + 4, h, 1)) return false;
            n = h[0];
            if (!n || length != 6U + 2U * n || !sx_add(c, &sxi_jpeg_scan, at, 5) ||
                !sx_table(c, &sxi_jpeg_scan_component, at + 5, 2, n) || !sx_add(c, &sxi_jpeg_scan_tail, at + 5 + (int64_t)n * 2, 3)) return false;
        } else if (marker == 0xdd) {
            if (length != 4 || !sx_add(c, &sxi_jpeg_dri, at, 6)) return false;
        } else if (marker == 0xe0 && length >= 16 && sx_read(c, at + 4, h, 5) && !xx_rt_memcmp(h, "JFIF\0", 5)) {
            if (!sx_add(c, &sxi_jpeg_jfif, at, 18) || !sx_raw(c, at + 18, length - 16)) return false;
        } else if (marker == 0xdb || marker == 0xc4) {
            int64_t p = at + 4;
            if (!sx_add(c, &sxi_jpeg_segment, at, 4)) return false;
            while (p < end) {
                if (marker == 0xdb) {
                    unsigned n;
                    if (!sx_read(c, p, h, 1) || (h[0] >> 4) > 1 || (h[0] & 15) > 3) return false;
                    n = (h[0] >> 4) ? 129 : 65;
                    if (n > (uint64_t)(end - p) || !sx_add(c, n == 129 ? &sxi_jpeg_dqt16 : &sxi_jpeg_dqt8, p, n)) return false;
                    p += n;
                } else {
                    unsigned n = 0, i;
                    if (end - p < 17 || !sx_read(c, p, h, 17) || (h[0] >> 4) > 1 || (h[0] & 15) > 3) return false;
                    for (i = 1; i <= 16; ++i) n += h[i];
                    if (n > 256 || n > (uint64_t)(end - p - 17) || !sx_add(c, &sxi_jpeg_dht, p, 17) || !sx_raw(c, p + 17, n)) return false;
                    p += (int64_t)n + 17;
                }
            }
        } else if (!sx_add(c, &sxi_jpeg_segment, at, 4) || !sx_raw(c, at + 4, length - 2)) return false;
        at = end;
        if (marker == 0xda) {
            int64_t start = at;
            /* Entropy-coded bytes contain FF00 stuffing and restart markers.
             * Emit restart markers separately without decoding sample data. */
            for (;;) {
                if (!sxi_byte(&cursor, at, h)) return false;
                if (h[0] != 0xff) { ++at; continue; }
                if (!sxi_byte(&cursor, at + 1, h + 1)) return false;
                if (h[1] == 0) { at += 2; continue; }
                if (h[1] >= 0xd0 && h[1] <= 0xd7) {
                    if (!sx_raw(c, start, at - start) || !sx_add(c, &sxi_jpeg_marker, at, 2)) return false;
                    at += 2;
                    start = at;
                    continue;
                }
                if (!sx_raw(c, start, at - start)) return false;
                break;
            }
        }
    }
    return false;
}

static unsigned sx_image_tiff_width(uint16_t type)
{
    static const unsigned widths[19] = {0, 1, 1, 2, 4, 8, 1, 1, 2, 4, 8, 4, 8, 4, 0, 0, 8, 8, 8};
    return type < SX_COUNT(widths) ? widths[type] : 0;
}

static bool sx_image_tiff_queue(uint64_t *queue, size_t *count, uint64_t offset, const sx_context *c, bool big)
{
    size_t i;
    if (!offset) return true;
    if (*count >= 1024 || offset < (big ? 16U : 8U) || offset >= (uint64_t)c->size) return false;
    for (i = 0; i < *count; ++i) if (queue[i] == offset) return false;
    queue[(*count)++] = offset;
    return true;
}

static bool sx_image_tiff(sx_context *c)
{
    uint8_t magic[2];
    uint16_t version, value16;
    uint32_t value32;
    uint64_t queue[1024], first;
    size_t count = 0, index = 0;
    bool be, big;
    const sx_layout *header, *counter, *next_layout, *inline_entry, *offset_entry;
    if (!sx_read(c, 0, magic, 2) || ((magic[0] != 'I' || magic[1] != 'I') && (magic[0] != 'M' || magic[1] != 'M'))) return false;
    be = magic[0] == 'M';
    if (!sx_u16(c, 2, be, &version) || (version != 42 && version != 43)) return false;
    big = version == 43;
    if (big) {
        if (!sx_u16(c, 4, be, &value16) || value16 != 8 || !sx_u16(c, 6, be, &value16) || value16 || !sx_u64(c, 8, be, &first)) return false;
        header = be ? &sxi_bigtiff_header_be : &sxi_bigtiff_header_le;
        counter = be ? &sxi_bigtiff_count_be : &sxi_bigtiff_count_le;
        next_layout = be ? &sxi_bigtiff_next_be : &sxi_bigtiff_next_le;
        inline_entry = be ? &sxi_bigtiff_entry_inline_be : &sxi_bigtiff_entry_inline_le;
        offset_entry = be ? &sxi_bigtiff_entry_offset_be : &sxi_bigtiff_entry_offset_le;
    } else {
        if (!sx_u32(c, 4, be, &value32)) return false;
        first = value32;
        header = be ? &sxi_tiff_header_be : &sxi_tiff_header_le;
        counter = be ? &sxi_tiff_count_be : &sxi_tiff_count_le;
        next_layout = be ? &sxi_tiff_next_be : &sxi_tiff_next_le;
        inline_entry = be ? &sxi_tiff_entry_inline_be : &sxi_tiff_entry_inline_le;
        offset_entry = be ? &sxi_tiff_entry_offset_be : &sxi_tiff_entry_offset_le;
    }
    if (!sx_add(c, header, 0, big ? 16 : 8) || !first || !sx_image_tiff_queue(queue, &count, first, c, big)) return false;
    while (index < count) {
        uint64_t n, i, next;
        unsigned count_size = big ? 8 : 2, entry_size = big ? 20 : 12, next_size = big ? 8 : 4;
        int64_t at = (int64_t)queue[index++], table;
        if (big) { if (!sx_u64(c, at, be, &n)) return false; }
        else { if (!sx_u16(c, at, be, &value16)) return false; n = value16; }
        if (n > 65536 || !sx_image_range(c, at, count_size + n * entry_size + next_size) || !sx_add(c, counter, at, count_size)) return false;
        table = at + count_size;
        for (i = 0; i < n; ++i) {
            int64_t p = table + (int64_t)i * entry_size, data;
            uint16_t tag, type;
            uint64_t elements, bytes, offset;
            unsigned width;
            if (!sx_u16(c, p, be, &tag) || !sx_u16(c, p + 2, be, &type) || !(width = sx_image_tiff_width(type)) || (!big && type >= 16)) return false;
            if (big) { if (!sx_u64(c, p + 4, be, &elements)) return false; }
            else { if (!sx_u32(c, p + 4, be, &value32)) return false; elements = value32; }
            if (elements > (uint64_t)INT64_MAX / width) return false;
            bytes = elements * width;
            data = p + (big ? 12 : 8);
            if (bytes > next_size) {
                if (big) { if (!sx_u64(c, data, be, &offset)) return false; }
                else { if (!sx_u32(c, data, be, &value32)) return false; offset = value32; }
                if (offset > INT64_MAX || !sx_image_range(c, (int64_t)offset, bytes) || !sx_add(c, offset_entry, p, entry_size) || !sx_raw(c, (int64_t)offset, (int64_t)bytes)) return false;
                data = (int64_t)offset;
            } else if (!sx_add(c, inline_entry, p, entry_size)) return false;
            /* TIFF SubIFDs and EXIF/GPS/interoperability directory pointers
             * use the same physical directory syntax. */
            if (tag == 330 || tag == 34665 || tag == 34853 || tag == 40965) {
                uint64_t j;
                if (elements > 1024 || (type != 4 && type != 13 && type != 16 && type != 18)) return false;
                for (j = 0; j < elements; ++j) {
                    int64_t pos = data + (int64_t)j * width;
                    if (width == 8) { if (!sx_u64(c, pos, be, &offset)) return false; }
                    else { if (!sx_u32(c, pos, be, &value32)) return false; offset = value32; }
                    if (!sx_image_tiff_queue(queue, &count, offset, c, big)) return false;
                }
            }
        }
        at = table + (int64_t)n * entry_size;
        if (big) { if (!sx_u64(c, at, be, &next)) return false; }
        else { if (!sx_u32(c, at, be, &value32)) return false; next = value32; }
        if (!sx_add(c, next_layout, at, next_size) || !sx_image_tiff_queue(queue, &count, next, c, big)) return false;
    }
    return true;
}

static bool sx_image_supports(xx_file_type_t type)
{
    return type == XX_FILE_TYPE_PNG || type == XX_FILE_TYPE_BMP || type == XX_FILE_TYPE_GIF || type == XX_FILE_TYPE_ICO ||
           type == XX_FILE_TYPE_QOI || type == XX_FILE_TYPE_JPEG || type == XX_FILE_TYPE_TIFF;
}

static bool sx_image_build(sx_context *c)
{
    switch (c->f->file_type) {
        case XX_FILE_TYPE_PNG: return sx_image_png(c);
        case XX_FILE_TYPE_BMP: return sx_image_bmp(c);
        case XX_FILE_TYPE_GIF: return sx_image_gif(c);
        case XX_FILE_TYPE_ICO: return sx_image_ico(c);
        case XX_FILE_TYPE_QOI: return sx_image_qoi(c);
        case XX_FILE_TYPE_JPEG: return sx_image_jpeg(c);
        case XX_FILE_TYPE_TIFF: return sx_image_tiff(c);
        default: return false;
    }
}

static bool sx_image_comment(xx_data_struct_record *rec, uint32_t id)
{
    uint64_t v;
    const wchar_t *comment = NULL;
    wchar_t formatted[256];
    char ascii[256];
    if (!rec || !rec->name || id < UINT32_C(0x60010001) || id >= UINT32_C(0x60020000)) return true;
    v = xx_var_get_u64(&rec->value);
    if (id == sxi_png_ihdr.id && !xx_rt_wcscmp(rec->name, L"color_type")) {
        switch (v) {
            case 0: comment = L"Grayscale"; break;
            case 2: comment = L"Truecolor"; break;
            case 3: comment = L"Indexed-color"; break;
            case 4: comment = L"Grayscale with alpha"; break;
            case 6: comment = L"Truecolor with alpha"; break;
        }
    } else if (id == sxi_png_ihdr.id && !xx_rt_wcscmp(rec->name, L"compression_method") && v == 0) comment = L"Deflate/inflate";
    else if (id == sxi_png_ihdr.id && !xx_rt_wcscmp(rec->name, L"filter_method") && v == 0) comment = L"Adaptive filtering";
    else if (id == sxi_png_ihdr.id && !xx_rt_wcscmp(rec->name, L"interlace_method")) comment = v == 0 ? L"No interlace" : v == 1 ? L"Adam7" : NULL;
    else if (id == sxi_png_phys.id && !xx_rt_wcscmp(rec->name, L"unit_specifier")) comment = v == 0 ? L"Unknown unit" : v == 1 ? L"Metre" : NULL;
    else if (id == sxi_png_srgb.id && !xx_rt_wcscmp(rec->name, L"rendering_intent")) comment = v == 0 ? L"Perceptual" : v == 1 ? L"Relative colorimetric" : v == 2 ? L"Saturation" : v == 3 ? L"Absolute colorimetric" : NULL;
    else if (id == sxi_png_fctl.id && !xx_rt_wcscmp(rec->name, L"dispose_op")) comment = v == 0 ? L"APNG_DISPOSE_OP_NONE" : v == 1 ? L"APNG_DISPOSE_OP_BACKGROUND" : v == 2 ? L"APNG_DISPOSE_OP_PREVIOUS" : NULL;
    else if (id == sxi_png_fctl.id && !xx_rt_wcscmp(rec->name, L"blend_op")) comment = v == 0 ? L"APNG_BLEND_OP_SOURCE" : v == 1 ? L"APNG_BLEND_OP_OVER" : NULL;
    else if ((id == sxi_bmp_info.id || id == sxi_bmp_v4.id || id == sxi_bmp_v5.id) && (!xx_rt_wcscmp(rec->name, L"biCompression") || !xx_rt_wcscmp(rec->name, L"bV4V4Compression") || !xx_rt_wcscmp(rec->name, L"bV5Compression"))) {
        switch (v) {
            case 0: comment = L"BI_RGB"; break; case 1: comment = L"BI_RLE8"; break;
            case 2: comment = L"BI_RLE4"; break; case 3: comment = L"BI_BITFIELDS"; break;
            case 4: comment = L"BI_JPEG"; break; case 5: comment = L"BI_PNG"; break;
            case 6: comment = L"BI_ALPHABITFIELDS"; break;
        }
    } else if (id == sxi_ico_header.id && !xx_rt_wcscmp(rec->name, L"idType")) comment = v == 1 ? L"Icon" : v == 2 ? L"Cursor" : NULL;
    else if ((id == sxi_ico_entry.id || id == sxi_cur_entry.id) && (!xx_rt_wcscmp(rec->name, L"bWidth") || !xx_rt_wcscmp(rec->name, L"bHeight")) && v == 0) comment = L"256 pixels";
    else if (id == sxi_qoi_header.id && !xx_rt_wcscmp(rec->name, L"colorspace")) comment = v == 0 ? L"sRGB with linear alpha" : v == 1 ? L"All channels linear" : NULL;
    else if ((id == sxi_gif_screen.id || id == sxi_gif_image.id || id == sxi_gif_graphic.id) && !xx_rt_wcscmp(rec->name, L"packed_fields")) {
        if (id == sxi_gif_screen.id)
            xx_rt_snprintf(ascii, sizeof(ascii), "GlobalColorTable=%u|ColorResolution=%u|Sorted=%u|TableEntries=%u", (unsigned)(v >> 7) & 1U,
                           ((unsigned)(v >> 4) & 7U) + 1U, (unsigned)(v >> 3) & 1U, 2U << (v & 7U));
        else if (id == sxi_gif_image.id)
            xx_rt_snprintf(ascii, sizeof(ascii), "LocalColorTable=%u|Interlaced=%u|Sorted=%u|Reserved=0x%X|TableEntries=%u", (unsigned)(v >> 7) & 1U,
                           (unsigned)(v >> 6) & 1U, (unsigned)(v >> 5) & 1U, (unsigned)v & 0x18U, 2U << (v & 7U));
        else
            xx_rt_snprintf(ascii, sizeof(ascii), "Reserved=0x%X|DisposalMethod=%u|UserInput=%u|Transparency=%u", (unsigned)v & 0xe0U,
                           (unsigned)(v >> 2) & 7U, (unsigned)(v >> 1) & 1U, (unsigned)v & 1U);
        for (size_t i = 0; i < sizeof(formatted) / sizeof(formatted[0]); ++i) {
            formatted[i] = (wchar_t)(unsigned char)ascii[i];
            if (!ascii[i]) break;
        }
        comment = formatted;
    }
    else if (!xx_rt_wcscmp(rec->name, L"marker") && id >= sxi_jpeg_marker.id && id <= sxi_jpeg_dht.id) {
        switch (v) {
            case 0xffd8: comment = L"SOI"; break; case 0xffd9: comment = L"EOI"; break;
            case 0xffda: comment = L"SOS"; break; case 0xffdb: comment = L"DQT"; break;
            case 0xffc4: comment = L"DHT"; break; case 0xffdd: comment = L"DRI"; break;
            case 0xffc0: comment = L"SOF0"; break; case 0xffc1: comment = L"SOF1"; break;
            case 0xffc2: comment = L"SOF2"; break; case 0xffc3: comment = L"SOF3"; break;
            case 0xffe0: comment = L"APP0"; break; case 0xffe1: comment = L"APP1"; break;
            case 0xfffe: comment = L"COM"; break;
        }
        if (!comment && ((v >= 0xffe0 && v <= 0xffef) || (v >= 0xffd0 && v <= 0xffd7))) {
            xx_rt_snprintf(ascii, sizeof(ascii), "%s%u", v >= 0xffe0 ? "APP" : "RST", (unsigned)(v & 15U));
            for (size_t i = 0; i < sizeof(formatted) / sizeof(formatted[0]); ++i) {
                formatted[i] = (wchar_t)(unsigned char)ascii[i];
                if (!ascii[i]) break;
            }
            comment = formatted;
        }
    } else if (id >= sxi_tiff_header_le.id && !xx_rt_wcscmp(rec->name, L"field_type")) {
        switch (v) {
            case 1: comment = L"TIFF_BYTE"; break; case 2: comment = L"TIFF_ASCII"; break;
            case 3: comment = L"TIFF_SHORT"; break; case 4: comment = L"TIFF_LONG"; break;
            case 5: comment = L"TIFF_RATIONAL"; break; case 6: comment = L"TIFF_SBYTE"; break;
            case 7: comment = L"TIFF_UNDEFINED"; break; case 8: comment = L"TIFF_SSHORT"; break;
            case 9: comment = L"TIFF_SLONG"; break; case 10: comment = L"TIFF_SRATIONAL"; break;
            case 11: comment = L"TIFF_FLOAT"; break; case 12: comment = L"TIFF_DOUBLE"; break;
            case 13: comment = L"TIFF_IFD"; break; case 16: comment = L"TIFF_LONG8"; break;
            case 17: comment = L"TIFF_SLONG8"; break; case 18: comment = L"TIFF_IFD8"; break;
        }
    } else if (id >= sxi_tiff_header_le.id && !xx_rt_wcscmp(rec->name, L"tag")) {
        switch (v) {
            case 254: comment = L"NewSubfileType"; break; case 256: comment = L"ImageWidth"; break;
            case 257: comment = L"ImageLength"; break; case 258: comment = L"BitsPerSample"; break;
            case 259: comment = L"Compression"; break; case 262: comment = L"PhotometricInterpretation"; break;
            case 270: comment = L"ImageDescription"; break; case 271: comment = L"Make"; break;
            case 272: comment = L"Model"; break; case 273: comment = L"StripOffsets"; break;
            case 274: comment = L"Orientation"; break; case 277: comment = L"SamplesPerPixel"; break;
            case 278: comment = L"RowsPerStrip"; break; case 279: comment = L"StripByteCounts"; break;
            case 282: comment = L"XResolution"; break; case 283: comment = L"YResolution"; break;
            case 284: comment = L"PlanarConfiguration"; break; case 296: comment = L"ResolutionUnit"; break;
            case 305: comment = L"Software"; break; case 306: comment = L"DateTime"; break;
            case 320: comment = L"ColorMap"; break; case 322: comment = L"TileWidth"; break;
            case 323: comment = L"TileLength"; break; case 324: comment = L"TileOffsets"; break;
            case 325: comment = L"TileByteCounts"; break; case 330: comment = L"SubIFDs"; break;
            case 338: comment = L"ExtraSamples"; break; case 339: comment = L"SampleFormat"; break;
            case 34665: comment = L"ExifIFD"; break; case 34853: comment = L"GPSInfoIFD"; break;
            case 40965: comment = L"InteroperabilityIFD"; break;
        }
    }
    return !comment || xx_data_struct_record_set_comment(rec, comment);
}
