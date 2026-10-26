/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ATARI DOS2 data structures, moved out of the retrofs schema family. */
#include "../../xx_format_schema_retrofs.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxrfs_atari_atr_header_fields[] = {
    SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("paragraphs_low","uint16",2,2,SX_NONE),
    SX_FIELD("sector_size","uint16",4,2,SX_SIZE),
    SX_FIELD("paragraphs_high","uint8",6,1,SX_NONE),
    SX_FIELD("reserved","byte[8]",7,8,SX_RESERVED),
    SX_FIELD("flags","uint8",15,1,SX_FLAGS),
};
const sx_layout sxrfs_atari_atr_header = {0x6065001cU,"atari_atr_header",sxrfs_atari_atr_header_fields,SX_COUNT(sxrfs_atari_atr_header_fields),SX_LE};
static const xx_data_struct_field_desc sxrfs_atari_dos2_vtoc_fields[] = {
    SX_FIELD("dos_code","uint8",0,1,SX_ID),
    SX_FIELD("total_available_sectors","uint16",1,2,SX_COUNT_PROP),
    SX_FIELD("free_sectors","uint16",3,2,SX_COUNT_PROP),
    SX_FIELD("reserved","byte[5]",5,5,SX_RESERVED),
    SX_FIELD("free_sector_bitmap","byte[90]",10,90,SX_FLAGS),
};
const sx_layout sxrfs_atari_dos2_vtoc = {0x6065001dU,"atari_dos2_vtoc",sxrfs_atari_dos2_vtoc_fields,SX_COUNT(sxrfs_atari_dos2_vtoc_fields),SX_LE};
static const xx_data_struct_field_desc sxrfs_atari_dos2_directory_entry_fields[] = {
    SX_FIELD("flags","uint8",0,1,SX_FLAGS),
    SX_FIELD("sector_count","uint16",1,2,SX_COUNT_PROP),
    SX_FIELD("first_sector","uint16",3,2,SX_NONE),
    SX_FIELD("name","byte[8]",5,8,SX_NONE),
    SX_FIELD("extension","byte[3]",13,3,SX_NONE),
};
const sx_layout sxrfs_atari_dos2_directory_entry = {0x6065001eU,"atari_dos2_directory_entry",sxrfs_atari_dos2_directory_entry_fields,SX_COUNT(sxrfs_atari_dos2_directory_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxrfs_atari_dos2_sector_trailer_fields[] = {
    SX_FIELD("file_index_and_next_high","uint8",0,1,SX_FLAGS),
    SX_FIELD("next_sector_low","uint8",1,1,SX_NONE),
    SX_FIELD("used_bytes","uint8",2,1,SX_SIZE),
};
const sx_layout sxrfs_atari_dos2_sector_trailer = {0x6065001fU,"atari_dos2_sector_trailer",sxrfs_atari_dos2_sector_trailer_fields,SX_COUNT(sxrfs_atari_dos2_sector_trailer_fields),SX_LE};
static const xx_data_struct_field_desc sxrfs_atari_dos25_extended_vtoc_fields[] = {
    SX_FIELD("primary_bitmap_mirror","byte[84]",0,84,SX_FLAGS),
    SX_FIELD("extended_free_bitmap","byte[38]",84,38,SX_FLAGS),
    SX_FIELD("extended_free_sectors","uint16",122,2,SX_COUNT_PROP),
};
const sx_layout sxrfs_atari_dos25_extended_vtoc = {0x6065004aU,"atari_dos25_extended_vtoc",sxrfs_atari_dos25_extended_vtoc_fields,SX_COUNT(sxrfs_atari_dos25_extended_vtoc_fields),SX_LE};
#define SXRFS_ADD(c,l,p) sxrfs_put(c,&sxrfs_##l,p,1)
static uint64_t sxrfs_atari_pos(unsigned s,unsigned z){return 16+(s<=3?(uint64_t)(s-1)*128:384+(uint64_t)(s-4)*z);}
static bool sxrfs_atari(sx_context*c){uint8_t h[16],b[128];if(!sxrfs_read(c,0,h,16)||sxrfs16(h,0)!=0x296)return false;unsigned z=sxrfs16(h+4,0);uint64_t bytes=((uint64_t)sxrfs16(h+2,0)|((uint64_t)h[6]<<16))*16;if((z!=128&&z!=256)||!sxrfs_span(c,16,bytes)||!SXRFS_ADD(c,atari_atr_header,0)||!SXRFS_ADD(c,atari_dos2_vtoc,sxrfs_atari_pos(360,z)))return false;if(bytes==133120&&!SXRFS_ADD(c,atari_dos25_extended_vtoc,sxrfs_atari_pos(1024,z)))return false;
 for(unsigned d=361;d<=368;d++){uint64_t p=sxrfs_atari_pos(d,z);if(!sxrfs_read(c,p,b,128))break;for(unsigned j=0;j<8;j++){const uint8_t*e=b+j*16;if(!(e[0]&0x40)||e[0]&0x80)continue;if(!SXRFS_ADD(c,atari_dos2_directory_entry,p+j*16))return false;unsigned sector=sxrfs16(e+3,0),count=sxrfs16(e+1,0);for(unsigned k=0;k<count&&k<1040&&sector; k++){if(sector>1040)break;uint64_t at=sxrfs_atari_pos(sector,z)+(sector<=3?128:z)-3;uint8_t tail[3];if(!sxrfs_read(c,at,tail,3))break;if(!SXRFS_ADD(c,atari_dos2_sector_trailer,at))return false;sector=((tail[0]&3)<<8)|tail[1];}}}return true;}
bool sx_atari_dos2_build(sx_context*c)
{
 return sxrfs_atari(c);
}
#undef SXRFS_ADD
