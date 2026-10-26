/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Atari Cas data structures, moved out of the systemextra schema family. */
#include "../../xx_format_schema_systemextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxse_atari_cas_description_fields[] = {
    SX_FIELD("chunk_id","char[4]",0,4,SX_ID),
    SX_FIELD("data_size","uint16",4,2,SX_SIZE),
    SX_FIELD("reserved","uint16",6,2,SX_NONE),
};
const sx_layout sxse_atari_cas_description = {0x602f0040U,"atari_cas_description",sxse_atari_cas_description_fields,SX_COUNT(sxse_atari_cas_description_fields),SX_LE};
static const xx_data_struct_field_desc sxse_atari_cas_baud_fields[] = {
    SX_FIELD("chunk_id","char[4]",0,4,SX_ID),
    SX_FIELD("data_size","uint16",4,2,SX_SIZE),
    SX_FIELD("baud_rate","uint16",6,2,SX_NONE),
};
const sx_layout sxse_atari_cas_baud = {0x602f0041U,"atari_cas_baud",sxse_atari_cas_baud_fields,SX_COUNT(sxse_atari_cas_baud_fields),SX_LE};
static const xx_data_struct_field_desc sxse_atari_cas_data_fields[] = {
    SX_FIELD("chunk_id","char[4]",0,4,SX_ID),
    SX_FIELD("data_size","uint16",4,2,SX_SIZE),
    SX_FIELD("gap_milliseconds","uint16",6,2,SX_NONE),
};
const sx_layout sxse_atari_cas_data = {0x602f0042U,"atari_cas_data",sxse_atari_cas_data_fields,SX_COUNT(sxse_atari_cas_data_fields),SX_LE};
static const xx_data_struct_field_desc sxse_atari_cas_fsk_fields[] = {
    SX_FIELD("chunk_id","char[4]",0,4,SX_ID),
    SX_FIELD("data_size","uint16",4,2,SX_SIZE),
    SX_FIELD("gap_milliseconds","uint16",6,2,SX_NONE),
};
const sx_layout sxse_atari_cas_fsk = {0x602f0043U,"atari_cas_fsk",sxse_atari_cas_fsk_fields,SX_COUNT(sxse_atari_cas_fsk_fields),SX_LE};
static bool sxse_cas(sx_context*c){uint64_t p=0;uint8_t b[8];for(unsigned k=0;p<(uint64_t)c->size&&k<65536;k++){if(!sxse_read(c,p,b,8))return false;uint64_t z=sxse_u16(b,4,false);const sx_layout*l=!xx_rt_memcmp(b,"FUJI",4)?&sxse_atari_cas_description:!xx_rt_memcmp(b,"baud",4)?&sxse_atari_cas_baud:!xx_rt_memcmp(b,"data",4)?&sxse_atari_cas_data:!xx_rt_memcmp(b,"fsk ",4)?&sxse_atari_cas_fsk:NULL;if(!l||!sxse_span(c,p+8,z)||!sxse_put(c,l,p,8,1))return false;p+=8+z;}return p==(uint64_t)c->size;}
bool sx_atari_cas_build(sx_context*c)
{
 return sxse_cas(c);
}
