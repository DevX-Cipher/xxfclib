/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical installer and self-extractor metadata; encoded payload remains raw.
 * Scope and sources: docs/data_struct_installerlast_scope.txt. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_installerlast.h"
static const xx_data_struct_field_desc sxil_installerlast_name_fields[] = {
    SX_FIELD("name","char",0,0,SX_NONE),
};
static const sx_layout sxil_installerlast_name = {0x60850001U,"installerlast_name",sxil_installerlast_name_fields,SX_COUNT(sxil_installerlast_name_fields),SX_LE};
static const xx_data_struct_field_desc sxil_installerlast_encoded_bytes_fields[] = {
    SX_FIELD("encoded_bytes","uint8",0,0,SX_NONE),
};
static const sx_layout sxil_installerlast_encoded_bytes = {0x60850003U,"installerlast_encoded_bytes",sxil_installerlast_encoded_bytes_fields,SX_COUNT(sxil_installerlast_encoded_bytes_fields),SX_LE};
static const xx_data_struct_field_desc sxil_installerlast_decimal_size_fields[] = {
    SX_FIELD("file_size","ascii_decimal",0,0,SX_SIZE),
};
static const sx_layout sxil_installerlast_decimal_size = {0x60850004U,"installerlast_decimal_size",sxil_installerlast_decimal_size_fields,SX_COUNT(sxil_installerlast_decimal_size_fields),SX_LE};
static const xx_data_struct_field_desc sxil_installerlast_utf16_size_fields[] = {
    SX_FIELD("file_size_text","uint16",0,0,SX_NONE),
};
static const sx_layout sxil_installerlast_utf16_size = {0x60850005U,"installerlast_utf16_size",sxil_installerlast_utf16_size_fields,SX_COUNT(sxil_installerlast_utf16_size_fields),SX_LE};
static const xx_data_struct_field_desc sxil_installshield12_count_fields[] = {
    SX_FIELD("file_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxil_installshield12_count = {0x6085001eU,"installshield12_count",sxil_installshield12_count_fields,SX_COUNT(sxil_installshield12_count_fields),SX_LE};
static const xx_data_struct_field_desc sxil_installshield_ansi_base_name_fields[] = {
    SX_FIELD("base_name","char",0,0,SX_NONE),
};
static const sx_layout sxil_installshield_ansi_base_name = {0x6085001fU,"installshield_ansi_base_name",sxil_installshield_ansi_base_name_fields,SX_COUNT(sxil_installshield_ansi_base_name_fields),SX_LE};
static const xx_data_struct_field_desc sxil_installshield_utf16_base_name_fields[] = {
    SX_FIELD("base_name","uint16",0,0,SX_NONE),
};
static const sx_layout sxil_installshield_utf16_base_name = {0x60850020U,"installshield_utf16_base_name",sxil_installshield_utf16_base_name_fields,SX_COUNT(sxil_installshield_utf16_base_name_fields),SX_LE};
static const xx_data_struct_field_desc sxil_installshield_ansi_relative_path_fields[] = {
    SX_FIELD("relative_path","char",0,0,SX_NONE),
};
static const sx_layout sxil_installshield_ansi_relative_path = {0x60850021U,"installshield_ansi_relative_path",sxil_installshield_ansi_relative_path_fields,SX_COUNT(sxil_installshield_ansi_relative_path_fields),SX_LE};
static const xx_data_struct_field_desc sxil_installshield_utf16_relative_path_fields[] = {
    SX_FIELD("relative_path","uint16",0,0,SX_NONE),
};
static const sx_layout sxil_installshield_utf16_relative_path = {0x60850022U,"installshield_utf16_relative_path",sxil_installshield_utf16_relative_path_fields,SX_COUNT(sxil_installshield_utf16_relative_path_fields),SX_LE};
static const xx_data_struct_field_desc sxil_installshield_ansi_version_fields[] = {
    SX_FIELD("version","char",0,0,SX_NONE),
};
static const sx_layout sxil_installshield_ansi_version = {0x60850023U,"installshield_ansi_version",sxil_installshield_ansi_version_fields,SX_COUNT(sxil_installshield_ansi_version_fields),SX_LE};
static const xx_data_struct_field_desc sxil_installshield_utf16_version_fields[] = {
    SX_FIELD("version","uint16",0,0,SX_NONE),
};
static const sx_layout sxil_installshield_utf16_version = {0x60850024U,"installshield_utf16_version",sxil_installshield_utf16_version_fields,SX_COUNT(sxil_installshield_utf16_version_fields),SX_LE};
static const xx_data_struct_field_desc sxil_installshield7_szdd_fields[] = {
    SX_FIELD("signature","byte[8]",0,8,SX_SIGNATURE),
    SX_FIELD("method","uint8",8,1,SX_ID),
    SX_FIELD("missing_name_character","uint8",9,1,SX_NONE),
    SX_FIELD("unpacked_size","uint32",10,4,SX_SIZE),
};
static const sx_layout sxil_installshield7_szdd = {0x60850028U,"installshield7_szdd",sxil_installshield7_szdd_fields,SX_COUNT(sxil_installshield7_szdd_fields),SX_LE};
static const xx_data_struct_field_desc sxil_createinstall_record_fields[] = {
    SX_FIELD("record_type","uint8",0,1,SX_ID),
    SX_FIELD("flag","uint8",1,1,SX_FLAGS),
    SX_FIELD("attributes","uint32",2,4,SX_FLAGS),
    SX_FIELD("filetime","uint64",6,8,SX_TIME),
    SX_FIELD("method","uint8",14,1,SX_ID),
    SX_FIELD("name_length","int16",15,2,SX_SIZE),
};
static const sx_layout sxil_createinstall_record = {0x6085003aU,"createinstall_record",sxil_createinstall_record_fields,SX_COUNT(sxil_createinstall_record_fields),SX_LE};
static const xx_data_struct_field_desc sxil_createinstall_file_size_fields[] = {
    SX_FIELD("file_size","int32",0,4,SX_SIZE),
};
static const sx_layout sxil_createinstall_file_size = {0x6085003bU,"createinstall_file_size",sxil_createinstall_file_size_fields,SX_COUNT(sxil_createinstall_file_size_fields),SX_LE};
static const xx_data_struct_field_desc sxil_createinstall_prelude_fields[] = {
    SX_FIELD("carrier_size","uint32",0,4,SX_SIZE),
    SX_FIELD("unknown","uint32",4,4,SX_NONE),
    SX_FIELD("script_size","int32",8,4,SX_SIZE),
    SX_FIELD("unknown_tail","byte[6]",12,6,SX_NONE),
};
static const sx_layout sxil_createinstall_prelude = {0x6085003cU,"createinstall_prelude",sxil_createinstall_prelude_fields,SX_COUNT(sxil_createinstall_prelude_fields),SX_LE};
static const sx_layout *const sx_installerlast_layouts[] = {
    &sxil_installerlast_name,
    &sxil_installerlast_utf16_name,
    &sxil_installerlast_encoded_bytes,
    &sxil_installerlast_decimal_size,
    &sxil_installerlast_utf16_size,
    &sxil_advanced_installer_footer,
    &sxil_advanced_installer_record,
    &sxil_advanced_installer_external,
    &sxil_ardi_trailer,
    &sxil_ardi_block_tag,
    &sxil_ardi_block_length,
    &sxil_ardi_member_time,
    &sxil_ardi_chain_start,
    &sxil_arni_member,
    &sxil_arni_end,
    &sxil_ej_technologies_header,
    &sxil_ej_technologies_variable,
    &sxil_ej_technologies_extra_count,
    &sxil_ej_technologies_member,
    &sxil_ej_technologies_member_later,
    &sxil_ej_technologies_trailer,
    &sxil_ej_technologies_trailer_name,
    &sxil_ej_technologies_trailer_size,
    &sxil_ibm_zpak_sfx_header,
    &sxil_ibm_zpak_sfx_v1_directory,
    &sxil_ibm_zpak_sfx_v2_record,
    &sxil_ibm_zpak_sfx_v1_trailer,
    &sxil_ibm_zpak_sfx_v2_trailer,
    &sxil_installerlast_dcl_prelude,
    &sxil_installshield12_count,
    &sxil_installshield_ansi_base_name,
    &sxil_installshield_utf16_base_name,
    &sxil_installshield_ansi_relative_path,
    &sxil_installshield_utf16_relative_path,
    &sxil_installshield_ansi_version,
    &sxil_installshield_utf16_version,
    &sxil_installshield3_descriptor,
    &sxil_installshield3_name_size,
    &sxil_installshield3_member,
    &sxil_installshield7_szdd,
    &sxil_installshield_developer_header,
    &sxil_installshield_developer_record,
    &sxil_installshield_multiplatform_footer,
    &sxil_installshield_multiplatform_count,
    &sxil_installshield_multiplatform_record,
    &sxil_installshield_multiplatform_optional,
    &sxil_installshield_multiplatform_u64,
    &sxil_installshield_skin_encoded_name,
    &sxil_installshield_skin_encoded_size,
    &sxil_qsetup_length,
    &sxil_qsetup_record,
    &sxil_qsetup_trailer,
    &sxil_tarma_section,
    &sxil_tarma_lzma_properties,
    &sxil_tarma_separator,
    &sxil_gentee_locator,
    &sxil_gentee_block_size,
    &sxil_createinstall_record,
    &sxil_createinstall_file_size,
    &sxil_createinstall_prelude,
    &sxil_clickteam_creator_tag,
    &sxil_clickteam_creator_chunk,
    &sxil_clickteam_creator_data_chunk,
    &sxil_clickteam_creator_compression1,
    &sxil_clickteam_creator_compression2,
    &sxil_clickteam_creator_method,
    &sxil_vise_header,
    &sxil_vise_footer,
    &sxil_vise_wrapper,
    &sxil_vise_string8,
    &sxil_vise_string16,
    &sxil_vise_masked_length,
    &sxil_vise_setup_count,
    &sxil_vise_setup_fields,
    &sxil_vise_packed_size,
    &sxil_vise_object4,
    &sxil_vise_object6,
    &sxil_wise_member_crc32,
    &sxil_wise_zip_local,
    &sxil_wise_zip_central,
    &sxil_wise_zip_end,
    &sxil_ghost_encoded_cab_header,
    &sxil_ghost_encoded_cab_reserve,
    &sxil_ghost_encoded_cab_folder,
    &sxil_ghost_encoded_cab_file,
    &sxil_ghost_encoded_cab_data,
    &sxil_ghost_trailer26,
    &sxil_ghost_trailer34,
    &sxil_inno_loader_pointer,
    &sxil_inno_loader2,
    &sxil_inno_loader4,
    &sxil_inno_loader5,
    &sxil_inno_loader6,
    &sxil_inno_loader7,
    &sxil_inno_loader_revision1,
    &sxil_inno_loader_revision2,
    &sxil_inno_setup_version,
    &sxil_inno_encryption_envelope,
    &sxil_inno_block_legacy,
    &sxil_inno_block32,
    &sxil_inno_block64,
    &sxil_inno_block_crc32,
    &sxil_inno_data_marker,
};
static bool sx_installerlast_comment(xx_data_struct_record*r,uint32_t id){
    if(!r||!r->name||id<0x60850000U||id>=0x60860000U)return true;
    const wchar_t *s=NULL;
    xx_var_type_t value_type=xx_var_get_type(&r->value);
    bool integer=value_type>=XX_VAR_TYPE_INT8&&value_type<=XX_VAR_TYPE_UINT64;
    uint64_t value=integer?xx_var_get_u64(&r->value):0;(void)value;
    switch(id){
    case 0x60850001U:
        if(!xx_rt_wcscmp(r->name,L"name"))s=L"Stored byte string including terminator when present; producer codepage varies";
        break;
    case 0x60850002U:
        if(!xx_rt_wcscmp(r->name,L"name"))s=L"Stored UTF-16LE code units";
        break;
    case 0x60850003U:
        if(!xx_rt_wcscmp(r->name,L"encoded_bytes"))s=L"Encoded physical bytes; values are not substituted with plaintext";
        break;
    case 0x60850004U:
        if(!xx_rt_wcscmp(r->name,L"file_size"))s=L"Stored ASCII decimal byte count";
        break;
    case 0x60850005U:
        if(!xx_rt_wcscmp(r->name,L"file_size_text"))s=L"Stored UTF-16LE decimal byte count; code units are retained";
        break;
    case 0x60850006U:
        if(!xx_rt_wcscmp(r->name,L"mode"))s=L"0 internal payload; 1 external MSI";
        else if(!xx_rt_wcscmp(r->name,L"external_name_offset"))s=L"Executable-relative external-name block offset in mode 1; footer offset in mode 0";
        else if(!xx_rt_wcscmp(r->name,L"metadata_end"))s=L"Executable-relative footer offset";
        else if(!xx_rt_wcscmp(r->name,L"info_offset"))s=L"Executable-relative file table offset";
        else if(!xx_rt_wcscmp(r->name,L"data_offset"))s=L"Executable-relative first stored payload";
        break;
    case 0x60850007U:
        if(!xx_rt_wcscmp(r->name,L"index"))s=L"Stored member ordinal";
        else if(!xx_rt_wcscmp(r->name,L"xor_flag"))s=L"2 XORs the first min(file_size,512) bytes with 0xFF; 0 is plain";
        else if(!xx_rt_wcscmp(r->name,L"file_offset"))s=L"Executable-relative payload offset";
        else if(!xx_rt_wcscmp(r->name,L"name_length"))s=L"Number of following UTF-16LE code units";
        break;
    case 0x60850008U:
        if(!xx_rt_wcscmp(r->name,L"name_length"))s=L"Number of following UTF-16LE code units";
        break;
    case 0x60850009U:
        if(!xx_rt_wcscmp(r->name,L"builder_check"))s=L"Builder check word; algorithm not established";
        break;
    case 0x6085000bU:
        if(!xx_rt_wcscmp(r->name,L"block_size"))s=L"Total block bytes including the tag and this trailing size word";
        break;
    case 0x6085000cU:
        if(!xx_rt_wcscmp(r->name,L"modification_time"))s=L"Unix seconds";
        break;
    case 0x60850013U:
        if(!xx_rt_wcscmp(r->name,L"file_size"))s=L"Size of the following XOR-0x88 payload";
        break;
    case 0x60850014U:
        if(!xx_rt_wcscmp(r->name,L"file_size"))s=L"Size of the following XOR-0x88 payload";
        break;
    case 0x60850019U:
        if(!xx_rt_wcscmp(r->name,L"dos_date"))s=L"Packed DOS calendar date";
        else if(!xx_rt_wcscmp(r->name,L"dos_time"))s=L"Packed DOS clock time";
        break;
    case 0x6085001aU:
        if(!xx_rt_wcscmp(r->name,L"writer_scratch"))s=L"Not reserved; nonzero producer-specific values occur";
        else if(!xx_rt_wcscmp(r->name,L"dos_date"))s=L"Packed DOS calendar date";
        else if(!xx_rt_wcscmp(r->name,L"dos_time"))s=L"Packed DOS clock time";
        else if(!xx_rt_wcscmp(r->name,L"name_size"))s=L"Byte size including terminating NUL";
        break;
    case 0x6085001bU:
        if(!xx_rt_wcscmp(r->name,L"header_offset"))s=L"Executable-relative archive header";
        break;
    case 0x6085001cU:
        if(!xx_rt_wcscmp(r->name,L"header_offset"))s=L"Executable-relative archive header";
        else if(!xx_rt_wcscmp(r->name,L"adjusted_file_size"))s=L"Stored file size plus 16 times the member count";
        break;
    case 0x6085001dU:
        if(!xx_rt_wcscmp(r->name,L"dictionary_bits"))s=L"Dictionary parameter 4..6; not a byte size";
        break;
    case 0x6085001fU:
        if(!xx_rt_wcscmp(r->name,L"base_name"))s=L"Stored NUL-terminated ANSI string";
        break;
    case 0x60850020U:
        if(!xx_rt_wcscmp(r->name,L"base_name"))s=L"Stored NUL-terminated UTF-16LE string";
        break;
    case 0x60850021U:
        if(!xx_rt_wcscmp(r->name,L"relative_path"))s=L"Stored NUL-terminated ANSI string";
        break;
    case 0x60850022U:
        if(!xx_rt_wcscmp(r->name,L"relative_path"))s=L"Stored NUL-terminated UTF-16LE string";
        break;
    case 0x60850023U:
        if(!xx_rt_wcscmp(r->name,L"version"))s=L"Stored NUL-terminated ANSI string";
        break;
    case 0x60850024U:
        if(!xx_rt_wcscmp(r->name,L"version"))s=L"Stored NUL-terminated UTF-16LE string";
        break;
    case 0x60850025U:
        if(!xx_rt_wcscmp(r->name,L"data_offset"))s=L"Executable-relative first record";
        else if(!xx_rt_wcscmp(r->name,L"end_offset"))s=L"Executable-relative end of the last record";
        else if(!xx_rt_wcscmp(r->name,L"encoded_unused_string"))s=L"Rotate/XOR-obfuscated fixed string allocation";
        else if(!xx_rt_wcscmp(r->name,L"encoded_command"))s=L"Rotate/XOR-obfuscated command";
        else if(!xx_rt_wcscmp(r->name,L"encoded_product_title"))s=L"Rotate/XOR-obfuscated product title";
        else if(!xx_rt_wcscmp(r->name,L"encoded_source_directory"))s=L"Rotate/XOR-obfuscated source directory";
        break;
    case 0x60850027U:
        if(!xx_rt_wcscmp(r->name,L"dos_date"))s=L"Packed DOS calendar date";
        else if(!xx_rt_wcscmp(r->name,L"dos_time"))s=L"Packed DOS clock time";
        break;
    case 0x6085002aU:
        if(!xx_rt_wcscmp(r->name,L"name_storage"))s=L"ANSI name and zero padding; later encoding-flag variants are not accepted by the native reader";
        break;
    case 0x6085002bU:
        if(!xx_rt_wcscmp(r->name,L"index_offset"))s=L"File-relative resource index";
        break;
    case 0x6085002dU:
        if(!xx_rt_wcscmp(r->name,L"file_offset"))s=L"File-relative stored resource";
        else if(!xx_rt_wcscmp(r->name,L"name_size"))s=L"Byte length of Java modified UTF-8 name";
        break;
    case 0x6085002eU:
        if(!xx_rt_wcscmp(r->name,L"has_u64"))s=L"0 or 1; whether the following 64-bit word is present";
        break;
    case 0x6085002fU:
        if(!xx_rt_wcscmp(r->name,L"bundled_jvm_value"))s=L"Opaque producer value; present only when selected by preceding flag";
        break;
    case 0x60850030U:
        if(!xx_rt_wcscmp(r->name,L"encoded_name"))s=L"Physical nibble-swapped and XOR-obfuscated name including encoded terminator";
        break;
    case 0x60850031U:
        if(!xx_rt_wcscmp(r->name,L"encoded_size"))s=L"Physical nibble-swapped and XOR-obfuscated decimal byte count including encoded terminator";
        break;
    case 0x60850033U:
        if(!xx_rt_wcscmp(r->name,L"packed_size"))s=L"Byte size of the following complete zlib stream";
        break;
    case 0x60850034U:
        if(!xx_rt_wcscmp(r->name,L"container_offset"))s=L"Executable-relative overlay start";
        break;
    case 0x60850035U:
        if(!xx_rt_wcscmp(r->name,L"section_size"))s=L"Includes this 72-byte header";
        else if(!xx_rt_wcscmp(r->name,L"check_word_a"))s=L"XOR with check_word_b equals 0x35BC6F82";
        else if(!xx_rt_wcscmp(r->name,L"check_word_b"))s=L"XOR with check_word_a equals 0x35BC6F82";
        break;
    case 0x60850036U:
        if(!xx_rt_wcscmp(r->name,L"properties"))s=L"Encoded LZMA lc/lp/pb parameters";
        break;
    case 0x60850037U:
        if(!xx_rt_wcscmp(r->name,L"complemented_value"))s=L"Bitwise complement of preceding value";
        break;
    case 0x60850038U:
        if(!xx_rt_wcscmp(r->name,L"payload_offset"))s=L"Executable-relative first block";
        else if(!xx_rt_wcscmp(r->name,L"first_block_size"))s=L"Producer locator size; native parser authenticates the payload pointer independently";
        break;
    case 0x60850039U:
        if(!xx_rt_wcscmp(r->name,L"unpacked_size"))s=L"Physical prefix of a solid adaptive-Huffman block; compressed extent is determined by native decoding";
        break;
    case 0x6085003aU:
        if(!xx_rt_wcscmp(r->name,L"record_type"))s=L"1 file; 2 enter directory; 3 leave directory; 4 end";
        else if(!xx_rt_wcscmp(r->name,L"filetime"))s=L"Windows FILETIME ticks";
        else if(!xx_rt_wcscmp(r->name,L"method"))s=L"0 packed; 1 stored";
        break;
    case 0x60850041U:
        if(!xx_rt_wcscmp(r->name,L"method"))s=L"0 stored; 1 zlib; 2 bzip2";
        break;
    case 0x60850042U:
        if(!xx_rt_wcscmp(r->name,L"method"))s=L"0 stored; 1 zlib; 2 bzip2";
        break;
    case 0x60850043U:
        if(!xx_rt_wcscmp(r->name,L"build_time"))s=L"Stored build timestamp";
        break;
    case 0x60850044U:
        if(!xx_rt_wcscmp(r->name,L"header_offset"))s=L"Executable-relative ESIV header or SIVM wrapper";
        break;
    case 0x60850045U:
        if(!xx_rt_wcscmp(r->name,L"container_size"))s=L"Bytes from SIVM wrapper up to, but excluding, the eight-byte footer";
        break;
    case 0x60850047U:
        if(!xx_rt_wcscmp(r->name,L"string_size"))s=L"Byte count, not UTF-16 code units";
        break;
    case 0x60850048U:
        if(!xx_rt_wcscmp(r->name,L"length_and_flags"))s=L"Low six bits give the following byte count; upper bits are not interpreted";
        break;
    case 0x6085004aU:
        if(!xx_rt_wcscmp(r->name,L"dos_date"))s=L"Packed DOS calendar date";
        else if(!xx_rt_wcscmp(r->name,L"dos_time"))s=L"Packed DOS clock time";
        break;
    case 0x6085004cU:
        if(!xx_rt_wcscmp(r->name,L"data_offset"))s=L"Relative to ESIV header";
        break;
    case 0x6085004dU:
        if(!xx_rt_wcscmp(r->name,L"data_offset"))s=L"Relative to ESIV header";
        break;
    case 0x6085004eU:
        if(!xx_rt_wcscmp(r->name,L"crc32"))s=L"CRC32 of the decoded raw-DEFLATE member";
        break;
    case 0x6085004fU:
        if(!xx_rt_wcscmp(r->name,L"flags"))s=L"Wise PK mode commonly sets bit 15";
        else if(!xx_rt_wcscmp(r->name,L"dos_time"))s=L"Packed DOS clock time";
        else if(!xx_rt_wcscmp(r->name,L"dos_date"))s=L"Packed DOS calendar date";
        break;
    case 0x60850050U:
        if(!xx_rt_wcscmp(r->name,L"dos_time"))s=L"Packed DOS clock time";
        else if(!xx_rt_wcscmp(r->name,L"dos_date"))s=L"Packed DOS calendar date";
        else if(!xx_rt_wcscmp(r->name,L"local_header_offset"))s=L"Absolute from executable start in native Wise PK mode";
        break;
    case 0x60850051U:
        if(!xx_rt_wcscmp(r->name,L"directory_offset"))s=L"Absolute from executable start in native Wise PK mode";
        break;
    case 0x60850052U:
        if(!xx_rt_wcscmp(r->name,L"encoded_signature"))s=L"Physical XOR-0x8D encoded signature";
        else if(!xx_rt_wcscmp(r->name,L"encoded_reserved1"))s=L"Physical XOR-0x8D encoded reserved1";
        else if(!xx_rt_wcscmp(r->name,L"encoded_cabinet_size"))s=L"Physical XOR-0x8D encoded cabinet_size";
        else if(!xx_rt_wcscmp(r->name,L"encoded_reserved2"))s=L"Physical XOR-0x8D encoded reserved2";
        else if(!xx_rt_wcscmp(r->name,L"encoded_files_offset"))s=L"Physical XOR-0x8D encoded files_offset";
        else if(!xx_rt_wcscmp(r->name,L"encoded_reserved3"))s=L"Physical XOR-0x8D encoded reserved3";
        else if(!xx_rt_wcscmp(r->name,L"encoded_version_minor"))s=L"Physical XOR-0x8D encoded version_minor";
        else if(!xx_rt_wcscmp(r->name,L"encoded_version_major"))s=L"Physical XOR-0x8D encoded version_major";
        else if(!xx_rt_wcscmp(r->name,L"encoded_folder_count"))s=L"Physical XOR-0x8D encoded folder_count";
        else if(!xx_rt_wcscmp(r->name,L"encoded_file_count"))s=L"Physical XOR-0x8D encoded file_count";
        else if(!xx_rt_wcscmp(r->name,L"encoded_flags"))s=L"Physical XOR-0x8D encoded flags";
        else if(!xx_rt_wcscmp(r->name,L"encoded_set_id"))s=L"Physical XOR-0x8D encoded set_id";
        else if(!xx_rt_wcscmp(r->name,L"encoded_cabinet_index"))s=L"Physical XOR-0x8D encoded cabinet_index";
        break;
    case 0x60850053U:
        if(!xx_rt_wcscmp(r->name,L"encoded_header_reserve_size"))s=L"Physical XOR-0x8D encoded header_reserve_size";
        else if(!xx_rt_wcscmp(r->name,L"encoded_folder_reserve_size"))s=L"Physical XOR-0x8D encoded folder_reserve_size";
        else if(!xx_rt_wcscmp(r->name,L"encoded_data_reserve_size"))s=L"Physical XOR-0x8D encoded data_reserve_size";
        break;
    case 0x60850054U:
        if(!xx_rt_wcscmp(r->name,L"encoded_data_offset"))s=L"Physical XOR-0x8D encoded data_offset";
        else if(!xx_rt_wcscmp(r->name,L"encoded_data_count"))s=L"Physical XOR-0x8D encoded data_count";
        else if(!xx_rt_wcscmp(r->name,L"encoded_compression_type"))s=L"Physical XOR-0x8D encoded compression_type";
        break;
    case 0x60850055U:
        if(!xx_rt_wcscmp(r->name,L"encoded_unpacked_size"))s=L"Physical XOR-0x8D encoded unpacked_size";
        else if(!xx_rt_wcscmp(r->name,L"encoded_folder_offset"))s=L"Physical XOR-0x8D encoded folder_offset";
        else if(!xx_rt_wcscmp(r->name,L"encoded_folder_index"))s=L"Physical XOR-0x8D encoded folder_index";
        else if(!xx_rt_wcscmp(r->name,L"encoded_dos_date"))s=L"Physical XOR-0x8D encoded dos_date";
        else if(!xx_rt_wcscmp(r->name,L"encoded_dos_time"))s=L"Physical XOR-0x8D encoded dos_time";
        else if(!xx_rt_wcscmp(r->name,L"encoded_attributes"))s=L"Physical XOR-0x8D encoded attributes";
        break;
    case 0x60850056U:
        if(!xx_rt_wcscmp(r->name,L"encoded_checksum"))s=L"Physical XOR-0x8D encoded checksum";
        else if(!xx_rt_wcscmp(r->name,L"encoded_packed_size"))s=L"Physical XOR-0x8D encoded packed_size";
        else if(!xx_rt_wcscmp(r->name,L"encoded_unpacked_size"))s=L"Physical XOR-0x8D encoded unpacked_size";
        break;
    case 0x60850057U:
        if(!xx_rt_wcscmp(r->name,L"metadata"))s=L"Clear producer-specific trailer words; exact meanings vary";
        break;
    case 0x60850058U:
        if(!xx_rt_wcscmp(r->name,L"metadata"))s=L"Clear producer-specific trailer words; exact meanings vary";
        break;
    case 0x60850059U:
        if(!xx_rt_wcscmp(r->name,L"table_offset"))s=L"Executable-relative loader table";
        else if(!xx_rt_wcscmp(r->name,L"complemented_table_offset"))s=L"Bitwise complement of table_offset";
        break;
    case 0x6085005aU:
        if(!xx_rt_wcscmp(r->name,L"exe_offset"))s=L"Executable-relative embedded setup loader";
        else if(!xx_rt_wcscmp(r->name,L"setup_header_offset"))s=L"Executable-relative setup version record";
        else if(!xx_rt_wcscmp(r->name,L"data_offset"))s=L"Executable-relative data area; zero denotes external slices";
        break;
    case 0x6085005bU:
        if(!xx_rt_wcscmp(r->name,L"exe_offset"))s=L"Executable-relative embedded setup loader";
        else if(!xx_rt_wcscmp(r->name,L"setup_header_offset"))s=L"Executable-relative setup version record";
        else if(!xx_rt_wcscmp(r->name,L"data_offset"))s=L"Executable-relative data area; zero denotes external slices";
        break;
    case 0x6085005cU:
        if(!xx_rt_wcscmp(r->name,L"exe_offset"))s=L"Executable-relative embedded setup loader";
        else if(!xx_rt_wcscmp(r->name,L"setup_header_offset"))s=L"Executable-relative setup version record";
        else if(!xx_rt_wcscmp(r->name,L"data_offset"))s=L"Executable-relative data area; zero denotes external slices";
        break;
    case 0x6085005dU:
        if(!xx_rt_wcscmp(r->name,L"exe_offset"))s=L"Executable-relative embedded setup loader";
        else if(!xx_rt_wcscmp(r->name,L"setup_header_offset"))s=L"Executable-relative setup version record";
        else if(!xx_rt_wcscmp(r->name,L"data_offset"))s=L"Executable-relative data area; zero denotes external slices";
        break;
    case 0x6085005eU:
        if(!xx_rt_wcscmp(r->name,L"exe_offset"))s=L"Executable-relative embedded setup loader";
        else if(!xx_rt_wcscmp(r->name,L"setup_header_offset"))s=L"Executable-relative setup version record";
        else if(!xx_rt_wcscmp(r->name,L"data_offset"))s=L"Executable-relative data area; zero denotes external slices";
        break;
    case 0x6085005fU:
        if(!xx_rt_wcscmp(r->name,L"exe_offset"))s=L"Executable-relative embedded loader";
        else if(!xx_rt_wcscmp(r->name,L"setup_header_offset"))s=L"Executable-relative setup version record";
        else if(!xx_rt_wcscmp(r->name,L"data_offset"))s=L"Executable-relative data area; zero denotes external slices";
        break;
    case 0x60850060U:
        if(!xx_rt_wcscmp(r->name,L"exe_offset"))s=L"Executable-relative embedded loader";
        else if(!xx_rt_wcscmp(r->name,L"setup_header_offset"))s=L"Executable-relative setup version record";
        else if(!xx_rt_wcscmp(r->name,L"data_offset"))s=L"Executable-relative data area; zero denotes external slices";
        break;
    case 0x60850061U:
        if(!xx_rt_wcscmp(r->name,L"version"))s=L"Stored setup format version text with NUL padding";
        break;
    case 0x60850062U:
        if(!xx_rt_wcscmp(r->name,L"encryption_parameters"))s=L"Physical encryption envelope; no plaintext substitution";
        break;
    case 0x60850063U:
        if(!xx_rt_wcscmp(r->name,L"compressed_size"))s=L"-1 means stored; otherwise compressed byte size excluding CRC prefixes";
        break;
    case 0x60850064U:
        if(!xx_rt_wcscmp(r->name,L"stored_extent"))s=L"Includes four-byte CRC prefixes for each up-to-4096-byte payload piece";
        break;
    case 0x60850065U:
        if(!xx_rt_wcscmp(r->name,L"stored_extent"))s=L"Includes four-byte CRC prefixes for each up-to-4096-byte payload piece";
        break;
    case 0x60850066U:
        if(!xx_rt_wcscmp(r->name,L"crc32"))s=L"CRC32 of the following up-to-4096 physical payload bytes";
        break;
    default:break;}
    return !s||xx_data_struct_record_set_comment(r,s);
}
#define SXIL_LIMIT 24000U
bool sxil_span(sx_context*c,uint64_t p,uint64_t n){return c&&c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p&&!xx_pd_is_stopped(c->pd);}
bool sxil_read(sx_context*c,uint64_t p,void*b,size_t n){return sxil_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
uint16_t sxil16(const uint8_t*b,bool be){return be?((uint16_t)b[0]<<8)|b[1]:(uint16_t)b[0]|((uint16_t)b[1]<<8);}
uint32_t sxil32(const uint8_t*b,bool be){return be?((uint32_t)b[0]<<24)|((uint32_t)b[1]<<16)|((uint32_t)b[2]<<8)|b[3]:(uint32_t)b[0]|((uint32_t)b[1]<<8)|((uint32_t)b[2]<<16)|((uint32_t)b[3]<<24);}
bool sxil_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t count){const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(!z||count>UINT64_MAX/z||!sxil_span(c,p,count*z))return false;if(!count||c->count>=SXIL_LIMIT)return true;return count==1?sx_add(c,l,(int64_t)p,(int64_t)z):sx_table(c,l,(int64_t)p,(int64_t)z,(int64_t)count);}
#define SXIL_ADD(c,n,p) sxil_put(c,&sxil_##n,p,1)
bool sxil_text(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n){if(!sxil_span(c,p,n))return false;if(!n||n>4096||c->count>=SXIL_LIMIT)return true;return sx_add(c,l,(int64_t)p,(int64_t)n);}
static int sxil_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;if(x->offset!=y->offset)return x->offset<y->offset?-1:1;if(x->total_size!=y->total_size)return x->total_size<y->total_size?-1:1;return x->id<y->id?-1:x->id>y->id;}
static bool sxil_finish(sx_context*c){size_t n=c->count,kept=0;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxil_order);for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(p<end)continue;c->items[kept++]=c->items[i];end=p+z;}c->count=kept;n=kept;end=0;for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxil_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
/* Borrow the authenticated native iterator, copy only physical coordinates,
 * and release it before inspecting bytes. No subclass assumptions or ownership transfer. */
