/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The carriermeta schema family: what its family unit (xx_format_schema_carriermeta.c)
 * and its formats' data files share. Formats: sfx szdd; winimage zip. */
#ifndef XX_FORMAT_SCHEMA_CARRIERMETA_H
#define XX_FORMAT_SCHEMA_CARRIERMETA_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sx_cm_sfx_szdd_header;
extern const sx_layout sx_cm_sfx_szdd_legacy_header;
extern const sx_layout sx_cm_winimage_sfx_marker;
extern const sx_layout sx_cm_winimage_zip_local_header;
extern const sx_layout sx_cm_winimage_zip_central_header;
extern const sx_layout sx_cm_winimage_zip_end_record;
extern const sx_layout sx_cm_winimage_zip_extra_field;
bool sx_cm_span(sx_context*c,int64_t p,uint64_t n);
bool sx_cm_read(sx_context*c,int64_t p,void*b,size_t n);
bool sx_cm_add(sx_context*c,const sx_layout*l,int64_t p,int64_t z);
xx_archive_record_state *sx_cm_records(sx_context*c);

/* Per-format walkers, called by the family's build. */
bool sx_sfx_szdd_build(sx_context *c);  /* archive/sfx_szdd/xx_sfx_szdd_data.c */
bool sx_winimage_zip_build(sx_context *c);  /* filesystem/winimage_zip/xx_winimage_zip_data.c */

#endif
