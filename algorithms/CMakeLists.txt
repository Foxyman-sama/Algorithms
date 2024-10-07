cmake_minimum_required(VERSION 3.30)
project(algorithms)

add_library(${PROJECT_NAME} binary_search.cc)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})