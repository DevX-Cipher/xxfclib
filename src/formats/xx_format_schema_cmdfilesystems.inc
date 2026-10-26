/* SPDX-License-Identifier: MIT. Physical CMD FD filesystem metadata. */
static const xx_data_struct_field_desc sxcmdfs_cmd_fd_system_header_fields[]={
 SX_FIELD("opaque_system_state","uint8[224]",0,224,SX_NONE),
 SX_FIELD("unknown_e0","uint8[2]",224,2,SX_NONE),
 SX_FIELD("default_partition","uint8",226,1,SX_NONE),
 SX_FIELD("default_partition_copy","uint8",227,1,SX_NONE),
 SX_FIELD("unknown_e4","uint8[12]",228,12,SX_NONE),
 SX_FIELD("signature","char[16]",240,16,SX_SIGNATURE),
};
static const sx_layout sxcmdfs_cmd_fd_system_header={0x609a0001U,"cmd_fd_system_header",sxcmdfs_cmd_fd_system_header_fields,SX_COUNT(sxcmdfs_cmd_fd_system_header_fields),SX_BE};
static const xx_data_struct_field_desc sxcmdfs_cmd_fd_partition_sector_link_fields[]={
 SX_FIELD("next_track","uint8",0,1,SX_NONE),
 SX_FIELD("next_sector","uint8",1,1,SX_NONE),
};
static const sx_layout sxcmdfs_cmd_fd_partition_sector_link={0x609a0002U,"cmd_fd_partition_sector_link",sxcmdfs_cmd_fd_partition_sector_link_fields,SX_COUNT(sxcmdfs_cmd_fd_partition_sector_link_fields),SX_BE};
static const xx_data_struct_field_desc sxcmdfs_cmd_fd_first_partition_fields[]={
 SX_FIELD("partition_type","uint8",0,1,SX_NONE),
 SX_FIELD("unknown_03","uint8[2]",1,2,SX_NONE),
 SX_FIELD("name_petscii","uint8[16]",3,16,SX_NONE),
 SX_FIELD("starting_lba","uint24",19,3,SX_OFFSET),
 SX_FIELD("unknown_18","uint8[5]",22,5,SX_NONE),
 SX_FIELD("length_lba","uint24",27,3,SX_SIZE),
};
static const sx_layout sxcmdfs_cmd_fd_first_partition={0x609a0003U,"cmd_fd_first_partition",sxcmdfs_cmd_fd_first_partition_fields,SX_COUNT(sxcmdfs_cmd_fd_first_partition_fields),SX_BE};
static const xx_data_struct_field_desc sxcmdfs_cmd_fd_partition_fields[]={
 SX_FIELD("unused_prefix","uint8[2]",0,2,SX_NONE),
 SX_FIELD("partition_type","uint8",2,1,SX_NONE),
 SX_FIELD("unknown_03","uint8[2]",3,2,SX_NONE),
 SX_FIELD("name_petscii","uint8[16]",5,16,SX_NONE),
 SX_FIELD("starting_lba","uint24",21,3,SX_OFFSET),
 SX_FIELD("unknown_18","uint8[5]",24,5,SX_NONE),
 SX_FIELD("length_lba","uint24",29,3,SX_SIZE),
};
static const sx_layout sxcmdfs_cmd_fd_partition={0x609a0004U,"cmd_fd_partition",sxcmdfs_cmd_fd_partition_fields,SX_COUNT(sxcmdfs_cmd_fd_partition_fields),SX_BE};
static const xx_data_struct_field_desc sxcmdfs_cmd_native_header_fields[]={
 SX_FIELD("directory_track","uint8",0,1,SX_NONE),
 SX_FIELD("directory_sector","uint8",1,1,SX_NONE),
 SX_FIELD("dos_version","char[1]",2,1,SX_NONE),
 SX_FIELD("reserved_03","uint8",3,1,SX_NONE),
 SX_FIELD("name_petscii","uint8[16]",4,16,SX_NONE),
 SX_FIELD("padding_14","uint8[2]",20,2,SX_NONE),
 SX_FIELD("disk_id","uint8[2]",22,2,SX_NONE),
 SX_FIELD("padding_18","uint8",24,1,SX_NONE),
 SX_FIELD("dos_type","char[2]",25,2,SX_NONE),
 SX_FIELD("padding_1b","uint8[2]",27,2,SX_NONE),
 SX_FIELD("reserved_1d","uint8[3]",29,3,SX_NONE),
 SX_FIELD("bam_track","uint8",32,1,SX_NONE),
 SX_FIELD("bam_sector","uint8",33,1,SX_NONE),
};
static const sx_layout sxcmdfs_cmd_native_header={0x609a0005U,"cmd_native_header",sxcmdfs_cmd_native_header_fields,SX_COUNT(sxcmdfs_cmd_native_header_fields),SX_BE};
static const xx_data_struct_field_desc sxcmdfs_cmd_native_bam_header_fields[]={
 SX_FIELD("unused_link","uint8[2]",0,2,SX_NONE),
 SX_FIELD("dos_version","char[1]",2,1,SX_NONE),
 SX_FIELD("dos_version_complement","uint8",3,1,SX_NONE),
 SX_FIELD("disk_id","uint8[2]",4,2,SX_NONE),
 SX_FIELD("flags","uint8",6,1,SX_FLAGS),
 SX_FIELD("reserved_07","uint8",7,1,SX_NONE),
 SX_FIELD("track_count","uint8",8,1,SX_COUNT_PROP),
};
static const sx_layout sxcmdfs_cmd_native_bam_header={0x609a0006U,"cmd_native_bam_header",sxcmdfs_cmd_native_bam_header_fields,SX_COUNT(sxcmdfs_cmd_native_bam_header_fields),SX_BE};
static const sx_layout*const sx_cmdfilesystems_layouts[]={&sxcmdfs_cmd_fd_system_header,&sxcmdfs_cmd_fd_partition_sector_link,&sxcmdfs_cmd_fd_first_partition,&sxcmdfs_cmd_fd_partition,&sxcmdfs_cmd_native_header,&sxcmdfs_cmd_native_bam_header};
static bool sx_cmdfilesystems_supports(xx_file_type_t type)
{switch(type){case XX_FILE_TYPE_CMD_D1M:case XX_FILE_TYPE_CMD_D2M:case XX_FILE_TYPE_CMD_D4M:return true;default:return false;}}
static bool sxcmdfs_span(sx_context*c,uint64_t p,uint64_t n)
{return c&&c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p&&!xx_pd_is_stopped(c->pd);}
static int sxcmdfs_compare(const void*a,const void*b)
{const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxcmdfs_finish(sx_context*c)
{
 size_t n=c->count;uint64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxcmdfs_compare);
 for(size_t i=0;i<n;i++){
  uint64_t at=(uint64_t)(c->items[i].offset-c->f->base_address),z=(uint64_t)c->items[i].total_size;
  if(at<end)return false;
  if(at>end&&!sx_raw(c,(int64_t)end,(int64_t)(at-end)))return false;
  end=at+z;
 }
 if(end<(uint64_t)c->size&&!sx_raw(c,(int64_t)end,c->size-(int64_t)end))return false;
 xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxcmdfs_compare);
 return !c->failed&&!xx_pd_is_stopped(c->pd);
}
static bool sx_cmdfilesystems_build(sx_context*c)
{
 uint64_t density,system,table,starts[31],lengths[31];size_t np=0;uint8_t h[256];
 if(!c||!c->f||!sx_cmdfilesystems_supports(c->f->file_type))return false;
 if((!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;
 density=c->f->file_type==XX_FILE_TYPE_CMD_D1M?1:c->f->file_type==XX_FILE_TYPE_CMD_D2M?2:4;
 if(c->size!=(int64_t)(density*829440))return false;
 system=density*819200;table=system+8*256;
 if(!sxcmdfs_span(c,system+5*256,256)||!sx_read(c,(int64_t)(system+5*256),h,256)||xx_rt_memcmp(h+240,"CMD FD SERIES   ",16))return false;
 if(!sx_add(c,&sxcmdfs_cmd_fd_system_header,(int64_t)(system+5*256),256))return false;
 for(unsigned sector=0;sector<4;sector++){
  uint64_t at=table+sector*256;
  if(!sxcmdfs_span(c,at,256)||!sx_read(c,(int64_t)at,h,256))return false;
  if(!sx_add(c,&sxcmdfs_cmd_fd_partition_sector_link,(int64_t)at,2)||!sx_add(c,&sxcmdfs_cmd_fd_first_partition,(int64_t)at+2,30)||!sx_table(c,&sxcmdfs_cmd_fd_partition,(int64_t)at+32,32,7))return false;
  for(unsigned j=0;j<8;j++){
   const uint8_t*q=h+j*32;uint64_t start=((uint64_t)q[21]<<16)|((uint64_t)q[22]<<8)|q[23],len=((uint64_t)q[29]<<16)|((uint64_t)q[30]<<8)|q[31];
   if((sector||j)&&q[2]==1&&len&&start<density*1600&&len<=density*1600-start){starts[np]=start*512;lengths[np++]=len*512;}
  }
 }
 /* A partition map can describe other DOSes or overlapping/inaccessible areas.
  * Expose its stored entries regardless; follow only disjoint native partitions
  * whose original physical header and BAM identifier agree. */
 for(size_t i=0;i<np;i++){
  uint64_t start=starts[i],len=lengths[i];bool overlap=false;
  for(size_t j=0;j<i;j++)if(start<starts[j]+lengths[j]&&starts[j]<start+len)overlap=true;
  if(overlap||len<521||!sxcmdfs_span(c,start+256,265))continue;
  uint8_t hd[34],bam[9];
  if(!sx_read(c,(int64_t)(start+256),hd,sizeof(hd))||!sx_read(c,(int64_t)(start+512),bam,sizeof(bam)))return false;
  if(hd[2]!='H'||hd[25]!='1'||hd[26]!='H'||bam[2]!='H'||bam[3]!=(uint8_t)~'H'||xx_rt_memcmp(hd+22,bam+4,2))continue;
  if(!sx_add(c,&sxcmdfs_cmd_native_header,(int64_t)start+256,34)||!sx_add(c,&sxcmdfs_cmd_native_bam_header,(int64_t)start+512,9))return false;
 }
 return sxcmdfs_finish(c);
}
static bool sx_cmdfilesystems_comment(xx_data_struct_record*r,uint32_t id)
{
 if(!r||!r->name||id<0x609a0001U||id>0x609a0006U)return true;
 if(!xx_rt_wcscmp(r->name,L"starting_lba"))return xx_data_struct_record_set_comment(r,L"Stored big-endian 24-bit start in 512-byte logical blocks. System partition entry stores zero; its computed physical origin is not substituted here.");
 if(!xx_rt_wcscmp(r->name,L"length_lba"))return xx_data_struct_record_set_comment(r,L"Stored big-endian 24-bit length in 512-byte logical blocks.");
 if(!xx_rt_wcscmp(r->name,L"name_petscii"))return xx_data_struct_record_set_comment(r,L"Original 16-byte PETSCII name, including A0 padding; retained as bytes without a lossy text conversion.");
 if(!xx_rt_wcscmp(r->name,L"default_partition")||!xx_rt_wcscmp(r->name,L"default_partition_copy"))return xx_data_struct_record_set_comment(r,L"Stored default partition number; VICE reads byte E2 and preserves its E3 copy.");
 if(r->value.type==XX_VAR_TYPE_FLOAT||r->value.type==XX_VAR_TYPE_DOUBLE)return true;
 if(!xx_rt_wcscmp(r->name,L"partition_type")){
  const wchar_t*t=L"Unknown or unavailable partition type";
  switch(xx_var_get_u64(&r->value)){case 0:t=L"Unused partition";break;case 1:t=L"CMD native partition";break;case 2:t=L"1541 emulation partition";break;case 3:t=L"1571 emulation partition";break;case 4:t=L"1581 emulation partition";break;case 255:t=L"System partition";break;}
  return xx_data_struct_record_set_comment(r,t);
 }
 return xx_data_struct_record_set_comment(r,L"Stored CMD FD filesystem metadata byte range. Geometry-derived values and decoded head-order positions are not inserted as members; unknown bytes remain opaque.");
}
