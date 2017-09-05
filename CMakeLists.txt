#---------------------------------------
# asarfunc verification project
#---------------------------------------

cmake_minimum_required(VERSION 3.1)
set(ASAR_VERSION "1.50")

link_directories(
        "${CMAKE_CURRENT_BINARY_DIR}"
        "./"
        "../"
        "${CMAKE_CURRENT_SOURCE_DIR}/${ASAR_VERSION}"
        )

project(asar_ftest)

file(RELATIVE_PATH SRCDIR "${PROJECT_BINARY_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}")
add_custom_target(ftest ALL
        COMMAND ${PROJECT_BINARY_DIR}/functest "${SRCDIR}test1.asm" "${SRCDIR}test2.asm" "${SRCDIR}fail.asm"
        )

add_executable(functest
        ${CMAKE_CURRENT_SOURCE_DIR}/functest.c
        ${CMAKE_CURRENT_SOURCE_DIR}/${ASAR_VERSION}/asardll.c
        )

target_include_directories(functest PRIVATE
        "${ASAR_VERSION}"
        )

if(UNIX)
target_link_libraries(functest
        "asar"
        "dl"
        )
endif(UNIX)

add_dependencies(ftest functest)

