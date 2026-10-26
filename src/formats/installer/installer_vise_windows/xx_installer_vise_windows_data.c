/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Installer VISE for Windows data structures, moved out of the installerlast schema family. */
#include "../../xx_format_schema_installerlast.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxil_vise_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("build_time","uint32",4,4,SX_TIME),
    SX_FIELD("version","uint32",8,4,SX_ID),
    SX_FIELD("variant","uint32",12,4,SX_ID),
};
const sx_layout sxil_vise_header = {0x60850043U,"vise_header",sxil_vise_header_fields,SX_COUNT(sxil_vise_header_fields),SX_LE};
static const xx_data_struct_field_desc sxil_vise_footer_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("header_offset","uint32",4,4,SX_OFFSET),
};
const sx_layout sxil_vise_footer = {0x60850044U,"vise_footer",sxil_vise_footer_fields,SX_COUNT(sxil_vise_footer_fields),SX_LE};
static const xx_data_struct_field_desc sxil_vise_wrapper_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("container_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxil_vise_wrapper = {0x60850045U,"vise_wrapper",sxil_vise_wrapper_fields,SX_COUNT(sxil_vise_wrapper_fields),SX_LE};
static const xx_data_struct_field_desc sxil_vise_string8_fields[] = {
    SX_FIELD("string_size","uint8",0,1,SX_SIZE),
};
const sx_layout sxil_vise_string8 = {0x60850046U,"vise_string8",sxil_vise_string8_fields,SX_COUNT(sxil_vise_string8_fields),SX_LE};
static const xx_data_struct_field_desc sxil_vise_string16_fields[] = {
    SX_FIELD("string_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxil_vise_string16 = {0x60850047U,"vise_string16",sxil_vise_string16_fields,SX_COUNT(sxil_vise_string16_fields),SX_LE};
static const xx_data_struct_field_desc sxil_vise_masked_length_fields[] = {
    SX_FIELD("length_and_flags","uint8",0,1,SX_NONE),
};
const sx_layout sxil_vise_masked_length = {0x60850048U,"vise_masked_length",sxil_vise_masked_length_fields,SX_COUNT(sxil_vise_masked_length_fields),SX_LE};
static const xx_data_struct_field_desc sxil_vise_setup_count_fields[] = {
    SX_FIELD("file_count","uint16",0,2,SX_COUNT_PROP),
};
const sx_layout sxil_vise_setup_count = {0x60850049U,"vise_setup_count",sxil_vise_setup_count_fields,SX_COUNT(sxil_vise_setup_count_fields),SX_LE};
static const xx_data_struct_field_desc sxil_vise_setup_fields_fields[] = {
    SX_FIELD("dos_date","uint16",0,2,SX_NONE),
    SX_FIELD("dos_time","uint16",2,2,SX_NONE),
    SX_FIELD("unknown","byte[8]",4,8,SX_NONE),
    SX_FIELD("packed_size","uint32",12,4,SX_SIZE),
};
const sx_layout sxil_vise_setup_fields = {0x6085004aU,"vise_setup_fields",sxil_vise_setup_fields_fields,SX_COUNT(sxil_vise_setup_fields_fields),SX_LE};
static const xx_data_struct_field_desc sxil_vise_packed_size_fields[] = {
    SX_FIELD("packed_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxil_vise_packed_size = {0x6085004bU,"vise_packed_size",sxil_vise_packed_size_fields,SX_COUNT(sxil_vise_packed_size_fields),SX_LE};
static const xx_data_struct_field_desc sxil_vise_object4_fields[] = {
    SX_FIELD("reserved","byte[4]",0,4,SX_RESERVED),
    SX_FIELD("unpacked_size","uint32",4,4,SX_SIZE),
    SX_FIELD("packed_size","uint32",8,4,SX_SIZE),
    SX_FIELD("flags","uint32",12,4,SX_FLAGS),
    SX_FIELD("data_offset","uint32",16,4,SX_OFFSET),
};
const sx_layout sxil_vise_object4 = {0x6085004cU,"vise_object4",sxil_vise_object4_fields,SX_COUNT(sxil_vise_object4_fields),SX_LE};
static const xx_data_struct_field_desc sxil_vise_object6_fields[] = {
    SX_FIELD("reserved","byte[6]",0,6,SX_RESERVED),
    SX_FIELD("unpacked_size","uint32",6,4,SX_SIZE),
    SX_FIELD("packed_size","uint32",10,4,SX_SIZE),
    SX_FIELD("flags","uint32",14,4,SX_FLAGS),
    SX_FIELD("data_offset","uint32",18,4,SX_OFFSET),
};
const sx_layout sxil_vise_object6 = {0x6085004dU,"vise_object6",sxil_vise_object6_fields,SX_COUNT(sxil_vise_object6_fields),SX_LE};
#define SXIL_ADD(c,n,p) sxil_put(c,&sxil_##n,p,1)
static bool sxil_vise_string(sx_context*c,uint64_t*p,uint64_t end,bool wide,bool masked){uint8_t b[2];unsigned w=wide?2:1;if(*p>end||w>end-*p||!sxil_read(c,*p,b,w))return false;uint64_t n=wide?sxil16(b,false):b[0];if(masked)n&=63;if(n>end-*p-w)return false;if(!sxil_put(c,wide?&sxil_vise_string16:masked?&sxil_vise_masked_length:&sxil_vise_string8,*p,1)||!sxil_name(c,*p+w,n))return false;*p+=w+n;return true;}
/* Match the native locator's ordered physical anchors. An ESIV byte pattern
 * inside executable code is not a container root. All coordinates are relative
 * to the current reader base; no subclass storage or ownership is borrowed. */
typedef struct sxil_vise_root {uint64_t head,wrapper,wrapper_size,footer,end,cert;} sxil_vise_root;
static bool sxil_vise_follow(sx_context*c,uint64_t pointer,uint64_t footer,sxil_vise_root*r){
 uint8_t h[12];if(pointer<64||pointer>footer||16>footer-pointer||!sxil_read(c,pointer,h,12))return false;
 if(!xx_rt_memcmp(h,"ESIV",4)){r->head=pointer;r->wrapper=UINT64_MAX;r->wrapper_size=0;return true;}
 if(!xx_rt_memcmp(h,"SIVM",4)&&!xx_rt_memcmp(h+8,"ESIV",4)&&24<=footer-pointer){r->head=pointer+8;r->wrapper=pointer;r->wrapper_size=sxil32(h+4,false);return true;}return false;
}
static bool sxil_vise_footer_is(sx_context*c,uint64_t p,uint64_t anchor){uint8_t h[8];return anchor<=UINT32_MAX&&sxil_read(c,p,h,8)&&!xx_rt_memcmp(h,"ESIV",4)&&sxil32(h+4,false)==anchor;}
static bool sxil_vise_locate(sx_context*c,sxil_vise_root*r){
 uint8_t dos[64],nt[24],sec[40],head[16];uint64_t total=(uint64_t)c->size;
 r->head=r->wrapper=r->footer=r->cert=UINT64_MAX;r->wrapper_size=0;r->end=total;
 if(total<256||!sxil_read(c,0,dos,64)||dos[0]!='M'||dos[1]!='Z')return false;
 uint64_t lf=sxil32(dos+60,false);if(lf<4||lf>0x10000000||!sxil_read(c,lf,nt,24))return false;
 if(nt[0]=='N'&&nt[1]=='E'){
  uint8_t f[8];uint64_t at=total-8;if(!sxil_read(c,at,f,8)||xx_rt_memcmp(f,"ESIV",4)||!sxil_vise_follow(c,sxil32(f+4,false),at,r))return false;r->footer=at;r->end=at;
 }else{
  if(xx_rt_memcmp(nt,"PE\0\0",4))return false;unsigned count=sxil16(nt+6,false),opt=sxil16(nt+20,false);uint64_t tab=lf+24+opt,overlay=0;
  if(!count||count>96||opt>4096||!sxil_span(c,tab,40U*count))return false;
  uint16_t magic;unsigned dd=0;if(opt>=2&&sxil_u16(c,lf+24,&magic))dd=magic==0x10b?96:magic==0x20b?112:0;
  if(dd&&opt>=dd+40){uint32_t countdir,off,size;if(sxil_u32(c,lf+24+dd-4,&countdir)&&countdir>=5&&sxil_u32(c,lf+24+dd+32,&off)&&sxil_u32(c,lf+24+dd+36,&size)&&size>=8&&off>=64&&sxil_span(c,off,size))r->cert=off;}
  for(unsigned i=0;i<count;i++){if(!sxil_read(c,tab+40U*i,sec,40))return false;uint64_t size=sxil32(sec+16,false),off=sxil32(sec+20,false);if(size&&off+size>overlay)overlay=off+size;}
  if(overlay>=64&&sxil_span(c,overlay,16)&&sxil_eq(c,overlay,"ESIV",4))r->head=overlay;
  for(unsigned i=0;r->head==UINT64_MAX&&i<count;i++){
   uint8_t w[12];if(!sxil_read(c,tab+40U*i,sec,40))return false;uint64_t size=sxil32(sec+16,false),off=sxil32(sec+20,false);
   if(size<32||off<64||!sxil_read(c,off,w,12)||xx_rt_memcmp(w,"SIVM",4)||xx_rt_memcmp(w+8,"ESIV",4))continue;
   uint64_t z=sxil32(w+4,false);if(z<24||!sxil_span(c,off,z+8))continue;r->head=off+8;r->wrapper=off;r->wrapper_size=z;
  }
  if(r->head==UINT64_MAX){
   uint64_t end=r->cert!=UINT64_MAX&&r->cert>=overlay?r->cert:total,low=end>64?end-64:0;
   if(end>=8)for(uint64_t p=end-8;;p--){uint8_t f[8];if(p<low)break;if(!sxil_read(c,p,f,8))return false;if(!xx_rt_memcmp(f,"ESIV",4)&&sxil_vise_follow(c,sxil32(f+4,false),p,r)){r->footer=p;break;}if(!p)break;}
  }
  if(r->wrapper!=UINT64_MAX&&sxil_span(c,r->wrapper,r->wrapper_size+8))r->end=r->wrapper+r->wrapper_size;
 }
 if(r->head==UINT64_MAX||!sxil_span(c,r->head,19)||!sxil_read(c,r->head,head,16)||xx_rt_memcmp(head,"ESIV",4)||sxil32(head+8,false)!=1)return false;
 if(r->footer==UINT64_MAX){
  uint64_t anchor=r->wrapper!=UINT64_MAX?r->wrapper:r->head;
  if(r->wrapper!=UINT64_MAX){uint64_t p=r->wrapper+r->wrapper_size;if(sxil_vise_footer_is(c,p,anchor))r->footer=p;}
  else{
   if(total>=r->head+24&&sxil_vise_footer_is(c,total-8,anchor))r->footer=total-8;
   if(r->footer==UINT64_MAX&&r->cert!=UINT64_MAX&&r->cert>=r->head+24){uint64_t low=r->cert>64?r->cert-64:0;for(uint64_t p=r->cert-8;p>=r->head+16&&p>=low;p--)if(sxil_vise_footer_is(c,p,anchor)){r->footer=p;break;}}
   if(r->footer==UINT64_MAX&&anchor<=UINT32_MAX){uint8_t needle[8]={'E','S','I','V',0,0,0,0};for(unsigned i=0;i<4;i++)needle[4+i]=(uint8_t)(anchor>>(8*i));uint64_t start=r->head+16,end=total;if(end-start>(UINT64_C(256)<<20))end=start+(UINT64_C(256)<<20);uint64_t p;if(sxil_find(c,needle,8,start,end,&p))r->footer=p;}
  }
 }
 if(r->footer!=UINT64_MAX)r->end=r->footer;return true;
}
static bool sxil_vise(sx_context*c,sxil_records*r){sxil_vise_root root;if(!sxil_vise_locate(c,&root))return true;uint64_t p=root.head,head=p;
 if(!SXIL_ADD(c,vise_header,p))return false;
 if(root.wrapper!=UINT64_MAX&&!SXIL_ADD(c,vise_wrapper,root.wrapper))return false;
 p+=16;for(unsigned k=0;k<3;k++)if(!sxil_vise_string(c,&p,root.end,false,k==1))return true;
 uint16_t n;if(!sxil_u16(c,p,&n)||!n)return true;if(!SXIL_ADD(c,vise_setup_count,p))return false;p+=2;
 for(unsigned i=0;i<n;i++){if(!sxil_vise_string(c,&p,root.end,false,false))return true;uint32_t z;if(!sxil_u32(c,p+12,&z)||!sxil_span(c,p+16,z))return true;if(!SXIL_ADD(c,vise_setup_fields,p))return false;p+=16+(uint64_t)z;}
 /* Authenticated member callbacks also describe second-table setup files,
  * settings frames and variant install objects. They contain physical spans. */
 for(size_t i=0;i<r->count;i++){sxil_member*m=r->items+i;if(m->header>=head&&m->header<p)continue;
  if(m->header_size==4){if(!SXIL_ADD(c,vise_packed_size,m->header))return false;continue;}
  uint8_t h[2];if(!sxil_read(c,m->header,h,2))continue;uint64_t z=h[0];if(z+17==m->header_size){if(!SXIL_ADD(c,vise_string8,m->header)||!sxil_name(c,m->header+1,z)||!SXIL_ADD(c,vise_setup_fields,m->header+1+z))return false;continue;}
  z=sxil16(h,false);for(unsigned extra=4;extra<=6;extra+=2){uint64_t at=m->header+2+z;if(m->header_size==2+z+extra+16&&sxil_span(c,at,extra+16)){uint32_t off;if(sxil_u32(c,at+extra+12,&off)&&head+(uint64_t)off==m->data){if(!SXIL_ADD(c,vise_string16,m->header)||!sxil_name(c,m->header+2,z)||!sxil_put(c,extra==4?&sxil_vise_object4:&sxil_vise_object6,at,1))return false;break;}}}
 }
 if(root.footer!=UINT64_MAX&&!SXIL_ADD(c,vise_footer,root.footer))return false;return true;
}
bool sx_installer_vise_windows_build(sx_context*c,sxil_records records)
{
 return sxil_vise(c,&records);
}
#undef SXIL_ADD
