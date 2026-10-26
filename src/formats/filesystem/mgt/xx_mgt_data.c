/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * MGT data structures, moved out of the disktail schema family. */
#include "../../xx_format_schema_disktail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#if SX_ALIAS_READER_FACTORY && defined(CPM)
#include "xxfclib/formats/filesystem/cpm/xx_cpm.h"
#endif

static const xx_data_struct_field_desc sxdt_mgt_directory_core_fields[] = {
    SX_FIELD("type_and_flags","uint8",0,1,SX_FLAGS),
    SX_FIELD("filename","char[10]",1,10,SX_NONE),
    SX_FIELD("sectors_used","uint16be",11,2,SX_COUNT_PROP),
    SX_FIELD("first_track_and_side","uint8",13,1,SX_NONE),
    SX_FIELD("first_sector","uint8",14,1,SX_NONE),
    SX_FIELD("allocation_bitmap","byte[195]",15,195,SX_NONE),
};
const sx_layout sxdt_mgt_directory_core = {0x607a0019U,"mgt_directory_core",sxdt_mgt_directory_core_fields,SX_COUNT(sxdt_mgt_directory_core_fields),SX_LE};
static const xx_data_struct_field_desc sxdt_mgt_sector_link_fields[] = {
    SX_FIELD("next_track_and_side","uint8",0,1,SX_NONE),
    SX_FIELD("next_sector","uint8",1,1,SX_NONE),
};
const sx_layout sxdt_mgt_sector_link = {0x607a001aU,"mgt_sector_link",sxdt_mgt_sector_link_fields,SX_COUNT(sxdt_mgt_sector_link_fields),SX_LE};
static const xx_data_struct_field_desc sxdt_mgt_compatibility_tail_fields[] = {
    SX_FIELD("legacy_header","byte[10]",0,10,SX_NONE),
};
const sx_layout sxdt_mgt_compatibility_tail = {0x607a003aU,"mgt_compatibility_tail",sxdt_mgt_compatibility_tail_fields,SX_COUNT(sxdt_mgt_compatibility_tail_fields),SX_LE};
static const xx_data_struct_field_desc sxdt_mgt_disk_label_fields[] = {
    SX_FIELD("disk_label","char[10]",0,10,SX_NONE),
};
const sx_layout sxdt_mgt_disk_label = {0x607a003bU,"mgt_disk_label",sxdt_mgt_disk_label_fields,SX_COUNT(sxdt_mgt_disk_label_fields),SX_LE};
static const xx_data_struct_field_desc sxdt_mgt_sam_tail_fields[] = {
    SX_FIELD("flags","uint8",0,1,SX_FLAGS),
    SX_FIELD("file_type_information","byte[11]",1,11,SX_NONE),
    SX_FIELD("reserved1","byte[4]",12,4,SX_RESERVED),
    SX_FIELD("start_page","uint8",16,1,SX_NONE),
    SX_FIELD("start_offset","uint16",17,2,SX_NONE),
    SX_FIELD("length_pages","uint8",19,1,SX_COUNT_PROP),
    SX_FIELD("length_remainder","uint16",20,2,SX_NONE),
    SX_FIELD("execution_page","uint8",22,1,SX_NONE),
    SX_FIELD("execution_offset_or_line","uint16",23,2,SX_NONE),
    SX_FIELD("save_day","uint8",25,1,SX_NONE),
    SX_FIELD("save_month","uint8",26,1,SX_NONE),
    SX_FIELD("save_year","uint8",27,1,SX_NONE),
    SX_FIELD("save_hour","uint8",28,1,SX_NONE),
    SX_FIELD("save_minute","uint8",29,1,SX_NONE),
    SX_FIELD("directory_tag","uint8",30,1,SX_ID),
    SX_FIELD("reserved2","uint8",31,1,SX_RESERVED),
    SX_FIELD("disk_identifier","uint16be",32,2,SX_ID),
    SX_FIELD("parent_directory_tag","uint8",34,1,SX_ID),
    SX_FIELD("extra_directory_tracks","uint8",35,1,SX_COUNT_PROP),
};
const sx_layout sxdt_mgt_sam_tail = {0x607a003cU,"mgt_sam_tail",sxdt_mgt_sam_tail_fields,SX_COUNT(sxdt_mgt_sam_tail_fields),SX_LE};
static const xx_data_struct_field_desc sxdt_mgt_dos_file_header_fields[] = {
    SX_FIELD("file_type","uint8",0,1,SX_ID),
    SX_FIELD("length_remainder","uint16",1,2,SX_NONE),
    SX_FIELD("start_offset","uint16",3,2,SX_NONE),
    SX_FIELD("parameter","uint16",5,2,SX_NONE),
    SX_FIELD("length_pages","uint8",7,1,SX_COUNT_PROP),
    SX_FIELD("start_page","uint8",8,1,SX_NONE),
};
const sx_layout sxdt_mgt_dos_file_header = {0x607a003dU,"mgt_dos_file_header",sxdt_mgt_dos_file_header_fields,SX_COUNT(sxdt_mgt_dos_file_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdt_mgt_legacy_tail_fields[] = {
    SX_FIELD("type_specific_storage","byte[36]",0,36,SX_NONE),
};
const sx_layout sxdt_mgt_legacy_tail = {0x607a0065U,"mgt_legacy_tail",sxdt_mgt_legacy_tail_fields,SX_COUNT(sxdt_mgt_legacy_tail_fields),SX_LE};
#define SXDT_LIMIT 24000U
#define SXDT_ADD(c,l,p) sxdt_put(c,&sxdt_##l,p,1)
static bool sxdt_mgt_position(unsigned track,unsigned sector,uint64_t*out){if(sector<1||sector>10||(track&127)>=80)return false;*out=((uint64_t)(track&127)*2+(track>>7))*5120+(sector-1)*512;return true;}
static bool sxdt_mgt_entry(sx_context*c,uint64_t p,bool first){uint8_t e[256];if(!sxdt_read(c,p,e,sizeof(e)))return false;unsigned type=e[0]&63;if(!SXDT_ADD(c,mgt_directory_core,p)||!sxdt_put(c,first&&type>=16?&sxdt_mgt_disk_label:&sxdt_mgt_compatibility_tail,p+210,1)||!sxdt_put(c,type>=16&&type<=31?&sxdt_mgt_sam_tail:&sxdt_mgt_legacy_tail,p+220,1))return false;if(!type||type==21)return true;unsigned count=sxdt16(e+11,1),t=e[13],s=e[14];if(count>1560)return true;uint8_t seen[195]={0};for(unsigned i=0;i<count&&c->count<SXDT_LIMIT;i++){uint64_t at;if(!sxdt_mgt_position(t,s,&at)||(!(t&128)&&t<4))break;unsigned bit=((t&127)+((t&128)?80:0)-4)*10+s-1;if(bit>=1560||!(e[15+bit/8]&(1U<<(bit%8)))||(seen[bit/8]&(1U<<(bit%8))))break;seen[bit/8]|=(uint8_t)(1U<<(bit%8));if(!i&&((type>=1&&type<=4)||type==7||(type>=16&&type<=20))&&!SXDT_ADD(c,mgt_dos_file_header,at))return false;if(!SXDT_ADD(c,mgt_sector_link,at+510))return false;uint8_t link[2];if(!sxdt_read(c,at+510,link,2))break;t=link[0];s=link[1];if(!t&&!s)break;}return true;}
static bool sxdt_mgt(sx_context*c){if(c->size<819200)return false;uint8_t used[195]={0},first[256],e[256];if(!sxdt_read(c,0,first,256))return false;for(unsigned t=0;t<4;t++)for(unsigned j=0;j<20;j++){uint64_t p=(uint64_t)t*10240+j*256;if(!sxdt_read(c,p,e,256)||!sxdt_mgt_entry(c,p,t==0&&j==0))return false;if((e[0]&63)&&(e[0]&63)!=21)for(unsigned k=0;k<195;k++)used[k]|=e[15+k];}unsigned extra=first[255],type=first[0]&63;if(extra<1||extra>35||type==5||type==9)return true;for(unsigned bit=1;bit<extra*10;bit++)if(used[bit/8]&(1U<<(bit%8)))return true;for(unsigned t=4;t<4+extra;t++)for(unsigned s=1;s<=10;s++){if(t==4&&s==1&&(used[0]&1))continue;uint64_t p;if(!sxdt_mgt_position(t,s,&p))return false;if(!sxdt_mgt_entry(c,p,false)||!sxdt_mgt_entry(c,p+256,false))return false;}return true;}
bool sx_mgt_build(sx_context*c)
{
bool ok=false;
ok=sxdt_mgt(c);
return ok&&c->count&&sxdt_finish(c);
}
