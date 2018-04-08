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
 * Hardware support for exti
 * @file exti.hh
 * @author Boris Vinogradov
 */

#include <associate_bit.hh>
#include <io_register.hh>
#include <types.hh>

#ifndef EXTI_HH
#define EXTI_HH

/* External interrupt/event
      controller */
template <lp::addr_t base_address>
struct exti_t {
    /* Interrupt mask register */
    using imr1 = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* Interrupt Mask on line 0 */
    using imr1_mr0 = lp::assoc_bit<imr1, 0>;
    /* Interrupt Mask on line 1 */
    using imr1_mr1 = lp::assoc_bit<imr1, 1>;
    /* Interrupt Mask on line 2 */
    using imr1_mr2 = lp::assoc_bit<imr1, 2>;
    /* Interrupt Mask on line 3 */
    using imr1_mr3 = lp::assoc_bit<imr1, 3>;
    /* Interrupt Mask on line 4 */
    using imr1_mr4 = lp::assoc_bit<imr1, 4>;
    /* Interrupt Mask on line 5 */
    using imr1_mr5 = lp::assoc_bit<imr1, 5>;
    /* Interrupt Mask on line 6 */
    using imr1_mr6 = lp::assoc_bit<imr1, 6>;
    /* Interrupt Mask on line 7 */
    using imr1_mr7 = lp::assoc_bit<imr1, 7>;
    /* Interrupt Mask on line 8 */
    using imr1_mr8 = lp::assoc_bit<imr1, 8>;
    /* Interrupt Mask on line 9 */
    using imr1_mr9 = lp::assoc_bit<imr1, 9>;
    /* Interrupt Mask on line 10 */
    using imr1_mr10 = lp::assoc_bit<imr1, 10>;
    /* Interrupt Mask on line 11 */
    using imr1_mr11 = lp::assoc_bit<imr1, 11>;
    /* Interrupt Mask on line 12 */
    using imr1_mr12 = lp::assoc_bit<imr1, 12>;
    /* Interrupt Mask on line 13 */
    using imr1_mr13 = lp::assoc_bit<imr1, 13>;
    /* Interrupt Mask on line 14 */
    using imr1_mr14 = lp::assoc_bit<imr1, 14>;
    /* Interrupt Mask on line 15 */
    using imr1_mr15 = lp::assoc_bit<imr1, 15>;
    /* Interrupt Mask on line 16 */
    using imr1_mr16 = lp::assoc_bit<imr1, 16>;
    /* Interrupt Mask on line 17 */
    using imr1_mr17 = lp::assoc_bit<imr1, 17>;
    /* Interrupt Mask on line 18 */
    using imr1_mr18 = lp::assoc_bit<imr1, 18>;
    /* Interrupt Mask on line 19 */
    using imr1_mr19 = lp::assoc_bit<imr1, 19>;
    /* Interrupt Mask on line 20 */
    using imr1_mr20 = lp::assoc_bit<imr1, 20>;
    /* Interrupt Mask on line 21 */
    using imr1_mr21 = lp::assoc_bit<imr1, 21>;
    /* Interrupt Mask on line 22 */
    using imr1_mr22 = lp::assoc_bit<imr1, 22>;
    /* Interrupt Mask on line 23 */
    using imr1_mr23 = lp::assoc_bit<imr1, 23>;
    /* Interrupt Mask on line 24 */
    using imr1_mr24 = lp::assoc_bit<imr1, 24>;
    /* Interrupt Mask on line 25 */
    using imr1_mr25 = lp::assoc_bit<imr1, 25>;
    /* Interrupt Mask on line 26 */
    using imr1_mr26 = lp::assoc_bit<imr1, 26>;
    /* Interrupt Mask on line 27 */
    using imr1_mr27 = lp::assoc_bit<imr1, 27>;
    /* Interrupt Mask on line 28 */
    using imr1_mr28 = lp::assoc_bit<imr1, 28>;
    /* Interrupt Mask on line 29 */
    using imr1_mr29 = lp::assoc_bit<imr1, 29>;
    /* Interrupt Mask on line 30 */
    using imr1_mr30 = lp::assoc_bit<imr1, 30>;
    /* Interrupt Mask on line 31 */
    using imr1_mr31 = lp::assoc_bit<imr1, 31>;


