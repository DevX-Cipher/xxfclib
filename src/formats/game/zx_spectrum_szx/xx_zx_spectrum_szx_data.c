/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * zx_spectrum_szx data structures, moved out of the gameplatforms schema family. */
#include "../../xx_format_schema_gameplatforms.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgp_szx_header_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("major","uint8",4,1,SX_ID),
 SX_FIELD("minor","uint8",5,1,SX_ID),
 SX_FIELD("machine","uint8",6,1,SX_ID),
 SX_FIELD("flags","uint8",7,1,SX_FLAGS),
};
const sx_layout sxgp_szx_header={UINT32_C(0x60360078),"szx_header",sxgp_szx_header_fields,SX_COUNT(sxgp_szx_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_szx_chunk_fields[]={
 SX_FIELD("chunk_id","bytes",0,4,SX_ID),
 SX_FIELD("data_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxgp_szx_chunk={UINT32_C(0x60360079),"szx_chunk",sxgp_szx_chunk_fields,SX_COUNT(sxgp_szx_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_szx_z80_fields[]={
 SX_FIELD("af","uint16",0,2,SX_FLAGS),
 SX_FIELD("bc","uint16",2,2,SX_NONE),
 SX_FIELD("de","uint16",4,2,SX_NONE),
 SX_FIELD("hl","uint16",6,2,SX_NONE),
 SX_FIELD("af_alt","uint16",8,2,SX_FLAGS),
 SX_FIELD("bc_alt","uint16",10,2,SX_NONE),
 SX_FIELD("de_alt","uint16",12,2,SX_NONE),
 SX_FIELD("hl_alt","uint16",14,2,SX_NONE),
 SX_FIELD("ix","uint16",16,2,SX_NONE),
 SX_FIELD("iy","uint16",18,2,SX_NONE),
 SX_FIELD("sp","uint16",20,2,SX_ADDRESS),
 SX_FIELD("pc","uint16",22,2,SX_ADDRESS),
 SX_FIELD("i","uint8",24,1,SX_NONE),
 SX_FIELD("r","uint8",25,1,SX_NONE),
 SX_FIELD("iff1","uint8",26,1,SX_FLAGS),
 SX_FIELD("iff2","uint8",27,1,SX_FLAGS),
 SX_FIELD("interrupt_mode","uint8",28,1,SX_ID),
 SX_FIELD("tstates","uint32",29,4,SX_NONE),
};
const sx_layout sxgp_szx_z80={UINT32_C(0x6036007A),"szx_z80",sxgp_szx_z80_fields,SX_COUNT(sxgp_szx_z80_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_szx_z80_v0_tail_fields[]={
 SX_FIELD("reserved","bytes",0,4,SX_RESERVED),
};
const sx_layout sxgp_szx_z80_v0_tail={UINT32_C(0x6036007B),"szx_z80_v0_tail",sxgp_szx_z80_v0_tail_fields,SX_COUNT(sxgp_szx_z80_v0_tail_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_szx_z80_v1_tail_fields[]={
 SX_FIELD("hold_interrupt_cycles","uint8",0,1,SX_NONE),
 SX_FIELD("flags","uint8",1,1,SX_FLAGS),
 SX_FIELD("hidden_register","uint8",2,1,SX_NONE),
 SX_FIELD("reserved","uint8",3,1,SX_RESERVED),
};
const sx_layout sxgp_szx_z80_v1_tail={UINT32_C(0x6036007C),"szx_z80_v1_tail",sxgp_szx_z80_v1_tail_fields,SX_COUNT(sxgp_szx_z80_v1_tail_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_szx_z80_v4_tail_fields[]={
 SX_FIELD("hold_interrupt_cycles","uint8",0,1,SX_NONE),
 SX_FIELD("flags","uint8",1,1,SX_FLAGS),
 SX_FIELD("memptr","uint16",2,2,SX_ADDRESS),
};
const sx_layout sxgp_szx_z80_v4_tail={UINT32_C(0x6036007D),"szx_z80_v4_tail",sxgp_szx_z80_v4_tail_fields,SX_COUNT(sxgp_szx_z80_v4_tail_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_szx_spectrum_fields[]={
 SX_FIELD("border","uint8",0,1,SX_ID),
 SX_FIELD("port_7ffd","uint8",1,1,SX_FLAGS),
 SX_FIELD("port_1ffd","uint8",2,1,SX_FLAGS),
 SX_FIELD("port_fe","uint8",3,1,SX_FLAGS),
 SX_FIELD("reserved","bytes",4,4,SX_RESERVED),
};
const sx_layout sxgp_szx_spectrum={UINT32_C(0x6036007E),"szx_spectrum",sxgp_szx_spectrum_fields,SX_COUNT(sxgp_szx_spectrum_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_szx_ram_fields[]={
 SX_FIELD("flags","uint16",0,2,SX_FLAGS),
 SX_FIELD("page_id","uint8",2,1,SX_ID),
};
const sx_layout sxgp_szx_ram={UINT32_C(0x6036007F),"szx_ram",sxgp_szx_ram_fields,SX_COUNT(sxgp_szx_ram_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_szx_creator_fields[]={
 SX_FIELD("creator","char[32]",0,32,SX_STRING),
 SX_FIELD("major","uint16",32,2,SX_ID),
 SX_FIELD("minor","uint16",34,2,SX_ID),
};
const sx_layout sxgp_szx_creator={UINT32_C(0x60360080),"szx_creator",sxgp_szx_creator_fields,SX_COUNT(sxgp_szx_creator_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_szx_joystick_fields[]={
 SX_FIELD("flags","uint32",0,4,SX_FLAGS),
 SX_FIELD("player1","uint8",4,1,SX_ID),
 SX_FIELD("player2","uint8",5,1,SX_ID),
};
const sx_layout sxgp_szx_joystick={UINT32_C(0x60360081),"szx_joystick",sxgp_szx_joystick_fields,SX_COUNT(sxgp_szx_joystick_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_szx_keyboard_fields[]={
 SX_FIELD("flags","uint32",0,4,SX_FLAGS),
};
const sx_layout sxgp_szx_keyboard={UINT32_C(0x60360082),"szx_keyboard",sxgp_szx_keyboard_fields,SX_COUNT(sxgp_szx_keyboard_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_szx_keyboard_joystick_fields[]={
 SX_FIELD("joystick","uint8",0,1,SX_ID),
};
const sx_layout sxgp_szx_keyboard_joystick={UINT32_C(0x60360083),"szx_keyboard_joystick",sxgp_szx_keyboard_joystick_fields,SX_COUNT(sxgp_szx_keyboard_joystick_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_szx_printer_fields[]={
 SX_FIELD("flags","uint16",0,2,SX_FLAGS),
};
const sx_layout sxgp_szx_printer={UINT32_C(0x60360084),"szx_printer",sxgp_szx_printer_fields,SX_COUNT(sxgp_szx_printer_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_szx_ay_fields[]={
 SX_FIELD("flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("selected_register","uint8",1,1,SX_ID),
 SX_FIELD("register_0","uint8",2,1,SX_FLAGS),
 SX_FIELD("register_1","uint8",3,1,SX_FLAGS),
 SX_FIELD("register_2","uint8",4,1,SX_FLAGS),
 SX_FIELD("register_3","uint8",5,1,SX_FLAGS),
 SX_FIELD("register_4","uint8",6,1,SX_FLAGS),
 SX_FIELD("register_5","uint8",7,1,SX_FLAGS),
 SX_FIELD("register_6","uint8",8,1,SX_FLAGS),
 SX_FIELD("register_7","uint8",9,1,SX_FLAGS),
 SX_FIELD("register_8","uint8",10,1,SX_FLAGS),
 SX_FIELD("register_9","uint8",11,1,SX_FLAGS),
 SX_FIELD("register_10","uint8",12,1,SX_FLAGS),
 SX_FIELD("register_11","uint8",13,1,SX_FLAGS),
 SX_FIELD("register_12","uint8",14,1,SX_FLAGS),
 SX_FIELD("register_13","uint8",15,1,SX_FLAGS),
 SX_FIELD("register_14","uint8",16,1,SX_FLAGS),
 SX_FIELD("register_15","uint8",17,1,SX_FLAGS),
};
const sx_layout sxgp_szx_ay={UINT32_C(0x60360085),"szx_ay",sxgp_szx_ay_fields,SX_COUNT(sxgp_szx_ay_fields),SX_LE};
#define SG_ROW(l,at,end) sxgp_row(v,&sxgp_##l,(at),(end))
static bool sxgp_szx(sxgp_view*v)
{uint64_t end=(uint64_t)v->c->size,p=8,z,minor;uint8_t tag[4];if(!SG_ROW(szx_header,0,end)||!sxgp_word(v,5,1,false,&minor,end))return false;
 while(p<end){if(!SG_ROW(szx_chunk,p,end)||!sxgp_read(v,p,tag,4,end)||!sxgp_word(v,p+4,4,false,&z,end)||!sxgp_span(v,p+8,z,end))return false;p+=8;uint64_t stop=p+z;const sx_layout*l=NULL;
  if(!xx_rt_memcmp(tag,"Z80R",4)){if(!SG_ROW(szx_z80,p,stop)||!sxgp_row(v,minor==0?&sxgp_szx_z80_v0_tail:minor<4?&sxgp_szx_z80_v1_tail:&sxgp_szx_z80_v4_tail,p+33,stop))return false;}
  else if(!xx_rt_memcmp(tag,"SPCR",4))l=&sxgp_szx_spectrum;
  else if(!xx_rt_memcmp(tag,"RAMP",4))l=&sxgp_szx_ram;
  else if(!xx_rt_memcmp(tag,"CRTR",4))l=&sxgp_szx_creator;
  else if(!xx_rt_memcmp(tag,"JOY\0",4))l=&sxgp_szx_joystick;
  else if(!xx_rt_memcmp(tag,"ZXPR",4))l=&sxgp_szx_printer;
  else if(!xx_rt_memcmp(tag,"AY\0\0",4))l=&sxgp_szx_ay;
  else if(!xx_rt_memcmp(tag,"KEYB",4)){l=&sxgp_szx_keyboard;if(minor&&!SG_ROW(szx_keyboard_joystick,p+4,stop))return false;}
  if(l&&!sxgp_row(v,l,p,stop))return false;p=stop;
 }return p==end;}
bool sx_zx_spectrum_szx_build(sxgp_view*v)
{
 return sxgp_szx(v);
}
#undef SG_ROW
