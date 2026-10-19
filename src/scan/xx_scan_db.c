/* Copyright (c) 2026 hors<horsicq@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/* xx_scan_db.c - loads the Detect It Easy signature database from a directory tree.
 *
 * The layout mirrors the original engine: the database root holds shared
 * include scripts (file type "unknown") and one subdirectory per format.
 * Only regular files with the ".sg" extension or no extension at all are
 * treated as signatures, and subdirectories below a format directory are
 * ignored - exactly like XScanEngine::_loadDatabaseFromPath.              */

#include "xxfclib/scan/xx_scan.h"
#include "../sort/xx_sort_scan_internal.h"
#include "xxfclib/js/xx_js.h"
#include "../die_engine/xx_die_engine_compat.h"
#include "xxfclib/algo/deflate/xx_deflate.h"
#include "xxfclib/fs/xx_fs.h"
#include "xxfclib/list/xx_list.h"
#include "xxfclib/strings/xx_string.h"

static const struct {
    const char *pDirectory;
    XFileType fileType;
} g_directories[] = {{"", XFT_UNKNOWN},
                     {"Binary", XFT_BINARY},
                     {"COM", XFT_COM},
                     {"Archive", XFT_ARCHIVE},
                     {"ZIP", XFT_ZIP},
                     {"JAR", XFT_JAR},
                     {"APK", XFT_APK},
                     {"IPA", XFT_IPA},
                     {"NPM", XFT_NPM},
                     {"MACHOFAT", XFT_MACHOFAT},
                     {"DEX", XFT_DEX},
                     {"MSDOS", XFT_MSDOS},
                     {"LE", XFT_LE},
                     {"LX", XFT_LX},
                     {"NE", XFT_NE},
                     {"PE", XFT_PE},
                     {"PE/DOTNET", XFT_CLI_ASSEMBLY},
                     {"ELF", XFT_ELF},
                     {"MACH", XFT_MACHO},
                     {"DOS16M", XFT_DOS16M},
                     {"DOS4G", XFT_DOS4G},
                     {"Amiga", XFT_AMIGAHUNK},
                     {"AtariST", XFT_ATARIST},
                     {"JavaClass", XFT_JAVACLASS},
                     {"PYC", XFT_PYC},
                     {"PDF", XFT_PDF},
                     {"CFBF", XFT_CFBF},
                     {"Image", XFT_IMAGE},
                     {"JPEG", XFT_JPEG},
                     {"PNG", XFT_PNG},
                     {"RAR", XFT_RAR},
                     {"ISO9660", XFT_ISO9660},
                     {NULL, XFT_UNKNOWN}};

/* QDir's default Name | IgnoreCase order is also used by the reference TAR
 * loader. Establish that input order before its pair-dependent priority sort. */
static int db_directory_order(XFileType fileType)
{
    int i;
    for (i = 0; g_directories[i].pDirectory; ++i) {
        if (g_directories[i].fileType == fileType) return i;
    }
    return i;
}

static void db_sort_loaded_records(DBase *pDb, int nBefore, DBKind kind)
{
    int i;
    DBase added = {0};

    /* An unused C-only extra database must not reorder the main database. */
    if (nBefore == pDb->nCount && kind == DB_EXTRA) return;

    for (i = nBefore + 1; i < pDb->nCount; ++i) {
        DBSignature value = pDb->pRecords[i];
        int order = db_directory_order(value.fileType);
        int hole = i;
        while (hole > nBefore) {
            DBSignature *previous = &pDb->pRecords[hole - 1];
            int previousOrder = db_directory_order(previous->fileType);
            if (previousOrder < order ||
                (previousOrder == order && cd_stricmp_ascii(previous->pName, value.pName) <= 0)) break;
            pDb->pRecords[hole] = *previous;
            --hole;
        }
        pDb->pRecords[hole] = value;
    }

    if (pDb->nCount > nBefore) {
        added.pRecords = pDb->pRecords + nBefore;
        added.nCount = pDb->nCount - nBefore;
        xx_scan_sort_database_records(&added);
    }
    /* loadDatabase sorts the newly loaded list, appends it, and sorts the
     * complete list once more, even for an existing empty custom directory. */
    xx_scan_sort_database_records(pDb);
}

static int is_signature_file(const char *pPath)
{
    char *pSuffix = NULL;
    int bResult = 0;

    if (!xx_fs_is_file(pPath)) {
        return 0;
    }

    pSuffix = xx_fs_path_suffix(pPath);

    if (pSuffix == NULL) {
        return 0;
    }

    bResult = ((pSuffix[0] == 0) || (cd_stricmp_ascii(pSuffix, "sg") == 0)) ? 1 : 0;
    xx_str_free(pSuffix);

    return bResult;
}

