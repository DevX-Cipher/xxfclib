/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * GROMACS_TRR data structures, moved out of the scienceheaders schema family. */
#include "../../xx_format_schema_scienceheaders.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsh_trr_header_fields[] = {
    SX_FIELD("magic","int32",0,4,SX_SIGNATURE),
    SX_FIELD("version_buffer_size","int32",4,4,SX_SIZE),
    SX_FIELD("version_string_size","int32",8,4,SX_SIZE),
    SX_FIELD("version","char[12]",12,12,SX_STRING),
    SX_FIELD("ir_size","int32",24,4,SX_SIZE),
    SX_FIELD("energy_size","int32",28,4,SX_SIZE),
    SX_FIELD("box_size","int32",32,4,SX_SIZE),
    SX_FIELD("virial_size","int32",36,4,SX_SIZE),
    SX_FIELD("pressure_size","int32",40,4,SX_SIZE),
    SX_FIELD("topology_size","int32",44,4,SX_SIZE),
    SX_FIELD("symbols_size","int32",48,4,SX_SIZE),
    SX_FIELD("coordinates_size","int32",52,4,SX_SIZE),
    SX_FIELD("velocities_size","int32",56,4,SX_SIZE),
    SX_FIELD("forces_size","int32",60,4,SX_SIZE),
    SX_FIELD("atom_count","int32",64,4,SX_COUNT_PROP),
    SX_FIELD("step","int32",68,4,SX_NONE),
    SX_FIELD("nre","int32",72,4,SX_NONE),
};
const sx_layout sxsh_trr_header = {UINT32_C(0x602a0018),"trr_header",sxsh_trr_header_fields,SX_COUNT(sxsh_trr_header_fields),SX_BE};
static const xx_data_struct_field_desc sxsh_trr_time32_fields[] = {
    SX_FIELD("time","float32",0,4,SX_NONE),
    SX_FIELD("lambda","float32",4,4,SX_NONE),
};
const sx_layout sxsh_trr_time32 = {UINT32_C(0x602a0019),"trr_time32",sxsh_trr_time32_fields,SX_COUNT(sxsh_trr_time32_fields),SX_BE};
static const xx_data_struct_field_desc sxsh_trr_time64_fields[] = {
    SX_FIELD("time","float64",0,8,SX_NONE),
    SX_FIELD("lambda","float64",8,8,SX_NONE),
};
const sx_layout sxsh_trr_time64 = {UINT32_C(0x602a001a),"trr_time64",sxsh_trr_time64_fields,SX_COUNT(sxsh_trr_time64_fields),SX_BE};
static bool sxsh_trr(sx_context *c)
{
 int64_t at=0;
 for(unsigned frame=0;at<c->size;frame++){
  uint8_t b[76];if(frame>=512||!sx_read(c,at,b,76)||sxsh32(b,true)!=1993||sxsh32(b+4,true)!=13||sxsh32(b+8,true)!=12||xx_rt_memcmp(b+12,"GMX_trn_file\0",12))return false;
  uint32_t sizes[10],atoms=sxsh32(b+64,true),width=0;uint64_t bytes=0;
  if(!atoms||atoms>1048576)return false;for(unsigned i=0;i<10;i++){sizes[i]=sxsh32(b+24+i*4,true);bytes+=sizes[i];}
  if(sizes[2])width=sizes[2]/9;else for(unsigned i=7;i<10&&!width;i++)if(sizes[i])width=sizes[i]/(atoms*3);
  if((width!=4&&width!=8)||sizes[0]||sizes[1]||sizes[5]||sizes[6]||!sxsh_span(c,at,76+width*2+bytes)||!sxsh_add(c,&sxsh_trr_header,at,76)||!sxsh_add(c,width==4?&sxsh_trr_time32:&sxsh_trr_time64,at+76,width*2))return false;
  for(unsigned i=2;i<=4;i++)if(sizes[i]&&sizes[i]!=width*9)return false;
  for(unsigned i=7;i<10;i++)if(sizes[i]&&sizes[i]!=width*3*atoms)return false;
  at+=76+width*2+(int64_t)bytes;
 }return at>0&&at==c->size;
}
bool sx_gromacs_trr_build(sx_context*c)
{
 bool ok=false;
 ok=sxsh_trr(c);
 return ok&&sxsh_finish(c);
}
