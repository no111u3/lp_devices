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
 * Hardware support for tim
 * @file tim.hh
 * @author Boris Vinogradov
 */

#include <associate_bit.hh>
#include <io_register.hh>
#include <types.hh>

#ifndef TIM_HH
#define TIM_HH

/* General-purpose-timers */
template <lp::addr_t base_address>
struct tim_t {
    /* control register 1 */
    using cr1 = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* Clock division */
    using cr1_ckd = lp::assoc_bit<cr1, 8, 2>;
    /* Auto-reload preload enable */
    using cr1_arpe = lp::assoc_bit<cr1, 7>;
    /* Center-aligned mode               selection */
    using cr1_cms = lp::assoc_bit<cr1, 5, 2>;
    /* Direction */
    using cr1_dir = lp::assoc_bit<cr1, 4>;
    /* One-pulse mode */
    using cr1_opm = lp::assoc_bit<cr1, 3>;
    /* Update request source */
    using cr1_urs = lp::assoc_bit<cr1, 2>;
    /* Update disable */
    using cr1_udis = lp::assoc_bit<cr1, 1>;
    /* Counter enable */
    using cr1_cen = lp::assoc_bit<cr1, 0>;


    /* control register 2 */
    using cr2 = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* TI1 selection */
    using cr2_ti1s = lp::assoc_bit<cr2, 7>;
    /* Master mode selection */
    using cr2_mms = lp::assoc_bit<cr2, 4, 3>;
    /* Capture/compare DMA               selection */
    using cr2_ccds = lp::assoc_bit<cr2, 3>;


    /* slave mode control register */
    using smcr = lp::io_register<lp::u32_t, base_address + 0x8>;
    /* External trigger polarity */
    using smcr_etp = lp::assoc_bit<smcr, 15>;
    /* External clock enable */
    using smcr_ece = lp::assoc_bit<smcr, 14>;
    /* External trigger prescaler */
    using smcr_etps = lp::assoc_bit<smcr, 12, 2>;
    /* External trigger filter */
    using smcr_etf = lp::assoc_bit<smcr, 8, 4>;
    /* Master/Slave mode */
    using smcr_msm = lp::assoc_bit<smcr, 7>;
    /* Trigger selection */
    using smcr_ts = lp::assoc_bit<smcr, 4, 3>;
    /* Slave mode selection */
    using smcr_sms = lp::assoc_bit<smcr, 0, 3>;


    /* DMA/Interrupt enable register */
    using dier = lp::io_register<lp::u32_t, base_address + 0xc>;
    /* Trigger DMA request enable */
    using dier_tde = lp::assoc_bit<dier, 14>;
    /* COM DMA request enable */
    using dier_comde = lp::assoc_bit<dier, 13>;
    /* Capture/Compare 4 DMA request               enable */
    using dier_cc4de = lp::assoc_bit<dier, 12>;
    /* Capture/Compare 3 DMA request               enable */
    using dier_cc3de = lp::assoc_bit<dier, 11>;
    /* Capture/Compare 2 DMA request               enable */
    using dier_cc2de = lp::assoc_bit<dier, 10>;
    /* Capture/Compare 1 DMA request               enable */
    using dier_cc1de = lp::assoc_bit<dier, 9>;
    /* Update DMA request enable */
    using dier_ude = lp::assoc_bit<dier, 8>;
    /* Trigger interrupt enable */
    using dier_tie = lp::assoc_bit<dier, 6>;
    /* Capture/Compare 4 interrupt               enable */
    using dier_cc4ie = lp::assoc_bit<dier, 4>;
    /* Capture/Compare 3 interrupt               enable */
    using dier_cc3ie = lp::assoc_bit<dier, 3>;
    /* Capture/Compare 2 interrupt               enable */
    using dier_cc2ie = lp::assoc_bit<dier, 2>;
    /* Capture/Compare 1 interrupt               enable */
    using dier_cc1ie = lp::assoc_bit<dier, 1>;
    /* Update interrupt enable */
    using dier_uie = lp::assoc_bit<dier, 0>;


    /* status register */
    using sr = lp::io_register<lp::u32_t, base_address + 0x10>;
    /* Capture/Compare 4 overcapture               flag */
    using sr_cc4of = lp::assoc_bit<sr, 12>;
    /* Capture/Compare 3 overcapture               flag */
    using sr_cc3of = lp::assoc_bit<sr, 11>;
    /* Capture/compare 2 overcapture               flag */
    using sr_cc2of = lp::assoc_bit<sr, 10>;
    /* Capture/Compare 1 overcapture               flag */
    using sr_cc1of = lp::assoc_bit<sr, 9>;
    /* Trigger interrupt flag */
    using sr_tif = lp::assoc_bit<sr, 6>;
    /* Capture/Compare 4 interrupt               flag */
    using sr_cc4if = lp::assoc_bit<sr, 4>;
    /* Capture/Compare 3 interrupt               flag */
    using sr_cc3if = lp::assoc_bit<sr, 3>;
    /* Capture/Compare 2 interrupt               flag */
    using sr_cc2if = lp::assoc_bit<sr, 2>;
    /* Capture/compare 1 interrupt               flag */
    using sr_cc1if = lp::assoc_bit<sr, 1>;
    /* Update interrupt flag */
    using sr_uif = lp::assoc_bit<sr, 0>;


    /* event generation register */
    using egr = lp::io_register<lp::u32_t, base_address + 0x14>;
    /* Trigger generation */
    using egr_tg = lp::assoc_bit<egr, 6>;
    /* Capture/compare 4               generation */
    using egr_cc4g = lp::assoc_bit<egr, 4>;
    /* Capture/compare 3               generation */
    using egr_cc3g = lp::assoc_bit<egr, 3>;
    /* Capture/compare 2               generation */
    using egr_cc2g = lp::assoc_bit<egr, 2>;
    /* Capture/compare 1               generation */
    using egr_cc1g = lp::assoc_bit<egr, 1>;
    /* Update generation */
    using egr_ug = lp::assoc_bit<egr, 0>;


    /* capture/compare mode register 1 (output           mode) */
    using ccmr1_output = lp::io_register<lp::u32_t, base_address + 0x18>;
    /* Output compare 2 clear               enable */
    using ccmr1_output_oc2ce = lp::assoc_bit<ccmr1_output, 15>;
    /* Output compare 2 mode */
    using ccmr1_output_oc2m = lp::assoc_bit<ccmr1_output, 12, 3>;
    /* Output compare 2 preload               enable */
    using ccmr1_output_oc2pe = lp::assoc_bit<ccmr1_output, 11>;
    /* Output compare 2 fast               enable */
    using ccmr1_output_oc2fe = lp::assoc_bit<ccmr1_output, 10>;
    /* Capture/Compare 2               selection */
    using ccmr1_output_cc2s = lp::assoc_bit<ccmr1_output, 8, 2>;
    /* Output compare 1 clear               enable */
    using ccmr1_output_oc1ce = lp::assoc_bit<ccmr1_output, 7>;
    /* Output compare 1 mode */
    using ccmr1_output_oc1m = lp::assoc_bit<ccmr1_output, 4, 3>;
    /* Output compare 1 preload               enable */
    using ccmr1_output_oc1pe = lp::assoc_bit<ccmr1_output, 3>;
    /* Output compare 1 fast               enable */
    using ccmr1_output_oc1fe = lp::assoc_bit<ccmr1_output, 2>;
    /* Capture/Compare 1               selection */
    using ccmr1_output_cc1s = lp::assoc_bit<ccmr1_output, 0, 2>;


