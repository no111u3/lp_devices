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
 * Hardware support for fpu
 * @file fpu.hh
 * @author Boris Vinogradov
 */

#include <associate_bit.hh>
#include <io_register.hh>
#include <types.hh>

#ifndef FPU_HH
#define FPU_HH

/* Floting point unit */
template <lp::addr_t base_address>
struct fpu_t {
    /* Floating-point context control           register */
    using fpccr = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* LSPACT */
    using fpccr_lspact = lp::assoc_bit<fpccr, 0>;
    /* USER */
    using fpccr_user = lp::assoc_bit<fpccr, 1>;
    /* THREAD */
    using fpccr_thread = lp::assoc_bit<fpccr, 3>;
    /* HFRDY */
    using fpccr_hfrdy = lp::assoc_bit<fpccr, 4>;
    /* MMRDY */
    using fpccr_mmrdy = lp::assoc_bit<fpccr, 5>;
    /* BFRDY */
    using fpccr_bfrdy = lp::assoc_bit<fpccr, 6>;
    /* MONRDY */
    using fpccr_monrdy = lp::assoc_bit<fpccr, 8>;
    /* LSPEN */
    using fpccr_lspen = lp::assoc_bit<fpccr, 30>;
    /* ASPEN */
    using fpccr_aspen = lp::assoc_bit<fpccr, 31>;


    /* Floating-point context address           register */
    using fpcar = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* Location of unpopulated               floating-point */
    using fpcar_address = lp::assoc_bit<fpcar, 3, 29>;


    /* Floating-point status control           register */
    using fpscr = lp::io_register<lp::u32_t, base_address + 0x8>;
    /* Invalid operation cumulative exception               bit */
    using fpscr_ioc = lp::assoc_bit<fpscr, 0>;
    /* Division by zero cumulative exception               bit. */
    using fpscr_dzc = lp::assoc_bit<fpscr, 1>;
    /* Overflow cumulative exception               bit */
    using fpscr_ofc = lp::assoc_bit<fpscr, 2>;
    /* Underflow cumulative exception               bit */
    using fpscr_ufc = lp::assoc_bit<fpscr, 3>;
    /* Inexact cumulative exception               bit */
    using fpscr_ixc = lp::assoc_bit<fpscr, 4>;
    /* Input denormal cumulative exception               bit. */
    using fpscr_idc = lp::assoc_bit<fpscr, 7>;
    /* Rounding Mode control               field */
    using fpscr_rmode = lp::assoc_bit<fpscr, 22, 2>;
    /* Flush-to-zero mode control               bit: */
    using fpscr_fz = lp::assoc_bit<fpscr, 24>;
    /* Default NaN mode control               bit */
    using fpscr_dn = lp::assoc_bit<fpscr, 25>;
    /* Alternative half-precision control               bit */
    using fpscr_ahp = lp::assoc_bit<fpscr, 26>;
    /* Overflow condition code               flag */
    using fpscr_v = lp::assoc_bit<fpscr, 28>;
    /* Carry condition code flag */
    using fpscr_c = lp::assoc_bit<fpscr, 29>;
    /* Zero condition code flag */
    using fpscr_z = lp::assoc_bit<fpscr, 30>;
    /* Negative condition code               flag */
    using fpscr_n = lp::assoc_bit<fpscr, 31>;


};

/* Floating point unit CPACR */
template <lp::addr_t base_address>
struct fpu_cpacr_t {
    /* Coprocessor access control           register */
    using cpacr = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* CP */
    using cpacr_cp = lp::assoc_bit<cpacr, 20, 4>;


};

using fpu = fpu_t<0xe000ef34>;
using fpu_cpacr = fpu_cpacr_t<0xe000ed88>;

#endif // FPU_HH
