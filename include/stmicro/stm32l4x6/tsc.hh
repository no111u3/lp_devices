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
 * Hardware support for tsc
 * @file tsc.hh
 * @author Boris Vinogradov
 */

#include <associate_bit.hh>
#include <io_register.hh>
#include <types.hh>

#ifndef TSC_HH
#define TSC_HH

/* Touch sensing controller */
template <lp::addr_t base_address>
struct tsc_t {
    /* control register */
    using cr = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* Charge transfer pulse high */
    using cr_ctph = lp::assoc_bit<cr, 28, 4>;
    /* Charge transfer pulse low */
    using cr_ctpl = lp::assoc_bit<cr, 24, 4>;
    /* Spread spectrum deviation */
    using cr_ssd = lp::assoc_bit<cr, 17, 7>;
    /* Spread spectrum enable */
    using cr_sse = lp::assoc_bit<cr, 16>;
    /* Spread spectrum prescaler */
    using cr_sspsc = lp::assoc_bit<cr, 15>;
    /* pulse generator prescaler */
    using cr_pgpsc = lp::assoc_bit<cr, 12, 3>;
    /* Max count value */
    using cr_mcv = lp::assoc_bit<cr, 5, 3>;
    /* I/O Default mode */
    using cr_iodef = lp::assoc_bit<cr, 4>;
    /* Synchronization pin               polarity */
    using cr_syncpol = lp::assoc_bit<cr, 3>;
    /* Acquisition mode */
    using cr_am = lp::assoc_bit<cr, 2>;
    /* Start a new acquisition */
    using cr_start = lp::assoc_bit<cr, 1>;
    /* Touch sensing controller               enable */
    using cr_tsce = lp::assoc_bit<cr, 0>;


    /* interrupt enable register */
    using ier = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* Max count error interrupt               enable */
    using ier_mceie = lp::assoc_bit<ier, 1>;
    /* End of acquisition interrupt               enable */
    using ier_eoaie = lp::assoc_bit<ier, 0>;


    /* interrupt clear register */
    using icr = lp::io_register<lp::u32_t, base_address + 0x8>;
    /* Max count error interrupt               clear */
    using icr_mceic = lp::assoc_bit<icr, 1>;
    /* End of acquisition interrupt               clear */
    using icr_eoaic = lp::assoc_bit<icr, 0>;


    /* interrupt status register */
    using isr = lp::io_register<lp::u32_t, base_address + 0xc>;
    /* Max count error flag */
    using isr_mcef = lp::assoc_bit<isr, 1>;
    /* End of acquisition flag */
    using isr_eoaf = lp::assoc_bit<isr, 0>;


