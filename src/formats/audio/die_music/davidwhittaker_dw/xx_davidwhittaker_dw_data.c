/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * davidwhittaker_dw data structures, moved out of the codeplayers schema family. */
#include "../../../xx_format_schema_codeplayers.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxcodeplayers_dw_speed_fields[]={
 SX_FIELD("speed","uint16",0,2,SX_NONE),
};
const sx_layout sxcodeplayers_dw_speed={UINT32_C(0x60A10005),"dw_speed",sxcodeplayers_dw_speed_fields,SX_COUNT(sxcodeplayers_dw_speed_fields),SX_BE};
static const xx_data_struct_field_desc sxcodeplayers_dw_delay_speed_fields[]={
 SX_FIELD("speed","uint8",0,1,SX_NONE),
 SX_FIELD("delay_speed","uint8",1,1,SX_NONE),
};
const sx_layout sxcodeplayers_dw_delay_speed={UINT32_C(0x60A10006),"dw_delay_speed",sxcodeplayers_dw_delay_speed_fields,SX_COUNT(sxcodeplayers_dw_delay_speed_fields),SX_BE};
static uint32_t sxcodeplayers_be32(const uint8_t*b){return (uint32_t)b[0]<<24|(uint32_t)b[1]<<16|(uint32_t)b[2]<<8|b[3];}
#define SCP_PUT(n,p,c) sxcodeplayers_put(v,&sxcodeplayers_##n,p,c)
/* Initial scope: new-player32-bit pointer variant. The old-player/sample-row
 * variants have different physical widths and are deliberately left raw. */
static bool sxcodeplayers_dw(sxcodeplayers_view*v){
 size_t p=SIZE_MAX,i,init,si,play;uint64_t origin,data,smp,sub,ns,x;
 for(i=0;i+6<=v->code_size;i+=2)if(sxcodeplayers_eq(v,i,"\x47\xfa",2)&&(v->code[i+2]&0xf0)==0xf0){p=i;break;}
 if(p==SIZE_MAX||!sxcodeplayers_ref(v,p+2,&origin))return false;
 init=sxcodeplayers_find(v,p,v->code_size,"\x61\0",2);if(init==SIZE_MAX)return false;si=init;
 if(sxcodeplayers_eq(v,init+4,"\x61\0",2)){if(!sxcodeplayers_ref(v,init+6,&x)||x>SIZE_MAX)return false;si=(size_t)x;}
 i=sxcodeplayers_find(v,si,v->code_size,"\x4a\x2b",2);if(i==SIZE_MAX||i+10>v->code_size||v->code[i+4]!=0x66)return false;
 if(!v->code[i+5])i+=2;
 if(!sxcodeplayers_eq(v,i+6,"\x41\xfa",2)||!sxcodeplayers_ref(v,i+8,&data))return false;i+=10;
 if(sxcodeplayers_eq(v,i,"\x27\x48",2)&&sxcodeplayers_eq(v,i+4,"\xd0\xfc",2)){
  if(i+16>v->code_size||!sxcodeplayers_eq(v,i+12,"\xd0\xfc",2))return false;
  uint64_t delta=(uint64_t)sxcodeplayers_be16(v->code+i+6)+sxcodeplayers_be16(v->code+i+14);if(delta>v->end-data)return false;data+=delta;i+=16;
 }
 if(!sxcodeplayers_eq(v,i,"\x4b\xfa",2)||i+6>v->code_size||v->code[i+4]!=0x72||!sxcodeplayers_ref(v,i+2,&smp))return false;ns=(uint64_t)v->code[i+5]+1;
 p=SIZE_MAX;for(i=init;i+6<=v->code_size;i+=2)if(sxcodeplayers_eq(v,i,"\x41\xfa",2)&&v->code[i+4]!=0x4b){p=i;break;}
 if(p==SIZE_MAX||(!sxcodeplayers_eq(v,p+4,"\x12\x30",2)&&!sxcodeplayers_eq(v,p+4,"\x37\x70",2))||!sxcodeplayers_ref(v,p+2,&sub))return false;
 i=p+4;p=SIZE_MAX;for(;i+6<=v->code_size;i+=2)if(sxcodeplayers_eq(v,i,"\x41\xfa",2)&&v->code[i+4]!=0x23){p=i;break;}
 if(p==SIZE_MAX||!sxcodeplayers_eq(v,p+4,"\x20\x70",2))return false;
 play=SIZE_MAX;for(i=0;i+12<=v->code_size;i+=2)if(sxcodeplayers_eq(v,i,"\x47\xfa",2)&&sxcodeplayers_eq(v,i+4,"\x4a\x2b",2)&&v->code[i+8]==0x67){uint16_t op=sxcodeplayers_be16(v->code+i+10);if(op!=0x33fc&&op!=0x177c&&op!=0x08b9){play=i;break;}}
 if(play==SIZE_MAX)return false;unsigned channels=0;bool delay=false;
 for(i=play;i<play+100&&i+2<=v->code_size;i+=2)if(sxcodeplayers_eq(v,i,"\x10\x3a",2)){delay=true;break;}
 for(i=play;i<play+200&&i+2<=v->code_size;i+=2)if(v->code[i]==0x7e){channels=v->code[i+1];if(channels)channels++;else for(;i<play+500&&i+4<=v->code_size;i+=2)if(sxcodeplayers_eq(v,i,"\xbe\x7c",2)||sxcodeplayers_eq(v,i,"\xbe\x3c",2)){channels=v->code[i+3];break;}break;}
 if(!channels||channels>16)return false;
 if(!SCP_PUT(dw_sample32,smp,ns))return false;
 uint64_t first=v->end,pos=sub,width=2+4U*channels;
 for(unsigned n=0;n<256&&pos<=first&&first-pos>=width;n++,pos+=width){uint64_t speed;if(!sxcodeplayers_u(v,pos,delay?1:2,&speed)||speed>255)break;bool valid=true;for(unsigned ch=0;ch<channels;ch++){if(!sxcodeplayers_u(v,pos+2+4U*ch,4,&x)||x>v->end-origin){valid=false;break;}if(origin+x<first)first=origin+x;}if(!valid||pos>first||width>first-pos)break;if(!sxcodeplayers_put(v,delay?&sxcodeplayers_dw_delay_speed:&sxcodeplayers_dw_speed,pos,1)||!SCP_PUT(dw_position_offset,pos+2,channels))return false;}
 for(uint64_t n=0,payload=data;n<ns;n++){uint8_t h[6];if(!sxcodeplayers_read(v,payload,h,6))break;uint64_t bytes=sxcodeplayers_be32(h);if(!sxcodeplayers_span(v,payload+6,bytes)||!sxcodeplayers_be16(h+4))break;if(!SCP_PUT(dw_sample_data,payload,1))return false;payload+=6+bytes;}
 return true;
}
bool sx_davidwhittaker_dw_build(sxcodeplayers_view*v)
{
 return sxcodeplayers_dw(v);
}
#undef SCP_PUT
