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
 * Hardware abstraction layer for device specific features
 * @file device.hh
 * @author Boris Vinogradov
 */

#include <types.hh>

#ifndef HAL_DEVICE_HH
#define HAL_DEVICE_HH

namespace hal {
    namespace device {
        enum struct alt : lp::u32_t {
            sys_af = 0,
            tim1_2_5_8_lptim1 = 1,
            tim1_2_3_4_5 = 2,
            tim8 = 3,
            i2c1_2_3 = 4,
            spi1_2 = 5,
            spi3_dfsdm = 6,
            usart1_2_3 = 7,
            uart4_5_lpuart1 = 8,
            can1_tsc = 9,
            otg_fs_quadspi = 10,
            lcd = 11,
            sdmmc1_comp1_2_fmc_swpmi1 = 12,
            sai1_2 = 13,
            tim2_15_16_17_lptim2 = 14,
            eventout = 15
        };

        enum struct exti_route : lp::u32_t {
            gpioa = 0,
            gpiob = 1,
            gpioc = 2,
            gpiod = 3,
            gpioe = 4,
            gpiof = 5,
            gpiog = 6,
            gpioh = 7
        };

        enum struct exti : lp::u32_t {
            // Gpio signals
            gpio0 = 0,
            gpio1 = 1,
            gpio2 = 2,
            gpio3 = 3,
            gpio4 = 4,
            gpio5 = 5,
            gpio6 = 6,
            gpio7 = 7,
            gpio8 = 8,
            gpio9 = 9,
            gpio10 = 10,
            gpio11 = 11,
            gpio12 = 12,
            gpio13 = 13,
            gpio14 = 14,
            gpio15 = 15,
            // System signals
            pvd = 16,
            otg_fs = 17,
            rtc = 18,
            rtc_tamper_css_lse = 19,
            rtc_wakeup = 20,
            comp1_output = 21,
            comp2_output = 22,
            i2c1_wakeup = 23,
            i2c2_wakeup = 24,
            i2c3_wakeup = 25,
            usart1_wakeup = 26,
            usart2_wakeup = 27,
            usart3_wakeup = 28,
            uart4_wakeup = 29,
            uart5_wakeup = 30,
            lpuart1_wakeup = 31,
            lptim1 = 32,
            lptim2 = 33,
            swpmi1_wakeup = 34,
            pvm1_wakeup = 35,
            pvm2_wakeup = 36,
            pvm3_wakeup = 37,
            pvm4_wakeup = 38,
            lcd_wakeup = 39,
            i2c4_wakeup = 40
        };
    }
}

#endif // HAL_DEVICE_HH
