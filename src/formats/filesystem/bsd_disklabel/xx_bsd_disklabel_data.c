/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Bsd Disklabel data structures, moved out of the volumeimages schema family. */
#include "../../xx_format_schema_volumeimages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxvi_bsd_disklabel_le_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("drive_type","uint16",4,2,SX_ID),
    SX_FIELD("subtype","uint16",6,2,SX_ID),
    SX_FIELD("type_name","char[16]",8,16,SX_STRING),
    SX_FIELD("pack_name","char[16]",24,16,SX_STRING),
    SX_FIELD("sector_size","uint32",40,4,SX_SIZE),
    SX_FIELD("sectors_per_track","uint32",44,4,SX_COUNT_PROP),
    SX_FIELD("tracks_per_cylinder","uint32",48,4,SX_COUNT_PROP),
    SX_FIELD("cylinders","uint32",52,4,SX_COUNT_PROP),
    SX_FIELD("sectors_per_cylinder","uint32",56,4,SX_COUNT_PROP),
    SX_FIELD("sectors_per_unit","uint32",60,4,SX_COUNT_PROP),
    SX_FIELD("spare_sectors_per_track","uint16",64,2,SX_COUNT_PROP),
    SX_FIELD("spare_sectors_per_cylinder","uint16",66,2,SX_COUNT_PROP),
    SX_FIELD("alternate_cylinders","uint32",68,4,SX_COUNT_PROP),
    SX_FIELD("rpm","uint16",72,2,SX_NONE),
    SX_FIELD("interleave","uint16",74,2,SX_NONE),
    SX_FIELD("track_skew","uint16",76,2,SX_NONE),
    SX_FIELD("cylinder_skew","uint16",78,2,SX_NONE),
    SX_FIELD("head_switch_microseconds","uint32",80,4,SX_NONE),
    SX_FIELD("track_seek_microseconds","uint32",84,4,SX_NONE),
    SX_FIELD("flags","uint32",88,4,SX_FLAGS),
    SX_FIELD("drive_data","uint32[5]",92,20,SX_NONE),
    SX_FIELD("spare","uint32[5]",112,20,SX_RESERVED),
    SX_FIELD("magic2","uint32",132,4,SX_SIGNATURE),
    SX_FIELD("checksum","uint16",136,2,SX_CHECKSUM),
    SX_FIELD("partition_count","uint16",138,2,SX_COUNT_PROP),
    SX_FIELD("boot_area_size","uint32",140,4,SX_SIZE),
    SX_FIELD("maximum_superblock_size","uint32",144,4,SX_SIZE),
};
const sx_layout sxvi_bsd_disklabel_le = {0x60530039U,"bsd_disklabel_le",sxvi_bsd_disklabel_le_fields,SX_COUNT(sxvi_bsd_disklabel_le_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_bsd_disklabel_be_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("drive_type","uint16",4,2,SX_ID),
    SX_FIELD("subtype","uint16",6,2,SX_ID),
    SX_FIELD("type_name","char[16]",8,16,SX_STRING),
    SX_FIELD("pack_name","char[16]",24,16,SX_STRING),
    SX_FIELD("sector_size","uint32",40,4,SX_SIZE),
    SX_FIELD("sectors_per_track","uint32",44,4,SX_COUNT_PROP),
    SX_FIELD("tracks_per_cylinder","uint32",48,4,SX_COUNT_PROP),
    SX_FIELD("cylinders","uint32",52,4,SX_COUNT_PROP),
    SX_FIELD("sectors_per_cylinder","uint32",56,4,SX_COUNT_PROP),
    SX_FIELD("sectors_per_unit","uint32",60,4,SX_COUNT_PROP),
    SX_FIELD("spare_sectors_per_track","uint16",64,2,SX_COUNT_PROP),
    SX_FIELD("spare_sectors_per_cylinder","uint16",66,2,SX_COUNT_PROP),
    SX_FIELD("alternate_cylinders","uint32",68,4,SX_COUNT_PROP),
    SX_FIELD("rpm","uint16",72,2,SX_NONE),
    SX_FIELD("interleave","uint16",74,2,SX_NONE),
    SX_FIELD("track_skew","uint16",76,2,SX_NONE),
    SX_FIELD("cylinder_skew","uint16",78,2,SX_NONE),
    SX_FIELD("head_switch_microseconds","uint32",80,4,SX_NONE),
    SX_FIELD("track_seek_microseconds","uint32",84,4,SX_NONE),
    SX_FIELD("flags","uint32",88,4,SX_FLAGS),
    SX_FIELD("drive_data","uint32[5]",92,20,SX_NONE),
    SX_FIELD("spare","uint32[5]",112,20,SX_RESERVED),
    SX_FIELD("magic2","uint32",132,4,SX_SIGNATURE),
    SX_FIELD("checksum","uint16",136,2,SX_CHECKSUM),
    SX_FIELD("partition_count","uint16",138,2,SX_COUNT_PROP),
    SX_FIELD("boot_area_size","uint32",140,4,SX_SIZE),
    SX_FIELD("maximum_superblock_size","uint32",144,4,SX_SIZE),
};
const sx_layout sxvi_bsd_disklabel_be = {0x6053003aU,"bsd_disklabel_be",sxvi_bsd_disklabel_be_fields,SX_COUNT(sxvi_bsd_disklabel_be_fields),SX_BE};
static const xx_data_struct_field_desc sxvi_bsd_partition_le_fields[] = {
    SX_FIELD("sector_count","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("start_sector","uint32",4,4,SX_NONE),
    SX_FIELD("fragment_size","uint32",8,4,SX_SIZE),
    SX_FIELD("filesystem_type","uint8",12,1,SX_ID),
    SX_FIELD("fragments_per_block","uint8",13,1,SX_COUNT_PROP),
    SX_FIELD("cylinders_per_group","uint16",14,2,SX_COUNT_PROP),
};
const sx_layout sxvi_bsd_partition_le = {0x6053003bU,"bsd_partition_le",sxvi_bsd_partition_le_fields,SX_COUNT(sxvi_bsd_partition_le_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_bsd_partition_be_fields[] = {
    SX_FIELD("sector_count","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("start_sector","uint32",4,4,SX_NONE),
    SX_FIELD("fragment_size","uint32",8,4,SX_SIZE),
    SX_FIELD("filesystem_type","uint8",12,1,SX_ID),
    SX_FIELD("fragments_per_block","uint8",13,1,SX_COUNT_PROP),
    SX_FIELD("cylinders_per_group","uint16",14,2,SX_COUNT_PROP),
};
const sx_layout sxvi_bsd_partition_be = {0x6053003cU,"bsd_partition_be",sxvi_bsd_partition_be_fields,SX_COUNT(sxvi_bsd_partition_be_fields),SX_BE};
#define SXVI_ORDER(l,o) ((o)==1?&sxvi_##l##_be:&sxvi_##l##_le)
static bool sxvi_bsd(sx_context*c){uint8_t h[148],b[1024];uint64_t limit=(uint64_t)c->size<8192?(uint64_t)c->size:8192;
 for(uint64_t p=0;p+148<=limit;p+=4){if(!sxvi_read(c,p,h,4))return false;unsigned o=sxvi32(h,0)==0x82564557U?0:sxvi32(h,1)==0x82564557U?1:2;if(o==2||!sxvi_read(c,p,h,148)||sxvi32(h+132,o)!=0x82564557U)continue;unsigned n=sxvi16(h+138,o);uint64_t bs=sxvi32(h+40,o),sectors=sxvi32(h+60,o);if(!n||n>64||!sxvi_pow(bs)||bs<128||bs>65536||!sectors||sectors>(uint64_t)c->size/bs||!sxvi_read(c,p+148,b,n*16))continue;uint16_t sum=0;for(unsigned j=0;j<148;j+=2)sum^=sxvi16(h+j,o);for(unsigned j=0;j<n*16;j+=2)sum^=sxvi16(b+j,o);if(sum)continue;
  return sxvi_put(c,SXVI_ORDER(bsd_disklabel,o),p,1)&&sxvi_put(c,SXVI_ORDER(bsd_partition,o),p+148,n);
 }return false;
}
bool sx_bsd_disklabel_build(sx_context*c)
{
 return sxvi_bsd(c);
}
#undef SXVI_ORDER
