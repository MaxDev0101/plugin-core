cmake_minimum_required(VERSION 3.20.0)

project(plugin-core)

add_subdirectory(external)

# library
add_library(plugin-core STATIC
    include/maxdev0101/plugin-core/circularbuffer.h
    source/circularbuffer.cpp
)

target_include_directories(plugin-core
    PUBLIC
        include
    PRIVATE
        source
)

target_compile_features(plugin-core
    PRIVATE 
        cxx_std_17
)

# executable
add_executable(plugin-core-googletest
    test/plugin-core_googletest.cpp
)

target_link_libraries(plugin-core-googletest
    PRIVATE
        plugin-core
        gtest_main
        gmock_main
)