/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Base64 / MIME text, bare or in a "begin-base64" envelope.  xx_base64.h
 * carries the grammar and the acceptance rules.
 *
 * Decoding follows the usual Base64 rules (RFC 4648 alphabet, CR / LF
 * ignored, a last group of two or three symbols gives one or two bytes, the
 * text stops at its '=' padding), which is also what Deark's base64 and
 * uuencode modules (deark-1.7.3/modules/xfer.c, MIT licence, Copyright (C)
 * 2016 Jason Summers) and 7-Zip's Base64 handler do.  The envelope
 * ("begin-base64 <mode> <name>" ... "====") is the one sharutils'
 * `uuencode -m` writes; several envelopes in one file are one member each,
 * like the blocks of a UUE file.  Neither reference auto-detects bare Base64
 * (7-Zip opens it by the .b64 extension only, Deark needs -m base64); the
 * detection window and its rules below are this reader's own.
 *
 * check_is_valid looks at no more than the first 64 KiB plus a 1 KiB tail,
 * so the late probe is cheap: binary input fails on its first byte and prose
 * on its first space or punctuation mark.  The first 512 bytes are read into
 * a stack buffer; only a text still valid past them gets one heap buffer of
 * xx_get_file_buffer_size() bytes per scan call, freed before it returns.
 * handle_base_info applies the same rules and then walks the rest of the
 * text only to find where it ends, with the same buffers.
 */

#include "xxfclib/rt/xx_rt.h"
#include "xxfclib/global/xx_global.h"
#include "xxfclib/formats/other/base64/xx_base64.h"

#include "xxfclib/algo/store/xx_store.h"
#include "xxfclib/io/xx_io.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/strings/xx_string.h"

#include <limits.h>
#include <stdio.h>

/* Registration placeholder.  xxfc_defs.h is shared and is not edited from
 * here, so the alias macro defined next to the enumerator is tested instead;
 * this picks up the real file type as soon as BASE64 is registered there. */
#ifdef BASE64
#define XX_BASE64_FILE_TYPE XX_FILE_TYPE_BASE64
#else
#define XX_BASE64_FILE_TYPE XX_FILE_TYPE_UNKNOWN
#endif

/* Bytes of text the acceptance rules are applied to. */
#define BASE64_WINDOW ((int64_t)64 * 1024)
/* Bytes of whitespace / 0x1A / 0x00 tolerated past the window when the text
 * ends inside it. */
#define BASE64_MAX_TAIL ((int64_t)1024)
/* Bare text: fewest symbols, and narrowest line of a multi-line text. */
#define BASE64_MIN_SYMBOLS 16U
#define BASE64_MIN_WIDTH 16U
/* Different symbols due from a symbol count on.  Hex text has at most 22
 * (0-9 A-F a-f), so a hex dump with a few stray letters stays out, while
 * encoded real data has far more: over the first 48 KiB of 5,374 system and
 * library files the fewest was 35, at 268 symbols. */
#define BASE64_DIVERSE_FROM 256U
#define BASE64_MIN_DISTINCT 24U
#define BASE64_DIVERSE_MORE_FROM 1024U
#define BASE64_MIN_DISTINCT_MORE 32U
/* Below this many symbols a bare text also needs a digit, '+', '/' or '='
 * padding, so a lone word such as "ReadMeFirstPlzOK" is not claimed. */
#define BASE64_SHORT_TEXT 64U
/* Longest "begin-base64" header line, line break included (xx_base64.h). */
#define BASE64_HEADER_MAX XX_BASE64_HEADER_MAX
#define BASE64_PREFIX "begin-base64 "
#define BASE64_PREFIX_SIZE 13U
#define BASE64_NAME_MAX 255U
/* Longest header name used as the member name: a file name. */
#define BASE64_NAME_USE_MAX BASE64_NAME_MAX
/* A joined output path longer than this is retried with the default name:
 * on Windows, which keeps a path within 260 characters. */
#ifdef _WIN32
#define BASE64_PATH_MAX 259U
#else
#define BASE64_PATH_MAX 4095U
#endif
#define BASE64_PAYLOAD_NAME "payload"
/* Envelopes in one file, and bytes of other text skipped between two of
 * them, as between UUE blocks. */
#define BASE64_MAX_ENVELOPES 65536U
#define BASE64_MAX_GAP ((int64_t)64 * 1024)
/* First chunk of a scan, read into a stack buffer so that the late probe
 * rejects most input with one small read and no allocation. */
#define BASE64_FIRST_CHUNK 512U

/* Scanner phases. */
enum {
    BASE64_DATA = 0, /* symbols and line breaks */
    BASE64_PAD2,     /* one '=' seen, a second one is due */
    BASE64_AFTER,    /* padding complete, the line must end */
    BASE64_TRAIL,    /* bare text over: whitespace to EOF */
    BASE64_ZTAIL,    /* bare text over: 0x1A / 0x00 to EOF */
    BASE64_WAIT,     /* envelope data over: blank lines, then "====" */
    BASE64_TERM,     /* inside the "====" line */
    BASE64_DONE      /* envelope closed */
};

/* Resumable forward scan, offsets relative to the base address. */
typedef struct base64_scan_s {
    int64_t position;      /**< Offset of the next byte. */
    int64_t data_end;      /**< Just past the last symbol or pad. */
    int64_t text_end;      /**< Just past the last byte of the format. */
    int64_t line_start;    /**< Offset of the current line. */
    int64_t line_data_end; /**< data_end where the current line starts. */
    uint64_t line_symbols; /**< symbols where the current line starts. */
    uint64_t symbols;
    uint64_t line_length; /**< Symbols and pads on the current line. */
    uint64_t width;       /**< Length of the first complete line, 0 = none. */
    uint64_t distinct;    /**< One bit per symbol value seen. */
    unsigned term_count;  /**< '=' of the terminator line seen so far. */
    int phase;
    bool wrapped;
    bool strict;     /**< Apply the window rules to this byte. */
    bool cr;         /**< Previous byte was CR. */
    bool short_line; /**< A complete line shorter than `width` seen. */
    bool has_upper;
    bool has_lower;
    bool has_nonhex;
    bool padded; /**< '=' padding seen. */
    bool terminated;
    bool finished; /**< The text ended; later bytes are not read. */
    bool rejected; /**< A window rule failed. */
    /* An envelope body: the symbols on its first data line, whether a
     * complete data line shorter than that was seen (an encoder writes only
     * its last line shorter), and whether a data line followed one. */
    uint64_t body_width;
    bool body_short;
    bool body_overrun;
} base64_scan;

typedef struct base64_context_s {
    int64_t header_offset;
    int64_t data_offset;
    int64_t data_size;
    int64_t text_size;
    uint64_t symbol_count;
    uint64_t unpacked_size;
    uint64_t line_width;
    uint32_t mode;
    bool wrapped;
    bool terminated;
    bool damaged; /**< An envelope whose header or body breaks the rules. */
    char name[BASE64_NAME_MAX + 1U];
} base64_context;

