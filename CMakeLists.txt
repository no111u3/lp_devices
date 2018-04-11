get_filename_component(LIB_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)

#include vendor specific features
include("${LIB_DIR}/cmake/${VENDOR}.cmake")
include("${LIB_DIR}/cmake/${CPU_VENDOR}.cmake")

#include device specific linker script
set(LINKER_SCRIPT ${LIB_DIR}/ld/${VENDOR}/${DEVICE}.ld PARENT_SCOPE)

file(GLOB LIB_SRC
    "${LIB_DIR}/src/${VENDOR}/${DEVICE_FAMILY}/isr_extend.cc"
    "${LIB_DIR}/src/${CPU_VENDOR}/${CPU}/isr_base.cc"
)

add_library(lp_devices ${LIB_SRC})
add_library(lp::devices ALIAS lp_devices)

target_link_libraries(lp_devices
    PRIVATE lp::cc_lib
)

target_include_directories(lp_devices PUBLIC "${LIB_DIR}/include")
target_include_directories(lp_devices PUBLIC "${LIB_DIR}/include/${CPU_VENDOR}/${CPU}")
target_include_directories(lp_devices PUBLIC "${LIB_DIR}/include/${VENDOR}")
target_include_directories(lp_devices PUBLIC "${LIB_DIR}/include/${VENDOR}/${DEVICE_FAMILY}")
