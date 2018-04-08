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
 * Hardware support for scb
 * @file scb.hh
 * @author Boris Vinogradov
 */

#include <associate_bit.hh>
#include <io_register.hh>
#include <types.hh>

#ifndef SCB_HH
#define SCB_HH

/* System control block */
template <lp::addr_t base_address>
struct scb_t {
    /* CPUID base register */
    using cpuid = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* Revision number */
    using cpuid_revision = lp::assoc_bit<cpuid, 0, 4>;
    /* Part number of the               processor */
    using cpuid_partno = lp::assoc_bit<cpuid, 4, 12>;
    /* Reads as 0xF */
    using cpuid_constant = lp::assoc_bit<cpuid, 16, 4>;
    /* Variant number */
    using cpuid_variant = lp::assoc_bit<cpuid, 20, 4>;
    /* Implementer code */
    using cpuid_implementer = lp::assoc_bit<cpuid, 24, 8>;


    /* Interrupt control and state           register */
    using icsr = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* Active vector */
    using icsr_vectactive = lp::assoc_bit<icsr, 0, 9>;
    /* Return to base level */
    using icsr_rettobase = lp::assoc_bit<icsr, 11>;
    /* Pending vector */
    using icsr_vectpending = lp::assoc_bit<icsr, 12, 7>;
    /* Interrupt pending flag */
    using icsr_isrpending = lp::assoc_bit<icsr, 22>;
    /* SysTick exception clear-pending               bit */
    using icsr_pendstclr = lp::assoc_bit<icsr, 25>;
    /* SysTick exception set-pending               bit */
    using icsr_pendstset = lp::assoc_bit<icsr, 26>;
    /* PendSV clear-pending bit */
    using icsr_pendsvclr = lp::assoc_bit<icsr, 27>;
    /* PendSV set-pending bit */
    using icsr_pendsvset = lp::assoc_bit<icsr, 28>;
    /* NMI set-pending bit. */
    using icsr_nmipendset = lp::assoc_bit<icsr, 31>;


    /* Vector table offset register */
    using vtor = lp::io_register<lp::u32_t, base_address + 0x8>;
    /* Vector table base offset               field */
    using vtor_tbloff = lp::assoc_bit<vtor, 9, 21>;


    /* Application interrupt and reset control           register */
    using aircr = lp::io_register<lp::u32_t, base_address + 0xc>;
    /* VECTRESET */
    using aircr_vectreset = lp::assoc_bit<aircr, 0>;
    /* VECTCLRACTIVE */
    using aircr_vectclractive = lp::assoc_bit<aircr, 1>;
    /* SYSRESETREQ */
    using aircr_sysresetreq = lp::assoc_bit<aircr, 2>;
    /* PRIGROUP */
    using aircr_prigroup = lp::assoc_bit<aircr, 8, 3>;
    /* ENDIANESS */
    using aircr_endianess = lp::assoc_bit<aircr, 15>;
    /* Register key */
    using aircr_vectkeystat = lp::assoc_bit<aircr, 16, 16>;


    /* System control register */
    using scr = lp::io_register<lp::u32_t, base_address + 0x10>;
    /* SLEEPONEXIT */
    using scr_sleeponexit = lp::assoc_bit<scr, 1>;
    /* SLEEPDEEP */
    using scr_sleepdeep = lp::assoc_bit<scr, 2>;
    /* Send Event on Pending bit */
    using scr_seveonpend = lp::assoc_bit<scr, 4>;


    /* Configuration and control           register */
    using ccr = lp::io_register<lp::u32_t, base_address + 0x14>;
    /* Configures how the processor enters               Thread mode */
    using ccr_nonbasethrdena = lp::assoc_bit<ccr, 0>;
    /* USERSETMPEND */
    using ccr_usersetmpend = lp::assoc_bit<ccr, 1>;
    /* UNALIGN_ TRP */
    using ccr_unalign__trp = lp::assoc_bit<ccr, 3>;
    /* DIV_0_TRP */
    using ccr_div_0_trp = lp::assoc_bit<ccr, 4>;
    /* BFHFNMIGN */
    using ccr_bfhfnmign = lp::assoc_bit<ccr, 8>;
    /* STKALIGN */
    using ccr_stkalign = lp::assoc_bit<ccr, 9>;


