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
 * Hardware support for fmc
 * @file fmc.hh
 * @author Boris Vinogradov
 */

#include <associate_bit.hh>
#include <io_register.hh>
#include <types.hh>

#ifndef FMC_HH
#define FMC_HH

/* Flexible memory controller */
template <lp::addr_t base_address>
struct fmc_t {
    /* SRAM/NOR-Flash chip-select control register           1 */
    using bcr1 = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* MBKEN */
    using bcr1_mbken = lp::assoc_bit<bcr1, 0>;
    /* MUXEN */
    using bcr1_muxen = lp::assoc_bit<bcr1, 1>;
    /* MTYP */
    using bcr1_mtyp = lp::assoc_bit<bcr1, 2, 2>;
    /* MWID */
    using bcr1_mwid = lp::assoc_bit<bcr1, 4, 2>;
    /* FACCEN */
    using bcr1_faccen = lp::assoc_bit<bcr1, 6>;
    /* BURSTEN */
    using bcr1_bursten = lp::assoc_bit<bcr1, 8>;
    /* WAITPOL */
    using bcr1_waitpol = lp::assoc_bit<bcr1, 9>;
    /* WAITCFG */
    using bcr1_waitcfg = lp::assoc_bit<bcr1, 11>;
    /* WREN */
    using bcr1_wren = lp::assoc_bit<bcr1, 12>;
    /* WAITEN */
    using bcr1_waiten = lp::assoc_bit<bcr1, 13>;
    /* EXTMOD */
    using bcr1_extmod = lp::assoc_bit<bcr1, 14>;
    /* ASYNCWAIT */
    using bcr1_asyncwait = lp::assoc_bit<bcr1, 15>;
    /* CBURSTRW */
    using bcr1_cburstrw = lp::assoc_bit<bcr1, 19>;
    /* CCLKEN */
    using bcr1_cclken = lp::assoc_bit<bcr1, 20>;
    /* Write FIFO Disable */
    using bcr1_wfdis = lp::assoc_bit<bcr1, 21>;


    /* SRAM/NOR-Flash chip-select timing register           1 */
    using btr1 = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* ACCMOD */
    using btr1_accmod = lp::assoc_bit<btr1, 28, 2>;
    /* DATLAT */
    using btr1_datlat = lp::assoc_bit<btr1, 24, 4>;
    /* CLKDIV */
    using btr1_clkdiv = lp::assoc_bit<btr1, 20, 4>;
    /* BUSTURN */
    using btr1_busturn = lp::assoc_bit<btr1, 16, 4>;
    /* DATAST */
    using btr1_datast = lp::assoc_bit<btr1, 8, 8>;
    /* ADDHLD */
    using btr1_addhld = lp::assoc_bit<btr1, 4, 4>;
    /* ADDSET */
    using btr1_addset = lp::assoc_bit<btr1, 0, 4>;


    /* SRAM/NOR-Flash chip-select control register           2 */
    using bcr2 = lp::io_register<lp::u32_t, base_address + 0x8>;
    /* CBURSTRW */
    using bcr2_cburstrw = lp::assoc_bit<bcr2, 19>;
    /* ASYNCWAIT */
    using bcr2_asyncwait = lp::assoc_bit<bcr2, 15>;
    /* EXTMOD */
    using bcr2_extmod = lp::assoc_bit<bcr2, 14>;
    /* WAITEN */
    using bcr2_waiten = lp::assoc_bit<bcr2, 13>;
    /* WREN */
    using bcr2_wren = lp::assoc_bit<bcr2, 12>;
    /* WAITCFG */
    using bcr2_waitcfg = lp::assoc_bit<bcr2, 11>;
    /* WRAPMOD */
    using bcr2_wrapmod = lp::assoc_bit<bcr2, 10>;
    /* WAITPOL */
    using bcr2_waitpol = lp::assoc_bit<bcr2, 9>;
    /* BURSTEN */
    using bcr2_bursten = lp::assoc_bit<bcr2, 8>;
    /* FACCEN */
    using bcr2_faccen = lp::assoc_bit<bcr2, 6>;
    /* MWID */
    using bcr2_mwid = lp::assoc_bit<bcr2, 4, 2>;
    /* MTYP */
    using bcr2_mtyp = lp::assoc_bit<bcr2, 2, 2>;
    /* MUXEN */
    using bcr2_muxen = lp::assoc_bit<bcr2, 1>;
    /* MBKEN */
    using bcr2_mbken = lp::assoc_bit<bcr2, 0>;


