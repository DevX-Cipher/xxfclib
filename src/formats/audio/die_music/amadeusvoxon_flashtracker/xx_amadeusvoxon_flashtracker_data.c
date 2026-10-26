/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Amadeus Voxon Flash Tracker data structures, moved out of the musicfurther schema family. */
#include "../../../xx_format_schema_musicfurther.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxfurther_fls_header_fields[]={
 SX_FIELD("positions_address","uint16",0,2,SX_ADDRESS),
 SX_FIELD("ornaments_address","uint16",2,2,SX_ADDRESS),
 SX_FIELD("samples_address","uint16",4,2,SX_ADDRESS),
};
const sx_layout sxfurther_fls_header={UINT32_C(0x60980001),"fls_header",sxfurther_fls_header_fields,SX_COUNT(sxfurther_fls_header_fields),SX_LE};
static const xx_data_struct_field_desc sxfurther_fls_pattern_addresses_fields[]={
 SX_FIELD("channel_a_address","uint16",0,2,SX_ADDRESS),
 SX_FIELD("channel_b_address","uint16",2,2,SX_ADDRESS),
 SX_FIELD("channel_c_address","uint16",4,2,SX_ADDRESS),
};
const sx_layout sxfurther_fls_pattern_addresses={UINT32_C(0x60980002),"fls_pattern_addresses",sxfurther_fls_pattern_addresses_fields,SX_COUNT(sxfurther_fls_pattern_addresses_fields),SX_LE};
static const xx_data_struct_field_desc sxfurther_fls_ornament_address_fields[]={
 SX_FIELD("ornament_address","uint16",0,2,SX_ADDRESS),
};
const sx_layout sxfurther_fls_ornament_address={UINT32_C(0x60980003),"fls_ornament_address",sxfurther_fls_ornament_address_fields,SX_COUNT(sxfurther_fls_ornament_address_fields),SX_LE};
static const xx_data_struct_field_desc sxfurther_fls_orders_end_fields[]={
 SX_FIELD("terminator","uint8",0,1,SX_ID),
};
const sx_layout sxfurther_fls_orders_end={UINT32_C(0x60980007),"fls_orders_end",sxfurther_fls_orders_end_fields,SX_COUNT(sxfurther_fls_orders_end_fields),SX_LE};
/* FLS uses original16-bit Z80 addresses. Authenticate relocation from the
 * pinned Vortex PrepareZXModule algorithm before following any address. */
