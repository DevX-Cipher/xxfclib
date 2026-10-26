/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Raster Musictracker data structures, moved out of the zxmusic schema family. */
#include "../../../xx_format_schema_zxmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxzxm_rmt_instrument_address_fields[]={
 SX_FIELD("instrument_address","uint16",0,2,SX_ADDRESS),
};
const sx_layout sxzxm_rmt_instrument_address={UINT32_C(0x608A006A),"rmt_instrument_address",sxzxm_rmt_instrument_address_fields,SX_COUNT(sxzxm_rmt_instrument_address_fields),SX_LE};
#define SXZXM_ADD(c,n,p) sxzxm_put(c,&sxzxm_##n,p,1)
static bool sxzxm_rmt(sx_context*c){
 uint8_t b[6],h[16];if(!sxzxm_read(c,0,b,6)||!SXZXM_ADD(c,rmt_binary_header,0))return false;
 unsigned load=sxzxm16(b+2),end=sxzxm16(b+4);if(end<load||!sxzxm_span(c,6,(unsigned)end-load+1)||!sxzxm_read(c,6,h,16))return true;
 if(!sxzxm_eq(c,6,"RMT",3)||(h[3]!='4'&&h[3]!='8'))return true;
 if(!SXZXM_ADD(c,rmt_header,6))return false;unsigned ip=sxzxm16(h+8),lo=sxzxm16(h+10),hi=sxzxm16(h+12),song=sxzxm16(h+14);uint64_t segment_end=7U+end-load;
 if(ip>=load+16U&&lo>=ip&&hi>=lo&&song>=hi&&song<=end+1U){
  unsigned ic=(lo-ip)/2,tc=hi-lo;if(ic>256)ic=256;if(tc>256)tc=256;uint64_t it=6U+ip-load;
  if(!sxzxm_opt(c,&sxzxm_rmt_instrument_address,it,ic)||!sxzxm_opt(c,&sxzxm_rmt_track_low,6U+lo-load,tc)||!sxzxm_opt(c,&sxzxm_rmt_track_high,6U+hi-load,song-hi<tc?song-hi:tc))return false;
  for(unsigned i=0;i<ic;i++){uint16_t address;if(!sxzxm_u16(c,it+2U*i,&address))break;if(address<load+16U||address>end)continue;uint64_t p=6U+address-load;uint8_t ih[12];if(p>segment_end||12>segment_end-p||!sxzxm_read(c,p,ih,12))continue;
   if(!SXZXM_ADD(c,rmt_instrument,p))return false;

  }
 }
 uint64_t p=segment_end;for(unsigned i=0;i<256&&sxzxm_span(c,p,4);i++){uint8_t sh[4];if(!sxzxm_read(c,p,sh,4))break;unsigned a=sxzxm16(sh),z=sxzxm16(sh+2);if(a==65535){if(!sxzxm_span(c,p+2,4))break;p+=2;if(!sxzxm_read(c,p,sh,4))break;a=sxzxm16(sh);z=sxzxm16(sh+2);}if(z<a||!sxzxm_span(c,p+4,z-a+1U))break;if(!SXZXM_ADD(c,rmt_binary_segment,p))return false;p+=4U+z-a+1U;}
 return true;
}
bool sx_raster_musictracker_build(sx_context*c)
{
 return sxzxm_rmt(c);
}
