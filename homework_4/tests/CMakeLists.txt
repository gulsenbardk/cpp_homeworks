Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG         v3.0.1 # or a later release
)

FetchContent_MakeAvailable(Catch2)

set(TEST_BINARY ${PROJECT_NAME}_test)
add_executable(${TEST_BINARY} test_named_vector.cpp test_ipb_algorithm.cpp)
target_link_libraries(${TEST_BINARY} homework_4 Catch2::Catch2WithMain)
include(Catch)
catch_discover_tests(${TEST_BINARY} WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})


#find_package(Catch2 REQUIRED)
#include(Catch)
#
#set(TEST_BINARY ${PROJECT_NAME}_test)
#add_executable(${TEST_BINARY} test_named_vector.cpp test_ipb_algorithm.cpp)
#target_link_libraries(${TEST_BINARY} homework_4 Catch2::Catch2WithMain)
#catch_discover_tests(${TEST_BINARY} WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})