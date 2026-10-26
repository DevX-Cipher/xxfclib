/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * DIE MUSIC HULSBECK THEFINALMUSICSYSTEMEXTENDED data structures, moved out of the classicmusic schema family. */
#include "../../../xx_format_schema_classicmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxcmus_tfmx_mod_wrapper_fields[]={
 SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("sample_data_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("tag_table_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("opaque_word","bytes",16,4,SX_NONE),
};
const sx_layout sxcmus_tfmx_mod_wrapper={UINT32_C(0x609E0015),"tfmx_mod_wrapper",sxcmus_tfmx_mod_wrapper_fields,SX_COUNT(sxcmus_tfmx_mod_wrapper_fields),SX_LE};
static const xx_data_struct_field_desc sxcmus_tfmx_prefix_fields[]={
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("variant_tag","bytes",4,4,SX_NONE),
 SX_FIELD("opaque_prefix","bytes",8,8,SX_NONE),
};
const sx_layout sxcmus_tfmx_prefix={UINT32_C(0x609E0016),"tfmx_prefix",sxcmus_tfmx_prefix_fields,SX_COUNT(sxcmus_tfmx_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxcmus_tfmx_comment_fields[]={
 SX_FIELD("comment","char[40]",0,40,SX_NONE),
};
const sx_layout sxcmus_tfmx_comment={UINT32_C(0x609E0017),"tfmx_comment",sxcmus_tfmx_comment_fields,SX_COUNT(sxcmus_tfmx_comment_fields),SX_LE};
static const xx_data_struct_field_desc sxcmus_tfmx_song_start_fields[]={
 SX_FIELD("first_track_step","uint16",0,2,SX_NONE),
};
const sx_layout sxcmus_tfmx_song_start={UINT32_C(0x609E0018),"tfmx_song_start",sxcmus_tfmx_song_start_fields,SX_COUNT(sxcmus_tfmx_song_start_fields),SX_BE};
static uint16_t sxcmus16(const uint8_t*b){return (uint16_t)b[0]|(uint16_t)((uint16_t)b[1]<<8);}
#define SXCMUS_ADD(c,n,p) sxcmus_put(c,&sxcmus_##n,p,1)
static bool sxcmus_tfmx(sx_context*c){
 uint64_t base=0,music_end=(uint64_t)c->size,tag=0;uint8_t b[20];
 if(sxcmus_eq(c,0,"TFHD",4)){
  if(!sxcmus_read(c,0,b,18)||!SXCMUS_ADD(c,tfmx_tfhd,0))return false;
  base=sxcmus_be32(b+4);uint64_t n=sxcmus_be32(b+10);if(base<18||!sxcmus_span(c,base,n))return true;music_end=base+n;
 }else if(sxcmus_eq(c,0,"TFMX-MOD",8)){
  if(!sxcmus_read(c,0,b,20)||!SXCMUS_ADD(c,tfmx_mod_wrapper,0))return false;
  base=20;uint64_t n=(uint32_t)b[8]|(uint32_t)b[9]<<8|(uint32_t)b[10]<<16|(uint32_t)b[11]<<24;
  tag=(uint32_t)b[12]|(uint32_t)b[13]<<8|(uint32_t)b[14]<<16|(uint32_t)b[15]<<24;
  if(n>=base&&n<=music_end)music_end=n;else return true;
 }
 if(!sxcmus_span(c,base,512)||music_end<base||music_end-base<512||(!sxcmus_eq(c,base,"TFMX",4)&&!sxcmus_eq(c,base,"tfmx",4)))return c->count!=0;
 if(!SXCMUS_ADD(c,tfmx_prefix,base)||!sxcmus_put(c,&sxcmus_tfmx_comment,base+16,6)||!sxcmus_put(c,&sxcmus_tfmx_song_start,base+256,32)||!sxcmus_put(c,&sxcmus_tfmx_song_end,base+320,32)||!sxcmus_put(c,&sxcmus_tfmx_song_tempo,base+384,32)||!sxcmus_put(c,&sxcmus_tfmx_track_mute,base+448,8))return false;
 uint8_t ptr[12];if(!sxcmus_read(c,base+464,ptr,12))return false;uint64_t refs[3];bool little=false;
 for(unsigned i=0;i<3;i++){refs[i]=sxcmus_be32(ptr+4*i);if(refs[i]>=(uint64_t)c->size)little=true;}
 if(little)for(unsigned i=0;i<3;i++){const uint8_t*p=ptr+4*i;refs[i]=(uint32_t)p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24;}
 if(!sxcmus_put(c,little?&sxcmus_tfmx_tables_le:&sxcmus_tfmx_tables_be,base+464,1))return false;
 if(!(refs[0]|refs[1]|refs[2])){refs[0]=0x800;refs[1]=0x400;refs[2]=0x600;}
 uint64_t track=refs[0],pattern=refs[1],macro=refs[2],first=0;
 /* Table capacities are bounded by the next distinct physical section.
  * Pattern/macro bytecode stays raw; pointer words remain big-endian. */
 for(unsigned j=1;j<=2;j++){
  uint64_t p=refs[j],end=music_end-base;if(p<512||p>end)continue;
  for(unsigned k=0;k<3;k++)if(k!=j&&refs[k]>p&&refs[k]<end)end=refs[k];
  uint64_t count=(end-p)/4;if(count>128)count=128;
  if(count&&!sxcmus_put(c,&sxcmus_tfmx_pointer,base+p,count))return false;
 }
 if(pattern>=512&&pattern<=music_end-base&&music_end-base-pattern>=4&&sxcmus_read(c,base+pattern,ptr,4))first=sxcmus_be32(ptr);
 if(track>=512&&first>=track&&first<=music_end-base){
  uint64_t n=(first-track)/16;if(n>512)n=512;
  for(uint64_t i=0;i<n;i++){
   uint64_t p=base+track+16*i;uint16_t marker;if(!sxcmus_word(c,p,&marker))return false;
   if(marker==0xeffe){if(!SXCMUS_ADD(c,tfmx_track_command,p))return false;}
   else if(!sxcmus_put(c,&sxcmus_tfmx_track_channel,p,8))return false;
  }
 }
 if(tag>=music_end&&tag<(uint64_t)c->size){
  for(unsigned i=0;i<4096&&sxcmus_span(c,tag,3);i++){
   uint8_t h[3];if(!sxcmus_read(c,tag,h,3)||!SXCMUS_ADD(c,tfmx_mod_tag,tag))return false;uint64_t n=sxcmus16(h+1);tag+=3;
   if(!h[0]||!n||!sxcmus_span(c,tag,n))break;tag+=n;
  }
 }
 (void)macro;return true;
}
bool sx_hulsbeck_thefinalmusicsystemextended_build(sx_context*c)
{
 return sxcmus_tfmx(c);
}
