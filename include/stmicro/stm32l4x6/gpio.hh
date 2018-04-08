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
 * Hardware support for gpio
 * @file gpio.hh
 * @author Boris Vinogradov
 */

#include <associate_bit.hh>
#include <io_register.hh>
#include <types.hh>

#ifndef GPIO_HH
#define GPIO_HH

/* General-purpose I/Os */
template <lp::addr_t base_address>
struct gpio_t {
    /* GPIO port mode register */
    using moder = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* Port x configuration bits (y =               0..15) */
    using moder_moder15 = lp::assoc_bit<moder, 30, 2>;
    /* Port x configuration bits (y =               0..15) */
    using moder_moder14 = lp::assoc_bit<moder, 28, 2>;
    /* Port x configuration bits (y =               0..15) */
    using moder_moder13 = lp::assoc_bit<moder, 26, 2>;
    /* Port x configuration bits (y =               0..15) */
    using moder_moder12 = lp::assoc_bit<moder, 24, 2>;
    /* Port x configuration bits (y =               0..15) */
    using moder_moder11 = lp::assoc_bit<moder, 22, 2>;
    /* Port x configuration bits (y =               0..15) */
    using moder_moder10 = lp::assoc_bit<moder, 20, 2>;
    /* Port x configuration bits (y =               0..15) */
    using moder_moder9 = lp::assoc_bit<moder, 18, 2>;
    /* Port x configuration bits (y =               0..15) */
    using moder_moder8 = lp::assoc_bit<moder, 16, 2>;
    /* Port x configuration bits (y =               0..15) */
    using moder_moder7 = lp::assoc_bit<moder, 14, 2>;
    /* Port x configuration bits (y =               0..15) */
    using moder_moder6 = lp::assoc_bit<moder, 12, 2>;
    /* Port x configuration bits (y =               0..15) */
    using moder_moder5 = lp::assoc_bit<moder, 10, 2>;
    /* Port x configuration bits (y =               0..15) */
    using moder_moder4 = lp::assoc_bit<moder, 8, 2>;
    /* Port x configuration bits (y =               0..15) */
    using moder_moder3 = lp::assoc_bit<moder, 6, 2>;
    /* Port x configuration bits (y =               0..15) */
    using moder_moder2 = lp::assoc_bit<moder, 4, 2>;
    /* Port x configuration bits (y =               0..15) */
    using moder_moder1 = lp::assoc_bit<moder, 2, 2>;
    /* Port x configuration bits (y =               0..15) */
    using moder_moder0 = lp::assoc_bit<moder, 0, 2>;


    /* GPIO port output type register */
    using otyper = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* Port x configuration bits (y =               0..15) */
    using otyper_ot15 = lp::assoc_bit<otyper, 15>;
    /* Port x configuration bits (y =               0..15) */
    using otyper_ot14 = lp::assoc_bit<otyper, 14>;
    /* Port x configuration bits (y =               0..15) */
    using otyper_ot13 = lp::assoc_bit<otyper, 13>;
    /* Port x configuration bits (y =               0..15) */
    using otyper_ot12 = lp::assoc_bit<otyper, 12>;
    /* Port x configuration bits (y =               0..15) */
    using otyper_ot11 = lp::assoc_bit<otyper, 11>;
    /* Port x configuration bits (y =               0..15) */
    using otyper_ot10 = lp::assoc_bit<otyper, 10>;
    /* Port x configuration bits (y =               0..15) */
    using otyper_ot9 = lp::assoc_bit<otyper, 9>;
    /* Port x configuration bits (y =               0..15) */
    using otyper_ot8 = lp::assoc_bit<otyper, 8>;
    /* Port x configuration bits (y =               0..15) */
    using otyper_ot7 = lp::assoc_bit<otyper, 7>;
    /* Port x configuration bits (y =               0..15) */
    using otyper_ot6 = lp::assoc_bit<otyper, 6>;
    /* Port x configuration bits (y =               0..15) */
    using otyper_ot5 = lp::assoc_bit<otyper, 5>;
    /* Port x configuration bits (y =               0..15) */
    using otyper_ot4 = lp::assoc_bit<otyper, 4>;
    /* Port x configuration bits (y =               0..15) */
    using otyper_ot3 = lp::assoc_bit<otyper, 3>;
    /* Port x configuration bits (y =               0..15) */
    using otyper_ot2 = lp::assoc_bit<otyper, 2>;
    /* Port x configuration bits (y =               0..15) */
    using otyper_ot1 = lp::assoc_bit<otyper, 1>;
    /* Port x configuration bits (y =               0..15) */
    using otyper_ot0 = lp::assoc_bit<otyper, 0>;


    /* GPIO port output speed           register */
    using ospeedr = lp::io_register<lp::u32_t, base_address + 0x8>;
    /* Port x configuration bits (y =               0..15) */
    using ospeedr_ospeedr15 = lp::assoc_bit<ospeedr, 30, 2>;
    /* Port x configuration bits (y =               0..15) */
    using ospeedr_ospeedr14 = lp::assoc_bit<ospeedr, 28, 2>;
    /* Port x configuration bits (y =               0..15) */
    using ospeedr_ospeedr13 = lp::assoc_bit<ospeedr, 26, 2>;
    /* Port x configuration bits (y =               0..15) */
    using ospeedr_ospeedr12 = lp::assoc_bit<ospeedr, 24, 2>;
    /* Port x configuration bits (y =               0..15) */
    using ospeedr_ospeedr11 = lp::assoc_bit<ospeedr, 22, 2>;
    /* Port x configuration bits (y =               0..15) */
    using ospeedr_ospeedr10 = lp::assoc_bit<ospeedr, 20, 2>;
    /* Port x configuration bits (y =               0..15) */
    using ospeedr_ospeedr9 = lp::assoc_bit<ospeedr, 18, 2>;
    /* Port x configuration bits (y =               0..15) */
    using ospeedr_ospeedr8 = lp::assoc_bit<ospeedr, 16, 2>;
    /* Port x configuration bits (y =               0..15) */
    using ospeedr_ospeedr7 = lp::assoc_bit<ospeedr, 14, 2>;
    /* Port x configuration bits (y =               0..15) */
    using ospeedr_ospeedr6 = lp::assoc_bit<ospeedr, 12, 2>;
    /* Port x configuration bits (y =               0..15) */
    using ospeedr_ospeedr5 = lp::assoc_bit<ospeedr, 10, 2>;
    /* Port x configuration bits (y =               0..15) */
    using ospeedr_ospeedr4 = lp::assoc_bit<ospeedr, 8, 2>;
    /* Port x configuration bits (y =               0..15) */
    using ospeedr_ospeedr3 = lp::assoc_bit<ospeedr, 6, 2>;
    /* Port x configuration bits (y =               0..15) */
    using ospeedr_ospeedr2 = lp::assoc_bit<ospeedr, 4, 2>;
    /* Port x configuration bits (y =               0..15) */
    using ospeedr_ospeedr1 = lp::assoc_bit<ospeedr, 2, 2>;
    /* Port x configuration bits (y =               0..15) */
    using ospeedr_ospeedr0 = lp::assoc_bit<ospeedr, 0, 2>;


