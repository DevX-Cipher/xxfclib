/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The sciencesequence schema family: what its family unit (xx_format_schema_sciencesequence.c)
 * and its formats' data files share. Formats: genomics_genbank; genomics_embl; genomics_swissprot; alignment_clustal; alignment_stockholm; alignment_phylip; alignment_maf; alignment_mauve; assembly_gfa; quake_md5mesh; idtech_md5anim. */
#ifndef XX_FORMAT_SCHEMA_SCIENCESEQUENCE_H
#define XX_FORMAT_SCHEMA_SCIENCESEQUENCE_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Native validation gates interpretation; every emitted span is checked again. */
typedef struct sxseq_cursor{sx_context*c;uint8_t*b;int64_t n,p;uint64_t work;}sxseq_cursor;
typedef struct sxseq_token{int64_t a,z;}sxseq_token;

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxseq_signature;
extern const sx_layout sxseq_keyword;
extern const sx_layout sxseq_field_key;
extern const sx_layout sxseq_field_text;
extern const sx_layout sxseq_identifier;
extern const sx_layout sxseq_molecule_type;
extern const sx_layout sxseq_locus_options;
extern const sx_layout sxseq_unit;
extern const sx_layout sxseq_accession;
extern const sx_layout sxseq_feature_key;
extern const sx_layout sxseq_feature_location;
extern const sx_layout sxseq_feature_qualifier;
extern const sx_layout sxseq_comment;
extern const sx_layout sxseq_terminator;
extern const sx_layout sxseq_sequence_length;
extern const sx_layout sxseq_alignment_columns;
extern const sx_layout sxseq_sequence_count;
extern const sx_layout sxseq_sequence_position;
extern const sx_layout sxseq_residue_total;
extern const sx_layout sxseq_sequence_text;
extern const sx_layout sxseq_consensus;
extern const sx_layout sxseq_annotation_key;
extern const sx_layout sxseq_annotation_text;
extern const sx_layout sxseq_maf_scoring;
extern const sx_layout sxseq_alignment_score;
extern const sx_layout sxseq_maf_start;
extern const sx_layout sxseq_maf_size;
extern const sx_layout sxseq_source_length;
extern const sx_layout sxseq_strand;
extern const sx_layout sxseq_mauve_sequence_id;
extern const sx_layout sxseq_mauve_start;
extern const sx_layout sxseq_mauve_end;
extern const sx_layout sxseq_source_filename;
extern const sx_layout sxseq_gfa_record_type;
extern const sx_layout sxseq_segment_name;
extern const sx_layout sxseq_path_name;
extern const sx_layout sxseq_orientation;
extern const sx_layout sxseq_overlap_length;
extern const sx_layout sxseq_cigar_operation;
extern const sx_layout sxseq_missing_overlap;
extern const sx_layout sxseq_tag_name;
extern const sx_layout sxseq_tag_type;
extern const sx_layout sxseq_tag_integer;
extern const sx_layout sxseq_tag_real;
extern const sx_layout sxseq_tag_string;
extern const sx_layout sxseq_tag_character;
extern const sx_layout sxseq_tag_hex_bytes;
extern const sx_layout sxseq_gfa_declared_length;
extern const sx_layout sxseq_version;
bool sxseq_eq(sxseq_cursor*q,sxseq_token t,const char*s);
sxseq_token sxseq_trim(sxseq_cursor*q,sxseq_token t);
bool sxseq_line(sxseq_cursor*q,sxseq_token*t);
unsigned sxseq_split(sxseq_cursor*q,sxseq_token line,sxseq_token*t,unsigned cap,bool tabs);
bool sxseq_emit(sxseq_cursor*q,const sx_layout*l,sxseq_token t);
bool sxseq_number(sxseq_cursor*q,sxseq_token t,uint64_t*v);
bool sxseq_chunks(sxseq_cursor*q,const sx_layout*l,sxseq_token t);
bool sxseq_embl_swiss(sxseq_cursor*q,bool swiss);
bool sxseq_md5(sxseq_cursor*q,bool animation);

/* Per-format walkers, called by the family's build. */
bool sx_genomics_genbank_build(sxseq_cursor*q);  /* science/genomics_genbank/xx_genomics_genbank_data.c */
bool sx_genomics_embl_build(sxseq_cursor*q);  /* science/genomics_embl/xx_genomics_embl_data.c */
bool sx_genomics_swissprot_build(sxseq_cursor*q);  /* science/genomics_swissprot/xx_genomics_swissprot_data.c */
bool sx_alignment_clustal_build(sxseq_cursor*q);  /* science/alignment_clustal/xx_alignment_clustal_data.c */
bool sx_alignment_stockholm_build(sxseq_cursor*q);  /* science/alignment_stockholm/xx_alignment_stockholm_data.c */
bool sx_alignment_phylip_build(sxseq_cursor*q);  /* science/alignment_phylip/xx_alignment_phylip_data.c */
bool sx_alignment_maf_build(sxseq_cursor*q);  /* science/alignment_maf/xx_alignment_maf_data.c */
bool sx_alignment_mauve_build(sxseq_cursor*q);  /* science/alignment_mauve/xx_alignment_mauve_data.c */
bool sx_assembly_gfa_build(sxseq_cursor*q);  /* science/assembly_gfa/xx_assembly_gfa_data.c */
bool sx_quake_md5mesh_build(sxseq_cursor*q);  /* game/quake_md5mesh/xx_quake_md5mesh_data.c */
bool sx_idtech_md5anim_build(sxseq_cursor*q);  /* game/idtech_md5anim/xx_idtech_md5anim_data.c */

#endif
