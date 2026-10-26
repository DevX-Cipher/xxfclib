/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The container schema family: what its family unit (xx_format_schema_container.c)
 * and its formats' data files share. Formats: RIFF; AUDIO_RIFX_WAVE; AUDIO_RIFF_IMA; AUDIO_WWISE_WEM; SOUNDFONT2; OGG; PCAP; SQLITE3; SQLITE_WAL; SFNT; WOFF; WOFF2; FLAC; AIFF; AUDIO_AU. */
#ifndef XX_FORMAT_SCHEMA_CONTAINER_H
#define XX_FORMAT_SCHEMA_CONTAINER_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sx_c_ogg_page_header;
extern const sx_layout sx_c_ogg_lacing_value;
extern const sx_layout sx_c_pcap_file_header_le;
extern const sx_layout sx_c_pcap_file_header_be;
extern const sx_layout sx_c_pcap_packet_header_le;
extern const sx_layout sx_c_pcap_packet_header_be;
extern const sx_layout sx_c_sqlite3_database_header;
extern const sx_layout sx_c_sqlite_btree_leaf_page_header;
extern const sx_layout sx_c_sqlite_btree_interior_page_header;
extern const sx_layout sx_c_sqlite_cell_pointer;
extern const sx_layout sx_c_sqlite_wal_header;
extern const sx_layout sx_c_sqlite_wal_frame_header;
extern const sx_layout sx_c_sfnt_offset_table;
extern const sx_layout sx_c_sfnt_table_record;
extern const sx_layout sx_c_woff_header;
extern const sx_layout sx_c_woff_table_record;
extern const sx_layout sx_c_woff2_header;
extern const sx_layout sx_c_woff2_table_flags;
extern const sx_layout sx_c_woff2_table_tag;
extern const sx_layout sx_c_woff2_base128_1;
extern const sx_layout sx_c_woff2_base128_2;
extern const sx_layout sx_c_woff2_base128_3;
extern const sx_layout sx_c_woff2_base128_4;
extern const sx_layout sx_c_woff2_base128_5;
extern const sx_layout sx_c_flac_marker;
extern const sx_layout sx_c_flac_metadata_block_header;
extern const sx_layout sx_c_flac_streaminfo;
extern const sx_layout sx_c_flac_application_header;
extern const sx_layout sx_c_flac_seekpoint;
extern const sx_layout sx_c_aiff_form_header;
extern const sx_layout sx_c_aiff_chunk_header;
extern const sx_layout sx_c_aiff_common_chunk;
extern const sx_layout sx_c_aifc_compression_type;
extern const sx_layout sx_c_aiff_sound_data_header;
extern const sx_layout sx_c_aiff_format_version;
extern const sx_layout sx_c_au_header;
bool sx_c_bounds(sx_context *c, int64_t off, uint64_t n);
bool sx_c_riff(sx_context *c);
bool sx_c_font_table(sx_context *c,const uint8_t tag[4],int64_t off,uint32_t n);

/* Per-format walkers, called by the family's build. */
bool sx_riff_build(sx_context *c);  /* other/riff/xx_riff_data.c */
bool sx_audio_rifx_wave_build(sx_context *c);  /* audio/audio_rifx_wave/xx_audio_rifx_wave_data.c */
bool sx_audio_riff_ima_build(sx_context *c);  /* audio/audio_riff_ima/xx_audio_riff_ima_data.c */
bool sx_audio_wwise_wem_build(sx_context *c);  /* audio/audio_wwise_wem/xx_audio_wwise_wem_data.c */
bool sx_soundfont2_build(sx_context *c);  /* audio/soundfont2/xx_soundfont2_data.c */
bool sx_ogg_build(sx_context *c);  /* audio/ogg/xx_ogg_data.c */
bool sx_pcap_build(sx_context *c);  /* other/pcap/xx_pcap_data.c */
bool sx_sqlite3_build(sx_context *c);  /* database/sqlite3/xx_sqlite3_data.c */
bool sx_sqlite_wal_build(sx_context *c);  /* database/sqlite_wal/xx_sqlite_wal_data.c */
bool sx_sfnt_build(sx_context *c);  /* font/sfnt/xx_sfnt_data.c */
bool sx_woff_build(sx_context *c);  /* font/woff/xx_woff_data.c */
bool sx_woff2_build(sx_context *c);  /* font/woff2/xx_woff2_data.c */
bool sx_flac_build(sx_context *c);  /* audio/flac/xx_flac_data.c */
bool sx_aiff_build(sx_context *c);  /* audio/aiff/xx_aiff_data.c */
bool sx_audio_au_build(sx_context *c);  /* audio/audio_au/xx_audio_au_data.c */

#endif
