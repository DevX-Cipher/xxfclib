/* Copyright (c)2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical music header and table metadata; compressed and unknown bodies stay raw. */
static const xx_data_struct_field_desc sxmodv_di_header_fields[]={
 SX_FIELD("sample_count","uint16",0,2,SX_COUNT_PROP),
 SX_FIELD("order_offset","uint32",2,4,SX_OFFSET),
 SX_FIELD("pattern_data_offset","uint32",6,4,SX_OFFSET),
 SX_FIELD("sample_data_offset","uint32",10,4,SX_OFFSET),
};
static const sx_layout sxmodv_di_header={UINT32_C(0x609B0001),"di_header",sxmodv_di_header_fields,SX_COUNT(sxmodv_di_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmodv_mod_compact_sample_fields[]={
 SX_FIELD("length_words","uint16",0,2,SX_NONE),
 SX_FIELD("finetune","uint8",2,1,SX_NONE),
 SX_FIELD("volume","uint8",3,1,SX_NONE),
 SX_FIELD("loop_start_words","uint16",4,2,SX_NONE),
 SX_FIELD("loop_length_words","uint16",6,2,SX_NONE),
};
static const sx_layout sxmodv_mod_compact_sample={UINT32_C(0x609B0002),"mod_compact_sample",sxmodv_mod_compact_sample_fields,SX_COUNT(sxmodv_mod_compact_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxmodv_di_pattern_offset_fields[]={
 SX_FIELD("pattern_offset","uint16",0,2,SX_OFFSET),
};
static const sx_layout sxmodv_di_pattern_offset={UINT32_C(0x609B0003),"di_pattern_offset",sxmodv_di_pattern_offset_fields,SX_COUNT(sxmodv_di_pattern_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxmodv_mod_order_fields[]={
 SX_FIELD("pattern_index","uint8",0,1,SX_ID),
};
static const sx_layout sxmodv_mod_order={UINT32_C(0x609B0004),"mod_order",sxmodv_mod_order_fields,SX_COUNT(sxmodv_mod_order_fields),SX_BE};
static const xx_data_struct_field_desc sxmodv_di_orders_end_fields[]={
 SX_FIELD("end_marker","uint8",0,1,SX_ID),
};
static const sx_layout sxmodv_di_orders_end={UINT32_C(0x609B0005),"di_orders_end",sxmodv_di_orders_end_fields,SX_COUNT(sxmodv_di_orders_end_fields),SX_BE};
static const xx_data_struct_field_desc sxmodv_di_blank_fields[]={
 SX_FIELD("blank_marker","uint8",0,1,SX_ID),
};
static const sx_layout sxmodv_di_blank={UINT32_C(0x609B0006),"di_blank",sxmodv_di_blank_fields,SX_COUNT(sxmodv_di_blank_fields),SX_BE};
static const xx_data_struct_field_desc sxmodv_di_event_fields[]={
 SX_FIELD("sample_note_control","uint8",0,1,SX_FLAGS),
 SX_FIELD("note_effect","uint8",1,1,SX_FLAGS),
};
static const sx_layout sxmodv_di_event={UINT32_C(0x609B0007),"di_event",sxmodv_di_event_fields,SX_COUNT(sxmodv_di_event_fields),SX_BE};
static const xx_data_struct_field_desc sxmodv_di_event_value_fields[]={
 SX_FIELD("sample_note_control","uint8",0,1,SX_FLAGS),
 SX_FIELD("note_effect","uint8",1,1,SX_FLAGS),
 SX_FIELD("effect_parameter","uint8",2,1,SX_NONE),
};
static const sx_layout sxmodv_di_event_value={UINT32_C(0x609B0008),"di_event_value",sxmodv_di_event_value_fields,SX_COUNT(sxmodv_di_event_value_fields),SX_BE};
static const xx_data_struct_field_desc sxmodv_pha_sample_fields[]={
 SX_FIELD("length_words","uint16",0,2,SX_NONE),
 SX_FIELD("unknown","uint8",2,1,SX_NONE),
 SX_FIELD("volume","uint8",3,1,SX_NONE),
 SX_FIELD("loop_start_words","uint16",4,2,SX_NONE),
 SX_FIELD("loop_length_words","uint16",6,2,SX_NONE),
 SX_FIELD("sample_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("finetune_times_72","uint16",12,2,SX_NONE),
};
static const sx_layout sxmodv_pha_sample={UINT32_C(0x609B0009),"pha_sample",sxmodv_pha_sample_fields,SX_COUNT(sxmodv_pha_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxmodv_pha_control_fields[]={
 SX_FIELD("unknown0","bytes",0,2,SX_NONE),
 SX_FIELD("position_table_bytes","uint16",2,2,SX_SIZE),
 SX_FIELD("unknown4","bytes",4,10,SX_NONE),
};
static const sx_layout sxmodv_pha_control={UINT32_C(0x609B000A),"pha_control",sxmodv_pha_control_fields,SX_COUNT(sxmodv_pha_control_fields),SX_BE};
static const xx_data_struct_field_desc sxmodv_pha_pattern_offset_fields[]={
 SX_FIELD("pattern_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxmodv_pha_pattern_offset={UINT32_C(0x609B000B),"pha_pattern_offset",sxmodv_pha_pattern_offset_fields,SX_COUNT(sxmodv_pha_pattern_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxmodv_soundtracker_title_fields[]={
 SX_FIELD("title","char[20]",0,20,SX_NONE),
};
static const sx_layout sxmodv_soundtracker_title={UINT32_C(0x609B000C),"soundtracker_title",sxmodv_soundtracker_title_fields,SX_COUNT(sxmodv_soundtracker_title_fields),SX_BE};
static const xx_data_struct_field_desc sxmodv_soundtracker_sample_fields[]={
 SX_FIELD("name","char[22]",0,22,SX_NONE),
 SX_FIELD("length_words","uint16",22,2,SX_NONE),
 SX_FIELD("finetune_control","uint8",24,1,SX_NONE),
 SX_FIELD("volume","uint8",25,1,SX_NONE),
 SX_FIELD("loop_start_encoded","uint16",26,2,SX_NONE),
 SX_FIELD("loop_length_words","uint16",28,2,SX_NONE),
};
static const sx_layout sxmodv_soundtracker_sample={UINT32_C(0x609B000D),"soundtracker_sample",sxmodv_soundtracker_sample_fields,SX_COUNT(sxmodv_soundtracker_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxmodv_soundtracker_controls_fields[]={
 SX_FIELD("song_length","uint8",0,1,SX_COUNT_PROP),
 SX_FIELD("tempo_control","uint8",1,1,SX_NONE),
};
static const sx_layout sxmodv_soundtracker_controls={UINT32_C(0x609B000E),"soundtracker_controls",sxmodv_soundtracker_controls_fields,SX_COUNT(sxmodv_soundtracker_controls_fields),SX_BE};
static const xx_data_struct_field_desc sxmodv_soundtracker_cell_fields[]={
 SX_FIELD("reserved_period_high","uint8",0,1,SX_FLAGS),
 SX_FIELD("period_low","uint8",1,1,SX_NONE),
 SX_FIELD("sample_low_effect","uint8",2,1,SX_FLAGS),
 SX_FIELD("effect_parameter","uint8",3,1,SX_NONE),
};
static const sx_layout sxmodv_soundtracker_cell={UINT32_C(0x609B000F),"soundtracker_cell",sxmodv_soundtracker_cell_fields,SX_COUNT(sxmodv_soundtracker_cell_fields),SX_BE};
static const xx_data_struct_field_desc sxmodv_mfp_controls_fields[]={
 SX_FIELD("song_length","uint8",0,1,SX_COUNT_PROP),
 SX_FIELD("restart","uint8",1,1,SX_ID),
};
static const sx_layout sxmodv_mfp_controls={UINT32_C(0x609B0010),"mfp_controls",sxmodv_mfp_controls_fields,SX_COUNT(sxmodv_mfp_controls_fields),SX_BE};
static const xx_data_struct_field_desc sxmodv_mfp_counts_fields[]={
 SX_FIELD("position_count","uint16",0,2,SX_COUNT_PROP),
 SX_FIELD("position_count_copy","uint16",2,2,SX_COUNT_PROP),
};
static const sx_layout sxmodv_mfp_counts={UINT32_C(0x609B0011),"mfp_counts",sxmodv_mfp_counts_fields,SX_COUNT(sxmodv_mfp_counts_fields),SX_BE};
static const xx_data_struct_field_desc sxmodv_mfp_channels_fields[]={
 SX_FIELD("channel_a_offset","int16",0,2,SX_OFFSET),
 SX_FIELD("channel_b_offset","int16",2,2,SX_OFFSET),
 SX_FIELD("channel_c_offset","int16",4,2,SX_OFFSET),
 SX_FIELD("channel_d_offset","int16",6,2,SX_OFFSET),
};
static const sx_layout sxmodv_mfp_channels={UINT32_C(0x609B0012),"mfp_channels",sxmodv_mfp_channels_fields,SX_COUNT(sxmodv_mfp_channels_fields),SX_BE};
static const sx_layout *const sx_modvariants_layouts[]={
 &sxmodv_di_header,
 &sxmodv_mod_compact_sample,
 &sxmodv_di_pattern_offset,
 &sxmodv_mod_order,
 &sxmodv_di_orders_end,
 &sxmodv_di_blank,
 &sxmodv_di_event,
 &sxmodv_di_event_value,
 &sxmodv_pha_sample,
 &sxmodv_pha_control,
 &sxmodv_pha_pattern_offset,
 &sxmodv_soundtracker_title,
 &sxmodv_soundtracker_sample,
 &sxmodv_soundtracker_controls,
 &sxmodv_soundtracker_cell,
 &sxmodv_mfp_controls,
 &sxmodv_mfp_counts,
 &sxmodv_mfp_channels,
};
/* Stored big-endian MOD variants. Native identity is a prerequisite, and all
 * physical spans below are checked again before being declared. */
typedef struct sxmodv_view {sx_context*c;uint64_t end;unsigned work;}sxmodv_view;
static bool sxmodv_span(sxmodv_view*v,uint64_t p,uint64_t n){return !xx_pd_is_stopped(v->c->pd)&&p<=v->end&&n<=v->end-p;}
static bool sxmodv_word(sxmodv_view*v,uint64_t p,unsigned n,uint64_t*x){uint8_t b[4];if(++v->work>1000000||!n||n>4||!sxmodv_span(v,p,n)||!sx_read(v->c,(int64_t)p,b,n))return false;*x=0;for(unsigned i=0;i<n;i++)*x=(*x<<8)|b[i];return true;}
static bool sxmodv_row(sxmodv_view*v,const sx_layout*l,uint64_t p){const xx_data_struct_field_desc*f=&l->fields[l->field_count-1];uint64_t n=(uint64_t)(f->rel_offset+f->size);return ++v->work<=1000000&&sxmodv_span(v,p,n)&&(v->c->count>=24000||sx_add(v->c,l,(int64_t)p,(int64_t)n));}
#define SMV_ROW(n,p) sxmodv_row(v,&sxmodv_##n,p)
static bool sxmodv_di_pattern(sxmodv_view*v,uint64_t p,uint64_t limit){
 if(p>=limit||limit>v->end)return false;
 for(unsigned row=0;row<64;row++){bool stop=false;for(unsigned ch=0;ch<4;ch++){
  uint64_t a,b;unsigned n;if(!sxmodv_word(v,p,1,&a))return false;
  if(a==255){if(p>=limit||!SMV_ROW(di_blank,p))return false;p++;continue;}
  n=a<128?2:3;if(p>limit||n>limit-p||!sxmodv_word(v,p+1,1,&b))return false;
  if((b&15)==11||(b&15)==13)stop=true;
  if(!sxmodv_row(v,n==2?&sxmodv_di_event:&sxmodv_di_event_value,p))return false;p+=n;
 }if(stop)break;}return true;
}
static bool sxmodv_di(sxmodv_view*v){
 uint64_t ns,orders,patterns,samples,x,np=0,norder=0,table,ends;
 if(!SMV_ROW(di_header,0)||!sxmodv_word(v,0,2,&ns)||ns>31||!sxmodv_word(v,2,4,&orders)||!sxmodv_word(v,6,4,&patterns)||!sxmodv_word(v,10,4,&samples))return false;
 table=14+ns*8;if(orders<table||patterns<=orders||samples<=patterns||samples>v->end||patterns-orders>129||!sxmodv_span(v,14,ns*8))return false;
 for(uint64_t i=0;i<ns;i++)if(!SMV_ROW(mod_compact_sample,14+i*8))return false;
 ends=orders;for(;ends<patterns&&norder<128;ends++,norder++){if(!sxmodv_word(v,ends,1,&x))return false;if(x==255)break;if(x>=128)return false;if(np<x+1)np=x+1;if(!SMV_ROW(mod_order,ends))return false;}
 if(!sxmodv_word(v,ends,1,&x)||x!=255||ends+1!=patterns||!SMV_ROW(di_orders_end,ends)||!np||np*2>orders-table)return false;
 uint64_t pointers[128];for(uint64_t i=0;i<np;i++){if(!sxmodv_word(v,table+i*2,2,&pointers[i])||!SMV_ROW(di_pattern_offset,table+i*2))return false;}
 for(uint64_t i=0;i<np;i++){
  uint64_t p=pointers[i],end=samples;bool duplicate=false;for(uint64_t j=0;j<i;j++)if(pointers[j]==p)duplicate=true;if(duplicate||p<patterns||p>=samples)continue;
  for(uint64_t j=0;j<np;j++)if(pointers[j]>p&&pointers[j]<end)end=pointers[j];
  (void)sxmodv_di_pattern(v,p,end);
 }return true;
}
static bool sxmodv_pha(sxmodv_view*v){
 if(!sxmodv_span(v,0,960))return false;
 for(unsigned i=0;i<31;i++)if(!SMV_ROW(pha_sample,i*14))return false;
 if(!SMV_ROW(pha_control,434))return false;
 for(unsigned i=0;i<128;i++)if(!SMV_ROW(pha_pattern_offset,448+i*4))return false;
 /* Repeated packed cells have player-state-dependent channel replication;
  * retain their physical bytes as raw instead of inventing decoded rows. */
 return true;
}
static bool sxmodv_soundtracker(sxmodv_view*v){
 uint64_t n=0,x;if(!SMV_ROW(soundtracker_title,0)||!sxmodv_span(v,20,580))return false;
 for(unsigned i=0;i<15;i++)if(!SMV_ROW(soundtracker_sample,20+i*30))return false;
 if(!SMV_ROW(soundtracker_controls,470))return false;
 /* The original loader scans every stored order slot to locate sample data. */
 for(unsigned i=0;i<128;i++){if(!sxmodv_word(v,472+i,1,&x)||!SMV_ROW(mod_order,472+i))return false;if(n<x+1)n=x+1;}
 if(n>64)return false;
 for(uint64_t i=0;i<n;i++)for(unsigned j=0;j<256;j++)if(!SMV_ROW(soundtracker_cell,600+i*1024+j*4))return false;
 return true;
}
static bool sxmodv_mfp(sxmodv_view*v){
 uint64_t count,copy;if(!sxmodv_span(v,0,382))return false;
 for(unsigned i=0;i<31;i++)if(!SMV_ROW(mod_compact_sample,i*8))return false;
 if(!SMV_ROW(mfp_controls,248))return false;
 for(unsigned i=0;i<128;i++)if(!SMV_ROW(mod_order,250+i))return false;
 if(!SMV_ROW(mfp_counts,378)||!sxmodv_word(v,378,2,&count)||!sxmodv_word(v,380,2,&copy)||count!=copy||!count||count>127||!sxmodv_span(v,382,count*8))return false;
 for(uint64_t i=0;i<count;i++)if(!SMV_ROW(mfp_channels,382+i*8))return false;
 /* Original ADDA.W uses signed displacements from382+8*count. Packed channel
  * bodies and the separate .smp companion have no invented physical members. */
 return true;
}
static int sxmodv_order(const void*aa,const void*bb){const xx_data_struct*a=aa,*b=bb;if(a->offset!=b->offset)return a->offset<b->offset?-1:1;return a->total_size<b->total_size?-1:a->total_size>b->total_size?1:0;}
static bool sxmodv_finish(sx_context*c){size_t n=c->count,keep=0;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxmodv_order);for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(at<end)continue;c->items[keep++]=c->items[i];end=at+z;}c->count=keep;n=keep;end=0;for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(at>end&&!sx_raw(c,end,at-end))return false;end=at+z;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxmodv_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
static bool sx_modvariants_supports(xx_file_type_t t){switch(t){case XX_FILE_TYPE_DIE_MUSIC_AZATOTH_PHAPACKER:case XX_FILE_TYPE_DIE_MUSIC_DIGITALILLUSIONSCREATIVEENT_DI:case XX_FILE_TYPE_DIE_MUSIC_OBI_SOUNDTRACKER_STK:case XX_FILE_TYPE_DIE_MUSIC_SOUTHERN_MAGNETICFIELDSPACKER:return true;default:return false;}}
static bool sx_modvariants_build(sx_context*c){if(!c||!c->f||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid||c->size<=0)return false;sxmodv_view v={c,(uint64_t)c->size,0};switch(c->f->file_type){case XX_FILE_TYPE_DIE_MUSIC_AZATOTH_PHAPACKER:(void)sxmodv_pha(&v);break;case XX_FILE_TYPE_DIE_MUSIC_DIGITALILLUSIONSCREATIVEENT_DI:(void)sxmodv_di(&v);break;case XX_FILE_TYPE_DIE_MUSIC_OBI_SOUNDTRACKER_STK:(void)sxmodv_soundtracker(&v);break;case XX_FILE_TYPE_DIE_MUSIC_SOUTHERN_MAGNETICFIELDSPACKER:(void)sxmodv_mfp(&v);break;default:return false;}return c->count&&sxmodv_finish(c);}
#undef SMV_ROW
static bool sx_modvariants_comment(xx_data_struct_record*r,uint32_t id){if(!r||!r->name||id<UINT32_C(0x609B0001)||id>=UINT32_C(0x609C0000))return true;const wchar_t*s=NULL;
#define SMV_N(n) (!xx_rt_wcscmp(r->name,L##n))
 if(id==sxmodv_mfp_channels.id)s=L"Signed channel-data byte displacement from module offset 382 + 8 * position_count; original player uses ADDA.W; packed bodies remain raw";
 else if(r->property&SX_OFFSET)s=L"Byte offset from the beginning of this module's physical file view";
 else if(SMV_N("length_words")||SMV_N("loop_length_words")||SMV_N("loop_start_words"))s=L"Stored in two-byte words; multiply by two for a byte length or loop position";
 else if(SMV_N("volume"))s=L"Amiga sample volume, 0..64";
 else if(SMV_N("finetune"))s=L"Stored MOD finetune nibble, 0..15; values 8..15 encode negative adjustments";
 else if(SMV_N("finetune_times_72"))s=L"Stored MOD finetune nibble multiplied by 72; preserved encoded value";
 else if(SMV_N("position_table_bytes"))s=L"Active bytes of the four-byte pattern-offset table; divide by four for active positions; 128 slots are physically stored";
 else if(id==sxmodv_mod_order.id)s=L"Zero-based pattern index; unused fixed-table slots are preserved";
 else if(id==sxmodv_di_orders_end.id)s=L"0xFF terminates the physical Digital Illusions order list";
 else if(id==sxmodv_di_blank.id)s=L"0xFF encodes one blank channel cell";
 else if(id==sxmodv_di_event.id||id==sxmodv_di_event_value.id){if(SMV_N("sample_note_control"))s=L"Bits 2..6 sample number; bits 0..1 high note bits; bit 7 adds a third effect-parameter byte";else if(SMV_N("note_effect"))s=L"High nibble low note bits; low nibble effect code; B/D stop after the current four-channel row";else s=L"Stored effect parameter; absent in the two-byte encoding";}
 else if(id==sxmodv_soundtracker_sample.id){if(SMV_N("finetune_control"))s=L"Physical control byte retained; early 15-sample SoundTracker variants do not share all later MOD finetune semantics";else if(SMV_N("loop_start_encoded"))s=L"Original encoded loop position; the retained SoundTracker IV player uses bytes, while later variants differ, so no unit conversion is assumed";}
 else if(id==sxmodv_soundtracker_controls.id&&SMV_N("tempo_control"))s=L"Stored SoundTracker timing/control byte; variant-dependent playback interpretation, not a timestamp";
 else if(id==sxmodv_mfp_controls.id&&SMV_N("restart"))s=L"Stored restart/control value; the native-supported Magnetic Fields Packer variant uses 127";
 else if(id==sxmodv_mfp_counts.id)s=L"Stored count of eight-byte channel-pointer rows; both physical copies are retained";
 else if(id==sxmodv_soundtracker_cell.id){if(SMV_N("reserved_period_high"))s=L"Upper nibble unused/reserved in the retained 15-sample player; lower nibble Amiga period high bits; sample number comes only from the third byte";else if(SMV_N("period_low"))s=L"Low eight bits of the Amiga playback period";else if(SMV_N("sample_low_effect"))s=L"High nibble sample number; low nibble effect code";else s=L"Effect-dependent unsigned parameter byte";}
 else if(SMV_N("song_length"))s=L"Count of active entries in the fixed 128-byte order table";
 if(!s&&(SMV_N("unknown")||SMV_N("unknown0")||SMV_N("unknown4")))s=L"Physically stored bytes skipped by the retained reference loader; no stronger semantics assumed";
#undef SMV_N
 return !s||xx_data_struct_record_set_comment(r,s);
}