    /* capture/compare mode register 1 (input           mode) */
    using ccmr1_input = lp::io_register<lp::u32_t, base_address + 0x18>;
    /* Input capture 2 filter */
    using ccmr1_input_ic2f = lp::assoc_bit<ccmr1_input, 12, 4>;
    /* Input capture 2 prescaler */
    using ccmr1_input_ic2psc = lp::assoc_bit<ccmr1_input, 10, 2>;
    /* Capture/compare 2               selection */
    using ccmr1_input_cc2s = lp::assoc_bit<ccmr1_input, 8, 2>;
    /* Input capture 1 filter */
    using ccmr1_input_ic1f = lp::assoc_bit<ccmr1_input, 4, 4>;
    /* Input capture 1 prescaler */
    using ccmr1_input_ic1psc = lp::assoc_bit<ccmr1_input, 2, 2>;
    /* Capture/Compare 1               selection */
    using ccmr1_input_cc1s = lp::assoc_bit<ccmr1_input, 0, 2>;


    /* capture/compare mode register 2 (output           mode) */
    using ccmr2_output = lp::io_register<lp::u32_t, base_address + 0x1c>;
    /* Output compare 4 clear               enable */
    using ccmr2_output_oc4ce = lp::assoc_bit<ccmr2_output, 15>;
    /* Output compare 4 mode */
    using ccmr2_output_oc4m = lp::assoc_bit<ccmr2_output, 12, 3>;
    /* Output compare 4 preload               enable */
    using ccmr2_output_oc4pe = lp::assoc_bit<ccmr2_output, 11>;
    /* Output compare 4 fast               enable */
    using ccmr2_output_oc4fe = lp::assoc_bit<ccmr2_output, 10>;
    /* Capture/Compare 4               selection */
    using ccmr2_output_cc4s = lp::assoc_bit<ccmr2_output, 8, 2>;
    /* Output compare 3 clear               enable */
    using ccmr2_output_oc3ce = lp::assoc_bit<ccmr2_output, 7>;
    /* Output compare 3 mode */
    using ccmr2_output_oc3m = lp::assoc_bit<ccmr2_output, 4, 3>;
    /* Output compare 3 preload               enable */
    using ccmr2_output_oc3pe = lp::assoc_bit<ccmr2_output, 3>;
    /* Output compare 3 fast               enable */
    using ccmr2_output_oc3fe = lp::assoc_bit<ccmr2_output, 2>;
    /* Capture/Compare 3               selection */
    using ccmr2_output_cc3s = lp::assoc_bit<ccmr2_output, 0, 2>;


    /* capture/compare mode register 2 (input           mode) */
    using ccmr2_input = lp::io_register<lp::u32_t, base_address + 0x1c>;
    /* Input capture 4 filter */
    using ccmr2_input_ic4f = lp::assoc_bit<ccmr2_input, 12, 4>;
    /* Input capture 4 prescaler */
    using ccmr2_input_ic4psc = lp::assoc_bit<ccmr2_input, 10, 2>;
    /* Capture/Compare 4               selection */
    using ccmr2_input_cc4s = lp::assoc_bit<ccmr2_input, 8, 2>;
    /* Input capture 3 filter */
    using ccmr2_input_ic3f = lp::assoc_bit<ccmr2_input, 4, 4>;
    /* Input capture 3 prescaler */
    using ccmr2_input_ic3psc = lp::assoc_bit<ccmr2_input, 2, 2>;
    /* Capture/Compare 3               selection */
    using ccmr2_input_cc3s = lp::assoc_bit<ccmr2_input, 0, 2>;


    /* capture/compare enable           register */
    using ccer = lp::io_register<lp::u32_t, base_address + 0x20>;
    /* Capture/Compare 4 output               Polarity */
    using ccer_cc4np = lp::assoc_bit<ccer, 15>;
    /* Capture/Compare 3 output               Polarity */
    using ccer_cc4p = lp::assoc_bit<ccer, 13>;
    /* Capture/Compare 4 output               enable */
    using ccer_cc4e = lp::assoc_bit<ccer, 12>;
    /* Capture/Compare 3 output               Polarity */
    using ccer_cc3np = lp::assoc_bit<ccer, 11>;
    /* Capture/Compare 3 output               Polarity */
    using ccer_cc3p = lp::assoc_bit<ccer, 9>;
    /* Capture/Compare 3 output               enable */
    using ccer_cc3e = lp::assoc_bit<ccer, 8>;
    /* Capture/Compare 2 output               Polarity */
    using ccer_cc2np = lp::assoc_bit<ccer, 7>;
    /* Capture/Compare 2 output               Polarity */
    using ccer_cc2p = lp::assoc_bit<ccer, 5>;
    /* Capture/Compare 2 output               enable */
    using ccer_cc2e = lp::assoc_bit<ccer, 4>;
    /* Capture/Compare 1 output               Polarity */
    using ccer_cc1np = lp::assoc_bit<ccer, 3>;
    /* Capture/Compare 1 output               Polarity */
    using ccer_cc1p = lp::assoc_bit<ccer, 1>;
    /* Capture/Compare 1 output               enable */
    using ccer_cc1e = lp::assoc_bit<ccer, 0>;


    /* counter */
    using cnt = lp::io_register<lp::u32_t, base_address + 0x24>;
    /* High counter value (TIM2               only) */
    using cnt_cnt_h = lp::assoc_bit<cnt, 16, 16>;
    /* Low counter value */
    using cnt_cnt_l = lp::assoc_bit<cnt, 0, 16>;


    /* prescaler */
    using psc = lp::io_register<lp::u32_t, base_address + 0x28>;
    /* Prescaler value */
    using psc_psc = lp::assoc_bit<psc, 0, 16>;


    /* auto-reload register */
    using arr = lp::io_register<lp::u32_t, base_address + 0x2c>;
    /* High Auto-reload value (TIM2               only) */
    using arr_arr_h = lp::assoc_bit<arr, 16, 16>;
    /* Low Auto-reload value */
    using arr_arr_l = lp::assoc_bit<arr, 0, 16>;


    /* capture/compare register 1 */
    using ccr1 = lp::io_register<lp::u32_t, base_address + 0x34>;
    /* High Capture/Compare 1 value (TIM2               only) */
    using ccr1_ccr1_h = lp::assoc_bit<ccr1, 16, 16>;
    /* Low Capture/Compare 1               value */
    using ccr1_ccr1_l = lp::assoc_bit<ccr1, 0, 16>;


    /* capture/compare register 2 */
    using ccr2 = lp::io_register<lp::u32_t, base_address + 0x38>;
    /* High Capture/Compare 2 value (TIM2               only) */
    using ccr2_ccr2_h = lp::assoc_bit<ccr2, 16, 16>;
    /* Low Capture/Compare 2               value */
    using ccr2_ccr2_l = lp::assoc_bit<ccr2, 0, 16>;


    /* capture/compare register 3 */
    using ccr3 = lp::io_register<lp::u32_t, base_address + 0x3c>;
    /* High Capture/Compare value (TIM2               only) */
    using ccr3_ccr3_h = lp::assoc_bit<ccr3, 16, 16>;
    /* Low Capture/Compare value */
    using ccr3_ccr3_l = lp::assoc_bit<ccr3, 0, 16>;


