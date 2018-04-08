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
 * Hardware support for dbgmcu
 * @file dbgmcu.hh
 * @author Boris Vinogradov
 */

#include <associate_bit.hh>
#include <io_register.hh>
#include <types.hh>

#ifndef DBGMCU_HH
#define DBGMCU_HH

/* Debug support */
template <lp::addr_t base_address>
struct dbgmcu_t {
    /* MCU Device ID Code Register */
    using idcode = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* Device Identifier */
    using idcode_dev_id = lp::assoc_bit<idcode, 0, 16>;
    /* Revision Identifier */
    using idcode_rev_id = lp::assoc_bit<idcode, 16, 16>;


    /* Debug MCU Configuration           Register */
    using cr = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* Debug Sleep Mode */
    using cr_dbg_sleep = lp::assoc_bit<cr, 0>;
    /* Debug Stop Mode */
    using cr_dbg_stop = lp::assoc_bit<cr, 1>;
    /* Debug Standby Mode */
    using cr_dbg_standby = lp::assoc_bit<cr, 2>;
    /* Trace pin assignment               control */
    using cr_trace_ioen = lp::assoc_bit<cr, 5>;
    /* Trace pin assignment               control */
    using cr_trace_mode = lp::assoc_bit<cr, 6, 2>;


    /* APB Low Freeze Register 1 */
    using apb1_fzr1 = lp::io_register<lp::u32_t, base_address + 0x8>;
    /* Debug Timer 2 stopped when Core is               halted */
    using apb1_fzr1_dbg_timer2_stop = lp::assoc_bit<apb1_fzr1, 0>;
    /* TIM3 counter stopped when core is               halted */
    using apb1_fzr1_dbg_tim3_stop = lp::assoc_bit<apb1_fzr1, 1>;
    /* TIM4 counter stopped when core is               halted */
    using apb1_fzr1_dbg_tim4_stop = lp::assoc_bit<apb1_fzr1, 2>;
    /* TIM5 counter stopped when core is               halted */
    using apb1_fzr1_dbg_tim5_stop = lp::assoc_bit<apb1_fzr1, 3>;
    /* Debug Timer 6 stopped when Core is               halted */
    using apb1_fzr1_dbg_timer6_stop = lp::assoc_bit<apb1_fzr1, 4>;
    /* TIM7 counter stopped when core is               halted */
    using apb1_fzr1_dbg_tim7_stop = lp::assoc_bit<apb1_fzr1, 5>;
    /* Debug RTC stopped when Core is               halted */
    using apb1_fzr1_dbg_rtc_stop = lp::assoc_bit<apb1_fzr1, 10>;
    /* Debug Window Wachdog stopped when Core               is halted */
    using apb1_fzr1_dbg_wwdg_stop = lp::assoc_bit<apb1_fzr1, 11>;
    /* Debug Independent Wachdog stopped when               Core is halted */
    using apb1_fzr1_dbg_iwdg_stop = lp::assoc_bit<apb1_fzr1, 12>;
    /* I2C1 SMBUS timeout mode stopped when               core is halted */
    using apb1_fzr1_dbg_i2c1_stop = lp::assoc_bit<apb1_fzr1, 21>;
    /* I2C2 SMBUS timeout mode stopped when               core is halted */
    using apb1_fzr1_dbg_i2c2_stop = lp::assoc_bit<apb1_fzr1, 22>;
    /* I2C3 SMBUS timeout counter stopped when               core is halted */
    using apb1_fzr1_dbg_i2c3_stop = lp::assoc_bit<apb1_fzr1, 23>;
    /* bxCAN stopped when core is               halted */
    using apb1_fzr1_dbg_can_stop = lp::assoc_bit<apb1_fzr1, 25>;
    /* LPTIM1 counter stopped when core is               halted */
    using apb1_fzr1_dbg_lptimer_stop = lp::assoc_bit<apb1_fzr1, 31>;


    /* APB Low Freeze Register 2 */
    using apb1_fzr2 = lp::io_register<lp::u32_t, base_address + 0xc>;
    /* LPTIM2 counter stopped when core is               halted */
    using apb1_fzr2_dbg_lptim2_stop = lp::assoc_bit<apb1_fzr2, 5>;


    /* APB High Freeze Register */
    using apb2_fzr = lp::io_register<lp::u32_t, base_address + 0x10>;
    /* TIM1 counter stopped when core is               halted */
    using apb2_fzr_dbg_tim1_stop = lp::assoc_bit<apb2_fzr, 11>;
    /* TIM8 counter stopped when core is               halted */
    using apb2_fzr_dbg_tim8_stop = lp::assoc_bit<apb2_fzr, 13>;
    /* TIM15 counter stopped when core is               halted */
    using apb2_fzr_dbg_tim15_stop = lp::assoc_bit<apb2_fzr, 16>;
    /* TIM16 counter stopped when core is               halted */
    using apb2_fzr_dbg_tim16_stop = lp::assoc_bit<apb2_fzr, 17>;
    /* TIM17 counter stopped when core is               halted */
    using apb2_fzr_dbg_tim17_stop = lp::assoc_bit<apb2_fzr, 18>;


};

using dbgmcu = dbgmcu_t<0xe0042000>;

#endif // DBGMCU_HH
