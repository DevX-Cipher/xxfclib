/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * FreeSurfer surface data structures, moved out of the sciencemeta schema family. */
#include "../../xx_format_schema_sciencemeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsc_freesurfer_signature_fields[] = {
    SX_FIELD("signature","uint24",0,3,SX_SIGNATURE),
};
const sx_layout sxsc_freesurfer_signature = {UINT32_C(0x6028002f),"freesurfer_signature",sxsc_freesurfer_signature_fields,SX_COUNT(sxsc_freesurfer_signature_fields),SX_BE};
static const xx_data_struct_field_desc sxsc_freesurfer_counts_fields[] = {
    SX_FIELD("vertex_count","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("face_count","uint32",4,4,SX_COUNT_PROP),
};
const sx_layout sxsc_freesurfer_counts = {UINT32_C(0x60280030),"freesurfer_counts",sxsc_freesurfer_counts_fields,SX_COUNT(sxsc_freesurfer_counts_fields),SX_BE};
static const xx_data_struct_field_desc sxsc_freesurfer_vertex_fields[] = {
    SX_FIELD("x","float32",0,4,SX_NONE),
    SX_FIELD("y","float32",4,4,SX_NONE),
    SX_FIELD("z","float32",8,4,SX_NONE),
};
const sx_layout sxsc_freesurfer_vertex = {UINT32_C(0x60280031),"freesurfer_vertex",sxsc_freesurfer_vertex_fields,SX_COUNT(sxsc_freesurfer_vertex_fields),SX_BE};
static const xx_data_struct_field_desc sxsc_freesurfer_face_fields[] = {
    SX_FIELD("vertex0","uint32",0,4,SX_ID),
    SX_FIELD("vertex1","uint32",4,4,SX_ID),
    SX_FIELD("vertex2","uint32",8,4,SX_ID),
};
const sx_layout sxsc_freesurfer_face = {UINT32_C(0x60280032),"freesurfer_face",sxsc_freesurfer_face_fields,SX_COUNT(sxsc_freesurfer_face_fields),SX_BE};
static const xx_data_struct_field_desc sxsc_freesurfer_volume_marker_fields[] = {
    SX_FIELD("marker","uint32",0,4,SX_ID),
};
const sx_layout sxsc_freesurfer_volume_marker = {UINT32_C(0x60280033),"freesurfer_volume_marker",sxsc_freesurfer_volume_marker_fields,SX_COUNT(sxsc_freesurfer_volume_marker_fields),SX_BE};
static const xx_data_struct_field_desc sxsc_freesurfer_volume_marker_long_fields[] = {
    SX_FIELD("marker","uint32",0,4,SX_ID),
    SX_FIELD("reserved","uint32",4,4,SX_RESERVED),
    SX_FIELD("volume_marker","uint32",8,4,SX_ID),
};
const sx_layout sxsc_freesurfer_volume_marker_long = {UINT32_C(0x60280034),"freesurfer_volume_marker_long",sxsc_freesurfer_volume_marker_long_fields,SX_COUNT(sxsc_freesurfer_volume_marker_long_fields),SX_BE};
static bool sxsc_freesurfer(sx_context *c)
{
 uint8_t b;int64_t at=3;if(!sxsc_add(c,&sxsc_freesurfer_signature,0,3))return false;
 for(unsigned line=0;line<2;line++){unsigned used=0;do{if(used++>4096||!sx_read(c,at++,&b,1))return false;}while(b!=10);}
 uint32_t vertices,faces;if(!sx_u32(c,at,true,&vertices)||!sx_u32(c,at+4,true,&faces)||vertices>1000000||faces>1000000||!sxsc_add(c,&sxsc_freesurfer_counts,at,8))return false;at+=8;
 if(!sxsc_table(c,&sxsc_freesurfer_vertex,at,12,vertices))return false;at+=(int64_t)vertices*12;if(!sxsc_table(c,&sxsc_freesurfer_face,at,12,faces))return false;at+=(int64_t)faces*12;
 if(at<c->size){uint32_t marker;if(!sx_u32(c,at,true,&marker))return false;if(marker==20)return sxsc_add(c,&sxsc_freesurfer_volume_marker,at,4);if(marker==2)return sxsc_add(c,&sxsc_freesurfer_volume_marker_long,at,12);return false;}return true;
}
bool sx_freesurfer_surface_build(sx_context*c)
{
 return sxsc_freesurfer(c);
}
