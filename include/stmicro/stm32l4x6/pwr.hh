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
 * Hardware support for pwr
 * @file pwr.hh
 * @author Boris Vinogradov
 */

#include <associate_bit.hh>
#include <io_register.hh>
#include <types.hh>

#ifndef PWR_HH
#define PWR_HH

/* Power control */
template <lp::addr_t base_address>
struct pwr_t {
    /* Power control register 1 */
    using cr1 = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* Low-power run */
    using cr1_lpr = lp::assoc_bit<cr1, 14>;
    /* Voltage scaling range               selection */
    using cr1_vos = lp::assoc_bit<cr1, 9, 2>;
    /* Disable backup domain write               protection */
    using cr1_dbp = lp::assoc_bit<cr1, 8>;
    /* Low-power mode selection */
    using cr1_lpms = lp::assoc_bit<cr1, 0, 3>;


    /* Power control register 2 */
    using cr2 = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* VDDUSB USB supply valid */
    using cr2_usv = lp::assoc_bit<cr2, 10>;
    /* VDDIO2 Independent I/Os supply               valid */
    using cr2_iosv = lp::assoc_bit<cr2, 9>;
    /* Peripheral voltage monitoring 4 enable:               VDDA vs. 2.2V */
    using cr2_pvme4 = lp::assoc_bit<cr2, 7>;
    /* Peripheral voltage monitoring 3 enable:               VDDA vs. 1.62V */
    using cr2_pvme3 = lp::assoc_bit<cr2, 6>;
    /* Peripheral voltage monitoring 2 enable:               VDDIO2 vs. 0.9V */
    using cr2_pvme2 = lp::assoc_bit<cr2, 5>;
    /* Peripheral voltage monitoring 1 enable:               VDDUSB vs. 1.2V */
    using cr2_pvme1 = lp::assoc_bit<cr2, 4>;
    /* Power voltage detector level               selection */
    using cr2_pls = lp::assoc_bit<cr2, 1, 3>;
    /* Power voltage detector               enable */
    using cr2_pvde = lp::assoc_bit<cr2, 0>;


    /* Power control register 3 */
    using cr3 = lp::io_register<lp::u32_t, base_address + 0x8>;
    /* Enable internal wakeup               line */
    using cr3_ewf = lp::assoc_bit<cr3, 15>;
    /* Apply pull-up and pull-down               configuration */
    using cr3_apc = lp::assoc_bit<cr3, 10>;
    /* SRAM2 retention in Standby               mode */
    using cr3_rrs = lp::assoc_bit<cr3, 8>;
    /* Enable Wakeup pin WKUP5 */
    using cr3_ewup5 = lp::assoc_bit<cr3, 4>;
    /* Enable Wakeup pin WKUP4 */
    using cr3_ewup4 = lp::assoc_bit<cr3, 3>;
    /* Enable Wakeup pin WKUP3 */
    using cr3_ewup3 = lp::assoc_bit<cr3, 2>;
    /* Enable Wakeup pin WKUP2 */
    using cr3_ewup2 = lp::assoc_bit<cr3, 1>;
    /* Enable Wakeup pin WKUP1 */
    using cr3_ewup1 = lp::assoc_bit<cr3, 0>;


    /* Power control register 4 */
    using cr4 = lp::io_register<lp::u32_t, base_address + 0xc>;
    /* VBAT battery charging resistor               selection */
    using cr4_vbrs = lp::assoc_bit<cr4, 9>;
    /* VBAT battery charging               enable */
    using cr4_vbe = lp::assoc_bit<cr4, 8>;
    /* Wakeup pin WKUP5 polarity */
    using cr4_wp5 = lp::assoc_bit<cr4, 4>;
    /* Wakeup pin WKUP4 polarity */
    using cr4_wp4 = lp::assoc_bit<cr4, 3>;
    /* Wakeup pin WKUP3 polarity */
    using cr4_wp3 = lp::assoc_bit<cr4, 2>;
    /* Wakeup pin WKUP2 polarity */
    using cr4_wp2 = lp::assoc_bit<cr4, 1>;
    /* Wakeup pin WKUP1 polarity */
    using cr4_wp1 = lp::assoc_bit<cr4, 0>;


    /* Power status register 1 */
    using sr1 = lp::io_register<lp::u32_t, base_address + 0x10>;
    /* Wakeup flag internal */
    using sr1_wufi = lp::assoc_bit<sr1, 15>;
    /* Standby flag */
    using sr1_csbf = lp::assoc_bit<sr1, 8>;
    /* Wakeup flag 5 */
    using sr1_cwuf5 = lp::assoc_bit<sr1, 4>;
    /* Wakeup flag 4 */
    using sr1_cwuf4 = lp::assoc_bit<sr1, 3>;
    /* Wakeup flag 3 */
    using sr1_cwuf3 = lp::assoc_bit<sr1, 2>;
    /* Wakeup flag 2 */
    using sr1_cwuf2 = lp::assoc_bit<sr1, 1>;
    /* Wakeup flag 1 */
    using sr1_cwuf1 = lp::assoc_bit<sr1, 0>;


