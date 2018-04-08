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
 * Hardware support for sdio
 * @file sdio.hh
 * @author Boris Vinogradov
 */

#include <associate_bit.hh>
#include <io_register.hh>
#include <types.hh>

#ifndef SDIO_HH
#define SDIO_HH

/* Secure digital input/output
      interface */
template <lp::addr_t base_address>
struct sdmmc_t {
    /* power control register */
    using power = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* PWRCTRL */
    using power_pwrctrl = lp::assoc_bit<power, 0, 2>;


    /* SDI clock control register */
    using clkcr = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* HW Flow Control enable */
    using clkcr_hwfc_en = lp::assoc_bit<clkcr, 14>;
    /* SDIO_CK dephasing selection               bit */
    using clkcr_negedge = lp::assoc_bit<clkcr, 13>;
    /* Wide bus mode enable bit */
    using clkcr_widbus = lp::assoc_bit<clkcr, 11, 2>;
    /* Clock divider bypass enable               bit */
    using clkcr_bypass = lp::assoc_bit<clkcr, 10>;
    /* Power saving configuration               bit */
    using clkcr_pwrsav = lp::assoc_bit<clkcr, 9>;
    /* Clock enable bit */
    using clkcr_clken = lp::assoc_bit<clkcr, 8>;
    /* Clock divide factor */
    using clkcr_clkdiv = lp::assoc_bit<clkcr, 0, 8>;


    /* argument register */
    using arg = lp::io_register<lp::u32_t, base_address + 0x8>;
    /* Command argument */
    using arg_cmdarg = lp::assoc_bit<arg, 0, 32>;


    /* command register */
    using cmd = lp::io_register<lp::u32_t, base_address + 0xc>;
    /* CE-ATA command */
    using cmd_ce_atacmd = lp::assoc_bit<cmd, 14>;
    /* not Interrupt Enable */
    using cmd_nien = lp::assoc_bit<cmd, 13>;
    /* Enable CMD completion */
    using cmd_encmdcompl = lp::assoc_bit<cmd, 12>;
    /* SD I/O suspend command */
    using cmd_sdiosuspend = lp::assoc_bit<cmd, 11>;
    /* Command path state machine (CPSM) Enable               bit */
    using cmd_cpsmen = lp::assoc_bit<cmd, 10>;
    /* CPSM Waits for ends of data transfer               (CmdPend internal signal) */
    using cmd_waitpend = lp::assoc_bit<cmd, 9>;
    /* CPSM waits for interrupt               request */
    using cmd_waitint = lp::assoc_bit<cmd, 8>;
    /* Wait for response bits */
    using cmd_waitresp = lp::assoc_bit<cmd, 6, 2>;
    /* Command index */
    using cmd_cmdindex = lp::assoc_bit<cmd, 0, 6>;


    /* command response register */
    using respcmd = lp::io_register<lp::u32_t, base_address + 0x10>;
    /* Response command index */
    using respcmd_respcmd = lp::assoc_bit<respcmd, 0, 6>;


    /* response 1..4 register */
    using resp1 = lp::io_register<lp::u32_t, base_address + 0x14>;
    /* see Table 132 */
    using resp1_cardstatus1 = lp::assoc_bit<resp1, 0, 32>;


    /* response 1..4 register */
    using resp2 = lp::io_register<lp::u32_t, base_address + 0x18>;
    /* see Table 132 */
    using resp2_cardstatus2 = lp::assoc_bit<resp2, 0, 32>;


    /* response 1..4 register */
    using resp3 = lp::io_register<lp::u32_t, base_address + 0x1c>;
    /* see Table 132 */
    using resp3_cardstatus3 = lp::assoc_bit<resp3, 0, 32>;


    /* response 1..4 register */
    using resp4 = lp::io_register<lp::u32_t, base_address + 0x20>;
    /* see Table 132 */
    using resp4_cardstatus4 = lp::assoc_bit<resp4, 0, 32>;


    /* data timer register */
    using dtimer = lp::io_register<lp::u32_t, base_address + 0x24>;
    /* Data timeout period */
    using dtimer_datatime = lp::assoc_bit<dtimer, 0, 32>;


    /* data length register */
    using dlen = lp::io_register<lp::u32_t, base_address + 0x28>;
    /* Data length value */
    using dlen_datalength = lp::assoc_bit<dlen, 0, 25>;


