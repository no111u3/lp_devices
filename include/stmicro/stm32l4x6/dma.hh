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
 * Hardware support for dma
 * @file dma.hh
 * @author Boris Vinogradov
 */

#include <associate_bit.hh>
#include <io_register.hh>
#include <types.hh>

#ifndef DMA_HH
#define DMA_HH

/* Direct memory access controller */
template <lp::addr_t base_address>
struct dma_t {
    /* interrupt status register */
    using isr = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* Channel x transfer error flag (x = 1               ..7) */
    using isr_teif7 = lp::assoc_bit<isr, 27>;
    /* Channel x half transfer flag (x = 1               ..7) */
    using isr_htif7 = lp::assoc_bit<isr, 26>;
    /* Channel x transfer complete flag (x = 1               ..7) */
    using isr_tcif7 = lp::assoc_bit<isr, 25>;
    /* Channel x global interrupt flag (x = 1               ..7) */
    using isr_gif7 = lp::assoc_bit<isr, 24>;
    /* Channel x transfer error flag (x = 1               ..7) */
    using isr_teif6 = lp::assoc_bit<isr, 23>;
    /* Channel x half transfer flag (x = 1               ..7) */
    using isr_htif6 = lp::assoc_bit<isr, 22>;
    /* Channel x transfer complete flag (x = 1               ..7) */
    using isr_tcif6 = lp::assoc_bit<isr, 21>;
    /* Channel x global interrupt flag (x = 1               ..7) */
    using isr_gif6 = lp::assoc_bit<isr, 20>;
    /* Channel x transfer error flag (x = 1               ..7) */
    using isr_teif5 = lp::assoc_bit<isr, 19>;
    /* Channel x half transfer flag (x = 1               ..7) */
    using isr_htif5 = lp::assoc_bit<isr, 18>;
    /* Channel x transfer complete flag (x = 1               ..7) */
    using isr_tcif5 = lp::assoc_bit<isr, 17>;
    /* Channel x global interrupt flag (x = 1               ..7) */
    using isr_gif5 = lp::assoc_bit<isr, 16>;
    /* Channel x transfer error flag (x = 1               ..7) */
    using isr_teif4 = lp::assoc_bit<isr, 15>;
    /* Channel x half transfer flag (x = 1               ..7) */
    using isr_htif4 = lp::assoc_bit<isr, 14>;
    /* Channel x transfer complete flag (x = 1               ..7) */
    using isr_tcif4 = lp::assoc_bit<isr, 13>;
    /* Channel x global interrupt flag (x = 1               ..7) */
    using isr_gif4 = lp::assoc_bit<isr, 12>;
    /* Channel x transfer error flag (x = 1               ..7) */
    using isr_teif3 = lp::assoc_bit<isr, 11>;
    /* Channel x half transfer flag (x = 1               ..7) */
    using isr_htif3 = lp::assoc_bit<isr, 10>;
    /* Channel x transfer complete flag (x = 1               ..7) */
    using isr_tcif3 = lp::assoc_bit<isr, 9>;
    /* Channel x global interrupt flag (x = 1               ..7) */
    using isr_gif3 = lp::assoc_bit<isr, 8>;
    /* Channel x transfer error flag (x = 1               ..7) */
    using isr_teif2 = lp::assoc_bit<isr, 7>;
    /* Channel x half transfer flag (x = 1               ..7) */
    using isr_htif2 = lp::assoc_bit<isr, 6>;
    /* Channel x transfer complete flag (x = 1               ..7) */
    using isr_tcif2 = lp::assoc_bit<isr, 5>;
    /* Channel x global interrupt flag (x = 1               ..7) */
    using isr_gif2 = lp::assoc_bit<isr, 4>;
    /* Channel x transfer error flag (x = 1               ..7) */
    using isr_teif1 = lp::assoc_bit<isr, 3>;
    /* Channel x half transfer flag (x = 1               ..7) */
    using isr_htif1 = lp::assoc_bit<isr, 2>;
    /* Channel x transfer complete flag (x = 1               ..7) */
    using isr_tcif1 = lp::assoc_bit<isr, 1>;
    /* Channel x global interrupt flag (x = 1               ..7) */
    using isr_gif1 = lp::assoc_bit<isr, 0>;


