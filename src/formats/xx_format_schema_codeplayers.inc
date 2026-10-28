/* Copyright (c)2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical music header and table metadata; compressed and unknown bodies stay raw. */
static const xx_data_struct_field_desc sxcodeplayers_bd_subsong_fields[]={
 SX_FIELD("channel0_position_offset","uint16",0,2,SX_OFFSET),
 SX_FIELD("channel1_position_offset","uint16",2,2,SX_OFFSET),
 SX_FIELD("channel2_position_offset","uint16",4,2,SX_OFFSET),
 SX_FIELD("channel3_position_offset","uint16",6,2,SX_OFFSET),
};
static const sx_layout sxcodeplayers_bd_subsong={UINT32_C(0x60A10001),"bd_subsong",sxcodeplayers_bd_subsong_fields,SX_COUNT(sxcodeplayers_bd_subsong_fields),SX_BE};
static const xx_data_struct_field_desc sxcodeplayers_bd_track_offset_fields[]={
 SX_FIELD("track_offset","uint16",0,2,SX_OFFSET),
};
static const sx_layout sxcodeplayers_bd_track_offset={UINT32_C(0x60A10002),"bd_track_offset",sxcodeplayers_bd_track_offset_fields,SX_COUNT(sxcodeplayers_bd_track_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxcodeplayers_bd_sample_offset_fields[]={
 SX_FIELD("sample_info_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxcodeplayers_bd_sample_offset={UINT32_C(0x60A10003),"bd_sample_offset",sxcodeplayers_bd_sample_offset_fields,SX_COUNT(sxcodeplayers_bd_sample_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxcodeplayers_bd_sample_fields[]={
 SX_FIELD("sample_data_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("loop_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("length_words","uint16",8,2,SX_NONE),
 SX_FIELD("loop_length_words","uint16",10,2,SX_NONE),
 SX_FIELD("volume","uint16",12,2,SX_NONE),
 SX_FIELD("volume_fade_speed","int16",14,2,SX_NONE),
 SX_FIELD("portamento_duration","int16",16,2,SX_NONE),
 SX_FIELD("portamento_add_value","int16",18,2,SX_NONE),
 SX_FIELD("vibrato_depth","uint16",20,2,SX_NONE),
 SX_FIELD("vibrato_add_value","uint16",22,2,SX_NONE),
 SX_FIELD("note_transpose","int16",24,2,SX_NONE),
 SX_FIELD("finetune_period","uint16",26,2,SX_NONE),
};
static const sx_layout sxcodeplayers_bd_sample={UINT32_C(0x60A10004),"bd_sample",sxcodeplayers_bd_sample_fields,SX_COUNT(sxcodeplayers_bd_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxcodeplayers_dw_speed_fields[]={
 SX_FIELD("speed","uint16",0,2,SX_NONE),
};
static const sx_layout sxcodeplayers_dw_speed={UINT32_C(0x60A10005),"dw_speed",sxcodeplayers_dw_speed_fields,SX_COUNT(sxcodeplayers_dw_speed_fields),SX_BE};
static const xx_data_struct_field_desc sxcodeplayers_dw_delay_speed_fields[]={
 SX_FIELD("speed","uint8",0,1,SX_NONE),
 SX_FIELD("delay_speed","uint8",1,1,SX_NONE),
};
static const sx_layout sxcodeplayers_dw_delay_speed={UINT32_C(0x60A10006),"dw_delay_speed",sxcodeplayers_dw_delay_speed_fields,SX_COUNT(sxcodeplayers_dw_delay_speed_fields),SX_BE};
static const xx_data_struct_field_desc sxcodeplayers_dw_position_offset_fields[]={
 SX_FIELD("position_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxcodeplayers_dw_position_offset={UINT32_C(0x60A10007),"dw_position_offset",sxcodeplayers_dw_position_offset_fields,SX_COUNT(sxcodeplayers_dw_position_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxcodeplayers_dw_sample32_fields[]={
 SX_FIELD("sample_pointer","uint32",0,4,SX_POINTER),
 SX_FIELD("loop_start","int32",4,4,SX_OFFSET),
 SX_FIELD("length_words","uint16",8,2,SX_NONE),
 SX_FIELD("padding","bytes",10,2,SX_NONE),
 SX_FIELD("finetune_period","uint16",12,2,SX_NONE),
 SX_FIELD("volume","uint16",14,2,SX_NONE),
};
static const sx_layout sxcodeplayers_dw_sample32={UINT32_C(0x60A10008),"dw_sample32",sxcodeplayers_dw_sample32_fields,SX_COUNT(sxcodeplayers_dw_sample32_fields),SX_BE};
static const xx_data_struct_field_desc sxcodeplayers_dw_sample_data_fields[]={
 SX_FIELD("sample_bytes","uint32",0,4,SX_SIZE),
 SX_FIELD("frequency_hz","uint16",4,2,SX_NONE),
};
static const sx_layout sxcodeplayers_dw_sample_data={UINT32_C(0x60A10009),"dw_sample_data",sxcodeplayers_dw_sample_data_fields,SX_COUNT(sxcodeplayers_dw_sample_data_fields),SX_BE};
static const xx_data_struct_field_desc sxcodeplayers_avp_subsong_fields[]={
 SX_FIELD("channel0_position_offset","uint16",0,2,SX_OFFSET),
 SX_FIELD("channel1_position_offset","uint16",2,2,SX_OFFSET),
 SX_FIELD("channel2_position_offset","uint16",4,2,SX_OFFSET),
 SX_FIELD("channel3_position_offset","uint16",6,2,SX_OFFSET),
 SX_FIELD("speed_variation0","int8",8,1,SX_NONE),
 SX_FIELD("speed_variation1","int8",9,1,SX_NONE),
 SX_FIELD("speed_variation2","int8",10,1,SX_NONE),
 SX_FIELD("speed_variation3","int8",11,1,SX_NONE),
 SX_FIELD("speed_variation4","int8",12,1,SX_NONE),
 SX_FIELD("speed_variation5","int8",13,1,SX_NONE),
 SX_FIELD("speed_variation6","int8",14,1,SX_NONE),
 SX_FIELD("speed_variation7","int8",15,1,SX_NONE),
};
static const sx_layout sxcodeplayers_avp_subsong={UINT32_C(0x60A1000A),"avp_subsong",sxcodeplayers_avp_subsong_fields,SX_COUNT(sxcodeplayers_avp_subsong_fields),SX_BE};
static const xx_data_struct_field_desc sxcodeplayers_avp_track_offset_fields[]={
 SX_FIELD("track_offset","int16",0,2,SX_OFFSET),
};
static const sx_layout sxcodeplayers_avp_track_offset={UINT32_C(0x60A1000B),"avp_track_offset",sxcodeplayers_avp_track_offset_fields,SX_COUNT(sxcodeplayers_avp_track_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxcodeplayers_avp_envelope_fields[]={
 SX_FIELD("point0_wait","uint8",0,1,SX_NONE),
 SX_FIELD("point0_increment","int8",1,1,SX_NONE),
 SX_FIELD("point0_repeat","uint8",2,1,SX_NONE),
 SX_FIELD("point1_wait","uint8",3,1,SX_NONE),
 SX_FIELD("point1_increment","int8",4,1,SX_NONE),
 SX_FIELD("point1_repeat","uint8",5,1,SX_NONE),
 SX_FIELD("point2_wait","uint8",6,1,SX_NONE),
 SX_FIELD("point2_increment","int8",7,1,SX_NONE),
 SX_FIELD("point2_repeat","uint8",8,1,SX_NONE),
 SX_FIELD("point3_wait","uint8",9,1,SX_NONE),
 SX_FIELD("point3_increment","int8",10,1,SX_NONE),
 SX_FIELD("point3_repeat","uint8",11,1,SX_NONE),
 SX_FIELD("point4_wait","uint8",12,1,SX_NONE),
 SX_FIELD("point4_increment","int8",13,1,SX_NONE),
 SX_FIELD("point4_repeat","uint8",14,1,SX_NONE),
 SX_FIELD("trailing_wait","uint8",15,1,SX_NONE),
};
static const sx_layout sxcodeplayers_avp_envelope={UINT32_C(0x60A1000C),"avp_envelope",sxcodeplayers_avp_envelope_fields,SX_COUNT(sxcodeplayers_avp_envelope_fields),SX_BE};
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
static const sx_layout sxcodeplayers_avp_instrument1={UINT32_C(0x60A1000D),"avp_instrument1",sxcodeplayers_avp_instrument1_fields,SX_COUNT(sxcodeplayers_avp_instrument1_fields),SX_BE};
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
static const sx_layout sxcodeplayers_avp_instrument2={UINT32_C(0x60A1000E),"avp_instrument2",sxcodeplayers_avp_instrument2_fields,SX_COUNT(sxcodeplayers_avp_instrument2_fields),SX_BE};
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
static const sx_layout sxcodeplayers_avp_instrument3={UINT32_C(0x60A1000F),"avp_instrument3",sxcodeplayers_avp_instrument3_fields,SX_COUNT(sxcodeplayers_avp_instrument3_fields),SX_BE};
static const xx_data_struct_field_desc sxcodeplayers_avp_sample_offset_fields[]={
 SX_FIELD("sample_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxcodeplayers_avp_sample_offset={UINT32_C(0x60A10010),"avp_sample_offset",sxcodeplayers_avp_sample_offset_fields,SX_COUNT(sxcodeplayers_avp_sample_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxcodeplayers_avp_sample_fields[]={
 SX_FIELD("length_words","uint16",0,2,SX_NONE),
 SX_FIELD("loop_start","uint16",2,2,SX_OFFSET),
 SX_FIELD("loop_length_words","uint16",4,2,SX_NONE),
};
static const sx_layout sxcodeplayers_avp_sample={UINT32_C(0x60A10011),"avp_sample",sxcodeplayers_avp_sample_fields,SX_COUNT(sxcodeplayers_avp_sample_fields),SX_BE};
static const sx_layout *const sx_codeplayers_layouts[]={
 &sxcodeplayers_bd_subsong,
 &sxcodeplayers_bd_track_offset,
 &sxcodeplayers_bd_sample_offset,
 &sxcodeplayers_bd_sample,
 &sxcodeplayers_dw_speed,
 &sxcodeplayers_dw_delay_speed,
 &sxcodeplayers_dw_position_offset,
 &sxcodeplayers_dw_sample32,
 &sxcodeplayers_dw_sample_data,
 &sxcodeplayers_avp_subsong,
 &sxcodeplayers_avp_track_offset,
 &sxcodeplayers_avp_envelope,
 &sxcodeplayers_avp_instrument1,
 &sxcodeplayers_avp_instrument2,
 &sxcodeplayers_avp_instrument3,
 &sxcodeplayers_avp_sample_offset,
 &sxcodeplayers_avp_sample,
};
/* Retained loaders authenticate metadata through these bounded instruction
 * forms. Instructions and runtime-only state are never emitted as fields. */
typedef struct{sx_context*c;uint64_t end;size_t code_size;uint8_t code[0x4000];unsigned work;}sxcodeplayers_view;
static bool sxcodeplayers_span(sxcodeplayers_view*v,uint64_t p,uint64_t n){return p<=v->end&&n<=v->end-p&&!xx_pd_is_stopped(v->c->pd);}
static bool sxcodeplayers_read(sxcodeplayers_view*v,uint64_t p,void*b,size_t n){return ++v->work<=1000000&&sxcodeplayers_span(v,p,n)&&sx_read(v->c,(int64_t)p,b,n);}
static uint16_t sxcodeplayers_be16(const uint8_t*b){return (uint16_t)((uint16_t)b[0]<<8)|b[1];}
static uint32_t sxcodeplayers_be32(const uint8_t*b){return (uint32_t)b[0]<<24|(uint32_t)b[1]<<16|(uint32_t)b[2]<<8|b[3];}
static bool sxcodeplayers_u(sxcodeplayers_view*v,uint64_t p,unsigned n,uint64_t*out){uint8_t b[4];if(!n||n>4||!sxcodeplayers_read(v,p,b,n))return false;*out=0;for(unsigned i=0;i<n;i++)*out=(*out<<8)|b[i];return true;}
static bool sxcodeplayers_eq(sxcodeplayers_view*v,size_t p,const char*b,size_t n){return p<=v->code_size&&n<=v->code_size-p&&!xx_rt_memcmp(v->code+p,b,n);}
static size_t sxcodeplayers_find(sxcodeplayers_view*v,size_t p,size_t end,const char*b,size_t n){if(end>v->code_size)end=v->code_size;for(;p<=end&&n<=end-p;p+=2){if(++v->work>1000000||xx_pd_is_stopped(v->c->pd))break;if(sxcodeplayers_eq(v,p,b,n))return p;}return SIZE_MAX;}
static bool sxcodeplayers_ref(sxcodeplayers_view*v,size_t p,uint64_t*out){if(p>v->code_size||v->code_size-p<2)return false;int32_t d=sxcodeplayers_be16(v->code+p);if(d>=32768)d-=65536;int64_t q=(int64_t)p+d;if(q<0||(uint64_t)q>=v->end)return false;*out=(uint64_t)q;return true;}
static bool sxcodeplayers_put(sxcodeplayers_view*v,const sx_layout*l,uint64_t p,uint64_t count){const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(!count)return true;if(!z||count>UINT64_MAX/z||!sxcodeplayers_span(v,p,count*z)||++v->work>1000000)return false;if(v->c->count>=24000)return true;uint64_t end=p+count*z;for(size_t i=0;i<v->c->count;i++){uint64_t q=(uint64_t)(v->c->items[i].offset-v->c->f->base_address),n=(uint64_t)v->c->items[i].total_size;if(p<q+n&&q<end)return true;}return count==1?sx_add(v->c,l,(int64_t)p,(int64_t)z):sx_table(v->c,l,(int64_t)p,(int64_t)z,(int64_t)count);}
#define SCP_PUT(n,p,c) sxcodeplayers_put(v,&sxcodeplayers_##n,p,c)
static bool sxcodeplayers_bd(sxcodeplayers_view*v){
 uint64_t init,play,sub,smp,table,tracks;size_t a=SIZE_MAX,b=SIZE_MAX,p;
 if(!sxcodeplayers_eq(v,0,"\x60\0",2)||!sxcodeplayers_eq(v,4,"\x60\0",2)||!sxcodeplayers_eq(v,10,"\x60\0",2)||!sxcodeplayers_ref(v,2,&init)||!sxcodeplayers_ref(v,6,&play)||!sxcodeplayers_eq(v,(size_t)init,"\x3f\0\x61\0",4)||!sxcodeplayers_eq(v,(size_t)init+6,"\x3d\x7c",2)||!sxcodeplayers_eq(v,(size_t)init+12,"\x41\xfa",2))return false;
 for(p=(size_t)init;p+6<=v->code_size;p+=2)if(sxcodeplayers_eq(v,p,"\x41\xfa",2)&&sxcodeplayers_eq(v,p+4,"\x22\x08",2)){a=p;break;}
 if(a==SIZE_MAX||!sxcodeplayers_ref(v,a+2,&sub))return false;
 for(p=a+4;p+6<=v->code_size;p+=2)if(sxcodeplayers_eq(v,p,"\x41\xfa",2)&&sxcodeplayers_eq(v,p+4,"\x23\x48",2)){b=p;break;}
 if(b==SIZE_MAX||!sxcodeplayers_ref(v,b+2,&smp))return false;
 a=SIZE_MAX;for(p=(size_t)play;p+6<=v->code_size;p+=2)if(sxcodeplayers_eq(v,p,"\x47\xfa",2)&&(sxcodeplayers_eq(v,p+4,"\x48\x80",2)||sxcodeplayers_eq(v,p+4,"\xd0\x40",2))){a=p;break;}
 if(a==SIZE_MAX||!sxcodeplayers_ref(v,a+2,&table))return false;
 b=SIZE_MAX;for(p=a+4;p+6<=v->code_size;p+=2)if(sxcodeplayers_eq(v,p,"\x47\xfa",2)&&sxcodeplayers_eq(v,p+4,"\xd6\xc0",2)){b=p;break;}
 if(b==SIZE_MAX||!sxcodeplayers_ref(v,b+2,&tracks))return false;
 uint64_t end=v->end,pos=sub;for(unsigned i=0;i<256&&pos<end;i++,pos+=8){uint8_t row[8];if(!sxcodeplayers_read(v,pos,row,8))break;bool good=true;for(unsigned j=0;j<4;j++){uint64_t off=sxcodeplayers_be16(row+2*j);if(off>v->end-sub||off<8){good=false;break;}if(sub+off<end)end=sub+off;}if(!good||pos>end||8>end-pos)break;if(!SCP_PUT(bd_subsong,pos,1))return false;}
 if(table<sub&&(sub-table)%2==0&&(sub-table)/2<=4096&&!SCP_PUT(bd_track_offset,table,(sub-table)/2))return false;
 uint64_t offsets[256],n=0,first=v->end-smp;
 while(n<256&&n*4<first){uint64_t x;if(!sxcodeplayers_u(v,smp+n*4,4,&x)||x<4||x>v->end-smp)break;if(x<first)first=x;if((n+1)*4>first)break;offsets[n++]=x;}
 if(!n||n*4!=first)return true;if(!SCP_PUT(bd_sample_offset,smp,n))return false;
 for(uint64_t i=0;i<n;i++)if(sxcodeplayers_span(v,smp+offsets[i],28)&&!SCP_PUT(bd_sample,smp+offsets[i],1))return false;
 (void)tracks;return true;
}
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
static int sxcodeplayers_order(const void*aa,const void*bb){const xx_data_struct*a=aa,*b=bb;return a->offset<b->offset?-1:a->offset>b->offset?1:0;}
static bool sxcodeplayers_finish(sx_context*c){size_t n=c->count;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxcodeplayers_order);for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(p<end||z<=0||p>c->size||z>c->size-p)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+z;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxcodeplayers_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
static bool sx_codeplayers_supports(xx_file_type_t t){switch(t){case XX_FILE_TYPE_DIE_MUSIC_BENDAGLISH_BD:case XX_FILE_TYPE_DIE_MUSIC_DAVIDWHITTAKER_DW:case XX_FILE_TYPE_DIE_MUSIC_WALKER_ACTIVISIONPRO:return true;default:return false;}}
static bool sx_codeplayers_build(sx_context*c){if(!c||!c->f||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid||c->size<=0)return false;sxcodeplayers_view v;v.c=c;v.end=(uint64_t)c->size;v.work=0;v.code_size=v.end<sizeof(v.code)?(size_t)v.end:sizeof(v.code);if(!sx_read(c,0,v.code,v.code_size))return false;switch(c->f->file_type){case XX_FILE_TYPE_DIE_MUSIC_BENDAGLISH_BD:(void)sxcodeplayers_bd(&v);break;case XX_FILE_TYPE_DIE_MUSIC_DAVIDWHITTAKER_DW:(void)sxcodeplayers_dw(&v);break;case XX_FILE_TYPE_DIE_MUSIC_WALKER_ACTIVISIONPRO:(void)sxcodeplayers_avp(&v);break;default:return false;}if(c->failed||xx_pd_is_stopped(c->pd))return false;return c->count?sxcodeplayers_finish(c):sx_raw(c,0,c->size);}
#undef SCP_PUT
static bool sx_codeplayers_comment(xx_data_struct_record*r,uint32_t id){
 if(!r||!r->name||id<UINT32_C(0x60a10001)||id>UINT32_C(0x60a1ffff)||r->value.type==XX_VAR_TYPE_FLOAT||r->value.type==XX_VAR_TYPE_DOUBLE)return true;
 const wchar_t*n=r->name;
 if(id==sxcodeplayers_bd_subsong.id)return xx_data_struct_record_set_comment(r,L"Byte offset relative to the authenticated Ben Daglish subsong-table origin; position command bytes remain raw.");
 if(id==sxcodeplayers_bd_track_offset.id)return xx_data_struct_record_set_comment(r,L"Byte offset relative to the separately authenticated track-data origin.");
 if(id==sxcodeplayers_bd_sample_offset.id||(id==sxcodeplayers_bd_sample.id&&(!xx_rt_wcscmp(n,L"sample_data_offset")||!xx_rt_wcscmp(n,L"loop_offset"))))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the authenticated sample-info offset-table origin. Zero loop offset disables looping.");
 if(!xx_rt_wcscmp(n,L"length_words")||!xx_rt_wcscmp(n,L"loop_length_words"))return xx_data_struct_record_set_comment(r,L"Stored length in two-byte words, preserved without conversion to bytes. Loop-length sentinel semantics depend on the player variant.");
 if(id==sxcodeplayers_dw_sample32.id&&!xx_rt_wcscmp(n,L"sample_pointer"))return xx_data_struct_record_set_comment(r,L"Stored sample-address slot. The loader replaces runtime pointers using the separate sample-data blocks; this is not followed as a physical file offset.");
 if(id==sxcodeplayers_dw_sample32.id&&!xx_rt_wcscmp(n,L"loop_start"))return xx_data_struct_record_set_comment(r,L"Signed sample-relative byte offset; -1 disables looping. Original stored value is retained.");
 if(id==sxcodeplayers_dw_position_offset.id)return xx_data_struct_record_set_comment(r,L"Byte offset relative to the authenticated player-global origin, not the start of this pointer table.");
 if(id==sxcodeplayers_dw_sample_data.id&&!xx_rt_wcscmp(n,L"frequency_hz"))return xx_data_struct_record_set_comment(r,L"Stored sample playback frequency in Hz; the player derives a period from 3579545 / frequency.");
 if(id==sxcodeplayers_avp_subsong.id){if(!xx_rt_wcsncmp(n,L"channel",7))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the separately authenticated position-list origin.");return xx_data_struct_record_set_comment(r,L"Signed stored speed-variation byte; playback sequence interpretation depends on the authenticated player variant.");}
 if(id==sxcodeplayers_avp_track_offset.id)return xx_data_struct_record_set_comment(r,L"Signed byte offset relative to the track-data origin. Negative entries are unused sentinels and are not followed.");
 if(id==sxcodeplayers_avp_sample_offset.id)return xx_data_struct_record_set_comment(r,L"Byte offset relative to the separately authenticated sample-data origin; the 28th entry marks the end after 27 sample slots.");
 if(id==sxcodeplayers_avp_sample.id&&!xx_rt_wcscmp(n,L"loop_start"))return xx_data_struct_record_set_comment(r,L"Sample-relative byte offset, unlike the length and repeat-length words in this record.");
 if(!xx_rt_wcscmp(n,L"sample_start_offset"))return xx_data_struct_record_set_comment(r,L"Sample-relative byte offset used by the version3 instrument player; retained separately from hardware word lengths.");
 if(id==sxcodeplayers_avp_envelope.id){if(!xx_rt_wcscmp(n,L"trailing_wait"))return xx_data_struct_record_set_comment(r,L"Physical trailing envelope byte. The maintained player may use it as a sixth wait counter; its synthetic increment/repeat values have no serialized fields.");if((xx_rt_wcschr(n,L'_')&&!xx_rt_wcscmp(xx_rt_wcschr(n,L'_')+1,L"increment")))return xx_data_struct_record_set_comment(r,L"Signed volume increment at this stored envelope point.");return xx_data_struct_record_set_comment(r,L"Stored envelope wait/repetition control byte; playback applies its original sentinel behavior.");}
 if(!xx_rt_wcscmp(n,L"volume"))return xx_data_struct_record_set_comment(r,L"Stored player volume control; usual Amiga hardware volume range is 0..64.");
 if(!xx_rt_wcsncmp(n,L"arpeggio",8)||!xx_rt_wcscmp(n,L"transpose")||!xx_rt_wcscmp(n,L"note_transpose"))return xx_data_struct_record_set_comment(r,L"Signed stored note adjustment; no derived note or frequency is substituted.");
 if(!xx_rt_wcscmp(n,L"finetune_period"))return xx_data_struct_record_set_comment(r,L"Stored sample period control, retained before any runtime frequency or note conversion.");
 return true;
}
