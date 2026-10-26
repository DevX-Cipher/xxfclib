/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * PHOTOSHOP PAT data structures, moved out of the nextmedia schema family. */
#include "../../xx_format_schema_nextmedia.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnx_pat_header_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_ID),
 SX_FIELD("pattern_count","uint32",6,4,SX_COUNT_PROP),
};
const sx_layout sxnx_pat_header={UINT32_C(0x6032003A),"pat_header",sxnx_pat_header_fields,SX_COUNT(sxnx_pat_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_pat_pattern_fields[]={
 SX_FIELD("version","uint32",0,4,SX_ID),
 SX_FIELD("image_mode","uint32",4,4,SX_ID),
 SX_FIELD("height","uint16",8,2,SX_COUNT_PROP),
 SX_FIELD("width","uint16",10,2,SX_COUNT_PROP),
 SX_FIELD("name_utf16_units","uint32",12,4,SX_COUNT_PROP),
};
const sx_layout sxnx_pat_pattern={UINT32_C(0x6032003B),"pat_pattern",sxnx_pat_pattern_fields,SX_COUNT(sxnx_pat_pattern_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_pat_id_length_fields[]={
 SX_FIELD("id_bytes","uint8",0,1,SX_SIZE),
};
const sx_layout sxnx_pat_id_length={UINT32_C(0x6032003C),"pat_id_length",sxnx_pat_id_length_fields,SX_COUNT(sxnx_pat_id_length_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_pat_vma_fields[]={
 SX_FIELD("version","uint32",0,4,SX_ID),
 SX_FIELD("data_size","uint32",4,4,SX_SIZE),
 SX_FIELD("top","int32",8,4,SX_NONE),
 SX_FIELD("left","int32",12,4,SX_NONE),
 SX_FIELD("bottom","int32",16,4,SX_NONE),
 SX_FIELD("right","int32",20,4,SX_NONE),
 SX_FIELD("channel_count","uint32",24,4,SX_COUNT_PROP),
};
const sx_layout sxnx_pat_vma={UINT32_C(0x6032003D),"pat_vma",sxnx_pat_vma_fields,SX_COUNT(sxnx_pat_vma_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_pat_slot_fields[]={
 SX_FIELD("present","uint32",0,4,SX_FLAGS),
};
const sx_layout sxnx_pat_slot={UINT32_C(0x6032003E),"pat_slot",sxnx_pat_slot_fields,SX_COUNT(sxnx_pat_slot_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_pat_channel_fields[]={
 SX_FIELD("data_size","uint32",0,4,SX_SIZE),
 SX_FIELD("depth","uint32",4,4,SX_NONE),
 SX_FIELD("top","int32",8,4,SX_NONE),
 SX_FIELD("left","int32",12,4,SX_NONE),
 SX_FIELD("bottom","int32",16,4,SX_NONE),
 SX_FIELD("right","int32",20,4,SX_NONE),
 SX_FIELD("pixel_depth","uint16",24,2,SX_NONE),
 SX_FIELD("compression","uint8",26,1,SX_ID),
};
const sx_layout sxnx_pat_channel={UINT32_C(0x6032003F),"pat_channel",sxnx_pat_channel_fields,SX_COUNT(sxnx_pat_channel_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_pat_row_size_fields[]={
 SX_FIELD("packed_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxnx_pat_row_size={UINT32_C(0x60320040),"pat_row_size",sxnx_pat_row_size_fields,SX_COUNT(sxnx_pat_row_size_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_pat_hierarchy_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("key","bytes",4,4,SX_ID),
 SX_FIELD("data_size","uint32",8,4,SX_SIZE),
};
const sx_layout sxnx_pat_hierarchy={UINT32_C(0x60320041),"pat_hierarchy",sxnx_pat_hierarchy_fields,SX_COUNT(sxnx_pat_hierarchy_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_pat_empty_descriptor_fields[]={
 SX_FIELD("version","uint32",0,4,SX_ID),
 SX_FIELD("name_utf16_units","uint32",4,4,SX_COUNT_PROP),
 SX_FIELD("name_utf16","bytes",8,2,SX_NONE),
 SX_FIELD("class_id_length","uint32",10,4,SX_SIZE),
 SX_FIELD("class_id","bytes",14,4,SX_ID),
 SX_FIELD("item_count","uint32",18,4,SX_COUNT_PROP),
 SX_FIELD("key_length","uint32",22,4,SX_SIZE),
 SX_FIELD("key","char[9]",26,9,SX_STRING),
 SX_FIELD("value_type","bytes",35,4,SX_ID),
 SX_FIELD("list_count","uint32",39,4,SX_COUNT_PROP),
};
const sx_layout sxnx_pat_empty_descriptor={UINT32_C(0x60320042),"pat_empty_descriptor",sxnx_pat_empty_descriptor_fields,SX_COUNT(sxnx_pat_empty_descriptor_fields),SX_BE};
#define SN_ROW(l,at,end) sxnx_row(v,&sxnx_##l,(at),(end))
static bool sxnx_pat(sxnx_view*v)
{if(!SN_ROW(pat_header,0,v->n))return false;unsigned count=sxnx_u32(v->p+6,true);if(count>4094)return false;size_t p=10;
 for(unsigned i=0;i<count;i++){if(!SN_ROW(pat_pattern,p,v->n))return false;unsigned h=sxnx_u16(v->p+p+8,true),units=sxnx_u32(v->p+p+12,true);p+=16;if(!sxnx_need(v,p,(uint64_t)units*2,v->n))return false;p+=units*2;if(!SN_ROW(pat_id_length,p,v->n))return false;unsigned id=v->p[p++];if(!sxnx_need(v,p,id,v->n))return false;p+=id;if(!SN_ROW(pat_vma,p,v->n))return false;uint32_t n=sxnx_u32(v->p+p+4,true),channels=sxnx_u32(v->p+p+24,true);if(n<20||channels>64||!sxnx_need(v,p+8,n,v->n))return false;size_t end=p+8+n;p+=28;
 for(unsigned j=0;j<channels+2;j++){if(!SN_ROW(pat_slot,p,end))return false;unsigned yes=sxnx_u32(v->p+p,true);p+=4;if(yes){if(!SN_ROW(pat_channel,p,end))return false;uint32_t z=sxnx_u32(v->p+p,true);if(z<23||!sxnx_need(v,p+4,z,end))return false;if(v->p[p+26]==1&&!sxnx_table(v,&sxnx_pat_row_size,p+27,h,p+4+z))return false;p+=4+z;}}if(p!=end)return false;}
 if(p<v->n){if(!SN_ROW(pat_hierarchy,p,v->n)||!SN_ROW(pat_empty_descriptor,p+12,v->n))return false;p+=55;}return p==v->n;}
bool sx_photoshop_pat_build(sxnx_view*v)
{
 return sxnx_pat(v);
}
#undef SN_ROW
