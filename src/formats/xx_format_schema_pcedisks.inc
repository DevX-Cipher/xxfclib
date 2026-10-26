/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical PCE disk metadata; see docs/data_struct_pcedisks_scope.txt.
 * Encoded payloads and unwalked trees remain raw. */

static const xx_data_struct_field_desc sx_pc_pfdc_legacy_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version_major","uint16",4,2,SX_ID),
    SX_FIELD("version_minor","uint16",6,2,SX_ID),
    SX_FIELD("sector_count","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("sector_records_offset","uint32",12,4,SX_OFFSET),
};
static const sx_layout sx_pc_pfdc_legacy_header = {0x60140001U,"pfdc_legacy_header",sx_pc_pfdc_legacy_header_fields,SX_COUNT(sx_pc_pfdc_legacy_header_fields),SX_BE};

static const xx_data_struct_field_desc sx_pc_pfdc_v2_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version_major","uint16",4,2,SX_ID),
    SX_FIELD("version_minor","uint16",6,2,SX_ID),
    SX_FIELD("reserved","uint32",8,4,SX_RESERVED),
    SX_FIELD("chunks_offset","uint32",12,4,SX_OFFSET),
};
static const sx_layout sx_pc_pfdc_v2_header = {0x60140002U,"pfdc_v2_header",sx_pc_pfdc_v2_header_fields,SX_COUNT(sx_pc_pfdc_v2_header_fields),SX_BE};

static const xx_data_struct_field_desc sx_pc_pfdc_v0_sector_fields[] = {
    SX_FIELD("physical_cylinder","uint8",0,1,SX_ID),
    SX_FIELD("physical_head","uint8",1,1,SX_ID),
    SX_FIELD("logical_cylinder","uint8",2,1,SX_ID),
    SX_FIELD("logical_head","uint8",3,1,SX_ID),
    SX_FIELD("logical_sector","uint8",4,1,SX_ID),
    SX_FIELD("flags","uint8",5,1,SX_FLAGS),
    SX_FIELD("sector_size","uint16",6,2,SX_SIZE),
    SX_FIELD("data_rate","uint32",8,4,SX_NONE),
};
static const sx_layout sx_pc_pfdc_v0_sector = {0x60140003U,"pfdc_v0_sector",sx_pc_pfdc_v0_sector_fields,SX_COUNT(sx_pc_pfdc_v0_sector_fields),SX_BE};

static const xx_data_struct_field_desc sx_pc_pfdc_v1_sector_fields[] = {
    SX_FIELD("sector_marker","uint8",0,1,SX_SIGNATURE),
    SX_FIELD("physical_cylinder","uint8",1,1,SX_ID),
    SX_FIELD("physical_head","uint8",2,1,SX_ID),
    SX_FIELD("logical_cylinder","uint8",3,1,SX_ID),
    SX_FIELD("logical_head","uint8",4,1,SX_ID),
    SX_FIELD("logical_sector","uint8",5,1,SX_ID),
    SX_FIELD("sector_size","uint16",6,2,SX_SIZE),
    SX_FIELD("encoding","uint8",8,1,SX_ID),
    SX_FIELD("data_rate","uint24",9,3,SX_NONE),
    SX_FIELD("flags","uint32",12,4,SX_FLAGS),
};
static const sx_layout sx_pc_pfdc_v1_sector = {0x60140004U,"pfdc_v1_sector",sx_pc_pfdc_v1_sector_fields,SX_COUNT(sx_pc_pfdc_v1_sector_fields),SX_BE};

static const xx_data_struct_field_desc sx_pc_pfdc_v2_sector_fields[] = {
    SX_FIELD("flags","uint8",0,1,SX_FLAGS),
    SX_FIELD("physical_cylinder","uint8",1,1,SX_ID),
    SX_FIELD("physical_head","uint8",2,1,SX_ID),
    SX_FIELD("logical_cylinder","uint8",3,1,SX_ID),
    SX_FIELD("logical_head","uint8",4,1,SX_ID),
    SX_FIELD("logical_sector","uint8",5,1,SX_ID),
    SX_FIELD("sector_size","uint16",6,2,SX_SIZE),
    SX_FIELD("encoding","uint8",8,1,SX_ID),
    SX_FIELD("data_rate","uint24",9,3,SX_NONE),
};
static const sx_layout sx_pc_pfdc_v2_sector = {0x60140005U,"pfdc_v2_sector",sx_pc_pfdc_v2_sector_fields,SX_COUNT(sx_pc_pfdc_v2_sector_fields),SX_BE};

