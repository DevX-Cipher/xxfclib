# xxfclib

A lightweight, portable, and safe **C library** template for data handling and binary buffer manipulation, supporting both **static** and **dynamic / shared (DLL)** builds.

## Project Layout

```
xxfclib/
├── CMakeLists.txt                      # Main CMake project configuration
├── README.md                           # Project documentation
├── release_version.txt                 # Semantic release version
├── include/
│   └── xxfclib/                        # Mirrors src/, folder for folder
│       ├── xxfclib.h                   # Umbrella header
│       ├── xxfc_defs.h                 # Status codes, macros, XXFC_API export/import
│       ├── formats/                    # One header per reader, in <category>/<name>/
│       ├── algo/                       # One header per codec, in <name>/
│       ├── die_engine/                 # die_engine.h
│       ├── scan/                       # Common scanning interface and options
│       └── io/ data/ buf/ ...          # One library-level header each
├── src/
│   ├── formats/                        # Native format readers and extractors
│   │   ├── xx_format.c                 # File-type detection and reader dispatch
│   │   ├── xx_memory_map.c             # Offset/address mapping shared by readers
│   │   ├── xx_data_signature.c         # Signature notation and matching
│   │   └── <category>/<name>/xx_<name>.c  # archive/zip, installer/nsis, filesystem/ntfs, ...
│   │                                   # (categories: docs/FORMAT_LAYOUT.md)
│   ├── algo/                           # Native codecs (deflate, lzma, lzh, dcl, ...)
│   ├── die_engine/                     # Detect-It-Easy scan engine and its script API
│   ├── scan/                           # Callback-based interface for scanning engines
│   ├── io/                             # File, memory and multi-volume I/O devices
│   ├── platforms/                      # Windows / POSIX I/O backends
│   ├── data/                           # Binary data, search, xx_pd
│   ├── buf/                            # Byte buffers
│   ├── memory/                         # Allocation
│   ├── strings/                        # String functions
│   ├── rt/                             # CRT-free runtime (memcpy, memset, snprintf, ...)
│   ├── terminal/                       # Console output and platform mode restoration
│   ├── settings/                       # Typed INI and current-user native settings
│   ├── xfileunpacker/                  # Shared XFileUnpacker archive engine
│   ├── fs/                             # Paths and directory listing
│   ├── var/ list/ tree/                # Variant values, lists and rooted trees
│   ├── json/ xml/                      # JSON and XML
│   ├── js/                             # Script engine used by die_engine
│   └── global/                         # Buffer sizes, CPU/terminal features and settings pointer
├── samples/
│   ├── console/                        # xxfc_dump: structure and metadata dumper
│   └── unpack/                         # xxfc_unpack: 7-Zip-style archive unpacker
├── tests/                              # Linkage and verification tests
└── packaging/
    └── windows/
        └── build_portable_windows.cmd  # Packaging script for Windows
```

## PE streams

PE32/PE64 readers provide incremental import, export, resource, metadata and symbol
cursors through `Abstractformat` callbacks and the common `xx_format_` API.
See [PE streaming API](docs/PE_STREAMS.md) for ownership, examples, supported
records and focused tests. Rebuild library consumers when using the enlarged
`Abstractformat` structure.

## Unpack handles

`xx_file_type_t` identifies a file or container. `xx_handle_type_t` identifies
an unpacking interpretation and uses independent `XX_HANDLE_TYPE_*` values.
A PE32 image can therefore offer `XX_HANDLE_TYPE_PE_ZIPSFX`, while a compressed
TAR can offer both `XX_HANDLE_TYPE_GZ` and `XX_HANDLE_TYPE_TAR_GZ`.

```c
xx_list_t *handles = xx_format_get_unpack_handle_types_device(device, true);
if (handles) {
    for (size_t i = 0; i < xx_list_count(handles); ++i) {
        xx_handle_type_t handle = *(const xx_handle_type_t *)xx_list_at(handles, i);
        /* Display xx_format_handle_type_to_string(handle), or select a reader. */
    }
    xx_list_destroy(handles);
}
```

