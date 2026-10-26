/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * sfx_wasp_windows_auto data structures, moved out of the installerextras schema family. */
#include "../../xx_format_schema_installerextras.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxiex_wasp_resource_shift_fields[] = {
    SX_FIELD("alignment_shift","uint16",0,2,SX_NONE),
};
const sx_layout sxiex_wasp_resource_shift = {0x60820030U,"wasp_resource_shift",sxiex_wasp_resource_shift_fields,SX_COUNT(sxiex_wasp_resource_shift_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_wasp_resource_type_fields[] = {
    SX_FIELD("type_identifier","uint16",0,2,SX_ID),
    SX_FIELD("resource_count","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("reserved","uint32",4,4,SX_RESERVED),
};
const sx_layout sxiex_wasp_resource_type = {0x60820031U,"wasp_resource_type",sxiex_wasp_resource_type_fields,SX_COUNT(sxiex_wasp_resource_type_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_wasp_resource_entry_fields[] = {
    SX_FIELD("offset_units","uint16",0,2,SX_NONE),
    SX_FIELD("length_units","uint16",2,2,SX_NONE),
    SX_FIELD("flags","uint16",4,2,SX_FLAGS),
    SX_FIELD("resource_identifier","uint16",6,2,SX_ID),
    SX_FIELD("reserved","uint32",8,4,SX_RESERVED),
};
const sx_layout sxiex_wasp_resource_entry = {0x60820032U,"wasp_resource_entry",sxiex_wasp_resource_entry_fields,SX_COUNT(sxiex_wasp_resource_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_wasp_string_length_fields[] = {
    SX_FIELD("length","uint8",0,1,SX_SIZE),
};
const sx_layout sxiex_wasp_string_length = {0x60820033U,"wasp_string_length",sxiex_wasp_string_length_fields,SX_COUNT(sxiex_wasp_string_length_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_wasp_payload_size_fields[] = {
    SX_FIELD("payload_size","ascii_decimal",0,0,SX_SIZE),
};
const sx_layout sxiex_wasp_payload_size = {0x60820034U,"wasp_payload_size",sxiex_wasp_payload_size_fields,SX_COUNT(sxiex_wasp_payload_size_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_wasp_name_separator_fields[] = {
    SX_FIELD("separator","char[1]",0,1,SX_NONE),
};
const sx_layout sxiex_wasp_name_separator = {0x60820061U,"wasp_name_separator",sxiex_wasp_name_separator_fields,SX_COUNT(sxiex_wasp_name_separator_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_wasp_run_marker_fields[] = {
    SX_FIELD("run_after_extract","char[1]",0,1,SX_NONE),
};
const sx_layout sxiex_wasp_run_marker = {0x60820062U,"wasp_run_marker",sxiex_wasp_run_marker_fields,SX_COUNT(sxiex_wasp_run_marker_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_wasp_resource_end_fields[] = {
    SX_FIELD("type_terminator","uint16",0,2,SX_SIGNATURE),
};
const sx_layout sxiex_wasp_resource_end = {0x60820063U,"wasp_resource_end",sxiex_wasp_resource_end_fields,SX_COUNT(sxiex_wasp_resource_end_fields),SX_LE};
#define SXIEX_ADD(c,n,p) sxiex_put(c,&sxiex_##n,p,1)
/* NE resource row offsets are kept in their original shift units. */
static bool sxiex_wasp(sx_context*c,const sxiex_records*r){
 (void)r;uint8_t dos[64],ne[40],b[12];if(!sxiex_read(c,0,dos,64)||dos[0]!='M'||dos[1]!='Z')return true;uint64_t np=sxiex32(dos+60,false);if(!sxiex_read(c,np,ne,40)||ne[0]!='N'||ne[1]!='E')return true;
 uint64_t start=np+sxiex16(ne+36,false),end=np+sxiex16(ne+38,false),p=start;uint16_t shift;if(end<start||!sxiex_span(c,start,end-start)||!sxiex_u16(c,p,&shift)||shift>16)return true;
 if(!SXIEX_ADD(c,wasp_resource_shift,p))return false;p+=2;
 for(unsigned row=0;row<4096&&end-p>=2;row++){
  uint16_t type;if(!sxiex_u16(c,p,&type))break;if(!type){if(!SXIEX_ADD(c,wasp_resource_end,p))return false;break;}if(end-p<8||!sxiex_read(c,p,b,8))break;uint16_t n=sxiex16(b+2,false);if((uint64_t)n*12>end-p-8)break;if(!SXIEX_ADD(c,wasp_resource_type,p))return false;
  if(!(type&0x8000U)&&type<end-start){uint64_t np=start+type;uint8_t len;if(sxiex_read(c,np,&len,1)&&len<=end-np-1){if(!SXIEX_ADD(c,wasp_string_length,np)||!sxiex_name(c,np+1,len))return false;}}p+=8;
  for(unsigned i=0;i<n;i++,p+=12){if(!sxiex_read(c,p,b,12))return false;if(!SXIEX_ADD(c,wasp_resource_entry,p))return false;
   if(type==0x8006){uint64_t q=(uint64_t)sxiex16(b,false)<<shift,z=(uint64_t)sxiex16(b+2,false)<<shift;if(!sxiex_span(c,q,z))continue;uint64_t e=q+z;
    for(unsigned j=0;j<16&&q<e;j++){uint8_t len,text[255];if(!sxiex_read(c,q,&len,1)||len>e-q-1)break;uint64_t s=q+1;q=s+len;if(!len)continue;if(!sxiex_read(c,s,text,len))return false;unsigned comma=len;for(unsigned k=0;k<len;k++)if(text[k]==',')comma=k;unsigned last=len;if(last&&text[last-1]=='*')last--;if(!comma||comma+1>=last)continue;bool number=true;for(unsigned k=comma+1;k<last;k++)if(text[k]<'0'||text[k]>'9')number=false;if(!number||last-comma-1>24)continue;
     if(!SXIEX_ADD(c,wasp_string_length,s-1)||!sxiex_name(c,s,comma)||!SXIEX_ADD(c,wasp_name_separator,s+comma)||!sxiex_text(c,&sxiex_wasp_payload_size,s+comma+1,last-comma-1)||(last<len&&!SXIEX_ADD(c,wasp_run_marker,s+last)))return false;
    }
   }
  }
 }
 return true;
}
bool sx_sfx_wasp_windows_auto_build(sx_context*c,const sxiex_records*records)
{
 return sxiex_wasp(c,records);
}
#undef SXIEX_ADD
