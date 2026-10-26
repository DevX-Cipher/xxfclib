/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * DjVu documents data structures, moved out of the docmeta schema family. */
#include "../../xx_format_schema_docmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdm_djvu_form_header_fields[]={
 SX_FIELD("magic","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("form_size","uint32",8,4,SX_SIZE),
 SX_FIELD("form_type","char[4]",12,4,SX_ID),
};
const sx_layout sxdm_djvu_form_header={UINT32_C(0x60230001),"djvu_form_header",sxdm_djvu_form_header_fields,SX_COUNT(sxdm_djvu_form_header_fields),SX_BE};
static const xx_data_struct_field_desc sxdm_djvu_chunk_header_fields[]={
 SX_FIELD("chunk_id","char[4]",0,4,SX_ID),
 SX_FIELD("data_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxdm_djvu_chunk_header={UINT32_C(0x60230002),"djvu_chunk_header",sxdm_djvu_chunk_header_fields,SX_COUNT(sxdm_djvu_chunk_header_fields),SX_BE};
static const xx_data_struct_field_desc sxdm_djvu_info_fields[]={
 SX_FIELD("width","uint16be",0,2,SX_COUNT_PROP),
 SX_FIELD("height","uint16be",2,2,SX_COUNT_PROP),
 SX_FIELD("version","uint16",4,2,SX_ID),
 SX_FIELD("dpi","uint16",6,2,SX_NONE),
 SX_FIELD("gamma_times_ten","uint8",8,1,SX_NONE),
 SX_FIELD("orientation","uint8",9,1,SX_ID),
};
const sx_layout sxdm_djvu_info={UINT32_C(0x60230003),"djvu_info",sxdm_djvu_info_fields,SX_COUNT(sxdm_djvu_info_fields),SX_LE};
static bool sxdm_djvu(sx_context *c)
{
 uint8_t b[16];if(!sx_read(c,0,b,16)||xx_rt_memcmp(b,"AT&TFORM",8)||xx_rt_memcmp(b+12,"DJVU",4)||!sxdm_add(c,&sxdm_djvu_form_header,0,16))return false;
 uint32_t n=xx_data_get_u32(b+8,4,0,true);int64_t end=12+(int64_t)n,at=16;if(n<4||!sxdm_span(c,0,(uint64_t)end))return false;
 for(unsigned i=0;at<end;i++){if(i>=4096||end-at<8||!sx_read(c,at,b,8))return false;n=xx_data_get_u32(b+4,4,0,true);if((uint64_t)n+(n&1)> (uint64_t)(end-at-8)||!sxdm_add(c,&sxdm_djvu_chunk_header,at,8))return false;if(!xx_rt_memcmp(b,"INFO",4)&&n==10&&!sxdm_add(c,&sxdm_djvu_info,at+8,10))return false;at+=8+(int64_t)n+(n&1);}return true;
}
bool sx_djvu_build(sx_context*c)
{
 return sxdm_djvu(c);
}
