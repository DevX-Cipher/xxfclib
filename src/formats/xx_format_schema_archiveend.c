/* SPDX-License-Identifier: MIT. Genuine physical metadata; see docs/data_struct_archiveend_scope.txt. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_archiveend.h"
static const xx_data_struct_field_desc sxaend_archiveend_name_fields[]={
 SX_FIELD("archiveend_name","char",0,0,SX_STRING),
};
static const sx_layout sxaend_archiveend_name={UINT32_C(0x60840001),"archiveend_name",sxaend_archiveend_name_fields,SX_COUNT(sxaend_archiveend_name_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_archiveend_comment_fields[]={
 SX_FIELD("archiveend_comment","char",0,0,SX_STRING),
};
const sx_layout sxaend_archiveend_comment={UINT32_C(0x60840002),"archiveend_comment",sxaend_archiveend_comment_fields,SX_COUNT(sxaend_archiveend_comment_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_sfx_arcv2_header_fields[]={
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_NONE),
 SX_FIELD("header_size","uint16",6,2,SX_SIZE),
 SX_FIELD("volume_flags","uint32",8,4,SX_NONE),
 SX_FIELD("disk_number","uint16",12,2,SX_NONE),
};
static const sx_layout sxaend_sfx_arcv2_header={UINT32_C(0x6084002c),"sfx_arcv2_header",sxaend_sfx_arcv2_header_fields,SX_COUNT(sxaend_sfx_arcv2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_sfx_arcv2_block_fields[]={
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_NONE),
 SX_FIELD("header_size","uint16",6,2,SX_SIZE),
 SX_FIELD("flags","uint32",8,4,SX_NONE),
 SX_FIELD("volume_payload_size","uint32",12,4,SX_SIZE),
 SX_FIELD("name_size","uint8",16,1,SX_SIZE),
};
static const sx_layout sxaend_sfx_arcv2_block={UINT32_C(0x6084002d),"sfx_arcv2_block",sxaend_sfx_arcv2_block_fields,SX_COUNT(sxaend_sfx_arcv2_block_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_sfx_arcv2_attributes_fields[]={
 SX_FIELD("uncompressed_size","uint32",0,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("attributes","uint32",8,4,SX_NONE),
 SX_FIELD("dos_timestamp","uint32",12,4,SX_NONE),
 SX_FIELD("opaque","uint8[8]",16,8,SX_NONE),
 SX_FIELD("packed_crc32","uint32",24,4,SX_CHECKSUM),
};
static const sx_layout sxaend_sfx_arcv2_attributes={UINT32_C(0x6084002e),"sfx_arcv2_attributes",sxaend_sfx_arcv2_attributes_fields,SX_COUNT(sxaend_sfx_arcv2_attributes_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_sfx_tgcf_header_fields[]={
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("opaque1","uint8[2]",4,2,SX_NONE),
 SX_FIELD("version","uint16",6,2,SX_NONE),
 SX_FIELD("opaque2","uint8[18]",8,18,SX_NONE),
 SX_FIELD("volume_name_size","uint16",26,2,SX_SIZE),
};
static const sx_layout sxaend_sfx_tgcf_header={UINT32_C(0x6084002f),"sfx_tgcf_header",sxaend_sfx_tgcf_header_fields,SX_COUNT(sxaend_sfx_tgcf_header_fields),SX_BE};
static const xx_data_struct_field_desc sxaend_sfx_tgcf_list_offset_fields[]={
 SX_FIELD("member_list_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxaend_sfx_tgcf_list_offset={UINT32_C(0x60840030),"sfx_tgcf_list_offset",sxaend_sfx_tgcf_list_offset_fields,SX_COUNT(sxaend_sfx_tgcf_list_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxaend_sfx_tgcf_crc_fields[]={
 SX_FIELD("crc32","uint32",0,4,SX_CHECKSUM),
};
static const sx_layout sxaend_sfx_tgcf_crc={UINT32_C(0x60840031),"sfx_tgcf_crc",sxaend_sfx_tgcf_crc_fields,SX_COUNT(sxaend_sfx_tgcf_crc_fields),SX_BE};
static const xx_data_struct_field_desc sxaend_sfx_tgcf_member_prefix_fields[]={
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("opaque","uint8[8]",4,8,SX_NONE),
 SX_FIELD("split_kind","uint16",12,2,SX_NONE),
 SX_FIELD("method","uint16",14,2,SX_NONE),
};
static const sx_layout sxaend_sfx_tgcf_member_prefix={UINT32_C(0x60840032),"sfx_tgcf_member_prefix",sxaend_sfx_tgcf_member_prefix_fields,SX_COUNT(sxaend_sfx_tgcf_member_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_sfx_tgcf_member_attributes_fields[]={
 SX_FIELD("timestamp","uint32",0,4,SX_NONE),
 SX_FIELD("compressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("crc32","uint32",12,4,SX_CHECKSUM),
 SX_FIELD("attributes","uint32",16,4,SX_NONE),
};
static const sx_layout sxaend_sfx_tgcf_member_attributes={UINT32_C(0x60840033),"sfx_tgcf_member_attributes",sxaend_sfx_tgcf_member_attributes_fields,SX_COUNT(sxaend_sfx_tgcf_member_attributes_fields),SX_BE};
static const xx_data_struct_field_desc sxaend_sfx_tgcf_member_flag_fields[]={
 SX_FIELD("flag","uint8",0,1,SX_NONE),
};
static const sx_layout sxaend_sfx_tgcf_member_flag={UINT32_C(0x60840034),"sfx_tgcf_member_flag",sxaend_sfx_tgcf_member_flag_fields,SX_COUNT(sxaend_sfx_tgcf_member_flag_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_sfx_tgcf_payload_offset_fields[]={
 SX_FIELD("payload_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxaend_sfx_tgcf_payload_offset={UINT32_C(0x60840035),"sfx_tgcf_payload_offset",sxaend_sfx_tgcf_payload_offset_fields,SX_COUNT(sxaend_sfx_tgcf_payload_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxaend_sfx_imp_header_fields[]={
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("directory_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("member_count","uint32",8,4,SX_COUNT_PROP),
 SX_FIELD("opaque","uint8[26]",12,26,SX_NONE),
 SX_FIELD("flags","uint16",38,2,SX_FLAGS),
 SX_FIELD("header_crc16","uint16",40,2,SX_CHECKSUM),
};
static const sx_layout sxaend_sfx_imp_header={UINT32_C(0x60840036),"sfx_imp_header",sxaend_sfx_imp_header_fields,SX_COUNT(sxaend_sfx_imp_header_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_sfx_imp_directory_block_fields[]={
 SX_FIELD("signature","uint8[6]",0,6,SX_SIGNATURE),
 SX_FIELD("method_and_lengths","uint48",6,6,SX_FLAGS),
};
static const sx_layout sxaend_sfx_imp_directory_block={UINT32_C(0x60840037),"sfx_imp_directory_block",sxaend_sfx_imp_directory_block_fields,SX_COUNT(sxaend_sfx_imp_directory_block_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_sfx_cazip_header_fields[]={
 SX_FIELD("lead_in","uint8[3]",0,3,SX_SIGNATURE),
 SX_FIELD("signature","char[5]",3,5,SX_SIGNATURE),
 SX_FIELD("version","char[2]",8,2,SX_NONE),
 SX_FIELD("fixed_word","uint16",10,2,SX_NONE),
 SX_FIELD("volume_flag","uint16",12,2,SX_NONE),
 SX_FIELD("crc32","uint32",14,4,SX_CHECKSUM),
 SX_FIELD("reserved","uint8[2]",18,2,SX_NONE),
};
static const sx_layout sxaend_sfx_cazip_header={UINT32_C(0x60840038),"sfx_cazip_header",sxaend_sfx_cazip_header_fields,SX_COUNT(sxaend_sfx_cazip_header_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_sfx_cazip_dcl_prefix_fields[]={
 SX_FIELD("literal_mode","uint8",0,1,SX_NONE),
 SX_FIELD("dictionary_bits","uint8",1,1,SX_NONE),
};
static const sx_layout sxaend_sfx_cazip_dcl_prefix={UINT32_C(0x60840039),"sfx_cazip_dcl_prefix",sxaend_sfx_cazip_dcl_prefix_fields,SX_COUNT(sxaend_sfx_cazip_dcl_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_sfx_starkit_header_fields[]={
 SX_FIELD("magic","uint8[4]",0,4,SX_SIGNATURE),
 SX_FIELD("file_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxaend_sfx_starkit_header={UINT32_C(0x6084003a),"sfx_starkit_header",sxaend_sfx_starkit_header_fields,SX_COUNT(sxaend_sfx_starkit_header_fields),SX_BE};
static const xx_data_struct_field_desc sxaend_sfx_starkit_commit_fields[]={
 SX_FIELD("commit_tag","uint32",0,4,SX_FLAGS),
 SX_FIELD("footer_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("root_size_and_tag","uint32",8,4,SX_FLAGS),
 SX_FIELD("root_offset","uint32",12,4,SX_OFFSET),
};
static const sx_layout sxaend_sfx_starkit_commit={UINT32_C(0x6084003b),"sfx_starkit_commit",sxaend_sfx_starkit_commit_fields,SX_COUNT(sxaend_sfx_starkit_commit_fields),SX_BE};
static const xx_data_struct_field_desc sxaend_sfx_starkit_root_prefix_fields[]={
 SX_FIELD("root_tag","uint8",0,1,SX_FLAGS),
 SX_FIELD("schema_size_and_tag","uint8",1,1,SX_FLAGS),
};
static const sx_layout sxaend_sfx_starkit_root_prefix={UINT32_C(0x6084003c),"sfx_starkit_root_prefix",sxaend_sfx_starkit_root_prefix_fields,SX_COUNT(sxaend_sfx_starkit_root_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_sfx_spis_header_fields[]={
 SX_FIELD("signature","uint8[5]",0,5,SX_SIGNATURE),
 SX_FIELD("method_tag","char[3]",5,3,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("archive_type","uint8",12,1,SX_NONE),
 SX_FIELD("checksum","uint32",13,4,SX_CHECKSUM),
 SX_FIELD("flags","uint32",17,4,SX_NONE),
};
static const sx_layout sxaend_sfx_spis_header={UINT32_C(0x6084003d),"sfx_spis_header",sxaend_sfx_spis_header_fields,SX_COUNT(sxaend_sfx_spis_header_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_sfx_spis_member_fields[]={
 SX_FIELD("name_size","uint16",0,2,SX_SIZE),
 SX_FIELD("dos_timestamp","uint32",2,4,SX_NONE),
 SX_FIELD("attributes","uint16",6,2,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",12,4,SX_SIZE),
 SX_FIELD("method","uint8",16,1,SX_NONE),
 SX_FIELD("checksum","uint32",17,4,SX_CHECKSUM),
 SX_FIELD("flags","uint32",21,4,SX_NONE),
};
static const sx_layout sxaend_sfx_spis_member={UINT32_C(0x6084003e),"sfx_spis_member",sxaend_sfx_spis_member_fields,SX_COUNT(sxaend_sfx_spis_member_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_pfx_lha_member_fields[]={
 SX_FIELD("header_size_minus_two","uint8",0,1,SX_NONE),
 SX_FIELD("header_checksum","uint8",1,1,SX_CHECKSUM),
 SX_FIELD("method","char[5]",2,5,SX_ID),
 SX_FIELD("packed_size","uint32",7,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",11,4,SX_SIZE),
 SX_FIELD("dos_date_time","uint32",15,4,SX_NONE),
 SX_FIELD("attributes","uint8",19,1,SX_FLAGS),
 SX_FIELD("header_level","uint8",20,1,SX_NONE),
 SX_FIELD("name_size","uint8",21,1,SX_SIZE),
};
static const sx_layout sxaend_pfx_lha_member={UINT32_C(0x60840040),"pfx_lha_member",sxaend_pfx_lha_member_fields,SX_COUNT(sxaend_pfx_lha_member_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_pfx_lha_crc_fields[]={
 SX_FIELD("data_crc16","uint16",0,2,SX_CHECKSUM),
};
static const sx_layout sxaend_pfx_lha_crc={UINT32_C(0x60840041),"pfx_lha_crc",sxaend_pfx_lha_crc_fields,SX_COUNT(sxaend_pfx_lha_crc_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_sfx_zip_local_fields[]={
 SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("version_needed","uint16",4,2,SX_NONE),
 SX_FIELD("flags","uint16",6,2,SX_FLAGS),
 SX_FIELD("method","uint16",8,2,SX_ID),
 SX_FIELD("dos_time","uint16",10,2,SX_NONE),
 SX_FIELD("dos_date","uint16",12,2,SX_NONE),
 SX_FIELD("crc32","uint32",14,4,SX_CHECKSUM),
 SX_FIELD("compressed_size","uint32",18,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",22,4,SX_SIZE),
 SX_FIELD("name_size","uint16",26,2,SX_SIZE),
 SX_FIELD("extra_size","uint16",28,2,SX_SIZE),
};
static const sx_layout sxaend_sfx_zip_local={UINT32_C(0x60840042),"sfx_zip_local",sxaend_sfx_zip_local_fields,SX_COUNT(sxaend_sfx_zip_local_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_sfx_zip_extra_fields[]={
 SX_FIELD("tag","uint16",0,2,SX_ID),
 SX_FIELD("payload_size","uint16",2,2,SX_SIZE),
};
static const sx_layout sxaend_sfx_zip_extra={UINT32_C(0x60840043),"sfx_zip_extra",sxaend_sfx_zip_extra_fields,SX_COUNT(sxaend_sfx_zip_extra_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_localzip_softpaq_member_fields[]={
 SX_FIELD("name_size","uint8",0,1,SX_SIZE),
};
static const sx_layout sxaend_localzip_softpaq_member={UINT32_C(0x60840045),"localzip_softpaq_member",sxaend_localzip_softpaq_member_fields,SX_COUNT(sxaend_localzip_softpaq_member_fields),SX_LE};
static const sx_layout *const sx_archiveend_layouts[]={
 &sxaend_archiveend_name,
 &sxaend_archiveend_comment,
 &sxaend_sds_sfx_member,
 &sxaend_lhpak_sfx_position,
 &sxaend_lhpak_sfx_member,
 &sxaend_lhpak_sfx_block,
 &sxaend_lhsfx_control,
 &sxaend_lhsfx_member,
 &sxaend_omni_mode,
 &sxaend_omni_comment_size,
 &sxaend_omni_name_size,
 &sxaend_omni_data_size,
 &sxaend_omni_member_tail,
 &sxaend_omni_lh_block,
 &sxaend_diet_data_v100,
 &sxaend_diet_data_v102,
 &sxaend_diet_data_v144,
 &sxaend_diet_data_lengths,
 &sxaend_dclraw_stream,
 &sxaend_copyqm_tx_header,
 &sxaend_copyqm_tx_leaf,
 &sxaend_copyqm_tx_branch,
 &sxaend_copyqm_tx_screen6,
 &sxaend_copyqm_tx_screen8,
 &sxaend_copyqm_tx_geometry,
 &sxaend_copyqm_tx_line,
 &sxaend_nss_member,
 &sxaend_dcx_ftsv_header,
 &sxaend_dcx_ftsv_table,
 &sxaend_dcx_ftsv_context,
 &sxaend_dcx_ftsv_leaf_bitmap,
 &sxaend_dcx_ftsv_nodes,
 &sxaend_dcx_ftsv_map,
 &sxaend_dcx_ftsv_first_frame,
 &sxaend_dcx_ftsv_second_group,
 &sxaend_dcx_ftsv_frame,
 &sxaend_dcx_ftsv_group_start,
 &sxaend_dcx_ftsv_group_end,
 &sxaend_pmarc_member,
 &sxaend_pmarc_crc,
 &sxaend_pmarc_end,
 &sxaend_boo_name,
 &sxaend_boo_encoded_line,
 &sxaend_sfx_arcv2_header,
 &sxaend_sfx_arcv2_block,
 &sxaend_sfx_arcv2_attributes,
 &sxaend_sfx_tgcf_header,
 &sxaend_sfx_tgcf_list_offset,
 &sxaend_sfx_tgcf_crc,
 &sxaend_sfx_tgcf_member_prefix,
 &sxaend_sfx_tgcf_member_attributes,
 &sxaend_sfx_tgcf_member_flag,
 &sxaend_sfx_tgcf_payload_offset,
 &sxaend_sfx_imp_header,
 &sxaend_sfx_imp_directory_block,
 &sxaend_sfx_cazip_header,
 &sxaend_sfx_cazip_dcl_prefix,
 &sxaend_sfx_starkit_header,
 &sxaend_sfx_starkit_commit,
 &sxaend_sfx_starkit_root_prefix,
 &sxaend_sfx_spis_header,
 &sxaend_sfx_spis_member,
 &sxaend_pfx_gemdos_header,
 &sxaend_pfx_lha_member,
 &sxaend_pfx_lha_crc,
 &sxaend_sfx_zip_local,
 &sxaend_sfx_zip_extra,
 &sxaend_localzip_softpaq_table,
 &sxaend_localzip_softpaq_member,
 &sxaend_rsfx_rar_signature,
 &sxaend_rsfx_rar_block,
 &sxaend_rsfx_rar_main,
 &sxaend_rsfx_rar_file,
 &sxaend_rsfx_rar_service_size,
};
static bool sx_archiveend_comment(xx_data_struct_record*r,uint32_t id){
 if(!r||!r->name||id<0x60840000U||id>=0x60850000U)return true;const wchar_t*text=NULL;switch(id){
 case 0x60840003U:text=L"Checksum is the low 16 bits of the sum of decoded bytes. A zero first name byte marks the final 30-byte record.";break;
 case 0x60840004U:text=L"First member offset = 128 + 4*archive_offset_longs, relative to the carrier start.";break;
 case 0x60840005U:text=L"Header checksum makes the sum of all big-endian header words zero. Name/comment lengths are four-byte units. Block displacement is relative to this header; zero is the final archive block.";break;
 case 0x60840006U:text=L"Continuation header is 20 bytes. Next displacement is relative to this block; zero marks the final archive block.";break;
 case 0x60840007U:text=L"0xFFFFFFFF ends the archive; otherwise followed by a 60-byte member header.";break;
 case 0x60840009U:text=L"Mode 1 has a length-prefixed archive comment before members.";break;
 case 0x6084000bU:text=L"Zero terminates the archive.";break;
 case 0x6084000dU:text=L"Physical two-byte trailer; native reader does not interpret it.";break;
 case 0x6084000eU:text=L"CRC32 uses the native raw initial-zero convention. Other member payloads are stored bytes.";break;
 case 0x6084000fU:text=L"Data-file v1.00 exit instructions and compressed-stream CRC16/ARC. Native reports but does not enforce the stored CRC.";break;
 case 0x60840012U:text=L"Packed length=((first&15)<<16)|packed_size_low. Plain length=((uncompressed_size_high>>2)<<16)|uncompressed_size_low. High first nibble is flags; 0x80 continuation is outside native scope.";break;
 case 0x60840013U:text=L"Mode 0=fixed literals, 1=coded literals. Dictionary selector 4/5/6 means 1/2/4 KiB. The authenticated native decoder determines each stream end.";break;
 case 0x60840014U:text=L"TX body size excludes the first ten bytes. Native supports six- and eight-byte screen directory rows.";break;
 case 0x60840015U:text=L"Zero marker means a decoded byte symbol; 0x0A ends a display line.";break;
 case 0x60840016U:text=L"One-based node indices; the last node is the Huffman root.";break;
 case 0x60840017U:text=L"Offset is relative to the TX compressed line-data area.";break;
 case 0x60840018U:text=L"Offset is relative to the TX compressed line-data area.";break;
 case 0x60840019U:text=L"Three equal nonzero producer geometry words; their screen-unit meaning is not assumed.";break;
 case 0x6084001aU:text=L"Total stored line size includes this one-byte prefix; following bits encode display characters and controls.";break;
 case 0x6084001bU:text=L"Norton Secret Stuff stores encrypted member bodies, in eight-byte blocks. Compression 0=stored, nonzero=compressed. Only serialized header fields are shown; ciphertext remains raw.";break;
 case 0x6084001eU:text=L"Node/map offsets are relative to this context header. Map entries select contexts; zero map_offset uses context zero.";break;
 case 0x6084001fU:text=L"Leaf flags for the Huffman node slots; bit index is the node index.";break;
 case 0x60840020U:text=L"A leaf slot holds a symbol; a branch slot holds child index/2; zero branch child is an end code.";break;
 case 0x60840021U:text=L"Context index selected after decoding the corresponding symbol.";break;
 case 0x60840027U:text=L"Total header size=first byte+2. Header checksum is byte sum from method through header end modulo256. DOS date/time is packed, not Unix seconds.";break;
 case 0x6084002bU:text=L"Six-bit characters encode decoded bytes. Tilde followed by an encoded count expands a zero run; no decoded-byte coordinates are invented.";break;
 case 0x6084002cU:text=L"Physical arcv2 header inside the authenticated carrier. Offsets retain the inner archive coordinate system. Encoded payload and unmodeled optional tables remain raw.";break;
 case 0x6084002dU:text=L"Physical arcv2 block inside the authenticated carrier. Offsets retain the inner archive coordinate system. Encoded payload and unmodeled optional tables remain raw.";break;
 case 0x6084002eU:text=L"Physical arcv2 attributes inside the authenticated carrier. Offsets retain the inner archive coordinate system. Encoded payload and unmodeled optional tables remain raw.";break;
 case 0x6084002fU:text=L"Physical tgcf header inside the authenticated carrier. Offsets retain the inner archive coordinate system. Encoded payload and unmodeled optional tables remain raw.";break;
 case 0x60840030U:text=L"Physical tgcf list offset inside the authenticated carrier. Offsets retain the inner archive coordinate system. Encoded payload and unmodeled optional tables remain raw.";break;
 case 0x60840031U:text=L"Physical tgcf crc inside the authenticated carrier. Offsets retain the inner archive coordinate system. Encoded payload and unmodeled optional tables remain raw.";break;
 case 0x60840032U:text=L"Physical tgcf member prefix inside the authenticated carrier. Offsets retain the inner archive coordinate system. Encoded payload and unmodeled optional tables remain raw.";break;
 case 0x60840033U:text=L"Physical tgcf member attributes inside the authenticated carrier. Offsets retain the inner archive coordinate system. Encoded payload and unmodeled optional tables remain raw.";break;
 case 0x60840034U:text=L"Physical tgcf member flag inside the authenticated carrier. Offsets retain the inner archive coordinate system. Encoded payload and unmodeled optional tables remain raw.";break;
 case 0x60840035U:text=L"Physical tgcf payload offset inside the authenticated carrier. Offsets retain the inner archive coordinate system. Encoded payload and unmodeled optional tables remain raw.";break;
 case 0x60840036U:text=L"Physical imp header inside the authenticated carrier. Offsets retain the inner archive coordinate system. Encoded payload and unmodeled optional tables remain raw.";break;
 case 0x60840037U:text=L"Physical imp directory block inside the authenticated carrier. Offsets retain the inner archive coordinate system. Encoded payload and unmodeled optional tables remain raw.";break;
 case 0x60840038U:text=L"Physical cazip header inside the authenticated carrier. Offsets retain the inner archive coordinate system. Encoded payload and unmodeled optional tables remain raw.";break;
 case 0x60840039U:text=L"Physical cazip dcl prefix inside the authenticated carrier. Offsets retain the inner archive coordinate system. Encoded payload and unmodeled optional tables remain raw.";break;
 case 0x6084003aU:text=L"Physical starkit header inside the authenticated carrier. Offsets retain the inner archive coordinate system. Encoded payload and unmodeled optional tables remain raw.";break;
 case 0x6084003bU:text=L"Physical starkit commit inside the authenticated carrier. Offsets retain the inner archive coordinate system. Encoded payload and unmodeled optional tables remain raw.";break;
 case 0x6084003cU:text=L"Physical starkit root prefix inside the authenticated carrier. Offsets retain the inner archive coordinate system. Encoded payload and unmodeled optional tables remain raw.";break;
 case 0x6084003dU:text=L"Physical spis header inside the authenticated carrier. Offsets retain the inner archive coordinate system. Encoded payload and unmodeled optional tables remain raw.";break;
 case 0x6084003eU:text=L"Physical spis member inside the authenticated carrier. Offsets retain the inner archive coordinate system. Encoded payload and unmodeled optional tables remain raw.";break;
 case 0x6084003fU:text=L"GEMDOS sizes are bytes. Physical archive starts at 28+text_size and is bounded by data_size.";break;
 case 0x60840040U:text=L"LArc PFX level0 LZ5/LH1 header. Stored packed length may exceed the authenticated DATA segment in known producer variants; its encoded value is preserved. DOS timestamp/attributes remain encoded.";break;
 case 0x60840041U:text=L"Known PFX LZ5 producer variants do not enforce the stored CRC; no checksum verification is implied by this field role.";break;
 case 0x60840043U:text=L"ZIP extra-field TLV header; unknown field payload remains raw.";break;
 case 0x60840044U:text=L"All three contiguous stored-member offsets are relative to the outer executable start.";break;
 case 0x60840047U:text=L"Original physical RAR1.5 header bytes are retained. The native extractor may repair known producer CRC/solid flags in its private decoded view only.";break;
 default:break;}
 return !text||xx_data_struct_record_set_comment(r,text);
}
#define SXAEND_LIMIT 20000U
bool sxaend_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
bool sxaend_read(sx_context*c,uint64_t p,void*b,size_t n){return sxaend_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
uint64_t sxaend_uint(const uint8_t*b,unsigned n,bool be){uint64_t v=0;for(unsigned i=0;i<n;i++)v|=(uint64_t)b[i]<<(8*(be?n-1-i:i));return v;}
bool sxaend_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v){uint8_t b[8];if(!n||n>8||!sxaend_read(c,p,b,n))return false;*v=sxaend_uint(b,n,be);return true;}
/* All coordinates are physical. Only documented byte aliases opt into overlap. */
static bool sxaend_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n,bool aliases){if(c->count>=SXAEND_LIMIT||xx_pd_is_stopped(c->pd))return false;if(!n){const xx_data_struct_field_desc*f=&l->fields[l->field_count-1];if(!f->size)return false;n=(uint64_t)(f->rel_offset+f->size);}if(!sxaend_span(c,p,n))return false;int64_t a=c->f->base_address+(int64_t)p;size_t lo=0,hi=c->count;while(lo<hi){size_t m=lo+(hi-lo)/2;if(c->items[m].offset<a)lo=m+1;else hi=m;}if(!aliases&&((lo<c->count&&c->items[lo].offset<a+(int64_t)n)||(lo&&c->items[lo-1].offset+c->items[lo-1].total_size>a)))return true;size_t old=c->count;if(!sx_add(c,l,(int64_t)p,(int64_t)n))return false;xx_data_struct row=c->items[old];xx_rt_memmove(c->items+lo+1,c->items+lo,(old-lo)*sizeof(row));c->items[lo]=row;return true;}
bool sxaend_add(sx_context*c,const sx_layout*l,uint64_t p){return sxaend_put(c,l,p,0,false);}
bool sxaend_text(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n,bool aliases){int64_t max=sx_variable_field_limit(l->fields[l->field_count-1].type);return !n||n>(uint64_t)(max?max:4096)?true:sxaend_put(c,l,p,n,aliases);}
static int sxaend_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxaend_finish(sx_context*c){size_t n=c->count;int64_t end=0;for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p>end&&!sx_raw(c,end,p-end))return false;if(p+c->items[i].total_size>end)end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxaend_order);return !c->failed;}
bool sxaend_name(sx_context*c,uint64_t p,uint64_t n){return sxaend_text(c,&sxaend_archiveend_name,p,n,false);}
/* Consume only the original reader's authenticated first physical member. */
bool sxaend_first_source(sx_context*c,uint64_t*at,uint64_t*size){Abstractformat*f=c->f;if(!f->create_archive_records_reading||!f->get_current_archive_record||!f->free_archive_records_reading)return false;xx_archive_record_state*s=(f->create_archive_records_reading)(f,NULL,c->pd);if(!s)return false;const xx_archive_record*r=(f->get_current_archive_record)(f,s);bool ok=r&&r->data_offset>=f->base_address&&r->compressed_size>0;if(ok){*at=(uint64_t)(r->data_offset-f->base_address);*size=(uint64_t)r->compressed_size;ok=sxaend_span(c,*at,*size);}(f->free_archive_records_reading)(f,s);return ok;}
static bool sxaend_arcv2(sx_context*c,uint64_t p,uint64_t z){uint64_t end=p+z;if(z<14||!sxaend_add(c,&sxaend_sfx_arcv2_header,p))return false;p+=14;for(unsigned i=0;p<end&&i<SXAEND_LIMIT;i++){uint8_t h[17];if(end-p<17||!sxaend_read(c,p,h,17)||xx_rt_memcmp(h,"BLCK",4))return false;uint64_t hs=sxaend_uint(h+6,2,false),n=sxaend_uint(h+12,4,false);if(hs!=45U+h[16]||hs>end-p||n>end-p-hs||!sxaend_add(c,&sxaend_sfx_arcv2_block,p)||!sxaend_name(c,p+17,h[16])||!sxaend_add(c,&sxaend_sfx_arcv2_attributes,p+17+h[16]))return false;p+=hs+n;}return true;}
static bool sxaend_imp(sx_context*c,uint64_t base,uint64_t z){uint64_t rel,n;if(z<42||!sxaend_word(c,base+4,4,false,&rel)||!sxaend_word(c,base+8,4,false,&n)||rel>z||!sxaend_add(c,&sxaend_sfx_imp_header,base))return false;uint64_t p=base+rel,end=base+z;for(unsigned i=0;p<end&&i<SXAEND_LIMIT;i++){uint8_t h[12];if(end-p<12||!sxaend_read(c,p,h,12)||xx_rt_memcmp(h,"IMPDE\0",6)||!sxaend_add(c,&sxaend_sfx_imp_directory_block,p))return false;uint64_t bits=sxaend_uint(h+6,6,false),packed=(bits>>25)&0xfffff;if(packed<6||packed>end-p-6)return false;p+=6+packed;}return true;}
static bool sxaend_starkit(sx_context*c,uint64_t p,uint64_t z){uint64_t n,off;if(z<24||!sxaend_add(c,&sxaend_sfx_starkit_header,p)||!sxaend_add(c,&sxaend_sfx_starkit_commit,p+z-16)||!sxaend_word(c,p+z-8,4,true,&n)||!sxaend_word(c,p+z-4,4,true,&off))return false;n&=0x7fffffff;if(n<2||off>z||n>z-off)return true;uint8_t b[2];if(!sxaend_read(c,p+off,b,2)||b[0]!=128||!(b[1]&128))return true;if(!sxaend_add(c,&sxaend_sfx_starkit_root_prefix,p+off))return false;uint64_t len=b[1]&127;return len<=n-2?sxaend_text(c,&sxaend_archiveend_comment,p+off+2,len,false):true;}
static bool sxaend_zip_record(sx_context*c,uint64_t p,uint64_t z){uint8_t h[30];if(z<30||!sxaend_read(c,p,h,30)||xx_rt_memcmp(h,"PK\3\4",4))return false;uint64_t n=sxaend_uint(h+26,2,false),extra=sxaend_uint(h+28,2,false);if(n>z-30||extra>z-30-n||!sxaend_add(c,&sxaend_sfx_zip_local,p)||!sxaend_name(c,p+30,n))return false;uint64_t q=p+30+n,end=q+extra;while(q+4<=end){uint64_t a;if(!sxaend_word(c,q+2,2,false,&a)||a>end-q-4)break;if(!sxaend_add(c,&sxaend_sfx_zip_extra,q))return false;q+=4+a;}return true;}
static bool sxaend_tgcf_record(sx_context*c,uint64_t p,uint64_t z){uint8_t h[36];if(z<43||!sxaend_read(c,p,h,36)||xx_rt_memcmp(h,"TGCF",4)||!sxaend_add(c,&sxaend_sfx_tgcf_member_prefix,p)||!sxaend_add(c,&sxaend_sfx_tgcf_member_attributes,p+16))return false;uint64_t q=p+36,end=p+z;for(unsigned n=0;n<2;n++){uint64_t start=q;uint8_t ch;while(q<end){if(!sxaend_read(c,q++,&ch,1))return false;if(!ch)break;}if(q==end||!sxaend_name(c,start,q-start))return false;}if(end-q!=5&&end-q!=9)return false;if(!sxaend_add(c,&sxaend_sfx_tgcf_member_flag,q++))return false;if(end-q==8){if(!sxaend_add(c,&sxaend_sfx_tgcf_payload_offset,q))return false;q+=4;}return sxaend_add(c,&sxaend_sfx_tgcf_crc,q);}
#if SX_ALIAS_READER_FACTORY
#include "xxfclib/formats/archive/sfx_tgcf/xx_sfx_tgcf.h"
#endif
static bool sxaend_tgcf_header(sx_context*c,uint64_t first){
#if SX_ALIAS_READER_FACTORY
 int64_t at,z;if(!xx_sfx_tgcf_get_payload_span(c->f,&at,&z,c->pd)||at<c->f->base_address||z<28)return true;
 uint64_t p=(uint64_t)(at-c->f->base_address),end=p+(uint64_t)z;uint8_t h[28];
 if(!sxaend_span(c,p,(uint64_t)z)||!sxaend_read(c,p,h,28)||xx_rt_memcmp(h,"TGCF",4))return true;
 uint64_t ver=sxaend_uint(h+6,2,true),n=sxaend_uint(h+26,2,true),list,q=p+28+n;
 if((ver!=0x130&&ver!=0x140&&ver!=0x160)||!n||n>1024||q>end||(ver>=0x160?8U:4U)>end-q)return true;
 if(ver>=0x160){if(!sxaend_word(c,q,4,true,&list)||list>(uint64_t)z||p+list!=first)return true;}else if(q+4!=first)return true;
 if(!sxaend_add(c,&sxaend_sfx_tgcf_header,p)||!sxaend_name(c,p+28,n))return false;
 if(ver>=0x160){if(!sxaend_add(c,&sxaend_sfx_tgcf_list_offset,q))return false;q+=4;}
 return sxaend_add(c,&sxaend_sfx_tgcf_crc,q);
#else
 (void)c;(void)first;return true;
#endif
}
bool sxaend_carrier_records(sx_context*c){Abstractformat*f=c->f;if(!f->create_archive_records_reading||!f->get_current_archive_record||!f->archive_record_move_to_next||!f->free_archive_records_reading)return false;xx_archive_record_state*s=(f->create_archive_records_reading)(f,NULL,c->pd);if(!s)return false;bool ok=true;for(unsigned i=0;i<SXAEND_LIMIT&&!xx_pd_is_stopped(c->pd);i++){const xx_archive_record*r=(f->get_current_archive_record)(f,s);if(!r)break;uint64_t p=0,z=0;bool header=r->header_offset>=f->base_address&&r->header_size>0;if(header){p=(uint64_t)(r->header_offset-f->base_address);z=(uint64_t)r->header_size;header=sxaend_span(c,p,z);}switch(f->file_type){case XX_FILE_TYPE_SFX_ARCV2:case XX_FILE_TYPE_SFX_IMP:case XX_FILE_TYPE_SFX_CAZIP:case XX_FILE_TYPE_SFX_STARKIT:if(r->data_offset<f->base_address||r->compressed_size<=0){ok=false;break;}p=(uint64_t)(r->data_offset-f->base_address);z=(uint64_t)r->compressed_size;if(!sxaend_span(c,p,z)){ok=false;break;}ok=f->file_type==XX_FILE_TYPE_SFX_ARCV2?sxaend_arcv2(c,p,z):f->file_type==XX_FILE_TYPE_SFX_IMP?sxaend_imp(c,p,z):f->file_type==XX_FILE_TYPE_SFX_STARKIT?sxaend_starkit(c,p,z):z>=24&&sxaend_add(c,&sxaend_sfx_cazip_header,p)&&sxaend_add(c,&sxaend_sfx_cazip_dcl_prefix,p+20);break;
 case XX_FILE_TYPE_SFX_TGCF:if(header){if(!i)ok=sxaend_tgcf_header(c,p);if(ok)ok=sxaend_tgcf_record(c,p,z);}break;
 case XX_FILE_TYPE_SFX_SPIS:if(!i){uint64_t start=0;bool candidate=false;if(header&&p>=21){start=p-21;candidate=true;}else if(!header&&r->data_offset>=f->base_address&&r->compressed_size>=21){start=(uint64_t)(r->data_offset-f->base_address);candidate=sxaend_span(c,start,(uint64_t)r->compressed_size);}if(candidate){uint8_t blob[21];if(sxaend_read(c,start,blob,21)&&!xx_rt_memcmp(blob,"SPIS\032",5)&&blob[12]==1&&!sxaend_add(c,&sxaend_sfx_spis_header,start)){ok=false;break;}}}if(header){uint8_t h[25];if(z==21&&sxaend_read(c,p,h,5)&&!xx_rt_memcmp(h,"SPIS\032",5))ok=sxaend_add(c,&sxaend_sfx_spis_header,p);else if(z>=25&&sxaend_read(c,p,h,25)&&sxaend_uint(h,2,false)==z-25)ok=sxaend_add(c,&sxaend_sfx_spis_member,p)&&sxaend_name(c,p+25,z-25);}break;
 case XX_FILE_TYPE_SFX_LOCALZIP:if(header){uint8_t h[4];if(z>=30&&sxaend_read(c,p,h,4)&&!xx_rt_memcmp(h,"PK\3\4",4))ok=sxaend_zip_record(c,p,z);else if(z>=2){uint64_t n;if(sxaend_word(c,p,1,false,&n)&&n==z-1)ok=sxaend_add(c,&sxaend_localzip_softpaq_member,p)&&sxaend_name(c,p+1,n);}}break;
 case XX_FILE_TYPE_LARC_PFX:if(header){uint8_t h[22];if(z<24||!sxaend_read(c,p,h,22)||h[0]+2!=z||h[21]>z-24){ok=false;break;}ok=sxaend_add(c,&sxaend_pfx_lha_member,p)&&sxaend_name(c,p+22,h[21])&&sxaend_add(c,&sxaend_pfx_lha_crc,p+22+h[21]);}break;default:ok=false;break;}if(!ok||!(f->archive_record_move_to_next)(f,s,c->pd))break;}(f->free_archive_records_reading)(f,s);return ok;}
