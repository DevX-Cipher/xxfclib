/* Private sorting implementation from src/formats/installer/installshield_3/xx_installshield_3.c. */

/* ------------------------------------------------------------------------ */
/* Member names                                                             */
/* ------------------------------------------------------------------------ */

static uint8_t is3_fold(uint8_t c)
{
    if (c >= 'a' && c <= 'z') return (uint8_t)(c - 'a' + 'A');
    return c;
}
