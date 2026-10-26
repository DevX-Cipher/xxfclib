/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * nintendo sdat data structures, moved out of the extendedmedia schema family. */
#include "../../xx_format_schema_extendedmedia.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxem_sdat_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("byte_order","uint16",4,2,SX_SIGNATURE),
    SX_FIELD("version","uint16",6,2,SX_ID),
    SX_FIELD("file_size","uint32",8,4,SX_SIZE),
    SX_FIELD("header_size","uint16",12,2,SX_SIZE),
    SX_FIELD("block_count","uint16",14,2,SX_COUNT_PROP),
    SX_FIELD("symbol_offset","uint32",16,4,SX_OFFSET),
    SX_FIELD("symbol_block_size","uint32",20,4,SX_SIZE),
    SX_FIELD("info_offset","uint32",24,4,SX_OFFSET),
    SX_FIELD("info_block_size","uint32",28,4,SX_SIZE),
    SX_FIELD("fat_offset","uint32",32,4,SX_OFFSET),
    SX_FIELD("fat_block_size","uint32",36,4,SX_SIZE),
    SX_FIELD("file_offset","uint32",40,4,SX_OFFSET),
    SX_FIELD("file_block_size","uint32",44,4,SX_SIZE),
    SX_FIELD("reserved","uint8[16]",48,16,SX_RESERVED),
};
const sx_layout sxem_sdat_header = {UINT32_C(0x600D013A),"sdat_header",sxem_sdat_header_fields,SX_COUNT(sxem_sdat_header_fields),SX_LE};
static const xx_data_struct_field_desc sxem_nitro_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("byte_order","uint16",4,2,SX_SIGNATURE),
    SX_FIELD("version","uint16",6,2,SX_ID),
    SX_FIELD("file_size","uint32",8,4,SX_SIZE),
    SX_FIELD("header_size","uint16",12,2,SX_SIZE),
    SX_FIELD("block_count","uint16",14,2,SX_COUNT_PROP),
};
const sx_layout sxem_nitro_header = {UINT32_C(0x600D013B),"nitro_header",sxem_nitro_header_fields,SX_COUNT(sxem_nitro_header_fields),SX_LE};
static const xx_data_struct_field_desc sxem_sdat_directory_fields[] = {
    SX_FIELD("sequence_table_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("sequence_archive_table_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("bank_table_offset","uint32",8,4,SX_OFFSET),
    SX_FIELD("wave_archive_table_offset","uint32",12,4,SX_OFFSET),
    SX_FIELD("player_table_offset","uint32",16,4,SX_OFFSET),
    SX_FIELD("group_table_offset","uint32",20,4,SX_OFFSET),
    SX_FIELD("stream_player_table_offset","uint32",24,4,SX_OFFSET),
    SX_FIELD("stream_table_offset","uint32",28,4,SX_OFFSET),
};
const sx_layout sxem_sdat_directory = {UINT32_C(0x600D013C),"sdat_directory",sxem_sdat_directory_fields,SX_COUNT(sxem_sdat_directory_fields),SX_LE};
static const xx_data_struct_field_desc sxem_sdat_count_fields[] = {
    SX_FIELD("record_count","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxem_sdat_count = {UINT32_C(0x600D013D),"sdat_count",sxem_sdat_count_fields,SX_COUNT(sxem_sdat_count_fields),SX_LE};
static const xx_data_struct_field_desc sxem_sdat_offset_fields[] = {
    SX_FIELD("offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxem_sdat_offset = {UINT32_C(0x600D013E),"sdat_offset",sxem_sdat_offset_fields,SX_COUNT(sxem_sdat_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxem_sdat_archive_symbol_fields[] = {
    SX_FIELD("name_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("subtable_offset","uint32",4,4,SX_OFFSET),
};
const sx_layout sxem_sdat_archive_symbol = {UINT32_C(0x600D013F),"sdat_archive_symbol",sxem_sdat_archive_symbol_fields,SX_COUNT(sxem_sdat_archive_symbol_fields),SX_LE};
static const xx_data_struct_field_desc sxem_sdat_sequence_fields[] = {
    SX_FIELD("file_id","uint16",0,2,SX_ID),
    SX_FIELD("unknown_02","uint16",2,2,SX_NONE),
    SX_FIELD("bank_id","uint16",4,2,SX_ID),
    SX_FIELD("volume","uint8",6,1,SX_NONE),
    SX_FIELD("channel_priority","uint8",7,1,SX_NONE),
    SX_FIELD("player_priority","uint8",8,1,SX_NONE),
    SX_FIELD("player_id","uint8",9,1,SX_ID),
};
const sx_layout sxem_sdat_sequence = {UINT32_C(0x600D0140),"sdat_sequence",sxem_sdat_sequence_fields,SX_COUNT(sxem_sdat_sequence_fields),SX_LE};
static const xx_data_struct_field_desc sxem_sdat_file_reference_fields[] = {
    SX_FIELD("file_id","uint16",0,2,SX_ID),
    SX_FIELD("unknown_02","uint16",2,2,SX_NONE),
};
const sx_layout sxem_sdat_file_reference = {UINT32_C(0x600D0141),"sdat_file_reference",sxem_sdat_file_reference_fields,SX_COUNT(sxem_sdat_file_reference_fields),SX_LE};
static const xx_data_struct_field_desc sxem_sdat_bank_fields[] = {
    SX_FIELD("file_id","uint16",0,2,SX_ID),
    SX_FIELD("unknown_02","uint16",2,2,SX_NONE),
    SX_FIELD("wave_archive_id[0]","int16",4,2,SX_ID),
    SX_FIELD("wave_archive_id[1]","int16",6,2,SX_ID),
    SX_FIELD("wave_archive_id[2]","int16",8,2,SX_ID),
    SX_FIELD("wave_archive_id[3]","int16",10,2,SX_ID),
};
const sx_layout sxem_sdat_bank = {UINT32_C(0x600D0142),"sdat_bank",sxem_sdat_bank_fields,SX_COUNT(sxem_sdat_bank_fields),SX_LE};
static const xx_data_struct_field_desc sxem_sdat_player_fields[] = {
    SX_FIELD("max_sequences","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("channel_mask","uint16",2,2,SX_FLAGS),
    SX_FIELD("heap_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxem_sdat_player = {UINT32_C(0x600D0143),"sdat_player",sxem_sdat_player_fields,SX_COUNT(sxem_sdat_player_fields),SX_LE};
static const xx_data_struct_field_desc sxem_sdat_stream_player_fields[] = {
    SX_FIELD("channel_count","uint8",0,1,SX_COUNT_PROP),
    SX_FIELD("channel_ids","uint8[16]",1,16,SX_NONE),
};
const sx_layout sxem_sdat_stream_player = {UINT32_C(0x600D0145),"sdat_stream_player",sxem_sdat_stream_player_fields,SX_COUNT(sxem_sdat_stream_player_fields),SX_LE};
static const xx_data_struct_field_desc sxem_sdat_stream_fields[] = {
    SX_FIELD("file_id","uint16",0,2,SX_ID),
    SX_FIELD("unknown_02","uint16",2,2,SX_NONE),
    SX_FIELD("volume","uint8",4,1,SX_NONE),
    SX_FIELD("priority","uint8",5,1,SX_NONE),
    SX_FIELD("player_id","uint8",6,1,SX_ID),
    SX_FIELD("unknown_07","uint8",7,1,SX_NONE),
};
const sx_layout sxem_sdat_stream = {UINT32_C(0x600D0146),"sdat_stream",sxem_sdat_stream_fields,SX_COUNT(sxem_sdat_stream_fields),SX_LE};
static const xx_data_struct_field_desc sxem_sdat_fat_entry_fields[] = {
    SX_FIELD("file_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("file_size","uint32",4,4,SX_SIZE),
    SX_FIELD("reserved","uint8[8]",8,8,SX_RESERVED),
};
const sx_layout sxem_sdat_fat_entry = {UINT32_C(0x600D0147),"sdat_fat_entry",sxem_sdat_fat_entry_fields,SX_COUNT(sxem_sdat_fat_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxem_sdat_file_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_ID),
    SX_FIELD("block_size","uint32",4,4,SX_SIZE),
    SX_FIELD("file_count","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("reserved","uint8[12]",12,12,SX_RESERVED),
};
const sx_layout sxem_sdat_file_header = {UINT32_C(0x600D0148),"sdat_file_header",sxem_sdat_file_header_fields,SX_COUNT(sxem_sdat_file_header_fields),SX_LE};
#define EM_NEED(x) do{if(!(x))return false;}while(0)
#define EM_U16(p,b) xx_data_get_u16((p),2,0,(b))
#define EM_U32(p,b) xx_data_get_u32((p),4,0,(b))
static bool sxem_sdat_table(sx_context *c,uint64_t block,uint64_t size,uint32_t rel,bool archive,uint32_t *count)
{
    uint32_t n;uint64_t stride=archive?8:4;EM_NEED(rel>=40&&rel<=size&&4<=size-rel&&sxem_u32(c,block+rel,false,&n)&&n<=1024&&n<=(size-rel-4)/stride);
    EM_NEED(sxem_add(c,&sxem_sdat_count,block+rel,4)&&sxem_table(c,archive?&sxem_sdat_archive_symbol:&sxem_sdat_offset,block+rel+4,stride,n));*count=n;return true;
}
static bool sxem_sdat(sx_context *c)
{
    uint8_t h[64];uint32_t at[4],len[4],files,n,off;uint64_t total;unsigned work=0;
    const char *names[4]={"SYMB","INFO","FAT ","FILE"};
    static const sx_layout *const records[8]={&sxem_sdat_sequence,&sxem_sdat_file_reference,&sxem_sdat_bank,&sxem_sdat_file_reference,&sxem_sdat_player,&sxem_sdat_count,&sxem_sdat_stream_player,&sxem_sdat_stream};
    static const unsigned widths[8]={10,4,12,4,8,4,17,8};
    EM_NEED(sxem_read(c,0,h,64)&&!xx_rt_memcmp(h,"SDAT",4)&&EM_U16(h+4,false)==0xfeff&&sxem_add(c,&sxem_sdat_header,0,64));total=EM_U32(h+8,false);EM_NEED(total<=(uint64_t)c->size);
    for(unsigned i=0;i<4;i++){
        at[i]=EM_U32(h+16+8*i,false);len[i]=EM_U32(h+20+8*i,false);
        if(!at[i]){EM_NEED(i==0&&!len[i]);continue;}
        EM_NEED(at[i]>=64&&at[i]<=total&&len[i]>=8&&len[i]<=total-at[i]);
    }
    for(unsigned i=0;i<4;i++)if(at[i]){
        if(i==3){EM_NEED(len[i]>=24&&sxem_read(c,at[i],h,24)&&!xx_rt_memcmp(h,"FILE",4)&&EM_U32(h+4,false)==len[i]&&sxem_add(c,&sxem_sdat_file_header,at[i],24));}
        else EM_NEED(sxem_block(c,at[i],len[i],total,false,names[i]));
    }
    EM_NEED(len[1]>=40&&len[2]>=12&&sxem_u32(c,(uint64_t)at[2]+8,false,&files)&&files&&files<=1024&&files<=(len[2]-12)/16&&sxem_add(c,&sxem_sdat_count,(uint64_t)at[2]+8,4)&&sxem_table(c,&sxem_sdat_fat_entry,(uint64_t)at[2]+12,16,files));
    EM_NEED(sxem_add(c,&sxem_sdat_directory,(uint64_t)at[1]+8,32));
    for(unsigned k=0;k<8;k++){
        EM_NEED(sxem_u32(c,(uint64_t)at[1]+8+4*k,false,&off)&&sxem_sdat_table(c,at[1],len[1],off,false,&n));
        for(unsigned i=0;i<n;i++){
            uint32_t p;EM_NEED(++work<=65536&&sxem_u32(c,(uint64_t)at[1]+off+4+4*i,false,&p));if(!p)continue;
            EM_NEED(p>=40&&p<=len[1]&&widths[k]<=len[1]-p&&sxem_add(c,records[k],(uint64_t)at[1]+p,widths[k]));
            if(k==5){uint32_t count;EM_NEED(sxem_u32(c,(uint64_t)at[1]+p,false,&count)&&count<=1024&&count<=(len[1]-p-4)/8&&sxem_table(c,&sxem_sdat_group_entry,(uint64_t)at[1]+p+4,8,count));}
        }
    }
    if(at[0]){
        EM_NEED(len[0]>=40&&sxem_add(c,&sxem_sdat_directory,(uint64_t)at[0]+8,32));
        for(unsigned k=0;k<8;k++){
            EM_NEED(sxem_u32(c,(uint64_t)at[0]+8+4*k,false,&off));if(!off)continue;
            EM_NEED(sxem_sdat_table(c,at[0],len[0],off,k==1,&n));
            if(k==1)for(unsigned i=0;i<n;i++){uint32_t sub,cnt;EM_NEED(++work<=65536&&sxem_u32(c,(uint64_t)at[0]+off+8+8*i,false,&sub));if(sub)EM_NEED(sxem_sdat_table(c,at[0],len[0],sub,false,&cnt));}
        }
    }
    for(unsigned i=0;i<files;i++){
        uint32_t p,z,size,blocks;uint64_t pos,end;EM_NEED(++work<=65536&&sxem_read(c,(uint64_t)at[2]+12+16*i,h,16));p=EM_U32(h,false);z=EM_U32(h+4,false);
        EM_NEED(p>=(uint64_t)at[3]+24&&p<=(uint64_t)at[3]+len[3]&&z<=(uint64_t)at[3]+len[3]-p&&z>=16&&sxem_read(c,p,h,16));size=EM_U32(h+8,false);blocks=EM_U16(h+14,false);
        EM_NEED(size>=24&&size<=z&&blocks&&blocks<=3&&sxem_add(c,&sxem_nitro_header,p,16));pos=(uint64_t)p+16;end=(uint64_t)p+size;
        for(unsigned j=0;j<blocks;j++){uint32_t width;EM_NEED(end-pos>=8&&sxem_read(c,pos,h,8));width=EM_U32(h+4,false);EM_NEED(width>=8&&width<=end-pos&&sxem_add(c,&sxem_nw_block_le,pos,8));pos+=width;}EM_NEED(pos==end);
    }
    return true;
}
#undef EM_NEED
#undef EM_U16
#undef EM_U32
bool sx_nintendo_sdat_build(sx_context*c)
{
 return sxem_sdat(c);
}
