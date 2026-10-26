/* SPDX-License-Identifier: MIT. Independently implemented physical music records. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_musiclate.h"
static const xx_data_struct_field_desc sxlate_buzz2_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version_major","uint16",4,2,SX_NONE),
 SX_FIELD("version_minor","uint16",6,2,SX_NONE),
 SX_FIELD("master_volume","float",8,4,SX_NONE),
 SX_FIELD("tempo_bpm","int32",12,4,SX_NONE),
 SX_FIELD("start_sequence","int32",16,4,SX_NONE),
 SX_FIELD("end_sequence","int32",20,4,SX_NONE),
 SX_FIELD("looping","uint8",24,1,SX_NONE),
 SX_FIELD("unused","uint8[128]",25,128,SX_NONE),
 SX_FIELD("alignment_padding","uint8[3]",153,3,SX_NONE),
};
const sx_layout sxlate_buzz2_header={0x60930001U,"buzz2_header",sxlate_buzz2_header_fields,SX_COUNT(sxlate_buzz2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_buzz2_instrument_fields[]={
 SX_FIELD("name","char[128]",0,128,SX_NONE),
 SX_FIELD("muted","uint8",128,1,SX_NONE),
 SX_FIELD("note","int8",129,1,SX_NONE),
 SX_FIELD("note_length","int8",130,1,SX_NONE),
 SX_FIELD("volume","int8",131,1,SX_NONE),
 SX_FIELD("operation_pointer_snapshot","uint32le[64]",132,256,SX_ADDRESS),
 SX_FIELD("operation_count","int32",388,4,SX_COUNT_PROP),
};
const sx_layout sxlate_buzz2_instrument={0x60930008U,"buzz2_instrument",sxlate_buzz2_instrument_fields,SX_COUNT(sxlate_buzz2_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_buzz2_operation_fields[]={
 SX_FIELD("vtable_snapshot","uint32",0,4,SX_ADDRESS),
 SX_FIELD("type","int32",4,4,SX_NONE),
 SX_FIELD("name","char[128]",8,128,SX_NONE),
 SX_FIELD("width","int32",136,4,SX_NONE),
 SX_FIELD("height","int32",140,4,SX_NONE),
 SX_FIELD("x","int32",144,4,SX_NONE),
 SX_FIELD("y","int32",148,4,SX_NONE),
 SX_FIELD("opcode","int32",152,4,SX_NONE),
 SX_FIELD("input_count","int32",156,4,SX_COUNT_PROP),
 SX_FIELD("parameter_count","int32",160,4,SX_COUNT_PROP),
 SX_FIELD("parameter_0","float",164,4,SX_NONE),
 SX_FIELD("parameter_1","float",168,4,SX_NONE),
 SX_FIELD("parameter_2","float",172,4,SX_NONE),
 SX_FIELD("parameter_3","float",176,4,SX_NONE),
 SX_FIELD("parameter_4","float",180,4,SX_NONE),
 SX_FIELD("parameter_5","float",184,4,SX_NONE),
 SX_FIELD("parameter_6","float",188,4,SX_NONE),
 SX_FIELD("parameter_7","float",192,4,SX_NONE),
 SX_FIELD("parameter_8","float",196,4,SX_NONE),
 SX_FIELD("parameter_9","float",200,4,SX_NONE),
 SX_FIELD("parameter_10","float",204,4,SX_NONE),
 SX_FIELD("parameter_11","float",208,4,SX_NONE),
 SX_FIELD("parameter_12","float",212,4,SX_NONE),
 SX_FIELD("parameter_13","float",216,4,SX_NONE),
 SX_FIELD("parameter_14","float",220,4,SX_NONE),
 SX_FIELD("parameter_15","float",224,4,SX_NONE),
 SX_FIELD("parameter_type","int32le[16]",228,64,SX_NONE),
 SX_FIELD("parameter_name_0","char[16]",292,16,SX_NONE),
 SX_FIELD("parameter_name_1","char[16]",308,16,SX_NONE),
 SX_FIELD("parameter_name_2","char[16]",324,16,SX_NONE),
 SX_FIELD("parameter_name_3","char[16]",340,16,SX_NONE),
 SX_FIELD("parameter_name_4","char[16]",356,16,SX_NONE),
 SX_FIELD("parameter_name_5","char[16]",372,16,SX_NONE),
 SX_FIELD("parameter_name_6","char[16]",388,16,SX_NONE),
 SX_FIELD("parameter_name_7","char[16]",404,16,SX_NONE),
 SX_FIELD("parameter_name_8","char[16]",420,16,SX_NONE),
 SX_FIELD("parameter_name_9","char[16]",436,16,SX_NONE),
 SX_FIELD("parameter_name_10","char[16]",452,16,SX_NONE),
 SX_FIELD("parameter_name_11","char[16]",468,16,SX_NONE),
 SX_FIELD("parameter_name_12","char[16]",484,16,SX_NONE),
 SX_FIELD("parameter_name_13","char[16]",500,16,SX_NONE),
 SX_FIELD("parameter_name_14","char[16]",516,16,SX_NONE),
 SX_FIELD("parameter_name_15","char[16]",532,16,SX_NONE),
 SX_FIELD("background_color","uint32",548,4,SX_NONE),
};
const sx_layout sxlate_buzz2_operation={0x6093000bU,"buzz2_operation",sxlate_buzz2_operation_fields,SX_COUNT(sxlate_buzz2_operation_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_jxs_subsong_fields[]={
 SX_FIELD("reserved_0","uint8[64]",0,64,SX_NONE),
 SX_FIELD("channel_muted","uint8[16]",64,16,SX_NONE),
 SX_FIELD("step_delay","int32",80,4,SX_NONE),
 SX_FIELD("groove","int32",84,4,SX_NONE),
 SX_FIELD("start_position","int32",88,4,SX_NONE),
 SX_FIELD("start_step","int32",92,4,SX_NONE),
 SX_FIELD("end_position","int32",96,4,SX_NONE),
 SX_FIELD("end_step","int32",100,4,SX_NONE),
 SX_FIELD("loop_position","int32",104,4,SX_NONE),
 SX_FIELD("loop_step","int32",108,4,SX_NONE),
 SX_FIELD("loop_enabled","int16",112,2,SX_NONE),
 SX_FIELD("name","char[32]",114,32,SX_NONE),
 SX_FIELD("channel_count","int16",146,2,SX_COUNT_PROP),
 SX_FIELD("echo_delay","uint16",148,2,SX_NONE),
 SX_FIELD("channel_echo_amount","uint8[16]",150,16,SX_NONE),
 SX_FIELD("amplification","int16",166,2,SX_NONE),
 SX_FIELD("reserved_1","uint8[12]",168,12,SX_NONE),
};
const sx_layout sxlate_jxs_subsong={0x6093000dU,"jxs_subsong",sxlate_jxs_subsong_fields,SX_COUNT(sxlate_jxs_subsong_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_jxs_sample_info_fields[]={
 SX_FIELD("sample_path","char[192]",0,192,SX_NONE),
 SX_FIELD("reserved","uint8[50]",192,50,SX_NONE),
 SX_FIELD("sharing","int16",242,2,SX_NONE),
 SX_FIELD("loop_enabled","int16",244,2,SX_NONE),
 SX_FIELD("bidirectional_loop","int16",246,2,SX_NONE),
 SX_FIELD("start_point","int32",248,4,SX_NONE),
 SX_FIELD("loop_point","int32",252,4,SX_NONE),
 SX_FIELD("end_point","int32",256,4,SX_NONE),
 SX_FIELD("sample_pointer_snapshot","int32",260,4,SX_ADDRESS),
 SX_FIELD("sample_bytes","int32",264,4,SX_SIZE),
};
const sx_layout sxlate_jxs_sample_info={0x60930014U,"jxs_sample_info",sxlate_jxs_sample_info_fields,SX_COUNT(sxlate_jxs_sample_info_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_ixs_instrument_fields[]={
 SX_FIELD("fadeout","uint16",0,2,SX_NONE),
 SX_FIELD("global_volume","uint8",2,1,SX_NONE),
 SX_FIELD("default_pan","uint8",3,1,SX_NONE),
 SX_FIELD("first_note","uint8",4,1,SX_NONE),
 SX_FIELD("first_sample_and_map_flag","uint8",5,1,SX_FLAGS),
};
const sx_layout sxlate_ixs_instrument={0x6093001aU,"ixs_instrument",sxlate_ixs_instrument_fields,SX_COUNT(sxlate_ixs_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_ixs_pattern_fields[]={
 SX_FIELD("packed_bytes","uint16",0,2,SX_SIZE),
 SX_FIELD("row_count","uint16",2,2,SX_COUNT_PROP),
};
const sx_layout sxlate_ixs_pattern={0x60930020U,"ixs_pattern",sxlate_ixs_pattern_fields,SX_COUNT(sxlate_ixs_pattern_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_opx_text_header_fields[]={
 SX_FIELD("title","uint8[53]",0,53,SX_NONE),
 SX_FIELD("title_ending","uint8[2]",53,2,SX_NONE),
 SX_FIELD("memo","uint8[53]",55,53,SX_NONE),
 SX_FIELD("memo_ending","uint8[2]",108,2,SX_NONE),
 SX_FIELD("code","uint8[13]",110,13,SX_NONE),
 SX_FIELD("code_ending","uint8[2]",123,2,SX_NONE),
 SX_FIELD("text_eof","uint8",125,1,SX_NONE),
 SX_FIELD("unknown_tail","uint8[2]",126,2,SX_NONE),
};
const sx_layout sxlate_opx_text_header={0x60930021U,"opx_text_header",sxlate_opx_text_header_fields,SX_COUNT(sxlate_opx_text_header_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_opx_info_fields[]={
 SX_FIELD("unknown_80","uint8[2]",0,2,SX_NONE),
 SX_FIELD("fm_voice_count","uint8",2,1,SX_COUNT_PROP),
 SX_FIELD("unknown_83","uint8",3,1,SX_NONE),
 SX_FIELD("envelope_count","uint8",4,1,SX_COUNT_PROP),
 SX_FIELD("mode_flags","uint8",5,1,SX_FLAGS),
 SX_FIELD("version","uint8",6,1,SX_NONE),
 SX_FIELD("track_0_offset","uint16",7,2,SX_OFFSET),
 SX_FIELD("track_1_offset","uint16",9,2,SX_OFFSET),
 SX_FIELD("track_2_offset","uint16",11,2,SX_OFFSET),
 SX_FIELD("track_3_offset","uint16",13,2,SX_OFFSET),
 SX_FIELD("track_4_offset","uint16",15,2,SX_OFFSET),
 SX_FIELD("track_5_offset","uint16",17,2,SX_OFFSET),
 SX_FIELD("track_6_offset","uint16",19,2,SX_OFFSET),
 SX_FIELD("track_7_offset","uint16",21,2,SX_OFFSET),
 SX_FIELD("track_8_offset","uint16",23,2,SX_OFFSET),
 SX_FIELD("track_9_offset","uint16",25,2,SX_OFFSET),
 SX_FIELD("track_10_offset","uint16",27,2,SX_OFFSET),
 SX_FIELD("track_11_offset","uint16",29,2,SX_OFFSET),
};
const sx_layout sxlate_opx_info={0x60930022U,"opx_info",sxlate_opx_info_fields,SX_COUNT(sxlate_opx_info_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_c670_header_fields[]={
 SX_FIELD("speed","uint8",0,1,SX_NONE),
 SX_FIELD("order_count","uint8",1,1,SX_COUNT_PROP),
 SX_FIELD("pattern_count","uint8",2,1,SX_COUNT_PROP),
 SX_FIELD("sample_count","uint8",3,1,SX_COUNT_PROP),
 SX_FIELD("fm_instrument_count","uint8",4,1,SX_COUNT_PROP),
 SX_FIELD("loop_order","uint8",5,1,SX_NONE),
 SX_FIELD("sample_offset","uint32",6,4,SX_OFFSET),
};
const sx_layout sxlate_c670_header={0x60930023U,"c670_header",sxlate_c670_header_fields,SX_COUNT(sxlate_c670_header_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_c670_pattern_offset_fields[]={
 SX_FIELD("relative_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxlate_c670_pattern_offset={0x60930027U,"c670_pattern_offset",sxlate_c670_pattern_offset_fields,SX_COUNT(sxlate_c670_pattern_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_c670_delay_fields[]={
 SX_FIELD("command","uint8",0,1,SX_NONE),
 SX_FIELD("row_delay","uint8",1,1,SX_NONE),
};
const sx_layout sxlate_c670_delay={0x6093002aU,"c670_delay",sxlate_c670_delay_fields,SX_COUNT(sxlate_c670_delay_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_c670_end_fields[]={
 SX_FIELD("command","uint8",0,1,SX_NONE),
};
const sx_layout sxlate_c670_end={0x6093002bU,"c670_end",sxlate_c670_end_fields,SX_COUNT(sxlate_c670_end_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_quartet_header_fields[]={
 SX_FIELD("sampling_rate_khz","uint16",0,2,SX_NONE),
 SX_FIELD("measure","uint16",2,2,SX_NONE),
 SX_FIELD("tempo","uint16",4,2,SX_NONE),
 SX_FIELD("time_signature_numerator","uint8",6,1,SX_NONE),
 SX_FIELD("time_signature_denominator","uint8",7,1,SX_NONE),
 SX_FIELD("reserved","uint8[4]",8,4,SX_NONE),
 SX_FIELD("timer_tag","char[2]",12,2,SX_NONE),
 SX_FIELD("timer_rate","uint16",14,2,SX_NONE),
};
const sx_layout sxlate_quartet_header={0x6093002cU,"quartet_header",sxlate_quartet_header_fields,SX_COUNT(sxlate_quartet_header_fields),SX_BE};
static const xx_data_struct_field_desc sxlate_quartet_sequence_fields[]={
 SX_FIELD("command","uint16",0,2,SX_NONE),
 SX_FIELD("length","uint16",2,2,SX_NONE),
 SX_FIELD("step","uint32",4,4,SX_NONE),
 SX_FIELD("parameter","uint32",8,4,SX_NONE),
};
const sx_layout sxlate_quartet_sequence={0x6093002dU,"quartet_sequence",sxlate_quartet_sequence_fields,SX_COUNT(sxlate_quartet_sequence_fields),SX_BE};
static const xx_data_struct_field_desc sxlate_ultima6_header_fields[]={
 SX_FIELD("unpacked_bytes","uint32",0,4,SX_SIZE),
};
const sx_layout sxlate_ultima6_header={0x6093002eU,"ultima6_header",sxlate_ultima6_header_fields,SX_COUNT(sxlate_ultima6_header_fields),SX_LE};
static const sx_layout*const sx_musiclate_layouts[]={&sxlate_buzz2_header,&sxlate_buzz2_counts,&sxlate_buzz2_capacities,&sxlate_buzz2_pattern,&sxlate_buzz2_sequence,&sxlate_buzz2_name,&sxlate_buzz2_instrument_count,&sxlate_buzz2_instrument,&sxlate_buzz2_connection,&sxlate_buzz2_instrument_tail,&sxlate_buzz2_operation,&sxlate_jxs_header,&sxlate_jxs_subsong,&sxlate_jxs_order,&sxlate_jxs_event,&sxlate_jxs_pattern_name_size,&sxlate_jxs_pattern_name,&sxlate_jxs_instrument,&sxlate_jxs_effect,&sxlate_jxs_sample_info,&sxlate_jxs_wave,&sxlate_jxs_arpeggio,&sxlate_ixs_header,&sxlate_ixs_orders,&sxlate_ixs_record_tag,&sxlate_ixs_instrument,&sxlate_ixs_keyboard,&sxlate_ixs_envelope_flags,&sxlate_ixs_envelope,&sxlate_ixs_envelope_point,&sxlate_ixs_sample,&sxlate_ixs_pattern,&sxlate_opx_text_header,&sxlate_opx_info,&sxlate_c670_header,&sxlate_c670_sample,&sxlate_c670_fm_instrument,&sxlate_c670_orders,&sxlate_c670_pattern_offset,&sxlate_c670_note,&sxlate_c670_volume,&sxlate_c670_delay,&sxlate_c670_end,&sxlate_quartet_header,&sxlate_quartet_sequence,&sxlate_ultima6_header};
bool sxlate_span(sx_context*c,uint64_t p,uint64_t n,uint64_t end)
{return c&&c->size>=0&&end<=(uint64_t)c->size&&p<=end&&n<=end-p&&!xx_pd_is_stopped(c->pd);}
bool sxlate_read(sx_context*c,uint64_t p,void*b,size_t n,uint64_t end)
{return sxlate_span(c,p,n,end)&&sx_read(c,(int64_t)p,b,n);}
bool sxlate_byte(sx_context*c,uint64_t p,uint8_t*b,uint64_t end)
{return sxlate_read(c,p,b,1,end);}
bool sxlate_row(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n,uint64_t end)
{return sxlate_span(c,p,n,end)&&sx_add(c,l,(int64_t)p,(int64_t)n);}
bool sxlate_plane(sx_context*c,const sx_layout*l,uint64_t*p,uint64_t n,uint64_t end)
{
    if(!sxlate_span(c,*p,n,end))return false;
    uint64_t shown=n>4096?4096:n;
    if(shown&&!sx_add(c,l,(int64_t)*p,(int64_t)shown))return false;
    *p+=n;return true;
}
static bool sxlate_string(sx_context*c,const sx_layout*l,uint64_t*p,uint64_t end)
{
    uint64_t start=*p;uint8_t b;
    while(*p<end&&*p-start<4096){
        if(!sxlate_byte(c,(*p)++,&b,end))return false;
        if(!b)return sxlate_row(c,l,start,*p-start,end);
    }
    return false;
}
static int sxlate_order(const void*a,const void*b)
{const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxlate_finish(sx_context*c)
{
    size_t n=c->count;uint64_t end=0;
    xx_rt_qsort(c->items,n,sizeof(*c->items),sxlate_order);
    for(size_t i=0;i<n;i++){
        uint64_t at=(uint64_t)(c->items[i].offset-c->f->base_address),z=(uint64_t)c->items[i].total_size;
        if(at<end)return false;
        if(at>end&&!sx_raw(c,(int64_t)end,(int64_t)(at-end)))return false;
        end=at+z;
    }
    if(end<(uint64_t)c->size&&!sx_raw(c,(int64_t)end,c->size-(int64_t)end))return false;
    xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxlate_order);
    return !c->failed&&!xx_pd_is_stopped(c->pd);
}
bool sxlate_table(sx_context*c,const sx_layout*l,uint64_t*p,uint64_t stride,uint64_t count,uint64_t end)
{
    if(!stride||count>UINT64_MAX/stride||!sxlate_span(c,*p,count*stride,end))return false;
    if(count&&!sx_table(c,l,(int64_t)*p,(int64_t)stride,count))return false;
    *p+=count*stride;return true;
}
bool sxlate_u32(sx_context*c,uint64_t p,uint32_t*v,uint64_t end)
{return sxlate_span(c,p,4,end)&&sx_u32(c,(int64_t)p,false,v);}
static bool sx_musiclate_supports(xx_file_type_t t)
{
    switch(t){
    case XX_FILE_TYPE_DIE_MUSIC_STEPANOV_BUZZIC2:
    case XX_FILE_TYPE_DIE_MUSIC_RHINO_JAYTRAXSYNTRAX_JXS:
    case XX_FILE_TYPE_DIE_MUSIC_SAHARASURFERS_IXALANCE_IXS_UNP:
    case XX_FILE_TYPE_DIE_MUSIC_MSXPERFORMER_OPX:
    case XX_FILE_TYPE_DIE_MUSIC_TRAN_CDFM_COMPOSER670_CO:
    case XX_FILE_TYPE_DIE_MUSIC_MICRODEAL_QUARTET_SMP:
    case XX_FILE_TYPE_DIE_MUSIC_ORIGINSYSTEMS_ULTIMA6:return true;
    default:return false;
    }
}
static bool sx_musiclate_build(sx_context*c)
{
    if(!c||!c->f||!sx_musiclate_supports(c->f->file_type)||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid||c->size<0)return false;
    bool ok=false;
    switch(c->f->file_type){
    case XX_FILE_TYPE_DIE_MUSIC_STEPANOV_BUZZIC2:ok=sx_stepanov_buzzic2_build(c);break;
    case XX_FILE_TYPE_DIE_MUSIC_RHINO_JAYTRAXSYNTRAX_JXS:ok=sx_rhino_jaytraxsyntrax_jxs_build(c);break;
    case XX_FILE_TYPE_DIE_MUSIC_SAHARASURFERS_IXALANCE_IXS_UNP:ok=sx_saharasurfers_ixalance_ixs_unp_build(c);break;
    case XX_FILE_TYPE_DIE_MUSIC_MSXPERFORMER_OPX:ok=sx_msxperformer_opx_build(c);break;
    case XX_FILE_TYPE_DIE_MUSIC_TRAN_CDFM_COMPOSER670_CO:ok=sx_tran_cdfm_composer670_co_build(c);break;
    case XX_FILE_TYPE_DIE_MUSIC_MICRODEAL_QUARTET_SMP:ok=sx_microdeal_quartet_smp_build(c);break;
    case XX_FILE_TYPE_DIE_MUSIC_ORIGINSYSTEMS_ULTIMA6:ok=sx_originsystems_ultima6_build(c);break;
    default:break;
    }
    return ok&&sxlate_finish(c);
}
static bool sx_musiclate_comment(xx_data_struct_record*r,uint32_t id)
{
    if(!r||!r->name||id<0x60930001U||id>sxlate_ultima6_header.id)return true;
    const wchar_t*s=L"Physical stored member; music playback and decoded or generated payload values are not represented here.";
    if(id==sxlate_buzz2_header.id)s=L"Original Buzzic2 Win32 file header, including its three stored alignment bytes. Version halves are little-endian; master volume is IEEE754 binary32.";
    else if(id==sxlate_buzz2_operation.id||id==sxlate_buzz2_instrument.id)s=L"Original Win32 object snapshot. Pointer and vtable values are stored 32-bit snapshots, never dereferenced. Operator parameters preserve IEEE754 binary32 values.";
    else if(id==sxlate_jxs_sample_info.id)s=L"Stored Jaytrax sample metadata. A nonzero saved sample pointer means sample_bytes follow the sixteen waveform tables. No virtual pointer is used.";
    else if(id==sxlate_jxs_subsong.id)s=L"Packed Jaytrax subsong metadata followed by sixteen channels of 256 order records. Stored signed integers are preserved.";
    else if(id==sxlate_ixs_instrument.id)s=L"High bit of first_sample_and_map_flag suppresses the remaining 119 keyboard mappings; they are synthesized by the player and are not physical file members.";
    else if(id==sxlate_ixs_pattern.id)s=L"The packed pattern byte count excludes this four-byte header. Event decompression and external sample caches are outside this physical view.";
    else if(id==sxlate_opx_text_header.id)s=L"Original MSX OPLLdriver2 title, memo and code byte ranges. Encoded text bytes are preserved without a lossy character conversion.";
    else if(id==sxlate_opx_info.id)s=L"Track offsets are relative to the music-data block and are bounded by the original driver's 16 KiB storage. Unproven information bytes remain explicitly unknown.";
    else if(id==sxlate_c670_pattern_offset.id)s=L"Little-endian byte offset relative to the beginning of compact .670 pattern data, immediately after the instrument records.";
    else if(id==sxlate_c670_delay.id)s=L"DELAY: command class 010xxxxx; the low five command bits are ignored by the original player. row_delay advances the pattern. The following command starts after two bytes.";
    else if(id==sxlate_c670_end.id)s=L"END_PATTERN: command class 011xxxxx; the low five command bits are ignored by the original player.";
    else if(id==sxlate_c670_header.id)s=L"Compact Composer670 header from the author's converter source. sample_offset is an absolute file offset; playback speed is not beats per minute.";
    else if(id==sxlate_quartet_header.id)s=L"Quartet score header, stored big-endian. A WT timer tag enables the trailing timer rate; without WT those bytes are reserved.";
    else if(id==sxlate_quartet_sequence.id)s=L"Stored 12-byte Quartet score command. F ends a channel, P plays, S slides, R rests, L/l control loops, V selects a voice. Parameter interpretation depends on the command.";
    else if(id==sxlate_ultima6_header.id)s=L"Ultima 6 LZW container header. unpacked_bytes is the stored output length; the compressed music stream stays raw.";
    return xx_data_struct_record_set_comment(r,s);
}
const sx_family sx_musiclate_family={sx_musiclate_supports,sx_musiclate_build,sx_musiclate_layouts,SX_COUNT(sx_musiclate_layouts),sx_musiclate_comment};
