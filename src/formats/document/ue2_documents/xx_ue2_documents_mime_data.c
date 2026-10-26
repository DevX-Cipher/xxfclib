/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * MIME email / HTML archive data structures, moved out of the documentwire schema family. */
#include "../../xx_format_schema_documentwire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdw_mime_field_name_fields[]={
 SX_FIELD("mime_field_name","utf8",0,0,SX_STRING),
};
const sx_layout sxdw_mime_field_name={0x6074005cU,"documentwire_mime_field_name",sxdw_mime_field_name_fields,SX_COUNT(sxdw_mime_field_name_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mime_field_value_fields[]={
 SX_FIELD("mime_field_value","utf8",0,0,SX_STRING),
};
const sx_layout sxdw_mime_field_value={0x6074005dU,"documentwire_mime_field_value",sxdw_mime_field_value_fields,SX_COUNT(sxdw_mime_field_value_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mime_continuation_fields[]={
 SX_FIELD("mime_continuation","utf8",0,0,SX_STRING),
};
const sx_layout sxdw_mime_continuation={0x6074005eU,"documentwire_mime_continuation",sxdw_mime_continuation_fields,SX_COUNT(sxdw_mime_continuation_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mime_boundary_fields[]={
 SX_FIELD("mime_boundary","utf8",0,0,SX_STRING),
};
const sx_layout sxdw_mime_boundary={0x6074005fU,"documentwire_mime_boundary",sxdw_mime_boundary_fields,SX_COUNT(sxdw_mime_boundary_fields),SX_LE};
static bool sxdw_ci(const uint8_t*b,int64_t n,const char*s)
{size_t z=xx_rt_strlen(s);if(n<0||(uint64_t)n!=z)return false;for(size_t i=0;i<z;i++){uint8_t c=b[i],d=(uint8_t)s[i];if(c>='A'&&c<='Z')c+=32;if(d>='A'&&d<='Z')d+=32;if(c!=d)return false;}return true;}
static bool sxdw_mime_parameter(const char*field,const char*key,char*out,size_t cap)
{
 size_t p=0,n=xx_rt_strlen(field);while(p<n){while(p<n&&field[p]!=';')p++;if(p==n)break;p++;while(p<n&&(field[p]==' '||field[p]=='\t'))p++;size_t a=p;while(p<n&&field[p]!='='&&field[p]!=';'&&field[p]!=' '&&field[p]!='\t')p++;bool wanted=sxdw_ci((const uint8_t*)field+a,(int64_t)(p-a),key);while(p<n&&(field[p]==' '||field[p]=='\t'))p++;if(p==n||field[p]!='=')continue;p++;while(p<n&&(field[p]==' '||field[p]=='\t'))p++;bool quoted=p<n&&field[p]=='"';if(quoted)p++;size_t used=0;
  while(p<n&&(quoted?field[p]!='"':field[p]!=';'&&field[p]!=' '&&field[p]!='\t')){char c=field[p++];if(quoted&&c=='\\'){if(p==n)return false;c=field[p++];}if(wanted){if((unsigned char)c<32||used+1>=cap)return false;out[used++]=c;}}
  if(wanted){if(quoted&&(p==n||field[p]!='"'))return false;out[used]=0;return used!=0;}if(quoted&&p<n)p++;
 }return false;
}
static bool sxdw_mime(sxdw_cursor*q,int64_t start,int64_t end,unsigned depth)
{
 if(depth>32||start<0||end>q->n||start>=end)return false;int64_t save_n=q->n;q->n=end;q->p=start;char type[1024]={0},encoding[128]={0};char*target=NULL;size_t cap=0;
 int64_t a,e;bool blank=false;
 while(q->c->count<32000&&sxdw_line(q,&a,&e)){if(a==e){blank=true;break;}int64_t val=a;
  bool continuation=q->b[a]==' '||q->b[a]=='\t';if(continuation){if(!sxdw_value(q,&sxdw_mime_continuation,a,e-a))return false;}
  else{int64_t colon=a;while(colon<e&&q->b[colon]!=':')colon++;if(colon==a||colon==e)return false;if(!sxdw_value(q,&sxdw_mime_field_name,a,colon-a))return false;val=colon+1;if(!sxdw_value(q,&sxdw_mime_field_value,val,e-val))return false;target=NULL;cap=0;if(sxdw_ci(q->b+a,colon-a,"content-type")){target=type;cap=sizeof(type);}else if(sxdw_ci(q->b+a,colon-a,"content-transfer-encoding")){target=encoding;cap=sizeof(encoding);}}
  while(val<e&&(q->b[val]==' '||q->b[val]=='\t'))val++;int64_t trim=e;while(trim>val&&(q->b[trim-1]==' '||q->b[trim-1]=='\t'))trim--;
  if(target){size_t used=continuation?xx_rt_strlen(target):0;if(continuation&&used+1<cap)target[used++]=' ';if((uint64_t)(trim-val)>=cap-used)return false;xx_rt_memcpy(target+used,q->b+val,(size_t)(trim-val));target[used+(size_t)(trim-val)]=0;}
 }
 if(!blank){q->n=save_n;return q->c->count>=32000;}int64_t body=q->p;
 if(xx_rt_strlen(type)>10&&sxdw_ci((const uint8_t*)type,10,"multipart/")){char boundary[256];if(!sxdw_mime_parameter(type,"boundary",boundary,sizeof(boundary)))return false;size_t length=xx_rt_strlen(boundary);int64_t part=-1;bool closed=false;
  while(q->c->count<32000&&sxdw_line(q,&a,&e)){if(e-a<(int64_t)length+2||q->b[a]!='-'||q->b[a+1]!='-'||xx_rt_memcmp(q->b+a+2,boundary,length))continue;int64_t p=a+2+(int64_t)length;bool closing=p+2<=e&&q->b[p]=='-'&&q->b[p+1]=='-';if(closing)p+=2;while(p<e&&(q->b[p]==' '||q->b[p]=='\t'))p++;if(p!=e)continue;int64_t next=q->p;if(!sxdw_value(q,&sxdw_mime_boundary,a,e-a))return false;
   if(part>=0){int64_t stop=a;if(stop>part&&q->b[stop-1]=='\n'){stop--;if(stop>part&&q->b[stop-1]=='\r')stop--;}if(!sxdw_mime(q,part,stop,depth+1))return false;}q->n=end;q->p=next;if(closing){closed=true;break;}part=next;
  }if(!closed&&q->c->count<32000)return false;
 }else if(xx_rt_strlen(type)>=14&&sxdw_ci((const uint8_t*)type,14,"message/rfc822")&&(!encoding[0]||sxdw_ci((const uint8_t*)encoding,(int64_t)xx_rt_strlen(encoding),"7bit")||sxdw_ci((const uint8_t*)encoding,(int64_t)xx_rt_strlen(encoding),"8bit")||sxdw_ci((const uint8_t*)encoding,(int64_t)xx_rt_strlen(encoding),"binary"))){if(body<end&&!sxdw_mime(q,body,end,depth+1))return false;}
 q->n=save_n;return !xx_pd_is_stopped(q->c->pd);
}
bool sx_ue2_documents_mime_build(sxdw_cursor*q)
{
 return sxdw_mime(q,0,q->n,0);
}