    /* GPIO port pull-up/pull-down           register */
    using pupdr = lp::io_register<lp::u32_t, base_address + 0xc>;
    /* Port x configuration bits (y =               0..15) */
    using pupdr_pupdr15 = lp::assoc_bit<pupdr, 30, 2>;
    /* Port x configuration bits (y =               0..15) */
    using pupdr_pupdr14 = lp::assoc_bit<pupdr, 28, 2>;
    /* Port x configuration bits (y =               0..15) */
    using pupdr_pupdr13 = lp::assoc_bit<pupdr, 26, 2>;
    /* Port x configuration bits (y =               0..15) */
    using pupdr_pupdr12 = lp::assoc_bit<pupdr, 24, 2>;
    /* Port x configuration bits (y =               0..15) */
    using pupdr_pupdr11 = lp::assoc_bit<pupdr, 22, 2>;
    /* Port x configuration bits (y =               0..15) */
    using pupdr_pupdr10 = lp::assoc_bit<pupdr, 20, 2>;
    /* Port x configuration bits (y =               0..15) */
    using pupdr_pupdr9 = lp::assoc_bit<pupdr, 18, 2>;
    /* Port x configuration bits (y =               0..15) */
    using pupdr_pupdr8 = lp::assoc_bit<pupdr, 16, 2>;
    /* Port x configuration bits (y =               0..15) */
    using pupdr_pupdr7 = lp::assoc_bit<pupdr, 14, 2>;
    /* Port x configuration bits (y =               0..15) */
    using pupdr_pupdr6 = lp::assoc_bit<pupdr, 12, 2>;
    /* Port x configuration bits (y =               0..15) */
    using pupdr_pupdr5 = lp::assoc_bit<pupdr, 10, 2>;
    /* Port x configuration bits (y =               0..15) */
    using pupdr_pupdr4 = lp::assoc_bit<pupdr, 8, 2>;
    /* Port x configuration bits (y =               0..15) */
    using pupdr_pupdr3 = lp::assoc_bit<pupdr, 6, 2>;
    /* Port x configuration bits (y =               0..15) */
    using pupdr_pupdr2 = lp::assoc_bit<pupdr, 4, 2>;
    /* Port x configuration bits (y =               0..15) */
    using pupdr_pupdr1 = lp::assoc_bit<pupdr, 2, 2>;
    /* Port x configuration bits (y =               0..15) */
    using pupdr_pupdr0 = lp::assoc_bit<pupdr, 0, 2>;


    /* GPIO port input data register */
    using idr = lp::io_register<lp::u32_t, base_address + 0x10>;
    /* Port input data (y =               0..15) */
    using idr_idr15 = lp::assoc_bit<idr, 15>;
    /* Port input data (y =               0..15) */
    using idr_idr14 = lp::assoc_bit<idr, 14>;
    /* Port input data (y =               0..15) */
    using idr_idr13 = lp::assoc_bit<idr, 13>;
    /* Port input data (y =               0..15) */
    using idr_idr12 = lp::assoc_bit<idr, 12>;
    /* Port input data (y =               0..15) */
    using idr_idr11 = lp::assoc_bit<idr, 11>;
    /* Port input data (y =               0..15) */
    using idr_idr10 = lp::assoc_bit<idr, 10>;
    /* Port input data (y =               0..15) */
    using idr_idr9 = lp::assoc_bit<idr, 9>;
    /* Port input data (y =               0..15) */
    using idr_idr8 = lp::assoc_bit<idr, 8>;
    /* Port input data (y =               0..15) */
    using idr_idr7 = lp::assoc_bit<idr, 7>;
    /* Port input data (y =               0..15) */
    using idr_idr6 = lp::assoc_bit<idr, 6>;
    /* Port input data (y =               0..15) */
    using idr_idr5 = lp::assoc_bit<idr, 5>;
    /* Port input data (y =               0..15) */
    using idr_idr4 = lp::assoc_bit<idr, 4>;
    /* Port input data (y =               0..15) */
    using idr_idr3 = lp::assoc_bit<idr, 3>;
    /* Port input data (y =               0..15) */
    using idr_idr2 = lp::assoc_bit<idr, 2>;
    /* Port input data (y =               0..15) */
    using idr_idr1 = lp::assoc_bit<idr, 1>;
    /* Port input data (y =               0..15) */
    using idr_idr0 = lp::assoc_bit<idr, 0>;


    /* GPIO port output data register */
    using odr = lp::io_register<lp::u32_t, base_address + 0x14>;
    /* Port output data (y =               0..15) */
    using odr_odr15 = lp::assoc_bit<odr, 15>;
    /* Port output data (y =               0..15) */
    using odr_odr14 = lp::assoc_bit<odr, 14>;
    /* Port output data (y =               0..15) */
    using odr_odr13 = lp::assoc_bit<odr, 13>;
    /* Port output data (y =               0..15) */
    using odr_odr12 = lp::assoc_bit<odr, 12>;
    /* Port output data (y =               0..15) */
    using odr_odr11 = lp::assoc_bit<odr, 11>;
    /* Port output data (y =               0..15) */
    using odr_odr10 = lp::assoc_bit<odr, 10>;
    /* Port output data (y =               0..15) */
    using odr_odr9 = lp::assoc_bit<odr, 9>;
    /* Port output data (y =               0..15) */
    using odr_odr8 = lp::assoc_bit<odr, 8>;
    /* Port output data (y =               0..15) */
    using odr_odr7 = lp::assoc_bit<odr, 7>;
    /* Port output data (y =               0..15) */
    using odr_odr6 = lp::assoc_bit<odr, 6>;
    /* Port output data (y =               0..15) */
    using odr_odr5 = lp::assoc_bit<odr, 5>;
    /* Port output data (y =               0..15) */
    using odr_odr4 = lp::assoc_bit<odr, 4>;
    /* Port output data (y =               0..15) */
    using odr_odr3 = lp::assoc_bit<odr, 3>;
    /* Port output data (y =               0..15) */
    using odr_odr2 = lp::assoc_bit<odr, 2>;
    /* Port output data (y =               0..15) */
    using odr_odr1 = lp::assoc_bit<odr, 1>;
    /* Port output data (y =               0..15) */
    using odr_odr0 = lp::assoc_bit<odr, 0>;


