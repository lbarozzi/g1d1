cmake_minimum_required(VERSION 3.23)

project(g1d1
    VERSION 0.1.0
    DESCRIPTION "Minimal C++23 CMake project"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(g1d1_lib
    src/g1d1.cpp
    src/md.cpp
    src/demographic.cpp
)

add_library(g1d1::g1d1 ALIAS g1d1_lib)

target_include_directories(g1d1_lib
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_compile_features(g1d1_lib PUBLIC cxx_std_23)

target_compile_options(g1d1_lib
    PRIVATE
        $<$<CXX_COMPILER_ID:GNU,Clang>:-Wall;-Wextra;-Wpedantic>
        $<$<CXX_COMPILER_ID:MSVC>:/W4>
)

add_executable(g1d1
    src/main.cpp
)

target_link_libraries(g1d1
    PRIVATE
        g1d1::g1d1
)

enable_testing()
add_subdirectory(tests)