typedef struct base64_stream_s {
    base64_context context;
    size_t index;
    size_t count;
    uint64_t *seen; /**< Open-addressed set of name hashes, 0 = empty. */
    size_t seen_mask;
    char name[BASE64_NAME_MAX + 24U]; /**< The current member's final name. */
} base64_stream;

static int base64_value(uint8_t c)
{
    if (c >= 'A' && c <= 'Z') return c - 'A';
    if (c >= 'a' && c <= 'z') return c - 'a' + 26;
    if (c >= '0' && c <= '9') return c - '0' + 52;
    if (c == '+') return 62;
    if (c == '/') return 63;
    return -1;
}

static bool base64_read_at(xx_io_device *device, int64_t offset, void *buffer, size_t size)
{
    size_t done = 0U;
    const size_t transfer_capacity = xx_get_file_buffer_size();
    if (!device || (!buffer && size != 0U) || offset < 0 || xx_io_seek64(device, offset, SEEK_SET) != 0) return false;
    while (done < size) {
        size_t request = size - done;
        if (request > transfer_capacity) request = transfer_capacity;
        ssize_t amount = xx_io_read(device, (uint8_t *)buffer + done, request);
        if (amount <= 0 || (size_t)amount > request) return false;
        done += (size_t)amount;
    }
    return true;
}

/* ---------------------------------------------------------------------- */
/* Scanner                                                                 */

/* A byte that breaks a window rule rejects the text inside the window and
 * merely ends it past the window. */
static bool base64_foreign(base64_scan *scan)
{
    if (scan->strict) scan->rejected = true;
    scan->finished = true;
    return false;
}

/* Line rules of a bare text, for a symbol or pad about to be added to the
 * current line. */
static bool base64_line_ok(const base64_scan *scan)
{
    if (!scan->strict || scan->wrapped || scan->width == 0U) return true;
    /* A line after the first one: the text is multi-line, so the first
     * line's width must be a real encoder's, and no short line may come
     * before this one. */
    if (scan->line_length == 0U && (scan->short_line || (scan->width & 3U) != 0U || scan->width < BASE64_MIN_WIDTH)) return false;
    return scan->line_length < scan->width;
}

static bool base64_symbol(base64_scan *scan, int value, uint8_t c, int64_t here)
{
    if (!base64_line_ok(scan)) return base64_foreign(scan);
    if (c >= 'A' && c <= 'Z') {
        scan->has_upper = true;
        if (c > 'F') scan->has_nonhex = true;
    } else if (c >= 'a' && c <= 'z') {
        scan->has_lower = true;
        if (c > 'f') scan->has_nonhex = true;
    } else if (c == '+' || c == '/') {
        scan->has_nonhex = true;
    }
    scan->distinct |= (uint64_t)1U << (unsigned)value;
    ++scan->symbols;
    ++scan->line_length;
    scan->data_end = scan->text_end = here + 1;
    return true;
}

static bool base64_pad(base64_scan *scan, int64_t here)
{
    if (!base64_line_ok(scan)) return base64_foreign(scan);
    ++scan->line_length;
    scan->padded = true;
    scan->data_end = scan->text_end = here + 1;
    return true;
}

/* The LF at `here` was taken: the next line starts after it. */
static bool base64_next_line(base64_scan *scan, int64_t here)
{
    scan->line_start = here + 1;
    scan->line_data_end = scan->data_end;
    scan->line_symbols = scan->symbols;
    return true;
}

/* LF inside the text (phase DATA or AFTER). */
static bool base64_line_end(base64_scan *scan, int64_t here)
{
    if (scan->line_length == 0U) {
        /* Blank line: skipped in an envelope, the end of a bare text. */
        if (scan->wrapped) return base64_next_line(scan, here);
        if (scan->symbols == 0U) return base64_foreign(scan);
        /* Unpadded, so the text must end on a whole group. */
        if (scan->phase == BASE64_DATA && scan->strict && (scan->symbols & 3U) != 0U) return base64_foreign(scan);
        scan->phase = BASE64_TRAIL;
        scan->text_end = here + 1;
        return true;
    }
    if (!scan->wrapped) {
        if (scan->width == 0U) scan->width = scan->line_length;
        else if (scan->line_length < scan->width) scan->short_line = true;
    } else if (scan->body_short) {
        scan->body_overrun = true;
    } else if (scan->body_width == 0U) {
        scan->body_width = scan->line_length;
    } else if (scan->line_length < scan->body_width) {
        scan->body_short = true;
    }
    scan->line_length = 0U;
    scan->text_end = here + 1;
    return base64_next_line(scan, here);
}

/* Feed one byte at offset `here`.  False once the text has ended (finished)
 * or a window rule failed (rejected). */
static bool base64_feed(base64_scan *scan, uint8_t c, int64_t here)
{
    int value;
    if (scan->cr) {
        scan->cr = false;
        /* A CR not followed by LF only passes outside the window. */
        if (c != '\n' && scan->strict) return base64_foreign(scan);
    }
    switch (scan->phase) {
        case BASE64_DATA:
            value = base64_value(c);
            if (value >= 0) return base64_symbol(scan, value, c, here);
            if (c == '=') {
                unsigned rest = (unsigned)(scan->symbols & 3U);
                if (scan->wrapped && scan->line_length == 0U) {
                    scan->phase = BASE64_TERM;
                    scan->term_count = 1U;
                    return true;
                }
                if (rest < 2U) return base64_foreign(scan);
                if (!base64_pad(scan, here)) return false;
                scan->phase = rest == 2U ? BASE64_PAD2 : BASE64_AFTER;
                return true;
            }
            if (c == '\r') {
                scan->cr = true;
                return true;
            }
            if (c == '\n') return base64_line_end(scan, here);
            if (!scan->wrapped && scan->line_length == 0U && scan->symbols != 0U && (c == ' ' || c == '\t' || c == 0x1AU || c == 0x00U)) {
                /* Whitespace or padding after the last line: the text ended
                 * without '=', so it must end on a whole group. */
                if (scan->strict && (scan->symbols & 3U) != 0U) return base64_foreign(scan);
                scan->phase = BASE64_TRAIL;
                return base64_feed(scan, c, here);
            }
            return base64_foreign(scan);
        case BASE64_PAD2:
            if (c != '=') return base64_foreign(scan);
            if (!base64_pad(scan, here)) return false;
            scan->phase = BASE64_AFTER;
            return true;
        case BASE64_AFTER:
            if (c == '\r') {
                scan->cr = true;
                return true;
            }
            if (c == '\n') {
                if (!base64_line_end(scan, here)) return false;
                scan->phase = scan->wrapped ? BASE64_WAIT : BASE64_TRAIL;
                return true;
            }
            if (!scan->wrapped && !scan->strict && (c == ' ' || c == '\t')) {
                scan->phase = BASE64_TRAIL;
                scan->text_end = here + 1;
                return true;
            }
            return base64_foreign(scan);
        case BASE64_TRAIL:
            if (c == '\r' || c == '\n' || c == ' ' || c == '\t') {
                scan->text_end = here + 1;
                return true;
            }
            if (scan->strict && (c == 0x1AU || c == 0x00U)) {
                scan->phase = BASE64_ZTAIL;
                return true;
            }
            return base64_foreign(scan);
        case BASE64_ZTAIL:
            if (c == 0x1AU || c == 0x00U) return true;
            return base64_foreign(scan);
        case BASE64_WAIT:
            if (c == '\r') {
                scan->cr = true;
                return true;
            }
            if (c == '\n') return base64_next_line(scan, here);
            if (c == '=') {
                scan->phase = BASE64_TERM;
                scan->term_count = 1U;
                return true;
            }
            return base64_foreign(scan);
        case BASE64_TERM:
            if (c == '=' && scan->term_count < 4U) {
                ++scan->term_count;
                return true;
            }
            /* Blanks may follow the four '='. */
            if (scan->term_count == 4U && (c == ' ' || c == '\t')) return true;
            if (scan->term_count == 4U && c == '\r') {
                scan->cr = true;
                return true;
            }
            if (scan->term_count == 4U && c == '\n') {
                scan->terminated = true;
                scan->text_end = here + 1;
                scan->phase = BASE64_DONE;
                scan->finished = true;
                return false;
            }
            return base64_foreign(scan);
        default: scan->finished = true; return false;
    }
}

