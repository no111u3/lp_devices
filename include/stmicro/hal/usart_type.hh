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
 * Hardware abstraction layer for usart
 * type definitions for usart
 * @file usart_type.hh
 * @author Boris Vinogradov
 */

#include <bit.hh>
#include <io_register.hh>
#include <io_register_operation_traits.hh>
#include <types.hh>
#include <type_list.hh>
#include <type_list_traits.hh>

#include <usart.hh>

#ifndef HAL_USART_TYPE_HH
#define HAL_USART_TYPE_HH

namespace hal {
    template <typename Usart_block>
    struct usart {
        using block = Usart_block;
        using input = typename block::rdr;
        using output = typename block::tdr;

        struct config {
            using none = typename block::cr1_ue;
            using tx_only = lp::type_list<none, typename block::cr1_te>;
            using rx_only = lp::type_list<none, typename block::cr1_re>;
            using txrx = lp::type_list<none,
                typename block::cr1_te,
                typename block::cr1_re>;
            template <lp::word_t Periph_clock, lp::word_t Baudrate>
            using baudrate = typename block::brr_brr::template with_value<Periph_clock / Baudrate>;
        };

        using register_setup_list = lp::type_list<
            typename block::brr,
            typename block::cr1::op_set_or
        >;

        template <typename ...Params>
        static constexpr void setup() noexcept {
            lp::register_op_unpack<register_setup_list, lp::repack_v<Params...>>::apply();
        }

        static constexpr void disable() noexcept {
            block::cr1::template set_nand<typename block::cr1_ue>();
        }

        static constexpr void send(lp::u32_t word) noexcept {
            while (!block::isr::template get_and<typename block::isr_txe>());

            output::get() = word;
        }

        static constexpr lp::u32_t recv() noexcept {
            while (!block::isr::template get_and<typename block::isr_rxne>());

            return input::get();
        }
    };
}

#endif // HAL_USART_TYPE_HH