typedef struct sxfurther_view{sx_context*c;uint64_t end;unsigned work;}sxfurther_view;
static bool sxfurther_span(sxfurther_view*v,uint64_t p,uint64_t n){return !xx_pd_is_stopped(v->c->pd)&&p<=v->end&&n<=v->end-p;}
static bool sxfurther_word(sxfurther_view*v,uint64_t p,unsigned n,uint64_t*x){uint8_t b[2];if(++v->work>1000000||!n||n>2||!sxfurther_span(v,p,n)||!sx_read(v->c,(int64_t)p,b,n))return false;*x=b[0]|(n==2?(uint64_t)b[1]<<8:0);return true;}
static bool sxfurther_row(sxfurther_view*v,const sx_layout*l,uint64_t p){const xx_data_struct_field_desc*f=&l->fields[l->field_count-1];uint64_t z=(uint64_t)(f->rel_offset+f->size);return ++v->work<=1000000&&sxfurther_span(v,p,z)&&(v->c->count>=24000||sx_add(v->c,l,(int64_t)p,(int64_t)z));}
#define SF_ROW(n,p) sxfurther_row(v,&sxfurther_##n,p)
static bool sxfurther_relative(uint64_t address,uint64_t base,uint64_t end,uint64_t*p){if(address<base||address-base>=end)return false;*p=address-base;return true;}
static bool sxfurther_candidate(sxfurther_view*v,uint64_t base,uint64_t samples,uint64_t a,uint64_t b){
 uint64_t sample_ptr,sample_data,ornament_data,at,x,pa,pb;
 if(!sxfurther_relative(samples,base,v->end,&sample_ptr)||sample_ptr<6||!sxfurther_word(v,sample_ptr+2,2,&sample_data)||!sxfurther_relative(sample_data,base,v->end,&sample_data)||sample_data<8)return false;
 if(!sxfurther_word(v,sample_ptr-2,2,&ornament_data)||!sxfurther_relative(ornament_data,base,v->end,&ornament_data)||ornament_data<6||sample_data<ornament_data||sample_data-ornament_data!=32)return false;
 if(!sxfurther_relative(a,base,v->end,&pa)||pa<=20||!sxfurther_relative(b,base,v->end,&pb)||pb<=21||!sxfurther_word(v,pa-1,1,&x)||x)return false;
 at=pa;while(at<v->end){if(!sxfurther_word(v,at,1,&x))return false;if(x==255)return at+1==pb;
  /* Advance exactly like original row interpreter:FF only terminates at a
   * row boundary; envelope commands82..8E consume one following operand. */
  bool row=false;while(at<v->end){if(!sxfurther_word(v,at,1,&x))return false;if(x<=0x5f||x==0x80||x==0x81){at++;row=true;break;}uint64_t n=x>=0x82&&x<=0x8e?2:1;if(!sxfurther_span(v,at,n))return false;at+=n;}
  if(!row)return false;
 }return false;
}
static bool sxfurther_fls(sxfurther_view*v){
 uint64_t positions,ornaments,samples,a,b,base=0;bool found=false;
 if(!sxfurther_word(v,0,2,&positions)||!sxfurther_word(v,2,2,&ornaments)||!sxfurther_word(v,4,2,&samples)||samples<ornaments||positions<=samples||(samples-ornaments)%2||samples-ornaments>30||(positions-samples)%4||positions-samples>64||!sxfurther_word(v,6,2,&a)||a<=positions||a-positions-1<1||a-positions-1>256||!SF_ROW(fls_header,0))return false;
 if(ornaments<16||!sxfurther_word(v,8,2,&b))return true;
 for(uint64_t candidate=ornaments-16;;candidate--){if(v->work>=1000000||xx_pd_is_stopped(v->c->pd))return true;if(sxfurther_candidate(v,candidate,samples,a,b)){base=candidate;found=true;break;}if(!candidate)break;}
 if(!found)return true;
 uint64_t op,sp,pp,ap;
 if(!sxfurther_relative(ornaments,base,v->end,&op)||!sxfurther_relative(samples,base,v->end,&sp)||!sxfurther_relative(positions,base,v->end,&pp)||!sxfurther_relative(a,base,v->end,&ap)||op<6||sp<op||pp<=sp||(op-6)%6||(sp-op)%2||(pp-sp)%4)return true;
 uint64_t np=(op-6)/6,no=(sp-op)/2,ns=(pp-sp)/4;
 if(np<1||np>31||no>15||ns<1||ns>16||!sxfurther_span(v,6,pp-6))return true;
 uint64_t terminator=pp+1,orders=0,x;
 for(;orders<256;orders++,terminator++){if(!sxfurther_word(v,terminator,1,&x))return true;if(!x)break;if(x>np)return true;}
 if(!orders||orders==256||terminator+1!=ap)return true;
 for(uint64_t i=0;i<np;i++){uint64_t at=6+i*6;for(unsigned ch=0;ch<3;ch++){uint64_t target;if(!sxfurther_word(v,at+ch*2,2,&x)||!sxfurther_relative(x,base,v->end,&target)||target<ap)return true;}if(!SF_ROW(fls_pattern_addresses,at))return true;}
 for(uint64_t i=0;i<no;i++)if(!SF_ROW(fls_ornament_address,op+i*2))return true;
 for(uint64_t i=0;i<ns;i++)if(!SF_ROW(fls_sample_descriptor,sp+i*4))return true;
 if(!SF_ROW(fls_delay,pp))return true;for(uint64_t i=0;i<orders;i++)if(!SF_ROW(fls_order,pp+1+i))return true;if(!SF_ROW(fls_orders_end,terminator))return true;
 for(uint64_t i=0;i<no;i++){uint64_t target;if(!sxfurther_word(v,op+i*2,2,&x)||!sxfurther_relative(x,base,v->end,&target)||target<ap||!sxfurther_span(v,target,32))continue;for(unsigned j=0;j<32;j++)if(!SF_ROW(fls_ornament_step,target+j))return true;}
 for(uint64_t i=0;i<ns;i++){uint64_t target;if(!sxfurther_word(v,sp+i*4+2,2,&x)||!sxfurther_relative(x,base,v->end,&target)||target<ap||!sxfurther_span(v,target,96))continue;for(unsigned j=0;j<32;j++)if(!SF_ROW(fls_sample_tick,target+j*3))return true;}
 return true;
}
static int sxfurther_order(const void*aa,const void*bb){const xx_data_struct*a=aa,*b=bb;if(a->offset!=b->offset)return a->offset<b->offset?-1:1;return a->total_size<b->total_size?-1:a->total_size>b->total_size?1:0;}
static bool sxfurther_finish(sx_context*c){size_t n=c->count,keep=0;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxfurther_order);for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(at<end)continue;c->items[keep++]=c->items[i];end=at+z;}c->count=keep;n=keep;end=0;for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(at>end&&!sx_raw(c,end,at-end))return false;end=at+z;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxfurther_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
#undef SF_ROW
bool sx_amadeusvoxon_flashtracker_build(sx_context*c)
{
 sxfurther_view v={c,(uint64_t)c->size,0};if(v.end>65536)v.end=65536;return sxfurther_fls(&v)&&sxfurther_finish(c);
}
