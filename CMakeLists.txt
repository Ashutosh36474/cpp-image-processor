# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(ImageProcessor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Tell CMake where to find stb headers
include_directories(vendor)

# Add our executable and its source files
add_executable(image_processor main.cpp Image.cpp)