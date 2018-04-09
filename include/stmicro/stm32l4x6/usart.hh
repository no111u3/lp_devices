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
 * Hardware support for usart
 * @file usart.hh
 * @author Boris Vinogradov
 */

#include <associate_bit.hh>
#include <io_register.hh>
#include <types.hh>

#ifndef USART_HH
#define USART_HH

/* Universal synchronous asynchronous receiver
      transmitter */
template <lp::addr_t base_address>
struct usart_t {
    /* Control register 1 */
    using cr1 = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* Word length */
    using cr1_m1 = lp::assoc_bit<cr1, 28>;
    /* End of Block interrupt               enable */
    using cr1_eobie = lp::assoc_bit<cr1, 27>;
    /* Receiver timeout interrupt               enable */
    using cr1_rtoie = lp::assoc_bit<cr1, 26>;
    /* Driver Enable assertion               time */
    using cr1_deat4 = lp::assoc_bit<cr1, 25>;
    /* DEAT3 */
    using cr1_deat3 = lp::assoc_bit<cr1, 24>;
    /* DEAT2 */
    using cr1_deat2 = lp::assoc_bit<cr1, 23>;
    /* DEAT1 */
    using cr1_deat1 = lp::assoc_bit<cr1, 22>;
    /* DEAT0 */
    using cr1_deat0 = lp::assoc_bit<cr1, 21>;
    /* Driver Enable de-assertion               time */
    using cr1_dedt4 = lp::assoc_bit<cr1, 20>;
    /* DEDT3 */
    using cr1_dedt3 = lp::assoc_bit<cr1, 19>;
    /* DEDT2 */
    using cr1_dedt2 = lp::assoc_bit<cr1, 18>;
    /* DEDT1 */
    using cr1_dedt1 = lp::assoc_bit<cr1, 17>;
    /* DEDT0 */
    using cr1_dedt0 = lp::assoc_bit<cr1, 16>;
    /* Oversampling mode */
    using cr1_over8 = lp::assoc_bit<cr1, 15>;
    /* Character match interrupt               enable */
    using cr1_cmie = lp::assoc_bit<cr1, 14>;
    /* Mute mode enable */
    using cr1_mme = lp::assoc_bit<cr1, 13>;
    /* Word length */
    using cr1_m0 = lp::assoc_bit<cr1, 12>;
    /* Receiver wakeup method */
    using cr1_wake = lp::assoc_bit<cr1, 11>;
    /* Parity control enable */
    using cr1_pce = lp::assoc_bit<cr1, 10>;
    /* Parity selection */
    using cr1_ps = lp::assoc_bit<cr1, 9>;
    /* PE interrupt enable */
    using cr1_peie = lp::assoc_bit<cr1, 8>;
    /* interrupt enable */
    using cr1_txeie = lp::assoc_bit<cr1, 7>;
    /* Transmission complete interrupt               enable */
    using cr1_tcie = lp::assoc_bit<cr1, 6>;
    /* RXNE interrupt enable */
    using cr1_rxneie = lp::assoc_bit<cr1, 5>;
    /* IDLE interrupt enable */
    using cr1_idleie = lp::assoc_bit<cr1, 4>;
    /* Transmitter enable */
    using cr1_te = lp::assoc_bit<cr1, 3>;
    /* Receiver enable */
    using cr1_re = lp::assoc_bit<cr1, 2>;
    /* USART enable in Stop mode */
    using cr1_uesm = lp::assoc_bit<cr1, 1>;
    /* USART enable */
    using cr1_ue = lp::assoc_bit<cr1, 0>;