static bool sxil_collect(sx_context*c,sxil_records*out){
 Abstractformat*f=c->f;out->items=NULL;out->count=0;
 if(!f->create_archive_records_reading||!f->get_current_archive_record||!f->archive_record_move_to_next||!f->free_archive_records_reading)return true;
 xx_archive_record_state*state=(f->create_archive_records_reading)(f,NULL,c->pd);if(!state)return true;
 sxil_member*v=xx_mem_alloc(SXIL_LIMIT*sizeof(*v));if(!v){(f->free_archive_records_reading)(f,state);return false;}
 for(size_t i=0;i<SXIL_LIMIT&&!xx_pd_is_stopped(c->pd);i++){
  const xx_archive_record*r=(f->get_current_archive_record)(f,state);if(!r)break;
  if((r->header_offset>=f->base_address||(f->file_type==XX_FILE_TYPE_CLICKTEAM_INSTALL_CREATOR&&r->header_offset==-1))&&r->header_size>=0&&r->data_offset>=f->base_address&&r->compressed_size>=0){
   uint64_t p=r->header_offset<0?UINT64_MAX:(uint64_t)(r->header_offset-f->base_address),d=(uint64_t)(r->data_offset-f->base_address),h=(uint64_t)r->header_size,z=(uint64_t)r->compressed_size;
   if((p==UINT64_MAX||sxil_span(c,p,h))&&sxil_span(c,d,z))v[out->count++]=(sxil_member){p,h,d,z,xx_archive_record_get_meta_u64(r,XX_META_ID_CRC32,UINT64_MAX)};
  }
  if(!(f->archive_record_move_to_next)(f,state,c->pd))break;
 }
 (f->free_archive_records_reading)(f,state);out->items=v;return !xx_pd_is_stopped(c->pd);
}
bool sxil_u32(sx_context*c,uint64_t p,uint32_t*v){uint8_t b[4];if(!sxil_read(c,p,b,4))return false;*v=sxil32(b,false);return true;}
bool sxil_u16(sx_context*c,uint64_t p,uint16_t*v){uint8_t b[2];if(!sxil_read(c,p,b,2))return false;*v=sxil16(b,false);return true;}
bool sxil_eq(sx_context*c,uint64_t p,const void*s,size_t n){uint8_t b[32];return n<=sizeof(b)&&sxil_read(c,p,b,n)&&!xx_rt_memcmp(b,s,n);}
bool sxil_name(sx_context*c,uint64_t p,uint64_t n){return sxil_text(c,&sxil_installerlast_name,p,n);}
bool sxil_encoded(sx_context*c,uint64_t p,uint64_t n){return sxil_text(c,&sxil_installerlast_encoded_bytes,p,n);}
/* This carrier walk locates an installer overlay only. It emits no PE fields. */
bool sxil_pe(sx_context*c,uint64_t*out){
 uint8_t d[64],h[24],o[64],s[40];if(!sxil_read(c,0,d,64)||d[0]!='M'||d[1]!='Z')return false;
 uint64_t at=sxil32(d+60,false);if(!sxil_read(c,at,h,24)||xx_rt_memcmp(h,"PE\0\0",4))return false;
 uint16_t count=sxil16(h+6,false),opt=sxil16(h+20,false);if(!count||count>96||opt<64||!sxil_read(c,at+24,o,64))return false;
 uint64_t end=sxil32(o+60,false),tab=at+24+opt;if(!sxil_span(c,0,end)||!sxil_span(c,tab,(uint64_t)count*40))return false;
 for(unsigned i=0;i<count;i++){if(!sxil_read(c,tab+40U*i,s,40))return false;uint64_t p=sxil32(s+20,false),n=sxil32(s+16,false);if(!sxil_span(c,p,n))return false;if(n&&p+n>end)end=p+n;}
 *out=end;return true;
}
static bool sxil_take(sx_context*c,uint64_t*p,uint64_t end,const sx_layout*l,unsigned width,bool decimal){
 uint64_t start=*p;uint8_t b[2];if(end>(uint64_t)c->size||!width||width>2)return false;
 for(unsigned i=0;i<4096&&*p<=end&&width<=end-*p;i++,*p+=width){if(!sxil_read(c,*p,b,width))return false;uint16_t v=width==1?b[0]:sxil16(b,false);if(!v){uint64_t n=*p-start;*p+=width;return sxil_text(c,l,start,decimal?n:n+width);}if(decimal&&(v<'0'||v>'9'))return false;}
 return false;
}
/* A bounded byte-pattern search for native-confirmed roots. Matches are always
 * checked against their count, geometry or authenticated member coordinates. */
