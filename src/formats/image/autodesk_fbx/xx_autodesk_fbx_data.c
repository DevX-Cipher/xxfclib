/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * AUTODESK_FBX data structures, moved out of the modelmeta schema family. */
#include "../../xx_format_schema_modelmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmo_fbx_header_fields[] = {
    SX_FIELD("signature","char[23]",0,23,SX_SIGNATURE),
    SX_FIELD("version","uint32",23,4,SX_ID),
};
const sx_layout sxmo_fbx_header = {UINT32_C(0x6021003b),"fbx_header",sxmo_fbx_header_fields,SX_COUNT(sxmo_fbx_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_fbx_node32_fields[] = {
    SX_FIELD("end_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("property_count","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("property_list_size","uint32",8,4,SX_SIZE),
    SX_FIELD("name_size","uint8",12,1,SX_SIZE),
};
const sx_layout sxmo_fbx_node32 = {UINT32_C(0x6021003c),"fbx_node32",sxmo_fbx_node32_fields,SX_COUNT(sxmo_fbx_node32_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_fbx_node64_fields[] = {
    SX_FIELD("end_offset","uint64",0,8,SX_OFFSET),
    SX_FIELD("property_count","uint64",8,8,SX_COUNT_PROP),
    SX_FIELD("property_list_size","uint64",16,8,SX_SIZE),
    SX_FIELD("name_size","uint8",24,1,SX_SIZE),
};
const sx_layout sxmo_fbx_node64 = {UINT32_C(0x6021003d),"fbx_node64",sxmo_fbx_node64_fields,SX_COUNT(sxmo_fbx_node64_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_fbx_scalar_y_fields[] = {
    SX_FIELD("type","char[1]",0,1,SX_ID),
    SX_FIELD("value","int16",1,2,SX_NONE),
};
const sx_layout sxmo_fbx_scalar_y = {UINT32_C(0x6021003e),"fbx_scalar_y",sxmo_fbx_scalar_y_fields,SX_COUNT(sxmo_fbx_scalar_y_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_fbx_scalar_c_fields[] = {
    SX_FIELD("type","char[1]",0,1,SX_ID),
    SX_FIELD("value","uint8",1,1,SX_NONE),
};
const sx_layout sxmo_fbx_scalar_c = {UINT32_C(0x6021003f),"fbx_scalar_c",sxmo_fbx_scalar_c_fields,SX_COUNT(sxmo_fbx_scalar_c_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_fbx_scalar_i_fields[] = {
    SX_FIELD("type","char[1]",0,1,SX_ID),
    SX_FIELD("value","int32",1,4,SX_NONE),
};
const sx_layout sxmo_fbx_scalar_i = {UINT32_C(0x60210040),"fbx_scalar_i",sxmo_fbx_scalar_i_fields,SX_COUNT(sxmo_fbx_scalar_i_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_fbx_scalar_f_fields[] = {
    SX_FIELD("type","char[1]",0,1,SX_ID),
    SX_FIELD("value","float32",1,4,SX_NONE),
};
const sx_layout sxmo_fbx_scalar_f = {UINT32_C(0x60210041),"fbx_scalar_f",sxmo_fbx_scalar_f_fields,SX_COUNT(sxmo_fbx_scalar_f_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_fbx_scalar_l_fields[] = {
    SX_FIELD("type","char[1]",0,1,SX_ID),
    SX_FIELD("value","int64",1,8,SX_NONE),
};
const sx_layout sxmo_fbx_scalar_l = {UINT32_C(0x60210042),"fbx_scalar_l",sxmo_fbx_scalar_l_fields,SX_COUNT(sxmo_fbx_scalar_l_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_fbx_scalar_d_fields[] = {
    SX_FIELD("type","char[1]",0,1,SX_ID),
    SX_FIELD("value","float64",1,8,SX_NONE),
};
const sx_layout sxmo_fbx_scalar_d = {UINT32_C(0x60210043),"fbx_scalar_d",sxmo_fbx_scalar_d_fields,SX_COUNT(sxmo_fbx_scalar_d_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_fbx_blob_fields[] = {
    SX_FIELD("type","char[1]",0,1,SX_ID),
    SX_FIELD("data_size","uint32",1,4,SX_SIZE),
};
const sx_layout sxmo_fbx_blob = {UINT32_C(0x60210044),"fbx_blob",sxmo_fbx_blob_fields,SX_COUNT(sxmo_fbx_blob_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_fbx_array_fields[] = {
    SX_FIELD("type","char[1]",0,1,SX_ID),
    SX_FIELD("element_count","uint32",1,4,SX_COUNT_PROP),
    SX_FIELD("encoding","uint32",5,4,SX_ID),
    SX_FIELD("stored_size","uint32",9,4,SX_SIZE),
};
const sx_layout sxmo_fbx_array = {UINT32_C(0x60210045),"fbx_array",sxmo_fbx_array_fields,SX_COUNT(sxmo_fbx_array_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_fbx_footer_prefix_fields[] = {
    SX_FIELD("identifier","uint8[16]",0,16,SX_NONE),
    SX_FIELD("reserved","uint32",16,4,SX_RESERVED),
};
const sx_layout sxmo_fbx_footer_prefix = {UINT32_C(0x60210046),"fbx_footer_prefix",sxmo_fbx_footer_prefix_fields,SX_COUNT(sxmo_fbx_footer_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_fbx_footer_tail_fields[] = {
    SX_FIELD("version","uint32",0,4,SX_ID),
    SX_FIELD("reserved","uint8[120]",4,120,SX_RESERVED),
    SX_FIELD("signature","uint8[16]",124,16,SX_SIGNATURE),
};
const sx_layout sxmo_fbx_footer_tail = {UINT32_C(0x60210047),"fbx_footer_tail",sxmo_fbx_footer_tail_fields,SX_COUNT(sxmo_fbx_footer_tail_fields),SX_LE};
static bool sxmo_fbx_properties(sx_context*c,uint64_t p,uint64_t end,uint64_t count){for(uint64_t i=0;i<count&&i<16000;i++){uint8_t h[13];if(p>=end||!sxmo_read(c,p,h,1))break;const sx_layout*l=NULL;unsigned z=0;switch(h[0]){case'Y':l=&sxmo_fbx_scalar_y;z=3;break;case'C':l=&sxmo_fbx_scalar_c;z=2;break;case'I':l=&sxmo_fbx_scalar_i;z=5;break;case'F':l=&sxmo_fbx_scalar_f;z=5;break;case'L':l=&sxmo_fbx_scalar_l;z=9;break;case'D':l=&sxmo_fbx_scalar_d;z=9;break;default:break;}if(l){if(z>end-p)break;if(!sxmo_add(c,l,p))return false;p+=z;continue;}
 if(h[0]=='S'||h[0]=='R'){if(end-p<5||!sxmo_read(c,p,h,5))break;uint64_t n=sxmo32(h+1,false);if(n>end-p-5)break;if(!sxmo_add(c,&sxmo_fbx_blob,p))return false;p+=5+n;}
 else if(h[0]=='f'||h[0]=='d'||h[0]=='l'||h[0]=='i'||h[0]=='b'||h[0]=='c'){if(end-p<13||!sxmo_read(c,p,h,13))break;uint64_t n=sxmo32(h+9,false);if(n>end-p-13)break;if(!sxmo_add(c,&sxmo_fbx_array,p))return false;p+=13+n;}else break;}return !c->failed;}
static bool sxmo_fbx_nodes(sx_context*c,uint64_t*p,uint64_t end,unsigned width,unsigned depth,unsigned*budget){unsigned z=width*3+1;while(*p<end&&depth<32&&*budget<16000){(*budget)++;uint8_t h[25];if(end-*p<z||!sxmo_read(c,*p,h,z))break;uint64_t stop=sxmo_uint(h,width,false),count=sxmo_uint(h+width,width,false),props=sxmo_uint(h+2*width,width,false),name=h[z-1];if(!stop&&!count&&!props&&!name){if(!sxmo_add(c,width==4?&sxmo_fbx_node32:&sxmo_fbx_node64,*p))return false;*p+=z;break;}if(stop<=*p||stop>end||stop-*p<z+name||props>stop-*p-z-name)break;if(!sxmo_add(c,width==4?&sxmo_fbx_node32:&sxmo_fbx_node64,*p))return false;uint64_t q=*p+z+name;if(!sxmo_fbx_properties(c,q,q+props,count))return false;q+=props;if(q<stop&&!sxmo_fbx_nodes(c,&q,stop,width,depth+1,budget))return false;*p=stop;}return !c->failed;}
static bool sxmo_fbx(sx_context*c){uint8_t h[27];if(!sxmo_read(c,0,h,27)||xx_rt_memcmp(h,"Kaydara FBX Binary  \0\x1a\0",23)||!sxmo_add(c,&sxmo_fbx_header,0))return false;unsigned width=sxmo32(h+23,false)>=7500?8:4,budget=0;uint64_t p=27,end=(uint64_t)c->size;if(!sxmo_fbx_nodes(c,&p,end,width,0,&budget))return false;if(p<end&&end-p>=20){if(!sxmo_add(c,&sxmo_fbx_footer_prefix,p))return false;p+=20;p+=16-(p&15);if(p<=end&&end-p>=140&&!sxmo_add(c,&sxmo_fbx_footer_tail,p))return false;}return !c->failed;}
bool sx_autodesk_fbx_build(sx_context*c)
{
bool ok=false;
ok=sxmo_fbx(c);
return ok&&c->count>0&&sxmo_finish(c);
}