    /* interrupt flag clear register */
    using ifcr = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* Channel x transfer error clear (x = 1               ..7) */
    using ifcr_cteif7 = lp::assoc_bit<ifcr, 27>;
    /* Channel x half transfer clear (x = 1               ..7) */
    using ifcr_chtif7 = lp::assoc_bit<ifcr, 26>;
    /* Channel x transfer complete clear (x = 1               ..7) */
    using ifcr_ctcif7 = lp::assoc_bit<ifcr, 25>;
    /* Channel x global interrupt clear (x = 1               ..7) */
    using ifcr_cgif7 = lp::assoc_bit<ifcr, 24>;
    /* Channel x transfer error clear (x = 1               ..7) */
    using ifcr_cteif6 = lp::assoc_bit<ifcr, 23>;
    /* Channel x half transfer clear (x = 1               ..7) */
    using ifcr_chtif6 = lp::assoc_bit<ifcr, 22>;
    /* Channel x transfer complete clear (x = 1               ..7) */
    using ifcr_ctcif6 = lp::assoc_bit<ifcr, 21>;
    /* Channel x global interrupt clear (x = 1               ..7) */
    using ifcr_cgif6 = lp::assoc_bit<ifcr, 20>;
    /* Channel x transfer error clear (x = 1               ..7) */
    using ifcr_cteif5 = lp::assoc_bit<ifcr, 19>;
    /* Channel x half transfer clear (x = 1               ..7) */
    using ifcr_chtif5 = lp::assoc_bit<ifcr, 18>;
    /* Channel x transfer complete clear (x = 1               ..7) */
    using ifcr_ctcif5 = lp::assoc_bit<ifcr, 17>;
    /* Channel x global interrupt clear (x = 1               ..7) */
    using ifcr_cgif5 = lp::assoc_bit<ifcr, 16>;
    /* Channel x transfer error clear (x = 1               ..7) */
    using ifcr_cteif4 = lp::assoc_bit<ifcr, 15>;
    /* Channel x half transfer clear (x = 1               ..7) */
    using ifcr_chtif4 = lp::assoc_bit<ifcr, 14>;
    /* Channel x transfer complete clear (x = 1               ..7) */
    using ifcr_ctcif4 = lp::assoc_bit<ifcr, 13>;
    /* Channel x global interrupt clear (x = 1               ..7) */
    using ifcr_cgif4 = lp::assoc_bit<ifcr, 12>;
    /* Channel x transfer error clear (x = 1               ..7) */
    using ifcr_cteif3 = lp::assoc_bit<ifcr, 11>;
    /* Channel x half transfer clear (x = 1               ..7) */
    using ifcr_chtif3 = lp::assoc_bit<ifcr, 10>;
    /* Channel x transfer complete clear (x = 1               ..7) */
    using ifcr_ctcif3 = lp::assoc_bit<ifcr, 9>;
    /* Channel x global interrupt clear (x = 1               ..7) */
    using ifcr_cgif3 = lp::assoc_bit<ifcr, 8>;
    /* Channel x transfer error clear (x = 1               ..7) */
    using ifcr_cteif2 = lp::assoc_bit<ifcr, 7>;
    /* Channel x half transfer clear (x = 1               ..7) */
    using ifcr_chtif2 = lp::assoc_bit<ifcr, 6>;
    /* Channel x transfer complete clear (x = 1               ..7) */
    using ifcr_ctcif2 = lp::assoc_bit<ifcr, 5>;
    /* Channel x global interrupt clear (x = 1               ..7) */
    using ifcr_cgif2 = lp::assoc_bit<ifcr, 4>;
    /* Channel x transfer error clear (x = 1               ..7) */
    using ifcr_cteif1 = lp::assoc_bit<ifcr, 3>;
    /* Channel x half transfer clear (x = 1               ..7) */
    using ifcr_chtif1 = lp::assoc_bit<ifcr, 2>;
    /* Channel x transfer complete clear (x = 1               ..7) */
    using ifcr_ctcif1 = lp::assoc_bit<ifcr, 1>;
    /* Channel x global interrupt clear (x = 1               ..7) */
    using ifcr_cgif1 = lp::assoc_bit<ifcr, 0>;


