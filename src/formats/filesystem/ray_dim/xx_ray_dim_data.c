/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * RAY_DIM data structures, moved out of the systemtail schema family. */
#include "../../xx_format_schema_systemtail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxst_raydim_header_indices_fields[] = {
    SX_FIELD("signature","char[80]",0,80,SX_SIGNATURE),
    SX_FIELD("disk_type","uint8",80,1,SX_ID),
    SX_FIELD("cylinders_indices","uint8",81,1,SX_NONE),
    SX_FIELD("sectors_per_track","uint8",82,1,SX_COUNT_PROP),
    SX_FIELD("heads_indices","uint8",83,1,SX_NONE),
};
const sx_layout sxst_raydim_header_indices = {0x6037002eU,"raydim_header_indices",sxst_raydim_header_indices_fields,SX_COUNT(sxst_raydim_header_indices_fields),SX_LE};
static const xx_data_struct_field_desc sxst_raydim_header_counts_fields[] = {
    SX_FIELD("signature","char[80]",0,80,SX_SIGNATURE),
    SX_FIELD("disk_type","uint8",80,1,SX_ID),
    SX_FIELD("cylinders_counts","uint8",81,1,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint8",82,1,SX_COUNT_PROP),
    SX_FIELD("heads_counts","uint8",83,1,SX_COUNT_PROP),
};
const sx_layout sxst_raydim_header_counts = {0x6037002fU,"raydim_header_counts",sxst_raydim_header_counts_fields,SX_COUNT(sxst_raydim_header_counts_fields),SX_LE};
static const xx_data_struct_field_desc sxst_raydim_sector_status_fields[] = {
    SX_FIELD("status","uint8",0,1,SX_FLAGS),
};
const sx_layout sxst_raydim_sector_status = {0x60370030U,"raydim_sector_status",sxst_raydim_sector_status_fields,SX_COUNT(sxst_raydim_sector_status_fields),SX_LE};
#define SXST_LIMIT 24000U
#define SXST_TABLE(c,l,p,n) sxst_put(c,&sxst_##l,p,n)
static bool sxst_ray(sx_context*c){uint8_t h[84];if(!sxst_read(c,0,h,84))return false;uint64_t n=(uint64_t)c->size,tracks=((uint64_t)h[81]+1)*(h[83]+1),bytes=(uint64_t)h[82]*512;bool original=h[83]<=1&&h[82]&&n==84+tracks*(bytes+h[82]);if(!sxst_put(c,original?&sxst_raydim_header_indices:&sxst_raydim_header_counts,0,1))return false;if(original)for(uint64_t i=0;i<tracks&&c->count<SXST_LIMIT;i++)if(!SXST_TABLE(c,raydim_sector_status,84+i*(bytes+h[82])+bytes,h[82]))return false;return true;}
bool sx_ray_dim_build(sx_context*c)
{
 return sxst_ray(c);
}
#undef SXST_LIMIT
#undef SXST_TABLE
