cmake_minimum_required(VERSION 3.16.3)
project(homework_7) 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#
find_package(OpenCV 4.6 REQUIRED)
if(OpenCV_FOUND)
  message(STATUS "Found OpenCV version ${OpenCV_VERSION}")
  include_directories(${OpenCV_INCLUDE_DIRS})
else()
  message(FATAL_ERROR "OpenCV not found, please read the README.md")
endif(OpenCV_FOUND)
#

include_directories(include)

add_library(serialization src/serialize.cpp)
target_link_libraries(serialization ${OpenCV_LIBS})
target_include_directories(serialization INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

add_library(convert_dataset src/convert_dataset.cpp)
target_link_libraries(convert_dataset ${OpenCV_LIBS})
target_include_directories(convert_dataset INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

add_library(kmeans src/kmeans.cpp)
target_link_libraries(kmeans ${OpenCV_LIBS})
target_include_directories(kmeans INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

add_library(bow_dictionary src/bow_dictionary.cpp)
target_link_libraries(bow_dictionary ${OpenCV_LIBS} serialization)
target_include_directories(bow_dictionary INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

add_library(homework_7 INTERFACE)
target_link_libraries(homework_7 INTERFACE serialization convert_dataset kmeans bow_dictionary ${OpenCV_LIBS})
target_include_directories(homework_7 INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
target_compile_features(homework_7 INTERFACE cxx_std_20)
target_compile_options(homework_7 INTERFACE -Wall -Werror)

add_executable(local_test src/main.cpp)
target_link_libraries(local_test ${OpenCV_LIBS} convert_dataset serialization kmeans bow_dictionary)

enable_testing()
add_subdirectory(tests)