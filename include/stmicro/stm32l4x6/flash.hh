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
 * Hardware support for flash
 * @file flash.hh
 * @author Boris Vinogradov
 */

#include <associate_bit.hh>
#include <io_register.hh>
#include <types.hh>

#ifndef FLASH_HH
#define FLASH_HH

/* Flash */
template <lp::addr_t base_address>
struct flash_t {
    /* Access control register */
    using acr = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* Latency */
    using acr_latency = lp::assoc_bit<acr, 0, 3>;
    /* Prefetch enable */
    using acr_prften = lp::assoc_bit<acr, 8>;
    /* Instruction cache enable */
    using acr_icen = lp::assoc_bit<acr, 9>;
    /* Data cache enable */
    using acr_dcen = lp::assoc_bit<acr, 10>;
    /* Instruction cache reset */
    using acr_icrst = lp::assoc_bit<acr, 11>;
    /* Data cache reset */
    using acr_dcrst = lp::assoc_bit<acr, 12>;
    /* Flash Power-down mode during Low-power               run mode */
    using acr_run_pd = lp::assoc_bit<acr, 13>;
    /* Flash Power-down mode during Low-power               sleep mode */
    using acr_sleep_pd = lp::assoc_bit<acr, 14>;


    /* Power down key register */
    using pdkeyr = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* RUN_PD in FLASH_ACR key */
    using pdkeyr_pdkeyr = lp::assoc_bit<pdkeyr, 0, 32>;


    /* Flash key register */
    using keyr = lp::io_register<lp::u32_t, base_address + 0x8>;
    /* KEYR */
    using keyr_keyr = lp::assoc_bit<keyr, 0, 32>;


    /* Option byte key register */
    using optkeyr = lp::io_register<lp::u32_t, base_address + 0xc>;
    /* Option byte key */
    using optkeyr_optkeyr = lp::assoc_bit<optkeyr, 0, 32>;


    /* Status register */
    using sr = lp::io_register<lp::u32_t, base_address + 0x10>;
    /* End of operation */
    using sr_eop = lp::assoc_bit<sr, 0>;
    /* Operation error */
    using sr_operr = lp::assoc_bit<sr, 1>;
    /* Programming error */
    using sr_progerr = lp::assoc_bit<sr, 3>;
    /* Write protected error */
    using sr_wrperr = lp::assoc_bit<sr, 4>;
    /* Programming alignment               error */
    using sr_pgaerr = lp::assoc_bit<sr, 5>;
    /* Size error */
    using sr_sizerr = lp::assoc_bit<sr, 6>;
    /* Programming sequence error */
    using sr_pgserr = lp::assoc_bit<sr, 7>;
    /* Fast programming data miss               error */
    using sr_miserr = lp::assoc_bit<sr, 8>;
    /* Fast programming error */
    using sr_fasterr = lp::assoc_bit<sr, 9>;
    /* PCROP read error */
    using sr_rderr = lp::assoc_bit<sr, 14>;
    /* Option validity error */
    using sr_optverr = lp::assoc_bit<sr, 15>;
    /* Busy */
    using sr_bsy = lp::assoc_bit<sr, 16>;


    /* Flash control register */
    using cr = lp::io_register<lp::u32_t, base_address + 0x14>;
    /* Programming */
    using cr_pg = lp::assoc_bit<cr, 0>;
    /* Page erase */
    using cr_per = lp::assoc_bit<cr, 1>;
    /* Bank 1 Mass erase */
    using cr_mer1 = lp::assoc_bit<cr, 2>;
    /* Page number */
    using cr_pnb = lp::assoc_bit<cr, 3, 8>;
    /* Bank erase */
    using cr_bker = lp::assoc_bit<cr, 11>;
    /* Bank 2 Mass erase */
    using cr_mer2 = lp::assoc_bit<cr, 15>;
    /* Start */
    using cr_start = lp::assoc_bit<cr, 16>;
    /* Options modification start */
    using cr_optstrt = lp::assoc_bit<cr, 17>;
    /* Fast programming */
    using cr_fstpg = lp::assoc_bit<cr, 18>;
    /* End of operation interrupt               enable */
    using cr_eopie = lp::assoc_bit<cr, 24>;
    /* Error interrupt enable */
    using cr_errie = lp::assoc_bit<cr, 25>;
    /* PCROP read error interrupt               enable */
    using cr_rderrie = lp::assoc_bit<cr, 26>;
    /* Force the option byte               loading */
    using cr_obl_launch = lp::assoc_bit<cr, 27>;
    /* Options Lock */
    using cr_optlock = lp::assoc_bit<cr, 30>;
    /* FLASH_CR Lock */
    using cr_lock = lp::assoc_bit<cr, 31>;


    /* Flash ECC register */
    using eccr = lp::io_register<lp::u32_t, base_address + 0x18>;
    /* ECC fail address */
    using eccr_addr_ecc = lp::assoc_bit<eccr, 0, 19>;
    /* ECC fail bank */
    using eccr_bk_ecc = lp::assoc_bit<eccr, 19>;
    /* System Flash ECC fail */
    using eccr_sysf_ecc = lp::assoc_bit<eccr, 20>;
    /* ECC correction interrupt               enable */
    using eccr_eccie = lp::assoc_bit<eccr, 24>;
    /* ECC correction */
    using eccr_eccc = lp::assoc_bit<eccr, 30>;
    /* ECC detection */
    using eccr_eccd = lp::assoc_bit<eccr, 31>;


