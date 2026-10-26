/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * tex dvi data structures, moved out of the package schema family. */
#include "../../xx_format_schema_package.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_p_dvi_preamble_fields[] = {
    SX_FIELD("opcode", "uint8", 0, 1, SX_ID),
    SX_FIELD("version", "uint8", 1, 1, SX_ID),
    SX_FIELD("numerator", "uint32", 2, 4, SX_NONE),
    SX_FIELD("denominator", "uint32", 6, 4, SX_NONE),
    SX_FIELD("magnification", "uint32", 10, 4, SX_NONE),
    SX_FIELD("comment_size", "uint8", 14, 1, SX_SIZE),
};
const sx_layout sx_p_dvi_preamble = { UINT32_C(0x6007004C), "dvi_preamble", sx_p_dvi_preamble_fields, SX_COUNT(sx_p_dvi_preamble_fields), SX_BE };
static const xx_data_struct_field_desc sx_p_dvi_postamble_fields[] = {
    SX_FIELD("opcode", "uint8", 0, 1, SX_ID),
    SX_FIELD("last_page", "int32", 1, 4, SX_OFFSET),
    SX_FIELD("numerator", "uint32", 5, 4, SX_NONE),
    SX_FIELD("denominator", "uint32", 9, 4, SX_NONE),
    SX_FIELD("magnification", "uint32", 13, 4, SX_NONE),
    SX_FIELD("max_height", "uint32", 17, 4, SX_NONE),
    SX_FIELD("max_width", "uint32", 21, 4, SX_NONE),
    SX_FIELD("max_stack_depth", "uint16", 25, 2, SX_COUNT_PROP),
    SX_FIELD("page_count", "uint16", 27, 2, SX_COUNT_PROP),
};
const sx_layout sx_p_dvi_postamble = { UINT32_C(0x6007004D), "dvi_postamble", sx_p_dvi_postamble_fields, SX_COUNT(sx_p_dvi_postamble_fields), SX_BE };
static const xx_data_struct_field_desc sx_p_dvi_post_post_fields[] = {
    SX_FIELD("opcode", "uint8", 0, 1, SX_ID),
    SX_FIELD("postamble_offset", "uint32", 1, 4, SX_OFFSET),
    SX_FIELD("version", "uint8", 5, 1, SX_ID),
};
const sx_layout sx_p_dvi_post_post = { UINT32_C(0x6007004E), "dvi_post_post", sx_p_dvi_post_post_fields, SX_COUNT(sx_p_dvi_post_post_fields), SX_BE };
static const xx_data_struct_field_desc sx_p_dvi_page_fields[] = {
    SX_FIELD("opcode", "uint8", 0, 1, SX_ID),
    SX_FIELD("count0", "int32", 1, 4, SX_NONE),
    SX_FIELD("count1", "int32", 5, 4, SX_NONE),
    SX_FIELD("count2", "int32", 9, 4, SX_NONE),
    SX_FIELD("count3", "int32", 13, 4, SX_NONE),
    SX_FIELD("count4", "int32", 17, 4, SX_NONE),
    SX_FIELD("count5", "int32", 21, 4, SX_NONE),
    SX_FIELD("count6", "int32", 25, 4, SX_NONE),
    SX_FIELD("count7", "int32", 29, 4, SX_NONE),
    SX_FIELD("count8", "int32", 33, 4, SX_NONE),
    SX_FIELD("count9", "int32", 37, 4, SX_NONE),
    SX_FIELD("previous_page", "int32", 41, 4, SX_OFFSET),
};
const sx_layout sx_p_dvi_page = { UINT32_C(0x6007005B), "dvi_page", sx_p_dvi_page_fields, SX_COUNT(sx_p_dvi_page_fields), SX_BE };
static bool sx_p_dvi(sx_context *c)
{
    uint8_t n,b;if(!sx_p_sig(c,0,"\xf7\2",2)||!sx_p_byte(c,14,&n)||!sx_p_span(c,15,n)||!sx_add(c,&sx_p_dvi_preamble,0,15)||c->size<10)return false;
    int64_t end=c->size;unsigned padding=0;while(end>0){if(!sx_p_byte(c,end-1,&b))return false;if(b!=223)break;end--;padding++;}if(padding<4||end<6)return false;
    uint32_t post;if(!sx_p_byte(c,end-6,&b)||b!=249||!sx_u32(c,end-5,true,&post)||!sx_p_byte(c,end-1,&b)||b!=2||post>=end-6||!sx_p_byte(c,post,&b)||b!=248||!sx_add(c,&sx_p_dvi_postamble,post,29)||!sx_add(c,&sx_p_dvi_post_post,end-6,6))return false;
    uint32_t page,previous;uint16_t pages;if(!sx_u32(c,(int64_t)post+1,true,&page)||!sx_u16(c,(int64_t)post+27,true,&pages))return false;unsigned seen=0;
    while(page!=UINT32_MAX){if(page>=post||!sx_p_byte(c,page,&b)||b!=139||!sx_add(c,&sx_p_dvi_page,page,45)||!sx_u32(c,(int64_t)page+41,true,&previous)||(++seen)>pages||(previous!=UINT32_MAX&&previous>=page))return false;page=previous;}
    return seen==pages;
}
bool sx_tex_dvi_build(sx_context*c)
{
    return sx_p_dvi(c);
}
