/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Bruns, RPG Maker MV, YCG, Unreal PAK, Fallout DAT, LiveMaker GAL and Smile game packs data structures, moved out of the gameremaining schema family. */
#include "../../xx_format_schema_gameremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgr_bruns_een_header_fields[]={
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("encoded_xor_seed","uint32le",4,4,SX_NONE),
};
const sx_layout sxgr_bruns_een_header={0x607e0001U,"bruns_een_header",sxgr_bruns_een_header_fields,SX_COUNT(sxgr_bruns_een_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgr_rpgmv_header_fields[]={
 SX_FIELD("signature","uint8[8]",0,8,SX_SIGNATURE),
 SX_FIELD("version","uint8[3]",8,3,SX_NONE),
 SX_FIELD("remaining_bytes","uint8[5]",11,5,SX_NONE),
};
const sx_layout sxgr_rpgmv_header={0x607e0002U,"rpgmv_header",sxgr_rpgmv_header_fields,SX_COUNT(sxgr_rpgmv_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgr_smile_game_header_fields[]={
 SX_FIELD("signature","char[6]",0,6,SX_SIGNATURE),
 SX_FIELD("format_version","uint16be",6,2,SX_NONE),
};
const sx_layout sxgr_smile_game_header={0x607e0003U,"smile_game_header",sxgr_smile_game_header_fields,SX_COUNT(sxgr_smile_game_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgr_fallout2_footer_fields[]={
 SX_FIELD("directory_size","int32le",0,4,SX_SIZE),
 SX_FIELD("archive_size","int32le",4,4,SX_SIZE),
};
const sx_layout sxgr_fallout2_footer={0x607e0005U,"fallout2_footer",sxgr_fallout2_footer_fields,SX_COUNT(sxgr_fallout2_footer_fields),SX_LE};
static const xx_data_struct_field_desc sxgr_fallout2_directory_fields[]={
 SX_FIELD("file_count","int32le",0,4,SX_COUNT_PROP),
};
const sx_layout sxgr_fallout2_directory={0x607e0006U,"fallout2_directory",sxgr_fallout2_directory_fields,SX_COUNT(sxgr_fallout2_directory_fields),SX_LE};
static const xx_data_struct_field_desc sxgr_fallout2_name_length_fields[]={
 SX_FIELD("name_size","int32le",0,4,SX_SIZE),
};
const sx_layout sxgr_fallout2_name_length={0x607e0007U,"fallout2_name_length",sxgr_fallout2_name_length_fields,SX_COUNT(sxgr_fallout2_name_length_fields),SX_LE};
static const xx_data_struct_field_desc sxgr_game_name_length_fields[]={
 SX_FIELD("name_size","uint32le",0,4,SX_SIZE),
};
const sx_layout sxgr_game_name_length={0x607e0008U,"game_name_length",sxgr_game_name_length_fields,SX_COUNT(sxgr_game_name_length_fields),SX_LE};
static const xx_data_struct_field_desc sxgr_game_name_fields[]={
 SX_FIELD("name","uint8",0,0,SX_NONE),
};
const sx_layout sxgr_game_name={0x607e0009U,"game_name",sxgr_game_name_fields,SX_COUNT(sxgr_game_name_fields),SX_LE};
static const xx_data_struct_field_desc sxgr_unreal_pak_footer_v1_fields[]={
 SX_FIELD("signature","uint32le",0,4,SX_SIGNATURE),
 SX_FIELD("format_version","uint32le",4,4,SX_NONE),
 SX_FIELD("index_offset","uint64le",8,8,SX_OFFSET),
 SX_FIELD("index_size","uint64le",16,8,SX_SIZE),
 SX_FIELD("index_sha1","uint8[20]",24,20,SX_CHECKSUM),
};
const sx_layout sxgr_unreal_pak_footer_v1={0x607e000bU,"unreal_pak_footer_v1",sxgr_unreal_pak_footer_v1_fields,SX_COUNT(sxgr_unreal_pak_footer_v1_fields),SX_LE};
static const xx_data_struct_field_desc sxgr_unreal_pak_footer_v4_fields[]={
 SX_FIELD("encrypted_index","uint8",0,1,SX_FLAGS),
 SX_FIELD("signature","uint32le",1,4,SX_SIGNATURE),
 SX_FIELD("format_version","uint32le",5,4,SX_NONE),
 SX_FIELD("index_offset","uint64le",9,8,SX_OFFSET),
 SX_FIELD("index_size","uint64le",17,8,SX_SIZE),
 SX_FIELD("index_sha1","uint8[20]",25,20,SX_CHECKSUM),
};
const sx_layout sxgr_unreal_pak_footer_v4={0x607e000cU,"unreal_pak_footer_v4",sxgr_unreal_pak_footer_v4_fields,SX_COUNT(sxgr_unreal_pak_footer_v4_fields),SX_LE};
static const xx_data_struct_field_desc sxgr_unreal_pak_footer_v7_fields[]={
 SX_FIELD("encryption_key_guid","uint8[16]",0,16,SX_ID),
 SX_FIELD("encrypted_index","uint8",16,1,SX_FLAGS),
 SX_FIELD("signature","uint32le",17,4,SX_SIGNATURE),
 SX_FIELD("format_version","uint32le",21,4,SX_NONE),
 SX_FIELD("index_offset","uint64le",25,8,SX_OFFSET),
 SX_FIELD("index_size","uint64le",33,8,SX_SIZE),
 SX_FIELD("index_sha1","uint8[20]",41,20,SX_CHECKSUM),
};
const sx_layout sxgr_unreal_pak_footer_v7={0x607e000dU,"unreal_pak_footer_v7",sxgr_unreal_pak_footer_v7_fields,SX_COUNT(sxgr_unreal_pak_footer_v7_fields),SX_LE};
static const xx_data_struct_field_desc sxgr_unreal_pak_string_length_fields[]={
 SX_FIELD("signed_character_count","int32le",0,4,SX_COUNT_PROP),
};
const sx_layout sxgr_unreal_pak_string_length={0x607e000eU,"unreal_pak_string_length",sxgr_unreal_pak_string_length_fields,SX_COUNT(sxgr_unreal_pak_string_length_fields),SX_LE};
static const xx_data_struct_field_desc sxgr_unreal_pak_string_fields[]={
 SX_FIELD("string_bytes","uint8",0,0,SX_NONE),
};
const sx_layout sxgr_unreal_pak_string={0x607e000fU,"unreal_pak_string",sxgr_unreal_pak_string_fields,SX_COUNT(sxgr_unreal_pak_string_fields),SX_LE};
static const xx_data_struct_field_desc sxgr_unreal_pak_directory_count_fields[]={
 SX_FIELD("entry_count","uint32le",0,4,SX_COUNT_PROP),
};
const sx_layout sxgr_unreal_pak_directory_count={0x607e0010U,"unreal_pak_directory_count",sxgr_unreal_pak_directory_count_fields,SX_COUNT(sxgr_unreal_pak_directory_count_fields),SX_LE};
static const xx_data_struct_field_desc sxgr_unreal_pak_block_count_fields[]={
 SX_FIELD("block_count","uint32le",0,4,SX_COUNT_PROP),
};
const sx_layout sxgr_unreal_pak_block_count={0x607e0013U,"unreal_pak_block_count",sxgr_unreal_pak_block_count_fields,SX_COUNT(sxgr_unreal_pak_block_count_fields),SX_LE};
static const xx_data_struct_field_desc sxgr_unreal_pak_block_fields[]={
 SX_FIELD("start_offset","uint64le",0,8,SX_OFFSET),
 SX_FIELD("end_offset","uint64le",8,8,SX_OFFSET),
};
const sx_layout sxgr_unreal_pak_block={0x607e0014U,"unreal_pak_block",sxgr_unreal_pak_block_fields,SX_COUNT(sxgr_unreal_pak_block_fields),SX_LE};
static const xx_data_struct_field_desc sxgr_gal_envelope_fields[]={
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("ascii_version","ascii_decimal[3]",4,3,SX_NONE),
 SX_FIELD("header_size","int32le",7,4,SX_SIZE),
};
const sx_layout sxgr_gal_envelope={0x607e0016U,"gal_envelope",sxgr_gal_envelope_fields,SX_COUNT(sxgr_gal_envelope_fields),SX_LE};
static const xx_data_struct_field_desc sxgr_gal_frame_fields[]={
 SX_FIELD("mask","uint32le",0,4,SX_FLAGS),
 SX_FIELD("unknown_04","uint8[9]",4,9,SX_NONE),
 SX_FIELD("layer_count","int32le",13,4,SX_COUNT_PROP),
 SX_FIELD("width","int32le",17,4,SX_NONE),
 SX_FIELD("height","int32le",21,4,SX_NONE),
 SX_FIELD("bits_per_pixel","int32le",25,4,SX_NONE),
};
const sx_layout sxgr_gal_frame={0x607e0018U,"gal_frame",sxgr_gal_frame_fields,SX_COUNT(sxgr_gal_frame_fields),SX_LE};
static const xx_data_struct_field_desc sxgr_gal_palette_entry_fields[]={
 SX_FIELD("blue","uint8",0,1,SX_NONE),
 SX_FIELD("green","uint8",1,1,SX_NONE),
 SX_FIELD("red","uint8",2,1,SX_NONE),
 SX_FIELD("fourth_component","uint8",3,1,SX_NONE),
};
const sx_layout sxgr_gal_palette_entry={0x607e0019U,"gal_palette_entry",sxgr_gal_palette_entry_fields,SX_COUNT(sxgr_gal_palette_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgr_gal_layer_fields[]={
 SX_FIELD("left","int32le",0,4,SX_NONE),
 SX_FIELD("top","int32le",4,4,SX_NONE),
 SX_FIELD("visible","uint8",8,1,SX_FLAGS),
 SX_FIELD("transparent_color","int32le",9,4,SX_NONE),
 SX_FIELD("alpha","int32le",13,4,SX_NONE),
 SX_FIELD("alpha_enabled","uint8",17,1,SX_FLAGS),
 SX_FIELD("name_size","uint32le",18,4,SX_SIZE),
};
const sx_layout sxgr_gal_layer={0x607e001aU,"gal_layer",sxgr_gal_layer_fields,SX_COUNT(sxgr_gal_layer_fields),SX_LE};
static const xx_data_struct_field_desc sxgr_gal_layer_lock_fields[]={
 SX_FIELD("locked","uint8",0,1,SX_FLAGS),
};
const sx_layout sxgr_gal_layer_lock={0x607e001bU,"gal_layer_lock",sxgr_gal_layer_lock_fields,SX_COUNT(sxgr_gal_layer_lock_fields),SX_LE};
static const xx_data_struct_field_desc sxgr_gal_layer_size_fields[]={
 SX_FIELD("layer_size","int32le",0,4,SX_SIZE),
};
const sx_layout sxgr_gal_layer_size={0x607e001cU,"gal_layer_size",sxgr_gal_layer_size_fields,SX_COUNT(sxgr_gal_layer_size_fields),SX_LE};
static const xx_data_struct_field_desc sxgr_gal_alpha_size_fields[]={
 SX_FIELD("alpha_size","int32le",0,4,SX_SIZE),
};
const sx_layout sxgr_gal_alpha_size={0x607e001dU,"gal_alpha_size",sxgr_gal_alpha_size_fields,SX_COUNT(sxgr_gal_alpha_size_fields),SX_LE};
/* Physical metadata uses bounded reads; compressed and unknown blocks stay raw. */
typedef struct sxgr_view {sx_context*c;uint64_t work;} sxgr_view;
static bool sxgr_span(sxgr_view*v,uint64_t at,uint64_t z,uint64_t end)
{return !xx_pd_is_stopped(v->c->pd)&&end<=(uint64_t)v->c->size&&at<=end&&z<=end-at;}
static bool sxgr_read(sxgr_view*v,uint64_t at,void*b,size_t z,uint64_t end)
{return ++v->work<=4000000&&sxgr_span(v,at,z,end)&&sx_read(v->c,(int64_t)at,b,z);}
static bool sxgr_u(sxgr_view*v,uint64_t at,unsigned z,uint64_t*out,uint64_t end)
{uint8_t b[8];if(!z||z>8||!sxgr_read(v,at,b,z,end))return false;*out=0;for(unsigned i=0;i<z;i++)*out|=(uint64_t)b[i]<<(8*i);return true;}
static bool sxgr_eq(sxgr_view*v,uint64_t at,const char*s,size_t z,uint64_t end)
{uint8_t b[64];return z<=sizeof(b)&&sxgr_read(v,at,b,z,end)&&!xx_rt_memcmp(b,s,z);}
static bool sxgr_emit(sxgr_view*v,const sx_layout*l,uint64_t at,uint64_t z,uint64_t end)
{if(!sxgr_span(v,at,z,end))return false;if(!z||v->c->count>=24000)return true;if(!l->fields[0].size&&z>(uint64_t)sx_variable_field_limit(l->fields[0].type))return true;return sx_add(v->c,l,(int64_t)at,(int64_t)z);}
static bool sxgr_row(sxgr_view*v,const sx_layout*l,uint64_t at,uint64_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;return sxgr_emit(v,l,at,(uint64_t)(f->rel_offset+f->size),end);}
static bool sxgr_table(sxgr_view*v,const sx_layout*l,uint64_t at,uint64_t n,uint64_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(!z||n>4000000||n>UINT64_MAX/z||!sxgr_span(v,at,n*z,end))return false;for(uint64_t i=0;i<n&&v->c->count<24000;i++,at+=z)if(!sxgr_row(v,l,at,end))return false;return true;}
static int sxgr_order(const void*aa,const void*bb)
{const xx_data_struct*a=aa,*b=bb;if(a->offset!=b->offset)return a->offset<b->offset?-1:1;return a->total_size<b->total_size?-1:a->total_size>b->total_size?1:0;}
static bool sxgr_finish(sx_context*c)
{size_t n=c->count,k=0;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxgr_order);for(size_t i=0;i<n;i++){int64_t a=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(a<end)continue;c->items[k++]=c->items[i];end=a+z;}c->count=k;n=k;end=0;for(size_t i=0;i<n;i++){int64_t a=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(a>end&&!sx_raw(c,end,a-end))return false;end=a+z;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxgr_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
#define GR_ROW(name,at,end) sxgr_row(v,&sxgr_##name,(at),(end))
/* All positions below are physical offsets in the original input. */
static bool sxgr_name(sxgr_view*v,uint64_t*p,uint64_t end)
{uint64_t n;if(!sxgr_u(v,*p,4,&n,end)||!GR_ROW(game_name_length,*p,end))return false;*p+=4;if(!sxgr_span(v,*p,n,end)||!sxgr_emit(v,&sxgr_game_name,*p,n,end))return false;*p+=n;return true;}
static bool sxgr_fallout(sxgr_view*v)
{uint64_t end=v->c->size,tree,count;if(end<12||!sxgr_u(v,end-8,4,&tree,end)||tree>end-8||tree<4||!GR_ROW(fallout2_footer,end-8,end))return false;uint64_t p=end-8-tree,stop=end-8;if(!sxgr_u(v,p,4,&count,stop)||count>65536||!GR_ROW(fallout2_directory,p,stop))return false;p+=4;for(uint64_t i=0;i<count&&v->c->count<24000;i++){uint64_t name;if(!sxgr_u(v,p,4,&name,stop)||name>INT32_MAX||!GR_ROW(fallout2_name_length,p,stop))return false;p+=4;if(!sxgr_emit(v,&sxgr_game_name,p,name,stop))return false;p+=name;if(!GR_ROW(fallout2_entry,p,stop))return false;p+=13;}return true;}
static bool sxgr_pak_string(sxgr_view*v,uint64_t*p,uint64_t end)
{uint64_t raw;if(!sxgr_u(v,*p,4,&raw,end)||!GR_ROW(unreal_pak_string_length,*p,end))return false;int32_t n=(int32_t)(uint32_t)raw;if(!n||n==INT32_MIN||n>4097||n< -4097)return false;uint64_t bytes=n<0?(uint64_t)(-(int64_t)n)*2:(uint64_t)n;*p+=4;if(!sxgr_span(v,*p,bytes,end)||!sxgr_emit(v,&sxgr_unreal_pak_string,*p,bytes,end))return false;*p+=bytes;return true;}
static bool sxgr_pak_entry(sxgr_view*v,uint64_t*p,uint64_t end,unsigned version,bool local)
{uint64_t start=*p,offset,method,count=0;if(!sxgr_u(v,start,8,&offset,end)||!sxgr_u(v,start+24,4,&method,end)||!sxgr_row(v,version==1?&sxgr_unreal_pak_entry_v1:&sxgr_unreal_pak_entry_v2,start,end))return false;*p+=version==1?56:48;if(version>=3){if(method){if(!sxgr_u(v,*p,4,&count,end)||count>65536||!GR_ROW(unreal_pak_block_count,*p,end))return false;*p+=4;if(!sxgr_table(v,&sxgr_unreal_pak_block,*p,count,end))return false;*p+=count*16;}if(!GR_ROW(unreal_pak_entry_flags,*p,end))return false;*p+=5;}
 if(local){uint64_t q=offset,z=*p-start;if(!sxgr_span(v,offset,z,end)||!sxgr_pak_entry(v,&q,offset+z,version,false))return false;}return true;}
static bool sxgr_pak(sxgr_view*v)
{uint64_t n=v->c->size,footer=0,index=0,size=0,version=0;unsigned candidates[]={44,45,61};for(unsigned i=0;i<3;i++){uint64_t magic,ver,at;unsigned z=candidates[i],pre=z-44;if(n<z)continue;at=n-z;if(!sxgr_u(v,at+pre,4,&magic,n)||!sxgr_u(v,at+pre+4,4,&ver,n))return false;if(magic!=0x5a6f12e1U||ver<1||ver>7||z!=(ver>=7?61U:ver>=4?45U:44U))continue;footer=at;version=ver;if(!sxgr_u(v,at+pre+8,8,&index,n)||!sxgr_u(v,at+pre+16,8,&size,n)||!sxgr_row(v,ver>=7?&sxgr_unreal_pak_footer_v7:ver>=4?&sxgr_unreal_pak_footer_v4:&sxgr_unreal_pak_footer_v1,at,n))return false;break;}
 if(!version||!sxgr_span(v,index,size,footer))return false;uint64_t p=index,end=index+size,count;if(!sxgr_pak_string(v,&p,end)||!sxgr_u(v,p,4,&count,end)||count>65536||!GR_ROW(unreal_pak_directory_count,p,end))return false;p+=4;for(uint64_t i=0;i<count&&v->c->count<24000;i++)if(!sxgr_pak_string(v,&p,end)||!sxgr_pak_entry(v,&p,end,(unsigned)version,true))return false;return true;}
static bool sxgr_gal(sxgr_view*v)
{uint64_t end=v->c->size,header,version,frames,compression;if(!sxgr_u(v,7,4,&header,end)||header<40||header>256||!sxgr_u(v,11,4,&version,end)||version<103||version>107||!sxgr_u(v,27,4,&frames,end)||frames>1024||!sxgr_u(v,33,1,&compression,end)||compression>1||!GR_ROW(gal_envelope,0,end)||!GR_ROW(gal_header,11,end)||!sxgr_span(v,11,header,end))return false;uint64_t p=11+header;
 for(uint64_t i=0;i<frames&&v->c->count<24000;i++){uint64_t layers,bpp;if(!sxgr_name(v,&p,end)||!sxgr_u(v,p+13,4,&layers,end)||!sxgr_u(v,p+25,4,&bpp,end)||layers>1024||!GR_ROW(gal_frame,p,end))return false;p+=29;if(bpp<=8){if(bpp!=4&&bpp!=8)return false;uint64_t colors=UINT64_C(1)<<bpp;if(!sxgr_table(v,&sxgr_gal_palette_entry,p,colors,end))return false;p+=colors*4;}
  for(uint64_t j=0;j<layers&&v->c->count<24000;j++){uint64_t name,packed,alpha;if(!sxgr_u(v,p+18,4,&name,end)||!GR_ROW(gal_layer,p,end))return false;p+=22;if(!sxgr_span(v,p,name,end)||!sxgr_emit(v,&sxgr_game_name,p,name,end))return false;p+=name;if(version>=107){if(!GR_ROW(gal_layer_lock,p,end))return false;p++;}if(!sxgr_u(v,p,4,&packed,end)||!GR_ROW(gal_layer_size,p,end))return false;p+=4;if(!sxgr_span(v,p,packed,end))return false;p+=packed;if(!sxgr_u(v,p,4,&alpha,end)||!GR_ROW(gal_alpha_size,p,end))return false;p+=4;if(!sxgr_span(v,p,alpha,end))return false;p+=alpha;}
 }return true;}
bool sx_ue2_games_build(sx_context*c)
{
 sxgr_view view={c,0},*v=&view;bool ok=false;switch(c->f->file_type){case XX_FILE_TYPE_BRUNS_MEDIA:ok=((sxgr_eq(v,0,"EENC",4,c->size)||sxgr_eq(v,0,"EENZ",4,c->size))&&GR_ROW(bruns_een_header,0,c->size));break;case XX_FILE_TYPE_RPG_MAKER_MV:ok=GR_ROW(rpgmv_header,0,c->size);break;case XX_FILE_TYPE_YCG_IMAGE:ok=GR_ROW(ycg_header,0,c->size);break;case XX_FILE_TYPE_UNREAL_PAK:ok=sxgr_pak(v);break;case XX_FILE_TYPE_FALLOUT_DAT:ok=sxgr_fallout(v);break;case XX_FILE_TYPE_LIVE_MAKER_GAL:ok=sxgr_gal(v);break;case XX_FILE_TYPE_SMILE_GAME_PACK:ok=GR_ROW(smile_game_header,0,c->size);break;default:break;}return ok&&sxgr_finish(c);
}
#undef GR_ROW
