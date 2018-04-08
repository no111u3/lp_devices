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
 * Hardware support for can
 * @file can.hh
 * @author Boris Vinogradov
 */

#include <associate_bit.hh>
#include <io_register.hh>
#include <types.hh>

#ifndef CAN_HH
#define CAN_HH

/* Controller area network */
template <lp::addr_t base_address>
struct can_t {
    /* master control register */
    using mcr = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* DBF */
    using mcr_dbf = lp::assoc_bit<mcr, 16>;
    /* RESET */
    using mcr_reset = lp::assoc_bit<mcr, 15>;
    /* TTCM */
    using mcr_ttcm = lp::assoc_bit<mcr, 7>;
    /* ABOM */
    using mcr_abom = lp::assoc_bit<mcr, 6>;
    /* AWUM */
    using mcr_awum = lp::assoc_bit<mcr, 5>;
    /* NART */
    using mcr_nart = lp::assoc_bit<mcr, 4>;
    /* RFLM */
    using mcr_rflm = lp::assoc_bit<mcr, 3>;
    /* TXFP */
    using mcr_txfp = lp::assoc_bit<mcr, 2>;
    /* SLEEP */
    using mcr_sleep = lp::assoc_bit<mcr, 1>;
    /* INRQ */
    using mcr_inrq = lp::assoc_bit<mcr, 0>;


    /* master status register */
    using msr = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* RX */
    using msr_rx = lp::assoc_bit<msr, 11>;
    /* SAMP */
    using msr_samp = lp::assoc_bit<msr, 10>;
    /* RXM */
    using msr_rxm = lp::assoc_bit<msr, 9>;
    /* TXM */
    using msr_txm = lp::assoc_bit<msr, 8>;
    /* SLAKI */
    using msr_slaki = lp::assoc_bit<msr, 4>;
    /* WKUI */
    using msr_wkui = lp::assoc_bit<msr, 3>;
    /* ERRI */
    using msr_erri = lp::assoc_bit<msr, 2>;
    /* SLAK */
    using msr_slak = lp::assoc_bit<msr, 1>;
    /* INAK */
    using msr_inak = lp::assoc_bit<msr, 0>;


    /* transmit status register */
    using tsr = lp::io_register<lp::u32_t, base_address + 0x8>;
    /* Lowest priority flag for mailbox               2 */
    using tsr_low2 = lp::assoc_bit<tsr, 31>;
    /* Lowest priority flag for mailbox               1 */
    using tsr_low1 = lp::assoc_bit<tsr, 30>;
    /* Lowest priority flag for mailbox               0 */
    using tsr_low0 = lp::assoc_bit<tsr, 29>;
    /* Lowest priority flag for mailbox               2 */
    using tsr_tme2 = lp::assoc_bit<tsr, 28>;
    /* Lowest priority flag for mailbox               1 */
    using tsr_tme1 = lp::assoc_bit<tsr, 27>;
    /* Lowest priority flag for mailbox               0 */
    using tsr_tme0 = lp::assoc_bit<tsr, 26>;
    /* CODE */
    using tsr_code = lp::assoc_bit<tsr, 24, 2>;
    /* ABRQ2 */
    using tsr_abrq2 = lp::assoc_bit<tsr, 23>;
    /* TERR2 */
    using tsr_terr2 = lp::assoc_bit<tsr, 19>;
    /* ALST2 */
    using tsr_alst2 = lp::assoc_bit<tsr, 18>;
    /* TXOK2 */
    using tsr_txok2 = lp::assoc_bit<tsr, 17>;
    /* RQCP2 */
    using tsr_rqcp2 = lp::assoc_bit<tsr, 16>;
    /* ABRQ1 */
    using tsr_abrq1 = lp::assoc_bit<tsr, 15>;
    /* TERR1 */
    using tsr_terr1 = lp::assoc_bit<tsr, 11>;
    /* ALST1 */
    using tsr_alst1 = lp::assoc_bit<tsr, 10>;
    /* TXOK1 */
    using tsr_txok1 = lp::assoc_bit<tsr, 9>;
    /* RQCP1 */
    using tsr_rqcp1 = lp::assoc_bit<tsr, 8>;
    /* ABRQ0 */
    using tsr_abrq0 = lp::assoc_bit<tsr, 7>;
    /* TERR0 */
    using tsr_terr0 = lp::assoc_bit<tsr, 3>;
    /* ALST0 */
    using tsr_alst0 = lp::assoc_bit<tsr, 2>;
    /* TXOK0 */
    using tsr_txok0 = lp::assoc_bit<tsr, 1>;
    /* RQCP0 */
    using tsr_rqcp0 = lp::assoc_bit<tsr, 0>;


    /* receive FIFO 0 register */
    using rf0r = lp::io_register<lp::u32_t, base_address + 0xc>;
    /* RFOM0 */
    using rf0r_rfom0 = lp::assoc_bit<rf0r, 5>;
    /* FOVR0 */
    using rf0r_fovr0 = lp::assoc_bit<rf0r, 4>;
    /* FULL0 */
    using rf0r_full0 = lp::assoc_bit<rf0r, 3>;
    /* FMP0 */
    using rf0r_fmp0 = lp::assoc_bit<rf0r, 0, 2>;


    /* receive FIFO 1 register */
    using rf1r = lp::io_register<lp::u32_t, base_address + 0x10>;
    /* RFOM1 */
    using rf1r_rfom1 = lp::assoc_bit<rf1r, 5>;
    /* FOVR1 */
    using rf1r_fovr1 = lp::assoc_bit<rf1r, 4>;
    /* FULL1 */
    using rf1r_full1 = lp::assoc_bit<rf1r, 3>;
    /* FMP1 */
    using rf1r_fmp1 = lp::assoc_bit<rf1r, 0, 2>;


    /* interrupt enable register */
    using ier = lp::io_register<lp::u32_t, base_address + 0x14>;
    /* SLKIE */
    using ier_slkie = lp::assoc_bit<ier, 17>;
    /* WKUIE */
    using ier_wkuie = lp::assoc_bit<ier, 16>;
    /* ERRIE */
    using ier_errie = lp::assoc_bit<ier, 15>;
    /* LECIE */
    using ier_lecie = lp::assoc_bit<ier, 11>;
    /* BOFIE */
    using ier_bofie = lp::assoc_bit<ier, 10>;
    /* EPVIE */
    using ier_epvie = lp::assoc_bit<ier, 9>;
    /* EWGIE */
    using ier_ewgie = lp::assoc_bit<ier, 8>;
    /* FOVIE1 */
    using ier_fovie1 = lp::assoc_bit<ier, 6>;
    /* FFIE1 */
    using ier_ffie1 = lp::assoc_bit<ier, 5>;
    /* FMPIE1 */
    using ier_fmpie1 = lp::assoc_bit<ier, 4>;
    /* FOVIE0 */
    using ier_fovie0 = lp::assoc_bit<ier, 3>;
    /* FFIE0 */
    using ier_ffie0 = lp::assoc_bit<ier, 2>;
    /* FMPIE0 */
    using ier_fmpie0 = lp::assoc_bit<ier, 1>;
    /* TMEIE */
    using ier_tmeie = lp::assoc_bit<ier, 0>;


    /* interrupt enable register */
    using esr = lp::io_register<lp::u32_t, base_address + 0x18>;
    /* REC */
    using esr_rec = lp::assoc_bit<esr, 24, 8>;
    /* TEC */
    using esr_tec = lp::assoc_bit<esr, 16, 8>;
    /* LEC */
    using esr_lec = lp::assoc_bit<esr, 4, 3>;
    /* BOFF */
    using esr_boff = lp::assoc_bit<esr, 2>;
    /* EPVF */
    using esr_epvf = lp::assoc_bit<esr, 1>;
    /* EWGF */
    using esr_ewgf = lp::assoc_bit<esr, 0>;


    /* bit timing register */
    using btr = lp::io_register<lp::u32_t, base_address + 0x1c>;
    /* SILM */
    using btr_silm = lp::assoc_bit<btr, 31>;
    /* LBKM */
    using btr_lbkm = lp::assoc_bit<btr, 30>;
    /* SJW */
    using btr_sjw = lp::assoc_bit<btr, 24, 2>;
    /* TS2 */
    using btr_ts2 = lp::assoc_bit<btr, 20, 3>;
    /* TS1 */
    using btr_ts1 = lp::assoc_bit<btr, 16, 4>;
    /* BRP */
    using btr_brp = lp::assoc_bit<btr, 0, 10>;


    /* TX mailbox identifier register */
    using ti0r = lp::io_register<lp::u32_t, base_address + 0x180>;
    /* STID */
    using ti0r_stid = lp::assoc_bit<ti0r, 21, 11>;
    /* EXID */
    using ti0r_exid = lp::assoc_bit<ti0r, 3, 18>;
    /* IDE */
    using ti0r_ide = lp::assoc_bit<ti0r, 2>;
    /* RTR */
    using ti0r_rtr = lp::assoc_bit<ti0r, 1>;
    /* TXRQ */
    using ti0r_txrq = lp::assoc_bit<ti0r, 0>;


    /* mailbox data length control and time stamp           register */
    using tdt0r = lp::io_register<lp::u32_t, base_address + 0x184>;
    /* TIME */
    using tdt0r_time = lp::assoc_bit<tdt0r, 16, 16>;
    /* TGT */
    using tdt0r_tgt = lp::assoc_bit<tdt0r, 8>;
    /* DLC */
    using tdt0r_dlc = lp::assoc_bit<tdt0r, 0, 4>;


    /* mailbox data low register */
    using tdl0r = lp::io_register<lp::u32_t, base_address + 0x188>;
    /* DATA3 */
    using tdl0r_data3 = lp::assoc_bit<tdl0r, 24, 8>;
    /* DATA2 */
    using tdl0r_data2 = lp::assoc_bit<tdl0r, 16, 8>;
    /* DATA1 */
    using tdl0r_data1 = lp::assoc_bit<tdl0r, 8, 8>;
    /* DATA0 */
    using tdl0r_data0 = lp::assoc_bit<tdl0r, 0, 8>;


    /* mailbox data high register */
    using tdh0r = lp::io_register<lp::u32_t, base_address + 0x18c>;
    /* DATA7 */
    using tdh0r_data7 = lp::assoc_bit<tdh0r, 24, 8>;
    /* DATA6 */
    using tdh0r_data6 = lp::assoc_bit<tdh0r, 16, 8>;
    /* DATA5 */
    using tdh0r_data5 = lp::assoc_bit<tdh0r, 8, 8>;
    /* DATA4 */
    using tdh0r_data4 = lp::assoc_bit<tdh0r, 0, 8>;


    /* mailbox identifier register */
    using ti1r = lp::io_register<lp::u32_t, base_address + 0x190>;
    /* STID */
    using ti1r_stid = lp::assoc_bit<ti1r, 21, 11>;
    /* EXID */
    using ti1r_exid = lp::assoc_bit<ti1r, 3, 18>;
    /* IDE */
    using ti1r_ide = lp::assoc_bit<ti1r, 2>;
    /* RTR */
    using ti1r_rtr = lp::assoc_bit<ti1r, 1>;
    /* TXRQ */
    using ti1r_txrq = lp::assoc_bit<ti1r, 0>;


    /* mailbox data length control and time stamp           register */
    using tdt1r = lp::io_register<lp::u32_t, base_address + 0x194>;
    /* TIME */
    using tdt1r_time = lp::assoc_bit<tdt1r, 16, 16>;
    /* TGT */
    using tdt1r_tgt = lp::assoc_bit<tdt1r, 8>;
    /* DLC */
    using tdt1r_dlc = lp::assoc_bit<tdt1r, 0, 4>;


    /* mailbox data low register */
    using tdl1r = lp::io_register<lp::u32_t, base_address + 0x198>;
    /* DATA3 */
    using tdl1r_data3 = lp::assoc_bit<tdl1r, 24, 8>;
    /* DATA2 */
    using tdl1r_data2 = lp::assoc_bit<tdl1r, 16, 8>;
    /* DATA1 */
    using tdl1r_data1 = lp::assoc_bit<tdl1r, 8, 8>;
    /* DATA0 */
    using tdl1r_data0 = lp::assoc_bit<tdl1r, 0, 8>;


    /* mailbox data high register */
    using tdh1r = lp::io_register<lp::u32_t, base_address + 0x19c>;
    /* DATA7 */
    using tdh1r_data7 = lp::assoc_bit<tdh1r, 24, 8>;
    /* DATA6 */
    using tdh1r_data6 = lp::assoc_bit<tdh1r, 16, 8>;
    /* DATA5 */
    using tdh1r_data5 = lp::assoc_bit<tdh1r, 8, 8>;
    /* DATA4 */
    using tdh1r_data4 = lp::assoc_bit<tdh1r, 0, 8>;


    /* mailbox identifier register */
    using ti2r = lp::io_register<lp::u32_t, base_address + 0x1a0>;
    /* STID */
    using ti2r_stid = lp::assoc_bit<ti2r, 21, 11>;
    /* EXID */
    using ti2r_exid = lp::assoc_bit<ti2r, 3, 18>;
    /* IDE */
    using ti2r_ide = lp::assoc_bit<ti2r, 2>;
    /* RTR */
    using ti2r_rtr = lp::assoc_bit<ti2r, 1>;
    /* TXRQ */
    using ti2r_txrq = lp::assoc_bit<ti2r, 0>;


    /* mailbox data length control and time stamp           register */
    using tdt2r = lp::io_register<lp::u32_t, base_address + 0x1a4>;
    /* TIME */
    using tdt2r_time = lp::assoc_bit<tdt2r, 16, 16>;
    /* TGT */
    using tdt2r_tgt = lp::assoc_bit<tdt2r, 8>;
    /* DLC */
    using tdt2r_dlc = lp::assoc_bit<tdt2r, 0, 4>;


    /* mailbox data low register */
    using tdl2r = lp::io_register<lp::u32_t, base_address + 0x1a8>;
    /* DATA3 */
    using tdl2r_data3 = lp::assoc_bit<tdl2r, 24, 8>;
    /* DATA2 */
    using tdl2r_data2 = lp::assoc_bit<tdl2r, 16, 8>;
    /* DATA1 */
    using tdl2r_data1 = lp::assoc_bit<tdl2r, 8, 8>;
    /* DATA0 */
    using tdl2r_data0 = lp::assoc_bit<tdl2r, 0, 8>;


    /* mailbox data high register */
    using tdh2r = lp::io_register<lp::u32_t, base_address + 0x1ac>;
    /* DATA7 */
    using tdh2r_data7 = lp::assoc_bit<tdh2r, 24, 8>;
    /* DATA6 */
    using tdh2r_data6 = lp::assoc_bit<tdh2r, 16, 8>;
    /* DATA5 */
    using tdh2r_data5 = lp::assoc_bit<tdh2r, 8, 8>;
    /* DATA4 */
    using tdh2r_data4 = lp::assoc_bit<tdh2r, 0, 8>;


    /* receive FIFO mailbox identifier           register */
    using ri0r = lp::io_register<lp::u32_t, base_address + 0x1b0>;
    /* STID */
    using ri0r_stid = lp::assoc_bit<ri0r, 21, 11>;
    /* EXID */
    using ri0r_exid = lp::assoc_bit<ri0r, 3, 18>;
    /* IDE */
    using ri0r_ide = lp::assoc_bit<ri0r, 2>;
    /* RTR */
    using ri0r_rtr = lp::assoc_bit<ri0r, 1>;


    /* mailbox data high register */
    using rdt0r = lp::io_register<lp::u32_t, base_address + 0x1b4>;
    /* TIME */
    using rdt0r_time = lp::assoc_bit<rdt0r, 16, 16>;
    /* FMI */
    using rdt0r_fmi = lp::assoc_bit<rdt0r, 8, 8>;
    /* DLC */
    using rdt0r_dlc = lp::assoc_bit<rdt0r, 0, 4>;


    /* mailbox data high register */
    using rdl0r = lp::io_register<lp::u32_t, base_address + 0x1b8>;
    /* DATA3 */
    using rdl0r_data3 = lp::assoc_bit<rdl0r, 24, 8>;
    /* DATA2 */
    using rdl0r_data2 = lp::assoc_bit<rdl0r, 16, 8>;
    /* DATA1 */
    using rdl0r_data1 = lp::assoc_bit<rdl0r, 8, 8>;
    /* DATA0 */
    using rdl0r_data0 = lp::assoc_bit<rdl0r, 0, 8>;


    /* receive FIFO mailbox data high           register */
    using rdh0r = lp::io_register<lp::u32_t, base_address + 0x1bc>;
    /* DATA7 */
    using rdh0r_data7 = lp::assoc_bit<rdh0r, 24, 8>;
    /* DATA6 */
    using rdh0r_data6 = lp::assoc_bit<rdh0r, 16, 8>;
    /* DATA5 */
    using rdh0r_data5 = lp::assoc_bit<rdh0r, 8, 8>;
    /* DATA4 */
    using rdh0r_data4 = lp::assoc_bit<rdh0r, 0, 8>;


    /* mailbox data high register */
    using ri1r = lp::io_register<lp::u32_t, base_address + 0x1c0>;
    /* STID */
    using ri1r_stid = lp::assoc_bit<ri1r, 21, 11>;
    /* EXID */
    using ri1r_exid = lp::assoc_bit<ri1r, 3, 18>;
    /* IDE */
    using ri1r_ide = lp::assoc_bit<ri1r, 2>;
    /* RTR */
    using ri1r_rtr = lp::assoc_bit<ri1r, 1>;


    /* mailbox data high register */
    using rdt1r = lp::io_register<lp::u32_t, base_address + 0x1c4>;
    /* TIME */
    using rdt1r_time = lp::assoc_bit<rdt1r, 16, 16>;
    /* FMI */
    using rdt1r_fmi = lp::assoc_bit<rdt1r, 8, 8>;
    /* DLC */
    using rdt1r_dlc = lp::assoc_bit<rdt1r, 0, 4>;


    /* mailbox data high register */
    using rdl1r = lp::io_register<lp::u32_t, base_address + 0x1c8>;
    /* DATA3 */
    using rdl1r_data3 = lp::assoc_bit<rdl1r, 24, 8>;
    /* DATA2 */
    using rdl1r_data2 = lp::assoc_bit<rdl1r, 16, 8>;
    /* DATA1 */
    using rdl1r_data1 = lp::assoc_bit<rdl1r, 8, 8>;
    /* DATA0 */
    using rdl1r_data0 = lp::assoc_bit<rdl1r, 0, 8>;


    /* mailbox data high register */
    using rdh1r = lp::io_register<lp::u32_t, base_address + 0x1cc>;
    /* DATA7 */
    using rdh1r_data7 = lp::assoc_bit<rdh1r, 24, 8>;
    /* DATA6 */
    using rdh1r_data6 = lp::assoc_bit<rdh1r, 16, 8>;
    /* DATA5 */
    using rdh1r_data5 = lp::assoc_bit<rdh1r, 8, 8>;
    /* DATA4 */
    using rdh1r_data4 = lp::assoc_bit<rdh1r, 0, 8>;


    /* filter master register */
    using fmr = lp::io_register<lp::u32_t, base_address + 0x200>;
    /* Filter initialization mode */
    using fmr_finit = lp::assoc_bit<fmr, 0>;
    /* CAN start bank */
    using fmr_cansb = lp::assoc_bit<fmr, 8, 6>;


    /* filter mode register */
    using fm1r = lp::io_register<lp::u32_t, base_address + 0x204>;
    /* Filter mode */
    using fm1r_fbm0 = lp::assoc_bit<fm1r, 0>;
    /* Filter mode */
    using fm1r_fbm1 = lp::assoc_bit<fm1r, 1>;
    /* Filter mode */
    using fm1r_fbm2 = lp::assoc_bit<fm1r, 2>;
    /* Filter mode */
    using fm1r_fbm3 = lp::assoc_bit<fm1r, 3>;
    /* Filter mode */
    using fm1r_fbm4 = lp::assoc_bit<fm1r, 4>;
    /* Filter mode */
    using fm1r_fbm5 = lp::assoc_bit<fm1r, 5>;
    /* Filter mode */
    using fm1r_fbm6 = lp::assoc_bit<fm1r, 6>;
    /* Filter mode */
    using fm1r_fbm7 = lp::assoc_bit<fm1r, 7>;
    /* Filter mode */
    using fm1r_fbm8 = lp::assoc_bit<fm1r, 8>;
    /* Filter mode */
    using fm1r_fbm9 = lp::assoc_bit<fm1r, 9>;
    /* Filter mode */
    using fm1r_fbm10 = lp::assoc_bit<fm1r, 10>;
    /* Filter mode */
    using fm1r_fbm11 = lp::assoc_bit<fm1r, 11>;
    /* Filter mode */
    using fm1r_fbm12 = lp::assoc_bit<fm1r, 12>;
    /* Filter mode */
    using fm1r_fbm13 = lp::assoc_bit<fm1r, 13>;
    /* Filter mode */
    using fm1r_fbm14 = lp::assoc_bit<fm1r, 14>;
    /* Filter mode */
    using fm1r_fbm15 = lp::assoc_bit<fm1r, 15>;
    /* Filter mode */
    using fm1r_fbm16 = lp::assoc_bit<fm1r, 16>;
    /* Filter mode */
    using fm1r_fbm17 = lp::assoc_bit<fm1r, 17>;
    /* Filter mode */
    using fm1r_fbm18 = lp::assoc_bit<fm1r, 18>;
    /* Filter mode */
    using fm1r_fbm19 = lp::assoc_bit<fm1r, 19>;
    /* Filter mode */
    using fm1r_fbm20 = lp::assoc_bit<fm1r, 20>;
    /* Filter mode */
    using fm1r_fbm21 = lp::assoc_bit<fm1r, 21>;
    /* Filter mode */
    using fm1r_fbm22 = lp::assoc_bit<fm1r, 22>;
    /* Filter mode */
    using fm1r_fbm23 = lp::assoc_bit<fm1r, 23>;
    /* Filter mode */
    using fm1r_fbm24 = lp::assoc_bit<fm1r, 24>;
    /* Filter mode */
    using fm1r_fbm25 = lp::assoc_bit<fm1r, 25>;
    /* Filter mode */
    using fm1r_fbm26 = lp::assoc_bit<fm1r, 26>;
    /* Filter mode */
    using fm1r_fbm27 = lp::assoc_bit<fm1r, 27>;


    /* filter scale register */
    using fs1r = lp::io_register<lp::u32_t, base_address + 0x20c>;
    /* Filter scale configuration */
    using fs1r_fsc0 = lp::assoc_bit<fs1r, 0>;
    /* Filter scale configuration */
    using fs1r_fsc1 = lp::assoc_bit<fs1r, 1>;
    /* Filter scale configuration */
    using fs1r_fsc2 = lp::assoc_bit<fs1r, 2>;
    /* Filter scale configuration */
    using fs1r_fsc3 = lp::assoc_bit<fs1r, 3>;
    /* Filter scale configuration */
    using fs1r_fsc4 = lp::assoc_bit<fs1r, 4>;
    /* Filter scale configuration */
    using fs1r_fsc5 = lp::assoc_bit<fs1r, 5>;
    /* Filter scale configuration */
    using fs1r_fsc6 = lp::assoc_bit<fs1r, 6>;
    /* Filter scale configuration */
    using fs1r_fsc7 = lp::assoc_bit<fs1r, 7>;
    /* Filter scale configuration */
    using fs1r_fsc8 = lp::assoc_bit<fs1r, 8>;
    /* Filter scale configuration */
    using fs1r_fsc9 = lp::assoc_bit<fs1r, 9>;
    /* Filter scale configuration */
    using fs1r_fsc10 = lp::assoc_bit<fs1r, 10>;
    /* Filter scale configuration */
    using fs1r_fsc11 = lp::assoc_bit<fs1r, 11>;
    /* Filter scale configuration */
    using fs1r_fsc12 = lp::assoc_bit<fs1r, 12>;
    /* Filter scale configuration */
    using fs1r_fsc13 = lp::assoc_bit<fs1r, 13>;
    /* Filter scale configuration */
    using fs1r_fsc14 = lp::assoc_bit<fs1r, 14>;
    /* Filter scale configuration */
    using fs1r_fsc15 = lp::assoc_bit<fs1r, 15>;
    /* Filter scale configuration */
    using fs1r_fsc16 = lp::assoc_bit<fs1r, 16>;
    /* Filter scale configuration */
    using fs1r_fsc17 = lp::assoc_bit<fs1r, 17>;
    /* Filter scale configuration */
    using fs1r_fsc18 = lp::assoc_bit<fs1r, 18>;
    /* Filter scale configuration */
    using fs1r_fsc19 = lp::assoc_bit<fs1r, 19>;
    /* Filter scale configuration */
    using fs1r_fsc20 = lp::assoc_bit<fs1r, 20>;
    /* Filter scale configuration */
    using fs1r_fsc21 = lp::assoc_bit<fs1r, 21>;
    /* Filter scale configuration */
    using fs1r_fsc22 = lp::assoc_bit<fs1r, 22>;
    /* Filter scale configuration */
    using fs1r_fsc23 = lp::assoc_bit<fs1r, 23>;
    /* Filter scale configuration */
    using fs1r_fsc24 = lp::assoc_bit<fs1r, 24>;
    /* Filter scale configuration */
    using fs1r_fsc25 = lp::assoc_bit<fs1r, 25>;
    /* Filter scale configuration */
    using fs1r_fsc26 = lp::assoc_bit<fs1r, 26>;
    /* Filter scale configuration */
    using fs1r_fsc27 = lp::assoc_bit<fs1r, 27>;


    /* filter FIFO assignment           register */
    using ffa1r = lp::io_register<lp::u32_t, base_address + 0x214>;
    /* Filter FIFO assignment for filter               0 */
    using ffa1r_ffa0 = lp::assoc_bit<ffa1r, 0>;
    /* Filter FIFO assignment for filter               1 */
    using ffa1r_ffa1 = lp::assoc_bit<ffa1r, 1>;
    /* Filter FIFO assignment for filter               2 */
    using ffa1r_ffa2 = lp::assoc_bit<ffa1r, 2>;
    /* Filter FIFO assignment for filter               3 */
    using ffa1r_ffa3 = lp::assoc_bit<ffa1r, 3>;
    /* Filter FIFO assignment for filter               4 */
    using ffa1r_ffa4 = lp::assoc_bit<ffa1r, 4>;
    /* Filter FIFO assignment for filter               5 */
    using ffa1r_ffa5 = lp::assoc_bit<ffa1r, 5>;
    /* Filter FIFO assignment for filter               6 */
    using ffa1r_ffa6 = lp::assoc_bit<ffa1r, 6>;
    /* Filter FIFO assignment for filter               7 */
    using ffa1r_ffa7 = lp::assoc_bit<ffa1r, 7>;
    /* Filter FIFO assignment for filter               8 */
    using ffa1r_ffa8 = lp::assoc_bit<ffa1r, 8>;
    /* Filter FIFO assignment for filter               9 */
    using ffa1r_ffa9 = lp::assoc_bit<ffa1r, 9>;
    /* Filter FIFO assignment for filter               10 */
    using ffa1r_ffa10 = lp::assoc_bit<ffa1r, 10>;
    /* Filter FIFO assignment for filter               11 */
    using ffa1r_ffa11 = lp::assoc_bit<ffa1r, 11>;
    /* Filter FIFO assignment for filter               12 */
    using ffa1r_ffa12 = lp::assoc_bit<ffa1r, 12>;
    /* Filter FIFO assignment for filter               13 */
    using ffa1r_ffa13 = lp::assoc_bit<ffa1r, 13>;
    /* Filter FIFO assignment for               filter */
    using ffa1r_ffa14 = lp::assoc_bit<ffa1r, 14>;
    /* Filter FIFO assignment for               filter */
    using ffa1r_ffa15 = lp::assoc_bit<ffa1r, 15>;
    /* Filter FIFO assignment for               filter */
    using ffa1r_ffa16 = lp::assoc_bit<ffa1r, 16>;
    /* Filter FIFO assignment for               filter */
    using ffa1r_ffa17 = lp::assoc_bit<ffa1r, 17>;
    /* Filter FIFO assignment for               filter */
    using ffa1r_ffa18 = lp::assoc_bit<ffa1r, 18>;
    /* Filter FIFO assignment for               filter */
    using ffa1r_ffa19 = lp::assoc_bit<ffa1r, 19>;
    /* Filter FIFO assignment for               filter */
    using ffa1r_ffa20 = lp::assoc_bit<ffa1r, 20>;
    /* Filter FIFO assignment for               filter */
    using ffa1r_ffa21 = lp::assoc_bit<ffa1r, 21>;
    /* Filter FIFO assignment for               filter */
    using ffa1r_ffa22 = lp::assoc_bit<ffa1r, 22>;
    /* Filter FIFO assignment for               filter */
    using ffa1r_ffa23 = lp::assoc_bit<ffa1r, 23>;
    /* Filter FIFO assignment for               filter */
    using ffa1r_ffa24 = lp::assoc_bit<ffa1r, 24>;
    /* Filter FIFO assignment for               filter */
    using ffa1r_ffa25 = lp::assoc_bit<ffa1r, 25>;
    /* Filter FIFO assignment for               filter */
    using ffa1r_ffa26 = lp::assoc_bit<ffa1r, 26>;
    /* Filter FIFO assignment for               filter */
    using ffa1r_ffa27 = lp::assoc_bit<ffa1r, 27>;


