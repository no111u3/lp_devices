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
 * Hardware abstraction layer for tim
 * type definitions for tim
 * @file tim_type.hh
 * @author Boris Vinogradov
 */

#include <bit.hh>
#include <io_register.hh>
#include <io_register_operation_traits.hh>
#include <types.hh>
#include <type_list.hh>
#include <type_list_traits.hh>

#include <tim.hh>

#ifndef HAL_TIM_TYPE_HH
#define HAL_TIM_TYPE_HH

namespace hal {
    template <typename Tim_block>
    struct tim {
        using block = Tim_block;
        using status = typename block::sr;

        struct config {
            using update_int_enable = typename block::dier_uie;
            template <lp::word_t Prescaller>
            using prescaller = typename block::psc_psc::template with_value<Prescaller - 1>;
            template <lp::word_t Reload_value>
            using reload_value = typename block::arr_arr::template with_value<Reload_value>;
        };

        using register_setup_list = lp::type_list<
            typename block::psc,
            typename block::arr,
            typename block::dier::op_set_or,
            typename block::cr1::op_set_or
        >;

        template <typename ...Params>
        static constexpr void setup() noexcept {
            lp::register_op_unpack<
                register_setup_list,
                typename lp::repack_v<Params...>::template append<typename block::cr1_cen>
            >::apply();
        }

        static constexpr void disable() noexcept {
            block::cr1::template set_nand<typename block::cr1_cen>();
        }

        template <typename ...Bits>
        static constexpr auto get_status() noexcept {
            return status::template get_and<Bits...>();
        }

        template <typename ...Bits>
        static constexpr void clear_status() noexcept {
            status::template set_nand<Bits...>();
        }
    };
} // namespace hal

#endif // HAL_TIM_TYPE_HH