Detection checks signature rules and native fixed anchors first, including
all applicable executable SFX/installer readers. It checks filename extensions
only when those probes find no unpack handle. `deep=true` enables structural
fallback when the preceding stages still found none. Profile-dependent raw
imports require explicit selection. Returned lists are deduplicated and owned
by the caller; the device and its original position are preserved.

`Abstractformat.handle_type` records the reader's unpack interpretation. Native
factories and successful common base-info handling populate it, and
`xx_format_get_handle_type()` refreshes it. Readers without the complete archive
streaming callbacks, or whose parsed contents are not unpackable, report
`XX_HANDLE_TYPE_UNKNOWN`. Use
`xx_format_create_handle_reader()` and `xx_format_free_reader()` to manage a
native handle reader; set passwords/options before validating it. Rebuild
consumers after this change to the public structure layout.
`NUMBERED_SPLIT` is handled by the unpacker's multi-file backend and has no
single-device native reader factory.

## Generic tree

`<xxfclib/tree/xx_tree.h>` provides an ordered, rooted tree of fixed-size
values alongside `xx_list`. Create it with `xx_tree_create(sizeof(value),
optional_destructor)`, add a root and children with `xx_tree_set_root` and
`xx_tree_append_child`, and release it with `xx_tree_destroy`. Nodes expose
parent/child/sibling navigation; `xx_tree_foreach` visits them in preorder.
`xx_tree_move` reparents a subtree without changing node pointers, and
`xx_tree_remove` destroys a subtree in postorder. Deep trees are traversed and
freed iteratively. Stack-allocated trees use `xx_tree_init` and
`xx_tree_cleanup`.

## Threads

`<xxfclib/threads/xx_threads.h>` provides threads (`xx_thread_create`,
`xx_thread_join`, `xx_thread_detach`), recursive mutexes, condition
variables, counting semaphores, `xx_once` and `long`/pointer atomics. All
objects are opaque handles, so the ABI does not depend on platform lock
sizes. Waits take a millisecond timeout or `XX_WAIT_INFINITE` and return
`XX_WAIT_OK`, `XX_WAIT_TIMEOUT` or `XX_WAIT_ERROR`. The Windows backend uses
KERNEL32 only and links in the CRT-free builds; condition variables are
resolved at run time, so on Windows XP `xx_cond_create` returns NULL. Other
platforms use POSIX threads.

## Formats and algorithms subset

Standalone consumers can include `xxformats.cmake` to build the format readers,
extractors and algorithms with their required I/O, memory, data and runtime
support. It excludes `die_engine`, its legacy parsers, the JavaScript
interpreter and its cdisasm dependency. Add `XXFORMATS_SOURCES` to a
static target, define `XXFC_STATIC` publicly, add `XXFORMATS_INCLUDE_DIR`
publicly and `XXFORMATS_INCLUDE_DIRS` privately, and link
`XXFORMATS_LIBRARIES`. XFileUnpacker uses this subset.

`cmake/xxfclib_xfileunpacker.cmake` adds the optional
`xxfclib::xfileunpacker_core` component. Its build-only engine headers,
implementation and source-built FreeArc SFX stub are under
`src/xfileunpacker`. The component links only the local
formats-profile library and platform libraries, and compiles all runtime
helper paths out with `XXFC_NO_EXTERNAL_HELPERS`.

## Disassembler dependency

The DIE script API uses the sibling `cdisasm` source tree for x86 decoding and
Intel text formatting. CMake defaults `XXFC_CDISASM_DIR` to `../cdisasm`; set
that cache path when using a different source layout. It builds cdisasm as a
static dependency of xxfclib, so CDiE executables need no separate decoder
DLL. CMake propagates the decoder archive to static xxfclib consumers;
manual linker commands must include cdisasm after xxfclib.
`cdisasm` is MIT licensed; its generated-data notices and license texts are in
its source tree.

## Terminal output

`xxfclib/terminal/xx_terminal.h` provides stdout/stderr output without format
string interpretation, console initialization and cleanup, and raw Windows
console attributes. The Windows implementation uses Win32 directly and does
not require the CRT. ANSI sequences and RGB/name conversion belong to the
caller; XOptions implements those color rules in `XColorString`.