    /* capture/compare register 4 */
    using ccr4 = lp::io_register<lp::u32_t, base_address + 0x40>;
    /* High Capture/Compare value (TIM2               only) */
    using ccr4_ccr4_h = lp::assoc_bit<ccr4, 16, 16>;
    /* Low Capture/Compare value */
    using ccr4_ccr4_l = lp::assoc_bit<ccr4, 0, 16>;


    /* DMA control register */
    using dcr = lp::io_register<lp::u32_t, base_address + 0x48>;
    /* DMA burst length */
    using dcr_dbl = lp::assoc_bit<dcr, 8, 5>;
    /* DMA base address */
    using dcr_dba = lp::assoc_bit<dcr, 0, 5>;


    /* DMA address for full transfer */
    using dmar = lp::io_register<lp::u32_t, base_address + 0x4c>;
    /* DMA register for burst               accesses */
    using dmar_dmab = lp::assoc_bit<dmar, 0, 16>;


    /* TIM2 option register */
    using or = lp::io_register<lp::u32_t, base_address + 0x50>;
    /* Timer2 ETR remap */
    using or_etr_rmp = lp::assoc_bit<or, 0, 3>;
    /* Internal trigger */
    using or_ti4_rmp = lp::assoc_bit<or, 3, 2>;


};

/* General purpose timers */
template <lp::addr_t base_address>
struct tim15_t {
    /* control register 1 */
    using cr1 = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* Counter enable */
    using cr1_cen = lp::assoc_bit<cr1, 0>;
    /* Update disable */
    using cr1_udis = lp::assoc_bit<cr1, 1>;
    /* Update request source */
    using cr1_urs = lp::assoc_bit<cr1, 2>;
    /* One-pulse mode */
    using cr1_opm = lp::assoc_bit<cr1, 3>;
    /* Auto-reload preload enable */
    using cr1_arpe = lp::assoc_bit<cr1, 7>;
    /* Clock division */
    using cr1_ckd = lp::assoc_bit<cr1, 8, 2>;
    /* UIF status bit remapping */
    using cr1_uifremap = lp::assoc_bit<cr1, 11>;


    /* control register 2 */
    using cr2 = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* Output Idle state 1 */
    using cr2_ois1n = lp::assoc_bit<cr2, 9>;
    /* Output Idle state 1 */
    using cr2_ois1 = lp::assoc_bit<cr2, 8>;
    /* Capture/compare DMA               selection */
    using cr2_ccds = lp::assoc_bit<cr2, 3>;
    /* Capture/compare control update               selection */
    using cr2_ccus = lp::assoc_bit<cr2, 2>;
    /* Capture/compare preloaded               control */
    using cr2_ccpc = lp::assoc_bit<cr2, 0>;


    /* DMA/Interrupt enable register */
    using dier = lp::io_register<lp::u32_t, base_address + 0xc>;
    /* Trigger DMA request enable */
    using dier_tde = lp::assoc_bit<dier, 14>;
    /* COM DMA request enable */
    using dier_comde = lp::assoc_bit<dier, 13>;
    /* Capture/Compare 1 DMA request               enable */
    using dier_cc1de = lp::assoc_bit<dier, 9>;
    /* Update DMA request enable */
    using dier_ude = lp::assoc_bit<dier, 8>;
    /* Break interrupt enable */
    using dier_bie = lp::assoc_bit<dier, 7>;
    /* Trigger interrupt enable */
    using dier_tie = lp::assoc_bit<dier, 6>;
    /* COM interrupt enable */
    using dier_comie = lp::assoc_bit<dier, 5>;
    /* Capture/Compare 1 interrupt               enable */
    using dier_cc1ie = lp::assoc_bit<dier, 1>;
    /* Update interrupt enable */
    using dier_uie = lp::assoc_bit<dier, 0>;


    /* status register */
    using sr = lp::io_register<lp::u32_t, base_address + 0x10>;
    /* Capture/Compare 1 overcapture               flag */
    using sr_cc1of = lp::assoc_bit<sr, 9>;
    /* Break interrupt flag */
    using sr_bif = lp::assoc_bit<sr, 7>;
    /* Trigger interrupt flag */
    using sr_tif = lp::assoc_bit<sr, 6>;
    /* COM interrupt flag */
    using sr_comif = lp::assoc_bit<sr, 5>;
    /* Capture/compare 1 interrupt               flag */
    using sr_cc1if = lp::assoc_bit<sr, 1>;
    /* Update interrupt flag */
    using sr_uif = lp::assoc_bit<sr, 0>;


    /* event generation register */
    using egr = lp::io_register<lp::u32_t, base_address + 0x14>;
    /* Break generation */
    using egr_bg = lp::assoc_bit<egr, 7>;
    /* Trigger generation */
    using egr_tg = lp::assoc_bit<egr, 6>;
    /* Capture/Compare control update               generation */
    using egr_comg = lp::assoc_bit<egr, 5>;
    /* Capture/compare 1               generation */
    using egr_cc1g = lp::assoc_bit<egr, 1>;
    /* Update generation */
    using egr_ug = lp::assoc_bit<egr, 0>;


    /* capture/compare mode register (output           mode) */
    using ccmr1_output = lp::io_register<lp::u32_t, base_address + 0x18>;
    /* Output Compare 1 mode */
    using ccmr1_output_oc1m_2 = lp::assoc_bit<ccmr1_output, 16>;
    /* Output Compare 1 mode */
    using ccmr1_output_oc1m = lp::assoc_bit<ccmr1_output, 4, 3>;
    /* Output Compare 1 preload               enable */
    using ccmr1_output_oc1pe = lp::assoc_bit<ccmr1_output, 3>;
    /* Output Compare 1 fast               enable */
    using ccmr1_output_oc1fe = lp::assoc_bit<ccmr1_output, 2>;
    /* Capture/Compare 1               selection */
    using ccmr1_output_cc1s = lp::assoc_bit<ccmr1_output, 0, 2>;


    /* capture/compare mode register 1 (input           mode) */
    using ccmr1_input = lp::io_register<lp::u32_t, base_address + 0x18>;
    /* Input capture 1 filter */
    using ccmr1_input_ic1f = lp::assoc_bit<ccmr1_input, 4, 4>;
    /* Input capture 1 prescaler */
    using ccmr1_input_ic1psc = lp::assoc_bit<ccmr1_input, 2, 2>;
    /* Capture/Compare 1               selection */
    using ccmr1_input_cc1s = lp::assoc_bit<ccmr1_input, 0, 2>;


    /* capture/compare enable           register */
    using ccer = lp::io_register<lp::u32_t, base_address + 0x20>;
    /* Capture/Compare 1 output               Polarity */
    using ccer_cc1np = lp::assoc_bit<ccer, 3>;
    /* Capture/Compare 1 complementary output               enable */
    using ccer_cc1ne = lp::assoc_bit<ccer, 2>;
    /* Capture/Compare 1 output               Polarity */
    using ccer_cc1p = lp::assoc_bit<ccer, 1>;
    /* Capture/Compare 1 output               enable */
    using ccer_cc1e = lp::assoc_bit<ccer, 0>;


    /* counter */
    using cnt = lp::io_register<lp::u32_t, base_address + 0x24>;
    /* counter value */
    using cnt_cnt = lp::assoc_bit<cnt, 0, 16>;
    /* UIF Copy */
    using cnt_uifcpy = lp::assoc_bit<cnt, 31>;


    /* prescaler */
    using psc = lp::io_register<lp::u32_t, base_address + 0x28>;
    /* Prescaler value */
    using psc_psc = lp::assoc_bit<psc, 0, 16>;