    /* SRAM/NOR-Flash chip-select timing register           2 */
    using btr2 = lp::io_register<lp::u32_t, base_address + 0xc>;
    /* ACCMOD */
    using btr2_accmod = lp::assoc_bit<btr2, 28, 2>;
    /* DATLAT */
    using btr2_datlat = lp::assoc_bit<btr2, 24, 4>;
    /* CLKDIV */
    using btr2_clkdiv = lp::assoc_bit<btr2, 20, 4>;
    /* BUSTURN */
    using btr2_busturn = lp::assoc_bit<btr2, 16, 4>;
    /* DATAST */
    using btr2_datast = lp::assoc_bit<btr2, 8, 8>;
    /* ADDHLD */
    using btr2_addhld = lp::assoc_bit<btr2, 4, 4>;
    /* ADDSET */
    using btr2_addset = lp::assoc_bit<btr2, 0, 4>;


    /* SRAM/NOR-Flash chip-select control register           3 */
    using bcr3 = lp::io_register<lp::u32_t, base_address + 0x10>;
    /* CBURSTRW */
    using bcr3_cburstrw = lp::assoc_bit<bcr3, 19>;
    /* ASYNCWAIT */
    using bcr3_asyncwait = lp::assoc_bit<bcr3, 15>;
    /* EXTMOD */
    using bcr3_extmod = lp::assoc_bit<bcr3, 14>;
    /* WAITEN */
    using bcr3_waiten = lp::assoc_bit<bcr3, 13>;
    /* WREN */
    using bcr3_wren = lp::assoc_bit<bcr3, 12>;
    /* WAITCFG */
    using bcr3_waitcfg = lp::assoc_bit<bcr3, 11>;
    /* WRAPMOD */
    using bcr3_wrapmod = lp::assoc_bit<bcr3, 10>;
    /* WAITPOL */
    using bcr3_waitpol = lp::assoc_bit<bcr3, 9>;
    /* BURSTEN */
    using bcr3_bursten = lp::assoc_bit<bcr3, 8>;
    /* FACCEN */
    using bcr3_faccen = lp::assoc_bit<bcr3, 6>;
    /* MWID */
    using bcr3_mwid = lp::assoc_bit<bcr3, 4, 2>;
    /* MTYP */
    using bcr3_mtyp = lp::assoc_bit<bcr3, 2, 2>;
    /* MUXEN */
    using bcr3_muxen = lp::assoc_bit<bcr3, 1>;
    /* MBKEN */
    using bcr3_mbken = lp::assoc_bit<bcr3, 0>;


    /* SRAM/NOR-Flash chip-select timing register           3 */
    using btr3 = lp::io_register<lp::u32_t, base_address + 0x14>;
    /* ACCMOD */
    using btr3_accmod = lp::assoc_bit<btr3, 28, 2>;
    /* DATLAT */
    using btr3_datlat = lp::assoc_bit<btr3, 24, 4>;
    /* CLKDIV */
    using btr3_clkdiv = lp::assoc_bit<btr3, 20, 4>;
    /* BUSTURN */
    using btr3_busturn = lp::assoc_bit<btr3, 16, 4>;
    /* DATAST */
    using btr3_datast = lp::assoc_bit<btr3, 8, 8>;
    /* ADDHLD */
    using btr3_addhld = lp::assoc_bit<btr3, 4, 4>;
    /* ADDSET */
    using btr3_addset = lp::assoc_bit<btr3, 0, 4>;


