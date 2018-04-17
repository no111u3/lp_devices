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
 * Hardware abstraction layer for syscfg
 * @file syscfg.hh
 * @author Boris Vinogradov
 */

#include <types.hh>
#include <type_list.hh>

#include <hal/device.hh>

#include <syscfg.hh>

#ifndef HAL_SYSCFG_HH
#define HAL_SYSCFG_HH

namespace hal {
    struct syscfg {
        using exticr = lp::type_list<
            typename ::syscfg::exticr1,
            typename ::syscfg::exticr2,
            typename ::syscfg::exticr3,
            typename ::syscfg::exticr4
        >;

        template <device::exti exti_num, device::exti_route route_num>
        static constexpr void set_route() {
            exticr::get<
                (static_cast<lp::word_t>(exti_num) >> 2)
                >::template set_nand<
                    lp::bit<
                        (static_cast<lp::word_t>(exti_num) & 0x3) * 4,
                        4
                    >
                >();

            exticr::get<
                (static_cast<lp::word_t>(exti_num) >> 2)
                >::template set_or<
                    typename lp::bit<
                        (static_cast<lp::word_t>(exti_num) & 0x3) * 4,
                        4
                    >::template with_value<static_cast<lp::word_t>(route_num)>
                >();
        }
    };
} // namespace hal

#endif // HAL_SYSCFG_HH
