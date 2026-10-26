/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * eCos kernel data structures, moved out of the firmwaretail schema family. */
#include "../../xx_format_schema_firmwaretail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxftl_ecos_exception_prefix_le_fields[]={
 SX_FIELD("cause_instruction","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("mask_instruction","uint32",4,4,SX_SIGNATURE),
};
const sx_layout sxftl_ecos_exception_prefix_le={0x60860001U,"ecos_exception_prefix_le",sxftl_ecos_exception_prefix_le_fields,SX_COUNT(sxftl_ecos_exception_prefix_le_fields),SX_LE};
static const xx_data_struct_field_desc sxftl_ecos_exception_prefix_le_nop_fields[]={
 SX_FIELD("cause_instruction","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("nop_instruction","uint32",4,4,SX_NONE),
 SX_FIELD("mask_instruction","uint32",8,4,SX_SIGNATURE),
};
const sx_layout sxftl_ecos_exception_prefix_le_nop={0x60860002U,"ecos_exception_prefix_le_nop",sxftl_ecos_exception_prefix_le_nop_fields,SX_COUNT(sxftl_ecos_exception_prefix_le_nop_fields),SX_LE};
static const xx_data_struct_field_desc sxftl_ecos_exception_prefix_be_fields[]={
 SX_FIELD("cause_instruction","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("mask_instruction","uint32",4,4,SX_SIGNATURE),
};
const sx_layout sxftl_ecos_exception_prefix_be={0x60860003U,"ecos_exception_prefix_be",sxftl_ecos_exception_prefix_be_fields,SX_COUNT(sxftl_ecos_exception_prefix_be_fields),SX_BE};
static const xx_data_struct_field_desc sxftl_ecos_exception_prefix_be_nop_fields[]={
 SX_FIELD("cause_instruction","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("nop_instruction","uint32",4,4,SX_NONE),
 SX_FIELD("mask_instruction","uint32",8,4,SX_SIGNATURE),
};
const sx_layout sxftl_ecos_exception_prefix_be_nop={0x60860004U,"ecos_exception_prefix_be_nop",sxftl_ecos_exception_prefix_be_nop_fields,SX_COUNT(sxftl_ecos_exception_prefix_be_nop_fields),SX_BE};
bool sx_ecos_build(sx_context*c)
{
    uint8_t h[12];const sx_layout*l=NULL;int64_t size=0;
    if(c->f->file_type==XX_FILE_TYPE_ECOS){
        static const uint8_t prefixes[4][12]={
            {0x00,0x68,0x1a,0x40,0x00,0x00,0x00,0x00,0x7f,0x00,0x5a,0x33},
            {0x40,0x1a,0x68,0x00,0x00,0x00,0x00,0x00,0x33,0x5a,0x00,0x7f},
            {0x00,0x68,0x1a,0x40,0x7f,0x00,0x5a,0x33},
            {0x40,0x1a,0x68,0x00,0x33,0x5a,0x00,0x7f}};
        const sx_layout*layouts[]={&sxftl_ecos_exception_prefix_le_nop,&sxftl_ecos_exception_prefix_be_nop,&sxftl_ecos_exception_prefix_le,&sxftl_ecos_exception_prefix_be};
        for(size_t i=0;i<4;i++){size=i<2?12:8;if(c->size>=size&&sx_read(c,0,h,(size_t)size)&&!xx_rt_memcmp(h,prefixes[i],(size_t)size)){l=layouts[i];break;}}
    }

    return l&&sx_add(c,l,0,size)&&sx_raw(c,size,c->size-size);
}
