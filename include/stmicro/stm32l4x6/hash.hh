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
 * Hardware support for hash
 * @file hash.hh
 * @author Boris Vinogradov
 */

#include <associate_bit.hh>
#include <io_register.hh>
#include <types.hh>

#ifndef HASH_HH
#define HASH_HH

/* Hash processor */
template <lp::addr_t base_address>
struct hash_t {
    /* control register */
    using cr = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* Initialize message digest               calculation */
    using cr_init = lp::assoc_bit<cr, 2>;
    /* DMA enable */
    using cr_dmae = lp::assoc_bit<cr, 3>;
    /* Data type selection */
    using cr_datatype = lp::assoc_bit<cr, 4, 2>;
    /* Mode selection */
    using cr_mode = lp::assoc_bit<cr, 6>;
    /* Algorithm selection */
    using cr_algo0 = lp::assoc_bit<cr, 7>;
    /* Number of words already               pushed */
    using cr_nbw = lp::assoc_bit<cr, 8, 4>;
    /* DIN not empty */
    using cr_dinne = lp::assoc_bit<cr, 12>;
    /* Multiple DMA Transfers */
    using cr_mdmat = lp::assoc_bit<cr, 13>;
    /* Long key selection */
    using cr_lkey = lp::assoc_bit<cr, 16>;
    /* ALGO */
    using cr_algo1 = lp::assoc_bit<cr, 18>;


    /* data input register */
    using din = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* Data input */
    using din_datain = lp::assoc_bit<din, 0, 32>;


    /* start register */
    using str = lp::io_register<lp::u32_t, base_address + 0x8>;
    /* Digest calculation */
    using str_dcal = lp::assoc_bit<str, 8>;
    /* Number of valid bits in the last word of               the message */
    using str_nblw = lp::assoc_bit<str, 0, 5>;


    /* digest registers */
    using hr0 = lp::io_register<lp::u32_t, base_address + 0xc>;
    /* H0 */
    using hr0_h0 = lp::assoc_bit<hr0, 0, 32>;


    /* interrupt enable register */
    using imr = lp::io_register<lp::u32_t, base_address + 0x20>;
    /* Digest calculation completion interrupt               enable */
    using imr_dcie = lp::assoc_bit<imr, 1>;
    /* Data input interrupt               enable */
    using imr_dinie = lp::assoc_bit<imr, 0>;


    /* status register */
    using sr = lp::io_register<lp::u32_t, base_address + 0x24>;
    /* Busy bit */
    using sr_busy = lp::assoc_bit<sr, 3>;
    /* DMA Status */
    using sr_dmas = lp::assoc_bit<sr, 2>;
    /* Digest calculation completion interrupt               status */
    using sr_dcis = lp::assoc_bit<sr, 1>;
    /* Data input interrupt               status */
    using sr_dinis = lp::assoc_bit<sr, 0>;


    /* context swap registers */
    using csr0 = lp::io_register<lp::u32_t, base_address + 0xf8>;
    /* CSR0 */
    using csr0_csr0 = lp::assoc_bit<csr0, 0, 32>;


    /* context swap registers */
    using csr1 = lp::io_register<lp::u32_t, base_address + 0xfc>;
    /* CSR1 */
    using csr1_csr1 = lp::assoc_bit<csr1, 0, 32>;


    /* context swap registers */
    using csr2 = lp::io_register<lp::u32_t, base_address + 0x100>;
    /* CSR2 */
    using csr2_csr2 = lp::assoc_bit<csr2, 0, 32>;


    /* context swap registers */
    using csr3 = lp::io_register<lp::u32_t, base_address + 0x104>;
    /* CSR3 */
    using csr3_csr3 = lp::assoc_bit<csr3, 0, 32>;


    /* context swap registers */
    using csr4 = lp::io_register<lp::u32_t, base_address + 0x108>;
    /* CSR4 */
    using csr4_csr4 = lp::assoc_bit<csr4, 0, 32>;


    /* context swap registers */
    using csr5 = lp::io_register<lp::u32_t, base_address + 0x10c>;
    /* CSR5 */
    using csr5_csr5 = lp::assoc_bit<csr5, 0, 32>;