    /* I/O hysteresis control           register */
    using iohcr = lp::io_register<lp::u32_t, base_address + 0x10>;
    /* G8_IO4 */
    using iohcr_g8_io4 = lp::assoc_bit<iohcr, 31>;
    /* G8_IO3 */
    using iohcr_g8_io3 = lp::assoc_bit<iohcr, 30>;
    /* G8_IO2 */
    using iohcr_g8_io2 = lp::assoc_bit<iohcr, 29>;
    /* G8_IO1 */
    using iohcr_g8_io1 = lp::assoc_bit<iohcr, 28>;
    /* G7_IO4 */
    using iohcr_g7_io4 = lp::assoc_bit<iohcr, 27>;
    /* G7_IO3 */
    using iohcr_g7_io3 = lp::assoc_bit<iohcr, 26>;
    /* G7_IO2 */
    using iohcr_g7_io2 = lp::assoc_bit<iohcr, 25>;
    /* G7_IO1 */
    using iohcr_g7_io1 = lp::assoc_bit<iohcr, 24>;
    /* G6_IO4 */
    using iohcr_g6_io4 = lp::assoc_bit<iohcr, 23>;
    /* G6_IO3 */
    using iohcr_g6_io3 = lp::assoc_bit<iohcr, 22>;
    /* G6_IO2 */
    using iohcr_g6_io2 = lp::assoc_bit<iohcr, 21>;
    /* G6_IO1 */
    using iohcr_g6_io1 = lp::assoc_bit<iohcr, 20>;
    /* G5_IO4 */
    using iohcr_g5_io4 = lp::assoc_bit<iohcr, 19>;
    /* G5_IO3 */
    using iohcr_g5_io3 = lp::assoc_bit<iohcr, 18>;
    /* G5_IO2 */
    using iohcr_g5_io2 = lp::assoc_bit<iohcr, 17>;
    /* G5_IO1 */
    using iohcr_g5_io1 = lp::assoc_bit<iohcr, 16>;
    /* G4_IO4 */
    using iohcr_g4_io4 = lp::assoc_bit<iohcr, 15>;
    /* G4_IO3 */
    using iohcr_g4_io3 = lp::assoc_bit<iohcr, 14>;
    /* G4_IO2 */
    using iohcr_g4_io2 = lp::assoc_bit<iohcr, 13>;
    /* G4_IO1 */
    using iohcr_g4_io1 = lp::assoc_bit<iohcr, 12>;
    /* G3_IO4 */
    using iohcr_g3_io4 = lp::assoc_bit<iohcr, 11>;
    /* G3_IO3 */
    using iohcr_g3_io3 = lp::assoc_bit<iohcr, 10>;
    /* G3_IO2 */
    using iohcr_g3_io2 = lp::assoc_bit<iohcr, 9>;
    /* G3_IO1 */
    using iohcr_g3_io1 = lp::assoc_bit<iohcr, 8>;
    /* G2_IO4 */
    using iohcr_g2_io4 = lp::assoc_bit<iohcr, 7>;
    /* G2_IO3 */
    using iohcr_g2_io3 = lp::assoc_bit<iohcr, 6>;
    /* G2_IO2 */
    using iohcr_g2_io2 = lp::assoc_bit<iohcr, 5>;
    /* G2_IO1 */
    using iohcr_g2_io1 = lp::assoc_bit<iohcr, 4>;
    /* G1_IO4 */
    using iohcr_g1_io4 = lp::assoc_bit<iohcr, 3>;
    /* G1_IO3 */
    using iohcr_g1_io3 = lp::assoc_bit<iohcr, 2>;
    /* G1_IO2 */
    using iohcr_g1_io2 = lp::assoc_bit<iohcr, 1>;
    /* G1_IO1 */
    using iohcr_g1_io1 = lp::assoc_bit<iohcr, 0>;


    /* I/O analog switch control           register */
    using ioascr = lp::io_register<lp::u32_t, base_address + 0x18>;
    /* G8_IO4 */
    using ioascr_g8_io4 = lp::assoc_bit<ioascr, 31>;
    /* G8_IO3 */
    using ioascr_g8_io3 = lp::assoc_bit<ioascr, 30>;
    /* G8_IO2 */
    using ioascr_g8_io2 = lp::assoc_bit<ioascr, 29>;
    /* G8_IO1 */
    using ioascr_g8_io1 = lp::assoc_bit<ioascr, 28>;
    /* G7_IO4 */
    using ioascr_g7_io4 = lp::assoc_bit<ioascr, 27>;
    /* G7_IO3 */
    using ioascr_g7_io3 = lp::assoc_bit<ioascr, 26>;
    /* G7_IO2 */
    using ioascr_g7_io2 = lp::assoc_bit<ioascr, 25>;
    /* G7_IO1 */
    using ioascr_g7_io1 = lp::assoc_bit<ioascr, 24>;
    /* G6_IO4 */
    using ioascr_g6_io4 = lp::assoc_bit<ioascr, 23>;
    /* G6_IO3 */
    using ioascr_g6_io3 = lp::assoc_bit<ioascr, 22>;
    /* G6_IO2 */
    using ioascr_g6_io2 = lp::assoc_bit<ioascr, 21>;
    /* G6_IO1 */
    using ioascr_g6_io1 = lp::assoc_bit<ioascr, 20>;
    /* G5_IO4 */
    using ioascr_g5_io4 = lp::assoc_bit<ioascr, 19>;
    /* G5_IO3 */
    using ioascr_g5_io3 = lp::assoc_bit<ioascr, 18>;
    /* G5_IO2 */
    using ioascr_g5_io2 = lp::assoc_bit<ioascr, 17>;
    /* G5_IO1 */
    using ioascr_g5_io1 = lp::assoc_bit<ioascr, 16>;
    /* G4_IO4 */
    using ioascr_g4_io4 = lp::assoc_bit<ioascr, 15>;
    /* G4_IO3 */
    using ioascr_g4_io3 = lp::assoc_bit<ioascr, 14>;
    /* G4_IO2 */
    using ioascr_g4_io2 = lp::assoc_bit<ioascr, 13>;
    /* G4_IO1 */
    using ioascr_g4_io1 = lp::assoc_bit<ioascr, 12>;
    /* G3_IO4 */
    using ioascr_g3_io4 = lp::assoc_bit<ioascr, 11>;
    /* G3_IO3 */
    using ioascr_g3_io3 = lp::assoc_bit<ioascr, 10>;
    /* G3_IO2 */
    using ioascr_g3_io2 = lp::assoc_bit<ioascr, 9>;
    /* G3_IO1 */
    using ioascr_g3_io1 = lp::assoc_bit<ioascr, 8>;
    /* G2_IO4 */
    using ioascr_g2_io4 = lp::assoc_bit<ioascr, 7>;
    /* G2_IO3 */
    using ioascr_g2_io3 = lp::assoc_bit<ioascr, 6>;
    /* G2_IO2 */
    using ioascr_g2_io2 = lp::assoc_bit<ioascr, 5>;
    /* G2_IO1 */
    using ioascr_g2_io1 = lp::assoc_bit<ioascr, 4>;
    /* G1_IO4 */
    using ioascr_g1_io4 = lp::assoc_bit<ioascr, 3>;
    /* G1_IO3 */
    using ioascr_g1_io3 = lp::assoc_bit<ioascr, 2>;
    /* G1_IO2 */
    using ioascr_g1_io2 = lp::assoc_bit<ioascr, 1>;
    /* G1_IO1 */
    using ioascr_g1_io1 = lp::assoc_bit<ioascr, 0>;


