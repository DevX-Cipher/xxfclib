/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * sgi_rgb data structures, moved out of the media schema family. */
#include "../../xx_format_schema_media.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxm_be_offset32_fields[] = {
    SX_FIELD("offset", "uint32", 0, 4, SX_OFFSET),
};
const sx_layout sxm_be_offset32 = {UINT32_C(0x6006000C), "be_offset32", sxm_be_offset32_fields, SX_COUNT(sxm_be_offset32_fields), SX_BE};
bool sx_sgi_rgb_build(sx_context*c,uint8_t*h,size_t n)
{
 uint64_t at=512,rows;if(n<108||xx_data_get_u16(h,n,0,true)!=474||!sx_add(c,&sxm_sgi_header,0,512))return false;if(h[2]==1){rows=(uint64_t)xx_data_get_u16(h,n,8,true)*xx_data_get_u16(h,n,10,true);if(!rows||!sx_table(c,&sxm_be_offset32,512,4,rows)||!sx_table(c,&sxm_be_length32,512+(int64_t)rows*4,4,rows))return false;for(uint64_t i=0;i<rows;i++){uint32_t off,z;if(!sx_u32(c,512+(int64_t)i*4,true,&off)||!sx_u32(c,512+(int64_t)(rows+i)*4,true,&z)||!sxm_span(c,off,z))return false;}at+=rows*8;}return sxm_tail(c,at);
}