    /* Event mask register */
    using emr1 = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* Event Mask on line 0 */
    using emr1_mr0 = lp::assoc_bit<emr1, 0>;
    /* Event Mask on line 1 */
    using emr1_mr1 = lp::assoc_bit<emr1, 1>;
    /* Event Mask on line 2 */
    using emr1_mr2 = lp::assoc_bit<emr1, 2>;
    /* Event Mask on line 3 */
    using emr1_mr3 = lp::assoc_bit<emr1, 3>;
    /* Event Mask on line 4 */
    using emr1_mr4 = lp::assoc_bit<emr1, 4>;
    /* Event Mask on line 5 */
    using emr1_mr5 = lp::assoc_bit<emr1, 5>;
    /* Event Mask on line 6 */
    using emr1_mr6 = lp::assoc_bit<emr1, 6>;
    /* Event Mask on line 7 */
    using emr1_mr7 = lp::assoc_bit<emr1, 7>;
    /* Event Mask on line 8 */
    using emr1_mr8 = lp::assoc_bit<emr1, 8>;
    /* Event Mask on line 9 */
    using emr1_mr9 = lp::assoc_bit<emr1, 9>;
    /* Event Mask on line 10 */
    using emr1_mr10 = lp::assoc_bit<emr1, 10>;
    /* Event Mask on line 11 */
    using emr1_mr11 = lp::assoc_bit<emr1, 11>;
    /* Event Mask on line 12 */
    using emr1_mr12 = lp::assoc_bit<emr1, 12>;
    /* Event Mask on line 13 */
    using emr1_mr13 = lp::assoc_bit<emr1, 13>;
    /* Event Mask on line 14 */
    using emr1_mr14 = lp::assoc_bit<emr1, 14>;
    /* Event Mask on line 15 */
    using emr1_mr15 = lp::assoc_bit<emr1, 15>;
    /* Event Mask on line 16 */
    using emr1_mr16 = lp::assoc_bit<emr1, 16>;
    /* Event Mask on line 17 */
    using emr1_mr17 = lp::assoc_bit<emr1, 17>;
    /* Event Mask on line 18 */
    using emr1_mr18 = lp::assoc_bit<emr1, 18>;
    /* Event Mask on line 19 */
    using emr1_mr19 = lp::assoc_bit<emr1, 19>;
    /* Event Mask on line 20 */
    using emr1_mr20 = lp::assoc_bit<emr1, 20>;
    /* Event Mask on line 21 */
    using emr1_mr21 = lp::assoc_bit<emr1, 21>;
    /* Event Mask on line 22 */
    using emr1_mr22 = lp::assoc_bit<emr1, 22>;
    /* Event Mask on line 23 */
    using emr1_mr23 = lp::assoc_bit<emr1, 23>;
    /* Event Mask on line 24 */
    using emr1_mr24 = lp::assoc_bit<emr1, 24>;
    /* Event Mask on line 25 */
    using emr1_mr25 = lp::assoc_bit<emr1, 25>;
    /* Event Mask on line 26 */
    using emr1_mr26 = lp::assoc_bit<emr1, 26>;
    /* Event Mask on line 27 */
    using emr1_mr27 = lp::assoc_bit<emr1, 27>;
    /* Event Mask on line 28 */
    using emr1_mr28 = lp::assoc_bit<emr1, 28>;
    /* Event Mask on line 29 */
    using emr1_mr29 = lp::assoc_bit<emr1, 29>;
    /* Event Mask on line 30 */
    using emr1_mr30 = lp::assoc_bit<emr1, 30>;
    /* Event Mask on line 31 */
    using emr1_mr31 = lp::assoc_bit<emr1, 31>;


