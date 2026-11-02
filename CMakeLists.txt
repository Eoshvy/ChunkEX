cmake_minimum_required(VERSION 3.14)
project(ChunkEX)

# LeviLauncher preloader SDK requires C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetch preloader-android SDK
include(FetchContent)
FetchContent_Declare(
    preloader_android
    GIT_REPOSITORY https://github.com/LiteLDev/preloader-android.git
    GIT_TAG        0.2.2
)
FetchContent_MakeAvailable(preloader_android)

# Find Android logging library
find_library(log-lib log)

# Target shared library
add_library(chunkex SHARED src/main.cpp)
set_target_properties(chunkex PROPERTIES SUFFIX ".so")

# Link the preloader target and Android log library
target_link_libraries(chunkex PRIVATE preloader ${log-lib})
