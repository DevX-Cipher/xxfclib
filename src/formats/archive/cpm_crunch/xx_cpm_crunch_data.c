/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * CPM_CRUNCH data structures, moved out of the archivestreams schema family. */
#include "../../xx_format_schema_archivestreams.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxas_crunch_magic_fields[] = {
 SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
};
const sx_layout sxas_crunch_magic = {UINT32_C(0x60430029),"crunch_magic",sxas_crunch_magic_fields,SX_COUNT(sxas_crunch_magic_fields),SX_LE};
static const xx_data_struct_field_desc sxas_crunch_parameters_fields[] = {
 SX_FIELD("encoder_version","uint8",0,1,SX_NONE),
 SX_FIELD("decoder_version","uint8",1,1,SX_NONE),
 SX_FIELD("checksum_flag","uint8",2,1,SX_NONE),
 SX_FIELD("reserved","uint8",3,1,SX_NONE),
};
const sx_layout sxas_crunch_parameters = {UINT32_C(0x6043002a),"crunch_parameters",sxas_crunch_parameters_fields,SX_COUNT(sxas_crunch_parameters_fields),SX_LE};
static bool sxas_zstr(sx_context*c,uint64_t*p,uint64_t end,unsigned cap){for(unsigned i=0;i<cap&&*p<end;i++){uint8_t b;if(!sxas_read(c,(*p)++,&b,1))return false;if(!b)return true;}return false;}
static bool sxas_crunch(sx_context*c){uint64_t p=2;return sxas_add(c,&sxas_crunch_magic,0)&&sxas_zstr(c,&p,(uint64_t)c->size,96)&&sxas_add(c,&sxas_crunch_parameters,p);}
bool sx_cpm_crunch_build(sx_context*c)
{
 return sxas_crunch(c);
}
