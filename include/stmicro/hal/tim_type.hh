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
    struct tim_base {
        using block = Tim_block;

        struct config_general {
            using update_int_enable = typename block::dier_uie;
            template <lp::word_t Prescaller>
            using prescaller = typename block::psc_psc::template with_value<Prescaller - 1>;
        };

        struct config : config_general {
            template <lp::word_t Reload_value>
            using reload_value = typename block::arr_arr::template with_value<Reload_value>;
        };

        struct status {
            using update_int = typename block::sr_uif;
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
            return block::sr::template get_and<Bits...>();
        }

        template <typename ...Bits>
        static constexpr void clear_status() noexcept {
            block::sr::template set_nand<Bits...>();
        }
    };

    template <typename Tim_block>
    struct tim_general : tim_base<Tim_block> {
        using block = Tim_block;
        using channel1 = typename block::ccr1;
        using channel2 = typename block::ccr2;
        using channel3 = typename block::ccr3;
        using channel4 = typename block::ccr4;

        struct config : tim_base<Tim_block>::config_general {
            template <lp::word_t Reload_value>
            using reload_value = typename block::arr_arr_l::template with_value<Reload_value>;
        };

        struct channel_config {
            using ch1_output_enable = typename block::ccer_cc1e;
            using ch2_output_enable = typename block::ccer_cc2e;
            using ch3_output_enable = typename block::ccer_cc3e;
            using ch4_output_enable = typename block::ccer_cc4e;

            enum struct mode : lp::u32_t {
                output = 0b00,
                input_t1_t3 = 0b01,
                input_t2_t4 = 0b10,
                input_trc = 0b11
            };

            template <mode Mode>
            using ch1_mode = typename block::ccmr1_output_cc1s::
                template with_value<static_cast<lp::u32_t>(Mode)>;
            template <mode Mode>
            using ch2_mode = typename block::ccmr1_output_cc2s::
                template with_value<static_cast<lp::u32_t>(Mode)>;
            template <mode Mode>
            using ch3_mode = typename block::ccmr2_output_cc3s::
                template with_value<static_cast<lp::u32_t>(Mode)>;
            template <mode Mode>
            using ch4_mode = typename block::ccmr2_output_cc4s::
                template with_value<static_cast<lp::u32_t>(Mode)>;

            enum struct output_mode : lp::u32_t {
                frozen = 0b000,
                active = 0b001,
                inactive = 0b010,
                toggle = 0b011,
                force_inactive = 0b100,
                force_active = 0b101,
                pwm1 = 0b110,
                pwm2 = 0b111,
                opm1 = 0b1000,
                opm2 = 0b1001,
                combined_pwm1 = 0b1100,
                combined_pwm2 = 0b1101
            };

            template <output_mode Output_mode>
            using ch1_output_mode = typename block::ccmr1_output_oc1m::
                template with_value<static_cast<lp::u32_t>(Output_mode)>;
            template <output_mode Output_mode>
            using ch2_output_mode = typename block::ccmr1_output_oc2m::
                template with_value<static_cast<lp::u32_t>(Output_mode)>;
            template <output_mode Output_mode>
            using ch3_output_mode = typename block::ccmr2_output_oc3m::
                template with_value<static_cast<lp::u32_t>(Output_mode)>;
            template <output_mode Output_mode>
            using ch4_output_mode = typename block::ccmr2_output_oc3m::
                template with_value<static_cast<lp::u32_t>(Output_mode)>;

            template <lp::word_t Channel_value>
            using ch1_value = typename block::ccr1_ccr1_l::
                template with_value<Channel_value>;
            template <lp::word_t Channel_value>
            using ch2_value = typename block::ccr2_ccr2_l::
                template with_value<Channel_value>;
            template <lp::word_t Channel_value>
            using ch3_value = typename block::ccr3_ccr3_l::
                template with_value<Channel_value>;
            template <lp::word_t Channel_value>
            using ch4_value = typename block::ccr4_ccr4_l::
                template with_value<Channel_value>;
        };

        using channel_register_setup_list = lp::type_list<
            typename block::ccer,
            typename block::ccmr1_output,
            typename block::ccmr2_output,
            typename block::ccr1,
            typename block::ccr2,
            typename block::ccr3,
            typename block::ccr4
        >;

        template <typename ...Params>
        static constexpr void channel_setup() noexcept {
            lp::register_op_unpack<
                channel_register_setup_list,
                lp::repack_v<Params...>
            >::apply();
        }
    };
} // namespace hal

#endif // HAL_TIM_TYPE_HH
