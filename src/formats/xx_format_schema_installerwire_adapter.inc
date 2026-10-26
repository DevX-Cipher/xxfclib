/* Included after sx_records. Only the authenticated Starkit carrier can expose outer bytes. */
#if SX_ALIAS_READER_FACTORY
#include "xxfclib/formats/executable/binsh_starkit/xx_binsh_starkit.h"
#endif
static xx_data_struct_record_state*sx_installerwire_records(Abstractformat*f,const xx_data_struct*d,xx_pd_struct*pd){
#if SX_ALIAS_READER_FACTORY
 if(f&&f->file_type==XX_FILE_TYPE_BINSH_STARKIT){int64_t base,size,inner;if(!d||!xx_binsh_starkit_get_container_span(f,&base,&size,&inner)||d->offset<base||d->total_size<0||d->offset-base>size||d->total_size>size-(d->offset-base))return NULL;Abstractformat view=*f;view.base_address=base;xx_data_struct_record_state*s=sx_records(&view,d,pd);if(s)s->format=f;return s;}
#endif
 return sx_records(f,d,pd);
}
