find_package(GTest REQUIRED)

set(TEST_BINARY ${PROJECT_NAME}_test)

add_executable(${TEST_BINARY}_kmeans test_kmeans.cpp test_data.cpp)
target_link_libraries(${TEST_BINARY}_kmeans homework_7 GTest::Main)
gtest_discover_tests(${TEST_BINARY}_kmeans WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(${TEST_BINARY}_bow_dictionary test_bow_dictionary.cpp)
target_link_libraries(${TEST_BINARY}_bow_dictionary homework_7 GTest::Main)
gtest_discover_tests(${TEST_BINARY}_bow_dictionary WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
