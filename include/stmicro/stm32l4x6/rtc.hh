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
 * Hardware support for rtc
 * @file rtc.hh
 * @author Boris Vinogradov
 */

#include <associate_bit.hh>
#include <io_register.hh>
#include <types.hh>

#ifndef RTC_HH
#define RTC_HH

/* Real-time clock */
template <lp::addr_t base_address>
struct rtc_t {
    /* time register */
    using tr = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* AM/PM notation */
    using tr_pm = lp::assoc_bit<tr, 22>;
    /* Hour tens in BCD format */
    using tr_ht = lp::assoc_bit<tr, 20, 2>;
    /* Hour units in BCD format */
    using tr_hu = lp::assoc_bit<tr, 16, 4>;
    /* Minute tens in BCD format */
    using tr_mnt = lp::assoc_bit<tr, 12, 3>;
    /* Minute units in BCD format */
    using tr_mnu = lp::assoc_bit<tr, 8, 4>;
    /* Second tens in BCD format */
    using tr_st = lp::assoc_bit<tr, 4, 3>;
    /* Second units in BCD format */
    using tr_su = lp::assoc_bit<tr, 0, 4>;


    /* date register */
    using dr = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* Year tens in BCD format */
    using dr_yt = lp::assoc_bit<dr, 20, 4>;
    /* Year units in BCD format */
    using dr_yu = lp::assoc_bit<dr, 16, 4>;
    /* Week day units */
    using dr_wdu = lp::assoc_bit<dr, 13, 3>;
    /* Month tens in BCD format */
    using dr_mt = lp::assoc_bit<dr, 12>;
    /* Month units in BCD format */
    using dr_mu = lp::assoc_bit<dr, 8, 4>;
    /* Date tens in BCD format */
    using dr_dt = lp::assoc_bit<dr, 4, 2>;
    /* Date units in BCD format */
    using dr_du = lp::assoc_bit<dr, 0, 4>;


    /* control register */
    using cr = lp::io_register<lp::u32_t, base_address + 0x8>;
    /* Wakeup clock selection */
    using cr_wcksel = lp::assoc_bit<cr, 0, 3>;
    /* Time-stamp event active               edge */
    using cr_tsedge = lp::assoc_bit<cr, 3>;
    /* Reference clock detection enable (50 or               60 Hz) */
    using cr_refckon = lp::assoc_bit<cr, 4>;
    /* Bypass the shadow               registers */
    using cr_bypshad = lp::assoc_bit<cr, 5>;
    /* Hour format */
    using cr_fmt = lp::assoc_bit<cr, 6>;
    /* Alarm A enable */
    using cr_alrae = lp::assoc_bit<cr, 8>;
    /* Alarm B enable */
    using cr_alrbe = lp::assoc_bit<cr, 9>;
    /* Wakeup timer enable */
    using cr_wute = lp::assoc_bit<cr, 10>;
    /* Time stamp enable */
    using cr_tse = lp::assoc_bit<cr, 11>;
    /* Alarm A interrupt enable */
    using cr_alraie = lp::assoc_bit<cr, 12>;
    /* Alarm B interrupt enable */
    using cr_alrbie = lp::assoc_bit<cr, 13>;
    /* Wakeup timer interrupt               enable */
    using cr_wutie = lp::assoc_bit<cr, 14>;
    /* Time-stamp interrupt               enable */
    using cr_tsie = lp::assoc_bit<cr, 15>;
    /* Add 1 hour (summer time               change) */
    using cr_add1h = lp::assoc_bit<cr, 16>;
    /* Subtract 1 hour (winter time               change) */
    using cr_sub1h = lp::assoc_bit<cr, 17>;
    /* Backup */
    using cr_bkp = lp::assoc_bit<cr, 18>;
    /* Calibration output               selection */
    using cr_cosel = lp::assoc_bit<cr, 19>;
    /* Output polarity */
    using cr_pol = lp::assoc_bit<cr, 20>;
    /* Output selection */
    using cr_osel = lp::assoc_bit<cr, 21, 2>;
    /* Calibration output enable */
    using cr_coe = lp::assoc_bit<cr, 23>;
    /* timestamp on internal event               enable */
    using cr_itse = lp::assoc_bit<cr, 24>;


