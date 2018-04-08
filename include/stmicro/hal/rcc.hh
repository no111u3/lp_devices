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
 * Hardware abstraction layer for rcc
 * @file rcc.hh
 * @author Boris Vinogradov
 */

#include <io_register_operation_traits.hh>
#include <type_list.hh>
#include <type_traits.hh>

#include <hal/rcc_device.hh>

#ifndef HAL_RCC_HH
#define HAL_RCC_HH

namespace hal {
    struct rcc {
        using register_op_set_or_list = lp::type_list<
            ::rcc::ahb1enr::op_set_or,
            ::rcc::ahb2enr::op_set_or,
            ::rcc::apb1enr1::op_set_or,
            ::rcc::apb1enr2::op_set_or,
            ::rcc::apb2enr::op_set_or
        >;

        using register_op_set_nand_list = lp::type_list<
            ::rcc::ahb1enr::op_set_nand,
            ::rcc::ahb2enr::op_set_nand,
            ::rcc::apb1enr1::op_set_nand,
            ::rcc::apb1enr2::op_set_nand,
            ::rcc::apb2enr::op_set_nand
        >;

        template <typename ...DevBits>
        static void device_enable() noexcept {
            using dev_bits = lp::type_list<DevBits...>;
            lp::register_op_unpack<register_op_set_or_list, dev_bits>::apply();
        }

        template <typename ...DevBits>
        static void device_disable() noexcept {
            using dev_bits = lp::type_list<DevBits...>;
            lp::register_op_unpack<register_op_set_nand_list, dev_bits>::apply();
        }
    };
}

#endif // HAL_RCC_HH
