/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Bounded declarative on-disk schemas for readers without a native provider.
 * RAW_DATA remains explicitly unparsed. Each family supplies genuine layouts.
 */
#include "xx_format_schema.h"
#include "xxfclib/formats/xx_format_streams.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#include "xx_format_schema_variable_field.inc"

#define SX_MAX_ITEMS 100000U
static bool sx_range(sx_context *c, int64_t off, uint64_t n)
{
    if (!c || c->failed || off < 0 || off > c->size || n > (uint64_t)(c->size-off) || xx_pd_is_stopped(c->pd)) {
        if (c) c->failed = true;
        return false;
    }
    return true;
}
static bool sx_read(sx_context *c, int64_t off, void *out, size_t n)
{
    size_t done=0;
    if (!sx_range(c,off,n) || (!out && n)) return false;
    if (!n) return true;
    if (xx_io_seek64(c->f->device,c->f->base_address+off,SEEK_SET) != 0) { c->failed=true; return false; }
    while (done<n) {
        ssize_t got=xx_io_read(c->f->device,(uint8_t *)out+done,n-done);
        if (got<=0 || (size_t)got>n-done || xx_pd_is_stopped(c->pd)) { c->failed=true; return false; }
        done+=(size_t)got;
    }
    return true;
}
static bool sx_u16(sx_context *c,int64_t o,bool be,uint16_t *v) { uint8_t b[2]; if(!v||!sx_read(c,o,b,2))return false;*v=xx_data_get_u16(b,2,0,be);return true; }
static bool sx_u32(sx_context *c,int64_t o,bool be,uint32_t *v) { uint8_t b[4]; if(!v||!sx_read(c,o,b,4))return false;*v=xx_data_get_u32(b,4,0,be);return true; }
static bool sx_u64(sx_context *c,int64_t o,bool be,uint64_t *v) { uint8_t b[8]; if(!v||!sx_read(c,o,b,8))return false;*v=xx_data_get_u64(b,8,0,be);return true; }
static bool sx_push(sx_context *c,const sx_layout *l,int64_t off,int64_t entry,uint64_t count,bool raw)
{
    uint64_t total;
    xx_data_struct *d;
    if (entry<0 || (!raw && (!l || !l->fields || !l->field_count || entry==0))) return false;
    if (!count) return true;
    if ((uint64_t)entry>INT64_MAX/count) return false;
    total=(uint64_t)entry*count;
    if (!sx_range(c,off,total) || c->count>=SX_MAX_ITEMS) {c->failed=true;return false;}
    if (!raw) for(size_t i=0;i<l->field_count;i++) {
        xx_data_struct_field_desc field;wchar_t type[64];
        if(!sx_expand_field(l,i,entry,&field,type)) {c->failed=true;return false;}
    }
    if(c->count==c->capacity) {
        size_t cap=c->capacity?c->capacity*2:32;
        void *p;
        if(cap>SX_MAX_ITEMS)cap=SX_MAX_ITEMS;
        p=xx_mem_realloc(c->items,cap*sizeof(*c->items));
        if(!p){c->failed=true;return false;}
        c->items=p;c->capacity=cap;
    }
    d=&c->items[c->count++];
    xx_mem_zero(d,sizeof(*d));
    d->id=raw?XX_DATA_STRUCT_ID_RAW_DATA:l->id;
    d->offset=c->f->base_address+off; d->address=-1;
    d->entry_size=entry;d->total_size=(int64_t)total;d->count=count;
    d->type=raw?XX_DATA_STRUCT_TYPE_RAW_DATA:XX_DATA_STRUCT_TYPE_STRUCT;
    return true;
}
static bool sx_add(sx_context *c,const sx_layout *l,int64_t o,int64_t n) {return sx_push(c,l,o,n,1,false);}
static bool sx_table(sx_context *c,const sx_layout *l,int64_t o,int64_t n,uint64_t count) {return sx_push(c,l,o,n,count,false);}
static bool sx_raw(sx_context *c,int64_t o,int64_t n) {if(!n)return true;return sx_push(c,NULL,o,n,1,true);}

#include "xx_format_schema_alias.inc"
#include "xx_format_schema_image.inc"
#include "xx_format_schema_container.inc"
#include "xx_format_schema_executable.inc"
#include "xx_format_schema_archive.inc"
#include "xx_format_schema_volume.inc"
#include "xx_format_schema_media.inc"
#include "xx_format_schema_package.inc"
#include "xx_format_schema_storage.inc"
#include "xx_format_schema_binary.inc"
#include "xx_format_schema_bcmrange.inc"
#include "xx_format_schema_classicdata.inc"
#include "xx_format_schema_playerdata.inc"
#include "xx_format_schema_musicmaker.inc"
#include "xx_format_schema_codeplayers.inc"
#include "xx_format_schema_classicmusic.inc"
#include "xx_format_schema_logicsamples.inc"
#include "xx_format_schema_vintagefilesystems.inc"
#include "xx_format_schema_modvariants.inc"
#include "xx_format_schema_cmdfilesystems.inc"
#include "xx_format_schema_pcmusicmore.inc"
#include "xx_format_schema_musicfurther.inc"
#include "xx_format_schema_amigamore.inc"
#include "xx_format_schema_pcmusic.inc"
#include "xx_format_schema_musiclate.inc"
#include "xx_format_schema_amigaplayers.inc"
#include "xx_format_schema_chipmusic.inc"
#include "xx_format_schema_musicportable.inc"
#include "xx_format_schema_synthtail.inc"
#include "xx_format_schema_musiclogs.inc"
#include "xx_format_schema_nextmusic.inc"
#include "xx_format_schema_zxmusic.inc"
#include "xx_format_schema_musicwire.inc"
#include "xx_format_schema_executabletail.inc"
#include "xx_format_schema_firmwaretail.inc"
#include "xx_format_schema_installerlast.inc"
#include "xx_format_schema_archiveend.inc"
#include "xx_format_schema_archivelpaq.inc"
#include "xx_format_schema_musictail.inc"
#include "xx_format_schema_installerextras.inc"
#include "xx_format_schema_installerremaining.inc"
#include "xx_format_schema_diskremaining.inc"
#include "xx_format_schema_gameremaining.inc"
#include "xx_format_schema_musicremaining.inc"
#include "xx_format_schema_disktail.inc"
#include "xx_format_schema_musicprojects.inc"
#include "xx_format_schema_disknext.inc"
#include "xx_format_schema_archivenext.inc"
#include "xx_format_schema_musicnext.inc"
#include "xx_format_schema_documentwire.inc"
#include "xx_format_schema_archivepackages.inc"
#include "xx_format_schema_disklegacy.inc"
#include "xx_format_schema_sciencesequence.inc"
#include "xx_format_schema_textwire.inc"
#include "xx_format_schema_archiveobsolete.inc"
#include "xx_format_schema_sciencemesh.inc"
#include "xx_format_schema_retrofs.inc"
#include "xx_format_schema_archivetails.inc"
#include "xx_format_schema_vectortext.inc"
#include "xx_format_schema_sciencechem.inc"
#include "xx_format_schema_volumeimages.inc"
#include "xx_format_schema_archiveframes.inc"
#include "xx_format_schema_modeltext.inc"
#include "xx_format_schema_scienceascii.inc"
#include "xx_format_schema_archiveclassic.inc"
#include "xx_format_schema_archivesystems.inc"
#include "xx_format_schema_modernfs.inc"
#include "xx_format_schema_archivestreams.inc"
#include "xx_format_schema_textimages.inc"
#include "xx_format_schema_gamecontainers.inc"
#include "xx_format_schema_resourceextra.inc"
#include "xx_format_schema_binaryresources.inc"
#include "xx_format_schema_classicfs.inc"
#include "xx_format_schema_archivefinal.inc"
#include "xx_format_schema_gamearchives.inc"
#include "xx_format_schema_samplebanks.inc"
#include "xx_format_schema_videotail.inc"
#include "xx_format_schema_audiolater.inc"
#include "xx_format_schema_systemtail.inc"
#include "xx_format_schema_gameplatforms.inc"
#include "xx_format_schema_binarylater.inc"
#include "xx_format_schema_trackerextra.inc"
#include "xx_format_schema_systemlater.inc"
#include "xx_format_schema_nextmedia.inc"
#include "xx_format_schema_scientificextra.inc"
#include "xx_format_schema_binaryextra.inc"
#include "xx_format_schema_cfefirmware.inc"
#include "xx_format_schema_utagemedia.inc"
#include "xx_format_schema_panorama.inc"
#include "xx_format_schema_archivequad.inc"
#include "xx_format_schema_archiveresidual.inc"
#include "xx_format_schema_archivewire.inc"
#include "xx_format_schema_archivetransport.inc"
#include "xx_format_schema_archiveremaining.inc"
#include "xx_format_schema_installerwire.inc"
#include "xx_format_schema_systemextra.inc"
#include "xx_format_schema_mediaextra.inc"
#include "xx_format_schema_sciencewire.inc"
#include "xx_format_schema_executablemore.inc"
#include "xx_format_schema_audiomore.inc"
#include "xx_format_schema_diskmeta.inc"
#include "xx_format_schema_gamemeta.inc"
#include "xx_format_schema_networkmeta.inc"
#include "xx_format_schema_scienceheaders.inc"
#include "xx_format_schema_sciencemeta.inc"
#include "xx_format_schema_carriermeta.inc"
#include "xx_format_schema_archivelegacy.inc"
#include "xx_format_schema_docmeta.inc"
#include "xx_format_schema_firmwaremore.inc"
#include "xx_format_schema_archivelater.inc"
#include "xx_format_schema_modelmeta.inc"
#include "xx_format_schema_columnar.inc"
#include "xx_format_schema_firmwaremeta.inc"
#include "xx_format_schema_rastermore.inc"
#include "xx_format_schema_archivemore.inc"
#include "xx_format_schema_androidmeta.inc"
#include "xx_format_schema_databases.inc"
#include "xx_format_schema_fontbinary.inc"
#include "xx_format_schema_cowfs.inc"
#include "xx_format_schema_archiveextras.inc"
#include "xx_format_schema_vmmeta.inc"
#include "xx_format_schema_diskimages.inc"
#include "xx_format_schema_pcedisks.inc"
#include "xx_format_schema_opticalfs.inc"
#include "xx_format_schema_unixfs.inc"
#include "xx_format_schema_filesystems.inc"
#include "xx_format_schema_adlib.inc"
#include "xx_format_schema_tracker.inc"
#include "xx_format_schema_extendedmedia.inc"
#include "xx_format_schema_systems.inc"
#include "xx_format_schema_multimedia.inc"
#include "xx_format_schema_legacy.inc"
#include "xx_format_schema_cinemusic.inc"
#include "xx_format_schema_opllogs.inc"
#include "xx_format_schema_music37_amiga.inc"
#include "xx_format_schema_music37modern.inc"
#include "xx_format_schema_aeroace.inc"
#include "xx_format_schema_music38_amiga.inc"
#include "xx_format_schema_edlibsamples.inc"
#include "xx_format_schema_music38modern.inc"
#include "xx_format_schema_music39_amiga.inc"
#include "xx_format_schema_companiondata.inc"
#include "xx_format_schema_darkwave.inc"
#include "xx_format_schema_megastation.inc"
#include "xx_format_schema_field_endian.inc"


