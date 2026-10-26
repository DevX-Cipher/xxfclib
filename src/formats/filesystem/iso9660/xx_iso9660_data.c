/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ISO 9660 (ECMA-119) data structures, moved out of the opticalfs schema family. */
#include "../../xx_format_schema_opticalfs.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxo_iso_path_table_l_fields[] = {
    SX_FIELD("identifier_length", "uint8", 0, 1, SX_SIZE),
    SX_FIELD("extended_attribute_blocks", "uint8", 1, 1, SX_COUNT_PROP),
    SX_FIELD("extent_lba", "uint32", 2, 4, SX_NONE),
    SX_FIELD("parent_directory_number", "uint16", 6, 2, SX_NONE),
};
const sx_layout sxo_iso_path_table_l = {UINT32_C(0x60130002),"iso_path_table_l",sxo_iso_path_table_l_fields,SX_COUNT(sxo_iso_path_table_l_fields),SX_LE};
static const xx_data_struct_field_desc sxo_iso_path_table_m_fields[] = {
    SX_FIELD("identifier_length", "uint8", 0, 1, SX_SIZE),
    SX_FIELD("extended_attribute_blocks", "uint8", 1, 1, SX_COUNT_PROP),
    SX_FIELD("extent_lba", "uint32", 2, 4, SX_NONE),
    SX_FIELD("parent_directory_number", "uint16", 6, 2, SX_NONE),
};
const sx_layout sxo_iso_path_table_m = {UINT32_C(0x60130003),"iso_path_table_m",sxo_iso_path_table_m_fields,SX_COUNT(sxo_iso_path_table_m_fields),SX_BE};
static const xx_data_struct_field_desc sxo_iso_primary_volume_descriptor_fields[] = {
    SX_FIELD("descriptor_type", "uint8", 0, 1, SX_ID),
    SX_FIELD("standard_identifier", "char[5]", 1, 5, SX_SIGNATURE),
    SX_FIELD("descriptor_version", "uint8", 6, 1, SX_ID),
    SX_FIELD("reserved_flags", "uint8", 7, 1, SX_RESERVED),
    SX_FIELD("system_identifier", "char[32]", 8, 32, SX_STRING),
    SX_FIELD("volume_identifier", "char[32]", 40, 32, SX_STRING),
    SX_FIELD("reserved0", "bytes", 72, 8, SX_RESERVED),
    SX_FIELD("volume_blocks_le", "uint32", 80, 4, SX_COUNT_PROP),
    SX_FIELD("volume_blocks_be", "uint32be", 84, 4, SX_COUNT_PROP),
    SX_FIELD("reserved_escape_sequences", "bytes", 88, 32, SX_RESERVED),
    SX_FIELD("volume_set_size_le", "uint16", 120, 2, SX_COUNT_PROP),
    SX_FIELD("volume_set_size_be", "uint16be", 122, 2, SX_COUNT_PROP),
    SX_FIELD("volume_sequence_le", "uint16", 124, 2, SX_NONE),
    SX_FIELD("volume_sequence_be", "uint16be", 126, 2, SX_NONE),
    SX_FIELD("logical_block_size_le", "uint16", 128, 2, SX_SIZE),
    SX_FIELD("logical_block_size_be", "uint16be", 130, 2, SX_SIZE),
    SX_FIELD("path_table_size_le", "uint32", 132, 4, SX_SIZE),
    SX_FIELD("path_table_size_be", "uint32be", 136, 4, SX_SIZE),
    SX_FIELD("l_path_table_lba", "uint32", 140, 4, SX_NONE),
    SX_FIELD("l_optional_path_table_lba", "uint32", 144, 4, SX_NONE),
    SX_FIELD("m_path_table_lba", "uint32be", 148, 4, SX_NONE),
    SX_FIELD("m_optional_path_table_lba", "uint32be", 152, 4, SX_NONE),
    SX_FIELD("root_record_length", "uint8", 156, 1, SX_SIZE),
    SX_FIELD("root_extended_attribute_blocks", "uint8", 157, 1, SX_COUNT_PROP),
    SX_FIELD("root_extent_lba_le", "uint32", 158, 4, SX_NONE),
    SX_FIELD("root_extent_lba_be", "uint32be", 162, 4, SX_NONE),
    SX_FIELD("root_data_length_le", "uint32", 166, 4, SX_SIZE),
    SX_FIELD("root_data_length_be", "uint32be", 170, 4, SX_SIZE),
    SX_FIELD("root_recorded_year_since_1900", "uint8", 174, 1, SX_NONE),
    SX_FIELD("root_recorded_month", "uint8", 175, 1, SX_NONE),
    SX_FIELD("root_recorded_day", "uint8", 176, 1, SX_NONE),
    SX_FIELD("root_recorded_hour", "uint8", 177, 1, SX_NONE),
    SX_FIELD("root_recorded_minute", "uint8", 178, 1, SX_NONE),
    SX_FIELD("root_recorded_second", "uint8", 179, 1, SX_NONE),
    SX_FIELD("root_recorded_timezone_quarters", "int8", 180, 1, SX_NONE),
    SX_FIELD("root_flags", "uint8", 181, 1, SX_FLAGS),
    SX_FIELD("root_file_unit_blocks", "uint8", 182, 1, SX_COUNT_PROP),
    SX_FIELD("root_interleave_gap_blocks", "uint8", 183, 1, SX_COUNT_PROP),
    SX_FIELD("root_volume_sequence_le", "uint16", 184, 2, SX_NONE),
    SX_FIELD("root_volume_sequence_be", "uint16be", 186, 2, SX_NONE),
    SX_FIELD("root_identifier_length", "uint8", 188, 1, SX_SIZE),
    SX_FIELD("root_identifier", "uint8", 189, 1, SX_NONE),
    SX_FIELD("volume_set_identifier", "char[128]", 190, 128, SX_STRING),
    SX_FIELD("publisher_identifier", "char[128]", 318, 128, SX_STRING),
    SX_FIELD("data_preparer_identifier", "char[128]", 446, 128, SX_STRING),
    SX_FIELD("application_identifier", "char[128]", 574, 128, SX_STRING),
    SX_FIELD("copyright_file_identifier", "char[37]", 702, 37, SX_STRING),
    SX_FIELD("abstract_file_identifier", "char[37]", 739, 37, SX_STRING),
    SX_FIELD("bibliographic_file_identifier", "char[37]", 776, 37, SX_STRING),
    SX_FIELD("creation_datetime_digits", "char[16]", 813, 16, SX_NONE),
    SX_FIELD("creation_timezone_quarters", "int8", 829, 1, SX_NONE),
    SX_FIELD("modification_datetime_digits", "char[16]", 830, 16, SX_NONE),
    SX_FIELD("modification_timezone_quarters", "int8", 846, 1, SX_NONE),
    SX_FIELD("expiration_datetime_digits", "char[16]", 847, 16, SX_NONE),
    SX_FIELD("expiration_timezone_quarters", "int8", 863, 1, SX_NONE),
    SX_FIELD("effective_datetime_digits", "char[16]", 864, 16, SX_NONE),
    SX_FIELD("effective_timezone_quarters", "int8", 880, 1, SX_NONE),
    SX_FIELD("file_structure_version", "uint8", 881, 1, SX_ID),
    SX_FIELD("reserved1", "uint8", 882, 1, SX_RESERVED),
    SX_FIELD("application_use", "bytes", 883, 512, SX_NONE),
    SX_FIELD("reserved2", "bytes", 1395, 653, SX_RESERVED),
};
const sx_layout sxo_iso_primary_volume_descriptor = {UINT32_C(0x60130004),"iso_primary_volume_descriptor",sxo_iso_primary_volume_descriptor_fields,SX_COUNT(sxo_iso_primary_volume_descriptor_fields),SX_LE};
static const xx_data_struct_field_desc sxo_iso_supplementary_volume_descriptor_fields[] = {
    SX_FIELD("descriptor_type", "uint8", 0, 1, SX_ID),
    SX_FIELD("standard_identifier", "char[5]", 1, 5, SX_SIGNATURE),
    SX_FIELD("descriptor_version", "uint8", 6, 1, SX_ID),
    SX_FIELD("volume_flags", "uint8", 7, 1, SX_FLAGS),
    SX_FIELD("system_identifier", "uint8[32]", 8, 32, SX_NONE),
    SX_FIELD("volume_identifier", "uint8[32]", 40, 32, SX_NONE),
    SX_FIELD("reserved0", "bytes", 72, 8, SX_RESERVED),
    SX_FIELD("volume_blocks_le", "uint32", 80, 4, SX_COUNT_PROP),
    SX_FIELD("volume_blocks_be", "uint32be", 84, 4, SX_COUNT_PROP),
    SX_FIELD("escape_sequences", "bytes", 88, 32, SX_NONE),
    SX_FIELD("volume_set_size_le", "uint16", 120, 2, SX_COUNT_PROP),
    SX_FIELD("volume_set_size_be", "uint16be", 122, 2, SX_COUNT_PROP),
    SX_FIELD("volume_sequence_le", "uint16", 124, 2, SX_NONE),
    SX_FIELD("volume_sequence_be", "uint16be", 126, 2, SX_NONE),
    SX_FIELD("logical_block_size_le", "uint16", 128, 2, SX_SIZE),
    SX_FIELD("logical_block_size_be", "uint16be", 130, 2, SX_SIZE),
    SX_FIELD("path_table_size_le", "uint32", 132, 4, SX_SIZE),
    SX_FIELD("path_table_size_be", "uint32be", 136, 4, SX_SIZE),
    SX_FIELD("l_path_table_lba", "uint32", 140, 4, SX_NONE),
    SX_FIELD("l_optional_path_table_lba", "uint32", 144, 4, SX_NONE),
    SX_FIELD("m_path_table_lba", "uint32be", 148, 4, SX_NONE),
    SX_FIELD("m_optional_path_table_lba", "uint32be", 152, 4, SX_NONE),
    SX_FIELD("root_record_length", "uint8", 156, 1, SX_SIZE),
    SX_FIELD("root_extended_attribute_blocks", "uint8", 157, 1, SX_COUNT_PROP),
    SX_FIELD("root_extent_lba_le", "uint32", 158, 4, SX_NONE),
    SX_FIELD("root_extent_lba_be", "uint32be", 162, 4, SX_NONE),
    SX_FIELD("root_data_length_le", "uint32", 166, 4, SX_SIZE),
    SX_FIELD("root_data_length_be", "uint32be", 170, 4, SX_SIZE),
    SX_FIELD("root_recorded_year_since_1900", "uint8", 174, 1, SX_NONE),
    SX_FIELD("root_recorded_month", "uint8", 175, 1, SX_NONE),
    SX_FIELD("root_recorded_day", "uint8", 176, 1, SX_NONE),
    SX_FIELD("root_recorded_hour", "uint8", 177, 1, SX_NONE),
    SX_FIELD("root_recorded_minute", "uint8", 178, 1, SX_NONE),
    SX_FIELD("root_recorded_second", "uint8", 179, 1, SX_NONE),
    SX_FIELD("root_recorded_timezone_quarters", "int8", 180, 1, SX_NONE),
    SX_FIELD("root_flags", "uint8", 181, 1, SX_FLAGS),
    SX_FIELD("root_file_unit_blocks", "uint8", 182, 1, SX_COUNT_PROP),
    SX_FIELD("root_interleave_gap_blocks", "uint8", 183, 1, SX_COUNT_PROP),
    SX_FIELD("root_volume_sequence_le", "uint16", 184, 2, SX_NONE),
    SX_FIELD("root_volume_sequence_be", "uint16be", 186, 2, SX_NONE),
    SX_FIELD("root_identifier_length", "uint8", 188, 1, SX_SIZE),
    SX_FIELD("root_identifier", "uint8", 189, 1, SX_NONE),
    SX_FIELD("volume_set_identifier", "uint8[128]", 190, 128, SX_NONE),
    SX_FIELD("publisher_identifier", "uint8[128]", 318, 128, SX_NONE),
    SX_FIELD("data_preparer_identifier", "uint8[128]", 446, 128, SX_NONE),
    SX_FIELD("application_identifier", "uint8[128]", 574, 128, SX_NONE),
    SX_FIELD("copyright_file_identifier", "uint8[37]", 702, 37, SX_NONE),
    SX_FIELD("abstract_file_identifier", "uint8[37]", 739, 37, SX_NONE),
    SX_FIELD("bibliographic_file_identifier", "uint8[37]", 776, 37, SX_NONE),
    SX_FIELD("creation_datetime_digits", "char[16]", 813, 16, SX_NONE),
    SX_FIELD("creation_timezone_quarters", "int8", 829, 1, SX_NONE),
    SX_FIELD("modification_datetime_digits", "char[16]", 830, 16, SX_NONE),
    SX_FIELD("modification_timezone_quarters", "int8", 846, 1, SX_NONE),
    SX_FIELD("expiration_datetime_digits", "char[16]", 847, 16, SX_NONE),
    SX_FIELD("expiration_timezone_quarters", "int8", 863, 1, SX_NONE),
    SX_FIELD("effective_datetime_digits", "char[16]", 864, 16, SX_NONE),
    SX_FIELD("effective_timezone_quarters", "int8", 880, 1, SX_NONE),
    SX_FIELD("file_structure_version", "uint8", 881, 1, SX_ID),
    SX_FIELD("reserved1", "uint8", 882, 1, SX_RESERVED),
    SX_FIELD("application_use", "bytes", 883, 512, SX_NONE),
    SX_FIELD("reserved2", "bytes", 1395, 653, SX_RESERVED),
};
const sx_layout sxo_iso_supplementary_volume_descriptor = {UINT32_C(0x60130005),"iso_supplementary_volume_descriptor",sxo_iso_supplementary_volume_descriptor_fields,SX_COUNT(sxo_iso_supplementary_volume_descriptor_fields),SX_LE};
static const xx_data_struct_field_desc sxo_iso_boot_record_fields[] = {
    SX_FIELD("descriptor_type", "uint8", 0, 1, SX_ID),
    SX_FIELD("standard_identifier", "char[5]", 1, 5, SX_SIGNATURE),
    SX_FIELD("descriptor_version", "uint8", 6, 1, SX_ID),
    SX_FIELD("boot_system_identifier", "char[32]", 7, 32, SX_STRING),
    SX_FIELD("boot_identifier", "char[32]", 39, 32, SX_STRING),
    SX_FIELD("boot_system_use", "bytes", 71, 1977, SX_NONE),
};
const sx_layout sxo_iso_boot_record = {UINT32_C(0x60130006),"iso_boot_record",sxo_iso_boot_record_fields,SX_COUNT(sxo_iso_boot_record_fields),SX_LE};
static const xx_data_struct_field_desc sxo_iso_volume_partition_descriptor_fields[] = {
    SX_FIELD("descriptor_type", "uint8", 0, 1, SX_ID),
    SX_FIELD("standard_identifier", "char[5]", 1, 5, SX_SIGNATURE),
    SX_FIELD("descriptor_version", "uint8", 6, 1, SX_ID),
    SX_FIELD("reserved", "uint8", 7, 1, SX_RESERVED),
    SX_FIELD("system_identifier", "char[32]", 8, 32, SX_STRING),
    SX_FIELD("partition_identifier", "char[32]", 40, 32, SX_STRING),
    SX_FIELD("partition_location_le", "uint32", 72, 4, SX_NONE),
    SX_FIELD("partition_location_be", "uint32be", 76, 4, SX_NONE),
    SX_FIELD("partition_blocks_le", "uint32", 80, 4, SX_COUNT_PROP),
    SX_FIELD("partition_blocks_be", "uint32be", 84, 4, SX_COUNT_PROP),
    SX_FIELD("system_use", "bytes", 88, 1960, SX_NONE),
};
const sx_layout sxo_iso_volume_partition_descriptor = {UINT32_C(0x60130007),"iso_volume_partition_descriptor",sxo_iso_volume_partition_descriptor_fields,SX_COUNT(sxo_iso_volume_partition_descriptor_fields),SX_LE};
static const xx_data_struct_field_desc sxo_iso_volume_descriptor_terminator_fields[] = {
    SX_FIELD("descriptor_type", "uint8", 0, 1, SX_ID),
    SX_FIELD("standard_identifier", "char[5]", 1, 5, SX_SIGNATURE),
    SX_FIELD("descriptor_version", "uint8", 6, 1, SX_ID),
    SX_FIELD("reserved", "bytes", 7, 2041, SX_RESERVED),
};
const sx_layout sxo_iso_volume_descriptor_terminator = {UINT32_C(0x60130008),"iso_volume_descriptor_terminator",sxo_iso_volume_descriptor_terminator_fields,SX_COUNT(sxo_iso_volume_descriptor_terminator_fields),SX_LE};
typedef struct sxo_iso_directory {uint32_t lba,size;unsigned depth;} sxo_iso_directory;
static bool sxo_iso_paths(sx_context *c,uint32_t block,uint32_t bytes,bool be)
{
    int64_t at=(int64_t)block*2048,end=at+bytes;unsigned entries=0;uint8_t b[8];
    if(!block||!bytes)return true;if(!sxo_can(c,at,bytes))return false;
    while(at<end){if(++entries>65535||end-at<8||!sx_read(c,at,b,8)||!b[0])return false;uint32_t n=8+b[0]+(b[0]&1);if(n>(uint64_t)(end-at))return false;
        if(!sxo_add(c,be?&sxo_iso_path_table_m:&sxo_iso_path_table_l,at,8))return false;at+=n;
    }return true;
}
static bool sxo_iso_build(sx_context *c)
{
    uint8_t b[2048],pvd[2048];bool primary=false,terminated=false,ok=false;size_t count=1;
    sxo_iso_directory *queue=xx_mem_alloc(8192*sizeof(*queue));if(!queue)return false;
    for(unsigned i=0;i<64;i++){
        int64_t at=(int64_t)(16+i)*2048;const sx_layout *l=&sxo_iso_volume_descriptor_header;int n=7;
        if(!sx_read(c,at,b,2048)||xx_rt_memcmp(b+1,"CD001",5)||b[6]!=1)goto done;
        switch(b[0]){case 0:l=&sxo_iso_boot_record;n=2048;break;case 1:l=&sxo_iso_primary_volume_descriptor;n=2048;if(!primary){xx_rt_memcpy(pvd,b,2048);primary=true;}break;case 2:l=&sxo_iso_supplementary_volume_descriptor;n=2048;break;case 3:l=&sxo_iso_volume_partition_descriptor;n=2048;break;case 255:l=&sxo_iso_volume_descriptor_terminator;n=2048;terminated=true;break;}
        if(!sxo_add(c,l,at,n))goto done;if(terminated)break;
    }
    if(!primary||!terminated||sxo_u32(pvd+80)!=xx_data_get_u32(pvd+84,4,0,true)||sxo_u16(pvd+128)!=2048||xx_data_get_u16(pvd+130,2,0,true)!=2048)goto done;
    if(sxo_u32(pvd+132)!=xx_data_get_u32(pvd+136,4,0,true))goto done;
    for(unsigned i=0;i<4;i++)if(!sxo_iso_paths(c,xx_data_get_u32(pvd+140+i*4,4,0,i>=2),sxo_u32(pvd+132),i>=2))goto done;
    queue[0]=(sxo_iso_directory){sxo_u32(pvd+158),sxo_u32(pvd+166),0};
    for(size_t q=0;q<count;q++){
        int64_t at=(int64_t)queue[q].lba*2048,end=at+queue[q].size,start=at;
        if(queue[q].depth>64||!queue[q].size||!sxo_can(c,at,queue[q].size))goto done;
        while(at<end){
            if(!sx_read(c,at,b,1))goto done;unsigned n=b[0];if(!n){at+=2048-(at-start)%2048;continue;}
            if(n<34||n>(uint64_t)(end-at)||n>2048-(at-start)%2048||!sx_read(c,at,b,n)||33U+b[32]>n)goto done;
            if(!sxo_add(c,&sxo_iso_directory_record,at,33))goto done;
            if((b[25]&2)&&!(b[32]==1&&(b[33]==0||b[33]==1))){
                uint32_t lba=sxo_u32(b+2),bytes=sxo_u32(b+10);bool seen=false;
                for(size_t j=0;j<count;j++)if(queue[j].lba==lba&&queue[j].size==bytes){seen=true;break;}
                if(!seen){if(count>=8192)goto done;queue[count++]=(sxo_iso_directory){lba,bytes,queue[q].depth+1};}
            }
            at+=n;
        }
    }
    ok=true;
done:xx_mem_free(queue);return ok;
}
bool sx_iso9660_build(sx_context*c)
{
 return sxo_iso_build(c);
}