/* Feed the bytes of [scan->position, limit) until the text ends.  False
 * only on a read error or a stop request. */
static bool base64_scan_run_buffered(Abstractformat *format, base64_scan *scan, int64_t limit, xx_pd_struct *pd, uint8_t *buffer, size_t buffer_capacity)
{
    while (!scan->finished && scan->position < limit) {
        int64_t left = limit - scan->position;
        size_t want = (uint64_t)left < (uint64_t)buffer_capacity ? (size_t)left : buffer_capacity;
        size_t index;
        if (pd && xx_pd_is_stopped(pd)) return false;
        if (!base64_read_at(format->device, format->base_address + scan->position, buffer, want)) return false;
        for (index = 0U; index < want; ++index)
            if (!base64_feed(scan, buffer[index], scan->position + (int64_t)index)) break;
        /* The byte that ended the text is not consumed. */
        scan->position += (int64_t)index;
    }
    return true;
}

/* The first BASE64_FIRST_CHUNK bytes go through a stack buffer; only a text
 * that survives them gets a heap buffer of the global transfer size. */
static bool base64_scan_run(Abstractformat *format, base64_scan *scan, int64_t limit, xx_pd_struct *pd)
{
    size_t buffer_capacity;
    uint8_t *buffer;
    bool result;
    if (scan->position < (int64_t)BASE64_FIRST_CHUNK) {
        uint8_t first[BASE64_FIRST_CHUNK];
        int64_t first_limit = (int64_t)BASE64_FIRST_CHUNK < limit ? (int64_t)BASE64_FIRST_CHUNK : limit;
        if (!base64_scan_run_buffered(format, scan, first_limit, pd, first, sizeof(first))) return false;
        if (scan->finished || scan->position >= limit) return true;
    }
    buffer_capacity = xx_get_file_buffer_size();
    buffer = (uint8_t *)xx_mem_alloc(buffer_capacity);
    if (!buffer) return false;
    result = base64_scan_run_buffered(format, scan, limit, pd, buffer, buffer_capacity);
    xx_mem_free(buffer);
    return result;
}

/* The input ended at scan->position.  False when a window rule fails. */
static bool base64_scan_eof(base64_scan *scan)
{
    unsigned rest = (unsigned)(scan->symbols & 3U);
    switch (scan->phase) {
        case BASE64_DATA:
            if (!scan->strict) return true;
            /* A bare text must end on a whole group; an envelope that lost its
             * terminator only needs its last group to be decodable. */
            return scan->wrapped ? rest != 1U : rest == 0U;
        /* An envelope cut inside its last group's padding or its "===="
         * line lost that line. */
        case BASE64_PAD2: return !scan->strict || scan->wrapped;
        case BASE64_TERM:
            if (scan->term_count == 4U) {
                scan->terminated = true;
                scan->text_end = scan->position;
                scan->phase = BASE64_DONE;
            }
            return true;
        default: return true;
    }
}

/* ---------------------------------------------------------------------- */
/* Envelope header                                                         */

static char base64_upper(char c)
{
    return (c >= 'a' && c <= 'z') ? (char)(c - 'a' + 'A') : c;
}

/* The first `stem` bytes of `name` spell `word` exactly, ignoring case. */
static bool base64_stem_is(const char *name, size_t stem, const char *word)
{
    size_t index;
    for (index = 0U; index < stem; ++index)
        if (!word[index] || base64_upper(name[index]) != word[index]) return false;
    return word[stem] == 0;
}

/* A plain file name: printable ASCII, no separators or reserved
 * punctuation, not only dots and spaces, no trailing dot or space, and not
 * a Windows device name with or without an extension. */
static bool base64_safe_name(const char *name, size_t length)
{
    static const char *const devices[] = {"CON", "PRN", "AUX", "NUL", "CONIN$", "CONOUT$", "CLOCK$"};
    size_t stem = 0U, index;
    bool meaningful = false;
    if (!name || length == 0U) return false;
    for (index = 0U; index < length; ++index) {
        char c = name[index];
        if ((unsigned char)c < 0x20U || (unsigned char)c > 0x7EU || c == '/' || c == '\\' || c == ':' || c == '<' || c == '>' || c == '"' || c == '|' || c == '?' ||
            c == '*')
            return false;
        if (c != '.' && c != ' ') meaningful = true;
    }
    if (!meaningful || name[length - 1U] == '.' || name[length - 1U] == ' ') return false;
    while (stem < length && name[stem] != '.') ++stem;
    while (stem > 0U && name[stem - 1U] == ' ') --stem;
    for (index = 0U; index < sizeof(devices) / sizeof(devices[0]); ++index)
        if (base64_stem_is(name, stem, devices[index])) return false;
    if (stem == 4U && name[3] >= '0' && name[3] <= '9' &&
        ((base64_upper(name[0]) == 'C' && base64_upper(name[1]) == 'O' && base64_upper(name[2]) == 'M') ||
         (base64_upper(name[0]) == 'L' && base64_upper(name[1]) == 'P' && base64_upper(name[2]) == 'T')))
        return false;
    return true;
}

/* The member name: the header name's last path component when that is a
 * safe plain file name ("-" is standard input), else the default. */