    /* auto-reload register */
    using arr = lp::io_register<lp::u32_t, base_address + 0x2c>;
    /* Auto-reload value */
    using arr_arr = lp::assoc_bit<arr, 0, 16>;


    /* repetition counter register */
    using rcr = lp::io_register<lp::u32_t, base_address + 0x30>;
    /* Repetition counter value */
    using rcr_rep = lp::assoc_bit<rcr, 0, 8>;


    /* capture/compare register 1 */
    using ccr1 = lp::io_register<lp::u32_t, base_address + 0x34>;
    /* Capture/Compare 1 value */
    using ccr1_ccr1 = lp::assoc_bit<ccr1, 0, 16>;


    /* break and dead-time register */
    using bdtr = lp::io_register<lp::u32_t, base_address + 0x44>;
    /* Dead-time generator setup */
    using bdtr_dtg = lp::assoc_bit<bdtr, 0, 8>;
    /* Lock configuration */
    using bdtr_lock = lp::assoc_bit<bdtr, 8, 2>;
    /* Off-state selection for Idle               mode */
    using bdtr_ossi = lp::assoc_bit<bdtr, 10>;
    /* Off-state selection for Run               mode */
    using bdtr_ossr = lp::assoc_bit<bdtr, 11>;
    /* Break enable */
    using bdtr_bke = lp::assoc_bit<bdtr, 12>;
    /* Break polarity */
    using bdtr_bkp = lp::assoc_bit<bdtr, 13>;
    /* Automatic output enable */
    using bdtr_aoe = lp::assoc_bit<bdtr, 14>;
    /* Main output enable */
    using bdtr_moe = lp::assoc_bit<bdtr, 15>;
    /* Break filter */
    using bdtr_bkf = lp::assoc_bit<bdtr, 16, 4>;


    /* DMA control register */
    using dcr = lp::io_register<lp::u32_t, base_address + 0x48>;
    /* DMA burst length */
    using dcr_dbl = lp::assoc_bit<dcr, 8, 5>;
    /* DMA base address */
    using dcr_dba = lp::assoc_bit<dcr, 0, 5>;


    /* DMA address for full transfer */
    using dmar = lp::io_register<lp::u32_t, base_address + 0x4c>;
    /* DMA register for burst               accesses */
    using dmar_dmab = lp::assoc_bit<dmar, 0, 16>;


};

/* General purpose timers */
template <lp::addr_t base_address>
struct tim16_t {
    /* control register 1 */
    using cr1 = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* Counter enable */
    using cr1_cen = lp::assoc_bit<cr1, 0>;
    /* Update disable */
    using cr1_udis = lp::assoc_bit<cr1, 1>;
    /* Update request source */
    using cr1_urs = lp::assoc_bit<cr1, 2>;
    /* One-pulse mode */
    using cr1_opm = lp::assoc_bit<cr1, 3>;
    /* Auto-reload preload enable */
    using cr1_arpe = lp::assoc_bit<cr1, 7>;
    /* Clock division */
    using cr1_ckd = lp::assoc_bit<cr1, 8, 2>;
    /* UIF status bit remapping */
    using cr1_uifremap = lp::assoc_bit<cr1, 11>;


    /* control register 2 */
    using cr2 = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* Output Idle state 1 */
    using cr2_ois1n = lp::assoc_bit<cr2, 9>;
    /* Output Idle state 1 */
    using cr2_ois1 = lp::assoc_bit<cr2, 8>;
    /* Capture/compare DMA               selection */
    using cr2_ccds = lp::assoc_bit<cr2, 3>;
    /* Capture/compare control update               selection */
    using cr2_ccus = lp::assoc_bit<cr2, 2>;
    /* Capture/compare preloaded               control */
    using cr2_ccpc = lp::assoc_bit<cr2, 0>;


    /* DMA/Interrupt enable register */
    using dier = lp::io_register<lp::u32_t, base_address + 0xc>;
    /* Trigger DMA request enable */
    using dier_tde = lp::assoc_bit<dier, 14>;
    /* COM DMA request enable */
    using dier_comde = lp::assoc_bit<dier, 13>;
    /* Capture/Compare 1 DMA request               enable */
    using dier_cc1de = lp::assoc_bit<dier, 9>;
    /* Update DMA request enable */
    using dier_ude = lp::assoc_bit<dier, 8>;
    /* Break interrupt enable */
    using dier_bie = lp::assoc_bit<dier, 7>;
    /* Trigger interrupt enable */
    using dier_tie = lp::assoc_bit<dier, 6>;
    /* COM interrupt enable */
    using dier_comie = lp::assoc_bit<dier, 5>;
    /* Capture/Compare 1 interrupt               enable */
    using dier_cc1ie = lp::assoc_bit<dier, 1>;
    /* Update interrupt enable */
    using dier_uie = lp::assoc_bit<dier, 0>;


    /* status register */
    using sr = lp::io_register<lp::u32_t, base_address + 0x10>;
    /* Capture/Compare 1 overcapture               flag */
    using sr_cc1of = lp::assoc_bit<sr, 9>;
    /* Break interrupt flag */
    using sr_bif = lp::assoc_bit<sr, 7>;
    /* Trigger interrupt flag */
    using sr_tif = lp::assoc_bit<sr, 6>;
    /* COM interrupt flag */
    using sr_comif = lp::assoc_bit<sr, 5>;
    /* Capture/compare 1 interrupt               flag */
    using sr_cc1if = lp::assoc_bit<sr, 1>;
    /* Update interrupt flag */
    using sr_uif = lp::assoc_bit<sr, 0>;


    /* event generation register */
    using egr = lp::io_register<lp::u32_t, base_address + 0x14>;
    /* Break generation */
    using egr_bg = lp::assoc_bit<egr, 7>;
    /* Trigger generation */
    using egr_tg = lp::assoc_bit<egr, 6>;
    /* Capture/Compare control update               generation */
    using egr_comg = lp::assoc_bit<egr, 5>;
    /* Capture/compare 1               generation */
    using egr_cc1g = lp::assoc_bit<egr, 1>;
    /* Update generation */
    using egr_ug = lp::assoc_bit<egr, 0>;


    /* capture/compare mode register (output           mode) */
    using ccmr1_output = lp::io_register<lp::u32_t, base_address + 0x18>;
    /* Output Compare 1 mode */
    using ccmr1_output_oc1m_2 = lp::assoc_bit<ccmr1_output, 16>;
    /* Output Compare 1 mode */
    using ccmr1_output_oc1m = lp::assoc_bit<ccmr1_output, 4, 3>;
    /* Output Compare 1 preload               enable */
    using ccmr1_output_oc1pe = lp::assoc_bit<ccmr1_output, 3>;
    /* Output Compare 1 fast               enable */
    using ccmr1_output_oc1fe = lp::assoc_bit<ccmr1_output, 2>;
    /* Capture/Compare 1               selection */
    using ccmr1_output_cc1s = lp::assoc_bit<ccmr1_output, 0, 2>;


    /* capture/compare mode register 1 (input           mode) */
    using ccmr1_input = lp::io_register<lp::u32_t, base_address + 0x18>;
    /* Input capture 1 filter */
    using ccmr1_input_ic1f = lp::assoc_bit<ccmr1_input, 4, 4>;
    /* Input capture 1 prescaler */
    using ccmr1_input_ic1psc = lp::assoc_bit<ccmr1_input, 2, 2>;
    /* Capture/Compare 1               selection */
    using ccmr1_input_cc1s = lp::assoc_bit<ccmr1_input, 0, 2>;


