/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * apache_orc data structures, moved out of the databases schema family. */
#include "../../xx_format_schema_databases.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxd_orc_header_fields[] = {
    SX_FIELD("magic", "char[3]", 0, 3, SX_SIGNATURE),
};
const sx_layout sxd_orc_header = {UINT32_C(0x601A003D),"orc_header",sxd_orc_header_fields,SX_COUNT(sxd_orc_header_fields),SX_LE};
static const xx_data_struct_field_desc sxd_orc_postscript_length_fields[] = {
    SX_FIELD("postscript_length", "uint8", 0, 1, SX_SIZE),
};
const sx_layout sxd_orc_postscript_length = {UINT32_C(0x601A003E),"orc_postscript_length",sxd_orc_postscript_length_fields,SX_COUNT(sxd_orc_postscript_length_fields),SX_LE};
static const xx_data_struct_field_desc sxd_orc_fixed32_fields[] = {
    SX_FIELD("value", "uint32", 0, 4, SX_NONE),
};
const sx_layout sxd_orc_fixed32 = {UINT32_C(0x601A003F),"orc_fixed32",sxd_orc_fixed32_fields,SX_COUNT(sxd_orc_fixed32_fields),SX_LE};
static const xx_data_struct_field_desc sxd_orc_fixed64_fields[] = {
    SX_FIELD("value", "uint64", 0, 8, SX_NONE),
};
const sx_layout sxd_orc_fixed64 = {UINT32_C(0x601A0040),"orc_fixed64",sxd_orc_fixed64_fields,SX_COUNT(sxd_orc_fixed64_fields),SX_LE};
static const xx_data_struct_field_desc sxd_database_varuint_1_fields[] = {
    SX_FIELD("value", "uleb128_64", 0, 1, SX_NONE),
};
const sx_layout sxd_database_varuint_1 = {UINT32_C(0x601A0041),"database_varuint_1",sxd_database_varuint_1_fields,SX_COUNT(sxd_database_varuint_1_fields),SX_LE};
static const xx_data_struct_field_desc sxd_database_varuint_2_fields[] = {
    SX_FIELD("value", "uleb128_64", 0, 2, SX_NONE),
};
const sx_layout sxd_database_varuint_2 = {UINT32_C(0x601A0042),"database_varuint_2",sxd_database_varuint_2_fields,SX_COUNT(sxd_database_varuint_2_fields),SX_LE};
static const xx_data_struct_field_desc sxd_database_varuint_3_fields[] = {
    SX_FIELD("value", "uleb128_64", 0, 3, SX_NONE),
};
const sx_layout sxd_database_varuint_3 = {UINT32_C(0x601A0043),"database_varuint_3",sxd_database_varuint_3_fields,SX_COUNT(sxd_database_varuint_3_fields),SX_LE};
static const xx_data_struct_field_desc sxd_database_varuint_4_fields[] = {
    SX_FIELD("value", "uleb128_64", 0, 4, SX_NONE),
};
const sx_layout sxd_database_varuint_4 = {UINT32_C(0x601A0044),"database_varuint_4",sxd_database_varuint_4_fields,SX_COUNT(sxd_database_varuint_4_fields),SX_LE};
static const xx_data_struct_field_desc sxd_database_varuint_5_fields[] = {
    SX_FIELD("value", "uleb128_64", 0, 5, SX_NONE),
};
const sx_layout sxd_database_varuint_5 = {UINT32_C(0x601A0045),"database_varuint_5",sxd_database_varuint_5_fields,SX_COUNT(sxd_database_varuint_5_fields),SX_LE};
static const xx_data_struct_field_desc sxd_database_varuint_6_fields[] = {
    SX_FIELD("value", "uleb128_64", 0, 6, SX_NONE),
};
const sx_layout sxd_database_varuint_6 = {UINT32_C(0x601A0046),"database_varuint_6",sxd_database_varuint_6_fields,SX_COUNT(sxd_database_varuint_6_fields),SX_LE};
static const xx_data_struct_field_desc sxd_database_varuint_7_fields[] = {
    SX_FIELD("value", "uleb128_64", 0, 7, SX_NONE),
};
const sx_layout sxd_database_varuint_7 = {UINT32_C(0x601A0047),"database_varuint_7",sxd_database_varuint_7_fields,SX_COUNT(sxd_database_varuint_7_fields),SX_LE};
static const xx_data_struct_field_desc sxd_database_varuint_8_fields[] = {
    SX_FIELD("value", "uleb128_64", 0, 8, SX_NONE),
};
const sx_layout sxd_database_varuint_8 = {UINT32_C(0x601A0048),"database_varuint_8",sxd_database_varuint_8_fields,SX_COUNT(sxd_database_varuint_8_fields),SX_LE};
static const xx_data_struct_field_desc sxd_database_varuint_9_fields[] = {
    SX_FIELD("value", "uleb128_64", 0, 9, SX_NONE),
};
const sx_layout sxd_database_varuint_9 = {UINT32_C(0x601A0049),"database_varuint_9",sxd_database_varuint_9_fields,SX_COUNT(sxd_database_varuint_9_fields),SX_LE};
static const xx_data_struct_field_desc sxd_database_varuint_10_fields[] = {
    SX_FIELD("value", "uleb128_64", 0, 10, SX_NONE),
};
const sx_layout sxd_database_varuint_10 = {UINT32_C(0x601A004A),"database_varuint_10",sxd_database_varuint_10_fields,SX_COUNT(sxd_database_varuint_10_fields),SX_LE};
static const xx_data_struct_field_desc sxd_database_varuint_count_1_fields[] = {
    SX_FIELD("item_count", "uleb128_64", 0, 1, SX_COUNT_PROP),
};
const sx_layout sxd_database_varuint_count_1 = {UINT32_C(0x601A005F),"database_varuint_count_1",sxd_database_varuint_count_1_fields,SX_COUNT(sxd_database_varuint_count_1_fields),SX_LE};
static const xx_data_struct_field_desc sxd_database_varuint_count_2_fields[] = {
    SX_FIELD("item_count", "uleb128_64", 0, 2, SX_COUNT_PROP),
};
const sx_layout sxd_database_varuint_count_2 = {UINT32_C(0x601A0060),"database_varuint_count_2",sxd_database_varuint_count_2_fields,SX_COUNT(sxd_database_varuint_count_2_fields),SX_LE};
static const xx_data_struct_field_desc sxd_database_varuint_count_3_fields[] = {
    SX_FIELD("item_count", "uleb128_64", 0, 3, SX_COUNT_PROP),
};
const sx_layout sxd_database_varuint_count_3 = {UINT32_C(0x601A0061),"database_varuint_count_3",sxd_database_varuint_count_3_fields,SX_COUNT(sxd_database_varuint_count_3_fields),SX_LE};
static const xx_data_struct_field_desc sxd_database_varuint_count_4_fields[] = {
    SX_FIELD("item_count", "uleb128_64", 0, 4, SX_COUNT_PROP),
};
const sx_layout sxd_database_varuint_count_4 = {UINT32_C(0x601A0062),"database_varuint_count_4",sxd_database_varuint_count_4_fields,SX_COUNT(sxd_database_varuint_count_4_fields),SX_LE};
static const xx_data_struct_field_desc sxd_database_varuint_count_5_fields[] = {
    SX_FIELD("item_count", "uleb128_64", 0, 5, SX_COUNT_PROP),
};
const sx_layout sxd_database_varuint_count_5 = {UINT32_C(0x601A0063),"database_varuint_count_5",sxd_database_varuint_count_5_fields,SX_COUNT(sxd_database_varuint_count_5_fields),SX_LE};
static const xx_data_struct_field_desc sxd_database_varuint_count_6_fields[] = {
    SX_FIELD("item_count", "uleb128_64", 0, 6, SX_COUNT_PROP),
};
const sx_layout sxd_database_varuint_count_6 = {UINT32_C(0x601A0064),"database_varuint_count_6",sxd_database_varuint_count_6_fields,SX_COUNT(sxd_database_varuint_count_6_fields),SX_LE};
static const xx_data_struct_field_desc sxd_database_varuint_count_7_fields[] = {
    SX_FIELD("item_count", "uleb128_64", 0, 7, SX_COUNT_PROP),
};
const sx_layout sxd_database_varuint_count_7 = {UINT32_C(0x601A0065),"database_varuint_count_7",sxd_database_varuint_count_7_fields,SX_COUNT(sxd_database_varuint_count_7_fields),SX_LE};
static const xx_data_struct_field_desc sxd_database_varuint_count_8_fields[] = {
    SX_FIELD("item_count", "uleb128_64", 0, 8, SX_COUNT_PROP),
};
const sx_layout sxd_database_varuint_count_8 = {UINT32_C(0x601A0066),"database_varuint_count_8",sxd_database_varuint_count_8_fields,SX_COUNT(sxd_database_varuint_count_8_fields),SX_LE};
static const xx_data_struct_field_desc sxd_database_varuint_count_9_fields[] = {
    SX_FIELD("item_count", "uleb128_64", 0, 9, SX_COUNT_PROP),
};
const sx_layout sxd_database_varuint_count_9 = {UINT32_C(0x601A0067),"database_varuint_count_9",sxd_database_varuint_count_9_fields,SX_COUNT(sxd_database_varuint_count_9_fields),SX_LE};
static const xx_data_struct_field_desc sxd_database_varuint_count_10_fields[] = {
    SX_FIELD("item_count", "uleb128_64", 0, 10, SX_COUNT_PROP),
};
const sx_layout sxd_database_varuint_count_10 = {UINT32_C(0x601A0068),"database_varuint_count_10",sxd_database_varuint_count_10_fields,SX_COUNT(sxd_database_varuint_count_10_fields),SX_LE};
static const xx_data_struct_field_desc sxd_database_varuint_id_1_fields[] = {
    SX_FIELD("identifier", "uleb128_64", 0, 1, SX_ID),
};
const sx_layout sxd_database_varuint_id_1 = {UINT32_C(0x601A0069),"database_varuint_id_1",sxd_database_varuint_id_1_fields,SX_COUNT(sxd_database_varuint_id_1_fields),SX_LE};
static const xx_data_struct_field_desc sxd_database_varuint_id_2_fields[] = {
    SX_FIELD("identifier", "uleb128_64", 0, 2, SX_ID),
};
const sx_layout sxd_database_varuint_id_2 = {UINT32_C(0x601A006A),"database_varuint_id_2",sxd_database_varuint_id_2_fields,SX_COUNT(sxd_database_varuint_id_2_fields),SX_LE};
static const xx_data_struct_field_desc sxd_database_varuint_id_3_fields[] = {
    SX_FIELD("identifier", "uleb128_64", 0, 3, SX_ID),
};
const sx_layout sxd_database_varuint_id_3 = {UINT32_C(0x601A006B),"database_varuint_id_3",sxd_database_varuint_id_3_fields,SX_COUNT(sxd_database_varuint_id_3_fields),SX_LE};
static const xx_data_struct_field_desc sxd_database_varuint_id_4_fields[] = {
    SX_FIELD("identifier", "uleb128_64", 0, 4, SX_ID),
};
const sx_layout sxd_database_varuint_id_4 = {UINT32_C(0x601A006C),"database_varuint_id_4",sxd_database_varuint_id_4_fields,SX_COUNT(sxd_database_varuint_id_4_fields),SX_LE};
static const xx_data_struct_field_desc sxd_database_varuint_id_5_fields[] = {
    SX_FIELD("identifier", "uleb128_64", 0, 5, SX_ID),
};
const sx_layout sxd_database_varuint_id_5 = {UINT32_C(0x601A006D),"database_varuint_id_5",sxd_database_varuint_id_5_fields,SX_COUNT(sxd_database_varuint_id_5_fields),SX_LE};
static const xx_data_struct_field_desc sxd_database_varuint_id_6_fields[] = {
    SX_FIELD("identifier", "uleb128_64", 0, 6, SX_ID),
};
const sx_layout sxd_database_varuint_id_6 = {UINT32_C(0x601A006E),"database_varuint_id_6",sxd_database_varuint_id_6_fields,SX_COUNT(sxd_database_varuint_id_6_fields),SX_LE};
static const xx_data_struct_field_desc sxd_database_varuint_id_7_fields[] = {
    SX_FIELD("identifier", "uleb128_64", 0, 7, SX_ID),
};
const sx_layout sxd_database_varuint_id_7 = {UINT32_C(0x601A006F),"database_varuint_id_7",sxd_database_varuint_id_7_fields,SX_COUNT(sxd_database_varuint_id_7_fields),SX_LE};
static const xx_data_struct_field_desc sxd_database_varuint_id_8_fields[] = {
    SX_FIELD("identifier", "uleb128_64", 0, 8, SX_ID),
};
const sx_layout sxd_database_varuint_id_8 = {UINT32_C(0x601A0070),"database_varuint_id_8",sxd_database_varuint_id_8_fields,SX_COUNT(sxd_database_varuint_id_8_fields),SX_LE};
static const xx_data_struct_field_desc sxd_database_varuint_id_9_fields[] = {
    SX_FIELD("identifier", "uleb128_64", 0, 9, SX_ID),
};
const sx_layout sxd_database_varuint_id_9 = {UINT32_C(0x601A0071),"database_varuint_id_9",sxd_database_varuint_id_9_fields,SX_COUNT(sxd_database_varuint_id_9_fields),SX_LE};
static const xx_data_struct_field_desc sxd_database_varuint_id_10_fields[] = {
    SX_FIELD("identifier", "uleb128_64", 0, 10, SX_ID),
};
const sx_layout sxd_database_varuint_id_10 = {UINT32_C(0x601A0072),"database_varuint_id_10",sxd_database_varuint_id_10_fields,SX_COUNT(sxd_database_varuint_id_10_fields),SX_LE};
static const xx_data_struct_field_desc sxd_orc_protobuf_key_1_fields[] = {
    SX_FIELD("field_number_and_wire_type", "uleb128_64", 0, 1, SX_ID),
};
const sx_layout sxd_orc_protobuf_key_1 = {UINT32_C(0x601A0073),"orc_protobuf_key_1",sxd_orc_protobuf_key_1_fields,SX_COUNT(sxd_orc_protobuf_key_1_fields),SX_LE};
static const xx_data_struct_field_desc sxd_orc_protobuf_key_2_fields[] = {
    SX_FIELD("field_number_and_wire_type", "uleb128_64", 0, 2, SX_ID),
};
const sx_layout sxd_orc_protobuf_key_2 = {UINT32_C(0x601A0074),"orc_protobuf_key_2",sxd_orc_protobuf_key_2_fields,SX_COUNT(sxd_orc_protobuf_key_2_fields),SX_LE};
static const xx_data_struct_field_desc sxd_orc_protobuf_key_3_fields[] = {
    SX_FIELD("field_number_and_wire_type", "uleb128_64", 0, 3, SX_ID),
};
const sx_layout sxd_orc_protobuf_key_3 = {UINT32_C(0x601A0075),"orc_protobuf_key_3",sxd_orc_protobuf_key_3_fields,SX_COUNT(sxd_orc_protobuf_key_3_fields),SX_LE};
static const xx_data_struct_field_desc sxd_orc_protobuf_key_4_fields[] = {
    SX_FIELD("field_number_and_wire_type", "uleb128_64", 0, 4, SX_ID),
};
const sx_layout sxd_orc_protobuf_key_4 = {UINT32_C(0x601A0076),"orc_protobuf_key_4",sxd_orc_protobuf_key_4_fields,SX_COUNT(sxd_orc_protobuf_key_4_fields),SX_LE};
static const xx_data_struct_field_desc sxd_orc_protobuf_key_5_fields[] = {
    SX_FIELD("field_number_and_wire_type", "uleb128_64", 0, 5, SX_ID),
};
const sx_layout sxd_orc_protobuf_key_5 = {UINT32_C(0x601A0077),"orc_protobuf_key_5",sxd_orc_protobuf_key_5_fields,SX_COUNT(sxd_orc_protobuf_key_5_fields),SX_LE};
static const xx_data_struct_field_desc sxd_orc_protobuf_key_6_fields[] = {
    SX_FIELD("field_number_and_wire_type", "uleb128_64", 0, 6, SX_ID),
};
const sx_layout sxd_orc_protobuf_key_6 = {UINT32_C(0x601A0078),"orc_protobuf_key_6",sxd_orc_protobuf_key_6_fields,SX_COUNT(sxd_orc_protobuf_key_6_fields),SX_LE};
static const xx_data_struct_field_desc sxd_orc_protobuf_key_7_fields[] = {
    SX_FIELD("field_number_and_wire_type", "uleb128_64", 0, 7, SX_ID),
};
const sx_layout sxd_orc_protobuf_key_7 = {UINT32_C(0x601A0079),"orc_protobuf_key_7",sxd_orc_protobuf_key_7_fields,SX_COUNT(sxd_orc_protobuf_key_7_fields),SX_LE};
static const xx_data_struct_field_desc sxd_orc_protobuf_key_8_fields[] = {
    SX_FIELD("field_number_and_wire_type", "uleb128_64", 0, 8, SX_ID),
};
const sx_layout sxd_orc_protobuf_key_8 = {UINT32_C(0x601A007A),"orc_protobuf_key_8",sxd_orc_protobuf_key_8_fields,SX_COUNT(sxd_orc_protobuf_key_8_fields),SX_LE};
static const xx_data_struct_field_desc sxd_orc_protobuf_key_9_fields[] = {
    SX_FIELD("field_number_and_wire_type", "uleb128_64", 0, 9, SX_ID),
};
const sx_layout sxd_orc_protobuf_key_9 = {UINT32_C(0x601A007B),"orc_protobuf_key_9",sxd_orc_protobuf_key_9_fields,SX_COUNT(sxd_orc_protobuf_key_9_fields),SX_LE};
static const xx_data_struct_field_desc sxd_orc_protobuf_key_10_fields[] = {
    SX_FIELD("field_number_and_wire_type", "uleb128_64", 0, 10, SX_ID),
};
const sx_layout sxd_orc_protobuf_key_10 = {UINT32_C(0x601A007C),"orc_protobuf_key_10",sxd_orc_protobuf_key_10_fields,SX_COUNT(sxd_orc_protobuf_key_10_fields),SX_LE};
static const sx_layout *const sxd_database_varuint_rows[] = {&sxd_database_varuint_1,&sxd_database_varuint_2,&sxd_database_varuint_3,&sxd_database_varuint_4,&sxd_database_varuint_5,&sxd_database_varuint_6,&sxd_database_varuint_7,&sxd_database_varuint_8,&sxd_database_varuint_9,&sxd_database_varuint_10};
static const sx_layout *const sxd_database_varuint_count_rows[] = {&sxd_database_varuint_count_1,&sxd_database_varuint_count_2,&sxd_database_varuint_count_3,&sxd_database_varuint_count_4,&sxd_database_varuint_count_5,&sxd_database_varuint_count_6,&sxd_database_varuint_count_7,&sxd_database_varuint_count_8,&sxd_database_varuint_count_9,&sxd_database_varuint_count_10};
static const sx_layout *const sxd_database_varuint_id_rows[] = {&sxd_database_varuint_id_1,&sxd_database_varuint_id_2,&sxd_database_varuint_id_3,&sxd_database_varuint_id_4,&sxd_database_varuint_id_5,&sxd_database_varuint_id_6,&sxd_database_varuint_id_7,&sxd_database_varuint_id_8,&sxd_database_varuint_id_9,&sxd_database_varuint_id_10};
static const sx_layout *const sxd_orc_protobuf_key_rows[] = {&sxd_orc_protobuf_key_1,&sxd_orc_protobuf_key_2,&sxd_orc_protobuf_key_3,&sxd_orc_protobuf_key_4,&sxd_orc_protobuf_key_5,&sxd_orc_protobuf_key_6,&sxd_orc_protobuf_key_7,&sxd_orc_protobuf_key_8,&sxd_orc_protobuf_key_9,&sxd_orc_protobuf_key_10};
typedef struct sxd_proto {uint64_t tag,wire,value,at,size;}sxd_proto;
static bool sxd_proto_next(sx_context *c,const uint8_t *b,uint64_t *at,uint64_t end,sxd_proto *f,bool emit,unsigned kind)
{
    uint64_t key;if(!sxd_var(c,b,at,end,&key,emit?sxd_orc_protobuf_key_rows:NULL)||!(key>>3)||(key>>3)>0x1fffffff)return false;
    f->tag=key>>3;f->wire=key&7;f->at=*at;f->size=0;f->value=0;
    if(!f->wire){
        const sx_layout *const *rows=sxd_database_varuint_rows;
        if((kind==1&&(f->tag==1||f->tag==3||f->tag==5||f->tag==7))||(kind==2&&(f->tag==1||f->tag==2))||(kind==3&&f->tag>=2&&f->tag<=4)||(kind==6&&f->tag==3)||(kind==9&&f->tag==11))rows=sxd_database_varuint_size_rows;
        if((kind==2&&(f->tag==6||f->tag==8))||(kind==3&&f->tag==5)||(kind==4&&f->tag==4)||(kind==7&&f->tag==2)||(kind==9&&f->tag==1))rows=sxd_database_varuint_count_rows;
        if(kind==3&&f->tag==1)rows=sxd_database_varuint_offset_rows;
        if((kind==1&&(f->tag==2||f->tag==6))||(kind==2&&(f->tag==9||f->tag==11))||(kind==4&&f->tag==1)||(kind==6&&(f->tag==1||f->tag==2))||(kind==7&&(f->tag==1||f->tag==3)))rows=sxd_database_varuint_id_rows;
        return sxd_var(c,b,at,end,&f->value,emit?rows:NULL);
    }
    if(f->wire==2){if(!sxd_var(c,b,at,end,&f->size,emit?sxd_database_varuint_size_rows:NULL))return false;f->at=*at;}
    else if(f->wire==1)f->size=8;else if(f->wire==5)f->size=4;else return false;
    if(*at>end||f->size>end-*at||!sxd_can(c,*at,f->size))return false;
    if(emit&&(f->wire==1||f->wire==5)&&!sxd_add(c,f->wire==1?&sxd_orc_fixed64:&sxd_orc_fixed32,*at,f->size))return false;*at+=f->size;return true;
}
/* Interpret only the protocol-message relationships defined by ORC. String,
 * packed numeric and column-data bytes are never guessed to be submessages. */