static int is_signature_name(const char *pName)
{
    const char *pDot = NULL;

    if (!pName || !pName[0]) {
        return 0;
    }

    pDot = xx_rt_strrchr(pName, '.');
    if (!pDot) {
        return 1; /* No extension: _init, _runtime_helpers, read, etc. */
    }

    return (cd_stricmp_ascii(pDot + 1, "sg") == 0) ? 1 : 0;
}

static void db_add(DBase *pDb, const char *pName, const char *pPath, char *pText, size_t nSize, XFileType fileType, DBKind kind)
{
    DBSignature *pRecord = NULL;

    if (pDb->nCount + 1 > pDb->nCapacity) {
        pDb->nCapacity = pDb->nCapacity ? (pDb->nCapacity * 2) : 256;
        pDb->pRecords = (DBSignature *)cd_realloc(pDb->pRecords, (size_t)pDb->nCapacity * sizeof(DBSignature));
    }

    pRecord = &pDb->pRecords[pDb->nCount++];
    pRecord->pName = cd_strdup(pName);
    pRecord->pFilePath = cd_strdup(pPath);
    pRecord->pText = pText;
    pRecord->nSize = nSize;
    pRecord->fileType = fileType;
    pRecord->databaseType = kind;
    pRecord->nElapsedTime = 0;
}

static void db_load_directory(DBase *pDb, const char *pPath, XFileType fileType, DBKind kind)
{
    xx_list_t list;
    size_t nCount = 0;
    size_t i = 0;

    if (!xx_list_init(&list, sizeof(xx_fs_entry_t *), NULL)) {
        return;
    }

    /* Name order, not the directories-first order xx_fs_list_dir gives: the
     * reference loads the signature files in the directory's own name order
     * and that order decides which of two scripts claiming the same file
     * wins. */
    if (!xx_fs_list_dir_sorted(pPath, &list, XX_FS_SORT_NAME)) {
        nCount = xx_list_count(&list);

        for (i = 0; i < nCount; i++) {
            xx_fs_entry_free(*(xx_fs_entry_t **)xx_list_at(&list, i));
        }

        xx_list_cleanup(&list);

        return;
    }

    nCount = xx_list_count(&list);

    for (i = 0; i < nCount; i++) {
        xx_fs_entry_t *pEntry = *(xx_fs_entry_t **)xx_list_at(&list, i);

        if (pEntry == NULL) {
            continue;
        }

        if (is_signature_file(pEntry->path)) {
            int64_t nSize = 0;
            char *pText = xx_fs_read_file(pEntry->path, &nSize);

            if (pText) {
                /* db_add copies the name and path but takes the text, and the
                 * record is released with cd_free. Hand it a cd_malloc block
                 * rather than relying on the two allocators coinciding. */
                char *pOwned = cd_strndup(pText, (size_t)nSize);

                xx_str_free(pText);
                db_add(pDb, pEntry->name, pEntry->path, pOwned, (size_t)nSize, fileType, kind);
            }
        }

        xx_fs_entry_free(pEntry);
    }

    xx_list_cleanup(&list);
}

/* ------------------------------------------------------------- tar utils  */

static uint64_t tar_parse_octal(const char *p, size_t n)
{
    uint64_t val = 0;
    while (n && (*p == ' ' || *p == '\0')) {
        p++;
        n--;
    }
    while (n && (*p >= '0' && *p <= '7')) {
        val = (val << 3) + (uint64_t)(*p - '0');
        p++;
        n--;
    }
    return val;
}

static int tar_write_header(xx_io_device *pFile, const char *pName, size_t nSize)
{
    char header[512];
    size_t i;
    unsigned int nChkSum = 0;

    x_memset(header, 0, sizeof(header));

    xx_rt_strncpy(header, pName, 100);
    xx_rt_snprintf(&header[100], 8, "%07o", 0644);
    xx_rt_snprintf(&header[108], 8, "%07o", 0);
    xx_rt_snprintf(&header[116], 8, "%07o", 0);
    xx_rt_snprintf(&header[124], 12, "%011llo", (unsigned long long)nSize);
    xx_rt_snprintf(&header[136], 12, "%011llo", (unsigned long long)0);

    for (i = 0; i < 8; i++) {
        header[148 + i] = ' ';
    }

    header[156] = '0';
    x_memcpy(&header[257], "ustar\0", 6);
    x_memcpy(&header[263], "00", 2);

    for (i = 0; i < 512; i++) {
        nChkSum += (unsigned char)header[i];
    }

    xx_rt_snprintf(&header[148], 8, "%06o", nChkSum);
    header[154] = '\0';
    header[155] = ' ';

    return (xx_io_write(pFile, header, 512) == 512) ? 1 : 0;
}