    /* Rising Trigger selection           register */
    using rtsr1 = lp::io_register<lp::u32_t, base_address + 0x8>;
    /* Rising trigger event configuration of               line 0 */
    using rtsr1_tr0 = lp::assoc_bit<rtsr1, 0>;
    /* Rising trigger event configuration of               line 1 */
    using rtsr1_tr1 = lp::assoc_bit<rtsr1, 1>;
    /* Rising trigger event configuration of               line 2 */
    using rtsr1_tr2 = lp::assoc_bit<rtsr1, 2>;
    /* Rising trigger event configuration of               line 3 */
    using rtsr1_tr3 = lp::assoc_bit<rtsr1, 3>;
    /* Rising trigger event configuration of               line 4 */
    using rtsr1_tr4 = lp::assoc_bit<rtsr1, 4>;
    /* Rising trigger event configuration of               line 5 */
    using rtsr1_tr5 = lp::assoc_bit<rtsr1, 5>;
    /* Rising trigger event configuration of               line 6 */
    using rtsr1_tr6 = lp::assoc_bit<rtsr1, 6>;
    /* Rising trigger event configuration of               line 7 */
    using rtsr1_tr7 = lp::assoc_bit<rtsr1, 7>;
    /* Rising trigger event configuration of               line 8 */
    using rtsr1_tr8 = lp::assoc_bit<rtsr1, 8>;
    /* Rising trigger event configuration of               line 9 */
    using rtsr1_tr9 = lp::assoc_bit<rtsr1, 9>;
    /* Rising trigger event configuration of               line 10 */
    using rtsr1_tr10 = lp::assoc_bit<rtsr1, 10>;
    /* Rising trigger event configuration of               line 11 */
    using rtsr1_tr11 = lp::assoc_bit<rtsr1, 11>;
    /* Rising trigger event configuration of               line 12 */
    using rtsr1_tr12 = lp::assoc_bit<rtsr1, 12>;
    /* Rising trigger event configuration of               line 13 */
    using rtsr1_tr13 = lp::assoc_bit<rtsr1, 13>;
    /* Rising trigger event configuration of               line 14 */
    using rtsr1_tr14 = lp::assoc_bit<rtsr1, 14>;
    /* Rising trigger event configuration of               line 15 */
    using rtsr1_tr15 = lp::assoc_bit<rtsr1, 15>;
    /* Rising trigger event configuration of               line 16 */
    using rtsr1_tr16 = lp::assoc_bit<rtsr1, 16>;
    /* Rising trigger event configuration of               line 18 */
    using rtsr1_tr18 = lp::assoc_bit<rtsr1, 18>;
    /* Rising trigger event configuration of               line 19 */
    using rtsr1_tr19 = lp::assoc_bit<rtsr1, 19>;
    /* Rising trigger event configuration of               line 20 */
    using rtsr1_tr20 = lp::assoc_bit<rtsr1, 20>;
    /* Rising trigger event configuration of               line 21 */
    using rtsr1_tr21 = lp::assoc_bit<rtsr1, 21>;
    /* Rising trigger event configuration of               line 22 */
    using rtsr1_tr22 = lp::assoc_bit<rtsr1, 22>;


