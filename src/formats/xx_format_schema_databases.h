/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The databases schema family: what its family unit (xx_format_schema_databases.c)
 * and its formats' data files share. Formats: hadoop_sequencefile; postgres_custom; lmdb_data; leveldb_sstable; redis_rdb; tps; dbz; apache_orc. */
#ifndef XX_FORMAT_SCHEMA_DATABASES_H
#define XX_FORMAT_SCHEMA_DATABASES_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxd_sequence_header;
extern const sx_layout sxd_sequence_options;
extern const sx_layout sxd_sequence_sync;
extern const sx_layout sxd_sequence_sync_record;
extern const sx_layout sxd_sequence_record;
extern const sx_layout sxd_sequence_text_length_0;
extern const sx_layout sxd_sequence_text_length_1;
extern const sx_layout sxd_sequence_text_length_2;
extern const sx_layout sxd_sequence_text_length_3;
extern const sx_layout sxd_sequence_text_length_4;
extern const sx_layout sxd_sequence_text_length_5;
extern const sx_layout sxd_sequence_text_length_6;
extern const sx_layout sxd_sequence_text_length_7;
extern const sx_layout sxd_sequence_text_length_8;
extern const sx_layout sxd_postgres_header;
extern const sx_layout sxd_postgres_compression_v15;
extern const sx_layout sxd_postgres_compression_legacy;
extern const sx_layout sxd_postgres_time;
extern const sx_layout sxd_postgres_string_length;
extern const sx_layout sxd_postgres_toc_count;
extern const sx_layout sxd_postgres_toc_prefix;
extern const sx_layout sxd_postgres_section;
extern const sx_layout sxd_postgres_data_offset;
extern const sx_layout sxd_postgres_block_header;
extern const sx_layout sxd_postgres_chunk_length;
extern const sx_layout sxd_lmdb_meta_prefix;
extern const sx_layout sxd_lmdb_database;
extern const sx_layout sxd_lmdb_free_database;
extern const sx_layout sxd_lmdb_meta_tail;
extern const sx_layout sxd_lmdb_page_header;
extern const sx_layout sxd_lmdb_node_offset;
extern const sx_layout sxd_lmdb_leaf_node;
extern const sx_layout sxd_lmdb_branch_node;
extern const sx_layout sxd_lmdb_overflow_reference;
extern const sx_layout sxd_lmdb_overflow_page;
extern const sx_layout sxd_leveldb_block_trailer;
extern const sx_layout sxd_leveldb_restart_offset;
extern const sx_layout sxd_leveldb_restart_count;
extern const sx_layout sxd_leveldb_footer_magic;
extern const sx_layout sxd_redis_header;
extern const sx_layout sxd_redis_opcode;
extern const sx_layout sxd_redis_trailer;
extern const sx_layout sxd_redis_expire_milliseconds;
extern const sx_layout sxd_redis_expire_seconds;
extern const sx_layout sxd_redis_frequency;
extern const sx_layout sxd_redis_length_6;
extern const sx_layout sxd_redis_length_14;
extern const sx_layout sxd_redis_length_32;
extern const sx_layout sxd_redis_length_64;
extern const sx_layout sxd_redis_encoded_string;
extern const sx_layout sxd_redis_integer_1;
extern const sx_layout sxd_redis_integer_2;
extern const sx_layout sxd_redis_integer_4;
extern const sx_layout sxd_redis_score_length;
extern const sx_layout sxd_redis_score_binary;
extern const sx_layout sxd_tps_header;
extern const sx_layout sxd_tps_entry;
extern const sx_layout sxd_tps_terminator;
extern const sx_layout sxd_dbz_header;
extern const sx_layout sxd_dbz_index_record;
extern const sx_layout sxd_orc_header;
extern const sx_layout sxd_orc_postscript_length;
extern const sx_layout sxd_orc_fixed32;
extern const sx_layout sxd_orc_fixed64;
extern const sx_layout sxd_database_varuint_1;
extern const sx_layout sxd_database_varuint_2;
extern const sx_layout sxd_database_varuint_3;
extern const sx_layout sxd_database_varuint_4;
extern const sx_layout sxd_database_varuint_5;
extern const sx_layout sxd_database_varuint_6;
extern const sx_layout sxd_database_varuint_7;
extern const sx_layout sxd_database_varuint_8;
extern const sx_layout sxd_database_varuint_9;
extern const sx_layout sxd_database_varuint_10;
extern const sx_layout sxd_database_varuint_count_1;
extern const sx_layout sxd_database_varuint_count_2;
extern const sx_layout sxd_database_varuint_count_3;
extern const sx_layout sxd_database_varuint_count_4;
extern const sx_layout sxd_database_varuint_count_5;
extern const sx_layout sxd_database_varuint_count_6;
extern const sx_layout sxd_database_varuint_count_7;
extern const sx_layout sxd_database_varuint_count_8;
extern const sx_layout sxd_database_varuint_count_9;
extern const sx_layout sxd_database_varuint_count_10;
extern const sx_layout sxd_database_varuint_id_1;
extern const sx_layout sxd_database_varuint_id_2;
extern const sx_layout sxd_database_varuint_id_3;
extern const sx_layout sxd_database_varuint_id_4;
extern const sx_layout sxd_database_varuint_id_5;
extern const sx_layout sxd_database_varuint_id_6;
extern const sx_layout sxd_database_varuint_id_7;
extern const sx_layout sxd_database_varuint_id_8;
extern const sx_layout sxd_database_varuint_id_9;
extern const sx_layout sxd_database_varuint_id_10;
extern const sx_layout sxd_orc_protobuf_key_1;
extern const sx_layout sxd_orc_protobuf_key_2;
extern const sx_layout sxd_orc_protobuf_key_3;
extern const sx_layout sxd_orc_protobuf_key_4;
extern const sx_layout sxd_orc_protobuf_key_5;
extern const sx_layout sxd_orc_protobuf_key_6;
extern const sx_layout sxd_orc_protobuf_key_7;
extern const sx_layout sxd_orc_protobuf_key_8;
extern const sx_layout sxd_orc_protobuf_key_9;
extern const sx_layout sxd_orc_protobuf_key_10;
extern const sx_layout *const sxd_database_varuint_offset_rows[10];
extern const sx_layout *const sxd_database_varuint_size_rows[10];
uint32_t sxd_u32(const uint8_t *p);
uint32_t sxd_be32(const uint8_t *p);
bool sxd_can(sx_context *c,uint64_t at,uint64_t n);
bool sxd_add(sx_context *c,const sx_layout *l,uint64_t at,uint64_t n);
bool sxd_table(sx_context *c,const sx_layout *l,uint64_t at,unsigned width,uint64_t count);
bool sxd_var(sx_context *c,const uint8_t *b,uint64_t *at,uint64_t end,uint64_t *v,const sx_layout *const *rows);

/* Per-format walkers, called by the family's build. */
bool sx_hadoop_sequencefile_build(sx_context *c,uint8_t *b);  /* database/hadoop_sequencefile/xx_hadoop_sequencefile_data.c */
bool sx_postgres_custom_build(sx_context *c,uint8_t *b);  /* database/postgres_custom/xx_postgres_custom_data.c */
bool sx_lmdb_data_build(sx_context *c,uint8_t *b);  /* database/lmdb_data/xx_lmdb_data_data.c */
bool sx_leveldb_sstable_build(sx_context *c,uint8_t *b);  /* database/leveldb_sstable/xx_leveldb_sstable_data.c */
bool sx_redis_rdb_build(sx_context *c,uint8_t *b);  /* database/redis_rdb/xx_redis_rdb_data.c */
bool sx_tps_build(sx_context *c,uint8_t *b);  /* database/tps/xx_tps_data.c */
bool sx_dbz_build(sx_context *c,uint8_t *b);  /* database/dbz/xx_dbz_data.c */
bool sx_apache_orc_build(sx_context *c,uint8_t *b);  /* database/apache_orc/xx_apache_orc_data.c */

#endif
