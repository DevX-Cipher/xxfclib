/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * walker_activisionpro data structures, moved out of the codeplayers schema family. */
#include "../../../xx_format_schema_codeplayers.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxcodeplayers_avp_instrument1_fields[]={
 SX_FIELD("sample_number","uint8",0,1,SX_ID),
 SX_FIELD("envelope_number","uint8",1,1,SX_ID),
 SX_FIELD("effect_flags","uint8",2,1,SX_FLAGS),
 SX_FIELD("opaque3","bytes",3,1,SX_NONE),
 SX_FIELD("portamento_add","uint8",4,1,SX_NONE),
 SX_FIELD("opaque5","bytes",5,2,SX_NONE),
 SX_FIELD("stop_reset_delay","uint8",7,1,SX_NONE),
 SX_FIELD("second_sample","uint8",8,1,SX_ID),
 SX_FIELD("arpeggio0","int8",9,1,SX_NONE),
 SX_FIELD("arpeggio1","int8",10,1,SX_NONE),
 SX_FIELD("arpeggio2","int8",11,1,SX_NONE),
 SX_FIELD("arpeggio3","int8",12,1,SX_NONE),
 SX_FIELD("fixed_or_transposed_note","uint8",13,1,SX_NONE),
 SX_FIELD("vibrato_number","uint8",14,1,SX_ID),
 SX_FIELD("vibrato_delay","uint8",15,1,SX_NONE),
};
const sx_layout sxcodeplayers_avp_instrument1={UINT32_C(0x60A1000D),"avp_instrument1",sxcodeplayers_avp_instrument1_fields,SX_COUNT(sxcodeplayers_avp_instrument1_fields),SX_BE};
static const xx_data_struct_field_desc sxcodeplayers_avp_instrument2_fields[]={
 SX_FIELD("sample_number","uint8",0,1,SX_ID),
 SX_FIELD("volume","uint8",1,1,SX_NONE),
 SX_FIELD("effect_flags","uint8",2,1,SX_FLAGS),
 SX_FIELD("opaque3","bytes",3,1,SX_NONE),
 SX_FIELD("portamento_add","uint8",4,1,SX_NONE),
 SX_FIELD("opaque5","bytes",5,2,SX_NONE),
 SX_FIELD("stop_reset_delay","uint8",7,1,SX_NONE),
 SX_FIELD("second_sample","uint8",8,1,SX_ID),
 SX_FIELD("arpeggio0","int8",9,1,SX_NONE),
 SX_FIELD("arpeggio1","int8",10,1,SX_NONE),
 SX_FIELD("arpeggio2","int8",11,1,SX_NONE),
 SX_FIELD("arpeggio3","int8",12,1,SX_NONE),
 SX_FIELD("fixed_or_transposed_note","uint8",13,1,SX_NONE),
 SX_FIELD("vibrato_number","uint8",14,1,SX_ID),
 SX_FIELD("vibrato_delay","uint8",15,1,SX_NONE),
};
const sx_layout sxcodeplayers_avp_instrument2={UINT32_C(0x60A1000E),"avp_instrument2",sxcodeplayers_avp_instrument2_fields,SX_COUNT(sxcodeplayers_avp_instrument2_fields),SX_BE};
static const xx_data_struct_field_desc sxcodeplayers_avp_instrument3_fields[]={
 SX_FIELD("sample_number","uint8",0,1,SX_ID),
 SX_FIELD("volume","uint8",1,1,SX_NONE),
 SX_FIELD("effect_flags","uint8",2,1,SX_FLAGS),
 SX_FIELD("transpose","int8",3,1,SX_NONE),
 SX_FIELD("finetune","int16",4,2,SX_NONE),
 SX_FIELD("sample_start_offset","uint16",6,2,SX_OFFSET),
 SX_FIELD("stop_reset_delay","uint8",8,1,SX_NONE),
 SX_FIELD("arpeggio0","int8",9,1,SX_NONE),
 SX_FIELD("arpeggio1","int8",10,1,SX_NONE),
 SX_FIELD("arpeggio2","int8",11,1,SX_NONE),
 SX_FIELD("arpeggio3","int8",12,1,SX_NONE),
 SX_FIELD("fixed_or_transposed_note","uint8",13,1,SX_NONE),
 SX_FIELD("vibrato_number","uint8",14,1,SX_ID),
 SX_FIELD("vibrato_delay","uint8",15,1,SX_NONE),
};
const sx_layout sxcodeplayers_avp_instrument3={UINT32_C(0x60A1000F),"avp_instrument3",sxcodeplayers_avp_instrument3_fields,SX_COUNT(sxcodeplayers_avp_instrument3_fields),SX_BE};
#define SCP_PUT(n,p,c) sxcodeplayers_put(v,&sxcodeplayers_##n,p,c)
static unsigned sxcodeplayers_avp_version(sxcodeplayers_view*v,size_t at){
 static const uint8_t a[][40]={{0x13,0xb5,0x50,2,0,0,0x13,0xb5,0x50,7,0,0,0x13,0xb5,0x50,15},{0x11,0xb5,0x50,1,0,0,0x13,0xb5,0x50,2,0,0,0x13,0xb5,0x50,7,0,0,0x13,0xb5,0x50,15},{0x11,0xb5,0x50,1,0,0,0x13,0xb5,0x50,2,0,0,0x13,0xb5,0x50,3,0,0,0x31,0xb5,0x50,4,0,0,0x33,0x75,0x50,6,0,0,0x13,0xb5,0x50,8,0,0,0x13,0xb5,0x50,15}};
 const unsigned sizes[]={16,22,40};for(unsigned k=0;k<3;k++){if(at>v->code_size||sizes[k]>v->code_size-at)continue;bool ok=true;for(unsigned n=0;n<sizes[k];n++)if(n%6<4&&v->code[at+n]!=a[k][n])ok=false;if(ok)return k+1;}return 0;
}
static bool sxcodeplayers_avp(sxcodeplayers_view*v){
 size_t start=SIZE_MAX,p=SIZE_MAX,q,play;uint64_t sub,positions,tracks,offsets,inst=0,global=0,data,samples,info=0,env=0,call;
 for(size_t i=0;i<1024&&i+4<=v->code_size;i++)if(sxcodeplayers_eq(v,i,"\x48\xe7\xfc\xfe",4)){start=i;break;}if(start==SIZE_MAX)return false;
 p=sxcodeplayers_find(v,start,v->code_size,"\xe9\x41\x70\0\x41\xfa",6);if(p==SIZE_MAX||!sxcodeplayers_ref(v,p+6,&sub))return false;
 q=p;for(;q+4<=v->code_size;q+=2){if(sxcodeplayers_eq(v,q,"\x4e\x75",2))return false;if(sxcodeplayers_eq(v,q,"\x61\0",2))break;}
 if(!sxcodeplayers_ref(v,q+2,&call)||!sxcodeplayers_eq(v,(size_t)call,"\x7a\0",2)||!sxcodeplayers_eq(v,(size_t)call+6,"\x49\xfa",2)||!sxcodeplayers_ref(v,(size_t)call+8,&positions)||positions<sub||(positions-sub)%16||(positions-sub)/16>256)return false;
 play=SIZE_MAX;for(size_t i=start;i+8<=v->code_size;i+=2)if(sxcodeplayers_eq(v,i,"\x2c\x7c",2)&&sxcodeplayers_eq(v,i+6,"\x4a\x29",2)){play=i;break;}if(play==SIZE_MAX||play<4)return false;
 for(size_t i=play-4;;){if(sxcodeplayers_eq(v,i,"\x4b\xfa",2)){if(!sxcodeplayers_ref(v,i+2,&inst))return false;}else if(sxcodeplayers_eq(v,i,"\x43\xfa",2)){if(!sxcodeplayers_ref(v,i+2,&global))return false;}if(inst&&global)break;if(i<2)return false;i-=2;}
 p=SIZE_MAX;for(size_t i=play;i+20<=v->code_size;i+=2)if(sxcodeplayers_eq(v,i,"\x7a\0\x1a\x31",4)&&sxcodeplayers_eq(v,i+6,"\xda\x45\x49\xfa",4)){p=i;break;}
 if(p==SIZE_MAX||!sxcodeplayers_ref(v,p+10,&offsets)||!sxcodeplayers_eq(v,p+12,"\x3a\x34",2)||!sxcodeplayers_eq(v,p+16,"\x49\xfa",2)||!sxcodeplayers_ref(v,p+18,&tracks)||offsets<inst||(offsets-inst)%16||(offsets-inst)/16>256||tracks<offsets||(tracks-offsets)%2||(tracks-offsets)/2>4096)return false;
 unsigned version=0;for(q=p+20;q+20<=v->code_size;q+=2)if(sxcodeplayers_eq(v,q,"\x31\x85",2)&&(version=sxcodeplayers_avp_version(v,q+4)))break;if(!version)return false;
 p=SIZE_MAX;for(size_t i=q+4;i+14<=v->code_size;i+=2)if(sxcodeplayers_eq(v,i,"\xe5\x45\x45\xfa",4)&&sxcodeplayers_eq(v,i+10,"\x45\xfa",2)){p=i;break;}
 if(p==SIZE_MAX||!sxcodeplayers_ref(v,p+4,&samples)||!sxcodeplayers_ref(v,p+12,&data))return false;
 if(sxcodeplayers_eq(v,p+26,"\xca\xfc",2)&&sxcodeplayers_eq(v,p+30,"\x45\xfa",2)&&!sxcodeplayers_ref(v,p+32,&info))return false;
 /* Envelope records are exposed only when the original envelope-load form
  * is present; no synthetic sixth runtime point is assigned physical bytes. */
 for(size_t i=p+14;i+10<=v->code_size;i+=2)if(sxcodeplayers_eq(v,i,"\xe9\x44",2)&&(v->code[i+2]==0x31||v->code[i+2]==0x11)&&v->code[i+3]==0x84&&sxcodeplayers_eq(v,i+6,"\x45\xfa",2)){if(!sxcodeplayers_ref(v,i+8,&env))return false;break;}
 if(!SCP_PUT(avp_subsong,sub,(positions-sub)/16))return false;
 if(env&&env<=inst&&(inst-env)%16==0&&(inst-env)/16<=256&&!SCP_PUT(avp_envelope,env,(inst-env)/16))return false;
 const sx_layout*l=version==1?&sxcodeplayers_avp_instrument1:version==2?&sxcodeplayers_avp_instrument2:&sxcodeplayers_avp_instrument3;
 if(!sxcodeplayers_put(v,l,inst,(offsets-inst)/16)||!SCP_PUT(avp_track_offset,offsets,(tracks-offsets)/2)||!SCP_PUT(avp_sample_offset,samples,28))return false;
 if(info){if(!SCP_PUT(avp_sample,info,27))return false;}
 else for(unsigned i=0;i<27;i++){uint64_t a,b;if(!sxcodeplayers_u(v,samples+4U*i,4,&a)||!sxcodeplayers_u(v,samples+4U*(i+1),4,&b))return false;if(b<a||b>v->end-data)continue;if(b-a>=6&&!SCP_PUT(avp_sample,data+a,1))return false;}
 return true;
}
bool sx_walker_activisionpro_build(sxcodeplayers_view*v)
{
 return sxcodeplayers_avp(v);
}
#undef SCP_PUT
