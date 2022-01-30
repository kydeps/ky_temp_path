cmake_minimum_required(VERSION 3.22)
project(ky_example_standalone)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(kydeps)

find_package(ky_temp_path)

add_executable(test
    test.cc
)
target_link_libraries(test
    PRIVATE ky_temp_path::ky_temp_path
)
