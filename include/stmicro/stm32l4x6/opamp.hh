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
 * Hardware support for opamp
 * @file opamp.hh
 * @author Boris Vinogradov
 */

#include <associate_bit.hh>
#include <io_register.hh>
#include <types.hh>

#ifndef OPAMP_HH
#define OPAMP_HH

/* Operational amplifiers */
template <lp::addr_t base_address>
struct opamp_t {
    /* OPAMP1 control/status register */
    using opamp1_csr = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* Operational amplifier               Enable */
    using opamp1_csr_opaen = lp::assoc_bit<opamp1_csr, 0>;
    /* Operational amplifier Low Power               Mode */
    using opamp1_csr_opalpm = lp::assoc_bit<opamp1_csr, 1>;
    /* Operational amplifier PGA               mode */
    using opamp1_csr_opamode = lp::assoc_bit<opamp1_csr, 2, 2>;
    /* Operational amplifier Programmable               amplifier gain value */
    using opamp1_csr_pga_gain = lp::assoc_bit<opamp1_csr, 4, 2>;
    /* Inverting input selection */
    using opamp1_csr_vm_sel = lp::assoc_bit<opamp1_csr, 8, 2>;
    /* Non inverted input               selection */
    using opamp1_csr_vp_sel = lp::assoc_bit<opamp1_csr, 10>;
    /* Calibration mode enabled */
    using opamp1_csr_calon = lp::assoc_bit<opamp1_csr, 12>;
    /* Calibration selection */
    using opamp1_csr_calsel = lp::assoc_bit<opamp1_csr, 13>;
    /* allows to switch from AOP offset trimmed               values to AOP offset */
    using opamp1_csr_usertrim = lp::assoc_bit<opamp1_csr, 14>;
    /* Operational amplifier calibration               output */
    using opamp1_csr_calout = lp::assoc_bit<opamp1_csr, 15>;
    /* Operational amplifier power supply range               for stability */
    using opamp1_csr_opa_range = lp::assoc_bit<opamp1_csr, 31>;


    /* OPAMP1 offset trimming register in normal           mode */
    using opamp1_otr = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* Trim for NMOS differential               pairs */
    using opamp1_otr_trimoffsetn = lp::assoc_bit<opamp1_otr, 0, 5>;
    /* Trim for PMOS differential               pairs */
    using opamp1_otr_trimoffsetp = lp::assoc_bit<opamp1_otr, 8, 5>;


    /* OPAMP1 offset trimming register in low-power           mode */
    using opamp1_lpotr = lp::io_register<lp::u32_t, base_address + 0x8>;
    /* Trim for NMOS differential               pairs */
    using opamp1_lpotr_trimlpoffsetn = lp::assoc_bit<opamp1_lpotr, 0, 5>;
    /* Trim for PMOS differential               pairs */
    using opamp1_lpotr_trimlpoffsetp = lp::assoc_bit<opamp1_lpotr, 8, 5>;


    /* OPAMP2 control/status register */
    using opamp2_csr = lp::io_register<lp::u32_t, base_address + 0x10>;
    /* Operational amplifier               Enable */
    using opamp2_csr_opaen = lp::assoc_bit<opamp2_csr, 0>;
    /* Operational amplifier Low Power               Mode */
    using opamp2_csr_opalpm = lp::assoc_bit<opamp2_csr, 1>;
    /* Operational amplifier PGA               mode */
    using opamp2_csr_opamode = lp::assoc_bit<opamp2_csr, 2, 2>;
    /* Operational amplifier Programmable               amplifier gain value */
    using opamp2_csr_pga_gain = lp::assoc_bit<opamp2_csr, 4, 2>;
    /* Inverting input selection */
    using opamp2_csr_vm_sel = lp::assoc_bit<opamp2_csr, 8, 2>;
    /* Non inverted input               selection */
    using opamp2_csr_vp_sel = lp::assoc_bit<opamp2_csr, 10>;
    /* Calibration mode enabled */
    using opamp2_csr_calon = lp::assoc_bit<opamp2_csr, 12>;
    /* Calibration selection */
    using opamp2_csr_calsel = lp::assoc_bit<opamp2_csr, 13>;
    /* allows to switch from AOP offset trimmed               values to AOP offset */
    using opamp2_csr_usertrim = lp::assoc_bit<opamp2_csr, 14>;
    /* Operational amplifier calibration               output */
    using opamp2_csr_calout = lp::assoc_bit<opamp2_csr, 15>;


    /* OPAMP2 offset trimming register in normal           mode */
    using opamp2_otr = lp::io_register<lp::u32_t, base_address + 0x14>;
    /* Trim for NMOS differential               pairs */
    using opamp2_otr_trimoffsetn = lp::assoc_bit<opamp2_otr, 0, 5>;
    /* Trim for PMOS differential               pairs */
    using opamp2_otr_trimoffsetp = lp::assoc_bit<opamp2_otr, 8, 5>;


    /* OPAMP2 offset trimming register in low-power           mode */
    using opamp2_lpotr = lp::io_register<lp::u32_t, base_address + 0x18>;
    /* Trim for NMOS differential               pairs */
    using opamp2_lpotr_trimlpoffsetn = lp::assoc_bit<opamp2_lpotr, 0, 5>;
    /* Trim for PMOS differential               pairs */
    using opamp2_lpotr_trimlpoffsetp = lp::assoc_bit<opamp2_lpotr, 8, 5>;


};

using opamp = opamp_t<0x40007800>;

#endif // OPAMP_HH
