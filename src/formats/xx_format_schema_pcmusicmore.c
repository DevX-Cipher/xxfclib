/* SPDX-License-Identifier: MIT
 * Physical PC tracker and multitrack-container metadata. Encoded samples and synthesizer bodies stay raw.
 * See docs/data_struct_pcmusicmore_scope.txt for format-specific limits. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_pcmusicmore.h"
static const xx_data_struct_field_desc sxpcmore_pcmore_text_fields[]={
 SX_FIELD("text","char",0,0,SX_NONE),
};
const sx_layout sxpcmore_pcmore_text={UINT32_C(0x60990001),"pcmore_text",sxpcmore_pcmore_text_fields,SX_COUNT(sxpcmore_pcmore_text_fields),SX_LE};
static const xx_data_struct_field_desc sxpcmore_webfoot_dmf_panning_fields[]={
 SX_FIELD("panning","int8[32]",0,32,SX_NONE),
};
const sx_layout sxpcmore_webfoot_dmf_panning={UINT32_C(0x60990003),"webfoot_dmf_panning",sxpcmore_webfoot_dmf_panning_fields,SX_COUNT(sxpcmore_webfoot_dmf_panning_fields),SX_LE};
static const xx_data_struct_field_desc sxpcmore_webfoot_dmf_track_reference_fields[]={
 SX_FIELD("logical_track_index","uint16",0,2,SX_NONE),
};
const sx_layout sxpcmore_webfoot_dmf_track_reference={UINT32_C(0x60990006),"webfoot_dmf_track_reference",sxpcmore_webfoot_dmf_track_reference_fields,SX_COUNT(sxpcmore_webfoot_dmf_track_reference_fields),SX_LE};
static const xx_data_struct_field_desc sxpcmore_webfoot_dmf_sample_fields[]={
 SX_FIELD("sample_type","uint8",0,1,SX_ID),
 SX_FIELD("name_remnant","bytes",1,1,SX_NONE),
 SX_FIELD("sample_data_index","uint32",2,4,SX_NONE),
 SX_FIELD("sample_value_count","uint32",6,4,SX_COUNT_PROP),
 SX_FIELD("sample_rate","uint16",10,2,SX_NONE),
 SX_FIELD("volume","uint8",12,1,SX_NONE),
 SX_FIELD("loop_start","uint32",13,4,SX_NONE),
 SX_FIELD("loop_end","uint24le",17,3,SX_NONE),
};
const sx_layout sxpcmore_webfoot_dmf_sample={UINT32_C(0x60990007),"webfoot_dmf_sample",sxpcmore_webfoot_dmf_sample_fields,SX_COUNT(sxpcmore_webfoot_dmf_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxpcmore_webfoot_dmf_track_map_fields[]={
 SX_FIELD("physical_track_index","uint16",0,2,SX_NONE),
};
const sx_layout sxpcmore_webfoot_dmf_track_map={UINT32_C(0x60990008),"webfoot_dmf_track_map",sxpcmore_webfoot_dmf_track_map_fields,SX_COUNT(sxpcmore_webfoot_dmf_track_map_fields),SX_LE};
static const xx_data_struct_field_desc sxpcmore_webfoot_dmf_track_fields[]={
 SX_FIELD("event_count","uint16",0,2,SX_COUNT_PROP),
 SX_FIELD("track_type","uint8",2,1,SX_ID),
};
const sx_layout sxpcmore_webfoot_dmf_track={UINT32_C(0x60990009),"webfoot_dmf_track",sxpcmore_webfoot_dmf_track_fields,SX_COUNT(sxpcmore_webfoot_dmf_track_fields),SX_LE};
static const xx_data_struct_field_desc sxpcmore_webfoot_dmf_event_fields[]={
 SX_FIELD("row_or_control","uint8",0,1,SX_NONE),
 SX_FIELD("command","uint8",1,1,SX_ID),
 SX_FIELD("parameter","uint8",2,1,SX_NONE),
};
const sx_layout sxpcmore_webfoot_dmf_event={UINT32_C(0x6099000A),"webfoot_dmf_event",sxpcmore_webfoot_dmf_event_fields,SX_COUNT(sxpcmore_webfoot_dmf_event_fields),SX_LE};
static const xx_data_struct_field_desc sxpcmore_ixs_compressed_header_fields[]={
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("decoded_it_header_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("decoded_sample_table_offset","int32",8,4,SX_OFFSET),
 SX_FIELD("decoded_synth_table_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("packed_byte_length","uint32",16,4,SX_SIZE),
 SX_FIELD("output_gain","float32",20,4,SX_NONE),
 SX_FIELD("title","char[32]",24,32,SX_NONE),
};
const sx_layout sxpcmore_ixs_compressed_header={UINT32_C(0x6099000B),"ixs_compressed_header",sxpcmore_ixs_compressed_header_fields,SX_COUNT(sxpcmore_ixs_compressed_header_fields),SX_LE};
static const xx_data_struct_field_desc sxpcmore_mdc_header_fields[]={
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("opaque_version_words","bytes",4,4,SX_NONE),
 SX_FIELD("declared_file_byte_length","uint32",8,4,SX_SIZE),
 SX_FIELD("opaque_word","bytes",12,4,SX_NONE),
 SX_FIELD("track_table_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("comment_offset","uint32",20,4,SX_OFFSET),
 SX_FIELD("opaque_settings","bytes",24,20,SX_NONE),
 SX_FIELD("midi_resolution","uint16",44,2,SX_NONE),
 SX_FIELD("opaque_tail","bytes",46,18,SX_NONE),
};
const sx_layout sxpcmore_mdc_header={UINT32_C(0x6099000C),"mdc_header",sxpcmore_mdc_header_fields,SX_COUNT(sxpcmore_mdc_header_fields),SX_BE};
static const xx_data_struct_field_desc sxpcmore_mdc_track_fields[]={
 SX_FIELD("track_data_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("track_id","uint8",4,1,SX_ID),
 SX_FIELD("midi_channel","uint8",5,1,SX_NONE),
 SX_FIELD("opaque_tail","bytes",6,2,SX_NONE),
};
const sx_layout sxpcmore_mdc_track={UINT32_C(0x6099000E),"mdc_track",sxpcmore_mdc_track_fields,SX_COUNT(sxpcmore_mdc_track_fields),SX_BE};
static const xx_data_struct_field_desc sxpcmore_mtc_chunk_fields[]={
 SX_FIELD("chunk_id","char[4]",0,4,SX_ID),
 SX_FIELD("payload_byte_length","uint32",4,4,SX_SIZE),
};
const sx_layout sxpcmore_mtc_chunk={UINT32_C(0x6099000F),"mtc_chunk",sxpcmore_mtc_chunk_fields,SX_COUNT(sxpcmore_mtc_chunk_fields),SX_BE};
static const xx_data_struct_field_desc sxpcmore_skm_chunk_fields[]={
 SX_FIELD("record_id","uint16",0,2,SX_ID),
 SX_FIELD("tag","uint16",2,2,SX_ID),
 SX_FIELD("payload_byte_length","uint32",4,4,SX_SIZE),
};
const sx_layout sxpcmore_skm_chunk={UINT32_C(0x60990010),"skm_chunk",sxpcmore_skm_chunk_fields,SX_COUNT(sxpcmore_skm_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxpcmore_skm_file_payload_fields[]={
 SX_FIELD("signature","char[5]",0,5,SX_SIGNATURE),
 SX_FIELD("serialized_version","uint32",5,4,SX_ID),
};
const sx_layout sxpcmore_skm_file_payload={UINT32_C(0x60990011),"skm_file_payload",sxpcmore_skm_file_payload_fields,SX_COUNT(sxpcmore_skm_file_payload_fields),SX_LE};
static const xx_data_struct_field_desc sxpcmore_skm_song_timing_fields[]={
 SX_FIELD("initial_bpm","uint8",0,1,SX_NONE),
 SX_FIELD("initial_speed","uint8",1,1,SX_NONE),
 SX_FIELD("channel_count","uint8",2,1,SX_COUNT_PROP),
 SX_FIELD("opaque_zero","bytes",3,1,SX_NONE),
 SX_FIELD("serialized_version","uint32",4,4,SX_ID),
};
const sx_layout sxpcmore_skm_song_timing={UINT32_C(0x60990012),"skm_song_timing",sxpcmore_skm_song_timing_fields,SX_COUNT(sxpcmore_skm_song_timing_fields),SX_LE};
static const xx_data_struct_field_desc sxpcmore_skm_message_fields[]={
 SX_FIELD("message_and_padding","char",0,0,SX_NONE),
};
const sx_layout sxpcmore_skm_message={UINT32_C(0x60990014),"skm_message",sxpcmore_skm_message_fields,SX_COUNT(sxpcmore_skm_message_fields),SX_LE};
static const xx_data_struct_field_desc sxpcmore_skm_orders_fields[]={
 SX_FIELD("channel_count","uint8",0,1,SX_COUNT_PROP),
 SX_FIELD("order_pattern_ids","uint8[256]",1,256,SX_NONE),
 SX_FIELD("song_length","uint8",257,1,SX_COUNT_PROP),
 SX_FIELD("repeat_position","uint8",258,1,SX_NONE),
};
const sx_layout sxpcmore_skm_orders={UINT32_C(0x60990015),"skm_orders",sxpcmore_skm_orders_fields,SX_COUNT(sxpcmore_skm_orders_fields),SX_LE};
static const xx_data_struct_field_desc sxpcmore_skm_pattern_fields[]={
 SX_FIELD("pattern_id","uint8",0,1,SX_ID),
 SX_FIELD("row_count","uint16",1,2,SX_COUNT_PROP),
};
const sx_layout sxpcmore_skm_pattern={UINT32_C(0x60990016),"skm_pattern",sxpcmore_skm_pattern_fields,SX_COUNT(sxpcmore_skm_pattern_fields),SX_LE};
static const xx_data_struct_field_desc sxpcmore_skm_track_chunk_fields[]={
 SX_FIELD("record_id","uint8",0,1,SX_ID),
 SX_FIELD("tag","uint8",1,1,SX_ID),
 SX_FIELD("payload_byte_length","uint16",2,2,SX_SIZE),
};
const sx_layout sxpcmore_skm_track_chunk={UINT32_C(0x60990017),"skm_track_chunk",sxpcmore_skm_track_chunk_fields,SX_COUNT(sxpcmore_skm_track_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxpcmore_mvx_connection_fields[]={
 SX_FIELD("source_machine","uint8",0,1,SX_NONE),
 SX_FIELD("target_machine","uint8",1,1,SX_NONE),
 SX_FIELD("volume","uint8",2,1,SX_NONE),
};
const sx_layout sxpcmore_mvx_connection={UINT32_C(0x6099001D),"mvx_connection",sxpcmore_mvx_connection_fields,SX_COUNT(sxpcmore_mvx_connection_fields),SX_LE};
static const sx_layout *const sx_pcmusicmore_layouts[]={
 &sxpcmore_pcmore_text,
 &sxpcmore_webfoot_dmf_header,
 &sxpcmore_webfoot_dmf_panning,
 &sxpcmore_webfoot_dmf_timing,
 &sxpcmore_webfoot_dmf_order,
 &sxpcmore_webfoot_dmf_track_reference,
 &sxpcmore_webfoot_dmf_sample,
 &sxpcmore_webfoot_dmf_track_map,
 &sxpcmore_webfoot_dmf_track,
 &sxpcmore_webfoot_dmf_event,
 &sxpcmore_ixs_compressed_header,
 &sxpcmore_mdc_header,
 &sxpcmore_mdc_track_count,
 &sxpcmore_mdc_track,
 &sxpcmore_mtc_chunk,
 &sxpcmore_skm_chunk,
 &sxpcmore_skm_file_payload,
 &sxpcmore_skm_song_timing,
 &sxpcmore_skm_title,
 &sxpcmore_skm_message,
 &sxpcmore_skm_orders,
 &sxpcmore_skm_pattern,
 &sxpcmore_skm_track_chunk,
 &sxpcmore_skm_channel,
 &sxpcmore_mvx_header,
 &sxpcmore_mvx_machine_id,
 &sxpcmore_mvx_machine_order,
 &sxpcmore_mvx_connection_count,
 &sxpcmore_mvx_connection,
};
#define SXPCMORE_LIMIT 24000U
bool sxpcmore_span(sx_context*c,uint64_t p,uint64_t n){return c&&c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p&&!xx_pd_is_stopped(c->pd);}
bool sxpcmore_read(sx_context*c,uint64_t p,void*b,size_t n){return sxpcmore_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
uint16_t sxpcmore16(const uint8_t*b){return (uint16_t)b[0]|(uint16_t)((uint16_t)b[1]<<8);}
bool sxpcmore_u8(sx_context*c,uint64_t p,uint8_t*v){return sxpcmore_read(c,p,v,1);}
uint64_t sxpcmore_width(const sx_layout*l){const xx_data_struct_field_desc*f=l->fields+l->field_count-1;return (uint64_t)f->rel_offset+(uint64_t)f->size;}
/* Insert only disjoint physical records. Shared pointers are decoded once;
 * conflicting interpretations remain covered by the first authenticated row.
 * Display-budget exhaustion retains earlier metadata and raw remainder. */
