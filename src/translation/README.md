# PO translation catalogs

The public API is `<xxfclib/translation/xx_translation.h>`. The memory-only
reader needs only xxfclib's memory/runtime primitives and can be embedded in
hosted or CRT-free C11 libraries. `xxtranslation.cmake` exports
`XXTRANSLATION_SOURCES` and `XXTRANSLATION_INCLUDE_DIR`. Add
`XXTRANSLATION_IO_SOURCES` with the normal I/O sources for UTF-8 file loading.
Full, formats and emulator-common library profiles include both modules.

```c
xx_translation *catalog = NULL;
size_t line = 0;
if (xx_translation_load_po(bytes, size, &catalog, &line) == XX_TRANSLATION_OK) {
    const char *label = xx_translation_gettext(catalog, "Scan");
    const char *open = xx_translation_pgettext(catalog, "verb", "Open");
    const char *files = xx_translation_ngettext(catalog, "file", "files", n);
    /* Use/copy borrowed results before destroying the catalog. */
    xx_translation_destroy(catalog);
}
```

The loader copies input, accepts a UTF-8 BOM, LF/CRLF, comments, obsolete entries,
multiline strings, C escapes, contexts, fuzzy flags and indexed plural forms.
It rejects duplicate keys, malformed or incomplete entries, invalid UTF-8/NULs,
unsupported charsets, and invalid plural syntax. Metadata is not displayed as a
message. Missing, fuzzy, obsolete and empty translations fall back to the input
source; plural fallback selects the source singular only for `n == 1`.

Plural-Forms supports `n`, unsigned integer constants, parentheses, unary
`! + -`, `* / % + -`, comparisons, `&& ||` and right-associative `?:` with C
precedence and short circuit evaluation. Arithmetic uses unsigned 64-bit values.
A catalog can contain up to 16 forms and its plural expression up to 256 nodes
and 64 levels. Division by zero or out-of-range results use source fallback.
Catalogs are immutable after loading and may be queried concurrently; callers
must serialize destruction. There is no process-global locale state, gettext
runtime, locale discovery, MO loading, or legacy charset conversion.

Run the focused tests without building the format engines:

```sh
cmake -S tests/translation -B build-translation
cmake --build build-translation
ctest --test-dir build-translation --output-on-failure
```

Or enable `XXFC_BUILD_TRANSLATION_TESTS` in the main build. Tests include
allocation failure injection and verify cleanup of every partial parse.

PO syntax follows the [GNU gettext manual](https://www.gnu.org/software/gettext/manual/html_node/PO-Files.html).