    /* channel x configuration           register */
    using ccr1 = lp::io_register<lp::u32_t, base_address + 0x8>;
    /* Memory to memory mode */
    using ccr1_mem2mem = lp::assoc_bit<ccr1, 14>;
    /* Channel priority level */
    using ccr1_pl = lp::assoc_bit<ccr1, 12, 2>;
    /* Memory size */
    using ccr1_msize = lp::assoc_bit<ccr1, 10, 2>;
    /* Peripheral size */
    using ccr1_psize = lp::assoc_bit<ccr1, 8, 2>;
    /* Memory increment mode */
    using ccr1_minc = lp::assoc_bit<ccr1, 7>;
    /* Peripheral increment mode */
    using ccr1_pinc = lp::assoc_bit<ccr1, 6>;
    /* Circular mode */
    using ccr1_circ = lp::assoc_bit<ccr1, 5>;
    /* Data transfer direction */
    using ccr1_dir = lp::assoc_bit<ccr1, 4>;
    /* Transfer error interrupt               enable */
    using ccr1_teie = lp::assoc_bit<ccr1, 3>;
    /* Half transfer interrupt               enable */
    using ccr1_htie = lp::assoc_bit<ccr1, 2>;
    /* Transfer complete interrupt               enable */
    using ccr1_tcie = lp::assoc_bit<ccr1, 1>;
    /* Channel enable */
    using ccr1_en = lp::assoc_bit<ccr1, 0>;


    /* channel x number of data           register */
    using cndtr1 = lp::io_register<lp::u32_t, base_address + 0xc>;
    /* Number of data to transfer */
    using cndtr1_ndt = lp::assoc_bit<cndtr1, 0, 16>;


    /* channel x peripheral address           register */
    using cpar1 = lp::io_register<lp::u32_t, base_address + 0x10>;
    /* Peripheral address */
    using cpar1_pa = lp::assoc_bit<cpar1, 0, 32>;


    /* channel x memory address           register */
    using cmar1 = lp::io_register<lp::u32_t, base_address + 0x14>;
    /* Memory address */
    using cmar1_ma = lp::assoc_bit<cmar1, 0, 32>;


    /* channel x configuration           register */
    using ccr2 = lp::io_register<lp::u32_t, base_address + 0x1c>;
    /* Memory to memory mode */
    using ccr2_mem2mem = lp::assoc_bit<ccr2, 14>;
    /* Channel priority level */
    using ccr2_pl = lp::assoc_bit<ccr2, 12, 2>;
    /* Memory size */
    using ccr2_msize = lp::assoc_bit<ccr2, 10, 2>;
    /* Peripheral size */
    using ccr2_psize = lp::assoc_bit<ccr2, 8, 2>;
    /* Memory increment mode */
    using ccr2_minc = lp::assoc_bit<ccr2, 7>;
    /* Peripheral increment mode */
    using ccr2_pinc = lp::assoc_bit<ccr2, 6>;
    /* Circular mode */
    using ccr2_circ = lp::assoc_bit<ccr2, 5>;
    /* Data transfer direction */
    using ccr2_dir = lp::assoc_bit<ccr2, 4>;
    /* Transfer error interrupt               enable */
    using ccr2_teie = lp::assoc_bit<ccr2, 3>;
    /* Half transfer interrupt               enable */
    using ccr2_htie = lp::assoc_bit<ccr2, 2>;
    /* Transfer complete interrupt               enable */
    using ccr2_tcie = lp::assoc_bit<ccr2, 1>;
    /* Channel enable */
    using ccr2_en = lp::assoc_bit<ccr2, 0>;


    /* channel x number of data           register */
    using cndtr2 = lp::io_register<lp::u32_t, base_address + 0x20>;
    /* Number of data to transfer */
    using cndtr2_ndt = lp::assoc_bit<cndtr2, 0, 16>;


