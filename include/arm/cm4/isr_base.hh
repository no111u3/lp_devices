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
 * Hardware support core interrupts
 * @file isr_base.hh
 * @author Boris Vinogradov
 */

#ifndef ISR_BASE_HH
#define ISR_BASE_HH

#include <types.hh>
extern lp::u32_t _estack; // linker defined variable - is a stack size

extern "C" {
    namespace isr {
        struct vectors // table of pointer to interrupt vectors - arm cortex core interrupts
        {
            lp::u32_t *estack; /*! stack begin */
            void (*reset)           (); /*!#0 cortex reset interrupt begin code of this */
            void (*NMI)             (); /*!#1 cortex non maskable interrupt */
            void (*hard_fault)      (); /*!#2 cortex hardware fault interrupt */
            void (*mem_manage)      (); /*!#3 cortex memory management interrupt */
            void (*bus_fault)       (); /*!#4 cortex bus fault interrupt */
            void (*usage_fault)     (); /*!#5 cortex usage fault interrupt */
            void (*__unused0[4])    (); /*!#6-9 reserved */
            void (*SVC)             (); /*!#10 cortex system service interrupt */
            void (*debug_mon)       (); /*!#11 cortex debug monitor interrupt */
            void (*__unused1[1])    (); /*!#12 reserved */
            void (*pend_SV)         (); /*!#13 cortex penable request for system service interrupt */
            void (*sys_tick_timer)  (); /*!#14 cortex system tick timer interrupt */
        };

        void reset();
        void NMI();
        void hard_fault();
        void mem_manage();
        void bus_fault();
        void usage_fault();
        void SVC();
        void debug_mon();
        void pend_SV();
        void sys_tick_timer();
    }
}

#endif // ISR_BASE_HH
