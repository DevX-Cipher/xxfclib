/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * DIE MUSIC KAJAPON PROFESSIONALMD M data structures, moved out of the pcmusic schema family. */
#include "../../../xx_format_schema_pcmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#define SXPCM_LIMIT 24000U
#define SXPCM_ADD(c,n,p) sxpcm_put(c,&sxpcm_##n,p,1)
/* Strings have dynamic physical width but share a genuine string-field layout. */
static bool sxpcm_string(sx_context*c,uint64_t p){uint8_t ch;uint64_t n=0;while(n<4096&&sxpcm_u8(c,p+n,&ch)){n++;if(!ch){if(c->count>=SXPCM_LIMIT)return true;for(size_t i=0;i<c->count;i++){uint64_t a=(uint64_t)(c->items[i].offset-c->f->base_address),z=(uint64_t)c->items[i].total_size;if(p<a+z&&a<p+n)return true;}return sx_add(c,&sxpcm_pc_text,(int64_t)p,(int64_t)n);}}return true;}
static bool sxpcm_pmd(sx_context*c){
 uint16_t first,p;if(!sxpcm_u16(c,1,&first)||(first!=0x18&&first!=0x1a)||!SXPCM_ADD(c,pmd_header,0))return false;
 if(first!=0x1a)return true;
 if(!sxpcm_u16(c,25,&p)||!SXPCM_ADD(c,pmd_program_pointer,25))return true;
 if(p<4)return true;uint64_t q=(uint64_t)p-3;uint8_t m[4];
 if(!sxpcm_read(c,q,m,4)||(m[2]!=0x40&&(m[2]<0x41||m[3]!=0xfe)))return true;
 if(!SXPCM_ADD(c,pmd_memo_header,q))return false;
 q=1+(uint64_t)sxpcm16(m);uint64_t end=(uint64_t)c->size;
 /* Memo-list terminator and earliest string target bound the pointer table.
  * No decoded audio/event positions are assigned physical coordinates. */
 for(unsigned i=0;i<256&&q<=end&&end-q>=2;i++,q+=2){uint16_t off;if(!sxpcm_u16(c,q,&off)||!SXPCM_ADD(c,pmd_memo_pointer,q))return true;if(!off)break;
  uint64_t target=(uint64_t)off+1;if(target<=q+1||target>=(uint64_t)c->size)break;if(target<end)end=target;
  if(!sxpcm_string(c,target))return false;
 }return true;
}
bool sx_kajapon_professionalmd_m_build(sx_context*c)
{
 return sxpcm_pmd(c);
}
