/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical sampler-bank metadata; encoded payload remains raw.
 * Scope and sources: docs/data_struct_samplebanks_scope.txt. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_samplebanks.h"
static const sx_layout *const sx_samplebanks_layouts[] = {
    &sxsb_emaxutil_marker,
    &sxsb_emax_bank_header,
    &sxsb_emax_preset_header,
    &sxsb_emax_key_area,
    &sxsb_emax_voice,
    &sxsb_emax_sample_entry,
    &sxsb_emulator2_selected_name,
    &sxsb_emulator2_keymaps,
    &sxsb_emulator2_preset_header,
    &sxsb_emulator2_selection,
    &sxsb_emulator2_preset_length,
    &sxsb_emulator2_key_range,
    &sxsb_emulator2_secondary_voice,
    &sxsb_emulator2_key_range_end,
    &sxsb_emulator2_voice,
    &sxsb_casio_fz_bank,
    &sxsb_casio_fz_voice,
    &sxsb_casio_fz_effect,
    &sxsb_casio_fzf_dump_workspace,
};
static bool sx_samplebanks_comment(xx_data_struct_record*r,uint32_t id){
    if(!r||!r->name||id<0x603a0000U||id>=0x603b0000U)return true;
    const wchar_t *s=NULL;
    xx_var_type_t value_type=xx_var_get_type(&r->value);
    bool integer=value_type>=XX_VAR_TYPE_INT8&&value_type<=XX_VAR_TYPE_UINT64;
    uint64_t value=integer?xx_var_get_u64(&r->value):0;
    if(id==0x603a0006U&&!xx_rt_wcscmp(r->name,L"sample_rate_index")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"10000 Hz");
    case 1U:return xx_data_struct_record_set_comment(r,L"15625 Hz");
    case 2U:return xx_data_struct_record_set_comment(r,L"20000 Hz");
    case 3U:return xx_data_struct_record_set_comment(r,L"22050 Hz");
    case 4U:return xx_data_struct_record_set_comment(r,L"27778 Hz");
    case 5U:return xx_data_struct_record_set_comment(r,L"31250 Hz");
    case 6U:return xx_data_struct_record_set_comment(r,L"41667 Hz");
    case 7U:return xx_data_struct_record_set_comment(r,L"44100 Hz");
    default:break;}}
    if(id==0x603a0011U&&!xx_rt_wcscmp(r->name,L"sounding_mode")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"NO SOUND");
    case 471U:return xx_data_struct_record_set_comment(r,L"NORMAL");
    case 4125U:return xx_data_struct_record_set_comment(r,L"REVERSE");
    case 8212U:return xx_data_struct_record_set_comment(r,L"CUE");
    case 19U:return xx_data_struct_record_set_comment(r,L"SYNTHESIZED");
    default:break;}}
    if(id==0x603a0011U&&!xx_rt_wcscmp(r->name,L"sample_rate_code")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"36000 Hz");
    case 1U:return xx_data_struct_record_set_comment(r,L"18000 Hz");
    case 2U:return xx_data_struct_record_set_comment(r,L"9000 Hz");
    default:break;}}
    if(id==0x603a0013U&&!xx_rt_wcscmp(r->name,L"dump_type")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"FULL DUMP");
    case 2U:return xx_data_struct_record_set_comment(r,L"BANK DUMP");
    default:break;}}
    switch(id){
    case 0x603a0001U:
        if(!xx_rt_wcscmp(r->name,L"producer_marker"))s=L"Constant emaxutil producer marker; the date text is not a per-file modification time.";
        break;
    case 0x603a0002U:
        if(!xx_rt_wcscmp(r->name,L"preset_addresses"))s=L"Little-endian CPU addresses into parameter memory mapped at 0x8000. Unused slots may contain stale addresses; this is not a contiguous record table.";
        else if(!xx_rt_wcscmp(r->name,L"allocation_address"))s=L"First free byte in parameter memory, expressed as a CPU address.";
        else if(!xx_rt_wcscmp(r->name,L"selected_preset"))s=L"Selected preset slot, not a preset count; all 100 pointer slots are independent.";
        else if(!xx_rt_wcscmp(r->name,L"sequence_addresses"))s=L"Sample-memory addresses; 0x80000 denotes an unused Emax I sequence slot.";
        else if(!xx_rt_wcscmp(r->name,L"lowest_sample_entry_address"))s=L"CPU address of the lowest sample-directory entry. Entries grow downwards from 0xF000.";
        else if(!xx_rt_wcscmp(r->name,L"highest_sample_entry_address"))s=L"CPU address, normally 0xEFE0.";
        break;
    case 0x603a0003U:
        if(!xx_rt_wcscmp(r->name,L"opaque_preset_parameters"))s=L"Stored preset parameters; their individual semantics are not decoded.";
        else if(!xx_rt_wcscmp(r->name,L"key_area_map"))s=L"Key 0 is MIDI note 21. Entries index the key-area table; 0xFF is silent.";
        break;
    case 0x603a0004U:
        if(!xx_rt_wcscmp(r->name,L"flags"))s=L"Bit 4 enables the secondary voice.";
        else if(!xx_rt_wcscmp(r->name,L"velocity_crossfade_encoded"))s=L"Stored velocity crossfade/switch parameter; its encoding is not decoded.";
        else if(!xx_rt_wcscmp(r->name,L"primary_voice"))s=L"Zero-based index in this preset's voice records.";
        else if(!xx_rt_wcscmp(r->name,L"secondary_voice"))s=L"Zero-based voice index; 0xFF denotes no secondary voice.";
        break;
    case 0x603a0005U:
        if(!xx_rt_wcscmp(r->name,L"amplitude_envelope_and_lfo_rate"))s=L"Little-endian packed bits: attack 0..4, hold 5..9, decay 10..14, sustain 15..19, release 20..24, LFO rate 25..31.";
        else if(!xx_rt_wcscmp(r->name,L"lfo_tuning_and_velocity"))s=L"Local bits: LFO delay 0..5, variation 6..10, pitch depth 11..14, signed tuning 15..19, velocity cutoff 20..23, velocity filter attack 24..27; upper 4 bits undecoded.";
        else if(!xx_rt_wcscmp(r->name,L"level_velocity_and_chorus"))s=L"Local bits: LFO volume 0..3, velocity level 4..7, velocity amplitude attack 12..15, chorus amount 24..28; other bits undecoded.";
        else if(!xx_rt_wcscmp(r->name,L"original_key"))s=L"MIDI note 21 plus this value.";
        else if(!xx_rt_wcscmp(r->name,L"sample_index"))s=L"Zero-based sample number, counted downwards from the top of the sample directory.";
        else if(!xx_rt_wcscmp(r->name,L"filter_cutoff_encoded"))s=L"Low 7 bits encode filter cutoff; high bit is undecoded.";
        else if(!xx_rt_wcscmp(r->name,L"filter_q_encoded"))s=L"Low 7 bits encode filter Q; high bit is undecoded.";
        else if(!xx_rt_wcscmp(r->name,L"filter_envelope_amount_encoded"))s=L"Low 7 bits form a signed filter-envelope amount; high bit is undecoded.";
        else if(!xx_rt_wcscmp(r->name,L"filter_envelope_and_flags"))s=L"Local bits: attack 0..4, hold 5..9, decay 10..14, sustain 15..19, release 20..24, velocity Q 25..28, non-transpose 31; bits 29..30 undecoded.";
        else if(!xx_rt_wcscmp(r->name,L"keyboard_tracking_and_pan"))s=L"Low nibble is filter keyboard tracking; high nibble is pan (1 right, 8 centre, 15 left).";
        else if(!xx_rt_wcscmp(r->name,L"lfo_filter_encoded"))s=L"High nibble is LFO-to-filter depth; low nibble undecoded.";
        else if(!xx_rt_wcscmp(r->name,L"delay_attenuation_chorus"))s=L"Low 6 bits are voice delay; bits 6..10 attenuation, bit 11 chorus enabled; upper bits undecoded.";
        break;
    case 0x603a0006U:
        if(!xx_rt_wcscmp(r->name,L"unused_00"))s=L"Unused stored word, potentially stale memory.";
        else if(!xx_rt_wcscmp(r->name,L"sample_start"))s=L"Address in Emax I sample memory; one stored byte per sample frame.";
        else if(!xx_rt_wcscmp(r->name,L"sample_end"))s=L"Address in Emax I sample memory.";
        else if(!xx_rt_wcscmp(r->name,L"sustain_loop_start"))s=L"Sample-memory address; loop fields may be stale when looping is disabled.";
        else if(!xx_rt_wcscmp(r->name,L"flags"))s=L"Bit 0 enables looping; bit 1 uses the sustain loop in release. Other bits remain undecoded.";
        break;
    case 0x603a0007U:
        if(!xx_rt_wcscmp(r->name,L"selected_name"))s=L"Stored display-name workspace; may be blank.";
        break;
    case 0x603a0008U:
        if(!xx_rt_wcscmp(r->name,L"primary_voice_number"))s=L"Expanded selected-preset voice numbers, one per keyboard key.";
        else if(!xx_rt_wcscmp(r->name,L"primary_voice_identifier"))s=L"Voice memory-page identifiers; 0x9B identifies the first 256-byte voice slot.";
        else if(!xx_rt_wcscmp(r->name,L"primary_transpose"))s=L"Stored semitone transposition; 0x10 is recorded pitch.";
        break;
    case 0x603a0009U:
        if(!xx_rt_wcscmp(r->name,L"encoded_header"))s=L"Stored preset-header values; individual semantics are undecoded.";
        else if(!xx_rt_wcscmp(r->name,L"header_flags"))s=L"High bit identifies a preset record.";
        else if(!xx_rt_wcscmp(r->name,L"name"))s=L"Display name; some producers use Mac Roman bytes or control characters.";
        break;
    case 0x603a000aU:
        if(!xx_rt_wcscmp(r->name,L"voice_identifiers"))s=L"Voice-number lookup; 0 is unused, 0x9B is the first voice-slot identifier.";
        break;
    case 0x603a000bU:
        if(!xx_rt_wcscmp(r->name,L"record_size"))s=L"Byte size of the following preset, including its final next-record-size word; zero ends the chain.";
        break;
    case 0x603a000cU:
        if(!xx_rt_wcscmp(r->name,L"mode_and_key_count"))s=L"High 2 bits: 1 silent, 2 primary voice, 3 dual voice; low 6 bits are the number of keys.";
        else if(!xx_rt_wcscmp(r->name,L"voice_number"))s=L"One-based voice number; zero is silent.";
        else if(!xx_rt_wcscmp(r->name,L"transpose"))s=L"0x10 denotes recorded pitch.";
        break;
    case 0x603a000dU:
        if(!xx_rt_wcscmp(r->name,L"voice_number"))s=L"One-based secondary voice number; zero is silent.";
        break;
    case 0x603a000eU:
        if(!xx_rt_wcscmp(r->name,L"end_marker"))s=L"Stored key-range terminator, normally 00 3D 00 00.";
        break;
    case 0x603a000fU:
        if(!xx_rt_wcscmp(r->name,L"playback_start_minus_one"))s=L"Encoded playback counter, stored address minus one; may be stale when flag 0x10 is set.";
        else if(!xx_rt_wcscmp(r->name,L"preloop_negative_counter"))s=L"0x500000 minus the pre-loop frame count; this is not a byte size.";
        else if(!xx_rt_wcscmp(r->name,L"loop_start_minus_one"))s=L"Encoded loop-start address minus one; may be stale.";
        else if(!xx_rt_wcscmp(r->name,L"loop_negative_counter"))s=L"Counter base (0x500000 or 0x600000) minus loop frames.";
        else if(!xx_rt_wcscmp(r->name,L"fine_tune"))s=L"Signed units of 1/64 semitone.";
        else if(!xx_rt_wcscmp(r->name,L"velocity_attack"))s=L"High nibble controls velocity-to-VCA attack, low nibble velocity-to-VCF attack.";
        else if(!xx_rt_wcscmp(r->name,L"lfo_delay_encoded"))s=L"Delay is (stored value minus one) times 10 milliseconds.";
        else if(!xx_rt_wcscmp(r->name,L"lfo_rate_encoded"))s=L"Encoded LFO-rate value, not Hertz.";
        else if(!xx_rt_wcscmp(r->name,L"filter_keyboard_tracking"))s=L"High nibble controls keyboard tracking; 8 is one octave per octave.";
        else if(!xx_rt_wcscmp(r->name,L"self_pointer_22"))s=L"Sampler CPU address into this voice record, not a file offset.";
        else if(!xx_rt_wcscmp(r->name,L"lfo_pitch_table_address"))s=L"Pointer into the sampler operating system's LFO-depth tables.";
        else if(!xx_rt_wcscmp(r->name,L"filter_flags"))s=L"Bit 7 inverts the filter envelope; other bits remain undecoded.";
        else if(!xx_rt_wcscmp(r->name,L"cutoff_velocity_table"))s=L"Encoded cutoff per velocity zone; entry 0 is the highest velocity.";
        else if(!xx_rt_wcscmp(r->name,L"filter_attack_passes"))s=L"Stored envelope counter passes, not timestamps or byte sizes.";
        else if(!xx_rt_wcscmp(r->name,L"flags"))s=L"0x04 loop enabled; 0x10 counter block stale; 0x08 changes loop counter base to 0x600000. Other bits undecoded.";
        else if(!xx_rt_wcscmp(r->name,L"region_offset"))s=L"Bank-relative sample region; one encoded byte per frame.";
        else if(!xx_rt_wcscmp(r->name,L"slot_frames"))s=L"Sample frames including padding; one encoded byte per frame.";
        else if(!xx_rt_wcscmp(r->name,L"loop_offset"))s=L"Bank-relative sample-loop start.";
        else if(!xx_rt_wcscmp(r->name,L"playback_offset"))s=L"Bank-relative sample-playback start.";
        break;
    case 0x603a0010U:
        if(!xx_rt_wcscmp(r->name,L"area_count"))s=L"Number of keyboard/velocity split areas, at most 64.";
        else if(!xx_rt_wcscmp(r->name,L"midi_channel"))s=L"Zero-based MIDI channel per area.";
        else if(!xx_rt_wcscmp(r->name,L"generator_mask"))s=L"Bits 0..7 enable sound generators 1..8.";
        else if(!xx_rt_wcscmp(r->name,L"voice_number"))s=L"Stored zero-based voice numbers, not the internal-memory pointers used by the running sampler.";
        break;
    case 0x603a0011U:
        if(!xx_rt_wcscmp(r->name,L"wave_start"))s=L"PCM memory word address, two bytes per sample; not a file offset.";
        else if(!xx_rt_wcscmp(r->name,L"sounding_mode"))s=L"Packed generator mode; 0 is silent, 0x101D reverse, 0x2014 cue.";
        else if(!xx_rt_wcscmp(r->name,L"sustain_loop"))s=L"Loop index, 0..8; encoded end/sustain control.";
        else if(!xx_rt_wcscmp(r->name,L"loop_start_encoded"))s=L"Low address bits plus high-byte loop-fine encoding; these packed words are not plain file offsets.";
        else if(!xx_rt_wcscmp(r->name,L"loop_end_encoded"))s=L"Word address with jump-loop flag in bit 31.";
        else if(!xx_rt_wcscmp(r->name,L"loop_time_encoded"))s=L"Encoded duration or repeat count; units depend on loop mode.";
        else if(!xx_rt_wcscmp(r->name,L"pitch_detune"))s=L"Signed pitch in 1/256 semitone units.";
        else if(!xx_rt_wcscmp(r->name,L"amplitude_rate"))s=L"Sign-magnitude envelope rate: bit 7 is decreasing, low 7 bits are the absolute rate.";
        else if(!xx_rt_wcscmp(r->name,L"filter_rate"))s=L"Sign-magnitude envelope rate: bit 7 is decreasing, low 7 bits are the absolute rate.";
        else if(!xx_rt_wcscmp(r->name,L"lfo_delay_encoded"))s=L"Units of 2 milliseconds.";
        else if(!xx_rt_wcscmp(r->name,L"lfo_waveform"))s=L"Low 7 bits select waveform 0..5; bit 7 enables phase synchronization.";
        break;
    case 0x603a0012U:
        if(!xx_rt_wcscmp(r->name,L"pitch_bend_depth"))s=L"Units of 1/8 semitone.";
        break;
    case 0x603a0013U:
        if(!xx_rt_wcscmp(r->name,L"dump_type"))s=L"HxC bare-dump type: 0 full, 2 bank.";
        else if(!xx_rt_wcscmp(r->name,L"opaque_06"))s=L"The native reader requires zero here.";
        else if(!xx_rt_wcscmp(r->name,L"voice_count"))s=L"Stored little-endian counter; current native wrapper validation uses its low byte and permits at most 64 voices.";
        else if(!xx_rt_wcscmp(r->name,L"content_blocks"))s=L"Total content length in 1024-byte blocks in fzdump files; retained as stored.";
        else if(!xx_rt_wcscmp(r->name,L"waveform_blocks"))s=L"Number of 1024-byte waveform blocks; not a byte count.";
        break;
    default:break;}
    return !s||xx_data_struct_record_set_comment(r,s);
}
/* Physical bank records. Optional damaged/stale heap pointers remain raw.
 * Bounds are independent of the native subclass and constructor. */
