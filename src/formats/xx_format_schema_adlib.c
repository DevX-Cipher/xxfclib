/* SPDX-License-Identifier: MIT
 * Physical AdLib-family layouts; native-supported variants only.
 * Original bounded schemas based on native readers and upstream wire-field facts.
 * Scope and references: docs/data_struct_adlib_scope.txt. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_adlib.h"
static const sx_layout *const sx_adlib_layouts[] = {
    &sxad_adlib_rad_header,
    &sxad_adlib_rad_instrument,
    &sxad_adlib_instrument_end,
    &sxad_adlib_rad_order_count,
    &sxad_adlib_rad_order,
    &sxad_adlib_rad_pattern_offset,
    &sxad_adlib_rad_row,
    &sxad_adlib_rad_event,
    &sxad_adlib_rad_effect_event,
    &sxad_adlib_hsc_instrument,
    &sxad_adlib_hsc_order,
    &sxad_adlib_hsc_event,
    &sxad_adlib_zero_terminator,
    &sxad_adlib_d00_header,
    &sxad_adlib_d00_subsong,
    &sxad_adlib_d00_order_header,
    &sxad_adlib_d00_order_word,
    &sxad_adlib_d00_sequence_offset,
    &sxad_adlib_d00_sequence_word,
    &sxad_adlib_d00_instrument,
    &sxad_adlib_d00_data_info_end,
    &sxad_adlib_bnk_header,
    &sxad_adlib_bnk_name,
    &sxad_adlib_bnk_instrument,
    &sxad_adlib_bam_header,
    &sxad_adlib_bam_command,
    &sxad_adlib_bam_note,
    &sxad_adlib_bam_instrument,
    &sxad_adlib_bam_jump,
    &sxad_adlib_bmf_signature,
    &sxad_adlib_bmf_settings,
    &sxad_adlib_bmf_instrument,
    &sxad_adlib_bmf_stream_flags,
    &sxad_adlib_bmf_note_or_control,
    &sxad_adlib_bmf_loop,
    &sxad_adlib_bmf_note_delay,
    &sxad_adlib_bmf_note_command,
    &sxad_adlib_bmf_note_delay_command,
    &sxad_adlib_dfm_header,
    &sxad_adlib_dfm_instrument_name,
    &sxad_adlib_dfm_instrument,
    &sxad_adlib_dfm_order,
    &sxad_adlib_dfm_pattern_count,
    &sxad_adlib_dfm_pattern_header,
    &sxad_adlib_dfm_note,
    &sxad_adlib_dfm_note_effect,
    &sxad_adlib_lds_header,
    &sxad_adlib_lds_patch,
    &sxad_adlib_lds_position_count,
    &sxad_adlib_lds_position,
    &sxad_adlib_lds_digital_count,
    &sxad_adlib_lds_pattern_word,
    &sxad_adlib_rol_header,
    &sxad_adlib_rol_tempo_count,
    &sxad_adlib_rol_tempo_event,
    &sxad_adlib_rol_note_header,
    &sxad_adlib_rol_note_event,
    &sxad_adlib_rol_event_header,
    &sxad_adlib_rol_instrument_event,
    &sxad_adlib_rol_volume_event,
    &sxad_adlib_rol_pitch_event,
    &sxad_adlib_jbm_header,
    &sxad_adlib_jbm_sequence_offset,
    &sxad_adlib_jbm_order,
    &sxad_adlib_jbm_end,
    &sxad_adlib_jbm_instrument_select,
    &sxad_adlib_jbm_note,
    &sxad_adlib_jbm_instrument,
    &sxad_adlib_xsm_header,
    &sxad_adlib_xsm_instrument,
    &sxad_adlib_xsm_note,
    &sxad_adlib_ksm_header,
    &sxad_adlib_ksm_event,
    &sxad_adlib_raw_header,
    &sxad_adlib_raw_command,
    &sxad_adlib_raw_timer,
    &sxad_adlib_raw_metadata_tag,
};
static bool sx_adlib_comment(xx_data_struct_record *r,uint32_t id)
{
    if(!r||!r->name||id<UINT32_C(0x600f0000)||id>=UINT32_C(0x60100000))return true;
    const wchar_t *comment=NULL;
    switch(id){
    case UINT32_C(0x600f0001):
        if(!xx_rt_wcscmp(r->name,L"flags"))comment=L"Low five bits: initial speed; bit6: slow timer; bit7: description present. Native reader accepts RAD1.0 only.";
        break;
    case UINT32_C(0x600f0005):
        if(!xx_rt_wcscmp(r->name,L"pattern_or_jump"))comment=L"Bit7 selects a jump to the low7-bit order index; otherwise a pattern number.";
        break;
    case UINT32_C(0x600f0006):
        if(!xx_rt_wcscmp(r->name,L"pattern_offset"))comment=L"Byte offset from the beginning of the RAD file; zero means absent.";
        break;
    case UINT32_C(0x600f0007):
        if(!xx_rt_wcscmp(r->name,L"row_flags"))comment=L"Bits0..6: row number; bit7: last row in this pattern.";
        break;
    case UINT32_C(0x600f0008):
        if(!xx_rt_wcscmp(r->name,L"channel_flags"))comment=L"Low nibble: channel; bit7: final channel entry in the row.";
        if(!xx_rt_wcscmp(r->name,L"note_octave"))comment=L"Low4 bits: note; bits4..6: octave; bit7 supplies instrument bit4.";
        if(!xx_rt_wcscmp(r->name,L"instrument_effect"))comment=L"Instrument and effect selector bits; nonzero low nibble has a following parameter.";
        break;
    case UINT32_C(0x600f0009):
        if(!xx_rt_wcscmp(r->name,L"channel_flags"))comment=L"Low nibble: channel; bit7: final channel entry in the row.";
        if(!xx_rt_wcscmp(r->name,L"note_octave"))comment=L"Low4 bits: note; bits4..6: octave; bit7 supplies instrument bit4.";
        if(!xx_rt_wcscmp(r->name,L"instrument_effect"))comment=L"Instrument and effect selector bits; nonzero low nibble has a following parameter.";
        break;
    case UINT32_C(0x600f000a):
        if(!xx_rt_wcscmp(r->name,L"carrier_characteristics"))comment=L"Encoded HSC instrument byte; slide uses the high nibble, and scale-level bits require HSC conversion.";
        if(!xx_rt_wcscmp(r->name,L"modulator_characteristics"))comment=L"Encoded HSC instrument byte; slide uses the high nibble, and scale-level bits require HSC conversion.";
        if(!xx_rt_wcscmp(r->name,L"carrier_scale_level"))comment=L"Encoded HSC instrument byte; slide uses the high nibble, and scale-level bits require HSC conversion.";
        if(!xx_rt_wcscmp(r->name,L"modulator_scale_level"))comment=L"Encoded HSC instrument byte; slide uses the high nibble, and scale-level bits require HSC conversion.";
        if(!xx_rt_wcscmp(r->name,L"carrier_attack_decay"))comment=L"Encoded HSC instrument byte; slide uses the high nibble, and scale-level bits require HSC conversion.";
        if(!xx_rt_wcscmp(r->name,L"modulator_attack_decay"))comment=L"Encoded HSC instrument byte; slide uses the high nibble, and scale-level bits require HSC conversion.";
        if(!xx_rt_wcscmp(r->name,L"carrier_sustain_release"))comment=L"Encoded HSC instrument byte; slide uses the high nibble, and scale-level bits require HSC conversion.";
        if(!xx_rt_wcscmp(r->name,L"modulator_sustain_release"))comment=L"Encoded HSC instrument byte; slide uses the high nibble, and scale-level bits require HSC conversion.";
        if(!xx_rt_wcscmp(r->name,L"feedback_connection"))comment=L"Encoded HSC instrument byte; slide uses the high nibble, and scale-level bits require HSC conversion.";
        if(!xx_rt_wcscmp(r->name,L"carrier_waveform"))comment=L"Encoded HSC instrument byte; slide uses the high nibble, and scale-level bits require HSC conversion.";
        if(!xx_rt_wcscmp(r->name,L"modulator_waveform"))comment=L"Encoded HSC instrument byte; slide uses the high nibble, and scale-level bits require HSC conversion.";
        if(!xx_rt_wcscmp(r->name,L"slide_encoded"))comment=L"Encoded HSC instrument byte; slide uses the high nibble, and scale-level bits require HSC conversion.";
        break;
    case UINT32_C(0x600f000b):
        if(!xx_rt_wcscmp(r->name,L"pattern_or_jump_or_end"))comment=L"0..127: pattern; bit7: order jump; values0xB2..0xFF end the order list.";
        break;
    case UINT32_C(0x600f000c):
        if(!xx_rt_wcscmp(r->name,L"note_or_instrument"))comment=L"Bit7 selects an instrument-change event; otherwise a note, with127 for key-off.";
        if(!xx_rt_wcscmp(r->name,L"effect_or_instrument"))comment=L"Instrument index when byte0 bit7 is set; otherwise packed effect and parameter.";
        break;
    case UINT32_C(0x600f0011):
        if(!xx_rt_wcscmp(r->name,L"order_word"))comment=L"Sequence index, transpose command,0xFFFE end,0xFFFF loop, or loop target word according to position.";
        break;
    case UINT32_C(0x600f0013):
        if(!xx_rt_wcscmp(r->name,L"event_word"))comment=L"Encoded D00 event/effect word;0xFFFF terminates the sequence. Playback/effect expansion is outside the schema.";
        break;
    case UINT32_C(0x600f001a):
        if(!xx_rt_wcscmp(r->name,L"command_channel"))comment=L"High nibble: command; low nibble: channel/label. Bytes>=0x80 encode delay.";
        break;
    case UINT32_C(0x600f001c):
        if(!xx_rt_wcscmp(r->name,L"modulator_characteristics"))comment=L"Encoded OPL2 register value.";
        if(!xx_rt_wcscmp(r->name,L"carrier_characteristics"))comment=L"Encoded OPL2 register value.";
        if(!xx_rt_wcscmp(r->name,L"modulator_scale_level"))comment=L"Encoded OPL2 register value.";
        if(!xx_rt_wcscmp(r->name,L"carrier_scale_level"))comment=L"Encoded OPL2 register value.";
        if(!xx_rt_wcscmp(r->name,L"modulator_attack_decay"))comment=L"Encoded OPL2 register value.";
        if(!xx_rt_wcscmp(r->name,L"carrier_attack_decay"))comment=L"Encoded OPL2 register value.";
        if(!xx_rt_wcscmp(r->name,L"modulator_sustain_release"))comment=L"Encoded OPL2 register value.";
        if(!xx_rt_wcscmp(r->name,L"carrier_sustain_release"))comment=L"Encoded OPL2 register value.";
        if(!xx_rt_wcscmp(r->name,L"modulator_waveform"))comment=L"Encoded OPL2 register value.";
        if(!xx_rt_wcscmp(r->name,L"carrier_waveform"))comment=L"Encoded OPL2 register value.";
        if(!xx_rt_wcscmp(r->name,L"feedback_connection"))comment=L"Encoded OPL2 register value.";
        break;
    case UINT32_C(0x600f001d):
        if(!xx_rt_wcscmp(r->name,L"repeat_mode"))comment=L"0: end loop;254: endless;255: chorus; other values: repetition count.";
        break;
    case UINT32_C(0x600f001f):
        if(!xx_rt_wcscmp(r->name,L"instrument_mask"))comment=L"Bits31..0 indicate which of32 instrument records are present.";
        break;
    case UINT32_C(0x600f0021):
        if(!xx_rt_wcscmp(r->name,L"channel_mask"))comment=L"Bits31..23 indicate which of9 channel streams are present.";
        break;
    case UINT32_C(0x600f0022):
        if(!xx_rt_wcscmp(r->name,L"note_or_control"))comment=L"0xFE ends stream;0x7D loops; ordinary values encode a note and optional-field bit.";
        break;
    case UINT32_C(0x600f0023):
        if(!xx_rt_wcscmp(r->name,L"repeat_count_encoded"))comment=L"Low6 bits encode repeat count; playback decrements by one.";
        break;
    case UINT32_C(0x600f0024):
        if(!xx_rt_wcscmp(r->name,L"delay_flags"))comment=L"Low6 bits: delay; bit7 indicates delay; bit6 announces a following command.";
        break;
    case UINT32_C(0x600f0025):
        if(!xx_rt_wcscmp(r->name,L"command"))comment=L"0x20..0x3F select instrument;0x40..0x7F select volume.";
        break;
    case UINT32_C(0x600f002a):
        if(!xx_rt_wcscmp(r->name,L"pattern_or_end"))comment=L"0x80 ends the order list; preceding values index stored patterns.";
        break;
    case UINT32_C(0x600f002d):
        if(!xx_rt_wcscmp(r->name,L"note_flags"))comment=L"Packed octave/note; bit7 announces an effect byte, low nibble0xF is key-off.";
        break;
    case UINT32_C(0x600f002e):
        if(!xx_rt_wcscmp(r->name,L"effect_parameter"))comment=L"Top3 bits: effect selector; low5 bits: parameter or instrument index.";
        break;
    case UINT32_C(0x600f0030):
        if(!xx_rt_wcscmp(r->name,L"digital_start"))comment=L"Encoded digital-sound parameter, ignored by the native FM reader; no address/unit conversion is inferred.";
        if(!xx_rt_wcscmp(r->name,L"digital_size"))comment=L"Encoded digital-sound parameter ignored by the native FM reader; no byte-size unit is inferred.";
        break;
    case UINT32_C(0x600f0032):
        if(!xx_rt_wcscmp(r->name,L"pattern_offset"))comment=L"Byte offset from the pattern-word pool; physical value is even.";
        if(!xx_rt_wcscmp(r->name,L"transpose_flags"))comment=L"Bit7 selects instrument transposition; bits0..6 encode a signed7-bit transpose.";
        break;
    case UINT32_C(0x600f0034):
        if(!xx_rt_wcscmp(r->name,L"event_word"))comment=L"Encoded note/instrument or command word; duration/loop semantics remain encoded.";
        break;
    case UINT32_C(0x600f003e):
        if(!xx_rt_wcscmp(r->name,L"flags"))comment=L"Bit0 selects AdLib rhythm mode.";
        break;
    case UINT32_C(0x600f0040):
        if(!xx_rt_wcscmp(r->name,L"sequence_or_end"))comment=L"0xFF ends a voice order list; other values index the sequence table.";
        break;
    case UINT32_C(0x600f0043):
        if(!xx_rt_wcscmp(r->name,L"note_flags"))comment=L"Low7 bits: note; bit7: key-off.";
        if(!xx_rt_wcscmp(r->name,L"delay_minus_one"))comment=L"Encoded duration; playback adds one tick.";
        break;
    case UINT32_C(0x600f0044):
        if(!xx_rt_wcscmp(r->name,L"modulator_characteristics"))comment=L"Encoded JBM OPL value; scale-level bytes invert low6 output bits; byte8 packs both waveforms and feedback.";
        if(!xx_rt_wcscmp(r->name,L"modulator_scale_level_encoded"))comment=L"Encoded JBM OPL value; scale-level bytes invert low6 output bits; byte8 packs both waveforms and feedback.";
        if(!xx_rt_wcscmp(r->name,L"modulator_attack_decay"))comment=L"Encoded JBM OPL value; scale-level bytes invert low6 output bits; byte8 packs both waveforms and feedback.";
        if(!xx_rt_wcscmp(r->name,L"modulator_sustain_release"))comment=L"Encoded JBM OPL value; scale-level bytes invert low6 output bits; byte8 packs both waveforms and feedback.";
        if(!xx_rt_wcscmp(r->name,L"carrier_characteristics"))comment=L"Encoded JBM OPL value; scale-level bytes invert low6 output bits; byte8 packs both waveforms and feedback.";
        if(!xx_rt_wcscmp(r->name,L"carrier_scale_level_encoded"))comment=L"Encoded JBM OPL value; scale-level bytes invert low6 output bits; byte8 packs both waveforms and feedback.";
        if(!xx_rt_wcscmp(r->name,L"carrier_attack_decay"))comment=L"Encoded JBM OPL value; scale-level bytes invert low6 output bits; byte8 packs both waveforms and feedback.";
        if(!xx_rt_wcscmp(r->name,L"carrier_sustain_release"))comment=L"Encoded JBM OPL value; scale-level bytes invert low6 output bits; byte8 packs both waveforms and feedback.";
        if(!xx_rt_wcscmp(r->name,L"waveforms_feedback"))comment=L"Encoded JBM OPL value; scale-level bytes invert low6 output bits; byte8 packs both waveforms and feedback.";
        break;
    case UINT32_C(0x600f0046):
        if(!xx_rt_wcscmp(r->name,L"modulator_characteristics"))comment=L"Encoded OPL2 register value.";
        if(!xx_rt_wcscmp(r->name,L"carrier_characteristics"))comment=L"Encoded OPL2 register value.";
        if(!xx_rt_wcscmp(r->name,L"modulator_scale_level"))comment=L"Encoded OPL2 register value.";
        if(!xx_rt_wcscmp(r->name,L"carrier_scale_level"))comment=L"Encoded OPL2 register value.";
        if(!xx_rt_wcscmp(r->name,L"modulator_attack_decay"))comment=L"Encoded OPL2 register value.";
        if(!xx_rt_wcscmp(r->name,L"carrier_attack_decay"))comment=L"Encoded OPL2 register value.";
        if(!xx_rt_wcscmp(r->name,L"modulator_sustain_release"))comment=L"Encoded OPL2 register value.";
        if(!xx_rt_wcscmp(r->name,L"carrier_sustain_release"))comment=L"Encoded OPL2 register value.";
        if(!xx_rt_wcscmp(r->name,L"modulator_waveform"))comment=L"Encoded OPL2 register value.";
        if(!xx_rt_wcscmp(r->name,L"carrier_waveform"))comment=L"Encoded OPL2 register value.";
        if(!xx_rt_wcscmp(r->name,L"feedback_connection"))comment=L"Encoded OPL2 register value.";
        break;
    case UINT32_C(0x600f0049):
        if(!xx_rt_wcscmp(r->name,L"packed_note_event"))comment=L"Bits0..5: note;6..7: note/volume action;8..11: track;12..31: event tick. Not a wall-clock timestamp.";
        break;
    case UINT32_C(0x600f004b):
        if(!xx_rt_wcscmp(r->name,L"register_or_command"))comment=L"0: delay;2: timer/chip control;other values: OPL register;0xFFFF pair ends stream.";
        break;
    case UINT32_C(0x600f004d):
        if(!xx_rt_wcscmp(r->name,L"tag"))comment=L"0x1A title;0x1B author;0x1C description; following NUL-terminated bytes remain raw.";
        break;
    default: break;
    }
    return !comment||xx_data_struct_record_set_comment(r,comment);
}
/* All offsets are relative to the original device base. No reader factories or
 * playback are invoked. The native reader validates supported variants; these
 * walkers independently bound every physical record, count and pointer. */