static const sx_layout *sx_lookup(Abstractformat *f,uint32_t id,const char *name)
{
    const sx_layout *const *rows=NULL;
    size_t n=0;
    xx_file_type_t type;
    if(!f)return NULL;
    type=sx_alias_canonical_type(f->file_type);
    if(sx_image_supports(type)){rows=sx_image_layouts;n=SX_COUNT(sx_image_layouts);}
    else if(sx_container_supports(type)){rows=sx_container_layouts;n=SX_COUNT(sx_container_layouts);}
    else if(sx_executable_supports(type)){rows=sx_executable_layouts;n=SX_COUNT(sx_executable_layouts);}
    else if(sx_archive_supports(type)){rows=sx_archive_layouts;n=SX_COUNT(sx_archive_layouts);}
    else if(sx_volume_supports(type)){rows=sx_volume_layouts;n=SX_COUNT(sx_volume_layouts);}
    else if(sx_media_supports(type)){rows=sx_media_layouts;n=SX_COUNT(sx_media_layouts);}
    else if(sx_package_supports(type)){rows=sx_package_layouts;n=SX_COUNT(sx_package_layouts);}
    else if(sx_storage_supports(type)){rows=sx_storage_layouts;n=SX_COUNT(sx_storage_layouts);}
    else if(sx_binary_supports(type)){rows=sx_binary_layouts;n=SX_COUNT(sx_binary_layouts);}
    else if(sx_legacy_supports(type)){rows=sx_legacy_layouts;n=SX_COUNT(sx_legacy_layouts);}
    else if(sx_multimedia_supports(type)){rows=sx_multimedia_layouts;n=SX_COUNT(sx_multimedia_layouts);}
    else if(sx_systems_supports(type)){rows=sx_systems_layouts;n=SX_COUNT(sx_systems_layouts);}
    else if(sx_extendedmedia_supports(type)){rows=sx_extendedmedia_layouts;n=SX_COUNT(sx_extendedmedia_layouts);}
    else if(sx_tracker_supports(type)){rows=sx_tracker_layouts;n=SX_COUNT(sx_tracker_layouts);}
    else if(sx_adlib_supports(type)){rows=sx_adlib_layouts;n=SX_COUNT(sx_adlib_layouts);}
    else if(sx_filesystems_supports(type)){rows=sx_filesystems_layouts;n=SX_COUNT(sx_filesystems_layouts);}
    else if(sx_unixfs_supports(type)){rows=sx_unixfs_layouts;n=SX_COUNT(sx_unixfs_layouts);}
    else if(sx_opticalfs_supports(type)){rows=sx_opticalfs_layouts;n=SX_COUNT(sx_opticalfs_layouts);}
    else if(sx_pcedisks_supports(type)){rows=sx_pcedisks_layouts;n=SX_COUNT(sx_pcedisks_layouts);}
    else if(sx_diskimages_supports(type)){rows=sx_diskimages_layouts;n=SX_COUNT(sx_diskimages_layouts);}
    else if(sx_vmmeta_supports(type)){rows=sx_vmmeta_layouts;n=SX_COUNT(sx_vmmeta_layouts);}
    else if(sx_archiveextras_supports(type)){rows=sx_archiveextras_layouts;n=SX_COUNT(sx_archiveextras_layouts);}
    else if(sx_cowfs_supports(type)){rows=sx_cowfs_layouts;n=SX_COUNT(sx_cowfs_layouts);}
    else if(sx_fontbinary_supports(type)){rows=sx_fontbinary_layouts;n=SX_COUNT(sx_fontbinary_layouts);}
    else if(sx_databases_supports(type)){rows=sx_databases_layouts;n=SX_COUNT(sx_databases_layouts);}
    else if(sx_androidmeta_supports(type)){rows=sx_androidmeta_layouts;n=SX_COUNT(sx_androidmeta_layouts);}
    else if(sx_archivemore_supports(type)){rows=sx_archivemore_layouts;n=SX_COUNT(sx_archivemore_layouts);}
    else if(sx_rastermore_supports(type)){rows=sx_rastermore_layouts;n=SX_COUNT(sx_rastermore_layouts);}
    else if(sx_firmwaremeta_supports(type)){rows=sx_firmwaremeta_layouts;n=SX_COUNT(sx_firmwaremeta_layouts);}
    else if(sx_columnar_supports(type)){rows=sx_columnar_layouts;n=SX_COUNT(sx_columnar_layouts);}
    else if(sx_modelmeta_supports(type)){rows=sx_modelmeta_layouts;n=SX_COUNT(sx_modelmeta_layouts);}
    else if(sx_archivelater_supports(type)){rows=sx_archivelater_layouts;n=SX_COUNT(sx_archivelater_layouts);}
    else if(sx_firmwaremore_supports(type)){rows=sx_firmwaremore_layouts;n=SX_COUNT(sx_firmwaremore_layouts);}
    else if(sx_docmeta_supports(type)){rows=sx_docmeta_layouts;n=SX_COUNT(sx_docmeta_layouts);}
    else if(sx_archivelegacy_supports(type)){rows=sx_archivelegacy_layouts;n=SX_COUNT(sx_archivelegacy_layouts);}
    else if(sx_carriermeta_supports(type)){rows=sx_carriermeta_layouts;n=SX_COUNT(sx_carriermeta_layouts);}
    else if(sx_sciencemeta_supports(type)){rows=sx_sciencemeta_layouts;n=SX_COUNT(sx_sciencemeta_layouts);}
    else if(sx_scienceheaders_supports(type)){rows=sx_scienceheaders_layouts;n=SX_COUNT(sx_scienceheaders_layouts);}
    else if(sx_networkmeta_supports(type)){rows=sx_networkmeta_layouts;n=SX_COUNT(sx_networkmeta_layouts);}
    else if(sx_gamemeta_supports(type)){rows=sx_gamemeta_layouts;n=SX_COUNT(sx_gamemeta_layouts);}
    else if(sx_diskmeta_supports(type)){rows=sx_diskmeta_layouts;n=SX_COUNT(sx_diskmeta_layouts);}
    else if(sx_audiomore_supports(type)){rows=sx_audiomore_layouts;n=SX_COUNT(sx_audiomore_layouts);}
    else if(sx_executablemore_supports(type)){rows=sx_executablemore_layouts;n=SX_COUNT(sx_executablemore_layouts);}
    else if(sx_sciencewire_supports(type)){rows=sx_sciencewire_layouts;n=SX_COUNT(sx_sciencewire_layouts);}
    else if(sx_mediaextra_supports(type)){rows=sx_mediaextra_layouts;n=SX_COUNT(sx_mediaextra_layouts);}
    else if(sx_systemextra_supports(type)){rows=sx_systemextra_layouts;n=SX_COUNT(sx_systemextra_layouts);}
    else if(sx_binaryextra_supports(type)){rows=sx_binaryextra_layouts;n=SX_COUNT(sx_binaryextra_layouts);}
    else if(sx_scientificextra_supports(type)){rows=sx_scientificextra_layouts;n=SX_COUNT(sx_scientificextra_layouts);}
    else if(sx_nextmedia_supports(type)){rows=sx_nextmedia_layouts;n=SX_COUNT(sx_nextmedia_layouts);}
    else if(sx_systemlater_supports(type)){rows=sx_systemlater_layouts;n=SX_COUNT(sx_systemlater_layouts);}
    else if(sx_trackerextra_supports(type)){rows=sx_trackerextra_layouts;n=SX_COUNT(sx_trackerextra_layouts);}
    else if(sx_binarylater_supports(type)){rows=sx_binarylater_layouts;n=SX_COUNT(sx_binarylater_layouts);}
    else if(sx_gameplatforms_supports(type)){rows=sx_gameplatforms_layouts;n=SX_COUNT(sx_gameplatforms_layouts);}
    else if(sx_systemtail_supports(type)){rows=sx_systemtail_layouts;n=SX_COUNT(sx_systemtail_layouts);}
    else if(sx_audiolater_supports(type)){rows=sx_audiolater_layouts;n=SX_COUNT(sx_audiolater_layouts);}
    else if(sx_videotail_supports(type)){rows=sx_videotail_layouts;n=SX_COUNT(sx_videotail_layouts);}
    else if(sx_samplebanks_supports(type)){rows=sx_samplebanks_layouts;n=SX_COUNT(sx_samplebanks_layouts);}
    else if(sx_gamearchives_supports(type)){rows=sx_gamearchives_layouts;n=SX_COUNT(sx_gamearchives_layouts);}
    else if(sx_archivefinal_supports(type)){rows=sx_archivefinal_layouts;n=SX_COUNT(sx_archivefinal_layouts);}
    else if(sx_classicfs_supports(type)){rows=sx_classicfs_layouts;n=SX_COUNT(sx_classicfs_layouts);}
    else if(sx_binaryresources_supports(type)){rows=sx_binaryresources_layouts;n=SX_COUNT(sx_binaryresources_layouts);}
    else if(sx_resourceextra_supports(type)){rows=sx_resourceextra_layouts;n=SX_COUNT(sx_resourceextra_layouts);}
    else if(sx_gamecontainers_supports(type)){rows=sx_gamecontainers_layouts;n=SX_COUNT(sx_gamecontainers_layouts);}
    else if(sx_textimages_supports(type)){rows=sx_textimages_layouts;n=SX_COUNT(sx_textimages_layouts);}
    else if(sx_archivestreams_supports(type)){rows=sx_archivestreams_layouts;n=SX_COUNT(sx_archivestreams_layouts);}
    else if(sx_modernfs_supports(type)){rows=sx_modernfs_layouts;n=SX_COUNT(sx_modernfs_layouts);}
    else if(sx_archivesystems_supports(type)){rows=sx_archivesystems_layouts;n=SX_COUNT(sx_archivesystems_layouts);}
    else if(sx_archiveclassic_supports(type)){rows=sx_archiveclassic_layouts;n=SX_COUNT(sx_archiveclassic_layouts);}
    else if(sx_scienceascii_supports(type)){rows=sx_scienceascii_layouts;n=SX_COUNT(sx_scienceascii_layouts);}
    else if(sx_modeltext_supports(type)){rows=sx_modeltext_layouts;n=SX_COUNT(sx_modeltext_layouts);}
    else if(sx_archiveframes_supports(type)){rows=sx_archiveframes_layouts;n=SX_COUNT(sx_archiveframes_layouts);}
    else if(sx_volumeimages_supports(type)){rows=sx_volumeimages_layouts;n=SX_COUNT(sx_volumeimages_layouts);}
    else if(sx_sciencechem_supports(type)){rows=sx_sciencechem_layouts;n=SX_COUNT(sx_sciencechem_layouts);}
    else if(sx_vectortext_supports(type)){rows=sx_vectortext_layouts;n=SX_COUNT(sx_vectortext_layouts);}
    else if(sx_archivetails_supports(type)){rows=sx_archivetails_layouts;n=SX_COUNT(sx_archivetails_layouts);}
    else if(sx_retrofs_supports(type)){rows=sx_retrofs_layouts;n=SX_COUNT(sx_retrofs_layouts);}
    else if(sx_sciencemesh_supports(type)){rows=sx_sciencemesh_layouts;n=SX_COUNT(sx_sciencemesh_layouts);}
    else if(sx_archiveobsolete_supports(type)){rows=sx_archiveobsolete_layouts;n=SX_COUNT(sx_archiveobsolete_layouts);}
    else if(sx_textwire_supports(type)){rows=sx_textwire_layouts;n=SX_COUNT(sx_textwire_layouts);}
    else if(sx_sciencesequence_supports(type)){rows=sx_sciencesequence_layouts;n=SX_COUNT(sx_sciencesequence_layouts);}
    else if(sx_disklegacy_supports(type)){rows=sx_disklegacy_layouts;n=SX_COUNT(sx_disklegacy_layouts);}
    else if(sx_archivepackages_supports(type)){rows=sx_archivepackages_layouts;n=SX_COUNT(sx_archivepackages_layouts);}
    else if(sx_documentwire_supports(type)){rows=sx_documentwire_layouts;n=SX_COUNT(sx_documentwire_layouts);}
    else if(sx_musicnext_supports(type)){rows=sx_musicnext_layouts;n=SX_COUNT(sx_musicnext_layouts);}
    else if(sx_archivenext_supports(type)){rows=sx_archivenext_layouts;n=SX_COUNT(sx_archivenext_layouts);}
    else if(sx_disknext_supports(type)){rows=sx_disknext_layouts;n=SX_COUNT(sx_disknext_layouts);}
    else if(sx_installerwire_supports(type)){rows=sx_installerwire_layouts;n=SX_COUNT(sx_installerwire_layouts);}
    if(type==XX_FILE_TYPE_BINSH_STARKIT)return sxiw_starkit_lookup(id,name);
    else if(sx_musicprojects_supports(type)){rows=sx_musicprojects_layouts;n=SX_COUNT(sx_musicprojects_layouts);}
    else if(sx_disktail_supports(type)){rows=sx_disktail_layouts;n=SX_COUNT(sx_disktail_layouts);}
    else if(sx_archiveremaining_supports(type)){rows=sx_archiveremaining_layouts;n=SX_COUNT(sx_archiveremaining_layouts);}
    else if(sx_musicremaining_supports(type)){rows=sx_musicremaining_layouts;n=SX_COUNT(sx_musicremaining_layouts);}
    else if(sx_gameremaining_supports(type)){rows=sx_gameremaining_layouts;n=SX_COUNT(sx_gameremaining_layouts);}
    else if(sx_diskremaining_supports(type)){rows=sx_diskremaining_layouts;n=SX_COUNT(sx_diskremaining_layouts);}
    else if(sx_installerremaining_supports(type)){rows=sx_installerremaining_layouts;n=SX_COUNT(sx_installerremaining_layouts);}
    else if(sx_installerextras_supports(type)){rows=sx_installerextras_layouts;n=SX_COUNT(sx_installerextras_layouts);}
    else if(sx_musictail_supports(type)){rows=sx_musictail_layouts;n=SX_COUNT(sx_musictail_layouts);}
    else if(sx_archivelpaq_supports(type)){rows=sx_archivelpaq_layouts;n=SX_COUNT(sx_archivelpaq_layouts);}
    else if(sx_archiveend_supports(type)){rows=sx_archiveend_layouts;n=SX_COUNT(sx_archiveend_layouts);}
    else if(sx_installerlast_supports(type)){rows=sx_installerlast_layouts;n=SX_COUNT(sx_installerlast_layouts);}
    else if(sx_firmwaretail_supports(type)){rows=sx_firmwaretail_layouts;n=SX_COUNT(sx_firmwaretail_layouts);}
    else if(sx_executabletail_supports(type)){rows=sx_executabletail_layouts;n=SX_COUNT(sx_executabletail_layouts);}
    else if(sx_musicwire_supports(type)){rows=sx_musicwire_layouts;n=SX_COUNT(sx_musicwire_layouts);}
    else if(sx_archivetransport_supports(type)){rows=sx_archivetransport_layouts;n=SX_COUNT(sx_archivetransport_layouts);}
    else if(sx_zxmusic_supports(type)){rows=sx_zxmusic_layouts;n=SX_COUNT(sx_zxmusic_layouts);}
    else if(sx_nextmusic_supports(type)){rows=sx_nextmusic_layouts;n=SX_COUNT(sx_nextmusic_layouts);}
    else if(sx_musiclogs_supports(type)){rows=sx_musiclogs_layouts;n=SX_COUNT(sx_musiclogs_layouts);}
    else if(sx_archivewire_supports(type)){rows=sx_archivewire_layouts;n=SX_COUNT(sx_archivewire_layouts);}
    else if(sx_synthtail_supports(type)){rows=sx_synthtail_layouts;n=SX_COUNT(sx_synthtail_layouts);}
    else if(sx_musicportable_supports(type)){rows=sx_musicportable_layouts;n=SX_COUNT(sx_musicportable_layouts);}
    else if(sx_chipmusic_supports(type)){rows=sx_chipmusic_layouts;n=SX_COUNT(sx_chipmusic_layouts);}
    else if(sx_amigaplayers_supports(type)){rows=sx_amigaplayers_layouts;n=SX_COUNT(sx_amigaplayers_layouts);}
    else if(sx_archiveresidual_supports(type)){rows=sx_archiveresidual_layouts;n=SX_COUNT(sx_archiveresidual_layouts);}
    else if(sx_archivequad_supports(type)){rows=sx_archivequad_layouts;n=SX_COUNT(sx_archivequad_layouts);}
    else if(sx_musiclate_supports(type)){rows=sx_musiclate_layouts;n=SX_COUNT(sx_musiclate_layouts);}
    else if(sx_pcmusic_supports(type)){rows=sx_pcmusic_layouts;n=SX_COUNT(sx_pcmusic_layouts);}
    else if(sx_amigamore_supports(type)){rows=sx_amigamore_layouts;n=SX_COUNT(sx_amigamore_layouts);}
    else if(sx_panorama_supports(type)){rows=sx_panorama_layouts;n=SX_COUNT(sx_panorama_layouts);}
    else if(sx_utagemedia_supports(type)){rows=sx_utagemedia_layouts;n=SX_COUNT(sx_utagemedia_layouts);}
    else if(sx_cfefirmware_supports(type)){rows=sx_cfefirmware_layouts;n=SX_COUNT(sx_cfefirmware_layouts);}
    else if(sx_musicfurther_supports(type)){rows=sx_musicfurther_layouts;n=SX_COUNT(sx_musicfurther_layouts);}
    else if(sx_pcmusicmore_supports(type)){rows=sx_pcmusicmore_layouts;n=SX_COUNT(sx_pcmusicmore_layouts);}
    else if(sx_cmdfilesystems_supports(type)){rows=sx_cmdfilesystems_layouts;n=SX_COUNT(sx_cmdfilesystems_layouts);}
    else if(sx_modvariants_supports(type)){rows=sx_modvariants_layouts;n=SX_COUNT(sx_modvariants_layouts);}
    else if(sx_vintagefilesystems_supports(type)){rows=sx_vintagefilesystems_layouts;n=SX_COUNT(sx_vintagefilesystems_layouts);}
    else if(sx_logicsamples_supports(type)){rows=sx_logicsamples_layouts;n=SX_COUNT(sx_logicsamples_layouts);}
    else if(sx_classicmusic_supports(type)){rows=sx_classicmusic_layouts;n=SX_COUNT(sx_classicmusic_layouts);}
    else if(sx_codeplayers_supports(type)){rows=sx_codeplayers_layouts;n=SX_COUNT(sx_codeplayers_layouts);}
    else if(sx_megastation_supports(type)){rows=sx_megastation_layouts;n=SX_COUNT(sx_megastation_layouts); }
    else if(sx_darkwave_supports(type)){rows=sx_darkwave_layouts;n=SX_COUNT(sx_darkwave_layouts); }
    else if(sx_musicmaker_supports(type)){rows=sx_musicmaker_layouts;n=SX_COUNT(sx_musicmaker_layouts);}
    else if(sx_playerdata_supports(type)){rows=sx_playerdata_layouts;n=SX_COUNT(sx_playerdata_layouts);}
    else if(sx_classicdata_supports(type)){rows=sx_classicdata_layouts;n=SX_COUNT(sx_classicdata_layouts);}
    else if(sx_bcmrange_supports(type)){rows=sx_bcmrange_layouts;n=SX_COUNT(sx_bcmrange_layouts);}
    else if(sx_companiondata_supports(type)){rows=sx_companiondata_layouts;n=SX_COUNT(sx_companiondata_layouts); }
    else if(sx_cinemusic_supports(type)){rows=sx_cinemusic_layouts;n=SX_COUNT(sx_cinemusic_layouts); }
    else if(sx_opllogs_supports(type)){rows=sx_opllogs_layouts;n=SX_COUNT(sx_opllogs_layouts);}
    else if(sx_music37_amiga_supports(type)){rows=sx_music37_amiga_layouts;n=SX_COUNT(sx_music37_amiga_layouts);}
    else if(sx_music37modern_supports(type)){rows=sx_music37modern_layouts;n=SX_COUNT(sx_music37modern_layouts);}
    else if(sx_aeroace_supports(type)){rows=sx_aeroace_layouts;n=SX_COUNT(sx_aeroace_layouts);}
    else if(sx_music38_amiga_supports(type)){rows=sx_music38_amiga_layouts;n=SX_COUNT(sx_music38_amiga_layouts);}
    else if(sx_edlibsamples_supports(type)){rows=sx_edlibsamples_layouts;n=SX_COUNT(sx_edlibsamples_layouts);}
    else if(sx_music38modern_supports(type)){rows=sx_music38modern_layouts;n=SX_COUNT(sx_music38modern_layouts);}
    else if(sx_music39_amiga_supports(type)){rows=sx_music39_amiga_layouts;n=SX_COUNT(sx_music39_amiga_layouts);}
    for(size_t i=0;i<n;i++)if((name&&xx_rt_strcmp(rows[i]->name,name)==0)||(!name&&rows[i]->id==id))return rows[i];
    return NULL;
}
static const char *sx_id_name(Abstractformat *f,uint32_t id)
{
    const sx_layout *l=sx_lookup(f,id,NULL);
    return id==XX_DATA_STRUCT_ID_RAW_DATA?"RAW_DATA":l?l->name:"UNKNOWN";
}
static uint32_t sx_name_id(Abstractformat *f,const char *name)
{
    const sx_layout *l;
    if(!name)return 0;
    if(!xx_rt_strcmp(name,"RAW_DATA"))return XX_DATA_STRUCT_ID_RAW_DATA;
    l=sx_lookup(f,0,name);return l?l->id:0;
}
static void sx_context_free(void *p)
{
    sx_context *c=p;
    if(c){
        xx_mem_free(c->items);
#if SX_ALIAS_READER_FACTORY
        if(c->owned_reader)xx_format_free_reader(c->owned_reader);
#endif
        xx_mem_free(c);
    }
}
static bool sx_struct_next(Abstractformat *f,xx_data_struct_state *s,xx_pd_struct *pd)
{
    sx_context *c=s?s->internal_state:NULL;(void)f;
    if(!c||xx_pd_is_stopped(pd)){if(s)s->has_struct=false;return false;}
    if(s->current_index<0||(uint64_t)s->current_index+1>=c->count){s->has_struct=false;return false;}
    s->current_index++;s->current_struct=c->items[s->current_index];s->has_struct=true;return true;
}
static xx_data_struct_state *sx_structs(Abstractformat *f,xx_pd_struct *pd)
{
    xx_data_struct_state *s;
    sx_context *c;
    int64_t total, available, content_end;
    bool ok;
    if(!f||!f->device||f->base_address<0||xx_pd_is_stopped(pd)||(total=xx_io_total_size(f->device))<f->base_address)return NULL;
#if SX_ALIAS_READER_FACTORY
    if(sx_alias_supports(f->file_type)) {
        Abstractformat *canonical;
        if((!f->base_info_handled&&!xx_format_handle_base_info(f,pd))||!f->is_valid)return NULL;
        /* Retain the caller's device coordinates. The factory's nonzero-base
         * path creates a sliced view whose descriptors start at zero. */
        canonical=xx_format_create_reader(sx_alias_canonical_type(f->file_type),f->device,0);
        if(!canonical)return NULL;
        xx_format_set_base_address(canonical,f->base_address);
        if(!xx_format_handle_base_info(canonical,pd)||!canonical->is_valid) {xx_format_free_reader(canonical);return NULL;}
        s=sx_structs(canonical,pd);
        if(!s){xx_format_free_reader(canonical);return NULL;}
        ((sx_context *)s->internal_state)->owned_reader=canonical;
        s->format=f;
        return s;
    }
#endif
    c=xx_mem_alloc(sizeof(*c));if(!c)return NULL;xx_mem_zero(c,sizeof(*c));
    c->f=f;c->pd=pd;available=total-f->base_address;content_end=available;
    if(!sx_volume_supports(f->file_type)&&f->base_info_handled&&f->is_valid&&f->format_size>0&&f->format_size<=available)content_end=f->format_size;
    c->size=content_end;
    ok=sx_image_supports(f->file_type)?sx_image_build(c):sx_container_supports(f->file_type)?sx_container_build(c):sx_executable_supports(f->file_type)?sx_executable_build(c):sx_archive_supports(f->file_type)?sx_archive_build(c):sx_volume_supports(f->file_type)?sx_volume_build(c):sx_media_supports(f->file_type)?sx_media_build(c):sx_package_supports(f->file_type)?sx_package_build(c):sx_storage_supports(f->file_type)?sx_storage_build(c):sx_binary_supports(f->file_type)?sx_binary_build(c):sx_legacy_supports(f->file_type)?sx_legacy_build(c):sx_multimedia_supports(f->file_type)?sx_multimedia_build(c):sx_systems_supports(f->file_type)?sx_systems_build(c):sx_extendedmedia_supports(f->file_type)?sx_extendedmedia_build(c):sx_tracker_supports(f->file_type)?sx_tracker_build(c):sx_adlib_supports(f->file_type)?sx_adlib_build(c):sx_filesystems_supports(f->file_type)?sx_filesystems_build(c):sx_unixfs_supports(f->file_type)?sx_unixfs_build(c):sx_opticalfs_supports(f->file_type)?sx_opticalfs_build(c):sx_pcedisks_supports(f->file_type)?sx_pcedisks_build(c):sx_diskimages_supports(f->file_type)?sx_diskimages_build(c):sx_vmmeta_supports(f->file_type)?sx_vmmeta_build(c):sx_archiveextras_supports(f->file_type)?sx_archiveextras_build(c):sx_cowfs_supports(f->file_type)?sx_cowfs_build(c):sx_fontbinary_supports(f->file_type)?sx_fontbinary_build(c):sx_databases_supports(f->file_type)?sx_databases_build(c):sx_androidmeta_supports(f->file_type)?sx_androidmeta_build(c):sx_archivemore_supports(f->file_type)?sx_archivemore_build(c):sx_rastermore_supports(f->file_type)?sx_rastermore_build(c):sx_firmwaremeta_supports(f->file_type)?sx_firmwaremeta_build(c):sx_columnar_supports(f->file_type)?sx_columnar_build(c):sx_modelmeta_supports(f->file_type)?sx_modelmeta_build(c):sx_archivelater_supports(f->file_type)?sx_archivelater_build(c):sx_firmwaremore_supports(f->file_type)?sx_firmwaremore_build(c):sx_docmeta_supports(f->file_type)?sx_docmeta_build(c):sx_archivelegacy_supports(f->file_type)?sx_archivelegacy_build(c):sx_carriermeta_supports(f->file_type)?sx_carriermeta_build(c):sx_sciencemeta_supports(f->file_type)?sx_sciencemeta_build(c):sx_scienceheaders_supports(f->file_type)?sx_scienceheaders_build(c):sx_networkmeta_supports(f->file_type)?sx_networkmeta_build(c):sx_gamemeta_supports(f->file_type)?sx_gamemeta_build(c):sx_diskmeta_supports(f->file_type)?sx_diskmeta_build(c):sx_audiomore_supports(f->file_type)?sx_audiomore_build(c):sx_executablemore_supports(f->file_type)?sx_executablemore_build(c):sx_sciencewire_supports(f->file_type)?sx_sciencewire_build(c):sx_mediaextra_supports(f->file_type)?sx_mediaextra_build(c):sx_systemextra_supports(f->file_type)?sx_systemextra_build(c):sx_binaryextra_supports(f->file_type)?sx_binaryextra_build(c):sx_scientificextra_supports(f->file_type)?sx_scientificextra_build(c):sx_nextmedia_supports(f->file_type)?sx_nextmedia_build(c):sx_systemlater_supports(f->file_type)?sx_systemlater_build(c):sx_trackerextra_supports(f->file_type)?sx_trackerextra_build(c):sx_binarylater_supports(f->file_type)?sx_binarylater_build(c):sx_gameplatforms_supports(f->file_type)?sx_gameplatforms_build(c):sx_systemtail_supports(f->file_type)?sx_systemtail_build(c):sx_audiolater_supports(f->file_type)?sx_audiolater_build(c):sx_videotail_supports(f->file_type)?sx_videotail_build(c):sx_samplebanks_supports(f->file_type)?sx_samplebanks_build(c):sx_gamearchives_supports(f->file_type)?sx_gamearchives_build(c):sx_archivefinal_supports(f->file_type)?sx_archivefinal_build(c):sx_classicfs_supports(f->file_type)?sx_classicfs_build(c):sx_binaryresources_supports(f->file_type)?sx_binaryresources_build(c):sx_resourceextra_supports(f->file_type)?sx_resourceextra_build(c):sx_gamecontainers_supports(f->file_type)?sx_gamecontainers_build(c):sx_textimages_supports(f->file_type)?sx_textimages_build(c):sx_archivestreams_supports(f->file_type)?sx_archivestreams_build(c):sx_modernfs_supports(f->file_type)?sx_modernfs_build(c):sx_archivesystems_supports(f->file_type)?sx_archivesystems_build(c):sx_archiveclassic_supports(f->file_type)?sx_archiveclassic_build(c):sx_scienceascii_supports(f->file_type)?sx_scienceascii_build(c):sx_modeltext_supports(f->file_type)?sx_modeltext_build(c):sx_archiveframes_supports(f->file_type)?sx_archiveframes_build(c):sx_volumeimages_supports(f->file_type)?sx_volumeimages_build(c):sx_sciencechem_supports(f->file_type)?sx_sciencechem_build(c):sx_vectortext_supports(f->file_type)?sx_vectortext_build(c):sx_archivetails_supports(f->file_type)?sx_archivetails_build(c):sx_retrofs_supports(f->file_type)?sx_retrofs_build(c):sx_sciencemesh_supports(f->file_type)?sx_sciencemesh_build(c):sx_archiveobsolete_supports(f->file_type)?sx_archiveobsolete_build(c):sx_textwire_supports(f->file_type)?sx_textwire_build(c):sx_sciencesequence_supports(f->file_type)?sx_sciencesequence_build(c):sx_disklegacy_supports(f->file_type)?sx_disklegacy_build(c):sx_archivepackages_supports(f->file_type)?sx_archivepackages_build(c):sx_documentwire_supports(f->file_type)?sx_documentwire_build(c):sx_musicnext_supports(f->file_type)?sx_musicnext_build(c):sx_archivenext_supports(f->file_type)?sx_archivenext_build(c):sx_disknext_supports(f->file_type)?sx_disknext_build(c):sx_installerwire_supports(f->file_type)?sx_installerwire_build(c):sx_musicprojects_supports(f->file_type)?sx_musicprojects_build(c):sx_disktail_supports(f->file_type)?sx_disktail_build(c):sx_archiveremaining_supports(f->file_type)?sx_archiveremaining_build(c):sx_musicremaining_supports(f->file_type)?sx_musicremaining_build(c):sx_gameremaining_supports(f->file_type)?sx_gameremaining_build(c):sx_diskremaining_supports(f->file_type)?sx_diskremaining_build(c):sx_installerremaining_supports(f->file_type)?sx_installerremaining_build(c):sx_installerextras_supports(f->file_type)?sx_installerextras_build(c):sx_musictail_supports(f->file_type)?sx_musictail_build(c):sx_archivelpaq_supports(f->file_type)?sx_archivelpaq_build(c):sx_archiveend_supports(f->file_type)?sx_archiveend_build(c):sx_installerlast_supports(f->file_type)?sx_installerlast_build(c):sx_firmwaretail_supports(f->file_type)?sx_firmwaretail_build(c):sx_executabletail_supports(f->file_type)?sx_executabletail_build(c):sx_musicwire_supports(f->file_type)?sx_musicwire_build(c):sx_archivetransport_supports(f->file_type)?sx_archivetransport_build(c):sx_zxmusic_supports(f->file_type)?sx_zxmusic_build(c):sx_nextmusic_supports(f->file_type)?sx_nextmusic_build(c):sx_musiclogs_supports(f->file_type)?sx_musiclogs_build(c):sx_archivewire_supports(f->file_type)?sx_archivewire_build(c):sx_synthtail_supports(f->file_type)?sx_synthtail_build(c):sx_musicportable_supports(f->file_type)?sx_musicportable_build(c):sx_chipmusic_supports(f->file_type)?sx_chipmusic_build(c):sx_amigaplayers_supports(f->file_type)?sx_amigaplayers_build(c):sx_archiveresidual_supports(f->file_type)?sx_archiveresidual_build(c):sx_archivequad_supports(f->file_type)?sx_archivequad_build(c):sx_musiclate_supports(f->file_type)?sx_musiclate_build(c):sx_pcmusic_supports(f->file_type)?sx_pcmusic_build(c):sx_amigamore_supports(f->file_type)?sx_amigamore_build(c):sx_panorama_supports(f->file_type)?sx_panorama_build(c):sx_utagemedia_supports(f->file_type)?sx_utagemedia_build(c):sx_cfefirmware_supports(f->file_type)?sx_cfefirmware_build(c):sx_musicfurther_supports(f->file_type)?sx_musicfurther_build(c):sx_pcmusicmore_supports(f->file_type)?sx_pcmusicmore_build(c):sx_cmdfilesystems_supports(f->file_type)?sx_cmdfilesystems_build(c):sx_modvariants_supports(f->file_type)?sx_modvariants_build(c):sx_vintagefilesystems_supports(f->file_type)?sx_vintagefilesystems_build(c):sx_logicsamples_supports(f->file_type)?sx_logicsamples_build(c):sx_classicmusic_supports(f->file_type)?sx_classicmusic_build(c):sx_codeplayers_supports(f->file_type)?sx_codeplayers_build(c):sx_megastation_supports(f->file_type)?sx_megastation_build(c):sx_darkwave_supports(f->file_type)?sx_darkwave_build(c):sx_musicmaker_supports(f->file_type)?sx_musicmaker_build(c):sx_playerdata_supports(f->file_type)?sx_playerdata_build(c):sx_classicdata_supports(f->file_type)?sx_classicdata_build(c):sx_bcmrange_supports(f->file_type)?sx_bcmrange_build(c):sx_companiondata_supports(f->file_type)?sx_companiondata_build(c):sx_cinemusic_supports(f->file_type)?sx_cinemusic_build(c):sx_opllogs_supports(f->file_type)?sx_opllogs_build(c):sx_music37_amiga_supports(f->file_type)?sx_music37_amiga_build(c):sx_music37modern_supports(f->file_type)?sx_music37modern_build(c):sx_aeroace_supports(f->file_type)?sx_aeroace_build(c):sx_music38_amiga_supports(f->file_type)?sx_music38_amiga_build(c):sx_edlibsamples_supports(f->file_type)?sx_edlibsamples_build(c):sx_music38modern_supports(f->file_type)?sx_music38modern_build(c):sx_music39_amiga_supports(f->file_type)?sx_music39_amiga_build(c):false;
    if(!ok||c->failed||xx_pd_is_stopped(pd)){sx_context_free(c);return NULL;}
    c->size=available;
    if(content_end<available&&!sx_raw(c,content_end,available-content_end)){sx_context_free(c);return NULL;}
    s=xx_mem_alloc(sizeof(*s));if(!s){sx_context_free(c);return NULL;}
    xx_data_struct_state_init(s,f);s->internal_state=c;s->free_internal=sx_context_free;s->total_structs=(int64_t)c->count;
    if(c->count){s->current_struct=c->items[0];s->current_index=0;s->has_struct=true;}
    return s;
}
typedef struct sx_record_context { const sx_layout *layout; bool be; } sx_record_context;
/* Variable-width integer encodings retain their physical bytes but expose
 * the decoded numeric value and semantic role to the common formatter. */
