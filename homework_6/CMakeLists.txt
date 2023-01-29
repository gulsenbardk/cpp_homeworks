cmake_minimum_required(VERSION 3.16.3)
project(homework_6) 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
#set(CMAKE_CXX_FLAGS "-Wall -Wextra")
#set(CMAKE_CXX_FLAGS_DEBUG "-g")
#set(CMAKE_CXX_FLAGS_RELEASE "-O3") 
#
find_package(OpenCV 4.6 REQUIRED)
if(OpenCV_FOUND)
  message(STATUS "Found OpenCV version ${OpenCV_VERSION}")
  #message(STATUS "OpenCV directories: ${OpenCV_INCLUDE_DIRS}")
  include_directories(${OpenCV_INCLUDE_DIRS})
else()
  message(FATAL_ERROR "OpenCV not found, please read the README.md")
endif(OpenCV_FOUND)
#

include_directories(include io_tools)


add_subdirectory(io_tools)
add_library(image src/image.cpp)
#add_library(io_tools io_tools/io_tools.cpp)

target_link_libraries(image ${OpenCV_LIBS})
#target_compile_features(image PRIVATE cxx_std_17)
#target_compile_options(image PRIVATE -Wall -Werror)


add_library(homework_6 INTERFACE)
target_include_directories(image PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
target_include_directories(io_tools PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
target_link_libraries(image io_tools)

target_link_libraries(homework_6 INTERFACE image io_tools ${OpenCV_LIBS})
target_include_directories(homework_6 INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
target_compile_features(homework_6 INTERFACE cxx_std_20)
target_compile_options(homework_6 INTERFACE -Wall -Werror) 


enable_testing()
add_subdirectory(tests)