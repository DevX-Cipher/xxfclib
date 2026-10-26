/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Optional stream providers are independent of Abstractformat. This registry
 * performs no I/O and borrows immutable, process-wide provider tables.
 */
#include "xxfclib/formats/xx_format.h"

/* Non-CMake builds retain the complete library's native providers by default.
 * Focused CMake profiles set these private flags from their reader closure. */
#ifndef XXFC_STREAM_HAS_7ZIP
#define XXFC_STREAM_HAS_7ZIP 1
#endif
#ifndef XXFC_STREAM_HAS_AR
#define XXFC_STREAM_HAS_AR 1
#endif
#ifndef XXFC_STREAM_HAS_BZ2
#define XXFC_STREAM_HAS_BZ2 1
#endif
#ifndef XXFC_STREAM_HAS_GZ
#define XXFC_STREAM_HAS_GZ 1
#endif
#ifndef XXFC_STREAM_HAS_RAR
#define XXFC_STREAM_HAS_RAR 1
#endif
#ifndef XXFC_STREAM_HAS_TAR
#define XXFC_STREAM_HAS_TAR 1
#endif
#ifndef XXFC_STREAM_HAS_TAR_BZ2
#define XXFC_STREAM_HAS_TAR_BZ2 1
#endif
#ifndef XXFC_STREAM_HAS_TAR_GZ
#define XXFC_STREAM_HAS_TAR_GZ 1
#endif
#ifndef XXFC_STREAM_HAS_TAR_LZ4
#define XXFC_STREAM_HAS_TAR_LZ4 1
#endif
#ifndef XXFC_STREAM_HAS_TAR_XZ
#define XXFC_STREAM_HAS_TAR_XZ 1
#endif
#ifndef XXFC_STREAM_HAS_TAR_ZSTD
#define XXFC_STREAM_HAS_TAR_ZSTD 1
#endif
#ifndef XXFC_STREAM_HAS_XORARCHIVE
#define XXFC_STREAM_HAS_XORARCHIVE 1
#endif
#ifndef XXFC_STREAM_HAS_XZ
#define XXFC_STREAM_HAS_XZ 1
#endif
#ifndef XXFC_STREAM_HAS_ZIP
#define XXFC_STREAM_HAS_ZIP 1
#endif
#ifndef XXFC_STREAM_HAS_DOTNET
#define XXFC_STREAM_HAS_DOTNET 1
#endif
#ifndef XXFC_STREAM_HAS_ELF
#define XXFC_STREAM_HAS_ELF 1
#endif
#ifndef XXFC_STREAM_HAS_LE
#define XXFC_STREAM_HAS_LE 1
#endif
#ifndef XXFC_STREAM_HAS_LX
#define XXFC_STREAM_HAS_LX 1
#endif
#ifndef XXFC_STREAM_HAS_MACHO
#define XXFC_STREAM_HAS_MACHO 1
#endif
#ifndef XXFC_STREAM_HAS_NE
#define XXFC_STREAM_HAS_NE 1
#endif
#ifndef XXFC_STREAM_HAS_OMF
#define XXFC_STREAM_HAS_OMF 1
#endif
#ifndef XXFC_STREAM_HAS_PE
#define XXFC_STREAM_HAS_PE 1
#endif
#ifndef XXFC_STREAM_HAS_PEF
#define XXFC_STREAM_HAS_PEF 1
#endif
#ifndef XXFC_STREAM_HAS_XTAC
#define XXFC_STREAM_HAS_XTAC 1
#endif
#ifndef XXFC_STREAM_HAS_VXWORKS
#define XXFC_STREAM_HAS_VXWORKS 1
#endif
#ifndef XXFC_STREAM_HAS_SCHEMA
#define XXFC_STREAM_HAS_SCHEMA 1
#endif