    /* Power status register 2 */
    using sr2 = lp::io_register<lp::u32_t, base_address + 0x14>;
    /* Peripheral voltage monitoring output:               VDDA vs. 2.2 V */
    using sr2_pvmo4 = lp::assoc_bit<sr2, 15>;
    /* Peripheral voltage monitoring output:               VDDA vs. 1.62 V */
    using sr2_pvmo3 = lp::assoc_bit<sr2, 14>;
    /* Peripheral voltage monitoring output:               VDDIO2 vs. 0.9 V */
    using sr2_pvmo2 = lp::assoc_bit<sr2, 13>;
    /* Peripheral voltage monitoring output:               VDDUSB vs. 1.2 V */
    using sr2_pvmo1 = lp::assoc_bit<sr2, 12>;
    /* Power voltage detector               output */
    using sr2_pvdo = lp::assoc_bit<sr2, 11>;
    /* Voltage scaling flag */
    using sr2_vosf = lp::assoc_bit<sr2, 10>;
    /* Low-power regulator flag */
    using sr2_reglpf = lp::assoc_bit<sr2, 9>;
    /* Low-power regulator               started */
    using sr2_reglps = lp::assoc_bit<sr2, 8>;


    /* Power status clear register */
    using scr = lp::io_register<lp::u32_t, base_address + 0x18>;
    /* Clear standby flag */
    using scr_sbf = lp::assoc_bit<scr, 8>;
    /* Clear wakeup flag 5 */
    using scr_wuf5 = lp::assoc_bit<scr, 4>;
    /* Clear wakeup flag 4 */
    using scr_wuf4 = lp::assoc_bit<scr, 3>;
    /* Clear wakeup flag 3 */
    using scr_wuf3 = lp::assoc_bit<scr, 2>;
    /* Clear wakeup flag 2 */
    using scr_wuf2 = lp::assoc_bit<scr, 1>;
    /* Clear wakeup flag 1 */
    using scr_wuf1 = lp::assoc_bit<scr, 0>;


    /* Power Port A pull-up control           register */
    using pucra = lp::io_register<lp::u32_t, base_address + 0x20>;
    /* Port A pull-up bit y               (y=0..15) */
    using pucra_pu15 = lp::assoc_bit<pucra, 15>;
    /* Port A pull-up bit y               (y=0..15) */
    using pucra_pu14 = lp::assoc_bit<pucra, 14>;
    /* Port A pull-up bit y               (y=0..15) */
    using pucra_pu13 = lp::assoc_bit<pucra, 13>;
    /* Port A pull-up bit y               (y=0..15) */
    using pucra_pu12 = lp::assoc_bit<pucra, 12>;
    /* Port A pull-up bit y               (y=0..15) */
    using pucra_pu11 = lp::assoc_bit<pucra, 11>;
    /* Port A pull-up bit y               (y=0..15) */
    using pucra_pu10 = lp::assoc_bit<pucra, 10>;
    /* Port A pull-up bit y               (y=0..15) */
    using pucra_pu9 = lp::assoc_bit<pucra, 9>;
    /* Port A pull-up bit y               (y=0..15) */
    using pucra_pu8 = lp::assoc_bit<pucra, 8>;
    /* Port A pull-up bit y               (y=0..15) */
    using pucra_pu7 = lp::assoc_bit<pucra, 7>;
    /* Port A pull-up bit y               (y=0..15) */
    using pucra_pu6 = lp::assoc_bit<pucra, 6>;
    /* Port A pull-up bit y               (y=0..15) */
    using pucra_pu5 = lp::assoc_bit<pucra, 5>;
    /* Port A pull-up bit y               (y=0..15) */
    using pucra_pu4 = lp::assoc_bit<pucra, 4>;
    /* Port A pull-up bit y               (y=0..15) */
    using pucra_pu3 = lp::assoc_bit<pucra, 3>;
    /* Port A pull-up bit y               (y=0..15) */
    using pucra_pu2 = lp::assoc_bit<pucra, 2>;
    /* Port A pull-up bit y               (y=0..15) */
    using pucra_pu1 = lp::assoc_bit<pucra, 1>;
    /* Port A pull-up bit y               (y=0..15) */
    using pucra_pu0 = lp::assoc_bit<pucra, 0>;


