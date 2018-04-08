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
 * Hardware support for stk
 * @file stk.hh
 * @author Boris Vinogradov
 */

#include <associate_bit.hh>
#include <io_register.hh>
#include <types.hh>

#ifndef STK_HH
#define STK_HH

/* SysTick timer */
template <lp::addr_t base_address>
struct stk_t {
    /* SysTick control and status           register */
    using ctrl = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* Counter enable */
    using ctrl_enable = lp::assoc_bit<ctrl, 0>;
    /* SysTick exception request               enable */
    using ctrl_tickint = lp::assoc_bit<ctrl, 1>;
    /* Clock source selection */
    using ctrl_clksource = lp::assoc_bit<ctrl, 2>;
    /* COUNTFLAG */
    using ctrl_countflag = lp::assoc_bit<ctrl, 16>;


    /* SysTick reload value register */
    using load = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* RELOAD value */
    using load_reload = lp::assoc_bit<load, 0, 24>;


    /* SysTick current value register */
    using val = lp::io_register<lp::u32_t, base_address + 0x8>;
    /* Current counter value */
    using val_current = lp::assoc_bit<val, 0, 24>;


    /* SysTick calibration value           register */
    using calib = lp::io_register<lp::u32_t, base_address + 0xc>;
    /* Calibration value */
    using calib_tenms = lp::assoc_bit<calib, 0, 24>;
    /* SKEW flag: Indicates whether the TENMS               value is exact */
    using calib_skew = lp::assoc_bit<calib, 30>;
    /* NOREF flag. Reads as zero */
    using calib_noref = lp::assoc_bit<calib, 31>;


};

using stk = stk_t<0xe000e010>;

#endif // STK_HH