    /* System handler priority           registers */
    using shpr1 = lp::io_register<lp::u32_t, base_address + 0x18>;
    /* Priority of system handler               4 */
    using shpr1_pri_4 = lp::assoc_bit<shpr1, 0, 8>;
    /* Priority of system handler               5 */
    using shpr1_pri_5 = lp::assoc_bit<shpr1, 8, 8>;
    /* Priority of system handler               6 */
    using shpr1_pri_6 = lp::assoc_bit<shpr1, 16, 8>;


    /* System handler priority           registers */
    using shpr2 = lp::io_register<lp::u32_t, base_address + 0x1c>;
    /* Priority of system handler               11 */
    using shpr2_pri_11 = lp::assoc_bit<shpr2, 24, 8>;


    /* System handler priority           registers */
    using shpr3 = lp::io_register<lp::u32_t, base_address + 0x20>;
    /* Priority of system handler               14 */
    using shpr3_pri_14 = lp::assoc_bit<shpr3, 16, 8>;
    /* Priority of system handler               15 */
    using shpr3_pri_15 = lp::assoc_bit<shpr3, 24, 8>;


    /* System handler control and state           register */
    using shcrs = lp::io_register<lp::u32_t, base_address + 0x24>;
    /* Memory management fault exception active               bit */
    using shcrs_memfaultact = lp::assoc_bit<shcrs, 0>;
    /* Bus fault exception active               bit */
    using shcrs_busfaultact = lp::assoc_bit<shcrs, 1>;
    /* Usage fault exception active               bit */
    using shcrs_usgfaultact = lp::assoc_bit<shcrs, 3>;
    /* SVC call active bit */
    using shcrs_svcallact = lp::assoc_bit<shcrs, 7>;
    /* Debug monitor active bit */
    using shcrs_monitoract = lp::assoc_bit<shcrs, 8>;
    /* PendSV exception active               bit */
    using shcrs_pendsvact = lp::assoc_bit<shcrs, 10>;
    /* SysTick exception active               bit */
    using shcrs_systickact = lp::assoc_bit<shcrs, 11>;
    /* Usage fault exception pending               bit */
    using shcrs_usgfaultpended = lp::assoc_bit<shcrs, 12>;
    /* Memory management fault exception               pending bit */
    using shcrs_memfaultpended = lp::assoc_bit<shcrs, 13>;
    /* Bus fault exception pending               bit */
    using shcrs_busfaultpended = lp::assoc_bit<shcrs, 14>;
    /* SVC call pending bit */
    using shcrs_svcallpended = lp::assoc_bit<shcrs, 15>;
    /* Memory management fault enable               bit */
    using shcrs_memfaultena = lp::assoc_bit<shcrs, 16>;
    /* Bus fault enable bit */
    using shcrs_busfaultena = lp::assoc_bit<shcrs, 17>;
    /* Usage fault enable bit */
    using shcrs_usgfaultena = lp::assoc_bit<shcrs, 18>;


