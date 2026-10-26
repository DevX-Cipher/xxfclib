/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Broadcom CFE data structures, moved out of the cfefirmware schema family. */
#include "../../xx_format_schema_cfefirmware.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"

static const xx_data_struct_field_desc sxcfefw_header_fields[]={
 SX_FIELD("seal","uint8[4]",0,4,SX_SIGNATURE),
 SX_FIELD("flags","uint32",4,4,SX_FLAGS),
 SX_FIELD("payload_size","uint32",8,4,SX_SIZE),
 SX_FIELD("payload_crc32","uint32",12,4,SX_CHECKSUM),
 SX_FIELD("board_name","char[32]",16,32,SX_STRING),
 SX_FIELD("major_version","uint8",48,1,SX_NONE),
 SX_FIELD("minor_version","uint8",49,1,SX_NONE),
 SX_FIELD("eco_version","uint8",50,1,SX_NONE),
 SX_FIELD("misc_version","uint8",51,1,SX_NONE),
 SX_FIELD("reserved","uint8[12]",52,12,SX_RESERVED),
};
const sx_layout sxcfefw_header={UINT32_C(0x609f0001),"cfe_flash_update_header",sxcfefw_header_fields,SX_COUNT(sxcfefw_header_fields),SX_BE};
static uint32_t sxcfefw_be32(const uint8_t*p){return((uint32_t)p[0]<<24)|((uint32_t)p[1]<<16)|((uint32_t)p[2]<<8)|p[3];}
static bool sxcfefw_update(sx_context*c){
 uint8_t h[64],b[8192];uint32_t crc=0;uint64_t done=0;bool terminated=false;
 if(c->size<64||!sx_read(c,0,h,64)||xx_rt_memcmp(h,"CFE1",4))return false;
 uint32_t n=sxcfefw_be32(h+8);if(!n||n>UINT32_C(67108864)||(uint64_t)n>(uint64_t)c->size-64)return false;
 for(unsigned i=16;i<48;i++)if(!h[i])terminated=true;if(!terminated)return false;
 while(done<n){size_t z=(uint64_t)n-done>sizeof(b)?sizeof(b):(size_t)((uint64_t)n-done);if(xx_pd_is_stopped(c->pd)||!sx_read(c,64+(int64_t)done,b,z))return false;crc=xx_crc32_calc(crc,b,z);done+=z;}
 if(~crc!=sxcfefw_be32(h+12))return false;
 return sx_add(c,&sxcfefw_header,0,64)&&sx_raw(c,64,c->size-64);
}
bool sx_cfe_build(sx_context*c)
{
 if(sxcfefw_update(c))return true;
 if(c->failed||xx_pd_is_stopped(c->pd))return false;
 uint8_t seal[8];
 return c->size>=36&&sx_read(c,28,seal,8)&&!xx_rt_memcmp(seal,"CFE1CFE1",8)&&sx_raw(c,0,c->size);
}
