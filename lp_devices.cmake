get_filename_component(LP_DEVICES_CMAKE_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)

#include vendor specific features
include("${LP_DEVICES_CMAKE_DIR}/cmake/${VENDOR}.cmake")
include("${LP_DEVICES_CMAKE_DIR}/cmake/${CPU_VENDOR}.cmake")

#include vendor and device specific headers
include_directories("${LP_DEVICES_CMAKE_DIR}/include")
include_directories("${LP_DEVICES_CMAKE_DIR}/include/${CPU_VENDOR}/${CPU}")
include_directories("${LP_DEVICES_CMAKE_DIR}/include/${VENDOR}")
include_directories("${LP_DEVICES_CMAKE_DIR}/include/${VENDOR}/${DEVICE_FAMILY}")

#include device specific linker script
set(LINKER_SCRIPT ${LP_DEVICES_CMAKE_DIR}/ld/${VENDOR}/${DEVICE}.ld)

set(LP_DEVICES_SRC
    "${LP_DEVICES_CMAKE_DIR}/src/${VENDOR}/${DEVICE_FAMILY}/isr_extend.cc"
    "${LP_DEVICES_CMAKE_DIR}/src/${CPU_VENDOR}/${CPU}/isr_base.cc"
)
