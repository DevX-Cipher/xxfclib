/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * BLENDER_BLEND data structures, moved out of the modelmeta schema family. */
#include "../../xx_format_schema_modelmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmo_blend_header_fields[] = {
    SX_FIELD("signature","char[7]",0,7,SX_SIGNATURE),
    SX_FIELD("pointer_size","char[1]",7,1,SX_ID),
    SX_FIELD("byte_order","char[1]",8,1,SX_ID),
    SX_FIELD("version","char[3]",9,3,SX_ID),
};
const sx_layout sxmo_blend_header = {UINT32_C(0x60210028),"blend_header",sxmo_blend_header_fields,SX_COUNT(sxmo_blend_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_blend_block32_le_fields[] = {
    SX_FIELD("code","char[4]",0,4,SX_ID),
    SX_FIELD("data_size","int32",4,4,SX_SIZE),
    SX_FIELD("old_pointer","uint32",8,4,SX_POINTER),
    SX_FIELD("dna_structure_index","int32",12,4,SX_ID),
    SX_FIELD("element_count","int32",16,4,SX_COUNT_PROP),
};
const sx_layout sxmo_blend_block32_le = {UINT32_C(0x60210029),"blend_block32_le",sxmo_blend_block32_le_fields,SX_COUNT(sxmo_blend_block32_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_blend_block64_le_fields[] = {
    SX_FIELD("code","char[4]",0,4,SX_ID),
    SX_FIELD("data_size","int32",4,4,SX_SIZE),
    SX_FIELD("old_pointer","uint64",8,8,SX_POINTER),
    SX_FIELD("dna_structure_index","int32",16,4,SX_ID),
    SX_FIELD("element_count","int32",20,4,SX_COUNT_PROP),
};
const sx_layout sxmo_blend_block64_le = {UINT32_C(0x6021002a),"blend_block64_le",sxmo_blend_block64_le_fields,SX_COUNT(sxmo_blend_block64_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_blend_dna_names_le_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("names_tag","char[4]",4,4,SX_ID),
    SX_FIELD("name_count","uint32",8,4,SX_COUNT_PROP),
};
const sx_layout sxmo_blend_dna_names_le = {UINT32_C(0x6021002b),"blend_dna_names_le",sxmo_blend_dna_names_le_fields,SX_COUNT(sxmo_blend_dna_names_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_blend_dna_types_le_fields[] = {
    SX_FIELD("tag","char[4]",0,4,SX_ID),
    SX_FIELD("type_count","uint32",4,4,SX_COUNT_PROP),
};
const sx_layout sxmo_blend_dna_types_le = {UINT32_C(0x6021002c),"blend_dna_types_le",sxmo_blend_dna_types_le_fields,SX_COUNT(sxmo_blend_dna_types_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_blend_dna_structures_le_fields[] = {
    SX_FIELD("tag","char[4]",0,4,SX_ID),
    SX_FIELD("structure_count","uint32",4,4,SX_COUNT_PROP),
};
const sx_layout sxmo_blend_dna_structures_le = {UINT32_C(0x6021002d),"blend_dna_structures_le",sxmo_blend_dna_structures_le_fields,SX_COUNT(sxmo_blend_dna_structures_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_blend_dna_lengths_tag_le_fields[] = {
    SX_FIELD("tag","char[4]",0,4,SX_ID),
};
const sx_layout sxmo_blend_dna_lengths_tag_le = {UINT32_C(0x6021002e),"blend_dna_lengths_tag_le",sxmo_blend_dna_lengths_tag_le_fields,SX_COUNT(sxmo_blend_dna_lengths_tag_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_blend_dna_type_size_le_fields[] = {
    SX_FIELD("type_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxmo_blend_dna_type_size_le = {UINT32_C(0x6021002f),"blend_dna_type_size_le",sxmo_blend_dna_type_size_le_fields,SX_COUNT(sxmo_blend_dna_type_size_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_blend_dna_structure_le_fields[] = {
    SX_FIELD("type_index","uint16",0,2,SX_ID),
    SX_FIELD("field_count","uint16",2,2,SX_COUNT_PROP),
};
const sx_layout sxmo_blend_dna_structure_le = {UINT32_C(0x60210030),"blend_dna_structure_le",sxmo_blend_dna_structure_le_fields,SX_COUNT(sxmo_blend_dna_structure_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_blend_dna_field_le_fields[] = {
    SX_FIELD("type_index","uint16",0,2,SX_ID),
    SX_FIELD("name_index","uint16",2,2,SX_ID),
};
const sx_layout sxmo_blend_dna_field_le = {UINT32_C(0x60210031),"blend_dna_field_le",sxmo_blend_dna_field_le_fields,SX_COUNT(sxmo_blend_dna_field_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_blend_block32_be_fields[] = {
    SX_FIELD("code","char[4]",0,4,SX_ID),
    SX_FIELD("data_size","int32",4,4,SX_SIZE),
    SX_FIELD("old_pointer","uint32",8,4,SX_POINTER),
    SX_FIELD("dna_structure_index","int32",12,4,SX_ID),
    SX_FIELD("element_count","int32",16,4,SX_COUNT_PROP),
};
const sx_layout sxmo_blend_block32_be = {UINT32_C(0x60210032),"blend_block32_be",sxmo_blend_block32_be_fields,SX_COUNT(sxmo_blend_block32_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmo_blend_block64_be_fields[] = {
    SX_FIELD("code","char[4]",0,4,SX_ID),
    SX_FIELD("data_size","int32",4,4,SX_SIZE),
    SX_FIELD("old_pointer","uint64",8,8,SX_POINTER),
    SX_FIELD("dna_structure_index","int32",16,4,SX_ID),
    SX_FIELD("element_count","int32",20,4,SX_COUNT_PROP),
};
const sx_layout sxmo_blend_block64_be = {UINT32_C(0x60210033),"blend_block64_be",sxmo_blend_block64_be_fields,SX_COUNT(sxmo_blend_block64_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmo_blend_dna_names_be_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("names_tag","char[4]",4,4,SX_ID),
    SX_FIELD("name_count","uint32",8,4,SX_COUNT_PROP),
};
const sx_layout sxmo_blend_dna_names_be = {UINT32_C(0x60210034),"blend_dna_names_be",sxmo_blend_dna_names_be_fields,SX_COUNT(sxmo_blend_dna_names_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmo_blend_dna_types_be_fields[] = {
    SX_FIELD("tag","char[4]",0,4,SX_ID),
    SX_FIELD("type_count","uint32",4,4,SX_COUNT_PROP),
};
const sx_layout sxmo_blend_dna_types_be = {UINT32_C(0x60210035),"blend_dna_types_be",sxmo_blend_dna_types_be_fields,SX_COUNT(sxmo_blend_dna_types_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmo_blend_dna_structures_be_fields[] = {
    SX_FIELD("tag","char[4]",0,4,SX_ID),
    SX_FIELD("structure_count","uint32",4,4,SX_COUNT_PROP),
};
const sx_layout sxmo_blend_dna_structures_be = {UINT32_C(0x60210036),"blend_dna_structures_be",sxmo_blend_dna_structures_be_fields,SX_COUNT(sxmo_blend_dna_structures_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmo_blend_dna_lengths_tag_be_fields[] = {
    SX_FIELD("tag","char[4]",0,4,SX_ID),
};
const sx_layout sxmo_blend_dna_lengths_tag_be = {UINT32_C(0x60210037),"blend_dna_lengths_tag_be",sxmo_blend_dna_lengths_tag_be_fields,SX_COUNT(sxmo_blend_dna_lengths_tag_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmo_blend_dna_type_size_be_fields[] = {
    SX_FIELD("type_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxmo_blend_dna_type_size_be = {UINT32_C(0x60210038),"blend_dna_type_size_be",sxmo_blend_dna_type_size_be_fields,SX_COUNT(sxmo_blend_dna_type_size_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmo_blend_dna_structure_be_fields[] = {
    SX_FIELD("type_index","uint16",0,2,SX_ID),
    SX_FIELD("field_count","uint16",2,2,SX_COUNT_PROP),
};
const sx_layout sxmo_blend_dna_structure_be = {UINT32_C(0x60210039),"blend_dna_structure_be",sxmo_blend_dna_structure_be_fields,SX_COUNT(sxmo_blend_dna_structure_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmo_blend_dna_field_be_fields[] = {
    SX_FIELD("type_index","uint16",0,2,SX_ID),
    SX_FIELD("name_index","uint16",2,2,SX_ID),
};
const sx_layout sxmo_blend_dna_field_be = {UINT32_C(0x6021003a),"blend_dna_field_be",sxmo_blend_dna_field_be_fields,SX_COUNT(sxmo_blend_dna_field_be_fields),SX_BE};
#define SXMO_E(n) (be?&sxmo_##n##_be:&sxmo_##n##_le)
static bool sxmo_blend_dna(sx_context*c,uint64_t p,uint64_t end,bool be){uint8_t h[12];if(end-p<12||!sxmo_read(c,p,h,12)||xx_rt_memcmp(h,"SDNANAME",8))return true;uint32_t n=sxmo32(h+8,be);if(n>65536)return true;if(!sxmo_add(c,SXMO_E(blend_dna_names),p))return false;p+=12;for(uint32_t i=0;i<n;i++)if(!sxmo_string(c,&p,end,0))return true;p=(p+3)&~UINT64_C(3);
 if(p>end||end-p<8||!sxmo_read(c,p,h,8)||xx_rt_memcmp(h,"TYPE",4))return true;n=sxmo32(h+4,be);if(n>65536)return true;if(!sxmo_add(c,SXMO_E(blend_dna_types),p))return false;p+=8;for(uint32_t i=0;i<n;i++)if(!sxmo_string(c,&p,end,0))return true;p=(p+3)&~UINT64_C(3);
 if(p>end||end-p<4+(uint64_t)n*2||!sxmo_read(c,p,h,4)||xx_rt_memcmp(h,"TLEN",4))return true;if(!sxmo_add(c,SXMO_E(blend_dna_lengths_tag),p)||!sxmo_table(c,SXMO_E(blend_dna_type_size),p+4,n))return false;p=(p+4+n*2+3)&~UINT64_C(3);
 if(p>end||end-p<8||!sxmo_read(c,p,h,8)||xx_rt_memcmp(h,"STRC",4))return true;n=sxmo32(h+4,be);if(n>4096)return true;if(!sxmo_add(c,SXMO_E(blend_dna_structures),p))return false;p+=8;for(uint32_t i=0;i<n;i++){if(p>end||end-p<4||!sxmo_read(c,p,h,4))break;unsigned fields=sxmo16(h+2,be);if((uint64_t)fields*4>end-p-4)break;if(!sxmo_add(c,SXMO_E(blend_dna_structure),p)||!sxmo_table(c,SXMO_E(blend_dna_field),p+4,fields))return false;p+=4+(uint64_t)fields*4;}return !c->failed;}
static bool sxmo_blend(sx_context*c){uint8_t h[24];if(!sxmo_read(c,0,h,12)||xx_rt_memcmp(h,"BLENDER",7)||(h[7]!='_'&&h[7]!='-')||(h[8]!='v'&&h[8]!='V')||!sxmo_add(c,&sxmo_blend_header,0))return false;unsigned ptr=h[7]=='_'?4:8,z=16+ptr;bool be=h[8]=='V';const sx_layout*l=ptr==4?SXMO_E(blend_block32):SXMO_E(blend_block64);uint64_t p=12,end=(uint64_t)c->size;
 for(unsigned i=0;i<4096&&p<end;i++){if(end-p<z||!sxmo_read(c,p,h,z))break;uint32_t n=sxmo32(h+4,be);if(n>INT32_MAX||n>end-p-z)break;if(!sxmo_add(c,l,p))return false;if(!xx_rt_memcmp(h,"DNA1",4)&&!sxmo_blend_dna(c,p+z,p+z+n,be))return false;if(!xx_rt_memcmp(h,"ENDB",4))break;p+=z+n;}return !c->failed;}
#undef SXMO_E
bool sx_blender_blend_build(sx_context*c)
{
bool ok=false;
ok=sxmo_blend(c);
return ok&&c->count>0&&sxmo_finish(c);
}