bool sxpcmore_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t count){
 uint64_t z=sxpcmore_width(l);if(!count)return true;if(!z||count>UINT64_MAX/z||!sxpcmore_span(c,p,count*z))return false;
 if(c->count>=SXPCMORE_LIMIT)return true;
 uint64_t end=p+count*z;
 for(size_t i=0;i<c->count;i++){int64_t rel=c->items[i].offset-c->f->base_address;uint64_t n=(uint64_t)c->items[i].total_size;
  if(rel>=0&&p<(uint64_t)rel+n&&(uint64_t)rel<end)return true;}
 return count==1?sx_add(c,l,(int64_t)p,(int64_t)z):sx_table(c,l,(int64_t)p,(int64_t)z,(int64_t)count);
}
static int sxpcmore_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset;}
bool sxpcmore_finish(sx_context*c){size_t n=c->count;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxpcmore_order);for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(p<end||z<=0||p>c->size||z>c->size-p)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+z;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxpcmore_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
uint32_t sxpcmore_be32(const uint8_t*b){return (uint32_t)b[0]<<24|(uint32_t)b[1]<<16|(uint32_t)b[2]<<8|b[3];}
static bool sx_pcmusicmore_supports(xx_file_type_t t){switch(t){
case XX_FILE_TYPE_DIE_MUSIC_WEBFOOT_DSMIAMFHACK:
case XX_FILE_TYPE_DIE_MUSIC_SAHARASURFERS_IXALANCE_CO:
case XX_FILE_TYPE_DIE_MUSIC_CULCHAN_MDC:
case XX_FILE_TYPE_DIE_MUSIC_MULTITRACKCONTAINER:
case XX_FILE_TYPE_DIE_MUSIC_BAKTERY_SKALETRACKER_SKM:
case XX_FILE_TYPE_DIE_MUSIC_GARGAJ_MVX_MVM:
return true;default:return false;}}
static bool sx_pcmusicmore_build(sx_context*c){
if(c->f->file_type==XX_FILE_TYPE_DIE_MUSIC_WEBFOOT_DSMIAMFHACK)return sx_webfoot_dsmiamfhack_build(c);
if(c->f->file_type==XX_FILE_TYPE_DIE_MUSIC_SAHARASURFERS_IXALANCE_CO)return sx_saharasurfers_ixalance_co_build(c);
if(c->f->file_type==XX_FILE_TYPE_DIE_MUSIC_CULCHAN_MDC)return sx_culchan_mdc_build(c);
if(c->f->file_type==XX_FILE_TYPE_DIE_MUSIC_MULTITRACKCONTAINER)return sx_multitrackcontainer_build(c);
if(c->f->file_type==XX_FILE_TYPE_DIE_MUSIC_BAKTERY_SKALETRACKER_SKM)return sx_baktery_skaletracker_skm_build(c);
if(c->f->file_type==XX_FILE_TYPE_DIE_MUSIC_GARGAJ_MVX_MVM)return sx_gargaj_mvx_mvm_build(c);
return false;}
static bool sx_pcmusicmore_comment(xx_data_struct_record*r,uint32_t id){
 if(!r||!r->name||id<0x60990000U||id>=0x609a0000U)return true;
 if(id==sxpcmore_webfoot_dmf_panning.id&&!xx_rt_wcscmp(r->name,L"panning"))return xx_data_struct_record_set_comment(r,L"Signed channel pan values, normally -64 through64; value100 selects surround. All32 saved slots are preserved.");
 if(id==sxpcmore_webfoot_dmf_track_reference.id&&!xx_rt_wcscmp(r->name,L"logical_track_index"))return xx_data_struct_record_set_comment(r,L"Stored track reference into the logical track map; zero selects an empty track.");
 if(id==sxpcmore_webfoot_dmf_sample.id&&!xx_rt_wcscmp(r->name,L"name_remnant"))return xx_data_struct_record_set_comment(r,L"One residual byte from the original sample name, retained by the compact writer; no complete text name is stored.");
 if(id==sxpcmore_webfoot_dmf_sample.id&&!xx_rt_wcscmp(r->name,L"sample_data_index"))return xx_data_struct_record_set_comment(r,L"One-based sample-data identity/order, not a source-file byte offset; multiple headers may share sample data.");
 if(id==sxpcmore_webfoot_dmf_sample.id&&!xx_rt_wcscmp(r->name,L"sample_value_count"))return xx_data_struct_record_set_comment(r,L"Number of8-bit mono delta-PCM sample values; encoded audio remains raw.");
 if(id==sxpcmore_webfoot_dmf_sample.id&&!xx_rt_wcscmp(r->name,L"loop_start"))return xx_data_struct_record_set_comment(r,L"Stored sample-value position; loop_end is exclusive and the compact record stores only its low24 bits.");
 if(id==sxpcmore_webfoot_dmf_sample.id&&!xx_rt_wcscmp(r->name,L"loop_end"))return xx_data_struct_record_set_comment(r,L"Stored sample-value position; loop_end is exclusive and the compact record stores only its low24 bits.");
 if(id==sxpcmore_webfoot_dmf_sample.id&&!xx_rt_wcscmp(r->name,L"sample_rate"))return xx_data_struct_record_set_comment(r,L"Stored C-4/C-5 reference sample playback frequency, in hertz; the maintained loader uses it directly as its C-5 speed.");
 if(id==sxpcmore_webfoot_dmf_sample.id&&!xx_rt_wcscmp(r->name,L"volume"))return xx_data_struct_record_set_comment(r,L"Stored linear volume, normally0..64; the physical value is not rescaled.");
 if(id==sxpcmore_webfoot_dmf_track_map.id&&!xx_rt_wcscmp(r->name,L"physical_track_index"))return xx_data_struct_record_set_comment(r,L"One-based packed-track identity; zero selects an empty track, and duplicate identities share the same physical record.");
 if(id==sxpcmore_webfoot_dmf_track.id&&!xx_rt_wcscmp(r->name,L"event_count"))return xx_data_struct_record_set_comment(r,L"Number of physical three-byte event records following this header.");
 if(id==sxpcmore_webfoot_dmf_event.id&&!xx_rt_wcscmp(r->name,L"row_or_control"))return xx_data_struct_record_set_comment(r,L"Stored row index or control byte; the packed track command stream is preserved without playback conversion.");
 if(id==sxpcmore_ixs_compressed_header.id&&!xx_rt_wcscmp(r->name,L"decoded_it_header_offset"))return xx_data_struct_record_set_comment(r,L"Stored byte offset relative to the beginning of the decompressed IXS buffer; this is not an offset into the physical compressed source file.");
 if(id==sxpcmore_ixs_compressed_header.id&&!xx_rt_wcscmp(r->name,L"decoded_sample_table_offset"))return xx_data_struct_record_set_comment(r,L"Stored signed32-bit displacement relative to the decompressed IXS buffer, as loaded by the retained player; this is not a physical compressed-source offset and is never followed here.");
 if(id==sxpcmore_ixs_compressed_header.id&&!xx_rt_wcscmp(r->name,L"decoded_synth_table_offset"))return xx_data_struct_record_set_comment(r,L"Stored byte offset relative to the beginning of the decompressed IXS buffer; this is not an offset into the physical compressed source file.");
 if(id==sxpcmore_ixs_compressed_header.id&&!xx_rt_wcscmp(r->name,L"output_gain"))return xx_data_struct_record_set_comment(r,L"Original player multiplies final audio by this IEEE754 output-volume value; the physical float is retained unchanged.");
 if(id==sxpcmore_ixs_compressed_header.id&&!xx_rt_wcscmp(r->name,L"packed_byte_length"))return xx_data_struct_record_set_comment(r,L"Byte length of the zlib-compressed body immediately after the56-byte physical header; the body remains raw.");
 if(id==sxpcmore_mdc_header.id&&!xx_rt_wcscmp(r->name,L"opaque_version_words"))return xx_data_struct_record_set_comment(r,L"Native identification expects bytes00080040; no independent field names are established for these stored words.");
 if(id==sxpcmore_mdc_header.id&&!xx_rt_wcscmp(r->name,L"midi_resolution"))return xx_data_struct_record_set_comment(r,L"Stored MIDI ticks per quarter note, read by the maintained MDC converter.");
 if(id==sxpcmore_mdc_track.id&&!xx_rt_wcscmp(r->name,L"track_data_offset"))return xx_data_struct_record_set_comment(r,L"Stored byte displacement relative to the track-count word at track_table_offset; not relative to this entry or the whole module.");
 if(id==sxpcmore_mdc_track.id&&!xx_rt_wcscmp(r->name,L"midi_channel"))return xx_data_struct_record_set_comment(r,L"Stored MIDI channel identifier; the converter applies its own output-channel mapping.");
 if(id==sxpcmore_mtc_chunk.id&&!xx_rt_wcscmp(r->name,L"payload_byte_length"))return xx_data_struct_record_set_comment(r,L"Payload bytes excluding the8-byte header and the optional one-byte padding used for two-byte alignment.");
 if(id==sxpcmore_mtc_chunk.id&&!xx_rt_wcscmp(r->name,L"chunk_id"))return xx_data_struct_record_set_comment(r,L"MTC1 contains global metadata and TRCK chunks; TRCK contains DATA and metadata. Other payloads remain raw unless their literal text grammar is known.");
 if(id==sxpcmore_skm_chunk.id&&!xx_rt_wcscmp(r->name,L"record_id"))return xx_data_struct_record_set_comment(r,L"Stored record representation/version identifier; meaning is local to the enclosing list.");
 if(id==sxpcmore_skm_chunk.id&&!xx_rt_wcscmp(r->name,L"tag"))return xx_data_struct_record_set_comment(r,L"Stored section or nested-record tag;0xFFFF terminates a full-width chunk list.");
 if(id==sxpcmore_skm_file_payload.id&&!xx_rt_wcscmp(r->name,L"serialized_version"))return xx_data_struct_record_set_comment(r,L"Stored writer version multiplied by10000; later0.80/0.81 application saves may still contain7600. It does not select instrument layout.");
 if(id==sxpcmore_skm_message.id&&!xx_rt_wcscmp(r->name,L"message_and_padding"))return xx_data_struct_record_set_comment(r,L"Physical message region including trailing NUL padding, bounded by the final8-byte timing trailer; no fixed ten-byte footer is assumed.");
 if(id==sxpcmore_skm_song_timing.id&&!xx_rt_wcscmp(r->name,L"opaque_zero"))return xx_data_struct_record_set_comment(r,L"Byte observed zero in the retained authentic application saves; no independent semantic meaning is asserted.");
 if(id==sxpcmore_skm_orders.id&&!xx_rt_wcscmp(r->name,L"order_pattern_ids"))return xx_data_struct_record_set_comment(r,L"All256 saved pattern-ID slots; entries beyond song_length may contain inactive saved state.");
 if(id==sxpcmore_skm_orders.id&&!xx_rt_wcscmp(r->name,L"repeat_position"))return xx_data_struct_record_set_comment(r,L"Stored zero-based order-list restart position, not a byte offset.");
 if(id==sxpcmore_skm_pattern.id&&!xx_rt_wcscmp(r->name,L"row_count"))return xx_data_struct_record_set_comment(r,L"Little-endian row count, including256 encoded as0001; event bytes are kept raw.");
 if(id==sxpcmore_skm_track_chunk.id&&!xx_rt_wcscmp(r->name,L"tag"))return xx_data_struct_record_set_comment(r,L"Tag1 holds a channel-index byte and encoded events;0xFF ends the half-width track list.");
 if(id==sxpcmore_mvx_connection.id&&!xx_rt_wcscmp(r->name,L"source_machine"))return xx_data_struct_record_set_comment(r,L"Stored machine-graph source identifier; the native format rule accepts the endpoint equal to machine_count.");
 if(id==sxpcmore_mvx_connection.id&&!xx_rt_wcscmp(r->name,L"target_machine"))return xx_data_struct_record_set_comment(r,L"Stored machine-graph target identifier; deeper machine synthesis state remains raw.");
 if(id==sxpcmore_mvx_connection.id&&!xx_rt_wcscmp(r->name,L"volume"))return xx_data_struct_record_set_comment(r,L"Stored connection-volume byte; no gain normalization is asserted without original serializer evidence.");
 if(r->property&SX_OFFSET)return xx_data_struct_record_set_comment(r,L"Stored byte offset relative to the module start, unless the enclosing structure specifies another origin.");
 if(r->property&SX_ADDRESS)return xx_data_struct_record_set_comment(r,L"Encoded target-machine memory address; the field source-file offset is shown separately.");
 return true;
}
const sx_family sx_pcmusicmore_family={sx_pcmusicmore_supports,sx_pcmusicmore_build,sx_pcmusicmore_layouts,SX_COUNT(sx_pcmusicmore_layouts),sx_pcmusicmore_comment};
