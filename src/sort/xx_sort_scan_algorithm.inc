/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */

/* Private algorithm template, instantiated for direct and cached signature
 * records. Keep a single implementation: its exact comparisons and moves
 * determine the result when the signature comparator is intransitive. */

static void SIGNATURE_SORT_FUNCTION(swap)(SIGNATURE_SORT_RECORD *pA, SIGNATURE_SORT_RECORD *pB)
{
    SIGNATURE_SORT_RECORD temporary = *pA;
    *pA = *pB;
    *pB = temporary;
}

/* Reproduce the reference Linux std::sort's median-of-three introsort and
 * final insertion pass. Its comparator is intransitive for mixed priority
 * names, so using a different sorting algorithm produces different results.
 * Explicit bounds replace the reference's unguarded scans: custom database
 * names must never let that comparator read outside the array. */
static size_t SIGNATURE_SORT_FUNCTION(partition)(SIGNATURE_SORT_RECORD *pRecords, size_t first, size_t last)
{
    size_t a = first + 1;
    size_t b = first + (last - first) / 2;
    size_t c = last - 1;
    size_t median;
    size_t left = first + 1;
    size_t right = last;

    if (SIGNATURE_SORT_LESS(&pRecords[a], &pRecords[b])) {
        if (SIGNATURE_SORT_LESS(&pRecords[b], &pRecords[c])) median = b;
        else if (SIGNATURE_SORT_LESS(&pRecords[a], &pRecords[c])) median = c;
        else median = a;
    } else if (SIGNATURE_SORT_LESS(&pRecords[a], &pRecords[c])) median = a;
    else if (SIGNATURE_SORT_LESS(&pRecords[b], &pRecords[c])) median = c;
    else median = b;

    SIGNATURE_SORT_FUNCTION(swap)(&pRecords[first], &pRecords[median]);
    for (;;) {
        while (left < last && SIGNATURE_SORT_LESS(&pRecords[left], &pRecords[first])) ++left;
        --right;
        while (right > first && SIGNATURE_SORT_LESS(&pRecords[first], &pRecords[right])) --right;
        if (left >= right) return left;
        SIGNATURE_SORT_FUNCTION(swap)(&pRecords[left], &pRecords[right]);
        ++left;
    }
}

static void SIGNATURE_SORT_FUNCTION(adjust_heap)(SIGNATURE_SORT_RECORD *pRecords, size_t hole, size_t count, SIGNATURE_SORT_RECORD value)
{
    size_t top = hole;
    size_t child = hole;

    while (child < (count - 1) / 2) {
        child = 2 * (child + 1);
        if (SIGNATURE_SORT_LESS(&pRecords[child], &pRecords[child - 1])) --child;
        pRecords[hole] = pRecords[child];
        hole = child;
    }
    if ((count & 1) == 0 && child == (count - 2) / 2) {
        child = 2 * (child + 1);
        pRecords[hole] = pRecords[child - 1];
        hole = child - 1;
    }
    while (hole > top) {
        size_t parent = (hole - 1) / 2;
        if (!SIGNATURE_SORT_LESS(&pRecords[parent], &value)) break;
        pRecords[hole] = pRecords[parent];
        hole = parent;
    }
    pRecords[hole] = value;
}

static void SIGNATURE_SORT_FUNCTION(heap_sort)(SIGNATURE_SORT_RECORD *pRecords, size_t count)
{
    size_t parent;

    if (count < 2) return;
    parent = (count - 2) / 2;
    for (;;) {
        SIGNATURE_SORT_FUNCTION(adjust_heap)(pRecords, parent, count, pRecords[parent]);
        if (parent == 0) break;
        --parent;
    }
    while (count > 1) {
        SIGNATURE_SORT_RECORD value = pRecords[--count];
        pRecords[count] = pRecords[0];
        SIGNATURE_SORT_FUNCTION(adjust_heap)(pRecords, 0, count, value);
    }
}

static void SIGNATURE_SORT_FUNCTION(introsort)(SIGNATURE_SORT_RECORD *pRecords, size_t first, size_t last, unsigned int depth)
{
    while (last - first > 16) {
        size_t cut;
        if (depth == 0) {
            SIGNATURE_SORT_FUNCTION(heap_sort)(pRecords + first, last - first);
            return;
        }
        --depth;
        cut = SIGNATURE_SORT_FUNCTION(partition)(pRecords, first, last);
        SIGNATURE_SORT_FUNCTION(introsort)(pRecords, cut, last, depth);
        last = cut;
    }
}

static void SIGNATURE_SORT_FUNCTION(insert)(SIGNATURE_SORT_RECORD *pRecords, size_t index)
{
    SIGNATURE_SORT_RECORD value = pRecords[index];
    size_t hole = index;

    while (hole > 0 && SIGNATURE_SORT_LESS(&value, &pRecords[hole - 1])) {
        pRecords[hole] = pRecords[hole - 1];
        --hole;
    }
    pRecords[hole] = value;
}

static void SIGNATURE_SORT_FUNCTION(sort)(SIGNATURE_SORT_RECORD *pRecords, size_t count)
{
    size_t threshold;
    size_t i;
    unsigned int depth = 0;
    if (!pRecords || count < 2) return;
    for (i = count; i > 1; i >>= 1) ++depth;
    SIGNATURE_SORT_FUNCTION(introsort)(pRecords, 0, count, 2 * depth);

    threshold = count < 16 ? count : 16;
    for (i = 1; i < threshold; ++i) {
        if (SIGNATURE_SORT_LESS(&pRecords[i], &pRecords[0])) {
            SIGNATURE_SORT_RECORD value = pRecords[i];
            size_t hole = i;
            while (hole > 0) {
                pRecords[hole] = pRecords[hole - 1];
                --hole;
            }
            pRecords[0] = value;
        } else {
            SIGNATURE_SORT_FUNCTION(insert)(pRecords, i);
        }
    }
    for (i = threshold; i < count; ++i) SIGNATURE_SORT_FUNCTION(insert)(pRecords, i);
}