static void base64_set_name(base64_context *context, const uint8_t *name, size_t length)
{
    size_t start = 0U, index;
    for (index = 0U; index < length; ++index)
        if (name[index] == '/' || name[index] == '\\' || name[index] == ':') start = index + 1U;
    name += start;
    length -= start;
    if (length == 0U || length > BASE64_NAME_USE_MAX || (length == 1U && name[0] == '-') || !base64_safe_name((const char *)name, length)) {
        name = (const uint8_t *)BASE64_PAYLOAD_NAME;
        length = sizeof(BASE64_PAYLOAD_NAME) - 1U;
    }
    xx_rt_memcpy(context->name, name, length);
    context->name[length] = 0;
}

/* "begin-base64 <1-6 octal digits> <name>" + LF or CRLF at the start of
 * `line` (the first `length` bytes of the input).  sharutils prints the mode
 * with %o, so it has as many digits as it needs (six for 100644).  The name
 * is any text up to the line break; one that is no safe file name gives the
 * default member name.  The envelope probe of XFileUnpacker applies the same
 * rules.  True with the offset of the next line in `data_offset`. */
static bool base64_parse_header(const uint8_t *line, size_t length, base64_context *context)
{
    size_t position = BASE64_PREFIX_SIZE, mode_start, end = 0U, index;
    uint32_t mode = 0U;
    if (length < BASE64_PREFIX_SIZE + 4U || xx_rt_memcmp(line, BASE64_PREFIX, BASE64_PREFIX_SIZE) != 0) return false;
    mode_start = position;
    while (position < length && position < mode_start + 6U && line[position] >= '0' && line[position] <= '7') {
        mode = (mode << 3U) | (uint32_t)(line[position] - '0');
        ++position;
    }
    if (position == mode_start || position >= length || line[position] != ' ') return false;
    ++position;
    for (index = position; index < length; ++index) {
        if (line[index] == '\n') {
            end = index;
            break;
        }
    }
    if (index >= length) return false;
    if (end > position && line[end - 1U] == '\r') --end;
    if (end <= position) return false;
    for (index = position; index < end; ++index)
        if (line[index] == 0U) return false;
    context->mode = mode;
    context->wrapped = true;
    base64_set_name(context, line + position, end - position);
    /* The line after the header. */
    while (line[end] != '\n') ++end;
    context->data_offset = (int64_t)end + 1;
    return true;
}

/* ---------------------------------------------------------------------- */
/* Parsing                                                                 */

/* Where the text of an envelope that goes on at the line start `from` past
 * the end of its data ends: past its "====" line, which may end in blanks
 * (*kind 1), at the next line that starts with "begin-base64 " (*kind 2), or
 * at a NUL byte, 0x1A padding or the end of the input (*kind 0).  *blank:
 * what lies before that end is only blank lines; with `quick`, the search
 * stops as soon as it is not.  -1 on a read error or a stop. */
static int64_t base64_text_end(Abstractformat *format, int64_t from, int64_t size, bool quick, int *kind, bool *blank, xx_pd_struct *pd)
{
    uint8_t buffer[4096];
    int64_t position = from, line_start = from;
    size_t column = 0U;
    bool header = true, terminator = true, line_blank = true;
    *kind = 0;
    *blank = true;
    while (position < size) {
        size_t want = size - position < (int64_t)sizeof(buffer) ? (size_t)(size - position) : sizeof(buffer), index;
        if ((pd && xx_pd_is_stopped(pd)) || !base64_read_at(format->device, format->base_address + position, buffer, want)) return -1;
        for (index = 0U; index < want; ++index) {
            uint8_t c = buffer[index];
            int64_t here = position + (int64_t)index;
            if (c == 0x00U || (c == 0x1AU && *blank && line_blank)) {
                /* Binary data, or 0x1A padding after blank lines, ends the
                 * text as the end of the input does. */
                *blank = *blank && line_blank;
                return here;
            }
            if (c == '\n') {
                if (terminator && column >= 4U) {
                    *kind = 1;
                    return here + 1;
                }
                *blank = *blank && line_blank;
                if (quick && !*blank) return here;
                line_start = here + 1;
                column = 0U;
                header = terminator = line_blank = true;
                continue;
            }
            if (c != ' ' && c != '\t' && c != '\r') line_blank = false;
            if (header && (column >= BASE64_PREFIX_SIZE || c != (uint8_t)BASE64_PREFIX[column])) header = false;
            if (terminator && !(column < 4U ? c == '=' : c == ' ' || c == '\t' || c == '\r')) terminator = false;
            ++column;
            if (header && column == BASE64_PREFIX_SIZE) {
                *kind = 2;
                return line_start;
            }
            /* Neither blank nor a line that ends the text. */
            if (quick && !line_blank && !header && !terminator) {
                *blank = false;
                return here;
            }
        }
        position += (int64_t)want;
    }
    /* The last line has no line break. */
    if (terminator && column >= 4U) *kind = 1;
    else *blank = *blank && line_blank;
    return size;
}

/* An envelope body stopped at scan->position before its "====" line.  A NUL
 * or 0x1A byte there ends the text as the end of the input does.  Else only
 * blank lines may come before the "====" line (which closes the envelope),
 * the next line that starts with "begin-base64 ", padding or the end of the
 * input: the terminator was lost then, and the symbols the body took from
 * the start of that header line ("begin") are given back.  The last group
 * of an envelope that lost its terminator must decode.  1 with *end where
 * the text ends; 0 for a body broken by other text (*end: the end of its
 * text, unless `quick`); -1 on a read error or a stop. */
static int base64_body_stop(Abstractformat *format, base64_scan *scan, int64_t size, bool quick, int64_t *end, xx_pd_struct *pd)
{
    uint8_t stop;
    int kind;
    bool blank;
    if (!base64_read_at(format->device, format->base_address + scan->position, &stop, 1U)) return -1;
    if (stop == 0x00U || stop == 0x1AU) {
        *end = scan->position;
        if (!base64_scan_eof(scan)) return 0;
    } else {
        *end = base64_text_end(format, scan->line_start, size, quick, &kind, &blank, pd);
        if (*end < 0) return -1;
        if (!blank) return 0;
        scan->terminated = kind == 1;
        scan->symbols = scan->line_symbols;
        scan->data_end = scan->line_data_end;
        scan->line_length = 0U;
    }
    return scan->terminated || (scan->symbols & 3U) != 1U;
}

/* Apply the window rules to the text at `start` (0, or the header of a
 * later envelope); with `measure`, also find where the text ends. */
