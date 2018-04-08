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
 * Hardware support for device interrupts
 * @file isr_extend.cc
 * @author Boris Vinogradov
 */

#include "isr_extend.hh"
#include "isr_extend_impl.hh"

__attribute__((noreturn)) void isr::default_handler_extend() {
    // nothing in prototype
    while (true);
}

__attribute__((section(".vectors.device"))) extern const isr::device_vectors device_vectors_table = {
    isr::WWDG,
    isr::PVD_PVM,
    isr::TAMP_STAMP,
    isr::RTC_WKUP,
    isr::FLASH,
    isr::RCC,
    isr::EXTI0,
    isr::EXTI1,
    isr::EXTI2,
    isr::EXTI3,
    isr::EXTI4,
    isr::DMA1_CH1,
    isr::DMA1_CH2,
    isr::DMA1_CH3,
    isr::DMA1_CH4,
    isr::DMA1_CH5,
    isr::DMA1_CH6,
    isr::DMA1_CH7,
    isr::ADC1_2,
    isr::CAN1_TX,
    isr::CAN1_RX0,
    isr::CAN1_RX1,
    isr::CAN1_SCE,
    isr::EXTI9_5,
    isr::TIM1_BRK_TIM15,
    isr::TIM1_UP_TIM16,
    isr::TIM1_TRG_COM_TIM17,
    isr::TIM1_CC,
    isr::TIM2,
    isr::TIM3,
    isr::TIM4,
    isr::I2C1_EV,
    isr::I2C1_ER,
    isr::I2C2_EV,
    isr::I2C2_ER,
    isr::SPI1,
    isr::SPI2,
    isr::USART1,
    isr::USART2,
    isr::USART3,
    isr::EXTI15_10,
    isr::RTC_ALARM,
    isr::DFSDM1_FLT3,
    isr::TIM8_BRK,
    isr::TIM8_UP,
    isr::TIM8_TRG_COM,
    isr::TIM8_CC,
    isr::ADC3,
    isr::FMC,
    isr::SDMMC1,
    isr::TIM5,
    isr::SPI3,
    isr::UART4,
    isr::UART5,
    isr::TIM6_DACUNDER,
    isr::TIM7,
    isr::DMA2_CH1,
    isr::DMA2_CH2,
    isr::DMA2_CH3,
    isr::DMA2_CH4,
    isr::DMA2_CH5,
    isr::DFSDM1_FLT0,
    isr::DFSDM1_FLT1,
    isr::DFSDM1_FLT2,
    isr::COMP,
    isr::LPTIM1,
    isr::LPTIM2,
    isr::OTG_FS,
    isr::DMA2_CH6,
    isr::DMA2_CH7,
    isr::LPUART1,
    isr::QUADSPI,
    isr::I2C3_EV,
    isr::I2C3_ER,
    isr::SAI1,
    isr::SAI2,
    isr::SWPMI1,
    isr::TSC,
    isr::LCD,
    isr::AES,
    isr::RNG_HASH,
    isr::FPU,
    isr::CRS,
    isr::I2C4_EV,
    isr::I2C4_ER,
    isr::DCMI,
    isr::CAN2_TX,
    isr::CAN2_RX0,
    isr::CAN2_RX1,
    isr::CAN2_SCE,
    isr::DMA2D,
};