bool sxad_byte(sx_context *c,int64_t at,uint8_t *v){return sx_read(c,at,v,1);}
bool sxad_tag(sx_context *c,int64_t at,const char *tag,size_t n)
{
    uint8_t b[16];return n<=sizeof(b)&&sx_read(c,at,b,n)&&!xx_rt_memcmp(b,tag,n);
}
bool sxad_zraw(sx_context *c,int64_t *at,size_t limit)
{
    int64_t start=*at;uint8_t v;
    for(size_t i=0;i<limit;i++){if(!sxad_byte(c,*at,&v))return false;(*at)++;if(!v)return sx_raw(c,start,*at-start);}return false;
}
bool sxad_header(sx_context *c,const sx_layout *l,int64_t *at,int64_t size)
{
    if(!sx_add(c,l,*at,size))return false;*at+=size;return true;
}
/* Fill uninterpreted physical gaps after constructing nonoverlapping records.
 * Sorting a compact interval view avoids quadratic work for sequential events. */
typedef struct sxad_interval {int64_t start,end;} sxad_interval;
static int sxad_compare_interval(const void *a,const void *b)
{
    const sxad_interval *x=a,*y=b;return x->start<y->start?-1:x->start>y->start?1:0;
}
static bool sxad_fill_gaps(sx_context *c)
{
    size_t n=c->count;if(!n||n>100000)return false;
    sxad_interval *ranges=xx_mem_alloc(n*sizeof(*ranges));if(!ranges)return false;
    for(size_t i=0;i<n;i++){ranges[i].start=c->items[i].offset-c->f->base_address;ranges[i].end=ranges[i].start+c->items[i].total_size;}
    xx_rt_qsort(ranges,n,sizeof(*ranges),sxad_compare_interval);int64_t end=0;bool ok=true;
    for(size_t i=0;i<n;i++){
        if(ranges[i].start<end){ok=false;break;}
        if(ranges[i].start>end&&!sx_raw(c,end,ranges[i].start-end)){ok=false;break;}end=ranges[i].end;
    }if(ok&&end<c->size)ok=sx_raw(c,end,c->size-end);xx_mem_free(ranges);return ok;
}
static bool sx_adlib_supports(xx_file_type_t type)
{
    switch(type){
    case XX_FILE_TYPE_ADLIB_RAD:case XX_FILE_TYPE_ADLIB_HSC:case XX_FILE_TYPE_ADLIB_D00:
    case XX_FILE_TYPE_ADLIB_BNK:case XX_FILE_TYPE_ADLIB_BAM:case XX_FILE_TYPE_ADLIB_BMF:
    case XX_FILE_TYPE_ADLIB_DFM:case XX_FILE_TYPE_ADLIB_LDS:case XX_FILE_TYPE_ADLIB_ROL:
    case XX_FILE_TYPE_ADLIB_JBM:case XX_FILE_TYPE_ADLIB_XSM:case XX_FILE_TYPE_KEN_KSM:case XX_FILE_TYPE_RDOS_RAW:return true;
    default:return false;
    }
}
static bool sx_adlib_build(sx_context *c)
{
    bool ok=false;
    switch(c->f->file_type){
    case XX_FILE_TYPE_ADLIB_RAD:ok=sx_adlib_rad_build(c);break;case XX_FILE_TYPE_ADLIB_HSC:ok=sx_adlib_hsc_build(c);break;
    case XX_FILE_TYPE_ADLIB_D00:ok=sx_adlib_d00_build(c);break;case XX_FILE_TYPE_ADLIB_BNK:ok=sx_adlib_bnk_build(c);break;
    case XX_FILE_TYPE_ADLIB_BAM:ok=sx_adlib_bam_build(c);break;case XX_FILE_TYPE_ADLIB_BMF:ok=sx_adlib_bmf_build(c);break;
    case XX_FILE_TYPE_ADLIB_DFM:ok=sx_adlib_dfm_build(c);break;case XX_FILE_TYPE_ADLIB_LDS:ok=sx_adlib_lds_build(c);break;
    case XX_FILE_TYPE_ADLIB_ROL:ok=sx_adlib_rol_build(c);break;case XX_FILE_TYPE_ADLIB_JBM:ok=sx_adlib_jbm_build(c);break;
    case XX_FILE_TYPE_ADLIB_XSM:ok=sx_adlib_xsm_build(c);break;case XX_FILE_TYPE_KEN_KSM:ok=sx_ken_ksm_build(c);break;
    case XX_FILE_TYPE_RDOS_RAW:ok=sx_rdos_raw_build(c);break;default:return false;
    }
    return ok&&sxad_fill_gaps(c);
}
const sx_family sx_adlib_family={sx_adlib_supports,sx_adlib_build,sx_adlib_layouts,SX_COUNT(sx_adlib_layouts),sx_adlib_comment};
