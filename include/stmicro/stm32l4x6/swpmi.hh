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
 * Hardware support for swpmi
 * @file swpmi.hh
 * @author Boris Vinogradov
 */

#include <associate_bit.hh>
#include <io_register.hh>
#include <types.hh>

#ifndef SWPMI_HH
#define SWPMI_HH

/* Single Wire Protocol Master
      Interface */
template <lp::addr_t base_address>
struct swpmi_t {
    /* SWPMI Configuration/Control           register */
    using cr = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* Reception DMA enable */
    using cr_rxdma = lp::assoc_bit<cr, 0>;
    /* Transmission DMA enable */
    using cr_txdma = lp::assoc_bit<cr, 1>;
    /* Reception buffering mode */
    using cr_rxmode = lp::assoc_bit<cr, 2>;
    /* Transmission buffering               mode */
    using cr_txmode = lp::assoc_bit<cr, 3>;
    /* Loopback mode enable */
    using cr_lpbk = lp::assoc_bit<cr, 4>;
    /* Single wire protocol master interface               activate */
    using cr_swpact = lp::assoc_bit<cr, 5>;
    /* Single wire protocol master interface               deactivate */
    using cr_deact = lp::assoc_bit<cr, 10>;


    /* SWPMI Bitrate register */
    using brr = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* Bitrate prescaler */
    using brr_br = lp::assoc_bit<brr, 0, 6>;


    /* SWPMI Interrupt and Status           register */
    using isr = lp::io_register<lp::u32_t, base_address + 0xc>;
    /* Receive buffer full flag */
    using isr_rxbff = lp::assoc_bit<isr, 0>;
    /* Transmit buffer empty flag */
    using isr_txbef = lp::assoc_bit<isr, 1>;
    /* Receive CRC error flag */
    using isr_rxberf = lp::assoc_bit<isr, 2>;
    /* Receive overrun error flag */
    using isr_rxovrf = lp::assoc_bit<isr, 3>;
    /* Transmit underrun error               flag */
    using isr_txunrf = lp::assoc_bit<isr, 4>;
    /* Receive data register not               empty */
    using isr_rxne = lp::assoc_bit<isr, 5>;
    /* Transmit data register               empty */
    using isr_txe = lp::assoc_bit<isr, 6>;
    /* Transfer complete flag */
    using isr_tcf = lp::assoc_bit<isr, 7>;
    /* Slave resume flag */
    using isr_srf = lp::assoc_bit<isr, 8>;
    /* SUSPEND flag */
    using isr_susp = lp::assoc_bit<isr, 9>;
    /* DEACTIVATED flag */
    using isr_deactf = lp::assoc_bit<isr, 10>;


    /* SWPMI Interrupt Flag Clear           register */
    using icr = lp::io_register<lp::u32_t, base_address + 0x10>;
    /* Clear receive buffer full               flag */
    using icr_crxbff = lp::assoc_bit<icr, 0>;
    /* Clear transmit buffer empty               flag */
    using icr_ctxbef = lp::assoc_bit<icr, 1>;
    /* Clear receive CRC error               flag */
    using icr_crxberf = lp::assoc_bit<icr, 2>;
    /* Clear receive overrun error               flag */
    using icr_crxovrf = lp::assoc_bit<icr, 3>;
    /* Clear transmit underrun error               flag */
    using icr_ctxunrf = lp::assoc_bit<icr, 4>;
    /* Clear transfer complete               flag */
    using icr_ctcf = lp::assoc_bit<icr, 7>;
    /* Clear slave resume flag */
    using icr_csrf = lp::assoc_bit<icr, 8>;


    /* SWPMI Interrupt Enable           register */
    using ier = lp::io_register<lp::u32_t, base_address + 0x14>;
    /* Receive buffer full interrupt               enable */
    using ier_rxbfie = lp::assoc_bit<ier, 0>;
    /* Transmit buffer empty interrupt               enable */
    using ier_txbeie = lp::assoc_bit<ier, 1>;
    /* Receive CRC error interrupt               enable */
    using ier_rxberie = lp::assoc_bit<ier, 2>;
    /* Receive overrun error interrupt               enable */
    using ier_rxovrie = lp::assoc_bit<ier, 3>;
    /* Transmit underrun error interrupt               enable */
    using ier_txunrie = lp::assoc_bit<ier, 4>;
    /* Receive interrupt enable */
    using ier_rie = lp::assoc_bit<ier, 5>;
    /* Transmit interrupt enable */
    using ier_tie = lp::assoc_bit<ier, 6>;
    /* Transmit complete interrupt               enable */
    using ier_tcie = lp::assoc_bit<ier, 7>;
    /* Slave resume interrupt               enable */
    using ier_srie = lp::assoc_bit<ier, 8>;


    /* SWPMI Receive Frame Length           register */
    using rfl = lp::io_register<lp::u32_t, base_address + 0x18>;
    /* Receive frame length */
    using rfl_rfl = lp::assoc_bit<rfl, 0, 5>;


    /* SWPMI Transmit data register */
    using tdr = lp::io_register<lp::u32_t, base_address + 0x1c>;
    /* Transmit data */
    using tdr_td = lp::assoc_bit<tdr, 0, 32>;


    /* SWPMI Receive data register */
    using rdr = lp::io_register<lp::u32_t, base_address + 0x20>;
    /* received data */
    using rdr_rd = lp::assoc_bit<rdr, 0, 32>;


    /* SWPMI Option register */
    using or1 = lp::io_register<lp::u32_t, base_address + 0x24>;
    /* SWP transceiver bypass */
    using or1_swp_tbyp = lp::assoc_bit<or1, 0>;
    /* SWP class selection */
    using or1_swp_class = lp::assoc_bit<or1, 1>;


};

using swpmi1 = swpmi_t<0x40008800>;

#endif // SWPMI_HH
