cmake_minimum_required(VERSION 3.30)
project(data_structures)

add_library(${PROJECT_NAME} dynamic_array.cc)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})