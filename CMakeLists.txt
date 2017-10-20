cmake_minimum_required(VERSION 3.8)
project(waste)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)

include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

set(SOURCE_FILES
        src/garbage/Garbage.hpp src/garbage/PaperGarbage.hpp src/garbage/PlasticGarbage.hpp src/garbage/BottleCap.hpp src/garbage/MetalGarbage.hpp
        src/dustbin/DustbinContentError.hpp src/dustbin/BottleCapException.hpp
        src/dustbin/Dustbin.cpp src/dustbin/Dustbin.h src/dustbin/Dustbin9000.cpp src/dustbin/Dustbin9000.h
        tests/DustbinTest.cpp)

add_executable(waste ${SOURCE_FILES})

target_link_libraries(waste gtest gtest_main)