    /* initialization and status           register */
    using isr = lp::io_register<lp::u32_t, base_address + 0xc>;
    /* Alarm A write flag */
    using isr_alrawf = lp::assoc_bit<isr, 0>;
    /* Alarm B write flag */
    using isr_alrbwf = lp::assoc_bit<isr, 1>;
    /* Wakeup timer write flag */
    using isr_wutwf = lp::assoc_bit<isr, 2>;
    /* Shift operation pending */
    using isr_shpf = lp::assoc_bit<isr, 3>;
    /* Initialization status flag */
    using isr_inits = lp::assoc_bit<isr, 4>;
    /* Registers synchronization               flag */
    using isr_rsf = lp::assoc_bit<isr, 5>;
    /* Initialization flag */
    using isr_initf = lp::assoc_bit<isr, 6>;
    /* Initialization mode */
    using isr_init = lp::assoc_bit<isr, 7>;
    /* Alarm A flag */
    using isr_alraf = lp::assoc_bit<isr, 8>;
    /* Alarm B flag */
    using isr_alrbf = lp::assoc_bit<isr, 9>;
    /* Wakeup timer flag */
    using isr_wutf = lp::assoc_bit<isr, 10>;
    /* Time-stamp flag */
    using isr_tsf = lp::assoc_bit<isr, 11>;
    /* Time-stamp overflow flag */
    using isr_tsovf = lp::assoc_bit<isr, 12>;
    /* Tamper detection flag */
    using isr_tamp1f = lp::assoc_bit<isr, 13>;
    /* RTC_TAMP2 detection flag */
    using isr_tamp2f = lp::assoc_bit<isr, 14>;
    /* RTC_TAMP3 detection flag */
    using isr_tamp3f = lp::assoc_bit<isr, 15>;
    /* Recalibration pending Flag */
    using isr_recalpf = lp::assoc_bit<isr, 16>;


    /* prescaler register */
    using prer = lp::io_register<lp::u32_t, base_address + 0x10>;
    /* Asynchronous prescaler               factor */
    using prer_prediv_a = lp::assoc_bit<prer, 16, 7>;
    /* Synchronous prescaler               factor */
    using prer_prediv_s = lp::assoc_bit<prer, 0, 15>;


    /* wakeup timer register */
    using wutr = lp::io_register<lp::u32_t, base_address + 0x14>;
    /* Wakeup auto-reload value               bits */
    using wutr_wut = lp::assoc_bit<wutr, 0, 16>;


    /* alarm A register */
    using alrmar = lp::io_register<lp::u32_t, base_address + 0x1c>;
    /* Alarm A date mask */
    using alrmar_msk4 = lp::assoc_bit<alrmar, 31>;
    /* Week day selection */
    using alrmar_wdsel = lp::assoc_bit<alrmar, 30>;
    /* Date tens in BCD format */
    using alrmar_dt = lp::assoc_bit<alrmar, 28, 2>;
    /* Date units or day in BCD               format */
    using alrmar_du = lp::assoc_bit<alrmar, 24, 4>;
    /* Alarm A hours mask */
    using alrmar_msk3 = lp::assoc_bit<alrmar, 23>;
    /* AM/PM notation */
    using alrmar_pm = lp::assoc_bit<alrmar, 22>;
    /* Hour tens in BCD format */
    using alrmar_ht = lp::assoc_bit<alrmar, 20, 2>;
    /* Hour units in BCD format */
    using alrmar_hu = lp::assoc_bit<alrmar, 16, 4>;
    /* Alarm A minutes mask */
    using alrmar_msk2 = lp::assoc_bit<alrmar, 15>;
    /* Minute tens in BCD format */
    using alrmar_mnt = lp::assoc_bit<alrmar, 12, 3>;
    /* Minute units in BCD format */
    using alrmar_mnu = lp::assoc_bit<alrmar, 8, 4>;
    /* Alarm A seconds mask */
    using alrmar_msk1 = lp::assoc_bit<alrmar, 7>;
    /* Second tens in BCD format */
    using alrmar_st = lp::assoc_bit<alrmar, 4, 3>;
    /* Second units in BCD format */
    using alrmar_su = lp::assoc_bit<alrmar, 0, 4>;