    /* Power Port A pull-down control           register */
    using pdcra = lp::io_register<lp::u32_t, base_address + 0x24>;
    /* Port A pull-down bit y               (y=0..15) */
    using pdcra_pd15 = lp::assoc_bit<pdcra, 15>;
    /* Port A pull-down bit y               (y=0..15) */
    using pdcra_pd14 = lp::assoc_bit<pdcra, 14>;
    /* Port A pull-down bit y               (y=0..15) */
    using pdcra_pd13 = lp::assoc_bit<pdcra, 13>;
    /* Port A pull-down bit y               (y=0..15) */
    using pdcra_pd12 = lp::assoc_bit<pdcra, 12>;
    /* Port A pull-down bit y               (y=0..15) */
    using pdcra_pd11 = lp::assoc_bit<pdcra, 11>;
    /* Port A pull-down bit y               (y=0..15) */
    using pdcra_pd10 = lp::assoc_bit<pdcra, 10>;
    /* Port A pull-down bit y               (y=0..15) */
    using pdcra_pd9 = lp::assoc_bit<pdcra, 9>;
    /* Port A pull-down bit y               (y=0..15) */
    using pdcra_pd8 = lp::assoc_bit<pdcra, 8>;
    /* Port A pull-down bit y               (y=0..15) */
    using pdcra_pd7 = lp::assoc_bit<pdcra, 7>;
    /* Port A pull-down bit y               (y=0..15) */
    using pdcra_pd6 = lp::assoc_bit<pdcra, 6>;
    /* Port A pull-down bit y               (y=0..15) */
    using pdcra_pd5 = lp::assoc_bit<pdcra, 5>;
    /* Port A pull-down bit y               (y=0..15) */
    using pdcra_pd4 = lp::assoc_bit<pdcra, 4>;
    /* Port A pull-down bit y               (y=0..15) */
    using pdcra_pd3 = lp::assoc_bit<pdcra, 3>;
    /* Port A pull-down bit y               (y=0..15) */
    using pdcra_pd2 = lp::assoc_bit<pdcra, 2>;
    /* Port A pull-down bit y               (y=0..15) */
    using pdcra_pd1 = lp::assoc_bit<pdcra, 1>;
    /* Port A pull-down bit y               (y=0..15) */
    using pdcra_pd0 = lp::assoc_bit<pdcra, 0>;


    /* Power Port B pull-up control           register */
    using pucrb = lp::io_register<lp::u32_t, base_address + 0x28>;
    /* Port B pull-up bit y               (y=0..15) */
    using pucrb_pu15 = lp::assoc_bit<pucrb, 15>;
    /* Port B pull-up bit y               (y=0..15) */
    using pucrb_pu14 = lp::assoc_bit<pucrb, 14>;
    /* Port B pull-up bit y               (y=0..15) */
    using pucrb_pu13 = lp::assoc_bit<pucrb, 13>;
    /* Port B pull-up bit y               (y=0..15) */
    using pucrb_pu12 = lp::assoc_bit<pucrb, 12>;
    /* Port B pull-up bit y               (y=0..15) */
    using pucrb_pu11 = lp::assoc_bit<pucrb, 11>;
    /* Port B pull-up bit y               (y=0..15) */
    using pucrb_pu10 = lp::assoc_bit<pucrb, 10>;
    /* Port B pull-up bit y               (y=0..15) */
    using pucrb_pu9 = lp::assoc_bit<pucrb, 9>;
    /* Port B pull-up bit y               (y=0..15) */
    using pucrb_pu8 = lp::assoc_bit<pucrb, 8>;
    /* Port B pull-up bit y               (y=0..15) */
    using pucrb_pu7 = lp::assoc_bit<pucrb, 7>;
    /* Port B pull-up bit y               (y=0..15) */
    using pucrb_pu6 = lp::assoc_bit<pucrb, 6>;
    /* Port B pull-up bit y               (y=0..15) */
    using pucrb_pu5 = lp::assoc_bit<pucrb, 5>;
    /* Port B pull-up bit y               (y=0..15) */
    using pucrb_pu4 = lp::assoc_bit<pucrb, 4>;
    /* Port B pull-up bit y               (y=0..15) */
    using pucrb_pu3 = lp::assoc_bit<pucrb, 3>;
    /* Port B pull-up bit y               (y=0..15) */
    using pucrb_pu2 = lp::assoc_bit<pucrb, 2>;
    /* Port B pull-up bit y               (y=0..15) */
    using pucrb_pu1 = lp::assoc_bit<pucrb, 1>;
    /* Port B pull-up bit y               (y=0..15) */
    using pucrb_pu0 = lp::assoc_bit<pucrb, 0>;


    /* Power Port B pull-down control           register */
    using pdcrb = lp::io_register<lp::u32_t, base_address + 0x2c>;
    /* Port B pull-down bit y               (y=0..15) */
    using pdcrb_pd15 = lp::assoc_bit<pdcrb, 15>;
    /* Port B pull-down bit y               (y=0..15) */
    using pdcrb_pd14 = lp::assoc_bit<pdcrb, 14>;
    /* Port B pull-down bit y               (y=0..15) */
    using pdcrb_pd13 = lp::assoc_bit<pdcrb, 13>;
    /* Port B pull-down bit y               (y=0..15) */
    using pdcrb_pd12 = lp::assoc_bit<pdcrb, 12>;
    /* Port B pull-down bit y               (y=0..15) */
    using pdcrb_pd11 = lp::assoc_bit<pdcrb, 11>;
    /* Port B pull-down bit y               (y=0..15) */
    using pdcrb_pd10 = lp::assoc_bit<pdcrb, 10>;
    /* Port B pull-down bit y               (y=0..15) */
    using pdcrb_pd9 = lp::assoc_bit<pdcrb, 9>;
    /* Port B pull-down bit y               (y=0..15) */
    using pdcrb_pd8 = lp::assoc_bit<pdcrb, 8>;
    /* Port B pull-down bit y               (y=0..15) */
    using pdcrb_pd7 = lp::assoc_bit<pdcrb, 7>;
    /* Port B pull-down bit y               (y=0..15) */
    using pdcrb_pd6 = lp::assoc_bit<pdcrb, 6>;
    /* Port B pull-down bit y               (y=0..15) */
    using pdcrb_pd5 = lp::assoc_bit<pdcrb, 5>;
    /* Port B pull-down bit y               (y=0..15) */
    using pdcrb_pd4 = lp::assoc_bit<pdcrb, 4>;
    /* Port B pull-down bit y               (y=0..15) */
    using pdcrb_pd3 = lp::assoc_bit<pdcrb, 3>;
    /* Port B pull-down bit y               (y=0..15) */
    using pdcrb_pd2 = lp::assoc_bit<pdcrb, 2>;
    /* Port B pull-down bit y               (y=0..15) */
    using pdcrb_pd1 = lp::assoc_bit<pdcrb, 1>;
    /* Port B pull-down bit y               (y=0..15) */
    using pdcrb_pd0 = lp::assoc_bit<pdcrb, 0>;