    /* channel x peripheral address           register */
    using cpar2 = lp::io_register<lp::u32_t, base_address + 0x24>;
    /* Peripheral address */
    using cpar2_pa = lp::assoc_bit<cpar2, 0, 32>;


    /* channel x memory address           register */
    using cmar2 = lp::io_register<lp::u32_t, base_address + 0x28>;
    /* Memory address */
    using cmar2_ma = lp::assoc_bit<cmar2, 0, 32>;


    /* channel x configuration           register */
    using ccr3 = lp::io_register<lp::u32_t, base_address + 0x30>;
    /* Memory to memory mode */
    using ccr3_mem2mem = lp::assoc_bit<ccr3, 14>;
    /* Channel priority level */
    using ccr3_pl = lp::assoc_bit<ccr3, 12, 2>;
    /* Memory size */
    using ccr3_msize = lp::assoc_bit<ccr3, 10, 2>;
    /* Peripheral size */
    using ccr3_psize = lp::assoc_bit<ccr3, 8, 2>;
    /* Memory increment mode */
    using ccr3_minc = lp::assoc_bit<ccr3, 7>;
    /* Peripheral increment mode */
    using ccr3_pinc = lp::assoc_bit<ccr3, 6>;
    /* Circular mode */
    using ccr3_circ = lp::assoc_bit<ccr3, 5>;
    /* Data transfer direction */
    using ccr3_dir = lp::assoc_bit<ccr3, 4>;
    /* Transfer error interrupt               enable */
    using ccr3_teie = lp::assoc_bit<ccr3, 3>;
    /* Half transfer interrupt               enable */
    using ccr3_htie = lp::assoc_bit<ccr3, 2>;
    /* Transfer complete interrupt               enable */
    using ccr3_tcie = lp::assoc_bit<ccr3, 1>;
    /* Channel enable */
    using ccr3_en = lp::assoc_bit<ccr3, 0>;


    /* channel x number of data           register */
    using cndtr3 = lp::io_register<lp::u32_t, base_address + 0x34>;
    /* Number of data to transfer */
    using cndtr3_ndt = lp::assoc_bit<cndtr3, 0, 16>;


    /* channel x peripheral address           register */
    using cpar3 = lp::io_register<lp::u32_t, base_address + 0x38>;
    /* Peripheral address */
    using cpar3_pa = lp::assoc_bit<cpar3, 0, 32>;


    /* channel x memory address           register */
    using cmar3 = lp::io_register<lp::u32_t, base_address + 0x3c>;
    /* Memory address */
    using cmar3_ma = lp::assoc_bit<cmar3, 0, 32>;


    /* channel x configuration           register */
    using ccr4 = lp::io_register<lp::u32_t, base_address + 0x44>;
    /* Memory to memory mode */
    using ccr4_mem2mem = lp::assoc_bit<ccr4, 14>;
    /* Channel priority level */
    using ccr4_pl = lp::assoc_bit<ccr4, 12, 2>;
    /* Memory size */
    using ccr4_msize = lp::assoc_bit<ccr4, 10, 2>;
    /* Peripheral size */
    using ccr4_psize = lp::assoc_bit<ccr4, 8, 2>;
    /* Memory increment mode */
    using ccr4_minc = lp::assoc_bit<ccr4, 7>;
    /* Peripheral increment mode */
    using ccr4_pinc = lp::assoc_bit<ccr4, 6>;
    /* Circular mode */
    using ccr4_circ = lp::assoc_bit<ccr4, 5>;
    /* Data transfer direction */
    using ccr4_dir = lp::assoc_bit<ccr4, 4>;
    /* Transfer error interrupt               enable */
    using ccr4_teie = lp::assoc_bit<ccr4, 3>;
    /* Half transfer interrupt               enable */
    using ccr4_htie = lp::assoc_bit<ccr4, 2>;
    /* Transfer complete interrupt               enable */
    using ccr4_tcie = lp::assoc_bit<ccr4, 1>;
    /* Channel enable */
    using ccr4_en = lp::assoc_bit<ccr4, 0>;


