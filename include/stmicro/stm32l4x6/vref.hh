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
 * Hardware support for vref
 * @file vref.hh
 * @author Boris Vinogradov
 */

#include <associate_bit.hh>
#include <io_register.hh>
#include <types.hh>

#ifndef VREF_HH
#define VREF_HH

/* Voltage reference buffer */
template <lp::addr_t base_address>
struct vrefbuf_t {
    /* VREF control and status           register */
    using csr = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* Voltage reference buffer               enable */
    using csr_envr = lp::assoc_bit<csr, 0>;
    /* High impedance mode */
    using csr_hiz = lp::assoc_bit<csr, 1>;
    /* Voltage reference scale */
    using csr_vrs = lp::assoc_bit<csr, 2>;
    /* Voltage reference buffer               ready */
    using csr_vrr = lp::assoc_bit<csr, 3>;


    /* calibration control register */
    using ccr = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* Trimming code */
    using ccr_trim = lp::assoc_bit<ccr, 0, 6>;


};

using vrefbuf = vrefbuf_t<0x40010030>;

#endif // VREF_HH
