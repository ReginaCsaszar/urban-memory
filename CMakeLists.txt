cmake_minimum_required(VERSION 3.8)
project(waste)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

set(SOURCE_FILES main.cpp)
add_executable(waste ${SOURCE_FILES})
target_link_libraries(waste gtest gtest_main)