The same module owns the common JSON and XML string writers used by the
console tools. `xx_terminal_writer` accepts a byte-sink callback, keeps the
first output error, validates shortest-form UTF-8, escapes JSON controls, and
filters characters forbidden by XML 1.0. Separate XML text and attribute
functions preserve attribute whitespace correctly. The callback design works
with standard streams, temporary staging files, memory buffers, and CRT-free
consumers without exposing a `FILE *` in the library ABI.

`xx_get_terminal_type()` detects stdout capability once, alongside CPU features
in `xx_global_init_features_once()`: `XX_TERMINAL_TYPE_NONE` for plain or
redirected output, `XX_TERMINAL_TYPE_ANSI`, or `XX_TERMINAL_TYPE_WINDOWS` for
native Windows colors. Stderr is checked independently when initialized.
`xx_set_terminal_type()` overrides stdout's preference; initialization still
keeps redirected output plain. `xx_set_color_output_enabled(false)` disables
all XOptions color output, including an already initialized console state.
The default color setting is enabled.

```c
xx_terminal_state terminal = xx_terminal_init(XX_TERMINAL_STDOUT);
xx_terminal_print(&terminal, "Progress: 100%\n");
xx_terminal_flush(&terminal);
xx_terminal_finish(&terminal);
```

Consumers needing only these services can compile the source list from
`xxterminal.cmake` with `XXFC_STATIC` and `XXTERMINAL_INCLUDE_DIR`, or include
`xxterminal.pri` in qmake. These compile the terminal and global modules
without the format readers or codecs. Consumers linking the full library
already have these symbols and should use that library's global state.

## Settings

`xxfclib/settings/xx_settings.h` provides memory, INI and native stores. Values
have explicit enum types: boolean, signed/unsigned 64-bit integer, double,
UTF-8 string, bytes, string list and opaque consumer data. `xx_settings_set()`
copies its value; `xx_settings_get()` returns a borrowed value until the next
store mutation. Strings and bytes have explicit lengths, including embedded
nulls. String-list items are null-terminated UTF-8 strings.

The optional `xxfclib/global/xx_settings_global.h` module declares the global
`xx_get_settings()` pointer, which starts at `NULL` (settings disabled).
Attach a store with `xx_set_settings()`. Loading/saving a null store succeeds
without I/O; destroying an attached store resets the global pointer. No store
is created by CPU/terminal feature initialization. Creation does not load,
and destruction does not save. Store ownership remains with the caller.
The pointer implementation lives in `src/global/xx_settings_global.c` and is
included by the settings source lists. `xx_global.h`/`xx_global.c` and the
terminal-only source lists do not depend on settings.

```c
xx_settings *settings = xx_settings_create_ini("config/application.ini");
if (settings && xx_settings_load(settings) == XXFC_OK) {
    xx_settings_value value = {0};
    value.type = XX_SETTINGS_VALUE_BOOL;
    value.data.boolean = true;
    xx_set_settings(settings);
    if (xx_settings_set(settings, "view/dark", &value) == XXFC_OK) {
        xxfc_status_t status = xx_settings_save(settings);
        /* Handle status before discarding the store. */
        (void)status;
    }
}
xx_settings_destroy(settings);
```

`xx_settings_create_native(organization, application)` uses HKCU
`Software\\organization\\application` on Windows, the CFPreferences domain
`organization.application` on macOS, and
`$XDG_CONFIG_HOME/organization/application.conf` on Linux/FreeBSD. A missing or
relative XDG_CONFIG_HOME falls back to `$HOME/.config`. These are current-user
settings. Native Windows strings use UTF-16; C paths and names use UTF-8.
macOS maps slash-separated groups to native dot-separated preference keys,
escaping literal dots/middle dots to retain distinct key names.
The Windows backend resolves registry APIs from System32 dynamically to retain
the existing CRT-free, kernel32-only import constraint. Windows registry keys
and value names follow the registry's case-insensitive naming rules.

INI saves merge changed keys into the current file and replace it atomically.
Loads are transactional: malformed input preserves the current snapshot.
Native saves update only changed keys; a failed registry/preferences save can
have applied earlier keys, and retains dirty values for retry. `clear()` removes
keys present in the current snapshot. Concurrent access needs external
synchronization; load-merge-replace does not lock against simultaneous writers.
Files/encoded values are capped at 16 MiB. INI values use `@XX...` markers for
types and quoting/escaping for text; text beginning with `@` is escaped.

