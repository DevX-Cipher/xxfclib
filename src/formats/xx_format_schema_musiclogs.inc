/* SPDX-License-Identifier: MIT. Physical packet/event schemas; no playback or decoded virtual data. */
static const xx_data_struct_field_desc sxlog_midi_clip_header_fields[]={
 SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
};
static const sx_layout sxlog_midi_clip_header={0x608c0001U,"midi_clip_header",sxlog_midi_clip_header_fields,SX_COUNT(sxlog_midi_clip_header_fields),SX_LE};
static const xx_data_struct_field_desc sxlog_midi_ump_utility_fields[]={
 SX_FIELD("message_type_reserved","uint8",0,1,SX_FLAGS),
 SX_FIELD("status_and_tick_high_bits","uint8",1,1,SX_FLAGS),
 SX_FIELD("tick_low_bits","uint16",2,2,SX_NONE),
};
static const sx_layout sxlog_midi_ump_utility={0x608c0002U,"midi_ump_utility",sxlog_midi_ump_utility_fields,SX_COUNT(sxlog_midi_ump_utility_fields),SX_BE};
static const xx_data_struct_field_desc sxlog_midi_ump_system_fields[]={
 SX_FIELD("type_and_group","uint8",0,1,SX_FLAGS),
 SX_FIELD("system_status","uint8",1,1,SX_FLAGS),
 SX_FIELD("parameter_1","uint8",2,1,SX_NONE),
 SX_FIELD("parameter_2","uint8",3,1,SX_NONE),
};
static const sx_layout sxlog_midi_ump_system={0x608c0003U,"midi_ump_system",sxlog_midi_ump_system_fields,SX_COUNT(sxlog_midi_ump_system_fields),SX_LE};
static const xx_data_struct_field_desc sxlog_midi_ump_midi1_note_fields[]={
 SX_FIELD("type_and_group","uint8",0,1,SX_FLAGS),
 SX_FIELD("status_and_channel","uint8",1,1,SX_FLAGS),
 SX_FIELD("note","uint8",2,1,SX_NONE),
 SX_FIELD("velocity","uint8",3,1,SX_NONE),
};
static const sx_layout sxlog_midi_ump_midi1_note={0x608c0004U,"midi_ump_midi1_note",sxlog_midi_ump_midi1_note_fields,SX_COUNT(sxlog_midi_ump_midi1_note_fields),SX_LE};
static const xx_data_struct_field_desc sxlog_midi_ump_midi1_channel_fields[]={
 SX_FIELD("type_and_group","uint8",0,1,SX_FLAGS),
 SX_FIELD("status_and_channel","uint8",1,1,SX_FLAGS),
 SX_FIELD("data_1","uint8",2,1,SX_NONE),
 SX_FIELD("data_2","uint8",3,1,SX_NONE),
};
static const sx_layout sxlog_midi_ump_midi1_channel={0x608c0005U,"midi_ump_midi1_channel",sxlog_midi_ump_midi1_channel_fields,SX_COUNT(sxlog_midi_ump_midi1_channel_fields),SX_LE};
static const xx_data_struct_field_desc sxlog_midi_ump_midi2_note_fields[]={
 SX_FIELD("type_and_group","uint8",0,1,SX_FLAGS),
 SX_FIELD("status_and_channel","uint8",1,1,SX_FLAGS),
 SX_FIELD("note","uint8",2,1,SX_NONE),
 SX_FIELD("attribute_type","uint8",3,1,SX_FLAGS),
 SX_FIELD("velocity","uint16",4,2,SX_NONE),
 SX_FIELD("attribute_data","uint16",6,2,SX_NONE),
};
static const sx_layout sxlog_midi_ump_midi2_note={0x608c0006U,"midi_ump_midi2_note",sxlog_midi_ump_midi2_note_fields,SX_COUNT(sxlog_midi_ump_midi2_note_fields),SX_BE};
static const xx_data_struct_field_desc sxlog_midi_ump_midi2_channel_fields[]={
 SX_FIELD("type_and_group","uint8",0,1,SX_FLAGS),
 SX_FIELD("status_and_channel","uint8",1,1,SX_FLAGS),
 SX_FIELD("index_or_options","uint16",2,2,SX_NONE),
 SX_FIELD("data","uint32",4,4,SX_NONE),
};
static const sx_layout sxlog_midi_ump_midi2_channel={0x608c0007U,"midi_ump_midi2_channel",sxlog_midi_ump_midi2_channel_fields,SX_COUNT(sxlog_midi_ump_midi2_channel_fields),SX_BE};
static const xx_data_struct_field_desc sxlog_midi_ump_sysex7_fields[]={
 SX_FIELD("type_and_group","uint8",0,1,SX_FLAGS),
 SX_FIELD("status_and_byte_count","uint8",1,1,SX_FLAGS),
 SX_FIELD("data","uint8[6]",2,6,SX_NONE),
};
static const sx_layout sxlog_midi_ump_sysex7={0x608c0008U,"midi_ump_sysex7",sxlog_midi_ump_sysex7_fields,SX_COUNT(sxlog_midi_ump_sysex7_fields),SX_LE};
static const xx_data_struct_field_desc sxlog_midi_ump_data128_fields[]={
 SX_FIELD("type_and_group","uint8",0,1,SX_FLAGS),
 SX_FIELD("status_and_byte_count","uint8",1,1,SX_FLAGS),
 SX_FIELD("data","uint8[14]",2,14,SX_NONE),
};
static const sx_layout sxlog_midi_ump_data128={0x608c0009U,"midi_ump_data128",sxlog_midi_ump_data128_fields,SX_COUNT(sxlog_midi_ump_data128_fields),SX_LE};
static const xx_data_struct_field_desc sxlog_midi_ump_flex_fields[]={
 SX_FIELD("type_and_group","uint8",0,1,SX_FLAGS),
 SX_FIELD("format_address_channel","uint8",1,1,SX_FLAGS),
 SX_FIELD("status_bank","uint8",2,1,SX_FLAGS),
 SX_FIELD("status","uint8",3,1,SX_FLAGS),
 SX_FIELD("data","uint8[12]",4,12,SX_NONE),
};
static const sx_layout sxlog_midi_ump_flex={0x608c000aU,"midi_ump_flex",sxlog_midi_ump_flex_fields,SX_COUNT(sxlog_midi_ump_flex_fields),SX_LE};
static const xx_data_struct_field_desc sxlog_midi_ump_stream_fields[]={
 SX_FIELD("type_format_status","uint16",0,2,SX_FLAGS),
 SX_FIELD("message_data","uint8[14]",2,14,SX_NONE),
};
static const sx_layout sxlog_midi_ump_stream={0x608c000bU,"midi_ump_stream",sxlog_midi_ump_stream_fields,SX_COUNT(sxlog_midi_ump_stream_fields),SX_BE};
static const xx_data_struct_field_desc sxlog_sidplayer_header_fields[]={
 SX_FIELD("load_address","uint16",0,2,SX_ADDRESS),
 SX_FIELD("voice_1_size","uint16",2,2,SX_SIZE),
 SX_FIELD("voice_2_size","uint16",4,2,SX_SIZE),
 SX_FIELD("voice_3_size","uint16",6,2,SX_SIZE),
};
static const sx_layout sxlog_sidplayer_header={0x608c000cU,"sidplayer_header",sxlog_sidplayer_header_fields,SX_COUNT(sxlog_sidplayer_header_fields),SX_LE};
static const xx_data_struct_field_desc sxlog_sidplayer_command_fields[]={
 SX_FIELD("command","uint8",0,1,SX_FLAGS),
 SX_FIELD("option","uint8",1,1,SX_FLAGS),
};
static const sx_layout sxlog_sidplayer_command={0x608c000dU,"sidplayer_command",sxlog_sidplayer_command_fields,SX_COUNT(sxlog_sidplayer_command_fields),SX_LE};
static const xx_data_struct_field_desc sxlog_sidplayer_halt_fields[]={
 SX_FIELD("halt_command","uint16",0,2,SX_FLAGS),
};
static const sx_layout sxlog_sidplayer_halt={0x608c000eU,"sidplayer_halt",sxlog_sidplayer_halt_fields,SX_COUNT(sxlog_sidplayer_halt_fields),SX_BE};
static const xx_data_struct_field_desc sxlog_sidplayer_description_fields[]={
 SX_FIELD("petscii_bytes","uint8",0,0,SX_NONE),
};
static const sx_layout sxlog_sidplayer_description={0x608c000fU,"sidplayer_description",sxlog_sidplayer_description_fields,SX_COUNT(sxlog_sidplayer_description_fields),SX_LE};
static const xx_data_struct_field_desc sxlog_imf_length_fields[]={
 SX_FIELD("event_bytes","uint16",0,2,SX_SIZE),
};
static const sx_layout sxlog_imf_length={0x608c0010U,"imf_length",sxlog_imf_length_fields,SX_COUNT(sxlog_imf_length_fields),SX_LE};
static const xx_data_struct_field_desc sxlog_adlib_header_fields[]={
 SX_FIELD("signature","char[5]",0,5,SX_SIGNATURE),
 SX_FIELD("version","uint8",5,1,SX_NONE),
};
static const sx_layout sxlog_adlib_header={0x608c0011U,"adlib_header",sxlog_adlib_header_fields,SX_COUNT(sxlog_adlib_header_fields),SX_LE};
static const xx_data_struct_field_desc sxlog_adlib_title_fields[]={
 SX_FIELD("title","char",0,0,SX_NONE),
};
static const sx_layout sxlog_adlib_title={0x608c0012U,"adlib_title",sxlog_adlib_title_fields,SX_COUNT(sxlog_adlib_title_fields),SX_LE};
static const xx_data_struct_field_desc sxlog_adlib_game_fields[]={
 SX_FIELD("game","char",0,0,SX_NONE),
};
static const sx_layout sxlog_adlib_game={0x608c0013U,"adlib_game",sxlog_adlib_game_fields,SX_COUNT(sxlog_adlib_game_fields),SX_LE};
static const xx_data_struct_field_desc sxlog_adlib_separator_fields[]={
 SX_FIELD("separator","uint8",0,1,SX_NONE),
};
static const sx_layout sxlog_adlib_separator={0x608c0014U,"adlib_separator",sxlog_adlib_separator_fields,SX_COUNT(sxlog_adlib_separator_fields),SX_LE};
static const xx_data_struct_field_desc sxlog_adlib_length_fields[]={
 SX_FIELD("event_bytes","uint32",0,4,SX_SIZE),
};
static const sx_layout sxlog_adlib_length={0x608c0015U,"adlib_length",sxlog_adlib_length_fields,SX_COUNT(sxlog_adlib_length_fields),SX_LE};
static const xx_data_struct_field_desc sxlog_imf_register_event_fields[]={
 SX_FIELD("register","uint8",0,1,SX_FLAGS),
 SX_FIELD("value","uint8",1,1,SX_NONE),
 SX_FIELD("delay_ticks","uint16",2,2,SX_NONE),
};
static const sx_layout sxlog_imf_register_event={0x608c0016U,"imf_register_event",sxlog_imf_register_event_fields,SX_COUNT(sxlog_imf_register_event_fields),SX_LE};
static const xx_data_struct_field_desc sxlog_imf_final_write_fields[]={
 SX_FIELD("register","uint8",0,1,SX_FLAGS),
 SX_FIELD("value","uint8",1,1,SX_NONE),
};
static const sx_layout sxlog_imf_final_write={0x608c0017U,"imf_final_write",sxlog_imf_final_write_fields,SX_COUNT(sxlog_imf_final_write_fields),SX_LE};
static const xx_data_struct_field_desc sxlog_cym_register_write_fields[]={
 SX_FIELD("register","uint8",0,1,SX_FLAGS),
 SX_FIELD("value","uint8",1,1,SX_NONE),
};
static const sx_layout sxlog_cym_register_write={0x608c0018U,"cym_register_write",sxlog_cym_register_write_fields,SX_COUNT(sxlog_cym_register_write_fields),SX_LE};
static const xx_data_struct_field_desc sxlog_cym_frame_wait_fields[]={
 SX_FIELD("wait_marker","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxlog_cym_frame_wait={0x608c0019U,"cym_frame_wait",sxlog_cym_frame_wait_fields,SX_COUNT(sxlog_cym_frame_wait_fields),SX_LE};
static const sx_layout*const sx_musiclogs_layouts[]={&sxlog_midi_clip_header,&sxlog_midi_ump_utility,&sxlog_midi_ump_system,&sxlog_midi_ump_midi1_note,&sxlog_midi_ump_midi1_channel,&sxlog_midi_ump_midi2_note,&sxlog_midi_ump_midi2_channel,&sxlog_midi_ump_sysex7,&sxlog_midi_ump_data128,&sxlog_midi_ump_flex,&sxlog_midi_ump_stream,&sxlog_sidplayer_header,&sxlog_sidplayer_command,&sxlog_sidplayer_halt,&sxlog_sidplayer_description,&sxlog_imf_length,&sxlog_adlib_header,&sxlog_adlib_title,&sxlog_adlib_game,&sxlog_adlib_separator,&sxlog_adlib_length,&sxlog_imf_register_event,&sxlog_imf_final_write,&sxlog_cym_register_write,&sxlog_cym_frame_wait};
static bool sx_musiclogs_supports(xx_file_type_t t)
{switch(t){case XX_FILE_TYPE_DIE_MUSIC_CLIP_MIDI2:case XX_FILE_TYPE_DIE_MUSIC_COMPUTE_SIDPLAYER_MUS:case XX_FILE_TYPE_DIE_MUSIC_IDAPOGEE_MUSICFORMAT:case XX_FILE_TYPE_DIE_MUSIC_FERNANDEZ_ADLIB:case XX_FILE_TYPE_DIE_MUSIC_YM2151OPMREGLOG_CYM:return true;default:return false;}}
static bool sxlog_cstring(sx_context*c,const sx_layout*l,int64_t*at)
{uint8_t b;int64_t end=*at;while(end<c->size&&end-*at<4096){if(!sx_read(c,end,&b,1))return false;end++;if(!b){if(!sx_add(c,l,*at,end-*at))return false;*at=end;return true;}}return false;}
static bool sxlog_midi(sx_context*c)
{uint8_t b[8];int64_t at=8;unsigned work=0;
 if(!sx_read(c,0,b,8)||xx_rt_memcmp(b,"SMF2CLIP",8)||!sx_add(c,&sxlog_midi_clip_header,0,8))return false;
 while(at<c->size&&work++<16000){const sx_layout*l=NULL;unsigned size=0;if(c->size-at<4)break;if(!sx_read(c,at,b,4))return false;unsigned mt=b[0]>>4,st=b[1]>>4;
  switch(mt){case 0:l=&sxlog_midi_ump_utility;size=4;break;case 1:l=&sxlog_midi_ump_system;size=4;break;
  case 2:l=(st==8||st==9)?&sxlog_midi_ump_midi1_note:&sxlog_midi_ump_midi1_channel;size=4;break;
  case 3:l=&sxlog_midi_ump_sysex7;size=8;break;case 4:l=(st==8||st==9)?&sxlog_midi_ump_midi2_note:&sxlog_midi_ump_midi2_channel;size=8;break;
  case 5:l=&sxlog_midi_ump_data128;size=16;break;case 13:l=&sxlog_midi_ump_flex;size=16;break;case 15:l=&sxlog_midi_ump_stream;size=16;break;default:break;}
  if(!l||size>(uint64_t)(c->size-at))break;if(!sx_add(c,l,at,size))return false;at+=size;
 }return sx_raw(c,at,c->size-at);}
static bool sxlog_sid(sx_context*c)
{uint16_t n[3];int64_t at=8;uint8_t halt[2];if(!sx_u16(c,2,false,n)||!sx_u16(c,4,false,n+1)||!sx_u16(c,6,false,n+2))return false;
 for(unsigned i=0;i<3;i++){if(n[i]<2||(n[i]&1)||!sx_range(c,at,n[i])||!sx_read(c,at+n[i]-2,halt,2)||halt[0]!=1||halt[1]!=0x4f)return false;at+=n[i];}
 if(!sx_add(c,&sxlog_sidplayer_header,0,8))return false;at=8;
 for(unsigned i=0;i<3;i++){if(!sx_table(c,&sxlog_sidplayer_command,at,2,n[i]/2-1)||!sx_add(c,&sxlog_sidplayer_halt,at+n[i]-2,2))return false;at+=n[i];}
 if(at<c->size){int64_t end=at;uint8_t b;while(end<c->size&&end-at<4096){if(!sx_read(c,end++,&b,1))return false;if(!b)break;}if(!sx_add(c,&sxlog_sidplayer_description,at,end-at))return false;at=end;}
 return sx_raw(c,at,c->size-at);}
static bool sxlog_imf(sx_context*c,bool header)
{int64_t at=0,available,declared;uint32_t n=0;uint16_t z=0;
 if(header){uint8_t b[6];if(!sx_read(c,0,b,6)||xx_rt_memcmp(b,"ADLIB\1",6)||!sx_add(c,&sxlog_adlib_header,0,6))return false;at=6;
  if(!sxlog_cstring(c,&sxlog_adlib_title,&at))return !c->failed&&sx_raw(c,at,c->size-at);
  if(!sxlog_cstring(c,&sxlog_adlib_game,&at))return !c->failed&&sx_raw(c,at,c->size-at);
  if(c->size-at<5)return sx_raw(c,at,c->size-at);if(!sx_add(c,&sxlog_adlib_separator,at,1))return false;at++;
  if(!sx_u32(c,at,false,&n))return false;if(n){if(!sx_add(c,&sxlog_adlib_length,at,4))return false;at+=4;}
 }else{if(!sx_u16(c,0,false,&z))return false;n=z;if(n){if(!sx_add(c,&sxlog_imf_length,0,2))return false;at=2;}}
 available=c->size-at;declared=n?(int64_t)n:available;
 /* Historical files can omit the final delay word; never synthesize it. */
 if(n&&(n&3))return sx_raw(c,at,available);if(declared>available){if(declared-available!=2)return sx_raw(c,at,available);declared=available;}
 if(declared<2)return sx_raw(c,at,available);int64_t bytes=declared-(declared%4);
 if(!sx_table(c,&sxlog_imf_register_event,at,4,(uint64_t)bytes/4))return false;at+=bytes;
 if(declared%4==2){if(!sx_add(c,&sxlog_imf_final_write,at,2))return false;at+=2;}
 return sx_raw(c,at,c->size-at);}
static bool sxlog_cym(sx_context*c)
{int64_t at=0;unsigned work=0;uint8_t r;while(at<c->size&&work++<16000){if(!sx_read(c,at,&r,1))return false;unsigned size=r?2:1;if(size>(uint64_t)(c->size-at))break;if(!sx_add(c,r?&sxlog_cym_register_write:&sxlog_cym_frame_wait,at,size))return false;at+=size;}return sx_raw(c,at,c->size-at);}
static bool sx_musiclogs_build(sx_context*c)
{if(!c||!c->f||!sx_musiclogs_supports(c->f->file_type)||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;
 switch(c->f->file_type){case XX_FILE_TYPE_DIE_MUSIC_CLIP_MIDI2:return sxlog_midi(c);case XX_FILE_TYPE_DIE_MUSIC_COMPUTE_SIDPLAYER_MUS:return sxlog_sid(c);
 case XX_FILE_TYPE_DIE_MUSIC_IDAPOGEE_MUSICFORMAT:return sxlog_imf(c,false);case XX_FILE_TYPE_DIE_MUSIC_FERNANDEZ_ADLIB:return sxlog_imf(c,true);
 case XX_FILE_TYPE_DIE_MUSIC_YM2151OPMREGLOG_CYM:return sxlog_cym(c);

 default:return false;}}
static bool sx_musiclogs_comment(xx_data_struct_record*r,uint32_t id)
{if(!r||!r->name||id<0x608c0001U||id>0x608c0019U)return true;
 const wchar_t*comment=L"Physical field; unsupported packet semantics remain uninterpreted.";
 if(!xx_rt_wcscmp(r->name,L"load_address"))comment=L"C64 load address stored in the file; SID editors and players may relocate the tune.";
 else if(!xx_rt_wcscmp(r->name,L"voice_1_size")||!xx_rt_wcscmp(r->name,L"voice_2_size")||!xx_rt_wcscmp(r->name,L"voice_3_size"))comment=L"Bytes in this voice stream, including its terminating HLT pair.";
 else if(!xx_rt_wcscmp(r->name,L"halt_command"))comment=L"SIDPLAYER_HLT (physical bytes 01 4F).";
 else if(!xx_rt_wcscmp(r->name,L"petscii_bytes"))comment=L"Song description in PETSCII, including a terminating NUL when present; bytes are preserved without ASCII conversion.";
 else if(!xx_rt_wcscmp(r->name,L"command"))comment=L"SID command byte; the low bits select a note or command family and can also hold operand bits.";
 else if(!xx_rt_wcscmp(r->name,L"option"))comment=L"SID option byte; interpretation depends on the paired command byte.";
 else if(!xx_rt_wcscmp(r->name,L"type_and_group"))comment=L"High nibble: UMP message type; low nibble: group (0 to 15).";
 else if(!xx_rt_wcscmp(r->name,L"status_and_channel"))comment=L"High nibble: MIDI channel status; low nibble: channel (0 to 15).";
 else if(!xx_rt_wcscmp(r->name,L"status_and_byte_count"))comment=L"High nibble: data-message status; low nibble: byte count or mixed-data identifier.";
 else if(!xx_rt_wcscmp(r->name,L"format_address_channel"))comment=L"Bits 7:6 format, bits 5:4 address, bits 3:0 channel; stored Flex Data header byte.";
 else if(!xx_rt_wcscmp(r->name,L"type_format_status"))comment=L"Bits 15:12 UMP_STREAM, bits 11:10 format, bits 9:0 stream status (0x20 START_OF_CLIP, 0x21 END_OF_CLIP).";
 else if(!xx_rt_wcscmp(r->name,L"message_type_reserved"))comment=L"UMP utility message type and reserved bits; these messages do not carry a group address.";
 else if(!xx_rt_wcscmp(r->name,L"status_and_tick_high_bits"))comment=L"High nibble: utility status (1 JR_CLOCK, 2 JR_TIMESTAMP, 3 DCTPQ, 4 DELTA_CLOCKSTAMP); low nibble is reserved or the upper 4 delta-tick bits.";
 else if(!xx_rt_wcscmp(r->name,L"tick_low_bits"))comment=L"Lower 16 timing bits. DELTA_CLOCKSTAMP also uses the preceding low nibble; DCTPQ gives ticks per quarter note.";
 else if(!xx_rt_wcscmp(r->name,L"event_bytes"))comment=L"Declared length in bytes of the following IMF events. A zero initial word belongs to the headerless event stream and is not a size field.";
 else if(!xx_rt_wcscmp(r->name,L"delay_ticks"))comment=L"Delay after this OPL2 write in playback ticks; the rate is external to the event stream.";
 else if(!xx_rt_wcscmp(r->name,L"wait_marker"))comment=L"CYM_WAIT_FRAME: zero byte advances the log by one 1/60-second frame.";
 else if(!xx_rt_wcscmp(r->name,L"register"))comment=id==0x608c0018U?L"YM2151 register number; zero is a separate frame-wait token.":L"Stored chip register number; no synthetic timing or header fields are added.";
 else if(!xx_rt_wcscmp(r->name,L"value"))comment=L"Byte written to the paired chip register.";
 else if(!xx_rt_wcscmp(r->name,L"separator"))comment=L"Extra byte after game title; preserved without requiring a particular value.";
 else if(!xx_rt_wcscmp(r->name,L"version"))comment=L"Fernandez ADLIB version 1.";
 return xx_data_struct_record_set_comment(r,comment);}