    /* Falling Trigger selection           register */
    using ftsr1 = lp::io_register<lp::u32_t, base_address + 0xc>;
    /* Falling trigger event configuration of               line 0 */
    using ftsr1_tr0 = lp::assoc_bit<ftsr1, 0>;
    /* Falling trigger event configuration of               line 1 */
    using ftsr1_tr1 = lp::assoc_bit<ftsr1, 1>;
    /* Falling trigger event configuration of               line 2 */
    using ftsr1_tr2 = lp::assoc_bit<ftsr1, 2>;
    /* Falling trigger event configuration of               line 3 */
    using ftsr1_tr3 = lp::assoc_bit<ftsr1, 3>;
    /* Falling trigger event configuration of               line 4 */
    using ftsr1_tr4 = lp::assoc_bit<ftsr1, 4>;
    /* Falling trigger event configuration of               line 5 */
    using ftsr1_tr5 = lp::assoc_bit<ftsr1, 5>;
    /* Falling trigger event configuration of               line 6 */
    using ftsr1_tr6 = lp::assoc_bit<ftsr1, 6>;
    /* Falling trigger event configuration of               line 7 */
    using ftsr1_tr7 = lp::assoc_bit<ftsr1, 7>;
    /* Falling trigger event configuration of               line 8 */
    using ftsr1_tr8 = lp::assoc_bit<ftsr1, 8>;
    /* Falling trigger event configuration of               line 9 */
    using ftsr1_tr9 = lp::assoc_bit<ftsr1, 9>;
    /* Falling trigger event configuration of               line 10 */
    using ftsr1_tr10 = lp::assoc_bit<ftsr1, 10>;
    /* Falling trigger event configuration of               line 11 */
    using ftsr1_tr11 = lp::assoc_bit<ftsr1, 11>;
    /* Falling trigger event configuration of               line 12 */
    using ftsr1_tr12 = lp::assoc_bit<ftsr1, 12>;
    /* Falling trigger event configuration of               line 13 */
    using ftsr1_tr13 = lp::assoc_bit<ftsr1, 13>;
    /* Falling trigger event configuration of               line 14 */
    using ftsr1_tr14 = lp::assoc_bit<ftsr1, 14>;
    /* Falling trigger event configuration of               line 15 */
    using ftsr1_tr15 = lp::assoc_bit<ftsr1, 15>;
    /* Falling trigger event configuration of               line 16 */
    using ftsr1_tr16 = lp::assoc_bit<ftsr1, 16>;
    /* Falling trigger event configuration of               line 18 */
    using ftsr1_tr18 = lp::assoc_bit<ftsr1, 18>;
    /* Falling trigger event configuration of               line 19 */
    using ftsr1_tr19 = lp::assoc_bit<ftsr1, 19>;
    /* Falling trigger event configuration of               line 20 */
    using ftsr1_tr20 = lp::assoc_bit<ftsr1, 20>;
    /* Falling trigger event configuration of               line 21 */
    using ftsr1_tr21 = lp::assoc_bit<ftsr1, 21>;
    /* Falling trigger event configuration of               line 22 */
    using ftsr1_tr22 = lp::assoc_bit<ftsr1, 22>;


    /* Software interrupt event           register */
    using swier1 = lp::io_register<lp::u32_t, base_address + 0x10>;
    /* Software Interrupt on line               0 */
    using swier1_swier0 = lp::assoc_bit<swier1, 0>;
    /* Software Interrupt on line               1 */
    using swier1_swier1 = lp::assoc_bit<swier1, 1>;
    /* Software Interrupt on line               2 */
    using swier1_swier2 = lp::assoc_bit<swier1, 2>;
    /* Software Interrupt on line               3 */
    using swier1_swier3 = lp::assoc_bit<swier1, 3>;
    /* Software Interrupt on line               4 */
    using swier1_swier4 = lp::assoc_bit<swier1, 4>;
    /* Software Interrupt on line               5 */
    using swier1_swier5 = lp::assoc_bit<swier1, 5>;
    /* Software Interrupt on line               6 */
    using swier1_swier6 = lp::assoc_bit<swier1, 6>;
    /* Software Interrupt on line               7 */
    using swier1_swier7 = lp::assoc_bit<swier1, 7>;
    /* Software Interrupt on line               8 */
    using swier1_swier8 = lp::assoc_bit<swier1, 8>;
    /* Software Interrupt on line               9 */
    using swier1_swier9 = lp::assoc_bit<swier1, 9>;
    /* Software Interrupt on line               10 */
    using swier1_swier10 = lp::assoc_bit<swier1, 10>;
    /* Software Interrupt on line               11 */
    using swier1_swier11 = lp::assoc_bit<swier1, 11>;
    /* Software Interrupt on line               12 */
    using swier1_swier12 = lp::assoc_bit<swier1, 12>;
    /* Software Interrupt on line               13 */
    using swier1_swier13 = lp::assoc_bit<swier1, 13>;
    /* Software Interrupt on line               14 */
    using swier1_swier14 = lp::assoc_bit<swier1, 14>;
    /* Software Interrupt on line               15 */
    using swier1_swier15 = lp::assoc_bit<swier1, 15>;
    /* Software Interrupt on line               16 */
    using swier1_swier16 = lp::assoc_bit<swier1, 16>;
    /* Software Interrupt on line               18 */
    using swier1_swier18 = lp::assoc_bit<swier1, 18>;
    /* Software Interrupt on line               19 */
    using swier1_swier19 = lp::assoc_bit<swier1, 19>;
    /* Software Interrupt on line               20 */
    using swier1_swier20 = lp::assoc_bit<swier1, 20>;
    /* Software Interrupt on line               21 */
    using swier1_swier21 = lp::assoc_bit<swier1, 21>;
    /* Software Interrupt on line               22 */
    using swier1_swier22 = lp::assoc_bit<swier1, 22>;


