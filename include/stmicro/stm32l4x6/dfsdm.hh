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
 * Hardware support for dfsdm
 * @file dfsdm.hh
 * @author Boris Vinogradov
 */

#include <associate_bit.hh>
#include <io_register.hh>
#include <types.hh>

#ifndef DFSDM_HH
#define DFSDM_HH

/* Digital filter for sigma delta
      modulators */
template <lp::addr_t base_address>
struct dfsdm_t {
    /* channel configuration y           register */
    using chcfg0r1 = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* DFSDMEN */
    using chcfg0r1_dfsdmen = lp::assoc_bit<chcfg0r1, 31>;
    /* CKOUTSRC */
    using chcfg0r1_ckoutsrc = lp::assoc_bit<chcfg0r1, 30>;
    /* CKOUTDIV */
    using chcfg0r1_ckoutdiv = lp::assoc_bit<chcfg0r1, 16, 8>;
    /* DATPACK */
    using chcfg0r1_datpack = lp::assoc_bit<chcfg0r1, 14, 2>;
    /* DATMPX */
    using chcfg0r1_datmpx = lp::assoc_bit<chcfg0r1, 12, 2>;
    /* CHINSEL */
    using chcfg0r1_chinsel = lp::assoc_bit<chcfg0r1, 8>;
    /* CHEN */
    using chcfg0r1_chen = lp::assoc_bit<chcfg0r1, 7>;
    /* CKABEN */
    using chcfg0r1_ckaben = lp::assoc_bit<chcfg0r1, 6>;
    /* SCDEN */
    using chcfg0r1_scden = lp::assoc_bit<chcfg0r1, 5>;
    /* SPICKSEL */
    using chcfg0r1_spicksel = lp::assoc_bit<chcfg0r1, 2, 2>;
    /* SITP */
    using chcfg0r1_sitp = lp::assoc_bit<chcfg0r1, 0, 2>;


    /* channel configuration y           register */
    using chcfg0r2 = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* OFFSET */
    using chcfg0r2_offset = lp::assoc_bit<chcfg0r2, 8, 24>;
    /* DTRBS */
    using chcfg0r2_dtrbs = lp::assoc_bit<chcfg0r2, 3, 5>;


    /* analog watchdog and short-circuit detector           register */
    using awscd0r = lp::io_register<lp::u32_t, base_address + 0x8>;
    /* AWFORD */
    using awscd0r_awford = lp::assoc_bit<awscd0r, 22, 2>;
    /* AWFOSR */
    using awscd0r_awfosr = lp::assoc_bit<awscd0r, 16, 5>;
    /* BKSCD */
    using awscd0r_bkscd = lp::assoc_bit<awscd0r, 12, 4>;
    /* SCDT */
    using awscd0r_scdt = lp::assoc_bit<awscd0r, 0, 8>;


    /* channel watchdog filter data           register */
    using chwdat0r = lp::io_register<lp::u32_t, base_address + 0xc>;
    /* WDATA */
    using chwdat0r_wdata = lp::assoc_bit<chwdat0r, 0, 16>;


    /* channel data input register */
    using chdatin0r = lp::io_register<lp::u32_t, base_address + 0x10>;
    /* INDAT1 */
    using chdatin0r_indat1 = lp::assoc_bit<chdatin0r, 16, 16>;
    /* INDAT0 */
    using chdatin0r_indat0 = lp::assoc_bit<chdatin0r, 0, 16>;


    /* CHCFG1R1 */
    using chcfg1r1 = lp::io_register<lp::u32_t, base_address + 0x20>;
    /* DATPACK */
    using chcfg1r1_datpack = lp::assoc_bit<chcfg1r1, 14, 2>;
    /* DATMPX */
    using chcfg1r1_datmpx = lp::assoc_bit<chcfg1r1, 12, 2>;
    /* CHINSEL */
    using chcfg1r1_chinsel = lp::assoc_bit<chcfg1r1, 8>;
    /* CHEN */
    using chcfg1r1_chen = lp::assoc_bit<chcfg1r1, 7>;
    /* CKABEN */
    using chcfg1r1_ckaben = lp::assoc_bit<chcfg1r1, 6>;
    /* SCDEN */
    using chcfg1r1_scden = lp::assoc_bit<chcfg1r1, 5>;
    /* SPICKSEL */
    using chcfg1r1_spicksel = lp::assoc_bit<chcfg1r1, 2, 2>;
    /* SITP */
    using chcfg1r1_sitp = lp::assoc_bit<chcfg1r1, 0, 2>;


    /* CHCFG1R2 */
    using chcfg1r2 = lp::io_register<lp::u32_t, base_address + 0x24>;
    /* OFFSET */
    using chcfg1r2_offset = lp::assoc_bit<chcfg1r2, 8, 24>;
    /* DTRBS */
    using chcfg1r2_dtrbs = lp::assoc_bit<chcfg1r2, 3, 5>;


    /* AWSCD1R */
    using awscd1r = lp::io_register<lp::u32_t, base_address + 0x28>;
    /* AWFORD */
    using awscd1r_awford = lp::assoc_bit<awscd1r, 22, 2>;
    /* AWFOSR */
    using awscd1r_awfosr = lp::assoc_bit<awscd1r, 16, 5>;
    /* BKSCD */
    using awscd1r_bkscd = lp::assoc_bit<awscd1r, 12, 4>;
    /* SCDT */
    using awscd1r_scdt = lp::assoc_bit<awscd1r, 0, 8>;


    /* CHWDAT1R */
    using chwdat1r = lp::io_register<lp::u32_t, base_address + 0x2c>;
    /* WDATA */
    using chwdat1r_wdata = lp::assoc_bit<chwdat1r, 0, 16>;


    /* CHDATIN1R */
    using chdatin1r = lp::io_register<lp::u32_t, base_address + 0x30>;
    /* INDAT1 */
    using chdatin1r_indat1 = lp::assoc_bit<chdatin1r, 16, 16>;
    /* INDAT0 */
    using chdatin1r_indat0 = lp::assoc_bit<chdatin1r, 0, 16>;


    /* CHCFG2R1 */
    using chcfg2r1 = lp::io_register<lp::u32_t, base_address + 0x40>;
    /* DATPACK */
    using chcfg2r1_datpack = lp::assoc_bit<chcfg2r1, 14, 2>;
    /* DATMPX */
    using chcfg2r1_datmpx = lp::assoc_bit<chcfg2r1, 12, 2>;
    /* CHINSEL */
    using chcfg2r1_chinsel = lp::assoc_bit<chcfg2r1, 8>;
    /* CHEN */
    using chcfg2r1_chen = lp::assoc_bit<chcfg2r1, 7>;
    /* CKABEN */
    using chcfg2r1_ckaben = lp::assoc_bit<chcfg2r1, 6>;
    /* SCDEN */
    using chcfg2r1_scden = lp::assoc_bit<chcfg2r1, 5>;
    /* SPICKSEL */
    using chcfg2r1_spicksel = lp::assoc_bit<chcfg2r1, 2, 2>;
    /* SITP */
    using chcfg2r1_sitp = lp::assoc_bit<chcfg2r1, 0, 2>;


    /* CHCFG2R2 */
    using chcfg2r2 = lp::io_register<lp::u32_t, base_address + 0x44>;
    /* OFFSET */
    using chcfg2r2_offset = lp::assoc_bit<chcfg2r2, 8, 24>;
    /* DTRBS */
    using chcfg2r2_dtrbs = lp::assoc_bit<chcfg2r2, 3, 5>;


    /* AWSCD2R */
    using awscd2r = lp::io_register<lp::u32_t, base_address + 0x48>;
    /* AWFORD */
    using awscd2r_awford = lp::assoc_bit<awscd2r, 22, 2>;
    /* AWFOSR */
    using awscd2r_awfosr = lp::assoc_bit<awscd2r, 16, 5>;
    /* BKSCD */
    using awscd2r_bkscd = lp::assoc_bit<awscd2r, 12, 4>;
    /* SCDT */
    using awscd2r_scdt = lp::assoc_bit<awscd2r, 0, 8>;


    /* CHWDAT2R */
    using chwdat2r = lp::io_register<lp::u32_t, base_address + 0x4c>;
    /* WDATA */
    using chwdat2r_wdata = lp::assoc_bit<chwdat2r, 0, 16>;