    /* Control register 2 */
    using cr2 = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* Address of the USART node */
    using cr2_add4_7 = lp::assoc_bit<cr2, 28, 4>;
    /* Address of the USART node */
    using cr2_add0_3 = lp::assoc_bit<cr2, 24, 4>;
    /* Receiver timeout enable */
    using cr2_rtoen = lp::assoc_bit<cr2, 23>;
    /* Auto baud rate mode */
    using cr2_abrmod1 = lp::assoc_bit<cr2, 22>;
    /* ABRMOD0 */
    using cr2_abrmod0 = lp::assoc_bit<cr2, 21>;
    /* Auto baud rate enable */
    using cr2_abren = lp::assoc_bit<cr2, 20>;
    /* Most significant bit first */
    using cr2_msbfirst = lp::assoc_bit<cr2, 19>;
    /* Binary data inversion */
    using cr2_tainv = lp::assoc_bit<cr2, 18>;
    /* TX pin active level               inversion */
    using cr2_txinv = lp::assoc_bit<cr2, 17>;
    /* RX pin active level               inversion */
    using cr2_rxinv = lp::assoc_bit<cr2, 16>;
    /* Swap TX/RX pins */
    using cr2_swap = lp::assoc_bit<cr2, 15>;
    /* LIN mode enable */
    using cr2_linen = lp::assoc_bit<cr2, 14>;
    /* STOP bits */
    using cr2_stop = lp::assoc_bit<cr2, 12, 2>;
    /* Clock enable */
    using cr2_clken = lp::assoc_bit<cr2, 11>;
    /* Clock polarity */
    using cr2_cpol = lp::assoc_bit<cr2, 10>;
    /* Clock phase */
    using cr2_cpha = lp::assoc_bit<cr2, 9>;
    /* Last bit clock pulse */
    using cr2_lbcl = lp::assoc_bit<cr2, 8>;
    /* LIN break detection interrupt               enable */
    using cr2_lbdie = lp::assoc_bit<cr2, 6>;
    /* LIN break detection length */
    using cr2_lbdl = lp::assoc_bit<cr2, 5>;
    /* 7-bit Address Detection/4-bit Address               Detection */
    using cr2_addm7 = lp::assoc_bit<cr2, 4>;


    /* Control register 3 */
    using cr3 = lp::io_register<lp::u32_t, base_address + 0x8>;
    /* Wakeup from Stop mode interrupt               enable */
    using cr3_wufie = lp::assoc_bit<cr3, 22>;
    /* Wakeup from Stop mode interrupt flag               selection */
    using cr3_wus = lp::assoc_bit<cr3, 20, 2>;
    /* Smartcard auto-retry count */
    using cr3_scarcnt = lp::assoc_bit<cr3, 17, 3>;
    /* Driver enable polarity               selection */
    using cr3_dep = lp::assoc_bit<cr3, 15>;
    /* Driver enable mode */
    using cr3_dem = lp::assoc_bit<cr3, 14>;
    /* DMA Disable on Reception               Error */
    using cr3_ddre = lp::assoc_bit<cr3, 13>;
    /* Overrun Disable */
    using cr3_ovrdis = lp::assoc_bit<cr3, 12>;
    /* One sample bit method               enable */
    using cr3_onebit = lp::assoc_bit<cr3, 11>;
    /* CTS interrupt enable */
    using cr3_ctsie = lp::assoc_bit<cr3, 10>;
    /* CTS enable */
    using cr3_ctse = lp::assoc_bit<cr3, 9>;
    /* RTS enable */
    using cr3_rtse = lp::assoc_bit<cr3, 8>;
    /* DMA enable transmitter */
    using cr3_dmat = lp::assoc_bit<cr3, 7>;
    /* DMA enable receiver */
    using cr3_dmar = lp::assoc_bit<cr3, 6>;
    /* Smartcard mode enable */
    using cr3_scen = lp::assoc_bit<cr3, 5>;
    /* Smartcard NACK enable */
    using cr3_nack = lp::assoc_bit<cr3, 4>;
    /* Half-duplex selection */
    using cr3_hdsel = lp::assoc_bit<cr3, 3>;
    /* Ir low-power */
    using cr3_irlp = lp::assoc_bit<cr3, 2>;
    /* Ir mode enable */
    using cr3_iren = lp::assoc_bit<cr3, 1>;
    /* Error interrupt enable */
    using cr3_eie = lp::assoc_bit<cr3, 0>;


    /* Baud rate register */
    using brr = lp::io_register<lp::u32_t, base_address + 0xc>;
    /* BRR */
    using brr_brr = lp::assoc_bit<brr, 0, 20>;


    /* Guard time and prescaler           register */
    using gtpr = lp::io_register<lp::u32_t, base_address + 0x10>;
    /* Guard time value */
    using gtpr_gt = lp::assoc_bit<gtpr, 8, 8>;
    /* Prescaler value */
    using gtpr_psc = lp::assoc_bit<gtpr, 0, 8>;


    /* Receiver timeout register */
    using rtor = lp::io_register<lp::u32_t, base_address + 0x14>;
    /* Block Length */
    using rtor_blen = lp::assoc_bit<rtor, 24, 8>;
    /* Receiver timeout value */
    using rtor_rto = lp::assoc_bit<rtor, 0, 24>;


    /* Request register */
    using rqr = lp::io_register<lp::u32_t, base_address + 0x18>;
    /* Transmit data flush               request */
    using rqr_txfrq = lp::assoc_bit<rqr, 4>;
    /* Receive data flush request */
    using rqr_rxfrq = lp::assoc_bit<rqr, 3>;
    /* Mute mode request */
    using rqr_mmrq = lp::assoc_bit<rqr, 2>;
    /* Send break request */
    using rqr_sbkrq = lp::assoc_bit<rqr, 1>;
    /* Auto baud rate request */
    using rqr_abrrq = lp::assoc_bit<rqr, 0>;


