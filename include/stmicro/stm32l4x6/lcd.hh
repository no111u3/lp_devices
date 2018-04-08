/* Copyright 2018 Boris Vinogradov <no111u3@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Hardware support for lcd
 * @file lcd.hh
 * @author Boris Vinogradov
 */

#include <associate_bit.hh>
#include <io_register.hh>
#include <types.hh>

#ifndef LCD_HH
#define LCD_HH

/* Liquid crystal display controller */
template <lp::addr_t base_address>
struct lcd_t {
    /* control register */
    using cr = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* Bias selector */
    using cr_bias = lp::assoc_bit<cr, 5, 2>;
    /* Duty selection */
    using cr_duty = lp::assoc_bit<cr, 2, 3>;
    /* Voltage source selection */
    using cr_vsel = lp::assoc_bit<cr, 1>;
    /* LCD controller enable */
    using cr_lcden = lp::assoc_bit<cr, 0>;
    /* Mux segment enable */
    using cr_mux_seg = lp::assoc_bit<cr, 7>;
    /* Voltage output buffer               enable */
    using cr_bufen = lp::assoc_bit<cr, 8>;


    /* frame control register */
    using fcr = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* PS 16-bit prescaler */
    using fcr_ps = lp::assoc_bit<fcr, 22, 4>;
    /* DIV clock divider */
    using fcr_div = lp::assoc_bit<fcr, 18, 4>;
    /* Blink mode selection */
    using fcr_blink = lp::assoc_bit<fcr, 16, 2>;
    /* Blink frequency selection */
    using fcr_blinkf = lp::assoc_bit<fcr, 13, 3>;
    /* Contrast control */
    using fcr_cc = lp::assoc_bit<fcr, 10, 3>;
    /* Dead time duration */
    using fcr_dead = lp::assoc_bit<fcr, 7, 3>;
    /* Pulse ON duration */
    using fcr_pon = lp::assoc_bit<fcr, 4, 3>;
    /* Update display done interrupt               enable */
    using fcr_uddie = lp::assoc_bit<fcr, 3>;
    /* Start of frame interrupt               enable */
    using fcr_sofie = lp::assoc_bit<fcr, 1>;
    /* High drive enable */
    using fcr_hd = lp::assoc_bit<fcr, 0>;


    /* status register */
    using sr = lp::io_register<lp::u32_t, base_address + 0x8>;
    /* LCD Frame Control Register               Synchronization flag */
    using sr_fcrsf = lp::assoc_bit<sr, 5>;
    /* Ready flag */
    using sr_rdy = lp::assoc_bit<sr, 4>;
    /* Update Display Done */
    using sr_udd = lp::assoc_bit<sr, 3>;
    /* Update display request */
    using sr_udr = lp::assoc_bit<sr, 2>;
    /* Start of frame flag */
    using sr_sof = lp::assoc_bit<sr, 1>;
    /* ENS */
    using sr_ens = lp::assoc_bit<sr, 0>;


    /* clear register */
    using clr = lp::io_register<lp::u32_t, base_address + 0xc>;
    /* Update display done clear */
    using clr_uddc = lp::assoc_bit<clr, 3>;
    /* Start of frame flag clear */
    using clr_sofc = lp::assoc_bit<clr, 1>;


