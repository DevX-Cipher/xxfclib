/* Copyright (c) 2026 hors<horsicq@gmail.com>. SPDX-License-Identifier: MIT */
#ifndef XX_ARCHIVE_OUTPUT_NAME_H
#define XX_ARCHIVE_OUTPUT_NAME_H

/* Private filename boundary for legacy readers. Metadata retains the stored
 * name. Never consult the host locale: each reader supplies its wire charset.
 * %HH escapes are reversible (literal '%' and the generated-name marker '~'
 * are escaped too). Root stripping is an explicit reader policy, never the
 * default; a traversal component is rejected before any conversion. */
#include "xxfclib/codepages/xx_codepage.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/strings/xx_string.h"
#include <stdio.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#endif

#define XX_ARCHIVE_NAME_ROOTED 1U
#define XX_ARCHIVE_NAME_DRIVE 2U
#define XX_ARCHIVE_NAME_NATIVE_TAR 4U

static bool xx_archive_name_device(const char *s, size_t n)
{
    char b[9]; size_t i = 0;
    while (i < n && i < sizeof(b) - 1 && s[i] != '.') {
        unsigned char c = (unsigned char)s[i];
        b[i++] = (char)(c >= 'a' && c <= 'z' ? c - 32 : c);
    }
    while (i && (b[i - 1] == ' ' || b[i - 1] == '.')) --i;
    b[i] = 0;
    return !strcmp(b, "CON") || !strcmp(b, "PRN") || !strcmp(b, "AUX") || !strcmp(b, "NUL") ||
           !strcmp(b, "CLOCK$") || !strcmp(b, "CONIN$") || !strcmp(b, "CONOUT$") ||
           (i == 4 && (!memcmp(b, "COM", 3) || !memcmp(b, "LPT", 3)) && b[3] >= '1' && b[3] <= '9') ||
           (i == 5 && (!memcmp(b, "COM", 3) || !memcmp(b, "LPT", 3)) &&
               (unsigned char)b[3] == 0xc2 && ((unsigned char)b[4] == 0xb9 || (unsigned char)b[4] == 0xb2 || (unsigned char)b[4] == 0xb3));
}