    /* GPIO port bit set/reset           register */
    using bsrr = lp::io_register<lp::u32_t, base_address + 0x18>;
    /* Port x reset bit y (y =               0..15) */
    using bsrr_br15 = lp::assoc_bit<bsrr, 31>;
    /* Port x reset bit y (y =               0..15) */
    using bsrr_br14 = lp::assoc_bit<bsrr, 30>;
    /* Port x reset bit y (y =               0..15) */
    using bsrr_br13 = lp::assoc_bit<bsrr, 29>;
    /* Port x reset bit y (y =               0..15) */
    using bsrr_br12 = lp::assoc_bit<bsrr, 28>;
    /* Port x reset bit y (y =               0..15) */
    using bsrr_br11 = lp::assoc_bit<bsrr, 27>;
    /* Port x reset bit y (y =               0..15) */
    using bsrr_br10 = lp::assoc_bit<bsrr, 26>;
    /* Port x reset bit y (y =               0..15) */
    using bsrr_br9 = lp::assoc_bit<bsrr, 25>;
    /* Port x reset bit y (y =               0..15) */
    using bsrr_br8 = lp::assoc_bit<bsrr, 24>;
    /* Port x reset bit y (y =               0..15) */
    using bsrr_br7 = lp::assoc_bit<bsrr, 23>;
    /* Port x reset bit y (y =               0..15) */
    using bsrr_br6 = lp::assoc_bit<bsrr, 22>;
    /* Port x reset bit y (y =               0..15) */
    using bsrr_br5 = lp::assoc_bit<bsrr, 21>;
    /* Port x reset bit y (y =               0..15) */
    using bsrr_br4 = lp::assoc_bit<bsrr, 20>;
    /* Port x reset bit y (y =               0..15) */
    using bsrr_br3 = lp::assoc_bit<bsrr, 19>;
    /* Port x reset bit y (y =               0..15) */
    using bsrr_br2 = lp::assoc_bit<bsrr, 18>;
    /* Port x reset bit y (y =               0..15) */
    using bsrr_br1 = lp::assoc_bit<bsrr, 17>;
    /* Port x set bit y (y=               0..15) */
    using bsrr_br0 = lp::assoc_bit<bsrr, 16>;
    /* Port x set bit y (y=               0..15) */
    using bsrr_bs15 = lp::assoc_bit<bsrr, 15>;
    /* Port x set bit y (y=               0..15) */
    using bsrr_bs14 = lp::assoc_bit<bsrr, 14>;
    /* Port x set bit y (y=               0..15) */
    using bsrr_bs13 = lp::assoc_bit<bsrr, 13>;
    /* Port x set bit y (y=               0..15) */
    using bsrr_bs12 = lp::assoc_bit<bsrr, 12>;
    /* Port x set bit y (y=               0..15) */
    using bsrr_bs11 = lp::assoc_bit<bsrr, 11>;
    /* Port x set bit y (y=               0..15) */
    using bsrr_bs10 = lp::assoc_bit<bsrr, 10>;
    /* Port x set bit y (y=               0..15) */
    using bsrr_bs9 = lp::assoc_bit<bsrr, 9>;
    /* Port x set bit y (y=               0..15) */
    using bsrr_bs8 = lp::assoc_bit<bsrr, 8>;
    /* Port x set bit y (y=               0..15) */
    using bsrr_bs7 = lp::assoc_bit<bsrr, 7>;
    /* Port x set bit y (y=               0..15) */
    using bsrr_bs6 = lp::assoc_bit<bsrr, 6>;
    /* Port x set bit y (y=               0..15) */
    using bsrr_bs5 = lp::assoc_bit<bsrr, 5>;
    /* Port x set bit y (y=               0..15) */
    using bsrr_bs4 = lp::assoc_bit<bsrr, 4>;
    /* Port x set bit y (y=               0..15) */
    using bsrr_bs3 = lp::assoc_bit<bsrr, 3>;
    /* Port x set bit y (y=               0..15) */
    using bsrr_bs2 = lp::assoc_bit<bsrr, 2>;
    /* Port x set bit y (y=               0..15) */
    using bsrr_bs1 = lp::assoc_bit<bsrr, 1>;
    /* Port x set bit y (y=               0..15) */
    using bsrr_bs0 = lp::assoc_bit<bsrr, 0>;


    /* GPIO port configuration lock           register */
    using lckr = lp::io_register<lp::u32_t, base_address + 0x1c>;
    /* Port x lock bit y (y=               0..15) */
    using lckr_lckk = lp::assoc_bit<lckr, 16>;
    /* Port x lock bit y (y=               0..15) */
    using lckr_lck15 = lp::assoc_bit<lckr, 15>;
    /* Port x lock bit y (y=               0..15) */
    using lckr_lck14 = lp::assoc_bit<lckr, 14>;
    /* Port x lock bit y (y=               0..15) */
    using lckr_lck13 = lp::assoc_bit<lckr, 13>;
    /* Port x lock bit y (y=               0..15) */
    using lckr_lck12 = lp::assoc_bit<lckr, 12>;
    /* Port x lock bit y (y=               0..15) */
    using lckr_lck11 = lp::assoc_bit<lckr, 11>;
    /* Port x lock bit y (y=               0..15) */
    using lckr_lck10 = lp::assoc_bit<lckr, 10>;
    /* Port x lock bit y (y=               0..15) */
    using lckr_lck9 = lp::assoc_bit<lckr, 9>;
    /* Port x lock bit y (y=               0..15) */
    using lckr_lck8 = lp::assoc_bit<lckr, 8>;
    /* Port x lock bit y (y=               0..15) */
    using lckr_lck7 = lp::assoc_bit<lckr, 7>;
    /* Port x lock bit y (y=               0..15) */
    using lckr_lck6 = lp::assoc_bit<lckr, 6>;
    /* Port x lock bit y (y=               0..15) */
    using lckr_lck5 = lp::assoc_bit<lckr, 5>;
    /* Port x lock bit y (y=               0..15) */
    using lckr_lck4 = lp::assoc_bit<lckr, 4>;
    /* Port x lock bit y (y=               0..15) */
    using lckr_lck3 = lp::assoc_bit<lckr, 3>;
    /* Port x lock bit y (y=               0..15) */
    using lckr_lck2 = lp::assoc_bit<lckr, 2>;
    /* Port x lock bit y (y=               0..15) */
    using lckr_lck1 = lp::assoc_bit<lckr, 1>;
    /* Port x lock bit y (y=               0..15) */
    using lckr_lck0 = lp::assoc_bit<lckr, 0>;


