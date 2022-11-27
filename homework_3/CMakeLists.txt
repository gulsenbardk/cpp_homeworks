cmake_minimum_required(VERSION 3.16.3)
project(homework_3) 
set(CMAKE_CXX_STANDARD 17) # Use c++17.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
include_directories(api)

add_library(homework_3 ${CMAKE_SOURCE_DIR}/src/html_writer.cpp ${CMAKE_SOURCE_DIR}/src/image_browser.cpp)


target_include_directories(homework_3 PUBLIC ${CMAKE_SOURCE_DIR})


enable_testing()
add_subdirectory(${CMAKE_SOURCE_DIR}/tests)