    /* Pending register */
    using pr1 = lp::io_register<lp::u32_t, base_address + 0x14>;
    /* Pending bit 0 */
    using pr1_pr0 = lp::assoc_bit<pr1, 0>;
    /* Pending bit 1 */
    using pr1_pr1 = lp::assoc_bit<pr1, 1>;
    /* Pending bit 2 */
    using pr1_pr2 = lp::assoc_bit<pr1, 2>;
    /* Pending bit 3 */
    using pr1_pr3 = lp::assoc_bit<pr1, 3>;
    /* Pending bit 4 */
    using pr1_pr4 = lp::assoc_bit<pr1, 4>;
    /* Pending bit 5 */
    using pr1_pr5 = lp::assoc_bit<pr1, 5>;
    /* Pending bit 6 */
    using pr1_pr6 = lp::assoc_bit<pr1, 6>;
    /* Pending bit 7 */
    using pr1_pr7 = lp::assoc_bit<pr1, 7>;
    /* Pending bit 8 */
    using pr1_pr8 = lp::assoc_bit<pr1, 8>;
    /* Pending bit 9 */
    using pr1_pr9 = lp::assoc_bit<pr1, 9>;
    /* Pending bit 10 */
    using pr1_pr10 = lp::assoc_bit<pr1, 10>;
    /* Pending bit 11 */
    using pr1_pr11 = lp::assoc_bit<pr1, 11>;
    /* Pending bit 12 */
    using pr1_pr12 = lp::assoc_bit<pr1, 12>;
    /* Pending bit 13 */
    using pr1_pr13 = lp::assoc_bit<pr1, 13>;
    /* Pending bit 14 */
    using pr1_pr14 = lp::assoc_bit<pr1, 14>;
    /* Pending bit 15 */
    using pr1_pr15 = lp::assoc_bit<pr1, 15>;
    /* Pending bit 16 */
    using pr1_pr16 = lp::assoc_bit<pr1, 16>;
    /* Pending bit 18 */
    using pr1_pr18 = lp::assoc_bit<pr1, 18>;
    /* Pending bit 19 */
    using pr1_pr19 = lp::assoc_bit<pr1, 19>;
    /* Pending bit 20 */
    using pr1_pr20 = lp::assoc_bit<pr1, 20>;
    /* Pending bit 21 */
    using pr1_pr21 = lp::assoc_bit<pr1, 21>;
    /* Pending bit 22 */
    using pr1_pr22 = lp::assoc_bit<pr1, 22>;


    /* Interrupt mask register */
    using imr2 = lp::io_register<lp::u32_t, base_address + 0x20>;
    /* Interrupt Mask on external/internal line               32 */
    using imr2_mr32 = lp::assoc_bit<imr2, 0>;
    /* Interrupt Mask on external/internal line               33 */
    using imr2_mr33 = lp::assoc_bit<imr2, 1>;
    /* Interrupt Mask on external/internal line               34 */
    using imr2_mr34 = lp::assoc_bit<imr2, 2>;
    /* Interrupt Mask on external/internal line               35 */
    using imr2_mr35 = lp::assoc_bit<imr2, 3>;
    /* Interrupt Mask on external/internal line               36 */
    using imr2_mr36 = lp::assoc_bit<imr2, 4>;
    /* Interrupt Mask on external/internal line               37 */
    using imr2_mr37 = lp::assoc_bit<imr2, 5>;
    /* Interrupt Mask on external/internal line               38 */
    using imr2_mr38 = lp::assoc_bit<imr2, 6>;
    /* Interrupt Mask on external/internal line               39 */
    using imr2_mr39 = lp::assoc_bit<imr2, 7>;


