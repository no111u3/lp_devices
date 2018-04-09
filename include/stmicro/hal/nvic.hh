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
 * Hardware abstraction layer for nvic
 * @file nvic.hh
 * @author Boris Vinogradov
 */

#include <hal/isr_irq.hh>
#include <hal/nvic_device.hh>

#ifndef HAL_NVIC_HH
#define HAL_NVIC_HH

namespace hal {
    struct nvic {
        template <irq_dev_num_t irq_n>
        static constexpr void enable_irq() noexcept {
            nvic_device::iser::value_type<
                (static_cast<lp::word_t>(irq_n) >> 5)
            >::template set<lp::bit<(static_cast<lp::word_t>(irq_n) & 0x1f)>>();
        }
    };
}

#endif // HAL_NVIC_HH
