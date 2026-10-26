/* SPDX-License-Identifier: MIT
 * Bounded physical game container records; transformed payloads stay raw. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_gameremaining.h"
static const xx_data_struct_field_desc sxgr_ycg_header_fields[]={
 SX_FIELD("signature","uint32le",0,4,SX_SIGNATURE),
 SX_FIELD("width","uint32le",4,4,SX_NONE),
 SX_FIELD("height","uint32le",8,4,SX_NONE),
 SX_FIELD("bits_per_pixel","int32le",12,4,SX_NONE),
 SX_FIELD("compression_method","int32le",16,4,SX_ID),
 SX_FIELD("unknown_14","uint8[12]",20,12,SX_NONE),
 SX_FIELD("uncompressed_size_1","int32le",32,4,SX_SIZE),
 SX_FIELD("compressed_size_1","int32le",36,4,SX_SIZE),
 SX_FIELD("unknown_28","uint8[8]",40,8,SX_NONE),
 SX_FIELD("uncompressed_size_2","int32le",48,4,SX_SIZE),
 SX_FIELD("compressed_size_2","int32le",52,4,SX_SIZE),
};
const sx_layout sxgr_ycg_header={0x607e0004U,"ycg_header",sxgr_ycg_header_fields,SX_COUNT(sxgr_ycg_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgr_fallout2_entry_fields[]={
 SX_FIELD("compression_method","uint8",0,1,SX_ID),
 SX_FIELD("uncompressed_size","int32le",1,4,SX_SIZE),
 SX_FIELD("compressed_size","int32le",5,4,SX_SIZE),
 SX_FIELD("file_offset","int32le",9,4,SX_OFFSET),
};
const sx_layout sxgr_fallout2_entry={0x607e000aU,"fallout2_entry",sxgr_fallout2_entry_fields,SX_COUNT(sxgr_fallout2_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgr_unreal_pak_entry_v1_fields[]={
 SX_FIELD("file_offset","uint64le",0,8,SX_OFFSET),
 SX_FIELD("compressed_size","uint64le",8,8,SX_SIZE),
 SX_FIELD("uncompressed_size","uint64le",16,8,SX_SIZE),
 SX_FIELD("compression_method","uint32le",24,4,SX_ID),
 SX_FIELD("timestamp","uint64le",28,8,SX_NONE),
 SX_FIELD("sha1","uint8[20]",36,20,SX_CHECKSUM),
};
const sx_layout sxgr_unreal_pak_entry_v1={0x607e0011U,"unreal_pak_entry_v1",sxgr_unreal_pak_entry_v1_fields,SX_COUNT(sxgr_unreal_pak_entry_v1_fields),SX_LE};
static const xx_data_struct_field_desc sxgr_unreal_pak_entry_v2_fields[]={
 SX_FIELD("file_offset","uint64le",0,8,SX_OFFSET),
 SX_FIELD("compressed_size","uint64le",8,8,SX_SIZE),
 SX_FIELD("uncompressed_size","uint64le",16,8,SX_SIZE),
 SX_FIELD("compression_method","uint32le",24,4,SX_ID),
 SX_FIELD("sha1","uint8[20]",28,20,SX_CHECKSUM),
};
const sx_layout sxgr_unreal_pak_entry_v2={0x607e0012U,"unreal_pak_entry_v2",sxgr_unreal_pak_entry_v2_fields,SX_COUNT(sxgr_unreal_pak_entry_v2_fields),SX_LE};
static const xx_data_struct_field_desc sxgr_unreal_pak_entry_flags_fields[]={
 SX_FIELD("flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("uncompressed_block_size","uint32le",1,4,SX_SIZE),
};
const sx_layout sxgr_unreal_pak_entry_flags={0x607e0015U,"unreal_pak_entry_flags",sxgr_unreal_pak_entry_flags_fields,SX_COUNT(sxgr_unreal_pak_entry_flags_fields),SX_LE};
static const xx_data_struct_field_desc sxgr_gal_header_fields[]={
 SX_FIELD("format_version","int32le",0,4,SX_NONE),
 SX_FIELD("width","uint32le",4,4,SX_NONE),
 SX_FIELD("height","uint32le",8,4,SX_NONE),
 SX_FIELD("bits_per_pixel","int32le",12,4,SX_NONE),
 SX_FIELD("frame_count","int32le",16,4,SX_COUNT_PROP),
 SX_FIELD("unknown_14","uint8",20,1,SX_NONE),
 SX_FIELD("shuffled","uint8",21,1,SX_FLAGS),
 SX_FIELD("compression_method","uint8",22,1,SX_ID),
 SX_FIELD("unknown_17","uint8",23,1,SX_NONE),
 SX_FIELD("mask","uint32le",24,4,SX_FLAGS),
 SX_FIELD("block_width","int32le",28,4,SX_NONE),
 SX_FIELD("block_height","int32le",32,4,SX_NONE),
 SX_FIELD("unknown_24","uint8[4]",36,4,SX_NONE),
};
const sx_layout sxgr_gal_header={0x607e0017U,"gal_header",sxgr_gal_header_fields,SX_COUNT(sxgr_gal_header_fields),SX_LE};
static const sx_layout*const sx_gameremaining_layouts[]={&sxgr_bruns_een_header,&sxgr_rpgmv_header,&sxgr_smile_game_header,&sxgr_ycg_header,&sxgr_fallout2_footer,&sxgr_fallout2_directory,&sxgr_fallout2_name_length,&sxgr_game_name_length,&sxgr_game_name,&sxgr_fallout2_entry,&sxgr_unreal_pak_footer_v1,&sxgr_unreal_pak_footer_v4,&sxgr_unreal_pak_footer_v7,&sxgr_unreal_pak_string_length,&sxgr_unreal_pak_string,&sxgr_unreal_pak_directory_count,&sxgr_unreal_pak_entry_v1,&sxgr_unreal_pak_entry_v2,&sxgr_unreal_pak_block_count,&sxgr_unreal_pak_block,&sxgr_unreal_pak_entry_flags,&sxgr_gal_envelope,&sxgr_gal_header,&sxgr_gal_frame,&sxgr_gal_palette_entry,&sxgr_gal_layer,&sxgr_gal_layer_lock,&sxgr_gal_layer_size,&sxgr_gal_alpha_size};
static bool sx_gameremaining_comment(xx_data_struct_record*r,uint32_t id)
{if(!r||!r->name||id<0x607e0000U||id>=0x607f0000U)return true;
 if(!xx_rt_wcscmp(r->name,L"encoded_xor_seed"))return xx_data_struct_record_set_comment(r,L"Stored seed; the payload XOR key is this word XOR 0xDEADBEEF.");
 if(!xx_rt_wcscmp(r->name,L"signed_character_count"))return xx_data_struct_record_set_comment(r,L"Includes the terminator: positive is single-byte characters; negative is the number of UTF-16LE code units with reversed sign.");
 if(!xx_rt_wcscmp(r->name,L"index_sha1"))return xx_data_struct_record_set_comment(r,L"SHA-1 digest of the stored index; this view displays the digest without verifying it.");
 if(!xx_rt_wcscmp(r->name,L"sha1"))return xx_data_struct_record_set_comment(r,L"Stored SHA-1 digest for this entry; this view does not verify payload hashes.");
 if(!xx_rt_wcscmp(r->name,L"start_offset")||!xx_rt_wcscmp(r->name,L"end_offset"))return xx_data_struct_record_set_comment(r,L"Compression block boundary: absolute before PAK version 5, relative to the entry header from version 5 onward.");
 if(!xx_rt_wcscmp(r->name,L"file_offset")&&(id==sxgr_unreal_pak_entry_v1.id||id==sxgr_unreal_pak_entry_v2.id))return xx_data_struct_record_set_comment(r,L"Index entry: physical offset of its duplicate local header. A local header stores zero here.");
 if(!xx_rt_wcscmp(r->name,L"index_offset"))return xx_data_struct_record_set_comment(r,L"Physical byte offset from the beginning of this PAK file.");
 if(!xx_rt_wcscmp(r->name,L"file_offset"))return xx_data_struct_record_set_comment(r,L"Physical byte offset from the beginning of this DAT file.");
 if(!xx_rt_wcscmp(r->name,L"flags")&&id==sxgr_unreal_pak_entry_flags.id)return xx_data_struct_record_set_comment(r,L"Bit 0: encrypted; bit 1: deleted. Unknown bits are preserved.");
 if(!xx_rt_wcscmp(r->name,L"compression_method")){
  if(r->value.type==XX_VAR_TYPE_FLOAT||r->value.type==XX_VAR_TYPE_DOUBLE)return true;
  uint64_t n=xx_var_get_u64(&r->value);
  if(id==sxgr_gal_header.id)return xx_data_struct_record_set_comment(r,n==0?L"ZLIB":n==1?L"STORED_BLOCKS":n==2?L"JPEG":L"Unknown compression method");
  if(id==sxgr_ycg_header.id)return xx_data_struct_record_set_comment(r,n==1?L"Two ZLIB streams":L"Unknown compression method");
  if(id==sxgr_fallout2_entry.id)return xx_data_struct_record_set_comment(r,n==0?L"STORED":n==1?L"ZLIB":L"Unknown compression method");
  if(id==sxgr_unreal_pak_entry_v1.id||id==sxgr_unreal_pak_entry_v2.id)return xx_data_struct_record_set_comment(r,n==0?L"STORED":n==1?L"ZLIB":n==2?L"GZIP":L"Unknown compression method");
 }
 return true;}
#define GR_ROW(name,at,end) sxgr_row(v,&sxgr_##name,(at),(end))
static bool sx_gameremaining_supports(xx_file_type_t type){switch(type){case XX_FILE_TYPE_BRUNS_MEDIA:case XX_FILE_TYPE_RPG_MAKER_MV:case XX_FILE_TYPE_YCG_IMAGE:case XX_FILE_TYPE_UNREAL_PAK:case XX_FILE_TYPE_FALLOUT_DAT:case XX_FILE_TYPE_LIVE_MAKER_GAL:case XX_FILE_TYPE_SMILE_GAME_PACK:return true;default:return false;}}
static bool sx_gameremaining_build(sx_context*c)
{if(!c||!c->f||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid||c->size<=0)return false;return sx_ue2_games_build(c);}
#undef GR_ROW
const sx_family sx_gameremaining_family={sx_gameremaining_supports,sx_gameremaining_build,sx_gameremaining_layouts,SX_COUNT(sx_gameremaining_layouts),sx_gameremaining_comment};