static bool base64_parse_at(Abstractformat *format, int64_t start, base64_context *out, bool measure, xx_pd_struct *pd)
{
    base64_scan scan;
    base64_context context;
    int64_t total, size, window, stop_end = 0;
    int stop = -1; /* base64_body_stop's answer, -1 = not asked */
    unsigned distinct = 0U;
    uint64_t bits;
    if (!format || !format->device || !out || format->base_address < 0) return false;
    total = xx_io_total_size(format->device);
    if (total < format->base_address) return false;
    size = total - format->base_address;
    if (start < 0 || start > size || size - start < (int64_t)BASE64_MIN_SYMBOLS) return false;

    xx_mem_zero(&context, sizeof(context));
    xx_mem_zero(&scan, sizeof(scan));
    {
        uint8_t head[BASE64_HEADER_MAX];
        size_t length = size - start < (int64_t)sizeof(head) ? (size_t)(size - start) : sizeof(head);
        /* Cheap early exit for the late probe: the first byte must start
         * either the envelope or a bare text. */
        if (!base64_read_at(format->device, format->base_address + start, head, 1U) || (head[0] != 'b' && base64_value(head[0]) < 0)) return false;
        if (head[0] == 'b' && base64_read_at(format->device, format->base_address + start, head, length) && !base64_parse_header(head, length, &context))
            xx_mem_zero(&context, sizeof(context));
        /* Only the first text may be bare. */
        if (start != 0 && !context.wrapped) return false;
        context.header_offset = start;
        context.data_offset += start;
    }
    scan.wrapped = context.wrapped;
    scan.position = scan.data_end = scan.text_end = context.data_offset;
    scan.line_start = scan.line_data_end = context.data_offset;
    scan.phase = BASE64_DATA;
    scan.strict = true;

    window = size - start < BASE64_WINDOW ? size : start + BASE64_WINDOW;
    if (!base64_scan_run(format, &scan, window, pd)) return false;
    if (scan.rejected) {
        /* An envelope body that only lost its terminator breaks no rule, and
         * one that other text stops is a damaged member, as past the window:
         * the header line is the evidence. */
        if (!scan.wrapped) return false;
        stop = base64_body_stop(format, &scan, size, !measure, &stop_end, pd);
        if (stop < 0) return false;
        scan.rejected = false;
        context.damaged = stop == 0;
    }
    if (!scan.wrapped && !scan.finished && scan.position < size && (scan.phase == BASE64_AFTER || scan.phase == BASE64_TRAIL || scan.phase == BASE64_ZTAIL)) {
        /* The bare text ended inside the window: its tail must reach EOF
         * soon. */
        if (size - scan.position > BASE64_MAX_TAIL) return false;
        if (!base64_scan_run(format, &scan, size, pd) || scan.rejected) return false;
    }
    if (!scan.finished && scan.position >= size && !base64_scan_eof(&scan)) {
        /* A bare text must end on a whole group; an envelope that ends in a
         * lone symbol is a damaged member, as past the window. */
        if (!scan.wrapped) return false;
        context.damaged = true;
    }

    if (scan.wrapped) {
        if (scan.symbols == 0U && !scan.terminated) return false;
    } else {
        for (bits = scan.distinct; bits != 0U; bits &= bits - 1U) ++distinct;
        if (scan.symbols < BASE64_MIN_SYMBOLS || !scan.has_upper || !scan.has_lower || !scan.has_nonhex ||
            (scan.symbols >= BASE64_DIVERSE_FROM && distinct < BASE64_MIN_DISTINCT) ||
            (scan.symbols >= BASE64_DIVERSE_MORE_FROM && distinct < BASE64_MIN_DISTINCT_MORE) ||
            /* Symbol values 52..63 are the digits, '+' and '/'. */
            (scan.symbols < BASE64_SHORT_TEXT && !scan.padded && (scan.distinct >> 52U) == 0U))
            return false;
    }

    if (measure) {
        scan.strict = false;
        if (!scan.finished && scan.position < size && !base64_scan_run(format, &scan, size, pd)) return false;
        if (!scan.finished && scan.position >= size) (void)base64_scan_eof(&scan);
        /* An envelope body that stops at other text before its "====" line
         * is damaged (base64_body_stop); its text goes on from the start of
         * the line that stopped it. */
        if (context.wrapped && scan.finished && !scan.terminated && stop < 0) {
            stop = base64_body_stop(format, &scan, size, false, &stop_end, pd);
            if (stop < 0) return false;
            context.damaged = stop == 0;
        }
        if (scan.data_end < context.data_offset || scan.text_end < scan.data_end || scan.text_end > size) return false;
        context.data_size = scan.data_end - context.data_offset;
        context.text_size = stop < 0 ? scan.text_end : stop_end;
        context.symbol_count = scan.symbols;
        context.unpacked_size = scan.symbols / 4U * 3U;
        if ((scan.symbols & 3U) >= 2U) context.unpacked_size += (scan.symbols & 3U) - 1U;
        context.line_width = scan.width;
        context.terminated = scan.terminated;
        /* At the end of the input, too, a lost terminator leaves a last
         * group that must decode.  Without its "====" line, a data line
         * after a line shorter than the first one (the encoder's last line)
         * is other text that happens to be in the Base64 alphabet ("text",
         * "Thanks"), not data: the envelope is damaged then. */
        if (context.wrapped && !context.terminated && ((scan.symbols & 3U) == 1U || scan.body_overrun || (scan.body_short && scan.line_length != 0U)))
            context.damaged = true;
        if (!context.wrapped) {
            xx_rt_memcpy(context.name, BASE64_PAYLOAD_NAME, sizeof(BASE64_PAYLOAD_NAME));
        }
    }
    *out = context;
    return true;
}

static bool base64_parse(Abstractformat *format, base64_context *out, bool measure, xx_pd_struct *pd)
{
    return base64_parse_at(format, 0, out, measure, pd);
}

/* Where the envelope after `previous` starts: a line that starts with
 * "begin-base64 " after at most BASE64_MAX_GAP bytes of other text.  One
 * that is no header is a damaged member, never text that is skipped.  1
 * with its offset, 0 when none follows, -1 on a read error. */
static int base64_next_header(Abstractformat *format, const base64_context *previous, int64_t *start)
{
    uint8_t line[BASE64_HEADER_MAX];
    int64_t total, size, position;
    if (!previous->wrapped) return 0;
    total = xx_io_total_size(format->device);
    if (total < format->base_address) return -1;
    size = total - format->base_address;
    position = previous->text_size;
    while (position < size && position - previous->text_size <= BASE64_MAX_GAP) {
        size_t length = size - position < (int64_t)sizeof(line) ? (size_t)(size - position) : sizeof(line);
        size_t end = 0U;
        if (!base64_read_at(format->device, format->base_address + position, line, length)) return -1;
        if (length >= BASE64_PREFIX_SIZE && xx_rt_memcmp(line, BASE64_PREFIX, BASE64_PREFIX_SIZE) == 0) {
            *start = position;
            return 1;
        }
        while (end < length && line[end] != '\n') {
            /* Binary data is not text between envelopes. */
            if (line[end] == 0U) return 0;
            ++end;
        }
        position += (int64_t)end;
        /* The rest of a line longer than the buffer. */
        while (end == sizeof(line) && position < size && position - previous->text_size <= BASE64_MAX_GAP) {
            length = size - position < (int64_t)sizeof(line) ? (size_t)(size - position) : sizeof(line);
            if (!base64_read_at(format->device, format->base_address + position, line, length)) return -1;
            for (end = 0U; end < length && line[end] != '\n'; ++end)
                if (line[end] == 0U) return 0;
            position += (int64_t)end;
        }
        /* Past the line break; the last line ends the search. */
        if (position >= size) return 0;
        ++position;
    }
    return 0;
}