    /* filter activation register */
    using fa1r = lp::io_register<lp::u32_t, base_address + 0x21c>;
    /* Filter active */
    using fa1r_fact0 = lp::assoc_bit<fa1r, 0>;
    /* Filter active */
    using fa1r_fact1 = lp::assoc_bit<fa1r, 1>;
    /* Filter active */
    using fa1r_fact2 = lp::assoc_bit<fa1r, 2>;
    /* Filter active */
    using fa1r_fact3 = lp::assoc_bit<fa1r, 3>;
    /* Filter active */
    using fa1r_fact4 = lp::assoc_bit<fa1r, 4>;
    /* Filter active */
    using fa1r_fact5 = lp::assoc_bit<fa1r, 5>;
    /* Filter active */
    using fa1r_fact6 = lp::assoc_bit<fa1r, 6>;
    /* Filter active */
    using fa1r_fact7 = lp::assoc_bit<fa1r, 7>;
    /* Filter active */
    using fa1r_fact8 = lp::assoc_bit<fa1r, 8>;
    /* Filter active */
    using fa1r_fact9 = lp::assoc_bit<fa1r, 9>;
    /* Filter active */
    using fa1r_fact10 = lp::assoc_bit<fa1r, 10>;
    /* Filter active */
    using fa1r_fact11 = lp::assoc_bit<fa1r, 11>;
    /* Filter active */
    using fa1r_fact12 = lp::assoc_bit<fa1r, 12>;
    /* Filter active */
    using fa1r_fact13 = lp::assoc_bit<fa1r, 13>;
    /* Filter active */
    using fa1r_fact14 = lp::assoc_bit<fa1r, 14>;
    /* Filter active */
    using fa1r_fact15 = lp::assoc_bit<fa1r, 15>;
    /* Filter active */
    using fa1r_fact16 = lp::assoc_bit<fa1r, 16>;
    /* Filter active */
    using fa1r_fact17 = lp::assoc_bit<fa1r, 17>;
    /* Filter active */
    using fa1r_fact18 = lp::assoc_bit<fa1r, 18>;
    /* Filter active */
    using fa1r_fact19 = lp::assoc_bit<fa1r, 19>;
    /* Filter active */
    using fa1r_fact20 = lp::assoc_bit<fa1r, 20>;
    /* Filter active */
    using fa1r_fact21 = lp::assoc_bit<fa1r, 21>;
    /* Filter active */
    using fa1r_fact22 = lp::assoc_bit<fa1r, 22>;
    /* Filter active */
    using fa1r_fact23 = lp::assoc_bit<fa1r, 23>;
    /* Filter active */
    using fa1r_fact24 = lp::assoc_bit<fa1r, 24>;
    /* Filter active */
    using fa1r_fact25 = lp::assoc_bit<fa1r, 25>;
    /* Filter active */
    using fa1r_fact26 = lp::assoc_bit<fa1r, 26>;
    /* Filter active */
    using fa1r_fact27 = lp::assoc_bit<fa1r, 27>;


    /* Filter bank 0 register 1 */
    using f0r1 = lp::io_register<lp::u32_t, base_address + 0x240>;
    /* Filter bits */
    using f0r1_fb0 = lp::assoc_bit<f0r1, 0>;
    /* Filter bits */
    using f0r1_fb1 = lp::assoc_bit<f0r1, 1>;
    /* Filter bits */
    using f0r1_fb2 = lp::assoc_bit<f0r1, 2>;
    /* Filter bits */
    using f0r1_fb3 = lp::assoc_bit<f0r1, 3>;
    /* Filter bits */
    using f0r1_fb4 = lp::assoc_bit<f0r1, 4>;
    /* Filter bits */
    using f0r1_fb5 = lp::assoc_bit<f0r1, 5>;
    /* Filter bits */
    using f0r1_fb6 = lp::assoc_bit<f0r1, 6>;
    /* Filter bits */
    using f0r1_fb7 = lp::assoc_bit<f0r1, 7>;
    /* Filter bits */
    using f0r1_fb8 = lp::assoc_bit<f0r1, 8>;
    /* Filter bits */
    using f0r1_fb9 = lp::assoc_bit<f0r1, 9>;
    /* Filter bits */
    using f0r1_fb10 = lp::assoc_bit<f0r1, 10>;
    /* Filter bits */
    using f0r1_fb11 = lp::assoc_bit<f0r1, 11>;
    /* Filter bits */
    using f0r1_fb12 = lp::assoc_bit<f0r1, 12>;
    /* Filter bits */
    using f0r1_fb13 = lp::assoc_bit<f0r1, 13>;
    /* Filter bits */
    using f0r1_fb14 = lp::assoc_bit<f0r1, 14>;
    /* Filter bits */
    using f0r1_fb15 = lp::assoc_bit<f0r1, 15>;
    /* Filter bits */
    using f0r1_fb16 = lp::assoc_bit<f0r1, 16>;
    /* Filter bits */
    using f0r1_fb17 = lp::assoc_bit<f0r1, 17>;
    /* Filter bits */
    using f0r1_fb18 = lp::assoc_bit<f0r1, 18>;
    /* Filter bits */
    using f0r1_fb19 = lp::assoc_bit<f0r1, 19>;
    /* Filter bits */
    using f0r1_fb20 = lp::assoc_bit<f0r1, 20>;
    /* Filter bits */
    using f0r1_fb21 = lp::assoc_bit<f0r1, 21>;
    /* Filter bits */
    using f0r1_fb22 = lp::assoc_bit<f0r1, 22>;
    /* Filter bits */
    using f0r1_fb23 = lp::assoc_bit<f0r1, 23>;
    /* Filter bits */
    using f0r1_fb24 = lp::assoc_bit<f0r1, 24>;
    /* Filter bits */
    using f0r1_fb25 = lp::assoc_bit<f0r1, 25>;
    /* Filter bits */
    using f0r1_fb26 = lp::assoc_bit<f0r1, 26>;
    /* Filter bits */
    using f0r1_fb27 = lp::assoc_bit<f0r1, 27>;
    /* Filter bits */
    using f0r1_fb28 = lp::assoc_bit<f0r1, 28>;
    /* Filter bits */
    using f0r1_fb29 = lp::assoc_bit<f0r1, 29>;
    /* Filter bits */
    using f0r1_fb30 = lp::assoc_bit<f0r1, 30>;
    /* Filter bits */
    using f0r1_fb31 = lp::assoc_bit<f0r1, 31>;


    /* Filter bank 0 register 2 */
    using f0r2 = lp::io_register<lp::u32_t, base_address + 0x244>;
    /* Filter bits */
    using f0r2_fb0 = lp::assoc_bit<f0r2, 0>;
    /* Filter bits */
    using f0r2_fb1 = lp::assoc_bit<f0r2, 1>;
    /* Filter bits */
    using f0r2_fb2 = lp::assoc_bit<f0r2, 2>;
    /* Filter bits */
    using f0r2_fb3 = lp::assoc_bit<f0r2, 3>;
    /* Filter bits */
    using f0r2_fb4 = lp::assoc_bit<f0r2, 4>;
    /* Filter bits */
    using f0r2_fb5 = lp::assoc_bit<f0r2, 5>;
    /* Filter bits */
    using f0r2_fb6 = lp::assoc_bit<f0r2, 6>;
    /* Filter bits */
    using f0r2_fb7 = lp::assoc_bit<f0r2, 7>;
    /* Filter bits */
    using f0r2_fb8 = lp::assoc_bit<f0r2, 8>;
    /* Filter bits */
    using f0r2_fb9 = lp::assoc_bit<f0r2, 9>;
    /* Filter bits */
    using f0r2_fb10 = lp::assoc_bit<f0r2, 10>;
    /* Filter bits */
    using f0r2_fb11 = lp::assoc_bit<f0r2, 11>;
    /* Filter bits */
    using f0r2_fb12 = lp::assoc_bit<f0r2, 12>;
    /* Filter bits */
    using f0r2_fb13 = lp::assoc_bit<f0r2, 13>;
    /* Filter bits */
    using f0r2_fb14 = lp::assoc_bit<f0r2, 14>;
    /* Filter bits */
    using f0r2_fb15 = lp::assoc_bit<f0r2, 15>;
    /* Filter bits */
    using f0r2_fb16 = lp::assoc_bit<f0r2, 16>;
    /* Filter bits */
    using f0r2_fb17 = lp::assoc_bit<f0r2, 17>;
    /* Filter bits */
    using f0r2_fb18 = lp::assoc_bit<f0r2, 18>;
    /* Filter bits */
    using f0r2_fb19 = lp::assoc_bit<f0r2, 19>;
    /* Filter bits */
    using f0r2_fb20 = lp::assoc_bit<f0r2, 20>;
    /* Filter bits */
    using f0r2_fb21 = lp::assoc_bit<f0r2, 21>;
    /* Filter bits */
    using f0r2_fb22 = lp::assoc_bit<f0r2, 22>;
    /* Filter bits */
    using f0r2_fb23 = lp::assoc_bit<f0r2, 23>;
    /* Filter bits */
    using f0r2_fb24 = lp::assoc_bit<f0r2, 24>;
    /* Filter bits */
    using f0r2_fb25 = lp::assoc_bit<f0r2, 25>;
    /* Filter bits */
    using f0r2_fb26 = lp::assoc_bit<f0r2, 26>;
    /* Filter bits */
    using f0r2_fb27 = lp::assoc_bit<f0r2, 27>;
    /* Filter bits */
    using f0r2_fb28 = lp::assoc_bit<f0r2, 28>;
    /* Filter bits */
    using f0r2_fb29 = lp::assoc_bit<f0r2, 29>;
    /* Filter bits */
    using f0r2_fb30 = lp::assoc_bit<f0r2, 30>;
    /* Filter bits */
    using f0r2_fb31 = lp::assoc_bit<f0r2, 31>;


    /* Filter bank 1 register 1 */
    using f1r1 = lp::io_register<lp::u32_t, base_address + 0x248>;
    /* Filter bits */
    using f1r1_fb0 = lp::assoc_bit<f1r1, 0>;
    /* Filter bits */
    using f1r1_fb1 = lp::assoc_bit<f1r1, 1>;
    /* Filter bits */
    using f1r1_fb2 = lp::assoc_bit<f1r1, 2>;
    /* Filter bits */
    using f1r1_fb3 = lp::assoc_bit<f1r1, 3>;
    /* Filter bits */
    using f1r1_fb4 = lp::assoc_bit<f1r1, 4>;
    /* Filter bits */
    using f1r1_fb5 = lp::assoc_bit<f1r1, 5>;
    /* Filter bits */
    using f1r1_fb6 = lp::assoc_bit<f1r1, 6>;
    /* Filter bits */
    using f1r1_fb7 = lp::assoc_bit<f1r1, 7>;
    /* Filter bits */
    using f1r1_fb8 = lp::assoc_bit<f1r1, 8>;
    /* Filter bits */
    using f1r1_fb9 = lp::assoc_bit<f1r1, 9>;
    /* Filter bits */
    using f1r1_fb10 = lp::assoc_bit<f1r1, 10>;
    /* Filter bits */
    using f1r1_fb11 = lp::assoc_bit<f1r1, 11>;
    /* Filter bits */
    using f1r1_fb12 = lp::assoc_bit<f1r1, 12>;
    /* Filter bits */
    using f1r1_fb13 = lp::assoc_bit<f1r1, 13>;
    /* Filter bits */
    using f1r1_fb14 = lp::assoc_bit<f1r1, 14>;
    /* Filter bits */
    using f1r1_fb15 = lp::assoc_bit<f1r1, 15>;
    /* Filter bits */
    using f1r1_fb16 = lp::assoc_bit<f1r1, 16>;
    /* Filter bits */
    using f1r1_fb17 = lp::assoc_bit<f1r1, 17>;
    /* Filter bits */
    using f1r1_fb18 = lp::assoc_bit<f1r1, 18>;
    /* Filter bits */
    using f1r1_fb19 = lp::assoc_bit<f1r1, 19>;
    /* Filter bits */
    using f1r1_fb20 = lp::assoc_bit<f1r1, 20>;
    /* Filter bits */
    using f1r1_fb21 = lp::assoc_bit<f1r1, 21>;
    /* Filter bits */
    using f1r1_fb22 = lp::assoc_bit<f1r1, 22>;
    /* Filter bits */
    using f1r1_fb23 = lp::assoc_bit<f1r1, 23>;
    /* Filter bits */
    using f1r1_fb24 = lp::assoc_bit<f1r1, 24>;
    /* Filter bits */
    using f1r1_fb25 = lp::assoc_bit<f1r1, 25>;
    /* Filter bits */
    using f1r1_fb26 = lp::assoc_bit<f1r1, 26>;
    /* Filter bits */
    using f1r1_fb27 = lp::assoc_bit<f1r1, 27>;
    /* Filter bits */
    using f1r1_fb28 = lp::assoc_bit<f1r1, 28>;
    /* Filter bits */
    using f1r1_fb29 = lp::assoc_bit<f1r1, 29>;
    /* Filter bits */
    using f1r1_fb30 = lp::assoc_bit<f1r1, 30>;
    /* Filter bits */
    using f1r1_fb31 = lp::assoc_bit<f1r1, 31>;


    /* Filter bank 1 register 2 */
    using f1r2 = lp::io_register<lp::u32_t, base_address + 0x24c>;
    /* Filter bits */
    using f1r2_fb0 = lp::assoc_bit<f1r2, 0>;
    /* Filter bits */
    using f1r2_fb1 = lp::assoc_bit<f1r2, 1>;
    /* Filter bits */
    using f1r2_fb2 = lp::assoc_bit<f1r2, 2>;
    /* Filter bits */
    using f1r2_fb3 = lp::assoc_bit<f1r2, 3>;
    /* Filter bits */
    using f1r2_fb4 = lp::assoc_bit<f1r2, 4>;
    /* Filter bits */
    using f1r2_fb5 = lp::assoc_bit<f1r2, 5>;
    /* Filter bits */
    using f1r2_fb6 = lp::assoc_bit<f1r2, 6>;
    /* Filter bits */
    using f1r2_fb7 = lp::assoc_bit<f1r2, 7>;
    /* Filter bits */
    using f1r2_fb8 = lp::assoc_bit<f1r2, 8>;
    /* Filter bits */
    using f1r2_fb9 = lp::assoc_bit<f1r2, 9>;
    /* Filter bits */
    using f1r2_fb10 = lp::assoc_bit<f1r2, 10>;
    /* Filter bits */
    using f1r2_fb11 = lp::assoc_bit<f1r2, 11>;
    /* Filter bits */
    using f1r2_fb12 = lp::assoc_bit<f1r2, 12>;
    /* Filter bits */
    using f1r2_fb13 = lp::assoc_bit<f1r2, 13>;
    /* Filter bits */
    using f1r2_fb14 = lp::assoc_bit<f1r2, 14>;
    /* Filter bits */
    using f1r2_fb15 = lp::assoc_bit<f1r2, 15>;
    /* Filter bits */
    using f1r2_fb16 = lp::assoc_bit<f1r2, 16>;
    /* Filter bits */
    using f1r2_fb17 = lp::assoc_bit<f1r2, 17>;
    /* Filter bits */
    using f1r2_fb18 = lp::assoc_bit<f1r2, 18>;
    /* Filter bits */
    using f1r2_fb19 = lp::assoc_bit<f1r2, 19>;
    /* Filter bits */
    using f1r2_fb20 = lp::assoc_bit<f1r2, 20>;
    /* Filter bits */
    using f1r2_fb21 = lp::assoc_bit<f1r2, 21>;
    /* Filter bits */
    using f1r2_fb22 = lp::assoc_bit<f1r2, 22>;
    /* Filter bits */
    using f1r2_fb23 = lp::assoc_bit<f1r2, 23>;
    /* Filter bits */
    using f1r2_fb24 = lp::assoc_bit<f1r2, 24>;
    /* Filter bits */
    using f1r2_fb25 = lp::assoc_bit<f1r2, 25>;
    /* Filter bits */
    using f1r2_fb26 = lp::assoc_bit<f1r2, 26>;
    /* Filter bits */
    using f1r2_fb27 = lp::assoc_bit<f1r2, 27>;
    /* Filter bits */
    using f1r2_fb28 = lp::assoc_bit<f1r2, 28>;
    /* Filter bits */
    using f1r2_fb29 = lp::assoc_bit<f1r2, 29>;
    /* Filter bits */
    using f1r2_fb30 = lp::assoc_bit<f1r2, 30>;
    /* Filter bits */
    using f1r2_fb31 = lp::assoc_bit<f1r2, 31>;


    /* Filter bank 2 register 1 */
    using f2r1 = lp::io_register<lp::u32_t, base_address + 0x250>;
    /* Filter bits */
    using f2r1_fb0 = lp::assoc_bit<f2r1, 0>;
    /* Filter bits */
    using f2r1_fb1 = lp::assoc_bit<f2r1, 1>;
    /* Filter bits */
    using f2r1_fb2 = lp::assoc_bit<f2r1, 2>;
    /* Filter bits */
    using f2r1_fb3 = lp::assoc_bit<f2r1, 3>;
    /* Filter bits */
    using f2r1_fb4 = lp::assoc_bit<f2r1, 4>;
    /* Filter bits */
    using f2r1_fb5 = lp::assoc_bit<f2r1, 5>;
    /* Filter bits */
    using f2r1_fb6 = lp::assoc_bit<f2r1, 6>;
    /* Filter bits */
    using f2r1_fb7 = lp::assoc_bit<f2r1, 7>;
    /* Filter bits */
    using f2r1_fb8 = lp::assoc_bit<f2r1, 8>;
    /* Filter bits */
    using f2r1_fb9 = lp::assoc_bit<f2r1, 9>;
    /* Filter bits */
    using f2r1_fb10 = lp::assoc_bit<f2r1, 10>;
    /* Filter bits */
    using f2r1_fb11 = lp::assoc_bit<f2r1, 11>;
    /* Filter bits */
    using f2r1_fb12 = lp::assoc_bit<f2r1, 12>;
    /* Filter bits */
    using f2r1_fb13 = lp::assoc_bit<f2r1, 13>;
    /* Filter bits */
    using f2r1_fb14 = lp::assoc_bit<f2r1, 14>;
    /* Filter bits */
    using f2r1_fb15 = lp::assoc_bit<f2r1, 15>;
    /* Filter bits */
    using f2r1_fb16 = lp::assoc_bit<f2r1, 16>;
    /* Filter bits */
    using f2r1_fb17 = lp::assoc_bit<f2r1, 17>;
    /* Filter bits */
    using f2r1_fb18 = lp::assoc_bit<f2r1, 18>;
    /* Filter bits */
    using f2r1_fb19 = lp::assoc_bit<f2r1, 19>;
    /* Filter bits */
    using f2r1_fb20 = lp::assoc_bit<f2r1, 20>;
    /* Filter bits */
    using f2r1_fb21 = lp::assoc_bit<f2r1, 21>;
    /* Filter bits */
    using f2r1_fb22 = lp::assoc_bit<f2r1, 22>;
    /* Filter bits */
    using f2r1_fb23 = lp::assoc_bit<f2r1, 23>;
    /* Filter bits */
    using f2r1_fb24 = lp::assoc_bit<f2r1, 24>;
    /* Filter bits */
    using f2r1_fb25 = lp::assoc_bit<f2r1, 25>;
    /* Filter bits */
    using f2r1_fb26 = lp::assoc_bit<f2r1, 26>;
    /* Filter bits */
    using f2r1_fb27 = lp::assoc_bit<f2r1, 27>;
    /* Filter bits */
    using f2r1_fb28 = lp::assoc_bit<f2r1, 28>;
    /* Filter bits */
    using f2r1_fb29 = lp::assoc_bit<f2r1, 29>;
    /* Filter bits */
    using f2r1_fb30 = lp::assoc_bit<f2r1, 30>;
    /* Filter bits */
    using f2r1_fb31 = lp::assoc_bit<f2r1, 31>;


    /* Filter bank 2 register 2 */
    using f2r2 = lp::io_register<lp::u32_t, base_address + 0x254>;
    /* Filter bits */
    using f2r2_fb0 = lp::assoc_bit<f2r2, 0>;
    /* Filter bits */
    using f2r2_fb1 = lp::assoc_bit<f2r2, 1>;
    /* Filter bits */
    using f2r2_fb2 = lp::assoc_bit<f2r2, 2>;
    /* Filter bits */
    using f2r2_fb3 = lp::assoc_bit<f2r2, 3>;
    /* Filter bits */
    using f2r2_fb4 = lp::assoc_bit<f2r2, 4>;
    /* Filter bits */
    using f2r2_fb5 = lp::assoc_bit<f2r2, 5>;
    /* Filter bits */
    using f2r2_fb6 = lp::assoc_bit<f2r2, 6>;
    /* Filter bits */
    using f2r2_fb7 = lp::assoc_bit<f2r2, 7>;
    /* Filter bits */
    using f2r2_fb8 = lp::assoc_bit<f2r2, 8>;
    /* Filter bits */
    using f2r2_fb9 = lp::assoc_bit<f2r2, 9>;
    /* Filter bits */
    using f2r2_fb10 = lp::assoc_bit<f2r2, 10>;
    /* Filter bits */
    using f2r2_fb11 = lp::assoc_bit<f2r2, 11>;
    /* Filter bits */
    using f2r2_fb12 = lp::assoc_bit<f2r2, 12>;
    /* Filter bits */
    using f2r2_fb13 = lp::assoc_bit<f2r2, 13>;
    /* Filter bits */
    using f2r2_fb14 = lp::assoc_bit<f2r2, 14>;
    /* Filter bits */
    using f2r2_fb15 = lp::assoc_bit<f2r2, 15>;
    /* Filter bits */
    using f2r2_fb16 = lp::assoc_bit<f2r2, 16>;
    /* Filter bits */
    using f2r2_fb17 = lp::assoc_bit<f2r2, 17>;
    /* Filter bits */
    using f2r2_fb18 = lp::assoc_bit<f2r2, 18>;
    /* Filter bits */
    using f2r2_fb19 = lp::assoc_bit<f2r2, 19>;
    /* Filter bits */
    using f2r2_fb20 = lp::assoc_bit<f2r2, 20>;
    /* Filter bits */
    using f2r2_fb21 = lp::assoc_bit<f2r2, 21>;
    /* Filter bits */
    using f2r2_fb22 = lp::assoc_bit<f2r2, 22>;
    /* Filter bits */
    using f2r2_fb23 = lp::assoc_bit<f2r2, 23>;
    /* Filter bits */
    using f2r2_fb24 = lp::assoc_bit<f2r2, 24>;
    /* Filter bits */
    using f2r2_fb25 = lp::assoc_bit<f2r2, 25>;
    /* Filter bits */
    using f2r2_fb26 = lp::assoc_bit<f2r2, 26>;
    /* Filter bits */
    using f2r2_fb27 = lp::assoc_bit<f2r2, 27>;
    /* Filter bits */
    using f2r2_fb28 = lp::assoc_bit<f2r2, 28>;
    /* Filter bits */
    using f2r2_fb29 = lp::assoc_bit<f2r2, 29>;
    /* Filter bits */
    using f2r2_fb30 = lp::assoc_bit<f2r2, 30>;
    /* Filter bits */
    using f2r2_fb31 = lp::assoc_bit<f2r2, 31>;


    /* Filter bank 3 register 1 */
    using f3r1 = lp::io_register<lp::u32_t, base_address + 0x258>;
    /* Filter bits */
    using f3r1_fb0 = lp::assoc_bit<f3r1, 0>;
    /* Filter bits */
    using f3r1_fb1 = lp::assoc_bit<f3r1, 1>;
    /* Filter bits */
    using f3r1_fb2 = lp::assoc_bit<f3r1, 2>;
    /* Filter bits */
    using f3r1_fb3 = lp::assoc_bit<f3r1, 3>;
    /* Filter bits */
    using f3r1_fb4 = lp::assoc_bit<f3r1, 4>;
    /* Filter bits */
    using f3r1_fb5 = lp::assoc_bit<f3r1, 5>;
    /* Filter bits */
    using f3r1_fb6 = lp::assoc_bit<f3r1, 6>;
    /* Filter bits */
    using f3r1_fb7 = lp::assoc_bit<f3r1, 7>;
    /* Filter bits */
    using f3r1_fb8 = lp::assoc_bit<f3r1, 8>;
    /* Filter bits */
    using f3r1_fb9 = lp::assoc_bit<f3r1, 9>;
    /* Filter bits */
    using f3r1_fb10 = lp::assoc_bit<f3r1, 10>;
    /* Filter bits */
    using f3r1_fb11 = lp::assoc_bit<f3r1, 11>;
    /* Filter bits */
    using f3r1_fb12 = lp::assoc_bit<f3r1, 12>;
    /* Filter bits */
    using f3r1_fb13 = lp::assoc_bit<f3r1, 13>;
    /* Filter bits */
    using f3r1_fb14 = lp::assoc_bit<f3r1, 14>;
    /* Filter bits */
    using f3r1_fb15 = lp::assoc_bit<f3r1, 15>;
    /* Filter bits */
    using f3r1_fb16 = lp::assoc_bit<f3r1, 16>;
    /* Filter bits */
    using f3r1_fb17 = lp::assoc_bit<f3r1, 17>;
    /* Filter bits */
    using f3r1_fb18 = lp::assoc_bit<f3r1, 18>;
    /* Filter bits */
    using f3r1_fb19 = lp::assoc_bit<f3r1, 19>;
    /* Filter bits */
    using f3r1_fb20 = lp::assoc_bit<f3r1, 20>;
    /* Filter bits */
    using f3r1_fb21 = lp::assoc_bit<f3r1, 21>;
    /* Filter bits */
    using f3r1_fb22 = lp::assoc_bit<f3r1, 22>;
    /* Filter bits */
    using f3r1_fb23 = lp::assoc_bit<f3r1, 23>;
    /* Filter bits */
    using f3r1_fb24 = lp::assoc_bit<f3r1, 24>;
    /* Filter bits */
    using f3r1_fb25 = lp::assoc_bit<f3r1, 25>;
    /* Filter bits */
    using f3r1_fb26 = lp::assoc_bit<f3r1, 26>;
    /* Filter bits */
    using f3r1_fb27 = lp::assoc_bit<f3r1, 27>;
    /* Filter bits */
    using f3r1_fb28 = lp::assoc_bit<f3r1, 28>;
    /* Filter bits */
    using f3r1_fb29 = lp::assoc_bit<f3r1, 29>;
    /* Filter bits */
    using f3r1_fb30 = lp::assoc_bit<f3r1, 30>;
    /* Filter bits */
    using f3r1_fb31 = lp::assoc_bit<f3r1, 31>;