    /* GPIO alternate function low           register */
    using afrl = lp::io_register<lp::u32_t, base_address + 0x20>;
    /* Alternate function selection for port x               bit y (y = 0..7) */
    using afrl_afrl7 = lp::assoc_bit<afrl, 28, 4>;
    /* Alternate function selection for port x               bit y (y = 0..7) */
    using afrl_afrl6 = lp::assoc_bit<afrl, 24, 4>;
    /* Alternate function selection for port x               bit y (y = 0..7) */
    using afrl_afrl5 = lp::assoc_bit<afrl, 20, 4>;
    /* Alternate function selection for port x               bit y (y = 0..7) */
    using afrl_afrl4 = lp::assoc_bit<afrl, 16, 4>;
    /* Alternate function selection for port x               bit y (y = 0..7) */
    using afrl_afrl3 = lp::assoc_bit<afrl, 12, 4>;
    /* Alternate function selection for port x               bit y (y = 0..7) */
    using afrl_afrl2 = lp::assoc_bit<afrl, 8, 4>;
    /* Alternate function selection for port x               bit y (y = 0..7) */
    using afrl_afrl1 = lp::assoc_bit<afrl, 4, 4>;
    /* Alternate function selection for port x               bit y (y = 0..7) */
    using afrl_afrl0 = lp::assoc_bit<afrl, 0, 4>;


    /* GPIO alternate function high           register */
    using afrh = lp::io_register<lp::u32_t, base_address + 0x24>;
    /* Alternate function selection for port x               bit y (y = 8..15) */
    using afrh_afrh15 = lp::assoc_bit<afrh, 28, 4>;
    /* Alternate function selection for port x               bit y (y = 8..15) */
    using afrh_afrh14 = lp::assoc_bit<afrh, 24, 4>;
    /* Alternate function selection for port x               bit y (y = 8..15) */
    using afrh_afrh13 = lp::assoc_bit<afrh, 20, 4>;
    /* Alternate function selection for port x               bit y (y = 8..15) */
    using afrh_afrh12 = lp::assoc_bit<afrh, 16, 4>;
    /* Alternate function selection for port x               bit y (y = 8..15) */
    using afrh_afrh11 = lp::assoc_bit<afrh, 12, 4>;
    /* Alternate function selection for port x               bit y (y = 8..15) */
    using afrh_afrh10 = lp::assoc_bit<afrh, 8, 4>;
    /* Alternate function selection for port x               bit y (y = 8..15) */
    using afrh_afrh9 = lp::assoc_bit<afrh, 4, 4>;
    /* Alternate function selection for port x               bit y (y = 8..15) */
    using afrh_afrh8 = lp::assoc_bit<afrh, 0, 4>;


    /* GPIO port bit reset register */
    using brr = lp::io_register<lp::u32_t, base_address + 0x28>;
    /* Port Reset bit */
    using brr_br0 = lp::assoc_bit<brr, 0>;
    /* Port Reset bit */
    using brr_br1 = lp::assoc_bit<brr, 1>;
    /* Port Reset bit */
    using brr_br2 = lp::assoc_bit<brr, 2>;
    /* Port Reset bit */
    using brr_br3 = lp::assoc_bit<brr, 3>;
    /* Port Reset bit */
    using brr_br4 = lp::assoc_bit<brr, 4>;
    /* Port Reset bit */
    using brr_br5 = lp::assoc_bit<brr, 5>;
    /* Port Reset bit */
    using brr_br6 = lp::assoc_bit<brr, 6>;
    /* Port Reset bit */
    using brr_br7 = lp::assoc_bit<brr, 7>;
    /* Port Reset bit */
    using brr_br8 = lp::assoc_bit<brr, 8>;
    /* Port Reset bit */
    using brr_br9 = lp::assoc_bit<brr, 9>;
    /* Port Reset bit */
    using brr_br10 = lp::assoc_bit<brr, 10>;
    /* Port Reset bit */
    using brr_br11 = lp::assoc_bit<brr, 11>;
    /* Port Reset bit */
    using brr_br12 = lp::assoc_bit<brr, 12>;
    /* Port Reset bit */
    using brr_br13 = lp::assoc_bit<brr, 13>;
    /* Port Reset bit */
    using brr_br14 = lp::assoc_bit<brr, 14>;
    /* Port Reset bit */
    using brr_br15 = lp::assoc_bit<brr, 15>;


    /* GPIO port analog switch control           register */
    using ascr = lp::io_register<lp::u32_t, base_address + 0x2c>;
    /* Port analog switch control */
    using ascr_asc0 = lp::assoc_bit<ascr, 0>;
    /* Port analog switch control */
    using ascr_asc1 = lp::assoc_bit<ascr, 1>;
    /* Port analog switch control */
    using ascr_asc2 = lp::assoc_bit<ascr, 2>;
    /* Port analog switch control */
    using ascr_asc3 = lp::assoc_bit<ascr, 3>;
    /* Port analog switch control */
    using ascr_asc4 = lp::assoc_bit<ascr, 4>;
    /* Port analog switch control */
    using ascr_asc5 = lp::assoc_bit<ascr, 5>;
    /* Port analog switch control */
    using ascr_asc6 = lp::assoc_bit<ascr, 6>;
    /* Port analog switch control */
    using ascr_asc7 = lp::assoc_bit<ascr, 7>;
    /* Port analog switch control */
    using ascr_asc8 = lp::assoc_bit<ascr, 8>;
    /* Port analog switch control */
    using ascr_asc9 = lp::assoc_bit<ascr, 9>;
    /* Port analog switch control */
    using ascr_asc10 = lp::assoc_bit<ascr, 10>;
    /* Port analog switch control */
    using ascr_asc11 = lp::assoc_bit<ascr, 11>;
    /* Port analog switch control */
    using ascr_asc12 = lp::assoc_bit<ascr, 12>;
    /* Port analog switch control */
    using ascr_asc13 = lp::assoc_bit<ascr, 13>;
    /* Port analog switch control */
    using ascr_asc14 = lp::assoc_bit<ascr, 14>;
    /* Port analog switch control */
    using ascr_asc15 = lp::assoc_bit<ascr, 15>;


};

