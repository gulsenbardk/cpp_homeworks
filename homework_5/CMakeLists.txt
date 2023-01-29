cmake_minimum_required(VERSION 3.16.3)
project(homework_5) 

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

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)


add_library(homework_5 INTERFACE)

add_library(mat_serialization src/serialize.cpp)
target_link_libraries(mat_serialization ${OpenCV_LIBS})
target_include_directories(mat_serialization INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

add_library(convert_dataset src/convert_dataset.cpp)
target_link_libraries(convert_dataset ${OpenCV_LIBS})
target_include_directories(convert_dataset INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

target_link_libraries(homework_5 INTERFACE mat_serialization convert_dataset)


add_executable(local_test src/main.cpp)
target_link_libraries(local_test ${OpenCV_LIBS} convert_dataset mat_serialization)
enable_testing()
add_subdirectory(tests)