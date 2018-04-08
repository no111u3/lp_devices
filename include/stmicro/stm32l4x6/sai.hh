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
 * Hardware support for sai
 * @file sai.hh
 * @author Boris Vinogradov
 */

#include <associate_bit.hh>
#include <io_register.hh>
#include <types.hh>

#ifndef SAI_HH
#define SAI_HH

/* Serial audio interface */
template <lp::addr_t base_address>
struct sai_t {
    /* BConfiguration register 1 */
    using bcr1 = lp::io_register<lp::u32_t, base_address + 0x24>;
    /* Master clock divider */
    using bcr1_mcjdiv = lp::assoc_bit<bcr1, 20, 4>;
    /* No divider */
    using bcr1_nodiv = lp::assoc_bit<bcr1, 19>;
    /* DMA enable */
    using bcr1_dmaen = lp::assoc_bit<bcr1, 17>;
    /* Audio block B enable */
    using bcr1_saiben = lp::assoc_bit<bcr1, 16>;
    /* Output drive */
    using bcr1_outdri = lp::assoc_bit<bcr1, 13>;
    /* Mono mode */
    using bcr1_mono = lp::assoc_bit<bcr1, 12>;
    /* Synchronization enable */
    using bcr1_syncen = lp::assoc_bit<bcr1, 10, 2>;
    /* Clock strobing edge */
    using bcr1_ckstr = lp::assoc_bit<bcr1, 9>;
    /* Least significant bit               first */
    using bcr1_lsbfirst = lp::assoc_bit<bcr1, 8>;
    /* Data size */
    using bcr1_ds = lp::assoc_bit<bcr1, 5, 3>;
    /* Protocol configuration */
    using bcr1_prtcfg = lp::assoc_bit<bcr1, 2, 2>;
    /* Audio block mode */
    using bcr1_mode = lp::assoc_bit<bcr1, 0, 2>;


    /* BConfiguration register 2 */
    using bcr2 = lp::io_register<lp::u32_t, base_address + 0x28>;
    /* Companding mode */
    using bcr2_comp = lp::assoc_bit<bcr2, 14, 2>;
    /* Complement bit */
    using bcr2_cpl = lp::assoc_bit<bcr2, 13>;
    /* Mute counter */
    using bcr2_mutecn = lp::assoc_bit<bcr2, 7, 6>;
    /* Mute value */
    using bcr2_muteval = lp::assoc_bit<bcr2, 6>;
    /* Mute */
    using bcr2_mute = lp::assoc_bit<bcr2, 5>;
    /* Tristate management on data               line */
    using bcr2_tris = lp::assoc_bit<bcr2, 4>;
    /* FIFO flush */
    using bcr2_fflus = lp::assoc_bit<bcr2, 3>;
    /* FIFO threshold */
    using bcr2_fth = lp::assoc_bit<bcr2, 0, 3>;


    /* BFRCR */
    using bfrcr = lp::io_register<lp::u32_t, base_address + 0x2c>;
    /* Frame synchronization               offset */
    using bfrcr_fsoff = lp::assoc_bit<bfrcr, 18>;
    /* Frame synchronization               polarity */
    using bfrcr_fspol = lp::assoc_bit<bfrcr, 17>;
    /* Frame synchronization               definition */
    using bfrcr_fsdef = lp::assoc_bit<bfrcr, 16>;
    /* Frame synchronization active level               length */
    using bfrcr_fsall = lp::assoc_bit<bfrcr, 8, 7>;
    /* Frame length */
    using bfrcr_frl = lp::assoc_bit<bfrcr, 0, 8>;


    /* BSlot register */
    using bslotr = lp::io_register<lp::u32_t, base_address + 0x30>;
    /* Slot enable */
    using bslotr_sloten = lp::assoc_bit<bslotr, 16, 16>;
    /* Number of slots in an audio               frame */
    using bslotr_nbslot = lp::assoc_bit<bslotr, 8, 4>;
    /* Slot size */
    using bslotr_slotsz = lp::assoc_bit<bslotr, 6, 2>;
    /* First bit offset */
    using bslotr_fboff = lp::assoc_bit<bslotr, 0, 5>;


