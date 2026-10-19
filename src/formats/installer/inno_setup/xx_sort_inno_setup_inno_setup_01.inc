/* Private sorting implementation from src/formats/installer/inno_setup/xx_inno_setup.c. */

/* Location indices by chunk start. An xx_sort_callback; context is the
 * inno_ctx. */
static int inno_head_compare(const void *left, const void *right, void *context)
{
    const inno_ctx *ctx = (const inno_ctx *)context;
    int64_t x = ctx->locs[*(const uint32_t *)left].chunk_offset;
    int64_t y = ctx->locs[*(const uint32_t *)right].chunk_offset;
    return x < y ? -1 : (x > y ? 1 : 0);
}
