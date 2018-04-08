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
 * Hardware support for aes
 * @file aes.hh
 * @author Boris Vinogradov
 */

#include <associate_bit.hh>
#include <io_register.hh>
#include <types.hh>

#ifndef AES_HH
#define AES_HH

/* Advanced encryption standard hardware
      accelerator */
template <lp::addr_t base_address>
struct aes_t {
    /* control register */
    using cr = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* Enable DMA management of data output               phase */
    using cr_dmaouten = lp::assoc_bit<cr, 12>;
    /* Enable DMA management of data input               phase */
    using cr_dmainen = lp::assoc_bit<cr, 11>;
    /* Error interrupt enable */
    using cr_errie = lp::assoc_bit<cr, 10>;
    /* CCF flag interrupt enable */
    using cr_ccfie = lp::assoc_bit<cr, 9>;
    /* Error clear */
    using cr_errc = lp::assoc_bit<cr, 8>;
    /* Computation Complete Flag               Clear */
    using cr_ccfc = lp::assoc_bit<cr, 7>;
    /* AES chaining mode */
    using cr_chmod = lp::assoc_bit<cr, 5, 2>;
    /* AES operating mode */
    using cr_mode = lp::assoc_bit<cr, 3, 2>;
    /* Data type selection (for data in and               data out to/from the cryptographic               block) */
    using cr_datatype = lp::assoc_bit<cr, 1, 2>;
    /* AES enable */
    using cr_en = lp::assoc_bit<cr, 0>;


    /* status register */
    using sr = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* Write error flag */
    using sr_wrerr = lp::assoc_bit<sr, 2>;
    /* Read error flag */
    using sr_rderr = lp::assoc_bit<sr, 1>;
    /* Computation complete flag */
    using sr_ccf = lp::assoc_bit<sr, 0>;


    /* data input register */
    using dinr = lp::io_register<lp::u32_t, base_address + 0x8>;
    /* Data Input Register */
    using dinr_aes_dinr = lp::assoc_bit<dinr, 0, 32>;


    /* data output register */
    using doutr = lp::io_register<lp::u32_t, base_address + 0xc>;
    /* Data output register */
    using doutr_aes_doutr = lp::assoc_bit<doutr, 0, 32>;


    /* key register 0 */
    using keyr0 = lp::io_register<lp::u32_t, base_address + 0x10>;
    /* Data Output Register (LSB key               [31:0]) */
    using keyr0_aes_keyr0 = lp::assoc_bit<keyr0, 0, 32>;


    /* key register 1 */
    using keyr1 = lp::io_register<lp::u32_t, base_address + 0x14>;
    /* AES key register (key               [63:32]) */
    using keyr1_aes_keyr1 = lp::assoc_bit<keyr1, 0, 32>;


    /* key register 2 */
    using keyr2 = lp::io_register<lp::u32_t, base_address + 0x18>;
    /* AES key register (key               [95:64]) */
    using keyr2_aes_keyr2 = lp::assoc_bit<keyr2, 0, 32>;


    /* key register 3 */
    using keyr3 = lp::io_register<lp::u32_t, base_address + 0x1c>;
    /* AES key register (MSB key               [127:96]) */
    using keyr3_aes_keyr3 = lp::assoc_bit<keyr3, 0, 32>;


    /* initialization vector register           0 */
    using ivr0 = lp::io_register<lp::u32_t, base_address + 0x20>;
    /* initialization vector register (LSB IVR               [31:0]) */
    using ivr0_aes_ivr0 = lp::assoc_bit<ivr0, 0, 32>;


    /* initialization vector register           1 */
    using ivr1 = lp::io_register<lp::u32_t, base_address + 0x24>;
    /* Initialization Vector Register (IVR               [63:32]) */
    using ivr1_aes_ivr1 = lp::assoc_bit<ivr1, 0, 32>;


    /* initialization vector register           2 */
    using ivr2 = lp::io_register<lp::u32_t, base_address + 0x28>;
    /* Initialization Vector Register (IVR               [95:64]) */
    using ivr2_aes_ivr2 = lp::assoc_bit<ivr2, 0, 32>;


    /* initialization vector register           3 */
    using ivr3 = lp::io_register<lp::u32_t, base_address + 0x2c>;
    /* Initialization Vector Register (MSB IVR               [127:96]) */
    using ivr3_aes_ivr3 = lp::assoc_bit<ivr3, 0, 32>;


};

using aes = aes_t<0x50060000>;

#endif // AES_HH
