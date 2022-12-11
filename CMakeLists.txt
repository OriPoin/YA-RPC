cmake_minimum_required(VERSION 3.0.0)
project(ya-rpc VERSION 0.1.0)

# boost.log & boost.test dependency
find_package(Boost REQUIRED COMPONENTS log_setup log unit_test_framework)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest)
enable_testing()

# Verbose GNU Make
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_GENERATOR "Unix Makefiles")

# Set default build type
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "RelWithDebInfo")
endif ()

message(STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(__DEBUG__)
endif ()
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pipe -fno-semantic-interposition -fno-math-errno -flto=auto")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -fno-semantic-interposition  -fno-math-errno -flto=auto")
endif()

set(CMAKE_C_COMPILER    "clang")
set(CMAKE_CXX_COMPILER  "clang++")

set(CMAKE_INSTALL_PREFIX    "${PROJECT_SOURCE_DIR}/dist")

# include dir
include_directories("include")
include_directories("/usr/include/node/")
add_subdirectory(include)
# source code lib
add_subdirectory(lib)
# tests code tests dir
add_subdirectory(tests)