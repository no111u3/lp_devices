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
 * Hardware support for rcc
 * @file rcc.hh
 * @author Boris Vinogradov
 */

#include <associate_bit.hh>
#include <io_register.hh>
#include <types.hh>

#ifndef RCC_HH
#define RCC_HH

/* Reset and clock control */
template <lp::addr_t base_address>
struct rcc_t {
    /* Clock control register */
    using cr = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* SAI2 PLL clock ready flag */
    using cr_pllsai2rdy = lp::assoc_bit<cr, 29>;
    /* SAI2 PLL enable */
    using cr_pllsai2on = lp::assoc_bit<cr, 28>;
    /* SAI1 PLL clock ready flag */
    using cr_pllsai1rdy = lp::assoc_bit<cr, 27>;
    /* SAI1 PLL enable */
    using cr_pllsai1on = lp::assoc_bit<cr, 26>;
    /* Main PLL clock ready flag */
    using cr_pllrdy = lp::assoc_bit<cr, 25>;
    /* Main PLL enable */
    using cr_pllon = lp::assoc_bit<cr, 24>;
    /* Clock security system               enable */
    using cr_csson = lp::assoc_bit<cr, 19>;
    /* HSE crystal oscillator               bypass */
    using cr_hsebyp = lp::assoc_bit<cr, 18>;
    /* HSE clock ready flag */
    using cr_hserdy = lp::assoc_bit<cr, 17>;
    /* HSE clock enable */
    using cr_hseon = lp::assoc_bit<cr, 16>;
    /* HSI automatic start from               Stop */
    using cr_hsiasfs = lp::assoc_bit<cr, 11>;
    /* HSI clock ready flag */
    using cr_hsirdy = lp::assoc_bit<cr, 10>;
    /* HSI always enable for peripheral               kernels */
    using cr_hsikeron = lp::assoc_bit<cr, 9>;
    /* HSI clock enable */
    using cr_hsion = lp::assoc_bit<cr, 8>;
    /* MSI clock ranges */
    using cr_msirange = lp::assoc_bit<cr, 4, 4>;
    /* MSI clock range selection */
    using cr_msirgsel = lp::assoc_bit<cr, 3>;
    /* MSI clock PLL enable */
    using cr_msipllen = lp::assoc_bit<cr, 2>;
    /* MSI clock ready flag */
    using cr_msirdy = lp::assoc_bit<cr, 1>;
    /* MSI clock enable */
    using cr_msion = lp::assoc_bit<cr, 0>;


    /* Internal clock sources calibration           register */
    using icscr = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* HSI clock trimming */
    using icscr_hsitrim = lp::assoc_bit<icscr, 24, 7>;
    /* HSI clock calibration */
    using icscr_hsical = lp::assoc_bit<icscr, 16, 8>;
    /* MSI clock trimming */
    using icscr_msitrim = lp::assoc_bit<icscr, 8, 8>;
    /* MSI clock calibration */
    using icscr_msical = lp::assoc_bit<icscr, 0, 8>;


    /* Clock configuration register */
    using cfgr = lp::io_register<lp::u32_t, base_address + 0x8>;
    /* Microcontroller clock output               prescaler */
    using cfgr_mcopre = lp::assoc_bit<cfgr, 28, 3>;
    /* Microcontroller clock               output */
    using cfgr_mcosel = lp::assoc_bit<cfgr, 24, 3>;
    /* Wakeup from Stop and CSS backup clock               selection */
    using cfgr_stopwuck = lp::assoc_bit<cfgr, 15>;
    /* APB high-speed prescaler               (APB2) */
    using cfgr_ppre2 = lp::assoc_bit<cfgr, 11, 3>;
    /* PB low-speed prescaler               (APB1) */
    using cfgr_ppre1 = lp::assoc_bit<cfgr, 8, 3>;
    /* AHB prescaler */
    using cfgr_hpre = lp::assoc_bit<cfgr, 4, 4>;
    /* System clock switch status */
    using cfgr_sws = lp::assoc_bit<cfgr, 2, 2>;
    /* System clock switch */
    using cfgr_sw = lp::assoc_bit<cfgr, 0, 2>;


    /* PLL configuration register */
    using pllcfgr = lp::io_register<lp::u32_t, base_address + 0xc>;
    /* Main PLL division factor for PLLCLK               (system clock) */
    using pllcfgr_pllr = lp::assoc_bit<pllcfgr, 25, 2>;
    /* Main PLL PLLCLK output               enable */
    using pllcfgr_pllren = lp::assoc_bit<pllcfgr, 24>;
    /* Main PLL division factor for               PLLUSB1CLK(48 MHz clock) */
    using pllcfgr_pllq = lp::assoc_bit<pllcfgr, 21, 2>;
    /* Main PLL PLLUSB1CLK output               enable */
    using pllcfgr_pllqen = lp::assoc_bit<pllcfgr, 20>;
    /* Main PLL division factor for PLLSAI3CLK               (SAI1 and SAI2 clock) */
    using pllcfgr_pllp = lp::assoc_bit<pllcfgr, 17>;
    /* Main PLL PLLSAI3CLK output               enable */
    using pllcfgr_pllpen = lp::assoc_bit<pllcfgr, 16>;
    /* Main PLL multiplication factor for               VCO */
    using pllcfgr_plln = lp::assoc_bit<pllcfgr, 8, 7>;
    /* Division factor for the main PLL and               audio PLL (PLLSAI1 and PLLSAI2) input               clock */
    using pllcfgr_pllm = lp::assoc_bit<pllcfgr, 4, 3>;
    /* Main PLL, PLLSAI1 and PLLSAI2 entry               clock source */
    using pllcfgr_pllsrc = lp::assoc_bit<pllcfgr, 0, 2>;
    /* Main PLL division factor for               PLLSAI2CLK */
    using pllcfgr_pllpdiv = lp::assoc_bit<pllcfgr, 27, 5>;