    /* I/O sampling control register */
    using ioscr = lp::io_register<lp::u32_t, base_address + 0x20>;
    /* G8_IO4 */
    using ioscr_g8_io4 = lp::assoc_bit<ioscr, 31>;
    /* G8_IO3 */
    using ioscr_g8_io3 = lp::assoc_bit<ioscr, 30>;
    /* G8_IO2 */
    using ioscr_g8_io2 = lp::assoc_bit<ioscr, 29>;
    /* G8_IO1 */
    using ioscr_g8_io1 = lp::assoc_bit<ioscr, 28>;
    /* G7_IO4 */
    using ioscr_g7_io4 = lp::assoc_bit<ioscr, 27>;
    /* G7_IO3 */
    using ioscr_g7_io3 = lp::assoc_bit<ioscr, 26>;
    /* G7_IO2 */
    using ioscr_g7_io2 = lp::assoc_bit<ioscr, 25>;
    /* G7_IO1 */
    using ioscr_g7_io1 = lp::assoc_bit<ioscr, 24>;
    /* G6_IO4 */
    using ioscr_g6_io4 = lp::assoc_bit<ioscr, 23>;
    /* G6_IO3 */
    using ioscr_g6_io3 = lp::assoc_bit<ioscr, 22>;
    /* G6_IO2 */
    using ioscr_g6_io2 = lp::assoc_bit<ioscr, 21>;
    /* G6_IO1 */
    using ioscr_g6_io1 = lp::assoc_bit<ioscr, 20>;
    /* G5_IO4 */
    using ioscr_g5_io4 = lp::assoc_bit<ioscr, 19>;
    /* G5_IO3 */
    using ioscr_g5_io3 = lp::assoc_bit<ioscr, 18>;
    /* G5_IO2 */
    using ioscr_g5_io2 = lp::assoc_bit<ioscr, 17>;
    /* G5_IO1 */
    using ioscr_g5_io1 = lp::assoc_bit<ioscr, 16>;
    /* G4_IO4 */
    using ioscr_g4_io4 = lp::assoc_bit<ioscr, 15>;
    /* G4_IO3 */
    using ioscr_g4_io3 = lp::assoc_bit<ioscr, 14>;
    /* G4_IO2 */
    using ioscr_g4_io2 = lp::assoc_bit<ioscr, 13>;
    /* G4_IO1 */
    using ioscr_g4_io1 = lp::assoc_bit<ioscr, 12>;
    /* G3_IO4 */
    using ioscr_g3_io4 = lp::assoc_bit<ioscr, 11>;
    /* G3_IO3 */
    using ioscr_g3_io3 = lp::assoc_bit<ioscr, 10>;
    /* G3_IO2 */
    using ioscr_g3_io2 = lp::assoc_bit<ioscr, 9>;
    /* G3_IO1 */
    using ioscr_g3_io1 = lp::assoc_bit<ioscr, 8>;
    /* G2_IO4 */
    using ioscr_g2_io4 = lp::assoc_bit<ioscr, 7>;
    /* G2_IO3 */
    using ioscr_g2_io3 = lp::assoc_bit<ioscr, 6>;
    /* G2_IO2 */
    using ioscr_g2_io2 = lp::assoc_bit<ioscr, 5>;
    /* G2_IO1 */
    using ioscr_g2_io1 = lp::assoc_bit<ioscr, 4>;
    /* G1_IO4 */
    using ioscr_g1_io4 = lp::assoc_bit<ioscr, 3>;
    /* G1_IO3 */
    using ioscr_g1_io3 = lp::assoc_bit<ioscr, 2>;
    /* G1_IO2 */
    using ioscr_g1_io2 = lp::assoc_bit<ioscr, 1>;
    /* G1_IO1 */
    using ioscr_g1_io1 = lp::assoc_bit<ioscr, 0>;


