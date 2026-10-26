/* SPDX-License-Identifier: MIT. Physical serialization metadata. Scope: docs/data_struct_archivenext_scope.txt. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_archivenext.h"
static const xx_data_struct_field_desc sxan_pc_install_member_fields[] = {
 SX_FIELD("next_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("attributes","uint32",4,4,SX_FLAGS),
 SX_FIELD("dos_time","uint16",8,2,SX_NONE),
 SX_FIELD("time_padding","uint16",10,2,SX_NONE),
 SX_FIELD("dos_date","uint16",12,2,SX_NONE),
 SX_FIELD("date_padding","uint16",14,2,SX_NONE),
 SX_FIELD("payload_size","uint32",16,4,SX_SIZE),
 SX_FIELD("name","char[256]",20,256,SX_NONE),
};
static const sx_layout sxan_pc_install_member = {UINT32_C(0x6077001c),"pc_install_member",sxan_pc_install_member_fields,SX_COUNT(sxan_pc_install_member_fields),SX_LE};
static const xx_data_struct_field_desc sxan_pc_install_trailer_fields[] = {
 SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("first_record_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("last_record_offset","uint32",12,4,SX_OFFSET),
};
static const sx_layout sxan_pc_install_trailer = {UINT32_C(0x6077001d),"pc_install_trailer",sxan_pc_install_trailer_fields,SX_COUNT(sxan_pc_install_trailer_fields),SX_LE};
static const xx_data_struct_field_desc sxan_pc_install_group_fields[] = {
 SX_FIELD("cross_volume","uint8[14]",0,14,SX_NONE),
 SX_FIELD("marker1","uint16",14,2,SX_SIGNATURE),
 SX_FIELD("member_count","uint16",16,2,SX_COUNT_PROP),
 SX_FIELD("marker2","uint16",18,2,SX_SIGNATURE),
 SX_FIELD("reserved","uint8[38]",20,38,SX_NONE),
};
static const sx_layout sxan_pc_install_group = {UINT32_C(0x6077001e),"pc_install_group",sxan_pc_install_group_fields,SX_COUNT(sxan_pc_install_group_fields),SX_LE};
static const xx_data_struct_field_desc sxan_pc_install_group_member_fields[] = {
 SX_FIELD("name","char[128]",0,128,SX_NONE),
 SX_FIELD("attributes","uint32",128,4,SX_FLAGS),
 SX_FIELD("reserved1","uint32",132,4,SX_NONE),
 SX_FIELD("compressed_size","uint32",136,4,SX_SIZE),
 SX_FIELD("dos_date","uint16",140,2,SX_NONE),
 SX_FIELD("date_padding","uint16",142,2,SX_NONE),
 SX_FIELD("dos_time","uint16",144,2,SX_NONE),
 SX_FIELD("time_padding","uint16",146,2,SX_NONE),
 SX_FIELD("unknown","uint8[8]",148,8,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",156,4,SX_SIZE),
 SX_FIELD("unknown_tail","uint8[8]",160,8,SX_NONE),
};
static const sx_layout sxan_pc_install_group_member = {UINT32_C(0x6077001f),"pc_install_group_member",sxan_pc_install_group_member_fields,SX_COUNT(sxan_pc_install_group_member_fields),SX_LE};
static const xx_data_struct_field_desc sxan_spoon_footer_fields[] = {
 SX_FIELD("unknown1","uint32",0,4,SX_NONE),
 SX_FIELD("unknown2","uint32",4,4,SX_NONE),
 SX_FIELD("directory_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("member_count","uint32",12,4,SX_COUNT_PROP),
 SX_FIELD("signature","uint8[8]",16,8,SX_SIGNATURE),
};
static const sx_layout sxan_spoon_footer = {UINT32_C(0x60770021),"spoon_footer",sxan_spoon_footer_fields,SX_COUNT(sxan_spoon_footer_fields),SX_LE};
static const xx_data_struct_field_desc sxan_spoon_member_fields[] = {
 SX_FIELD("stream_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("compressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("byte_sum","uint32",12,4,SX_CHECKSUM),
 SX_FIELD("name_size","uint8",16,1,SX_SIZE),
};
static const sx_layout sxan_spoon_member = {UINT32_C(0x60770022),"spoon_member",sxan_spoon_member_fields,SX_COUNT(sxan_spoon_member_fields),SX_LE};
static const xx_data_struct_field_desc sxan_ckpedp_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_NONE),
 SX_FIELD("member_count","uint32",6,4,SX_COUNT_PROP),
 SX_FIELD("unknown","uint32",10,4,SX_NONE),
};
static const sx_layout sxan_ckpedp_header = {UINT32_C(0x6077002a),"ckpedp_header",sxan_ckpedp_header_fields,SX_COUNT(sxan_ckpedp_header_fields),SX_LE};
static const xx_data_struct_field_desc sxan_ckpedp_name_size_fields[] = {
 SX_FIELD("name_units","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxan_ckpedp_name_size = {UINT32_C(0x6077002b),"ckpedp_name_size",sxan_ckpedp_name_size_fields,SX_COUNT(sxan_ckpedp_name_size_fields),SX_LE};
static const xx_data_struct_field_desc sxan_ckpedp_member_tail_fields[] = {
 SX_FIELD("unknown","uint8[8]",0,8,SX_NONE),
 SX_FIELD("reserved","uint32",8,4,SX_NONE),
 SX_FIELD("data_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("payload_size","uint32",16,4,SX_SIZE),
};
static const sx_layout sxan_ckpedp_member_tail = {UINT32_C(0x6077002c),"ckpedp_member_tail",sxan_ckpedp_member_tail_fields,SX_COUNT(sxan_ckpedp_member_tail_fields),SX_LE};
static const xx_data_struct_field_desc sxan_ckpedp_encoded_name_fields[] = {
 SX_FIELD("encoded_name","uint8",0,0,SX_NONE),
};
static const sx_layout sxan_ckpedp_encoded_name = {UINT32_C(0x6077002d),"ckpedp_encoded_name",sxan_ckpedp_encoded_name_fields,SX_COUNT(sxan_ckpedp_encoded_name_fields),SX_LE};
static const xx_data_struct_field_desc sxan_parsec_rib_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("uncompressed_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxan_parsec_rib_header = {UINT32_C(0x6077002e),"parsec_rib_header",sxan_parsec_rib_header_fields,SX_COUNT(sxan_parsec_rib_header_fields),SX_LE};
static const xx_data_struct_field_desc sxan_parsec_member_offset_fields[] = {
 SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxan_parsec_member_offset = {UINT32_C(0x6077002f),"parsec_member_offset",sxan_parsec_member_offset_fields,SX_COUNT(sxan_parsec_member_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxan_parsec_member_size_fields[] = {
 SX_FIELD("payload_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxan_parsec_member_size = {UINT32_C(0x60770030),"parsec_member_size",sxan_parsec_member_size_fields,SX_COUNT(sxan_parsec_member_size_fields),SX_LE};
static const xx_data_struct_field_desc sxan_archivenext_name_fields[] = {
 SX_FIELD("name","char",0,0,SX_NONE),
};
const sx_layout sxan_archivenext_name = {UINT32_C(0x60770043),"archivenext_name",sxan_archivenext_name_fields,SX_COUNT(sxan_archivenext_name_fields),SX_LE};
static const xx_data_struct_field_desc sxan_pc_install_tag_fields[] = {
 SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
};
static const sx_layout sxan_pc_install_tag = {UINT32_C(0x60770049),"pc_install_tag",sxan_pc_install_tag_fields,SX_COUNT(sxan_pc_install_tag_fields),SX_LE};
static const xx_data_struct_field_desc sxan_lha_dialect_header_fields[] = {
 SX_FIELD("header_size","uint8",0,1,SX_SIZE),
 SX_FIELD("header_sum","uint8",1,1,SX_CHECKSUM),
 SX_FIELD("method","char[5]",2,5,SX_NONE),
 SX_FIELD("compressed_size","uint32",7,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",11,4,SX_SIZE),
 SX_FIELD("dos_datetime","uint32",15,4,SX_NONE),
 SX_FIELD("attributes","uint8",19,1,SX_FLAGS),
 SX_FIELD("level","uint8",20,1,SX_NONE),
 SX_FIELD("name_size","uint8",21,1,SX_SIZE),
};
static const sx_layout sxan_lha_dialect_header = {UINT32_C(0x60770058),"lha_dialect_header",sxan_lha_dialect_header_fields,SX_COUNT(sxan_lha_dialect_header_fields),SX_LE};
static const xx_data_struct_field_desc sxan_lha_dialect_crc_fields[] = {
 SX_FIELD("crc16","uint16",0,2,SX_CHECKSUM),
};
static const sx_layout sxan_lha_dialect_crc = {UINT32_C(0x60770059),"lha_dialect_crc",sxan_lha_dialect_crc_fields,SX_COUNT(sxan_lha_dialect_crc_fields),SX_LE};
static const xx_data_struct_field_desc sxan_lha_dialect_os_fields[] = {
 SX_FIELD("originating_os","uint8",0,1,SX_NONE),
};
static const sx_layout sxan_lha_dialect_os = {UINT32_C(0x6077005a),"lha_dialect_os",sxan_lha_dialect_os_fields,SX_COUNT(sxan_lha_dialect_os_fields),SX_LE};
static const xx_data_struct_field_desc sxan_lha_dialect_next_fields[] = {
 SX_FIELD("next_header_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxan_lha_dialect_next = {UINT32_C(0x6077005b),"lha_dialect_next",sxan_lha_dialect_next_fields,SX_COUNT(sxan_lha_dialect_next_fields),SX_LE};
static const xx_data_struct_field_desc sxan_lha_dialect_type_fields[] = {
 SX_FIELD("extension_type","uint8",0,1,SX_NONE),
};
static const sx_layout sxan_lha_dialect_type = {UINT32_C(0x6077005c),"lha_dialect_type",sxan_lha_dialect_type_fields,SX_COUNT(sxan_lha_dialect_type_fields),SX_LE};
static const xx_data_struct_field_desc sxan_lha_dialect_end_fields[] = {
 SX_FIELD("terminator","uint8",0,1,SX_NONE),
};
static const sx_layout sxan_lha_dialect_end = {UINT32_C(0x6077005d),"lha_dialect_end",sxan_lha_dialect_end_fields,SX_COUNT(sxan_lha_dialect_end_fields),SX_LE};
static const sx_layout *const sx_archivenext_layouts[] = {
 &sxan_is3_header,
 &sxan_is3_directory,
 &sxan_is3_member,
 &sxan_is3_payload_header,
 &sxan_is3_payload_member,
 &sxan_is3_second_name,
 &sxan_is5_header,
 &sxan_is5_descriptor,
 &sxan_is5_member_v5,
 &sxan_is5_member_v6,
 &sxan_is5_table_offset,
 &sxan_is11_header,
 &sxan_is11_member_v1,
 &sxan_is11_member_v3,
 &sxan_gksetup_banner,
 &sxan_gksetup_signature,
 &sxan_gksetup_data_offset,
 &sxan_gksetup_member,
 &sxan_pcinstall_header,
 &sxan_pcinstall_member,
 &sxan_finstall_header,
 &sxan_finstall_member,
 &sxan_ifah_header,
 &sxan_ifah_member,
 &sxan_osetup_member,
 &sxan_osetup_trailer_6,
 &sxan_osetup_trailer_8,
 &sxan_pc_install_member,
 &sxan_pc_install_trailer,
 &sxan_pc_install_group,
 &sxan_pc_install_group_member,
 &sxan_rtpatch_setup_member,
 &sxan_spoon_footer,
 &sxan_spoon_member,
 &sxan_issetup_header,
 &sxan_issetup_member,
 &sxan_epsf_header,
 &sxan_setup_factory_header,
 &sxan_setup_factory_engine_16,
 &sxan_setup_factory_engine_260,
 &sxan_westwood_offset,
 &sxan_ckpedp_header,
 &sxan_ckpedp_name_size,
 &sxan_ckpedp_member_tail,
 &sxan_ckpedp_encoded_name,
 &sxan_parsec_rib_header,
 &sxan_parsec_member_offset,
 &sxan_parsec_member_size,
 &sxan_ptero_header,
 &sxan_ptero_member,
 &sxan_ptero_block,
 &sxan_titan_header,
 &sxan_titan_block,
 &sxan_titan_member,
 &sxan_cgjp_signature,
 &sxan_cgjp_block,
 &sxan_birdies_header,
 &sxan_birdies_member,
 &sxan_xuiz_header,
 &sxan_xuiz_member_0,
 &sxan_xuiz_member_10,
 &sxan_dcs_header,
 &sxan_dcs_block,
 &sxan_audials_count,
 &sxan_audials_offset,
 &sxan_audials_size,
 &sxan_archivenext_name,
 &sxan_archivenext_utf16le,
 &sxan_archivenext_utf16be,
 &sxan_is5_volume_prefix,
 &sxan_archivenext_padding32,
 &sxan_archivenext_separator,
 &sxan_pc_install_tag,
 &sxan_wad_header,
 &sxan_wad_rsa2048,
 &sxan_wad_ticket,
 &sxan_wad_limit,
 &sxan_wad_tmd,
 &sxan_wad_content,
 &sxan_stfs_signature,
 &sxan_stfs_metadata_digest,
 &sxan_stfs_volume_le,
 &sxan_stfs_volume_be,
 &sxan_stfs_data_file_count,
 &sxan_stfs_hash_entry,
 &sxan_stfs_file_le,
 &sxan_stfs_file_be,
 &sxan_lha_dialect_header,
 &sxan_lha_dialect_crc,
 &sxan_lha_dialect_os,
 &sxan_lha_dialect_next,
 &sxan_lha_dialect_type,
 &sxan_lha_dialect_end,
 &sxan_bytekiller_header,
 &sxan_bytekiller_ace_header,
 &sxan_bytekiller_anc_header,
 &sxan_bytekiller_grac_header,
 &sxan_bytekiller_md11_header,
 &sxan_bytekiller_signature,
 &sxan_bytekiller_footer,
 &sxan_osl_encoded_record,
 &sxan_osl_payload_checksum,
 &sxan_osl_signature,
 &sxan_sbpak_header,
 &sxan_sbpak_encoded_header,
 &sxan_sbpak_member,
 &sxan_sbpak_encoded_member,
 &sxan_freearc_header,
 &sxan_freearc_magic,
 &sxan_freearc_crc,
 &sxan_freearc_time,
 &sxan_freearc_folder,
 &sxan_freearc_method,
 &sxan_freearc_type1,
 &sxan_freearc_count1,
 &sxan_freearc_offset1,
 &sxan_freearc_size1,
 &sxan_freearc_packed1,
 &sxan_freearc_index1,
 &sxan_freearc_type2,
 &sxan_freearc_count2,
 &sxan_freearc_offset2,
 &sxan_freearc_size2,
 &sxan_freearc_packed2,
 &sxan_freearc_index2,
 &sxan_freearc_type3,
 &sxan_freearc_count3,
 &sxan_freearc_offset3,
 &sxan_freearc_size3,
 &sxan_freearc_packed3,
 &sxan_freearc_index3,
 &sxan_freearc_type4,
 &sxan_freearc_count4,
 &sxan_freearc_offset4,
 &sxan_freearc_size4,
 &sxan_freearc_packed4,
 &sxan_freearc_index4,
 &sxan_freearc_type5,
 &sxan_freearc_count5,
 &sxan_freearc_offset5,
 &sxan_freearc_size5,
 &sxan_freearc_packed5,
 &sxan_freearc_index5,
 &sxan_freearc_type6,
 &sxan_freearc_count6,
 &sxan_freearc_offset6,
 &sxan_freearc_size6,
 &sxan_freearc_packed6,
 &sxan_freearc_index6,
 &sxan_freearc_type7,
 &sxan_freearc_count7,
 &sxan_freearc_offset7,
 &sxan_freearc_size7,
 &sxan_freearc_packed7,
 &sxan_freearc_index7,
 &sxan_freearc_type8,
 &sxan_freearc_count8,
 &sxan_freearc_offset8,
 &sxan_freearc_size8,
 &sxan_freearc_packed8,
 &sxan_freearc_index8,
 &sxan_freearc_type9,
 &sxan_freearc_count9,
 &sxan_freearc_offset9,
 &sxan_freearc_size9,
 &sxan_freearc_packed9,
 &sxan_freearc_index9,
 &sxan_zpaq_block,
 &sxan_zpaq_model,
 &sxan_zpaq_locator,
 &sxan_zpaq_marker,
 &sxan_zpaq_stored_run,
 &sxan_zpaq_sha1,
 &sxan_zpaq_comment,
 &sxan_zpaq_cons,
 &sxan_zpaq_cm,
 &sxan_zpaq_icm,
 &sxan_zpaq_match,
 &sxan_zpaq_avg,
 &sxan_zpaq_mix2,
 &sxan_zpaq_mix,
 &sxan_zpaq_isse,
 &sxan_zpaq_sse,
};
static bool sx_archivenext_comment(xx_data_struct_record*r,uint32_t id){
 if(!r||!r->name||id<0x60770000U||id>=0x60780000U)return true;
 if(r->type&&(!xx_rt_wcsncmp(r->type,L"ascii_decimal[",14)||!xx_rt_wcsncmp(r->type,L"ascii_octal_padded[",19))&&r->value.type!=XX_VAR_TYPE_UINT64&&r->value.type!=XX_VAR_TYPE_INT64)return true;
 const wchar_t*text=NULL;switch(id){
 case 0x60770001U:
 if(!xx_rt_wcscmp(r->name,L"timestamp"))text=L"Stored archive timestamp; epoch not established";
 if(!xx_rt_wcscmp(r->name,L"archive_size"))text=L"Total across all volumes";
 break;
 case 0x60770003U:
 if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Offset in the archive volume";
 break;
 case 0x60770008U:
 if(!xx_rt_wcscmp(r->name,L"file_table_offset"))text=L"Relative to cabinet descriptor";
 if(!xx_rt_wcscmp(r->name,L"second_table_offset"))text=L"Relative to the file table";
 break;
 case 0x60770009U:
 if(!xx_rt_wcscmp(r->name,L"name_offset"))text=L"Relative to file table";
 if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Relative to applicable cabinet volume";
 break;
 case 0x6077000aU:
 if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Relative to applicable cabinet volume";
 if(!xx_rt_wcscmp(r->name,L"md5"))text=L"Stored checksum or digest";
 if(!xx_rt_wcscmp(r->name,L"name_offset"))text=L"Relative to file table";
 break;
 case 0x6077000bU:
 if(!xx_rt_wcscmp(r->name,L"entry_offset"))text=L"Relative to file table";
 break;
 case 0x60770012U:
 if(!xx_rt_wcscmp(r->name,L"creation_time"))text=L"Windows FILETIME100ns ticks since1601";
 if(!xx_rt_wcscmp(r->name,L"access_time"))text=L"Windows FILETIME100ns ticks since1601";
 if(!xx_rt_wcscmp(r->name,L"modification_time"))text=L"Windows FILETIME100ns ticks since1601";
 break;
 case 0x60770016U:
 if(!xx_rt_wcscmp(r->name,L"name"))text=L"DOS codepage437 bytes";
 break;
 case 0x60770017U:
 if(!xx_rt_wcscmp(r->name,L"declared_size"))text=L"Whole setup size, including stub when present";
 break;
 case 0x60770018U:
 if(!xx_rt_wcscmp(r->name,L"crc32"))text=L"Stored checksum or digest";
 break;
 case 0x60770019U:
 if(!xx_rt_wcscmp(r->name,L"writer_memory"))text=L"Uninitialized writer bytes, not interpreted";
 break;
 case 0x6077001cU:
 if(!xx_rt_wcscmp(r->name,L"next_offset"))text=L"Stored original base-relative record offset; may require native relocation";
 break;
 case 0x60770022U:
 if(!xx_rt_wcscmp(r->name,L"byte_sum"))text=L"Stored checksum or digest";
 if(!xx_rt_wcscmp(r->name,L"name_size"))text=L"Includes NUL terminator";
 break;
 case 0x60770024U:
 if(!xx_rt_wcscmp(r->name,L"name_size"))text=L"UTF16LE byte count";
 if(!xx_rt_wcscmp(r->name,L"cipher_selector"))text=L"0,0xffffffff,0xfffffffd=none;2,6=name-keyed filter";
 if(!xx_rt_wcscmp(r->name,L"storage"))text=L"0=stored,1=zlib stream";
 break;
 case 0x60770025U:
 if(!xx_rt_wcscmp(r->name,L"runtime_byte_sum"))text=L"Stored checksum or digest";
 break;
 case 0x60770027U:
 if(!xx_rt_wcscmp(r->name,L"crc32"))text=L"Stored checksum or digest";
 break;
 case 0x60770028U:
 if(!xx_rt_wcscmp(r->name,L"crc32"))text=L"Stored checksum or digest";
 break;
 case 0x60770029U:
 if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Zero denotes directory termination in supported variants";
 break;
 case 0x6077002bU:
 if(!xx_rt_wcscmp(r->name,L"name_units"))text=L"Encoded bytes for CKP, encoded UTF16LE units for EDP";
 break;
 case 0x6077002dU:
 if(!xx_rt_wcscmp(r->name,L"encoded_name"))text=L"Inverted bytes/UTF16LE plus native character remapping; retained exactly as stored";
 break;
 case 0x6077002fU:
 if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"First entry also equals physical directory size; final offset word is zero";
 break;
 case 0x60770032U:
 if(!xx_rt_wcscmp(r->name,L"marker"))text=L"Native-supported value32";
 if(!xx_rt_wcscmp(r->name,L"timestamp"))text=L"Stored timestamp; epoch not established";
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0=stored,1=framed Ptero LZW";
 break;
 case 0x60770036U:
 if(!xx_rt_wcscmp(r->name,L"type"))text=L"1=stored contiguous,3=block chain";
 if(!xx_rt_wcscmp(r->name,L"adler32"))text=L"Stored checksum or digest";
 if(!xx_rt_wcscmp(r->name,L"name_size"))text=L"Excludes terminating NUL";
 if(!xx_rt_wcscmp(r->name,L"name_offset"))text=L"Relative to name table";
 break;
 case 0x60770038U:
 if(!xx_rt_wcscmp(r->name,L"compressed_size"))text=L"Zero means stored bytes of uncompressed_size";
 break;
 case 0x6077003cU:
 if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Relative to end of directory";
 if(!xx_rt_wcscmp(r->name,L"name_units"))text=L"UTF16BE code units";
 break;
 case 0x6077003dU:
 if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Relative to end of directory";
 if(!xx_rt_wcscmp(r->name,L"name_units"))text=L"UTF16BE code units";
 break;
 case 0x6077003fU:
 if(!xx_rt_wcscmp(r->name,L"stored_size"))text=L"Includes four-byte expected-size word, excludes this word";
 break;
 case 0x60770041U:
 if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Relative to the end of the complete text directory";
 break;
 case 0x60770044U:
 if(!xx_rt_wcscmp(r->name,L"name_units"))text=L"UTF16LE serialized units; retained as an array";
 break;
 case 0x60770045U:
 if(!xx_rt_wcscmp(r->name,L"name_units"))text=L"UTF16BE serialized units; retained as an array";
 break;
 case 0x6077004bU:
 if(!xx_rt_wcscmp(r->name,L"signature_type"))text=L"0x10001=RSA2048/SHA1";
 if(!xx_rt_wcscmp(r->name,L"signature"))text=L"RSA2048 signature bytes";
 break;
 case 0x6077004fU:
 if(!xx_rt_wcscmp(r->name,L"sha1"))text=L"Stored checksum or digest";
 break;
 case 0x60770051U:
 if(!xx_rt_wcscmp(r->name,L"sha1"))text=L"Stored checksum or digest";
 break;
 case 0x60770052U:
 if(!xx_rt_wcscmp(r->name,L"block_separation"))text=L"Bit0 selects single/double hash-table copies; bit1 selects top copy";
 if(!xx_rt_wcscmp(r->name,L"file_table_blocks"))text=L"Number of4096-byte logical blocks";
 if(!xx_rt_wcscmp(r->name,L"first_file_table_block"))text=L"Logical block index";
 break;
 case 0x60770053U:
 if(!xx_rt_wcscmp(r->name,L"top_sha1"))text=L"Stored checksum or digest";
 if(!xx_rt_wcscmp(r->name,L"allocated_blocks"))text=L"4096-byte logical blocks";
 if(!xx_rt_wcscmp(r->name,L"unallocated_blocks"))text=L"4096-byte logical blocks";
 break;
 case 0x60770055U:
 if(!xx_rt_wcscmp(r->name,L"sha1"))text=L"Stored checksum or digest";
 if(!xx_rt_wcscmp(r->name,L"status"))text=L">=0x80 allocated; parent bit0x40 selects alternate hash table";
 if(!xx_rt_wcscmp(r->name,L"next_block"))text=L"Logical block index;0xffffff terminates chain";
 break;
 case 0x60770056U:
 if(!xx_rt_wcscmp(r->name,L"name_length_flags"))text=L"Low6 bits=name byte count;0x40=consecutive;0x80=directory";
 if(!xx_rt_wcscmp(r->name,L"allocated_blocks"))text=L"4096-byte logical blocks";
 if(!xx_rt_wcscmp(r->name,L"first_block"))text=L"Logical block index";
 break;
 case 0x60770057U:
 if(!xx_rt_wcscmp(r->name,L"parent_index"))text=L"0xffff=root";
 if(!xx_rt_wcscmp(r->name,L"creation_time"))text=L"Packed FAT date/time";
 if(!xx_rt_wcscmp(r->name,L"access_time"))text=L"Packed FAT date/time";
 break;
 case 0x60770058U:
 if(!xx_rt_wcscmp(r->name,L"header_size"))text=L"Excludes this byte and checksum byte";
 if(!xx_rt_wcscmp(r->name,L"header_sum"))text=L"Stored checksum or digest";
 if(!xx_rt_wcscmp(r->name,L"compressed_size"))text=L"Level1 includes extended headers";
 break;
 case 0x60770059U:
 if(!xx_rt_wcscmp(r->name,L"crc16"))text=L"CRC16 checksum";
 break;
 case 0x6077005cU:
 if(!xx_rt_wcscmp(r->name,L"extension_type"))text=L"0=header CRC16;1=replacement filename;2=directory with0xff separators";
 break;
 case 0x6077005eU:
 if(!xx_rt_wcscmp(r->name,L"xor_checksum"))text=L"Stored checksum or digest";
 break;
 case 0x6077005fU:
 if(!xx_rt_wcscmp(r->name,L"stored_size"))text=L"Physical extent minus12; includes checksum word";
 if(!xx_rt_wcscmp(r->name,L"xor_checksum"))text=L"Stored checksum or digest";
 break;
 case 0x60770060U:
 if(!xx_rt_wcscmp(r->name,L"stored_size"))text=L"Physical extent minus8; includes final checksum and size words";
 break;
 case 0x60770062U:
 if(!xx_rt_wcscmp(r->name,L"encoded_size"))text=L"XOR with0x4d443131 gives two repeated16-bit plaintext lengths";
 break;
 case 0x60770064U:
 if(!xx_rt_wcscmp(r->name,L"xor_checksum"))text=L"Stored checksum or digest";
 break;
 case 0x60770065U:
 if(!xx_rt_wcscmp(r->name,L"encoded_header"))text=L"Whole transformed record header: decoded marker16, length32 and name10; byte rotations and previous-byte mixing prevent independent ciphertext-field semantics";
 break;
 case 0x60770066U:
 if(!xx_rt_wcscmp(r->name,L"rolling_checksum"))text=L"16-bit rotate-left sum over decoded member bytes";
 break;
 case 0x6077006aU:
 if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Relative to data area";
 if(!xx_rt_wcscmp(r->name,L"name_offset_flags"))text=L"Low24 bits=name-table-relative offset; physical name begins two bytes later";
 if(!xx_rt_wcscmp(r->name,L"directory_offset_flags"))text=L"Low24 bits=name-table-relative offset; zero=no parent";
 break;
 case 0x6077006eU:
 if(!xx_rt_wcscmp(r->name,L"crc32"))text=L"CRC32 of the applicable physical or decoded block";
 break;
 case 0x60770072U:
 if(!xx_rt_wcscmp(r->name,L"block_type"))text=L"1=header,3=directory,4=footer";
 break;
 case 0x60770073U:
 if(!xx_rt_wcscmp(r->name,L"count"))text=L"Physical FreeArc variable-length count";
 break;
 case 0x60770074U:
 if(!xx_rt_wcscmp(r->name,L"relative_offset"))text=L"Backward distance from containing directory/footer data start";
 break;
 case 0x60770077U:
 if(!xx_rt_wcscmp(r->name,L"directory_index"))text=L"Zero-based directory index";
 break;
 case 0x60770078U:
 if(!xx_rt_wcscmp(r->name,L"block_type"))text=L"1=header,3=directory,4=footer";
 break;
 case 0x60770079U:
 if(!xx_rt_wcscmp(r->name,L"count"))text=L"Physical FreeArc variable-length count";
 break;
 case 0x6077007aU:
 if(!xx_rt_wcscmp(r->name,L"relative_offset"))text=L"Backward distance from containing directory/footer data start";
 break;
 case 0x6077007dU:
 if(!xx_rt_wcscmp(r->name,L"directory_index"))text=L"Zero-based directory index";
 break;
 case 0x6077007eU:
 if(!xx_rt_wcscmp(r->name,L"block_type"))text=L"1=header,3=directory,4=footer";
 break;
 case 0x6077007fU:
 if(!xx_rt_wcscmp(r->name,L"count"))text=L"Physical FreeArc variable-length count";
 break;
 case 0x60770080U:
 if(!xx_rt_wcscmp(r->name,L"relative_offset"))text=L"Backward distance from containing directory/footer data start";
 break;
 case 0x60770083U:
 if(!xx_rt_wcscmp(r->name,L"directory_index"))text=L"Zero-based directory index";
 break;
 case 0x60770084U:
 if(!xx_rt_wcscmp(r->name,L"block_type"))text=L"1=header,3=directory,4=footer";
 break;
 case 0x60770085U:
 if(!xx_rt_wcscmp(r->name,L"count"))text=L"Physical FreeArc variable-length count";
 break;
 case 0x60770086U:
 if(!xx_rt_wcscmp(r->name,L"relative_offset"))text=L"Backward distance from containing directory/footer data start";
 break;
 case 0x60770089U:
 if(!xx_rt_wcscmp(r->name,L"directory_index"))text=L"Zero-based directory index";
 break;
 case 0x6077008aU:
 if(!xx_rt_wcscmp(r->name,L"block_type"))text=L"1=header,3=directory,4=footer";
 break;
 case 0x6077008bU:
 if(!xx_rt_wcscmp(r->name,L"count"))text=L"Physical FreeArc variable-length count";
 break;
 case 0x6077008cU:
 if(!xx_rt_wcscmp(r->name,L"relative_offset"))text=L"Backward distance from containing directory/footer data start";
 break;
 case 0x6077008fU:
 if(!xx_rt_wcscmp(r->name,L"directory_index"))text=L"Zero-based directory index";
 break;
 case 0x60770090U:
 if(!xx_rt_wcscmp(r->name,L"block_type"))text=L"1=header,3=directory,4=footer";
 break;
 case 0x60770091U:
 if(!xx_rt_wcscmp(r->name,L"count"))text=L"Physical FreeArc variable-length count";
 break;
 case 0x60770092U:
 if(!xx_rt_wcscmp(r->name,L"relative_offset"))text=L"Backward distance from containing directory/footer data start";
 break;
 case 0x60770095U:
 if(!xx_rt_wcscmp(r->name,L"directory_index"))text=L"Zero-based directory index";
 break;
 case 0x60770096U:
 if(!xx_rt_wcscmp(r->name,L"block_type"))text=L"1=header,3=directory,4=footer";
 break;
 case 0x60770097U:
 if(!xx_rt_wcscmp(r->name,L"count"))text=L"Physical FreeArc variable-length count";
 break;
 case 0x60770098U:
 if(!xx_rt_wcscmp(r->name,L"relative_offset"))text=L"Backward distance from containing directory/footer data start";
 break;
 case 0x6077009bU:
 if(!xx_rt_wcscmp(r->name,L"directory_index"))text=L"Zero-based directory index";
 break;
 case 0x6077009cU:
 if(!xx_rt_wcscmp(r->name,L"block_type"))text=L"1=header,3=directory,4=footer";
 break;
 case 0x6077009dU:
 if(!xx_rt_wcscmp(r->name,L"count"))text=L"Physical FreeArc variable-length count";
 break;
 case 0x6077009eU:
 if(!xx_rt_wcscmp(r->name,L"relative_offset"))text=L"Backward distance from containing directory/footer data start";
 break;
 case 0x607700a1U:
 if(!xx_rt_wcscmp(r->name,L"directory_index"))text=L"Zero-based directory index";
 break;
 case 0x607700a2U:
 if(!xx_rt_wcscmp(r->name,L"block_type"))text=L"1=header,3=directory,4=footer";
 break;
 case 0x607700a3U:
 if(!xx_rt_wcscmp(r->name,L"count"))text=L"Physical FreeArc variable-length count";
 break;
 case 0x607700a4U:
 if(!xx_rt_wcscmp(r->name,L"relative_offset"))text=L"Backward distance from containing directory/footer data start";
 break;
 case 0x607700a7U:
 if(!xx_rt_wcscmp(r->name,L"directory_index"))text=L"Zero-based directory index";
 break;
 case 0x607700abU:
 if(!xx_rt_wcscmp(r->name,L"marker"))text=L"0=header terminator/reserved;1=segment;253=SHA1 follows;254=no SHA1;255=end block";
 break;
 case 0x607700acU:
 if(!xx_rt_wcscmp(r->name,L"run_size"))text=L"Zero ends stored segment; decoded payload may include PCOMP controls";
 break;
 case 0x607700adU:
 if(!xx_rt_wcscmp(r->name,L"sha1"))text=L"SHA1 digest of decoded segment bytes";
 break;
 default:break;}
 return !text||xx_data_struct_record_set_comment(r,text);
}
#define SXAN_LIMIT 20000U
bool sxan_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
bool sxan_read(sx_context*c,uint64_t p,void*b,size_t n){return sxan_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
uint64_t sxan_uint(const uint8_t*b,unsigned n,bool be){uint64_t v=0;for(unsigned i=0;i<n;i++)v|=(uint64_t)b[i]<<(8*(be?n-1-i:i));return v;}
bool sxan_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v){uint8_t b[8];if(!n||n>8||!sxan_read(c,p,b,n))return false;*v=sxan_uint(b,n,be);return true;}
/* All coordinates are physical. Only documented byte aliases opt into overlap. */
static bool sxan_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n,bool aliases){if(c->count>=SXAN_LIMIT||xx_pd_is_stopped(c->pd))return false;if(!n){const xx_data_struct_field_desc*f=&l->fields[l->field_count-1];if(!f->size)return false;n=(uint64_t)(f->rel_offset+f->size);}if(!sxan_span(c,p,n))return false;int64_t a=c->f->base_address+(int64_t)p;size_t lo=0,hi=c->count;while(lo<hi){size_t m=lo+(hi-lo)/2;if(c->items[m].offset<a)lo=m+1;else hi=m;}if(!aliases&&((lo<c->count&&c->items[lo].offset<a+(int64_t)n)||(lo&&c->items[lo-1].offset+c->items[lo-1].total_size>a)))return true;size_t old=c->count;if(!sx_add(c,l,(int64_t)p,(int64_t)n))return false;xx_data_struct row=c->items[old];xx_rt_memmove(c->items+lo+1,c->items+lo,(old-lo)*sizeof(row));c->items[lo]=row;return true;}
bool sxan_add(sx_context*c,const sx_layout*l,uint64_t p){return sxan_put(c,l,p,0,false);}
bool sxan_text(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n,bool aliases){int64_t max=sx_variable_field_limit(l->fields[l->field_count-1].type);return !n||n>(uint64_t)(max?max:4096)?true:sxan_put(c,l,p,n,aliases);}
bool sxan_zlen(sx_context*c,uint64_t p,uint64_t end,uint64_t*n){uint8_t b;*n=0;while(p<end&&*n<4096){if(!sxan_read(c,p++,&b,1))return false;(*n)++;if(!b)return true;}return false;}
static int sxan_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
bool sxan_finish(sx_context*c){size_t n=c->count;int64_t end=0;for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p>end&&!sx_raw(c,end,p-end))return false;if(p+c->items[i].total_size>end)end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxan_order);return !c->failed;}
bool sxan_table(sx_context*c,const sx_layout*l,uint64_t p,uint64_t width,uint64_t n){if(!width||p>(uint64_t)c->size||n>(((uint64_t)c->size-p)/width))return false;for(uint64_t i=0;i<n;i++)if(!sxan_add(c,l,p+i*width))return false;return true;}
/* Locate the same physical PE overlay used by the native installer readers.
 * This parses only wire headers and introduces no constructor/profile dependency. */
