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
 * Hardware support for dac
 * @file dac.hh
 * @author Boris Vinogradov
 */

#include <associate_bit.hh>
#include <io_register.hh>
#include <types.hh>

#ifndef DAC_HH
#define DAC_HH

/* Digital-to-analog converter */
template <lp::addr_t base_address>
struct dac_t {
    /* control register */
    using cr = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* DAC channel1 enable */
    using cr_en1 = lp::assoc_bit<cr, 0>;
    /* DAC channel1 trigger               enable */
    using cr_ten1 = lp::assoc_bit<cr, 2>;
    /* DAC channel1 trigger               selection */
    using cr_tsel1 = lp::assoc_bit<cr, 3, 3>;
    /* DAC channel1 noise/triangle wave               generation enable */
    using cr_wave1 = lp::assoc_bit<cr, 6, 2>;
    /* DAC channel1 mask/amplitude               selector */
    using cr_mamp1 = lp::assoc_bit<cr, 8, 4>;
    /* DAC channel1 DMA enable */
    using cr_dmaen1 = lp::assoc_bit<cr, 12>;
    /* DAC channel1 DMA Underrun Interrupt               enable */
    using cr_dmaudrie1 = lp::assoc_bit<cr, 13>;
    /* DAC Channel 1 calibration               enable */
    using cr_cen1 = lp::assoc_bit<cr, 14>;
    /* DAC channel2 enable */
    using cr_en2 = lp::assoc_bit<cr, 16>;
    /* DAC channel2 trigger               enable */
    using cr_ten2 = lp::assoc_bit<cr, 18>;
    /* DAC channel2 trigger               selection */
    using cr_tsel2 = lp::assoc_bit<cr, 19, 3>;
    /* DAC channel2 noise/triangle wave               generation enable */
    using cr_wave2 = lp::assoc_bit<cr, 22, 2>;
    /* DAC channel2 mask/amplitude               selector */
    using cr_mamp2 = lp::assoc_bit<cr, 24, 4>;
    /* DAC channel2 DMA enable */
    using cr_dmaen2 = lp::assoc_bit<cr, 28>;
    /* DAC channel2 DMA underrun interrupt               enable */
    using cr_dmaudrie2 = lp::assoc_bit<cr, 29>;
    /* DAC Channel 2 calibration               enable */
    using cr_cen2 = lp::assoc_bit<cr, 30>;


    /* software trigger register */
    using swtrigr = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* DAC channel1 software               trigger */
    using swtrigr_swtrig1 = lp::assoc_bit<swtrigr, 0>;
    /* DAC channel2 software               trigger */
    using swtrigr_swtrig2 = lp::assoc_bit<swtrigr, 1>;


    /* channel1 12-bit right-aligned data holding           register */
    using dhr12r1 = lp::io_register<lp::u32_t, base_address + 0x8>;
    /* DAC channel1 12-bit right-aligned               data */
    using dhr12r1_dacc1dhr = lp::assoc_bit<dhr12r1, 0, 12>;


    /* channel1 12-bit left-aligned data holding           register */
    using dhr12l1 = lp::io_register<lp::u32_t, base_address + 0xc>;
    /* DAC channel1 12-bit left-aligned               data */
    using dhr12l1_dacc1dhr = lp::assoc_bit<dhr12l1, 4, 12>;


    /* channel1 8-bit right-aligned data holding           register */
    using dhr8r1 = lp::io_register<lp::u32_t, base_address + 0x10>;
    /* DAC channel1 8-bit right-aligned               data */
    using dhr8r1_dacc1dhr = lp::assoc_bit<dhr8r1, 0, 8>;


    /* channel2 12-bit right aligned data holding           register */
    using dhr12r2 = lp::io_register<lp::u32_t, base_address + 0x14>;
    /* DAC channel2 12-bit right-aligned               data */
    using dhr12r2_dacc2dhr = lp::assoc_bit<dhr12r2, 0, 12>;


    /* channel2 12-bit left aligned data holding           register */
    using dhr12l2 = lp::io_register<lp::u32_t, base_address + 0x18>;
    /* DAC channel2 12-bit left-aligned               data */
    using dhr12l2_dacc2dhr = lp::assoc_bit<dhr12l2, 4, 12>;


    /* channel2 8-bit right-aligned data holding           register */
    using dhr8r2 = lp::io_register<lp::u32_t, base_address + 0x1c>;
    /* DAC channel2 8-bit right-aligned               data */
    using dhr8r2_dacc2dhr = lp::assoc_bit<dhr8r2, 0, 8>;


