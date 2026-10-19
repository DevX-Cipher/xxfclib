/* Private sorting implementation from src/formats/installer/advanced_installer_bootstrapper/xx_advanced_installer_bootstrapper.c. */

static uint8_t aib_fold(uint8_t c)
{
    return (c >= (uint8_t)'a' && c <= (uint8_t)'z') ? (uint8_t)(c - 32U) : c;
}
