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
 * Hardware support for crc
 * @file crc.hh
 * @author Boris Vinogradov
 */

#include <associate_bit.hh>
#include <io_register.hh>
#include <types.hh>

#ifndef CRC_HH
#define CRC_HH

/* Cyclic redundancy check calculation
      unit */
template <lp::addr_t base_address>
struct crc_t {
    /* Data register */
    using dr = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* Data register bits */
    using dr_dr = lp::assoc_bit<dr, 0, 32>;


    /* Independent data register */
    using idr = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* General-purpose 8-bit data register               bits */
    using idr_idr = lp::assoc_bit<idr, 0, 8>;


    /* Control register */
    using cr = lp::io_register<lp::u32_t, base_address + 0x8>;
    /* Reverse output data */
    using cr_rev_out = lp::assoc_bit<cr, 7>;
    /* Reverse input data */
    using cr_rev_in = lp::assoc_bit<cr, 5, 2>;
    /* Polynomial size */
    using cr_polysize = lp::assoc_bit<cr, 3, 2>;
    /* RESET bit */
    using cr_reset = lp::assoc_bit<cr, 0>;


    /* Initial CRC value */
    using init = lp::io_register<lp::u32_t, base_address + 0x10>;
    /* Programmable initial CRC               value */
    using init_crc_init = lp::assoc_bit<init, 0, 32>;


    /* polynomial */
    using pol = lp::io_register<lp::u32_t, base_address + 0x14>;
    /* Programmable polynomial */
    using pol_polynomialcoefficients = lp::assoc_bit<pol, 0, 32>;


};

using crc = crc_t<0x40023000>;

#endif // CRC_HH
