cmake_minimum_required(VERSION 3.1)

project(StringUnicode)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /utf-8")
endif ()

add_executable(StringUnicode StringUnicode.cpp)
