/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * nintendo_wbfs data structures, moved out of the gameplatforms schema family. */
#include "../../xx_format_schema_gameplatforms.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgp_wbfs_header_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("host_sector_count","uint32",4,4,SX_COUNT_PROP),
 SX_FIELD("host_sector_shift","uint8",8,1,SX_NONE),
 SX_FIELD("wbfs_sector_shift","uint8",9,1,SX_NONE),
 SX_FIELD("reserved","bytes",10,2,SX_RESERVED),
 SX_FIELD("disc_table","bytes",12,500,SX_FLAGS),
};
const sx_layout sxgp_wbfs_header={UINT32_C(0x6036009C),"wbfs_header",sxgp_wbfs_header_fields,SX_COUNT(sxgp_wbfs_header_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_wbfs_disc_title_fields[]={
 SX_FIELD("title","char[64]",0,64,SX_STRING),
};
const sx_layout sxgp_wbfs_disc_title={UINT32_C(0x6036009D),"wbfs_disc_title",sxgp_wbfs_disc_title_fields,SX_COUNT(sxgp_wbfs_disc_title_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_wbfs_block_fields[]={
 SX_FIELD("physical_cluster","uint16",0,2,SX_NONE),
};
const sx_layout sxgp_wbfs_block={UINT32_C(0x6036009E),"wbfs_block",sxgp_wbfs_block_fields,SX_COUNT(sxgp_wbfs_block_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_wbfs_md5_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("digest","bytes",4,16,SX_CHECKSUM),
};
const sx_layout sxgp_wbfs_md5={UINT32_C(0x6036009F),"wbfs_md5",sxgp_wbfs_md5_fields,SX_COUNT(sxgp_wbfs_md5_fields),SX_LE};
#define SG_ROW(l,at,end) sxgp_row(v,&sxgp_##l,(at),(end))
static bool sxgp_wbfs(sxgp_view*v)
{uint64_t end=(uint64_t)v->c->size,shift,physical;uint8_t tag[4];if(!SG_ROW(wbfs_header,0,end)||!SG_ROW(gcm_id,512,end)||!SG_ROW(wbfs_disc_title,544,end)||!sxgp_word(v,9,1,false,&shift,end)||shift<19||shift>24)return false;
 uint64_t cluster=UINT64_C(1)<<shift,n=(UINT64_C(143432)*2*32768+cluster-1)/cluster;if(!sxgp_table(v,&sxgp_wbfs_block,768,n,end)||!sxgp_word(v,768,2,true,&physical,end)||!sxgp_span(v,physical*cluster,256,end)||!SG_ROW(gcm_id,physical*cluster,end)||!SG_ROW(wbfs_disc_title,physical*cluster+32,end))return false;
 if(!sxgp_read(v,512+236,tag,4,end))return false;return xx_rt_memcmp(tag,"MD5#",4)||SG_ROW(wbfs_md5,512+236,end);}
bool sx_nintendo_wbfs_build(sxgp_view*v)
{
 return sxgp_wbfs(v);
}
#undef SG_ROW