bool sxil_find(sx_context*c,const uint8_t*needle,size_t n,uint64_t start,uint64_t end,uint64_t*out){
 uint8_t b[4096+64];if(!n||n>64||start>end||end>(uint64_t)c->size)return false;
 while(start<end){size_t z=(size_t)((end-start)>sizeof(b)?sizeof(b):end-start);if(z<n||!sxil_read(c,start,b,z))return false;for(size_t k=0;k+n<=z;k++)if(!xx_rt_memcmp(b+k,needle,n)){*out=start+k;return true;}start+=z-n+1;}return false;
}
static bool sxil_rva(sx_context*c,uint32_t rva,uint32_t bytes,uint64_t*out){uint32_t nt;uint8_t h[24];if(!sxil_u32(c,60,&nt)||!sxil_read(c,nt,h,24))return false;unsigned n=sxil16(h+6,false),opt=sxil16(h+20,false);if(!n||n>96)return false;uint64_t table=(uint64_t)nt+24+opt;for(unsigned i=0;i<n;i++){uint8_t s[40];if(!sxil_read(c,table+40U*i,s,40))return false;uint32_t va=sxil32(s+12,false),raw=sxil32(s+16,false),off=sxil32(s+20,false);if(rva>=va&&(uint64_t)rva-va<=raw&&bytes<=raw-(rva-va)&&sxil_span(c,(uint64_t)off+rva-va,bytes)){*out=(uint64_t)off+rva-va;return true;}}return false;}
static bool sxil_resource_name(sx_context*c,uint64_t root,uint32_t size,uint32_t field,const char*name){if(!(field&0x80000000U)||!name)return false;uint32_t at=field&0x7fffffffU;uint16_t n;if(at>size||size-at<2||!sxil_u16(c,root+at,&n)||n>64||2U*n>size-at-2)return false;for(unsigned i=0;i<n;i++){uint16_t ch;if(!name[i]||!sxil_u16(c,root+at+2+2U*i,&ch)||ch!=(uint8_t)name[i])return false;}return name[n]==0;}
static bool sxil_resource_tree(sx_context*c,uint64_t root,uint32_t span,uint32_t dir,unsigned depth,uint32_t type,uint32_t id,const char*name,unsigned*work,uint64_t*out,uint32_t*length){
 uint8_t h[16];if(depth>2||dir>span||16>span-dir||!sxil_read(c,root+dir,h,16))return false;unsigned n=(unsigned)sxil16(h+12,false)+sxil16(h+14,false);if(n>4096||(uint64_t)n*8>span-dir-16)return false;
 for(unsigned i=0;i<n&&*work<12000;i++,(*work)++){uint8_t e[8];if(!sxil_read(c,root+dir+16+8U*i,e,8))return false;uint32_t key=sxil32(e,false),next=sxil32(e+4,false);if(depth==0&&(key!=type))continue;if(depth==1&&(name?!sxil_resource_name(c,root,span,key,name):key!=id))continue;
  if(depth<2){if(!(next&0x80000000U))continue;if(sxil_resource_tree(c,root,span,next&0x7fffffffU,depth+1,type,id,name,work,out,length))return true;}
  else if(!(next&0x80000000U)&&next<=span&&16<=span-next&&sxil_read(c,root+next,h,16)){uint32_t rva=sxil32(h,false),z=sxil32(h+4,false);if(sxil_rva(c,rva,z,out)){*length=z;return true;}}
 }return false;
}
bool sxil_resource(sx_context*c,uint32_t type,uint32_t id,const char*name,uint64_t*out,uint32_t*length){uint32_t nt;uint8_t h[24],d[8];uint16_t magic;if(!sxil_u32(c,60,&nt)||!sxil_read(c,nt,h,24)||xx_rt_memcmp(h,"PE\0\0",4)||!sxil_u16(c,(uint64_t)nt+24,&magic))return false;unsigned opt=sxil16(h+20,false),dd=magic==0x10b?96:magic==0x20b?112:0;if(!dd||opt<dd+24||!sxil_read(c,(uint64_t)nt+24+dd+16,d,8))return false;uint32_t rva=sxil32(d,false),span=sxil32(d+4,false);uint64_t root;unsigned work=0;if(!rva||!span||!sxil_rva(c,rva,span,&root))return false;return sxil_resource_tree(c,root,span,0,0,type,id,name,&work,out,length);}
bool sxil_is_strings(sx_context*c,sxil_records*r,bool wide,bool boot){
 if(wide){uint64_t p;if(sxil_pe(c,&p)&&!SXIL_ADD(c,installshield12_count,p))return false;}
 const sx_layout*str[4]={wide?&sxil_installshield_utf16_base_name:&sxil_installshield_ansi_base_name,wide?&sxil_installshield_utf16_relative_path:&sxil_installshield_ansi_relative_path,wide?&sxil_installshield_utf16_version:&sxil_installshield_ansi_version,wide?&sxil_installerlast_utf16_size:&sxil_installerlast_decimal_size};
 for(size_t i=0;i<r->count;i++){sxil_member*m=r->items+i;uint64_t p=m->header,end=p+m->header_size;for(unsigned k=0;k<4;k++)if(!sxil_take(c,&p,end,str[k],wide?2:1,k==3))break;if(boot&&m->packed>=14&&sxil_eq(c,m->data,"SZDD\x88\xf0\x27\x33",8)&&!SXIL_ADD(c,installshield7_szdd,m->data))return false;}return !c->failed;
}
static bool sxil_createinstall(sx_context*c,sxil_records*r){
 for(size_t i=0;i<r->count;i++){sxil_member*m=r->items+i;if(m->header_size<21)continue;uint8_t b[17];if(!sxil_read(c,m->header,b,17))continue;uint64_t n=sxil16(b+15,false);if(b[0]!=1||b[14]>1||n>INT16_MAX||17+n+4!=m->header_size)continue;
  if(!SXIL_ADD(c,createinstall_record,m->header)||!sxil_name(c,m->header+17,n)||!SXIL_ADD(c,createinstall_file_size,m->header+17+n))return false;
 }
 /* Native runtime extent authenticates the beginning of the raw prelude.
  * Match the stored carrier size and a real first record; never scan codec output. */
 if(r->count>1&&r->items[0].header_size==0){uint64_t start=r->items[0].data+r->items[0].packed,end=r->items[1].header,p;uint8_t needle[4];for(unsigned i=0;i<4;i++)needle[i]=(uint8_t)((uint64_t)c->size>>(8*i));
  if(end>=start&&end-start<=0x10000&&sxil_find(c,needle,4,start,end,&p)){uint32_t z;if(sxil_u32(c,p+8,&z)&&(p+77+(uint64_t)z==end||p+79+(uint64_t)z==end)&&!SXIL_ADD(c,createinstall_prelude,p))return false;}}
 return true;
}
static bool sx_installerlast_supports(xx_file_type_t type){switch(type){
case XX_FILE_TYPE_WISE_INSTALLATION_SYSTEM:case XX_FILE_TYPE_GENTEE_INSTALLER:case XX_FILE_TYPE_CLICKTEAM_INSTALL_CREATOR:case XX_FILE_TYPE_CREATEINSTALL_INSTCRIN_EXTRACTOR:case XX_FILE_TYPE_ADVANCED_INSTALLER_BOOTSTRAPPER:case XX_FILE_TYPE_ARDI_INSTALLER:case XX_FILE_TYPE_ARNI_INSTALLER_CONTAINER:case XX_FILE_TYPE_EJ_TECHNOLOGIES_INSTALL:case XX_FILE_TYPE_GHOST_INSTALLER:case XX_FILE_TYPE_IBM_ZPAK_INSTALLER:case XX_FILE_TYPE_INNO_SETUP:case XX_FILE_TYPE_INSTALLER_VISE_WINDOWS:case XX_FILE_TYPE_INSTALLSHIELD_12_SETUP:case XX_FILE_TYPE_INSTALLSHIELD_3:case XX_FILE_TYPE_INSTALLSHIELD_7_SETUP:case XX_FILE_TYPE_INSTALLSHIELD_7_SETUP2:case XX_FILE_TYPE_INSTALLSHIELD_DEVELOPER:case XX_FILE_TYPE_INSTALLSHIELD_MULTIPLATFORM:case XX_FILE_TYPE_INSTALLSHIELD_SKIN:case XX_FILE_TYPE_QSETUP_INSTALLATION_SUITE:case XX_FILE_TYPE_TARMA_INSTALLER:return true;default:return false;}}
static bool sx_installerlast_build(sx_context*c){if(!c||!c->f||c->size<0||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;sxil_records records;if(!sxil_collect(c,&records)){if(records.items)xx_mem_free(records.items);return false;}bool ok=false;switch(c->f->file_type){
case XX_FILE_TYPE_WISE_INSTALLATION_SYSTEM:ok=sx_wise_installation_system_build(c,records);break;
case XX_FILE_TYPE_GENTEE_INSTALLER:ok=sx_gentee_installer_build(c,records);break;
case XX_FILE_TYPE_CLICKTEAM_INSTALL_CREATOR:ok=sx_clickteam_install_creator_build(c,records);break;
case XX_FILE_TYPE_CREATEINSTALL_INSTCRIN_EXTRACTOR:ok=sxil_createinstall(c,&records);break;
case XX_FILE_TYPE_ADVANCED_INSTALLER_BOOTSTRAPPER:ok=sx_advanced_installer_bootstrapper_build(c,records);break;
case XX_FILE_TYPE_ARDI_INSTALLER:ok=sx_ardi_installer_build(c);break;
case XX_FILE_TYPE_ARNI_INSTALLER_CONTAINER:ok=sx_arni_installer_container_build(c,records);break;
case XX_FILE_TYPE_EJ_TECHNOLOGIES_INSTALL:ok=sx_ej_technologies_install_build(c,records);break;
case XX_FILE_TYPE_GHOST_INSTALLER:ok=sx_ghost_installer_build(c);break;
case XX_FILE_TYPE_IBM_ZPAK_INSTALLER:ok=sx_ibm_zpak_installer_build(c);break;
case XX_FILE_TYPE_INNO_SETUP:ok=sx_inno_setup_build(c);break;
case XX_FILE_TYPE_INSTALLER_VISE_WINDOWS:ok=sx_installer_vise_windows_build(c,records);break;
case XX_FILE_TYPE_INSTALLSHIELD_12_SETUP:ok=sx_installshield_12_setup_build(c,records);break;
case XX_FILE_TYPE_INSTALLSHIELD_3:ok=sx_installshield_3_build(c,records);break;
case XX_FILE_TYPE_INSTALLSHIELD_7_SETUP:ok=sx_installshield_7_setup_build(c,records);break;
case XX_FILE_TYPE_INSTALLSHIELD_7_SETUP2:ok=sx_installshield_7_setup2_build(c,records);break;
case XX_FILE_TYPE_INSTALLSHIELD_DEVELOPER:ok=sx_installshield_developer_build(c);break;
case XX_FILE_TYPE_INSTALLSHIELD_MULTIPLATFORM:ok=sx_installshield_multiplatform_build(c);break;
case XX_FILE_TYPE_INSTALLSHIELD_SKIN:ok=sx_installshield_skin_build(c,records);break;
case XX_FILE_TYPE_QSETUP_INSTALLATION_SUITE:ok=sx_qsetup_installation_suite_build(c);break;
case XX_FILE_TYPE_TARMA_INSTALLER:ok=sx_tarma_installer_build(c);break;
default:break;}if(records.items)xx_mem_free(records.items);(void)ok;return c->count&&sxil_finish(c);}
#undef SXIL_ADD
#undef SXIL_LIMIT
const sx_family sx_installerlast_family={sx_installerlast_supports,sx_installerlast_build,sx_installerlast_layouts,SX_COUNT(sx_installerlast_layouts),sx_installerlast_comment};
