/* SPDX-License-Identifier: MIT
 * Physical binary-font metadata. See docs/data_struct_fontbinary_scope.txt. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_fontbinary.h"
static const xx_data_struct_field_desc sxfb_nintendo_font_header_be_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("byte_order","uint16",4,2,SX_ID),
    SX_FIELD("header_size","uint16",6,2,SX_SIZE),
    SX_FIELD("version","uint32",8,4,SX_ID),
    SX_FIELD("file_size","uint32",12,4,SX_SIZE),
    SX_FIELD("block_count","uint32",16,4,SX_COUNT_PROP),
};
static const sx_layout sxfb_nintendo_font_header_be = {UINT32_C(0x60190001),"nintendo_font_header_be",sxfb_nintendo_font_header_be_fields,SX_COUNT(sxfb_nintendo_font_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_nintendo_font_chunk_be_fields[] = {
    SX_FIELD("block_id","char[4]",0,4,SX_ID),
    SX_FIELD("block_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxfb_nintendo_font_chunk_be = {UINT32_C(0x60190002),"nintendo_font_chunk_be",sxfb_nintendo_font_chunk_be_fields,SX_COUNT(sxfb_nintendo_font_chunk_be_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_bfnt_finf_fields[] = {
    SX_FIELD("font_type","uint8",0,1,SX_ID),
    SX_FIELD("height","uint8",1,1,SX_COUNT_PROP),
    SX_FIELD("width","uint8",2,1,SX_COUNT_PROP),
    SX_FIELD("ascent","uint8",3,1,SX_NONE),
    SX_FIELD("line_feed","uint16",4,2,SX_NONE),
    SX_FIELD("alternate_character_index","uint16",6,2,SX_ID),
    SX_FIELD("default_left","int8",8,1,SX_NONE),
    SX_FIELD("default_glyph_width","uint8",9,1,SX_COUNT_PROP),
    SX_FIELD("default_character_width","uint8",10,1,SX_COUNT_PROP),
    SX_FIELD("encoding","uint8",11,1,SX_ID),
    SX_FIELD("texture_header_offset","uint32",12,4,SX_OFFSET),
    SX_FIELD("width_header_offset","uint32",16,4,SX_OFFSET),
    SX_FIELD("map_header_offset","uint32",20,4,SX_OFFSET),
};
static const sx_layout sxfb_bfnt_finf = {UINT32_C(0x60190003),"bfnt_finf",sxfb_bfnt_finf_fields,SX_COUNT(sxfb_bfnt_finf_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_bfnt_tglp_fields[] = {
    SX_FIELD("cell_width","uint8",0,1,SX_COUNT_PROP),
    SX_FIELD("cell_height","uint8",1,1,SX_COUNT_PROP),
    SX_FIELD("sheet_count","uint8",2,1,SX_COUNT_PROP),
    SX_FIELD("maximum_character_width","uint8",3,1,SX_COUNT_PROP),
    SX_FIELD("sheet_size","uint32",4,4,SX_SIZE),
    SX_FIELD("baseline_position","uint16",8,2,SX_NONE),
    SX_FIELD("sheet_format","uint16",10,2,SX_ID),
    SX_FIELD("sheet_columns","uint16",12,2,SX_COUNT_PROP),
    SX_FIELD("sheet_rows","uint16",14,2,SX_COUNT_PROP),
    SX_FIELD("sheet_width","uint16",16,2,SX_COUNT_PROP),
    SX_FIELD("sheet_height","uint16",18,2,SX_COUNT_PROP),
    SX_FIELD("sheet_data_offset","uint32",20,4,SX_OFFSET),
};
static const sx_layout sxfb_bfnt_tglp = {UINT32_C(0x60190004),"bfnt_tglp",sxfb_bfnt_tglp_fields,SX_COUNT(sxfb_bfnt_tglp_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_nintendo_cwdh_be_fields[] = {
    SX_FIELD("first_glyph","uint16",0,2,SX_ID),
    SX_FIELD("last_glyph","uint16",2,2,SX_ID),
    SX_FIELD("next_body_offset","uint32",4,4,SX_OFFSET),
};
static const sx_layout sxfb_nintendo_cwdh_be = {UINT32_C(0x60190005),"nintendo_cwdh_be",sxfb_nintendo_cwdh_be_fields,SX_COUNT(sxfb_nintendo_cwdh_be_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_nintendo_width_be_fields[] = {
    SX_FIELD("left_bearing","int8",0,1,SX_NONE),
    SX_FIELD("glyph_width","uint8",1,1,SX_COUNT_PROP),
    SX_FIELD("character_width","uint8",2,1,SX_COUNT_PROP),
};
static const sx_layout sxfb_nintendo_width_be = {UINT32_C(0x60190006),"nintendo_width_be",sxfb_nintendo_width_be_fields,SX_COUNT(sxfb_nintendo_width_be_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_nintendo_cmap_be_fields[] = {
    SX_FIELD("first_character","uint16",0,2,SX_ID),
    SX_FIELD("last_character","uint16",2,2,SX_ID),
    SX_FIELD("method","uint16",4,2,SX_ID),
    SX_FIELD("reserved","uint16",6,2,SX_RESERVED),
    SX_FIELD("next_body_offset","uint32",8,4,SX_OFFSET),
};
static const sx_layout sxfb_nintendo_cmap_be = {UINT32_C(0x60190007),"nintendo_cmap_be",sxfb_nintendo_cmap_be_fields,SX_COUNT(sxfb_nintendo_cmap_be_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_nintendo_map_index_be_fields[] = {
    SX_FIELD("glyph_index","uint16",0,2,SX_ID),
};
static const sx_layout sxfb_nintendo_map_index_be = {UINT32_C(0x60190008),"nintendo_map_index_be",sxfb_nintendo_map_index_be_fields,SX_COUNT(sxfb_nintendo_map_index_be_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_nintendo_map_count_be_fields[] = {
    SX_FIELD("pair_count","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxfb_nintendo_map_count_be = {UINT32_C(0x60190009),"nintendo_map_count_be",sxfb_nintendo_map_count_be_fields,SX_COUNT(sxfb_nintendo_map_count_be_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_nintendo_map_pair_be_fields[] = {
    SX_FIELD("character","uint16",0,2,SX_ID),
    SX_FIELD("glyph_index","uint16",2,2,SX_ID),
};
static const sx_layout sxfb_nintendo_map_pair_be = {UINT32_C(0x6019000a),"nintendo_map_pair_be",sxfb_nintendo_map_pair_be_fields,SX_COUNT(sxfb_nintendo_map_pair_be_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_nintendo_font_header_le_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("byte_order","uint16",4,2,SX_ID),
    SX_FIELD("header_size","uint16",6,2,SX_SIZE),
    SX_FIELD("version","uint32",8,4,SX_ID),
    SX_FIELD("file_size","uint32",12,4,SX_SIZE),
    SX_FIELD("block_count","uint32",16,4,SX_COUNT_PROP),
};
static const sx_layout sxfb_nintendo_font_header_le = {UINT32_C(0x6019000b),"nintendo_font_header_le",sxfb_nintendo_font_header_le_fields,SX_COUNT(sxfb_nintendo_font_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxfb_nintendo_font_chunk_le_fields[] = {
    SX_FIELD("block_id","char[4]",0,4,SX_ID),
    SX_FIELD("block_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxfb_nintendo_font_chunk_le = {UINT32_C(0x6019000c),"nintendo_font_chunk_le",sxfb_nintendo_font_chunk_le_fields,SX_COUNT(sxfb_nintendo_font_chunk_le_fields),SX_LE};
static const xx_data_struct_field_desc sxfb_bcfnt_finf_fields[] = {
    SX_FIELD("font_type","uint8",0,1,SX_ID),
    SX_FIELD("line_feed","uint8",1,1,SX_NONE),
    SX_FIELD("alternate_character_index","uint16",2,2,SX_ID),
    SX_FIELD("default_left","int8",4,1,SX_NONE),
    SX_FIELD("default_glyph_width","uint8",5,1,SX_COUNT_PROP),
    SX_FIELD("default_character_width","uint8",6,1,SX_COUNT_PROP),
    SX_FIELD("encoding","uint8",7,1,SX_ID),
    SX_FIELD("texture_header_offset","uint32",8,4,SX_OFFSET),
    SX_FIELD("width_header_offset","uint32",12,4,SX_OFFSET),
    SX_FIELD("map_header_offset","uint32",16,4,SX_OFFSET),
    SX_FIELD("height","uint8",20,1,SX_COUNT_PROP),
    SX_FIELD("width","uint8",21,1,SX_COUNT_PROP),
    SX_FIELD("ascent","uint8",22,1,SX_NONE),
    SX_FIELD("padding","uint8",23,1,SX_RESERVED),
};
static const sx_layout sxfb_bcfnt_finf = {UINT32_C(0x6019000d),"bcfnt_finf",sxfb_bcfnt_finf_fields,SX_COUNT(sxfb_bcfnt_finf_fields),SX_LE};
static const xx_data_struct_field_desc sxfb_bcfnt_tglp_fields[] = {
    SX_FIELD("cell_width","uint8",0,1,SX_COUNT_PROP),
    SX_FIELD("cell_height","uint8",1,1,SX_COUNT_PROP),
    SX_FIELD("baseline_position","uint8",2,1,SX_NONE),
    SX_FIELD("maximum_character_width","uint8",3,1,SX_COUNT_PROP),
    SX_FIELD("sheet_size","uint32",4,4,SX_SIZE),
    SX_FIELD("sheet_count","uint16",8,2,SX_COUNT_PROP),
    SX_FIELD("sheet_format","uint16",10,2,SX_ID),
    SX_FIELD("sheet_columns","uint16",12,2,SX_COUNT_PROP),
    SX_FIELD("sheet_rows","uint16",14,2,SX_COUNT_PROP),
    SX_FIELD("sheet_width","uint16",16,2,SX_COUNT_PROP),
    SX_FIELD("sheet_height","uint16",18,2,SX_COUNT_PROP),
    SX_FIELD("sheet_data_offset","uint32",20,4,SX_OFFSET),
};
static const sx_layout sxfb_bcfnt_tglp = {UINT32_C(0x6019000e),"bcfnt_tglp",sxfb_bcfnt_tglp_fields,SX_COUNT(sxfb_bcfnt_tglp_fields),SX_LE};
static const xx_data_struct_field_desc sxfb_nintendo_cwdh_le_fields[] = {
    SX_FIELD("first_glyph","uint16",0,2,SX_ID),
    SX_FIELD("last_glyph","uint16",2,2,SX_ID),
    SX_FIELD("next_body_offset","uint32",4,4,SX_OFFSET),
};
static const sx_layout sxfb_nintendo_cwdh_le = {UINT32_C(0x6019000f),"nintendo_cwdh_le",sxfb_nintendo_cwdh_le_fields,SX_COUNT(sxfb_nintendo_cwdh_le_fields),SX_LE};
static const xx_data_struct_field_desc sxfb_nintendo_width_le_fields[] = {
    SX_FIELD("left_bearing","int8",0,1,SX_NONE),
    SX_FIELD("glyph_width","uint8",1,1,SX_COUNT_PROP),
    SX_FIELD("character_width","uint8",2,1,SX_COUNT_PROP),
};
static const sx_layout sxfb_nintendo_width_le = {UINT32_C(0x60190010),"nintendo_width_le",sxfb_nintendo_width_le_fields,SX_COUNT(sxfb_nintendo_width_le_fields),SX_LE};
static const xx_data_struct_field_desc sxfb_nintendo_cmap_le_fields[] = {
    SX_FIELD("first_character","uint16",0,2,SX_ID),
    SX_FIELD("last_character","uint16",2,2,SX_ID),
    SX_FIELD("method","uint16",4,2,SX_ID),
    SX_FIELD("reserved","uint16",6,2,SX_RESERVED),
    SX_FIELD("next_body_offset","uint32",8,4,SX_OFFSET),
};
static const sx_layout sxfb_nintendo_cmap_le = {UINT32_C(0x60190011),"nintendo_cmap_le",sxfb_nintendo_cmap_le_fields,SX_COUNT(sxfb_nintendo_cmap_le_fields),SX_LE};
static const xx_data_struct_field_desc sxfb_nintendo_map_index_le_fields[] = {
    SX_FIELD("glyph_index","uint16",0,2,SX_ID),
};
static const sx_layout sxfb_nintendo_map_index_le = {UINT32_C(0x60190012),"nintendo_map_index_le",sxfb_nintendo_map_index_le_fields,SX_COUNT(sxfb_nintendo_map_index_le_fields),SX_LE};
static const xx_data_struct_field_desc sxfb_nintendo_map_count_le_fields[] = {
    SX_FIELD("pair_count","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxfb_nintendo_map_count_le = {UINT32_C(0x60190013),"nintendo_map_count_le",sxfb_nintendo_map_count_le_fields,SX_COUNT(sxfb_nintendo_map_count_le_fields),SX_LE};
static const xx_data_struct_field_desc sxfb_nintendo_map_pair_le_fields[] = {
    SX_FIELD("character","uint16",0,2,SX_ID),
    SX_FIELD("glyph_index","uint16",2,2,SX_ID),
};
static const sx_layout sxfb_nintendo_map_pair_le = {UINT32_C(0x60190014),"nintendo_map_pair_le",sxfb_nintendo_map_pair_le_fields,SX_COUNT(sxfb_nintendo_map_pair_le_fields),SX_LE};
static const xx_data_struct_field_desc sxfb_tex_font_preamble_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
    SX_FIELD("format_id","uint8",1,1,SX_ID),
    SX_FIELD("comment_length","uint8",2,1,SX_SIZE),
};
static const sx_layout sxfb_tex_font_preamble = {UINT32_C(0x6019002c),"tex_font_preamble",sxfb_tex_font_preamble_fields,SX_COUNT(sxfb_tex_font_preamble_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_tex_opcode_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
};
const sx_layout sxfb_tex_opcode = {UINT32_C(0x60190031),"tex_opcode",sxfb_tex_opcode_fields,SX_COUNT(sxfb_tex_opcode_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_tex_special1_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
    SX_FIELD("payload_size","uint8",1,1,SX_SIZE),
};
static const sx_layout sxfb_tex_special1 = {UINT32_C(0x60190032),"tex_special1",sxfb_tex_special1_fields,SX_COUNT(sxfb_tex_special1_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_tex_special2_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
    SX_FIELD("payload_size","uint16",1,2,SX_SIZE),
};
static const sx_layout sxfb_tex_special2 = {UINT32_C(0x60190033),"tex_special2",sxfb_tex_special2_fields,SX_COUNT(sxfb_tex_special2_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_tex_special3_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
    SX_FIELD("payload_size","uint24",1,3,SX_SIZE),
};
static const sx_layout sxfb_tex_special3 = {UINT32_C(0x60190034),"tex_special3",sxfb_tex_special3_fields,SX_COUNT(sxfb_tex_special3_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_tex_special4_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
    SX_FIELD("payload_size","int32",1,4,SX_SIZE),
};
static const sx_layout sxfb_tex_special4 = {UINT32_C(0x60190035),"tex_special4",sxfb_tex_special4_fields,SX_COUNT(sxfb_tex_special4_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_tex_numeric_special_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
    SX_FIELD("value","int32",1,4,SX_NONE),
};
const sx_layout sxfb_tex_numeric_special = {UINT32_C(0x60190036),"tex_numeric_special",sxfb_tex_numeric_special_fields,SX_COUNT(sxfb_tex_numeric_special_fields),SX_BE};
static const sx_layout *const sx_fontbinary_layouts[] = {
    &sxfb_nintendo_font_header_be,
    &sxfb_nintendo_font_chunk_be,
    &sxfb_bfnt_finf,
    &sxfb_bfnt_tglp,
    &sxfb_nintendo_cwdh_be,
    &sxfb_nintendo_width_be,
    &sxfb_nintendo_cmap_be,
    &sxfb_nintendo_map_index_be,
    &sxfb_nintendo_map_count_be,
    &sxfb_nintendo_map_pair_be,
    &sxfb_nintendo_font_header_le,
    &sxfb_nintendo_font_chunk_le,
    &sxfb_bcfnt_finf,
    &sxfb_bcfnt_tglp,
    &sxfb_nintendo_cwdh_le,
    &sxfb_nintendo_width_le,
    &sxfb_nintendo_cmap_le,
    &sxfb_nintendo_map_index_le,
    &sxfb_nintendo_map_count_le,
    &sxfb_nintendo_map_pair_le,
    &sxfb_windows_fnt2_header,
    &sxfb_windows_fnt3_header,
    &sxfb_windows_fnt2_glyph,
    &sxfb_windows_fnt3_glyph,
    &sxfb_gem_font_header_le,
    &sxfb_gem_glyph_bit_position_le,
    &sxfb_gem_font_header_be,
    &sxfb_gem_glyph_bit_position_be,
    &sxfb_gem_horizontal_offsets,
    &sxfb_tfm_counts,
    &sxfb_tfm_header,
    &sxfb_tfm_coding_scheme,
    &sxfb_tfm_family,
    &sxfb_tfm_face,
    &sxfb_tfm_character,
    &sxfb_tfm_width,
    &sxfb_tfm_height,
    &sxfb_tfm_depth,
    &sxfb_tfm_italic,
    &sxfb_tfm_kern,
    &sxfb_tfm_parameter,
    &sxfb_tfm_ligature_kern,
    &sxfb_tfm_extensible_recipe,
    &sxfb_tex_font_preamble,
    &sxfb_pk_metrics,
    &sxfb_pk_short_glyph,
    &sxfb_pk_extended_glyph,
    &sxfb_pk_long_glyph,
    &sxfb_tex_opcode,
    &sxfb_tex_special1,
    &sxfb_tex_special2,
    &sxfb_tex_special3,
    &sxfb_tex_special4,
    &sxfb_tex_numeric_special,
    &sxfb_gf_boc,
    &sxfb_gf_boc1,
    &sxfb_gf_paint1,
    &sxfb_gf_skip1,
    &sxfb_gf_paint2,
    &sxfb_gf_skip2,
    &sxfb_gf_paint3,
    &sxfb_gf_skip3,
    &sxfb_gf_post,
    &sxfb_gf_char_loc,
    &sxfb_gf_char_loc0,
    &sxfb_gf_postpost,
    &sxfb_vf_metrics,
    &sxfb_vf_font_definition1,
    &sxfb_vf_font_definition2,
    &sxfb_vf_font_definition3,
    &sxfb_vf_font_definition4,
    &sxfb_vf_short_packet,
    &sxfb_vf_long_packet,
};
static bool sx_fontbinary_comment(xx_data_struct_record *r,uint32_t id)
{
    if(!r||!r->name||id<0x60190000U||id>=0x601a0000U)return true;
    const wchar_t *text=NULL;switch(id){
    case 0x60190003U:
        if(!xx_rt_wcscmp(r->name,L"texture_header_offset"))text=L"File-relative byte offset to block body, eight bytes after its magic.";
        if(!xx_rt_wcscmp(r->name,L"width_header_offset"))text=L"File-relative byte offset to block body, eight bytes after its magic.";
        if(!xx_rt_wcscmp(r->name,L"map_header_offset"))text=L"File-relative byte offset to block body, eight bytes after its magic.";
        break;
    case 0x60190005U:
        if(!xx_rt_wcscmp(r->name,L"next_body_offset"))text=L"File-relative byte offset to next CWDH body; zero ends the chain.";
        break;
    case 0x60190007U:
        if(!xx_rt_wcscmp(r->name,L"method"))text=L"0=direct, 1=table, 2=scan pairs.";
        if(!xx_rt_wcscmp(r->name,L"next_body_offset"))text=L"File-relative byte offset to next CMAP body; zero ends the chain.";
        break;
    case 0x60190008U:
        if(!xx_rt_wcscmp(r->name,L"glyph_index"))text=L"Direct mapping start or indexed glyph; 65535 marks an absent indexed glyph.";
        break;
    case 0x6019000dU:
        if(!xx_rt_wcscmp(r->name,L"texture_header_offset"))text=L"File-relative byte offset to block body, eight bytes after its magic.";
        if(!xx_rt_wcscmp(r->name,L"width_header_offset"))text=L"File-relative byte offset to block body, eight bytes after its magic.";
        if(!xx_rt_wcscmp(r->name,L"map_header_offset"))text=L"File-relative byte offset to block body, eight bytes after its magic.";
        break;
    case 0x6019000fU:
        if(!xx_rt_wcscmp(r->name,L"next_body_offset"))text=L"File-relative byte offset to next CWDH body; zero ends the chain.";
        break;
    case 0x60190011U:
        if(!xx_rt_wcscmp(r->name,L"method"))text=L"0=direct, 1=table, 2=scan pairs.";
        if(!xx_rt_wcscmp(r->name,L"next_body_offset"))text=L"File-relative byte offset to next CMAP body; zero ends the chain.";
        break;
    case 0x60190012U:
        if(!xx_rt_wcscmp(r->name,L"glyph_index"))text=L"Direct mapping start or indexed glyph; 65535 marks an absent indexed glyph.";
        break;
    case 0x60190015U:
        if(!xx_rt_wcscmp(r->name,L"default_character_index"))text=L"Relative to first_character, not an absolute character code.";
        if(!xx_rt_wcscmp(r->name,L"break_character_index"))text=L"Relative to first_character, not an absolute character code.";
        if(!xx_rt_wcscmp(r->name,L"bits_pointer"))text=L"Runtime pointer word, normally zero in a disk font.";
        break;
    case 0x60190016U:
        if(!xx_rt_wcscmp(r->name,L"default_character_index"))text=L"Relative to first_character, not an absolute character code.";
        if(!xx_rt_wcscmp(r->name,L"break_character_index"))text=L"Relative to first_character, not an absolute character code.";
        if(!xx_rt_wcscmp(r->name,L"bits_pointer"))text=L"Runtime pointer word, normally zero in a disk font.";
        break;
    case 0x60190019U:
        if(!xx_rt_wcscmp(r->name,L"left_skew_offset"))text=L"Pixel displacement, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"right_skew_offset"))text=L"Pixel displacement, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"1=default, 2=horizontal table, 4=Motorola standard bitmap, 8=monospaced.";
        if(!xx_rt_wcscmp(r->name,L"next_font_pointer"))text=L"Runtime linked-font pointer; native standalone files require zero.";
        break;
    case 0x6019001aU:
        if(!xx_rt_wcscmp(r->name,L"bit_position"))text=L"Horizontal bit position in a raster row; not a byte offset.";
        break;
    case 0x6019001bU:
        if(!xx_rt_wcscmp(r->name,L"left_skew_offset"))text=L"Pixel displacement, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"right_skew_offset"))text=L"Pixel displacement, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"1=default, 2=horizontal table, 4=Motorola standard bitmap, 8=monospaced.";
        if(!xx_rt_wcscmp(r->name,L"next_font_pointer"))text=L"Runtime linked-font pointer; native standalone files require zero.";
        break;
    case 0x6019001cU:
        if(!xx_rt_wcscmp(r->name,L"bit_position"))text=L"Horizontal bit position in a raster row; not a byte offset.";
        break;
    case 0x6019001dU:
        if(!xx_rt_wcscmp(r->name,L"encoded_offsets"))text=L"Original two-byte horizontal offset entry; preserved without synthesizing metrics.";
        break;
    case 0x6019001eU:
        if(!xx_rt_wcscmp(r->name,L"file_words"))text=L"Total file length in four-byte words.";
        if(!xx_rt_wcscmp(r->name,L"header_words"))text=L"Header length in four-byte words.";
        break;
    case 0x6019001fU:
        if(!xx_rt_wcscmp(r->name,L"design_size"))text=L"Signed fixed-point points with 20 fractional bits.";
        break;
    case 0x60190023U:
        if(!xx_rt_wcscmp(r->name,L"height_depth_indexes"))text=L"High nibble=height table index; low nibble=depth table index.";
        if(!xx_rt_wcscmp(r->name,L"italic_index_and_tag"))text=L"High 6 bits=italic index; low 2 bits select remainder interpretation.";
        if(!xx_rt_wcscmp(r->name,L"remainder"))text=L"Tag 0=unused,1=ligature program,2=next character,3=extensible recipe.";
        break;
    case 0x60190024U:
        if(!xx_rt_wcscmp(r->name,L"value"))text=L"Signed fixed-point word with 20 fractional bits; units depend on the metric or parameter.";
        break;
    case 0x60190025U:
        if(!xx_rt_wcscmp(r->name,L"value"))text=L"Signed fixed-point word with 20 fractional bits; units depend on the metric or parameter.";
        break;
    case 0x60190026U:
        if(!xx_rt_wcscmp(r->name,L"value"))text=L"Signed fixed-point word with 20 fractional bits; units depend on the metric or parameter.";
        break;
    case 0x60190027U:
        if(!xx_rt_wcscmp(r->name,L"value"))text=L"Signed fixed-point word with 20 fractional bits; units depend on the metric or parameter.";
        break;
    case 0x60190028U:
        if(!xx_rt_wcscmp(r->name,L"value"))text=L"Signed fixed-point word with 20 fractional bits; units depend on the metric or parameter.";
        break;
    case 0x60190029U:
        if(!xx_rt_wcscmp(r->name,L"value"))text=L"Signed fixed-point word with 20 fractional bits; units depend on the metric or parameter.";
        break;
    case 0x6019002aU:
        if(!xx_rt_wcscmp(r->name,L"remainder"))text=L"Ligature operation or kern/restart index component, selected by skip and operation bytes.";
        break;
    case 0x6019002dU:
        if(!xx_rt_wcscmp(r->name,L"design_size"))text=L"Fixed-point points with 20 fractional bits.";
        if(!xx_rt_wcscmp(r->name,L"horizontal_pixels_per_point"))text=L"Fixed-point ratio with 16 fractional bits.";
        if(!xx_rt_wcscmp(r->name,L"vertical_pixels_per_point"))text=L"Fixed-point ratio with 16 fractional bits.";
        break;
    case 0x6019002eU:
        if(!xx_rt_wcscmp(r->name,L"packet_size_low"))text=L"Low packet-length bits; remaining bits are encoded in the low three flag bits.";
        if(!xx_rt_wcscmp(r->name,L"tfm_width"))text=L"Fixed-point width with 20 fractional bits.";
        if(!xx_rt_wcscmp(r->name,L"dx"))text=L"Pixel quantity, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"width_pixels"))text=L"Pixel quantity, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"height_pixels"))text=L"Pixel quantity, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"horizontal_offset"))text=L"Pixel quantity, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"vertical_offset"))text=L"Pixel quantity, not a file offset.";
        break;
    case 0x6019002fU:
        if(!xx_rt_wcscmp(r->name,L"packet_size_low"))text=L"Low packet-length bits; remaining bits are encoded in the low three flag bits.";
        if(!xx_rt_wcscmp(r->name,L"tfm_width"))text=L"Fixed-point width with 20 fractional bits.";
        if(!xx_rt_wcscmp(r->name,L"dx"))text=L"Pixel quantity, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"width_pixels"))text=L"Pixel quantity, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"height_pixels"))text=L"Pixel quantity, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"horizontal_offset"))text=L"Pixel quantity, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"vertical_offset"))text=L"Pixel quantity, not a file offset.";
        break;
    case 0x60190030U:
        if(!xx_rt_wcscmp(r->name,L"packet_size"))text=L"Byte count beginning at tfm_width, including metrics and raster.";
        if(!xx_rt_wcscmp(r->name,L"tfm_width"))text=L"Signed fixed-point width with 20 fractional bits.";
        if(!xx_rt_wcscmp(r->name,L"dx"))text=L"Pixel escapement with 16 fractional bits.";
        if(!xx_rt_wcscmp(r->name,L"dy"))text=L"Pixel escapement with 16 fractional bits.";
        if(!xx_rt_wcscmp(r->name,L"horizontal_offset"))text=L"Pixel displacement, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"vertical_offset"))text=L"Pixel displacement, not a file offset.";
        break;
    case 0x60190037U:
        if(!xx_rt_wcscmp(r->name,L"previous_boc_offset"))text=L"Relative file byte offset; -1 means no previous character packet.";
        break;
    case 0x6019003aU:
        if(!xx_rt_wcscmp(r->name,L"extra_rows"))text=L"Actual row advance is this value plus one.";
        break;
    case 0x6019003cU:
        if(!xx_rt_wcscmp(r->name,L"extra_rows"))text=L"Actual row advance is this value plus one.";
        break;
    case 0x6019003eU:
        if(!xx_rt_wcscmp(r->name,L"extra_rows"))text=L"Actual row advance is this value plus one.";
        break;
    case 0x6019003fU:
        if(!xx_rt_wcscmp(r->name,L"design_size"))text=L"Fixed-point points with 20 fractional bits.";
        if(!xx_rt_wcscmp(r->name,L"horizontal_pixels_per_point"))text=L"Fixed-point ratio with 16 fractional bits.";
        if(!xx_rt_wcscmp(r->name,L"vertical_pixels_per_point"))text=L"Fixed-point ratio with 16 fractional bits.";
        break;
    case 0x60190040U:
        if(!xx_rt_wcscmp(r->name,L"dx"))text=L"Pixel escapement with 16 fractional bits.";
        if(!xx_rt_wcscmp(r->name,L"dy"))text=L"Pixel escapement with 16 fractional bits.";
        if(!xx_rt_wcscmp(r->name,L"tfm_width"))text=L"Signed fixed-point width with 20 fractional bits.";
        if(!xx_rt_wcscmp(r->name,L"packet_offset"))text=L"File-relative byte offset; -1 means no packet.";
        break;
    case 0x60190041U:
        if(!xx_rt_wcscmp(r->name,L"dx"))text=L"Whole-pixel horizontal escapement.";
        if(!xx_rt_wcscmp(r->name,L"tfm_width"))text=L"Signed fixed-point width with 20 fractional bits.";
        if(!xx_rt_wcscmp(r->name,L"packet_offset"))text=L"File-relative byte offset; -1 means no packet.";
        break;
    case 0x60190043U:
        if(!xx_rt_wcscmp(r->name,L"design_size"))text=L"Fixed-point points with 20 fractional bits.";
        break;
    case 0x60190044U:
        if(!xx_rt_wcscmp(r->name,L"scale"))text=L"Fixed-point scale with 20 fractional bits relative to the VF design size.";
        if(!xx_rt_wcscmp(r->name,L"design_size"))text=L"Fixed-point points with 20 fractional bits.";
        break;
    case 0x60190045U:
        if(!xx_rt_wcscmp(r->name,L"scale"))text=L"Fixed-point scale with 20 fractional bits relative to the VF design size.";
        if(!xx_rt_wcscmp(r->name,L"design_size"))text=L"Fixed-point points with 20 fractional bits.";
        break;
    case 0x60190046U:
        if(!xx_rt_wcscmp(r->name,L"scale"))text=L"Fixed-point scale with 20 fractional bits relative to the VF design size.";
        if(!xx_rt_wcscmp(r->name,L"design_size"))text=L"Fixed-point points with 20 fractional bits.";
        break;
    case 0x60190047U:
        if(!xx_rt_wcscmp(r->name,L"scale"))text=L"Fixed-point scale with 20 fractional bits relative to the VF design size.";
        if(!xx_rt_wcscmp(r->name,L"design_size"))text=L"Fixed-point points with 20 fractional bits.";
        break;
    case 0x60190048U:
        if(!xx_rt_wcscmp(r->name,L"tfm_width"))text=L"Fixed-point width with 20 fractional bits.";
        break;
    case 0x60190049U:
        if(!xx_rt_wcscmp(r->name,L"tfm_width"))text=L"Signed fixed-point width with 20 fractional bits.";
        break;
    default:break;}return !text||xx_data_struct_record_set_comment(r,text);
}
/* These walkers describe only original bytes, not decoded glyph raster data. */
bool sxfb_span(sx_context *c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
bool sxfb_read(sx_context *c,uint64_t p,void *b,size_t n){return sxfb_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
static uint32_t sxfb_uint(const uint8_t *b,unsigned n,bool be){uint32_t x=0;for(unsigned i=0;i<n;i++)x|=(uint32_t)b[i]<<(8*(be?n-1-i:i));return x;}
uint16_t sxfb16(const uint8_t *b,bool be){return (uint16_t)sxfb_uint(b,2,be);}
uint32_t sxfb32(const uint8_t *b,bool be){return sxfb_uint(b,4,be);}
bool sxfb_add(sx_context *c,const sx_layout *l,uint64_t p){const xx_data_struct_field_desc *f=&l->fields[l->field_count-1];return p<=INT64_MAX&&sx_add(c,l,(int64_t)p,f->rel_offset+f->size);}
bool sxfb_nintendo(sx_context *c,bool be)
{
 uint8_t h[32];if(!sxfb_read(c,0,h,20)||xx_rt_memcmp(h,be?"FFNT":"CFNT",4)||sxfb16(h+4,be)!=0xfeff||sxfb16(h+6,be)!=20)return false;
 uint32_t size=sxfb32(h+12,be),blocks=sxfb32(h+16,be);if(size<20||!sxfb_span(c,0,size)||blocks>1024)return false;
 if(!sxfb_add(c,be?&sxfb_nintendo_font_header_be:&sxfb_nintendo_font_header_le,0))return false;uint64_t p=20;
 for(uint32_t i=0;i<blocks;i++){
  if(p>size||size-p<8||!sxfb_read(c,p,h,8))break;uint32_t z=sxfb32(h+4,be);if(z<8||z>size-p)break;
  if(!sxfb_add(c,be?&sxfb_nintendo_font_chunk_be:&sxfb_nintendo_font_chunk_le,p))return false;
  if(!xx_rt_memcmp(h,"FINF",4)&&z>=32){if(!sxfb_add(c,be?&sxfb_bfnt_finf:&sxfb_bcfnt_finf,p+8))return false;}
  else if(!xx_rt_memcmp(h,"TGLP",4)&&z>=32){if(!sxfb_add(c,be?&sxfb_bfnt_tglp:&sxfb_bcfnt_tglp,p+8))return false;}
  else if(!xx_rt_memcmp(h,"CWDH",4)&&z>=16){if(!sxfb_read(c,p+8,h,8)||!sxfb_add(c,be?&sxfb_nintendo_cwdh_be:&sxfb_nintendo_cwdh_le,p+8))return false;
   uint32_t first=sxfb16(h,be),last=sxfb16(h+2,be);if(last>=first&&(uint64_t)(last-first+1)*3<=z-16&&!sx_table(c,be?&sxfb_nintendo_width_be:&sxfb_nintendo_width_le,(int64_t)p+16,3,last-first+1))return false;
  }else if(!xx_rt_memcmp(h,"CMAP",4)&&z>=20){if(!sxfb_read(c,p+8,h,12)||!sxfb_add(c,be?&sxfb_nintendo_cmap_be:&sxfb_nintendo_cmap_le,p+8))return false;
   uint32_t first=sxfb16(h,be),last=sxfb16(h+2,be),method=sxfb16(h+4,be);
   if(!method&&z>=22){if(!sxfb_add(c,be?&sxfb_nintendo_map_index_be:&sxfb_nintendo_map_index_le,p+20))return false;}
   else if(method==1&&last>=first&&(uint64_t)(last-first+1)*2<=z-20){if(!sx_table(c,be?&sxfb_nintendo_map_index_be:&sxfb_nintendo_map_index_le,(int64_t)p+20,2,last-first+1))return false;}
   else if(method==2&&z>=22){if(!sxfb_read(c,p+20,h,2)||!sxfb_add(c,be?&sxfb_nintendo_map_count_be:&sxfb_nintendo_map_count_le,p+20))return false;uint32_t count=sxfb16(h,be);
    if(count&&(uint64_t)count*4<=z-22&&!sx_table(c,be?&sxfb_nintendo_map_pair_be:&sxfb_nintendo_map_pair_le,(int64_t)p+22,4,count))return false;}
  }p+=z;
 }return true;
}
/* PK/GF xxx special commands share their physical length/payload encoding. */
bool sxfb_special(sx_context *c,uint64_t *p,unsigned width)
{
 const sx_layout *l[]={&sxfb_tex_special1,&sxfb_tex_special2,&sxfb_tex_special3,&sxfb_tex_special4};uint8_t b[5];
 if(width<1||width>4||!sxfb_read(c,*p,b,width+1))return false;uint32_t n=sxfb_uint(b+1,width,true);if(!sxfb_span(c,*p,(uint64_t)width+1+n))return false;
 if(!sxfb_add(c,l[width-1],*p))return false;*p+=width+1+(uint64_t)n;return true;
}
bool sxfb_preamble(sx_context *c,unsigned id,uint64_t *p)
{
 uint8_t h[3];if(!sxfb_read(c,0,h,3)||h[0]!=247||h[1]!=id||!sxfb_span(c,3,h[2])||!sxfb_add(c,&sxfb_tex_font_preamble,0))return false;*p=3+h[2];return true;
}
static int sxfb_order(const void *a,const void *b){const xx_data_struct *x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxfb_finish(sx_context *c)
{
 size_t n=c->count;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxfb_order);
 for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p<end)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+c->items[i].total_size;}
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxfb_order);return !c->failed;
}
static bool sx_fontbinary_supports(xx_file_type_t type)
{
 switch(type){case XX_FILE_TYPE_NINTENDO_BFNT:case XX_FILE_TYPE_NINTENDO_BCFNT:case XX_FILE_TYPE_FONT_WINDOWS_FNT:case XX_FILE_TYPE_FONT_GEM_FNT:case XX_FILE_TYPE_TEX_TFM:case XX_FILE_TYPE_TEX_PK:case XX_FILE_TYPE_TEX_GF:case XX_FILE_TYPE_TEX_VF:return true;default:return false;}
}
static bool sx_fontbinary_build(sx_context *c)
{
 bool ok=false;switch(c->f->file_type){case XX_FILE_TYPE_NINTENDO_BFNT:ok=sx_nintendo_bfnt_build(c);break;case XX_FILE_TYPE_NINTENDO_BCFNT:ok=sx_nintendo_bcfnt_build(c);break;case XX_FILE_TYPE_FONT_WINDOWS_FNT:ok=sx_font_windows_fnt_build(c);break;case XX_FILE_TYPE_FONT_GEM_FNT:ok=sx_font_gem_fnt_build(c);break;case XX_FILE_TYPE_TEX_TFM:ok=sx_tex_tfm_build(c);break;case XX_FILE_TYPE_TEX_PK:ok=sx_tex_pk_build(c);break;case XX_FILE_TYPE_TEX_GF:ok=sx_tex_gf_build(c);break;case XX_FILE_TYPE_TEX_VF:ok=sx_tex_vf_build(c);break;default:break;}return ok&&sxfb_finish(c);
}
const sx_family sx_fontbinary_family={sx_fontbinary_supports,sx_fontbinary_build,sx_fontbinary_layouts,SX_COUNT(sx_fontbinary_layouts),sx_fontbinary_comment};
