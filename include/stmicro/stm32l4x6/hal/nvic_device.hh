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
 * Hardware abstraction layer for device nvic
 * @file nvic_device.hh
 * @author Boris Vinogradov
 */

#include <nvic.hh>
#include <type_list.hh>

#ifndef HAL_NVIC_DEVICE_HH
#define HAL_NVIC_DEVICE_HH

namespace hal {
    namespace nvic_device {

        /* Interrupt Set-Enable Registers */
        using iser = lp::type_list<nvic::iser0, nvic::iser1, nvic::iser2>;

        /* Interrupt Clear-Enable
          Registers */
        using icer = lp::type_list<nvic::icer0, nvic::icer1, nvic::icer2>;

        /* Interrupt Set-Pending Registers */
        using ispr = lp::type_list<nvic::ispr0, nvic::ispr1, nvic::ispr2>;

        /* Interrupt Clear-Pending
          Registers */
        using icpr = lp::type_list<nvic::icpr0, nvic::icpr1, nvic::icpr2>;

        /* Interrupt Active Bit Registers */
        using iabr = lp::type_list<nvic::iabr0, nvic::iabr1, nvic::iabr2>;

        /* Interrupt Priority Registers */
        using ipr = lp::type_list<nvic::ipr0, nvic::ipr1, nvic::ipr2, nvic::ipr3, nvic::ipr4, nvic::ipr5, nvic::ipr6, nvic::ipr7, nvic::ipr8, nvic::ipr9, nvic::ipr10, nvic::ipr11, nvic::ipr12, nvic::ipr13, nvic::ipr14, nvic::ipr15, nvic::ipr16, nvic::ipr17, nvic::ipr18, nvic::ipr19, nvic::ipr20>;
    }
}

#endif // HAL_NVIC_DEVICE_HH
