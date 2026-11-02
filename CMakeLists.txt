cmake_minimum_required(VERSION 3.14)
project(ChunkEX)

set(CMAKE_CXX_STANDARD 17)

# Fetch the LeviLauncher Preloader SDK for Android
include(FetchContent)
FetchContent_Declare(
    preloader-android
    GIT_REPOSITORY https://github.com/LiteLDev/preloader-android.git
    GIT_TAG        v0.2.2
)
FetchContent_MakeAvailable(preloader-android)

# Find Android logging library
find_library(log-lib log)

# Define shared library source files
add_library(chunkex SHARED src/main.cpp)
set_target_properties(chunkex PROPERTIES SUFFIX ".so")

# Link Preloader SDK and Android log library
target_link_libraries(chunkex PRIVATE preloader::sdk ${log-lib})