    /* display memory */
    using ram_com0 = lp::io_register<lp::u32_t, base_address + 0x14>;
    /* S30 */
    using ram_com0_s30 = lp::assoc_bit<ram_com0, 30>;
    /* S29 */
    using ram_com0_s29 = lp::assoc_bit<ram_com0, 29>;
    /* S28 */
    using ram_com0_s28 = lp::assoc_bit<ram_com0, 28>;
    /* S27 */
    using ram_com0_s27 = lp::assoc_bit<ram_com0, 27>;
    /* S26 */
    using ram_com0_s26 = lp::assoc_bit<ram_com0, 26>;
    /* S25 */
    using ram_com0_s25 = lp::assoc_bit<ram_com0, 25>;
    /* S24 */
    using ram_com0_s24 = lp::assoc_bit<ram_com0, 24>;
    /* S23 */
    using ram_com0_s23 = lp::assoc_bit<ram_com0, 23>;
    /* S22 */
    using ram_com0_s22 = lp::assoc_bit<ram_com0, 22>;
    /* S21 */
    using ram_com0_s21 = lp::assoc_bit<ram_com0, 21>;
    /* S20 */
    using ram_com0_s20 = lp::assoc_bit<ram_com0, 20>;
    /* S19 */
    using ram_com0_s19 = lp::assoc_bit<ram_com0, 19>;
    /* S18 */
    using ram_com0_s18 = lp::assoc_bit<ram_com0, 18>;
    /* S17 */
    using ram_com0_s17 = lp::assoc_bit<ram_com0, 17>;
    /* S16 */
    using ram_com0_s16 = lp::assoc_bit<ram_com0, 16>;
    /* S15 */
    using ram_com0_s15 = lp::assoc_bit<ram_com0, 15>;
    /* S14 */
    using ram_com0_s14 = lp::assoc_bit<ram_com0, 14>;
    /* S13 */
    using ram_com0_s13 = lp::assoc_bit<ram_com0, 13>;
    /* S12 */
    using ram_com0_s12 = lp::assoc_bit<ram_com0, 12>;
    /* S11 */
    using ram_com0_s11 = lp::assoc_bit<ram_com0, 11>;
    /* S10 */
    using ram_com0_s10 = lp::assoc_bit<ram_com0, 10>;
    /* S09 */
    using ram_com0_s09 = lp::assoc_bit<ram_com0, 9>;
    /* S08 */
    using ram_com0_s08 = lp::assoc_bit<ram_com0, 8>;
    /* S07 */
    using ram_com0_s07 = lp::assoc_bit<ram_com0, 7>;
    /* S06 */
    using ram_com0_s06 = lp::assoc_bit<ram_com0, 6>;
    /* S05 */
    using ram_com0_s05 = lp::assoc_bit<ram_com0, 5>;
    /* S04 */
    using ram_com0_s04 = lp::assoc_bit<ram_com0, 4>;
    /* S03 */
    using ram_com0_s03 = lp::assoc_bit<ram_com0, 3>;
    /* S02 */
    using ram_com0_s02 = lp::assoc_bit<ram_com0, 2>;
    /* S01 */
    using ram_com0_s01 = lp::assoc_bit<ram_com0, 1>;
    /* S00 */
    using ram_com0_s00 = lp::assoc_bit<ram_com0, 0>;


    /* display memory */
    using ram_com1 = lp::io_register<lp::u32_t, base_address + 0x1c>;
    /* S31 */
    using ram_com1_s31 = lp::assoc_bit<ram_com1, 31>;
    /* S30 */
    using ram_com1_s30 = lp::assoc_bit<ram_com1, 30>;
    /* S29 */
    using ram_com1_s29 = lp::assoc_bit<ram_com1, 29>;
    /* S28 */
    using ram_com1_s28 = lp::assoc_bit<ram_com1, 28>;
    /* S27 */
    using ram_com1_s27 = lp::assoc_bit<ram_com1, 27>;
    /* S26 */
    using ram_com1_s26 = lp::assoc_bit<ram_com1, 26>;
    /* S25 */
    using ram_com1_s25 = lp::assoc_bit<ram_com1, 25>;
    /* S24 */
    using ram_com1_s24 = lp::assoc_bit<ram_com1, 24>;
    /* S23 */
    using ram_com1_s23 = lp::assoc_bit<ram_com1, 23>;
    /* S22 */
    using ram_com1_s22 = lp::assoc_bit<ram_com1, 22>;
    /* S21 */
    using ram_com1_s21 = lp::assoc_bit<ram_com1, 21>;
    /* S20 */
    using ram_com1_s20 = lp::assoc_bit<ram_com1, 20>;
    /* S19 */
    using ram_com1_s19 = lp::assoc_bit<ram_com1, 19>;
    /* S18 */
    using ram_com1_s18 = lp::assoc_bit<ram_com1, 18>;
    /* S17 */
    using ram_com1_s17 = lp::assoc_bit<ram_com1, 17>;
    /* S16 */
    using ram_com1_s16 = lp::assoc_bit<ram_com1, 16>;
    /* S15 */
    using ram_com1_s15 = lp::assoc_bit<ram_com1, 15>;
    /* S14 */
    using ram_com1_s14 = lp::assoc_bit<ram_com1, 14>;
    /* S13 */
    using ram_com1_s13 = lp::assoc_bit<ram_com1, 13>;
    /* S12 */
    using ram_com1_s12 = lp::assoc_bit<ram_com1, 12>;
    /* S11 */
    using ram_com1_s11 = lp::assoc_bit<ram_com1, 11>;
    /* S10 */
    using ram_com1_s10 = lp::assoc_bit<ram_com1, 10>;
    /* S09 */
    using ram_com1_s09 = lp::assoc_bit<ram_com1, 9>;
    /* S08 */
    using ram_com1_s08 = lp::assoc_bit<ram_com1, 8>;
    /* S07 */
    using ram_com1_s07 = lp::assoc_bit<ram_com1, 7>;
    /* S06 */
    using ram_com1_s06 = lp::assoc_bit<ram_com1, 6>;
    /* S05 */
    using ram_com1_s05 = lp::assoc_bit<ram_com1, 5>;
    /* S04 */
    using ram_com1_s04 = lp::assoc_bit<ram_com1, 4>;
    /* S03 */
    using ram_com1_s03 = lp::assoc_bit<ram_com1, 3>;
    /* S02 */
    using ram_com1_s02 = lp::assoc_bit<ram_com1, 2>;
    /* S01 */
    using ram_com1_s01 = lp::assoc_bit<ram_com1, 1>;
    /* S00 */
    using ram_com1_s00 = lp::assoc_bit<ram_com1, 0>;


