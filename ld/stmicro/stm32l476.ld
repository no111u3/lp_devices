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
 * Lepestrum linker scripts
 * STM32L476 support
 * @file stm32l476.ld
 * @author Boris Vinogradov
 */

/* Entry Point */
ENTRY(reset)
/* Specify the memory areas */
MEMORY {
    flash (rx) : org = 0x08000000, len = 1024k
    ram (rwx) : org = 0x20000000, len = 96k
    ram_ecc (rwx) : org = 0x10000000, len = 32k
}
/* Define output sections */
SECTIONS {
    . = ORIGIN(flash);
    .text :
    {
        *(.vectors) /* Vector table */
        *(.vectors.*) /* Any extra device vectors */
        *(.text .text.*) /* Program code */
        *(.rodata) /* Read only data */
        *(.rodata*)
        __text_end = .;
    } >flash

    /*
     * Those regions provide unwind exception information
     */
    .ARM.exidx : { *(.ARM.exidx.*) } >flash
    .ARM.extab : { *(.ARM.extab.*) } >flash

    /*
     * This is the initialized data section
     * The program executes knowing that the data is in the ram
     * but the loader puts the initial values in the flash (inidata).
     * One task of "startup" is to copy the initial values from flash to ram.
     */
    .data :
    {
        /* This is used by the startup in order to initialize the .data secion */
        PROVIDE (__data_start = .);
        *(.data)
        *(.data.*)
        . = ALIGN(8);
        PROVIDE (__ctors_begin = .);
        KEEP (*(SORT(.ctors.*)))
        KEEP (*(.ctors))
        PROVIDE (__ctors_end = .);
        PROVIDE (__preinit_array_start = .);
        KEEP (*(SORT(.preinit_array.*)))
        KEEP (*(.preinit_array))
        PROVIDE (__preinit_array_end = .);
        PROVIDE (__init_array_start = .);
        KEEP (*(SORT(.init_array.*)))
        KEEP (*(.init_array))
        PROVIDE (__init_array_end = .);
        . = ALIGN(4);
        /* This is used by the startup in order to initialize the .data secion */
        PROVIDE (__data_end = .);
    } >ram AT >flash

    .bss :
    {
        PROVIDE(__bss_start = .);
        *(.bss)
        *(COMMON)
        . = ALIGN(4);
        PROVIDE(__bss_end = .);
    } >ram

    . = ALIGN(4);

    _stack_start = .;

}

_end = .;
/* Provide stack end address */
PROVIDE(_estack = ORIGIN(ram) + LENGTH(ram) - 4); 