    /* Filter bank 3 register 2 */
    using f3r2 = lp::io_register<lp::u32_t, base_address + 0x25c>;
    /* Filter bits */
    using f3r2_fb0 = lp::assoc_bit<f3r2, 0>;
    /* Filter bits */
    using f3r2_fb1 = lp::assoc_bit<f3r2, 1>;
    /* Filter bits */
    using f3r2_fb2 = lp::assoc_bit<f3r2, 2>;
    /* Filter bits */
    using f3r2_fb3 = lp::assoc_bit<f3r2, 3>;
    /* Filter bits */
    using f3r2_fb4 = lp::assoc_bit<f3r2, 4>;
    /* Filter bits */
    using f3r2_fb5 = lp::assoc_bit<f3r2, 5>;
    /* Filter bits */
    using f3r2_fb6 = lp::assoc_bit<f3r2, 6>;
    /* Filter bits */
    using f3r2_fb7 = lp::assoc_bit<f3r2, 7>;
    /* Filter bits */
    using f3r2_fb8 = lp::assoc_bit<f3r2, 8>;
    /* Filter bits */
    using f3r2_fb9 = lp::assoc_bit<f3r2, 9>;
    /* Filter bits */
    using f3r2_fb10 = lp::assoc_bit<f3r2, 10>;
    /* Filter bits */
    using f3r2_fb11 = lp::assoc_bit<f3r2, 11>;
    /* Filter bits */
    using f3r2_fb12 = lp::assoc_bit<f3r2, 12>;
    /* Filter bits */
    using f3r2_fb13 = lp::assoc_bit<f3r2, 13>;
    /* Filter bits */
    using f3r2_fb14 = lp::assoc_bit<f3r2, 14>;
    /* Filter bits */
    using f3r2_fb15 = lp::assoc_bit<f3r2, 15>;
    /* Filter bits */
    using f3r2_fb16 = lp::assoc_bit<f3r2, 16>;
    /* Filter bits */
    using f3r2_fb17 = lp::assoc_bit<f3r2, 17>;
    /* Filter bits */
    using f3r2_fb18 = lp::assoc_bit<f3r2, 18>;
    /* Filter bits */
    using f3r2_fb19 = lp::assoc_bit<f3r2, 19>;
    /* Filter bits */
    using f3r2_fb20 = lp::assoc_bit<f3r2, 20>;
    /* Filter bits */
    using f3r2_fb21 = lp::assoc_bit<f3r2, 21>;
    /* Filter bits */
    using f3r2_fb22 = lp::assoc_bit<f3r2, 22>;
    /* Filter bits */
    using f3r2_fb23 = lp::assoc_bit<f3r2, 23>;
    /* Filter bits */
    using f3r2_fb24 = lp::assoc_bit<f3r2, 24>;
    /* Filter bits */
    using f3r2_fb25 = lp::assoc_bit<f3r2, 25>;
    /* Filter bits */
    using f3r2_fb26 = lp::assoc_bit<f3r2, 26>;
    /* Filter bits */
    using f3r2_fb27 = lp::assoc_bit<f3r2, 27>;
    /* Filter bits */
    using f3r2_fb28 = lp::assoc_bit<f3r2, 28>;
    /* Filter bits */
    using f3r2_fb29 = lp::assoc_bit<f3r2, 29>;
    /* Filter bits */
    using f3r2_fb30 = lp::assoc_bit<f3r2, 30>;
    /* Filter bits */
    using f3r2_fb31 = lp::assoc_bit<f3r2, 31>;


    /* Filter bank 4 register 1 */
    using f4r1 = lp::io_register<lp::u32_t, base_address + 0x260>;
    /* Filter bits */
    using f4r1_fb0 = lp::assoc_bit<f4r1, 0>;
    /* Filter bits */
    using f4r1_fb1 = lp::assoc_bit<f4r1, 1>;
    /* Filter bits */
    using f4r1_fb2 = lp::assoc_bit<f4r1, 2>;
    /* Filter bits */
    using f4r1_fb3 = lp::assoc_bit<f4r1, 3>;
    /* Filter bits */
    using f4r1_fb4 = lp::assoc_bit<f4r1, 4>;
    /* Filter bits */
    using f4r1_fb5 = lp::assoc_bit<f4r1, 5>;
    /* Filter bits */
    using f4r1_fb6 = lp::assoc_bit<f4r1, 6>;
    /* Filter bits */
    using f4r1_fb7 = lp::assoc_bit<f4r1, 7>;
    /* Filter bits */
    using f4r1_fb8 = lp::assoc_bit<f4r1, 8>;
    /* Filter bits */
    using f4r1_fb9 = lp::assoc_bit<f4r1, 9>;
    /* Filter bits */
    using f4r1_fb10 = lp::assoc_bit<f4r1, 10>;
    /* Filter bits */
    using f4r1_fb11 = lp::assoc_bit<f4r1, 11>;
    /* Filter bits */
    using f4r1_fb12 = lp::assoc_bit<f4r1, 12>;
    /* Filter bits */
    using f4r1_fb13 = lp::assoc_bit<f4r1, 13>;
    /* Filter bits */
    using f4r1_fb14 = lp::assoc_bit<f4r1, 14>;
    /* Filter bits */
    using f4r1_fb15 = lp::assoc_bit<f4r1, 15>;
    /* Filter bits */
    using f4r1_fb16 = lp::assoc_bit<f4r1, 16>;
    /* Filter bits */
    using f4r1_fb17 = lp::assoc_bit<f4r1, 17>;
    /* Filter bits */
    using f4r1_fb18 = lp::assoc_bit<f4r1, 18>;
    /* Filter bits */
    using f4r1_fb19 = lp::assoc_bit<f4r1, 19>;
    /* Filter bits */
    using f4r1_fb20 = lp::assoc_bit<f4r1, 20>;
    /* Filter bits */
    using f4r1_fb21 = lp::assoc_bit<f4r1, 21>;
    /* Filter bits */
    using f4r1_fb22 = lp::assoc_bit<f4r1, 22>;
    /* Filter bits */
    using f4r1_fb23 = lp::assoc_bit<f4r1, 23>;
    /* Filter bits */
    using f4r1_fb24 = lp::assoc_bit<f4r1, 24>;
    /* Filter bits */
    using f4r1_fb25 = lp::assoc_bit<f4r1, 25>;
    /* Filter bits */
    using f4r1_fb26 = lp::assoc_bit<f4r1, 26>;
    /* Filter bits */
    using f4r1_fb27 = lp::assoc_bit<f4r1, 27>;
    /* Filter bits */
    using f4r1_fb28 = lp::assoc_bit<f4r1, 28>;
    /* Filter bits */
    using f4r1_fb29 = lp::assoc_bit<f4r1, 29>;
    /* Filter bits */
    using f4r1_fb30 = lp::assoc_bit<f4r1, 30>;
    /* Filter bits */
    using f4r1_fb31 = lp::assoc_bit<f4r1, 31>;


    /* Filter bank 4 register 2 */
    using f4r2 = lp::io_register<lp::u32_t, base_address + 0x264>;
    /* Filter bits */
    using f4r2_fb0 = lp::assoc_bit<f4r2, 0>;
    /* Filter bits */
    using f4r2_fb1 = lp::assoc_bit<f4r2, 1>;
    /* Filter bits */
    using f4r2_fb2 = lp::assoc_bit<f4r2, 2>;
    /* Filter bits */
    using f4r2_fb3 = lp::assoc_bit<f4r2, 3>;
    /* Filter bits */
    using f4r2_fb4 = lp::assoc_bit<f4r2, 4>;
    /* Filter bits */
    using f4r2_fb5 = lp::assoc_bit<f4r2, 5>;
    /* Filter bits */
    using f4r2_fb6 = lp::assoc_bit<f4r2, 6>;
    /* Filter bits */
    using f4r2_fb7 = lp::assoc_bit<f4r2, 7>;
    /* Filter bits */
    using f4r2_fb8 = lp::assoc_bit<f4r2, 8>;
    /* Filter bits */
    using f4r2_fb9 = lp::assoc_bit<f4r2, 9>;
    /* Filter bits */
    using f4r2_fb10 = lp::assoc_bit<f4r2, 10>;
    /* Filter bits */
    using f4r2_fb11 = lp::assoc_bit<f4r2, 11>;
    /* Filter bits */
    using f4r2_fb12 = lp::assoc_bit<f4r2, 12>;
    /* Filter bits */
    using f4r2_fb13 = lp::assoc_bit<f4r2, 13>;
    /* Filter bits */
    using f4r2_fb14 = lp::assoc_bit<f4r2, 14>;
    /* Filter bits */
    using f4r2_fb15 = lp::assoc_bit<f4r2, 15>;
    /* Filter bits */
    using f4r2_fb16 = lp::assoc_bit<f4r2, 16>;
    /* Filter bits */
    using f4r2_fb17 = lp::assoc_bit<f4r2, 17>;
    /* Filter bits */
    using f4r2_fb18 = lp::assoc_bit<f4r2, 18>;
    /* Filter bits */
    using f4r2_fb19 = lp::assoc_bit<f4r2, 19>;
    /* Filter bits */
    using f4r2_fb20 = lp::assoc_bit<f4r2, 20>;
    /* Filter bits */
    using f4r2_fb21 = lp::assoc_bit<f4r2, 21>;
    /* Filter bits */
    using f4r2_fb22 = lp::assoc_bit<f4r2, 22>;
    /* Filter bits */
    using f4r2_fb23 = lp::assoc_bit<f4r2, 23>;
    /* Filter bits */
    using f4r2_fb24 = lp::assoc_bit<f4r2, 24>;
    /* Filter bits */
    using f4r2_fb25 = lp::assoc_bit<f4r2, 25>;
    /* Filter bits */
    using f4r2_fb26 = lp::assoc_bit<f4r2, 26>;
    /* Filter bits */
    using f4r2_fb27 = lp::assoc_bit<f4r2, 27>;
    /* Filter bits */
    using f4r2_fb28 = lp::assoc_bit<f4r2, 28>;
    /* Filter bits */
    using f4r2_fb29 = lp::assoc_bit<f4r2, 29>;
    /* Filter bits */
    using f4r2_fb30 = lp::assoc_bit<f4r2, 30>;
    /* Filter bits */
    using f4r2_fb31 = lp::assoc_bit<f4r2, 31>;


    /* Filter bank 5 register 1 */
    using f5r1 = lp::io_register<lp::u32_t, base_address + 0x268>;
    /* Filter bits */
    using f5r1_fb0 = lp::assoc_bit<f5r1, 0>;
    /* Filter bits */
    using f5r1_fb1 = lp::assoc_bit<f5r1, 1>;
    /* Filter bits */
    using f5r1_fb2 = lp::assoc_bit<f5r1, 2>;
    /* Filter bits */
    using f5r1_fb3 = lp::assoc_bit<f5r1, 3>;
    /* Filter bits */
    using f5r1_fb4 = lp::assoc_bit<f5r1, 4>;
    /* Filter bits */
    using f5r1_fb5 = lp::assoc_bit<f5r1, 5>;
    /* Filter bits */
    using f5r1_fb6 = lp::assoc_bit<f5r1, 6>;
    /* Filter bits */
    using f5r1_fb7 = lp::assoc_bit<f5r1, 7>;
    /* Filter bits */
    using f5r1_fb8 = lp::assoc_bit<f5r1, 8>;
    /* Filter bits */
    using f5r1_fb9 = lp::assoc_bit<f5r1, 9>;
    /* Filter bits */
    using f5r1_fb10 = lp::assoc_bit<f5r1, 10>;
    /* Filter bits */
    using f5r1_fb11 = lp::assoc_bit<f5r1, 11>;
    /* Filter bits */
    using f5r1_fb12 = lp::assoc_bit<f5r1, 12>;
    /* Filter bits */
    using f5r1_fb13 = lp::assoc_bit<f5r1, 13>;
    /* Filter bits */
    using f5r1_fb14 = lp::assoc_bit<f5r1, 14>;
    /* Filter bits */
    using f5r1_fb15 = lp::assoc_bit<f5r1, 15>;
    /* Filter bits */
    using f5r1_fb16 = lp::assoc_bit<f5r1, 16>;
    /* Filter bits */
    using f5r1_fb17 = lp::assoc_bit<f5r1, 17>;
    /* Filter bits */
    using f5r1_fb18 = lp::assoc_bit<f5r1, 18>;
    /* Filter bits */
    using f5r1_fb19 = lp::assoc_bit<f5r1, 19>;
    /* Filter bits */
    using f5r1_fb20 = lp::assoc_bit<f5r1, 20>;
    /* Filter bits */
    using f5r1_fb21 = lp::assoc_bit<f5r1, 21>;
    /* Filter bits */
    using f5r1_fb22 = lp::assoc_bit<f5r1, 22>;
    /* Filter bits */
    using f5r1_fb23 = lp::assoc_bit<f5r1, 23>;
    /* Filter bits */
    using f5r1_fb24 = lp::assoc_bit<f5r1, 24>;
    /* Filter bits */
    using f5r1_fb25 = lp::assoc_bit<f5r1, 25>;
    /* Filter bits */
    using f5r1_fb26 = lp::assoc_bit<f5r1, 26>;
    /* Filter bits */
    using f5r1_fb27 = lp::assoc_bit<f5r1, 27>;
    /* Filter bits */
    using f5r1_fb28 = lp::assoc_bit<f5r1, 28>;
    /* Filter bits */
    using f5r1_fb29 = lp::assoc_bit<f5r1, 29>;
    /* Filter bits */
    using f5r1_fb30 = lp::assoc_bit<f5r1, 30>;
    /* Filter bits */
    using f5r1_fb31 = lp::assoc_bit<f5r1, 31>;


    /* Filter bank 5 register 2 */
    using f5r2 = lp::io_register<lp::u32_t, base_address + 0x26c>;
    /* Filter bits */
    using f5r2_fb0 = lp::assoc_bit<f5r2, 0>;
    /* Filter bits */
    using f5r2_fb1 = lp::assoc_bit<f5r2, 1>;
    /* Filter bits */
    using f5r2_fb2 = lp::assoc_bit<f5r2, 2>;
    /* Filter bits */
    using f5r2_fb3 = lp::assoc_bit<f5r2, 3>;
    /* Filter bits */
    using f5r2_fb4 = lp::assoc_bit<f5r2, 4>;
    /* Filter bits */
    using f5r2_fb5 = lp::assoc_bit<f5r2, 5>;
    /* Filter bits */
    using f5r2_fb6 = lp::assoc_bit<f5r2, 6>;
    /* Filter bits */
    using f5r2_fb7 = lp::assoc_bit<f5r2, 7>;
    /* Filter bits */
    using f5r2_fb8 = lp::assoc_bit<f5r2, 8>;
    /* Filter bits */
    using f5r2_fb9 = lp::assoc_bit<f5r2, 9>;
    /* Filter bits */
    using f5r2_fb10 = lp::assoc_bit<f5r2, 10>;
    /* Filter bits */
    using f5r2_fb11 = lp::assoc_bit<f5r2, 11>;
    /* Filter bits */
    using f5r2_fb12 = lp::assoc_bit<f5r2, 12>;
    /* Filter bits */
    using f5r2_fb13 = lp::assoc_bit<f5r2, 13>;
    /* Filter bits */
    using f5r2_fb14 = lp::assoc_bit<f5r2, 14>;
    /* Filter bits */
    using f5r2_fb15 = lp::assoc_bit<f5r2, 15>;
    /* Filter bits */
    using f5r2_fb16 = lp::assoc_bit<f5r2, 16>;
    /* Filter bits */
    using f5r2_fb17 = lp::assoc_bit<f5r2, 17>;
    /* Filter bits */
    using f5r2_fb18 = lp::assoc_bit<f5r2, 18>;
    /* Filter bits */
    using f5r2_fb19 = lp::assoc_bit<f5r2, 19>;
    /* Filter bits */
    using f5r2_fb20 = lp::assoc_bit<f5r2, 20>;
    /* Filter bits */
    using f5r2_fb21 = lp::assoc_bit<f5r2, 21>;
    /* Filter bits */
    using f5r2_fb22 = lp::assoc_bit<f5r2, 22>;
    /* Filter bits */
    using f5r2_fb23 = lp::assoc_bit<f5r2, 23>;
    /* Filter bits */
    using f5r2_fb24 = lp::assoc_bit<f5r2, 24>;
    /* Filter bits */
    using f5r2_fb25 = lp::assoc_bit<f5r2, 25>;
    /* Filter bits */
    using f5r2_fb26 = lp::assoc_bit<f5r2, 26>;
    /* Filter bits */
    using f5r2_fb27 = lp::assoc_bit<f5r2, 27>;
    /* Filter bits */
    using f5r2_fb28 = lp::assoc_bit<f5r2, 28>;
    /* Filter bits */
    using f5r2_fb29 = lp::assoc_bit<f5r2, 29>;
    /* Filter bits */
    using f5r2_fb30 = lp::assoc_bit<f5r2, 30>;
    /* Filter bits */
    using f5r2_fb31 = lp::assoc_bit<f5r2, 31>;


    /* Filter bank 6 register 1 */
    using f6r1 = lp::io_register<lp::u32_t, base_address + 0x270>;
    /* Filter bits */
    using f6r1_fb0 = lp::assoc_bit<f6r1, 0>;
    /* Filter bits */
    using f6r1_fb1 = lp::assoc_bit<f6r1, 1>;
    /* Filter bits */
    using f6r1_fb2 = lp::assoc_bit<f6r1, 2>;
    /* Filter bits */
    using f6r1_fb3 = lp::assoc_bit<f6r1, 3>;
    /* Filter bits */
    using f6r1_fb4 = lp::assoc_bit<f6r1, 4>;
    /* Filter bits */
    using f6r1_fb5 = lp::assoc_bit<f6r1, 5>;
    /* Filter bits */
    using f6r1_fb6 = lp::assoc_bit<f6r1, 6>;
    /* Filter bits */
    using f6r1_fb7 = lp::assoc_bit<f6r1, 7>;
    /* Filter bits */
    using f6r1_fb8 = lp::assoc_bit<f6r1, 8>;
    /* Filter bits */
    using f6r1_fb9 = lp::assoc_bit<f6r1, 9>;
    /* Filter bits */
    using f6r1_fb10 = lp::assoc_bit<f6r1, 10>;
    /* Filter bits */
    using f6r1_fb11 = lp::assoc_bit<f6r1, 11>;
    /* Filter bits */
    using f6r1_fb12 = lp::assoc_bit<f6r1, 12>;
    /* Filter bits */
    using f6r1_fb13 = lp::assoc_bit<f6r1, 13>;
    /* Filter bits */
    using f6r1_fb14 = lp::assoc_bit<f6r1, 14>;
    /* Filter bits */
    using f6r1_fb15 = lp::assoc_bit<f6r1, 15>;
    /* Filter bits */
    using f6r1_fb16 = lp::assoc_bit<f6r1, 16>;
    /* Filter bits */
    using f6r1_fb17 = lp::assoc_bit<f6r1, 17>;
    /* Filter bits */
    using f6r1_fb18 = lp::assoc_bit<f6r1, 18>;
    /* Filter bits */
    using f6r1_fb19 = lp::assoc_bit<f6r1, 19>;
    /* Filter bits */
    using f6r1_fb20 = lp::assoc_bit<f6r1, 20>;
    /* Filter bits */
    using f6r1_fb21 = lp::assoc_bit<f6r1, 21>;
    /* Filter bits */
    using f6r1_fb22 = lp::assoc_bit<f6r1, 22>;
    /* Filter bits */
    using f6r1_fb23 = lp::assoc_bit<f6r1, 23>;
    /* Filter bits */
    using f6r1_fb24 = lp::assoc_bit<f6r1, 24>;
    /* Filter bits */
    using f6r1_fb25 = lp::assoc_bit<f6r1, 25>;
    /* Filter bits */
    using f6r1_fb26 = lp::assoc_bit<f6r1, 26>;
    /* Filter bits */
    using f6r1_fb27 = lp::assoc_bit<f6r1, 27>;
    /* Filter bits */
    using f6r1_fb28 = lp::assoc_bit<f6r1, 28>;
    /* Filter bits */
    using f6r1_fb29 = lp::assoc_bit<f6r1, 29>;
    /* Filter bits */
    using f6r1_fb30 = lp::assoc_bit<f6r1, 30>;
    /* Filter bits */
    using f6r1_fb31 = lp::assoc_bit<f6r1, 31>;


    /* Filter bank 6 register 2 */
    using f6r2 = lp::io_register<lp::u32_t, base_address + 0x274>;
    /* Filter bits */
    using f6r2_fb0 = lp::assoc_bit<f6r2, 0>;
    /* Filter bits */
    using f6r2_fb1 = lp::assoc_bit<f6r2, 1>;
    /* Filter bits */
    using f6r2_fb2 = lp::assoc_bit<f6r2, 2>;
    /* Filter bits */
    using f6r2_fb3 = lp::assoc_bit<f6r2, 3>;
    /* Filter bits */
    using f6r2_fb4 = lp::assoc_bit<f6r2, 4>;
    /* Filter bits */
    using f6r2_fb5 = lp::assoc_bit<f6r2, 5>;
    /* Filter bits */
    using f6r2_fb6 = lp::assoc_bit<f6r2, 6>;
    /* Filter bits */
    using f6r2_fb7 = lp::assoc_bit<f6r2, 7>;
    /* Filter bits */
    using f6r2_fb8 = lp::assoc_bit<f6r2, 8>;
    /* Filter bits */
    using f6r2_fb9 = lp::assoc_bit<f6r2, 9>;
    /* Filter bits */
    using f6r2_fb10 = lp::assoc_bit<f6r2, 10>;
    /* Filter bits */
    using f6r2_fb11 = lp::assoc_bit<f6r2, 11>;
    /* Filter bits */
    using f6r2_fb12 = lp::assoc_bit<f6r2, 12>;
    /* Filter bits */
    using f6r2_fb13 = lp::assoc_bit<f6r2, 13>;
    /* Filter bits */
    using f6r2_fb14 = lp::assoc_bit<f6r2, 14>;
    /* Filter bits */
    using f6r2_fb15 = lp::assoc_bit<f6r2, 15>;
    /* Filter bits */
    using f6r2_fb16 = lp::assoc_bit<f6r2, 16>;
    /* Filter bits */
    using f6r2_fb17 = lp::assoc_bit<f6r2, 17>;
    /* Filter bits */
    using f6r2_fb18 = lp::assoc_bit<f6r2, 18>;
    /* Filter bits */
    using f6r2_fb19 = lp::assoc_bit<f6r2, 19>;
    /* Filter bits */
    using f6r2_fb20 = lp::assoc_bit<f6r2, 20>;
    /* Filter bits */
    using f6r2_fb21 = lp::assoc_bit<f6r2, 21>;
    /* Filter bits */
    using f6r2_fb22 = lp::assoc_bit<f6r2, 22>;
    /* Filter bits */
    using f6r2_fb23 = lp::assoc_bit<f6r2, 23>;
    /* Filter bits */
    using f6r2_fb24 = lp::assoc_bit<f6r2, 24>;
    /* Filter bits */
    using f6r2_fb25 = lp::assoc_bit<f6r2, 25>;
    /* Filter bits */
    using f6r2_fb26 = lp::assoc_bit<f6r2, 26>;
    /* Filter bits */
    using f6r2_fb27 = lp::assoc_bit<f6r2, 27>;
    /* Filter bits */
    using f6r2_fb28 = lp::assoc_bit<f6r2, 28>;
    /* Filter bits */
    using f6r2_fb29 = lp::assoc_bit<f6r2, 29>;
    /* Filter bits */
    using f6r2_fb30 = lp::assoc_bit<f6r2, 30>;
    /* Filter bits */
    using f6r2_fb31 = lp::assoc_bit<f6r2, 31>;


    /* Filter bank 7 register 1 */
    using f7r1 = lp::io_register<lp::u32_t, base_address + 0x278>;
    /* Filter bits */
    using f7r1_fb0 = lp::assoc_bit<f7r1, 0>;
    /* Filter bits */
    using f7r1_fb1 = lp::assoc_bit<f7r1, 1>;
    /* Filter bits */
    using f7r1_fb2 = lp::assoc_bit<f7r1, 2>;
    /* Filter bits */
    using f7r1_fb3 = lp::assoc_bit<f7r1, 3>;
    /* Filter bits */
    using f7r1_fb4 = lp::assoc_bit<f7r1, 4>;
    /* Filter bits */
    using f7r1_fb5 = lp::assoc_bit<f7r1, 5>;
    /* Filter bits */
    using f7r1_fb6 = lp::assoc_bit<f7r1, 6>;
    /* Filter bits */
    using f7r1_fb7 = lp::assoc_bit<f7r1, 7>;
    /* Filter bits */
    using f7r1_fb8 = lp::assoc_bit<f7r1, 8>;
    /* Filter bits */
    using f7r1_fb9 = lp::assoc_bit<f7r1, 9>;
    /* Filter bits */
    using f7r1_fb10 = lp::assoc_bit<f7r1, 10>;
    /* Filter bits */
    using f7r1_fb11 = lp::assoc_bit<f7r1, 11>;
    /* Filter bits */
    using f7r1_fb12 = lp::assoc_bit<f7r1, 12>;
    /* Filter bits */
    using f7r1_fb13 = lp::assoc_bit<f7r1, 13>;
    /* Filter bits */
    using f7r1_fb14 = lp::assoc_bit<f7r1, 14>;
    /* Filter bits */
    using f7r1_fb15 = lp::assoc_bit<f7r1, 15>;
    /* Filter bits */
    using f7r1_fb16 = lp::assoc_bit<f7r1, 16>;
    /* Filter bits */
    using f7r1_fb17 = lp::assoc_bit<f7r1, 17>;
    /* Filter bits */
    using f7r1_fb18 = lp::assoc_bit<f7r1, 18>;
    /* Filter bits */
    using f7r1_fb19 = lp::assoc_bit<f7r1, 19>;
    /* Filter bits */
    using f7r1_fb20 = lp::assoc_bit<f7r1, 20>;
    /* Filter bits */
    using f7r1_fb21 = lp::assoc_bit<f7r1, 21>;
    /* Filter bits */
    using f7r1_fb22 = lp::assoc_bit<f7r1, 22>;
    /* Filter bits */
    using f7r1_fb23 = lp::assoc_bit<f7r1, 23>;
    /* Filter bits */
    using f7r1_fb24 = lp::assoc_bit<f7r1, 24>;
    /* Filter bits */
    using f7r1_fb25 = lp::assoc_bit<f7r1, 25>;
    /* Filter bits */
    using f7r1_fb26 = lp::assoc_bit<f7r1, 26>;
    /* Filter bits */
    using f7r1_fb27 = lp::assoc_bit<f7r1, 27>;
    /* Filter bits */
    using f7r1_fb28 = lp::assoc_bit<f7r1, 28>;
    /* Filter bits */
    using f7r1_fb29 = lp::assoc_bit<f7r1, 29>;
    /* Filter bits */
    using f7r1_fb30 = lp::assoc_bit<f7r1, 30>;
    /* Filter bits */
    using f7r1_fb31 = lp::assoc_bit<f7r1, 31>;


