/* SPDX-License-Identifier: MIT. Independent physical V2M and DMO metadata layouts. */
static const xx_data_struct_field_desc sxsynt_v2m_header_fields[]={
 SX_FIELD("ticks_per_quarter","uint32",0,4,SX_NONE),
 SX_FIELD("maximum_time","uint32",4,4,SX_NONE),
 SX_FIELD("global_event_count","uint32",8,4,SX_COUNT_PROP),
};
static const sx_layout sxsynt_v2m_header={0x608e0001U,"v2m_header",sxsynt_v2m_header_fields,SX_COUNT(sxsynt_v2m_header_fields),SX_LE};
static const xx_data_struct_field_desc sxsynt_v2m_time_delta_low_plane_fields[]={
 SX_FIELD("time_delta_low","uint8",0,0,SX_NONE),
};
static const sx_layout sxsynt_v2m_time_delta_low_plane={0x608e0002U,"v2m_time_delta_low_plane",sxsynt_v2m_time_delta_low_plane_fields,SX_COUNT(sxsynt_v2m_time_delta_low_plane_fields),SX_LE};
static const xx_data_struct_field_desc sxsynt_v2m_time_delta_middle_plane_fields[]={
 SX_FIELD("time_delta_middle","uint8",0,0,SX_NONE),
};
static const sx_layout sxsynt_v2m_time_delta_middle_plane={0x608e0003U,"v2m_time_delta_middle_plane",sxsynt_v2m_time_delta_middle_plane_fields,SX_COUNT(sxsynt_v2m_time_delta_middle_plane_fields),SX_LE};
static const xx_data_struct_field_desc sxsynt_v2m_time_delta_high_plane_fields[]={
 SX_FIELD("time_delta_high","uint8",0,0,SX_NONE),
};
static const sx_layout sxsynt_v2m_time_delta_high_plane={0x608e0004U,"v2m_time_delta_high_plane",sxsynt_v2m_time_delta_high_plane_fields,SX_COUNT(sxsynt_v2m_time_delta_high_plane_fields),SX_LE};
static const xx_data_struct_field_desc sxsynt_v2m_time_signature_numerator_plane_fields[]={
 SX_FIELD("time_signature_numerator","uint8",0,0,SX_NONE),
};
static const sx_layout sxsynt_v2m_time_signature_numerator_plane={0x608e0005U,"v2m_time_signature_numerator_plane",sxsynt_v2m_time_signature_numerator_plane_fields,SX_COUNT(sxsynt_v2m_time_signature_numerator_plane_fields),SX_LE};
static const xx_data_struct_field_desc sxsynt_v2m_time_signature_denominator_plane_fields[]={
 SX_FIELD("time_signature_denominator","uint8",0,0,SX_NONE),
};
static const sx_layout sxsynt_v2m_time_signature_denominator_plane={0x608e0006U,"v2m_time_signature_denominator_plane",sxsynt_v2m_time_signature_denominator_plane_fields,SX_COUNT(sxsynt_v2m_time_signature_denominator_plane_fields),SX_LE};
static const xx_data_struct_field_desc sxsynt_v2m_timing_tpq_plane_fields[]={
 SX_FIELD("timing_tpq","uint8",0,0,SX_NONE),
};
static const sx_layout sxsynt_v2m_timing_tpq_plane={0x608e0007U,"v2m_timing_tpq_plane",sxsynt_v2m_timing_tpq_plane_fields,SX_COUNT(sxsynt_v2m_timing_tpq_plane_fields),SX_LE};
static const xx_data_struct_field_desc sxsynt_v2m_note_delta_plane_fields[]={
 SX_FIELD("note_delta","uint8",0,0,SX_NONE),
};
static const sx_layout sxsynt_v2m_note_delta_plane={0x608e0008U,"v2m_note_delta_plane",sxsynt_v2m_note_delta_plane_fields,SX_COUNT(sxsynt_v2m_note_delta_plane_fields),SX_LE};
static const xx_data_struct_field_desc sxsynt_v2m_velocity_delta_plane_fields[]={
 SX_FIELD("velocity_delta","uint8",0,0,SX_NONE),
};
static const sx_layout sxsynt_v2m_velocity_delta_plane={0x608e0009U,"v2m_velocity_delta_plane",sxsynt_v2m_velocity_delta_plane_fields,SX_COUNT(sxsynt_v2m_velocity_delta_plane_fields),SX_LE};
static const xx_data_struct_field_desc sxsynt_v2m_program_delta_plane_fields[]={
 SX_FIELD("program_delta","uint8",0,0,SX_NONE),
};
static const sx_layout sxsynt_v2m_program_delta_plane={0x608e000aU,"v2m_program_delta_plane",sxsynt_v2m_program_delta_plane_fields,SX_COUNT(sxsynt_v2m_program_delta_plane_fields),SX_LE};
static const xx_data_struct_field_desc sxsynt_v2m_pitch_lsb_delta_plane_fields[]={
 SX_FIELD("pitch_lsb_delta","uint8",0,0,SX_NONE),
};
static const sx_layout sxsynt_v2m_pitch_lsb_delta_plane={0x608e000bU,"v2m_pitch_lsb_delta_plane",sxsynt_v2m_pitch_lsb_delta_plane_fields,SX_COUNT(sxsynt_v2m_pitch_lsb_delta_plane_fields),SX_LE};
static const xx_data_struct_field_desc sxsynt_v2m_pitch_msb_delta_plane_fields[]={
 SX_FIELD("pitch_msb_delta","uint8",0,0,SX_NONE),
};
static const sx_layout sxsynt_v2m_pitch_msb_delta_plane={0x608e000cU,"v2m_pitch_msb_delta_plane",sxsynt_v2m_pitch_msb_delta_plane_fields,SX_COUNT(sxsynt_v2m_pitch_msb_delta_plane_fields),SX_LE};
static const xx_data_struct_field_desc sxsynt_v2m_controller_delta_plane_fields[]={
 SX_FIELD("controller_delta","uint8",0,0,SX_NONE),
};
static const sx_layout sxsynt_v2m_controller_delta_plane={0x608e000dU,"v2m_controller_delta_plane",sxsynt_v2m_controller_delta_plane_fields,SX_COUNT(sxsynt_v2m_controller_delta_plane_fields),SX_LE};
static const xx_data_struct_field_desc sxsynt_v2m_tempo_fields[]={
 SX_FIELD("microseconds_per_quarter","uint32",0,4,SX_NONE),
};
static const sx_layout sxsynt_v2m_tempo={0x608e000eU,"v2m_tempo",sxsynt_v2m_tempo_fields,SX_COUNT(sxsynt_v2m_tempo_fields),SX_LE};
static const xx_data_struct_field_desc sxsynt_v2m_note_count_fields[]={
 SX_FIELD("note_event_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxsynt_v2m_note_count={0x608e000fU,"v2m_note_count",sxsynt_v2m_note_count_fields,SX_COUNT(sxsynt_v2m_note_count_fields),SX_LE};
static const xx_data_struct_field_desc sxsynt_v2m_program_count_fields[]={
 SX_FIELD("program_event_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxsynt_v2m_program_count={0x608e0010U,"v2m_program_count",sxsynt_v2m_program_count_fields,SX_COUNT(sxsynt_v2m_program_count_fields),SX_LE};
static const xx_data_struct_field_desc sxsynt_v2m_pitch_count_fields[]={
 SX_FIELD("pitch_event_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxsynt_v2m_pitch_count={0x608e0011U,"v2m_pitch_count",sxsynt_v2m_pitch_count_fields,SX_COUNT(sxsynt_v2m_pitch_count_fields),SX_LE};
static const xx_data_struct_field_desc sxsynt_v2m_controller_count_fields[]={
 SX_FIELD("controller_event_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxsynt_v2m_controller_count={0x608e0012U,"v2m_controller_count",sxsynt_v2m_controller_count_fields,SX_COUNT(sxsynt_v2m_controller_count_fields),SX_LE};
static const xx_data_struct_field_desc sxsynt_v2m_globals_length_fields[]={
 SX_FIELD("globals_bytes","uint32",0,4,SX_SIZE),
};
static const sx_layout sxsynt_v2m_globals_length={0x608e0013U,"v2m_globals_length",sxsynt_v2m_globals_length_fields,SX_COUNT(sxsynt_v2m_globals_length_fields),SX_LE};
static const xx_data_struct_field_desc sxsynt_v2m_patchmap_length_fields[]={
 SX_FIELD("patchmap_bytes","uint32",0,4,SX_SIZE),
};
static const sx_layout sxsynt_v2m_patchmap_length={0x608e0014U,"v2m_patchmap_length",sxsynt_v2m_patchmap_length_fields,SX_COUNT(sxsynt_v2m_patchmap_length_fields),SX_LE};
static const xx_data_struct_field_desc sxsynt_v2m_speech_length_fields[]={
 SX_FIELD("speech_bytes","uint32",0,4,SX_SIZE),
};
static const sx_layout sxsynt_v2m_speech_length={0x608e0015U,"v2m_speech_length",sxsynt_v2m_speech_length_fields,SX_COUNT(sxsynt_v2m_speech_length_fields),SX_LE};
static const xx_data_struct_field_desc sxsynt_v2m_speech_count_fields[]={
 SX_FIELD("speech_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxsynt_v2m_speech_count={0x608e0016U,"v2m_speech_count",sxsynt_v2m_speech_count_fields,SX_COUNT(sxsynt_v2m_speech_count_fields),SX_LE};
static const xx_data_struct_field_desc sxsynt_v2m_speech_offset_fields[]={
 SX_FIELD("speech_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxsynt_v2m_speech_offset={0x608e0017U,"v2m_speech_offset",sxsynt_v2m_speech_offset_fields,SX_COUNT(sxsynt_v2m_speech_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxsynt_dmo_cipher_header_fields[]={
 SX_FIELD("initial_seed","uint32",0,4,SX_NONE),
 SX_FIELD("seed_iteration_limit","uint16",4,2,SX_NONE),
 SX_FIELD("seed_xor","uint32",6,4,SX_NONE),
 SX_FIELD("seed_check","uint16",10,2,SX_NONE),
};
static const sx_layout sxsynt_dmo_cipher_header={0x608e0018U,"dmo_cipher_header",sxsynt_dmo_cipher_header_fields,SX_COUNT(sxsynt_dmo_cipher_header_fields),SX_LE};
static const sx_layout*const sx_synthtail_layouts[]={&sxsynt_v2m_header,&sxsynt_v2m_time_delta_low_plane,&sxsynt_v2m_time_delta_middle_plane,&sxsynt_v2m_time_delta_high_plane,&sxsynt_v2m_time_signature_numerator_plane,&sxsynt_v2m_time_signature_denominator_plane,&sxsynt_v2m_timing_tpq_plane,&sxsynt_v2m_note_delta_plane,&sxsynt_v2m_velocity_delta_plane,&sxsynt_v2m_program_delta_plane,&sxsynt_v2m_pitch_lsb_delta_plane,&sxsynt_v2m_pitch_msb_delta_plane,&sxsynt_v2m_controller_delta_plane,&sxsynt_v2m_tempo,&sxsynt_v2m_note_count,&sxsynt_v2m_program_count,&sxsynt_v2m_pitch_count,&sxsynt_v2m_controller_count,&sxsynt_v2m_globals_length,&sxsynt_v2m_patchmap_length,&sxsynt_v2m_speech_length,&sxsynt_v2m_speech_count,&sxsynt_v2m_speech_offset,&sxsynt_dmo_cipher_header};
static bool sx_synthtail_supports(xx_file_type_t t)
{return t==XX_FILE_TYPE_DIE_MUSIC_FARBRAUSCH_V2SYNTHESIZER||t==XX_FILE_TYPE_DIE_MUSIC_TWINTEAM_TWINTRACKPLAYER_DMO;}
/* These planes contain stored delta bytes, not reconstructed MIDI values. */
static bool sxsynt_plane(sx_context*c,const sx_layout*l,int64_t*at,uint32_t count)
{if((uint64_t)count>(uint64_t)(c->size-*at))return false;int64_t shown=count>4096?4096:count;if(shown&&!sx_add(c,l,*at,shown))return false;if(!sx_raw(c,*at+shown,(int64_t)count-shown))return false;*at+=count;return true;}
static bool sxsynt_time(sx_context*c,int64_t*at,uint32_t n)
{return sxsynt_plane(c,&sxsynt_v2m_time_delta_low_plane,at,n)&&sxsynt_plane(c,&sxsynt_v2m_time_delta_middle_plane,at,n)&&sxsynt_plane(c,&sxsynt_v2m_time_delta_high_plane,at,n);}
static bool sxsynt_count(sx_context*c,const sx_layout*l,int64_t*at,uint32_t*n)
{if(!sx_u32(c,*at,false,n)||!sx_add(c,l,*at,4))return false;*at+=4;return true;}
static bool sxsynt_v2m(sx_context*c)
{uint32_t n;int64_t at=12;
 if(!sx_u32(c,8,false,&n)||(uint64_t)n>(uint64_t)(c->size-12)/10||!sx_add(c,&sxsynt_v2m_header,0,12))return false;
 if(!sxsynt_time(c,&at,n)||!sx_table(c,&sxsynt_v2m_tempo,at,4,n))return false;at+=(int64_t)n*4;
 if(!sxsynt_plane(c,&sxsynt_v2m_time_signature_numerator_plane,&at,n)||!sxsynt_plane(c,&sxsynt_v2m_time_signature_denominator_plane,&at,n)||!sxsynt_plane(c,&sxsynt_v2m_timing_tpq_plane,&at,n))return false;
 for(unsigned channel=0;channel<16;channel++){
  if(!sxsynt_count(c,&sxsynt_v2m_note_count,&at,&n))return false;if(!n)continue;
  if((uint64_t)n>(uint64_t)(c->size-at)/5||!sxsynt_time(c,&at,n)||!sxsynt_plane(c,&sxsynt_v2m_note_delta_plane,&at,n)||!sxsynt_plane(c,&sxsynt_v2m_velocity_delta_plane,&at,n))return false;
  if(!sxsynt_count(c,&sxsynt_v2m_program_count,&at,&n)||(uint64_t)n>(uint64_t)(c->size-at)/4||!sxsynt_time(c,&at,n)||!sxsynt_plane(c,&sxsynt_v2m_program_delta_plane,&at,n))return false;
  if(!sxsynt_count(c,&sxsynt_v2m_pitch_count,&at,&n)||(uint64_t)n>(uint64_t)(c->size-at)/5||!sxsynt_time(c,&at,n)||!sxsynt_plane(c,&sxsynt_v2m_pitch_lsb_delta_plane,&at,n)||!sxsynt_plane(c,&sxsynt_v2m_pitch_msb_delta_plane,&at,n))return false;
  for(unsigned control=0;control<7;control++)if(!sxsynt_count(c,&sxsynt_v2m_controller_count,&at,&n)||(uint64_t)n>(uint64_t)(c->size-at)/4||!sxsynt_time(c,&at,n)||!sxsynt_plane(c,&sxsynt_v2m_controller_delta_plane,&at,n))return false;
 }
 if(!sxsynt_count(c,&sxsynt_v2m_globals_length,&at,&n)||n>16384||(uint64_t)n>(uint64_t)(c->size-at)||!sx_raw(c,at,n))return false;at+=n;
 if(!sxsynt_count(c,&sxsynt_v2m_patchmap_length,&at,&n)||n>1048576||(uint64_t)n>(uint64_t)(c->size-at)||!sx_raw(c,at,n))return false;at+=n;
 if(c->size-at<4)return sx_raw(c,at,c->size-at);
 if(!sxsynt_count(c,&sxsynt_v2m_speech_length,&at,&n))return false;
 /* The original player disables zero/large speech blocks. Do not invent a
  * physical block extent when that sentinel or truncated legacy data occurs. */
 if(n<4||n>=8192||(uint64_t)n>(uint64_t)(c->size-at))return sx_raw(c,at,c->size-at);
 uint32_t count;if(!sx_u32(c,at,false,&count))return false;
 if(count>256||count>(n-4)/4)return sx_raw(c,at,c->size-at);
 for(uint32_t i=0;i<count;i++){uint32_t off;if(!sx_u32(c,at+4+(int64_t)i*4,false,&off))return false;if(off<4+count*4||off>=n)return sx_raw(c,at,c->size-at);}
 if(!sx_add(c,&sxsynt_v2m_speech_count,at,4)||!sx_table(c,&sxsynt_v2m_speech_offset,at+4,4,count))return false;
 at+=4+(int64_t)count*4;return sx_raw(c,at,c->size-at);}
static bool sxsynt_dmo(sx_context*c)
{uint32_t state,mix,sum=0;uint16_t rounds,check;
 if(!sx_u32(c,0,false,&state)||!sx_u16(c,4,false,&rounds)||!sx_u32(c,6,false,&mix)||!sx_u16(c,10,false,&check))return false;
 for(uint32_t i=0;i<=(uint32_t)rounds;i++){
  if(!(i&255U)&&c->pd&&xx_pd_is_stopped(c->pd))return false;
  state=state*UINT32_C(0x08088405)+1U;sum+=(uint32_t)(((uint64_t)state*65535U)>>32);
 }
 state=(sum^mix)*UINT32_C(0x08088405)+1U;
 if((uint16_t)(((uint64_t)state*65535U)>>32)!=check)return sx_raw(c,0,c->size);
 return sx_add(c,&sxsynt_dmo_cipher_header,0,12)&&sx_raw(c,12,c->size-12);
}
static bool sx_synthtail_build(sx_context*c)
{if(!c||!c->f||!sx_synthtail_supports(c->f->file_type)||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;
 if(c->f->file_type==XX_FILE_TYPE_DIE_MUSIC_TWINTEAM_TWINTRACKPLAYER_DMO)return sxsynt_dmo(c);
 return sxsynt_v2m(c);}
static bool sx_synthtail_comment(xx_data_struct_record*r,uint32_t id)
{if(!r||!r->name||id<0x608e0001U||id>0x608e0018U)return true;
 const wchar_t*t=L"Stored physical value; synthesizer execution and reconstructed MIDI state are not exposed as file members.";
 if(!xx_rt_wcscmp(r->name,L"speech_offset"))t=L"Byte offset relative to the start of the speech block, whose first field is speech_count.";
 else if(!xx_rt_wcscmp(r->name,L"initial_seed"))t=L"Initial 32-bit seed for the TwinTeam header's pseudorandom validation sequence.";
 else if(!xx_rt_wcscmp(r->name,L"seed_iteration_limit"))t=L"Inclusive iteration limit; the seed-summing loop runs this value plus one times.";
 else if(!xx_rt_wcscmp(r->name,L"seed_xor"))t=L"Value XORed with the accumulated seed before the header check and byte decoding.";
 else if(!xx_rt_wcscmp(r->name,L"seed_check"))t=L"Validated 16-bit pseudorandom header check. This checks header identity only; the encrypted payload remains raw and is not authenticated.";
 else if(!xx_rt_wcscmp(r->name,L"microseconds_per_quarter"))t=L"Tempo in microseconds per quarter note; little-endian global event value.";
 else if(!xx_rt_wcscmp(r->name,L"timing_tpq"))t=L"Stored TPQ byte in the global timing event; its physical value is preserved without assuming an undocumented unit.";
 else if(!xx_rt_wcscmp(r->name,L"maximum_time"))t=L"Song end time in file ticks, using ticks_per_quarter.";
 else if(!xx_rt_wcscmp(r->name,L"time_delta_low")||!xx_rt_wcscmp(r->name,L"time_delta_middle")||!xx_rt_wcscmp(r->name,L"time_delta_high"))t=L"One byte plane of 24-bit unsigned event-time deltas: low, middle, and high planes are stored separately.";
 else if(!xx_rt_wcscmp(r->name,L"note_delta")||!xx_rt_wcscmp(r->name,L"velocity_delta")||!xx_rt_wcscmp(r->name,L"program_delta")||!xx_rt_wcscmp(r->name,L"pitch_lsb_delta")||!xx_rt_wcscmp(r->name,L"pitch_msb_delta")||!xx_rt_wcscmp(r->name,L"controller_delta"))t=L"Stored byte-difference plane. Playback accumulates these bytes; this field preserves the encoded differences.";
 return xx_data_struct_record_set_comment(r,t);}