bool sxan_pe_overlay(sx_context*c,uint64_t*out){uint8_t h[40];uint64_t pe,sections,optional,end=0;if(!sxan_read(c,0,h,2)||h[0]!='M'||h[1]!='Z'||!sxan_word(c,60,4,false,&pe)||!sxan_read(c,pe,h,24)||xx_rt_memcmp(h,"PE\0\0",4))return false;sections=sxan_uint(h+6,2,false);optional=sxan_uint(h+20,2,false);if(!sections||sections>4096||!sxan_span(c,pe+24,optional)||!sxan_span(c,pe+24+optional,40*sections))return false;for(uint64_t i=0;i<sections;i++){if(!sxan_read(c,pe+24+optional+40*i,h,40))return false;uint64_t z=sxan_uint(h+16,4,false),p=sxan_uint(h+20,4,false);if(!sxan_span(c,p,z))return false;if(z&&p+z>end)end=p+z;}if(!end)return false;*out=end;return true;}
bool sxan_named(sx_context*c,uint64_t p,uint64_t n){return sxan_span(c,p,n)&&sxan_text(c,&sxan_archivenext_name,p,n,false);}
/* Native callback offsets are authenticated, physical, and already include
 * the reader base. They identify relocated PC-Install records and Spoon
 * directories without scanning the executable for coincidental strings. */