    /* display memory */
    using ram_com2 = lp::io_register<lp::u32_t, base_address + 0x24>;
    /* S31 */
    using ram_com2_s31 = lp::assoc_bit<ram_com2, 31>;
    /* S30 */
    using ram_com2_s30 = lp::assoc_bit<ram_com2, 30>;
    /* S29 */
    using ram_com2_s29 = lp::assoc_bit<ram_com2, 29>;
    /* S28 */
    using ram_com2_s28 = lp::assoc_bit<ram_com2, 28>;
    /* S27 */
    using ram_com2_s27 = lp::assoc_bit<ram_com2, 27>;
    /* S26 */
    using ram_com2_s26 = lp::assoc_bit<ram_com2, 26>;
    /* S25 */
    using ram_com2_s25 = lp::assoc_bit<ram_com2, 25>;
    /* S24 */
    using ram_com2_s24 = lp::assoc_bit<ram_com2, 24>;
    /* S23 */
    using ram_com2_s23 = lp::assoc_bit<ram_com2, 23>;
    /* S22 */
    using ram_com2_s22 = lp::assoc_bit<ram_com2, 22>;
    /* S21 */
    using ram_com2_s21 = lp::assoc_bit<ram_com2, 21>;
    /* S20 */
    using ram_com2_s20 = lp::assoc_bit<ram_com2, 20>;
    /* S19 */
    using ram_com2_s19 = lp::assoc_bit<ram_com2, 19>;
    /* S18 */
    using ram_com2_s18 = lp::assoc_bit<ram_com2, 18>;
    /* S17 */
    using ram_com2_s17 = lp::assoc_bit<ram_com2, 17>;
    /* S16 */
    using ram_com2_s16 = lp::assoc_bit<ram_com2, 16>;
    /* S15 */
    using ram_com2_s15 = lp::assoc_bit<ram_com2, 15>;
    /* S14 */
    using ram_com2_s14 = lp::assoc_bit<ram_com2, 14>;
    /* S13 */
    using ram_com2_s13 = lp::assoc_bit<ram_com2, 13>;
    /* S12 */
    using ram_com2_s12 = lp::assoc_bit<ram_com2, 12>;
    /* S11 */
    using ram_com2_s11 = lp::assoc_bit<ram_com2, 11>;
    /* S10 */
    using ram_com2_s10 = lp::assoc_bit<ram_com2, 10>;
    /* S09 */
    using ram_com2_s09 = lp::assoc_bit<ram_com2, 9>;
    /* S08 */
    using ram_com2_s08 = lp::assoc_bit<ram_com2, 8>;
    /* S07 */
    using ram_com2_s07 = lp::assoc_bit<ram_com2, 7>;
    /* S06 */
    using ram_com2_s06 = lp::assoc_bit<ram_com2, 6>;
    /* S05 */
    using ram_com2_s05 = lp::assoc_bit<ram_com2, 5>;
    /* S04 */
    using ram_com2_s04 = lp::assoc_bit<ram_com2, 4>;
    /* S03 */
    using ram_com2_s03 = lp::assoc_bit<ram_com2, 3>;
    /* S02 */
    using ram_com2_s02 = lp::assoc_bit<ram_com2, 2>;
    /* S01 */
    using ram_com2_s01 = lp::assoc_bit<ram_com2, 1>;
    /* S00 */
    using ram_com2_s00 = lp::assoc_bit<ram_com2, 0>;


