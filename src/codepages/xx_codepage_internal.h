/* Copyright (c) 2024-2026 hors<horsicq@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef XX_CODEPAGE_INTERNAL_H
#define XX_CODEPAGE_INTERNAL_H
#include "xxfclib/codepages/xx_codepage.h"
xx_codepage_status xx_codepage_sb_decode(const xx_codepage *, const unsigned char *, size_t, size_t *, uint32_t *);
xx_codepage_status xx_codepage_sb_encode(const xx_codepage *, uint32_t, unsigned char *, size_t, size_t *);
typedef struct xx_codepage_pair {
    uint16_t key, value;
} xx_codepage_pair;
typedef struct xx_codepage_dbcs {
    const uint32_t *singles;
    const unsigned char *leads;
    const xx_codepage_pair *forward;
    size_t forward_count;
    const xx_codepage_pair *reverse;
    size_t reverse_count;
} xx_codepage_dbcs;
xx_codepage_status xx_codepage_dbcs_decode(const xx_codepage *, const unsigned char *, size_t, size_t *, uint32_t *);
xx_codepage_status xx_codepage_dbcs_encode(const xx_codepage *, uint32_t, unsigned char *, size_t, size_t *);
#endif