    /* Power Port C pull-up control           register */
    using pucrc = lp::io_register<lp::u32_t, base_address + 0x30>;
    /* Port C pull-up bit y               (y=0..15) */
    using pucrc_pu15 = lp::assoc_bit<pucrc, 15>;
    /* Port C pull-up bit y               (y=0..15) */
    using pucrc_pu14 = lp::assoc_bit<pucrc, 14>;
    /* Port C pull-up bit y               (y=0..15) */
    using pucrc_pu13 = lp::assoc_bit<pucrc, 13>;
    /* Port C pull-up bit y               (y=0..15) */
    using pucrc_pu12 = lp::assoc_bit<pucrc, 12>;
    /* Port C pull-up bit y               (y=0..15) */
    using pucrc_pu11 = lp::assoc_bit<pucrc, 11>;
    /* Port C pull-up bit y               (y=0..15) */
    using pucrc_pu10 = lp::assoc_bit<pucrc, 10>;
    /* Port C pull-up bit y               (y=0..15) */
    using pucrc_pu9 = lp::assoc_bit<pucrc, 9>;
    /* Port C pull-up bit y               (y=0..15) */
    using pucrc_pu8 = lp::assoc_bit<pucrc, 8>;
    /* Port C pull-up bit y               (y=0..15) */
    using pucrc_pu7 = lp::assoc_bit<pucrc, 7>;
    /* Port C pull-up bit y               (y=0..15) */
    using pucrc_pu6 = lp::assoc_bit<pucrc, 6>;
    /* Port C pull-up bit y               (y=0..15) */
    using pucrc_pu5 = lp::assoc_bit<pucrc, 5>;
    /* Port C pull-up bit y               (y=0..15) */
    using pucrc_pu4 = lp::assoc_bit<pucrc, 4>;
    /* Port C pull-up bit y               (y=0..15) */
    using pucrc_pu3 = lp::assoc_bit<pucrc, 3>;
    /* Port C pull-up bit y               (y=0..15) */
    using pucrc_pu2 = lp::assoc_bit<pucrc, 2>;
    /* Port C pull-up bit y               (y=0..15) */
    using pucrc_pu1 = lp::assoc_bit<pucrc, 1>;
    /* Port C pull-up bit y               (y=0..15) */
    using pucrc_pu0 = lp::assoc_bit<pucrc, 0>;


    /* Power Port C pull-down control           register */
    using pdcrc = lp::io_register<lp::u32_t, base_address + 0x34>;
    /* Port C pull-down bit y               (y=0..15) */
    using pdcrc_pd15 = lp::assoc_bit<pdcrc, 15>;
    /* Port C pull-down bit y               (y=0..15) */
    using pdcrc_pd14 = lp::assoc_bit<pdcrc, 14>;
    /* Port C pull-down bit y               (y=0..15) */
    using pdcrc_pd13 = lp::assoc_bit<pdcrc, 13>;
    /* Port C pull-down bit y               (y=0..15) */
    using pdcrc_pd12 = lp::assoc_bit<pdcrc, 12>;
    /* Port C pull-down bit y               (y=0..15) */
    using pdcrc_pd11 = lp::assoc_bit<pdcrc, 11>;
    /* Port C pull-down bit y               (y=0..15) */
    using pdcrc_pd10 = lp::assoc_bit<pdcrc, 10>;
    /* Port C pull-down bit y               (y=0..15) */
    using pdcrc_pd9 = lp::assoc_bit<pdcrc, 9>;
    /* Port C pull-down bit y               (y=0..15) */
    using pdcrc_pd8 = lp::assoc_bit<pdcrc, 8>;
    /* Port C pull-down bit y               (y=0..15) */
    using pdcrc_pd7 = lp::assoc_bit<pdcrc, 7>;
    /* Port C pull-down bit y               (y=0..15) */
    using pdcrc_pd6 = lp::assoc_bit<pdcrc, 6>;
    /* Port C pull-down bit y               (y=0..15) */
    using pdcrc_pd5 = lp::assoc_bit<pdcrc, 5>;
    /* Port C pull-down bit y               (y=0..15) */
    using pdcrc_pd4 = lp::assoc_bit<pdcrc, 4>;
    /* Port C pull-down bit y               (y=0..15) */
    using pdcrc_pd3 = lp::assoc_bit<pdcrc, 3>;
    /* Port C pull-down bit y               (y=0..15) */
    using pdcrc_pd2 = lp::assoc_bit<pdcrc, 2>;
    /* Port C pull-down bit y               (y=0..15) */
    using pdcrc_pd1 = lp::assoc_bit<pdcrc, 1>;
    /* Port C pull-down bit y               (y=0..15) */
    using pdcrc_pd0 = lp::assoc_bit<pdcrc, 0>;