    /* display memory */
    using ram_com3 = lp::io_register<lp::u32_t, base_address + 0x2c>;
    /* S31 */
    using ram_com3_s31 = lp::assoc_bit<ram_com3, 31>;
    /* S30 */
    using ram_com3_s30 = lp::assoc_bit<ram_com3, 30>;
    /* S29 */
    using ram_com3_s29 = lp::assoc_bit<ram_com3, 29>;
    /* S28 */
    using ram_com3_s28 = lp::assoc_bit<ram_com3, 28>;
    /* S27 */
    using ram_com3_s27 = lp::assoc_bit<ram_com3, 27>;
    /* S26 */
    using ram_com3_s26 = lp::assoc_bit<ram_com3, 26>;
    /* S25 */
    using ram_com3_s25 = lp::assoc_bit<ram_com3, 25>;
    /* S24 */
    using ram_com3_s24 = lp::assoc_bit<ram_com3, 24>;
    /* S23 */
    using ram_com3_s23 = lp::assoc_bit<ram_com3, 23>;
    /* S22 */
    using ram_com3_s22 = lp::assoc_bit<ram_com3, 22>;
    /* S21 */
    using ram_com3_s21 = lp::assoc_bit<ram_com3, 21>;
    /* S20 */
    using ram_com3_s20 = lp::assoc_bit<ram_com3, 20>;
    /* S19 */
    using ram_com3_s19 = lp::assoc_bit<ram_com3, 19>;
    /* S18 */
    using ram_com3_s18 = lp::assoc_bit<ram_com3, 18>;
    /* S17 */
    using ram_com3_s17 = lp::assoc_bit<ram_com3, 17>;
    /* S16 */
    using ram_com3_s16 = lp::assoc_bit<ram_com3, 16>;
    /* S15 */
    using ram_com3_s15 = lp::assoc_bit<ram_com3, 15>;
    /* S14 */
    using ram_com3_s14 = lp::assoc_bit<ram_com3, 14>;
    /* S13 */
    using ram_com3_s13 = lp::assoc_bit<ram_com3, 13>;
    /* S12 */
    using ram_com3_s12 = lp::assoc_bit<ram_com3, 12>;
    /* S11 */
    using ram_com3_s11 = lp::assoc_bit<ram_com3, 11>;
    /* S10 */
    using ram_com3_s10 = lp::assoc_bit<ram_com3, 10>;
    /* S09 */
    using ram_com3_s09 = lp::assoc_bit<ram_com3, 9>;
    /* S08 */
    using ram_com3_s08 = lp::assoc_bit<ram_com3, 8>;
    /* S07 */
    using ram_com3_s07 = lp::assoc_bit<ram_com3, 7>;
    /* S06 */
    using ram_com3_s06 = lp::assoc_bit<ram_com3, 6>;
    /* S05 */
    using ram_com3_s05 = lp::assoc_bit<ram_com3, 5>;
    /* S04 */
    using ram_com3_s04 = lp::assoc_bit<ram_com3, 4>;
    /* S03 */
    using ram_com3_s03 = lp::assoc_bit<ram_com3, 3>;
    /* S02 */
    using ram_com3_s02 = lp::assoc_bit<ram_com3, 2>;
    /* S01 */
    using ram_com3_s01 = lp::assoc_bit<ram_com3, 1>;
    /* S00 */
    using ram_com3_s00 = lp::assoc_bit<ram_com3, 0>;


