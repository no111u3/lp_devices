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
 * Hardware support for lptim
 * @file lptim.hh
 * @author Boris Vinogradov
 */

#include <associate_bit.hh>
#include <io_register.hh>
#include <types.hh>

#ifndef LPTIM_HH
#define LPTIM_HH

/* Low power timer */
template <lp::addr_t base_address>
struct lptim_t {
    /* Interrupt and Status Register */
    using isr = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* Counter direction change up to               down */
    using isr_down = lp::assoc_bit<isr, 6>;
    /* Counter direction change down to               up */
    using isr_up = lp::assoc_bit<isr, 5>;
    /* Autoreload register update               OK */
    using isr_arrok = lp::assoc_bit<isr, 4>;
    /* Compare register update OK */
    using isr_cmpok = lp::assoc_bit<isr, 3>;
    /* External trigger edge               event */
    using isr_exttrig = lp::assoc_bit<isr, 2>;
    /* Autoreload match */
    using isr_arrm = lp::assoc_bit<isr, 1>;
    /* Compare match */
    using isr_cmpm = lp::assoc_bit<isr, 0>;


    /* Interrupt Clear Register */
    using icr = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* Direction change to down Clear               Flag */
    using icr_downcf = lp::assoc_bit<icr, 6>;
    /* Direction change to UP Clear               Flag */
    using icr_upcf = lp::assoc_bit<icr, 5>;
    /* Autoreload register update OK Clear               Flag */
    using icr_arrokcf = lp::assoc_bit<icr, 4>;
    /* Compare register update OK Clear               Flag */
    using icr_cmpokcf = lp::assoc_bit<icr, 3>;
    /* External trigger valid edge Clear               Flag */
    using icr_exttrigcf = lp::assoc_bit<icr, 2>;
    /* Autoreload match Clear               Flag */
    using icr_arrmcf = lp::assoc_bit<icr, 1>;
    /* compare match Clear Flag */
    using icr_cmpmcf = lp::assoc_bit<icr, 0>;


    /* Interrupt Enable Register */
    using ier = lp::io_register<lp::u32_t, base_address + 0x8>;
    /* Direction change to down Interrupt               Enable */
    using ier_downie = lp::assoc_bit<ier, 6>;
    /* Direction change to UP Interrupt               Enable */
    using ier_upie = lp::assoc_bit<ier, 5>;
    /* Autoreload register update OK Interrupt               Enable */
    using ier_arrokie = lp::assoc_bit<ier, 4>;
    /* Compare register update OK Interrupt               Enable */
    using ier_cmpokie = lp::assoc_bit<ier, 3>;
    /* External trigger valid edge Interrupt               Enable */
    using ier_exttrigie = lp::assoc_bit<ier, 2>;
    /* Autoreload match Interrupt               Enable */
    using ier_arrmie = lp::assoc_bit<ier, 1>;
    /* Compare match Interrupt               Enable */
    using ier_cmpmie = lp::assoc_bit<ier, 0>;


    /* Configuration Register */
    using cfgr = lp::io_register<lp::u32_t, base_address + 0xc>;
    /* Encoder mode enable */
    using cfgr_enc = lp::assoc_bit<cfgr, 24>;
    /* counter mode enabled */
    using cfgr_countmode = lp::assoc_bit<cfgr, 23>;
    /* Registers update mode */
    using cfgr_preload = lp::assoc_bit<cfgr, 22>;
    /* Waveform shape polarity */
    using cfgr_wavpol = lp::assoc_bit<cfgr, 21>;
    /* Waveform shape */
    using cfgr_wave = lp::assoc_bit<cfgr, 20>;
    /* Timeout enable */
    using cfgr_timout = lp::assoc_bit<cfgr, 19>;
    /* Trigger enable and               polarity */
    using cfgr_trigen = lp::assoc_bit<cfgr, 17, 2>;
    /* Trigger selector */
    using cfgr_trigsel = lp::assoc_bit<cfgr, 13, 3>;
    /* Clock prescaler */
    using cfgr_presc = lp::assoc_bit<cfgr, 9, 3>;
    /* Configurable digital filter for               trigger */
    using cfgr_trgflt = lp::assoc_bit<cfgr, 6, 2>;
    /* Configurable digital filter for external               clock */
    using cfgr_ckflt = lp::assoc_bit<cfgr, 3, 2>;
    /* Clock Polarity */
    using cfgr_ckpol = lp::assoc_bit<cfgr, 1, 2>;
    /* Clock selector */
    using cfgr_cksel = lp::assoc_bit<cfgr, 0>;


    /* Control Register */
    using cr = lp::io_register<lp::u32_t, base_address + 0x10>;
    /* Timer start in continuous               mode */
    using cr_cntstrt = lp::assoc_bit<cr, 2>;
    /* LPTIM start in single mode */
    using cr_sngstrt = lp::assoc_bit<cr, 1>;
    /* LPTIM Enable */
    using cr_enable = lp::assoc_bit<cr, 0>;


    /* Compare Register */
    using cmp = lp::io_register<lp::u32_t, base_address + 0x14>;
    /* Compare value */
    using cmp_cmp = lp::assoc_bit<cmp, 0, 16>;


    /* Autoreload Register */
    using arr = lp::io_register<lp::u32_t, base_address + 0x18>;
    /* Auto reload value */
    using arr_arr = lp::assoc_bit<arr, 0, 16>;


    /* Counter Register */
    using cnt = lp::io_register<lp::u32_t, base_address + 0x1c>;
    /* Counter value */
    using cnt_cnt = lp::assoc_bit<cnt, 0, 16>;


};

using lptim1 = lptim_t<0x40007c00>;
using lptim2 = lptim_t<0x40009400>;

#endif // LPTIM_HH