For standalone consumers, `xxsettings.cmake` supplies `XXSETTINGS_SOURCES`,
`XXSETTINGS_INCLUDE_DIR` and `XXSETTINGS_LIBRARIES`; define `XXFC_STATIC` on the
consumer. qmake consumers can include `xxsettings.pri`. Remove duplicate common
sources when combining the terminal/settings lists, as XOptions does.

Configure `tests/settings` for the focused C tests, including Windows CRT-free
linkage. Native tests create and remove isolated test application settings.

`xxfclib/settings/xx_shortcuts.h` loads named keyboard bindings from
`shortcuts.ini` using the same INI reader. `xx_shortcuts_load(path, defaults,
count, &list)` copies defaults and applies `[shortcuts]` overrides. A null path
uses `shortcuts.ini` in the current directory; missing files preserve defaults.
Empty values disable bindings. Additional action names are retained for the
consumer to map, and unrelated INI sections are ignored. The loader never
writes the file. Errors return a null result. Access owned entries with
`xx_shortcuts_count()` / `xx_shortcuts_at()` and release them with
`xx_shortcuts_destroy()`. The module is included in both settings source lists
and supports the CRT-free runtime. Consumers validate actual key combinations.

```ini
[shortcuts]
open=Ctrl+O
extract_selected=Ctrl+Shift+E
refresh=F5
```

Additional archive, disk-image and filesystem readers, explicit reader selection, and supported subsets: [native format expansion](docs/additional_native_formats.md).

ZIP extraction and creation methods, supported profiles, limits and focused tests:
[ZIP method support](docs/zip_methods.md).
The latest native listing/extraction work, reference projects, independent
fixtures and remaining variant gaps are documented in
[native reader expansion](docs/native_expansion_20260929.md).

### ARM PMULL CRC acceleration

CRC32 (IEEE) and CRC32C use a three-stream CRC32 + PMULL backend for buffers
of at least 3072 bytes when both `xx_is_arm_crc32_enabled()` and
`xx_is_arm_pmull_enabled()` are true. Smaller buffers retain their existing
backend. MPEG-2 CRC and CRC64 are unchanged.

`xx_has_arm_pmull()`, `xx_set_arm_pmull_enabled(bool)`,
`xx_enable_arm_pmull(bool)`, and `xx_is_arm_pmull_enabled()` follow the existing
acceleration API, including the `xx_global_*` aliases. PMULL defaults on when
supported. Detection uses macOS sysctl, Linux/Android HWCAP, or Windows ARM
crypto capability; optional instruction flags remain local to the backend.

Console options: `--armpmull`, `--noarmpmull`, `--arm-pmull`, and
`--no-arm-pmull`. The shared optimization widget exposes **Use Arm PMULL**.
See `../xxfclib_tests/README.md` for correctness tests and measured speed.

### Explicit DEFLATE packing candidate count

ZIP DEFLATE (method 8) and Deflate64 (method 9) packing accept the optional
integer `XX_META_ID_COMPRESSION_CANDIDATES` (alias
`XX_META_ID_OPT_COMPRESSION_CANDIDATES`). It can be supplied in the writer's
options list, per archive record, or as a format extra parameter. Precedence
is record > writer options > format parameter. A record value of zero resets
an inherited count to level-based behavior.

```c
xx_archive_record_set_meta_u64(&record, XX_META_ID_COMPRESSION_CANDIDATES, 128);
```

A positive count overrides the compression level: it sets the maximum
hash-chain candidates searched at each position and selects the normal
compression path, even if level 0 was supplied. Zero or absence keeps the
existing level mapping (0=stored blocks, 1–3=4 candidates, 4–6=16,
7–9=128). For Deflate64 an explicit count also uses the normal long-match
limit instead of the low-level 258-byte cap. Explicit ZIP STORE (method 0)
remains stored. Other ZIP codecs keep their existing level handling.
Negative, floating-point, string, and nonrepresentable counts are rejected
before the member is written. This option is a packing control, not an
on-disk ZIP metadata field. It is local to the operation and also applies
to encrypted ZIP entries.