    /* data control register */
    using dctrl = lp::io_register<lp::u32_t, base_address + 0x2c>;
    /* SD I/O enable functions */
    using dctrl_sdioen = lp::assoc_bit<dctrl, 11>;
    /* Read wait mode */
    using dctrl_rwmod = lp::assoc_bit<dctrl, 10>;
    /* Read wait stop */
    using dctrl_rwstop = lp::assoc_bit<dctrl, 9>;
    /* Read wait start */
    using dctrl_rwstart = lp::assoc_bit<dctrl, 8>;
    /* Data block size */
    using dctrl_dblocksize = lp::assoc_bit<dctrl, 4, 4>;
    /* DMA enable bit */
    using dctrl_dmaen = lp::assoc_bit<dctrl, 3>;
    /* Data transfer mode selection 1: Stream               or SDIO multibyte data transfer */
    using dctrl_dtmode = lp::assoc_bit<dctrl, 2>;
    /* Data transfer direction               selection */
    using dctrl_dtdir = lp::assoc_bit<dctrl, 1>;
    /* DTEN */
    using dctrl_dten = lp::assoc_bit<dctrl, 0>;


    /* data counter register */
    using dcount = lp::io_register<lp::u32_t, base_address + 0x30>;
    /* Data count value */
    using dcount_datacount = lp::assoc_bit<dcount, 0, 25>;


    /* status register */
    using sta = lp::io_register<lp::u32_t, base_address + 0x34>;
    /* CE-ATA command completion signal               received for CMD61 */
    using sta_ceataend = lp::assoc_bit<sta, 23>;
    /* SDIO interrupt received */
    using sta_sdioit = lp::assoc_bit<sta, 22>;
    /* Data available in receive               FIFO */
    using sta_rxdavl = lp::assoc_bit<sta, 21>;
    /* Data available in transmit               FIFO */
    using sta_txdavl = lp::assoc_bit<sta, 20>;
    /* Receive FIFO empty */
    using sta_rxfifoe = lp::assoc_bit<sta, 19>;
    /* Transmit FIFO empty */
    using sta_txfifoe = lp::assoc_bit<sta, 18>;
    /* Receive FIFO full */
    using sta_rxfifof = lp::assoc_bit<sta, 17>;
    /* Transmit FIFO full */
    using sta_txfifof = lp::assoc_bit<sta, 16>;
    /* Receive FIFO half full: there are at               least 8 words in the FIFO */
    using sta_rxfifohf = lp::assoc_bit<sta, 15>;
    /* Transmit FIFO half empty: at least 8               words can be written into the FIFO */
    using sta_txfifohe = lp::assoc_bit<sta, 14>;
    /* Data receive in progress */
    using sta_rxact = lp::assoc_bit<sta, 13>;
    /* Data transmit in progress */
    using sta_txact = lp::assoc_bit<sta, 12>;
    /* Command transfer in               progress */
    using sta_cmdact = lp::assoc_bit<sta, 11>;
    /* Data block sent/received (CRC check               passed) */
    using sta_dbckend = lp::assoc_bit<sta, 10>;
    /* Start bit not detected on all data               signals in wide bus mode */
    using sta_stbiterr = lp::assoc_bit<sta, 9>;
    /* Data end (data counter, SDIDCOUNT, is               zero) */
    using sta_dataend = lp::assoc_bit<sta, 8>;
    /* Command sent (no response               required) */
    using sta_cmdsent = lp::assoc_bit<sta, 7>;
    /* Command response received (CRC check               passed) */
    using sta_cmdrend = lp::assoc_bit<sta, 6>;
    /* Received FIFO overrun               error */
    using sta_rxoverr = lp::assoc_bit<sta, 5>;
    /* Transmit FIFO underrun               error */
    using sta_txunderr = lp::assoc_bit<sta, 4>;
    /* Data timeout */
    using sta_dtimeout = lp::assoc_bit<sta, 3>;
    /* Command response timeout */
    using sta_ctimeout = lp::assoc_bit<sta, 2>;
    /* Data block sent/received (CRC check               failed) */
    using sta_dcrcfail = lp::assoc_bit<sta, 1>;
    /* Command response received (CRC check               failed) */
    using sta_ccrcfail = lp::assoc_bit<sta, 0>;


