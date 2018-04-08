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
 * Hardware support for comp
 * @file comp.hh
 * @author Boris Vinogradov
 */

#include <associate_bit.hh>
#include <io_register.hh>
#include <types.hh>

#ifndef COMP_HH
#define COMP_HH

/* Comparator */
template <lp::addr_t base_address>
struct comp_t {
    /* Comparator 1 control and status           register */
    using comp1_csr = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* Comparator 1 enable bit */
    using comp1_csr_comp1_en = lp::assoc_bit<comp1_csr, 0>;
    /* Power Mode of the comparator               1 */
    using comp1_csr_comp1_pwrmode = lp::assoc_bit<comp1_csr, 2, 2>;
    /* Comparator 1 Input Minus connection               configuration bit */
    using comp1_csr_comp1_inmsel = lp::assoc_bit<comp1_csr, 4, 3>;
    /* Comparator1 input plus selection               bit */
    using comp1_csr_comp1_inpsel = lp::assoc_bit<comp1_csr, 7>;
    /* Comparator 1 polarity selection               bit */
    using comp1_csr_comp1_polarity = lp::assoc_bit<comp1_csr, 15>;
    /* Comparator 1 hysteresis selection               bits */
    using comp1_csr_comp1_hyst = lp::assoc_bit<comp1_csr, 16, 2>;
    /* Comparator 1 blanking source selection               bits */
    using comp1_csr_comp1_blanking = lp::assoc_bit<comp1_csr, 18, 3>;
    /* Scaler bridge enable */
    using comp1_csr_comp1_brgen = lp::assoc_bit<comp1_csr, 22>;
    /* Voltage scaler enable bit */
    using comp1_csr_comp1_scalen = lp::assoc_bit<comp1_csr, 23>;
    /* Comparator 1 output status               bit */
    using comp1_csr_comp1_value = lp::assoc_bit<comp1_csr, 30>;
    /* COMP1_CSR register lock               bit */
    using comp1_csr_comp1_lock = lp::assoc_bit<comp1_csr, 31>;


    /* Comparator 2 control and status           register */
    using comp2_csr = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* Comparator 2 enable bit */
    using comp2_csr_comp2_en = lp::assoc_bit<comp2_csr, 0>;
    /* Power Mode of the comparator               2 */
    using comp2_csr_comp2_pwrmode = lp::assoc_bit<comp2_csr, 2, 2>;
    /* Comparator 2 Input Minus connection               configuration bit */
    using comp2_csr_comp2_inmsel = lp::assoc_bit<comp2_csr, 4, 3>;
    /* Comparator 2 Input Plus connection               configuration bit */
    using comp2_csr_comp2_inpsel = lp::assoc_bit<comp2_csr, 7>;
    /* Windows mode selection bit */
    using comp2_csr_comp2_winmode = lp::assoc_bit<comp2_csr, 9>;
    /* Comparator 2 polarity selection               bit */
    using comp2_csr_comp2_polarity = lp::assoc_bit<comp2_csr, 15>;
    /* Comparator 2 hysteresis selection               bits */
    using comp2_csr_comp2_hyst = lp::assoc_bit<comp2_csr, 16, 2>;
    /* Comparator 2 blanking source selection               bits */
    using comp2_csr_comp2_blanking = lp::assoc_bit<comp2_csr, 18, 3>;
    /* Scaler bridge enable */
    using comp2_csr_comp2_brgen = lp::assoc_bit<comp2_csr, 22>;
    /* Voltage scaler enable bit */
    using comp2_csr_comp2_scalen = lp::assoc_bit<comp2_csr, 23>;
    /* Comparator 2 output status               bit */
    using comp2_csr_comp2_value = lp::assoc_bit<comp2_csr, 30>;
    /* COMP2_CSR register lock               bit */
    using comp2_csr_comp2_lock = lp::assoc_bit<comp2_csr, 31>;


};

using comp = comp_t<0x40010200>;

#endif // COMP_HH