    /* capture/compare enable           register */
    using ccer = lp::io_register<lp::u32_t, base_address + 0x20>;
    /* Capture/Compare 1 output               Polarity */
    using ccer_cc1np = lp::assoc_bit<ccer, 3>;
    /* Capture/Compare 1 complementary output               enable */
    using ccer_cc1ne = lp::assoc_bit<ccer, 2>;
    /* Capture/Compare 1 output               Polarity */
    using ccer_cc1p = lp::assoc_bit<ccer, 1>;
    /* Capture/Compare 1 output               enable */
    using ccer_cc1e = lp::assoc_bit<ccer, 0>;


    /* counter */
    using cnt = lp::io_register<lp::u32_t, base_address + 0x24>;
    /* counter value */
    using cnt_cnt = lp::assoc_bit<cnt, 0, 16>;
    /* UIF Copy */
    using cnt_uifcpy = lp::assoc_bit<cnt, 31>;


    /* prescaler */
    using psc = lp::io_register<lp::u32_t, base_address + 0x28>;
    /* Prescaler value */
    using psc_psc = lp::assoc_bit<psc, 0, 16>;


    /* auto-reload register */
    using arr = lp::io_register<lp::u32_t, base_address + 0x2c>;
    /* Auto-reload value */
    using arr_arr = lp::assoc_bit<arr, 0, 16>;


    /* repetition counter register */
    using rcr = lp::io_register<lp::u32_t, base_address + 0x30>;
    /* Repetition counter value */
    using rcr_rep = lp::assoc_bit<rcr, 0, 8>;


    /* capture/compare register 1 */
    using ccr1 = lp::io_register<lp::u32_t, base_address + 0x34>;
    /* Capture/Compare 1 value */
    using ccr1_ccr1 = lp::assoc_bit<ccr1, 0, 16>;


    /* break and dead-time register */
    using bdtr = lp::io_register<lp::u32_t, base_address + 0x44>;
    /* Dead-time generator setup */
    using bdtr_dtg = lp::assoc_bit<bdtr, 0, 8>;
    /* Lock configuration */
    using bdtr_lock = lp::assoc_bit<bdtr, 8, 2>;
    /* Off-state selection for Idle               mode */
    using bdtr_ossi = lp::assoc_bit<bdtr, 10>;
    /* Off-state selection for Run               mode */
    using bdtr_ossr = lp::assoc_bit<bdtr, 11>;
    /* Break enable */
    using bdtr_bke = lp::assoc_bit<bdtr, 12>;
    /* Break polarity */
    using bdtr_bkp = lp::assoc_bit<bdtr, 13>;
    /* Automatic output enable */
    using bdtr_aoe = lp::assoc_bit<bdtr, 14>;
    /* Main output enable */
    using bdtr_moe = lp::assoc_bit<bdtr, 15>;
    /* Break filter */
    using bdtr_bkf = lp::assoc_bit<bdtr, 16, 4>;


    /* DMA control register */
    using dcr = lp::io_register<lp::u32_t, base_address + 0x48>;
    /* DMA burst length */
    using dcr_dbl = lp::assoc_bit<dcr, 8, 5>;
    /* DMA base address */
    using dcr_dba = lp::assoc_bit<dcr, 0, 5>;


    /* DMA address for full transfer */
    using dmar = lp::io_register<lp::u32_t, base_address + 0x4c>;
    /* DMA register for burst               accesses */
    using dmar_dmab = lp::assoc_bit<dmar, 0, 16>;


    /* TIM16 option register 1 */
    using or1 = lp::io_register<lp::u32_t, base_address + 0x50>;
    /* Input capture 1 remap */
    using or1_ti1_rmp = lp::assoc_bit<or1, 0, 2>;


    /* TIM17 option register 1 */
    using or2 = lp::io_register<lp::u32_t, base_address + 0x60>;
    /* BRK BKIN input enable */
    using or2_bkine = lp::assoc_bit<or2, 0>;
    /* BRK COMP1 enable */
    using or2_bkcmp1e = lp::assoc_bit<or2, 1>;
    /* BRK COMP2 enable */
    using or2_bkcmp2e = lp::assoc_bit<or2, 2>;
    /* BRK DFSDM_BREAK1 enable */
    using or2_bkdfbk1e = lp::assoc_bit<or2, 8>;
    /* BRK BKIN input polarity */
    using or2_bkinp = lp::assoc_bit<or2, 9>;
    /* BRK COMP1 input polarity */
    using or2_bkcmp1p = lp::assoc_bit<or2, 10>;
    /* BRK COMP2 input polarit */
    using or2_bkcmp2p = lp::assoc_bit<or2, 11>;


};

/* Advanced-timers */
template <lp::addr_t base_address>
struct tim1_t {
    /* control register 1 */
    using cr1 = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* Clock division */
    using cr1_ckd = lp::assoc_bit<cr1, 8, 2>;
    /* Auto-reload preload enable */
    using cr1_arpe = lp::assoc_bit<cr1, 7>;
    /* Center-aligned mode               selection */
    using cr1_cms = lp::assoc_bit<cr1, 5, 2>;
    /* Direction */
    using cr1_dir = lp::assoc_bit<cr1, 4>;
    /* One-pulse mode */
    using cr1_opm = lp::assoc_bit<cr1, 3>;
    /* Update request source */
    using cr1_urs = lp::assoc_bit<cr1, 2>;
    /* Update disable */
    using cr1_udis = lp::assoc_bit<cr1, 1>;
    /* Counter enable */
    using cr1_cen = lp::assoc_bit<cr1, 0>;


    /* control register 2 */
    using cr2 = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* Output Idle state 4 */
    using cr2_ois4 = lp::assoc_bit<cr2, 14>;
    /* Output Idle state 3 */
    using cr2_ois3n = lp::assoc_bit<cr2, 13>;
    /* Output Idle state 3 */
    using cr2_ois3 = lp::assoc_bit<cr2, 12>;
    /* Output Idle state 2 */
    using cr2_ois2n = lp::assoc_bit<cr2, 11>;
    /* Output Idle state 2 */
    using cr2_ois2 = lp::assoc_bit<cr2, 10>;
    /* Output Idle state 1 */
    using cr2_ois1n = lp::assoc_bit<cr2, 9>;
    /* Output Idle state 1 */
    using cr2_ois1 = lp::assoc_bit<cr2, 8>;
    /* TI1 selection */
    using cr2_ti1s = lp::assoc_bit<cr2, 7>;
    /* Master mode selection */
    using cr2_mms = lp::assoc_bit<cr2, 4, 3>;
    /* Capture/compare DMA               selection */
    using cr2_ccds = lp::assoc_bit<cr2, 3>;
    /* Capture/compare control update               selection */
    using cr2_ccus = lp::assoc_bit<cr2, 2>;
    /* Capture/compare preloaded               control */
    using cr2_ccpc = lp::assoc_bit<cr2, 0>;


    /* slave mode control register */
    using smcr = lp::io_register<lp::u32_t, base_address + 0x8>;
    /* External trigger polarity */
    using smcr_etp = lp::assoc_bit<smcr, 15>;
    /* External clock enable */
    using smcr_ece = lp::assoc_bit<smcr, 14>;
    /* External trigger prescaler */
    using smcr_etps = lp::assoc_bit<smcr, 12, 2>;
    /* External trigger filter */
    using smcr_etf = lp::assoc_bit<smcr, 8, 4>;
    /* Master/Slave mode */
    using smcr_msm = lp::assoc_bit<smcr, 7>;
    /* Trigger selection */
    using smcr_ts = lp::assoc_bit<smcr, 4, 3>;
    /* Slave mode selection */
    using smcr_sms = lp::assoc_bit<smcr, 0, 3>;


