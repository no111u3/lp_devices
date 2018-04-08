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
    }
}

#endif // HAL_DEVICE_HH