    /* interrupt clear register */
    using icr = lp::io_register<lp::u32_t, base_address + 0x38>;
    /* CEATAEND flag clear bit */
    using icr_ceataendc = lp::assoc_bit<icr, 23>;
    /* SDIOIT flag clear bit */
    using icr_sdioitc = lp::assoc_bit<icr, 22>;
    /* DBCKEND flag clear bit */
    using icr_dbckendc = lp::assoc_bit<icr, 10>;
    /* STBITERR flag clear bit */
    using icr_stbiterrc = lp::assoc_bit<icr, 9>;
    /* DATAEND flag clear bit */
    using icr_dataendc = lp::assoc_bit<icr, 8>;
    /* CMDSENT flag clear bit */
    using icr_cmdsentc = lp::assoc_bit<icr, 7>;
    /* CMDREND flag clear bit */
    using icr_cmdrendc = lp::assoc_bit<icr, 6>;
    /* RXOVERR flag clear bit */
    using icr_rxoverrc = lp::assoc_bit<icr, 5>;
    /* TXUNDERR flag clear bit */
    using icr_txunderrc = lp::assoc_bit<icr, 4>;
    /* DTIMEOUT flag clear bit */
    using icr_dtimeoutc = lp::assoc_bit<icr, 3>;
    /* CTIMEOUT flag clear bit */
    using icr_ctimeoutc = lp::assoc_bit<icr, 2>;
    /* DCRCFAIL flag clear bit */
    using icr_dcrcfailc = lp::assoc_bit<icr, 1>;
    /* CCRCFAIL flag clear bit */
    using icr_ccrcfailc = lp::assoc_bit<icr, 0>;


    /* mask register */
    using mask = lp::io_register<lp::u32_t, base_address + 0x3c>;
    /* CE-ATA command completion signal               received interrupt enable */
    using mask_ceataendie = lp::assoc_bit<mask, 23>;
    /* SDIO mode interrupt received interrupt               enable */
    using mask_sdioitie = lp::assoc_bit<mask, 22>;
    /* Data available in Rx FIFO interrupt               enable */
    using mask_rxdavlie = lp::assoc_bit<mask, 21>;
    /* Data available in Tx FIFO interrupt               enable */
    using mask_txdavlie = lp::assoc_bit<mask, 20>;
    /* Rx FIFO empty interrupt               enable */
    using mask_rxfifoeie = lp::assoc_bit<mask, 19>;
    /* Tx FIFO empty interrupt               enable */
    using mask_txfifoeie = lp::assoc_bit<mask, 18>;
    /* Rx FIFO full interrupt               enable */
    using mask_rxfifofie = lp::assoc_bit<mask, 17>;
    /* Tx FIFO full interrupt               enable */
    using mask_txfifofie = lp::assoc_bit<mask, 16>;
    /* Rx FIFO half full interrupt               enable */
    using mask_rxfifohfie = lp::assoc_bit<mask, 15>;
    /* Tx FIFO half empty interrupt               enable */
    using mask_txfifoheie = lp::assoc_bit<mask, 14>;
    /* Data receive acting interrupt               enable */
    using mask_rxactie = lp::assoc_bit<mask, 13>;
    /* Data transmit acting interrupt               enable */
    using mask_txactie = lp::assoc_bit<mask, 12>;
    /* Command acting interrupt               enable */
    using mask_cmdactie = lp::assoc_bit<mask, 11>;
    /* Data block end interrupt               enable */
    using mask_dbckendie = lp::assoc_bit<mask, 10>;
    /* Start bit error interrupt               enable */
    using mask_stbiterrie = lp::assoc_bit<mask, 9>;
    /* Data end interrupt enable */
    using mask_dataendie = lp::assoc_bit<mask, 8>;
    /* Command sent interrupt               enable */
    using mask_cmdsentie = lp::assoc_bit<mask, 7>;
    /* Command response received interrupt               enable */
    using mask_cmdrendie = lp::assoc_bit<mask, 6>;
    /* Rx FIFO overrun error interrupt               enable */
    using mask_rxoverrie = lp::assoc_bit<mask, 5>;
    /* Tx FIFO underrun error interrupt               enable */
    using mask_txunderrie = lp::assoc_bit<mask, 4>;
    /* Data timeout interrupt               enable */
    using mask_dtimeoutie = lp::assoc_bit<mask, 3>;
    /* Command timeout interrupt               enable */
    using mask_ctimeoutie = lp::assoc_bit<mask, 2>;
    /* Data CRC fail interrupt               enable */
    using mask_dcrcfailie = lp::assoc_bit<mask, 1>;
    /* Command CRC fail interrupt               enable */
    using mask_ccrcfailie = lp::assoc_bit<mask, 0>;


    /* FIFO counter register */
    using fifocnt = lp::io_register<lp::u32_t, base_address + 0x48>;
    /* Remaining number of words to be written               to or read from the FIFO */
    using fifocnt_fifocount = lp::assoc_bit<fifocnt, 0, 24>;


    /* data FIFO register */
    using fifo = lp::io_register<lp::u32_t, base_address + 0x80>;
    /* Receive and transmit FIFO               data */
    using fifo_fifodata = lp::assoc_bit<fifo, 0, 32>;


};

using sdmmc1 = sdmmc_t<0x40012800>;

#endif // SDIO_HH
