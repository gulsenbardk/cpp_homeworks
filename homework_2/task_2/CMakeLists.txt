cmake_minimum_required(VERSION 3.16.3)
project(task_2)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
add_executable(task_2 task_2.cpp)
target_compile_features(task_2 PRIVATE cxx_std_17)
target_compile_options(task_2 PRIVATE -Wall -Werror)
#install(FILES bin/task_2 
#        PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
#        DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../bin)
#install(FILES bin/task_2 
#        PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
#        DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../bin)