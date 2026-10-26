/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Neuroscan CNT data structures, moved out of the sciencewire schema family. */
#include "../../xx_format_schema_sciencewire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsw_cnt_setup_fields[] = {
    SX_FIELD("revision","char[12]",0,12,SX_STRING),
    SX_FIELD("next_file","int32",12,4,SX_POINTER),
    SX_FIELD("opaque_10","uint8[5]",16,5,SX_NONE),
    SX_FIELD("patient_id","char[20]",21,20,SX_STRING),
    SX_FIELD("opaque_29","uint8[80]",41,80,SX_NONE),
    SX_FIELD("patient_name","char[20]",121,20,SX_STRING),
    SX_FIELD("opaque_8d","uint8[2]",141,2,SX_NONE),
    SX_FIELD("sex","char[1]",143,1,SX_ID),
    SX_FIELD("handedness","char[1]",144,1,SX_ID),
    SX_FIELD("opaque_91","uint8[60]",145,60,SX_NONE),
    SX_FIELD("session_label","char[20]",205,20,SX_STRING),
    SX_FIELD("date","char[10]",225,10,SX_STRING),
    SX_FIELD("time","char[12]",235,12,SX_STRING),
    SX_FIELD("opaque_f7","uint8[123]",247,123,SX_NONE),
    SX_FIELD("channel_count","uint16",370,2,SX_COUNT_PROP),
    SX_FIELD("opaque_174","uint8[4]",372,4,SX_NONE),
    SX_FIELD("sample_rate","uint16",376,2,SX_NONE),
    SX_FIELD("opaque_17a","uint8[24]",378,24,SX_NONE),
    SX_FIELD("eog_channel1","int16",402,2,SX_ID),
    SX_FIELD("eog_channel2","int16",404,2,SX_ID),
    SX_FIELD("opaque_196","uint8[32]",406,32,SX_NONE),
    SX_FIELD("lowpass_enabled","uint8",438,1,SX_FLAGS),
    SX_FIELD("highpass_enabled","uint8",439,1,SX_FLAGS),
    SX_FIELD("opaque_1b8","uint8[424]",440,424,SX_NONE),
    SX_FIELD("sample_count","uint32",864,4,SX_COUNT_PROP),
    SX_FIELD("opaque_364","uint8[1]",868,1,SX_NONE),
    SX_FIELD("low_cutoff","float32",869,4,SX_NONE),
    SX_FIELD("opaque_369","uint8[2]",873,2,SX_NONE),
    SX_FIELD("high_cutoff","float32",875,4,SX_NONE),
    SX_FIELD("opaque_36f","uint8[7]",879,7,SX_NONE),
    SX_FIELD("event_table_offset","uint32",886,4,SX_OFFSET),
    SX_FIELD("continuous_seconds","float32",890,4,SX_NONE),
    SX_FIELD("channel_block_size","int32",894,4,SX_SIZE),
    SX_FIELD("opaque_382","uint8[2]",898,2,SX_NONE),
};
const sx_layout sxsw_cnt_setup = {UINT32_C(0x602d003a),"cnt_setup",sxsw_cnt_setup_fields,SX_COUNT(sxsw_cnt_setup_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_cnt_channel_fields[] = {
    SX_FIELD("label","char[10]",0,10,SX_STRING),
    SX_FIELD("opaque_a","uint8[4]",10,4,SX_NONE),
    SX_FIELD("bad_channel","uint8",14,1,SX_FLAGS),
    SX_FIELD("opaque_f","uint8[4]",15,4,SX_NONE),
    SX_FIELD("x_coordinate","float32",19,4,SX_NONE),
    SX_FIELD("y_coordinate","float32",23,4,SX_NONE),
    SX_FIELD("opaque_1b","uint8[20]",27,20,SX_NONE),
    SX_FIELD("baseline","int16",47,2,SX_NONE),
    SX_FIELD("opaque_31","uint8[10]",49,10,SX_NONE),
    SX_FIELD("sensitivity","float32",59,4,SX_NONE),
    SX_FIELD("opaque_3f","uint8[8]",63,8,SX_NONE),
    SX_FIELD("calibration","float32",71,4,SX_NONE),
};
const sx_layout sxsw_cnt_channel = {UINT32_C(0x602d003b),"cnt_channel",sxsw_cnt_channel_fields,SX_COUNT(sxsw_cnt_channel_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_cnt_event_table_fields[] = {
    SX_FIELD("event_type","uint8",0,1,SX_ID),
    SX_FIELD("event_bytes","int32",1,4,SX_SIZE),
    SX_FIELD("offset","int32",5,4,SX_NONE),
};
const sx_layout sxsw_cnt_event_table = {UINT32_C(0x602d003c),"cnt_event_table",sxsw_cnt_event_table_fields,SX_COUNT(sxsw_cnt_event_table_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_cnt_event1_fields[] = {
    SX_FIELD("stimulus_type","uint16",0,2,SX_ID),
    SX_FIELD("keyboard","uint8",2,1,SX_ID),
    SX_FIELD("keypad_accept","uint8",3,1,SX_FLAGS),
    SX_FIELD("offset","int32",4,4,SX_OFFSET),
};
const sx_layout sxsw_cnt_event1 = {UINT32_C(0x602d003d),"cnt_event1",sxsw_cnt_event1_fields,SX_COUNT(sxsw_cnt_event1_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_cnt_event2_fields[] = {
    SX_FIELD("stimulus_type","uint16",0,2,SX_ID),
    SX_FIELD("keyboard","uint8",2,1,SX_ID),
    SX_FIELD("keypad_accept","uint8",3,1,SX_FLAGS),
    SX_FIELD("offset","int32",4,4,SX_OFFSET),
    SX_FIELD("type","int16",8,2,SX_ID),
    SX_FIELD("code","int16",10,2,SX_ID),
    SX_FIELD("latency","float32",12,4,SX_NONE),
    SX_FIELD("epoch","uint8",16,1,SX_ID),
    SX_FIELD("accept2","uint8",17,1,SX_FLAGS),
    SX_FIELD("accuracy","uint8",18,1,SX_NONE),
};
const sx_layout sxsw_cnt_event2 = {UINT32_C(0x602d003e),"cnt_event2",sxsw_cnt_event2_fields,SX_COUNT(sxsw_cnt_event2_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_cnt_event3_fields[] = {
    SX_FIELD("stimulus_type","uint16",0,2,SX_ID),
    SX_FIELD("keyboard","uint8",2,1,SX_ID),
    SX_FIELD("keypad_accept","uint8",3,1,SX_FLAGS),
    SX_FIELD("global_sample_frame","uint32",4,4,SX_NONE),
    SX_FIELD("type","int16",8,2,SX_ID),
    SX_FIELD("code","int16",10,2,SX_ID),
    SX_FIELD("latency","float32",12,4,SX_NONE),
    SX_FIELD("epoch","uint8",16,1,SX_ID),
    SX_FIELD("accept2","uint8",17,1,SX_FLAGS),
    SX_FIELD("accuracy","uint8",18,1,SX_NONE),
};
const sx_layout sxsw_cnt_event3 = {UINT32_C(0x602d003f),"cnt_event3",sxsw_cnt_event3_fields,SX_COUNT(sxsw_cnt_event3_fields),SX_LE};
static bool sxsw_cnt(sx_context *c)
{
 uint8_t b[900];if(!sx_read(c,0,b,900))return false;uint32_t channels=sxsw16(b+370,false),events=sxsw32(b+886,false);
 if(!sxsw_add(c,&sxsw_cnt_setup,0,900)||!sxsw_table(c,&sxsw_cnt_channel,900,75,channels)||!sx_read(c,events,b,9)||!sxsw_add(c,&sxsw_cnt_event_table,events,9))return false;
 unsigned event_type=b[0];uint32_t bytes=sxsw32(b+1,false),width=event_type==1?8:19;
 return bytes%width==0&&sxsw_table(c,event_type==1?&sxsw_cnt_event1:event_type==3?&sxsw_cnt_event3:&sxsw_cnt_event2,(int64_t)events+9,width,bytes/width);
}
bool sx_neuroscan_cnt_build(sx_context*c)
{
 return sxsw_cnt(c);
}