static bool sx_size_comment(xx_data_struct_record *r,uint64_t v)
{
    char a[96];wchar_t w[96];size_t i;
    if(!xx_str_bytes_count_to_string(v,1024,a,sizeof(a)))return false;
    for(i=0;a[i];i++)w[i]=(unsigned char)a[i];w[i]=0;
    return xx_data_struct_record_set_comment(r,w);
}
#include "xx_format_schema_legacy_integer.inc"
#include "xx_format_schema_cpio_integer.inc"
#include "xx_format_schema_ascii_scalar.inc"
#include "xx_format_schema_nastran_real.inc"
#include "xx_format_schema_fortran_real.inc"
#include "xx_format_schema_utf8_field.inc"
#include "xx_format_schema_ones_complement.inc"
#include "xx_format_schema_msb_bits.inc"
#include "xx_format_schema_stuffitx_bits.inc"
#include "xx_format_schema_bias33.inc"

static bool sx_decode_ascii_integer(xx_data_struct_record_state *s,const xx_data_struct_field_desc *field)
{
    unsigned base=field->type&&!xx_rt_wcsncmp(field->type,L"ascii_hex[",10)?16:field->type&&!xx_rt_wcsncmp(field->type,L"ascii_octal[",12)?8:0;
    uint8_t bytes[24];uint64_t v=0;char a[40];wchar_t w[40];int n;
    if(!base)return true;
    if(field->size<1||field->size>(int64_t)sizeof(bytes)||!xx_io_read_at(s->format->device,s->parent_struct.offset+field->rel_offset,bytes,(size_t)field->size))return false;
    for(int64_t i=0;i<field->size;i++) {
        unsigned d=bytes[i]>='0'&&bytes[i]<='9'?bytes[i]-'0':bytes[i]>='a'&&bytes[i]<='f'?bytes[i]-'a'+10:bytes[i]>='A'&&bytes[i]<='F'?bytes[i]-'A'+10:255;
        if(d>=base||v>(UINT64_MAX-d)/base)return false;v=v*base+d;
    }
    xx_var_set_u64(&s->current_record.value,v);
    bool hex=(field->property&(SX_ID|SX_FLAGS|SX_SIGNATURE|SX_CHECKSUM|SX_OFFSET|SX_POINTER|SX_ADDRESS))!=0;
    n=xx_rt_snprintf(a,sizeof(a),hex?"0x%llX":"%llu",(unsigned long long)v);
    if(n<0||n>=(int)sizeof(a))return false;for(int i=0;i<=n;i++)w[i]=(unsigned char)a[i];
    return xx_data_struct_record_set_display_value(&s->current_record,w)&&(!(field->property&SX_SIZE)||sx_size_comment(&s->current_record,v));
}
#include "xx_format_schema_uleb64.inc"
#include "xx_format_schema_freearc_uint.inc"