    /* BInterrupt mask register2 */
    using bim = lp::io_register<lp::u32_t, base_address + 0x34>;
    /* Late frame synchronization detection               interrupt enable */
    using bim_lfsdetie = lp::assoc_bit<bim, 6>;
    /* Anticipated frame synchronization               detection interrupt enable */
    using bim_afsdetie = lp::assoc_bit<bim, 5>;
    /* Codec not ready interrupt               enable */
    using bim_cnrdyie = lp::assoc_bit<bim, 4>;
    /* FIFO request interrupt               enable */
    using bim_freqie = lp::assoc_bit<bim, 3>;
    /* Wrong clock configuration interrupt               enable */
    using bim_wckcfg = lp::assoc_bit<bim, 2>;
    /* Mute detection interrupt               enable */
    using bim_mutedet = lp::assoc_bit<bim, 1>;
    /* Overrun/underrun interrupt               enable */
    using bim_ovrudrie = lp::assoc_bit<bim, 0>;


    /* BStatus register */
    using bsr = lp::io_register<lp::u32_t, base_address + 0x38>;
    /* FIFO level threshold */
    using bsr_flvl = lp::assoc_bit<bsr, 16, 3>;
    /* Late frame synchronization               detection */
    using bsr_lfsdet = lp::assoc_bit<bsr, 6>;
    /* Anticipated frame synchronization               detection */
    using bsr_afsdet = lp::assoc_bit<bsr, 5>;
    /* Codec not ready */
    using bsr_cnrdy = lp::assoc_bit<bsr, 4>;
    /* FIFO request */
    using bsr_freq = lp::assoc_bit<bsr, 3>;
    /* Wrong clock configuration               flag */
    using bsr_wckcfg = lp::assoc_bit<bsr, 2>;
    /* Mute detection */
    using bsr_mutedet = lp::assoc_bit<bsr, 1>;
    /* Overrun / underrun */
    using bsr_ovrudr = lp::assoc_bit<bsr, 0>;


    /* BClear flag register */
    using bclrfr = lp::io_register<lp::u32_t, base_address + 0x3c>;
    /* Clear late frame synchronization               detection flag */
    using bclrfr_lfsdet = lp::assoc_bit<bclrfr, 6>;
    /* Clear anticipated frame synchronization               detection flag */
    using bclrfr_cafsdet = lp::assoc_bit<bclrfr, 5>;
    /* Clear codec not ready flag */
    using bclrfr_cnrdy = lp::assoc_bit<bclrfr, 4>;
    /* Clear wrong clock configuration               flag */
    using bclrfr_wckcfg = lp::assoc_bit<bclrfr, 2>;
    /* Mute detection flag */
    using bclrfr_mutedet = lp::assoc_bit<bclrfr, 1>;
    /* Clear overrun / underrun */
    using bclrfr_ovrudr = lp::assoc_bit<bclrfr, 0>;


    /* BData register */
    using bdr = lp::io_register<lp::u32_t, base_address + 0x40>;
    /* Data */
    using bdr_data = lp::assoc_bit<bdr, 0, 32>;


    /* AConfiguration register 1 */
    using acr1 = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* Master clock divider */
    using acr1_mcjdiv = lp::assoc_bit<acr1, 20, 4>;
    /* No divider */
    using acr1_nodiv = lp::assoc_bit<acr1, 19>;
    /* DMA enable */
    using acr1_dmaen = lp::assoc_bit<acr1, 17>;
    /* Audio block A enable */
    using acr1_saiaen = lp::assoc_bit<acr1, 16>;
    /* Output drive */
    using acr1_outdri = lp::assoc_bit<acr1, 13>;
    /* Mono mode */
    using acr1_mono = lp::assoc_bit<acr1, 12>;
    /* Synchronization enable */
    using acr1_syncen = lp::assoc_bit<acr1, 10, 2>;
    /* Clock strobing edge */
    using acr1_ckstr = lp::assoc_bit<acr1, 9>;
    /* Least significant bit               first */
    using acr1_lsbfirst = lp::assoc_bit<acr1, 8>;
    /* Data size */
    using acr1_ds = lp::assoc_bit<acr1, 5, 3>;
    /* Protocol configuration */
    using acr1_prtcfg = lp::assoc_bit<acr1, 2, 2>;
    /* Audio block mode */
    using acr1_mode = lp::assoc_bit<acr1, 0, 2>;


    /* AConfiguration register 2 */
    using acr2 = lp::io_register<lp::u32_t, base_address + 0x8>;
    /* Companding mode */
    using acr2_comp = lp::assoc_bit<acr2, 14, 2>;
    /* Complement bit */
    using acr2_cpl = lp::assoc_bit<acr2, 13>;
    /* Mute counter */
    using acr2_mutecn = lp::assoc_bit<acr2, 7, 6>;
    /* Mute value */
    using acr2_muteval = lp::assoc_bit<acr2, 6>;
    /* Mute */
    using acr2_mute = lp::assoc_bit<acr2, 5>;
    /* Tristate management on data               line */
    using acr2_tris = lp::assoc_bit<acr2, 4>;
    /* FIFO flush */
    using acr2_fflus = lp::assoc_bit<acr2, 3>;
    /* FIFO threshold */
    using acr2_fth = lp::assoc_bit<acr2, 0, 3>;