    /* alarm B register */
    using alrmbr = lp::io_register<lp::u32_t, base_address + 0x20>;
    /* Alarm B date mask */
    using alrmbr_msk4 = lp::assoc_bit<alrmbr, 31>;
    /* Week day selection */
    using alrmbr_wdsel = lp::assoc_bit<alrmbr, 30>;
    /* Date tens in BCD format */
    using alrmbr_dt = lp::assoc_bit<alrmbr, 28, 2>;
    /* Date units or day in BCD               format */
    using alrmbr_du = lp::assoc_bit<alrmbr, 24, 4>;
    /* Alarm B hours mask */
    using alrmbr_msk3 = lp::assoc_bit<alrmbr, 23>;
    /* AM/PM notation */
    using alrmbr_pm = lp::assoc_bit<alrmbr, 22>;
    /* Hour tens in BCD format */
    using alrmbr_ht = lp::assoc_bit<alrmbr, 20, 2>;
    /* Hour units in BCD format */
    using alrmbr_hu = lp::assoc_bit<alrmbr, 16, 4>;
    /* Alarm B minutes mask */
    using alrmbr_msk2 = lp::assoc_bit<alrmbr, 15>;
    /* Minute tens in BCD format */
    using alrmbr_mnt = lp::assoc_bit<alrmbr, 12, 3>;
    /* Minute units in BCD format */
    using alrmbr_mnu = lp::assoc_bit<alrmbr, 8, 4>;
    /* Alarm B seconds mask */
    using alrmbr_msk1 = lp::assoc_bit<alrmbr, 7>;
    /* Second tens in BCD format */
    using alrmbr_st = lp::assoc_bit<alrmbr, 4, 3>;
    /* Second units in BCD format */
    using alrmbr_su = lp::assoc_bit<alrmbr, 0, 4>;


    /* write protection register */
    using wpr = lp::io_register<lp::u32_t, base_address + 0x24>;
    /* Write protection key */
    using wpr_key = lp::assoc_bit<wpr, 0, 8>;


    /* sub second register */
    using ssr = lp::io_register<lp::u32_t, base_address + 0x28>;
    /* Sub second value */
    using ssr_ss = lp::assoc_bit<ssr, 0, 16>;


    /* shift control register */
    using shiftr = lp::io_register<lp::u32_t, base_address + 0x2c>;
    /* Add one second */
    using shiftr_add1s = lp::assoc_bit<shiftr, 31>;
    /* Subtract a fraction of a               second */
    using shiftr_subfs = lp::assoc_bit<shiftr, 0, 15>;


    /* time stamp time register */
    using tstr = lp::io_register<lp::u32_t, base_address + 0x30>;
    /* Second units in BCD format */
    using tstr_su = lp::assoc_bit<tstr, 0, 4>;
    /* Second tens in BCD format */
    using tstr_st = lp::assoc_bit<tstr, 4, 3>;
    /* Minute units in BCD format */
    using tstr_mnu = lp::assoc_bit<tstr, 8, 4>;
    /* Minute tens in BCD format */
    using tstr_mnt = lp::assoc_bit<tstr, 12, 3>;
    /* Hour units in BCD format */
    using tstr_hu = lp::assoc_bit<tstr, 16, 4>;
    /* Hour tens in BCD format */
    using tstr_ht = lp::assoc_bit<tstr, 20, 2>;
    /* AM/PM notation */
    using tstr_pm = lp::assoc_bit<tstr, 22>;