    /* PLLSAI1 configuration register */
    using pllsai1cfgr = lp::io_register<lp::u32_t, base_address + 0x10>;
    /* PLLSAI1 division factor for PLLADC1CLK               (ADC clock) */
    using pllsai1cfgr_pllsai1r = lp::assoc_bit<pllsai1cfgr, 25, 2>;
    /* PLLSAI1 PLLADC1CLK output               enable */
    using pllsai1cfgr_pllsai1ren = lp::assoc_bit<pllsai1cfgr, 24>;
    /* SAI1PLL division factor for PLLUSB2CLK               (48 MHz clock) */
    using pllsai1cfgr_pllsai1q = lp::assoc_bit<pllsai1cfgr, 21, 2>;
    /* SAI1PLL PLLUSB2CLK output               enable */
    using pllsai1cfgr_pllsai1qen = lp::assoc_bit<pllsai1cfgr, 20>;
    /* SAI1PLL division factor for PLLSAI1CLK               (SAI1 or SAI2 clock) */
    using pllsai1cfgr_pllsai1p = lp::assoc_bit<pllsai1cfgr, 17>;
    /* SAI1PLL PLLSAI1CLK output               enable */
    using pllsai1cfgr_pllsai1pen = lp::assoc_bit<pllsai1cfgr, 16>;
    /* SAI1PLL multiplication factor for               VCO */
    using pllsai1cfgr_pllsai1n = lp::assoc_bit<pllsai1cfgr, 8, 7>;
    /* PLLSAI1 division factor for               PLLSAI1CLK */
    using pllsai1cfgr_pllsai1pdiv = lp::assoc_bit<pllsai1cfgr, 27, 5>;


    /* PLLSAI2 configuration register */
    using pllsai2cfgr = lp::io_register<lp::u32_t, base_address + 0x14>;
    /* PLLSAI2 division factor for PLLADC2CLK               (ADC clock) */
    using pllsai2cfgr_pllsai2r = lp::assoc_bit<pllsai2cfgr, 25, 2>;
    /* PLLSAI2 PLLADC2CLK output               enable */
    using pllsai2cfgr_pllsai2ren = lp::assoc_bit<pllsai2cfgr, 24>;
    /* SAI1PLL division factor for PLLSAI2CLK               (SAI1 or SAI2 clock) */
    using pllsai2cfgr_pllsai2p = lp::assoc_bit<pllsai2cfgr, 17>;
    /* SAI2PLL PLLSAI2CLK output               enable */
    using pllsai2cfgr_pllsai2pen = lp::assoc_bit<pllsai2cfgr, 16>;
    /* SAI2PLL multiplication factor for               VCO */
    using pllsai2cfgr_pllsai2n = lp::assoc_bit<pllsai2cfgr, 8, 7>;
    /* PLLSAI2 division factor for               PLLSAI2CLK */
    using pllsai2cfgr_pllsai2pdiv = lp::assoc_bit<pllsai2cfgr, 27, 5>;


    /* Clock interrupt enable           register */
    using cier = lp::io_register<lp::u32_t, base_address + 0x18>;
    /* LSE clock security system interrupt               enable */
    using cier_lsecssie = lp::assoc_bit<cier, 9>;
    /* PLLSAI2 ready interrupt               enable */
    using cier_pllsai2rdyie = lp::assoc_bit<cier, 7>;
    /* PLLSAI1 ready interrupt               enable */
    using cier_pllsai1rdyie = lp::assoc_bit<cier, 6>;
    /* PLL ready interrupt enable */
    using cier_pllrdyie = lp::assoc_bit<cier, 5>;
    /* HSE ready interrupt enable */
    using cier_hserdyie = lp::assoc_bit<cier, 4>;
    /* HSI ready interrupt enable */
    using cier_hsirdyie = lp::assoc_bit<cier, 3>;
    /* MSI ready interrupt enable */
    using cier_msirdyie = lp::assoc_bit<cier, 2>;
    /* LSE ready interrupt enable */
    using cier_lserdyie = lp::assoc_bit<cier, 1>;
    /* LSI ready interrupt enable */
    using cier_lsirdyie = lp::assoc_bit<cier, 0>;
    /* HSI48 ready interrupt               enable */
    using cier_hsi48rdyie = lp::assoc_bit<cier, 10>;


    /* Clock interrupt flag register */
    using cifr = lp::io_register<lp::u32_t, base_address + 0x1c>;
    /* LSE Clock security system interrupt               flag */
    using cifr_lsecssf = lp::assoc_bit<cifr, 9>;
    /* Clock security system interrupt               flag */
    using cifr_cssf = lp::assoc_bit<cifr, 8>;
    /* PLLSAI2 ready interrupt               flag */
    using cifr_pllsai2rdyf = lp::assoc_bit<cifr, 7>;
    /* PLLSAI1 ready interrupt               flag */
    using cifr_pllsai1rdyf = lp::assoc_bit<cifr, 6>;
    /* PLL ready interrupt flag */
    using cifr_pllrdyf = lp::assoc_bit<cifr, 5>;
    /* HSE ready interrupt flag */
    using cifr_hserdyf = lp::assoc_bit<cifr, 4>;
    /* HSI ready interrupt flag */
    using cifr_hsirdyf = lp::assoc_bit<cifr, 3>;
    /* MSI ready interrupt flag */
    using cifr_msirdyf = lp::assoc_bit<cifr, 2>;
    /* LSE ready interrupt flag */
    using cifr_lserdyf = lp::assoc_bit<cifr, 1>;
    /* LSI ready interrupt flag */
    using cifr_lsirdyf = lp::assoc_bit<cifr, 0>;
    /* HSI48 ready interrupt flag */
    using cifr_hsi48rdyf = lp::assoc_bit<cifr, 10>;