/* General-purpose I/Os */
template <lp::addr_t base_address>
struct gpioi_t {
    /* GPIO port mode register */
    using moder = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* Port x configuration bits (y =               0..15) */
    using moder_moder15 = lp::assoc_bit<moder, 30, 2>;
    /* Port x configuration bits (y =               0..15) */
    using moder_moder14 = lp::assoc_bit<moder, 28, 2>;
    /* Port x configuration bits (y =               0..15) */
    using moder_moder13 = lp::assoc_bit<moder, 26, 2>;
    /* Port x configuration bits (y =               0..15) */
    using moder_moder12 = lp::assoc_bit<moder, 24, 2>;
    /* Port x configuration bits (y =               0..15) */
    using moder_moder11 = lp::assoc_bit<moder, 22, 2>;
    /* Port x configuration bits (y =               0..15) */
    using moder_moder10 = lp::assoc_bit<moder, 20, 2>;
    /* Port x configuration bits (y =               0..15) */
    using moder_moder9 = lp::assoc_bit<moder, 18, 2>;
    /* Port x configuration bits (y =               0..15) */
    using moder_moder8 = lp::assoc_bit<moder, 16, 2>;
    /* Port x configuration bits (y =               0..15) */
    using moder_moder7 = lp::assoc_bit<moder, 14, 2>;
    /* Port x configuration bits (y =               0..15) */
    using moder_moder6 = lp::assoc_bit<moder, 12, 2>;
    /* Port x configuration bits (y =               0..15) */
    using moder_moder5 = lp::assoc_bit<moder, 10, 2>;
    /* Port x configuration bits (y =               0..15) */
    using moder_moder4 = lp::assoc_bit<moder, 8, 2>;
    /* Port x configuration bits (y =               0..15) */
    using moder_moder3 = lp::assoc_bit<moder, 6, 2>;
    /* Port x configuration bits (y =               0..15) */
    using moder_moder2 = lp::assoc_bit<moder, 4, 2>;
    /* Port x configuration bits (y =               0..15) */
    using moder_moder1 = lp::assoc_bit<moder, 2, 2>;
    /* Port x configuration bits (y =               0..15) */
    using moder_moder0 = lp::assoc_bit<moder, 0, 2>;


    /* GPIO port output type register */
    using otyper = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* Port x configuration bits (y =               0..15) */
    using otyper_ot15 = lp::assoc_bit<otyper, 15>;
    /* Port x configuration bits (y =               0..15) */
    using otyper_ot14 = lp::assoc_bit<otyper, 14>;
    /* Port x configuration bits (y =               0..15) */
    using otyper_ot13 = lp::assoc_bit<otyper, 13>;
    /* Port x configuration bits (y =               0..15) */
    using otyper_ot12 = lp::assoc_bit<otyper, 12>;
    /* Port x configuration bits (y =               0..15) */
    using otyper_ot11 = lp::assoc_bit<otyper, 11>;
    /* Port x configuration bits (y =               0..15) */
    using otyper_ot10 = lp::assoc_bit<otyper, 10>;
    /* Port x configuration bits (y =               0..15) */
    using otyper_ot9 = lp::assoc_bit<otyper, 9>;
    /* Port x configuration bits (y =               0..15) */
    using otyper_ot8 = lp::assoc_bit<otyper, 8>;
    /* Port x configuration bits (y =               0..15) */
    using otyper_ot7 = lp::assoc_bit<otyper, 7>;
    /* Port x configuration bits (y =               0..15) */
    using otyper_ot6 = lp::assoc_bit<otyper, 6>;
    /* Port x configuration bits (y =               0..15) */
    using otyper_ot5 = lp::assoc_bit<otyper, 5>;
    /* Port x configuration bits (y =               0..15) */
    using otyper_ot4 = lp::assoc_bit<otyper, 4>;
    /* Port x configuration bits (y =               0..15) */
    using otyper_ot3 = lp::assoc_bit<otyper, 3>;
    /* Port x configuration bits (y =               0..15) */
    using otyper_ot2 = lp::assoc_bit<otyper, 2>;
    /* Port x configuration bits (y =               0..15) */
    using otyper_ot1 = lp::assoc_bit<otyper, 1>;
    /* Port x configuration bits (y =               0..15) */
    using otyper_ot0 = lp::assoc_bit<otyper, 0>;


