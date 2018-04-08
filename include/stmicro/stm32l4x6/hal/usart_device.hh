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
 * Hardware abstraction layer for device usart
 * @file usart_device.hh
 * @author Boris Vinogradov
 */

#include <usart.hh>
#include <hal/usart_type.hh>

#ifndef HAL_USART_DEVICE_HH
#define HAL_USART_DEVICE_HH

namespace hal {
    namespace usart_device {
        using usart1 = usart<usart1>;
        using usart2 = usart<usart2>;
        using usart3 = usart<usart3>;
        using uart4 = usart<uart4>;
        using uart5 = usart<uart5>;
        using lpuart1 = usart<lpuart1>;
    }
}

#endif // HAL_USART_DEVICE_HH