    /* SRAM/NOR-Flash chip-select control register           4 */
    using bcr4 = lp::io_register<lp::u32_t, base_address + 0x18>;
    /* CBURSTRW */
    using bcr4_cburstrw = lp::assoc_bit<bcr4, 19>;
    /* ASYNCWAIT */
    using bcr4_asyncwait = lp::assoc_bit<bcr4, 15>;
    /* EXTMOD */
    using bcr4_extmod = lp::assoc_bit<bcr4, 14>;
    /* WAITEN */
    using bcr4_waiten = lp::assoc_bit<bcr4, 13>;
    /* WREN */
    using bcr4_wren = lp::assoc_bit<bcr4, 12>;
    /* WAITCFG */
    using bcr4_waitcfg = lp::assoc_bit<bcr4, 11>;
    /* WRAPMOD */
    using bcr4_wrapmod = lp::assoc_bit<bcr4, 10>;
    /* WAITPOL */
    using bcr4_waitpol = lp::assoc_bit<bcr4, 9>;
    /* BURSTEN */
    using bcr4_bursten = lp::assoc_bit<bcr4, 8>;
    /* FACCEN */
    using bcr4_faccen = lp::assoc_bit<bcr4, 6>;
    /* MWID */
    using bcr4_mwid = lp::assoc_bit<bcr4, 4, 2>;
    /* MTYP */
    using bcr4_mtyp = lp::assoc_bit<bcr4, 2, 2>;
    /* MUXEN */
    using bcr4_muxen = lp::assoc_bit<bcr4, 1>;
    /* MBKEN */
    using bcr4_mbken = lp::assoc_bit<bcr4, 0>;


    /* SRAM/NOR-Flash chip-select timing register           4 */
    using btr4 = lp::io_register<lp::u32_t, base_address + 0x1c>;
    /* ACCMOD */
    using btr4_accmod = lp::assoc_bit<btr4, 28, 2>;
    /* DATLAT */
    using btr4_datlat = lp::assoc_bit<btr4, 24, 4>;
    /* CLKDIV */
    using btr4_clkdiv = lp::assoc_bit<btr4, 20, 4>;
    /* BUSTURN */
    using btr4_busturn = lp::assoc_bit<btr4, 16, 4>;
    /* DATAST */
    using btr4_datast = lp::assoc_bit<btr4, 8, 8>;
    /* ADDHLD */
    using btr4_addhld = lp::assoc_bit<btr4, 4, 4>;
    /* ADDSET */
    using btr4_addset = lp::assoc_bit<btr4, 0, 4>;


    /* PC Card/NAND Flash control register           3 */
    using pcr = lp::io_register<lp::u32_t, base_address + 0x80>;
    /* ECCPS */
    using pcr_eccps = lp::assoc_bit<pcr, 17, 3>;
    /* TAR */
    using pcr_tar = lp::assoc_bit<pcr, 13, 4>;
    /* TCLR */
    using pcr_tclr = lp::assoc_bit<pcr, 9, 4>;
    /* ECCEN */
    using pcr_eccen = lp::assoc_bit<pcr, 6>;
    /* PWID */
    using pcr_pwid = lp::assoc_bit<pcr, 4, 2>;
    /* PTYP */
    using pcr_ptyp = lp::assoc_bit<pcr, 3>;
    /* PBKEN */
    using pcr_pbken = lp::assoc_bit<pcr, 2>;
    /* PWAITEN */
    using pcr_pwaiten = lp::assoc_bit<pcr, 1>;


    /* FIFO status and interrupt register           3 */
    using sr = lp::io_register<lp::u32_t, base_address + 0x84>;
    /* FEMPT */
    using sr_fempt = lp::assoc_bit<sr, 6>;
    /* IFEN */
    using sr_ifen = lp::assoc_bit<sr, 5>;
    /* ILEN */
    using sr_ilen = lp::assoc_bit<sr, 4>;
    /* IREN */
    using sr_iren = lp::assoc_bit<sr, 3>;
    /* IFS */
    using sr_ifs = lp::assoc_bit<sr, 2>;
    /* ILS */
    using sr_ils = lp::assoc_bit<sr, 1>;
    /* IRS */
    using sr_irs = lp::assoc_bit<sr, 0>;


    /* Common memory space timing register           3 */
    using pmem = lp::io_register<lp::u32_t, base_address + 0x88>;
    /* MEMHIZx */
    using pmem_memhizx = lp::assoc_bit<pmem, 24, 8>;
    /* MEMHOLDx */
    using pmem_memholdx = lp::assoc_bit<pmem, 16, 8>;
    /* MEMWAITx */
    using pmem_memwaitx = lp::assoc_bit<pmem, 8, 8>;
    /* MEMSETx */
    using pmem_memsetx = lp::assoc_bit<pmem, 0, 8>;


