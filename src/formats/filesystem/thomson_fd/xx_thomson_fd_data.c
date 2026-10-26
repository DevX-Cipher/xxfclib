/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Thomson FD (BASIC-DOS) data structures, moved out of the vintagefilesystems schema family. */
#include "../../xx_format_schema_vintagefilesystems.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxvintage_thomson_volume_header_fields[]={
 SX_FIELD("volume_name","char[8]",0,8,SX_NONE),
 SX_FIELD("unknown_volume_bytes","uint8[248]",8,248,SX_NONE),
};
const sx_layout sxvintage_thomson_volume_header={0x609d0001U,"thomson_volume_header",sxvintage_thomson_volume_header_fields,SX_COUNT(sxvintage_thomson_volume_header_fields),SX_BE};
static const xx_data_struct_field_desc sxvintage_thomson_fat_prefix_fields[]={
 SX_FIELD("reserved_zero","uint8",0,1,SX_NONE),
};
const sx_layout sxvintage_thomson_fat_prefix={0x609d0002U,"thomson_fat_prefix",sxvintage_thomson_fat_prefix_fields,SX_COUNT(sxvintage_thomson_fat_prefix_fields),SX_BE};
static const xx_data_struct_field_desc sxvintage_thomson_fat_entry_fields[]={
 SX_FIELD("allocation_value","uint8",0,1,SX_NONE),
};
const sx_layout sxvintage_thomson_fat_entry={0x609d0003U,"thomson_fat_entry",sxvintage_thomson_fat_entry_fields,SX_COUNT(sxvintage_thomson_fat_entry_fields),SX_BE};
static const xx_data_struct_field_desc sxvintage_thomson_directory_entry_fields[]={
 SX_FIELD("filename","char[8]",0,8,SX_NONE),
 SX_FIELD("extension","char[3]",8,3,SX_NONE),
 SX_FIELD("file_type","uint8",11,1,SX_ID),
 SX_FIELD("format_flag","uint8",12,1,SX_FLAGS),
 SX_FIELD("first_block","uint8",13,1,SX_ID),
 SX_FIELD("last_sector_bytes","uint16",14,2,SX_SIZE),
 SX_FIELD("comment","char[8]",16,8,SX_NONE),
 SX_FIELD("day","uint8",24,1,SX_NONE),
 SX_FIELD("month","uint8",25,1,SX_NONE),
 SX_FIELD("year","uint8",26,1,SX_NONE),
 SX_FIELD("unknown_tail","uint8[5]",27,5,SX_NONE),
};
const sx_layout sxvintage_thomson_directory_entry={0x609d0004U,"thomson_directory_entry",sxvintage_thomson_directory_entry_fields,SX_COUNT(sxvintage_thomson_directory_entry_fields),SX_BE};
static const xx_data_struct_field_desc sxvintage_thomson_directory_state_fields[]={
 SX_FIELD("entry_state","uint8",0,1,SX_NONE),
};
const sx_layout sxvintage_thomson_directory_state={0x609d0005U,"thomson_directory_state",sxvintage_thomson_directory_state_fields,SX_COUNT(sxvintage_thomson_directory_state_fields),SX_BE};
static bool sxvintage_span(sx_context*c,uint64_t at,uint64_t size)
{return c&&c->size>=0&&at<=(uint64_t)c->size&&size<=(uint64_t)c->size-at&&!xx_pd_is_stopped(c->pd);}
static bool sxvintage_thomson_side(sx_context*c,uint64_t origin,bool*accepted)
{
 uint8_t volume[256],fat[256],directory[3584];uint64_t at=origin+20*4096;unsigned blocks=80,entries=0;
 *accepted=false;
 if(!sxvintage_span(c,at,4096))return true;
 if(!sx_read(c,(int64_t)at,volume,256)||!sx_read(c,(int64_t)at+256,fat,256)||!sx_read(c,(int64_t)at+512,directory,sizeof(directory)))return false;
 for(unsigned i=0;i<8;i++)if(volume[i]<32||volume[i]>127)return true;
 if(fat[0]||!(fat[41]==254||fat[41]==251)||!(fat[42]==254||fat[42]==251))return true;
 for(unsigned i=81;i<256;i++)if(fat[i]){blocks=160;break;}
 if(!sxvintage_span(c,origin,(uint64_t)blocks*2048))return true;
 for(unsigned i=blocks+1;i<256;i++)if(fat[i])return true;
 for(unsigned i=1;i<=blocks;i++)if(!(fat[i]<blocks||(fat[i]>=193&&fat[i]<=200)||fat[i]==251||fat[i]==254||fat[i]==255))return true;
 for(;entries<112;entries++){
  const uint8_t*d=directory+entries*32;
  if(d[0]==255){entries++;break;}
  if(!d[0])continue;
  for(unsigned i=0;i<11;i++)if(d[i]<32||d[i]>127)return true;
  if(d[11]>3||(d[12]!=0&&d[12]!=255)||d[13]>=blocks||d[14])return true;
 }
 if(!sx_add(c,&sxvintage_thomson_volume_header,(int64_t)at,256)||
    !sx_add(c,&sxvintage_thomson_fat_prefix,(int64_t)at+256,1)||
    !sx_table(c,&sxvintage_thomson_fat_entry,(int64_t)at+257,1,blocks))return false;
 for(unsigned i=0;i<entries;i++){
  const uint8_t*d=directory+i*32;
  const sx_layout*l=(d[0]==0||d[0]==255)?&sxvintage_thomson_directory_state:&sxvintage_thomson_directory_entry;
  if(!sx_add(c,l,(int64_t)at+512+i*32,l==&sxvintage_thomson_directory_state?1:32))return false;
 }
 *accepted=true;return true;
}
bool sx_thomson_fd_build(sx_context*c)
{
 if(c->size!=327680&&c->size!=655360)return false;
 bool first=false,second=false;
 if(!sxvintage_thomson_side(c,0,&first)||!sxvintage_thomson_side(c,(uint64_t)c->size/2,&second))return false;
 if(!first&&!second)return sx_raw(c,0,c->size);
 return sxvintage_finish(c);
}
