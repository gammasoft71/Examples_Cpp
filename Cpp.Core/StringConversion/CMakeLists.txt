cmake_minimum_required(VERSION 3.1)
project(StringConversion)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (MSVC)
  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif ()

add_executable(StringConversion StringConversion.cpp)
