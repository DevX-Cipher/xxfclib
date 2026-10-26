/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * btoa / Ascii85 data structures, moved out of the archiveremaining schema family. */
#include "../../xx_format_schema_archiveremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxarm_transport_hex_size_fields[]={
 SX_FIELD("transport_hex_size","ascii_hex",0,0,SX_SIZE),
};
const sx_layout sxarm_transport_hex_size={UINT32_C(0x607c000b),"transport_hex_size",sxarm_transport_hex_size_fields,SX_COUNT(sxarm_transport_hex_size_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_btoa_line_width_fields[]={
 SX_FIELD("btoa_line_width","ascii_decimal",0,0,SX_COUNT_PROP),
};
const sx_layout sxarm_btoa_line_width={UINT32_C(0x607c0014),"btoa_line_width",sxarm_btoa_line_width_fields,SX_COUNT(sxarm_btoa_line_width_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_btoa_begin_fields[]={
 SX_FIELD("marker","char[11]",0,11,SX_SIGNATURE),
};
const sx_layout sxarm_btoa_begin={UINT32_C(0x607c0040),"btoa_begin",sxarm_btoa_begin_fields,SX_COUNT(sxarm_btoa_begin_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_btoa5_begin_fields[]={
 SX_FIELD("marker","char[6]",0,6,SX_SIGNATURE),
};
const sx_layout sxarm_btoa5_begin={UINT32_C(0x607c0041),"btoa5_begin",sxarm_btoa5_begin_fields,SX_COUNT(sxarm_btoa5_begin_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_btoa_end_fields[]={
 SX_FIELD("marker","char[11]",0,11,SX_ID),
};
const sx_layout sxarm_btoa_end={UINT32_C(0x607c0042),"btoa_end",sxarm_btoa_end_fields,SX_COUNT(sxarm_btoa_end_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_ascii85_begin_fields[]={
 SX_FIELD("marker","char[2]",0,2,SX_SIGNATURE),
};
const sx_layout sxarm_ascii85_begin={UINT32_C(0x607c0043),"ascii85_begin",sxarm_ascii85_begin_fields,SX_COUNT(sxarm_ascii85_begin_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_ascii85_end_fields[]={
 SX_FIELD("marker","char[2]",0,2,SX_ID),
};
const sx_layout sxarm_ascii85_end={UINT32_C(0x607c0044),"ascii85_end",sxarm_ascii85_end_fields,SX_COUNT(sxarm_ascii85_end_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_ascii85_group_fields[]={
 SX_FIELD("ascii85_group","char",0,0,SX_NONE),
};
const sx_layout sxarm_ascii85_group={UINT32_C(0x607c0045),"ascii85_group",sxarm_ascii85_group_fields,SX_COUNT(sxarm_ascii85_group_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_ascii85_shorthand_fields[]={
 SX_FIELD("token","char[1]",0,1,SX_ID),
};
const sx_layout sxarm_ascii85_shorthand={UINT32_C(0x607c0046),"ascii85_shorthand",sxarm_ascii85_shorthand_fields,SX_COUNT(sxarm_ascii85_shorthand_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_btoa_line_check_fields[]={
 SX_FIELD("line_check_character","char[1]",0,1,SXARM_CHECKSUM),
};
const sx_layout sxarm_btoa_line_check={UINT32_C(0x607c0047),"btoa_line_check",sxarm_btoa_line_check_fields,SX_COUNT(sxarm_btoa_line_check_fields),SX_LE};
/* Encoded Ascii85 digit runs keep their exact stored character positions.
 * Whitespace splits a run; no claim that a fragment is a full decoded word. */
static bool sxarm_a85(sx_context*c,uint64_t p,const uint8_t*b,size_t n){for(size_t i=0;i<n;){if(b[i]>='!'&&b[i]<='u'){size_t a=i;while(i<n&&b[i]>='!'&&b[i]<='u')i++;if(!sxarm_text(c,&sxarm_ascii85_group,p+a,i-a,false))return false;}else{if((b[i]=='z'||b[i]=='y'||b[i]=='w')&&!sxarm_add(c,&sxarm_ascii85_shorthand,p+i))return false;i++;}}return true;}
static bool sxarm_btoa(sx_context*c){uint64_t p=0,next;uint8_t b[4096];size_t n;bool body=false,new_format=false;while(p<(uint64_t)c->size){if(!sxarm_line(c,p,b,sizeof(b),&n,&next))return true;if(n>=11&&!xx_rt_memcmp(b,"xbtoa Begin",11)){if(!sxarm_add(c,&sxarm_btoa_begin,p))return false;body=true;new_format=false;}else if(n>=7&&!xx_rt_memcmp(b,"xbtoa5",6)&&(b[6]==' '||b[6]=='\t')){if(!sxarm_add(c,&sxarm_btoa5_begin,p))return false;size_t q=6,e=n;while(e&& (b[e-1]==' '||b[e-1]=='\t'))e--;while(q<e&&(b[q]==' '||b[q]=='\t'))q++;size_t a=q;while(q<e&&b[q]>='0'&&b[q]<='9')q++;if(!sxarm_text(c,&sxarm_btoa_line_width,p+a,q-a,false))return false;while(q<e&&(b[q]==' '||b[q]=='\t'))q++;if(e<q+7||xx_rt_memcmp(b+e-5,"Begin",5))return true;size_t name_end=e-6;while(name_end>q&&(b[name_end-1]==' '||b[name_end-1]=='\t'))name_end--;if(!sxarm_text(c,&sxarm_transport_filename,p+q,name_end-q,false))return false;body=true;new_format=true;}else if(n>=11&&!xx_rt_memcmp(b,"xbtoa End N",11)){if(!sxarm_add(c,&sxarm_btoa_end,p))return false;size_t q=11;unsigned field=0;while(q<n){while(q<n&&(b[q]==' '||b[q]=='\t'))q++;size_t a=q;while(q<n&&b[q]!=' '&&b[q]!='\t')q++;if(q==a)break;if(q-a==1&&(b[a]=='E'||b[a]=='S'||b[a]=='R'))continue;const sx_layout*l=field==0?&sxarm_transport_decimal_size:field==1?&sxarm_transport_hex_size:&sxarm_transport_crc;if(!sxarm_numeric_text(c,l,p+a,b+a,q-a))return false;field++;}body=false;}else{size_t a=0,end=n;if(!body&&n>=2&&b[0]=='<'&&b[1]=='~'){if(!sxarm_add(c,&sxarm_ascii85_begin,p))return false;a=2;body=true;}if(body){if(new_format&&end>a){end--;if(!sxarm_add(c,&sxarm_btoa_line_check,p+end))return false;}for(size_t q=a;q+1<n;q++)if(b[q]=='~'&&b[q+1]=='>'){end=q;if(!sxarm_add(c,&sxarm_ascii85_end,p+q))return false;body=false;break;}if(!sxarm_a85(c,p+a,b+a,end-a))return false;}}p=next;}return true;}
bool sx_btoa_build(sx_context*c)
{
 return sxarm_btoa(c);
}
