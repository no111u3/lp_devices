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
 * Hardware support for quadspi
 * @file quadspi.hh
 * @author Boris Vinogradov
 */

#include <associate_bit.hh>
#include <io_register.hh>
#include <types.hh>

#ifndef QUADSPI_HH
#define QUADSPI_HH

/* QuadSPI interface */
template <lp::addr_t base_address>
struct quadspi_t {
    /* control register */
    using cr = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* Clock prescaler */
    using cr_prescaler = lp::assoc_bit<cr, 24, 8>;
    /* Polling match mode */
    using cr_pmm = lp::assoc_bit<cr, 23>;
    /* Automatic poll mode stop */
    using cr_apms = lp::assoc_bit<cr, 22>;
    /* TimeOut interrupt enable */
    using cr_toie = lp::assoc_bit<cr, 20>;
    /* Status match interrupt               enable */
    using cr_smie = lp::assoc_bit<cr, 19>;
    /* FIFO threshold interrupt               enable */
    using cr_ftie = lp::assoc_bit<cr, 18>;
    /* Transfer complete interrupt               enable */
    using cr_tcie = lp::assoc_bit<cr, 17>;
    /* Transfer error interrupt               enable */
    using cr_teie = lp::assoc_bit<cr, 16>;
    /* IFO threshold level */
    using cr_fthres = lp::assoc_bit<cr, 8, 5>;
    /* FLASH memory selection */
    using cr_fsel = lp::assoc_bit<cr, 7>;
    /* Dual-flash mode */
    using cr_dfm = lp::assoc_bit<cr, 6>;
    /* Sample shift */
    using cr_sshift = lp::assoc_bit<cr, 4>;
    /* Timeout counter enable */
    using cr_tcen = lp::assoc_bit<cr, 3>;
    /* DMA enable */
    using cr_dmaen = lp::assoc_bit<cr, 2>;
    /* Abort request */
    using cr_abort = lp::assoc_bit<cr, 1>;
    /* Enable */
    using cr_en = lp::assoc_bit<cr, 0>;


    /* device configuration register */
    using dcr = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* FLASH memory size */
    using dcr_fsize = lp::assoc_bit<dcr, 16, 5>;
    /* Chip select high time */
    using dcr_csht = lp::assoc_bit<dcr, 8, 3>;
    /* Mode 0 / mode 3 */
    using dcr_ckmode = lp::assoc_bit<dcr, 0>;


    /* status register */
    using sr = lp::io_register<lp::u32_t, base_address + 0x8>;
    /* FIFO level */
    using sr_flevel = lp::assoc_bit<sr, 8, 7>;
    /* Busy */
    using sr_busy = lp::assoc_bit<sr, 5>;
    /* Timeout flag */
    using sr_tof = lp::assoc_bit<sr, 4>;
    /* Status match flag */
    using sr_smf = lp::assoc_bit<sr, 3>;
    /* FIFO threshold flag */
    using sr_ftf = lp::assoc_bit<sr, 2>;
    /* Transfer complete flag */
    using sr_tcf = lp::assoc_bit<sr, 1>;
    /* Transfer error flag */
    using sr_tef = lp::assoc_bit<sr, 0>;


    /* flag clear register */
    using fcr = lp::io_register<lp::u32_t, base_address + 0xc>;
    /* Clear timeout flag */
    using fcr_ctof = lp::assoc_bit<fcr, 4>;
    /* Clear status match flag */
    using fcr_csmf = lp::assoc_bit<fcr, 3>;
    /* Clear transfer complete               flag */
    using fcr_ctcf = lp::assoc_bit<fcr, 1>;
    /* Clear transfer error flag */
    using fcr_ctef = lp::assoc_bit<fcr, 0>;


    /* data length register */
    using dlr = lp::io_register<lp::u32_t, base_address + 0x10>;
    /* Data length */
    using dlr_dl = lp::assoc_bit<dlr, 0, 32>;


    /* communication configuration           register */
    using ccr = lp::io_register<lp::u32_t, base_address + 0x14>;
    /* Double data rate mode */
    using ccr_ddrm = lp::assoc_bit<ccr, 31>;
    /* DDR hold half cycle */
    using ccr_dhhc = lp::assoc_bit<ccr, 30>;
    /* Send instruction only once               mode */
    using ccr_sioo = lp::assoc_bit<ccr, 28>;
    /* Functional mode */
    using ccr_fmode = lp::assoc_bit<ccr, 26, 2>;
    /* Data mode */
    using ccr_dmode = lp::assoc_bit<ccr, 24, 2>;
    /* Number of dummy cycles */
    using ccr_dcyc = lp::assoc_bit<ccr, 18, 5>;
    /* Alternate bytes size */
    using ccr_absize = lp::assoc_bit<ccr, 16, 2>;
    /* Alternate bytes mode */
    using ccr_abmode = lp::assoc_bit<ccr, 14, 2>;
    /* Address size */
    using ccr_adsize = lp::assoc_bit<ccr, 12, 2>;
    /* Address mode */
    using ccr_admode = lp::assoc_bit<ccr, 10, 2>;
    /* Instruction mode */
    using ccr_imode = lp::assoc_bit<ccr, 8, 2>;
    /* Instruction */
    using ccr_instruction = lp::assoc_bit<ccr, 0, 8>;


    /* address register */
    using ar = lp::io_register<lp::u32_t, base_address + 0x18>;
    /* Address */
    using ar_address = lp::assoc_bit<ar, 0, 32>;


    /* ABR */
    using abr = lp::io_register<lp::u32_t, base_address + 0x1c>;
    /* ALTERNATE */
    using abr_alternate = lp::assoc_bit<abr, 0, 32>;


    /* data register */
    using dr = lp::io_register<lp::u32_t, base_address + 0x20>;
    /* Data */
    using dr_data = lp::assoc_bit<dr, 0, 32>;


    /* polling status mask register */
    using psmkr = lp::io_register<lp::u32_t, base_address + 0x24>;
    /* Status mask */
    using psmkr_mask = lp::assoc_bit<psmkr, 0, 32>;


    /* polling status match register */
    using psmar = lp::io_register<lp::u32_t, base_address + 0x28>;
    /* Status match */
    using psmar_match = lp::assoc_bit<psmar, 0, 32>;


    /* polling interval register */
    using pir = lp::io_register<lp::u32_t, base_address + 0x2c>;
    /* Polling interval */
    using pir_interval = lp::assoc_bit<pir, 0, 16>;


    /* low-power timeout register */
    using lptr = lp::io_register<lp::u32_t, base_address + 0x30>;
    /* Timeout period */
    using lptr_timeout = lp::assoc_bit<lptr, 0, 16>;


};

using quadspi = quadspi_t<0xa0001000>;

#endif // QUADSPI_HH
