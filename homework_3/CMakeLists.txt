cmake_minimum_required(VERSION 3.16.3)
project( homework_3 ) 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)
include_directories(api)

add_library(html_writer ${CMAKE_SOURCE_DIR}/src/html_writer.cpp)
add_library(image_browser ${CMAKE_SOURCE_DIR}/src/image_browser.cpp)

target_link_libraries(image_browser html_writer) 
target_include_directories(image_browser PUBLIC ${CMAKE_SOURCE_DIR}/api)