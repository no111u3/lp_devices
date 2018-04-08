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
 * Hardware support for dcmi
 * @file dcmi.hh
 * @author Boris Vinogradov
 */

#include <associate_bit.hh>
#include <io_register.hh>
#include <types.hh>

#ifndef DCMI_HH
#define DCMI_HH

/* Digital camera interface */
template <lp::addr_t base_address>
struct dcmi_t {
    /* control register 1 */
    using cr = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* DCMI enable */
    using cr_enable = lp::assoc_bit<cr, 14>;
    /* Extended data mode */
    using cr_edm = lp::assoc_bit<cr, 10, 2>;
    /* Frame capture rate control */
    using cr_fcrc = lp::assoc_bit<cr, 8, 2>;
    /* Vertical synchronization               polarity */
    using cr_vspol = lp::assoc_bit<cr, 7>;
    /* Horizontal synchronization               polarity */
    using cr_hspol = lp::assoc_bit<cr, 6>;
    /* Pixel clock polarity */
    using cr_pckpol = lp::assoc_bit<cr, 5>;
    /* Embedded synchronization               select */
    using cr_ess = lp::assoc_bit<cr, 4>;
    /* JPEG format */
    using cr_jpeg = lp::assoc_bit<cr, 3>;
    /* Crop feature */
    using cr_crop = lp::assoc_bit<cr, 2>;
    /* Capture mode */
    using cr_cm = lp::assoc_bit<cr, 1>;
    /* Capture enable */
    using cr_capture = lp::assoc_bit<cr, 0>;
    /* Odd/Even Line Select (Line Select               Start) */
    using cr_oels = lp::assoc_bit<cr, 20>;
    /* Line Select mode */
    using cr_lsm = lp::assoc_bit<cr, 19>;
    /* Odd/Even Byte Select (Byte Select               Start) */
    using cr_oebs = lp::assoc_bit<cr, 18>;
    /* Byte Select mode */
    using cr_bsm = lp::assoc_bit<cr, 16, 2>;


    /* status register */
    using sr = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* FIFO not empty */
    using sr_fne = lp::assoc_bit<sr, 2>;
    /* VSYNC */
    using sr_vsync = lp::assoc_bit<sr, 1>;
    /* HSYNC */
    using sr_hsync = lp::assoc_bit<sr, 0>;


    /* raw interrupt status register */
    using ris = lp::io_register<lp::u32_t, base_address + 0x8>;
    /* Line raw interrupt status */
    using ris_line_ris = lp::assoc_bit<ris, 4>;
    /* VSYNC raw interrupt status */
    using ris_vsync_ris = lp::assoc_bit<ris, 3>;
    /* Synchronization error raw interrupt               status */
    using ris_err_ris = lp::assoc_bit<ris, 2>;
    /* Overrun raw interrupt               status */
    using ris_ovr_ris = lp::assoc_bit<ris, 1>;
    /* Capture complete raw interrupt               status */
    using ris_frame_ris = lp::assoc_bit<ris, 0>;


    /* interrupt enable register */
    using ier = lp::io_register<lp::u32_t, base_address + 0xc>;
    /* Line interrupt enable */
    using ier_line_ie = lp::assoc_bit<ier, 4>;
    /* VSYNC interrupt enable */
    using ier_vsync_ie = lp::assoc_bit<ier, 3>;
    /* Synchronization error interrupt               enable */
    using ier_err_ie = lp::assoc_bit<ier, 2>;
    /* Overrun interrupt enable */
    using ier_ovr_ie = lp::assoc_bit<ier, 1>;
    /* Capture complete interrupt               enable */
    using ier_frame_ie = lp::assoc_bit<ier, 0>;


    /* masked interrupt status           register */
    using mis = lp::io_register<lp::u32_t, base_address + 0x10>;
    /* Line masked interrupt               status */
    using mis_line_mis = lp::assoc_bit<mis, 4>;
    /* VSYNC masked interrupt               status */
    using mis_vsync_mis = lp::assoc_bit<mis, 3>;
    /* Synchronization error masked interrupt               status */
    using mis_err_mis = lp::assoc_bit<mis, 2>;
    /* Overrun masked interrupt               status */
    using mis_ovr_mis = lp::assoc_bit<mis, 1>;
    /* Capture complete masked interrupt               status */
    using mis_frame_mis = lp::assoc_bit<mis, 0>;


    /* interrupt clear register */
    using icr = lp::io_register<lp::u32_t, base_address + 0x14>;
    /* line interrupt status               clear */
    using icr_line_isc = lp::assoc_bit<icr, 4>;
    /* Vertical synch interrupt status               clear */
    using icr_vsync_isc = lp::assoc_bit<icr, 3>;
    /* Synchronization error interrupt status               clear */
    using icr_err_isc = lp::assoc_bit<icr, 2>;
    /* Overrun interrupt status               clear */
    using icr_ovr_isc = lp::assoc_bit<icr, 1>;
    /* Capture complete interrupt status               clear */
    using icr_frame_isc = lp::assoc_bit<icr, 0>;


    /* embedded synchronization code           register */
    using escr = lp::io_register<lp::u32_t, base_address + 0x18>;
    /* Frame end delimiter code */
    using escr_fec = lp::assoc_bit<escr, 24, 8>;
    /* Line end delimiter code */
    using escr_lec = lp::assoc_bit<escr, 16, 8>;
    /* Line start delimiter code */
    using escr_lsc = lp::assoc_bit<escr, 8, 8>;
    /* Frame start delimiter code */
    using escr_fsc = lp::assoc_bit<escr, 0, 8>;


    /* embedded synchronization unmask           register */
    using esur = lp::io_register<lp::u32_t, base_address + 0x1c>;
    /* Frame end delimiter unmask */
    using esur_feu = lp::assoc_bit<esur, 24, 8>;
    /* Line end delimiter unmask */
    using esur_leu = lp::assoc_bit<esur, 16, 8>;
    /* Line start delimiter               unmask */
    using esur_lsu = lp::assoc_bit<esur, 8, 8>;
    /* Frame start delimiter               unmask */
    using esur_fsu = lp::assoc_bit<esur, 0, 8>;


    /* crop window start */
    using cwstrt = lp::io_register<lp::u32_t, base_address + 0x20>;
    /* Vertical start line count */
    using cwstrt_vst = lp::assoc_bit<cwstrt, 16, 13>;
    /* Horizontal offset count */
    using cwstrt_hoffcnt = lp::assoc_bit<cwstrt, 0, 14>;


    /* crop window size */
    using cwsize = lp::io_register<lp::u32_t, base_address + 0x24>;
    /* Vertical line count */
    using cwsize_vline = lp::assoc_bit<cwsize, 16, 14>;
    /* Capture count */
    using cwsize_capcnt = lp::assoc_bit<cwsize, 0, 14>;


    /* data register */
    using dr = lp::io_register<lp::u32_t, base_address + 0x28>;
    /* Data byte 3 */
    using dr_byte3 = lp::assoc_bit<dr, 24, 8>;
    /* Data byte 2 */
    using dr_byte2 = lp::assoc_bit<dr, 16, 8>;
    /* Data byte 1 */
    using dr_byte1 = lp::assoc_bit<dr, 8, 8>;
    /* Data byte 0 */
    using dr_byte0 = lp::assoc_bit<dr, 0, 8>;


};

using dcmi = dcmi_t<0x50050000>;

#endif // DCMI_HH
