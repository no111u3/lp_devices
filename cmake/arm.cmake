if (CPU STREQUAL "cm4")
    set(CPU_FLAGS "-mcpu=cortex-m4" PARENT_SCOPE)
else()
    message("You need to define cpu for current vendor")
endif()
