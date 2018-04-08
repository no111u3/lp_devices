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
 * Hardware support for adc
 * @file adc.hh
 * @author Boris Vinogradov
 */

#include <associate_bit.hh>
#include <io_register.hh>
#include <types.hh>

#ifndef ADC_HH
#define ADC_HH

/* Analog-to-Digital Converter */
template <lp::addr_t base_address>
struct adc_t {
    /* interrupt and status register */
    using isr = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* JQOVF */
    using isr_jqovf = lp::assoc_bit<isr, 10>;
    /* AWD3 */
    using isr_awd3 = lp::assoc_bit<isr, 9>;
    /* AWD2 */
    using isr_awd2 = lp::assoc_bit<isr, 8>;
    /* AWD1 */
    using isr_awd1 = lp::assoc_bit<isr, 7>;
    /* JEOS */
    using isr_jeos = lp::assoc_bit<isr, 6>;
    /* JEOC */
    using isr_jeoc = lp::assoc_bit<isr, 5>;
    /* OVR */
    using isr_ovr = lp::assoc_bit<isr, 4>;
    /* EOS */
    using isr_eos = lp::assoc_bit<isr, 3>;
    /* EOC */
    using isr_eoc = lp::assoc_bit<isr, 2>;
    /* EOSMP */
    using isr_eosmp = lp::assoc_bit<isr, 1>;
    /* ADRDY */
    using isr_adrdy = lp::assoc_bit<isr, 0>;


    /* interrupt enable register */
    using ier = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* JQOVFIE */
    using ier_jqovfie = lp::assoc_bit<ier, 10>;
    /* AWD3IE */
    using ier_awd3ie = lp::assoc_bit<ier, 9>;
    /* AWD2IE */
    using ier_awd2ie = lp::assoc_bit<ier, 8>;
    /* AWD1IE */
    using ier_awd1ie = lp::assoc_bit<ier, 7>;
    /* JEOSIE */
    using ier_jeosie = lp::assoc_bit<ier, 6>;
    /* JEOCIE */
    using ier_jeocie = lp::assoc_bit<ier, 5>;
    /* OVRIE */
    using ier_ovrie = lp::assoc_bit<ier, 4>;
    /* EOSIE */
    using ier_eosie = lp::assoc_bit<ier, 3>;
    /* EOCIE */
    using ier_eocie = lp::assoc_bit<ier, 2>;
    /* EOSMPIE */
    using ier_eosmpie = lp::assoc_bit<ier, 1>;
    /* ADRDYIE */
    using ier_adrdyie = lp::assoc_bit<ier, 0>;


    /* control register */
    using cr = lp::io_register<lp::u32_t, base_address + 0x8>;
    /* ADCAL */
    using cr_adcal = lp::assoc_bit<cr, 31>;
    /* ADCALDIF */
    using cr_adcaldif = lp::assoc_bit<cr, 30>;
    /* DEEPPWD */
    using cr_deeppwd = lp::assoc_bit<cr, 29>;
    /* ADVREGEN */
    using cr_advregen = lp::assoc_bit<cr, 28>;
    /* JADSTP */
    using cr_jadstp = lp::assoc_bit<cr, 5>;
    /* ADSTP */
    using cr_adstp = lp::assoc_bit<cr, 4>;
    /* JADSTART */
    using cr_jadstart = lp::assoc_bit<cr, 3>;
    /* ADSTART */
    using cr_adstart = lp::assoc_bit<cr, 2>;
    /* ADDIS */
    using cr_addis = lp::assoc_bit<cr, 1>;
    /* ADEN */
    using cr_aden = lp::assoc_bit<cr, 0>;


