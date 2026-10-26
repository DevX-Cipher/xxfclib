/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * xna_xnb data structures, moved out of the gameplatforms schema family. */
#include "../../xx_format_schema_gameplatforms.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgp_xnb_header_fields[]={
 SX_FIELD("signature","bytes",0,3,SX_SIGNATURE),
 SX_FIELD("target_platform","uint8",3,1,SX_ID),
 SX_FIELD("version","uint8",4,1,SX_ID),
 SX_FIELD("flags","uint8",5,1,SX_FLAGS),
 SX_FIELD("file_size","uint32",6,4,SX_SIZE),
};
const sx_layout sxgp_xnb_header={UINT32_C(0x60360019),"xnb_header",sxgp_xnb_header_fields,SX_COUNT(sxgp_xnb_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_xnb_count_fields[]={
 SX_FIELD("count","uleb128_64",0,1,SX_COUNT_PROP),
};
const sx_layout sxgp_xnb_count={UINT32_C(0x6036001A),"xnb_count",sxgp_xnb_count_fields,SX_COUNT(sxgp_xnb_count_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_xnb_reader_id_fields[]={
 SX_FIELD("reader_id","uleb128_64",0,1,SX_ID),
};
const sx_layout sxgp_xnb_reader_id={UINT32_C(0x6036001B),"xnb_reader_id",sxgp_xnb_reader_id_fields,SX_COUNT(sxgp_xnb_reader_id_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_xnb_length_1_fields[]={
 SX_FIELD("byte_size","uleb128_64",0,1,SX_SIZE),
};
const sx_layout sxgp_xnb_length_1={UINT32_C(0x6036001C),"xnb_length_1",sxgp_xnb_length_1_fields,SX_COUNT(sxgp_xnb_length_1_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_xnb_length_2_fields[]={
 SX_FIELD("byte_size","uleb128_64",0,2,SX_SIZE),
};
const sx_layout sxgp_xnb_length_2={UINT32_C(0x6036001D),"xnb_length_2",sxgp_xnb_length_2_fields,SX_COUNT(sxgp_xnb_length_2_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_xnb_length_3_fields[]={
 SX_FIELD("byte_size","uleb128_64",0,3,SX_SIZE),
};
const sx_layout sxgp_xnb_length_3={UINT32_C(0x6036001E),"xnb_length_3",sxgp_xnb_length_3_fields,SX_COUNT(sxgp_xnb_length_3_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_xnb_length_4_fields[]={
 SX_FIELD("byte_size","uleb128_64",0,4,SX_SIZE),
};
const sx_layout sxgp_xnb_length_4={UINT32_C(0x6036001F),"xnb_length_4",sxgp_xnb_length_4_fields,SX_COUNT(sxgp_xnb_length_4_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_xnb_reader_version_fields[]={
 SX_FIELD("reader_version","int32",0,4,SX_ID),
};
const sx_layout sxgp_xnb_reader_version={UINT32_C(0x60360020),"xnb_reader_version",sxgp_xnb_reader_version_fields,SX_COUNT(sxgp_xnb_reader_version_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_xnb_texture_fields[]={
 SX_FIELD("surface_format","int32",0,4,SX_ID),
 SX_FIELD("width","int32",4,4,SX_COUNT_PROP),
 SX_FIELD("height","int32",8,4,SX_COUNT_PROP),
 SX_FIELD("mip_count","int32",12,4,SX_COUNT_PROP),
};
const sx_layout sxgp_xnb_texture={UINT32_C(0x60360021),"xnb_texture",sxgp_xnb_texture_fields,SX_COUNT(sxgp_xnb_texture_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_xnb_mip_fields[]={
 SX_FIELD("data_size","int32",0,4,SX_SIZE),
};
const sx_layout sxgp_xnb_mip={UINT32_C(0x60360022),"xnb_mip",sxgp_xnb_mip_fields,SX_COUNT(sxgp_xnb_mip_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_xnb_int32_fields[]={
 SX_FIELD("value","int32",0,4,SX_NONE),
};
const sx_layout sxgp_xnb_int32={UINT32_C(0x60360023),"xnb_int32",sxgp_xnb_int32_fields,SX_COUNT(sxgp_xnb_int32_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_xnb_float32_fields[]={
 SX_FIELD("value","float",0,4,SX_NONE),
};
const sx_layout sxgp_xnb_float32={UINT32_C(0x60360024),"xnb_float32",sxgp_xnb_float32_fields,SX_COUNT(sxgp_xnb_float32_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_xnb_byte_fields[]={
 SX_FIELD("value","uint8",0,1,SX_NONE),
};
const sx_layout sxgp_xnb_byte={UINT32_C(0x60360025),"xnb_byte",sxgp_xnb_byte_fields,SX_COUNT(sxgp_xnb_byte_fields),SX_LE};
#define SG_ROW(l,at,end) sxgp_row(v,&sxgp_##l,(at),(end))
static bool sxgp_xnb_var(sxgp_view*v,uint64_t*p,uint64_t end,unsigned kind,uint64_t*out)
{uint64_t a=*p,x=0,ch;unsigned n=0;do{if(n==5||!sxgp_word(v,*p,1,false,&ch,end))return false;(*p)++;if(n==4&&(ch&248))return false;x|=(ch&127)<<(7*n++);}while(ch&128);if(n>1&&!ch)return false;
 const sx_layout*ls[]={&sxgp_xnb_length_1,&sxgp_xnb_length_2,&sxgp_xnb_length_3,&sxgp_xnb_length_4};if((kind&&n!=1)||(!kind&&n>4)||!sxgp_row(v,kind==1?&sxgp_xnb_count:kind==2?&sxgp_xnb_reader_id:ls[n-1],a,end))return false;*out=x;return true;}
static bool sxgp_xnb(sxgp_view*v)
{uint64_t end=(uint64_t)v->c->size,p=10,z,mips;char name[1025];if(!SG_ROW(xnb_header,0,end)||!sxgp_word(v,6,4,false,&end,end)||!sxgp_xnb_var(v,&p,end,1,&z)||z!=1||!sxgp_xnb_var(v,&p,end,0,&z)||z>1024||!sxgp_read(v,p,name,(size_t)z,end))return false;name[z]=0;p+=z;
 if(!SG_ROW(xnb_reader_version,p,end))return false;p+=4;if(!sxgp_xnb_var(v,&p,end,1,&z)||z||!sxgp_xnb_var(v,&p,end,2,&z)||z!=1)return false;
 if(!xx_rt_strncmp(name,"Microsoft.Xna.Framework.Content.Texture2DReader",46)){if(!SG_ROW(xnb_texture,p,end)||!sxgp_word(v,p+12,4,false,&mips,end)||mips>16)return false;p+=16;for(uint64_t i=0;i<mips;i++){if(!SG_ROW(xnb_mip,p,end)||!sxgp_word(v,p,4,false,&z,end)||!sxgp_span(v,p+4,z,end))return false;p+=4+z;}}
 else if(!xx_rt_strncmp(name,"Microsoft.Xna.Framework.Content.StringReader",43)){if(!sxgp_xnb_var(v,&p,end,0,&z)||!sxgp_span(v,p,z,end))return false;p+=z;}
 else if(!xx_rt_strncmp(name,"Microsoft.Xna.Framework.Content.ByteReader",41)){if(!SG_ROW(xnb_byte,p,end))return false;p++;}
 else if(!xx_rt_strncmp(name,"Microsoft.Xna.Framework.Content.Int32Reader",42)){if(!SG_ROW(xnb_int32,p,end))return false;p+=4;}
 else if(!xx_rt_strncmp(name,"Microsoft.Xna.Framework.Content.SingleReader",43)){if(!SG_ROW(xnb_float32,p,end))return false;p+=4;}else return false;
 return p==end;}
bool sx_xna_xnb_build(sxgp_view*v)
{
 return sxgp_xnb(v);
}
#undef SG_ROW