static const xx_data_struct_field_desc sx_pc_pfdc_v4_sector_fields[] = {
    SX_FIELD("physical_cylinder","uint16",0,2,SX_ID),
    SX_FIELD("physical_head","uint16",2,2,SX_ID),
    SX_FIELD("logical_cylinder","uint16",4,2,SX_ID),
    SX_FIELD("logical_head","uint16",6,2,SX_ID),
    SX_FIELD("logical_sector","uint16",8,2,SX_ID),
    SX_FIELD("sector_size","uint16",10,2,SX_SIZE),
    SX_FIELD("size_code_or_gcr_format","uint8",12,1,SX_ID),
    SX_FIELD("filler","uint8",13,1,SX_ID),
    SX_FIELD("flags","uint16",14,2,SX_FLAGS),
    SX_FIELD("encoding","uint16",16,2,SX_ID),
};
static const sx_layout sx_pc_pfdc_v4_sector = {0x60140006U,"pfdc_v4_sector",sx_pc_pfdc_v4_sector_fields,SX_COUNT(sx_pc_pfdc_v4_sector_fields),SX_BE};

static const xx_data_struct_field_desc sx_pc_pfdc_v2_chunk_fields[] = {
    SX_FIELD("chunk_id","char[2]",0,2,SX_ID),
    SX_FIELD("payload_size","uint16",2,2,SX_SIZE),
};
static const sx_layout sx_pc_pfdc_v2_chunk = {0x60140007U,"pfdc_v2_chunk",sx_pc_pfdc_v2_chunk_fields,SX_COUNT(sx_pc_pfdc_v2_chunk_fields),SX_BE};

