set(CPU_VENDOR arm)

if (DEVICE STREQUAL "stm32l476")
    set(DEVICE_FAMILY stm32l4x6)
    set(CPU cm4)
else()
    message("You need to define device for current vendor")
endif()
