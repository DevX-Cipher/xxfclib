/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * COPYTAPE data structures, moved out of the systemtail schema family. */
#include "../../xx_format_schema_systemtail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxst_copytape_block_fields[] = {
    SX_FIELD("marker","char[9]",0,9,SX_SIGNATURE),
    SX_FIELD("block_length","ascii_decimal[6]",9,6,SX_SIZE),
    SX_FIELD("line_feed","uint8",15,1,SX_ID),
};
const sx_layout sxst_copytape_block = {0x60370024U,"copytape_block",sxst_copytape_block_fields,SX_COUNT(sxst_copytape_block_fields),SX_LE};
static const xx_data_struct_field_desc sxst_copytape_mark_fields[] = {
    SX_FIELD("prefix","char[5]",0,5,SX_SIGNATURE),
    SX_FIELD("kind","char[3]",5,3,SX_ID),
    SX_FIELD("line_feed","uint8",8,1,SX_ID),
};
const sx_layout sxst_copytape_mark = {0x60370025U,"copytape_mark",sxst_copytape_mark_fields,SX_COUNT(sxst_copytape_mark_fields),SX_LE};
static const xx_data_struct_field_desc sxst_copytape_separator_fields[] = {
    SX_FIELD("line_feed","uint8",0,1,SX_ID),
};
const sx_layout sxst_copytape_separator = {0x60370026U,"copytape_separator",sxst_copytape_separator_fields,SX_COUNT(sxst_copytape_separator_fields),SX_LE};
#define SXST_LIMIT 24000U
#define SXST_ADD(c,l,p) sxst_put(c,&sxst_##l,p,1)
static bool sxst_copytape(sx_context*c){uint64_t p=0;uint8_t b[16];for(unsigned i=0;i<100000&&c->count<SXST_LIMIT;i++){if(!sxst_read(c,p,b,9))break;if(!xx_rt_memcmp(b,"CPTP:MRK\n",9)||!xx_rt_memcmp(b,"CPTP:EOT\n",9)){if(!SXST_ADD(c,copytape_mark,p))return false;p+=9;if(b[5]=='E')break;continue;}if(xx_rt_memcmp(b,"CPTP:BLK ",9)||!sxst_read(c,p,b,16)||b[15]!=10)break;uint64_t z=0;bool valid=true;for(unsigned j=9;j<15;j++){if(b[j]<'0'||b[j]>'9'){valid=false;break;}z=z*10+b[j]-'0';}if(!valid||!z||!sxst_span(c,p,17+z)||!SXST_ADD(c,copytape_block,p)||!SXST_ADD(c,copytape_separator,p+16+z))break;p+=17+z;}return c->count>0;}
bool sx_copytape_build(sx_context*c)
{
 return sxst_copytape(c);
}
#undef SXST_LIMIT
#undef SXST_ADD
