/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Atari St Msa data structures, moved out of the systemextra schema family. */
#include "../../xx_format_schema_systemextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxse_msa_header_fields[] = {
    SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("sectors_per_track","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("sides_minus_one","uint16",4,2,SX_NONE),
    SX_FIELD("first_track","uint16",6,2,SX_ID),
    SX_FIELD("last_track","uint16",8,2,SX_ID),
};
const sx_layout sxse_msa_header = {0x602f0021U,"msa_header",sxse_msa_header_fields,SX_COUNT(sxse_msa_header_fields),SX_BE};
static const xx_data_struct_field_desc sxse_msa_track_header_fields[] = {
    SX_FIELD("stored_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxse_msa_track_header = {0x602f0022U,"msa_track_header",sxse_msa_track_header_fields,SX_COUNT(sxse_msa_track_header_fields),SX_BE};
#define SXSE_ADD(c,l,p,z) sxse_put(c,&sxse_##l,p,z,1)
static bool sxse_msa(sx_context*c){uint8_t b[10];if(!sxse_read(c,0,b,10)||sxse_u16(b,0,true)!=0x0e0f||!SXSE_ADD(c,msa_header,0,10))return false;unsigned side=sxse_u16(b,4,true)+1,first=sxse_u16(b,6,true),last=sxse_u16(b,8,true);if(side>2||first>last||last>85)return false;uint64_t p=10;for(unsigned i=0;i<(last-first+1)*side;i++){uint16_t z;if(!sx_u16(c,(int64_t)p,true,&z)||!z||!sxse_span(c,p+2,z)||!SXSE_ADD(c,msa_track_header,p,2))return false;p+=2+z;}return true;}
bool sx_atari_st_msa_build(sx_context*c)
{
 return sxse_msa(c);
}
#undef SXSE_ADD