    /* time stamp date register */
    using tsdr = lp::io_register<lp::u32_t, base_address + 0x34>;
    /* Week day units */
    using tsdr_wdu = lp::assoc_bit<tsdr, 13, 3>;
    /* Month tens in BCD format */
    using tsdr_mt = lp::assoc_bit<tsdr, 12>;
    /* Month units in BCD format */
    using tsdr_mu = lp::assoc_bit<tsdr, 8, 4>;
    /* Date tens in BCD format */
    using tsdr_dt = lp::assoc_bit<tsdr, 4, 2>;
    /* Date units in BCD format */
    using tsdr_du = lp::assoc_bit<tsdr, 0, 4>;


    /* timestamp sub second register */
    using tsssr = lp::io_register<lp::u32_t, base_address + 0x38>;
    /* Sub second value */
    using tsssr_ss = lp::assoc_bit<tsssr, 0, 16>;


    /* calibration register */
    using calr = lp::io_register<lp::u32_t, base_address + 0x3c>;
    /* Increase frequency of RTC by 488.5               ppm */
    using calr_calp = lp::assoc_bit<calr, 15>;
    /* Use an 8-second calibration cycle               period */
    using calr_calw8 = lp::assoc_bit<calr, 14>;
    /* Use a 16-second calibration cycle               period */
    using calr_calw16 = lp::assoc_bit<calr, 13>;
    /* Calibration minus */
    using calr_calm = lp::assoc_bit<calr, 0, 9>;


    /* tamper configuration register */
    using tampcr = lp::io_register<lp::u32_t, base_address + 0x40>;
    /* Tamper 1 detection enable */
    using tampcr_tamp1e = lp::assoc_bit<tampcr, 0>;
    /* Active level for tamper 1 */
    using tampcr_tamp1trg = lp::assoc_bit<tampcr, 1>;
    /* Tamper interrupt enable */
    using tampcr_tampie = lp::assoc_bit<tampcr, 2>;
    /* Tamper 2 detection enable */
    using tampcr_tamp2e = lp::assoc_bit<tampcr, 3>;
    /* Active level for tamper 2 */
    using tampcr_tamp2trg = lp::assoc_bit<tampcr, 4>;
    /* Tamper 3 detection enable */
    using tampcr_tamp3e = lp::assoc_bit<tampcr, 5>;
    /* Active level for tamper 3 */
    using tampcr_tamp3trg = lp::assoc_bit<tampcr, 6>;
    /* Activate timestamp on tamper detection               event */
    using tampcr_tampts = lp::assoc_bit<tampcr, 7>;
    /* Tamper sampling frequency */
    using tampcr_tampfreq = lp::assoc_bit<tampcr, 8, 3>;
    /* Tamper filter count */
    using tampcr_tampflt = lp::assoc_bit<tampcr, 11, 2>;
    /* Tamper precharge duration */
    using tampcr_tampprch = lp::assoc_bit<tampcr, 13, 2>;
    /* TAMPER pull-up disable */
    using tampcr_tamppudis = lp::assoc_bit<tampcr, 15>;
    /* Tamper 1 interrupt enable */
    using tampcr_tamp1ie = lp::assoc_bit<tampcr, 16>;
    /* Tamper 1 no erase */
    using tampcr_tamp1noerase = lp::assoc_bit<tampcr, 17>;
    /* Tamper 1 mask flag */
    using tampcr_tamp1mf = lp::assoc_bit<tampcr, 18>;
    /* Tamper 2 interrupt enable */
    using tampcr_tamp2ie = lp::assoc_bit<tampcr, 19>;
    /* Tamper 2 no erase */
    using tampcr_tamp2noerase = lp::assoc_bit<tampcr, 20>;
    /* Tamper 2 mask flag */
    using tampcr_tamp2mf = lp::assoc_bit<tampcr, 21>;
    /* Tamper 3 interrupt enable */
    using tampcr_tamp3ie = lp::assoc_bit<tampcr, 22>;
    /* Tamper 3 no erase */
    using tampcr_tamp3noerase = lp::assoc_bit<tampcr, 23>;
    /* Tamper 3 mask flag */
    using tampcr_tamp3mf = lp::assoc_bit<tampcr, 24>;


