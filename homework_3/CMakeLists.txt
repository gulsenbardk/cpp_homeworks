cmake_minimum_required(VERSION 3.16.3)
project(homework_3)
set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/build)
#add_subdirectory(./api)


include_directories(api/)
add_library(html_writer STATIC ./api/html_writer.cpp)
add_library(image_browser STATIC ./api/image_browser.cpp )

target_link_libraries(image_browser PUBLIC html_writer)

add_executable(create_image_browser ./api/homework_3.cpp)
target_link_libraries(create_image_browser PUBLIC image_browser html_writer) 

install(FILES api/homework_3.h DESTINATION ../tests)
install(FILES api/html_writer.hpp DESTINATION ../tests)
install(FILES api/image_browser.hpp DESTINATION ../tests)

