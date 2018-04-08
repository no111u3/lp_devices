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
 * Hardware support for spi
 * @file spi.hh
 * @author Boris Vinogradov
 */

#include <associate_bit.hh>
#include <io_register.hh>
#include <types.hh>

#ifndef SPI_HH
#define SPI_HH

/* Serial peripheral interface/Inter-IC
      sound */
template <lp::addr_t base_address>
struct spi_t {
    /* control register 1 */
    using cr1 = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* Bidirectional data mode               enable */
    using cr1_bidimode = lp::assoc_bit<cr1, 15>;
    /* Output enable in bidirectional               mode */
    using cr1_bidioe = lp::assoc_bit<cr1, 14>;
    /* Hardware CRC calculation               enable */
    using cr1_crcen = lp::assoc_bit<cr1, 13>;
    /* CRC transfer next */
    using cr1_crcnext = lp::assoc_bit<cr1, 12>;
    /* Data frame format */
    using cr1_dff = lp::assoc_bit<cr1, 11>;
    /* Receive only */
    using cr1_rxonly = lp::assoc_bit<cr1, 10>;
    /* Software slave management */
    using cr1_ssm = lp::assoc_bit<cr1, 9>;
    /* Internal slave select */
    using cr1_ssi = lp::assoc_bit<cr1, 8>;
    /* Frame format */
    using cr1_lsbfirst = lp::assoc_bit<cr1, 7>;
    /* SPI enable */
    using cr1_spe = lp::assoc_bit<cr1, 6>;
    /* Baud rate control */
    using cr1_br = lp::assoc_bit<cr1, 3, 3>;
    /* Master selection */
    using cr1_mstr = lp::assoc_bit<cr1, 2>;
    /* Clock polarity */
    using cr1_cpol = lp::assoc_bit<cr1, 1>;
    /* Clock phase */
    using cr1_cpha = lp::assoc_bit<cr1, 0>;


    /* control register 2 */
    using cr2 = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* Rx buffer DMA enable */
    using cr2_rxdmaen = lp::assoc_bit<cr2, 0>;
    /* Tx buffer DMA enable */
    using cr2_txdmaen = lp::assoc_bit<cr2, 1>;
    /* SS output enable */
    using cr2_ssoe = lp::assoc_bit<cr2, 2>;
    /* NSS pulse management */
    using cr2_nssp = lp::assoc_bit<cr2, 3>;
    /* Frame format */
    using cr2_frf = lp::assoc_bit<cr2, 4>;
    /* Error interrupt enable */
    using cr2_errie = lp::assoc_bit<cr2, 5>;
    /* RX buffer not empty interrupt               enable */
    using cr2_rxneie = lp::assoc_bit<cr2, 6>;
    /* Tx buffer empty interrupt               enable */
    using cr2_txeie = lp::assoc_bit<cr2, 7>;
    /* Data size */
    using cr2_ds = lp::assoc_bit<cr2, 8, 4>;
    /* FIFO reception threshold */
    using cr2_frxth = lp::assoc_bit<cr2, 12>;
    /* Last DMA transfer for               reception */
    using cr2_ldma_rx = lp::assoc_bit<cr2, 13>;
    /* Last DMA transfer for               transmission */
    using cr2_ldma_tx = lp::assoc_bit<cr2, 14>;


    /* status register */
    using sr = lp::io_register<lp::u32_t, base_address + 0x8>;
    /* Receive buffer not empty */
    using sr_rxne = lp::assoc_bit<sr, 0>;
    /* Transmit buffer empty */
    using sr_txe = lp::assoc_bit<sr, 1>;
    /* CRC error flag */
    using sr_crcerr = lp::assoc_bit<sr, 4>;
    /* Mode fault */
    using sr_modf = lp::assoc_bit<sr, 5>;
    /* Overrun flag */
    using sr_ovr = lp::assoc_bit<sr, 6>;
    /* Busy flag */
    using sr_bsy = lp::assoc_bit<sr, 7>;
    /* TI frame format error */
    using sr_tifrfe = lp::assoc_bit<sr, 8>;
    /* FIFO reception level */
    using sr_frlvl = lp::assoc_bit<sr, 9, 2>;
    /* FIFO transmission level */
    using sr_ftlvl = lp::assoc_bit<sr, 11, 2>;


    /* data register */
    using dr = lp::io_register<lp::u32_t, base_address + 0xc>;
    /* Data register */
    using dr_dr = lp::assoc_bit<dr, 0, 16>;


    /* CRC polynomial register */
    using crcpr = lp::io_register<lp::u32_t, base_address + 0x10>;
    /* CRC polynomial register */
    using crcpr_crcpoly = lp::assoc_bit<crcpr, 0, 16>;


    /* RX CRC register */
    using rxcrcr = lp::io_register<lp::u32_t, base_address + 0x14>;
    /* Rx CRC register */
    using rxcrcr_rxcrc = lp::assoc_bit<rxcrcr, 0, 16>;


    /* TX CRC register */
    using txcrcr = lp::io_register<lp::u32_t, base_address + 0x18>;
    /* Tx CRC register */
    using txcrcr_txcrc = lp::assoc_bit<txcrcr, 0, 16>;


};

using spi1 = spi_t<0x40013000>;
using spi2 = spi_t<0x40003800>;
using spi3 = spi_t<0x40003c00>;

#endif // SPI_HH