    /* Filter bank 7 register 2 */
    using f7r2 = lp::io_register<lp::u32_t, base_address + 0x27c>;
    /* Filter bits */
    using f7r2_fb0 = lp::assoc_bit<f7r2, 0>;
    /* Filter bits */
    using f7r2_fb1 = lp::assoc_bit<f7r2, 1>;
    /* Filter bits */
    using f7r2_fb2 = lp::assoc_bit<f7r2, 2>;
    /* Filter bits */
    using f7r2_fb3 = lp::assoc_bit<f7r2, 3>;
    /* Filter bits */
    using f7r2_fb4 = lp::assoc_bit<f7r2, 4>;
    /* Filter bits */
    using f7r2_fb5 = lp::assoc_bit<f7r2, 5>;
    /* Filter bits */
    using f7r2_fb6 = lp::assoc_bit<f7r2, 6>;
    /* Filter bits */
    using f7r2_fb7 = lp::assoc_bit<f7r2, 7>;
    /* Filter bits */
    using f7r2_fb8 = lp::assoc_bit<f7r2, 8>;
    /* Filter bits */
    using f7r2_fb9 = lp::assoc_bit<f7r2, 9>;
    /* Filter bits */
    using f7r2_fb10 = lp::assoc_bit<f7r2, 10>;
    /* Filter bits */
    using f7r2_fb11 = lp::assoc_bit<f7r2, 11>;
    /* Filter bits */
    using f7r2_fb12 = lp::assoc_bit<f7r2, 12>;
    /* Filter bits */
    using f7r2_fb13 = lp::assoc_bit<f7r2, 13>;
    /* Filter bits */
    using f7r2_fb14 = lp::assoc_bit<f7r2, 14>;
    /* Filter bits */
    using f7r2_fb15 = lp::assoc_bit<f7r2, 15>;
    /* Filter bits */
    using f7r2_fb16 = lp::assoc_bit<f7r2, 16>;
    /* Filter bits */
    using f7r2_fb17 = lp::assoc_bit<f7r2, 17>;
    /* Filter bits */
    using f7r2_fb18 = lp::assoc_bit<f7r2, 18>;
    /* Filter bits */
    using f7r2_fb19 = lp::assoc_bit<f7r2, 19>;
    /* Filter bits */
    using f7r2_fb20 = lp::assoc_bit<f7r2, 20>;
    /* Filter bits */
    using f7r2_fb21 = lp::assoc_bit<f7r2, 21>;
    /* Filter bits */
    using f7r2_fb22 = lp::assoc_bit<f7r2, 22>;
    /* Filter bits */
    using f7r2_fb23 = lp::assoc_bit<f7r2, 23>;
    /* Filter bits */
    using f7r2_fb24 = lp::assoc_bit<f7r2, 24>;
    /* Filter bits */
    using f7r2_fb25 = lp::assoc_bit<f7r2, 25>;
    /* Filter bits */
    using f7r2_fb26 = lp::assoc_bit<f7r2, 26>;
    /* Filter bits */
    using f7r2_fb27 = lp::assoc_bit<f7r2, 27>;
    /* Filter bits */
    using f7r2_fb28 = lp::assoc_bit<f7r2, 28>;
    /* Filter bits */
    using f7r2_fb29 = lp::assoc_bit<f7r2, 29>;
    /* Filter bits */
    using f7r2_fb30 = lp::assoc_bit<f7r2, 30>;
    /* Filter bits */
    using f7r2_fb31 = lp::assoc_bit<f7r2, 31>;


    /* Filter bank 8 register 1 */
    using f8r1 = lp::io_register<lp::u32_t, base_address + 0x280>;
    /* Filter bits */
    using f8r1_fb0 = lp::assoc_bit<f8r1, 0>;
    /* Filter bits */
    using f8r1_fb1 = lp::assoc_bit<f8r1, 1>;
    /* Filter bits */
    using f8r1_fb2 = lp::assoc_bit<f8r1, 2>;
    /* Filter bits */
    using f8r1_fb3 = lp::assoc_bit<f8r1, 3>;
    /* Filter bits */
    using f8r1_fb4 = lp::assoc_bit<f8r1, 4>;
    /* Filter bits */
    using f8r1_fb5 = lp::assoc_bit<f8r1, 5>;
    /* Filter bits */
    using f8r1_fb6 = lp::assoc_bit<f8r1, 6>;
    /* Filter bits */
    using f8r1_fb7 = lp::assoc_bit<f8r1, 7>;
    /* Filter bits */
    using f8r1_fb8 = lp::assoc_bit<f8r1, 8>;
    /* Filter bits */
    using f8r1_fb9 = lp::assoc_bit<f8r1, 9>;
    /* Filter bits */
    using f8r1_fb10 = lp::assoc_bit<f8r1, 10>;
    /* Filter bits */
    using f8r1_fb11 = lp::assoc_bit<f8r1, 11>;
    /* Filter bits */
    using f8r1_fb12 = lp::assoc_bit<f8r1, 12>;
    /* Filter bits */
    using f8r1_fb13 = lp::assoc_bit<f8r1, 13>;
    /* Filter bits */
    using f8r1_fb14 = lp::assoc_bit<f8r1, 14>;
    /* Filter bits */
    using f8r1_fb15 = lp::assoc_bit<f8r1, 15>;
    /* Filter bits */
    using f8r1_fb16 = lp::assoc_bit<f8r1, 16>;
    /* Filter bits */
    using f8r1_fb17 = lp::assoc_bit<f8r1, 17>;
    /* Filter bits */
    using f8r1_fb18 = lp::assoc_bit<f8r1, 18>;
    /* Filter bits */
    using f8r1_fb19 = lp::assoc_bit<f8r1, 19>;
    /* Filter bits */
    using f8r1_fb20 = lp::assoc_bit<f8r1, 20>;
    /* Filter bits */
    using f8r1_fb21 = lp::assoc_bit<f8r1, 21>;
    /* Filter bits */
    using f8r1_fb22 = lp::assoc_bit<f8r1, 22>;
    /* Filter bits */
    using f8r1_fb23 = lp::assoc_bit<f8r1, 23>;
    /* Filter bits */
    using f8r1_fb24 = lp::assoc_bit<f8r1, 24>;
    /* Filter bits */
    using f8r1_fb25 = lp::assoc_bit<f8r1, 25>;
    /* Filter bits */
    using f8r1_fb26 = lp::assoc_bit<f8r1, 26>;
    /* Filter bits */
    using f8r1_fb27 = lp::assoc_bit<f8r1, 27>;
    /* Filter bits */
    using f8r1_fb28 = lp::assoc_bit<f8r1, 28>;
    /* Filter bits */
    using f8r1_fb29 = lp::assoc_bit<f8r1, 29>;
    /* Filter bits */
    using f8r1_fb30 = lp::assoc_bit<f8r1, 30>;
    /* Filter bits */
    using f8r1_fb31 = lp::assoc_bit<f8r1, 31>;


    /* Filter bank 8 register 2 */
    using f8r2 = lp::io_register<lp::u32_t, base_address + 0x284>;
    /* Filter bits */
    using f8r2_fb0 = lp::assoc_bit<f8r2, 0>;
    /* Filter bits */
    using f8r2_fb1 = lp::assoc_bit<f8r2, 1>;
    /* Filter bits */
    using f8r2_fb2 = lp::assoc_bit<f8r2, 2>;
    /* Filter bits */
    using f8r2_fb3 = lp::assoc_bit<f8r2, 3>;
    /* Filter bits */
    using f8r2_fb4 = lp::assoc_bit<f8r2, 4>;
    /* Filter bits */
    using f8r2_fb5 = lp::assoc_bit<f8r2, 5>;
    /* Filter bits */
    using f8r2_fb6 = lp::assoc_bit<f8r2, 6>;
    /* Filter bits */
    using f8r2_fb7 = lp::assoc_bit<f8r2, 7>;
    /* Filter bits */
    using f8r2_fb8 = lp::assoc_bit<f8r2, 8>;
    /* Filter bits */
    using f8r2_fb9 = lp::assoc_bit<f8r2, 9>;
    /* Filter bits */
    using f8r2_fb10 = lp::assoc_bit<f8r2, 10>;
    /* Filter bits */
    using f8r2_fb11 = lp::assoc_bit<f8r2, 11>;
    /* Filter bits */
    using f8r2_fb12 = lp::assoc_bit<f8r2, 12>;
    /* Filter bits */
    using f8r2_fb13 = lp::assoc_bit<f8r2, 13>;
    /* Filter bits */
    using f8r2_fb14 = lp::assoc_bit<f8r2, 14>;
    /* Filter bits */
    using f8r2_fb15 = lp::assoc_bit<f8r2, 15>;
    /* Filter bits */
    using f8r2_fb16 = lp::assoc_bit<f8r2, 16>;
    /* Filter bits */
    using f8r2_fb17 = lp::assoc_bit<f8r2, 17>;
    /* Filter bits */
    using f8r2_fb18 = lp::assoc_bit<f8r2, 18>;
    /* Filter bits */
    using f8r2_fb19 = lp::assoc_bit<f8r2, 19>;
    /* Filter bits */
    using f8r2_fb20 = lp::assoc_bit<f8r2, 20>;
    /* Filter bits */
    using f8r2_fb21 = lp::assoc_bit<f8r2, 21>;
    /* Filter bits */
    using f8r2_fb22 = lp::assoc_bit<f8r2, 22>;
    /* Filter bits */
    using f8r2_fb23 = lp::assoc_bit<f8r2, 23>;
    /* Filter bits */
    using f8r2_fb24 = lp::assoc_bit<f8r2, 24>;
    /* Filter bits */
    using f8r2_fb25 = lp::assoc_bit<f8r2, 25>;
    /* Filter bits */
    using f8r2_fb26 = lp::assoc_bit<f8r2, 26>;
    /* Filter bits */
    using f8r2_fb27 = lp::assoc_bit<f8r2, 27>;
    /* Filter bits */
    using f8r2_fb28 = lp::assoc_bit<f8r2, 28>;
    /* Filter bits */
    using f8r2_fb29 = lp::assoc_bit<f8r2, 29>;
    /* Filter bits */
    using f8r2_fb30 = lp::assoc_bit<f8r2, 30>;
    /* Filter bits */
    using f8r2_fb31 = lp::assoc_bit<f8r2, 31>;


    /* Filter bank 9 register 1 */
    using f9r1 = lp::io_register<lp::u32_t, base_address + 0x288>;
    /* Filter bits */
    using f9r1_fb0 = lp::assoc_bit<f9r1, 0>;
    /* Filter bits */
    using f9r1_fb1 = lp::assoc_bit<f9r1, 1>;
    /* Filter bits */
    using f9r1_fb2 = lp::assoc_bit<f9r1, 2>;
    /* Filter bits */
    using f9r1_fb3 = lp::assoc_bit<f9r1, 3>;
    /* Filter bits */
    using f9r1_fb4 = lp::assoc_bit<f9r1, 4>;
    /* Filter bits */
    using f9r1_fb5 = lp::assoc_bit<f9r1, 5>;
    /* Filter bits */
    using f9r1_fb6 = lp::assoc_bit<f9r1, 6>;
    /* Filter bits */
    using f9r1_fb7 = lp::assoc_bit<f9r1, 7>;
    /* Filter bits */
    using f9r1_fb8 = lp::assoc_bit<f9r1, 8>;
    /* Filter bits */
    using f9r1_fb9 = lp::assoc_bit<f9r1, 9>;
    /* Filter bits */
    using f9r1_fb10 = lp::assoc_bit<f9r1, 10>;
    /* Filter bits */
    using f9r1_fb11 = lp::assoc_bit<f9r1, 11>;
    /* Filter bits */
    using f9r1_fb12 = lp::assoc_bit<f9r1, 12>;
    /* Filter bits */
    using f9r1_fb13 = lp::assoc_bit<f9r1, 13>;
    /* Filter bits */
    using f9r1_fb14 = lp::assoc_bit<f9r1, 14>;
    /* Filter bits */
    using f9r1_fb15 = lp::assoc_bit<f9r1, 15>;
    /* Filter bits */
    using f9r1_fb16 = lp::assoc_bit<f9r1, 16>;
    /* Filter bits */
    using f9r1_fb17 = lp::assoc_bit<f9r1, 17>;
    /* Filter bits */
    using f9r1_fb18 = lp::assoc_bit<f9r1, 18>;
    /* Filter bits */
    using f9r1_fb19 = lp::assoc_bit<f9r1, 19>;
    /* Filter bits */
    using f9r1_fb20 = lp::assoc_bit<f9r1, 20>;
    /* Filter bits */
    using f9r1_fb21 = lp::assoc_bit<f9r1, 21>;
    /* Filter bits */
    using f9r1_fb22 = lp::assoc_bit<f9r1, 22>;
    /* Filter bits */
    using f9r1_fb23 = lp::assoc_bit<f9r1, 23>;
    /* Filter bits */
    using f9r1_fb24 = lp::assoc_bit<f9r1, 24>;
    /* Filter bits */
    using f9r1_fb25 = lp::assoc_bit<f9r1, 25>;
    /* Filter bits */
    using f9r1_fb26 = lp::assoc_bit<f9r1, 26>;
    /* Filter bits */
    using f9r1_fb27 = lp::assoc_bit<f9r1, 27>;
    /* Filter bits */
    using f9r1_fb28 = lp::assoc_bit<f9r1, 28>;
    /* Filter bits */
    using f9r1_fb29 = lp::assoc_bit<f9r1, 29>;
    /* Filter bits */
    using f9r1_fb30 = lp::assoc_bit<f9r1, 30>;
    /* Filter bits */
    using f9r1_fb31 = lp::assoc_bit<f9r1, 31>;


    /* Filter bank 9 register 2 */
    using f9r2 = lp::io_register<lp::u32_t, base_address + 0x28c>;
    /* Filter bits */
    using f9r2_fb0 = lp::assoc_bit<f9r2, 0>;
    /* Filter bits */
    using f9r2_fb1 = lp::assoc_bit<f9r2, 1>;
    /* Filter bits */
    using f9r2_fb2 = lp::assoc_bit<f9r2, 2>;
    /* Filter bits */
    using f9r2_fb3 = lp::assoc_bit<f9r2, 3>;
    /* Filter bits */
    using f9r2_fb4 = lp::assoc_bit<f9r2, 4>;
    /* Filter bits */
    using f9r2_fb5 = lp::assoc_bit<f9r2, 5>;
    /* Filter bits */
    using f9r2_fb6 = lp::assoc_bit<f9r2, 6>;
    /* Filter bits */
    using f9r2_fb7 = lp::assoc_bit<f9r2, 7>;
    /* Filter bits */
    using f9r2_fb8 = lp::assoc_bit<f9r2, 8>;
    /* Filter bits */
    using f9r2_fb9 = lp::assoc_bit<f9r2, 9>;
    /* Filter bits */
    using f9r2_fb10 = lp::assoc_bit<f9r2, 10>;
    /* Filter bits */
    using f9r2_fb11 = lp::assoc_bit<f9r2, 11>;
    /* Filter bits */
    using f9r2_fb12 = lp::assoc_bit<f9r2, 12>;
    /* Filter bits */
    using f9r2_fb13 = lp::assoc_bit<f9r2, 13>;
    /* Filter bits */
    using f9r2_fb14 = lp::assoc_bit<f9r2, 14>;
    /* Filter bits */
    using f9r2_fb15 = lp::assoc_bit<f9r2, 15>;
    /* Filter bits */
    using f9r2_fb16 = lp::assoc_bit<f9r2, 16>;
    /* Filter bits */
    using f9r2_fb17 = lp::assoc_bit<f9r2, 17>;
    /* Filter bits */
    using f9r2_fb18 = lp::assoc_bit<f9r2, 18>;
    /* Filter bits */
    using f9r2_fb19 = lp::assoc_bit<f9r2, 19>;
    /* Filter bits */
    using f9r2_fb20 = lp::assoc_bit<f9r2, 20>;
    /* Filter bits */
    using f9r2_fb21 = lp::assoc_bit<f9r2, 21>;
    /* Filter bits */
    using f9r2_fb22 = lp::assoc_bit<f9r2, 22>;
    /* Filter bits */
    using f9r2_fb23 = lp::assoc_bit<f9r2, 23>;
    /* Filter bits */
    using f9r2_fb24 = lp::assoc_bit<f9r2, 24>;
    /* Filter bits */
    using f9r2_fb25 = lp::assoc_bit<f9r2, 25>;
    /* Filter bits */
    using f9r2_fb26 = lp::assoc_bit<f9r2, 26>;
    /* Filter bits */
    using f9r2_fb27 = lp::assoc_bit<f9r2, 27>;
    /* Filter bits */
    using f9r2_fb28 = lp::assoc_bit<f9r2, 28>;
    /* Filter bits */
    using f9r2_fb29 = lp::assoc_bit<f9r2, 29>;
    /* Filter bits */
    using f9r2_fb30 = lp::assoc_bit<f9r2, 30>;
    /* Filter bits */
    using f9r2_fb31 = lp::assoc_bit<f9r2, 31>;


    /* Filter bank 10 register 1 */
    using f10r1 = lp::io_register<lp::u32_t, base_address + 0x290>;
    /* Filter bits */
    using f10r1_fb0 = lp::assoc_bit<f10r1, 0>;
    /* Filter bits */
    using f10r1_fb1 = lp::assoc_bit<f10r1, 1>;
    /* Filter bits */
    using f10r1_fb2 = lp::assoc_bit<f10r1, 2>;
    /* Filter bits */
    using f10r1_fb3 = lp::assoc_bit<f10r1, 3>;
    /* Filter bits */
    using f10r1_fb4 = lp::assoc_bit<f10r1, 4>;
    /* Filter bits */
    using f10r1_fb5 = lp::assoc_bit<f10r1, 5>;
    /* Filter bits */
    using f10r1_fb6 = lp::assoc_bit<f10r1, 6>;
    /* Filter bits */
    using f10r1_fb7 = lp::assoc_bit<f10r1, 7>;
    /* Filter bits */
    using f10r1_fb8 = lp::assoc_bit<f10r1, 8>;
    /* Filter bits */
    using f10r1_fb9 = lp::assoc_bit<f10r1, 9>;
    /* Filter bits */
    using f10r1_fb10 = lp::assoc_bit<f10r1, 10>;
    /* Filter bits */
    using f10r1_fb11 = lp::assoc_bit<f10r1, 11>;
    /* Filter bits */
    using f10r1_fb12 = lp::assoc_bit<f10r1, 12>;
    /* Filter bits */
    using f10r1_fb13 = lp::assoc_bit<f10r1, 13>;
    /* Filter bits */
    using f10r1_fb14 = lp::assoc_bit<f10r1, 14>;
    /* Filter bits */
    using f10r1_fb15 = lp::assoc_bit<f10r1, 15>;
    /* Filter bits */
    using f10r1_fb16 = lp::assoc_bit<f10r1, 16>;
    /* Filter bits */
    using f10r1_fb17 = lp::assoc_bit<f10r1, 17>;
    /* Filter bits */
    using f10r1_fb18 = lp::assoc_bit<f10r1, 18>;
    /* Filter bits */
    using f10r1_fb19 = lp::assoc_bit<f10r1, 19>;
    /* Filter bits */
    using f10r1_fb20 = lp::assoc_bit<f10r1, 20>;
    /* Filter bits */
    using f10r1_fb21 = lp::assoc_bit<f10r1, 21>;
    /* Filter bits */
    using f10r1_fb22 = lp::assoc_bit<f10r1, 22>;
    /* Filter bits */
    using f10r1_fb23 = lp::assoc_bit<f10r1, 23>;
    /* Filter bits */
    using f10r1_fb24 = lp::assoc_bit<f10r1, 24>;
    /* Filter bits */
    using f10r1_fb25 = lp::assoc_bit<f10r1, 25>;
    /* Filter bits */
    using f10r1_fb26 = lp::assoc_bit<f10r1, 26>;
    /* Filter bits */
    using f10r1_fb27 = lp::assoc_bit<f10r1, 27>;
    /* Filter bits */
    using f10r1_fb28 = lp::assoc_bit<f10r1, 28>;
    /* Filter bits */
    using f10r1_fb29 = lp::assoc_bit<f10r1, 29>;
    /* Filter bits */
    using f10r1_fb30 = lp::assoc_bit<f10r1, 30>;
    /* Filter bits */
    using f10r1_fb31 = lp::assoc_bit<f10r1, 31>;


    /* Filter bank 10 register 2 */
    using f10r2 = lp::io_register<lp::u32_t, base_address + 0x294>;
    /* Filter bits */
    using f10r2_fb0 = lp::assoc_bit<f10r2, 0>;
    /* Filter bits */
    using f10r2_fb1 = lp::assoc_bit<f10r2, 1>;
    /* Filter bits */
    using f10r2_fb2 = lp::assoc_bit<f10r2, 2>;
    /* Filter bits */
    using f10r2_fb3 = lp::assoc_bit<f10r2, 3>;
    /* Filter bits */
    using f10r2_fb4 = lp::assoc_bit<f10r2, 4>;
    /* Filter bits */
    using f10r2_fb5 = lp::assoc_bit<f10r2, 5>;
    /* Filter bits */
    using f10r2_fb6 = lp::assoc_bit<f10r2, 6>;
    /* Filter bits */
    using f10r2_fb7 = lp::assoc_bit<f10r2, 7>;
    /* Filter bits */
    using f10r2_fb8 = lp::assoc_bit<f10r2, 8>;
    /* Filter bits */
    using f10r2_fb9 = lp::assoc_bit<f10r2, 9>;
    /* Filter bits */
    using f10r2_fb10 = lp::assoc_bit<f10r2, 10>;
    /* Filter bits */
    using f10r2_fb11 = lp::assoc_bit<f10r2, 11>;
    /* Filter bits */
    using f10r2_fb12 = lp::assoc_bit<f10r2, 12>;
    /* Filter bits */
    using f10r2_fb13 = lp::assoc_bit<f10r2, 13>;
    /* Filter bits */
    using f10r2_fb14 = lp::assoc_bit<f10r2, 14>;
    /* Filter bits */
    using f10r2_fb15 = lp::assoc_bit<f10r2, 15>;
    /* Filter bits */
    using f10r2_fb16 = lp::assoc_bit<f10r2, 16>;
    /* Filter bits */
    using f10r2_fb17 = lp::assoc_bit<f10r2, 17>;
    /* Filter bits */
    using f10r2_fb18 = lp::assoc_bit<f10r2, 18>;
    /* Filter bits */
    using f10r2_fb19 = lp::assoc_bit<f10r2, 19>;
    /* Filter bits */
    using f10r2_fb20 = lp::assoc_bit<f10r2, 20>;
    /* Filter bits */
    using f10r2_fb21 = lp::assoc_bit<f10r2, 21>;
    /* Filter bits */
    using f10r2_fb22 = lp::assoc_bit<f10r2, 22>;
    /* Filter bits */
    using f10r2_fb23 = lp::assoc_bit<f10r2, 23>;
    /* Filter bits */
    using f10r2_fb24 = lp::assoc_bit<f10r2, 24>;
    /* Filter bits */
    using f10r2_fb25 = lp::assoc_bit<f10r2, 25>;
    /* Filter bits */
    using f10r2_fb26 = lp::assoc_bit<f10r2, 26>;
    /* Filter bits */
    using f10r2_fb27 = lp::assoc_bit<f10r2, 27>;
    /* Filter bits */
    using f10r2_fb28 = lp::assoc_bit<f10r2, 28>;
    /* Filter bits */
    using f10r2_fb29 = lp::assoc_bit<f10r2, 29>;
    /* Filter bits */
    using f10r2_fb30 = lp::assoc_bit<f10r2, 30>;
    /* Filter bits */
    using f10r2_fb31 = lp::assoc_bit<f10r2, 31>;


    /* Filter bank 11 register 1 */
    using f11r1 = lp::io_register<lp::u32_t, base_address + 0x298>;
    /* Filter bits */
    using f11r1_fb0 = lp::assoc_bit<f11r1, 0>;
    /* Filter bits */
    using f11r1_fb1 = lp::assoc_bit<f11r1, 1>;
    /* Filter bits */
    using f11r1_fb2 = lp::assoc_bit<f11r1, 2>;
    /* Filter bits */
    using f11r1_fb3 = lp::assoc_bit<f11r1, 3>;
    /* Filter bits */
    using f11r1_fb4 = lp::assoc_bit<f11r1, 4>;
    /* Filter bits */
    using f11r1_fb5 = lp::assoc_bit<f11r1, 5>;
    /* Filter bits */
    using f11r1_fb6 = lp::assoc_bit<f11r1, 6>;
    /* Filter bits */
    using f11r1_fb7 = lp::assoc_bit<f11r1, 7>;
    /* Filter bits */
    using f11r1_fb8 = lp::assoc_bit<f11r1, 8>;
    /* Filter bits */
    using f11r1_fb9 = lp::assoc_bit<f11r1, 9>;
    /* Filter bits */
    using f11r1_fb10 = lp::assoc_bit<f11r1, 10>;
    /* Filter bits */
    using f11r1_fb11 = lp::assoc_bit<f11r1, 11>;
    /* Filter bits */
    using f11r1_fb12 = lp::assoc_bit<f11r1, 12>;
    /* Filter bits */
    using f11r1_fb13 = lp::assoc_bit<f11r1, 13>;
    /* Filter bits */
    using f11r1_fb14 = lp::assoc_bit<f11r1, 14>;
    /* Filter bits */
    using f11r1_fb15 = lp::assoc_bit<f11r1, 15>;
    /* Filter bits */
    using f11r1_fb16 = lp::assoc_bit<f11r1, 16>;
    /* Filter bits */
    using f11r1_fb17 = lp::assoc_bit<f11r1, 17>;
    /* Filter bits */
    using f11r1_fb18 = lp::assoc_bit<f11r1, 18>;
    /* Filter bits */
    using f11r1_fb19 = lp::assoc_bit<f11r1, 19>;
    /* Filter bits */
    using f11r1_fb20 = lp::assoc_bit<f11r1, 20>;
    /* Filter bits */
    using f11r1_fb21 = lp::assoc_bit<f11r1, 21>;
    /* Filter bits */
    using f11r1_fb22 = lp::assoc_bit<f11r1, 22>;
    /* Filter bits */
    using f11r1_fb23 = lp::assoc_bit<f11r1, 23>;
    /* Filter bits */
    using f11r1_fb24 = lp::assoc_bit<f11r1, 24>;
    /* Filter bits */
    using f11r1_fb25 = lp::assoc_bit<f11r1, 25>;
    /* Filter bits */
    using f11r1_fb26 = lp::assoc_bit<f11r1, 26>;
    /* Filter bits */
    using f11r1_fb27 = lp::assoc_bit<f11r1, 27>;
    /* Filter bits */
    using f11r1_fb28 = lp::assoc_bit<f11r1, 28>;
    /* Filter bits */
    using f11r1_fb29 = lp::assoc_bit<f11r1, 29>;
    /* Filter bits */
    using f11r1_fb30 = lp::assoc_bit<f11r1, 30>;
    /* Filter bits */
    using f11r1_fb31 = lp::assoc_bit<f11r1, 31>;


