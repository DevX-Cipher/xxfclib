/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * CHARMM_DCD data structures, moved out of the scienceheaders schema family. */
#include "../../xx_format_schema_scienceheaders.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsh_dcd_header_le_fields[] = {
    SX_FIELD("record_size","int32",0,4,SX_SIZE),
    SX_FIELD("signature","char[4]",4,4,SX_SIGNATURE),
    SX_FIELD("frame_count","int32",8,4,SX_COUNT_PROP),
    SX_FIELD("first_step","int32",12,4,SX_NONE),
    SX_FIELD("step_interval","int32",16,4,SX_NONE),
    SX_FIELD("control_words","int32[5]",20,20,SX_NONE),
    SX_FIELD("fixed_atom_count","int32",40,4,SX_COUNT_PROP),
    SX_FIELD("delta","float32",44,4,SX_NONE),
    SX_FIELD("unit_cell_flag","int32",48,4,SX_FLAGS),
    SX_FIELD("four_dimensions_flag","int32",52,4,SX_FLAGS),
    SX_FIELD("reserved","int32[7]",56,28,SX_RESERVED),
    SX_FIELD("charmm_version","int32",84,4,SX_ID),
    SX_FIELD("trailing_record_size","int32",88,4,SX_SIZE),
};
const sx_layout sxsh_dcd_header_le = {UINT32_C(0x602a000d),"dcd_header_le",sxsh_dcd_header_le_fields,SX_COUNT(sxsh_dcd_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsh_dcd_record_size_le_fields[] = {
    SX_FIELD("record_size","int32",0,4,SX_SIZE),
};
const sx_layout sxsh_dcd_record_size_le = {UINT32_C(0x602a000e),"dcd_record_size_le",sxsh_dcd_record_size_le_fields,SX_COUNT(sxsh_dcd_record_size_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsh_dcd_title_count_le_fields[] = {
    SX_FIELD("title_count","int32",0,4,SX_COUNT_PROP),
};
const sx_layout sxsh_dcd_title_count_le = {UINT32_C(0x602a000f),"dcd_title_count_le",sxsh_dcd_title_count_le_fields,SX_COUNT(sxsh_dcd_title_count_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsh_dcd_atom_count_le_fields[] = {
    SX_FIELD("atom_count","int32",0,4,SX_COUNT_PROP),
};
const sx_layout sxsh_dcd_atom_count_le = {UINT32_C(0x602a0010),"dcd_atom_count_le",sxsh_dcd_atom_count_le_fields,SX_COUNT(sxsh_dcd_atom_count_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsh_dcd_cell_le_fields[] = {
    SX_FIELD("a","float64",0,8,SX_NONE),
    SX_FIELD("gamma","float64",8,8,SX_NONE),
    SX_FIELD("b","float64",16,8,SX_NONE),
    SX_FIELD("beta","float64",24,8,SX_NONE),
    SX_FIELD("alpha","float64",32,8,SX_NONE),
    SX_FIELD("c","float64",40,8,SX_NONE),
};
const sx_layout sxsh_dcd_cell_le = {UINT32_C(0x602a0011),"dcd_cell_le",sxsh_dcd_cell_le_fields,SX_COUNT(sxsh_dcd_cell_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsh_dcd_header_be_fields[] = {
    SX_FIELD("record_size","int32",0,4,SX_SIZE),
    SX_FIELD("signature","char[4]",4,4,SX_SIGNATURE),
    SX_FIELD("frame_count","int32",8,4,SX_COUNT_PROP),
    SX_FIELD("first_step","int32",12,4,SX_NONE),
    SX_FIELD("step_interval","int32",16,4,SX_NONE),
    SX_FIELD("control_words","int32[5]",20,20,SX_NONE),
    SX_FIELD("fixed_atom_count","int32",40,4,SX_COUNT_PROP),
    SX_FIELD("delta","float32",44,4,SX_NONE),
    SX_FIELD("unit_cell_flag","int32",48,4,SX_FLAGS),
    SX_FIELD("four_dimensions_flag","int32",52,4,SX_FLAGS),
    SX_FIELD("reserved","int32[7]",56,28,SX_RESERVED),
    SX_FIELD("charmm_version","int32",84,4,SX_ID),
    SX_FIELD("trailing_record_size","int32",88,4,SX_SIZE),
};
const sx_layout sxsh_dcd_header_be = {UINT32_C(0x602a0012),"dcd_header_be",sxsh_dcd_header_be_fields,SX_COUNT(sxsh_dcd_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsh_dcd_record_size_be_fields[] = {
    SX_FIELD("record_size","int32",0,4,SX_SIZE),
};
const sx_layout sxsh_dcd_record_size_be = {UINT32_C(0x602a0013),"dcd_record_size_be",sxsh_dcd_record_size_be_fields,SX_COUNT(sxsh_dcd_record_size_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsh_dcd_title_count_be_fields[] = {
    SX_FIELD("title_count","int32",0,4,SX_COUNT_PROP),
};
const sx_layout sxsh_dcd_title_count_be = {UINT32_C(0x602a0014),"dcd_title_count_be",sxsh_dcd_title_count_be_fields,SX_COUNT(sxsh_dcd_title_count_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsh_dcd_atom_count_be_fields[] = {
    SX_FIELD("atom_count","int32",0,4,SX_COUNT_PROP),
};
const sx_layout sxsh_dcd_atom_count_be = {UINT32_C(0x602a0015),"dcd_atom_count_be",sxsh_dcd_atom_count_be_fields,SX_COUNT(sxsh_dcd_atom_count_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsh_dcd_cell_be_fields[] = {
    SX_FIELD("a","float64",0,8,SX_NONE),
    SX_FIELD("gamma","float64",8,8,SX_NONE),
    SX_FIELD("b","float64",16,8,SX_NONE),
    SX_FIELD("beta","float64",24,8,SX_NONE),
    SX_FIELD("alpha","float64",32,8,SX_NONE),
    SX_FIELD("c","float64",40,8,SX_NONE),
};
const sx_layout sxsh_dcd_cell_be = {UINT32_C(0x602a0016),"dcd_cell_be",sxsh_dcd_cell_be_fields,SX_COUNT(sxsh_dcd_cell_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsh_dcd_title_fields[] = {
    SX_FIELD("title","char[80]",0,80,SX_STRING),
};
const sx_layout sxsh_dcd_title = {UINT32_C(0x602a0017),"dcd_title",sxsh_dcd_title_fields,SX_COUNT(sxsh_dcd_title_fields),SX_LE};
static bool sxsh_dcd_record(sx_context *c,int64_t *at,bool be,uint32_t wanted,const sx_layout *payload)
{
 uint32_t n,tail;int64_t p=*at;
 if(!sx_u32(c,p,be,&n)||n!=wanted||!sxsh_span(c,p,(uint64_t)n+8)||!sx_u32(c,p+4+n,be,&tail)||tail!=n||!sxsh_add(c,be?&sxsh_dcd_record_size_be:&sxsh_dcd_record_size_le,p,4)||!sxsh_add(c,be?&sxsh_dcd_record_size_be:&sxsh_dcd_record_size_le,p+4+n,4))return false;
 if(payload&&!sxsh_add(c,payload,p+4,n))return false;*at=p+8+n;return true;
}
static bool sxsh_dcd(sx_context *c)
{
 uint8_t b[92];if(!sx_read(c,0,b,92)||xx_rt_memcmp(b+4,"CORD",4))return false;bool be=sxsh32(b,true)==84;
 uint32_t frames=sxsh32(b+8,be),cell=sxsh32(b+48,be),title,count,atoms;int64_t at=92;
 if(sxsh32(b,be)!=84||!frames||frames>1024||cell>1||!sxsh_add(c,be?&sxsh_dcd_header_be:&sxsh_dcd_header_le,0,92)||!sx_u32(c,at,be,&title)||title<84||title>2564||!sx_u32(c,at+4,be,&count)||count!=(title-4)/80||title!=4+count*80)return false;
 if(!sxsh_add(c,be?&sxsh_dcd_title_count_be:&sxsh_dcd_title_count_le,at+4,4)||!sxsh_table(c,&sxsh_dcd_title,at+8,80,count)||!sxsh_dcd_record(c,&at,be,title,NULL)||!sx_u32(c,at+4,be,&atoms)||!atoms||atoms>1048576||!sxsh_dcd_record(c,&at,be,4,be?&sxsh_dcd_atom_count_be:&sxsh_dcd_atom_count_le))return false;
 for(uint32_t i=0;i<frames;i++){
  if(cell&&!sxsh_dcd_record(c,&at,be,48,be?&sxsh_dcd_cell_be:&sxsh_dcd_cell_le))return false;
  for(unsigned j=0;j<3;j++)if(!sxsh_dcd_record(c,&at,be,atoms*4,NULL))return false;
 }return at==c->size;
}
bool sx_charmm_dcd_build(sx_context*c)
{
 bool ok=false;
 ok=sxsh_dcd(c);
 return ok&&sxsh_finish(c);
}
