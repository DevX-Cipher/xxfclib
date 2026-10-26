/* Copyright (c)2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical music header and table metadata; compressed and unknown bodies stay raw. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_musicfurther.h"
static const xx_data_struct_field_desc sxfurther_fls_sample_descriptor_fields[]={
 SX_FIELD("loop_start_plus_one","uint8",0,1,SX_NONE),
 SX_FIELD("loop_length","uint8",1,1,SX_COUNT_PROP),
 SX_FIELD("data_address","uint16",2,2,SX_ADDRESS),
};
const sx_layout sxfurther_fls_sample_descriptor={UINT32_C(0x60980004),"fls_sample_descriptor",sxfurther_fls_sample_descriptor_fields,SX_COUNT(sxfurther_fls_sample_descriptor_fields),SX_LE};
static const xx_data_struct_field_desc sxfurther_fls_delay_fields[]={
 SX_FIELD("ticks_per_row","uint8",0,1,SX_NONE),
};
const sx_layout sxfurther_fls_delay={UINT32_C(0x60980005),"fls_delay",sxfurther_fls_delay_fields,SX_COUNT(sxfurther_fls_delay_fields),SX_LE};
static const xx_data_struct_field_desc sxfurther_fls_order_fields[]={
 SX_FIELD("pattern_number","uint8",0,1,SX_ID),
};
const sx_layout sxfurther_fls_order={UINT32_C(0x60980006),"fls_order",sxfurther_fls_order_fields,SX_COUNT(sxfurther_fls_order_fields),SX_LE};
static const xx_data_struct_field_desc sxfurther_fls_ornament_step_fields[]={
 SX_FIELD("pitch_shift","int8",0,1,SX_NONE),
};
const sx_layout sxfurther_fls_ornament_step={UINT32_C(0x60980008),"fls_ornament_step",sxfurther_fls_ornament_step_fields,SX_COUNT(sxfurther_fls_ornament_step_fields),SX_LE};
static const xx_data_struct_field_desc sxfurther_fls_sample_tick_fields[]={
 SX_FIELD("amplitude_tone_high","uint8",0,1,SX_FLAGS),
 SX_FIELD("noise_tone_control","uint8",1,1,SX_FLAGS),
 SX_FIELD("tone_low","uint8",2,1,SX_NONE),
};
const sx_layout sxfurther_fls_sample_tick={UINT32_C(0x60980009),"fls_sample_tick",sxfurther_fls_sample_tick_fields,SX_COUNT(sxfurther_fls_sample_tick_fields),SX_LE};
static const sx_layout *const sx_musicfurther_layouts[]={
 &sxfurther_fls_header,
 &sxfurther_fls_pattern_addresses,
 &sxfurther_fls_ornament_address,
 &sxfurther_fls_sample_descriptor,
 &sxfurther_fls_delay,
 &sxfurther_fls_order,
 &sxfurther_fls_orders_end,
 &sxfurther_fls_ornament_step,
 &sxfurther_fls_sample_tick,
};
static bool sx_musicfurther_supports(xx_file_type_t t){return t==XX_FILE_TYPE_DIE_MUSIC_AMADEUSVOXON_FLASHTRACKER;}
static bool sx_musicfurther_build(sx_context*c){if(!c||!c->f||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid||c->size<=0)return false;return sx_amadeusvoxon_flashtracker_build(c);}
static bool sx_musicfurther_comment(xx_data_struct_record*r,uint32_t id){if(!r||!r->name||id<UINT32_C(0x60980001)||id>=UINT32_C(0x60990000))return true;const wchar_t*s=NULL;
 if(r->property&SX_ADDRESS)s=L"Original 16-bit Z80 target address before relocation; bounded metadata mapping follows the original loader's authenticated load base";
 else if(id==sxfurther_fls_sample_descriptor.id){if(!xx_rt_wcscmp(r->name,L"loop_start_plus_one"))s=L"Zero disables the sample loop; otherwise stored value minus one is the first loop tick";else s=L"Stored count of repeated ticks when loop_start_plus_one is nonzero; 32 physical ticks are always stored";}
 else if(id==sxfurther_fls_delay.id)s=L"Playback interrupt ticks per row; not a wall-clock timestamp";
 else if(id==sxfurther_fls_order.id)s=L"One-based pattern-table number; zero ends the stored order list";
 else if(id==sxfurther_fls_ornament_step.id)s=L"Signed semitone pitch shift; 32 stored steps, with replay looping derived from the selected sample";
 else if(id==sxfurther_fls_sample_tick.id){if(!xx_rt_wcscmp(r->name,L"amplitude_tone_high"))s=L"Low nibble AY amplitude; high nibble supplies bits 8..11 of the tone delta magnitude";else if(!xx_rt_wcscmp(r->name,L"noise_tone_control"))s=L"Bits 0..4 signed noise delta; bit 5 selects positive tone delta; bit 6 disables tone; bit 7 disables noise";else s=L"Low 8 bits of the tone delta magnitude; sign is stored in noise_tone_control bit 5";}
 return !s||xx_data_struct_record_set_comment(r,s);
}
const sx_family sx_musicfurther_family={sx_musicfurther_supports,sx_musicfurther_build,sx_musicfurther_layouts,SX_COUNT(sx_musicfurther_layouts),sx_musicfurther_comment};