#if XXFC_ENABLE_STREAM_DATASTRUCTS && XXFC_STREAM_HAS_ZIP && XXFC_STREAM_HAS_XORARCHIVE
/* XORARCHIVE embeds either ZIP or ARJ. Its native ZIP table describes the
 * decoded device already installed by the reader, without opening a cursor. */
#include "xxfclib/formats/archive/xorarchive/xx_xorarchive.h"
#endif

#if XXFC_STREAM_HAS_PE && (XXFC_ENABLE_STREAM_DATASTRUCTS || XXFC_ENABLE_STREAM_IMPORT || XXFC_ENABLE_STREAM_EXPORT || XXFC_ENABLE_STREAM_RESOURCES || XXFC_ENABLE_STREAM_METADATA || XXFC_ENABLE_STREAM_SYMBOLS)
extern bool xx_pe_handle_base_info(Abstractformat *format, xx_pd_struct *pd);
#endif
#if XXFC_STREAM_HAS_ELF && (XXFC_ENABLE_STREAM_DATASTRUCTS || XXFC_ENABLE_STREAM_RESOURCES || XXFC_ENABLE_STREAM_SYMBOLS)
extern bool xx_elf_handle_base_info(Abstractformat *format, xx_pd_struct *pd);
#endif
#if XXFC_STREAM_HAS_MACHO && (XXFC_ENABLE_STREAM_DATASTRUCTS)
extern bool xx_macho_handle_base_info(Abstractformat *format, xx_pd_struct *pd);
#endif
#if XXFC_STREAM_HAS_DOTNET && (XXFC_ENABLE_STREAM_DATASTRUCTS)
extern bool xx_dotnet_handle_base_info(Abstractformat *format, xx_pd_struct *pd);
#endif

#if XXFC_ENABLE_STREAM_DATASTRUCTS
#if XXFC_STREAM_HAS_7ZIP
extern const StreamDataStructs *xx_7zip_get_stream_datastructs(void);
#endif
#if XXFC_STREAM_HAS_AR
extern const StreamDataStructs *xx_ar_get_stream_datastructs(void);
#endif
#if XXFC_STREAM_HAS_BZ2
extern const StreamDataStructs *xx_bz2_get_stream_datastructs(void);
#endif
#if XXFC_STREAM_HAS_GZ
extern const StreamDataStructs *xx_gz_get_stream_datastructs(void);
#endif
#if XXFC_STREAM_HAS_RAR
extern const StreamDataStructs *xx_rar_get_stream_datastructs(void);
#endif
#if XXFC_STREAM_HAS_TAR
extern const StreamDataStructs *xx_tar_get_stream_datastructs(void);
#endif
#if XXFC_STREAM_HAS_TAR_BZ2
extern const StreamDataStructs *xx_tar_bz2_get_stream_datastructs(void);
#endif
#if XXFC_STREAM_HAS_TAR_GZ
extern const StreamDataStructs *xx_tar_gz_get_stream_datastructs(void);
#endif
#if XXFC_STREAM_HAS_TAR_LZ4
extern const StreamDataStructs *xx_tar_lz4_get_stream_datastructs(void);
#endif
#if XXFC_STREAM_HAS_TAR_XZ
extern const StreamDataStructs *xx_tar_xz_get_stream_datastructs(void);
#endif
#if XXFC_STREAM_HAS_TAR_ZSTD
extern const StreamDataStructs *xx_tar_zstd_get_stream_datastructs(void);
#endif
#if XXFC_STREAM_HAS_XZ
extern const StreamDataStructs *xx_xz_get_stream_datastructs(void);
#endif
#if XXFC_STREAM_HAS_ZIP
extern const StreamDataStructs *xx_zip_get_stream_datastructs(void);
#endif
#if XXFC_STREAM_HAS_DOTNET
extern const StreamDataStructs *xx_dotnet_get_stream_datastructs(void);
#endif
#if XXFC_STREAM_HAS_ELF
extern const StreamDataStructs *xx_elf_get_stream_datastructs(void);
#endif
#if XXFC_STREAM_HAS_LE
extern const StreamDataStructs *xx_le_get_stream_datastructs(void);
#endif
#if XXFC_STREAM_HAS_MACHO
extern const StreamDataStructs *xx_macho_get_stream_datastructs(void);
#endif
#if XXFC_STREAM_HAS_NE
extern const StreamDataStructs *xx_ne_get_stream_datastructs(void);
#endif
#if XXFC_STREAM_HAS_PE
extern const StreamDataStructs *xx_pe_get_stream_datastructs(void);
#endif
#if XXFC_STREAM_HAS_SCHEMA
extern const StreamDataStructs *xx_format_schema_get_stream_datastructs(Abstractformat *format);
#endif
#endif

