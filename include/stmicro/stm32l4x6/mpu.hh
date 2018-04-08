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
 * Hardware support for mpu
 * @file mpu.hh
 * @author Boris Vinogradov
 */

#include <associate_bit.hh>
#include <io_register.hh>
#include <types.hh>

#ifndef MPU_HH
#define MPU_HH

/* Memory protection unit */
template <lp::addr_t base_address>
struct mpu_t {
    /* MPU type register */
    using mpu_typer = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* Separate flag */
    using mpu_typer_separate = lp::assoc_bit<mpu_typer, 0>;
    /* Number of MPU data regions */
    using mpu_typer_dregion = lp::assoc_bit<mpu_typer, 8, 8>;
    /* Number of MPU instruction               regions */
    using mpu_typer_iregion = lp::assoc_bit<mpu_typer, 16, 8>;


    /* MPU control register */
    using mpu_ctrl = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* Enables the MPU */
    using mpu_ctrl_enable = lp::assoc_bit<mpu_ctrl, 0>;
    /* Enables the operation of MPU during hard               fault */
    using mpu_ctrl_hfnmiena = lp::assoc_bit<mpu_ctrl, 1>;
    /* Enable priviliged software access to               default memory map */
    using mpu_ctrl_privdefena = lp::assoc_bit<mpu_ctrl, 2>;


    /* MPU region number register */
    using mpu_rnr = lp::io_register<lp::u32_t, base_address + 0x8>;
    /* MPU region */
    using mpu_rnr_region = lp::assoc_bit<mpu_rnr, 0, 8>;


    /* MPU region base address           register */
    using mpu_rbar = lp::io_register<lp::u32_t, base_address + 0xc>;
    /* MPU region field */
    using mpu_rbar_region = lp::assoc_bit<mpu_rbar, 0, 4>;
    /* MPU region number valid */
    using mpu_rbar_valid = lp::assoc_bit<mpu_rbar, 4>;
    /* Region base address field */
    using mpu_rbar_addr = lp::assoc_bit<mpu_rbar, 5, 27>;


    /* MPU region attribute and size           register */
    using mpu_rasr = lp::io_register<lp::u32_t, base_address + 0x10>;
    /* Region enable bit. */
    using mpu_rasr_enable = lp::assoc_bit<mpu_rasr, 0>;
    /* Size of the MPU protection               region */
    using mpu_rasr_size = lp::assoc_bit<mpu_rasr, 1, 5>;
    /* Subregion disable bits */
    using mpu_rasr_srd = lp::assoc_bit<mpu_rasr, 8, 8>;
    /* memory attribute */
    using mpu_rasr_b = lp::assoc_bit<mpu_rasr, 16>;
    /* memory attribute */
    using mpu_rasr_c = lp::assoc_bit<mpu_rasr, 17>;
    /* Shareable memory attribute */
    using mpu_rasr_s = lp::assoc_bit<mpu_rasr, 18>;
    /* memory attribute */
    using mpu_rasr_tex = lp::assoc_bit<mpu_rasr, 19, 3>;
    /* Access permission */
    using mpu_rasr_ap = lp::assoc_bit<mpu_rasr, 24, 3>;
    /* Instruction access disable               bit */
    using mpu_rasr_xn = lp::assoc_bit<mpu_rasr, 28>;


};

using mpu = mpu_t<0xe000ed90>;

#endif // MPU_HH
