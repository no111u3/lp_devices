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
 * Hardware abstraction layer for gpio
 * type definitions for gpio version 2 (new STM32 devices)
 * @file gpio_type_v2.hh
 * @author Boris Vinogradov
 */

#include <bit.hh>
#include <io_register.hh>
#include <types.hh>

#include <gpio.hh>

#include <hal/device.hh>

#ifndef HAL_GPIO_TYPE_V2_HH
#define HAL_GPIO_TYPE_V2_HH

namespace hal {
    struct pins {
        enum struct mode : lp::u32_t {
            input = 0b00,
            output = 0b01,
            alt_func = 0b10,
            analog = 0b11
        };

        enum struct speed : lp::u32_t {
            very_low = 0b00,
            low = 0b01,
            medium = 0b10,
            high = 0b11
        };

        enum struct pull : lp::u32_t {
            none = 0b00,
            up = 0b01,
            dow = 0b10,
            _reserved = 0b11
        };

        enum struct alt : lp::u32_t {
            af0 = 0,
            af1 = 1,
            af2 = 2,
            af3 = 3,
            af4 = 4,
            af5 = 5,
            af6 = 6,
            af7 = 7,
            af8 = 8,
            af9 = 9,
            af10 = 10,
            af11 = 11,
            af12 = 12,
            af13 = 13,
            af14 = 14,
            af15 = 15
        };

        using p0 = lp::bit<0>;
        using p1 = lp::bit<1>;
        using p2 = lp::bit<2>;
        using p3 = lp::bit<3>;
        using p4 = lp::bit<4>;
        using p5 = lp::bit<5>;
        using p6 = lp::bit<6>;
        using p7 = lp::bit<7>;
        using p8 = lp::bit<8>;
        using p9 = lp::bit<9>;
        using p10 = lp::bit<10>;
        using p11 = lp::bit<11>;
        using p12 = lp::bit<12>;
        using p13 = lp::bit<13>;
        using p14 = lp::bit<14>;
        using p15 = lp::bit<15>;
    };

    template <typename Gpio_block>
    struct gpio {
        using block = Gpio_block;
        using output = typename block::odr;
        using input = typename block::idr;

        template <pins::mode mode, typename ...Pins>
        static constexpr void set_mode() noexcept {
            set_value<typename block::moder, static_cast<lp::u32_t>(mode), 2, Pins...>();
        }

        template <typename ...Pins>
        static constexpr void set_open_drain() noexcept {
            block::otyper::template set_or<Pins...>();
        }

        template <typename ...Pins>
        static constexpr void set_push_pull() noexcept {
            block::otyper::template set_nand<Pins...>();
        }

        template <pins::speed speed, typename ...Pins>
        static constexpr void set_speed() noexcept {
            set_value<typename block::ospeedr, static_cast<lp::u32_t>(speed), 2, Pins...>();
        }

        template <pins::pull pull, typename ...Pins>
        static void set_pull() noexcept {
            set_value<typename block::pupdr, static_cast<lp::u32_t>(pull), 2, Pins...>();
        }

        template <typename ...Pins>
        static constexpr auto get_value() noexcept {
            return input::template get_and<Pins...>();
        }

        template <typename ...Pins>
        static constexpr void set_value() noexcept {
            block::bsrr::template set<Pins...>();
        }

        template <typename ...Pins>
        static constexpr void reset_value() noexcept {
            block::bsrr::template set<16, Pins...>();
        }

        template <typename ...Pins>
        static constexpr void lock() noexcept {
            block::lckr::template set_or<Pins...>();
        }

        template <typename ...Pins>
        static constexpr void unlock() noexcept {
            block::lckr::template set_nand<Pins...>();
        }

        template <pins::alt alt_func, typename ...Pins>
        static constexpr void set_alt_func() noexcept {
            set_value<afr64, static_cast<lp::u32_t>(alt_func), 4, Pins...>();
        }

        template <device::alt alt_func, typename ...Pins>
        static constexpr void set_alt_func() noexcept {
            set_value<afr64, static_cast<lp::u32_t>(alt_func), 4, Pins...>();
        }

        template <typename ...Pins>
        static constexpr void reset() noexcept {
            block::brr::template set_or<Pins...>();
        }

    private:
        using afr64 = lp::io_register<lp::u64_t, block::afrl::address>;

        template <typename GpioRegister, lp::u32_t value, lp::u32_t shift, typename ...Pins>
        static constexpr void set_value() noexcept {
            GpioRegister::template set_nand<
                typename lp::bit<
                    Pins::position * shift, shift
                >...
            >();
            GpioRegister::template set_or<
                typename lp::bit<
                    Pins::position * shift, shift
                >::template with_value<value>...
            >();
        }
    };
}

#endif // HAL_GPIO_TYPE_V2_HH
