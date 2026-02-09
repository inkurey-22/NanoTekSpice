cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_COMPILER "clang++")

project(nanotekspice LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O2")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE NANO_SOURCES
    CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

add_executable(nanotekspice ${NANO_SOURCES})

target_include_directories(nanotekspice PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_options(nanotekspice PRIVATE -Wall -Wextra -O2)
