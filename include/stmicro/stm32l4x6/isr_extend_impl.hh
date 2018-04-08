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
 * Hardware support for device interrupts - implementation
 * @file isr_extend_impl.hh
 * @author Boris Vinogradov
 */

#ifndef ISR_EXTEND_IMPL_HH
#define ISR_EXTEND_IMPL_HH

extern "C" {
    namespace isr {
        void default_handler_extend(); // default handler for undefined device handlers

        void WWDG() __attribute__ ((weak, alias ("default_handler_extend")));
        void PVD_PVM() __attribute__ ((weak, alias ("default_handler_extend")));
        void TAMP_STAMP() __attribute__ ((weak, alias ("default_handler_extend")));
        void RTC_WKUP() __attribute__ ((weak, alias ("default_handler_extend")));
        void FLASH() __attribute__ ((weak, alias ("default_handler_extend")));
        void RCC() __attribute__ ((weak, alias ("default_handler_extend")));
        void EXTI0() __attribute__ ((weak, alias ("default_handler_extend")));
        void EXTI1() __attribute__ ((weak, alias ("default_handler_extend")));
        void EXTI2() __attribute__ ((weak, alias ("default_handler_extend")));
        void EXTI3() __attribute__ ((weak, alias ("default_handler_extend")));
        void EXTI4() __attribute__ ((weak, alias ("default_handler_extend")));
        void DMA1_CH1() __attribute__ ((weak, alias ("default_handler_extend")));
        void DMA1_CH2() __attribute__ ((weak, alias ("default_handler_extend")));
        void DMA1_CH3() __attribute__ ((weak, alias ("default_handler_extend")));
        void DMA1_CH4() __attribute__ ((weak, alias ("default_handler_extend")));
        void DMA1_CH5() __attribute__ ((weak, alias ("default_handler_extend")));
        void DMA1_CH6() __attribute__ ((weak, alias ("default_handler_extend")));
        void DMA1_CH7() __attribute__ ((weak, alias ("default_handler_extend")));
        void ADC1_2() __attribute__ ((weak, alias ("default_handler_extend")));
        void CAN1_TX() __attribute__ ((weak, alias ("default_handler_extend")));
        void CAN1_RX0() __attribute__ ((weak, alias ("default_handler_extend")));
        void CAN1_RX1() __attribute__ ((weak, alias ("default_handler_extend")));
        void CAN1_SCE() __attribute__ ((weak, alias ("default_handler_extend")));
        void EXTI9_5() __attribute__ ((weak, alias ("default_handler_extend")));
        void TIM1_BRK_TIM15() __attribute__ ((weak, alias ("default_handler_extend")));
        void TIM1_UP_TIM16() __attribute__ ((weak, alias ("default_handler_extend")));
        void TIM1_TRG_COM_TIM17() __attribute__ ((weak, alias ("default_handler_extend")));
        void TIM1_CC() __attribute__ ((weak, alias ("default_handler_extend")));
        void TIM2() __attribute__ ((weak, alias ("default_handler_extend")));
        void TIM3() __attribute__ ((weak, alias ("default_handler_extend")));
        void TIM4() __attribute__ ((weak, alias ("default_handler_extend")));
        void I2C1_EV() __attribute__ ((weak, alias ("default_handler_extend")));
        void I2C1_ER() __attribute__ ((weak, alias ("default_handler_extend")));
        void I2C2_EV() __attribute__ ((weak, alias ("default_handler_extend")));
        void I2C2_ER() __attribute__ ((weak, alias ("default_handler_extend")));
        void SPI1() __attribute__ ((weak, alias ("default_handler_extend")));
        void SPI2() __attribute__ ((weak, alias ("default_handler_extend")));
        void USART1() __attribute__ ((weak, alias ("default_handler_extend")));
        void USART2() __attribute__ ((weak, alias ("default_handler_extend")));
        void USART3() __attribute__ ((weak, alias ("default_handler_extend")));
        void EXTI15_10() __attribute__ ((weak, alias ("default_handler_extend")));
        void RTC_ALARM() __attribute__ ((weak, alias ("default_handler_extend")));
        void DFSDM1_FLT3() __attribute__ ((weak, alias ("default_handler_extend")));
        void TIM8_BRK() __attribute__ ((weak, alias ("default_handler_extend")));
        void TIM8_UP() __attribute__ ((weak, alias ("default_handler_extend")));
        void TIM8_TRG_COM() __attribute__ ((weak, alias ("default_handler_extend")));
        void TIM8_CC() __attribute__ ((weak, alias ("default_handler_extend")));
        void ADC3() __attribute__ ((weak, alias ("default_handler_extend")));
        void FMC() __attribute__ ((weak, alias ("default_handler_extend")));
        void SDMMC1() __attribute__ ((weak, alias ("default_handler_extend")));
        void TIM5() __attribute__ ((weak, alias ("default_handler_extend")));
        void SPI3() __attribute__ ((weak, alias ("default_handler_extend")));
        void UART4() __attribute__ ((weak, alias ("default_handler_extend")));
        void UART5() __attribute__ ((weak, alias ("default_handler_extend")));
        void TIM6_DACUNDER() __attribute__ ((weak, alias ("default_handler_extend")));
        void TIM7() __attribute__ ((weak, alias ("default_handler_extend")));
        void DMA2_CH1() __attribute__ ((weak, alias ("default_handler_extend")));
        void DMA2_CH2() __attribute__ ((weak, alias ("default_handler_extend")));
        void DMA2_CH3() __attribute__ ((weak, alias ("default_handler_extend")));
        void DMA2_CH4() __attribute__ ((weak, alias ("default_handler_extend")));
        void DMA2_CH5() __attribute__ ((weak, alias ("default_handler_extend")));
        void DFSDM1_FLT0() __attribute__ ((weak, alias ("default_handler_extend")));
        void DFSDM1_FLT1() __attribute__ ((weak, alias ("default_handler_extend")));
        void DFSDM1_FLT2() __attribute__ ((weak, alias ("default_handler_extend")));
        void COMP() __attribute__ ((weak, alias ("default_handler_extend")));
        void LPTIM1() __attribute__ ((weak, alias ("default_handler_extend")));
        void LPTIM2() __attribute__ ((weak, alias ("default_handler_extend")));
        void OTG_FS() __attribute__ ((weak, alias ("default_handler_extend")));
        void DMA2_CH6() __attribute__ ((weak, alias ("default_handler_extend")));
        void DMA2_CH7() __attribute__ ((weak, alias ("default_handler_extend")));
        void LPUART1() __attribute__ ((weak, alias ("default_handler_extend")));
        void QUADSPI() __attribute__ ((weak, alias ("default_handler_extend")));
        void I2C3_EV() __attribute__ ((weak, alias ("default_handler_extend")));
        void I2C3_ER() __attribute__ ((weak, alias ("default_handler_extend")));
        void SAI1() __attribute__ ((weak, alias ("default_handler_extend")));
        void SAI2() __attribute__ ((weak, alias ("default_handler_extend")));
        void SWPMI1() __attribute__ ((weak, alias ("default_handler_extend")));
        void TSC() __attribute__ ((weak, alias ("default_handler_extend")));
        void LCD() __attribute__ ((weak, alias ("default_handler_extend")));
        void AES() __attribute__ ((weak, alias ("default_handler_extend")));
        void RNG_HASH() __attribute__ ((weak, alias ("default_handler_extend")));
        void FPU() __attribute__ ((weak, alias ("default_handler_extend")));
        void CRS() __attribute__ ((weak, alias ("default_handler_extend")));
        void I2C4_EV() __attribute__ ((weak, alias ("default_handler_extend")));
        void I2C4_ER() __attribute__ ((weak, alias ("default_handler_extend")));
        void DCMI() __attribute__ ((weak, alias ("default_handler_extend")));
        void CAN2_TX() __attribute__ ((weak, alias ("default_handler_extend")));
        void CAN2_RX0() __attribute__ ((weak, alias ("default_handler_extend")));
        void CAN2_RX1() __attribute__ ((weak, alias ("default_handler_extend")));
        void CAN2_SCE() __attribute__ ((weak, alias ("default_handler_extend")));
        void DMA2D() __attribute__ ((weak, alias ("default_handler_extend")));
    }
}

#endif // ISR_EXTEND_IMPL_HH
