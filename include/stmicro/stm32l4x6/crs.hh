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
 * Hardware support for crs
 * @file crs.hh
 * @author Boris Vinogradov
 */

#include <associate_bit.hh>
#include <io_register.hh>
#include <types.hh>

#ifndef CRS_HH
#define CRS_HH

/* Clock recovery system */
template <lp::addr_t base_address>
struct crs_t {
    /* control register */
    using cr = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* HSI48 oscillator smooth               trimming */
    using cr_trim = lp::assoc_bit<cr, 8, 6>;
    /* Generate software SYNC               event */
    using cr_swsync = lp::assoc_bit<cr, 7>;
    /* Automatic trimming enable */
    using cr_autotrimen = lp::assoc_bit<cr, 6>;
    /* Frequency error counter               enable */
    using cr_cen = lp::assoc_bit<cr, 5>;
    /* Expected SYNC interrupt               enable */
    using cr_esyncie = lp::assoc_bit<cr, 3>;
    /* Synchronization or trimming error               interrupt enable */
    using cr_errie = lp::assoc_bit<cr, 2>;
    /* SYNC warning interrupt               enable */
    using cr_syncwarnie = lp::assoc_bit<cr, 1>;
    /* SYNC event OK interrupt               enable */
    using cr_syncokie = lp::assoc_bit<cr, 0>;


    /* configuration register */
    using cfgr = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* SYNC polarity selection */
    using cfgr_syncpol = lp::assoc_bit<cfgr, 31>;
    /* SYNC signal source               selection */
    using cfgr_syncsrc = lp::assoc_bit<cfgr, 28, 2>;
    /* SYNC divider */
    using cfgr_syncdiv = lp::assoc_bit<cfgr, 24, 3>;
    /* Frequency error limit */
    using cfgr_felim = lp::assoc_bit<cfgr, 16, 8>;
    /* Counter reload value */
    using cfgr_reload = lp::assoc_bit<cfgr, 0, 16>;


    /* interrupt and status register */
    using isr = lp::io_register<lp::u32_t, base_address + 0x8>;
    /* Frequency error capture */
    using isr_fecap = lp::assoc_bit<isr, 16, 16>;
    /* Frequency error direction */
    using isr_fedir = lp::assoc_bit<isr, 15>;
    /* Trimming overflow or               underflow */
    using isr_trimovf = lp::assoc_bit<isr, 10>;
    /* SYNC missed */
    using isr_syncmiss = lp::assoc_bit<isr, 9>;
    /* SYNC error */
    using isr_syncerr = lp::assoc_bit<isr, 8>;
    /* Expected SYNC flag */
    using isr_esyncf = lp::assoc_bit<isr, 3>;
    /* Error flag */
    using isr_errf = lp::assoc_bit<isr, 2>;
    /* SYNC warning flag */
    using isr_syncwarnf = lp::assoc_bit<isr, 1>;
    /* SYNC event OK flag */
    using isr_syncokf = lp::assoc_bit<isr, 0>;


    /* interrupt flag clear register */
    using icr = lp::io_register<lp::u32_t, base_address + 0xc>;
    /* Expected SYNC clear flag */
    using icr_esyncc = lp::assoc_bit<icr, 3>;
    /* Error clear flag */
    using icr_errc = lp::assoc_bit<icr, 2>;
    /* SYNC warning clear flag */
    using icr_syncwarnc = lp::assoc_bit<icr, 1>;
    /* SYNC event OK clear flag */
    using icr_syncokc = lp::assoc_bit<icr, 0>;


};

using crs = crs_t<0x40006000>;

#endif // CRS_HH
