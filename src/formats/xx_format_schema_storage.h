/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The storage schema family: what its family unit (xx_format_schema_storage.c)
 * and its formats' data files share. Formats: MIDI; CAF; CREATIVE_VOC; SONY_VAG; SONY_PSF; AUDIO_DSF; AUDIO_DFF; AUDIO_WAVE64; AUDIO_ADX; AUDIO_WAVPACK; IVF; IDTECH_ROQ; FLASH_VIDEO_FLV; RAD_BINK; RAD_SMACKER; AUTODESK_FLIC; QCOW; QCOW1; LUKS; ROMFS; CRAMFS. */
#ifndef XX_FORMAT_SCHEMA_STORAGE_H
#define XX_FORMAT_SCHEMA_STORAGE_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sx_st_midi_header;
extern const sx_layout sx_st_midi_track;
extern const sx_layout sx_st_caf_header;
extern const sx_layout sx_st_caf_chunk;
extern const sx_layout sx_st_caf_description;
extern const sx_layout sx_st_caf_data;
extern const sx_layout sx_st_caf_packet_table;
extern const sx_layout sx_st_voc_header;
extern const sx_layout sx_st_voc_block;
extern const sx_layout sx_st_voc_terminator;
extern const sx_layout sx_st_voc_sound;
extern const sx_layout sx_st_voc_silence;
extern const sx_layout sx_st_voc_marker;
extern const sx_layout sx_st_voc_repeat;
extern const sx_layout sx_st_voc_sound_v2;
extern const sx_layout sx_st_vag_header;
extern const sx_layout sx_st_vag_adpcm_frame;
extern const sx_layout sx_st_psf_header;
extern const sx_layout sx_st_dsf_header;
extern const sx_layout sx_st_dsf_format;
extern const sx_layout sx_st_dsf_data;
extern const sx_layout sx_st_dff_form;
extern const sx_layout sx_st_dff_chunk;
extern const sx_layout sx_st_dff_version;
extern const sx_layout sx_st_dff_property;
extern const sx_layout sx_st_dff_frequency;
extern const sx_layout sx_st_dff_channels;
extern const sx_layout sx_st_dff_channel;
extern const sx_layout sx_st_dff_compression;
extern const sx_layout sx_st_wave64_header;
extern const sx_layout sx_st_wave64_chunk;
extern const sx_layout sx_st_wave64_format;
extern const sx_layout sx_st_wave64_format_extra;
extern const sx_layout sx_st_adx_header;
extern const sx_layout sx_st_adx_terminator;
extern const sx_layout sx_st_wavpack_block;
extern const sx_layout sx_st_wavpack_metadata;
extern const sx_layout sx_st_wavpack_metadata_large;
extern const sx_layout sx_st_apev2_tag;
extern const sx_layout sx_st_apev2_item;
extern const sx_layout sx_st_ivf_header;
extern const sx_layout sx_st_ivf_frame;
extern const sx_layout sx_st_roq_header;
extern const sx_layout sx_st_roq_chunk;
extern const sx_layout sx_st_roq_info;
extern const sx_layout sx_st_roq_codebook_cell;
extern const sx_layout sx_st_roq_codebook_quad;
extern const sx_layout sx_st_flv_header;
extern const sx_layout sx_st_flv_previous_tag;
extern const sx_layout sx_st_flv_tag;
extern const sx_layout sx_st_flv_audio;
extern const sx_layout sx_st_flv_aac_audio;
extern const sx_layout sx_st_flv_video;
extern const sx_layout sx_st_flv_avc_video;
extern const sx_layout sx_st_bink_header;
extern const sx_layout sx_st_bink_audio_maximum;
extern const sx_layout sx_st_bink_audio_format;
extern const sx_layout sx_st_bink_audio_id;
extern const sx_layout sx_st_bink_frame_index;
extern const sx_layout sx_st_bink_end_offset;
extern const sx_layout sx_st_bink_audio_packet;
extern const sx_layout sx_st_bink_audio_decoded;
extern const sx_layout sx_st_smacker_header;
extern const sx_layout sx_st_smacker_frame_size;
extern const sx_layout sx_st_smacker_frame_type;
extern const sx_layout sx_st_smacker_audio_packet;
extern const sx_layout sx_st_smacker_audio_decoded;
extern const sx_layout sx_st_smacker_palette;
extern const sx_layout sx_st_fli_header;
extern const sx_layout sx_st_flc_header;
extern const sx_layout sx_st_flic_chunk;
extern const sx_layout sx_st_flic_frame;
extern const sx_layout sx_st_luks1_header;
extern const sx_layout sx_st_luks1_keyslot;
extern const sx_layout sx_st_luks2_header;
extern const sx_layout sx_st_romfs_superblock;
extern const sx_layout sx_st_romfs_inode;
extern const sx_layout sx_st_cramfs_superblock_le;
extern const sx_layout sx_st_cramfs_inode_le;
extern const sx_layout sx_st_cramfs_block_pointer_le;
extern const sx_layout sx_st_cramfs_superblock_be;
extern const sx_layout sx_st_cramfs_inode_be;
extern const sx_layout sx_st_cramfs_block_pointer_be;
bool sx_st_fits(const sx_context *c,uint64_t o,uint64_t n);
bool sx_st_finish(sx_context *c);
bool sx_st_free(sx_context *c,uint64_t o,uint64_t n);
bool sx_st_qcow(sx_context *c,bool v1);

