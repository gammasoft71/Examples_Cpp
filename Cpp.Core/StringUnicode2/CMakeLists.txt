cmake_minimum_required(VERSION 3.1)

project(StringUnicode2)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (MSVC)
  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif ()

add_executable(StringUnicode2 StringUnicode2.cpp)
