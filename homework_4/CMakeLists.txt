cmake_minimum_required(VERSION 3.16.3)
project(homework_4) 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
#add_library(ipb_algoritmh src/ipb_algorithm.cpp) 

add_executable(local_test src/main.cpp)
#target_link_libraries(local_test ipb_algorithm)


add_library(homework_4 INTERFACE)
#target_link_libraries(homework_4 INTERFACE ipb_algorithm)
target_include_directories(homework_4 INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)


enable_testing()
add_subdirectory(tests)