    /* Interrupt & status           register */
    using isr = lp::io_register<lp::u32_t, base_address + 0x1c>;
    /* REACK */
    using isr_reack = lp::assoc_bit<isr, 22>;
    /* TEACK */
    using isr_teack = lp::assoc_bit<isr, 21>;
    /* WUF */
    using isr_wuf = lp::assoc_bit<isr, 20>;
    /* RWU */
    using isr_rwu = lp::assoc_bit<isr, 19>;
    /* SBKF */
    using isr_sbkf = lp::assoc_bit<isr, 18>;
    /* CMF */
    using isr_cmf = lp::assoc_bit<isr, 17>;
    /* BUSY */
    using isr_busy = lp::assoc_bit<isr, 16>;
    /* ABRF */
    using isr_abrf = lp::assoc_bit<isr, 15>;
    /* ABRE */
    using isr_abre = lp::assoc_bit<isr, 14>;
    /* EOBF */
    using isr_eobf = lp::assoc_bit<isr, 12>;
    /* RTOF */
    using isr_rtof = lp::assoc_bit<isr, 11>;
    /* CTS */
    using isr_cts = lp::assoc_bit<isr, 10>;
    /* CTSIF */
    using isr_ctsif = lp::assoc_bit<isr, 9>;
    /* LBDF */
    using isr_lbdf = lp::assoc_bit<isr, 8>;
    /* TXE */
    using isr_txe = lp::assoc_bit<isr, 7>;
    /* TC */
    using isr_tc = lp::assoc_bit<isr, 6>;
    /* RXNE */
    using isr_rxne = lp::assoc_bit<isr, 5>;
    /* IDLE */
    using isr_idle = lp::assoc_bit<isr, 4>;
    /* ORE */
    using isr_ore = lp::assoc_bit<isr, 3>;
    /* NF */
    using isr_nf = lp::assoc_bit<isr, 2>;
    /* FE */
    using isr_fe = lp::assoc_bit<isr, 1>;
    /* PE */
    using isr_pe = lp::assoc_bit<isr, 0>;


    /* Interrupt flag clear register */
    using icr = lp::io_register<lp::u32_t, base_address + 0x20>;
    /* Wakeup from Stop mode clear               flag */
    using icr_wucf = lp::assoc_bit<icr, 20>;
    /* Character match clear flag */
    using icr_cmcf = lp::assoc_bit<icr, 17>;
    /* End of block clear flag */
    using icr_eobcf = lp::assoc_bit<icr, 12>;
    /* Receiver timeout clear               flag */
    using icr_rtocf = lp::assoc_bit<icr, 11>;
    /* CTS clear flag */
    using icr_ctscf = lp::assoc_bit<icr, 9>;
    /* LIN break detection clear               flag */
    using icr_lbdcf = lp::assoc_bit<icr, 8>;
    /* Transmission complete clear               flag */
    using icr_tccf = lp::assoc_bit<icr, 6>;
    /* Idle line detected clear               flag */
    using icr_idlecf = lp::assoc_bit<icr, 4>;
    /* Overrun error clear flag */
    using icr_orecf = lp::assoc_bit<icr, 3>;
    /* Noise detected clear flag */
    using icr_ncf = lp::assoc_bit<icr, 2>;
    /* Framing error clear flag */
    using icr_fecf = lp::assoc_bit<icr, 1>;
    /* Parity error clear flag */
    using icr_pecf = lp::assoc_bit<icr, 0>;


    /* Receive data register */
    using rdr = lp::io_register<lp::u32_t, base_address + 0x24>;
    /* Receive data value */
    using rdr_rdr = lp::assoc_bit<rdr, 0, 9>;


    /* Transmit data register */
    using tdr = lp::io_register<lp::u32_t, base_address + 0x28>;
    /* Transmit data value */
    using tdr_tdr = lp::assoc_bit<tdr, 0, 9>;


};

/* Universal synchronous asynchronous receiver
      transmitter */