    /* Clock interrupt clear register */
    using cicr = lp::io_register<lp::u32_t, base_address + 0x20>;
    /* LSE Clock security system interrupt               clear */
    using cicr_lsecssc = lp::assoc_bit<cicr, 9>;
    /* Clock security system interrupt               clear */
    using cicr_cssc = lp::assoc_bit<cicr, 8>;
    /* PLLSAI2 ready interrupt               clear */
    using cicr_pllsai2rdyc = lp::assoc_bit<cicr, 7>;
    /* PLLSAI1 ready interrupt               clear */
    using cicr_pllsai1rdyc = lp::assoc_bit<cicr, 6>;
    /* PLL ready interrupt clear */
    using cicr_pllrdyc = lp::assoc_bit<cicr, 5>;
    /* HSE ready interrupt clear */
    using cicr_hserdyc = lp::assoc_bit<cicr, 4>;
    /* HSI ready interrupt clear */
    using cicr_hsirdyc = lp::assoc_bit<cicr, 3>;
    /* MSI ready interrupt clear */
    using cicr_msirdyc = lp::assoc_bit<cicr, 2>;
    /* LSE ready interrupt clear */
    using cicr_lserdyc = lp::assoc_bit<cicr, 1>;
    /* LSI ready interrupt clear */
    using cicr_lsirdyc = lp::assoc_bit<cicr, 0>;
    /* HSI48 oscillator ready interrupt               clear */
    using cicr_hsi48rdyc = lp::assoc_bit<cicr, 10>;


    /* AHB1 peripheral reset register */
    using ahb1rstr = lp::io_register<lp::u32_t, base_address + 0x28>;
    /* Touch Sensing Controller               reset */
    using ahb1rstr_tscrst = lp::assoc_bit<ahb1rstr, 16>;
    /* CRC reset */
    using ahb1rstr_crcrst = lp::assoc_bit<ahb1rstr, 12>;
    /* Flash memory interface               reset */
    using ahb1rstr_flashrst = lp::assoc_bit<ahb1rstr, 8>;
    /* DMA2 reset */
    using ahb1rstr_dma2rst = lp::assoc_bit<ahb1rstr, 1>;
    /* DMA1 reset */
    using ahb1rstr_dma1rst = lp::assoc_bit<ahb1rstr, 0>;
    /* DMA2D reset */
    using ahb1rstr_dma2drst = lp::assoc_bit<ahb1rstr, 17>;


    /* AHB2 peripheral reset register */
    using ahb2rstr = lp::io_register<lp::u32_t, base_address + 0x2c>;
    /* Random number generator               reset */
    using ahb2rstr_rngrst = lp::assoc_bit<ahb2rstr, 18>;
    /* AES hardware accelerator               reset */
    using ahb2rstr_aesrst = lp::assoc_bit<ahb2rstr, 16>;
    /* ADC reset */
    using ahb2rstr_adcrst = lp::assoc_bit<ahb2rstr, 13>;
    /* USB OTG FS reset */
    using ahb2rstr_otgfsrst = lp::assoc_bit<ahb2rstr, 12>;
    /* IO port H reset */
    using ahb2rstr_gpiohrst = lp::assoc_bit<ahb2rstr, 7>;
    /* IO port G reset */
    using ahb2rstr_gpiogrst = lp::assoc_bit<ahb2rstr, 6>;
    /* IO port F reset */
    using ahb2rstr_gpiofrst = lp::assoc_bit<ahb2rstr, 5>;
    /* IO port E reset */
    using ahb2rstr_gpioerst = lp::assoc_bit<ahb2rstr, 4>;
    /* IO port D reset */
    using ahb2rstr_gpiodrst = lp::assoc_bit<ahb2rstr, 3>;
    /* IO port C reset */
    using ahb2rstr_gpiocrst = lp::assoc_bit<ahb2rstr, 2>;
    /* IO port B reset */
    using ahb2rstr_gpiobrst = lp::assoc_bit<ahb2rstr, 1>;
    /* IO port A reset */
    using ahb2rstr_gpioarst = lp::assoc_bit<ahb2rstr, 0>;
    /* IO port I reset */
    using ahb2rstr_gpioirst = lp::assoc_bit<ahb2rstr, 8>;
    /* Digital Camera Interface               reset */
    using ahb2rstr_dcmirst = lp::assoc_bit<ahb2rstr, 14>;
    /* Hash reset */
    using ahb2rstr_hash1rst = lp::assoc_bit<ahb2rstr, 17>;


    /* AHB3 peripheral reset register */
    using ahb3rstr = lp::io_register<lp::u32_t, base_address + 0x30>;
    /* Quad SPI memory interface               reset */
    using ahb3rstr_qspirst = lp::assoc_bit<ahb3rstr, 8>;
    /* Flexible memory controller               reset */
    using ahb3rstr_fmcrst = lp::assoc_bit<ahb3rstr, 0>;