static char *xx_archive_output_name(const char *raw, unsigned codepage, unsigned flags)
{
    const char *s = raw, *p, *start;
    char *out, *converted = NULL;
    size_t length, used, written, at = 0;
    bool converted_valid = true;
    const xx_codepage *utf8 = xx_codepage_by_number(65001), *cp = xx_codepage_by_number(codepage);
    static const char hex[] = "0123456789ABCDEF";
    if (!s || !*s) return NULL;
    /* UNC/device paths are never reinterpreted as archive-relative names. */
    if ((s[0] == '/' || s[0] == '\\') && (s[1] == '/' || s[1] == '\\')) return NULL;
    if (s[0] == '/' || s[0] == '\\') {
        if (!(flags & XX_ARCHIVE_NAME_ROOTED)) return NULL;
        ++s;
    }
    if (((s[0] >= 'A' && s[0] <= 'Z') || (s[0] >= 'a' && s[0] <= 'z')) && s[1] == ':') {
        if (!(flags & XX_ARCHIVE_NAME_DRIVE)) return NULL;
        s += 2;
        if (*s == '/' || *s == '\\') ++s;
    }
    for (start = p = s;; ++p) {
        unsigned char c = (unsigned char)*p;
        if (c && c < 32) return NULL;
        if (c == 127) return NULL;
        if (!c || c == '/' || c == '\\') {
            if (p - start == 2 && start[0] == '.' && start[1] == '.') return NULL;
            if (!c) break;
            start = p + 1;
        }
    }
    length = strlen(s);
    if (length > (SIZE_MAX - 4) / 12) return NULL;
    converted = (char *)xx_mem_alloc(length * 4 + 1);
    if (!converted) return NULL;
    /* A valid UTF-8 string wins over a historical single-byte fallback. */
    if (utf8 && xx_codepage_to_utf8(utf8, (const unsigned char *)s, length,
            (unsigned char *)converted, length * 4, &used, &written) == XX_CODEPAGE_OK) {
        converted[written] = 0;
    } else if (cp && xx_codepage_to_utf8(cp, (const unsigned char *)s, length,
            (unsigned char *)converted, length * 4, &used, &written) == XX_CODEPAGE_OK) {
        converted[written] = 0;
    } else {
        /* Unknown/undefined historical bytes remain distinguishable. */
        memcpy(converted, s, length + 1);
        converted_valid = false;
    }
    s = converted;
    length = strlen(s);
    out = (char *)xx_mem_alloc(length * 3 + 1);
    if (!out) { xx_mem_free(converted); return NULL; }
    for (start = p = s;; ++p) {
        if (!*p || *p == '/' || *p == '\\') {
            size_t n = (size_t)(p - start), i;
            if (n && !(n == 1 && start[0] == '.')) {
                bool device = xx_archive_name_device(start, n);
                if (at) out[at++] = '/';
                for (i = 0; i < n; ++i) {
                    unsigned char c = (unsigned char)start[i];
                    bool escape = !(flags & XX_ARCHIVE_NAME_NATIVE_TAR) && (c == '%' || c == '~');
#ifdef _WIN32
                    escape = escape || c == ':' || c == '<' || c == '>' || c == '"' || c == '|' || c == '?' || c == '*' ||
                        ((c == '.' || c == ' ') && i + 1 == n) || (device && i == 0);
#else
                    (void)device;
#endif
                    /* If neither codec accepted the name, escape high bytes. */
                    if (c >= 128 && !converted_valid) escape = true;
                    if (escape) { out[at++] = '%'; out[at++] = hex[c >> 4]; out[at++] = hex[c & 15]; }
                    else out[at++] = (char)c;
                }
            }
            if (!*p) break;
            start = p + 1;
        }
    }
    xx_mem_free(converted);
    out[at] = 0;
    if (!at) { xx_mem_free(out); return NULL; }
    return out;
}

static inline bool xx_archive_output_equal_prefix(const char *name, const char *other)
{
#ifdef _WIN32
    wchar_t *a = xx_str_utf8_to_unicode(name), *b = xx_str_utf8_to_unicode(other);
    size_t n = a ? xx_str_wlen(a) : 0, m = b ? xx_str_wlen(b) : 0;
    bool same = a && b && n <= m && (!b[n] || b[n] == '/') &&
        CompareStringOrdinal(a, (int)n, b, (int)n, TRUE) == CSTR_EQUAL;
    xx_str_wfree(a); xx_str_wfree(b);
    return same;
#else
    size_t n = strlen(name), m = strlen(other);
    if (n > m || (other[n] && other[n] != '/')) return false;
    return !memcmp(name, other, n);
#endif
}

/* Stable suffixes cannot collide with literal archive names: '~' was escaped
 * above. The whole leaf is renamed when it would also be a directory. */
static inline bool xx_archive_output_suffix(char **name, size_t index)
{
    char suffix[40], *next;
    snprintf(suffix, sizeof(suffix), "~xx-%08llu", (unsigned long long)index);
    next = xx_str_concat(*name, suffix);
    if (!next) return false;
    xx_mem_free(*name); *name = next; return true;
}

#define XX_ARCHIVE_OUTPUT_RESOLVE(result, array, count, index, field, cp, flags) do { \
    size_t xx_oni; bool xx_oncollision = (count) > 2048; \
    for (xx_oni = 0; !xx_oncollision && (result) && xx_oni < (count); ++xx_oni) { \
        char *xx_onother; if (xx_oni == (index)) continue; \
        xx_onother = xx_archive_output_name((array)[xx_oni].field, cp, flags); \
        if (xx_onother && xx_archive_output_equal_prefix(result, xx_onother)) xx_oncollision = true; \
        xx_mem_free(xx_onother); \
    } \
    if (xx_oncollision && !xx_archive_output_suffix(&(result), index)) { xx_mem_free(result); (result) = NULL; } \
} while (0)

#endif