    /* GPIO port output speed           register */
    using ospeedr = lp::io_register<lp::u32_t, base_address + 0x8>;
    /* Port x configuration bits (y =               0..15) */
    using ospeedr_ospeedr15 = lp::assoc_bit<ospeedr, 30, 2>;
    /* Port x configuration bits (y =               0..15) */
    using ospeedr_ospeedr14 = lp::assoc_bit<ospeedr, 28, 2>;
    /* Port x configuration bits (y =               0..15) */
    using ospeedr_ospeedr13 = lp::assoc_bit<ospeedr, 26, 2>;
    /* Port x configuration bits (y =               0..15) */
    using ospeedr_ospeedr12 = lp::assoc_bit<ospeedr, 24, 2>;
    /* Port x configuration bits (y =               0..15) */
    using ospeedr_ospeedr11 = lp::assoc_bit<ospeedr, 22, 2>;
    /* Port x configuration bits (y =               0..15) */
    using ospeedr_ospeedr10 = lp::assoc_bit<ospeedr, 20, 2>;
    /* Port x configuration bits (y =               0..15) */
    using ospeedr_ospeedr9 = lp::assoc_bit<ospeedr, 18, 2>;
    /* Port x configuration bits (y =               0..15) */
    using ospeedr_ospeedr8 = lp::assoc_bit<ospeedr, 16, 2>;
    /* Port x configuration bits (y =               0..15) */
    using ospeedr_ospeedr7 = lp::assoc_bit<ospeedr, 14, 2>;
    /* Port x configuration bits (y =               0..15) */
    using ospeedr_ospeedr6 = lp::assoc_bit<ospeedr, 12, 2>;
    /* Port x configuration bits (y =               0..15) */
    using ospeedr_ospeedr5 = lp::assoc_bit<ospeedr, 10, 2>;
    /* Port x configuration bits (y =               0..15) */
    using ospeedr_ospeedr4 = lp::assoc_bit<ospeedr, 8, 2>;
    /* Port x configuration bits (y =               0..15) */
    using ospeedr_ospeedr3 = lp::assoc_bit<ospeedr, 6, 2>;
    /* Port x configuration bits (y =               0..15) */
    using ospeedr_ospeedr2 = lp::assoc_bit<ospeedr, 4, 2>;
    /* Port x configuration bits (y =               0..15) */
    using ospeedr_ospeedr1 = lp::assoc_bit<ospeedr, 2, 2>;
    /* Port x configuration bits (y =               0..15) */
    using ospeedr_ospeedr0 = lp::assoc_bit<ospeedr, 0, 2>;


    /* GPIO port pull-up/pull-down           register */
    using pupdr = lp::io_register<lp::u32_t, base_address + 0xc>;
    /* Port x configuration bits (y =               0..15) */
    using pupdr_pupdr15 = lp::assoc_bit<pupdr, 30, 2>;
    /* Port x configuration bits (y =               0..15) */
    using pupdr_pupdr14 = lp::assoc_bit<pupdr, 28, 2>;
    /* Port x configuration bits (y =               0..15) */
    using pupdr_pupdr13 = lp::assoc_bit<pupdr, 26, 2>;
    /* Port x configuration bits (y =               0..15) */
    using pupdr_pupdr12 = lp::assoc_bit<pupdr, 24, 2>;
    /* Port x configuration bits (y =               0..15) */
    using pupdr_pupdr11 = lp::assoc_bit<pupdr, 22, 2>;
    /* Port x configuration bits (y =               0..15) */
    using pupdr_pupdr10 = lp::assoc_bit<pupdr, 20, 2>;
    /* Port x configuration bits (y =               0..15) */
    using pupdr_pupdr9 = lp::assoc_bit<pupdr, 18, 2>;
    /* Port x configuration bits (y =               0..15) */
    using pupdr_pupdr8 = lp::assoc_bit<pupdr, 16, 2>;
    /* Port x configuration bits (y =               0..15) */
    using pupdr_pupdr7 = lp::assoc_bit<pupdr, 14, 2>;
    /* Port x configuration bits (y =               0..15) */
    using pupdr_pupdr6 = lp::assoc_bit<pupdr, 12, 2>;
    /* Port x configuration bits (y =               0..15) */
    using pupdr_pupdr5 = lp::assoc_bit<pupdr, 10, 2>;
    /* Port x configuration bits (y =               0..15) */
    using pupdr_pupdr4 = lp::assoc_bit<pupdr, 8, 2>;
    /* Port x configuration bits (y =               0..15) */
    using pupdr_pupdr3 = lp::assoc_bit<pupdr, 6, 2>;
    /* Port x configuration bits (y =               0..15) */
    using pupdr_pupdr2 = lp::assoc_bit<pupdr, 4, 2>;
    /* Port x configuration bits (y =               0..15) */
    using pupdr_pupdr1 = lp::assoc_bit<pupdr, 2, 2>;
    /* Port x configuration bits (y =               0..15) */
    using pupdr_pupdr0 = lp::assoc_bit<pupdr, 0, 2>;


    /* GPIO port input data register */
    using idr = lp::io_register<lp::u32_t, base_address + 0x10>;
    /* Port input data (y =               0..15) */
    using idr_idr15 = lp::assoc_bit<idr, 15>;
    /* Port input data (y =               0..15) */
    using idr_idr14 = lp::assoc_bit<idr, 14>;
    /* Port input data (y =               0..15) */
    using idr_idr13 = lp::assoc_bit<idr, 13>;
    /* Port input data (y =               0..15) */
    using idr_idr12 = lp::assoc_bit<idr, 12>;
    /* Port input data (y =               0..15) */
    using idr_idr11 = lp::assoc_bit<idr, 11>;
    /* Port input data (y =               0..15) */
    using idr_idr10 = lp::assoc_bit<idr, 10>;
    /* Port input data (y =               0..15) */
    using idr_idr9 = lp::assoc_bit<idr, 9>;
    /* Port input data (y =               0..15) */
    using idr_idr8 = lp::assoc_bit<idr, 8>;
    /* Port input data (y =               0..15) */
    using idr_idr7 = lp::assoc_bit<idr, 7>;
    /* Port input data (y =               0..15) */
    using idr_idr6 = lp::assoc_bit<idr, 6>;
    /* Port input data (y =               0..15) */
    using idr_idr5 = lp::assoc_bit<idr, 5>;
    /* Port input data (y =               0..15) */
    using idr_idr4 = lp::assoc_bit<idr, 4>;
    /* Port input data (y =               0..15) */
    using idr_idr3 = lp::assoc_bit<idr, 3>;
    /* Port input data (y =               0..15) */
    using idr_idr2 = lp::assoc_bit<idr, 2>;
    /* Port input data (y =               0..15) */
    using idr_idr1 = lp::assoc_bit<idr, 1>;
    /* Port input data (y =               0..15) */
    using idr_idr0 = lp::assoc_bit<idr, 0>;