    /* Power Port D pull-up control           register */
    using pucrd = lp::io_register<lp::u32_t, base_address + 0x38>;
    /* Port D pull-up bit y               (y=0..15) */
    using pucrd_pu15 = lp::assoc_bit<pucrd, 15>;
    /* Port D pull-up bit y               (y=0..15) */
    using pucrd_pu14 = lp::assoc_bit<pucrd, 14>;
    /* Port D pull-up bit y               (y=0..15) */
    using pucrd_pu13 = lp::assoc_bit<pucrd, 13>;
    /* Port D pull-up bit y               (y=0..15) */
    using pucrd_pu12 = lp::assoc_bit<pucrd, 12>;
    /* Port D pull-up bit y               (y=0..15) */
    using pucrd_pu11 = lp::assoc_bit<pucrd, 11>;
    /* Port D pull-up bit y               (y=0..15) */
    using pucrd_pu10 = lp::assoc_bit<pucrd, 10>;
    /* Port D pull-up bit y               (y=0..15) */
    using pucrd_pu9 = lp::assoc_bit<pucrd, 9>;
    /* Port D pull-up bit y               (y=0..15) */
    using pucrd_pu8 = lp::assoc_bit<pucrd, 8>;
    /* Port D pull-up bit y               (y=0..15) */
    using pucrd_pu7 = lp::assoc_bit<pucrd, 7>;
    /* Port D pull-up bit y               (y=0..15) */
    using pucrd_pu6 = lp::assoc_bit<pucrd, 6>;
    /* Port D pull-up bit y               (y=0..15) */
    using pucrd_pu5 = lp::assoc_bit<pucrd, 5>;
    /* Port D pull-up bit y               (y=0..15) */
    using pucrd_pu4 = lp::assoc_bit<pucrd, 4>;
    /* Port D pull-up bit y               (y=0..15) */
    using pucrd_pu3 = lp::assoc_bit<pucrd, 3>;
    /* Port D pull-up bit y               (y=0..15) */
    using pucrd_pu2 = lp::assoc_bit<pucrd, 2>;
    /* Port D pull-up bit y               (y=0..15) */
    using pucrd_pu1 = lp::assoc_bit<pucrd, 1>;
    /* Port D pull-up bit y               (y=0..15) */
    using pucrd_pu0 = lp::assoc_bit<pucrd, 0>;


    /* Power Port D pull-down control           register */
    using pdcrd = lp::io_register<lp::u32_t, base_address + 0x3c>;
    /* Port D pull-down bit y               (y=0..15) */
    using pdcrd_pd15 = lp::assoc_bit<pdcrd, 15>;
    /* Port D pull-down bit y               (y=0..15) */
    using pdcrd_pd14 = lp::assoc_bit<pdcrd, 14>;
    /* Port D pull-down bit y               (y=0..15) */
    using pdcrd_pd13 = lp::assoc_bit<pdcrd, 13>;
    /* Port D pull-down bit y               (y=0..15) */
    using pdcrd_pd12 = lp::assoc_bit<pdcrd, 12>;
    /* Port D pull-down bit y               (y=0..15) */
    using pdcrd_pd11 = lp::assoc_bit<pdcrd, 11>;
    /* Port D pull-down bit y               (y=0..15) */
    using pdcrd_pd10 = lp::assoc_bit<pdcrd, 10>;
    /* Port D pull-down bit y               (y=0..15) */
    using pdcrd_pd9 = lp::assoc_bit<pdcrd, 9>;
    /* Port D pull-down bit y               (y=0..15) */
    using pdcrd_pd8 = lp::assoc_bit<pdcrd, 8>;
    /* Port D pull-down bit y               (y=0..15) */
    using pdcrd_pd7 = lp::assoc_bit<pdcrd, 7>;
    /* Port D pull-down bit y               (y=0..15) */
    using pdcrd_pd6 = lp::assoc_bit<pdcrd, 6>;
    /* Port D pull-down bit y               (y=0..15) */
    using pdcrd_pd5 = lp::assoc_bit<pdcrd, 5>;
    /* Port D pull-down bit y               (y=0..15) */
    using pdcrd_pd4 = lp::assoc_bit<pdcrd, 4>;
    /* Port D pull-down bit y               (y=0..15) */
    using pdcrd_pd3 = lp::assoc_bit<pdcrd, 3>;
    /* Port D pull-down bit y               (y=0..15) */
    using pdcrd_pd2 = lp::assoc_bit<pdcrd, 2>;
    /* Port D pull-down bit y               (y=0..15) */
    using pdcrd_pd1 = lp::assoc_bit<pdcrd, 1>;
    /* Port D pull-down bit y               (y=0..15) */
    using pdcrd_pd0 = lp::assoc_bit<pdcrd, 0>;


