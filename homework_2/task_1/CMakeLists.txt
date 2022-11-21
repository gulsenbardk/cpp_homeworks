cmake_minimum_required(VERSION 3.16.3)
project(task_1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INSTALL_PREFIX ${CMAKE__CURRENT_SOURCE_DIR}/bin)
add_executable(task_1 task_1.cpp)
#install(FILES build/task_1 
#        PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
#        DESTINATION ${CMAKE_SOURCE_DIR}/bin)