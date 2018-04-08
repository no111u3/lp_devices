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
 * Hardware support for nvic
 * @file nvic.hh
 * @author Boris Vinogradov
 */

#include <associate_bit.hh>
#include <io_register.hh>
#include <types.hh>

#ifndef NVIC_HH
#define NVIC_HH

/* Nested Vectored Interrupt
      Controller */
template <lp::addr_t base_address>
struct nvic_t {
    /* Interrupt Set-Enable Register */
    using iser0 = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* SETENA */
    using iser0_setena = lp::assoc_bit<iser0, 0, 32>;


    /* Interrupt Set-Enable Register */
    using iser1 = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* SETENA */
    using iser1_setena = lp::assoc_bit<iser1, 0, 32>;


    /* Interrupt Set-Enable Register */
    using iser2 = lp::io_register<lp::u32_t, base_address + 0x8>;
    /* SETENA */
    using iser2_setena = lp::assoc_bit<iser2, 0, 32>;


    /* Interrupt Clear-Enable           Register */
    using icer0 = lp::io_register<lp::u32_t, base_address + 0x80>;
    /* CLRENA */
    using icer0_clrena = lp::assoc_bit<icer0, 0, 32>;


    /* Interrupt Clear-Enable           Register */
    using icer1 = lp::io_register<lp::u32_t, base_address + 0x84>;
    /* CLRENA */
    using icer1_clrena = lp::assoc_bit<icer1, 0, 32>;


    /* Interrupt Clear-Enable           Register */
    using icer2 = lp::io_register<lp::u32_t, base_address + 0x88>;
    /* CLRENA */
    using icer2_clrena = lp::assoc_bit<icer2, 0, 32>;


    /* Interrupt Set-Pending Register */
    using ispr0 = lp::io_register<lp::u32_t, base_address + 0x100>;
    /* SETPEND */
    using ispr0_setpend = lp::assoc_bit<ispr0, 0, 32>;


    /* Interrupt Set-Pending Register */
    using ispr1 = lp::io_register<lp::u32_t, base_address + 0x104>;
    /* SETPEND */
    using ispr1_setpend = lp::assoc_bit<ispr1, 0, 32>;


    /* Interrupt Set-Pending Register */
    using ispr2 = lp::io_register<lp::u32_t, base_address + 0x108>;
    /* SETPEND */
    using ispr2_setpend = lp::assoc_bit<ispr2, 0, 32>;


    /* Interrupt Clear-Pending           Register */
    using icpr0 = lp::io_register<lp::u32_t, base_address + 0x180>;
    /* CLRPEND */
    using icpr0_clrpend = lp::assoc_bit<icpr0, 0, 32>;


    /* Interrupt Clear-Pending           Register */
    using icpr1 = lp::io_register<lp::u32_t, base_address + 0x184>;
    /* CLRPEND */
    using icpr1_clrpend = lp::assoc_bit<icpr1, 0, 32>;


    /* Interrupt Clear-Pending           Register */
    using icpr2 = lp::io_register<lp::u32_t, base_address + 0x188>;
    /* CLRPEND */
    using icpr2_clrpend = lp::assoc_bit<icpr2, 0, 32>;


    /* Interrupt Active Bit Register */
    using iabr0 = lp::io_register<lp::u32_t, base_address + 0x200>;
    /* ACTIVE */
    using iabr0_active = lp::assoc_bit<iabr0, 0, 32>;


    /* Interrupt Active Bit Register */
    using iabr1 = lp::io_register<lp::u32_t, base_address + 0x204>;
    /* ACTIVE */
    using iabr1_active = lp::assoc_bit<iabr1, 0, 32>;


    /* Interrupt Active Bit Register */
    using iabr2 = lp::io_register<lp::u32_t, base_address + 0x208>;
    /* ACTIVE */
    using iabr2_active = lp::assoc_bit<iabr2, 0, 32>;


    /* Interrupt Priority Register */
    using ipr0 = lp::io_register<lp::u32_t, base_address + 0x300>;
    /* IPR_N0 */
    using ipr0_ipr_n0 = lp::assoc_bit<ipr0, 0, 8>;
    /* IPR_N1 */
    using ipr0_ipr_n1 = lp::assoc_bit<ipr0, 8, 8>;
    /* IPR_N2 */
    using ipr0_ipr_n2 = lp::assoc_bit<ipr0, 16, 8>;
    /* IPR_N3 */
    using ipr0_ipr_n3 = lp::assoc_bit<ipr0, 24, 8>;