    /* configuration register */
    using cfgr = lp::io_register<lp::u32_t, base_address + 0xc>;
    /* Injected Queue disable */
    using cfgr_jqdis = lp::assoc_bit<cfgr, 31>;
    /* AWDCH1CH */
    using cfgr_awdch1ch = lp::assoc_bit<cfgr, 26, 5>;
    /* JAUTO */
    using cfgr_jauto = lp::assoc_bit<cfgr, 25>;
    /* JAWD1EN */
    using cfgr_jawd1en = lp::assoc_bit<cfgr, 24>;
    /* AWD1EN */
    using cfgr_awd1en = lp::assoc_bit<cfgr, 23>;
    /* AWD1SGL */
    using cfgr_awd1sgl = lp::assoc_bit<cfgr, 22>;
    /* JQM */
    using cfgr_jqm = lp::assoc_bit<cfgr, 21>;
    /* JDISCEN */
    using cfgr_jdiscen = lp::assoc_bit<cfgr, 20>;
    /* DISCNUM */
    using cfgr_discnum = lp::assoc_bit<cfgr, 17, 3>;
    /* DISCEN */
    using cfgr_discen = lp::assoc_bit<cfgr, 16>;
    /* AUTDLY */
    using cfgr_autdly = lp::assoc_bit<cfgr, 14>;
    /* CONT */
    using cfgr_cont = lp::assoc_bit<cfgr, 13>;
    /* OVRMOD */
    using cfgr_ovrmod = lp::assoc_bit<cfgr, 12>;
    /* EXTEN */
    using cfgr_exten = lp::assoc_bit<cfgr, 10, 2>;
    /* EXTSEL */
    using cfgr_extsel = lp::assoc_bit<cfgr, 6, 4>;
    /* ALIGN */
    using cfgr_align = lp::assoc_bit<cfgr, 5>;
    /* RES */
    using cfgr_res = lp::assoc_bit<cfgr, 3, 2>;
    /* DFSDMCFG */
    using cfgr_dfsdmcfg = lp::assoc_bit<cfgr, 2>;
    /* DMACFG */
    using cfgr_dmacfg = lp::assoc_bit<cfgr, 1>;
    /* DMAEN */
    using cfgr_dmaen = lp::assoc_bit<cfgr, 0>;


    /* configuration register */
    using cfgr2 = lp::io_register<lp::u32_t, base_address + 0x10>;
    /* EXTEN */
    using cfgr2_rovsm = lp::assoc_bit<cfgr2, 10>;
    /* Triggered Regular               Oversampling */
    using cfgr2_trovs = lp::assoc_bit<cfgr2, 9>;
    /* ALIGN */
    using cfgr2_ovss = lp::assoc_bit<cfgr2, 5, 4>;
    /* RES */
    using cfgr2_ovsr = lp::assoc_bit<cfgr2, 2, 3>;
    /* DMACFG */
    using cfgr2_jovse = lp::assoc_bit<cfgr2, 1>;
    /* DMAEN */
    using cfgr2_rovse = lp::assoc_bit<cfgr2, 0>;


    /* sample time register 1 */
    using smpr1 = lp::io_register<lp::u32_t, base_address + 0x14>;
    /* SMP9 */
    using smpr1_smp9 = lp::assoc_bit<smpr1, 27, 3>;
    /* SMP8 */
    using smpr1_smp8 = lp::assoc_bit<smpr1, 24, 3>;
    /* SMP7 */
    using smpr1_smp7 = lp::assoc_bit<smpr1, 21, 3>;
    /* SMP6 */
    using smpr1_smp6 = lp::assoc_bit<smpr1, 18, 3>;
    /* SMP5 */
    using smpr1_smp5 = lp::assoc_bit<smpr1, 15, 3>;
    /* SMP4 */
    using smpr1_smp4 = lp::assoc_bit<smpr1, 12, 3>;
    /* SMP3 */
    using smpr1_smp3 = lp::assoc_bit<smpr1, 9, 3>;
    /* SMP2 */
    using smpr1_smp2 = lp::assoc_bit<smpr1, 6, 3>;
    /* SMP1 */
    using smpr1_smp1 = lp::assoc_bit<smpr1, 3, 3>;
    /* Addition of one clock cycle to the               sampling time */
    using smpr1_smpplus = lp::assoc_bit<smpr1, 31>;
    /* SMP0 */
    using smpr1_smp0 = lp::assoc_bit<smpr1, 0, 3>;


    /* sample time register 2 */
    using smpr2 = lp::io_register<lp::u32_t, base_address + 0x18>;
    /* SMP18 */
    using smpr2_smp18 = lp::assoc_bit<smpr2, 24, 3>;
    /* SMP17 */
    using smpr2_smp17 = lp::assoc_bit<smpr2, 21, 3>;
    /* SMP16 */
    using smpr2_smp16 = lp::assoc_bit<smpr2, 18, 3>;
    /* SMP15 */
    using smpr2_smp15 = lp::assoc_bit<smpr2, 15, 3>;
    /* SMP14 */
    using smpr2_smp14 = lp::assoc_bit<smpr2, 12, 3>;
    /* SMP13 */
    using smpr2_smp13 = lp::assoc_bit<smpr2, 9, 3>;
    /* SMP12 */
    using smpr2_smp12 = lp::assoc_bit<smpr2, 6, 3>;
    /* SMP11 */
    using smpr2_smp11 = lp::assoc_bit<smpr2, 3, 3>;
    /* SMP10 */
    using smpr2_smp10 = lp::assoc_bit<smpr2, 0, 3>;


