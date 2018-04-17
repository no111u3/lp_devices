This is C++14 based device support library for Lepestrum

It consist:
 - Base device cpu core support with interrupt support for ARM (Cortex-M4)
 - Base device low-level peripheral support with interrupt support for
   1. STMicro devices
        1. STM32L4x6 family (stm32l476)
 - Base device middle-level core and peripheral support
   1. STMicro devices
        1. EXTI
        2. GPIO
        3. Interrupts/NVIC
        4. RCC (Partial)
        5. SysCfg (Partial)
        6. SysTick (Partial)
        7. TIM (Partial)
        8. USART (Partial)
 - CMake based core and device specific flags for correct build procedures

Library depends:
 - lp_cc_lib (types and defines)
