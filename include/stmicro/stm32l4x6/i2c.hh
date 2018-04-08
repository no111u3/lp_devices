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
 * Hardware support for i2c
 * @file i2c.hh
 * @author Boris Vinogradov
 */

#include <associate_bit.hh>
#include <io_register.hh>
#include <types.hh>

#ifndef I2C_HH
#define I2C_HH

/* Inter-integrated circuit */
template <lp::addr_t base_address>
struct ic_t {
    /* Control register 1 */
    using cr1 = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* Peripheral enable */
    using cr1_pe = lp::assoc_bit<cr1, 0>;
    /* TX Interrupt enable */
    using cr1_txie = lp::assoc_bit<cr1, 1>;
    /* RX Interrupt enable */
    using cr1_rxie = lp::assoc_bit<cr1, 2>;
    /* Address match interrupt enable (slave               only) */
    using cr1_addrie = lp::assoc_bit<cr1, 3>;
    /* Not acknowledge received interrupt               enable */
    using cr1_nackie = lp::assoc_bit<cr1, 4>;
    /* STOP detection Interrupt               enable */
    using cr1_stopie = lp::assoc_bit<cr1, 5>;
    /* Transfer Complete interrupt               enable */
    using cr1_tcie = lp::assoc_bit<cr1, 6>;
    /* Error interrupts enable */
    using cr1_errie = lp::assoc_bit<cr1, 7>;
    /* Digital noise filter */
    using cr1_dnf = lp::assoc_bit<cr1, 8, 4>;
    /* Analog noise filter OFF */
    using cr1_anfoff = lp::assoc_bit<cr1, 12>;
    /* DMA transmission requests               enable */
    using cr1_txdmaen = lp::assoc_bit<cr1, 14>;
    /* DMA reception requests               enable */
    using cr1_rxdmaen = lp::assoc_bit<cr1, 15>;
    /* Slave byte control */
    using cr1_sbc = lp::assoc_bit<cr1, 16>;
    /* Clock stretching disable */
    using cr1_nostretch = lp::assoc_bit<cr1, 17>;
    /* Wakeup from STOP enable */
    using cr1_wupen = lp::assoc_bit<cr1, 18>;
    /* General call enable */
    using cr1_gcen = lp::assoc_bit<cr1, 19>;
    /* SMBus Host address enable */
    using cr1_smbhen = lp::assoc_bit<cr1, 20>;
    /* SMBus Device Default address               enable */
    using cr1_smbden = lp::assoc_bit<cr1, 21>;
    /* SMBUS alert enable */
    using cr1_alerten = lp::assoc_bit<cr1, 22>;
    /* PEC enable */
    using cr1_pecen = lp::assoc_bit<cr1, 23>;


    /* Control register 2 */
    using cr2 = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* Packet error checking byte */
    using cr2_pecbyte = lp::assoc_bit<cr2, 26>;
    /* Automatic end mode (master               mode) */
    using cr2_autoend = lp::assoc_bit<cr2, 25>;
    /* NBYTES reload mode */
    using cr2_reload = lp::assoc_bit<cr2, 24>;
    /* Number of bytes */
    using cr2_nbytes = lp::assoc_bit<cr2, 16, 8>;
    /* NACK generation (slave               mode) */
    using cr2_nack = lp::assoc_bit<cr2, 15>;
    /* Stop generation (master               mode) */
    using cr2_stop = lp::assoc_bit<cr2, 14>;
    /* Start generation */
    using cr2_start = lp::assoc_bit<cr2, 13>;
    /* 10-bit address header only read               direction (master receiver mode) */
    using cr2_head10r = lp::assoc_bit<cr2, 12>;
    /* 10-bit addressing mode (master               mode) */
    using cr2_add10 = lp::assoc_bit<cr2, 11>;
    /* Transfer direction (master               mode) */
    using cr2_rd_wrn = lp::assoc_bit<cr2, 10>;
    /* Slave address bit (master               mode) */
    using cr2_sadd = lp::assoc_bit<cr2, 0, 10>;


    /* Own address register 1 */
    using oar1 = lp::io_register<lp::u32_t, base_address + 0x8>;
    /* Interface address */
    using oar1_oa1 = lp::assoc_bit<oar1, 0, 10>;
    /* Own Address 1 10-bit mode */
    using oar1_oa1mode = lp::assoc_bit<oar1, 10>;
    /* Own Address 1 enable */
    using oar1_oa1en = lp::assoc_bit<oar1, 15>;


    /* Own address register 2 */
    using oar2 = lp::io_register<lp::u32_t, base_address + 0xc>;
    /* Interface address */
    using oar2_oa2 = lp::assoc_bit<oar2, 1, 7>;
    /* Own Address 2 masks */
    using oar2_oa2msk = lp::assoc_bit<oar2, 8, 3>;
    /* Own Address 2 enable */
    using oar2_oa2en = lp::assoc_bit<oar2, 15>;