static int tar_write_data(xx_io_device *pFile, const void *pData, size_t nSize)
{
    static const char zeroes[512] = {0};
    size_t nPad = (512 - (nSize % 512)) % 512;

    if (nSize > 0) {
        if (xx_io_write(pFile, pData, nSize) != (ssize_t)nSize) {
            return 0;
        }
    }
    if (nPad > 0) {
        if (xx_io_write(pFile, zeroes, nPad) != (ssize_t)nPad) {
            return 0;
        }
    }
    return 1;
}

static int tar_write_end(xx_io_device *pFile)
{
    static const char zeroes[1024] = {0};
    return (xx_io_write(pFile, zeroes, sizeof(zeroes)) == (ssize_t)sizeof(zeroes)) ? 1 : 0;
}

static int tar_strnicmp_ascii(const char *pLeft, const char *pRight, size_t n)
{
    while (n > 0) {
        char a = *pLeft++;
        char b = *pRight++;
        if (a >= 'a' && a <= 'z') a = (char)(a - 'a' + 'A');
        if (b >= 'a' && b <= 'z') b = (char)(b - 'a' + 'A');
        if (a != b) {
            return (a < b) ? -1 : 1;
        }
        if (a == '\0') {
            break;
        }
        n--;
    }
    return 0;
}

static XFileType file_type_from_tar_path(const char *pTarPath, const char **ppBaseName)
{
    const char *pDirStart = pTarPath;
    const char *pSlash = NULL;
    int i = 0;
    size_t dirLen = 0;

    while (pDirStart[0] == '.' && (pDirStart[1] == '/' || pDirStart[1] == '\\')) {
        pDirStart += 2;
    }
    while (*pDirStart == '/' || *pDirStart == '\\') {
        pDirStart++;
    }

    pSlash = xx_rt_strrchr(pDirStart, '/');
    if (!pSlash) {
        pSlash = xx_rt_strrchr(pDirStart, '\\');
    }

    if (!pSlash) {
        if (ppBaseName) *ppBaseName = pDirStart;
        return XFT_UNKNOWN;
    }

    if (ppBaseName) *ppBaseName = pSlash + 1;

    dirLen = (size_t)(pSlash - pDirStart);

    /* 1. Exact directory match */
    for (i = 0; g_directories[i].pDirectory; i++) {
        size_t entryLen = 0;
        if (g_directories[i].pDirectory[0] == 0) continue;
        entryLen = xx_rt_strlen(g_directories[i].pDirectory);
        if ((dirLen == entryLen) && (tar_strnicmp_ascii(pDirStart, g_directories[i].pDirectory, dirLen) == 0)) {
            return g_directories[i].fileType;
        }
    }

    /* 2. Suffix directory match if archive has top-level prefix like "db/PE/..." */
    {
        const char *pFirstSlash = xx_rt_strchr(pDirStart, '/');
        if (!pFirstSlash) pFirstSlash = xx_rt_strchr(pDirStart, '\\');
        if (pFirstSlash && pFirstSlash < pSlash) {
            const char *pSub = pFirstSlash + 1;
            size_t subLen = (size_t)(pSlash - pSub);
            for (i = 0; g_directories[i].pDirectory; i++) {
                size_t entryLen = 0;
                if (g_directories[i].pDirectory[0] == 0) continue;
                entryLen = xx_rt_strlen(g_directories[i].pDirectory);
                if ((subLen == entryLen) && (tar_strnicmp_ascii(pSub, g_directories[i].pDirectory, subLen) == 0)) {
                    return g_directories[i].fileType;
                }
            }
        }
    }

    return XFT_UNKNOWN;
}

