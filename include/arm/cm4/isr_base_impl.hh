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
 * Hardware support for core interrupts - implementation
 * @file isr_base_impl.hh
 * @author Boris Vinogradov
 */

#ifndef ISR_BASE_IMPL_HH
#define ISR_BASE_IMPL_HH

extern "C" {
    namespace isr {
        void default_handler(); // default handler for undefined handlers

        void reset() __attribute__ ((weak, alias ("default_handler")));
        void NMI() __attribute__ ((weak, alias ("default_handler")));
        void hard_fault() __attribute__ ((weak, alias ("default_handler")));
        void mem_manage() __attribute__ ((weak, alias ("default_handler")));
        void bus_fault() __attribute__ ((weak, alias ("default_handler")));
        void usage_fault() __attribute__ ((weak, alias ("default_handler")));
        void SVC() __attribute__ ((weak, alias ("default_handler")));
        void debug_mon() __attribute__ ((weak, alias ("default_handler")));
        void pend_SV() __attribute__ ((weak, alias ("default_handler")));
        void sys_tick_timer() __attribute__ ((weak, alias ("default_handler")));
    }
}

#endif // ISR_BASE_IMPL_HH
