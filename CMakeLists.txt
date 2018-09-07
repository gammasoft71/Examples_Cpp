cmake_minimum_required(VERSION 3.0)
project(Cpp.Examples)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

if (NOT EXECUTABLE_OUTPUT_PATH)
  if ("${CMAKE_BUILD_TYPE}" STREQUAL "")
    set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})
  else()
    set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/${CMAKE_BUILD_TYPE})
  endif()
endif()

add_subdirectory("src")