    /* context swap registers */
    using csr6 = lp::io_register<lp::u32_t, base_address + 0x110>;
    /* CSR6 */
    using csr6_csr6 = lp::assoc_bit<csr6, 0, 32>;


    /* context swap registers */
    using csr7 = lp::io_register<lp::u32_t, base_address + 0x114>;
    /* CSR7 */
    using csr7_csr7 = lp::assoc_bit<csr7, 0, 32>;


    /* context swap registers */
    using csr8 = lp::io_register<lp::u32_t, base_address + 0x118>;
    /* CSR8 */
    using csr8_csr8 = lp::assoc_bit<csr8, 0, 32>;


    /* context swap registers */
    using csr9 = lp::io_register<lp::u32_t, base_address + 0x11c>;
    /* CSR9 */
    using csr9_csr9 = lp::assoc_bit<csr9, 0, 32>;


    /* context swap registers */
    using csr10 = lp::io_register<lp::u32_t, base_address + 0x120>;
    /* CSR10 */
    using csr10_csr10 = lp::assoc_bit<csr10, 0, 32>;


    /* context swap registers */
    using csr11 = lp::io_register<lp::u32_t, base_address + 0x124>;
    /* CSR11 */
    using csr11_csr11 = lp::assoc_bit<csr11, 0, 32>;


    /* context swap registers */
    using csr12 = lp::io_register<lp::u32_t, base_address + 0x128>;
    /* CSR12 */
    using csr12_csr12 = lp::assoc_bit<csr12, 0, 32>;


    /* context swap registers */
    using csr13 = lp::io_register<lp::u32_t, base_address + 0x12c>;
    /* CSR13 */
    using csr13_csr13 = lp::assoc_bit<csr13, 0, 32>;


    /* context swap registers */
    using csr14 = lp::io_register<lp::u32_t, base_address + 0x130>;
    /* CSR14 */
    using csr14_csr14 = lp::assoc_bit<csr14, 0, 32>;


    /* context swap registers */
    using csr15 = lp::io_register<lp::u32_t, base_address + 0x134>;
    /* CSR15 */
    using csr15_csr15 = lp::assoc_bit<csr15, 0, 32>;


    /* context swap registers */
    using csr16 = lp::io_register<lp::u32_t, base_address + 0x138>;
    /* CSR16 */
    using csr16_csr16 = lp::assoc_bit<csr16, 0, 32>;


    /* context swap registers */
    using csr17 = lp::io_register<lp::u32_t, base_address + 0x13c>;
    /* CSR17 */
    using csr17_csr17 = lp::assoc_bit<csr17, 0, 32>;


    /* context swap registers */
    using csr18 = lp::io_register<lp::u32_t, base_address + 0x140>;
    /* CSR18 */
    using csr18_csr18 = lp::assoc_bit<csr18, 0, 32>;


    /* context swap registers */
    using csr19 = lp::io_register<lp::u32_t, base_address + 0x144>;
    /* CSR19 */
    using csr19_csr19 = lp::assoc_bit<csr19, 0, 32>;


    /* context swap registers */
    using csr20 = lp::io_register<lp::u32_t, base_address + 0x148>;
    /* CSR20 */
    using csr20_csr20 = lp::assoc_bit<csr20, 0, 32>;


    /* context swap registers */
    using csr21 = lp::io_register<lp::u32_t, base_address + 0x14c>;
    /* CSR21 */
    using csr21_csr21 = lp::assoc_bit<csr21, 0, 32>;


    /* context swap registers */
    using csr22 = lp::io_register<lp::u32_t, base_address + 0x150>;
    /* CSR22 */
    using csr22_csr22 = lp::assoc_bit<csr22, 0, 32>;


    /* context swap registers */
    using csr23 = lp::io_register<lp::u32_t, base_address + 0x154>;
    /* CSR23 */
    using csr23_csr23 = lp::assoc_bit<csr23, 0, 32>;


    /* context swap registers */
    using csr24 = lp::io_register<lp::u32_t, base_address + 0x158>;
    /* CSR24 */
    using csr24_csr24 = lp::assoc_bit<csr24, 0, 32>;


