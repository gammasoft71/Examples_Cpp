cmake_minimum_required(VERSION 3.2)
project(CppExamples)

if ("${CMAKE_BUILD_TYPE}" STREQUAL "")
  set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})
else()
  set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/${CMAKE_BUILD_TYPE})
endif()

# Hello World
add_subdirectory("src/HelloWorld")

# Hello World
add_subdirectory("src/ExceptionPointer")

# System
add_subdirectory("src/ConsoleColor")