    /* watchdog threshold register 1 */
    using tr1 = lp::io_register<lp::u32_t, base_address + 0x20>;
    /* HT1 */
    using tr1_ht1 = lp::assoc_bit<tr1, 16, 12>;
    /* LT1 */
    using tr1_lt1 = lp::assoc_bit<tr1, 0, 12>;


    /* watchdog threshold register */
    using tr2 = lp::io_register<lp::u32_t, base_address + 0x24>;
    /* HT2 */
    using tr2_ht2 = lp::assoc_bit<tr2, 16, 8>;
    /* LT2 */
    using tr2_lt2 = lp::assoc_bit<tr2, 0, 8>;


    /* watchdog threshold register 3 */
    using tr3 = lp::io_register<lp::u32_t, base_address + 0x28>;
    /* HT3 */
    using tr3_ht3 = lp::assoc_bit<tr3, 16, 8>;
    /* LT3 */
    using tr3_lt3 = lp::assoc_bit<tr3, 0, 8>;


    /* regular sequence register 1 */
    using sqr1 = lp::io_register<lp::u32_t, base_address + 0x30>;
    /* SQ4 */
    using sqr1_sq4 = lp::assoc_bit<sqr1, 24, 5>;
    /* SQ3 */
    using sqr1_sq3 = lp::assoc_bit<sqr1, 18, 5>;
    /* SQ2 */
    using sqr1_sq2 = lp::assoc_bit<sqr1, 12, 5>;
    /* SQ1 */
    using sqr1_sq1 = lp::assoc_bit<sqr1, 6, 5>;
    /* Regular channel sequence               length */
    using sqr1_l = lp::assoc_bit<sqr1, 0, 4>;


    /* regular sequence register 2 */
    using sqr2 = lp::io_register<lp::u32_t, base_address + 0x34>;
    /* SQ9 */
    using sqr2_sq9 = lp::assoc_bit<sqr2, 24, 5>;
    /* SQ8 */
    using sqr2_sq8 = lp::assoc_bit<sqr2, 18, 5>;
    /* SQ7 */
    using sqr2_sq7 = lp::assoc_bit<sqr2, 12, 5>;
    /* SQ6 */
    using sqr2_sq6 = lp::assoc_bit<sqr2, 6, 5>;
    /* SQ5 */
    using sqr2_sq5 = lp::assoc_bit<sqr2, 0, 5>;


    /* regular sequence register 3 */
    using sqr3 = lp::io_register<lp::u32_t, base_address + 0x38>;
    /* SQ14 */
    using sqr3_sq14 = lp::assoc_bit<sqr3, 24, 5>;
    /* SQ13 */
    using sqr3_sq13 = lp::assoc_bit<sqr3, 18, 5>;
    /* SQ12 */
    using sqr3_sq12 = lp::assoc_bit<sqr3, 12, 5>;
    /* SQ11 */
    using sqr3_sq11 = lp::assoc_bit<sqr3, 6, 5>;
    /* SQ10 */
    using sqr3_sq10 = lp::assoc_bit<sqr3, 0, 5>;


    /* regular sequence register 4 */
    using sqr4 = lp::io_register<lp::u32_t, base_address + 0x3c>;
    /* SQ16 */
    using sqr4_sq16 = lp::assoc_bit<sqr4, 6, 5>;
    /* SQ15 */
    using sqr4_sq15 = lp::assoc_bit<sqr4, 0, 5>;


    /* regular Data Register */
    using dr = lp::io_register<lp::u32_t, base_address + 0x40>;
    /* Regular Data converted */
    using dr_rdata = lp::assoc_bit<dr, 0, 16>;


    /* injected sequence register */
    using jsqr = lp::io_register<lp::u32_t, base_address + 0x4c>;
    /* JSQ4 */
    using jsqr_jsq4 = lp::assoc_bit<jsqr, 26, 5>;
    /* JSQ3 */
    using jsqr_jsq3 = lp::assoc_bit<jsqr, 20, 5>;
    /* JSQ2 */
    using jsqr_jsq2 = lp::assoc_bit<jsqr, 14, 5>;
    /* JSQ1 */
    using jsqr_jsq1 = lp::assoc_bit<jsqr, 8, 5>;
    /* JEXTEN */
    using jsqr_jexten = lp::assoc_bit<jsqr, 6, 2>;
    /* JEXTSEL */
    using jsqr_jextsel = lp::assoc_bit<jsqr, 2, 4>;
    /* JL */
    using jsqr_jl = lp::assoc_bit<jsqr, 0, 2>;