#if XXFC_ENABLE_STREAM_IMPORT
#if XXFC_STREAM_HAS_LE
extern const StreamImport *xx_le_get_stream_import(void);
#endif
#if XXFC_STREAM_HAS_LX
extern const StreamImport *xx_lx_get_stream_import(void);
#endif
#if XXFC_STREAM_HAS_NE
extern const StreamImport *xx_ne_get_stream_import(void);
#endif
#if XXFC_STREAM_HAS_PE
extern const StreamImport *xx_pe_get_stream_import(void);
#endif
#if XXFC_STREAM_HAS_PEF
extern const StreamImport *xx_pef_get_stream_import(void);
#endif
#endif

#if XXFC_ENABLE_STREAM_EXPORT
#if XXFC_STREAM_HAS_LE
extern const StreamExport *xx_le_get_stream_export(void);
#endif
#if XXFC_STREAM_HAS_LX
extern const StreamExport *xx_lx_get_stream_export(void);
#endif
#if XXFC_STREAM_HAS_NE
extern const StreamExport *xx_ne_get_stream_export(void);
#endif
#if XXFC_STREAM_HAS_PE
extern const StreamExport *xx_pe_get_stream_export(void);
#endif
#endif

#if XXFC_ENABLE_STREAM_RESOURCES
#if XXFC_STREAM_HAS_LE
extern const StreamResources *xx_le_get_stream_resources(void);
#endif
#if XXFC_STREAM_HAS_LX
extern const StreamResources *xx_lx_get_stream_resources(void);
#endif
#if XXFC_STREAM_HAS_NE
extern const StreamResources *xx_ne_get_stream_resources(void);
#endif
#if XXFC_STREAM_HAS_PE
extern const StreamResources *xx_pe_get_stream_resources(void);
#endif
#if XXFC_STREAM_HAS_ELF
extern const StreamResources *xx_elf_get_stream_resources(void);
#endif
#endif

#if XXFC_ENABLE_STREAM_METADATA
#if XXFC_STREAM_HAS_VXWORKS
extern const StreamMetadata *xx_vxworks_get_stream_metadata(void);
#endif
#if XXFC_STREAM_HAS_PE
extern const StreamMetadata *xx_pe_get_stream_metadata(void);
#endif
#endif

#if XXFC_ENABLE_STREAM_SYMBOLS
#if XXFC_STREAM_HAS_PE
extern const StreamSymbols *xx_pe_get_stream_symbols(void);
#endif
#if XXFC_STREAM_HAS_ELF
extern const StreamSymbols *xx_elf_get_stream_symbols(void);
#endif
#if XXFC_STREAM_HAS_OMF
extern const StreamSymbols *xx_omf_get_stream_symbols(void);
#endif
#if XXFC_STREAM_HAS_XTAC
extern const StreamSymbols *xx_xtac_get_stream_symbols(void);
#endif
#endif

