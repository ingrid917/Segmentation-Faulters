cmake_minimum_required(VERSION 3.14)
project(SegmentationFaulters)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(ProductRepoDir)

add_executable(SegmentationFaulters main.cpp)

target_link_libraries(SegmentationFaulters ProductRepoLib)