    /* DMA/Interrupt enable register */
    using dier = lp::io_register<lp::u32_t, base_address + 0xc>;
    /* Trigger DMA request enable */
    using dier_tde = lp::assoc_bit<dier, 14>;
    /* COM DMA request enable */
    using dier_comde = lp::assoc_bit<dier, 13>;
    /* Capture/Compare 4 DMA request               enable */
    using dier_cc4de = lp::assoc_bit<dier, 12>;
    /* Capture/Compare 3 DMA request               enable */
    using dier_cc3de = lp::assoc_bit<dier, 11>;
    /* Capture/Compare 2 DMA request               enable */
    using dier_cc2de = lp::assoc_bit<dier, 10>;
    /* Capture/Compare 1 DMA request               enable */
    using dier_cc1de = lp::assoc_bit<dier, 9>;
    /* Update DMA request enable */
    using dier_ude = lp::assoc_bit<dier, 8>;
    /* Trigger interrupt enable */
    using dier_tie = lp::assoc_bit<dier, 6>;
    /* Capture/Compare 4 interrupt               enable */
    using dier_cc4ie = lp::assoc_bit<dier, 4>;
    /* Capture/Compare 3 interrupt               enable */
    using dier_cc3ie = lp::assoc_bit<dier, 3>;
    /* Capture/Compare 2 interrupt               enable */
    using dier_cc2ie = lp::assoc_bit<dier, 2>;
    /* Capture/Compare 1 interrupt               enable */
    using dier_cc1ie = lp::assoc_bit<dier, 1>;
    /* Update interrupt enable */
    using dier_uie = lp::assoc_bit<dier, 0>;
    /* Break interrupt enable */
    using dier_bie = lp::assoc_bit<dier, 7>;
    /* COM interrupt enable */
    using dier_comie = lp::assoc_bit<dier, 5>;


    /* status register */
    using sr = lp::io_register<lp::u32_t, base_address + 0x10>;
    /* Capture/Compare 4 overcapture               flag */
    using sr_cc4of = lp::assoc_bit<sr, 12>;
    /* Capture/Compare 3 overcapture               flag */
    using sr_cc3of = lp::assoc_bit<sr, 11>;
    /* Capture/compare 2 overcapture               flag */
    using sr_cc2of = lp::assoc_bit<sr, 10>;
    /* Capture/Compare 1 overcapture               flag */
    using sr_cc1of = lp::assoc_bit<sr, 9>;
    /* Break interrupt flag */
    using sr_bif = lp::assoc_bit<sr, 7>;
    /* Trigger interrupt flag */
    using sr_tif = lp::assoc_bit<sr, 6>;
    /* COM interrupt flag */
    using sr_comif = lp::assoc_bit<sr, 5>;
    /* Capture/Compare 4 interrupt               flag */
    using sr_cc4if = lp::assoc_bit<sr, 4>;
    /* Capture/Compare 3 interrupt               flag */
    using sr_cc3if = lp::assoc_bit<sr, 3>;
    /* Capture/Compare 2 interrupt               flag */
    using sr_cc2if = lp::assoc_bit<sr, 2>;
    /* Capture/compare 1 interrupt               flag */
    using sr_cc1if = lp::assoc_bit<sr, 1>;
    /* Update interrupt flag */
    using sr_uif = lp::assoc_bit<sr, 0>;


    /* event generation register */
    using egr = lp::io_register<lp::u32_t, base_address + 0x14>;
    /* Break generation */
    using egr_bg = lp::assoc_bit<egr, 7>;
    /* Trigger generation */
    using egr_tg = lp::assoc_bit<egr, 6>;
    /* Capture/Compare control update               generation */
    using egr_comg = lp::assoc_bit<egr, 5>;
    /* Capture/compare 4               generation */
    using egr_cc4g = lp::assoc_bit<egr, 4>;
    /* Capture/compare 3               generation */
    using egr_cc3g = lp::assoc_bit<egr, 3>;
    /* Capture/compare 2               generation */
    using egr_cc2g = lp::assoc_bit<egr, 2>;
    /* Capture/compare 1               generation */
    using egr_cc1g = lp::assoc_bit<egr, 1>;
    /* Update generation */
    using egr_ug = lp::assoc_bit<egr, 0>;


    /* capture/compare mode register 1 (output           mode) */
    using ccmr1_output = lp::io_register<lp::u32_t, base_address + 0x18>;
    /* Output Compare 2 clear               enable */
    using ccmr1_output_oc2ce = lp::assoc_bit<ccmr1_output, 15>;
    /* Output Compare 2 mode */
    using ccmr1_output_oc2m = lp::assoc_bit<ccmr1_output, 12, 3>;
    /* Output Compare 2 preload               enable */
    using ccmr1_output_oc2pe = lp::assoc_bit<ccmr1_output, 11>;
    /* Output Compare 2 fast               enable */
    using ccmr1_output_oc2fe = lp::assoc_bit<ccmr1_output, 10>;
    /* Capture/Compare 2               selection */
    using ccmr1_output_cc2s = lp::assoc_bit<ccmr1_output, 8, 2>;
    /* Output Compare 1 clear               enable */
    using ccmr1_output_oc1ce = lp::assoc_bit<ccmr1_output, 7>;
    /* Output Compare 1 mode */
    using ccmr1_output_oc1m = lp::assoc_bit<ccmr1_output, 4, 3>;
    /* Output Compare 1 preload               enable */
    using ccmr1_output_oc1pe = lp::assoc_bit<ccmr1_output, 3>;
    /* Output Compare 1 fast               enable */
    using ccmr1_output_oc1fe = lp::assoc_bit<ccmr1_output, 2>;
    /* Capture/Compare 1               selection */
    using ccmr1_output_cc1s = lp::assoc_bit<ccmr1_output, 0, 2>;


    /* capture/compare mode register 1 (input           mode) */
    using ccmr1_input = lp::io_register<lp::u32_t, base_address + 0x18>;
    /* Input capture 2 filter */
    using ccmr1_input_ic2f = lp::assoc_bit<ccmr1_input, 12, 4>;
    /* Input capture 2 prescaler */
    using ccmr1_input_ic2pcs = lp::assoc_bit<ccmr1_input, 10, 2>;
    /* Capture/Compare 2               selection */
    using ccmr1_input_cc2s = lp::assoc_bit<ccmr1_input, 8, 2>;
    /* Input capture 1 filter */
    using ccmr1_input_ic1f = lp::assoc_bit<ccmr1_input, 4, 4>;
    /* Input capture 1 prescaler */
    using ccmr1_input_icpcs = lp::assoc_bit<ccmr1_input, 2, 2>;
    /* Capture/Compare 1               selection */
    using ccmr1_input_cc1s = lp::assoc_bit<ccmr1_input, 0, 2>;