    /* CHDATIN2R */
    using chdatin2r = lp::io_register<lp::u32_t, base_address + 0x50>;
    /* INDAT1 */
    using chdatin2r_indat1 = lp::assoc_bit<chdatin2r, 16, 16>;
    /* INDAT0 */
    using chdatin2r_indat0 = lp::assoc_bit<chdatin2r, 0, 16>;


    /* CHCFG3R1 */
    using chcfg3r1 = lp::io_register<lp::u32_t, base_address + 0x60>;
    /* DATPACK */
    using chcfg3r1_datpack = lp::assoc_bit<chcfg3r1, 14, 2>;
    /* DATMPX */
    using chcfg3r1_datmpx = lp::assoc_bit<chcfg3r1, 12, 2>;
    /* CHINSEL */
    using chcfg3r1_chinsel = lp::assoc_bit<chcfg3r1, 8>;
    /* CHEN */
    using chcfg3r1_chen = lp::assoc_bit<chcfg3r1, 7>;
    /* CKABEN */
    using chcfg3r1_ckaben = lp::assoc_bit<chcfg3r1, 6>;
    /* SCDEN */
    using chcfg3r1_scden = lp::assoc_bit<chcfg3r1, 5>;
    /* SPICKSEL */
    using chcfg3r1_spicksel = lp::assoc_bit<chcfg3r1, 2, 2>;
    /* SITP */
    using chcfg3r1_sitp = lp::assoc_bit<chcfg3r1, 0, 2>;


    /* CHCFG3R2 */
    using chcfg3r2 = lp::io_register<lp::u32_t, base_address + 0x64>;
    /* OFFSET */
    using chcfg3r2_offset = lp::assoc_bit<chcfg3r2, 8, 24>;
    /* DTRBS */
    using chcfg3r2_dtrbs = lp::assoc_bit<chcfg3r2, 3, 5>;


    /* AWSCD3R */
    using awscd3r = lp::io_register<lp::u32_t, base_address + 0x68>;
    /* AWFORD */
    using awscd3r_awford = lp::assoc_bit<awscd3r, 22, 2>;
    /* AWFOSR */
    using awscd3r_awfosr = lp::assoc_bit<awscd3r, 16, 5>;
    /* BKSCD */
    using awscd3r_bkscd = lp::assoc_bit<awscd3r, 12, 4>;
    /* SCDT */
    using awscd3r_scdt = lp::assoc_bit<awscd3r, 0, 8>;


    /* CHWDAT3R */
    using chwdat3r = lp::io_register<lp::u32_t, base_address + 0x6c>;
    /* WDATA */
    using chwdat3r_wdata = lp::assoc_bit<chwdat3r, 0, 16>;


    /* CHDATIN3R */
    using chdatin3r = lp::io_register<lp::u32_t, base_address + 0x70>;
    /* INDAT1 */
    using chdatin3r_indat1 = lp::assoc_bit<chdatin3r, 16, 16>;
    /* INDAT0 */
    using chdatin3r_indat0 = lp::assoc_bit<chdatin3r, 0, 16>;


    /* CHCFG4R1 */
    using chcfg4r1 = lp::io_register<lp::u32_t, base_address + 0x80>;
    /* DATPACK */
    using chcfg4r1_datpack = lp::assoc_bit<chcfg4r1, 14, 2>;
    /* DATMPX */
    using chcfg4r1_datmpx = lp::assoc_bit<chcfg4r1, 12, 2>;
    /* CHINSEL */
    using chcfg4r1_chinsel = lp::assoc_bit<chcfg4r1, 8>;
    /* CHEN */
    using chcfg4r1_chen = lp::assoc_bit<chcfg4r1, 7>;
    /* CKABEN */
    using chcfg4r1_ckaben = lp::assoc_bit<chcfg4r1, 6>;
    /* SCDEN */
    using chcfg4r1_scden = lp::assoc_bit<chcfg4r1, 5>;
    /* SPICKSEL */
    using chcfg4r1_spicksel = lp::assoc_bit<chcfg4r1, 2, 2>;
    /* SITP */
    using chcfg4r1_sitp = lp::assoc_bit<chcfg4r1, 0, 2>;


    /* CHCFG4R2 */
    using chcfg4r2 = lp::io_register<lp::u32_t, base_address + 0x84>;
    /* OFFSET */
    using chcfg4r2_offset = lp::assoc_bit<chcfg4r2, 8, 24>;
    /* DTRBS */
    using chcfg4r2_dtrbs = lp::assoc_bit<chcfg4r2, 3, 5>;


    /* AWSCD4R */
    using awscd4r = lp::io_register<lp::u32_t, base_address + 0x88>;
    /* AWFORD */
    using awscd4r_awford = lp::assoc_bit<awscd4r, 22, 2>;
    /* AWFOSR */
    using awscd4r_awfosr = lp::assoc_bit<awscd4r, 16, 5>;
    /* BKSCD */
    using awscd4r_bkscd = lp::assoc_bit<awscd4r, 12, 4>;
    /* SCDT */
    using awscd4r_scdt = lp::assoc_bit<awscd4r, 0, 8>;


    /* CHWDAT4R */
    using chwdat4r = lp::io_register<lp::u32_t, base_address + 0x8c>;
    /* WDATA */
    using chwdat4r_wdata = lp::assoc_bit<chwdat4r, 0, 16>;


    /* CHDATIN4R */
    using chdatin4r = lp::io_register<lp::u32_t, base_address + 0x90>;
    /* INDAT1 */
    using chdatin4r_indat1 = lp::assoc_bit<chdatin4r, 16, 16>;
    /* INDAT0 */
    using chdatin4r_indat0 = lp::assoc_bit<chdatin4r, 0, 16>;


    /* CHCFG5R1 */
    using chcfg5r1 = lp::io_register<lp::u32_t, base_address + 0xa0>;
    /* DATPACK */
    using chcfg5r1_datpack = lp::assoc_bit<chcfg5r1, 14, 2>;
    /* DATMPX */
    using chcfg5r1_datmpx = lp::assoc_bit<chcfg5r1, 12, 2>;
    /* CHINSEL */
    using chcfg5r1_chinsel = lp::assoc_bit<chcfg5r1, 8>;
    /* CHEN */
    using chcfg5r1_chen = lp::assoc_bit<chcfg5r1, 7>;
    /* CKABEN */
    using chcfg5r1_ckaben = lp::assoc_bit<chcfg5r1, 6>;
    /* SCDEN */
    using chcfg5r1_scden = lp::assoc_bit<chcfg5r1, 5>;
    /* SPICKSEL */
    using chcfg5r1_spicksel = lp::assoc_bit<chcfg5r1, 2, 2>;
    /* SITP */
    using chcfg5r1_sitp = lp::assoc_bit<chcfg5r1, 0, 2>;


    /* CHCFG5R2 */
    using chcfg5r2 = lp::io_register<lp::u32_t, base_address + 0xa4>;
    /* OFFSET */
    using chcfg5r2_offset = lp::assoc_bit<chcfg5r2, 8, 24>;
    /* DTRBS */
    using chcfg5r2_dtrbs = lp::assoc_bit<chcfg5r2, 3, 5>;


    /* AWSCD5R */
    using awscd5r = lp::io_register<lp::u32_t, base_address + 0xa8>;
    /* AWFORD */
    using awscd5r_awford = lp::assoc_bit<awscd5r, 22, 2>;
    /* AWFOSR */
    using awscd5r_awfosr = lp::assoc_bit<awscd5r, 16, 5>;
    /* BKSCD */
    using awscd5r_bkscd = lp::assoc_bit<awscd5r, 12, 4>;
    /* SCDT */
    using awscd5r_scdt = lp::assoc_bit<awscd5r, 0, 8>;


    /* CHWDAT5R */
    using chwdat5r = lp::io_register<lp::u32_t, base_address + 0xac>;
    /* WDATA */
    using chwdat5r_wdata = lp::assoc_bit<chwdat5r, 0, 16>;


    /* CHDATIN5R */
    using chdatin5r = lp::io_register<lp::u32_t, base_address + 0xb0>;
    /* INDAT1 */
    using chdatin5r_indat1 = lp::assoc_bit<chdatin5r, 16, 16>;
    /* INDAT0 */
    using chdatin5r_indat0 = lp::assoc_bit<chdatin5r, 0, 16>;


