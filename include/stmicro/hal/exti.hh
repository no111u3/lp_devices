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
 * Hardware abstraction layer for exti
 * @file exti.hh
 * @author Boris Vinogradov
 */

#include <types.hh>

#include <hal/device.hh>
#include <hal/exti_device.hh>

#ifndef HAL_EXTI_HH
#define HAL_EXTI_HH

namespace hal {
    struct exti {
        template <device::exti exti_num>
        static constexpr void unmask_int() noexcept {
            exti_device::imr::get<
                (static_cast<lp::word_t>(exti_num) >> 5)
            >::template set_or<lp::bit<(static_cast<lp::word_t>(exti_num) & 0x1f)>>();
        }

        template <device::exti exti_num>
        static constexpr void mask_int() noexcept {
            exti_device::imr::get<
                (static_cast<lp::word_t>(exti_num) >> 5)
            >::template set_nand<lp::bit<(static_cast<lp::word_t>(exti_num) & 0x1f)>>();
        }

        template <device::exti exti_num>
        static constexpr void unmask_event() noexcept {
            exti_device::emr::get<
                (static_cast<lp::word_t>(exti_num) >> 5)
            >::template set_or<lp::bit<(static_cast<lp::word_t>(exti_num) & 0x1f)>>();
        }

        template <device::exti exti_num>
        static constexpr void mask_event() noexcept {
            exti_device::emr::get<
                (static_cast<lp::word_t>(exti_num) >> 5)
            >::template set_nand<lp::bit<(static_cast<lp::word_t>(exti_num) & 0x1f)>>();
        }

        template <device::exti exti_num>
        static constexpr void rising_edge_en() noexcept {
            exti_device::rtsr::get<
                (static_cast<lp::word_t>(exti_num) >> 5)
            >::template set_or<lp::bit<(static_cast<lp::word_t>(exti_num) & 0x1f)>>();
        }

        template <device::exti exti_num>
        static constexpr void rising_edge_dis() noexcept {
            exti_device::rtsr::get<
                (static_cast<lp::word_t>(exti_num) >> 5)
            >::template set_nand<lp::bit<(static_cast<lp::word_t>(exti_num) & 0x1f)>>();
        }

        template <device::exti exti_num>
        static constexpr void faling_edge_en() noexcept {
            exti_device::ftsr::get<
                (static_cast<lp::word_t>(exti_num) >> 5)
            >::template set_or<lp::bit<(static_cast<lp::word_t>(exti_num) & 0x1f)>>();
        }

        template <device::exti exti_num>
        static constexpr void failng_edge_dis() noexcept {
            exti_device::ftsr::get<
                (static_cast<lp::word_t>(exti_num) >> 5)
            >::template set_nand<lp::bit<(static_cast<lp::word_t>(exti_num) & 0x1f)>>();
        }

        template <device::exti exti_num>
        static constexpr void sw_event_en() noexcept {
            exti_device::swier::get<
                (static_cast<lp::word_t>(exti_num) >> 5)
            >::template set_or<lp::bit<(static_cast<lp::word_t>(exti_num) & 0x1f)>>();
        }

        template <device::exti exti_num>
        static constexpr void sw_event_dis() noexcept {
            exti_device::swier::get<
                (static_cast<lp::word_t>(exti_num) >> 5)
            >::template set_nand<lp::bit<(static_cast<lp::word_t>(exti_num) & 0x1f)>>();
        }

        template <device::exti exti_num>
        static constexpr void pend_occurred() noexcept {
            exti_device::pr::get<
                (static_cast<lp::word_t>(exti_num) >> 5)
            >::template set_or<lp::bit<(static_cast<lp::word_t>(exti_num) & 0x1f)>>();
        }
    };
} // namespace hal

#endif // HAL_EXTI_HH
