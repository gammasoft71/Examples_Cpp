cmake_minimum_required(VERSION 3.0)
project(ConsoleColor)

if (MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /utf-8")
endif ()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(ConsoleColor ConsoleColor.cpp)