    /* context swap registers */
    using csr25 = lp::io_register<lp::u32_t, base_address + 0x15c>;
    /* CSR25 */
    using csr25_csr25 = lp::assoc_bit<csr25, 0, 32>;


    /* context swap registers */
    using csr26 = lp::io_register<lp::u32_t, base_address + 0x160>;
    /* CSR26 */
    using csr26_csr26 = lp::assoc_bit<csr26, 0, 32>;


    /* context swap registers */
    using csr27 = lp::io_register<lp::u32_t, base_address + 0x164>;
    /* CSR27 */
    using csr27_csr27 = lp::assoc_bit<csr27, 0, 32>;


    /* context swap registers */
    using csr28 = lp::io_register<lp::u32_t, base_address + 0x168>;
    /* CSR28 */
    using csr28_csr28 = lp::assoc_bit<csr28, 0, 32>;


    /* context swap registers */
    using csr29 = lp::io_register<lp::u32_t, base_address + 0x16c>;
    /* CSR29 */
    using csr29_csr29 = lp::assoc_bit<csr29, 0, 32>;


    /* context swap registers */
    using csr30 = lp::io_register<lp::u32_t, base_address + 0x170>;
    /* CSR30 */
    using csr30_csr30 = lp::assoc_bit<csr30, 0, 32>;


    /* context swap registers */
    using csr31 = lp::io_register<lp::u32_t, base_address + 0x174>;
    /* CSR31 */
    using csr31_csr31 = lp::assoc_bit<csr31, 0, 32>;


    /* context swap registers */
    using csr32 = lp::io_register<lp::u32_t, base_address + 0x178>;
    /* CSR32 */
    using csr32_csr32 = lp::assoc_bit<csr32, 0, 32>;


    /* context swap registers */
    using csr33 = lp::io_register<lp::u32_t, base_address + 0x17c>;
    /* CSR33 */
    using csr33_csr33 = lp::assoc_bit<csr33, 0, 32>;


    /* context swap registers */
    using csr34 = lp::io_register<lp::u32_t, base_address + 0x180>;
    /* CSR34 */
    using csr34_csr34 = lp::assoc_bit<csr34, 0, 32>;


    /* context swap registers */
    using csr35 = lp::io_register<lp::u32_t, base_address + 0x184>;
    /* CSR35 */
    using csr35_csr35 = lp::assoc_bit<csr35, 0, 32>;


    /* context swap registers */
    using csr36 = lp::io_register<lp::u32_t, base_address + 0x188>;
    /* CSR36 */
    using csr36_csr36 = lp::assoc_bit<csr36, 0, 32>;


    /* context swap registers */
    using csr37 = lp::io_register<lp::u32_t, base_address + 0x18c>;
    /* CSR37 */
    using csr37_csr37 = lp::assoc_bit<csr37, 0, 32>;


    /* context swap registers */
    using csr38 = lp::io_register<lp::u32_t, base_address + 0x190>;
    /* CSR38 */
    using csr38_csr38 = lp::assoc_bit<csr38, 0, 32>;


    /* context swap registers */
    using csr39 = lp::io_register<lp::u32_t, base_address + 0x194>;
    /* CSR39 */
    using csr39_csr39 = lp::assoc_bit<csr39, 0, 32>;


    /* context swap registers */
    using csr40 = lp::io_register<lp::u32_t, base_address + 0x198>;
    /* CSR40 */
    using csr40_csr40 = lp::assoc_bit<csr40, 0, 32>;


    /* context swap registers */
    using csr41 = lp::io_register<lp::u32_t, base_address + 0x19c>;
    /* CSR41 */
    using csr41_csr41 = lp::assoc_bit<csr41, 0, 32>;


    /* context swap registers */
    using csr42 = lp::io_register<lp::u32_t, base_address + 0x1a0>;
    /* CSR42 */
    using csr42_csr42 = lp::assoc_bit<csr42, 0, 32>;


    /* context swap registers */
    using csr43 = lp::io_register<lp::u32_t, base_address + 0x1a4>;
    /* CSR43 */
    using csr43_csr43 = lp::assoc_bit<csr43, 0, 32>;


