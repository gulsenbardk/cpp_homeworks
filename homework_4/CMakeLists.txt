cmake_minimum_required(VERSION 3.16.3)
project(homework_4) 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)
add_library(ipb_algoritmh src/ipb_algorithm.cpp) 

add_library(homework_4 INTERFACE)
target_link_libraries(homework_4 INTERFACE ipb_algorithm)
target_include_directories(homework_4 INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
target_compile_features(homework_4 INTERFACE cxx_std_20)
target_compile_options(homework_4 INTERFACE -Wall -Werror) 


#enable_testing()
#add_subdirectory(tests)