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
 * Hardware support for rng
 * @file rng.hh
 * @author Boris Vinogradov
 */

#include <associate_bit.hh>
#include <io_register.hh>
#include <types.hh>

#ifndef RNG_HH
#define RNG_HH

/* Random number generator */
template <lp::addr_t base_address>
struct rng_t {
    /* control register */
    using cr = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* Interrupt enable */
    using cr_ie = lp::assoc_bit<cr, 3>;
    /* Random number generator               enable */
    using cr_rngen = lp::assoc_bit<cr, 2>;


    /* status register */
    using sr = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* Seed error interrupt               status */
    using sr_seis = lp::assoc_bit<sr, 6>;
    /* Clock error interrupt               status */
    using sr_ceis = lp::assoc_bit<sr, 5>;
    /* Seed error current status */
    using sr_secs = lp::assoc_bit<sr, 2>;
    /* Clock error current status */
    using sr_cecs = lp::assoc_bit<sr, 1>;
    /* Data ready */
    using sr_drdy = lp::assoc_bit<sr, 0>;


    /* data register */
    using dr = lp::io_register<lp::u32_t, base_address + 0x8>;
    /* Random data */
    using dr_rndata = lp::assoc_bit<dr, 0, 32>;


};

using rng = rng_t<0x50060800>;

#endif // RNG_HH
