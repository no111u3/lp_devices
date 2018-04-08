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
 * Hardware support for syscfg
 * @file syscfg.hh
 * @author Boris Vinogradov
 */

#include <associate_bit.hh>
#include <io_register.hh>
#include <types.hh>

#ifndef SYSCFG_HH
#define SYSCFG_HH

/* System configuration controller */
template <lp::addr_t base_address>
struct syscfg_t {
    /* memory remap register */
    using memrmp = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* Flash Bank mode selection */
    using memrmp_fb_mode = lp::assoc_bit<memrmp, 8>;
    /* QUADSPI memory mapping               swap */
    using memrmp_qfs = lp::assoc_bit<memrmp, 3>;
    /* Memory mapping selection */
    using memrmp_mem_mode = lp::assoc_bit<memrmp, 0, 3>;


    /* configuration register 1 */
    using cfgr1 = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* Floating Point Unit interrupts enable               bits */
    using cfgr1_fpu_ie = lp::assoc_bit<cfgr1, 26, 6>;
    /* I2C3 Fast-mode Plus driving capability               activation */
    using cfgr1_i2c3_fmp = lp::assoc_bit<cfgr1, 22>;
    /* I2C2 Fast-mode Plus driving capability               activation */
    using cfgr1_i2c2_fmp = lp::assoc_bit<cfgr1, 21>;
    /* I2C1 Fast-mode Plus driving capability               activation */
    using cfgr1_i2c1_fmp = lp::assoc_bit<cfgr1, 20>;
    /* Fast-mode Plus (Fm+) driving capability               activation on PB9 */
    using cfgr1_i2c_pb9_fmp = lp::assoc_bit<cfgr1, 19>;
    /* Fast-mode Plus (Fm+) driving capability               activation on PB8 */
    using cfgr1_i2c_pb8_fmp = lp::assoc_bit<cfgr1, 18>;
    /* Fast-mode Plus (Fm+) driving capability               activation on PB7 */
    using cfgr1_i2c_pb7_fmp = lp::assoc_bit<cfgr1, 17>;
    /* Fast-mode Plus (Fm+) driving capability               activation on PB6 */
    using cfgr1_i2c_pb6_fmp = lp::assoc_bit<cfgr1, 16>;
    /* I/O analog switch voltage booster               enable */
    using cfgr1_boosten = lp::assoc_bit<cfgr1, 8>;
    /* Firewall disable */
    using cfgr1_fwdis = lp::assoc_bit<cfgr1, 0>;


    /* external interrupt configuration register           1 */
    using exticr1 = lp::io_register<lp::u32_t, base_address + 0x8>;
    /* EXTI 3 configuration bits */
    using exticr1_exti3 = lp::assoc_bit<exticr1, 12, 3>;
    /* EXTI 2 configuration bits */
    using exticr1_exti2 = lp::assoc_bit<exticr1, 8, 3>;
    /* EXTI 1 configuration bits */
    using exticr1_exti1 = lp::assoc_bit<exticr1, 4, 3>;
    /* EXTI 0 configuration bits */
    using exticr1_exti0 = lp::assoc_bit<exticr1, 0, 3>;


    /* external interrupt configuration register           2 */
    using exticr2 = lp::io_register<lp::u32_t, base_address + 0xc>;
    /* EXTI 7 configuration bits */
    using exticr2_exti7 = lp::assoc_bit<exticr2, 12, 3>;
    /* EXTI 6 configuration bits */
    using exticr2_exti6 = lp::assoc_bit<exticr2, 8, 3>;
    /* EXTI 5 configuration bits */
    using exticr2_exti5 = lp::assoc_bit<exticr2, 4, 3>;
    /* EXTI 4 configuration bits */
    using exticr2_exti4 = lp::assoc_bit<exticr2, 0, 3>;


    /* external interrupt configuration register           3 */
    using exticr3 = lp::io_register<lp::u32_t, base_address + 0x10>;
    /* EXTI 11 configuration bits */
    using exticr3_exti11 = lp::assoc_bit<exticr3, 12, 3>;
    /* EXTI 10 configuration bits */
    using exticr3_exti10 = lp::assoc_bit<exticr3, 8, 3>;
    /* EXTI 9 configuration bits */
    using exticr3_exti9 = lp::assoc_bit<exticr3, 4, 3>;
    /* EXTI 8 configuration bits */
    using exticr3_exti8 = lp::assoc_bit<exticr3, 0, 3>;


    /* external interrupt configuration register           4 */
    using exticr4 = lp::io_register<lp::u32_t, base_address + 0x14>;
    /* EXTI15 configuration bits */
    using exticr4_exti15 = lp::assoc_bit<exticr4, 12, 3>;
    /* EXTI14 configuration bits */
    using exticr4_exti14 = lp::assoc_bit<exticr4, 8, 3>;
    /* EXTI13 configuration bits */
    using exticr4_exti13 = lp::assoc_bit<exticr4, 4, 3>;
    /* EXTI12 configuration bits */
    using exticr4_exti12 = lp::assoc_bit<exticr4, 0, 3>;