    /* display memory */
    using ram_com4 = lp::io_register<lp::u32_t, base_address + 0x34>;
    /* S31 */
    using ram_com4_s31 = lp::assoc_bit<ram_com4, 31>;
    /* S30 */
    using ram_com4_s30 = lp::assoc_bit<ram_com4, 30>;
    /* S29 */
    using ram_com4_s29 = lp::assoc_bit<ram_com4, 29>;
    /* S28 */
    using ram_com4_s28 = lp::assoc_bit<ram_com4, 28>;
    /* S27 */
    using ram_com4_s27 = lp::assoc_bit<ram_com4, 27>;
    /* S26 */
    using ram_com4_s26 = lp::assoc_bit<ram_com4, 26>;
    /* S25 */
    using ram_com4_s25 = lp::assoc_bit<ram_com4, 25>;
    /* S24 */
    using ram_com4_s24 = lp::assoc_bit<ram_com4, 24>;
    /* S23 */
    using ram_com4_s23 = lp::assoc_bit<ram_com4, 23>;
    /* S22 */
    using ram_com4_s22 = lp::assoc_bit<ram_com4, 22>;
    /* S21 */
    using ram_com4_s21 = lp::assoc_bit<ram_com4, 21>;
    /* S20 */
    using ram_com4_s20 = lp::assoc_bit<ram_com4, 20>;
    /* S19 */
    using ram_com4_s19 = lp::assoc_bit<ram_com4, 19>;
    /* S18 */
    using ram_com4_s18 = lp::assoc_bit<ram_com4, 18>;
    /* S17 */
    using ram_com4_s17 = lp::assoc_bit<ram_com4, 17>;
    /* S16 */
    using ram_com4_s16 = lp::assoc_bit<ram_com4, 16>;
    /* S15 */
    using ram_com4_s15 = lp::assoc_bit<ram_com4, 15>;
    /* S14 */
    using ram_com4_s14 = lp::assoc_bit<ram_com4, 14>;
    /* S13 */
    using ram_com4_s13 = lp::assoc_bit<ram_com4, 13>;
    /* S12 */
    using ram_com4_s12 = lp::assoc_bit<ram_com4, 12>;
    /* S11 */
    using ram_com4_s11 = lp::assoc_bit<ram_com4, 11>;
    /* S10 */
    using ram_com4_s10 = lp::assoc_bit<ram_com4, 10>;
    /* S09 */
    using ram_com4_s09 = lp::assoc_bit<ram_com4, 9>;
    /* S08 */
    using ram_com4_s08 = lp::assoc_bit<ram_com4, 8>;
    /* S07 */
    using ram_com4_s07 = lp::assoc_bit<ram_com4, 7>;
    /* S06 */
    using ram_com4_s06 = lp::assoc_bit<ram_com4, 6>;
    /* S05 */
    using ram_com4_s05 = lp::assoc_bit<ram_com4, 5>;
    /* S04 */
    using ram_com4_s04 = lp::assoc_bit<ram_com4, 4>;
    /* S03 */
    using ram_com4_s03 = lp::assoc_bit<ram_com4, 3>;
    /* S02 */
    using ram_com4_s02 = lp::assoc_bit<ram_com4, 2>;
    /* S01 */
    using ram_com4_s01 = lp::assoc_bit<ram_com4, 1>;
    /* S00 */
    using ram_com4_s00 = lp::assoc_bit<ram_com4, 0>;