const StreamDataStructs *xx_format_get_stream_datastructs(Abstractformat *format)
{
#if XXFC_ENABLE_STREAM_DATASTRUCTS
    if (!format) return NULL;
#if XXFC_STREAM_HAS_DOTNET
    if (format->handle_base_info == xx_dotnet_handle_base_info) return xx_dotnet_get_stream_datastructs();
#endif
#if XXFC_STREAM_HAS_PE
    if (format->handle_base_info == xx_pe_handle_base_info) return xx_pe_get_stream_datastructs();
#endif
#if XXFC_STREAM_HAS_ELF
    if (format->handle_base_info == xx_elf_handle_base_info) return xx_elf_get_stream_datastructs();
#endif
#if XXFC_STREAM_HAS_MACHO
    if (format->handle_base_info == xx_macho_handle_base_info) return xx_macho_get_stream_datastructs();
#endif
    switch (format->file_type) {
#if XXFC_STREAM_HAS_7ZIP
    case XX_FILE_TYPE_7ZIP:
        return xx_7zip_get_stream_datastructs();
#endif
#if XXFC_STREAM_HAS_AR
    case XX_FILE_TYPE_AR:
        return xx_ar_get_stream_datastructs();
#endif
#if XXFC_STREAM_HAS_BZ2
    case XX_FILE_TYPE_BZ2:
        return xx_bz2_get_stream_datastructs();
#endif
#if XXFC_STREAM_HAS_GZ
    case XX_FILE_TYPE_GZ:
        return xx_gz_get_stream_datastructs();
#endif
#if XXFC_STREAM_HAS_RAR
    case XX_FILE_TYPE_RAR:
        return xx_rar_get_stream_datastructs();
#endif
#if XXFC_STREAM_HAS_TAR
    case XX_FILE_TYPE_TAR:
        return xx_tar_get_stream_datastructs();
#endif
#if XXFC_STREAM_HAS_TAR_BZ2
    case XX_FILE_TYPE_TAR_BZ2:
        return xx_tar_bz2_get_stream_datastructs();
#endif
#if XXFC_STREAM_HAS_TAR_GZ
    case XX_FILE_TYPE_TAR_GZ:
    case XX_FILE_TYPE_NPM:
        return xx_tar_gz_get_stream_datastructs();
#endif
#if XXFC_STREAM_HAS_TAR_LZ4
    case XX_FILE_TYPE_TAR_LZ4:
        return xx_tar_lz4_get_stream_datastructs();
#endif
#if XXFC_STREAM_HAS_TAR_XZ
    case XX_FILE_TYPE_TAR_XZ:
        return xx_tar_xz_get_stream_datastructs();
#endif
#if XXFC_STREAM_HAS_TAR_ZSTD
    case XX_FILE_TYPE_TAR_ZSTD:
        return xx_tar_zstd_get_stream_datastructs();
#endif
#if XXFC_STREAM_HAS_XZ
    case XX_FILE_TYPE_XZ:
        return xx_xz_get_stream_datastructs();
#endif
#if XXFC_STREAM_HAS_ZIP
    case XX_FILE_TYPE_ZIP:
    case XX_FILE_TYPE_ZIP64:
    case XX_FILE_TYPE_JAR:
    case XX_FILE_TYPE_APK:
    case XX_FILE_TYPE_IPA:
    case XX_FILE_TYPE_APKS:
    case XX_FILE_TYPE_ZIP_PSC:
    case XX_FILE_TYPE_CRX:
        return xx_zip_get_stream_datastructs();
#endif
#if XXFC_STREAM_HAS_DOTNET
    case XX_FILE_TYPE_DOTNET:
        return xx_dotnet_get_stream_datastructs();
#endif
#if XXFC_STREAM_HAS_ELF
    case XX_FILE_TYPE_ELF32:
    case XX_FILE_TYPE_ELF64:
        return xx_elf_get_stream_datastructs();
#endif
#if XXFC_STREAM_HAS_LE
    case XX_FILE_TYPE_LE:
    case XX_FILE_TYPE_LX:
        return xx_le_get_stream_datastructs();
#endif
#if XXFC_STREAM_HAS_MACHO
    case XX_FILE_TYPE_MACHO32:
    case XX_FILE_TYPE_MACHO64:
        return xx_macho_get_stream_datastructs();
#endif
#if XXFC_STREAM_HAS_NE
    case XX_FILE_TYPE_NE:
        return xx_ne_get_stream_datastructs();
#endif
#if XXFC_STREAM_HAS_PE
    case XX_FILE_TYPE_PE32:
    case XX_FILE_TYPE_PE64:
        return xx_pe_get_stream_datastructs();
#endif
#if XXFC_STREAM_HAS_ZIP && XXFC_STREAM_HAS_XORARCHIVE
    case XX_FILE_TYPE_XORARCHIVE:
        /* A file-type tag alone does not guarantee a concrete reader allocation. */
        if (format->handle_base_info == xx_xorarchive_handle_base_info &&
            ((const xx_xorarchive *)format)->family == XX_XORARCHIVE_FAMILY_ZIP)
            return xx_zip_get_stream_datastructs();
        break;
#endif
    default:
        break;
    }
#if XXFC_STREAM_HAS_SCHEMA
    return xx_format_schema_get_stream_datastructs(format);
#else
    return NULL;
#endif
#else
    (void)format;
    return NULL;
#endif
}

