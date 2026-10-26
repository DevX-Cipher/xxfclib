/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * gerber rs274x data structures, moved out of the vectortext schema family. */
#include "../../xx_format_schema_vectortext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxvtx_aperture_number_fields[]={
 SX_FIELD("aperture_number","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxvtx_aperture_number={0x60620049U,"vectortext_aperture_number",sxvtx_aperture_number_fields,SX_COUNT(sxvtx_aperture_number_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_x_integer_digits_fields[]={
 SX_FIELD("x_integer_digits","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxvtx_x_integer_digits={0x6062007aU,"vectortext_x_integer_digits",sxvtx_x_integer_digits_fields,SX_COUNT(sxvtx_x_integer_digits_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_x_fraction_digits_fields[]={
 SX_FIELD("x_fraction_digits","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxvtx_x_fraction_digits={0x6062007bU,"vectortext_x_fraction_digits",sxvtx_x_fraction_digits_fields,SX_COUNT(sxvtx_x_fraction_digits_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_y_integer_digits_fields[]={
 SX_FIELD("y_integer_digits","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxvtx_y_integer_digits={0x6062007cU,"vectortext_y_integer_digits",sxvtx_y_integer_digits_fields,SX_COUNT(sxvtx_y_integer_digits_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_y_fraction_digits_fields[]={
 SX_FIELD("y_fraction_digits","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxvtx_y_fraction_digits={0x6062007dU,"vectortext_y_fraction_digits",sxvtx_y_fraction_digits_fields,SX_COUNT(sxvtx_y_fraction_digits_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_vertex_count_fields[]={
 SX_FIELD("vertex_count","ascii_signed",0,0,SX_COUNT_PROP),
};
const sx_layout sxvtx_vertex_count={0x6062007eU,"vectortext_vertex_count",sxvtx_vertex_count_fields,SX_COUNT(sxvtx_vertex_count_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_d_code_fields[]={
 SX_FIELD("d_code","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxvtx_d_code={0x6062007fU,"vectortext_d_code",sxvtx_d_code_fields,SX_COUNT(sxvtx_d_code_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_aperture_width_fields[]={
 SX_FIELD("aperture_width","ascii_real",0,0,SX_NONE),
};
const sx_layout sxvtx_aperture_width={0x60620080U,"vectortext_aperture_width",sxvtx_aperture_width_fields,SX_COUNT(sxvtx_aperture_width_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_aperture_height_fields[]={
 SX_FIELD("aperture_height","ascii_real",0,0,SX_NONE),
};
const sx_layout sxvtx_aperture_height={0x60620081U,"vectortext_aperture_height",sxvtx_aperture_height_fields,SX_COUNT(sxvtx_aperture_height_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_hole_diameter_fields[]={
 SX_FIELD("hole_diameter","ascii_real",0,0,SX_NONE),
};
const sx_layout sxvtx_hole_diameter={0x60620082U,"vectortext_hole_diameter",sxvtx_hole_diameter_fields,SX_COUNT(sxvtx_hole_diameter_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_coordinate_notation_fields[]={
 SX_FIELD("coordinate_notation","char",0,0,SX_STRING),
};
const sx_layout sxvtx_coordinate_notation={0x60620083U,"vectortext_coordinate_notation",sxvtx_coordinate_notation_fields,SX_COUNT(sxvtx_coordinate_notation_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_polarity_fields[]={
 SX_FIELD("polarity","char",0,0,SX_STRING),
};
const sx_layout sxvtx_polarity={0x60620084U,"vectortext_polarity",sxvtx_polarity_fields,SX_COUNT(sxvtx_polarity_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_aperture_shape_fields[]={
 SX_FIELD("aperture_shape","char",0,0,SX_STRING),
};
const sx_layout sxvtx_aperture_shape={0x60620085U,"vectortext_aperture_shape",sxvtx_aperture_shape_fields,SX_COUNT(sxvtx_aperture_shape_fields),SX_LE};
#define VT_EMIT(n,a,z) do{if(!sxvtx_emit(q,&sxvtx_##n,(a),(z)))return false;}while(0)
static bool sxvtx_gerber(sxvtx_cursor*q)
{
 int64_t p=0;
 while(p<q->n){if(q->c->count>=32000)return true;while(p<q->n&&sxvtx_space(q->b[p]))p++;if(p==q->n)break;bool extended=q->b[p]=='%';if(extended)p++;int64_t a=p;while(p<q->n&&q->b[p]!='*')p++;if(p==q->n)return false;int64_t end=p++;if(extended&&(p==q->n||q->b[p++]!='%'))return false;
  if(extended){
   while(a<end&&sxvtx_space(q->b[a]))a++;while(end>a&&sxvtx_space(q->b[end-1]))end--;
   if(end-a==10&&q->b[a]=='F'&&q->b[a+1]=='S'){
    VT_EMIT(keyword,a,2);VT_EMIT(zero_suppression,a+2,1);VT_EMIT(coordinate_notation,a+3,1);VT_EMIT(keyword,a+4,1);VT_EMIT(x_integer_digits,a+5,1);VT_EMIT(x_fraction_digits,a+6,1);VT_EMIT(keyword,a+7,1);VT_EMIT(y_integer_digits,a+8,1);VT_EMIT(y_fraction_digits,a+9,1);
   }else if(end-a==4&&q->b[a]=='M'&&q->b[a+1]=='O'){VT_EMIT(keyword,a,2);VT_EMIT(units,a+2,2);}
   else if(end-a==3&&q->b[a]=='L'&&q->b[a+1]=='P'){VT_EMIT(keyword,a,2);VT_EMIT(polarity,a+2,1);}
   else if(end-a>=3&&q->b[a]=='A'){
    /* Native lexer permits whitespace between the three ADD letters. */
    for(unsigned k=0;k<3;k++){while(a<end&&sxvtx_space(q->b[a]))a++;if(a==end)return false;VT_EMIT(keyword,a,1);a++;}
    while(a<end&&sxvtx_space(q->b[a]))a++;int64_t start=a;if(a<end&&(q->b[a]=='+'||q->b[a]=='-'))a++;while(a<end&&q->b[a]>='0'&&q->b[a]<='9')a++;VT_EMIT(aperture_number,start,a-start);if(a==end)return false;unsigned shape=q->b[a];VT_EMIT(aperture_shape,a,1);a++;while(a<end&&sxvtx_space(q->b[a]))a++;if(a==end||q->b[a++]!=',')return false;
    unsigned item=0;while(a<end){while(a<end&&sxvtx_space(q->b[a]))a++;start=a;while(a<end&&q->b[a]!='X')a++;int64_t stop=a;while(stop>start&&sxvtx_space(q->b[stop-1]))stop--;
     const sx_layout*l=&sxvtx_hole_diameter;if(shape=='C')l=item?&sxvtx_hole_diameter:&sxvtx_diameter;else if(shape=='R'||shape=='O')l=item==0?&sxvtx_aperture_width:item==1?&sxvtx_aperture_height:&sxvtx_hole_diameter;else if(shape=='P')l=item==0?&sxvtx_diameter:item==1?&sxvtx_vertex_count:item==2?&sxvtx_rotation:&sxvtx_hole_diameter;
     if(!sxvtx_emit(q,l,start,stop-start))return false;item++;if(a<end)a++;
    }
   }else if(end-a>=2&&q->b[a]=='T'){VT_EMIT(keyword,a,2);if(end-a>2)VT_EMIT(record_text,a+2,end-a-2);}
   else return false;
  }else if(end-a>=3&&!xx_rt_memcmp(q->b+a,"G04",3)){VT_EMIT(keyword,a,3);VT_EMIT(string_value,a+3,end-a-3);}
  else{
   while(a<end){while(a<end&&sxvtx_space(q->b[a]))a++;if(a==end)break;unsigned key=q->b[a];VT_EMIT(keyword,a,1);int64_t start=++a;while(start<end&&sxvtx_space(q->b[start]))start++;a=start;if(a<end&&(q->b[a]=='+'||q->b[a]=='-'))a++;while(a<end&&q->b[a]>='0'&&q->b[a]<='9')a++;if(a==start)return false;
    const sx_layout*l=key=='X'?&sxvtx_encoded_x:key=='Y'?&sxvtx_encoded_y:key=='D'?&sxvtx_d_code:&sxvtx_command_code;if(!sxvtx_emit(q,l,start,a-start))return false;
   }
  }
 }
 return true;
}
bool sx_gerber_rs274x_build(sxvtx_cursor*q)
{
 return sxvtx_gerber(q);
}
#undef VT_EMIT
