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
 * Hardware abstraction layer for device tim
 * @file tim_device.hh
 * @author Boris Vinogradov
 */

#include <tim.hh>
#include <hal/tim_type.hh>

#ifndef HAL_TIM_DEVICE_HH
#define HAL_TIM_DEVICE_HH

namespace hal {
    namespace tim_device {
        using tim2 = tim_general<tim2>;
        using tim3 = tim_general<tim3>;
        using tim4 = tim_general<tim4>;
        using tim5 = tim_general<tim5>;
        using tim15 = tim_general<tim15>;
        using tim16 = tim_general<tim16>;
        using tim17 = tim_general<tim17>;
        using tim1 = tim_general<tim1>;
        using tim8 = tim_general<tim8>;
        using tim6 = tim_base<tim6>;
        using tim7 = tim_base<tim7>;
    }
}

#endif // HAL_TIM_DEVICE_HH