    /* AFRCR */
    using afrcr = lp::io_register<lp::u32_t, base_address + 0xc>;
    /* Frame synchronization               offset */
    using afrcr_fsoff = lp::assoc_bit<afrcr, 18>;
    /* Frame synchronization               polarity */
    using afrcr_fspol = lp::assoc_bit<afrcr, 17>;
    /* Frame synchronization               definition */
    using afrcr_fsdef = lp::assoc_bit<afrcr, 16>;
    /* Frame synchronization active level               length */
    using afrcr_fsall = lp::assoc_bit<afrcr, 8, 7>;
    /* Frame length */
    using afrcr_frl = lp::assoc_bit<afrcr, 0, 8>;


    /* ASlot register */
    using aslotr = lp::io_register<lp::u32_t, base_address + 0x10>;
    /* Slot enable */
    using aslotr_sloten = lp::assoc_bit<aslotr, 16, 16>;
    /* Number of slots in an audio               frame */
    using aslotr_nbslot = lp::assoc_bit<aslotr, 8, 4>;
    /* Slot size */
    using aslotr_slotsz = lp::assoc_bit<aslotr, 6, 2>;
    /* First bit offset */
    using aslotr_fboff = lp::assoc_bit<aslotr, 0, 5>;


    /* AInterrupt mask register2 */
    using aim = lp::io_register<lp::u32_t, base_address + 0x14>;
    /* Late frame synchronization detection               interrupt enable */
    using aim_lfsdet = lp::assoc_bit<aim, 6>;
    /* Anticipated frame synchronization               detection interrupt enable */
    using aim_afsdetie = lp::assoc_bit<aim, 5>;
    /* Codec not ready interrupt               enable */
    using aim_cnrdyie = lp::assoc_bit<aim, 4>;
    /* FIFO request interrupt               enable */
    using aim_freqie = lp::assoc_bit<aim, 3>;
    /* Wrong clock configuration interrupt               enable */
    using aim_wckcfg = lp::assoc_bit<aim, 2>;
    /* Mute detection interrupt               enable */
    using aim_mutedet = lp::assoc_bit<aim, 1>;
    /* Overrun/underrun interrupt               enable */
    using aim_ovrudrie = lp::assoc_bit<aim, 0>;


    /* AStatus register */
    using asr = lp::io_register<lp::u32_t, base_address + 0x18>;
    /* FIFO level threshold */
    using asr_flvl = lp::assoc_bit<asr, 16, 3>;
    /* Late frame synchronization               detection */
    using asr_lfsdet = lp::assoc_bit<asr, 6>;
    /* Anticipated frame synchronization               detection */
    using asr_afsdet = lp::assoc_bit<asr, 5>;
    /* Codec not ready */
    using asr_cnrdy = lp::assoc_bit<asr, 4>;
    /* FIFO request */
    using asr_freq = lp::assoc_bit<asr, 3>;
    /* Wrong clock configuration flag. This bit               is read only */
    using asr_wckcfg = lp::assoc_bit<asr, 2>;
    /* Mute detection */
    using asr_mutedet = lp::assoc_bit<asr, 1>;
    /* Overrun / underrun */
    using asr_ovrudr = lp::assoc_bit<asr, 0>;


    /* AClear flag register */
    using aclrfr = lp::io_register<lp::u32_t, base_address + 0x1c>;
    /* Clear late frame synchronization               detection flag */
    using aclrfr_lfsdet = lp::assoc_bit<aclrfr, 6>;
    /* Clear anticipated frame synchronization               detection flag */
    using aclrfr_cafsdet = lp::assoc_bit<aclrfr, 5>;
    /* Clear codec not ready flag */
    using aclrfr_cnrdy = lp::assoc_bit<aclrfr, 4>;
    /* Clear wrong clock configuration               flag */
    using aclrfr_wckcfg = lp::assoc_bit<aclrfr, 2>;
    /* Mute detection flag */
    using aclrfr_mutedet = lp::assoc_bit<aclrfr, 1>;
    /* Clear overrun / underrun */
    using aclrfr_ovrudr = lp::assoc_bit<aclrfr, 0>;


    /* AData register */
    using adr = lp::io_register<lp::u32_t, base_address + 0x20>;
    /* Data */
    using adr_data = lp::assoc_bit<adr, 0, 32>;


};

using sai1 = sai_t<0x40015400>;
using sai2 = sai_t<0x40015800>;

#endif // SAI_HH
