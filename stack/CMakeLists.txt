cmake_minimum_required(VERSION 3.6)
project(arrayStack)

include_directories(include)

set(ARRAY_STACK src/arrayStack.cpp)

add_executable(arrayStack ${ARRAY_STACK} main.cpp)
