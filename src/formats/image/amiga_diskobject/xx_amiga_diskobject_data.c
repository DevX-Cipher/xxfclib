/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * AMIGA DISKOBJECT data structures, moved out of the nextmedia schema family. */
#include "../../xx_format_schema_nextmedia.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnx_icon_diskobject_fields[]={
 SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("version","uint16",2,2,SX_ID),
 SX_FIELD("next_gadget","uint32",4,4,SX_POINTER),
 SX_FIELD("left","int16",8,2,SX_NONE),
 SX_FIELD("top","int16",10,2,SX_NONE),
 SX_FIELD("width","int16",12,2,SX_NONE),
 SX_FIELD("height","int16",14,2,SX_NONE),
 SX_FIELD("gadget_flags","uint16",16,2,SX_FLAGS),
 SX_FIELD("activation","uint16",18,2,SX_FLAGS),
 SX_FIELD("gadget_type","uint16",20,2,SX_FLAGS),
 SX_FIELD("gadget_render","uint32",22,4,SX_POINTER),
 SX_FIELD("select_render","uint32",26,4,SX_POINTER),
 SX_FIELD("gadget_text","uint32",30,4,SX_POINTER),
 SX_FIELD("mutual_exclude","int32",34,4,SX_NONE),
 SX_FIELD("special_info","uint32",38,4,SX_POINTER),
 SX_FIELD("gadget_id","uint16",42,2,SX_ID),
 SX_FIELD("user_data","uint32",44,4,SX_POINTER),
 SX_FIELD("object_type","uint8",48,1,SX_ID),
 SX_FIELD("padding","uint8",49,1,SX_RESERVED),
 SX_FIELD("default_tool","uint32",50,4,SX_POINTER),
 SX_FIELD("tool_types","uint32",54,4,SX_POINTER),
 SX_FIELD("current_x","int32",58,4,SX_NONE),
 SX_FIELD("current_y","int32",62,4,SX_NONE),
 SX_FIELD("drawer_data","uint32",66,4,SX_POINTER),
 SX_FIELD("tool_window","uint32",70,4,SX_POINTER),
 SX_FIELD("stack_size","int32",74,4,SX_SIZE),
};
const sx_layout sxnx_icon_diskobject={UINT32_C(0x60320052),"icon_diskobject",sxnx_icon_diskobject_fields,SX_COUNT(sxnx_icon_diskobject_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_icon_drawer_fields[]={
 SX_FIELD("left","int16",0,2,SX_NONE),
 SX_FIELD("top","int16",2,2,SX_NONE),
 SX_FIELD("width","int16",4,2,SX_NONE),
 SX_FIELD("height","int16",6,2,SX_NONE),
 SX_FIELD("detail_pen","uint8",8,1,SX_NONE),
 SX_FIELD("block_pen","uint8",9,1,SX_NONE),
 SX_FIELD("idcmp_flags","uint32",10,4,SX_FLAGS),
 SX_FIELD("window_flags","uint32",14,4,SX_FLAGS),
 SX_FIELD("first_gadget","uint32",18,4,SX_POINTER),
 SX_FIELD("check_mark","uint32",22,4,SX_POINTER),
 SX_FIELD("title","uint32",26,4,SX_POINTER),
 SX_FIELD("screen","uint32",30,4,SX_POINTER),
 SX_FIELD("bitmap","uint32",34,4,SX_POINTER),
 SX_FIELD("min_width","int16",38,2,SX_NONE),
 SX_FIELD("min_height","int16",40,2,SX_NONE),
 SX_FIELD("max_width","uint16",42,2,SX_NONE),
 SX_FIELD("max_height","uint16",44,2,SX_NONE),
 SX_FIELD("window_type","uint16",46,2,SX_ID),
 SX_FIELD("current_x","int32",48,4,SX_NONE),
 SX_FIELD("current_y","int32",52,4,SX_NONE),
};
const sx_layout sxnx_icon_drawer={UINT32_C(0x60320053),"icon_drawer",sxnx_icon_drawer_fields,SX_COUNT(sxnx_icon_drawer_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_icon_image_fields[]={
 SX_FIELD("left","int16",0,2,SX_NONE),
 SX_FIELD("top","int16",2,2,SX_NONE),
 SX_FIELD("width","int16",4,2,SX_NONE),
 SX_FIELD("height","int16",6,2,SX_NONE),
 SX_FIELD("depth","int16",8,2,SX_NONE),
 SX_FIELD("image_data","uint32",10,4,SX_POINTER),
 SX_FIELD("plane_pick","uint8",14,1,SX_FLAGS),
 SX_FIELD("plane_on_off","uint8",15,1,SX_FLAGS),
 SX_FIELD("next_image","uint32",16,4,SX_POINTER),
};
const sx_layout sxnx_icon_image={UINT32_C(0x60320054),"icon_image",sxnx_icon_image_fields,SX_COUNT(sxnx_icon_image_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_icon_string_fields[]={
 SX_FIELD("string_bytes","uint32",0,4,SX_SIZE),
};
const sx_layout sxnx_icon_string={UINT32_C(0x60320055),"icon_string",sxnx_icon_string_fields,SX_COUNT(sxnx_icon_string_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_icon_tooltypes_fields[]={
 SX_FIELD("pointer_array_bytes","uint32",0,4,SX_SIZE),
};
const sx_layout sxnx_icon_tooltypes={UINT32_C(0x60320056),"icon_tooltypes",sxnx_icon_tooltypes_fields,SX_COUNT(sxnx_icon_tooltypes_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_icon_new_drawer_fields[]={
 SX_FIELD("flags","uint32",0,4,SX_FLAGS),
 SX_FIELD("view_mode","uint16",4,2,SX_ID),
};
const sx_layout sxnx_icon_new_drawer={UINT32_C(0x60320057),"icon_new_drawer",sxnx_icon_new_drawer_fields,SX_COUNT(sxnx_icon_new_drawer_fields),SX_BE};
#define SN_ROW(l,at,end) sxnx_row(v,&sxnx_##l,(at),(end))
static bool sxnx_walk_icon_string(sxnx_view*v,size_t*p){if(!SN_ROW(icon_string,*p,v->n))return false;unsigned n=sxnx_u32(v->p+*p,true);*p+=4;if(!sxnx_need(v,*p,n,v->n))return false;*p+=n;return true;}
static bool sxnx_icon(sxnx_view*v)
{if(!SN_ROW(icon_diskobject,0,v->n))return false;size_t p=78;bool drawer=sxnx_u32(v->p+66,true)!=0;if(drawer){if(!SN_ROW(icon_drawer,p,v->n))return false;p+=56;}
 for(unsigned i=0;i<(sxnx_u32(v->p+26,true)?2:1);i++){if(!SN_ROW(icon_image,p,v->n))return false;uint64_t w=sxnx_u16(v->p+p+4,true),h=sxnx_u16(v->p+p+6,true),d=sxnx_u16(v->p+p+8,true),z=((w+15)/16)*2*h*d;p+=20;if(!sxnx_need(v,p,z,v->n))return false;p+=(size_t)z;}
 if(sxnx_u32(v->p+50,true)&&!sxnx_walk_icon_string(v,&p))return false;if(sxnx_u32(v->p+54,true)){if(!SN_ROW(icon_tooltypes,p,v->n))return false;unsigned n=sxnx_u32(v->p+p,true);p+=4;if(n<4||n>8192||(n&3))return false;for(unsigned i=0;i<n/4-1;i++)if(!sxnx_walk_icon_string(v,&p))return false;}if(sxnx_u32(v->p+70,true)&&!sxnx_walk_icon_string(v,&p))return false;if(drawer&&(sxnx_u32(v->p+44,true)&255)){if(!SN_ROW(icon_new_drawer,p,v->n))return false;p+=6;}return p==v->n;}
bool sx_amiga_diskobject_build(sxnx_view*v)
{
 return sxnx_icon(v);
}
#undef SN_ROW