    /* Power Port E pull-up control           register */
    using pucre = lp::io_register<lp::u32_t, base_address + 0x40>;
    /* Port E pull-up bit y               (y=0..15) */
    using pucre_pu15 = lp::assoc_bit<pucre, 15>;
    /* Port E pull-up bit y               (y=0..15) */
    using pucre_pu14 = lp::assoc_bit<pucre, 14>;
    /* Port E pull-up bit y               (y=0..15) */
    using pucre_pu13 = lp::assoc_bit<pucre, 13>;
    /* Port E pull-up bit y               (y=0..15) */
    using pucre_pu12 = lp::assoc_bit<pucre, 12>;
    /* Port E pull-up bit y               (y=0..15) */
    using pucre_pu11 = lp::assoc_bit<pucre, 11>;
    /* Port E pull-up bit y               (y=0..15) */
    using pucre_pu10 = lp::assoc_bit<pucre, 10>;
    /* Port E pull-up bit y               (y=0..15) */
    using pucre_pu9 = lp::assoc_bit<pucre, 9>;
    /* Port E pull-up bit y               (y=0..15) */
    using pucre_pu8 = lp::assoc_bit<pucre, 8>;
    /* Port E pull-up bit y               (y=0..15) */
    using pucre_pu7 = lp::assoc_bit<pucre, 7>;
    /* Port E pull-up bit y               (y=0..15) */
    using pucre_pu6 = lp::assoc_bit<pucre, 6>;
    /* Port E pull-up bit y               (y=0..15) */
    using pucre_pu5 = lp::assoc_bit<pucre, 5>;
    /* Port E pull-up bit y               (y=0..15) */
    using pucre_pu4 = lp::assoc_bit<pucre, 4>;
    /* Port E pull-up bit y               (y=0..15) */
    using pucre_pu3 = lp::assoc_bit<pucre, 3>;
    /* Port E pull-up bit y               (y=0..15) */
    using pucre_pu2 = lp::assoc_bit<pucre, 2>;
    /* Port E pull-up bit y               (y=0..15) */
    using pucre_pu1 = lp::assoc_bit<pucre, 1>;
    /* Port E pull-up bit y               (y=0..15) */
    using pucre_pu0 = lp::assoc_bit<pucre, 0>;


    /* Power Port E pull-down control           register */
    using pdcre = lp::io_register<lp::u32_t, base_address + 0x44>;
    /* Port E pull-down bit y               (y=0..15) */
    using pdcre_pd15 = lp::assoc_bit<pdcre, 15>;
    /* Port E pull-down bit y               (y=0..15) */
    using pdcre_pd14 = lp::assoc_bit<pdcre, 14>;
    /* Port E pull-down bit y               (y=0..15) */
    using pdcre_pd13 = lp::assoc_bit<pdcre, 13>;
    /* Port E pull-down bit y               (y=0..15) */
    using pdcre_pd12 = lp::assoc_bit<pdcre, 12>;
    /* Port E pull-down bit y               (y=0..15) */
    using pdcre_pd11 = lp::assoc_bit<pdcre, 11>;
    /* Port E pull-down bit y               (y=0..15) */
    using pdcre_pd10 = lp::assoc_bit<pdcre, 10>;
    /* Port E pull-down bit y               (y=0..15) */
    using pdcre_pd9 = lp::assoc_bit<pdcre, 9>;
    /* Port E pull-down bit y               (y=0..15) */
    using pdcre_pd8 = lp::assoc_bit<pdcre, 8>;
    /* Port E pull-down bit y               (y=0..15) */
    using pdcre_pd7 = lp::assoc_bit<pdcre, 7>;
    /* Port E pull-down bit y               (y=0..15) */
    using pdcre_pd6 = lp::assoc_bit<pdcre, 6>;
    /* Port E pull-down bit y               (y=0..15) */
    using pdcre_pd5 = lp::assoc_bit<pdcre, 5>;
    /* Port E pull-down bit y               (y=0..15) */
    using pdcre_pd4 = lp::assoc_bit<pdcre, 4>;
    /* Port E pull-down bit y               (y=0..15) */
    using pdcre_pd3 = lp::assoc_bit<pdcre, 3>;
    /* Port E pull-down bit y               (y=0..15) */
    using pdcre_pd2 = lp::assoc_bit<pdcre, 2>;
    /* Port E pull-down bit y               (y=0..15) */
    using pdcre_pd1 = lp::assoc_bit<pdcre, 1>;
    /* Port E pull-down bit y               (y=0..15) */
    using pdcre_pd0 = lp::assoc_bit<pdcre, 0>;


