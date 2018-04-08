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
 * Hardware support for dma2d
 * @file dma2d.hh
 * @author Boris Vinogradov
 */

#include <associate_bit.hh>
#include <io_register.hh>
#include <types.hh>

#ifndef DMA2D_HH
#define DMA2D_HH

/* DMA2D controller */
template <lp::addr_t base_address>
struct dmad_t {
    /* control register */
    using cr = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* DMA2D mode */
    using cr_mode = lp::assoc_bit<cr, 16, 2>;
    /* Configuration Error Interrupt               Enable */
    using cr_ceie = lp::assoc_bit<cr, 13>;
    /* CLUT transfer complete interrupt               enable */
    using cr_ctcie = lp::assoc_bit<cr, 12>;
    /* CLUT access error interrupt               enable */
    using cr_caeie = lp::assoc_bit<cr, 11>;
    /* Transfer watermark interrupt               enable */
    using cr_twie = lp::assoc_bit<cr, 10>;
    /* Transfer complete interrupt               enable */
    using cr_tcie = lp::assoc_bit<cr, 9>;
    /* Transfer error interrupt               enable */
    using cr_teie = lp::assoc_bit<cr, 8>;
    /* Abort */
    using cr_abort = lp::assoc_bit<cr, 2>;
    /* Suspend */
    using cr_susp = lp::assoc_bit<cr, 1>;
    /* Start */
    using cr_start = lp::assoc_bit<cr, 0>;


    /* Interrupt Status Register */
    using isr = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* Configuration error interrupt               flag */
    using isr_ceif = lp::assoc_bit<isr, 5>;
    /* CLUT transfer complete interrupt               flag */
    using isr_ctcif = lp::assoc_bit<isr, 4>;
    /* CLUT access error interrupt               flag */
    using isr_caeif = lp::assoc_bit<isr, 3>;
    /* Transfer watermark interrupt               flag */
    using isr_twif = lp::assoc_bit<isr, 2>;
    /* Transfer complete interrupt               flag */
    using isr_tcif = lp::assoc_bit<isr, 1>;
    /* Transfer error interrupt               flag */
    using isr_teif = lp::assoc_bit<isr, 0>;


    /* interrupt flag clear register */
    using ifcr = lp::io_register<lp::u32_t, base_address + 0x8>;
    /* Clear configuration error interrupt               flag */
    using ifcr_cceif = lp::assoc_bit<ifcr, 5>;
    /* Clear CLUT transfer complete interrupt               flag */
    using ifcr_cctcif = lp::assoc_bit<ifcr, 4>;
    /* Clear CLUT access error interrupt               flag */
    using ifcr_caecif = lp::assoc_bit<ifcr, 3>;
    /* Clear transfer watermark interrupt               flag */
    using ifcr_ctwif = lp::assoc_bit<ifcr, 2>;
    /* Clear transfer complete interrupt               flag */
    using ifcr_ctcif = lp::assoc_bit<ifcr, 1>;
    /* Clear Transfer error interrupt               flag */
    using ifcr_cteif = lp::assoc_bit<ifcr, 0>;


    /* foreground memory address           register */
    using fgmar = lp::io_register<lp::u32_t, base_address + 0xc>;
    /* Memory address */
    using fgmar_ma = lp::assoc_bit<fgmar, 0, 32>;


    /* foreground offset register */
    using fgor = lp::io_register<lp::u32_t, base_address + 0x10>;
    /* Line offset */
    using fgor_lo = lp::assoc_bit<fgor, 0, 14>;


    /* background memory address           register */
    using bgmar = lp::io_register<lp::u32_t, base_address + 0x14>;
    /* Memory address */
    using bgmar_ma = lp::assoc_bit<bgmar, 0, 32>;


    /* background offset register */
    using bgor = lp::io_register<lp::u32_t, base_address + 0x18>;
    /* Line offset */
    using bgor_lo = lp::assoc_bit<bgor, 0, 14>;


    /* foreground PFC control           register */
    using fgpfccr = lp::io_register<lp::u32_t, base_address + 0x1c>;
    /* Alpha value */
    using fgpfccr_alpha = lp::assoc_bit<fgpfccr, 24, 8>;
    /* Alpha mode */
    using fgpfccr_am = lp::assoc_bit<fgpfccr, 16, 2>;
    /* CLUT size */
    using fgpfccr_cs = lp::assoc_bit<fgpfccr, 8, 8>;
    /* Start */
    using fgpfccr_start = lp::assoc_bit<fgpfccr, 5>;
    /* CLUT color mode */
    using fgpfccr_ccm = lp::assoc_bit<fgpfccr, 4>;
    /* Color mode */
    using fgpfccr_cm = lp::assoc_bit<fgpfccr, 0, 4>;
    /* Red Blue Swap */
    using fgpfccr_rbs = lp::assoc_bit<fgpfccr, 21>;
    /* Alpha Inverted */
    using fgpfccr_ai = lp::assoc_bit<fgpfccr, 20>;


    /* foreground color register */
    using fgcolr = lp::io_register<lp::u32_t, base_address + 0x20>;
    /* Red Value */
    using fgcolr_red = lp::assoc_bit<fgcolr, 16, 8>;
    /* Green Value */
    using fgcolr_green = lp::assoc_bit<fgcolr, 8, 8>;
    /* Blue Value */
    using fgcolr_blue = lp::assoc_bit<fgcolr, 0, 8>;


