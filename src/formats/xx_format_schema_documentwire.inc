/* SPDX-License-Identifier: MIT. Partial physical document/protocol metadata. */
static const xx_data_struct_field_desc sxdw_mathcad_header_fields[]={
 SX_FIELD("signature","char[15]",0,15,SX_SIGNATURE),
};
static const sx_layout sxdw_mathcad_header={0x60740001U,"documentwire_mathcad_header",sxdw_mathcad_header_fields,SX_COUNT(sxdw_mathcad_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mathcad_literal_bit0_fields[]={
 SX_FIELD("literal_flag","msb_bits[0,1]",0,1,SX_FLAGS),
 SX_FIELD("literal_byte","msb_bits[1,8]",0,2,SX_NONE),
};
static const sx_layout sxdw_mathcad_literal_bit0={0x60740002U,"documentwire_mathcad_literal_bit0",sxdw_mathcad_literal_bit0_fields,SX_COUNT(sxdw_mathcad_literal_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mathcad_match_bit0_fields[]={
 SX_FIELD("literal_flag","msb_bits[0,1]",0,1,SX_FLAGS),
 SX_FIELD("ring_position","msb_bits[1,12]",0,2,SX_NONE),
 SX_FIELD("length_code","msb_bits[5,4]",1,2,SX_NONE),
};
static const sx_layout sxdw_mathcad_match_bit0={0x60740003U,"documentwire_mathcad_match_bit0",sxdw_mathcad_match_bit0_fields,SX_COUNT(sxdw_mathcad_match_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mathcad_end_bit0_fields[]={
 SX_FIELD("literal_flag","msb_bits[0,1]",0,1,SX_FLAGS),
 SX_FIELD("end_position","msb_bits[1,12]",0,2,SX_NONE),
};
static const sx_layout sxdw_mathcad_end_bit0={0x60740004U,"documentwire_mathcad_end_bit0",sxdw_mathcad_end_bit0_fields,SX_COUNT(sxdw_mathcad_end_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mathcad_literal_bit1_fields[]={
 SX_FIELD("literal_flag","msb_bits[1,1]",0,1,SX_FLAGS),
 SX_FIELD("literal_byte","msb_bits[2,8]",0,2,SX_NONE),
};
static const sx_layout sxdw_mathcad_literal_bit1={0x60740005U,"documentwire_mathcad_literal_bit1",sxdw_mathcad_literal_bit1_fields,SX_COUNT(sxdw_mathcad_literal_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mathcad_match_bit1_fields[]={
 SX_FIELD("literal_flag","msb_bits[1,1]",0,1,SX_FLAGS),
 SX_FIELD("ring_position","msb_bits[2,12]",0,2,SX_NONE),
 SX_FIELD("length_code","msb_bits[6,4]",1,2,SX_NONE),
};
static const sx_layout sxdw_mathcad_match_bit1={0x60740006U,"documentwire_mathcad_match_bit1",sxdw_mathcad_match_bit1_fields,SX_COUNT(sxdw_mathcad_match_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mathcad_end_bit1_fields[]={
 SX_FIELD("literal_flag","msb_bits[1,1]",0,1,SX_FLAGS),
 SX_FIELD("end_position","msb_bits[2,12]",0,2,SX_NONE),
};
static const sx_layout sxdw_mathcad_end_bit1={0x60740007U,"documentwire_mathcad_end_bit1",sxdw_mathcad_end_bit1_fields,SX_COUNT(sxdw_mathcad_end_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mathcad_literal_bit2_fields[]={
 SX_FIELD("literal_flag","msb_bits[2,1]",0,1,SX_FLAGS),
 SX_FIELD("literal_byte","msb_bits[3,8]",0,2,SX_NONE),
};
static const sx_layout sxdw_mathcad_literal_bit2={0x60740008U,"documentwire_mathcad_literal_bit2",sxdw_mathcad_literal_bit2_fields,SX_COUNT(sxdw_mathcad_literal_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mathcad_match_bit2_fields[]={
 SX_FIELD("literal_flag","msb_bits[2,1]",0,1,SX_FLAGS),
 SX_FIELD("ring_position","msb_bits[3,12]",0,2,SX_NONE),
 SX_FIELD("length_code","msb_bits[7,4]",1,2,SX_NONE),
};
static const sx_layout sxdw_mathcad_match_bit2={0x60740009U,"documentwire_mathcad_match_bit2",sxdw_mathcad_match_bit2_fields,SX_COUNT(sxdw_mathcad_match_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mathcad_end_bit2_fields[]={
 SX_FIELD("literal_flag","msb_bits[2,1]",0,1,SX_FLAGS),
 SX_FIELD("end_position","msb_bits[3,12]",0,2,SX_NONE),
};
static const sx_layout sxdw_mathcad_end_bit2={0x6074000aU,"documentwire_mathcad_end_bit2",sxdw_mathcad_end_bit2_fields,SX_COUNT(sxdw_mathcad_end_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mathcad_literal_bit3_fields[]={
 SX_FIELD("literal_flag","msb_bits[3,1]",0,1,SX_FLAGS),
 SX_FIELD("literal_byte","msb_bits[4,8]",0,2,SX_NONE),
};
static const sx_layout sxdw_mathcad_literal_bit3={0x6074000bU,"documentwire_mathcad_literal_bit3",sxdw_mathcad_literal_bit3_fields,SX_COUNT(sxdw_mathcad_literal_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mathcad_match_bit3_fields[]={
 SX_FIELD("literal_flag","msb_bits[3,1]",0,1,SX_FLAGS),
 SX_FIELD("ring_position","msb_bits[4,12]",0,2,SX_NONE),
 SX_FIELD("length_code","msb_bits[0,4]",2,1,SX_NONE),
};
static const sx_layout sxdw_mathcad_match_bit3={0x6074000cU,"documentwire_mathcad_match_bit3",sxdw_mathcad_match_bit3_fields,SX_COUNT(sxdw_mathcad_match_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mathcad_end_bit3_fields[]={
 SX_FIELD("literal_flag","msb_bits[3,1]",0,1,SX_FLAGS),
 SX_FIELD("end_position","msb_bits[4,12]",0,2,SX_NONE),
};
static const sx_layout sxdw_mathcad_end_bit3={0x6074000dU,"documentwire_mathcad_end_bit3",sxdw_mathcad_end_bit3_fields,SX_COUNT(sxdw_mathcad_end_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mathcad_literal_bit4_fields[]={
 SX_FIELD("literal_flag","msb_bits[4,1]",0,1,SX_FLAGS),
 SX_FIELD("literal_byte","msb_bits[5,8]",0,2,SX_NONE),
};
static const sx_layout sxdw_mathcad_literal_bit4={0x6074000eU,"documentwire_mathcad_literal_bit4",sxdw_mathcad_literal_bit4_fields,SX_COUNT(sxdw_mathcad_literal_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mathcad_match_bit4_fields[]={
 SX_FIELD("literal_flag","msb_bits[4,1]",0,1,SX_FLAGS),
 SX_FIELD("ring_position","msb_bits[5,12]",0,3,SX_NONE),
 SX_FIELD("length_code","msb_bits[1,4]",2,1,SX_NONE),
};
static const sx_layout sxdw_mathcad_match_bit4={0x6074000fU,"documentwire_mathcad_match_bit4",sxdw_mathcad_match_bit4_fields,SX_COUNT(sxdw_mathcad_match_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mathcad_end_bit4_fields[]={
 SX_FIELD("literal_flag","msb_bits[4,1]",0,1,SX_FLAGS),
 SX_FIELD("end_position","msb_bits[5,12]",0,3,SX_NONE),
};
static const sx_layout sxdw_mathcad_end_bit4={0x60740010U,"documentwire_mathcad_end_bit4",sxdw_mathcad_end_bit4_fields,SX_COUNT(sxdw_mathcad_end_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mathcad_literal_bit5_fields[]={
 SX_FIELD("literal_flag","msb_bits[5,1]",0,1,SX_FLAGS),
 SX_FIELD("literal_byte","msb_bits[6,8]",0,2,SX_NONE),
};
static const sx_layout sxdw_mathcad_literal_bit5={0x60740011U,"documentwire_mathcad_literal_bit5",sxdw_mathcad_literal_bit5_fields,SX_COUNT(sxdw_mathcad_literal_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mathcad_match_bit5_fields[]={
 SX_FIELD("literal_flag","msb_bits[5,1]",0,1,SX_FLAGS),
 SX_FIELD("ring_position","msb_bits[6,12]",0,3,SX_NONE),
 SX_FIELD("length_code","msb_bits[2,4]",2,1,SX_NONE),
};
static const sx_layout sxdw_mathcad_match_bit5={0x60740012U,"documentwire_mathcad_match_bit5",sxdw_mathcad_match_bit5_fields,SX_COUNT(sxdw_mathcad_match_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mathcad_end_bit5_fields[]={
 SX_FIELD("literal_flag","msb_bits[5,1]",0,1,SX_FLAGS),
 SX_FIELD("end_position","msb_bits[6,12]",0,3,SX_NONE),
};
static const sx_layout sxdw_mathcad_end_bit5={0x60740013U,"documentwire_mathcad_end_bit5",sxdw_mathcad_end_bit5_fields,SX_COUNT(sxdw_mathcad_end_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mathcad_literal_bit6_fields[]={
 SX_FIELD("literal_flag","msb_bits[6,1]",0,1,SX_FLAGS),
 SX_FIELD("literal_byte","msb_bits[7,8]",0,2,SX_NONE),
};
static const sx_layout sxdw_mathcad_literal_bit6={0x60740014U,"documentwire_mathcad_literal_bit6",sxdw_mathcad_literal_bit6_fields,SX_COUNT(sxdw_mathcad_literal_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mathcad_match_bit6_fields[]={
 SX_FIELD("literal_flag","msb_bits[6,1]",0,1,SX_FLAGS),
 SX_FIELD("ring_position","msb_bits[7,12]",0,3,SX_NONE),
 SX_FIELD("length_code","msb_bits[3,4]",2,1,SX_NONE),
};
static const sx_layout sxdw_mathcad_match_bit6={0x60740015U,"documentwire_mathcad_match_bit6",sxdw_mathcad_match_bit6_fields,SX_COUNT(sxdw_mathcad_match_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mathcad_end_bit6_fields[]={
 SX_FIELD("literal_flag","msb_bits[6,1]",0,1,SX_FLAGS),
 SX_FIELD("end_position","msb_bits[7,12]",0,3,SX_NONE),
};
static const sx_layout sxdw_mathcad_end_bit6={0x60740016U,"documentwire_mathcad_end_bit6",sxdw_mathcad_end_bit6_fields,SX_COUNT(sxdw_mathcad_end_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mathcad_literal_bit7_fields[]={
 SX_FIELD("literal_flag","msb_bits[7,1]",0,1,SX_FLAGS),
 SX_FIELD("literal_byte","msb_bits[0,8]",1,1,SX_NONE),
};
static const sx_layout sxdw_mathcad_literal_bit7={0x60740017U,"documentwire_mathcad_literal_bit7",sxdw_mathcad_literal_bit7_fields,SX_COUNT(sxdw_mathcad_literal_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mathcad_match_bit7_fields[]={
 SX_FIELD("literal_flag","msb_bits[7,1]",0,1,SX_FLAGS),
 SX_FIELD("ring_position","msb_bits[0,12]",1,2,SX_NONE),
 SX_FIELD("length_code","msb_bits[4,4]",2,1,SX_NONE),
};
static const sx_layout sxdw_mathcad_match_bit7={0x60740018U,"documentwire_mathcad_match_bit7",sxdw_mathcad_match_bit7_fields,SX_COUNT(sxdw_mathcad_match_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mathcad_end_bit7_fields[]={
 SX_FIELD("literal_flag","msb_bits[7,1]",0,1,SX_FLAGS),
 SX_FIELD("end_position","msb_bits[0,12]",1,2,SX_NONE),
};
static const sx_layout sxdw_mathcad_end_bit7={0x60740019U,"documentwire_mathcad_end_bit7",sxdw_mathcad_end_bit7_fields,SX_COUNT(sxdw_mathcad_end_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_rprj_header_fields[]={
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32le",4,4,SX_NONE),
};
static const sx_layout sxdw_rprj_header={0x6074001aU,"documentwire_rprj_header",sxdw_rprj_header_fields,SX_COUNT(sxdw_rprj_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_theme_version_fields[]={
 SX_FIELD("theme_version","utf8",0,0,SX_STRING),
};
static const sx_layout sxdw_theme_version={0x6074001bU,"documentwire_theme_version",sxdw_theme_version_fields,SX_COUNT(sxdw_theme_version_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_theme_name_fields[]={
 SX_FIELD("theme_name","utf8",0,0,SX_STRING),
};
static const sx_layout sxdw_theme_name={0x6074001cU,"documentwire_theme_name",sxdw_theme_name_fields,SX_COUNT(sxdw_theme_name_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_theme_css_fields[]={
 SX_FIELD("theme_css","utf8",0,0,SX_STRING),
};
static const sx_layout sxdw_theme_css={0x6074001dU,"documentwire_theme_css",sxdw_theme_css_fields,SX_COUNT(sxdw_theme_css_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_notetab_option_fields[]={
 SX_FIELD("notetab_option","utf8",0,0,SX_STRING),
};
static const sx_layout sxdw_notetab_option={0x6074001eU,"documentwire_notetab_option",sxdw_notetab_option_fields,SX_COUNT(sxdw_notetab_option_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_notetab_heading_fields[]={
 SX_FIELD("notetab_heading","utf8",0,0,SX_STRING),
};
static const sx_layout sxdw_notetab_heading={0x6074001fU,"documentwire_notetab_heading",sxdw_notetab_heading_fields,SX_COUNT(sxdw_notetab_heading_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_notetab_body_line_fields[]={
 SX_FIELD("notetab_body_line","utf8",0,0,SX_STRING),
};
static const sx_layout sxdw_notetab_body_line={0x60740020U,"documentwire_notetab_body_line",sxdw_notetab_body_line_fields,SX_COUNT(sxdw_notetab_body_line_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_pjl_command_fields[]={
 SX_FIELD("pjl_command","utf8",0,0,SX_STRING),
};
static const sx_layout sxdw_pjl_command={0x60740021U,"documentwire_pjl_command",sxdw_pjl_command_fields,SX_COUNT(sxdw_pjl_command_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_pjl_parameter_fields[]={
 SX_FIELD("pjl_parameter","utf8",0,0,SX_STRING),
};
static const sx_layout sxdw_pjl_parameter={0x60740022U,"documentwire_pjl_parameter",sxdw_pjl_parameter_fields,SX_COUNT(sxdw_pjl_parameter_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_pjl_value_fields[]={
 SX_FIELD("pjl_value","utf8",0,0,SX_STRING),
};
static const sx_layout sxdw_pjl_value={0x60740023U,"documentwire_pjl_value",sxdw_pjl_value_fields,SX_COUNT(sxdw_pjl_value_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_pjl_text_fields[]={
 SX_FIELD("pjl_text","utf8",0,0,SX_STRING),
};
static const sx_layout sxdw_pjl_text={0x60740024U,"documentwire_pjl_text",sxdw_pjl_text_fields,SX_COUNT(sxdw_pjl_text_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_theme_member_count_fields[]={
 SX_FIELD("theme_member_count","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxdw_theme_member_count={0x60740025U,"documentwire_theme_member_count",sxdw_theme_member_count_fields,SX_COUNT(sxdw_theme_member_count_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_theme_member_size_fields[]={
 SX_FIELD("theme_member_size","ascii_signed",0,0,SX_SIZE),
};
static const sx_layout sxdw_theme_member_size={0x60740026U,"documentwire_theme_member_size",sxdw_theme_member_size_fields,SX_COUNT(sxdw_theme_member_size_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_wrq_record_size_fields[]={
 SX_FIELD("wrq_record_size","ascii_signed",0,0,SX_SIZE),
};
static const sx_layout sxdw_wrq_record_size={0x60740027U,"documentwire_wrq_record_size",sxdw_wrq_record_size_fields,SX_COUNT(sxdw_wrq_record_size_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_wrq_block_factor_fields[]={
 SX_FIELD("wrq_block_factor","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxdw_wrq_block_factor={0x60740028U,"documentwire_wrq_block_factor",sxdw_wrq_block_factor_fields,SX_COUNT(sxdw_wrq_block_factor_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_wrq_file_code_fields[]={
 SX_FIELD("wrq_file_code","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxdw_wrq_file_code={0x60740029U,"documentwire_wrq_file_code",sxdw_wrq_file_code_fields,SX_COUNT(sxdw_wrq_file_code_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_wrq_extents_fields[]={
 SX_FIELD("wrq_extents","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxdw_wrq_extents={0x6074002aU,"documentwire_wrq_extents",sxdw_wrq_extents_fields,SX_COUNT(sxdw_wrq_extents_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_wrq_record_count_fields[]={
 SX_FIELD("wrq_record_count","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxdw_wrq_record_count={0x6074002bU,"documentwire_wrq_record_count",sxdw_wrq_record_count_fields,SX_COUNT(sxdw_wrq_record_count_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_theme_payload_marker_fields[]={
 SX_FIELD("marker","char[14]",0,14,SX_SIGNATURE),
};
static const sx_layout sxdw_theme_payload_marker={0x6074002cU,"documentwire_theme_payload_marker",sxdw_theme_payload_marker_fields,SX_COUNT(sxdw_theme_payload_marker_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_notetab_declaration_fields[]={
 SX_FIELD("signature","char[3]",0,3,SX_SIGNATURE),
 SX_FIELD("version","ascii_signed[1]",3,1,SX_NONE),
};
static const sx_layout sxdw_notetab_declaration={0x6074002dU,"documentwire_notetab_declaration",sxdw_notetab_declaration_fields,SX_COUNT(sxdw_notetab_declaration_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_pjl_uel_fields[]={
 SX_FIELD("universal_exit_language","uint8[9]",0,9,SX_SIGNATURE),
};
static const sx_layout sxdw_pjl_uel={0x6074002eU,"documentwire_pjl_uel",sxdw_pjl_uel_fields,SX_COUNT(sxdw_pjl_uel_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_wrq_format_fields[]={
 SX_FIELD("format","char[1]",0,1,SX_ID),
};
static const sx_layout sxdw_wrq_format={0x6074002fU,"documentwire_wrq_format",sxdw_wrq_format_fields,SX_COUNT(sxdw_wrq_format_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_ber_short_header_fields[]={
 SX_FIELD("tag","uint8",0,1,SX_ID),
 SX_FIELD("content_length","uint8",1,1,SX_SIZE),
};
static const sx_layout sxdw_ber_short_header={0x60740030U,"documentwire_ber_short_header",sxdw_ber_short_header_fields,SX_COUNT(sxdw_ber_short_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_ber_long_header1_fields[]={
 SX_FIELD("tag","uint8",0,1,SX_ID),
 SX_FIELD("length_form","uint8",1,1,SX_FLAGS),
 SX_FIELD("content_length","uint8be",2,1,SX_SIZE),
};
static const sx_layout sxdw_ber_long_header1={0x60740031U,"documentwire_ber_long_header1",sxdw_ber_long_header1_fields,SX_COUNT(sxdw_ber_long_header1_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_ber_long_header2_fields[]={
 SX_FIELD("tag","uint8",0,1,SX_ID),
 SX_FIELD("length_form","uint8",1,1,SX_FLAGS),
 SX_FIELD("content_length","uint16be",2,2,SX_SIZE),
};
static const sx_layout sxdw_ber_long_header2={0x60740032U,"documentwire_ber_long_header2",sxdw_ber_long_header2_fields,SX_COUNT(sxdw_ber_long_header2_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_ber_long_header3_fields[]={
 SX_FIELD("tag","uint8",0,1,SX_ID),
 SX_FIELD("length_form","uint8",1,1,SX_FLAGS),
 SX_FIELD("content_length","uint24be",2,3,SX_SIZE),
};
static const sx_layout sxdw_ber_long_header3={0x60740033U,"documentwire_ber_long_header3",sxdw_ber_long_header3_fields,SX_COUNT(sxdw_ber_long_header3_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_ber_long_header4_fields[]={
 SX_FIELD("tag","uint8",0,1,SX_ID),
 SX_FIELD("length_form","uint8",1,1,SX_FLAGS),
 SX_FIELD("content_length","uint32be",2,4,SX_SIZE),
};
static const sx_layout sxdw_ber_long_header4={0x60740034U,"documentwire_ber_long_header4",sxdw_ber_long_header4_fields,SX_COUNT(sxdw_ber_long_header4_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_ber_signed1_fields[]={
 SX_FIELD("integer","int8be",0,1,SX_NONE),
};
static const sx_layout sxdw_ber_signed1={0x60740035U,"documentwire_ber_signed1",sxdw_ber_signed1_fields,SX_COUNT(sxdw_ber_signed1_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_ber_signed2_fields[]={
 SX_FIELD("integer","int16be",0,2,SX_NONE),
};
static const sx_layout sxdw_ber_signed2={0x60740036U,"documentwire_ber_signed2",sxdw_ber_signed2_fields,SX_COUNT(sxdw_ber_signed2_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_ber_signed3_fields[]={
 SX_FIELD("integer","int24be",0,3,SX_NONE),
};
static const sx_layout sxdw_ber_signed3={0x60740037U,"documentwire_ber_signed3",sxdw_ber_signed3_fields,SX_COUNT(sxdw_ber_signed3_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_ber_signed4_fields[]={
 SX_FIELD("integer","int32be",0,4,SX_NONE),
};
static const sx_layout sxdw_ber_signed4={0x60740038U,"documentwire_ber_signed4",sxdw_ber_signed4_fields,SX_COUNT(sxdw_ber_signed4_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_ber_unsigned1_fields[]={
 SX_FIELD("unsigned_integer","uint8be",0,1,SX_NONE),
};
static const sx_layout sxdw_ber_unsigned1={0x60740039U,"documentwire_ber_unsigned1",sxdw_ber_unsigned1_fields,SX_COUNT(sxdw_ber_unsigned1_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_ber_unsigned2_fields[]={
 SX_FIELD("unsigned_integer","uint16be",0,2,SX_NONE),
};
static const sx_layout sxdw_ber_unsigned2={0x6074003aU,"documentwire_ber_unsigned2",sxdw_ber_unsigned2_fields,SX_COUNT(sxdw_ber_unsigned2_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_ber_unsigned3_fields[]={
 SX_FIELD("unsigned_integer","uint24be",0,3,SX_NONE),
};
static const sx_layout sxdw_ber_unsigned3={0x6074003bU,"documentwire_ber_unsigned3",sxdw_ber_unsigned3_fields,SX_COUNT(sxdw_ber_unsigned3_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_ber_unsigned4_fields[]={
 SX_FIELD("unsigned_integer","uint32be",0,4,SX_NONE),
};
static const sx_layout sxdw_ber_unsigned4={0x6074003cU,"documentwire_ber_unsigned4",sxdw_ber_unsigned4_fields,SX_COUNT(sxdw_ber_unsigned4_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_ber_unsigned5_fields[]={
 SX_FIELD("unsigned_integer","uint40be",0,5,SX_NONE),
};
static const sx_layout sxdw_ber_unsigned5={0x6074003dU,"documentwire_ber_unsigned5",sxdw_ber_unsigned5_fields,SX_COUNT(sxdw_ber_unsigned5_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_ber_unsigned6_fields[]={
 SX_FIELD("unsigned_integer","uint48be",0,6,SX_NONE),
};
static const sx_layout sxdw_ber_unsigned6={0x6074003eU,"documentwire_ber_unsigned6",sxdw_ber_unsigned6_fields,SX_COUNT(sxdw_ber_unsigned6_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_ber_unsigned7_fields[]={
 SX_FIELD("unsigned_integer","uint56be",0,7,SX_NONE),
};
static const sx_layout sxdw_ber_unsigned7={0x6074003fU,"documentwire_ber_unsigned7",sxdw_ber_unsigned7_fields,SX_COUNT(sxdw_ber_unsigned7_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_ber_unsigned8_fields[]={
 SX_FIELD("unsigned_integer","uint64be",0,8,SX_NONE),
};
static const sx_layout sxdw_ber_unsigned8={0x60740040U,"documentwire_ber_unsigned8",sxdw_ber_unsigned8_fields,SX_COUNT(sxdw_ber_unsigned8_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_ber_unsigned9_fields[]={
 SX_FIELD("positive_sign_octet","uint8",0,1,SX_NONE),
 SX_FIELD("unsigned_integer","uint64be",1,8,SX_NONE),
};
static const sx_layout sxdw_ber_unsigned9={0x60740041U,"documentwire_ber_unsigned9",sxdw_ber_unsigned9_fields,SX_COUNT(sxdw_ber_unsigned9_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_ber_oid_octet_fields[]={
 SX_FIELD("base128_oid_octet","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxdw_ber_oid_octet={0x60740042U,"documentwire_ber_oid_octet",sxdw_ber_oid_octet_fields,SX_COUNT(sxdw_ber_oid_octet_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_ber_ipv4_fields[]={
 SX_FIELD("ipv4_address","uint8[4]",0,4,SX_NONE),
};
static const sx_layout sxdw_ber_ipv4={0x60740043U,"documentwire_ber_ipv4",sxdw_ber_ipv4_fields,SX_COUNT(sxdw_ber_ipv4_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_ber_octet_text_fields[]={
 SX_FIELD("ber_octet_text","utf8",0,0,SX_STRING),
};
static const sx_layout sxdw_ber_octet_text={0x60740044U,"documentwire_ber_octet_text",sxdw_ber_octet_text_fields,SX_COUNT(sxdw_ber_octet_text_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_ssh_identification_fields[]={
 SX_FIELD("ssh_identification","utf8",0,0,SX_STRING),
};
static const sx_layout sxdw_ssh_identification={0x60740045U,"documentwire_ssh_identification",sxdw_ssh_identification_fields,SX_COUNT(sxdw_ssh_identification_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_ssh_packet_header_fields[]={
 SX_FIELD("packet_length","uint32be",0,4,SX_SIZE),
 SX_FIELD("padding_length","uint8",4,1,SX_SIZE),
 SX_FIELD("message_type","uint8",5,1,SX_ID),
};
static const sx_layout sxdw_ssh_packet_header={0x60740046U,"documentwire_ssh_packet_header",sxdw_ssh_packet_header_fields,SX_COUNT(sxdw_ssh_packet_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_ssh_cookie_fields[]={
 SX_FIELD("cookie","uint8[16]",0,16,SX_NONE),
};
static const sx_layout sxdw_ssh_cookie={0x60740047U,"documentwire_ssh_cookie",sxdw_ssh_cookie_fields,SX_COUNT(sxdw_ssh_cookie_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_ssh_string_length_fields[]={
 SX_FIELD("byte_length","uint32be",0,4,SX_SIZE),
};
static const sx_layout sxdw_ssh_string_length={0x60740048U,"documentwire_ssh_string_length",sxdw_ssh_string_length_fields,SX_COUNT(sxdw_ssh_string_length_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_ssh_kex_algorithms_fields[]={
 SX_FIELD("ssh_kex_algorithms","utf8",0,0,SX_STRING),
};
static const sx_layout sxdw_ssh_kex_algorithms={0x60740049U,"documentwire_ssh_kex_algorithms",sxdw_ssh_kex_algorithms_fields,SX_COUNT(sxdw_ssh_kex_algorithms_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_ssh_server_host_key_algorithms_fields[]={
 SX_FIELD("ssh_server_host_key_algorithms","utf8",0,0,SX_STRING),
};
static const sx_layout sxdw_ssh_server_host_key_algorithms={0x6074004aU,"documentwire_ssh_server_host_key_algorithms",sxdw_ssh_server_host_key_algorithms_fields,SX_COUNT(sxdw_ssh_server_host_key_algorithms_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_ssh_encryption_client_to_server_fields[]={
 SX_FIELD("ssh_encryption_client_to_server","utf8",0,0,SX_STRING),
};
static const sx_layout sxdw_ssh_encryption_client_to_server={0x6074004bU,"documentwire_ssh_encryption_client_to_server",sxdw_ssh_encryption_client_to_server_fields,SX_COUNT(sxdw_ssh_encryption_client_to_server_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_ssh_encryption_server_to_client_fields[]={
 SX_FIELD("ssh_encryption_server_to_client","utf8",0,0,SX_STRING),
};
static const sx_layout sxdw_ssh_encryption_server_to_client={0x6074004cU,"documentwire_ssh_encryption_server_to_client",sxdw_ssh_encryption_server_to_client_fields,SX_COUNT(sxdw_ssh_encryption_server_to_client_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_ssh_mac_client_to_server_fields[]={
 SX_FIELD("ssh_mac_client_to_server","utf8",0,0,SX_STRING),
};
static const sx_layout sxdw_ssh_mac_client_to_server={0x6074004dU,"documentwire_ssh_mac_client_to_server",sxdw_ssh_mac_client_to_server_fields,SX_COUNT(sxdw_ssh_mac_client_to_server_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_ssh_mac_server_to_client_fields[]={
 SX_FIELD("ssh_mac_server_to_client","utf8",0,0,SX_STRING),
};
static const sx_layout sxdw_ssh_mac_server_to_client={0x6074004eU,"documentwire_ssh_mac_server_to_client",sxdw_ssh_mac_server_to_client_fields,SX_COUNT(sxdw_ssh_mac_server_to_client_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_ssh_compression_client_to_server_fields[]={
 SX_FIELD("ssh_compression_client_to_server","utf8",0,0,SX_STRING),
};
static const sx_layout sxdw_ssh_compression_client_to_server={0x6074004fU,"documentwire_ssh_compression_client_to_server",sxdw_ssh_compression_client_to_server_fields,SX_COUNT(sxdw_ssh_compression_client_to_server_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_ssh_compression_server_to_client_fields[]={
 SX_FIELD("ssh_compression_server_to_client","utf8",0,0,SX_STRING),
};
static const sx_layout sxdw_ssh_compression_server_to_client={0x60740050U,"documentwire_ssh_compression_server_to_client",sxdw_ssh_compression_server_to_client_fields,SX_COUNT(sxdw_ssh_compression_server_to_client_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_ssh_languages_client_to_server_fields[]={
 SX_FIELD("ssh_languages_client_to_server","utf8",0,0,SX_STRING),
};
static const sx_layout sxdw_ssh_languages_client_to_server={0x60740051U,"documentwire_ssh_languages_client_to_server",sxdw_ssh_languages_client_to_server_fields,SX_COUNT(sxdw_ssh_languages_client_to_server_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_ssh_languages_server_to_client_fields[]={
 SX_FIELD("ssh_languages_server_to_client","utf8",0,0,SX_STRING),
};
static const sx_layout sxdw_ssh_languages_server_to_client={0x60740052U,"documentwire_ssh_languages_server_to_client",sxdw_ssh_languages_server_to_client_fields,SX_COUNT(sxdw_ssh_languages_server_to_client_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_ssh_kex_tail_fields[]={
 SX_FIELD("first_kex_packet_follows","uint8",0,1,SX_FLAGS),
 SX_FIELD("reserved","uint32be",1,4,SX_RESERVED),
};
static const sx_layout sxdw_ssh_kex_tail={0x60740053U,"documentwire_ssh_kex_tail",sxdw_ssh_kex_tail_fields,SX_COUNT(sxdw_ssh_kex_tail_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_text_bom2_fields[]={
 SX_FIELD("byte_order_mark","uint8[2]",0,2,SX_SIGNATURE),
};
static const sx_layout sxdw_text_bom2={0x60740054U,"documentwire_text_bom2",sxdw_text_bom2_fields,SX_COUNT(sxdw_text_bom2_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_text_bom3_fields[]={
 SX_FIELD("byte_order_mark","uint8[3]",0,3,SX_SIGNATURE),
};
static const sx_layout sxdw_text_bom3={0x60740055U,"documentwire_text_bom3",sxdw_text_bom3_fields,SX_COUNT(sxdw_text_bom3_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_text_bom4_fields[]={
 SX_FIELD("byte_order_mark","uint8[4]",0,4,SX_SIGNATURE),
};
static const sx_layout sxdw_text_bom4={0x60740056U,"documentwire_text_bom4",sxdw_text_bom4_fields,SX_COUNT(sxdw_text_bom4_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_text_utf16le_fields[]={
 SX_FIELD("code_unit","uint16le",0,2,SX_NONE),
};
static const sx_layout sxdw_text_utf16le={0x60740057U,"documentwire_text_utf16le",sxdw_text_utf16le_fields,SX_COUNT(sxdw_text_utf16le_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_text_utf16be_fields[]={
 SX_FIELD("code_unit","uint16be",0,2,SX_NONE),
};
static const sx_layout sxdw_text_utf16be={0x60740058U,"documentwire_text_utf16be",sxdw_text_utf16be_fields,SX_COUNT(sxdw_text_utf16be_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_text_utf32le_fields[]={
 SX_FIELD("code_unit","uint32le",0,4,SX_NONE),
};
static const sx_layout sxdw_text_utf32le={0x60740059U,"documentwire_text_utf32le",sxdw_text_utf32le_fields,SX_COUNT(sxdw_text_utf32le_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_text_utf32be_fields[]={
 SX_FIELD("code_unit","uint32be",0,4,SX_NONE),
};
static const sx_layout sxdw_text_utf32be={0x6074005aU,"documentwire_text_utf32be",sxdw_text_utf32be_fields,SX_COUNT(sxdw_text_utf32be_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_text_line_fields[]={
 SX_FIELD("text_line","utf8",0,0,SX_STRING),
};
static const sx_layout sxdw_text_line={0x6074005bU,"documentwire_text_line",sxdw_text_line_fields,SX_COUNT(sxdw_text_line_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mime_field_name_fields[]={
 SX_FIELD("mime_field_name","utf8",0,0,SX_STRING),
};
static const sx_layout sxdw_mime_field_name={0x6074005cU,"documentwire_mime_field_name",sxdw_mime_field_name_fields,SX_COUNT(sxdw_mime_field_name_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mime_field_value_fields[]={
 SX_FIELD("mime_field_value","utf8",0,0,SX_STRING),
};
static const sx_layout sxdw_mime_field_value={0x6074005dU,"documentwire_mime_field_value",sxdw_mime_field_value_fields,SX_COUNT(sxdw_mime_field_value_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mime_continuation_fields[]={
 SX_FIELD("mime_continuation","utf8",0,0,SX_STRING),
};
static const sx_layout sxdw_mime_continuation={0x6074005eU,"documentwire_mime_continuation",sxdw_mime_continuation_fields,SX_COUNT(sxdw_mime_continuation_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mime_boundary_fields[]={
 SX_FIELD("mime_boundary","utf8",0,0,SX_STRING),
};
static const sx_layout sxdw_mime_boundary={0x6074005fU,"documentwire_mime_boundary",sxdw_mime_boundary_fields,SX_COUNT(sxdw_mime_boundary_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_pdf_header_fields[]={
 SX_FIELD("signature","char[5]",0,5,SX_SIGNATURE),
 SX_FIELD("version","char[3]",5,3,SX_NONE),
};
static const sx_layout sxdw_pdf_header={0x60740060U,"documentwire_pdf_header",sxdw_pdf_header_fields,SX_COUNT(sxdw_pdf_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_pdf_name_fields[]={
 SX_FIELD("pdf_name","utf8",0,0,SX_STRING),
};
static const sx_layout sxdw_pdf_name={0x60740061U,"documentwire_pdf_name",sxdw_pdf_name_fields,SX_COUNT(sxdw_pdf_name_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_pdf_literal_string_fields[]={
 SX_FIELD("pdf_literal_string","utf8",0,0,SX_STRING),
};
static const sx_layout sxdw_pdf_literal_string={0x60740062U,"documentwire_pdf_literal_string",sxdw_pdf_literal_string_fields,SX_COUNT(sxdw_pdf_literal_string_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_pdf_hex_string_fields[]={
 SX_FIELD("pdf_hex_string","utf8",0,0,SX_STRING),
};
static const sx_layout sxdw_pdf_hex_string={0x60740063U,"documentwire_pdf_hex_string",sxdw_pdf_hex_string_fields,SX_COUNT(sxdw_pdf_hex_string_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_pdf_keyword_fields[]={
 SX_FIELD("pdf_keyword","utf8",0,0,SX_STRING),
};
static const sx_layout sxdw_pdf_keyword={0x60740064U,"documentwire_pdf_keyword",sxdw_pdf_keyword_fields,SX_COUNT(sxdw_pdf_keyword_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_pdf_integer_fields[]={
 SX_FIELD("pdf_integer","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxdw_pdf_integer={0x60740065U,"documentwire_pdf_integer",sxdw_pdf_integer_fields,SX_COUNT(sxdw_pdf_integer_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_pdf_object_id_fields[]={
 SX_FIELD("pdf_object_id","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxdw_pdf_object_id={0x60740066U,"documentwire_pdf_object_id",sxdw_pdf_object_id_fields,SX_COUNT(sxdw_pdf_object_id_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_pdf_generation_fields[]={
 SX_FIELD("pdf_generation","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxdw_pdf_generation={0x60740067U,"documentwire_pdf_generation",sxdw_pdf_generation_fields,SX_COUNT(sxdw_pdf_generation_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_pdf_xref_first_object_fields[]={
 SX_FIELD("pdf_xref_first_object","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxdw_pdf_xref_first_object={0x60740068U,"documentwire_pdf_xref_first_object",sxdw_pdf_xref_first_object_fields,SX_COUNT(sxdw_pdf_xref_first_object_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_pdf_xref_count_fields[]={
 SX_FIELD("pdf_xref_count","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxdw_pdf_xref_count={0x60740069U,"documentwire_pdf_xref_count",sxdw_pdf_xref_count_fields,SX_COUNT(sxdw_pdf_xref_count_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_pdf_stream_length_fields[]={
 SX_FIELD("pdf_stream_length","ascii_signed",0,0,SX_SIZE),
};
static const sx_layout sxdw_pdf_stream_length={0x6074006aU,"documentwire_pdf_stream_length",sxdw_pdf_stream_length_fields,SX_COUNT(sxdw_pdf_stream_length_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_pdf_offset_fields[]={
 SX_FIELD("pdf_offset","ascii_signed",0,0,SX_OFFSET),
};
static const sx_layout sxdw_pdf_offset={0x6074006bU,"documentwire_pdf_offset",sxdw_pdf_offset_fields,SX_COUNT(sxdw_pdf_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_pdf_real_fields[]={
 SX_FIELD("pdf_real","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxdw_pdf_real={0x6074006cU,"documentwire_pdf_real",sxdw_pdf_real_fields,SX_COUNT(sxdw_pdf_real_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_pdf_xref_in_use_fields[]={
 SX_FIELD("file_offset","ascii_signed[10]",0,10,SX_OFFSET),
 SX_FIELD("generation","ascii_signed[5]",11,5,SX_NONE),
 SX_FIELD("entry_kind","char[1]",17,1,SX_ID),
};
static const sx_layout sxdw_pdf_xref_in_use={0x6074006dU,"documentwire_pdf_xref_in_use",sxdw_pdf_xref_in_use_fields,SX_COUNT(sxdw_pdf_xref_in_use_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_pdf_xref_free_fields[]={
 SX_FIELD("next_free_object","ascii_signed[10]",0,10,SX_NONE),
 SX_FIELD("generation","ascii_signed[5]",11,5,SX_NONE),
 SX_FIELD("entry_kind","char[1]",17,1,SX_ID),
};
static const sx_layout sxdw_pdf_xref_free={0x6074006eU,"documentwire_pdf_xref_free",sxdw_pdf_xref_free_fields,SX_COUNT(sxdw_pdf_xref_free_fields),SX_LE};
static const sx_layout*const sx_documentwire_layouts[]={&sxdw_mathcad_header,&sxdw_mathcad_literal_bit0,&sxdw_mathcad_match_bit0,&sxdw_mathcad_end_bit0,&sxdw_mathcad_literal_bit1,&sxdw_mathcad_match_bit1,&sxdw_mathcad_end_bit1,&sxdw_mathcad_literal_bit2,&sxdw_mathcad_match_bit2,&sxdw_mathcad_end_bit2,&sxdw_mathcad_literal_bit3,&sxdw_mathcad_match_bit3,&sxdw_mathcad_end_bit3,&sxdw_mathcad_literal_bit4,&sxdw_mathcad_match_bit4,&sxdw_mathcad_end_bit4,&sxdw_mathcad_literal_bit5,&sxdw_mathcad_match_bit5,&sxdw_mathcad_end_bit5,&sxdw_mathcad_literal_bit6,&sxdw_mathcad_match_bit6,&sxdw_mathcad_end_bit6,&sxdw_mathcad_literal_bit7,&sxdw_mathcad_match_bit7,&sxdw_mathcad_end_bit7,&sxdw_rprj_header,&sxdw_theme_version,&sxdw_theme_name,&sxdw_theme_css,&sxdw_notetab_option,&sxdw_notetab_heading,&sxdw_notetab_body_line,&sxdw_pjl_command,&sxdw_pjl_parameter,&sxdw_pjl_value,&sxdw_pjl_text,&sxdw_theme_member_count,&sxdw_theme_member_size,&sxdw_wrq_record_size,&sxdw_wrq_block_factor,&sxdw_wrq_file_code,&sxdw_wrq_extents,&sxdw_wrq_record_count,&sxdw_theme_payload_marker,&sxdw_notetab_declaration,&sxdw_pjl_uel,&sxdw_wrq_format,&sxdw_ber_short_header,&sxdw_ber_long_header1,&sxdw_ber_long_header2,&sxdw_ber_long_header3,&sxdw_ber_long_header4,&sxdw_ber_signed1,&sxdw_ber_signed2,&sxdw_ber_signed3,&sxdw_ber_signed4,&sxdw_ber_unsigned1,&sxdw_ber_unsigned2,&sxdw_ber_unsigned3,&sxdw_ber_unsigned4,&sxdw_ber_unsigned5,&sxdw_ber_unsigned6,&sxdw_ber_unsigned7,&sxdw_ber_unsigned8,&sxdw_ber_unsigned9,&sxdw_ber_oid_octet,&sxdw_ber_ipv4,&sxdw_ber_octet_text,&sxdw_ssh_identification,&sxdw_ssh_packet_header,&sxdw_ssh_cookie,&sxdw_ssh_string_length,&sxdw_ssh_kex_algorithms,&sxdw_ssh_server_host_key_algorithms,&sxdw_ssh_encryption_client_to_server,&sxdw_ssh_encryption_server_to_client,&sxdw_ssh_mac_client_to_server,&sxdw_ssh_mac_server_to_client,&sxdw_ssh_compression_client_to_server,&sxdw_ssh_compression_server_to_client,&sxdw_ssh_languages_client_to_server,&sxdw_ssh_languages_server_to_client,&sxdw_ssh_kex_tail,&sxdw_text_bom2,&sxdw_text_bom3,&sxdw_text_bom4,&sxdw_text_utf16le,&sxdw_text_utf16be,&sxdw_text_utf32le,&sxdw_text_utf32be,&sxdw_text_line,&sxdw_mime_field_name,&sxdw_mime_field_value,&sxdw_mime_continuation,&sxdw_mime_boundary,&sxdw_pdf_header,&sxdw_pdf_name,&sxdw_pdf_literal_string,&sxdw_pdf_hex_string,&sxdw_pdf_keyword,&sxdw_pdf_integer,&sxdw_pdf_object_id,&sxdw_pdf_generation,&sxdw_pdf_xref_first_object,&sxdw_pdf_xref_count,&sxdw_pdf_stream_length,&sxdw_pdf_offset,&sxdw_pdf_real,&sxdw_pdf_xref_in_use,&sxdw_pdf_xref_free};
static bool sx_documentwire_comment(xx_data_struct_record*r,uint32_t id){if(!r)return false;if(id<0x60740001U||id>=0x60740001U+SX_COUNT(sx_documentwire_layouts))return true;switch(id){
case 0x60740002U:if(!xx_data_struct_record_set_comment(r,L"MSB-first token. The field type records its start bit and width within the preserved physical bytes."))return false;break;
case 0x60740003U:if(!xx_data_struct_record_set_comment(r,L"Ring position is an index in the 4096-byte LZSS dictionary. Match length equals the encoded length_code plus2; neither field is a source-file offset."))return false;break;
case 0x60740004U:if(!xx_data_struct_record_set_comment(r,L"A zero12-bit position following flag0 terminates the compressed stream."))return false;break;
case 0x60740005U:if(!xx_data_struct_record_set_comment(r,L"MSB-first token. The field type records its start bit and width within the preserved physical bytes."))return false;break;
case 0x60740006U:if(!xx_data_struct_record_set_comment(r,L"Ring position is an index in the 4096-byte LZSS dictionary. Match length equals the encoded length_code plus2; neither field is a source-file offset."))return false;break;
case 0x60740007U:if(!xx_data_struct_record_set_comment(r,L"A zero12-bit position following flag0 terminates the compressed stream."))return false;break;
case 0x60740008U:if(!xx_data_struct_record_set_comment(r,L"MSB-first token. The field type records its start bit and width within the preserved physical bytes."))return false;break;
case 0x60740009U:if(!xx_data_struct_record_set_comment(r,L"Ring position is an index in the 4096-byte LZSS dictionary. Match length equals the encoded length_code plus2; neither field is a source-file offset."))return false;break;
case 0x6074000aU:if(!xx_data_struct_record_set_comment(r,L"A zero12-bit position following flag0 terminates the compressed stream."))return false;break;
case 0x6074000bU:if(!xx_data_struct_record_set_comment(r,L"MSB-first token. The field type records its start bit and width within the preserved physical bytes."))return false;break;
case 0x6074000cU:if(!xx_data_struct_record_set_comment(r,L"Ring position is an index in the 4096-byte LZSS dictionary. Match length equals the encoded length_code plus2; neither field is a source-file offset."))return false;break;
case 0x6074000dU:if(!xx_data_struct_record_set_comment(r,L"A zero12-bit position following flag0 terminates the compressed stream."))return false;break;
case 0x6074000eU:if(!xx_data_struct_record_set_comment(r,L"MSB-first token. The field type records its start bit and width within the preserved physical bytes."))return false;break;
case 0x6074000fU:if(!xx_data_struct_record_set_comment(r,L"Ring position is an index in the 4096-byte LZSS dictionary. Match length equals the encoded length_code plus2; neither field is a source-file offset."))return false;break;
case 0x60740010U:if(!xx_data_struct_record_set_comment(r,L"A zero12-bit position following flag0 terminates the compressed stream."))return false;break;
case 0x60740011U:if(!xx_data_struct_record_set_comment(r,L"MSB-first token. The field type records its start bit and width within the preserved physical bytes."))return false;break;
case 0x60740012U:if(!xx_data_struct_record_set_comment(r,L"Ring position is an index in the 4096-byte LZSS dictionary. Match length equals the encoded length_code plus2; neither field is a source-file offset."))return false;break;
case 0x60740013U:if(!xx_data_struct_record_set_comment(r,L"A zero12-bit position following flag0 terminates the compressed stream."))return false;break;
case 0x60740014U:if(!xx_data_struct_record_set_comment(r,L"MSB-first token. The field type records its start bit and width within the preserved physical bytes."))return false;break;
case 0x60740015U:if(!xx_data_struct_record_set_comment(r,L"Ring position is an index in the 4096-byte LZSS dictionary. Match length equals the encoded length_code plus2; neither field is a source-file offset."))return false;break;
case 0x60740016U:if(!xx_data_struct_record_set_comment(r,L"A zero12-bit position following flag0 terminates the compressed stream."))return false;break;
case 0x60740017U:if(!xx_data_struct_record_set_comment(r,L"MSB-first token. The field type records its start bit and width within the preserved physical bytes."))return false;break;
case 0x60740018U:if(!xx_data_struct_record_set_comment(r,L"Ring position is an index in the 4096-byte LZSS dictionary. Match length equals the encoded length_code plus2; neither field is a source-file offset."))return false;break;
case 0x60740019U:if(!xx_data_struct_record_set_comment(r,L"A zero12-bit position following flag0 terminates the compressed stream."))return false;break;
case 0x6074001aU:if(!xx_data_struct_record_set_comment(r,L"Little-endian stored version metadata; future or older versions are preserved."))return false;break;
case 0x6074002bU:if(!xx_data_struct_record_set_comment(r,L"FILESIZE is a record count. Payload byte length equals RECSIZE times FILESIZE."))return false;break;
case 0x6074002cU:if(!xx_data_struct_record_set_comment(r,L"The physical marker is exactly14 ASCII bytes, without a terminating NUL."))return false;break;
case 0x6074002fU:if(!xx_data_struct_record_set_comment(r,L"F denotes fixed-length records."))return false;break;
case 0x60740042U:if(!xx_data_struct_record_set_comment(r,L"High bit continues a base128 subidentifier. The first subidentifier combines the first two OID arcs."))return false;break;
case 0x60740046U:if(!xx_data_struct_record_set_comment(r,L"Packet length excludes its own four bytes and any MAC. Only native-validated initial cleartext packets are walked."))return false;break;
case 0x60740057U:if(!xx_data_struct_record_set_comment(r,L"Original UTF code unit; UTF16 supplementary characters occupy a high/low surrogate pair."))return false;break;
case 0x60740058U:if(!xx_data_struct_record_set_comment(r,L"Original UTF code unit; UTF16 supplementary characters occupy a high/low surrogate pair."))return false;break;
case 0x60740059U:if(!xx_data_struct_record_set_comment(r,L"Original UTF32 Unicode scalar value."))return false;break;
case 0x6074005aU:if(!xx_data_struct_record_set_comment(r,L"Original UTF32 Unicode scalar value."))return false;break;
case 0x6074006dU:if(!xx_data_struct_record_set_comment(r,L"In-use cross-reference entry n; physical file offset is shown in hexadecimal."))return false;break;
case 0x6074006eU:if(!xx_data_struct_record_set_comment(r,L"Free cross-reference entry f; the first field is a linked-list object number, not a file offset."))return false;break;
default:break;}if(!r->name)return true;xx_var_type_t t=xx_var_get_type(&r->value);if(t<XX_VAR_TYPE_INT8||t>XX_VAR_TYPE_UINT64)return true;uint64_t v=xx_var_get_u64(&r->value);const wchar_t*text=NULL;
if(!xx_rt_wcscmp(r->name,L"tag"))switch(v){case 2:text=L"INTEGER";break;case 4:text=L"OCTET STRING";break;case 5:text=L"NULL";break;case 6:text=L"OBJECT IDENTIFIER";break;case 10:text=L"ENUMERATED";break;case 48:text=L"SEQUENCE";break;case 49:text=L"SET";break;case 64:text=L"IpAddress";break;case 65:text=L"Counter32";break;case 66:text=L"Gauge32/Unsigned32";break;case 67:text=L"TimeTicks";break;case 70:text=L"Counter64";break;case 100:text=L"LDAP SearchResultEntry";break;case 101:text=L"LDAP SearchResultDone";break;case 128:text=L"noSuchObject";break;case 129:text=L"noSuchInstance";break;case 130:text=L"endOfMibView";break;case 160:text=L"GetRequest-PDU";break;case 161:text=L"GetNextRequest-PDU";break;case 162:text=L"Response-PDU";break;case 163:text=L"SetRequest-PDU";break;case 165:text=L"GetBulkRequest-PDU";break;case 166:text=L"InformRequest-PDU";break;case 167:text=L"SNMPv2-Trap-PDU";break;case 168:text=L"Report-PDU";break;default:break;}
if(!xx_rt_wcscmp(r->name,L"message_type"))switch(v){case 20:text=L"SSH_MSG_KEXINIT";break;case 30:text=L"SSH_MSG_KEXDH_INIT";break;case 21:text=L"SSH_MSG_NEWKEYS";break;default:break;}return !text||xx_data_struct_record_set_comment(r,text);}

typedef struct sxdw_cursor{sx_context*c;uint8_t*b;int64_t n,p;}sxdw_cursor;
static bool sxdw_emit(sxdw_cursor*q,const sx_layout*l,int64_t at,int64_t n)
{if(at<0||n<=0||at>q->n||n>q->n-at||xx_pd_is_stopped(q->c->pd))return false;if(q->c->count>=32000)return true;return sx_add(q->c,l,at,n);}
static bool sxdw_take_bits(sxdw_cursor*q,uint64_t*bit,unsigned width,uint64_t*v)
{if(*bit>(uint64_t)q->n*8||width>(uint64_t)q->n*8-*bit)return false;*v=0;for(unsigned i=0;i<width;i++){uint64_t b=(*bit)++;*v=(*v<<1)|((q->b[b/8]>>(7-b%8))&1U);}return true;}
static bool sxdw_mathcad(sxdw_cursor*q)
{
 if(q->n<16||xx_rt_memcmp(q->b,".MCDCOMPRESSION",15)||!sxdw_emit(q,&sxdw_mathcad_header,0,15))return false;
 const sx_layout*literal[]={&sxdw_mathcad_literal_bit0,&sxdw_mathcad_literal_bit1,&sxdw_mathcad_literal_bit2,&sxdw_mathcad_literal_bit3,&sxdw_mathcad_literal_bit4,&sxdw_mathcad_literal_bit5,&sxdw_mathcad_literal_bit6,&sxdw_mathcad_literal_bit7};
 const sx_layout*match[]={&sxdw_mathcad_match_bit0,&sxdw_mathcad_match_bit1,&sxdw_mathcad_match_bit2,&sxdw_mathcad_match_bit3,&sxdw_mathcad_match_bit4,&sxdw_mathcad_match_bit5,&sxdw_mathcad_match_bit6,&sxdw_mathcad_match_bit7};
 const sx_layout*stop[]={&sxdw_mathcad_end_bit0,&sxdw_mathcad_end_bit1,&sxdw_mathcad_end_bit2,&sxdw_mathcad_end_bit3,&sxdw_mathcad_end_bit4,&sxdw_mathcad_end_bit5,&sxdw_mathcad_end_bit6,&sxdw_mathcad_end_bit7};
 uint64_t bit=120;while(q->c->count<32000){if(xx_pd_is_stopped(q->c->pd))return false;uint64_t start=bit,flag,pos,n;const sx_layout*l;bool ended=false;
  if(!sxdw_take_bits(q,&bit,1,&flag))break;if(flag){if(!sxdw_take_bits(q,&bit,8,&n))break;l=literal[start%8];}
  else{if(!sxdw_take_bits(q,&bit,12,&pos))break;if(!pos){l=stop[start%8];ended=true;}else{if(!sxdw_take_bits(q,&bit,4,&n))break;l=match[start%8];}}
  if(!sxdw_emit(q,l,(int64_t)(start/8),(int64_t)((bit+7)/8-start/8)))return false;if(ended)return true;
 }return true;
}

/* Preserve actual wire spans; delimiters and stored bodies remain RAW_DATA. */
static bool sxdw_value(sxdw_cursor*q,const sx_layout*l,int64_t at,int64_t n)
{
 if(!n)return true;if(at<0||n<0||at>q->n||n>q->n-at)return false;
 int64_t limit=!xx_rt_wcscmp(l->fields[0].type,L"ascii_signed")?128:4096;
 if(limit==128&&n>limit)return true;
 while(n&&q->c->count<32000){int64_t take=n<limit?n:limit;if(take<n&&!xx_rt_wcscmp(l->fields[0].type,L"utf8")){int64_t aligned=take;while(aligned>0&&(q->b[at+aligned]&192)==128)aligned--;if(aligned)take=aligned;}if(!sxdw_emit(q,l,at,take))return false;at+=take;n-=take;}return true;
}
#define DW_VALUE(name,a,n) sxdw_value(q,&sxdw_##name,a,n)
static bool sxdw_line(sxdw_cursor*q,int64_t*start,int64_t*end)
{
 if(q->p>=q->n||xx_pd_is_stopped(q->c->pd))return false;*start=q->p;
 while(q->p<q->n&&q->b[q->p]!='\r'&&q->b[q->p]!='\n')q->p++;
 *end=q->p;if(q->p<q->n){uint8_t c=q->b[q->p++];if(q->p<q->n&&((c=='\r'&&q->b[q->p]=='\n')||(c=='\n'&&q->b[q->p]=='\r')))q->p++;}return true;
}
static bool sxdw_decimal(sxdw_cursor*q,int64_t at,int64_t end,uint64_t*v)
{
 *v=0;if(at>=end||at<0||end>q->n)return false;
 for(;at<end;at++){uint8_t c=q->b[at];if(c<'0'||c>'9'||*v>((uint64_t)INT64_MAX-(c-'0'))/10)return false;*v=*v*10+c-'0';}return true;
}
static bool sxdw_prefix(sxdw_cursor*q,int64_t at,int64_t end,const char*text)
{size_t n=xx_rt_strlen(text);return at>=0&&end<=q->n&&at<=end&&(uint64_t)(end-at)>=n&&!xx_rt_memcmp(q->b+at,text,n);}
static bool sxdw_theme(sxdw_cursor*q,bool elm)
{
 int64_t a,e;uint64_t count;if(!sxdw_line(q,&a,&e)||!DW_VALUE(theme_version,a,e-a)||!sxdw_line(q,&a,&e)||!sxdw_decimal(q,a,e,&count)||count>65536||!DW_VALUE(theme_member_count,a,e-a))return false;
 uint64_t*sizes=xx_mem_alloc((size_t)(count?count:1)*sizeof(*sizes));if(!sizes)return false;bool ok=true;
 for(uint64_t i=0;i<count&&ok;i++){if(!sxdw_line(q,&a,&e)){ok=false;break;}int64_t comma=a;while(comma<e&&q->b[comma]!=',')comma++;
  ok=comma<e&&sxdw_decimal(q,comma+1,e,&sizes[i])&&DW_VALUE(theme_name,a,comma-a)&&DW_VALUE(theme_member_size,comma+1,e-comma-1);}
 for(uint64_t i=0;i<count&&ok;i++){ok=q->n-q->p>=14&&!xx_rt_memcmp(q->b+q->p,"<==MS-Theme==>",14)&&sxdw_emit(q,&sxdw_theme_payload_marker,q->p,14);if(ok){q->p+=14;ok=sizes[i]<=(uint64_t)(q->n-q->p);if(ok)q->p+=(int64_t)sizes[i];}}
 xx_mem_free(sizes);if(ok&&elm&&q->p<q->n)ok=DW_VALUE(theme_css,q->p,q->n-q->p);return ok;
}
static bool sxdw_wrq(sxdw_cursor*q)
{
 const char*keys[]={"RECSIZE=","BLOCKFACTOR=","CODE=","EXTENTS=","FILESIZE=","FORMAT="};
 const sx_layout*fields[]={&sxdw_wrq_record_size,&sxdw_wrq_block_factor,&sxdw_wrq_file_code,&sxdw_wrq_extents,&sxdw_wrq_record_count};
 for(unsigned i=0;i<6;i++){size_t k=xx_rt_strlen(keys[i]);if(!sxdw_prefix(q,q->p,q->n,keys[i]))return false;q->p+=(int64_t)k;if(i==5)return sxdw_emit(q,&sxdw_wrq_format,q->p,1);
  int64_t a=q->p;while(q->p<q->n&&q->b[q->p]>='0'&&q->b[q->p]<='9')q->p++;uint64_t value;if(!sxdw_decimal(q,a,q->p,&value)||!sxdw_value(q,fields[i],a,q->p-a)||q->p>=q->n||q->b[q->p++]!=';')return false;
 }return true;
}
static bool sxdw_notetab(sxdw_cursor*q)
{
 int64_t a,e;if(!sxdw_line(q,&a,&e)||e<5||!sxdw_emit(q,&sxdw_notetab_declaration,0,4)||!DW_VALUE(notetab_option,5,e-5)||!sxdw_line(q,&a,&e))return false;
 int64_t body=q->p;bool quoted=false;while(sxdw_line(q,&a,&e))if(sxdw_prefix(q,a,e,"H=\"")){quoted=true;break;}q->p=body;bool heading=false;
 while(q->c->count<32000&&sxdw_line(q,&a,&e)){int64_t tag=quoted?3:2;if(sxdw_prefix(q,a,e,quoted?"H=\"":"H=")){int64_t end=e;if(quoted&&end>a+tag&&q->b[end-1]=='"')end--;if(!DW_VALUE(notetab_heading,a+tag,end-a-tag))return false;heading=true;}
  else if(heading&&!DW_VALUE(notetab_body_line,a,e-a))return false;}return !xx_pd_is_stopped(q->c->pd);
}
static bool sxdw_pjl(sxdw_cursor*q)
{
 int64_t end=9;while(end<q->n&&q->b[end])end++;int64_t total=q->n;q->n=end;q->p=0;
 while(q->p<q->n&&q->c->count<32000){if(sxdw_prefix(q,q->p,q->n,"\033%-12345X")){if(!sxdw_emit(q,&sxdw_pjl_uel,q->p,9))return false;q->p+=9;continue;}
  int64_t a,e;if(!sxdw_line(q,&a,&e))break;if(sxdw_prefix(q,a,e,"@PJL")){int64_t p=a+4;while(p<e&&(q->b[p]==' '||q->b[p]=='\t'))p++;int64_t b=p;while(p<e&&q->b[p]!=' '&&q->b[p]!='\t')p++;if(!DW_VALUE(pjl_command,b,p-b))return false;
   while(p<e){while(p<e&&(q->b[p]==' '||q->b[p]=='\t'))p++;b=p;while(p<e&&q->b[p]!='='&&q->b[p]!=' '&&q->b[p]!='\t')p++;if(!DW_VALUE(pjl_parameter,b,p-b))return false;while(p<e&&(q->b[p]==' '||q->b[p]=='\t'))p++;if(p<e&&q->b[p]=='='){p++;while(p<e&&(q->b[p]==' '||q->b[p]=='\t'))p++;b=p;if(p<e&&q->b[p]=='"'){p++;while(p<e&&q->b[p]!='"')p++;if(p<e)p++;}else while(p<e&&q->b[p]!=' '&&q->b[p]!='\t')p++;if(!DW_VALUE(pjl_value,b,p-b))return false;}if(p==b&&p<e)p++;}
  }else if(!DW_VALUE(pjl_text,a,e-a))return false;
 }q->n=total;return !xx_pd_is_stopped(q->c->pd);
}
#undef DW_VALUE

/* RFC3416, RFC4511 and RFC4253; native grammar gating precedes this walker. */
static bool sxdw_ber(sxdw_cursor*q,int64_t p,int64_t end,unsigned depth)
{
 if(depth>32||p<0||end>q->n||p>end)return false;
 const sx_layout*heads[]={&sxdw_ber_short_header,&sxdw_ber_long_header1,&sxdw_ber_long_header2,&sxdw_ber_long_header3,&sxdw_ber_long_header4};
 const sx_layout*signs[]={&sxdw_ber_signed1,&sxdw_ber_signed2,&sxdw_ber_signed3,&sxdw_ber_signed4};
 const sx_layout*unsigns[]={&sxdw_ber_unsigned1,&sxdw_ber_unsigned2,&sxdw_ber_unsigned3,&sxdw_ber_unsigned4,&sxdw_ber_unsigned5,&sxdw_ber_unsigned6,&sxdw_ber_unsigned7,&sxdw_ber_unsigned8,&sxdw_ber_unsigned9};
 while(p<end&&q->c->count<32000){if(end-p<2)return false;int64_t start=p;uint8_t tag=q->b[p++],len=q->b[p++];unsigned width=0;uint64_t n=len;
  if((tag&31)==31||!tag)return false;if(len&128){width=len&127;if(!width||width>4||(int64_t)width>end-p)return false;n=0;for(unsigned i=0;i<width;i++)n=(n<<8)|q->b[p++];}
  if(n>(uint64_t)(end-p)||!sxdw_emit(q,heads[width],start,p-start))return false;int64_t next=p+(int64_t)n;
  if(tag&32){if(!sxdw_ber(q,p,next,depth+1))return false;}
  else if((tag==2||tag==10)&&n>0&&n<=4){if(!sxdw_emit(q,signs[n-1],p,(int64_t)n))return false;}
  else if((tag==65||tag==66||tag==67||tag==70)&&n>0&&n<=9){if(!sxdw_emit(q,unsigns[n-1],p,(int64_t)n))return false;}
  else if(tag==64&&n==4){if(!sxdw_emit(q,&sxdw_ber_ipv4,p,4))return false;}
  else if(tag==6){for(int64_t k=p;k<next&&q->c->count<32000;k++)if(!sxdw_emit(q,&sxdw_ber_oid_octet,k,1))return false;}
  else if(tag==4&&n){bool text=true;for(int64_t k=p;k<next;k++)if(q->b[k]<32||q->b[k]>126){text=false;break;}if(text&&!sxdw_value(q,&sxdw_ber_octet_text,p,(int64_t)n))return false;}
  p=next;
 }return !xx_pd_is_stopped(q->c->pd);
}
static bool sxdw_ssh(sxdw_cursor*q)
{
 int64_t a,e;if(!sxdw_line(q,&a,&e)||!sxdw_value(q,&sxdw_ssh_identification,a,e-a))return false;
 const sx_layout*lists[]={&sxdw_ssh_kex_algorithms,&sxdw_ssh_server_host_key_algorithms,&sxdw_ssh_encryption_client_to_server,&sxdw_ssh_encryption_server_to_client,&sxdw_ssh_mac_client_to_server,&sxdw_ssh_mac_server_to_client,&sxdw_ssh_compression_client_to_server,&sxdw_ssh_compression_server_to_client,&sxdw_ssh_languages_client_to_server,&sxdw_ssh_languages_server_to_client};
 while(q->p<q->n&&q->c->count<32000){int64_t start=q->p;if(q->n-start<6)return false;uint64_t n=xx_data_get_u32(q->b+start,4,0,true);unsigned pad=q->b[start+4],type=q->b[start+5];if(n<2||pad>=n-1||n>(uint64_t)(q->n-start-4)||!sxdw_emit(q,&sxdw_ssh_packet_header,start,6))return false;
  int64_t end=start+4+(int64_t)n-pad;q->p=start+6;
  if(type==20){if(end-q->p<16||!sxdw_emit(q,&sxdw_ssh_cookie,q->p,16))return false;q->p+=16;
   for(unsigned i=0;i<10;i++){if(end-q->p<4)return false;uint32_t z=xx_data_get_u32(q->b+q->p,4,0,true);if(!sxdw_emit(q,&sxdw_ssh_string_length,q->p,4))return false;q->p+=4;if(z>(uint64_t)(end-q->p)||!sxdw_value(q,lists[i],q->p,z))return false;q->p+=z;}
   if(end-q->p!=5||!sxdw_emit(q,&sxdw_ssh_kex_tail,q->p,5))return false;
  }else if(type==30){if(end-q->p<4||!sxdw_emit(q,&sxdw_ssh_string_length,q->p,4))return false;}
  q->p=start+4+(int64_t)n;
 }return !xx_pd_is_stopped(q->c->pd);
}

static bool sxdw_text(sxdw_cursor*q)
{
 /* Read the common validated metadata; never downcast a factory wrapper. */
 const char*v=xx_format_get_version(q->c->f);unsigned width=1,bom=0;const sx_layout*l=NULL;
 if(v&&!xx_rt_strcmp(v,"UTF-16LE")){width=2;l=&sxdw_text_utf16le;}
 else if(v&&!xx_rt_strcmp(v,"UTF-16BE")){width=2;l=&sxdw_text_utf16be;}
 else if(v&&!xx_rt_strcmp(v,"UTF-32LE")){width=4;l=&sxdw_text_utf32le;}
 else if(v&&!xx_rt_strcmp(v,"UTF-32BE")){width=4;l=&sxdw_text_utf32be;}
 if(width==4&&q->n>=4&&((q->b[0]==255&&q->b[1]==254&&!q->b[2]&&!q->b[3])||(!q->b[0]&&!q->b[1]&&q->b[2]==254&&q->b[3]==255)))bom=4;
 else if(width==2&&q->n>=2&&((q->b[0]==255&&q->b[1]==254)||(q->b[0]==254&&q->b[1]==255)))bom=2;
 else if(width==1&&q->n>=3&&q->b[0]==239&&q->b[1]==187&&q->b[2]==191)bom=3;
 if(bom&&!sxdw_emit(q,bom==2?&sxdw_text_bom2:bom==3?&sxdw_text_bom3:&sxdw_text_bom4,0,bom))return false;q->p=bom;
 if(width>1){while(q->p<q->n&&q->c->count<32000){if(!sxdw_emit(q,l,q->p,width))return false;q->p+=width;}}
 else{int64_t a,e;while(q->c->count<32000&&sxdw_line(q,&a,&e))if(!sxdw_value(q,&sxdw_text_line,a,q->p-a))return false;}
 return !xx_pd_is_stopped(q->c->pd);
}
static bool sxdw_ci(const uint8_t*b,int64_t n,const char*s)
{size_t z=xx_rt_strlen(s);if(n<0||(uint64_t)n!=z)return false;for(size_t i=0;i<z;i++){uint8_t c=b[i],d=(uint8_t)s[i];if(c>='A'&&c<='Z')c+=32;if(d>='A'&&d<='Z')d+=32;if(c!=d)return false;}return true;}
static bool sxdw_mime_parameter(const char*field,const char*key,char*out,size_t cap)
{
 size_t p=0,n=xx_rt_strlen(field);while(p<n){while(p<n&&field[p]!=';')p++;if(p==n)break;p++;while(p<n&&(field[p]==' '||field[p]=='\t'))p++;size_t a=p;while(p<n&&field[p]!='='&&field[p]!=';'&&field[p]!=' '&&field[p]!='\t')p++;bool wanted=sxdw_ci((const uint8_t*)field+a,(int64_t)(p-a),key);while(p<n&&(field[p]==' '||field[p]=='\t'))p++;if(p==n||field[p]!='=')continue;p++;while(p<n&&(field[p]==' '||field[p]=='\t'))p++;bool quoted=p<n&&field[p]=='"';if(quoted)p++;size_t used=0;
  while(p<n&&(quoted?field[p]!='"':field[p]!=';'&&field[p]!=' '&&field[p]!='\t')){char c=field[p++];if(quoted&&c=='\\'){if(p==n)return false;c=field[p++];}if(wanted){if((unsigned char)c<32||used+1>=cap)return false;out[used++]=c;}}
  if(wanted){if(quoted&&(p==n||field[p]!='"'))return false;out[used]=0;return used!=0;}if(quoted&&p<n)p++;
 }return false;
}
static bool sxdw_mime(sxdw_cursor*q,int64_t start,int64_t end,unsigned depth)
{
 if(depth>32||start<0||end>q->n||start>=end)return false;int64_t save_n=q->n;q->n=end;q->p=start;char type[1024]={0},encoding[128]={0};char*target=NULL;size_t cap=0;
 int64_t a,e;bool blank=false;
 while(q->c->count<32000&&sxdw_line(q,&a,&e)){if(a==e){blank=true;break;}int64_t val=a;
  bool continuation=q->b[a]==' '||q->b[a]=='\t';if(continuation){if(!sxdw_value(q,&sxdw_mime_continuation,a,e-a))return false;}
  else{int64_t colon=a;while(colon<e&&q->b[colon]!=':')colon++;if(colon==a||colon==e)return false;if(!sxdw_value(q,&sxdw_mime_field_name,a,colon-a))return false;val=colon+1;if(!sxdw_value(q,&sxdw_mime_field_value,val,e-val))return false;target=NULL;cap=0;if(sxdw_ci(q->b+a,colon-a,"content-type")){target=type;cap=sizeof(type);}else if(sxdw_ci(q->b+a,colon-a,"content-transfer-encoding")){target=encoding;cap=sizeof(encoding);}}
  while(val<e&&(q->b[val]==' '||q->b[val]=='\t'))val++;int64_t trim=e;while(trim>val&&(q->b[trim-1]==' '||q->b[trim-1]=='\t'))trim--;
  if(target){size_t used=continuation?xx_rt_strlen(target):0;if(continuation&&used+1<cap)target[used++]=' ';if((uint64_t)(trim-val)>=cap-used)return false;xx_rt_memcpy(target+used,q->b+val,(size_t)(trim-val));target[used+(size_t)(trim-val)]=0;}
 }
 if(!blank){q->n=save_n;return q->c->count>=32000;}int64_t body=q->p;
 if(xx_rt_strlen(type)>10&&sxdw_ci((const uint8_t*)type,10,"multipart/")){char boundary[256];if(!sxdw_mime_parameter(type,"boundary",boundary,sizeof(boundary)))return false;size_t length=xx_rt_strlen(boundary);int64_t part=-1;bool closed=false;
  while(q->c->count<32000&&sxdw_line(q,&a,&e)){if(e-a<(int64_t)length+2||q->b[a]!='-'||q->b[a+1]!='-'||xx_rt_memcmp(q->b+a+2,boundary,length))continue;int64_t p=a+2+(int64_t)length;bool closing=p+2<=e&&q->b[p]=='-'&&q->b[p+1]=='-';if(closing)p+=2;while(p<e&&(q->b[p]==' '||q->b[p]=='\t'))p++;if(p!=e)continue;int64_t next=q->p;if(!sxdw_value(q,&sxdw_mime_boundary,a,e-a))return false;
   if(part>=0){int64_t stop=a;if(stop>part&&q->b[stop-1]=='\n'){stop--;if(stop>part&&q->b[stop-1]=='\r')stop--;}if(!sxdw_mime(q,part,stop,depth+1))return false;}q->n=end;q->p=next;if(closing){closed=true;break;}part=next;
  }if(!closed&&q->c->count<32000)return false;
 }else if(xx_rt_strlen(type)>=14&&sxdw_ci((const uint8_t*)type,14,"message/rfc822")&&(!encoding[0]||sxdw_ci((const uint8_t*)encoding,(int64_t)xx_rt_strlen(encoding),"7bit")||sxdw_ci((const uint8_t*)encoding,(int64_t)xx_rt_strlen(encoding),"8bit")||sxdw_ci((const uint8_t*)encoding,(int64_t)xx_rt_strlen(encoding),"binary"))){if(body<end&&!sxdw_mime(q,body,end,depth+1))return false;}
 q->n=save_n;return !xx_pd_is_stopped(q->c->pd);
}

typedef struct sxdw_pdf_span{int64_t at,end;}sxdw_pdf_span;
static int sxdw_pdf_span_order(const void*a,const void*b){const sxdw_pdf_span*x=a,*y=b;return x->at<y->at?-1:x->at>y->at?1:x->end<y->end?-1:x->end>y->end?1:0;}
static bool sxdw_pdf_space(uint8_t c){return !c||c==9||c==10||c==12||c==13||c==32;}
static bool sxdw_pdf_delim(uint8_t c){return sxdw_pdf_space(c)||c=='('||c==')'||c=='<'||c=='>'||c=='['||c==']'||c=='{'||c=='}'||c=='/'||c=='%';}
static int64_t sxdw_pdf_skip(sxdw_cursor*q,int64_t p){for(;;){while(p<q->n&&sxdw_pdf_space(q->b[p]))p++;if(p<q->n&&q->b[p]=='%'){while(p<q->n&&q->b[p]!=10&&q->b[p]!=13)p++;}else break;}return p;}
static bool sxdw_pdf_number(sxdw_cursor*q,int64_t a,int64_t e,bool*real)
{
 *real=false;if(a<e&&(q->b[a]=='+'||q->b[a]=='-'))a++;bool digit=false;for(;a<e;a++){if(q->b[a]=='.'&&!*real)*real=true;else if(q->b[a]>='0'&&q->b[a]<='9')digit=true;else return false;}return digit;
}
static bool sxdw_pdf(sxdw_cursor*q)
{
 sxdw_pdf_span*spans=NULL;size_t count=0,capacity=0,index=0;bool ok=true;Abstractformat*f=q->c->f;
 if(!f->handle_base_info||!f->handle_base_info(f,q->c->pd)||!f->is_valid)return false;
 xx_archive_record_state*s=xx_format_create_archive_records_reading(f,NULL,q->c->pd);if(!s)return false;
 for(size_t work=0;work<65536;work++){const xx_archive_record*r=xx_format_get_current_archive_record(f,s);if(!r)break;if(r->data_offset<f->base_address||r->compressed_size<0){ok=false;break;}int64_t a=r->data_offset-f->base_address,n=r->compressed_size;if(a>q->n||n>q->n-a){ok=false;break;}
  if(count==capacity){size_t cap=capacity?capacity*2:16;sxdw_pdf_span*grown=xx_mem_realloc(spans,cap*sizeof(*spans));if(!grown){ok=false;break;}spans=grown;capacity=cap;}spans[count++]=(sxdw_pdf_span){a,a+n};if(!xx_format_archive_record_move_to_next(f,s,q->c->pd))break;
 }
 xx_format_free_archive_records_reading(f,s);if(!ok){xx_mem_free(spans);return false;}xx_rt_qsort(spans,count,sizeof(*spans),sxdw_pdf_span_order);
 int64_t p=0;while(p+8<=q->n&&p<=1024&&!sxdw_prefix(q,p,q->n,"%PDF-"))p++;
 if(p>1024||q->n-p<8||!sxdw_emit(q,&sxdw_pdf_header,p,8)){xx_mem_free(spans);return false;}p+=8;bool want_offset=false;const sx_layout*number_layout=&sxdw_pdf_integer;
 while(p<q->n&&q->c->count<32000&&ok){if(xx_pd_is_stopped(q->c->pd)){ok=false;break;}while(index<count&&spans[index].end<=p)index++;if(index<count&&p>=spans[index].at&&p<spans[index].end){p=spans[index].end;continue;}
  uint8_t c=q->b[p];if(sxdw_pdf_space(c)){p++;continue;}if(c=='%'){while(p<q->n&&q->b[p]!=10&&q->b[p]!=13)p++;continue;}int64_t a=p;
  if((c=='<'||c=='>')&&p+1<q->n&&q->b[p+1]==c){p+=2;continue;}
  if(c=='('){unsigned depth=1;p++;while(p<q->n&&depth){uint8_t x=q->b[p++];if(x=='\\'){if(p<q->n){uint8_t y=q->b[p++];if(y==13&&p<q->n&&q->b[p]==10)p++;}}else if(x=='(')depth++;else if(x==')')depth--;if(depth>128)break;}if(depth)break;ok=sxdw_value(q,&sxdw_pdf_literal_string,a,p-a);number_layout=&sxdw_pdf_integer;continue;}
  if(c=='<'&&p+1<q->n&&q->b[p+1]!='<'){p++;while(p<q->n&&q->b[p]!='>')p++;if(p==q->n)break;p++;ok=sxdw_value(q,&sxdw_pdf_hex_string,a,p-a);number_layout=&sxdw_pdf_integer;continue;}
  if(c=='/'){p++;while(p<q->n&&!sxdw_pdf_delim(q->b[p]))p++;ok=sxdw_value(q,&sxdw_pdf_name,a,p-a);number_layout=sxdw_prefix(q,a,p,"/Length")&&p-a==7?&sxdw_pdf_stream_length:((p-a==5&&sxdw_prefix(q,a,p,"/Prev"))||(p-a==8&&sxdw_prefix(q,a,p,"/XRefStm")))?&sxdw_pdf_offset:&sxdw_pdf_integer;continue;}
  if(sxdw_pdf_delim(c)){p++;continue;}while(p<q->n&&!sxdw_pdf_delim(q->b[p]))p++;bool real=false;
  if(sxdw_pdf_number(q,a,p,&real)){int64_t first_end=p,b=sxdw_pdf_skip(q,p),z=b;while(z<q->n&&!sxdw_pdf_delim(q->b[z]))z++;bool real2=false;int64_t obj=sxdw_pdf_skip(q,z);
   unsigned token=0;if(obj+3<=q->n&&!xx_rt_memcmp(q->b+obj,"obj",3)&&(obj+3==q->n||sxdw_pdf_delim(q->b[obj+3])))token=3;else if(obj<q->n&&q->b[obj]=='R'&&(obj+1==q->n||sxdw_pdf_delim(q->b[obj+1])))token=1;uint64_t object_id,generation;
   if(token&&!real&&sxdw_pdf_number(q,b,z,&real2)&&!real2&&sxdw_decimal(q,a,first_end,&object_id)&&sxdw_decimal(q,b,z,&generation)){ok=sxdw_value(q,&sxdw_pdf_object_id,a,first_end-a)&&sxdw_value(q,&sxdw_pdf_generation,b,z-b)&&sxdw_value(q,&sxdw_pdf_keyword,obj,token);p=obj+token;}
   else ok=sxdw_value(q,want_offset?&sxdw_pdf_offset:real?&sxdw_pdf_real:number_layout,a,p-a);
   want_offset=false;number_layout=&sxdw_pdf_integer;continue;
  }
  ok=sxdw_value(q,&sxdw_pdf_keyword,a,p-a);number_layout=&sxdw_pdf_integer;
  if(p-a==9&&!xx_rt_memcmp(q->b+a,"startxref",9)){want_offset=true;continue;}
  if(p-a==6&&!xx_rt_memcmp(q->b+a,"stream",6)){int64_t data=p;if(data<q->n&&q->b[data]==13){data++;if(data<q->n&&q->b[data]==10)data++;}else if(data<q->n&&q->b[data]==10)data++;while(index<count&&spans[index].at<data)index++;if(index>=count||spans[index].at!=data)break;p=spans[index].end;continue;}
  if(p-a==4&&!xx_rt_memcmp(q->b+a,"xref",4)){
   for(;;){int64_t x=sxdw_pdf_skip(q,p),e=x;while(e<q->n&&q->b[e]!=10&&q->b[e]!=13)e++;int64_t sep=x;while(sep<e&&q->b[sep]>='0'&&q->b[sep]<='9')sep++;int64_t y=sep;while(y<e&&(q->b[y]==' '||q->b[y]=='\t'))y++;int64_t last=y;while(last<e&&q->b[last]>='0'&&q->b[last]<='9')last++;uint64_t first,n;if(!sxdw_decimal(q,x,sep,&first)||!sxdw_decimal(q,y,last,&n)||n>32000)break;int64_t trail=last;while(trail<e&&(q->b[trail]==' '||q->b[trail]=='\t'))trail++;if(trail!=e)break;
    if(!sxdw_value(q,&sxdw_pdf_xref_first_object,x,sep-x)||!sxdw_value(q,&sxdw_pdf_xref_count,y,last-y)){ok=false;break;}p=e;if(p<q->n&&q->b[p]==13)p++;if(p<q->n&&q->b[p]==10)p++;
    for(uint64_t i=0;i<n&&q->c->count<32000;i++){if(q->n-p<20){ok=false;break;}uint64_t off,gen;if(!sxdw_decimal(q,p,p+10,&off)||q->b[p+10]!=' '||!sxdw_decimal(q,p+11,p+16,&gen)||q->b[p+16]!=' '||(q->b[p+17]!='n'&&q->b[p+17]!='f')||!sxdw_emit(q,q->b[p+17]=='n'?&sxdw_pdf_xref_in_use:&sxdw_pdf_xref_free,p,20)){ok=false;break;}p+=20;}
    if(!ok||q->c->count>=32000)break;
   }
  }
 }
 xx_mem_free(spans);return ok;
}

static int sxdw_order(const void *a,const void *b){const xx_data_struct *x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:x->total_size<y->total_size?-1:x->total_size>y->total_size?1:x->id<y->id?-1:x->id>y->id?1:0;}
static bool sxdw_finish(sx_context *c)
{
 size_t n=c->count,keep=0;if(!n)return false;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxdw_order);
 /* Resources can share physical extents. Keep one identical physical view,
  * preserve distinct aliased interpretations and fill only uncovered gaps. */
 for(size_t i=0;i<n;i++){
  xx_data_struct d=c->items[i];if(keep){const xx_data_struct *p=&c->items[keep-1];if(d.offset==p->offset&&d.total_size==p->total_size&&d.entry_size==p->entry_size&&d.count==p->count&&d.id==p->id)continue;}
  c->items[keep++]=d;
 }c->count=n=keep;
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,bytes=c->items[i].total_size;if(at>end&&!sx_raw(c,end,at-end))return false;if(at+bytes>end)end=at+bytes;}
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxdw_order);return !c->failed&&!xx_pd_is_stopped(c->pd);
}


static bool sx_documentwire_supports(xx_file_type_t t){switch(t){case XX_FILE_TYPE_MATHCAD:case XX_FILE_TYPE_RPRJ:case XX_FILE_TYPE_FRONTPAGETHEME:case XX_FILE_TYPE_ELM:case XX_FILE_TYPE_NOTETAB:case XX_FILE_TYPE_PJL:case XX_FILE_TYPE_HP3000_WRQ:case XX_FILE_TYPE_SNMP_MESSAGE:case XX_FILE_TYPE_LDAP_MESSAGE:case XX_FILE_TYPE_SSH_TRANSPORT:case XX_FILE_TYPE_TEXT:case XX_FILE_TYPE_MIME_MESSAGE:case XX_FILE_TYPE_PDF:return true;default:return false;}}
static bool sx_documentwire_build(sx_context*c){
 if(!c||!c->f||c->size<1||c->size>33554432||xx_pd_is_stopped(c->pd))return false;
 if((!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;
 uint8_t*b=xx_mem_alloc((size_t)c->size);if(!b)return false;bool ok=sx_read(c,0,b,(size_t)c->size);sxdw_cursor cursor={c,b,c->size,0},*q=&cursor;xx_file_type_t type=c->f->file_type;
 if(ok)switch(type){case XX_FILE_TYPE_MATHCAD:ok=sxdw_mathcad(q);break;case XX_FILE_TYPE_RPRJ:ok=sxdw_emit(q,&sxdw_rprj_header,0,8);break;case XX_FILE_TYPE_FRONTPAGETHEME:ok=sxdw_theme(q,false);break;case XX_FILE_TYPE_ELM:ok=sxdw_theme(q,true);break;case XX_FILE_TYPE_NOTETAB:ok=sxdw_notetab(q);break;case XX_FILE_TYPE_PJL:ok=sxdw_pjl(q);break;case XX_FILE_TYPE_HP3000_WRQ:ok=sxdw_wrq(q);break;case XX_FILE_TYPE_SNMP_MESSAGE:ok=sxdw_ber(q,0,q->n,0);break;case XX_FILE_TYPE_LDAP_MESSAGE:ok=sxdw_ber(q,0,q->n,0);break;case XX_FILE_TYPE_SSH_TRANSPORT:ok=sxdw_ssh(q);break;case XX_FILE_TYPE_TEXT:ok=sxdw_text(q);break;case XX_FILE_TYPE_MIME_MESSAGE:ok=sxdw_mime(q,0,q->n,0);break;case XX_FILE_TYPE_PDF:ok=sxdw_pdf(q);break;default:ok=false;break;}
 xx_mem_free(b);return ok&&sxdw_finish(c);}
#undef TW_VALUE
#undef TW_EMIT
