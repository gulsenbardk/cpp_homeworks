cmake_minimum_required(VERSION 3.16.3)
project(homework_6) 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
#
find_package(OpenCV 4.6 REQUIRED)
if(OpenCV_FOUND)
  message(STATUS "Found OpenCV version ${OpenCV_VERSION}")
  message(STATUS "OpenCV directories: ${OpenCV_INCLUDE_DIRS}")
  include_directories(${OpenCV_INCLUDE_DIRS})
else()
  message(FATAL_ERROR "OpenCV not found, please read the README.md")
endif(OpenCV_FOUND)
#

include_directories(include io_tools)


add_subdirectory(io_tools)
add_library(image src/image.cpp)
target_link_libraries(image io_tools)
target_link_libraries(image ${OpenCV_INCLUDE_LIBS})
#target_compile_features(image PRIVATE cxx_std_17)
#target_compile_options(image PRIVATE -Wall -Werror)



add_executable(main src/main.cpp)
target_link_libraries(main image)
add_library(homework_6 INTERFACE)
target_include_directories(image INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
target_include_directories(io_tools INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

target_link_libraries(homework_6 INTERFACE image io_tools ${OpenCV_LIBS})

enable_testing()
add_subdirectory(tests)