static int db_create_tar_internal(const char *pDbPath, const char *pTarPath, int bPrecompile)
{
    xx_io_device *pTar = NULL;
    JSCtx *pJs = NULL;
    int i = 0;

    if (!pDbPath || !pTarPath || !xx_fs_is_dir(pDbPath)) {
        return 0;
    }

    pTar = xx_io_file_open(pTarPath, "wb");
    if (!pTar) {
        return 0;
    }

    if (bPrecompile) {
        pJs = js_new();
    }

    for (i = 0; g_directories[i].pDirectory; i++) {
        char *pDirPath = NULL;
        xx_list_t list;
        size_t nCount = 0;
        size_t j = 0;

        if (g_directories[i].pDirectory[0] == 0) {
            pDirPath = cd_strdup(pDbPath);
        } else {
            pDirPath = xx_fs_path_join(pDbPath, g_directories[i].pDirectory);
        }

        if (!pDirPath || !xx_fs_is_dir(pDirPath)) {
            cd_free(pDirPath);
            continue;
        }

        if (!xx_list_init(&list, sizeof(xx_fs_entry_t *), NULL)) {
            cd_free(pDirPath);
            continue;
        }

        if (xx_fs_list_dir_sorted(pDirPath, &list, XX_FS_SORT_NAME)) {
            nCount = xx_list_count(&list);
            for (j = 0; j < nCount; j++) {
                xx_fs_entry_t *pEntry = *(xx_fs_entry_t **)xx_list_at(&list, j);
                if (pEntry && is_signature_file(pEntry->path)) {
                    int64_t nFileSize = 0;
                    char *pText = xx_fs_read_file(pEntry->path, &nFileSize);
                    if (pText && nFileSize >= 0) {
                        char sRelPath[256];
                        char *pC = NULL;

                        if (g_directories[i].pDirectory[0] == 0) {
                            xx_rt_strncpy(sRelPath, pEntry->name, sizeof(sRelPath) - 1);
                        } else {
                            xx_rt_snprintf(sRelPath, sizeof(sRelPath), "%s/%s", g_directories[i].pDirectory, pEntry->name);
                        }
                        sRelPath[sizeof(sRelPath) - 1] = '\0';

                        for (pC = sRelPath; *pC; pC++) {
                            if (*pC == '\\') *pC = '/';
                        }

                        if (bPrecompile && pJs && is_signature_name(pEntry->name)) {
                            size_t nBcSize = 0;
                            void *pBc = js_compile_to_bytecode(pJs, pText, pEntry->name, &nBcSize);
                            if (pBc && nBcSize > 0) {
                                tar_write_header(pTar, sRelPath, nBcSize);
                                tar_write_data(pTar, pBc, nBcSize);
                                xx_rt_free(pBc);
                            } else {
                                tar_write_header(pTar, sRelPath, (size_t)nFileSize);
                                tar_write_data(pTar, pText, (size_t)nFileSize);
                            }
                        } else {
                            tar_write_header(pTar, sRelPath, (size_t)nFileSize);
                            tar_write_data(pTar, pText, (size_t)nFileSize);
                        }

                        xx_str_free(pText);
                    }
                }
                if (pEntry) {
                    xx_fs_entry_free(pEntry);
                }
            }
        }

        xx_list_cleanup(&list);
        cd_free(pDirPath);
    }

    tar_write_end(pTar);
    xx_io_close(pTar);

    if (pJs) {
        js_free(pJs);
    }

    return 1;
}

int db_create_tar(const char *pDbPath, const char *pTarPath)
{
    return db_create_tar_internal(pDbPath, pTarPath, 0);
}

int db_create_tar_precompiled(const char *pDbPath, const char *pTarPath)
{
    return db_create_tar_internal(pDbPath, pTarPath, 1);
}

#include "../die_engine/xx_die_audio_bundle.inc"

static int db_load_builtin_audio_subset(DBase *pDb, DBKind kind, int bMusicOnly)
{
    int nBefore;
    size_t i;

    if (!pDb) return 0;
    nBefore = pDb->nCount;
    for (i = 0; i < sizeof(xx_die_audio_entries) / sizeof(xx_die_audio_entries[0]); i++) {
        const xx_die_audio_entry *entry = &xx_die_audio_entries[i];
        const char *name = xx_rt_strrchr(entry->path, '/');
        char *text;
        size_t size = 0;

        if (bMusicOnly && entry->file_type == XFT_BINARY && x_strcmp(entry->path, "Binary/_init") != 0 && x_strcmp(entry->path, "Binary/audio.1.sg") != 0) continue;
        if (entry->original_size == SIZE_MAX || entry->compressed_size == 0) break;
        text = (char *)cd_malloc(entry->original_size + 1U);
        if (!xx_deflate_decompress_memory(entry->deflated, entry->compressed_size, text, entry->original_size, &size, false) || size != entry->original_size) {
            cd_free(text);
            break;
        }
        text[size] = '\0';
        db_add(pDb, name ? name + 1 : entry->path, entry->path, text, size, entry->file_type, kind);
    }
    if (i != sizeof(xx_die_audio_entries) / sizeof(xx_die_audio_entries[0])) {
        while (pDb->nCount > nBefore) {
            DBSignature *record = &pDb->pRecords[--pDb->nCount];
            cd_free(record->pName);
            cd_free(record->pFilePath);
            cd_free(record->pText);
        }
        return 0;
    }
    xx_scan_sort_database_records(pDb);
    return 1;
}