    /* Flash option register */
    using optr = lp::io_register<lp::u32_t, base_address + 0x20>;
    /* Read protection level */
    using optr_rdp = lp::assoc_bit<optr, 0, 8>;
    /* BOR reset Level */
    using optr_bor_lev = lp::assoc_bit<optr, 8, 3>;
    /* nRST_STOP */
    using optr_nrst_stop = lp::assoc_bit<optr, 12>;
    /* nRST_STDBY */
    using optr_nrst_stdby = lp::assoc_bit<optr, 13>;
    /* Independent watchdog               selection */
    using optr_idwg_sw = lp::assoc_bit<optr, 16>;
    /* Independent watchdog counter freeze in               Stop mode */
    using optr_iwdg_stop = lp::assoc_bit<optr, 17>;
    /* Independent watchdog counter freeze in               Standby mode */
    using optr_iwdg_stdby = lp::assoc_bit<optr, 18>;
    /* Window watchdog selection */
    using optr_wwdg_sw = lp::assoc_bit<optr, 19>;
    /* Dual-bank boot */
    using optr_bfb2 = lp::assoc_bit<optr, 20>;
    /* Dual-Bank on 512 KB or 256 KB Flash               memory devices */
    using optr_dualbank = lp::assoc_bit<optr, 21>;
    /* Boot configuration */
    using optr_nboot1 = lp::assoc_bit<optr, 23>;
    /* SRAM2 parity check enable */
    using optr_sram2_pe = lp::assoc_bit<optr, 24>;
    /* SRAM2 Erase when system               reset */
    using optr_sram2_rst = lp::assoc_bit<optr, 25>;


    /* Flash Bank 1 PCROP Start address           register */
    using pcrop1sr = lp::io_register<lp::u32_t, base_address + 0x24>;
    /* Bank 1 PCROP area start               offset */
    using pcrop1sr_pcrop1_strt = lp::assoc_bit<pcrop1sr, 0, 16>;


    /* Flash Bank 1 PCROP End address           register */
    using pcrop1er = lp::io_register<lp::u32_t, base_address + 0x28>;
    /* Bank 1 PCROP area end               offset */
    using pcrop1er_pcrop1_end = lp::assoc_bit<pcrop1er, 0, 16>;
    /* PCROP area preserved when RDP level               decreased */
    using pcrop1er_pcrop_rdp = lp::assoc_bit<pcrop1er, 31>;


    /* Flash Bank 1 WRP area A address           register */
    using wrp1ar = lp::io_register<lp::u32_t, base_address + 0x2c>;
    /* Bank 1 WRP first area start               offset */
    using wrp1ar_wrp1a_strt = lp::assoc_bit<wrp1ar, 0, 8>;
    /* Bank 1 WRP first area A end               offset */
    using wrp1ar_wrp1a_end = lp::assoc_bit<wrp1ar, 16, 8>;


    /* Flash Bank 1 WRP area B address           register */
    using wrp1br = lp::io_register<lp::u32_t, base_address + 0x30>;
    /* Bank 1 WRP second area B end               offset */
    using wrp1br_wrp1b_strt = lp::assoc_bit<wrp1br, 16, 8>;
    /* Bank 1 WRP second area B start               offset */
    using wrp1br_wrp1b_end = lp::assoc_bit<wrp1br, 0, 8>;


    /* Flash Bank 2 PCROP Start address           register */
    using pcrop2sr = lp::io_register<lp::u32_t, base_address + 0x44>;
    /* Bank 2 PCROP area start               offset */
    using pcrop2sr_pcrop2_strt = lp::assoc_bit<pcrop2sr, 0, 16>;


    /* Flash Bank 2 PCROP End address           register */
    using pcrop2er = lp::io_register<lp::u32_t, base_address + 0x48>;
    /* Bank 2 PCROP area end               offset */
    using pcrop2er_pcrop2_end = lp::assoc_bit<pcrop2er, 0, 16>;


    /* Flash Bank 2 WRP area A address           register */
    using wrp2ar = lp::io_register<lp::u32_t, base_address + 0x4c>;
    /* Bank 2 WRP first area A start               offset */
    using wrp2ar_wrp2a_strt = lp::assoc_bit<wrp2ar, 0, 8>;
    /* Bank 2 WRP first area A end               offset */
    using wrp2ar_wrp2a_end = lp::assoc_bit<wrp2ar, 16, 8>;


    /* Flash Bank 2 WRP area B address           register */
    using wrp2br = lp::io_register<lp::u32_t, base_address + 0x50>;
    /* Bank 2 WRP second area B start               offset */
    using wrp2br_wrp2b_strt = lp::assoc_bit<wrp2br, 0, 8>;
    /* Bank 2 WRP second area B end               offset */
    using wrp2br_wrp2b_end = lp::assoc_bit<wrp2br, 16, 8>;


};

using flash = flash_t<0x40022000>;

#endif // FLASH_HH
