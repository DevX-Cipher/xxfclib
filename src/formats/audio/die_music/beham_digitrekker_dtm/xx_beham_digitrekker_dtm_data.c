/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * beham_digitrekker_dtm data structures, moved out of the nextmusic schema family. */
#include "../../../xx_format_schema_nextmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnextm_track16_fields[]={
 SX_FIELD("track_index","uint16",0,2,SX_ID),
};
const sx_layout sxnextm_track16={UINT32_C(0x608B0007),"track16",sxnextm_track16_fields,SX_COUNT(sxnextm_track16_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_chunk_le_fields[]={
 SX_FIELD("chunk_id","bytes",0,4,SX_ID),
 SX_FIELD("payload_bytes","uint32",4,4,SX_SIZE),
};
const sx_layout sxnextm_chunk_le={UINT32_C(0x608B0009),"chunk_le",sxnextm_chunk_le_fields,SX_COUNT(sxnextm_chunk_le_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_dtm_info_fields[]={
 SX_FIELD("channels","uint16",0,2,SX_COUNT_PROP),
 SX_FIELD("sequence_length","uint16",2,2,SX_COUNT_PROP),
 SX_FIELD("patterns","uint16",4,2,SX_COUNT_PROP),
 SX_FIELD("tracks","uint16",6,2,SX_COUNT_PROP),
 SX_FIELD("instruments","uint16",8,2,SX_COUNT_PROP),
};
const sx_layout sxnextm_dtm_info={UINT32_C(0x608B0019),"dtm_info",sxnextm_dtm_info_fields,SX_COUNT(sxnextm_dtm_info_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_dtm_speed_fields[]={
 SX_FIELD("frames_per_row","uint16",0,2,SX_NONE),
 SX_FIELD("beats_per_minute","uint16",2,2,SX_NONE),
};
const sx_layout sxnextm_dtm_speed={UINT32_C(0x608B001A),"dtm_speed",sxnextm_dtm_speed_fields,SX_COUNT(sxnextm_dtm_speed_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_dtm_pan_fields[]={
 SX_FIELD("left_volume","uint8",0,1,SX_NONE),
 SX_FIELD("right_volume","uint8",1,1,SX_NONE),
};
const sx_layout sxnextm_dtm_pan={UINT32_C(0x608B001B),"dtm_pan",sxnextm_dtm_pan_fields,SX_COUNT(sxnextm_dtm_pan_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_dtm_rows_fields[]={
 SX_FIELD("rows","uint16",0,2,SX_COUNT_PROP),
};
const sx_layout sxnextm_dtm_rows={UINT32_C(0x608B001D),"dtm_rows",sxnextm_dtm_rows_fields,SX_COUNT(sxnextm_dtm_rows_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_dtm_instrument_fields[]={
 SX_FIELD("instrument","uint8",0,1,SX_ID),
};
const sx_layout sxnextm_dtm_instrument={UINT32_C(0x608B001F),"dtm_instrument",sxnextm_dtm_instrument_fields,SX_COUNT(sxnextm_dtm_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_dtm_argument_high_fields[]={
 SX_FIELD("argument_high","uint8",0,1,SX_NONE),
};
const sx_layout sxnextm_dtm_argument_high={UINT32_C(0x608B0022),"dtm_argument_high",sxnextm_dtm_argument_high_fields,SX_COUNT(sxnextm_dtm_argument_high_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_dtm_argument_low_fields[]={
 SX_FIELD("argument_low","uint8",0,1,SX_NONE),
};
const sx_layout sxnextm_dtm_argument_low={UINT32_C(0x608B0023),"dtm_argument_low",sxnextm_dtm_argument_low_fields,SX_COUNT(sxnextm_dtm_argument_low_fields),SX_LE};
#define NX_ROW(l,at,end) sxnextm_row(v,&sxnextm_##l,(at),(end))
#define NX_TAKE(l,p,n,end) sxnextm_take(v,&sxnextm_##l,(p),(n),(end))
static bool sxnextm_dtm_chunks(sxnextm_view*v,uint64_t p,uint64_t e,unsigned context,unsigned depth){if(depth>3)return false;while(p<e){uint8_t id[4];uint64_t z;if(!sxnextm_read(v,p,id,4,e)||!sxnextm_u(v,p+4,4,&z,e)||!NX_ROW(chunk_le,p,e)||!sxnextm_span(v,p+8,z,e))return false;uint64_t b=p+8,end=b+z;
 if((!xx_rt_memcmp(id,"SONG",4)&&depth==0)||(!xx_rt_memcmp(id,"INIT",4)&&context==1)||(!xx_rt_memcmp(id,"INST",4)&&context==1)||(!xx_rt_memcmp(id,"TRAK",4)&&context==1)||(!xx_rt_memcmp(id,"SAMP",4)&&context==1)){unsigned next=!xx_rt_memcmp(id,"SONG",4)?1:!xx_rt_memcmp(id,"INIT",4)?2:!xx_rt_memcmp(id,"INST",4)?3:!xx_rt_memcmp(id,"TRAK",4)?4:5;if(!sxnextm_dtm_chunks(v,b,end,next,depth+1))return false;}
 else if(context==1&&!xx_rt_memcmp(id,"INFO",4)){if(!NX_ROW(dtm_info,b,end))return false;}
 else if((context==1&&!xx_rt_memcmp(id,"NAME",4))||((context==3||context==5)&&!xx_rt_memcmp(id,"text",4))){if(!sxnextm_text_emit(v,b,z,end))return false;}
 else if(context==2&&!xx_rt_memcmp(id,"sped",4)){if(!NX_ROW(dtm_speed,b,end))return false;}
 else if(context==2&&!xx_rt_memcmp(id,"vpan",4)){if(z%2||!sxnextm_table(v,&sxnextm_dtm_pan,b,z/2,end))return false;}
 else if(context==1&&!xx_rt_memcmp(id,"PSEQ",4)){if(!sxnextm_table(v,&sxnextm_order8,b,z,end))return false;}
 else if(context==1&&!xx_rt_memcmp(id,"PATT",4)){if(z%2||!sxnextm_table(v,&sxnextm_track16,b,z/2,end))return false;}
 else if(context==3&&!xx_rt_memcmp(id,"samp",4)){if(!NX_ROW(dtm_sample,b,end))return false;}
 else if(context==4&&!xx_rt_memcmp(id,"trak",4)){uint64_t n,q=b;if(!sxnextm_u(v,b,2,&n,end)||!NX_TAKE(dtm_rows,&q,1,end)||!NX_TAKE(dtm_pitch,&q,n,end)||!NX_TAKE(dtm_instrument,&q,n,end)||!NX_TAKE(dtm_volume,&q,n,end)||!NX_TAKE(dtm_effect,&q,n,end)||!NX_TAKE(dtm_argument_high,&q,n,end)||!NX_TAKE(dtm_argument_low,&q,n,end))return false;}
 p=end;}return true;}
static bool sxnextm_dtm(sxnextm_view*v){uint64_t e=(uint64_t)v->c->size,z;return sxnextm_eq(v,0,"SONG",4,e)&&sxnextm_u(v,4,4,&z,e)&&sxnextm_span(v,8,z,e)&&sxnextm_dtm_chunks(v,0,8+z,0,0);}
bool sx_beham_digitrekker_dtm_build(sxnextm_view*v)
{
 return sxnextm_dtm(v);
}
#undef NX_ROW
#undef NX_TAKE