/* The envelope whose header line is at `start`.  One whose header or body
 * breaks the rules stays a member, a damaged one that fails to decode
 * (named after its header when that can be read), rather than being dropped
 * without a word, and so does one whose body stops at other text before
 * its "====" line.  The next envelope is looked for past a damaged one's
 * text.  False only on a read error or a stop. */
static bool base64_parse_next(Abstractformat *format, int64_t start, base64_context *out, xx_pd_struct *pd)
{
    uint8_t line[BASE64_HEADER_MAX];
    int64_t size = xx_io_total_size(format->device) - format->base_address, end;
    size_t length, index;
    int kind;
    bool blank;
    if (base64_parse_at(format, start, out, true, pd)) return true;
    if ((pd && xx_pd_is_stopped(pd)) || start < 0 || size <= start) return false;
    length = size - start < (int64_t)sizeof(line) ? (size_t)(size - start) : sizeof(line);
    xx_mem_zero(out, sizeof(*out));
    if (!base64_read_at(format->device, format->base_address + start, line, length)) return false;
    if (!base64_parse_header(line, length, out)) {
        /* Not even its header can be read: the default name, and the data
         * would start on the next line. */
        index = 0U;
        while (index < length && line[index] != '\n') ++index;
        xx_mem_zero(out, sizeof(*out));
        out->wrapped = true;
        out->data_offset = (int64_t)(index < length ? index + 1U : length);
        xx_rt_memcpy(out->name, BASE64_PAYLOAD_NAME, sizeof(BASE64_PAYLOAD_NAME));
    }
    out->header_offset = start;
    out->data_offset += start;
    out->damaged = true;
    end = base64_text_end(format, out->data_offset, size, false, &kind, &blank, pd);
    if (end < 0) return false;
    out->text_size = end;
    return true;
}

/* Every envelope: their number, where the last one ends, and whether the
 * first one and every later one that decodes ended at its "====" line (a
 * later one that fails to decode is that member's failure). */
static bool base64_walk(Abstractformat *format, base64_context *first, uint64_t *count, int64_t *text_size, bool *terminated, xx_pd_struct *pd)
{
    base64_context context;
    if (!base64_parse(format, first, true, pd)) return false;
    context = *first;
    *count = 1U;
    *terminated = first->terminated;
    while (*count < BASE64_MAX_ENVELOPES) {
        int64_t start;
        int next = base64_next_header(format, &context, &start);
        if (next < 0) return false;
        if (next == 0) break;
        if (!base64_parse_next(format, start, &context, pd)) return false;
        if (!context.terminated && !context.damaged) *terminated = false;
        ++*count;
    }
    *text_size = context.text_size;
    return true;
}

static bool base64_write_all(xx_io_device *destination, const uint8_t *data, size_t size, size_t transfer_capacity)
{
    size_t done = 0U;

    while (done < size) {
        size_t request = size - done;
        if (request > transfer_capacity) request = transfer_capacity;
        ssize_t amount = xx_io_write(destination, data + done, request);
        if (amount <= 0 || (size_t)amount > request) return false;
        done += (size_t)amount;
    }
    return true;
}

/* Decode the measured text to `destination` (or only count it when that is
 * NULL).  Every byte of the text was classified by the measuring pass, so a
 * foreign byte or a count mismatch means the input changed underneath. */
static bool base64_decode_buffered(Abstractformat *format, const base64_context *context, xx_io_device *destination, xx_pd_struct *pd, uint8_t *input, uint8_t *output,
                                   size_t buffer_capacity)
{
    int64_t position = 0;
    uint64_t written = 0U;
    uint32_t group = 0U;
    unsigned count = 0U;
    bool padded = false;
    if (!format || !context || context->data_size < 0) return false;
    while (!padded && position < context->data_size) {
        int64_t left = context->data_size - position;
        size_t want = (uint64_t)left < (uint64_t)buffer_capacity ? (size_t)left : buffer_capacity;
        size_t index, produced = 0U;
        if (pd && xx_pd_is_stopped(pd)) return false;
        if (!base64_read_at(format->device, format->base_address + context->data_offset + position, input, want)) return false;
        for (index = 0U; index < want; ++index) {
            uint8_t c = input[index];
            int value = base64_value(c);
            if (value < 0) {
                if (c == '\r' || c == '\n') continue;
                if (c == '=') {
                    padded = true;
                    break;
                }
                return false;
            }
            group = (group << 6U) | (uint32_t)value;
            if (++count == 4U) {
                /* A complete quartet yields a semantic three-byte group.
                 * Append it bytewise so even capacity 1/2 stays bounded. */
                for (unsigned byte = 0U; byte < 3U; ++byte) {
                    output[produced++] = (uint8_t)(group >> (16U - 8U * byte));
                    if (produced == buffer_capacity) {
                        if ((uint64_t)produced > context->unpacked_size - written || (destination && !base64_write_all(destination, output, produced, buffer_capacity)))
                            return false;
                        written += produced;
                        produced = 0U;
                    }
                }
                group = 0U;
                count = 0U;
            }
        }
        /* Flush the bounded output left after complete quartet groups. */
        if (produced != 0U) {
            if ((uint64_t)produced > context->unpacked_size - written || (destination && !base64_write_all(destination, output, produced, buffer_capacity))) return false;
            written += (uint64_t)produced;
        }
        position += (int64_t)want;
    }
    if (count >= 2U) {
        uint8_t tail[2];
        size_t produced = count - 1U;
        group <<= 6U * (4U - count);
        tail[0] = (uint8_t)(group >> 16U);
        tail[1] = (uint8_t)(group >> 8U);
        if ((uint64_t)produced > context->unpacked_size - written || (destination && !base64_write_all(destination, tail, produced, buffer_capacity))) return false;
        written += (uint64_t)produced;
    }
    return written == context->unpacked_size;
}

static bool base64_decode(Abstractformat *format, const base64_context *context, xx_io_device *destination, xx_pd_struct *pd)
{
    size_t buffer_capacity = xx_get_file_buffer_size();
    uint8_t *input = context->damaged ? NULL : (uint8_t *)xx_mem_alloc(buffer_capacity);
    uint8_t *output = context->damaged ? NULL : (uint8_t *)xx_mem_alloc(buffer_capacity);
    bool ok = input && output && base64_decode_buffered(format, context, destination, pd, input, output, buffer_capacity);
    xx_mem_free(output);
    xx_mem_free(input);
    return ok;
}

/* ---------------------------------------------------------------------- */
/* Records                                                                 */