    /* Attribute memory space timing register           3 */
    using patt = lp::io_register<lp::u32_t, base_address + 0x8c>;
    /* ATTHIZx */
    using patt_atthizx = lp::assoc_bit<patt, 24, 8>;
    /* ATTHOLDx */
    using patt_attholdx = lp::assoc_bit<patt, 16, 8>;
    /* ATTWAITx */
    using patt_attwaitx = lp::assoc_bit<patt, 8, 8>;
    /* ATTSETx */
    using patt_attsetx = lp::assoc_bit<patt, 0, 8>;


    /* ECC result register 3 */
    using eccr = lp::io_register<lp::u32_t, base_address + 0x94>;
    /* ECCx */
    using eccr_eccx = lp::assoc_bit<eccr, 0, 32>;


    /* SRAM/NOR-Flash write timing registers           1 */
    using bwtr1 = lp::io_register<lp::u32_t, base_address + 0x104>;
    /* ACCMOD */
    using bwtr1_accmod = lp::assoc_bit<bwtr1, 28, 2>;
    /* DATLAT */
    using bwtr1_datlat = lp::assoc_bit<bwtr1, 24, 4>;
    /* CLKDIV */
    using bwtr1_clkdiv = lp::assoc_bit<bwtr1, 20, 4>;
    /* DATAST */
    using bwtr1_datast = lp::assoc_bit<bwtr1, 8, 8>;
    /* ADDHLD */
    using bwtr1_addhld = lp::assoc_bit<bwtr1, 4, 4>;
    /* ADDSET */
    using bwtr1_addset = lp::assoc_bit<bwtr1, 0, 4>;


    /* SRAM/NOR-Flash write timing registers           2 */
    using bwtr2 = lp::io_register<lp::u32_t, base_address + 0x10c>;
    /* ACCMOD */
    using bwtr2_accmod = lp::assoc_bit<bwtr2, 28, 2>;
    /* DATLAT */
    using bwtr2_datlat = lp::assoc_bit<bwtr2, 24, 4>;
    /* CLKDIV */
    using bwtr2_clkdiv = lp::assoc_bit<bwtr2, 20, 4>;
    /* DATAST */
    using bwtr2_datast = lp::assoc_bit<bwtr2, 8, 8>;
    /* ADDHLD */
    using bwtr2_addhld = lp::assoc_bit<bwtr2, 4, 4>;
    /* ADDSET */
    using bwtr2_addset = lp::assoc_bit<bwtr2, 0, 4>;


    /* SRAM/NOR-Flash write timing registers           3 */
    using bwtr3 = lp::io_register<lp::u32_t, base_address + 0x114>;
    /* ACCMOD */
    using bwtr3_accmod = lp::assoc_bit<bwtr3, 28, 2>;
    /* DATLAT */
    using bwtr3_datlat = lp::assoc_bit<bwtr3, 24, 4>;
    /* CLKDIV */
    using bwtr3_clkdiv = lp::assoc_bit<bwtr3, 20, 4>;
    /* DATAST */
    using bwtr3_datast = lp::assoc_bit<bwtr3, 8, 8>;
    /* ADDHLD */
    using bwtr3_addhld = lp::assoc_bit<bwtr3, 4, 4>;
    /* ADDSET */
    using bwtr3_addset = lp::assoc_bit<bwtr3, 0, 4>;


    /* SRAM/NOR-Flash write timing registers           4 */
    using bwtr4 = lp::io_register<lp::u32_t, base_address + 0x11c>;
    /* ACCMOD */
    using bwtr4_accmod = lp::assoc_bit<bwtr4, 28, 2>;
    /* DATLAT */
    using bwtr4_datlat = lp::assoc_bit<bwtr4, 24, 4>;
    /* CLKDIV */
    using bwtr4_clkdiv = lp::assoc_bit<bwtr4, 20, 4>;
    /* DATAST */
    using bwtr4_datast = lp::assoc_bit<bwtr4, 8, 8>;
    /* ADDHLD */
    using bwtr4_addhld = lp::assoc_bit<bwtr4, 4, 4>;
    /* ADDSET */
    using bwtr4_addset = lp::assoc_bit<bwtr4, 0, 4>;


};

using fmc = fmc_t<0xa0000000>;

#endif // FMC_HH