    /* GPIO port output data register */
    using odr = lp::io_register<lp::u32_t, base_address + 0x14>;
    /* Port output data (y =               0..15) */
    using odr_odr15 = lp::assoc_bit<odr, 15>;
    /* Port output data (y =               0..15) */
    using odr_odr14 = lp::assoc_bit<odr, 14>;
    /* Port output data (y =               0..15) */
    using odr_odr13 = lp::assoc_bit<odr, 13>;
    /* Port output data (y =               0..15) */
    using odr_odr12 = lp::assoc_bit<odr, 12>;
    /* Port output data (y =               0..15) */
    using odr_odr11 = lp::assoc_bit<odr, 11>;
    /* Port output data (y =               0..15) */
    using odr_odr10 = lp::assoc_bit<odr, 10>;
    /* Port output data (y =               0..15) */
    using odr_odr9 = lp::assoc_bit<odr, 9>;
    /* Port output data (y =               0..15) */
    using odr_odr8 = lp::assoc_bit<odr, 8>;
    /* Port output data (y =               0..15) */
    using odr_odr7 = lp::assoc_bit<odr, 7>;
    /* Port output data (y =               0..15) */
    using odr_odr6 = lp::assoc_bit<odr, 6>;
    /* Port output data (y =               0..15) */
    using odr_odr5 = lp::assoc_bit<odr, 5>;
    /* Port output data (y =               0..15) */
    using odr_odr4 = lp::assoc_bit<odr, 4>;
    /* Port output data (y =               0..15) */
    using odr_odr3 = lp::assoc_bit<odr, 3>;
    /* Port output data (y =               0..15) */
    using odr_odr2 = lp::assoc_bit<odr, 2>;
    /* Port output data (y =               0..15) */
    using odr_odr1 = lp::assoc_bit<odr, 1>;
    /* Port output data (y =               0..15) */
    using odr_odr0 = lp::assoc_bit<odr, 0>;


    /* GPIO port bit set/reset           register */
    using bsrr = lp::io_register<lp::u32_t, base_address + 0x18>;
    /* Port x reset bit y (y =               0..15) */
    using bsrr_br15 = lp::assoc_bit<bsrr, 31>;
    /* Port x reset bit y (y =               0..15) */
    using bsrr_br14 = lp::assoc_bit<bsrr, 30>;
    /* Port x reset bit y (y =               0..15) */
    using bsrr_br13 = lp::assoc_bit<bsrr, 29>;
    /* Port x reset bit y (y =               0..15) */
    using bsrr_br12 = lp::assoc_bit<bsrr, 28>;
    /* Port x reset bit y (y =               0..15) */
    using bsrr_br11 = lp::assoc_bit<bsrr, 27>;
    /* Port x reset bit y (y =               0..15) */
    using bsrr_br10 = lp::assoc_bit<bsrr, 26>;
    /* Port x reset bit y (y =               0..15) */
    using bsrr_br9 = lp::assoc_bit<bsrr, 25>;
    /* Port x reset bit y (y =               0..15) */
    using bsrr_br8 = lp::assoc_bit<bsrr, 24>;
    /* Port x reset bit y (y =               0..15) */
    using bsrr_br7 = lp::assoc_bit<bsrr, 23>;
    /* Port x reset bit y (y =               0..15) */
    using bsrr_br6 = lp::assoc_bit<bsrr, 22>;
    /* Port x reset bit y (y =               0..15) */
    using bsrr_br5 = lp::assoc_bit<bsrr, 21>;
    /* Port x reset bit y (y =               0..15) */
    using bsrr_br4 = lp::assoc_bit<bsrr, 20>;
    /* Port x reset bit y (y =               0..15) */
    using bsrr_br3 = lp::assoc_bit<bsrr, 19>;
    /* Port x reset bit y (y =               0..15) */
    using bsrr_br2 = lp::assoc_bit<bsrr, 18>;
    /* Port x reset bit y (y =               0..15) */
    using bsrr_br1 = lp::assoc_bit<bsrr, 17>;
    /* Port x set bit y (y=               0..15) */
    using bsrr_br0 = lp::assoc_bit<bsrr, 16>;
    /* Port x set bit y (y=               0..15) */
    using bsrr_bs15 = lp::assoc_bit<bsrr, 15>;
    /* Port x set bit y (y=               0..15) */
    using bsrr_bs14 = lp::assoc_bit<bsrr, 14>;
    /* Port x set bit y (y=               0..15) */
    using bsrr_bs13 = lp::assoc_bit<bsrr, 13>;
    /* Port x set bit y (y=               0..15) */
    using bsrr_bs12 = lp::assoc_bit<bsrr, 12>;
    /* Port x set bit y (y=               0..15) */
    using bsrr_bs11 = lp::assoc_bit<bsrr, 11>;
    /* Port x set bit y (y=               0..15) */
    using bsrr_bs10 = lp::assoc_bit<bsrr, 10>;
    /* Port x set bit y (y=               0..15) */
    using bsrr_bs9 = lp::assoc_bit<bsrr, 9>;
    /* Port x set bit y (y=               0..15) */
    using bsrr_bs8 = lp::assoc_bit<bsrr, 8>;
    /* Port x set bit y (y=               0..15) */
    using bsrr_bs7 = lp::assoc_bit<bsrr, 7>;
    /* Port x set bit y (y=               0..15) */
    using bsrr_bs6 = lp::assoc_bit<bsrr, 6>;
    /* Port x set bit y (y=               0..15) */
    using bsrr_bs5 = lp::assoc_bit<bsrr, 5>;
    /* Port x set bit y (y=               0..15) */
    using bsrr_bs4 = lp::assoc_bit<bsrr, 4>;
    /* Port x set bit y (y=               0..15) */
    using bsrr_bs3 = lp::assoc_bit<bsrr, 3>;
    /* Port x set bit y (y=               0..15) */
    using bsrr_bs2 = lp::assoc_bit<bsrr, 2>;
    /* Port x set bit y (y=               0..15) */
    using bsrr_bs1 = lp::assoc_bit<bsrr, 1>;
    /* Port x set bit y (y=               0..15) */
    using bsrr_bs0 = lp::assoc_bit<bsrr, 0>;