    /* APB1 peripheral reset register           1 */
    using apb1rstr1 = lp::io_register<lp::u32_t, base_address + 0x38>;
    /* Low Power Timer 1 reset */
    using apb1rstr1_lptim1rst = lp::assoc_bit<apb1rstr1, 31>;
    /* OPAMP interface reset */
    using apb1rstr1_opamprst = lp::assoc_bit<apb1rstr1, 30>;
    /* DAC1 interface reset */
    using apb1rstr1_dac1rst = lp::assoc_bit<apb1rstr1, 29>;
    /* Power interface reset */
    using apb1rstr1_pwrrst = lp::assoc_bit<apb1rstr1, 28>;
    /* CAN1 reset */
    using apb1rstr1_can1rst = lp::assoc_bit<apb1rstr1, 25>;
    /* I2C3 reset */
    using apb1rstr1_i2c3rst = lp::assoc_bit<apb1rstr1, 23>;
    /* I2C2 reset */
    using apb1rstr1_i2c2rst = lp::assoc_bit<apb1rstr1, 22>;
    /* I2C1 reset */
    using apb1rstr1_i2c1rst = lp::assoc_bit<apb1rstr1, 21>;
    /* UART5 reset */
    using apb1rstr1_uart5rst = lp::assoc_bit<apb1rstr1, 20>;
    /* UART4 reset */
    using apb1rstr1_uart4rst = lp::assoc_bit<apb1rstr1, 19>;
    /* USART3 reset */
    using apb1rstr1_usart3rst = lp::assoc_bit<apb1rstr1, 18>;
    /* USART2 reset */
    using apb1rstr1_usart2rst = lp::assoc_bit<apb1rstr1, 17>;
    /* SPI3 reset */
    using apb1rstr1_spi3rst = lp::assoc_bit<apb1rstr1, 15>;
    /* SPI2 reset */
    using apb1rstr1_spi2rst = lp::assoc_bit<apb1rstr1, 14>;
    /* LCD interface reset */
    using apb1rstr1_lcdrst = lp::assoc_bit<apb1rstr1, 9>;
    /* TIM7 timer reset */
    using apb1rstr1_tim7rst = lp::assoc_bit<apb1rstr1, 5>;
    /* TIM6 timer reset */
    using apb1rstr1_tim6rst = lp::assoc_bit<apb1rstr1, 4>;
    /* TIM5 timer reset */
    using apb1rstr1_tim5rst = lp::assoc_bit<apb1rstr1, 3>;
    /* TIM3 timer reset */
    using apb1rstr1_tim4rst = lp::assoc_bit<apb1rstr1, 2>;
    /* TIM3 timer reset */
    using apb1rstr1_tim3rst = lp::assoc_bit<apb1rstr1, 1>;
    /* TIM2 timer reset */
    using apb1rstr1_tim2rst = lp::assoc_bit<apb1rstr1, 0>;
    /* CRS reset */
    using apb1rstr1_crsrst = lp::assoc_bit<apb1rstr1, 24>;
    /* CAN2 reset */
    using apb1rstr1_can2rst = lp::assoc_bit<apb1rstr1, 26>;


    /* APB1 peripheral reset register           2 */
    using apb1rstr2 = lp::io_register<lp::u32_t, base_address + 0x3c>;
    /* Low-power timer 2 reset */
    using apb1rstr2_lptim2rst = lp::assoc_bit<apb1rstr2, 5>;
    /* Single wire protocol reset */
    using apb1rstr2_swpmi1rst = lp::assoc_bit<apb1rstr2, 2>;
    /* Low-power UART 1 reset */
    using apb1rstr2_lpuart1rst = lp::assoc_bit<apb1rstr2, 0>;
    /* I2C4 reset */
    using apb1rstr2_i2c4rst = lp::assoc_bit<apb1rstr2, 1>;


    /* APB2 peripheral reset register */
    using apb2rstr = lp::io_register<lp::u32_t, base_address + 0x40>;
    /* Digital filters for sigma-delata               modulators (DFSDM) reset */
    using apb2rstr_dfsdmrst = lp::assoc_bit<apb2rstr, 24>;
    /* Serial audio interface 2 (SAI2)               reset */
    using apb2rstr_sai2rst = lp::assoc_bit<apb2rstr, 22>;
    /* Serial audio interface 1 (SAI1)               reset */
    using apb2rstr_sai1rst = lp::assoc_bit<apb2rstr, 21>;
    /* TIM17 timer reset */
    using apb2rstr_tim17rst = lp::assoc_bit<apb2rstr, 18>;
    /* TIM16 timer reset */
    using apb2rstr_tim16rst = lp::assoc_bit<apb2rstr, 17>;
    /* TIM15 timer reset */
    using apb2rstr_tim15rst = lp::assoc_bit<apb2rstr, 16>;
    /* USART1 reset */
    using apb2rstr_usart1rst = lp::assoc_bit<apb2rstr, 14>;
    /* TIM8 timer reset */
    using apb2rstr_tim8rst = lp::assoc_bit<apb2rstr, 13>;
    /* SPI1 reset */
    using apb2rstr_spi1rst = lp::assoc_bit<apb2rstr, 12>;
    /* TIM1 timer reset */
    using apb2rstr_tim1rst = lp::assoc_bit<apb2rstr, 11>;
    /* SDMMC reset */
    using apb2rstr_sdmmcrst = lp::assoc_bit<apb2rstr, 10>;
    /* System configuration (SYSCFG)               reset */
    using apb2rstr_syscfgrst = lp::assoc_bit<apb2rstr, 0>;


    /* AHB1 peripheral clock enable           register */
    using ahb1enr = lp::io_register<lp::u32_t, base_address + 0x48>;
    /* Touch Sensing Controller clock               enable */
    using ahb1enr_tscen = lp::assoc_bit<ahb1enr, 16>;
    /* CRC clock enable */
    using ahb1enr_crcen = lp::assoc_bit<ahb1enr, 12>;
    /* Flash memory interface clock               enable */
    using ahb1enr_flashen = lp::assoc_bit<ahb1enr, 8>;
    /* DMA2 clock enable */
    using ahb1enr_dma2en = lp::assoc_bit<ahb1enr, 1>;
    /* DMA1 clock enable */
    using ahb1enr_dma1en = lp::assoc_bit<ahb1enr, 0>;
    /* DMA2D clock enable */
    using ahb1enr_dma2den = lp::assoc_bit<ahb1enr, 17>;


