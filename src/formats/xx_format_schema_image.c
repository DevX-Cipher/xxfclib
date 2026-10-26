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
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_image.h"
static const xx_data_struct_field_desc sxi_png_ihdr_fields[] = {
    SX_FIELD("width", "uint32", 0, 4, SX_NONE),
    SX_FIELD("height", "uint32", 4, 4, SX_NONE),
    SX_FIELD("bit_depth", "uint8", 8, 1, SX_NONE),
    SX_FIELD("color_type", "uint8", 9, 1, SX_ID),
    SX_FIELD("compression_method", "uint8", 10, 1, SX_ID),
    SX_FIELD("filter_method", "uint8", 11, 1, SX_ID),
    SX_FIELD("interlace_method", "uint8", 12, 1, SX_ID),
};
const sx_layout sxi_png_ihdr = { UINT32_C(0x60010004), "PNG_IHDR", sxi_png_ihdr_fields, SX_COUNT(sxi_png_ihdr_fields), SX_BE };
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
const sx_layout sxi_png_fctl = { UINT32_C(0x60010006), "PNG_fcTL", sxi_png_fctl_fields, SX_COUNT(sxi_png_fctl_fields), SX_BE };
static const xx_data_struct_field_desc sxi_rgb_fields[] = {
    SX_FIELD("red", "uint8", 0, 1, SX_NONE),
    SX_FIELD("green", "uint8", 1, 1, SX_NONE),
    SX_FIELD("blue", "uint8", 2, 1, SX_NONE),
};
const sx_layout sxi_rgb = { UINT32_C(0x60010008), "RGB_COLOR", sxi_rgb_fields, SX_COUNT(sxi_rgb_fields), SX_LE };
static const xx_data_struct_field_desc sxi_png_phys_fields[] = {
    SX_FIELD("pixels_per_unit_x", "uint32", 0, 4, SX_NONE),
    SX_FIELD("pixels_per_unit_y", "uint32", 4, 4, SX_NONE),
    SX_FIELD("unit_specifier", "uint8", 8, 1, SX_ID),
};
const sx_layout sxi_png_phys = { UINT32_C(0x60010009), "PNG_pHYs", sxi_png_phys_fields, SX_COUNT(sxi_png_phys_fields), SX_BE };
static const xx_data_struct_field_desc sxi_png_srgb_fields[] = {
    SX_FIELD("rendering_intent", "uint8", 0, 1, SX_ID),
};
const sx_layout sxi_png_srgb = { UINT32_C(0x6001000C), "PNG_sRGB", sxi_png_srgb_fields, SX_COUNT(sxi_png_srgb_fields), SX_BE };
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
const sx_layout sxi_bmp_info = { UINT32_C(0x60010010), "BITMAPINFOHEADER", sxi_bmp_info_fields, SX_COUNT(sxi_bmp_info_fields), SX_LE };
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
const sx_layout sxi_bmp_v4 = { UINT32_C(0x60010011), "BITMAPV4HEADER", sxi_bmp_v4_fields, SX_COUNT(sxi_bmp_v4_fields), SX_LE };
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
const sx_layout sxi_bmp_v5 = { UINT32_C(0x60010012), "BITMAPV5HEADER", sxi_bmp_v5_fields, SX_COUNT(sxi_bmp_v5_fields), SX_LE };
static const xx_data_struct_field_desc sxi_gif_screen_fields[] = {
    SX_FIELD("logical_screen_width", "uint16", 0, 2, SX_NONE),
    SX_FIELD("logical_screen_height", "uint16", 2, 2, SX_NONE),
    SX_FIELD("packed_fields", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("background_color_index", "uint8", 5, 1, SX_NONE),
    SX_FIELD("pixel_aspect_ratio", "uint8", 6, 1, SX_NONE),
};
const sx_layout sxi_gif_screen = { UINT32_C(0x60010018), "GIF_LOGICAL_SCREEN_DESCRIPTOR", sxi_gif_screen_fields, SX_COUNT(sxi_gif_screen_fields), SX_LE };
static const xx_data_struct_field_desc sxi_gif_image_fields[] = {
    SX_FIELD("image_separator", "uint8", 0, 1, SX_SIGNATURE),
    SX_FIELD("image_left_position", "uint16", 1, 2, SX_NONE),
    SX_FIELD("image_top_position", "uint16", 3, 2, SX_NONE),
    SX_FIELD("image_width", "uint16", 5, 2, SX_NONE),
    SX_FIELD("image_height", "uint16", 7, 2, SX_NONE),
    SX_FIELD("packed_fields", "uint8", 9, 1, SX_FLAGS),
};
const sx_layout sxi_gif_image = { UINT32_C(0x60010019), "GIF_IMAGE_DESCRIPTOR", sxi_gif_image_fields, SX_COUNT(sxi_gif_image_fields), SX_LE };
static const xx_data_struct_field_desc sxi_gif_graphic_fields[] = {
    SX_FIELD("extension_introducer", "uint8", 0, 1, SX_SIGNATURE),
    SX_FIELD("graphic_control_label", "uint8", 1, 1, SX_ID),
    SX_FIELD("block_size", "uint8", 2, 1, SX_SIZE),
    SX_FIELD("packed_fields", "uint8", 3, 1, SX_FLAGS),
    SX_FIELD("delay_time", "uint16", 4, 2, SX_NONE),
    SX_FIELD("transparent_color_index", "uint8", 6, 1, SX_NONE),
    SX_FIELD("block_terminator", "uint8", 7, 1, SX_SIGNATURE),
};
const sx_layout sxi_gif_graphic = { UINT32_C(0x6001001B), "GIF_GRAPHIC_CONTROL_EXTENSION", sxi_gif_graphic_fields, SX_COUNT(sxi_gif_graphic_fields), SX_LE };
static const xx_data_struct_field_desc sxi_ico_header_fields[] = {
    SX_FIELD("idReserved", "uint16", 0, 2, SX_RESERVED),
    SX_FIELD("idType", "uint16", 2, 2, SX_ID),
    SX_FIELD("idCount", "uint16", 4, 2, SX_COUNT_PROP),
};
const sx_layout sxi_ico_header = { UINT32_C(0x60010021), "ICONDIR", sxi_ico_header_fields, SX_COUNT(sxi_ico_header_fields), SX_LE };
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
const sx_layout sxi_ico_entry = { UINT32_C(0x60010022), "ICONDIRENTRY", sxi_ico_entry_fields, SX_COUNT(sxi_ico_entry_fields), SX_LE };
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
const sx_layout sxi_cur_entry = { UINT32_C(0x60010023), "CURSORDIRENTRY", sxi_cur_entry_fields, SX_COUNT(sxi_cur_entry_fields), SX_LE };
static const xx_data_struct_field_desc sxi_qoi_header_fields[] = {
    SX_FIELD("magic", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("width", "uint32", 4, 4, SX_NONE),
    SX_FIELD("height", "uint32", 8, 4, SX_NONE),
    SX_FIELD("channels", "uint8", 12, 1, SX_COUNT_PROP),
    SX_FIELD("colorspace", "uint8", 13, 1, SX_ID),
};
const sx_layout sxi_qoi_header = { UINT32_C(0x60010024), "QOI_HEADER", sxi_qoi_header_fields, SX_COUNT(sxi_qoi_header_fields), SX_BE };
static const xx_data_struct_field_desc sxi_jpeg_marker_fields[] = {
    SX_FIELD("marker", "uint16", 0, 2, SX_ID),
};
const sx_layout sxi_jpeg_marker = { UINT32_C(0x60010026), "JPEG_MARKER", sxi_jpeg_marker_fields, SX_COUNT(sxi_jpeg_marker_fields), SX_BE };
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
const sx_layout sxi_jpeg_dht = { UINT32_C(0x60010031), "JPEG_HUFFMAN_TABLE_HEADER", sxi_jpeg_dht_fields, SX_COUNT(sxi_jpeg_dht_fields), SX_BE };
const xx_data_struct_field_desc sxi_tiff_header_le_fields[] = {
    SX_FIELD("byte_order", "char[2]", 0, 2, SX_ID),
    SX_FIELD("version", "uint16", 2, 2, SX_ID),
    SX_FIELD("first_ifd_offset", "uint32", 4, 4, SX_OFFSET),
};
const sx_layout sxi_tiff_header_le = { UINT32_C(0x60010032), "TIFF_HEADER_LE", sxi_tiff_header_le_fields, SX_COUNT(sxi_tiff_header_le_fields), SX_LE };
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
bool sx_image_range(const sx_context *c, int64_t at, uint64_t n)
{
    return c && at >= 0 && at <= c->size && n <= (uint64_t)(c->size - at);
}
bool sxi_byte(sxi_cursor *cursor, int64_t at, uint8_t *value)
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
static bool sx_image_supports(xx_file_type_t type)
{
    return type == XX_FILE_TYPE_PNG || type == XX_FILE_TYPE_BMP || type == XX_FILE_TYPE_GIF || type == XX_FILE_TYPE_ICO ||
           type == XX_FILE_TYPE_QOI || type == XX_FILE_TYPE_JPEG || type == XX_FILE_TYPE_TIFF;
}
static bool sx_image_build(sx_context *c)
{
    switch (c->f->file_type) {
        case XX_FILE_TYPE_PNG: return sx_png_build(c);
        case XX_FILE_TYPE_BMP: return sx_bmp_build(c);
        case XX_FILE_TYPE_GIF: return sx_gif_build(c);
        case XX_FILE_TYPE_ICO: return sx_ico_build(c);
        case XX_FILE_TYPE_QOI: return sx_qoi_build(c);
        case XX_FILE_TYPE_JPEG: return sx_jpeg_build(c);
        case XX_FILE_TYPE_TIFF: return sx_tiff_build(c);
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
const sx_family sx_image_family={sx_image_supports,sx_image_build,sx_image_layouts,SX_COUNT(sx_image_layouts),sx_image_comment};
