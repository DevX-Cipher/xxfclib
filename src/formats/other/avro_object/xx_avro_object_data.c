/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * avro object data structures, moved out of the binarylater schema family. */
#include "../../xx_format_schema_binarylater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxbl_avro_magic_fields[] = {
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
};
const sx_layout sxbl_avro_magic = {UINT32_C(0x603500f8),"avro_magic",sxbl_avro_magic_fields,SX_COUNT(sxbl_avro_magic_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_avro_sync_fields[] = {
 SX_FIELD("sync_marker","uint8[16]",0,16,SX_SIGNATURE),
};
const sx_layout sxbl_avro_sync = {UINT32_C(0x603500f9),"avro_sync",sxbl_avro_sync_fields,SX_COUNT(sxbl_avro_sync_fields),SX_LE};
#define SXBL_LIMIT 20000U
static bool sxbl_avro_long(sx_context*c,uint64_t*p,uint64_t end,unsigned role,int64_t*out){uint64_t u;if(!sxbl_var(c,p,end,role,&u))return false;*out=(u&1)?-(int64_t)(u>>1)-1:(int64_t)(u>>1);return true;}
static bool sxbl_avro(sx_context*c){uint64_t p=0,end=(uint64_t)c->size;int64_t n,z;if(!sxbl_emit(c,&p,end,&sxbl_avro_magic))return false;for(unsigned b=0;b<1024;b++){if(!sxbl_avro_long(c,&p,end,1,&n))return false;if(!n)break;if(n==INT64_MIN)return false;if(n<0){n=-n;if(!sxbl_avro_long(c,&p,end,0,&z)||z<0||(uint64_t)z>end-p)return false;}if(n>1024)return false;for(int64_t i=0;i<n;i++)for(unsigned j=0;j<2;j++)if(!sxbl_avro_long(c,&p,end,0,&z)||z<0||!sxbl_skip(c,&p,end,(uint64_t)z))return false;}
 if(!sxbl_emit(c,&p,end,&sxbl_avro_sync))return false;for(unsigned i=0;p<end&&i<SXBL_LIMIT;i++)if(!sxbl_avro_long(c,&p,end,1,&n)||n<=0||!sxbl_avro_long(c,&p,end,0,&z)||z<0||!sxbl_skip(c,&p,end,(uint64_t)z)||!sxbl_emit(c,&p,end,&sxbl_avro_sync))return false;return p==end;}
bool sx_avro_object_build(sx_context*c)
{
 return sxbl_avro(c);
}
