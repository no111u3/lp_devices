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
 * Hardware abstraction layer for device rcc
 * @file rcc_device.hh
 * @author Boris Vinogradov
 */

#include <rcc.hh>
#ifndef HAL_RCC_DEVICE_HH
#define HAL_RCC_DEVICE_HH

namespace hal {
    namespace rcc_device {
        /* Touch Sensing Controller clock               enable */
        using tscen = rcc::ahb1enr_tscen;
        /* CRC clock enable */
        using crcen = rcc::ahb1enr_crcen;
        /* Flash memory interface clock               enable */
        using flashen = rcc::ahb1enr_flashen;
        /* DMA2 clock enable */
        using dma2en = rcc::ahb1enr_dma2en;
        /* DMA1 clock enable */
        using dma1en = rcc::ahb1enr_dma1en;
        /* DMA2D clock enable */
        using dma2den = rcc::ahb1enr_dma2den;
        /* Random Number Generator clock               enable */
        using rngen = rcc::ahb2enr_rngen;
        /* AES accelerator clock               enable */
        using aesen = rcc::ahb2enr_aesen;
        /* ADC clock enable */
        using adcen = rcc::ahb2enr_adcen;
        /* OTG full speed clock               enable */
        using otgfsen = rcc::ahb2enr_otgfsen;
        /* IO port H clock enable */
        using gpiohen = rcc::ahb2enr_gpiohen;
        /* IO port G clock enable */
        using gpiogen = rcc::ahb2enr_gpiogen;
        /* IO port F clock enable */
        using gpiofen = rcc::ahb2enr_gpiofen;
        /* IO port E clock enable */
        using gpioeen = rcc::ahb2enr_gpioeen;
        /* IO port D clock enable */
        using gpioden = rcc::ahb2enr_gpioden;
        /* IO port C clock enable */
        using gpiocen = rcc::ahb2enr_gpiocen;
        /* IO port B clock enable */
        using gpioben = rcc::ahb2enr_gpioben;
        /* IO port A clock enable */
        using gpioaen = rcc::ahb2enr_gpioaen;
        /* IO port I clock enable */
        using gpioien = rcc::ahb2enr_gpioien;
        /* DCMI clock enable */
        using dcmien = rcc::ahb2enr_dcmien;
        /* HASH clock enable */
        using hash1en = rcc::ahb2enr_hash1en;
        /* QSPIEN */
        using qspien = rcc::ahb3enr_qspien;
        /* Flexible memory controller clock               enable */
        using fmcen = rcc::ahb3enr_fmcen;
        /* Low power timer 1 clock               enable */
        using lptim1en = rcc::apb1enr1_lptim1en;
        /* OPAMP interface clock               enable */
        using opampen = rcc::apb1enr1_opampen;
        /* DAC1 interface clock               enable */
        using dac1en = rcc::apb1enr1_dac1en;
        /* Power interface clock               enable */
        using pwren = rcc::apb1enr1_pwren;
        /* CAN1 clock enable */
        using can1en = rcc::apb1enr1_can1en;
        /* I2C3 clock enable */
        using i2c3en = rcc::apb1enr1_i2c3en;
        /* I2C2 clock enable */
        using i2c2en = rcc::apb1enr1_i2c2en;
        /* I2C1 clock enable */
        using i2c1en = rcc::apb1enr1_i2c1en;
        /* UART5 clock enable */
        using uart5en = rcc::apb1enr1_uart5en;
        /* UART4 clock enable */
        using uart4en = rcc::apb1enr1_uart4en;
        /* USART3 clock enable */
        using usart3en = rcc::apb1enr1_usart3en;
        /* USART2 clock enable */
        using usart2en = rcc::apb1enr1_usart2en;
        /* SPI3 clock enable */
        using sp3en = rcc::apb1enr1_sp3en;
        /* SPI2 clock enable */
        using spi2en = rcc::apb1enr1_spi2en;
        /* Window watchdog clock               enable */
        using wwdgen = rcc::apb1enr1_wwdgen;
        /* LCD clock enable */
        using lcden = rcc::apb1enr1_lcden;
        /* TIM7 timer clock enable */
        using tim7en = rcc::apb1enr1_tim7en;
        /* TIM6 timer clock enable */
        using tim6en = rcc::apb1enr1_tim6en;
        /* TIM5 timer clock enable */
        using tim5en = rcc::apb1enr1_tim5en;
        /* TIM4 timer clock enable */
        using tim4en = rcc::apb1enr1_tim4en;
        /* TIM3 timer clock enable */
        using tim3en = rcc::apb1enr1_tim3en;
        /* TIM2 timer clock enable */
        using tim2en = rcc::apb1enr1_tim2en;
        /* RTC APB clock enable */
        using rtcapben = rcc::apb1enr1_rtcapben;
        /* Clock Recovery System clock               enable */
        using crsen = rcc::apb1enr1_crsen;
        /* CAN2 clock enable */
        using can2en = rcc::apb1enr1_can2en;
        /* LPTIM2EN */
        using lptim2en = rcc::apb1enr2_lptim2en;
        /* Single wire protocol clock               enable */
        using swpmi1en = rcc::apb1enr2_swpmi1en;
        /* Low power UART 1 clock               enable */
        using lpuart1en = rcc::apb1enr2_lpuart1en;
        /* I2C4 clock enable */
        using i2c4en = rcc::apb1enr2_i2c4en;
        /* DFSDM timer clock enable */
        using dfsdmen = rcc::apb2enr_dfsdmen;
        /* SAI2 clock enable */
        using sai2en = rcc::apb2enr_sai2en;
        /* SAI1 clock enable */
        using sai1en = rcc::apb2enr_sai1en;
        /* TIM17 timer clock enable */
        using tim17en = rcc::apb2enr_tim17en;
        /* TIM16 timer clock enable */
        using tim16en = rcc::apb2enr_tim16en;
        /* TIM15 timer clock enable */
        using tim15en = rcc::apb2enr_tim15en;
        /* USART1clock enable */
        using usart1en = rcc::apb2enr_usart1en;
        /* TIM8 timer clock enable */
        using tim8en = rcc::apb2enr_tim8en;
        /* SPI1 clock enable */
        using spi1en = rcc::apb2enr_spi1en;
        /* TIM1 timer clock enable */
        using tim1en = rcc::apb2enr_tim1en;
        /* SDMMC clock enable */
        using sdmmcen = rcc::apb2enr_sdmmcen;
        /* Firewall clock enable */
        using firewallen = rcc::apb2enr_firewallen;
        /* SYSCFG clock enable */
        using syscfgen = rcc::apb2enr_syscfgen;
        /* Touch Sensing Controller clocks enable               during Sleep and Stop modes */
        using tscsmen = rcc::ahb1smenr_tscsmen;
        /* CRCSMEN */
        using crcsmen = rcc::ahb1smenr_crcsmen;
        /* SRAM1 interface clocks enable during               Sleep and Stop modes */
        using sram1smen = rcc::ahb1smenr_sram1smen;
        /* Flash memory interface clocks enable               during Sleep and Stop modes */
        using flashsmen = rcc::ahb1smenr_flashsmen;
        /* DMA2 clocks enable during Sleep and Stop               modes */
        using dma2smen = rcc::ahb1smenr_dma2smen;
        /* DMA1 clocks enable during Sleep and Stop               modes */
        using dma1smen = rcc::ahb1smenr_dma1smen;
        /* DMA2D clock enable during Sleep and Stop               modes */
        using dma2dsmen = rcc::ahb1smenr_dma2dsmen;
        /* Random Number Generator clocks enable               during Sleep and Stop modes */
        using rngsmen = rcc::ahb2smenr_rngsmen;
        /* AES accelerator clocks enable during               Sleep and Stop modes */
        using aessmen = rcc::ahb2smenr_aessmen;
        /* ADC clocks enable during Sleep and Stop               modes */
        using adcfssmen = rcc::ahb2smenr_adcfssmen;
        /* OTG full speed clocks enable during               Sleep and Stop modes */
        using otgfssmen = rcc::ahb2smenr_otgfssmen;
        /* SRAM2 interface clocks enable during               Sleep and Stop modes */
        using sram2smen = rcc::ahb2smenr_sram2smen;
        /* IO port H clocks enable during Sleep and               Stop modes */
        using gpiohsmen = rcc::ahb2smenr_gpiohsmen;
        /* IO port G clocks enable during Sleep and               Stop modes */
        using gpiogsmen = rcc::ahb2smenr_gpiogsmen;
        /* IO port F clocks enable during Sleep and               Stop modes */
        using gpiofsmen = rcc::ahb2smenr_gpiofsmen;
        /* IO port E clocks enable during Sleep and               Stop modes */
        using gpioesmen = rcc::ahb2smenr_gpioesmen;
        /* IO port D clocks enable during Sleep and               Stop modes */
        using gpiodsmen = rcc::ahb2smenr_gpiodsmen;
        /* IO port C clocks enable during Sleep and               Stop modes */
        using gpiocsmen = rcc::ahb2smenr_gpiocsmen;
        /* IO port B clocks enable during Sleep and               Stop modes */
        using gpiobsmen = rcc::ahb2smenr_gpiobsmen;
        /* IO port A clocks enable during Sleep and               Stop modes */
        using gpioasmen = rcc::ahb2smenr_gpioasmen;
        /* IO port I clocks enable during Sleep and               Stop modes */
        using gpioismen = rcc::ahb2smenr_gpioismen;
        /* DCMI clock enable during Sleep and Stop               modes */
        using dcmismen = rcc::ahb2smenr_dcmismen;
        /* HASH clock enable during Sleep and Stop               modes */
        using hash1smen = rcc::ahb2smenr_hash1smen;
        /* QSPISMEN */
        using qspismen = rcc::ahb3smenr_qspismen;
        /* Flexible memory controller clocks enable               during Sleep and Stop modes */
        using fmcsmen = rcc::ahb3smenr_fmcsmen;
        /* Low power timer 1 clocks enable during               Sleep and Stop modes */
        using lptim1smen = rcc::apb1smenr1_lptim1smen;
        /* OPAMP interface clocks enable during               Sleep and Stop modes */
        using opampsmen = rcc::apb1smenr1_opampsmen;
        /* DAC1 interface clocks enable during               Sleep and Stop modes */
        using dac1smen = rcc::apb1smenr1_dac1smen;
        /* Power interface clocks enable during               Sleep and Stop modes */
        using pwrsmen = rcc::apb1smenr1_pwrsmen;
        /* CAN1 clocks enable during Sleep and Stop               modes */
        using can1smen = rcc::apb1smenr1_can1smen;
        /* I2C3 clocks enable during Sleep and Stop               modes */
        using i2c3smen = rcc::apb1smenr1_i2c3smen;
        /* I2C2 clocks enable during Sleep and Stop               modes */
        using i2c2smen = rcc::apb1smenr1_i2c2smen;
        /* I2C1 clocks enable during Sleep and Stop               modes */
        using i2c1smen = rcc::apb1smenr1_i2c1smen;
        /* UART5 clocks enable during Sleep and               Stop modes */
        using uart5smen = rcc::apb1smenr1_uart5smen;
        /* UART4 clocks enable during Sleep and               Stop modes */
        using uart4smen = rcc::apb1smenr1_uart4smen;
        /* USART3 clocks enable during Sleep and               Stop modes */
        using usart3smen = rcc::apb1smenr1_usart3smen;
        /* USART2 clocks enable during Sleep and               Stop modes */
        using usart2smen = rcc::apb1smenr1_usart2smen;
        /* SPI3 clocks enable during Sleep and Stop               modes */
        using sp3smen = rcc::apb1smenr1_sp3smen;
        /* SPI2 clocks enable during Sleep and Stop               modes */
        using spi2smen = rcc::apb1smenr1_spi2smen;
        /* Window watchdog clocks enable during               Sleep and Stop modes */
        using wwdgsmen = rcc::apb1smenr1_wwdgsmen;
        /* LCD clocks enable during Sleep and Stop               modes */
        using lcdsmen = rcc::apb1smenr1_lcdsmen;
        /* TIM7 timer clocks enable during Sleep               and Stop modes */
        using tim7smen = rcc::apb1smenr1_tim7smen;
        /* TIM6 timer clocks enable during Sleep               and Stop modes */
        using tim6smen = rcc::apb1smenr1_tim6smen;
        /* TIM5 timer clocks enable during Sleep               and Stop modes */
        using tim5smen = rcc::apb1smenr1_tim5smen;
        /* TIM4 timer clocks enable during Sleep               and Stop modes */
        using tim4smen = rcc::apb1smenr1_tim4smen;
        /* TIM3 timer clocks enable during Sleep               and Stop modes */
        using tim3smen = rcc::apb1smenr1_tim3smen;
        /* TIM2 timer clocks enable during Sleep               and Stop modes */
        using tim2smen = rcc::apb1smenr1_tim2smen;
        /* RTC APB clock enable during Sleep and               Stop modes */
        using rtcapbsmen = rcc::apb1smenr1_rtcapbsmen;
        /* CAN2 clocks enable during Sleep and Stop               modes */
        using can2smen = rcc::apb1smenr1_can2smen;
        /* LPTIM2SMEN */
        using lptim2smen = rcc::apb1smenr2_lptim2smen;
        /* Single wire protocol clocks enable               during Sleep and Stop modes */
        using swpmi1smen = rcc::apb1smenr2_swpmi1smen;
        /* Low power UART 1 clocks enable during               Sleep and Stop modes */
        using lpuart1smen = rcc::apb1smenr2_lpuart1smen;
        /* I2C4 clocks enable during Sleep and Stop               modes */
        using i2c4smen = rcc::apb1smenr2_i2c4smen;
        /* DFSDM timer clocks enable during Sleep               and Stop modes */
        using dfsdmsmen = rcc::apb2smenr_dfsdmsmen;
        /* SAI2 clocks enable during Sleep and Stop               modes */
        using sai2smen = rcc::apb2smenr_sai2smen;
        /* SAI1 clocks enable during Sleep and Stop               modes */
        using sai1smen = rcc::apb2smenr_sai1smen;
        /* TIM17 timer clocks enable during Sleep               and Stop modes */
        using tim17smen = rcc::apb2smenr_tim17smen;
        /* TIM16 timer clocks enable during Sleep               and Stop modes */
        using tim16smen = rcc::apb2smenr_tim16smen;
        /* TIM15 timer clocks enable during Sleep               and Stop modes */
        using tim15smen = rcc::apb2smenr_tim15smen;
        /* USART1clocks enable during Sleep and               Stop modes */
        using usart1smen = rcc::apb2smenr_usart1smen;
        /* TIM8 timer clocks enable during Sleep               and Stop modes */
        using tim8smen = rcc::apb2smenr_tim8smen;
        /* SPI1 clocks enable during Sleep and Stop               modes */
        using spi1smen = rcc::apb2smenr_spi1smen;
        /* TIM1 timer clocks enable during Sleep               and Stop modes */
        using tim1smen = rcc::apb2smenr_tim1smen;
        /* SDMMC clocks enable during Sleep and               Stop modes */
        using sdmmcsmen = rcc::apb2smenr_sdmmcsmen;
        /* SYSCFG clocks enable during Sleep and               Stop modes */
        using syscfgsmen = rcc::apb2smenr_syscfgsmen;
    }
}

#endif // HAL_RCC_DEVICE_HH
