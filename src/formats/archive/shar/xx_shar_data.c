/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * shar data structures, moved out of the archivetransport schema family. */
#include "../../xx_format_schema_archivetransport.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxatp_shar_command_fields[]={
 SX_FIELD("command","char",0,0,SX_NONE),
};
const sx_layout sxatp_shar_command={UINT32_C(0x6089007a),"shar_command",sxatp_shar_command_fields,SX_COUNT(sxatp_shar_command_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_shar_redirection_fields[]={
 SX_FIELD("redirection_operator","char",0,0,SX_NONE),
};
const sx_layout sxatp_shar_redirection={UINT32_C(0x6089007b),"shar_redirection",sxatp_shar_redirection_fields,SX_COUNT(sxatp_shar_redirection_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_shar_heredoc_operator_fields[]={
 SX_FIELD("here_document_operator","char",0,0,SX_NONE),
};
const sx_layout sxatp_shar_heredoc_operator={UINT32_C(0x6089007c),"shar_heredoc_operator",sxatp_shar_heredoc_operator_fields,SX_COUNT(sxatp_shar_heredoc_operator_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_shar_delimiter_fields[]={
 SX_FIELD("delimiter","char",0,0,SX_NONE),
};
const sx_layout sxatp_shar_delimiter={UINT32_C(0x6089007d),"shar_delimiter",sxatp_shar_delimiter_fields,SX_COUNT(sxatp_shar_delimiter_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_shar_name_fields[]={
 SX_FIELD("member_name","char",0,0,SX_NONE),
};
const sx_layout sxatp_shar_name={UINT32_C(0x6089007e),"shar_name",sxatp_shar_name_fields,SX_COUNT(sxatp_shar_name_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_shar_quoted_marker_fields[]={
 SX_FIELD("quoting_marker","char",0,0,SX_NONE),
};
const sx_layout sxatp_shar_quoted_marker={UINT32_C(0x6089007f),"shar_quoted_marker",sxatp_shar_quoted_marker_fields,SX_COUNT(sxatp_shar_quoted_marker_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_shar_terminator_fields[]={
 SX_FIELD("terminating_delimiter","char",0,0,SX_NONE),
};
const sx_layout sxatp_shar_terminator={UINT32_C(0x60890080),"shar_terminator",sxatp_shar_terminator_fields,SX_COUNT(sxatp_shar_terminator_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_shar_prefix_expression_fields[]={
 SX_FIELD("prefix_expression","char",0,0,SX_NONE),
};
const sx_layout sxatp_shar_prefix_expression={UINT32_C(0x60890081),"shar_prefix_expression",sxatp_shar_prefix_expression_fields,SX_COUNT(sxatp_shar_prefix_expression_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_shar_uu_begin_fields[]={
 SX_FIELD("uuencode_begin_line","char",0,0,SX_NONE),
};
const sx_layout sxatp_shar_uu_begin={UINT32_C(0x60890082),"shar_uu_begin",sxatp_shar_uu_begin_fields,SX_COUNT(sxatp_shar_uu_begin_fields),SX_LE};
static bool sxatp_line(sx_context*c,uint64_t p,uint8_t*b,size_t cap,size_t*n,uint64_t*next){*n=0;uint64_t q=p;while(q<(uint64_t)c->size){uint8_t x;if(!sxatp_read(c,q,&x,1))return false;q++;if(x=='\r'||x=='\n'){if(x=='\r'&&q<(uint64_t)c->size){uint8_t y;if(!sxatp_read(c,q,&y,1))return false;if(y=='\n')q++;}*next=q;return true;}if(*n>=cap)return false;b[(*n)++]=x;}*next=q;return q>p;}
static bool sxatp_shword(sx_context*c,const uint8_t*b,size_t n,size_t p,uint64_t base,const sx_layout*l,size_t*end,size_t*start,size_t*len){while(p<n&&(b[p]==' '||b[p]=='\t'||b[p]=='\r'))p++;if(p>=n)return false;size_t original=p;if(b[p]=='\\')p++;if(p>=n)return false;size_t a=p,z;if(b[p]=='\''||b[p]=='"'){uint8_t quote=b[p++];a=p;while(p<n&&b[p]!=quote)p++;if(p>=n)return false;z=p-a;*end=p+1;}else{a=p;while(p<n&&!sxatp_space(b[p])&&!xx_rt_strchr(";&|<>()",b[p]))p++;z=p-a;*end=p;}if(!z)return false;if(a>original&&!sxatp_text(c,&sxatp_shar_quoted_marker,base+original,a-original,false))return false;if(*end>a+z&&!sxatp_text(c,&sxatp_shar_quoted_marker,base+a+z,*end-a-z,false))return false;if(!sxatp_text(c,l,base+a,z,false))return false;*start=a;*len=z;return true;}
static bool sxatp_shar_one(sx_context*c,uint64_t p,uint64_t header_size,uint64_t end){uint8_t b[4096];size_t n;uint64_t next;if(!header_size||!sxatp_line(c,p,b,sizeof(b),&n,&next)||next-p>header_size)return false;size_t a=0;while(a<n&&(b[a]==' '||b[a]=='\t'))a++;size_t cmd=a;while(a<n&&!sxatp_space(b[a])&&!xx_rt_strchr(";&|<>()",b[a]))a++;if(!sxatp_text(c,&sxatp_shar_command,p+cmd,a-cmd,false))return false;size_t here=a;while(here+1<n&&(b[here]!='<'||b[here+1]!='<'))here++;if(here+1>=n)return false;size_t op=2;if(here+2<n&&b[here+2]=='-')op++;if(!sxatp_text(c,&sxatp_shar_heredoc_operator,p+here,op,false))return false;size_t de,ds,dn;if(!sxatp_shword(c,b,n,here+op,p,&sxatp_shar_delimiter,&de,&ds,&dn))return false;
 for(size_t k=a;k+5<here;k++)if(b[k]=='s'&&b[k+1]=='/'&&b[k+2]=='^'){size_t z=(b[k+3]=='\\'&&b[k+4]=='t')?7:6;if(k+z<=here&&b[k+z-1]=='/'&&b[k+z-2]=='/')if(!sxatp_text(c,&sxatp_shar_prefix_expression,p+k,z,false))return false;}
 size_t red=a;while(red<n&&(b[red]!='>'||(red>=here&&red<de)))red++;if(red<n){size_t rz=red+1<n&&b[red+1]=='>'?2:1,e,s,z;if(!sxatp_text(c,&sxatp_shar_redirection,p+red,rz,false)||!sxatp_shword(c,b,n,red+rz,p,&sxatp_shar_name,&e,&s,&z))return false;}else if(next<p+header_size){size_t z;uint64_t nn;if(!sxatp_line(c,next,b,sizeof(b),&z,&nn)||!sxatp_text(c,&sxatp_shar_uu_begin,next,z,false))return false;}
 /* Native record cursor excludes the ending delimiter. A truncated body has no terminator. */
 if(end<(uint64_t)c->size){uint8_t t[4096];size_t z;uint64_t nn;if(!sxatp_line(c,end,t,sizeof(t),&z,&nn))return false;size_t k=0;if(op==3)while(k<z&&t[k]=='\t')k++;if(z-k==dn&&!sxatp_text(c,&sxatp_shar_terminator,end+k,dn,false))return false;}return true;}
static bool sxatp_shar(sx_context*c){Abstractformat*f=c->f;if(!f->create_archive_records_reading||!f->get_current_archive_record||!f->archive_record_move_to_next||!f->free_archive_records_reading)return false;xx_archive_record_state*s=(f->create_archive_records_reading)(f,NULL,c->pd);if(!s)return false;bool ok=true;for(unsigned i=0;i<SXATP_LIMIT&&!xx_pd_is_stopped(c->pd);i++){const xx_archive_record*r=(f->get_current_archive_record)(f,s);if(!r)break;if(r->header_offset<f->base_address||r->header_size<=0||r->data_offset<f->base_address||r->compressed_size<0){ok=false;break;}uint64_t p=(uint64_t)(r->header_offset-f->base_address),d=(uint64_t)(r->data_offset-f->base_address),z=(uint64_t)r->compressed_size;if(!sxatp_span(c,p,(uint64_t)r->header_size)||!sxatp_span(c,d,z)||!sxatp_shar_one(c,p,(uint64_t)r->header_size,d+z)){ok=false;break;}if(!(f->archive_record_move_to_next)(f,s,c->pd))break;}(f->free_archive_records_reading)(f,s);return ok;}
bool sx_shar_build(sx_context*c)
{
 return sxatp_shar(c);
}