#include "xx_format_schema_zigzag.inc"

static bool sx_decode_encoded_integer(xx_data_struct_record_state *s, const xx_data_struct_field_desc *field)
{
    bool base128=field->type&&!xx_rt_wcscmp(field->type,L"uintbase128");
    bool uleb=field->type&&!xx_rt_wcscmp(field->type,L"uleb128");
    uint8_t bytes[5];uint32_t v=0;char ascii[32];wchar_t display[32];
    if(!base128&&!uleb)return true;
    if(field->size<1||field->size>5||!xx_io_read_at(s->format->device,s->parent_struct.offset+field->rel_offset,bytes,(size_t)field->size))return false;
    for(size_t i=0;i<(size_t)field->size;i++) {
        if(((bytes[i]&128)!=0)!=(i+1<(size_t)field->size))return false;
        if(base128){if((i==0&&bytes[i]==128)||(v&0xfe000000U))return false;v=(v<<7)|(bytes[i]&127);}
        else{if(i==4&&(bytes[i]&0xf0))return false;v|=(uint32_t)(bytes[i]&127)<<(7*i);}
    }
    xx_var_set_u32(&s->current_record.value,v);
    int n=xx_rt_snprintf(ascii,sizeof(ascii),"%u",(unsigned)v);
    if(n<0||n>=(int)sizeof(ascii))return false;
    for(int i=0;i<=n;i++)display[i]=(unsigned char)ascii[i];
    return xx_data_struct_record_set_raw_bytes(&s->current_record,s->format->device,s->parent_struct.offset+field->rel_offset,field->size)&&
           xx_data_struct_record_set_display_value(&s->current_record,display)&&
           (!(field->property&SX_SIZE)||sx_size_comment(&s->current_record,v));
}
static bool sx_record_load(xx_data_struct_record_state *s)
{
    sx_record_context *c=s->internal_state;
    const xx_data_struct_field_desc *field;
    if(s->current_index<0||(uint64_t)s->current_index>=c->layout->field_count)return false;
    xx_data_struct_field_desc expanded;wchar_t type[64];
    if(!sx_expand_field(c->layout,(size_t)s->current_index,s->parent_struct.entry_size,&expanded,type))return false;
    field=&expanded;
    if(!sx_populate_record_field(&s->current_record,s->format->device,s->parent_struct.offset,field,c->be))return false;
    if(!sx_decode_fortran_real(s,field)||!sx_decode_nastran_real(s,field)||!sx_decode_ascii_scalar(s,field)||!sx_decode_utf8_field(s,field)||!sx_decode_bias33(s,field)||!sx_decode_stuffitx_bits(s,field)||!sx_decode_msb_bits(s,field)||!sx_decode_ones_complement(s,field)||!sx_decode_freearc_uint(s,field)||!sx_decode_uleb64(s,field)||!sx_decode_cpio_integer(s,field)||!sx_decode_legacy_integer(s,field)||!sx_decode_ascii_integer(s,field)||!sx_decode_zigzag(s,field)||!sx_decode_encoded_integer(s,field)||!sx_image_comment(&s->current_record,c->layout->id)||!sx_container_comment(&s->current_record,c->layout->id)||!sx_executable_comment(&s->current_record,c->layout->id)||!sx_archive_comment(&s->current_record,c->layout->id)||!sx_volume_comment(&s->current_record,c->layout->id)||!sx_media_comment(&s->current_record,c->layout->id)||!sx_package_comment(&s->current_record,c->layout->id)||!sx_storage_comment(&s->current_record,c->layout->id)||!sx_legacy_comment(&s->current_record,c->layout->id)||!sx_multimedia_comment(&s->current_record,c->layout->id)||!sx_systems_comment(&s->current_record,c->layout->id)||!sx_extendedmedia_comment(&s->current_record,c->layout->id)||!sx_tracker_comment(&s->current_record,c->layout->id)||!sx_adlib_comment(&s->current_record,c->layout->id)||!sx_filesystems_comment(&s->current_record,c->layout->id)||!sx_unixfs_comment(&s->current_record,c->layout->id)||!sx_opticalfs_comment(&s->current_record,c->layout->id)||!sx_pcedisks_comment(&s->current_record,c->layout->id)||!sx_diskimages_comment(&s->current_record,c->layout->id)||!sx_vmmeta_comment(&s->current_record,c->layout->id)||!sx_archiveextras_comment(&s->current_record,c->layout->id)||!sx_cowfs_comment(&s->current_record,c->layout->id)||!sx_fontbinary_comment(&s->current_record,c->layout->id)||!sx_databases_comment(&s->current_record,c->layout->id)||!sx_androidmeta_comment(&s->current_record,c->layout->id)||!sx_archivemore_comment(&s->current_record,c->layout->id)||!sx_rastermore_comment(&s->current_record,c->layout->id)||!sx_firmwaremeta_comment(&s->current_record,c->layout->id)||!sx_columnar_comment(&s->current_record,c->layout->id)||!sx_modelmeta_comment(&s->current_record,c->layout->id)||!sx_archivelater_comment(&s->current_record,c->layout->id)||!sx_firmwaremore_comment(&s->current_record,c->layout->id)||!sx_docmeta_comment(&s->current_record,c->layout->id)||!sx_archivelegacy_comment(&s->current_record,c->layout->id)||!sx_carriermeta_comment(&s->current_record,c->layout->id)||!sx_sciencemeta_comment(&s->current_record,c->layout->id)||!sx_scienceheaders_comment(&s->current_record,c->layout->id)||!sx_networkmeta_comment(&s->current_record,c->layout->id)||!sx_gamemeta_comment(&s->current_record,c->layout->id)||!sx_diskmeta_comment(&s->current_record,c->layout->id)||!sx_audiomore_comment(&s->current_record,c->layout->id)||!sx_executablemore_comment(&s->current_record,c->layout->id)||!sx_sciencewire_comment(&s->current_record,c->layout->id)||!sx_mediaextra_comment(&s->current_record,c->layout->id)||!sx_systemextra_comment(&s->current_record,c->layout->id)||!sx_binaryextra_comment(&s->current_record,c->layout->id)||!sx_scientificextra_comment(&s->current_record,c->layout->id)||!sx_nextmedia_comment(&s->current_record,c->layout->id)||!sx_systemlater_comment(&s->current_record,c->layout->id)||!sx_trackerextra_comment(&s->current_record,c->layout->id)||!sx_binarylater_comment(&s->current_record,c->layout->id)||!sx_gameplatforms_comment(&s->current_record,c->layout->id)||!sx_systemtail_comment(&s->current_record,c->layout->id)||!sx_audiolater_comment(&s->current_record,c->layout->id)||!sx_videotail_comment(&s->current_record,c->layout->id)||!sx_samplebanks_comment(&s->current_record,c->layout->id)||!sx_gamearchives_comment(&s->current_record,c->layout->id)||!sx_archivefinal_comment(&s->current_record,c->layout->id)||!sx_classicfs_comment(&s->current_record,c->layout->id)||!sx_binaryresources_comment(&s->current_record,c->layout->id)||!sx_resourceextra_comment(&s->current_record,c->layout->id)||!sx_gamecontainers_comment(&s->current_record,c->layout->id)||!sx_textimages_comment(&s->current_record,c->layout->id)||!sx_archivestreams_comment(&s->current_record,c->layout->id)||!sx_modernfs_comment(&s->current_record,c->layout->id)||!sx_archivesystems_comment(&s->current_record,c->layout->id)||!sx_archiveclassic_comment(&s->current_record,c->layout->id)||!sx_scienceascii_comment(&s->current_record,c->layout->id)||!sx_modeltext_comment(&s->current_record,c->layout->id)||!sx_archiveframes_comment(&s->current_record,c->layout->id)||!sx_volumeimages_comment(&s->current_record,c->layout->id)||!sx_sciencechem_comment(&s->current_record,c->layout->id)||!sx_vectortext_comment(&s->current_record,c->layout->id)||!sx_archivetails_comment(&s->current_record,c->layout->id)||!sx_retrofs_comment(&s->current_record,c->layout->id)||!sx_sciencemesh_comment(&s->current_record,c->layout->id)||!sx_archiveobsolete_comment(&s->current_record,c->layout->id)||!sx_textwire_comment(&s->current_record,c->layout->id)||!sx_sciencesequence_comment(&s->current_record,c->layout->id)||!sx_disklegacy_comment(&s->current_record,c->layout->id)||!sx_archivepackages_comment(&s->current_record,c->layout->id)||!sx_documentwire_comment(&s->current_record,c->layout->id)||!sx_musicnext_comment(&s->current_record,c->layout->id)||!sx_archivenext_comment(&s->current_record,c->layout->id)||!sx_disknext_comment(&s->current_record,c->layout->id)||!sx_installerwire_comment(&s->current_record,c->layout->id)||!sx_musicprojects_comment(&s->current_record,c->layout->id)||!sx_disktail_comment(&s->current_record,c->layout->id)||!sx_archiveremaining_comment(&s->current_record,c->layout->id)||!sx_musicremaining_comment(&s->current_record,c->layout->id)||!sx_gameremaining_comment(&s->current_record,c->layout->id)||!sx_diskremaining_comment(&s->current_record,c->layout->id)||!sx_installerremaining_comment(&s->current_record,c->layout->id)||!sx_installerextras_comment(&s->current_record,c->layout->id)||!sx_musictail_comment(&s->current_record,c->layout->id)||!sx_archivelpaq_comment(&s->current_record,c->layout->id)||!sx_archiveend_comment(&s->current_record,c->layout->id)||!sx_installerlast_comment(&s->current_record,c->layout->id)||!sx_firmwaretail_comment(&s->current_record,c->layout->id)||!sx_executabletail_comment(&s->current_record,c->layout->id)||!sx_musicwire_comment(&s->current_record,c->layout->id)||!sx_archivetransport_comment(&s->current_record,c->layout->id)||!sx_zxmusic_comment(&s->current_record,c->layout->id)||!sx_nextmusic_comment(&s->current_record,c->layout->id)||!sx_musiclogs_comment(&s->current_record,c->layout->id)||!sx_archivewire_comment(&s->current_record,c->layout->id)||!sx_synthtail_comment(&s->current_record,c->layout->id)||!sx_musicportable_comment(&s->current_record,c->layout->id)||!sx_chipmusic_comment(&s->current_record,c->layout->id)||!sx_amigaplayers_comment(&s->current_record,c->layout->id)||!sx_archiveresidual_comment(&s->current_record,c->layout->id)||!sx_archivequad_comment(&s->current_record,c->layout->id)||!sx_musiclate_comment(&s->current_record,c->layout->id)||!sx_pcmusic_comment(&s->current_record,c->layout->id)||!sx_amigamore_comment(&s->current_record,c->layout->id)||!sx_panorama_comment(&s->current_record,c->layout->id)||!sx_utagemedia_comment(&s->current_record,c->layout->id)||!sx_cfefirmware_comment(&s->current_record,c->layout->id)||!sx_musicfurther_comment(&s->current_record,c->layout->id)||!sx_pcmusicmore_comment(&s->current_record,c->layout->id)||!sx_cmdfilesystems_comment(&s->current_record,c->layout->id)||!sx_modvariants_comment(&s->current_record,c->layout->id)||!sx_vintagefilesystems_comment(&s->current_record,c->layout->id)||!sx_logicsamples_comment(&s->current_record,c->layout->id)||!sx_classicmusic_comment(&s->current_record,c->layout->id)||!sx_codeplayers_comment(&s->current_record,c->layout->id)||!sx_musicmaker_comment(&s->current_record,c->layout->id)||!sx_playerdata_comment(&s->current_record,c->layout->id)||!sx_classicdata_comment(&s->current_record,c->layout->id)||!sx_bcmrange_comment(&s->current_record,c->layout->id)||!sx_binary_comment(&s->current_record,c->layout->id)||!sx_opllogs_comment(&s->current_record,c->layout->id)||!sx_music37_amiga_comment(&s->current_record,c->layout->id)||!sx_music37modern_comment(&s->current_record,c->layout->id)||!sx_aeroace_comment(&s->current_record,c->layout->id)||!sx_music38_amiga_comment(&s->current_record,c->layout->id)||!sx_edlibsamples_comment(&s->current_record,c->layout->id)||!sx_music38modern_comment(&s->current_record,c->layout->id)||!sx_music39_amiga_comment(&s->current_record,c->layout->id)||!sx_cinemusic_comment(&s->current_record,c->layout->id)||!sx_companiondata_comment(&s->current_record,c->layout->id)||!sx_darkwave_comment(&s->current_record,c->layout->id)||!sx_megastation_comment(&s->current_record,c->layout->id)) {
        xx_data_struct_record_cleanup(&s->current_record);return false;
    }
    s->has_record=true;return true;
}
static bool sx_record_next(Abstractformat *f,xx_data_struct_record_state *s,xx_pd_struct *pd)
{
    (void)f;
    if(!s||!s->internal_state)return false;
    xx_data_struct_record_cleanup(&s->current_record);s->has_record=false;
    if(xx_pd_is_stopped(pd))return false;
    s->current_index++;return sx_record_load(s);
}
static xx_data_struct_record_state *sx_records(Abstractformat *f,const xx_data_struct *d,xx_pd_struct *pd)
{
    const sx_layout *l;
    xx_data_struct_record_state *s;
    sx_record_context *c;
    int64_t total;
    if(!f||!d||xx_pd_is_stopped(pd)||!(l=sx_lookup(f,d->id,NULL))||f->base_address<0||d->offset<f->base_address||d->entry_size<=0||d->count==0||d->total_size<d->entry_size)return NULL;
    total=xx_io_total_size(f->device);
    if(d->offset>total||d->total_size>total-d->offset||d->count>(uint64_t)d->total_size/(uint64_t)d->entry_size)return NULL;
    for(size_t i=0;i<l->field_count;i++){xx_data_struct_field_desc field;wchar_t type[64];if(!sx_expand_field(l,i,d->entry_size,&field,type))return NULL;}
    s=xx_mem_alloc(sizeof(*s));if(!s)return NULL;
    xx_data_struct_record_state_init(s,f,d);
    c=xx_mem_alloc(sizeof(*c));if(!c){xx_data_struct_record_state_free(s);return NULL;}
    c->layout=l;c->be=l->endian==SX_BE||(l->endian==SX_FILE&&f->endian==XX_ENDIAN_BIG);
    s->internal_state=c;s->free_internal=xx_mem_free;s->total_records=(int64_t)l->field_count;s->current_index=0;
    if(!sx_record_load(s)){xx_data_struct_record_state_free(s);return NULL;}return s;
}
#include "xx_format_schema_disknext_adapter.inc"
#include "xx_format_schema_installerwire_adapter.inc"
#include "xx_format_schema_nativecarriers.inc"

