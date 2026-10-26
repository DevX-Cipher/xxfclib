/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The textwire schema family: what its family unit (xx_format_schema_textwire.c)
 * and its formats' data files share. Formats: http1_message; sip_message; rtsp_message; redis_resp; stomp_frames; smtp_transcript; bittorrent_metainfo; base16; base64; pem; android_ab; age_encrypted; jose_jws; putty_ppk; srec; ihex; debugscr; gdbm_dump; mtree; safetensors; svg; dec_sixel; gitobject; gpgsigned. */
#ifndef XX_FORMAT_SCHEMA_TEXTWIRE_H
#define XX_FORMAT_SCHEMA_TEXTWIRE_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

typedef struct sxtw_cursor {sx_context*c;uint8_t*b;int64_t n,p;}sxtw_cursor;

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxtw_signature;
extern const sx_layout sxtw_version;
extern const sx_layout sxtw_field_name;
extern const sx_layout sxtw_field_value;
extern const sx_layout sxtw_name;
extern const sx_layout sxtw_path;
extern const sx_layout sxtw_key;
extern const sx_layout sxtw_text;
extern const sx_layout sxtw_command;
extern const sx_layout sxtw_encryption;
extern const sx_layout sxtw_algorithm;
extern const sx_layout sxtw_base64_text;
extern const sx_layout sxtw_base64url_header;
extern const sx_layout sxtw_base64url_payload;
extern const sx_layout sxtw_base64url_signature;
extern const sx_layout sxtw_mac_text;
extern const sx_layout sxtw_octal_mode;
extern const sx_layout sxtw_type_name;
extern const sx_layout sxtw_time_text;
extern const sx_layout sxtw_xml_element;
extern const sx_layout sxtw_xml_attribute;
extern const sx_layout sxtw_json_key;
extern const sx_layout sxtw_json_string;
extern const sx_layout sxtw_tensor_dtype;
extern const sx_layout sxtw_recipient_type;
extern const sx_layout sxtw_encoded_public_key;
extern const sx_layout sxtw_encoded_wrapped_key;
extern const sx_layout sxtw_encoded_header_mac;
extern const sx_layout sxtw_content_length;
extern const sx_layout sxtw_byte_length;
extern const sx_layout sxtw_declared_size;
extern const sx_layout sxtw_backup_version;
extern const sx_layout sxtw_compression;
extern const sx_layout sxtw_array_count;
extern const sx_layout sxtw_integer_value;
extern const sx_layout sxtw_line_count;
extern const sx_layout sxtw_uid;
extern const sx_layout sxtw_gid;
extern const sx_layout sxtw_inode;
extern const sx_layout sxtw_link_count;
extern const sx_layout sxtw_checksum_decimal;
extern const sx_layout sxtw_shape_dimension;
extern const sx_layout sxtw_sixel_parameter;
extern const sx_layout sxtw_aspect_numerator;
extern const sx_layout sxtw_aspect_denominator;
extern const sx_layout sxtw_width;
extern const sx_layout sxtw_height;
extern const sx_layout sxtw_color_register;
extern const sx_layout sxtw_color_mode;
extern const sx_layout sxtw_red_percent;
extern const sx_layout sxtw_green_percent;
extern const sx_layout sxtw_blue_percent;
extern const sx_layout sxtw_repeat_count;
extern const sx_layout sxtw_record_count;
extern const sx_layout sxtw_address_hex;
extern const sx_layout sxtw_tensor_data_offset;
extern const sx_layout sxtw_hex_byte;
extern const sx_layout sxtw_hex_size;
extern const sx_layout sxtw_binary_nonce;
extern const sx_layout sxtw_sixel_symbol;
extern const sx_layout sxtw_control;
extern const sx_layout sxtw_safetensors_header;
bool sxtw_space(unsigned x);
bool sxtw_eq(sxtw_cursor*q,int64_t a,int64_t n,const char*s);
bool sxtw_ci(sxtw_cursor*q,int64_t a,int64_t n,const char*s);
bool sxtw_emit(sxtw_cursor*q,const sx_layout*l,int64_t a,int64_t n);
bool sxtw_line(sxtw_cursor*q,int64_t*a,int64_t*end);
void sxtw_trim(sxtw_cursor*q,int64_t*a,int64_t*end);
bool sxtw_number(sxtw_cursor*q,int64_t a,int64_t n,unsigned radix,uint64_t*out);
bool sxtw_headers(sxtw_cursor*q,bool http);
bool sxtw_hex_records(sxtw_cursor*q,bool intel);
bool sxtw_base64(sxtw_cursor*q,bool pem);
bool sxtw_carrier(sxtw_cursor*q,bool git);

/* Per-format walkers, called by the family's build. */
bool sx_http1_message_build(sxtw_cursor*q);  /* other/http1_message/xx_http1_message_data.c */
bool sx_sip_message_build(sxtw_cursor*q);  /* other/sip_message/xx_sip_message_data.c */
bool sx_rtsp_message_build(sxtw_cursor*q);  /* other/rtsp_message/xx_rtsp_message_data.c */
bool sx_redis_resp_build(sxtw_cursor*q);  /* other/redis_resp/xx_redis_resp_data.c */
bool sx_stomp_frames_build(sxtw_cursor*q);  /* other/stomp_frames/xx_stomp_frames_data.c */
bool sx_smtp_transcript_build(sxtw_cursor*q);  /* other/smtp_transcript/xx_smtp_transcript_data.c */
bool sx_bittorrent_metainfo_build(sxtw_cursor*q);  /* other/bittorrent_metainfo/xx_bittorrent_metainfo_data.c */
bool sx_base16_build(sxtw_cursor*q);  /* other/base16/xx_base16_data.c */
bool sx_base64_build(sxtw_cursor*q);  /* other/base64/xx_base64_data.c */
bool sx_pem_build(sxtw_cursor*q);  /* other/pem/xx_pem_data.c */
bool sx_android_ab_build(sxtw_cursor*q);  /* other/android_ab/xx_android_ab_data.c */
bool sx_age_encrypted_build(sxtw_cursor*q);  /* other/age_encrypted/xx_age_encrypted_data.c */
bool sx_jose_jws_build(sxtw_cursor*q);  /* other/jose_jws/xx_jose_jws_data.c */
bool sx_putty_ppk_build(sxtw_cursor*q);  /* other/putty_ppk/xx_putty_ppk_data.c */
bool sx_srec_build(sxtw_cursor*q);  /* firmware/srec/xx_srec_data.c */
bool sx_ihex_build(sxtw_cursor*q);  /* firmware/ihex/xx_ihex_data.c */
bool sx_debugscr_build(sxtw_cursor*q);  /* executable/debugscr/xx_debugscr_data.c */
bool sx_gdbm_dump_build(sxtw_cursor*q);  /* database/gdbm_dump/xx_gdbm_dump_data.c */
bool sx_mtree_build(sxtw_cursor*q);  /* other/mtree/xx_mtree_data.c */
bool sx_safetensors_build(sxtw_cursor*q);  /* other/safetensors/xx_safetensors_data.c */
bool sx_svg_build(sxtw_cursor*q);  /* image/svg/xx_svg_data.c */
bool sx_dec_sixel_build(sxtw_cursor*q);  /* image/dec_sixel/xx_dec_sixel_data.c */
bool sx_gitobject_build(sxtw_cursor*q);  /* other/gitobject/xx_gitobject_data.c */
bool sx_gpgsigned_build(sxtw_cursor*q);  /* other/gpgsigned/xx_gpgsigned_data.c */

#endif
