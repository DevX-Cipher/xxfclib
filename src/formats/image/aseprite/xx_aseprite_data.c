/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * aseprite data structures, moved out of the rastermore schema family. */
#include "../../xx_format_schema_rastermore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxrm_aseprite_header_fields[] = {
    SX_FIELD("file_size","uint32",0,4,SX_SIZE),
    SX_FIELD("magic","uint16",4,2,SX_SIGNATURE),
    SX_FIELD("frames","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("width","uint16",8,2,SX_COUNT_PROP),
    SX_FIELD("height","uint16",10,2,SX_COUNT_PROP),
    SX_FIELD("color_depth","uint16",12,2,SX_NONE),
    SX_FIELD("flags","uint32",14,4,SX_FLAGS),
    SX_FIELD("speed_milliseconds","uint16",18,2,SX_NONE),
    SX_FIELD("reserved0","uint32",20,4,SX_RESERVED),
    SX_FIELD("reserved1","uint32",24,4,SX_RESERVED),
    SX_FIELD("transparent_palette_index","uint8",28,1,SX_ID),
    SX_FIELD("ignored","uint8[3]",29,3,SX_RESERVED),
    SX_FIELD("color_count","uint16",32,2,SX_COUNT_PROP),
    SX_FIELD("pixel_width","uint8",34,1,SX_NONE),
    SX_FIELD("pixel_height","uint8",35,1,SX_NONE),
    SX_FIELD("grid_x","int16",36,2,SX_NONE),
    SX_FIELD("grid_y","int16",38,2,SX_NONE),
    SX_FIELD("grid_width","uint16",40,2,SX_COUNT_PROP),
    SX_FIELD("grid_height","uint16",42,2,SX_COUNT_PROP),
    SX_FIELD("reserved2","uint8[84]",44,84,SX_RESERVED),
};
const sx_layout sxrm_aseprite_header = {UINT32_C(0x601d004b),"aseprite_header",sxrm_aseprite_header_fields,SX_COUNT(sxrm_aseprite_header_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_aseprite_frame_fields[] = {
    SX_FIELD("frame_size","uint32",0,4,SX_SIZE),
    SX_FIELD("magic","uint16",4,2,SX_SIGNATURE),
    SX_FIELD("old_chunk_count","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("duration_milliseconds","uint16",8,2,SX_NONE),
    SX_FIELD("reserved","uint8[2]",10,2,SX_RESERVED),
    SX_FIELD("chunk_count","uint32",12,4,SX_COUNT_PROP),
};
const sx_layout sxrm_aseprite_frame = {UINT32_C(0x601d004c),"aseprite_frame",sxrm_aseprite_frame_fields,SX_COUNT(sxrm_aseprite_frame_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_aseprite_chunk_fields[] = {
    SX_FIELD("chunk_size","uint32",0,4,SX_SIZE),
    SX_FIELD("chunk_type","uint16",4,2,SX_ID),
};
const sx_layout sxrm_aseprite_chunk = {UINT32_C(0x601d004d),"aseprite_chunk",sxrm_aseprite_chunk_fields,SX_COUNT(sxrm_aseprite_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_aseprite_layer_fields[] = {
    SX_FIELD("flags","uint16",0,2,SX_FLAGS),
    SX_FIELD("layer_type","uint16",2,2,SX_ID),
    SX_FIELD("child_level","uint16",4,2,SX_NONE),
    SX_FIELD("default_width","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("default_height","uint16",8,2,SX_COUNT_PROP),
    SX_FIELD("blend_mode","uint16",10,2,SX_ID),
    SX_FIELD("opacity","uint8",12,1,SX_NONE),
    SX_FIELD("reserved","uint8[3]",13,3,SX_RESERVED),
    SX_FIELD("name_length","uint16",16,2,SX_SIZE),
};
const sx_layout sxrm_aseprite_layer = {UINT32_C(0x601d004e),"aseprite_layer",sxrm_aseprite_layer_fields,SX_COUNT(sxrm_aseprite_layer_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_aseprite_layer_uuid_fields[] = {
    SX_FIELD("uuid","uint8[16]",0,16,SX_ID),
};
const sx_layout sxrm_aseprite_layer_uuid = {UINT32_C(0x601d004f),"aseprite_layer_uuid",sxrm_aseprite_layer_uuid_fields,SX_COUNT(sxrm_aseprite_layer_uuid_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_aseprite_cel_fields[] = {
    SX_FIELD("layer_index","uint16",0,2,SX_ID),
    SX_FIELD("x","int16",2,2,SX_NONE),
    SX_FIELD("y","int16",4,2,SX_NONE),
    SX_FIELD("opacity","uint8",6,1,SX_NONE),
    SX_FIELD("cel_type","uint16",7,2,SX_ID),
    SX_FIELD("z_index","int16",9,2,SX_NONE),
    SX_FIELD("reserved","uint8[5]",11,5,SX_RESERVED),
};
const sx_layout sxrm_aseprite_cel = {UINT32_C(0x601d0050),"aseprite_cel",sxrm_aseprite_cel_fields,SX_COUNT(sxrm_aseprite_cel_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_aseprite_cel_dimensions_fields[] = {
    SX_FIELD("width","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("height","uint16",2,2,SX_COUNT_PROP),
};
const sx_layout sxrm_aseprite_cel_dimensions = {UINT32_C(0x601d0051),"aseprite_cel_dimensions",sxrm_aseprite_cel_dimensions_fields,SX_COUNT(sxrm_aseprite_cel_dimensions_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_aseprite_linked_cel_fields[] = {
    SX_FIELD("frame_index","uint16",0,2,SX_ID),
};
const sx_layout sxrm_aseprite_linked_cel = {UINT32_C(0x601d0052),"aseprite_linked_cel",sxrm_aseprite_linked_cel_fields,SX_COUNT(sxrm_aseprite_linked_cel_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_aseprite_palette_fields[] = {
    SX_FIELD("palette_size","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("first_index","uint32",4,4,SX_ID),
    SX_FIELD("last_index","uint32",8,4,SX_ID),
    SX_FIELD("reserved","uint8[8]",12,8,SX_RESERVED),
};
const sx_layout sxrm_aseprite_palette = {UINT32_C(0x601d0053),"aseprite_palette",sxrm_aseprite_palette_fields,SX_COUNT(sxrm_aseprite_palette_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_aseprite_palette_entry_fields[] = {
    SX_FIELD("flags","uint16",0,2,SX_FLAGS),
    SX_FIELD("red","uint8",2,1,SX_NONE),
    SX_FIELD("green","uint8",3,1,SX_NONE),
    SX_FIELD("blue","uint8",4,1,SX_NONE),
    SX_FIELD("alpha","uint8",5,1,SX_NONE),
};
const sx_layout sxrm_aseprite_palette_entry = {UINT32_C(0x601d0054),"aseprite_palette_entry",sxrm_aseprite_palette_entry_fields,SX_COUNT(sxrm_aseprite_palette_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_aseprite_string_length_fields[] = {
    SX_FIELD("byte_length","uint16",0,2,SX_SIZE),
};
const sx_layout sxrm_aseprite_string_length = {UINT32_C(0x601d0055),"aseprite_string_length",sxrm_aseprite_string_length_fields,SX_COUNT(sxrm_aseprite_string_length_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_aseprite_user_flags_fields[] = {
    SX_FIELD("flags","uint32",0,4,SX_FLAGS),
};
const sx_layout sxrm_aseprite_user_flags = {UINT32_C(0x601d0056),"aseprite_user_flags",sxrm_aseprite_user_flags_fields,SX_COUNT(sxrm_aseprite_user_flags_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_aseprite_rgba_fields[] = {
    SX_FIELD("red","uint8",0,1,SX_NONE),
    SX_FIELD("green","uint8",1,1,SX_NONE),
    SX_FIELD("blue","uint8",2,1,SX_NONE),
    SX_FIELD("alpha","uint8",3,1,SX_NONE),
};
const sx_layout sxrm_aseprite_rgba = {UINT32_C(0x601d0057),"aseprite_rgba",sxrm_aseprite_rgba_fields,SX_COUNT(sxrm_aseprite_rgba_fields),SX_LE};
static bool sxrm_ase_string(sx_context *c,uint64_t *p,uint64_t end)
{
 uint8_t h[2];if(*p>end||end-*p<2||!sxrm_read(c,*p,h,2))return false;uint32_t n=sxrm16(h,false);if(n>end-*p-2)return false;if(!sxrm_add(c,&sxrm_aseprite_string_length,*p))return false;*p+=2+n;return true;
}
static bool sxrm_aseprite(sx_context *c)
{
 uint8_t h[128];if(!sxrm_read(c,0,h,128)||sxrm16(h+4,false)!=0xa5e0||!sxrm_add(c,&sxrm_aseprite_header,0))return false;unsigned frames=sxrm16(h+6,false),flags=sxrm32(h+14,false),budget=0;uint64_t p=128;
 for(unsigned i=0;i<frames&&i<4096;i++){
  if(!sxrm_read(c,p,h,16))break;uint32_t z=sxrm32(h,false),chunks=sxrm32(h+12,false);if(!chunks)chunks=sxrm16(h+6,false);if(z<16||!sxrm_span(c,p,z)||chunks>4096)break;if(!sxrm_add(c,&sxrm_aseprite_frame,p))return false;uint64_t q=p+16,end=p+z;
  for(unsigned k=0;k<chunks&&budget++<20000;k++){
   if(end-q<6||!sxrm_read(c,q,h,6))break;uint32_t n=sxrm32(h,false);unsigned type=sxrm16(h+4,false);if(n<6||n>end-q)break;if(!sxrm_add(c,&sxrm_aseprite_chunk,q))return false;uint64_t a=q+6,stop=q+n;n-=6;
   if(type==0x2004&&n>=18){if(!sxrm_read(c,a,h,18)||!sxrm_add(c,&sxrm_aseprite_layer,a))return false;uint64_t tail=a+18+sxrm16(h+16,false);if((flags&4)&&tail<=stop&&stop-tail>=16&&!sxrm_add(c,&sxrm_aseprite_layer_uuid,tail))return false;}
   else if(type==0x2005&&n>=16){if(!sxrm_read(c,a,h,16)||!sxrm_add(c,&sxrm_aseprite_cel,a))return false;unsigned ct=sxrm16(h+7,false);if((ct==0||ct==2)&&n>=20){if(!sxrm_add(c,&sxrm_aseprite_cel_dimensions,a+16))return false;}else if(ct==1&&n>=18&&!sxrm_add(c,&sxrm_aseprite_linked_cel,a+16))return false;}
   else if(type==0x2019&&n>=20){if(!sxrm_read(c,a,h,20)||!sxrm_add(c,&sxrm_aseprite_palette,a))return false;uint32_t first=sxrm32(h+4,false),last=sxrm32(h+8,false);uint64_t r=a+20;if(last>=first&&last-first<4096)for(uint64_t j=0;j<=(uint64_t)last-first;j++){if(stop-r<6||!sxrm_read(c,r,h,6))break;if(!sxrm_add(c,&sxrm_aseprite_palette_entry,r))return false;r+=6;if((sxrm16(h,false)&1)&&!sxrm_ase_string(c,&r,stop))break;}}
   else if(type==0x2020&&n>=4){if(!sxrm_read(c,a,h,4)||!sxrm_add(c,&sxrm_aseprite_user_flags,a))return false;uint32_t uf=sxrm32(h,false);uint64_t r=a+4;bool good=!(uf&1)||sxrm_ase_string(c,&r,stop);if(good&&(uf&2)&&stop-r>=4&&!sxrm_add(c,&sxrm_aseprite_rgba,r))return false;}
   q=stop;
  }p=end;
 }return !c->failed;
}
bool sx_aseprite_build(sx_context*c)
{
 return sxrm_aseprite(c);
}
