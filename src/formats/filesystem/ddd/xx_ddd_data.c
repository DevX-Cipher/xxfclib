/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ddd data structures, moved out of the diskremaining schema family. */
#include "../../xx_format_schema_diskremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdr_ddd_initial_dictionary_fields[] = {
    SX_FIELD("dos_lead","byte[4]",0,4,SX_NONE),
    SX_FIELD("reserved_prefix","msb_bits[0,3]",4,1,SX_RESERVED),
    SX_FIELD("volume_reversed_bits","msb_bits[3,8]",4,2,SX_NONE),
    SX_FIELD("favorite_0_reversed_bits","msb_bits[3,8]",5,2,SX_NONE),
    SX_FIELD("favorite_1_reversed_bits","msb_bits[3,8]",6,2,SX_NONE),
    SX_FIELD("favorite_2_reversed_bits","msb_bits[3,8]",7,2,SX_NONE),
    SX_FIELD("favorite_3_reversed_bits","msb_bits[3,8]",8,2,SX_NONE),
    SX_FIELD("favorite_4_reversed_bits","msb_bits[3,8]",9,2,SX_NONE),
    SX_FIELD("favorite_5_reversed_bits","msb_bits[3,8]",10,2,SX_NONE),
    SX_FIELD("favorite_6_reversed_bits","msb_bits[3,8]",11,2,SX_NONE),
    SX_FIELD("favorite_7_reversed_bits","msb_bits[3,8]",12,2,SX_NONE),
    SX_FIELD("favorite_8_reversed_bits","msb_bits[3,8]",13,2,SX_NONE),
    SX_FIELD("favorite_9_reversed_bits","msb_bits[3,8]",14,2,SX_NONE),
    SX_FIELD("favorite_10_reversed_bits","msb_bits[3,8]",15,2,SX_NONE),
    SX_FIELD("favorite_11_reversed_bits","msb_bits[3,8]",16,2,SX_NONE),
    SX_FIELD("favorite_12_reversed_bits","msb_bits[3,8]",17,2,SX_NONE),
    SX_FIELD("favorite_13_reversed_bits","msb_bits[3,8]",18,2,SX_NONE),
    SX_FIELD("favorite_14_reversed_bits","msb_bits[3,8]",19,2,SX_NONE),
    SX_FIELD("favorite_15_reversed_bits","msb_bits[3,8]",20,2,SX_NONE),
    SX_FIELD("favorite_16_reversed_bits","msb_bits[3,8]",21,2,SX_NONE),
    SX_FIELD("favorite_17_reversed_bits","msb_bits[3,8]",22,2,SX_NONE),
    SX_FIELD("favorite_18_reversed_bits","msb_bits[3,8]",23,2,SX_NONE),
    SX_FIELD("favorite_19_reversed_bits","msb_bits[3,8]",24,2,SX_NONE),
};
const sx_layout sxdr_ddd_initial_dictionary = {0x607f0031U,"ddd_initial_dictionary",sxdr_ddd_initial_dictionary_fields,SX_COUNT(sxdr_ddd_initial_dictionary_fields),SX_LE};
#define SXDR_ADD(c,n,p) sxdr_put(c,&sxdr_##n,p,1)
static bool sxdr_ddd(sx_context*c){uint8_t h[26];return sxdr_read(c,0,h,sizeof(h))&&!(h[4]&0xe0)&&SXDR_ADD(c,ddd_initial_dictionary,0);}
#undef SXDR_ADD
bool sx_ddd_build(sx_context*c)
{
 return sxdr_ddd(c);
}
