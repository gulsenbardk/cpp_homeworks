cmake_minimum_required(VERSION 3.16.3)
project(homework_3)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/build)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
include_directories(api/)
add_library(html_writer STATIC src/html_writer.cpp)
add_library(image_browser STATIC src/image_browser.cpp )

target_link_libraries(image_browser PUBLIC html_writer)

add_executable(create_image_browser src/homework_3.cpp)
target_link_libraries(create_image_browser PUBLIC image_browser html_writer) 
#install(DIRECTORY ${CMAKE_SOURCE_DIR} DESTINATION ../tests)
install(FILES api/homework_3.h DESTINATION ../tests)
install(FILES api/html_writer.hpp DESTINATION ../tests)
install(FILES api/image_browser.hpp DESTINATION ../tests)

#add_library(image_browser SHARED ./src/image_browser.cpp)

#target_include_directories(image_browser PUBLIC api)

#link_libraries(html_writer image_browser) # Indicate that lib1 is needed for lib2
#find_package(image_browser REQUIRED)
 
#target_include_directories(homework_3 PUBLIC api)

#