const StreamDataStructs *xx_format_schema_get_stream_datastructs(Abstractformat *f)
{
    xx_file_type_t type;
    if(!f)return NULL;
    const StreamDataStructs *native = sx_nativecarriers_get_stream_datastructs(f);
    if(native)return native;
    type=sx_alias_canonical_type(f->file_type);
    if(!sx_image_supports(type)&&!sx_container_supports(type)&&!sx_executable_supports(type)&&!sx_archive_supports(type)&&!sx_volume_supports(type)&&!sx_media_supports(type)&&!sx_package_supports(type)&&!sx_storage_supports(type)&&!sx_legacy_supports(type)&&!sx_multimedia_supports(type)&&!sx_systems_supports(type)&&!sx_extendedmedia_supports(type)&&!sx_tracker_supports(type)&&!sx_adlib_supports(type)&&!sx_filesystems_supports(type)&&!sx_unixfs_supports(type)&&!sx_opticalfs_supports(type)&&!sx_pcedisks_supports(type)&&!sx_diskimages_supports(type)&&!sx_vmmeta_supports(type)&&!sx_archiveextras_supports(type)&&!sx_cowfs_supports(type)&&!sx_fontbinary_supports(type)&&!sx_databases_supports(type)&&!sx_androidmeta_supports(type)&&!sx_archivemore_supports(type)&&!sx_rastermore_supports(type)&&!sx_firmwaremeta_supports(type)&&!sx_columnar_supports(type)&&!sx_modelmeta_supports(type)&&!sx_archivelater_supports(type)&&!sx_firmwaremore_supports(type)&&!sx_docmeta_supports(type)&&!sx_archivelegacy_supports(type)&&!sx_carriermeta_supports(type)&&!sx_sciencemeta_supports(type)&&!sx_scienceheaders_supports(type)&&!sx_networkmeta_supports(type)&&!sx_gamemeta_supports(type)&&!sx_diskmeta_supports(type)&&!sx_audiomore_supports(type)&&!sx_executablemore_supports(type)&&!sx_sciencewire_supports(type)&&!sx_mediaextra_supports(type)&&!sx_systemextra_supports(type)&&!sx_binaryextra_supports(type)&&!sx_scientificextra_supports(type)&&!sx_nextmedia_supports(type)&&!sx_systemlater_supports(type)&&!sx_trackerextra_supports(type)&&!sx_binarylater_supports(type)&&!sx_gameplatforms_supports(type)&&!sx_systemtail_supports(type)&&!sx_audiolater_supports(type)&&!sx_videotail_supports(type)&&!sx_samplebanks_supports(type)&&!sx_gamearchives_supports(type)&&!sx_archivefinal_supports(type)&&!sx_classicfs_supports(type)&&!sx_binaryresources_supports(type)&&!sx_resourceextra_supports(type)&&!sx_gamecontainers_supports(type)&&!sx_textimages_supports(type)&&!sx_archivestreams_supports(type)&&!sx_modernfs_supports(type)&&!sx_archivesystems_supports(type)&&!sx_archiveclassic_supports(type)&&!sx_scienceascii_supports(type)&&!sx_modeltext_supports(type)&&!sx_archiveframes_supports(type)&&!sx_volumeimages_supports(type)&&!sx_sciencechem_supports(type)&&!sx_vectortext_supports(type)&&!sx_archivetails_supports(type)&&!sx_retrofs_supports(type)&&!sx_sciencemesh_supports(type)&&!sx_archiveobsolete_supports(type)&&!sx_textwire_supports(type)&&!sx_sciencesequence_supports(type)&&!sx_disklegacy_supports(type)&&!sx_archivepackages_supports(type)&&!sx_documentwire_supports(type)&&!sx_musicnext_supports(type)&&!sx_archivenext_supports(type)&&!sx_disknext_supports(type)&&!sx_installerwire_supports(type)&&!sx_musicprojects_supports(type)&&!sx_disktail_supports(type)&&!sx_archiveremaining_supports(type)&&!sx_musicremaining_supports(type)&&!sx_gameremaining_supports(type)&&!sx_diskremaining_supports(type)&&!sx_installerremaining_supports(type)&&!sx_installerextras_supports(type)&&!sx_musictail_supports(type)&&!sx_archivelpaq_supports(type)&&!sx_archiveend_supports(type)&&!sx_installerlast_supports(type)&&!sx_firmwaretail_supports(type)&&!sx_executabletail_supports(type)&&!sx_musicwire_supports(type)&&!sx_archivetransport_supports(type)&&!sx_zxmusic_supports(type)&&!sx_nextmusic_supports(type)&&!sx_musiclogs_supports(type)&&!sx_archivewire_supports(type)&&!sx_synthtail_supports(type)&&!sx_musicportable_supports(type)&&!sx_chipmusic_supports(type)&&!sx_amigaplayers_supports(type)&&!sx_archiveresidual_supports(type)&&!sx_archivequad_supports(type)&&!sx_musiclate_supports(type)&&!sx_pcmusic_supports(type)&&!sx_amigamore_supports(type)&&!sx_panorama_supports(type)&&!sx_utagemedia_supports(type)&&!sx_cfefirmware_supports(type)&&!sx_musicfurther_supports(type)&&!sx_pcmusicmore_supports(type)&&!sx_cmdfilesystems_supports(type)&&!sx_modvariants_supports(type)&&!sx_vintagefilesystems_supports(type)&&!sx_logicsamples_supports(type)&&!sx_classicmusic_supports(type)&&!sx_codeplayers_supports(type)&&!sx_binary_supports(type)&&!sx_megastation_supports(type)&&!sx_darkwave_supports(type)&&!sx_musicmaker_supports(type)&&!sx_playerdata_supports(type)&&!sx_classicdata_supports(type)&&!sx_bcmrange_supports(type)&&!sx_companiondata_supports(type)&&!sx_cinemusic_supports(type)&&!sx_opllogs_supports(type)&&!sx_music37_amiga_supports(type)&&!sx_music37modern_supports(type)&&!sx_aeroace_supports(type)&&!sx_music38_amiga_supports(type)&&!sx_edlibsamples_supports(type)&&!sx_music38modern_supports(type)&&!sx_music39_amiga_supports(type))return NULL;
    static const StreamDataStructs standard = {
        .data_struct_id_to_string = sx_id_name,
        .data_struct_string_to_id = sx_name_id,
        .create_data_structs_reading = sx_structs,
        .data_struct_move_to_next = sx_struct_next,
        .create_data_struct_records_reading = sx_records,
        .data_struct_record_move_to_next = sx_record_next
    };
    static const StreamDataStructs starkit = {
        .data_struct_id_to_string = sx_id_name,
        .data_struct_string_to_id = sx_name_id,
        .create_data_structs_reading = sx_structs,
        .data_struct_move_to_next = sx_struct_next,
        .create_data_struct_records_reading = sx_installerwire_records,
        .data_struct_record_move_to_next = sx_record_next
    };
    static const StreamDataStructs psadisk = {
        .data_struct_id_to_string = sx_id_name,
        .data_struct_string_to_id = sx_name_id,
        .create_data_structs_reading = sx_structs,
        .data_struct_move_to_next = sx_struct_next,
        .create_data_struct_records_reading = sx_disknext_records,
        .data_struct_record_move_to_next = sx_record_next
    };
    return f->file_type == XX_FILE_TYPE_BINSH_STARKIT ? &starkit :
           f->file_type == XX_FILE_TYPE_PSA_DISK ? &psadisk : &standard;
}