    /* AHB2 peripheral clock enable           register */
    using ahb2enr = lp::io_register<lp::u32_t, base_address + 0x4c>;
    /* Random Number Generator clock               enable */
    using ahb2enr_rngen = lp::assoc_bit<ahb2enr, 18>;
    /* AES accelerator clock               enable */
    using ahb2enr_aesen = lp::assoc_bit<ahb2enr, 16>;
    /* ADC clock enable */
    using ahb2enr_adcen = lp::assoc_bit<ahb2enr, 13>;
    /* OTG full speed clock               enable */
    using ahb2enr_otgfsen = lp::assoc_bit<ahb2enr, 12>;
    /* IO port H clock enable */
    using ahb2enr_gpiohen = lp::assoc_bit<ahb2enr, 7>;
    /* IO port G clock enable */
    using ahb2enr_gpiogen = lp::assoc_bit<ahb2enr, 6>;
    /* IO port F clock enable */
    using ahb2enr_gpiofen = lp::assoc_bit<ahb2enr, 5>;
    /* IO port E clock enable */
    using ahb2enr_gpioeen = lp::assoc_bit<ahb2enr, 4>;
    /* IO port D clock enable */
    using ahb2enr_gpioden = lp::assoc_bit<ahb2enr, 3>;
    /* IO port C clock enable */
    using ahb2enr_gpiocen = lp::assoc_bit<ahb2enr, 2>;
    /* IO port B clock enable */
    using ahb2enr_gpioben = lp::assoc_bit<ahb2enr, 1>;
    /* IO port A clock enable */
    using ahb2enr_gpioaen = lp::assoc_bit<ahb2enr, 0>;
    /* IO port I clock enable */
    using ahb2enr_gpioien = lp::assoc_bit<ahb2enr, 8>;
    /* DCMI clock enable */
    using ahb2enr_dcmien = lp::assoc_bit<ahb2enr, 14>;
    /* HASH clock enable */
    using ahb2enr_hash1en = lp::assoc_bit<ahb2enr, 17>;


    /* AHB3 peripheral clock enable           register */
    using ahb3enr = lp::io_register<lp::u32_t, base_address + 0x50>;
    /* QSPIEN */
    using ahb3enr_qspien = lp::assoc_bit<ahb3enr, 8>;
    /* Flexible memory controller clock               enable */
    using ahb3enr_fmcen = lp::assoc_bit<ahb3enr, 0>;


    /* APB1ENR1 */
    using apb1enr1 = lp::io_register<lp::u32_t, base_address + 0x58>;
    /* Low power timer 1 clock               enable */
    using apb1enr1_lptim1en = lp::assoc_bit<apb1enr1, 31>;
    /* OPAMP interface clock               enable */
    using apb1enr1_opampen = lp::assoc_bit<apb1enr1, 30>;
    /* DAC1 interface clock               enable */
    using apb1enr1_dac1en = lp::assoc_bit<apb1enr1, 29>;
    /* Power interface clock               enable */
    using apb1enr1_pwren = lp::assoc_bit<apb1enr1, 28>;
    /* CAN1 clock enable */
    using apb1enr1_can1en = lp::assoc_bit<apb1enr1, 25>;
    /* I2C3 clock enable */
    using apb1enr1_i2c3en = lp::assoc_bit<apb1enr1, 23>;
    /* I2C2 clock enable */
    using apb1enr1_i2c2en = lp::assoc_bit<apb1enr1, 22>;
    /* I2C1 clock enable */
    using apb1enr1_i2c1en = lp::assoc_bit<apb1enr1, 21>;
    /* UART5 clock enable */
    using apb1enr1_uart5en = lp::assoc_bit<apb1enr1, 20>;
    /* UART4 clock enable */
    using apb1enr1_uart4en = lp::assoc_bit<apb1enr1, 19>;
    /* USART3 clock enable */
    using apb1enr1_usart3en = lp::assoc_bit<apb1enr1, 18>;
    /* USART2 clock enable */
    using apb1enr1_usart2en = lp::assoc_bit<apb1enr1, 17>;
    /* SPI3 clock enable */
    using apb1enr1_sp3en = lp::assoc_bit<apb1enr1, 15>;
    /* SPI2 clock enable */
    using apb1enr1_spi2en = lp::assoc_bit<apb1enr1, 14>;
    /* Window watchdog clock               enable */
    using apb1enr1_wwdgen = lp::assoc_bit<apb1enr1, 11>;
    /* LCD clock enable */
    using apb1enr1_lcden = lp::assoc_bit<apb1enr1, 9>;
    /* TIM7 timer clock enable */
    using apb1enr1_tim7en = lp::assoc_bit<apb1enr1, 5>;
    /* TIM6 timer clock enable */
    using apb1enr1_tim6en = lp::assoc_bit<apb1enr1, 4>;
    /* TIM5 timer clock enable */
    using apb1enr1_tim5en = lp::assoc_bit<apb1enr1, 3>;
    /* TIM4 timer clock enable */
    using apb1enr1_tim4en = lp::assoc_bit<apb1enr1, 2>;
    /* TIM3 timer clock enable */
    using apb1enr1_tim3en = lp::assoc_bit<apb1enr1, 1>;
    /* TIM2 timer clock enable */
    using apb1enr1_tim2en = lp::assoc_bit<apb1enr1, 0>;
    /* RTC APB clock enable */
    using apb1enr1_rtcapben = lp::assoc_bit<apb1enr1, 10>;
    /* Clock Recovery System clock               enable */
    using apb1enr1_crsen = lp::assoc_bit<apb1enr1, 24>;
    /* CAN2 clock enable */
    using apb1enr1_can2en = lp::assoc_bit<apb1enr1, 26>;


    /* APB1 peripheral clock enable register           2 */
    using apb1enr2 = lp::io_register<lp::u32_t, base_address + 0x5c>;
    /* LPTIM2EN */
    using apb1enr2_lptim2en = lp::assoc_bit<apb1enr2, 5>;
    /* Single wire protocol clock               enable */
    using apb1enr2_swpmi1en = lp::assoc_bit<apb1enr2, 2>;
    /* Low power UART 1 clock               enable */
    using apb1enr2_lpuart1en = lp::assoc_bit<apb1enr2, 0>;
    /* I2C4 clock enable */
    using apb1enr2_i2c4en = lp::assoc_bit<apb1enr2, 1>;


