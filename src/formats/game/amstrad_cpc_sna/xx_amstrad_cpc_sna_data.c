/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * amstrad_cpc_sna data structures, moved out of the gameplatforms schema family. */
#include "../../xx_format_schema_gameplatforms.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgp_cpc_header_fields[]={
 SX_FIELD("signature","bytes",0,8,SX_SIGNATURE),
 SX_FIELD("reserved","bytes",8,8,SX_RESERVED),
 SX_FIELD("version","uint8",16,1,SX_ID),
 SX_FIELD("f","uint8",17,1,SX_FLAGS),
 SX_FIELD("a","uint8",18,1,SX_NONE),
 SX_FIELD("c","uint8",19,1,SX_NONE),
 SX_FIELD("b","uint8",20,1,SX_NONE),
 SX_FIELD("e","uint8",21,1,SX_NONE),
 SX_FIELD("d","uint8",22,1,SX_NONE),
 SX_FIELD("l","uint8",23,1,SX_NONE),
 SX_FIELD("h","uint8",24,1,SX_NONE),
 SX_FIELD("r","uint8",25,1,SX_NONE),
 SX_FIELD("i","uint8",26,1,SX_NONE),
 SX_FIELD("iff1","uint8",27,1,SX_FLAGS),
 SX_FIELD("iff2","uint8",28,1,SX_FLAGS),
 SX_FIELD("ix","uint16",29,2,SX_NONE),
 SX_FIELD("iy","uint16",31,2,SX_NONE),
 SX_FIELD("sp","uint16",33,2,SX_ADDRESS),
 SX_FIELD("pc","uint16",35,2,SX_ADDRESS),
 SX_FIELD("interrupt_mode","uint8",37,1,SX_ID),
 SX_FIELD("f_alt","uint8",38,1,SX_FLAGS),
 SX_FIELD("a_alt","uint8",39,1,SX_NONE),
 SX_FIELD("c_alt","uint8",40,1,SX_NONE),
 SX_FIELD("b_alt","uint8",41,1,SX_NONE),
 SX_FIELD("e_alt","uint8",42,1,SX_NONE),
 SX_FIELD("d_alt","uint8",43,1,SX_NONE),
 SX_FIELD("l_alt","uint8",44,1,SX_NONE),
 SX_FIELD("h_alt","uint8",45,1,SX_NONE),
 SX_FIELD("selected_pen","uint8",46,1,SX_ID),
 SX_FIELD("pen_0","uint8",47,1,SX_ID),
 SX_FIELD("pen_1","uint8",48,1,SX_ID),
 SX_FIELD("pen_2","uint8",49,1,SX_ID),
 SX_FIELD("pen_3","uint8",50,1,SX_ID),
 SX_FIELD("pen_4","uint8",51,1,SX_ID),
 SX_FIELD("pen_5","uint8",52,1,SX_ID),
 SX_FIELD("pen_6","uint8",53,1,SX_ID),
 SX_FIELD("pen_7","uint8",54,1,SX_ID),
 SX_FIELD("pen_8","uint8",55,1,SX_ID),
 SX_FIELD("pen_9","uint8",56,1,SX_ID),
 SX_FIELD("pen_10","uint8",57,1,SX_ID),
 SX_FIELD("pen_11","uint8",58,1,SX_ID),
 SX_FIELD("pen_12","uint8",59,1,SX_ID),
 SX_FIELD("pen_13","uint8",60,1,SX_ID),
 SX_FIELD("pen_14","uint8",61,1,SX_ID),
 SX_FIELD("pen_15","uint8",62,1,SX_ID),
 SX_FIELD("pen_16","uint8",63,1,SX_ID),
 SX_FIELD("gate_array_config","uint8",64,1,SX_FLAGS),
 SX_FIELD("ram_config","uint8",65,1,SX_FLAGS),
 SX_FIELD("selected_crtc","uint8",66,1,SX_ID),
 SX_FIELD("crtc_0","uint8",67,1,SX_FLAGS),
 SX_FIELD("crtc_1","uint8",68,1,SX_FLAGS),
 SX_FIELD("crtc_2","uint8",69,1,SX_FLAGS),
 SX_FIELD("crtc_3","uint8",70,1,SX_FLAGS),
 SX_FIELD("crtc_4","uint8",71,1,SX_FLAGS),
 SX_FIELD("crtc_5","uint8",72,1,SX_FLAGS),
 SX_FIELD("crtc_6","uint8",73,1,SX_FLAGS),
 SX_FIELD("crtc_7","uint8",74,1,SX_FLAGS),
 SX_FIELD("crtc_8","uint8",75,1,SX_FLAGS),
 SX_FIELD("crtc_9","uint8",76,1,SX_FLAGS),
 SX_FIELD("crtc_10","uint8",77,1,SX_FLAGS),
 SX_FIELD("crtc_11","uint8",78,1,SX_FLAGS),
 SX_FIELD("crtc_12","uint8",79,1,SX_FLAGS),
 SX_FIELD("crtc_13","uint8",80,1,SX_FLAGS),
 SX_FIELD("crtc_14","uint8",81,1,SX_FLAGS),
 SX_FIELD("crtc_15","uint8",82,1,SX_FLAGS),
 SX_FIELD("crtc_16","uint8",83,1,SX_FLAGS),
 SX_FIELD("crtc_17","uint8",84,1,SX_FLAGS),
 SX_FIELD("rom_selection","uint8",85,1,SX_ID),
 SX_FIELD("ppi_a","uint8",86,1,SX_FLAGS),
 SX_FIELD("ppi_b","uint8",87,1,SX_FLAGS),
 SX_FIELD("ppi_c","uint8",88,1,SX_FLAGS),
 SX_FIELD("ppi_control","uint8",89,1,SX_FLAGS),
 SX_FIELD("selected_psg","uint8",90,1,SX_ID),
 SX_FIELD("psg_0","uint8",91,1,SX_FLAGS),
 SX_FIELD("psg_1","uint8",92,1,SX_FLAGS),
 SX_FIELD("psg_2","uint8",93,1,SX_FLAGS),
 SX_FIELD("psg_3","uint8",94,1,SX_FLAGS),
 SX_FIELD("psg_4","uint8",95,1,SX_FLAGS),
 SX_FIELD("psg_5","uint8",96,1,SX_FLAGS),
 SX_FIELD("psg_6","uint8",97,1,SX_FLAGS),
 SX_FIELD("psg_7","uint8",98,1,SX_FLAGS),
 SX_FIELD("psg_8","uint8",99,1,SX_FLAGS),
 SX_FIELD("psg_9","uint8",100,1,SX_FLAGS),
 SX_FIELD("psg_10","uint8",101,1,SX_FLAGS),
 SX_FIELD("psg_11","uint8",102,1,SX_FLAGS),
 SX_FIELD("psg_12","uint8",103,1,SX_FLAGS),
 SX_FIELD("psg_13","uint8",104,1,SX_FLAGS),
 SX_FIELD("psg_14","uint8",105,1,SX_FLAGS),
 SX_FIELD("psg_15","uint8",106,1,SX_FLAGS),
 SX_FIELD("memory_dump_kib","uint16",107,2,SX_NONE),
};
const sx_layout sxgp_cpc_header={UINT32_C(0x60360086),"cpc_header",sxgp_cpc_header_fields,SX_COUNT(sxgp_cpc_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_cpc_v1_tail_fields[]={
 SX_FIELD("reserved","bytes",0,147,SX_RESERVED),
};
const sx_layout sxgp_cpc_v1_tail={UINT32_C(0x60360087),"cpc_v1_tail",sxgp_cpc_v1_tail_fields,SX_COUNT(sxgp_cpc_v1_tail_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_cpc_model_fields[]={
 SX_FIELD("machine_type","uint8",0,1,SX_ID),
};
const sx_layout sxgp_cpc_model={UINT32_C(0x60360088),"cpc_model",sxgp_cpc_model_fields,SX_COUNT(sxgp_cpc_model_fields),SX_LE};
#define SG_ROW(l,at,end) sxgp_row(v,&sxgp_##l,(at),(end))
static bool sxgp_cpc(sxgp_view*v){uint64_t end=(uint64_t)v->c->size,ver;return SG_ROW(cpc_header,0,end)&&sxgp_word(v,16,1,false,&ver,end)&&sxgp_row(v,ver==1?&sxgp_cpc_v1_tail:&sxgp_cpc_model,0x6d,end);}
bool sx_amstrad_cpc_sna_build(sxgp_view*v)
{
 return sxgp_cpc(v);
}
#undef SG_ROW