    /* alarm A sub second register */
    using alrmassr = lp::io_register<lp::u32_t, base_address + 0x44>;
    /* Mask the most-significant bits starting               at this bit */
    using alrmassr_maskss = lp::assoc_bit<alrmassr, 24, 4>;
    /* Sub seconds value */
    using alrmassr_ss = lp::assoc_bit<alrmassr, 0, 15>;


    /* alarm B sub second register */
    using alrmbssr = lp::io_register<lp::u32_t, base_address + 0x48>;
    /* Mask the most-significant bits starting               at this bit */
    using alrmbssr_maskss = lp::assoc_bit<alrmbssr, 24, 4>;
    /* Sub seconds value */
    using alrmbssr_ss = lp::assoc_bit<alrmbssr, 0, 15>;


    /* option register */
    using or1 = lp::io_register<lp::u32_t, base_address + 0x4c>;
    /* RTC_ALARM on PC13 output               type */
    using or1_rtc_alarm_type = lp::assoc_bit<or1, 0>;
    /* RTC_OUT remap */
    using or1_rtc_out_rmp = lp::assoc_bit<or1, 1>;


    /* backup register */
    using bkp0r = lp::io_register<lp::u32_t, base_address + 0x50>;
    /* BKP */
    using bkp0r_bkp = lp::assoc_bit<bkp0r, 0, 32>;


    /* backup register */
    using bkp1r = lp::io_register<lp::u32_t, base_address + 0x54>;
    /* BKP */
    using bkp1r_bkp = lp::assoc_bit<bkp1r, 0, 32>;


    /* backup register */
    using bkp2r = lp::io_register<lp::u32_t, base_address + 0x58>;
    /* BKP */
    using bkp2r_bkp = lp::assoc_bit<bkp2r, 0, 32>;


    /* backup register */
    using bkp3r = lp::io_register<lp::u32_t, base_address + 0x5c>;
    /* BKP */
    using bkp3r_bkp = lp::assoc_bit<bkp3r, 0, 32>;


    /* backup register */
    using bkp4r = lp::io_register<lp::u32_t, base_address + 0x60>;
    /* BKP */
    using bkp4r_bkp = lp::assoc_bit<bkp4r, 0, 32>;


    /* backup register */
    using bkp5r = lp::io_register<lp::u32_t, base_address + 0x64>;
    /* BKP */
    using bkp5r_bkp = lp::assoc_bit<bkp5r, 0, 32>;


    /* backup register */
    using bkp6r = lp::io_register<lp::u32_t, base_address + 0x68>;
    /* BKP */
    using bkp6r_bkp = lp::assoc_bit<bkp6r, 0, 32>;


    /* backup register */
    using bkp7r = lp::io_register<lp::u32_t, base_address + 0x6c>;
    /* BKP */
    using bkp7r_bkp = lp::assoc_bit<bkp7r, 0, 32>;


    /* backup register */
    using bkp8r = lp::io_register<lp::u32_t, base_address + 0x70>;
    /* BKP */
    using bkp8r_bkp = lp::assoc_bit<bkp8r, 0, 32>;


    /* backup register */
    using bkp9r = lp::io_register<lp::u32_t, base_address + 0x74>;
    /* BKP */
    using bkp9r_bkp = lp::assoc_bit<bkp9r, 0, 32>;


    /* backup register */
    using bkp10r = lp::io_register<lp::u32_t, base_address + 0x78>;
    /* BKP */
    using bkp10r_bkp = lp::assoc_bit<bkp10r, 0, 32>;


    /* backup register */
    using bkp11r = lp::io_register<lp::u32_t, base_address + 0x7c>;
    /* BKP */
    using bkp11r_bkp = lp::assoc_bit<bkp11r, 0, 32>;


    /* backup register */
    using bkp12r = lp::io_register<lp::u32_t, base_address + 0x80>;
    /* BKP */
    using bkp12r_bkp = lp::assoc_bit<bkp12r, 0, 32>;


    /* backup register */
    using bkp13r = lp::io_register<lp::u32_t, base_address + 0x84>;
    /* BKP */
    using bkp13r_bkp = lp::assoc_bit<bkp13r, 0, 32>;