#define SXSB_LIMIT 24000U
static bool sxsb_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
bool sxsb_read(sx_context*c,uint64_t p,void*b,size_t n){return sxsb_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
uint32_t sxsb16(const uint8_t*b){return (uint32_t)b[0]|(uint32_t)b[1]<<8;}
uint32_t sxsb24(const uint8_t*b){return sxsb16(b)|(uint32_t)b[2]<<16;}
uint32_t sxsb32(const uint8_t*b){return sxsb24(b)|(uint32_t)b[3]<<24;}
bool sxsb_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n){
 const xx_data_struct_field_desc*f=l->fields+l->field_count-1;
 uint64_t z=(uint64_t)(f->rel_offset+f->size);size_t lo=0,hi=c->count;
 if(!n)return true;
 if(n>1048576U||n>(uint64_t)INT64_MAX/z||!sxsb_span(c,p,n*z)||xx_pd_is_stopped(c->pd))return false;
 if(c->count>=SXSB_LIMIT)return true;
 while(lo<hi){size_t m=lo+(hi-lo)/2;uint64_t at=(uint64_t)(c->items[m].offset-c->f->base_address);if(at<p)lo=m+1;else hi=m;}
 if(lo&&c->items[lo-1].offset-c->f->base_address+c->items[lo-1].total_size>(int64_t)p)return true;
 if(lo<c->count&&(uint64_t)(c->items[lo].offset-c->f->base_address)<p+n*z)return true;
 size_t prior=c->count;if(!sx_table(c,l,(int64_t)p,(int64_t)z,n))return false;
 if(lo<prior){xx_data_struct row=c->items[prior];xx_rt_memmove(c->items+lo+1,c->items+lo,(prior-lo)*sizeof(*c->items));c->items[lo]=row;}
 return true;
}
static int sxsb_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxsb_finish(sx_context*c){size_t n=c->count;int64_t end=0;if(!n)return false;xx_rt_qsort(c->items,n,sizeof(*c->items),sxsb_order);for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p<end)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxsb_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
static bool sx_samplebanks_supports(xx_file_type_t t){return t==XX_FILE_TYPE_EMAX_DISK||t==XX_FILE_TYPE_EMULATORII_EII||t==XX_FILE_TYPE_CASIO_FZF;}
static bool sx_samplebanks_build(sx_context*c){if(!c||!c->f||c->size<0||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;switch(c->f->file_type){case XX_FILE_TYPE_EMAX_DISK:ok=sx_emax_disk_build(c);break;case XX_FILE_TYPE_EMULATORII_EII:ok=sx_emulatorii_eii_build(c);break;case XX_FILE_TYPE_CASIO_FZF:ok=sx_casio_fzf_build(c);break;default:break;}return ok&&sxsb_finish(c);}
#undef SXSB_LIMIT
const sx_family sx_samplebanks_family={sx_samplebanks_supports,sx_samplebanks_build,sx_samplebanks_layouts,SX_COUNT(sx_samplebanks_layouts),sx_samplebanks_comment};
