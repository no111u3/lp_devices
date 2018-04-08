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
 * @file isr_extend.hh
 * @author Boris Vinogradov
 */

#ifndef ISR_EXTEND_HH
#define ISR_EXTEND_HH

extern "C" {
    namespace isr {
        struct device_vectors { // Table of pointer to interrupt vectors - STM32L4x6 specific interrupts
            void (*WWDG)(); /*!%0 Window Watchdog interrupt */
            void (*PVD_PVM)(); /*!%1 PVD through EXTI line detection */
            void (*TAMP_STAMP)(); /*!%2 Tamper and TimeStamp interrupts */
            void (*RTC_WKUP)(); /*!%3 RTC Tamper or TimeStamp /CSS on LSE through         EXTI line 19 interrupts */
            void (*FLASH)(); /*!%4 Flash global interrupt */
            void (*RCC)(); /*!%5 RCC global interrupt */
            void (*EXTI0)(); /*!%6 EXTI Line 0 interrupt */
            void (*EXTI1)(); /*!%7 EXTI Line 1 interrupt */
            void (*EXTI2)(); /*!%8 EXTI Line 2 interrupt */
            void (*EXTI3)(); /*!%9 EXTI Line 3 interrupt */
            void (*EXTI4)(); /*!%10 EXTI Line 4 interrupt */
            void (*DMA1_CH1)(); /*!%11 DMA1 Channel1 global interrupt */
            void (*DMA1_CH2)(); /*!%12 DMA1 Channel2 global interrupt */
            void (*DMA1_CH3)(); /*!%13 DMA1 Channel3 interrupt */
            void (*DMA1_CH4)(); /*!%14 DMA1 Channel4 interrupt */
            void (*DMA1_CH5)(); /*!%15 DMA1 Channel5 interrupt */
            void (*DMA1_CH6)(); /*!%16 DMA1 Channel6 interrupt */
            void (*DMA1_CH7)(); /*!%17 DMA1 Channel 7 interrupt */
            void (*ADC1_2)(); /*!%18 ADC1 and ADC2 global interrupt */
            void (*CAN1_TX)(); /*!%19 CAN1 TX interrupts */
            void (*CAN1_RX0)(); /*!%20 CAN1 RX0 interrupts */
            void (*CAN1_RX1)(); /*!%21 CAN1 RX1 interrupts */
            void (*CAN1_SCE)(); /*!%22 CAN1 SCE interrupt */
            void (*EXTI9_5)(); /*!%23 EXTI Line5 to Line9 interrupts */
            void (*TIM1_BRK_TIM15)(); /*!%24 TIM1 Break/TIM15 global         interrupts */
            void (*TIM1_UP_TIM16)(); /*!%25 TIM1 Update/TIM16 global         interrupts */
            void (*TIM1_TRG_COM_TIM17)(); /*!%26 TIM1 Trigger and Commutation interrupts and         TIM17 global interrupt */
            void (*TIM1_CC)(); /*!%27 TIM1 Capture Compare interrupt */
            void (*TIM2)(); /*!%28 TIM2 global interrupt */
            void (*TIM3)(); /*!%29 TIM3 global interrupt */
            void (*TIM4)(); /*!%30 TIM4 global interrupt */
            void (*I2C1_EV)(); /*!%31 I2C1 event interrupt */
            void (*I2C1_ER)(); /*!%32 I2C1 error interrupt */
            void (*I2C2_EV)(); /*!%33 I2C2 event interrupt */
            void (*I2C2_ER)(); /*!%34 I2C2 error interrupt */
            void (*SPI1)(); /*!%35 SPI1 global interrupt */
            void (*SPI2)(); /*!%36 SPI2 global interrupt */
            void (*USART1)(); /*!%37 USART1 global interrupt */
            void (*USART2)(); /*!%38 USART2 global interrupt */
            void (*USART3)(); /*!%39 USART3 global interrupt */
            void (*EXTI15_10)(); /*!%40 EXTI Lines 10 to 15 interrupts */
            void (*RTC_ALARM)(); /*!%41 RTC alarms through EXTI line 18         interrupts */
            void (*DFSDM1_FLT3)(); /*!%42 DFSDM1_FLT3 global interrupt */
            void (*TIM8_BRK)(); /*!%43 TIM8 Break Interrupt */
            void (*TIM8_UP)(); /*!%44 TIM8 Update Interrupt */
            void (*TIM8_TRG_COM)(); /*!%45 TIM8 Trigger and Commutation         Interrupt */
            void (*TIM8_CC)(); /*!%46 TIM8 Capture Compare Interrupt */
            void (*ADC3)(); /*!%47 ADC3 global interrupt */
            void (*FMC)(); /*!%48 FMC global Interrupt */
            void (*SDMMC1)(); /*!%49 SDMMC global Interrupt */
            void (*TIM5)(); /*!%50 TIM5 global Interrupt */
            void (*SPI3)(); /*!%51 SPI3 global Interrupt */
            void (*UART4)(); /*!%52 UART4 global Interrupt */
            void (*UART5)(); /*!%53 UART5 global Interrupt */
            void (*TIM6_DACUNDER)(); /*!%54 TIM6 global and DAC1 and 2 underrun error         interrupts */
            void (*TIM7)(); /*!%55 TIM7 global interrupt */
            void (*DMA2_CH1)(); /*!%56 DMA2 Channel 1 global Interrupt */
            void (*DMA2_CH2)(); /*!%57 DMA2 Channel 2 global Interrupt */
            void (*DMA2_CH3)(); /*!%58 DMA2 Channel 3 global Interrupt */
            void (*DMA2_CH4)(); /*!%59 DMA2 Channel 4 global Interrupt */
            void (*DMA2_CH5)(); /*!%60 DMA2 Channel 5 global Interrupt */
            void (*DFSDM1_FLT0)(); /*!%61 DFSDM1_FLT0 global interrupt */
            void (*DFSDM1_FLT1)(); /*!%62 DFSDM1_FLT1 global interrupt */
            void (*DFSDM1_FLT2)(); /*!%63 DFSDM1_FLT2 global interrupt */
            void (*COMP)(); /*!%64 COMP1 and COMP2 interrupts */
            void (*LPTIM1)(); /*!%65 LP TIM1 interrupt */
            void (*LPTIM2)(); /*!%66 LP TIM2 interrupt */
            void (*OTG_FS)(); /*!%67 USB OTG FS global Interrupt */
            void (*DMA2_CH6)(); /*!%68 DMA2 Channel 6 global Interrupt */
            void (*DMA2_CH7)(); /*!%69 DMA2 Channel 7 global Interrupt */
            void (*LPUART1)(); /*!%70 LPUART1 global interrupt */
            void (*QUADSPI)(); /*!%71 Quad SPI global interrupt */
            void (*I2C3_EV)(); /*!%72 I2C3 event interrupt */
            void (*I2C3_ER)(); /*!%73 I2C3 error interrupt */
            void (*SAI1)(); /*!%74 SAI1 global interrupt */
            void (*SAI2)(); /*!%75 SAI2 global interrupt */
            void (*SWPMI1)(); /*!%76 SWPMI1 global interrupt */
            void (*TSC)(); /*!%77 TSC global interrupt */
            void (*LCD)(); /*!%78 LCD global interrupt */
            void (*AES)(); /*!%79 AES global interrupt */
            void (*RNG_HASH)(); /*!%80 RNG and HASH global interrupt */
            void (*FPU)(); /*!%81 Floating point interrupt */
            void (*CRS)(); /*!%82 CRS global interrupt */
            void (*I2C4_EV)(); /*!%83 I2C4 event interrupt */
            void (*I2C4_ER)(); /*!%84 I2C4 error interrupt */
            void (*DCMI)(); /*!%85 DCMI global interrupt */
            void (*CAN2_TX)(); /*!%86 CAN2 TX interrupt */
            void (*CAN2_RX0)(); /*!%87 CAN2 RX0 interrupt */
            void (*CAN2_RX1)(); /*!%88 CAN2 RX1 interrupt */
            void (*CAN2_SCE)(); /*!%89 CAN SCE interrupt */
            void (*DMA2D)(); /*!%90 DMA2D global interrupt */
        };

        void WWDG();
        void PVD_PVM();
        void TAMP_STAMP();
        void RTC_WKUP();
        void FLASH();
        void RCC();
        void EXTI0();
        void EXTI1();
        void EXTI2();
        void EXTI3();
        void EXTI4();
        void DMA1_CH1();
        void DMA1_CH2();
        void DMA1_CH3();
        void DMA1_CH4();
        void DMA1_CH5();
        void DMA1_CH6();
        void DMA1_CH7();
        void ADC1_2();
        void CAN1_TX();
        void CAN1_RX0();
        void CAN1_RX1();
        void CAN1_SCE();
        void EXTI9_5();
        void TIM1_BRK_TIM15();
        void TIM1_UP_TIM16();
        void TIM1_TRG_COM_TIM17();
        void TIM1_CC();
        void TIM2();
        void TIM3();
        void TIM4();
        void I2C1_EV();
        void I2C1_ER();
        void I2C2_EV();
        void I2C2_ER();
        void SPI1();
        void SPI2();
        void USART1();
        void USART2();
        void USART3();
        void EXTI15_10();
        void RTC_ALARM();
        void DFSDM1_FLT3();
        void TIM8_BRK();
        void TIM8_UP();
        void TIM8_TRG_COM();
        void TIM8_CC();
        void ADC3();
        void FMC();
        void SDMMC1();
        void TIM5();
        void SPI3();
        void UART4();
        void UART5();
        void TIM6_DACUNDER();
        void TIM7();
        void DMA2_CH1();
        void DMA2_CH2();
        void DMA2_CH3();
        void DMA2_CH4();
        void DMA2_CH5();
        void DFSDM1_FLT0();
        void DFSDM1_FLT1();
        void DFSDM1_FLT2();
        void COMP();
        void LPTIM1();
        void LPTIM2();
        void OTG_FS();
        void DMA2_CH6();
        void DMA2_CH7();
        void LPUART1();
        void QUADSPI();
        void I2C3_EV();
        void I2C3_ER();
        void SAI1();
        void SAI2();
        void SWPMI1();
        void TSC();
        void LCD();
        void AES();
        void RNG_HASH();
        void FPU();
        void CRS();
        void I2C4_EV();
        void I2C4_ER();
        void DCMI();
        void CAN2_TX();
        void CAN2_RX0();
        void CAN2_RX1();
        void CAN2_SCE();
        void DMA2D();
    }
}

#endif // ISR_EXTEND_HH
