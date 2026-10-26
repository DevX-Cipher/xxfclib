/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical package/document metadata. Compressed streams, XML, opcode streams
 * and unparsed variable extensions remain RAW_DATA.
 */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_package.h"
static const xx_data_struct_field_desc sx_p_length16_fields[] = {
    SX_FIELD("data_size", "uint16", 0, 2, SX_SIZE),
};
const sx_layout sx_p_length16 = { UINT32_C(0x60070006), "length16", sx_p_length16_fields, SX_COUNT(sx_p_length16_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_alz_file_fields[] = {
    SX_FIELD("signature", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("name_size", "uint16", 4, 2, SX_SIZE),
    SX_FIELD("attributes", "uint8", 6, 1, SX_FLAGS),
    SX_FIELD("modified", "uint32", 7, 4, SX_TIME),
    SX_FIELD("descriptor", "uint8", 11, 1, SX_FLAGS),
    SX_FIELD("reserved", "uint8", 12, 1, SX_RESERVED),
};
const sx_layout sx_p_alz_file = { UINT32_C(0x6007000C), "alz_file", sx_p_alz_file_fields, SX_COUNT(sx_p_alz_file_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_ha_file_fields[] = {
    SX_FIELD("version_method", "uint8", 0, 1, SX_ID),
    SX_FIELD("packed_size", "uint32", 1, 4, SX_SIZE),
    SX_FIELD("original_size", "uint32", 5, 4, SX_SIZE),
    SX_FIELD("crc32", "uint32", 9, 4, SX_CHECKSUM),
    SX_FIELD("modified", "uint32", 13, 4, SX_TIME),
};
const sx_layout sx_p_ha_file = { UINT32_C(0x60070016), "ha_file", sx_p_ha_file_fields, SX_COUNT(sx_p_ha_file_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_zoo_directory_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("type", "uint8", 4, 1, SX_ID),
    SX_FIELD("method", "uint8", 5, 1, SX_ID),
    SX_FIELD("next_directory", "uint32", 6, 4, SX_OFFSET),
    SX_FIELD("data_offset", "uint32", 10, 4, SX_OFFSET),
    SX_FIELD("date", "uint16", 14, 2, SX_NONE),
    SX_FIELD("time", "uint16", 16, 2, SX_NONE),
    SX_FIELD("crc16", "uint16", 18, 2, SX_CHECKSUM),
    SX_FIELD("original_size", "uint32", 20, 4, SX_SIZE),
    SX_FIELD("packed_size", "uint32", 24, 4, SX_SIZE),
    SX_FIELD("version_major", "uint8", 28, 1, SX_NONE),
    SX_FIELD("version_minor", "uint8", 29, 1, SX_NONE),
    SX_FIELD("deleted", "uint8", 30, 1, SX_FLAGS),
    SX_FIELD("file_structure", "uint8", 31, 1, SX_ID),
    SX_FIELD("comment_offset", "uint32", 32, 4, SX_OFFSET),
    SX_FIELD("comment_size", "uint16", 36, 2, SX_SIZE),
    SX_FIELD("short_name", "char[13]", 38, 13, SX_STRING),
};
const sx_layout sx_p_zoo_directory = { UINT32_C(0x60070019), "zoo_directory", sx_p_zoo_directory_fields, SX_COUNT(sx_p_zoo_directory_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_zlib_header_fields[] = {
    SX_FIELD("compression_method_flags", "uint8", 0, 1, SX_FLAGS),
    SX_FIELD("flags", "uint8", 1, 1, SX_FLAGS),
};
const sx_layout sx_p_zlib_header = { UINT32_C(0x60070023), "zlib_header", sx_p_zlib_header_fields, SX_COUNT(sx_p_zlib_header_fields), SX_BE };
static const xx_data_struct_field_desc sx_p_lzma_header_fields[] = {
    SX_FIELD("properties", "uint8", 0, 1, SX_FLAGS),
    SX_FIELD("dictionary_size", "uint32", 1, 4, SX_SIZE),
    SX_FIELD("original_size", "uint64", 5, 8, SX_SIZE),
};
static const sx_layout sx_p_lzma_header = { UINT32_C(0x60070026), "lzma_header", sx_p_lzma_header_fields, SX_COUNT(sx_p_lzma_header_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_lzma86_filter_fields[] = {
    SX_FIELD("filter", "uint8", 0, 1, SX_ID),
};
static const sx_layout sx_p_lzma86_filter = { UINT32_C(0x60070027), "lzma86_filter", sx_p_lzma86_filter_fields, SX_COUNT(sx_p_lzma86_filter_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_xar_header_fields[] = {
    SX_FIELD("signature", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("header_size", "uint16", 4, 2, SX_SIZE),
    SX_FIELD("version", "uint16", 6, 2, SX_NONE),
    SX_FIELD("toc_packed_size", "uint64", 8, 8, SX_SIZE),
    SX_FIELD("toc_original_size", "uint64", 16, 8, SX_SIZE),
    SX_FIELD("checksum_algorithm", "uint32", 24, 4, SX_ID),
};
const sx_layout sx_p_xar_header = { UINT32_C(0x60070028), "xar_header", sx_p_xar_header_fields, SX_COUNT(sx_p_xar_header_fields), SX_BE };
static const xx_data_struct_field_desc sx_p_rpm_index_fields[] = {
    SX_FIELD("tag", "uint32", 0, 4, SX_ID),
    SX_FIELD("type", "uint32", 4, 4, SX_ID),
    SX_FIELD("data_offset", "uint32", 8, 4, SX_OFFSET),
    SX_FIELD("count", "uint32", 12, 4, SX_COUNT_PROP),
};
const sx_layout sx_p_rpm_index = { UINT32_C(0x6007002B), "rpm_index", sx_p_rpm_index_fields, SX_COUNT(sx_p_rpm_index_fields), SX_BE };
static const xx_data_struct_field_desc sx_p_cfbf_header_fields[] = {
    SX_FIELD("signature", "bytes", 0, 8, SX_SIGNATURE),
    SX_FIELD("clsid", "bytes", 8, 16, SX_ID),
    SX_FIELD("minor_version", "uint16", 24, 2, SX_NONE),
    SX_FIELD("major_version", "uint16", 26, 2, SX_NONE),
    SX_FIELD("byte_order", "uint16", 28, 2, SX_ID),
    SX_FIELD("sector_shift", "uint16", 30, 2, SX_NONE),
    SX_FIELD("mini_sector_shift", "uint16", 32, 2, SX_NONE),
    SX_FIELD("reserved", "bytes", 34, 6, SX_RESERVED),
    SX_FIELD("directory_sector_count", "uint32", 40, 4, SX_COUNT_PROP),
    SX_FIELD("fat_sector_count", "uint32", 44, 4, SX_COUNT_PROP),
    SX_FIELD("first_directory_sector", "uint32", 48, 4, SX_ID),
    SX_FIELD("transaction_signature", "uint32", 52, 4, SX_SIGNATURE),
    SX_FIELD("mini_stream_cutoff", "uint32", 56, 4, SX_SIZE),
    SX_FIELD("first_mini_fat_sector", "uint32", 60, 4, SX_ID),
    SX_FIELD("mini_fat_sector_count", "uint32", 64, 4, SX_COUNT_PROP),
    SX_FIELD("first_difat_sector", "uint32", 68, 4, SX_ID),
    SX_FIELD("difat_sector_count", "uint32", 72, 4, SX_COUNT_PROP),
};
static const sx_layout sx_p_cfbf_header = { UINT32_C(0x6007002C), "cfbf_header", sx_p_cfbf_header_fields, SX_COUNT(sx_p_cfbf_header_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_cfbf_sector_id_fields[] = {
    SX_FIELD("sector_id", "uint32", 0, 4, SX_ID),
};
static const sx_layout sx_p_cfbf_sector_id = { UINT32_C(0x6007002D), "cfbf_sector_id", sx_p_cfbf_sector_id_fields, SX_COUNT(sx_p_cfbf_sector_id_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_cfbf_directory_fields[] = {
    SX_FIELD("name_utf16", "bytes", 0, 64, SX_STRING),
    SX_FIELD("name_size", "uint16", 64, 2, SX_SIZE),
    SX_FIELD("object_type", "uint8", 66, 1, SX_ID),
    SX_FIELD("color", "uint8", 67, 1, SX_ID),
    SX_FIELD("left_sibling", "uint32", 68, 4, SX_ID),
    SX_FIELD("right_sibling", "uint32", 72, 4, SX_ID),
    SX_FIELD("child", "uint32", 76, 4, SX_ID),
    SX_FIELD("clsid", "bytes", 80, 16, SX_ID),
    SX_FIELD("state_bits", "uint32", 96, 4, SX_FLAGS),
    SX_FIELD("created", "uint64", 100, 8, SX_TIME),
    SX_FIELD("modified", "uint64", 108, 8, SX_TIME),
    SX_FIELD("first_sector", "uint32", 116, 4, SX_ID),
    SX_FIELD("stream_size", "uint64", 120, 8, SX_SIZE),
};
static const sx_layout sx_p_cfbf_directory = { UINT32_C(0x6007002E), "cfbf_directory", sx_p_cfbf_directory_fields, SX_COUNT(sx_p_cfbf_directory_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_chm_itsf2_fields[] = {
    SX_FIELD("signature", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("version", "uint32", 4, 4, SX_NONE),
    SX_FIELD("header_size", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("unknown", "uint32", 12, 4, SX_NONE),
    SX_FIELD("timestamp", "uint32", 16, 4, SX_NONE),
    SX_FIELD("language_id", "uint32", 20, 4, SX_ID),
    SX_FIELD("directory_guid", "bytes", 24, 16, SX_ID),
    SX_FIELD("stream_guid", "bytes", 40, 16, SX_ID),
    SX_FIELD("section0_offset", "uint64", 56, 8, SX_OFFSET),
    SX_FIELD("section0_size", "uint64", 64, 8, SX_SIZE),
    SX_FIELD("directory_offset", "uint64", 72, 8, SX_OFFSET),
    SX_FIELD("directory_size", "uint64", 80, 8, SX_SIZE),
};
const sx_layout sx_p_chm_itsf2 = { UINT32_C(0x6007002F), "chm_itsf2", sx_p_chm_itsf2_fields, SX_COUNT(sx_p_chm_itsf2_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_chm_itsf3_fields[] = {
    SX_FIELD("signature", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("version", "uint32", 4, 4, SX_NONE),
    SX_FIELD("header_size", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("unknown", "uint32", 12, 4, SX_NONE),
    SX_FIELD("timestamp", "uint32", 16, 4, SX_NONE),
    SX_FIELD("language_id", "uint32", 20, 4, SX_ID),
    SX_FIELD("directory_guid", "bytes", 24, 16, SX_ID),
    SX_FIELD("stream_guid", "bytes", 40, 16, SX_ID),
    SX_FIELD("section0_offset", "uint64", 56, 8, SX_OFFSET),
    SX_FIELD("section0_size", "uint64", 64, 8, SX_SIZE),
    SX_FIELD("directory_offset", "uint64", 72, 8, SX_OFFSET),
    SX_FIELD("directory_size", "uint64", 80, 8, SX_SIZE),
    SX_FIELD("data_offset", "uint64", 88, 8, SX_OFFSET),
};
const sx_layout sx_p_chm_itsf3 = { UINT32_C(0x60070030), "chm_itsf3", sx_p_chm_itsf3_fields, SX_COUNT(sx_p_chm_itsf3_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_tnef_attribute_fields[] = {
    SX_FIELD("level", "uint8", 0, 1, SX_ID),
    SX_FIELD("attribute_id", "uint32", 1, 4, SX_ID),
    SX_FIELD("data_size", "uint32", 5, 4, SX_SIZE),
};
const sx_layout sx_p_tnef_attribute = { UINT32_C(0x60070036), "tnef_attribute", sx_p_tnef_attribute_fields, SX_COUNT(sx_p_tnef_attribute_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_wim_resource_fields[] = {
    SX_FIELD("size_and_flags", "uint64", 0, 8, SX_FLAGS),
    SX_FIELD("offset", "uint64", 8, 8, SX_OFFSET),
    SX_FIELD("original_size", "uint64", 16, 8, SX_SIZE),
};
const sx_layout sx_p_wim_resource = { UINT32_C(0x60070039), "wim_resource", sx_p_wim_resource_fields, SX_COUNT(sx_p_wim_resource_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_wim_blob_fields[] = {
    SX_FIELD("size_and_flags", "uint64", 0, 8, SX_FLAGS),
    SX_FIELD("offset", "uint64", 8, 8, SX_OFFSET),
    SX_FIELD("original_size", "uint64", 16, 8, SX_SIZE),
    SX_FIELD("part_number", "uint16", 24, 2, SX_NONE),
    SX_FIELD("reference_count", "uint32", 26, 4, SX_COUNT_PROP),
    SX_FIELD("sha1", "bytes", 30, 20, SX_CHECKSUM),
};
const sx_layout sx_p_wim_blob = { UINT32_C(0x6007003B), "wim_blob", sx_p_wim_blob_fields, SX_COUNT(sx_p_wim_blob_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_unix_compress_header_fields[] = {
    SX_FIELD("signature", "bytes", 0, 2, SX_SIGNATURE),
    SX_FIELD("flags", "uint8", 2, 1, SX_FLAGS),
};
const sx_layout sx_p_unix_compress_header = { UINT32_C(0x6007003C), "unix_compress_header", sx_p_unix_compress_header_fields, SX_COUNT(sx_p_unix_compress_header_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_unix_pack_old_header_fields[] = {
    SX_FIELD("signature", "bytes", 0, 2, SX_SIGNATURE),
    SX_FIELD("original_size_high", "uint16", 2, 2, SX_NONE),
    SX_FIELD("original_size_low", "uint16", 4, 2, SX_NONE),
};
const sx_layout sx_p_unix_pack_old_header = { UINT32_C(0x6007003E), "unix_pack_old_header", sx_p_unix_pack_old_header_fields, SX_COUNT(sx_p_unix_pack_old_header_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_snappy_chunk_fields[] = {
    SX_FIELD("type", "uint8", 0, 1, SX_ID),
    SX_FIELD("data_size", "uint24", 1, 3, SX_SIZE),
};
const sx_layout sx_p_snappy_chunk = { UINT32_C(0x6007003F), "snappy_chunk", sx_p_snappy_chunk_fields, SX_COUNT(sx_p_snappy_chunk_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_pp20_header_fields[] = {
    SX_FIELD("signature", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("efficiency", "bytes", 4, 4, SX_NONE),
};
static const sx_layout sx_p_pp20_header = { UINT32_C(0x6007004A), "pp20_header", sx_p_pp20_header_fields, SX_COUNT(sx_p_pp20_header_fields), SX_BE };
static const xx_data_struct_field_desc sx_p_pp20_trailer_fields[] = {
    SX_FIELD("original_size", "uint24", 0, 3, SX_SIZE),
    SX_FIELD("skip_bits", "uint8", 3, 1, SX_COUNT_PROP),
};
static const sx_layout sx_p_pp20_trailer = { UINT32_C(0x6007004B), "pp20_trailer", sx_p_pp20_trailer_fields, SX_COUNT(sx_p_pp20_trailer_fields), SX_BE };
static const xx_data_struct_field_desc sx_p_pp20_library_header_fields[] = {
    SX_FIELD("signature", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("hunk_original_size", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("efficiency", "bytes", 8, 4, SX_NONE),
};
static const sx_layout sx_p_pp20_library_header = { UINT32_C(0x60070052), "pp20_library_header", sx_p_pp20_library_header_fields, SX_COUNT(sx_p_pp20_library_header_fields), SX_BE };
static const xx_data_struct_field_desc sx_p_pp20_encrypted_header_fields[] = {
    SX_FIELD("signature", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("password_checksum", "uint16", 4, 2, SX_CHECKSUM),
    SX_FIELD("efficiency", "bytes", 6, 4, SX_NONE),
};
static const sx_layout sx_p_pp20_encrypted_header = { UINT32_C(0x60070053), "pp20_encrypted_header", sx_p_pp20_encrypted_header_fields, SX_COUNT(sx_p_pp20_encrypted_header_fields), SX_BE };
static const xx_data_struct_field_desc sx_p_pack_level_fields[] = {
    SX_FIELD("stored_code_count", "uint8", 0, 1, SX_COUNT_PROP),
};
const sx_layout sx_p_pack_level = { UINT32_C(0x60070059), "pack_level", sx_p_pack_level_fields, SX_COUNT(sx_p_pack_level_fields), SX_BE };
static const sx_layout *const sx_package_layouts[] = {
    &sx_p_arj_prefix,
    &sx_p_arj_main,
    &sx_p_arj_file,
    &sx_p_crc32,
    &sx_p_crc16,
    &sx_p_length16,
    &sx_p_ace_main,
    &sx_p_ace_generic,
    &sx_p_ace_file32,
    &sx_p_ace_file64,
    &sx_p_alz_header,
    &sx_p_alz_file,
    &sx_p_alz_sizes1,
    &sx_p_alz_sizes2,
    &sx_p_alz_sizes3,
    &sx_p_alz_sizes4,
    &sx_p_alz_sizes5,
    &sx_p_alz_sizes6,
    &sx_p_alz_sizes7,
    &sx_p_alz_sizes8,
    &sx_p_ha_header,
    &sx_p_ha_file,
    &sx_p_ha_machine,
    &sx_p_zoo_header,
    &sx_p_zoo_directory,
    &sx_p_zoo_variable,
    &sx_p_lha_level0,
    &sx_p_lha_level1,
    &sx_p_lha_level2,
    &sx_p_lha_level3,
    &sx_p_lha_extension2,
    &sx_p_lha_extension4,
    &sx_p_lha_os,
    &sx_p_length32,
    &sx_p_zlib_header,
    &sx_p_zlib_dictionary,
    &sx_p_zlib_trailer,
    &sx_p_lzma_header,
    &sx_p_lzma86_filter,
    &sx_p_xar_header,
    &sx_p_rpm_lead,
    &sx_p_rpm_header,
    &sx_p_rpm_index,
    &sx_p_cfbf_header,
    &sx_p_cfbf_sector_id,
    &sx_p_cfbf_directory,
    &sx_p_chm_itsf2,
    &sx_p_chm_itsf3,
    &sx_p_chm_itsp,
    &sx_p_chm_pmgl,
    &sx_p_chm_pmgi,
    &sx_p_chm_section0,
    &sx_p_tnef_header,
    &sx_p_tnef_attribute,
    &sx_p_tnef_checksum,
    &sx_p_wim_header,
    &sx_p_wim_resource,
    &sx_p_wim_boot,
    &sx_p_wim_blob,
    &sx_p_unix_compress_header,
    &sx_p_unix_pack_header,
    &sx_p_unix_pack_old_header,
    &sx_p_snappy_chunk,
    &sx_p_snappy_crc,
    &sx_p_mar_header,
    &sx_p_mar_index,
    &sx_p_mar_entry,
    &sx_p_pak_header4,
    &sx_p_pak_header5,
    &sx_p_pak_resource,
    &sx_p_pak_alias,
    &sx_p_xpak_header,
    &sx_p_xpak_codec,
    &sx_p_pp20_header,
    &sx_p_pp20_trailer,
    &sx_p_dvi_preamble,
    &sx_p_dvi_postamble,
    &sx_p_dvi_post_post,
    &sx_p_zoo_attributes,
    &sx_p_lha_unix_mode,
    &sx_p_lha_sizes64,
    &sx_p_pp20_library_header,
    &sx_p_pp20_encrypted_header,
    &sx_p_mar_signed_header,
    &sx_p_mar_signature,
    &sx_p_mar_sections,
    &sx_p_mar_section,
    &sx_p_pack_tree,
    &sx_p_pack_level,
    &sx_p_pack_literal,
    &sx_p_dvi_page,
    &sx_p_pack_old_tree,
    &sx_p_pack_old_node,
    &sx_p_pack_old_wide_node,
};
/* Arithmetic is relative to the selected format base. Sector IDs, bit counts
 * and packed flags are deliberately not labelled byte offsets or byte sizes. */
bool sx_p_span(sx_context *c,uint64_t off,uint64_t size) { return off<=(uint64_t)c->size&&size<=(uint64_t)c->size-off; }
bool sx_p_sig(sx_context *c,int64_t off,const char *sig,size_t n) { uint8_t b[16];return n<=sizeof(b)&&sx_read(c,off,b,n)&&!xx_rt_memcmp(b,sig,n); }
bool sx_p_byte(sx_context *c,int64_t off,uint8_t *v) {return sx_read(c,off,v,1);}
bool sx_p_uint(sx_context *c,int64_t off,unsigned n,uint64_t *v) {uint8_t b[8];if(!n||n>8||!sx_read(c,off,b,n))return false;*v=0;for(unsigned i=0;i<n;i++)*v|=(uint64_t)b[i]<<(8*i);return true;}
bool sx_p_zstring(sx_context *c,int64_t *off,int64_t end) {uint8_t b;while(*off<end){if(!sx_p_byte(c,(*off)++,&b))return false;if(!b)return true;}return false;}
/* Sort non-overlapping metadata and fill every other physical byte as raw.
 * Linked metadata may arrive out of order; overlaps are malformed, not views. */
static bool sx_p_finish(sx_context *c)
{
    size_t n=c->count;int64_t end=0;
    for(size_t gap=n/2;gap;gap/=2)for(size_t i=gap;i<n;i++){xx_data_struct item=c->items[i];size_t j=i;while(j>=gap&&c->items[j-gap].offset>item.offset){c->items[j]=c->items[j-gap];j-=gap;}c->items[j]=item;}
    for(size_t i=0;i<n;i++){int64_t off=c->items[i].offset-c->f->base_address,total=c->items[i].total_size;if(off<end||!sx_p_span(c,(uint64_t)off,(uint64_t)total)||!sx_raw(c,end,off-end))return false;end=off+total;}
    if(!sx_raw(c,end,c->size-end))return false;
    for(size_t gap=c->count/2;gap;gap/=2)for(size_t i=gap;i<c->count;i++){xx_data_struct item=c->items[i];size_t j=i;while(j>=gap&&c->items[j-gap].offset>item.offset){c->items[j]=c->items[j-gap];j-=gap;}c->items[j]=item;}
    return true;
}
static bool sx_p_cfbf(sx_context *c)
{
    uint16_t major,shift;uint32_t dir,fats;
    if(!sx_p_sig(c,0,"\xd0\xcf\x11\xe0\xa1\xb1\x1a\xe1",8)||!sx_u16(c,26,false,&major)||!sx_p_sig(c,28,"\xfe\xff",2)||!sx_u16(c,30,false,&shift)||!((major==3&&shift==9)||(major==4&&shift==12))||!sx_u32(c,44,false,&fats)||!sx_u32(c,48,false,&dir)||!sx_add(c,&sx_p_cfbf_header,0,76)||!sx_table(c,&sx_p_cfbf_sector_id,76,4,109))return false;
    uint64_t sector=UINT64_C(1)<<shift;if(!sx_p_span(c,0,sector))return false;
    /* Inline DIFAT permits bounded FAT lookup. Extended DIFAT chains remain
     * raw in this revision instead of claiming a complete storage walk. */
    if(fats>109)return true;
    for(uint32_t i=0;i<fats;i++){uint32_t id;if(!sx_u32(c,76+4*i,false,&id)||id>=0xfffffffa||!sx_table(c,&sx_p_cfbf_sector_id,(int64_t)((uint64_t)(id+1)*sector),4,sector/4))return false;}
    uint64_t max=(uint64_t)c->size/sector;
    for(uint64_t seen=0;dir<0xfffffffa&&seen<max;seen++){uint64_t loc=(uint64_t)(dir+1)*sector;if(!sx_table(c,&sx_p_cfbf_directory,(int64_t)loc,128,sector/128))return false;uint64_t fi=dir/(sector/4);uint32_t fat,next;if(fi>=fats||!sx_u32(c,76+(int64_t)fi*4,false,&fat)||!sx_u32(c,(int64_t)((uint64_t)(fat+1)*sector+(dir%(sector/4))*4),false,&next))return false;if(next==0xfffffffe)return true;if(next==dir)return false;dir=next;}
    return dir==0xfffffffe;
}
static bool sx_package_supports(xx_file_type_t type)
{
    switch(type){case XX_FILE_TYPE_ARJ:case XX_FILE_TYPE_ACE:case XX_FILE_TYPE_ALZ:case XX_FILE_TYPE_HA:case XX_FILE_TYPE_ZOO:case XX_FILE_TYPE_LHA:case XX_FILE_TYPE_ZLIB:case XX_FILE_TYPE_LZMA:case XX_FILE_TYPE_LZMA86:case XX_FILE_TYPE_XAR:case XX_FILE_TYPE_RPM:case XX_FILE_TYPE_CFBF:case XX_FILE_TYPE_BINDER:case XX_FILE_TYPE_CHM:case XX_FILE_TYPE_TNEF:case XX_FILE_TYPE_WIM:case XX_FILE_TYPE_UNIX_COMPRESS:case XX_FILE_TYPE_UNIX_PACK:case XX_FILE_TYPE_SNAPPY_FRAMED:case XX_FILE_TYPE_MOZILLA_MAR:case XX_FILE_TYPE_CHROMIUM_PAK:case XX_FILE_TYPE_XPAK:case XX_FILE_TYPE_PP20:case XX_FILE_TYPE_TEX_DVI:return true;default:return false;}
}
static bool sx_package_build(sx_context *c)
{
    bool ok=false;uint8_t b[16];
    switch(c->f->file_type){
    case XX_FILE_TYPE_ARJ:ok=sx_arj_build(c);break;case XX_FILE_TYPE_ACE:ok=sx_ace_build(c);break;case XX_FILE_TYPE_ALZ:ok=sx_alz_build(c);break;case XX_FILE_TYPE_HA:ok=sx_ha_build(c);break;case XX_FILE_TYPE_ZOO:ok=sx_zoo_build(c);break;case XX_FILE_TYPE_LHA:ok=sx_lha_build(c);break;
    case XX_FILE_TYPE_ZLIB:ok=sx_zlib_build(c);break;
    case XX_FILE_TYPE_LZMA:case XX_FILE_TYPE_LZMA86:{int off=c->f->file_type==XX_FILE_TYPE_LZMA86?1:0;if(off&&(!sx_p_byte(c,0,b)||*b>1||!sx_add(c,&sx_p_lzma86_filter,0,1)))break;ok=sx_p_byte(c,off,b)&&*b<225&&sx_add(c,&sx_p_lzma_header,off,13);break;}
    case XX_FILE_TYPE_XAR:ok=sx_xar_build(c);break;
    case XX_FILE_TYPE_RPM:ok=sx_rpm_build(c);break;case XX_FILE_TYPE_CFBF:case XX_FILE_TYPE_BINDER:ok=sx_p_cfbf(c);break;case XX_FILE_TYPE_CHM:ok=sx_chm_build(c);break;case XX_FILE_TYPE_TNEF:ok=sx_tnef_build(c);break;case XX_FILE_TYPE_WIM:ok=sx_wim_build(c);break;
    case XX_FILE_TYPE_UNIX_COMPRESS:ok=sx_unixcompress_build(c);break;
    case XX_FILE_TYPE_UNIX_PACK:ok=sx_unixpack_build(c);break;
    case XX_FILE_TYPE_SNAPPY_FRAMED:ok=sx_snappy_framed_build(c);break;case XX_FILE_TYPE_MOZILLA_MAR:ok=sx_mozilla_mar_build(c);break;case XX_FILE_TYPE_CHROMIUM_PAK:ok=sx_chromium_pak_build(c);break;
    case XX_FILE_TYPE_XPAK:ok=sx_xpak_build(c);break;
    case XX_FILE_TYPE_PP20:{
        int header=8;const sx_layout *layout=&sx_p_pp20_header;
        if(!sx_read(c,0,b,4))break;
        if(!xx_rt_memcmp(b,"PPLS",4)){header=12;layout=&sx_p_pp20_library_header;}else if(!xx_rt_memcmp(b,"PX20",4)){header=10;layout=&sx_p_pp20_encrypted_header;}else if(xx_rt_memcmp(b,"PP20",4)&&xx_rt_memcmp(b,"PP11",4)&&xx_rt_memcmp(b,"PPBK",4))break;
        if(c->size<header+5||(c->size&3)||!sx_read(c,header-4,b,4))break;
        bool widths=true;for(unsigned i=0;i<4;i++)if(b[i]<9||b[i]>16||(i&&b[i]<b[i-1]))widths=false;
        ok=widths&&sx_add(c,layout,0,header)&&sx_p_byte(c,c->size-1,b)&&*b<=31&&sx_add(c,&sx_p_pp20_trailer,c->size-4,4);break;}

    case XX_FILE_TYPE_TEX_DVI:ok=sx_tex_dvi_build(c);break;default:return false;}
    return ok&&sx_p_finish(c);
}
static const wchar_t *sx_p_comment(uint32_t id,const wchar_t *name,uint64_t value)
{
    if((id==sx_p_chm_itsf2.id||id==sx_p_chm_itsf3.id)&&!xx_rt_wcscmp(name,L"timestamp"))return L"Encoded low 32 bits of FILETIME plus 42, modulo 2^32";
    if(id==sx_p_zoo_directory.id){if(!xx_rt_wcscmp(name,L"date"))return L"Packed MS-DOS date: year since 1980 (bits 9..15), month (5..8), day (0..4)";if(!xx_rt_wcscmp(name,L"time"))return L"Packed MS-DOS time: hour (bits 11..15), minute (5..10), two-second units (0..4)";}
    if((id==sx_p_cfbf_header.id)&&(!xx_rt_wcscmp(name,L"sector_shift")||!xx_rt_wcscmp(name,L"mini_sector_shift")))return L"log2(sector size in bytes)";
    if(id==sx_p_wim_resource.id||id==sx_p_wim_blob.id)if(!xx_rt_wcscmp(name,L"size_and_flags"))return L"Low 56 bits: packed byte size; high 8 bits: resource flags";
    if(id==sx_p_lzma_header.id){if(!xx_rt_wcscmp(name,L"properties"))return L"(pb * 5 + lp) * 9 + lc";if(!xx_rt_wcscmp(name,L"original_size")&&value==UINT64_MAX)return L"Unknown size; end marker terminates stream";}
    if(id==sx_p_lzma86_filter.id)return value==0?L"No filter":value==1?L"x86 BCJ":NULL;
    if(id==sx_p_xar_header.id&&!xx_rt_wcscmp(name,L"checksum_algorithm"))return value==0?L"NONE":value==1?L"SHA1":value==2?L"MD5":value==3?L"SHA256":value==4?L"SHA512":NULL;
    if(id==sx_p_rpm_index.id&&!xx_rt_wcscmp(name,L"type")){static const wchar_t *const names[]={L"NULL",L"CHAR",L"INT8",L"INT16",L"INT32",L"INT64",L"STRING",L"BIN",L"STRING_ARRAY",L"I18NSTRING"};return value<SX_COUNT(names)?names[value]:NULL;}
    if(id==sx_p_snappy_chunk.id&&!xx_rt_wcscmp(name,L"type"))return value==0?L"Compressed data":value==1?L"Uncompressed data":value==255?L"Stream identifier":value>=128?L"Skippable chunk":L"Reserved unskippable chunk";
    if(id==sx_p_tnef_attribute.id&&!xx_rt_wcscmp(name,L"level"))return value==1?L"Message":value==2?L"Attachment":NULL;
    if(id==sx_p_unix_compress_header.id&&!xx_rt_wcscmp(name,L"flags"))return L"Low 5 bits: maximum code width; bit 7: block mode";
    if(id==sx_p_zlib_header.id){if(!xx_rt_wcscmp(name,L"compression_method_flags"))return L"CM in bits 0..3 (8 = DEFLATE); CINFO in bits 4..7 (window log2 minus 8)";return L"FCHECK in bits 0..4; FDICT bit 5; compression level bits 6..7";}
    if(id==sx_p_alz_file.id&&!xx_rt_wcscmp(name,L"descriptor"))return L"High nibble: size-field byte width; bit 0: encrypted";
    if(id==sx_p_ha_file.id&&!xx_rt_wcscmp(name,L"version_method"))return L"High nibble: version; low nibble: method (0 stored, 1 ASC, 2 HSC)";
    if(id==sx_p_unix_pack_old_header.id&&(!xx_rt_wcscmp(name,L"original_size_high")||!xx_rt_wcscmp(name,L"original_size_low")))return L"Original size = (high << 16) | low; words are little endian";
    if(id==sx_p_pack_level.id)return L"Codewords at this depth; deepest level stores the count minus 2";
    return NULL;
}
static bool sx_package_comment(xx_data_struct_record *record,uint32_t id)
{
    if(!record||!record->name||id<UINT32_C(0x60070000)||id>=UINT32_C(0x60080000))return true;
    const wchar_t *comment=sx_p_comment(id,record->name,xx_var_get_u64(&record->value));
    return !comment||xx_data_struct_record_set_comment(record,comment);
}
const sx_family sx_package_family={sx_package_supports,sx_package_build,sx_package_layouts,SX_COUNT(sx_package_layouts),sx_package_comment};