    /* Interrupt Priority Register */
    using ipr1 = lp::io_register<lp::u32_t, base_address + 0x304>;
    /* IPR_N0 */
    using ipr1_ipr_n0 = lp::assoc_bit<ipr1, 0, 8>;
    /* IPR_N1 */
    using ipr1_ipr_n1 = lp::assoc_bit<ipr1, 8, 8>;
    /* IPR_N2 */
    using ipr1_ipr_n2 = lp::assoc_bit<ipr1, 16, 8>;
    /* IPR_N3 */
    using ipr1_ipr_n3 = lp::assoc_bit<ipr1, 24, 8>;


    /* Interrupt Priority Register */
    using ipr2 = lp::io_register<lp::u32_t, base_address + 0x308>;
    /* IPR_N0 */
    using ipr2_ipr_n0 = lp::assoc_bit<ipr2, 0, 8>;
    /* IPR_N1 */
    using ipr2_ipr_n1 = lp::assoc_bit<ipr2, 8, 8>;
    /* IPR_N2 */
    using ipr2_ipr_n2 = lp::assoc_bit<ipr2, 16, 8>;
    /* IPR_N3 */
    using ipr2_ipr_n3 = lp::assoc_bit<ipr2, 24, 8>;


    /* Interrupt Priority Register */
    using ipr3 = lp::io_register<lp::u32_t, base_address + 0x30c>;
    /* IPR_N0 */
    using ipr3_ipr_n0 = lp::assoc_bit<ipr3, 0, 8>;
    /* IPR_N1 */
    using ipr3_ipr_n1 = lp::assoc_bit<ipr3, 8, 8>;
    /* IPR_N2 */
    using ipr3_ipr_n2 = lp::assoc_bit<ipr3, 16, 8>;
    /* IPR_N3 */
    using ipr3_ipr_n3 = lp::assoc_bit<ipr3, 24, 8>;


    /* Interrupt Priority Register */
    using ipr4 = lp::io_register<lp::u32_t, base_address + 0x310>;
    /* IPR_N0 */
    using ipr4_ipr_n0 = lp::assoc_bit<ipr4, 0, 8>;
    /* IPR_N1 */
    using ipr4_ipr_n1 = lp::assoc_bit<ipr4, 8, 8>;
    /* IPR_N2 */
    using ipr4_ipr_n2 = lp::assoc_bit<ipr4, 16, 8>;
    /* IPR_N3 */
    using ipr4_ipr_n3 = lp::assoc_bit<ipr4, 24, 8>;


    /* Interrupt Priority Register */
    using ipr5 = lp::io_register<lp::u32_t, base_address + 0x314>;
    /* IPR_N0 */
    using ipr5_ipr_n0 = lp::assoc_bit<ipr5, 0, 8>;
    /* IPR_N1 */
    using ipr5_ipr_n1 = lp::assoc_bit<ipr5, 8, 8>;
    /* IPR_N2 */
    using ipr5_ipr_n2 = lp::assoc_bit<ipr5, 16, 8>;
    /* IPR_N3 */
    using ipr5_ipr_n3 = lp::assoc_bit<ipr5, 24, 8>;


    /* Interrupt Priority Register */
    using ipr6 = lp::io_register<lp::u32_t, base_address + 0x318>;
    /* IPR_N0 */
    using ipr6_ipr_n0 = lp::assoc_bit<ipr6, 0, 8>;
    /* IPR_N1 */
    using ipr6_ipr_n1 = lp::assoc_bit<ipr6, 8, 8>;
    /* IPR_N2 */
    using ipr6_ipr_n2 = lp::assoc_bit<ipr6, 16, 8>;
    /* IPR_N3 */
    using ipr6_ipr_n3 = lp::assoc_bit<ipr6, 24, 8>;


    /* Interrupt Priority Register */
    using ipr7 = lp::io_register<lp::u32_t, base_address + 0x31c>;
    /* IPR_N0 */
    using ipr7_ipr_n0 = lp::assoc_bit<ipr7, 0, 8>;
    /* IPR_N1 */
    using ipr7_ipr_n1 = lp::assoc_bit<ipr7, 8, 8>;
    /* IPR_N2 */
    using ipr7_ipr_n2 = lp::assoc_bit<ipr7, 16, 8>;
    /* IPR_N3 */
    using ipr7_ipr_n3 = lp::assoc_bit<ipr7, 24, 8>;


