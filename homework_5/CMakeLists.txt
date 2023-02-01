cmake_minimum_required(VERSION 3.16.3)
project(homework_5) 

#
find_package(OpenCV 4.6 REQUIRED)
if(OpenCV_FOUND)
  message(STATUS "Found OpenCV version ${OpenCV_VERSION}")
  include_directories(${OpenCV_INCLUDE_DIRS})
else()
  message(FATAL_ERROR "OpenCV not found, please read the README.md")
endif(OpenCV_FOUND)
#

set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_BUILD_TYPE debug)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
#set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
#set(CMAKE_CXX_FLAGS "-Wall -Wextra")
#set(CMAKE_CXX_FLAGS_DEBUG "-g")
#set(CMAKE_CXX_FLAGS_RELEASE "-O3") 

include_directories(include)




add_library(mat_serialization src/serialize.cpp)
target_link_libraries(mat_serialization ${OpenCV_LIBS})
target_include_directories(mat_serialization INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

add_library(convert_dataset src/convert_dataset.cpp)
target_link_libraries(convert_dataset ${OpenCV_LIBS})
target_include_directories(convert_dataset INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)



add_library(homework_5 INTERFACE)
target_link_libraries(homework_5 INTERFACE mat_serialization convert_dataset ${OpenCV_LIBS})
target_include_directories(homework_5 INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
target_compile_features(homework_5 INTERFACE cxx_std_20)
target_compile_options(homework_5 INTERFACE -Wall -Werror)


add_executable(local_test src/main.cpp)
target_link_libraries(local_test ${OpenCV_LIBS} convert_dataset mat_serialization)

enable_testing()
add_subdirectory(tests)