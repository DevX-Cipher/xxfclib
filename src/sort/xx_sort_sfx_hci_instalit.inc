/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its domain types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

        /* Insertion sort: at most 24 values. */
        for (index = 1U; index < count; ++index) {
            unsigned value = reversed[index], at = index;
            while (at > 0U && reversed[at - 1U] > value) {
                reversed[at] = reversed[at - 1U];
                --at;
            }
            reversed[at] = value;
        }