    /* CHCFG6R1 */
    using chcfg6r1 = lp::io_register<lp::u32_t, base_address + 0xc0>;
    /* DATPACK */
    using chcfg6r1_datpack = lp::assoc_bit<chcfg6r1, 14, 2>;
    /* DATMPX */
    using chcfg6r1_datmpx = lp::assoc_bit<chcfg6r1, 12, 2>;
    /* CHINSEL */
    using chcfg6r1_chinsel = lp::assoc_bit<chcfg6r1, 8>;
    /* CHEN */
    using chcfg6r1_chen = lp::assoc_bit<chcfg6r1, 7>;
    /* CKABEN */
    using chcfg6r1_ckaben = lp::assoc_bit<chcfg6r1, 6>;
    /* SCDEN */
    using chcfg6r1_scden = lp::assoc_bit<chcfg6r1, 5>;
    /* SPICKSEL */
    using chcfg6r1_spicksel = lp::assoc_bit<chcfg6r1, 2, 2>;
    /* SITP */
    using chcfg6r1_sitp = lp::assoc_bit<chcfg6r1, 0, 2>;


    /* CHCFG6R2 */
    using chcfg6r2 = lp::io_register<lp::u32_t, base_address + 0xc4>;
    /* OFFSET */
    using chcfg6r2_offset = lp::assoc_bit<chcfg6r2, 8, 24>;
    /* DTRBS */
    using chcfg6r2_dtrbs = lp::assoc_bit<chcfg6r2, 3, 5>;


    /* AWSCD6R */
    using awscd6r = lp::io_register<lp::u32_t, base_address + 0xc8>;
    /* AWFORD */
    using awscd6r_awford = lp::assoc_bit<awscd6r, 22, 2>;
    /* AWFOSR */
    using awscd6r_awfosr = lp::assoc_bit<awscd6r, 16, 5>;
    /* BKSCD */
    using awscd6r_bkscd = lp::assoc_bit<awscd6r, 12, 4>;
    /* SCDT */
    using awscd6r_scdt = lp::assoc_bit<awscd6r, 0, 8>;


    /* CHWDAT6R */
    using chwdat6r = lp::io_register<lp::u32_t, base_address + 0xcc>;
    /* WDATA */
    using chwdat6r_wdata = lp::assoc_bit<chwdat6r, 0, 16>;


    /* CHDATIN6R */
    using chdatin6r = lp::io_register<lp::u32_t, base_address + 0xd0>;
    /* INDAT1 */
    using chdatin6r_indat1 = lp::assoc_bit<chdatin6r, 16, 16>;
    /* INDAT0 */
    using chdatin6r_indat0 = lp::assoc_bit<chdatin6r, 0, 16>;


    /* CHCFG7R1 */
    using chcfg7r1 = lp::io_register<lp::u32_t, base_address + 0xe0>;
    /* DATPACK */
    using chcfg7r1_datpack = lp::assoc_bit<chcfg7r1, 14, 2>;
    /* DATMPX */
    using chcfg7r1_datmpx = lp::assoc_bit<chcfg7r1, 12, 2>;
    /* CHINSEL */
    using chcfg7r1_chinsel = lp::assoc_bit<chcfg7r1, 8>;
    /* CHEN */
    using chcfg7r1_chen = lp::assoc_bit<chcfg7r1, 7>;
    /* CKABEN */
    using chcfg7r1_ckaben = lp::assoc_bit<chcfg7r1, 6>;
    /* SCDEN */
    using chcfg7r1_scden = lp::assoc_bit<chcfg7r1, 5>;
    /* SPICKSEL */
    using chcfg7r1_spicksel = lp::assoc_bit<chcfg7r1, 2, 2>;
    /* SITP */
    using chcfg7r1_sitp = lp::assoc_bit<chcfg7r1, 0, 2>;


    /* CHCFG7R2 */
    using chcfg7r2 = lp::io_register<lp::u32_t, base_address + 0xe4>;
    /* OFFSET */
    using chcfg7r2_offset = lp::assoc_bit<chcfg7r2, 8, 24>;
    /* DTRBS */
    using chcfg7r2_dtrbs = lp::assoc_bit<chcfg7r2, 3, 5>;


    /* AWSCD7R */
    using awscd7r = lp::io_register<lp::u32_t, base_address + 0xe8>;
    /* AWFORD */
    using awscd7r_awford = lp::assoc_bit<awscd7r, 22, 2>;
    /* AWFOSR */
    using awscd7r_awfosr = lp::assoc_bit<awscd7r, 16, 5>;
    /* BKSCD */
    using awscd7r_bkscd = lp::assoc_bit<awscd7r, 12, 4>;
    /* SCDT */
    using awscd7r_scdt = lp::assoc_bit<awscd7r, 0, 8>;


    /* CHWDAT7R */
    using chwdat7r = lp::io_register<lp::u32_t, base_address + 0xec>;
    /* WDATA */
    using chwdat7r_wdata = lp::assoc_bit<chwdat7r, 0, 16>;


    /* CHDATIN7R */
    using chdatin7r = lp::io_register<lp::u32_t, base_address + 0xf0>;
    /* INDAT1 */
    using chdatin7r_indat1 = lp::assoc_bit<chdatin7r, 16, 16>;
    /* INDAT0 */
    using chdatin7r_indat0 = lp::assoc_bit<chdatin7r, 0, 16>;


    /* control register 1 */
    using dfsdm0_cr1 = lp::io_register<lp::u32_t, base_address + 0x100>;
    /* Analog watchdog fast mode               select */
    using dfsdm0_cr1_awfsel = lp::assoc_bit<dfsdm0_cr1, 30>;
    /* Fast conversion mode selection for               regular conversions */
    using dfsdm0_cr1_fast = lp::assoc_bit<dfsdm0_cr1, 29>;
    /* Regular channel selection */
    using dfsdm0_cr1_rch = lp::assoc_bit<dfsdm0_cr1, 24, 3>;
    /* DMA channel enabled to read data for the               regular conversion */
    using dfsdm0_cr1_rdmaen = lp::assoc_bit<dfsdm0_cr1, 21>;
    /* Launch regular conversion synchronously               with DFSDM0 */
    using dfsdm0_cr1_rsync = lp::assoc_bit<dfsdm0_cr1, 19>;
    /* Continuous mode selection for regular               conversions */
    using dfsdm0_cr1_rcont = lp::assoc_bit<dfsdm0_cr1, 18>;
    /* Software start of a conversion on the               regular channel */
    using dfsdm0_cr1_rswstart = lp::assoc_bit<dfsdm0_cr1, 17>;
    /* Trigger enable and trigger edge               selection for injected conversions */
    using dfsdm0_cr1_jexten = lp::assoc_bit<dfsdm0_cr1, 13, 2>;
    /* Trigger signal selection for launching               injected conversions */
    using dfsdm0_cr1_jextsel = lp::assoc_bit<dfsdm0_cr1, 8, 3>;
    /* DMA channel enabled to read data for the               injected channel group */
    using dfsdm0_cr1_jdmaen = lp::assoc_bit<dfsdm0_cr1, 5>;
    /* Scanning conversion mode for injected               conversions */
    using dfsdm0_cr1_jscan = lp::assoc_bit<dfsdm0_cr1, 4>;
    /* Launch an injected conversion               synchronously with the DFSDM0 JSWSTART               trigger */
    using dfsdm0_cr1_jsync = lp::assoc_bit<dfsdm0_cr1, 3>;
    /* Start a conversion of the injected group               of channels */
    using dfsdm0_cr1_jswstart = lp::assoc_bit<dfsdm0_cr1, 1>;
    /* DFSDM enable */
    using dfsdm0_cr1_dfen = lp::assoc_bit<dfsdm0_cr1, 0>;


