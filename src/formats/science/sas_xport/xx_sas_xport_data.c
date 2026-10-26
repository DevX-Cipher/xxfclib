/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SAS XPORT data structures, moved out of the sciencewire schema family. */
#include "../../xx_format_schema_sciencewire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsw_xport_header_record_fields[] = {
    SX_FIELD("prefix","char[20]",0,20,SX_SIGNATURE),
    SX_FIELD("record_name","char[8]",20,8,SX_ID),
    SX_FIELD("suffix","char[20]",28,20,SX_SIGNATURE),
    SX_FIELD("field1","ascii_decimal[5]",48,5,SX_NONE),
    SX_FIELD("field2","ascii_decimal[5]",53,5,SX_NONE),
    SX_FIELD("field3","ascii_decimal[5]",58,5,SX_NONE),
    SX_FIELD("field4","ascii_decimal[5]",63,5,SX_NONE),
    SX_FIELD("field5","ascii_decimal[5]",68,5,SX_NONE),
    SX_FIELD("field6","ascii_decimal[5]",73,5,SX_NONE),
    SX_FIELD("padding","char[2]",78,2,SX_RESERVED),
};
const sx_layout sxsw_xport_header_record = {UINT32_C(0x602d0003),"xport_header_record",sxsw_xport_header_record_fields,SX_COUNT(sxsw_xport_header_record_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_xport_namestr_fields[] = {
    SX_FIELD("type","uint16",0,2,SX_ID),
    SX_FIELD("hash_function","uint16",2,2,SX_RESERVED),
    SX_FIELD("length","uint16",4,2,SX_SIZE),
    SX_FIELD("variable_number","uint16",6,2,SX_ID),
    SX_FIELD("name","char[8]",8,8,SX_STRING),
    SX_FIELD("label","char[40]",16,40,SX_STRING),
    SX_FIELD("format","char[8]",56,8,SX_STRING),
    SX_FIELD("format_width","uint16",64,2,SX_NONE),
    SX_FIELD("format_decimals","uint16",66,2,SX_NONE),
    SX_FIELD("justification","uint16",68,2,SX_ID),
    SX_FIELD("reserved1","char[2]",70,2,SX_RESERVED),
    SX_FIELD("informat","char[8]",72,8,SX_STRING),
    SX_FIELD("informat_width","uint16",80,2,SX_NONE),
    SX_FIELD("informat_decimals","uint16",82,2,SX_NONE),
    SX_FIELD("observation_offset","uint32",84,4,SX_OFFSET),
    SX_FIELD("reserved2","uint8[52]",88,52,SX_RESERVED),
};
const sx_layout sxsw_xport_namestr = {UINT32_C(0x602d0004),"xport_namestr",sxsw_xport_namestr_fields,SX_COUNT(sxsw_xport_namestr_fields),SX_BE};
static bool sxsw_xport(sx_context *c)
{
 uint8_t b[80];int64_t count,at;
 if(!sx_read(c,560,b,80)||!sxsw_text_integer(b+54,4,&count)||count<1||count>4096)return false;
 const int64_t headers[]={0,240,320,560};for(unsigned i=0;i<SX_COUNT(headers);i++)if(!sxsw_add(c,&sxsw_xport_header_record,headers[i],80))return false;
 at=((640+count*140+79)/80)*80;
 return sxsw_table(c,&sxsw_xport_namestr,640,140,(uint64_t)count)&&sxsw_add(c,&sxsw_xport_header_record,at,80);
}
bool sx_sas_xport_build(sx_context*c)
{
 return sxsw_xport(c);
}
