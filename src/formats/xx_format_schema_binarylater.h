/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The binarylater schema family: what its family unit (xx_format_schema_binarylater.c)
 * and its formats' data files share. Formats: mongodb bson; cbor; msgpack; ubjson; erlang external term; amazon ion binary; thrift compact; python marshal; python pickle; java serialization; openssh private key; openssh certificate; ethereum rlp; avro object. */
#ifndef XX_FORMAT_SCHEMA_BINARYLATER_H
#define XX_FORMAT_SCHEMA_BINARYLATER_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxbl_bson_tag;
extern const sx_layout sxbl_cbor_tag;
extern const sx_layout sxbl_msgpack_tag;
extern const sx_layout sxbl_ubjson_tag;
extern const sx_layout sxbl_etf_tag;
extern const sx_layout sxbl_ion_tag;
extern const sx_layout sxbl_thrift_field_tag;
extern const sx_layout sxbl_thrift_collection_tag;
extern const sx_layout sxbl_thrift_map_tag;
extern const sx_layout sxbl_pickle_tag;
extern const sx_layout sxbl_marshal_tag;
extern const sx_layout sxbl_java_tag;
extern const sx_layout sxbl_rlp_tag;
extern const sx_layout sxbl_bson_document_size;
extern const sx_layout sxbl_bson_string_size;
extern const sx_layout sxbl_bson_terminator;
extern const sx_layout sxbl_bson_binary_header;
extern const sx_layout sxbl_bson_object_id;
extern const sx_layout sxbl_bson_timestamp;
extern const sx_layout sxbl_bson_decimal128;
extern const sx_layout sxbl_bson_bool;
extern const sx_layout sxbl_bson_code_scope_size;
extern const sx_layout sxbl_bson_datetime;
extern const sx_layout sxbl_cbor_self_describe;
extern const sx_layout sxbl_cbor_half_float;
extern const sx_layout sxbl_msgpack_extension_type;
extern const sx_layout sxbl_msgpack_timestamp64;
extern const sx_layout sxbl_msgpack_timestamp96;
extern const sx_layout sxbl_ubjson_optimized_type;
extern const sx_layout sxbl_etf_version;
extern const sx_layout sxbl_etf_big_sign;
extern const sx_layout sxbl_etf_bit_count;
extern const sx_layout sxbl_etf_old_float;
extern const sx_layout sxbl_etf_pid_old;
extern const sx_layout sxbl_etf_pid_new;
extern const sx_layout sxbl_etf_port_old;
extern const sx_layout sxbl_etf_port_new;
extern const sx_layout sxbl_etf_port_v4;
extern const sx_layout sxbl_etf_reference_id;
extern const sx_layout sxbl_etf_creation1;
extern const sx_layout sxbl_etf_creation4;
extern const sx_layout sxbl_ion_version;
extern const sx_layout sxbl_ion_length1;
extern const sx_layout sxbl_ion_field_id1;
extern const sx_layout sxbl_ion_annotation_length1;
extern const sx_layout sxbl_ion_annotation_id1;
extern const sx_layout sxbl_ion_decimal_exponent1;
extern const sx_layout sxbl_ion_length2;
extern const sx_layout sxbl_ion_field_id2;
extern const sx_layout sxbl_ion_annotation_length2;
extern const sx_layout sxbl_ion_annotation_id2;
extern const sx_layout sxbl_ion_decimal_exponent2;
extern const sx_layout sxbl_ion_length3;
extern const sx_layout sxbl_ion_field_id3;
extern const sx_layout sxbl_ion_annotation_length3;
extern const sx_layout sxbl_ion_annotation_id3;
extern const sx_layout sxbl_ion_decimal_exponent3;
extern const sx_layout sxbl_ion_length4;
extern const sx_layout sxbl_ion_field_id4;
extern const sx_layout sxbl_ion_annotation_length4;
extern const sx_layout sxbl_ion_annotation_id4;
extern const sx_layout sxbl_ion_decimal_exponent4;
extern const sx_layout sxbl_ion_length5;
extern const sx_layout sxbl_ion_field_id5;
extern const sx_layout sxbl_ion_annotation_length5;
extern const sx_layout sxbl_ion_annotation_id5;
extern const sx_layout sxbl_ion_decimal_exponent5;
extern const sx_layout sxbl_ion_length6;
extern const sx_layout sxbl_ion_field_id6;
extern const sx_layout sxbl_ion_annotation_length6;
extern const sx_layout sxbl_ion_annotation_id6;
extern const sx_layout sxbl_ion_decimal_exponent6;
extern const sx_layout sxbl_ion_length7;
extern const sx_layout sxbl_ion_field_id7;
extern const sx_layout sxbl_ion_annotation_length7;
extern const sx_layout sxbl_ion_annotation_id7;
extern const sx_layout sxbl_ion_decimal_exponent7;
extern const sx_layout sxbl_ion_length8;
extern const sx_layout sxbl_ion_field_id8;
extern const sx_layout sxbl_ion_annotation_length8;
extern const sx_layout sxbl_ion_annotation_id8;
extern const sx_layout sxbl_ion_decimal_exponent8;
extern const sx_layout sxbl_ion_length9;
extern const sx_layout sxbl_ion_field_id9;
extern const sx_layout sxbl_ion_annotation_length9;
extern const sx_layout sxbl_ion_annotation_id9;
extern const sx_layout sxbl_ion_decimal_exponent9;
extern const sx_layout sxbl_ion_length10;
extern const sx_layout sxbl_ion_field_id10;
extern const sx_layout sxbl_ion_annotation_length10;
extern const sx_layout sxbl_ion_annotation_id10;
extern const sx_layout sxbl_ion_decimal_exponent10;
extern const sx_layout sxbl_thrift_message;
extern const sx_layout sxbl_thrift_uuid;
extern const sx_layout sxbl_pickle_protocol;
extern const sx_layout sxbl_pickle_frame_size;
extern const sx_layout sxbl_pickle_memo1;
extern const sx_layout sxbl_pickle_memo4;
extern const sx_layout sxbl_pickle_signed_length;
extern const sx_layout sxbl_marshal_signed_count;
extern const sx_layout sxbl_marshal_long_digit;
extern const sx_layout sxbl_marshal_reference;
extern const sx_layout sxbl_marshal_count;
extern const sx_layout sxbl_marshal_string_size;
extern const sx_layout sxbl_marshal_complex;
extern const sx_layout sxbl_java_stream;
extern const sx_layout sxbl_java_handle;
extern const sx_layout sxbl_java_array_count;
extern const sx_layout sxbl_java_class_fields;
extern const sx_layout sxbl_avro_magic;
extern const sx_layout sxbl_avro_sync;
extern const sx_layout sxbl_bson_legacy_binary_size;
extern const sx_layout sxbl_msgpack_timestamp32;
extern const sx_layout sxbl_ion_negative_magnitude1;
extern const sx_layout sxbl_rlp_payload_size1;
extern const sx_layout sxbl_ion_negative_magnitude2;
extern const sx_layout sxbl_rlp_payload_size2;
extern const sx_layout sxbl_ion_negative_magnitude3;
extern const sx_layout sxbl_rlp_payload_size3;
extern const sx_layout sxbl_ion_negative_magnitude4;
extern const sx_layout sxbl_rlp_payload_size4;
extern const sx_layout sxbl_ion_negative_magnitude5;
extern const sx_layout sxbl_rlp_payload_size5;
extern const sx_layout sxbl_ion_negative_magnitude6;
extern const sx_layout sxbl_rlp_payload_size6;
extern const sx_layout sxbl_ion_negative_magnitude7;
extern const sx_layout sxbl_rlp_payload_size7;
extern const sx_layout sxbl_ion_negative_magnitude8;
extern const sx_layout sxbl_rlp_payload_size8;
extern const sx_layout sxbl_cbor_negative_argument1;
extern const sx_layout sxbl_ubjson_byte_size1;
extern const sx_layout sxbl_ubjson_item_count1;
extern const sx_layout sxbl_cbor_negative_argument2;
extern const sx_layout sxbl_ubjson_byte_size2;
extern const sx_layout sxbl_ubjson_item_count2;
extern const sx_layout sxbl_cbor_negative_argument4;
extern const sx_layout sxbl_ubjson_byte_size4;
extern const sx_layout sxbl_ubjson_item_count4;
extern const sx_layout sxbl_cbor_negative_argument8;
extern const sx_layout sxbl_ubjson_byte_size8;
extern const sx_layout sxbl_ubjson_item_count8;
extern const sx_layout sxbl_etf_reference_old;
extern const sx_layout sxbl_rlp_literal;
bool sxbl_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v);
bool sxbl_add(sx_context*c,const sx_layout*l,uint64_t p);
bool sxbl_emit(sx_context*c,uint64_t*p,uint64_t end,const sx_layout*l);
bool sxbl_skip(sx_context*c,uint64_t*p,uint64_t end,uint64_t n);
bool sxbl_byte(sx_context*c,uint64_t p,uint8_t*v);
bool sxbl_numeric(sx_context*c,uint64_t*p,uint64_t end,unsigned z,bool sign,bool be);
bool sxbl_float(sx_context*c,uint64_t*p,uint64_t end,unsigned z,bool be);
bool sxbl_length(sx_context*c,uint64_t*p,uint64_t end,unsigned z,bool be,bool count,uint64_t*v);
bool sxbl_string(sx_context*c,uint64_t*p,uint64_t end,unsigned z,bool be);
bool sxbl_var(sx_context*c,uint64_t*p,uint64_t end,unsigned role,uint64_t*out);
bool sxbl_ssh(sx_context*c,bool cert);

