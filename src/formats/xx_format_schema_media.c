/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical image, font and scientific structures. Wire references and reader
 * scope are listed in private_tests/data_structs/media_coverage.json.
 * Encoded pixels, glyph programs, arrays and uninterpreted metadata stay RAW_DATA.
 */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_media.h"
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
const sx_layout sxm_tga_header = {UINT32_C(0x60060001), "tga_header", sxm_tga_header_fields, SX_COUNT(sxm_tga_header_fields), SX_LE};
static const xx_data_struct_field_desc sxm_be_length32_fields[] = {
    SX_FIELD("length", "uint32", 0, 4, SX_SIZE),
};
const sx_layout sxm_be_length32 = {UINT32_C(0x60060007), "be_length32", sxm_be_length32_fields, SX_COUNT(sxm_be_length32_fields), SX_BE};
static const xx_data_struct_field_desc sxm_psd_compression_fields[] = {
    SX_FIELD("compression", "uint16", 0, 2, SX_ID),
};
const sx_layout sxm_psd_compression = {UINT32_C(0x60060009), "psd_compression", sxm_psd_compression_fields, SX_COUNT(sxm_psd_compression_fields), SX_BE};
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
const sx_layout sxm_sgi_header = {UINT32_C(0x6006000B), "sgi_header", sxm_sgi_header_fields, SX_COUNT(sxm_sgi_header_fields), SX_BE};
static const xx_data_struct_field_desc sxm_le_offset32_fields[] = {
    SX_FIELD("offset", "uint32", 0, 4, SX_OFFSET),
};
static const sx_layout sxm_le_offset32 = {UINT32_C(0x6006000E), "le_offset32", sxm_le_offset32_fields, SX_COUNT(sxm_le_offset32_fields), SX_LE};
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
static const xx_data_struct_field_desc sxm_mat4_header_le_fields[] = {
    SX_FIELD("mopt", "int32", 0, 4, SX_ID),
    SX_FIELD("rows", "int32", 4, 4, SX_COUNT_PROP),
    SX_FIELD("columns", "int32", 8, 4, SX_COUNT_PROP),
    SX_FIELD("imaginary", "int32", 12, 4, SX_FLAGS),
    SX_FIELD("name_length", "int32", 16, 4, SX_SIZE),
};
const sx_layout sxm_mat4_header_le = {UINT32_C(0x6006003A), "mat4_header_le", sxm_mat4_header_le_fields, SX_COUNT(sxm_mat4_header_le_fields), SX_LE};
static const xx_data_struct_field_desc sxm_mat5_small_tag_le_fields[] = {
    SX_FIELD("type_and_length", "uint32", 0, 4, SX_FLAGS),
    SX_FIELD("inline_data", "uint8[4]", 4, 4, SX_NONE),
};
const sx_layout sxm_mat5_small_tag_le = {UINT32_C(0x6006003D), "mat5_small_tag_le", sxm_mat5_small_tag_le_fields, SX_COUNT(sxm_mat5_small_tag_le_fields), SX_LE};
static const xx_data_struct_field_desc sxm_mat4_header_be_fields[] = {
    SX_FIELD("mopt", "int32", 0, 4, SX_ID),
    SX_FIELD("rows", "int32", 4, 4, SX_COUNT_PROP),
    SX_FIELD("columns", "int32", 8, 4, SX_COUNT_PROP),
    SX_FIELD("imaginary", "int32", 12, 4, SX_FLAGS),
    SX_FIELD("name_length", "int32", 16, 4, SX_SIZE),
};
const sx_layout sxm_mat4_header_be = {UINT32_C(0x6006003E), "mat4_header_be", sxm_mat4_header_be_fields, SX_COUNT(sxm_mat4_header_be_fields), SX_BE};
static const xx_data_struct_field_desc sxm_mat5_small_tag_be_fields[] = {
    SX_FIELD("type_and_length", "uint32", 0, 4, SX_FLAGS),
    SX_FIELD("inline_data", "uint8[4]", 4, 4, SX_NONE),
};
const sx_layout sxm_mat5_small_tag_be = {UINT32_C(0x60060041), "mat5_small_tag_be", sxm_mat5_small_tag_be_fields, SX_COUNT(sxm_mat5_small_tag_be_fields), SX_BE};
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
bool sxm_span(sx_context *c,uint64_t at,uint64_t n)
{
    if(at>INT64_MAX)return false;
    return sx_range(c,(int64_t)at,n);
}
bool sxm_raw(sx_context *c,uint64_t at,uint64_t n)
{
    return n<=INT64_MAX&&sxm_span(c,at,n)&&sx_raw(c,(int64_t)at,(int64_t)n);
}
bool sxm_tail(sx_context *c,uint64_t at)
{
    return at<=(uint64_t)c->size&&sxm_raw(c,at,(uint64_t)c->size-at);
}
bool sxm_fixed(sx_context *c,const sx_layout *l,int64_t bytes)
{
    return sx_add(c,l,0,bytes)&&sxm_tail(c,(uint64_t)bytes);
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
    case XX_FILE_TYPE_TGA:return sx_tga_build(c);
    case XX_FILE_TYPE_PCX:return sx_pcx_build(c,h);
    case XX_FILE_TYPE_DDS:return sx_dds_build(c,h,n);
    case XX_FILE_TYPE_PHOTOSHOP_PSD:return sx_photoshop_psd_build(c,h,n);
    case XX_FILE_TYPE_FARBFELD:return sx_farbfeld_build(c,h,n);
    case XX_FILE_TYPE_SGI_RGB:return sx_sgi_rgb_build(c,h,n);
    case XX_FILE_TYPE_SUN_RASTER:return sx_sun_raster_build(c,h,n);
    case XX_FILE_TYPE_AVS_IMAGE:return sx_avs_image_build(c,h,n);
    case XX_FILE_TYPE_ALIAS_PIX:return sx_alias_pix_build(c,n);
    case XX_FILE_TYPE_ASTC_TEXTURE:return sx_astc_texture_build(c,h,n);
    case XX_FILE_TYPE_PKM_TEXTURE:return sx_pkm_texture_build(c,h,n);
    case XX_FILE_TYPE_KTX:return sx_ktx_build(c,h,n);
    case XX_FILE_TYPE_KTX2:return sx_ktx2_build(c,h,n);
    case XX_FILE_TYPE_PVR:return sx_pvr_build(c,h,n);
    case XX_FILE_TYPE_GIMP_GBR:case XX_FILE_TYPE_GIMP_PAT:{bool pat=c->f->file_type==XX_FILE_TYPE_GIMP_PAT;uint32_t fixed=pat?24:28,header;if(n<fixed||xx_rt_memcmp(h+20,pat?"GPAT":"GIMP",4))return false;header=xx_data_get_u32(h,n,0,true);return header>=fixed&&sxm_span(c,0,header)&&sxm_fixed(c,pat?&sxm_gimp_pat_header:&sxm_gimp_gbr_header,fixed);}
    case XX_FILE_TYPE_ICNS:return sx_icns_build(c,h,n);
    case XX_FILE_TYPE_XWD:return sx_xwd_build(c,h,n);
    case XX_FILE_TYPE_FONT_PSF:return sx_font_psf_build(c,h,n);
    case XX_FILE_TYPE_FONT_PCF:return sx_font_pcf_build(c,h,n);
    case XX_FILE_TYPE_FONT_TYPE1_PFB:return sx_font_type1_pfb_build(c);
    case XX_FILE_TYPE_FONT_BMFONT:return sx_font_bmfont_build(c,h,n);
    case XX_FILE_TYPE_PROCESSING_VLW:return sx_processing_vlw_build(c,h,n);
    case XX_FILE_TYPE_NUMPY_NPY:return sx_numpy_npy_build(c,h,n);
    case XX_FILE_TYPE_UCSC_NIB:return sx_ucsc_nib_build(c,h,n);
    case XX_FILE_TYPE_SEQUENCING_SCF:return sx_sequencing_scf_build(c,h,n);
    case XX_FILE_TYPE_SEQUENCING_ABIF:return sx_sequencing_abif_build(c,h,n);
    case XX_FILE_TYPE_GENOMICS_SFF:return sx_genomics_sff_build(c,h,n);
    case XX_FILE_TYPE_MATLAB_MAT4:return sx_matlab_mat4_build(c);
    case XX_FILE_TYPE_MATLAB_MAT5:return sx_matlab_mat5_build(c,h,n);
    case XX_FILE_TYPE_HDF4:return sx_hdf4_build(c,h,n);
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
const sx_family sx_media_family={sx_media_supports,sx_media_build,sx_media_layouts,SX_COUNT(sx_media_layouts),sx_media_comment};
