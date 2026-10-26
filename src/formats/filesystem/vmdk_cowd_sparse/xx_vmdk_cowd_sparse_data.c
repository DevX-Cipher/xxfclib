/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * VMDK_COWD_SPARSE data structures, moved out of the systemlater schema family. */
#include "../../xx_format_schema_systemlater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsl_cowd_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",4,4,SX_NONE),
    SX_FIELD("flags","uint32",8,4,SX_FLAGS),
    SX_FIELD("capacity_sectors","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("grain_sectors","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("directory_sector","uint32",20,4,SX_NONE),
    SX_FIELD("directory_count","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("next_free_sector","uint32",28,4,SX_NONE),
};
const sx_layout sxsl_cowd_header = {0x60330049U,"cowd_header",sxsl_cowd_header_fields,SX_COUNT(sxsl_cowd_header_fields),SX_LE};
static const xx_data_struct_field_desc sxsl_cowd_root_fields[] = {
    SX_FIELD("cylinder_count","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("head_count","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("reserved","byte[1016]",12,1016,SX_RESERVED),
};
const sx_layout sxsl_cowd_root = {0x6033004aU,"cowd_root",sxsl_cowd_root_fields,SX_COUNT(sxsl_cowd_root_fields),SX_LE};
static const xx_data_struct_field_desc sxsl_cowd_child_fields[] = {
    SX_FIELD("parent_filename","char[1024]",0,1024,SX_NONE),
    SX_FIELD("parent_generation","uint32",1024,4,SX_NONE),
};
const sx_layout sxsl_cowd_child = {0x6033004bU,"cowd_child",sxsl_cowd_child_fields,SX_COUNT(sxsl_cowd_child_fields),SX_LE};
static const xx_data_struct_field_desc sxsl_cowd_tail_fields[] = {
    SX_FIELD("generation","uint32",0,4,SX_NONE),
    SX_FIELD("name","char[60]",4,60,SX_NONE),
    SX_FIELD("description","char[512]",64,512,SX_NONE),
    SX_FIELD("saved_generation","uint32",576,4,SX_NONE),
    SX_FIELD("reserved1","byte[8]",580,8,SX_RESERVED),
    SX_FIELD("dirty","uint32",588,4,SX_FLAGS),
    SX_FIELD("reserved2","byte[396]",592,396,SX_RESERVED),
};
const sx_layout sxsl_cowd_tail = {0x6033004cU,"cowd_tail",sxsl_cowd_tail_fields,SX_COUNT(sxsl_cowd_tail_fields),SX_LE};
static const xx_data_struct_field_desc sxsl_cowd_directory_fields[] = {
    SX_FIELD("table_sector","uint32",0,4,SX_NONE),
};
const sx_layout sxsl_cowd_directory = {0x6033004dU,"cowd_directory",sxsl_cowd_directory_fields,SX_COUNT(sxsl_cowd_directory_fields),SX_LE};
static const xx_data_struct_field_desc sxsl_cowd_grain_fields[] = {
    SX_FIELD("grain_sector","uint32",0,4,SX_NONE),
};
const sx_layout sxsl_cowd_grain = {0x6033004eU,"cowd_grain",sxsl_cowd_grain_fields,SX_COUNT(sxsl_cowd_grain_fields),SX_LE};
#define SXSL_LIMIT 24000U
#define SXSL_ROWS 1048576U
#define SXSL_ADD(c,l,p) sxsl_put(c,&sxsl_##l,p,1)
#define SXSL_TABLE(c,l,p,n) sxsl_put(c,&sxsl_##l,p,n)
static bool sxsl_cowd(sx_context*c){uint8_t h[32];if(!sxsl_read(c,0,h,32)||!SXSL_ADD(c,cowd_header,0))return false;uint64_t gd=(uint64_t)sxsl32(h+20)*512,n=sxsl32(h+24),capacity=sxsl32(h+12),grain=sxsl32(h+16);if(gd>=2048&&sxsl_span(c,32,2016)){if(!sxsl_put(c,(sxsl32(h+8)&1)?&sxsl_cowd_root:&sxsl_cowd_child,32,1)||!SXSL_ADD(c,cowd_tail,1060))return false;}if(!grain||!capacity)return true;uint64_t needed=(capacity+grain*4096-1)/(grain*4096);if(n<needed||needed>SXSL_ROWS||gd<32||!sxsl_span(c,gd,needed*4)||!SXSL_TABLE(c,cowd_directory,gd,needed))return true;for(uint64_t i=0;i<needed&&c->count<SXSL_LIMIT;i++){uint64_t p;if(!sxsl_word(c,gd+i*4,4,false,&p))return false;p*=512;if(p>=32&&sxsl_span(c,p,16384)&&!SXSL_TABLE(c,cowd_grain,p,4096))return false;}return true;}
bool sx_vmdk_cowd_sparse_build(sx_context*c)
{
bool ok=false;
ok=sxsl_cowd(c);
return ok&&sxsl_finish(c);
}
