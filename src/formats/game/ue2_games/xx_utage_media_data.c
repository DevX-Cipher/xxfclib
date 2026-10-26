/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Utage media (modified-XOR) data structures, moved out of the utagemedia schema family. */
#include "../../xx_format_schema_utagemedia.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxutg_png_signature_fields[]={
 SX_FIELD("encoded_png_signature","uint8[8]",0,8,SX_NONE),
};
const sx_layout sxutg_png_signature={UINT32_C(0x609c0001),"utage_png_signature",sxutg_png_signature_fields,SX_COUNT(sxutg_png_signature_fields),SX_LE};
static const xx_data_struct_field_desc sxutg_png_chunk_fields[]={
 SX_FIELD("encoded_data_length","uint8[4]",0,4,SX_NONE),
 SX_FIELD("encoded_chunk_type","uint8[4]",4,4,SX_NONE),
};
const sx_layout sxutg_png_chunk={UINT32_C(0x609c0002),"utage_png_chunk",sxutg_png_chunk_fields,SX_COUNT(sxutg_png_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxutg_png_ihdr_fields[]={
 SX_FIELD("encoded_width","uint8[4]",0,4,SX_NONE),
 SX_FIELD("encoded_height","uint8[4]",4,4,SX_NONE),
 SX_FIELD("encoded_bit_depth","uint8[1]",8,1,SX_NONE),
 SX_FIELD("encoded_color_type","uint8[1]",9,1,SX_NONE),
 SX_FIELD("encoded_compression_method","uint8[1]",10,1,SX_NONE),
 SX_FIELD("encoded_filter_method","uint8[1]",11,1,SX_NONE),
 SX_FIELD("encoded_interlace_method","uint8[1]",12,1,SX_NONE),
};
const sx_layout sxutg_png_ihdr={UINT32_C(0x609c0003),"utage_png_ihdr",sxutg_png_ihdr_fields,SX_COUNT(sxutg_png_ihdr_fields),SX_LE};
static const xx_data_struct_field_desc sxutg_png_crc_fields[]={
 SX_FIELD("encoded_chunk_crc","uint8[4]",0,4,SX_NONE),
};
const sx_layout sxutg_png_crc={UINT32_C(0x609c0004),"utage_png_crc",sxutg_png_crc_fields,SX_COUNT(sxutg_png_crc_fields),SX_LE};
static const xx_data_struct_field_desc sxutg_bmp_file_fields[]={
 SX_FIELD("encoded_type","uint8[2]",0,2,SX_NONE),
 SX_FIELD("encoded_file_size","uint8[4]",2,4,SX_NONE),
 SX_FIELD("encoded_reserved1","uint8[2]",6,2,SX_NONE),
 SX_FIELD("encoded_reserved2","uint8[2]",8,2,SX_NONE),
 SX_FIELD("encoded_pixel_offset","uint8[4]",10,4,SX_NONE),
};
const sx_layout sxutg_bmp_file={UINT32_C(0x609c0005),"utage_bmp_file",sxutg_bmp_file_fields,SX_COUNT(sxutg_bmp_file_fields),SX_LE};
static const xx_data_struct_field_desc sxutg_bmp_core_fields[]={
 SX_FIELD("encoded_header_size","uint8[4]",0,4,SX_NONE),
 SX_FIELD("encoded_width","uint8[2]",4,2,SX_NONE),
 SX_FIELD("encoded_height","uint8[2]",6,2,SX_NONE),
 SX_FIELD("encoded_planes","uint8[2]",8,2,SX_NONE),
 SX_FIELD("encoded_bits_per_pixel","uint8[2]",10,2,SX_NONE),
};
const sx_layout sxutg_bmp_core={UINT32_C(0x609c0006),"utage_bmp_core",sxutg_bmp_core_fields,SX_COUNT(sxutg_bmp_core_fields),SX_LE};
static const xx_data_struct_field_desc sxutg_bmp_info_fields[]={
 SX_FIELD("encoded_header_size","uint8[4]",0,4,SX_NONE),
 SX_FIELD("encoded_width","uint8[4]",4,4,SX_NONE),
 SX_FIELD("encoded_height","uint8[4]",8,4,SX_NONE),
 SX_FIELD("encoded_planes","uint8[2]",12,2,SX_NONE),
 SX_FIELD("encoded_bits_per_pixel","uint8[2]",14,2,SX_NONE),
 SX_FIELD("encoded_compression","uint8[4]",16,4,SX_NONE),
 SX_FIELD("encoded_image_size","uint8[4]",20,4,SX_NONE),
 SX_FIELD("encoded_x_pixels_per_meter","uint8[4]",24,4,SX_NONE),
 SX_FIELD("encoded_y_pixels_per_meter","uint8[4]",28,4,SX_NONE),
 SX_FIELD("encoded_colors_used","uint8[4]",32,4,SX_NONE),
 SX_FIELD("encoded_colors_important","uint8[4]",36,4,SX_NONE),
};
const sx_layout sxutg_bmp_info={UINT32_C(0x609c0007),"utage_bmp_info",sxutg_bmp_info_fields,SX_COUNT(sxutg_bmp_info_fields),SX_LE};
static const xx_data_struct_field_desc sxutg_jpeg_marker_fields[]={
 SX_FIELD("encoded_marker_prefix","uint8[1]",0,1,SX_NONE),
 SX_FIELD("encoded_marker_code","uint8[1]",1,1,SX_NONE),
};
const sx_layout sxutg_jpeg_marker={UINT32_C(0x609c0008),"utage_jpeg_marker",sxutg_jpeg_marker_fields,SX_COUNT(sxutg_jpeg_marker_fields),SX_LE};
static const xx_data_struct_field_desc sxutg_jpeg_segment_fields[]={
 SX_FIELD("encoded_marker_prefix","uint8[1]",0,1,SX_NONE),
 SX_FIELD("encoded_marker_code","uint8[1]",1,1,SX_NONE),
 SX_FIELD("encoded_segment_length","uint8[2]",2,2,SX_NONE),
};
const sx_layout sxutg_jpeg_segment={UINT32_C(0x609c0009),"utage_jpeg_segment",sxutg_jpeg_segment_fields,SX_COUNT(sxutg_jpeg_segment_fields),SX_LE};
static const xx_data_struct_field_desc sxutg_jpeg_frame_fields[]={
 SX_FIELD("encoded_sample_precision","uint8[1]",0,1,SX_NONE),
 SX_FIELD("encoded_height","uint8[2]",1,2,SX_NONE),
 SX_FIELD("encoded_width","uint8[2]",3,2,SX_NONE),
 SX_FIELD("encoded_component_count","uint8[1]",5,1,SX_NONE),
};
const sx_layout sxutg_jpeg_frame={UINT32_C(0x609c000a),"utage_jpeg_frame",sxutg_jpeg_frame_fields,SX_COUNT(sxutg_jpeg_frame_fields),SX_LE};
static const xx_data_struct_field_desc sxutg_jpeg_frame_component_fields[]={
 SX_FIELD("encoded_component_id","uint8[1]",0,1,SX_NONE),
 SX_FIELD("encoded_sampling_factors","uint8[1]",1,1,SX_NONE),
 SX_FIELD("encoded_quantization_table_id","uint8[1]",2,1,SX_NONE),
};
const sx_layout sxutg_jpeg_frame_component={UINT32_C(0x609c000b),"utage_jpeg_frame_component",sxutg_jpeg_frame_component_fields,SX_COUNT(sxutg_jpeg_frame_component_fields),SX_LE};
static const xx_data_struct_field_desc sxutg_jpeg_scan_fields[]={
 SX_FIELD("encoded_component_count","uint8[1]",0,1,SX_NONE),
};
const sx_layout sxutg_jpeg_scan={UINT32_C(0x609c000c),"utage_jpeg_scan",sxutg_jpeg_scan_fields,SX_COUNT(sxutg_jpeg_scan_fields),SX_LE};
static const xx_data_struct_field_desc sxutg_jpeg_scan_component_fields[]={
 SX_FIELD("encoded_component_id","uint8[1]",0,1,SX_NONE),
 SX_FIELD("encoded_entropy_table_selectors","uint8[1]",1,1,SX_NONE),
};
const sx_layout sxutg_jpeg_scan_component={UINT32_C(0x609c000d),"utage_jpeg_scan_component",sxutg_jpeg_scan_component_fields,SX_COUNT(sxutg_jpeg_scan_component_fields),SX_LE};
static const xx_data_struct_field_desc sxutg_jpeg_scan_parameters_fields[]={
 SX_FIELD("encoded_spectral_selection_start","uint8[1]",0,1,SX_NONE),
 SX_FIELD("encoded_spectral_selection_end","uint8[1]",1,1,SX_NONE),
 SX_FIELD("encoded_successive_approximation","uint8[1]",2,1,SX_NONE),
};
const sx_layout sxutg_jpeg_scan_parameters={UINT32_C(0x609c000e),"utage_jpeg_scan_parameters",sxutg_jpeg_scan_parameters_fields,SX_COUNT(sxutg_jpeg_scan_parameters_fields),SX_LE};
static const xx_data_struct_field_desc sxutg_riff_webp_fields[]={
 SX_FIELD("encoded_riff_id","uint8[4]",0,4,SX_NONE),
 SX_FIELD("encoded_riff_size","uint8[4]",4,4,SX_NONE),
 SX_FIELD("encoded_webp_id","uint8[4]",8,4,SX_NONE),
};
const sx_layout sxutg_riff_webp={UINT32_C(0x609c000f),"utage_riff_webp",sxutg_riff_webp_fields,SX_COUNT(sxutg_riff_webp_fields),SX_LE};
static const xx_data_struct_field_desc sxutg_riff_chunk_fields[]={
 SX_FIELD("encoded_chunk_id","uint8[4]",0,4,SX_NONE),
 SX_FIELD("encoded_data_size","uint8[4]",4,4,SX_NONE),
};
const sx_layout sxutg_riff_chunk={UINT32_C(0x609c0010),"utage_riff_chunk",sxutg_riff_chunk_fields,SX_COUNT(sxutg_riff_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxutg_webp_vp8x_fields[]={
 SX_FIELD("encoded_feature_flags","uint8[1]",0,1,SX_NONE),
 SX_FIELD("encoded_reserved","uint8[3]",1,3,SX_NONE),
 SX_FIELD("encoded_canvas_width_minus_one","uint8[3]",4,3,SX_NONE),
 SX_FIELD("encoded_canvas_height_minus_one","uint8[3]",7,3,SX_NONE),
};
const sx_layout sxutg_webp_vp8x={UINT32_C(0x609c0011),"utage_webp_vp8x",sxutg_webp_vp8x_fields,SX_COUNT(sxutg_webp_vp8x_fields),SX_LE};
static const xx_data_struct_field_desc sxutg_webp_vp8l_fields[]={
 SX_FIELD("encoded_signature","uint8[1]",0,1,SX_NONE),
 SX_FIELD("encoded_dimensions_alpha_version_bits","uint8[4]",1,4,SX_NONE),
};
const sx_layout sxutg_webp_vp8l={UINT32_C(0x609c0012),"utage_webp_vp8l",sxutg_webp_vp8l_fields,SX_COUNT(sxutg_webp_vp8l_fields),SX_LE};
static const xx_data_struct_field_desc sxutg_webp_vp8_fields[]={
 SX_FIELD("encoded_frame_tag","uint8[3]",0,3,SX_NONE),
 SX_FIELD("encoded_key_frame_start_code","uint8[3]",3,3,SX_NONE),
 SX_FIELD("encoded_width_and_scale","uint8[2]",6,2,SX_NONE),
 SX_FIELD("encoded_height_and_scale","uint8[2]",8,2,SX_NONE),
};
const sx_layout sxutg_webp_vp8={UINT32_C(0x609c0013),"utage_webp_vp8",sxutg_webp_vp8_fields,SX_COUNT(sxutg_webp_vp8_fields),SX_LE};
static const xx_data_struct_field_desc sxutg_ogg_page_fields[]={
 SX_FIELD("encoded_capture_pattern","uint8[4]",0,4,SX_NONE),
 SX_FIELD("encoded_version","uint8[1]",4,1,SX_NONE),
 SX_FIELD("encoded_header_type","uint8[1]",5,1,SX_NONE),
 SX_FIELD("encoded_granule_position","uint8[8]",6,8,SX_NONE),
 SX_FIELD("encoded_serial_number","uint8[4]",14,4,SX_NONE),
 SX_FIELD("encoded_page_sequence","uint8[4]",18,4,SX_NONE),
 SX_FIELD("encoded_page_checksum","uint8[4]",22,4,SX_NONE),
 SX_FIELD("encoded_segment_count","uint8[1]",26,1,SX_NONE),
};
const sx_layout sxutg_ogg_page={UINT32_C(0x609c0014),"utage_ogg_page",sxutg_ogg_page_fields,SX_COUNT(sxutg_ogg_page_fields),SX_LE};
static const xx_data_struct_field_desc sxutg_ogg_lacing_fields[]={
 SX_FIELD("encoded_lacing_value","uint8[1]",0,1,SX_NONE),
};
const sx_layout sxutg_ogg_lacing={UINT32_C(0x609c0015),"utage_ogg_lacing",sxutg_ogg_lacing_fields,SX_COUNT(sxutg_ogg_lacing_fields),SX_LE};
static const xx_data_struct_field_desc sxutg_isobmff_box_fields[]={
 SX_FIELD("encoded_box_size","uint8[4]",0,4,SX_NONE),
 SX_FIELD("encoded_box_type","uint8[4]",4,4,SX_NONE),
};
const sx_layout sxutg_isobmff_box={UINT32_C(0x609c0016),"utage_isobmff_box",sxutg_isobmff_box_fields,SX_COUNT(sxutg_isobmff_box_fields),SX_LE};
static const xx_data_struct_field_desc sxutg_isobmff_large_box_fields[]={
 SX_FIELD("encoded_box_size","uint8[4]",0,4,SX_NONE),
 SX_FIELD("encoded_box_type","uint8[4]",4,4,SX_NONE),
 SX_FIELD("encoded_large_size","uint8[8]",8,8,SX_NONE),
};
const sx_layout sxutg_isobmff_large_box={UINT32_C(0x609c0017),"utage_isobmff_large_box",sxutg_isobmff_large_box_fields,SX_COUNT(sxutg_isobmff_large_box_fields),SX_LE};
static const xx_data_struct_field_desc sxutg_isobmff_ftyp_fields[]={
 SX_FIELD("encoded_major_brand","uint8[4]",0,4,SX_NONE),
 SX_FIELD("encoded_minor_version","uint8[4]",4,4,SX_NONE),
};
const sx_layout sxutg_isobmff_ftyp={UINT32_C(0x609c0018),"utage_isobmff_ftyp",sxutg_isobmff_ftyp_fields,SX_COUNT(sxutg_isobmff_ftyp_fields),SX_LE};
static const xx_data_struct_field_desc sxutg_isobmff_brand_fields[]={
 SX_FIELD("encoded_compatible_brand","uint8[4]",0,4,SX_NONE),
};
const sx_layout sxutg_isobmff_brand={UINT32_C(0x609c0019),"utage_isobmff_brand",sxutg_isobmff_brand_fields,SX_COUNT(sxutg_isobmff_brand_fields),SX_LE};
static const xx_data_struct_field_desc sxutg_isobmff_uuid_fields[]={
 SX_FIELD("encoded_user_type","uint8[16]",0,16,SX_NONE),
};
const sx_layout sxutg_isobmff_uuid={UINT32_C(0x609c001a),"utage_isobmff_uuid",sxutg_isobmff_uuid_fields,SX_COUNT(sxutg_isobmff_uuid_fields),SX_LE};
typedef struct sxutg_view{sx_context*c;const char*key;size_t keylen;uint64_t work;}sxutg_view;
static bool sxutg_span(sxutg_view*v,uint64_t p,uint64_t n){return p<=(uint64_t)v->c->size&&n<=(uint64_t)v->c->size-p;}
static bool sxutg_read(sxutg_view*v,uint64_t p,void*out,size_t n){
 if(v->work>UINT64_C(16777216)||n>UINT64_C(16777216)-v->work||!sxutg_span(v,p,n)||!sx_read(v->c,(int64_t)p,out,n))return false;
 v->work+=n;uint8_t*b=out;for(size_t i=0;i<n;i++){uint8_t k=(uint8_t)v->key[(p+i)%v->keylen];if(b[i]&&b[i]!=k)b[i]^=k;}return true;
}
static uint32_t sxutg_le(const uint8_t*b){return(uint32_t)b[0]|((uint32_t)b[1]<<8)|((uint32_t)b[2]<<16)|((uint32_t)b[3]<<24);}
static uint32_t sxutg_be(const uint8_t*b){return((uint32_t)b[0]<<24)|((uint32_t)b[1]<<16)|((uint32_t)b[2]<<8)|b[3];}
static bool sxutg_put(sxutg_view*v,const sx_layout*l,uint64_t p,uint64_t n){return v->c->count<20000&&sxutg_span(v,p,n)&&sx_add(v->c,l,(int64_t)p,(int64_t)n);}
static int sxutg_order(const void*aa,const void*bb){const xx_data_struct*a=aa,*b=bb;return a->offset<b->offset?-1:a->offset>b->offset?1:0;}
static bool sxutg_finish(sx_context*c){size_t n=c->count;int64_t end=0;if(!n)return false;for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(p<end)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+z;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxutg_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
static bool sxutg_png(sxutg_view*v){uint8_t h[21];uint64_t p=8;bool first=true;
 while(sxutg_span(v,p,12)&&v->c->count<20000&&!xx_pd_is_stopped(v->c->pd)){
  if(!sxutg_read(v,p,h,8))return false;uint32_t z=sxutg_be(h);if(z>INT32_MAX||!sxutg_span(v,p+8,(uint64_t)z+4))return false;
  for(unsigned i=4;i<8;i++)if(!((h[i]>='A'&&h[i]<='Z')||(h[i]>='a'&&h[i]<='z')))return false;
  bool ihdr=!xx_rt_memcmp(h+4,"IHDR",4),iend=!xx_rt_memcmp(h+4,"IEND",4);
  if(first){if(!ihdr||z!=13||!sxutg_read(v,p+8,h+8,13)||!sxutg_be(h+8)||!sxutg_be(h+12))return false;if(!sxutg_put(v,&sxutg_png_signature,0,8))return false;first=false;}
  if(!sxutg_put(v,&sxutg_png_chunk,p,8))return false;if(ihdr&&z==13&&!sxutg_put(v,&sxutg_png_ihdr,p+8,13))return false;if(!sxutg_put(v,&sxutg_png_crc,p+8+z,4))return false;p+=(uint64_t)z+12;if(iend)return true;
 }return !first;
}
static bool sxutg_bmp(sxutg_view*v){uint8_t h[54];if(!sxutg_read(v,0,h,18))return false;uint32_t dib=sxutg_le(h+14),pixels=sxutg_le(h+10);unsigned z=dib==12?12:dib>=40?40:0;if(!z||!sxutg_span(v,14,dib)||pixels<(uint64_t)14+dib||!sxutg_span(v,pixels,0)||!sxutg_read(v,14,h,z))return false;return sxutg_put(v,&sxutg_bmp_file,0,14)&&sxutg_put(v,dib==12?&sxutg_bmp_core:&sxutg_bmp_info,14,z);}
static bool sxutg_jpeg(sxutg_view*v){uint64_t p=2;bool first=true;uint8_t h[10];
 while(sxutg_span(v,p,2)&&v->c->count<20000&&!xx_pd_is_stopped(v->c->pd)){
  if(!sxutg_read(v,p,h,2)||h[0]!=255||!h[1])return false;if(h[1]==255){p++;continue;}unsigned code=h[1];
  if(code==0xd8||code==0xd9||code==1||(code>=0xd0&&code<=0xd7)){if(first)return false;if(!sxutg_put(v,&sxutg_jpeg_marker,p,2))return false;p+=2;if(code==0xd9)return true;continue;}
  if(!sxutg_read(v,p,h,4))return false;unsigned z=((unsigned)h[2]<<8)|h[3];if(z<2||!sxutg_span(v,p+2,z))return false;
  if(first){if(!sxutg_put(v,&sxutg_jpeg_marker,0,2))return false;first=false;}if(!sxutg_put(v,&sxutg_jpeg_segment,p,4))return false;
  if(code>=0xc0&&code<=0xcf&&code!=0xc4&&code!=0xc8&&code!=0xcc){if(z<8||!sxutg_read(v,p+4,h,6))return false;unsigned n=h[5];if(!n||z!=8+n*3)return false;if(!sxutg_put(v,&sxutg_jpeg_frame,p+4,6))return false;for(unsigned i=0;i<n;i++)if(!sxutg_put(v,&sxutg_jpeg_frame_component,p+10+3*i,3))return false;}
  if(code==0xda){if(z<6||!sxutg_read(v,p+4,h,1))return false;unsigned n=h[0];if(!n||z!=6+n*2)return false;if(!sxutg_put(v,&sxutg_jpeg_scan,p+4,1))return false;for(unsigned i=0;i<n;i++)if(!sxutg_put(v,&sxutg_jpeg_scan_component,p+5+2*i,2))return false;if(!sxutg_put(v,&sxutg_jpeg_scan_parameters,p+5+2*n,3))return false;return true;}
  p+=(uint64_t)z+2;
 }return !first;
}
static bool sxutg_webp(sxutg_view*v){uint8_t h[12];if(!sxutg_read(v,0,h,12))return false;uint64_t end=(uint64_t)sxutg_le(h+4)+8,p=12;if(end<20||!sxutg_span(v,0,end))return false;bool first=true;
 while(p<end&&v->c->count<20000&&!xx_pd_is_stopped(v->c->pd)){if(end-p<8||!sxutg_read(v,p,h,8))return false;uint64_t z=sxutg_le(h+4);if(z>end-p-8||(z&1)>end-p-8-z)return false;
  if(first){if(!sxutg_put(v,&sxutg_riff_webp,0,12))return false;first=false;}if(!sxutg_put(v,&sxutg_riff_chunk,p,8))return false;
  if(!xx_rt_memcmp(h,"VP8X",4)&&z==10){if(!sxutg_put(v,&sxutg_webp_vp8x,p+8,10))return false;}
  else if(!xx_rt_memcmp(h,"VP8L",4)&&z>=5){if(!sxutg_read(v,p+8,h,5))return false;if(h[0]==0x2f&&!sxutg_put(v,&sxutg_webp_vp8l,p+8,5))return false;}
  else if(!xx_rt_memcmp(h,"VP8 ",4)&&z>=10){if(!sxutg_read(v,p+8,h,10))return false;if(!(h[0]&1)&&h[3]==0x9d&&h[4]==1&&h[5]==0x2a&&!sxutg_put(v,&sxutg_webp_vp8,p+8,10))return false;}
  p+=8+z+(z&1);
 }return !first;
}
static bool sxutg_ogg(sxutg_view*v){uint8_t h[282];uint64_t p=0;bool any=false;while(sxutg_span(v,p,27)&&v->c->count<20000&&!xx_pd_is_stopped(v->c->pd)){
 if(!sxutg_read(v,p,h,27)||xx_rt_memcmp(h,"OggS",4)||h[4])return false;unsigned n=h[26];if(!sxutg_read(v,p+27,h+27,n))return false;uint64_t data=0;for(unsigned i=0;i<n;i++)data+=h[27+i];if(!sxutg_span(v,p+27+n,data))return false;if(!sxutg_put(v,&sxutg_ogg_page,p,27))return false;any=true;for(unsigned i=0;i<n;i++)if(!sxutg_put(v,&sxutg_ogg_lacing,p+27+i,1))return false;p+=27+n+data;
 }return any;}
static bool sxutg_mp4(sxutg_view*v){uint64_t p=0;uint8_t h[32];bool first=true;while(sxutg_span(v,p,8)&&v->c->count<20000&&!xx_pd_is_stopped(v->c->pd)){
 if(!sxutg_read(v,p,h,8))return false;uint64_t z=sxutg_be(h);unsigned head=8;bool large=z==1;if(large){if(!sxutg_read(v,p+8,h+8,8))return false;z=((uint64_t)sxutg_be(h+8)<<32)|sxutg_be(h+12);head=16;}else if(!z)z=(uint64_t)v->c->size-p;
 bool uuid=!xx_rt_memcmp(h+4,"uuid",4),ftyp=!xx_rt_memcmp(h+4,"ftyp",4);if(z<head+(uuid?16:0)||!sxutg_span(v,p,z))return false;if(first&&(!ftyp||z<head+8||(z-head-8)%4))return false;
 if(!sxutg_put(v,large?&sxutg_isobmff_large_box:&sxutg_isobmff_box,p,head))return false;first=false;
 if(uuid){if(!sxutg_put(v,&sxutg_isobmff_uuid,p+head,16))return false;head+=16;}
 if(ftyp&&z>=head+8&&(z-head-8)%4==0){if(!sxutg_put(v,&sxutg_isobmff_ftyp,p+head,8))return false;for(uint64_t q=p+head+8;q<p+z;q+=4)if(!sxutg_put(v,&sxutg_isobmff_brand,q,4))return false;}p+=z;
 }return !first;}
bool sx_utage_media_build(sx_context*c)
{
 const xx_var*opt=xx_format_find_extra_parameter(c->f,XX_META_ID_OPT_PASSWORD);const char*key=opt?xx_var_get_str(opt):NULL;if(!key||!key[0])key="InputOriginalKey";size_t n=0;while(n<=256&&key[n])n++;if(!n||n>256)return false;sxutg_view v={c,key,n,0};uint8_t h[32];if(!sxutg_read(&v,0,h,32))return false;
 if(!xx_rt_memcmp(h,"\211PNG\r\n\032\n",8))(void)sxutg_png(&v);else if(h[0]=='B'&&h[1]=='M')(void)sxutg_bmp(&v);else if(h[0]==255&&h[1]==216&&h[2]==255)(void)sxutg_jpeg(&v);else if(!xx_rt_memcmp(h,"RIFF",4)&&!xx_rt_memcmp(h+8,"WEBP",4))(void)sxutg_webp(&v);else if(!xx_rt_memcmp(h,"OggS",4)&&!h[4])(void)sxutg_ogg(&v);else if(!xx_rt_memcmp(h+4,"ftyp",4))(void)sxutg_mp4(&v);
 return sxutg_finish(c);
}