    /* Power Port F pull-up control           register */
    using pucrf = lp::io_register<lp::u32_t, base_address + 0x48>;
    /* Port F pull-up bit y               (y=0..15) */
    using pucrf_pu15 = lp::assoc_bit<pucrf, 15>;
    /* Port F pull-up bit y               (y=0..15) */
    using pucrf_pu14 = lp::assoc_bit<pucrf, 14>;
    /* Port F pull-up bit y               (y=0..15) */
    using pucrf_pu13 = lp::assoc_bit<pucrf, 13>;
    /* Port F pull-up bit y               (y=0..15) */
    using pucrf_pu12 = lp::assoc_bit<pucrf, 12>;
    /* Port F pull-up bit y               (y=0..15) */
    using pucrf_pu11 = lp::assoc_bit<pucrf, 11>;
    /* Port F pull-up bit y               (y=0..15) */
    using pucrf_pu10 = lp::assoc_bit<pucrf, 10>;
    /* Port F pull-up bit y               (y=0..15) */
    using pucrf_pu9 = lp::assoc_bit<pucrf, 9>;
    /* Port F pull-up bit y               (y=0..15) */
    using pucrf_pu8 = lp::assoc_bit<pucrf, 8>;
    /* Port F pull-up bit y               (y=0..15) */
    using pucrf_pu7 = lp::assoc_bit<pucrf, 7>;
    /* Port F pull-up bit y               (y=0..15) */
    using pucrf_pu6 = lp::assoc_bit<pucrf, 6>;
    /* Port F pull-up bit y               (y=0..15) */
    using pucrf_pu5 = lp::assoc_bit<pucrf, 5>;
    /* Port F pull-up bit y               (y=0..15) */
    using pucrf_pu4 = lp::assoc_bit<pucrf, 4>;
    /* Port F pull-up bit y               (y=0..15) */
    using pucrf_pu3 = lp::assoc_bit<pucrf, 3>;
    /* Port F pull-up bit y               (y=0..15) */
    using pucrf_pu2 = lp::assoc_bit<pucrf, 2>;
    /* Port F pull-up bit y               (y=0..15) */
    using pucrf_pu1 = lp::assoc_bit<pucrf, 1>;
    /* Port F pull-up bit y               (y=0..15) */
    using pucrf_pu0 = lp::assoc_bit<pucrf, 0>;


    /* Power Port F pull-down control           register */
    using pdcrf = lp::io_register<lp::u32_t, base_address + 0x4c>;
    /* Port F pull-down bit y               (y=0..15) */
    using pdcrf_pd15 = lp::assoc_bit<pdcrf, 15>;
    /* Port F pull-down bit y               (y=0..15) */
    using pdcrf_pd14 = lp::assoc_bit<pdcrf, 14>;
    /* Port F pull-down bit y               (y=0..15) */
    using pdcrf_pd13 = lp::assoc_bit<pdcrf, 13>;
    /* Port F pull-down bit y               (y=0..15) */
    using pdcrf_pd12 = lp::assoc_bit<pdcrf, 12>;
    /* Port F pull-down bit y               (y=0..15) */
    using pdcrf_pd11 = lp::assoc_bit<pdcrf, 11>;
    /* Port F pull-down bit y               (y=0..15) */
    using pdcrf_pd10 = lp::assoc_bit<pdcrf, 10>;
    /* Port F pull-down bit y               (y=0..15) */
    using pdcrf_pd9 = lp::assoc_bit<pdcrf, 9>;
    /* Port F pull-down bit y               (y=0..15) */
    using pdcrf_pd8 = lp::assoc_bit<pdcrf, 8>;
    /* Port F pull-down bit y               (y=0..15) */
    using pdcrf_pd7 = lp::assoc_bit<pdcrf, 7>;
    /* Port F pull-down bit y               (y=0..15) */
    using pdcrf_pd6 = lp::assoc_bit<pdcrf, 6>;
    /* Port F pull-down bit y               (y=0..15) */
    using pdcrf_pd5 = lp::assoc_bit<pdcrf, 5>;
    /* Port F pull-down bit y               (y=0..15) */
    using pdcrf_pd4 = lp::assoc_bit<pdcrf, 4>;
    /* Port F pull-down bit y               (y=0..15) */
    using pdcrf_pd3 = lp::assoc_bit<pdcrf, 3>;
    /* Port F pull-down bit y               (y=0..15) */
    using pdcrf_pd2 = lp::assoc_bit<pdcrf, 2>;
    /* Port F pull-down bit y               (y=0..15) */
    using pdcrf_pd1 = lp::assoc_bit<pdcrf, 1>;
    /* Port F pull-down bit y               (y=0..15) */
    using pdcrf_pd0 = lp::assoc_bit<pdcrf, 0>;


