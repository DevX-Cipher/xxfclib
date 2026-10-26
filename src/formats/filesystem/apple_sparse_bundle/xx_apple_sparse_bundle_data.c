/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Apple sparse bundle data structures, moved out of the diskremaining schema family. */
#include "../../xx_format_schema_diskremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdr_plist_tag_fields[] = {
    SX_FIELD("tag","utf8",0,0,SX_NONE),
};
const sx_layout sxdr_plist_tag = {0x607f001fU,"plist_tag",sxdr_plist_tag_fields,SX_COUNT(sxdr_plist_tag_fields),SX_LE};
static const xx_data_struct_field_desc sxdr_plist_key_fields[] = {
    SX_FIELD("key","utf8",0,0,SX_NONE),
};
const sx_layout sxdr_plist_key = {0x607f0020U,"plist_key",sxdr_plist_key_fields,SX_COUNT(sxdr_plist_key_fields),SX_LE};
static const xx_data_struct_field_desc sxdr_plist_string_fields[] = {
    SX_FIELD("value","utf8",0,0,SX_NONE),
};
const sx_layout sxdr_plist_string = {0x607f0021U,"plist_string",sxdr_plist_string_fields,SX_COUNT(sxdr_plist_string_fields),SX_LE};
static const xx_data_struct_field_desc sxdr_plist_integer_fields[] = {
    SX_FIELD("value","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxdr_plist_integer = {0x607f0022U,"plist_integer",sxdr_plist_integer_fields,SX_COUNT(sxdr_plist_integer_fields),SX_LE};
static const xx_data_struct_field_desc sxdr_plist_disk_size_fields[] = {
    SX_FIELD("disk_size","ascii_signed",0,0,SX_SIZE),
};
const sx_layout sxdr_plist_disk_size = {0x607f0023U,"plist_disk_size",sxdr_plist_disk_size_fields,SX_COUNT(sxdr_plist_disk_size_fields),SX_LE};
static const xx_data_struct_field_desc sxdr_plist_band_size_fields[] = {
    SX_FIELD("band_size","ascii_signed",0,0,SX_SIZE),
};
const sx_layout sxdr_plist_band_size = {0x607f0024U,"plist_band_size",sxdr_plist_band_size_fields,SX_COUNT(sxdr_plist_band_size_fields),SX_LE};
static const xx_data_struct_field_desc sxdr_plist_bundle_version_fields[] = {
    SX_FIELD("bundle_version","ascii_signed",0,0,SX_ID),
};
const sx_layout sxdr_plist_bundle_version = {0x607f0025U,"plist_bundle_version",sxdr_plist_bundle_version_fields,SX_COUNT(sxdr_plist_bundle_version_fields),SX_LE};
static bool sxdr_ws(uint8_t x){return x==' '||x=='\t'||x=='\n'||x=='\r';}
static bool sxdr_plist(sx_context*c){if(c->size<64||c->size>65536)return false;size_t n=(size_t)c->size,p=0,depth=0;uint8_t*b=xx_mem_alloc(n);if(!b)return false;bool ok=sxdr_read(c,0,b,n);char stack[68][64],key[40]={0};if(n>=3&&b[0]==0xef&&b[1]==0xbb&&b[2]==0xbf)p=3;
 while(ok&&p<n){if(xx_pd_is_stopped(c->pd)){ok=false;break;}if(b[p]!='<'){size_t a=p;while(p<n&&b[p]!='<')p++;size_t z=p;while(a<z&&sxdr_ws(b[a]))a++;while(z>a&&sxdr_ws(b[z-1]))z--;if(!depth||a==z)continue;const sx_layout*l=NULL;const char*t=stack[depth-1];if(!xx_rt_strcmp(t,"key")){l=&sxdr_plist_key;if(depth==3){size_t len=z-a;key[0]=0;if(len<sizeof(key)){xx_rt_memcpy(key,b+a,len);key[len]=0;}}}else if(!xx_rt_strcmp(t,"string"))l=&sxdr_plist_string;else if(!xx_rt_strcmp(t,"integer")){l=&sxdr_plist_integer;if(depth==3){if(!xx_rt_strcmp(key,"size"))l=&sxdr_plist_disk_size;else if(!xx_rt_strcmp(key,"band-size"))l=&sxdr_plist_band_size;else if(!xx_rt_strcmp(key,"bundle-backingstore-version"))l=&sxdr_plist_bundle_version;}}
 if(l&&!sxdr_text(c,l,a,z-a)){ok=false;break;}continue;}
 size_t a=p++;if(p<n&&(b[p]=='!'||b[p]=='?')){const char*end=b[p]=='?'?"?>":p+2<n&&b[p+1]=='-'&&b[p+2]=='-'?"-->":">";size_t len=xx_rt_strlen(end);while(p+len<=n&&xx_rt_memcmp(b+p,end,len))p++;if(p+len>n){ok=false;break;}p+=len;continue;}
 bool close=p<n&&b[p]=='/';if(close)p++;size_t start=p;while(p<n&&((b[p]>='a'&&b[p]<='z')||(b[p]>='A'&&b[p]<='Z')||(b[p]>='0'&&b[p]<='9')||b[p]=='-'||b[p]=='_'||b[p]=='.'||b[p]==':'))p++;size_t len=p-start;if(!len||len>=64){ok=false;break;}uint8_t quote=0;bool ended=false;for(;p<n;p++){uint8_t x=b[p];if(quote){if(x==quote)quote=0;}else if(x=='\''||x=='"')quote=x;else if(x=='>'){p++;ended=true;break;}else if(x=='<'){break;}}
 if(!ended){ok=false;break;}bool empty=p>=2&&b[p-2]=='/';if(!sxdr_text(c,&sxdr_plist_tag,a,p-a)){ok=false;break;}if(close){if(!depth||xx_rt_strlen(stack[depth-1])!=len||xx_rt_memcmp(stack[depth-1],b+start,len)){ok=false;break;}depth--;}else if(!empty){if(depth>=68){ok=false;break;}xx_rt_memcpy(stack[depth],b+start,len);stack[depth][len]=0;depth++;}}
 xx_mem_free(b);return !xx_pd_is_stopped(c->pd)&&!c->failed&&c->count!=0;}
bool sx_apple_sparse_bundle_build(sx_context*c)
{
 return sxdr_plist(c);
}
