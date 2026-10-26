/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * RAWCD data structures, moved out of the disktail schema family. */
#include "../../xx_format_schema_disktail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#if SX_ALIAS_READER_FACTORY && defined(CPM)
#include "xxfclib/formats/filesystem/cpm/xx_cpm.h"
#endif

static const xx_data_struct_field_desc sxdt_rawcd_sector_header_fields[] = {
    SX_FIELD("sync","byte[12]",0,12,SX_SIGNATURE),
    SX_FIELD("minute_bcd","uint8",12,1,SX_NONE),
    SX_FIELD("second_bcd","uint8",13,1,SX_NONE),
    SX_FIELD("frame_bcd","uint8",14,1,SX_NONE),
    SX_FIELD("mode","uint8",15,1,SX_ID),
};
const sx_layout sxdt_rawcd_sector_header = {0x607a0016U,"rawcd_sector_header",sxdt_rawcd_sector_header_fields,SX_COUNT(sxdt_rawcd_sector_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdt_rawcd_xa_subheader_fields[] = {
    SX_FIELD("file_number","uint8",0,1,SX_ID),
    SX_FIELD("channel_number","uint8",1,1,SX_ID),
    SX_FIELD("submode","uint8",2,1,SX_FLAGS),
    SX_FIELD("coding_information","uint8",3,1,SX_FLAGS),
    SX_FIELD("file_number_copy","uint8",4,1,SX_ID),
    SX_FIELD("channel_number_copy","uint8",5,1,SX_ID),
    SX_FIELD("submode_copy","uint8",6,1,SX_FLAGS),
    SX_FIELD("coding_information_copy","uint8",7,1,SX_FLAGS),
};
const sx_layout sxdt_rawcd_xa_subheader = {0x607a0017U,"rawcd_xa_subheader",sxdt_rawcd_xa_subheader_fields,SX_COUNT(sxdt_rawcd_xa_subheader_fields),SX_LE};
static const xx_data_struct_field_desc sxdt_rawcd_edc_fields[] = {
    SX_FIELD("edc","uint32",0,4,SX_CHECKSUM),
};
const sx_layout sxdt_rawcd_edc = {0x607a0018U,"rawcd_edc",sxdt_rawcd_edc_fields,SX_COUNT(sxdt_rawcd_edc_fields),SX_LE};
#define SXDT_LIMIT 24000U
#define SXDT_ADD(c,l,p) sxdt_put(c,&sxdt_##l,p,1)
static int sxdt_cd_frames(const uint8_t*b){static const uint8_t sync[]={0,255,255,255,255,255,255,255,255,255,255,0};if(xx_rt_memcmp(b,sync,12))return -1;unsigned n[3];for(unsigned i=0;i<3;i++){unsigned v=b[12+i];if((v&15)>9||(v>>4)>9)return -1;n[i]=(v>>4)*10+(v&15);}if(n[1]>=60||n[2]>=75)return -1;return(int)(n[0]*4500+n[1]*75+n[2]);}
static bool sxdt_cd_descriptor(sx_context*c,uint64_t p){uint8_t b[7];return sxdt_read(c,p,b,7)&&(b[0]<=3||b[0]==255)&&b[6]==1&&(!xx_rt_memcmp(b+1,"CD001",5)||!xx_rt_memcmp(b+1,"CD-I ",5));}
static bool sxdt_rawcd(sx_context*c){
 uint8_t first[24],b[24];unsigned stride=0,data=0;bool synced=false;static const unsigned sizes[]={2352,2448,2368};
 if(!sxdt_read(c,0,first,24))return false;int frames=sxdt_cd_frames(first);
 if(frames>=0&&(first[15]==1||first[15]==2))for(unsigned i=0;i<SX_COUNT(sizes);i++)if(sxdt_read(c,sizes[i],b,24)&&sxdt_cd_frames(b)==frames+1&&b[15]<=2){stride=sizes[i];data=first[15]==1?16:24;synced=true;break;}
 if(!stride){static const unsigned z[]={2336,2352,2352,2448,2448},d[]={8,16,24,16,24};for(unsigned i=0;i<SX_COUNT(z);i++){if((uint64_t)c->size%z[i]||!sxdt_cd_descriptor(c,(uint64_t)z[i]*16+d[i])||!sxdt_cd_descriptor(c,(uint64_t)z[i]*17+d[i]))continue;if(i){if(!sxdt_read(c,(uint64_t)z[i]*16,b,24)||sxdt_cd_frames(b)<0||b[15]!=(d[i]==16?1:2))continue;}stride=z[i];data=d[i];synced=i!=0;break;}}
 if(!stride)return false;uint64_t sectors=(uint64_t)c->size/stride;if(sectors>1000000)sectors=1000000;
 for(uint64_t i=0;i<sectors&&c->count<SXDT_LIMIT;i++){
  uint64_t p=i*stride;if(!sxdt_read(c,p,b,24))break;unsigned mode=2,xa=0;
  if(synced){if(sxdt_cd_frames(b)<0)continue;mode=b[15]&3;if(mode>2)continue;if(!SXDT_ADD(c,rawcd_sector_header,p))return false;xa=16;}
  if(mode==1){if(!SXDT_ADD(c,rawcd_edc,p+2064))return false;}
  else if(mode==2){if(xx_rt_memcmp(b+xa,b+xa+4,4))continue;if(!SXDT_ADD(c,rawcd_xa_subheader,p+xa)||!SXDT_ADD(c,rawcd_edc,p+xa+8+((b[xa+2]&32)?2324:2048)))return false;}
 }
 (void)data;return c->count!=0;
}
bool sx_rawcd_build(sx_context*c)
{
bool ok=false;
ok=sxdt_rawcd(c);
return ok&&c->count&&sxdt_finish(c);
}
