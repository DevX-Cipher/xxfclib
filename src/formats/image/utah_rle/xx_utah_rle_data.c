/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * utah rle data structures, moved out of the rastermore schema family. */
#include "../../xx_format_schema_rastermore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxrm_utah_rle_header_fields[] = {
    SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("x_position","int16",2,2,SX_NONE),
    SX_FIELD("y_position","int16",4,2,SX_NONE),
    SX_FIELD("width","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("height","uint16",8,2,SX_COUNT_PROP),
    SX_FIELD("flags","uint8",10,1,SX_FLAGS),
    SX_FIELD("color_channels","uint8",11,1,SX_COUNT_PROP),
    SX_FIELD("pixel_bits","uint8",12,1,SX_NONE),
    SX_FIELD("colormap_channels","uint8",13,1,SX_COUNT_PROP),
    SX_FIELD("colormap_length_log2","uint8",14,1,SX_NONE),
};
const sx_layout sxrm_utah_rle_header = {UINT32_C(0x601d0028),"utah_rle_header",sxrm_utah_rle_header_fields,SX_COUNT(sxrm_utah_rle_header_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_utah_background_fields[] = {
    SX_FIELD("value","uint8",0,1,SX_NONE),
};
const sx_layout sxrm_utah_background = {UINT32_C(0x601d0029),"utah_background",sxrm_utah_background_fields,SX_COUNT(sxrm_utah_background_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_utah_colormap_fields[] = {
    SX_FIELD("value","uint16",0,2,SX_NONE),
};
const sx_layout sxrm_utah_colormap = {UINT32_C(0x601d002a),"utah_colormap",sxrm_utah_colormap_fields,SX_COUNT(sxrm_utah_colormap_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_utah_comment_length_fields[] = {
    SX_FIELD("byte_length","uint16",0,2,SX_SIZE),
};
const sx_layout sxrm_utah_comment_length = {UINT32_C(0x601d002b),"utah_comment_length",sxrm_utah_comment_length_fields,SX_COUNT(sxrm_utah_comment_length_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_utah_opcode_fields[] = {
    SX_FIELD("opcode_and_flags","uint8",0,1,SX_FLAGS),
    SX_FIELD("operand","uint8",1,1,SX_NONE),
};
const sx_layout sxrm_utah_opcode = {UINT32_C(0x601d002c),"utah_opcode",sxrm_utah_opcode_fields,SX_COUNT(sxrm_utah_opcode_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_utah_long_opcode_fields[] = {
    SX_FIELD("opcode_and_flags","uint8",0,1,SX_FLAGS),
    SX_FIELD("unused","uint8",1,1,SX_RESERVED),
    SX_FIELD("operand","uint16",2,2,SX_NONE),
};
const sx_layout sxrm_utah_long_opcode = {UINT32_C(0x601d002d),"utah_long_opcode",sxrm_utah_long_opcode_fields,SX_COUNT(sxrm_utah_long_opcode_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_utah_run_value_fields[] = {
    SX_FIELD("value","uint8",0,1,SX_NONE),
    SX_FIELD("padding","uint8",1,1,SX_RESERVED),
};
const sx_layout sxrm_utah_run_value = {UINT32_C(0x601d002e),"utah_run_value",sxrm_utah_run_value_fields,SX_COUNT(sxrm_utah_run_value_fields),SX_LE};
static bool sxrm_utah(sx_context *c)
{
 uint8_t h[16];if(!sxrm_read(c,0,h,15)||sxrm16(h,false)!=0xcc52||!sxrm_add(c,&sxrm_utah_rle_header,0))return false;unsigned flags=h[10],colors=h[11],maps=h[13],log=h[14];uint64_t p=15;
 if(!(flags&2)&&colors&&colors<=4&&sxrm_span(c,p,colors)&&!sxrm_table(c,&sxrm_utah_background,p,colors))return false;p+=(flags&2)?1:1+(colors/2)*2;
 if(log>8||maps>4)return true;uint64_t n=(uint64_t)maps<<log;if(!sxrm_span(c,p,n*2))return true;if(n&&!sxrm_table(c,&sxrm_utah_colormap,p,n))return false;p+=n*2;
 if(flags&8){if(!sxrm_read(c,p,h,2))return true;n=sxrm16(h,false);if(!sxrm_span(c,p+2,n))return true;if(!sxrm_add(c,&sxrm_utah_comment_length,p))return false;p+=2+n+(n&1);}
 for(unsigned step=0;step<20000&&p<(uint64_t)c->size;step++){if(!sxrm_read(c,p,h,2))break;unsigned op=h[0]&0x3f,longop=h[0]&0x40;uint32_t count=h[1],size=longop?4:2;if(h[0]&0x80||op==0||op==4||op>7)break;
  if(longop){if(!sxrm_read(c,p,h,4))break;count=sxrm16(h+2,false);}if(!sxrm_add(c,longop?&sxrm_utah_long_opcode:&sxrm_utah_opcode,p))return false;p+=size;
  if(op==7)break;if(op==5){uint64_t z=(uint64_t)count+1;p+=z+(z&1);}else if(op==6){if(!sxrm_span(c,p,2))break;if(!sxrm_add(c,&sxrm_utah_run_value,p))return false;p+=2;}
 }return !c->failed;
}
bool sx_utah_rle_build(sx_context*c)
{
 return sxrm_utah(c);
}
