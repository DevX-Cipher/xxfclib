/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its domain types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static void zoom_huf_update(zoom_huf *h, int32_t symbol)
{
    int32_t c;

    if ((int32_t)h->freq[ZOOM_R] == ZOOM_MAX_FREQ) {
        /* DELIBERATE, do not "fix": Zoom's decoder simply stops re-weighting
         * from here.  The textbook LZHUF halves every frequency and rebuilds
         * the tree; Zoom does not, and the two are not interchangeable. */
        return;
    }

    c = h->prnt[symbol + ZOOM_T];

    do {
        uint16_t f;
        int32_t l;

        h->freq[c] = (uint16_t)(h->freq[c] + 1);
        f = h->freq[c];
        l = c + 1;

        if (h->freq[l] < f) {
            int32_t i;
            int32_t j;

            /* freq[T] is the 0xFFFF sentinel that stops this walk, so l may
             * legitimately reach T - one past the last node - before the
             * decrement pulls it back into range. */
            l = c + 2;
            while ((l <= ZOOM_T) && (h->freq[l] < f)) ++l;
            --l;
            if ((l < 0) || (l >= ZOOM_T)) return;

            h->freq[c] = h->freq[l];
            h->freq[l] = f;

            i = h->son[c];
            h->prnt[i] = l;
            if (i < ZOOM_T) h->prnt[i + 1] = l;

            j = h->son[l];
            h->son[l] = i;
            h->prnt[j] = c;
            if (j < ZOOM_T) h->prnt[j + 1] = c;

            h->son[c] = j;
            c = l;
        }

        c = h->prnt[c];
    } while (c != 0);
}
