cmake_minimum_required(VERSION 3.14)
project(Segmentation___Faulters)

set(CMAKE_CXX_STANDARD 17)

add_executable(Segmentation___Faulters main.cpp
        User/User.cpp
        User/User.h
        User/UserRepository.cpp
        User/UserRepository.h
        User/UserServices.cpp
        User/UserServices.h
        User/UserTests.cpp
)