Raw DEFLATE APIs provide the same control through `xx_deflate_pack_options`
and the new `xx_deflate_pack_device_with_options`,
`xx_deflate_pack_source_with_options`, and
`xx_deflate_compress_memory_with_options` functions:

```c
xx_deflate_pack_options options = {128};
xx_deflate_pack_device_with_options(source, 0, source_size, destination,
                                   6, false, 0, &options, pd);
```

Passing `NULL` options, or `{0}`, preserves level-based packing. Existing
APIs remain available and delegate with `NULL`; there is no global candidate
setting. The candidate budget does not enlarge the DEFLATE history window.


ZIP DEFLATE and Deflate64 also accept `XX_META_ID_COMPRESSION_LAZY_MATCH`
(alias `XX_META_ID_OPT_COMPRESSION_LAZY_MATCH`). This nonnegative integer
sets a match-length threshold for one-byte lookahead. Zero or absence keeps
greedy parsing; 16 checks the next position when the current match is shorter
than 16 bytes and emits a literal if the next match is longer. Larger thresholds
apply this check to longer matches; they do not increase lookahead distance or
guarantee smaller output. Values beyond the codec's maximum match length are
equivalent to that maximum.

```c
xx_archive_record_set_meta_u64(&record, XX_META_ID_COMPRESSION_CANDIDATES, 128);
xx_archive_record_set_meta_u64(&record, XX_META_ID_COMPRESSION_LAZY_MATCH, 16);
```

Resolution is record > writer options > format parameter. An explicit zero
disables inherited lazy matching. Invalid types, negative values and values
beyond `SIZE_MAX` are rejected before member data is written. Lazy matching
alone does not override levels: level 0 still stores blocks unless a positive
candidate count selects compression. The setting applies to encrypted entries
as well; ZIP STORE and other codecs are unaffected.

For raw streams use `xx_deflate_pack_options_ex options = {128, 16}` with
`xx_deflate_pack_device_with_options_ex`,
`xx_deflate_pack_source_with_options_ex`, or
`xx_deflate_compress_memory_with_options_ex`. The extended structure contains
`max_candidates` and `lazy_match_limit`. The original options structure and
APIs retain their layout and greedy behavior. Both options are local to each
packing operation.


`XX_META_ID_COMPRESSION_SHORT_MATCH_FILTER` is a boolean ZIP DEFLATE/Deflate64
packing option (alias `XX_META_ID_OPT_COMPRESSION_SHORT_MATCH_FILTER`). With
`true`, a selected match of exactly 3 bytes is discarded if its distance is
more than 4096 bytes; the encoder emits a literal instead. Matches at distance
4096, and matches longer than 3 bytes, remain eligible. This is a heuristic,
not an exact Huffman bit-cost calculation, and does not guarantee smaller output.

```c
xx_archive_record_set_meta_bool(&record, XX_META_ID_COMPRESSION_SHORT_MATCH_FILTER, true);
```

It combines independently with candidate count and lazy matching. Default or
`false` preserves existing behavior. Resolution is record > writer options >
format parameter; explicit `false` disables inherited `true`. Only boolean
metadata is accepted, with invalid types rejected before member data is written.
Encrypted entries use the same option; explicit STORE and other codecs remain
unchanged. It does not override the compression level.

Raw extended packing options now include `bool short_match_filter`:
`xx_deflate_pack_options_ex options = {128, 16, true}`. Rebuild callers using
this extended struct with the updated header and library. The original
`xx_deflate_pack_options` and original APIs remain unchanged, with filtering off.


ZIP DEFLATE/Deflate64 also accept the nonnegative integer packing thresholds
`XX_META_ID_COMPRESSION_NICE_MATCH` and `XX_META_ID_COMPRESSION_GOOD_MATCH`
(with corresponding `XX_META_ID_OPT_*` aliases). Zero or absence disables
each shortcut and preserves the existing search. Both use record > writer >
format precedence; explicit zero disables inherited values. Invalid types,
negative values and values greater than `SIZE_MAX` fail before member output.

* `nice_match`: stop the main hash-chain search when the best match reaches
  this length (or the maximum available match length).