/* Per-format walkers, called by the family's build. */
bool sx_mongodb_bson_build(sx_context *c);  /* other/mongodb_bson/xx_mongodb_bson_data.c */
bool sx_cbor_build(sx_context *c);  /* other/cbor/xx_cbor_data.c */
bool sx_msgpack_build(sx_context *c);  /* other/msgpack/xx_msgpack_data.c */
bool sx_ubjson_build(sx_context *c);  /* other/ubjson/xx_ubjson_data.c */
bool sx_erlang_external_term_build(sx_context *c);  /* other/erlang_external_term/xx_erlang_external_term_data.c */
bool sx_amazon_ion_binary_build(sx_context *c);  /* other/amazon_ion_binary/xx_amazon_ion_binary_data.c */
bool sx_thrift_compact_build(sx_context *c);  /* other/thrift_compact/xx_thrift_compact_data.c */
bool sx_python_marshal_build(sx_context *c);  /* executable/python_marshal/xx_python_marshal_data.c */
bool sx_python_pickle_build(sx_context *c);  /* other/python_pickle/xx_python_pickle_data.c */
bool sx_java_serialization_build(sx_context *c);  /* other/java_serialization/xx_java_serialization_data.c */
bool sx_openssh_private_key_build(sx_context *c);  /* other/openssh_private_key/xx_openssh_private_key_data.c */
bool sx_openssh_certificate_build(sx_context *c);  /* other/openssh_certificate/xx_openssh_certificate_data.c */
bool sx_ethereum_rlp_build(sx_context *c);  /* other/ethereum_rlp/xx_ethereum_rlp_data.c */
bool sx_avro_object_build(sx_context *c);  /* other/avro_object/xx_avro_object_data.c */

#endif