    /* Interrupt Priority Register */
    using ipr8 = lp::io_register<lp::u32_t, base_address + 0x320>;
    /* IPR_N0 */
    using ipr8_ipr_n0 = lp::assoc_bit<ipr8, 0, 8>;
    /* IPR_N1 */
    using ipr8_ipr_n1 = lp::assoc_bit<ipr8, 8, 8>;
    /* IPR_N2 */
    using ipr8_ipr_n2 = lp::assoc_bit<ipr8, 16, 8>;
    /* IPR_N3 */
    using ipr8_ipr_n3 = lp::assoc_bit<ipr8, 24, 8>;


    /* Interrupt Priority Register */
    using ipr9 = lp::io_register<lp::u32_t, base_address + 0x324>;
    /* IPR_N0 */
    using ipr9_ipr_n0 = lp::assoc_bit<ipr9, 0, 8>;
    /* IPR_N1 */
    using ipr9_ipr_n1 = lp::assoc_bit<ipr9, 8, 8>;
    /* IPR_N2 */
    using ipr9_ipr_n2 = lp::assoc_bit<ipr9, 16, 8>;
    /* IPR_N3 */
    using ipr9_ipr_n3 = lp::assoc_bit<ipr9, 24, 8>;


    /* Interrupt Priority Register */
    using ipr10 = lp::io_register<lp::u32_t, base_address + 0x328>;
    /* IPR_N0 */
    using ipr10_ipr_n0 = lp::assoc_bit<ipr10, 0, 8>;
    /* IPR_N1 */
    using ipr10_ipr_n1 = lp::assoc_bit<ipr10, 8, 8>;
    /* IPR_N2 */
    using ipr10_ipr_n2 = lp::assoc_bit<ipr10, 16, 8>;
    /* IPR_N3 */
    using ipr10_ipr_n3 = lp::assoc_bit<ipr10, 24, 8>;


    /* Interrupt Priority Register */
    using ipr11 = lp::io_register<lp::u32_t, base_address + 0x32c>;
    /* IPR_N0 */
    using ipr11_ipr_n0 = lp::assoc_bit<ipr11, 0, 8>;
    /* IPR_N1 */
    using ipr11_ipr_n1 = lp::assoc_bit<ipr11, 8, 8>;
    /* IPR_N2 */
    using ipr11_ipr_n2 = lp::assoc_bit<ipr11, 16, 8>;
    /* IPR_N3 */
    using ipr11_ipr_n3 = lp::assoc_bit<ipr11, 24, 8>;


    /* Interrupt Priority Register */
    using ipr12 = lp::io_register<lp::u32_t, base_address + 0x330>;
    /* IPR_N0 */
    using ipr12_ipr_n0 = lp::assoc_bit<ipr12, 0, 8>;
    /* IPR_N1 */
    using ipr12_ipr_n1 = lp::assoc_bit<ipr12, 8, 8>;
    /* IPR_N2 */
    using ipr12_ipr_n2 = lp::assoc_bit<ipr12, 16, 8>;
    /* IPR_N3 */
    using ipr12_ipr_n3 = lp::assoc_bit<ipr12, 24, 8>;


    /* Interrupt Priority Register */
    using ipr13 = lp::io_register<lp::u32_t, base_address + 0x334>;
    /* IPR_N0 */
    using ipr13_ipr_n0 = lp::assoc_bit<ipr13, 0, 8>;
    /* IPR_N1 */
    using ipr13_ipr_n1 = lp::assoc_bit<ipr13, 8, 8>;
    /* IPR_N2 */
    using ipr13_ipr_n2 = lp::assoc_bit<ipr13, 16, 8>;
    /* IPR_N3 */
    using ipr13_ipr_n3 = lp::assoc_bit<ipr13, 24, 8>;


    /* Interrupt Priority Register */
    using ipr14 = lp::io_register<lp::u32_t, base_address + 0x338>;
    /* IPR_N0 */
    using ipr14_ipr_n0 = lp::assoc_bit<ipr14, 0, 8>;
    /* IPR_N1 */
    using ipr14_ipr_n1 = lp::assoc_bit<ipr14, 8, 8>;
    /* IPR_N2 */
    using ipr14_ipr_n2 = lp::assoc_bit<ipr14, 16, 8>;
    /* IPR_N3 */
    using ipr14_ipr_n3 = lp::assoc_bit<ipr14, 24, 8>;