    /* APB2ENR */
    using apb2enr = lp::io_register<lp::u32_t, base_address + 0x60>;
    /* DFSDM timer clock enable */
    using apb2enr_dfsdmen = lp::assoc_bit<apb2enr, 24>;
    /* SAI2 clock enable */
    using apb2enr_sai2en = lp::assoc_bit<apb2enr, 22>;
    /* SAI1 clock enable */
    using apb2enr_sai1en = lp::assoc_bit<apb2enr, 21>;
    /* TIM17 timer clock enable */
    using apb2enr_tim17en = lp::assoc_bit<apb2enr, 18>;
    /* TIM16 timer clock enable */
    using apb2enr_tim16en = lp::assoc_bit<apb2enr, 17>;
    /* TIM15 timer clock enable */
    using apb2enr_tim15en = lp::assoc_bit<apb2enr, 16>;
    /* USART1clock enable */
    using apb2enr_usart1en = lp::assoc_bit<apb2enr, 14>;
    /* TIM8 timer clock enable */
    using apb2enr_tim8en = lp::assoc_bit<apb2enr, 13>;
    /* SPI1 clock enable */
    using apb2enr_spi1en = lp::assoc_bit<apb2enr, 12>;
    /* TIM1 timer clock enable */
    using apb2enr_tim1en = lp::assoc_bit<apb2enr, 11>;
    /* SDMMC clock enable */
    using apb2enr_sdmmcen = lp::assoc_bit<apb2enr, 10>;
    /* Firewall clock enable */
    using apb2enr_firewallen = lp::assoc_bit<apb2enr, 7>;
    /* SYSCFG clock enable */
    using apb2enr_syscfgen = lp::assoc_bit<apb2enr, 0>;


    /* AHB1 peripheral clocks enable in Sleep and           Stop modes register */
    using ahb1smenr = lp::io_register<lp::u32_t, base_address + 0x68>;
    /* Touch Sensing Controller clocks enable               during Sleep and Stop modes */
    using ahb1smenr_tscsmen = lp::assoc_bit<ahb1smenr, 16>;
    /* CRCSMEN */
    using ahb1smenr_crcsmen = lp::assoc_bit<ahb1smenr, 12>;
    /* SRAM1 interface clocks enable during               Sleep and Stop modes */
    using ahb1smenr_sram1smen = lp::assoc_bit<ahb1smenr, 9>;
    /* Flash memory interface clocks enable               during Sleep and Stop modes */
    using ahb1smenr_flashsmen = lp::assoc_bit<ahb1smenr, 8>;
    /* DMA2 clocks enable during Sleep and Stop               modes */
    using ahb1smenr_dma2smen = lp::assoc_bit<ahb1smenr, 1>;
    /* DMA1 clocks enable during Sleep and Stop               modes */
    using ahb1smenr_dma1smen = lp::assoc_bit<ahb1smenr, 0>;
    /* DMA2D clock enable during Sleep and Stop               modes */
    using ahb1smenr_dma2dsmen = lp::assoc_bit<ahb1smenr, 17>;


    /* AHB2 peripheral clocks enable in Sleep and           Stop modes register */
    using ahb2smenr = lp::io_register<lp::u32_t, base_address + 0x6c>;
    /* Random Number Generator clocks enable               during Sleep and Stop modes */
    using ahb2smenr_rngsmen = lp::assoc_bit<ahb2smenr, 18>;
    /* AES accelerator clocks enable during               Sleep and Stop modes */
    using ahb2smenr_aessmen = lp::assoc_bit<ahb2smenr, 16>;
    /* ADC clocks enable during Sleep and Stop               modes */
    using ahb2smenr_adcfssmen = lp::assoc_bit<ahb2smenr, 13>;
    /* OTG full speed clocks enable during               Sleep and Stop modes */
    using ahb2smenr_otgfssmen = lp::assoc_bit<ahb2smenr, 12>;
    /* SRAM2 interface clocks enable during               Sleep and Stop modes */
    using ahb2smenr_sram2smen = lp::assoc_bit<ahb2smenr, 9>;
    /* IO port H clocks enable during Sleep and               Stop modes */
    using ahb2smenr_gpiohsmen = lp::assoc_bit<ahb2smenr, 7>;
    /* IO port G clocks enable during Sleep and               Stop modes */
    using ahb2smenr_gpiogsmen = lp::assoc_bit<ahb2smenr, 6>;
    /* IO port F clocks enable during Sleep and               Stop modes */
    using ahb2smenr_gpiofsmen = lp::assoc_bit<ahb2smenr, 5>;
    /* IO port E clocks enable during Sleep and               Stop modes */
    using ahb2smenr_gpioesmen = lp::assoc_bit<ahb2smenr, 4>;
    /* IO port D clocks enable during Sleep and               Stop modes */
    using ahb2smenr_gpiodsmen = lp::assoc_bit<ahb2smenr, 3>;
    /* IO port C clocks enable during Sleep and               Stop modes */
    using ahb2smenr_gpiocsmen = lp::assoc_bit<ahb2smenr, 2>;
    /* IO port B clocks enable during Sleep and               Stop modes */
    using ahb2smenr_gpiobsmen = lp::assoc_bit<ahb2smenr, 1>;
    /* IO port A clocks enable during Sleep and               Stop modes */
    using ahb2smenr_gpioasmen = lp::assoc_bit<ahb2smenr, 0>;
    /* IO port I clocks enable during Sleep and               Stop modes */
    using ahb2smenr_gpioismen = lp::assoc_bit<ahb2smenr, 8>;
    /* DCMI clock enable during Sleep and Stop               modes */
    using ahb2smenr_dcmismen = lp::assoc_bit<ahb2smenr, 14>;
    /* HASH clock enable during Sleep and Stop               modes */
    using ahb2smenr_hash1smen = lp::assoc_bit<ahb2smenr, 17>;


    /* AHB3 peripheral clocks enable in Sleep and           Stop modes register */
    using ahb3smenr = lp::io_register<lp::u32_t, base_address + 0x70>;
    /* QSPISMEN */
    using ahb3smenr_qspismen = lp::assoc_bit<ahb3smenr, 8>;
    /* Flexible memory controller clocks enable               during Sleep and Stop modes */
    using ahb3smenr_fmcsmen = lp::assoc_bit<ahb3smenr, 0>;