int db_load_builtin_audio(DBase *pDb, DBKind kind)
{
    return db_load_builtin_audio_subset(pDb, kind, 0);
}

int db_load_builtin_music(DBase *pDb, DBKind kind)
{
    return db_load_builtin_audio_subset(pDb, kind, 1);
}

int db_load_tar(DBase *pDb, const char *pTarPath, DBKind kind)
{
    xx_io_device *pFile = NULL;
    int nBefore = 0;
    char header[512];

    if (!pDb || !pTarPath || !pTarPath[0]) {
        return 0;
    }

    pFile = xx_io_file_open(pTarPath, "rb");
    if (!pFile) {
        return 0;
    }

    nBefore = pDb->nCount;

    while (xx_io_read(pFile, header, 512) == 512) {
        uint64_t nSize = 0;
        char typeflag = 0;
        char sName[256];
        char *pC = NULL;
        char *pData = NULL;
        size_t nPad = 0;
        const char *pBaseName = NULL;
        XFileType fileType = XFT_UNKNOWN;

        if (header[0] == '\0') {
            break;
        }

        nSize = tar_parse_octal(&header[124], 12);
        typeflag = header[156];

        if (header[345] != '\0') {
            xx_rt_snprintf(sName, sizeof(sName), "%s/%s", &header[345], header);
        } else {
            xx_rt_strncpy(sName, header, 100);
            sName[100] = '\0';
        }
        sName[sizeof(sName) - 1] = '\0';

        for (pC = sName; *pC; pC++) {
            if (*pC == '\\') *pC = '/';
        }

        if (typeflag == '5') {
            continue;
        }

        pData = (char *)cd_malloc((size_t)nSize + 1);
        if (!pData) {
            break;
        }

        if (nSize > 0) {
            if (xx_io_read(pFile, pData, (size_t)nSize) != (ssize_t)nSize) {
                cd_free(pData);
                break;
            }
        }
        pData[nSize] = '\0';

        nPad = (512 - (nSize % 512)) % 512;
        if (nPad > 0) {
            xx_io_seek(pFile, (long)nPad, SEEK_CUR);
        }

        fileType = file_type_from_tar_path(sName, &pBaseName);

        if (is_signature_name(pBaseName)) {
            db_add(pDb, pBaseName, sName, pData, (size_t)nSize, fileType, kind);
        } else {
            cd_free(pData);
        }
    }

    xx_io_close(pFile);

    if (pDb->nCount > nBefore) db_sort_loaded_records(pDb, nBefore, kind);

    return (pDb->nCount > nBefore) ? 1 : 0;
}

int db_load(DBase *pDb, const char *pPath, DBKind kind)
{
    int i = 0;
    int nBefore = pDb->nCount;

    if ((pPath == NULL) || (pPath[0] == 0)) {
        return 0;
    }

    if (xx_fs_is_file(pPath)) {
        return db_load_tar(pDb, pPath, kind);
    }

    if (!xx_fs_is_dir(pPath)) {
        return 0;
    }

    for (i = 0; g_directories[i].pDirectory; i++) {
        if (g_directories[i].pDirectory[0] == 0) {
            db_load_directory(pDb, pPath, g_directories[i].fileType, kind);
        } else {
            /* Always a non-empty right side -- the empty entry takes the
             * branch above -- so xx_fs_path_join's rule of only inserting a
             * separator when there is something to separate never differs
             * here from cdie's of always inserting one. */
            char *pSubPath = xx_fs_path_join(pPath, g_directories[i].pDirectory);

            db_load_directory(pDb, pSubPath, g_directories[i].fileType, kind);
            xx_str_free(pSubPath);
        }
    }

    db_sort_loaded_records(pDb, nBefore, kind);

    return (pDb->nCount > nBefore) ? 1 : 0;
}

void db_free(DBase *pDb)
{
    int i = 0;

    for (i = 0; i < pDb->nCount; i++) {
        cd_free(pDb->pRecords[i].pName);
        cd_free(pDb->pRecords[i].pFilePath);
        cd_free(pDb->pRecords[i].pText);
    }

    cd_free(pDb->pRecords);
    x_memset(pDb, 0, sizeof(*pDb));
}

int db_count_for_type(DBase *pDb, XFileType fileType)
{
    int nResult = 0;
    int i = 0;

    for (i = 0; i < pDb->nCount; i++) {
        if ((x_strcmp(pDb->pRecords[i].pName, "_init") != 0) && xft_check(pDb->pRecords[i].fileType, fileType)) {
            nResult++;
        }
    }

    return nResult;
}
