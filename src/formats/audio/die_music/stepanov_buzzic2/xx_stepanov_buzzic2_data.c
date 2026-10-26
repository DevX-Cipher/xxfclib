/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Stepanov Buzzic2 data structures, moved out of the musiclate schema family. */
#include "../../../xx_format_schema_musiclate.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxlate_buzz2_counts_fields[]={
 SX_FIELD("pattern_count","int32",0,4,SX_COUNT_PROP),
 SX_FIELD("sequence_count","int32",4,4,SX_COUNT_PROP),
};
const sx_layout sxlate_buzz2_counts={0x60930002U,"buzz2_counts",sxlate_buzz2_counts_fields,SX_COUNT(sxlate_buzz2_counts_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_buzz2_capacities_fields[]={
 SX_FIELD("pattern_capacity","int32",0,4,SX_COUNT_PROP),
 SX_FIELD("sequence_capacity","int32",4,4,SX_COUNT_PROP),
 SX_FIELD("sequence_length","int32",8,4,SX_COUNT_PROP),
};
const sx_layout sxlate_buzz2_capacities={0x60930003U,"buzz2_capacities",sxlate_buzz2_capacities_fields,SX_COUNT(sxlate_buzz2_capacities_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_buzz2_pattern_fields[]={
 SX_FIELD("note","uint8[16]",0,16,SX_NONE),
};
const sx_layout sxlate_buzz2_pattern={0x60930004U,"buzz2_pattern",sxlate_buzz2_pattern_fields,SX_COUNT(sxlate_buzz2_pattern_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_buzz2_sequence_fields[]={
 SX_FIELD("pattern_index","uint8",0,0,SX_NONE),
};
const sx_layout sxlate_buzz2_sequence={0x60930005U,"buzz2_sequence",sxlate_buzz2_sequence_fields,SX_COUNT(sxlate_buzz2_sequence_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_buzz2_name_fields[]={
 SX_FIELD("name","char[64]",0,64,SX_NONE),
};
const sx_layout sxlate_buzz2_name={0x60930006U,"buzz2_name",sxlate_buzz2_name_fields,SX_COUNT(sxlate_buzz2_name_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_buzz2_instrument_count_fields[]={
 SX_FIELD("instrument_count","int32",0,4,SX_COUNT_PROP),
};
const sx_layout sxlate_buzz2_instrument_count={0x60930007U,"buzz2_instrument_count",sxlate_buzz2_instrument_count_fields,SX_COUNT(sxlate_buzz2_instrument_count_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_buzz2_connection_fields[]={
 SX_FIELD("source_operation","int32",0,4,SX_NONE),
 SX_FIELD("destination_operation","int32",4,4,SX_NONE),
 SX_FIELD("input_index","int32",8,4,SX_NONE),
};
const sx_layout sxlate_buzz2_connection={0x60930009U,"buzz2_connection",sxlate_buzz2_connection_fields,SX_COUNT(sxlate_buzz2_connection_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_buzz2_instrument_tail_fields[]={
 SX_FIELD("connection_count","int32",0,4,SX_COUNT_PROP),
 SX_FIELD("program","uint8[1024]",4,1024,SX_NONE),
 SX_FIELD("program_bytes","int32",1028,4,SX_SIZE),
 SX_FIELD("unused","uint8[128]",1032,128,SX_NONE),
};
const sx_layout sxlate_buzz2_instrument_tail={0x6093000aU,"buzz2_instrument_tail",sxlate_buzz2_instrument_tail_fields,SX_COUNT(sxlate_buzz2_instrument_tail_fields),SX_LE};
static bool sxlate_buzz2(sx_context*c)
{
    uint64_t end=(uint64_t)c->size,p=156;uint8_t h[8];uint32_t patterns=64,sequences=64,length=128,instruments;
    if(!sxlate_read(c,0,h,8,end)||xx_rt_memcmp(h,"buz2",4)||xx_data_get_u16(h,8,4,false)!=2||!sxlate_row(c,&sxlate_buzz2_header,0,156,end)||!sxlate_row(c,&sxlate_buzz2_counts,p,8,end))return false;
    p+=8;
    if(xx_data_get_u16(h,8,6,false)){
        if(!sxlate_row(c,&sxlate_buzz2_capacities,p,12,end)||!sxlate_u32(c,p,&patterns,end)||!sxlate_u32(c,p+4,&sequences,end)||!sxlate_u32(c,p+8,&length,end))return false;
        p+=12;
    }
    if(patterns>1024||sequences>1024||!length||length>4096)return true;
    if(!sxlate_table(c,&sxlate_buzz2_pattern,&p,16,patterns,end))return false;
    for(uint32_t i=0;i<sequences;i++)if(!sxlate_plane(c,&sxlate_buzz2_sequence,&p,length,end))return false;
    if(!sxlate_table(c,&sxlate_buzz2_name,&p,64,128,end)||!sxlate_u32(c,p,&instruments,end)||!sxlate_row(c,&sxlate_buzz2_instrument_count,p,4,end))return false;
    p+=4;if(instruments>128)return true;
    for(uint32_t i=0;i<instruments;i++){
        uint32_t operations;
        if(!sxlate_u32(c,p+388,&operations,end)||!sxlate_row(c,&sxlate_buzz2_instrument,p,392,end))return false;
        p+=392;
        if(!sxlate_table(c,&sxlate_buzz2_connection,&p,12,640,end)||!sxlate_row(c,&sxlate_buzz2_instrument_tail,p,1160,end))return false;
        p+=1160;
        if(operations>64)return true;
        if(!sxlate_table(c,&sxlate_buzz2_operation,&p,552,operations,end))return false;
    }
    return true;
}
bool sx_stepanov_buzzic2_build(sx_context*c)
{
    return sxlate_buzz2(c);
}
