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
 * Hardware abstraction layer for stk
 * @file stk.hh
 * @author Boris Vinogradov
 */

#include <stk.hh>

#ifndef HAL_STK_HH
#define HAL_STK_HH

namespace hal {
    struct stk {
        template <lp::u32_t ticks>
        static constexpr void config() noexcept {
            using timer = ::stk;
            static_assert(ticks <= timer::load_reload::mask<lp::u32_t>::value + 1, "Can't set value greater than 2^24");

            timer::load::set<timer::load_reload::with_value<ticks - 1>>();
            timer::val::set<timer::val_current::with_value<0>>();

            timer::ctrl::set_or<timer::ctrl_enable, timer::ctrl_tickint, timer::ctrl_clksource>();
        }
    };
}

#endif // HAL_STK_HH
 