    /* Interrupt Priority Register */
    using ipr15 = lp::io_register<lp::u32_t, base_address + 0x33c>;
    /* IPR_N0 */
    using ipr15_ipr_n0 = lp::assoc_bit<ipr15, 0, 8>;
    /* IPR_N1 */
    using ipr15_ipr_n1 = lp::assoc_bit<ipr15, 8, 8>;
    /* IPR_N2 */
    using ipr15_ipr_n2 = lp::assoc_bit<ipr15, 16, 8>;
    /* IPR_N3 */
    using ipr15_ipr_n3 = lp::assoc_bit<ipr15, 24, 8>;


    /* Interrupt Priority Register */
    using ipr16 = lp::io_register<lp::u32_t, base_address + 0x340>;
    /* IPR_N0 */
    using ipr16_ipr_n0 = lp::assoc_bit<ipr16, 0, 8>;
    /* IPR_N1 */
    using ipr16_ipr_n1 = lp::assoc_bit<ipr16, 8, 8>;
    /* IPR_N2 */
    using ipr16_ipr_n2 = lp::assoc_bit<ipr16, 16, 8>;
    /* IPR_N3 */
    using ipr16_ipr_n3 = lp::assoc_bit<ipr16, 24, 8>;


    /* Interrupt Priority Register */
    using ipr17 = lp::io_register<lp::u32_t, base_address + 0x344>;
    /* IPR_N0 */
    using ipr17_ipr_n0 = lp::assoc_bit<ipr17, 0, 8>;
    /* IPR_N1 */
    using ipr17_ipr_n1 = lp::assoc_bit<ipr17, 8, 8>;
    /* IPR_N2 */
    using ipr17_ipr_n2 = lp::assoc_bit<ipr17, 16, 8>;
    /* IPR_N3 */
    using ipr17_ipr_n3 = lp::assoc_bit<ipr17, 24, 8>;


    /* Interrupt Priority Register */
    using ipr18 = lp::io_register<lp::u32_t, base_address + 0x348>;
    /* IPR_N0 */
    using ipr18_ipr_n0 = lp::assoc_bit<ipr18, 0, 8>;
    /* IPR_N1 */
    using ipr18_ipr_n1 = lp::assoc_bit<ipr18, 8, 8>;
    /* IPR_N2 */
    using ipr18_ipr_n2 = lp::assoc_bit<ipr18, 16, 8>;
    /* IPR_N3 */
    using ipr18_ipr_n3 = lp::assoc_bit<ipr18, 24, 8>;


    /* Interrupt Priority Register */
    using ipr19 = lp::io_register<lp::u32_t, base_address + 0x34c>;
    /* IPR_N0 */
    using ipr19_ipr_n0 = lp::assoc_bit<ipr19, 0, 8>;
    /* IPR_N1 */
    using ipr19_ipr_n1 = lp::assoc_bit<ipr19, 8, 8>;
    /* IPR_N2 */
    using ipr19_ipr_n2 = lp::assoc_bit<ipr19, 16, 8>;
    /* IPR_N3 */
    using ipr19_ipr_n3 = lp::assoc_bit<ipr19, 24, 8>;


    /* Interrupt Priority Register */
    using ipr20 = lp::io_register<lp::u32_t, base_address + 0x350>;
    /* IPR_N0 */
    using ipr20_ipr_n0 = lp::assoc_bit<ipr20, 0, 8>;
    /* IPR_N1 */
    using ipr20_ipr_n1 = lp::assoc_bit<ipr20, 8, 8>;
    /* IPR_N2 */
    using ipr20_ipr_n2 = lp::assoc_bit<ipr20, 16, 8>;
    /* IPR_N3 */
    using ipr20_ipr_n3 = lp::assoc_bit<ipr20, 24, 8>;


};

/* Nested vectored interrupt
      controller */
template <lp::addr_t base_address>
struct nvic_stir_t {
    /* Software trigger interrupt           register */
    using stir = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* Software generated interrupt               ID */
    using stir_intid = lp::assoc_bit<stir, 0, 9>;


};

using nvic = nvic_t<0xe000e100>;
using nvic_stir = nvic_stir_t<0xe000ef00>;

#endif // NVIC_HH