    /* context swap registers */
    using csr44 = lp::io_register<lp::u32_t, base_address + 0x1a8>;
    /* CSR44 */
    using csr44_csr44 = lp::assoc_bit<csr44, 0, 32>;


    /* context swap registers */
    using csr45 = lp::io_register<lp::u32_t, base_address + 0x1ac>;
    /* CSR45 */
    using csr45_csr45 = lp::assoc_bit<csr45, 0, 32>;


    /* context swap registers */
    using csr46 = lp::io_register<lp::u32_t, base_address + 0x1b0>;
    /* CSR46 */
    using csr46_csr46 = lp::assoc_bit<csr46, 0, 32>;


    /* context swap registers */
    using csr47 = lp::io_register<lp::u32_t, base_address + 0x1b4>;
    /* CSR47 */
    using csr47_csr47 = lp::assoc_bit<csr47, 0, 32>;


    /* context swap registers */
    using csr48 = lp::io_register<lp::u32_t, base_address + 0x1b8>;
    /* CSR48 */
    using csr48_csr48 = lp::assoc_bit<csr48, 0, 32>;


    /* context swap registers */
    using csr49 = lp::io_register<lp::u32_t, base_address + 0x1bc>;
    /* CSR49 */
    using csr49_csr49 = lp::assoc_bit<csr49, 0, 32>;


    /* context swap registers */
    using csr50 = lp::io_register<lp::u32_t, base_address + 0x1c0>;
    /* CSR50 */
    using csr50_csr50 = lp::assoc_bit<csr50, 0, 32>;


    /* context swap registers */
    using csr51 = lp::io_register<lp::u32_t, base_address + 0x1c4>;
    /* CSR51 */
    using csr51_csr51 = lp::assoc_bit<csr51, 0, 32>;


    /* context swap registers */
    using csr52 = lp::io_register<lp::u32_t, base_address + 0x1c8>;
    /* CSR52 */
    using csr52_csr52 = lp::assoc_bit<csr52, 0, 32>;


    /* context swap registers */
    using csr53 = lp::io_register<lp::u32_t, base_address + 0x1cc>;
    /* CSR53 */
    using csr53_csr53 = lp::assoc_bit<csr53, 0, 32>;


    /* HASH digest register */
    using hash_hr0 = lp::io_register<lp::u32_t, base_address + 0x310>;
    /* H0 */
    using hash_hr0_h0 = lp::assoc_bit<hash_hr0, 0, 32>;


    /* read-only */
    using hash_hr1 = lp::io_register<lp::u32_t, base_address + 0x314>;
    /* H1 */
    using hash_hr1_h1 = lp::assoc_bit<hash_hr1, 0, 32>;


    /* read-only */
    using hash_hr2 = lp::io_register<lp::u32_t, base_address + 0x318>;
    /* H2 */
    using hash_hr2_h2 = lp::assoc_bit<hash_hr2, 0, 32>;


    /* read-only */
    using hash_hr3 = lp::io_register<lp::u32_t, base_address + 0x31c>;
    /* H3 */
    using hash_hr3_h3 = lp::assoc_bit<hash_hr3, 0, 32>;


    /* read-only */
    using hash_hr4 = lp::io_register<lp::u32_t, base_address + 0x320>;
    /* H4 */
    using hash_hr4_h4 = lp::assoc_bit<hash_hr4, 0, 32>;


    /* read-only */
    using hash_hr5 = lp::io_register<lp::u32_t, base_address + 0x324>;
    /* H5 */
    using hash_hr5_h5 = lp::assoc_bit<hash_hr5, 0, 32>;


    /* read-only */
    using hash_hr6 = lp::io_register<lp::u32_t, base_address + 0x328>;
    /* H6 */
    using hash_hr6_h6 = lp::assoc_bit<hash_hr6, 0, 32>;


    /* read-only */
    using hash_hr7 = lp::io_register<lp::u32_t, base_address + 0x32c>;
    /* H7 */
    using hash_hr7_h7 = lp::assoc_bit<hash_hr7, 0, 32>;


};

using hash = hash_t<0x50060400>;

#endif // HASH_HH