static bool sxd_orc_proto(sx_context *c,const uint8_t *b,uint64_t at,uint64_t end,unsigned kind,unsigned depth)
{
    if(depth>16||end>(uint64_t)c->size||at>end)return false;unsigned work=0;
    while(at<end){sxd_proto f;if(++work>100000||!sxd_proto_next(c,b,&at,end,&f,true,kind))return false;if(f.wire!=2)continue;
        unsigned child=0;bool packed=false;
        if(kind==1&&f.tag==4)packed=true;
        if(kind==2){if(f.tag==3)child=3;else if(f.tag==4)child=4;else if(f.tag==5)child=8;else if(f.tag==7)child=9;}
        if(kind==4){if(f.tag==2)packed=true;else if(f.tag==7)child=8;}
        if(kind==5){if(f.tag==1)child=6;else if(f.tag==2)child=7;}
        if(kind==10&&f.tag==1)child=11;
        if(kind==11&&f.tag==1)child=9;
        if(child&&!sxd_orc_proto(c,b,f.at,f.at+f.size,child,depth+1))return false;
        if(packed){uint64_t p=f.at,v;while(p<f.at+f.size)if(!sxd_var(c,b,&p,f.at+f.size,&v,sxd_database_varuint_rows))return false;}
    }return at==end;
}
static bool sxd_orc(sx_context *c,const uint8_t *b)
{
    if(c->size<4)return false;uint64_t n=(uint64_t)c->size,ps=b[n-1];if(!ps||ps>n-4)return false;uint64_t p=n-1-ps,end=n-1,fl=0,ml=0;
    while(p<end){sxd_proto f;if(!sxd_proto_next(c,b,&p,end,&f,false,0))return false;if(f.tag==1)fl=f.value;else if(f.tag==5)ml=f.value;}
    if(fl>n-ps-4||ml>n-ps-4-fl)return false;uint64_t footer=n-1-ps-fl,meta=footer-ml;
    if(!sxd_add(c,&sxd_orc_header,0,3)||!sxd_add(c,&sxd_orc_postscript_length,n-1,1)||!sxd_orc_proto(c,b,n-1-ps,n-1,1,0)||!sxd_orc_proto(c,b,footer,footer+fl,2,0)||!sxd_orc_proto(c,b,meta,footer,10,0))return false;
    p=footer;while(p<footer+fl){sxd_proto f;if(!sxd_proto_next(c,b,&p,footer+fl,&f,false,0))return false;if(f.tag==3&&f.wire==2){uint64_t q=f.at,v[5]={0,0,0,0,0};while(q<f.at+f.size){sxd_proto x;if(!sxd_proto_next(c,b,&q,f.at+f.size,&x,false,0)||x.wire||x.tag<1||x.tag>5)return false;v[x.tag-1]=x.value;}
        if(v[0]>meta||v[1]>meta-v[0]||v[2]>meta-v[0]-v[1]||v[3]>meta-v[0]-v[1]-v[2])return false;uint64_t sf=v[0]+v[1]+v[2];if(!sxd_orc_proto(c,b,sf,sf+v[3],5,0))return false;
    }}return true;
}
bool sx_apache_orc_build(sx_context *c,uint8_t *b)
{
 return sxd_orc(c,b);
}
