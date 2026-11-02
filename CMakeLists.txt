cmake_minimum_required(VERSION 3.10)
project(ChunkEX)

set(CMAKE_CXX_STANDARD 17)

add_library(chunkex SHARED src/main.cpp)
set_target_properties(chunkex PROPERTIES SUFFIX ".so")
