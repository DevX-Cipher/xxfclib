/* SPDX-License-Identifier: MIT. Physical wire fields; see permanent archiveresidual scope. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_archiveresidual.h"
static const sx_layout *const sx_archiveresidual_layouts[]={
 &sxarfinal_pcsecure_physical_header,
 &sxarfinal_unixcompact_prefix,
 &sxarfinal_unixcompact_code1_bit0,
 &sxarfinal_unixcompact_code1_bit1,
 &sxarfinal_unixcompact_code1_bit2,
 &sxarfinal_unixcompact_code1_bit3,
 &sxarfinal_unixcompact_code1_bit4,
 &sxarfinal_unixcompact_code1_bit5,
 &sxarfinal_unixcompact_code1_bit6,
 &sxarfinal_unixcompact_code1_bit7,
 &sxarfinal_unixcompact_code2_bit0,
 &sxarfinal_unixcompact_code2_bit1,
 &sxarfinal_unixcompact_code2_bit2,
 &sxarfinal_unixcompact_code2_bit3,
 &sxarfinal_unixcompact_code2_bit4,
 &sxarfinal_unixcompact_code2_bit5,
 &sxarfinal_unixcompact_code2_bit6,
 &sxarfinal_unixcompact_code2_bit7,
 &sxarfinal_unixcompact_code3_bit0,
 &sxarfinal_unixcompact_code3_bit1,
 &sxarfinal_unixcompact_code3_bit2,
 &sxarfinal_unixcompact_code3_bit3,
 &sxarfinal_unixcompact_code3_bit4,
 &sxarfinal_unixcompact_code3_bit5,
 &sxarfinal_unixcompact_code3_bit6,
 &sxarfinal_unixcompact_code3_bit7,
 &sxarfinal_unixcompact_code4_bit0,
 &sxarfinal_unixcompact_code4_bit1,
 &sxarfinal_unixcompact_code4_bit2,
 &sxarfinal_unixcompact_code4_bit3,
 &sxarfinal_unixcompact_code4_bit4,
 &sxarfinal_unixcompact_code4_bit5,
 &sxarfinal_unixcompact_code4_bit6,
 &sxarfinal_unixcompact_code4_bit7,
 &sxarfinal_unixcompact_code5_bit0,
 &sxarfinal_unixcompact_code5_bit1,
 &sxarfinal_unixcompact_code5_bit2,
 &sxarfinal_unixcompact_code5_bit3,
 &sxarfinal_unixcompact_code5_bit4,
 &sxarfinal_unixcompact_code5_bit5,
 &sxarfinal_unixcompact_code5_bit6,
 &sxarfinal_unixcompact_code5_bit7,
 &sxarfinal_unixcompact_code6_bit0,
 &sxarfinal_unixcompact_code6_bit1,
 &sxarfinal_unixcompact_code6_bit2,
 &sxarfinal_unixcompact_code6_bit3,
 &sxarfinal_unixcompact_code6_bit4,
 &sxarfinal_unixcompact_code6_bit5,
 &sxarfinal_unixcompact_code6_bit6,
 &sxarfinal_unixcompact_code6_bit7,
 &sxarfinal_unixcompact_code7_bit0,
 &sxarfinal_unixcompact_code7_bit1,
 &sxarfinal_unixcompact_code7_bit2,
 &sxarfinal_unixcompact_code7_bit3,
 &sxarfinal_unixcompact_code7_bit4,
 &sxarfinal_unixcompact_code7_bit5,
 &sxarfinal_unixcompact_code7_bit6,
 &sxarfinal_unixcompact_code7_bit7,
 &sxarfinal_unixcompact_code8_bit0,
 &sxarfinal_unixcompact_code8_bit1,
 &sxarfinal_unixcompact_code8_bit2,
 &sxarfinal_unixcompact_code8_bit3,
 &sxarfinal_unixcompact_code8_bit4,
 &sxarfinal_unixcompact_code8_bit5,
 &sxarfinal_unixcompact_code8_bit6,
 &sxarfinal_unixcompact_code8_bit7,
 &sxarfinal_unixcompact_code9_bit0,
 &sxarfinal_unixcompact_code9_bit1,
 &sxarfinal_unixcompact_code9_bit2,
 &sxarfinal_unixcompact_code9_bit3,
 &sxarfinal_unixcompact_code9_bit4,
 &sxarfinal_unixcompact_code9_bit5,
 &sxarfinal_unixcompact_code9_bit6,
 &sxarfinal_unixcompact_code9_bit7,
 &sxarfinal_unixcompact_code10_bit0,
 &sxarfinal_unixcompact_code10_bit1,
 &sxarfinal_unixcompact_code10_bit2,
 &sxarfinal_unixcompact_code10_bit3,
 &sxarfinal_unixcompact_code10_bit4,
 &sxarfinal_unixcompact_code10_bit5,
 &sxarfinal_unixcompact_code10_bit6,
 &sxarfinal_unixcompact_code10_bit7,
 &sxarfinal_unixcompact_code11_bit0,
 &sxarfinal_unixcompact_code11_bit1,
 &sxarfinal_unixcompact_code11_bit2,
 &sxarfinal_unixcompact_code11_bit3,
 &sxarfinal_unixcompact_code11_bit4,
 &sxarfinal_unixcompact_code11_bit5,
 &sxarfinal_unixcompact_code11_bit6,
 &sxarfinal_unixcompact_code11_bit7,
 &sxarfinal_unixcompact_code12_bit0,
 &sxarfinal_unixcompact_code12_bit1,
 &sxarfinal_unixcompact_code12_bit2,
 &sxarfinal_unixcompact_code12_bit3,
 &sxarfinal_unixcompact_code12_bit4,
 &sxarfinal_unixcompact_code12_bit5,
 &sxarfinal_unixcompact_code12_bit6,
 &sxarfinal_unixcompact_code12_bit7,
 &sxarfinal_unixcompact_code13_bit0,
 &sxarfinal_unixcompact_code13_bit1,
 &sxarfinal_unixcompact_code13_bit2,
 &sxarfinal_unixcompact_code13_bit3,
 &sxarfinal_unixcompact_code13_bit4,
 &sxarfinal_unixcompact_code13_bit5,
 &sxarfinal_unixcompact_code13_bit6,
 &sxarfinal_unixcompact_code13_bit7,
 &sxarfinal_unixcompact_code14_bit0,
 &sxarfinal_unixcompact_code14_bit1,
 &sxarfinal_unixcompact_code14_bit2,
 &sxarfinal_unixcompact_code14_bit3,
 &sxarfinal_unixcompact_code14_bit4,
 &sxarfinal_unixcompact_code14_bit5,
 &sxarfinal_unixcompact_code14_bit6,
 &sxarfinal_unixcompact_code14_bit7,
 &sxarfinal_unixcompact_code15_bit0,
 &sxarfinal_unixcompact_code15_bit1,
 &sxarfinal_unixcompact_code15_bit2,
 &sxarfinal_unixcompact_code15_bit3,
 &sxarfinal_unixcompact_code15_bit4,
 &sxarfinal_unixcompact_code15_bit5,
 &sxarfinal_unixcompact_code15_bit6,
 &sxarfinal_unixcompact_code15_bit7,
 &sxarfinal_unixcompact_code16_bit0,
 &sxarfinal_unixcompact_code16_bit1,
 &sxarfinal_unixcompact_code16_bit2,
 &sxarfinal_unixcompact_code16_bit3,
 &sxarfinal_unixcompact_code16_bit4,
 &sxarfinal_unixcompact_code16_bit5,
 &sxarfinal_unixcompact_code16_bit6,
 &sxarfinal_unixcompact_code16_bit7,
 &sxarfinal_unixcompact_code17_bit0,
 &sxarfinal_unixcompact_code17_bit1,
 &sxarfinal_unixcompact_code17_bit2,
 &sxarfinal_unixcompact_code17_bit3,
 &sxarfinal_unixcompact_code17_bit4,
 &sxarfinal_unixcompact_code17_bit5,
 &sxarfinal_unixcompact_code17_bit6,
 &sxarfinal_unixcompact_code17_bit7,
 &sxarfinal_unixcompact_code18_bit0,
 &sxarfinal_unixcompact_code18_bit1,
 &sxarfinal_unixcompact_code18_bit2,
 &sxarfinal_unixcompact_code18_bit3,
 &sxarfinal_unixcompact_code18_bit4,
 &sxarfinal_unixcompact_code18_bit5,
 &sxarfinal_unixcompact_code18_bit6,
 &sxarfinal_unixcompact_code18_bit7,
 &sxarfinal_unixcompact_code19_bit0,
 &sxarfinal_unixcompact_code19_bit1,
 &sxarfinal_unixcompact_code19_bit2,
 &sxarfinal_unixcompact_code19_bit3,
 &sxarfinal_unixcompact_code19_bit4,
 &sxarfinal_unixcompact_code19_bit5,
 &sxarfinal_unixcompact_code19_bit6,
 &sxarfinal_unixcompact_code19_bit7,
 &sxarfinal_unixcompact_code20_bit0,
 &sxarfinal_unixcompact_code20_bit1,
 &sxarfinal_unixcompact_code20_bit2,
 &sxarfinal_unixcompact_code20_bit3,
 &sxarfinal_unixcompact_code20_bit4,
 &sxarfinal_unixcompact_code20_bit5,
 &sxarfinal_unixcompact_code20_bit6,
 &sxarfinal_unixcompact_code20_bit7,
 &sxarfinal_unixcompact_code21_bit0,
 &sxarfinal_unixcompact_code21_bit1,
 &sxarfinal_unixcompact_code21_bit2,
 &sxarfinal_unixcompact_code21_bit3,
 &sxarfinal_unixcompact_code21_bit4,
 &sxarfinal_unixcompact_code21_bit5,
 &sxarfinal_unixcompact_code21_bit6,
 &sxarfinal_unixcompact_code21_bit7,
 &sxarfinal_unixcompact_code22_bit0,
 &sxarfinal_unixcompact_code22_bit1,
 &sxarfinal_unixcompact_code22_bit2,
 &sxarfinal_unixcompact_code22_bit3,
 &sxarfinal_unixcompact_code22_bit4,
 &sxarfinal_unixcompact_code22_bit5,
 &sxarfinal_unixcompact_code22_bit6,
 &sxarfinal_unixcompact_code22_bit7,
 &sxarfinal_unixcompact_code23_bit0,
 &sxarfinal_unixcompact_code23_bit1,
 &sxarfinal_unixcompact_code23_bit2,
 &sxarfinal_unixcompact_code23_bit3,
 &sxarfinal_unixcompact_code23_bit4,
 &sxarfinal_unixcompact_code23_bit5,
 &sxarfinal_unixcompact_code23_bit6,
 &sxarfinal_unixcompact_code23_bit7,
 &sxarfinal_unixcompact_code24_bit0,
 &sxarfinal_unixcompact_code24_bit1,
 &sxarfinal_unixcompact_code24_bit2,
 &sxarfinal_unixcompact_code24_bit3,
 &sxarfinal_unixcompact_code24_bit4,
 &sxarfinal_unixcompact_code24_bit5,
 &sxarfinal_unixcompact_code24_bit6,
 &sxarfinal_unixcompact_code24_bit7,
 &sxarfinal_unixcompact_code25_bit0,
 &sxarfinal_unixcompact_code25_bit1,
 &sxarfinal_unixcompact_code25_bit2,
 &sxarfinal_unixcompact_code25_bit3,
 &sxarfinal_unixcompact_code25_bit4,
 &sxarfinal_unixcompact_code25_bit5,
 &sxarfinal_unixcompact_code25_bit6,
 &sxarfinal_unixcompact_code25_bit7,
 &sxarfinal_unixcompact_code26_bit0,
 &sxarfinal_unixcompact_code26_bit1,
 &sxarfinal_unixcompact_code26_bit2,
 &sxarfinal_unixcompact_code26_bit3,
 &sxarfinal_unixcompact_code26_bit4,
 &sxarfinal_unixcompact_code26_bit5,
 &sxarfinal_unixcompact_code26_bit6,
 &sxarfinal_unixcompact_code26_bit7,
 &sxarfinal_unixcompact_code27_bit0,
 &sxarfinal_unixcompact_code27_bit1,
 &sxarfinal_unixcompact_code27_bit2,
 &sxarfinal_unixcompact_code27_bit3,
 &sxarfinal_unixcompact_code27_bit4,
 &sxarfinal_unixcompact_code27_bit5,
 &sxarfinal_unixcompact_code27_bit6,
 &sxarfinal_unixcompact_code27_bit7,
 &sxarfinal_unixcompact_code28_bit0,
 &sxarfinal_unixcompact_code28_bit1,
 &sxarfinal_unixcompact_code28_bit2,
 &sxarfinal_unixcompact_code28_bit3,
 &sxarfinal_unixcompact_code28_bit4,
 &sxarfinal_unixcompact_code28_bit5,
 &sxarfinal_unixcompact_code28_bit6,
 &sxarfinal_unixcompact_code28_bit7,
 &sxarfinal_unixcompact_code29_bit0,
 &sxarfinal_unixcompact_code29_bit1,
 &sxarfinal_unixcompact_code29_bit2,
 &sxarfinal_unixcompact_code29_bit3,
 &sxarfinal_unixcompact_code29_bit4,
 &sxarfinal_unixcompact_code29_bit5,
 &sxarfinal_unixcompact_code29_bit6,
 &sxarfinal_unixcompact_code29_bit7,
 &sxarfinal_unixcompact_code30_bit0,
 &sxarfinal_unixcompact_code30_bit1,
 &sxarfinal_unixcompact_code30_bit2,
 &sxarfinal_unixcompact_code30_bit3,
 &sxarfinal_unixcompact_code30_bit4,
 &sxarfinal_unixcompact_code30_bit5,
 &sxarfinal_unixcompact_code30_bit6,
 &sxarfinal_unixcompact_code30_bit7,
 &sxarfinal_unixcompact_code31_bit0,
 &sxarfinal_unixcompact_code31_bit1,
 &sxarfinal_unixcompact_code31_bit2,
 &sxarfinal_unixcompact_code31_bit3,
 &sxarfinal_unixcompact_code31_bit4,
 &sxarfinal_unixcompact_code31_bit5,
 &sxarfinal_unixcompact_code31_bit6,
 &sxarfinal_unixcompact_code31_bit7,
 &sxarfinal_unixcompact_code32_bit0,
 &sxarfinal_unixcompact_code32_bit1,
 &sxarfinal_unixcompact_code32_bit2,
 &sxarfinal_unixcompact_code32_bit3,
 &sxarfinal_unixcompact_code32_bit4,
 &sxarfinal_unixcompact_code32_bit5,
 &sxarfinal_unixcompact_code32_bit6,
 &sxarfinal_unixcompact_code32_bit7,
 &sxarfinal_unixcompact_code33_bit0,
 &sxarfinal_unixcompact_code33_bit1,
 &sxarfinal_unixcompact_code33_bit2,
 &sxarfinal_unixcompact_code33_bit3,
 &sxarfinal_unixcompact_code33_bit4,
 &sxarfinal_unixcompact_code33_bit5,
 &sxarfinal_unixcompact_code33_bit6,
 &sxarfinal_unixcompact_code33_bit7,
 &sxarfinal_unixcompact_code34_bit0,
 &sxarfinal_unixcompact_code34_bit1,
 &sxarfinal_unixcompact_code34_bit2,
 &sxarfinal_unixcompact_code34_bit3,
 &sxarfinal_unixcompact_code34_bit4,
 &sxarfinal_unixcompact_code34_bit5,
 &sxarfinal_unixcompact_code34_bit6,
 &sxarfinal_unixcompact_code34_bit7,
 &sxarfinal_unixcompact_code35_bit0,
 &sxarfinal_unixcompact_code35_bit1,
 &sxarfinal_unixcompact_code35_bit2,
 &sxarfinal_unixcompact_code35_bit3,
 &sxarfinal_unixcompact_code35_bit4,
 &sxarfinal_unixcompact_code35_bit5,
 &sxarfinal_unixcompact_code35_bit6,
 &sxarfinal_unixcompact_code35_bit7,
 &sxarfinal_unixcompact_code36_bit0,
 &sxarfinal_unixcompact_code36_bit1,
 &sxarfinal_unixcompact_code36_bit2,
 &sxarfinal_unixcompact_code36_bit3,
 &sxarfinal_unixcompact_code36_bit4,
 &sxarfinal_unixcompact_code36_bit5,
 &sxarfinal_unixcompact_code36_bit6,
 &sxarfinal_unixcompact_code36_bit7,
 &sxarfinal_unixcompact_code37_bit0,
 &sxarfinal_unixcompact_code37_bit1,
 &sxarfinal_unixcompact_code37_bit2,
 &sxarfinal_unixcompact_code37_bit3,
 &sxarfinal_unixcompact_code37_bit4,
 &sxarfinal_unixcompact_code37_bit5,
 &sxarfinal_unixcompact_code37_bit6,
 &sxarfinal_unixcompact_code37_bit7,
 &sxarfinal_unixcompact_code38_bit0,
 &sxarfinal_unixcompact_code38_bit1,
 &sxarfinal_unixcompact_code38_bit2,
 &sxarfinal_unixcompact_code38_bit3,
 &sxarfinal_unixcompact_code38_bit4,
 &sxarfinal_unixcompact_code38_bit5,
 &sxarfinal_unixcompact_code38_bit6,
 &sxarfinal_unixcompact_code38_bit7,
 &sxarfinal_unixcompact_code39_bit0,
 &sxarfinal_unixcompact_code39_bit1,
 &sxarfinal_unixcompact_code39_bit2,
 &sxarfinal_unixcompact_code39_bit3,
 &sxarfinal_unixcompact_code39_bit4,
 &sxarfinal_unixcompact_code39_bit5,
 &sxarfinal_unixcompact_code39_bit6,
 &sxarfinal_unixcompact_code39_bit7,
 &sxarfinal_unixcompact_code40_bit0,
 &sxarfinal_unixcompact_code40_bit1,
 &sxarfinal_unixcompact_code40_bit2,
 &sxarfinal_unixcompact_code40_bit3,
 &sxarfinal_unixcompact_code40_bit4,
 &sxarfinal_unixcompact_code40_bit5,
 &sxarfinal_unixcompact_code40_bit6,
 &sxarfinal_unixcompact_code40_bit7,
 &sxarfinal_unixcompact_code41_bit0,
 &sxarfinal_unixcompact_code41_bit1,
 &sxarfinal_unixcompact_code41_bit2,
 &sxarfinal_unixcompact_code41_bit3,
 &sxarfinal_unixcompact_code41_bit4,
 &sxarfinal_unixcompact_code41_bit5,
 &sxarfinal_unixcompact_code41_bit6,
 &sxarfinal_unixcompact_code41_bit7,
 &sxarfinal_unixcompact_code42_bit0,
 &sxarfinal_unixcompact_code42_bit1,
 &sxarfinal_unixcompact_code42_bit2,
 &sxarfinal_unixcompact_code42_bit3,
 &sxarfinal_unixcompact_code42_bit4,
 &sxarfinal_unixcompact_code42_bit5,
 &sxarfinal_unixcompact_code42_bit6,
 &sxarfinal_unixcompact_code42_bit7,
 &sxarfinal_unixcompact_code43_bit0,
 &sxarfinal_unixcompact_code43_bit1,
 &sxarfinal_unixcompact_code43_bit2,
 &sxarfinal_unixcompact_code43_bit3,
 &sxarfinal_unixcompact_code43_bit4,
 &sxarfinal_unixcompact_code43_bit5,
 &sxarfinal_unixcompact_code43_bit6,
 &sxarfinal_unixcompact_code43_bit7,
 &sxarfinal_unixcompact_code44_bit0,
 &sxarfinal_unixcompact_code44_bit1,
 &sxarfinal_unixcompact_code44_bit2,
 &sxarfinal_unixcompact_code44_bit3,
 &sxarfinal_unixcompact_code44_bit4,
 &sxarfinal_unixcompact_code44_bit5,
 &sxarfinal_unixcompact_code44_bit6,
 &sxarfinal_unixcompact_code44_bit7,
 &sxarfinal_unixcompact_code45_bit0,
 &sxarfinal_unixcompact_code45_bit1,
 &sxarfinal_unixcompact_code45_bit2,
 &sxarfinal_unixcompact_code45_bit3,
 &sxarfinal_unixcompact_code45_bit4,
 &sxarfinal_unixcompact_code45_bit5,
 &sxarfinal_unixcompact_code45_bit6,
 &sxarfinal_unixcompact_code45_bit7,
 &sxarfinal_unixcompact_code46_bit0,
 &sxarfinal_unixcompact_code46_bit1,
 &sxarfinal_unixcompact_code46_bit2,
 &sxarfinal_unixcompact_code46_bit3,
 &sxarfinal_unixcompact_code46_bit4,
 &sxarfinal_unixcompact_code46_bit5,
 &sxarfinal_unixcompact_code46_bit6,
 &sxarfinal_unixcompact_code46_bit7,
 &sxarfinal_unixcompact_code47_bit0,
 &sxarfinal_unixcompact_code47_bit1,
 &sxarfinal_unixcompact_code47_bit2,
 &sxarfinal_unixcompact_code47_bit3,
 &sxarfinal_unixcompact_code47_bit4,
 &sxarfinal_unixcompact_code47_bit5,
 &sxarfinal_unixcompact_code47_bit6,
 &sxarfinal_unixcompact_code47_bit7,
 &sxarfinal_unixcompact_code48_bit0,
 &sxarfinal_unixcompact_code48_bit1,
 &sxarfinal_unixcompact_code48_bit2,
 &sxarfinal_unixcompact_code48_bit3,
 &sxarfinal_unixcompact_code48_bit4,
 &sxarfinal_unixcompact_code48_bit5,
 &sxarfinal_unixcompact_code48_bit6,
 &sxarfinal_unixcompact_code48_bit7,
 &sxarfinal_unixcompact_code49_bit0,
 &sxarfinal_unixcompact_code49_bit1,
 &sxarfinal_unixcompact_code49_bit2,
 &sxarfinal_unixcompact_code49_bit3,
 &sxarfinal_unixcompact_code49_bit4,
 &sxarfinal_unixcompact_code49_bit5,
 &sxarfinal_unixcompact_code49_bit6,
 &sxarfinal_unixcompact_code49_bit7,
 &sxarfinal_unixcompact_code50_bit0,
 &sxarfinal_unixcompact_code50_bit1,
 &sxarfinal_unixcompact_code50_bit2,
 &sxarfinal_unixcompact_code50_bit3,
 &sxarfinal_unixcompact_code50_bit4,
 &sxarfinal_unixcompact_code50_bit5,
 &sxarfinal_unixcompact_code50_bit6,
 &sxarfinal_unixcompact_code50_bit7,
 &sxarfinal_unixcompact_code51_bit0,
 &sxarfinal_unixcompact_code51_bit1,
 &sxarfinal_unixcompact_code51_bit2,
 &sxarfinal_unixcompact_code51_bit3,
 &sxarfinal_unixcompact_code51_bit4,
 &sxarfinal_unixcompact_code51_bit5,
 &sxarfinal_unixcompact_code51_bit6,
 &sxarfinal_unixcompact_code51_bit7,
 &sxarfinal_unixcompact_code52_bit0,
 &sxarfinal_unixcompact_code52_bit1,
 &sxarfinal_unixcompact_code52_bit2,
 &sxarfinal_unixcompact_code52_bit3,
 &sxarfinal_unixcompact_code52_bit4,
 &sxarfinal_unixcompact_code52_bit5,
 &sxarfinal_unixcompact_code52_bit6,
 &sxarfinal_unixcompact_code52_bit7,
 &sxarfinal_unixcompact_code53_bit0,
 &sxarfinal_unixcompact_code53_bit1,
 &sxarfinal_unixcompact_code53_bit2,
 &sxarfinal_unixcompact_code53_bit3,
 &sxarfinal_unixcompact_code53_bit4,
 &sxarfinal_unixcompact_code53_bit5,
 &sxarfinal_unixcompact_code53_bit6,
 &sxarfinal_unixcompact_code53_bit7,
 &sxarfinal_unixcompact_code54_bit0,
 &sxarfinal_unixcompact_code54_bit1,
 &sxarfinal_unixcompact_code54_bit2,
 &sxarfinal_unixcompact_code54_bit3,
 &sxarfinal_unixcompact_code54_bit4,
 &sxarfinal_unixcompact_code54_bit5,
 &sxarfinal_unixcompact_code54_bit6,
 &sxarfinal_unixcompact_code54_bit7,
 &sxarfinal_unixcompact_code55_bit0,
 &sxarfinal_unixcompact_code55_bit1,
 &sxarfinal_unixcompact_code55_bit2,
 &sxarfinal_unixcompact_code55_bit3,
 &sxarfinal_unixcompact_code55_bit4,
 &sxarfinal_unixcompact_code55_bit5,
 &sxarfinal_unixcompact_code55_bit6,
 &sxarfinal_unixcompact_code55_bit7,
 &sxarfinal_unixcompact_code56_bit0,
 &sxarfinal_unixcompact_code56_bit1,
 &sxarfinal_unixcompact_code56_bit2,
 &sxarfinal_unixcompact_code56_bit3,
 &sxarfinal_unixcompact_code56_bit4,
 &sxarfinal_unixcompact_code56_bit5,
 &sxarfinal_unixcompact_code56_bit6,
 &sxarfinal_unixcompact_code56_bit7,
 &sxarfinal_unixcompact_code57_bit0,
 &sxarfinal_unixcompact_code57_bit1,
 &sxarfinal_unixcompact_code57_bit2,
 &sxarfinal_unixcompact_code57_bit3,
 &sxarfinal_unixcompact_code57_bit4,
 &sxarfinal_unixcompact_code57_bit5,
 &sxarfinal_unixcompact_code57_bit6,
 &sxarfinal_unixcompact_code57_bit7,
 &sxarfinal_unixcompact_code58_bit0,
 &sxarfinal_unixcompact_code58_bit1,
 &sxarfinal_unixcompact_code58_bit2,
 &sxarfinal_unixcompact_code58_bit3,
 &sxarfinal_unixcompact_code58_bit4,
 &sxarfinal_unixcompact_code58_bit5,
 &sxarfinal_unixcompact_code58_bit6,
 &sxarfinal_unixcompact_code58_bit7,
 &sxarfinal_unixcompact_code59_bit0,
 &sxarfinal_unixcompact_code59_bit1,
 &sxarfinal_unixcompact_code59_bit2,
 &sxarfinal_unixcompact_code59_bit3,
 &sxarfinal_unixcompact_code59_bit4,
 &sxarfinal_unixcompact_code59_bit5,
 &sxarfinal_unixcompact_code59_bit6,
 &sxarfinal_unixcompact_code59_bit7,
 &sxarfinal_unixcompact_code60_bit0,
 &sxarfinal_unixcompact_code60_bit1,
 &sxarfinal_unixcompact_code60_bit2,
 &sxarfinal_unixcompact_code60_bit3,
 &sxarfinal_unixcompact_code60_bit4,
 &sxarfinal_unixcompact_code60_bit5,
 &sxarfinal_unixcompact_code60_bit6,
 &sxarfinal_unixcompact_code60_bit7,
 &sxarfinal_unixcompact_code61_bit0,
 &sxarfinal_unixcompact_code61_bit1,
 &sxarfinal_unixcompact_code61_bit2,
 &sxarfinal_unixcompact_code61_bit3,
 &sxarfinal_unixcompact_code61_bit4,
 &sxarfinal_unixcompact_code61_bit5,
 &sxarfinal_unixcompact_code61_bit6,
 &sxarfinal_unixcompact_code61_bit7,
 &sxarfinal_unixcompact_code62_bit0,
 &sxarfinal_unixcompact_code62_bit1,
 &sxarfinal_unixcompact_code62_bit2,
 &sxarfinal_unixcompact_code62_bit3,
 &sxarfinal_unixcompact_code62_bit4,
 &sxarfinal_unixcompact_code62_bit5,
 &sxarfinal_unixcompact_code62_bit6,
 &sxarfinal_unixcompact_code62_bit7,
 &sxarfinal_unixcompact_code63_bit0,
 &sxarfinal_unixcompact_code63_bit1,
 &sxarfinal_unixcompact_code63_bit2,
 &sxarfinal_unixcompact_code63_bit3,
 &sxarfinal_unixcompact_code63_bit4,
 &sxarfinal_unixcompact_code63_bit5,
 &sxarfinal_unixcompact_code63_bit6,
 &sxarfinal_unixcompact_code63_bit7,
 &sxarfinal_unixcompact_code64_bit0,
 &sxarfinal_unixcompact_code64_bit1,
 &sxarfinal_unixcompact_code64_bit2,
 &sxarfinal_unixcompact_code64_bit3,
 &sxarfinal_unixcompact_code64_bit4,
 &sxarfinal_unixcompact_code64_bit5,
 &sxarfinal_unixcompact_code64_bit6,
 &sxarfinal_unixcompact_code64_bit7,
 &sxarfinal_unixcompact_new_literal_bit0,
 &sxarfinal_unixcompact_new_literal_bit1,
 &sxarfinal_unixcompact_new_literal_bit2,
 &sxarfinal_unixcompact_new_literal_bit3,
 &sxarfinal_unixcompact_new_literal_bit4,
 &sxarfinal_unixcompact_new_literal_bit5,
 &sxarfinal_unixcompact_new_literal_bit6,
 &sxarfinal_unixcompact_new_literal_bit7,
 &sxarfinal_tarx1_transport_prefix,
 &sxarfinal_tarx1_encrypted_tar_core,
 &sxarfinal_paq8l_stored_header,
 &sxarfinal_paq8_member_size,
 &sxarfinal_paq8_member_name,
 &sxarfinal_paq8_tab,
 &sxarfinal_paq8_line_ending,
 &sxarfinal_paq8_directory_end,
 &sxarfinal_paq8l_stored_frame,
 &sxarfinal_grzip_stream_header,
 &sxarfinal_grzip_block_header,
};
static bool sx_archiveresidual_comment(xx_data_struct_record*r,uint32_t id){
 if(!r||!r->name||id<0x60920000U||id>=0x60930000U)return true;const wchar_t*text=NULL;switch(id){
 case 0x60920001U:text=L"Signature is clear. Bytes4..59 are seven encrypted DES header blocks and cannot be split into plaintext numeric fields. Nonzero final8 bytes wrap a user file key under a fixed DES key; zero selects built-in key candidates. Stored ciphertext is retained; no password or integrity claim.";break;
 case 0x60920002U:text=L"The first decoded byte is physically stored at offset2 and initializes the adaptive Huffman tree. No stored output length or checksum exists.";break;
 case 0x60920003U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920004U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920005U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920006U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920007U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920008U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920009U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092000aU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092000bU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092000cU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092000dU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092000eU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092000fU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920010U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920011U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920012U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920013U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920014U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920015U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920016U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920017U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920018U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920019U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092001aU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092001bU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092001cU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092001dU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092001eU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092001fU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920020U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920021U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920022U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920023U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920024U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920025U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920026U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920027U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920028U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920029U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092002aU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092002bU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092002cU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092002dU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092002eU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092002fU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920030U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920031U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920032U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920033U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920034U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920035U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920036U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920037U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920038U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920039U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092003aU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092003bU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092003cU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092003dU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092003eU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092003fU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920040U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920041U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920042U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920043U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920044U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920045U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920046U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920047U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920048U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920049U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092004aU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092004bU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092004cU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092004dU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092004eU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092004fU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920050U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920051U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920052U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920053U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920054U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920055U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920056U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920057U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920058U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920059U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092005aU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092005bU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092005cU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092005dU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092005eU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092005fU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920060U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920061U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920062U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920063U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920064U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920065U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920066U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920067U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920068U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920069U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092006aU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092006bU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092006cU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092006dU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092006eU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092006fU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920070U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920071U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920072U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920073U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920074U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920075U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920076U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920077U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920078U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920079U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092007aU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092007bU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092007cU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092007dU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092007eU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092007fU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920080U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920081U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920082U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920083U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920084U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920085U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920086U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920087U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920088U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920089U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092008aU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092008bU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092008cU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092008dU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092008eU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092008fU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920090U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920091U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920092U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920093U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920094U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920095U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920096U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920097U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920098U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920099U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092009aU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092009bU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092009cU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092009dU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092009eU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092009fU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200a0U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200a1U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200a2U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200a3U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200a4U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200a5U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200a6U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200a7U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200a8U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200a9U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200aaU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200abU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200acU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200adU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200aeU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200afU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200b0U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200b1U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200b2U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200b3U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200b4U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200b5U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200b6U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200b7U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200b8U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200b9U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200baU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200bbU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200bcU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200bdU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200beU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200bfU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200c0U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200c1U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200c2U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200c3U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200c4U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200c5U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200c6U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200c7U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200c8U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200c9U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200caU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200cbU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200ccU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200cdU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200ceU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200cfU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200d0U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200d1U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200d2U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200d3U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200d4U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200d5U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200d6U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200d7U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200d8U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200d9U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200daU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200dbU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200dcU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200ddU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200deU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200dfU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200e0U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200e1U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200e2U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200e3U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200e4U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200e5U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200e6U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200e7U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200e8U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200e9U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200eaU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200ebU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200ecU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200edU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200eeU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200efU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200f0U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200f1U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200f2U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200f3U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200f4U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200f5U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200f6U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200f7U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200f8U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200f9U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200faU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200fbU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200fcU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200fdU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200feU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200ffU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920100U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920101U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920102U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920103U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920104U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920105U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920106U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920107U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920108U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920109U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092010aU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092010bU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092010cU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092010dU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092010eU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092010fU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920110U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920111U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920112U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920113U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920114U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920115U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920116U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920117U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920118U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920119U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092011aU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092011bU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092011cU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092011dU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092011eU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092011fU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920120U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920121U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920122U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920123U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920124U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920125U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920126U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920127U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920128U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920129U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092012aU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092012bU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092012cU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092012dU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092012eU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092012fU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920130U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920131U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920132U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920133U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920134U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920135U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920136U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920137U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920138U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920139U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092013aU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092013bU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092013cU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092013dU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092013eU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092013fU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920140U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920141U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920142U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920143U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920144U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920145U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920146U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920147U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920148U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920149U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092014aU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092014bU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092014cU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092014dU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092014eU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092014fU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920150U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920151U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920152U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920153U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920154U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920155U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920156U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920157U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920158U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920159U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092015aU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092015bU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092015cU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092015dU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092015eU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092015fU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920160U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920161U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920162U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920163U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920164U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920165U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920166U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920167U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920168U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920169U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092016aU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092016bU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092016cU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092016dU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092016eU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092016fU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920170U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920171U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920172U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920173U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920174U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920175U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920176U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920177U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920178U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920179U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092017aU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092017bU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092017cU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092017dU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092017eU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092017fU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920180U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920181U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920182U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920183U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920184U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920185U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920186U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920187U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920188U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920189U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092018aU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092018bU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092018cU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092018dU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092018eU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092018fU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920190U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920191U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920192U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920193U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920194U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920195U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920196U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920197U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920198U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920199U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092019aU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092019bU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092019cU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092019dU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092019eU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092019fU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201a0U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201a1U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201a2U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201a3U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201a4U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201a5U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201a6U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201a7U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201a8U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201a9U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201aaU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201abU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201acU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201adU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201aeU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201afU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201b0U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201b1U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201b2U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201b3U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201b4U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201b5U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201b6U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201b7U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201b8U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201b9U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201baU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201bbU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201bcU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201bdU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201beU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201bfU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201c0U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201c1U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201c2U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201c3U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201c4U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201c5U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201c6U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201c7U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201c8U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201c9U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201caU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201cbU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201ccU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201cdU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201ceU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201cfU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201d0U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201d1U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201d2U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201d3U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201d4U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201d5U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201d6U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201d7U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201d8U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201d9U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201daU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201dbU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201dcU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201ddU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201deU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201dfU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201e0U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201e1U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201e2U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201e3U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201e4U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201e5U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201e6U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201e7U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201e8U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201e9U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201eaU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201ebU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201ecU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201edU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201eeU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201efU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201f0U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201f1U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201f2U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201f3U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201f4U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201f5U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201f6U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201f7U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201f8U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201f9U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201faU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201fbU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201fcU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201fdU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201feU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201ffU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920200U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920201U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920202U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920203U:text=L"Eight physical MSB-first literal bits after an adaptive ESC code. This introduces a byte not previously seen.";break;
 case 0x60920204U:text=L"Eight physical MSB-first literal bits after an adaptive ESC code. This introduces a byte not previously seen.";break;
 case 0x60920205U:text=L"Eight physical MSB-first literal bits after an adaptive ESC code. This introduces a byte not previously seen.";break;
 case 0x60920206U:text=L"Eight physical MSB-first literal bits after an adaptive ESC code. This introduces a byte not previously seen.";break;
 case 0x60920207U:text=L"Eight physical MSB-first literal bits after an adaptive ESC code. This introduces a byte not previously seen.";break;
 case 0x60920208U:text=L"Eight physical MSB-first literal bits after an adaptive ESC code. This introduces a byte not previously seen.";break;
 case 0x60920209U:text=L"Eight physical MSB-first literal bits after an adaptive ESC code. This introduces a byte not previously seen.";break;
 case 0x6092020aU:text=L"Eight physical MSB-first literal bits after an adaptive ESC code. This introduces a byte not previously seen.";break;
 case 0x6092020bU:text=L"Clear TARX1 transport signature. Encrypted TAR byte0 is stored at physical byte4; the cipher preserves all subsequent byte positions.";break;
 case 0x6092020cU:text=L"Stored ciphertext bytes at a native-authenticated decoded TAR member header. TARX1 preserves byte boundaries but values here remain encoded, including size, timestamp and checksum. The common257-byte TAR prefix is covered; variant-specific extensions and remaining header bytes stay raw. Decoded archive offsets gain the four-byte clear transport prefix.";break;
 case 0x6092020dU:text=L"PAQ8L level0 physical header. The optional standalone helper currently accepts only level0 DEFAULT stored frames; other PAQ8 revisions/levels/modes remain unsupported by that helper.";break;
 case 0x6092020eU:text=L"Decimal decoded member byte length in the clear PAQ8 directory. The corresponding payload is part of the solid body, not located at this text position.";break;
 case 0x6092020fU:text=L"Physical clear directory name, excluding the preceding TAB and following CRLF. No file is extracted by this schema.";break;
 case 0x60920212U:text=L"Physical byte0x1A ends the clear member directory; it is not part of any decoded member.";break;
 case 0x60920213U:text=L"Level0 DEFAULT type0 frame; four-byte big-endian length counts following untransformed bytes. Entropy-coded and EXE/JPEG preprocessing variants are not interpreted here.";break;
 case 0x60920215U:text=L"GRZipII stored block fields. Mode-1/parameter0 stores bytes verbatim; transform_parameter is written zero in that mode. Other modes use these parameter words for LZP/filter/sorting state. CRC values are stored metadata; this schema does not claim independent integrity verification.";break;
 default:break;}
 return !text||xx_data_struct_record_set_comment(r,text);
}
#define SXARFINAL_LIMIT 20000U
bool sxarfinal_span(sx_context*c,uint64_t p,uint64_t n){return c&&c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p&&!xx_pd_is_stopped(c->pd);}
bool sxarfinal_read(sx_context*c,uint64_t p,void*b,size_t n){return sxarfinal_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
uint64_t sxarfinal_num(const uint8_t*b,unsigned n,bool be){uint64_t v=0;for(unsigned i=0;i<n;i++)v|=(uint64_t)b[i]<<(8*(be?n-1-i:i));return v;}
static uint64_t sxarfinal_width(const sx_layout*l){const xx_data_struct_field_desc*f=l->fields+l->field_count-1;return (uint64_t)(f->rel_offset+f->size);}
bool sxarfinal_put(sx_context*c,const sx_layout*l,uint64_t p){uint64_t n=sxarfinal_width(l);return c->count<SXARFINAL_LIMIT&&n&&sxarfinal_span(c,p,n)&&sx_add(c,l,(int64_t)p,(int64_t)n);}
/* Bit windows intentionally share byte boundaries. Their bit ranges do not
 * overlap; raw gaps use the union of the minimal enclosing byte windows. */
