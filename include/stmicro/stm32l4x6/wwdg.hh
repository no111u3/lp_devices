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
 * Hardware support for wwdg
 * @file wwdg.hh
 * @author Boris Vinogradov
 */

#include <associate_bit.hh>
#include <io_register.hh>
#include <types.hh>

#ifndef WWDG_HH
#define WWDG_HH

/* System window watchdog */
template <lp::addr_t base_address>
struct wwdg_t {
    /* Control register */
    using cr = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* Activation bit */
    using cr_wdga = lp::assoc_bit<cr, 7>;
    /* 7-bit counter (MSB to LSB) */
    using cr_t = lp::assoc_bit<cr, 0, 7>;


    /* Configuration register */
    using cfr = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* Early wakeup interrupt */
    using cfr_ewi = lp::assoc_bit<cfr, 9>;
    /* Timer base */
    using cfr_wdgtb = lp::assoc_bit<cfr, 7, 2>;
    /* 7-bit window value */
    using cfr_w = lp::assoc_bit<cfr, 0, 7>;


    /* Status register */
    using sr = lp::io_register<lp::u32_t, base_address + 0x8>;
    /* Early wakeup interrupt               flag */
    using sr_ewif = lp::assoc_bit<sr, 0>;


};

using wwdg = wwdg_t<0x40002c00>;

#endif // WWDG_HH