const StreamImport *xx_format_get_stream_import(Abstractformat *format)
{
#if XXFC_ENABLE_STREAM_IMPORT
    if (!format) return NULL;
#if XXFC_STREAM_HAS_PE
    if (format->handle_base_info == xx_pe_handle_base_info) return xx_pe_get_stream_import();
#endif
    switch (format->file_type) {
#if XXFC_STREAM_HAS_LE
    case XX_FILE_TYPE_LE:
        return xx_le_get_stream_import();
#endif
#if XXFC_STREAM_HAS_LX
    case XX_FILE_TYPE_LX:
        return xx_lx_get_stream_import();
#endif
#if XXFC_STREAM_HAS_NE
    case XX_FILE_TYPE_NE:
        return xx_ne_get_stream_import();
#endif
#if XXFC_STREAM_HAS_PE
    case XX_FILE_TYPE_PE32:
    case XX_FILE_TYPE_PE64:
    case XX_FILE_TYPE_DOTNET:
        return xx_pe_get_stream_import();
#endif
#if XXFC_STREAM_HAS_PEF
    case XX_FILE_TYPE_PEF:
        return xx_pef_get_stream_import();
#endif
    default:
        break;
    }
    return NULL;
#else
    (void)format;
    return NULL;
#endif
}

const StreamExport *xx_format_get_stream_export(Abstractformat *format)
{
#if XXFC_ENABLE_STREAM_EXPORT
    if (!format) return NULL;
#if XXFC_STREAM_HAS_PE
    if (format->handle_base_info == xx_pe_handle_base_info) return xx_pe_get_stream_export();
#endif
    switch (format->file_type) {
#if XXFC_STREAM_HAS_LE
    case XX_FILE_TYPE_LE:
        return xx_le_get_stream_export();
#endif
#if XXFC_STREAM_HAS_LX
    case XX_FILE_TYPE_LX:
        return xx_lx_get_stream_export();
#endif
#if XXFC_STREAM_HAS_NE
    case XX_FILE_TYPE_NE:
        return xx_ne_get_stream_export();
#endif
#if XXFC_STREAM_HAS_PE
    case XX_FILE_TYPE_PE32:
    case XX_FILE_TYPE_PE64:
    case XX_FILE_TYPE_DOTNET:
        return xx_pe_get_stream_export();
#endif
    default:
        break;
    }
    return NULL;
#else
    (void)format;
    return NULL;
#endif
}