    /* I/O channel control register */
    using ioccr = lp::io_register<lp::u32_t, base_address + 0x28>;
    /* G8_IO4 */
    using ioccr_g8_io4 = lp::assoc_bit<ioccr, 31>;
    /* G8_IO3 */
    using ioccr_g8_io3 = lp::assoc_bit<ioccr, 30>;
    /* G8_IO2 */
    using ioccr_g8_io2 = lp::assoc_bit<ioccr, 29>;
    /* G8_IO1 */
    using ioccr_g8_io1 = lp::assoc_bit<ioccr, 28>;
    /* G7_IO4 */
    using ioccr_g7_io4 = lp::assoc_bit<ioccr, 27>;
    /* G7_IO3 */
    using ioccr_g7_io3 = lp::assoc_bit<ioccr, 26>;
    /* G7_IO2 */
    using ioccr_g7_io2 = lp::assoc_bit<ioccr, 25>;
    /* G7_IO1 */
    using ioccr_g7_io1 = lp::assoc_bit<ioccr, 24>;
    /* G6_IO4 */
    using ioccr_g6_io4 = lp::assoc_bit<ioccr, 23>;
    /* G6_IO3 */
    using ioccr_g6_io3 = lp::assoc_bit<ioccr, 22>;
    /* G6_IO2 */
    using ioccr_g6_io2 = lp::assoc_bit<ioccr, 21>;
    /* G6_IO1 */
    using ioccr_g6_io1 = lp::assoc_bit<ioccr, 20>;
    /* G5_IO4 */
    using ioccr_g5_io4 = lp::assoc_bit<ioccr, 19>;
    /* G5_IO3 */
    using ioccr_g5_io3 = lp::assoc_bit<ioccr, 18>;
    /* G5_IO2 */
    using ioccr_g5_io2 = lp::assoc_bit<ioccr, 17>;
    /* G5_IO1 */
    using ioccr_g5_io1 = lp::assoc_bit<ioccr, 16>;
    /* G4_IO4 */
    using ioccr_g4_io4 = lp::assoc_bit<ioccr, 15>;
    /* G4_IO3 */
    using ioccr_g4_io3 = lp::assoc_bit<ioccr, 14>;
    /* G4_IO2 */
    using ioccr_g4_io2 = lp::assoc_bit<ioccr, 13>;
    /* G4_IO1 */
    using ioccr_g4_io1 = lp::assoc_bit<ioccr, 12>;
    /* G3_IO4 */
    using ioccr_g3_io4 = lp::assoc_bit<ioccr, 11>;
    /* G3_IO3 */
    using ioccr_g3_io3 = lp::assoc_bit<ioccr, 10>;
    /* G3_IO2 */
    using ioccr_g3_io2 = lp::assoc_bit<ioccr, 9>;
    /* G3_IO1 */
    using ioccr_g3_io1 = lp::assoc_bit<ioccr, 8>;
    /* G2_IO4 */
    using ioccr_g2_io4 = lp::assoc_bit<ioccr, 7>;
    /* G2_IO3 */
    using ioccr_g2_io3 = lp::assoc_bit<ioccr, 6>;
    /* G2_IO2 */
    using ioccr_g2_io2 = lp::assoc_bit<ioccr, 5>;
    /* G2_IO1 */
    using ioccr_g2_io1 = lp::assoc_bit<ioccr, 4>;
    /* G1_IO4 */
    using ioccr_g1_io4 = lp::assoc_bit<ioccr, 3>;
    /* G1_IO3 */
    using ioccr_g1_io3 = lp::assoc_bit<ioccr, 2>;
    /* G1_IO2 */
    using ioccr_g1_io2 = lp::assoc_bit<ioccr, 1>;
    /* G1_IO1 */
    using ioccr_g1_io1 = lp::assoc_bit<ioccr, 0>;


