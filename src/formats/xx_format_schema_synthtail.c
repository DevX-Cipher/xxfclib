/* SPDX-License-Identifier: MIT. Independent physical V2M and DMO metadata layouts. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_synthtail.h"
static const sx_layout*const sx_synthtail_layouts[]={&sxsynt_v2m_header,&sxsynt_v2m_time_delta_low_plane,&sxsynt_v2m_time_delta_middle_plane,&sxsynt_v2m_time_delta_high_plane,&sxsynt_v2m_time_signature_numerator_plane,&sxsynt_v2m_time_signature_denominator_plane,&sxsynt_v2m_timing_tpq_plane,&sxsynt_v2m_note_delta_plane,&sxsynt_v2m_velocity_delta_plane,&sxsynt_v2m_program_delta_plane,&sxsynt_v2m_pitch_lsb_delta_plane,&sxsynt_v2m_pitch_msb_delta_plane,&sxsynt_v2m_controller_delta_plane,&sxsynt_v2m_tempo,&sxsynt_v2m_note_count,&sxsynt_v2m_program_count,&sxsynt_v2m_pitch_count,&sxsynt_v2m_controller_count,&sxsynt_v2m_globals_length,&sxsynt_v2m_patchmap_length,&sxsynt_v2m_speech_length,&sxsynt_v2m_speech_count,&sxsynt_v2m_speech_offset,&sxsynt_dmo_cipher_header};
static bool sx_synthtail_supports(xx_file_type_t t)
{return t==XX_FILE_TYPE_DIE_MUSIC_FARBRAUSCH_V2SYNTHESIZER||t==XX_FILE_TYPE_DIE_MUSIC_TWINTEAM_TWINTRACKPLAYER_DMO;}
static bool sx_synthtail_build(sx_context*c)
{if(!c||!c->f||!sx_synthtail_supports(c->f->file_type)||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;
 if(c->f->file_type==XX_FILE_TYPE_DIE_MUSIC_TWINTEAM_TWINTRACKPLAYER_DMO)return sx_twinteam_twintrackplayer_dmo_build(c);
 return sx_farbrausch_v2synthesizer_build(c);}
static bool sx_synthtail_comment(xx_data_struct_record*r,uint32_t id)
{if(!r||!r->name||id<0x608e0001U||id>0x608e0018U)return true;
 const wchar_t*t=L"Stored physical value; synthesizer execution and reconstructed MIDI state are not exposed as file members.";
 if(!xx_rt_wcscmp(r->name,L"speech_offset"))t=L"Byte offset relative to the start of the speech block, whose first field is speech_count.";
 else if(!xx_rt_wcscmp(r->name,L"initial_seed"))t=L"Initial 32-bit seed for the TwinTeam header's pseudorandom validation sequence.";
 else if(!xx_rt_wcscmp(r->name,L"seed_iteration_limit"))t=L"Inclusive iteration limit; the seed-summing loop runs this value plus one times.";
 else if(!xx_rt_wcscmp(r->name,L"seed_xor"))t=L"Value XORed with the accumulated seed before the header check and byte decoding.";
 else if(!xx_rt_wcscmp(r->name,L"seed_check"))t=L"Validated 16-bit pseudorandom header check. This checks header identity only; the encrypted payload remains raw and is not authenticated.";
 else if(!xx_rt_wcscmp(r->name,L"microseconds_per_quarter"))t=L"Tempo in microseconds per quarter note; little-endian global event value.";
 else if(!xx_rt_wcscmp(r->name,L"timing_tpq"))t=L"Stored TPQ byte in the global timing event; its physical value is preserved without assuming an undocumented unit.";
 else if(!xx_rt_wcscmp(r->name,L"maximum_time"))t=L"Song end time in file ticks, using ticks_per_quarter.";
 else if(!xx_rt_wcscmp(r->name,L"time_delta_low")||!xx_rt_wcscmp(r->name,L"time_delta_middle")||!xx_rt_wcscmp(r->name,L"time_delta_high"))t=L"One byte plane of 24-bit unsigned event-time deltas: low, middle, and high planes are stored separately.";
 else if(!xx_rt_wcscmp(r->name,L"note_delta")||!xx_rt_wcscmp(r->name,L"velocity_delta")||!xx_rt_wcscmp(r->name,L"program_delta")||!xx_rt_wcscmp(r->name,L"pitch_lsb_delta")||!xx_rt_wcscmp(r->name,L"pitch_msb_delta")||!xx_rt_wcscmp(r->name,L"controller_delta"))t=L"Stored byte-difference plane. Playback accumulates these bytes; this field preserves the encoded differences.";
 return xx_data_struct_record_set_comment(r,t);}
const sx_family sx_synthtail_family={sx_synthtail_supports,sx_synthtail_build,sx_synthtail_layouts,SX_COUNT(sx_synthtail_layouts),sx_synthtail_comment};