static const xx_data_struct_field_desc sx_pc_pce_chunk_header_fields[] = {
    SX_FIELD("chunk_id","char[4]",0,4,SX_ID),
    SX_FIELD("payload_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sx_pc_pce_chunk_header = {0x60140008U,"pce_chunk_header",sx_pc_pce_chunk_header_fields,SX_COUNT(sx_pc_pce_chunk_header_fields),SX_BE};

static const xx_data_struct_field_desc sx_pc_pce_chunk_crc_fields[] = {
    SX_FIELD("crc32","uint32",0,4,SX_CHECKSUM),
};
static const sx_layout sx_pc_pce_chunk_crc = {0x60140009U,"pce_chunk_crc",sx_pc_pce_chunk_crc_fields,SX_COUNT(sx_pc_pce_chunk_crc_fields),SX_BE};

static const xx_data_struct_field_desc sx_pc_pfdc_file_crc_fields[] = {
    SX_FIELD("file_crc32","uint32",0,4,SX_CHECKSUM),
};
static const sx_layout sx_pc_pfdc_file_crc = {0x6014000aU,"pfdc_file_crc",sx_pc_pfdc_file_crc_fields,SX_COUNT(sx_pc_pfdc_file_crc_fields),SX_BE};

static const xx_data_struct_field_desc sx_pc_pce_version_fields[] = {
    SX_FIELD("version","uint32",0,4,SX_ID),
};
static const sx_layout sx_pc_pce_version = {0x6014000bU,"pce_version",sx_pc_pce_version_fields,SX_COUNT(sx_pc_pce_version_fields),SX_BE};

static const xx_data_struct_field_desc sx_pc_pfdc_version_fields[] = {
    SX_FIELD("version_major","uint16",0,2,SX_ID),
    SX_FIELD("version_minor","uint16",2,2,SX_ID),
};
static const sx_layout sx_pc_pfdc_version = {0x6014000cU,"pfdc_version",sx_pc_pfdc_version_fields,SX_COUNT(sx_pc_pfdc_version_fields),SX_BE};

static const xx_data_struct_field_desc sx_pc_pce_fill_byte_fields[] = {
    SX_FIELD("filler","uint8",0,1,SX_ID),
};
static const sx_layout sx_pc_pce_fill_byte = {0x6014000dU,"pce_fill_byte",sx_pc_pce_fill_byte_fields,SX_COUNT(sx_pc_pce_fill_byte_fields),SX_BE};

static const xx_data_struct_field_desc sx_pc_pri_track_fields[] = {
    SX_FIELD("cylinder","uint32",0,4,SX_ID),
    SX_FIELD("head","uint32",4,4,SX_ID),
    SX_FIELD("bit_count","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("clock_hz","uint32",12,4,SX_NONE),
};
static const sx_layout sx_pc_pri_track = {0x6014000eU,"pri_track",sx_pc_pri_track_fields,SX_COUNT(sx_pc_pri_track_fields),SX_BE};

static const xx_data_struct_field_desc sx_pc_pfi_track_fields[] = {
    SX_FIELD("cylinder","uint32",0,4,SX_ID),
    SX_FIELD("head","uint32",4,4,SX_ID),
    SX_FIELD("clock_hz","uint32",8,4,SX_NONE),
};
static const sx_layout sx_pc_pfi_track = {0x6014000fU,"pfi_track",sx_pc_pfi_track_fields,SX_COUNT(sx_pc_pfi_track_fields),SX_BE};

static const xx_data_struct_field_desc sx_pc_pfi_index_fields[] = {
    SX_FIELD("clock_position","uint32",0,4,SX_NONE),
};
static const sx_layout sx_pc_pfi_index = {0x60140010U,"pfi_index",sx_pc_pfi_index_fields,SX_COUNT(sx_pc_pfi_index_fields),SX_BE};

static const xx_data_struct_field_desc sx_pc_pbit_header_fields[] = {
    SX_FIELD("version","uint32",0,4,SX_ID),
    SX_FIELD("reserved","uint32",4,4,SX_RESERVED),
};
static const sx_layout sx_pc_pbit_header = {0x60140011U,"pbit_header",sx_pc_pbit_header_fields,SX_COUNT(sx_pc_pbit_header_fields),SX_BE};

static const xx_data_struct_field_desc sx_pc_pbit_track_fields[] = {
    SX_FIELD("cylinder","uint32",0,4,SX_ID),
    SX_FIELD("head","uint32",4,4,SX_ID),
    SX_FIELD("bit_count","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("clock_hz","uint32",12,4,SX_NONE),
    SX_FIELD("reserved","uint32",16,4,SX_RESERVED),
};
static const sx_layout sx_pc_pbit_track = {0x60140012U,"pbit_track",sx_pc_pbit_track_fields,SX_COUNT(sx_pc_pbit_track_fields),SX_BE};

static const xx_data_struct_field_desc sx_pc_psi_header_fields[] = {
    SX_FIELD("version","uint16",0,2,SX_ID),
    SX_FIELD("encoding","uint16",2,2,SX_ID),
};
static const sx_layout sx_pc_psi_header = {0x60140013U,"psi_header",sx_pc_psi_header_fields,SX_COUNT(sx_pc_psi_header_fields),SX_BE};

static const xx_data_struct_field_desc sx_pc_psi_sector_fields[] = {
    SX_FIELD("cylinder","uint16",0,2,SX_ID),
    SX_FIELD("head","uint8",2,1,SX_ID),
    SX_FIELD("sector","uint8",3,1,SX_ID),
    SX_FIELD("sector_size","uint16",4,2,SX_SIZE),
    SX_FIELD("flags","uint8",6,1,SX_FLAGS),
    SX_FIELD("filler","uint8",7,1,SX_ID),
};
static const sx_layout sx_pc_psi_sector = {0x60140014U,"psi_sector",sx_pc_psi_sector_fields,SX_COUNT(sx_pc_psi_sector_fields),SX_BE};

static const xx_data_struct_field_desc sx_pc_psi_ibm_sector_fields[] = {
    SX_FIELD("cylinder","uint8",0,1,SX_ID),
    SX_FIELD("head","uint8",1,1,SX_ID),
    SX_FIELD("sector","uint8",2,1,SX_ID),
    SX_FIELD("size_shift","uint8",3,1,SX_NONE),
    SX_FIELD("flags","uint8",4,1,SX_FLAGS),
    SX_FIELD("density","uint8",5,1,SX_ID),
};
static const sx_layout sx_pc_psi_ibm_sector = {0x60140015U,"psi_ibm_sector",sx_pc_psi_ibm_sector_fields,SX_COUNT(sx_pc_psi_ibm_sector_fields),SX_BE};

static const xx_data_struct_field_desc sx_pc_psi_bit_position_fields[] = {
    SX_FIELD("bit_position","uint32",0,4,SX_NONE),
};
static const sx_layout sx_pc_psi_bit_position = {0x60140016U,"psi_bit_position",sx_pc_psi_bit_position_fields,SX_COUNT(sx_pc_psi_bit_position_fields),SX_BE};

static const xx_data_struct_field_desc sx_pc_psi_read_time_fields[] = {
    SX_FIELD("bit_cell_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sx_pc_psi_read_time = {0x60140017U,"psi_read_time",sx_pc_psi_read_time_fields,SX_COUNT(sx_pc_psi_read_time_fields),SX_BE};

static const xx_data_struct_field_desc sx_pc_pbi_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",4,4,SX_ID),
    SX_FIELD("header_size","uint32",8,4,SX_SIZE),
    SX_FIELD("l1_index_bits","uint8",12,1,SX_NONE),
    SX_FIELD("l2_index_bits","uint8",13,1,SX_NONE),
    SX_FIELD("block_size_shift","uint8",14,1,SX_NONE),
    SX_FIELD("reserved","uint8",15,1,SX_RESERVED),
    SX_FIELD("image_size","uint64",16,8,SX_SIZE),
    SX_FIELD("l1_offset","uint64",24,8,SX_OFFSET),
    SX_FIELD("file_size","uint64",32,8,SX_SIZE),
};
static const sx_layout sx_pc_pbi_header = {0x60140018U,"pbi_header",sx_pc_pbi_header_fields,SX_COUNT(sx_pc_pbi_header_fields),SX_BE};

static const xx_data_struct_field_desc sx_pc_pbi_l1_entry_fields[] = {
    SX_FIELD("l2_offset","uint64",0,8,SX_OFFSET),
};
static const sx_layout sx_pc_pbi_l1_entry = {0x60140019U,"pbi_l1_entry",sx_pc_pbi_l1_entry_fields,SX_COUNT(sx_pc_pbi_l1_entry_fields),SX_BE};

static const xx_data_struct_field_desc sx_pc_pbi_l2_entry_fields[] = {
    SX_FIELD("data_offset","uint64",0,8,SX_OFFSET),
};
static const sx_layout sx_pc_pbi_l2_entry = {0x6014001aU,"pbi_l2_entry",sx_pc_pbi_l2_entry_fields,SX_COUNT(sx_pc_pbi_l2_entry_fields),SX_BE};

static const xx_data_struct_field_desc sx_pc_pbi_l2_fill_fields[] = {
    SX_FIELD("fill_pattern","uint32",0,4,SX_ID),
    SX_FIELD("flags","uint32",4,4,SX_FLAGS),
};
static const sx_layout sx_pc_pbi_l2_fill = {0x6014001bU,"pbi_l2_fill",sx_pc_pbi_l2_fill_fields,SX_COUNT(sx_pc_pbi_l2_fill_fields),SX_BE};

static const sx_layout *const sx_pcedisks_layouts[] = {
    &sx_pc_pfdc_legacy_header,
    &sx_pc_pfdc_v2_header,
    &sx_pc_pfdc_v0_sector,
    &sx_pc_pfdc_v1_sector,
    &sx_pc_pfdc_v2_sector,
    &sx_pc_pfdc_v4_sector,
    &sx_pc_pfdc_v2_chunk,
    &sx_pc_pce_chunk_header,
    &sx_pc_pce_chunk_crc,
    &sx_pc_pfdc_file_crc,
    &sx_pc_pce_version,
    &sx_pc_pfdc_version,
    &sx_pc_pce_fill_byte,
    &sx_pc_pri_track,
    &sx_pc_pfi_track,
    &sx_pc_pfi_index,
    &sx_pc_pbit_header,
    &sx_pc_pbit_track,
    &sx_pc_psi_header,
    &sx_pc_psi_sector,
    &sx_pc_psi_ibm_sector,
    &sx_pc_psi_bit_position,
    &sx_pc_psi_read_time,
    &sx_pc_pbi_header,
    &sx_pc_pbi_l1_entry,
    &sx_pc_pbi_l2_entry,
    &sx_pc_pbi_l2_fill,
};

static bool sx_pcedisks_supports(xx_file_type_t type)
{
    switch(type) {
    case XX_FILE_TYPE_PCE_PFDC_V0:case XX_FILE_TYPE_PCE_PFDC_V1:case XX_FILE_TYPE_PCE_PFDC_V2:case XX_FILE_TYPE_PCE_PFDC_V4:
    case XX_FILE_TYPE_PCE_PRI:case XX_FILE_TYPE_PCE_PFI:case XX_FILE_TYPE_PCE_PSI:case XX_FILE_TYPE_PCE_PBIT:case XX_FILE_TYPE_PCE_PBI:return true;
    default:return false;
    }
}
static bool sx_pc_span(sx_context *c,uint64_t at,uint64_t n)
{
    return at<=(uint64_t)c->size&&n<=(uint64_t)c->size-at;
}
static bool sx_pc_free(sx_context *c,uint64_t at,uint64_t n)
{
    if(!sx_pc_span(c,at,n)||c->count>=50000)return false;
    for(size_t i=0;i<c->count;i++) {
        uint64_t o=(uint64_t)(c->items[i].offset-c->f->base_address),z=(uint64_t)c->items[i].total_size;
        if(at<o+z&&o<at+n)return false;
    }
    return true;
}
static void sx_pc_sort(sx_context *c)
{
    for(size_t gap=c->count/2;gap;gap/=2)for(size_t i=gap;i<c->count;i++) {
        xx_data_struct d=c->items[i];size_t j=i;
        while(j>=gap&&c->items[j-gap].offset>d.offset){c->items[j]=c->items[j-gap];j-=gap;}
        c->items[j]=d;
    }
}
static bool sx_pc_finish(sx_context *c)
{
    size_t n=c->count;int64_t end=0;sx_pc_sort(c);
    for(size_t i=0;i<n;i++) {
        int64_t at=c->items[i].offset-c->f->base_address;
        if(at<end||(at>end&&!sx_raw(c,end,at-end)))return false;
        end=at+c->items[i].total_size;
    }
    if(end<c->size&&!sx_raw(c,end,c->size-end))return false;
    sx_pc_sort(c);return !c->failed;
}
static bool sx_pc_legacy(sx_context *c,unsigned version)
{
    uint32_t count,offset;
    if(!sx_u32(c,8,true,&count)||!sx_u32(c,12,true,&offset)||!count||count>4096||offset<16||!sx_add(c,&sx_pc_pfdc_legacy_header,0,16))return false;
    uint64_t at=offset;
    for(uint32_t i=0;i<count;i++) {
        uint8_t b[16];uint32_t h=version?16:12;
        if(!sx_pc_span(c,at,h)||!sx_read(c,(int64_t)at,b,h))return false;
        uint32_t flags=version?xx_data_get_u32(b,h,12,true):b[5],size=xx_data_get_u16(b,h,6,true),stored=(flags&0x80U)?1:size;
        if(!sx_pc_span(c,at+h,stored)||!sx_add(c,version?&sx_pc_pfdc_v1_sector:&sx_pc_pfdc_v0_sector,(int64_t)at,h))return false;
        if((flags&0x80U)&&!sx_add(c,&sx_pc_pce_fill_byte,(int64_t)(at+h),1))return false;
        at+=h+stored;
    }
    return at==(uint64_t)c->size;
}
static bool sx_pc_v2(sx_context *c)
{
    uint32_t offset;if(c->size<28||!sx_u32(c,12,true,&offset)||offset<16||!sx_add(c,&sx_pc_pfdc_v2_header,0,16))return false;
    uint64_t at=offset,end=(uint64_t)c->size-4;
    for(unsigned n=0;n<8192&&at<end;n++) {
        uint8_t b[4];if(at>end||end-at<8||!sx_read(c,(int64_t)at,b,4))return false;
        uint32_t size=xx_data_get_u16(b,4,2,true);if(size>end-at-8)return false;
        if(!sx_add(c,&sx_pc_pfdc_v2_chunk,(int64_t)at,4)||!sx_add(c,&sx_pc_pce_chunk_crc,(int64_t)(at+4+size),4))return false;
        if(b[0]=='S'&&b[1]=='C') {
            uint8_t h[12];if(size<12||!sx_read(c,(int64_t)at+4,h,12)||!sx_add(c,&sx_pc_pfdc_v2_sector,(int64_t)at+4,12))return false;
            if(h[0]&0x80U)if(size<13||!sx_add(c,&sx_pc_pce_fill_byte,(int64_t)at+16,1))return false;
        }
        at+=size+8;
    }
    return at==end&&sx_add(c,&sx_pc_pfdc_file_crc,(int64_t)end,4);
}
static bool sx_pc_chunks(sx_context *c)
{
    uint64_t at=0;xx_file_type_t type=c->f->file_type;
    for(unsigned n=0;n<8192&&at<(uint64_t)c->size;n++) {
        uint8_t h[8];if(!sx_pc_span(c,at,12)||!sx_read(c,(int64_t)at,h,8))return false;
        uint32_t size=xx_data_get_u32(h,8,4,true);uint64_t q=at+8;const sx_layout *l=NULL;uint32_t z=0;
        if(!sx_pc_span(c,q,(uint64_t)size+4)||!sx_add(c,&sx_pc_pce_chunk_header,(int64_t)at,8)||!sx_add(c,&sx_pc_pce_chunk_crc,(int64_t)(q+size),4))return false;
        if(at==0) {
            if(type==XX_FILE_TYPE_PCE_PBIT){l=&sx_pc_pbit_header;z=8;}
            else if(type==XX_FILE_TYPE_PCE_PSI){l=&sx_pc_psi_header;z=4;}
            else if(type==XX_FILE_TYPE_PCE_PFDC_V4){l=&sx_pc_pfdc_version;z=4;}
            else {l=&sx_pc_pce_version;z=4;}
        } else if(!xx_rt_memcmp(h,"SECT",4)) {
            if(type==XX_FILE_TYPE_PCE_PFDC_V4){l=&sx_pc_pfdc_v4_sector;z=18;}
            else if(type==XX_FILE_TYPE_PCE_PSI){l=&sx_pc_psi_sector;z=8;}
        } else if(!xx_rt_memcmp(h,"TRAK",4)) {
            if(type==XX_FILE_TYPE_PCE_PRI){l=&sx_pc_pri_track;z=16;}
            else if(type==XX_FILE_TYPE_PCE_PFI){l=&sx_pc_pfi_track;z=12;}
            else if(type==XX_FILE_TYPE_PCE_PBIT){l=&sx_pc_pbit_track;z=20;}
        } else if(type==XX_FILE_TYPE_PCE_PFI&&!xx_rt_memcmp(h,"INDX",4)) {
            if(size%4||size/4>4096)return false;
            if(size&&!sx_table(c,&sx_pc_pfi_index,(int64_t)q,4,size/4))return false;
        } else if(type==XX_FILE_TYPE_PCE_PSI) {
            if(!xx_rt_memcmp(h,"IBMF",4)||!xx_rt_memcmp(h,"IBMM",4)){l=&sx_pc_psi_ibm_sector;z=6;}
            else if(!xx_rt_memcmp(h,"OFFS",4)){l=&sx_pc_psi_bit_position;z=4;}
            else if(!xx_rt_memcmp(h,"TIME",4)){l=&sx_pc_psi_read_time;z=4;}
        }
        if(l&&(size<z||!sx_add(c,l,(int64_t)q,z)))return false;
        at=q+size+4;
    }
    return at==(uint64_t)c->size;
}
static bool sx_pc_pbi(sx_context *c)
{
    uint8_t b[48];uint64_t header=0;
    if(!sx_read(c,0,b,sizeof(b)))return false;
    if(!xx_rt_memcmp(b,"PBIn",4)) {
        if(b[14]<9||b[14]>24||(uint64_t)c->size<(UINT64_C(1)<<b[14]))return false;
        header=(uint64_t)c->size-(UINT64_C(1)<<b[14]);
        if(header<48||!sx_read(c,(int64_t)header,b,sizeof(b))||!sx_add(c,&sx_pc_pbi_header,0,40))return false;
    }
    if(xx_rt_memcmp(b,"PBI ",4)||b[12]>24||b[13]>24||b[14]<9||b[14]>24||!sx_add(c,&sx_pc_pbi_header,(int64_t)header,40))return false;
    uint64_t at=xx_data_get_u64(b,48,24,true),n=UINT64_C(1)<<b[12],m=UINT64_C(1)<<b[13],volume=xx_data_get_u64(b,48,16,true),block=UINT64_C(1)<<b[14];
    if(n>4096)n=4096;
    if(!sx_pc_free(c,at,n*8))return true;
    if(!sx_table(c,&sx_pc_pbi_l1_entry,(int64_t)at,8,n))return false;
    uint64_t blocks=volume/block+(volume%block!=0),needed=blocks/m+(blocks%m!=0);if(n>needed)n=needed;
    for(uint64_t i=0;i<n;i++) {
        uint64_t ptr;if(!sx_u64(c,(int64_t)(at+i*8),true,&ptr))return false;
        uint64_t entries=m;if(entries>4096)entries=4096;
        if(!ptr||!sx_pc_free(c,ptr,entries*8))continue;
        for(uint64_t j=0;j<entries;j++) {
            uint64_t value;if(!sx_u64(c,(int64_t)(ptr+j*8),true,&value))return false;
            if(c->count>=50000)return true;
            if(!sx_add(c,value&2U?&sx_pc_pbi_l2_fill:&sx_pc_pbi_l2_entry,(int64_t)(ptr+j*8),8))return false;
        }
    }
    return true;
}
static bool sx_pcedisks_build(sx_context *c)
{
    if(!c||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;
    bool ok;
    switch(c->f->file_type) {
    case XX_FILE_TYPE_PCE_PFDC_V0:ok=sx_pc_legacy(c,0);break;
    case XX_FILE_TYPE_PCE_PFDC_V1:ok=sx_pc_legacy(c,1);break;
    case XX_FILE_TYPE_PCE_PFDC_V2:ok=sx_pc_v2(c);break;
    case XX_FILE_TYPE_PCE_PBI:ok=sx_pc_pbi(c);break;
    default:ok=sx_pc_chunks(c);break;
    }
    return ok&&sx_pc_finish(c);
}
typedef struct sx_pc_flag {uint64_t mask;const wchar_t *name;} sx_pc_flag;
static bool sx_pc_flags(xx_data_struct_record *r,const sx_pc_flag *flags,size_t count)
{
    wchar_t out[256];size_t used=0;uint64_t value=xx_var_get_u64(&r->value),known=0;
    for(size_t i=0;i<count;i++) {
        known|=flags[i].mask;if(!(value&flags[i].mask))continue;
        if(used+32>=SX_COUNT(out))return false;
        if(used)out[used++]=L'|';
        const wchar_t *p=flags[i].name;while(*p&&used+24<SX_COUNT(out))out[used++]=*p++;
        if(*p)return false;
    }
    uint64_t unknown=value&~known;
    if(unknown) {
        if(used)out[used++]=L'|';out[used++]=L'0';out[used++]=L'x';
        bool started=false;
        for(int shift=60;shift>=0;shift-=4) {unsigned digit=(unsigned)((unknown>>shift)&15);if(digit||started||!shift){out[used++]=L"0123456789ABCDEF"[digit];started=true;}}
    }
    if(!used)out[used++]=L'0';out[used]=0;
    return xx_data_struct_record_set_comment(r,out);
}
static bool sx_pcedisks_comment(xx_data_struct_record *r,uint32_t id)
{
    if(!r||!r->name||id<0x60140000U||id>=0x60150000U)return true;
    const wchar_t *name=r->name,*comment=NULL;
    if(!xx_rt_wcscmp(name,L"flags")) {
        static const sx_pc_flag v0[]={{1,L"FM"},{2,L"MFM"},{4,L"CRC_ID"},{8,L"CRC_DATA"},{16,L"DEL_DAM"},{128,L"COMPRESSED"}};
        static const sx_pc_flag v1[]={{1,L"ALTERNATE"},{4,L"CRC_ID"},{8,L"CRC_DATA"},{16,L"DEL_DAM"},{128,L"COMPRESSED"}};
        static const sx_pc_flag v2[]={{1,L"CRC_ID"},{2,L"CRC_DATA"},{4,L"DEL_DAM"},{8,L"NO_DAM"},{64,L"ALTERNATE"},{128,L"COMPRESSED"}};
        static const sx_pc_flag v4[]={{1,L"CRC_ID"},{2,L"CRC_DATA"},{4,L"DEL_DAM"},{8,L"NO_DAM"},{0x4000,L"ALTERNATE"},{0x8000,L"COMPRESSED"}};
        static const sx_pc_flag psi[]={{1,L"COMPRESSED"},{2,L"ALTERNATE"},{4,L"CRC_DATA"}};
        static const sx_pc_flag ibm[]={{1,L"CRC_ID"},{2,L"CRC_DATA"},{4,L"DEL_DAM"},{8,L"NO_DAM"}};
        static const sx_pc_flag pbi[]={{2,L"FILL"}};
        if(id==sx_pc_pfdc_v0_sector.id)return sx_pc_flags(r,v0,SX_COUNT(v0));
        if(id==sx_pc_pfdc_v1_sector.id)return sx_pc_flags(r,v1,SX_COUNT(v1));
        if(id==sx_pc_pfdc_v2_sector.id)return sx_pc_flags(r,v2,SX_COUNT(v2));
        if(id==sx_pc_pfdc_v4_sector.id)return sx_pc_flags(r,v4,SX_COUNT(v4));
        if(id==sx_pc_psi_sector.id)return sx_pc_flags(r,psi,SX_COUNT(psi));
        if(id==sx_pc_psi_ibm_sector.id)return sx_pc_flags(r,ibm,SX_COUNT(ibm));
        if(id==sx_pc_pbi_l2_fill.id)return sx_pc_flags(r,pbi,SX_COUNT(pbi));
    }
    if(!xx_rt_wcscmp(name,L"data_rate"))comment=L"Bits per second";
    else if(!xx_rt_wcscmp(name,L"clock_hz"))comment=L"Clock frequency in Hz";
    else if(!xx_rt_wcscmp(name,L"clock_position"))comment=L"Original index position in track clock ticks; not sorted or deduplicated";
    else if(!xx_rt_wcscmp(name,L"bit_count"))comment=L"Stored track length in bits; final byte may contain padding";
    else if(!xx_rt_wcscmp(name,L"bit_position"))comment=L"Bit position in the track; not a byte offset";
    else if(!xx_rt_wcscmp(name,L"bit_cell_count"))comment=L"Sector read time in bit cells";
    else if(!xx_rt_wcscmp(name,L"size_shift"))comment=L"Decoded sector byte size is 128 << value";
    else if(!xx_rt_wcscmp(name,L"size_code_or_gcr_format"))comment=L"FM/MFM: encoded size; GCR: format byte, selected by encoding";
    else if(!xx_rt_wcscmp(name,L"filler"))comment=L"Byte repeated when the compressed-sector flag is set; no virtual expanded bytes are assigned physical offsets";
    else if(!xx_rt_wcscmp(name,L"crc32"))comment=L"CRC of stored chunk header and payload, excluding this checksum";
    else if(!xx_rt_wcscmp(name,L"file_crc32"))comment=L"PFDC2 CRC of all preceding file bytes (initial remainder 0xFFFFFFFF)";
    else if(!xx_rt_wcscmp(name,L"l1_index_bits")||!xx_rt_wcscmp(name,L"l2_index_bits"))comment=L"Table entry count = 1 << value";
    else if(!xx_rt_wcscmp(name,L"block_size_shift"))comment=L"Block size in bytes = 1 << value";
    else if(!xx_rt_wcscmp(name,L"l2_offset")||!xx_rt_wcscmp(name,L"data_offset"))comment=L"Physical file byte offset; zero represents an unallocated zero-filled region";
    else if(id==sx_pc_pbi_l2_fill.id)comment=L"Fill entry: high 32 bits hold the repeated byte pattern; low word is 2";
    else if(!xx_rt_wcscmp(name,L"encoding")) {
        uint64_t v=xx_var_get_u64(&r->value);
        if(id==sx_pc_pfdc_v1_sector.id||id==sx_pc_pfdc_v2_sector.id) {
            switch(v){case 0:comment=L"UNKNOWN";break;case 1:comment=L"FM";break;case 2:comment=L"MFM";break;case 3:if(id==sx_pc_pfdc_v2_sector.id)comment=L"GCR";break;default:break;}
        } else if(id==sx_pc_pfdc_v4_sector.id) {
            switch(v){case 0:comment=L"UNKNOWN";break;case 1:comment=L"FM_DD";break;case 0x8001:comment=L"FM_HD";break;case 2:comment=L"MFM_DD";break;case 0x8002:comment=L"MFM_HD";break;case 0x4002:comment=L"MFM_ED";break;case 3:comment=L"GCR";break;default:break;}
        } else switch(v){case 0:comment=L"UNKNOWN";break;case 0x100:comment=L"FM_DD";break;case 0x101:comment=L"FM_HD";break;case 0x200:comment=L"MFM_DD";break;case 0x201:comment=L"MFM_HD";break;case 0x202:comment=L"MFM_ED";break;case 0x300:comment=L"GCR";break;default:break;}
    }
    return !comment||xx_data_struct_record_set_comment(r,comment);
}