const StreamResources *xx_format_get_stream_resources(Abstractformat *format)
{
#if XXFC_ENABLE_STREAM_RESOURCES
    if (!format) return NULL;
#if XXFC_STREAM_HAS_PE
    if (format->handle_base_info == xx_pe_handle_base_info) return xx_pe_get_stream_resources();
#endif
#if XXFC_STREAM_HAS_ELF
    if (format->handle_base_info == xx_elf_handle_base_info) return xx_elf_get_stream_resources();
#endif
    switch (format->file_type) {
#if XXFC_STREAM_HAS_LE
    case XX_FILE_TYPE_LE:
        return xx_le_get_stream_resources();
#endif
#if XXFC_STREAM_HAS_LX
    case XX_FILE_TYPE_LX:
        return xx_lx_get_stream_resources();
#endif
#if XXFC_STREAM_HAS_NE
    case XX_FILE_TYPE_NE:
        return xx_ne_get_stream_resources();
#endif
#if XXFC_STREAM_HAS_PE
    case XX_FILE_TYPE_PE32:
    case XX_FILE_TYPE_PE64:
    case XX_FILE_TYPE_DOTNET:
        return xx_pe_get_stream_resources();
#endif
#if XXFC_STREAM_HAS_ELF
    case XX_FILE_TYPE_ELF32:
    case XX_FILE_TYPE_ELF64:
        return xx_elf_get_stream_resources();
#endif
    default:
        break;
    }
    return NULL;
#else
    (void)format;
    return NULL;
#endif
}

const StreamMetadata *xx_format_get_stream_metadata(Abstractformat *format)
{
#if XXFC_ENABLE_STREAM_METADATA
    if (!format) return NULL;
#if XXFC_STREAM_HAS_PE
    if (format->handle_base_info == xx_pe_handle_base_info) return xx_pe_get_stream_metadata();
#endif
    switch (format->file_type) {
#if XXFC_STREAM_HAS_VXWORKS
    case XX_FILE_TYPE_VXWORKS:
        return xx_vxworks_get_stream_metadata();
#endif
#if XXFC_STREAM_HAS_PE
    case XX_FILE_TYPE_PE32:
    case XX_FILE_TYPE_PE64:
    case XX_FILE_TYPE_DOTNET:
        return xx_pe_get_stream_metadata();
#endif
    default:
        break;
    }
    return NULL;
#else
    (void)format;
    return NULL;
#endif
}

const StreamSymbols *xx_format_get_stream_symbols(Abstractformat *format)
{
#if XXFC_ENABLE_STREAM_SYMBOLS
    if (!format) return NULL;
#if XXFC_STREAM_HAS_PE
    if (format->handle_base_info == xx_pe_handle_base_info) return xx_pe_get_stream_symbols();
#endif
#if XXFC_STREAM_HAS_ELF
    if (format->handle_base_info == xx_elf_handle_base_info) return xx_elf_get_stream_symbols();
#endif
    switch (format->file_type) {
#if XXFC_STREAM_HAS_PE
    case XX_FILE_TYPE_PE32:
    case XX_FILE_TYPE_PE64:
    case XX_FILE_TYPE_DOTNET:
        return xx_pe_get_stream_symbols();
#endif
#if XXFC_STREAM_HAS_ELF
    case XX_FILE_TYPE_ELF32:
    case XX_FILE_TYPE_ELF64:
        return xx_elf_get_stream_symbols();
#endif
#if XXFC_STREAM_HAS_OMF
    case XX_FILE_TYPE_OMF:
        return xx_omf_get_stream_symbols();
#endif
#if XXFC_STREAM_HAS_XTAC
    case XX_FILE_TYPE_XTAC:
        return xx_xtac_get_stream_symbols();
#endif
    default:
        break;
    }
    return NULL;
#else
    (void)format;
    return NULL;
#endif
}

bool xx_format_has_data_structs(Abstractformat *format)
{
    const StreamDataStructs *stream = xx_format_get_stream_datastructs(format);
    return stream && stream->create_data_structs_reading && stream->data_struct_move_to_next;
}