    /* Timing register */
    using timingr = lp::io_register<lp::u32_t, base_address + 0x10>;
    /* SCL low period (master               mode) */
    using timingr_scll = lp::assoc_bit<timingr, 0, 8>;
    /* SCL high period (master               mode) */
    using timingr_sclh = lp::assoc_bit<timingr, 8, 8>;
    /* Data hold time */
    using timingr_sdadel = lp::assoc_bit<timingr, 16, 4>;
    /* Data setup time */
    using timingr_scldel = lp::assoc_bit<timingr, 20, 4>;
    /* Timing prescaler */
    using timingr_presc = lp::assoc_bit<timingr, 28, 4>;


    /* Status register 1 */
    using timeoutr = lp::io_register<lp::u32_t, base_address + 0x14>;
    /* Bus timeout A */
    using timeoutr_timeouta = lp::assoc_bit<timeoutr, 0, 12>;
    /* Idle clock timeout               detection */
    using timeoutr_tidle = lp::assoc_bit<timeoutr, 12>;
    /* Clock timeout enable */
    using timeoutr_timouten = lp::assoc_bit<timeoutr, 15>;
    /* Bus timeout B */
    using timeoutr_timeoutb = lp::assoc_bit<timeoutr, 16, 12>;
    /* Extended clock timeout               enable */
    using timeoutr_texten = lp::assoc_bit<timeoutr, 31>;


    /* Interrupt and Status register */
    using isr = lp::io_register<lp::u32_t, base_address + 0x18>;
    /* Address match code (Slave               mode) */
    using isr_addcode = lp::assoc_bit<isr, 17, 7>;
    /* Transfer direction (Slave               mode) */
    using isr_dir = lp::assoc_bit<isr, 16>;
    /* Bus busy */
    using isr_busy = lp::assoc_bit<isr, 15>;
    /* SMBus alert */
    using isr_alert = lp::assoc_bit<isr, 13>;
    /* Timeout or t_low detection               flag */
    using isr_timeout = lp::assoc_bit<isr, 12>;
    /* PEC Error in reception */
    using isr_pecerr = lp::assoc_bit<isr, 11>;
    /* Overrun/Underrun (slave               mode) */
    using isr_ovr = lp::assoc_bit<isr, 10>;
    /* Arbitration lost */
    using isr_arlo = lp::assoc_bit<isr, 9>;
    /* Bus error */
    using isr_berr = lp::assoc_bit<isr, 8>;
    /* Transfer Complete Reload */
    using isr_tcr = lp::assoc_bit<isr, 7>;
    /* Transfer Complete (master               mode) */
    using isr_tc = lp::assoc_bit<isr, 6>;
    /* Stop detection flag */
    using isr_stopf = lp::assoc_bit<isr, 5>;
    /* Not acknowledge received               flag */
    using isr_nackf = lp::assoc_bit<isr, 4>;
    /* Address matched (slave               mode) */
    using isr_addr = lp::assoc_bit<isr, 3>;
    /* Receive data register not empty               (receivers) */
    using isr_rxne = lp::assoc_bit<isr, 2>;
    /* Transmit interrupt status               (transmitters) */
    using isr_txis = lp::assoc_bit<isr, 1>;
    /* Transmit data register empty               (transmitters) */
    using isr_txe = lp::assoc_bit<isr, 0>;


    /* Interrupt clear register */
    using icr = lp::io_register<lp::u32_t, base_address + 0x1c>;
    /* Alert flag clear */
    using icr_alertcf = lp::assoc_bit<icr, 13>;
    /* Timeout detection flag               clear */
    using icr_timoutcf = lp::assoc_bit<icr, 12>;
    /* PEC Error flag clear */
    using icr_peccf = lp::assoc_bit<icr, 11>;
    /* Overrun/Underrun flag               clear */
    using icr_ovrcf = lp::assoc_bit<icr, 10>;
    /* Arbitration lost flag               clear */
    using icr_arlocf = lp::assoc_bit<icr, 9>;
    /* Bus error flag clear */
    using icr_berrcf = lp::assoc_bit<icr, 8>;
    /* Stop detection flag clear */
    using icr_stopcf = lp::assoc_bit<icr, 5>;
    /* Not Acknowledge flag clear */
    using icr_nackcf = lp::assoc_bit<icr, 4>;
    /* Address Matched flag clear */
    using icr_addrcf = lp::assoc_bit<icr, 3>;


    /* PEC register */
    using pecr = lp::io_register<lp::u32_t, base_address + 0x20>;
    /* Packet error checking               register */
    using pecr_pec = lp::assoc_bit<pecr, 0, 8>;


    /* Receive data register */
    using rxdr = lp::io_register<lp::u32_t, base_address + 0x24>;
    /* 8-bit receive data */
    using rxdr_rxdata = lp::assoc_bit<rxdr, 0, 8>;


    /* Transmit data register */
    using txdr = lp::io_register<lp::u32_t, base_address + 0x28>;
    /* 8-bit transmit data */
    using txdr_txdata = lp::assoc_bit<txdr, 0, 8>;


};

using i2c1 = ic_t<0x40005400>;
using i2c2 = ic_t<0x40005800>;
using i2c3 = ic_t<0x40005c00>;
using i2c4 = ic_t<0x40008400>;

#endif // I2C_HH
