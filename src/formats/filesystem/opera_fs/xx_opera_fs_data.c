/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * OPERA FS data structures, moved out of the modernfs schema family. */
#include "../../xx_format_schema_modernfs.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmf_opera_disc_label_fields[] = {
    SX_FIELD("record_type","uint8",0,1,SX_ID),
    SX_FIELD("sync","char[5]",1,5,SX_SIGNATURE),
    SX_FIELD("record_version","uint8",6,1,SX_ID),
    SX_FIELD("volume_flags","uint8",7,1,SX_FLAGS),
    SX_FIELD("comment","char[32]",8,32,SX_STRING),
    SX_FIELD("label","char[32]",40,32,SX_STRING),
    SX_FIELD("volume_id","uint32",72,4,SX_ID),
    SX_FIELD("block_size","uint32",76,4,SX_SIZE),
    SX_FIELD("block_count","uint32",80,4,SX_COUNT_PROP),
    SX_FIELD("root_id","uint32",84,4,SX_ID),
    SX_FIELD("root_blocks","uint32",88,4,SX_COUNT_PROP),
    SX_FIELD("root_block_size","uint32",92,4,SX_SIZE),
    SX_FIELD("last_root_avatar_index","uint32",96,4,SX_NONE),
    SX_FIELD("root_avatars","uint32[8]",100,32,SX_NONE),
};
const sx_layout sxmf_opera_disc_label = {0x6042001cU,"opera_disc_label",sxmf_opera_disc_label_fields,SX_COUNT(sxmf_opera_disc_label_fields),SX_BE};
static const xx_data_struct_field_desc sxmf_opera_directory_header_fields[] = {
    SX_FIELD("next_block","int32",0,4,SX_NONE),
    SX_FIELD("previous_block","int32",4,4,SX_NONE),
    SX_FIELD("flags","uint32",8,4,SX_FLAGS),
    SX_FIELD("first_free","uint32",12,4,SX_OFFSET),
    SX_FIELD("first_used","uint32",16,4,SX_OFFSET),
};
const sx_layout sxmf_opera_directory_header = {0x6042001dU,"opera_directory_header",sxmf_opera_directory_header_fields,SX_COUNT(sxmf_opera_directory_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmf_opera_directory_record_fields[] = {
    SX_FIELD("flags","uint32",0,4,SX_FLAGS),
    SX_FIELD("id","uint32",4,4,SX_ID),
    SX_FIELD("type","char[4]",8,4,SX_ID),
    SX_FIELD("block_size","uint32",12,4,SX_SIZE),
    SX_FIELD("byte_count","uint32",16,4,SX_SIZE),
    SX_FIELD("block_count","uint32",20,4,SX_COUNT_PROP),
    SX_FIELD("burst_blocks","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("gap_blocks","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("name","char[32]",32,32,SX_STRING),
    SX_FIELD("last_avatar_index","uint32",64,4,SX_NONE),
};
const sx_layout sxmf_opera_directory_record = {0x6042001eU,"opera_directory_record",sxmf_opera_directory_record_fields,SX_COUNT(sxmf_opera_directory_record_fields),SX_BE};
static const xx_data_struct_field_desc sxmf_opera_avatar_fields[] = {
    SX_FIELD("block","uint32",0,4,SX_NONE),
};
const sx_layout sxmf_opera_avatar = {0x6042001fU,"opera_avatar",sxmf_opera_avatar_fields,SX_COUNT(sxmf_opera_avatar_fields),SX_BE};
#define SXMF_LIMIT 24000U
#define SXMF_ADD(c,l,p) sxmf_put(c,&sxmf_##l,p,1)
#define SXMF_TABLE(c,l,p,n) sxmf_put(c,&sxmf_##l,p,n)
typedef struct sxmf_op_task{uint64_t avatar,block,blocks,burst,gap;unsigned depth;}sxmf_op_task;
static bool sxmf_opera(sx_context*c){uint8_t h[132];if(!sxmf_read(c,0,h,132)||h[0]!=1||xx_rt_memcmp(h+1,"ZZZZZ",5)||!SXMF_ADD(c,opera_disc_label,0))return false;uint64_t volbs=sxmf32(h+76,1);if(!sxmf_pow(volbs)||volbs<512||volbs>65536)return true;sxmf_op_task*q=xx_rt_calloc(4096,sizeof(*q));uint8_t*b=xx_rt_malloc(65536);if(!q||!b){xx_rt_free(q);xx_rt_free(b);return false;}size_t count=1,index=0;bool ok=true;q[0]=(sxmf_op_task){sxmf32(h+100,1),sxmf32(h+92,1),sxmf32(h+88,1),0,0,0};
 while(ok&&index<count&&c->count<SXMF_LIMIT){sxmf_op_task t=q[index++];if(t.depth>32||!t.blocks||!sxmf_pow(t.block)||t.block<volbs||t.block>65536||(!t.burst&&t.gap))continue;uint64_t logical=0;for(uint64_t visit=0;visit<t.blocks&&visit<4096&&c->count<SXMF_LIMIT;visit++){if(logical>=t.blocks)break;uint64_t physical=logical;if(t.burst)physical+=(logical/t.burst)*t.gap;if(physical>UINT64_MAX/t.block||t.avatar>UINT64_MAX/volbs||physical*t.block>UINT64_MAX-t.avatar*volbs)break;uint64_t p=t.avatar*volbs+physical*t.block;if(!sxmf_read(c,p,b,(size_t)t.block))break;uint64_t first=sxmf32(b+16,1),free=sxmf32(b+12,1),next=sxmf32(b,1);if(first<20||first>free||free>t.block)break;if(!SXMF_ADD(c,opera_directory_header,p)){ok=false;break;}
   for(uint64_t at=first;at+68<=free;){uint64_t last=sxmf32(b+at+64,1),flags=sxmf32(b+at,1);if(last>255||last+1>(free-at-68)/4)break;if(!SXMF_ADD(c,opera_directory_record,p+at)||!SXMF_TABLE(c,opera_avatar,p+at+68,last+1)){ok=false;break;}if((flags&1)&&count<4096){sxmf_op_task child={sxmf32(b+at+68,1),sxmf32(b+at+12,1),sxmf32(b+at+20,1),sxmf32(b+at+24,1),sxmf32(b+at+28,1),t.depth+1};bool seen=false;for(size_t j=0;j<count;j++)if(q[j].avatar==child.avatar)seen=true;if(!seen)q[count++]=child;}at+=68+4*(last+1);if(flags&0xc0000000U)break;}
   if(!ok||next==UINT32_MAX)break;logical=next;
  }
 }xx_rt_free(q);xx_rt_free(b);return ok;
}
bool sx_opera_fs_build(sx_context*c)
{
 return sxmf_opera(c);
}
#undef SXMF_LIMIT
#undef SXMF_ADD
#undef SXMF_TABLE
