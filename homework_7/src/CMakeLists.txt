add_executable(local_test main.cpp) 
target_link_libraries(local_test ${OpenCV_LIBS} kmeans serialization)
