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
 * Hardware abstraction layer for device gpio
 * @file gpio_device.hh
 * @author Boris Vinogradov
 */

#include <gpio.hh>
#include <hal/gpio_type_v2.hh>

#ifndef HAL_GPIO_DEVICE_HH
#define HAL_GPIO_DEVICE_HH

namespace hal {
    namespace gpio_device {
        using gpioa = gpio<gpioa>;
        using gpiob = gpio<gpiob>;
        using gpioc = gpio<gpioc>;
        using gpiod = gpio<gpiod>;
        using gpioe = gpio<gpioe>;
        using gpiof = gpio<gpiof>;
        using gpiog = gpio<gpiog>;
        using gpioh = gpio<gpioh>;
        using gpioi = gpio<gpioi>;
    }
}

#endif // HAL_GPIO_DEVICE_HH