    /* Filter bank 11 register 2 */
    using f11r2 = lp::io_register<lp::u32_t, base_address + 0x29c>;
    /* Filter bits */
    using f11r2_fb0 = lp::assoc_bit<f11r2, 0>;
    /* Filter bits */
    using f11r2_fb1 = lp::assoc_bit<f11r2, 1>;
    /* Filter bits */
    using f11r2_fb2 = lp::assoc_bit<f11r2, 2>;
    /* Filter bits */
    using f11r2_fb3 = lp::assoc_bit<f11r2, 3>;
    /* Filter bits */
    using f11r2_fb4 = lp::assoc_bit<f11r2, 4>;
    /* Filter bits */
    using f11r2_fb5 = lp::assoc_bit<f11r2, 5>;
    /* Filter bits */
    using f11r2_fb6 = lp::assoc_bit<f11r2, 6>;
    /* Filter bits */
    using f11r2_fb7 = lp::assoc_bit<f11r2, 7>;
    /* Filter bits */
    using f11r2_fb8 = lp::assoc_bit<f11r2, 8>;
    /* Filter bits */
    using f11r2_fb9 = lp::assoc_bit<f11r2, 9>;
    /* Filter bits */
    using f11r2_fb10 = lp::assoc_bit<f11r2, 10>;
    /* Filter bits */
    using f11r2_fb11 = lp::assoc_bit<f11r2, 11>;
    /* Filter bits */
    using f11r2_fb12 = lp::assoc_bit<f11r2, 12>;
    /* Filter bits */
    using f11r2_fb13 = lp::assoc_bit<f11r2, 13>;
    /* Filter bits */
    using f11r2_fb14 = lp::assoc_bit<f11r2, 14>;
    /* Filter bits */
    using f11r2_fb15 = lp::assoc_bit<f11r2, 15>;
    /* Filter bits */
    using f11r2_fb16 = lp::assoc_bit<f11r2, 16>;
    /* Filter bits */
    using f11r2_fb17 = lp::assoc_bit<f11r2, 17>;
    /* Filter bits */
    using f11r2_fb18 = lp::assoc_bit<f11r2, 18>;
    /* Filter bits */
    using f11r2_fb19 = lp::assoc_bit<f11r2, 19>;
    /* Filter bits */
    using f11r2_fb20 = lp::assoc_bit<f11r2, 20>;
    /* Filter bits */
    using f11r2_fb21 = lp::assoc_bit<f11r2, 21>;
    /* Filter bits */
    using f11r2_fb22 = lp::assoc_bit<f11r2, 22>;
    /* Filter bits */
    using f11r2_fb23 = lp::assoc_bit<f11r2, 23>;
    /* Filter bits */
    using f11r2_fb24 = lp::assoc_bit<f11r2, 24>;
    /* Filter bits */
    using f11r2_fb25 = lp::assoc_bit<f11r2, 25>;
    /* Filter bits */
    using f11r2_fb26 = lp::assoc_bit<f11r2, 26>;
    /* Filter bits */
    using f11r2_fb27 = lp::assoc_bit<f11r2, 27>;
    /* Filter bits */
    using f11r2_fb28 = lp::assoc_bit<f11r2, 28>;
    /* Filter bits */
    using f11r2_fb29 = lp::assoc_bit<f11r2, 29>;
    /* Filter bits */
    using f11r2_fb30 = lp::assoc_bit<f11r2, 30>;
    /* Filter bits */
    using f11r2_fb31 = lp::assoc_bit<f11r2, 31>;


    /* Filter bank 4 register 1 */
    using f12r1 = lp::io_register<lp::u32_t, base_address + 0x2a0>;
    /* Filter bits */
    using f12r1_fb0 = lp::assoc_bit<f12r1, 0>;
    /* Filter bits */
    using f12r1_fb1 = lp::assoc_bit<f12r1, 1>;
    /* Filter bits */
    using f12r1_fb2 = lp::assoc_bit<f12r1, 2>;
    /* Filter bits */
    using f12r1_fb3 = lp::assoc_bit<f12r1, 3>;
    /* Filter bits */
    using f12r1_fb4 = lp::assoc_bit<f12r1, 4>;
    /* Filter bits */
    using f12r1_fb5 = lp::assoc_bit<f12r1, 5>;
    /* Filter bits */
    using f12r1_fb6 = lp::assoc_bit<f12r1, 6>;
    /* Filter bits */
    using f12r1_fb7 = lp::assoc_bit<f12r1, 7>;
    /* Filter bits */
    using f12r1_fb8 = lp::assoc_bit<f12r1, 8>;
    /* Filter bits */
    using f12r1_fb9 = lp::assoc_bit<f12r1, 9>;
    /* Filter bits */
    using f12r1_fb10 = lp::assoc_bit<f12r1, 10>;
    /* Filter bits */
    using f12r1_fb11 = lp::assoc_bit<f12r1, 11>;
    /* Filter bits */
    using f12r1_fb12 = lp::assoc_bit<f12r1, 12>;
    /* Filter bits */
    using f12r1_fb13 = lp::assoc_bit<f12r1, 13>;
    /* Filter bits */
    using f12r1_fb14 = lp::assoc_bit<f12r1, 14>;
    /* Filter bits */
    using f12r1_fb15 = lp::assoc_bit<f12r1, 15>;
    /* Filter bits */
    using f12r1_fb16 = lp::assoc_bit<f12r1, 16>;
    /* Filter bits */
    using f12r1_fb17 = lp::assoc_bit<f12r1, 17>;
    /* Filter bits */
    using f12r1_fb18 = lp::assoc_bit<f12r1, 18>;
    /* Filter bits */
    using f12r1_fb19 = lp::assoc_bit<f12r1, 19>;
    /* Filter bits */
    using f12r1_fb20 = lp::assoc_bit<f12r1, 20>;
    /* Filter bits */
    using f12r1_fb21 = lp::assoc_bit<f12r1, 21>;
    /* Filter bits */
    using f12r1_fb22 = lp::assoc_bit<f12r1, 22>;
    /* Filter bits */
    using f12r1_fb23 = lp::assoc_bit<f12r1, 23>;
    /* Filter bits */
    using f12r1_fb24 = lp::assoc_bit<f12r1, 24>;
    /* Filter bits */
    using f12r1_fb25 = lp::assoc_bit<f12r1, 25>;
    /* Filter bits */
    using f12r1_fb26 = lp::assoc_bit<f12r1, 26>;
    /* Filter bits */
    using f12r1_fb27 = lp::assoc_bit<f12r1, 27>;
    /* Filter bits */
    using f12r1_fb28 = lp::assoc_bit<f12r1, 28>;
    /* Filter bits */
    using f12r1_fb29 = lp::assoc_bit<f12r1, 29>;
    /* Filter bits */
    using f12r1_fb30 = lp::assoc_bit<f12r1, 30>;
    /* Filter bits */
    using f12r1_fb31 = lp::assoc_bit<f12r1, 31>;


    /* Filter bank 12 register 2 */
    using f12r2 = lp::io_register<lp::u32_t, base_address + 0x2a4>;
    /* Filter bits */
    using f12r2_fb0 = lp::assoc_bit<f12r2, 0>;
    /* Filter bits */
    using f12r2_fb1 = lp::assoc_bit<f12r2, 1>;
    /* Filter bits */
    using f12r2_fb2 = lp::assoc_bit<f12r2, 2>;
    /* Filter bits */
    using f12r2_fb3 = lp::assoc_bit<f12r2, 3>;
    /* Filter bits */
    using f12r2_fb4 = lp::assoc_bit<f12r2, 4>;
    /* Filter bits */
    using f12r2_fb5 = lp::assoc_bit<f12r2, 5>;
    /* Filter bits */
    using f12r2_fb6 = lp::assoc_bit<f12r2, 6>;
    /* Filter bits */
    using f12r2_fb7 = lp::assoc_bit<f12r2, 7>;
    /* Filter bits */
    using f12r2_fb8 = lp::assoc_bit<f12r2, 8>;
    /* Filter bits */
    using f12r2_fb9 = lp::assoc_bit<f12r2, 9>;
    /* Filter bits */
    using f12r2_fb10 = lp::assoc_bit<f12r2, 10>;
    /* Filter bits */
    using f12r2_fb11 = lp::assoc_bit<f12r2, 11>;
    /* Filter bits */
    using f12r2_fb12 = lp::assoc_bit<f12r2, 12>;
    /* Filter bits */
    using f12r2_fb13 = lp::assoc_bit<f12r2, 13>;
    /* Filter bits */
    using f12r2_fb14 = lp::assoc_bit<f12r2, 14>;
    /* Filter bits */
    using f12r2_fb15 = lp::assoc_bit<f12r2, 15>;
    /* Filter bits */
    using f12r2_fb16 = lp::assoc_bit<f12r2, 16>;
    /* Filter bits */
    using f12r2_fb17 = lp::assoc_bit<f12r2, 17>;
    /* Filter bits */
    using f12r2_fb18 = lp::assoc_bit<f12r2, 18>;
    /* Filter bits */
    using f12r2_fb19 = lp::assoc_bit<f12r2, 19>;
    /* Filter bits */
    using f12r2_fb20 = lp::assoc_bit<f12r2, 20>;
    /* Filter bits */
    using f12r2_fb21 = lp::assoc_bit<f12r2, 21>;
    /* Filter bits */
    using f12r2_fb22 = lp::assoc_bit<f12r2, 22>;
    /* Filter bits */
    using f12r2_fb23 = lp::assoc_bit<f12r2, 23>;
    /* Filter bits */
    using f12r2_fb24 = lp::assoc_bit<f12r2, 24>;
    /* Filter bits */
    using f12r2_fb25 = lp::assoc_bit<f12r2, 25>;
    /* Filter bits */
    using f12r2_fb26 = lp::assoc_bit<f12r2, 26>;
    /* Filter bits */
    using f12r2_fb27 = lp::assoc_bit<f12r2, 27>;
    /* Filter bits */
    using f12r2_fb28 = lp::assoc_bit<f12r2, 28>;
    /* Filter bits */
    using f12r2_fb29 = lp::assoc_bit<f12r2, 29>;
    /* Filter bits */
    using f12r2_fb30 = lp::assoc_bit<f12r2, 30>;
    /* Filter bits */
    using f12r2_fb31 = lp::assoc_bit<f12r2, 31>;


    /* Filter bank 13 register 1 */
    using f13r1 = lp::io_register<lp::u32_t, base_address + 0x2a8>;
    /* Filter bits */
    using f13r1_fb0 = lp::assoc_bit<f13r1, 0>;
    /* Filter bits */
    using f13r1_fb1 = lp::assoc_bit<f13r1, 1>;
    /* Filter bits */
    using f13r1_fb2 = lp::assoc_bit<f13r1, 2>;
    /* Filter bits */
    using f13r1_fb3 = lp::assoc_bit<f13r1, 3>;
    /* Filter bits */
    using f13r1_fb4 = lp::assoc_bit<f13r1, 4>;
    /* Filter bits */
    using f13r1_fb5 = lp::assoc_bit<f13r1, 5>;
    /* Filter bits */
    using f13r1_fb6 = lp::assoc_bit<f13r1, 6>;
    /* Filter bits */
    using f13r1_fb7 = lp::assoc_bit<f13r1, 7>;
    /* Filter bits */
    using f13r1_fb8 = lp::assoc_bit<f13r1, 8>;
    /* Filter bits */
    using f13r1_fb9 = lp::assoc_bit<f13r1, 9>;
    /* Filter bits */
    using f13r1_fb10 = lp::assoc_bit<f13r1, 10>;
    /* Filter bits */
    using f13r1_fb11 = lp::assoc_bit<f13r1, 11>;
    /* Filter bits */
    using f13r1_fb12 = lp::assoc_bit<f13r1, 12>;
    /* Filter bits */
    using f13r1_fb13 = lp::assoc_bit<f13r1, 13>;
    /* Filter bits */
    using f13r1_fb14 = lp::assoc_bit<f13r1, 14>;
    /* Filter bits */
    using f13r1_fb15 = lp::assoc_bit<f13r1, 15>;
    /* Filter bits */
    using f13r1_fb16 = lp::assoc_bit<f13r1, 16>;
    /* Filter bits */
    using f13r1_fb17 = lp::assoc_bit<f13r1, 17>;
    /* Filter bits */
    using f13r1_fb18 = lp::assoc_bit<f13r1, 18>;
    /* Filter bits */
    using f13r1_fb19 = lp::assoc_bit<f13r1, 19>;
    /* Filter bits */
    using f13r1_fb20 = lp::assoc_bit<f13r1, 20>;
    /* Filter bits */
    using f13r1_fb21 = lp::assoc_bit<f13r1, 21>;
    /* Filter bits */
    using f13r1_fb22 = lp::assoc_bit<f13r1, 22>;
    /* Filter bits */
    using f13r1_fb23 = lp::assoc_bit<f13r1, 23>;
    /* Filter bits */
    using f13r1_fb24 = lp::assoc_bit<f13r1, 24>;
    /* Filter bits */
    using f13r1_fb25 = lp::assoc_bit<f13r1, 25>;
    /* Filter bits */
    using f13r1_fb26 = lp::assoc_bit<f13r1, 26>;
    /* Filter bits */
    using f13r1_fb27 = lp::assoc_bit<f13r1, 27>;
    /* Filter bits */
    using f13r1_fb28 = lp::assoc_bit<f13r1, 28>;
    /* Filter bits */
    using f13r1_fb29 = lp::assoc_bit<f13r1, 29>;
    /* Filter bits */
    using f13r1_fb30 = lp::assoc_bit<f13r1, 30>;
    /* Filter bits */
    using f13r1_fb31 = lp::assoc_bit<f13r1, 31>;


    /* Filter bank 13 register 2 */
    using f13r2 = lp::io_register<lp::u32_t, base_address + 0x2ac>;
    /* Filter bits */
    using f13r2_fb0 = lp::assoc_bit<f13r2, 0>;
    /* Filter bits */
    using f13r2_fb1 = lp::assoc_bit<f13r2, 1>;
    /* Filter bits */
    using f13r2_fb2 = lp::assoc_bit<f13r2, 2>;
    /* Filter bits */
    using f13r2_fb3 = lp::assoc_bit<f13r2, 3>;
    /* Filter bits */
    using f13r2_fb4 = lp::assoc_bit<f13r2, 4>;
    /* Filter bits */
    using f13r2_fb5 = lp::assoc_bit<f13r2, 5>;
    /* Filter bits */
    using f13r2_fb6 = lp::assoc_bit<f13r2, 6>;
    /* Filter bits */
    using f13r2_fb7 = lp::assoc_bit<f13r2, 7>;
    /* Filter bits */
    using f13r2_fb8 = lp::assoc_bit<f13r2, 8>;
    /* Filter bits */
    using f13r2_fb9 = lp::assoc_bit<f13r2, 9>;
    /* Filter bits */
    using f13r2_fb10 = lp::assoc_bit<f13r2, 10>;
    /* Filter bits */
    using f13r2_fb11 = lp::assoc_bit<f13r2, 11>;
    /* Filter bits */
    using f13r2_fb12 = lp::assoc_bit<f13r2, 12>;
    /* Filter bits */
    using f13r2_fb13 = lp::assoc_bit<f13r2, 13>;
    /* Filter bits */
    using f13r2_fb14 = lp::assoc_bit<f13r2, 14>;
    /* Filter bits */
    using f13r2_fb15 = lp::assoc_bit<f13r2, 15>;
    /* Filter bits */
    using f13r2_fb16 = lp::assoc_bit<f13r2, 16>;
    /* Filter bits */
    using f13r2_fb17 = lp::assoc_bit<f13r2, 17>;
    /* Filter bits */
    using f13r2_fb18 = lp::assoc_bit<f13r2, 18>;
    /* Filter bits */
    using f13r2_fb19 = lp::assoc_bit<f13r2, 19>;
    /* Filter bits */
    using f13r2_fb20 = lp::assoc_bit<f13r2, 20>;
    /* Filter bits */
    using f13r2_fb21 = lp::assoc_bit<f13r2, 21>;
    /* Filter bits */
    using f13r2_fb22 = lp::assoc_bit<f13r2, 22>;
    /* Filter bits */
    using f13r2_fb23 = lp::assoc_bit<f13r2, 23>;
    /* Filter bits */
    using f13r2_fb24 = lp::assoc_bit<f13r2, 24>;
    /* Filter bits */
    using f13r2_fb25 = lp::assoc_bit<f13r2, 25>;
    /* Filter bits */
    using f13r2_fb26 = lp::assoc_bit<f13r2, 26>;
    /* Filter bits */
    using f13r2_fb27 = lp::assoc_bit<f13r2, 27>;
    /* Filter bits */
    using f13r2_fb28 = lp::assoc_bit<f13r2, 28>;
    /* Filter bits */
    using f13r2_fb29 = lp::assoc_bit<f13r2, 29>;
    /* Filter bits */
    using f13r2_fb30 = lp::assoc_bit<f13r2, 30>;
    /* Filter bits */
    using f13r2_fb31 = lp::assoc_bit<f13r2, 31>;


    /* Filter bank 14 register 1 */
    using f14r1 = lp::io_register<lp::u32_t, base_address + 0x2b0>;
    /* Filter bits */
    using f14r1_fb0 = lp::assoc_bit<f14r1, 0>;
    /* Filter bits */
    using f14r1_fb1 = lp::assoc_bit<f14r1, 1>;
    /* Filter bits */
    using f14r1_fb2 = lp::assoc_bit<f14r1, 2>;
    /* Filter bits */
    using f14r1_fb3 = lp::assoc_bit<f14r1, 3>;
    /* Filter bits */
    using f14r1_fb4 = lp::assoc_bit<f14r1, 4>;
    /* Filter bits */
    using f14r1_fb5 = lp::assoc_bit<f14r1, 5>;
    /* Filter bits */
    using f14r1_fb6 = lp::assoc_bit<f14r1, 6>;
    /* Filter bits */
    using f14r1_fb7 = lp::assoc_bit<f14r1, 7>;
    /* Filter bits */
    using f14r1_fb8 = lp::assoc_bit<f14r1, 8>;
    /* Filter bits */
    using f14r1_fb9 = lp::assoc_bit<f14r1, 9>;
    /* Filter bits */
    using f14r1_fb10 = lp::assoc_bit<f14r1, 10>;
    /* Filter bits */
    using f14r1_fb11 = lp::assoc_bit<f14r1, 11>;
    /* Filter bits */
    using f14r1_fb12 = lp::assoc_bit<f14r1, 12>;
    /* Filter bits */
    using f14r1_fb13 = lp::assoc_bit<f14r1, 13>;
    /* Filter bits */
    using f14r1_fb14 = lp::assoc_bit<f14r1, 14>;
    /* Filter bits */
    using f14r1_fb15 = lp::assoc_bit<f14r1, 15>;
    /* Filter bits */
    using f14r1_fb16 = lp::assoc_bit<f14r1, 16>;
    /* Filter bits */
    using f14r1_fb17 = lp::assoc_bit<f14r1, 17>;
    /* Filter bits */
    using f14r1_fb18 = lp::assoc_bit<f14r1, 18>;
    /* Filter bits */
    using f14r1_fb19 = lp::assoc_bit<f14r1, 19>;
    /* Filter bits */
    using f14r1_fb20 = lp::assoc_bit<f14r1, 20>;
    /* Filter bits */
    using f14r1_fb21 = lp::assoc_bit<f14r1, 21>;
    /* Filter bits */
    using f14r1_fb22 = lp::assoc_bit<f14r1, 22>;
    /* Filter bits */
    using f14r1_fb23 = lp::assoc_bit<f14r1, 23>;
    /* Filter bits */
    using f14r1_fb24 = lp::assoc_bit<f14r1, 24>;
    /* Filter bits */
    using f14r1_fb25 = lp::assoc_bit<f14r1, 25>;
    /* Filter bits */
    using f14r1_fb26 = lp::assoc_bit<f14r1, 26>;
    /* Filter bits */
    using f14r1_fb27 = lp::assoc_bit<f14r1, 27>;
    /* Filter bits */
    using f14r1_fb28 = lp::assoc_bit<f14r1, 28>;
    /* Filter bits */
    using f14r1_fb29 = lp::assoc_bit<f14r1, 29>;
    /* Filter bits */
    using f14r1_fb30 = lp::assoc_bit<f14r1, 30>;
    /* Filter bits */
    using f14r1_fb31 = lp::assoc_bit<f14r1, 31>;


    /* Filter bank 14 register 2 */
    using f14r2 = lp::io_register<lp::u32_t, base_address + 0x2b4>;
    /* Filter bits */
    using f14r2_fb0 = lp::assoc_bit<f14r2, 0>;
    /* Filter bits */
    using f14r2_fb1 = lp::assoc_bit<f14r2, 1>;
    /* Filter bits */
    using f14r2_fb2 = lp::assoc_bit<f14r2, 2>;
    /* Filter bits */
    using f14r2_fb3 = lp::assoc_bit<f14r2, 3>;
    /* Filter bits */
    using f14r2_fb4 = lp::assoc_bit<f14r2, 4>;
    /* Filter bits */
    using f14r2_fb5 = lp::assoc_bit<f14r2, 5>;
    /* Filter bits */
    using f14r2_fb6 = lp::assoc_bit<f14r2, 6>;
    /* Filter bits */
    using f14r2_fb7 = lp::assoc_bit<f14r2, 7>;
    /* Filter bits */
    using f14r2_fb8 = lp::assoc_bit<f14r2, 8>;
    /* Filter bits */
    using f14r2_fb9 = lp::assoc_bit<f14r2, 9>;
    /* Filter bits */
    using f14r2_fb10 = lp::assoc_bit<f14r2, 10>;
    /* Filter bits */
    using f14r2_fb11 = lp::assoc_bit<f14r2, 11>;
    /* Filter bits */
    using f14r2_fb12 = lp::assoc_bit<f14r2, 12>;
    /* Filter bits */
    using f14r2_fb13 = lp::assoc_bit<f14r2, 13>;
    /* Filter bits */
    using f14r2_fb14 = lp::assoc_bit<f14r2, 14>;
    /* Filter bits */
    using f14r2_fb15 = lp::assoc_bit<f14r2, 15>;
    /* Filter bits */
    using f14r2_fb16 = lp::assoc_bit<f14r2, 16>;
    /* Filter bits */
    using f14r2_fb17 = lp::assoc_bit<f14r2, 17>;
    /* Filter bits */
    using f14r2_fb18 = lp::assoc_bit<f14r2, 18>;
    /* Filter bits */
    using f14r2_fb19 = lp::assoc_bit<f14r2, 19>;
    /* Filter bits */
    using f14r2_fb20 = lp::assoc_bit<f14r2, 20>;
    /* Filter bits */
    using f14r2_fb21 = lp::assoc_bit<f14r2, 21>;
    /* Filter bits */
    using f14r2_fb22 = lp::assoc_bit<f14r2, 22>;
    /* Filter bits */
    using f14r2_fb23 = lp::assoc_bit<f14r2, 23>;
    /* Filter bits */
    using f14r2_fb24 = lp::assoc_bit<f14r2, 24>;
    /* Filter bits */
    using f14r2_fb25 = lp::assoc_bit<f14r2, 25>;
    /* Filter bits */
    using f14r2_fb26 = lp::assoc_bit<f14r2, 26>;
    /* Filter bits */
    using f14r2_fb27 = lp::assoc_bit<f14r2, 27>;
    /* Filter bits */
    using f14r2_fb28 = lp::assoc_bit<f14r2, 28>;
    /* Filter bits */
    using f14r2_fb29 = lp::assoc_bit<f14r2, 29>;
    /* Filter bits */
    using f14r2_fb30 = lp::assoc_bit<f14r2, 30>;
    /* Filter bits */
    using f14r2_fb31 = lp::assoc_bit<f14r2, 31>;


    /* Filter bank 15 register 1 */
    using f15r1 = lp::io_register<lp::u32_t, base_address + 0x2b8>;
    /* Filter bits */
    using f15r1_fb0 = lp::assoc_bit<f15r1, 0>;
    /* Filter bits */
    using f15r1_fb1 = lp::assoc_bit<f15r1, 1>;
    /* Filter bits */
    using f15r1_fb2 = lp::assoc_bit<f15r1, 2>;
    /* Filter bits */
    using f15r1_fb3 = lp::assoc_bit<f15r1, 3>;
    /* Filter bits */
    using f15r1_fb4 = lp::assoc_bit<f15r1, 4>;
    /* Filter bits */
    using f15r1_fb5 = lp::assoc_bit<f15r1, 5>;
    /* Filter bits */
    using f15r1_fb6 = lp::assoc_bit<f15r1, 6>;
    /* Filter bits */
    using f15r1_fb7 = lp::assoc_bit<f15r1, 7>;
    /* Filter bits */
    using f15r1_fb8 = lp::assoc_bit<f15r1, 8>;
    /* Filter bits */
    using f15r1_fb9 = lp::assoc_bit<f15r1, 9>;
    /* Filter bits */
    using f15r1_fb10 = lp::assoc_bit<f15r1, 10>;
    /* Filter bits */
    using f15r1_fb11 = lp::assoc_bit<f15r1, 11>;
    /* Filter bits */
    using f15r1_fb12 = lp::assoc_bit<f15r1, 12>;
    /* Filter bits */
    using f15r1_fb13 = lp::assoc_bit<f15r1, 13>;
    /* Filter bits */
    using f15r1_fb14 = lp::assoc_bit<f15r1, 14>;
    /* Filter bits */
    using f15r1_fb15 = lp::assoc_bit<f15r1, 15>;
    /* Filter bits */
    using f15r1_fb16 = lp::assoc_bit<f15r1, 16>;
    /* Filter bits */
    using f15r1_fb17 = lp::assoc_bit<f15r1, 17>;
    /* Filter bits */
    using f15r1_fb18 = lp::assoc_bit<f15r1, 18>;
    /* Filter bits */
    using f15r1_fb19 = lp::assoc_bit<f15r1, 19>;
    /* Filter bits */
    using f15r1_fb20 = lp::assoc_bit<f15r1, 20>;
    /* Filter bits */
    using f15r1_fb21 = lp::assoc_bit<f15r1, 21>;
    /* Filter bits */
    using f15r1_fb22 = lp::assoc_bit<f15r1, 22>;
    /* Filter bits */
    using f15r1_fb23 = lp::assoc_bit<f15r1, 23>;
    /* Filter bits */
    using f15r1_fb24 = lp::assoc_bit<f15r1, 24>;
    /* Filter bits */
    using f15r1_fb25 = lp::assoc_bit<f15r1, 25>;
    /* Filter bits */
    using f15r1_fb26 = lp::assoc_bit<f15r1, 26>;
    /* Filter bits */
    using f15r1_fb27 = lp::assoc_bit<f15r1, 27>;
    /* Filter bits */
    using f15r1_fb28 = lp::assoc_bit<f15r1, 28>;
    /* Filter bits */
    using f15r1_fb29 = lp::assoc_bit<f15r1, 29>;
    /* Filter bits */
    using f15r1_fb30 = lp::assoc_bit<f15r1, 30>;
    /* Filter bits */
    using f15r1_fb31 = lp::assoc_bit<f15r1, 31>;


