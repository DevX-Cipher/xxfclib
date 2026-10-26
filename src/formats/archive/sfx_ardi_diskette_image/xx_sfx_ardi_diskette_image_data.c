/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ARDI self-extracting diskette image (Daniel F Valot, ARDI 4.31) data structures, moved out of the archivewire schema family. */
#include "../../xx_format_schema_archivewire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxarwire_ardi_geometry_record_fields[]={
 SX_FIELD("bytes_per_sector","uint16",0,2,SX_NONE),
 SX_FIELD("sectors_per_cluster","uint8",2,1,SX_NONE),
 SX_FIELD("reserved_sectors","uint16",3,2,SX_COUNT_PROP),
 SX_FIELD("fat_count","uint8",5,1,SX_COUNT_PROP),
 SX_FIELD("root_directory_entries","uint16",6,2,SX_COUNT_PROP),
 SX_FIELD("total_sectors","uint16",8,2,SX_COUNT_PROP),
 SX_FIELD("media_descriptor","uint8",10,1,SX_ID),
 SX_FIELD("sectors_per_fat","uint16",11,2,SX_COUNT_PROP),
 SX_FIELD("sectors_per_track","uint16",13,2,SX_COUNT_PROP),
 SX_FIELD("heads","uint16",15,2,SX_COUNT_PROP),
 SX_FIELD("hidden_sectors","uint32",17,4,SX_COUNT_PROP),
 SX_FIELD("large_total_sectors","uint32",21,4,SX_COUNT_PROP),
 SX_FIELD("drive_geometry","uint8[11]",25,11,SX_NONE),
 SX_FIELD("record_marker","uint16",36,2,SX_SIGNATURE),
 SX_FIELD("compressed_size","uint32",38,4,SX_SIZE),
 SX_FIELD("constant","uint32",42,4,SX_NONE),
 SX_FIELD("zero","uint8",46,1,SX_NONE),
 SX_FIELD("image_crc32","uint32",47,4,SX_CHECKSUM),
};
const sx_layout sxarwire_ardi_geometry_record={UINT32_C(0x608d0129),"ardi_geometry_record",sxarwire_ardi_geometry_record_fields,SX_COUNT(sxarwire_ardi_geometry_record_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_ardi_trailer_fields[]={
 SX_FIELD("opaque_prefix","uint8[20]",0,20,SX_NONE),
 SX_FIELD("copyright_prefix","char[13]",20,13,SX_NONE),
 SX_FIELD("copyright_year","ascii_decimal[4]",33,4,SX_NONE),
 SX_FIELD("author","char[13]",37,13,SX_NONE),
 SX_FIELD("terminator","uint8",50,1,SX_NONE),
};
const sx_layout sxarwire_ardi_trailer={UINT32_C(0x608d012a),"ardi_trailer",sxarwire_ardi_trailer_fields,SX_COUNT(sxarwire_ardi_trailer_fields),SX_LE};
static bool sxarwire_ardi(sx_context*c){Abstractformat*f=c->f;if(!f->create_archive_records_reading||!f->get_current_archive_record||!f->free_archive_records_reading)return false;xx_archive_record_state*s=(f->create_archive_records_reading)(f,NULL,c->pd);if(!s)return false;const xx_archive_record*r=(f->get_current_archive_record)(f,s);bool ok=false;
 if(r&&r->header_offset>=f->base_address&&r->header_size==51&&r->data_offset>=f->base_address&&r->compressed_size>0){uint64_t p=(uint64_t)(r->header_offset-f->base_address),d=(uint64_t)(r->data_offset-f->base_address),z=(uint64_t)r->compressed_size;uint8_t b[51];if(sxarwire_span(c,p,51)&&d==p+51&&sxarwire_span(c,d,z)&&sxarwire_span(c,d+z,51)&&d+z+51==(uint64_t)c->size&&sxarwire_read(c,p,b,51)&&sxarwire_num(b+38,4,false)==z)ok=sxarwire_put(c,&sxarwire_ardi_geometry_record,p)&&sxarwire_put(c,&sxarwire_ardi_trailer,d+z);}
 (f->free_archive_records_reading)(f,s);return ok;}
bool sx_sfx_ardi_diskette_image_build(sx_context*c)
{
 return sxarwire_ardi(c);
}