    /* control register 2 */
    using dfsdm0_cr2 = lp::io_register<lp::u32_t, base_address + 0x104>;
    /* Analog watchdog channel               selection */
    using dfsdm0_cr2_awdch = lp::assoc_bit<dfsdm0_cr2, 16, 8>;
    /* Extremes detector channel               selection */
    using dfsdm0_cr2_exch = lp::assoc_bit<dfsdm0_cr2, 8, 8>;
    /* Clock absence interrupt               enable */
    using dfsdm0_cr2_ckabie = lp::assoc_bit<dfsdm0_cr2, 6>;
    /* Short-circuit detector interrupt               enable */
    using dfsdm0_cr2_scdie = lp::assoc_bit<dfsdm0_cr2, 5>;
    /* Analog watchdog interrupt               enable */
    using dfsdm0_cr2_awdie = lp::assoc_bit<dfsdm0_cr2, 4>;
    /* Regular data overrun interrupt               enable */
    using dfsdm0_cr2_rovrie = lp::assoc_bit<dfsdm0_cr2, 3>;
    /* Injected data overrun interrupt               enable */
    using dfsdm0_cr2_jovrie = lp::assoc_bit<dfsdm0_cr2, 2>;
    /* Regular end of conversion interrupt               enable */
    using dfsdm0_cr2_reocie = lp::assoc_bit<dfsdm0_cr2, 1>;
    /* Injected end of conversion interrupt               enable */
    using dfsdm0_cr2_jeocie = lp::assoc_bit<dfsdm0_cr2, 0>;


    /* interrupt and status register */
    using dfsdm0_isr = lp::io_register<lp::u32_t, base_address + 0x108>;
    /* short-circuit detector               flag */
    using dfsdm0_isr_scdf = lp::assoc_bit<dfsdm0_isr, 24, 8>;
    /* Clock absence flag */
    using dfsdm0_isr_ckabf = lp::assoc_bit<dfsdm0_isr, 16, 8>;
    /* Regular conversion in progress               status */
    using dfsdm0_isr_rcip = lp::assoc_bit<dfsdm0_isr, 14>;
    /* Injected conversion in progress               status */
    using dfsdm0_isr_jcip = lp::assoc_bit<dfsdm0_isr, 13>;
    /* Analog watchdog */
    using dfsdm0_isr_awdf = lp::assoc_bit<dfsdm0_isr, 4>;
    /* Regular conversion overrun               flag */
    using dfsdm0_isr_rovrf = lp::assoc_bit<dfsdm0_isr, 3>;
    /* Injected conversion overrun               flag */
    using dfsdm0_isr_jovrf = lp::assoc_bit<dfsdm0_isr, 2>;
    /* End of regular conversion               flag */
    using dfsdm0_isr_reocf = lp::assoc_bit<dfsdm0_isr, 1>;
    /* End of injected conversion               flag */
    using dfsdm0_isr_jeocf = lp::assoc_bit<dfsdm0_isr, 0>;


    /* interrupt flag clear register */
    using dfsdm0_icr = lp::io_register<lp::u32_t, base_address + 0x10c>;
    /* Clear the short-circuit detector               flag */
    using dfsdm0_icr_clrscdf = lp::assoc_bit<dfsdm0_icr, 24, 8>;
    /* Clear the clock absence               flag */
    using dfsdm0_icr_clrckabf = lp::assoc_bit<dfsdm0_icr, 16, 8>;
    /* Clear the regular conversion overrun               flag */
    using dfsdm0_icr_clrrovrf = lp::assoc_bit<dfsdm0_icr, 3>;
    /* Clear the injected conversion overrun               flag */
    using dfsdm0_icr_clrjovrf = lp::assoc_bit<dfsdm0_icr, 2>;


    /* injected channel group selection           register */
    using dfsdm0_jchgr = lp::io_register<lp::u32_t, base_address + 0x110>;
    /* Injected channel group               selection */
    using dfsdm0_jchgr_jchg = lp::assoc_bit<dfsdm0_jchgr, 0, 8>;


    /* filter control register */
    using dfsdm0_fcr = lp::io_register<lp::u32_t, base_address + 0x114>;
    /* Sinc filter order */
    using dfsdm0_fcr_ford = lp::assoc_bit<dfsdm0_fcr, 29, 3>;
    /* Sinc filter oversampling ratio               (decimation rate) */
    using dfsdm0_fcr_fosr = lp::assoc_bit<dfsdm0_fcr, 16, 10>;
    /* Integrator oversampling ratio (averaging               length) */
    using dfsdm0_fcr_iosr = lp::assoc_bit<dfsdm0_fcr, 0, 8>;


    /* data register for injected           group */
    using dfsdm0_jdatar = lp::io_register<lp::u32_t, base_address + 0x118>;
    /* Injected group conversion               data */
    using dfsdm0_jdatar_jdata = lp::assoc_bit<dfsdm0_jdatar, 8, 24>;
    /* Injected channel most recently               converted */
    using dfsdm0_jdatar_jdatach = lp::assoc_bit<dfsdm0_jdatar, 0, 3>;


    /* data register for the regular           channel */
    using dfsdm0_rdatar = lp::io_register<lp::u32_t, base_address + 0x11c>;
    /* Regular channel conversion               data */
    using dfsdm0_rdatar_rdata = lp::assoc_bit<dfsdm0_rdatar, 8, 24>;
    /* Regular channel pending               data */
    using dfsdm0_rdatar_rpend = lp::assoc_bit<dfsdm0_rdatar, 4>;
    /* Regular channel most recently               converted */
    using dfsdm0_rdatar_rdatach = lp::assoc_bit<dfsdm0_rdatar, 0, 3>;


    /* analog watchdog high threshold           register */
    using dfsdm0_awhtr = lp::io_register<lp::u32_t, base_address + 0x120>;
    /* Analog watchdog high               threshold */
    using dfsdm0_awhtr_awht = lp::assoc_bit<dfsdm0_awhtr, 8, 24>;
    /* Break signal assignment to analog               watchdog high threshold event */
    using dfsdm0_awhtr_bkawh = lp::assoc_bit<dfsdm0_awhtr, 0, 4>;


    /* analog watchdog low threshold           register */
    using dfsdm0_awltr = lp::io_register<lp::u32_t, base_address + 0x124>;
    /* Analog watchdog low               threshold */
    using dfsdm0_awltr_awlt = lp::assoc_bit<dfsdm0_awltr, 8, 24>;
    /* Break signal assignment to analog               watchdog low threshold event */
    using dfsdm0_awltr_bkawl = lp::assoc_bit<dfsdm0_awltr, 0, 4>;


    /* analog watchdog status           register */
    using dfsdm0_awsr = lp::io_register<lp::u32_t, base_address + 0x128>;
    /* Analog watchdog high threshold               flag */
    using dfsdm0_awsr_awhtf = lp::assoc_bit<dfsdm0_awsr, 8, 8>;
    /* Analog watchdog low threshold               flag */
    using dfsdm0_awsr_awltf = lp::assoc_bit<dfsdm0_awsr, 0, 8>;


    /* analog watchdog clear flag           register */
    using dfsdm0_awcfr = lp::io_register<lp::u32_t, base_address + 0x12c>;
    /* Clear the analog watchdog high threshold               flag */
    using dfsdm0_awcfr_clrawhtf = lp::assoc_bit<dfsdm0_awcfr, 8, 8>;
    /* Clear the analog watchdog low threshold               flag */
    using dfsdm0_awcfr_clrawltf = lp::assoc_bit<dfsdm0_awcfr, 0, 8>;


    /* Extremes detector maximum           register */
    using dfsdm0_exmax = lp::io_register<lp::u32_t, base_address + 0x130>;
    /* Extremes detector maximum               value */
    using dfsdm0_exmax_exmax = lp::assoc_bit<dfsdm0_exmax, 8, 24>;
    /* Extremes detector maximum data               channel */
    using dfsdm0_exmax_exmaxch = lp::assoc_bit<dfsdm0_exmax, 0, 3>;


    /* Extremes detector minimum           register */
    using dfsdm0_exmin = lp::io_register<lp::u32_t, base_address + 0x134>;
    /* EXMIN */
    using dfsdm0_exmin_exmin = lp::assoc_bit<dfsdm0_exmin, 8, 24>;
    /* Extremes detector minimum data               channel */
    using dfsdm0_exmin_exminch = lp::assoc_bit<dfsdm0_exmin, 0, 3>;


    /* conversion timer register */
    using dfsdm0_cnvtimr = lp::io_register<lp::u32_t, base_address + 0x138>;
    /* 28-bit timer counting conversion time t               = CNVCNT[27:0] / fDFSDM_CKIN */
    using dfsdm0_cnvtimr_cnvcnt = lp::assoc_bit<dfsdm0_cnvtimr, 4, 28>;