    /* offset register 1 */
    using ofr1 = lp::io_register<lp::u32_t, base_address + 0x60>;
    /* OFFSET1_EN */
    using ofr1_offset1_en = lp::assoc_bit<ofr1, 31>;
    /* OFFSET1_CH */
    using ofr1_offset1_ch = lp::assoc_bit<ofr1, 26, 5>;
    /* OFFSET1 */
    using ofr1_offset1 = lp::assoc_bit<ofr1, 0, 12>;


    /* offset register 2 */
    using ofr2 = lp::io_register<lp::u32_t, base_address + 0x64>;
    /* OFFSET2_EN */
    using ofr2_offset2_en = lp::assoc_bit<ofr2, 31>;
    /* OFFSET2_CH */
    using ofr2_offset2_ch = lp::assoc_bit<ofr2, 26, 5>;
    /* OFFSET2 */
    using ofr2_offset2 = lp::assoc_bit<ofr2, 0, 12>;


    /* offset register 3 */
    using ofr3 = lp::io_register<lp::u32_t, base_address + 0x68>;
    /* OFFSET3_EN */
    using ofr3_offset3_en = lp::assoc_bit<ofr3, 31>;
    /* OFFSET3_CH */
    using ofr3_offset3_ch = lp::assoc_bit<ofr3, 26, 5>;
    /* OFFSET3 */
    using ofr3_offset3 = lp::assoc_bit<ofr3, 0, 12>;


    /* offset register 4 */
    using ofr4 = lp::io_register<lp::u32_t, base_address + 0x6c>;
    /* OFFSET4_EN */
    using ofr4_offset4_en = lp::assoc_bit<ofr4, 31>;
    /* OFFSET4_CH */
    using ofr4_offset4_ch = lp::assoc_bit<ofr4, 26, 5>;
    /* OFFSET4 */
    using ofr4_offset4 = lp::assoc_bit<ofr4, 0, 12>;


    /* injected data register 1 */
    using jdr1 = lp::io_register<lp::u32_t, base_address + 0x80>;
    /* JDATA1 */
    using jdr1_jdata1 = lp::assoc_bit<jdr1, 0, 16>;


    /* injected data register 2 */
    using jdr2 = lp::io_register<lp::u32_t, base_address + 0x84>;
    /* JDATA2 */
    using jdr2_jdata2 = lp::assoc_bit<jdr2, 0, 16>;


    /* injected data register 3 */
    using jdr3 = lp::io_register<lp::u32_t, base_address + 0x88>;
    /* JDATA3 */
    using jdr3_jdata3 = lp::assoc_bit<jdr3, 0, 16>;


    /* injected data register 4 */
    using jdr4 = lp::io_register<lp::u32_t, base_address + 0x8c>;
    /* JDATA4 */
    using jdr4_jdata4 = lp::assoc_bit<jdr4, 0, 16>;


    /* Analog Watchdog 2 Configuration           Register */
    using awd2cr = lp::io_register<lp::u32_t, base_address + 0xa0>;
    /* AWD2CH */
    using awd2cr_awd2ch = lp::assoc_bit<awd2cr, 0, 19>;


    /* Analog Watchdog 3 Configuration           Register */
    using awd3cr = lp::io_register<lp::u32_t, base_address + 0xa4>;
    /* AWD3CH */
    using awd3cr_awd3ch = lp::assoc_bit<awd3cr, 0, 19>;


    /* Differential Mode Selection Register           2 */
    using difsel = lp::io_register<lp::u32_t, base_address + 0xb0>;
    /* Differential mode for channels               0 */
    using difsel_difsel_0 = lp::assoc_bit<difsel, 0>;
    /* Differential mode for channels 15 to               1 */
    using difsel_difsel_1_15 = lp::assoc_bit<difsel, 1, 15>;
    /* Differential mode for channels 18 to               16 */
    using difsel_difsel_16_18 = lp::assoc_bit<difsel, 16, 3>;


    /* Calibration Factors */
    using calfact = lp::io_register<lp::u32_t, base_address + 0xb4>;
    /* CALFACT_D */
    using calfact_calfact_d = lp::assoc_bit<calfact, 16, 7>;
    /* CALFACT_S */
    using calfact_calfact_s = lp::assoc_bit<calfact, 0, 7>;


};

