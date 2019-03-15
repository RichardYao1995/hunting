cmake_minimum_required(VERSION 3.6)
project(chain)

include_directories(include)

set(CHAIN_CHAIN src/chain.cpp)

add_executable(Chain ${CHAIN_CHAIN} main.cpp)