    /* control register 1 */
    using dfsdm1_cr1 = lp::io_register<lp::u32_t, base_address + 0x200>;
    /* Analog watchdog fast mode               select */
    using dfsdm1_cr1_awfsel = lp::assoc_bit<dfsdm1_cr1, 30>;
    /* Fast conversion mode selection for               regular conversions */
    using dfsdm1_cr1_fast = lp::assoc_bit<dfsdm1_cr1, 29>;
    /* Regular channel selection */
    using dfsdm1_cr1_rch = lp::assoc_bit<dfsdm1_cr1, 24, 3>;
    /* DMA channel enabled to read data for the               regular conversion */
    using dfsdm1_cr1_rdmaen = lp::assoc_bit<dfsdm1_cr1, 21>;
    /* Launch regular conversion synchronously               with DFSDM0 */
    using dfsdm1_cr1_rsync = lp::assoc_bit<dfsdm1_cr1, 19>;
    /* Continuous mode selection for regular               conversions */
    using dfsdm1_cr1_rcont = lp::assoc_bit<dfsdm1_cr1, 18>;
    /* Software start of a conversion on the               regular channel */
    using dfsdm1_cr1_rswstart = lp::assoc_bit<dfsdm1_cr1, 17>;
    /* Trigger enable and trigger edge               selection for injected conversions */
    using dfsdm1_cr1_jexten = lp::assoc_bit<dfsdm1_cr1, 13, 2>;
    /* Trigger signal selection for launching               injected conversions */
    using dfsdm1_cr1_jextsel = lp::assoc_bit<dfsdm1_cr1, 8, 3>;
    /* DMA channel enabled to read data for the               injected channel group */
    using dfsdm1_cr1_jdmaen = lp::assoc_bit<dfsdm1_cr1, 5>;
    /* Scanning conversion mode for injected               conversions */
    using dfsdm1_cr1_jscan = lp::assoc_bit<dfsdm1_cr1, 4>;
    /* Launch an injected conversion               synchronously with the DFSDM0 JSWSTART               trigger */
    using dfsdm1_cr1_jsync = lp::assoc_bit<dfsdm1_cr1, 3>;
    /* Start a conversion of the injected group               of channels */
    using dfsdm1_cr1_jswstart = lp::assoc_bit<dfsdm1_cr1, 1>;
    /* DFSDM enable */
    using dfsdm1_cr1_dfen = lp::assoc_bit<dfsdm1_cr1, 0>;


    /* control register 2 */
    using dfsdm1_cr2 = lp::io_register<lp::u32_t, base_address + 0x204>;
    /* Analog watchdog channel               selection */
    using dfsdm1_cr2_awdch = lp::assoc_bit<dfsdm1_cr2, 16, 8>;
    /* Extremes detector channel               selection */
    using dfsdm1_cr2_exch = lp::assoc_bit<dfsdm1_cr2, 8, 8>;
    /* Clock absence interrupt               enable */
    using dfsdm1_cr2_ckabie = lp::assoc_bit<dfsdm1_cr2, 6>;
    /* Short-circuit detector interrupt               enable */
    using dfsdm1_cr2_scdie = lp::assoc_bit<dfsdm1_cr2, 5>;
    /* Analog watchdog interrupt               enable */
    using dfsdm1_cr2_awdie = lp::assoc_bit<dfsdm1_cr2, 4>;
    /* Regular data overrun interrupt               enable */
    using dfsdm1_cr2_rovrie = lp::assoc_bit<dfsdm1_cr2, 3>;
    /* Injected data overrun interrupt               enable */
    using dfsdm1_cr2_jovrie = lp::assoc_bit<dfsdm1_cr2, 2>;
    /* Regular end of conversion interrupt               enable */
    using dfsdm1_cr2_reocie = lp::assoc_bit<dfsdm1_cr2, 1>;
    /* Injected end of conversion interrupt               enable */
    using dfsdm1_cr2_jeocie = lp::assoc_bit<dfsdm1_cr2, 0>;


    /* interrupt and status register */
    using dfsdm1_isr = lp::io_register<lp::u32_t, base_address + 0x208>;
    /* short-circuit detector               flag */
    using dfsdm1_isr_scdf = lp::assoc_bit<dfsdm1_isr, 24, 8>;
    /* Clock absence flag */
    using dfsdm1_isr_ckabf = lp::assoc_bit<dfsdm1_isr, 16, 8>;
    /* Regular conversion in progress               status */
    using dfsdm1_isr_rcip = lp::assoc_bit<dfsdm1_isr, 14>;
    /* Injected conversion in progress               status */
    using dfsdm1_isr_jcip = lp::assoc_bit<dfsdm1_isr, 13>;
    /* Analog watchdog */
    using dfsdm1_isr_awdf = lp::assoc_bit<dfsdm1_isr, 4>;
    /* Regular conversion overrun               flag */
    using dfsdm1_isr_rovrf = lp::assoc_bit<dfsdm1_isr, 3>;
    /* Injected conversion overrun               flag */
    using dfsdm1_isr_jovrf = lp::assoc_bit<dfsdm1_isr, 2>;
    /* End of regular conversion               flag */
    using dfsdm1_isr_reocf = lp::assoc_bit<dfsdm1_isr, 1>;
    /* End of injected conversion               flag */
    using dfsdm1_isr_jeocf = lp::assoc_bit<dfsdm1_isr, 0>;


    /* interrupt flag clear register */
    using dfsdm1_icr = lp::io_register<lp::u32_t, base_address + 0x20c>;
    /* Clear the short-circuit detector               flag */
    using dfsdm1_icr_clrscdf = lp::assoc_bit<dfsdm1_icr, 24, 8>;
    /* Clear the clock absence               flag */
    using dfsdm1_icr_clrckabf = lp::assoc_bit<dfsdm1_icr, 16, 8>;
    /* Clear the regular conversion overrun               flag */
    using dfsdm1_icr_clrrovrf = lp::assoc_bit<dfsdm1_icr, 3>;
    /* Clear the injected conversion overrun               flag */
    using dfsdm1_icr_clrjovrf = lp::assoc_bit<dfsdm1_icr, 2>;


    /* injected channel group selection           register */
    using dfsdm1_jchgr = lp::io_register<lp::u32_t, base_address + 0x210>;
    /* Injected channel group               selection */
    using dfsdm1_jchgr_jchg = lp::assoc_bit<dfsdm1_jchgr, 0, 8>;


    /* filter control register */
    using dfsdm1_fcr = lp::io_register<lp::u32_t, base_address + 0x214>;
    /* Sinc filter order */
    using dfsdm1_fcr_ford = lp::assoc_bit<dfsdm1_fcr, 29, 3>;
    /* Sinc filter oversampling ratio               (decimation rate) */
    using dfsdm1_fcr_fosr = lp::assoc_bit<dfsdm1_fcr, 16, 10>;
    /* Integrator oversampling ratio (averaging               length) */
    using dfsdm1_fcr_iosr = lp::assoc_bit<dfsdm1_fcr, 0, 8>;


    /* data register for injected           group */
    using dfsdm1_jdatar = lp::io_register<lp::u32_t, base_address + 0x218>;
    /* Injected group conversion               data */
    using dfsdm1_jdatar_jdata = lp::assoc_bit<dfsdm1_jdatar, 8, 24>;
    /* Injected channel most recently               converted */
    using dfsdm1_jdatar_jdatach = lp::assoc_bit<dfsdm1_jdatar, 0, 3>;


    /* data register for the regular           channel */
    using dfsdm1_rdatar = lp::io_register<lp::u32_t, base_address + 0x21c>;
    /* Regular channel conversion               data */
    using dfsdm1_rdatar_rdata = lp::assoc_bit<dfsdm1_rdatar, 8, 24>;
    /* Regular channel pending               data */
    using dfsdm1_rdatar_rpend = lp::assoc_bit<dfsdm1_rdatar, 4>;
    /* Regular channel most recently               converted */
    using dfsdm1_rdatar_rdatach = lp::assoc_bit<dfsdm1_rdatar, 0, 3>;


    /* analog watchdog high threshold           register */
    using dfsdm1_awhtr = lp::io_register<lp::u32_t, base_address + 0x220>;
    /* Analog watchdog high               threshold */
    using dfsdm1_awhtr_awht = lp::assoc_bit<dfsdm1_awhtr, 8, 24>;
    /* Break signal assignment to analog               watchdog high threshold event */
    using dfsdm1_awhtr_bkawh = lp::assoc_bit<dfsdm1_awhtr, 0, 4>;


