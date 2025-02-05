minimum_required_version(VERSION 3.22)

project(stack)
set(CMAKE_CXXSTANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra -Wpedantic)

add_executable(test test.cpp)

#Fix below
target_link_directories(test PRIVATE)