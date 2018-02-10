cmake_minimum_required (VERSION 2.8)

add_compile_options (-std=c++14)

set (SRCS cellular.cpp grid.cpp evol.cpp life.cpp)

add_executable (life main.cpp ${SRCS})
add_executable (life_test test.cpp ${SRCS})

target_link_libraries (life pthread)
target_link_libraries (life_test pthread)