    /* capture/compare mode register 2 (output           mode) */
    using ccmr2_output = lp::io_register<lp::u32_t, base_address + 0x1c>;
    /* Output compare 4 clear               enable */
    using ccmr2_output_oc4ce = lp::assoc_bit<ccmr2_output, 15>;
    /* Output compare 4 mode */
    using ccmr2_output_oc4m = lp::assoc_bit<ccmr2_output, 12, 3>;
    /* Output compare 4 preload               enable */
    using ccmr2_output_oc4pe = lp::assoc_bit<ccmr2_output, 11>;
    /* Output compare 4 fast               enable */
    using ccmr2_output_oc4fe = lp::assoc_bit<ccmr2_output, 10>;
    /* Capture/Compare 4               selection */
    using ccmr2_output_cc4s = lp::assoc_bit<ccmr2_output, 8, 2>;
    /* Output compare 3 clear               enable */
    using ccmr2_output_oc3ce = lp::assoc_bit<ccmr2_output, 7>;
    /* Output compare 3 mode */
    using ccmr2_output_oc3m = lp::assoc_bit<ccmr2_output, 4, 3>;
    /* Output compare 3 preload               enable */
    using ccmr2_output_oc3pe = lp::assoc_bit<ccmr2_output, 3>;
    /* Output compare 3 fast               enable */
    using ccmr2_output_oc3fe = lp::assoc_bit<ccmr2_output, 2>;
    /* Capture/Compare 3               selection */
    using ccmr2_output_cc3s = lp::assoc_bit<ccmr2_output, 0, 2>;


    /* capture/compare mode register 2 (input           mode) */
    using ccmr2_input = lp::io_register<lp::u32_t, base_address + 0x1c>;
    /* Input capture 4 filter */
    using ccmr2_input_ic4f = lp::assoc_bit<ccmr2_input, 12, 4>;
    /* Input capture 4 prescaler */
    using ccmr2_input_ic4psc = lp::assoc_bit<ccmr2_input, 10, 2>;
    /* Capture/Compare 4               selection */
    using ccmr2_input_cc4s = lp::assoc_bit<ccmr2_input, 8, 2>;
    /* Input capture 3 filter */
    using ccmr2_input_ic3f = lp::assoc_bit<ccmr2_input, 4, 4>;
    /* Input capture 3 prescaler */
    using ccmr2_input_ic3psc = lp::assoc_bit<ccmr2_input, 2, 2>;
    /* Capture/compare 3               selection */
    using ccmr2_input_cc3s = lp::assoc_bit<ccmr2_input, 0, 2>;


    /* capture/compare enable           register */
    using ccer = lp::io_register<lp::u32_t, base_address + 0x20>;
    /* Capture/Compare 3 output               Polarity */
    using ccer_cc4p = lp::assoc_bit<ccer, 13>;
    /* Capture/Compare 4 output               enable */
    using ccer_cc4e = lp::assoc_bit<ccer, 12>;
    /* Capture/Compare 3 output               Polarity */
    using ccer_cc3np = lp::assoc_bit<ccer, 11>;
    /* Capture/Compare 3 complementary output               enable */
    using ccer_cc3ne = lp::assoc_bit<ccer, 10>;
    /* Capture/Compare 3 output               Polarity */
    using ccer_cc3p = lp::assoc_bit<ccer, 9>;
    /* Capture/Compare 3 output               enable */
    using ccer_cc3e = lp::assoc_bit<ccer, 8>;
    /* Capture/Compare 2 output               Polarity */
    using ccer_cc2np = lp::assoc_bit<ccer, 7>;
    /* Capture/Compare 2 complementary output               enable */
    using ccer_cc2ne = lp::assoc_bit<ccer, 6>;
    /* Capture/Compare 2 output               Polarity */
    using ccer_cc2p = lp::assoc_bit<ccer, 5>;
    /* Capture/Compare 2 output               enable */
    using ccer_cc2e = lp::assoc_bit<ccer, 4>;
    /* Capture/Compare 1 output               Polarity */
    using ccer_cc1np = lp::assoc_bit<ccer, 3>;
    /* Capture/Compare 1 complementary output               enable */
    using ccer_cc1ne = lp::assoc_bit<ccer, 2>;
    /* Capture/Compare 1 output               Polarity */
    using ccer_cc1p = lp::assoc_bit<ccer, 1>;
    /* Capture/Compare 1 output               enable */
    using ccer_cc1e = lp::assoc_bit<ccer, 0>;


    /* counter */
    using cnt = lp::io_register<lp::u32_t, base_address + 0x24>;
    /* counter value */
    using cnt_cnt = lp::assoc_bit<cnt, 0, 16>;


    /* prescaler */
    using psc = lp::io_register<lp::u32_t, base_address + 0x28>;
    /* Prescaler value */
    using psc_psc = lp::assoc_bit<psc, 0, 16>;


    /* auto-reload register */
    using arr = lp::io_register<lp::u32_t, base_address + 0x2c>;
    /* Auto-reload value */
    using arr_arr = lp::assoc_bit<arr, 0, 16>;


    /* repetition counter register */
    using rcr = lp::io_register<lp::u32_t, base_address + 0x30>;
    /* Repetition counter value */
    using rcr_rep = lp::assoc_bit<rcr, 0, 8>;


    /* capture/compare register 1 */
    using ccr1 = lp::io_register<lp::u32_t, base_address + 0x34>;
    /* Capture/Compare 1 value */
    using ccr1_ccr1 = lp::assoc_bit<ccr1, 0, 16>;


    /* capture/compare register 2 */
    using ccr2 = lp::io_register<lp::u32_t, base_address + 0x38>;
    /* Capture/Compare 2 value */
    using ccr2_ccr2 = lp::assoc_bit<ccr2, 0, 16>;


    /* capture/compare register 3 */
    using ccr3 = lp::io_register<lp::u32_t, base_address + 0x3c>;
    /* Capture/Compare value */
    using ccr3_ccr3 = lp::assoc_bit<ccr3, 0, 16>;


    /* capture/compare register 4 */
    using ccr4 = lp::io_register<lp::u32_t, base_address + 0x40>;
    /* Capture/Compare value */
    using ccr4_ccr4 = lp::assoc_bit<ccr4, 0, 16>;


    /* break and dead-time register */
    using bdtr = lp::io_register<lp::u32_t, base_address + 0x44>;
    /* Main output enable */
    using bdtr_moe = lp::assoc_bit<bdtr, 15>;
    /* Automatic output enable */
    using bdtr_aoe = lp::assoc_bit<bdtr, 14>;
    /* Break polarity */
    using bdtr_bkp = lp::assoc_bit<bdtr, 13>;
    /* Break enable */
    using bdtr_bke = lp::assoc_bit<bdtr, 12>;
    /* Off-state selection for Run               mode */
    using bdtr_ossr = lp::assoc_bit<bdtr, 11>;
    /* Off-state selection for Idle               mode */
    using bdtr_ossi = lp::assoc_bit<bdtr, 10>;
    /* Lock configuration */
    using bdtr_lock = lp::assoc_bit<bdtr, 8, 2>;
    /* Dead-time generator setup */
    using bdtr_dtg = lp::assoc_bit<bdtr, 0, 8>;


    /* DMA control register */
    using dcr = lp::io_register<lp::u32_t, base_address + 0x48>;
    /* DMA burst length */
    using dcr_dbl = lp::assoc_bit<dcr, 8, 5>;
    /* DMA base address */
    using dcr_dba = lp::assoc_bit<dcr, 0, 5>;


    /* DMA address for full transfer */
    using dmar = lp::io_register<lp::u32_t, base_address + 0x4c>;
    /* DMA register for burst               accesses */
    using dmar_dmab = lp::assoc_bit<dmar, 0, 16>;


