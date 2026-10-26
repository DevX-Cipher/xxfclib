/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * PLAN9_PARTITIONS data structures, moved out of the disktail schema family. */
#include "../../xx_format_schema_disktail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#if SX_ALIAS_READER_FACTORY && defined(CPM)
#include "xxfclib/formats/filesystem/cpm/xx_cpm.h"
#endif

static const xx_data_struct_field_desc sxdt_plan9_keyword_fields[] = {
    SX_FIELD("keyword","utf8",0,0,SX_ID),
};
const sx_layout sxdt_plan9_keyword = {0x607a0042U,"plan9_keyword",sxdt_plan9_keyword_fields,SX_COUNT(sxdt_plan9_keyword_fields),SX_LE};
static const xx_data_struct_field_desc sxdt_plan9_name_fields[] = {
    SX_FIELD("name","utf8",0,0,SX_NONE),
};
const sx_layout sxdt_plan9_name = {0x607a0043U,"plan9_name",sxdt_plan9_name_fields,SX_COUNT(sxdt_plan9_name_fields),SX_LE};
static const xx_data_struct_field_desc sxdt_plan9_first_sector_fields[] = {
    SX_FIELD("first_sector","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxdt_plan9_first_sector = {0x607a0044U,"plan9_first_sector",sxdt_plan9_first_sector_fields,SX_COUNT(sxdt_plan9_first_sector_fields),SX_LE};
static const xx_data_struct_field_desc sxdt_plan9_end_sector_fields[] = {
    SX_FIELD("exclusive_end_sector","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxdt_plan9_end_sector = {0x607a0045U,"plan9_end_sector",sxdt_plan9_end_sector_fields,SX_COUNT(sxdt_plan9_end_sector_fields),SX_LE};
#define SXDT_LIMIT 24000U
static bool sxdt_plan9(sx_context*c){uint8_t b[512];if(!sxdt_read(c,512,b,512)||xx_rt_memcmp(b,"part ",5))return false;/* Native reserves finalbyte for a string terminator. */size_t p=0,n=511;while(p<n&&b[p]&&c->count<SXDT_LIMIT){size_t end=p;while(end<n&&b[end]&&b[end]!='\n')end++;size_t word[4],len[4],k=0;while(p<end&&k<4){while(p<end&&sxdt_space(b[p]))p++;word[k]=p;while(p<end&&!sxdt_space(b[p]))p++;len[k]=p-word[k];k++;}if(k==4&&sxdt_eq(b+word[0],len[0],"part")){if(!sxdt_value(c,&sxdt_plan9_keyword,512+word[0],len[0])||!sxdt_value(c,&sxdt_plan9_name,512+word[1],len[1])||!sxdt_value(c,&sxdt_plan9_first_sector,512+word[2],len[2])||!sxdt_value(c,&sxdt_plan9_end_sector,512+word[3],len[3]))return false;}p=end+1;}return c->count!=0;}
bool sx_plan9_partitions_build(sx_context*c)
{
bool ok=false;
ok=sxdt_plan9(c);
return ok&&c->count&&sxdt_finish(c);
}