    /* GPIO port configuration lock           register */
    using lckr = lp::io_register<lp::u32_t, base_address + 0x1c>;
    /* Port x lock bit y (y=               0..15) */
    using lckr_lckk = lp::assoc_bit<lckr, 16>;
    /* Port x lock bit y (y=               0..15) */
    using lckr_lck15 = lp::assoc_bit<lckr, 15>;
    /* Port x lock bit y (y=               0..15) */
    using lckr_lck14 = lp::assoc_bit<lckr, 14>;
    /* Port x lock bit y (y=               0..15) */
    using lckr_lck13 = lp::assoc_bit<lckr, 13>;
    /* Port x lock bit y (y=               0..15) */
    using lckr_lck12 = lp::assoc_bit<lckr, 12>;
    /* Port x lock bit y (y=               0..15) */
    using lckr_lck11 = lp::assoc_bit<lckr, 11>;
    /* Port x lock bit y (y=               0..15) */
    using lckr_lck10 = lp::assoc_bit<lckr, 10>;
    /* Port x lock bit y (y=               0..15) */
    using lckr_lck9 = lp::assoc_bit<lckr, 9>;
    /* Port x lock bit y (y=               0..15) */
    using lckr_lck8 = lp::assoc_bit<lckr, 8>;
    /* Port x lock bit y (y=               0..15) */
    using lckr_lck7 = lp::assoc_bit<lckr, 7>;
    /* Port x lock bit y (y=               0..15) */
    using lckr_lck6 = lp::assoc_bit<lckr, 6>;
    /* Port x lock bit y (y=               0..15) */
    using lckr_lck5 = lp::assoc_bit<lckr, 5>;
    /* Port x lock bit y (y=               0..15) */
    using lckr_lck4 = lp::assoc_bit<lckr, 4>;
    /* Port x lock bit y (y=               0..15) */
    using lckr_lck3 = lp::assoc_bit<lckr, 3>;
    /* Port x lock bit y (y=               0..15) */
    using lckr_lck2 = lp::assoc_bit<lckr, 2>;
    /* Port x lock bit y (y=               0..15) */
    using lckr_lck1 = lp::assoc_bit<lckr, 1>;
    /* Port x lock bit y (y=               0..15) */
    using lckr_lck0 = lp::assoc_bit<lckr, 0>;


    /* GPIO alternate function low           register */
    using afrl = lp::io_register<lp::u32_t, base_address + 0x20>;
    /* Alternate function selection for port x               bit y (y = 0..7) */
    using afrl_afrl7 = lp::assoc_bit<afrl, 28, 4>;
    /* Alternate function selection for port x               bit y (y = 0..7) */
    using afrl_afrl6 = lp::assoc_bit<afrl, 24, 4>;
    /* Alternate function selection for port x               bit y (y = 0..7) */
    using afrl_afrl5 = lp::assoc_bit<afrl, 20, 4>;
    /* Alternate function selection for port x               bit y (y = 0..7) */
    using afrl_afrl4 = lp::assoc_bit<afrl, 16, 4>;
    /* Alternate function selection for port x               bit y (y = 0..7) */
    using afrl_afrl3 = lp::assoc_bit<afrl, 12, 4>;
    /* Alternate function selection for port x               bit y (y = 0..7) */
    using afrl_afrl2 = lp::assoc_bit<afrl, 8, 4>;
    /* Alternate function selection for port x               bit y (y = 0..7) */
    using afrl_afrl1 = lp::assoc_bit<afrl, 4, 4>;
    /* Alternate function selection for port x               bit y (y = 0..7) */
    using afrl_afrl0 = lp::assoc_bit<afrl, 0, 4>;


    /* GPIO alternate function high           register */
    using afrh = lp::io_register<lp::u32_t, base_address + 0x24>;
    /* Alternate function selection for port x               bit y (y = 8..15) */
    using afrh_afrh15 = lp::assoc_bit<afrh, 28, 4>;
    /* Alternate function selection for port x               bit y (y = 8..15) */
    using afrh_afrh14 = lp::assoc_bit<afrh, 24, 4>;
    /* Alternate function selection for port x               bit y (y = 8..15) */
    using afrh_afrh13 = lp::assoc_bit<afrh, 20, 4>;
    /* Alternate function selection for port x               bit y (y = 8..15) */
    using afrh_afrh12 = lp::assoc_bit<afrh, 16, 4>;
    /* Alternate function selection for port x               bit y (y = 8..15) */
    using afrh_afrh11 = lp::assoc_bit<afrh, 12, 4>;
    /* Alternate function selection for port x               bit y (y = 8..15) */
    using afrh_afrh10 = lp::assoc_bit<afrh, 8, 4>;
    /* Alternate function selection for port x               bit y (y = 8..15) */
    using afrh_afrh9 = lp::assoc_bit<afrh, 4, 4>;
    /* Alternate function selection for port x               bit y (y = 8..15) */
    using afrh_afrh8 = lp::assoc_bit<afrh, 0, 4>;


    /* GPIO port bit reset register */
    using brr = lp::io_register<lp::u32_t, base_address + 0x28>;
    /* Port Reset bit */
    using brr_br0 = lp::assoc_bit<brr, 0>;
    /* Port Reset bit */
    using brr_br1 = lp::assoc_bit<brr, 1>;
    /* Port Reset bit */
    using brr_br2 = lp::assoc_bit<brr, 2>;
    /* Port Reset bit */
    using brr_br3 = lp::assoc_bit<brr, 3>;
    /* Port Reset bit */
    using brr_br4 = lp::assoc_bit<brr, 4>;
    /* Port Reset bit */
    using brr_br5 = lp::assoc_bit<brr, 5>;
    /* Port Reset bit */
    using brr_br6 = lp::assoc_bit<brr, 6>;
    /* Port Reset bit */
    using brr_br7 = lp::assoc_bit<brr, 7>;
    /* Port Reset bit */
    using brr_br8 = lp::assoc_bit<brr, 8>;
    /* Port Reset bit */
    using brr_br9 = lp::assoc_bit<brr, 9>;
    /* Port Reset bit */
    using brr_br10 = lp::assoc_bit<brr, 10>;
    /* Port Reset bit */
    using brr_br11 = lp::assoc_bit<brr, 11>;
    /* Port Reset bit */
    using brr_br12 = lp::assoc_bit<brr, 12>;
    /* Port Reset bit */
    using brr_br13 = lp::assoc_bit<brr, 13>;
    /* Port Reset bit */
    using brr_br14 = lp::assoc_bit<brr, 14>;
    /* Port Reset bit */
    using brr_br15 = lp::assoc_bit<brr, 15>;


};

using gpioa = gpio_t<0x48000000>;
using gpiob = gpio_t<0x48000400>;
using gpioc = gpio_t<0x48000800>;
using gpiod = gpio_t<0x48000c00>;
using gpioe = gpio_t<0x48001000>;
using gpiof = gpio_t<0x48001400>;
using gpiog = gpio_t<0x48001800>;
using gpioh = gpio_t<0x48001c00>;
using gpioi = gpioi_t<0x48002000>;

#endif // GPIO_HH
