cmake_minimum_required(VERSION 3.16.3)
project(task_1)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(task_1 task_1.cpp)
target_compile_features(task_1 PRIVATE cxx_std_17)
target_compile_options(task_1 PRIVATE -Wall -Werror)
#install(FILES bin/task_1 
#        PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
#        DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../bin)
#install(FILES bin/task_1 
#        PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
#        DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../bin)