    /* APB1SMENR1 */
    using apb1smenr1 = lp::io_register<lp::u32_t, base_address + 0x78>;
    /* Low power timer 1 clocks enable during               Sleep and Stop modes */
    using apb1smenr1_lptim1smen = lp::assoc_bit<apb1smenr1, 31>;
    /* OPAMP interface clocks enable during               Sleep and Stop modes */
    using apb1smenr1_opampsmen = lp::assoc_bit<apb1smenr1, 30>;
    /* DAC1 interface clocks enable during               Sleep and Stop modes */
    using apb1smenr1_dac1smen = lp::assoc_bit<apb1smenr1, 29>;
    /* Power interface clocks enable during               Sleep and Stop modes */
    using apb1smenr1_pwrsmen = lp::assoc_bit<apb1smenr1, 28>;
    /* CAN1 clocks enable during Sleep and Stop               modes */
    using apb1smenr1_can1smen = lp::assoc_bit<apb1smenr1, 25>;
    /* I2C3 clocks enable during Sleep and Stop               modes */
    using apb1smenr1_i2c3smen = lp::assoc_bit<apb1smenr1, 23>;
    /* I2C2 clocks enable during Sleep and Stop               modes */
    using apb1smenr1_i2c2smen = lp::assoc_bit<apb1smenr1, 22>;
    /* I2C1 clocks enable during Sleep and Stop               modes */
    using apb1smenr1_i2c1smen = lp::assoc_bit<apb1smenr1, 21>;
    /* UART5 clocks enable during Sleep and               Stop modes */
    using apb1smenr1_uart5smen = lp::assoc_bit<apb1smenr1, 20>;
    /* UART4 clocks enable during Sleep and               Stop modes */
    using apb1smenr1_uart4smen = lp::assoc_bit<apb1smenr1, 19>;
    /* USART3 clocks enable during Sleep and               Stop modes */
    using apb1smenr1_usart3smen = lp::assoc_bit<apb1smenr1, 18>;
    /* USART2 clocks enable during Sleep and               Stop modes */
    using apb1smenr1_usart2smen = lp::assoc_bit<apb1smenr1, 17>;
    /* SPI3 clocks enable during Sleep and Stop               modes */
    using apb1smenr1_sp3smen = lp::assoc_bit<apb1smenr1, 15>;
    /* SPI2 clocks enable during Sleep and Stop               modes */
    using apb1smenr1_spi2smen = lp::assoc_bit<apb1smenr1, 14>;
    /* Window watchdog clocks enable during               Sleep and Stop modes */
    using apb1smenr1_wwdgsmen = lp::assoc_bit<apb1smenr1, 11>;
    /* LCD clocks enable during Sleep and Stop               modes */
    using apb1smenr1_lcdsmen = lp::assoc_bit<apb1smenr1, 9>;
    /* TIM7 timer clocks enable during Sleep               and Stop modes */
    using apb1smenr1_tim7smen = lp::assoc_bit<apb1smenr1, 5>;
    /* TIM6 timer clocks enable during Sleep               and Stop modes */
    using apb1smenr1_tim6smen = lp::assoc_bit<apb1smenr1, 4>;
    /* TIM5 timer clocks enable during Sleep               and Stop modes */
    using apb1smenr1_tim5smen = lp::assoc_bit<apb1smenr1, 3>;
    /* TIM4 timer clocks enable during Sleep               and Stop modes */
    using apb1smenr1_tim4smen = lp::assoc_bit<apb1smenr1, 2>;
    /* TIM3 timer clocks enable during Sleep               and Stop modes */
    using apb1smenr1_tim3smen = lp::assoc_bit<apb1smenr1, 1>;
    /* TIM2 timer clocks enable during Sleep               and Stop modes */
    using apb1smenr1_tim2smen = lp::assoc_bit<apb1smenr1, 0>;
    /* RTC APB clock enable during Sleep and               Stop modes */
    using apb1smenr1_rtcapbsmen = lp::assoc_bit<apb1smenr1, 10>;
    /* CAN2 clocks enable during Sleep and Stop               modes */
    using apb1smenr1_can2smen = lp::assoc_bit<apb1smenr1, 26>;


    /* APB1 peripheral clocks enable in Sleep and           Stop modes register 2 */
    using apb1smenr2 = lp::io_register<lp::u32_t, base_address + 0x7c>;
    /* LPTIM2SMEN */
    using apb1smenr2_lptim2smen = lp::assoc_bit<apb1smenr2, 5>;
    /* Single wire protocol clocks enable               during Sleep and Stop modes */
    using apb1smenr2_swpmi1smen = lp::assoc_bit<apb1smenr2, 2>;
    /* Low power UART 1 clocks enable during               Sleep and Stop modes */
    using apb1smenr2_lpuart1smen = lp::assoc_bit<apb1smenr2, 0>;
    /* I2C4 clocks enable during Sleep and Stop               modes */
    using apb1smenr2_i2c4smen = lp::assoc_bit<apb1smenr2, 1>;


    /* APB2SMENR */
    using apb2smenr = lp::io_register<lp::u32_t, base_address + 0x80>;
    /* DFSDM timer clocks enable during Sleep               and Stop modes */
    using apb2smenr_dfsdmsmen = lp::assoc_bit<apb2smenr, 24>;
    /* SAI2 clocks enable during Sleep and Stop               modes */
    using apb2smenr_sai2smen = lp::assoc_bit<apb2smenr, 22>;
    /* SAI1 clocks enable during Sleep and Stop               modes */
    using apb2smenr_sai1smen = lp::assoc_bit<apb2smenr, 21>;
    /* TIM17 timer clocks enable during Sleep               and Stop modes */
    using apb2smenr_tim17smen = lp::assoc_bit<apb2smenr, 18>;
    /* TIM16 timer clocks enable during Sleep               and Stop modes */
    using apb2smenr_tim16smen = lp::assoc_bit<apb2smenr, 17>;
    /* TIM15 timer clocks enable during Sleep               and Stop modes */
    using apb2smenr_tim15smen = lp::assoc_bit<apb2smenr, 16>;
    /* USART1clocks enable during Sleep and               Stop modes */
    using apb2smenr_usart1smen = lp::assoc_bit<apb2smenr, 14>;
    /* TIM8 timer clocks enable during Sleep               and Stop modes */
    using apb2smenr_tim8smen = lp::assoc_bit<apb2smenr, 13>;
    /* SPI1 clocks enable during Sleep and Stop               modes */
    using apb2smenr_spi1smen = lp::assoc_bit<apb2smenr, 12>;
    /* TIM1 timer clocks enable during Sleep               and Stop modes */
    using apb2smenr_tim1smen = lp::assoc_bit<apb2smenr, 11>;
    /* SDMMC clocks enable during Sleep and               Stop modes */
    using apb2smenr_sdmmcsmen = lp::assoc_bit<apb2smenr, 10>;
    /* SYSCFG clocks enable during Sleep and               Stop modes */
    using apb2smenr_syscfgsmen = lp::assoc_bit<apb2smenr, 0>;