    /* backup register */
    using bkp14r = lp::io_register<lp::u32_t, base_address + 0x88>;
    /* BKP */
    using bkp14r_bkp = lp::assoc_bit<bkp14r, 0, 32>;


    /* backup register */
    using bkp15r = lp::io_register<lp::u32_t, base_address + 0x8c>;
    /* BKP */
    using bkp15r_bkp = lp::assoc_bit<bkp15r, 0, 32>;


    /* backup register */
    using bkp16r = lp::io_register<lp::u32_t, base_address + 0x90>;
    /* BKP */
    using bkp16r_bkp = lp::assoc_bit<bkp16r, 0, 32>;


    /* backup register */
    using bkp17r = lp::io_register<lp::u32_t, base_address + 0x94>;
    /* BKP */
    using bkp17r_bkp = lp::assoc_bit<bkp17r, 0, 32>;


    /* backup register */
    using bkp18r = lp::io_register<lp::u32_t, base_address + 0x98>;
    /* BKP */
    using bkp18r_bkp = lp::assoc_bit<bkp18r, 0, 32>;


    /* backup register */
    using bkp19r = lp::io_register<lp::u32_t, base_address + 0x9c>;
    /* BKP */
    using bkp19r_bkp = lp::assoc_bit<bkp19r, 0, 32>;


    /* backup register */
    using bkp20r = lp::io_register<lp::u32_t, base_address + 0xa0>;
    /* BKP */
    using bkp20r_bkp = lp::assoc_bit<bkp20r, 0, 32>;


    /* backup register */
    using bkp21r = lp::io_register<lp::u32_t, base_address + 0xa4>;
    /* BKP */
    using bkp21r_bkp = lp::assoc_bit<bkp21r, 0, 32>;


    /* backup register */
    using bkp22r = lp::io_register<lp::u32_t, base_address + 0xa8>;
    /* BKP */
    using bkp22r_bkp = lp::assoc_bit<bkp22r, 0, 32>;


    /* backup register */
    using bkp23r = lp::io_register<lp::u32_t, base_address + 0xac>;
    /* BKP */
    using bkp23r_bkp = lp::assoc_bit<bkp23r, 0, 32>;


    /* backup register */
    using bkp24r = lp::io_register<lp::u32_t, base_address + 0xb0>;
    /* BKP */
    using bkp24r_bkp = lp::assoc_bit<bkp24r, 0, 32>;


    /* backup register */
    using bkp25r = lp::io_register<lp::u32_t, base_address + 0xb4>;
    /* BKP */
    using bkp25r_bkp = lp::assoc_bit<bkp25r, 0, 32>;


    /* backup register */
    using bkp26r = lp::io_register<lp::u32_t, base_address + 0xb8>;
    /* BKP */
    using bkp26r_bkp = lp::assoc_bit<bkp26r, 0, 32>;


    /* backup register */
    using bkp27r = lp::io_register<lp::u32_t, base_address + 0xbc>;
    /* BKP */
    using bkp27r_bkp = lp::assoc_bit<bkp27r, 0, 32>;


    /* backup register */
    using bkp28r = lp::io_register<lp::u32_t, base_address + 0xc0>;
    /* BKP */
    using bkp28r_bkp = lp::assoc_bit<bkp28r, 0, 32>;


    /* backup register */
    using bkp29r = lp::io_register<lp::u32_t, base_address + 0xc4>;
    /* BKP */
    using bkp29r_bkp = lp::assoc_bit<bkp29r, 0, 32>;


    /* backup register */
    using bkp30r = lp::io_register<lp::u32_t, base_address + 0xc8>;
    /* BKP */
    using bkp30r_bkp = lp::assoc_bit<bkp30r, 0, 32>;


    /* backup register */
    using bkp31r = lp::io_register<lp::u32_t, base_address + 0xcc>;
    /* BKP */
    using bkp31r_bkp = lp::assoc_bit<bkp31r, 0, 32>;


};

using rtc = rtc_t<0x40002800>;

#endif // RTC_HH
