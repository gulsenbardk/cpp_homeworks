cmake_minimum_required(VERSION 3.16.3)
project(homework_3)
set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
#include_directories(api)
add_library(html_writer SHARED src/html_writer.cpp)
target_include_directories(html_writer PUBLIC api)

add_library(image_browser SHARED src/image_browser.cpp)
target_include_directories(image_browser PUBLIC api)


link_libraries(html_writer image_browser) # Indicate that lib1 is needed for lib2

add_executable(homework_3 src/homework_3.cpp)
target_include_directories(homework_3 PUBLIC api)
target_link_libraries(homework_3 html_writer image_browser)  