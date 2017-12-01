cmake_minimum_required(VERSION 2.8)
project(dsa171a2)

set(CXX_DEFINES "-DAVL_USE_HEIGHT -DUSE_CUSTOME_COMPARE_OPS -DUSE_HASH_ID")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX_DEFINES}")

set(SOURCE_FILES main.cpp requestLib.cpp dbLib.cpp processData.cpp)
add_executable(dsa171a2 ${SOURCE_FILES})