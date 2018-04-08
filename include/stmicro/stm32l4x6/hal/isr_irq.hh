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
 * Hardware support device interrupts
 * @file isr_irq.hh
 * @author Boris Vinogradov
 */

#include <types.hh>

#ifndef ISR_IRQ_HH
#define ISR_IRQ_HH

namespace hal {
    enum struct irq_dev_num_t : lp::u8_t {
        WWDG = 0, /*!%0 Window Watchdog interrupt */
        PVD_PVM = 1, /*!%1 PVD through EXTI line detection */
        TAMP_STAMP = 2, /*!%2 Tamper and TimeStamp interrupts */
        RTC_WKUP = 3, /*!%3 RTC Tamper or TimeStamp /CSS on LSE through         EXTI line 19 interrupts */
        FLASH = 4, /*!%4 Flash global interrupt */
        RCC = 5, /*!%5 RCC global interrupt */
        EXTI0 = 6, /*!%6 EXTI Line 0 interrupt */
        EXTI1 = 7, /*!%7 EXTI Line 1 interrupt */
        EXTI2 = 8, /*!%8 EXTI Line 2 interrupt */
        EXTI3 = 9, /*!%9 EXTI Line 3 interrupt */
        EXTI4 = 10, /*!%10 EXTI Line 4 interrupt */
        DMA1_CH1 = 11, /*!%11 DMA1 Channel1 global interrupt */
        DMA1_CH2 = 12, /*!%12 DMA1 Channel2 global interrupt */
        DMA1_CH3 = 13, /*!%13 DMA1 Channel3 interrupt */
        DMA1_CH4 = 14, /*!%14 DMA1 Channel4 interrupt */
        DMA1_CH5 = 15, /*!%15 DMA1 Channel5 interrupt */
        DMA1_CH6 = 16, /*!%16 DMA1 Channel6 interrupt */
        DMA1_CH7 = 17, /*!%17 DMA1 Channel 7 interrupt */
        ADC1_2 = 18, /*!%18 ADC1 and ADC2 global interrupt */
        CAN1_TX = 19, /*!%19 CAN1 TX interrupts */
        CAN1_RX0 = 20, /*!%20 CAN1 RX0 interrupts */
        CAN1_RX1 = 21, /*!%21 CAN1 RX1 interrupts */
        CAN1_SCE = 22, /*!%22 CAN1 SCE interrupt */
        EXTI9_5 = 23, /*!%23 EXTI Line5 to Line9 interrupts */
        TIM1_BRK_TIM15 = 24, /*!%24 TIM1 Break/TIM15 global         interrupts */
        TIM1_UP_TIM16 = 25, /*!%25 TIM1 Update/TIM16 global         interrupts */
        TIM1_TRG_COM_TIM17 = 26, /*!%26 TIM1 Trigger and Commutation interrupts and         TIM17 global interrupt */
        TIM1_CC = 27, /*!%27 TIM1 Capture Compare interrupt */
        TIM2 = 28, /*!%28 TIM2 global interrupt */
        TIM3 = 29, /*!%29 TIM3 global interrupt */
        TIM4 = 30, /*!%30 TIM4 global interrupt */
        I2C1_EV = 31, /*!%31 I2C1 event interrupt */
        I2C1_ER = 32, /*!%32 I2C1 error interrupt */
        I2C2_EV = 33, /*!%33 I2C2 event interrupt */
        I2C2_ER = 34, /*!%34 I2C2 error interrupt */
        SPI1 = 35, /*!%35 SPI1 global interrupt */
        SPI2 = 36, /*!%36 SPI2 global interrupt */
        USART1 = 37, /*!%37 USART1 global interrupt */
        USART2 = 38, /*!%38 USART2 global interrupt */
        USART3 = 39, /*!%39 USART3 global interrupt */
        EXTI15_10 = 40, /*!%40 EXTI Lines 10 to 15 interrupts */
        RTC_ALARM = 41, /*!%41 RTC alarms through EXTI line 18         interrupts */
        DFSDM1_FLT3 = 42, /*!%42 DFSDM1_FLT3 global interrupt */
        TIM8_BRK = 43, /*!%43 TIM8 Break Interrupt */
        TIM8_UP = 44, /*!%44 TIM8 Update Interrupt */
        TIM8_TRG_COM = 45, /*!%45 TIM8 Trigger and Commutation         Interrupt */
        TIM8_CC = 46, /*!%46 TIM8 Capture Compare Interrupt */
        ADC3 = 47, /*!%47 ADC3 global interrupt */
        FMC = 48, /*!%48 FMC global Interrupt */
        SDMMC1 = 49, /*!%49 SDMMC global Interrupt */
        TIM5 = 50, /*!%50 TIM5 global Interrupt */
        SPI3 = 51, /*!%51 SPI3 global Interrupt */
        UART4 = 52, /*!%52 UART4 global Interrupt */
        UART5 = 53, /*!%53 UART5 global Interrupt */
        TIM6_DACUNDER = 54, /*!%54 TIM6 global and DAC1 and 2 underrun error         interrupts */
        TIM7 = 55, /*!%55 TIM7 global interrupt */
        DMA2_CH1 = 56, /*!%56 DMA2 Channel 1 global Interrupt */
        DMA2_CH2 = 57, /*!%57 DMA2 Channel 2 global Interrupt */
        DMA2_CH3 = 58, /*!%58 DMA2 Channel 3 global Interrupt */
        DMA2_CH4 = 59, /*!%59 DMA2 Channel 4 global Interrupt */
        DMA2_CH5 = 60, /*!%60 DMA2 Channel 5 global Interrupt */
        DFSDM1_FLT0 = 61, /*!%61 DFSDM1_FLT0 global interrupt */
        DFSDM1_FLT1 = 62, /*!%62 DFSDM1_FLT1 global interrupt */
        DFSDM1_FLT2 = 63, /*!%63 DFSDM1_FLT2 global interrupt */
        COMP = 64, /*!%64 COMP1 and COMP2 interrupts */
        LPTIM1 = 65, /*!%65 LP TIM1 interrupt */
        LPTIM2 = 66, /*!%66 LP TIM2 interrupt */
        OTG_FS = 67, /*!%67 USB OTG FS global Interrupt */
        DMA2_CH6 = 68, /*!%68 DMA2 Channel 6 global Interrupt */
        DMA2_CH7 = 69, /*!%69 DMA2 Channel 7 global Interrupt */
        LPUART1 = 70, /*!%70 LPUART1 global interrupt */
        QUADSPI = 71, /*!%71 Quad SPI global interrupt */
        I2C3_EV = 72, /*!%72 I2C3 event interrupt */
        I2C3_ER = 73, /*!%73 I2C3 error interrupt */
        SAI1 = 74, /*!%74 SAI1 global interrupt */
        SAI2 = 75, /*!%75 SAI2 global interrupt */
        SWPMI1 = 76, /*!%76 SWPMI1 global interrupt */
        TSC = 77, /*!%77 TSC global interrupt */
        LCD = 78, /*!%78 LCD global interrupt */
        AES = 79, /*!%79 AES global interrupt */
        RNG_HASH = 80, /*!%80 RNG and HASH global interrupt */
        FPU = 81, /*!%81 Floating point interrupt */
        CRS = 82, /*!%82 CRS global interrupt */
        I2C4_EV = 83, /*!%83 I2C4 event interrupt */
        I2C4_ER = 84, /*!%84 I2C4 error interrupt */
        DCMI = 85, /*!%85 DCMI global interrupt */
        CAN2_TX = 86, /*!%86 CAN2 TX interrupt */
        CAN2_RX0 = 87, /*!%87 CAN2 RX0 interrupt */
        CAN2_RX1 = 88, /*!%88 CAN2 RX1 interrupt */
        CAN2_SCE = 89, /*!%89 CAN SCE interrupt */
        DMA2D = 90, /*!%90 DMA2D global interrupt */
    };
}

#endif // ISR_IRQ_HH