static bool base64_copy_options(xx_list_s *destination, const xx_list_s *source)
{
    size_t index;
    if (!source) return true;
    for (index = 0U; index < source->count; ++index) {
        const xx_meta *original = (const xx_meta *)xx_list_at((const xx_list_t *)source, index);
        xx_meta copy;
        if (!original) continue;
        xx_meta_init(&copy, original->meta_id);
        if (!xx_var_copy(&copy.var, &original->var) || !xx_list_append(destination, &copy)) {
            xx_meta_cleanup(&copy);
            return false;
        }
    }
    return true;
}

static const xx_var *base64_option(const xx_list_s *options, uint32_t id)
{
    size_t index;
    if (!options) return NULL;
    for (index = 0U; index < options->count; ++index) {
        const xx_meta *meta = (const xx_meta *)xx_list_at((const xx_list_t *)options, index);
        if (meta && meta->meta_id == id) return &meta->var;
    }
    return NULL;
}

static uint64_t base64_name_hash(const char *name)
{
    uint64_t hash = UINT64_C(0xcbf29ce484222325);
    for (; *name; ++name) {
        char c = *name;
        if (c >= 'A' && c <= 'Z') c = (char)(c - 'A' + 'a');
        hash ^= (uint8_t)c;
        hash *= UINT64_C(0x100000001b3);
    }
    return hash ? hash : 1U;
}

/* Add `hash`; false when it was already there. */
static bool base64_seen_add(base64_stream *stream, uint64_t hash)
{
    size_t slot = (size_t)hash & stream->seen_mask, probes;
    for (probes = 0U; probes <= stream->seen_mask; ++probes) {
        if (stream->seen[slot] == 0U) {
            stream->seen[slot] = hash;
            return true;
        }
        if (stream->seen[slot] == hash) return false;
        slot = (slot + 1U) & stream->seen_mask;
    }
    return false;
}

/* The member name: the envelope's name, or, when an earlier member took it
 * already, the same with "%_<envelope number>" before its extension (the
 * names the UUE reader gives its blocks). */
static void base64_final_name(base64_stream *stream)
{
    const char *name = stream->context.name;
    size_t length = xx_str_len(name), dot = length, index;
    char digits[24];
    size_t digit_count = 0U;
    uint64_t number = (uint64_t)stream->index + 1U;
    if (base64_seen_add(stream, base64_name_hash(name))) {
        xx_rt_memcpy(stream->name, name, length + 1U);
        return;
    }
    /* A file name has at most 255 bytes, also with its number. */
    if (length + 22U > BASE64_NAME_MAX) {
        name = BASE64_PAYLOAD_NAME;
        length = dot = sizeof(BASE64_PAYLOAD_NAME) - 1U;
    }
    for (index = length; index > 1U; --index)
        if (name[index - 1U] == '.') {
            dot = index - 1U;
            break;
        }
    do {
        digits[digit_count++] = (char)('0' + (int)(number % 10U));
        number /= 10U;
    } while (number != 0U && digit_count < sizeof(digits));
    xx_rt_memcpy(stream->name, name, dot);
    stream->name[dot] = '%';
    stream->name[dot + 1U] = '_';
    for (index = 0U; index < digit_count; ++index) stream->name[dot + 2U + index] = digits[digit_count - 1U - index];
    xx_rt_memcpy(stream->name + dot + 2U + digit_count, name + dot, length - dot + 1U);
    (void)base64_seen_add(stream, base64_name_hash(stream->name));
}

static bool base64_set_record(Abstractformat *format, xx_archive_record *record, base64_stream *stream)
{
    const base64_context *context = &stream->context;
    base64_final_name(stream);
    xx_archive_record_cleanup(record);
    xx_archive_record_init(record);
    record->header_offset = format->base_address + context->header_offset;
    record->header_size = context->data_offset - context->header_offset;
    record->data_offset = format->base_address + context->data_offset;
    record->compressed_size = context->data_size;
    return xx_archive_record_set_original_name(record, stream->name) &&
           xx_archive_record_set_meta_u64(record, XX_META_ID_COMPRESSED_SIZE, (uint64_t)context->data_size) &&
           xx_archive_record_set_meta_u64(record, XX_META_ID_UNCOMPRESSED_SIZE, context->unpacked_size) &&
           xx_archive_record_set_meta_u64(record, XX_META_ID_COMPRESSION_METHOD, 0U) && xx_archive_record_set_meta_bool(record, XX_META_ID_IS_ENCRYPTED, false) &&
           xx_archive_record_set_meta_bool(record, XX_META_ID_IS_FOLDER, false);
}

static void base64_stream_free(void *opaque)
{
    base64_stream *stream = (base64_stream *)opaque;
    if (!stream) return;
    if (stream->seen) xx_mem_free(stream->seen);
    xx_mem_free(stream);
}

/* ---------------------------------------------------------------------- */
/* Public API                                                              */

void xx_base64_init(xx_base64 *archive, xx_io_device *device, int64_t base_address)
{
    if (!archive) return;
    xx_mem_zero(archive, sizeof(*archive));
    xx_format_init(&archive->format, device, base_address);
    archive->format.endian = XX_ENDIAN_LITTLE;
    archive->format.file_type = XX_BASE64_FILE_TYPE;
    archive->format.format_type = XX_TYPE_ARCHIVE;
    archive->format.is_archive = true;
    xx_format_set_mime_type(&archive->format, "text/plain");
    xx_format_set_extension(&archive->format, "b64");
    archive->format.check_is_valid = xx_base64_check_is_valid;
    archive->format.handle_base_info = xx_base64_handle_base_info;
    archive->format.get_format_size = xx_base64_get_format_size;
    archive->format.get_number_of_archive_records = xx_base64_get_number_of_archive_records;
    archive->format.create_archive_records_reading = xx_base64_create_archive_records_reading;
    archive->format.get_current_archive_record = xx_base64_get_current_archive_record;
    archive->format.unpack_current_archive_record = xx_base64_unpack_current_archive_record;
    archive->format.archive_record_move_to_next = xx_base64_archive_record_move_to_next;
    archive->format.free_archive_records_reading = xx_base64_free_archive_records_reading;
}

xx_base64 *xx_base64_create(xx_io_device *device, int64_t base_address)
{
    xx_base64 *archive = (xx_base64 *)xx_mem_alloc(sizeof(*archive));
    if (archive) xx_base64_init(archive, device, base_address);
    return archive;
}

void xx_base64_destroy(xx_base64 *archive)
{
    if (archive) xx_format_cleanup_extra_parameters(&archive->format);
}

void xx_base64_free(xx_base64 *archive)
{
    if (!archive) return;
    xx_base64_destroy(archive);
    xx_mem_free(archive);
}

bool xx_base64_check_is_valid(Abstractformat *format, xx_pd_struct *pd)
{
    base64_context context;
    return base64_parse(format, &context, false, pd);
}

