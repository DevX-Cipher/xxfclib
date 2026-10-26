/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * QUBICLE_QB data structures, moved out of the modelmeta schema family. */
#include "../../xx_format_schema_modelmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmo_qb_header_fields[] = {
    SX_FIELD("version","uint32",0,4,SX_ID),
    SX_FIELD("color_format","uint32",4,4,SX_ID),
    SX_FIELD("z_axis_orientation","uint32",8,4,SX_ID),
    SX_FIELD("compressed","uint32",12,4,SX_FLAGS),
    SX_FIELD("visibility_mask_encoded","uint32",16,4,SX_FLAGS),
    SX_FIELD("matrix_count","uint32",20,4,SX_COUNT_PROP),
};
const sx_layout sxmo_qb_header = {UINT32_C(0x6021006a),"qb_header",sxmo_qb_header_fields,SX_COUNT(sxmo_qb_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_qb_name_length_fields[] = {
    SX_FIELD("name_size","uint8",0,1,SX_SIZE),
};
const sx_layout sxmo_qb_name_length = {UINT32_C(0x6021006b),"qb_name_length",sxmo_qb_name_length_fields,SX_COUNT(sxmo_qb_name_length_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_qb_matrix_fields[] = {
    SX_FIELD("size_x","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("size_y","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("size_z","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("position_x","int32",12,4,SX_NONE),
    SX_FIELD("position_y","int32",16,4,SX_NONE),
    SX_FIELD("position_z","int32",20,4,SX_NONE),
};
const sx_layout sxmo_qb_matrix = {UINT32_C(0x6021006c),"qb_matrix",sxmo_qb_matrix_fields,SX_COUNT(sxmo_qb_matrix_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_qb_voxel_fields[] = {
    SX_FIELD("encoded_color","uint32",0,4,SX_FLAGS),
};
const sx_layout sxmo_qb_voxel = {UINT32_C(0x6021006d),"qb_voxel",sxmo_qb_voxel_fields,SX_COUNT(sxmo_qb_voxel_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_qb_rle_marker_fields[] = {
    SX_FIELD("marker","uint32",0,4,SX_ID),
};
const sx_layout sxmo_qb_rle_marker = {UINT32_C(0x6021006e),"qb_rle_marker",sxmo_qb_rle_marker_fields,SX_COUNT(sxmo_qb_rle_marker_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_qb_rle_run_fields[] = {
    SX_FIELD("voxel_count","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("encoded_color","uint32",4,4,SX_FLAGS),
};
const sx_layout sxmo_qb_rle_run = {UINT32_C(0x6021006f),"qb_rle_run",sxmo_qb_rle_run_fields,SX_COUNT(sxmo_qb_rle_run_fields),SX_LE};
static bool sxmo_qb(sx_context*c){uint8_t h[24];if(!sxmo_read(c,0,h,24)||sxmo32(h,false)!=0x101||!sxmo_add(c,&sxmo_qb_header,0))return false;uint32_t count=sxmo32(h+20,false),compressed=sxmo32(h+12,false);if(count>1024||compressed>1)return true;uint64_t p=24,end=(uint64_t)c->size;unsigned budget=0;
 for(unsigned i=0;i<count;i++){if(p>=end||!sxmo_read(c,p,h,1))break;unsigned z=h[0];if(25+(uint64_t)z>end-p)break;if(!sxmo_add(c,&sxmo_qb_name_length,p))return false;p+=1+z;if(!sxmo_read(c,p,h,24)||!sxmo_add(c,&sxmo_qb_matrix,p))return false;p+=24;uint64_t nx=sxmo32(h,false),ny=sxmo32(h+4,false),nz=sxmo32(h+8,false);if(!nx||!ny||!nz||nx>16777216||ny>16777216/nx||nz>16777216/(nx*ny))break;uint64_t pixels=nx*ny*nz;
 if(!compressed){if(pixels*4>end-p)break;if(pixels<=1000000&&!sxmo_table(c,&sxmo_qb_voxel,p,pixels))return false;p+=pixels*4;}
 else{bool valid=true;for(uint64_t slice=0;slice<nz&&valid;slice++){uint64_t filled=0;bool terminal=false;while(p<end&&budget++<16000){if(end-p<4||!sxmo_read(c,p,h,4)){valid=false;break;}uint32_t code=sxmo32(h,false);if(code==6){if(!sxmo_take(c,&sxmo_qb_rle_marker,&p,end))return false;terminal=true;break;}uint64_t run=1;if(code==2){if(end-p<12||!sxmo_read(c,p+4,h,8)){valid=false;break;}run=sxmo32(h,false);if(!sxmo_take(c,&sxmo_qb_rle_marker,&p,end)||!sxmo_take(c,&sxmo_qb_rle_run,&p,end))return false;}else if(!sxmo_take(c,&sxmo_qb_voxel,&p,end))return false;if(run>nx*ny-filled){valid=false;break;}filled+=run;}if(!terminal||filled!=nx*ny)valid=false;}if(!valid)break;}}return !c->failed;}
bool sx_qubicle_qb_build(sx_context*c)
{
bool ok=false;
ok=sxmo_qb(c);
return ok&&c->count>0&&sxmo_finish(c);
}
