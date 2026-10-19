/* Private sorting implementation from src/formats/inno_setup/xx_inno_setup.c. */

static bool inno_head_before(const inno_ctx *ctx, uint32_t x, uint32_t y)
{
    return ctx->locs[x].chunk_offset < ctx->locs[y].chunk_offset;
}