    /* Event mask register */
    using emr2 = lp::io_register<lp::u32_t, base_address + 0x24>;
    /* Event mask on external/internal line               32 */
    using emr2_mr32 = lp::assoc_bit<emr2, 0>;
    /* Event mask on external/internal line               33 */
    using emr2_mr33 = lp::assoc_bit<emr2, 1>;
    /* Event mask on external/internal line               34 */
    using emr2_mr34 = lp::assoc_bit<emr2, 2>;
    /* Event mask on external/internal line               35 */
    using emr2_mr35 = lp::assoc_bit<emr2, 3>;
    /* Event mask on external/internal line               36 */
    using emr2_mr36 = lp::assoc_bit<emr2, 4>;
    /* Event mask on external/internal line               37 */
    using emr2_mr37 = lp::assoc_bit<emr2, 5>;
    /* Event mask on external/internal line               38 */
    using emr2_mr38 = lp::assoc_bit<emr2, 6>;
    /* Event mask on external/internal line               39 */
    using emr2_mr39 = lp::assoc_bit<emr2, 7>;


    /* Rising Trigger selection           register */
    using rtsr2 = lp::io_register<lp::u32_t, base_address + 0x28>;
    /* Rising trigger event configuration bit               of line 35 */
    using rtsr2_rt35 = lp::assoc_bit<rtsr2, 3>;
    /* Rising trigger event configuration bit               of line 36 */
    using rtsr2_rt36 = lp::assoc_bit<rtsr2, 4>;
    /* Rising trigger event configuration bit               of line 37 */
    using rtsr2_rt37 = lp::assoc_bit<rtsr2, 5>;
    /* Rising trigger event configuration bit               of line 38 */
    using rtsr2_rt38 = lp::assoc_bit<rtsr2, 6>;


    /* Falling Trigger selection           register */
    using ftsr2 = lp::io_register<lp::u32_t, base_address + 0x2c>;
    /* Falling trigger event configuration bit               of line 35 */
    using ftsr2_ft35 = lp::assoc_bit<ftsr2, 3>;
    /* Falling trigger event configuration bit               of line 36 */
    using ftsr2_ft36 = lp::assoc_bit<ftsr2, 4>;
    /* Falling trigger event configuration bit               of line 37 */
    using ftsr2_ft37 = lp::assoc_bit<ftsr2, 5>;
    /* Falling trigger event configuration bit               of line 38 */
    using ftsr2_ft38 = lp::assoc_bit<ftsr2, 6>;


    /* Software interrupt event           register */
    using swier2 = lp::io_register<lp::u32_t, base_address + 0x30>;
    /* Software interrupt on line               35 */
    using swier2_swi35 = lp::assoc_bit<swier2, 3>;
    /* Software interrupt on line               36 */
    using swier2_swi36 = lp::assoc_bit<swier2, 4>;
    /* Software interrupt on line               37 */
    using swier2_swi37 = lp::assoc_bit<swier2, 5>;
    /* Software interrupt on line               38 */
    using swier2_swi38 = lp::assoc_bit<swier2, 6>;


    /* Pending register */
    using pr2 = lp::io_register<lp::u32_t, base_address + 0x34>;
    /* Pending interrupt flag on line               35 */
    using pr2_pif35 = lp::assoc_bit<pr2, 3>;
    /* Pending interrupt flag on line               36 */
    using pr2_pif36 = lp::assoc_bit<pr2, 4>;
    /* Pending interrupt flag on line               37 */
    using pr2_pif37 = lp::assoc_bit<pr2, 5>;
    /* Pending interrupt flag on line               38 */
    using pr2_pif38 = lp::assoc_bit<pr2, 6>;


};

using exti = exti_t<0x40010400>;

#endif // EXTI_HH