    /* channel x number of data           register */
    using cndtr4 = lp::io_register<lp::u32_t, base_address + 0x48>;
    /* Number of data to transfer */
    using cndtr4_ndt = lp::assoc_bit<cndtr4, 0, 16>;


    /* channel x peripheral address           register */
    using cpar4 = lp::io_register<lp::u32_t, base_address + 0x4c>;
    /* Peripheral address */
    using cpar4_pa = lp::assoc_bit<cpar4, 0, 32>;


    /* channel x memory address           register */
    using cmar4 = lp::io_register<lp::u32_t, base_address + 0x50>;
    /* Memory address */
    using cmar4_ma = lp::assoc_bit<cmar4, 0, 32>;


    /* channel x configuration           register */
    using ccr5 = lp::io_register<lp::u32_t, base_address + 0x58>;
    /* Memory to memory mode */
    using ccr5_mem2mem = lp::assoc_bit<ccr5, 14>;
    /* Channel priority level */
    using ccr5_pl = lp::assoc_bit<ccr5, 12, 2>;
    /* Memory size */
    using ccr5_msize = lp::assoc_bit<ccr5, 10, 2>;
    /* Peripheral size */
    using ccr5_psize = lp::assoc_bit<ccr5, 8, 2>;
    /* Memory increment mode */
    using ccr5_minc = lp::assoc_bit<ccr5, 7>;
    /* Peripheral increment mode */
    using ccr5_pinc = lp::assoc_bit<ccr5, 6>;
    /* Circular mode */
    using ccr5_circ = lp::assoc_bit<ccr5, 5>;
    /* Data transfer direction */
    using ccr5_dir = lp::assoc_bit<ccr5, 4>;
    /* Transfer error interrupt               enable */
    using ccr5_teie = lp::assoc_bit<ccr5, 3>;
    /* Half transfer interrupt               enable */
    using ccr5_htie = lp::assoc_bit<ccr5, 2>;
    /* Transfer complete interrupt               enable */
    using ccr5_tcie = lp::assoc_bit<ccr5, 1>;
    /* Channel enable */
    using ccr5_en = lp::assoc_bit<ccr5, 0>;


    /* channel x number of data           register */
    using cndtr5 = lp::io_register<lp::u32_t, base_address + 0x5c>;
    /* Number of data to transfer */
    using cndtr5_ndt = lp::assoc_bit<cndtr5, 0, 16>;


    /* channel x peripheral address           register */
    using cpar5 = lp::io_register<lp::u32_t, base_address + 0x60>;
    /* Peripheral address */
    using cpar5_pa = lp::assoc_bit<cpar5, 0, 32>;


    /* channel x memory address           register */
    using cmar5 = lp::io_register<lp::u32_t, base_address + 0x64>;
    /* Memory address */
    using cmar5_ma = lp::assoc_bit<cmar5, 0, 32>;


    /* channel x configuration           register */
    using ccr6 = lp::io_register<lp::u32_t, base_address + 0x6c>;
    /* Memory to memory mode */
    using ccr6_mem2mem = lp::assoc_bit<ccr6, 14>;
    /* Channel priority level */
    using ccr6_pl = lp::assoc_bit<ccr6, 12, 2>;
    /* Memory size */
    using ccr6_msize = lp::assoc_bit<ccr6, 10, 2>;
    /* Peripheral size */
    using ccr6_psize = lp::assoc_bit<ccr6, 8, 2>;
    /* Memory increment mode */
    using ccr6_minc = lp::assoc_bit<ccr6, 7>;
    /* Peripheral increment mode */
    using ccr6_pinc = lp::assoc_bit<ccr6, 6>;
    /* Circular mode */
    using ccr6_circ = lp::assoc_bit<ccr6, 5>;
    /* Data transfer direction */
    using ccr6_dir = lp::assoc_bit<ccr6, 4>;
    /* Transfer error interrupt               enable */
    using ccr6_teie = lp::assoc_bit<ccr6, 3>;
    /* Half transfer interrupt               enable */
    using ccr6_htie = lp::assoc_bit<ccr6, 2>;
    /* Transfer complete interrupt               enable */
    using ccr6_tcie = lp::assoc_bit<ccr6, 1>;
    /* Channel enable */
    using ccr6_en = lp::assoc_bit<ccr6, 0>;