    /* Filter bank 15 register 2 */
    using f15r2 = lp::io_register<lp::u32_t, base_address + 0x2bc>;
    /* Filter bits */
    using f15r2_fb0 = lp::assoc_bit<f15r2, 0>;
    /* Filter bits */
    using f15r2_fb1 = lp::assoc_bit<f15r2, 1>;
    /* Filter bits */
    using f15r2_fb2 = lp::assoc_bit<f15r2, 2>;
    /* Filter bits */
    using f15r2_fb3 = lp::assoc_bit<f15r2, 3>;
    /* Filter bits */
    using f15r2_fb4 = lp::assoc_bit<f15r2, 4>;
    /* Filter bits */
    using f15r2_fb5 = lp::assoc_bit<f15r2, 5>;
    /* Filter bits */
    using f15r2_fb6 = lp::assoc_bit<f15r2, 6>;
    /* Filter bits */
    using f15r2_fb7 = lp::assoc_bit<f15r2, 7>;
    /* Filter bits */
    using f15r2_fb8 = lp::assoc_bit<f15r2, 8>;
    /* Filter bits */
    using f15r2_fb9 = lp::assoc_bit<f15r2, 9>;
    /* Filter bits */
    using f15r2_fb10 = lp::assoc_bit<f15r2, 10>;
    /* Filter bits */
    using f15r2_fb11 = lp::assoc_bit<f15r2, 11>;
    /* Filter bits */
    using f15r2_fb12 = lp::assoc_bit<f15r2, 12>;
    /* Filter bits */
    using f15r2_fb13 = lp::assoc_bit<f15r2, 13>;
    /* Filter bits */
    using f15r2_fb14 = lp::assoc_bit<f15r2, 14>;
    /* Filter bits */
    using f15r2_fb15 = lp::assoc_bit<f15r2, 15>;
    /* Filter bits */
    using f15r2_fb16 = lp::assoc_bit<f15r2, 16>;
    /* Filter bits */
    using f15r2_fb17 = lp::assoc_bit<f15r2, 17>;
    /* Filter bits */
    using f15r2_fb18 = lp::assoc_bit<f15r2, 18>;
    /* Filter bits */
    using f15r2_fb19 = lp::assoc_bit<f15r2, 19>;
    /* Filter bits */
    using f15r2_fb20 = lp::assoc_bit<f15r2, 20>;
    /* Filter bits */
    using f15r2_fb21 = lp::assoc_bit<f15r2, 21>;
    /* Filter bits */
    using f15r2_fb22 = lp::assoc_bit<f15r2, 22>;
    /* Filter bits */
    using f15r2_fb23 = lp::assoc_bit<f15r2, 23>;
    /* Filter bits */
    using f15r2_fb24 = lp::assoc_bit<f15r2, 24>;
    /* Filter bits */
    using f15r2_fb25 = lp::assoc_bit<f15r2, 25>;
    /* Filter bits */
    using f15r2_fb26 = lp::assoc_bit<f15r2, 26>;
    /* Filter bits */
    using f15r2_fb27 = lp::assoc_bit<f15r2, 27>;
    /* Filter bits */
    using f15r2_fb28 = lp::assoc_bit<f15r2, 28>;
    /* Filter bits */
    using f15r2_fb29 = lp::assoc_bit<f15r2, 29>;
    /* Filter bits */
    using f15r2_fb30 = lp::assoc_bit<f15r2, 30>;
    /* Filter bits */
    using f15r2_fb31 = lp::assoc_bit<f15r2, 31>;


    /* Filter bank 16 register 1 */
    using f16r1 = lp::io_register<lp::u32_t, base_address + 0x2c0>;
    /* Filter bits */
    using f16r1_fb0 = lp::assoc_bit<f16r1, 0>;
    /* Filter bits */
    using f16r1_fb1 = lp::assoc_bit<f16r1, 1>;
    /* Filter bits */
    using f16r1_fb2 = lp::assoc_bit<f16r1, 2>;
    /* Filter bits */
    using f16r1_fb3 = lp::assoc_bit<f16r1, 3>;
    /* Filter bits */
    using f16r1_fb4 = lp::assoc_bit<f16r1, 4>;
    /* Filter bits */
    using f16r1_fb5 = lp::assoc_bit<f16r1, 5>;
    /* Filter bits */
    using f16r1_fb6 = lp::assoc_bit<f16r1, 6>;
    /* Filter bits */
    using f16r1_fb7 = lp::assoc_bit<f16r1, 7>;
    /* Filter bits */
    using f16r1_fb8 = lp::assoc_bit<f16r1, 8>;
    /* Filter bits */
    using f16r1_fb9 = lp::assoc_bit<f16r1, 9>;
    /* Filter bits */
    using f16r1_fb10 = lp::assoc_bit<f16r1, 10>;
    /* Filter bits */
    using f16r1_fb11 = lp::assoc_bit<f16r1, 11>;
    /* Filter bits */
    using f16r1_fb12 = lp::assoc_bit<f16r1, 12>;
    /* Filter bits */
    using f16r1_fb13 = lp::assoc_bit<f16r1, 13>;
    /* Filter bits */
    using f16r1_fb14 = lp::assoc_bit<f16r1, 14>;
    /* Filter bits */
    using f16r1_fb15 = lp::assoc_bit<f16r1, 15>;
    /* Filter bits */
    using f16r1_fb16 = lp::assoc_bit<f16r1, 16>;
    /* Filter bits */
    using f16r1_fb17 = lp::assoc_bit<f16r1, 17>;
    /* Filter bits */
    using f16r1_fb18 = lp::assoc_bit<f16r1, 18>;
    /* Filter bits */
    using f16r1_fb19 = lp::assoc_bit<f16r1, 19>;
    /* Filter bits */
    using f16r1_fb20 = lp::assoc_bit<f16r1, 20>;
    /* Filter bits */
    using f16r1_fb21 = lp::assoc_bit<f16r1, 21>;
    /* Filter bits */
    using f16r1_fb22 = lp::assoc_bit<f16r1, 22>;
    /* Filter bits */
    using f16r1_fb23 = lp::assoc_bit<f16r1, 23>;
    /* Filter bits */
    using f16r1_fb24 = lp::assoc_bit<f16r1, 24>;
    /* Filter bits */
    using f16r1_fb25 = lp::assoc_bit<f16r1, 25>;
    /* Filter bits */
    using f16r1_fb26 = lp::assoc_bit<f16r1, 26>;
    /* Filter bits */
    using f16r1_fb27 = lp::assoc_bit<f16r1, 27>;
    /* Filter bits */
    using f16r1_fb28 = lp::assoc_bit<f16r1, 28>;
    /* Filter bits */
    using f16r1_fb29 = lp::assoc_bit<f16r1, 29>;
    /* Filter bits */
    using f16r1_fb30 = lp::assoc_bit<f16r1, 30>;
    /* Filter bits */
    using f16r1_fb31 = lp::assoc_bit<f16r1, 31>;


    /* Filter bank 16 register 2 */
    using f16r2 = lp::io_register<lp::u32_t, base_address + 0x2c4>;
    /* Filter bits */
    using f16r2_fb0 = lp::assoc_bit<f16r2, 0>;
    /* Filter bits */
    using f16r2_fb1 = lp::assoc_bit<f16r2, 1>;
    /* Filter bits */
    using f16r2_fb2 = lp::assoc_bit<f16r2, 2>;
    /* Filter bits */
    using f16r2_fb3 = lp::assoc_bit<f16r2, 3>;
    /* Filter bits */
    using f16r2_fb4 = lp::assoc_bit<f16r2, 4>;
    /* Filter bits */
    using f16r2_fb5 = lp::assoc_bit<f16r2, 5>;
    /* Filter bits */
    using f16r2_fb6 = lp::assoc_bit<f16r2, 6>;
    /* Filter bits */
    using f16r2_fb7 = lp::assoc_bit<f16r2, 7>;
    /* Filter bits */
    using f16r2_fb8 = lp::assoc_bit<f16r2, 8>;
    /* Filter bits */
    using f16r2_fb9 = lp::assoc_bit<f16r2, 9>;
    /* Filter bits */
    using f16r2_fb10 = lp::assoc_bit<f16r2, 10>;
    /* Filter bits */
    using f16r2_fb11 = lp::assoc_bit<f16r2, 11>;
    /* Filter bits */
    using f16r2_fb12 = lp::assoc_bit<f16r2, 12>;
    /* Filter bits */
    using f16r2_fb13 = lp::assoc_bit<f16r2, 13>;
    /* Filter bits */
    using f16r2_fb14 = lp::assoc_bit<f16r2, 14>;
    /* Filter bits */
    using f16r2_fb15 = lp::assoc_bit<f16r2, 15>;
    /* Filter bits */
    using f16r2_fb16 = lp::assoc_bit<f16r2, 16>;
    /* Filter bits */
    using f16r2_fb17 = lp::assoc_bit<f16r2, 17>;
    /* Filter bits */
    using f16r2_fb18 = lp::assoc_bit<f16r2, 18>;
    /* Filter bits */
    using f16r2_fb19 = lp::assoc_bit<f16r2, 19>;
    /* Filter bits */
    using f16r2_fb20 = lp::assoc_bit<f16r2, 20>;
    /* Filter bits */
    using f16r2_fb21 = lp::assoc_bit<f16r2, 21>;
    /* Filter bits */
    using f16r2_fb22 = lp::assoc_bit<f16r2, 22>;
    /* Filter bits */
    using f16r2_fb23 = lp::assoc_bit<f16r2, 23>;
    /* Filter bits */
    using f16r2_fb24 = lp::assoc_bit<f16r2, 24>;
    /* Filter bits */
    using f16r2_fb25 = lp::assoc_bit<f16r2, 25>;
    /* Filter bits */
    using f16r2_fb26 = lp::assoc_bit<f16r2, 26>;
    /* Filter bits */
    using f16r2_fb27 = lp::assoc_bit<f16r2, 27>;
    /* Filter bits */
    using f16r2_fb28 = lp::assoc_bit<f16r2, 28>;
    /* Filter bits */
    using f16r2_fb29 = lp::assoc_bit<f16r2, 29>;
    /* Filter bits */
    using f16r2_fb30 = lp::assoc_bit<f16r2, 30>;
    /* Filter bits */
    using f16r2_fb31 = lp::assoc_bit<f16r2, 31>;


    /* Filter bank 17 register 1 */
    using f17r1 = lp::io_register<lp::u32_t, base_address + 0x2c8>;
    /* Filter bits */
    using f17r1_fb0 = lp::assoc_bit<f17r1, 0>;
    /* Filter bits */
    using f17r1_fb1 = lp::assoc_bit<f17r1, 1>;
    /* Filter bits */
    using f17r1_fb2 = lp::assoc_bit<f17r1, 2>;
    /* Filter bits */
    using f17r1_fb3 = lp::assoc_bit<f17r1, 3>;
    /* Filter bits */
    using f17r1_fb4 = lp::assoc_bit<f17r1, 4>;
    /* Filter bits */
    using f17r1_fb5 = lp::assoc_bit<f17r1, 5>;
    /* Filter bits */
    using f17r1_fb6 = lp::assoc_bit<f17r1, 6>;
    /* Filter bits */
    using f17r1_fb7 = lp::assoc_bit<f17r1, 7>;
    /* Filter bits */
    using f17r1_fb8 = lp::assoc_bit<f17r1, 8>;
    /* Filter bits */
    using f17r1_fb9 = lp::assoc_bit<f17r1, 9>;
    /* Filter bits */
    using f17r1_fb10 = lp::assoc_bit<f17r1, 10>;
    /* Filter bits */
    using f17r1_fb11 = lp::assoc_bit<f17r1, 11>;
    /* Filter bits */
    using f17r1_fb12 = lp::assoc_bit<f17r1, 12>;
    /* Filter bits */
    using f17r1_fb13 = lp::assoc_bit<f17r1, 13>;
    /* Filter bits */
    using f17r1_fb14 = lp::assoc_bit<f17r1, 14>;
    /* Filter bits */
    using f17r1_fb15 = lp::assoc_bit<f17r1, 15>;
    /* Filter bits */
    using f17r1_fb16 = lp::assoc_bit<f17r1, 16>;
    /* Filter bits */
    using f17r1_fb17 = lp::assoc_bit<f17r1, 17>;
    /* Filter bits */
    using f17r1_fb18 = lp::assoc_bit<f17r1, 18>;
    /* Filter bits */
    using f17r1_fb19 = lp::assoc_bit<f17r1, 19>;
    /* Filter bits */
    using f17r1_fb20 = lp::assoc_bit<f17r1, 20>;
    /* Filter bits */
    using f17r1_fb21 = lp::assoc_bit<f17r1, 21>;
    /* Filter bits */
    using f17r1_fb22 = lp::assoc_bit<f17r1, 22>;
    /* Filter bits */
    using f17r1_fb23 = lp::assoc_bit<f17r1, 23>;
    /* Filter bits */
    using f17r1_fb24 = lp::assoc_bit<f17r1, 24>;
    /* Filter bits */
    using f17r1_fb25 = lp::assoc_bit<f17r1, 25>;
    /* Filter bits */
    using f17r1_fb26 = lp::assoc_bit<f17r1, 26>;
    /* Filter bits */
    using f17r1_fb27 = lp::assoc_bit<f17r1, 27>;
    /* Filter bits */
    using f17r1_fb28 = lp::assoc_bit<f17r1, 28>;
    /* Filter bits */
    using f17r1_fb29 = lp::assoc_bit<f17r1, 29>;
    /* Filter bits */
    using f17r1_fb30 = lp::assoc_bit<f17r1, 30>;
    /* Filter bits */
    using f17r1_fb31 = lp::assoc_bit<f17r1, 31>;


    /* Filter bank 17 register 2 */
    using f17r2 = lp::io_register<lp::u32_t, base_address + 0x2cc>;
    /* Filter bits */
    using f17r2_fb0 = lp::assoc_bit<f17r2, 0>;
    /* Filter bits */
    using f17r2_fb1 = lp::assoc_bit<f17r2, 1>;
    /* Filter bits */
    using f17r2_fb2 = lp::assoc_bit<f17r2, 2>;
    /* Filter bits */
    using f17r2_fb3 = lp::assoc_bit<f17r2, 3>;
    /* Filter bits */
    using f17r2_fb4 = lp::assoc_bit<f17r2, 4>;
    /* Filter bits */
    using f17r2_fb5 = lp::assoc_bit<f17r2, 5>;
    /* Filter bits */
    using f17r2_fb6 = lp::assoc_bit<f17r2, 6>;
    /* Filter bits */
    using f17r2_fb7 = lp::assoc_bit<f17r2, 7>;
    /* Filter bits */
    using f17r2_fb8 = lp::assoc_bit<f17r2, 8>;
    /* Filter bits */
    using f17r2_fb9 = lp::assoc_bit<f17r2, 9>;
    /* Filter bits */
    using f17r2_fb10 = lp::assoc_bit<f17r2, 10>;
    /* Filter bits */
    using f17r2_fb11 = lp::assoc_bit<f17r2, 11>;
    /* Filter bits */
    using f17r2_fb12 = lp::assoc_bit<f17r2, 12>;
    /* Filter bits */
    using f17r2_fb13 = lp::assoc_bit<f17r2, 13>;
    /* Filter bits */
    using f17r2_fb14 = lp::assoc_bit<f17r2, 14>;
    /* Filter bits */
    using f17r2_fb15 = lp::assoc_bit<f17r2, 15>;
    /* Filter bits */
    using f17r2_fb16 = lp::assoc_bit<f17r2, 16>;
    /* Filter bits */
    using f17r2_fb17 = lp::assoc_bit<f17r2, 17>;
    /* Filter bits */
    using f17r2_fb18 = lp::assoc_bit<f17r2, 18>;
    /* Filter bits */
    using f17r2_fb19 = lp::assoc_bit<f17r2, 19>;
    /* Filter bits */
    using f17r2_fb20 = lp::assoc_bit<f17r2, 20>;
    /* Filter bits */
    using f17r2_fb21 = lp::assoc_bit<f17r2, 21>;
    /* Filter bits */
    using f17r2_fb22 = lp::assoc_bit<f17r2, 22>;
    /* Filter bits */
    using f17r2_fb23 = lp::assoc_bit<f17r2, 23>;
    /* Filter bits */
    using f17r2_fb24 = lp::assoc_bit<f17r2, 24>;
    /* Filter bits */
    using f17r2_fb25 = lp::assoc_bit<f17r2, 25>;
    /* Filter bits */
    using f17r2_fb26 = lp::assoc_bit<f17r2, 26>;
    /* Filter bits */
    using f17r2_fb27 = lp::assoc_bit<f17r2, 27>;
    /* Filter bits */
    using f17r2_fb28 = lp::assoc_bit<f17r2, 28>;
    /* Filter bits */
    using f17r2_fb29 = lp::assoc_bit<f17r2, 29>;
    /* Filter bits */
    using f17r2_fb30 = lp::assoc_bit<f17r2, 30>;
    /* Filter bits */
    using f17r2_fb31 = lp::assoc_bit<f17r2, 31>;


    /* Filter bank 18 register 1 */
    using f18r1 = lp::io_register<lp::u32_t, base_address + 0x2d0>;
    /* Filter bits */
    using f18r1_fb0 = lp::assoc_bit<f18r1, 0>;
    /* Filter bits */
    using f18r1_fb1 = lp::assoc_bit<f18r1, 1>;
    /* Filter bits */
    using f18r1_fb2 = lp::assoc_bit<f18r1, 2>;
    /* Filter bits */
    using f18r1_fb3 = lp::assoc_bit<f18r1, 3>;
    /* Filter bits */
    using f18r1_fb4 = lp::assoc_bit<f18r1, 4>;
    /* Filter bits */
    using f18r1_fb5 = lp::assoc_bit<f18r1, 5>;
    /* Filter bits */
    using f18r1_fb6 = lp::assoc_bit<f18r1, 6>;
    /* Filter bits */
    using f18r1_fb7 = lp::assoc_bit<f18r1, 7>;
    /* Filter bits */
    using f18r1_fb8 = lp::assoc_bit<f18r1, 8>;
    /* Filter bits */
    using f18r1_fb9 = lp::assoc_bit<f18r1, 9>;
    /* Filter bits */
    using f18r1_fb10 = lp::assoc_bit<f18r1, 10>;
    /* Filter bits */
    using f18r1_fb11 = lp::assoc_bit<f18r1, 11>;
    /* Filter bits */
    using f18r1_fb12 = lp::assoc_bit<f18r1, 12>;
    /* Filter bits */
    using f18r1_fb13 = lp::assoc_bit<f18r1, 13>;
    /* Filter bits */
    using f18r1_fb14 = lp::assoc_bit<f18r1, 14>;
    /* Filter bits */
    using f18r1_fb15 = lp::assoc_bit<f18r1, 15>;
    /* Filter bits */
    using f18r1_fb16 = lp::assoc_bit<f18r1, 16>;
    /* Filter bits */
    using f18r1_fb17 = lp::assoc_bit<f18r1, 17>;
    /* Filter bits */
    using f18r1_fb18 = lp::assoc_bit<f18r1, 18>;
    /* Filter bits */
    using f18r1_fb19 = lp::assoc_bit<f18r1, 19>;
    /* Filter bits */
    using f18r1_fb20 = lp::assoc_bit<f18r1, 20>;
    /* Filter bits */
    using f18r1_fb21 = lp::assoc_bit<f18r1, 21>;
    /* Filter bits */
    using f18r1_fb22 = lp::assoc_bit<f18r1, 22>;
    /* Filter bits */
    using f18r1_fb23 = lp::assoc_bit<f18r1, 23>;
    /* Filter bits */
    using f18r1_fb24 = lp::assoc_bit<f18r1, 24>;
    /* Filter bits */
    using f18r1_fb25 = lp::assoc_bit<f18r1, 25>;
    /* Filter bits */
    using f18r1_fb26 = lp::assoc_bit<f18r1, 26>;
    /* Filter bits */
    using f18r1_fb27 = lp::assoc_bit<f18r1, 27>;
    /* Filter bits */
    using f18r1_fb28 = lp::assoc_bit<f18r1, 28>;
    /* Filter bits */
    using f18r1_fb29 = lp::assoc_bit<f18r1, 29>;
    /* Filter bits */
    using f18r1_fb30 = lp::assoc_bit<f18r1, 30>;
    /* Filter bits */
    using f18r1_fb31 = lp::assoc_bit<f18r1, 31>;


    /* Filter bank 18 register 2 */
    using f18r2 = lp::io_register<lp::u32_t, base_address + 0x2d4>;
    /* Filter bits */
    using f18r2_fb0 = lp::assoc_bit<f18r2, 0>;
    /* Filter bits */
    using f18r2_fb1 = lp::assoc_bit<f18r2, 1>;
    /* Filter bits */
    using f18r2_fb2 = lp::assoc_bit<f18r2, 2>;
    /* Filter bits */
    using f18r2_fb3 = lp::assoc_bit<f18r2, 3>;
    /* Filter bits */
    using f18r2_fb4 = lp::assoc_bit<f18r2, 4>;
    /* Filter bits */
    using f18r2_fb5 = lp::assoc_bit<f18r2, 5>;
    /* Filter bits */
    using f18r2_fb6 = lp::assoc_bit<f18r2, 6>;
    /* Filter bits */
    using f18r2_fb7 = lp::assoc_bit<f18r2, 7>;
    /* Filter bits */
    using f18r2_fb8 = lp::assoc_bit<f18r2, 8>;
    /* Filter bits */
    using f18r2_fb9 = lp::assoc_bit<f18r2, 9>;
    /* Filter bits */
    using f18r2_fb10 = lp::assoc_bit<f18r2, 10>;
    /* Filter bits */
    using f18r2_fb11 = lp::assoc_bit<f18r2, 11>;
    /* Filter bits */
    using f18r2_fb12 = lp::assoc_bit<f18r2, 12>;
    /* Filter bits */
    using f18r2_fb13 = lp::assoc_bit<f18r2, 13>;
    /* Filter bits */
    using f18r2_fb14 = lp::assoc_bit<f18r2, 14>;
    /* Filter bits */
    using f18r2_fb15 = lp::assoc_bit<f18r2, 15>;
    /* Filter bits */
    using f18r2_fb16 = lp::assoc_bit<f18r2, 16>;
    /* Filter bits */
    using f18r2_fb17 = lp::assoc_bit<f18r2, 17>;
    /* Filter bits */
    using f18r2_fb18 = lp::assoc_bit<f18r2, 18>;
    /* Filter bits */
    using f18r2_fb19 = lp::assoc_bit<f18r2, 19>;
    /* Filter bits */
    using f18r2_fb20 = lp::assoc_bit<f18r2, 20>;
    /* Filter bits */
    using f18r2_fb21 = lp::assoc_bit<f18r2, 21>;
    /* Filter bits */
    using f18r2_fb22 = lp::assoc_bit<f18r2, 22>;
    /* Filter bits */
    using f18r2_fb23 = lp::assoc_bit<f18r2, 23>;
    /* Filter bits */
    using f18r2_fb24 = lp::assoc_bit<f18r2, 24>;
    /* Filter bits */
    using f18r2_fb25 = lp::assoc_bit<f18r2, 25>;
    /* Filter bits */
    using f18r2_fb26 = lp::assoc_bit<f18r2, 26>;
    /* Filter bits */
    using f18r2_fb27 = lp::assoc_bit<f18r2, 27>;
    /* Filter bits */
    using f18r2_fb28 = lp::assoc_bit<f18r2, 28>;
    /* Filter bits */
    using f18r2_fb29 = lp::assoc_bit<f18r2, 29>;
    /* Filter bits */
    using f18r2_fb30 = lp::assoc_bit<f18r2, 30>;
    /* Filter bits */
    using f18r2_fb31 = lp::assoc_bit<f18r2, 31>;


    /* Filter bank 19 register 1 */
    using f19r1 = lp::io_register<lp::u32_t, base_address + 0x2d8>;
    /* Filter bits */
    using f19r1_fb0 = lp::assoc_bit<f19r1, 0>;
    /* Filter bits */
    using f19r1_fb1 = lp::assoc_bit<f19r1, 1>;
    /* Filter bits */
    using f19r1_fb2 = lp::assoc_bit<f19r1, 2>;
    /* Filter bits */
    using f19r1_fb3 = lp::assoc_bit<f19r1, 3>;
    /* Filter bits */
    using f19r1_fb4 = lp::assoc_bit<f19r1, 4>;
    /* Filter bits */
    using f19r1_fb5 = lp::assoc_bit<f19r1, 5>;
    /* Filter bits */
    using f19r1_fb6 = lp::assoc_bit<f19r1, 6>;
    /* Filter bits */
    using f19r1_fb7 = lp::assoc_bit<f19r1, 7>;
    /* Filter bits */
    using f19r1_fb8 = lp::assoc_bit<f19r1, 8>;
    /* Filter bits */
    using f19r1_fb9 = lp::assoc_bit<f19r1, 9>;
    /* Filter bits */
    using f19r1_fb10 = lp::assoc_bit<f19r1, 10>;
    /* Filter bits */
    using f19r1_fb11 = lp::assoc_bit<f19r1, 11>;
    /* Filter bits */
    using f19r1_fb12 = lp::assoc_bit<f19r1, 12>;
    /* Filter bits */
    using f19r1_fb13 = lp::assoc_bit<f19r1, 13>;
    /* Filter bits */
    using f19r1_fb14 = lp::assoc_bit<f19r1, 14>;
    /* Filter bits */
    using f19r1_fb15 = lp::assoc_bit<f19r1, 15>;
    /* Filter bits */
    using f19r1_fb16 = lp::assoc_bit<f19r1, 16>;
    /* Filter bits */
    using f19r1_fb17 = lp::assoc_bit<f19r1, 17>;
    /* Filter bits */
    using f19r1_fb18 = lp::assoc_bit<f19r1, 18>;
    /* Filter bits */
    using f19r1_fb19 = lp::assoc_bit<f19r1, 19>;
    /* Filter bits */
    using f19r1_fb20 = lp::assoc_bit<f19r1, 20>;
    /* Filter bits */
    using f19r1_fb21 = lp::assoc_bit<f19r1, 21>;
    /* Filter bits */
    using f19r1_fb22 = lp::assoc_bit<f19r1, 22>;
    /* Filter bits */
    using f19r1_fb23 = lp::assoc_bit<f19r1, 23>;
    /* Filter bits */
    using f19r1_fb24 = lp::assoc_bit<f19r1, 24>;
    /* Filter bits */
    using f19r1_fb25 = lp::assoc_bit<f19r1, 25>;
    /* Filter bits */
    using f19r1_fb26 = lp::assoc_bit<f19r1, 26>;
    /* Filter bits */
    using f19r1_fb27 = lp::assoc_bit<f19r1, 27>;
    /* Filter bits */
    using f19r1_fb28 = lp::assoc_bit<f19r1, 28>;
    /* Filter bits */
    using f19r1_fb29 = lp::assoc_bit<f19r1, 29>;
    /* Filter bits */
    using f19r1_fb30 = lp::assoc_bit<f19r1, 30>;
    /* Filter bits */
    using f19r1_fb31 = lp::assoc_bit<f19r1, 31>;


    /* Filter bank 19 register 2 */
    using f19r2 = lp::io_register<lp::u32_t, base_address + 0x2dc>;
    /* Filter bits */
    using f19r2_fb0 = lp::assoc_bit<f19r2, 0>;
    /* Filter bits */
    using f19r2_fb1 = lp::assoc_bit<f19r2, 1>;
    /* Filter bits */
    using f19r2_fb2 = lp::assoc_bit<f19r2, 2>;
    /* Filter bits */
    using f19r2_fb3 = lp::assoc_bit<f19r2, 3>;
    /* Filter bits */
    using f19r2_fb4 = lp::assoc_bit<f19r2, 4>;
    /* Filter bits */
    using f19r2_fb5 = lp::assoc_bit<f19r2, 5>;
    /* Filter bits */
    using f19r2_fb6 = lp::assoc_bit<f19r2, 6>;
    /* Filter bits */
    using f19r2_fb7 = lp::assoc_bit<f19r2, 7>;
    /* Filter bits */
    using f19r2_fb8 = lp::assoc_bit<f19r2, 8>;
    /* Filter bits */
    using f19r2_fb9 = lp::assoc_bit<f19r2, 9>;
    /* Filter bits */
    using f19r2_fb10 = lp::assoc_bit<f19r2, 10>;
    /* Filter bits */
    using f19r2_fb11 = lp::assoc_bit<f19r2, 11>;
    /* Filter bits */
    using f19r2_fb12 = lp::assoc_bit<f19r2, 12>;
    /* Filter bits */
    using f19r2_fb13 = lp::assoc_bit<f19r2, 13>;
    /* Filter bits */
    using f19r2_fb14 = lp::assoc_bit<f19r2, 14>;
    /* Filter bits */
    using f19r2_fb15 = lp::assoc_bit<f19r2, 15>;
    /* Filter bits */
    using f19r2_fb16 = lp::assoc_bit<f19r2, 16>;
    /* Filter bits */
    using f19r2_fb17 = lp::assoc_bit<f19r2, 17>;
    /* Filter bits */
    using f19r2_fb18 = lp::assoc_bit<f19r2, 18>;
    /* Filter bits */
    using f19r2_fb19 = lp::assoc_bit<f19r2, 19>;
    /* Filter bits */
    using f19r2_fb20 = lp::assoc_bit<f19r2, 20>;
    /* Filter bits */
    using f19r2_fb21 = lp::assoc_bit<f19r2, 21>;
    /* Filter bits */
    using f19r2_fb22 = lp::assoc_bit<f19r2, 22>;
    /* Filter bits */
    using f19r2_fb23 = lp::assoc_bit<f19r2, 23>;
    /* Filter bits */
    using f19r2_fb24 = lp::assoc_bit<f19r2, 24>;
    /* Filter bits */
    using f19r2_fb25 = lp::assoc_bit<f19r2, 25>;
    /* Filter bits */
    using f19r2_fb26 = lp::assoc_bit<f19r2, 26>;
    /* Filter bits */
    using f19r2_fb27 = lp::assoc_bit<f19r2, 27>;
    /* Filter bits */
    using f19r2_fb28 = lp::assoc_bit<f19r2, 28>;
    /* Filter bits */
    using f19r2_fb29 = lp::assoc_bit<f19r2, 29>;
    /* Filter bits */
    using f19r2_fb30 = lp::assoc_bit<f19r2, 30>;
    /* Filter bits */
    using f19r2_fb31 = lp::assoc_bit<f19r2, 31>;