    /* analog watchdog low threshold           register */
    using dfsdm1_awltr = lp::io_register<lp::u32_t, base_address + 0x224>;
    /* Analog watchdog low               threshold */
    using dfsdm1_awltr_awlt = lp::assoc_bit<dfsdm1_awltr, 8, 24>;
    /* Break signal assignment to analog               watchdog low threshold event */
    using dfsdm1_awltr_bkawl = lp::assoc_bit<dfsdm1_awltr, 0, 4>;


    /* analog watchdog status           register */
    using dfsdm1_awsr = lp::io_register<lp::u32_t, base_address + 0x228>;
    /* Analog watchdog high threshold               flag */
    using dfsdm1_awsr_awhtf = lp::assoc_bit<dfsdm1_awsr, 8, 8>;
    /* Analog watchdog low threshold               flag */
    using dfsdm1_awsr_awltf = lp::assoc_bit<dfsdm1_awsr, 0, 8>;


    /* analog watchdog clear flag           register */
    using dfsdm1_awcfr = lp::io_register<lp::u32_t, base_address + 0x22c>;
    /* Clear the analog watchdog high threshold               flag */
    using dfsdm1_awcfr_clrawhtf = lp::assoc_bit<dfsdm1_awcfr, 8, 8>;
    /* Clear the analog watchdog low threshold               flag */
    using dfsdm1_awcfr_clrawltf = lp::assoc_bit<dfsdm1_awcfr, 0, 8>;


    /* Extremes detector maximum           register */
    using dfsdm1_exmax = lp::io_register<lp::u32_t, base_address + 0x230>;
    /* Extremes detector maximum               value */
    using dfsdm1_exmax_exmax = lp::assoc_bit<dfsdm1_exmax, 8, 24>;
    /* Extremes detector maximum data               channel */
    using dfsdm1_exmax_exmaxch = lp::assoc_bit<dfsdm1_exmax, 0, 3>;


    /* Extremes detector minimum           register */
    using dfsdm1_exmin = lp::io_register<lp::u32_t, base_address + 0x234>;
    /* EXMIN */
    using dfsdm1_exmin_exmin = lp::assoc_bit<dfsdm1_exmin, 8, 24>;
    /* Extremes detector minimum data               channel */
    using dfsdm1_exmin_exminch = lp::assoc_bit<dfsdm1_exmin, 0, 3>;


    /* conversion timer register */
    using dfsdm1_cnvtimr = lp::io_register<lp::u32_t, base_address + 0x238>;
    /* 28-bit timer counting conversion time t               = CNVCNT[27:0] / fDFSDM_CKIN */
    using dfsdm1_cnvtimr_cnvcnt = lp::assoc_bit<dfsdm1_cnvtimr, 4, 28>;


    /* control register 1 */
    using dfsdm2_cr1 = lp::io_register<lp::u32_t, base_address + 0x300>;
    /* Analog watchdog fast mode               select */
    using dfsdm2_cr1_awfsel = lp::assoc_bit<dfsdm2_cr1, 30>;
    /* Fast conversion mode selection for               regular conversions */
    using dfsdm2_cr1_fast = lp::assoc_bit<dfsdm2_cr1, 29>;
    /* Regular channel selection */
    using dfsdm2_cr1_rch = lp::assoc_bit<dfsdm2_cr1, 24, 3>;
    /* DMA channel enabled to read data for the               regular conversion */
    using dfsdm2_cr1_rdmaen = lp::assoc_bit<dfsdm2_cr1, 21>;
    /* Launch regular conversion synchronously               with DFSDM0 */
    using dfsdm2_cr1_rsync = lp::assoc_bit<dfsdm2_cr1, 19>;
    /* Continuous mode selection for regular               conversions */
    using dfsdm2_cr1_rcont = lp::assoc_bit<dfsdm2_cr1, 18>;
    /* Software start of a conversion on the               regular channel */
    using dfsdm2_cr1_rswstart = lp::assoc_bit<dfsdm2_cr1, 17>;
    /* Trigger enable and trigger edge               selection for injected conversions */
    using dfsdm2_cr1_jexten = lp::assoc_bit<dfsdm2_cr1, 13, 2>;
    /* Trigger signal selection for launching               injected conversions */
    using dfsdm2_cr1_jextsel = lp::assoc_bit<dfsdm2_cr1, 8, 3>;
    /* DMA channel enabled to read data for the               injected channel group */
    using dfsdm2_cr1_jdmaen = lp::assoc_bit<dfsdm2_cr1, 5>;
    /* Scanning conversion mode for injected               conversions */
    using dfsdm2_cr1_jscan = lp::assoc_bit<dfsdm2_cr1, 4>;
    /* Launch an injected conversion               synchronously with the DFSDM0 JSWSTART               trigger */
    using dfsdm2_cr1_jsync = lp::assoc_bit<dfsdm2_cr1, 3>;
    /* Start a conversion of the injected group               of channels */
    using dfsdm2_cr1_jswstart = lp::assoc_bit<dfsdm2_cr1, 1>;
    /* DFSDM enable */
    using dfsdm2_cr1_dfen = lp::assoc_bit<dfsdm2_cr1, 0>;


    /* control register 2 */
    using dfsdm2_cr2 = lp::io_register<lp::u32_t, base_address + 0x304>;
    /* Analog watchdog channel               selection */
    using dfsdm2_cr2_awdch = lp::assoc_bit<dfsdm2_cr2, 16, 8>;
    /* Extremes detector channel               selection */
    using dfsdm2_cr2_exch = lp::assoc_bit<dfsdm2_cr2, 8, 8>;
    /* Clock absence interrupt               enable */
    using dfsdm2_cr2_ckabie = lp::assoc_bit<dfsdm2_cr2, 6>;
    /* Short-circuit detector interrupt               enable */
    using dfsdm2_cr2_scdie = lp::assoc_bit<dfsdm2_cr2, 5>;
    /* Analog watchdog interrupt               enable */
    using dfsdm2_cr2_awdie = lp::assoc_bit<dfsdm2_cr2, 4>;
    /* Regular data overrun interrupt               enable */
    using dfsdm2_cr2_rovrie = lp::assoc_bit<dfsdm2_cr2, 3>;
    /* Injected data overrun interrupt               enable */
    using dfsdm2_cr2_jovrie = lp::assoc_bit<dfsdm2_cr2, 2>;
    /* Regular end of conversion interrupt               enable */
    using dfsdm2_cr2_reocie = lp::assoc_bit<dfsdm2_cr2, 1>;
    /* Injected end of conversion interrupt               enable */
    using dfsdm2_cr2_jeocie = lp::assoc_bit<dfsdm2_cr2, 0>;


    /* interrupt and status register */
    using dfsdm2_isr = lp::io_register<lp::u32_t, base_address + 0x308>;
    /* short-circuit detector               flag */
    using dfsdm2_isr_scdf = lp::assoc_bit<dfsdm2_isr, 24, 8>;
    /* Clock absence flag */
    using dfsdm2_isr_ckabf = lp::assoc_bit<dfsdm2_isr, 16, 8>;
    /* Regular conversion in progress               status */
    using dfsdm2_isr_rcip = lp::assoc_bit<dfsdm2_isr, 14>;
    /* Injected conversion in progress               status */
    using dfsdm2_isr_jcip = lp::assoc_bit<dfsdm2_isr, 13>;
    /* Analog watchdog */
    using dfsdm2_isr_awdf = lp::assoc_bit<dfsdm2_isr, 4>;
    /* Regular conversion overrun               flag */
    using dfsdm2_isr_rovrf = lp::assoc_bit<dfsdm2_isr, 3>;
    /* Injected conversion overrun               flag */
    using dfsdm2_isr_jovrf = lp::assoc_bit<dfsdm2_isr, 2>;
    /* End of regular conversion               flag */
    using dfsdm2_isr_reocf = lp::assoc_bit<dfsdm2_isr, 1>;
    /* End of injected conversion               flag */
    using dfsdm2_isr_jeocf = lp::assoc_bit<dfsdm2_isr, 0>;


    /* interrupt flag clear register */
    using dfsdm2_icr = lp::io_register<lp::u32_t, base_address + 0x30c>;
    /* Clear the short-circuit detector               flag */
    using dfsdm2_icr_clrscdf = lp::assoc_bit<dfsdm2_icr, 24, 8>;
    /* Clear the clock absence               flag */
    using dfsdm2_icr_clrckabf = lp::assoc_bit<dfsdm2_icr, 16, 8>;
    /* Clear the regular conversion overrun               flag */
    using dfsdm2_icr_clrrovrf = lp::assoc_bit<dfsdm2_icr, 3>;
    /* Clear the injected conversion overrun               flag */
    using dfsdm2_icr_clrjovrf = lp::assoc_bit<dfsdm2_icr, 2>;