    /* I/O group control status           register */
    using iogcsr = lp::io_register<lp::u32_t, base_address + 0x30>;
    /* Analog I/O group x status */
    using iogcsr_g8s = lp::assoc_bit<iogcsr, 23>;
    /* Analog I/O group x status */
    using iogcsr_g7s = lp::assoc_bit<iogcsr, 22>;
    /* Analog I/O group x status */
    using iogcsr_g6s = lp::assoc_bit<iogcsr, 21>;
    /* Analog I/O group x status */
    using iogcsr_g5s = lp::assoc_bit<iogcsr, 20>;
    /* Analog I/O group x status */
    using iogcsr_g4s = lp::assoc_bit<iogcsr, 19>;
    /* Analog I/O group x status */
    using iogcsr_g3s = lp::assoc_bit<iogcsr, 18>;
    /* Analog I/O group x status */
    using iogcsr_g2s = lp::assoc_bit<iogcsr, 17>;
    /* Analog I/O group x status */
    using iogcsr_g1s = lp::assoc_bit<iogcsr, 16>;
    /* Analog I/O group x enable */
    using iogcsr_g8e = lp::assoc_bit<iogcsr, 7>;
    /* Analog I/O group x enable */
    using iogcsr_g7e = lp::assoc_bit<iogcsr, 6>;
    /* Analog I/O group x enable */
    using iogcsr_g6e = lp::assoc_bit<iogcsr, 5>;
    /* Analog I/O group x enable */
    using iogcsr_g5e = lp::assoc_bit<iogcsr, 4>;
    /* Analog I/O group x enable */
    using iogcsr_g4e = lp::assoc_bit<iogcsr, 3>;
    /* Analog I/O group x enable */
    using iogcsr_g3e = lp::assoc_bit<iogcsr, 2>;
    /* Analog I/O group x enable */
    using iogcsr_g2e = lp::assoc_bit<iogcsr, 1>;
    /* Analog I/O group x enable */
    using iogcsr_g1e = lp::assoc_bit<iogcsr, 0>;


    /* I/O group x counter register */
    using iog1cr = lp::io_register<lp::u32_t, base_address + 0x34>;
    /* Counter value */
    using iog1cr_cnt = lp::assoc_bit<iog1cr, 0, 14>;


    /* I/O group x counter register */
    using iog2cr = lp::io_register<lp::u32_t, base_address + 0x38>;
    /* Counter value */
    using iog2cr_cnt = lp::assoc_bit<iog2cr, 0, 14>;


    /* I/O group x counter register */
    using iog3cr = lp::io_register<lp::u32_t, base_address + 0x3c>;
    /* Counter value */
    using iog3cr_cnt = lp::assoc_bit<iog3cr, 0, 14>;


    /* I/O group x counter register */
    using iog4cr = lp::io_register<lp::u32_t, base_address + 0x40>;
    /* Counter value */
    using iog4cr_cnt = lp::assoc_bit<iog4cr, 0, 14>;


    /* I/O group x counter register */
    using iog5cr = lp::io_register<lp::u32_t, base_address + 0x44>;
    /* Counter value */
    using iog5cr_cnt = lp::assoc_bit<iog5cr, 0, 14>;


    /* I/O group x counter register */
    using iog6cr = lp::io_register<lp::u32_t, base_address + 0x48>;
    /* Counter value */
    using iog6cr_cnt = lp::assoc_bit<iog6cr, 0, 14>;


    /* I/O group x counter register */
    using iog7cr = lp::io_register<lp::u32_t, base_address + 0x4c>;
    /* Counter value */
    using iog7cr_cnt = lp::assoc_bit<iog7cr, 0, 14>;


    /* I/O group x counter register */
    using iog8cr = lp::io_register<lp::u32_t, base_address + 0x50>;
    /* Counter value */
    using iog8cr_cnt = lp::assoc_bit<iog8cr, 0, 14>;


};

using tsc = tsc_t<0x40024000>;

#endif // TSC_HH
