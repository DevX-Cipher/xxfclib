# Sorting

`xx_sort.c` and `platforms/` implement the public array sorting API in
`xxfclib/sort/xx_sort.h`. Runtime compatibility entry points also live here.
`xx_sort_list.c` and `xx_sort_scan.c` retain list and signature ordering policies.

Private `.inc` files hold format, codec, filesystem, and JavaScript sorting
code. Consumers include them where the original functions or loops were
defined, so private types, static linkage, callback behavior, and ordering
remain unchanged. These fragments are included sources, not separate
translation units. Their relative includes resolve from `src/sort`.

The shared API offers the existing platform default sort, a context-based
heapsort, the signature database's exact quicksort, and a stable insertion
sort. Algorithms with format-defined tie behavior retain their original
implementation in their private fragment.

The library-owned array algorithms instantiate `xx_sort_algorithms.inc` for
scalar, SSE2, and AVX2 element movement. They select a backend once per call
using `xx_is_sse2_enabled()` and `xx_is_avx2_enabled()`, including the existing
CPU and OS checks. Elements below 16 bytes remain scalar; SSE2 starts at 16
bytes and AVX2 at 64 bytes. Disabling both switches selects scalar movement.
Unaligned vector loads and stores stay within each element, including tails.
All backends retain the same comparisons, swaps, stability, and tie ordering.

ISA flags apply only to the backend translation units. Hosted POSIX `xx_sort`
continues to use libc; the context, quick, and stable APIs use these backends
on supported x86 builds. Format and codec algorithms retain their own policy.

`xx_list_sort` keeps equal elements in their input order. It selects scalar,
SSE2, or AVX2 movement once per call, using the global switches and element
size thresholds above. Larger lists reuse one temporary merge buffer and the
existing native memory copy kernels. Small lists and allocation failures use
stable in-place merges with binary-search cuts and block rotations. List
storage, capacity, count, and ownership callbacks remain unchanged.