    /* display memory */
    using ram_com5 = lp::io_register<lp::u32_t, base_address + 0x3c>;
    /* S31 */
    using ram_com5_s31 = lp::assoc_bit<ram_com5, 31>;
    /* S30 */
    using ram_com5_s30 = lp::assoc_bit<ram_com5, 30>;
    /* S29 */
    using ram_com5_s29 = lp::assoc_bit<ram_com5, 29>;
    /* S28 */
    using ram_com5_s28 = lp::assoc_bit<ram_com5, 28>;
    /* S27 */
    using ram_com5_s27 = lp::assoc_bit<ram_com5, 27>;
    /* S26 */
    using ram_com5_s26 = lp::assoc_bit<ram_com5, 26>;
    /* S25 */
    using ram_com5_s25 = lp::assoc_bit<ram_com5, 25>;
    /* S24 */
    using ram_com5_s24 = lp::assoc_bit<ram_com5, 24>;
    /* S23 */
    using ram_com5_s23 = lp::assoc_bit<ram_com5, 23>;
    /* S22 */
    using ram_com5_s22 = lp::assoc_bit<ram_com5, 22>;
    /* S21 */
    using ram_com5_s21 = lp::assoc_bit<ram_com5, 21>;
    /* S20 */
    using ram_com5_s20 = lp::assoc_bit<ram_com5, 20>;
    /* S19 */
    using ram_com5_s19 = lp::assoc_bit<ram_com5, 19>;
    /* S18 */
    using ram_com5_s18 = lp::assoc_bit<ram_com5, 18>;
    /* S17 */
    using ram_com5_s17 = lp::assoc_bit<ram_com5, 17>;
    /* S16 */
    using ram_com5_s16 = lp::assoc_bit<ram_com5, 16>;
    /* S15 */
    using ram_com5_s15 = lp::assoc_bit<ram_com5, 15>;
    /* S14 */
    using ram_com5_s14 = lp::assoc_bit<ram_com5, 14>;
    /* S13 */
    using ram_com5_s13 = lp::assoc_bit<ram_com5, 13>;
    /* S12 */
    using ram_com5_s12 = lp::assoc_bit<ram_com5, 12>;
    /* S11 */
    using ram_com5_s11 = lp::assoc_bit<ram_com5, 11>;
    /* S10 */
    using ram_com5_s10 = lp::assoc_bit<ram_com5, 10>;
    /* S09 */
    using ram_com5_s09 = lp::assoc_bit<ram_com5, 9>;
    /* S08 */
    using ram_com5_s08 = lp::assoc_bit<ram_com5, 8>;
    /* S07 */
    using ram_com5_s07 = lp::assoc_bit<ram_com5, 7>;
    /* S06 */
    using ram_com5_s06 = lp::assoc_bit<ram_com5, 6>;
    /* S05 */
    using ram_com5_s05 = lp::assoc_bit<ram_com5, 5>;
    /* S04 */
    using ram_com5_s04 = lp::assoc_bit<ram_com5, 4>;
    /* S03 */
    using ram_com5_s03 = lp::assoc_bit<ram_com5, 3>;
    /* S02 */
    using ram_com5_s02 = lp::assoc_bit<ram_com5, 2>;
    /* S01 */
    using ram_com5_s01 = lp::assoc_bit<ram_com5, 1>;
    /* S00 */
    using ram_com5_s00 = lp::assoc_bit<ram_com5, 0>;


    /* display memory */
    using ram_com6 = lp::io_register<lp::u32_t, base_address + 0x44>;
    /* S31 */
    using ram_com6_s31 = lp::assoc_bit<ram_com6, 31>;
    /* S30 */
    using ram_com6_s30 = lp::assoc_bit<ram_com6, 30>;
    /* S29 */
    using ram_com6_s29 = lp::assoc_bit<ram_com6, 29>;
    /* S28 */
    using ram_com6_s28 = lp::assoc_bit<ram_com6, 28>;
    /* S27 */
    using ram_com6_s27 = lp::assoc_bit<ram_com6, 27>;
    /* S26 */
    using ram_com6_s26 = lp::assoc_bit<ram_com6, 26>;
    /* S25 */
    using ram_com6_s25 = lp::assoc_bit<ram_com6, 25>;
    /* S24 */
    using ram_com6_s24 = lp::assoc_bit<ram_com6, 24>;
    /* S23 */
    using ram_com6_s23 = lp::assoc_bit<ram_com6, 23>;
    /* S22 */
    using ram_com6_s22 = lp::assoc_bit<ram_com6, 22>;
    /* S21 */
    using ram_com6_s21 = lp::assoc_bit<ram_com6, 21>;
    /* S20 */
    using ram_com6_s20 = lp::assoc_bit<ram_com6, 20>;
    /* S19 */
    using ram_com6_s19 = lp::assoc_bit<ram_com6, 19>;
    /* S18 */
    using ram_com6_s18 = lp::assoc_bit<ram_com6, 18>;
    /* S17 */
    using ram_com6_s17 = lp::assoc_bit<ram_com6, 17>;
    /* S16 */
    using ram_com6_s16 = lp::assoc_bit<ram_com6, 16>;
    /* S15 */
    using ram_com6_s15 = lp::assoc_bit<ram_com6, 15>;
    /* S14 */
    using ram_com6_s14 = lp::assoc_bit<ram_com6, 14>;
    /* S13 */
    using ram_com6_s13 = lp::assoc_bit<ram_com6, 13>;
    /* S12 */
    using ram_com6_s12 = lp::assoc_bit<ram_com6, 12>;
    /* S11 */
    using ram_com6_s11 = lp::assoc_bit<ram_com6, 11>;
    /* S10 */
    using ram_com6_s10 = lp::assoc_bit<ram_com6, 10>;
    /* S09 */
    using ram_com6_s09 = lp::assoc_bit<ram_com6, 9>;
    /* S08 */
    using ram_com6_s08 = lp::assoc_bit<ram_com6, 8>;
    /* S07 */
    using ram_com6_s07 = lp::assoc_bit<ram_com6, 7>;
    /* S06 */
    using ram_com6_s06 = lp::assoc_bit<ram_com6, 6>;
    /* S05 */
    using ram_com6_s05 = lp::assoc_bit<ram_com6, 5>;
    /* S04 */
    using ram_com6_s04 = lp::assoc_bit<ram_com6, 4>;
    /* S03 */
    using ram_com6_s03 = lp::assoc_bit<ram_com6, 3>;
    /* S02 */
    using ram_com6_s02 = lp::assoc_bit<ram_com6, 2>;
    /* S01 */
    using ram_com6_s01 = lp::assoc_bit<ram_com6, 1>;
    /* S00 */
    using ram_com6_s00 = lp::assoc_bit<ram_com6, 0>;