    /* SCSR */
    using scsr = lp::io_register<lp::u32_t, base_address + 0x18>;
    /* SRAM2 busy by erase               operation */
    using scsr_sram2bsy = lp::assoc_bit<scsr, 1>;
    /* SRAM2 Erase */
    using scsr_sram2er = lp::assoc_bit<scsr, 0>;


    /* CFGR2 */
    using cfgr2 = lp::io_register<lp::u32_t, base_address + 0x1c>;
    /* SRAM2 parity error flag */
    using cfgr2_spf = lp::assoc_bit<cfgr2, 8>;
    /* ECC Lock */
    using cfgr2_eccl = lp::assoc_bit<cfgr2, 3>;
    /* PVD lock enable bit */
    using cfgr2_pvdl = lp::assoc_bit<cfgr2, 2>;
    /* SRAM2 parity lock bit */
    using cfgr2_spl = lp::assoc_bit<cfgr2, 1>;
    /* Cortex-M4 LOCKUP (Hardfault) output               enable bit */
    using cfgr2_cll = lp::assoc_bit<cfgr2, 0>;


    /* SWPR */
    using swpr = lp::io_register<lp::u32_t, base_address + 0x20>;
    /* SRAM2 page 31 write               protection */
    using swpr_p31wp = lp::assoc_bit<swpr, 31>;
    /* P30WP */
    using swpr_p30wp = lp::assoc_bit<swpr, 30>;
    /* P29WP */
    using swpr_p29wp = lp::assoc_bit<swpr, 29>;
    /* P28WP */
    using swpr_p28wp = lp::assoc_bit<swpr, 28>;
    /* P27WP */
    using swpr_p27wp = lp::assoc_bit<swpr, 27>;
    /* P26WP */
    using swpr_p26wp = lp::assoc_bit<swpr, 26>;
    /* P25WP */
    using swpr_p25wp = lp::assoc_bit<swpr, 25>;
    /* P24WP */
    using swpr_p24wp = lp::assoc_bit<swpr, 24>;
    /* P23WP */
    using swpr_p23wp = lp::assoc_bit<swpr, 23>;
    /* P22WP */
    using swpr_p22wp = lp::assoc_bit<swpr, 22>;
    /* P21WP */
    using swpr_p21wp = lp::assoc_bit<swpr, 21>;
    /* P20WP */
    using swpr_p20wp = lp::assoc_bit<swpr, 20>;
    /* P19WP */
    using swpr_p19wp = lp::assoc_bit<swpr, 19>;
    /* P18WP */
    using swpr_p18wp = lp::assoc_bit<swpr, 18>;
    /* P17WP */
    using swpr_p17wp = lp::assoc_bit<swpr, 17>;
    /* P16WP */
    using swpr_p16wp = lp::assoc_bit<swpr, 16>;
    /* P15WP */
    using swpr_p15wp = lp::assoc_bit<swpr, 15>;
    /* P14WP */
    using swpr_p14wp = lp::assoc_bit<swpr, 14>;
    /* P13WP */
    using swpr_p13wp = lp::assoc_bit<swpr, 13>;
    /* P12WP */
    using swpr_p12wp = lp::assoc_bit<swpr, 12>;
    /* P11WP */
    using swpr_p11wp = lp::assoc_bit<swpr, 11>;
    /* P10WP */
    using swpr_p10wp = lp::assoc_bit<swpr, 10>;
    /* P9WP */
    using swpr_p9wp = lp::assoc_bit<swpr, 9>;
    /* P8WP */
    using swpr_p8wp = lp::assoc_bit<swpr, 8>;
    /* P7WP */
    using swpr_p7wp = lp::assoc_bit<swpr, 7>;
    /* P6WP */
    using swpr_p6wp = lp::assoc_bit<swpr, 6>;
    /* P5WP */
    using swpr_p5wp = lp::assoc_bit<swpr, 5>;
    /* P4WP */
    using swpr_p4wp = lp::assoc_bit<swpr, 4>;
    /* P3WP */
    using swpr_p3wp = lp::assoc_bit<swpr, 3>;
    /* P2WP */
    using swpr_p2wp = lp::assoc_bit<swpr, 2>;
    /* P1WP */
    using swpr_p1wp = lp::assoc_bit<swpr, 1>;
    /* P0WP */
    using swpr_p0wp = lp::assoc_bit<swpr, 0>;


    /* SKR */
    using skr = lp::io_register<lp::u32_t, base_address + 0x24>;
    /* SRAM2 write protection key for software               erase */
    using skr_key = lp::assoc_bit<skr, 0, 8>;


};

using syscfg = syscfg_t<0x40010000>;

#endif // SYSCFG_HH
