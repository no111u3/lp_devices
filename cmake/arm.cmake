set(CMAKE_SYSTEM_PROCESSOR arm)

if (CPU STREQUAL "cm4")
    set(CPU_FLAGS "-mcpu=cortex-m4")
else()
    message("You need to define cpu for current vendor")
endif()