template <lp::addr_t base_address>
struct lpuart_t {
    /* Control register 1 */
    using cr1 = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* Word length */
    using cr1_m1 = lp::assoc_bit<cr1, 28>;
    /* Driver Enable assertion               time */
    using cr1_deat4 = lp::assoc_bit<cr1, 25>;
    /* DEAT3 */
    using cr1_deat3 = lp::assoc_bit<cr1, 24>;
    /* DEAT2 */
    using cr1_deat2 = lp::assoc_bit<cr1, 23>;
    /* DEAT1 */
    using cr1_deat1 = lp::assoc_bit<cr1, 22>;
    /* DEAT0 */
    using cr1_deat0 = lp::assoc_bit<cr1, 21>;
    /* Driver Enable de-assertion               time */
    using cr1_dedt4 = lp::assoc_bit<cr1, 20>;
    /* DEDT3 */
    using cr1_dedt3 = lp::assoc_bit<cr1, 19>;
    /* DEDT2 */
    using cr1_dedt2 = lp::assoc_bit<cr1, 18>;
    /* DEDT1 */
    using cr1_dedt1 = lp::assoc_bit<cr1, 17>;
    /* DEDT0 */
    using cr1_dedt0 = lp::assoc_bit<cr1, 16>;
    /* Character match interrupt               enable */
    using cr1_cmie = lp::assoc_bit<cr1, 14>;
    /* Mute mode enable */
    using cr1_mme = lp::assoc_bit<cr1, 13>;
    /* Word length */
    using cr1_m0 = lp::assoc_bit<cr1, 12>;
    /* Receiver wakeup method */
    using cr1_wake = lp::assoc_bit<cr1, 11>;
    /* Parity control enable */
    using cr1_pce = lp::assoc_bit<cr1, 10>;
    /* Parity selection */
    using cr1_ps = lp::assoc_bit<cr1, 9>;
    /* PE interrupt enable */
    using cr1_peie = lp::assoc_bit<cr1, 8>;
    /* interrupt enable */
    using cr1_txeie = lp::assoc_bit<cr1, 7>;
    /* Transmission complete interrupt               enable */
    using cr1_tcie = lp::assoc_bit<cr1, 6>;
    /* RXNE interrupt enable */
    using cr1_rxneie = lp::assoc_bit<cr1, 5>;
    /* IDLE interrupt enable */
    using cr1_idleie = lp::assoc_bit<cr1, 4>;
    /* Transmitter enable */
    using cr1_te = lp::assoc_bit<cr1, 3>;
    /* Receiver enable */
    using cr1_re = lp::assoc_bit<cr1, 2>;
    /* USART enable in Stop mode */
    using cr1_uesm = lp::assoc_bit<cr1, 1>;
    /* USART enable */
    using cr1_ue = lp::assoc_bit<cr1, 0>;


    /* Control register 2 */
    using cr2 = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* Address of the USART node */
    using cr2_add4_7 = lp::assoc_bit<cr2, 28, 4>;
    /* Address of the USART node */
    using cr2_add0_3 = lp::assoc_bit<cr2, 24, 4>;
    /* Most significant bit first */
    using cr2_msbfirst = lp::assoc_bit<cr2, 19>;
    /* Binary data inversion */
    using cr2_tainv = lp::assoc_bit<cr2, 18>;
    /* TX pin active level               inversion */
    using cr2_txinv = lp::assoc_bit<cr2, 17>;
    /* RX pin active level               inversion */
    using cr2_rxinv = lp::assoc_bit<cr2, 16>;
    /* Swap TX/RX pins */
    using cr2_swap = lp::assoc_bit<cr2, 15>;
    /* STOP bits */
    using cr2_stop = lp::assoc_bit<cr2, 12, 2>;
    /* Clock enable */
    using cr2_clken = lp::assoc_bit<cr2, 11>;
    /* 7-bit Address Detection/4-bit Address               Detection */
    using cr2_addm7 = lp::assoc_bit<cr2, 4>;


    /* Control register 3 */
    using cr3 = lp::io_register<lp::u32_t, base_address + 0x8>;
    /* Wakeup from Stop mode interrupt               enable */
    using cr3_wufie = lp::assoc_bit<cr3, 22>;
    /* Wakeup from Stop mode interrupt flag               selection */
    using cr3_wus = lp::assoc_bit<cr3, 20, 2>;
    /* Driver enable polarity               selection */
    using cr3_dep = lp::assoc_bit<cr3, 15>;
    /* Driver enable mode */
    using cr3_dem = lp::assoc_bit<cr3, 14>;
    /* DMA Disable on Reception               Error */
    using cr3_ddre = lp::assoc_bit<cr3, 13>;
    /* Overrun Disable */
    using cr3_ovrdis = lp::assoc_bit<cr3, 12>;
    /* CTS interrupt enable */
    using cr3_ctsie = lp::assoc_bit<cr3, 10>;
    /* CTS enable */
    using cr3_ctse = lp::assoc_bit<cr3, 9>;
    /* RTS enable */
    using cr3_rtse = lp::assoc_bit<cr3, 8>;
    /* DMA enable transmitter */
    using cr3_dmat = lp::assoc_bit<cr3, 7>;
    /* DMA enable receiver */
    using cr3_dmar = lp::assoc_bit<cr3, 6>;
    /* Half-duplex selection */
    using cr3_hdsel = lp::assoc_bit<cr3, 3>;
    /* Error interrupt enable */
    using cr3_eie = lp::assoc_bit<cr3, 0>;


