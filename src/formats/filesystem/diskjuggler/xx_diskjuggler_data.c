/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Diskjuggler data structures, moved out of the volumeimages schema family. */
#include "../../xx_format_schema_volumeimages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxvi_cdi_footer_v2_fields[] = {
    SX_FIELD("version","uint32",0,4,SX_ID),
    SX_FIELD("descriptor_offset","uint32",4,4,SX_OFFSET),
};
const sx_layout sxvi_cdi_footer_v2 = {0x60530056U,"cdi_footer_v2",sxvi_cdi_footer_v2_fields,SX_COUNT(sxvi_cdi_footer_v2_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_cdi_footer_v35_fields[] = {
    SX_FIELD("version","uint32",0,4,SX_ID),
    SX_FIELD("descriptor_distance","uint32",4,4,SX_SIZE),
};
const sx_layout sxvi_cdi_footer_v35 = {0x60530057U,"cdi_footer_v35",sxvi_cdi_footer_v35_fields,SX_COUNT(sxvi_cdi_footer_v35_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_cdi_descriptor_header_fields[] = {
    SX_FIELD("session_count","uint16",0,2,SX_COUNT_PROP),
};
const sx_layout sxvi_cdi_descriptor_header = {0x60530058U,"cdi_descriptor_header",sxvi_cdi_descriptor_header_fields,SX_COUNT(sxvi_cdi_descriptor_header_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_cdi_track_prefix_fields[] = {
    SX_FIELD("markers","byte[20]",0,20,SX_SIGNATURE),
    SX_FIELD("unknown","byte[4]",20,4,SX_NONE),
    SX_FIELD("filename_length","uint8",24,1,SX_SIZE),
};
const sx_layout sxvi_cdi_track_prefix = {0x60530059U,"cdi_track_prefix",sxvi_cdi_track_prefix_fields,SX_COUNT(sxvi_cdi_track_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_cdi_index_count_fields[] = {
    SX_FIELD("count","uint16",0,2,SX_COUNT_PROP),
};
const sx_layout sxvi_cdi_index_count = {0x6053005aU,"cdi_index_count",sxvi_cdi_index_count_fields,SX_COUNT(sxvi_cdi_index_count_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_cdi_index_fields[] = {
    SX_FIELD("sectors","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxvi_cdi_index = {0x6053005bU,"cdi_index",sxvi_cdi_index_fields,SX_COUNT(sxvi_cdi_index_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_cdi_cdtext_count_fields[] = {
    SX_FIELD("count","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxvi_cdi_cdtext_count = {0x6053005cU,"cdi_cdtext_count",sxvi_cdi_cdtext_count_fields,SX_COUNT(sxvi_cdi_cdtext_count_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_cdi_track_geometry_fields[] = {
    SX_FIELD("unknown0","byte[2]",0,2,SX_NONE),
    SX_FIELD("mode","uint32",2,4,SX_ID),
    SX_FIELD("unknown1","byte[4]",6,4,SX_NONE),
    SX_FIELD("session_index","uint32",10,4,SX_NONE),
    SX_FIELD("track_index","uint32",14,4,SX_NONE),
    SX_FIELD("start_sector","uint32",18,4,SX_NONE),
    SX_FIELD("sector_count","uint32",22,4,SX_COUNT_PROP),
    SX_FIELD("unknown2","byte[16]",26,16,SX_NONE),
    SX_FIELD("read_mode","uint32",42,4,SX_ID),
};
const sx_layout sxvi_cdi_track_geometry = {0x6053005dU,"cdi_track_geometry",sxvi_cdi_track_geometry_fields,SX_COUNT(sxvi_cdi_track_geometry_fields),SX_LE};
#define SXVI_LIMIT 24000U
#define SXVI_ADD(c,l,p) sxvi_put(c,&sxvi_##l,p,1)
#define SXVI_TABLE(c,l,p,n) sxvi_put(c,&sxvi_##l,p,n)
static bool sxvi_cdi(sx_context*c){uint8_t f[8];if(c->size<16||!sxvi_read(c,(uint64_t)c->size-8,f,8))return false;uint32_t version=sxvi32(f,0);uint64_t off=sxvi32(f+4,0),end=(uint64_t)c->size-8;if(version<0x80000004U||version>0x80000006U)return false;uint64_t p=version==0x80000006U?(off<=(uint64_t)c->size?(uint64_t)c->size-off:UINT64_MAX):off;if(p>=end||end-p<2||end-p>UINT64_C(16777216))return false;if(!sxvi_put(c,version==0x80000006U?&sxvi_cdi_footer_v35:&sxvi_cdi_footer_v2,end,1)||!SXVI_ADD(c,cdi_descriptor_header,p))return false;
 size_t n=(size_t)(end-p);uint8_t*h=xx_rt_malloc(n);if(!h)return false;if(!sxvi_read(c,p,h,n)){xx_rt_free(h);return false;}static const uint8_t mark[10]={0,0,1,0,0,0,255,255,255,255};bool ok=true;unsigned sessions=sxvi16(h,0);
 for(uint64_t at=2;at+25<=n&&c->count<SXVI_LIMIT;at++){if(xx_rt_memcmp(h+at,mark,10)||xx_rt_memcmp(h+at+10,mark,10))continue;uint64_t names=h[at+24],ic=at+56+names;if(ic>n||n-ic<2)continue;unsigned indices=sxvi16(h+ic,0);if(indices>64||indices*4U>n-ic-2)continue;uint64_t tc=ic+2+indices*4;if(n-tc<4)continue;uint64_t text=sxvi32(h+tc,0);if(text>4096||text*18>n-tc-4)continue;uint64_t fixed=tc+4+text*18;if(n-fixed<46||h[fixed+2]>2||sxvi32(h+fixed+42,0)>2||sxvi32(h+fixed+10,0)>=sessions||sxvi32(h+fixed+14,0)>999)continue;
  if(!SXVI_ADD(c,cdi_track_prefix,p+at)||!SXVI_ADD(c,cdi_index_count,p+ic)||!SXVI_TABLE(c,cdi_index,p+ic+2,indices)||!SXVI_ADD(c,cdi_cdtext_count,p+tc)||!SXVI_ADD(c,cdi_track_geometry,p+fixed)){ok=false;break;}at+=19;
 }xx_rt_free(h);return ok;
}
bool sx_diskjuggler_build(sx_context*c)
{
 return sxvi_cdi(c);
}
#undef SXVI_LIMIT
#undef SXVI_ADD
#undef SXVI_TABLE