    /* injected channel group selection           register */
    using dfsdm2_jchgr = lp::io_register<lp::u32_t, base_address + 0x310>;
    /* Injected channel group               selection */
    using dfsdm2_jchgr_jchg = lp::assoc_bit<dfsdm2_jchgr, 0, 8>;


    /* filter control register */
    using dfsdm2_fcr = lp::io_register<lp::u32_t, base_address + 0x314>;
    /* Sinc filter order */
    using dfsdm2_fcr_ford = lp::assoc_bit<dfsdm2_fcr, 29, 3>;
    /* Sinc filter oversampling ratio               (decimation rate) */
    using dfsdm2_fcr_fosr = lp::assoc_bit<dfsdm2_fcr, 16, 10>;
    /* Integrator oversampling ratio (averaging               length) */
    using dfsdm2_fcr_iosr = lp::assoc_bit<dfsdm2_fcr, 0, 8>;


    /* data register for injected           group */
    using dfsdm2_jdatar = lp::io_register<lp::u32_t, base_address + 0x318>;
    /* Injected group conversion               data */
    using dfsdm2_jdatar_jdata = lp::assoc_bit<dfsdm2_jdatar, 8, 24>;
    /* Injected channel most recently               converted */
    using dfsdm2_jdatar_jdatach = lp::assoc_bit<dfsdm2_jdatar, 0, 3>;


    /* data register for the regular           channel */
    using dfsdm2_rdatar = lp::io_register<lp::u32_t, base_address + 0x31c>;
    /* Regular channel conversion               data */
    using dfsdm2_rdatar_rdata = lp::assoc_bit<dfsdm2_rdatar, 8, 24>;
    /* Regular channel pending               data */
    using dfsdm2_rdatar_rpend = lp::assoc_bit<dfsdm2_rdatar, 4>;
    /* Regular channel most recently               converted */
    using dfsdm2_rdatar_rdatach = lp::assoc_bit<dfsdm2_rdatar, 0, 3>;


    /* analog watchdog high threshold           register */
    using dfsdm2_awhtr = lp::io_register<lp::u32_t, base_address + 0x320>;
    /* Analog watchdog high               threshold */
    using dfsdm2_awhtr_awht = lp::assoc_bit<dfsdm2_awhtr, 8, 24>;
    /* Break signal assignment to analog               watchdog high threshold event */
    using dfsdm2_awhtr_bkawh = lp::assoc_bit<dfsdm2_awhtr, 0, 4>;


    /* analog watchdog low threshold           register */
    using dfsdm2_awltr = lp::io_register<lp::u32_t, base_address + 0x324>;
    /* Analog watchdog low               threshold */
    using dfsdm2_awltr_awlt = lp::assoc_bit<dfsdm2_awltr, 8, 24>;
    /* Break signal assignment to analog               watchdog low threshold event */
    using dfsdm2_awltr_bkawl = lp::assoc_bit<dfsdm2_awltr, 0, 4>;


    /* analog watchdog status           register */
    using dfsdm2_awsr = lp::io_register<lp::u32_t, base_address + 0x328>;
    /* Analog watchdog high threshold               flag */
    using dfsdm2_awsr_awhtf = lp::assoc_bit<dfsdm2_awsr, 8, 8>;
    /* Analog watchdog low threshold               flag */
    using dfsdm2_awsr_awltf = lp::assoc_bit<dfsdm2_awsr, 0, 8>;


    /* analog watchdog clear flag           register */
    using dfsdm2_awcfr = lp::io_register<lp::u32_t, base_address + 0x32c>;
    /* Clear the analog watchdog high threshold               flag */
    using dfsdm2_awcfr_clrawhtf = lp::assoc_bit<dfsdm2_awcfr, 8, 8>;
    /* Clear the analog watchdog low threshold               flag */
    using dfsdm2_awcfr_clrawltf = lp::assoc_bit<dfsdm2_awcfr, 0, 8>;


    /* Extremes detector maximum           register */
    using dfsdm2_exmax = lp::io_register<lp::u32_t, base_address + 0x330>;
    /* Extremes detector maximum               value */
    using dfsdm2_exmax_exmax = lp::assoc_bit<dfsdm2_exmax, 8, 24>;
    /* Extremes detector maximum data               channel */
    using dfsdm2_exmax_exmaxch = lp::assoc_bit<dfsdm2_exmax, 0, 3>;


    /* Extremes detector minimum           register */
    using dfsdm2_exmin = lp::io_register<lp::u32_t, base_address + 0x334>;
    /* EXMIN */
    using dfsdm2_exmin_exmin = lp::assoc_bit<dfsdm2_exmin, 8, 24>;
    /* Extremes detector minimum data               channel */
    using dfsdm2_exmin_exminch = lp::assoc_bit<dfsdm2_exmin, 0, 3>;


    /* conversion timer register */
    using dfsdm2_cnvtimr = lp::io_register<lp::u32_t, base_address + 0x338>;
    /* 28-bit timer counting conversion time t               = CNVCNT[27:0] / fDFSDM_CKIN */
    using dfsdm2_cnvtimr_cnvcnt = lp::assoc_bit<dfsdm2_cnvtimr, 4, 28>;


    /* control register 1 */
    using dfsdm3_cr1 = lp::io_register<lp::u32_t, base_address + 0x400>;
    /* Analog watchdog fast mode               select */
    using dfsdm3_cr1_awfsel = lp::assoc_bit<dfsdm3_cr1, 30>;
    /* Fast conversion mode selection for               regular conversions */
    using dfsdm3_cr1_fast = lp::assoc_bit<dfsdm3_cr1, 29>;
    /* Regular channel selection */
    using dfsdm3_cr1_rch = lp::assoc_bit<dfsdm3_cr1, 24, 3>;
    /* DMA channel enabled to read data for the               regular conversion */
    using dfsdm3_cr1_rdmaen = lp::assoc_bit<dfsdm3_cr1, 21>;
    /* Launch regular conversion synchronously               with DFSDM0 */
    using dfsdm3_cr1_rsync = lp::assoc_bit<dfsdm3_cr1, 19>;
    /* Continuous mode selection for regular               conversions */
    using dfsdm3_cr1_rcont = lp::assoc_bit<dfsdm3_cr1, 18>;
    /* Software start of a conversion on the               regular channel */
    using dfsdm3_cr1_rswstart = lp::assoc_bit<dfsdm3_cr1, 17>;
    /* Trigger enable and trigger edge               selection for injected conversions */
    using dfsdm3_cr1_jexten = lp::assoc_bit<dfsdm3_cr1, 13, 2>;
    /* Trigger signal selection for launching               injected conversions */
    using dfsdm3_cr1_jextsel = lp::assoc_bit<dfsdm3_cr1, 8, 3>;
    /* DMA channel enabled to read data for the               injected channel group */
    using dfsdm3_cr1_jdmaen = lp::assoc_bit<dfsdm3_cr1, 5>;
    /* Scanning conversion mode for injected               conversions */
    using dfsdm3_cr1_jscan = lp::assoc_bit<dfsdm3_cr1, 4>;
    /* Launch an injected conversion               synchronously with the DFSDM0 JSWSTART               trigger */
    using dfsdm3_cr1_jsync = lp::assoc_bit<dfsdm3_cr1, 3>;
    /* Start a conversion of the injected group               of channels */
    using dfsdm3_cr1_jswstart = lp::assoc_bit<dfsdm3_cr1, 1>;
    /* DFSDM enable */
    using dfsdm3_cr1_dfen = lp::assoc_bit<dfsdm3_cr1, 0>;