    /* DMA address for full transfer */
    using or1 = lp::io_register<lp::u32_t, base_address + 0x50>;
    /* External trigger remap on ADC1 analog               watchdog */
    using or1_etr_adc1_rmp = lp::assoc_bit<or1, 0, 2>;
    /* External trigger remap on ADC3 analog               watchdog */
    using or1_etr_adc3_rmp = lp::assoc_bit<or1, 2, 2>;
    /* Input Capture 1 remap */
    using or1_ti1_rmp = lp::assoc_bit<or1, 4>;


    /* capture/compare mode register 2 (output           mode) */
    using ccmr3_output = lp::io_register<lp::u32_t, base_address + 0x54>;
    /* Output Compare 6 mode bit               3 */
    using ccmr3_output_oc6m_bit3 = lp::assoc_bit<ccmr3_output, 24>;
    /* Output Compare 5 mode bit               3 */
    using ccmr3_output_oc5m_bit3 = lp::assoc_bit<ccmr3_output, 16, 3>;
    /* Output compare 6 clear               enable */
    using ccmr3_output_oc6ce = lp::assoc_bit<ccmr3_output, 15>;
    /* Output compare 6 mode */
    using ccmr3_output_oc6m = lp::assoc_bit<ccmr3_output, 12, 3>;
    /* Output compare 6 preload               enable */
    using ccmr3_output_oc6pe = lp::assoc_bit<ccmr3_output, 11>;
    /* Output compare 6 fast               enable */
    using ccmr3_output_oc6fe = lp::assoc_bit<ccmr3_output, 10>;
    /* Output compare 5 clear               enable */
    using ccmr3_output_oc5ce = lp::assoc_bit<ccmr3_output, 7>;
    /* Output compare 5 mode */
    using ccmr3_output_oc5m = lp::assoc_bit<ccmr3_output, 4, 3>;
    /* Output compare 5 preload               enable */
    using ccmr3_output_oc5pe = lp::assoc_bit<ccmr3_output, 3>;
    /* Output compare 5 fast               enable */
    using ccmr3_output_oc5fe = lp::assoc_bit<ccmr3_output, 2>;


    /* capture/compare register 4 */
    using ccr5 = lp::io_register<lp::u32_t, base_address + 0x58>;
    /* Capture/Compare value */
    using ccr5_ccr5 = lp::assoc_bit<ccr5, 0, 16>;
    /* Group Channel 5 and Channel               1 */
    using ccr5_gc5c1 = lp::assoc_bit<ccr5, 29>;
    /* Group Channel 5 and Channel               2 */
    using ccr5_gc5c2 = lp::assoc_bit<ccr5, 30>;
    /* Group Channel 5 and Channel               3 */
    using ccr5_gc5c3 = lp::assoc_bit<ccr5, 31>;


    /* capture/compare register 4 */
    using ccr6 = lp::io_register<lp::u32_t, base_address + 0x5c>;
    /* Capture/Compare value */
    using ccr6_ccr6 = lp::assoc_bit<ccr6, 0, 16>;


    /* DMA address for full transfer */
    using or2 = lp::io_register<lp::u32_t, base_address + 0x60>;
    /* BRK BKIN input enable */
    using or2_bkine = lp::assoc_bit<or2, 0>;
    /* BRK COMP1 enable */
    using or2_bkcmp1e = lp::assoc_bit<or2, 1>;
    /* BRK COMP2 enable */
    using or2_bkcmp2e = lp::assoc_bit<or2, 2>;
    /* BRK DFSDM_BREAK0 enable */
    using or2_bkdfbk0e = lp::assoc_bit<or2, 8>;
    /* BRK BKIN input polarity */
    using or2_bkinp = lp::assoc_bit<or2, 9>;
    /* BRK COMP1 input polarity */
    using or2_bkcmp1p = lp::assoc_bit<or2, 10>;
    /* BRK COMP2 input polarity */
    using or2_bkcmp2p = lp::assoc_bit<or2, 11>;
    /* ETR source selection */
    using or2_etrsel = lp::assoc_bit<or2, 14, 3>;


    /* DMA address for full transfer */
    using or3 = lp::io_register<lp::u32_t, base_address + 0x64>;
    /* BRK2 BKIN input enable */
    using or3_bk2ine = lp::assoc_bit<or3, 0>;
    /* BRK2 COMP1 enable */
    using or3_bk2cmp1e = lp::assoc_bit<or3, 1>;
    /* BRK2 COMP2 enable */
    using or3_bk2cmp2e = lp::assoc_bit<or3, 2>;
    /* BRK2 DFSDM_BREAK0 enable */
    using or3_bk2dfbk0e = lp::assoc_bit<or3, 8>;
    /* BRK2 BKIN input polarity */
    using or3_bk2inp = lp::assoc_bit<or3, 9>;
    /* BRK2 COMP1 input polarity */
    using or3_bk2cmp1p = lp::assoc_bit<or3, 10>;
    /* BRK2 COMP2 input polarity */
    using or3_bk2cmp2p = lp::assoc_bit<or3, 11>;


};

/* Basic-timers */
template <lp::addr_t base_address>
struct tim6_t {
    /* control register 1 */
    using cr1 = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* Auto-reload preload enable */
    using cr1_arpe = lp::assoc_bit<cr1, 7>;
    /* One-pulse mode */
    using cr1_opm = lp::assoc_bit<cr1, 3>;
    /* Update request source */
    using cr1_urs = lp::assoc_bit<cr1, 2>;
    /* Update disable */
    using cr1_udis = lp::assoc_bit<cr1, 1>;
    /* Counter enable */
    using cr1_cen = lp::assoc_bit<cr1, 0>;


    /* control register 2 */
    using cr2 = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* Master mode selection */
    using cr2_mms = lp::assoc_bit<cr2, 4, 3>;


    /* DMA/Interrupt enable register */
    using dier = lp::io_register<lp::u32_t, base_address + 0xc>;
    /* Update DMA request enable */
    using dier_ude = lp::assoc_bit<dier, 8>;
    /* Update interrupt enable */
    using dier_uie = lp::assoc_bit<dier, 0>;


    /* status register */
    using sr = lp::io_register<lp::u32_t, base_address + 0x10>;
    /* Update interrupt flag */
    using sr_uif = lp::assoc_bit<sr, 0>;


    /* event generation register */
    using egr = lp::io_register<lp::u32_t, base_address + 0x14>;
    /* Update generation */
    using egr_ug = lp::assoc_bit<egr, 0>;


    /* counter */
    using cnt = lp::io_register<lp::u32_t, base_address + 0x24>;
    /* Low counter value */
    using cnt_cnt = lp::assoc_bit<cnt, 0, 16>;


    /* prescaler */
    using psc = lp::io_register<lp::u32_t, base_address + 0x28>;
    /* Prescaler value */
    using psc_psc = lp::assoc_bit<psc, 0, 16>;


    /* auto-reload register */
    using arr = lp::io_register<lp::u32_t, base_address + 0x2c>;
    /* Low Auto-reload value */
    using arr_arr = lp::assoc_bit<arr, 0, 16>;


};

using tim2 = tim_t<0x40000000>;
using tim3 = tim_t<0x40000400>;
using tim4 = tim_t<0x40000800>;
using tim5 = tim_t<0x40000c00>;
using tim15 = tim15_t<0x40014000>;
using tim16 = tim16_t<0x40014400>;
using tim17 = tim16_t<0x40014800>;
using tim1 = tim1_t<0x40012c00>;
using tim8 = tim1_t<0x40013400>;
using tim6 = tim6_t<0x40001000>;
using tim7 = tim6_t<0x40001400>;

#endif // TIM_HH