* `good_match`: once the best match reaches this length, reduce the total
  candidate budget for that position to `max(1, max_candidates / 4)`, using
  the effective level-based budget if no explicit count was supplied. Already
  examined candidates count towards that total. Reduction occurs only once.

Both shortcuts apply only to valid matches of at least 3 bytes; thresholds
1 or 2 therefore act as 3. Values above the codec's maximum match length
cannot trigger. Neither shortcut changes the separate one-byte lazy proof
search, compression level selection, or ZIP STORE behavior. Both apply to
encrypted entries and can be combined with lazy matching and short-match
filtering. Smaller thresholds can save search work but may increase output
size. These are explicit xxfclib semantics, not a complete Info-ZIP profile.

```c
xx_archive_record_set_meta_u64(&record, XX_META_ID_COMPRESSION_NICE_MATCH, 128);
xx_archive_record_set_meta_u64(&record, XX_META_ID_COMPRESSION_GOOD_MATCH, 8);
```

Raw `xx_deflate_pack_options_ex` gains `size_t nice_match` and
`size_t good_match` after `short_match_filter`:
`xx_deflate_pack_options_ex options = {128, 16, true, 128, 8}`.
Rebuild users of this extended struct with the updated header and library.
The original options struct and original APIs retain their defaults.

## LZFSE, LZ4 and LZMA packing

All three algorithms now support encoding and decoding without an external
codec library. LZMA/LZMA2 already had native encoders and decoders; the new
work adds LZFSE and LZ4 encoders alongside their existing bounded decoders.

* `<xxfclib/algo/lzfse/xx_lzfse.h>`: `xx_lzfse_compress_bound`,
  `xx_lzfse_compress_memory`, `xx_lzfse_pack_device`, and the existing
  `xx_lzfse_decompress_memory`. Encodes real LZFSE/LZVN blocks with raw fallback,
  not just a wrapper around uncompressed bytes. Encoding accepts at most
  `INT32_MAX-1` input bytes per call. Output capacity is capped internally at
  `source_size+12`, ensuring incompressible input can fall back to a raw block.
* `<xxfclib/algo/lz4/xx_lz4.h>`: `xx_lz4_compress_block` encodes raw blocks;
  `xx_lz4_compress_memory` / `xx_lz4_pack_device` produce standard LZ4 frames
  with independent blocks up to 4 MiB, content size, header checksum and
  content checksum. Incompressible blocks are stored. Existing block/frame
  decoders handle the output. `xx_lz4_compress_bound` bounds frame size;
  raw-block bound is `n+n/255+16`, within the documented source-size limits.
* `<xxfclib/algo/lzma/xx_lzma.h>`: existing `xx_lzma_compress_memory`,
  `xx_lzma_pack_device` and decode APIs use explicit LZMA properties. Existing
  LZMA-Alone format writer produces `.lzma`; XZ and ZIP use their own wrappers.

Memory encoders accept NULL source only for empty input, reject invalid size /
capacity, and reset optional `out_written` to zero on failure. Input and output
must not overlap. The new device encoders buffer the complete known-size input
and output; they support partial I/O, check cancellation between I/O chunks and
before/after encoding, and never close caller devices. LZ4 device packing is
limited to `INT32_MAX` input bytes; LZFSE to `INT32_MAX-1`. They do not provide
incremental/resumable encoding.

LZ4 **standard frames** differ from Apple's `COMPRESSION_LZ4` framing. The raw
block API is interoperable with `COMPRESSION_LZ4_RAW`. LZFSE streams interoperate
with `COMPRESSION_LZFSE`. These codec APIs do not create Apple Archive `.aar`
containers; container handling is a separate layer.

LZFSE encoding incorporates Apple's BSD-3-Clause reference encoder directly in
the build, with namespaced symbols and xxfclib allocation/runtime functions.
The existing native decoder remains in use. Source provenance, the local FSE
undefined-shift fix and the full redistribution notice are under
[src/algo/lzfse/reference](src/algo/lzfse/reference/README.md), including
[LICENSE](src/algo/lzfse/reference/LICENSE). Retain that notice with binary
redistributions containing the encoder. Main CMake and the formats-only source
profile both include the encoder; macOS Compression is linked only by tests.
