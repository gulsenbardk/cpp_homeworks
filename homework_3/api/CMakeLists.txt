cmake_minimum_required(VERSION 3.16.3)
project(homework_3)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}) 
#set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/build)
#set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/build)


add_library(html_writer STATIC ./html_writer.cpp)
add_library(image_browser STATIC ./image_browser.cpp )

target_link_libraries(image_browser PUBLIC html_writer)

add_executable(create_image_browser ./homework_3.cpp)
target_link_libraries(create_image_browser PUBLIC image_browser html_writer) 

#install(DIRECTORY ${CMAKE_SOURCE_DIR}/api DESTINATION ${CMAKE_INSTALL_PREFIX})
#install(TARGETS create_image_browser DESTINATION ${CMAKE_CURRENT_SOURCE_DIRECTORY}/tests)
#install(FILES api/homework_3.h DESTINATION ${CMAKE_CURRENT_SOURCE_DIRECTORY}/tests)
#install(FILES api/html_writer.hpp DESTINATION ${CMAKE_CURRENT_SOURCE_DIRECTORY}/tests)
#install(FILES api/image_browser.hpp DESTINATION ${CMAKE_CURRENT_SOURCE_DIRECTORY}/tests)
#install(FILES build/libhtml_writer.a DESTINATION ${CMAKE_CURRENT_SOURCE_DIRECTORY}/tests)
#install(FILES build/libimage_browser.a DESTINATION ${CMAKE_CURRENT_SOURCE_DIRECTORY}/tests)
#install(FILES api/html_writer.hpp DESTINATION ../tests)
#install(FILES api/image_browser.hpp DESTINATION ../tests)
#install(FILES build/create_image_browser 
#        PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
#        DESTINATION ../tests)
