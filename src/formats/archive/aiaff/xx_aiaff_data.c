/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * AIAFF data structures, moved out of the archiveobsolete schema family. */
#include "../../xx_format_schema_archiveobsolete.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxao_aiaff_header_fields[] = {
 SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("member_table_offset","ascii_decimal[12]",8,12,SX_OFFSET),
 SX_FIELD("symbol_table_offset","ascii_decimal[12]",20,12,SX_OFFSET),
 SX_FIELD("first_member_offset","ascii_decimal[12]",32,12,SX_OFFSET),
 SX_FIELD("last_member_offset","ascii_decimal[12]",44,12,SX_OFFSET),
 SX_FIELD("free_list_offset","ascii_decimal[12]",56,12,SX_OFFSET),
};
const sx_layout sxao_aiaff_header = {UINT32_C(0x60700039),"aiaff_header",sxao_aiaff_header_fields,SX_COUNT(sxao_aiaff_header_fields),SX_LE};
static const xx_data_struct_field_desc sxao_aiaff_member_fields[] = {
 SX_FIELD("payload_size","ascii_decimal[12]",0,12,SX_SIZE),
 SX_FIELD("next_member_offset","ascii_decimal[12]",12,12,SX_OFFSET),
 SX_FIELD("previous_member_offset","ascii_decimal[12]",24,12,SX_OFFSET),
 SX_FIELD("modification_time","ascii_decimal[12]",36,12,SX_TIME),
 SX_FIELD("user_id","ascii_decimal[12]",48,12,SX_NONE),
 SX_FIELD("group_id","ascii_decimal[12]",60,12,SX_NONE),
 SX_FIELD("mode","ascii_octal_padded[12]",72,12,SX_FLAGS),
 SX_FIELD("name_size","ascii_decimal[4]",84,4,SX_SIZE),
};
const sx_layout sxao_aiaff_member = {UINT32_C(0x6070003a),"aiaff_member",sxao_aiaff_member_fields,SX_COUNT(sxao_aiaff_member_fields),SX_LE};
static const xx_data_struct_field_desc sxao_aiaff_terminator_fields[] = {
 SX_FIELD("terminator","char[2]",0,2,SX_SIGNATURE),
};
const sx_layout sxao_aiaff_terminator = {UINT32_C(0x6070003b),"aiaff_terminator",sxao_aiaff_terminator_fields,SX_COUNT(sxao_aiaff_terminator_fields),SX_LE};
#define SXAO_LIMIT 20000U
static bool sxao_decimal(sx_context*c,uint64_t p,unsigned n,uint64_t*v){uint8_t b[24];if(!n||n>24||!sxao_read(c,p,b,n))return false;*v=0;unsigned first=0,last=n;while(first<last&&(b[first]==' '||b[first]=='\t'))first++;while(last>first&&(b[last-1]==' '||b[last-1]=='\t'||b[last-1]=='\r'||b[last-1]=='\n'))last--;for(unsigned i=first;i<last;i++){if(b[i]<'0'||b[i]>'9'||*v>(UINT64_MAX-(b[i]-'0'))/10)return false;*v=*v*10+(b[i]-'0');}return true;}
static bool sxao_aiaff(sx_context*c){uint64_t p,last;if(!sxao_decimal(c,32,12,&p)||!sxao_decimal(c,44,12,&last)||!sxao_add(c,&sxao_aiaff_header,0))return false;uint64_t anchor=p,power=1,length=0;for(size_t work=0;p&&work<SXAO_LIMIT;work++){uint64_t n,next;if(!sxao_decimal(c,p+84,4,&n)||!sxao_decimal(c,p+12,12,&next)||!sxao_add(c,&sxao_aiaff_member,p)||!sxao_span(c,p+88,n+(n&1)+2)||!sxao_text(c,&sxao_archiveobsolete_name,p+88,n,false)||!sxao_add(c,&sxao_aiaff_terminator,p+88+n+(n&1)))return false;if(p==last||!next)break;if(next==anchor)return false;if(++length==power){anchor=next;length=0;if(power<=SXAO_LIMIT/2)power*=2;}p=next;}return true;}
bool sx_aiaff_build(sx_context*c)
{
 return sxao_aiaff(c);
}
