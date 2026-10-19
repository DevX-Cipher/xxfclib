/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation included by src/fs/xx_fs.c.
 * Retains that translation unit's private types and static linkage.
 */

/* By name alone. Used when the caller's order is the directory's own name
 * order rather than a presentation order. */
static int xx_fs_entry_compare_name(const void *left, const void *right)
{
    const xx_fs_entry_t *a = *(const xx_fs_entry_t *const *)left;
    const xx_fs_entry_t *b = *(const xx_fs_entry_t *const *)right;

    return xx_rt_strcmp(a->name, b->name);
}

/* Directories first, then by name, so a listing is stable across platforms
 * whose enumeration order differs. */
static int xx_fs_entry_compare(const void *left, const void *right)
{
    const xx_fs_entry_t *a = *(const xx_fs_entry_t *const *)left;
    const xx_fs_entry_t *b = *(const xx_fs_entry_t *const *)right;

    if (a->type != b->type) {
        return a->type == XX_FS_ENTRY_DIR ? -1 : 1;
    }
    return xx_rt_strcmp(a->name, b->name);
}

