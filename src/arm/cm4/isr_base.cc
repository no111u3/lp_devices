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
 * Hardware support for core interrupts
 * @file isr_base.cc
 * @author Boris Vinogradov
 */

#include "isr_base.hh"
#include "isr_base_impl.hh"

__attribute__((noreturn)) void isr::default_handler() {
    // nothing in prototype
    while (true);
}

__attribute__((section(".vectors"))) extern const isr::vectors vectors_table = {
    &_estack,
    isr::reset,
    isr::NMI,
    isr::hard_fault,
    isr::mem_manage,
    isr::bus_fault,
    isr::usage_fault,
    {0, 0, 0, 0},
    isr::SVC,
    isr::debug_mon,
    {0},
    isr::pend_SV,
    isr::sys_tick_timer
}; 
