/* SPDX-License-Identifier: MIT
 * Included after sx_records. PSA's real reader retains the inner FAT base;
 * only this callback permits authenticated outer-container header fields. */
static xx_data_struct_record_state *sx_disknext_records(Abstractformat *f,const xx_data_struct*d,xx_pd_struct*pd)
{
#if SX_ALIAS_READER_FACTORY
 if(f&&f->file_type==XX_FILE_TYPE_PSA_DISK){
  int64_t base,size;if(!xx_psa_disk_get_container_span(f,&base,&size)||!d||d->offset<base||d->total_size<0||d->offset-base>size||d->total_size>size-(d->offset-base))return NULL;
  Abstractformat view=*f;view.base_address=base;
  xx_data_struct_record_state*s=sx_records(&view,d,pd);
  if(s)s->format=f; /* Future record-next uses the live original device. */
  return s;
 }
#endif
 return sx_records(f,d,pd);
}