bool xx_base64_handle_base_info(Abstractformat *format, xx_pd_struct *pd)
{
    base64_context context;
    xx_base64 *archive;
    uint64_t count;
    int64_t text_size;
    size_t length;
    bool terminated;
    if (!format || !base64_walk(format, &context, &count, &text_size, &terminated, pd)) return false;
    archive = (xx_base64 *)format;
    archive->number_of_records = count;
    archive->unpacked_size = context.unpacked_size;
    archive->symbol_count = context.symbol_count;
    archive->data_offset = context.data_offset;
    archive->data_size = context.data_size;
    archive->text_size = context.text_size;
    archive->line_width = context.line_width > UINT32_MAX ? UINT32_MAX : (uint32_t)context.line_width;
    archive->mode = context.mode;
    archive->is_wrapped = context.wrapped;
    archive->is_terminated = terminated;
    length = xx_str_len(context.name);
    if (length >= sizeof(archive->name)) length = sizeof(archive->name) - 1U;
    xx_rt_memcpy(archive->name, context.name, length);
    archive->name[length] = 0;
    format->number_of_archive_records = count;
    format->format_size = text_size;
    format->is_valid = true;
    format->base_info_handled = true;
    return true;
}

int64_t xx_base64_get_format_size(Abstractformat *format, xx_pd_struct *pd)
{
    return format && (format->base_info_handled || xx_base64_handle_base_info(format, pd)) ? format->format_size : -1;
}

uint64_t xx_base64_get_number_of_archive_records(Abstractformat *format, xx_pd_struct *pd)
{
    return format && (format->base_info_handled || xx_base64_handle_base_info(format, pd)) ? ((xx_base64 *)format)->number_of_records : 0U;
}

uint64_t xx_base64_get_unpacked_size(xx_base64 *archive)
{
    if (!archive) return 0U;
    if (!archive->format.base_info_handled && !xx_base64_handle_base_info(&archive->format, NULL)) return 0U;
    return archive->unpacked_size;
}

bool xx_base64_unpack_to_device(xx_base64 *archive, xx_io_device *destination, xx_pd_struct *pd)
{
    base64_context context;
    if (!archive || !destination || !base64_parse(&archive->format, &context, true, pd)) return false;
    return base64_decode(&archive->format, &context, destination, pd);
}

xx_archive_record_state *xx_base64_create_archive_records_reading(Abstractformat *format, const xx_list_s *options, xx_pd_struct *pd)
{
    base64_stream *stream;
    xx_archive_record_state *state;
    base64_context context;
    size_t slots = 16U;
    if (!format || (!format->base_info_handled && !xx_base64_handle_base_info(format, pd)) || !base64_parse(format, &context, true, pd)) return NULL;
    stream = (base64_stream *)xx_mem_calloc(1U, sizeof(*stream));
    if (!stream) return NULL;
    stream->context = context;
    stream->count = (size_t)((xx_base64 *)format)->number_of_records;
    while (slots < 2U * stream->count) slots <<= 1U;
    stream->seen = (uint64_t *)xx_mem_calloc(slots, sizeof(uint64_t));
    stream->seen_mask = slots - 1U;
    if (!stream->seen || stream->count == 0U) {
        base64_stream_free(stream);
        return NULL;
    }
    state = (xx_archive_record_state *)xx_mem_alloc(sizeof(*state));
    if (!state) {
        base64_stream_free(stream);
        return NULL;
    }
    xx_archive_record_state_init(state, format);
    state->internal_state = stream;
    state->free_internal = base64_stream_free;
    state->total_records = (int64_t)stream->count;
    if (!base64_copy_options(&state->options, options) || !base64_set_record(format, &state->current_record, stream)) {
        xx_archive_record_state_free(state);
        return NULL;
    }
    state->has_record = true;
    return state;
}

const xx_archive_record *xx_base64_get_current_archive_record(Abstractformat *format, xx_archive_record_state *state)
{
    return format && state && state->format == format && state->has_record ? &state->current_record : NULL;
}

bool xx_base64_archive_record_move_to_next(Abstractformat *format, xx_archive_record_state *state, xx_pd_struct *pd)
{
    base64_stream *stream;
    base64_context next;
    int64_t start;
    if (!format || !state || state->format != format || !state->has_record || !(stream = (base64_stream *)state->internal_state) || stream->index + 1U >= stream->count ||
        base64_next_header(format, &stream->context, &start) != 1 || !base64_parse_next(format, start, &next, pd)) {
        if (state) state->has_record = false;
        return false;
    }
    stream->context = next;
    ++stream->index;
    if (!base64_set_record(format, &state->current_record, stream)) {
        state->has_record = false;
        return false;
    }
    return true;
}

bool xx_base64_unpack_current_archive_record(Abstractformat *format, xx_archive_record_state *state, xx_pd_struct *pd)
{
    base64_stream *stream;
    const xx_var *path_option;
    const char *base = NULL;
    char *owned_base = NULL;
    char *path = NULL;
    bool result = false;
    bool created = false;
    if (!format || !state || state->format != format || !state->has_record || !(stream = (base64_stream *)state->internal_state) || stream->index >= stream->count ||
        (pd && xx_pd_is_stopped(pd)))
        return false;
    path_option = base64_option(&state->options, XX_META_ID_OPT_UNPACK_PATH);
    if (!path_option) {
        /* No destination: prove the text still decodes and report that. */
        return base64_decode(format, &stream->context, NULL, pd);
    }
    if (path_option->type == XX_VAR_TYPE_STRING || path_option->type == XX_VAR_TYPE_STRING_VIEW) base = xx_var_get_str(path_option);
    else if (path_option->type == XX_VAR_TYPE_WSTRING || path_option->type == XX_VAR_TYPE_WSTRING_VIEW) {
        owned_base = xx_str_unicode_to_utf8(xx_var_get_wstr(path_option));
        base = owned_base;
    }
    if (!base) goto done;
    {
        const char *name = stream->name;
        bool separator = base[0] && base[xx_str_len(base) - 1U] != '/' && base[xx_str_len(base) - 1U] != '\\';
        /* A header name that would push the path past the Windows limit
         * gives way to the default name. */
        if (xx_str_len(base) + 1U + xx_str_len(name) > BASE64_PATH_MAX) name = BASE64_PAYLOAD_NAME;
        path = separator ? xx_str_concat3(base, "/", name) : xx_str_concat(base, name);
    }
    if (!path || !xx_store_create_dirs_a(path, false)) goto done;
    {
        xx_io_device *destination = xx_io_file_open(path, "wb");
        created = destination != NULL;
        if (!destination) goto done;
        result = base64_decode(format, &stream->context, destination, pd);
        if (xx_io_close(destination) != 0) result = false;
    }
done:
    if (!result && path && created) xx_rt_remove(path);
    if (path) xx_str_free(path);
    if (owned_base) xx_str_free(owned_base);
    return result;
}

void xx_base64_free_archive_records_reading(Abstractformat *format, xx_archive_record_state *state)
{
    (void)format;
    xx_archive_record_state_free(state);
}