/* Analog-to-Digital Converter */
template <lp::addr_t base_address>
struct adc_common_t {
    /* ADC Common status register */
    using csr = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* ADDRDY_MST */
    using csr_addrdy_mst = lp::assoc_bit<csr, 0>;
    /* EOSMP_MST */
    using csr_eosmp_mst = lp::assoc_bit<csr, 1>;
    /* EOC_MST */
    using csr_eoc_mst = lp::assoc_bit<csr, 2>;
    /* EOS_MST */
    using csr_eos_mst = lp::assoc_bit<csr, 3>;
    /* OVR_MST */
    using csr_ovr_mst = lp::assoc_bit<csr, 4>;
    /* JEOC_MST */
    using csr_jeoc_mst = lp::assoc_bit<csr, 5>;
    /* JEOS_MST */
    using csr_jeos_mst = lp::assoc_bit<csr, 6>;
    /* AWD1_MST */
    using csr_awd1_mst = lp::assoc_bit<csr, 7>;
    /* AWD2_MST */
    using csr_awd2_mst = lp::assoc_bit<csr, 8>;
    /* AWD3_MST */
    using csr_awd3_mst = lp::assoc_bit<csr, 9>;
    /* JQOVF_MST */
    using csr_jqovf_mst = lp::assoc_bit<csr, 10>;
    /* ADRDY_SLV */
    using csr_adrdy_slv = lp::assoc_bit<csr, 16>;
    /* EOSMP_SLV */
    using csr_eosmp_slv = lp::assoc_bit<csr, 17>;
    /* End of regular conversion of the slave               ADC */
    using csr_eoc_slv = lp::assoc_bit<csr, 18>;
    /* End of regular sequence flag of the               slave ADC */
    using csr_eos_slv = lp::assoc_bit<csr, 19>;
    /* Overrun flag of the slave               ADC */
    using csr_ovr_slv = lp::assoc_bit<csr, 20>;
    /* End of injected conversion flag of the               slave ADC */
    using csr_jeoc_slv = lp::assoc_bit<csr, 21>;
    /* End of injected sequence flag of the               slave ADC */
    using csr_jeos_slv = lp::assoc_bit<csr, 22>;
    /* Analog watchdog 1 flag of the slave               ADC */
    using csr_awd1_slv = lp::assoc_bit<csr, 23>;
    /* Analog watchdog 2 flag of the slave               ADC */
    using csr_awd2_slv = lp::assoc_bit<csr, 24>;
    /* Analog watchdog 3 flag of the slave               ADC */
    using csr_awd3_slv = lp::assoc_bit<csr, 25>;
    /* Injected Context Queue Overflow flag of               the slave ADC */
    using csr_jqovf_slv = lp::assoc_bit<csr, 26>;


    /* ADC common control register */
    using ccr = lp::io_register<lp::u32_t, base_address + 0x8>;
    /* Dual ADC mode selection */
    using ccr_dual = lp::assoc_bit<ccr, 0, 5>;
    /* Delay between 2 sampling               phases */
    using ccr_delay = lp::assoc_bit<ccr, 8, 4>;
    /* DMA configuration (for multi-ADC               mode) */
    using ccr_dmacfg = lp::assoc_bit<ccr, 13>;
    /* Direct memory access mode for multi ADC               mode */
    using ccr_mdma = lp::assoc_bit<ccr, 14, 2>;
    /* ADC clock mode */
    using ccr_ckmode = lp::assoc_bit<ccr, 16, 2>;
    /* VREFINT enable */
    using ccr_vrefen = lp::assoc_bit<ccr, 22>;
    /* CH17 selection */
    using ccr_ch17sel = lp::assoc_bit<ccr, 23>;
    /* CH18 selection */
    using ccr_ch18sel = lp::assoc_bit<ccr, 24>;
    /* ADC prescaler */
    using ccr_presc = lp::assoc_bit<ccr, 18, 4>;


    /* ADC common regular data register for dual           and triple modes */
    using cdr = lp::io_register<lp::u32_t, base_address + 0xc>;
    /* Regular data of the slave               ADC */
    using cdr_rdata_slv = lp::assoc_bit<cdr, 16, 16>;
    /* Regular data of the master               ADC */
    using cdr_rdata_mst = lp::assoc_bit<cdr, 0, 16>;


};

using adc1 = adc_t<0x50040000>;
using adc2 = adc_t<0x50040100>;
using adc3 = adc_t<0x50040200>;
using adc_common = adc_common_t<0x50040300>;

#endif // ADC_HH