    /* Power Port G pull-up control           register */
    using pucrg = lp::io_register<lp::u32_t, base_address + 0x50>;
    /* Port G pull-up bit y               (y=0..15) */
    using pucrg_pu15 = lp::assoc_bit<pucrg, 15>;
    /* Port G pull-up bit y               (y=0..15) */
    using pucrg_pu14 = lp::assoc_bit<pucrg, 14>;
    /* Port G pull-up bit y               (y=0..15) */
    using pucrg_pu13 = lp::assoc_bit<pucrg, 13>;
    /* Port G pull-up bit y               (y=0..15) */
    using pucrg_pu12 = lp::assoc_bit<pucrg, 12>;
    /* Port G pull-up bit y               (y=0..15) */
    using pucrg_pu11 = lp::assoc_bit<pucrg, 11>;
    /* Port G pull-up bit y               (y=0..15) */
    using pucrg_pu10 = lp::assoc_bit<pucrg, 10>;
    /* Port G pull-up bit y               (y=0..15) */
    using pucrg_pu9 = lp::assoc_bit<pucrg, 9>;
    /* Port G pull-up bit y               (y=0..15) */
    using pucrg_pu8 = lp::assoc_bit<pucrg, 8>;
    /* Port G pull-up bit y               (y=0..15) */
    using pucrg_pu7 = lp::assoc_bit<pucrg, 7>;
    /* Port G pull-up bit y               (y=0..15) */
    using pucrg_pu6 = lp::assoc_bit<pucrg, 6>;
    /* Port G pull-up bit y               (y=0..15) */
    using pucrg_pu5 = lp::assoc_bit<pucrg, 5>;
    /* Port G pull-up bit y               (y=0..15) */
    using pucrg_pu4 = lp::assoc_bit<pucrg, 4>;
    /* Port G pull-up bit y               (y=0..15) */
    using pucrg_pu3 = lp::assoc_bit<pucrg, 3>;
    /* Port G pull-up bit y               (y=0..15) */
    using pucrg_pu2 = lp::assoc_bit<pucrg, 2>;
    /* Port G pull-up bit y               (y=0..15) */
    using pucrg_pu1 = lp::assoc_bit<pucrg, 1>;
    /* Port G pull-up bit y               (y=0..15) */
    using pucrg_pu0 = lp::assoc_bit<pucrg, 0>;


    /* Power Port G pull-down control           register */
    using pdcrg = lp::io_register<lp::u32_t, base_address + 0x54>;
    /* Port G pull-down bit y               (y=0..15) */
    using pdcrg_pd15 = lp::assoc_bit<pdcrg, 15>;
    /* Port G pull-down bit y               (y=0..15) */
    using pdcrg_pd14 = lp::assoc_bit<pdcrg, 14>;
    /* Port G pull-down bit y               (y=0..15) */
    using pdcrg_pd13 = lp::assoc_bit<pdcrg, 13>;
    /* Port G pull-down bit y               (y=0..15) */
    using pdcrg_pd12 = lp::assoc_bit<pdcrg, 12>;
    /* Port G pull-down bit y               (y=0..15) */
    using pdcrg_pd11 = lp::assoc_bit<pdcrg, 11>;
    /* Port G pull-down bit y               (y=0..15) */
    using pdcrg_pd10 = lp::assoc_bit<pdcrg, 10>;
    /* Port G pull-down bit y               (y=0..15) */
    using pdcrg_pd9 = lp::assoc_bit<pdcrg, 9>;
    /* Port G pull-down bit y               (y=0..15) */
    using pdcrg_pd8 = lp::assoc_bit<pdcrg, 8>;
    /* Port G pull-down bit y               (y=0..15) */
    using pdcrg_pd7 = lp::assoc_bit<pdcrg, 7>;
    /* Port G pull-down bit y               (y=0..15) */
    using pdcrg_pd6 = lp::assoc_bit<pdcrg, 6>;
    /* Port G pull-down bit y               (y=0..15) */
    using pdcrg_pd5 = lp::assoc_bit<pdcrg, 5>;
    /* Port G pull-down bit y               (y=0..15) */
    using pdcrg_pd4 = lp::assoc_bit<pdcrg, 4>;
    /* Port G pull-down bit y               (y=0..15) */
    using pdcrg_pd3 = lp::assoc_bit<pdcrg, 3>;
    /* Port G pull-down bit y               (y=0..15) */
    using pdcrg_pd2 = lp::assoc_bit<pdcrg, 2>;
    /* Port G pull-down bit y               (y=0..15) */
    using pdcrg_pd1 = lp::assoc_bit<pdcrg, 1>;
    /* Port G pull-down bit y               (y=0..15) */
    using pdcrg_pd0 = lp::assoc_bit<pdcrg, 0>;


    /* Power Port H pull-up control           register */
    using pucrh = lp::io_register<lp::u32_t, base_address + 0x58>;
    /* Port H pull-up bit y               (y=0..1) */
    using pucrh_pu1 = lp::assoc_bit<pucrh, 1>;
    /* Port H pull-up bit y               (y=0..1) */
    using pucrh_pu0 = lp::assoc_bit<pucrh, 0>;


    /* Power Port H pull-down control           register */
    using pdcrh = lp::io_register<lp::u32_t, base_address + 0x5c>;
    /* Port H pull-down bit y               (y=0..1) */
    using pdcrh_pd1 = lp::assoc_bit<pdcrh, 1>;
    /* Port H pull-down bit y               (y=0..1) */
    using pdcrh_pd0 = lp::assoc_bit<pdcrh, 0>;


};

using pwr = pwr_t<0x40007000>;

#endif // PWR_HH
