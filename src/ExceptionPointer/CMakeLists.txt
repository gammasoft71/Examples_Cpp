cmake_minimum_required(VERSION 3.0)
project(ExceptionPointer VERSION 1.0.0)
find_package(Threads REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(ExceptionPointer ExceptionPointer.cpp)
target_link_libraries(ExceptionPointer Threads::Threads)