    /* Filter bank 20 register 1 */
    using f20r1 = lp::io_register<lp::u32_t, base_address + 0x2e0>;
    /* Filter bits */
    using f20r1_fb0 = lp::assoc_bit<f20r1, 0>;
    /* Filter bits */
    using f20r1_fb1 = lp::assoc_bit<f20r1, 1>;
    /* Filter bits */
    using f20r1_fb2 = lp::assoc_bit<f20r1, 2>;
    /* Filter bits */
    using f20r1_fb3 = lp::assoc_bit<f20r1, 3>;
    /* Filter bits */
    using f20r1_fb4 = lp::assoc_bit<f20r1, 4>;
    /* Filter bits */
    using f20r1_fb5 = lp::assoc_bit<f20r1, 5>;
    /* Filter bits */
    using f20r1_fb6 = lp::assoc_bit<f20r1, 6>;
    /* Filter bits */
    using f20r1_fb7 = lp::assoc_bit<f20r1, 7>;
    /* Filter bits */
    using f20r1_fb8 = lp::assoc_bit<f20r1, 8>;
    /* Filter bits */
    using f20r1_fb9 = lp::assoc_bit<f20r1, 9>;
    /* Filter bits */
    using f20r1_fb10 = lp::assoc_bit<f20r1, 10>;
    /* Filter bits */
    using f20r1_fb11 = lp::assoc_bit<f20r1, 11>;
    /* Filter bits */
    using f20r1_fb12 = lp::assoc_bit<f20r1, 12>;
    /* Filter bits */
    using f20r1_fb13 = lp::assoc_bit<f20r1, 13>;
    /* Filter bits */
    using f20r1_fb14 = lp::assoc_bit<f20r1, 14>;
    /* Filter bits */
    using f20r1_fb15 = lp::assoc_bit<f20r1, 15>;
    /* Filter bits */
    using f20r1_fb16 = lp::assoc_bit<f20r1, 16>;
    /* Filter bits */
    using f20r1_fb17 = lp::assoc_bit<f20r1, 17>;
    /* Filter bits */
    using f20r1_fb18 = lp::assoc_bit<f20r1, 18>;
    /* Filter bits */
    using f20r1_fb19 = lp::assoc_bit<f20r1, 19>;
    /* Filter bits */
    using f20r1_fb20 = lp::assoc_bit<f20r1, 20>;
    /* Filter bits */
    using f20r1_fb21 = lp::assoc_bit<f20r1, 21>;
    /* Filter bits */
    using f20r1_fb22 = lp::assoc_bit<f20r1, 22>;
    /* Filter bits */
    using f20r1_fb23 = lp::assoc_bit<f20r1, 23>;
    /* Filter bits */
    using f20r1_fb24 = lp::assoc_bit<f20r1, 24>;
    /* Filter bits */
    using f20r1_fb25 = lp::assoc_bit<f20r1, 25>;
    /* Filter bits */
    using f20r1_fb26 = lp::assoc_bit<f20r1, 26>;
    /* Filter bits */
    using f20r1_fb27 = lp::assoc_bit<f20r1, 27>;
    /* Filter bits */
    using f20r1_fb28 = lp::assoc_bit<f20r1, 28>;
    /* Filter bits */
    using f20r1_fb29 = lp::assoc_bit<f20r1, 29>;
    /* Filter bits */
    using f20r1_fb30 = lp::assoc_bit<f20r1, 30>;
    /* Filter bits */
    using f20r1_fb31 = lp::assoc_bit<f20r1, 31>;


    /* Filter bank 20 register 2 */
    using f20r2 = lp::io_register<lp::u32_t, base_address + 0x2e4>;
    /* Filter bits */
    using f20r2_fb0 = lp::assoc_bit<f20r2, 0>;
    /* Filter bits */
    using f20r2_fb1 = lp::assoc_bit<f20r2, 1>;
    /* Filter bits */
    using f20r2_fb2 = lp::assoc_bit<f20r2, 2>;
    /* Filter bits */
    using f20r2_fb3 = lp::assoc_bit<f20r2, 3>;
    /* Filter bits */
    using f20r2_fb4 = lp::assoc_bit<f20r2, 4>;
    /* Filter bits */
    using f20r2_fb5 = lp::assoc_bit<f20r2, 5>;
    /* Filter bits */
    using f20r2_fb6 = lp::assoc_bit<f20r2, 6>;
    /* Filter bits */
    using f20r2_fb7 = lp::assoc_bit<f20r2, 7>;
    /* Filter bits */
    using f20r2_fb8 = lp::assoc_bit<f20r2, 8>;
    /* Filter bits */
    using f20r2_fb9 = lp::assoc_bit<f20r2, 9>;
    /* Filter bits */
    using f20r2_fb10 = lp::assoc_bit<f20r2, 10>;
    /* Filter bits */
    using f20r2_fb11 = lp::assoc_bit<f20r2, 11>;
    /* Filter bits */
    using f20r2_fb12 = lp::assoc_bit<f20r2, 12>;
    /* Filter bits */
    using f20r2_fb13 = lp::assoc_bit<f20r2, 13>;
    /* Filter bits */
    using f20r2_fb14 = lp::assoc_bit<f20r2, 14>;
    /* Filter bits */
    using f20r2_fb15 = lp::assoc_bit<f20r2, 15>;
    /* Filter bits */
    using f20r2_fb16 = lp::assoc_bit<f20r2, 16>;
    /* Filter bits */
    using f20r2_fb17 = lp::assoc_bit<f20r2, 17>;
    /* Filter bits */
    using f20r2_fb18 = lp::assoc_bit<f20r2, 18>;
    /* Filter bits */
    using f20r2_fb19 = lp::assoc_bit<f20r2, 19>;
    /* Filter bits */
    using f20r2_fb20 = lp::assoc_bit<f20r2, 20>;
    /* Filter bits */
    using f20r2_fb21 = lp::assoc_bit<f20r2, 21>;
    /* Filter bits */
    using f20r2_fb22 = lp::assoc_bit<f20r2, 22>;
    /* Filter bits */
    using f20r2_fb23 = lp::assoc_bit<f20r2, 23>;
    /* Filter bits */
    using f20r2_fb24 = lp::assoc_bit<f20r2, 24>;
    /* Filter bits */
    using f20r2_fb25 = lp::assoc_bit<f20r2, 25>;
    /* Filter bits */
    using f20r2_fb26 = lp::assoc_bit<f20r2, 26>;
    /* Filter bits */
    using f20r2_fb27 = lp::assoc_bit<f20r2, 27>;
    /* Filter bits */
    using f20r2_fb28 = lp::assoc_bit<f20r2, 28>;
    /* Filter bits */
    using f20r2_fb29 = lp::assoc_bit<f20r2, 29>;
    /* Filter bits */
    using f20r2_fb30 = lp::assoc_bit<f20r2, 30>;
    /* Filter bits */
    using f20r2_fb31 = lp::assoc_bit<f20r2, 31>;


    /* Filter bank 21 register 1 */
    using f21r1 = lp::io_register<lp::u32_t, base_address + 0x2e8>;
    /* Filter bits */
    using f21r1_fb0 = lp::assoc_bit<f21r1, 0>;
    /* Filter bits */
    using f21r1_fb1 = lp::assoc_bit<f21r1, 1>;
    /* Filter bits */
    using f21r1_fb2 = lp::assoc_bit<f21r1, 2>;
    /* Filter bits */
    using f21r1_fb3 = lp::assoc_bit<f21r1, 3>;
    /* Filter bits */
    using f21r1_fb4 = lp::assoc_bit<f21r1, 4>;
    /* Filter bits */
    using f21r1_fb5 = lp::assoc_bit<f21r1, 5>;
    /* Filter bits */
    using f21r1_fb6 = lp::assoc_bit<f21r1, 6>;
    /* Filter bits */
    using f21r1_fb7 = lp::assoc_bit<f21r1, 7>;
    /* Filter bits */
    using f21r1_fb8 = lp::assoc_bit<f21r1, 8>;
    /* Filter bits */
    using f21r1_fb9 = lp::assoc_bit<f21r1, 9>;
    /* Filter bits */
    using f21r1_fb10 = lp::assoc_bit<f21r1, 10>;
    /* Filter bits */
    using f21r1_fb11 = lp::assoc_bit<f21r1, 11>;
    /* Filter bits */
    using f21r1_fb12 = lp::assoc_bit<f21r1, 12>;
    /* Filter bits */
    using f21r1_fb13 = lp::assoc_bit<f21r1, 13>;
    /* Filter bits */
    using f21r1_fb14 = lp::assoc_bit<f21r1, 14>;
    /* Filter bits */
    using f21r1_fb15 = lp::assoc_bit<f21r1, 15>;
    /* Filter bits */
    using f21r1_fb16 = lp::assoc_bit<f21r1, 16>;
    /* Filter bits */
    using f21r1_fb17 = lp::assoc_bit<f21r1, 17>;
    /* Filter bits */
    using f21r1_fb18 = lp::assoc_bit<f21r1, 18>;
    /* Filter bits */
    using f21r1_fb19 = lp::assoc_bit<f21r1, 19>;
    /* Filter bits */
    using f21r1_fb20 = lp::assoc_bit<f21r1, 20>;
    /* Filter bits */
    using f21r1_fb21 = lp::assoc_bit<f21r1, 21>;
    /* Filter bits */
    using f21r1_fb22 = lp::assoc_bit<f21r1, 22>;
    /* Filter bits */
    using f21r1_fb23 = lp::assoc_bit<f21r1, 23>;
    /* Filter bits */
    using f21r1_fb24 = lp::assoc_bit<f21r1, 24>;
    /* Filter bits */
    using f21r1_fb25 = lp::assoc_bit<f21r1, 25>;
    /* Filter bits */
    using f21r1_fb26 = lp::assoc_bit<f21r1, 26>;
    /* Filter bits */
    using f21r1_fb27 = lp::assoc_bit<f21r1, 27>;
    /* Filter bits */
    using f21r1_fb28 = lp::assoc_bit<f21r1, 28>;
    /* Filter bits */
    using f21r1_fb29 = lp::assoc_bit<f21r1, 29>;
    /* Filter bits */
    using f21r1_fb30 = lp::assoc_bit<f21r1, 30>;
    /* Filter bits */
    using f21r1_fb31 = lp::assoc_bit<f21r1, 31>;


    /* Filter bank 21 register 2 */
    using f21r2 = lp::io_register<lp::u32_t, base_address + 0x2ec>;
    /* Filter bits */
    using f21r2_fb0 = lp::assoc_bit<f21r2, 0>;
    /* Filter bits */
    using f21r2_fb1 = lp::assoc_bit<f21r2, 1>;
    /* Filter bits */
    using f21r2_fb2 = lp::assoc_bit<f21r2, 2>;
    /* Filter bits */
    using f21r2_fb3 = lp::assoc_bit<f21r2, 3>;
    /* Filter bits */
    using f21r2_fb4 = lp::assoc_bit<f21r2, 4>;
    /* Filter bits */
    using f21r2_fb5 = lp::assoc_bit<f21r2, 5>;
    /* Filter bits */
    using f21r2_fb6 = lp::assoc_bit<f21r2, 6>;
    /* Filter bits */
    using f21r2_fb7 = lp::assoc_bit<f21r2, 7>;
    /* Filter bits */
    using f21r2_fb8 = lp::assoc_bit<f21r2, 8>;
    /* Filter bits */
    using f21r2_fb9 = lp::assoc_bit<f21r2, 9>;
    /* Filter bits */
    using f21r2_fb10 = lp::assoc_bit<f21r2, 10>;
    /* Filter bits */
    using f21r2_fb11 = lp::assoc_bit<f21r2, 11>;
    /* Filter bits */
    using f21r2_fb12 = lp::assoc_bit<f21r2, 12>;
    /* Filter bits */
    using f21r2_fb13 = lp::assoc_bit<f21r2, 13>;
    /* Filter bits */
    using f21r2_fb14 = lp::assoc_bit<f21r2, 14>;
    /* Filter bits */
    using f21r2_fb15 = lp::assoc_bit<f21r2, 15>;
    /* Filter bits */
    using f21r2_fb16 = lp::assoc_bit<f21r2, 16>;
    /* Filter bits */
    using f21r2_fb17 = lp::assoc_bit<f21r2, 17>;
    /* Filter bits */
    using f21r2_fb18 = lp::assoc_bit<f21r2, 18>;
    /* Filter bits */
    using f21r2_fb19 = lp::assoc_bit<f21r2, 19>;
    /* Filter bits */
    using f21r2_fb20 = lp::assoc_bit<f21r2, 20>;
    /* Filter bits */
    using f21r2_fb21 = lp::assoc_bit<f21r2, 21>;
    /* Filter bits */
    using f21r2_fb22 = lp::assoc_bit<f21r2, 22>;
    /* Filter bits */
    using f21r2_fb23 = lp::assoc_bit<f21r2, 23>;
    /* Filter bits */
    using f21r2_fb24 = lp::assoc_bit<f21r2, 24>;
    /* Filter bits */
    using f21r2_fb25 = lp::assoc_bit<f21r2, 25>;
    /* Filter bits */
    using f21r2_fb26 = lp::assoc_bit<f21r2, 26>;
    /* Filter bits */
    using f21r2_fb27 = lp::assoc_bit<f21r2, 27>;
    /* Filter bits */
    using f21r2_fb28 = lp::assoc_bit<f21r2, 28>;
    /* Filter bits */
    using f21r2_fb29 = lp::assoc_bit<f21r2, 29>;
    /* Filter bits */
    using f21r2_fb30 = lp::assoc_bit<f21r2, 30>;
    /* Filter bits */
    using f21r2_fb31 = lp::assoc_bit<f21r2, 31>;


    /* Filter bank 22 register 1 */
    using f22r1 = lp::io_register<lp::u32_t, base_address + 0x2f0>;
    /* Filter bits */
    using f22r1_fb0 = lp::assoc_bit<f22r1, 0>;
    /* Filter bits */
    using f22r1_fb1 = lp::assoc_bit<f22r1, 1>;
    /* Filter bits */
    using f22r1_fb2 = lp::assoc_bit<f22r1, 2>;
    /* Filter bits */
    using f22r1_fb3 = lp::assoc_bit<f22r1, 3>;
    /* Filter bits */
    using f22r1_fb4 = lp::assoc_bit<f22r1, 4>;
    /* Filter bits */
    using f22r1_fb5 = lp::assoc_bit<f22r1, 5>;
    /* Filter bits */
    using f22r1_fb6 = lp::assoc_bit<f22r1, 6>;
    /* Filter bits */
    using f22r1_fb7 = lp::assoc_bit<f22r1, 7>;
    /* Filter bits */
    using f22r1_fb8 = lp::assoc_bit<f22r1, 8>;
    /* Filter bits */
    using f22r1_fb9 = lp::assoc_bit<f22r1, 9>;
    /* Filter bits */
    using f22r1_fb10 = lp::assoc_bit<f22r1, 10>;
    /* Filter bits */
    using f22r1_fb11 = lp::assoc_bit<f22r1, 11>;
    /* Filter bits */
    using f22r1_fb12 = lp::assoc_bit<f22r1, 12>;
    /* Filter bits */
    using f22r1_fb13 = lp::assoc_bit<f22r1, 13>;
    /* Filter bits */
    using f22r1_fb14 = lp::assoc_bit<f22r1, 14>;
    /* Filter bits */
    using f22r1_fb15 = lp::assoc_bit<f22r1, 15>;
    /* Filter bits */
    using f22r1_fb16 = lp::assoc_bit<f22r1, 16>;
    /* Filter bits */
    using f22r1_fb17 = lp::assoc_bit<f22r1, 17>;
    /* Filter bits */
    using f22r1_fb18 = lp::assoc_bit<f22r1, 18>;
    /* Filter bits */
    using f22r1_fb19 = lp::assoc_bit<f22r1, 19>;
    /* Filter bits */
    using f22r1_fb20 = lp::assoc_bit<f22r1, 20>;
    /* Filter bits */
    using f22r1_fb21 = lp::assoc_bit<f22r1, 21>;
    /* Filter bits */
    using f22r1_fb22 = lp::assoc_bit<f22r1, 22>;
    /* Filter bits */
    using f22r1_fb23 = lp::assoc_bit<f22r1, 23>;
    /* Filter bits */
    using f22r1_fb24 = lp::assoc_bit<f22r1, 24>;
    /* Filter bits */
    using f22r1_fb25 = lp::assoc_bit<f22r1, 25>;
    /* Filter bits */
    using f22r1_fb26 = lp::assoc_bit<f22r1, 26>;
    /* Filter bits */
    using f22r1_fb27 = lp::assoc_bit<f22r1, 27>;
    /* Filter bits */
    using f22r1_fb28 = lp::assoc_bit<f22r1, 28>;
    /* Filter bits */
    using f22r1_fb29 = lp::assoc_bit<f22r1, 29>;
    /* Filter bits */
    using f22r1_fb30 = lp::assoc_bit<f22r1, 30>;
    /* Filter bits */
    using f22r1_fb31 = lp::assoc_bit<f22r1, 31>;


    /* Filter bank 22 register 2 */
    using f22r2 = lp::io_register<lp::u32_t, base_address + 0x2f4>;
    /* Filter bits */
    using f22r2_fb0 = lp::assoc_bit<f22r2, 0>;
    /* Filter bits */
    using f22r2_fb1 = lp::assoc_bit<f22r2, 1>;
    /* Filter bits */
    using f22r2_fb2 = lp::assoc_bit<f22r2, 2>;
    /* Filter bits */
    using f22r2_fb3 = lp::assoc_bit<f22r2, 3>;
    /* Filter bits */
    using f22r2_fb4 = lp::assoc_bit<f22r2, 4>;
    /* Filter bits */
    using f22r2_fb5 = lp::assoc_bit<f22r2, 5>;
    /* Filter bits */
    using f22r2_fb6 = lp::assoc_bit<f22r2, 6>;
    /* Filter bits */
    using f22r2_fb7 = lp::assoc_bit<f22r2, 7>;
    /* Filter bits */
    using f22r2_fb8 = lp::assoc_bit<f22r2, 8>;
    /* Filter bits */
    using f22r2_fb9 = lp::assoc_bit<f22r2, 9>;
    /* Filter bits */
    using f22r2_fb10 = lp::assoc_bit<f22r2, 10>;
    /* Filter bits */
    using f22r2_fb11 = lp::assoc_bit<f22r2, 11>;
    /* Filter bits */
    using f22r2_fb12 = lp::assoc_bit<f22r2, 12>;
    /* Filter bits */
    using f22r2_fb13 = lp::assoc_bit<f22r2, 13>;
    /* Filter bits */
    using f22r2_fb14 = lp::assoc_bit<f22r2, 14>;
    /* Filter bits */
    using f22r2_fb15 = lp::assoc_bit<f22r2, 15>;
    /* Filter bits */
    using f22r2_fb16 = lp::assoc_bit<f22r2, 16>;
    /* Filter bits */
    using f22r2_fb17 = lp::assoc_bit<f22r2, 17>;
    /* Filter bits */
    using f22r2_fb18 = lp::assoc_bit<f22r2, 18>;
    /* Filter bits */
    using f22r2_fb19 = lp::assoc_bit<f22r2, 19>;
    /* Filter bits */
    using f22r2_fb20 = lp::assoc_bit<f22r2, 20>;
    /* Filter bits */
    using f22r2_fb21 = lp::assoc_bit<f22r2, 21>;
    /* Filter bits */
    using f22r2_fb22 = lp::assoc_bit<f22r2, 22>;
    /* Filter bits */
    using f22r2_fb23 = lp::assoc_bit<f22r2, 23>;
    /* Filter bits */
    using f22r2_fb24 = lp::assoc_bit<f22r2, 24>;
    /* Filter bits */
    using f22r2_fb25 = lp::assoc_bit<f22r2, 25>;
    /* Filter bits */
    using f22r2_fb26 = lp::assoc_bit<f22r2, 26>;
    /* Filter bits */
    using f22r2_fb27 = lp::assoc_bit<f22r2, 27>;
    /* Filter bits */
    using f22r2_fb28 = lp::assoc_bit<f22r2, 28>;
    /* Filter bits */
    using f22r2_fb29 = lp::assoc_bit<f22r2, 29>;
    /* Filter bits */
    using f22r2_fb30 = lp::assoc_bit<f22r2, 30>;
    /* Filter bits */
    using f22r2_fb31 = lp::assoc_bit<f22r2, 31>;


    /* Filter bank 23 register 1 */
    using f23r1 = lp::io_register<lp::u32_t, base_address + 0x2f8>;
    /* Filter bits */
    using f23r1_fb0 = lp::assoc_bit<f23r1, 0>;
    /* Filter bits */
    using f23r1_fb1 = lp::assoc_bit<f23r1, 1>;
    /* Filter bits */
    using f23r1_fb2 = lp::assoc_bit<f23r1, 2>;
    /* Filter bits */
    using f23r1_fb3 = lp::assoc_bit<f23r1, 3>;
    /* Filter bits */
    using f23r1_fb4 = lp::assoc_bit<f23r1, 4>;
    /* Filter bits */
    using f23r1_fb5 = lp::assoc_bit<f23r1, 5>;
    /* Filter bits */
    using f23r1_fb6 = lp::assoc_bit<f23r1, 6>;
    /* Filter bits */
    using f23r1_fb7 = lp::assoc_bit<f23r1, 7>;
    /* Filter bits */
    using f23r1_fb8 = lp::assoc_bit<f23r1, 8>;
    /* Filter bits */
    using f23r1_fb9 = lp::assoc_bit<f23r1, 9>;
    /* Filter bits */
    using f23r1_fb10 = lp::assoc_bit<f23r1, 10>;
    /* Filter bits */
    using f23r1_fb11 = lp::assoc_bit<f23r1, 11>;
    /* Filter bits */
    using f23r1_fb12 = lp::assoc_bit<f23r1, 12>;
    /* Filter bits */
    using f23r1_fb13 = lp::assoc_bit<f23r1, 13>;
    /* Filter bits */
    using f23r1_fb14 = lp::assoc_bit<f23r1, 14>;
    /* Filter bits */
    using f23r1_fb15 = lp::assoc_bit<f23r1, 15>;
    /* Filter bits */
    using f23r1_fb16 = lp::assoc_bit<f23r1, 16>;
    /* Filter bits */
    using f23r1_fb17 = lp::assoc_bit<f23r1, 17>;
    /* Filter bits */
    using f23r1_fb18 = lp::assoc_bit<f23r1, 18>;
    /* Filter bits */
    using f23r1_fb19 = lp::assoc_bit<f23r1, 19>;
    /* Filter bits */
    using f23r1_fb20 = lp::assoc_bit<f23r1, 20>;
    /* Filter bits */
    using f23r1_fb21 = lp::assoc_bit<f23r1, 21>;
    /* Filter bits */
    using f23r1_fb22 = lp::assoc_bit<f23r1, 22>;
    /* Filter bits */
    using f23r1_fb23 = lp::assoc_bit<f23r1, 23>;
    /* Filter bits */
    using f23r1_fb24 = lp::assoc_bit<f23r1, 24>;
    /* Filter bits */
    using f23r1_fb25 = lp::assoc_bit<f23r1, 25>;
    /* Filter bits */
    using f23r1_fb26 = lp::assoc_bit<f23r1, 26>;
    /* Filter bits */
    using f23r1_fb27 = lp::assoc_bit<f23r1, 27>;
    /* Filter bits */
    using f23r1_fb28 = lp::assoc_bit<f23r1, 28>;
    /* Filter bits */
    using f23r1_fb29 = lp::assoc_bit<f23r1, 29>;
    /* Filter bits */
    using f23r1_fb30 = lp::assoc_bit<f23r1, 30>;
    /* Filter bits */
    using f23r1_fb31 = lp::assoc_bit<f23r1, 31>;


    /* Filter bank 23 register 2 */
    using f23r2 = lp::io_register<lp::u32_t, base_address + 0x2fc>;
    /* Filter bits */
    using f23r2_fb0 = lp::assoc_bit<f23r2, 0>;
    /* Filter bits */
    using f23r2_fb1 = lp::assoc_bit<f23r2, 1>;
    /* Filter bits */
    using f23r2_fb2 = lp::assoc_bit<f23r2, 2>;
    /* Filter bits */
    using f23r2_fb3 = lp::assoc_bit<f23r2, 3>;
    /* Filter bits */
    using f23r2_fb4 = lp::assoc_bit<f23r2, 4>;
    /* Filter bits */
    using f23r2_fb5 = lp::assoc_bit<f23r2, 5>;
    /* Filter bits */
    using f23r2_fb6 = lp::assoc_bit<f23r2, 6>;
    /* Filter bits */
    using f23r2_fb7 = lp::assoc_bit<f23r2, 7>;
    /* Filter bits */
    using f23r2_fb8 = lp::assoc_bit<f23r2, 8>;
    /* Filter bits */
    using f23r2_fb9 = lp::assoc_bit<f23r2, 9>;
    /* Filter bits */
    using f23r2_fb10 = lp::assoc_bit<f23r2, 10>;
    /* Filter bits */
    using f23r2_fb11 = lp::assoc_bit<f23r2, 11>;
    /* Filter bits */
    using f23r2_fb12 = lp::assoc_bit<f23r2, 12>;
    /* Filter bits */
    using f23r2_fb13 = lp::assoc_bit<f23r2, 13>;
    /* Filter bits */
    using f23r2_fb14 = lp::assoc_bit<f23r2, 14>;
    /* Filter bits */
    using f23r2_fb15 = lp::assoc_bit<f23r2, 15>;
    /* Filter bits */
    using f23r2_fb16 = lp::assoc_bit<f23r2, 16>;
    /* Filter bits */
    using f23r2_fb17 = lp::assoc_bit<f23r2, 17>;
    /* Filter bits */
    using f23r2_fb18 = lp::assoc_bit<f23r2, 18>;
    /* Filter bits */
    using f23r2_fb19 = lp::assoc_bit<f23r2, 19>;
    /* Filter bits */
    using f23r2_fb20 = lp::assoc_bit<f23r2, 20>;
    /* Filter bits */
    using f23r2_fb21 = lp::assoc_bit<f23r2, 21>;
    /* Filter bits */
    using f23r2_fb22 = lp::assoc_bit<f23r2, 22>;
    /* Filter bits */
    using f23r2_fb23 = lp::assoc_bit<f23r2, 23>;
    /* Filter bits */
    using f23r2_fb24 = lp::assoc_bit<f23r2, 24>;
    /* Filter bits */
    using f23r2_fb25 = lp::assoc_bit<f23r2, 25>;
    /* Filter bits */
    using f23r2_fb26 = lp::assoc_bit<f23r2, 26>;
    /* Filter bits */
    using f23r2_fb27 = lp::assoc_bit<f23r2, 27>;
    /* Filter bits */
    using f23r2_fb28 = lp::assoc_bit<f23r2, 28>;
    /* Filter bits */
    using f23r2_fb29 = lp::assoc_bit<f23r2, 29>;
    /* Filter bits */
    using f23r2_fb30 = lp::assoc_bit<f23r2, 30>;
    /* Filter bits */
    using f23r2_fb31 = lp::assoc_bit<f23r2, 31>;


