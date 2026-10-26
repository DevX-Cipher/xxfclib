/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * QRST data structures, moved out of the systemlater schema family. */
#include "../../xx_format_schema_systemlater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsl_qrst_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","float32",4,4,SX_NONE),
    SX_FIELD("set_id","uint32",8,4,SX_ID),
    SX_FIELD("disk_type","uint8",12,1,SX_ID),
    SX_FIELD("disk_number","uint8",13,1,SX_NONE),
    SX_FIELD("disk_count","uint8",14,1,SX_COUNT_PROP),
    SX_FIELD("description_and_banner","char[781]",15,781,SX_NONE),
};
const sx_layout sxsl_qrst_header = {0x60330009U,"qrst_header",sxsl_qrst_header_fields,SX_COUNT(sxsl_qrst_header_fields),SX_LE};
static const xx_data_struct_field_desc sxsl_qrst_track_fields[] = {
    SX_FIELD("cylinder","uint8",0,1,SX_NONE),
    SX_FIELD("head","uint8",1,1,SX_NONE),
    SX_FIELD("method","uint8",2,1,SX_ID),
};
const sx_layout sxsl_qrst_track = {0x6033000aU,"qrst_track",sxsl_qrst_track_fields,SX_COUNT(sxsl_qrst_track_fields),SX_LE};
static const xx_data_struct_field_desc sxsl_qrst_fill_fields[] = {
    SX_FIELD("fill_value","uint8",0,1,SX_ID),
};
const sx_layout sxsl_qrst_fill = {0x6033000bU,"qrst_fill",sxsl_qrst_fill_fields,SX_COUNT(sxsl_qrst_fill_fields),SX_LE};
static const xx_data_struct_field_desc sxsl_qrst_encoded_size_fields[] = {
    SX_FIELD("encoded_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxsl_qrst_encoded_size = {0x6033000cU,"qrst_encoded_size",sxsl_qrst_encoded_size_fields,SX_COUNT(sxsl_qrst_encoded_size_fields),SX_LE};
#define SXSL_LIMIT 24000U
#define SXSL_ADD(c,l,p) sxsl_put(c,&sxsl_##l,p,1)
static bool sxsl_qrst(sx_context*c){uint64_t p=0;uint8_t h[15],b[5];for(unsigned image=0;image<128&&c->count<SXSL_LIMIT;image++){if(!sxsl_read(c,p,h,15)||xx_rt_memcmp(h,"QRST",4)||!sxsl_span(c,p,796))break;if(!SXSL_ADD(c,qrst_header,p))return false;if(sxsl32(h+4)!=0x3f800000||(h[12]!=3&&h[12]!=4))break;uint64_t track=h[12]==3?4608:9216;p+=796;bool ok=true;for(unsigned i=0;i<160;i++){if(!sxsl_read(c,p,b,3)){ok=false;break;}uint64_t data=b[2]==0?track:b[2]==1?1:0;if(b[2]==2){if(!sxsl_read(c,p,b,5)){ok=false;break;}data=2+sxsl16(b+3);}else if(b[2]>1){ok=false;break;}if(!sxsl_span(c,p+3,data)){ok=false;break;}if(!SXSL_ADD(c,qrst_track,p)||(b[2]==1&&!SXSL_ADD(c,qrst_fill,p+3))||(b[2]==2&&!SXSL_ADD(c,qrst_encoded_size,p+3)))return false;p+=3+data;}if(!ok)break;}return c->count>0;}
bool sx_qrst_build(sx_context*c)
{
bool ok=false;
ok=sxsl_qrst(c);
return ok&&sxsl_finish(c);
}
