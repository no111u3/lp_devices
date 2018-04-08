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
 * Hardware support core features
 * @file cpu.hh
 * @author Boris Vinogradov
 */

#ifndef CPU_HH
#define CPU_HH

/// Cortex-M4 implementation of cpu type
struct cpu {
    static inline void __attribute__((always_inline)) wait_interrupt() noexcept {
        __asm__ volatile ("wfi");
    }

    static inline void __attribute__((always_inline)) wait_event() noexcept {
        __asm__ volatile ("wfe");
    }
};

#endif // CPU_HH
