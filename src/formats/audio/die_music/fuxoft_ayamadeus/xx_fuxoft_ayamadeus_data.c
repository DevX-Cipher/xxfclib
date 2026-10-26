/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * DIE MUSIC FUXOFT AYAMADEUS data structures, moved out of the chipmusic schema family. */
#include "../../../xx_format_schema_chipmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxchip_chip_text_fields[]={
 SX_FIELD("text","char",0,0,SX_NONE),
};
const sx_layout sxchip_chip_text={UINT32_C(0x608F0001),"chip_text",sxchip_chip_text_fields,SX_COUNT(sxchip_chip_text_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_ay_amadeus_address_fields[]={
 SX_FIELD("load_address","uint16",0,2,SX_ADDRESS),
};
const sx_layout sxchip_chip_ay_amadeus_address={UINT32_C(0x608F0006),"chip_ay_amadeus_address",sxchip_chip_ay_amadeus_address_fields,SX_COUNT(sxchip_chip_ay_amadeus_address_fields),SX_BE};
#define SXCHIP_LIMIT 24000U
#define SXCHIP_ADD(c,n,p) sxchip_put(c,&sxchip_##n,p,1)
/* Strings have dynamic physical width but share a genuine string-field layout. */
static bool sxchip_string(sx_context*c,uint64_t p){uint8_t ch;uint64_t n=0;while(n<4096&&sxchip_u8(c,p+n,&ch)){n++;if(!ch){if(c->count>=SXCHIP_LIMIT)return true;for(size_t i=0;i<c->count;i++){uint64_t a=(uint64_t)(c->items[i].offset-c->f->base_address),z=(uint64_t)c->items[i].total_size;if(p<a+z&&a<p+n)return true;}return sx_add(c,&sxchip_chip_text,(int64_t)p,(int64_t)n);}}return true;}
static uint16_t sxchipbe16(const uint8_t*b){return (uint16_t)((uint16_t)b[0]<<8)|b[1];}
static bool sxchip_delta(sx_context*c,uint64_t origin,int16_t delta,uint64_t*out){
 if(delta<0){uint64_t d=(uint64_t)(-(int32_t)delta);if(d>origin)return false;*out=origin-d;}
 else{if((uint64_t)delta>UINT64_MAX-origin)return false;*out=origin+(uint16_t)delta;}
 return sxchip_span(c,*out,0);
}
static bool sxchip_amadeus(sx_context*c){
 uint8_t h[20];if(!sxchip_read(c,0,h,20)||xx_rt_memcmp(h,"ZXAYAMAD",8))return false;
 if(!SXCHIP_ADD(c,chip_ay_amadeus_header,0))return false;
 uint64_t p;for(unsigned i=12;i<=14;i+=2)if(sxchipbe16(h+i)&&sxchip_delta(c,i,(int16_t)sxchipbe16(h+i),&p)&&!sxchip_string(c,p))return false;
 if(!sxchip_delta(c,18,(int16_t)sxchipbe16(h+18),&p))return true;
 for(unsigned i=0;i<=(unsigned)h[16];i++,p+=4){uint8_t r[4];if(!sxchip_read(c,p,r,4))break;
  if(!SXCHIP_ADD(c,chip_ay_song,p))return false;uint64_t q;
  if(sxchip_delta(c,p,(int16_t)sxchipbe16(r),&q)&&!sxchip_string(c,q))return false;
  /* The first song word is explicitly read as BE target load address by AY_Emul.
   * Later playback fields and bytecode remain raw, not guessed from AY-EMUL. */
  if(sxchip_delta(c,p+2,(int16_t)sxchipbe16(r+2),&q)&&!sxchip_opt(c,&sxchip_chip_ay_amadeus_address,q,1))return false;
 }
 return true;
}
bool sx_fuxoft_ayamadeus_build(sx_context*c)
{
 return sxchip_amadeus(c);
}
