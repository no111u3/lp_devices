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
 * Hardware support for firewall
 * @file firewall.hh
 * @author Boris Vinogradov
 */

#include <associate_bit.hh>
#include <io_register.hh>
#include <types.hh>

#ifndef FIREWALL_HH
#define FIREWALL_HH

/* Firewall */
template <lp::addr_t base_address>
struct firewall_t {
    /* Code segment start address */
    using cssa = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* code segment start address */
    using cssa_add = lp::assoc_bit<cssa, 8, 16>;


    /* Code segment length */
    using csl = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* code segment length */
    using csl_leng = lp::assoc_bit<csl, 8, 14>;


    /* Non-volatile data segment start           address */
    using nvdssa = lp::io_register<lp::u32_t, base_address + 0x8>;
    /* Non-volatile data segment start               address */
    using nvdssa_add = lp::assoc_bit<nvdssa, 8, 16>;


    /* Non-volatile data segment           length */
    using nvdsl = lp::io_register<lp::u32_t, base_address + 0xc>;
    /* Non-volatile data segment               length */
    using nvdsl_leng = lp::assoc_bit<nvdsl, 8, 14>;


    /* Volatile data segment start           address */
    using vdssa = lp::io_register<lp::u32_t, base_address + 0x10>;
    /* Volatile data segment start               address */
    using vdssa_add = lp::assoc_bit<vdssa, 6, 10>;


    /* Volatile data segment length */
    using vdsl = lp::io_register<lp::u32_t, base_address + 0x14>;
    /* Non-volatile data segment               length */
    using vdsl_leng = lp::assoc_bit<vdsl, 6, 10>;


    /* Configuration register */
    using cr = lp::io_register<lp::u32_t, base_address + 0x20>;
    /* Volatile data execution */
    using cr_vde = lp::assoc_bit<cr, 2>;
    /* Volatile data shared */
    using cr_vds = lp::assoc_bit<cr, 1>;
    /* Firewall pre alarm */
    using cr_fpa = lp::assoc_bit<cr, 0>;


};

using firewall = firewall_t<0x40011c00>;

#endif // FIREWALL_HH
