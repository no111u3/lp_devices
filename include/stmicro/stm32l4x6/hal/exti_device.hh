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
 * Hardware abstraction layer for device exti
 * @file exti_device.hh
 * @author Boris Vinogradov
 */

#include <exti.hh>
#include <type_list.hh>

#ifndef HAL_EXTI_DEVICE_HH
#define HAL_EXTI_DEVICE_HH

namespace hal {
    namespace exti_device {

        /* Interrupt mask registers */
        using imr = lp::type_list<exti::imr1, exti::imr2>;

        /* Event mask registers */
        using emr = lp::type_list<exti::emr1, exti::emr2>;

        /* Rising Trigger selection
          registers */
        using rtsr = lp::type_list<exti::rtsr1, exti::rtsr2>;

        /* Falling Trigger selection
          registers */
        using ftsr = lp::type_list<exti::ftsr1, exti::ftsr2>;

        /* Software interrupt event
          registers */
        using swier = lp::type_list<exti::swier1, exti::swier2>;

        /* Pending registers */
        using pr = lp::type_list<exti::pr1, exti::pr2>;
    }
}

#endif // HAL_EXTI_DEVICE_HH
