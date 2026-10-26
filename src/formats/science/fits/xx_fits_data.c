/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * FITS data structures, moved out of the sciencewire schema family. */
#include "../../xx_format_schema_sciencewire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsw_fits_card_fields[] = {
    SX_FIELD("keyword","char[8]",0,8,SX_ID),
    SX_FIELD("value_and_comment","char[72]",8,72,SX_STRING),
};
const sx_layout sxsw_fits_card = {UINT32_C(0x602d0001),"fits_card",sxsw_fits_card_fields,SX_COUNT(sxsw_fits_card_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_fits_integer_card_fields[] = {
    SX_FIELD("keyword","char[8]",0,8,SX_ID),
    SX_FIELD("indicator","char[2]",8,2,SX_NONE),
    SX_FIELD("integer_text","char[20]",10,20,SX_STRING),
    SX_FIELD("comment","char[50]",30,50,SX_STRING),
};
const sx_layout sxsw_fits_integer_card = {UINT32_C(0x602d0002),"fits_integer_card",sxsw_fits_integer_card_fields,SX_COUNT(sxsw_fits_integer_card_fields),SX_LE};
static bool sxsw_fits(sx_context *c)
{
 int64_t at=0;
 for(unsigned hdu=0;at<c->size&&hdu<1024;hdu++){
  uint8_t b[80];int64_t begin=at,bitpix=0,rank=-1;uint64_t pixels=1;bool end=false;
  if(!sx_read(c,at,b,80))return false;if(hdu&&xx_rt_memcmp(b,"XTENSION",8))return true;
  for(unsigned card=0;card<4096;card++){
   if(!sx_read(c,at,b,80))return false;bool integer=!xx_rt_memcmp(b,"BITPIX  ",8)||!xx_rt_memcmp(b,"NAXIS",5)||!xx_rt_memcmp(b,"PCOUNT  ",8)||!xx_rt_memcmp(b,"GCOUNT  ",8);
   if(!sxsw_add(c,integer?&sxsw_fits_integer_card:&sxsw_fits_card,at,80))return false;at+=80;
   if(!xx_rt_memcmp(b,"END     ",8)){end=true;break;}
   if(integer){int64_t n;if(!sxsw_text_integer(b+10,20,&n))return false;
    if(!xx_rt_memcmp(b,"BITPIX  ",8))bitpix=n;else if(!xx_rt_memcmp(b,"NAXIS   ",8))rank=n;
    else if(!xx_rt_memcmp(b,"NAXIS",5)){if(n<0||(n&&pixels>UINT64_MAX/(uint64_t)n))return false;pixels*=(uint64_t)n;}
   }
  }
  if(!end||rank<0||rank>16||!bitpix||bitpix==INT64_MIN)return false;
  uint64_t width=(uint64_t)(bitpix<0?-bitpix:bitpix)/8;if(!width||pixels>INT64_MAX/width)return false;
  uint64_t header=((uint64_t)(at-begin)+2879)/2880*2880,bytes=rank?pixels*width:0;
  bytes=(bytes+2879)/2880*2880;if(!sxsw_span(c,begin,header+bytes))return false;at=begin+(int64_t)(header+bytes);
 }return at==c->size;
}
bool sx_fits_build(sx_context*c)
{
 return sxsw_fits(c);
}
