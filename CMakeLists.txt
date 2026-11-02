cmake_minimum_required(VERSION 3.10)
project(ChunkEX)

set(CMAKE_CXX_STANDARD 17)

# Locate the Android log library
find_library(log-lib log)

# Define your mod's target library
add_library(chunkex SHARED src/main.cpp)
set_target_properties(chunkex PROPERTIES SUFFIX ".so")

# Link the Android log library to chunkex
target_link_libraries(chunkex ${log-lib})