bool sxan_callback(sx_context*c,unsigned kind){Abstractformat*f=c->f;if(!f->create_archive_records_reading||!f->get_current_archive_record||!f->archive_record_move_to_next||!f->free_archive_records_reading)return true;xx_archive_record_state*s=(f->create_archive_records_reading)(f,NULL,c->pd);if(!s)return true;bool ok=true;uint64_t last=0,first=UINT64_MAX,nested_first=UINT64_MAX;for(unsigned i=0;i<SXAN_LIMIT;i++){const xx_archive_record*r=(f->get_current_archive_record)(f,s);if(!r)break;if(r->header_offset>=f->base_address&&r->header_size>0){uint64_t p=(uint64_t)(r->header_offset-f->base_address),z=(uint64_t)r->header_size;if(sxan_span(c,p,z)){if(kind==1&&z>=17){ok=sxan_add(c,&sxan_spoon_member,p)&&sxan_named(c,p+17,z-17);if(p+z>last)last=p+z;}else if(kind==2){if(z==276){ok=sxan_add(c,&sxan_pc_install_member,p);if(p<first)first=p;/* The native stream publishes authenticated nested entries before the raw group. A prefix match alone is insufficient. */if(nested_first==p+276+58&&r->compressed_size>=58&&r->data_offset==r->header_offset+276)ok=ok&&sxan_add(c,&sxan_pc_install_group,p+276);nested_first=UINT64_MAX;}else if(z==168){if(p<nested_first)nested_first=p;ok=sxan_add(c,&sxan_pc_install_group_member,p);}}}}if(!ok||!(f->archive_record_move_to_next)(f,s,c->pd))break;}(f->free_archive_records_reading)(f,s);if(!ok)return false;if(kind==1&&last&&sxan_span(c,last,24))return sxan_add(c,&sxan_spoon_footer,last);if(kind==2){if(first>=8&&first!=UINT64_MAX&&!sxan_add(c,&sxan_pc_install_tag,first-8))return false;return c->size<16||sxan_add(c,&sxan_pc_install_trailer,(uint64_t)c->size-16);}return true;}
bool sxan_ckpedp(sx_context*c){uint64_t n,p=14,len;unsigned width=c->f->file_type==XX_FILE_TYPE_EDP?2:1;if(!sxan_add(c,&sxan_ckpedp_header,0)||!sxan_word(c,6,4,false,&n))return false;for(uint64_t i=0;i<n;i++){if(!sxan_word(c,p,2,false,&len)||!sxan_add(c,&sxan_ckpedp_name_size,p)||!sxan_span(c,p+2,len*width)||!sxan_text(c,&sxan_ckpedp_encoded_name,p+2,len*width,false))return false;p+=2+len*width;if(!sxan_add(c,&sxan_ckpedp_member_tail,p))return false;p+=20;}return true;}
bool sxan_parsec(sx_context*c){uint64_t z,n,p,len;uint8_t h[8];if(c->f->file_type==XX_FILE_TYPE_PARSEC_RIB)return sxan_add(c,&sxan_parsec_rib_header,0);if(!sxan_word(c,0,4,false,&z)||z<12||(z-4)%8||!sxan_span(c,0,z))return false;n=(z-4)/8;if(!sxan_table(c,&sxan_parsec_member_offset,0,4,n+1)||!sxan_table(c,&sxan_parsec_member_size,4*(n+1),4,n))return false;for(uint64_t i=0;i<n;i++){if(!sxan_word(c,4*i,4,false,&p)||!sxan_word(c,4*(n+1+i),4,false,&len))return false;if(len>=8&&sxan_span(c,p,len)&&sxan_read(c,p,h,8)&&!xx_rt_memcmp(h,"RIB\0",4)&&!sxan_add(c,&sxan_parsec_rib_header,p))return false;}return true;}
bool sxan_lha(sx_context*c){uint64_t p=0;while(sxan_span(c,p,1)){uint8_t h[22];if(!sxan_read(c,p,h,1))return false;if(!h[0])return sxan_add(c,&sxan_lha_dialect_end,p);if(!sxan_read(c,p,h,22))return true;uint64_t total=(uint64_t)h[0]+2,packed=sxan_uint(h+7,4,false),len=h[21],q,next=0,used=0;if(h[20]>1||total<24+len||!sxan_span(c,p,total)||!sxan_add(c,&sxan_lha_dialect_header,p)||!sxan_named(c,p+22,len)||!sxan_add(c,&sxan_lha_dialect_crc,p+22+len))return false;q=p+total;if(h[20]==1){if(total<27+len||!sxan_add(c,&sxan_lha_dialect_os,p+24+len)||!sxan_add(c,&sxan_lha_dialect_next,p+total-2)||!sxan_word(c,p+total-2,2,false,&next))return false;for(unsigned i=0;next&&i<SXAN_LIMIT;i++){uint64_t z=next;if(z<3||used>packed||z>packed-used||!sxan_span(c,q,z)||!sxan_add(c,&sxan_lha_dialect_type,q)||!sxan_add(c,&sxan_lha_dialect_next,q+z-2)||!sxan_word(c,q+z-2,2,false,&next))return false;uint64_t type;if(!sxan_word(c,q,1,false,&type))return false;if(type==0&&z>=5){if(!sxan_add(c,&sxan_lha_dialect_crc,q+1))return false;}else if((type==1||type==2)&&!sxan_named(c,q+1,z-3))return false;q+=z;used+=z;}}if(used>packed||!sxan_span(c,q,packed-used))return true;p=q+packed-used;}return true;}
static bool sx_archivenext_supports(xx_file_type_t type){switch(type){case XX_FILE_TYPE_IS3:case XX_FILE_TYPE_IS5:case XX_FILE_TYPE_IS11:case XX_FILE_TYPE_GKSETUP:case XX_FILE_TYPE_PCINSTALL:case XX_FILE_TYPE_FINSTALL:case XX_FILE_TYPE_IFAH_INSTALLER:case XX_FILE_TYPE_O_SETUP:case XX_FILE_TYPE_PC_INSTALL_SETUP:case XX_FILE_TYPE_RTPATCH_SETUP_DATA:case XX_FILE_TYPE_SPOON_INSTALLER:case XX_FILE_TYPE_INSTALLSHIELD_ISSETUPSTREAM:case XX_FILE_TYPE_ESCHALON_SETUP_EPSF:case XX_FILE_TYPE_SETUP_FACTORY:case XX_FILE_TYPE_WESTWOOD_PAK:case XX_FILE_TYPE_CKP:case XX_FILE_TYPE_EDP:case XX_FILE_TYPE_PARSEC_RIB:case XX_FILE_TYPE_PARSEC_ARCHIVE:case XX_FILE_TYPE_PTERO_BIGF:case XX_FILE_TYPE_PIRS:case XX_FILE_TYPE_SBPAK:case XX_FILE_TYPE_TITAN_QUEST:case XX_FILE_TYPE_CGJP:case XX_FILE_TYPE_BIRDIES:case XX_FILE_TYPE_XUIZ:case XX_FILE_TYPE_WII_WAD:case XX_FILE_TYPE_FREEARC:case XX_FILE_TYPE_ZPAQ:case XX_FILE_TYPE_BYTEKILLER:case XX_FILE_TYPE_DCS:case XX_FILE_TYPE_AUDIALS:case XX_FILE_TYPE_OSL2000:case XX_FILE_TYPE_MICROFOX_PUT:case XX_FILE_TYPE_SAR:return true;default:return false;}}
static bool sx_archivenext_build(sx_context*c){if(!c||!c->f||c->size<0||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;
if(c->f->file_type==XX_FILE_TYPE_IS3)return sx_is3_build(c);
if(c->f->file_type==XX_FILE_TYPE_IS5)return sx_is5_build(c);
if(c->f->file_type==XX_FILE_TYPE_IS11)return sx_is11_build(c);
if(c->f->file_type==XX_FILE_TYPE_GKSETUP)return sx_gksetup_build(c);
if(c->f->file_type==XX_FILE_TYPE_PCINSTALL)return sx_pcinstall_build(c);
if(c->f->file_type==XX_FILE_TYPE_FINSTALL)return sx_finstall_build(c);
if(c->f->file_type==XX_FILE_TYPE_IFAH_INSTALLER)return sx_ifah_installer_build(c);
if(c->f->file_type==XX_FILE_TYPE_O_SETUP)return sx_o_setup_build(c);
if(c->f->file_type==XX_FILE_TYPE_PC_INSTALL_SETUP)return sx_pc_install_setup_build(c);
if(c->f->file_type==XX_FILE_TYPE_RTPATCH_SETUP_DATA)return sx_rtpatch_setup_data_build(c);
if(c->f->file_type==XX_FILE_TYPE_SPOON_INSTALLER)return sx_spoon_installer_build(c);
if(c->f->file_type==XX_FILE_TYPE_INSTALLSHIELD_ISSETUPSTREAM)return sx_installshield_issetupstream_build(c);
if(c->f->file_type==XX_FILE_TYPE_ESCHALON_SETUP_EPSF)return sx_eschalon_setup_epsf_build(c);
if(c->f->file_type==XX_FILE_TYPE_SETUP_FACTORY)return sx_setup_factory_build(c);
if(c->f->file_type==XX_FILE_TYPE_WESTWOOD_PAK)return sx_westwood_pak_build(c);
if(c->f->file_type==XX_FILE_TYPE_CKP)return sx_ckp_build(c);
if(c->f->file_type==XX_FILE_TYPE_EDP)return sx_edp_build(c);
if(c->f->file_type==XX_FILE_TYPE_PARSEC_RIB)return sx_parsec_rib_build(c);
if(c->f->file_type==XX_FILE_TYPE_PARSEC_ARCHIVE)return sx_parsec_archive_build(c);
if(c->f->file_type==XX_FILE_TYPE_PTERO_BIGF)return sx_ptero_bigf_build(c);
if(c->f->file_type==XX_FILE_TYPE_PIRS)return sx_pirs_build(c);
if(c->f->file_type==XX_FILE_TYPE_SBPAK)return sx_sbpak_build(c);
if(c->f->file_type==XX_FILE_TYPE_TITAN_QUEST)return sx_titan_quest_build(c);
if(c->f->file_type==XX_FILE_TYPE_CGJP)return sx_cgjp_build(c);
if(c->f->file_type==XX_FILE_TYPE_BIRDIES)return sx_birdies_build(c);
if(c->f->file_type==XX_FILE_TYPE_XUIZ)return sx_xuiz_build(c);
if(c->f->file_type==XX_FILE_TYPE_WII_WAD)return sx_wii_wad_build(c);
if(c->f->file_type==XX_FILE_TYPE_FREEARC)return sx_freearc_build(c);
if(c->f->file_type==XX_FILE_TYPE_ZPAQ)return sx_zpaq_build(c);
if(c->f->file_type==XX_FILE_TYPE_BYTEKILLER)return sx_bytekiller_build(c);
if(c->f->file_type==XX_FILE_TYPE_DCS)return sx_dcs_build(c);
if(c->f->file_type==XX_FILE_TYPE_AUDIALS)return sx_audials_build(c);
if(c->f->file_type==XX_FILE_TYPE_OSL2000)return sx_osl2000_build(c);
if(c->f->file_type==XX_FILE_TYPE_MICROFOX_PUT)return sx_microfox_put_build(c);
if(c->f->file_type==XX_FILE_TYPE_SAR)return sx_sar_build(c);
return c->count&&sxan_finish(c);}
const sx_family sx_archivenext_family={sx_archivenext_supports,sx_archivenext_build,sx_archivenext_layouts,SX_COUNT(sx_archivenext_layouts),sx_archivenext_comment};