static int sxarfinal_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
bool sxarfinal_finish(sx_context*c){size_t n=c->count;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxarfinal_order);for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(p<0||z<=0||p>c->size||z>c->size-p)return false;if(p>end&&!sx_raw(c,end,p-end))return false;if(p+z>end)end=p+z;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxarfinal_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
/* A runaway guard: nothing in the file bounds the plaintext. */
#define SXARFINAL_COMPACT_MAX_OUTPUT ((size_t)256 * 1024 * 1024)
#define SXARFINAL_COMPACT_INITIAL_OUTPUT ((size_t)64 * 1024)
static bool sx_archiveresidual_supports(xx_file_type_t t){switch(t){case XX_FILE_TYPE_PAQ8:case XX_FILE_TYPE_GRZIP:case XX_FILE_TYPE_TARX1:case XX_FILE_TYPE_PCSECURE:case XX_FILE_TYPE_UNIX_COMPACT:return true;default:return false;}}
static bool sx_archiveresidual_build(sx_context*c){
if(c->f->file_type==XX_FILE_TYPE_PAQ8)return sx_paq8_build(c);
if(c->f->file_type==XX_FILE_TYPE_GRZIP)return sx_grzip_build(c);
if(c->f->file_type==XX_FILE_TYPE_TARX1)return sx_tarx1_build(c);
if(c->f->file_type==XX_FILE_TYPE_PCSECURE)return sx_pcsecure_build(c);
if(c->f->file_type==XX_FILE_TYPE_UNIX_COMPACT)return sx_unixcompact_build(c);
return false;}
const sx_family sx_archiveresidual_family={sx_archiveresidual_supports,sx_archiveresidual_build,sx_archiveresidual_layouts,SX_COUNT(sx_archiveresidual_layouts),sx_archiveresidual_comment};