    /* CCIPR */
    using ccipr = lp::io_register<lp::u32_t, base_address + 0x88>;
    /* DFSDM clock source               selection */
    using ccipr_dfsdmsel = lp::assoc_bit<ccipr, 31>;
    /* SWPMI1 clock source               selection */
    using ccipr_swpmi1sel = lp::assoc_bit<ccipr, 30>;
    /* ADCs clock source               selection */
    using ccipr_adcsel = lp::assoc_bit<ccipr, 28, 2>;
    /* 48 MHz clock source               selection */
    using ccipr_clk48sel = lp::assoc_bit<ccipr, 26, 2>;
    /* SAI2 clock source               selection */
    using ccipr_sai2sel = lp::assoc_bit<ccipr, 24, 2>;
    /* SAI1 clock source               selection */
    using ccipr_sai1sel = lp::assoc_bit<ccipr, 22, 2>;
    /* Low power timer 2 clock source               selection */
    using ccipr_lptim2sel = lp::assoc_bit<ccipr, 20, 2>;
    /* Low power timer 1 clock source               selection */
    using ccipr_lptim1sel = lp::assoc_bit<ccipr, 18, 2>;
    /* I2C3 clock source               selection */
    using ccipr_i2c3sel = lp::assoc_bit<ccipr, 16, 2>;
    /* I2C2 clock source               selection */
    using ccipr_i2c2sel = lp::assoc_bit<ccipr, 14, 2>;
    /* I2C1 clock source               selection */
    using ccipr_i2c1sel = lp::assoc_bit<ccipr, 12, 2>;
    /* LPUART1 clock source               selection */
    using ccipr_lpuart1sel = lp::assoc_bit<ccipr, 10, 2>;
    /* UART5 clock source               selection */
    using ccipr_uart5sel = lp::assoc_bit<ccipr, 8, 2>;
    /* UART4 clock source               selection */
    using ccipr_uart4sel = lp::assoc_bit<ccipr, 6, 2>;
    /* USART3 clock source               selection */
    using ccipr_usart3sel = lp::assoc_bit<ccipr, 4, 2>;
    /* USART2 clock source               selection */
    using ccipr_usart2sel = lp::assoc_bit<ccipr, 2, 2>;
    /* USART1 clock source               selection */
    using ccipr_usart1sel = lp::assoc_bit<ccipr, 0, 2>;


    /* BDCR */
    using bdcr = lp::io_register<lp::u32_t, base_address + 0x90>;
    /* Low speed clock output               selection */
    using bdcr_lscosel = lp::assoc_bit<bdcr, 25>;
    /* Low speed clock output               enable */
    using bdcr_lscoen = lp::assoc_bit<bdcr, 24>;
    /* Backup domain software               reset */
    using bdcr_bdrst = lp::assoc_bit<bdcr, 16>;
    /* RTC clock enable */
    using bdcr_rtcen = lp::assoc_bit<bdcr, 15>;
    /* RTC clock source selection */
    using bdcr_rtcsel = lp::assoc_bit<bdcr, 8, 2>;
    /* LSECSSD */
    using bdcr_lsecssd = lp::assoc_bit<bdcr, 6>;
    /* LSECSSON */
    using bdcr_lsecsson = lp::assoc_bit<bdcr, 5>;
    /* SE oscillator drive               capability */
    using bdcr_lsedrv = lp::assoc_bit<bdcr, 3, 2>;
    /* LSE oscillator bypass */
    using bdcr_lsebyp = lp::assoc_bit<bdcr, 2>;
    /* LSE oscillator ready */
    using bdcr_lserdy = lp::assoc_bit<bdcr, 1>;
    /* LSE oscillator enable */
    using bdcr_lseon = lp::assoc_bit<bdcr, 0>;


    /* CSR */
    using csr = lp::io_register<lp::u32_t, base_address + 0x94>;
    /* Low-power reset flag */
    using csr_lpwrstf = lp::assoc_bit<csr, 31>;
    /* Window watchdog reset flag */
    using csr_wwdgrstf = lp::assoc_bit<csr, 30>;
    /* Independent window watchdog reset               flag */
    using csr_iwdgrstf = lp::assoc_bit<csr, 29>;
    /* Software reset flag */
    using csr_sftrstf = lp::assoc_bit<csr, 28>;
    /* BOR flag */
    using csr_borrstf = lp::assoc_bit<csr, 27>;
    /* Pin reset flag */
    using csr_pinrstf = lp::assoc_bit<csr, 26>;
    /* Option byte loader reset               flag */
    using csr_oblrstf = lp::assoc_bit<csr, 25>;
    /* Firewall reset flag */
    using csr_firewallrstf = lp::assoc_bit<csr, 24>;
    /* Remove reset flag */
    using csr_rmvf = lp::assoc_bit<csr, 23>;
    /* SI range after Standby               mode */
    using csr_msisrange = lp::assoc_bit<csr, 8, 4>;
    /* LSI oscillator ready */
    using csr_lsirdy = lp::assoc_bit<csr, 1>;
    /* LSI oscillator enable */
    using csr_lsion = lp::assoc_bit<csr, 0>;


};

using rcc = rcc_t<0x40021000>;

#endif // RCC_HH
