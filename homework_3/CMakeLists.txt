cmake_minimum_required(VERSION 3.16.3)
project(homework_3) 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(api)
add_library(image_browser src/html_writer.cpp src/image_browser.cpp) 

add_executable(create_image_browser src/main.cpp )
target_link_libraries(create_image_browser image_browser) 

add_library(homework_3 INTERFACE)
target_link_libraries(homework_3 INTERFACE image_browser)
target_include_directories(homework_3 INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/api>)


enable_testing()
add_subdirectory(tests)