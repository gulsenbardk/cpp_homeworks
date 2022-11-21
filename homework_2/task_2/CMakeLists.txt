cmake_minimum_required(VERSION 3.16.3)
project(task_2)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INSTALL_PREFIX ${CMAKE__CURRENT_SOURCE_DIR}/bin)
add_executable(task_2 ./task_2.cpp)
#install(FILES build/task_2 
#        PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
#        DESTINATION ${CMAKE_SOURCE_DIR}/bin)