    /* background PFC control           register */
    using bgpfccr = lp::io_register<lp::u32_t, base_address + 0x24>;
    /* Alpha value */
    using bgpfccr_alpha = lp::assoc_bit<bgpfccr, 24, 8>;
    /* Alpha mode */
    using bgpfccr_am = lp::assoc_bit<bgpfccr, 16, 2>;
    /* CLUT size */
    using bgpfccr_cs = lp::assoc_bit<bgpfccr, 8, 8>;
    /* Start */
    using bgpfccr_start = lp::assoc_bit<bgpfccr, 5>;
    /* CLUT Color mode */
    using bgpfccr_ccm = lp::assoc_bit<bgpfccr, 4>;
    /* Color mode */
    using bgpfccr_cm = lp::assoc_bit<bgpfccr, 0, 4>;
    /* Red Blue Swap */
    using bgpfccr_rbs = lp::assoc_bit<bgpfccr, 21>;
    /* Alpha Inverted */
    using bgpfccr_ai = lp::assoc_bit<bgpfccr, 20>;


    /* background color register */
    using bgcolr = lp::io_register<lp::u32_t, base_address + 0x28>;
    /* Red Value */
    using bgcolr_red = lp::assoc_bit<bgcolr, 16, 8>;
    /* Green Value */
    using bgcolr_green = lp::assoc_bit<bgcolr, 8, 8>;
    /* Blue Value */
    using bgcolr_blue = lp::assoc_bit<bgcolr, 0, 8>;


    /* foreground CLUT memory address           register */
    using fgcmar = lp::io_register<lp::u32_t, base_address + 0x2c>;
    /* Memory Address */
    using fgcmar_ma = lp::assoc_bit<fgcmar, 0, 32>;


    /* background CLUT memory address           register */
    using bgcmar = lp::io_register<lp::u32_t, base_address + 0x30>;
    /* Memory address */
    using bgcmar_ma = lp::assoc_bit<bgcmar, 0, 32>;


    /* output PFC control register */
    using opfccr = lp::io_register<lp::u32_t, base_address + 0x34>;
    /* Color mode */
    using opfccr_cm = lp::assoc_bit<opfccr, 0, 3>;
    /* Red Blue Swap */
    using opfccr_rbs = lp::assoc_bit<opfccr, 21>;
    /* Alpha Inverted */
    using opfccr_ai = lp::assoc_bit<opfccr, 20>;


    /* output color register */
    using ocolr = lp::io_register<lp::u32_t, base_address + 0x38>;
    /* Alpha Channel Value */
    using ocolr_aplha = lp::assoc_bit<ocolr, 24, 8>;
    /* Red Value */
    using ocolr_red = lp::assoc_bit<ocolr, 16, 8>;
    /* Green Value */
    using ocolr_green = lp::assoc_bit<ocolr, 8, 8>;
    /* Blue Value */
    using ocolr_blue = lp::assoc_bit<ocolr, 0, 8>;


    /* output memory address register */
    using omar = lp::io_register<lp::u32_t, base_address + 0x3c>;
    /* Memory Address */
    using omar_ma = lp::assoc_bit<omar, 0, 32>;


    /* output offset register */
    using oor = lp::io_register<lp::u32_t, base_address + 0x40>;
    /* Line Offset */
    using oor_lo = lp::assoc_bit<oor, 0, 14>;


    /* number of line register */
    using nlr = lp::io_register<lp::u32_t, base_address + 0x44>;
    /* Pixel per lines */
    using nlr_pl = lp::assoc_bit<nlr, 16, 14>;
    /* Number of lines */
    using nlr_nl = lp::assoc_bit<nlr, 0, 16>;


    /* line watermark register */
    using lwr = lp::io_register<lp::u32_t, base_address + 0x48>;
    /* Line watermark */
    using lwr_lw = lp::assoc_bit<lwr, 0, 16>;


    /* AHB master timer configuration           register */
    using amtcr = lp::io_register<lp::u32_t, base_address + 0x4c>;
    /* Dead Time */
    using amtcr_dt = lp::assoc_bit<amtcr, 8, 8>;
    /* Enable */
    using amtcr_en = lp::assoc_bit<amtcr, 0>;


    /* FGCLUT */
    using fgclut = lp::io_register<lp::u32_t, base_address + 0x400>;
    /* APLHA */
    using fgclut_aplha = lp::assoc_bit<fgclut, 24, 8>;
    /* RED */
    using fgclut_red = lp::assoc_bit<fgclut, 16, 8>;
    /* GREEN */
    using fgclut_green = lp::assoc_bit<fgclut, 8, 8>;
    /* BLUE */
    using fgclut_blue = lp::assoc_bit<fgclut, 0, 8>;


    /* BGCLUT */
    using bgclut = lp::io_register<lp::u32_t, base_address + 0x800>;
    /* APLHA */
    using bgclut_aplha = lp::assoc_bit<bgclut, 24, 8>;
    /* RED */
    using bgclut_red = lp::assoc_bit<bgclut, 16, 8>;
    /* GREEN */
    using bgclut_green = lp::assoc_bit<bgclut, 8, 8>;
    /* BLUE */
    using bgclut_blue = lp::assoc_bit<bgclut, 0, 8>;


};

using dma2d = dmad_t<0x4002b000>;

#endif // DMA2D_HH
