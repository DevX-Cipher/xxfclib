/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * kafka record batch data structures, moved out of the binaryextra schema family. */
#include "../../xx_format_schema_binaryextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxbx_kafka_batch_fields[] = {
 SX_FIELD("base_offset","int64",0,8,SX_NONE),
 SX_FIELD("batch_length","int32",8,4,SX_SIZE),
 SX_FIELD("partition_leader_epoch","int32",12,4,SX_NONE),
 SX_FIELD("magic","int8",16,1,SX_SIGNATURE),
 SX_FIELD("crc32c","uint32",17,4,SX_CHECKSUM),
 SX_FIELD("attributes","int16",21,2,SX_FLAGS),
 SX_FIELD("last_offset_delta","int32",23,4,SX_NONE),
 SX_FIELD("base_timestamp","int64",27,8,SX_NONE),
 SX_FIELD("max_timestamp","int64",35,8,SX_NONE),
 SX_FIELD("producer_id","int64",43,8,SX_ID),
 SX_FIELD("producer_epoch","int16",51,2,SX_NONE),
 SX_FIELD("base_sequence","int32",53,4,SX_NONE),
 SX_FIELD("record_count","int32",57,4,SX_COUNT_PROP),
};
const sx_layout sxbx_kafka_batch = {UINT32_C(0x6030002a),"kafka_batch",sxbx_kafka_batch_fields,SX_COUNT(sxbx_kafka_batch_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_kafka_attributes_fields[] = {
 SX_FIELD("attributes","int8",0,1,SX_FLAGS),
};
const sx_layout sxbx_kafka_attributes = {UINT32_C(0x6030002b),"kafka_attributes",sxbx_kafka_attributes_fields,SX_COUNT(sxbx_kafka_attributes_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_record_size1_fields[] = {
 SX_FIELD("record_size","zigzag32",0,1,SX_SIZE),
};
const sx_layout sxbx_kafka_record_size1 = {UINT32_C(0x6030002c),"kafka_record_size1",sxbx_kafka_record_size1_fields,SX_COUNT(sxbx_kafka_record_size1_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_record_size2_fields[] = {
 SX_FIELD("record_size","zigzag32",0,2,SX_SIZE),
};
const sx_layout sxbx_kafka_record_size2 = {UINT32_C(0x6030002d),"kafka_record_size2",sxbx_kafka_record_size2_fields,SX_COUNT(sxbx_kafka_record_size2_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_record_size3_fields[] = {
 SX_FIELD("record_size","zigzag32",0,3,SX_SIZE),
};
const sx_layout sxbx_kafka_record_size3 = {UINT32_C(0x6030002e),"kafka_record_size3",sxbx_kafka_record_size3_fields,SX_COUNT(sxbx_kafka_record_size3_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_record_size4_fields[] = {
 SX_FIELD("record_size","zigzag32",0,4,SX_SIZE),
};
const sx_layout sxbx_kafka_record_size4 = {UINT32_C(0x6030002f),"kafka_record_size4",sxbx_kafka_record_size4_fields,SX_COUNT(sxbx_kafka_record_size4_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_record_size5_fields[] = {
 SX_FIELD("record_size","zigzag32",0,5,SX_SIZE),
};
const sx_layout sxbx_kafka_record_size5 = {UINT32_C(0x60300030),"kafka_record_size5",sxbx_kafka_record_size5_fields,SX_COUNT(sxbx_kafka_record_size5_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_record_size6_fields[] = {
 SX_FIELD("record_size","zigzag32",0,6,SX_SIZE),
};
const sx_layout sxbx_kafka_record_size6 = {UINT32_C(0x60300031),"kafka_record_size6",sxbx_kafka_record_size6_fields,SX_COUNT(sxbx_kafka_record_size6_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_record_size7_fields[] = {
 SX_FIELD("record_size","zigzag32",0,7,SX_SIZE),
};
const sx_layout sxbx_kafka_record_size7 = {UINT32_C(0x60300032),"kafka_record_size7",sxbx_kafka_record_size7_fields,SX_COUNT(sxbx_kafka_record_size7_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_record_size8_fields[] = {
 SX_FIELD("record_size","zigzag32",0,8,SX_SIZE),
};
const sx_layout sxbx_kafka_record_size8 = {UINT32_C(0x60300033),"kafka_record_size8",sxbx_kafka_record_size8_fields,SX_COUNT(sxbx_kafka_record_size8_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_record_size9_fields[] = {
 SX_FIELD("record_size","zigzag32",0,9,SX_SIZE),
};
const sx_layout sxbx_kafka_record_size9 = {UINT32_C(0x60300034),"kafka_record_size9",sxbx_kafka_record_size9_fields,SX_COUNT(sxbx_kafka_record_size9_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_record_size10_fields[] = {
 SX_FIELD("record_size","zigzag32",0,10,SX_SIZE),
};
const sx_layout sxbx_kafka_record_size10 = {UINT32_C(0x60300035),"kafka_record_size10",sxbx_kafka_record_size10_fields,SX_COUNT(sxbx_kafka_record_size10_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_timestamp_delta1_fields[] = {
 SX_FIELD("timestamp_delta","zigzag64",0,1,SX_NONE),
};
const sx_layout sxbx_kafka_timestamp_delta1 = {UINT32_C(0x60300036),"kafka_timestamp_delta1",sxbx_kafka_timestamp_delta1_fields,SX_COUNT(sxbx_kafka_timestamp_delta1_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_timestamp_delta2_fields[] = {
 SX_FIELD("timestamp_delta","zigzag64",0,2,SX_NONE),
};
const sx_layout sxbx_kafka_timestamp_delta2 = {UINT32_C(0x60300037),"kafka_timestamp_delta2",sxbx_kafka_timestamp_delta2_fields,SX_COUNT(sxbx_kafka_timestamp_delta2_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_timestamp_delta3_fields[] = {
 SX_FIELD("timestamp_delta","zigzag64",0,3,SX_NONE),
};
const sx_layout sxbx_kafka_timestamp_delta3 = {UINT32_C(0x60300038),"kafka_timestamp_delta3",sxbx_kafka_timestamp_delta3_fields,SX_COUNT(sxbx_kafka_timestamp_delta3_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_timestamp_delta4_fields[] = {
 SX_FIELD("timestamp_delta","zigzag64",0,4,SX_NONE),
};
const sx_layout sxbx_kafka_timestamp_delta4 = {UINT32_C(0x60300039),"kafka_timestamp_delta4",sxbx_kafka_timestamp_delta4_fields,SX_COUNT(sxbx_kafka_timestamp_delta4_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_timestamp_delta5_fields[] = {
 SX_FIELD("timestamp_delta","zigzag64",0,5,SX_NONE),
};
const sx_layout sxbx_kafka_timestamp_delta5 = {UINT32_C(0x6030003a),"kafka_timestamp_delta5",sxbx_kafka_timestamp_delta5_fields,SX_COUNT(sxbx_kafka_timestamp_delta5_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_timestamp_delta6_fields[] = {
 SX_FIELD("timestamp_delta","zigzag64",0,6,SX_NONE),
};
const sx_layout sxbx_kafka_timestamp_delta6 = {UINT32_C(0x6030003b),"kafka_timestamp_delta6",sxbx_kafka_timestamp_delta6_fields,SX_COUNT(sxbx_kafka_timestamp_delta6_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_timestamp_delta7_fields[] = {
 SX_FIELD("timestamp_delta","zigzag64",0,7,SX_NONE),
};
const sx_layout sxbx_kafka_timestamp_delta7 = {UINT32_C(0x6030003c),"kafka_timestamp_delta7",sxbx_kafka_timestamp_delta7_fields,SX_COUNT(sxbx_kafka_timestamp_delta7_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_timestamp_delta8_fields[] = {
 SX_FIELD("timestamp_delta","zigzag64",0,8,SX_NONE),
};
const sx_layout sxbx_kafka_timestamp_delta8 = {UINT32_C(0x6030003d),"kafka_timestamp_delta8",sxbx_kafka_timestamp_delta8_fields,SX_COUNT(sxbx_kafka_timestamp_delta8_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_timestamp_delta9_fields[] = {
 SX_FIELD("timestamp_delta","zigzag64",0,9,SX_NONE),
};
const sx_layout sxbx_kafka_timestamp_delta9 = {UINT32_C(0x6030003e),"kafka_timestamp_delta9",sxbx_kafka_timestamp_delta9_fields,SX_COUNT(sxbx_kafka_timestamp_delta9_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_timestamp_delta10_fields[] = {
 SX_FIELD("timestamp_delta","zigzag64",0,10,SX_NONE),
};
const sx_layout sxbx_kafka_timestamp_delta10 = {UINT32_C(0x6030003f),"kafka_timestamp_delta10",sxbx_kafka_timestamp_delta10_fields,SX_COUNT(sxbx_kafka_timestamp_delta10_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_offset_delta1_fields[] = {
 SX_FIELD("offset_delta","zigzag32",0,1,SX_NONE),
};
const sx_layout sxbx_kafka_offset_delta1 = {UINT32_C(0x60300040),"kafka_offset_delta1",sxbx_kafka_offset_delta1_fields,SX_COUNT(sxbx_kafka_offset_delta1_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_offset_delta2_fields[] = {
 SX_FIELD("offset_delta","zigzag32",0,2,SX_NONE),
};
const sx_layout sxbx_kafka_offset_delta2 = {UINT32_C(0x60300041),"kafka_offset_delta2",sxbx_kafka_offset_delta2_fields,SX_COUNT(sxbx_kafka_offset_delta2_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_offset_delta3_fields[] = {
 SX_FIELD("offset_delta","zigzag32",0,3,SX_NONE),
};
const sx_layout sxbx_kafka_offset_delta3 = {UINT32_C(0x60300042),"kafka_offset_delta3",sxbx_kafka_offset_delta3_fields,SX_COUNT(sxbx_kafka_offset_delta3_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_offset_delta4_fields[] = {
 SX_FIELD("offset_delta","zigzag32",0,4,SX_NONE),
};
const sx_layout sxbx_kafka_offset_delta4 = {UINT32_C(0x60300043),"kafka_offset_delta4",sxbx_kafka_offset_delta4_fields,SX_COUNT(sxbx_kafka_offset_delta4_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_offset_delta5_fields[] = {
 SX_FIELD("offset_delta","zigzag32",0,5,SX_NONE),
};
const sx_layout sxbx_kafka_offset_delta5 = {UINT32_C(0x60300044),"kafka_offset_delta5",sxbx_kafka_offset_delta5_fields,SX_COUNT(sxbx_kafka_offset_delta5_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_offset_delta6_fields[] = {
 SX_FIELD("offset_delta","zigzag32",0,6,SX_NONE),
};
const sx_layout sxbx_kafka_offset_delta6 = {UINT32_C(0x60300045),"kafka_offset_delta6",sxbx_kafka_offset_delta6_fields,SX_COUNT(sxbx_kafka_offset_delta6_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_offset_delta7_fields[] = {
 SX_FIELD("offset_delta","zigzag32",0,7,SX_NONE),
};
const sx_layout sxbx_kafka_offset_delta7 = {UINT32_C(0x60300046),"kafka_offset_delta7",sxbx_kafka_offset_delta7_fields,SX_COUNT(sxbx_kafka_offset_delta7_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_offset_delta8_fields[] = {
 SX_FIELD("offset_delta","zigzag32",0,8,SX_NONE),
};
const sx_layout sxbx_kafka_offset_delta8 = {UINT32_C(0x60300047),"kafka_offset_delta8",sxbx_kafka_offset_delta8_fields,SX_COUNT(sxbx_kafka_offset_delta8_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_offset_delta9_fields[] = {
 SX_FIELD("offset_delta","zigzag32",0,9,SX_NONE),
};
const sx_layout sxbx_kafka_offset_delta9 = {UINT32_C(0x60300048),"kafka_offset_delta9",sxbx_kafka_offset_delta9_fields,SX_COUNT(sxbx_kafka_offset_delta9_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_offset_delta10_fields[] = {
 SX_FIELD("offset_delta","zigzag32",0,10,SX_NONE),
};
const sx_layout sxbx_kafka_offset_delta10 = {UINT32_C(0x60300049),"kafka_offset_delta10",sxbx_kafka_offset_delta10_fields,SX_COUNT(sxbx_kafka_offset_delta10_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_nullable_size1_fields[] = {
 SX_FIELD("nullable_size","zigzag32",0,1,SX_NONE),
};
const sx_layout sxbx_kafka_nullable_size1 = {UINT32_C(0x6030004a),"kafka_nullable_size1",sxbx_kafka_nullable_size1_fields,SX_COUNT(sxbx_kafka_nullable_size1_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_nullable_size2_fields[] = {
 SX_FIELD("nullable_size","zigzag32",0,2,SX_NONE),
};
const sx_layout sxbx_kafka_nullable_size2 = {UINT32_C(0x6030004b),"kafka_nullable_size2",sxbx_kafka_nullable_size2_fields,SX_COUNT(sxbx_kafka_nullable_size2_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_nullable_size3_fields[] = {
 SX_FIELD("nullable_size","zigzag32",0,3,SX_NONE),
};
const sx_layout sxbx_kafka_nullable_size3 = {UINT32_C(0x6030004c),"kafka_nullable_size3",sxbx_kafka_nullable_size3_fields,SX_COUNT(sxbx_kafka_nullable_size3_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_nullable_size4_fields[] = {
 SX_FIELD("nullable_size","zigzag32",0,4,SX_NONE),
};
const sx_layout sxbx_kafka_nullable_size4 = {UINT32_C(0x6030004d),"kafka_nullable_size4",sxbx_kafka_nullable_size4_fields,SX_COUNT(sxbx_kafka_nullable_size4_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_nullable_size5_fields[] = {
 SX_FIELD("nullable_size","zigzag32",0,5,SX_NONE),
};
const sx_layout sxbx_kafka_nullable_size5 = {UINT32_C(0x6030004e),"kafka_nullable_size5",sxbx_kafka_nullable_size5_fields,SX_COUNT(sxbx_kafka_nullable_size5_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_nullable_size6_fields[] = {
 SX_FIELD("nullable_size","zigzag32",0,6,SX_NONE),
};
const sx_layout sxbx_kafka_nullable_size6 = {UINT32_C(0x6030004f),"kafka_nullable_size6",sxbx_kafka_nullable_size6_fields,SX_COUNT(sxbx_kafka_nullable_size6_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_nullable_size7_fields[] = {
 SX_FIELD("nullable_size","zigzag32",0,7,SX_NONE),
};
const sx_layout sxbx_kafka_nullable_size7 = {UINT32_C(0x60300050),"kafka_nullable_size7",sxbx_kafka_nullable_size7_fields,SX_COUNT(sxbx_kafka_nullable_size7_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_nullable_size8_fields[] = {
 SX_FIELD("nullable_size","zigzag32",0,8,SX_NONE),
};
const sx_layout sxbx_kafka_nullable_size8 = {UINT32_C(0x60300051),"kafka_nullable_size8",sxbx_kafka_nullable_size8_fields,SX_COUNT(sxbx_kafka_nullable_size8_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_nullable_size9_fields[] = {
 SX_FIELD("nullable_size","zigzag32",0,9,SX_NONE),
};
const sx_layout sxbx_kafka_nullable_size9 = {UINT32_C(0x60300052),"kafka_nullable_size9",sxbx_kafka_nullable_size9_fields,SX_COUNT(sxbx_kafka_nullable_size9_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_nullable_size10_fields[] = {
 SX_FIELD("nullable_size","zigzag32",0,10,SX_NONE),
};
const sx_layout sxbx_kafka_nullable_size10 = {UINT32_C(0x60300053),"kafka_nullable_size10",sxbx_kafka_nullable_size10_fields,SX_COUNT(sxbx_kafka_nullable_size10_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_header_count1_fields[] = {
 SX_FIELD("header_count","zigzag32",0,1,SX_COUNT_PROP),
};
const sx_layout sxbx_kafka_header_count1 = {UINT32_C(0x60300054),"kafka_header_count1",sxbx_kafka_header_count1_fields,SX_COUNT(sxbx_kafka_header_count1_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_header_count2_fields[] = {
 SX_FIELD("header_count","zigzag32",0,2,SX_COUNT_PROP),
};
const sx_layout sxbx_kafka_header_count2 = {UINT32_C(0x60300055),"kafka_header_count2",sxbx_kafka_header_count2_fields,SX_COUNT(sxbx_kafka_header_count2_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_header_count3_fields[] = {
 SX_FIELD("header_count","zigzag32",0,3,SX_COUNT_PROP),
};
const sx_layout sxbx_kafka_header_count3 = {UINT32_C(0x60300056),"kafka_header_count3",sxbx_kafka_header_count3_fields,SX_COUNT(sxbx_kafka_header_count3_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_header_count4_fields[] = {
 SX_FIELD("header_count","zigzag32",0,4,SX_COUNT_PROP),
};
const sx_layout sxbx_kafka_header_count4 = {UINT32_C(0x60300057),"kafka_header_count4",sxbx_kafka_header_count4_fields,SX_COUNT(sxbx_kafka_header_count4_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_header_count5_fields[] = {
 SX_FIELD("header_count","zigzag32",0,5,SX_COUNT_PROP),
};
const sx_layout sxbx_kafka_header_count5 = {UINT32_C(0x60300058),"kafka_header_count5",sxbx_kafka_header_count5_fields,SX_COUNT(sxbx_kafka_header_count5_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_header_count6_fields[] = {
 SX_FIELD("header_count","zigzag32",0,6,SX_COUNT_PROP),
};
const sx_layout sxbx_kafka_header_count6 = {UINT32_C(0x60300059),"kafka_header_count6",sxbx_kafka_header_count6_fields,SX_COUNT(sxbx_kafka_header_count6_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_header_count7_fields[] = {
 SX_FIELD("header_count","zigzag32",0,7,SX_COUNT_PROP),
};
const sx_layout sxbx_kafka_header_count7 = {UINT32_C(0x6030005a),"kafka_header_count7",sxbx_kafka_header_count7_fields,SX_COUNT(sxbx_kafka_header_count7_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_header_count8_fields[] = {
 SX_FIELD("header_count","zigzag32",0,8,SX_COUNT_PROP),
};
const sx_layout sxbx_kafka_header_count8 = {UINT32_C(0x6030005b),"kafka_header_count8",sxbx_kafka_header_count8_fields,SX_COUNT(sxbx_kafka_header_count8_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_header_count9_fields[] = {
 SX_FIELD("header_count","zigzag32",0,9,SX_COUNT_PROP),
};
const sx_layout sxbx_kafka_header_count9 = {UINT32_C(0x6030005c),"kafka_header_count9",sxbx_kafka_header_count9_fields,SX_COUNT(sxbx_kafka_header_count9_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_header_count10_fields[] = {
 SX_FIELD("header_count","zigzag32",0,10,SX_COUNT_PROP),
};
const sx_layout sxbx_kafka_header_count10 = {UINT32_C(0x6030005d),"kafka_header_count10",sxbx_kafka_header_count10_fields,SX_COUNT(sxbx_kafka_header_count10_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_header_key_size1_fields[] = {
 SX_FIELD("header_key_size","zigzag32",0,1,SX_SIZE),
};
const sx_layout sxbx_kafka_header_key_size1 = {UINT32_C(0x6030005e),"kafka_header_key_size1",sxbx_kafka_header_key_size1_fields,SX_COUNT(sxbx_kafka_header_key_size1_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_header_key_size2_fields[] = {
 SX_FIELD("header_key_size","zigzag32",0,2,SX_SIZE),
};
const sx_layout sxbx_kafka_header_key_size2 = {UINT32_C(0x6030005f),"kafka_header_key_size2",sxbx_kafka_header_key_size2_fields,SX_COUNT(sxbx_kafka_header_key_size2_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_header_key_size3_fields[] = {
 SX_FIELD("header_key_size","zigzag32",0,3,SX_SIZE),
};
const sx_layout sxbx_kafka_header_key_size3 = {UINT32_C(0x60300060),"kafka_header_key_size3",sxbx_kafka_header_key_size3_fields,SX_COUNT(sxbx_kafka_header_key_size3_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_header_key_size4_fields[] = {
 SX_FIELD("header_key_size","zigzag32",0,4,SX_SIZE),
};
const sx_layout sxbx_kafka_header_key_size4 = {UINT32_C(0x60300061),"kafka_header_key_size4",sxbx_kafka_header_key_size4_fields,SX_COUNT(sxbx_kafka_header_key_size4_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_header_key_size5_fields[] = {
 SX_FIELD("header_key_size","zigzag32",0,5,SX_SIZE),
};
const sx_layout sxbx_kafka_header_key_size5 = {UINT32_C(0x60300062),"kafka_header_key_size5",sxbx_kafka_header_key_size5_fields,SX_COUNT(sxbx_kafka_header_key_size5_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_header_key_size6_fields[] = {
 SX_FIELD("header_key_size","zigzag32",0,6,SX_SIZE),
};
const sx_layout sxbx_kafka_header_key_size6 = {UINT32_C(0x60300063),"kafka_header_key_size6",sxbx_kafka_header_key_size6_fields,SX_COUNT(sxbx_kafka_header_key_size6_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_header_key_size7_fields[] = {
 SX_FIELD("header_key_size","zigzag32",0,7,SX_SIZE),
};
const sx_layout sxbx_kafka_header_key_size7 = {UINT32_C(0x60300064),"kafka_header_key_size7",sxbx_kafka_header_key_size7_fields,SX_COUNT(sxbx_kafka_header_key_size7_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_header_key_size8_fields[] = {
 SX_FIELD("header_key_size","zigzag32",0,8,SX_SIZE),
};
const sx_layout sxbx_kafka_header_key_size8 = {UINT32_C(0x60300065),"kafka_header_key_size8",sxbx_kafka_header_key_size8_fields,SX_COUNT(sxbx_kafka_header_key_size8_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_header_key_size9_fields[] = {
 SX_FIELD("header_key_size","zigzag32",0,9,SX_SIZE),
};
const sx_layout sxbx_kafka_header_key_size9 = {UINT32_C(0x60300066),"kafka_header_key_size9",sxbx_kafka_header_key_size9_fields,SX_COUNT(sxbx_kafka_header_key_size9_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_header_key_size10_fields[] = {
 SX_FIELD("header_key_size","zigzag32",0,10,SX_SIZE),
};
const sx_layout sxbx_kafka_header_key_size10 = {UINT32_C(0x60300067),"kafka_header_key_size10",sxbx_kafka_header_key_size10_fields,SX_COUNT(sxbx_kafka_header_key_size10_fields),SX_LE};
#define SXBX_LIMIT 20000U
static const sx_layout *const sxbx_kafka_record_size[] = {&sxbx_kafka_record_size1,&sxbx_kafka_record_size2,&sxbx_kafka_record_size3,&sxbx_kafka_record_size4,&sxbx_kafka_record_size5,&sxbx_kafka_record_size6,&sxbx_kafka_record_size7,&sxbx_kafka_record_size8,&sxbx_kafka_record_size9,&sxbx_kafka_record_size10};
static const sx_layout *const sxbx_kafka_timestamp_delta[] = {&sxbx_kafka_timestamp_delta1,&sxbx_kafka_timestamp_delta2,&sxbx_kafka_timestamp_delta3,&sxbx_kafka_timestamp_delta4,&sxbx_kafka_timestamp_delta5,&sxbx_kafka_timestamp_delta6,&sxbx_kafka_timestamp_delta7,&sxbx_kafka_timestamp_delta8,&sxbx_kafka_timestamp_delta9,&sxbx_kafka_timestamp_delta10};
static const sx_layout *const sxbx_kafka_offset_delta[] = {&sxbx_kafka_offset_delta1,&sxbx_kafka_offset_delta2,&sxbx_kafka_offset_delta3,&sxbx_kafka_offset_delta4,&sxbx_kafka_offset_delta5,&sxbx_kafka_offset_delta6,&sxbx_kafka_offset_delta7,&sxbx_kafka_offset_delta8,&sxbx_kafka_offset_delta9,&sxbx_kafka_offset_delta10};
static const sx_layout *const sxbx_kafka_nullable_size[] = {&sxbx_kafka_nullable_size1,&sxbx_kafka_nullable_size2,&sxbx_kafka_nullable_size3,&sxbx_kafka_nullable_size4,&sxbx_kafka_nullable_size5,&sxbx_kafka_nullable_size6,&sxbx_kafka_nullable_size7,&sxbx_kafka_nullable_size8,&sxbx_kafka_nullable_size9,&sxbx_kafka_nullable_size10};
static const sx_layout *const sxbx_kafka_header_count[] = {&sxbx_kafka_header_count1,&sxbx_kafka_header_count2,&sxbx_kafka_header_count3,&sxbx_kafka_header_count4,&sxbx_kafka_header_count5,&sxbx_kafka_header_count6,&sxbx_kafka_header_count7,&sxbx_kafka_header_count8,&sxbx_kafka_header_count9,&sxbx_kafka_header_count10};
static const sx_layout *const sxbx_kafka_header_key_size[] = {&sxbx_kafka_header_key_size1,&sxbx_kafka_header_key_size2,&sxbx_kafka_header_key_size3,&sxbx_kafka_header_key_size4,&sxbx_kafka_header_key_size5,&sxbx_kafka_header_key_size6,&sxbx_kafka_header_key_size7,&sxbx_kafka_header_key_size8,&sxbx_kafka_header_key_size9,&sxbx_kafka_header_key_size10};
static bool sxbx_zig(sx_context*c,uint64_t*p,uint64_t end,const sx_layout *const*ls,int64_t*out){uint64_t u=0,start=*p;for(unsigned i=0;i<10;i++){uint64_t v;if(*p>=end||!sxbx_word(c,(*p)++,1,false,&v)||(i==9&&(v&254)))return false;u|=(v&127)<<(i*7);if(!(v&128)){*out=(int64_t)(u>>1)^-(int64_t)(u&1);return sxbx_add(c,ls[i],start);}}return false;}
static bool sxbx_kafka_blob(sx_context*c,uint64_t*p,uint64_t end,bool key){int64_t z;if(!sxbx_zig(c,p,end,key?sxbx_kafka_header_key_size:sxbx_kafka_nullable_size,&z)||z<(key?0:-1)||z>INT32_MAX)return false;if(z<0)return true;if((uint64_t)z>end-*p)return false;*p+=(uint64_t)z;return true;}
static bool sxbx_kafka(sx_context*c){uint64_t p=0;uint8_t b[61];for(unsigned batch=0;batch<SXBX_LIMIT&&c->count<SXBX_LIMIT;batch++){if(!sxbx_read(c,p,b,61)||b[16]!=2)break;int64_t length=(int32_t)sxbx32(b+8,true),count=(int32_t)sxbx32(b+57,true);if(length<49||count<0||count>2048||!sxbx_span(c,p,(uint64_t)length+12))break;if(!sxbx_add(c,&sxbx_kafka_batch,p))return false;uint64_t q=p+61,end=p+12+(uint64_t)length;for(int64_t i=0;i<count&&q<end&&c->count<SXBX_LIMIT;i++){size_t old=c->count;int64_t z,delta,headers;uint64_t rec=q;if(!sxbx_zig(c,&q,end,sxbx_kafka_record_size,&z)||z<6||z>INT32_MAX||(uint64_t)z>end-q){c->count=old;break;}uint64_t stop=q+(uint64_t)z;if(!sxbx_add(c,&sxbx_kafka_attributes,q++ )||!sxbx_zig(c,&q,stop,sxbx_kafka_timestamp_delta,&delta)||!sxbx_zig(c,&q,stop,sxbx_kafka_offset_delta,&delta)||delta<0||delta>INT32_MAX||!sxbx_kafka_blob(c,&q,stop,false)||!sxbx_kafka_blob(c,&q,stop,false)||!sxbx_zig(c,&q,stop,sxbx_kafka_header_count,&headers)||headers<0||headers>256){c->count=old;break;}bool ok=true;for(int64_t j=0;j<headers;j++)if(!sxbx_kafka_blob(c,&q,stop,true)||!sxbx_kafka_blob(c,&q,stop,false)){ok=false;break;}if(!ok||q!=stop||q<=rec){c->count=old;break;}}p=end;}return c->count>0;}
bool sx_kafka_record_batch_build(sx_context*c)
{
 return sxbx_kafka(c);
}