    /* Baud rate register */
    using brr = lp::io_register<lp::u32_t, base_address + 0xc>;
    /* BRR */
    using brr_brr = lp::assoc_bit<brr, 0, 20>;


    /* Request register */
    using rqr = lp::io_register<lp::u32_t, base_address + 0x18>;
    /* Receive data flush request */
    using rqr_rxfrq = lp::assoc_bit<rqr, 3>;
    /* Mute mode request */
    using rqr_mmrq = lp::assoc_bit<rqr, 2>;
    /* Send break request */
    using rqr_sbkrq = lp::assoc_bit<rqr, 1>;


    /* Interrupt & status           register */
    using isr = lp::io_register<lp::u32_t, base_address + 0x1c>;
    /* REACK */
    using isr_reack = lp::assoc_bit<isr, 22>;
    /* TEACK */
    using isr_teack = lp::assoc_bit<isr, 21>;
    /* WUF */
    using isr_wuf = lp::assoc_bit<isr, 20>;
    /* RWU */
    using isr_rwu = lp::assoc_bit<isr, 19>;
    /* SBKF */
    using isr_sbkf = lp::assoc_bit<isr, 18>;
    /* CMF */
    using isr_cmf = lp::assoc_bit<isr, 17>;
    /* BUSY */
    using isr_busy = lp::assoc_bit<isr, 16>;
    /* CTS */
    using isr_cts = lp::assoc_bit<isr, 10>;
    /* CTSIF */
    using isr_ctsif = lp::assoc_bit<isr, 9>;
    /* TXE */
    using isr_txe = lp::assoc_bit<isr, 7>;
    /* TC */
    using isr_tc = lp::assoc_bit<isr, 6>;
    /* RXNE */
    using isr_rxne = lp::assoc_bit<isr, 5>;
    /* IDLE */
    using isr_idle = lp::assoc_bit<isr, 4>;
    /* ORE */
    using isr_ore = lp::assoc_bit<isr, 3>;
    /* NF */
    using isr_nf = lp::assoc_bit<isr, 2>;
    /* FE */
    using isr_fe = lp::assoc_bit<isr, 1>;
    /* PE */
    using isr_pe = lp::assoc_bit<isr, 0>;


    /* Interrupt flag clear register */
    using icr = lp::io_register<lp::u32_t, base_address + 0x20>;
    /* Wakeup from Stop mode clear               flag */
    using icr_wucf = lp::assoc_bit<icr, 20>;
    /* Character match clear flag */
    using icr_cmcf = lp::assoc_bit<icr, 17>;
    /* CTS clear flag */
    using icr_ctscf = lp::assoc_bit<icr, 9>;
    /* Transmission complete clear               flag */
    using icr_tccf = lp::assoc_bit<icr, 6>;
    /* Idle line detected clear               flag */
    using icr_idlecf = lp::assoc_bit<icr, 4>;
    /* Overrun error clear flag */
    using icr_orecf = lp::assoc_bit<icr, 3>;
    /* Noise detected clear flag */
    using icr_ncf = lp::assoc_bit<icr, 2>;
    /* Framing error clear flag */
    using icr_fecf = lp::assoc_bit<icr, 1>;
    /* Parity error clear flag */
    using icr_pecf = lp::assoc_bit<icr, 0>;


    /* Receive data register */
    using rdr = lp::io_register<lp::u32_t, base_address + 0x24>;
    /* Receive data value */
    using rdr_rdr = lp::assoc_bit<rdr, 0, 9>;


    /* Transmit data register */
    using tdr = lp::io_register<lp::u32_t, base_address + 0x28>;
    /* Transmit data value */
    using tdr_tdr = lp::assoc_bit<tdr, 0, 9>;


};

using usart1 = usart_t<0x40013800>;
using usart2 = usart_t<0x40004400>;
using usart3 = usart_t<0x40004800>;
using uart4 = usart_t<0x40004c00>;
using uart5 = usart_t<0x40005000>;
using lpuart1 = lpuart_t<0x40008000>;

#endif // USART_HH
