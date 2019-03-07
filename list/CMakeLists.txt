cmake_minimum_required(VERSION 3.6)
project(arrayList)

include_directories(include)

set(LIST_LIST src/arrayList.cpp)

add_executable(List ${LIST_LIST} main.cpp)
