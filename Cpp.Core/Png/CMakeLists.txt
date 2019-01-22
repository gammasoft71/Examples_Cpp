cmake_minimum_required(VERSION 3.1)
project(Png)

find_package(PNG REQUIRED)
link_libraries(PNG::PNG)

add_definitions(-D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(Png Png.cpp)
