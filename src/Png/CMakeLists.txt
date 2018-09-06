cmake_minimum_required(VERSION 3.0)
project(Png VERSION 1.0.0)
find_package(PNG REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(Png Png.cpp)
target_link_libraries(Png PNG::PNG)