    /* control register 2 */
    using dfsdm3_cr2 = lp::io_register<lp::u32_t, base_address + 0x404>;
    /* Analog watchdog channel               selection */
    using dfsdm3_cr2_awdch = lp::assoc_bit<dfsdm3_cr2, 16, 8>;
    /* Extremes detector channel               selection */
    using dfsdm3_cr2_exch = lp::assoc_bit<dfsdm3_cr2, 8, 8>;
    /* Clock absence interrupt               enable */
    using dfsdm3_cr2_ckabie = lp::assoc_bit<dfsdm3_cr2, 6>;
    /* Short-circuit detector interrupt               enable */
    using dfsdm3_cr2_scdie = lp::assoc_bit<dfsdm3_cr2, 5>;
    /* Analog watchdog interrupt               enable */
    using dfsdm3_cr2_awdie = lp::assoc_bit<dfsdm3_cr2, 4>;
    /* Regular data overrun interrupt               enable */
    using dfsdm3_cr2_rovrie = lp::assoc_bit<dfsdm3_cr2, 3>;
    /* Injected data overrun interrupt               enable */
    using dfsdm3_cr2_jovrie = lp::assoc_bit<dfsdm3_cr2, 2>;
    /* Regular end of conversion interrupt               enable */
    using dfsdm3_cr2_reocie = lp::assoc_bit<dfsdm3_cr2, 1>;
    /* Injected end of conversion interrupt               enable */
    using dfsdm3_cr2_jeocie = lp::assoc_bit<dfsdm3_cr2, 0>;


    /* interrupt and status register */
    using dfsdm3_isr = lp::io_register<lp::u32_t, base_address + 0x408>;
    /* short-circuit detector               flag */
    using dfsdm3_isr_scdf = lp::assoc_bit<dfsdm3_isr, 24, 8>;
    /* Clock absence flag */
    using dfsdm3_isr_ckabf = lp::assoc_bit<dfsdm3_isr, 16, 8>;
    /* Regular conversion in progress               status */
    using dfsdm3_isr_rcip = lp::assoc_bit<dfsdm3_isr, 14>;
    /* Injected conversion in progress               status */
    using dfsdm3_isr_jcip = lp::assoc_bit<dfsdm3_isr, 13>;
    /* Analog watchdog */
    using dfsdm3_isr_awdf = lp::assoc_bit<dfsdm3_isr, 4>;
    /* Regular conversion overrun               flag */
    using dfsdm3_isr_rovrf = lp::assoc_bit<dfsdm3_isr, 3>;
    /* Injected conversion overrun               flag */
    using dfsdm3_isr_jovrf = lp::assoc_bit<dfsdm3_isr, 2>;
    /* End of regular conversion               flag */
    using dfsdm3_isr_reocf = lp::assoc_bit<dfsdm3_isr, 1>;
    /* End of injected conversion               flag */
    using dfsdm3_isr_jeocf = lp::assoc_bit<dfsdm3_isr, 0>;


    /* interrupt flag clear register */
    using dfsdm3_icr = lp::io_register<lp::u32_t, base_address + 0x40c>;
    /* Clear the short-circuit detector               flag */
    using dfsdm3_icr_clrscdf = lp::assoc_bit<dfsdm3_icr, 24, 8>;
    /* Clear the clock absence               flag */
    using dfsdm3_icr_clrckabf = lp::assoc_bit<dfsdm3_icr, 16, 8>;
    /* Clear the regular conversion overrun               flag */
    using dfsdm3_icr_clrrovrf = lp::assoc_bit<dfsdm3_icr, 3>;
    /* Clear the injected conversion overrun               flag */
    using dfsdm3_icr_clrjovrf = lp::assoc_bit<dfsdm3_icr, 2>;


    /* injected channel group selection           register */
    using dfsdm3_jchgr = lp::io_register<lp::u32_t, base_address + 0x410>;
    /* Injected channel group               selection */
    using dfsdm3_jchgr_jchg = lp::assoc_bit<dfsdm3_jchgr, 0, 8>;


    /* filter control register */
    using dfsdm3_fcr = lp::io_register<lp::u32_t, base_address + 0x414>;
    /* Sinc filter order */
    using dfsdm3_fcr_ford = lp::assoc_bit<dfsdm3_fcr, 29, 3>;
    /* Sinc filter oversampling ratio               (decimation rate) */
    using dfsdm3_fcr_fosr = lp::assoc_bit<dfsdm3_fcr, 16, 10>;
    /* Integrator oversampling ratio (averaging               length) */
    using dfsdm3_fcr_iosr = lp::assoc_bit<dfsdm3_fcr, 0, 8>;


    /* data register for injected           group */
    using dfsdm3_jdatar = lp::io_register<lp::u32_t, base_address + 0x418>;
    /* Injected group conversion               data */
    using dfsdm3_jdatar_jdata = lp::assoc_bit<dfsdm3_jdatar, 8, 24>;
    /* Injected channel most recently               converted */
    using dfsdm3_jdatar_jdatach = lp::assoc_bit<dfsdm3_jdatar, 0, 3>;


    /* data register for the regular           channel */
    using dfsdm3_rdatar = lp::io_register<lp::u32_t, base_address + 0x41c>;
    /* Regular channel conversion               data */
    using dfsdm3_rdatar_rdata = lp::assoc_bit<dfsdm3_rdatar, 8, 24>;
    /* Regular channel pending               data */
    using dfsdm3_rdatar_rpend = lp::assoc_bit<dfsdm3_rdatar, 4>;
    /* Regular channel most recently               converted */
    using dfsdm3_rdatar_rdatach = lp::assoc_bit<dfsdm3_rdatar, 0, 3>;


    /* analog watchdog high threshold           register */
    using dfsdm3_awhtr = lp::io_register<lp::u32_t, base_address + 0x420>;
    /* Analog watchdog high               threshold */
    using dfsdm3_awhtr_awht = lp::assoc_bit<dfsdm3_awhtr, 8, 24>;
    /* Break signal assignment to analog               watchdog high threshold event */
    using dfsdm3_awhtr_bkawh = lp::assoc_bit<dfsdm3_awhtr, 0, 4>;


    /* analog watchdog low threshold           register */
    using dfsdm3_awltr = lp::io_register<lp::u32_t, base_address + 0x424>;
    /* Analog watchdog low               threshold */
    using dfsdm3_awltr_awlt = lp::assoc_bit<dfsdm3_awltr, 8, 24>;
    /* Break signal assignment to analog               watchdog low threshold event */
    using dfsdm3_awltr_bkawl = lp::assoc_bit<dfsdm3_awltr, 0, 4>;


    /* analog watchdog status           register */
    using dfsdm3_awsr = lp::io_register<lp::u32_t, base_address + 0x428>;
    /* Analog watchdog high threshold               flag */
    using dfsdm3_awsr_awhtf = lp::assoc_bit<dfsdm3_awsr, 8, 8>;
    /* Analog watchdog low threshold               flag */
    using dfsdm3_awsr_awltf = lp::assoc_bit<dfsdm3_awsr, 0, 8>;


    /* analog watchdog clear flag           register */
    using dfsdm3_awcfr = lp::io_register<lp::u32_t, base_address + 0x42c>;
    /* Clear the analog watchdog high threshold               flag */
    using dfsdm3_awcfr_clrawhtf = lp::assoc_bit<dfsdm3_awcfr, 8, 8>;
    /* Clear the analog watchdog low threshold               flag */
    using dfsdm3_awcfr_clrawltf = lp::assoc_bit<dfsdm3_awcfr, 0, 8>;


    /* Extremes detector maximum           register */
    using dfsdm3_exmax = lp::io_register<lp::u32_t, base_address + 0x430>;
    /* Extremes detector maximum               value */
    using dfsdm3_exmax_exmax = lp::assoc_bit<dfsdm3_exmax, 8, 24>;
    /* Extremes detector maximum data               channel */
    using dfsdm3_exmax_exmaxch = lp::assoc_bit<dfsdm3_exmax, 0, 3>;


    /* Extremes detector minimum           register */
    using dfsdm3_exmin = lp::io_register<lp::u32_t, base_address + 0x434>;
    /* EXMIN */
    using dfsdm3_exmin_exmin = lp::assoc_bit<dfsdm3_exmin, 8, 24>;
    /* Extremes detector minimum data               channel */
    using dfsdm3_exmin_exminch = lp::assoc_bit<dfsdm3_exmin, 0, 3>;


    /* conversion timer register */
    using dfsdm3_cnvtimr = lp::io_register<lp::u32_t, base_address + 0x438>;
    /* 28-bit timer counting conversion time t               = CNVCNT[27:0] / fDFSDM_CKIN */
    using dfsdm3_cnvtimr_cnvcnt = lp::assoc_bit<dfsdm3_cnvtimr, 4, 28>;


};

using dfsdm1 = dfsdm_t<0x40016000>;

#endif // DFSDM_HH
