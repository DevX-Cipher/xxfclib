/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * PASCAL_PROFILE_MANAGER data structures, moved out of the disktail schema family. */
#include "../../xx_format_schema_disktail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#if SX_ALIAS_READER_FACTORY && defined(CPM)
#include "xxfclib/formats/filesystem/cpm/xx_cpm.h"
#endif

static const xx_data_struct_field_desc sxdt_ppm_header_fields[] = {
    SX_FIELD("area_blocks","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("volume_count","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("signature_length","uint8",4,1,SX_SIZE),
    SX_FIELD("signature","char[3]",5,3,SX_SIGNATURE),
    SX_FIELD("unused","byte[8]",8,8,SX_NONE),
};
const sx_layout sxdt_ppm_header = {0x607a0005U,"ppm_header",sxdt_ppm_header_fields,SX_COUNT(sxdt_ppm_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdt_ppm_volume_entry_fields[] = {
    SX_FIELD("absolute_start_block","uint16",0,2,SX_NONE),
    SX_FIELD("block_count","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("default_unit","uint8",4,1,SX_ID),
    SX_FIELD("write_protection","uint8",5,1,SX_FLAGS),
    SX_FIELD("old_driver_address","uint16",6,2,SX_ADDRESS),
};
const sx_layout sxdt_ppm_volume_entry = {0x607a0006U,"ppm_volume_entry",sxdt_ppm_volume_entry_fields,SX_COUNT(sxdt_ppm_volume_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxdt_ppm_volume_description_fields[] = {
    SX_FIELD("length","uint8",0,1,SX_SIZE),
    SX_FIELD("description","char[15]",1,15,SX_NONE),
};
const sx_layout sxdt_ppm_volume_description = {0x607a0007U,"ppm_volume_description",sxdt_ppm_volume_description_fields,SX_COUNT(sxdt_ppm_volume_description_fields),SX_LE};
static const xx_data_struct_field_desc sxdt_ppm_cached_volume_name_fields[] = {
    SX_FIELD("length","uint8",0,1,SX_SIZE),
    SX_FIELD("name","char[7]",1,7,SX_NONE),
};
const sx_layout sxdt_ppm_cached_volume_name = {0x607a0008U,"ppm_cached_volume_name",sxdt_ppm_cached_volume_name_fields,SX_COUNT(sxdt_ppm_cached_volume_name_fields),SX_LE};
#define SXDT_ADD(c,l,p) sxdt_put(c,&sxdt_##l,p,1)
#define SXDT_TABLE(c,l,p,n) sxdt_put(c,&sxdt_##l,p,n)
static bool sxdt_ppm(sx_context*c){sxdt_view v={c,0,(uint64_t)c->size,0};uint8_t h[512],seen[8192]={0};if(!sxdt_av_prodos(&v))return false;unsigned block=2;uint64_t area=0;for(unsigned walk=0;block&&walk<65536;walk++){if(block>=65536||(seen[block/8]&(1U<<(block%8)))||!sxdt_read(c,(uint64_t)block*512,h,512))break;seen[block/8]|=(uint8_t)(1U<<(block%8));for(unsigned i=block==2?1:0;i<13;i++){uint8_t*e=h+4+i*39;if((e[0]>>4)==4&&(e[0]&15)==11&&!xx_rt_memcmp(e+1,"PASCAL.AREA",11)&&e[16]==239)area=(uint64_t)sxdt16(e+17,0)*512;}block=sxdt16(h+2,0);}if(!area||!sxdt_read(c,area,h,16)||xx_rt_memcmp(h+4,"\003PPM",4))return false;unsigned count=sxdt16(h+2,0);if(!count||count>31||!SXDT_ADD(c,ppm_header,area)||!SXDT_TABLE(c,ppm_volume_entry,area+16,count)||!SXDT_TABLE(c,ppm_volume_description,area+256,32)||!SXDT_TABLE(c,ppm_cached_volume_name,area+768,32))return false;for(unsigned i=0;i<count;i++){if(!sxdt_read(c,area+16+i*8,h,8))return false;uint64_t p=(uint64_t)sxdt16(h,0)*512,n=(uint64_t)sxdt16(h+2,0)*512;if(!sxdt_span(c,p,n))return false;sxdt_view child={c,p,n,0};if(!sxdt_av_pascal(&child))return false;}return true;}
bool sx_pascal_profile_manager_build(sx_context*c)
{
bool ok=false;
ok=sxdt_ppm(c);
return ok&&c->count&&sxdt_finish(c);
}
