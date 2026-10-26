/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * NorthStar NSI data structures, moved out of the vintagefilesystems schema family. */
#include "../../xx_format_schema_vintagefilesystems.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxvintage_northstar_directory_entry_fields[]={
 SX_FIELD("filename","char[8]",0,8,SX_NONE),
 SX_FIELD("disk_address","uint16",8,2,SX_ID),
 SX_FIELD("stored_length","uint16",10,2,SX_COUNT_PROP),
 SX_FIELD("type_density","uint8",12,1,SX_FLAGS),
 SX_FIELD("opaque_type_data","uint8[3]",13,3,SX_NONE),
};
const sx_layout sxvintage_northstar_directory_entry={0x609d0006U,"northstar_directory_entry",sxvintage_northstar_directory_entry_fields,SX_COUNT(sxvintage_northstar_directory_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxvintage_northstar_executable_entry_fields[]={
 SX_FIELD("filename","char[8]",0,8,SX_NONE),
 SX_FIELD("disk_address","uint16",8,2,SX_ID),
 SX_FIELD("stored_length","uint16",10,2,SX_COUNT_PROP),
 SX_FIELD("type_density","uint8",12,1,SX_FLAGS),
 SX_FIELD("go_address","uint16",13,2,SX_ADDRESS),
 SX_FIELD("unknown_tail","uint8",15,1,SX_NONE),
};
const sx_layout sxvintage_northstar_executable_entry={0x609d0007U,"northstar_executable_entry",sxvintage_northstar_executable_entry_fields,SX_COUNT(sxvintage_northstar_executable_entry_fields),SX_LE};
static bool sxvintage_northstar(sx_context*c)
{
 uint8_t directory[2048];unsigned used=0;uint64_t sectors;
 if(c->size!=179200&&c->size!=358400)return false;
 sectors=(uint64_t)c->size/512;
 if(!sx_read(c,0,directory,sizeof(directory)))return false;
 for(unsigned i=0;i<128;i++){
  const uint8_t*d=directory+i*16;
  if(d[0]==' ')continue;
  for(unsigned j=0;j<8;j++)if(d[j]<32||d[j]>=127||d[j]==',')return false;
  uint64_t at=(uint64_t)d[8]+((uint64_t)d[9]<<8),length=(uint64_t)d[10]+((uint64_t)d[11]<<8);
  if(!(d[12]&128)||at>=sectors||length>sectors-at)return false;
  used++;
 }
 if(!used)return false;
 for(unsigned i=0;i<128;i++){
  const uint8_t*d=directory+i*16;
  if(d[0]==' ')continue;
  const sx_layout*l=(d[12]&127)==1?&sxvintage_northstar_executable_entry:&sxvintage_northstar_directory_entry;
  if(!sx_add(c,l,i*16,16))return false;
 }
 return true;
}
bool sx_northstar_nsi_build(sx_context*c)
{
 if(c->size!=89600&&c->size!=179200&&c->size!=358400)return false;
 if(sxvintage_northstar(c))return sxvintage_finish(c);
 if(c->failed||c->count||xx_pd_is_stopped(c->pd))return false;
 return sx_raw(c,0,c->size);
}