    /* channel x number of data           register */
    using cndtr6 = lp::io_register<lp::u32_t, base_address + 0x70>;
    /* Number of data to transfer */
    using cndtr6_ndt = lp::assoc_bit<cndtr6, 0, 16>;


    /* channel x peripheral address           register */
    using cpar6 = lp::io_register<lp::u32_t, base_address + 0x74>;
    /* Peripheral address */
    using cpar6_pa = lp::assoc_bit<cpar6, 0, 32>;


    /* channel x memory address           register */
    using cmar6 = lp::io_register<lp::u32_t, base_address + 0x78>;
    /* Memory address */
    using cmar6_ma = lp::assoc_bit<cmar6, 0, 32>;


    /* channel x configuration           register */
    using ccr7 = lp::io_register<lp::u32_t, base_address + 0x80>;
    /* Memory to memory mode */
    using ccr7_mem2mem = lp::assoc_bit<ccr7, 14>;
    /* Channel priority level */
    using ccr7_pl = lp::assoc_bit<ccr7, 12, 2>;
    /* Memory size */
    using ccr7_msize = lp::assoc_bit<ccr7, 10, 2>;
    /* Peripheral size */
    using ccr7_psize = lp::assoc_bit<ccr7, 8, 2>;
    /* Memory increment mode */
    using ccr7_minc = lp::assoc_bit<ccr7, 7>;
    /* Peripheral increment mode */
    using ccr7_pinc = lp::assoc_bit<ccr7, 6>;
    /* Circular mode */
    using ccr7_circ = lp::assoc_bit<ccr7, 5>;
    /* Data transfer direction */
    using ccr7_dir = lp::assoc_bit<ccr7, 4>;
    /* Transfer error interrupt               enable */
    using ccr7_teie = lp::assoc_bit<ccr7, 3>;
    /* Half transfer interrupt               enable */
    using ccr7_htie = lp::assoc_bit<ccr7, 2>;
    /* Transfer complete interrupt               enable */
    using ccr7_tcie = lp::assoc_bit<ccr7, 1>;
    /* Channel enable */
    using ccr7_en = lp::assoc_bit<ccr7, 0>;


    /* channel x number of data           register */
    using cndtr7 = lp::io_register<lp::u32_t, base_address + 0x84>;
    /* Number of data to transfer */
    using cndtr7_ndt = lp::assoc_bit<cndtr7, 0, 16>;


    /* channel x peripheral address           register */
    using cpar7 = lp::io_register<lp::u32_t, base_address + 0x88>;
    /* Peripheral address */
    using cpar7_pa = lp::assoc_bit<cpar7, 0, 32>;


    /* channel x memory address           register */
    using cmar7 = lp::io_register<lp::u32_t, base_address + 0x8c>;
    /* Memory address */
    using cmar7_ma = lp::assoc_bit<cmar7, 0, 32>;


    /* channel selection register */
    using cselr = lp::io_register<lp::u32_t, base_address + 0xa8>;
    /* DMA channel 7 selection */
    using cselr_c7s = lp::assoc_bit<cselr, 24, 4>;
    /* DMA channel 6 selection */
    using cselr_c6s = lp::assoc_bit<cselr, 20, 4>;
    /* DMA channel 5 selection */
    using cselr_c5s = lp::assoc_bit<cselr, 16, 4>;
    /* DMA channel 4 selection */
    using cselr_c4s = lp::assoc_bit<cselr, 12, 4>;
    /* DMA channel 3 selection */
    using cselr_c3s = lp::assoc_bit<cselr, 8, 4>;
    /* DMA channel 2 selection */
    using cselr_c2s = lp::assoc_bit<cselr, 4, 4>;
    /* DMA channel 1 selection */
    using cselr_c1s = lp::assoc_bit<cselr, 0, 4>;


};

using dma1 = dma_t<0x40020000>;
using dma2 = dma_t<0x40020400>;

#endif // DMA_HH