    /* Configurable fault status           register */
    using cfsr_ufsr_bfsr_mmfsr = lp::io_register<lp::u32_t, base_address + 0x28>;
    /* Instruction access violation               flag */
    using cfsr_ufsr_bfsr_mmfsr_iaccviol = lp::assoc_bit<cfsr_ufsr_bfsr_mmfsr, 1>;
    /* Memory manager fault on unstacking for a               return from exception */
    using cfsr_ufsr_bfsr_mmfsr_munstkerr = lp::assoc_bit<cfsr_ufsr_bfsr_mmfsr, 3>;
    /* Memory manager fault on stacking for               exception entry. */
    using cfsr_ufsr_bfsr_mmfsr_mstkerr = lp::assoc_bit<cfsr_ufsr_bfsr_mmfsr, 4>;
    /* MLSPERR */
    using cfsr_ufsr_bfsr_mmfsr_mlsperr = lp::assoc_bit<cfsr_ufsr_bfsr_mmfsr, 5>;
    /* Memory Management Fault Address Register               (MMAR) valid flag */
    using cfsr_ufsr_bfsr_mmfsr_mmarvalid = lp::assoc_bit<cfsr_ufsr_bfsr_mmfsr, 7>;
    /* Instruction bus error */
    using cfsr_ufsr_bfsr_mmfsr_ibuserr = lp::assoc_bit<cfsr_ufsr_bfsr_mmfsr, 8>;
    /* Precise data bus error */
    using cfsr_ufsr_bfsr_mmfsr_preciserr = lp::assoc_bit<cfsr_ufsr_bfsr_mmfsr, 9>;
    /* Imprecise data bus error */
    using cfsr_ufsr_bfsr_mmfsr_impreciserr = lp::assoc_bit<cfsr_ufsr_bfsr_mmfsr, 10>;
    /* Bus fault on unstacking for a return               from exception */
    using cfsr_ufsr_bfsr_mmfsr_unstkerr = lp::assoc_bit<cfsr_ufsr_bfsr_mmfsr, 11>;
    /* Bus fault on stacking for exception               entry */
    using cfsr_ufsr_bfsr_mmfsr_stkerr = lp::assoc_bit<cfsr_ufsr_bfsr_mmfsr, 12>;
    /* Bus fault on floating-point lazy state               preservation */
    using cfsr_ufsr_bfsr_mmfsr_lsperr = lp::assoc_bit<cfsr_ufsr_bfsr_mmfsr, 13>;
    /* Bus Fault Address Register (BFAR) valid               flag */
    using cfsr_ufsr_bfsr_mmfsr_bfarvalid = lp::assoc_bit<cfsr_ufsr_bfsr_mmfsr, 15>;
    /* Undefined instruction usage               fault */
    using cfsr_ufsr_bfsr_mmfsr_undefinstr = lp::assoc_bit<cfsr_ufsr_bfsr_mmfsr, 16>;
    /* Invalid state usage fault */
    using cfsr_ufsr_bfsr_mmfsr_invstate = lp::assoc_bit<cfsr_ufsr_bfsr_mmfsr, 17>;
    /* Invalid PC load usage               fault */
    using cfsr_ufsr_bfsr_mmfsr_invpc = lp::assoc_bit<cfsr_ufsr_bfsr_mmfsr, 18>;
    /* No coprocessor usage               fault. */
    using cfsr_ufsr_bfsr_mmfsr_nocp = lp::assoc_bit<cfsr_ufsr_bfsr_mmfsr, 19>;
    /* Unaligned access usage               fault */
    using cfsr_ufsr_bfsr_mmfsr_unaligned = lp::assoc_bit<cfsr_ufsr_bfsr_mmfsr, 24>;
    /* Divide by zero usage fault */
    using cfsr_ufsr_bfsr_mmfsr_divbyzero = lp::assoc_bit<cfsr_ufsr_bfsr_mmfsr, 25>;


    /* Hard fault status register */
    using hfsr = lp::io_register<lp::u32_t, base_address + 0x2c>;
    /* Vector table hard fault */
    using hfsr_vecttbl = lp::assoc_bit<hfsr, 1>;
    /* Forced hard fault */
    using hfsr_forced = lp::assoc_bit<hfsr, 30>;
    /* Reserved for Debug use */
    using hfsr_debug_vt = lp::assoc_bit<hfsr, 31>;


    /* Memory management fault address           register */
    using mmfar = lp::io_register<lp::u32_t, base_address + 0x34>;
    /* Memory management fault               address */
    using mmfar_mmfar = lp::assoc_bit<mmfar, 0, 32>;


    /* Bus fault address register */
    using bfar = lp::io_register<lp::u32_t, base_address + 0x38>;
    /* Bus fault address */
    using bfar_bfar = lp::assoc_bit<bfar, 0, 32>;


    /* Auxiliary fault status           register */
    using afsr = lp::io_register<lp::u32_t, base_address + 0x3c>;
    /* Implementation defined */
    using afsr_impdef = lp::assoc_bit<afsr, 0, 32>;


};

/* System control block ACTLR */
template <lp::addr_t base_address>
struct scb_actrl_t {
    /* Auxiliary control register */
    using actrl = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* DISMCYCINT */
    using actrl_dismcycint = lp::assoc_bit<actrl, 0>;
    /* DISDEFWBUF */
    using actrl_disdefwbuf = lp::assoc_bit<actrl, 1>;
    /* DISFOLD */
    using actrl_disfold = lp::assoc_bit<actrl, 2>;
    /* DISFPCA */
    using actrl_disfpca = lp::assoc_bit<actrl, 8>;
    /* DISOOFP */
    using actrl_disoofp = lp::assoc_bit<actrl, 9>;


};

using scb = scb_t<0xe000ed00>;
using scb_actrl = scb_actrl_t<0xe000e008>;

#endif // SCB_HH