static bool sx_archiveend_supports(xx_file_type_t t){switch(t){case XX_FILE_TYPE_SDS_SFX:case XX_FILE_TYPE_LHPAK_SFX:case XX_FILE_TYPE_LHSFX:case XX_FILE_TYPE_S_OMNI:case XX_FILE_TYPE_PMARC_SFX:case XX_FILE_TYPE_SFX_VMS_DCX:case XX_FILE_TYPE_SFX_NSS:case XX_FILE_TYPE_COPYQMEXE:case XX_FILE_TYPE_DCLRAW:case XX_FILE_TYPE_DIET_COMPRESSION:case XX_FILE_TYPE_BOO:case XX_FILE_TYPE_SFX_ARCV2:case XX_FILE_TYPE_SFX_IMP:case XX_FILE_TYPE_SFX_CAZIP:case XX_FILE_TYPE_SFX_STARKIT:case XX_FILE_TYPE_SFX_TGCF:case XX_FILE_TYPE_SFX_SPIS:case XX_FILE_TYPE_LARC_PFX:case XX_FILE_TYPE_SFX_LOCALZIP:case XX_FILE_TYPE_SFX_RSFX:return true;default:return false;}}
static bool sx_archiveend_build(sx_context*c){if((!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;switch(c->f->file_type){case XX_FILE_TYPE_SDS_SFX:ok=sx_sds_sfx_build(c);break;case XX_FILE_TYPE_LHPAK_SFX:ok=sx_lhpak_sfx_build(c);break;case XX_FILE_TYPE_LHSFX:ok=sx_lhsfx_build(c);break;case XX_FILE_TYPE_S_OMNI:ok=sx_s_omni_build(c);break;case XX_FILE_TYPE_PMARC_SFX:ok=sx_pmarc_sfx_build(c);break;case XX_FILE_TYPE_SFX_VMS_DCX:ok=sx_sfx_vms_dcx_build(c);break;case XX_FILE_TYPE_SFX_NSS:ok=sx_sfx_nss_build(c);break;case XX_FILE_TYPE_COPYQMEXE:ok=sx_copyqmexe_build(c);break;case XX_FILE_TYPE_DCLRAW:ok=sx_dclraw_build(c);break;case XX_FILE_TYPE_DIET_COMPRESSION:ok=sx_diet_compression_build(c);break;case XX_FILE_TYPE_BOO:ok=sx_boo_build(c);break;case XX_FILE_TYPE_SFX_ARCV2:ok=sx_sfx_arcv2_build(c);break;case XX_FILE_TYPE_SFX_IMP:ok=sx_sfx_imp_build(c);break;case XX_FILE_TYPE_SFX_CAZIP:ok=sx_sfx_cazip_build(c);break;case XX_FILE_TYPE_SFX_STARKIT:ok=sx_sfx_starkit_build(c);break;case XX_FILE_TYPE_SFX_TGCF:ok=sx_sfx_tgcf_build(c);break;case XX_FILE_TYPE_SFX_SPIS:ok=sx_sfx_spis_build(c);break;case XX_FILE_TYPE_LARC_PFX:ok=sx_larc_pfx_build(c);break;case XX_FILE_TYPE_SFX_LOCALZIP:ok=sx_sfx_localzip_build(c);break;case XX_FILE_TYPE_SFX_RSFX:ok=sx_sfx_rsfx_build(c);break;default:return false;}(void)ok;/* Partial bounded metadata survives optional damaged records/display caps. */return c->count&&sxaend_finish(c);}
const sx_family sx_archiveend_family={sx_archiveend_supports,sx_archiveend_build,sx_archiveend_layouts,SX_COUNT(sx_archiveend_layouts),sx_archiveend_comment};
