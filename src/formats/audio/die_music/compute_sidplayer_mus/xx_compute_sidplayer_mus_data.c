/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Compute! Sidplayer MUS data structures, moved out of the musiclogs schema family. */
#include "../../../xx_format_schema_musiclogs.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxlog_sidplayer_header_fields[]={
 SX_FIELD("load_address","uint16",0,2,SX_ADDRESS),
 SX_FIELD("voice_1_size","uint16",2,2,SX_SIZE),
 SX_FIELD("voice_2_size","uint16",4,2,SX_SIZE),
 SX_FIELD("voice_3_size","uint16",6,2,SX_SIZE),
};
const sx_layout sxlog_sidplayer_header={0x608c000cU,"sidplayer_header",sxlog_sidplayer_header_fields,SX_COUNT(sxlog_sidplayer_header_fields),SX_LE};
static const xx_data_struct_field_desc sxlog_sidplayer_command_fields[]={
 SX_FIELD("command","uint8",0,1,SX_FLAGS),
 SX_FIELD("option","uint8",1,1,SX_FLAGS),
};
const sx_layout sxlog_sidplayer_command={0x608c000dU,"sidplayer_command",sxlog_sidplayer_command_fields,SX_COUNT(sxlog_sidplayer_command_fields),SX_LE};
static const xx_data_struct_field_desc sxlog_sidplayer_halt_fields[]={
 SX_FIELD("halt_command","uint16",0,2,SX_FLAGS),
};
const sx_layout sxlog_sidplayer_halt={0x608c000eU,"sidplayer_halt",sxlog_sidplayer_halt_fields,SX_COUNT(sxlog_sidplayer_halt_fields),SX_BE};
static const xx_data_struct_field_desc sxlog_sidplayer_description_fields[]={
 SX_FIELD("petscii_bytes","uint8",0,0,SX_NONE),
};
const sx_layout sxlog_sidplayer_description={0x608c000fU,"sidplayer_description",sxlog_sidplayer_description_fields,SX_COUNT(sxlog_sidplayer_description_fields),SX_LE};
static bool sxlog_sid(sx_context*c)
{uint16_t n[3];int64_t at=8;uint8_t halt[2];if(!sx_u16(c,2,false,n)||!sx_u16(c,4,false,n+1)||!sx_u16(c,6,false,n+2))return false;
 for(unsigned i=0;i<3;i++){if(n[i]<2||(n[i]&1)||!sx_range(c,at,n[i])||!sx_read(c,at+n[i]-2,halt,2)||halt[0]!=1||halt[1]!=0x4f)return false;at+=n[i];}
 if(!sx_add(c,&sxlog_sidplayer_header,0,8))return false;at=8;
 for(unsigned i=0;i<3;i++){if(!sx_table(c,&sxlog_sidplayer_command,at,2,n[i]/2-1)||!sx_add(c,&sxlog_sidplayer_halt,at+n[i]-2,2))return false;at+=n[i];}
 if(at<c->size){int64_t end=at;uint8_t b;while(end<c->size&&end-at<4096){if(!sx_read(c,end++,&b,1))return false;if(!b)break;}if(!sx_add(c,&sxlog_sidplayer_description,at,end-at))return false;at=end;}
 return sx_raw(c,at,c->size-at);}
bool sx_compute_sidplayer_mus_build(sx_context*c)
{
 return sxlog_sid(c);
}
