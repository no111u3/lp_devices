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
 * Hardware support for iwdg
 * @file iwdg.hh
 * @author Boris Vinogradov
 */

#include <associate_bit.hh>
#include <io_register.hh>
#include <types.hh>

#ifndef IWDG_HH
#define IWDG_HH

/* Independent watchdog */
template <lp::addr_t base_address>
struct iwdg_t {
    /* Key register */
    using kr = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* Key value (write only, read               0x0000) */
    using kr_key = lp::assoc_bit<kr, 0, 16>;


    /* Prescaler register */
    using pr = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* Prescaler divider */
    using pr_pr = lp::assoc_bit<pr, 0, 3>;


    /* Reload register */
    using rlr = lp::io_register<lp::u32_t, base_address + 0x8>;
    /* Watchdog counter reload               value */
    using rlr_rl = lp::assoc_bit<rlr, 0, 12>;


    /* Status register */
    using sr = lp::io_register<lp::u32_t, base_address + 0xc>;
    /* Watchdog counter window value               update */
    using sr_wvu = lp::assoc_bit<sr, 2>;
    /* Watchdog counter reload value               update */
    using sr_rvu = lp::assoc_bit<sr, 1>;
    /* Watchdog prescaler value               update */
    using sr_pvu = lp::assoc_bit<sr, 0>;


    /* Window register */
    using winr = lp::io_register<lp::u32_t, base_address + 0x10>;
    /* Watchdog counter window               value */
    using winr_win = lp::assoc_bit<winr, 0, 12>;


};

using iwdg = iwdg_t<0x40003000>;

#endif // IWDG_HH