    /* Dual DAC 12-bit right-aligned data holding           register */
    using dhr12rd = lp::io_register<lp::u32_t, base_address + 0x20>;
    /* DAC channel1 12-bit right-aligned               data */
    using dhr12rd_dacc1dhr = lp::assoc_bit<dhr12rd, 0, 12>;
    /* DAC channel2 12-bit right-aligned               data */
    using dhr12rd_dacc2dhr = lp::assoc_bit<dhr12rd, 16, 12>;


    /* DUAL DAC 12-bit left aligned data holding           register */
    using dhr12ld = lp::io_register<lp::u32_t, base_address + 0x24>;
    /* DAC channel1 12-bit left-aligned               data */
    using dhr12ld_dacc1dhr = lp::assoc_bit<dhr12ld, 4, 12>;
    /* DAC channel2 12-bit left-aligned               data */
    using dhr12ld_dacc2dhr = lp::assoc_bit<dhr12ld, 20, 12>;


    /* DUAL DAC 8-bit right aligned data holding           register */
    using dhr8rd = lp::io_register<lp::u32_t, base_address + 0x28>;
    /* DAC channel1 8-bit right-aligned               data */
    using dhr8rd_dacc1dhr = lp::assoc_bit<dhr8rd, 0, 8>;
    /* DAC channel2 8-bit right-aligned               data */
    using dhr8rd_dacc2dhr = lp::assoc_bit<dhr8rd, 8, 8>;


    /* channel1 data output register */
    using dor1 = lp::io_register<lp::u32_t, base_address + 0x2c>;
    /* DAC channel1 data output */
    using dor1_dacc1dor = lp::assoc_bit<dor1, 0, 12>;


    /* channel2 data output register */
    using dor2 = lp::io_register<lp::u32_t, base_address + 0x30>;
    /* DAC channel2 data output */
    using dor2_dacc2dor = lp::assoc_bit<dor2, 0, 12>;


    /* status register */
    using sr = lp::io_register<lp::u32_t, base_address + 0x34>;
    /* DAC channel1 DMA underrun               flag */
    using sr_dmaudr1 = lp::assoc_bit<sr, 13>;
    /* DAC Channel 1 calibration offset               status */
    using sr_cal_flag1 = lp::assoc_bit<sr, 14>;
    /* DAC Channel 1 busy writing sample time               flag */
    using sr_bwst1 = lp::assoc_bit<sr, 15>;
    /* DAC channel2 DMA underrun               flag */
    using sr_dmaudr2 = lp::assoc_bit<sr, 29>;
    /* DAC Channel 2 calibration offset               status */
    using sr_cal_flag2 = lp::assoc_bit<sr, 30>;
    /* DAC Channel 2 busy writing sample time               flag */
    using sr_bwst2 = lp::assoc_bit<sr, 31>;


    /* calibration control register */
    using ccr = lp::io_register<lp::u32_t, base_address + 0x38>;
    /* DAC Channel 1 offset trimming               value */
    using ccr_otrim1 = lp::assoc_bit<ccr, 0, 5>;
    /* DAC Channel 2 offset trimming               value */
    using ccr_otrim2 = lp::assoc_bit<ccr, 16, 5>;


    /* mode control register */
    using mcr = lp::io_register<lp::u32_t, base_address + 0x3c>;
    /* DAC Channel 1 mode */
    using mcr_mode1 = lp::assoc_bit<mcr, 0, 3>;
    /* DAC Channel 2 mode */
    using mcr_mode2 = lp::assoc_bit<mcr, 16, 3>;


    /* Sample and Hold sample time register           1 */
    using shsr1 = lp::io_register<lp::u32_t, base_address + 0x40>;
    /* DAC Channel 1 sample Time */
    using shsr1_tsample1 = lp::assoc_bit<shsr1, 0, 10>;


    /* Sample and Hold sample time register           2 */
    using shsr2 = lp::io_register<lp::u32_t, base_address + 0x44>;
    /* DAC Channel 2 sample Time */
    using shsr2_tsample2 = lp::assoc_bit<shsr2, 0, 10>;


    /* Sample and Hold hold time           register */
    using shhr = lp::io_register<lp::u32_t, base_address + 0x48>;
    /* DAC Channel 1 hold Time */
    using shhr_thold1 = lp::assoc_bit<shhr, 0, 10>;
    /* DAC Channel 2 hold time */
    using shhr_thold2 = lp::assoc_bit<shhr, 16, 10>;


    /* Sample and Hold refresh time           register */
    using shrr = lp::io_register<lp::u32_t, base_address + 0x4c>;
    /* DAC Channel 1 refresh Time */
    using shrr_trefresh1 = lp::assoc_bit<shrr, 0, 8>;
    /* DAC Channel 2 refresh Time */
    using shrr_trefresh2 = lp::assoc_bit<shrr, 16, 8>;


};

using dac = dac_t<0x40007400>;

#endif // DAC_HH
