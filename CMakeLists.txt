cmake_minimum_required(VERSION 3.16)
project(StackDataStructureDemo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(chapter3_core STATIC
    src/stack.cpp
    src/queue.cpp
    src/expression.cpp
    src/applications.cpp
)
target_include_directories(chapter3_core PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
if(MSVC)
    target_compile_options(chapter3_core PRIVATE /W4)
else()
    target_compile_options(chapter3_core PRIVATE -Wall -Wextra -Wpedantic)
endif()

enable_testing()
file(GLOB DEMOS CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/examples/*.cpp")
foreach(source IN LISTS DEMOS)
    get_filename_component(name "${source}" NAME_WE)
    string(REGEX MATCH "^[0-9]+" number "${name}")
    if(NOT number)
        message(FATAL_ERROR "演示文件名需要以数字编号开头：${name}")
    endif()
    set(target "demo_${number}")
    add_executable("${target}" "${source}")
    target_link_libraries("${target}" PRIVATE chapter3_core)
    if(MSVC)
        target_compile_options("${target}" PRIVATE /W4)
    else()
        target_compile_options("${target}" PRIVATE -Wall -Wextra -Wpedantic)
    endif()
    add_test(NAME "${target}" COMMAND "${target}")
endforeach()

add_executable(core_checks tests/core_checks.cpp)
target_link_libraries(core_checks PRIVATE chapter3_core)
add_test(NAME core_checks COMMAND core_checks)
