/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * VMDK_SESPARSE data structures, moved out of the systemlater schema family. */
#include "../../xx_format_schema_systemlater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsl_sesparse_header_fields[] = {
    SX_FIELD("magic","uint64",0,8,SX_SIGNATURE),
    SX_FIELD("version","uint64",8,8,SX_NONE),
    SX_FIELD("capacity_sectors","uint64",16,8,SX_COUNT_PROP),
    SX_FIELD("grain_sectors","uint64",24,8,SX_COUNT_PROP),
    SX_FIELD("table_sectors","uint64",32,8,SX_COUNT_PROP),
    SX_FIELD("flags","uint64",40,8,SX_FLAGS),
    SX_FIELD("reserved1","uint64[4]",48,32,SX_RESERVED),
    SX_FIELD("volatile_header_sector","uint64",80,8,SX_NONE),
    SX_FIELD("volatile_header_sectors","uint64",88,8,SX_COUNT_PROP),
    SX_FIELD("journal_header_sector","uint64",96,8,SX_NONE),
    SX_FIELD("journal_header_sectors","uint64",104,8,SX_COUNT_PROP),
    SX_FIELD("journal_sector","uint64",112,8,SX_NONE),
    SX_FIELD("journal_sectors","uint64",120,8,SX_COUNT_PROP),
    SX_FIELD("grain_directory_sector","uint64",128,8,SX_NONE),
    SX_FIELD("grain_directory_sectors","uint64",136,8,SX_COUNT_PROP),
    SX_FIELD("grain_tables_sector","uint64",144,8,SX_NONE),
    SX_FIELD("grain_tables_sectors","uint64",152,8,SX_COUNT_PROP),
    SX_FIELD("free_bitmap_sector","uint64",160,8,SX_NONE),
    SX_FIELD("free_bitmap_sectors","uint64",168,8,SX_COUNT_PROP),
    SX_FIELD("back_map_sector","uint64",176,8,SX_NONE),
    SX_FIELD("back_map_sectors","uint64",184,8,SX_COUNT_PROP),
    SX_FIELD("grains_sector","uint64",192,8,SX_NONE),
    SX_FIELD("grains_sectors","uint64",200,8,SX_COUNT_PROP),
    SX_FIELD("reserved2","byte[304]",208,304,SX_RESERVED),
};
const sx_layout sxsl_sesparse_header = {0x6033004fU,"sesparse_header",sxsl_sesparse_header_fields,SX_COUNT(sxsl_sesparse_header_fields),SX_LE};
static const xx_data_struct_field_desc sxsl_sesparse_volatile_fields[] = {
    SX_FIELD("magic","uint64",0,8,SX_SIGNATURE),
    SX_FIELD("free_table_number","uint64",8,8,SX_NONE),
    SX_FIELD("next_transaction_number","uint64",16,8,SX_NONE),
    SX_FIELD("replay_journal","uint64",24,8,SX_FLAGS),
    SX_FIELD("reserved","byte[480]",32,480,SX_RESERVED),
};
const sx_layout sxsl_sesparse_volatile = {0x60330050U,"sesparse_volatile",sxsl_sesparse_volatile_fields,SX_COUNT(sxsl_sesparse_volatile_fields),SX_LE};
static const xx_data_struct_field_desc sxsl_sesparse_directory_fields[] = {
    SX_FIELD("table_index_and_flags","uint64",0,8,SX_FLAGS),
};
const sx_layout sxsl_sesparse_directory = {0x60330051U,"sesparse_directory",sxsl_sesparse_directory_fields,SX_COUNT(sxsl_sesparse_directory_fields),SX_LE};
static const xx_data_struct_field_desc sxsl_sesparse_grain_fields[] = {
    SX_FIELD("grain_index_and_type","uint64",0,8,SX_FLAGS),
};
const sx_layout sxsl_sesparse_grain = {0x60330052U,"sesparse_grain",sxsl_sesparse_grain_fields,SX_COUNT(sxsl_sesparse_grain_fields),SX_LE};
#define SXSL_LIMIT 24000U
#define SXSL_ROWS 1048576U
#define SXSL_ADD(c,l,p) sxsl_put(c,&sxsl_##l,p,1)
#define SXSL_TABLE(c,l,p,n) sxsl_put(c,&sxsl_##l,p,n)
static bool sxsl_sesparse(sx_context*c){uint8_t h[208];if(!sxsl_read(c,0,h,208)||!SXSL_ADD(c,sesparse_header,0))return false;uint64_t v=sxsl_uint(h+80,8,false),gd=sxsl_uint(h+128,8,false),gs=sxsl_uint(h+136,8,false),tables=sxsl_uint(h+144,8,false),table_size=sxsl_uint(h+152,8,false),cap=sxsl_uint(h+16,8,false),grain=sxsl_uint(h+24,8,false);if(v<=(uint64_t)c->size/512&&sxsl_span(c,v*512,512)&&!SXSL_ADD(c,sesparse_volatile,v*512))return false;if(!grain||grain>UINT64_MAX/4096)return true;uint64_t cover=grain*4096,needed=cap/cover+(cap%cover!=0);if(needed>SXSL_ROWS||gd>(uint64_t)c->size/512||gs>UINT64_MAX/512||needed>gs*64||!sxsl_span(c,gd*512,needed*8)||!SXSL_TABLE(c,sesparse_directory,gd*512,needed))return true;for(uint64_t i=0;i<needed&&c->count<SXSL_LIMIT;i++){uint64_t word;if(!sxsl_word(c,gd*512+8*i,8,false,&word))return false;if((word>>32)!=0x10000000)continue;uint64_t index=(uint32_t)word;if(index>=table_size/64||tables>UINT64_MAX-index*64)continue;uint64_t p=tables+index*64;if(p<=(uint64_t)c->size/512&&sxsl_span(c,p*512,32768)&&!SXSL_TABLE(c,sesparse_grain,p*512,4096))return false;}return true;}
bool sx_vmdk_sesparse_build(sx_context*c)
{
bool ok=false;
ok=sxsl_sesparse(c);
return ok&&sxsl_finish(c);
}
