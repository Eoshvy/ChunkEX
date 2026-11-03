cmake_minimum_required(VERSION 3.22)
project(ChunkEX LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    preloader_android
    GIT_REPOSITORY https://github.com/LiteLDev/preloader-android.git
    GIT_TAG        0.2.2
    GIT_SUBMODULES_RECURSE TRUE
)
FetchContent_MakeAvailable(preloader_android)

add_library(chunkex SHARED src/main.cpp)
set_target_properties(chunkex PROPERTIES SUFFIX ".so")

target_link_libraries(chunkex PRIVATE preloader)