/* Per-format walkers, called by the family's build. */
bool sx_midi_build(sx_context *c);  /* audio/midi/xx_midi_data.c */
bool sx_caf_build(sx_context *c);  /* audio/caf/xx_caf_data.c */
bool sx_creative_voc_build(sx_context *c);  /* audio/creative_voc/xx_creative_voc_data.c */
bool sx_sony_vag_build(sx_context *c);  /* audio/sony_vag/xx_sony_vag_data.c */
bool sx_sony_psf_build(sx_context *c);  /* audio/sony_psf/xx_sony_psf_data.c */
bool sx_audio_dsf_build(sx_context *c);  /* audio/audio_dsf/xx_audio_dsf_data.c */
bool sx_audio_dff_build(sx_context *c);  /* audio/audio_dff/xx_audio_dff_data.c */
bool sx_audio_wave64_build(sx_context *c);  /* audio/audio_wave64/xx_audio_wave64_data.c */
bool sx_audio_adx_build(sx_context *c);  /* audio/audio_adx/xx_audio_adx_data.c */
bool sx_audio_wavpack_build(sx_context *c);  /* audio/audio_wavpack/xx_audio_wavpack_data.c */
bool sx_ivf_build(sx_context *c);  /* video/ivf/xx_ivf_data.c */
bool sx_idtech_roq_build(sx_context *c);  /* video/idtech_roq/xx_idtech_roq_data.c */
bool sx_flash_video_flv_build(sx_context *c);  /* video/flash_video_flv/xx_flash_video_flv_data.c */
bool sx_rad_bink_build(sx_context *c);  /* video/rad_bink/xx_rad_bink_data.c */
bool sx_rad_smacker_build(sx_context *c);  /* video/rad_smacker/xx_rad_smacker_data.c */
bool sx_autodesk_flic_build(sx_context *c);  /* video/autodesk_flic/xx_autodesk_flic_data.c */
bool sx_qcow_build(sx_context *c);  /* filesystem/qcow/xx_qcow_data.c */
bool sx_qcow1_build(sx_context *c);  /* filesystem/qcow1/xx_qcow1_data.c */
bool sx_luks_build(sx_context *c);  /* filesystem/luks/xx_luks_data.c */
bool sx_romfs_build(sx_context *c);  /* filesystem/romfs/xx_romfs_data.c */
bool sx_cramfs_build(sx_context *c);  /* filesystem/cramfs/xx_cramfs_data.c */

#endif