    /* display memory */
    using ram_com7 = lp::io_register<lp::u32_t, base_address + 0x4c>;
    /* S31 */
    using ram_com7_s31 = lp::assoc_bit<ram_com7, 31>;
    /* S30 */
    using ram_com7_s30 = lp::assoc_bit<ram_com7, 30>;
    /* S29 */
    using ram_com7_s29 = lp::assoc_bit<ram_com7, 29>;
    /* S28 */
    using ram_com7_s28 = lp::assoc_bit<ram_com7, 28>;
    /* S27 */
    using ram_com7_s27 = lp::assoc_bit<ram_com7, 27>;
    /* S26 */
    using ram_com7_s26 = lp::assoc_bit<ram_com7, 26>;
    /* S25 */
    using ram_com7_s25 = lp::assoc_bit<ram_com7, 25>;
    /* S24 */
    using ram_com7_s24 = lp::assoc_bit<ram_com7, 24>;
    /* S23 */
    using ram_com7_s23 = lp::assoc_bit<ram_com7, 23>;
    /* S22 */
    using ram_com7_s22 = lp::assoc_bit<ram_com7, 22>;
    /* S21 */
    using ram_com7_s21 = lp::assoc_bit<ram_com7, 21>;
    /* S20 */
    using ram_com7_s20 = lp::assoc_bit<ram_com7, 20>;
    /* S19 */
    using ram_com7_s19 = lp::assoc_bit<ram_com7, 19>;
    /* S18 */
    using ram_com7_s18 = lp::assoc_bit<ram_com7, 18>;
    /* S17 */
    using ram_com7_s17 = lp::assoc_bit<ram_com7, 17>;
    /* S16 */
    using ram_com7_s16 = lp::assoc_bit<ram_com7, 16>;
    /* S15 */
    using ram_com7_s15 = lp::assoc_bit<ram_com7, 15>;
    /* S14 */
    using ram_com7_s14 = lp::assoc_bit<ram_com7, 14>;
    /* S13 */
    using ram_com7_s13 = lp::assoc_bit<ram_com7, 13>;
    /* S12 */
    using ram_com7_s12 = lp::assoc_bit<ram_com7, 12>;
    /* S11 */
    using ram_com7_s11 = lp::assoc_bit<ram_com7, 11>;
    /* S10 */
    using ram_com7_s10 = lp::assoc_bit<ram_com7, 10>;
    /* S09 */
    using ram_com7_s09 = lp::assoc_bit<ram_com7, 9>;
    /* S08 */
    using ram_com7_s08 = lp::assoc_bit<ram_com7, 8>;
    /* S07 */
    using ram_com7_s07 = lp::assoc_bit<ram_com7, 7>;
    /* S06 */
    using ram_com7_s06 = lp::assoc_bit<ram_com7, 6>;
    /* S05 */
    using ram_com7_s05 = lp::assoc_bit<ram_com7, 5>;
    /* S04 */
    using ram_com7_s04 = lp::assoc_bit<ram_com7, 4>;
    /* S03 */
    using ram_com7_s03 = lp::assoc_bit<ram_com7, 3>;
    /* S02 */
    using ram_com7_s02 = lp::assoc_bit<ram_com7, 2>;
    /* S01 */
    using ram_com7_s01 = lp::assoc_bit<ram_com7, 1>;
    /* S00 */
    using ram_com7_s00 = lp::assoc_bit<ram_com7, 0>;


};

using lcd = lcd_t<0x40002400>;

#endif // LCD_HH
