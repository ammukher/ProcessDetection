project(ProcessDetection2D)
cmake_minimum_required(VERSION 2.8)
if(COMMAND cmake_policy)
   cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

find_package(ITK 4 REQUIRED)
include(${ITK_USE_FILE})

add_executable(Process proc.cxx)
target_link_libraries(Process ${ITK_LIBRARIES})

add_executable(splitter splitter.h splitter_test.cxx)
target_link_libraries(splitter ${ITK_LIBRARIES})