    /* Filter bank 24 register 1 */
    using f24r1 = lp::io_register<lp::u32_t, base_address + 0x300>;
    /* Filter bits */
    using f24r1_fb0 = lp::assoc_bit<f24r1, 0>;
    /* Filter bits */
    using f24r1_fb1 = lp::assoc_bit<f24r1, 1>;
    /* Filter bits */
    using f24r1_fb2 = lp::assoc_bit<f24r1, 2>;
    /* Filter bits */
    using f24r1_fb3 = lp::assoc_bit<f24r1, 3>;
    /* Filter bits */
    using f24r1_fb4 = lp::assoc_bit<f24r1, 4>;
    /* Filter bits */
    using f24r1_fb5 = lp::assoc_bit<f24r1, 5>;
    /* Filter bits */
    using f24r1_fb6 = lp::assoc_bit<f24r1, 6>;
    /* Filter bits */
    using f24r1_fb7 = lp::assoc_bit<f24r1, 7>;
    /* Filter bits */
    using f24r1_fb8 = lp::assoc_bit<f24r1, 8>;
    /* Filter bits */
    using f24r1_fb9 = lp::assoc_bit<f24r1, 9>;
    /* Filter bits */
    using f24r1_fb10 = lp::assoc_bit<f24r1, 10>;
    /* Filter bits */
    using f24r1_fb11 = lp::assoc_bit<f24r1, 11>;
    /* Filter bits */
    using f24r1_fb12 = lp::assoc_bit<f24r1, 12>;
    /* Filter bits */
    using f24r1_fb13 = lp::assoc_bit<f24r1, 13>;
    /* Filter bits */
    using f24r1_fb14 = lp::assoc_bit<f24r1, 14>;
    /* Filter bits */
    using f24r1_fb15 = lp::assoc_bit<f24r1, 15>;
    /* Filter bits */
    using f24r1_fb16 = lp::assoc_bit<f24r1, 16>;
    /* Filter bits */
    using f24r1_fb17 = lp::assoc_bit<f24r1, 17>;
    /* Filter bits */
    using f24r1_fb18 = lp::assoc_bit<f24r1, 18>;
    /* Filter bits */
    using f24r1_fb19 = lp::assoc_bit<f24r1, 19>;
    /* Filter bits */
    using f24r1_fb20 = lp::assoc_bit<f24r1, 20>;
    /* Filter bits */
    using f24r1_fb21 = lp::assoc_bit<f24r1, 21>;
    /* Filter bits */
    using f24r1_fb22 = lp::assoc_bit<f24r1, 22>;
    /* Filter bits */
    using f24r1_fb23 = lp::assoc_bit<f24r1, 23>;
    /* Filter bits */
    using f24r1_fb24 = lp::assoc_bit<f24r1, 24>;
    /* Filter bits */
    using f24r1_fb25 = lp::assoc_bit<f24r1, 25>;
    /* Filter bits */
    using f24r1_fb26 = lp::assoc_bit<f24r1, 26>;
    /* Filter bits */
    using f24r1_fb27 = lp::assoc_bit<f24r1, 27>;
    /* Filter bits */
    using f24r1_fb28 = lp::assoc_bit<f24r1, 28>;
    /* Filter bits */
    using f24r1_fb29 = lp::assoc_bit<f24r1, 29>;
    /* Filter bits */
    using f24r1_fb30 = lp::assoc_bit<f24r1, 30>;
    /* Filter bits */
    using f24r1_fb31 = lp::assoc_bit<f24r1, 31>;


    /* Filter bank 24 register 2 */
    using f24r2 = lp::io_register<lp::u32_t, base_address + 0x304>;
    /* Filter bits */
    using f24r2_fb0 = lp::assoc_bit<f24r2, 0>;
    /* Filter bits */
    using f24r2_fb1 = lp::assoc_bit<f24r2, 1>;
    /* Filter bits */
    using f24r2_fb2 = lp::assoc_bit<f24r2, 2>;
    /* Filter bits */
    using f24r2_fb3 = lp::assoc_bit<f24r2, 3>;
    /* Filter bits */
    using f24r2_fb4 = lp::assoc_bit<f24r2, 4>;
    /* Filter bits */
    using f24r2_fb5 = lp::assoc_bit<f24r2, 5>;
    /* Filter bits */
    using f24r2_fb6 = lp::assoc_bit<f24r2, 6>;
    /* Filter bits */
    using f24r2_fb7 = lp::assoc_bit<f24r2, 7>;
    /* Filter bits */
    using f24r2_fb8 = lp::assoc_bit<f24r2, 8>;
    /* Filter bits */
    using f24r2_fb9 = lp::assoc_bit<f24r2, 9>;
    /* Filter bits */
    using f24r2_fb10 = lp::assoc_bit<f24r2, 10>;
    /* Filter bits */
    using f24r2_fb11 = lp::assoc_bit<f24r2, 11>;
    /* Filter bits */
    using f24r2_fb12 = lp::assoc_bit<f24r2, 12>;
    /* Filter bits */
    using f24r2_fb13 = lp::assoc_bit<f24r2, 13>;
    /* Filter bits */
    using f24r2_fb14 = lp::assoc_bit<f24r2, 14>;
    /* Filter bits */
    using f24r2_fb15 = lp::assoc_bit<f24r2, 15>;
    /* Filter bits */
    using f24r2_fb16 = lp::assoc_bit<f24r2, 16>;
    /* Filter bits */
    using f24r2_fb17 = lp::assoc_bit<f24r2, 17>;
    /* Filter bits */
    using f24r2_fb18 = lp::assoc_bit<f24r2, 18>;
    /* Filter bits */
    using f24r2_fb19 = lp::assoc_bit<f24r2, 19>;
    /* Filter bits */
    using f24r2_fb20 = lp::assoc_bit<f24r2, 20>;
    /* Filter bits */
    using f24r2_fb21 = lp::assoc_bit<f24r2, 21>;
    /* Filter bits */
    using f24r2_fb22 = lp::assoc_bit<f24r2, 22>;
    /* Filter bits */
    using f24r2_fb23 = lp::assoc_bit<f24r2, 23>;
    /* Filter bits */
    using f24r2_fb24 = lp::assoc_bit<f24r2, 24>;
    /* Filter bits */
    using f24r2_fb25 = lp::assoc_bit<f24r2, 25>;
    /* Filter bits */
    using f24r2_fb26 = lp::assoc_bit<f24r2, 26>;
    /* Filter bits */
    using f24r2_fb27 = lp::assoc_bit<f24r2, 27>;
    /* Filter bits */
    using f24r2_fb28 = lp::assoc_bit<f24r2, 28>;
    /* Filter bits */
    using f24r2_fb29 = lp::assoc_bit<f24r2, 29>;
    /* Filter bits */
    using f24r2_fb30 = lp::assoc_bit<f24r2, 30>;
    /* Filter bits */
    using f24r2_fb31 = lp::assoc_bit<f24r2, 31>;


    /* Filter bank 25 register 1 */
    using f25r1 = lp::io_register<lp::u32_t, base_address + 0x308>;
    /* Filter bits */
    using f25r1_fb0 = lp::assoc_bit<f25r1, 0>;
    /* Filter bits */
    using f25r1_fb1 = lp::assoc_bit<f25r1, 1>;
    /* Filter bits */
    using f25r1_fb2 = lp::assoc_bit<f25r1, 2>;
    /* Filter bits */
    using f25r1_fb3 = lp::assoc_bit<f25r1, 3>;
    /* Filter bits */
    using f25r1_fb4 = lp::assoc_bit<f25r1, 4>;
    /* Filter bits */
    using f25r1_fb5 = lp::assoc_bit<f25r1, 5>;
    /* Filter bits */
    using f25r1_fb6 = lp::assoc_bit<f25r1, 6>;
    /* Filter bits */
    using f25r1_fb7 = lp::assoc_bit<f25r1, 7>;
    /* Filter bits */
    using f25r1_fb8 = lp::assoc_bit<f25r1, 8>;
    /* Filter bits */
    using f25r1_fb9 = lp::assoc_bit<f25r1, 9>;
    /* Filter bits */
    using f25r1_fb10 = lp::assoc_bit<f25r1, 10>;
    /* Filter bits */
    using f25r1_fb11 = lp::assoc_bit<f25r1, 11>;
    /* Filter bits */
    using f25r1_fb12 = lp::assoc_bit<f25r1, 12>;
    /* Filter bits */
    using f25r1_fb13 = lp::assoc_bit<f25r1, 13>;
    /* Filter bits */
    using f25r1_fb14 = lp::assoc_bit<f25r1, 14>;
    /* Filter bits */
    using f25r1_fb15 = lp::assoc_bit<f25r1, 15>;
    /* Filter bits */
    using f25r1_fb16 = lp::assoc_bit<f25r1, 16>;
    /* Filter bits */
    using f25r1_fb17 = lp::assoc_bit<f25r1, 17>;
    /* Filter bits */
    using f25r1_fb18 = lp::assoc_bit<f25r1, 18>;
    /* Filter bits */
    using f25r1_fb19 = lp::assoc_bit<f25r1, 19>;
    /* Filter bits */
    using f25r1_fb20 = lp::assoc_bit<f25r1, 20>;
    /* Filter bits */
    using f25r1_fb21 = lp::assoc_bit<f25r1, 21>;
    /* Filter bits */
    using f25r1_fb22 = lp::assoc_bit<f25r1, 22>;
    /* Filter bits */
    using f25r1_fb23 = lp::assoc_bit<f25r1, 23>;
    /* Filter bits */
    using f25r1_fb24 = lp::assoc_bit<f25r1, 24>;
    /* Filter bits */
    using f25r1_fb25 = lp::assoc_bit<f25r1, 25>;
    /* Filter bits */
    using f25r1_fb26 = lp::assoc_bit<f25r1, 26>;
    /* Filter bits */
    using f25r1_fb27 = lp::assoc_bit<f25r1, 27>;
    /* Filter bits */
    using f25r1_fb28 = lp::assoc_bit<f25r1, 28>;
    /* Filter bits */
    using f25r1_fb29 = lp::assoc_bit<f25r1, 29>;
    /* Filter bits */
    using f25r1_fb30 = lp::assoc_bit<f25r1, 30>;
    /* Filter bits */
    using f25r1_fb31 = lp::assoc_bit<f25r1, 31>;


    /* Filter bank 25 register 2 */
    using f25r2 = lp::io_register<lp::u32_t, base_address + 0x30c>;
    /* Filter bits */
    using f25r2_fb0 = lp::assoc_bit<f25r2, 0>;
    /* Filter bits */
    using f25r2_fb1 = lp::assoc_bit<f25r2, 1>;
    /* Filter bits */
    using f25r2_fb2 = lp::assoc_bit<f25r2, 2>;
    /* Filter bits */
    using f25r2_fb3 = lp::assoc_bit<f25r2, 3>;
    /* Filter bits */
    using f25r2_fb4 = lp::assoc_bit<f25r2, 4>;
    /* Filter bits */
    using f25r2_fb5 = lp::assoc_bit<f25r2, 5>;
    /* Filter bits */
    using f25r2_fb6 = lp::assoc_bit<f25r2, 6>;
    /* Filter bits */
    using f25r2_fb7 = lp::assoc_bit<f25r2, 7>;
    /* Filter bits */
    using f25r2_fb8 = lp::assoc_bit<f25r2, 8>;
    /* Filter bits */
    using f25r2_fb9 = lp::assoc_bit<f25r2, 9>;
    /* Filter bits */
    using f25r2_fb10 = lp::assoc_bit<f25r2, 10>;
    /* Filter bits */
    using f25r2_fb11 = lp::assoc_bit<f25r2, 11>;
    /* Filter bits */
    using f25r2_fb12 = lp::assoc_bit<f25r2, 12>;
    /* Filter bits */
    using f25r2_fb13 = lp::assoc_bit<f25r2, 13>;
    /* Filter bits */
    using f25r2_fb14 = lp::assoc_bit<f25r2, 14>;
    /* Filter bits */
    using f25r2_fb15 = lp::assoc_bit<f25r2, 15>;
    /* Filter bits */
    using f25r2_fb16 = lp::assoc_bit<f25r2, 16>;
    /* Filter bits */
    using f25r2_fb17 = lp::assoc_bit<f25r2, 17>;
    /* Filter bits */
    using f25r2_fb18 = lp::assoc_bit<f25r2, 18>;
    /* Filter bits */
    using f25r2_fb19 = lp::assoc_bit<f25r2, 19>;
    /* Filter bits */
    using f25r2_fb20 = lp::assoc_bit<f25r2, 20>;
    /* Filter bits */
    using f25r2_fb21 = lp::assoc_bit<f25r2, 21>;
    /* Filter bits */
    using f25r2_fb22 = lp::assoc_bit<f25r2, 22>;
    /* Filter bits */
    using f25r2_fb23 = lp::assoc_bit<f25r2, 23>;
    /* Filter bits */
    using f25r2_fb24 = lp::assoc_bit<f25r2, 24>;
    /* Filter bits */
    using f25r2_fb25 = lp::assoc_bit<f25r2, 25>;
    /* Filter bits */
    using f25r2_fb26 = lp::assoc_bit<f25r2, 26>;
    /* Filter bits */
    using f25r2_fb27 = lp::assoc_bit<f25r2, 27>;
    /* Filter bits */
    using f25r2_fb28 = lp::assoc_bit<f25r2, 28>;
    /* Filter bits */
    using f25r2_fb29 = lp::assoc_bit<f25r2, 29>;
    /* Filter bits */
    using f25r2_fb30 = lp::assoc_bit<f25r2, 30>;
    /* Filter bits */
    using f25r2_fb31 = lp::assoc_bit<f25r2, 31>;


    /* Filter bank 26 register 1 */
    using f26r1 = lp::io_register<lp::u32_t, base_address + 0x310>;
    /* Filter bits */
    using f26r1_fb0 = lp::assoc_bit<f26r1, 0>;
    /* Filter bits */
    using f26r1_fb1 = lp::assoc_bit<f26r1, 1>;
    /* Filter bits */
    using f26r1_fb2 = lp::assoc_bit<f26r1, 2>;
    /* Filter bits */
    using f26r1_fb3 = lp::assoc_bit<f26r1, 3>;
    /* Filter bits */
    using f26r1_fb4 = lp::assoc_bit<f26r1, 4>;
    /* Filter bits */
    using f26r1_fb5 = lp::assoc_bit<f26r1, 5>;
    /* Filter bits */
    using f26r1_fb6 = lp::assoc_bit<f26r1, 6>;
    /* Filter bits */
    using f26r1_fb7 = lp::assoc_bit<f26r1, 7>;
    /* Filter bits */
    using f26r1_fb8 = lp::assoc_bit<f26r1, 8>;
    /* Filter bits */
    using f26r1_fb9 = lp::assoc_bit<f26r1, 9>;
    /* Filter bits */
    using f26r1_fb10 = lp::assoc_bit<f26r1, 10>;
    /* Filter bits */
    using f26r1_fb11 = lp::assoc_bit<f26r1, 11>;
    /* Filter bits */
    using f26r1_fb12 = lp::assoc_bit<f26r1, 12>;
    /* Filter bits */
    using f26r1_fb13 = lp::assoc_bit<f26r1, 13>;
    /* Filter bits */
    using f26r1_fb14 = lp::assoc_bit<f26r1, 14>;
    /* Filter bits */
    using f26r1_fb15 = lp::assoc_bit<f26r1, 15>;
    /* Filter bits */
    using f26r1_fb16 = lp::assoc_bit<f26r1, 16>;
    /* Filter bits */
    using f26r1_fb17 = lp::assoc_bit<f26r1, 17>;
    /* Filter bits */
    using f26r1_fb18 = lp::assoc_bit<f26r1, 18>;
    /* Filter bits */
    using f26r1_fb19 = lp::assoc_bit<f26r1, 19>;
    /* Filter bits */
    using f26r1_fb20 = lp::assoc_bit<f26r1, 20>;
    /* Filter bits */
    using f26r1_fb21 = lp::assoc_bit<f26r1, 21>;
    /* Filter bits */
    using f26r1_fb22 = lp::assoc_bit<f26r1, 22>;
    /* Filter bits */
    using f26r1_fb23 = lp::assoc_bit<f26r1, 23>;
    /* Filter bits */
    using f26r1_fb24 = lp::assoc_bit<f26r1, 24>;
    /* Filter bits */
    using f26r1_fb25 = lp::assoc_bit<f26r1, 25>;
    /* Filter bits */
    using f26r1_fb26 = lp::assoc_bit<f26r1, 26>;
    /* Filter bits */
    using f26r1_fb27 = lp::assoc_bit<f26r1, 27>;
    /* Filter bits */
    using f26r1_fb28 = lp::assoc_bit<f26r1, 28>;
    /* Filter bits */
    using f26r1_fb29 = lp::assoc_bit<f26r1, 29>;
    /* Filter bits */
    using f26r1_fb30 = lp::assoc_bit<f26r1, 30>;
    /* Filter bits */
    using f26r1_fb31 = lp::assoc_bit<f26r1, 31>;


    /* Filter bank 26 register 2 */
    using f26r2 = lp::io_register<lp::u32_t, base_address + 0x314>;
    /* Filter bits */
    using f26r2_fb0 = lp::assoc_bit<f26r2, 0>;
    /* Filter bits */
    using f26r2_fb1 = lp::assoc_bit<f26r2, 1>;
    /* Filter bits */
    using f26r2_fb2 = lp::assoc_bit<f26r2, 2>;
    /* Filter bits */
    using f26r2_fb3 = lp::assoc_bit<f26r2, 3>;
    /* Filter bits */
    using f26r2_fb4 = lp::assoc_bit<f26r2, 4>;
    /* Filter bits */
    using f26r2_fb5 = lp::assoc_bit<f26r2, 5>;
    /* Filter bits */
    using f26r2_fb6 = lp::assoc_bit<f26r2, 6>;
    /* Filter bits */
    using f26r2_fb7 = lp::assoc_bit<f26r2, 7>;
    /* Filter bits */
    using f26r2_fb8 = lp::assoc_bit<f26r2, 8>;
    /* Filter bits */
    using f26r2_fb9 = lp::assoc_bit<f26r2, 9>;
    /* Filter bits */
    using f26r2_fb10 = lp::assoc_bit<f26r2, 10>;
    /* Filter bits */
    using f26r2_fb11 = lp::assoc_bit<f26r2, 11>;
    /* Filter bits */
    using f26r2_fb12 = lp::assoc_bit<f26r2, 12>;
    /* Filter bits */
    using f26r2_fb13 = lp::assoc_bit<f26r2, 13>;
    /* Filter bits */
    using f26r2_fb14 = lp::assoc_bit<f26r2, 14>;
    /* Filter bits */
    using f26r2_fb15 = lp::assoc_bit<f26r2, 15>;
    /* Filter bits */
    using f26r2_fb16 = lp::assoc_bit<f26r2, 16>;
    /* Filter bits */
    using f26r2_fb17 = lp::assoc_bit<f26r2, 17>;
    /* Filter bits */
    using f26r2_fb18 = lp::assoc_bit<f26r2, 18>;
    /* Filter bits */
    using f26r2_fb19 = lp::assoc_bit<f26r2, 19>;
    /* Filter bits */
    using f26r2_fb20 = lp::assoc_bit<f26r2, 20>;
    /* Filter bits */
    using f26r2_fb21 = lp::assoc_bit<f26r2, 21>;
    /* Filter bits */
    using f26r2_fb22 = lp::assoc_bit<f26r2, 22>;
    /* Filter bits */
    using f26r2_fb23 = lp::assoc_bit<f26r2, 23>;
    /* Filter bits */
    using f26r2_fb24 = lp::assoc_bit<f26r2, 24>;
    /* Filter bits */
    using f26r2_fb25 = lp::assoc_bit<f26r2, 25>;
    /* Filter bits */
    using f26r2_fb26 = lp::assoc_bit<f26r2, 26>;
    /* Filter bits */
    using f26r2_fb27 = lp::assoc_bit<f26r2, 27>;
    /* Filter bits */
    using f26r2_fb28 = lp::assoc_bit<f26r2, 28>;
    /* Filter bits */
    using f26r2_fb29 = lp::assoc_bit<f26r2, 29>;
    /* Filter bits */
    using f26r2_fb30 = lp::assoc_bit<f26r2, 30>;
    /* Filter bits */
    using f26r2_fb31 = lp::assoc_bit<f26r2, 31>;


    /* Filter bank 27 register 1 */
    using f27r1 = lp::io_register<lp::u32_t, base_address + 0x318>;
    /* Filter bits */
    using f27r1_fb0 = lp::assoc_bit<f27r1, 0>;
    /* Filter bits */
    using f27r1_fb1 = lp::assoc_bit<f27r1, 1>;
    /* Filter bits */
    using f27r1_fb2 = lp::assoc_bit<f27r1, 2>;
    /* Filter bits */
    using f27r1_fb3 = lp::assoc_bit<f27r1, 3>;
    /* Filter bits */
    using f27r1_fb4 = lp::assoc_bit<f27r1, 4>;
    /* Filter bits */
    using f27r1_fb5 = lp::assoc_bit<f27r1, 5>;
    /* Filter bits */
    using f27r1_fb6 = lp::assoc_bit<f27r1, 6>;
    /* Filter bits */
    using f27r1_fb7 = lp::assoc_bit<f27r1, 7>;
    /* Filter bits */
    using f27r1_fb8 = lp::assoc_bit<f27r1, 8>;
    /* Filter bits */
    using f27r1_fb9 = lp::assoc_bit<f27r1, 9>;
    /* Filter bits */
    using f27r1_fb10 = lp::assoc_bit<f27r1, 10>;
    /* Filter bits */
    using f27r1_fb11 = lp::assoc_bit<f27r1, 11>;
    /* Filter bits */
    using f27r1_fb12 = lp::assoc_bit<f27r1, 12>;
    /* Filter bits */
    using f27r1_fb13 = lp::assoc_bit<f27r1, 13>;
    /* Filter bits */
    using f27r1_fb14 = lp::assoc_bit<f27r1, 14>;
    /* Filter bits */
    using f27r1_fb15 = lp::assoc_bit<f27r1, 15>;
    /* Filter bits */
    using f27r1_fb16 = lp::assoc_bit<f27r1, 16>;
    /* Filter bits */
    using f27r1_fb17 = lp::assoc_bit<f27r1, 17>;
    /* Filter bits */
    using f27r1_fb18 = lp::assoc_bit<f27r1, 18>;
    /* Filter bits */
    using f27r1_fb19 = lp::assoc_bit<f27r1, 19>;
    /* Filter bits */
    using f27r1_fb20 = lp::assoc_bit<f27r1, 20>;
    /* Filter bits */
    using f27r1_fb21 = lp::assoc_bit<f27r1, 21>;
    /* Filter bits */
    using f27r1_fb22 = lp::assoc_bit<f27r1, 22>;
    /* Filter bits */
    using f27r1_fb23 = lp::assoc_bit<f27r1, 23>;
    /* Filter bits */
    using f27r1_fb24 = lp::assoc_bit<f27r1, 24>;
    /* Filter bits */
    using f27r1_fb25 = lp::assoc_bit<f27r1, 25>;
    /* Filter bits */
    using f27r1_fb26 = lp::assoc_bit<f27r1, 26>;
    /* Filter bits */
    using f27r1_fb27 = lp::assoc_bit<f27r1, 27>;
    /* Filter bits */
    using f27r1_fb28 = lp::assoc_bit<f27r1, 28>;
    /* Filter bits */
    using f27r1_fb29 = lp::assoc_bit<f27r1, 29>;
    /* Filter bits */
    using f27r1_fb30 = lp::assoc_bit<f27r1, 30>;
    /* Filter bits */
    using f27r1_fb31 = lp::assoc_bit<f27r1, 31>;


    /* Filter bank 27 register 2 */
    using f27r2 = lp::io_register<lp::u32_t, base_address + 0x31c>;
    /* Filter bits */
    using f27r2_fb0 = lp::assoc_bit<f27r2, 0>;
    /* Filter bits */
    using f27r2_fb1 = lp::assoc_bit<f27r2, 1>;
    /* Filter bits */
    using f27r2_fb2 = lp::assoc_bit<f27r2, 2>;
    /* Filter bits */
    using f27r2_fb3 = lp::assoc_bit<f27r2, 3>;
    /* Filter bits */
    using f27r2_fb4 = lp::assoc_bit<f27r2, 4>;
    /* Filter bits */
    using f27r2_fb5 = lp::assoc_bit<f27r2, 5>;
    /* Filter bits */
    using f27r2_fb6 = lp::assoc_bit<f27r2, 6>;
    /* Filter bits */
    using f27r2_fb7 = lp::assoc_bit<f27r2, 7>;
    /* Filter bits */
    using f27r2_fb8 = lp::assoc_bit<f27r2, 8>;
    /* Filter bits */
    using f27r2_fb9 = lp::assoc_bit<f27r2, 9>;
    /* Filter bits */
    using f27r2_fb10 = lp::assoc_bit<f27r2, 10>;
    /* Filter bits */
    using f27r2_fb11 = lp::assoc_bit<f27r2, 11>;
    /* Filter bits */
    using f27r2_fb12 = lp::assoc_bit<f27r2, 12>;
    /* Filter bits */
    using f27r2_fb13 = lp::assoc_bit<f27r2, 13>;
    /* Filter bits */
    using f27r2_fb14 = lp::assoc_bit<f27r2, 14>;
    /* Filter bits */
    using f27r2_fb15 = lp::assoc_bit<f27r2, 15>;
    /* Filter bits */
    using f27r2_fb16 = lp::assoc_bit<f27r2, 16>;
    /* Filter bits */
    using f27r2_fb17 = lp::assoc_bit<f27r2, 17>;
    /* Filter bits */
    using f27r2_fb18 = lp::assoc_bit<f27r2, 18>;
    /* Filter bits */
    using f27r2_fb19 = lp::assoc_bit<f27r2, 19>;
    /* Filter bits */
    using f27r2_fb20 = lp::assoc_bit<f27r2, 20>;
    /* Filter bits */
    using f27r2_fb21 = lp::assoc_bit<f27r2, 21>;
    /* Filter bits */
    using f27r2_fb22 = lp::assoc_bit<f27r2, 22>;
    /* Filter bits */
    using f27r2_fb23 = lp::assoc_bit<f27r2, 23>;
    /* Filter bits */
    using f27r2_fb24 = lp::assoc_bit<f27r2, 24>;
    /* Filter bits */
    using f27r2_fb25 = lp::assoc_bit<f27r2, 25>;
    /* Filter bits */
    using f27r2_fb26 = lp::assoc_bit<f27r2, 26>;
    /* Filter bits */
    using f27r2_fb27 = lp::assoc_bit<f27r2, 27>;
    /* Filter bits */
    using f27r2_fb28 = lp::assoc_bit<f27r2, 28>;
    /* Filter bits */
    using f27r2_fb29 = lp::assoc_bit<f27r2, 29>;
    /* Filter bits */
    using f27r2_fb30 = lp::assoc_bit<f27r2, 30>;
    /* Filter bits */
    using f27r2_fb31 = lp::assoc_bit<f27r2, 31>;


};

using can1 = can_t<0x40006400>;
using can2 = can_t<0x40006800>;

#endif // CAN_HH
